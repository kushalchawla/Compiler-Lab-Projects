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
    VAR = 258,
    PROTOTYPE = 259,
    DEF = 260,
    INT = 261,
    BOOL = 262,
    CHAR = 263,
    BEG = 264,
    END = 265,
    RET = 266,
    ASSIGN = 267,
    CALL = 268,
    SCAN = 269,
    PRINT = 270,
    ENDL = 271,
    SPACE = 272,
    WHILE = 273,
    IF = 274,
    THEN = 275,
    ID = 276,
    NUM = 277,
    CH = 278
  };
#endif
/* Tokens.  */
#define VAR 258
#define PROTOTYPE 259
#define DEF 260
#define INT 261
#define BOOL 262
#define CHAR 263
#define BEG 264
#define END 265
#define RET 266
#define ASSIGN 267
#define CALL 268
#define SCAN 269
#define PRINT 270
#define ENDL 271
#define SPACE 272
#define WHILE 273
#define IF 274
#define THEN 275
#define ID 276
#define NUM 277
#define CH 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
