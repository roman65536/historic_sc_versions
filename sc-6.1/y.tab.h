/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
    K_ACOS = 291,
    K_ASIN = 292,
    K_ATAN = 293,
    K_ATAN2 = 294,
    K_CEIL = 295,
    K_COS = 296,
    K_EXP = 297,
    K_FABS = 298,
    K_FLOOR = 299,
    K_HYPOT = 300,
    K_LN = 301,
    K_LOG = 302,
    K_PI = 303,
    K_POW = 304,
    K_SIN = 305,
    K_SQRT = 306,
    K_TAN = 307,
    K_DTR = 308,
    K_RTD = 309,
    K_MAX = 310,
    K_MIN = 311,
    K_RND = 312,
    K_PV = 313,
    K_FV = 314,
    K_PMT = 315,
    K_HOUR = 316,
    K_MINUTE = 317,
    K_SECOND = 318,
    K_MONTH = 319,
    K_DAY = 320,
    K_YEAR = 321,
    K_NOW = 322,
    K_DATE = 323,
    K_FMT = 324,
    K_SUBSTR = 325,
    K_STON = 326,
    K_EQS = 327,
    K_EXT = 328,
    K_NVAL = 329,
    K_SVAL = 330,
    K_LOOKUP = 331,
    K_INDEX = 332,
    K_STINDEX = 333,
    K_AUTO = 334,
    K_AUTOCALC = 335,
    K_BYROWS = 336,
    K_BYCOLS = 337,
    K_BYGRAPH = 338,
    K_ITERATIONS = 339,
    K_NUMERIC = 340,
    K_PRESCALE = 341,
    K_EXTFUN = 342,
    K_CELLCUR = 343,
    K_TOPROW = 344,
    K_TBLSTYLE = 345,
    K_TBL = 346,
    K_LATEX = 347,
    K_TEX = 348
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
#define K_ACOS 291
#define K_ASIN 292
#define K_ATAN 293
#define K_ATAN2 294
#define K_CEIL 295
#define K_COS 296
#define K_EXP 297
#define K_FABS 298
#define K_FLOOR 299
#define K_HYPOT 300
#define K_LN 301
#define K_LOG 302
#define K_PI 303
#define K_POW 304
#define K_SIN 305
#define K_SQRT 306
#define K_TAN 307
#define K_DTR 308
#define K_RTD 309
#define K_MAX 310
#define K_MIN 311
#define K_RND 312
#define K_PV 313
#define K_FV 314
#define K_PMT 315
#define K_HOUR 316
#define K_MINUTE 317
#define K_SECOND 318
#define K_MONTH 319
#define K_DAY 320
#define K_YEAR 321
#define K_NOW 322
#define K_DATE 323
#define K_FMT 324
#define K_SUBSTR 325
#define K_STON 326
#define K_EQS 327
#define K_EXT 328
#define K_NVAL 329
#define K_SVAL 330
#define K_LOOKUP 331
#define K_INDEX 332
#define K_STINDEX 333
#define K_AUTO 334
#define K_AUTOCALC 335
#define K_BYROWS 336
#define K_BYCOLS 337
#define K_BYGRAPH 338
#define K_ITERATIONS 339
#define K_NUMERIC 340
#define K_PRESCALE 341
#define K_EXTFUN 342
#define K_CELLCUR 343
#define K_TOPROW 344
#define K_TBLSTYLE 345
#define K_TBL 346
#define K_LATEX 347
#define K_TEX 348

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 26 "gram.y" /* yacc.c:1909  */

    int ival;
    double fval;
    struct ent_ptr ent;
    struct enode *enode;
    char *sval;
    struct range_s rval;

#line 249 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
