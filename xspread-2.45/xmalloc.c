/*
 * A safer saner malloc, for careless programmers
 * $Revision: 1.5 $
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "sc.h"

static void fatal(char *);

#define	MAGIC	(double)1234567890.12344

void *
scxmalloc(size_t n)
{
    register char *ptr;

    if ((ptr = malloc(n + sizeof(double))) == NULL)
	fatal("scxmalloc: no memory");
    *((double *) ptr) = MAGIC;		/* magic number */
    return(ptr + sizeof(double));
}

/* we make sure realloc will do a malloc if needed */
void *
scxrealloc(void *ptr, size_t n)
{
#ifdef DEBUG
    static size_t reall;

    fprintf(stderr, "scxrealloc: got request to add %u bytes\n", n);
    reall += n;
    if (reall > 65536) exit (EXIT_FAILURE);
#endif
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
scxfree(void *p)
{
    if (p == NULL)
	fatal("scxfree: NULL");
    p -= sizeof(double);
    if (*((double *) p) != MAGIC)
	fatal("scxfree: storage not malloc'ed");
    free(p);
}

static void
fatal(char *str)
{
    (void) fprintf(stderr,"%s\n", str);
    diesave();
    exit(EXIT_FAILURE);
}
