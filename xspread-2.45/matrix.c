/* matrix.c for xspread: Matrix calculation routines
   Original coding by Fang Wang, 1991.
   Modified by Allin Cottrell, May 2001
*/

#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>
#include <math.h>
#include "config.h"

#include "sc.h"

void get_add_sub(int opt);
void get_mult(void);
void get_trans_invert(int opt);

struct m_range *findrge(char *);
static int convert(int, char[], int);

static void add_sub_matrix (int, int, int, int, int, 
			    int, int, int, int, int, int);
static void multmatrix (int, int, int, int, int, int, int, int, int, int); 
static void transpose (int, int, int, int, int, int);
static void invertmatrix (int, int, int, int, int, int); 
static int regress(int xcol, int xsr, int xer,
		   int ycol, int ysr, int yer,
		   int dcol, int drow);

/* -------------------- utility routines ------------------------- */

static void
set_dest (struct m_range *rge_d,
	  int *mindr,  /* min row, dest */
	  int *mindc,  /* min col, dest */
	  int *maxdr,  /* max row, dest */
	  int *maxdc,  /* max col, dest */
	  int *mins1r, /* min row, source 1 */
	  int *maxs1r, /* max row, source 1 */
	  int *mins1c, /* min col, source 1 */
	  int *maxs1c, /* max col, source 1 */
	  int *mins2c, /* min col, source 2 */
	  int *maxs2c, /* max col, source 2 */
	  int opt)
{
    struct ent *dmin;

    dmin = lookat(rge_d->sr, rge_d->sc);
    *mindr = dmin->row;
    *mindc = dmin->col;
    if (opt == MATRIX_MULT) 
	*maxdc = *mindc + *maxs2c - *mins2c;
    else 
	*maxdc = *mindc + *maxs1c - *mins1c;
    *maxdr = *mindr + *maxs1r - *mins1r;
}

static int
check_source_ranges (struct m_range *rge_s1, /* first source */
		     struct m_range *rge_s2, /* second source */
		     int *mins1r, /* min row, source 1 */
		     int *maxs1r, /* max row, source 1 */
		     int *mins1c, /* min col, source 1 */
		     int *maxs1c, /* max col, source 1 */
		     int *mins2r, /* min row, source 2 */
		     int *maxs2r, /* max row, source 2 */
		     int *mins2c, /* min col, source 2 */
		     int *maxs2c, /* max col, source 2 */
		     int opt      /* operation */
		     )
{
    struct ent *s1min, *s1max;
    struct ent *s2min, *s2max;
    int r, c, err = 0;

    s1min = lookat(rge_s1->sr, rge_s1->sc);
    s1max = lookat(rge_s1->er, rge_s1->ec);
    *maxs1r = s1max->row;
    *maxs1c = s1max->col;
    *mins1r = s1min->row;
    *mins1c = s1min->col;
    if (*mins1r > *maxs1r) 
	r = *maxs1r, *maxs1r = *mins1r, *mins1r = r;
    if (*mins1c > *maxs1c) 
	c = *maxs1c, *maxs1c = *mins1c, *mins1c = c;

    if (opt == MATRIX_INV) { /* source must be square */
	if (*maxs1c - *mins1c != *maxs1r - *mins1r) {
	    error("Matrix not square: can't invert");
	    return 1;
	}
    }

    if (opt == MATRIX_INV || opt == MATRIX_TRANS)
	return 0;

    s2min = lookat(rge_s2->sr, rge_s2->sc);
    s2max = lookat(rge_s2->er, rge_s2->ec);
    *maxs2r = s2max->row;
    *maxs2c = s2max->col;
    *mins2r = s2min->row;
    *mins2c = s2min->col;
    if (*mins2r > *maxs2r) 
	r = *maxs2r, *maxs2r = *mins2r, *mins2r = r;
    if (*mins2c > *maxs2c) 
	c = *maxs2c, *maxs2c = *mins2c, *mins2c = c;

    if (opt == MATRIX_MULT) {  /* multiplication */
	if (*maxs1c - *mins1c != *maxs2r - *mins2r) 
	    err = 1;
    } else { /* addition or subtraction */
	if ((*maxs1r - *mins1r != *maxs2r - *mins2r) ||
	    (*maxs2c - *mins2c != *maxs1c - *mins1c)) 
	    err = 1;
    }

    if (err) 
	error("Matrices not conformable");
    return err;
}

static int 
get_matrix_ranges (int *mins1r, /* min row, source 1 */
		   int *maxs1r, /* max row, source 1 */
		   int *mins1c, /* min col, source 1 */
		   int *maxs1c, /* max col, source 1 */
		   int *mins2r, /* min row, source 2 */
		   int *maxs2r, /* max row, source 2 */
		   int *mins2c, /* min col, source 2 */
		   int *maxs2c, /* max col, source 2 */
		   int *mindr,  /* min row, dest */
		   int *mindc,  /* min col, dest */
		   int *maxdr,  /* max row, dest */
		   int *maxdc,  /* max col, dest */
		   int opt      /* operation */
		   )
{
    static char *get_src_1[] = {
	"first matrix range: ",
	"matrix 1 range: ",
	"source matrix range: ",
	"left matrix range: ",
	"source matrix range: "
    };
    static char *get_src_2[] = {
	"second matrix range: ",
	"matrix 2 range: ",
	NULL,
	"right matrix range: "
    };
    char s[100];
    struct m_range *rge_s1 = NULL, *rge_s2 = NULL, *rge_d = NULL;

    strcpy(s, get_src_1[opt-MATRIX_ADD]);
    get_str(s, TSSIZE, NULL);
    if (*s == '\0' || (rge_s1 = findrge(s)) == NULL) {
	if (*s) error("Input syntax error");
	return 1;
    }

    if (opt != MATRIX_TRANS && opt != MATRIX_INV) { 
	/* second source range wanted */
	clearlines(0, 0);
	strcpy(s, get_src_2[opt - MATRIX_ADD]);
	get_str(s, TSSIZE, NULL);
	if (*s == '\0' || (rge_s2 = findrge(s)) == NULL) {
	    if (*s) error("Input syntax error");
	    scxfree(rge_s1);
	    return 1;
	}
    }

    /* check for conformability before asking for dest */
    if (check_source_ranges(rge_s1, rge_s2, 
			    mins1r, maxs1r, mins1c, maxs1c,
			    mins2r, maxs2r, mins2c, maxs2c,
			    opt)) {
	scxfree(rge_s1);
	if (rge_s2 != NULL) scxfree(rge_s2);
	return 1;
    }

    clearlines(0, 0);
    strcpy(s, "top left cell for result: ");
    get_str(s, TSSIZE, NULL);
    if (*s == '\0' || (rge_d = findrge(s)) == NULL) {
	if (*s) error("Input syntax error");
	scxfree(rge_s1);
	if (rge_s2 != NULL) scxfree(rge_s2);
	return 1;
    }

    set_dest(rge_d, mindr, mindc, maxdr, maxdc,
	     mins1r, maxs1r, mins1c, maxs1c, 
	     mins2c, maxs2c, opt);

    scxfree(rge_s1);
    if (rge_s2 != NULL) scxfree(rge_s2);
    scxfree(rge_d);

    return 0;
}	 

static int 
convert(int base, char s[], int size)
     /* Convert the col, row into integer */
{ 
    int val, i;
    int temp;

    temp = 0;
    val = 0;
    for (i=0; (i<size) && (s[i] != '\0'); i++) {
	if (((s[i]<='Z') && (s[i]>='A')) || ((s[i]<='z') && (s[i]>='a'))) {
	    if (islower(s[i]))
		s[i] = toupper(s[i]);
	    val = temp*base + ( s[i]-'A');
	    temp = temp + 1;
	}
	else if ((s[i]<='9') && (s[i]>='0'))
	    val = val*base + (s[i]-'0');
    }
    return val;
}

struct m_range *
findrge(char *s)
     /* get a range from user input string */
{ 
    char col[COLIM], row[ROWLIM];
    int i, j, mtemp[5];
    struct m_range *rge;

    /* check for a named range (with leading quote) */
    if (*s == '\"') {
	struct range *r;

	if ((r = find_range(s + 1, strlen(s) - 2, NULL, NULL))) {
	    rge = scxmalloc(sizeof *rge);
	    rge->sr = r->r_left.vp->row;
	    rge->sc = r->r_left.vp->col;
	    rge->er = r->r_right.vp->row;
	    rge->ec = r->r_right.vp->col;
	    return rge;
	} else
	    return NULL;
    }

    /* otherwise parse as, e.g., A0:B4 */
    for (i=0; i<=4; i++) mtemp[i] = 0;
    j = 0;
    while (*s != '\0') {
	i = 0;
	if (*s == ':') s++;
	while ((*s <= 'Z' && *s >= 'A') || (*s <= 'z' && *s >= 'a'))
	    col[i++] = *(s++);
	col[i] = '\0';
	if (strlen(col) == 0 || strlen(col) > COLIM-1)
	    return NULL;
	mtemp[j++] = convert(26, col, strlen(col));
	i = 0;
	while (*s <= '9' && *s >= '0')
	    row[i++] = *(s++);
	row[i] = '\0';
	if (strlen(row) == 0 || strlen(row) > ROWLIM-1)
	    return NULL;
	mtemp[j++] = convert(10, row, strlen(row)); 
    } 

    rge = scxmalloc(sizeof *rge);

    rge->sc = mtemp[0];
    rge->sr = mtemp[1];
    rge->ec = mtemp[2];
    rge->er = mtemp[3];

    return rge;
} 

/* -------------- functions to assemble matrix commands ----------- */

void 
get_add_sub(int opt)
     /* assemble command for matrix addition, subtraction */
{
    int mins1r, mins1c;
    int maxs1r, maxs1c;
    int mins2r, mins2c;
    int maxs2r, maxs2c;
    int mindr, mindc;
    int maxdr, maxdc;
    int vr, vc;

    if (get_matrix_ranges(&mins1r, &maxs1r, &mins1c, &maxs1c,
			  &mins2r, &maxs2r, &mins2c, &maxs2c,
			  &mindr, &mindc, &maxdr, &maxdc,
			  opt))
	return;

    erase_area(mindr, mindc, maxdr, maxdc);

    if (mins1r == maxs1r && mins1c == maxs1c && mins2r == maxs2r &&
        mins2c == maxs2c )  { /* Source is a single cell */
        for(vr = mindr; vr <= maxdr; vr++)
            for (vc = mindc; vc <= maxdc; vc++)
		add_sub_matrix(vr, vc, mins1r, mins1c, maxs1r, maxs1c,
			       mins2r, mins2c, maxs2r, maxs2c, opt);
    } else if (mins1r == maxs1r && mins2r == maxs2r) {
        /* Source is a single row */
        for (vr = mindr; vr <= maxdr; vr++)
	    add_sub_matrix(vr, mindc, mins1r, mins1c, maxs1r, maxs1c,
			   mins2r, mins2c, maxs2r, maxs2c, opt);
    } else if (mins1c == maxs1c && mins2c == maxs2c ) {
        /* Source is a single column */
        for (vc = mindc; vc <= maxdc; vc++)
	    add_sub_matrix(mindr, vc, mins1r, mins1c, maxs1r, maxs1c,
			   mins2r, mins2c, maxs2r, maxs2c, opt);
    } else { /* Everything else */
        add_sub_matrix(mindr, mindc, mins1r, mins1c, maxs1r, maxs1c,
		       mins2r, mins2c, maxs2r, maxs2c, opt);
    }
}

void 
get_mult(void)
     /* assemble command for matrix multiplication */
{
    int mins1r, mins1c;
    int maxs1r, maxs1c;
    int mins2r, mins2c;
    int maxs2r, maxs2c;
    int mindr, mindc;
    int maxdr, maxdc;
    int vr, vc;

    if (get_matrix_ranges(&mins1r, &maxs1r, &mins1c, &maxs1c,
			  &mins2r, &maxs2r, &mins2c, &maxs2c,
			  &mindr, &mindc, &maxdr, &maxdc,
			  MATRIX_MULT))
	return;

    erase_area(mindr, mindc, maxdr, maxdc);
    if (mins1r == maxs1r && mins1c == maxs1c && mins2r == maxs2r &&
        mins2c == maxs2c)  { /* Source is a single cell */
        for(vr = mindr; vr <= maxdr; vr++)
            for (vc = mindc; vc <= maxdc; vc++)
		multmatrix(vr, vc, mins1r, mins1c, maxs1r, maxs1c,
			   mins2r, mins2c, maxs2r, maxs2c);
    }
    else { /* Everything else */
        multmatrix(mindr, mindc, mins1r, mins1c, maxs1r, maxs1c,
		   mins2r, mins2c, maxs2r, maxs2c);
    }
}

void 
get_trans_invert(int opt)  
     /* assemble command for matrix transposition, inversion */    
{
    int minsr, minsc;
    int maxsr, maxsc;
    int mindr, mindc;
    int maxdr, maxdc;
    int vr, vc;

    if (get_matrix_ranges(&minsr, &maxsr, &minsc, &maxsc,
			  NULL, NULL, NULL, NULL,
			  &mindr, &mindc, &maxdr, &maxdc,
			  opt))
	return;

    erase_area(mindr, mindc, maxdr, maxdc); /* clear the dest area */

    if (opt == MATRIX_TRANS) {
	if (minsr == maxsr && minsc == maxsc) {
	    /* Source is a single cell */
	    for(vr = mindr; vr <= maxdr; vr++)
		for (vc = mindc; vc <= maxdc; vc++)
		    transpose(vr, vc, minsr, minsc, maxsr, maxsc);
	} else if (minsr == maxsr) {
	    /* Source is a single row */
	    for (vc = mindc; vc <= maxdc; vc++)
		transpose(mindr, vc, minsr, minsc, maxsr, maxsc);
	} else if (minsc == maxsc) {
	    /* Source is a single column */
	    for (vr = mindr; vr <= maxdr; vr++)
		transpose(vr, mindc, minsr, minsc, maxsr, maxsc);
	} else {
	    /* Everything else */
	    transpose(mindr, mindc, minsr, minsc, maxsr, maxsc);
	}
    } else {
	if (minsr == maxsr && minsc == maxsc) {
	    /* Source is a single cell */
	    for (vr = mindr; vr <= maxdr; vr++)
		for (vc = mindc; vc <= maxdc; vc++)
		    invertmatrix(vr, vc, minsr, minsc, maxsr, maxsc);
	} else {
	    /* Everything else */
	    invertmatrix(mindr, mindc, minsr, minsc, maxsr, maxsc);
	}
    }
}

static int 
get_regress_ranges (int *mins1r, /* min row, source 1 */
		    int *maxs1r, /* max row, source 1 */
		    int *mins1c, /* min col, source 1 */
		    int *maxs1c, /* max col, source 1 */
		    int *mins2r, /* min row, source 2 */
		    int *maxs2r, /* max row, source 2 */
		    int *mins2c, /* min col, source 2 */
		    int *maxs2c, /* max col, source 2 */
		    int *mindr,  /* min row, dest */
		    int *mindc   /* min col, dest */
		    )
{
    char s[100];
    struct m_range *rge_s1 = NULL, *rge_s2 = NULL, *rge_d = NULL;
    struct ent *rmin, *rmax;

#ifdef VR3
    strcpy(s, "dependent var range: ");
#else
    strcpy(s, "dependent variable range: ");
#endif
    get_str(s, TSSIZE, NULL);
    if (*s == '\0' || (rge_s1 = findrge(s)) == NULL) {
	if (*s) error("Input syntax error");
	return 1;
    }

    rmin = lookat(rge_s1->sr, rge_s1->sc);
    rmax = lookat(rge_s1->er, rge_s1->ec);
    *mins1c = rmin->col;
    *mins1r = rmin->row;
    *maxs1c = rmax->col;
    *maxs1r = rmax->row;
    
    if (*mins1c != *maxs1c || *maxs1r <= *mins1r) {
	error("need column vector for dep. var.");
	scxfree(rge_s1);
	return 1;
    }

    clearlines(0, 0);
#ifdef VR3
    strcpy(s, "independent var range: ");
#else
    strcpy(s, "independent variable range: ");
#endif
    get_str(s, TSSIZE, NULL);
    if (*s == '\0' || (rge_s2 = findrge(s)) == NULL) {
	scxfree(rge_s1);
	if (*s) error("Input syntax error");
	return 1;
    }	

    rmin = lookat(rge_s2->sr, rge_s2->sc);
    rmax = lookat(rge_s2->er, rge_s2->ec);
    *mins2c = rmin->col;
    *mins2r = rmin->row;
    *maxs2c = rmax->col;
    *maxs2r = rmax->row;

    if (*mins2c != *maxs2c || *maxs2r <= *mins2r) {
	error("need col vector for indep var");
	scxfree(rge_s1);
	scxfree(rge_s2);
	return 1;
    }    

    if (*maxs1r - *mins1r != *maxs2r - *mins2r) {
	error("x and y vectors not same length");
	return 1;
    }

    clearlines(0, 0);
    strcpy(s, "top left cell for result: ");
    get_str(s, TSSIZE, NULL);
    if (*s == '\0' || (rge_d = findrge(s)) == NULL) {
	if (*s) error("Input syntax error");
	scxfree(rge_s1);
	scxfree(rge_s2);
	return 1;
    }

    rmin = lookat(rge_d->sr, rge_d->sc);
    *mindc = rmin->col;
    *mindr = rmin->row;

    scxfree(rge_s1);
    scxfree(rge_s2);
    scxfree(rge_d);

    return 0;
}	 

void 
get_regress(void)
     /* assemble command for simple regression */
{
    int mins1r, mins1c;
    int maxs1r, maxs1c;
    int mins2r, mins2c;
    int maxs2r, maxs2c;
    int mindr, mindc;

    if (get_regress_ranges(&mins1r, &maxs1r, &mins1c, &maxs1c,
			   &mins2r, &maxs2r, &mins2c, &maxs2c,
			   &mindr, &mindc))
	return;

    erase_area(mindr, mindc, mindr+1, mindc+1);

    regress(mins1c, mins1r, maxs1r, 
	    mins2c, mins2r, maxs2r, 
	    mindc, mindr);
}


/* --------------- matrix calculation functions -------------- */

static void 
add_sub_matrix(int vr, int vc, int mins1r, int mins1c, 
	       int maxs1r, int maxs1c, int mins2r, int mins2c,
	       int maxs2r, int maxs2c, int opt)
     /* add or subtract two matrices */
{
    register struct ent *p1, *p2;
    register struct ent *n;
    register int s1r, s1c, s2r, s2c;
    register int dr, dc;

    for (dr=vr, s1r=mins1r,s2r=mins2r; s1r<=maxs1r; s1r++, dr++, s2r++) {
	for (dc=vc, s1c=mins1c, s2c=mins2c; s1c<=maxs1c; s1c++, dc++, s2c++) {
            n = lookat(dr, dc);
            (void) clearent(n);
            if ((p2 = *ATBL(tbl, s2r, s2c)) && (p2->flags & is_valid)) {
		if ((p1 = *ATBL(tbl, s1r, s1c)) && (p1->flags & is_valid)) {
		    copyent(n, p1, dr - s1r, dc - s1c);
		    if (opt == MATRIX_ADD)
			n->v = p1->v + p2->v;
		    else
			n->v = p1->v - p2->v;
		}
	    }
	}
    }
}

static void 
multmatrix(int vr, int vc, int mins1r, int mins1c, 
	   int maxs1r, int maxs1c, int mins2r, int mins2c,
	   int maxs2r, int maxs2c)
     /* multiply two matrices */
{
    register struct ent *p1, *p2;
    register struct ent *n;
    register int s1r, s1c, s2r, s2c;
    register int dr, dc;
    double sum;
    int i, j, k;
    double list1[MINMAX][MINMAX];
    double list2[MINMAX][MINMAX];
    double list3[MINMAX][MINMAX];

    for (i=0; i<MINMAX; i++) {
	for (j=0; j<MINMAX; j++) {
            list1[i][j] = 0;
            list2[i][j] = 0;
            list3[i][j] = 0;
        }
    }

    for (i=0, s1r=mins1r; s1r<=maxs1r; s1r++, i++) {
        j = 0;
        for (s1c=mins1c;s1c<=maxs1c;s1c++) 
	    if ((p1 = *ATBL(tbl, s1r, s1c)) && p1->flags & is_valid)
		list1[i][j++] = p1->v;
    }
          
    for (i=0, s2r=mins2r; s2r<=maxs2r; s2r++, i++) {
	j = 0;
	for (s2c=mins2c; s2c<=maxs2c; s2c++)
            if ((p2 = *ATBL(tbl, s2r, s2c)) && p2->flags & is_valid)
		list2[i][j++] = p2->v;
    }

    for (i=0; i<MINMAX; i++) {
	for (j=0; j<MINMAX; j++) {
	    sum = 0;
	    for (k=0;k<MINMAX;k++)
		sum = sum + (list1[i][k]) * (list2[k][j]);
	    list3[i][j] = sum;
	}
    }

    for (i=0, dr=vr, s1r=mins1r; s1r<=maxs1r; s1r++, dr++, i++) {
	j = 0;
	for (dc=vc, s1c=mins2c; s1c<=maxs2c; s1c++, dc++) {
            n = lookat(dr, dc);
            (void) clearent(n);
            if ((p1 = *ATBL(tbl, s1r, s1c)) && (p1->flags & is_valid)) {
		copyent(n, p1, dr - s1r, dc - s1c);
		n->v = list3[i][j++];
	    }
	}
    }
}

static void 
transpose(int vr, int vc, int minsr, int minsc, int maxsr, int maxsc) 
     /* calculate matrix transpose */
{
    register struct ent *p;
    register struct ent *n;
    register int sr, sc;
    register int dr, dc;

    for (dc=vc, sr=minsr; sr<=maxsr; sr++, dc++) {
	for (dr=vr, sc=minsc; sc<=maxsc; sc++, dr++) {
            n = lookat(dr, dc);
            (void) clearent(n);
            if ((p = *ATBL(tbl, sr, sc)))
                copyent( n, p, dr - sr, dc - sc);
        }
    }
}

static void 
invertmatrix (int vr, int vc, int minsr, int minsc, int maxsr, int maxsc)
     /* do matrix inversion */
{
    register struct ent *p;
    register struct ent *q;
    register int sr, sc;
    register int dr, dc;
    double list[MAXROW][MAXCOL];
    int i, j, k, m, n;
    int rowlim, collim;
    double temp;
   
    for (i=0; i<((maxsr-minsr)*2+1); i++)
	for (j=0; j<((maxsc-minsc)*2+1); j++)
	    list[i][j] = 0;
    rowlim = maxsr-minsr+1;
    collim = maxsc-minsc+1;
    for (i=0; i<rowlim; i++)
	for (j=0; j<collim; j++)
	    if (i == j) list[i][j] = 1;

    for (i=0, sr=minsr;(i<rowlim) && (sr<=maxsr); i++, sr++)
	for (j=collim, sc=minsc; j<2*collim && sc<=maxsc; j++, sc++)
	    if ((p = *ATBL(tbl, sr, sc)) && p->flags & is_valid)
                list[i][j] = p->v;
    for (j=collim; j<2*collim; j++)  {
        k = j-collim;
        temp = list[k][j];
        for (i=0; i<2*collim; i++)
            list[k][i] = list[k][i] / temp;
        for (m=0; m < rowlim; m++)
            for (n=0; n<2*collim; n++)
		if (m != k && n != j) 
		    list[m][n] = list[m][n] - list[k][n]*list[m][j];
    }

    for (i=0, dr=vr, sr=minsr; sr<=maxsr; sr++, dr++, i++) {
	j = 0;
	for (dc=vc, sc=minsc; sc<=maxsc; sc++, dc++) {
            q = lookat(dr, dc);
            (void) clearent(q);
            if ((p = *ATBL(tbl, sr, sc)) && (p->flags & is_valid)) {
		copyent(q, p, dr - sr, dc - sc);
		q->v = list[i][j++];
	    }
	}
    }
}

static int
regress(int ycol, int ysr, int yer,
	int xcol, int xsr, int xer,
	int dcol, int drow)
{
    register struct ent *p1, *p2, *targ;
    int i, err = 0;
    double xsum = 0, ysum = 0, xysum = 0;
    double x2sum = 0, y2sum = 0, sxx = 0, syy = 0, sxy = 0;
    double xbar, ybar, ess, r2, sdb;
    int n = xer - xsr + 1;
    int yoff = ysr - xsr;
    double tmp, *x, *y;
    double a, b;
    static char *cellstr[] = {"const:", 
			      "slope:", 
			      "s(slope):", 
			      "R^2:"};

    x = scxmalloc(n * sizeof *x);
    y = scxmalloc(n * sizeof *y);
    if (x == NULL || y == NULL) return 1;

    for (i=0; i<n; i++) {
	if ((p1 = *ATBL(tbl, xsr+i, xcol)) && p1->flags & is_valid) {
	    x[i] = p1->v;
	    xsum += x[i];
	    x2sum += x[i] * x[i];
	} else {
	    err = 1;
	    goto getout;
	}
	if ((p2 = *ATBL(tbl, xsr+yoff+i, ycol)) && p2->flags & is_valid) {
	    y[i] = p2->v;
	    ysum += y[i];
	    y2sum += y[i] * y[i];
	} else {
	    err = 1;
	    goto getout;
	}
	xysum += x[i] * y[i];
    }
    xbar = xsum / n;
    ybar = ysum / n;

    for (i=0; i<n ; i++) {
	sxy += (x[i] - xbar) * (y[i] - ybar);
	sxx += (x[i] - xbar) * (x[i] - xbar);
	syy += (y[i] - ybar) * (y[i] - ybar);
    }

    if (sxx <= 0.0) {
	error("SXX not positive");
	err = 1;
	goto getout;
    }

    b = sxy / sxx;
    a = ybar - b * xbar;
    ess = 0;
    for (i=0; i<n; i++) {
	tmp = y[i] - a - b * x[i];
	ess += tmp * tmp;
    }
    sdb = sqrt(ess / ((n-2) * sxx));
    r2 = b * b * sxx / syy;

    for (i=0; i<4; i++) {
	targ = lookat(drow + i, dcol);
	(void) clearent(targ);
	label(targ, cellstr[i], 1);
	targ->flags |= is_changed | is_locked;
	
	targ = lookat(drow+i, dcol+1);
	(void) clearent(targ);
	targ->v = (i == 0)? a : (i == 1)? b : (i == 2)? sdb : r2;
	targ->flags |= is_valid | is_locked | is_changed;
    }

 getout:
    scxfree(x);
    scxfree(y);
    return err;
}


