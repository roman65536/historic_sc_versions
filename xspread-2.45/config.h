/* configuration header for xspread */

#ifndef CONFIG_H
#define CONFIG_H

/* uncomment below if you want to enable "vi mode" (editing of expressions
   for entering into cells) in xspread.  Leaving this out shaves about
   10K off the executable for the agenda.
*/
/* #define USE_VI_MODE */

/* special stuff for a tiny version of xspread for the agenda vr3 */
#ifdef VR3
# define SC_FONT "5x7"
# define MENUSPACE 1         /* space between men items on line */
# define MIN_COLS 40
# define MIN_ROWS 20
/* see "textrow" macro in sc.h */
# define TEXTROW_ADJUST 0    /* was 2 */
# define XSH_MIN_WIDTH 160
# define XSH_MIN_HEIGHT 240
/* see clearlines() in screen.c */
# define CLEAR_START_ADD 1  
# define CLEAR_HEIGHT_ADD 0
# define CURSOR_OFFSET 1   /* was 1 */
# define DEFWIDTH 8	/* Default column width and precision */ 
#else /* regular, not tiny version */
# define SC_FONT "9x15"
# define MENUSPACE 2
# define MIN_COLS 80
# define MIN_ROWS 25
/* see "textrow" macro in sc.h */
# define TEXTROW_ADJUST -1
# define XSH_MIN_WIDTH (MIN_COLS * curfontwidth)
# define XSH_MIN_HEIGHT ((MIN_ROWS + 1) * curfontheight)
/* see clearlines() in screen.c */
# define CLEAR_START_ADD 3 
# define CLEAR_HEIGHT_ADD 1  
# define CURSOR_OFFSET 4
/* Default column width and precision */ 
# define DEFWIDTH 10	
#endif

/*  Define this if you want backups saved of the files */
#define DOBACKUPS

/*  The name to save the backup worksheet to  */
#define SAVENAME "SC.SAVE"

/*  Define this if your system doesn't have rint in the math lib */
#if defined(__convex__)
#define RINT
#endif

/*  The regular expression handlers
 *  RE_COMP for system re_comp/re_exec()   (BSD, SUN)
 *  REGCMP for standard system regcmp/regex handlers (SVR3/4)
 *  REGCOMP for spencer lib use
 *  REG_COMP for POSIX.2 FIPS 
 */

/*  386BSD has patches to use RE_COMP, but some people may not have them */
#if defined(__386BSD__) || defined(__hpux)
#define REGCOMP
#else
#if defined(systemvthing)
#define REGCMP
#else
/* defined(mips) || defined(sun) || defined(__convex__) || defined(__osf__) */
#define RE_COMP
#endif
#endif

/* Define SIGVOID if your signal routine returns a void */
#define SIGVOID

#endif /* CONFIG_H */
