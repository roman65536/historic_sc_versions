/*	SC	A Spreadsheet Calculator
 *		Curses based Screen driver
 *
 *		original by James Gosling, September 1982
 *		modifications by Mark Weiser and Bruce Israel,
 *			University of Maryland
 *
 *              More mods Robert Bond, 12/86
 *		More mods by Alan Silverstein, 3-4/88, see list of changes.
 *		More mods by Peter Doemel, 2/93: static prvstring in update
 *		Currently supported by gator!sawmill!buhrt (Jeff Buhrt)
 *		$Revision: 1.23 $
 *
 */

#include "config.h"

#include <stdio.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "sc.h"
#include "scXstuff.h"

extern char revmsg[];

int prvmx, prvmy, prvcol;   /* line added by Bob Parbs 12-92 */

int rows, lcols;
int lastmx, lastmy;	/* Screen address of the cursor */
int lastcol;	        /* Spreadsheet Column the cursor was in last */
extern int showrange;	/* Causes ranges to be highlighted */
extern int showneed;	/* Causes cells needing values to be highlighted */
extern int showexpr;	/* Causes cell exprs to be displayed, highlighted */
extern int showgrid;    /* Show worksheet grid lines */

int called = 0;
/*
 * update() does general screen update
 *
 * standout last time in update()?
 */
int standlast = FALSE;

void
update(int anychanged)
     /* did any cell really change in value? */
{
    register int row, col;
    register struct ent **pp;
    int	mxrow, mxcol;
    int	minsr = 0, minsc = 0, maxsr = 0, maxsc = 0;
    register int r, i;
    static int lastcurcol = -1, lastcurrow = -1;
    char field[FBUFLEN];
    static char prvstring[FBUFLEN];

    /* place the cursor on the screen, 
       set col, curcol, stcol, lastcol as needed
    */
    if (curcol != lastcurcol || FullUpdate) {
	while (col_hidden[curcol]) /* Can't hide the last row or col */
	    curcol++;

	/* First see if the last display still covers curcol */
	if (stcol <= curcol) {
	    for (i = stcol, lcols = 0, col = RESCOL;
		 (col + fwidth[i]) < maintextcols-1 && i < maxcols; i++) {
		lcols++;
		if (col_hidden[i]) continue;
		col += fwidth[i];
	    }
	}
	while (stcol + lcols - 1 < curcol || curcol < stcol) {
	    FullUpdate++;
	    if (stcol - 1 == curcol)    /* How about back one? */
		stcol--;
	    else if (stcol + lcols == curcol)    /* Forward one? */
		stcol++;
	    else {
		/* Try to put the cursor in the center of the screen */
		col = (maintextcols - RESCOL - fwidth[curcol]) / 2 + RESCOL; 
		stcol = curcol;
		for (i=curcol-1; i >= 0 && col-fwidth[i] > RESCOL; i--) {
		    stcol--;
		    if (col_hidden[i])
			continue;
		    col -= fwidth[i];
		}
	    }
	    /* Now pick up the counts again */
	    for (i=stcol, lcols=0, col=RESCOL;
		 (col + fwidth[i]) < maintextcols-1 && i < maxcols; i++) {
		lcols++;
		if (col_hidden[i])
		    continue;
		col += fwidth[i];
	    }
	}
	lastcurcol = curcol;
    }

    /* Now - same process on the rows as the columns */
    if (currow != lastcurrow || FullUpdate) {
	while (row_hidden[currow])   /* You can't hide the last row or col */
	    currow++;
	if (strow <= currow) {
	    for (i=strow, rows=0, row=RESROW; row<maintextrows 
		     && i<maxrows; i++) {
		rows++;
		if (row_hidden[i]) continue;
		row++;
	    }
	}

	while (strow + rows - 1 < currow || currow < strow) {
	    FullUpdate++;
	    if (strow - 1 == currow)     /* How about up one? */
		strow--;
	    else if (strow + rows == currow)   /* Down one? */
		strow++;
	    else {
		/* Try to put the cursor in the center of the screen */
		row = (maintextrows - RESROW) / 2 + RESROW; 
		strow = currow;
		for (i=currow-1; i >= 0 && row-1 > RESROW; i--) {
		    strow--;
		    if (row_hidden[i])
			continue;
		    row--;
		}
	    }
	    /* Now pick up the counts again */
	    for (i=strow, rows=0, row=RESROW; row<maintextrows 
		     && i<maxrows; i++) {
		rows++;
		if (row_hidden[i])
		    continue;
		row++;
	    }
	}
	lastcurrow = currow;
    }
    mxcol = stcol + lcols - 1;
    mxrow = strow + rows - 1;

    /* Get rid of cursor standout on the cell at previous cursor position */
    if (!FullUpdate) {
	XDrawImageString(dpy, mainwin, maingc, 
		         textcol(prvmx), textrow(prvmy),
		         prvstring, strlen(prvstring));
	XFillRectangle(dpy, mainwin, invertgc, 
		       textcol(prvmx), /* x co-ord of top left corner */
		       textrow(prvmy-1) + CURSOR_OFFSET, /* y co-ord */
		       textcol(fwidth[prvcol]), /* width of rectangle */
		       textrow(0)); /* height */
    }

    /* where is the the cursor now? */
    lastmy = RESROW;
    for (row = strow; row < currow; row++)
	if (!row_hidden[row])
	    lastmy++;

    lastmx = RESCOL;
    for (col = stcol; col < curcol; col++)
	if (!col_hidden[col])
	    lastmx += fwidth[col];
    lastcol = curcol;

    /* relabel the rows and columns if a full update is performed */
    if (FullUpdate || standlast) {
        cleardownfrom(2);

	for (row=RESROW, i=strow; i<=mxrow; i++) {
	    if (row_hidden[i]) 
		continue;
	    sprintf(stringbuf, "%-*d", (maxrows < 1000)? RESCOL-1 : RESCOL, i);
	    XDrawImageString(dpy, mainwin, maingcreversed,
			     textcol(0), textrow(row),
			     stringbuf, strlen(stringbuf));
	    row++;
	}
        /* the following will work as long as RESCOL<20.  It is 
	 * more efficient than the usual sprintf(stringbuf..) and
	 * XDrawString(...strlen(stringbuf)) combination
	 */
        XDrawImageString(dpy, mainwin, maingcreversed,
			 textcol(0), textrow(3),
			 "                    ", 
			 RESCOL);
	for (col=RESCOL, i=stcol; i<=mxcol; i++) {
	    register int k;

	    if (col_hidden[i])
		continue;
	    k = fwidth[i] / 2;
	    if (k == 0)
		sprintf(stringbuf, "%1s", coltoa(i));
	    else
		sprintf(stringbuf, "%*s%-*s", k, " ", fwidth[i]-k, coltoa(i));
            XDrawImageString(dpy, mainwin, maingcreversed,
                             textcol(col), textrow(3),
                             stringbuf, strlen(stringbuf));
	    col += fwidth[i];
	}
    }

    if (showrange) {
	minsr = showsr < currow ? showsr : currow;
	minsc = showsc < curcol ? showsc : curcol;
	maxsr = showsr > currow ? showsr : currow;
	maxsc = showsc > curcol ? showsc : curcol;

	sprintf(stringbuf, "Default range: %s",
		r_name(minsr, minsc, maxsr, maxsc)); 
	XDrawImageString(dpy, mainwin, maingc,
			 textcol(0), textrow(1),
			 stringbuf, strlen(stringbuf));
    }

    /* Repaint the visible screen */
    if (showrange || anychanged || FullUpdate || standlast) {
	/* may be reset in loop, if not next time we will do a FullUpdate */
	if (standlast) {
	    FullUpdate = TRUE;
	    standlast = FALSE;
	}

	for (row=strow, r=RESROW; row<=mxrow; row++) {
	    register int c = RESCOL;
	    int do_stand = 0;
	    int fieldlen;
	    int nextcol;

	    if (row_hidden[row])
		continue;
	    for (pp = ATBL(tbl, row, col = stcol); col <= mxcol;
		 pp += nextcol - col,  col = nextcol, c += fieldlen) {

		nextcol = col + 1;
		if (col_hidden[col]) {
		    fieldlen = 0;
		    continue;
		}
		fieldlen = fwidth[col];

		/*
		 * Set standout if:
		 *
		 * - showing ranges, and not showing cells which need to 
		 *   be filled in, and not showing cell expressions, 
		 *   and in a range, OR
		 *
		 * - if showing cells which need to be filled in and this one is
		 *   of that type (has a value and doesn't have an expression,
		 *   or it is a string expression), OR
		 *
		 * - if showing cells which have expressions and this one does.
		 */

		if ((showrange && (!showneed) && (!showexpr)
		     && (row >= minsr) && (row <= maxsr)
		     && (col >= minsc) && (col <= maxsc))
		    || (showneed && (*pp) && ((*pp)->flags & is_valid) &&
			(((*pp)->flags & is_strexpr) || !((*pp)->expr)))
		    || (showexpr && (*pp) && ((*pp)->expr))) {
		    standlast++;
		    if (!*pp) { /* no cell, but standing out */
			sprintf(stringbuf, "%*s", fwidth[col], " ");
			XDrawImageString(dpy, mainwin, maingcreversed,
					 textcol(c), textrow(r),
					 stringbuf, strlen(stringbuf));
			continue;
		    }
		    else
			do_stand = 1;
		} else
		    do_stand = 0;

		if ((*pp) && 
		    (((*pp)->flags & is_changed || FullUpdate) || do_stand)) {
		    if (do_stand) 
			(*pp)->flags |= is_changed; 
		    else 
			(*pp)->flags &= ~is_changed;

		    /* Show expression; takes priority over other displays */
		    if ((*pp)->cellerror) {
			sprintf(stringbuf, "%*.*s", fwidth[col], fwidth[col],
				(*pp)->cellerror == CELLERROR ? 
				"ERROR" : "INVALID");
			XDrawImageString(dpy,mainwin,
					 do_stand ? maingcreversed : maingc,
					 textcol(c),textrow(r),
					 stringbuf, strlen(stringbuf));
		    } else
			if (showexpr && ((*pp)->expr)) {
			    linelim = 0;
			    editexp(row, col); /* set line to expr */
			    linelim = -1;
			    showstring(line, /* leftflush = */ 
				       1,    /* hasvalue = */ 
				       0,
				       row, col, &nextcol, mxcol, 
				       &fieldlen, r, c, do_stand);
			} else {
				/* Show cell's numeric value: */
			    if ((*pp)->flags & is_valid) {
				if ((*pp)->format) {
				    (void) format((*pp)->format, (*pp)->v,
						  field, sizeof(field));
				} else {
				    (void) engformat(realfmt[col], fwidth[col], 
						     precision[col], (*pp)->v, 
						     field, sizeof(field));
				}
				if (strlen(field) > fwidth[col]) {
				    for(i = 0; i<fwidth[col]; i++)
					field[i] = '*';
				    field[fwidth[col]] = '\0';

				    /* following statement to print case 
				       of field too long Bob Parbs 12-92 */
				    XDrawImageString(dpy, mainwin,
						     do_stand? maingcreversed: maingc,
						     textcol(c + fwidth[col] - strlen(field)),
						     textrow(r), field, strlen(field));
				} else {
				    XDrawImageString(dpy, mainwin,
						     do_stand? maingcreversed: maingc,
						     textcol(c + fwidth[col] - strlen(field)),
						     textrow(r), field, strlen(field));
				    strncpy(prvstring, field, FBUFLEN);
				}
			    }

                            /* Show cell's label string: */
			    if ((*pp)->label) {
				showstring((*pp)->label,
					   (*pp)->flags & (is_leftflush|is_label),
					   (*pp)->flags & is_valid,
					   row, col, &nextcol, mxcol,
					   &fieldlen, r, c, do_stand);
			    } else /* repaint a blank cell: */
				if ((do_stand || !FullUpdate) &&
				    ((*pp)->flags & is_changed) &&
				    !((*pp)->flags & is_valid) && !(*pp)->label) {
				    sprintf (stringbuf, "%*s", fwidth[col], " ");
				    XDrawImageString(dpy, mainwin,
						     do_stand? maingcreversed: maingc,
						     textcol(c), textrow(r),
						     stringbuf, strlen(stringbuf));
				}
			} /* else */

		    if (do_stand) {
			do_stand = 0;
		    }
		}
	    }
	    r++;
	}
    }
    called++;

    if (called) {
	XFillRectangle(dpy, mainwin, invertgc, textcol(lastmx),
		       (textrow(lastmy - 1) + CURSOR_OFFSET), 
		       textcol(fwidth[lastcol]), textrow(0));
        prvmx = lastmx;    /* three statements added by Bob Parbs 12-92 */
        prvmy = lastmy;    /* to prevent screen write if no cursor      */
        *prvstring = '\0'; /* movement but other command executed.      */
	prvcol = lastcol;  /* added by Allin Cottrell */
    }

    show_top_line();

    if (showgrid) {  /* draw grid lines on worksheet */
	for (col=RESCOL, i=stcol; i<=mxcol+1; i++) { /* verticals */
	    if (i > stcol)
		XDrawLine(dpy, mainwin, graygc, 
			  textcol(col), gridrow(2) + 1,
			  textcol(col), gridrow(RESROW + mxrow));
	    col += fwidth[i];
	}
	col -= fwidth[mxcol+1];
	for (row=RESROW, i=strow; i<=mxrow; i++) { /* horizontals */
	    XDrawLine(dpy, mainwin, graygc, 
		      0, gridrow(row),
		      textcol(col), gridrow(row));
	    row++;
	}
    }

    FullUpdate = FALSE;
}

int seenerr;

/* error routine for yacc (gram.y) */
void
yyerror(char *err)
{
    if (seenerr) return;
    seenerr++;

    clearlines(1, 1);
    sprintf(stringbuf, "%s: %.*s<=%s", err, linelim, line, line+linelim);
    XDrawImageString(dpy, mainwin, maingc,
		     textcol(0), textrow(1), stringbuf, strlen(stringbuf));
    XFlush(dpy);
}

static char * 
get_prompt(int i)
{
    /* a prompt string for each mode in sc.h */
    static char *modestr[] = {
	"",     /* NULL_MODE */
	"$ ",   /* EDIT_MODE */
	"",     /* GRAB_MODE */
	"v> ",  /* VI_MODE */
	"R> ",  /* REP_MODE */
	"/> "   /* SEARCH_MODE */
    };

    if (i >=0 && i < sizeof modestr / sizeof modestr[0])
	return modestr[i];
    else /* should be impossible! */
	return NULL;
}

void
show_top_line(void)
{ 
    static int started;
    char *modestr;
    int mlen = 0;

    clearlines(0, 0);
    stringbuf[0] = '\0';

#ifdef DEBUG
    fprintf(stderr, "doing show_top_line()\n");
#endif
    if (linelim >= 0) {
	modestr = get_prompt(topline_mode);
	if (modestr) mlen = strlen(modestr);
	sprintf(stringbuf, "%s%s ", modestr, line); /* was "%s%s_" */
	XDrawImageString(dpy, mainwin, maingc,
			 textcol(0), textrow(0), stringbuf, linelim+mlen);
	XDrawImageString(dpy, mainwin, maingcreversed,
			 textcol(linelim+mlen), textrow(0), 
			 &stringbuf[linelim+mlen], 1);
	XDrawImageString(dpy, mainwin, maingc,
			 textcol(linelim+mlen+1), textrow(0), 
			 &stringbuf[linelim+mlen+1],
			 strlen(stringbuf)-linelim-mlen-1);
    } else {
	register struct ent *p1;
	int printed = 0;		/* printed something? */
	    
	/* show the current cell's format */
	if ((p1 = *ATBL(tbl, currow, curcol)) && p1->format)
	    sprintf(stringbuf, "%s%d (%s) ", coltoa(curcol), currow,
		    p1->format);
	else
	    sprintf(stringbuf, "%s%d (%d %d %d) ", coltoa(curcol), currow,
		    fwidth[curcol], precision[curcol], realfmt[curcol]);

	if (p1) {
	    if (p1->expr) {
		/* has expr of some type */
		linelim = 0;
		editexp(currow, curcol);	/* set line to expr */
		linelim = -1;
	    }

	    /* Display string part of cell */
	    if ((p1->expr) && (p1->flags & is_strexpr)) {
		if ((p1->flags & is_label))
		    strcat(stringbuf, "|{");
		else
		    strcat(stringbuf, 
			   ((p1->flags & is_leftflush) ? "<{" : ">{"));
		strcat(stringbuf, line);
		strcat(stringbuf, "} ");	/* and this '}' is for vi % */
		printed = 1;
	    } else if (p1->label) {
		/* has constant label only */
		if ((p1->flags & is_label))
		    strcat(stringbuf, "|\"");
		else
		    strcat(stringbuf, 
			   (p1->flags & is_leftflush) ? "<\"" : ">\"");
		strcat(stringbuf, p1->label);
		strcat(stringbuf, "\" ");
		printed = 1;
	    }

	    /* Display value part of cell */
	    if (p1->flags & is_valid) {
		/* has value or num expr */
		if ((!(p1->expr)) || (p1->flags & is_strexpr))
#ifdef VR3
		    (void) sprintf (line, "%.8g", p1->v);
#else
		(void) sprintf (line, "%.15g", p1->v);
#endif
		strcat(stringbuf, "[");
		strcat(stringbuf, line);
		strcat(stringbuf, "]");
		*line = '\0'; /* this is the input buffer ! */
		printed = 1;
	    }
	}
	if (!printed)
	    strcat(stringbuf, "[]");
	/* Display if cell is locked */
	if (p1 && p1->flags & is_locked)
	    strcat(stringbuf, " locked");

	XDrawImageString(dpy, mainwin, maingc,
			 textcol(0), textrow(0), 
			 stringbuf, strlen(stringbuf));
    }

    /* Show initial program info, on startup only */
    if (started < 2) {
	clearlines(0, 0);
	XDrawImageString(dpy, mainwin, maingc,
			 textcol(0), textrow(0),
			 revmsg, strlen(revmsg));
	clearlines(1, 1);
	XDrawImageString(dpy, mainwin, maingc,
			 textcol(0), textrow(1),
			 "Type '?' for help, '/' for menu",
			 strlen("Type '?' for help, '/' for menu"));
	started++;
    }

    /* Draw indicator for whether focus is on sheet or not */
    if (focus == FOCUS_SHEET) 
	XDrawImageString(dpy, mainwin, maingcreversed, 
			 textcol(0), textrow(3),
			 "*", 1);
    else
	XDrawImageString(dpy, mainwin, maingcreversed, 
			 textcol(0), textrow(3),
			 " ", 1);

    FullUpdate = 0;
}

void
clearlines (int start, int end)
     /* clear the lines start through end, given in text coordinates */
{
    int temp; 

    if (start > end) {
	temp = end;
	end = start;
	start = temp;
    }

    XClearArea(dpy,mainwin,
	       0, textrow(start) - curfontheight + CLEAR_START_ADD, 
	       /* above: top left corner of area */
	       0, /* 0 width => full window width */
	       textrow(end) - textrow(start) + 
	       curfontheight + CLEAR_HEIGHT_ADD, /* height of area */
	       0);    /* don't send Expose events */
}



