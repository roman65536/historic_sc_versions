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

#ifndef PLOT_H
#define PLOT_H

#include <math.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "config.h"
#include "sc.h"
#include "scXstuff.h"

#define Max(a, b) ((a)>(b) ? (a) : (b))
#define Min(a, b) ((a)<(b) ? (a) : (b))

#define N_RANGES      5  /* distinct data ranges allowed */
#define N_TITLES      4  /* title, subtitle and axis labels */
#define GMAXLEN      40  /* max length of graph title strings */

#ifdef VR3 /* tiny, landscape plot */
# define RECT_X   32
# define RECT_Y   8
# define RECT_W   192
# define RECT_H   134
# define GWIN_W   240
# define GWIN_H   160
# define G_YOFFSET   0.   /* offset for drawing y-axis tic labels */
# define G_XOFFSET  148.   /* offset for drawing x-axis tic labels */
# define MAXTICS  4
# define TICKLEN  3
#else /* normal size */
# define RECT_X   100
# define RECT_Y   100
# define RECT_W   450
# define RECT_H   350
# define GWIN_W   650
# define GWIN_H   550
# define G_YOFFSET 2
# define G_XOFFSET (RECT_H + RECT_Y * 7/6)  
# define MAXTICS  5
# define TICKLEN  8
#endif 

#ifndef irint
#define irint(x) floor((x)+0.5)
#endif

extern XSetWindowAttributes xswa;  /* Temporary Set Window Attribute struct */
extern XWindowAttributes xwa;	   /* Temporary Window Attribute struct */

struct graph {
    char type;
    char grid;
    char auto_man[2];
    char legend[N_RANGES-1][42];
    char format[N_RANGES];
    char title[N_TITLES][42];
    unsigned nlines;
    double scale[2][2];
    struct m_range rge[N_RANGES];
    int labelskip;
};

void message(const char *x);
void graph_init(struct graph *plot); 
void Graph_Menu(struct graph *plot); 
void plot_XY(struct graph *plot, GC gcontext);
void plot_line(struct graph *plot, GC gcontext);
void plot_bar(struct graph *plot, GC gcontext);

void read_plot_options(FILE *f, struct graph *plot);
void print_plot_options(FILE *f, struct graph *plot);

#endif /* PLOT_H */
