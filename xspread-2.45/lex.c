/*	SC	A Spreadsheet Calculator
 *		Lexical analyser
 *
 *		original by James Gosling, September 1982
 *		modifications by Mark Weiser and Bruce Israel,
 *			University of Maryland
 *
 *              More mods Robert Bond, 12/86
 *		More mods by Alan Silverstein, 3/88, see list of changes.
 *		$Revision: 1.10 $
 *
 */

#include <string.h>
#include <sys/types.h>
#include "config.h"

#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <signal.h>
#include <setjmp.h>
#include "sc.h"
#include "scXstuff.h"
#include <ctype.h>

#include "y.tab.h" 

char *mystrtof(char *volatile, double *);

jmp_buf wakeup;
jmp_buf fpe_buf;

sig_type
fpe_trap(int signo)
{
    longjmp(fpe_buf, 1);
}

struct key {
    char *key;
    int val;
};

struct key experres[] = {
#include "experres.h"
    {0, 0}};

struct key statres[] = {
#include "statres.h"
    {0, 0}};

int
yylex (void)
{
    char *volatile p = line + linelim;
    int ret;

    while (isspace(*p))
	p++;
    if (*p == '\0') ret = -1;
    else if (isalpha(*p)) {
	char *tokenst = p;
	register int tokenl;
	register struct key *tblp;
	tokenl = 0;
	/*
	 * This picks up either 1 or 2 alpha characters (a column) or
	 * tokens with at least three leading alphas and '_' or digits
	 * (a function or token or command or a range name)
	 */
	while (isalpha(*p) || (((*p == '_') || isdigit(*p)) && (tokenl > 2))) {
	    p++;
	    tokenl++;
	}
	if (tokenl <= 2) { /* a COL is 1 or 2 char alpha
			      (but not pi, ln, fv, pv, if -- 
			      this should be fixed!) */
	    if (tokenl == 2 && tokenst[0] == 'p' && tokenst[1] == 'i') {
		ret = K_PI;
	    } else if (tokenl == 2 && tokenst[0] == 'l' && tokenst[1] == 'n') {
		ret = K_LN;
	    } else if (tokenl == 2 && tokenst[0] == 'f' && tokenst[1] == 'v') {
		ret = K_FV;
	    } else if (tokenl == 2 && tokenst[0] == 'p' && tokenst[1] == 'v') {
		ret = K_PV;
	    } else if (tokenl == 2 && tokenst[0] == 'i' && tokenst[1] == 'f') {
		ret = K_IF;
	    } else {
		ret = COL;
		yylval.ival = atocol (tokenst, tokenl);
	    }
	} else {
	    ret = WORD;
	    for (tblp = linelim ? experres : statres; tblp->key; tblp++)
		if (((tblp->key[0]^tokenst[0])&0137) == 0
		    && tblp->key[tokenl] == 0) {
		    register int i = 1;
		    while (i<tokenl && ((tokenst[i]^tblp->key[i])&0137)==0)
			i++;
		    if (i >= tokenl) {
			ret = tblp->val;
			break;
		    }
		}
	    if (ret == WORD) { 
		struct range *r;
		if ((r = find_range(tokenst, tokenl, NULL, NULL))) {
		    yylval.rval.left = r->r_left;
		    yylval.rval.right = r->r_right;
		    if (r->r_is_range)
		        ret = RANGE;
		    else
			ret = VAR;
		} else {
		    linelim = p-line;
#ifdef VR3
		    yyerror("Bad line");
#else
		    yyerror("Unintelligible word");
#endif
		}
	    }
	}
    } else if (*p == '.' || isdigit(*p)) {
	sig_type (*sig_save)();
	double volatile v = 0.0;
	char *volatile nstart = p;
	int temp;

	sig_save = signal(SIGFPE, fpe_trap);
	if (setjmp(fpe_buf)) {
	    (void) signal(SIGFPE, sig_save);
	    yylval.fval = v;
	    error("Floating point exception\n");
	    return FNUMBER;
	}

	if (*p != '.') {
	    do v = v*10.0 + (double) ((unsigned) *p - '0');
	    while (isdigit(*++p));
	}
	if (*p=='.' || *p == 'e' || *p == 'E') {
	    ret = FNUMBER;
	    p = mystrtof(nstart, &yylval.fval);
	} else {
	    /* A NUMBER must hold at least MAXROW and MAXCOL */
	    /* This is consistent with a short row and col in struct ent */
	    if (v > (double)32767 || v < (double)-32768) {
		ret = FNUMBER;
		yylval.fval = v;
	    } else {
		temp = (int)v;
		if((double)temp != v) {
		    ret = FNUMBER;
		    yylval.fval = v;
		} else {
		    ret = NUMBER;
		    yylval.ival = temp;
		}
	    }
	}
	(void) signal(SIGFPE, sig_save);
    } else if (*p == '"') {
	char *ptr;

        ptr = p+1;	/* "string" or "string\"quoted\"" */
        while(*ptr && ((*ptr != '"') || (*(ptr-1) == '\\')))
	    ptr++;
        ptr = scxmalloc((unsigned)(ptr-p));
	yylval.sval = ptr;
	p += 1;
	while (*p && (*p != '"' || *(p-1) == '\\'))
	    *ptr++ = *p++;
	*ptr = 0;
	if (*p)
	    p += 1;
	ret = STRING;
    } else if (*p == '[') {
	while (*p && *p != ']')
	    p++;
	if (*p)
	    p++;
	linelim = p-line;
	return yylex();
    } else ret = *p++;
    linelim = p-line;
    return ret;
}


/*
 * Given a token string starting with a symbolic column name and its valid
 * length, convert column name ("A"-"Z" or "AA"-"ZZ") to a column number (0-N).
 * Never mind if the column number is illegal (too high).  The procedure's name
 * and function are the inverse of coltoa().
 * 
 * Case-insensitivity is done crudely, by ignoring the 040 bit.
 */

int
atocol (char *string, int len)
{
    register int col;

    col = (string [0] & 0137) - 'A';

    if (len == 2)		/* has second char */
	col = ((col + 1) * 26) + ((string [1] & 0137) - 'A');

    return (col);
}

/*
 * This converts a floating point number of the form
 * [s]ddd[.d*][esd*]  where s can be a + or - and e is E or e.
 * to floating point. 
 * p is advanced.
 */

char * 
mystrtof(char *volatile p, double *res)
{
    double acc;
    int sign;
    double fpos;
    int exp;
    int exps;
    sig_type (*sig_save)();

    sig_save = signal(SIGFPE, fpe_trap);
    if (setjmp(fpe_buf)) {
	error("Floating point exception\n");
	*res = 0.0; 
        (void) signal(SIGFPE, sig_save);
	return p;
    }
    acc = 0.0;
    sign = 1;
    exp = 0;
    exps = 1;
    if (*p == '+')
        p++;
    else if (*p == '-') {
        p++;
        sign = -1;
    }
    while (isdigit(*p)) {
        acc = acc * 10.0 + (double)(*p - '0');
        p++;
    }
    if (*p == 'e' || *p == 'E') {
	p++;
        if (*p == '+')
	    p++;
        else if (*p == '-') {
	    p++;
	    exps = -1;
        }
        while(isdigit(*p)) {
	    exp = exp * 10 + (*p - '0');
	    p++;
        }
    }
    if (*p == '.') {
	fpos = 1.0/10.0;
	p++;
	while(isdigit(*p)) {
	    acc += (*p - '0') * fpos;
	    fpos *= 1.0/10.0;
	    p++;
	}
    }
    if (*p == 'e' || *p == 'E') {
	exp = 0;
	exps = 1;
        p++;
	if (*p == '+')
	    p++;
	else if (*p == '-') {
	    p++;
	    exps = -1;
	}
	while(isdigit(*p)) {
	    exp = exp * 10 + (*p - '0');
	    p++;
	}
    }
    if (exp) {
	if (exps > 0)
	    while (exp--)
		acc *= 10.0;
	else
	    while (exp--)
		acc *= 1.0/10.0;
    }
    if (sign > 0)
        *res = acc;
    else
	*res = -acc;

    (void) signal(SIGFPE, sig_save);
    return p;
}

