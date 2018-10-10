/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 17 "gram.y" /* yacc.c:339  */

#include <curses.h>
#include <stdlib.h>
#include "sc.h"

#ifdef USELOCALE
#include <locale.h>
#endif

#ifndef MSDOS
#include <unistd.h>
#endif

#define ENULL (struct enode *)0

#line 82 "gram.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "gram.h".  */
#ifndef YY_YY_GRAM_H_INCLUDED
# define YY_YY_GRAM_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING = 258,
    NUMBER = 259,
    FNUMBER = 260,
    RANGE = 261,
    VAR = 262,
    WORD = 263,
    PLUGIN = 264,
    COL = 265,
    S_SHOW = 266,
    S_HIDE = 267,
    S_INSERTCOL = 268,
    S_OPENCOL = 269,
    S_DELETECOL = 270,
    S_YANKCOL = 271,
    S_GETFORMAT = 272,
    S_FORMAT = 273,
    S_FMT = 274,
    S_LET = 275,
    S_LABEL = 276,
    S_LEFTSTRING = 277,
    S_RIGHTSTRING = 278,
    S_LEFTJUSTIFY = 279,
    S_RIGHTJUSTIFY = 280,
    S_CENTER = 281,
    S_COLOR = 282,
    S_ADDNOTE = 283,
    S_DELNOTE = 284,
    S_GET = 285,
    S_PUT = 286,
    S_MERGE = 287,
    S_WRITE = 288,
    S_TBL = 289,
    S_COPY = 290,
    S_MOVE = 291,
    S_ERASE = 292,
    S_YANK = 293,
    S_FILL = 294,
    S_SORT = 295,
    S_LOCK = 296,
    S_UNLOCK = 297,
    S_GOTO = 298,
    S_DEFINE = 299,
    S_UNDEFINE = 300,
    S_ABBREV = 301,
    S_UNABBREV = 302,
    S_FRAME = 303,
    S_FRAMETOP = 304,
    S_FRAMEBOTTOM = 305,
    S_FRAMELEFT = 306,
    S_FRAMERIGHT = 307,
    S_UNFRAME = 308,
    S_VALUE = 309,
    S_MDIR = 310,
    S_AUTORUN = 311,
    S_FKEY = 312,
    S_SCEXT = 313,
    S_ASCEXT = 314,
    S_TBL0EXT = 315,
    S_TBLEXT = 316,
    S_LATEXEXT = 317,
    S_SLATEXEXT = 318,
    S_TEXEXT = 319,
    S_SET = 320,
    S_UP = 321,
    S_DOWN = 322,
    S_LEFT = 323,
    S_RIGHT = 324,
    S_ENDUP = 325,
    S_ENDDOWN = 326,
    S_ENDLEFT = 327,
    S_ENDRIGHT = 328,
    S_SELECT = 329,
    S_INSERTROW = 330,
    S_OPENROW = 331,
    S_DELETEROW = 332,
    S_YANKROW = 333,
    S_PULL = 334,
    S_PULLMERGE = 335,
    S_PULLROWS = 336,
    S_PULLCOLS = 337,
    S_PULLXCHG = 338,
    S_PULLTP = 339,
    S_PULLFMT = 340,
    S_PULLCOPY = 341,
    S_WHEREAMI = 342,
    S_GETNUM = 343,
    S_FGETNUM = 344,
    S_GETSTRING = 345,
    S_GETEXP = 346,
    S_GETFMT = 347,
    S_GETFRAME = 348,
    S_GETRANGE = 349,
    S_EVAL = 350,
    S_SEVAL = 351,
    S_QUERY = 352,
    S_GETKEY = 353,
    S_ERROR = 354,
    S_RECALC = 355,
    S_REDRAW = 356,
    S_QUIT = 357,
    S_STATUS = 358,
    S_RUN = 359,
    S_PLUGIN = 360,
    S_PLUGOUT = 361,
    K_ERROR = 362,
    K_INVALID = 363,
    K_FIXED = 364,
    K_SUM = 365,
    K_PROD = 366,
    K_AVG = 367,
    K_STDDEV = 368,
    K_COUNT = 369,
    K_ROWS = 370,
    K_COLS = 371,
    K_ABS = 372,
    K_ACOS = 373,
    K_ASIN = 374,
    K_ATAN = 375,
    K_ATAN2 = 376,
    K_CEIL = 377,
    K_COS = 378,
    K_EXP = 379,
    K_FABS = 380,
    K_FLOOR = 381,
    K_HYPOT = 382,
    K_LN = 383,
    K_LOG = 384,
    K_PI = 385,
    K_POW = 386,
    K_SIN = 387,
    K_SQRT = 388,
    K_TAN = 389,
    K_DTR = 390,
    K_RTD = 391,
    K_MAX = 392,
    K_MIN = 393,
    K_RND = 394,
    K_ROUND = 395,
    K_IF = 396,
    K_PV = 397,
    K_FV = 398,
    K_PMT = 399,
    K_HOUR = 400,
    K_MINUTE = 401,
    K_SECOND = 402,
    K_MONTH = 403,
    K_DAY = 404,
    K_YEAR = 405,
    K_NOW = 406,
    K_DATE = 407,
    K_DTS = 408,
    K_TTS = 409,
    K_FMT = 410,
    K_SUBSTR = 411,
    K_UPPER = 412,
    K_LOWER = 413,
    K_CAPITAL = 414,
    K_STON = 415,
    K_EQS = 416,
    K_EXT = 417,
    K_LUA = 418,
    K_NVAL = 419,
    K_SVAL = 420,
    K_LOOKUP = 421,
    K_HLOOKUP = 422,
    K_VLOOKUP = 423,
    K_INDEX = 424,
    K_STINDEX = 425,
    K_AUTO = 426,
    K_AUTOCALC = 427,
    K_AUTOINSERT = 428,
    K_AUTOWRAP = 429,
    K_CSLOP = 430,
    K_BYROWS = 431,
    K_BYCOLS = 432,
    K_OPTIMIZE = 433,
    K_ITERATIONS = 434,
    K_NUMERIC = 435,
    K_PRESCALE = 436,
    K_EXTFUN = 437,
    K_CELLCUR = 438,
    K_TOPROW = 439,
    K_COLOR = 440,
    K_COLORNEG = 441,
    K_COLORERR = 442,
    K_BRAILLE = 443,
    K_BLACK = 444,
    K_RED = 445,
    K_GREEN = 446,
    K_YELLOW = 447,
    K_BLUE = 448,
    K_MAGENTA = 449,
    K_CYAN = 450,
    K_WHITE = 451,
    K_TBLSTYLE = 452,
    K_TBL = 453,
    K_LATEX = 454,
    K_SLATEX = 455,
    K_TEX = 456,
    K_FRAME = 457,
    K_RNDTOEVEN = 458,
    K_FILENAME = 459,
    K_MYROW = 460,
    K_MYCOL = 461,
    K_LASTROW = 462,
    K_LASTCOL = 463,
    K_COLTOA = 464,
    K_CRACTION = 465,
    K_CRROW = 466,
    K_CRCOL = 467,
    K_ROWLIMIT = 468,
    K_COLLIMIT = 469,
    K_PAGESIZE = 470,
    K_NUMITER = 471,
    K_ERR = 472,
    K_SCRC = 473,
    K_LOCALE = 474
  };
#endif
/* Tokens.  */
#define STRING 258
#define NUMBER 259
#define FNUMBER 260
#define RANGE 261
#define VAR 262
#define WORD 263
#define PLUGIN 264
#define COL 265
#define S_SHOW 266
#define S_HIDE 267
#define S_INSERTCOL 268
#define S_OPENCOL 269
#define S_DELETECOL 270
#define S_YANKCOL 271
#define S_GETFORMAT 272
#define S_FORMAT 273
#define S_FMT 274
#define S_LET 275
#define S_LABEL 276
#define S_LEFTSTRING 277
#define S_RIGHTSTRING 278
#define S_LEFTJUSTIFY 279
#define S_RIGHTJUSTIFY 280
#define S_CENTER 281
#define S_COLOR 282
#define S_ADDNOTE 283
#define S_DELNOTE 284
#define S_GET 285
#define S_PUT 286
#define S_MERGE 287
#define S_WRITE 288
#define S_TBL 289
#define S_COPY 290
#define S_MOVE 291
#define S_ERASE 292
#define S_YANK 293
#define S_FILL 294
#define S_SORT 295
#define S_LOCK 296
#define S_UNLOCK 297
#define S_GOTO 298
#define S_DEFINE 299
#define S_UNDEFINE 300
#define S_ABBREV 301
#define S_UNABBREV 302
#define S_FRAME 303
#define S_FRAMETOP 304
#define S_FRAMEBOTTOM 305
#define S_FRAMELEFT 306
#define S_FRAMERIGHT 307
#define S_UNFRAME 308
#define S_VALUE 309
#define S_MDIR 310
#define S_AUTORUN 311
#define S_FKEY 312
#define S_SCEXT 313
#define S_ASCEXT 314
#define S_TBL0EXT 315
#define S_TBLEXT 316
#define S_LATEXEXT 317
#define S_SLATEXEXT 318
#define S_TEXEXT 319
#define S_SET 320
#define S_UP 321
#define S_DOWN 322
#define S_LEFT 323
#define S_RIGHT 324
#define S_ENDUP 325
#define S_ENDDOWN 326
#define S_ENDLEFT 327
#define S_ENDRIGHT 328
#define S_SELECT 329
#define S_INSERTROW 330
#define S_OPENROW 331
#define S_DELETEROW 332
#define S_YANKROW 333
#define S_PULL 334
#define S_PULLMERGE 335
#define S_PULLROWS 336
#define S_PULLCOLS 337
#define S_PULLXCHG 338
#define S_PULLTP 339
#define S_PULLFMT 340
#define S_PULLCOPY 341
#define S_WHEREAMI 342
#define S_GETNUM 343
#define S_FGETNUM 344
#define S_GETSTRING 345
#define S_GETEXP 346
#define S_GETFMT 347
#define S_GETFRAME 348
#define S_GETRANGE 349
#define S_EVAL 350
#define S_SEVAL 351
#define S_QUERY 352
#define S_GETKEY 353
#define S_ERROR 354
#define S_RECALC 355
#define S_REDRAW 356
#define S_QUIT 357
#define S_STATUS 358
#define S_RUN 359
#define S_PLUGIN 360
#define S_PLUGOUT 361
#define K_ERROR 362
#define K_INVALID 363
#define K_FIXED 364
#define K_SUM 365
#define K_PROD 366
#define K_AVG 367
#define K_STDDEV 368
#define K_COUNT 369
#define K_ROWS 370
#define K_COLS 371
#define K_ABS 372
#define K_ACOS 373
#define K_ASIN 374
#define K_ATAN 375
#define K_ATAN2 376
#define K_CEIL 377
#define K_COS 378
#define K_EXP 379
#define K_FABS 380
#define K_FLOOR 381
#define K_HYPOT 382
#define K_LN 383
#define K_LOG 384
#define K_PI 385
#define K_POW 386
#define K_SIN 387
#define K_SQRT 388
#define K_TAN 389
#define K_DTR 390
#define K_RTD 391
#define K_MAX 392
#define K_MIN 393
#define K_RND 394
#define K_ROUND 395
#define K_IF 396
#define K_PV 397
#define K_FV 398
#define K_PMT 399
#define K_HOUR 400
#define K_MINUTE 401
#define K_SECOND 402
#define K_MONTH 403
#define K_DAY 404
#define K_YEAR 405
#define K_NOW 406
#define K_DATE 407
#define K_DTS 408
#define K_TTS 409
#define K_FMT 410
#define K_SUBSTR 411
#define K_UPPER 412
#define K_LOWER 413
#define K_CAPITAL 414
#define K_STON 415
#define K_EQS 416
#define K_EXT 417
#define K_LUA 418
#define K_NVAL 419
#define K_SVAL 420
#define K_LOOKUP 421
#define K_HLOOKUP 422
#define K_VLOOKUP 423
#define K_INDEX 424
#define K_STINDEX 425
#define K_AUTO 426
#define K_AUTOCALC 427
#define K_AUTOINSERT 428
#define K_AUTOWRAP 429
#define K_CSLOP 430
#define K_BYROWS 431
#define K_BYCOLS 432
#define K_OPTIMIZE 433
#define K_ITERATIONS 434
#define K_NUMERIC 435
#define K_PRESCALE 436
#define K_EXTFUN 437
#define K_CELLCUR 438
#define K_TOPROW 439
#define K_COLOR 440
#define K_COLORNEG 441
#define K_COLORERR 442
#define K_BRAILLE 443
#define K_BLACK 444
#define K_RED 445
#define K_GREEN 446
#define K_YELLOW 447
#define K_BLUE 448
#define K_MAGENTA 449
#define K_CYAN 450
#define K_WHITE 451
#define K_TBLSTYLE 452
#define K_TBL 453
#define K_LATEX 454
#define K_SLATEX 455
#define K_TEX 456
#define K_FRAME 457
#define K_RNDTOEVEN 458
#define K_FILENAME 459
#define K_MYROW 460
#define K_MYCOL 461
#define K_LASTROW 462
#define K_LASTCOL 463
#define K_COLTOA 464
#define K_CRACTION 465
#define K_CRROW 466
#define K_CRCOL 467
#define K_ROWLIMIT 468
#define K_COLLIMIT 469
#define K_PAGESIZE 470
#define K_NUMITER 471
#define K_ERR 472
#define K_SCRC 473
#define K_LOCALE 474

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 33 "gram.y" /* yacc.c:355  */

    int ival;
    double fval;
    struct ent_ptr ent;
    struct enode *enode;
    char *sval;
    struct range_s rval;

#line 569 "gram.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAM_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 584 "gram.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  240
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2939

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  243
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  425
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  897

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   474

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   228,     2,   231,   242,   234,   224,     2,
     237,   238,   232,   229,   239,   230,   240,   233,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   222,   220,
     225,   226,   227,   221,   236,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   235,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   223,     2,   241,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   289,   289,   291,   304,   306,   308,   310,   313,   317,
     320,   324,   327,   331,   346,   355,   356,   362,   364,   366,
     368,   370,   383,   390,   396,   400,   405,   417,   418,   419,
     421,   422,   424,   426,   427,   432,   434,   438,   443,   447,
     450,   452,   454,   458,   460,   463,   465,   467,   471,   473,
     474,   476,   496,   497,   510,   511,   525,   534,   536,   539,
     541,   543,   545,   546,   548,   549,   551,   555,   557,   559,
     560,   562,   564,   566,   568,   570,   572,   576,   579,   583,
     585,   586,   590,   594,   598,   600,   602,   604,   605,   607,
     617,   618,   619,   620,   621,   622,   623,   626,   643,   658,
     661,   668,   671,   678,   681,   688,   691,   698,   700,   707,
     711,   712,   714,   715,   716,   717,   718,   719,   720,   721,
     722,   723,   724,   725,   726,   727,   738,   739,   740,   741,
     742,   743,   744,   745,   746,   758,   759,   764,   778,   790,
     795,   796,   809,   821,   822,   827,   839,   851,   856,   857,
     868,   869,   870,   871,   872,   873,   874,   875,   876,   878,
     884,   890,   894,   899,   901,   903,   907,   912,   914,   916,
     921,   926,   928,   930,   934,   939,   941,   943,   944,   946,
     947,   948,   952,   957,   959,   961,   962,   963,   964,   966,
     968,   970,   973,   974,   975,   977,   978,   980,   981,   982,
     983,   984,   985,   986,   990,   998,   999,  1009,  1011,  1013,
    1017,  1018,  1020,  1021,  1022,  1024,  1027,  1030,  1033,  1036,
    1039,  1042,  1045,  1048,  1051,  1054,  1057,  1060,  1062,  1065,
    1068,  1070,  1072,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1097,  1098,  1099,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1110,  1114,  1116,  1117,
    1118,  1119,  1120,  1121,  1122,  1123,  1124,  1126,  1128,  1131,
    1133,  1135,  1138,  1141,  1144,  1147,  1149,  1151,  1154,  1155,
    1156,  1157,  1158,  1160,  1161,  1162,  1163,  1164,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1189,
    1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1210,  1211,
    1214,  1215,  1218,  1219,  1221,  1223,  1225,  1228,  1229,  1232,
    1233,  1234,  1235,  1238,  1239,  1251,  1252,  1256,  1257,  1258,
    1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,
    1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,
    1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,
    1289,  1290,  1291,  1298,  1304,  1310,  1311,  1312,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1354,  1359,  1367,  1371,  1373,  1377
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "NUMBER", "FNUMBER", "RANGE",
  "VAR", "WORD", "PLUGIN", "COL", "S_SHOW", "S_HIDE", "S_INSERTCOL",
  "S_OPENCOL", "S_DELETECOL", "S_YANKCOL", "S_GETFORMAT", "S_FORMAT",
  "S_FMT", "S_LET", "S_LABEL", "S_LEFTSTRING", "S_RIGHTSTRING",
  "S_LEFTJUSTIFY", "S_RIGHTJUSTIFY", "S_CENTER", "S_COLOR", "S_ADDNOTE",
  "S_DELNOTE", "S_GET", "S_PUT", "S_MERGE", "S_WRITE", "S_TBL", "S_COPY",
  "S_MOVE", "S_ERASE", "S_YANK", "S_FILL", "S_SORT", "S_LOCK", "S_UNLOCK",
  "S_GOTO", "S_DEFINE", "S_UNDEFINE", "S_ABBREV", "S_UNABBREV", "S_FRAME",
  "S_FRAMETOP", "S_FRAMEBOTTOM", "S_FRAMELEFT", "S_FRAMERIGHT",
  "S_UNFRAME", "S_VALUE", "S_MDIR", "S_AUTORUN", "S_FKEY", "S_SCEXT",
  "S_ASCEXT", "S_TBL0EXT", "S_TBLEXT", "S_LATEXEXT", "S_SLATEXEXT",
  "S_TEXEXT", "S_SET", "S_UP", "S_DOWN", "S_LEFT", "S_RIGHT", "S_ENDUP",
  "S_ENDDOWN", "S_ENDLEFT", "S_ENDRIGHT", "S_SELECT", "S_INSERTROW",
  "S_OPENROW", "S_DELETEROW", "S_YANKROW", "S_PULL", "S_PULLMERGE",
  "S_PULLROWS", "S_PULLCOLS", "S_PULLXCHG", "S_PULLTP", "S_PULLFMT",
  "S_PULLCOPY", "S_WHEREAMI", "S_GETNUM", "S_FGETNUM", "S_GETSTRING",
  "S_GETEXP", "S_GETFMT", "S_GETFRAME", "S_GETRANGE", "S_EVAL", "S_SEVAL",
  "S_QUERY", "S_GETKEY", "S_ERROR", "S_RECALC", "S_REDRAW", "S_QUIT",
  "S_STATUS", "S_RUN", "S_PLUGIN", "S_PLUGOUT", "K_ERROR", "K_INVALID",
  "K_FIXED", "K_SUM", "K_PROD", "K_AVG", "K_STDDEV", "K_COUNT", "K_ROWS",
  "K_COLS", "K_ABS", "K_ACOS", "K_ASIN", "K_ATAN", "K_ATAN2", "K_CEIL",
  "K_COS", "K_EXP", "K_FABS", "K_FLOOR", "K_HYPOT", "K_LN", "K_LOG",
  "K_PI", "K_POW", "K_SIN", "K_SQRT", "K_TAN", "K_DTR", "K_RTD", "K_MAX",
  "K_MIN", "K_RND", "K_ROUND", "K_IF", "K_PV", "K_FV", "K_PMT", "K_HOUR",
  "K_MINUTE", "K_SECOND", "K_MONTH", "K_DAY", "K_YEAR", "K_NOW", "K_DATE",
  "K_DTS", "K_TTS", "K_FMT", "K_SUBSTR", "K_UPPER", "K_LOWER", "K_CAPITAL",
  "K_STON", "K_EQS", "K_EXT", "K_LUA", "K_NVAL", "K_SVAL", "K_LOOKUP",
  "K_HLOOKUP", "K_VLOOKUP", "K_INDEX", "K_STINDEX", "K_AUTO", "K_AUTOCALC",
  "K_AUTOINSERT", "K_AUTOWRAP", "K_CSLOP", "K_BYROWS", "K_BYCOLS",
  "K_OPTIMIZE", "K_ITERATIONS", "K_NUMERIC", "K_PRESCALE", "K_EXTFUN",
  "K_CELLCUR", "K_TOPROW", "K_COLOR", "K_COLORNEG", "K_COLORERR",
  "K_BRAILLE", "K_BLACK", "K_RED", "K_GREEN", "K_YELLOW", "K_BLUE",
  "K_MAGENTA", "K_CYAN", "K_WHITE", "K_TBLSTYLE", "K_TBL", "K_LATEX",
  "K_SLATEX", "K_TEX", "K_FRAME", "K_RNDTOEVEN", "K_FILENAME", "K_MYROW",
  "K_MYCOL", "K_LASTROW", "K_LASTCOL", "K_COLTOA", "K_CRACTION", "K_CRROW",
  "K_CRCOL", "K_ROWLIMIT", "K_COLLIMIT", "K_PAGESIZE", "K_NUMITER",
  "K_ERR", "K_SCRC", "K_LOCALE", "';'", "'?'", "':'", "'|'", "'&'", "'<'",
  "'='", "'>'", "'!'", "'+'", "'-'", "'#'", "'*'", "'/'", "'%'", "'^'",
  "'@'", "'('", "')'", "','", "'.'", "'~'", "'$'", "$accept", "command",
  "term", "e", "expr_list", "range", "var", "var_or_range", "num",
  "strarg", "setlist", "setitem", "errlist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
      59,    63,    58,   124,    38,    60,    61,    62,    33,    43,
      45,    35,    42,    47,    37,    94,    64,    40,    41,    44,
      46,   126,    36
};
# endif

#define YYPACT_NINF -196

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-196)))

#define YYTABLE_NINF -349

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-349)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1168,  -196,  -196,   103,   104,  -184,  -169,    12,    72,    33,
     106,   198,   198,   198,   198,   198,   198,   198,   198,     8,
     121,   121,    99,    28,    99,    59,    99,   198,   121,   198,
     198,   198,   198,   198,   198,    46,    99,   198,    81,    90,
     198,   119,   129,   155,   160,   198,   198,    99,    99,    73,
      99,    99,    99,    99,    99,    99,    99,  -196,    91,   111,
     117,   120,  -196,  -196,  -196,  -196,   131,  -129,  -100,    74,
      76,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   198,   -80,
      84,   178,   184,   186,   193,   -72,   165,   153,   153,    29,
    -196,   166,  -196,  -196,  -196,   -51,   170,   179,   192,   187,
     -33,   -24,   -16,   -15,   206,   208,    -9,   210,  -196,    -5,
     214,    -2,   221,     0,    63,  -196,  -196,    13,   217,  -196,
       7,   227,    15,    19,    23,    25,  -196,  -196,  -196,    27,
     254,     7,   198,  -196,  -196,  -196,  -196,   198,    35,    36,
       7,   198,  -196,  -196,  -196,   198,   198,   198,   198,  -196,
    -196,   100,    99,  -196,  -196,   198,  -196,  -196,  -196,   198,
     198,   100,   100,   228,   269,   198,   198,  -196,   198,  -196,
    -196,  -196,   198,  -196,   277,  -196,   282,  -196,   283,  -196,
     285,  -196,  -196,  -196,  -196,    66,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,   376,  -196,  -196,  -196,  -196,  -196,   290,
     293,    78,   294,    80,   299,  -196,   305,   309,    92,   310,
      93,   313,    98,   318,   102,   323,   105,   327,   109,  -196,
      95,  -196,  -196,   153,   153,   153,   843,   176,   153,  -196,
     302,  -196,   909,    34,   329,  -196,   332,  -196,   112,   123,
    -196,   333,   347,   354,   349,  -196,  -196,   350,  -196,   352,
    -196,   360,  -196,   369,   370,   363,  -196,   371,    22,   121,
    -196,   153,   153,   153,   153,   153,  -196,  -196,  -196,   198,
     198,  -196,  -196,  -196,  -196,  -196,   100,  -196,  -196,  -196,
    -196,  -196,  -196,   198,   198,  -196,  -196,  -196,     7,  -196,
    -196,  -196,  -196,  -196,    99,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,   150,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,   151,  -196,   152,   154,   158,   159,  -196,
    -196,   529,   553,  -196,  -196,  -196,   375,  -196,   382,  -196,
    -196,  -196,   383,  -196,   388,  -196,   392,  -196,   394,  -196,
     395,  -196,   396,   399,  -196,  -196,  -196,   153,   171,   173,
     174,   177,   182,   185,   188,   190,   194,   195,   196,   197,
     199,   200,   201,   202,   204,   205,   207,   262,  -196,   263,
     264,   265,   266,   267,   268,   272,   274,   276,   287,   301,
     303,   306,   307,   308,   328,   330,   331,   334,   335,  -196,
     337,   338,   339,   340,   341,   343,   351,   355,   356,   359,
     361,   362,   364,   365,   366,   368,   372,   373,   374,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,   377,  -196,  -196,
    -196,  -196,   378,  -196,  -196,   958,  1678,  -196,   220,   153,
     153,   153,   153,     6,   153,    37,   189,   153,   153,   153,
     153,   153,   153,   153,   291,   417,  -196,  -196,   420,   421,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   425,   426,
    -196,  -196,   535,  -196,   909,   909,   909,   909,   909,  -196,
    -196,  -196,  -196,  -196,  -196,   542,   167,   562,   565,   566,
     583,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,   357,  -196,   198,   198,   198,   198,   198,
     198,   198,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,    54,    54,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,    54,
      54,    54,    54,    54,   153,   153,    82,  -196,   596,   909,
     794,  2682,  2693,   153,   153,  2704,  2704,   153,  2704,   153,
       5,     5,     5,   381,   381,   381,  -196,   602,  -196,  -196,
    -196,  -196,   608,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,   609,   380,   384,   385,   387,
     390,   389,   401,   393,   402,   405,   406,   407,  1694,  1710,
    1726,  1742,  1086,  1758,  1774,  1790,  1806,  1822,  1106,  1838,
    1854,  1136,  1870,  1886,  1902,  1918,  1934,  1153,   408,  -183,
     411,  1170,   413,   412,  1950,  1187,  1204,  1221,  1238,  1255,
    1966,  1982,  1998,  2014,  2030,  2046,   637,  1272,  1289,  1306,
    1338,  2062,  2078,  2094,  2110,  1355,  1372,  1389,  1406,  1423,
    1440,   414,     7,  1457,   415,  1474,   416,  1491,   418,  1508,
     423,  2126,  2142,   153,  -196,   153,  2704,  2704,  2704,  2704,
    -196,   616,  -196,   153,  -196,   153,  -196,   153,  -196,   153,
    -196,   153,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   153,
    -196,  -196,  -196,  -196,  -196,   153,  -196,  -196,   153,  -196,
    -196,  -196,  -196,  -196,   153,   153,  -196,   153,   153,  -196,
    -196,   153,   153,   153,   153,   153,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,   153,   153,   153,   153,   153,  -196,  -196,
    -196,  -196,   153,   153,   153,   153,   153,   198,   153,   198,
     153,   198,   153,   198,   153,   198,   153,  -196,  -196,  -196,
    2670,  -196,  2158,  2174,  2190,  2206,  2222,  2238,  2254,  2270,
     909,  -193,  2286,  -127,  2302,  2318,  1525,  1542,  1559,  1576,
    2334,  1593,  1610,  2350,  1627,  2366,  2382,  2398,  2414,  2430,
     422,  2446,   424,  1644,   430,  1661,   432,   657,   433,  1055,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   153,
    -196,  -196,  -196,  -196,   153,   153,   153,   153,  -196,   153,
     153,  -196,   153,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
     153,   153,   153,   153,  -196,  -196,   153,  -196,  -196,   153,
     909,  2462,  2478,  2494,  2510,  2526,  2542,  2558,  2574,  2590,
    2606,  2622,  2638,  2654,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   211,   209,     0,    51,   130,   132,   138,   146,   179,
       0,     0,     0,     0,     0,     0,     8,    10,    12,     0,
       0,    16,     0,    41,     0,    46,     0,    56,     0,    61,
      63,     0,    68,    72,    74,    87,     0,     0,    94,     0,
      98,     0,     0,     0,     0,   108,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   355,   113,   115,
     117,   119,   121,   122,   123,   124,     0,   126,   128,   134,
     142,   150,   151,   152,   153,   154,   155,   156,   157,   159,
     163,   167,   171,   175,   183,   185,     0,     0,     0,   197,
     199,     0,   203,   204,   205,   201,     0,     0,     0,     0,
       0,     0,    54,    52,     0,     0,   139,     0,   147,     0,
       0,   177,     0,     0,     0,   341,   346,     0,     0,   347,
     348,     0,     0,     0,     0,     0,     7,     9,    11,     0,
       0,     0,    13,    15,   353,   354,    22,     0,    40,    36,
     354,    35,    23,    45,    44,    43,    48,    57,    59,    62,
      64,     0,    69,    73,    75,    84,   349,   350,    88,   423,
     425,     0,     0,     0,     0,    77,    79,    80,    89,    92,
      93,    95,    97,   100,     0,   102,     0,   104,     0,   106,
       0,   107,    66,    24,    25,     0,    27,    28,    29,    30,
      31,    32,    33,   112,   114,   116,   118,   120,   125,     0,
       0,   136,     0,   144,     0,   158,     0,     0,   161,     0,
     165,     0,   169,     0,   173,     0,   181,     0,   187,   299,
     296,   297,   310,     0,     0,     0,     0,     0,     0,   325,
     189,   212,   192,   195,     0,   200,     0,   206,     0,     0,
       1,     0,     0,     0,     0,   131,   133,     0,   140,     0,
     148,     0,   180,     0,     0,     0,   342,     0,     0,     0,
      71,     3,     0,     0,     0,   109,   111,    14,    39,     0,
       0,    34,    42,    47,    58,    60,     0,    70,    81,   422,
     424,   352,   351,    85,    86,    76,    78,    90,    91,    96,
      99,   101,   103,   105,     0,   357,   358,   383,   386,   389,
     364,   363,   365,     0,   368,   371,   374,   377,   380,   392,
     395,   398,   401,     0,   411,     0,     0,     0,     0,   418,
     419,     0,     0,   356,   127,   129,     0,   135,     0,   143,
     160,   164,     0,   168,     0,   172,     0,   176,     0,   184,
       0,   186,     0,     0,   301,   294,   295,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   311,
     312,   313,   314,   315,   316,   317,   318,     0,   303,   304,
     305,   306,     0,   308,   309,     0,     0,   300,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   193,     0,   198,   202,     0,     0,
      50,    49,    55,    53,   141,   149,   178,    21,    20,     0,
     344,   343,     0,   340,     2,     4,     5,     6,   110,    38,
      37,    67,    82,    83,    26,     0,     0,     0,     0,     0,
       0,   361,   362,   385,   388,   391,   367,   370,   373,   376,
     379,   382,   393,   396,   399,   402,   412,   420,   359,   360,
     384,   387,   390,   366,   369,   372,   375,   378,   381,   394,
     397,   400,   403,   413,   421,   137,   145,   162,   166,   170,
     174,   182,   188,     0,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     0,   327,
       0,   332,   331,     0,     0,   328,   329,     0,   330,     0,
     319,   320,   337,   321,   322,   323,   324,     0,   196,   207,
     208,    18,     0,   345,   404,   405,   406,   407,   408,   409,
     410,   414,   415,   416,   417,     0,   347,     0,   347,     0,
     347,     0,   347,     0,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   212,
       0,     0,   347,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,     0,   333,   335,   336,   334,
     194,    19,   266,     0,   215,     0,   217,     0,   219,     0,
     221,     0,   223,   231,   232,   233,   234,   235,   236,     0,
     238,   239,   240,   241,   242,     0,   244,   245,     0,   247,
     248,   249,   250,   251,     0,     0,   225,     0,     0,   228,
     252,     0,     0,     0,     0,     0,   258,   259,   260,   261,
     262,   263,   270,     0,     0,     0,     0,     0,   273,   274,
     275,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   302,   307,   214,
     326,    17,     0,     0,     0,     0,     0,     0,     0,     0,
     338,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   218,   220,   222,   224,   237,   243,   246,   227,     0,
     226,   230,   229,   253,     0,     0,     0,     0,   271,     0,
       0,   272,     0,   269,   288,   289,   290,   291,   280,   279,
       0,     0,     0,     0,   277,   276,     0,   286,   285,     0,
     339,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   255,   256,   257,   265,   267,
     292,   282,   281,   284,   283,   278,   287
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -195,   -87,  -126,    56,   772,   -10,    58,    94,
    -196,  -196,  -196
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    99,   229,   800,   801,   119,   231,   121,   166,   136,
     193,   323,   167
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     230,   232,   122,   123,   124,   125,   126,   127,   128,   219,
     220,   221,   129,   116,   115,   116,   117,   256,   117,   149,
     150,   151,   106,   153,   154,   165,   461,   169,   344,   345,
     346,   134,   233,   427,   115,   116,   182,   444,   117,   259,
     219,   220,   221,   111,   116,   838,   839,   117,   104,   155,
     156,   157,   115,   116,   158,  -348,   117,   219,   220,   221,
     115,   116,   134,   105,   117,   115,   116,   254,   205,   117,
     208,   210,   212,   214,   216,   130,   108,   185,   201,   139,
     203,   144,   109,   147,   170,   219,   220,   221,   152,   116,
     115,   116,   117,   171,   117,   194,   172,   174,   176,   178,
     180,   181,   134,   199,   156,   157,   116,   100,   102,   117,
     113,   841,   839,   101,   103,   195,   114,   141,   142,   145,
     146,   196,   267,   173,   197,   115,   116,   268,   116,   117,
     168,   117,   200,   175,   198,   115,   116,   274,   275,   117,
     426,   183,   184,   206,   186,   187,   188,   189,   190,   191,
     192,   217,   524,   159,   160,   285,   219,   220,   221,   177,
     116,   115,   116,   117,   179,   117,   115,   116,   218,   235,
     117,   615,   236,   237,   464,   465,   466,   467,   468,   219,
     220,   221,   238,   116,   115,   116,   117,   240,   117,   241,
     115,   116,   115,   116,   117,   239,   117,   271,   242,   115,
     116,   272,   273,   117,   115,   116,   243,   244,   117,   276,
     245,   278,   246,   247,   248,   279,   280,   249,   250,   281,
     282,   251,   286,   222,   287,   252,   253,   258,   289,   259,
     260,   283,   593,   594,   223,   224,   225,   440,   441,   442,
     443,   261,   226,   227,   107,   262,   277,   228,   118,   263,
     118,   264,   234,   265,   222,   257,   112,   445,   266,   469,
     470,   137,   138,   597,   462,   223,   224,   225,   269,   270,
     118,   222,   284,   226,   227,   161,   162,   163,   228,   118,
     164,   290,   223,   224,   225,   255,   291,   292,   118,   293,
     226,   227,   294,   143,   324,   228,   118,   325,   327,   222,
     326,   118,   328,   329,   110,   428,   202,   207,   204,   330,
     223,   224,   225,   331,   333,   332,   334,   335,   226,   227,
     703,   336,   337,   228,   118,   338,   118,   339,   340,   161,
     162,   341,   342,   446,   471,   343,   447,   450,   448,   472,
     473,   118,   589,   590,   591,   592,   595,   596,   598,   449,
     600,   601,   602,   603,   604,   605,   606,   451,   452,   453,
     454,   118,   455,   118,   456,   616,   617,   618,   619,   620,
     222,   118,   457,   459,   458,   460,   475,   476,   477,   515,
     478,   223,   224,   225,   479,   480,   516,   517,   474,   226,
     227,   524,   518,   222,   228,   118,   519,   118,   520,   521,
     522,   209,   118,   523,   223,   224,   225,   211,   525,   213,
     526,   527,   425,   227,   528,   599,   215,   228,   118,   529,
     118,   608,   530,   609,   610,   531,   118,   532,   118,   611,
     612,   533,   534,   535,   536,   118,   537,   538,   539,   540,
     118,   541,   542,   588,   543,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   661,   664,   665,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   693,   695,   697,   699,   701,   702,   544,
     545,   546,   547,   548,   549,   550,   706,   707,   789,   551,
     708,   552,   709,   553,   607,   627,   629,   631,   633,   635,
     636,   637,   429,   430,   554,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   555,   613,
     556,   660,   663,   557,   558,   559,   614,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   560,   621,   561,   562,   622,
     623,   563,   564,   313,   565,   566,   567,   568,   569,   314,
     570,   626,   628,   630,   632,   634,   315,   624,   571,   316,
     317,   318,   572,   573,   319,   320,   574,   625,   575,   576,
     704,   577,   578,   579,   321,   580,   710,   658,   662,   581,
     582,   583,   711,   712,   584,   585,   443,   322,   790,   713,
     791,   803,   714,     0,   715,   716,   792,   718,   793,   717,
     794,   720,   795,     0,   796,   691,   694,   696,   698,   700,
     719,   721,   797,   722,   723,   724,     0,   745,   798,   746,
     749,   799,   748,   778,   780,   782,     0,   784,   802,     0,
     858,   804,   786,   860,   805,   806,   807,   808,   809,   862,
     864,   867,     0,     0,     0,     0,   810,   811,   812,   813,
     814,     0,     0,     0,     0,   815,   816,   817,   818,   819,
       0,   821,     0,   823,     0,   825,     0,   827,     0,   829,
     481,   482,   483,   484,   485,     0,     0,   486,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,     0,     0,   498,   499,   500,   501,   502,     0,
       0,   503,   496,   504,   505,   506,   507,   508,   509,   510,
     511,   512,     0,     0,     0,     0,     0,     0,   497,     0,
       0,     0,   870,     0,     0,     0,   513,   871,   872,   873,
     874,     0,   875,   876,     0,   877,     0,     0,     0,     0,
       0,     0,   514,   878,   879,   880,   881,     0,     0,   882,
       0,     0,   883,   120,   120,   120,   120,   120,   120,   120,
     120,   131,   132,   133,   135,   140,   135,   140,   135,   131,
     148,   120,   120,   120,   131,   120,   120,   120,   135,   120,
       0,     0,   131,   131,   131,   131,   131,   131,   120,   135,
     135,     0,   135,   135,   135,   135,   135,   135,   135,     0,
       0,     0,     0,   820,     0,   822,     0,   824,     0,   826,
       0,   828,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,   120,   120,   120,   120,   120,   429,   430,     0,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,     0,     0,   762,   763,   429,   430,     0,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,     0,     0,   865,   866,     0,     0,     0,
       0,     0,     0,     0,   120,     0,     0,     0,     0,   120,
       0,     0,     0,   131,     0,     0,     0,   131,   131,   120,
     120,     0,     0,     0,   135,     0,     0,   131,     0,     0,
       0,   131,   131,     0,     0,     0,     0,   120,   131,     0,
     288,     0,     0,     0,   131,     0,     0,     0,     0,     0,
       0,     0,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   429,   430,   705,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
       0,   463,   409,   410,   411,   412,   413,   414,   415,   416,
       0,   120,   120,     0,     0,     0,     0,   417,   418,   419,
     420,   421,   422,     0,     0,   131,   131,     0,     0,   423,
     424,     0,     0,     0,     0,     0,   135,   586,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   429,
     430,     0,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,     0,     0,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,     0,
       0,     0,   417,   418,   419,   420,   421,   422,  -210,     1,
       0,     0,     0,     0,   423,   424,     0,     2,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   429,   430,     0,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,     0,     0,   868,   869,     0,     0,   120,   120,   120,
     120,   120,   120,   120,     0,     0,   429,   430,     0,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,     0,   659,   659,   729,   429,   430,     0,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,     0,     0,     0,   735,     0,     0,     0,     0,
       0,   692,   692,   692,   692,   692,   429,   430,     0,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,     0,   429,   430,   738,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,     0,
     429,   430,   744,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,     0,   429,   430,   747,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,     0,   429,   430,   751,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
       0,   429,   430,   752,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,     0,   429,   430,
     753,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,     0,   429,   430,   754,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,     0,   429,   430,   755,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,     0,   429,
     430,   764,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,     0,   429,   430,   765,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,     0,     0,     0,   766,     0,     0,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,   429,   430,
       0,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,     0,   429,   430,   767,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,     0,   429,   430,   772,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,     0,   429,
     430,   773,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,     0,   429,   430,   774,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,     0,   429,   430,   775,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,     0,
     429,   430,   776,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,     0,   429,   430,   777,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,     0,   429,   430,   779,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
       0,   429,   430,   781,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,     0,   429,   430,
     783,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,     0,   429,   430,   785,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,     0,   429,   430,   844,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,     0,   429,
     430,   845,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,     0,   429,   430,   846,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,     0,   429,   430,   847,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,     0,
     429,   430,   849,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,     0,   429,   430,   850,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,     0,   429,   430,   852,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
       0,   429,   430,   861,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,     0,   429,   430,
     863,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   587,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   725,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   726,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   727,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     728,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   730,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   731,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   732,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   733,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     734,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   736,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   737,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   739,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   740,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     741,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   742,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   743,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   750,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   756,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     757,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   758,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   759,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   760,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   761,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     768,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   769,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   770,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   771,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   787,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     788,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   830,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   831,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   832,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   833,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     834,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   835,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   836,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   837,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   840,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     842,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   843,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   848,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   851,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   853,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     854,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   855,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   856,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   857,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   859,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     884,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   885,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   886,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   887,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   888,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     889,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   890,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     429,   430,   891,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   429,   430,   892,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   429,   430,   893,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   429,   430,
     894,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   429,   430,   895,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
       0,     0,   896,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,  -349,
    -349,  -349,  -349,   437,   438,   439,   440,   441,   442,   443
};

static const yytype_int16 yycheck[] =
{
      87,    88,    12,    13,    14,    15,    16,    17,    18,     3,
       4,     5,     4,     7,     6,     7,    10,     4,    10,    29,
      30,    31,    10,    33,    34,    35,     4,    37,   223,   224,
     225,     3,     3,   228,     6,     7,    46,     3,    10,   222,
       3,     4,     5,    10,     7,   238,   239,    10,   232,     3,
       4,     5,     6,     7,     8,   238,    10,     3,     4,     5,
       6,     7,     3,   232,    10,     6,     7,     4,    78,    10,
      80,    81,    82,    83,    84,    19,     4,     4,     4,    23,
       4,    25,    10,    27,     3,     3,     4,     5,    32,     7,
       6,     7,    10,     3,    10,     4,    40,    41,    42,    43,
      44,    45,     3,   232,     4,     5,     7,     4,     4,    10,
       4,   238,   239,    10,    10,     4,    10,    23,    24,    25,
      26,     4,   132,     4,     4,     6,     7,   137,     7,    10,
      36,    10,   232,     4,     3,     6,     7,   147,   148,    10,
     227,    47,    48,   223,    50,    51,    52,    53,    54,    55,
      56,   223,   347,   107,   108,   165,     3,     4,     5,     4,
       7,     6,     7,    10,     4,    10,     6,     7,     3,     3,
      10,     4,   223,     3,   261,   262,   263,   264,   265,     3,
       4,     5,     3,     7,     6,     7,    10,     0,    10,   222,
       6,     7,     6,     7,    10,     3,    10,   141,   222,     6,
       7,   145,   146,    10,     6,     7,   222,   222,    10,   151,
       4,   155,     4,   222,     4,   159,   160,   222,     4,   161,
     162,   223,   166,   217,   168,     4,   226,    10,   172,   222,
       3,     3,   226,   227,   228,   229,   230,   232,   233,   234,
     235,   226,   236,   237,   232,   226,   152,   241,   242,   226,
     242,   226,   223,   226,   217,   242,   223,   223,     4,   269,
     270,   233,   234,   226,   242,   228,   229,   230,   233,   233,
     242,   217,     3,   236,   237,   229,   230,   231,   241,   242,
     234,     4,   228,   229,   230,   222,     4,     4,   242,     4,
     236,   237,   226,   234,     4,   241,   242,     4,     4,   217,
     222,   242,   222,     4,   232,     3,   232,   223,   232,     4,
     228,   229,   230,     4,     4,   223,   223,     4,   236,   237,
     238,   223,     4,   241,   242,   223,   242,     4,   223,   229,
     230,     4,   223,     4,   276,   240,     4,     4,   226,   283,
     284,   242,   429,   430,   431,   432,   433,   434,   435,   226,
     437,   438,   439,   440,   441,   442,   443,    10,     4,    10,
      10,   242,    10,   242,     4,   198,   199,   200,   201,   202,
     217,   242,     3,    10,     4,     4,   226,   226,   226,     4,
     226,   228,   229,   230,   226,   226,     4,     4,   294,   236,
     237,   586,     4,   217,   241,   242,     4,   242,     4,     4,
       4,   223,   242,     4,   228,   229,   230,   223,   237,   223,
     237,   237,   236,   237,   237,   226,   223,   241,   242,   237,
     242,     4,   237,     3,     3,   237,   242,   237,   242,     4,
       4,   237,   237,   237,   237,   242,   237,   237,   237,   237,
     242,   237,   237,   223,   237,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   237,
     237,   237,   237,   237,   237,   237,   593,   594,   703,   237,
     597,   237,   599,   237,   223,   525,   526,   527,   528,   529,
     530,   531,   220,   221,   237,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   237,     4,
     237,   551,   552,   237,   237,   237,     4,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   237,     4,   237,   237,     4,
       4,   237,   237,   197,   237,   237,   237,   237,   237,   203,
     237,   525,   526,   527,   528,   529,   210,     4,   237,   213,
     214,   215,   237,   237,   218,   219,   237,   240,   237,   237,
       4,   237,   237,   237,   228,   237,     4,   551,   552,   237,
     237,   237,     4,     4,   237,   237,   235,   241,   705,   239,
       4,   747,   238,    -1,   239,   238,   713,   238,   715,   239,
     717,   238,   719,    -1,   721,   579,   580,   581,   582,   583,
     239,   239,   729,   238,   238,   238,    -1,   239,   735,   238,
     238,   738,   239,   239,   239,   239,    -1,   239,   745,    -1,
     238,   748,   239,   239,   751,   752,   753,   754,   755,   239,
     238,   238,    -1,    -1,    -1,    -1,   763,   764,   765,   766,
     767,    -1,    -1,    -1,    -1,   772,   773,   774,   775,   776,
      -1,   778,    -1,   780,    -1,   782,    -1,   784,    -1,   786,
     171,   172,   173,   174,   175,    -1,    -1,   178,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,   174,   175,    -1,
      -1,   178,   203,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,
      -1,    -1,   839,    -1,    -1,    -1,   203,   844,   845,   846,
     847,    -1,   849,   850,    -1,   852,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   860,   861,   862,   863,    -1,    -1,   866,
      -1,    -1,   869,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,   777,    -1,   779,    -1,   781,    -1,   783,
      -1,   785,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    83,    84,   220,   221,    -1,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,   238,   239,   220,   221,    -1,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,   238,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,   141,    -1,    -1,    -1,   145,   146,   147,
     148,    -1,    -1,    -1,   152,    -1,    -1,   155,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,    -1,
     168,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,   259,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,   269,   270,    -1,    -1,    -1,    -1,   204,   205,   206,
     207,   208,   209,    -1,    -1,   283,   284,    -1,    -1,   216,
     217,    -1,    -1,    -1,    -1,    -1,   294,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   220,
     221,    -1,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,     0,     1,
      -1,    -1,    -1,    -1,   216,   217,    -1,     9,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   220,   221,    -1,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,    -1,   238,   239,    -1,    -1,   525,   526,   527,
     528,   529,   530,   531,    -1,    -1,   220,   221,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,   551,   552,   239,   220,   221,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,   579,   580,   581,   582,   583,   220,   221,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,   220,   221,   239,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
     220,   221,   239,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,   220,   221,   239,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,   220,   221,   239,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,   220,   221,   239,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,   220,   221,
     239,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,   220,   221,   239,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,   220,   221,   239,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,   220,
     221,   239,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,   220,   221,   239,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,   239,    -1,    -1,    -1,   777,
      -1,   779,    -1,   781,    -1,   783,    -1,   785,   220,   221,
      -1,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,   220,   221,   239,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,   220,   221,   239,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,   220,
     221,   239,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,   220,   221,   239,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,   220,   221,   239,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
     220,   221,   239,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,   220,   221,   239,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,   220,   221,   239,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,   220,   221,   239,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,   220,   221,
     239,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,   220,   221,   239,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,    -1,   220,   221,   239,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,   220,
     221,   239,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,   220,   221,   239,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,   220,   221,   239,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
     220,   221,   239,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,   220,   221,   239,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,   220,   221,   239,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,   220,   221,   239,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,   220,   221,
     239,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     220,   221,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   220,   221,   238,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   221,   238,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   220,   221,
     238,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   220,   221,   238,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,   238,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   244,
       4,    10,     4,    10,   232,   232,    10,   232,     4,    10,
     232,    10,   223,     4,    10,     6,     7,    10,   242,   248,
     249,   250,   250,   250,   250,   250,   250,   250,   250,     4,
     248,   249,   249,   249,     3,   249,   252,   233,   234,   248,
     249,   252,   252,   234,   248,   252,   252,   248,   249,   250,
     250,   250,   248,   250,   250,     3,     4,     5,     8,   107,
     108,   229,   230,   231,   234,   250,   251,   255,   252,   250,
       3,     3,   248,     4,   248,     4,   248,     4,   248,     4,
     248,   248,   250,   252,   252,     4,   252,   252,   252,   252,
     252,   252,   252,   253,     4,     4,     4,     4,     3,   232,
     232,     4,   232,     4,   232,   250,   223,   223,   250,   223,
     250,   223,   250,   223,   250,   223,   250,   223,     3,     3,
       4,     5,   217,   228,   229,   230,   236,   237,   241,   245,
     246,   249,   246,     3,   223,     3,   223,     3,     3,     3,
       0,   222,   222,   222,   222,     4,     4,   222,     4,   222,
       4,   223,     4,   226,     4,   222,     4,   242,    10,   222,
       3,   226,   226,   226,   226,   226,     4,   250,   250,   233,
     233,   248,   248,   248,   250,   250,   251,   252,   248,   248,
     248,   251,   251,     3,     3,   250,   248,   248,   249,   248,
       4,     4,     4,     4,   226,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   197,   203,   210,   213,   214,   215,   218,
     219,   228,   241,   254,     4,     4,   222,     4,   222,     4,
       4,     4,   223,     4,   223,     4,   223,     4,   223,     4,
     223,     4,   223,   240,   245,   245,   245,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   189,
     190,   191,   192,   193,   194,   195,   196,   204,   205,   206,
     207,   208,   209,   216,   217,   236,   246,   245,     3,   220,
     221,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,     3,   223,     4,     4,   226,   226,
       4,    10,     4,    10,    10,    10,     4,     3,     4,    10,
       4,     4,   242,   249,   246,   246,   246,   246,   246,   250,
     250,   251,   248,   248,   252,   226,   226,   226,   226,   226,
     226,   171,   172,   173,   174,   175,   178,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   203,   219,   171,   172,
     173,   174,   175,   178,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   203,   219,     4,     4,     4,     4,     4,
       4,     4,     4,     4,   245,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   109,   238,   223,   246,
     246,   246,   246,   226,   227,   246,   246,   226,   246,   226,
     246,   246,   246,   246,   246,   246,   246,   223,     4,     3,
       3,     4,     4,     4,     4,     4,   198,   199,   200,   201,
     202,     4,     4,     4,     4,   240,   248,   250,   248,   250,
     248,   250,   248,   250,   248,   250,   250,   250,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   248,   249,
     250,   246,   248,   250,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   248,   249,   246,   248,   246,   248,   246,   248,   246,
     248,   246,   246,   238,     4,   222,   246,   246,   246,   246,
       4,     4,     4,   239,   238,   239,   238,   239,   238,   239,
     238,   239,   238,   238,   238,   238,   238,   238,   238,   239,
     238,   238,   238,   238,   238,   239,   238,   238,   239,   238,
     238,   238,   238,   238,   239,   239,   238,   239,   239,   238,
     238,   239,   239,   239,   239,   239,   238,   238,   238,   238,
     238,   238,   238,   239,   239,   239,   239,   239,   238,   238,
     238,   238,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   238,   238,   245,
     246,     4,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   247,   246,   247,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     248,   246,   248,   246,   248,   246,   248,   246,   248,   246,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   239,
     238,   238,   238,   238,   239,   239,   239,   239,   238,   239,
     239,   238,   239,   238,   238,   238,   238,   238,   238,   238,
     239,   239,   239,   239,   238,   238,   239,   238,   238,   239,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   243,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   247,   247,
     248,   248,   249,   249,   249,   249,   249,   250,   250,   251,
     251,   251,   251,   252,   252,   253,   253,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   255,   255,   255,   255
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     4,     4,     4,     2,     1,     2,
       1,     2,     1,     2,     3,     2,     1,     7,     5,     6,
       4,     4,     2,     2,     2,     2,     4,     2,     2,     2,
       2,     2,     2,     2,     3,     2,     2,     4,     4,     3,
       2,     1,     3,     2,     2,     2,     1,     3,     2,     4,
       4,     1,     2,     4,     2,     4,     1,     2,     3,     2,
       3,     1,     2,     1,     2,     1,     2,     4,     1,     2,
       3,     3,     1,     2,     1,     2,     3,     2,     3,     2,
       2,     3,     4,     4,     2,     3,     3,     1,     2,     2,
       3,     3,     2,     2,     1,     2,     3,     2,     1,     3,
       2,     3,     2,     3,     2,     3,     2,     2,     1,     3,
       4,     3,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     2,     4,     1,     2,
       3,     4,     1,     3,     2,     4,     1,     2,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     2,     4,     1,     3,     2,     4,     1,     3,     2,
       4,     1,     3,     2,     4,     1,     3,     2,     4,     1,
       3,     2,     4,     1,     3,     1,     3,     2,     4,     2,
       3,     5,     2,     3,     5,     2,     4,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     2,     4,     4,     1,
       0,     1,     1,     3,     5,     5,     7,     5,     7,     5,
       7,     5,     7,     5,     7,     5,     7,     7,     5,     7,
       7,     5,     5,     5,     5,     5,     5,     7,     5,     5,
       5,     5,     5,     7,     5,     5,     7,     5,     5,     5,
       5,     5,     5,     7,     9,     9,     9,     9,     5,     5,
       5,     5,     5,     5,     2,     9,     5,     9,     5,     7,
       5,     7,     7,     5,     5,     5,     7,     7,     9,     7,
       7,     9,     9,     9,     9,     7,     7,     9,     7,     7,
       7,     7,     9,     3,     2,     2,     1,     1,     2,     1,
       2,     2,     5,     2,     2,     2,     2,     5,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     1,     5,     3,     3,     3,
       3,     3,     3,     4,     4,     4,     4,     3,     1,     3,
       3,     1,     2,     3,     3,     4,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     0,     2,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     1,     2,     2,     1,     2,     2,
       1,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     2,     3,     3,     3,     3,     1,     1,
       2,     2,     2,     1,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 290 "gram.y" /* yacc.c:1646  */
    { let((yyvsp[-2].rval).left.vp, (yyvsp[0].enode)); }
#line 2715 "gram.c" /* yacc.c:1646  */
    break;

  case 3:
#line 292 "gram.y" /* yacc.c:1646  */
    { (yyvsp[-1].rval).left.vp->v = (double) 0.0;
				  if ((yyvsp[-1].rval).left.vp->expr &&
					!((yyvsp[-1].rval).left.vp->flags & is_strexpr)) {
				    efree((yyvsp[-1].rval).left.vp->expr);
				    (yyvsp[-1].rval).left.vp->expr = NULL;
				  }
				  (yyvsp[-1].rval).left.vp->cellerror = CELLOK;
				  (yyvsp[-1].rval).left.vp->flags &= ~is_valid;
				  (yyvsp[-1].rval).left.vp->flags |= is_changed;
				  changed++;
				  FullUpdate++;
				  modflg++; }
#line 2732 "gram.c" /* yacc.c:1646  */
    break;

  case 4:
#line 305 "gram.y" /* yacc.c:1646  */
    { slet((yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 0); }
#line 2738 "gram.c" /* yacc.c:1646  */
    break;

  case 5:
#line 307 "gram.y" /* yacc.c:1646  */
    { slet((yyvsp[-2].rval).left.vp, (yyvsp[0].enode), -1); }
#line 2744 "gram.c" /* yacc.c:1646  */
    break;

  case 6:
#line 309 "gram.y" /* yacc.c:1646  */
    { slet((yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 1); }
#line 2750 "gram.c" /* yacc.c:1646  */
    break;

  case 7:
#line 311 "gram.y" /* yacc.c:1646  */
    { ljustify((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
				    (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 2757 "gram.c" /* yacc.c:1646  */
    break;

  case 8:
#line 314 "gram.y" /* yacc.c:1646  */
    { if (showrange)
				    ljustify(showsr, showsc, currow, curcol);
				}
#line 2765 "gram.c" /* yacc.c:1646  */
    break;

  case 9:
#line 318 "gram.y" /* yacc.c:1646  */
    { rjustify((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
				    (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 2772 "gram.c" /* yacc.c:1646  */
    break;

  case 10:
#line 321 "gram.y" /* yacc.c:1646  */
    { if (showrange)
				    rjustify(showsr, showsc, currow, curcol);
				}
#line 2780 "gram.c" /* yacc.c:1646  */
    break;

  case 11:
#line 325 "gram.y" /* yacc.c:1646  */
    { center((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
				    (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 2787 "gram.c" /* yacc.c:1646  */
    break;

  case 12:
#line 328 "gram.y" /* yacc.c:1646  */
    { if (showrange)
				    center(showsr, showsc, currow, curcol);
				}
#line 2795 "gram.c" /* yacc.c:1646  */
    break;

  case 13:
#line 331 "gram.y" /* yacc.c:1646  */
    { if (showrange) {
				    (yyvsp[0].ent).vp->nrow=currow<showsr?currow:showsr;
				    (yyvsp[0].ent).vp->ncol=curcol<showsc?curcol:showsc;
				    (yyvsp[0].ent).vp->nlastrow=currow<showsr?showsr:currow;
				    (yyvsp[0].ent).vp->nlastcol=curcol<showsc?showsc:curcol;
				  } else {
				    (yyvsp[0].ent).vp->nrow=currow;
				    (yyvsp[0].ent).vp->ncol=curcol;
				    (yyvsp[0].ent).vp->nlastrow=currow;
				    (yyvsp[0].ent).vp->nlastcol=curcol;
				  }
				  (yyvsp[0].ent).vp->flags |= is_changed;
				  FullUpdate++;
				  modflg++;
				}
#line 2815 "gram.c" /* yacc.c:1646  */
    break;

  case 14:
#line 347 "gram.y" /* yacc.c:1646  */
    { (yyvsp[-1].ent).vp->nrow = (yyvsp[0].rval).left.vp->row;
				  (yyvsp[-1].ent).vp->ncol = (yyvsp[0].rval).left.vp->col;
				  (yyvsp[-1].ent).vp->nlastrow = (yyvsp[0].rval).right.vp->row;
				  (yyvsp[-1].ent).vp->nlastcol = (yyvsp[0].rval).right.vp->col;
				  (yyvsp[-1].ent).vp->flags |= is_changed;
				  FullUpdate++;
				  modflg++;
				}
#line 2828 "gram.c" /* yacc.c:1646  */
    break;

  case 15:
#line 355 "gram.y" /* yacc.c:1646  */
    { (yyvsp[0].ent).vp->nrow = (yyvsp[0].ent).vp->ncol = -1; }
#line 2834 "gram.c" /* yacc.c:1646  */
    break;

  case 16:
#line 356 "gram.y" /* yacc.c:1646  */
    { struct ent *p;
				  p = lookat(currow, curcol);
				  p->nrow = p->ncol = -1;
				  p->flags |= is_changed;
				  modflg++;
				}
#line 2845 "gram.c" /* yacc.c:1646  */
    break;

  case 17:
#line 363 "gram.y" /* yacc.c:1646  */
    { doformat((yyvsp[-5].ival),(yyvsp[-3].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival)); }
#line 2851 "gram.c" /* yacc.c:1646  */
    break;

  case 18:
#line 365 "gram.y" /* yacc.c:1646  */
    { doformat((yyvsp[-3].ival),(yyvsp[-3].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival)); }
#line 2857 "gram.c" /* yacc.c:1646  */
    break;

  case 19:
#line 367 "gram.y" /* yacc.c:1646  */
    { doformat((yyvsp[-4].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival), REFMTFIX); }
#line 2863 "gram.c" /* yacc.c:1646  */
    break;

  case 20:
#line 369 "gram.y" /* yacc.c:1646  */
    { doformat((yyvsp[-2].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival), REFMTFIX); }
#line 2869 "gram.c" /* yacc.c:1646  */
    break;

  case 21:
#line 371 "gram.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].ival) >= 0 && (yyvsp[-2].ival) < 10) {
				    if (colformat[(yyvsp[-2].ival)])
					scxfree(colformat[(yyvsp[-2].ival)]);
				    if (strlen((yyvsp[0].sval)))
					colformat[(yyvsp[-2].ival)] = (yyvsp[0].sval);
				    else
					colformat[(yyvsp[-2].ival)] = NULL;
				    FullUpdate++;
				    modflg++;
				  } else
				    error("Invalid format number");
				}
#line 2886 "gram.c" /* yacc.c:1646  */
    break;

  case 22:
#line 383 "gram.y" /* yacc.c:1646  */
    {  /* This tmp hack is because readfile
				    * recurses back through yyparse. */
				    char *tmp;
				    tmp = (yyvsp[0].sval);
				    readfile(tmp, 1);
				    scxfree(tmp);
				}
#line 2898 "gram.c" /* yacc.c:1646  */
    break;

  case 23:
#line 390 "gram.y" /* yacc.c:1646  */
    {
				    char *tmp;
				    tmp = (yyvsp[0].sval);
				    readfile(tmp, 0);
				    scxfree(tmp);
				}
#line 2909 "gram.c" /* yacc.c:1646  */
    break;

  case 24:
#line 396 "gram.y" /* yacc.c:1646  */
    { if (mdir) scxfree(mdir);
				  if (strlen((yyvsp[0].sval)))
				    mdir = (yyvsp[0].sval);
				  modflg++; }
#line 2918 "gram.c" /* yacc.c:1646  */
    break;

  case 25:
#line 401 "gram.y" /* yacc.c:1646  */
    { if (autorun) scxfree(autorun);
				  if (strlen((yyvsp[0].sval)))
				    autorun = (yyvsp[0].sval);
				  modflg++; }
#line 2927 "gram.c" /* yacc.c:1646  */
    break;

  case 26:
#line 406 "gram.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].ival) > 0 && (yyvsp[-2].ival) <= FKEYS) {
				    if (fkey[(yyvsp[-2].ival) - 1]) {
					scxfree(fkey[(yyvsp[-2].ival) - 1]);
					fkey[(yyvsp[-2].ival) - 1] = NULL;
				    }
				    if (strlen((yyvsp[0].sval)))
					fkey[(yyvsp[-2].ival) - 1] = (yyvsp[0].sval);
				    modflg++;
				  } else
				    error("Invalid function key");
				}
#line 2943 "gram.c" /* yacc.c:1646  */
    break;

  case 27:
#line 417 "gram.y" /* yacc.c:1646  */
    { if (scext) scxfree(scext); scext = (yyvsp[0].sval); }
#line 2949 "gram.c" /* yacc.c:1646  */
    break;

  case 28:
#line 418 "gram.y" /* yacc.c:1646  */
    { if (ascext) scxfree(ascext); ascext = (yyvsp[0].sval); }
#line 2955 "gram.c" /* yacc.c:1646  */
    break;

  case 29:
#line 420 "gram.y" /* yacc.c:1646  */
    { if (tbl0ext) scxfree(tbl0ext); tbl0ext = (yyvsp[0].sval); }
#line 2961 "gram.c" /* yacc.c:1646  */
    break;

  case 30:
#line 421 "gram.y" /* yacc.c:1646  */
    { if (tblext) scxfree(tblext); tblext = (yyvsp[0].sval); }
#line 2967 "gram.c" /* yacc.c:1646  */
    break;

  case 31:
#line 422 "gram.y" /* yacc.c:1646  */
    { if (latexext) scxfree(latexext);
					    latexext = (yyvsp[0].sval); }
#line 2974 "gram.c" /* yacc.c:1646  */
    break;

  case 32:
#line 424 "gram.y" /* yacc.c:1646  */
    { if (slatexext) scxfree(slatexext);
					    slatexext = (yyvsp[0].sval); }
#line 2981 "gram.c" /* yacc.c:1646  */
    break;

  case 33:
#line 426 "gram.y" /* yacc.c:1646  */
    { if (texext) scxfree(texext); texext = (yyvsp[0].sval); }
#line 2987 "gram.c" /* yacc.c:1646  */
    break;

  case 34:
#line 428 "gram.y" /* yacc.c:1646  */
    { (void) writefile((yyvsp[-1].sval), ((yyvsp[0].rval).left.vp)->row, 
					((yyvsp[0].rval).left.vp)->col, ((yyvsp[0].rval).right.vp)->row,
					((yyvsp[0].rval).right.vp)->col);
					    scxfree((yyvsp[-1].sval)); }
#line 2996 "gram.c" /* yacc.c:1646  */
    break;

  case 35:
#line 432 "gram.y" /* yacc.c:1646  */
    { (void) writefile((yyvsp[0].sval), 0, 0, maxrow, maxcol);
					    scxfree((yyvsp[0].sval)); }
#line 3003 "gram.c" /* yacc.c:1646  */
    break;

  case 36:
#line 434 "gram.y" /* yacc.c:1646  */
    { (void) write_cells(stdout,
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
					  (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col,
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col); }
#line 3012 "gram.c" /* yacc.c:1646  */
    break;

  case 37:
#line 439 "gram.y" /* yacc.c:1646  */
    { (void) write_cells(stdout,
					  (yyvsp[-2].rval).left.vp->row, (yyvsp[-2].rval).left.vp->col,
					  (yyvsp[-2].rval).right.vp->row, (yyvsp[-2].rval).right.vp->col,
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col); }
#line 3021 "gram.c" /* yacc.c:1646  */
    break;

  case 38:
#line 444 "gram.y" /* yacc.c:1646  */
    { (void) write_cells(stdout, 0, 0,
					  maxrow, maxcol,
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col); }
#line 3029 "gram.c" /* yacc.c:1646  */
    break;

  case 39:
#line 447 "gram.y" /* yacc.c:1646  */
    { (void) write_cells(stdout,
					  showsr, showsc, currow, curcol,
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col); }
#line 3037 "gram.c" /* yacc.c:1646  */
    break;

  case 40:
#line 450 "gram.y" /* yacc.c:1646  */
    { (void) write_cells(stdout, 0, 0,
					    maxrow, maxcol, 0, 0); }
#line 3044 "gram.c" /* yacc.c:1646  */
    break;

  case 41:
#line 452 "gram.y" /* yacc.c:1646  */
    { (void) write_cells(stdout, 0, 0,
					    maxrow, maxcol, 0, 0); }
#line 3051 "gram.c" /* yacc.c:1646  */
    break;

  case 42:
#line 454 "gram.y" /* yacc.c:1646  */
    { (void) printfile((yyvsp[-1].sval), ((yyvsp[0].rval).left.vp)->row, 
					((yyvsp[0].rval).left.vp)->col, ((yyvsp[0].rval).right.vp)->row,
					((yyvsp[0].rval).right.vp)->col);
					    scxfree((yyvsp[-1].sval)); }
#line 3060 "gram.c" /* yacc.c:1646  */
    break;

  case 43:
#line 458 "gram.y" /* yacc.c:1646  */
    { (void) printfile((yyvsp[0].sval), 0, 0, maxrow, maxcol);
					    scxfree((yyvsp[0].sval)); }
#line 3067 "gram.c" /* yacc.c:1646  */
    break;

  case 44:
#line 460 "gram.y" /* yacc.c:1646  */
    { (void) printfile(NULL,
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
					  (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3075 "gram.c" /* yacc.c:1646  */
    break;

  case 45:
#line 463 "gram.y" /* yacc.c:1646  */
    { (void) printfile(NULL, 0, 0,
					    maxrow, maxcol); }
#line 3082 "gram.c" /* yacc.c:1646  */
    break;

  case 46:
#line 465 "gram.y" /* yacc.c:1646  */
    { (void) printfile(NULL, 0, 0,
					    maxrow, maxcol); }
#line 3089 "gram.c" /* yacc.c:1646  */
    break;

  case 47:
#line 467 "gram.y" /* yacc.c:1646  */
    { (void) tblprintfile((yyvsp[-1].sval), ((yyvsp[0].rval).left.vp)->row, 
					((yyvsp[0].rval).left.vp)->col, ((yyvsp[0].rval).right.vp)->row,
					((yyvsp[0].rval).right.vp)->col);
					    scxfree((yyvsp[-1].sval)); }
#line 3098 "gram.c" /* yacc.c:1646  */
    break;

  case 48:
#line 471 "gram.y" /* yacc.c:1646  */
    { (void)tblprintfile((yyvsp[0].sval), 0, 0, maxrow, maxcol);
					    scxfree((yyvsp[0].sval)); }
#line 3105 "gram.c" /* yacc.c:1646  */
    break;

  case 49:
#line 473 "gram.y" /* yacc.c:1646  */
    { showcol((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 3111 "gram.c" /* yacc.c:1646  */
    break;

  case 50:
#line 475 "gram.y" /* yacc.c:1646  */
    { showrow((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 3117 "gram.c" /* yacc.c:1646  */
    break;

  case 51:
#line 476 "gram.y" /* yacc.c:1646  */
    { int arg;
	    				  if (showrange == SHOWROWS) {
					    if (showsr < currow) {
						int r = currow;
						currow = showsr;
						showsr = r;
					    }
					    arg = showsr - currow + 1;
					    hiderow(arg);
					  } else if (showrange == SHOWCOLS) {
					    if (showsc < curcol) {
						int c = curcol;
						curcol = showsc;
						showsc = c;
					    }
					    arg = showsc - curcol + 1;
					    hidecol(arg);
					  } else
					    arg = 1;
					}
#line 3142 "gram.c" /* yacc.c:1646  */
    break;

  case 52:
#line 496 "gram.y" /* yacc.c:1646  */
    { hide_col((yyvsp[0].ival)); }
#line 3148 "gram.c" /* yacc.c:1646  */
    break;

  case 53:
#line 497 "gram.y" /* yacc.c:1646  */
    { int c = curcol, arg;
					  if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
					    curcol = (yyvsp[-2].ival);
					    arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
					  } else {
					      curcol = (yyvsp[0].ival);
					      arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
					  }
					  hidecol(arg);
					  curcol = c < curcol ? c :
					      c < curcol + arg ? curcol :
					      c - arg;
					}
#line 3166 "gram.c" /* yacc.c:1646  */
    break;

  case 54:
#line 510 "gram.y" /* yacc.c:1646  */
    { hide_row((yyvsp[0].ival)); }
#line 3172 "gram.c" /* yacc.c:1646  */
    break;

  case 55:
#line 512 "gram.y" /* yacc.c:1646  */
    { int r = currow, arg;
					  if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
					    currow = (yyvsp[-2].ival);
					    arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
					  } else {
					      currow = (yyvsp[0].ival);
					      arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
					  }
					  hiderow(arg);
					  currow = r < currow ? r :
					      r < currow + arg ? currow :
					      r - arg;
					}
#line 3190 "gram.c" /* yacc.c:1646  */
    break;

  case 56:
#line 525 "gram.y" /* yacc.c:1646  */
    { if (showrange) {
					    showrange = 0;
					    copy(lookat(showsr, showsc),
					    lookat(currow, curcol),
					    NULL, NULL);
					  } else
					    copy(lookat(currow, curcol),
					    lookat(currow, curcol),
					    NULL, NULL); }
#line 3204 "gram.c" /* yacc.c:1646  */
    break;

  case 57:
#line 534 "gram.y" /* yacc.c:1646  */
    { copy((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp,
					    NULL, NULL); }
#line 3211 "gram.c" /* yacc.c:1646  */
    break;

  case 58:
#line 537 "gram.y" /* yacc.c:1646  */
    { copy((yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp,
					    (yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 3218 "gram.c" /* yacc.c:1646  */
    break;

  case 59:
#line 539 "gram.y" /* yacc.c:1646  */
    { mover((yyvsp[0].ent).vp, lookat(showsr, showsc),
					    lookat(currow, curcol)); }
#line 3225 "gram.c" /* yacc.c:1646  */
    break;

  case 60:
#line 541 "gram.y" /* yacc.c:1646  */
    { mover((yyvsp[-1].ent).vp, (yyvsp[0].rval).left.vp,
					    (yyvsp[0].rval).right.vp); }
#line 3232 "gram.c" /* yacc.c:1646  */
    break;

  case 61:
#line 543 "gram.y" /* yacc.c:1646  */
    { eraser(lookat(showsr, showsc),
					    lookat(currow, curcol)); }
#line 3239 "gram.c" /* yacc.c:1646  */
    break;

  case 62:
#line 545 "gram.y" /* yacc.c:1646  */
    { eraser((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 3245 "gram.c" /* yacc.c:1646  */
    break;

  case 63:
#line 546 "gram.y" /* yacc.c:1646  */
    { yankr(lookat(showsr, showsc),
					    lookat(currow, curcol)); }
#line 3252 "gram.c" /* yacc.c:1646  */
    break;

  case 64:
#line 548 "gram.y" /* yacc.c:1646  */
    { yankr((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 3258 "gram.c" /* yacc.c:1646  */
    break;

  case 65:
#line 549 "gram.y" /* yacc.c:1646  */
    { valueize_area(showsr, showsc, currow, curcol);
					    modflg++; }
#line 3265 "gram.c" /* yacc.c:1646  */
    break;

  case 66:
#line 551 "gram.y" /* yacc.c:1646  */
    { valueize_area(((yyvsp[0].rval).left.vp)->row,
					    ((yyvsp[0].rval).left.vp)->col,
					    ((yyvsp[0].rval).right.vp)->row,
					    ((yyvsp[0].rval).right.vp)->col); modflg++; }
#line 3274 "gram.c" /* yacc.c:1646  */
    break;

  case 67:
#line 556 "gram.y" /* yacc.c:1646  */
    { fill((yyvsp[-2].rval).left.vp, (yyvsp[-2].rval).right.vp, (yyvsp[-1].fval), (yyvsp[0].fval)); }
#line 3280 "gram.c" /* yacc.c:1646  */
    break;

  case 68:
#line 557 "gram.y" /* yacc.c:1646  */
    { sortrange(lookat(showsr, showsc),
				  lookat(currow, curcol), NULL); }
#line 3287 "gram.c" /* yacc.c:1646  */
    break;

  case 69:
#line 559 "gram.y" /* yacc.c:1646  */
    { sortrange((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp, NULL); }
#line 3293 "gram.c" /* yacc.c:1646  */
    break;

  case 70:
#line 561 "gram.y" /* yacc.c:1646  */
    { sortrange((yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp, (yyvsp[0].sval)); }
#line 3299 "gram.c" /* yacc.c:1646  */
    break;

  case 71:
#line 563 "gram.y" /* yacc.c:1646  */
    { format_cell((yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp, (yyvsp[0].sval)); }
#line 3305 "gram.c" /* yacc.c:1646  */
    break;

  case 72:
#line 564 "gram.y" /* yacc.c:1646  */
    { lock_cells(lookat(showsr, showsc),
				    lookat(currow, curcol)); }
#line 3312 "gram.c" /* yacc.c:1646  */
    break;

  case 73:
#line 567 "gram.y" /* yacc.c:1646  */
    { lock_cells((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 3318 "gram.c" /* yacc.c:1646  */
    break;

  case 74:
#line 568 "gram.y" /* yacc.c:1646  */
    { unlock_cells(lookat(showsr, showsc),
					    lookat(currow, curcol)); }
#line 3325 "gram.c" /* yacc.c:1646  */
    break;

  case 75:
#line 571 "gram.y" /* yacc.c:1646  */
    { unlock_cells((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 3331 "gram.c" /* yacc.c:1646  */
    break;

  case 76:
#line 573 "gram.y" /* yacc.c:1646  */
    { moveto((yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col,
					    (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col,
					    (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col); }
#line 3339 "gram.c" /* yacc.c:1646  */
    break;

  case 77:
#line 576 "gram.y" /* yacc.c:1646  */
    { moveto((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
					    (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col,
					    -1, -1); }
#line 3347 "gram.c" /* yacc.c:1646  */
    break;

  case 78:
#line 579 "gram.y" /* yacc.c:1646  */
    { num_search((yyvsp[-1].fval),
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
					  (yyvsp[0].rval).right.vp->row,
					  (yyvsp[0].rval).right.vp->col, 0); }
#line 3356 "gram.c" /* yacc.c:1646  */
    break;

  case 79:
#line 583 "gram.y" /* yacc.c:1646  */
    { num_search((yyvsp[0].fval), 0, 0,
					  maxrow, maxcol, 0); }
#line 3363 "gram.c" /* yacc.c:1646  */
    break;

  case 81:
#line 586 "gram.y" /* yacc.c:1646  */
    { str_search((yyvsp[-1].sval),
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
					  (yyvsp[0].rval).right.vp->row,
					  (yyvsp[0].rval).right.vp->col, 0); }
#line 3372 "gram.c" /* yacc.c:1646  */
    break;

  case 82:
#line 590 "gram.y" /* yacc.c:1646  */
    { str_search((yyvsp[-1].sval),
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
					  (yyvsp[0].rval).right.vp->row,
					  (yyvsp[0].rval).right.vp->col, 1); }
#line 3381 "gram.c" /* yacc.c:1646  */
    break;

  case 83:
#line 594 "gram.y" /* yacc.c:1646  */
    { str_search((yyvsp[-1].sval),
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
					  (yyvsp[0].rval).right.vp->row,
					  (yyvsp[0].rval).right.vp->col, 2); }
#line 3390 "gram.c" /* yacc.c:1646  */
    break;

  case 84:
#line 598 "gram.y" /* yacc.c:1646  */
    { str_search((yyvsp[0].sval), 0, 0,
					  maxrow, maxcol, 0); }
#line 3397 "gram.c" /* yacc.c:1646  */
    break;

  case 85:
#line 600 "gram.y" /* yacc.c:1646  */
    { str_search((yyvsp[0].sval), 0, 0,
					  maxrow, maxcol, 1); }
#line 3404 "gram.c" /* yacc.c:1646  */
    break;

  case 86:
#line 602 "gram.y" /* yacc.c:1646  */
    { str_search((yyvsp[0].sval), 0, 0,
					  maxrow, maxcol, 2); }
#line 3411 "gram.c" /* yacc.c:1646  */
    break;

  case 87:
#line 604 "gram.y" /* yacc.c:1646  */
    { go_last(); }
#line 3417 "gram.c" /* yacc.c:1646  */
    break;

  case 88:
#line 605 "gram.y" /* yacc.c:1646  */
    { /* don't repeat last goto on
						"unintelligible word" */ ; }
#line 3424 "gram.c" /* yacc.c:1646  */
    break;

  case 89:
#line 607 "gram.y" /* yacc.c:1646  */
    { struct ent_ptr arg1, arg2;
					  arg1.vp = lookat(showsr, showsc);
					  arg1.vf = 0;
					  arg2.vp = lookat(currow, curcol);
					  arg2.vf = 0;
                                          if (arg1.vp == arg2.vp || !showrange)
                                             add_range((yyvsp[0].sval), arg2, arg2, 0);
                                          else
                                             add_range((yyvsp[0].sval), arg1, arg2, 1); }
#line 3438 "gram.c" /* yacc.c:1646  */
    break;

  case 90:
#line 617 "gram.y" /* yacc.c:1646  */
    { add_range((yyvsp[-1].sval), (yyvsp[0].rval).left, (yyvsp[0].rval).right, 1); }
#line 3444 "gram.c" /* yacc.c:1646  */
    break;

  case 91:
#line 618 "gram.y" /* yacc.c:1646  */
    { add_range((yyvsp[-1].sval), (yyvsp[0].ent), (yyvsp[0].ent), 0); }
#line 3450 "gram.c" /* yacc.c:1646  */
    break;

  case 92:
#line 619 "gram.y" /* yacc.c:1646  */
    { del_range((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 3456 "gram.c" /* yacc.c:1646  */
    break;

  case 93:
#line 620 "gram.y" /* yacc.c:1646  */
    { add_abbr((yyvsp[0].sval)); }
#line 3462 "gram.c" /* yacc.c:1646  */
    break;

  case 94:
#line 621 "gram.y" /* yacc.c:1646  */
    { add_abbr(NULL); }
#line 3468 "gram.c" /* yacc.c:1646  */
    break;

  case 95:
#line 622 "gram.y" /* yacc.c:1646  */
    { del_abbr((yyvsp[0].sval)); }
#line 3474 "gram.c" /* yacc.c:1646  */
    break;

  case 96:
#line 623 "gram.y" /* yacc.c:1646  */
    { add_frange((yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp,
						(yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp,
						0, 0, 0, 0); }
#line 3482 "gram.c" /* yacc.c:1646  */
    break;

  case 97:
#line 626 "gram.y" /* yacc.c:1646  */
    { if (showrange) {
					    showrange = 0;
					    add_frange((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp,
						lookat(showsr, showsc),
						lookat(currow, curcol),
						0, 0, 0, 0);
					  } else {
					    struct frange *cfr;
					    cfr = find_frange(currow, curcol);
					    if (cfr) {
						add_frange(cfr->or_left,
						    cfr->or_right,
						    (yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp,
						    0, 0, 0, 0);
					    }
					  }
					}
#line 3504 "gram.c" /* yacc.c:1646  */
    break;

  case 98:
#line 643 "gram.y" /* yacc.c:1646  */
    { struct frange *cfr;
					  /* cfr points to current frange */
					  cfr = find_frange(currow, curcol);
					  if (showrange && cfr) {
					    showrange = 0;
					    add_frange(cfr->or_left,
						cfr->or_right,
						lookat(showsr, showsc),
						lookat(currow, curcol),
						0, 0, 0, 0);
					  } else {
					    error("Need both outer and inner"
						    " ranges to create frame");
					  }
					}
#line 3524 "gram.c" /* yacc.c:1646  */
    break;

  case 99:
#line 659 "gram.y" /* yacc.c:1646  */
    { add_frange((yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp,
						NULL, NULL, (yyvsp[0].ival), -1, -1, -1); }
#line 3531 "gram.c" /* yacc.c:1646  */
    break;

  case 100:
#line 661 "gram.y" /* yacc.c:1646  */
    { struct frange *cfr;
					  /* cfr points to current frange */
					  cfr = find_frange(currow, curcol);
					  if (cfr)
					    add_frange(cfr->or_left,
						cfr->or_right,
						NULL, NULL, (yyvsp[0].ival), -1, -1, -1); }
#line 3543 "gram.c" /* yacc.c:1646  */
    break;

  case 101:
#line 669 "gram.y" /* yacc.c:1646  */
    { add_frange((yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp,
						NULL, NULL, -1, (yyvsp[0].ival), -1, -1); }
#line 3550 "gram.c" /* yacc.c:1646  */
    break;

  case 102:
#line 671 "gram.y" /* yacc.c:1646  */
    { struct frange *cfr;
					  /* cfr points to current frange */
					  cfr = find_frange(currow, curcol);
					  if (cfr)
					    add_frange(cfr->or_left,
						cfr->or_right,
						NULL, NULL, -1, (yyvsp[0].ival), -1, -1); }
#line 3562 "gram.c" /* yacc.c:1646  */
    break;

  case 103:
#line 679 "gram.y" /* yacc.c:1646  */
    { add_frange((yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp,
						NULL, NULL, -1, -1, (yyvsp[0].ival), -1); }
#line 3569 "gram.c" /* yacc.c:1646  */
    break;

  case 104:
#line 681 "gram.y" /* yacc.c:1646  */
    { struct frange *cfr;
					  /* cfr points to current frange */
					  cfr = find_frange(currow, curcol);
					  if (cfr)
					    add_frange(cfr->or_left,
						cfr->or_right,
						NULL, NULL, -1, -1, (yyvsp[0].ival), -1); }
#line 3581 "gram.c" /* yacc.c:1646  */
    break;

  case 105:
#line 689 "gram.y" /* yacc.c:1646  */
    { add_frange((yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp,
						NULL, NULL, -1, -1, -1, (yyvsp[0].ival)); }
#line 3588 "gram.c" /* yacc.c:1646  */
    break;

  case 106:
#line 691 "gram.y" /* yacc.c:1646  */
    { struct frange *cfr;
					  /* cfr points to current frange */
					  cfr = find_frange(currow, curcol);
					  if (cfr)
					    add_frange(cfr->or_left,
						cfr->or_right,
						NULL, NULL, -1, -1, -1, (yyvsp[0].ival)); }
#line 3600 "gram.c" /* yacc.c:1646  */
    break;

  case 107:
#line 698 "gram.y" /* yacc.c:1646  */
    { add_frange((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp,
						NULL, NULL, 0, 0, 0, 0); }
#line 3607 "gram.c" /* yacc.c:1646  */
    break;

  case 108:
#line 700 "gram.y" /* yacc.c:1646  */
    { struct frange *cfr;
					  /* cfr points to current frange */
					  cfr = find_frange(currow, curcol);
					  if (cfr)
					    add_frange(cfr->or_left,
						cfr->or_right,
						NULL, NULL, 0, 0, 0, 0); }
#line 3619 "gram.c" /* yacc.c:1646  */
    break;

  case 109:
#line 707 "gram.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].ival) > 0 && (yyvsp[-1].ival) < 9)
					    initcolor((yyvsp[-1].ival));
					  else
					    error("Invalid color number"); }
#line 3628 "gram.c" /* yacc.c:1646  */
    break;

  case 110:
#line 711 "gram.y" /* yacc.c:1646  */
    { change_color((yyvsp[-2].ival), (yyvsp[0].enode)); }
#line 3634 "gram.c" /* yacc.c:1646  */
    break;

  case 111:
#line 712 "gram.y" /* yacc.c:1646  */
    { add_crange((yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp,
						(yyvsp[0].ival)); }
#line 3641 "gram.c" /* yacc.c:1646  */
    break;

  case 112:
#line 714 "gram.y" /* yacc.c:1646  */
    { modflg++; }
#line 3647 "gram.c" /* yacc.c:1646  */
    break;

  case 113:
#line 715 "gram.y" /* yacc.c:1646  */
    { backrow( 1); }
#line 3653 "gram.c" /* yacc.c:1646  */
    break;

  case 114:
#line 716 "gram.y" /* yacc.c:1646  */
    { backrow((yyvsp[0].ival)); }
#line 3659 "gram.c" /* yacc.c:1646  */
    break;

  case 115:
#line 717 "gram.y" /* yacc.c:1646  */
    { forwrow( 1); }
#line 3665 "gram.c" /* yacc.c:1646  */
    break;

  case 116:
#line 718 "gram.y" /* yacc.c:1646  */
    { forwrow((yyvsp[0].ival)); }
#line 3671 "gram.c" /* yacc.c:1646  */
    break;

  case 117:
#line 719 "gram.y" /* yacc.c:1646  */
    { backcol( 1); }
#line 3677 "gram.c" /* yacc.c:1646  */
    break;

  case 118:
#line 720 "gram.y" /* yacc.c:1646  */
    { backcol((yyvsp[0].ival)); }
#line 3683 "gram.c" /* yacc.c:1646  */
    break;

  case 119:
#line 721 "gram.y" /* yacc.c:1646  */
    { forwcol( 1); }
#line 3689 "gram.c" /* yacc.c:1646  */
    break;

  case 120:
#line 722 "gram.y" /* yacc.c:1646  */
    { forwcol((yyvsp[0].ival)); }
#line 3695 "gram.c" /* yacc.c:1646  */
    break;

  case 121:
#line 723 "gram.y" /* yacc.c:1646  */
    { doend(-1, 0); }
#line 3701 "gram.c" /* yacc.c:1646  */
    break;

  case 122:
#line 724 "gram.y" /* yacc.c:1646  */
    { doend( 1, 0); }
#line 3707 "gram.c" /* yacc.c:1646  */
    break;

  case 123:
#line 725 "gram.y" /* yacc.c:1646  */
    { doend( 0,-1); }
#line 3713 "gram.c" /* yacc.c:1646  */
    break;

  case 124:
#line 726 "gram.y" /* yacc.c:1646  */
    { doend( 0, 1); }
#line 3719 "gram.c" /* yacc.c:1646  */
    break;

  case 125:
#line 727 "gram.y" /* yacc.c:1646  */
    { int c;
					  if ((c = *(yyvsp[0].sval)) >= '0' && c <= '9') {
					    qbuf = c - '0' + (DELBUFSIZE - 10);
					  } else if (c >= 'a' && c <= 'z') {
					    qbuf = c - 'a' + (DELBUFSIZE - 36);
					  } else if (c == '"') {
					    qbuf = 0;
					  } else
					    error("Invalid buffer");
					  scxfree((yyvsp[0].sval));
					}
#line 3735 "gram.c" /* yacc.c:1646  */
    break;

  case 126:
#line 738 "gram.y" /* yacc.c:1646  */
    { insertrow( 1, 0); }
#line 3741 "gram.c" /* yacc.c:1646  */
    break;

  case 127:
#line 739 "gram.y" /* yacc.c:1646  */
    { insertrow((yyvsp[0].ival), 0); }
#line 3747 "gram.c" /* yacc.c:1646  */
    break;

  case 128:
#line 740 "gram.y" /* yacc.c:1646  */
    { insertrow( 1, 1); }
#line 3753 "gram.c" /* yacc.c:1646  */
    break;

  case 129:
#line 741 "gram.y" /* yacc.c:1646  */
    { insertrow((yyvsp[0].ival), 1); }
#line 3759 "gram.c" /* yacc.c:1646  */
    break;

  case 130:
#line 742 "gram.y" /* yacc.c:1646  */
    { insertcol( 1, 0); }
#line 3765 "gram.c" /* yacc.c:1646  */
    break;

  case 131:
#line 743 "gram.y" /* yacc.c:1646  */
    { insertcol((yyvsp[0].ival), 0); }
#line 3771 "gram.c" /* yacc.c:1646  */
    break;

  case 132:
#line 744 "gram.y" /* yacc.c:1646  */
    { insertcol( 1, 1); }
#line 3777 "gram.c" /* yacc.c:1646  */
    break;

  case 133:
#line 745 "gram.y" /* yacc.c:1646  */
    { insertcol((yyvsp[0].ival), 1); }
#line 3783 "gram.c" /* yacc.c:1646  */
    break;

  case 134:
#line 746 "gram.y" /* yacc.c:1646  */
    { int arg;
	    				  if (showrange == SHOWROWS) {
					    if (showsr < currow) {
						int r = currow;
						currow = showsr;
						showsr = r;
					    }
					    arg = showsr - currow + 1;
					  } else
					    arg = 1;
					  deleterow(arg);
					}
#line 3800 "gram.c" /* yacc.c:1646  */
    break;

  case 135:
#line 758 "gram.y" /* yacc.c:1646  */
    { deleterow((yyvsp[0].ival)); }
#line 3806 "gram.c" /* yacc.c:1646  */
    break;

  case 136:
#line 759 "gram.y" /* yacc.c:1646  */
    { int r = currow;
					  currow = (yyvsp[0].ival);
					  deleterow(1);
					  currow = r <= currow ? r : r - 1;
					}
#line 3816 "gram.c" /* yacc.c:1646  */
    break;

  case 137:
#line 765 "gram.y" /* yacc.c:1646  */
    { int r = currow, arg;
					  if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
					    currow = (yyvsp[-2].ival);
					    arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
					  } else {
					      currow = (yyvsp[0].ival);
					      arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
					  }
					  deleterow(arg);
					  currow = r < currow ? r :
					      r < currow + arg ? currow :
					      r - arg;
					}
#line 3834 "gram.c" /* yacc.c:1646  */
    break;

  case 138:
#line 778 "gram.y" /* yacc.c:1646  */
    { int arg;
	    				  if (showrange == SHOWCOLS) {
					    if (showsc < curcol) {
						int c = curcol;
						curcol = showsc;
						showsc = c;
					    }
					    arg = showsc - curcol + 1;
					  } else
					    arg = 1;
					  closecol(arg);
					}
#line 3851 "gram.c" /* yacc.c:1646  */
    break;

  case 139:
#line 790 "gram.y" /* yacc.c:1646  */
    { int r = curcol;
					  curcol = (yyvsp[0].ival);
					  closecol(1);
					  curcol = r <= curcol ? r : r - 1;
					}
#line 3861 "gram.c" /* yacc.c:1646  */
    break;

  case 140:
#line 795 "gram.y" /* yacc.c:1646  */
    { closecol((yyvsp[0].ival)); }
#line 3867 "gram.c" /* yacc.c:1646  */
    break;

  case 141:
#line 796 "gram.y" /* yacc.c:1646  */
    { int c = curcol, arg;
					  if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
					    curcol = (yyvsp[-2].ival);
					    arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
					  } else {
					      curcol = (yyvsp[0].ival);
					      arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
					  }
					  closecol(arg);
					  curcol = c < curcol ? c :
					      c < curcol + arg ? curcol :
					      c - arg;
					}
#line 3885 "gram.c" /* yacc.c:1646  */
    break;

  case 142:
#line 809 "gram.y" /* yacc.c:1646  */
    { int r = currow, arg;
	    				  if (showrange == SHOWROWS) {
					    if (showsr < currow) {
						currow = showsr;
						showsr = r;
					    }
					    arg = showsr - currow + 1;
					  } else
					    arg = 1;
					  yankrow(arg);
					  currow = r;
					}
#line 3902 "gram.c" /* yacc.c:1646  */
    break;

  case 143:
#line 821 "gram.y" /* yacc.c:1646  */
    { yankrow((yyvsp[0].ival)); }
#line 3908 "gram.c" /* yacc.c:1646  */
    break;

  case 144:
#line 822 "gram.y" /* yacc.c:1646  */
    { int r = currow;
					  currow = (yyvsp[0].ival);
					  yankrow(1);
					  currow = r;
					}
#line 3918 "gram.c" /* yacc.c:1646  */
    break;

  case 145:
#line 828 "gram.y" /* yacc.c:1646  */
    { int r = currow, arg;
					  if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
					    currow = (yyvsp[-2].ival);
					    arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
					  } else {
					      currow = (yyvsp[0].ival);
					      arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
					  }
					  yankrow(arg);
					  currow = r;
					}
#line 3934 "gram.c" /* yacc.c:1646  */
    break;

  case 146:
#line 839 "gram.y" /* yacc.c:1646  */
    { int c = curcol, arg;
	    				  if (showrange == SHOWCOLS) {
					    if (showsc < curcol) {
						curcol = showsc;
						showsc = c;
					    }
					    arg = showsc - curcol + 1;
					  } else
					    arg = 1;
					  yankcol(arg);
					  curcol = c;
					}
#line 3951 "gram.c" /* yacc.c:1646  */
    break;

  case 147:
#line 851 "gram.y" /* yacc.c:1646  */
    { int c = curcol;
					  curcol = (yyvsp[0].ival);
					  yankcol(1);
					  curcol = c;
					}
#line 3961 "gram.c" /* yacc.c:1646  */
    break;

  case 148:
#line 856 "gram.y" /* yacc.c:1646  */
    { yankcol((yyvsp[0].ival)); }
#line 3967 "gram.c" /* yacc.c:1646  */
    break;

  case 149:
#line 857 "gram.y" /* yacc.c:1646  */
    { int c = curcol, arg;
					  if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
					    curcol = (yyvsp[-2].ival);
					    arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
					  } else {
					      curcol = (yyvsp[0].ival);
					      arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
					  }
					  yankcol(arg);
					  curcol = c;
					}
#line 3983 "gram.c" /* yacc.c:1646  */
    break;

  case 150:
#line 868 "gram.y" /* yacc.c:1646  */
    { pullcells('p'); }
#line 3989 "gram.c" /* yacc.c:1646  */
    break;

  case 151:
#line 869 "gram.y" /* yacc.c:1646  */
    { pullcells('m'); }
#line 3995 "gram.c" /* yacc.c:1646  */
    break;

  case 152:
#line 870 "gram.y" /* yacc.c:1646  */
    { pullcells('r'); }
#line 4001 "gram.c" /* yacc.c:1646  */
    break;

  case 153:
#line 871 "gram.y" /* yacc.c:1646  */
    { pullcells('c'); }
#line 4007 "gram.c" /* yacc.c:1646  */
    break;

  case 154:
#line 872 "gram.y" /* yacc.c:1646  */
    { pullcells('x'); }
#line 4013 "gram.c" /* yacc.c:1646  */
    break;

  case 155:
#line 873 "gram.y" /* yacc.c:1646  */
    { pullcells('t'); }
#line 4019 "gram.c" /* yacc.c:1646  */
    break;

  case 156:
#line 874 "gram.y" /* yacc.c:1646  */
    { pullcells('f'); }
#line 4025 "gram.c" /* yacc.c:1646  */
    break;

  case 157:
#line 875 "gram.y" /* yacc.c:1646  */
    { copy(NULL, NULL, NULL, NULL); }
#line 4031 "gram.c" /* yacc.c:1646  */
    break;

  case 158:
#line 876 "gram.y" /* yacc.c:1646  */
    { copy((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp,
					     NULL, (struct ent *)1); }
#line 4038 "gram.c" /* yacc.c:1646  */
    break;

  case 159:
#line 878 "gram.y" /* yacc.c:1646  */
    { sprintf(line, "%s%d ",
					     coltoa(curcol), currow);
					  sprintf(line + strlen(line), "%s%d\n",
					     coltoa(stcol), strow);
					  write(macrofd, line, strlen(line));
					  line[0] = '\0'; }
#line 4049 "gram.c" /* yacc.c:1646  */
    break;

  case 160:
#line 884 "gram.y" /* yacc.c:1646  */
    { sprintf(line, "%s%d ",
					     coltoa(curcol), currow);
					  sprintf(line + strlen(line), "%s%d\n",
					     coltoa(stcol), strow);
					  write((yyvsp[0].ival), line, strlen(line));
					  line[0] = '\0'; }
#line 4060 "gram.c" /* yacc.c:1646  */
    break;

  case 161:
#line 890 "gram.y" /* yacc.c:1646  */
    { getnum((yyvsp[0].rval).left.vp->row,
						(yyvsp[0].rval).left.vp->col,
						(yyvsp[0].rval).right.vp->row,
						(yyvsp[0].rval).right.vp->col, macrofd); }
#line 4069 "gram.c" /* yacc.c:1646  */
    break;

  case 162:
#line 895 "gram.y" /* yacc.c:1646  */
    { getnum((yyvsp[-2].rval).left.vp->row,
						(yyvsp[-2].rval).left.vp->col,
						(yyvsp[-2].rval).right.vp->row,
						(yyvsp[-2].rval).right.vp->col, (yyvsp[0].ival)); }
#line 4078 "gram.c" /* yacc.c:1646  */
    break;

  case 163:
#line 899 "gram.y" /* yacc.c:1646  */
    { getnum(currow, curcol,
						currow, curcol, macrofd); }
#line 4085 "gram.c" /* yacc.c:1646  */
    break;

  case 164:
#line 901 "gram.y" /* yacc.c:1646  */
    { getnum(currow, curcol,
						currow, curcol, (yyvsp[0].ival)); }
#line 4092 "gram.c" /* yacc.c:1646  */
    break;

  case 165:
#line 903 "gram.y" /* yacc.c:1646  */
    { fgetnum((yyvsp[0].rval).left.vp->row,
						(yyvsp[0].rval).left.vp->col,
						(yyvsp[0].rval).right.vp->row,
						(yyvsp[0].rval).right.vp->col, macrofd); }
#line 4101 "gram.c" /* yacc.c:1646  */
    break;

  case 166:
#line 908 "gram.y" /* yacc.c:1646  */
    { fgetnum((yyvsp[-2].rval).left.vp->row,
						(yyvsp[-2].rval).left.vp->col,
						(yyvsp[-2].rval).right.vp->row,
						(yyvsp[-2].rval).right.vp->col, (yyvsp[0].ival)); }
#line 4110 "gram.c" /* yacc.c:1646  */
    break;

  case 167:
#line 912 "gram.y" /* yacc.c:1646  */
    { fgetnum(currow, curcol,
						currow, curcol, macrofd); }
#line 4117 "gram.c" /* yacc.c:1646  */
    break;

  case 168:
#line 914 "gram.y" /* yacc.c:1646  */
    { fgetnum(currow, curcol,
						currow, curcol, (yyvsp[0].ival)); }
#line 4124 "gram.c" /* yacc.c:1646  */
    break;

  case 169:
#line 917 "gram.y" /* yacc.c:1646  */
    { getstring((yyvsp[0].rval).left.vp->row,
						(yyvsp[0].rval).left.vp->col,
						(yyvsp[0].rval).right.vp->row,
						(yyvsp[0].rval).right.vp->col, macrofd); }
#line 4133 "gram.c" /* yacc.c:1646  */
    break;

  case 170:
#line 922 "gram.y" /* yacc.c:1646  */
    { getstring((yyvsp[-2].rval).left.vp->row,
						(yyvsp[-2].rval).left.vp->col,
						(yyvsp[-2].rval).right.vp->row,
						(yyvsp[-2].rval).right.vp->col, (yyvsp[0].ival)); }
#line 4142 "gram.c" /* yacc.c:1646  */
    break;

  case 171:
#line 926 "gram.y" /* yacc.c:1646  */
    { getstring(currow, curcol,
						currow, curcol, macrofd); }
#line 4149 "gram.c" /* yacc.c:1646  */
    break;

  case 172:
#line 928 "gram.y" /* yacc.c:1646  */
    { getstring(currow, curcol,
						currow, curcol, (yyvsp[0].ival)); }
#line 4156 "gram.c" /* yacc.c:1646  */
    break;

  case 173:
#line 930 "gram.y" /* yacc.c:1646  */
    { getexp((yyvsp[0].rval).left.vp->row,
						(yyvsp[0].rval).left.vp->col,
						(yyvsp[0].rval).right.vp->row,
						(yyvsp[0].rval).right.vp->col, macrofd); }
#line 4165 "gram.c" /* yacc.c:1646  */
    break;

  case 174:
#line 935 "gram.y" /* yacc.c:1646  */
    { getexp((yyvsp[-2].rval).left.vp->row,
						(yyvsp[-2].rval).left.vp->col,
						(yyvsp[-2].rval).right.vp->row,
						(yyvsp[-2].rval).right.vp->col, (yyvsp[0].ival)); }
#line 4174 "gram.c" /* yacc.c:1646  */
    break;

  case 175:
#line 939 "gram.y" /* yacc.c:1646  */
    { getexp(currow, curcol,
						currow, curcol, macrofd); }
#line 4181 "gram.c" /* yacc.c:1646  */
    break;

  case 176:
#line 941 "gram.y" /* yacc.c:1646  */
    { getexp(currow, curcol,
						currow, curcol, (yyvsp[0].ival)); }
#line 4188 "gram.c" /* yacc.c:1646  */
    break;

  case 177:
#line 943 "gram.y" /* yacc.c:1646  */
    { getformat((yyvsp[0].ival), macrofd); }
#line 4194 "gram.c" /* yacc.c:1646  */
    break;

  case 178:
#line 945 "gram.y" /* yacc.c:1646  */
    { getformat((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 4200 "gram.c" /* yacc.c:1646  */
    break;

  case 179:
#line 946 "gram.y" /* yacc.c:1646  */
    { getformat(curcol, macrofd); }
#line 4206 "gram.c" /* yacc.c:1646  */
    break;

  case 180:
#line 947 "gram.y" /* yacc.c:1646  */
    { getformat(curcol, (yyvsp[0].ival)); }
#line 4212 "gram.c" /* yacc.c:1646  */
    break;

  case 181:
#line 948 "gram.y" /* yacc.c:1646  */
    { getfmt((yyvsp[0].rval).left.vp->row,
						(yyvsp[0].rval).left.vp->col,
						(yyvsp[0].rval).right.vp->row,
						(yyvsp[0].rval).right.vp->col, macrofd); }
#line 4221 "gram.c" /* yacc.c:1646  */
    break;

  case 182:
#line 953 "gram.y" /* yacc.c:1646  */
    { getfmt((yyvsp[-2].rval).left.vp->row,
						(yyvsp[-2].rval).left.vp->col,
						(yyvsp[-2].rval).right.vp->row,
						(yyvsp[-2].rval).right.vp->col, (yyvsp[0].ival)); }
#line 4230 "gram.c" /* yacc.c:1646  */
    break;

  case 183:
#line 957 "gram.y" /* yacc.c:1646  */
    { getfmt(currow, curcol,
						currow, curcol, macrofd); }
#line 4237 "gram.c" /* yacc.c:1646  */
    break;

  case 184:
#line 959 "gram.y" /* yacc.c:1646  */
    { getfmt(currow, curcol,
						currow, curcol, (yyvsp[0].ival)); }
#line 4244 "gram.c" /* yacc.c:1646  */
    break;

  case 185:
#line 961 "gram.y" /* yacc.c:1646  */
    { getframe(macrofd); }
#line 4250 "gram.c" /* yacc.c:1646  */
    break;

  case 186:
#line 962 "gram.y" /* yacc.c:1646  */
    { getframe((yyvsp[0].ival)); }
#line 4256 "gram.c" /* yacc.c:1646  */
    break;

  case 187:
#line 963 "gram.y" /* yacc.c:1646  */
    { getrange((yyvsp[0].sval), macrofd); }
#line 4262 "gram.c" /* yacc.c:1646  */
    break;

  case 188:
#line 965 "gram.y" /* yacc.c:1646  */
    { getrange((yyvsp[-2].sval), (yyvsp[0].ival)); }
#line 4268 "gram.c" /* yacc.c:1646  */
    break;

  case 189:
#line 966 "gram.y" /* yacc.c:1646  */
    { doeval((yyvsp[0].enode), NULL, currow, curcol,
						macrofd); }
#line 4275 "gram.c" /* yacc.c:1646  */
    break;

  case 190:
#line 968 "gram.y" /* yacc.c:1646  */
    { doeval((yyvsp[-1].enode), (yyvsp[0].sval), currow, curcol,
						macrofd); }
#line 4282 "gram.c" /* yacc.c:1646  */
    break;

  case 191:
#line 971 "gram.y" /* yacc.c:1646  */
    { doeval((yyvsp[-3].enode), (yyvsp[-2].sval), currow, curcol,
						(yyvsp[-2].sval)); }
#line 4289 "gram.c" /* yacc.c:1646  */
    break;

  case 192:
#line 973 "gram.y" /* yacc.c:1646  */
    { doseval((yyvsp[0].enode), currow, curcol, macrofd); }
#line 4295 "gram.c" /* yacc.c:1646  */
    break;

  case 193:
#line 974 "gram.y" /* yacc.c:1646  */
    { doquery((yyvsp[-1].sval), (yyvsp[0].sval), macrofd); }
#line 4301 "gram.c" /* yacc.c:1646  */
    break;

  case 194:
#line 976 "gram.y" /* yacc.c:1646  */
    { doquery((yyvsp[-3].sval), (yyvsp[-2].sval), (yyvsp[0].ival)); }
#line 4307 "gram.c" /* yacc.c:1646  */
    break;

  case 195:
#line 977 "gram.y" /* yacc.c:1646  */
    { doquery((yyvsp[0].sval), NULL, macrofd); }
#line 4313 "gram.c" /* yacc.c:1646  */
    break;

  case 196:
#line 979 "gram.y" /* yacc.c:1646  */
    { doquery((yyvsp[-2].sval), NULL, (yyvsp[0].ival)); }
#line 4319 "gram.c" /* yacc.c:1646  */
    break;

  case 197:
#line 980 "gram.y" /* yacc.c:1646  */
    { doquery(NULL, NULL, macrofd); }
#line 4325 "gram.c" /* yacc.c:1646  */
    break;

  case 198:
#line 981 "gram.y" /* yacc.c:1646  */
    { doquery(NULL, NULL, (yyvsp[0].ival)); }
#line 4331 "gram.c" /* yacc.c:1646  */
    break;

  case 199:
#line 982 "gram.y" /* yacc.c:1646  */
    { dogetkey(); }
#line 4337 "gram.c" /* yacc.c:1646  */
    break;

  case 200:
#line 983 "gram.y" /* yacc.c:1646  */
    { error((yyvsp[0].sval)); }
#line 4343 "gram.c" /* yacc.c:1646  */
    break;

  case 201:
#line 984 "gram.y" /* yacc.c:1646  */
    { dostat(macrofd); }
#line 4349 "gram.c" /* yacc.c:1646  */
    break;

  case 202:
#line 985 "gram.y" /* yacc.c:1646  */
    { dostat((yyvsp[0].ival)); }
#line 4355 "gram.c" /* yacc.c:1646  */
    break;

  case 203:
#line 986 "gram.y" /* yacc.c:1646  */
    { EvalAll();
					  update(1);
					  changed = 0;
					}
#line 4364 "gram.c" /* yacc.c:1646  */
    break;

  case 204:
#line 990 "gram.y" /* yacc.c:1646  */
    { if (usecurses) {
					    clearok(stdscr, TRUE);
					    linelim = -1;
					    update(1);
					    refresh();
					    changed = 0;
					  }
					}
#line 4377 "gram.c" /* yacc.c:1646  */
    break;

  case 205:
#line 998 "gram.y" /* yacc.c:1646  */
    { stopdisp(); exit(0); }
#line 4383 "gram.c" /* yacc.c:1646  */
    break;

  case 206:
#line 999 "gram.y" /* yacc.c:1646  */
    { deraw(1);
					  system((yyvsp[0].sval));
					  if (*((yyvsp[0].sval) + strlen((yyvsp[0].sval)) - 1) != '&') {
					    printf("Press any key to continue ");
					    fflush(stdout);
					    cbreak();
					    nmgetch();
					  }
					  goraw();
					  scxfree((yyvsp[0].sval)); }
#line 4398 "gram.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1010 "gram.y" /* yacc.c:1646  */
    { addplugin((yyvsp[-2].sval), (yyvsp[0].sval), 'r'); }
#line 4404 "gram.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1012 "gram.y" /* yacc.c:1646  */
    { addplugin((yyvsp[-2].sval), (yyvsp[0].sval), 'w'); }
#line 4410 "gram.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1013 "gram.y" /* yacc.c:1646  */
    { *line = '|';
					  sprintf(line + 1, (yyvsp[0].sval));
					  readfile(line, 0);
					  scxfree((yyvsp[0].sval)); }
#line 4419 "gram.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1020 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_var(O_VAR, (yyvsp[0].ent)); }
#line 4425 "gram.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1021 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('f', (yyvsp[0].enode), ENULL); }
#line 4431 "gram.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1023 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('F', (yyvsp[0].enode), ENULL); }
#line 4437 "gram.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1025 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SUM,
					new_range(REDUCE | SUM, (yyvsp[-1].rval)), ENULL); }
#line 4444 "gram.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1028 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SUM,
					new_range(REDUCE | SUM, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4451 "gram.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1031 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(PROD,
					new_range(REDUCE | PROD, (yyvsp[-1].rval)), ENULL); }
#line 4458 "gram.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1034 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(PROD,
					new_range(REDUCE | PROD, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4465 "gram.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1037 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(AVG,
					new_range(REDUCE | AVG, (yyvsp[-1].rval)), ENULL); }
#line 4472 "gram.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1040 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(AVG,
					new_range(REDUCE | AVG, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4479 "gram.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1043 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(STDDEV,
					new_range(REDUCE | STDDEV, (yyvsp[-1].rval)), ENULL); }
#line 4486 "gram.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1046 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(STDDEV,
					new_range(REDUCE | STDDEV, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4493 "gram.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1049 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(COUNT,
					new_range(REDUCE | COUNT, (yyvsp[-1].rval)), ENULL); }
#line 4500 "gram.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1052 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(COUNT,
					new_range(REDUCE | COUNT, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4507 "gram.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1055 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MAX,
					new_range(REDUCE | MAX, (yyvsp[-1].rval)), ENULL); }
#line 4514 "gram.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1058 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MAX,
					new_range(REDUCE | MAX, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4521 "gram.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1061 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LMAX, (yyvsp[-1].enode), (yyvsp[-3].enode)); }
#line 4527 "gram.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1063 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MIN,
					new_range(REDUCE | MIN, (yyvsp[-1].rval)), ENULL); }
#line 4534 "gram.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1066 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MIN,
					new_range(REDUCE | MIN, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4541 "gram.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1069 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LMIN, (yyvsp[-1].enode), (yyvsp[-3].enode)); }
#line 4547 "gram.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1071 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range(REDUCE | 'R', (yyvsp[-1].rval)); }
#line 4553 "gram.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1073 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range(REDUCE | 'C', (yyvsp[-1].rval)); }
#line 4559 "gram.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1074 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ABS, (yyvsp[-1].enode), ENULL); }
#line 4565 "gram.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1075 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ACOS, (yyvsp[-1].enode), ENULL); }
#line 4571 "gram.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1076 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ASIN, (yyvsp[-1].enode), ENULL); }
#line 4577 "gram.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1077 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ATAN, (yyvsp[-1].enode), ENULL); }
#line 4583 "gram.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1078 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ATAN2, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4589 "gram.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1079 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(CEIL, (yyvsp[-1].enode), ENULL); }
#line 4595 "gram.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1080 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(COS, (yyvsp[-1].enode), ENULL); }
#line 4601 "gram.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1081 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(EXP, (yyvsp[-1].enode), ENULL); }
#line 4607 "gram.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1082 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FABS, (yyvsp[-1].enode), ENULL); }
#line 4613 "gram.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1083 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FLOOR, (yyvsp[-1].enode), ENULL); }
#line 4619 "gram.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1084 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(HYPOT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4625 "gram.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1085 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOG, (yyvsp[-1].enode), ENULL); }
#line 4631 "gram.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1086 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOG10, (yyvsp[-1].enode), ENULL); }
#line 4637 "gram.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1087 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(POW, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4643 "gram.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1088 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SIN, (yyvsp[-1].enode), ENULL); }
#line 4649 "gram.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1089 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SQRT, (yyvsp[-1].enode), ENULL); }
#line 4655 "gram.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1090 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(TAN, (yyvsp[-1].enode), ENULL); }
#line 4661 "gram.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1091 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DTR, (yyvsp[-1].enode), ENULL); }
#line 4667 "gram.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1092 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(RTD, (yyvsp[-1].enode), ENULL); }
#line 4673 "gram.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1093 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(RND, (yyvsp[-1].enode), ENULL); }
#line 4679 "gram.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1094 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ROUND, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4685 "gram.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1095 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(IF,  (yyvsp[-5].enode),new(',',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4691 "gram.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1097 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(PV,  (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4697 "gram.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1098 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FV,  (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4703 "gram.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1099 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(PMT, (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4709 "gram.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1101 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(HOUR, (yyvsp[-1].enode), ENULL); }
#line 4715 "gram.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1102 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MINUTE, (yyvsp[-1].enode), ENULL); }
#line 4721 "gram.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1103 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SECOND, (yyvsp[-1].enode), ENULL); }
#line 4727 "gram.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1104 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MONTH, (yyvsp[-1].enode), ENULL); }
#line 4733 "gram.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1105 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DAY, (yyvsp[-1].enode), ENULL); }
#line 4739 "gram.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1106 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(YEAR, (yyvsp[-1].enode), ENULL); }
#line 4745 "gram.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1107 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(NOW, ENULL, ENULL);}
#line 4751 "gram.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1109 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DTS, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode)));}
#line 4757 "gram.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1110 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DTS,
				new_const(O_CONST, (double) (yyvsp[-4].ival)),
				new(',', new_const(O_CONST, (double) (yyvsp[-2].ival)),
				new_const(O_CONST, (double) (yyvsp[0].ival))));}
#line 4766 "gram.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1115 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(TTS, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode)));}
#line 4772 "gram.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1116 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(STON, (yyvsp[-1].enode), ENULL); }
#line 4778 "gram.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1117 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(EQS, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4784 "gram.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1118 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DATE, (yyvsp[-1].enode), ENULL); }
#line 4790 "gram.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1119 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DATE, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4796 "gram.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1120 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FMT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4802 "gram.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1121 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(UPPER, (yyvsp[-1].enode), ENULL); }
#line 4808 "gram.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1122 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOWER, (yyvsp[-1].enode), ENULL); }
#line 4814 "gram.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1123 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(CAPITAL, (yyvsp[-1].enode), ENULL); }
#line 4820 "gram.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1125 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(INDEX, new_range(REDUCE | INDEX, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4826 "gram.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1127 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(INDEX, new_range(REDUCE | INDEX, (yyvsp[-1].rval)), (yyvsp[-3].enode)); }
#line 4832 "gram.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1129 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(INDEX, new_range(REDUCE | INDEX, (yyvsp[-5].rval)),
		    new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4839 "gram.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1132 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOOKUP, new_range(REDUCE | LOOKUP, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4845 "gram.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1134 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOOKUP, new_range(REDUCE | LOOKUP, (yyvsp[-1].rval)), (yyvsp[-3].enode)); }
#line 4851 "gram.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1136 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(HLOOKUP, new_range(REDUCE | HLOOKUP, (yyvsp[-5].rval)),
		    new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4858 "gram.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1139 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(HLOOKUP, new_range(REDUCE | HLOOKUP, (yyvsp[-3].rval)),
		    new(',', (yyvsp[-5].enode), (yyvsp[-1].enode))); }
#line 4865 "gram.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1142 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(VLOOKUP, new_range(REDUCE | VLOOKUP, (yyvsp[-5].rval)),
		    new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4872 "gram.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1145 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(VLOOKUP, new_range(REDUCE | VLOOKUP, (yyvsp[-3].rval)),
		    new(',', (yyvsp[-5].enode), (yyvsp[-1].enode))); }
#line 4879 "gram.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1148 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(STINDEX, new_range(REDUCE | STINDEX, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4885 "gram.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1150 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(STINDEX, new_range(REDUCE | STINDEX, (yyvsp[-1].rval)), (yyvsp[-3].enode)); }
#line 4891 "gram.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1152 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(STINDEX, new_range(REDUCE | STINDEX, (yyvsp[-5].rval)),
		    new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4898 "gram.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1154 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(EXT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4904 "gram.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1155 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LUA, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4910 "gram.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1156 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(NVAL, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4916 "gram.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1157 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SVAL, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4922 "gram.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1159 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SUBSTR, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4928 "gram.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1160 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = (yyvsp[-1].enode); }
#line 4934 "gram.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1161 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = (yyvsp[0].enode); }
#line 4940 "gram.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1162 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('m', (yyvsp[0].enode), ENULL); }
#line 4946 "gram.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1163 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_const(O_CONST, (double) (yyvsp[0].ival)); }
#line 4952 "gram.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1164 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_const(O_CONST, (yyvsp[0].fval)); }
#line 4958 "gram.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1165 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(PI_, ENULL, ENULL); }
#line 4964 "gram.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1166 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_str((yyvsp[0].sval)); }
#line 4970 "gram.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1167 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('!', (yyvsp[0].enode), ENULL); }
#line 4976 "gram.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1168 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('!', (yyvsp[0].enode), ENULL); }
#line 4982 "gram.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1169 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FILENAME, (yyvsp[-1].enode), ENULL); }
#line 4988 "gram.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1170 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MYROW, ENULL, ENULL);}
#line 4994 "gram.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1171 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MYCOL, ENULL, ENULL);}
#line 5000 "gram.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1172 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LASTROW, ENULL, ENULL);}
#line 5006 "gram.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1173 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LASTCOL, ENULL, ENULL);}
#line 5012 "gram.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1174 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(COLTOA, (yyvsp[-1].enode), ENULL);}
#line 5018 "gram.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1175 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(NUMITER, ENULL, ENULL);}
#line 5024 "gram.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1176 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ERR_, ENULL, ENULL); }
#line 5030 "gram.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1177 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ERR_, ENULL, ENULL); }
#line 5036 "gram.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1178 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(BLACK, ENULL, ENULL); }
#line 5042 "gram.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1179 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(RED, ENULL, ENULL); }
#line 5048 "gram.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1180 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(GREEN, ENULL, ENULL); }
#line 5054 "gram.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1181 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(YELLOW, ENULL, ENULL); }
#line 5060 "gram.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1182 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(BLUE, ENULL, ENULL); }
#line 5066 "gram.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1183 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MAGENTA, ENULL, ENULL); }
#line 5072 "gram.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1184 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(CYAN, ENULL, ENULL); }
#line 5078 "gram.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1185 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(WHITE, ENULL, ENULL); }
#line 5084 "gram.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1189 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('+', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5090 "gram.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1190 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('-', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5096 "gram.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1191 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('*', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5102 "gram.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1192 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('/', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5108 "gram.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1193 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('%', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5114 "gram.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1194 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('^', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5120 "gram.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1196 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('?', (yyvsp[-4].enode), new(':', (yyvsp[-2].enode), (yyvsp[0].enode))); }
#line 5126 "gram.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1197 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(';', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5132 "gram.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1198 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('<', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5138 "gram.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1199 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('=', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5144 "gram.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1200 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('>', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5150 "gram.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1201 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('&', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5156 "gram.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1202 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('|', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5162 "gram.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1203 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('!', new('>', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5168 "gram.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1204 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('!', new('=', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5174 "gram.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1205 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('!', new('=', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5180 "gram.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1206 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('!', new('<', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5186 "gram.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1207 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new('#', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5192 "gram.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1210 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ELIST, ENULL, (yyvsp[0].enode)); }
#line 5198 "gram.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1211 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ELIST, (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5204 "gram.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1214 "gram.y" /* yacc.c:1646  */
    { (yyval.rval).left = (yyvsp[-2].ent); (yyval.rval).right = (yyvsp[0].ent); }
#line 5210 "gram.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1215 "gram.y" /* yacc.c:1646  */
    { (yyval.rval) = (yyvsp[0].rval); }
#line 5216 "gram.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1218 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival), (yyvsp[-1].ival)); (yyval.ent).vf = 0; }
#line 5222 "gram.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1219 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival), (yyvsp[-1].ival));
					(yyval.ent).vf = FIX_COL; }
#line 5229 "gram.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1221 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival), (yyvsp[-2].ival));
					(yyval.ent).vf = FIX_ROW; }
#line 5236 "gram.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1223 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival), (yyvsp[-2].ival));
					(yyval.ent).vf = FIX_ROW | FIX_COL; }
#line 5243 "gram.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1225 "gram.y" /* yacc.c:1646  */
    { (yyval.ent) = (yyvsp[0].rval).left; }
#line 5249 "gram.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1228 "gram.y" /* yacc.c:1646  */
    { (yyval.rval) = (yyvsp[0].rval); }
#line 5255 "gram.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1229 "gram.y" /* yacc.c:1646  */
    { (yyval.rval).left = (yyvsp[0].ent); (yyval.rval).right = (yyvsp[0].ent); }
#line 5261 "gram.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1232 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = (double) (yyvsp[0].ival); }
#line 5267 "gram.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1233 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = (yyvsp[0].fval); }
#line 5273 "gram.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1234 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = -(yyvsp[0].fval); }
#line 5279 "gram.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1235 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = (yyvsp[0].fval); }
#line 5285 "gram.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1238 "gram.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 5291 "gram.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1239 "gram.y" /* yacc.c:1646  */
    {
				    char *s, *s1;
				    s1 = (yyvsp[0].ent).vp->label;
				    if (!s1)
					s1 = "NULL_STRING";
				    s = scxmalloc((unsigned)strlen(s1)+1);
				    (void) strcpy(s, s1);
				    (yyval.sval) = s;
				}
#line 5305 "gram.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1256 "gram.y" /* yacc.c:1646  */
    { setauto(1); }
#line 5311 "gram.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1257 "gram.y" /* yacc.c:1646  */
    { setauto(1); }
#line 5317 "gram.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1258 "gram.y" /* yacc.c:1646  */
    { setauto(0); }
#line 5323 "gram.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1259 "gram.y" /* yacc.c:1646  */
    { setauto(0); }
#line 5329 "gram.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1260 "gram.y" /* yacc.c:1646  */
    { setauto(0); }
#line 5335 "gram.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1261 "gram.y" /* yacc.c:1646  */
    { setauto(0); }
#line 5341 "gram.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1262 "gram.y" /* yacc.c:1646  */
    { setorder(BYCOLS); }
#line 5347 "gram.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1263 "gram.y" /* yacc.c:1646  */
    { setorder(BYROWS); }
#line 5353 "gram.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1264 "gram.y" /* yacc.c:1646  */
    { optimize = 1; }
#line 5359 "gram.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1265 "gram.y" /* yacc.c:1646  */
    { optimize = 0; }
#line 5365 "gram.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1266 "gram.y" /* yacc.c:1646  */
    { optimize = 0; }
#line 5371 "gram.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1267 "gram.y" /* yacc.c:1646  */
    { numeric = 1; }
#line 5377 "gram.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1268 "gram.y" /* yacc.c:1646  */
    { numeric = 0; }
#line 5383 "gram.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1269 "gram.y" /* yacc.c:1646  */
    { numeric = 0; }
#line 5389 "gram.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1270 "gram.y" /* yacc.c:1646  */
    { prescale = 0.01; }
#line 5395 "gram.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1271 "gram.y" /* yacc.c:1646  */
    { prescale = 1.0; }
#line 5401 "gram.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1272 "gram.y" /* yacc.c:1646  */
    { prescale = 1.0; }
#line 5407 "gram.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1273 "gram.y" /* yacc.c:1646  */
    { extfunc = 1; }
#line 5413 "gram.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1274 "gram.y" /* yacc.c:1646  */
    { extfunc = 0; }
#line 5419 "gram.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1275 "gram.y" /* yacc.c:1646  */
    { extfunc = 0; }
#line 5425 "gram.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1276 "gram.y" /* yacc.c:1646  */
    { showcell = 1; }
#line 5431 "gram.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1277 "gram.y" /* yacc.c:1646  */
    { showcell = 0; }
#line 5437 "gram.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1278 "gram.y" /* yacc.c:1646  */
    { showcell = 0; }
#line 5443 "gram.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1279 "gram.y" /* yacc.c:1646  */
    { showtop = 1; }
#line 5449 "gram.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1280 "gram.y" /* yacc.c:1646  */
    { showtop = 0; }
#line 5455 "gram.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1281 "gram.y" /* yacc.c:1646  */
    { showtop = 0; }
#line 5461 "gram.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1282 "gram.y" /* yacc.c:1646  */
    { autoinsert = 1; }
#line 5467 "gram.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1283 "gram.y" /* yacc.c:1646  */
    { autoinsert = 0; }
#line 5473 "gram.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1284 "gram.y" /* yacc.c:1646  */
    { autoinsert = 0; }
#line 5479 "gram.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1285 "gram.y" /* yacc.c:1646  */
    { autowrap = 1; }
#line 5485 "gram.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1286 "gram.y" /* yacc.c:1646  */
    { autowrap = 0; }
#line 5491 "gram.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1287 "gram.y" /* yacc.c:1646  */
    { autowrap = 0; }
#line 5497 "gram.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1288 "gram.y" /* yacc.c:1646  */
    { cslop = 0; }
#line 5503 "gram.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1289 "gram.y" /* yacc.c:1646  */
    { cslop = 1; }
#line 5509 "gram.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1290 "gram.y" /* yacc.c:1646  */
    { cslop = 1; }
#line 5515 "gram.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1291 "gram.y" /* yacc.c:1646  */
    { color = 1;
					  if (usecurses && has_colors()) {
					    color_set(1, NULL);
					    bkgd(COLOR_PAIR(1) | ' ');
					    FullUpdate++;
					  }
					}
#line 5527 "gram.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1298 "gram.y" /* yacc.c:1646  */
    { color = 0;
					  if (usecurses && has_colors()) {
					    color_set(0, NULL);
					    bkgd(COLOR_PAIR(0) | ' ');
					  }
					}
#line 5538 "gram.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1304 "gram.y" /* yacc.c:1646  */
    { color = 0;
					  if (usecurses && has_colors()) {
					    color_set(0, NULL);
					    bkgd(COLOR_PAIR(0) | ' ');
					  }
					}
#line 5549 "gram.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1310 "gram.y" /* yacc.c:1646  */
    { colorneg = 1; }
#line 5555 "gram.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1311 "gram.y" /* yacc.c:1646  */
    { colorneg = 0; }
#line 5561 "gram.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1312 "gram.y" /* yacc.c:1646  */
    { colorneg = 0; }
#line 5567 "gram.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1313 "gram.y" /* yacc.c:1646  */
    { colorerr = 1; }
#line 5573 "gram.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1314 "gram.y" /* yacc.c:1646  */
    { colorerr = 0; }
#line 5579 "gram.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1315 "gram.y" /* yacc.c:1646  */
    { colorerr = 0; }
#line 5585 "gram.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1316 "gram.y" /* yacc.c:1646  */
    { braille = 1; }
#line 5591 "gram.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1317 "gram.y" /* yacc.c:1646  */
    { braille = 0; }
#line 5597 "gram.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1318 "gram.y" /* yacc.c:1646  */
    { braille = 0; }
#line 5603 "gram.c" /* yacc.c:1646  */
    break;

  case 404:
#line 1319 "gram.y" /* yacc.c:1646  */
    { setiterations((yyvsp[0].ival)); }
#line 5609 "gram.c" /* yacc.c:1646  */
    break;

  case 405:
#line 1320 "gram.y" /* yacc.c:1646  */
    { tbl_style = (yyvsp[0].ival); }
#line 5615 "gram.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1321 "gram.y" /* yacc.c:1646  */
    { tbl_style = TBL; }
#line 5621 "gram.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1322 "gram.y" /* yacc.c:1646  */
    { tbl_style = LATEX; }
#line 5627 "gram.c" /* yacc.c:1646  */
    break;

  case 408:
#line 1323 "gram.y" /* yacc.c:1646  */
    { tbl_style = SLATEX; }
#line 5633 "gram.c" /* yacc.c:1646  */
    break;

  case 409:
#line 1324 "gram.y" /* yacc.c:1646  */
    { tbl_style = TEX; }
#line 5639 "gram.c" /* yacc.c:1646  */
    break;

  case 410:
#line 1325 "gram.y" /* yacc.c:1646  */
    { tbl_style = FRAME; }
#line 5645 "gram.c" /* yacc.c:1646  */
    break;

  case 411:
#line 1326 "gram.y" /* yacc.c:1646  */
    { rndtoeven = 1; FullUpdate++; }
#line 5651 "gram.c" /* yacc.c:1646  */
    break;

  case 412:
#line 1327 "gram.y" /* yacc.c:1646  */
    { rndtoeven = 0; FullUpdate++; }
#line 5657 "gram.c" /* yacc.c:1646  */
    break;

  case 413:
#line 1328 "gram.y" /* yacc.c:1646  */
    { rndtoeven = 0; FullUpdate++; }
#line 5663 "gram.c" /* yacc.c:1646  */
    break;

  case 414:
#line 1329 "gram.y" /* yacc.c:1646  */
    { craction = (yyvsp[0].ival); }
#line 5669 "gram.c" /* yacc.c:1646  */
    break;

  case 415:
#line 1330 "gram.y" /* yacc.c:1646  */
    { rowlimit = (yyvsp[0].ival); }
#line 5675 "gram.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1331 "gram.y" /* yacc.c:1646  */
    { collimit = (yyvsp[0].ival); }
#line 5681 "gram.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1332 "gram.y" /* yacc.c:1646  */
    { pagesize = (yyvsp[0].ival); }
#line 5687 "gram.c" /* yacc.c:1646  */
    break;

  case 418:
#line 1333 "gram.y" /* yacc.c:1646  */
    { scrc++; }
#line 5693 "gram.c" /* yacc.c:1646  */
    break;

  case 419:
#line 1334 "gram.y" /* yacc.c:1646  */
    {
#ifdef USELOCALE
					  struct  lconv *locstruct;
					  char    *loc;

					  loc = setlocale(LC_ALL, "");
					  if (loc != NULL) {
					    locstruct = localeconv();
					    dpoint = (locstruct->decimal_point)[0];
					    thsep = (locstruct->thousands_sep)[0];
					  }
					  else {
					    dpoint = '.';
					    thsep = ',';
					  }
					  FullUpdate++;
#else
					  error("Locale support not available");
#endif
					}
#line 5718 "gram.c" /* yacc.c:1646  */
    break;

  case 420:
#line 1354 "gram.y" /* yacc.c:1646  */
    {
					  dpoint = '.';
					  thsep = ',';
					  FullUpdate++;
					}
#line 5728 "gram.c" /* yacc.c:1646  */
    break;

  case 421:
#line 1359 "gram.y" /* yacc.c:1646  */
    {
					  dpoint = '.';
					  thsep = ',';
					  FullUpdate++;
					}
#line 5738 "gram.c" /* yacc.c:1646  */
    break;

  case 422:
#line 1367 "gram.y" /* yacc.c:1646  */
    { num_search((double)0,
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
					  (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col,
					  CELLERROR); }
#line 5747 "gram.c" /* yacc.c:1646  */
    break;

  case 423:
#line 1371 "gram.y" /* yacc.c:1646  */
    { num_search((double)0, 0, 0,
					  maxrow, maxcol, CELLERROR); }
#line 5754 "gram.c" /* yacc.c:1646  */
    break;

  case 424:
#line 1373 "gram.y" /* yacc.c:1646  */
    { num_search((double)0,
					  (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col,
					  (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col,
					  CELLINVALID); }
#line 5763 "gram.c" /* yacc.c:1646  */
    break;

  case 425:
#line 1377 "gram.y" /* yacc.c:1646  */
    { num_search((double)0, 0, 0,
					  maxrow, maxcol, CELLINVALID); }
#line 5770 "gram.c" /* yacc.c:1646  */
    break;


#line 5774 "gram.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
