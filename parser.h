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
    DOT_EQU = 258,                 /* DOT_EQU  */
    DOT_SECTION = 259,             /* DOT_SECTION  */
    DOT_GLOBL = 260,               /* DOT_GLOBL  */
    DOT_GLOBAL = 261,              /* DOT_GLOBAL  */
    DOT_TEXT = 262,                /* DOT_TEXT  */
    DOT_DATA = 263,                /* DOT_DATA  */
    DOT_BYTE = 264,                /* DOT_BYTE  */
    DOT_HALF = 265,                /* DOT_HALF  */
    DOT_WORD = 266,                /* DOT_WORD  */
    DOT_DWORD = 267,               /* DOT_DWORD  */
    DOT_FILE = 268,                /* DOT_FILE  */
    DOT_RODATA = 269,              /* DOT_RODATA  */
    DOT_ASCIZ = 270,               /* DOT_ASCIZ  */
    ADD = 271,                     /* ADD  */
    ADDI = 272,                    /* ADDI  */
    AUIPC = 273,                   /* AUIPC  */
    BEQ = 274,                     /* BEQ  */
    BEQZ = 275,                    /* BEQZ  */
    BGE = 276,                     /* BGE  */
    BLT = 277,                     /* BLT  */
    BGT = 278,                     /* BGT  */
    BNE = 279,                     /* BNE  */
    BNEZ = 280,                    /* BNEZ  */
    CALL = 281,                    /* CALL  */
    J = 282,                       /* J  */
    JALR = 283,                    /* JALR  */
    LD = 284,                      /* LD  */
    LW = 285,                      /* LW  */
    LH = 286,                      /* LH  */
    LB = 287,                      /* LB  */
    LI = 288,                      /* LI  */
    LUI = 289,                     /* LUI  */
    MUL = 290,                     /* MUL  */
    MV = 291,                      /* MV  */
    RET = 292,                     /* RET  */
    SRLI = 293,                    /* SRLI  */
    SLLI = 294,                    /* SLLI  */
    SD = 295,                      /* SD  */
    SW = 296,                      /* SW  */
    SH = 297,                      /* SH  */
    SB = 298,                      /* SB  */
    NEW_LINE = 299,                /* NEW_LINE  */
    MODIFIER_HI = 300,             /* MODIFIER_HI  */
    MODIFIER_LO = 301,             /* MODIFIER_LO  */
    NUMERIC = 302,                 /* NUMERIC  */
    IDENTIFIER = 303,              /* IDENTIFIER  */
    STRING_LITERAL = 304,          /* STRING_LITERAL  */
    DOT = 305,                     /* DOT  */
    COLON = 306,                   /* COLON  */
    COMMA = 307,                   /* COMMA  */
    OPENING_BRACKET = 308,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 309,         /* CLOSING_BRACKET  */
    REG_ZERO = 310,                /* REG_ZERO  */
    REG_RA = 311,                  /* REG_RA  */
    REG_SP = 312,                  /* REG_SP  */
    REG_GP = 313,                  /* REG_GP  */
    REG_TP = 314,                  /* REG_TP  */
    REG_T0 = 315,                  /* REG_T0  */
    REG_T1 = 316,                  /* REG_T1  */
    REG_T2 = 317,                  /* REG_T2  */
    REG_T3 = 318,                  /* REG_T3  */
    REG_T4 = 319,                  /* REG_T4  */
    REG_T5 = 320,                  /* REG_T5  */
    REG_T6 = 321,                  /* REG_T6  */
    REG_FP = 322,                  /* REG_FP  */
    REG_A0 = 323,                  /* REG_A0  */
    REG_A1 = 324,                  /* REG_A1  */
    REG_A2 = 325,                  /* REG_A2  */
    REG_A3 = 326,                  /* REG_A3  */
    REG_A4 = 327,                  /* REG_A4  */
    REG_A5 = 328,                  /* REG_A5  */
    REG_A6 = 329,                  /* REG_A6  */
    REG_A7 = 330,                  /* REG_A7  */
    REG_S0 = 331,                  /* REG_S0  */
    REG_S1 = 332,                  /* REG_S1  */
    REG_S2 = 333,                  /* REG_S2  */
    REG_S3 = 334,                  /* REG_S3  */
    REG_S4 = 335,                  /* REG_S4  */
    REG_S5 = 336,                  /* REG_S5  */
    REG_S6 = 337,                  /* REG_S6  */
    REG_S7 = 338,                  /* REG_S7  */
    REG_S8 = 339,                  /* REG_S8  */
    REG_S9 = 340,                  /* REG_S9  */
    REG_S10 = 341,                 /* REG_S10  */
    REG_S11 = 342                  /* REG_S11  */
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

#line 158 "parser.h"

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
