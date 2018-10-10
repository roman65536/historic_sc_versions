/*
 * Copyright (C) 1992  Board of Regents of the University of Wisconsin
 * on behalf of the Department of Electrical Engineering and Computer
 * Science, University of Wisconsin-Milwaukee, Milwaukee, WI 53201.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * The programs in this directory were developed by software engineering
 * teams as part of the course "Introduction to Software Engineering"
 * under the supervision of Professor G. Davida.
 *
 * Please send all changes, enhancements, and other comments about this
 * software to
 *
 *     		soft-eng@cs.uwm.edu
 *
 *			or
 *		
 *		Software Engineering Coordinator
 *		Computer Science
 *   		Department of EECS
 *		University of Wisconsin - Milwaukee
 *		Milwaukee, WI  53201
 *		414-229-4677
 */


/* Original work by Tuan Tang, July 1990 */

/* Modified by Dan Gruber to run Line, Bar, XY, Stack Bar and
   Pie graphs.  Mike Frey modified the Graph Menu so that if
   <ESC> is pressed, it will bounce up one.  December 1991 */

/* B. Backman 7-29-91.  Appended other graphic calls to this
 * file instead of (ugh) #include-ing (choke, choke) them.
 * Also, fixed the atrocious spelling and grammar of Tuan Tang! */

/* Extensively re-written by Allin Cottrell, May 2001 */

#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "config.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <stdio.h>
#include <ctype.h> 
#include "sc.h"  
#include "scXstuff.h" 
#include "plot.h"

/* link to fltk file dialog, in scstub.c */
extern int
get_filename(const char *msg, const char *pat, char *fname, 
	     const char *start); 

extern void Main_Menu(void);
extern unsigned 
menu(unsigned item_no, char *item[], char *help_prompt[], int deflt);
extern struct m_range *findrge(char *s);
void message(const char *x);

static void view_graph(struct graph *plot);

static void format_select(struct graph *plot);
static void format_set(unsigned idx, struct graph *plot);
static void range_select(int c, struct graph *plot);
static void grid_select(struct graph *plot);
static void legend_select(struct graph *plot);
static void options_select(struct graph *plot);
static void scale_select(struct graph *plot);
static void axis_scale_select(unsigned c, char *m[], struct graph *plot);
static void axis_range(int c1, char *m[], int c2, struct graph *plot);
static void title_select(struct graph *plot);
static void type_select(struct graph *plot);
static void gc_select(struct graph *plot);
static int graph_defined(struct graph *plot, int gnuplot);
static void export_gnuplot(char *fname, struct graph *plot);

static GC graphgc;

/* menu setup and item count */

static char *menu_top[] = {
    "Type",
    "X", "A", "B", "C", "D",
    "Reset",
    "View",
    "Export",
    "Options"
};

static char *help_top[] = {
    "Type of graph",
    "Set data range for X",
    "Set data range for A",
    "Set data range for B",
    "Set data range for C",
    "Set data range for D",
    "Clear all graph settings",
    "View the graph",
    "Export to gnuplot file",
    "Graph output options"
};

static unsigned msize_main = sizeof menu_top / sizeof menu_top[0];

/* This function sets the numeric scales for the X axis    */
/* and Y axis, Automatic is the default scale while manual */
/* allows the user specified output data range.            */

static void
axis_scale_select(unsigned c, char *m[], struct graph *plot) 
     /* c = 1 for X scale, 2 for Y scale */
     /* m = array of items from scale_select */
{
    static char *submenu[] = {
	"Automatic",
	"Lower",
	"Upper",
    };
    static char *help[] = {
	"Use max, min values of data to set scale",
	"Set lower limit manually",                        
	"Set upper limit manually",
    };
    unsigned choice;
    unsigned msize = sizeof submenu / sizeof submenu[0];

    while ((choice = menu(msize, submenu, help, 1)) != 0)
	switch (choice) {
	case 0: 
	    options_select(plot);
	    break;
	case 1: 
	    plot->auto_man[c-1] = 'A';
	    message("Graph scale is Automatic");
	    break;
	case 2: 
	case 3: 
	    axis_range(c, m, choice, plot);
	    break;
	default: 
	    message("Invalid data!");
	    break;
	}  
}

static double 
gatofn(char s[])    /* convert s to double (from system library) */
{
    double val, power;
    int i, sign;

    for (i=0; s[i]==' ' || s[i]=='\n' || s[i]=='\t'; i++)
        ;           /* skip white space */
    sign = 1;
    if (s[i] == '+' || s[i] == '-') 
	sign = (s[i++]=='+') ? 1 : -1;
    for (val = 0; s[i] >= '0' && s[i] <= '9'; i++)
	val = 10 * val + s[i] - '0';
    if (s[i] == '.')
	i++;
    for (power = 1; s[i] >= '0' && s[i] <= '9'; i++) {
	val = 10 * val + s[i] - '0';
	power *= 10;
    }
    return(sign * val / power);
}

/* Function format_select sets the output format    */
/* of XY & line graphs. The format can be set for     */
/* each data range or for all data ranges.            */
/* To set one data range at a time select A,B,...,    */
/* or F.  And of all data ranges select Graph.        */

static void 
format_select(struct graph *plot)
{
    static char *submenu[] = {
	"Graph",
	"A", "B", "C", "D",
    };
    static char *help[] = {
	"Change format of the entire graph",
	"Change the format of A range",                     
	"Change the format of B range",                     
	"Change the format of C range",                     
	"Change the format of D range",                     
    };
    unsigned msize = sizeof submenu / sizeof submenu[0];
    unsigned choice;
    char msg[100];

    while ((choice = menu(msize, submenu, help, 1))) {
	if (choice > msize) {
	    sprintf(msg,"0 <= Input Data < %1d ", msize);
	    message(msg);
	} else 
	    format_set(choice - 1, plot); 
    } 
}  

static void
format_set(unsigned idx, struct graph *plot)
{
    static char *submenu[] = {
	"Lines",
	"Symbols",
	"Both"
    };

    static char *help[] = {
	"Connect points with lines",
	"Represent points with symbols",
	"Use both lines and symbols"
    };

    unsigned choice;
    unsigned menusize = sizeof submenu / sizeof submenu[0];
    char msg[100];
    int i, deflt;

    deflt = (plot->format[idx] == 'S')? 2 : (plot->format[idx] == 'B')? 3 : 1;

    choice = menu(menusize, submenu, help, deflt);
    switch (choice) {
    case 0: options_select(plot); break;
    case 1: plot->format[idx] = 'L'; break;
    case 2: plot->format[idx] = 'S'; break;
    case 3: plot->format[idx] = 'B'; break;
    default: 
	message("Input error for format!");
	break;
    }   
    if (1 <= choice && choice <= menusize) {
	sprintf(msg, "Graph format is %s", submenu[choice-1]);
	message(msg);
    }	 
    
    /* set a common format for all data ranges */
    if (idx == 0) { 
	for (i=1; i<N_RANGES; i++) 
	    plot->format[i] = plot->format[0];
    }
}  

static void
range_select(int i, struct graph *plot)
{
    char s[100], orig[18];
    struct m_range *rge = NULL;
    int cancel = 0;

    if (plot->rge[i].ec != -1) 
	sprintf(orig, " %s%d:%s%d", coltoa(plot->rge[i].sc), plot->rge[i].sr,
		coltoa(plot->rge[i].ec), plot->rge[i].er);
    else
	strcpy(orig, " ");

    if ((plot->type == 'L' || plot->type == 'B') && i == 0) {
	sprintf(s, "range for X labels:%s", orig);
	error("(blank for auto labels)");
    }
    else
	sprintf(s, "range for %c data:%s", (i == 0)? 'X' : 'A' + i - 1, orig);
    get_str(s, TSSIZE, &cancel);
    if (cancel) return;
    if (*s == '\0' || (rge = findrge(s)) == NULL) {
	if (*s) error("Input syntax error");
	return;
    }
    if (rge->sc != rge->ec) {
	error("please select a single series");
	scxfree(rge);
	return;
    }
    plot->rge[i] = *rge;
    scxfree(rge);
}

static void 
grid_select(struct graph *plot)
{
    static char *submenu[] = { 
	"Horizontal",
	"Vertical",                 
	"Both",
	"None",
    };
                   
    static char *help[] = { 
	"Show horizontal grid lines",
	"Show vertical grid lines",
	"Show full grid",
	"Don't show grid lines"
    };

    unsigned choice;
    unsigned menusize = sizeof submenu / sizeof submenu[0];
    char msg[100];
    int deflt;

    deflt = (plot->grid == 'V')? 2 : (plot->grid == 'B')? 3 :
	(plot->grid == 'C')? 4 : 1;
    
    choice = menu(menusize, submenu, help, deflt);
    switch (choice) {
    case 0: options_select(plot); break;
    case 1: 
	plot->grid = 'H';
	message("Add horizontal grid lines");
	break;
    case 2: 
	plot->grid = 'V';
	message("Add vertical grid lines");
	break;
    case 3: 
	plot->grid = 'B';
	message("Add full grid");
	break;
    case 4: 
	plot->grid = 'C';
	message("No grid lines");
	break;
    default: 
	sprintf(msg, "0 <= Input Data <= %1d ", menusize);
	message(msg);
	break;
    } 
} 

void
graph_init(struct graph *plot)
{
    int i, j;

    plot->type = 'X';  /* default graph type is X-Y scatter */
    plot->grid = 'C';  /* default: no grid lines */
   
    for (i=0; i<N_RANGES-1; i++)  
	plot->legend[i][0] = '\0';    /* no legends assigned */

    for (i=0; i<N_TITLES; i++)    /* no titles assigned */
	plot->title[i][0] = '\0';

    plot->auto_man[0] = plot->auto_man[1] = 'A';  /* Automatic scaling */

    for (i=0; i<2; i++) 
	for (j=0; j<2; j++)
	    plot->scale[i][j] = 0.0;

    for (i=0; i<N_RANGES; i++) {
	plot->format[i] = 'S'; /* default: symbols, no lines */
	plot->rge[i].ec = -1;  /* data ranges undefined */
    }

    plot->labelskip = 1;
}   

static void
legend_select(struct graph *plot)
{
    static char *submenu[] = {
	"A", "B", "C", "D", 
    };

    static char *help[] = {
	"Set legend for A",
	"Set legend for B",
	"Set legend for C",
	"Set legend for D", 
    };

    unsigned choice;
    unsigned menusize = sizeof submenu / sizeof submenu[0];
    char msg[100];
    int cancel = 0;
    
    while ((choice = menu(menusize, submenu, help, 1))) {
	sprintf(msg, "legend for %s: %s", submenu[choice-1], 
		plot->legend[choice-1]);
	get_str(msg, GMAXLEN, &cancel);
	if (cancel) continue;
	strcpy(plot->legend[choice-1], msg); 
	sprintf(msg, "legend for %s is: %s", submenu[choice-1],
		plot->legend[choice-1]); 
	message(msg); 
    }
}

static void
options_select(struct graph *plot)
{
    static char *submenu[] = {
	"Legend",
	"Format",
	"Titles",
	"Grid",
	"Scale",
	"Reverse"
    };

    static char *help[] = {
	"Labels to identify data",
	"Change appearance of line and XY graphs",
	"Assign title to axes or graph",
	"Add or remove grid lines",
	"Set numeric scales for axes",
	"Reverse background/foreground colors"
    };

    unsigned c;
    unsigned menusize = sizeof submenu / sizeof submenu[0];

    do {  
        c = menu(menusize, submenu, help, 1);
        switch (c) {
	case 1: legend_select(plot);
	    break;
	case 2: format_select(plot); 
	    break;
	case 3: title_select(plot); 
	    break;
	case 4: grid_select(plot); 
	    break;
	case 5: scale_select(plot);
	    break;
	case 6: gc_select(plot);
	    break;
	case 0: break; 
	default: 
	    message("Invalid data!");
	    break;
	}
    } while (c); 
}

static void
scale_select(struct graph *plot)
{
    static char *submenu[] = {
	"X scale",
	"Y Scale"
    };

    static char *help[] = {
	"Alter X-axis scale",                        
	"Alter Y-axis scale"
    };

    unsigned choice;
    unsigned menusize = sizeof submenu / sizeof submenu[0];
    char msg[100];

    while ((choice = menu(menusize, submenu, help, 1))) {
	switch (choice) {
	case 0: 
	    options_select(plot); break;
	case 1: 
	case 2: 
	    axis_scale_select(choice, submenu, plot); break;
	default: 
	    sprintf(msg, "0<= Input Value <=%1d", menusize);
	    message(msg);
	    break;
	}
    }  
} 

static void 
gc_select(struct graph *plot)
     /* added by Allin Cottrell, May 2001 */
{
    static char *submenu[] = {
	"Black on white",
	"White on black"
    };

    static char *help[] = {
	"Black lines/symbols, white background",
	"White lines/symbols, black background"                        
    };

    unsigned choice;
    unsigned menusize = sizeof submenu / sizeof submenu[0];

    choice = menu(menusize, submenu, help, 1);
    switch (choice) {
    case 1: 
	graphgc = maingc;
	message("Black on white background");
	break;
    case 2: 
	graphgc = maingcreversed;
	message("White on black background");
	break;
    default: 
	options_select(plot); break;
    } 
} 

/* Sets the range of X scale or Y scale */
/* called from scale_select() */

static void
axis_range(int c1, char *m[], int c2, struct graph *plot)
     /* c1: indicate whether it is X scale or Y scale */
     /* m[] array of items: X, Y scale */
     /* c2: indicate whether it is Lower or Upper limit */
{
    char s[GMAXLEN], numstr[32];
    int cancel = 0;

    if (c2 == 2) {  /* Lower limit */
	if (plot->scale[c1-1][0] != 0.0)
	    sprintf(numstr, " %.2f", plot->scale[c1-1][0]);
	else
	    strcpy(numstr, "");
	sprintf(s, "lower limit for %s:%s", m[c1-1], numstr);
	get_str(s, GMAXLEN, &cancel);
	if (cancel) return;
	plot->scale[c1-1][0] = gatofn(s);
    }
    else if (c2 == 3) { /* Upper limit */
	if (plot->scale[c1-1][1] != 0.0)
	    sprintf(numstr, " %.2f", plot->scale[c1-1][1]);
	else
	    strcpy(numstr, "");
	sprintf(s, "upper limit for %s:%s", m[c1-1], numstr);
	get_str(s, GMAXLEN, &cancel);
	if (cancel) return;
	plot->scale[c1-1][1] = gatofn(s);
    }
}
  
static void
title_select(struct graph *plot)
{
    static char *submenu[] = {
	"first",
	"second",
	"x-axis",
	"y-axis",
    };

    static char *help[] = {
	"main title for graph",
	"subtitle",
	"label for x-axis",
	"label for y-axis",
    };

    unsigned choice;
    unsigned menusize = sizeof submenu / sizeof submenu[0];
    char s[GMAXLEN];
    int cancel = 0;

    while ((choice = menu(menusize, submenu, help, 1)) != 0) {
	if (choice > menusize) {
	    sprintf(s, "0 <= Input Value < %1d ", menusize);
	    message(s);
	} else {
	    sprintf(s, "Enter %s title: %s", submenu[choice-1], 
		    plot->title[choice-1]);
	    get_str(s, GMAXLEN, &cancel);
	    if (cancel) continue;
	    strcpy(plot->title[choice-1], s);
	}  
    }  
} 

static void
type_select(struct graph *plot)
{
#ifdef VR3
    static char *submenu[] = {
	"XY",
	"Line"
    };
    static char *help[] = {
	"X-Y scatter diagram",
	"Time-series plot or similar"
    };
#else
    static char *submenu[] = {
	"XY",
	"Line",
	"Bar"
    };
    static char *help[] = {
	"Plot pairs of xy values with a point",
	"Represent each value with a point",
	"Represent each value with a bar"
    };
#endif

    unsigned choice;
    unsigned menusize = sizeof submenu / sizeof submenu[0];
    char msg[100];
    int deflt;

    deflt = (plot->type == 'L')? 2 : (plot->type == 'B')? 3 : 1;

    choice = menu(menusize, submenu, help, deflt);
    switch (choice) {
    case 1: plot->type = 'X'; break;
    case 2: plot->type = 'L'; break;
#ifndef VR3
    case 3: plot->type = 'B'; break;
#endif
    case 0: break;
    default: sprintf(msg, "Sorry, %s is not implemented",
		     submenu[choice-1]);
    message(msg);
    choice = 0;
    break;
    }
    if (0 < choice && choice <= menusize) {
	sprintf(msg, "Selected %s graph", submenu[choice-1]);
	message(msg);
    }
}

static void
view_graph(struct graph *plot)
{
    int i, j;
    double x;

    if (!graphgc) graphgc = maingc;

    if (plot->type != 'L' && plot->rge[0].ec == -1) { 
	message("X range not defined");
	return;
    }

    plot->nlines = 0;
    for (i=1; i<N_RANGES; i++) {
	int cells = 0; /* valid numeric cells in this range */

	if (plot->rge[i].ec == -1)
	    continue;
	for (j=plot->rge[i].sr; j<=plot->rge[i].er; j++) {
	    if ((lookat(j, plot->rge[i].sc))->flags & is_valid)
		cells++;
	    else {
		sprintf(stringbuf,"Bad value in range '%c'", 'A' + i);
		message(stringbuf);
	    }
	}
	if (cells < 1) {
	    sprintf(stringbuf,"Range '%c' ignored", 'A' + i);
	    message(stringbuf);
	    plot->rge[i].ec = -1;
	} else 
	    plot->nlines += 1;
    }  
    if (plot->nlines < 1) {
	message("Not enough ranges defined");
	return;
    }
 
    if (plot->scale[0][0] > plot->scale[0][1]) {
	x = plot->scale[0][0]; 
	plot->scale[0][0] = plot->scale[0][1]; 
	plot->scale[0][1] = x; 
    }

    if (plot->scale[1][0] > plot->scale[1][1]) {
	x = plot->scale[1][0]; 
	plot->scale[1][0] = plot->scale[1][1]; 
	plot->scale[1][1] = x; 
    }

    switch (plot->type) {
    case 'X':
	plot_XY(plot, graphgc);
	break;
    case 'L':
	plot_line(plot, graphgc);
	break; 
#ifndef VR3
    case 'B':
	plot_bar(plot, graphgc);
	break;
#endif 
    default:
	error("graph type not defined");
	return;
    }
    FullUpdate++; /* in case window becomes obscured */
    update(FALSE);
}

/* exported functions */

void
Graph_Menu(struct graph *plot)
{
    char fname[PATHLEN];
    unsigned c = 0;

    do {     /* do until ESC is selected */
	c = menu(msize_main, menu_top, help_top, 1); 
	switch (c) {    
	case 0: 
	    Main_Menu(); 
	    break; 
	case 1: 
	    type_select(plot); 
	    break;
	case 2: 
	case 3:
	case 4: 
	case 5:
	case 6: 
	    range_select(c-2, plot); 
	    break;
	case 7: 
	    graph_init(plot);
	    message("Graph settings cleared");
	    break;
	case 8: 
	    view_graph(plot); 
	    break;
	case 9:
	    if (!graph_defined(plot, 1)) 
		error("No graph is defined");
	    else if (get_filename("Export graph", "*.gp", fname, NULL)) 
		export_gnuplot(fname, plot);
	    break;
	case 10: 
	    options_select(plot); 
	    break;
	default: 
	    message("Invalid data!");
	    break;
	} 
    } while (c);
}

void 
message(const char *s)  
{
    clearlines(0, 0);
    XDrawImageString(dpy, mainwin, maingc,
		     textcol(0), textrow(0),
		     s, strlen(s));
    XFlush(dpy);      
    sleep(1);         
    clearlines(0, 0);
} 

/* modified versions of Dan Coppersmith's functions
   for writing and reading graphic definitions
*/

void
read_plot_options(FILE *f, struct graph *plot)
{
    int c, i, j, k;
    double d1, d2;
    char t, line[100], s[42];

    while (fgets(line, sizeof line, f)) {
	if (sscanf(line, "g_type = %c", &t) == 1) 
	    plot->type = t;
	else if (sscanf(line, "g_labelskip = %d", &c) == 1) 
	    plot->labelskip = c;
	else if (sscanf(line, "g_legend[%d] = %16s", &i, s) == 2) { 
	    strcpy(plot->legend[i], line + 14);
	    plot->legend[i][strlen(plot->legend[i]) - 1] = '\0';
	}
	else if (sscanf(line, "g_format = %4s", s) == 1) {
	    for (i=1; i<N_RANGES; i++) 
		plot->format[i] = s[i-1];
	}
	else if (sscanf(line, "g_title[%d] = %39s", &i, s) == 2) {
	    strcpy(plot->title[i], line + 13);
	    plot->title[i][strlen(plot->title[i]) - 1] = '\0';
	}
	else if (sscanf(line, "g_grid = %d", &c) == 1)
	    plot->grid = c;
	else if (sscanf(line, "curves_n = %d", &i) == 1)
	    plot->nlines = i;
	else if (sscanf(line, "g_scale[%d][] = %lf %lf", 
			&i, &d1, &d2) == 3) {
	    plot->scale[i][0] = d1;
	    plot->scale[i][1] = d2;
	}
	else if (sscanf(line, "g_range[%d] = %d %d %d", 
			&i, &c, &j, &k) == 4) {
	    plot->rge[i].sr = c;
	    plot->rge[i].er = j;
	    plot->rge[i].sc = k;
	    plot->rge[i].ec = 0;
	}
	else if (!strncmp(line, "End Graph", 9)) {
	    return;
	}
    }
}

static int 
graph_defined(struct graph *plot, int gnuplot)
{
    int i, save = 0;

    for (i=0; i<N_RANGES; i++)
        if (plot->rge[i].ec != -1)
            save = 1;
    if (gnuplot && save == 0) return 0;

    for (i=0; i<N_RANGES-1; i++)
        if (plot->legend[i][0] != '\0')
            save = 1;
    for (i=0; i<N_TITLES; i++)
        if (plot->title[i][0] != '\0')
            save = 1;
    for (i=0; i<N_RANGES; i++)
        if (plot->format[i] != 'S')
            save = 1;

    if (plot->type != 'X' || plot->grid != 'C' || plot->auto_man[0] != 'A' ||
	plot->auto_man[1] != 'A')
	save = 1;

    return save;
}

void
print_plot_options(FILE *f, struct graph *plot)
{
    int i;

    if (!graph_defined(plot, 0)) return;

    fprintf(f, "Graph Definitions:\n");
    fprintf(f, "g_type = %c\n", plot->type);
    
    for (i=0; i<N_RANGES-1; i++) {
	if (plot->legend[i][0] != '\0') 
	    fprintf(f, "g_legend[%d] = %s\n", i, plot->legend[i]);
    }

    fprintf(f, "g_format = ");
    for (i=1; i<N_RANGES; i++)
        fprintf(f, "%c", plot->format[i]);
    fprintf(f, "\n");

    for (i=0; i<N_TITLES; i++) {
	if (plot->title[i][0] != '\0')
	    fprintf(f, "g_title[%d] = %s\n", i, plot->title[i]);
    }

    fprintf(f, "curves_n = %u\n", plot->nlines);

    fprintf(f, "g_grid = %c\n", plot->grid);

    for (i=0; i<2; i++) {
	if (plot->auto_man[i] == 'M') 
	    fprintf(f, "g_scale[%d][] = %f %f\n", i,
		    plot->scale[i][0], plot->scale[i][1]);
    }

    for (i=0; i<N_RANGES; i++) {
	if (plot->rge[i].ec != -1)
	    fprintf(f, "g_range[%d] = %d %d %d\n", i,
		    plot->rge[i].sr, plot->rge[i].er,
		    plot->rge[i].sc);
    } 

    fprintf(f, "g_labelskip = %d\n", plot->labelskip);

    fprintf(f, "End Graph Definitions\n");
}

static void
export_gnuplot(char *fname, struct graph *plot)
{
    int i, j, k, count, nlabels;
    char legend[42], withstr[16];
    struct ent *xent, *yent; 
    FILE *f;

    f = fopen(fname, "w");
    if (f == NULL) {
	error("Couldn't open gnuplot file");
	return;
    }

    fprintf(f, "# plot exported from xspread\n");

    if (plot->title[0][0] != '\0') {
	fprintf(f, "set title \"%s", plot->title[0]);
	if (plot->title[1][0] != '\0')
	    fprintf(f, "\\n%s\"\n", plot->title[1]);
	else  
	    fprintf(f, "\"\n");
    }

    if (plot->grid == 'H')
	fprintf(f, "set grid ytics\n");
    else if (plot->grid == 'V')
	fprintf(f, "set grid xtics\n");
    else if (plot->grid == 'B')
	fprintf(f, "set grid xtics ytics\n");

    if (plot->title[2][0] != '\0')
	fprintf(f, "set xlabel '%s'\n", plot->title[2]);

    if (plot->title[3][0] != '\0')
	fprintf(f, "set ylabel '%s'\n", plot->title[3]);

    if (plot->auto_man[0] == 'M')
	fprintf(f, "set xrange [%f:%f]\n", 
		plot->scale[0][0], plot->scale[0][1]);

    if (plot->auto_man[1] == 'M')
	fprintf(f, "set yrange [%f:%f]\n", 
		plot->scale[1][0], plot->scale[1][1]);

    if (plot->type == 'L' && plot->rge[0].ec != -1) {
	count = 0;
	for (i=plot->rge[0].sr; i<=plot->rge[0].er; i++) { 
	    xent = lookat(i, plot->rge[0].sc);
	    if (!(xent->label)) continue;
	    count++;
	} 
	nlabels = count / plot->labelskip;
#ifdef DEBUG
	fprintf(stderr, "count=%d, labelskip=%d, nlabels=%d\n",
		count, plot->labelskip, nlabels);
#endif
	fprintf(f, "set xtics (");
	i = 0; j = 0;
	while (i < nlabels) {
	    xent = lookat(plot->rge[0].sr + j, plot->rge[0].sc);
	    if (xent->label && j % plot->labelskip == 0) {
		fprintf(f, "\"%s\" %d", xent->label, j);
		if (i < nlabels - 1)
		    fprintf(f, ", ");
		i++;
	    }
	    j++;
	}
	fprintf(f, ")\n");
    }

    fprintf(f, "plot \\\n");
    count = 1;
    for (i=1; i<N_RANGES; i++) {
	if (plot->rge[i].ec == -1) continue;
	/* pick up legends */
	if (plot->legend[i-1][0] != '\0')
	    sprintf(legend, "t '%s'", plot->legend[i-1]);
	else
	    strcpy(legend, "t ''");
	/* lines, points */
	if (plot->format[i] == 'L') 
	    strcpy(withstr, "w lines");
	else if (plot->format[i] == 'S')
	    strcpy(withstr, "w points");
	else if (plot->format[i] == 'B')
	    strcpy(withstr, "w linespoints");
	if (plot->type == 'X')
	    fprintf(f, "'-' using 1:2 %s %s", legend, withstr);
	else
	    fprintf(f, "'-' %s %s", legend, withstr);	    
	fprintf(f, (count++ < plot->nlines)? ", \\\n" : "\n"); 
    }

    for (i=1; i<N_RANGES; i++) {
	if (plot->rge[i].ec == -1) continue;
	if (plot->type == 'X') {
	    for (j=plot->rge[0].sr, k=plot->rge[i].sr;
		 j<=plot->rge[0].er && k<=plot->rge[i].er; 
		 j++, k++) {
		xent = lookat(j, plot->rge[0].sc);
		yent = lookat(j, plot->rge[i].sc);
		if ((xent->flags & is_valid) && (yent->flags & is_valid))    
		    fprintf(f, "%g %g\n", xent->v, yent->v);
	    }
	}
	else if (plot->type == 'L') {
	    for (j=plot->rge[i].sr; j<=plot->rge[i].er; j++) {
		yent = lookat(j, plot->rge[i].sc);
		if (yent->flags & is_valid)
		    fprintf(f, "%g\n", yent->v);
	    }
	}
	fprintf(f, "e\n");
    }
 
    fclose(f);
}

