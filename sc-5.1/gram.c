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
#line 14 "gram.y" /* yacc.c:339  */

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
    K_FIXED = 284,
    K_SUM = 285,
    K_PROD = 286,
    K_AVG = 287,
    K_STDDEV = 288,
    K_ACOS = 289,
    K_ASIN = 290,
    K_ATAN = 291,
    K_CEIL = 292,
    K_COS = 293,
    K_EXP = 294,
    K_FABS = 295,
    K_FLOOR = 296,
    K_HYPOT = 297,
    K_LN = 298,
    K_LOG = 299,
    K_PI = 300,
    K_POW = 301,
    K_SIN = 302,
    K_SQRT = 303,
    K_TAN = 304,
    K_DTR = 305,
    K_RTD = 306,
    K_MAX = 307,
    K_MIN = 308,
    K_RND = 309,
    K_HOUR = 310,
    K_MINUTE = 311,
    K_SECOND = 312,
    K_MONTH = 313,
    K_DAY = 314,
    K_YEAR = 315,
    K_NOW = 316,
    K_DATE = 317,
    K_FMT = 318,
    K_LBL = 319,
    K_SUBSTR = 320,
    K_STON = 321,
    K_EQS = 322
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
#define K_FIXED 284
#define K_SUM 285
#define K_PROD 286
#define K_AVG 287
#define K_STDDEV 288
#define K_ACOS 289
#define K_ASIN 290
#define K_ATAN 291
#define K_CEIL 292
#define K_COS 293
#define K_EXP 294
#define K_FABS 295
#define K_FLOOR 296
#define K_HYPOT 297
#define K_LN 298
#define K_LOG 299
#define K_PI 300
#define K_POW 301
#define K_SIN 302
#define K_SQRT 303
#define K_TAN 304
#define K_DTR 305
#define K_RTD 306
#define K_MAX 307
#define K_MIN 308
#define K_RND 309
#define K_HOUR 310
#define K_MINUTE 311
#define K_SECOND 312
#define K_MONTH 313
#define K_DAY 314
#define K_YEAR 315
#define K_NOW 316
#define K_DATE 317
#define K_FMT 318
#define K_LBL 319
#define K_SUBSTR 320
#define K_STON 321
#define K_EQS 322

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 23 "gram.y" /* yacc.c:355  */

    int ival;
    double fval;
    struct ent_ptr ent;
    struct enode *enode;
    char *sval;
    struct range_s rval;

#line 258 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 273 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   961

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  301

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,    78,    87,     2,    71,     2,
      83,    84,    79,    76,    85,    77,     2,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,     2,
      72,    73,    74,    68,    82,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    70,     2,    86,     2,     2,     2,
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
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   116,   118,   120,   122,   124,   126,   133,
     139,   141,   146,   149,   153,   155,   159,   161,   163,   165,
     168,   171,   173,   175,   179,   181,   183,   184,   191,   192,
     193,   194,   195,   197,   198,   199,   201,   203,   205,   207,
     209,   211,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   272,   273,   276,   277,
     279,   281,   283,   286,   287,   290,   291,   292,   293,   296,
     297
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
  "S_UNDEFINE", "S_VALUE", "S_MDIR", "K_FIXED", "K_SUM", "K_PROD", "K_AVG",
  "K_STDDEV", "K_ACOS", "K_ASIN", "K_ATAN", "K_CEIL", "K_COS", "K_EXP",
  "K_FABS", "K_FLOOR", "K_HYPOT", "K_LN", "K_LOG", "K_PI", "K_POW",
  "K_SIN", "K_SQRT", "K_TAN", "K_DTR", "K_RTD", "K_MAX", "K_MIN", "K_RND",
  "K_HOUR", "K_MINUTE", "K_SECOND", "K_MONTH", "K_DAY", "K_YEAR", "K_NOW",
  "K_DATE", "K_FMT", "K_LBL", "K_SUBSTR", "K_STON", "K_EQS", "'?'", "':'",
  "'|'", "'&'", "'<'", "'='", "'>'", "'!'", "'+'", "'-'", "'#'", "'*'",
  "'/'", "'^'", "'@'", "'('", "')'", "','", "'~'", "'$'", "$accept",
  "command", "term", "e", "range", "var", "var_or_range", "num", "strarg", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,    63,    58,
     124,    38,    60,    61,    62,    33,    43,    45,    35,    42,
      47,    94,    64,    40,    41,    44,   126,    36
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-32)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     245,   -65,    14,    52,    52,    52,    48,    48,    48,    52,
      48,    48,    52,    20,    52,    71,    52,    48,    52,    52,
      48,    25,    22,   -65,   -65,    11,    26,   -65,   -38,   -41,
     -37,   -27,   -65,   -65,   -65,    52,   -65,   -24,    52,    52,
      52,   -38,   -19,   -17,   -65,   -65,   -65,    23,    23,    23,
      23,   -65,    52,   -65,   -65,   -65,   -65,    56,    47,   -65,
      59,    49,    -5,   202,   202,   202,   -65,   202,   -65,   -65,
     -65,    63,    64,   -65,   -65,    23,   -65,   -65,   -38,   -65,
      70,   -65,   -65,    77,   -65,   -65,   -65,   -65,   202,   -65,
     202,   202,   202,   260,   202,   202,   -65,   823,   -65,   823,
     823,   823,   -65,   -65,   -65,    79,   -65,   -65,   -65,   -65,
     -65,   -15,     1,    18,    19,    37,    38,    51,    54,    57,
      61,    62,    80,    81,    86,    90,    92,    95,    96,    97,
      99,   100,   101,   105,   106,   107,   108,   115,   116,   117,
     119,   -65,   120,   125,   133,   141,   143,   357,   -65,   202,
     202,   202,   152,   202,   167,    69,   202,   202,   202,   202,
     202,   202,   -65,    52,    52,    52,    52,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,    52,    52,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   -65,   809,
     860,   870,   202,   880,   880,   202,   880,   202,    -9,    -9,
      -9,    65,    65,   -65,    76,    78,   126,   146,   372,   387,
     402,   417,   432,   447,   462,   477,   261,   492,   507,   277,
     522,   537,   552,   567,   582,   148,   153,   597,   612,   627,
     642,   657,   672,   687,   702,   293,   309,   717,   325,   202,
     880,   880,   880,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   202,   -65,   -65,   202,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   202,   202,   -65,   202,   849,   732,
     747,   762,   341,   777,   -65,   -65,   -65,   202,   -65,   792,
     -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    22,
       0,     0,     0,    97,   102,     0,     0,   103,   104,     0,
       0,     0,   109,   110,     8,    12,     9,     0,    14,    16,
       0,     0,     0,     0,    21,   105,   106,     0,     0,     0,
       0,    26,    27,    30,    23,    10,     1,     0,     0,    98,
       0,     0,     0,     0,     0,     0,    11,     0,    13,    15,
      19,     0,     0,   108,   107,     0,    24,    28,    29,     7,
       0,   100,    99,     0,    96,    77,    74,    75,     0,    76,
       0,     0,     0,     0,     0,     0,    85,     3,    33,     4,
       5,     2,    18,    17,    25,     0,   101,    34,    79,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
      91,    90,     0,    87,    88,     0,    89,     0,    80,    81,
      95,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    94,    93,    35,    36,    37,    38,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    50,    51,     0,    53,
      54,    55,    56,    57,    39,    40,    58,    59,    60,    61,
      62,    63,    64,    68,     0,     0,    66,     0,    86,     0,
       0,     0,     0,     0,    49,    52,    69,     0,    67,     0,
      70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   127,   -64,    27,     2,    29,   102,   898
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    21,    96,    97,    27,    98,    29,    50,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      99,   100,    24,   101,    25,    28,    28,    28,    33,    33,
      33,    28,    33,    33,    41,    59,    28,    28,    28,    33,
      28,    28,    33,    22,    42,    56,    57,    45,    46,    43,
     147,    62,    63,    30,    31,    61,    64,    41,    37,    40,
      41,    41,    28,    44,    49,    51,    65,    53,    54,    67,
      71,    32,    72,    82,    78,    24,    80,    25,    23,    24,
      79,    25,    66,    81,    84,    68,    69,   102,   163,    70,
     159,   160,   161,   103,   105,    45,    46,    23,    24,    77,
      25,   106,    26,   162,   164,   199,   200,   201,   203,   204,
     206,    58,   208,   209,   210,   211,   212,   213,    60,    47,
      48,   165,   166,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     167,   168,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   169,    26,    83,   170,   250,    26,
     171,   251,   207,   252,   172,   173,   161,    47,    48,    73,
      74,    75,    76,     0,     0,    85,    86,    87,    26,    24,
     253,    25,   254,   174,   175,    28,    28,    28,    28,   176,
      85,    86,    87,   177,    24,   178,    25,   104,   179,   180,
     181,    88,   182,   183,   184,   288,    28,    28,   185,   186,
     187,   188,   214,   215,   216,   217,    88,    89,   189,   190,
     191,   289,   192,   193,   290,    85,    86,    87,   194,    24,
     255,    25,    89,   235,   236,   107,   195,   108,   109,   110,
     291,   292,   148,   293,   196,   202,   197,    90,    91,    92,
     256,    88,   274,   299,    93,    94,     0,   275,    95,    26,
     205,     0,    90,    91,    92,   -31,     1,    89,     0,    93,
      94,     0,     0,    95,    26,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,    90,    91,    92,
       0,     0,     0,     0,    93,    94,     0,     0,    95,    26,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,   144,   145,   146,     0,   149,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,   149,   265,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
       0,   149,   268,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,     0,   149,   284,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,     0,   149,   285,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,     0,   149,
     287,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,   149,   297,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   198,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   257,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   258,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   259,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   260,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   261,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   262,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   263,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   264,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   266,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   267,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   269,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   270,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   271,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   272,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   273,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   276,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   277,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   278,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   279,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   280,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   281,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   282,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   283,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   286,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   294,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   295,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,   149,   296,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
     149,   298,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,   300,   149,   249,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   149,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    35,    36,     0,    38,    39,
       0,     0,     0,     0,     0,    52,     0,     0,    55,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   -32,   -32,   -32,   -32,   156,   157,   158,   159,
     160,   161
};

static const yytype_int16 yycheck[] =
{
      64,    65,     7,    67,     9,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     4,    14,    15,    16,    17,
      18,    19,    20,     9,     4,     0,     4,     4,     5,     9,
      94,    69,    73,     4,     5,     9,    73,    35,     9,    12,
      38,    39,    40,    14,    15,    16,    73,    18,    19,    73,
      69,     3,    69,     4,    52,     7,     9,     9,     6,     7,
       4,     9,    35,     4,    62,    38,    39,     4,    83,    40,
      79,    80,    81,     9,     4,     4,     5,     6,     7,    52,
       9,     4,    87,     4,    83,   149,   150,   151,   152,   153,
     154,    69,   156,   157,   158,   159,   160,   161,    87,    76,
      77,    83,    83,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      83,    83,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    83,    87,    87,    83,   202,    87,
      83,   205,    73,   207,    83,    83,    81,    76,    77,    47,
      48,    49,    50,    -1,    -1,     3,     4,     5,    87,     7,
      84,     9,    84,    83,    83,   163,   164,   165,   166,    83,
       3,     4,     5,    83,     7,    83,     9,    75,    83,    83,
      83,    29,    83,    83,    83,   249,   184,   185,    83,    83,
      83,    83,   163,   164,   165,   166,    29,    45,    83,    83,
      83,   265,    83,    83,   268,     3,     4,     5,    83,     7,
      84,     9,    45,   184,   185,    88,    83,    90,    91,    92,
     284,   285,    95,   287,    83,    73,    83,    75,    76,    77,
      84,    29,    84,   297,    82,    83,    -1,    84,    86,    87,
      73,    -1,    75,    76,    77,     0,     1,    45,    -1,    82,
      83,    -1,    -1,    86,    87,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    86,    87,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    68,    85,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    68,    85,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    68,    85,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    68,    85,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    68,
      85,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    68,    85,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    68,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      68,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    89,     9,     6,     7,     9,    87,    92,    93,    94,
      94,    94,     3,    93,    96,    96,    96,    94,    96,    96,
      92,    93,     4,     9,    94,     4,     5,    76,    77,    94,
      95,    94,    96,    94,    94,    96,     0,     4,    69,     4,
      87,     9,    69,    73,    73,    73,    92,    73,    92,    92,
      94,    69,    69,    95,    95,    95,    95,    92,    93,     4,
       9,     4,     4,    87,    93,     3,     4,     5,    29,    45,
      75,    76,    77,    82,    83,    86,    90,    91,    93,    91,
      91,    91,     4,     9,    95,     4,     4,    90,    90,    90,
      90,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    65,    66,    67,    91,    90,    68,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     4,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    91,
      91,    91,    73,    91,    91,    73,    91,    73,    91,    91,
      91,    91,    91,    91,    94,    94,    94,    94,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    94,    94,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    69,
      91,    91,    91,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    85,    84,    84,    85,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    85,    84,    85,    91,    91,
      91,    91,    91,    91,    84,    84,    84,    85,    84,    91,
      84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    94,    94,    95,    95,    95,    95,    96,
      96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     4,     4,     4,     6,     4,     2,     2,
       2,     3,     2,     3,     2,     3,     2,     4,     4,     3,
       1,     2,     1,     2,     3,     4,     2,     2,     3,     3,
       2,     0,     1,     1,     2,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     7,
       5,     5,     7,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     2,     5,     7,     5,     7,
       9,     3,     2,     2,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     3,     1,     5,     3,     3,     3,
       3,     3,     4,     4,     4,     3,     3,     1,     2,     3,
       3,     4,     1,     1,     1,     1,     1,     2,     2,     1,
       1
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
#line 115 "gram.y" /* yacc.c:1646  */
    { let((yyvsp[-2].rval).left.vp, (yyvsp[0].enode)); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 117 "gram.y" /* yacc.c:1646  */
    { slet((yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 0); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 119 "gram.y" /* yacc.c:1646  */
    { slet((yyvsp[-2].rval).left.vp, (yyvsp[0].enode), -1); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 121 "gram.y" /* yacc.c:1646  */
    { slet((yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 1); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 123 "gram.y" /* yacc.c:1646  */
    { doformat((yyvsp[-4].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival)); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 125 "gram.y" /* yacc.c:1646  */
    { doformat((yyvsp[-2].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival)); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "gram.y" /* yacc.c:1646  */
    {  /* This tmp hack is because readfile
				    * recurses back through yyparse. */
				  char *tmp;
				  tmp = (yyvsp[0].sval);
				  readfile (tmp, 1);
				  xfree(tmp);
				}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 133 "gram.y" /* yacc.c:1646  */
    {
				  char *tmp;
				  tmp = (yyvsp[0].sval);
				  readfile (tmp, 0);
				  xfree(tmp);
				}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 140 "gram.y" /* yacc.c:1646  */
    { if (mdir) xfree(mdir); mdir = (yyvsp[0].sval); }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 142 "gram.y" /* yacc.c:1646  */
    { (void) writefile((yyvsp[-1].sval), ((yyvsp[0].rval).left.vp)->row, 
			 	((yyvsp[0].rval).left.vp)->col, ((yyvsp[0].rval).right.vp)->row,
			 	((yyvsp[0].rval).right.vp)->col);
			 	xfree((yyvsp[-1].sval)); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 147 "gram.y" /* yacc.c:1646  */
    { (void) writefile ((yyvsp[0].sval), 0, 0, maxrow, maxcol);
			 	xfree((yyvsp[0].sval)); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "gram.y" /* yacc.c:1646  */
    { (void) printfile((yyvsp[-1].sval), ((yyvsp[0].rval).left.vp)->row, 
			 ((yyvsp[0].rval).left.vp)->col, ((yyvsp[0].rval).right.vp)->row,
			 ((yyvsp[0].rval).right.vp)->col);
			 xfree((yyvsp[-1].sval)); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 153 "gram.y" /* yacc.c:1646  */
    { (void) printfile ((yyvsp[0].sval), 0, 0, maxrow, maxcol);
			 xfree((yyvsp[0].sval)); }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 155 "gram.y" /* yacc.c:1646  */
    { (void) tblprintfile((yyvsp[-1].sval), ((yyvsp[0].rval).left.vp)->row, 
			 ((yyvsp[0].rval).left.vp)->col, ((yyvsp[0].rval).right.vp)->row,
			 ((yyvsp[0].rval).right.vp)->col);
			 xfree((yyvsp[-1].sval)); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "gram.y" /* yacc.c:1646  */
    { (void)tblprintfile ((yyvsp[0].sval), 0, 0, maxrow, maxcol);
			 xfree((yyvsp[0].sval)); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 162 "gram.y" /* yacc.c:1646  */
    { showcol( (yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "gram.y" /* yacc.c:1646  */
    { showrow( (yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 166 "gram.y" /* yacc.c:1646  */
    { copy((yyvsp[-1].rval).left.vp,(yyvsp[-1].rval).right.vp,
					(yyvsp[0].rval).left.vp,(yyvsp[0].rval).right.vp); }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 169 "gram.y" /* yacc.c:1646  */
    { eraser(lookat(showsr, showsc),
				        lookat(currow, curcol)); }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 172 "gram.y" /* yacc.c:1646  */
    { eraser((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 173 "gram.y" /* yacc.c:1646  */
    { valueize_area(showsr, showsc, currow, curcol);
				 modflg++; }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 175 "gram.y" /* yacc.c:1646  */
    { valueize_area(((yyvsp[0].rval).left.vp)->row,
				((yyvsp[0].rval).left.vp)->col,
				((yyvsp[0].rval).right.vp)->row,
				((yyvsp[0].rval).right.vp)->col); modflg++; }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 179 "gram.y" /* yacc.c:1646  */
    { fill(lookat(showsr, showsc),
				      lookat(currow, curcol), (yyvsp[-1].fval), (yyvsp[0].fval)); }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 182 "gram.y" /* yacc.c:1646  */
    { fill((yyvsp[-2].rval).left.vp, (yyvsp[-2].rval).right.vp, (yyvsp[-1].fval), (yyvsp[0].fval)); }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 183 "gram.y" /* yacc.c:1646  */
    {(void) moveto((yyvsp[0].rval).left.vp); }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 184 "gram.y" /* yacc.c:1646  */
    { struct ent_ptr arg1, arg2;
					arg1.vp = lookat(showsr, showsc);
					arg1.vf = 0;
					arg2.vp = lookat(currow, curcol);
					arg2.vf = 0;
					add_range((yyvsp[0].sval), arg1, arg2, 1); }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 191 "gram.y" /* yacc.c:1646  */
    { add_range((yyvsp[-1].sval), (yyvsp[0].rval).left, (yyvsp[0].rval).right, 1); }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 192 "gram.y" /* yacc.c:1646  */
    { add_range((yyvsp[-1].sval), (yyvsp[0].ent), (yyvsp[0].ent), 0); }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 193 "gram.y" /* yacc.c:1646  */
    { del_range((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 197 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_var('v', (yyvsp[0].ent)); }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 198 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('f', ENULL, (yyvsp[0].enode)); }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 200 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range(O_REDUCE('+'), (yyvsp[-1].rval)); }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 202 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (O_REDUCE('*'), (yyvsp[-1].rval)); }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 204 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (O_REDUCE('a'), (yyvsp[-1].rval)); }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 206 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (O_REDUCE('s'), (yyvsp[-1].rval)); }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 208 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (O_REDUCE(MAX), (yyvsp[-1].rval)); }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 210 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_range (O_REDUCE(MIN), (yyvsp[-1].rval)); }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 212 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ACOS, ENULL, (yyvsp[-1].enode)); }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 213 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ASIN, ENULL, (yyvsp[-1].enode)); }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 214 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(ATAN, ENULL, (yyvsp[-1].enode)); }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 215 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(CEIL, ENULL, (yyvsp[-1].enode)); }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 216 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(COS, ENULL, (yyvsp[-1].enode)); }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 217 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(EXP, ENULL, (yyvsp[-1].enode)); }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FABS, ENULL, (yyvsp[-1].enode)); }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 219 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FLOOR, ENULL, (yyvsp[-1].enode)); }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 220 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(HYPOT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 221 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOG, ENULL, (yyvsp[-1].enode)); }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 222 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(LOG10, ENULL, (yyvsp[-1].enode)); }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 223 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(POW, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 224 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SIN, ENULL, (yyvsp[-1].enode)); }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 225 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SQRT, ENULL, (yyvsp[-1].enode)); }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 226 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(TAN, ENULL, (yyvsp[-1].enode)); }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 227 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DTR, ENULL, (yyvsp[-1].enode)); }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 228 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(RTD, ENULL, (yyvsp[-1].enode)); }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 229 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(RND, ENULL, (yyvsp[-1].enode)); }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 230 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(HOUR,ENULL, (yyvsp[-1].enode)); }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 231 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MINUTE,ENULL, (yyvsp[-1].enode)); }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 232 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SECOND,ENULL, (yyvsp[-1].enode)); }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 233 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(MONTH,ENULL,(yyvsp[-1].enode)); }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 234 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DAY, ENULL, (yyvsp[-1].enode)); }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 235 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(YEAR, ENULL, (yyvsp[-1].enode)); }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 236 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(NOW, ENULL, ENULL);}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 237 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(STON, ENULL, (yyvsp[-1].enode)); }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 238 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new (EQS, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 239 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(DATE, ENULL, (yyvsp[-1].enode)); }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 240 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(FMT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 242 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new(SUBSTR, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 243 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = (yyvsp[-1].enode); }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 244 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = (yyvsp[0].enode); }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 245 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('m', ENULL, (yyvsp[0].enode)); }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 246 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_const('k', (double) (yyvsp[0].ival)); }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 247 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_const('k', (yyvsp[0].fval)); }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 248 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_const('k', (double)3.14159265358979323846); }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 249 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new_str((yyvsp[0].sval)); }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 250 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, (yyvsp[0].enode)); }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 251 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, (yyvsp[0].enode)); }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 254 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('+', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 255 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('-', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 256 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('*', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 257 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('/', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 258 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('^', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 260 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('?', (yyvsp[-4].enode), new(':', (yyvsp[-2].enode), (yyvsp[0].enode))); }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 261 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('<', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 262 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('=', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 263 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('>', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 264 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('&', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 265 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('|', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 266 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, new ('>', (yyvsp[-3].enode), (yyvsp[0].enode))); }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 267 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, new ('=', (yyvsp[-3].enode), (yyvsp[0].enode))); }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 268 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('~', ENULL, new ('<', (yyvsp[-3].enode), (yyvsp[0].enode))); }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 269 "gram.y" /* yacc.c:1646  */
    { (yyval.enode) = new ('#', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 272 "gram.y" /* yacc.c:1646  */
    { (yyval.rval).left = (yyvsp[-2].ent); (yyval.rval).right = (yyvsp[0].ent); }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 273 "gram.y" /* yacc.c:1646  */
    { (yyval.rval) = (yyvsp[0].rval); }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 276 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival) , (yyvsp[-1].ival)); (yyval.ent).vf = 0;}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 277 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival) , (yyvsp[-1].ival));
					(yyval.ent).vf = FIX_COL;}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 279 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival) , (yyvsp[-2].ival));
					(yyval.ent).vf = FIX_ROW;}
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 281 "gram.y" /* yacc.c:1646  */
    { (yyval.ent).vp = lookat((yyvsp[0].ival) , (yyvsp[-2].ival));
					(yyval.ent).vf = FIX_ROW | FIX_COL;}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 283 "gram.y" /* yacc.c:1646  */
    { (yyval.ent) = (yyvsp[0].rval).left; }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 286 "gram.y" /* yacc.c:1646  */
    { (yyval.rval) = (yyvsp[0].rval); }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 287 "gram.y" /* yacc.c:1646  */
    { (yyval.rval).left = (yyvsp[0].ent); (yyval.rval).right = (yyvsp[0].ent); }
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 290 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = (double) (yyvsp[0].ival); }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 291 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = (yyvsp[0].fval); }
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 292 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = -(yyvsp[0].fval); }
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 293 "gram.y" /* yacc.c:1646  */
    { (yyval.fval) = (yyvsp[0].fval); }
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 296 "gram.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 297 "gram.y" /* yacc.c:1646  */
    {
				    char *s, *s1;
				    s1 = (yyvsp[0].ent).vp->label;
				    if (!s1)
					s1 = "NULL_STRING";
				    s = xmalloc((unsigned)strlen(s1)+1);
				    (void) strcpy(s, s1);
				    (yyval.sval) = s;
				}
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2359 "y.tab.c" /* yacc.c:1646  */
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
