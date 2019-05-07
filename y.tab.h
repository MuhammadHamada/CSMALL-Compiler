
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
     INTEGER = 258,
     DECIMAL = 259,
     CHARACTER = 260,
     VAR = 261,
     CONST = 262,
     INT = 263,
     FLOAT = 264,
     CHAR = 265,
     BOOL = 266,
     ENDOFFILE = 267,
     GE = 268,
     LE = 269,
     GT = 270,
     LT = 271,
     EQ = 272,
     NE = 273,
     NOT = 274,
     AND = 275,
     OR = 276,
     WHILE = 277,
     FOR = 278,
     DO = 279,
     IF = 280,
     ELSE = 281,
     SWITCH = 282,
     CASE = 283,
     DEFAULT = 284,
     BREAK = 285,
     BOOL_TRUE = 286,
     BOOL_FALSE = 287,
     UMINUS = 288,
     IFX = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 109 "csmall-parser.y"

  char* val; 
      		
	char* name;

  struct info1{
    int type;
    char val[100];
  }info;
		




/* Line 1676 of yacc.c  */
#line 101 "csmall-parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


