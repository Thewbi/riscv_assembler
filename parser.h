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
    ADDI = 259,                    /* ADDI  */
    BEQ = 260,                     /* BEQ  */
    JALR = 261,                    /* JALR  */
    LB = 262,                      /* LB  */
    LI = 263,                      /* LI  */
    LW = 264,                      /* LW  */
    MUL = 265,                     /* MUL  */
    SRLI = 266,                    /* SRLI  */
    SLLI = 267,                    /* SLLI  */
    SW = 268,                      /* SW  */
    NEW_LINE = 269,                /* NEW_LINE  */
    NUMERIC = 270,                 /* NUMERIC  */
    IDENTIFIER = 271,              /* IDENTIFIER  */
    SECTION = 272,                 /* SECTION  */
    GLOBAL = 273,                  /* GLOBAL  */
    DOT = 274,                     /* DOT  */
    COLON = 275,                   /* COLON  */
    COMMA = 276,                   /* COMMA  */
    OPENING_BRACKET = 277,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 278,         /* CLOSING_BRACKET  */
    REG_ZERO = 279,                /* REG_ZERO  */
    REG_RA = 280,                  /* REG_RA  */
    REG_SP = 281,                  /* REG_SP  */
    REG_GP = 282,                  /* REG_GP  */
    REG_TP = 283,                  /* REG_TP  */
    REG_T0 = 284,                  /* REG_T0  */
    REG_T1 = 285,                  /* REG_T1  */
    REG_T2 = 286,                  /* REG_T2  */
    REG_T3 = 287,                  /* REG_T3  */
    REG_T4 = 288,                  /* REG_T4  */
    REG_T5 = 289,                  /* REG_T5  */
    REG_T6 = 290,                  /* REG_T6  */
    REG_FP = 291,                  /* REG_FP  */
    REG_A0 = 292,                  /* REG_A0  */
    REG_A1 = 293,                  /* REG_A1  */
    REG_A2 = 294,                  /* REG_A2  */
    REG_A3 = 295,                  /* REG_A3  */
    REG_A4 = 296,                  /* REG_A4  */
    REG_A5 = 297,                  /* REG_A5  */
    REG_A6 = 298,                  /* REG_A6  */
    REG_A7 = 299,                  /* REG_A7  */
    REG_S0 = 300,                  /* REG_S0  */
    REG_S1 = 301,                  /* REG_S1  */
    REG_S2 = 302,                  /* REG_S2  */
    REG_S3 = 303,                  /* REG_S3  */
    REG_S4 = 304,                  /* REG_S4  */
    REG_S5 = 305,                  /* REG_S5  */
    REG_S6 = 306,                  /* REG_S6  */
    REG_S7 = 307,                  /* REG_S7  */
    REG_S8 = 308,                  /* REG_S8  */
    REG_S9 = 309,                  /* REG_S9  */
    REG_S10 = 310,                 /* REG_S10  */
    REG_S11 = 311                  /* REG_S11  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "parser.y"

  int int_val; 
  char sym;

#line 125 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
