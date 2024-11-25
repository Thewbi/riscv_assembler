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
    BGE = 273,                     /* BGE  */
    BLT = 274,                     /* BLT  */
    BGT = 275,                     /* BGT  */
    BNE = 276,                     /* BNE  */
    BNEZ = 277,                    /* BNEZ  */
    CALL = 278,                    /* CALL  */
    J = 279,                       /* J  */
    JALR = 280,                    /* JALR  */
    LD = 281,                      /* LD  */
    LW = 282,                      /* LW  */
    LH = 283,                      /* LH  */
    LB = 284,                      /* LB  */
    LI = 285,                      /* LI  */
    LUI = 286,                     /* LUI  */
    MUL = 287,                     /* MUL  */
    MV = 288,                      /* MV  */
    RET = 289,                     /* RET  */
    SRLI = 290,                    /* SRLI  */
    SLLI = 291,                    /* SLLI  */
    SD = 292,                      /* SD  */
    SW = 293,                      /* SW  */
    SH = 294,                      /* SH  */
    SB = 295,                      /* SB  */
    NEW_LINE = 296,                /* NEW_LINE  */
    MODIFIER_HI = 297,             /* MODIFIER_HI  */
    MODIFIER_LO = 298,             /* MODIFIER_LO  */
    NUMERIC = 299,                 /* NUMERIC  */
    IDENTIFIER = 300,              /* IDENTIFIER  */
    DOT = 301,                     /* DOT  */
    COLON = 302,                   /* COLON  */
    COMMA = 303,                   /* COMMA  */
    OPENING_BRACKET = 304,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 305,         /* CLOSING_BRACKET  */
    REG_ZERO = 306,                /* REG_ZERO  */
    REG_RA = 307,                  /* REG_RA  */
    REG_SP = 308,                  /* REG_SP  */
    REG_GP = 309,                  /* REG_GP  */
    REG_TP = 310,                  /* REG_TP  */
    REG_T0 = 311,                  /* REG_T0  */
    REG_T1 = 312,                  /* REG_T1  */
    REG_T2 = 313,                  /* REG_T2  */
    REG_T3 = 314,                  /* REG_T3  */
    REG_T4 = 315,                  /* REG_T4  */
    REG_T5 = 316,                  /* REG_T5  */
    REG_T6 = 317,                  /* REG_T6  */
    REG_FP = 318,                  /* REG_FP  */
    REG_A0 = 319,                  /* REG_A0  */
    REG_A1 = 320,                  /* REG_A1  */
    REG_A2 = 321,                  /* REG_A2  */
    REG_A3 = 322,                  /* REG_A3  */
    REG_A4 = 323,                  /* REG_A4  */
    REG_A5 = 324,                  /* REG_A5  */
    REG_A6 = 325,                  /* REG_A6  */
    REG_A7 = 326,                  /* REG_A7  */
    REG_S0 = 327,                  /* REG_S0  */
    REG_S1 = 328,                  /* REG_S1  */
    REG_S2 = 329,                  /* REG_S2  */
    REG_S3 = 330,                  /* REG_S3  */
    REG_S4 = 331,                  /* REG_S4  */
    REG_S5 = 332,                  /* REG_S5  */
    REG_S6 = 333,                  /* REG_S6  */
    REG_S7 = 334,                  /* REG_S7  */
    REG_S8 = 335,                  /* REG_S8  */
    REG_S9 = 336,                  /* REG_S9  */
    REG_S10 = 337,                 /* REG_S10  */
    REG_S11 = 338                  /* REG_S11  */
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

#line 154 "parser.h"

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
