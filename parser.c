/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "parser.y"


#include <stdio.h>
//#include <cstring>

#include <asm_line.h>
#include <encoder.h>
#include <common.h>
#include <node.h>

#define YYDEBUG 1
#define YYERROR_VERBOSE 1

extern int yylineno;

node_t* current_node = NULL;

// defining this symbol makes the generated riscv emulator or assembler a self sustained
// application that works without an external driver. It defines all
// symbols to become self-sustained.
//
// If you would rather not have the symbols
// defined because you are building an external driver, then do not
// define the USE_INTERNAL_DRIVER symbol
//#define USE_INTERNAL_DRIVER 1

//-- Lexer prototype required by bison, aka getNextToken()
int yylex();
int yyerror(const char *p) { printf("yyerror() - Error! '%s' | Line: %d \n", p, yylineno); return 1; }

#ifdef USE_INTERNAL_DRIVER
    asm_line_t parser_asm_line;
#else
    extern asm_line_t parser_asm_line;
#endif

// https://www.geeksforgeeks.org/function-pointer-in-c/
void (*fp_emit)(asm_line_t*);


#line 112 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


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
    ADD = 262,                     /* ADD  */
    ADDI = 263,                    /* ADDI  */
    AUIPC = 264,                   /* AUIPC  */
    BEQ = 265,                     /* BEQ  */
    BEQZ = 266,                    /* BEQZ  */
    BNE = 267,                     /* BNE  */
    BNEZ = 268,                    /* BNEZ  */
    CALL = 269,                    /* CALL  */
    J = 270,                       /* J  */
    JALR = 271,                    /* JALR  */
    LB = 272,                      /* LB  */
    LI = 273,                      /* LI  */
    LW = 274,                      /* LW  */
    LUI = 275,                     /* LUI  */
    MUL = 276,                     /* MUL  */
    MV = 277,                      /* MV  */
    RET = 278,                     /* RET  */
    SRLI = 279,                    /* SRLI  */
    SLLI = 280,                    /* SLLI  */
    SW = 281,                      /* SW  */
    NEW_LINE = 282,                /* NEW_LINE  */
    NUMERIC = 283,                 /* NUMERIC  */
    IDENTIFIER = 284,              /* IDENTIFIER  */
    DOT = 285,                     /* DOT  */
    COLON = 286,                   /* COLON  */
    COMMA = 287,                   /* COMMA  */
    OPENING_BRACKET = 288,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 289,         /* CLOSING_BRACKET  */
    REG_ZERO = 290,                /* REG_ZERO  */
    REG_RA = 291,                  /* REG_RA  */
    REG_SP = 292,                  /* REG_SP  */
    REG_GP = 293,                  /* REG_GP  */
    REG_TP = 294,                  /* REG_TP  */
    REG_T0 = 295,                  /* REG_T0  */
    REG_T1 = 296,                  /* REG_T1  */
    REG_T2 = 297,                  /* REG_T2  */
    REG_T3 = 298,                  /* REG_T3  */
    REG_T4 = 299,                  /* REG_T4  */
    REG_T5 = 300,                  /* REG_T5  */
    REG_T6 = 301,                  /* REG_T6  */
    REG_FP = 302,                  /* REG_FP  */
    REG_A0 = 303,                  /* REG_A0  */
    REG_A1 = 304,                  /* REG_A1  */
    REG_A2 = 305,                  /* REG_A2  */
    REG_A3 = 306,                  /* REG_A3  */
    REG_A4 = 307,                  /* REG_A4  */
    REG_A5 = 308,                  /* REG_A5  */
    REG_A6 = 309,                  /* REG_A6  */
    REG_A7 = 310,                  /* REG_A7  */
    REG_S0 = 311,                  /* REG_S0  */
    REG_S1 = 312,                  /* REG_S1  */
    REG_S2 = 313,                  /* REG_S2  */
    REG_S3 = 314,                  /* REG_S3  */
    REG_S4 = 315,                  /* REG_S4  */
    REG_S5 = 316,                  /* REG_S5  */
    REG_S6 = 317,                  /* REG_S6  */
    REG_S7 = 318,                  /* REG_S7  */
    REG_S8 = 319,                  /* REG_S8  */
    REG_S9 = 320,                  /* REG_S9  */
    REG_S10 = 321,                 /* REG_S10  */
    REG_S11 = 322                  /* REG_S11  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define EQU 258
#define SECTION 259
#define GLOBL 260
#define GLOBAL 261
#define ADD 262
#define ADDI 263
#define AUIPC 264
#define BEQ 265
#define BEQZ 266
#define BNE 267
#define BNEZ 268
#define CALL 269
#define J 270
#define JALR 271
#define LB 272
#define LI 273
#define LW 274
#define LUI 275
#define MUL 276
#define MV 277
#define RET 278
#define SRLI 279
#define SLLI 280
#define SW 281
#define NEW_LINE 282
#define NUMERIC 283
#define IDENTIFIER 284
#define DOT 285
#define COLON 286
#define COMMA 287
#define OPENING_BRACKET 288
#define CLOSING_BRACKET 289
#define REG_ZERO 290
#define REG_RA 291
#define REG_SP 292
#define REG_GP 293
#define REG_TP 294
#define REG_T0 295
#define REG_T1 296
#define REG_T2 297
#define REG_T3 298
#define REG_T4 299
#define REG_T5 300
#define REG_T6 301
#define REG_FP 302
#define REG_A0 303
#define REG_A1 304
#define REG_A2 305
#define REG_A3 306
#define REG_A4 307
#define REG_A5 308
#define REG_A6 309
#define REG_A7 310
#define REG_S0 311
#define REG_S1 312
#define REG_S2 313
#define REG_S3 314
#define REG_S4 315
#define REG_S5 316
#define REG_S6 317
#define REG_S7 318
#define REG_S8 319
#define REG_S9 320
#define REG_S10 321
#define REG_S11 322

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "parser.y"

  int int_val;
  char string_val[100];
  char sym;
  node_t* expr_ptr;

#line 303 "y.tab.c"

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



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EQU = 3,                        /* EQU  */
  YYSYMBOL_SECTION = 4,                    /* SECTION  */
  YYSYMBOL_GLOBL = 5,                      /* GLOBL  */
  YYSYMBOL_GLOBAL = 6,                     /* GLOBAL  */
  YYSYMBOL_ADD = 7,                        /* ADD  */
  YYSYMBOL_ADDI = 8,                       /* ADDI  */
  YYSYMBOL_AUIPC = 9,                      /* AUIPC  */
  YYSYMBOL_BEQ = 10,                       /* BEQ  */
  YYSYMBOL_BEQZ = 11,                      /* BEQZ  */
  YYSYMBOL_BNE = 12,                       /* BNE  */
  YYSYMBOL_BNEZ = 13,                      /* BNEZ  */
  YYSYMBOL_CALL = 14,                      /* CALL  */
  YYSYMBOL_J = 15,                         /* J  */
  YYSYMBOL_JALR = 16,                      /* JALR  */
  YYSYMBOL_LB = 17,                        /* LB  */
  YYSYMBOL_LI = 18,                        /* LI  */
  YYSYMBOL_LW = 19,                        /* LW  */
  YYSYMBOL_LUI = 20,                       /* LUI  */
  YYSYMBOL_MUL = 21,                       /* MUL  */
  YYSYMBOL_MV = 22,                        /* MV  */
  YYSYMBOL_RET = 23,                       /* RET  */
  YYSYMBOL_SRLI = 24,                      /* SRLI  */
  YYSYMBOL_SLLI = 25,                      /* SLLI  */
  YYSYMBOL_SW = 26,                        /* SW  */
  YYSYMBOL_NEW_LINE = 27,                  /* NEW_LINE  */
  YYSYMBOL_NUMERIC = 28,                   /* NUMERIC  */
  YYSYMBOL_IDENTIFIER = 29,                /* IDENTIFIER  */
  YYSYMBOL_DOT = 30,                       /* DOT  */
  YYSYMBOL_COLON = 31,                     /* COLON  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_OPENING_BRACKET = 33,           /* OPENING_BRACKET  */
  YYSYMBOL_CLOSING_BRACKET = 34,           /* CLOSING_BRACKET  */
  YYSYMBOL_REG_ZERO = 35,                  /* REG_ZERO  */
  YYSYMBOL_REG_RA = 36,                    /* REG_RA  */
  YYSYMBOL_REG_SP = 37,                    /* REG_SP  */
  YYSYMBOL_REG_GP = 38,                    /* REG_GP  */
  YYSYMBOL_REG_TP = 39,                    /* REG_TP  */
  YYSYMBOL_REG_T0 = 40,                    /* REG_T0  */
  YYSYMBOL_REG_T1 = 41,                    /* REG_T1  */
  YYSYMBOL_REG_T2 = 42,                    /* REG_T2  */
  YYSYMBOL_REG_T3 = 43,                    /* REG_T3  */
  YYSYMBOL_REG_T4 = 44,                    /* REG_T4  */
  YYSYMBOL_REG_T5 = 45,                    /* REG_T5  */
  YYSYMBOL_REG_T6 = 46,                    /* REG_T6  */
  YYSYMBOL_REG_FP = 47,                    /* REG_FP  */
  YYSYMBOL_REG_A0 = 48,                    /* REG_A0  */
  YYSYMBOL_REG_A1 = 49,                    /* REG_A1  */
  YYSYMBOL_REG_A2 = 50,                    /* REG_A2  */
  YYSYMBOL_REG_A3 = 51,                    /* REG_A3  */
  YYSYMBOL_REG_A4 = 52,                    /* REG_A4  */
  YYSYMBOL_REG_A5 = 53,                    /* REG_A5  */
  YYSYMBOL_REG_A6 = 54,                    /* REG_A6  */
  YYSYMBOL_REG_A7 = 55,                    /* REG_A7  */
  YYSYMBOL_REG_S0 = 56,                    /* REG_S0  */
  YYSYMBOL_REG_S1 = 57,                    /* REG_S1  */
  YYSYMBOL_REG_S2 = 58,                    /* REG_S2  */
  YYSYMBOL_REG_S3 = 59,                    /* REG_S3  */
  YYSYMBOL_REG_S4 = 60,                    /* REG_S4  */
  YYSYMBOL_REG_S5 = 61,                    /* REG_S5  */
  YYSYMBOL_REG_S6 = 62,                    /* REG_S6  */
  YYSYMBOL_REG_S7 = 63,                    /* REG_S7  */
  YYSYMBOL_REG_S8 = 64,                    /* REG_S8  */
  YYSYMBOL_REG_S9 = 65,                    /* REG_S9  */
  YYSYMBOL_REG_S10 = 66,                   /* REG_S10  */
  YYSYMBOL_REG_S11 = 67,                   /* REG_S11  */
  YYSYMBOL_YYACCEPT = 68,                  /* $accept  */
  YYSYMBOL_asm_file = 69,                  /* asm_file  */
  YYSYMBOL_line_end = 70,                  /* line_end  */
  YYSYMBOL_asm_line = 71,                  /* asm_line  */
  YYSYMBOL_params = 72,                    /* params  */
  YYSYMBOL_param_1 = 73,                   /* param_1  */
  YYSYMBOL_74_1 = 74,                      /* $@1  */
  YYSYMBOL_75_2 = 75,                      /* $@2  */
  YYSYMBOL_param_2 = 76,                   /* param_2  */
  YYSYMBOL_77_3 = 77,                      /* $@3  */
  YYSYMBOL_78_4 = 78,                      /* $@4  */
  YYSYMBOL_param_3 = 79,                   /* param_3  */
  YYSYMBOL_80_5 = 80,                      /* $@5  */
  YYSYMBOL_81_6 = 81,                      /* $@6  */
  YYSYMBOL_label = 82,                     /* label  */
  YYSYMBOL_expr = 83,                      /* expr  */
  YYSYMBOL_assembler_instruction = 84,     /* assembler_instruction  */
  YYSYMBOL_mnemonic = 85,                  /* mnemonic  */
  YYSYMBOL_register = 86                   /* register  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    82,    84,    86,    88,    90,    93,   103,
     113,   122,   131,   146,   155,   158,   161,   166,   166,   171,
     171,   176,   183,   183,   188,   188,   193,   200,   200,   205,
     205,   210,   217,   221,   230,   257,   262,   283,   300,   310,
     321,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EQU", "SECTION",
  "GLOBL", "GLOBAL", "ADD", "ADDI", "AUIPC", "BEQ", "BEQZ", "BNE", "BNEZ",
  "CALL", "J", "JALR", "LB", "LI", "LW", "LUI", "MUL", "MV", "RET", "SRLI",
  "SLLI", "SW", "NEW_LINE", "NUMERIC", "IDENTIFIER", "DOT", "COLON",
  "COMMA", "OPENING_BRACKET", "CLOSING_BRACKET", "REG_ZERO", "REG_RA",
  "REG_SP", "REG_GP", "REG_TP", "REG_T0", "REG_T1", "REG_T2", "REG_T3",
  "REG_T4", "REG_T5", "REG_T6", "REG_FP", "REG_A0", "REG_A1", "REG_A2",
  "REG_A3", "REG_A4", "REG_A5", "REG_A6", "REG_A7", "REG_S0", "REG_S1",
  "REG_S2", "REG_S3", "REG_S4", "REG_S5", "REG_S6", "REG_S7", "REG_S8",
  "REG_S9", "REG_S10", "REG_S11", "$accept", "asm_file", "line_end",
  "asm_line", "params", "param_1", "$@1", "$@2", "param_2", "$@3", "$@4",
  "param_3", "$@5", "$@6", "label", "expr", "assembler_instruction",
  "mnemonic", "register", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     189,   -27,   -26,   -25,   -24,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,    11,    13,     6,   189,
      16,   212,   -29,   -28,    14,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   189,   -28,    49,    50,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
      53,   -29,   -29,    12,   -29,   -29,    12,    12,    52,   -29,
     -29,   -29,   -29,   -29,    51,    89,    54,   -29,    90,    91,
      12,    12,    92,   -29,   -29,   -29,   -29,    93,   129,   -29,
     -29,   133,   134,    12,    12,   -29,   -29,   -29,   -29,   135,
     136,   -29,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     7,     0,     0,     0,     3,
       6,    12,    13,    11,     0,    38,    39,    40,    33,    32,
       1,     2,     5,    10,    34,    36,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     9,
      16,    21,    35,     0,     4,     8,     0,     0,     0,    34,
      36,    37,    19,    17,    34,    36,    15,    26,     0,     0,
       0,     0,     0,    20,    18,    24,    22,    34,    36,    14,
      31,     0,     0,     0,     0,    25,    23,    29,    27,     0,
       0,    30,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -29,   132,    15,   -29,    80,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,    77,   -29,   140,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    28,    29,    30,    79,    80,    99,    98,    96,   112,
     111,   109,   120,   119,    31,    81,    32,    33,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    45,    34,    35,    36,    37,    40,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      89,    90,    38,    25,    39,    42,    83,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      94,    95,    86,    87,   100,    88,   102,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
     107,   108,   101,    85,   103,   104,   113,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      91,    41,   114,    92,    93,    97,     0,   115,   116,   121,
     122,    43,     0,     0,    84,     0,     0,   105,   106,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,   118,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24
};

static const yytype_int8 yycheck[] =
{
      28,    29,    29,    29,    29,    29,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      28,    29,    31,    27,    31,    30,    32,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      28,    29,    33,    33,    33,    32,    32,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      28,    29,    33,    43,    34,    34,    33,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      83,    29,    33,    86,    87,    88,    -1,    34,    34,    34,
      34,    31,    -1,    -1,    42,    -1,    -1,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    69,    70,
      71,    82,    84,    85,    29,    29,    29,    29,    31,    31,
       0,    69,    70,    85,    28,    29,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    72,
      73,    83,    86,    32,    69,    72,    33,    33,    32,    28,
      29,    83,    83,    83,    28,    29,    76,    83,    75,    74,
      33,    33,    32,    34,    34,    83,    83,    28,    29,    79,
      83,    78,    77,    33,    33,    34,    34,    83,    83,    81,
      80,    34,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    69,    69,    69,    69,    70,    71,    71,
      71,    71,    71,    71,    72,    72,    72,    74,    73,    75,
      73,    73,    77,    76,    78,    76,    76,    80,    79,    81,
      79,    79,    82,    82,    83,    83,    83,    84,    84,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     1,     1,     3,     2,
       2,     1,     1,     1,     5,     3,     1,     0,     5,     0,
       5,     1,     0,     5,     0,     5,     1,     0,     5,     0,
       5,     1,     2,     2,     1,     1,     1,     4,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* asm_line: label mnemonic params  */
#line 93 "parser.y"
                          {
        //printf("label mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno -1);

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1621 "y.tab.c"
    break;

  case 9: /* asm_line: mnemonic params  */
#line 103 "parser.y"
                        {
        //printf("mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno -1);

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1635 "y.tab.c"
    break;

  case 10: /* asm_line: label mnemonic  */
#line 113 "parser.y"
                       {
        //printf("label mnemonic\n");
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno - 1);

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1648 "y.tab.c"
    break;

  case 11: /* asm_line: mnemonic  */
#line 122 "parser.y"
                 {
        //printf("mnemonic\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1661 "y.tab.c"
    break;

  case 12: /* asm_line: label  */
#line 131 "parser.y"
          {
        //printf("label\n");
        //printf("label Line: %d\n", (yylineno-1));

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        parser_asm_line.line_nr = (yylineno - 1);

        //printf("Line: %d label: %s \n", parser_asm_line.label, yylineno);
        //printf("Line: %d\n", yylineno);

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1680 "y.tab.c"
    break;

  case 13: /* asm_line: assembler_instruction  */
#line 146 "parser.y"
                          {
        //printf("assembler_instruction\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1693 "y.tab.c"
    break;

  case 14: /* params: param_1 COMMA param_2 COMMA param_3  */
#line 155 "parser.y"
                                             {
        //printf("param_1 COMMA param_2 COMMA param_3\n");
    }
#line 1701 "y.tab.c"
    break;

  case 15: /* params: param_1 COMMA param_2  */
#line 158 "parser.y"
                            {
        //printf("param_1 COMMA param_2\n");
    }
#line 1709 "y.tab.c"
    break;

  case 16: /* params: param_1  */
#line 161 "parser.y"
              {
        //printf("param_1\n");
    }
#line 1717 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 166 "parser.y"
                                    {
        //printf("identifier OFFSET 1\n");
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-2].string_val), 0);
    }
#line 1726 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 171 "parser.y"
                                 {
        //printf("numeric OFFSET 1\n");
        insert_offset(&parser_asm_line, (yyvsp[-1].sym), 0);
    }
#line 1735 "y.tab.c"
    break;

  case 21: /* param_1: expr  */
#line 176 "parser.y"
         {
        //printf("expr 1\n");
        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1745 "y.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 183 "parser.y"
                                    {
        //printf("identifier OFFSET 2: %s\n", $1);
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-2].string_val), 1);
    }
#line 1754 "y.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 188 "parser.y"
                                 {
        //printf("numeric OFFSET 2\n");
        insert_offset(&parser_asm_line, (yyvsp[-1].sym), 1);
    }
#line 1763 "y.tab.c"
    break;

  case 26: /* param_2: expr  */
#line 193 "parser.y"
         {
        //printf("expr 2\n");
        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1773 "y.tab.c"
    break;

  case 27: /* $@5: %empty  */
#line 200 "parser.y"
                                    {
        //printf("identifier OFFSET 3\n");
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-2].string_val), 2);
    }
#line 1782 "y.tab.c"
    break;

  case 29: /* $@6: %empty  */
#line 205 "parser.y"
                                 {
        //printf("numeric OFFSET 3\n");
        insert_offset(&parser_asm_line, (yyvsp[-1].sym), 2);
    }
#line 1791 "y.tab.c"
    break;

  case 31: /* param_3: expr  */
#line 210 "parser.y"
         {
        //printf("expr 3\n");
        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1801 "y.tab.c"
    break;

  case 32: /* label: IDENTIFIER COLON  */
#line 217 "parser.y"
                     {
        strncpy((yyval.string_val), (yyvsp[-1].string_val), 100);
    }
#line 1809 "y.tab.c"
    break;

  case 33: /* label: NUMERIC COLON  */
#line 221 "parser.y"
                  {
        char buffer[100];
        memset(buffer, 0, 100);
        snprintf(buffer, 100, "%d", (yyvsp[-1].int_val));
        strncpy((yyval.string_val), buffer, 100);
    }
#line 1820 "y.tab.c"
    break;

  case 34: /* expr: NUMERIC  */
#line 230 "parser.y"
            {
        //printf("PARSER-NUMERIC: %08" PRIx32 "\n", $1);
        //insert_integer_immediate(&parser_asm_line, $1);

        if (current_node == NULL)
        {
            //current_node = new node_t;
            current_node = (node_t *)malloc(sizeof(node_t));

            //printf("Line: %d\n", yylineno);

            reset_node(current_node);

            //printf("PARSER-NUMERIC: creating node: %d\n", $1);
            //printf("PARSER-NUMERIC: creating node: %08" PRIx32 "\n", $1);
            //current_node->int_val = sign_extend_20_bit_to_uint32_t($1);
            current_node->int_val = (yyvsp[0].int_val);
            //printf("PARSER-NUMERIC: creating node: %d\n", current_node->int_val);

            //printf("PARSER-NUMERIC: creating node: %d\n", current_node->int_val);

            (yyval.expr_ptr) = current_node;
        } else {
            printf("PARSER-NUMERIC: not null!\n");
        }
    }
#line 1851 "y.tab.c"
    break;

  case 35: /* expr: register  */
#line 257 "parser.y"
             {
        //printf("expr - register\n");
        (yyval.expr_ptr) = current_node;
    }
#line 1860 "y.tab.c"
    break;

  case 36: /* expr: IDENTIFIER  */
#line 262 "parser.y"
               {
        //printf("expr - IDENTIFIER: %s \n", $1);

        if (current_node == NULL)
        {
            //current_node = new node_t;
            current_node = (node_t *)malloc(sizeof(node_t));

            //printf("Line: %d\n", yylineno);

            reset_node(current_node);
            memset(current_node->string_val, 0, 100);
            memcpy(current_node->string_val, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

            (yyval.expr_ptr) = current_node;
        } else {
            printf("expr - IDENTIFIER: not null!\n");
        }
    }
#line 1884 "y.tab.c"
    break;

  case 37: /* assembler_instruction: EQU IDENTIFIER COMMA expr  */
#line 283 "parser.y"
                              {

        parser_asm_line.asm_instruction = AI_EQU;

        //printf("AAA: %s\n", $2);

        //parser_asm_line.asm_instruction_symbol = $2,
        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[-2].string_val), strlen((yyvsp[-2].string_val)));

        //printf("BBB: %s\n", parser_asm_line.asm_instruction_symbol);

        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);
        //parser_asm_line.asm_instruction_expr = NULL;
        current_node = NULL;
    }
#line 1905 "y.tab.c"
    break;

  case 38: /* assembler_instruction: SECTION IDENTIFIER  */
#line 300 "parser.y"
                       {

        parser_asm_line.asm_instruction = AI_SECTION;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        current_node = NULL;
    }
#line 1919 "y.tab.c"
    break;

  case 39: /* assembler_instruction: GLOBL IDENTIFIER  */
#line 310 "parser.y"
                     {

        parser_asm_line.asm_instruction = AI_GLOBL;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        current_node = NULL;

    }
#line 1934 "y.tab.c"
    break;

  case 40: /* assembler_instruction: GLOBAL IDENTIFIER  */
#line 321 "parser.y"
                      {

        parser_asm_line.asm_instruction = AI_GLOBL;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        current_node = NULL;

    }
#line 1949 "y.tab.c"
    break;

  case 41: /* mnemonic: ADD  */
#line 332 "parser.y"
               { /*printf("Parser-ADD: %d\n", I_ADD);*/ /*parser_asm_line.instruction = I_ADD; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_ADD, IT_R); }
#line 1955 "y.tab.c"
    break;

  case 42: /* mnemonic: ADDI  */
#line 333 "parser.y"
           { /*printf("Parser-ADDI: %d\n", I_ADDI);*/ /*parser_asm_line.instruction = I_ADDI; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_ADDI, IT_R); }
#line 1961 "y.tab.c"
    break;

  case 43: /* mnemonic: AUIPC  */
#line 334 "parser.y"
            { /*printf("Parser-AUIPC: %d\n", I_AUIPC);*/ /*parser_asm_line.instruction = I_AUIPC; parser_asm_line.instruction_type = IT_U;*/ set_instruction(&parser_asm_line, I_AUIPC, IT_U); }
#line 1967 "y.tab.c"
    break;

  case 44: /* mnemonic: BEQ  */
#line 335 "parser.y"
          { /*printf("Parser-BEQ: %d\n", I_BEQ);*/ /*parser_asm_line.instruction = I_BEQ; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BEQ, IT_B); }
#line 1973 "y.tab.c"
    break;

  case 45: /* mnemonic: BEQZ  */
#line 336 "parser.y"
           { /*printf("Parser-BEQZ: %d\n", I_BEQZ);*/ /*parser_asm_line.instruction = I_BEQZ; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_BEQZ, IT_P); }
#line 1979 "y.tab.c"
    break;

  case 46: /* mnemonic: BNE  */
#line 337 "parser.y"
          { /*printf("Parser-BNE: %d\n", I_BNE);*/ /*parser_asm_line.instruction = I_BNE; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BNE, IT_B); }
#line 1985 "y.tab.c"
    break;

  case 47: /* mnemonic: BNEZ  */
#line 338 "parser.y"
           { /*printf("Parser-BNEZ: %d\n", I_BNEZ);*/ /*parser_asm_line.instruction = I_BNEZ; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_BNEZ, IT_P); }
#line 1991 "y.tab.c"
    break;

  case 48: /* mnemonic: CALL  */
#line 339 "parser.y"
           { /*printf("Parser-CALL: %d\n", I_CALL);*/ /*parser_asm_line.instruction = I_CALL; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_CALL, IT_P); }
#line 1997 "y.tab.c"
    break;

  case 49: /* mnemonic: J  */
#line 340 "parser.y"
        { /*printf("Parser-J: %d\n", I_J);*/ /*parser_asm_line.instruction = I_J; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_J, IT_P); }
#line 2003 "y.tab.c"
    break;

  case 50: /* mnemonic: JALR  */
#line 341 "parser.y"
           { /*printf("Parser-JALR: %d\n", I_JALR);*/ /*parser_asm_line.instruction = I_JALR; parser_asm_line.instruction_type = IT_J;*/ set_instruction(&parser_asm_line, I_JALR, IT_J); }
#line 2009 "y.tab.c"
    break;

  case 51: /* mnemonic: LB  */
#line 342 "parser.y"
         { /*printf("Parser-LB: %d\n", I_LB);*/ /*parser_asm_line.instruction = I_LB; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LB, IT_I); }
#line 2015 "y.tab.c"
    break;

  case 52: /* mnemonic: LI  */
#line 343 "parser.y"
         { /*printf("Parser-LI: %d\n", I_LI);*/ /*parser_asm_line.instruction = I_LI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LI, IT_P); }
#line 2021 "y.tab.c"
    break;

  case 53: /* mnemonic: LW  */
#line 344 "parser.y"
         { /*printf("Parser-LW: %d\n", I_LW);*/ /*parser_asm_line.instruction = I_LW; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LW, IT_I); }
#line 2027 "y.tab.c"
    break;

  case 54: /* mnemonic: LUI  */
#line 345 "parser.y"
          { /*printf("Parser-LUI: %d\n", I_LUI);*/ /*parser_asm_line.instruction = I_LUI; parser_asm_line.instruction_type = IT_U;*/ set_instruction(&parser_asm_line, I_LUI, IT_U); }
#line 2033 "y.tab.c"
    break;

  case 55: /* mnemonic: MUL  */
#line 346 "parser.y"
          { /*printf("Parser-LW: %d\n", I_MUL);*/ /*parser_asm_line.instruction = I_MUL; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_MUL, IT_R); }
#line 2039 "y.tab.c"
    break;

  case 56: /* mnemonic: MV  */
#line 347 "parser.y"
         { /*printf("Parser-LW: %d\n", I_MV);*/ /*parser_asm_line.instruction = I_MV; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_MV, IT_P); }
#line 2045 "y.tab.c"
    break;

  case 57: /* mnemonic: RET  */
#line 348 "parser.y"
          { /*printf("Parser-RET: %d\n", I_RET);*/ /*parser_asm_line.instruction = I_RET; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_RET, IT_P); }
#line 2051 "y.tab.c"
    break;

  case 58: /* mnemonic: SRLI  */
#line 349 "parser.y"
           { /*printf("Parser-SRLI: %d\n", I_SRLI);*/ /*parser_asm_line.instruction = I_SRLI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_SRLI, IT_I); }
#line 2057 "y.tab.c"
    break;

  case 59: /* mnemonic: SLLI  */
#line 350 "parser.y"
           { /*printf("Parser-SLLI: %d\n", I_SLLI);*/ /*parser_asm_line.instruction = I_SLLI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_SLLI, IT_I); }
#line 2063 "y.tab.c"
    break;

  case 60: /* mnemonic: SW  */
#line 351 "parser.y"
         { /*printf("Parser-SW: %d\n", I_SW);*/ /*parser_asm_line.instruction = I_SW; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SW, IT_S); }
#line 2069 "y.tab.c"
    break;

  case 61: /* register: REG_ZERO  */
#line 353 "parser.y"
                    { /*printf("REG_ZERO\n");*/ insert_register(&parser_asm_line, R_ZERO); }
#line 2075 "y.tab.c"
    break;

  case 62: /* register: REG_RA  */
#line 354 "parser.y"
             { /*printf("REG_RA\n");*/ insert_register(&parser_asm_line, R_RA); }
#line 2081 "y.tab.c"
    break;

  case 63: /* register: REG_SP  */
#line 355 "parser.y"
             { /*printf("REG_SP\n");*/ insert_register(&parser_asm_line, R_SP); }
#line 2087 "y.tab.c"
    break;

  case 64: /* register: REG_GP  */
#line 356 "parser.y"
             { /*printf("REG_GP\n");*/ insert_register(&parser_asm_line, R_GP); }
#line 2093 "y.tab.c"
    break;

  case 65: /* register: REG_TP  */
#line 357 "parser.y"
             { /*printf("REG_TP\n");*/ insert_register(&parser_asm_line, R_TP); }
#line 2099 "y.tab.c"
    break;

  case 66: /* register: REG_T0  */
#line 358 "parser.y"
             { /*printf("REG_T0\n");*/ insert_register(&parser_asm_line, R_T0); }
#line 2105 "y.tab.c"
    break;

  case 67: /* register: REG_T1  */
#line 359 "parser.y"
             { /*printf("REG_T1\n");*/ insert_register(&parser_asm_line, R_T1); }
#line 2111 "y.tab.c"
    break;

  case 68: /* register: REG_T2  */
#line 360 "parser.y"
             { /*printf("REG_T2\n");*/ insert_register(&parser_asm_line, R_T2); }
#line 2117 "y.tab.c"
    break;

  case 69: /* register: REG_T3  */
#line 361 "parser.y"
             { /*printf("REG_T3\n");*/ insert_register(&parser_asm_line, R_T3); }
#line 2123 "y.tab.c"
    break;

  case 70: /* register: REG_T4  */
#line 362 "parser.y"
             { /*printf("REG_T4\n");*/ insert_register(&parser_asm_line, R_T4); }
#line 2129 "y.tab.c"
    break;

  case 71: /* register: REG_T5  */
#line 363 "parser.y"
             { /*printf("REG_T5\n");*/ insert_register(&parser_asm_line, R_T5); }
#line 2135 "y.tab.c"
    break;

  case 72: /* register: REG_T6  */
#line 364 "parser.y"
             { /*printf("REG_T6\n");*/ insert_register(&parser_asm_line, R_T6); }
#line 2141 "y.tab.c"
    break;

  case 73: /* register: REG_FP  */
#line 365 "parser.y"
             { /*printf("REG_FP\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 2147 "y.tab.c"
    break;

  case 74: /* register: REG_A0  */
#line 366 "parser.y"
             { /*printf("REG_A0\n");*/ insert_register(&parser_asm_line, R_A0); }
#line 2153 "y.tab.c"
    break;

  case 75: /* register: REG_A1  */
#line 367 "parser.y"
             { /*printf("REG_A1\n");*/ insert_register(&parser_asm_line, R_A1); }
#line 2159 "y.tab.c"
    break;

  case 76: /* register: REG_A2  */
#line 368 "parser.y"
             { /*printf("REG_A2\n");*/ insert_register(&parser_asm_line, R_A2); }
#line 2165 "y.tab.c"
    break;

  case 77: /* register: REG_A3  */
#line 369 "parser.y"
             { /*printf("REG_A3\n");*/ insert_register(&parser_asm_line, R_A3); }
#line 2171 "y.tab.c"
    break;

  case 78: /* register: REG_A4  */
#line 370 "parser.y"
             { /*printf("REG_A4\n");*/ insert_register(&parser_asm_line, R_A4); }
#line 2177 "y.tab.c"
    break;

  case 79: /* register: REG_A5  */
#line 371 "parser.y"
             { /*printf("REG_A5\n");*/ insert_register(&parser_asm_line, R_A5); }
#line 2183 "y.tab.c"
    break;

  case 80: /* register: REG_A6  */
#line 372 "parser.y"
             { /*printf("REG_A6\n");*/ insert_register(&parser_asm_line, R_A6); }
#line 2189 "y.tab.c"
    break;

  case 81: /* register: REG_A7  */
#line 373 "parser.y"
             { /*printf("REG_A7\n");*/ insert_register(&parser_asm_line, R_A7); }
#line 2195 "y.tab.c"
    break;

  case 82: /* register: REG_S0  */
#line 374 "parser.y"
             { /*printf("REG_S0\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 2201 "y.tab.c"
    break;

  case 83: /* register: REG_S1  */
#line 375 "parser.y"
             { /*printf("REG_S1\n");*/ insert_register(&parser_asm_line, R_S1); }
#line 2207 "y.tab.c"
    break;

  case 84: /* register: REG_S2  */
#line 376 "parser.y"
             { /*printf("REG_S2\n");*/ insert_register(&parser_asm_line, R_S2); }
#line 2213 "y.tab.c"
    break;

  case 85: /* register: REG_S3  */
#line 377 "parser.y"
             { /*printf("REG_S3\n");*/ insert_register(&parser_asm_line, R_S3); }
#line 2219 "y.tab.c"
    break;

  case 86: /* register: REG_S4  */
#line 378 "parser.y"
             { /*printf("REG_S4\n");*/ insert_register(&parser_asm_line, R_S4); }
#line 2225 "y.tab.c"
    break;

  case 87: /* register: REG_S5  */
#line 379 "parser.y"
             { /*printf("REG_S5\n");*/ insert_register(&parser_asm_line, R_S5); }
#line 2231 "y.tab.c"
    break;

  case 88: /* register: REG_S6  */
#line 380 "parser.y"
             { /*printf("REG_S6\n");*/ insert_register(&parser_asm_line, R_S6); }
#line 2237 "y.tab.c"
    break;

  case 89: /* register: REG_S7  */
#line 381 "parser.y"
             { /*printf("REG_S7\n");*/ insert_register(&parser_asm_line, R_S7); }
#line 2243 "y.tab.c"
    break;

  case 90: /* register: REG_S8  */
#line 382 "parser.y"
             { /*printf("REG_S8\n");*/ insert_register(&parser_asm_line, R_S8); }
#line 2249 "y.tab.c"
    break;

  case 91: /* register: REG_S9  */
#line 383 "parser.y"
             { /*printf("REG_S9\n");*/ insert_register(&parser_asm_line, R_S9); }
#line 2255 "y.tab.c"
    break;

  case 92: /* register: REG_S10  */
#line 384 "parser.y"
              { /*printf("REG_S10\n");*/ insert_register(&parser_asm_line, R_S10); }
#line 2261 "y.tab.c"
    break;

  case 93: /* register: REG_S11  */
#line 385 "parser.y"
              { /*printf("REG_S11\n");*/ insert_register(&parser_asm_line, R_S11); }
#line 2267 "y.tab.c"
    break;


#line 2271 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 409 "parser.y"


//-- SECTION 4: FUNCTION DEFINITIONS ---------------------------------

// only define this symbol if there is not external application that uses the parser
#ifdef USE_INTERNAL_DRIVER

extern FILE* yyin;
extern int yy_flex_debug;

/*
void emit(asm_line_t* asm_line) {
    printf("emit\n");
}
*/

int main(int argc, char **argv)
{
    reset_asm_line(&parser_asm_line);

    //fp_emit = &emit;
    fp_emit = &encoder_callback;

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", argv[1]);
    }

    yy_flex_debug = 0;
    yydebug = 0;
    yyparse();

    return 0;
}

#endif
