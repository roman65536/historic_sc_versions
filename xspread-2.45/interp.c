/*	SC	A Spreadsheet Calculator
 *		Expression interpreter and assorted support routines.
 *
 *		original by James Gosling, September 1982
 *		modified by Mark Weiser and Bruce Israel, 
 *			University of Maryland
 *
 *              More mods Robert Bond, 12/86
 *		More mods by Alan Silverstein, 3-4/88, see list of changes.
 *              More mods by Peter Doemel, 2/93: support for REG_COMP
 *		$Revision: 1.32 $
 */

#include "config.h"
#include <stdio.h> 
#include <string.h>
#include <time.h>
#include <float.h>

#include <sys/types.h>

#include <math.h>
#include <signal.h>
#include <setjmp.h>
#include <ctype.h>
#include <errno.h>

extern int errno;		/* set by math functions */

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "sc.h"
#include "scXstuff.h"

#if defined(RE_COMP)
char *re_comp();
#endif
#if defined(REGCMP)
char *regcmp();
char *regex();
#endif

#if defined(REG_COMP) /* Peter Doemel, 10-Feb-1993 */
#include <regex.h>
# if NeedFunctionPrototypes
int regcomp(regex_t *preg, const char *pattern, int cflags);
int regexec(const regex_t *preg, const char *string, size_t nmatch,
	    regmatch_t pmatch[], int eflags);
void regfree(regex_t *preg);
char *regerrmsg(interrcode);
# else
char *regerrmsg();
# endif
#endif
  

sig_type doquit();

/* Use this structure to save the the last 'g' command */
struct go_save {
    int g_type;
    double g_n;
    char *g_s;
    int  g_row;
    int  g_col;
    int  errsearch;
} gs;

/* g_type can be: */
#define G_NONE 0			/* Starting value - must be 0*/
#define G_NUM 1
#define G_STR 2
#define G_CELL 3

#define ISVALID(r,c)	((r)>=0 && (r)<maxrows && (c)>=0 && (c)<maxcols)

jmp_buf fpe_save;
int	exprerr;	/* Set by eval() and seval() if expression errors */
double  prescale = 1.0;	/* Prescale for constants in let() */
int	extfunc  = 0;	/* Enable/disable external functions */
int     loading = 0;	/* Set when readfile() is active */
int	gmyrow, gmycol;	/* globals used to implement @myrow, @mycol cmds */

/* a linked list of free [struct enodes]'s, uses .e.o.left as the pointer */
struct enode *freeenodes = NULL;

static int	RealEvalAll(void);
static void	RealEvalOne(struct ent *, int, int, int *);
static int	constant(struct enode *);
static void	copyrtv(int, int, int, int, int, int);
static void	decodev(struct ent_ptr);
static void	decompile(struct enode *, int);
static void	decompile_list(struct enode *);
static double	doavg(int, int, int, int, struct enode*);
static char *	docapital(char *);
static char *	docase(int, char *);
static char *	docat(char *, char *);
static double	docount(int, int, int, int, struct enode*);
static char *	dodate(long);
static double	doeqs(char *, char *);
static char *	doext(char *, double);
static char *	dofmt(char *, double);
static double	doindex(double, int, int, int, int);
static double	dolookup(struct enode *, int, int, int, int, int, int);
static double	dolmax(struct enode *);
static double	dolmin(struct enode *);
static double	doprod(int, int, int, int, struct enode*);
static double	domax(int, int, int, int, struct enode*);
static double	domin(int, int, int, int, struct enode*);
static double	donval(char *, double);
static double	dostddev(int, int, int, int, struct enode*);
static double	doentropy(int, int, int, int);
static char *	dostindex(double, int, int, int, int);
static char *	dostlookup(struct enode *, int, int, int, int, int, int);
static char *	dosubstr(char *, int, int);
static double	dosum(int, int, int, int, struct enode*);
static char *	dosval(char *, double);
static double	doston(char *);
static double	dotime(int, double);
static double	dotts(int, int, int);
static double	eval(struct enode *);
static sig_type	eval_fpe(int);		/* Trap for FPE errors in eval */
static double	finfunc(int, double, double, double);
static double	fn1_eval(double (*)(), double);
static double	fn2_eval(double (*)(), double, double);
static struct ent *getent(char *, double);
static void	g_free(void);
static void	index_arg(char *, struct enode *);
static void	list_arg(char *, struct enode *);
static void	one_arg(char *, struct enode *);
static void	range_arg(char *, struct enode *);
static char *	seval();
static void	three_arg(char *, struct enode *);
static void	two_arg(char *, struct enode *);
static void	two_arg_index(char *, struct enode *);

static double doirr(int minr, int minc, int maxr, int maxc);
static double dorlirr(int minr, int minc, int maxr, int maxc);
static int valid_nrange(int minr, int minc, int maxr, int maxc, int emptyok);
static void set_step(int minr, int minc, int maxr, int maxc, 
		     int *rincp, int *cincp);
static void populate_power(double rate, double *rate_pow, int npow);
static double cash_flow(double rate, double *rate_pow, 
			int minr, int minc, int maxr, int maxc);


#ifndef PI
#define PI (double)3.14159265358979323846
#endif

int cellerror = CELLOK;	/* is there an error in this cell */

#define dtr(x) ((x)*(PI/(double)180.0))
#define rtd(x) ((x)*(180.0/(double)PI))
#define log2(x) (log((x))/log(2.0))

#ifdef  RINT  /* Otherwise we use the one in math.h */
/**     round-to-even, also known as ``banker's rounding''.
	With round-to-even, a number exactly halfway between two values is
	rounded to whichever is even; e.g. rnd(0.5)=0, rnd(1.5)=2,
	rnd(2.5)=2, rnd(3.5)=4.  This is the default rounding mode for
	IEEE floating point, for good reason: it has better numeric
	properties.  For example, if X+Y is an integer,
	then X+Y = rnd(X)+rnd(Y) with round-to-even,
	but not always with sc's rounding (which is
	round-to-positive-infinity).  I ran into this problem when trying to
	split interest in an account to two people fairly.
**/
double 
rint(double d)
{
    /* as sent */
    double fl = floor(d), fr = d - fl;

    return ((fr < 0.5) || ((fr == 0.5) && (fl == floor(fl/2) * 2)))
	? fl : ceil(d);
}
#endif

static double
finfunc(int fun, double v1, double v2, double v3)
{
    double answer, p;
 
    p = fn2_eval(pow, 1 + v2, v3);
 
    switch(fun) {
    case PV:
	if (v2)
	    answer = v1 * (1 - 1/p) / v2;
	else {
	    cellerror = CELLERROR;
	    answer = 0.0;
	}
	break;
    case FV:
	if (v2)
	    answer = v1 * (p - 1) / v2;
	else {
	    cellerror = CELLERROR;
	    answer = 0.0;
	}
	break;
    case PMT:
	/* CHECK IF ~= 1 - 1/1 */
	if (p && p != (double)1)
	    answer = v1 * v2 / (1 - 1/p);
	else {
	    cellerror = CELLERROR;
	    answer = 0.0;
	}
		
	break;
    default:
	error("Unknown function in finfunc");
	cellerror = CELLERROR;
	return 0.0;
    }
    return answer;
}

static char *
dostindex(double val, int minr, int minc, int maxr, int maxc)
{
    register int r, c;
    register struct ent *p;
    char *pr;
    int x;

    x = (int) val;
    r = minr; c = minc;
    p = NULL;
    if (minr == maxr) { /* look along the row */
	c = minc + x - 1;
	if (c <= maxc && c >=minc)
	    p = *ATBL(tbl, r, c);
    } else if (minc == maxc) { /* look down the column */
	r = minr + x - 1;
	if (r <= maxr && r >=minr)
	    p = *ATBL(tbl, r, c);
    } else {
	error ("range specified to @stindex");
	cellerror = CELLERROR;
	return NULL;
    }

    if (p && p->label) {
	pr = scxmalloc(strlen(p->label) + 1);
	strcpy(pr, p->label);
	if (p->cellerror)
	    cellerror = CELLINVALID;
	return (pr);
    } else
	return NULL;
}

static double
doindex(double val, int minr, int minc, int maxr, int maxc)
{
    double v;
    register int r, c;
    register struct ent *p;
    int x;

    x = (int) val;
    v = 0.0;
    r = minr; c = minc;
    if (minr == maxr) { /* look along the row */
	c = minc + x - 1;
	if (c <= maxc && c >=minc 
	    && (p = *ATBL(tbl, r, c)) && p->flags & is_valid ) {
	    if (p->cellerror)
		cellerror = CELLINVALID;
	    return p->v;
	}
    }
    else if (minc == maxc) { /* look down the column */
	r = minr + x - 1;
	if (r <= maxr && r >=minr 
	    && (p = *ATBL(tbl, r, c)) && p->flags & is_valid ) {
	    if (p->cellerror)
		cellerror = CELLINVALID;
	    return p->v;
	}
    } 
    else {
	error(" range specified to @index");
	cellerror = CELLERROR;
    }
    return v;
}

static double
dolookup(struct enode *val, int minr, int minc, int maxr, int maxc, 
	 int offr, int offc)
{
    double v, ret = 0.0;
    register int r, c;
    register struct ent *p = NULL;
    int incr,incc,fndr,fndc;
    char *s;

    incr = (offc != 0); incc = (offr != 0);
    if (etype(val) == NUM) {
	cellerror = CELLOK;
	v = eval(val);
	for (r = minr, c = minc; r <= maxr && c <= maxc; r+=incr, c+=incc) {
	    if ( (p = *ATBL(tbl, r, c)) && p->flags & is_valid ) {
		if (p->v <= v) {
		    fndr = incc ? (minr + offr) : r;
		    fndc = incr ? (minc + offc) : c;
		    if (ISVALID(fndr,fndc))
			p = *ATBL(tbl, fndr, fndc);
		    else {
			error(" range specified to @[hv]lookup");
			cellerror = CELLERROR;
		    }
		    if ( p && p->flags & is_valid)
			{	if (p->cellerror)
			    cellerror = CELLINVALID;
			ret = p->v;
			}
		} else break;
	    }
	}
    } else {
	cellerror = CELLOK;
	s = seval(val);
	for (r = minr, c = minc; r <= maxr && c <= maxc; r+=incr, c+=incc) {
	    if ( (p = *ATBL(tbl, r, c)) && p->label ) {
		if (strcmp(p->label,s) == 0) {
		    fndr = incc ? (minr + offr) : r;
		    fndc = incr ? (minc + offc) : c;
		    if (ISVALID(fndr,fndc))
			{	p = *ATBL(tbl, fndr, fndc);
			if (p->cellerror)
			    cellerror = CELLINVALID;
			}
		    else {
			error(" range specified to @[hv]lookup");
			cellerror = CELLERROR;
		    }
		    break;
		}
	    }
	}
	if ( p && p->flags & is_valid)
	    ret = p->v;
	scxfree(s);
    }
    return ret;
}

static char *
dostlookup(struct enode *val, int minr, int minc, int maxr, int maxc, 
	 int offr, int offc)
{
    double v;
    char *pr = NULL;
    register int r, c;
    register struct ent *p = NULL;
    int incr,incc,fndr,fndc;
    char *s;

    incr = (offc != 0); incc = (offr != 0);
    if (etype(val) == NUM) {
	cellerror = CELLOK;
	v = eval(val);
	for (r = minr, c = minc; r <= maxr && c <= maxc; r+=incr, c+=incc) {
	    if ( (p = *ATBL(tbl, r, c)) && p->flags&is_valid ) {
		if (p->v <= v) {
		    fndr = incc ? (minr + offr) : r;
		    fndc = incr ? (minc + offc) : c;
		    if (ISVALID(fndr,fndc))
			p = *ATBL(tbl, fndr, fndc);
		    else {
			error(" range specified to @[hv]lookup");
			cellerror = CELLERROR;
		    }
			if (p && p->label) {
			  pr = scxmalloc(strlen(p->label) + 1);
			  (void) strcpy(pr, p->label);
			  if (p->cellerror) {
			    cellerror = CELLINVALID;
			  }
			} else {
			  pr = NULL;
			}
		} else break;
	    }
	}
    } else {
	cellerror = CELLOK;
	s = seval(val);
	for (r = minr, c = minc; r <= maxr && c <= maxc; r+=incr, c+=incc) {
	    if ( (p = *ATBL(tbl, r, c)) && p->label ) {
		if (strcmp(p->label,s) == 0) {
		    fndr = incc ? (minr + offr) : r;
		    fndc = incr ? (minc + offc) : c;
		    if (ISVALID(fndr,fndc))
			{	p = *ATBL(tbl, fndr, fndc);
			if (p->cellerror) {
			    cellerror = CELLINVALID;
			}
			}
		    else {
			error(" range specified to @[hv]lookup");
			cellerror = CELLERROR;
		    }
		    break;
		}
	    }
	}



	  if (p && p->label) {
	    pr = scxmalloc(strlen(p->label) + 1);
	    (void) strcpy(pr, p->label);
	    if (p->cellerror)
	      cellerror = CELLINVALID;
	  } else {
	    pr = NULL;
	  }
	scxfree(s);
    }
    return pr;
}

/* a range expression is an expression, possibly referencing other cells,
   intended to determine in-/exclusion of a particular cell into the range.
   If the conditional expression references cells, these cell references
   might need to be offset for each new cell in the range, if they are
   relative references. This is what this function does.  -nlin */

static void 
offset_expression(struct enode *e, int Rdelta, int Cdelta)
{
    if (!e) return;

    /* nlin: basically copied from cmds.c, function "copye"
       (should be refactored) */

    switch (e->op) {
	case O_VAR:
	    {
		int newrow, newcol;

		newrow = e->e.v.vf & FIX_ROW ? e->e.v.vp->row :
		    e->e.v.vp->row + Rdelta;
		newcol = e->e.v.vf & FIX_COL ? e->e.v.vp->col :
		    e->e.v.vp->col + Cdelta;
		e->e.v.vp = lookat(newrow, newcol);
		break;
	    }
	/* nlin: don't know what these cases mean, but they are cases
	   which cannot be allowed to fall through to the default case,
	   because they have no left/right children */
	case 'k':
	    break;
	case 'f':
	    break;
	case '$':
	    break;
	default:
	    offset_expression(e->e.o.right, Rdelta, Cdelta);
	    offset_expression(e->e.o.left, Rdelta, Cdelta);
	    break;
    }
}

static double
docount(int minr, int minc, int maxr, int maxc, struct enode *e)
{
    int v = 0;
    register int r, c;
    register struct ent *p;

    for (r=minr; r<=maxr; r++) {
	for (c=minc; c<=maxc; c++) {
	    if (((p = *ATBL(tbl, r, c)) && p->flags & is_valid) 
	    && ((!e) || eval(e))) {
		if (p->cellerror)
		    cellerror = CELLINVALID;
		v++;
	    }
	    offset_expression(e, 0, 1);
	}
	offset_expression(e, 1, -(maxc-minc+1));
    }
    offset_expression(e, -(maxr-minr+1), 0);
    return v;
}

static double
dosum(int minr, int minc, int maxr, int maxc, struct enode *e)
{
    double v = 0.0;
    register int r, c;
    register struct ent *p;

    for (r=minr; r<=maxr; r++) {
	for (c=minc; c<=maxc; c++) {
	    if (((p = *ATBL(tbl, r, c)) && p->flags & is_valid)
		&& ((!e) || eval(e))) { /* nlin: code to evaluate expression */
                if (p->cellerror)
                    cellerror = CELLINVALID;
                v += p->v;
            }
            offset_expression(e, 0, 1);
	}
        offset_expression(e, 1, -(maxc-minc+1));
    }
    offset_expression(e, -(maxr-minr+1), 0);
    return v;
}

static double
doprod(int minr, int minc, int maxr, int maxc, struct enode *e)
{
    double v = 1.0;
    register int r, c;
    register struct ent *p;

    for (r=minr; r<=maxr; r++) {
        for (c=minc; c<=maxc; c++) {
            if (((p = *ATBL(tbl, r, c)) && p->flags & is_valid)
	    && ((!e) || eval(e))) {
		if (p->cellerror)
		    cellerror = CELLINVALID;
		v *= p->v;
	    }
	    offset_expression(e, 0, 1);
	}
	offset_expression(e, 1, -(maxc-minc+1));
    }
    offset_expression(e, -(maxr-minr+1), 0);
    return v;
}

static double
doavg(int minr, int minc, int maxr, int maxc, struct enode *e)
{
    double v;
    register int r, c, count;
    register struct ent *p;

    v = 0.0;
    count = 0;
    for (r = minr; r<=maxr; r++) {
	for (c = minc; c<=maxc; c++) {
	    if (((p = *ATBL(tbl, r, c)) && p->flags & is_valid)
	    && ((!e) || eval(e))) {
		if (p->cellerror)
		    cellerror = CELLINVALID;
		v += p->v;
		count++;
	    }
	    offset_expression(e, 0, 1);
	}
	offset_expression(e, 1, -(maxc-minc+1));
    }
    offset_expression(e, -(maxr-minr+1), 0);

    if (count == 0) 
	return (double) 0;

    return v / (double)count;
}

static double
dostddev(int minr, int minc, int maxr, int maxc, struct enode *e)
{
    double lp, rp, v, nd;
    register int r, c, n;
    register struct ent *p;

    n = 0;
    lp = 0;
    rp = 0;
    for (r = minr; r<=maxr; r++) {
	for (c = minc; c<=maxc; c++) {
	    if (((p = *ATBL(tbl, r, c)) && p->flags & is_valid)
	    && ((!e) || eval(e))) {
		if (p->cellerror)
		    cellerror = CELLINVALID;
		v = p->v;
		lp += v*v;
		rp += v;
		n++;
	    }
	    offset_expression(e, 0, 1);
	}
	offset_expression(e, 1, -(maxc-minc+1));
    }
    offset_expression(e, -(maxr-minr+1), 0);

    if (n == 0 || n == 1) 
	return (double) 0;
    nd = (double) n;
    return sqrt((nd*lp-rp*rp)/(nd*(nd-1)));
}

static double
doentropy(int minr, int minc, int maxr, int maxc)
{
    double v, vsum = 0.0, H = 0.0;
    int r, c, n = 0;
    struct ent *p;

    for (r=minr; r<=maxr; r++) {
	for (c=minc; c<=maxc; c++) {
	    if ((p = *ATBL(tbl, r, c)) && p->flags & is_valid) {
		if (p->cellerror)
		    cellerror = CELLINVALID;
		v = p->v;
		if (v >= 1.0 || v < 0) return 0.0;
		vsum += v;
		if (vsum > 1.0) return 0.0;
		if (v > 0.0) {
		    H += v * log2(v);
		    n++;
		}
	    }
	}
    }
    if (n == 0 || n == 1) 
	return 0.0;
    return -H;
}

static double
domax(int minr, int minc, int maxr, int maxc, struct enode *e)
{
    double v = 0.0;
    register int r, c, count;
    register struct ent *p;

    count = 0;
    for (r = minr; r<=maxr; r++) {
	for (c = minc; c<=maxc; c++) {
	    if (((p = *ATBL(tbl, r, c)) && p->flags & is_valid) 
	    && ((!e) || eval(e))) {
		if (p->cellerror)
		    cellerror = CELLINVALID;
		if (!count) {
		    v = p->v;
		    count++;
		} else if (p->v > v)
		    v = p->v;
	    }
	    offset_expression(e, 0, 1);
	}
	offset_expression(e, 1, -(maxc-minc+1));
    }
    offset_expression(e, -(maxr-minr+1), 0);

    if (count == 0) 
	return (double) 0;

    return v;
}

static double
domin(int minr, int minc, int maxr, int maxc, struct enode *e)
{
    double v = 0.0;
    register int r, c, count;
    register struct ent *p;

    count = 0;
    for (r = minr; r<=maxr; r++) {
	for (c = minc; c<=maxc; c++) {
	    if (((p = *ATBL(tbl, r, c)) && p->flags & is_valid) 
	    && ((!e) || eval(e))) {
		if (p->cellerror)
		    cellerror = CELLINVALID;

		if (!count) {
		    v = p->v;
		    count++;
		} else if (p->v < v)
		    v = p->v;
	    }
	    offset_expression(e, 0, 1);
	}
	offset_expression(e, 1, -(maxc-minc+1));
    }
    offset_expression(e, -(maxr-minr+1), 0);

    if (count == 0) 
	return (double) 0;

    return v;
}

#define sec_min 60
#define sec_hr  3600L
#define sec_day 86400L
#define sec_yr  31471200L     /* 364.25 days/yr */
#define sec_mo  2622600L       /* sec_yr/12: sort of an average */
int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

double
dodts(int mo, int day, int yr)
{
    long trial;
    register struct tm *tp; 
    register int i;
    register long jdate;

    mdays[1] = 28 + (yr%4 == 0);

    if (mo < 1 || mo > 12 || day < 1 || day > mdays[--mo] ||
	yr > 1999 || yr < 1970) {
	error("@dts: invalid argument");
	cellerror = CELLERROR;
	return(0.0);
    }

    jdate = day-1;
    for (i=0; i<mo; i++)
	jdate += mdays[i];
    for (i = 1970; i < yr; i++)
	jdate += 365 + (i%4 == 0);

    trial = jdate * sec_day; 

    yr -= 1900;

    tp = localtime(&trial);

    if (tp->tm_year != yr) {
	/*
	 * We may fail this test once a year because of time zone
	 * and daylight savings time errors.  This bounces the
	 * trial time past the boundary.  The error introduced is
	 * corrected below.
	 */
	trial += sec_day*(yr - tp->tm_year);
	tp = localtime(&trial);
    }
    if (tp->tm_mon != mo) {
	/* We may fail this test once a month.  */
	trial += sec_day*(mo - tp->tm_mon);
	tp = localtime(&trial);
    }
    if (tp->tm_mday + tp->tm_hour + tp->tm_min + tp->tm_sec != day) {
	trial -= (tp->tm_mday - day)*sec_day +  tp->tm_hour*sec_hr
	    + tp->tm_min*sec_min + tp->tm_sec;
    }

    return (double) trial;
}

double 
normcdf (const double z)
/* returns prob that a normal(0, 1) r.v. is > z */
{
    const double a1 = .0705230784;
    const double a2 = .0422820123;
    const double a3 = .0092705272;
    const double a4 = .0001520143;
    const double a5 = .0002765672;
    const double a6 = .0000430638;
    double absx, xx, zz, p;

    absx = (z > 0.0)? z : -z;
    if (absx <= 14.14) zz = .7071067812 * absx;
    else zz = 10.0;
    xx = a6*zz + a5;
    xx = xx*zz + a4;
    xx = xx*zz + a3;
    xx = xx*zz + a2;
    xx = xx*zz + a1;
    xx = xx*zz + 1.0;
    p = 0.5 * pow(xx, -16.0);
    if (z > 0.0) p = 1.0 - p;
    return p;
}


double 
normal(void) 
     /* Box and Muller method */
{
    double x, y, scale = 1.0/RAND_MAX;

    x = (double) rand() * scale;
    y = (double) rand() * scale;
    return sqrt(-2. * log(x)) * cos(2. * PI * y);
}

double
uniform(void) 
{
    double scale = 100.0/RAND_MAX;

    return (double) rand() * scale;
}

static double
dotts(int hr, int min,int  sec)
{
    if (hr < 0 || hr > 23 || min < 0 || min > 59 || sec < 0 || sec > 59) {
	error ("@tts: Invalid argument");
	cellerror = CELLERROR;
	return 0.0;
    }
    return (double)(sec + min*60 + hr*3600);
}

static double
dotime(int which, double when)
{
    static long t_cache;
    static struct tm tm_cache;
    struct tm *tp;
    long tloc;

    if (which == NOW) 
	return (double) time(NULL);

    tloc = (long)when;

    if (tloc != t_cache) {
	tp = localtime(&tloc);
	tm_cache = *tp;
	tm_cache.tm_mon += 1;
	tm_cache.tm_year += 1900;
	t_cache = tloc;
    }

    switch (which) {
    case HOUR: return (double)(tm_cache.tm_hour);
    case MINUTE: return (double)(tm_cache.tm_min);
    case SECOND: return (double)(tm_cache.tm_sec);
    case MONTH: return (double)(tm_cache.tm_mon);
    case DAY: return (double)(tm_cache.tm_mday);
    case YEAR: return (double)(tm_cache.tm_year);
    }
    /* Safety net */
    cellerror = CELLERROR;
    return 0.0;
}

static double
doston(char *s)
{
    double v;

    if (!s)
	return 0.0;

    v = atof(s);
    scxfree(s);
    return v;
}

static double
doeqs(char *s1, char *s2)
{
    double v;

    if (!s1 && !s2)
	return 1.0;

    if (!s1 || !s2)
	v = 0.0;
    else if (strcmp(s1, s2) == 0)
	v = 1.0;
    else
	v = 0.0;

    if (s1)
    	scxfree(s1);

    if (s2)
    	scxfree(s2);

    return v;
}


/*
 * Given a string representing a column name and a value which is a column
 * number, return a pointer to the selected cell's entry, if any, else NULL.
 * Use only the integer part of the column number.  Always free the string.
 */

static struct ent *
getent (char *colstr, double rowdoub)
{
    int collen;		/* length of string */
    int row, col;	/* integer values   */
    struct ent *p = NULL;	/* selected entry   */

    if (!colstr) {
	cellerror = CELLERROR;
	return NULL;
    }

    if (((row = (int) floor (rowdoub)) >= 0)
	&& (row < maxrows)				/* in range */
	&& ((collen = strlen (colstr)) <= 2)	/* not too long */
	&& ((col = atocol (colstr, collen)) >= 0)
	&& (col < maxcols)) {			/* in range */
	
	p = *ATBL(tbl, row, col);
	if ((p != NULL) && p->cellerror)
	    cellerror = CELLINVALID;
    }
    scxfree(colstr);
    return p;
}

/*
 * Given a string representing a column name and a value which is a column
 * number, return the selected cell's numeric value, if any.
 */

static double
donval(char *colstr, double rowdoub)
{
    struct ent *ep;

    return ((ep = getent (colstr, rowdoub)) && ((ep -> flags) & is_valid)) ?
	    (ep -> v) : 0.0;
}

/*
 *	The list routines (e.g. dolmax) are called with an LMAX enode.
 *	The left pointer is a chain of ELIST nodes, the right pointer
 *	is a value.
 */

static double
dolmax(struct enode *ep)
{
    register int count = 0;
    register double maxval = 0; /* Assignment to shut up lint */
    register struct enode *p;
    register double v;

    cellerror = CELLOK;
    for (p = ep; p; p = p->e.o.left) {
	v = eval(p->e.o.right);
	if (!count || v > maxval) {
	    maxval = v; count++;
	}
    }
    if (count) return maxval;
    else return 0.0;
}

static double
dolmin(struct enode *ep)
{
    register int count = 0;
    register double minval = 0; /* Assignment to shut up lint */
    register struct enode *p;
    register double v;

    cellerror = CELLOK;
    for (p = ep; p; p = p->e.o.left) {
	v = eval(p->e.o.right);
	if (!count || v < minval) {
	    minval = v; count++;
	}
    }
    if (count) return minval;
    else return 0.0;
}

static double 
eval(register struct enode *e)
{
    if (e == NULL) {
	cellerror = CELLINVALID;
	return 0.0;
    }
    switch (e->op) {
    case '+': return eval(e->e.o.left) + eval(e->e.o.right);
    case 'P': return eval(e->e.o.left) + eval(e->e.o.right);
    case '-': return eval(e->e.o.left) - eval(e->e.o.right);
    case '*': return eval(e->e.o.left) * eval(e->e.o.right);
    case '/':   { 
	double num, denom;

	num = eval(e->e.o.left);
	denom = eval(e->e.o.right);
	if (denom)
	    return num/denom;
	else {
	    cellerror = CELLERROR;
	    return 0.0;
	}
    }
    case '%':  {	
	double num, denom;

	num = floor(eval(e->e.o.left));
	denom = floor(eval(e->e.o.right));
	if (denom)
	    return num - floor(num/denom)*denom;
	else {
	    cellerror = CELLERROR;
	    return 0.0;
	}
    }
    case '^':	return (fn2_eval(pow, eval(e->e.o.left), eval(e->e.o.right)));
    case '<':	return (eval(e->e.o.left) < eval(e->e.o.right));
    case '=':	return (eval(e->e.o.left) == eval(e->e.o.right));
    case '>':	return (eval(e->e.o.left) > eval(e->e.o.right));
    case '&':	return (eval(e->e.o.left) && eval(e->e.o.right));
    case '|':	return (eval(e->e.o.left) || eval(e->e.o.right));
    case IF:
    case '?':	return eval(e->e.o.left) ? eval(e->e.o.right->e.o.left)
		    : eval(e->e.o.right->e.o.right);
    case 'm':	return (-eval(e->e.o.right));
    case 'x':
    case 'f':	return (eval(e->e.o.right));
    case '~':	return (eval(e->e.o.right) == 0.0);
    case O_CONST:	
	return (e->e.k);
    case O_VAR:	
	if (e->e.v.vp->cellerror)
	    cellerror = CELLINVALID;
	return (e->e.v.vp->v);
    case INDEX:
    case LOOKUP:
    case HLOOKUP:
    case VLOOKUP: {
	int r,c;
	int maxr, maxc;
	int minr, minc;

	maxr = e->e.o.right->e.r.right.vp -> row;
	maxc = e->e.o.right->e.r.right.vp -> col;
	minr = e->e.o.right->e.r.left.vp -> row;
	minc = e->e.o.right->e.r.left.vp -> col;
	if (minr>maxr) r = maxr, maxr = minr, minr = r;
	if (minc>maxc) c = maxc, maxc = minc, minc = c;
	switch(e->op) {
	case LOOKUP:
	    return dolookup(e->e.o.left, minr, minc, maxr, maxc,
			    minr==maxr, minc==maxc);
	case HLOOKUP:
	    return dolookup(e->e.o.left->e.o.left, minr,minc,maxr,maxc,
			    (int) eval(e->e.o.left->e.o.right), 0);
	case VLOOKUP:
	    return dolookup(e->e.o.left->e.o.left, minr,minc,maxr,maxc,
			    0, (int) eval(e->e.o.left->e.o.right));
	case INDEX:
	    return doindex(eval(e->e.o.left), minr, minc, maxr, maxc);
	}
    }
    case REDUCE | '+':      /* sum */
    case REDUCE | '*':      /* prod */
    case REDUCE | 'a':      /* avg */
    case REDUCE | 'c':      /* count */
    case REDUCE | 'e':      /* entropy */
    case REDUCE | 's':      /* stddev */
    case REDUCE | IRR:      /* internal rate of return */
    case REDUCE | MAXR:     /* max-range */
    case REDUCE | MINR:  {  /* min-range */
	int r, c;
	int maxr, maxc;
	int minr, minc;

	maxr = e->e.r.right.vp->row;
	maxc = e->e.r.right.vp->col;
	minr = e->e.r.left.vp->row;
	minc = e->e.r.left.vp->col;
	if (minr > maxr) r = maxr, maxr = minr, minr = r;
	if (minc > maxc) c = maxc, maxc = minc, minc = c;
	switch (e->op & ~REDUCE) {
	case '+': return dosum(minr, minc, maxr, maxc, e->e.r.expr);
	case '*': return doprod(minr, minc, maxr, maxc, e->e.r.expr);
	case 'a': return doavg(minr, minc, maxr, maxc, e->e.r.expr);
	case 'c': return docount(minr, minc, maxr, maxc, e->e.r.expr);
	case 'e': return doentropy(minr, minc, maxr, maxc);
	case 's': return dostddev(minr, minc, maxr, maxc, e->e.r.expr);
	case IRR: return doirr(minr, minc, maxr, maxc);
	case MAXR: return domax(minr, minc, maxr, maxc, e->e.r.expr);
	case MINR: return domin(minr, minc, maxr, maxc, e->e.r.expr);
	}
    }
    case ABS:	 return fn1_eval(fabs, eval(e->e.o.right));
    case ACOS:	 return fn1_eval(acos, eval(e->e.o.right));
    case ASIN:	 return fn1_eval(asin, eval(e->e.o.right));
    case ATAN:	 return fn1_eval(atan, eval(e->e.o.right));
    case ATAN2:	 return fn2_eval(atan2, eval(e->e.o.left), eval(e->e.o.right));
    case CEIL:	 return fn1_eval(ceil, eval(e->e.o.right));
    case COS:	 return fn1_eval(cos, eval(e->e.o.right));
    case EXP:	 return fn1_eval(exp, eval(e->e.o.right));
    case FABS:	 return fn1_eval(fabs, eval(e->e.o.right));
    case FLOOR:	 return fn1_eval(floor, eval(e->e.o.right));
    case HYPOT:	 return fn2_eval(hypot, eval(e->e.o.left), eval(e->e.o.right));
    case LOG:	 return fn1_eval(log, eval(e->e.o.right));
    case LOG10:	 return fn1_eval(log10, eval(e->e.o.right));
    case LOG2:	 return log2(eval(e->e.o.right));
    case POW:	 return fn2_eval(pow, eval(e->e.o.left), eval(e->e.o.right));
    case SIN:	 return fn1_eval(sin, eval(e->e.o.right));
    case SQRT:	 return fn1_eval(sqrt, eval(e->e.o.right));
    case TAN:	 return fn1_eval(tan, eval(e->e.o.right));
    case DTR:	 return dtr(eval(e->e.o.right));
    case RTD:	 return rtd(eval(e->e.o.right));
    case RND:
	if (rndinfinity) {
	    double temp = eval(e->e.o.right);
	    return temp-floor(temp) < 0.5 ?
		   floor(temp) : ceil(temp);
	} else
	    return rint(eval(e->e.o.right));
    case ROUND: {
	int prec = (int) eval(e->e.o.right);
	double scal = 1;
	if (0 < prec)
	    do scal *= 10; while (0 < --prec);
	else if (prec < 0)
	    do scal /= 10; while (++prec < 0);

	if (rndinfinity) {
	    double temp = eval(e->e.o.left);
	    temp *= scal;
	    temp = ((temp-floor(temp)) < 0.5 ?
		    floor(temp) : ceil(temp));
	    return temp / scal;
	}  else
	    return rint(eval(e->e.o.left) * scal) / scal;
    }
    case FV:
    case PV:
    case PMT:	return (finfunc(e->op,eval(e->e.o.left),
			       eval(e->e.o.right->e.o.left),
			       eval(e->e.o.right->e.o.right)));
    case HOUR:	return (dotime(HOUR, eval(e->e.o.right)));
    case MINUTE:	return (dotime(MINUTE, eval(e->e.o.right)));
    case SECOND:	return (dotime(SECOND, eval(e->e.o.right)));
    case MONTH:	return (dotime(MONTH, eval(e->e.o.right)));
    case DAY:	return (dotime(DAY, eval(e->e.o.right)));
    case YEAR:	return (dotime(YEAR, eval(e->e.o.right)));
    case NOW:	return (dotime(NOW, 0.0));
    case DTS:	return (dodts((int)eval(e->e.o.left),
			      (int)eval(e->e.o.right->e.o.left),
			      (int)eval(e->e.o.right->e.o.right)));
    case TTS:	return (dotts((int)eval(e->e.o.left),
			      (int)eval(e->e.o.right->e.o.left),
			      (int)eval(e->e.o.right->e.o.right)));
    case STON:	return (doston(seval(e->e.o.right)));
    case EQS:       return (doeqs(seval(e->e.o.right),seval(e->e.o.left)));
    case LMAX:	return dolmax(e);
    case LMIN:	return dolmin(e);
    case NVAL:  return (donval(seval(e->e.o.left),eval(e->e.o.right)));
    case MYROW:	return ((double) gmyrow);
    case MYCOL:	return ((double) gmycol);
    case NUMITER: return ((double) repct);
    case RAND: return uniform();
    case NORM: return normal();
    case NORMCDF: return normcdf(eval(e->e.o.right));
    default: error ("Illegal numeric expression");
	exprerr = 1;
    }
    cellerror = CELLERROR;
    return 0.0;
}

static sig_type   /* static added by Bob Parbs 12-92 */
eval_fpe(int sig) /* Trap for FPE errors in eval */
{
    /* re-establish signal handler for next time */
    signal(SIGFPE, eval_fpe);
    longjmp(fpe_save, 1);
}

static double
fn1_eval(double (*fn)(), double arg)
{
    double res;
    errno = 0;
    res = (*fn)(arg);
    if(errno)
	cellerror = CELLERROR;

    return res;
}

static double
fn2_eval(double (*fn)(), double arg1, double arg2)
{
    double res;
    errno = 0;
    res = (*fn)(arg1, arg2);
    if(errno)
	cellerror = CELLERROR;

    return res;
}

/* 
 * Rules for string functions:
 * Take string arguments which they scxfree.
 * All returned strings are assumed to be xalloced.
 */

static char *
docat(register char *s1, register char *s2)
{
    register char *p;
    char *arg1, *arg2;

    if (!s1 && !s2)
	return NULL;
    arg1 = s1 ? s1 : "";
    arg2 = s2 ? s2 : "";
    p = scxmalloc(strlen(arg1) + strlen(arg2) + 1);
    strcpy(p, arg1);
    strcat(p, arg2);
    if (s1)
        scxfree(s1);
    if (s2)
        scxfree(s2);
    return p;
}

static char *
dodate(long tloc)
{
    char *tp, *p;

    tp = ctime(&tloc);
    tp[24] = '\0';
    p = scxmalloc((size_t) 25);
    strcpy(p, tp);
    return p;
}


static char *
dofmt(char *fmtstr, double v)
{
    char buff[FBUFLEN];
    char *p;

    if (!fmtstr)
	return NULL;
    sprintf(buff, fmtstr, v);
    p = scxmalloc(strlen(buff) + 1);
    strcpy(p, buff);
    scxfree(fmtstr);
    return p;
}

/*
 * Given a command name and a value, run the command with the given value and
 * read and return its first output line (only) as an allocated string, always
 * a copy of prevstr, which is set appropriately first unless external
 * functions are disabled, in which case the previous value is used.  The
 * handling of prevstr and freeing of command is tricky.  Returning an
 * allocated string in all cases, even if null, insures cell expressions are
 * written to files, etc.
 */

static char *
doext (char *command, double value)
{
    static char *prevstr;	/* previous result */
    static unsigned prevlen;
    char buff[FBUFLEN];		/* command line/return, not permanently alloc */

    if (!extfunc) {
	sprintf(stringbuf, "Warning: external functions disabled; "
		"using %s value",
		((prevstr == NULL) || (*prevstr == '\0')) ?
		"null" : "previous");
	error(stringbuf);

	if (command)
	    scxfree (command);
    } else {
	if ((!command) || (!*command)) {
	    error ("Warning: external function given null command name");
	    cellerror = CELLERROR;
	    if (command) scxfree (command);
	} else {
	    FILE *pp;

	    sprintf (buff, "%s %g", command, value); /* build cmd line */
	    scxfree (command);

	    error ("Running external function...");

	    if ((pp = popen(buff, "r")) == NULL) {	/* run it */
		sprintf(stringbuf, "Warning: running \"%s\" failed", buff);
		error(stringbuf);
		cellerror = CELLERROR;
	    }
	    else {
		if (fgets (buff, sizeof(buff)-1, pp) == NULL)	/* one line */
		    error ("Warning: external function returned nothing");
		else {
		    char *cp;

		    error ("");				/* erase notice */
		    buff[sizeof(buff)-1] = '\0';

		    if ((cp = strchr (buff, '\n')))	/* contains newline */
			*cp = '\0';			/* end string there */

		    if (strlen(buff) + 1 > prevlen) {
			prevlen = strlen(buff) + 40;
			prevstr = scxrealloc(prevstr, prevlen);
		    }
		    strcpy (prevstr, buff);
		    /* save alloc'd copy */
		}
		pclose(pp);

	    } /* else */
	} /* else */
    } /* else */
    if (prevstr)
	return strcpy(scxmalloc(strlen(prevstr) + 1), prevstr);
    else
	return strcpy(scxmalloc(1), "");
}

/*
 * Given a string representing a column name and a value which is a column
 * number, return the selected cell's string value, if any.  Even if none,
 * still allocate and return a null string so the cell has a label value so
 * the expression is saved in a file, etc.
 */

static char *
dosval (char *colstr, double rowdoub)
{
    struct ent *ep;
    char *llabel;

    llabel = (ep = getent (colstr, rowdoub)) ? (ep -> label) : "";
    return strcpy(scxmalloc(strlen(llabel) + 1), llabel);
}

/*
 * Substring:  Note that v1 and v2 are one-based to users, but zero-based
 * when calling this routine.
 */

static char *
dosubstr(char *s, register int v1, register int v2)
{
    register char *s1, *s2;
    char *p;

    if (!s)
	return NULL;

    if (v2 >= (int)strlen (s))		/* past end */
	v2 =  strlen (s) - 1;		/* to end   */

    if (v1 < 0 || v1 > v2) {		/* out of range, return null string */
	scxfree(s);
	p = scxmalloc(1);
	p[0] = '\0';
	return p;
    }
    s2 = p = scxmalloc(v2 - v1 + 2);
    s1 = &s[v1];
    for(; v1 <= v2; s1++, s2++, v1++)
	*s2 = *s1;
    *s2 = '\0';
    scxfree(s);
    return p;
}

/*
 * character casing: make upper case, make lower case
 */

static char *
docase(int acase, char *s)
{
    char *p = s;

    if (s == NULL)
	return NULL;

    if (acase == UPPER) {
        while (*p != '\0') {
	    if (islower(*p))
		*p = toupper(*p);
	    p++;
	}
    }
    else if (acase == LOWER) {
	while (*p != '\0') {
	    if (isupper(*p))
		*p = tolower(*p);
	    p++;
	}
    }
    return s;
}

/*
 * make proper capitals of every word in a string
 * if the string has mixed case we say the string is lower
 *	and we will upcase only first letters of words
 * if the string is all upper we will lower rest of words.
 */

static char *
docapital(char *s)
{
    char *p;
    int skip = 1;
    int AllUpper = 1;

    if (s == NULL)
	return NULL;
    for (p = s; *p != '\0' && AllUpper != 0; p++)
	if (isalpha(*p) && islower(*p)) AllUpper = 0;
    for (p = s; *p != '\0'; p++) {
	if (!isalnum(*p))
	    skip = 1;
	else
	    if (skip == 1) {
		skip = 0;
		if (islower(*p))
		    *p = toupper(*p);
	    }
	    else	/* if the string was all upper before */
		if (isupper(*p) && AllUpper != 0)
		    *p = tolower(*p);
    }
    return s;
}

static char *
seval(register struct enode *se)
{
    register char *p;

    if (se == NULL) return NULL;
    switch (se->op) {
    case O_SCONST: p = scxmalloc(strlen(se->e.s) + 1);
	strcpy(p, se->e.s);
	return(p);
    case O_VAR:    {
	struct ent *ep;
	ep = se->e.v.vp;

	if (!ep->label)
	    return NULL;
	p = scxmalloc(strlen(ep->label) + 1);
	strcpy(p, ep->label);
	return(p);
    }
    case '#':    return docat(seval(se->e.o.left), seval(se->e.o.right));
    case 'f':    return seval(se->e.o.right);
    case IF:
    case '?':    return eval(se->e.o.left) ? seval(se->e.o.right->e.o.left)
			: seval(se->e.o.right->e.o.right);
    case DATE:   return dodate((long)(eval(se->e.o.right)));
    case FMT:    return dofmt(seval(se->e.o.left), eval(se->e.o.right));
    case UPPER:  return docase(UPPER, seval(se->e.o.right));
    case LOWER:  return docase(LOWER, seval(se->e.o.right));
    case CAPITAL:return docapital(seval(se->e.o.right));
    case STINDEX:
    case LOOKUP:
    case HLOOKUP:
    case VLOOKUP: {
	    register int r,c;
	    register int maxr, maxc;
	    register int minr, minc;

	    maxr = se->e.o.right->e.r.right.vp -> row;
	    maxc = se->e.o.right->e.r.right.vp -> col;
	    minr = se->e.o.right->e.r.left.vp -> row;
	    minc = se->e.o.right->e.r.left.vp -> col;
	    if (minr > maxr) r = maxr, maxr = minr, minr = r;
	    if (minc > maxc) c = maxc, maxc = minc, minc = c;
	    switch (se->op) {
	    case LOOKUP:
	      return dostlookup(se->e.o.left, minr, minc, maxr, maxc,
			      minr==maxr, minc==maxc);
	    case HLOOKUP:
	      return dostlookup(se->e.o.left->e.o.left, minr,minc,maxr,maxc,
			      (int) eval(se->e.o.left->e.o.right), 0);
	    case VLOOKUP:
	      return dostlookup(se->e.o.left->e.o.left, minr,minc,maxr,maxc,
			      0, (int) eval(se->e.o.left->e.o.right));
	    case STINDEX:
	      return dostindex(eval(se->e.o.left), minr, minc, maxr, maxc);
	    }
	}
    case EXT:    return doext(seval(se->e.o.left), eval(se->e.o.right));
    case SVAL:   return dosval(seval(se->e.o.left), eval(se->e.o.right));
    case SUBSTR: return dosubstr(seval(se->e.o.left),
				 (int)eval(se->e.o.right->e.o.left) - 1,
				 (int)eval(se->e.o.right->e.o.right) - 1);
    case COLTOA: return strcpy(scxmalloc(10),
			       coltoa((int)eval(se->e.o.right)+1));
    default:
	error ("Illegal string expression");
	exprerr = 1;
	return NULL;
    }
}

/*
 * The graph formed by cell expressions which use other cells's values is not
 * evaluated "bottom up".  The whole table is merely re-evaluated cell by cell,
 * top to bottom, left to right, in RealEvalAll().  Each cell's expression uses
 * constants in other cells.  However, RealEvalAll() notices when a cell gets a
 * new numeric or string value, and reports if this happens for any cell.
 * EvalAll() repeats calling RealEvalAll() until there are no changes or the
 * evaluation count expires.
 */

int propagation = 10;	/* max number of times to try calculation */
int repct = 1;		/* Make repct a global variable so that the 
			   function @numiter can access it */

void
setiterations(int i)
{
    if (i<1) {
	error("iteration count must be at least 1");
	propagation = 1;
    }
    else propagation = i;
}

void
EvalAll(void) 
{
    int lastcnt;
  
    repct = 1;
    signal(SIGFPE, eval_fpe);

    while ((lastcnt = RealEvalAll()) && (++repct <= propagation))
	;
    if (propagation > 1 && lastcnt > 0) {
	sprintf(stringbuf, "Still changing after %d iterations",
		propagation - 1);
	error(stringbuf);
    }
    signal(SIGFPE, doquit);
}

/*
 * Evaluate all cells which have expressions and alter their numeric or string
 * values.  Return the number of cells which changed.
 */

static int 
RealEvalAll(void) 
{
    register int i, j;
    int chgct = 0;
    register struct ent *p;

    if (calc_order == BYROWS) {
	for (i=0; i<=maxrow; i++) {
	    for (j=0; j<=maxcol; j++) {
		if ((p = *ATBL(tbl, i, j)) && 
		    !(p->flags & is_locked) && p->expr) 
		    RealEvalOne(p, i, j, &chgct);
	    }
	}
    }
    else if (calc_order == BYCOLS) {
	for (j=0; j<=maxcol; j++) {
	    for (i=0; i<=maxrow; i++) {
		if ((p = *ATBL(tbl, i, j)) && 
		    !(p->flags & is_locked) && p->expr) 
		    RealEvalOne(p, i, j, &chgct);
	    }
	}
    }
    else error("Internal error calc_order");
    return chgct;
}

static void                /* static added by Bob Parbs 12-92 */
RealEvalOne(register struct ent *p, int i, int j, int *chgct)
{
    static double v, diff;

    if (p->flags & is_strexpr) {
	char *v;
	if (setjmp(fpe_save)) {
	    sprintf(stringbuf, "Floating point exception %s", v_name(i, j));
	    error(stringbuf);
	    cellerror = CELLERROR;
	    v = "";
	} else {
	    cellerror = CELLOK;
	    v = seval(p->expr);
	}
	p->cellerror = cellerror;
	if (!v && !p->label) /* Everything's fine */
	    return;
	if (!p->label || !v || strcmp(v, p->label) != 0 || cellerror) {
	    (*chgct)++;
	    p->flags |= is_changed;
	    changed++;
	}
	if(p->label)
	    scxfree(p->label);
	p->label = v;
    } else { /* cell with numeric content */
	if (setjmp(fpe_save)) {
	    sprintf(stringbuf, "Floating point exception %s", v_name(i, j));
	    error(stringbuf);
	    cellerror = CELLERROR;
	    v = 0.0;
	} else {
	    cellerror = CELLOK;
	    gmyrow=i; gmycol=j;
	    v = eval(p->expr);
	    diff = v - p->v;
	}
	/* Modified the test here.  Allin Cottrell, May 2001 */
	if ((p->cellerror = cellerror) || fabs(diff) > 100 * DBL_EPSILON) {
	    p->v = v;
	    if (cellerror)
		; /* don't keep eval'ing an error */
	    else if (p->expr && 
		     (p->expr->op == RAND || p->expr->op == NORM))
		; /* don't keep eval'ing random numbers */
	    else 
		(*chgct)++;
	    p->flags |= is_changed | is_valid;
	    changed++;
	}
    }
}

struct enode *
new(int op, struct enode *a1, struct enode *a2)
{
    register struct enode *p;

    if (freeenodes) {
	p = freeenodes;
	freeenodes = p->e.o.left;
    } else
	p = scxmalloc(sizeof *p);
    p->op = op;
    p->e.o.left = a1;
    p->e.o.right = a2;
    return p;
}

struct enode *
new_var(int op, struct ent_ptr a1)
{
    register struct enode *p;

    if (freeenodes) {
	p = freeenodes;
	freeenodes = p->e.o.left;
    } else
	p = scxmalloc(sizeof *p);
    p->op = op;
    p->e.v = a1;
    return p;
}

struct enode *
new_range(int op, struct range_s a1)
{
    register struct enode *p;

    if (freeenodes) {
	p = freeenodes;
	freeenodes = p->e.o.left;
    } else
	p = scxmalloc(sizeof *p);
    p->op = op;
    p->e.r = a1;
    return p;
}

struct enode *
new_const(int op, double a1)
{
    register struct enode *p;

    if (freeenodes) {	/* reuse an already free'd enode */
	p = freeenodes;
	freeenodes = p->e.o.left;
    } else
	p = scxmalloc(sizeof *p);
    p->op = op;
    p->e.k = a1;
    return p;
}

struct enode *
new_str(char *s)
{
    register struct enode *p;

    if (freeenodes) {	/* reuse an already free'd enode */
	p = freeenodes;
	freeenodes = p->e.o.left;
    } else
	p = scxmalloc(sizeof *p);
    p->op = O_SCONST;
    p->e.s = s;
    return(p);
}

void
copy(struct ent *v1, struct ent *v2, struct ent *dv1, struct ent *dv2)
{
    int minsr, minsc;
    int maxsr, maxsc;
    int mindr, mindc;
    int maxdr, maxdc;
    int vr, vc;
    int r, c;

    mindr = dv1->row;
    mindc = dv1->col;
    maxdr = dv2->row;
    maxdc = dv2->col;
    if (mindr > maxdr) r = maxdr, maxdr = mindr, mindr = r;
    if (mindc > maxdc) c = maxdc, maxdc = mindc, mindc = c;
    maxsr = v2->row;
    maxsc = v2->col;
    minsr = v1->row;
    minsc = v1->col;
    if (minsr > maxsr) r = maxsr, maxsr = minsr, minsr = r;
    if (minsc > maxsc) c = maxsc, maxsc = minsc, minsc = c;
    checkbounds(&maxdr, &maxdc);

    erase_area(mindr, mindc, maxdr, maxdc);
    if (minsr == maxsr && minsc == maxsc) {
	/* Source is a single cell */
	for(vr = mindr; vr <= maxdr; vr++)
	    for (vc = mindc; vc <= maxdc; vc++)
		copyrtv(vr, vc, minsr, minsc, maxsr, maxsc);
    } else if (minsr == maxsr) {
	/* Source is a single row */
	for (vr = mindr; vr <= maxdr; vr++)
	    copyrtv(vr, mindc, minsr, minsc, maxsr, maxsc);
    } else if (minsc == maxsc) {
	/* Source is a single column */
	for (vc = mindc; vc <= maxdc; vc++)
	    copyrtv(mindr, vc, minsr, minsc, maxsr, maxsc);
    } else {
	/* Everything else */
	copyrtv(mindr, mindc, minsr, minsc, maxsr, maxsc);
    }
    sync_refs();
}

static void
copyrtv(int vr, int vc, int minsr, int minsc, int maxsr, int maxsc)
{
    register struct ent *p;
    register struct ent *n;
    register int sr, sc;
    register int dr, dc;

    for (dr=vr, sr=minsr; sr<=maxsr; sr++, dr++) {
	for (dc=vc, sc=minsc; sc<=maxsc; sc++, dc++) {
	    if ((p = *ATBL(tbl, sr, sc))) {
		n = lookat (dr, dc);
		if (n->flags & is_locked) continue;
		clearent(n);
		copyent( n, p, dr - sr, dc - sc);
	    }
	    else
		if ((n = *ATBL(tbl, dr, dc)))
		    clearent(n);
	}
    }
}

/* ERASE a Range of cells */
void
eraser(struct ent *v1, struct ent *v2)
{
    FullUpdate++;
    flush_saved();
    erase_area(v1->row, v1->col, v2->row, v2->col);
    sync_refs();
}

/* Goto subroutines */

static void             /* static added by Bob Parbs 12-92 */
g_free(void)
{
    switch (gs.g_type) {
    case G_STR: scxfree(gs.g_s); break;
    default: break;
    }
    gs.g_type = G_NONE;
    gs.errsearch = 0;
}

/* repeat the last goto command */
void
go_last(void)
{
    switch (gs.g_type) {
    case G_NONE:
	error("Nothing to repeat"); break;
    case G_NUM:
	num_search(gs.g_n, gs.errsearch);
	break;
    case  G_CELL:
	moveto(gs.g_row, gs.g_col);
	break;
    case  G_STR: 
	gs.g_type = G_NONE;	/* Don't free the string */
	str_search(gs.g_s); 
	break;
    default: error("go_last: internal error");
    }
}

/* place the cursor on a given cell */
void
moveto(int row, int col)
{
    currow = row;
    curcol = col;
    g_free();
    gs.g_type = G_CELL;
    gs.g_row = currow;
    gs.g_col = curcol;
}

/*
 * 'goto' either a given number,'error', or 'invalid' starting at currow,curcol
 */
void
num_search(double n, int errsearch)
{
    register struct ent *p;
    register int r,c;
    int	endr, endc;

    g_free();
    gs.g_type = G_NUM;
    gs.g_n = n;
    gs.errsearch = errsearch;

    if (currow > maxrow)
	endr = maxrow ? maxrow-1 : 0;
    else
	endr = currow;
    if (curcol > maxcol)
	endc = maxcol ? maxcol-1 : 0;
    else
	endc = curcol;
    r = endr;
    c = endc;
    do {
	if (c < maxcol)
	    c++;
	else {
	    if (r < maxrow) {
		while(++r < maxrow && row_hidden[r]) /* */;
		c = 0;
	    } else {
		r = 0;
		c = 0;
	    }
	}
	if (r == endr && c == endc) {
	    if (errsearch) {
		sprintf(stringbuf, "no %s cell found",
			errsearch == CELLERROR ? "ERROR" : "INVALID");
		error(stringbuf);
	    } 
	    else
		error("Number not found");
	    return;
	}
	p = *ATBL(tbl, r, c);
    } while (col_hidden[c] || !p || !(p->flags & is_valid)
	     || (!errsearch && (p->v != n))
	     || (errsearch && !((p->cellerror == errsearch) ||
				(p->cellerror == errsearch))));	
    /* CELLERROR vs CELLINVALID */
		
    currow = r;
    curcol = c;
}

#if defined(REG_COMP) /* Peter Doemel, 10-Feb-1993 */
char *
regerrmsg(errcode)
     int errcode;
{
    switch(errcode) {
    case REG_NOMATCH:
	return "regexec() failed to match.";
    case REG_ECOLLATE:
	return "Invalid collation element referenced.";
    case REG_EESCAPE:
	return "Trailing \\ in pattern.";
    case REG_ENEWLINE:
	return "<newline> found before end of pattern and REG_NEWLINE flag not set.";
    case REG_ESUBREG:
	return "Number in \\digit invalid or in error.";
    case REG_EBRACK:
	return "[ ] imbalance.";
    case REG_EPAREN:
	return "\\( \\) imbalance in basic regular expression or ( ) imbalance in extended regular expression.";
    case REG_EBRACE:
	return "\\{ \\} imbalance.";
    case REG_ERANGE:
	return "Invalid endpoint in range statement.";
    case REG_ESPACE:
	return "Out of memory for compiled pattern.";
    case REG_EMEM:
	return "Out of memory while matching expression.";
    case REG_ECTYPE:
	return "Invalid character class type named.";
    case REG_ENSUB:
	return "Too many parenthesis pairs or nesting level too deep.";
    case REG_EABRACE:
	return "Number too large in \\{ \\} construct.";
    case REG_EBBRACE:
	return "Invalid number in \\{ \\} construct.";
    case REG_ECBRACE:
	return "More than two numbers in \\{ \\} construct.";
    case REG_EDBRACE:
	return "First number exceeds second in \\{ \\} construct.";
    case REG_ENOSEARCH:
	return "No remembered search string.";
    case REG_EDUPOPER:
	return "Duplication operator in illegal position.";
    case REG_ENOEXPR:
	return "No expression within ( ) or on one side of an |.";
    default:
	return "regerrmsg: INVALID ERRORCODE";
    }
}
#endif

/* 'goto' a cell containing a matching string */

void
str_search(char *s)
{
    register struct ent *p;
    register int r,c;
    int	endr, endc;
#if defined(RE_COMP) || defined(REGCMP)
    char *tmp;
#endif

#if defined(REG_COMP) /* Peter Doemel, 10-Feb-1993 */
    int status;
    regex_t preg;

    if ((status = regcomp(&preg, s, 0)) != 0) {
	scxfree(s);
	cellerror = CELLERROR;
	error(regerrmsg(status));
	return;
    }
#endif

#if defined(RE_COMP)
    if ((tmp = re_comp(s)) != NULL) {
	scxfree(s);
	error(tmp);
	return;
    }
#endif
#if defined(REGCMP)
    if ((tmp = regcmp(s, NULL)) == NULL) {
	scxfree(s);
	cellerror = CELLERROR;
	error("Invalid search string");
	return;
    }
#endif
    g_free();
    gs.g_type = G_STR;
    gs.g_s = s;
    if (currow > maxrow)
	endr = maxrow ? maxrow-1 : 0;
    else
	endr = currow;
    if (curcol > maxcol)
	endc = maxcol ? maxcol-1 : 0;
    else
	endc = curcol;
    r = endr;
    c = endc;
    do {
	if (c < maxcol)
	    c++;
	else {
	    if (r < maxrow) {
		while(++r < maxrow && row_hidden[r]) /* */;
		c = 0;
	    } else {
		r = 0;
		c = 0;
	    }
	}
	if (r == endr && c == endc) {
	    error("String not found");
#if defined(REG_COMP) /* Peter Doemel, 10-Feb-1993 */
	    regfree(&preg);
#elif defined(REGCMP)
	    free(tmp);
#endif
	    return;
	}
	p = *ATBL(tbl, r, c);
    } while(col_hidden[c] || !p || !(p->label)

#if defined(REG_COMP) /* Peter Doemel, 10-Feb-1993 */
	    || (regexec(&preg, p->label, (size_t)0, NULL, 0) != 0));
#elif defined(RE_COMP)
    || (re_exec(p->label) == 0));
#elif defined(REGCMP)
	    || (regex(tmp, p->label) == NULL));
#else
			|| (strcmp(s, p->label) != 0));
#endif
    currow = r;
    curcol = c;
#if defined(REG_COMP) /* Peter Doemel, 10-Feb-1993 */
    regfree(&preg);
#elif defined(REGCMP)
    free(tmp);
#endif
}

/* fill a range with constants */
void
fill(struct ent *v1, struct ent *v2, double start, double inc)
{
    register int r, c;
    register struct ent *n;
    int maxr, maxc;
    int minr, minc;

    maxr = v2->row;
    maxc = v2->col;
    minr = v1->row;
    minc = v1->col;
    if (minr>maxr) r = maxr, maxr = minr, minr = r;
    if (minc>maxc) c = maxc, maxc = minc, minc = c;
    checkbounds(&maxr, &maxc);
    if (minr < 0) minr = 0;
    if (minc < 0) minc = 0;

    FullUpdate++;
    if (calc_order == BYROWS) {
    for (r = minr; r<=maxr; r++)
	for (c = minc; c<=maxc; c++) {
	    n = lookat (r, c);
	    if (n->flags & is_locked) continue;
	    clearent(n);
	    n->v = start;
	    start += inc;
	    n->flags |= (is_changed|is_valid);
	}
    }
    else if (calc_order == BYCOLS) {
    for (c = minc; c<=maxc; c++)
	for (r = minr; r<=maxr; r++) {
	    n = lookat (r, c);
	    clearent(n);
	    n->v = start;
	    start += inc;
	    n->flags |= (is_changed|is_valid);
	}
    }
    else error("Internal error calc_order");
    changed++;
}

/* lock a range of cells */

void
lock_cells(struct ent *v1, struct ent *v2)
{
    register int r, c;
    register struct ent *n;
    int maxr, maxc;
    int minr, minc;

    maxr = v2->row;
    maxc = v2->col;
    minr = v1->row;
    minc = v1->col;
    if (minr>maxr) r = maxr, maxr = minr, minr = r;
    if (minc>maxc) c = maxc, maxc = minc, minc = c;
    checkbounds(&maxr, &maxc);
    if (minr < 0) minr = 0;
    if (minc < 0) minc = 0;

    for (r = minr; r<=maxr; r++) {
	for (c = minc; c<=maxc; c++) {
	    n = lookat (r, c);
	    n->flags |= is_locked;
	}
    }
}

/* unlock a range of cells */

void
unlock_cells(struct ent *v1, struct ent *v2)
{
    register int r, c;
    register struct ent *n;
    int maxr, maxc;
    int minr, minc;

    maxr = v2->row;
    maxc = v2->col;
    minr = v1->row;
    minc = v1->col;
    if (minr>maxr) r = maxr, maxr = minr, minr = r;
    if (minc>maxc) c = maxc, maxc = minc, minc = c;
    checkbounds(&maxr, &maxc);
    if (minr < 0) minr = 0;
    if (minc < 0) minc = 0;

    for (r = minr; r<=maxr; r++) {
	for (c = minc; c<=maxc; c++) {
	    n = lookat (r, c);
	    n->flags &= ~is_locked;
	}
    }
}

/* set the numeric part of a cell */
void
let(struct ent *v, struct enode *e)
{
    double val;
    unsigned isconstant = constant(e);

    if (loading && !isconstant)
	val = 0.0;
    else {
	exprerr = 0;
	signal(SIGFPE, eval_fpe);
	if (setjmp(fpe_save)) {
	    sprintf(stringbuf, "Floating point exception in cell %s", 
		    v_name(v->row, v->col));
	    error(stringbuf);
	    val = 0.0;
	    cellerror = CELLERROR;
	} else {
	    cellerror = CELLOK;
	    val = eval(e);
	}
	if (v->cellerror != cellerror) {
		v->flags |= is_changed;
		changed++; 
		modflg++;
		FullUpdate++;
		v->cellerror = cellerror;
	}
	signal(SIGFPE, doquit);
	if (exprerr) {
	    efree(e);
	    return;
	}
    }

    if (isconstant) {
	/* prescale input unless it has a decimal */
	if (!loading && (prescale < 0.9999999) &&
	    ((val - floor(val)) == 0.0))
	    val *= prescale;

	v->v = val;

	if (!(v->flags & is_strexpr)) {
            efree(v->expr);
	    v->expr = NULL;
	}
	efree(e);
    }
    else {
	efree(v->expr);
	v->expr = e;
	v->flags &= ~is_strexpr;
    }

    changed++; modflg++;
    v->flags |= (is_changed | is_valid);
}

void
slet(struct ent *v, struct enode *se, int flushdir)
{
    char *p;

    exprerr = 0;
    signal(SIGFPE, eval_fpe);
    if (setjmp(fpe_save)) {
	sprintf(stringbuf, "Floating point exception in cell %s", 
		v_name(v->row, v->col));
	error(stringbuf);
	cellerror = CELLERROR;
	p = "";
    } else {
	cellerror = CELLOK;
	p = seval(se);
    }
    if (v->cellerror != cellerror) {
    	v->flags |= is_changed;
	changed++;	modflg++;
	FullUpdate++;
	v->cellerror = cellerror;
    }
    signal(SIGFPE, doquit);
    if (exprerr) {
	efree(se);
	return;
    }
    if (constant(se)) {
	label(v, p, flushdir);
	if (p)
	    scxfree(p);
	efree(se);
	if (v->flags & is_strexpr) {
            efree(v->expr);
	    v->expr = NULL;
	    v->flags &= ~is_strexpr;
	}
	return;
    }
    efree(v->expr);
    v->expr = se;
    v->flags |= (is_changed | is_strexpr);
    if (flushdir < 0) 
	v->flags |= is_leftflush;
    if (flushdir == 0)
	v->flags |= is_label;
    else v->flags &= ~is_label;

    FullUpdate++;
    changed++;
    modflg++;
}

void
format_cell(struct ent *v1, struct ent *v2, char *s)
{
    register int r, c;
    register struct ent *n;
    int maxr, maxc;
    int minr, minc;

    maxr = v2->row;
    maxc = v2->col;
    minr = v1->row;
    minc = v1->col;
    if (minr>maxr) r = maxr, maxr = minr, minr = r;
    if (minc>maxc) c = maxc, maxc = minc, minc = c;
    checkbounds(&maxr, &maxc);
    if (minr < 0) minr = 0;
    if (minc < 0) minc = 0;

    FullUpdate++;
	modflg++;
    for (r = minr; r <= maxr; r++)
	for (c = minc; c <= maxc; c++) {
	    n = lookat(r, c);
	    if (n->flags & is_locked) {
		sprintf(stringbuf, "Cell %s%d is locked", 
			coltoa(n->col), n->row);
		error(stringbuf);
		continue;
	    }
	    if (n->format)
		scxfree(n->format);
	    n->format = 0;
	    if (s && *s != '\0')
		n->format = strcpy(scxmalloc(strlen(s) + 1), s);
	    n->flags |= is_changed;
       }
}

void
hide_row(int arg)
{
    if (arg < 0) {
	error("Invalid Range");
	return;
    }
    if (arg >= maxrows-1) {
	if (!growtbl(GROWROW, arg+1, 0)) {
		error("You can't hide the last row");
		return;
	}
    }
    FullUpdate++;
    row_hidden[arg] = 1;
}

void
hide_col(int arg)
{
    if (arg < 0) {
	error("Invalid Range");
	return;
    }
    if (arg >= maxcols-1) {
    	if ((arg >= ABSMAXCOLS-1) || !growtbl(GROWCOL, 0, arg+1)) {
		error("You can't hide the last col");
		return;
	}
    }
    FullUpdate++;
    col_hidden[arg] = TRUE;
}

void
clearent(struct ent *v)
{
    if (!v)
	return;
    label(v, "", -1);
    v->v = 0.0;
    if (v->expr)
	efree(v->expr);
    v->expr = NULL;
    if (v->format)
	scxfree(v->format);
    v->format = NULL;
    v->flags |= (is_changed);
    v->flags &= ~(is_valid);
    changed++;
    modflg++;
}

/*
 * Say if an expression is a constant (return 1) or not.
 */
static int                   /* static added by Bob Parbs 12-92 */
constant (register struct enode *e)
{
    return (
	 e == NULL
	 || e -> op == O_CONST
	 || e -> op == O_SCONST
	 || (
	     e -> op != O_VAR
	     && (e -> op & REDUCE) != REDUCE
	     && constant(e -> e.o.left)
	     && constant(e -> e.o.right)
	     && e -> op != EXT	 /* functions look like constants but aren't */
	     && e -> op != NVAL
	     && e -> op != SVAL
	     && e -> op != NOW
	     && e -> op != MYROW
	     && e -> op != MYCOL
	     && e -> op != NUMITER
	     && e -> op != RAND
	     && e -> op != NORM
	     && e -> op != NORMCDF
	     )
    );
}

void
efree (struct enode *e)
{
    if (e) {
	if (e->op != O_VAR && e->op !=O_CONST && e->op != O_SCONST
		&& (e->op & REDUCE) != REDUCE) {
	    efree(e->e.o.left);
	    efree(e->e.o.right);
	}
	/* case of conditional range */
	if ((e->op & REDUCE) && e->e.r.expr) {
	    efree(e->e.r.expr);
	}
	if (e->op == O_SCONST && e->e.s)
	    scxfree(e->e.s);
	e->e.o.left = freeenodes;
	freeenodes = e;
    } 
}

void
label (register struct ent *v, register char *s, int flushdir)
{
    if (v == NULL) return;
    if (flushdir == 0 && v->flags & is_valid) {
	register struct ent *tv;

	if (v->col>0 && 
	    ((tv=lookat(v->row,v->col-1))->flags & is_valid) == 0)
	    v = tv, flushdir = 1;
	else if (((tv=lookat (v->row,v->col+1))->flags & is_valid) == 0)
	    v = tv, flushdir = -1;
	else flushdir = -1;
    }
    if (v->label) scxfree(v->label);
    if (s && s[0]) {
	v->label = scxmalloc(strlen(s) + 1);
	strcpy(v->label, s);
    } else
	v->label = NULL;
    if (flushdir < 0) v->flags |= is_leftflush;
    else v->flags &= ~is_leftflush;
    if (flushdir == 0) v->flags |= is_label;
    else v->flags &= ~is_label;
    FullUpdate++;
    modflg++;
}

static void
decodev(struct ent_ptr v)
{
    register struct range *r;

    if (!v.vp) sprintf(line + linelim, "VAR?");
    else if ((r = find_range(NULL, 0, v.vp, v.vp)) && !r->r_is_range)
	sprintf(line+linelim, "%s", r->r_name);
    else
	sprintf (line+linelim, "%s%s%s%d",
			v.vf & FIX_COL ? "$" : "",
			coltoa(v.vp->col),
			v.vf & FIX_ROW ? "$" : "",
			v.vp->row);
    linelim += strlen(line + linelim);
}

char *
coltoa(int col)
{
    static char rname[3];
    register char *p = rname;

    if (col > 25) {
	*p++ = col/26 + 'A' - 1;
	col %= 26;
    }
    *p++ = col + 'A';
    *p = '\0';
    return rname;
}

/*
 *	To make list elements come out in the same order
 *	they were entered, we must do a depth-first eval
 *	of the ELIST tree
 */
static void
decompile_list(struct enode *p)
{
    if (!p) return;
    decompile_list(p->e.o.left);	/* depth first */
    decompile(p->e.o.right, 0);
    line[linelim++] = ',';
}

static void               /* static added by Bob Parbs 12-92 */
decompile(register struct enode *e, int priority)
{
    register char *s;

    if (e) {
	int mypriority;
	switch (e->op) {
	default: mypriority = 99; break;
	case '?': mypriority = 1; break;
	case ':': mypriority = 2; break;
	case '|': mypriority = 3; break;
	case '&': mypriority = 4; break;
	case '<': case '=': case '>': mypriority = 6; break;
	case '+': case '-': case '#': mypriority = 8; break;
	case '*': case '/': case '%': mypriority = 10; break;
	case '^': mypriority = 12; break;
	}
	if (mypriority < priority) line[linelim++] = '(';
	switch (e->op) {
	case 'x':       decompile (e->e.o.right, 30);
	                break;
	case 'f':	for (s="fixed "; (line[linelim++] = *s++););
			linelim--;
			decompile (e->e.o.right, 30);
			break;
	case 'm':	line[linelim++] = '-';
			decompile (e->e.o.right, 30);
			break;
	case '~':	line[linelim++] = '~';
			decompile (e->e.o.right, 30);
			break;
	case O_VAR:	decodev (e->e.v);
			break;
#ifdef VR3
	case O_CONST:	sprintf(line + linelim, "%.8g", e->e.k);
#else
	case O_CONST:	sprintf(line + linelim, "%.15g", e->e.k);
#endif
			linelim += strlen(line + linelim);
			break;
	case O_SCONST:	sprintf(line + linelim, "\"%s\"", e->e.s);
			linelim += strlen(line + linelim);
			break;

	case RAND: sprintf(line + linelim, "@rand"); 
	                linelim += strlen(line + linelim); break;
	case NORM: sprintf(line + linelim, "@norm"); 
	                linelim += strlen(line + linelim); break;

	case REDUCE | '+': range_arg( "@sum(", e); break;
	case REDUCE | '*': range_arg( "@prod(", e); break;
	case REDUCE | 'a': range_arg( "@avg(", e); break;
	case REDUCE | 'c': range_arg( "@count(", e); break;
	case REDUCE | 'e': range_arg( "@entropy(", e); break;
	case REDUCE | 's': range_arg( "@stddev(", e); break;
	case (REDUCE | IRR): range_arg( "@irr(", e); break;
	case (REDUCE | MAXR): range_arg( "@max(", e); break;
	case (REDUCE | MINR): range_arg( "@min(", e); break;

	case ABS:		one_arg( "@abs(", e); break;
	case ACOS:	one_arg( "@acos(", e); break;
	case ASIN:	one_arg( "@asin(", e); break;
	case ATAN:	one_arg( "@atan(", e); break;
	case ATAN2:	two_arg( "@atan2(", e); break;
	case CEIL:	one_arg( "@ceil(", e); break;
	case COS:	one_arg( "@cos(", e); break;
	case EXP:	one_arg( "@exp(", e); break;
	case FABS:	one_arg( "@fabs(", e); break;
	case FLOOR:	one_arg( "@floor(", e); break;
	case HYPOT:	two_arg( "@hypot(", e); break;
	case LOG:	one_arg( "@ln(", e); break;
	case LOG10:	one_arg( "@log(", e); break;
	case LOG2:	one_arg( "@log2(", e); break;
	case POW:	two_arg( "@pow(", e); break;
	case SIN:	one_arg( "@sin(", e); break;
	case SQRT:	one_arg( "@sqrt(", e); break;
	case TAN:	one_arg( "@tan(", e); break;
	case DTR:	one_arg( "@dtr(", e); break;
	case RTD:	one_arg( "@rtd(", e); break;
	case RND:	one_arg( "@rnd(", e); break;
	case ROUND:	two_arg( "@round(", e); break;
	case HOUR:	one_arg( "@hour(", e); break;
	case MINUTE:	one_arg( "@minute(", e); break;
	case SECOND:	one_arg( "@second(", e); break;
	case MONTH:	one_arg( "@month(", e); break;
	case DAY:	one_arg( "@day(", e); break;
	case YEAR:	one_arg( "@year(", e); break;
	case DATE:	one_arg( "@date(", e); break;
	case UPPER:	one_arg( "@upper(", e); break;
	case LOWER:	one_arg( "@lower(", e); break;
	case CAPITAL:	one_arg( "@capital(", e); break;
	case DTS:	three_arg( "@dts(", e); break;
	case TTS:	three_arg( "@tts(", e); break;
	case STON:	one_arg( "@ston(", e); break;
	case NORMCDF:	one_arg( "@normcdf(", e); break;
	case FMT:	two_arg( "@fmt(", e); break;
	case EQS:	two_arg( "@eqs(", e); break;
	case NOW:	for (s = "@now"; (line[linelim++] = *s++););
			linelim--;
			break;
	case LMAX:	list_arg("@max(", e); break;
	case LMIN: 	list_arg("@min(", e); break;
	case FV:	three_arg("@fv(", e); break;
	case PV:	three_arg("@pv(", e); break;
	case PMT:	three_arg("@pmt(", e); break;
	case NVAL:	two_arg("@nval(", e); break;
	case SVAL:	two_arg("@sval(", e); break;
	case EXT:	two_arg("@ext(", e); break;
	case SUBSTR:	three_arg("@substr(", e); break;
	case STINDEX:	index_arg("@stindex(", e); break;
	case INDEX:	index_arg("@index(", e); break;
	case LOOKUP:	index_arg("@lookup(", e); break;
	case HLOOKUP:	two_arg_index("@hlookup(", e); break;
	case VLOOKUP:	two_arg_index("@vlookup(", e); break;
	case IF:	three_arg("@if(", e); break;
	case MYROW:	for (s = "@myrow"; (line[linelim++] = *s++););
			linelim--;
			break;
	case MYCOL:	for (s = "@mycol"; (line[linelim++] = *s++););
			linelim--;
			break;
	case COLTOA:	one_arg( "@coltoa(", e); break;
	case NUMITER:	for (s = "@numiter"; (line[linelim++] = *s++););
                        linelim--;
                        break;
/* FIXME-test this code (also what is the matrix priority (in gram.y) */
	case MATRIX_ADD:	three_arg("@matrix_add(", e); break;
	case MATRIX_SUB:	three_arg("@matrix_sub(", e); break;
	case MATRIX_INV:	two_arg("@matrix_inv(", e); break;
	case MATRIX_MULT:	three_arg("@matrix_mult(", e); break;
	case MATRIX_TRANS:	two_arg("@matrix_trans(", e); break;
	default:	decompile(e->e.o.left, mypriority);
			line[linelim++] = e->op;
			decompile(e->e.o.right, mypriority+1);
			break;
	}
	if (mypriority < priority) line[linelim++] = ')';
    } else line[linelim++] = '?';
}

static void
index_arg(char *s, struct enode *e)
{
    for ( ; (line[linelim++] = *s++); );
    linelim--;
    decompile(e->e.o.left, 0);
    range_arg(", ", e->e.o.right);
}

static void
two_arg_index(char *s, struct enode *e)
{
    for (; (line[linelim++] = *s++););
    linelim--;
    decompile(e->e.o.left->e.o.left, 0);
    range_arg(",", e->e.o.right);
    linelim--;
    line[linelim++] = ',';
    decompile(e->e.o.left->e.o.right, 0);
    line[linelim++] = ')';
}

static void
list_arg(char *s, struct enode *e)
{
    for (; (line[linelim++] = *s++););
    linelim--;

    decompile(e->e.o.right, 0);
    line[linelim++] = ',';
    decompile_list(e->e.o.left);
    line[linelim - 1] = ')';
}

static void
one_arg(char *s, struct enode *e)
{
    for (; (line[linelim++] = *s++); );
    linelim--;
    decompile(e->e.o.right, 0);
    line[linelim++] = ')';
}

static void
two_arg(char *s, struct enode *e)
{
    for (; (line[linelim++] = *s++); );
    linelim--;
    decompile(e->e.o.left, 0);
    line[linelim++] = ',';
    decompile(e->e.o.right, 0);
    line[linelim++] = ')';
}

static void
three_arg(char *s,struct enode *e)
{
    for (; (line[linelim++] = *s++););
    linelim--;
    decompile(e->e.o.left, 0);
    line[linelim++] = ',';
    decompile(e->e.o.right->e.o.left, 0);
    line[linelim++] = ',';
    decompile(e->e.o.right->e.o.right, 0);
    line[linelim++] = ')';
}

static void
range_arg(char *s, struct enode *e)
{
    struct range *r;

    for (; (line[linelim++] = *s++););
    linelim--;
    if ((r = find_range(NULL, 0, e->e.r.left.vp,
			e->e.r.right.vp)) && r->r_is_range) {
	sprintf(line + linelim, "%s", r->r_name);
	linelim += strlen(line + linelim);
    } else {
	decodev(e->e.r.left);
	line[linelim++] = ':';
	decodev(e->e.r.right);
	if(e->e.r.expr) {
            line[linelim++] = '#';
            decompile(e->e.r.expr, 0);
        }
    }
    line[linelim++] = ')';
}

void
editfmt(int row, int col)
{
    register struct ent *p;

    p = lookat(row, col);
    if (p->format) {
        sprintf (line, "fmt %s \"%s\"", v_name(row, col), p->format);
	linelim = strlen(line);
    }
}

void
editv(int row, int col)
{
    register struct ent *p;

    p = lookat(row, col);
    sprintf(line, "let %s = ", v_name(row, col));
    linelim = strlen(line);
    if (p->flags & is_strexpr || p->expr == 0) {
#ifdef VR3 /* tiny screen */
	sprintf(line + linelim, "%.8g", p->v);
#else
	sprintf(line + linelim, "%.15g", p->v);
#endif
	linelim += strlen(line + linelim);
    } else {
        editexp(row, col);
    }
}

void
editexp(int row, int col)
{
    register struct ent *p;

    p = lookat(row, col);
    decompile(p->expr, 0);
    line[linelim] = '\0';
}

void
edits(int row, int col)
{
    register struct ent *p;

    p = lookat(row, col);
    if (p->flags & is_label) {
	sprintf(line, "label %s = ", v_name(row, col));
    } else {
	sprintf(line, "%sstring %s = ",
		       ((p->flags & is_leftflush) ? "left" : "right"),
		       v_name(row, col));
    }
    linelim = strlen(line);
    if (p->flags & is_strexpr && p->expr) {
	editexp(row, col);
    } else if (p->label) {
        sprintf(line + linelim, "\"%s\"", p->label);
        linelim += strlen(line + linelim);
    } else {
        sprintf(line + linelim, "\"");
        linelim += 1;
    }
}

/*
 * DOIRR -- calculates the "internal-rate-of-return" for a cash flow
 * over equal length intervals, designated in the range.  I.e.  
 * the rate-of-return which would yield a cash flow with these properties,
 * common in bond-returns.  E.g. -103.4 9.13 9.13 109.13  might be
 * the cell contents for a bond which costs 103.4, returns 9 1/8% on
 * par value 100, and then returns the principal and last payment 
 * all at once.
 *
 * Formula:
 *	based on solving for "r" in:
 *		  t
 *		Sum	CF(j) / (1+r)^j
 * 		  j = 0
 */
static double
doirr(int minr, int minc, int maxr, int maxc)
{
    static double ret = 0;
    
    /* first check validity of all entries,
     * as well as validity of the range
     */
    if (minr != maxr && minc != maxc) {
	/* range is wrong shape, the formula needs changing */
	error(" range specified to @doirr");
	cellerror = CELLERROR;
	return ret;
    }
    /* must be at least 2 numbers in the cash flow. */
    if (!valid_nrange(minr, minc, maxr, maxc, 2)) {
	/* formula may be fine, range values may be changed */
	cellerror = CELLINVALID;
	return ret;
    }

    /* now run the irr approximation */
    return dorlirr(minr, minc, maxr, maxc);
}


/* calculate @irr() over range, approximating the rate, using exponential
 * doubling to find an upper bound for a guess, then narrowing in using
 * binary search.
 */
static double
dorlirr(int minr, int minc, int maxr, int maxc)
{
    double guess = 1.0;
    double err = 0.0001;
    double rate = guess;
    double *rate_pow;
    int	growing = 1;		/* finding upper bound for rate */
    int	npow;
    double oval = -123456.0;	/* arbitrary number */
    double val;

    /* rate power table */
    npow = (maxr-minr+1) * (maxc-minc+1) + 1;
    rate_pow = scxmalloc(sizeof *rate_pow * npow);
    /* repeatedly guess */
    for (;;) {
	populate_power(rate, rate_pow, npow);
	val = cash_flow(rate, rate_pow, minr, minc, maxr, maxc);
	if (fabs(val) <= err)
	    break;
	if (fabs(val - oval) <= err || fabs(rate) <= err) {
	    /* not converging, no rate */
	    cellerror = CELLERROR;
	    break;
	}
	oval = val;
	/* adjust guess */
	if (val > 0.0 && growing) {
	    /* still trying to find an upper bound */
	    rate += guess;
	    guess *= 2;
	}
	else {
	    /* bin search */
	    guess *= 0.5;
	    if (val > 0.0) { /* grow rate */
		rate += guess;
	    }
	    else { /* diminish rate */
		growing = 0;
		rate -= guess;
	    }
	}
    }

    scxfree(rate_pow);
    return rate;
}

/*
 * valid numeric range?
 * emptyok:  -1 -- all range must be numeric
 *            # -- skip non-numeric or missing, must be at least #
 *		  numerics present
 * any cellerror values will cause invalid range.
 */
static int
valid_nrange(int minr, int minc, int maxr, int maxc, int emptyok)
{
    register struct ent	*p;
    int	cinc, rinc;
    int	numerics = 0;

    set_step(minr, minc, maxr, maxc, &rinc, &cinc);
    for (; minr <= maxr && minc <= maxc; minr += rinc, minc += cinc) {
	p = *ATBL(tbl, minr, minc);
	if (p) {
	    /* error */
	    if (p->cellerror)
		return 0;
	    /* valid number? */
	    if (p->flags & is_valid)
		numerics++;
	    /* !ok to be empty */
	    else if (emptyok == -1)
		return 0;
	}
	else if (emptyok == -1)
	    return 0;
    }
    return numerics >= emptyok;
}

/* for one-dim matrices, sets steps to traverse. */
static void
set_step(int minr, int minc, int maxr, int maxc, int *rincp, int *cincp)
{
    *cincp = *rincp = 0;
    /* establish steps */
    if (minr == maxr)
	*cincp = 1;
    else
	*rincp = 1;
}

static void
populate_power(double rate, double *rate_pow, int npow)
{
    double c = 1.0;

    while (--npow >= 0) {
	*rate_pow++ = c;
	c *= rate;
    }
}


static double 
cash_flow(double rate, double *rate_pow, 
	  int minr, int minc, int maxr, int maxc)
{
    int rinc, cinc;
    struct ent *p;
    double ret = 0.0;

    set_step(minr, minc, maxr, maxc, &rinc, &cinc);
    for (; minr <= maxr && minc <= maxc; minr += rinc, minc += cinc)
	/* skip empties and labels. */
	if ((p = *ATBL(tbl, minr, minc)) && (p->flags & is_valid))
	    ret += (*ATBL(tbl, minr, minc))->v / *rate_pow++;
    return ret;
}
