/*
 * A safer saner malloc, for careless programmers
 * $Revision: 6.21 A $
 */

#include <stdio.h>
#ifndef DOINGX
#include <curses.h>
#endif
#include "sc.h"

#ifdef __STDC__
static	void	fatal(char *);
#else	/* __STDC__ */
static void	fatal();
extern void	free();
extern char *	malloc();
extern char *	realloc();
#endif	/* __STDC__ */

#define	MAGIC	(double)1234567890.12344

char *
scxmalloc(n)
unsigned int	n;
{
	register char *ptr;

	if ((ptr = malloc(n + sizeof(double))) == NULL)
		fatal("scxmalloc: no memory");
	*((double *) ptr) = MAGIC;		/* magic number */
	return(ptr + sizeof(double));
}

/* we make sure realloc will do a malloc if needed */
char *
scxrealloc(ptr, n)
char	*ptr;
unsigned int n;
{
	if (ptr == NULL)
		return(scxmalloc(n));

	ptr -= sizeof(double);
	if (*((double *) ptr) != MAGIC)
		fatal("scxrealloc: storage not scxmalloc'ed");

	if ((ptr = realloc(ptr, n + sizeof(double))) == NULL)
		fatal("scxmalloc: no memory");
	*((double *) ptr) = MAGIC;		/* magic number */
	return(ptr + sizeof(double));
}

void
scxfree(p)
char *p;
{
	if (p == NULL)
		fatal("scxfree: NULL");
	p -= sizeof(double);
	if (*((double *) p) != MAGIC)
		fatal("scxfree: storage not malloc'ed");
	free(p);
}

#ifdef PSC
void
static fatal(str)
char *str;
{
    (void) fprintf(stderr,"%s\n", str);
    exit(1);
}
#else
static void
fatal(str)
char *str;
{
#ifndef DOINGX
    deraw();
#endif
    (void) fprintf(stderr,"%s\n", str);
    diesave();
    exit(1);
}
#endif /* PSC */
