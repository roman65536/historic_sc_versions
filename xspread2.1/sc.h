/*	SC	A Table Calculator
 *		Common definitions
 *
 *		original by James Gosling, September 1982
 *		modified by Mark Weiser and Bruce Israel,
 *			University of Maryland
 *		R. Bond  12/86
 *		More mods by Alan Silverstein, 3-4/88, see list of changes.
 *		$Revision: 6.21 A $
 *
 */

#if defined(MSDOS)
#include <stdio.h>
#endif
#include <limits.h>

#define	ATBL(tbl, row, col)	(*(tbl + row) + (col))

#define MINROWS 100 	/* minimum size at startup */
#define MINCOLS 30 
#define	ABSMAXCOLS 702	/* absolute cols: ZZ (base 26) */

#ifdef DOINGX
/*the following give the minimum size of the main window, in text coordinates*/ 
#define MIN_COLS 80
#define MIN_ROWS 25
#endif

#define REG_LEN 28      /* following eight moved here by Bob Parbs 12-92 */
#define ROWLIM  5       /* increased to five from four after move */
#define COLIM   3 
#define TSSIZE  15
#define MAXSS   2000
#define MINMAX  25
#define MAXROW  25 
#define MAXCOL  25      /* moved from matrix.c */

#define CRROWS 1
#define CRCOLS 2
#define RESCOL 4	/* columns reserved for row numbers */
/*#ifdef DOINGX*/
#define RESROW 4 /* rows reserved for prompt, error, and column numbers */
/*#else
#define RESROW 3 */ /* rows reserved for prompt, error, and column numbers */
/*#endif*/

/* formats for engformat() */
#define REFMTFIX	0	/* fixed point: -0.00010 */
#define REFMTFLT	1	/* scientific notation: -1.00E\-04 */
#define REFMTENG	2	/* engineering notation: -100.00u */
#define REFMTDATE	3	/* dates: 05/15/92 */
#define REFMTEXP	4	/* modulo 3 exponent notation: -100.E-06 */

#define DEFWIDTH 10	/* Default column width and precision */
#define DEFPREC   2
#define DEFREFMT  REFMTFIX /* Make default format fixed point  THA 10/14/90 */

#define HISTLEN  10	/* Number of history entries for vi emulation */

#define	FBUFLEN	1024	/* buffer size for a single field */

	/* maximum path length */
#ifdef PATH_MAX
# define	PATHLEN	PATH_MAX
#else
# ifdef PATHSIZE
#  define	PATHLEN	PATHSIZE
# else
#  define	PATHLEN	1024
# endif
#endif

#ifndef A_CHARTEXT	/* Should be defined in curses.h */
# ifdef INTERNATIONAL
#  define A_CHARTEXT 0xff
# else
#  define A_CHARTEXT 0x7f
# endif
#endif

#if (defined(BSD42) || defined(BSD43)) && !defined(strrchr)
#define strrchr rindex
#endif

#if (defined(BSD42) || defined(BSD43)) && !defined(strchr)
#define strchr index
#endif

#ifndef FALSE
# define	FALSE	0
# define	TRUE	1
#endif /* !FALSE */

#ifdef SIGVOID
typedef void	sig_type;
#else
typedef int	sig_type;
#endif

/*
 * ent_ptr holds the row/col # and address type of a cell
 *
 * vf is the type of cell address, 0 non-fixed, or bitwise OR of FIX_ROW or
 *	FIX_COL
 * vp : we just use vp->row or vp->col, vp may be a new cell just for holding
 *	row/col (say in gram.y) or a pointer to an existing cell
 */
struct ent_ptr {
    int vf;
    struct ent *vp;
};

/* holds the beginning/ending cells of a range */
struct range_s {
	struct ent_ptr left, right;
};

/*
 * Some not too obvious things about the flags:
 *    is_valid means there is a valid number in v.
 *    is_locked means that the cell cannot be edited.
 *    label set means it points to a valid constant string.
 *    is_strexpr set means expr yields a string expression.
 *    If is_strexpr is not set, and expr points to an expression tree, the
 *        expression yields a numeric expression.
 *    So, either v or label can be set to a constant. 
 *        Either (but not both at the same time) can be set from an expression.
 */

#define VALID_CELL(p, r, c) ((p = *ATBL(tbl, r, c)) && \
			     ((p->flags & is_valid) || p->label))

/* info for each cell, only alloc'd when something is stored in a cell */
struct ent {
    double v;		/* v && label are set in EvalAll() */
    char *label;
    struct enode *expr;	/* cell's contents */
    short flags;	
    short row, col;
    struct ent *next;	/* next deleted ent (pulled, deleted cells) */
    char *format;	/* printf format for this cell */
    char cellerror;	/* error in a cell? */
};

/* stores a range (left, right) */
struct range {
    struct ent_ptr r_left, r_right;
    char *r_name;			/* possible name for this range */
    struct range *r_next, *r_prev;	/* chained ranges */
    int r_is_range;
};

#define FIX_ROW 1
#define FIX_COL 2

/* stores type of operation this cell will preform */
struct enode {
    int op;
    union {
	int gram_match;         /* some compilers (hp9000ipc) need this */
	double k;		/* constant # */
	struct ent_ptr v;	/* ref. another cell */
	struct range_s r;	/* op is on a range */
	char *s;		/* string part of a cell */
	struct {		/* other cells use to eval()/seval() */
	    struct enode *left, *right;
	} o;
    } e;
};

/* following structure moved from matrix.c by Bob Parbs 12-92 */
struct m_range_sd{
    int ssr,ser,ssc,sec;
    int dsr,der,dsc,dec;
    };

/* this struct also moved from matrix.c by Bob Parbs 12-92 */
struct m_range{
    int sr,er,sc,ec;
    };

/* op values */
#define O_VAR		'v'
#define O_CONST		'k'
#define O_ECONST	'E'	/* constant cell w/ an error */
#define O_SCONST	'$'
#define REDUCE		0200	/* Or'ed into OP if operand is a range */

#define OP_BASE	256
#define ACOS	(OP_BASE + 0)
#define ASIN	(OP_BASE + 1)
#define ATAN	(OP_BASE + 2)
#define CEIL	(OP_BASE + 3)
#define COS	(OP_BASE + 4)
#define EXP	(OP_BASE + 5)
#define FABS	(OP_BASE + 6)
#define FLOOR	(OP_BASE + 7)
#define HYPOT	(OP_BASE + 8)
#define LOG	(OP_BASE + 9)
#define LOG10	(OP_BASE + 10)
#define POW	(OP_BASE + 11)
#define SIN	(OP_BASE + 12)
#define SQRT	(OP_BASE + 13)
#define TAN	(OP_BASE + 14)
#define DTR	(OP_BASE + 15)
#define RTD	(OP_BASE + 16)
#define MINR	(OP_BASE + 17)	/* MIN/MAX might already be macros ... */
#define MAXR	(OP_BASE + 18)
#define RND	(OP_BASE + 19)
#define HOUR	(OP_BASE + 20)
#define MINUTE	(OP_BASE + 21)
#define SECOND	(OP_BASE + 22)
#define MONTH	(OP_BASE + 23)
#define DAY	(OP_BASE + 24)
#define YEAR	(OP_BASE + 25)
#define NOW	(OP_BASE + 26)
#define DATE	(OP_BASE + 27)
#define FMT	(OP_BASE + 28)
#define SUBSTR	(OP_BASE + 29)
#define STON	(OP_BASE + 30)
#define EQS	(OP_BASE + 31)
#define EXT	(OP_BASE + 32)
#define ELIST	(OP_BASE + 33)	/* List of expressions */
#define LMAX	(OP_BASE + 34)
#define LMIN	(OP_BASE + 35)
#define NVAL	(OP_BASE + 36)
#define SVAL	(OP_BASE + 37)
#define PV	(OP_BASE + 38)
#define FV	(OP_BASE + 39)
#define PMT	(OP_BASE + 40)
#define STINDEX	(OP_BASE + 41)
#define LOOKUP	(OP_BASE + 42)
#define ATAN2	(OP_BASE + 43)
#define INDEX	(OP_BASE + 44)
#define DTS	(OP_BASE + 45)
#define TTS	(OP_BASE + 46)
#define ABS	(OP_BASE + 47)
#define HLOOKUP	(OP_BASE + 48)
#define VLOOKUP	(OP_BASE + 49)
#define ROUND	(OP_BASE + 50)
#define IF	(OP_BASE + 51)
#define MYROW	(OP_BASE + 52)
#define MYCOL	(OP_BASE + 53)
#define COLTOA	(OP_BASE + 54)
#define UPPER	(OP_BASE + 55)
#define LOWER	(OP_BASE + 56)
#define CAPITAL	(OP_BASE + 57)
#define NUMITER	(OP_BASE + 58)
#define MATRIX_ADD   (OP_BASE + 59)
#define MATRIX_SUB   (OP_BASE + 60)
#define MATRIX_INV   (OP_BASE + 61)
#define MATRIX_MULT  (OP_BASE + 62)
#define MATRIX_TRANS (OP_BASE + 63)

/* flag values */
#define is_valid     0001
#define is_changed   0002
#define is_strexpr   0004
#define is_leftflush 0010
#define is_deleted   0020
#define is_locked    0040
#define is_label     0100

/* cell error (1st generation (ERROR) or 2nd+ (INVALID)) */
#define	CELLOK		0
#define	CELLERROR	1
#define	CELLINVALID	2

#define ctl(c)	((c)&037)
#define ESC	033
#define DEL	0177

/* calculation order */
#define BYCOLS	1
#define BYROWS	2

/* tblprint style output for: */
#define	TBL	1		/* 'tbl' */
#define	LATEX	2		/* 'LaTeX' */
#define	TEX	3		/* 'TeX' */
#define	SLATEX	4		/* 'SLaTeX' (Scandinavian LaTeX) */
#define	FRAME	5		/* tblprint style output for FrameMaker */

/* Types for etype() */
#define NUM	1
#define STR	2

#define	GROWAMT	30	/* default minimum amount to grow */

#define	GROWNEW		1	/* first time table */
#define	GROWROW		2	/* add rows */
#define	GROWCOL		3	/* add columns */
#define	GROWBOTH	4	/* grow both */
extern	struct ent ***tbl;	/* data table ref. in vmtbl.c and ATBL() */

extern char	curfile[];
extern int	strow, stcol;
extern int	currow, curcol;
extern int	savedrow, savedcol;
extern int	FullUpdate;
extern int	maxrow, maxcol;
extern int	maxrows, maxcols;	/* # cells currently allocated */
extern int	*fwidth;
extern int	*precision;
extern int	*realfmt;
extern char	*col_hidden;
extern char	*row_hidden;
extern char	line[FBUFLEN];
extern int	linelim;
extern int	changed;
extern struct ent *to_fix;
extern int	showsc, showsr;
extern char     prvstring[1024];/*to store last string Bob Parbs 12-92 */
extern char	stringbuf[1024];
extern int	maintextrows,	/* text rows in mainwin */
		maintextcols;	/* text cols in mainwin */
extern int	running;	/* are we done? -be careful on use... */

#ifdef __STDC__

extern void	EvalAll(void);
extern void	add_range(char *, struct ent_ptr, struct ent_ptr, int);
extern int	any_locked_cells(int, int, int, int);
extern int	are_ranges(void);
extern int	atocol(char *, int);
extern void	backcol(int);
extern void	backrow(int);
#ifdef DOBACKUPS
extern int	backup_file(char *);
#endif
extern void	checkbounds(int *, int *);
extern void	clean_range(void);
extern void	clearent(struct ent *);
extern void	clearlines(int, int);
extern void	closecol(int, int);
extern void	closeout(FILE *, int);
extern void	closerow(int);
extern void	colshow_op(void);
extern char *	coltoa(int);
extern void	copy(struct ent *, struct ent *, struct ent *, struct ent *);
extern struct enode *	copye(struct enode *, int, int);
extern void	copyent(struct ent *, struct ent *, int, int);
extern void	creadfile(char *, int);
extern void	cr_line(void);
extern int	cwritefile(char *, int, int, int, int);
extern void	del_range(struct ent *, struct ent *);
extern void	deleterow(int);
extern void	deraw(void);
extern void	diesave(void);
extern double	dodts(int, int, int);
extern void	doend(int, int);
extern void	doformat(int, int, int, int, int);
extern void	dupcol(void);
extern void	duprow(void);
extern void	edit_mode(void);
extern void	editexp(int, int);
extern void	editfmt(int, int);
extern void	edits(int, int);
extern void	editv(int, int);
extern void	efree(struct enode *);
extern int	engformat(int, int, int, double, char *, int);
extern void	erase_area(int, int, int, int);
extern void	erasedb(void);
extern void	eraser(struct ent *, struct ent *);
extern int	etype(struct enode *);
extern void	fill(struct ent *, struct ent *, double, double);
extern struct range *	find_range(char *, int, struct ent *, struct ent *);
extern char *	findhome(char *);
extern void	flush_saved(void);
extern int	format(char *, double, char *, int);
extern void	format_cell(struct ent *, struct ent *, char *);
extern void	forwcol(int);
extern void	forwrow(int);
extern void	free_ent(struct ent *);
extern char *	fsuffix(char *, char *);
#ifndef DOINGX
extern int	get_rcqual(int);
#else
extern char *	get_str(char *, int);
#endif
extern void	go_last(void);
extern void	goraw(void);
extern int	growtbl(int, int, int);
extern void	help(void);
extern void	hide_col(int);
extern void	hide_row(int);
extern void	hidecol(int);
extern void	hiderow(int);
extern void	initkbd(void);
extern void	ins_string(char *);
extern void	insert_mode(void);
extern void	insertrow(int);
extern void	kbd_again(void);
extern void	label(struct ent *, char *, int);
extern void	let(struct ent *, struct enode *);
extern void	list_range(FILE *);
extern void	lock_cells(struct ent *, struct ent *);
extern int	locked_cell(int, int);
extern struct ent *	lookat(int, int);
extern int	modcheck(char *);
extern void	moveto(int, int);
extern struct enode *	new(int, struct enode *, struct enode *);
extern struct enode *	new_const(int, double);
extern struct enode *	new_range(int, struct range_s);
extern struct enode *	new_str(char *);
extern struct enode *	new_var(int, struct ent_ptr);
extern int	nmgetch(void);
extern void	num_search(double, int);
extern void	opencol(int, int);
extern FILE *	openout(char *, int *);
extern void	printfile(char *, int, int, int, int);
extern void	pullcells(int);
extern char *	r_name(int, int, int, int);
extern void	readfile(char *, int);
extern void	repaint(int, int, int);
extern void	resetkbd(void);
extern void	rowshow_op(void);
extern void	scxfree(char *);
extern char *	scxmalloc(unsigned int);
extern char *	scxrealloc(char *, unsigned int);
extern void	setauto(int);
extern void	setiterations(int);
extern void	setorder(int);
extern void	show_top_line(void);
extern void	showcol(int, int);
extern void	showdr(void);
extern void	showrow(int, int);
extern void	showstring(char *, int, int, int, int, int	*, int, int *,int,int);
extern void	signals(void);
extern void	slet(struct ent *, struct enode *, int);
extern void	startdisp(void);
extern void	startshow(void);
extern void	stopdisp(void);
extern void	str_search(char *);
//extern char *	strtof(char *volatile, double *);
extern void	sync_ranges(void);
extern void	sync_refs(void);
extern void	tblprintfile(char *, int, int, int, int);
extern sig_type	time_out(int);
extern void	unlock_cells(struct ent *, struct ent *);
extern void	update(int);
extern char *	v_name(int, int);
extern void	valueize_area(int, int, int, int);
extern void	write_fd(FILE *, int, int, int, int);
extern void	write_line(int);
extern void	write_range(FILE *);
extern int	writefile(char *, int, int, int, int);
extern int	yn_ask(char *);
extern void	yyerror(char *);

#else	/* __STDC__ */

extern void	EvalAll();
extern void	add_range();
extern void     addmatrix();       /* added by Bob Parbs 12-92 */
extern int	any_locked_cells();
extern int	are_ranges();
extern int	atocol();
extern void	backcol();
extern void	backrow();
#ifdef DOBACKUPS
extern int	backup_file();
#endif
extern void	checkbounds();
extern void	clean_range();
extern void	clearent();
extern void	clearlines(/*startrow, endrow*/);
extern void	closecol();
extern void	closeout();
extern void	closerow();
extern void	colshow_op();
extern char *	coltoa();
extern int      convert();         /* added by Bob Parbs 12-92 */ 
extern void	copy();
extern struct enode *	copye();
extern void	copyent();
extern void	creadfile();
extern void	cr_line();
extern int	cwritefile();
extern void	del_range();
extern void	deleterow();
extern void	deraw();
extern void	diesave();
extern double	dodts();
extern void	doend();
extern void	doformat();
extern void	dupcol();
extern void	duprow();
extern void	edit_mode();
extern void	editexp();
extern void	editfmt();
extern void	edits();
extern void	editv();
extern void	efree();
extern int	engformat();
extern void	erase_area();
extern void	erasedb();
extern void	eraser();
extern int	etype();
extern void	fill();
extern struct range *	find_range();
extern struct m_range_sd * find_rge();   /* added by Bob Parbs 12-92 */
extern struct m_range * findrge();       /* Bob Parbs 12-92 */
extern char *	findhome();
extern void	flush_saved();
extern int	format();
extern void	format_cell();
extern void	forwcol();
extern void	forwrow();
extern void	free_ent();
extern char *	fsuffix();
extern void     get_add();               /* Bob Parbs 12-92 */
extern void     get_invert();            /* Bob Parbs 12-92 */
extern void     get_mult();              /* Bob Parbs 12-92 */
#ifndef DOINGX
extern int	get_rcqual();
#else
extern char *	get_str();
#endif
extern void     get_sub();               /* Bob Parbs 12-92 */
extern void     get_trans();             /* Bob Parbs 12-92 */
extern void	go_last();
extern void	goraw();
extern int	growtbl();
extern void	help();
extern void	hide_col();
extern void	hide_row();
extern void	hidecol();
extern void	hiderow();
extern void	initkbd();
extern void	ins_string();
extern void	insert_mode();
extern void	insertrow();
extern void     invertmatrix();          /* Bob Parbs 12-92 */
extern void	kbd_again();
extern void	label();
extern void	let();
extern void	list_range();
extern void	lock_cells();
extern int	locked_cell();
extern struct ent *	lookat();
extern int	modcheck();
extern void	moveto();
extern void     multmatrix();            /* Bob Parbs 12-92 */
extern void     multmatrix1();           /* Bob Parbs 12-92 */
extern struct enode *	new();
extern struct enode *	new_const();
extern struct enode *	new_range();
extern struct enode *	new_str();
extern struct enode *	new_var();
extern int	nmgetch();
extern void	num_search();
extern void	opencol();
extern FILE *	openout();
extern void	printfile();
extern void	pullcells();
extern char *	r_name();
extern void	readfile();
extern void	repaint();
extern void	resetkbd();
extern void	rowshow_op();
extern void	scxfree();
extern char *	scxmalloc();
extern char *	scxrealloc();
extern void	setauto();
extern void	setiterations();
extern void	setorder();
extern void	show_top_line();
extern void	showcol();
extern void	showdr();
extern void	showrow();
extern void	showstring();
extern void	signals();
extern void	slet();
extern void	startdisp();
extern void	startshow();
extern void	stopdisp();
extern void	str_search();
extern char *	strtof();
extern void     submatrix();              /* Bob Parbs 12-92 */
extern void	sync_ranges();
extern void	sync_refs();
extern void	tblprintfile();
extern sig_type	time_out();
extern void     transpose();              /* Bob Parbs 12-92 */
extern void	unlock_cells();
extern void	update();
extern char *	v_name();
extern void	valueize_area();
extern void	write_fd();
extern void	write_line();
extern void	write_range();
extern int	writefile();
extern int	yn_ask();
extern void	yyerror();

#endif	/* __STDC__ */

#if !defined(VMS) && !defined(MSDOS) && defined(CRYPT_PATH)
extern int	Crypt;
#endif
extern int	autocalc;
extern int	autolabel;
extern int	calc_order;
extern int	collimit;
extern int	craction;
extern int	extfunc;
extern int	getrcqual;
extern int	loading;
extern char *	mdir;
extern int	modflg;
extern int	numeric;
extern double	prescale;
extern char *	progname;
extern int	propagation;
extern int	repct;
extern int	rndinfinity;
extern int	rowlimit;
extern int	showcell;
extern int	showtop;
extern int	tbl_style;

#if BSD42 || SYSIII

#ifndef cbreak
#define	cbreak		crmode
#define	nocbreak	nocrmode
#endif

#endif

#if defined(BSD42) || defined(BSD43) && !defined(ultrix)
#define	memcpy(dest, source, len)	bcopy(source, dest, (unsigned int)len);
#define	memset(dest, zero, len)		bzero((dest), (unsigned int)(len));
#else
#include <memory.h>
#endif

/*
 * Feature-setting declarations.  Can be used to control the default
 * setting of various features.
 */

#ifndef	SHOWCURSOR
#define	SHOWCURSOR	TRUE
#endif

/*
 * Declarations of standard functions used in various places.  Mostly
 * to shut up line and 'gcc -Wall'.
 */

#ifdef __STDC__
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

extern int	kill();
extern int	re_exec();
extern int	stty();
extern int	wait();
extern int	yylex(void);
extern int	yyparse();

#else	/* __STDC__ */

extern int	_filbuf();
extern int	_flsbuf();
extern int	alarm();
extern int	close();
extern int	dup();
extern int	endwin();
extern int	execl();
#ifdef SYSV3
extern void	exit();
#endif
extern int	fclose();
extern FILE *	fdopen();
extern int	fflush();
extern FILE *	fopen();
extern int	fork();
extern int	fprintf();
extern int	fputs();
extern char	*getenv();
extern int	ioctl();
extern int	kill();
extern int	pclose();
extern int	pipe();
extern FILE *	popen();
extern double	pow();
extern int	printf();
extern int	printw();
extern int	puts();
extern int	re_exec();
extern int	read();
extern char *	strchr();
extern char *	strrchr();
/*extern int	strlen();*/
/*extern size_t	strlen();*/
extern int	stty();
extern long	time();
extern int	tolower();
extern int	toupper();
extern int	waddch();
extern int	waddstr();
extern int	wait();
extern int	wclear();
extern int	wclrtobot();
extern int	wclrtoeol();
extern int	wmove() ;
extern int	wmove();
extern int	wrefresh();
extern int	write();
extern int	wstandend();
extern int	wstandout();
extern int	yylex();
extern int	yyparse();

#endif	/* __STDC__ */
