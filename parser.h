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
    EQU = 258,                     /* EQU  */
    SECTION = 259,                 /* SECTION  */
    GLOBL = 260,                   /* GLOBL  */
    ADD = 261,                     /* ADD  */
    ADDI = 262,                    /* ADDI  */
    BEQ = 263,                     /* BEQ  */
    BNE = 264,                     /* BNE  */
    BNEZ = 265,                    /* BNEZ  */
    CALL = 266,                    /* CALL  */
    J = 267,                       /* J  */
    JALR = 268,                    /* JALR  */
    LB = 269,                      /* LB  */
    LI = 270,                      /* LI  */
    LW = 271,                      /* LW  */
    LUI = 272,                     /* LUI  */
    MUL = 273,                     /* MUL  */
    MV = 274,                      /* MV  */
    RET = 275,                     /* RET  */
    SRLI = 276,                    /* SRLI  */
    SLLI = 277,                    /* SLLI  */
    SW = 278,                      /* SW  */
    NEW_LINE = 279,                /* NEW_LINE  */
    NUMERIC = 280,                 /* NUMERIC  */
    IDENTIFIER = 281,              /* IDENTIFIER  */
    DOT = 282,                     /* DOT  */
    COLON = 283,                   /* COLON  */
    COMMA = 284,                   /* COMMA  */
    OPENING_BRACKET = 285,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 286,         /* CLOSING_BRACKET  */
    REG_ZERO = 287,                /* REG_ZERO  */
    REG_RA = 288,                  /* REG_RA  */
    REG_SP = 289,                  /* REG_SP  */
    REG_GP = 290,                  /* REG_GP  */
    REG_TP = 291,                  /* REG_TP  */
    REG_T0 = 292,                  /* REG_T0  */
    REG_T1 = 293,                  /* REG_T1  */
    REG_T2 = 294,                  /* REG_T2  */
    REG_T3 = 295,                  /* REG_T3  */
    REG_T4 = 296,                  /* REG_T4  */
    REG_T5 = 297,                  /* REG_T5  */
    REG_T6 = 298,                  /* REG_T6  */
    REG_FP = 299,                  /* REG_FP  */
    REG_A0 = 300,                  /* REG_A0  */
    REG_A1 = 301,                  /* REG_A1  */
    REG_A2 = 302,                  /* REG_A2  */
    REG_A3 = 303,                  /* REG_A3  */
    REG_A4 = 304,                  /* REG_A4  */
    REG_A5 = 305,                  /* REG_A5  */
    REG_A6 = 306,                  /* REG_A6  */
    REG_A7 = 307,                  /* REG_A7  */
    REG_S0 = 308,                  /* REG_S0  */
    REG_S1 = 309,                  /* REG_S1  */
    REG_S2 = 310,                  /* REG_S2  */
    REG_S3 = 311,                  /* REG_S3  */
    REG_S4 = 312,                  /* REG_S4  */
    REG_S5 = 313,                  /* REG_S5  */
    REG_S6 = 314,                  /* REG_S6  */
    REG_S7 = 315,                  /* REG_S7  */
    REG_S8 = 316,                  /* REG_S8  */
    REG_S9 = 317,                  /* REG_S9  */
    REG_S10 = 318,                 /* REG_S10  */
    REG_S11 = 319                  /* REG_S11  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "parser.y"

  int int_val;
  char string_val[100];
  char sym;
  node_t* expr_ptr;

#line 135 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
