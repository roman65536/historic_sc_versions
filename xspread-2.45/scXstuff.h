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
 *		HISTORY, CLAIMS and CONTRIBUTIONS
 */

/* This file declares the functions and globals defined in scXstuff.c */
/* REVISION HISTORY */
/* 7-19-91   B. Backman   Creation */

#ifndef SC_XSTUFF_H
#define SC_XSTUFF_H

extern Display *dpy;		/* X server connection */
extern Window mainwin;	        /* Window ID of main window*/
extern GC maingc,	        /* GC for mainwin */
          maingcreversed,	/* reverse-field GC for mainwin */
          invertgc,	        /* (invert) reverse-field GC for mainwin */
          graygc;               /* for grid lines */
extern XFontStruct *curfont; 	/* Font descriptor structure for current font */
extern int curfontwidth, 
	   curfontheight;       /* dimensions of current font (in pixels) */
char *userfont;			/*  user specified font name */

/* functions defined in scXstuff.c  */
extern void cleardownfrom(int r);
extern void clearupfrom(int r);
extern int sc_Xinit(int argc, char **argv);
extern int sc_handleresize(XEvent *event);

#endif /* SC_XSTUFF_H */
