
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     FOR = 260,
     WHILE = 261,
     IF = 262,
     ELSE = 263,
     RETURN = 264,
     STRUCT = 265,
     VOID = 266,
     COLON = 267,
     PRINTF = 268,
     LP = 269,
     RP = 270,
     LC = 271,
     RC = 272,
     LS = 273,
     RS = 274,
     ADD = 275,
     SUB = 276,
     MUL = 277,
     DIV = 278,
     MOD = 279,
     NE = 280,
     AND = 281,
     OR = 282,
     NOT = 283,
     ASSIGN = 284,
     EQU = 285,
     SEMI = 286,
     GT = 287,
     LT = 288,
     GE = 289,
     LE = 290,
     COMMA = 291,
     QUES = 292,
     ID = 293,
     STRING_LITERAL = 294,
     NUM = 295,
     FLOAT_NUM = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 41 "cal.y"

    int ival;
    char* sval;



/* Line 1676 of yacc.c  */
#line 100 "cal.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


