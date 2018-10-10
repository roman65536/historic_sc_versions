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
#include "sc.h"

#define ENULL (struct enode *)0

char *strcpy();

#line 75 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    COL = 264,
    S_FORMAT = 265,
    S_LABEL = 266,
    S_LEFTSTRING = 267,
    S_RIGHTSTRING = 268,
    S_GET = 269,
    S_PUT = 270,
    S_MERGE = 271,
    S_LET = 272,
    S_WRITE = 273,
    S_TBL = 274,
    S_COPY = 275,
    S_SHOW = 276,
    S_ERASE = 277,
    S_FILL = 278,
    S_GOTO = 279,
    S_DEFINE = 280,
    S_UNDEFINE = 281,
    S_VALUE = 282,
    S_MDIR = 283,
    S_HIDE = 284,
    S_SET = 285,
    K_FIXED = 286,
    K_SUM = 287,
    K_PROD = 288,
    K_AVG = 289,
    K_STDDEV = 290,
    K_COUNT = 291,
    K_ABS = 292,
    K_ACOS = 293,
    K_ASIN = 294,
    K_ATAN = 295,
    K_ATAN2 = 296,
    K_CEIL = 297,
    K_COS = 298,
    K_EXP = 299,
    K_FABS = 300,
    K_FLOOR = 301,
    K_HYPOT = 302,
    K_LN = 303,
    K_LOG = 304,
    K_PI = 305,
    K_POW = 306,
    K_SIN = 307,
    K_SQRT = 308,
    K_TAN = 309,
    K_DTR = 310,
    K_RTD = 311,
    K_MAX = 312,
    K_MIN = 313,
    K_RND = 314,
    K_ROUND = 315,
    K_IF = 316,
    K_PV = 317,
    K_FV = 318,
    K_PMT = 319,
    K_HOUR = 320,
    K_MINUTE = 321,
    K_SECOND = 322,
    K_MONTH = 323,
    K_DAY = 324,
    K_YEAR = 325,
    K_NOW = 326,
    K_DATE = 327,
    K_DTS = 328,
    K_TTS = 329,
    K_FMT = 330,
    K_SUBSTR = 331,
    K_STON = 332,
    K_EQS = 333,
    K_EXT = 334,
    K_NVAL = 335,
    K_SVAL = 336,
    K_LOOKUP = 337,
    K_HLOOKUP = 338,
    K_VLOOKUP = 339,
    K_INDEX = 340,
    K_STINDEX = 341,
    K_AUTO = 342,
    K_AUTOCALC = 343,
    K_BYROWS = 344,
    K_BYCOLS = 345,
    K_BYGRAPH = 346,
    K_ITERATIONS = 347,
    K_NUMERIC = 348,
    K_PRESCALE = 349,
    K_EXTFUN = 350,
    K_CELLCUR = 351,
    K_TOPROW = 352,
    K_TBLSTYLE = 353,
    K_TBL = 354,
    K_LATEX = 355,
    K_TEX = 356
  };
#endif
/* Tokens.  */
#define STRING 258
#define NUMBER 259
#define FNUMBER 260
#define RANGE 261
#define VAR 262
#define WORD 263
#define COL 264
#define S_FORMAT 265
#define S_LABEL 266
#define S_LEFTSTRING 267
#define S_RIGHTSTRING 268
#define S_GET 269
#define S_PUT 270
#define S_MERGE 271
#define S_LET 272
#define S_WRITE 273
#define S_TBL 274
#define S_COPY 275
#define S_SHOW 276
#define S_ERASE 277
#define S_FILL 278
#define S_GOTO 279
#define S_DEFINE 280
#define S_UNDEFINE 281
#define S_VALUE 282
#define S_MDIR 283
#define S_HIDE 284
#define S_SET 285
#define K_FIXED 286
#define K_SUM 287
#define K_PROD 288
#define K_AVG 289
#define K_STDDEV 290
#define K_COUNT 291
#define K_ABS 292
#define K_ACOS 293
#define K_ASIN 294
#define K_ATAN 295
#define K_ATAN2 296
#define K_CEIL 297
#define K_COS 298
#define K_EXP 299
#define K_FABS 300
#define K_FLOOR 301
#define K_HYPOT 302
#define K_LN 303
#define K_LOG 304
#define K_PI 305
#define K_POW 306
#define K_SIN 307
#define K_SQRT 308
#define K_TAN 309
#define K_DTR 310
#define K_RTD 311
#define K_MAX 312
#define K_MIN 313
#define K_RND 314
#define K_ROUND 315
#define K_IF 316
#define K_PV 317
#define K_FV 318
#define K_PMT 319
#define K_HOUR 320
#define K_MINUTE 321
#define K_SECOND 322
#define K_MONTH 323
#define K_DAY 324
#define K_YEAR 325
#define K_NOW 326
#define K_DATE 327
#define K_DTS 328
#define K_TTS 329
#define K_FMT 330
#define K_SUBSTR 331
#define K_STON 332
#define K_EQS 333
#define K_EXT 334
#define K_NVAL 335
#define K_SVAL 336
#define K_LOOKUP 337
#define K_HLOOKUP 338
#define K_VLOOKUP 339
#define K_INDEX 340
#define K_STINDEX 341
#define K_AUTO 342
#define K_AUTOCALC 343
#define K_BYROWS 344
#define K_BYCOLS 345
#define K_BYGRAPH 346
#define K_ITERATIONS 347
#define K_NUMERIC 348
#define K_PRESCALE 349
#define K_EXTFUN 350
#define K_CELLCUR 351
#define K_TOPROW 352
#define K_TBLSTYLE 353
#define K_TBL 354
#define K_LATEX 355
#define K_TEX 356

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 26 "gram.y" /* yacc.c:355  */

    int ival;
    double fval;
    struct ent_ptr ent;
    struct enode *enode;
    char *sval;
    struct range_s rval;

#line 326 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 341 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1811

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  473

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   356

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   109,     2,   112,   122,   115,   105,     2,
     118,   119,   113,   110,   120,   111,     2,   114,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   103,     2,
     106,   107,   108,   102,   117,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   116,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   104,     2,   121,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   153,   153,   155,   157,   159,   161,   163,   165,   172,
     178,   180,   185,   188,   192,   194,   198,   200,   202,   204,
     206,   208,   211,   214,   216,   218,   222,   224,   226,   227,
     228,   229,   230,   237,   238,   239,   240,   241,   242,   244,
     245,   246,   248,   250,   252,   254,   256,   258,   260,   262,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   287,   288,   289,   291,   292,   293,   294,   295,
     296,   297,   298,   300,   302,   303,   304,   305,   306,   308,
     310,   313,   316,   318,   319,   320,   321,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   353,   354,   357,   358,   361,   362,   364,
     366,   368,   371,   372,   375,   376,   377,   378,   381,   382,
     393,   394,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "NUMBER", "FNUMBER", "RANGE",
  "VAR", "WORD", "COL", "S_FORMAT", "S_LABEL", "S_LEFTSTRING",
  "S_RIGHTSTRING", "S_GET", "S_PUT", "S_MERGE", "S_LET", "S_WRITE",
  "S_TBL", "S_COPY", "S_SHOW", "S_ERASE", "S_FILL", "S_GOTO", "S_DEFINE",
  "S_UNDEFINE", "S_VALUE", "S_MDIR", "S_HIDE", "S_SET", "K_FIXED", "K_SUM",
  "K_PROD", "K_AVG", "K_STDDEV", "K_COUNT", "K_ABS", "K_ACOS", "K_ASIN",
  "K_ATAN", "K_ATAN2", "K_CEIL", "K_COS", "K_EXP", "K_FABS", "K_FLOOR",
  "K_HYPOT", "K_LN", "K_LOG", "K_PI", "K_POW", "K_SIN", "K_SQRT", "K_TAN",
  "K_DTR", "K_RTD", "K_MAX", "K_MIN", "K_RND", "K_ROUND", "K_IF", "K_PV",
  "K_FV", "K_PMT", "K_HOUR", "K_MINUTE", "K_SECOND", "K_MONTH", "K_DAY",
  "K_YEAR", "K_NOW", "K_DATE", "K_DTS", "K_TTS", "K_FMT", "K_SUBSTR",
  "K_STON", "K_EQS", "K_EXT", "K_NVAL", "K_SVAL", "K_LOOKUP", "K_HLOOKUP",
  "K_VLOOKUP", "K_INDEX", "K_STINDEX", "K_AUTO", "K_AUTOCALC", "K_BYROWS",
  "K_BYCOLS", "K_BYGRAPH", "K_ITERATIONS", "K_NUMERIC", "K_PRESCALE",
  "K_EXTFUN", "K_CELLCUR", "K_TOPROW", "K_TBLSTYLE", "K_TBL", "K_LATEX",
  "K_TEX", "'?'", "':'", "'|'", "'&'", "'<'", "'='", "'>'", "'!'", "'+'",
  "'-'", "'#'", "'*'", "'/'", "'%'", "'^'", "'@'", "'('", "')'", "','",
  "'~'", "'$'", "$accept", "command", "term", "e", "expr_list", "range",
  "var", "var_or_range", "num", "strarg", "setlist", "setitem", YY_NULLPTR
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
     355,   356,    63,    58,   124,    38,    60,    61,    62,    33,
      43,    45,    35,    42,    47,    37,    94,    64,    40,    41,
      44,   126,    36
};
# endif

#define YYPACT_NINF -161

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-161)))

#define YYTABLE_NINF -134

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-134)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     488,  -161,    22,    45,    45,    45,    33,    33,    33,    45,
      33,    33,    45,    37,    45,   101,    88,    33,    45,    45,
      33,    46,  -161,    70,     6,  -161,  -161,    21,    66,  -161,
     -26,   -23,   -21,   -11,  -161,  -161,  -161,    45,  -161,    -9,
      45,    45,    45,   -26,    -4,    -2,  -161,  -161,  -161,    78,
      78,    78,    78,  -161,  -161,  -161,    45,  -161,  -161,  -161,
    -161,  -161,   357,  -161,    98,    94,  -161,   107,    23,    55,
      69,    69,    69,  -161,    69,  -161,  -161,  -161,   112,   109,
    -161,  -161,    78,  -161,  -161,   -26,  -161,  -161,  -161,  -161,
    -161,    18,  -161,  -161,  -161,  -161,  -161,    26,   297,   -19,
    -161,  -161,   125,  -161,  -161,   132,  -161,  -161,  -161,  -161,
      69,  -161,    69,    69,    69,   294,    69,    69,  -161,  1648,
    -161,  1648,  1648,  1648,  -161,  -161,  -161,   138,    31,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,   140,  -161,
    -161,  -161,  -161,  -161,    28,    30,    34,    36,    42,    67,
      76,    79,    82,    83,    85,    86,    89,    90,    91,    95,
      96,    97,   104,   106,   108,   110,   111,   113,   114,   115,
     121,   122,   131,   139,   142,   143,   144,   145,   146,   147,
     148,   149,  -161,   198,   199,   200,   201,   203,   204,   206,
     226,   263,   264,   265,   268,   269,   270,   277,   927,  -161,
      69,    69,    69,    17,    69,    40,    99,    69,    69,    69,
      69,    69,    69,    69,  -161,  -161,  -161,  -161,  -161,  -161,
      45,    45,    45,    45,    45,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    54,    54,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,  -161,  1633,  1673,  1684,    69,  1695,  1695,
      69,  1695,    69,    68,    68,    68,    58,    58,    58,  -161,
     284,   285,   286,   287,   288,   943,   959,   975,   991,   417,
    1007,  1023,  1039,  1055,  1071,   434,  1087,  1103,   451,  1119,
    1135,  1151,  1167,  1183,   468,   -38,   290,   485,   291,  1199,
     502,   519,   536,   553,   570,  1215,  1231,  1247,  1263,  1279,
    1295,  1311,   587,   604,   621,   638,  1327,   655,   672,   689,
     706,   723,   740,   757,   774,   791,    69,  1695,  1695,  1695,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,    69,
    -161,  -161,  -161,  -161,  -161,    69,  -161,  -161,    69,  -161,
    -161,  -161,  -161,  -161,    69,  -161,    69,  -161,  -161,    69,
      69,    69,    69,    69,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,    69,    69,    69,    69,  -161,    69,    69,    69,    69,
      45,    45,    45,    45,    45,  1661,  1343,  1359,  1375,  1648,
     -40,   -31,  1391,   808,   825,   842,   859,   876,   893,  1407,
     910,  1423,  1439,  1455,  1471,   293,   105,   276,   300,   301,
    -161,  -161,  -161,  -161,    69,  -161,  -161,    69,    69,    69,
      69,    69,    69,  -161,    69,  -161,  -161,  -161,  -161,  -161,
      69,    69,  -161,  -161,  1648,  1487,  1503,  1519,  1535,  1551,
    1567,  1583,  1599,  1615,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,    31,     0,     0,    24,
       0,     0,   140,     0,     0,   126,   131,     0,     0,   132,
     133,     0,     0,     0,   138,   139,     8,    12,     9,     0,
      14,    16,     0,     0,     0,     0,    23,   134,   135,     0,
       0,     0,     0,    30,    28,    29,    32,    35,    25,    10,
      20,    19,    36,     1,     0,     0,   127,     0,     0,     0,
       0,     0,     0,    11,     0,    13,    15,    21,     0,     0,
     137,   136,     0,    26,    33,    34,   142,   143,   149,   148,
     150,     0,   151,   153,   155,   157,   159,     0,     0,     0,
     141,     7,     0,   129,   128,     0,   125,   103,   100,   101,
       0,   102,     0,     0,     0,     0,     0,     0,   112,     3,
      39,     4,     5,     2,    18,    17,    27,     0,     0,   146,
     147,   152,   154,   156,   158,   160,   144,   145,     0,   130,
      40,   105,    98,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   162,   163,   164,   165,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,   118,   117,     0,   114,   115,
       0,   116,     0,   106,   107,   122,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   121,   120,
      41,    42,    43,    44,    45,    50,    51,    52,    53,     0,
      55,    56,    57,    58,    59,     0,    61,    62,     0,    64,
      65,    66,    67,    68,     0,    46,     0,    48,    69,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      86,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    60,    63,    47,     0,    49,    70,     0,     0,     0,
       0,     0,     0,    87,     0,    85,    93,    94,    95,    89,
       0,     0,    88,    92,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    82,    83,
      96,    90,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,    56,    43,  -160,   100,    -3,    14,    71,   185,
    -161,  -161
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,   118,   409,   410,    29,   120,    31,    52,    36,
      62,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    30,    30,    35,    35,    35,    30,    35,    35,    43,
      64,    30,    30,    30,    35,    30,    30,    35,    32,    33,
     107,   108,   109,    39,    26,    66,    27,   104,    46,    51,
      54,    24,    57,    58,    43,   215,    34,    43,    43,    30,
      26,    44,    27,   107,   108,   109,    45,    26,   110,    27,
      60,    25,    26,    85,    27,    61,    77,   107,   108,   109,
      25,    26,    26,    27,    27,    69,   106,   111,   136,   137,
      63,   110,   107,   108,   109,    68,    26,    69,    27,   433,
     434,  -133,    47,    48,    70,   110,    71,    55,   435,   434,
     111,    53,    47,    48,    25,    26,    72,    27,    74,    78,
     110,    79,   101,   102,   111,    47,    48,    25,    26,    65,
      27,   103,    42,   119,   121,   122,   124,   123,   125,   111,
      80,    81,    82,    83,   277,   127,   112,   113,   114,   138,
     216,   217,   218,   128,   115,   116,   139,    73,   117,    28,
      75,    76,   214,    67,   219,   105,   220,   280,   221,   112,
     113,   114,   222,   126,   223,    28,    84,   115,   116,   198,
     224,   117,    28,   112,   113,   114,   140,    28,   141,   142,
     143,   115,   116,   199,   213,   117,    28,    28,   112,   113,
     114,   210,   211,   212,   213,   225,   115,   116,    49,    50,
     117,    28,    37,    38,   226,    40,    41,   227,    49,    50,
     228,   229,    56,   230,   231,    59,   282,   232,   233,   234,
      28,    49,    50,   235,   236,   237,   411,    30,    30,    30,
      30,    30,   238,    28,   239,   450,   240,     0,   241,   242,
       0,   243,   244,   245,   290,   291,   292,   293,   294,   246,
     247,   315,   315,   274,   275,   276,   278,   279,   281,   248,
     283,   284,   285,   286,   287,   288,   289,   249,   316,   318,
     250,   251,   252,   253,   254,   255,   256,   257,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   317,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   258,   259,   260,   261,
     347,   262,   263,   348,   264,   349,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   265,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   266,   267,   268,   129,   130,   269,   270,   271,   405,
     131,   132,   133,   134,   135,   272,   451,    30,    30,    30,
      30,    30,   406,   350,   351,   352,   353,   354,   407,   375,
     377,   408,   449,     0,   425,   426,   427,   428,   429,   452,
     453,     0,   412,   413,   414,   415,   416,     0,     0,     0,
       0,     0,     0,     0,   417,   418,   419,   420,     0,   421,
     422,   423,   424,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   454,    99,     0,
     455,   456,   457,   458,   459,   460,     0,   461,   -37,     1,
       0,     0,     0,   462,   463,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   200,
       0,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,     0,   200,   359,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,     0,     0,   200,   365,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,     0,
     200,   368,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,     0,     0,   200,   374,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,     0,   200,   376,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,     0,
       0,   200,   379,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,     0,   200,   380,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,     0,   200,   381,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,     0,   200,   382,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,     0,     0,   200,
     383,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,     0,   200,   391,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,     0,     0,   200,   392,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,     0,
     200,   393,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,     0,     0,   200,   394,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,     0,   200,   396,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,     0,
       0,   200,   397,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,     0,   200,   398,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,     0,   200,   399,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,     0,   200,   400,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,     0,     0,   200,
     401,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,     0,   200,   402,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,     0,     0,   200,   403,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,     0,
     200,   404,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,     0,     0,   200,   437,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,     0,   200,   438,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,     0,
       0,   200,   439,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,     0,   200,   440,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,     0,   200,   441,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,     0,   200,   442,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,     0,     0,   200,
     444,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   200,   273,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   200,   355,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   200,   356,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   200,   357,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   200,
     358,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   200,   360,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   200,   361,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   200,   362,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   200,   363,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   200,
     364,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   200,   366,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   200,   367,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   200,   369,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   200,   370,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   200,
     371,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   200,   372,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   200,   373,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   200,   378,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   200,   384,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   200,
     385,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   200,   386,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   200,   387,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   200,   388,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   200,   389,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   200,
     390,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   200,   395,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   200,   430,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   200,   431,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   200,   432,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   200,
     436,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   200,   443,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   200,   445,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   200,   446,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   200,   447,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   200,
     448,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   200,   464,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   200,   465,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   200,   466,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   200,   467,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   200,
     468,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   200,   469,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   200,   470,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   200,   471,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,     0,   472,   200,   346,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     200,     0,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,  -134,  -134,  -134,  -134,   207,   208,   209,   210,   211,
     212,   213
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       4,    14,    15,    16,    17,    18,    19,    20,     4,     5,
       3,     4,     5,     9,     7,     4,     9,     4,    14,    15,
      16,     9,    18,    19,    37,     4,     3,    40,    41,    42,
       7,     4,     9,     3,     4,     5,     9,     7,    31,     9,
       4,     6,     7,    56,     9,     9,    42,     3,     4,     5,
       6,     7,     7,     9,     9,   103,    69,    50,    87,    88,
       0,    31,     3,     4,     5,     9,     7,   103,     9,   119,
     120,   119,     4,     5,   107,    31,   107,    16,   119,   120,
      50,     3,     4,     5,     6,     7,   107,     9,   107,   103,
      31,   103,     4,     9,    50,     4,     5,     6,     7,   103,
       9,     4,    12,    70,    71,    72,     4,    74,     9,    50,
      49,    50,    51,    52,   107,   107,   109,   110,   111,     4,
      99,   100,   101,   107,   117,   118,     4,    37,   121,   122,
      40,    41,     4,   122,     4,   122,   118,   107,   118,   109,
     110,   111,   118,    82,   118,   122,    56,   117,   118,   116,
     118,   121,   122,   109,   110,   111,   110,   122,   112,   113,
     114,   117,   118,   117,   116,   121,   122,   122,   109,   110,
     111,   113,   114,   115,   116,   118,   117,   118,   110,   111,
     121,   122,     7,     8,   118,    10,    11,   118,   110,   111,
     118,   118,    17,   118,   118,    20,   107,   118,   118,   118,
     122,   110,   111,   118,   118,   118,   376,   220,   221,   222,
     223,   224,   118,   122,   118,   120,   118,    -1,   118,   118,
      -1,   118,   118,   118,   220,   221,   222,   223,   224,   118,
     118,   244,   245,   200,   201,   202,   203,   204,   205,   118,
     207,   208,   209,   210,   211,   212,   213,   118,   244,   245,
     118,   118,   118,   118,   118,   118,   118,   118,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   118,   118,   118,   118,
     277,   118,   118,   280,   118,   282,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   118,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,   118,   118,   118,    87,    88,   118,   118,   118,   346,
      93,    94,    95,    96,    97,   118,   120,   400,   401,   402,
     403,   404,   359,   119,   119,   119,   119,   119,   365,   119,
     119,   368,   119,    -1,   400,   401,   402,   403,   404,   119,
     119,    -1,   379,   380,   381,   382,   383,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   391,   392,   393,   394,    -1,   396,
     397,   398,   399,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,   121,    -1,
     437,   438,   439,   440,   441,   442,    -1,   444,     0,     1,
      -1,    -1,    -1,   450,   451,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,   102,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,   102,   120,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,   102,   120,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
     102,   120,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,   102,   120,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,   102,   120,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,   102,   120,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,   102,   120,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,   102,   120,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,   102,   120,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,   102,
     120,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,   102,   120,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,   102,   120,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
     102,   120,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,   102,   120,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,   102,   120,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,   102,   120,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,   102,   120,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,   102,   120,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,   102,   120,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,   102,
     120,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,   102,   120,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,   102,   120,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
     102,   120,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,   102,   120,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,   102,   120,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,   102,   120,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,   102,   120,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,   102,   120,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,   102,   120,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,   102,
     120,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   102,   119,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   102,   119,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   102,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   102,   119,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   102,
     119,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   102,   119,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   102,   119,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   102,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   102,   119,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   102,
     119,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   102,   119,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   102,   119,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   102,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   102,   119,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   102,
     119,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   102,   119,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   102,   119,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   102,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   102,   119,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   102,
     119,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   102,   119,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   102,   119,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   102,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   102,   119,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   102,
     119,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   102,   119,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   102,   119,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   102,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   102,   119,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   102,
     119,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   102,   119,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   102,   119,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   102,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   102,   119,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   102,
     119,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   102,   119,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   102,   119,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   102,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   102,   119,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   102,
     119,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   102,   119,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   102,   119,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   102,   119,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,   119,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     102,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   124,     9,     6,     7,     9,   122,   128,
     129,   130,   130,   130,     3,   129,   132,   132,   132,   130,
     132,   132,   128,   129,     4,     9,   130,     4,     5,   110,
     111,   130,   131,     3,   130,   131,   132,   130,   130,   132,
       4,     9,   133,     0,     4,   103,     4,   122,     9,   103,
     107,   107,   107,   128,   107,   128,   128,   130,   103,   103,
     131,   131,   131,   131,   128,   129,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   109,   121,
     134,     4,     9,     4,     4,   122,   129,     3,     4,     5,
      31,    50,   109,   110,   111,   117,   118,   121,   125,   126,
     129,   126,   126,   126,     4,     9,   131,   107,   107,    87,
      88,    93,    94,    95,    96,    97,    87,    88,     4,     4,
     125,   125,   125,   125,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   126,   125,
     102,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     4,     4,    99,   100,   101,     4,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   126,   126,   126,   107,   126,   126,
     107,   126,   107,   126,   126,   126,   126,   126,   126,   126,
     130,   130,   130,   130,   130,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   129,   130,   126,   130,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   103,   126,   126,   126,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   120,
     119,   119,   119,   119,   119,   120,   119,   119,   120,   119,
     119,   119,   119,   119,   120,   119,   120,   119,   119,   120,
     120,   120,   120,   120,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   120,   120,   119,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   126,   126,   126,   126,   126,
     127,   127,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   130,   130,   130,   130,   130,
     119,   119,   119,   119,   120,   119,   119,   120,   120,   120,
     120,   120,   120,   119,   120,   119,   119,   119,   119,   119,
     120,   120,   119,   119,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   119,   119,   119,   119,   119,   119,
     119,   119,   119
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   127,   127,   128,   128,   129,   129,   129,
     129,   129,   130,   130,   131,   131,   131,   131,   132,   132,
     133,   133,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     4,     4,     4,     6,     4,     2,     2,
       2,     3,     2,     3,     2,     3,     2,     4,     4,     2,
       2,     3,     1,     2,     1,     2,     3,     4,     2,     2,
       2,     1,     2,     3,     3,     2,     2,     0,     1,     1,
       2,     5,     5,     5,     5,     5,     5,     7,     5,     7,
       5,     5,     5,     5,     7,     5,     5,     5,     5,     5,
       7,     5,     5,     7,     5,     5,     5,     5,     5,     5,
       7,     9,     9,     9,     9,     5,     5,     5,     5,     5,
       5,     2,     9,     9,     5,     7,     5,     7,     7,     7,
       9,     9,     7,     7,     7,     7,     9,     3,     2,     2,
       1,     1,     1,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     1,     5,     3,     3,     3,     3,     3,     4,
       4,     4,     3,     1,     3,     3,     1,     2,     3,     3,
       4,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       0,     2,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     3,     3,     3,     3,     3
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
#line 154 "gram.y" /* yacc.c:1646  */
    { let((yyvsp[-2].rval).left.vp, (yyvsp[0].enode)); }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 156 "gram.y" /* yacc.c:1646  */
    { slet((yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 0); }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 158 "gram.y" /* yacc.c:1646  */
    { slet((yyvsp[-2].rval).left.vp, (yyvsp[0].enode), -1); }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 160 "gram.y" /* yacc.c:1646  */
    { slet((yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 1); }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 162 "gram.y" /* yacc.c:1646  */
    { doformat((yyvsp[-4].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival)); }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 164 "gram.y" /* yacc.c:1646  */
    { doformat((yyvsp[-2].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival)); }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 165 "gram.y" /* yacc.c:1646  */
    {  /* This tmp hack is because readfile
				    * recurses back through yyparse. */
				  char *tmp;
				  tmp = (yyvsp[0].sval);
				  readfile (tmp, 1);
				  xfree(tmp);
				}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "gram.y" /* yacc.c:1646  */
    {
				  char *tmp;
				  tmp = (yyvsp[0].sval);
				  readfile (tmp, 0);
				  xfree(tmp);
				}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 179 "gram.y" /* yacc.c:1646  */
    { if (mdir) xfree(mdir); mdir = (yyvsp[0].sval); }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 181 "gram.y" /* yacc.c:1646  */
    { (void) writefile((yyvsp[-1].sval), ((yyvsp[0].rval).left.vp)->row, 
			 	((yyvsp[0].rval).left.vp)->col, ((yyvsp[0].rval).right.vp)->row,
			 	((yyvsp[0].rval).right.vp)->col);
			 	xfree((yyvsp[-1].sval)); }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 186 "gram.y" /* yacc.c:1646  */
    { (void) writefile ((yyvsp[0].sval), 0, 0, maxrow, maxcol);
			 	xfree((yyvsp[0].sval)); }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 188 "gram.y" /* yacc.c:1646  */
    { (void) printfile((yyvsp[-1].sval), ((yyvsp[0].rval).left.vp)->row, 
			 ((yyvsp[0].rval).left.vp)->col, ((yyvsp[0].rval).right.vp)->row,
			 ((yyvsp[0].rval).right.vp)->col);
			 xfree((yyvsp[-1].sval)); }
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 192 "gram.y" /* yacc.c:1646  */
    { (void) printfile ((yyvsp[0].sval), 0, 0, maxrow, maxcol);
			 xfree((yyvsp[0].sval)); }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 194 "gram.y" /* yacc.c:1646  */
    { (void) tblprintfile((yyvsp[-1].sval), ((yyvsp[0].rval).left.vp)->row, 
			 ((yyvsp[0].rval).left.vp)->col, ((yyvsp[0].rval).right.vp)->row,
			 ((yyvsp[0].rval).right.vp)->col);
			 xfree((yyvsp[-1].sval)); }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 198 "gram.y" /* yacc.c:1646  */
    { (void)tblprintfile ((yyvsp[0].sval), 0, 0, maxrow, maxcol);
			 xfree((yyvsp[0].sval)); }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 201 "gram.y" /* yacc.c:1646  */
    { showcol( (yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 203 "gram.y" /* yacc.c:1646  */
    { showrow( (yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 205 "gram.y" /* yacc.c:1646  */
    { hide_col( (yyvsp[0].ival) ); }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "gram.y" /* yacc.c:1646  */
    { hide_row( (yyvsp[0].ival) ); }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 209 "gram.y" /* yacc.c:1646  */
    { copy((yyvsp[-1].rval).left.vp,(yyvsp[-1].rval).right.vp,
					(yyvsp[0].rval).left.vp,(yyvsp[0].rval).right.vp); }
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 212 "gram.y" /* yacc.c:1646  */
    { eraser(lookat(showsr, showsc),
				        lookat(currow, curcol)); }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 215 "gram.y" /* yacc.c:1646  */
    { eraser((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 216 "gram.y" /* yacc.c:1646  */
    { valueize_area(showsr, showsc, currow, curcol);
				 modflg++; }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 218 "gram.y" /* yacc.c:1646  */
    { valueize_area(((yyvsp[0].rval).left.vp)->row,
				((yyvsp[0].rval).left.vp)->col,
				((yyvsp[0].rval).right.vp)->row,
				((yyvsp[0].rval).right.vp)->col); modflg++; }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 222 "gram.y" /* yacc.c:1646  */
    { fill(lookat(showsr, showsc),
				      lookat(currow, curcol), (yyvsp[-1].fval), (yyvsp[0].fval)); }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 225 "gram.y" /* yacc.c:1646  */
    { fill((yyvsp[-2].rval).left.vp, (yyvsp[-2].rval).right.vp, (yyvsp[-1].fval), (yyvsp[0].fval)); }
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 226 "gram.y" /* yacc.c:1646  */
    {moveto((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 227 "gram.y" /* yacc.c:1646  */
    {num_search((yyvsp[0].fval));}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 228 "gram.y" /* yacc.c:1646  */
    {str_search((yyvsp[0].sval));}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 229 "gram.y" /* yacc.c:1646  */
    {go_last();}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 230 "gram.y" /* yacc.c:1646  */
    { struct ent_ptr arg1, arg2;
					arg1.vp = lookat(showsr, showsc);
					arg1.vf = 0;
					arg2.vp = lookat(currow, curcol);
					arg2.vf = 0;
					add_range((yyvsp[0].sval), arg1, arg2, 1); }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 237 "gram.y" /* yacc.c:1646  */
    { add_range((yyvsp[-1].sval), (yyvsp[0].rval).left, (yyvsp[0].rval).right, 1); }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 238 "gram.y" /* yacc.c:1646  */
    { add_range((yyvsp[-1].sval), (yyvsp[0].ent), (yyvsp[0].ent), 0); }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 239 "gram.y" /* yacc.c:1646  */
    { del_range((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 244 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_var('v', (yyvsp[0].ent)); }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 245 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('f', ENULL, (yyvsp[0].enode)); }
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 247 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range(REDUCE | '+', (yyvsp[-1].rval)); }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 249 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (REDUCE | '*', (yyvsp[-1].rval)); }
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 251 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (REDUCE | 'a', (yyvsp[-1].rval)); }
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 253 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (REDUCE | 's', (yyvsp[-1].rval)); }
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 255 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (REDUCE | 'c', (yyvsp[-1].rval)); }
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 257 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (REDUCE | MAX, (yyvsp[-1].rval)); }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 259 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LMAX, (yyvsp[-1].enode), (yyvsp[-3].enode)); }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 261 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (REDUCE | MIN, (yyvsp[-1].rval)); }
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 263 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LMIN, (yyvsp[-1].enode), (yyvsp[-3].enode)); }
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 264 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ABS, ENULL, (yyvsp[-1].enode)); }
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 265 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ACOS, ENULL, (yyvsp[-1].enode)); }
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 266 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ASIN, ENULL, (yyvsp[-1].enode)); }
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 267 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ATAN, ENULL, (yyvsp[-1].enode)); }
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 268 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ATAN2, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 269 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(CEIL, ENULL, (yyvsp[-1].enode)); }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 270 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(COS, ENULL, (yyvsp[-1].enode)); }
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 271 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(EXP, ENULL, (yyvsp[-1].enode)); }
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 272 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FABS, ENULL, (yyvsp[-1].enode)); }
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 273 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FLOOR, ENULL, (yyvsp[-1].enode)); }
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 274 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(HYPOT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 275 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOG, ENULL, (yyvsp[-1].enode)); }
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 276 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOG10, ENULL, (yyvsp[-1].enode)); }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 277 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(POW, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 278 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SIN, ENULL, (yyvsp[-1].enode)); }
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 279 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SQRT, ENULL, (yyvsp[-1].enode)); }
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 280 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(TAN, ENULL, (yyvsp[-1].enode)); }
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 281 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DTR, ENULL, (yyvsp[-1].enode)); }
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 282 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(RTD, ENULL, (yyvsp[-1].enode)); }
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 283 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(RND, ENULL, (yyvsp[-1].enode)); }
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 284 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ROUND, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 285 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(IF,  (yyvsp[-5].enode),new(',',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 287 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(PV,  (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 288 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FV,  (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 289 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(PMT, (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 291 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(HOUR,ENULL, (yyvsp[-1].enode)); }
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 292 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MINUTE,ENULL, (yyvsp[-1].enode)); }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 293 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SECOND,ENULL, (yyvsp[-1].enode)); }
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 294 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MONTH,ENULL,(yyvsp[-1].enode)); }
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 295 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DAY, ENULL, (yyvsp[-1].enode)); }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 296 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(YEAR, ENULL, (yyvsp[-1].enode)); }
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 297 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(NOW, ENULL, ENULL);}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 299 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DTS, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode)));}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 301 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(TTS, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode)));}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 302 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(STON, ENULL, (yyvsp[-1].enode)); }
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 303 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new (EQS, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 304 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DATE, ENULL, (yyvsp[-1].enode)); }
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 305 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FMT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 307 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(INDEX, (yyvsp[-3].enode), new_range(REDUCE | INDEX, (yyvsp[-1].rval))); }
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 309 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOOKUP, (yyvsp[-3].enode), new_range(REDUCE | LOOKUP, (yyvsp[-1].rval))); }
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 311 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(HLOOKUP, new(',', (yyvsp[-5].enode), (yyvsp[-1].enode)),
		    new_range(REDUCE | HLOOKUP, (yyvsp[-3].rval))); }
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 314 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(VLOOKUP, new(',', (yyvsp[-5].enode), (yyvsp[-1].enode)),
		    new_range(REDUCE | VLOOKUP, (yyvsp[-3].rval))); }
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 317 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(STINDEX, (yyvsp[-3].enode), new_range(REDUCE | STINDEX, (yyvsp[-1].rval))); }
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 318 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(EXT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 319 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(NVAL, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 320 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SVAL, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 322 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SUBSTR, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 323 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = (yyvsp[-1].enode); }
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 324 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = (yyvsp[0].enode); }
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 325 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('m', ENULL, (yyvsp[0].enode)); }
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 326 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_const('k', (double) (yyvsp[0].ival)); }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 327 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_const('k', (yyvsp[0].fval)); }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 328 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_const('k', (double)3.14159265358979323846); }
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 329 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_str((yyvsp[0].sval)); }
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 330 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, (yyvsp[0].enode)); }
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 331 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, (yyvsp[0].enode)); }
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 334 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('+', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 335 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('-', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 336 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('*', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 337 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('/', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 338 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('%', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 339 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('^', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 341 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('?', (yyvsp[-4].enode), new(':', (yyvsp[-2].enode), (yyvsp[0].enode))); }
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 342 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('<', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 343 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('=', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 344 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('>', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 345 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('&', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 346 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('|', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 347 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, new ('>', (yyvsp[-3].enode), (yyvsp[0].enode))); }
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 348 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, new ('=', (yyvsp[-3].enode), (yyvsp[0].enode))); }
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 349 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, new ('<', (yyvsp[-3].enode), (yyvsp[0].enode))); }
#line 2725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 350 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('#', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 353 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ELIST, ENULL, (yyvsp[0].enode)); }
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 354 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ELIST, (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 357 "gram.y" /* yacc.c:1646  */
    { (yyval.rval).left = (yyvsp[-2].ent); (yyval.rval).right = (yyvsp[0].ent); }
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 358 "gram.y" /* yacc.c:1646  */
    { (yyval.rval) = (yyvsp[0].rval); }
#line 2755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 361 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival) , (yyvsp[-1].ival)); (yyval.ent).vf = 0;}
#line 2761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 362 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival) , (yyvsp[-1].ival));
					(yyval.ent).vf = FIX_COL;}
#line 2768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 364 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival) , (yyvsp[-2].ival));
					(yyval.ent).vf = FIX_ROW;}
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 366 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival) , (yyvsp[-2].ival));
					(yyval.ent).vf = FIX_ROW | FIX_COL;}
#line 2782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 368 "gram.y" /* yacc.c:1646  */
    { (yyval.ent) = (yyvsp[0].rval).left; }
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 371 "gram.y" /* yacc.c:1646  */
    { (yyval.rval) = (yyvsp[0].rval); }
#line 2794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 372 "gram.y" /* yacc.c:1646  */
    { (yyval.rval).left = (yyvsp[0].ent); (yyval.rval).right = (yyvsp[0].ent); }
#line 2800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 375 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = (double) (yyvsp[0].ival); }
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 376 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = (yyvsp[0].fval); }
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 377 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = -(yyvsp[0].fval); }
#line 2818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 378 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = (yyvsp[0].fval); }
#line 2824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 381 "gram.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 382 "gram.y" /* yacc.c:1646  */
    {
				    char *s, *s1;
				    s1 = (yyvsp[0].ent).vp->label;
				    if (!s1)
					s1 = "NULL_STRING";
				    s = xmalloc((unsigned)strlen(s1)+1);
				    (void) strcpy(s, s1);
				    (yyval.sval) = s;
				}
#line 2844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 397 "gram.y" /* yacc.c:1646  */
    { setauto(1); }
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 398 "gram.y" /* yacc.c:1646  */
    { setauto(1); }
#line 2856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 399 "gram.y" /* yacc.c:1646  */
    { setauto(0); }
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 400 "gram.y" /* yacc.c:1646  */
    { setauto(0); }
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 401 "gram.y" /* yacc.c:1646  */
    { setauto(0); }
#line 2874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 402 "gram.y" /* yacc.c:1646  */
    { setauto(0); }
#line 2880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 403 "gram.y" /* yacc.c:1646  */
    { setorder(BYCOLS); }
#line 2886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 404 "gram.y" /* yacc.c:1646  */
    { setorder(BYROWS); }
#line 2892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 405 "gram.y" /* yacc.c:1646  */
    { setorder(BYGRAPH); }
#line 2898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 406 "gram.y" /* yacc.c:1646  */
    { numeric = 1; }
#line 2904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 407 "gram.y" /* yacc.c:1646  */
    { numeric = 0; }
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 408 "gram.y" /* yacc.c:1646  */
    { prescale = 0.01; }
#line 2916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 409 "gram.y" /* yacc.c:1646  */
    { prescale = 1.0; }
#line 2922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 410 "gram.y" /* yacc.c:1646  */
    { extfunc = 1; }
#line 2928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 411 "gram.y" /* yacc.c:1646  */
    { extfunc = 0; }
#line 2934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 412 "gram.y" /* yacc.c:1646  */
    { showcell = 1; }
#line 2940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 413 "gram.y" /* yacc.c:1646  */
    { showcell = 0; }
#line 2946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 414 "gram.y" /* yacc.c:1646  */
    { showtop = 1; }
#line 2952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 415 "gram.y" /* yacc.c:1646  */
    { showtop = 0; }
#line 2958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 416 "gram.y" /* yacc.c:1646  */
    { setiterations((yyvsp[0].ival)); }
#line 2964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 417 "gram.y" /* yacc.c:1646  */
    { tbl_style = (yyvsp[0].ival); }
#line 2970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 418 "gram.y" /* yacc.c:1646  */
    { tbl_style = TBL; }
#line 2976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 419 "gram.y" /* yacc.c:1646  */
    { tbl_style = LATEX; }
#line 2982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 420 "gram.y" /* yacc.c:1646  */
    { tbl_style = TEX; }
#line 2988 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2992 "y.tab.c" /* yacc.c:1646  */
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
