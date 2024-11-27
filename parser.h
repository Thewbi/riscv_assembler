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
    DOT_SKIP = 271,                /* DOT_SKIP  */
    DOT_STRING = 272,              /* DOT_STRING  */
    ADD = 273,                     /* ADD  */
    ADDI = 274,                    /* ADDI  */
    AND = 275,                     /* AND  */
    ANDI = 276,                    /* ANDI  */
    AUIPC = 277,                   /* AUIPC  */
    BEQ = 278,                     /* BEQ  */
    BEQZ = 279,                    /* BEQZ  */
    BGE = 280,                     /* BGE  */
    BLT = 281,                     /* BLT  */
    BGT = 282,                     /* BGT  */
    BNE = 283,                     /* BNE  */
    BNEZ = 284,                    /* BNEZ  */
    CALL = 285,                    /* CALL  */
    J = 286,                       /* J  */
    JR = 287,                      /* JR  */
    JALR = 288,                    /* JALR  */
    LD = 289,                      /* LD  */
    LW = 290,                      /* LW  */
    LH = 291,                      /* LH  */
    LB = 292,                      /* LB  */
    LBU = 293,                     /* LBU  */
    LI = 294,                      /* LI  */
    LUI = 295,                     /* LUI  */
    MUL = 296,                     /* MUL  */
    MV = 297,                      /* MV  */
    NOP = 298,                     /* NOP  */
    NOT = 299,                     /* NOT  */
    RET = 300,                     /* RET  */
    SRLI = 301,                    /* SRLI  */
    SLLI = 302,                    /* SLLI  */
    SD = 303,                      /* SD  */
    SW = 304,                      /* SW  */
    SH = 305,                      /* SH  */
    SB = 306,                      /* SB  */
    WFI = 307,                     /* WFI  */
    NEW_LINE = 308,                /* NEW_LINE  */
    MODIFIER_HI = 309,             /* MODIFIER_HI  */
    MODIFIER_LO = 310,             /* MODIFIER_LO  */
    NUMERIC = 311,                 /* NUMERIC  */
    IDENTIFIER = 312,              /* IDENTIFIER  */
    STRING_LITERAL = 313,          /* STRING_LITERAL  */
    DOT = 314,                     /* DOT  */
    COLON = 315,                   /* COLON  */
    COMMA = 316,                   /* COMMA  */
    OPENING_BRACKET = 317,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 318,         /* CLOSING_BRACKET  */
    REG_ZERO = 319,                /* REG_ZERO  */
    REG_RA = 320,                  /* REG_RA  */
    REG_SP = 321,                  /* REG_SP  */
    REG_GP = 322,                  /* REG_GP  */
    REG_TP = 323,                  /* REG_TP  */
    REG_T0 = 324,                  /* REG_T0  */
    REG_T1 = 325,                  /* REG_T1  */
    REG_T2 = 326,                  /* REG_T2  */
    REG_T3 = 327,                  /* REG_T3  */
    REG_T4 = 328,                  /* REG_T4  */
    REG_T5 = 329,                  /* REG_T5  */
    REG_T6 = 330,                  /* REG_T6  */
    REG_FP = 331,                  /* REG_FP  */
    REG_A0 = 332,                  /* REG_A0  */
    REG_A1 = 333,                  /* REG_A1  */
    REG_A2 = 334,                  /* REG_A2  */
    REG_A3 = 335,                  /* REG_A3  */
    REG_A4 = 336,                  /* REG_A4  */
    REG_A5 = 337,                  /* REG_A5  */
    REG_A6 = 338,                  /* REG_A6  */
    REG_A7 = 339,                  /* REG_A7  */
    REG_S0 = 340,                  /* REG_S0  */
    REG_S1 = 341,                  /* REG_S1  */
    REG_S2 = 342,                  /* REG_S2  */
    REG_S3 = 343,                  /* REG_S3  */
    REG_S4 = 344,                  /* REG_S4  */
    REG_S5 = 345,                  /* REG_S5  */
    REG_S6 = 346,                  /* REG_S6  */
    REG_S7 = 347,                  /* REG_S7  */
    REG_S8 = 348,                  /* REG_S8  */
    REG_S9 = 349,                  /* REG_S9  */
    REG_S10 = 350,                 /* REG_S10  */
    REG_S11 = 351                  /* REG_S11  */
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

#line 167 "parser.h"

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
