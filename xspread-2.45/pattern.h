
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

#ifndef PATTERN_H
#define PATTERN_H

static short g_pattern_len[] = {1, 16, 2, 4};

static unsigned char white_bits[] = {
    0x01
};

static unsigned char gray1_bits[] = {
    0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff,
     0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff,
     0xaa, 0xaa, 0xff, 0xff, 0xaa, 0xaa, 0xff, 0xff
};

static unsigned char gray2_bits[] = {
    0x01, 0x02
};

static unsigned char gray3_bits[] = {
    0x01, 0x00, 0x04, 0x00
};

#endif /* PATTERN_H */

