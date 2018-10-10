/*	SC	A Spreadsheet Calculator
 *		Main driver
 *
 *		original by James Gosling, September 1982
 *		modifications by Mark Weiser and Bruce Israel,
 *			University of Maryland
 *
 *              More mods Robert Bond, 12/86
 *		More mods by Alan Silverstein, 3-4/88, see list of changes.
 *		Currently supported by gator!sawmill!buhrt (Jeff Buhrt)
 *		$Revision: 1.20 $
 *        
 *              More mods by Allin Cottrell, 5/2001
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <ctype.h>
#include <time.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

#include "config.h"
#include "sc.h"
#include "scXstuff.h"
#include "plot.h"
#include "version.h"

#define MAXCMD 160	/* for ! command below */

static void File_Menu(int);
static void Option_Menu1(int);
static void Option_Menu2(int);
static void Row_Col_Menu(int);
static void Range_Menu(int);
static void prompt(const char *pstr, const char *hint);
static void startshow(void);
static void showdr(void);

void Main_Menu(void);

/* functions from matrix.c */
extern void get_add_sub(int);
extern void get_trans_invert(int); 
extern void get_mult(void); 
extern void get_regress(void);

#ifdef VR3
extern void print_small_help(void);  /* small_help.c */
#else
extern void print_help(void);        /* help.c */
#endif

/* link to fltk file dialog, in scstub.c */
extern int
get_filename(const char *msg, const char *pat, char *fname, 
	     const char *start); 

/* Globals defined in sc.h */
struct ent ***tbl;
int topline_mode;
int strow = 0, stcol = 0;
int currow = 0, curcol = 0;
int savedrow, savedcol;
int FullUpdate = 0;
int ClearScreen = 0;	/* don't try to be smart */
int showgrid = 1;   
int maxrow, maxcol;
int maxrows, maxcols;
int *fwidth;
int *precision;
int *realfmt;
char *col_hidden;
char *row_hidden;
char line[FBUFLEN];
int changed;
struct ent *to_fix;
int modflg;
int showsc, showsr;	/* Starting cell for highlighted range */
int maintextrows,       /* text rows in main window */
    maintextcols;       /* text cols in main window */

char stringbuf[1024];    /* build misc. strings for display on screen */

char curfile[PATHLEN];
char revmsg[80];

int linelim = -1;

int showrange = 0;	/* Causes ranges to be highlighted		  */
int showneed  = 0;	/* Causes cells needing values to be highlighted  */
int showexpr  = 0;	/* Causes cell exprs to be displayed, highlighted */

int numeric;		/* data entry mode: 1 for numeric */ 
                        /* Peter Doemel, 11-Feb-1993 */
int autocalc;		/* 1 to calculate after each update               */
int calc_order; 	/* order of calculation: BYROWS or BYCOLS         */
int craction = 0;	/* CRCOLS for down, CRROWS for right              */

int tbl_style = 0;	/* headers for T command output */
int rndinfinity = 0;
int numeric_field = 0;  /* Started the line editing with a number */
int rowlimit = -1;
int collimit = -1;
int focus = FOCUS_SHEET;
int showhint = 0;

extern int lastmx, lastmy;	/* Screen address of the cursor */
extern int lastcol, lcols;	/* Spreadsheet Column the cursor was in last */

/* a linked list of free [struct ent]'s, uses .next as the pointer */
struct ent *freeents = NULL;

extern int seenerr;
extern char *rev;
int anychanged = FALSE;

/* apparatus for setting Save/Export range */
static struct m_range save_range;
static int save_range_set;

/* graph struct: can be extended to allow for multiple graphs */
struct graph baseplot;

/* return a pointer to a cell's [struct ent *], creating if needed */
struct ent *
lookat(int row, int col)
{
    register struct ent **pp;

    checkbounds(&row, &col);
    pp = ATBL(tbl, row, col);
    if (*pp == NULL) {
        if (freeents != NULL) {
	    *pp = freeents;
	    freeents = freeents->next;
	} else
	    *pp = scxmalloc(sizeof **pp);
	if (row>maxrow) maxrow = row;
	if (col>maxcol) maxcol = col;
	(*pp)->label = NULL;
	(*pp)->row = row;
	(*pp)->col = col;
	(*pp)->flags = 0;
	(*pp)->expr = NULL;
	(*pp)->v = 0.0;
	(*pp)->format = NULL;
	(*pp)->cellerror = CELLOK;
	(*pp)->next = NULL;
    }
    return *pp;
}

/*
 * This structure is used to keep ent structs around before they
 * are deleted to allow the sync_refs routine a chance to fix the
 * variable references.
 * We also use it as a last-deleted buffer for the 'p' command.
 */
void
free_ent(register struct ent *p)
{
    p->next = to_fix;
    to_fix = p;
    p->flags |= is_deleted;
    p->flags &= ~is_locked;
}

/* free deleted cells */
void
flush_saved(void)
{
    register struct ent *p;
    register struct ent *q;

    if (!(p = to_fix))
	return;
    while (p) {
	(void) clearent(p);
	q = p->next;
	p->next = freeents;	/* put this ent on the front of freeents */
	freeents = p;
	p = q;
    }
    to_fix = NULL;
}

char *progname;
static int arg = 1;
int running = TRUE;

static void
cell_delete (void)
{
    register struct ent **pp;
    register int c1;

    flush_saved();
    if (calc_order == BYROWS) {
	for (c1 = curcol; arg-- && c1 < maxcols; c1++) {
	    pp = ATBL(tbl, currow, c1);
	    if ((*pp) && !locked_cell(currow, curcol)) {
		if (*pp) {
		    free_ent(*pp);
		    *pp = NULL;
		}
	    }
	}
    } else {
	for (c1 = currow; arg-- && c1 < maxrows; c1++) {
	    pp = ATBL(tbl, c1, curcol);
	    if ((*pp) && !locked_cell(currow, curcol)) {
		if (*pp) {
		    free_ent(*pp);
		    *pp = NULL;
		}
	    }
	}
    }
    sync_refs();
    modflg++;
    FullUpdate++;
}

int
scmain(int argc, char **argv)
{
    int inloop = 1;
    register KeySym c;
    int edistate = -1;
    int narg;
    int nedistate;
    char *revi;

    /*
     * Keep command line options around until the file is read so the
     * command line overrides file options
     */

    int Mopt = 0;
    int Nopt = 0;
    int Copt = 0; 
    char **copyv = argv;
    int copyc = argc;

    srand((unsigned int) time(NULL));

    userfont = NULL;

    if ((revi = strrchr(argv[0], '/')) != NULL)
	progname = revi + 1;
    else
	progname = argv[0];

    while (argc > 1 && argv[1][0] == '-') {
	argv++;
	argc--;
    	switch (argv[0][1]) {
	case 'm':
	    Mopt = 1;
	    break;
	case 'n':
	    Nopt = 1;
	    break;
	case 'c':
	    Copt = 1;
	    break;
	case 'f':   /*  -fn font size */
	    if (argv[0][2] != 'n') goto ILLEGALOPTION; 
	    argv++;
	    argc--;
	    userfont = argv[0];
	    break;
	case 'C':
	    craction = CRCOLS;
	    break;
	case 'R':
	    craction = CRROWS;
	    break;
	case 'h':
#ifdef VR3
	    print_small_help();
#else
	    print_help();
#endif
	    exit(EXIT_SUCCESS);
	default:
	ILLEGALOPTION: 
	    (void) fprintf(stderr, "%s: unrecognized option: \"%c\"\n",
			   progname, argv[0][1]);
#ifdef VR3
	    print_small_help();
#else
	    print_help();
#endif
	    exit(EXIT_FAILURE);
	}
    }

    sc_Xinit(copyc, copyv);

    *curfile ='\0';

    graph_init(&baseplot);  /* initialize graphing parameters */

    signals();

    /* setup the spreadsheet arrays, initscr() will get the screen size */
    if (!growtbl(GROWNEW, 0, 0)) {
	exit(EXIT_FAILURE);
    }

    strcpy(revmsg, version);

    autocalc = Mopt ? 0 : 1;
    numeric = Nopt ? 0 : 1;
    calc_order = Copt ? BYCOLS : BYROWS;

    if (argc > 1) {	/* moved here by Peter Doemel, 25-Feb-1993 */
	(void) strcpy(curfile, argv[1]);
	readfile(argv[1], 0);
    }

    modflg = 0;
    FullUpdate++;

    while (inloop) { 
	running = TRUE;
	while (running) {
	    nedistate = -1;
	    narg = 1;
	    if (edistate < 0 && linelim < 0 && autocalc 
		&& (changed || FullUpdate)) {
	        EvalAll();
		if (changed) /* if EvalAll changed or was before */
		    anychanged = TRUE;
		changed = 0;
	    } else /* any cells change? */
		if (changed)
		    anychanged = TRUE;

	    update(anychanged);
	    anychanged = FALSE;

	    showneed = 0; /* reset after each update */
	    showexpr = 0;

	    if (!seenerr && !showhint) 
		clearlines(1, 1);

	    seenerr = 0;

	    c = nmgetch();
#ifdef DEBUG
	    fprintf(stderr, "topline_mode=%d, nmgetch got %ld\n", 
		    topline_mode, c);
#endif
	    if (!running) 
		break;

	    if (c == NoSymbol) continue;

	    if (isascii(c) && (iscntrl(c) || c == 020)) {
		switch (c) {
		case ctl('r'):
		    showneed = 1;
		case ctl('l'):
		    FullUpdate++;
		    ClearScreen++;
		    /* Centering the display with cursor for middle */
		    if(currow > (maintextrows - RESROW)/2)
			strow = currow - ((maintextrows - RESROW) / 2);
		    break;
		case ctl('x'):
		    FullUpdate++;
		    showexpr = 1;
		    break;
		case ctl('k'):
		    if (topline_mode == EDIT_MODE) write_line(c);
		    break;
		default:
		    sprintf(stringbuf, "No such command (^%c)", (int) c + 0100);
		    error(stringbuf);
		    break;
		case ctl('b'):
		    if (numeric_field) {
			write_line(ctl('m'));
			numeric_field = 0;
		    }
		    backcol(arg);
		    break;
		case ctl('c'):  /* mark cell for copy */
		    savedrow = currow;
		    savedcol = curcol;
		    sprintf(stringbuf, "%s%d marked for copy",
			    coltoa(curcol), currow);
		    error(stringbuf);
		    break;

		case ctl('e'):
		    if (topline_mode == EDIT_MODE) {
			write_line(c);
			break;
		    }
		    switch (nmgetch()) {
		    case NoSymbol: break;
		    case ctl('p'): case 'k': doend(-1, 0);	break;
		    case ctl('n'): case 'j': doend(1, 0);	break;
		    case ctl('b'): case 'h':
		    case ctl('h'):	     doend(0, -1);	break;
		    case ctl('f'): case 'l':
		    case ctl('i'): case ' ': doend(0, 1);	break;
		    case ESC:
		    case ctl('g'):
			break;
		    default:
			error("Invalid ^E command");
			break;
		    }
		    break;

		case ctl('f'):
		    if (numeric_field) {
			write_line(ctl('m'));
			numeric_field = 0;
		    }
		    forwcol(arg);
		    break;

		case ctl('g'):
		    if (topline_mode == EDIT_MODE) {
			write_line(c);
			break;
		    }
		    showrange = 0;
		    linelim = -1;
		    clearlines(1, 1);
		    focus = FOCUS_SHEET;
		    break;

		case ESC:	/* ctl('[') */
		    write_line(ESC);
		    break;

		case ctl('d'):
		    write_line(ctl('d'));
		    break;

		case DEL:
		    if (linelim < 0) 
			cell_delete();
		    else
			write_line(DEL);
		    break;

		case ctl('h'):
		    if (linelim < 0) {	/* not editing line */
			backcol(arg);	/* treat like ^B    */
			break;
		    }
		    write_line(ctl('h'));
		    break;

		case ctl('i'): 		/* tab */
		    if (linelim < 0) {	/* not editing line */
			forwcol(arg);
			break;
		    }
		    if (!showrange) {
			startshow();
		    } else {
			showdr();
			linelim = strlen(line);
			showrange = 0;
		    }
		    linelim = strlen(line);
		    break;

		case ctl('m'):
		case ctl('j'):
		    numeric_field = 0;
		    write_line(ctl('m'));
		    switch(craction) {
		    case CRCOLS:
			if ((rowlimit >= 0) && (currow >= rowlimit)) {
			    forwcol(1);
			    currow = 0;
			}
			else 
			    forwrow(1);
			break;
		    case CRROWS:
			if ((collimit >= 0) && (curcol >= collimit)) {
			    forwrow(1);
			    curcol = 0;
			}
			else 
			    forwcol(1);
			break;
		    default:
			break;
		    }
		    break;

		case ctl('n'):
		    if (numeric_field || focus == FOCUS_TOP) {
			write_line(ctl('m'));
			numeric_field = 0;
		    }
		    forwrow(arg);
		    break;

		case ctl('p'):
		    if (numeric_field || focus == FOCUS_TOP) {
			write_line(ctl('m'));
			numeric_field = 0;
		    }
		    backrow(arg);
		    break;

		case ctl('q'): 
		    diesave();
		    exit(EXIT_SUCCESS);
		    break;
		case ctl('s'):
		    diesave(); /* FIXME */
		    break; 

		case ctl('t'):
		    error("Toggles: a,c,e,g,i,n,$,r,z");
		    switch (nmgetch()) {
		    case NoSymbol: break;
		    case 'a': case 'A':
		    case 'm': case 'M':	/* Auto recalc */
			Option_Menu1(1); break;
		    case 'n': case 'N':	/* Numeric */
			Option_Menu1(2); break;
		    case 'g': case 'G':	/* Grid lines */
			Option_Menu2(6); break;
		    case '$':		/* Pre-scale */
			Option_Menu1(3); break;
		    case 'e': case 'E':	/* Ext-funcs */
			Option_Menu1(4); break;
		    case 'r': case 'R':	/* NL-action */
			Option_Menu2(1); break;
		    case 'z': case 'Z':	/* Row/Col-Limits */
			Option_Menu2(2); break;
		    case 'c': case 'C': /* Recalc by rows or cols */
			Option_Menu2(3); break;
		    case 'i': case 'I': /* Round to infinity */
			Option_Menu2(4); break;
		    default:
			error ("Invalid toggle command");
  				/* note fall thru */
		    case ESC:
		    case ctl('g'):
			--modflg; /* negate the modflg++ */
		    }
		    FullUpdate++;
		    modflg++;
		    break;

		case ctl('u'):
		    narg = arg * 4;
		    nedistate = 1;
		    break;

		case ctl('v'):	
		    if (linelim > 0) { /* insert cell value */
			struct ent *p = *ATBL(tbl, currow, curcol);
			char temp[100];

			if (p && p->flags & is_valid) {
			    (void) sprintf (temp, "%.*f",
					    precision[curcol],p->v);
			    ins_string(temp);
			}
		    }
		    else {            /* paste marked cell */
			register struct ent *p = *ATBL(tbl, savedrow, savedcol);
			register int c1;
			register struct ent *n;
			if (!p)
			    break;
			FullUpdate++;
			modflg++;
			for (c1 = curcol; arg-- && c1 < maxcols; c1++) {
			    n = lookat(currow, c1);
			    (void) clearent(n);
			    copyent(n, p, currow - savedrow, c1 - savedcol);
			}
		    }
		    break;

		case ctl('w'):	/* insert variable expression */
		    if (linelim > 0)  {
			static char *temp, *temp1;
			static unsigned templen;
			int templim;

			/* scxrealloc will scxmalloc if needed */
			if (strlen(line)+1 > templen) {
			    templen = strlen(line) + 40;
			    temp = scxrealloc(temp, templen);
			    temp1= scxrealloc(temp1, templen);
			}
			strcpy(temp, line);
			templim = linelim;
			linelim = 0;		/* reset line to empty	*/
			editexp(currow, curcol);
			strcpy(temp1, line);
			strcpy(line, temp);
			linelim = templim;
			ins_string(temp1);
		    }
		    break;

		case ctl('a'):
		    if (linelim > 0) write_line(c);
		    break;

		} /* End of the control char switch */
	    }
	    else if (isascii(c) && isdigit(c) && 
		     ((numeric && edistate >= 0) ||
		      (!numeric && (linelim < 0 || edistate >= 0)))) {
		/* we got a leading number */
		if (edistate != 0) {
		    /* First char of the count */
		    if (c == '0') {     /* just a '0' goes to left col */
			curcol = 0;
		    } else {
			nedistate = 0;
			narg = c - '0';
		    }
		} else {
		    /* Succeeding count chars */
		    nedistate = 0;
		    narg = arg * 10 + (c - '0');
		}
	    } else if (linelim >= 0) {
		/* Editing line */
		if (c == NoSymbol) continue;
		switch (c) {
		case ')':
		    if (showrange) {
			showdr();
			showrange = 0;
			linelim = strlen(line);
		    }
		    break;
		default:
		    break;
		}
		write_line(c);
		/* break; */
	    } else if (!numeric && (c == '+' || c == '-')) {
		/* increment/decrement ops */
		register struct ent *p = *ATBL(tbl, currow, curcol);

		if (!p)
		    continue;
		if (p->expr && !(p->flags & is_strexpr)) {
		    error("Can't increment/decrement a formula\n");
		    continue;
		}
		FullUpdate++;
		modflg++;
		if (c == '+')
		    p->v += (double) arg;
		else
		    p->v -= (double) arg;
	    } else {
		/* switch on a normal command character */
		switch (c) {
		case ':':
		    break;	/* Be nice to vi users */

		case '@':
		    EvalAll();
		    changed = 0;
		    anychanged = TRUE;
		    break;

		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		case '-': case '.': case '+':
		    if (locked_cell(currow, curcol))
			break;
		    numeric_field = 1;
		    (void) sprintf(line,"let %s = %c",  /* FIXME VR3? */
				   v_name(currow, curcol), (int) c);
		    linelim = strlen(line);
		    edit_mode();
		    break;

		case '=':
		    if (locked_cell(currow, curcol))
			break;
		    (void) sprintf(line,"let %s = ",
				   v_name(currow, curcol));
		    linelim = strlen(line);
		    edit_mode();
		    break;

		case '!': {
		    /*
		     *  "! command"  executes command
		     *  "!"	forks a shell
		     *  "!!" repeats last command
		     */
		    char *shl;
		    int pid, temp;
		    char cmd[MAXCMD];
		    static char lastcmd[MAXCMD];

		    if (!(shl = getenv("SHELL")))
			shl = "/bin/sh";

		    fputs("! ", stdout);
		    fflush(stdout);
		    fgets(cmd, MAXCMD, stdin);
		    cmd[strlen(cmd) - 1] = '\0';	/* clobber \n */
		    if(strcmp(cmd,"!") == 0)		/* repeat? */
			strcpy(cmd, lastcmd);
		    else
			strcpy(lastcmd, cmd);

		    if (modflg) {
			puts("[No write since last change]");
			fflush(stdout);
		    }

		    if (!(pid = fork())) {
			signal (SIGINT, SIG_DFL);  /* reset */
			if(strlen(cmd))
			    execl(shl, shl, "-c", cmd, NULL);
			else
			    execl(shl, shl, NULL);
			exit(-127);
		    }

		    while (pid != wait(&temp));

		    printf("Press RETURN to continue ");
		    fflush(stdout);
		    break;
		}

		/* Range commands: (not in manual) */
		case 'r':
		    error("Range: x:erase v:value c:copy f:fill d:def "
			  "r:remove s:show l:lock u:unlock");
		    switch (nmgetch()) {
		    case NoSymbol: break;
		    case 'x': Range_Menu(1); break;
		    case 'v': Range_Menu(2); break;
		    case 'c': Range_Menu(3); break;
		    case 'f': Range_Menu(4); break;
		    case 'd': Range_Menu(5); break;
		    case 'r': Range_Menu(6); break;
		    case 's': Range_Menu(7); break;
		    case 'l': Range_Menu(8); break;
		    case 'u': Range_Menu(9); break;
		    case ESC:
		    case ctl('g'):
			clearlines(1, 1);
			break;
		    default:
			error("Invalid region command");
			break;
		    }
		    break;

		/* Row/column commands */
		case 'i': Row_Col_Menu(1); break;	/* insert */
		case 'a': Row_Col_Menu(2); break;	/* append */
		case 'd': Row_Col_Menu(3); break;	/* delete */
		case 'p': Row_Col_Menu(4); break;	/* pull */
		case 'v': Row_Col_Menu(5); break;	/* valueize */
		case 'z': Row_Col_Menu(6); break;	/* hide */
		case 's': Row_Col_Menu(7); break;	/* show */

		case '$': {
		    register struct ent *p;

		    curcol = maxcols - 1;
		    while (!VALID_CELL(p, currow, curcol) && curcol > 0)
			curcol--;
		    break;
		}
		case '#': {
		    register struct ent *p;

		    currow = maxrows - 1;
		    while (!VALID_CELL(p, currow, curcol) && currow > 0)
			currow--;
		    break;
		}
		case 'w': {
		    register struct ent *p;

		    while (--arg>=0) {
			do {
			    if (curcol < maxcols - 1)
				curcol++;
			    else {
				if (currow < maxrows - 1) {
				    while(++currow < maxrows - 1 &&
					  row_hidden[currow]) /* */;
				    curcol = 0;
				} else {
				    error("At end of table");
				    break;
				}
			    }
			} while(col_hidden[curcol] ||
				!VALID_CELL(p, currow, curcol));
		    }
		    break;
		}
		case 'b': {
		    register struct ent *p;

		    while (--arg>=0) {
			do {
			    if (curcol) 
				curcol--;
			    else {
				if (currow) {
				    while(--currow &&
					  row_hidden[currow]) /* */;
				    curcol = maxcols - 1;
				} else {
				    error ("At start of table");
				    break;
				}
			    }
			} while(col_hidden[curcol] ||
				!VALID_CELL(p, currow, curcol));
		    }
		    break;
		}
		case '^':
		    currow = 0;
		    break;
#ifdef XK_Help
		case XK_Help:
#endif
		case '?':
		    help();
		    break;
		case '"':
		    if (!locked_cell(currow, curcol)) {
			struct ent *p = lookat(currow, curcol);

			(void) sprintf (line, "label %s = \"%s",
					v_name(currow, curcol),
					(p && p->label && p->label[0])? 
					p->label : "");
			linelim = strlen (line);
			edit_mode();
		    }
		    break;

		case '<':
		    if (!locked_cell(currow, curcol)) {
			struct ent *p = lookat(currow, curcol);

			(void) sprintf (line, "leftstring %s = \"%s",
					v_name(currow, curcol),
					(p && p->label && p->label[0])? 
					p->label : "");
			linelim = strlen(line);
			edit_mode();
		    }
		    break;

		case '>': 
		    if (!locked_cell(currow, curcol)) {
			struct ent *p = lookat(currow, curcol);

			(void) sprintf (line, "rightstring %s = \"%s",
					v_name(currow, curcol),
					(p && p->label && p->label[0])? 
					p->label : "");
			linelim = strlen(line);
			edit_mode();
		    }
		    break;
		case 'e':
		    if (!locked_cell(currow, curcol)) {
			/* conditional added 5/30/01 AC */
			struct ent *p = lookat(currow, curcol);

			if (p && p->label) edits(currow, curcol);
			else editv(currow, curcol);
			edit_mode(); 
		    }
		    break;
		case 'E':
		    if (!locked_cell(currow, curcol)) {
			edits(currow, curcol);
			edit_mode(); 
		    }
		    break;
		case 'f':
		    if (arg == 1) {
			(void) sprintf (line, "format [for column] %s ",
					coltoa(curcol));
		    } else {
			(void) sprintf(line, "format [for columns] %s:",
				       coltoa(curcol));
			(void) sprintf(line+strlen(line), "%s ",
				       coltoa(curcol+arg-1));
		    }
		    sprintf(stringbuf, "Current format is %d %d %d",
			    fwidth[curcol], precision[curcol],
			    realfmt[curcol]);
		    error(stringbuf);
		    linelim = strlen (line);
		    edit_mode();
		    break;
		case 'g':
		    (void) sprintf (line, "goto [v] ");
		    linelim = strlen (line);
		    edit_mode();
		    break;

		case 'O': File_Menu(1); break;	/* Open "file" */
		case 'S': File_Menu(2); break;	/* Save "file" */
		case 'X': File_Menu(3); break;	/* Export "file" range */
		case 'M': File_Menu(4); break;	/* Merge "file" */
		case 'R': File_Menu(5); break;	/* Set save range */

		case 'x': 
		    cell_delete();
		    break;
		case 'Q':
		case 'q':
		    running = FALSE;
		    break;
		case 'h':
		    backcol(arg);
		    break;
		case 'j':
		    forwrow(arg);
		    break;
		case 'k':
		    backrow(arg);
		    break;
		case 'H':
		    backcol((curcol-stcol+1)+1);
		    break;
		case XK_Next:
		case 'J':
		    forwrow(maintextrows - RESROW - (currow-strow) + 1);
		    break;
		case XK_Prior:
		case 'K':
		    backrow((currow-strow+1) + 3);
		    break;
		case XK_Home:
		    currow = 0;
		    curcol = 0;
		    FullUpdate++;
		    break;
		case 'L':
		    forwcol(lcols -(curcol-stcol)+1);
		    break;
		case ' ':
		case 'l':
		    forwcol(arg);
		    break;
		case 'm': /* mark cell for copy */
		    savedrow = currow;
		    savedcol = curcol;
		    sprintf(stringbuf, "%s%d marked for copy",
			    coltoa(curcol), currow);
		    error(stringbuf);
		    break;
		case 'c': {
		    register struct ent *p = *ATBL(tbl, savedrow, savedcol);
		    register int c1;
		    register struct ent *n;
		    if (!p)
			break;
		    FullUpdate++;
		    modflg++;
		    for (c1 = curcol; arg-- && c1 < maxcols; c1++) {
			n = lookat(currow, c1);
			(void) clearent(n);
			copyent(n, p, currow - savedrow, c1 - savedcol);
		    }
		    break;
		}
		case '/': Main_Menu(); break;
		default:
		    if ((toascii(c)) != c)
			sprintf(stringbuf, "Weird character, decimal %d",
				(int) c);
		    else
			sprintf(stringbuf, "No such command (%c)", (int) c);
		    error(stringbuf);
		    break;
		}
	    }
	    edistate = nedistate;
	    arg = narg;
	} /* while (running) */
	inloop = modcheck(" before exiting");
    } /*  while (inloop) */
    return 0;
    /*NOTREACHED*/
}

/* show the current range (see ^I), we are moving around to define a range */
static void
startshow(void)
{
    showrange = 1;
    showsr = currow;
    showsc = curcol;
}

/* insert the range we defined by moving around the screen, see startshow() */
void
showdr(void)
{
    int minsr, minsc, maxsr, maxsc;

    minsr = showsr < currow ? showsr : currow;
    minsc = showsc < curcol ? showsc : curcol;
    maxsr = showsr > currow ? showsr : currow;
    maxsc = showsc > curcol ? showsc : curcol;
    (void) sprintf(line+linelim, "%s", r_name(minsr, minsc, maxsr, maxsc));
}

/* set the calculation order */
void
setorder(int i)
{
    if (i == BYROWS || i == BYCOLS)
	calc_order = i;
}

void
setauto(int i)
{
    autocalc = i;
}

void
signals(void)
{
    sig_type doquit(int);
    sig_type dump_me(int);

    (void) signal(SIGINT, SIG_IGN);
    (void) signal(SIGQUIT, dump_me);
    (void) signal(SIGPIPE, doquit);
    (void) signal(SIGBUS, doquit);
    (void) signal(SIGTERM, doquit);
    (void) signal(SIGFPE, doquit);
}

sig_type
doquit(int arg)
{
    diesave();
    exit(EXIT_FAILURE);
}

sig_type
dump_me(int arg)
{
    diesave();
    abort();
}

/* try to save the current spreadsheet if we can */
void
diesave(void)
{   
    char path[PATHLEN];

    if (modcheck(" before Spreadsheet dies") == 1) {
     	(void) sprintf(path, "~/%s", SAVENAME);
	if (writefile(path, 0, 0, maxrow, maxcol) < 0) {
	    (void) sprintf(path, "/tmp/%s", SAVENAME);
	    if (writefile(path, 0, 0, maxrow, maxcol) < 0)
		error("Couldn't save current spreadsheet, Sorry");
	}
    }
}

/* check if tbl was modified and ask to save
 * returning 0 if the user wants to quit (don't keep running), or 1 if 
 * the program should keep running
 */
int
modcheck(char *endstr)
{
    int yn_ans;

    if (!modflg) return 0;

    if (curfile[0]) {
	char lin[100];

#ifdef VR3
	sprintf(lin, "Save '%s'?", curfile);
#else	
	sprintf(lin, "File \"%s\" is modified, save%s? ",
		curfile, endstr);
#endif
	if ((yn_ans = yn_ask(lin)) < 0 ||
	    (yn_ans == 1 && writefile(curfile, 0, 0, maxrow, maxcol) < 0))
	    return 1;
    } else {
	if ((yn_ans = yn_ask("Save the current data? ")) < 0)
	    return 1;
	else {
	    if (yn_ans == 1) File_Menu(2);
	    return yn_ans;
	}
    }
    return 0;
}

/* Returns 1 if cell is locked, 0 otherwise */
int
locked_cell (int r, int c)
{
    struct ent *p = *ATBL(tbl, r, c);

    if (p && (p->flags & is_locked)) {
	sprintf(stringbuf, "Cell %s%d is locked", coltoa(c), r);
	error(stringbuf);
	return(1);
    }
    return(0);
}

/* Check if area contains locked cells */
int
any_locked_cells(int r1, int c1, int r2, int c2)
{
    int r, c;
    struct ent *p ;

    for (r=r1; r<=r2; r++)
	for (c=c1; c<=c2; c++) {
	    p = *ATBL(tbl, r, c);
	    if (p && (p->flags & is_locked))
		return(1);
	}
    return 0;
}

/*===========================================================================
 *
 * The following functions implement the cursor style menu
 *
 *                                 by SWLin, 8/90
 */

#ifdef VR3
# define COLMAX 32
#else
# define COLMAX 1024
#endif

unsigned 
menu(unsigned item_no, char *item[], char *help_prompt[], int deflt)
{  
    int i, choice, done;
    int scroll = 0, scrollitem = 32, scrollcol;
    char c;
    int show_screen;
    int cursor_temp, choice_temp, TempX_Loc, col = 0;
    XEvent event;
    KeySym key;
    char buffer[8];

    /* column accounting for narrow screen on agenda */
    for (i=0; i<item_no; i++) {
	col += strlen(item[i]) + MENUSPACE;
	if (col > COLMAX) {
	    scrollcol = col - strlen(item[i]) - MENUSPACE ;
	    scrollitem = i;
	    break;
	}
    }

    choice = deflt;
    done = 0;
    show_screen = 1;

    clearlines(1, 1);
    i = 0;

    while (!done) {
	TempX_Loc = event.xbutton.x;
	if (show_screen) {
	    if (scroll == 0 || scroll == 2) i = 0;
	    else i = scrollitem - 1;
	    if (scroll) clearlines(1, 1);
	    if (scroll == 2) scroll = 0;
	    for (col=0; i<item_no; i++) {
		XDrawImageString(dpy, mainwin,
				 (i == choice-1) ? maingcreversed : maingc,
				 textcol(col), textrow(1),
				 item[i], strlen(item[i]));
		col += strlen(item[i]) + MENUSPACE;
	    }
	    clearlines(2, 2);
	    XDrawImageString(dpy, mainwin, maingc,
			     textcol(0), textrow(2),
			     help_prompt[choice - 1], 
			     strlen(help_prompt[choice - 1]));
	    show_screen = 0;
	}

	/*** HACK COURTESY OF MIKE ***/
	XNextEvent(dpy, &event);

#ifdef VR3 /* there's no MotionNotify on agenda */
	switch (event.type) {
	case ButtonPress:
	    if ((event.xbutton.y >= curfontheight + 1) && 
		(event.xbutton.y <= 2 * curfontheight + 2)) {
		choice_temp = 1;
		cursor_temp = (strlen(item[0]) + MENUSPACE) * curfontwidth;
		while (cursor_temp < event.xbutton.x) {
		    if (choice_temp < item_no) {
			cursor_temp += (strlen(item[choice_temp++])
					+ MENUSPACE) * curfontwidth;
		    } 
		}
		if (choice_temp <= item_no) {
		    choice = choice_temp;
		    if (scroll) choice += scrollitem - 1;
		    show_screen = done = 1;
		} /* if choice_temp is within bounds */
	    }
	    else if (event.xbutton.y > 2 * curfontheight + 2) {
		choice = 0;
		done = 1;
	    }
	    else 
		show_screen = done = 1;
	    break;
#else
	switch (event.type) {

        case MotionNotify:
	    if ((event.xbutton.y >= 10) && 
		 (event.xbutton.y <= 2 * curfontheight)) {
		choice_temp = 1;
		cursor_temp = ((strlen(item[0]) + MENUSPACE) * curfontwidth);
		while (cursor_temp < event.xbutton.x) {
		    if (choice_temp < item_no) {
			cursor_temp += ( (strlen(item[choice_temp++])
					  + MENUSPACE) * curfontwidth);
		    } else
			break;
		}

		if (choice_temp <= item_no) {
		    if (choice_temp != choice) {
			choice = choice_temp;
			show_screen = 1;
		    } /* end of if choice_temp */
		} /* only if choice_temp is within bounds */
	    }
	    break;

	case ButtonPress:
	    if (event.xbutton.y > 2 * curfontheight) {
		choice = 0;
		done = 1;
	    }
	    else /* Let the mouse select the exact choice */
		show_screen = done = 1;
	    break;
#endif /* VR3 */
	 
	case Expose:
	    FullUpdate++;
	    update(FALSE);
	    show_screen = 1;
	    break;

	case MappingNotify:
	    XRefreshKeyboardMapping(&(event.xmapping));
	    break;

	case ConfigureNotify:
	    sc_handleresize(&event);
	    break;

	    /***** NEEDS TO BE FIXED *****/

	case KeyPress:
	    if ((XLookupString (&(event.xkey), buffer, 8, &key, 0)) ||
		(IsCursorKey(key))) {
		show_screen = 1;
		if (!IsCursorKey(key)) {
		    c = buffer[0];

		    switch (c) {
		    case ctl('f'):
			/* case 'l': */
		    case 'L': 
			choice++;
			if (choice == item_no + 1)
			    choice = 1;
			break; 
		    case ctl ('b'):
		    case ' ':
		    case 'h':
		    case 'H':
			choice--;
			if (choice == 0)
			    choice = item_no;
			break;
		    case ctl('p'):
		    case 'k':
		    case 'K':
			choice = 1;
			break;
		    case ctl('n'):
		    case 'j':
		    case 'J':
			choice = item_no;
			break;
		    case '/':
		    case 27:
		    case ctl('g'):
			choice = 0;
			done = 1;
			break;
		    case 13:
		    case 10:
			done = 1;
			break;
		    default:
			for (i=0; i<item_no; i++) {
			    if ((c == *item[i]) || 
				((c > 91) && (c == *item[i] + 32))) {
				choice = i+1;
				done = 1;
				break;
			    }
			}
			if (!done) { 
			    XBell(dpy, 50);
			}     
			break;
		    } /* switch(c) */
		} /* if !IsCursorKey(key) */
		else switch (key) {
		case XK_Up:
		case XK_Page_Up:
		    choice = 1;
		    break;
		case XK_Down:
		case XK_Page_Down:
		    choice = item_no;
		    break;
		case XK_Left:
		    choice--;
		    if (choice - 1 < scrollitem) {
			scroll = 2;
		    }		    
		    if (choice == 0)
			choice = item_no;
		    break;
		case XK_Right:
		    choice++;
		    if (choice - 1 == scrollitem) {
			scroll = 1;
		    }
		    if (choice == item_no + 1) /* wrap */
			choice = 1;
		    break; 
		}
		break;
	    } /* if XLookupString(..) */
	} /* switch (event.type) */
    } /* while (!done) */
    clearlines(1, 2);
    return choice;
}

/*
 *============================================================================
 */

static void
Range_Menu(int opt)
{   
    int	doneok;

#ifdef VR3
    static char *item[] = { 
	"Erase",
	"Vals",
	"Copy",
	"Fill",
	"Def",
	"Remove",
	"Show",
	"Lock",
	"Unlock"
    };

    static char *help_prompt[] = {
	"Erase data in a range", 
	"Convert formulas to values",
	"Copy src range to dest range",
	"Fill range with values",
	"Assign name to a cell or range",
	"Undefine previously def'd range",
	"Show defined range names",
	"Lock a range (disallow input)",
	"Unlock a range (allow input)"
    };
#else
    static char *item[] = { 
	"Erase",
	"Values",
	"Copy",
	"Fill",
	"Define",
	"Remove",
	"Show",
	"Lock",
	"Unlock"
    };

    static char *help_prompt[] = {
	"Erase data in a range", 
	"Substitute value for formulas in range",
	"Copy source range to destination range",
	"Fill range with predefined values",
	"Assign name to a cell or range of cells",
	"Undefine a previously defined range name",
	"Show currently defined range names",
	"Lock a range of cells (disallow input)",
	"Unlock a range of cells (allow input)"
    };
#endif

    doneok = FALSE;
    switch (opt >= 0 ? opt : menu(9, item, help_prompt, 1)) {
    case 0:
	if (opt < 0)
	    Main_Menu();
	break;
    case 1: /* Erase */
	prompt("erase ", "[range]");
	doneok = TRUE;
	break;
    case 2: /* Value */
	prompt("valueize ", "[range]");
	doneok = TRUE;
	break;
    case 3: /* Copy */
	prompt("copy ", "[src_range dest_range]");
	doneok = TRUE;
	break;
    case 4: /* Fill */
	prompt("fill ", "[range start inc]");
	doneok = TRUE;
	break;
    case 5: /* Define */
	prompt("define \"", "[string range]");
	doneok = TRUE;
	modflg++;
	break;
    case 6: /* Undefine */
	prompt("undefine ", "[range]");
	doneok = TRUE;
	break;
    case 7: /* Show */
	if (are_ranges()) 
	    x_list_range();
	else
	    error("No ranges defined");
	break;
    case 8: /* Lock */
	prompt("lock ", "[range]");
	doneok = TRUE;
	break;
    case 9: /* Unlock */
	prompt("unlock ", "[range]");	
	doneok = TRUE;
	break;
    default:
	error("Invalid region command");
	break;
    }

    if (doneok)	{ /* wrote something to edit */
	linelim = strlen(line);
	/* startshow(); */ /* commented out in 3.1 */
	edit_mode();
	show_top_line();
    }
}

static void
Row_Col_Menu(int opt)
{
    static char *item[] = { 
	"Insert",
	"Append",
	"Delete", 
	"Pull", 
	"Values", 
	"Hide", 
	"Show",
	"Format"
    };

    static char *help_prompt[] = {
	"Insert empty row (column)",
	"Copy/paste current row (column)",
	"Delete the current row (column)",
	"Pull back deleted cells",
	"Substitute values for formulas",
	"Hide the current row (column)",
	"Show hidden rows (columns)",
	"Set output format"
    };

    static char *item_1[] = {"Column", "Row"};

    static char *help_promt_1[] = {"Act on column",
				   "Act on row"};

    switch (opt >= 0 ? opt : menu(8, item, help_prompt, 1)) {

    case 0: 
	if (opt < 0)
	    Main_Menu();
	break;

    case 1: /* Insert */
	switch (menu(2, item_1, help_promt_1, 1)) {
	case 0: Row_Col_Menu(-1);  break;
	case 1: opencol(curcol, arg); break;
	case 2: insertrow(arg); break;
	}
	break;

    case 2: /* Append */
	switch (menu(2, item_1, help_promt_1, 1)) {
	case 0:	Row_Col_Menu(-1);  break;
	case 1: while (arg--) dupcol(); break;
	case 2: while (arg--) duprow(); break;
	}
	break;

    case 3: /* Delete */
	switch (menu(2, item_1, help_promt_1, 1)) {
	case 0: Row_Col_Menu(-1);  break;
	case 1: closecol(curcol, arg); break;
	case 2: deleterow(arg); break;
	}
	break;

    case 4: /* Pull */
	switch (menu(2, item_1, help_promt_1, 1)) {
	case 0: Row_Col_Menu(-1);  break;
	case 1: while (arg--)
	    pullcells('c');
	break;
	case 2: while (arg--)
	    pullcells('r');
	break;
	}
	break;

    case 5: /*
	     * turn an area starting at currow/curcol into
	     * constants vs expressions - not reversible
	     */
	switch (menu(2, item_1, help_promt_1, 1)) { 
	case 0: Row_Col_Menu(-1);  break;
	case 1: valueize_area(0, curcol, maxrow, curcol + arg - 1);
	    modflg = 1;
	    break;
	case 2:	valueize_area(currow, 0, currow + arg - 1, maxcol);
	    modflg = 1;
	    break;
	}
	break;

    case 6: /* Hide */
	switch (menu(2, item_1, help_promt_1, 1)) {
	case 0: Row_Col_Menu(-1);  break;
	case 1: hidecol (arg); break;
	case 2: hiderow (arg); break;
	}
	modflg++;
	break;

    case 7:   /* Show: special case; no repeat count */
	switch (menu(2, item_1, help_promt_1, 1)) {
	case 0: Row_Col_Menu(-1);  break;
	case 1: colshow_op(); break;
	case 2: rowshow_op(); break;
	}
	break;
    case 8:   /* Format */
	if (arg == 1)
	    (void) sprintf(line, "format [for column] %s ",
			   coltoa(curcol));
	else {
	    (void) sprintf(line, "format [for columns] %s:",
			   coltoa(curcol));
	    (void) sprintf(line + strlen(line), "%s ",
			   coltoa(curcol+arg-1));
	}
	sprintf(stringbuf, "Current format is %d %d",
		fwidth[curcol], precision[curcol]);
	clearlines(1, 1);
	XDrawImageString(dpy, mainwin, maingc,
			 textcol(0), textrow(1),
			 stringbuf, strlen(stringbuf));
	XFlush(dpy);

	seenerr = 1;
	linelim = strlen(line);
	break;
    }
}

static void
Option_Menu1(int opt)
{
    int	doneok;
    static char *item[] = {
	"Auto",
	"Numeric",
	"PreScale",
	"Ext",
	"More..."
    };

    static char *help_prompt[] = {
	"Recalc: auto or on `@' command",
	"Digit starts a numeric value",  
	"Numbers are multiplied by 0.01",
	"External funcs enable/disable",
	"More toggle options..."
    };

    doneok = FALSE;
    switch (opt >= 0 ? opt : menu(5, item, help_prompt, 1)) {
    case 0:
	if (opt < 0)
	    Main_Menu();
	break; 
    case 1:
	autocalc = (!autocalc);
	sprintf(stringbuf, "Automatic recalculation %sabled",
		autocalc ? "en":"dis"); 
	error(stringbuf);
	doneok = TRUE;
	break;
    case 2:
	numeric = (!numeric);
	sprintf(stringbuf,"Quick numeric input %sabled",
		numeric ? "en" : "dis");
	error(stringbuf);
	doneok = TRUE;
	break;
    case 3:
	if (prescale == 1.0) {
	    error ("PreScale enabled");
	    prescale = 0.01;
	} else {
	    prescale = 1.0;
	    error ("PreScale disabled");
	}
	doneok = TRUE;
	break;
    case 4: 
	extfunc = (! extfunc);
	sprintf(stringbuf,"External functions %sabled",
		extfunc? "en" : "dis");
	error(stringbuf);
	doneok = TRUE;
	break;
    case 5:
	Option_Menu2(-1);
	break;
    }
    if (doneok) {
	FullUpdate++;
	modflg++;
    }
}

static void
Option_Menu2(int opt)
{
    int	doneok;
#ifdef VR3
    static char *item[] = {
	"NL",
	"Limit",
	"Recalc",
	"Up",
	"Iters",
	"Grid"
    };
    static char *help_prompt[] = {
	"Newline action (direction)",
	"Set cell as limit for NL action",
	"Recalculate by row or column",
	"Round .5 up (vs to nearest even)",
	"Number of iterations on recalc.",
	"Grid lines show/hide"
    };
#else
    static char *item[] = {
	"NL-action",
	"Col/Row-Limits",
	"Recalc",
	"Up",
	"Iterations",
	"Grid lines"
    };
    static char *help_prompt[] = {
	"Newline action (direction)",
	"Set current cell as limit for NL action",
	"Recalculate by row or by column",
	"Always round .5 up (versus to nearest even)",
	"Number of iterations on recalculate",
	"Worksheet grid lines show/hide"
    };
#endif

    doneok = FALSE;
    switch (opt >= 0 ? opt : menu(6, item, help_prompt, 1)) {
    case 0:
	if (opt < 0)
	    Main_Menu();
	break; 
    case 1:
	++craction;
	if (craction >= 3)
	    craction = 0;
	switch(craction) {
	case CRCOLS:
	    error("Down row after newline");
	    break;
	case CRROWS:
	    error("Right column after newline");
	    break;
	default:
	    craction = 0; /* fall through */
	case 0:
	    error("No action after newline");
	    break;
	}
	doneok = TRUE;
	break;
    case 2:
	rowlimit = currow;
	collimit = curcol;
	error("Row and column limits set");
	doneok = TRUE;
	break;
    case 3:
	if (calc_order == BYROWS) {
	    calc_order = BYCOLS;
	    error("Recalculation is now by cols");
	} else {
	    calc_order = BYROWS;
	    error("Recalculation is now by rows");
	}
	break;
    case 4:
	rndinfinity = !(rndinfinity);
	if (rndinfinity)
	    error(".5 now gets rounded up");
	else
	    error(".5 now rounded to nearest even");
	break;
    case 5:
	sprintf (line, "set iterations=");
#ifdef VR3
	error("# of iterations on recalculation");
#else
	error("Number of iterations on recalculation");
#endif
	linelim = strlen (line);
	break;
    case 6:
	showgrid = !showgrid;
	doneok = TRUE;
	break;
    }

    if (doneok) {
	FullUpdate++;
	modflg++;
    }
}

static void
Export_Menu(void)
{
    static char *item[] = {
	"Screen",
	"CSV",
	"LaTeX",
	"Tbl"
    };
    static char *help_prompt[] = {
	"Plain text, as shown on screen",
	"Comma Separated Values",
	"LaTeX tabular environment",
	"For the tbl processor (troff)"
    };
    char suffix[5], fname[PATHLEN], *deftfile = NULL;

    switch (menu(4, item, help_prompt, 1)) {
    case 0:
	Main_Menu();
	return;
    case 1: /* plain text */
	tbl_style = 0;
	strcpy(suffix, ".txt");
	break;
    case 2:
	tbl_style = CSV;
	strcpy(suffix, ".csv");
	break;
    case 3:
	tbl_style = LATEX;
	strcpy(suffix, ".tex");
	break;
    case 4:
	tbl_style = TBL;
	strcpy(suffix, ".tbl");
	break;
    }

    if (*curfile) 
	deftfile = fsuffix(curfile, suffix);
    if (get_filename("Export file", NULL, fname, deftfile)) {
	if (save_range_set)
	    tblprintfile(fname, save_range.sr, save_range.sc,
			 save_range.er, save_range.ec);
	else
	    tblprintfile(fname, 0, 0, maxrow, maxcol);
    }
    if (deftfile != NULL) 
	scxfree(deftfile);
}  

extern struct m_range *findrge(char *s);

static void
File_Menu(int opt)
{
    static char *item[] = {
	"Open",
	"Save",
	"Export",
	"Merge",
	"Range"
    };
    static char *help_prompt[] = {
	"Open worksheet file",
	"Save current sheet to file",
	"Export data, various formats",
	"Merge data from file",
	"Set range for Save, Export"
    };
    char fname[PATHLEN], *start = NULL;

    switch (opt >= 0 ? opt : menu(5, item, help_prompt, 1)) {
    case 0:
	if (opt < 0)
	    Main_Menu();
	break;
    case 1: 
	if (get_filename("Open file", "*.xsw", fname, NULL))
	    readfile(fname, 1);
	break;
    case 2:
	if (*curfile) 
	    start = curfile;
	if (get_filename("Save file", "*.xsw", fname, start)) 
	    writefile(fname, 0, 0, maxrow, maxcol);
	break;
    case 3: 
	Export_Menu();
	break;
    case 4:
	if (get_filename("Merge file", "*", fname, NULL)) 
	    readfile(fname, 0);
	break;
    case 5: 
	{
	char s[100];
	struct m_range *rge;

	strcpy(s, "range for save/export:");
	get_str(s, TSSIZE, NULL);
	rge = findrge(s);
	if (rge == NULL) 
	    error("Input syntax error");
	else {
	    save_range_set = 1;
	    save_range.sr = rge->sr;
	    save_range.er = rge->er;
	    save_range.sc = rge->sc;
	    save_range.ec = rge->ec;
	    scxfree(rge);
	    error("Save/Export range set");
	}
	break;
	}
    }
}

void Matrix_Menu(void)
{   
    int	doneok;

#ifdef VR3
    static char *item[] = {
	"Transpose",
	"Add",
	"Subtract",
	"Multiply",
	"Invert"
    };
#else
    static char *item[] = {
	"Transpose",
	"Addition",
	"Subtraction",
	"Multiplication",
	"Invert"
    };
#endif
    static char *help_prompt[] = {
	"Transpose the matrix",
	"Add two matrices",
	"Subtract matrix 2 from matrix 1",
	"Multiply matrix 1 into matrix 2",
	"Invert the matrix"
    };

    doneok = FALSE;
    switch (menu(5, item, help_prompt, 1)) {
    case 0:
	Main_Menu();
	break;
    case 1:
	get_trans_invert(MATRIX_TRANS);
	break;
    case 2:
	get_add_sub(MATRIX_ADD);
	break;
    case 3:
	get_add_sub(MATRIX_SUB);
	break;
    case 4:
	get_mult();
	break;
    case 5:
	get_trans_invert(MATRIX_INV);
	break;
    default:
	error("Invalid region command");
	break;
    }
}

void
Main_Menu()
{
#ifdef VR3
    static char *item[] = {
	"Range",
	"Col/Row",
	"Opt",
	"File",
	"Graph",
	"Matrix",
	"Linreg",
	"Quit"
    };

    static char *help_prompt[] = {
	"Various operations on ranges",
	"Various actions on column or row",
	"Toggle values of options",
	"Open Save Export Merge Range",
	"Type Ranges View Export Options",
	"Transpose Add Subtract Multiply Invert",
	"Simple regression",
	"Quit xspread"
    };
#else    
    static char *item[] = {
	"Range",
	"Column/Row",
	"Option",
	"File",
	"Graph",
	"Matrix",
	"Linreg",
	"Quit"
    };

    static char *help_prompt[] = {
	"Erase Value Copy Fill Define Show Remove Lock Unlock",
	"Insert Append Delete Pull Values Hide Show Format",
	"Auto Numeric PreScale Ext More",
	"Open Save Export Merge Range",
	"Type X A B C D Reset View Export Options",
	"Transpose Addition Subtraction Multiplication Invert",
	"Simple linear regression",
	"Quit xspread"
    };
#endif

    switch (menu(8, item, help_prompt, 1)) {
    case 0:
	show_top_line();
	break;
    case 1:
	Range_Menu(-1);
	break;
    case 2:
	Row_Col_Menu(-1);
	break;
    case 3:
	Option_Menu1(-1);
	break;
    case 4:
	File_Menu(-1);
	break;
    case 5:
	Graph_Menu(&baseplot);
	break;
    case 6:
	Matrix_Menu();
	break;
    case 7:
	get_regress();
	break;
    case 8:
	running = FALSE;
	break;
    }
}

static void
prompt(const char *pstr, const char *hint)
{
    (void) sprintf(line, "%s", pstr); 
    if (hint != NULL) {
	error(hint);
	showhint = 1;
    }
}


