
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
     NUM = 258,
     LCADENA = 259,
     ID = 260,
     TIPODATO = 261,
     PRESERVADA = 262,
     MODALIDAD = 263,
     AND = 264,
     PUNTUACION = 265,
     INCREMENTO = 266,
     DECREMENTO = 267,
     SUMADIRECTA = 268,
     RESTADIRECTA = 269,
     OR = 270,
     VOID = 271,
     MAYORIGUAL = 272,
     MENORIGUAL = 273,
     PERTENECE = 274,
     DESIGUALDAD = 275,
     IGUALDAD = 276,
     RETURN = 277,
     IF = 278,
     DO = 279,
     WHILE = 280,
     ELSE = 281,
     FOR = 282,
     TYPEDEF = 283,
     STRUCT = 284,
     SIZEOF = 285,
     SWITCH = 286,
     CASE = 287,
     BREAK = 288,
     CONTINUE = 289,
     CONTROLOTRA = 290,
     OPERADOR = 291,
     CONDICION = 292,
     DEFAULT = 293,
     NEG = 294,
     POS = 295,
     PUNT = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 29 "TP4.y"

    struct{
    char cadena[50];
    double valor;
    int tipo;
  }s; 



/* Line 1676 of yacc.c  */
#line 103 "TP4.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


