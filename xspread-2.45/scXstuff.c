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
 * This is a modification of a program written or modified by
 * others.  The original copyrights, as per GNU General Public License,
 * may still be applicable.  The UWM copyright is applicable only
 * the those parts generated at UWM.
 *
 * Please send all changes, enhancements, and other comments about this
 * software to
 *     		soft-eng@cs.uwm.edu
 *
 * No Warranty, expressed or implied, comes with this software.
 * This software is intended to be used by not-for-profit
 * organizations. Selling this software for profit without
 * the permission of the Board of Regents of the University
 * of Wisconsin is strictly forbidden. 
 *
 * Contact:	soft-eng@cs.uwm.edu
 *			or
 *		
 *		Software Engineering Coordinator
 *		Computer Science
 *    		Department of EECS
 *		University of Wisconsin - Milwaukee
 *		Milwaukee, WI  53201
 *		414-229-4677
 *
 *		HISTORY,CLAIMS and CONTRIBUTIONS
 */

/**********************************************************************
*                                                                    *
*      Error rountine modified by Mike Frey and Jim Cornelius.       *       
*                                              Fall, 1991            *
**********************************************************************/
/* scXstuff.c
This file contains the code for initializing and keeping track of basic
X-Windows information such as fonts, the size of the window, etc.  Functions
and macros are explained as they are presented.  */

/* REVISION HISTORY */
/* 7-19-91  B. Backman Creation */

#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>  
#include "sc.h"

unsigned long white, black;     /* white and black pixels */
unsigned long gray;
unsigned long bw;         	/* border width */
XGCValues gcv;         	  	/* struct for creating GC */
XSizeHints xsh;  		/* size hints for window manager */
XSetWindowAttributes xswa;	/* Temporary Set Window Attribute struct */
XWindowAttributes xwa;	        /* Temporary Window Attribute struct */

/* The following variables are declared in scXstuff.h */
Display *dpy;            /* X server (workstation) connection */
Window mainwin;          /* resource ID of main window */
GC maingc,               /* GC for mainwin */
    maingcreversed,      /* Reverse-field GC for mainwin */
    invertgc,		 /* (invert) reverse-field GC for mainwin */
    graygc;              /* for grid lines */
XFontStruct *curfont;    /* Font descriptor struct for current font */
Font curfontid;          /* resource id of current font */
int curfontwidth,
    curfontheight;       /* pixel dimensions of current font */
char *userfont;          /* User-specifed font from command line */

void 
error(const char *errstring)
{
    clearlines(1, 1);
    XDrawImageString(dpy, mainwin, maingc,
		     textcol(0), textrow(1),
		     errstring, strlen(errstring));
    XFlush(dpy);
    seenerr = 1; 
}

void
usefont(XFontStruct *fontinfo)
{
    curfont = fontinfo;
    curfontid = fontinfo->fid;
    curfontheight = fontinfo->max_bounds.ascent + fontinfo->max_bounds.descent;
    curfontwidth = fontinfo->max_bounds.width;
} 

#ifndef SC_FONT
#define SC_FONT "fixed"
#endif

/***
function sc_Xinit() initializes all of the global variables defined in 
this file.  argc and argv are used to set some of the window parameters,
if any X parameters were given on the command line.
***/
int
sc_Xinit(int argc, char **argv)
{
#if defined TEST || !defined VR3
    XColor hilite, exact;
    Colormap cmap;
#endif

    if ((dpy = XOpenDisplay(NULL)) == NULL) {
	fprintf(stderr, "%s: Can't open display %s\n", argv[0], 
		XDisplayName(NULL));
	exit(EXIT_FAILURE);
    }

    if (userfont == NULL)
	curfont = XLoadQueryFont(dpy, SC_FONT);
    else
	curfont = XLoadQueryFont(dpy, userfont);
    if (curfont == NULL) {
	fprintf(stderr, "%s: Display %s doesn't know font \"%s\" \n",
		progname, DisplayString(dpy), 
		userfont == NULL ? SC_FONT : userfont);
	exit(EXIT_FAILURE);
    }
    usefont(curfont);

    /* initialize pixel values  */
    black = BlackPixel(dpy, DefaultScreen(dpy)); 
    white = WhitePixel(dpy, DefaultScreen(dpy)); 

#if defined TEST || !defined VR3
    cmap = DefaultColormap(dpy, DefaultScreen(dpy));
    if (XAllocNamedColor(dpy, cmap, "gray80", &exact, &hilite)) 
        gray = hilite.pixel;
    else 
        gray = (black + white) / 2;
#else
    gray = 0x07;
#endif /* desktop test */

    /* border width of 1 */
    bw = 1;

    /* fill in the window manager hints */
    xsh.flags = (PMinSize | PResizeInc | PPosition);
    xsh.min_width = xsh.width = XSH_MIN_WIDTH;
    xsh.min_height = xsh.height = XSH_MIN_HEIGHT;
    xsh.width_inc = curfontwidth;
    xsh.height_inc = curfontheight;
    xsh.x = xsh.y = 0; 

    /* create the main window and give the hints to the window manager */
    mainwin = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy),
				  xsh.x, xsh.y, xsh.min_width, xsh.min_height,
				  bw, black, white);
    XSetStandardProperties(dpy, mainwin, progname, progname, None, 
			   argv, argc, &xsh);

    /* Insure that the window's colormap points to the default colormap, and
       set the window's bit gravity to NorthWest, because that is the origin 
       of everything in the window */
    xswa.colormap = DefaultColormap(dpy, DefaultScreen(dpy));
    XChangeWindowAttributes(dpy, mainwin, CWColormap, &xswa);

    /* create the normal Graphics Context */
    maingc = XCreateGC(dpy, mainwin, 0, 0); 
    XSetFont(dpy, maingc, curfontid);
    XSetForeground(dpy, maingc, black);
    XSetBackground(dpy, maingc, white);
    /* and the reversed GC */
    maingcreversed = XCreateGC(dpy, mainwin, 0, 0);
    XSetFont(dpy, maingcreversed, curfontid);
#ifdef VR3
    XSetForeground(dpy, maingcreversed, black);
    XSetBackground(dpy, maingcreversed, gray);
#else
    XSetForeground(dpy, maingcreversed, white);
    XSetBackground(dpy, maingcreversed, black);
#endif

    /* and the (inverting) reversed GC */
    invertgc = XCreateGC(dpy, mainwin, 0, 0);
    XCopyGC(dpy, maingc, GCForeground | GCBackground, invertgc);
    XSetFunction(dpy, invertgc, GXinvert);
    XSetPlaneMask(dpy, invertgc, white^black);

    /* gc for grid lines */
    graygc = XCreateGC(dpy, mainwin, 0, 0);
    XSetForeground(dpy, graygc, gray);
    XSetBackground(dpy, graygc, white);

    /* input event selection */
#ifdef VR3
    XSelectInput(dpy, mainwin, 
		 StructureNotifyMask | KeyPressMask | ButtonPressMask | 
		 ExposureMask | Button1MotionMask | ButtonReleaseMask);
#else
    XSelectInput(dpy, mainwin, 
		 StructureNotifyMask | KeyPressMask | ButtonPressMask | 
		 ExposureMask | PointerMotionMask | Button1MotionMask |
		 ButtonReleaseMask);
#endif

    /* map the window to make it visible */
    XMapRaised(dpy, mainwin);

    /*determine the window's dimensions */
    if (XGetWindowAttributes(dpy, mainwin, &xwa) == 0) {
	fprintf(stderr,"%s: Error: Can't get attributes of main window.",
		progname);
	exit(EXIT_FAILURE);
    }
    maintextcols = xwa.width / curfontwidth;
    maintextrows = xwa.height / curfontheight - 1;

    return 0;
}

int
sc_handleresize(XEvent *event)
{
    if (event->type != ConfigureNotify) return 0;
    maintextrows = event->xconfigure.height / curfontheight - 1;
    maintextcols = event->xconfigure.width / curfontwidth;
    return 0;
}

void
cleardownfrom(int r)
     /* clears window from row to the bottom */
{
    XClearArea(dpy, mainwin,
	       0, textrow(r - 1) + 1,
	       0,              /* 0 width => clear to right side */
	       0,              /* 0 height => remaining window height*/
	       0);             /* don't generate Expose events */
}

void
clearupfrom(int r)
     /* clears row r, and any lines above it */
{
    XClearArea(dpy, mainwin,
	       0, 0,           /* top left corner */
	       0,              /* use width of window */
	       textrow(r),     /* go through row r */
	       0);             /* don't send Expose events */
}




