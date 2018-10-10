/*	SC	A Spreadsheet Calculator
 *		Command routines
 *
 *		original by James Gosling, September 1982
 *		modifications by Mark Weiser and Bruce Israel,
 *			University of Maryland
 *
 *              More mods Robert Bond, 12/86
 *              More mods Allin cottrell, 5/01
 *
 *		$Revision: 1.27 $
 */

#include <string.h>
#include "config.h"

#include <sys/types.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <fcntl.h>

#include "sc.h"
#include "scXstuff.h"
#include "plot.h"

#include <signal.h>
#include <errno.h>

static void openrow(int);
static void print_options(FILE *);
static void syncref(struct enode *);
static void unspecial(FILE *, char *, int);

extern int errno;

/* To store location of previous cursor position */
extern int prvmx, prvmy, prvcol;     /* line added by Bob Parbs 12-92 */
extern int lastmx, lastmy, lastcol;  /* line added by Bob Parbs 12-92 */

/* a linked list of free [struct ent]'s, uses .next as the pointer */
extern struct ent *freeents;

/* a linked list of free [struct enodes]'s, uses .e.o.left as the pointer */
extern struct enode *freeenodes;

/* global graphing struct from scmain.c */
extern struct graph baseplot;

/* copy the current row (currow) and place the cursor in the new row */
void
duprow(void)
{
    if (currow >= maxrows - 1 || maxrow >= maxrows - 1) {
	if (!growtbl(GROWROW, 0, 0))
	    return;
    }
    modflg++;
    currow++;
    openrow (currow);
    for (curcol = 0; curcol <= maxcol; curcol++) {
	register struct ent *p = *ATBL(tbl, currow - 1, curcol);
	if (p) {
	    register struct ent *n;
	    n = lookat (currow, curcol);
	    (void)copyent(n, p, 1, 0);
	}
    }
    for (curcol = 0; curcol <= maxcol; curcol++) {
	register struct ent *p = *ATBL(tbl, currow, curcol);
	if (p && (p->flags & is_valid) && !p->expr)
	    break;
    }
    if (curcol > maxcol)
	curcol = 0;
}

/* copy the current column (curcol) and place the cursor in the new column */
void
dupcol(void) 
{
    if (curcol >= maxcols - 1 || maxcol >= maxcols - 1) {
	if (!growtbl(GROWCOL, 0, 0))
	    return;
    }
    modflg++;
    curcol++;
    opencol (curcol, 1);
    for (currow = 0; currow <= maxrow; currow++) {
	register struct ent *p = *ATBL(tbl, currow, curcol - 1);
	if (p) {
	    register struct ent *n;
	    n = lookat (currow, curcol);
	    copyent(n, p, 0, 1);
	}
    }
    for (currow = 0; currow <= maxrow; currow++) {
	register struct ent *p = *ATBL(tbl, currow, curcol);
	if (p && (p->flags & is_valid) && !p->expr)
	    break;
    }
    if (currow > maxrow)
	currow = 0;
}

/* insert 'arg' rows before currow */
void
insertrow(register int arg)
{
    while (--arg>=0) openrow (currow);
}

/* delete 'arg' rows starting at currow (deletes from currow downward) */
void
deleterow(register int arg)
{
    if (any_locked_cells(currow, 0, currow + arg - 1, maxcol))
	error("Locked cells encountered. Nothing changed");
    else {
    	flush_saved();
    	erase_area(currow, 0, currow + arg - 1, maxcol);
    	currow += arg;
    	while (--arg >= 0) closerow (--currow);
    	sync_refs();
    }
}

void
erase_area(int sr, int sc, int er, int ec)
{
    register int r, c;
    register struct ent **pp;

    if (sr > er) {
	r = sr; sr = er; er= r;	
    }

    if (sc > ec) {
	c = sc; sc = ec; ec= c;	
    }

    if (sr < 0)
	sr = 0; 
    if (sc < 0)
	sc = 0;
    checkbounds(&er, &ec);

    for (r = sr; r <= er; r++) {
	for (c = sc; c <= ec; c++) {
	    pp = ATBL(tbl, r, c);
	    if (*pp && !((*pp)->flags&is_locked)) {
		free_ent(*pp);
		*pp = NULL;
	    }
	}
    }
}

/*
 * deletes the expression associated w/ a cell and turns it into a constant
 * containing whatever was on the screen
 */
void
valueize_area(int sr, int sc, int  er, int ec)
{
    register int r, c;
    register struct ent *p;

    if (sr > er) {
	r = sr; sr = er; er= r;	
    }

    if (sc > ec) {
	c = sc; sc = ec; ec= c;	
    }

    if (sr < 0)
	sr = 0; 
    if (sc < 0)
	sc = 0;
    checkbounds(&er, &ec);

    for (r = sr; r <= er; r++) {
	for (c = sc; c <= ec; c++) {
	    p = *ATBL(tbl, r, c);
	    if (p && p->flags&is_locked) {
		sprintf(stringbuf, " Cell %s%d is locked", coltoa(c), r);
		error(stringbuf);
		continue;
	    }
	    if (p && p->expr) {
		efree(p->expr);
		p->expr = NULL;
		p->flags &= ~is_strexpr;
	    }
	}
    }
}

void
pullcells(int to_insert)
{
    register struct ent *p, *n;
    register int deltar, deltac;
    int minrow, mincol;
    int mxrow, mxcol;
    int numrows, numcols;

    if (! to_fix)
	{
	    error ("No data to pull");
	    return;
	}

    minrow = maxrows; 
    mincol = maxcols;
    mxrow = 0;
    mxcol = 0;

    for (p = to_fix; p; p = p->next) {
	if (p->row < minrow)
	    minrow = p->row;
	if (p->row > mxrow)
	    mxrow = p->row;
	if (p->col < mincol)
	    mincol = p->col;
	if (p->col > mxcol)
	    mxcol = p->col;
    }

    numrows = mxrow - minrow + 1;
    numcols = mxcol - mincol + 1;
    deltar = currow - minrow;
    deltac = curcol - mincol;

    if (to_insert == 'r') {
	insertrow(numrows);
	deltac = 0;
    } else if (to_insert == 'c') {
	opencol(curcol, numcols);
	deltar = 0;
    }

    FullUpdate++;
    modflg++;

    for (p = to_fix; p; p = p->next) {
	n = lookat (p->row + deltar, p->col + deltac);
	clearent(n);
	copyent(n, p, deltar, deltac);
	n->flags = p->flags & ~is_deleted;
    }
}

void
colshow_op(void)
{
    register int i, j;

    for (i=0; i<maxcols; i++)
	if (col_hidden[i]) 
	    break;
    for(j=i; j<maxcols; j++)
	if (!col_hidden[j])
	    break;
    j--;
    if (i>=maxcols)
	error ("No hidden columns to show");
    else {
	sprintf(line,"show %s:", coltoa(i));
	sprintf(line + strlen(line),"%s",coltoa(j));
	linelim = strlen(line);
    }
}

void
rowshow_op(void)
{
    register int i, j;

    for (i=0; i<maxrows; i++)
	if (row_hidden[i]) 
	    break;
    for (j=i; j<maxrows; j++)
	if (!row_hidden[j]) 
	    break;
    j--;

    if (i >= maxrows)
	error ("No hidden rows to show");
    else {
	sprintf(line,"show %d:%d", i, j);
        linelim = strlen(line);
    }
}

static void
openrow(int rs)
{
    register int r, c;
    struct ent **tmprow, **pp;

    if (rs > maxrow) maxrow = rs;
    if (maxrow >= maxrows - 1 || rs > maxrows - 1) {
	if (!growtbl(GROWROW, rs, 0))
	    return;
    }
    /*
     * save the last active row+1, shift the rows downward, put the last
     * row in place of the first
     */
    tmprow = tbl[++maxrow];
    for (r = maxrow; r > rs; r--) {
	row_hidden[r] = row_hidden[r-1];
	tbl[r] = tbl[r-1];
	pp = ATBL(tbl, r, 0);
	for (c = 0; c < maxcols; c++, pp++)
	    if (*pp)
		(*pp)->row = r;
    }
    tbl[r] = tmprow;	/* the last row was never used.... */
    FullUpdate++;
    modflg++;
}

/* delete row r */
void
closerow(register int r)
{
    register struct ent **pp;
    register int c;
    struct ent	**tmprow;

    if (r > maxrow) return;

    /* save the row and empty it out */
    tmprow = tbl[r];
    pp = ATBL(tbl, r, 0);
    for (c=maxcol+1; --c>=0; pp++) {
	if (*pp) {
	    free_ent(*pp);
	    *pp = NULL;
	}
    }

    /* move the rows, put the deleted, but now empty, row at the end */
    for (; r < maxrows - 1; r++) {
	row_hidden[r] = row_hidden[r+1];
	tbl[r] = tbl[r+1];
	pp = ATBL(tbl, r, 0);
	for (c = 0; c < maxcols; c++, pp++)
	    if (*pp)
		(*pp)->row = r;
    }
    tbl[r] = tmprow;

    maxrow--;
    FullUpdate++;
    modflg++;
}

void
opencol(int cs, int numcol)
{
    register int r, c;
    register struct ent **pp;
    register int lim = maxcol-cs+1;
    int i;

    if (cs > maxcol)
	maxcol = cs;
    maxcol += numcol;

    if ((maxcol >= maxcols - 1) && !growtbl(GROWCOL, 0, maxcol))
	return;

    for (i = maxcol; i > cs; i--) {
	fwidth[i] = fwidth[i-numcol];
	precision[i] = precision[i-numcol];
	realfmt[i] = realfmt[i-numcol];
	col_hidden[i] = col_hidden[i-numcol];
    }
    for (c = cs; c - cs < numcol; c++) {
    	fwidth[c] = DEFWIDTH;
	precision[c] =  DEFPREC;
	realfmt[c] = DEFREFMT;
    }
	
    for (r=0; r<=maxrow; r++) {
	pp = ATBL(tbl, r, maxcol);
	for (c=lim; --c>=0; pp--)
	    if ((pp[0] = pp[-numcol])) 
		pp[0]->col += numcol;

	pp = ATBL(tbl, r, cs);
	for (c = cs; c - cs < numcol; c++, pp++)
	    *pp = NULL;
    }
    FullUpdate++;
    modflg++;
}

/* delete group of columns (1 or more) */
void
closecol (int cs, int numcol)
{
    register int r, c;
    register struct ent **pp;
    register struct ent *q;
    register int lim = maxcol-cs;
    int i;
    char buf[50];

    if (lim - numcol < -1) {
    	sprintf(buf, "Can't delete %d column%s %d columns left", 
		numcol, (numcol > 1 ? "s," : ","), lim+1);
	error(buf);
	return;
    }
    if (any_locked_cells(0, curcol, maxrow, curcol + numcol - 1)) {
	error("Locked cells encountered. Nothing changed");
	return;
    }
    flush_saved();
    erase_area(0, curcol, maxrow, curcol + numcol - 1);
    sync_refs();

    /* clear then copy the block left */
    lim = maxcols - numcol - 1;
    for (r=0; r<=maxrow; r++) {
	for (c = cs; c - cs < numcol; c++)
	    if ((q = *ATBL(tbl, r, c)))
		free_ent(q);

	pp = ATBL(tbl, r, cs);
	for (c=cs; c <= lim; c++, pp++) {
	    if (c > lim)
		*pp = NULL;
	    else if ((pp[0] = pp[numcol]))
		pp[0]->col -= numcol;
	}

	c = numcol;
	for (; --c >= 0; pp++)		
	    *pp = NULL;
    }

    for (i=cs; i<maxcols - numcol - 1; i++) {
	fwidth[i] = fwidth[i+numcol];
	precision[i] = precision[i+numcol];
	realfmt[i] = realfmt[i+numcol];
	col_hidden[i] = col_hidden[i+numcol];
    }
    for (; i < maxcols - 1; i++) {
	fwidth[i] = DEFWIDTH;
	precision[i] = DEFPREC;
	realfmt[i] = DEFREFMT;
	col_hidden[i] = FALSE;
    }

    maxcol -= numcol;
    FullUpdate++;
    modflg++;
}

void
doend(int rowinc, int colinc)
{
    register struct ent *p;
    int r, c;

    if (VALID_CELL(p, currow, curcol)) {
	r = currow + rowinc;
	c = curcol + colinc;
	if (r >= 0 && r < maxrows && 
	    c >= 0 && c < maxcols &&
	    !VALID_CELL(p, r, c)) {
	    currow = r;
	    curcol = c;
	}
    }

    if (!VALID_CELL(p, currow, curcol)) {
        switch (rowinc) {
        case -1:
	    while (!VALID_CELL(p, currow, curcol) && currow > 0)
		currow--;
	    break;
        case  1:
	    while (!VALID_CELL(p, currow, curcol) && currow < maxrows-1)
		currow++;
	    break;
        case  0:
            switch (colinc) {
 	    case -1:
	        while (!VALID_CELL(p, currow, curcol) && curcol > 0)
		    curcol--;
	        break;
 	    case  1:
	        while (!VALID_CELL(p, currow, curcol) && curcol < maxcols-1)
		    curcol++;
	        break;
	    }
            break;
        }

	error ("");	/* clear line */
	return;
    }

    switch (rowinc) {
    case -1:
	while (VALID_CELL(p, currow, curcol) && currow > 0)
	    currow--;
	break;
    case  1:
	while (VALID_CELL(p, currow, curcol) && currow < maxrows-1)
	    currow++;
	break;
    case  0:
	switch (colinc) {
	case -1:
	    while (VALID_CELL(p, currow, curcol) && curcol > 0)
		curcol--;
	    break;
	case  1:
	    while (VALID_CELL(p, currow, curcol) && curcol < maxcols-1)
		curcol++;
	    break;
	}
	break;
    }
    if (!VALID_CELL(p, currow, curcol)) {
        currow -= rowinc;
        curcol -= colinc;
    }
}

/* Modified 9/17/90 THA to handle more formats */
void
doformat(int c1, int c2, int w, int p, int r)
{
    register int i;
    int crows = 0;
    int ccols = c2;

    if (c1 >= maxcols && !growtbl(GROWCOL, 0, c1)) c1 = maxcols-1 ;
    if (c2 >= maxcols && !growtbl(GROWCOL, 0, c2)) c2 = maxcols-1 ;

    if (w > maintextcols - RESCOL - 2) {
	sprintf(stringbuf,"Format too large - Maximum = %d", 
		maintextcols - RESCOL - 2);
	error(stringbuf);
	w = maintextcols - RESCOL - 2;
    }

    if (p > w) {
	error("Precision too large");
	p = w;
    }

    checkbounds(&crows, &ccols);
    if (ccols < c2) {
	sprintf(stringbuf,"Format: couldn't create implied column %d", 
		c2);
	error(stringbuf);
	return;
    }

    for (i=c1; i<=c2; i++)
	fwidth[i] = w, precision[i] = p, realfmt[i] = r;

    FullUpdate++;
    modflg++;
}

static	void
print_options(FILE *f)
{
    if (
	autocalc &&
	propagation == 10 &&
	calc_order == BYROWS &&
	!numeric &&
	prescale == 1.0 &&
	!extfunc &&
	tbl_style == 0 &&
	craction == 0 &&
	rowlimit == -1 &&
	collimit == -1
	)
	return;		/* No reason to do this */

    fprintf(f, "set");
    if (!autocalc) 
	fprintf(f," !autocalc");
    if (propagation != 10)
	fprintf(f, " iterations = %d", propagation);
    if (calc_order != BYROWS)
	fprintf(f, " bycols");
    if (numeric)
	fprintf(f, " numeric");
    if (prescale != 1.0)
	fprintf(f, " prescale");
    if (extfunc)
	fprintf(f, " extfun");
    if (tbl_style)
	fprintf(f, " tblstyle = %s", tbl_style == TBL ? "tbl" :
		tbl_style == LATEX ? "latex" :
		tbl_style == CSV ? "csv" : "0");
    if (craction)
	fprintf(f, " craction = %d", craction);
    if (rowlimit >= 0)
	fprintf(f, " rowlimit = %d", rowlimit);
    if (collimit >= 0)
	fprintf(f, " collimit = %d", collimit);
    fprintf(f, "\n");
}

void
printfile (char *fname, int r0, int c0, int rn, int cn)
{
    FILE *f;
    static char *pline = NULL;
    static unsigned fbufs_allocated = 0;
    int plinelim;
    int pid;
    int fieldlen = 0;
    int nextcol = 0;
    register int row, col;
    register struct ent **pp;
    char *newname;

    /* strip off the .sc ending and add a .txt suffix */
    if (*fname == '\0') {
    	newname = fsuffix(curfile, ".txt");
	fname = newname;
    } else
	newname = NULL;

    if ((strcmp(fname, curfile) == 0) &&
	!yn_ask("Really overwrite database? (y,n)")) {
	if (newname != NULL)
	    scxfree(newname);
	return;
    }

    if (!pline && (pline = scxmalloc(FBUFLEN * ++fbufs_allocated)) == NULL) {
	error("Malloc failed in printfile()");
	if (newname != NULL)
	    scxfree(newname);
        return;
    }

    if ((f = openout(fname, &pid)) == NULL) {
    	sprintf(stringbuf, "Can't create file \"%s\"", fname);
	error(stringbuf);
	if (newname != NULL)
	    scxfree(newname);
	return;
    }
    for (row=r0; row<=rn; row++) {
	register int c = 0;

	if (row_hidden[row])
	    continue;

	pline[plinelim=0] = '\0';
	for (pp = ATBL(tbl, row, col=c0); col<=cn;
	     pp += nextcol-col, col = nextcol, c += fieldlen) {

	    nextcol = col+1;
	    if (col_hidden[col]) {
		fieldlen = 0;
		continue;
	    }

	    fieldlen = fwidth[col];
	    if (*pp) {
		char *s;

		/* 
		 * dynamically allocate pline, making sure we are not 
		 * attempting to write 'out of bounds'.
		 */
		while (c > (fbufs_allocated * FBUFLEN)) {
		    if ((pline = scxrealloc
			 (pline, FBUFLEN * ++fbufs_allocated)) == NULL) {
			error ("Realloc failed in printfile()");
			if (newname != NULL)
			    scxfree(newname);
			return;
		    }
		}		  
		while (plinelim < c) pline[plinelim++] = ' ';
		plinelim = c;
		if ((*pp)->flags&is_valid) {
		    while (plinelim + fwidth[col] > 
			   (fbufs_allocated * FBUFLEN)) {
			if ((pline = (scxrealloc
				      (pline, 
				       FBUFLEN * ++fbufs_allocated)))
			    == NULL) {
			    error ("Realloc failed in printfile()");
			    if (newname != NULL)
				scxfree(newname);
			    return;
			}
		    }
		    if ((*pp)->cellerror) 
			sprintf (pline+plinelim, "%*s",
				 fwidth[col],
				 ((*pp)->cellerror == CELLERROR ? 
				  "ERROR" : "INVALID"));
		    else {
			if ((*pp)->format) {
			    char field[FBUFLEN];

			    format ((*pp)->format, (*pp)->v, field,
				    sizeof field);
			    sprintf (pline+plinelim, "%*s", fwidth[col],
				     field);
			} else {
			    char field[FBUFLEN];

			    engformat(realfmt[col], fwidth[col],
				      precision[col], (*pp)->v,
				      field, sizeof field);
			    sprintf (pline+plinelim, "%*s", fwidth[col],
				     field);
			}
		    }
		    plinelim += strlen(pline+plinelim);
		}
		if ((s = (*pp)->label)) {
		    int slen;
		    char *start, *last;
		    register char *fp;
		    struct ent *nc;

		    /*
		     * Figure out if the label slops over to a blank field. A
		     * string started with backslash is defining repition char
		     */
		    slen = strlen(s);
		    if (*s == '\\' && *(s+1)!= '\0')
			slen = fwidth[col];
		    while (slen > fieldlen && nextcol <= cn &&
			   !((nc = lookat(row,nextcol))->flags & is_valid) &&
			   !(nc->label)) {
			
	                if (!col_hidden[nextcol])
		 	    fieldlen += fwidth[nextcol];

			nextcol++;
		    }
		    if (slen > fieldlen)
			slen = fieldlen;
		    
		    while (c + fieldlen + 2 > (fbufs_allocated * FBUFLEN)) {
			if ((pline = (scxrealloc(pline, 
						 FBUFLEN * ++fbufs_allocated)))
			    == NULL) {
			    error ("scxrealloc failed in printfile()");
			    if (newname != NULL)
				scxfree(newname);
			    return;
			}
		    }		  

		    /* Now justify and print */
		    start = (*pp)->flags & is_leftflush ? pline + c
			: pline + c + fieldlen - slen;
		    if ((*pp)->flags & is_label)
			start = pline + (c + ((fwidth[col]>slen) ?
					      (fwidth[col]-slen)/2:0));
		    last = pline + c + fieldlen;
		    fp = (plinelim < c)? pline + plinelim : pline + c;
		    while (fp < start)
			*fp++ = ' ';
		    if (*s == '\\' && *(s+1)!= '\0') {
			char *strt = ++s;

			while(slen--) {
			    *fp++ = *s++; if (*s == '\0') s = strt;
			}
		    }
		    else
			while (slen--)
			    *fp++ = *s++;

		    if (!((*pp)->flags & is_valid) || fieldlen != fwidth[col])
			while (fp < last)
			    *fp++ = ' ';
		    if (plinelim < fp - pline)
			plinelim = fp - pline;
		}
	    }
	}
	pline[plinelim++] = '\n';
	pline[plinelim] = '\0';
	fputs (pline, f);
    }
    if (newname != NULL)
	scxfree(newname);

    closeout(f, pid);
}

void
tblprintfile(char *fname, int r0, int c0, int rn, int cn)
{
    FILE *f;
    int	pid;
    register int row, col;
    register struct ent **pp;
    char coldelim = ',';
    char *newname;
    char *suffix;

    if (tbl_style == 0) {
	printfile(fname, r0, c0, rn, cn);
	return;
    }

    /* strip off the .sc ending and add a suffix */
    newname = NULL;
    if (*fname == '\0') {
	if (tbl_style == TBL)
	    suffix = ".tbl";
	else if (tbl_style == LATEX)
	    suffix = ".tex";
	else if (tbl_style == CSV)
	    suffix = ".csv";
	else
	    suffix = NULL;
	if (suffix != NULL) {
	    newname = fsuffix(curfile, suffix);
	    fname = newname;
	}
    }

    if ((strcmp(fname, curfile) == 0) &&
	!yn_ask("Really overwrite the database? (y,n)")) {
    	if (newname != NULL)
	    scxfree(newname);
	return;
    }

    if ((f = openout(fname, &pid)) == NULL) {
    	sprintf(stringbuf, "Can't create file \"%s\"", fname);
	error(stringbuf);
	if (newname != NULL)
	    scxfree(newname);
	return;
    }

    if (tbl_style == TBL) {
	coldelim = ':';
	fprintf(f,".\\\" ** %s spreadsheet output \n.TS\n", progname);
	fprintf(f,"tab(%c);\n", coldelim);
	for (col=c0; col<=cn; col++) fprintf(f, " n");
	fprintf(f, ".\n");
    }
    else if (tbl_style == LATEX) {
	fprintf(f, "%% ** %s spreadsheet output\n\\begin{tabular}{", 
		progname);
	for (col=c0; col<=cn; col++) fprintf(f, "c");
	fprintf(f, "}\n");
	coldelim = '&';
    }
    for (row=r0; row<=rn; row++) {
	for (pp = ATBL(tbl, row, col=c0); col<=cn; col++, pp++) {
	    if (*pp) {
		char *s;
		if ((*pp)->flags & is_valid) {
		    if ((*pp)->cellerror) {
			fprintf (f, "%*s",
				 fwidth[col],
				 ((*pp)->cellerror == CELLERROR ? 
				  "ERROR" : "INVALID"));
		    }
		    else
			if ((*pp)->format) {
			    char field[FBUFLEN];
			
			    format ((*pp)->format, (*pp)->v, 
				    field, sizeof field);
			    unspecial(f, field, coldelim);
			} else {
			    char field[FBUFLEN];

			    engformat(realfmt[col], fwidth[col],
				      precision[col], (*pp)->v,
				      field, sizeof field);
			    unspecial(f, field, coldelim);
			}
		}
		if ((s = (*pp)->label)) {
	            unspecial(f, s, coldelim);
		}
	    }
	    if (col < cn)
		fprintf(f, "%c", coldelim);
	}
	if (tbl_style == LATEX) {
	    if (row < rn) fprintf (f, "\\\\");
	}
	fprintf (f,"\n");
    }

    if (tbl_style == TBL)
	fprintf (f,".TE\n.\\\" ** end of %s spreadsheet output\n", 
		 progname);
    else if (tbl_style == LATEX)
	fprintf (f,"\\end{tabular}\n%% ** end of %s spreadsheet output\n", 
		 progname);

    if (newname != NULL)
	scxfree(newname);
    closeout(f, pid);
}

/* unspecial (backquote) things that are special chars in a table */
static	void
unspecial(FILE *f, char *str, int delim)
{
    if (*str == '\\') str++; /* delete wheeling string operator, OK? */
    while (*str) {
	if (tbl_style == LATEX &&
	    ((*str == delim) || (*str == '$') || (*str == '#') ||
	     (*str == '%') || (*str == '{') || (*str == '}') ||
	     (*str == '[') || (*str == ']') || (*str == '&')))
	    putc('\\', f);
	putc(*str, f);
	str++;
    }
}

struct enode *
copye (register struct enode *e, int Rdelta, int Cdelta)
{
    register struct enode *ret;

    if (e == NULL) {
        ret = NULL;
    } else if (e->op & REDUCE) {
	int newrow, newcol;

	if (freeenodes) {
	    ret = freeenodes;
	    freeenodes = ret->e.o.left;
	}
	else
	    ret = scxmalloc(sizeof *ret);
	ret->op = e->op;

	newrow = e->e.r.left.vf & FIX_ROW ? e->e.r.left.vp->row :
	    e->e.r.left.vp->row + Rdelta;
	newcol = e->e.r.left.vf & FIX_COL ? e->e.r.left.vp->col :
	    e->e.r.left.vp->col + Cdelta;
	ret->e.r.left.vp = lookat(newrow, newcol);
	ret->e.r.left.vf = e->e.r.left.vf;
	newrow = e->e.r.right.vf & FIX_ROW ? e->e.r.right.vp->row :
	    e->e.r.right.vp->row + Rdelta;
	newcol = e->e.r.right.vf & FIX_COL ? e->e.r.right.vp->col :
	    e->e.r.right.vp->col + Cdelta;
	ret->e.r.right.vp = lookat(newrow, newcol);
	ret->e.r.right.vf = e->e.r.right.vf;

	/* for conditional range expressions */
	if (e->e.r.expr) {
	    ret->e.r.expr = copye(e->e.r.expr, Rdelta, Cdelta);
	}

    } else {
	if (freeenodes) {
	    ret = freeenodes;
	    freeenodes = ret->e.o.left;
	}
	else
	    ret = scxmalloc(sizeof *ret);
	ret->op = e->op;
	switch (ret->op) {
	case 'v':
	    {
		int newrow, newcol;

		newrow=e->e.v.vf & FIX_ROW ? e->e.v.vp->row :
		    e->e.v.vp->row + Rdelta;
		newcol=e->e.v.vf & FIX_COL ? e->e.v.vp->col :
		    e->e.v.vp->col + Cdelta;
		ret->e.v.vp = lookat(newrow, newcol);
		ret->e.v.vf = e->e.v.vf;
		break;
	    }
	case 'k':
	    ret->e.k = e->e.k;
	    break;
	case 'f':
	    ret->e.o.right = copye(e->e.o.right, 0, 0);
	    ret->e.o.left = NULL;
	    break;
	case '$':
	    ret->e.s = scxmalloc(strlen(e->e.s) + 1);
	    strcpy(ret->e.s, e->e.s);
	    break;
	case 'x':
	    ret->e.o.right = copye(e->e.o.right, Rdelta, Cdelta);
	    ret->e.o.left = NULL;
	    break;
	default:
	    ret->e.o.right = copye(e->e.o.right, Rdelta, Cdelta);
	    ret->e.o.left = copye(e->e.o.left, Rdelta, Cdelta);
	    break;
	}
    }
    return ret;
}

/*
 * sync_refs and syncref are used to remove references to
 * deleted struct ents.  Note that the deleted structure must still
 * be hanging around before the call, but not referenced by an entry
 * in tbl.  Thus the free_ent calls in sc.c
 */
void
sync_refs(void)
{
    register int i, j;
    register struct ent *p;

    sync_ranges();
    for (i=0; i<=maxrow; i++)
	for (j=0; j<=maxcol; j++)
	    if ((p = *ATBL(tbl, i, j)) && p->expr)
		syncref(p->expr);
}

static void
syncref(register struct enode *e)
{
    if (e == NULL)
	return;
    else if (e->op & REDUCE) {
 	e->e.r.right.vp = lookat(e->e.r.right.vp->row, e->e.r.right.vp->col);
 	e->e.r.left.vp = lookat(e->e.r.left.vp->row, e->e.r.left.vp->col);
    } else {
	switch (e->op) {
	case 'v':
	    e->e.v.vp = lookat(e->e.v.vp->row, e->e.v.vp->col);
	    break;
	case 'k':
	    break;
	case '$':
	    break;
	default:
	    syncref(e->e.o.right);
	    syncref(e->e.o.left);
	    break;
	}
    }
}

/* mark a row as hidden */
void
hiderow(int arg)
{
    register int r1;
    register int r2;

    r1 = currow;
    r2 = r1 + arg - 1;
    if (r1 < 0 || r1 > r2) {
	error ("Invalid range");
	return;
    }
    if (r2 >= maxrows-1) {
    	if (!growtbl(GROWROW, arg+1, 0)) {
	    error("You can't hide the last row");
	    return;
	}
    }
    FullUpdate++;
    modflg++;
    while (r1 <= r2)
	row_hidden[r1++] = 1;
}

/* mark a column as hidden */
void
hidecol(int arg)
{
    register int c1;
    register int c2;

    c1 = curcol;
    c2 = c1 + arg - 1;
    if (c1 < 0 || c1 > c2) {
	error ("Invalid range");
	return;
    }
    if (c2 >= maxcols-1) {
    	if ((arg >= ABSMAXCOLS-1) || !growtbl(GROWCOL, 0, arg+1)) {
	    error("You can't hide the last col");
	    return;
	}
    }
    FullUpdate++;
    modflg++;
    while (c1 <= c2)
	col_hidden[c1++] = TRUE;
}

/* mark a row as not-hidden */
void
showrow(int r1, int r2)
{
    if (r1 < 0 || r1 > r2) {
	error ("Invalid range");
	return;
    }
    if (r2 > maxrows-1) 
	r2 = maxrows-1;

    FullUpdate++;
    modflg++;
    while (r1 <= r2)
	row_hidden[r1++] = 0;
}

/* mark a column as not-hidden */
void
showcol(int c1, int c2)
{
    if (c1 < 0 || c1 > c2) {
	error ("Invalid range");
	return;
    }
    if (c2 > maxcols-1) {
	c2 = maxcols-1;
    }
    FullUpdate++;
    modflg++;
    while (c1 <= c2)
	col_hidden[c1++] = FALSE;
}

/* Open the output file, setting up a pipe if needed */
FILE *
openout(char *fname, int *rpid)
{
    int pipefd[2];
    int pid;
    FILE *f = NULL;
    char *efname;

    while (*fname && (*fname == ' '))  /* Skip leading blanks */
	fname++;

    if (*fname != '|') {		/* Open file if not pipe */
	*rpid = 0;
	
	efname = findhome(fname);
#ifdef DOBACKUPS
	if (!backup_file(efname) &&
	    (yn_ask("Couldn't create backup, Save anyhow?: (y,n)") != 1))
	    return 0;
#endif
	return fopen(efname, "w");
    }

    fname++; /* Skip | */
    if (pipe(pipefd) < 0) {
	error("Can't make pipe to child");
	*rpid = 0;
	return 0;
    }

    if ((pid = fork()) == 0) { /* if child  */
	close (0); /* close stdin */
	close (pipefd[1]);
	dup (pipefd[0]); /* connect to pipe input */
	signal (SIGINT, SIG_DFL); /* reset */
	execl ("/bin/sh", "sh", "-c", fname, 0);
	exit (-127);
    } else { /* else parent */
	*rpid = pid;
	if ((f = fdopen (pipefd[1], "w")) == NULL) {
	    kill (pid, -9);
	    error ("Can't fdopen output");
	    close (pipefd[1]);
	    *rpid = 0;
	    return 0;
	}
    }
    return f;
}

/* close a file opened by openout(), if process wait for return */
void
closeout(FILE *f, int pid)
{
    int temp;

    fclose (f);
    if (pid) {
	while (pid != wait(&temp))
	    ;
	printf("Press RETURN to continue ");
	fflush(stdout);
	nmgetch();
    }
}

void
copyent(register struct ent *n, register struct ent *p,
	int dr, int dc)
{
    if (!n || !p) {
    	error("internal error");
	return;
    }
    n->v = p->v;
    n->flags = p->flags;
    n->expr = copye(p->expr, dr, dc);
    n->label = NULL;
    if (p->label) {
	n->label = scxmalloc(strlen(p->label) + 1);
	strcpy (n->label, p->label);
    }
    n->format = 0;
    if (p->format) {
        n->format = scxmalloc(strlen(p->format) + 1);
	strcpy(n->format, p->format);
    }
}

void
write_fd (register FILE *f, int r0, int c0, int rn, int cn)
{
    register struct ent **pp;
    register int r, c;

    fprintf (f, "# This file was auto-generated by xspread.\n");
    fprintf (f, "# You probably shouldn't edit it manually.\n\n");

    print_plot_options(f, &baseplot);
    print_options(f);

    for (c=0; c<maxcols; c++)
	if (fwidth[c] != DEFWIDTH || precision[c] != DEFPREC || 
	    realfmt[c] != DEFREFMT)
	    fprintf(f, "format %s %d %d %d\n",
		    coltoa(c), fwidth[c], precision[c], realfmt[c]);
    for (c=c0; c<cn; c++) {
        if (col_hidden[c]) 
            fprintf(f, "hide %s\n", coltoa(c));
    }
    for (r=r0; r<=rn; r++) {
	if (row_hidden[r]) 
	    fprintf(f, "hide %d\n", r);
    }

    write_range(f);

    for (r=r0; r<=rn; r++) {
	pp = ATBL(tbl, r, c0);
	for (c=c0; c<=cn; c++, pp++)
	    if (*pp) {
		if ((*pp)->label || (*pp)->flags & is_strexpr) {
		    edits(r, c);
		    fprintf(f, "%s\n", line);
		}
		if ((*pp)->flags & is_valid) {
		    editv(r, c);
		    fprintf(f, "%s\n", line);
		}
		if ((*pp)->format) {
		    editfmt(r, c);
		    fprintf(f, "%s\n", line);
		}
		if ((*pp)->flags & is_locked)
		    fprintf(f, "lock %s%d\n", coltoa((*pp)->col),
			    (*pp)->row) ;
	    }
    }
    if (rndinfinity)
	fprintf(f, "set rndinfinity\n");
    fprintf(f, "goto %s\n", v_name(currow, curcol));
}

int
writefile(char *fname, int r0, int c0, int rn, int cn)
{
    register FILE *f;
    char save[PATHLEN];
    int pid;

    if (*fname == '\0') fname = curfile;

    strcpy(save, fname);

    if ((f = openout(fname, &pid)) == NULL) {
    	sprintf(stringbuf, "Can't create file \"%s\"", fname);
	error(stringbuf);
	return -1;
    }

    write_fd(f, r0, c0, rn, cn);
    
    closeout(f, pid);

    /* clean up after the "edit" stuff invoked by write_fd */
    linelim = -1;
    topline_mode = NULL_MODE;
    focus = FOCUS_SHEET;

    if (!pid) {
        strcpy(curfile, save);
        modflg = 0;
	sprintf(stringbuf, "File \"%s\" written", curfile);
	error(stringbuf);
    }
    return 0;
}

void
readfile(char *fname, int eraseflg)
{
    register FILE *f;
    char save[PATHLEN];

    if (*fname == '\0') fname = curfile;
    strcpy(save, fname);

#ifdef notdef    
    if (eraseflg && strcmp(fname, curfile) && modcheck(" first"))
	return;
#endif

    if ((f = fopen(findhome(save), "r")) == NULL) {
    	sprintf(stringbuf, "Can't read file \"%s\"", save);
	error(stringbuf);
	return;
    }

    if (eraseflg) erasedb();

    loading++;
    while (fgets(line, sizeof line, f)) {
        linelim = 0;
	if (!strncmp(line, "Graph Def", 9)) 
            read_plot_options(f, &baseplot);
        else if (line[0] != '#') yyparse ();
    }
    --loading;
    fclose(f);
    linelim = -1;
    modflg++;
    if (eraseflg) {
	strcpy(curfile, save);
	modflg = 0;
    }
    EvalAll();
}

/* erase the database (tbl, etc.) */
void
erasedb(void)
{
    register int r, c;

    for (c = 0; c<=maxcol; c++) {
	fwidth[c] = DEFWIDTH;
	precision[c] = DEFPREC;
	realfmt[c] = DEFREFMT;
    }

    for (r = 0; r<=maxrow; r++) {
	register struct ent **pp = ATBL(tbl, r, 0);
	for (c=0; c++<=maxcol; pp++)
	    if (*pp) {
		if ((*pp)->expr) efree((*pp)->expr);
		if ((*pp)->label) scxfree((*pp)->label);
		(*pp)->next = freeents;	/* save [struct ent] for reuse */
		freeents = *pp;
		*pp = NULL;
	    }
    }
    maxrow = 0;
    maxcol = 0;
    clean_range();
    FullUpdate++;
}

/* moves curcol back one displayed column */
void
backcol(int arg)
{    
    prvmx = lastmx; 
    prvmy = lastmy;
    prvcol = lastcol; /* lines added by Bob Parbs 12-92 */ 

    while (--arg >= 0) {
	if (curcol)
	    curcol--;
	else {
	    error ("At column A");
	    break;
	}
	while (col_hidden[curcol] && curcol)
	    curcol--;
    }
}

/* moves curcol forward one displayed column */
void
forwcol(int arg)
{
    prvmx = lastmx; 
    prvmy = lastmy; 
    prvcol = lastcol; /* lines added by Bob Parbs 12-92 */

    while (--arg >= 0) {
	if (curcol < maxcols - 1)
	    curcol++;
	else
	    if (!growtbl(GROWCOL, 0, arg))	/* get as much as needed */
		break;
	    else
		curcol++;
	while(col_hidden[curcol]&&(curcol<maxcols-1))
	    curcol++;
    }
}

/* moves currow forward one displayed row */
void
forwrow(int arg)
{
    prvmx = lastmx; 
    prvmy = lastmy; 
    prvcol = lastcol; /* lines added by Bob Parbs 12-92 */

    while (--arg>=0) {
	if (currow < maxrows - 1)
	    currow++;
	else
	    if (!growtbl(GROWROW, arg, 0))	/* get as much as needed */
		break;
	    else
		currow++;
	while (row_hidden[currow]&&(currow<maxrows-1))
	    currow++;
    }
}

/* moves currow backward one displayed row */
void
backrow(int arg)
{
    prvmx = lastmx; 
    prvmy = lastmy; 
    prvcol = lastcol; /* lines added by Bob Parbs 12-92 */

    while (--arg >= 0) {
	if (currow)
	    currow--;
	else {
	    error("At row zero");
	    break;
	}
	while (row_hidden[currow] && currow)
	    currow--;
    }
}


/*
 * Show a cell's label string or expression value.  May overwrite value if
 * there is one already displayed in the cell.  Created from old code in
 * update(), copied with minimal changes.
 */

void
showstring(char *string,       /* to display */
	   int dirflush,       /* or rightflush or centered */
	   int hasvalue,       /* is there a numeric value? */
	   int row, int col,   /* spreadsheet location */
	   int *nextcolp,      /* value returned through it */
	   int mxcol,          /* last column displayed? */
	   int *fieldlenp,     /* value returned through it */
	   int r, int c,       /* screen row and column */
	   int do_stand)       /* if standout needed */
{
    register int nextcol = *nextcolp;
    register int fieldlen = *fieldlenp;

    char field[FBUFLEN];
    int slen;
    char *start, *last;
    register char *fp;
    struct ent *nc;

    /* This figures out if the label is allowed to
       slop over into the next blank field */

    slen = strlen (string);
    if (*string == '\\' && *(string+1)!= '\0')
	slen = fwidth[col];
    while ((slen > fieldlen) && (nextcol <= mxcol) &&
	   !((nc = lookat (row, nextcol))->flags & is_valid) &&
	   !(nc->label)) {

	if (! col_hidden [nextcol])
	    fieldlen += fwidth [nextcol];

	nextcol++;
    }
    if (slen > fieldlen)
	slen = fieldlen;

    /* Now justify and print */
    start = (dirflush&is_leftflush) ? field : field + fieldlen - slen;
    if (dirflush & is_label)
	start = field + ((slen<fwidth[col]) ? (fieldlen-slen)/2 : 0);
    last = field+fieldlen;
    fp = field;
    while (fp < start)
	*fp++ = ' ';
    if (*string == '\\'  && *(string+1)!= '\0') {
	char *strt;
	strt = ++string;

	while(slen--) {
	    *fp++ = *string++;
	    if (*string == '\0')
		string = strt;
	}
    }
    else
	while (slen--)
	    *fp++ = *string++;

    if ((! hasvalue) || fieldlen != fwidth[col]) 
	while (fp < last)
	    *fp++ = ' ';
    *fp = '\0';

    XDrawImageString(dpy, mainwin, do_stand ? maingcreversed : maingc,
                     textcol(c), textrow(r),
                     field, strlen(field));

    *nextcolp  = nextcol;
    *fieldlenp = fieldlen;
}

int
etype(register struct enode *e)
{
    if (e == NULL)
	return NUM;
    switch (e->op) {
    case UPPER: case LOWER: case CAPITAL:
    case O_SCONST: case '#': case DATE: case FMT: case STINDEX:
    case EXT: case SVAL: case SUBSTR:
        return STR;

    case '?':
    case IF:
        return etype(e->e.o.right->e.o.left);

    case 'f':
        return etype(e->e.o.right);

    case O_VAR: {
	register struct ent *p;

	p = e->e.v.vp;
	if (p->expr) 
	    return (p->flags & is_strexpr)? STR : NUM;
	else if (p->label)
	    return STR;
	else
	    return NUM;
    }

    default:
	return NUM;
    }
}

/* return 1 if yes given, 0 otherwise */
int
yn_ask(char *msg)
{	
    char ch;
    XEvent event;
    char buffer[8];

    clearlines(1, 1);
    XDrawImageString(dpy, mainwin, maingc,
		     textcol(0), textrow(1),
		     msg, strlen(msg));
    update(0);

    while (1) {
	XWindowEvent(dpy, mainwin, KeyPressMask, &event);
	if (event.type == KeyPress) {
	    if (XLookupString(&(event.xkey), buffer, 8, 0, 0)) {
		ch = buffer[0];
		if (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') {
		    if (ch == ctl('g') || ch == ESC)
			return -1;
		    error("y or n response required");
		    return -1;
		}
		if (ch == 'y' || ch == 'Y')
		    return 1;
		else
		    return 0;
	    }
	} else {
	    error("Y or N keypress is required");
	    return -1;
	}
    }
    return 0;
}

/* expand a ~ in a path to your home directory */
#include <pwd.h>

char *
findhome(char *path)
{
    static char *HomeDir;

    if (*path == '~') {
	char *pathptr;
	char tmppath[PATHLEN];

	if (HomeDir == NULL) {
	    HomeDir = getenv("HOME");
	    if (HomeDir == NULL)
		HomeDir = "/";
	}
	pathptr = path + 1;
	if ((*pathptr == '/') || (*pathptr == '\0')) {
	    strcpy(tmppath, HomeDir);
	} else {
	    struct passwd *pwent;
	    char *namep;
	    char name[50];

	    namep = name;
	    while ((*pathptr != '\0') && (*pathptr != '/'))
		*(namep++) = *(pathptr++);
	    *namep = '\0';
	    if ((pwent = getpwnam(name)) == NULL) {
		sprintf(path, "Can't find user %s", name);
		return NULL;
	    }
	    strcpy(tmppath, pwent->pw_dir);
	}
	strcat(tmppath, pathptr);
	strcpy(path, tmppath);
    }
    return path;
}

#ifdef DOBACKUPS
#include <sys/stat.h>

/*
 * make a backup copy of a file, use the same mode and name in the format
 * [path/]#file~
 * return 1 if we were successful, 0 otherwise
 */
int
backup_file(char *path)
{
    struct stat statbuf;
    char fname[PATHLEN];
    char tpath[PATHLEN];
    char buf[BUFSIZ];
    char *tpp;
    int	infd, outfd;
    int	count;

    /* tpath will be the [path/]file ---> [path/]#file~ */
    strcpy(tpath, path);
    if ((tpp = strrchr(tpath, '/')) == NULL)
	tpp = tpath;
    else
	tpp++;
    strcpy(fname, tpp);
    sprintf(tpp, "#%s~", fname);

    if (stat(path, &statbuf) == 0) {
	if ((infd = open(path, O_RDONLY, 0)) < 0)
	    return 0;

	if ((outfd = open(tpath, O_TRUNC|O_WRONLY|O_CREAT,
			  statbuf.st_mode)) < 0)
	    return 0;

	while ((count = read(infd, buf, sizeof buf)) > 0) {
	    if (write(outfd, buf, count) != count) {
		count = -1;
		break;
	    }
	}
	close(infd);
	close(outfd);

	return (count < 0) ? 0 : 1;
    } else
	if (errno == ENOENT)
	    return 1;
    return 0;
}
#endif

/* replace a possible '.xsw' or '.' suffix with "ending" */
char *
fsuffix(char *fname, char *ending)
{	
    char *newname, *chp, *slp;

    if ((newname = scxmalloc(strlen(fname) + 1 + strlen(ending))) != NULL) {
	strcpy(newname, fname);

	/* chp will point to the start of the filename, path seperator */
	if ((slp = strrchr(newname, '/')) != NULL) {
	    *slp = '\0';
	    chp = slp+1;
	} else
	    chp = newname;
	
	/* start of .xsw? */
	if ((chp = strrchr(chp, '.')) != NULL) {
	    if (strncmp(chp, ".xsw", strlen(chp)) == 0)
		*chp = '\0';
	}

	/* put the path '/' back */
	if (slp != NULL)
	    *slp = '/';
	strcat(newname, ending);
    }
    return newname;
}
