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

#include "plot.h"

static unsigned maxtics = MAXTICS;  /* might make this controllable */

#ifndef VR3
#include "pattern.h" /* for bar charts only */
/*
 * This structure forms the WM_HINTS property of the window,
 * letting the window manager know how to handle this window.
 * See Section 9.1 of the Xlib manual.
 */
XWMHints hints = {
    (InputHint|StateHint),   /* flags         */
    False,                   /* input         */
    NormalState,             /* initial_state */
    0,                       /* icon pixmap   */
    0,                       /* icon window   */
    0, 0,                    /* icon location */
    0,                       /* icon mask     */
    0,                       /* Window group  */
};
#endif /* not VR3 */

static void do_titles(struct graph *plot, GC gcontext, Window win);

static double
Lpow10(double p)
{
    double q;
 
    p = floor(p);
    if (p >= 0) {
	for (q = 1; p > 0; --p)
	    q = q * 10;
    }
    else {
	p = -p;
	for (q = 1; p > 0; --p)
	    q = q / 10;
    }
    return q;
}

extern int white;

#ifdef VR3 /* turn graphs sideways on agenda vr3 */

#include <X11/xpm.h>
#include "pixmaps/fivebyseven.xpm"

#define CHARWD 5
#define CHARHT 7

static Pixmap backbuf, pix_text, mask_text;
static GC gc_text;
extern int black;

static void 
drawtext(Display *dpy, Drawable d, GC gc, 
	 int x, int y, char *text, int len)
{
    int i;
    int winx = GWIN_H - CHARHT - y, winy = x;

    for (i=0; i<len; i++) {
	if (text[i] >= '!' && text[i] <= '~') {
	    XSetClipOrigin(dpy, gc_text, winx, winy);
	    XCopyArea(dpy, pix_text, backbuf, gc_text,
		      0, (text[i] - '!') * CHARWD, CHARHT, CHARWD, 
		      winx, winy);
	}
	winy += CHARWD;
    }
}

static void 
flip_translate(int *x, int *y)
{
    int tmp = *y;

    *y = *x;
    *x = GWIN_H - tmp;
}

static void 
drawline(Display *dpy, Drawable d, GC gc,
	 int x1, int y1, int x2, int y2)
{
    flip_translate(&x1, &y1);
    flip_translate(&x2, &y2);
    XDrawLine(dpy, backbuf, gc, x1, y1, x2, y2);
}

static void 
drawlines(Display *dpy, Drawable d, GC gc,
	  XPoint *points, int npoints, int mode)
{
    int i, x, y;

    for (i=0; i<npoints; i++) {
	x = points[i].x;
	y = points[i].y;
	flip_translate(&x, &y);
	points[i].x = (short) x;
	points[i].y = (short) y;
    }
    XDrawLines(dpy, backbuf, gc, points, npoints, mode);
}

#else /* not VR3 */
#define drawtext(dpy, d, gc, x, y, str, len) \
    XDrawImageString(dpy, d, gc, x, y, str, len)
#define drawline(dpy, d, gc, x1, y1, x2, y2) \
    XDrawLine(dpy, d, gc, x1, y1, x2, y2)
#define drawlines(dpy, d, gc, points, npoints, mode) \
    XDrawLines(dpy, d, gc, points, npoints, mode)
#endif /* end not VR3 */


/* --------- some common drawing functions ------------- */

static void 
DrawOpenDiamond(short x, short y, GC gcontext, Window win)
{
    XPoint points[5];

    points[0].x = points[2].x = points[4].x = x; 
    points[0].y = points[4].y = y - 3; 
    points[1].x = x + 3;
    points[1].y = points[3].y = y;
    points[2].y = y + 3;
    points[3].x = x - 3;

    drawlines(dpy, win, gcontext, points, 5, CoordModeOrigin);
}

static void 
DrawOpenSquare(short x, short y, GC gcontext, Window win)
{
    XPoint points[5];

    points[0].x = points[3].x = points[4].x = x - 2; 
    points[0].y = points[1].y = points[4].y = y - 2; 
    points[1].x = points[2].x = x + 2;
    points[2].y = points[3].y = y + 2;

    drawlines(dpy, win, gcontext, points, 5, CoordModeOrigin);
}

static void 
DrawOpenTriangle(short x, short y, GC gcontext, Window win)
{ 
    XPoint points[4];

    points[0].x = points[3].x = x; 
    points[0].y = points[3].y = y - 3; 
    points[1].x = x + 2;
    points[1].y = y + 2;
    points[2].x = x - 2; 
    points[2].y = y + 2; 

    drawlines(dpy, win, gcontext, points, 4, CoordModeOrigin);
}

static void 
DrawCross(short x, short y, GC gcontext, Window win)
{
    XPoint points[6];

    points[0].x = points[3].x = points[4].x = points[5].x = x; 
    points[0].y = points[1].y = points[2].y = points[3].y = y; 
    points[1].x = x - 2;
    points[2].x = x + 2;
    points[4].y = y - 2;
    points[5].y = y + 2;

    drawlines(dpy, win, gcontext, points, 6, CoordModeOrigin);
}

static void
DrawSymbol(short x, short y, GC gcontext, Window win, int i)
{
    switch (i) {
    case 0: 
	DrawOpenSquare(x, y, gcontext, win); 	
	break;
    case 1: 
	DrawOpenTriangle(x, y, gcontext, win); 	
	break;
    case 2: 
	DrawOpenDiamond(x, y, gcontext, win); 	
	break;
    case 3: 
	DrawCross(x, y, gcontext, win); 
	break;
    }
}

#ifdef VR3
static void 
backbuf_init(Window win)
{
    GC whitegc;
    XGCValues vals;

    backbuf = XCreatePixmap(dpy, win, GWIN_H, GWIN_W,
			    DefaultDepthOfScreen(DefaultScreenOfDisplay(dpy)));

    /* Create graphics contexts */
    vals.foreground = white;
    vals.background = black;
    whitegc = XCreateGC(dpy, win, GCForeground | GCBackground,
			&vals);

    /* Text */
    XpmCreatePixmapFromData(dpy, win,
			    text_xpm, &pix_text, &mask_text, NULL);
    vals.foreground = white;
    vals.background = black;
    vals.graphics_exposures = False;
    gc_text = XCreateGC(dpy, win,
			GCForeground | GCBackground | GCGraphicsExposures,
			&vals);
    XSetClipMask(dpy, gc_text, mask_text);

    XFillRectangle(dpy, backbuf, whitegc, 0, 0, GWIN_H, GWIN_W);
    XCopyArea(dpy, backbuf, win, maingc, 0, 0, GWIN_H, GWIN_W, 0, 0);
}
#endif

Window 
makewin(GC gcontext, char *title, int width, int height)
{
    XGCValues vals;
    Window win;
    XSizeHints xsh;
    unsigned long bw = 1;

    XGetGCValues(dpy, gcontext, GCForeground | GCBackground, &vals);

    xsh.flags = (PPosition | PSize);
#ifdef VR3
    xsh.height = width; 
    xsh.width = height; 
#else
    xsh.height = height; 
    xsh.width = width; 
#endif

    xsh.x = (DisplayWidth(dpy, DefaultScreen(dpy)) - xsh.width) / 2;
    xsh.y = (DisplayHeight(dpy, DefaultScreen(dpy)) - xsh.height) / 2;

    win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy),
			      xsh.x, xsh.y, xsh.width, xsh.height,
			      bw, white, vals.background);

    XSetStandardProperties(dpy, win, title, title, 
			   None, NULL, 0, &xsh);
#ifndef VR3
    XSetWMHints(dpy, win, &hints);
#endif

    xswa.colormap = DefaultColormap(dpy, DefaultScreen(dpy));
    xswa.bit_gravity = CenterGravity;
    XChangeWindowAttributes(dpy, win, (CWColormap | CWBitGravity), &xswa);

    XMapWindow(dpy, win);

    if (XGetWindowAttributes(dpy, win, &xwa) == 0) 
	return 0L;    

    XClearWindow(dpy, win);
    XSelectInput(dpy, win, ButtonPressMask | KeyPressMask | ExposureMask);

#ifdef VR3
    backbuf_init(win);
#endif

    return win;
}

static void
get_grid_xy(char g_grid, int *x, int *y)
{
    if (g_grid == 'H') { /* horizontal grid */
	*x = RECT_W;
	*y = TICKLEN;
    } else if (g_grid == 'V') { /* vertical grid */
	*x = TICKLEN;
	*y = RECT_H;
    } else if (g_grid == 'B') { /* both */
	*x = RECT_W;
	*y = RECT_H;
    } else {
	*x = TICKLEN; /* no grid */
	*y = TICKLEN;
    }
}

static int
draw_box_etc(struct graph *plot, 
	     double y_max,
	     double y_range,
	     double x_max,
	     double x_range,
	     unsigned n_items,
	     GC gcontext,
	     Window win)
{
    int grid_l_x, grid_l_y, grid_w = 0, grid_h;
    int i, x, y, len, xtics, ytics, text_w = 0;
    char str[32];

    /* Draw the outer box */
#ifdef VR3
    XDrawRectangle(dpy, backbuf, gcontext, GWIN_H - RECT_H - RECT_Y, RECT_X, 
		   RECT_H, RECT_W); 
#else
    XDrawRectangle(dpy, win, gcontext, RECT_X, RECT_Y, RECT_W, RECT_H); 
#endif

    /* Are we doing an XY scatter or a lines plot? */
    if (plot->type == 'X')  
	xtics = maxtics;
    else  /* lines plot */
	xtics = n_items + 1; 
    ytics = maxtics;

    grid_w = RECT_W / xtics;
    grid_h = RECT_H / ytics;

    /* draw the y-axis ticks/grid and numeric labels */
    get_grid_xy(plot->grid, &grid_l_x, &grid_l_y);
    for (i=0; i<=ytics; i++) {
	y = RECT_Y + i * grid_h;
	drawline(dpy, win, gcontext, 
		 RECT_X, y,
		 RECT_X + grid_l_x, y);
	drawline(dpy, win, gcontext, 
		 RECT_X + RECT_W, y,
		 RECT_X + RECT_W - grid_l_x, y);
	sprintf(str, "%.1f", (y_max - y_range * i / ytics));
	len = strlen(str);
	text_w = XTextWidth(curfont, str, len + G_YOFFSET);
#ifdef VR3
	drawtext(dpy, win, gcontext,
		 RECT_X - text_w,
		 y - curfontheight / 3,
		 str, len);
#else
	drawtext(dpy, win, gcontext,
		 RECT_X - text_w,
		 y + curfontheight / 3,
		 str, len);
#endif
    }

    /* x-axis tick marks and labels (X-Y scatter only) */
    if (plot->type == 'X') {
	for (i=0; i<=xtics; i++) { 
	    x = RECT_X + i * grid_w;
	    drawline(dpy, win, gcontext, 
		     x, RECT_Y, 
		     x, RECT_Y + grid_l_y); 
	    drawline(dpy, win, gcontext, 
		     x, RECT_Y + RECT_H, 
		     x, RECT_Y + RECT_H - grid_l_y);
	    sprintf(str, "%.1f", x_max - x_range * i / xtics);
	    len = strlen(str);
	    text_w = XTextWidth(curfont, str, len);
	    drawtext(dpy, win, gcontext,
		     RECT_X + RECT_W - i*grid_w - text_w / 2,
		     G_XOFFSET, 
		     str, len);
	}
    }

    do_titles(plot, gcontext, win);

    return grid_w;
}

static void 
do_titles(struct graph *plot, GC gcontext, Window win)
{
    int i, len, x, text_w = 0;
    int ypos[4] = {
	RECT_Y / 3,
	RECT_Y * 2 / 3,
	RECT_H + RECT_Y * 3 / 2,
	RECT_Y - curfontheight
    };

    for (i=0; i<4; i++) {
	if (i < 3) x = (GWIN_W - text_w) / 2;
	else x = (RECT_X - text_w < 0)? curfontwidth : RECT_X - text_w;
	len = strlen(plot->title[i]); 
	text_w = XTextWidth(curfont, plot->title[i], len);
	drawtext(dpy, win, gcontext, x, ypos[i],
		 plot->title[i], len);
    }
}

static void
do_yrange(struct graph *plot, double *y_min, double *y_max)
{
    int i, j, first_y_datum = 1;
    struct ent *p;

    if (plot->scale[1][0] != 0.0 || plot->scale[1][1] != 0.0) {
        *y_min = plot->scale[1][0];
        *y_max = plot->scale[1][1];
	plot->auto_man[1] = 'M';
    } else {
        first_y_datum = 1;
	for (j=1; j<N_RANGES; j++) { 
	    if (plot->rge[j].ec == -1) continue;
	    for (i=plot->rge[j].sr; i<=plot->rge[j].er; i++) { 
		p = lookat(i, plot->rge[j].sc);
		if (!(p->flags & is_valid)) continue; /* ignore invalid */
		if (first_y_datum) {
		    *y_max = p->v;
		    *y_min = p->v;
		    first_y_datum = 0;
		} else {
		    *y_max = Max(*y_max, p->v); 
		    *y_min = Min(*y_min, p->v);
		}
	    }
        }
    }
}

static void
get_max_min(double *z_min, double *z_max, double *z_range)
{
    double z_power;

    if (*z_min == *z_max) {
	*z_max = 1.01 * (*z_max);
	*z_min = 0.99 * (*z_min);
    }
    z_power = - floor(log10((*z_max - *z_min)));
    z_power = Lpow10(z_power);
    *z_min = floor(*z_min * z_power) / z_power;
    *z_max = ceil(*z_max * z_power) / z_power;
    *z_range = *z_max - *z_min;
}

static void 
draw_legends(struct graph *plot, GC gcontext, Window win)
{
    int i, x, len, text_w, legend_n = 0;
    int y = RECT_Y * 7 / 4 + RECT_H;

    /* draw legend symbols and strings */
    for (i=1; i<N_RANGES; i++) {
	if (plot->rge[i].ec == -1 || plot->nlines < 1 || 
	    plot->legend[i-1][0] == '\0') 
	    continue; 

	len = strlen(plot->legend[i-1]);
	text_w = XTextWidth(curfont, plot->legend[i-1], len);

	if (plot->nlines == 1) 
	    x = RECT_X + (RECT_W - text_w) / 2 - 10;
	else
	    x = RECT_X/2 + legend_n * (GWIN_W/plot->nlines - 10) - 10;

	if (plot->format[i] == 'L' || plot->format[i] == 'B') 
	    drawline(dpy, win, gcontext, x-5, y, x+5, y); 
	if (plot->format[i] == 'S' || plot->format[i] == 'B')
	    DrawSymbol(x, y, gcontext, win, i-1);
	drawtext(dpy, win, gcontext, x+10, y,
		 plot->legend[i-1], len);
	
	if (plot->nlines == 1) break;

	legend_n++;
    }
}

void 
plot_XY(struct graph *plot, GC gcontext)
{
    double x_max = 0, x_min = 0, y_max = 0, y_min = 0; 
    double x_range, y_range;
    int i, j, k;
    int x, y, x1 = 0, y1 = 0;
    int looping = 1;     /* true if we shouldn't exit yet */
    int draw = 1;        /* true if we should paint the window */
    char format;         /* graph format specifier, (L)ine, (S)ymbol, (B)oth */
    int first_point;     /* true when getting coords for 1st point in curve */
    struct ent *p;
    struct ent *xent, *yent;  /* table entries for x and y values */
    int cells = 0; 
    int first_x_datum = 1;
    Window win;

    /* check that we have enough valid x values.  While we are looping,
     * determine the minimum and maximum x values, in case we need them
     */
    for (i=plot->rge[0].sr; i<=plot->rge[0].er; i++) { 
	p = lookat(i, plot->rge[0].sc);
	if (!(p->flags & is_valid)) continue;
	cells++;
	if (first_x_datum) {
	    x_max = p->v;
	    x_min = p->v;
	    first_x_datum = 0;
	} else {
	    x_max = Max(x_max, p->v); 
	    x_min = Min(x_min, p->v);
	}
    } 

    if (cells < 2) {
	message("Not enough valid X values");
	return;
    }

    /* if x-scale is manual, override limits calculated above */
    if (plot->scale[0][0] != 0.0 || plot->scale[0][1] != 0.0) {
	plot->auto_man[0] = 'M';
	x_max = plot->scale[0][1];
	x_min = plot->scale[0][0];
    }

    do_yrange(plot, &y_min, &y_max);
    get_max_min(&x_min, &x_max, &x_range);
    get_max_min(&y_min, &y_max, &y_range);

    win = makewin(gcontext, "xspread plot", GWIN_W, GWIN_H);

    if (win == 0L) return;

    while (looping) {
	XEvent event;

	XNextEvent(dpy, &event);
	switch (event.type) {
	case KeyPress: 
	case ButtonPress: looping = 0; 
	    break;
	case Expose: draw = 1;
	}

	/* if not drawing, go back and get another event */
	if (!draw) continue;

	/* draw outer box plus tics (or grid) and titles */
	(void) draw_box_etc(plot, 
			    y_max, y_range, 
			    x_max, x_range,
			    0, gcontext, win);

	draw_legends(plot, gcontext, win);

	/* Draw curves */
	for (i=1; i<N_RANGES; i++) { 
	    if (plot->rge[i].ec == -1) continue;
	   
	    first_point = 1;
	    format = plot->format[i];

	    for (j=plot->rge[0].sr, k=plot->rge[i].sr;
		 j<=plot->rge[0].er && k<=plot->rge[i].er; j++, k++) {

		xent = lookat(j, plot->rge[0].sc);
		if (!(xent->flags & is_valid) || xent->v < x_min 
		    || xent->v > x_max)
		    continue;
		yent = lookat(j, plot->rge[i].sc);
		if (!(yent->flags & is_valid) || yent->v < y_min 
		    || yent->v > y_max)
		    continue;

		if (first_point) {
		    x1 = RECT_X + RECT_W * (xent->v - x_min) / x_range;  
		    y1 = RECT_Y + RECT_H - RECT_H * (yent->v - y_min) / y_range;   
		    if (format == 'S' || format == 'B')
			DrawSymbol(x1, y1, gcontext, win, i-1);
		    first_point = 0;
		    continue;
		}

		x = RECT_X + RECT_W * (xent->v - x_min) / x_range;   
		y = RECT_Y + RECT_H - RECT_H * (yent->v - y_min) / y_range;   

		if (format == 'L' || format == 'B') 
		    drawline(dpy, win, gcontext, x1, y1, x, y);
		if (format == 'S' || format == 'B') 
		    DrawSymbol(x, y, gcontext, win, i-1);
		x1 = x;
		y1 = y;
	    }
	}
#ifdef VR3
	XSync(dpy, 0); 
	XCopyArea(dpy, backbuf, win, maingc, 0, 0, GWIN_H, GWIN_W, 0, 0);
	XFlush(dpy);
#endif
	draw = 0;
    }  /* end of while */
    XUnmapWindow(dpy, win);
    XDestroyWindow(dpy, win);
} 

#ifdef VR3
# define PIX_SEP 2
#else
# define PIX_SEP 3
#endif

void
plot_line(struct graph *plot, GC gcontext)
{   
    double y_max = 0, y_min = 0; 
    double y_range;
    double grid_w, data_w;
    int i, j, len;
    int text_w;
    int x, y, x1 = 0, y1 = 0;
    int looping = 1;   /* true if we shouldn't exit yet                    */
    int draw = 1;      /* true if we should paint the window               */
    char format;       /* graph format specifier, (L)ine, (S)ymbol, (B)oth */
    int first_point;   /* true when getting coords for 1st point in curve  */
    struct ent *p;
    struct ent *yent;  /* table entries y values                           */
    int items = 0;
    int n_items = 0;
    int width;         /* used to calculate the Labelsize */
    int labelsize;     /* The size of the Label to be drawn */
    int maxitems;
    int labelskip = 1;
    int autolabel = 0;
    char str[100];
    Window win;

    /* check that we have enough valid x values.  While we are looping,
     * determine the minimum and maximum x values, in case we need them
     */
#ifdef VR3
    maxitems = 4;
#else
    maxitems = 6;
#endif

    if (plot->rge[0].ec == -1) { /* no x range given */
	autolabel = 1;
	n_items = plot->rge[1].er - plot->rge[1].sr + 1;
    } else { /* x label range was specified */
	for (i=plot->rge[0].sr; i<=plot->rge[0].er; i++) { 
	    p = lookat(i, plot->rge[0].sc);
	    if (!(p->label)) continue;
	    n_items++;
	} 
	if (n_items < 2) {
	    message("Not enough valid X labels");
	    return;
	}
    }

    if (n_items > maxitems)  /* can't use all the x-labels */
	labelskip = (double) n_items / maxitems;
    else 
	maxitems = n_items;

    plot->labelskip = labelskip;
    do_yrange(plot, &y_min, &y_max);
    get_max_min(&y_min, &y_max, &y_range);

    win = makewin(gcontext, "xspread plot", GWIN_W, GWIN_H);

    if (win == 0L) return;

    while (looping) {
	XEvent event;

	XNextEvent(dpy,&event);
	switch (event.type) {
	case KeyPress: 
	case ButtonPress: looping = 0; 
	    break;
	case Expose: draw = 1;
	}

	if (!draw) continue;

	/* draw outer box plus tics (or grid) and titles */
	grid_w = draw_box_etc(plot, 
			      y_max, y_range, 
			      0, 0,
			      maxitems, gcontext, win);

	/* draw x-axis labels */
	width = (RECT_W - PIX_SEP * (maxitems + 1))/maxitems;
	if (width > 0) 
	    labelsize = irint(floor(width/(double) curfontwidth) - 1);
	else
	    labelsize = 0;

	data_w = RECT_W / n_items;

	if (labelsize > 0 && labelsize < 100) { /* sanity check */
	    first_point = 1;
	    y = RECT_Y + RECT_H + curfontheight;
	    for (i=0; i<n_items; i++) {
		if (i % labelskip) continue;
		if (autolabel) 
		    sprintf(str, "%d", i+1);
		else {
		    p = lookat(plot->rge[0].sr + i, plot->rge[0].sc);
		    if (!(p->label)) 
			continue;
		    strncpy(str, p->label, labelsize); 
		    str[labelsize] = '\0';
		}
		len = strlen(str);
		text_w = XTextWidth(curfont, str, len);
		
		if (first_point) {
		    x1 = RECT_X + data_w;
		    first_point = 0;
		} else
		    x1 += data_w * labelskip;

		x = x1 - text_w / 2;
		drawtext(dpy, win, gcontext,
			 x, y, str, len);
		drawline(dpy, win, gcontext, 
			 x1, RECT_Y, 
			 x1, RECT_Y + TICKLEN); 
		drawline(dpy, win, gcontext, 
			 x1, RECT_Y + RECT_H, 
			 x1, RECT_Y + RECT_H - TICKLEN);
	    }
	} 

	draw_legends(plot, gcontext, win);

	/* Draw curves */
	for (i=1; i<N_RANGES; i++) { 
	    if (plot->rge[i].ec == -1) continue;
	   
	    first_point = 1;
	    format = plot->format[i];
	    items = 0; 

	    for (j=plot->rge[i].sr; j<=plot->rge[i].er; j++) {

		x = RECT_X + data_w * ++items;

		yent = lookat(j, plot->rge[i].sc);
		if (!(yent->flags & is_valid) || yent->v < y_min 
		    || yent->v > y_max)
		    continue;

		if (first_point) {
		    x1 = x;
		    y1 = RECT_Y + RECT_H - RECT_H * (yent->v - y_min) / y_range;   
		    if ((format == 'S') || (format == 'B'))
			DrawSymbol(x1, y1, gcontext, win, i-1);
		    first_point = 0;
		    continue;
		}

		y = RECT_Y + RECT_H - RECT_H * (yent->v - y_min) / y_range;   
		if ((format == 'L') || (format == 'B')) 
		    drawline(dpy, win, gcontext, x1, y1, x, y);
		if ((format == 'S') || (format == 'B'))
		    DrawSymbol(x, y, gcontext, win, i-1);
		x1 = x;
		y1 = y;
	    }
	} 
#ifdef VR3
	XSync(dpy, 0);
	XCopyArea(dpy, backbuf, win, maingc, 0, 0, GWIN_H, GWIN_W, 0, 0);
	XFlush(dpy);
#endif
	draw = 0;
    }  /* end of while */
    XUnmapWindow(dpy, win);
    XDestroyWindow(dpy, win);
} 

#ifndef VR3  /* can't make legible bar charts on agenda! */

#define BAR_SEP 8   /* The distance between each group of bars */

static void
get_pattern(Pixmap *Pattern, Window win, int i)
{
    *Pattern = XCreateBitmapFromData(dpy, win, 
				     (i == 1)? white_bits :
				     (i == 2)? gray1_bits :
				     (i == 3)? gray2_bits :
				     gray3_bits,
				     g_pattern_len[i],
				     g_pattern_len[i]);
}

void
plot_bar(struct graph *plot, GC gcontext)
{ 
    double y_max = 0;  /* Maximum Y value                   */
    double y_min = 0;  /* Minimum Y value                   */
    double y_range;    

    int i, j, k;       /* Iteration variables               */
    int len;           /* Length of a Label                 */
    int grid_l_x;      /* Size of grid separators           */ 
    int grid_l_y;
    int grid_h;
    char str[100];     /* The Label to be drawn             */
    int height,width;  /* Height and Width of the bar       */
    int text_w;        /* Text width variable               */
    int x, y;          /* Current x and y position          */
    struct ent *p;
    int looping = 1;   /* Continue looping flag             */
    int draw = 0;      /* Continue drawing flag             */
    int first_bar = 1; /* The first bar flag                */
    int num_rows = 0;  /* The number of rows to be drawn    */
    int num_cols = 0;  /* The number of columns to be drawn */
    int row;           /* The current row position          */
    int bars;          /* The current bar being processed   */
    int labelsize;     /* The size of the Label             */
    Pixmap Pattern = 0;    /* The type of pattern to display */
    Window win;

    bars = 0;
    for (i=plot->rge[0].sr; i<=plot->rge[0].er; i++) { 
	p = lookat(i, plot->rge[0].sc);
	if (!(p->label)) {
	    continue;
	}
	bars++;
    }

    if (bars < 1) {
	message("Not enough valid X labels");
	return;
    }

    if (plot->scale[1][0] != 0.0 || plot->scale[1][1] != 0.0) {
	plot->auto_man[1] = 'M';
	y_max = plot->scale[1][1];
	y_min = plot->scale[1][0];
    } else {
	for (j=1; j<N_RANGES; j++) {
	    if (plot->rge[j].ec == -1) 
		continue; 
	    else 
		num_cols++;
	    row = 0;
	    for (i=plot->rge[j].sr; i<=plot->rge[j].er; i++) {
		p = lookat(i, plot->rge[j].sc);
		if (!(p->flags & is_valid)) continue;
		row++; 
                
		if (first_bar) {
		    y_max = p->v; /* find the maximum y value */
		    y_min = p->v; /* find the minimum y value */
		    first_bar = 0;
		} else {
		    y_max = Max(y_max, p->v);
		    y_min = Min(y_min, p->v);
		}
		num_rows = Max(row,num_rows); 
	    }
	}
	y_min -= 0.1*(fabs(y_min)); /* so smallest bar shows */ 
    }
    y_min = floor(y_min);
    y_max = ceil(y_max);

    win = makewin(gcontext, "xspread plot", GWIN_W, GWIN_H);
    if (win == 0L) return;

    while (looping) {
	XEvent event;

	XNextEvent(dpy,&event);
	switch(event.type) {
	case KeyPress:
	case ButtonPress: looping = 0;
	    break;
	case Expose: draw = 1;
	}
		       
	if (!draw) continue;

	XDrawRectangle(dpy, win, gcontext, RECT_X, RECT_Y, RECT_W, RECT_H);
     
	/* ----------------------------------------------------------------  */
	/* This next section will draw the grid on which the bar graphs will */
	/* be drawn and will display the title of the graph as well as       */
	/* label the x and y axis. Written by Georgiane Kondich    Aug 1990  */
	/*                                                                   */
	/* Modified 12/10/91 - Dan Gruber.  This graph now displays a value  */
	/*                     for each tick mark on the Y Axis.             */
	/* ----------------------------------------------------------------- */
	/*
	 * grid_l_x and grid_l_y are the length of the grid lines  
	 * to be drawn.  They have a value of '0' if no grids are 
	 * drawn.
	 */

	get_grid_xy(plot->grid, &grid_l_x, &grid_l_y);

	grid_h = RECT_H / 10;
	y_range = y_max - y_min;

	/* Calculate the width of a single bar */
	width = (RECT_W - BAR_SEP*num_rows) / (num_cols*num_rows);
	 
	/* Draw the grid plus y-axis labels */
	for (i=0; i<11; i++) {
	    if (i > 0 && i < 10)
		drawline(dpy,win,gcontext,
			 RECT_X-4, RECT_Y+i*grid_h,
			 RECT_X, RECT_Y+i*grid_h);
	    drawline(dpy,win,gcontext,
		     RECT_X, RECT_Y+i*grid_h,
		     RECT_X+grid_l_x, RECT_Y+i*grid_h);
	    drawline(dpy,win,gcontext,
		     RECT_X + RECT_W,RECT_Y+i*grid_h,
		     RECT_X+RECT_W - grid_l_x, RECT_Y+i*grid_h);

	    sprintf(str,"%.1f",(y_max - y_range*i/10));
	    len = strlen(str);
	    text_w = XTextWidth(curfont,str,len+2);
	    drawtext(dpy,win,gcontext,
		     RECT_X - text_w,
		     RECT_Y + i*grid_h + curfontheight/3,
		     str, len);
	} 
           
	for (i=1; i<num_rows; i++) { 
	    x = RECT_X + BAR_SEP*i + i*width*(num_cols);
	    drawline(dpy,win,gcontext,
		     x, RECT_Y, x, RECT_Y+grid_l_y);
	    drawline(dpy,win,gcontext,
		     x, RECT_Y + RECT_H, x, RECT_Y + RECT_H - grid_l_y);
	} 

	do_titles(plot, gcontext, win);

	/* --------------------------------------------------------------------*/
	/* This next section will read values of the x and y center points     */
	/* and find the maximum and minimum values for each, then set the      */
	/* width and height paramters, convert x and y so that the origin      */
	/* is at the lower left corner of the window, and then finally         */
	/* draw and fill the bars.                                             */
	/* ------------------------------------------------------------------- */

	/* Draw Labels */
	labelsize = irint(floor((width*num_cols)/(double)curfontwidth) -1);
	y = RECT_Y + RECT_H + curfontheight;
	bars = 0;
	for (i=plot->rge[0].sr; i<=plot->rge[0].er; i++) {
	    p = lookat(i, plot->rge[0].sc);
	    if (!(p->label)) continue;
	    bars++;
	    strncpy(str, p->label, labelsize);
	    str[labelsize] = '\0';
	    len = strlen(str);
	    text_w = XTextWidth(curfont, str, len);
	    x = RECT_X+ BAR_SEP*(bars-1)+width*(bars-1)*num_cols;
	    x = x + (width*num_cols/2) - (text_w / 2); 
	    drawtext(dpy, win, gcontext, x, y,
		     str, strlen(str));
	}

	/* Now draw the bars, with a different pattern for 
	   each column of data */
	for (i=1; i<N_RANGES; i++) {
	    if (plot->rge[i].ec == -1) continue;
	    row = 0;
	    for (j=plot->rge[0].sr, k=plot->rge[i].sr;
		 j<=plot->rge[0].er && k<=plot->rge[i].er; j++, k++) {
		row++;
		if (!((p=lookat(j, plot->rge[0].sc))->label)) continue;
                 
		x = RECT_X+(row-1)*(BAR_SEP)+(row-1)*(num_cols)*width+width*(i-1);

		if (!((p=lookat(j, plot->rge[i].sc))->flags & is_valid) 
		    || (p->v < y_min) || (p->v > y_max)) continue;

		height = irint((p->v - y_min) / y_range * RECT_H);

		y = RECT_Y + RECT_H - height;  

		/* If there are grids to be drawn, clear the area before
		   the bar is drawn */
		if (plot->grid != 'C')
		    XClearArea(dpy, win, x, y, width, height, False);

		get_pattern(&Pattern, win, i);

		/* Draw the bar with a filled pattern */
		XSetStipple(dpy, gcontext, Pattern);
		XSetFillStyle(dpy, gcontext, FillStippled);
		XFillRectangle(dpy, win, gcontext, x, y, width, height);

		/* Outline the bar with a solid rectangle */
		XSetFillStyle(dpy, gcontext, FillSolid);
		XDrawRectangle(dpy, win, gcontext, x, y, width, height);
	    }
	}
    }
    XUnmapWindow(dpy, win);
    XDestroyWindow(dpy, win);
}

#endif /* VR3 -- no bar charts */
