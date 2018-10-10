/*	SC	A Spreadsheet Calculator
 *		Spreadsheet 'tbl' creation
 *
 *		original by James Gosling, September 1982
 *		modifications by Mark Weiser and Bruce Israel,
 *			University of Maryland
 *
 *              More mods Robert Bond, 12/86
 *		More mods by Alan Silverstein, 3-4/88, see list of changes.
 *		Currently supported by gator!sawmill!buhrt (Jeff Buhrt)
 *		$Revision: 1.5 $
 *
 */

#include <stdio.h>

#include "config.h"
#include "sc.h"

#define GROWALLOC(newptr, oldptr, nelem, type, msg) \
	newptr = scxrealloc(oldptr, nelem * sizeof(type)); \
	if (newptr == NULL) { \
	    error(msg); \
	    return FALSE; \
	} \
	oldptr = newptr; /* wait in case we can't alloc */

/*
 * check to see if *rowp && *colp are currently allocated, if not expand the
 * current size if we can.
 */
void
checkbounds(int *rowp, int *colp)
{
    if (*rowp < 0)
	*rowp = 0;
    else if (*rowp >= maxrows) {
	if (*colp >= maxcols) {
	    if (!growtbl(GROWBOTH, *rowp, *colp)) {
		*rowp = maxrows -1;
		*colp = maxcols -1;
	    }
	    return;
	}
	else {
	    if (!growtbl(GROWROW, *rowp, 0))
		*rowp = maxrows-1;
	    return;
	}
    }
    if (*colp < 0) 
	*colp = 0;
    else if (*colp >= maxcols) {
	if (!growtbl(GROWCOL, 0, *colp))
	    *colp = maxcols-1;
    }
}
	
static char nolonger[] = "The table can't be any longer";
static char nowider[] = "The table can't be any wider";

/*
 * grow the main && auxiliary tables (reset maxrows/maxcols as needed)
 * toprow &&/|| topcol tell us a better guess of how big to become.
 * we return TRUE if we could grow, FALSE if not....
 */
int
growtbl(int rowcol, int toprow, int topcol)
{
    int	*fwidth2;
    int	*precision2;
    int *realfmt2;
    int	newcols;
    char *col_hidden2;
    int	i;
    struct ent ***tbl2;
    struct ent **nullit;
    int	cnt;
    char *row_hidden2;
    int	newrows;

    newrows = maxrows;
    newcols = maxcols;
    if (rowcol == GROWNEW) {
	int startval;

	maxrows = toprow = 0;
	/* when we first start up, fill the screen w/ cells */
	startval = maintextrows - RESROW;
	newrows = startval > MINROWS ? startval : MINROWS;
	startval = (maintextcols - RESCOL) / DEFWIDTH;
	newcols = startval > MINCOLS ? startval : MINCOLS;
	maxcols = topcol = 0;
    }

    /* set how much to grow */
    if ((rowcol == GROWROW) || (rowcol == GROWBOTH)) {
	if (toprow > maxrows)
	    newrows = GROWAMT + toprow;
	else
	    newrows += GROWAMT;
    }

    if (rowcol == GROWCOL || rowcol == GROWBOTH) {
	if (rowcol == GROWCOL && (maxcols == ABSMAXCOLS ||
				  topcol >= ABSMAXCOLS)) {
	    fprintf(stderr, nowider);
	    return FALSE;
	}

	if (topcol > maxcols)
	    newcols = GROWAMT + topcol;
	else
	    newcols += GROWAMT;

	if (newcols > ABSMAXCOLS)
	    newcols = ABSMAXCOLS;
    }

    if ((rowcol == GROWROW) || (rowcol == GROWBOTH) || 
	(rowcol == GROWNEW)) {
	struct ent ***lnullit;
	int lcnt;

	GROWALLOC(row_hidden2, row_hidden, newrows, char, nolonger);
	memset(row_hidden + maxrows, 0, newrows - maxrows);

	/*
	 * alloc tbl row pointers, per net.lang.c, calloc does not
	 * necessarily fill in NULL pointers
	 */
	GROWALLOC(tbl2, tbl, newrows, struct ent **, nolonger);
	for (lnullit = tbl+maxrows, lcnt = 0; lcnt < newrows-maxrows;
	     lcnt++, lnullit++)
	    *lnullit = NULL;
    }

    if ((rowcol == GROWCOL) || (rowcol == GROWBOTH) || 
	(rowcol == GROWNEW)) {
	GROWALLOC(fwidth2, fwidth, newcols, int, nowider);
	GROWALLOC(precision2, precision, newcols, int, nowider);
	GROWALLOC(realfmt2, realfmt, newcols, int, nowider);
	GROWALLOC(col_hidden2, col_hidden, newcols, char, nowider);
	memset(col_hidden+maxcols, 0, newcols-maxcols);
	for (i = maxcols; i < newcols; i++) {
	    fwidth[i] = DEFWIDTH;
	    precision[i] = DEFPREC;
	    realfmt[i] = DEFREFMT;
	}

	/* [re]alloc the space for each row */
	for (i=0; i<maxrows; i++) {
	    tbl[i] = scxrealloc(tbl[i], newcols * sizeof(struct ent **));
	    if (tbl[i] == NULL) {
		error(nowider);
		return FALSE;
	    }
	    for (nullit = ATBL(tbl, i, maxcols), cnt = 0;
		 cnt < newcols-maxcols; cnt++, nullit++)
		*nullit = NULL;
	}
    } else
	i = maxrows;

    /* fill in the bottom of the table */
    for (; i<newrows; i++) {
	tbl[i] = scxmalloc(newcols * sizeof(struct ent **));
	if (tbl[i] == NULL) {
	    error(nowider);
	    return FALSE;
	}
	for (nullit=tbl[i], cnt=0; cnt<newcols; cnt++, nullit++)
	    *nullit = NULL;
    }

    FullUpdate++;
    maxrows = newrows;

    maxcols = newcols;
    return TRUE;
}
