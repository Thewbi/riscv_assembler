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
    DOT_SPACE = 265,               /* DOT_SPACE  */
    DOT_HALF = 266,                /* DOT_HALF  */
    DOT_WORD = 267,                /* DOT_WORD  */
    DOT_DWORD = 268,               /* DOT_DWORD  */
    DOT_FILE = 269,                /* DOT_FILE  */
    DOT_RODATA = 270,              /* DOT_RODATA  */
    DOT_ASCIZ = 271,               /* DOT_ASCIZ  */
    DOT_SKIP = 272,                /* DOT_SKIP  */
    DOT_STRING = 273,              /* DOT_STRING  */
    ADD = 274,                     /* ADD  */
    ADDI = 275,                    /* ADDI  */
    AND = 276,                     /* AND  */
    ANDI = 277,                    /* ANDI  */
    AUIPC = 278,                   /* AUIPC  */
    BEQ = 279,                     /* BEQ  */
    BEQZ = 280,                    /* BEQZ  */
    BGE = 281,                     /* BGE  */
    BLT = 282,                     /* BLT  */
    BGT = 283,                     /* BGT  */
    BNE = 284,                     /* BNE  */
    BNEZ = 285,                    /* BNEZ  */
    CALL = 286,                    /* CALL  */
    ECALL = 287,                   /* ECALL  */
    J = 288,                       /* J  */
    JR = 289,                      /* JR  */
    JALR = 290,                    /* JALR  */
    LA = 291,                      /* LA  */
    LD = 292,                      /* LD  */
    LW = 293,                      /* LW  */
    LH = 294,                      /* LH  */
    LB = 295,                      /* LB  */
    LBU = 296,                     /* LBU  */
    LI = 297,                      /* LI  */
    LUI = 298,                     /* LUI  */
    MUL = 299,                     /* MUL  */
    MV = 300,                      /* MV  */
    NOP = 301,                     /* NOP  */
    NOT = 302,                     /* NOT  */
    RET = 303,                     /* RET  */
    SRLI = 304,                    /* SRLI  */
    SLLI = 305,                    /* SLLI  */
    SD = 306,                      /* SD  */
    SW = 307,                      /* SW  */
    SH = 308,                      /* SH  */
    SB = 309,                      /* SB  */
    WFI = 310,                     /* WFI  */
    NEW_LINE = 311,                /* NEW_LINE  */
    MODIFIER_HI = 312,             /* MODIFIER_HI  */
    MODIFIER_LO = 313,             /* MODIFIER_LO  */
    NUMERIC = 314,                 /* NUMERIC  */
    IDENTIFIER = 315,              /* IDENTIFIER  */
    STRING_LITERAL = 316,          /* STRING_LITERAL  */
    DOT = 317,                     /* DOT  */
    COLON = 318,                   /* COLON  */
    COMMA = 319,                   /* COMMA  */
    OPENING_BRACKET = 320,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 321,         /* CLOSING_BRACKET  */
    REG_ZERO = 322,                /* REG_ZERO  */
    REG_RA = 323,                  /* REG_RA  */
    REG_SP = 324,                  /* REG_SP  */
    REG_GP = 325,                  /* REG_GP  */
    REG_TP = 326,                  /* REG_TP  */
    REG_T0 = 327,                  /* REG_T0  */
    REG_T1 = 328,                  /* REG_T1  */
    REG_T2 = 329,                  /* REG_T2  */
    REG_T3 = 330,                  /* REG_T3  */
    REG_T4 = 331,                  /* REG_T4  */
    REG_T5 = 332,                  /* REG_T5  */
    REG_T6 = 333,                  /* REG_T6  */
    REG_FP = 334,                  /* REG_FP  */
    REG_A0 = 335,                  /* REG_A0  */
    REG_A1 = 336,                  /* REG_A1  */
    REG_A2 = 337,                  /* REG_A2  */
    REG_A3 = 338,                  /* REG_A3  */
    REG_A4 = 339,                  /* REG_A4  */
    REG_A5 = 340,                  /* REG_A5  */
    REG_A6 = 341,                  /* REG_A6  */
    REG_A7 = 342,                  /* REG_A7  */
    REG_S0 = 343,                  /* REG_S0  */
    REG_S1 = 344,                  /* REG_S1  */
    REG_S2 = 345,                  /* REG_S2  */
    REG_S3 = 346,                  /* REG_S3  */
    REG_S4 = 347,                  /* REG_S4  */
    REG_S5 = 348,                  /* REG_S5  */
    REG_S6 = 349,                  /* REG_S6  */
    REG_S7 = 350,                  /* REG_S7  */
    REG_S8 = 351,                  /* REG_S8  */
    REG_S9 = 352,                  /* REG_S9  */
    REG_S10 = 353,                 /* REG_S10  */
    REG_S11 = 354                  /* REG_S11  */
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

#line 170 "parser.h"

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
