/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    ID = 258,
    INTNR = 259,
    ARR = 260,
    FLOATNR = 261,
    DOUBLENR = 262,
    BOOLEAN = 263,
    AND = 264,
    OR = 265,
    NOT = 266,
    INT = 267,
    FLOAT = 268,
    BOOL = 269,
    DOUBLE = 270,
    CHAR = 271,
    VOID = 272,
    CONST = 273,
    STRING = 274,
    STRINGVAL = 275,
    FOR = 276,
    WHILE = 277,
    STRUCT = 278,
    IF = 279,
    ELSE = 280,
    print = 281,
    START_MAIN = 282,
    END_MAIN = 283,
    LE = 284,
    GE = 285,
    EQ = 286,
    NE = 287,
    LT = 288,
    GT = 289
  };
#endif
/* Tokens.  */
#define ID 258
#define INTNR 259
#define ARR 260
#define FLOATNR 261
#define DOUBLENR 262
#define BOOLEAN 263
#define AND 264
#define OR 265
#define NOT 266
#define INT 267
#define FLOAT 268
#define BOOL 269
#define DOUBLE 270
#define CHAR 271
#define VOID 272
#define CONST 273
#define STRING 274
#define STRINGVAL 275
#define FOR 276
#define WHILE 277
#define STRUCT 278
#define IF 279
#define ELSE 280
#define print 281
#define START_MAIN 282
#define END_MAIN 283
#define LE 284
#define GE 285
#define EQ 286
#define NE 287
#define LT 288
#define GT 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 49 "limbaj.y" /* yacc.c:1909  */

   char* textt;

#line 126 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
