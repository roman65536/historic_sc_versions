/*
 * Help functions for sc 
 * Allin Cottrell 2001
 * R. Bond, 1988
 * J. Buhrt 1990
 * $Revision: 1.23 $
 */

#include "config.h"

#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "sc.h"
#include "scXstuff.h"

static char *intro[] = {
    "A: This overview",
    "B: Toggle Options",
    "C: Cursor movement commands",
    "D: Cell entry and editing",
#ifdef USE_VI_MODE
    "E: Line Editor",
#else
    "E: Line Editor (disabled)",
#endif
    "F: File commands",
    "G: Row and column commands",
    "H: Range commands",
    "I: Miscellaneous commands",
    "J: Variable names/Expressions",
    "K: Range functions",
    "L: Numeric functions",
    "M: String functions",
    "N: Financial functions",
    "O: Time and date functions",
    "P: Statistical functions",
    " ",
    "Q: Quit help",
    NULL
};

static char *toggleoptions[] = {
    "B: Toggle Options",
    "^T Toggle options. Toggle one",
    " option selected by letter:",
    "a Recalculate automatically or ",
    "  on '@' commands.",
    "c Recalc by rows or by columns",
    "e External function execution",
    "g Show/hide worksheet grid lines",
    "i Round .5 up or to even",
    "n Digit starts a numeric value",
    "$ Prescale: numeric constants",
    "  are multiplied by 0.01.",
    "r Newline action.  Toggle among ",
    "  no action, go down, go right",
    "z Set newline action limits to ",
    "  current row and column",
    NULL
};

static char *cursor[] = {
    "C: Cell cursor motion",
    "^N ^P ^B ^F ",
    "    Down, up, back, forward",
    "^Ed End of range.  Follow ^E",
    "    by a direction indicator",
    "    such as ^P or j.",
    " ",
    "If no prompt active:",
    "j,k,l,h Down, up, right, left",
    "J,K,L,H Down, up, right, left"
    "        by 1/2 pages",
    "SPACE Forward",
    "^H Back",
    "TAB Forward, otherwise starts/",
    "    ends a range",
    "^ To row 0 of current col",
    "# To last row of current col",
    "0 To column A.  Preface with ^U",
    "  if in numeric mode",
    "$ To last column of current row",
    "b Back, up to previous cell",
    "w Forward, down to next cell",
    "g Go to: Cell name, range name",
    "  quoted string, number, 'error'",
    "  or 'invalid' to specify cell",
    NULL
};

static char *cell[] = {
    "D: Cell entry, editing:",
    "= Enter numeric constant or ",
    "  expression.",
    "< Enter left justified string ",
    "  or string expression",
    "\" Enter centered label",
    "> Enter right justified string",
    "  or string expression",
    "e Edit cell's numeric value",
    "E Edit cell's string part",
    "x Clear the current cell",
    "c Copy the last marked cell to",
    "  current cell",
    "m Mark cell to be used as source",
    "  for 'c'",
    "+ Increment numeric part",
    "- Decrement numeric part",
    "RETURN Enter insert mode if ",
    "  input line empty",
    "(ESC to edit)",
    " ",
    "        SPACE for more",
    NULL
};

static char *cell_more[] = {
    "D: Cell entry (contd):",
    " ",
    "In numeric mode, decimal digit,",
    "'+', '-', and '.' all start a",
    "numeric constant or expression",
    NULL
};

#ifdef USE_VI_MODE
static char *vi[] = {
    "E: Line Editor",
    "ESC while entering any command",
    "on the top line starts a one-",
    "line vi-style editor.",
    " ",
    "ESC q Abort command entry",
    "h l Cursor forward, backward",
    "0 $ Cursor to start, end of line",
    "b w Cursor forward/back one word",
    "fc  Move cursor to character c",
    "tc  Move cursor to char before c",
    "D   Delete to end of line",
    "i a Enter insert mode before/",
    "    after the cursor.",
    "I A Move to column 0/end of line",
    "    and enter insert mode.",
    "x X Del char under/before cursor",
    "rc Repl char under cursor with c",
    "cm Change - m = b,f,h,l,t or w",
    "dm Delete - m = b,f,h,l,t or w",
    "R  Replace (overstrike) mode",
    " ",
    "        SPACE for more",
    NULL
};
#else
char *vi[] = {
    "E: Line Editor",
    " ",
    "This version of xspread was com-",
    "piled without support for the",
    "vi-style line editor.  If you ",
    "want to use this feature, get",
    "the xspread source code from ",
    "www.ecn.wfu.edu/~cottrell/agenda",
    "and compile the program with",
    "USE_VI_MODE defined.",
    NULL
};
#endif /* USE_VI_MODE */

static char *vi_more[] = {
    "E: Line Editor (contd)",
    " ",
    "+ j - k / Forward/backward ",
    "   search the command history",
    "n  Repeat last history search",
    ". u Repeat/undo the last command",
    "<RETURN> Save",
    NULL
};

static char *file[] = {
    "F: File commands:",
    "O Open a worksheet file",
    "S Save the current sheet to file",
    "E Export the data.  A submenu", 
    "  gives a choice of formats",
    "M Merge file into current sheet",
    "R Set range for Save/Export",
    "",
    "'\"| program\"' for filename",
    "pipes output to a program for",
    "Save and Export.  If a cell",
    "name is given as the filename",
    "the cell's string part is used",
    "as the file name.",
    NULL
};

static char *row[] = {
    "G: Row/column commands:",
    "ir, ic Insert an empty row (col)",
    "ar, ac Append copy of row (col)",
    "dr, dc Delete current row (col)",
    "pr, pc, pm  Pull deleted cells ",
    "  back into the sheet: insert",
    "  rows, cols or merge cells",
    "vr, vc Remove expressions from",
    "  the given rows or columns,",
    "  leaving only the values.",
    "zr, zc Hide current row (column)",
    "sr, sc Show hidden rows (cols)",
    "f Set format for cell values in",
    "  this column. Give field width,"
    "  number of significant digits ",
    "  and format (0: fixed point, 1:",
    "  scientific, 2: engineering).",
    "  A preceding count can be used",
    "  to change more than one column.",
    " ",
    "        SPACE for more",
    NULL
};

static char *row_more[] = {
    "G: Row/column (contd):",
    " ",
    "Moving or copying cells modifies",
    "row and column references. Use",
    "'fixed' or '$' cell refs to",
    "suppress thes changes",
    " ",
    "@myrow, @mycol return the row or",
    "column of the current cell",
    NULL
};

static char *range[] = {
    "H: Range commands:",
    "/x Clear range",
    "/v Remove expressions from range",
    "   leaving just values",
    "/c Copy source range to dest",
    "/f Fill range, starting with a",
    "   given value and increasing by",
    "   a given increment",
    "/d Assign a name to a cell or",
    "   range. Give the name, quoted,",
    "   and a cell name e.g. 'A10' or",
    "   range such as 'a1:b20'",
    "/l Lock a cell or range, i.e.",
    "   make it unchangeable",
    "/U Unlock a locked cell",
    "/s Show currently defined range",
    "   names.  Pipe output to sort",
    "   then to pager",
    "/u Undefine a previously defined",
    "   range name",
    " ",
    "        SPACE for more",
    NULL
};

static char *range_more[] = {
    "H: Range (contd):",
    " ",
    "Range operations affect a ",
    "rectangular region defined by",
    "the top left and bottom right",
    "cells, e.g. 'a20:k52'.  Ranges",
    "may be referred to using names",
    "defined using '/d'.",
    NULL
};

static char *misc[] = {
    "I: Miscellaneous:",
    "Q q ^C Exit from the program",
    "^G ESC Abort entry of current",
    "       command.",
    "? Help",
    "! Shell escape. Enter a command",
    "  to run. '!!' repeats last",
    "  command.  Just '!' starts",
    "  interactive shell.",
    "^L Redraw screen",
    "^R Redraw screen: hilight cells",
    "   with values but no expression",
    "^X Redraw screen: show formulas,",
    "   not values",
    "@  Recalculate the spreadsheet",
    "^V Put this cell's numeric value",
    "^W Put active cell's expression",
    "TAB When the character cursor ",
    "   is on the top line TAB can be",
    "   used to start/stop choice of",
    "   a default range",
    NULL
};

static char *var[] = {
    "J: Variable names:",
    "K20   Row, column vary on copy",
    "$K$20 Row, column fixed on copy",
    "$K20  Column held fixed on copy",
    "K$20  Row held fixed on copy",
    "fixed holds following expression",
    "fixed on copies",
    "Cells and ranges can be given a",
    "symbolic name via '/d'.",
    " ",
    "Operators:",
    "-e Negation, e-e Subtraction",
    "e+e Addition, e*e Multiplication",
    "e/e Division, e%e Modulo",
    "e^e Exponentiation",
    "e=e Equal, e!=e Not Equal",
    "e>e Greater than, e<e Less than",
    "e>=e, e<=e Greater/Less or equal",
    "~e, e&e, e|e Boolean NOT AND OR",
    "e?e1:e2 or @if(e,e1,e2)",
    "   If e != 0 then e1, else e2",
    "Terms may be constants, var-",
    "iables, and parenthesized ",
    "expressions.",
    NULL
};

static char *rangef[] = {
    "K: Range functions:",
    "@sum(r) Sum of cell values",
    "@prod(r) Product of cell values",
    "@avg(r) Average of cells values",
    "@count(r) Count of valid cells",
    "@max(r) Maximum value in range",
    "@min(r) Minimum value in range",
    "@stddev(r)",
    "  Sample standard deviation",
    "@index(e,r) @stindex(e,r)",
    "  Numeric (string) value of cell",
    "  at index e into range r",
    "@lookup(e,r) @hlookup(e,r,n)",
    "@vlookup(e,r,n)",
    "  Search range r for value",
    "matching e. For numeric e, the",
    "last value <= e matches; for"
    "string, an exact match is re-",
    "quired. @lookup searches one row",
    "(column) and returns the value",
    "from the next column (row)",
    "@hlookup (@vlookup) searches the",
    "first row (column) in r and re-",
    "turns the value n columns (rows)",
    "from the match.",
    NULL
};

static char *numericf[] = {
    "L: Numeric functions:",
    " ",
    "@atan2(e1,e2)",
    " Arc tangent of e1/e2",
    "@ceil(e)",
    " Smallest integer >= e",
    "@eqs(se1,se2)",
    " 1 if string expr se1 has same",
    " value as se2, else 0",
    "@exp(e)",
    " Exponential function of e",
    "@abs(e) @fabs(e)",
    " Absolute value of e",
    "@floor(e)",
    " Largest integer <= e",
    "@hypot(x,y)",
    " Sqrt(x*x+y*y)",
    "@max(e1,e2,...)",
    " Maximum of values of the e's",
    "@min(e1,e2,...)",
    " Minimum of values of the e's",
    " ",
    "       SPACE for more",
    NULL,
};

static char *numericf_more[] = {
    "L: Numeric (contd):",
    " ",
    "@nval(se,e)",
    " Numeric value of a named cell",
    "pi @pi",
    " A constant quite close to pi",
    "@pow(e1,e2)",
    " e1 raised to the power of e2",
    "@rnd(e)",
    " Round e to nearest integer",
    "@round(e,n)",
    " Round e to n decimal places",
    "@sqrt(e) Square root of e",
    "@ston(se)",
    " Convert string se to numeric",
    "@ln(e) @log(e) @log2(e)",
    " Natural/base 10/base2 log of e",
    "@dtr(e) @rtd(e)",
    " Convert degrees to/from radians",
    "@cos(e) @sin(e) @tan(e)",
    " Trig functions, radian arguments",
    "@asin(e) @acos(e) @atan(e)",
    " Inverse trig functions",
    NULL
};

static char *stringf[] = {
    "M: String functions:",
    "# Concatenate strings",
    " E.g., 'A0 # \"azy dog\"' yields",
    " 'the lazy dog' if A0 is 'the l'",
    "@substr(se,e1,e2)",
    " Extract characters e1 through",
    " e2 from string expression se.",
    " '@substr(\"Nice jacket\" 4, 7)'",
    " yields 'e ja'",
    "@fmt(se,e)",
    " Convert number to string using",
    " sprintf.  E.g.", 
    " '@fmt(\"*%6.3f*\",10.5)' yields",
    " '*10.500*'.  Formats are e, E,",
    " f, g, and G.", 
    "@sval(se,e)",
    " Return string value of cell ",
    " selected by name",
    " ",
    "        SPACE for more",
    NULL
};

static char *stringf_more[] = {
    "M: String funcs (contd):",
    "@ext(se,e)",
    " Call an external function",
    " (program or script). Convert",
    " e to string and append it to",
    " the command line as an",
    " argument. @ext yields a string:",
    " the first line printed to",
    " stdout by the command.",
    "@coltoa(e)",
    " Return the column letter(s)",
    " from the passed number",
    "@upper(s) @lower(s)",
    " Return s in upper/lower case",
    "@capital(s)",
    " Return capitalized string",
    " ",
    "String expressions are made up",
    "of constant strings (characters",
    "surrounded by quotes), variables",
    "and string functions.",
    NULL
};

static char *finf[] = {
    "N: Financial functions:",
    " ",
    "@pmt(e1,e2,e3)",
    " @pmt(60000,.01,360) computes",
    " the monthly payments for a",
    " $60000 mortgage at 12% annual",
    " interest (.01 per month) for 30",
    " years (360 months)",
    " ",		
    "@fv(e1,e2,e3)",
    " @fv(100,.005,36) computes the",
    " future value of 36 monthly pay-",
    " ments of $100 at 6% interest",
    " (.005 per month).  Answers the",
    " question: 'How much will I have",
    " in 36 months if I deposit $100",
    " per month in a savings account",
    " paying 6% interest compounded",
    " monthly?'",
    " ",
    "        SPACE for more",
    NULL
};

static char *finf_more[] = {
    "N: Financial (contd):",
    " ",
    "@pv(e1,e2,e3)",
    " @pv(1000,.015,36) computes the ",
    " present value of an ordinary ",
    " annuity of 36 monthly payments",
    " of $1000 at 18% annual interest.",
    " Answers the question: 'How much",
    " can I borrow at 18% for 3 years",
    " if I pay $1000 per month?'",
    " ",
    "@irr(range)",
    " @irr(A1:A9) computes the inter-",
    " nal rate of return on cash flow",
    " in range, where the first cell",
    " is the negative of the initial",
    " investment",
    NULL
};

static char *timef[] = {
    "O: Time/date functions:",
    "@now",
    " Time in seconds since 1970",
    "@dts(m,d,y)",
    " m/d/y, given in secs since 1970",
    "@tts(h,m,s)",
    " h:m:s, in secs since midnight",
    " ",
    "The following take an argument",
    "expressed in seconds:",
    " ",
    "@date(e)",
    " 24-char date string of form:",
    " 'Sun Sep 16 01:03:52 1973'",
    " @substr can be used to extact",
    " pieces of the string"
    "@year(e)",
    " Return the year (starting 1970)",
    "@month(e)",
    " Return the month,  1 to 12",
    "@day(e)",
    " Day of the month, 1 to 31",
    " ",
    "        SPACE for more",
    NULL
};

static char *timef_more[] = {
    "O: Time/date (contd):",
    " ",
    "The following take an argument",
    "expressed in seconds:",
    " ",
    "@hour(e)",
    " Hours since midnight, 0 to 23",
    "@minute(e)",
    " Minutes since last full hour,",
    " 0 to 59",
    "@second(e)",
    " Seconds since last full minute,",
    " 0 to 59",
    NULL
};

static char *statf[] = {
    "P: Statistical functions:",
    "@avg(range)",
    " Average of cell values",
    "@count(range)",
    " Count of valid cells",
    "@entropy(range)",
    " Boltzmann entropy of probab-",
    " ilities in range",
    "@max(range)",
    " Maximum value in range",
    "@min(range)",
    " Minimum value in range",
    "@sum(range)",
    " Sum of cell values in range",
    "@prod(range)",
    " Product of cell values",
    "@stddev(range)",
    "  Sample standard deviation",
    "@rand",
    " Uniform random value, 0-100",
    "@norm",
    " Standard normal random value",
    "@normcdf(x)",
    " Normal cumulative density",
    NULL
};

static int pscreen(char **);

void
help(void)
{
    int option;
    char **ns = intro;

    while ((option = pscreen(ns)) != 'q' && option != 'Q') {
    	switch (option) {
	case 'a': case 'A': ns = intro; break;
	case 'b': case 'B': ns = toggleoptions; break;
	case 'c': case 'C': ns = cursor; break;
	case 'd': case 'D': ns = cell; break;
	case 'e': case 'E': ns = vi; break;
	case 'f': case 'F': ns = file; break;
	case 'g': case 'G': ns = row; break;
	case 'h': case 'H': ns = range; break;
	case 'i': case 'I': ns = misc; break;
	case 'j': case 'J': ns = var; break;
	case 'k': case 'K': ns = rangef; break;
	case 'l': case 'L': ns = numericf; break;
	case 'm': case 'M': ns = stringf; break;
	case 'n': case 'N': ns = finf; break;
	case 'o': case 'O': ns = timef; break;
	case 'p': case 'P': ns = statf; break;
	case '>': case '.': case ' ':
	    if (ns == numericf) ns = numericf_more;
	    else if (ns == finf) ns = finf_more;
	    else if (ns == timef) ns = timef_more;
	    else if (ns == stringf) ns = stringf_more;
	    else if (ns == row) ns = row_more;
	    else if (ns == cell) ns = cell_more;
	    else if (ns == range) ns = range_more;
	    else if (ns == vi) ns = vi_more;
	    break;
	default: ns = intro; break;
	}
    }
    FullUpdate++;
    cleardownfrom(1);
}

static int
pscreen(char *screen[])
{
    int line, dbline, done = 0;
    int show_string = 1;
    XEvent event;
    char buffer[8];
    char c = 0;
    int is_intro = (screen == intro);

    while (!done) {
	if (show_string && is_intro) {
	    cleardownfrom(0);
	    dbline = 1;
	    for (line=0; screen[line]; line++) {
		dbline++;
		XDrawImageString(dpy, mainwin, maingc,
				 textcol(0), textrow(dbline),
				 screen[line], strlen(screen[line]));
	    }
	    XDrawImageString(dpy, mainwin, maingc,
			     textcol(0), textrow(0),
			     "Which Screen? [a-p, q]",
			     strlen("Which Screen? [a-p, q]"));
	}
	else if (show_string) {
	    cleardownfrom(0);
	    dbline = 0;
	    for (line=0; screen[line]; line++) {
		dbline++;
		XDrawImageString(dpy, mainwin, maingc,
				 textcol(0), textrow(dbline),
				 screen[line], strlen(screen[line]));
	    }
	    XDrawImageString(dpy, mainwin, maingc,
			     textcol(0), textrow(0),
			     "                        [a-p, q]",
			     strlen("                        [a-p, q]"));


	}
	show_string = 0;

	XNextEvent(dpy, &event);
	switch (event.type) {
	case Expose:
	    show_string = 1;
	    break;
	case MappingNotify:
	    XRefreshKeyboardMapping(&(event.xmapping));
	    break;
	case ConfigureNotify:
	    sc_handleresize(&event);
	    break;
	case KeyPress:
	    if (XLookupString(&(event.xkey), buffer, 8, 0, 0)) {
		c = buffer[0];
		done = 1;
	    }
	    break;
	}
    }
    return c;
}

void 
print_small_help(void)
{
   printf(
   "xspread [-h] [-c] [-m] [-n]\n"
   " [-C] [-R] [-fn font] [filename]\n\n");

   printf("-c: Column order recalculation\n"
	  "Default: row order\n");
   printf("-m: Manual recalculation\n"
	  "Default: automatic\n");
   printf("-n: Alternative Data entry mode\n"
	  "Default: numeric\n");
   printf("-C: Action on Enter: col (go down)\n");
   printf("-R: Action on Enter: row (go right)\n"
	  "Default: none\n");
   printf("-fn: Change the font\n");
   printf("-h:  Command line help\n");
   printf("Options can be changed via\n"
	  "Ctrl-t toggle commands\n");
} 
