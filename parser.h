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
    GLOBAL = 261,                  /* GLOBAL  */
    TEXT = 262,                    /* TEXT  */
    DATA = 263,                    /* DATA  */
    BYTE = 264,                    /* BYTE  */
    HALF = 265,                    /* HALF  */
    WORD = 266,                    /* WORD  */
    DWORD = 267,                   /* DWORD  */
    ADD = 268,                     /* ADD  */
    ADDI = 269,                    /* ADDI  */
    AUIPC = 270,                   /* AUIPC  */
    BEQ = 271,                     /* BEQ  */
    BEQZ = 272,                    /* BEQZ  */
    BNE = 273,                     /* BNE  */
    BNEZ = 274,                    /* BNEZ  */
    CALL = 275,                    /* CALL  */
    J = 276,                       /* J  */
    JALR = 277,                    /* JALR  */
    LB = 278,                      /* LB  */
    LH = 279,                      /* LH  */
    LI = 280,                      /* LI  */
    LW = 281,                      /* LW  */
    LUI = 282,                     /* LUI  */
    MUL = 283,                     /* MUL  */
    MV = 284,                      /* MV  */
    RET = 285,                     /* RET  */
    SRLI = 286,                    /* SRLI  */
    SLLI = 287,                    /* SLLI  */
    SW = 288,                      /* SW  */
    NEW_LINE = 289,                /* NEW_LINE  */
    NUMERIC = 290,                 /* NUMERIC  */
    IDENTIFIER = 291,              /* IDENTIFIER  */
    DOT = 292,                     /* DOT  */
    COLON = 293,                   /* COLON  */
    COMMA = 294,                   /* COMMA  */
    OPENING_BRACKET = 295,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 296,         /* CLOSING_BRACKET  */
    REG_ZERO = 297,                /* REG_ZERO  */
    REG_RA = 298,                  /* REG_RA  */
    REG_SP = 299,                  /* REG_SP  */
    REG_GP = 300,                  /* REG_GP  */
    REG_TP = 301,                  /* REG_TP  */
    REG_T0 = 302,                  /* REG_T0  */
    REG_T1 = 303,                  /* REG_T1  */
    REG_T2 = 304,                  /* REG_T2  */
    REG_T3 = 305,                  /* REG_T3  */
    REG_T4 = 306,                  /* REG_T4  */
    REG_T5 = 307,                  /* REG_T5  */
    REG_T6 = 308,                  /* REG_T6  */
    REG_FP = 309,                  /* REG_FP  */
    REG_A0 = 310,                  /* REG_A0  */
    REG_A1 = 311,                  /* REG_A1  */
    REG_A2 = 312,                  /* REG_A2  */
    REG_A3 = 313,                  /* REG_A3  */
    REG_A4 = 314,                  /* REG_A4  */
    REG_A5 = 315,                  /* REG_A5  */
    REG_A6 = 316,                  /* REG_A6  */
    REG_A7 = 317,                  /* REG_A7  */
    REG_S0 = 318,                  /* REG_S0  */
    REG_S1 = 319,                  /* REG_S1  */
    REG_S2 = 320,                  /* REG_S2  */
    REG_S3 = 321,                  /* REG_S3  */
    REG_S4 = 322,                  /* REG_S4  */
    REG_S5 = 323,                  /* REG_S5  */
    REG_S6 = 324,                  /* REG_S6  */
    REG_S7 = 325,                  /* REG_S7  */
    REG_S8 = 326,                  /* REG_S8  */
    REG_S9 = 327,                  /* REG_S9  */
    REG_S10 = 328,                 /* REG_S10  */
    REG_S11 = 329                  /* REG_S11  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "parser.y"

    uint64_t int_val;
    char string_val[100];
    char sym;
    node_t* expr_ptr;

#line 145 "parser.h"

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
