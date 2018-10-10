/*
 * Encryption utilites
 * Bradley Williams	
 * {allegra,ihnp4,uiucdcs,ctvax}!convex!williams
 */

#include <stdio.h>
#include <curses.h>

#if defined(BSD42) || defined(BSD43)
#include <sys/file.h>
#else
#include <fcntl.h>
#endif

#include "sc.h"

extern char curfile[];
char        *strcpy();
#ifdef SYSV3
void exit();
#endif

int         Crypt = 0;

#define DEFWIDTH 10
#define DEFPREC   2

creadfile (save, eraseflg)
char *save;
{
    register FILE *f;
    int pipefd[2];
    int fildes;
    int pid;

    if (eraseflg && strcmp(save, curfile) && modcheck(" first")) return;

    fildes = open (save, O_RDONLY, 0);
    if (fildes < 0)
    {
	error ("Can't read %s", save);
	return;
    }

    if (eraseflg) erasedb ();

    if (pipe(pipefd) < 0) {
	error("Can't make pipe to child");
	return;
    }

    deraw();
    if ((pid=fork()) == 0)			  /* if child  */
    {
	(void) close (0);		  /* close stdin */
	(void) close (1);		  /* close stdout */
	(void) close (pipefd[0]);	  /* close pipe input */
	(void) dup (fildes);		  /* standard in from file */
	(void) dup (pipefd[1]);		  /* connect to pipe */
	(void) fprintf (stderr, " ");
	(void) execl ("/bin/sh", "sh", "-c", "crypt", 0);
	exit (-127);
    }
    else				  /* else parent */
    {
	(void) close (fildes);
	(void) close (pipefd[1]);	  /* close pipe output */
	f = fdopen (pipefd[0], "r");
	if (f == 0)
	{
	    (void) kill (pid, -9);
	    error ("Can't fdopen file %s", save);
	    (void) close (pipefd[0]);
	    return;
	}
    }

    while (fgets(line,sizeof line,f)) {
	linelim = 0;
	if (line[0] != '#') (void) yyparse ();
    }
    (void) fclose (f);
    (void) close (pipefd[0]);
    while (pid != wait(&fildes)) /**/;
    goraw();
    linelim = -1;
    modflg++;
    if (eraseflg) {
	(void) strcpy (curfile, save);
	modflg = 0;
    }
    EvalAll();
}

cwritefile (fname, r0, c0, rn, cn)
char *fname;
{
    register FILE *f;
    register struct ent **p;
    register r, c;
    int pipefd[2];
    int fildes;
    int pid;
    char save[1024];

    if (*fname == 0) fname = &curfile[0];

    (void) strcpy(save,fname);

    fildes = open (save, O_WRONLY|O_CREAT, 0600);
    if (fildes < 0)
    {
	error ("Can't create %s", save);
	return(-1);
    }

    if (pipe (pipefd) < 0) {
	error ("Can't make pipe to child\n");
	return(-1);
    }

    deraw();
    if ((pid=fork()) == 0)			  /* if child  */
    {
	(void) close (0);			  /* close stdin */
	(void) close (1);			  /* close stdout */
	(void) close (pipefd[1]);		  /* close pipe output */
	(void) dup (pipefd[0]);			  /* connect to pipe input */
	(void) dup (fildes);			  /* standard out to file */
	(void) fprintf (stderr, " ");
	(void) execl ("/bin/sh", "sh", "-c", "crypt", 0);
	exit (-127);
    }
    else				  /* else parent */
    {
	(void) close (fildes);
	(void) close (pipefd[0]);		  /* close pipe input */
	f = fdopen (pipefd[1], "w");
	if (f == 0)
	{
	    (void) kill (pid, -9);
	    error ("Can't fdopen file %s", save);
	    (void) close (pipefd[1]);
	    return(-1);
	}
    }

    (void) fprintf (f, "# This data file was generated by the Spreadsheet ");
    (void) fprintf (f, "Calculator.\n");
    (void) fprintf (f, "# You almost certainly shouldn't edit it.\n\n");
    for (c=0; c<MAXCOLS; c++)
	if (fwidth[c] != DEFWIDTH || precision[c] != DEFPREC)
	    (void)fprintf(f,"format %s %d %d\n",coltoa(c),fwidth[c],precision[c]);
    write_range(f);
    if (mdir)
	(void) fprintf(f, "mdir \"%s\"\n", mdir);
    for (r=r0; r<=rn; r++) {
	p = &tbl[r][0];
	for (c=c0; c<=cn; c++, p++)
	    if (*p) {
		if ((*p)->label) {
		    edits(r, c);
		    (void) fprintf(f, "%s\n", line);
		}
		if ((*p)->flags&is_valid) {
		    editv(r, c);
		    (void) fprintf (f, "%s\n",line);
		}
	    }
    }
    (void) fclose (f);
    (void) close (pipefd[1]);
    while (pid != wait(&fildes)) /**/;
    (void) strcpy(curfile,save);

    modflg = 0;
    error("File '%s' written.",curfile);
    goraw();
    return(0);
}
