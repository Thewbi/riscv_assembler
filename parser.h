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
    LUI = 265,                     /* LUI  */
    MUL = 266,                     /* MUL  */
    MV = 267,                      /* MV  */
    SRLI = 268,                    /* SRLI  */
    SLLI = 269,                    /* SLLI  */
    SW = 270,                      /* SW  */
    NEW_LINE = 271,                /* NEW_LINE  */
    NUMERIC = 272,                 /* NUMERIC  */
    IDENTIFIER = 273,              /* IDENTIFIER  */
    SECTION = 274,                 /* SECTION  */
    GLOBAL = 275,                  /* GLOBAL  */
    DOT = 276,                     /* DOT  */
    COLON = 277,                   /* COLON  */
    COMMA = 278,                   /* COMMA  */
    OPENING_BRACKET = 279,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 280,         /* CLOSING_BRACKET  */
    REG_ZERO = 281,                /* REG_ZERO  */
    REG_RA = 282,                  /* REG_RA  */
    REG_SP = 283,                  /* REG_SP  */
    REG_GP = 284,                  /* REG_GP  */
    REG_TP = 285,                  /* REG_TP  */
    REG_T0 = 286,                  /* REG_T0  */
    REG_T1 = 287,                  /* REG_T1  */
    REG_T2 = 288,                  /* REG_T2  */
    REG_T3 = 289,                  /* REG_T3  */
    REG_T4 = 290,                  /* REG_T4  */
    REG_T5 = 291,                  /* REG_T5  */
    REG_T6 = 292,                  /* REG_T6  */
    REG_FP = 293,                  /* REG_FP  */
    REG_A0 = 294,                  /* REG_A0  */
    REG_A1 = 295,                  /* REG_A1  */
    REG_A2 = 296,                  /* REG_A2  */
    REG_A3 = 297,                  /* REG_A3  */
    REG_A4 = 298,                  /* REG_A4  */
    REG_A5 = 299,                  /* REG_A5  */
    REG_A6 = 300,                  /* REG_A6  */
    REG_A7 = 301,                  /* REG_A7  */
    REG_S0 = 302,                  /* REG_S0  */
    REG_S1 = 303,                  /* REG_S1  */
    REG_S2 = 304,                  /* REG_S2  */
    REG_S3 = 305,                  /* REG_S3  */
    REG_S4 = 306,                  /* REG_S4  */
    REG_S5 = 307,                  /* REG_S5  */
    REG_S6 = 308,                  /* REG_S6  */
    REG_S7 = 309,                  /* REG_S7  */
    REG_S8 = 310,                  /* REG_S8  */
    REG_S9 = 311,                  /* REG_S9  */
    REG_S10 = 312,                 /* REG_S10  */
    REG_S11 = 313                  /* REG_S11  */
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

#line 127 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
