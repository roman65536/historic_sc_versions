/*	SC	A Spreadsheet Calculator
 *
 *	Editing routines for xspread
 *	$Revision: 1.32 $
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <signal.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

#include "config.h"
#include "sc.h"
#include "scXstuff.h"

static int doyyparse = 1;
static int backstop;
static char getbuf[1024];

extern void Main_Menu(void);
extern int anychanged;

static void     get_col_row(int x, int y, int *col, int *row);

/* basic editing functions */
static void	col_0(void);
static void	last_col(void);
static void	back_space(void);
static void	del_to_end(void);
static void	stop_edit(void);
static void	del_in_line(int);
static void	ins_in_line(int);
static int	back_line(void);

/* make sure that history stuff is invoked if needed */
#ifdef USE_VI_MODE
# ifndef USE_HISTORY
#  define USE_HISTORY
# endif
#endif

#ifdef USE_HISTORY
static void	save_hist(void);
static void	trash_hist(void);
static void	for_hist(void);
static void	back_hist(void);

static int histp = -1;
static int lasthist = -1;
static int endhist = -1;

struct hist {
    unsigned len;
    char *histline;
} history[HISTLEN];
#endif

#ifdef USE_VI_MODE
# define istext(a) (isalnum(a) || ((a) == '_'))
# define	DOTLEN		200
static void	append_line(void);
static void	change_cmd(void);
static void	delete_cmd(void);
static void	del_chars(int, int);
static void	dotcmd(void);
/* cursor motion */
static int	get_motion(void);
static int	for_line(int);
static int	for_word(int);
static int	back_word(void);
/* search & replace */
static int	find_char(void);
static void	rep_char(void);
static void	replace_in_line(int);
static void	replace_mode(void);
static void	restore_it(void);
static void	savedot(int);
static void	search_again(void);
static void	search_mode(void);
static void	search_hist(void);
static int	to_char(void);
static void	u_save(int);

static char *last_search = NULL;
static char *undo_line = NULL;
static int undo_lim;
static char dotb[DOTLEN];
static int doti = 0;
static int do_dot = 0;
#endif /* USE_VI_MODE */

extern int showrange;

void
write_line(int c)
{
#ifdef DEBUG
    fprintf(stderr, "write_line() called w arg=%d\n", c);
#endif
    if (topline_mode == EDIT_MODE || topline_mode == GRAB_MODE) { 
#ifdef USE_VI_MODE
	savedot(c);
#endif
	switch (c) {
	case (ctl('a')):  col_0();	        	break;
	case (ctl('e')):  last_col();	        	break;
	case (ctl('h')):  back_space();	        	break;
	case (ctl('k')):  del_to_end();	        	break;
	case (ctl('m')):  cr_line();			break;
	case (ctl('g')):  stop_edit();			break;
#ifdef USE_VI_MODE
  	case ESC:	vi_mode();			break; 
#else
  	case ESC:	stop_edit();			break; 
#endif
	case (ctl('d')):
	case DEL:       del_in_line(1);                 break;
	default:	if (isprint((unsigned) c)) 
			    ins_in_line(c);		break;
	}
    }
#ifdef USE_VI_MODE 
    else if (topline_mode == VI_MODE) {
	switch (c) {
	case (ctl('h')): linelim = back_line();		break;
	case (ctl('m')): cr_line();			break;
	case ESC:	stop_edit();			break;
	case '+':	for_hist();			break;
	case '-':	back_hist();			break;
	case '$':	last_col();			break;
	case '.':	dotcmd();			break;
	case '/':	search_mode();			break;
	case '0':	col_0();			break;
        case 'C':       u_save(c);del_to_end(); last_col();
                        append_line();                  break;
	case 'D':	u_save(c);del_to_end();		break;
	case 'I':	u_save(c);col_0();edit_mode(); break;
	case 'R':	replace_mode();			break;
	case 'X':	u_save(c); back_space();	break;
	case 'a':	u_save(c); append_line();	break;
	case 'A':	u_save(c);last_col();append_line();	break;
	case 'b':	linelim = back_word();		break;
	case 'c':	u_save(c); change_cmd();	break;
	case 'd':	u_save(c); delete_cmd();	break;
	case 'f':	linelim = find_char();		break;
	case 'h':	linelim = back_line();		break;
	case 'i':	u_save(c); edit_mode();	break;
	case 'j':	for_hist();			break;
	case 'k':	back_hist();			break;
	case ' ':
	case 'l':	linelim = for_line(0);		break;
	case 'n':	search_again();			break;
	case 'q':	stop_edit();			break;
	case 'r':	u_save(c); rep_char();		break;
	case 't':	linelim = to_char();		break;
	case 'u':	restore_it();			break;
	case 'w':	linelim = for_word(0);		break;
	case 'x':	u_save(c); del_in_line(0);	break;
	default:	break;
	}
    } else if (topline_mode == SEARCH_MODE) {
	switch (c) {
	case (ctl('h')):  back_space();                 break;
	case (ctl('m')):  search_hist();	        break;
	case ESC:	vi_mode();			break;
	default:	ins_in_line(c);			break;
	}
    } else if (topline_mode == REP_MODE) {
	savedot(c);
	switch(c) {
	case (ctl('h')):  back_space();			break;
	case (ctl('m')):  cr_line();			break;
	case ESC:	vi_mode();			break;
	default:	replace_in_line(c);		break;
	}
    }
#endif /* USE_VI_MODE */    
}

/* editing (top line) modes */

void
edit_mode(void)
{
    topline_mode = EDIT_MODE;
    focus = FOCUS_TOP;
#ifdef USE_HISTORY
    histp = -1;
#endif
}

static void
grab_mode(void)
{
    topline_mode = GRAB_MODE;
    focus = FOCUS_TOP;
}

/* This command stops the editing process. */
static void
stop_edit(void)
{
    showrange = 0;
    linelim = -1;
    doyyparse = 1;
    topline_mode = NULL_MODE;
    focus = FOCUS_SHEET;
#ifdef USE_HISTORY
    trash_hist();
#endif
}

#ifdef USE_VI_MODE
void
vi_mode(void)
{
    topline_mode = VI_MODE;
    histp = -1;
    if (linelim < 0)	/* -1 says stop editing, ...so we still aren't */
	return;
    if (line[linelim] == '\0')
	linelim = back_line();
}

static	void
search_mode(void)
{
    line[0] = '/';
    line[1] = '\0';
    linelim = 1;
    histp = -1;
    topline_mode = SEARCH_MODE;
}

static	void
replace_mode(void)
{
    topline_mode = REP_MODE;
}
#endif /* USE_VI_MODE */

/* end of top line modes */

static	int
for_line(int stop_null)
{
    if (linelim >= 0 && line[linelim] != '\0' && 
	(line[linelim + 1] != '\0' || stop_null))
	return linelim + 1;
    else
	return linelim;
}

static	int
back_line(void)
{
    return (linelim - backstop > 0)? linelim - 1 : backstop;
}

#ifdef USE_VI_MODE
/* dot command functions.  Saves info so we can redo on a '.' command */

static	void
savedot(int c)
{
    if (!do_dot && c != '\n' && doti < DOTLEN-1) {
	dotb[doti++] = c;
	dotb[doti] = '\0';
    }
}

static int dotcalled = 0;

static	void
dotcmd(void)
{
    int c;

    if (dotcalled)	/* stop recursive calling of dotcmd() */
	return;
    do_dot = 1;
    doti = 0;
    while(dotb[doti] != '\0') {
	c = dotb[doti++];
	dotcalled = 1;
	write_line(c);
    }
    do_dot = 0;
    doti = 0;
    dotcalled = 0;
}

int
vigetch(void)
{
    int c;

    if (do_dot) {
	if (dotb[doti] != '\0') {
	    return dotb[doti++];
	} else {
	    do_dot = 0;
	    doti = 0;
	    return nmgetch();
	}
    }
    c = nmgetch();
    savedot(c);
    return c;
}
/* end dot commands */

/* saves the current line for possible use by an undo cmd */
static	void
u_save(int c)
{   
    static unsigned undolen;

    if (strlen(line) + 1 > undolen) {
	undolen = strlen(line) + 40;
	undo_line = scxrealloc(undo_line, undolen);
    }
    strcpy(undo_line, line);

    undo_lim = linelim;

    /* reset dot command if not processing it. */
    if (!do_dot) {
	doti = 0;
	savedot(c);
    }
}

/* Restores the current line saved by u_save() */
static void
restore_it(void)
{
    static char *tempc;
    static unsigned templen;
    int tempi;

    if (undo_line == NULL || *undo_line == '\0') 
	return;

    if (strlen(line)+1 > templen) {
    	templen = strlen(line)+40;
	tempc = scxrealloc(tempc, templen);
    }

    strcpy(tempc, line);
    tempi = linelim;
    strcpy(line, undo_line);
    linelim = undo_lim;
    strcpy(undo_line, tempc);
    undo_lim = tempi;
}

/*
 * Motion commands.  Forward motion commands take an argument
 * which, when set, cause the forward motion to continue onto
 * the null at the end of the line instead of stopping at the
 * the last character of the line.
 */

static	int
for_word(int stop_null)
{
    register int c;
    register int cpos;

    cpos = linelim;

    if (line[cpos] == ' ') {
	while (line[cpos] == ' ')
	    cpos++;
	if (cpos > 0 && line[cpos] == '\0')
	    --cpos;
	return cpos;
    }

    if (istext(line[cpos])) {
    	while ((c = line[cpos]) && istext(c)) 
	    cpos++;
    } else {
	while ((c = line[cpos]) && !istext(c) && c != ' ')
	    cpos++;
    }

    while (line[cpos] == ' ')
        cpos++;

    if (cpos > 0 && line[cpos] == '\0' && !stop_null) 
        --cpos;

    return cpos;
}

static	int
back_word(void)
{
    register int c, cpos = linelim;

    if (line[cpos] == ' ') {
	/* Skip white space */
        while (cpos > 0 && line[cpos] == ' ')
	    --cpos;
    } else if (cpos > 0 && (line[cpos-1] == ' ' 
			    || (istext(line[cpos]) && !istext(line[cpos-1]))
			    || (!istext(line[cpos]) &&  istext(line[cpos-1])))) {
	/* Started on the first char of a word - back up to prev. word */
	--cpos;
        while (cpos > 0 && line[cpos] == ' ')
	    --cpos;
    }

    /* Skip across the word - goes 1 too far */
    if (istext(line[cpos])) {
    	while (cpos > 0 && (c = line[cpos]) && istext(c)) 
	    --cpos;
    } else {
	while (cpos > 0 && (c = line[cpos]) && !istext(c) && c != ' ')
	    --cpos;
    }

    /* We are done - fix up the one too far */
    if (cpos > 0 && line[cpos] && line[cpos+1]) 
	cpos++;

    return cpos;
}
#endif /* USE_VI_MODE */

/* Text manipulation commands */

static	void
del_in_line(int forward)
{
    register int len, i;

    if (linelim >= 0) {
	len = strlen(line);
	if (linelim == len && linelim > 0 && !forward)
	    linelim--;
	for (i = linelim; i < len; i++)
	    line[i] = line[i+1];
    }
    if (linelim > 0 && line[linelim] == '\0')
	--linelim;
}

static void
ins_in_line(int c)
{
    register int i, len;

    if (linelim < 0) {
	*line = '\0';
	linelim = 0;
    }
    len = strlen(line);
    for (i=len; i>=linelim; i--)
	line[i+1] = line[i];
    line[linelim++] = c;
    line[len+1] = '\0';
#ifdef DEBUG
    fprintf(stderr, "ins_in_line: line is now '%s'\n", line);
#endif
}

void
ins_string(char *s)
{
    while (*s)
	ins_in_line(*s++);
}

static	void
back_space(void)
{
    if (linelim - backstop == 0)
	return;

    if (line[linelim] == '\0') {
	linelim = back_line();
	del_in_line(0);
	linelim = strlen(line);
    } else {
	linelim = back_line();
	del_in_line(0);
    }
}

#ifdef USE_VI_MODE
static void
append_line(void)
{
    register int i = linelim;

    if (i >= 0 && line[i])
	linelim++;
    edit_mode();
}

static	int
find_char(void)
{
    register int c = vigetch();
    register int i = linelim;

    while(line[i] && line[i] != c)
	i++;
    if (!line[i])
	i = linelim;
    return i;
}

static	int
to_char(void)
{
    register int i = find_char();

    if (i > 0 && i != linelim)
	--i;
    return i;
}

static	void
rep_char(void)
{
    int c;

    if (linelim < 0) {
    	linelim = 0;
	*line = '\0';
    }
    c = vigetch();
    if (line[linelim] != '\0') {
    	line[linelim] = c;
    } else {
	line[linelim] = c;
	line[linelim+1] = '\0';
    }
}

static	void
replace_in_line(int c)
{
    register int len;

    if (linelim < 0) {
    	linelim = 0;
	*line = '\0';
    }
    len = strlen(line);
    line[linelim++] = c;
    if (linelim > len)
	line[linelim] = '\0';
}

static	int
get_motion(void)
{
    int c = vigetch();

    switch (c) {
    case 'b': return back_word();
    case 'f': return find_char() + 1;
    case 'h': return back_line();
    case 'l': return for_line(1);
    case 't': return to_char() + 1;
    case 'w': return for_word(1);
    case '0': return 0;
    case '$': return strlen(line);
    default: return linelim;
    }
}

static int del_end;

static	void
delete_cmd(void)
{
    int cpos, ll = strlen(line);

    del_end = 0;
    cpos = get_motion();
    if (cpos == ll || linelim == ll)
	del_end = 1;
    del_chars(cpos, linelim);
}

static	void
change_cmd(void)
{
    delete_cmd();
    if (del_end)
	append_line();
    else
	edit_mode();
}

static	void
del_chars(register int first, register int last)
{
    int temp;

    if (first == last)
	return;

    if (last < first) {
	temp = last; last = first; first = temp;
    }

    linelim = first;
    while (first < last) {
	del_in_line(0);
	--last;
    }
}
#endif /* USE_VI_MODE */

static	void
del_to_end(void)
{
    if (linelim - backstop < 0)
	return;
    line[linelim] = '\0';
    /* linelim = back_line(); */
}

void
cr_line(void)
{
    char *test;

    showhint = 0;
    edit_mode();
    if (linelim != -1) {
	focus = FOCUS_SHEET;
	showrange = 0;
	linelim = 0;
	if (doyyparse) {
	    yyparse();
#ifdef USE_HISTORY
	    if (!seenerr && strlen(line)) 
		save_hist();
#endif
	} else {
	    if ((test = strstr(line, ":")) && strlen(test) > 2) 
		strcpy(getbuf, test + 2);
	    else getbuf[0] = '\0';
	    doyyparse = 1;
	}
	linelim = -1;
	topline_mode = NULL_MODE;
    } else {    /* '\n' alone will put you into entry mode */
    	*line = '\0';
	linelim = 0;
    }
}

#ifdef USE_HISTORY
/* History functions */
static	void
save_hist(void)
{
    if (lasthist < 0) 
    	lasthist = 0;
    else
	lasthist = (lasthist + 1) % HISTLEN;

    if (lasthist > endhist)
	endhist = lasthist;

    if (history[lasthist].len < strlen(line)+1) {
    	history[lasthist].len = strlen(line)+40;
	history[lasthist].histline = scxrealloc(history[lasthist].histline,
						history[lasthist].len);
    }
    strcpy(history[lasthist].histline, line);
}

static void
trash_hist (void)
{
    if (lasthist >= 0) {
	scxfree(history[lasthist].histline);
	history[lasthist].histline = NULL;
	lasthist--;
    }
}

static	void
back_hist(void)
{
    fprintf(stderr, "back_hist(): histp = %d, lasthist = %d\n", histp, lasthist);
    if (histp == -1) {
	histp = lasthist - 1; /* was lasthist */
	if (histp < 0) return;
    } 
    else if (histp == 0) {
	if (endhist != lasthist)
	    histp = endhist;
    } 
    else if (histp != ((lasthist + 1) % (endhist + 1)))
	histp--;

    if (lasthist < 0)
	line[linelim = 0] = '\0';
    else {
    	strcpy(line, history[histp].histline);
	linelim = strlen(line);
    }
}

static	void
for_hist(void)
{
    if (histp == -1)
	histp = lasthist;
    else
	if (histp != lasthist)
	    histp = (histp + 1) % (endhist + 1);

    if (lasthist < 0)
	line[linelim = 0] = '\0';
    else {
	strcpy(line, history[histp].histline);
	linelim = strlen(line);
    }
}
#endif /* USE_HISTORY */

#ifdef USE_VI_MODE
static	void
search_hist(void)
{
    static unsigned lastslen = 0;

    if (linelim < 1) {
	linelim = 0;
	vi_mode();
	return;
    }

    if (strlen(line)+1 > lastslen) {
    	lastslen = strlen(line)+40;
	last_search = scxrealloc(last_search, lastslen);
    }
    strcpy(last_search, line+1);
    search_again();
    topline_mode = VI_MODE;
}

static	void
search_again(void)
{
    int found_it;
    int do_next;
    int prev_histp;
    char *look_here;

    prev_histp = histp;
    if (last_search == NULL || *last_search == '\0')
	return;

    do {
	back_hist();
	if (prev_histp == histp)
	    break;
	prev_histp = histp;
	look_here = line;
	found_it = do_next = 0;
	for (look_here = strchr(look_here, last_search[0]);
	     look_here != NULL && !found_it && !do_next;
	     look_here = strchr(look_here, last_search[0])) {
	    if (strncmp(look_here, last_search, strlen(last_search)) == 0)
		found_it++;
	    else if (look_here < line + strlen(line) - 1)
	        look_here++;
	    else
		do_next++;
	}
    } while (!found_it);
}
#endif /* USE_VI_MODE */

static	void
col_0(void)
{
    linelim = backstop;
}

static	void
last_col(void)
{
    linelim = strlen(line);
}

char *
get_str(char *s, int maxlen, int *cancel)
{
    KeySym k;
    size_t n = strlen(s);

    doyyparse = 0;
    if (n > 0 && s[n-1] == ':') { /* add a trailing space if need be */
	s[n] = ' ';
	s[n+1] = '\0';
    }
    sprintf(line, s);
    linelim = strlen(line);
    if (strstr(line, ":"))
	backstop = strstr(line, ":") - line + 2;
    grab_mode();
    show_top_line();
    while (!doyyparse) {
	k = nmgetch();
	if (cancel != NULL && (k == ctl('g') || k == ESC)) *cancel = 1;
	if (k != NoSymbol) write_line(k);
	show_top_line();
    }
    backstop = 0;
    strncpy(s, getbuf, maxlen - 1);
    s[maxlen-1] = '\0';
    return s;
}

static void 
get_col_row (int x, int y, int *col, int *row)
{
    int pixel, complete;

    pixel = 5 * curfontwidth + 1; 
    complete = 0;
    *col = stcol - 1; 
    if (stcol > 0 && x < pixel) 
	*col = stcol - 1;
    else {
	while (!complete) {
	    (*col)++;
	    checkbounds(row, col);
	    if (!col_hidden[*col]) {
		pixel = pixel + fwidth[*col] * curfontwidth;
		if (x < pixel)
		    complete++;
	    }
	}
    }
    /* find y (row) */
    pixel = 4 * curfontheight + 3; 
    complete = 0; 
    *row = strow - 1; 
    if (strow > 0 && y < pixel)
	*row = strow - 1;
    else {
	while (!complete) {
	    (*row)++; 
	    checkbounds(row, col);
	    if (!row_hidden[*row]) {
		pixel = pixel + curfontheight;
		if (y < pixel)
		    complete++;
	    }
	}
    }
}

static int
want_range (char *line)
{
    int c1 = line[linelim-1], c2 = line[linelim-2];

    if (strstr(line, "cell for")) return 0;

    if (c1 == ' ' && c2 == '=') return 0;
    if (c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/' ||
	c1 == '^' || c1 == '%' || c1 == '=' || c1 == '>' ||
	c1 == '<' || c1 == '~' || c1 == '&' || c1 == '|')
	return 0;

    if (strstr(line, "@") == NULL ||
	strstr(line, "@avg") != NULL ||
	strstr(line, "@count") != NULL ||
	strstr(line, "@entropy") != NULL ||
	strstr(line, "@max") != NULL ||
	strstr(line, "@min") != NULL ||
	strstr(line, "@prod") != NULL ||
	strstr(line, "@stddev") != NULL ||
	strstr(line, "@sum") != NULL ||
	strstr(line, "@lookup") != NULL)
	return 1;
    else
	return 0;
}

KeySym
nmgetch(void)
{
    XEvent event;
    KeySym key;
    char buffer[8];
    int oldcol = curcol, oldrow = currow;
    static int range_complete = 1;

    while (TRUE) {
	XNextEvent(dpy, &event);

	while (event.type == MotionNotify) 
	    XNextEvent(dpy, &event);

	if (event.xbutton.button == 3) { /* mouse 3 shows menu */
	    Main_Menu();
	    /* show_top_line(); */
	    if (!running)
		return (int) 'q';
	} else if (event.type == ButtonPress) {

	    /* click shifts focus */
	    if (event.xbutton.y >= 3 * curfontheight) 
		focus = FOCUS_SHEET;
	    else
		focus = FOCUS_TOP;

	    /* click on top line */
	    if (event.xbutton.y <= curfontheight) {
		/* go into edit mode, if not already there */
		if (topline_mode == NULL_MODE)
		    return (int) 'e';
		/* shift top line cursor to click point */
		else if (topline_mode == EDIT_MODE) {
		    int x = event.xbutton.x / curfontwidth - 2;
		    if (x <= strlen(line)) {
			linelim = x;
			return NoSymbol;
		    }
		}
	    } else {
		/* click on sheet shifts highlight */
		get_col_row(event.xbutton.x, event.xbutton.y,
			    &curcol, &currow);
	    }

	    /* click the current cell address into the top line */
	    if (linelim > 0 && focus == FOCUS_SHEET
		&& event.xbutton.y >= 4 * curfontheight) {
		int w = want_range(line);

		sprintf(line + linelim, "%s%d%s", coltoa(curcol), currow,
			(range_complete && w)? ":" : "");
		if (w) 
		    range_complete = !(range_complete);
		linelim = strlen(line);
		curcol = oldcol;
		currow = oldrow;
		return NoSymbol;
	    } else {
		oldcol = curcol; oldrow = currow;
		update(anychanged);
	    } /* end of mouse click */
	} else if (event.type == KeyPress) {
	    if (XLookupString(&(event.xkey), buffer, 8, &key, 0)) {
#ifdef DEBUG
		fprintf(stderr, "xkey: got %d\n", buffer[0]);
#endif		
		return buffer[0];
	    }
	    else if (IsCursorKey(key)) {
		switch (key) {
		case XK_Left: 
		    if (focus == FOCUS_SHEET) 
			return ctl('b');
		    if (topline_mode == EDIT_MODE || topline_mode == GRAB_MODE) 
			linelim = back_line();
		    return NoSymbol;
		case XK_Right: 
		    if (focus == FOCUS_SHEET) 
			return ctl('f');
		    if (topline_mode == EDIT_MODE || topline_mode == GRAB_MODE) {
			if (linelim < strlen(line)) {
			    linelim = for_line(1);
			    return NoSymbol;
			} else 
			    return ctl('f');
		    }
		case XK_Down: 
#ifdef VR3
		case XK_Page_Down: 
#endif
		    /* if (focus == FOCUS_SHEET) */
		    return ctl('n');
#ifdef USE_HISTORY
		    if (topline_mode == EDIT_MODE) {
			fprintf(stderr, "nmgetch(), before for_hist(), "
				"histp=%d\n", histp);
			for_hist();
			fprintf(stderr, "nmgetch(), after for_hist(), "
				"histp=%d\n", histp);
		    }
#endif
		    return NoSymbol;
		    
		case XK_Up: 
#ifdef VR3
		case XK_Page_Up: 
#endif
		    /* if (focus == FOCUS_SHEET) */
		    return ctl('p');
#ifdef USE_HISTORY
		    if (topline_mode == EDIT_MODE) {
			fprintf(stderr, "nmgetch(), before back_hist(), "
				"histp=%d\n", histp);
			if (histp == -1) save_hist();
			back_hist();
			fprintf(stderr, "nmgetch(), before back_hist(), "
				"histp=%d\n", histp);
		    }
#endif
		    return NoSymbol;
		}
		return key;
	    }
	} else {
	    switch(event.type) {
	    case Expose:
		if (event.xexpose.count != 0)
		    break;
		FullUpdate++;
		update(anychanged);
		break;

	    case MappingNotify:
		XRefreshKeyboardMapping(&(event.xmapping));
		break;

	    case ConfigureNotify:
		sc_handleresize(&event);
		break;
	    }
	}
    }
}
