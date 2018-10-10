
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

/* These patterns were created using the bitmap editor.  They are used */
/* in the plot_pie, plot_bar, and plot_stacked_bar procedures.         */
/* Dan Gruber - 11/13/91                                               */

#define white_width 1
#define white_height 1
static unsigned char white_bits[] = {
   0x01};

#define gray1_width 4
#define gray1_height 4
static unsigned char gray1_bits[] = {
   0xfe, 0xff, 0xfb, 0xff};

#define gray2_width 16
#define gray2_height 16
static unsigned char gray2_bits[] = {
   0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff,
   0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff,
   0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff};

#define gray3_width 2
#define gray3_height 2
static unsigned char gray3_bits[] = {
   0x01, 0x02};

#define gray4_width 16
#define gray4_height 16
static unsigned char gray4_bits[] = {
   0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00,
   0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00,
   0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00};

#define gray5_width 4
#define gray5_height 4
static unsigned char gray5_bits[] = {
   0x01, 0x00, 0x04, 0x00};

#define black_width 1
#define black_height 1
static unsigned char black_bits[] = {
   0x00};

#define horiz_lines_width 1
#define horiz_lines_height 5
static unsigned char horiz_lines_bits[] = {
   0x00, 0x00, 0x01, 0x00, 0x00};

#define vert_lines_width 5
#define vert_lines_height 1
static unsigned char vert_lines_bits[] = {
   0x04};

#define checker_width 10
#define checker_height 10
static unsigned char checker_bits[] = {
   0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0xe0, 0x03,
   0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x03};

#define diag_l_width 7
#define diag_l_height 7
static unsigned char diag_l_bits[] = {
   0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40};

#define diag_r_width 7
#define diag_r_height 7
static unsigned char diag_r_bits[] = {
   0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

#define light_diamond_width 7
#define light_diamond_height 7
static unsigned char light_diamond_bits[] = {
   0xbe, 0xdd, 0xeb, 0xf7, 0xeb, 0xdd, 0xbe};

#define dark_diamond_width 7
#define dark_diamond_height 7
static unsigned char dark_diamond_bits[] = {
   0x41, 0x22, 0x14, 0x08, 0x14, 0x22, 0x41};

#define light_cross_weave_width 16
#define light_cross_weave_height 16
static unsigned char light_cross_weave_bits[] = {
   0xaa, 0xaa, 0x77, 0x77, 0xaa, 0xaa, 0xdd, 0xdd, 0xaa, 0xaa, 0x77, 0x77,
   0xaa, 0xaa, 0xdd, 0xdd, 0xaa, 0xaa, 0x77, 0x77, 0xaa, 0xaa, 0xdd, 0xdd,
   0xaa, 0xaa, 0x77, 0x77, 0xaa, 0xaa, 0xdd, 0xdd};

#define dark_cross_weave_width 16
#define dark_cross_weave_height 16
static unsigned char dark_cross_weave_bits[] = {
   0x55, 0x55, 0x88, 0x88, 0x55, 0x55, 0x22, 0x22, 0x55, 0x55, 0x88, 0x88,
   0x55, 0x55, 0x22, 0x22, 0x55, 0x55, 0x88, 0x88, 0x55, 0x55, 0x22, 0x22,
   0x55, 0x55, 0x88, 0x88, 0x55, 0x55, 0x22, 0x22};

#define light_root_weave_width 4
#define light_root_weave_height 4
static unsigned char light_root_weave_bits[] = {
   0xf8, 0xf2, 0xf4, 0xf1};

#define dark_root_weave_width 4
#define dark_root_weave_height 4
static unsigned char dark_root_weave_bits[] = {
   0x07, 0x0d, 0x0b, 0x0e};

#define light_wide_weave_width 16
#define light_wide_weave_height 16
static unsigned char light_wide_weave_bits[] = {
   0x11, 0x11, 0xb8, 0xb8, 0x7c, 0x7c, 0x3a, 0x3a, 0x11, 0x11, 0xa3, 0xa3,
   0xc7, 0xc7, 0x8b, 0x8b, 0x11, 0x11, 0xb8, 0xb8, 0x7c, 0x7c, 0x3a, 0x3a,
   0x11, 0x11, 0xa3, 0xa3, 0xc7, 0xc7, 0x8b, 0x8b};

#define dark_wide_weave_width 16
#define dark_wide_weave_height 16
static unsigned char dark_wide_weave_bits[] = {
   0xee, 0xee, 0x47, 0x47, 0x83, 0x83, 0xc5, 0xc5, 0xee, 0xee, 0x5c, 0x5c,
   0x38, 0x38, 0x74, 0x74, 0xee, 0xee, 0x47, 0x47, 0x83, 0x83, 0xc5, 0xc5,
   0xee, 0xee, 0x5c, 0x5c, 0x38, 0x38, 0x74, 0x74};
