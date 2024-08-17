/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD = 258,                     /* ADD  */
    JALR = 259,                    /* JALR  */
    LI = 260,                      /* LI  */
    NEW_LINE = 261,                /* NEW_LINE  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    NUMERIC = 263,                 /* NUMERIC  */
    SECTION = 264,                 /* SECTION  */
    GLOBAL = 265,                  /* GLOBAL  */
    DOT = 266,                     /* DOT  */
    COLON = 267,                   /* COLON  */
    COMMA = 268,                   /* COMMA  */
    REG_ZERO = 269,                /* REG_ZERO  */
    REG_RA = 270,                  /* REG_RA  */
    REG_SP = 271,                  /* REG_SP  */
    REG_GP = 272,                  /* REG_GP  */
    REG_TP = 273,                  /* REG_TP  */
    REG_T0 = 274,                  /* REG_T0  */
    REG_T1 = 275,                  /* REG_T1  */
    REG_T2 = 276,                  /* REG_T2  */
    REG_T3 = 277,                  /* REG_T3  */
    REG_T4 = 278,                  /* REG_T4  */
    REG_T5 = 279,                  /* REG_T5  */
    REG_T6 = 280,                  /* REG_T6  */
    REG_FP = 281,                  /* REG_FP  */
    REG_A0 = 282,                  /* REG_A0  */
    REG_A1 = 283,                  /* REG_A1  */
    REG_A2 = 284,                  /* REG_A2  */
    REG_A3 = 285,                  /* REG_A3  */
    REG_A4 = 286,                  /* REG_A4  */
    REG_A5 = 287,                  /* REG_A5  */
    REG_A6 = 288,                  /* REG_A6  */
    REG_A7 = 289,                  /* REG_A7  */
    REG_S0 = 290,                  /* REG_S0  */
    REG_S1 = 291,                  /* REG_S1  */
    REG_S2 = 292,                  /* REG_S2  */
    REG_S3 = 293,                  /* REG_S3  */
    REG_S4 = 294,                  /* REG_S4  */
    REG_S5 = 295,                  /* REG_S5  */
    REG_S6 = 296,                  /* REG_S6  */
    REG_S7 = 297,                  /* REG_S7  */
    REG_S8 = 298,                  /* REG_S8  */
    REG_S9 = 299,                  /* REG_S9  */
    REG_S10 = 300,                 /* REG_S10  */
    REG_S11 = 301                  /* REG_S11  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "parser.ypp"

  int val; 
  char sym;

#line 115 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
