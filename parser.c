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
#line 5 "../parser.y"


#include <stdio.h>

#include <asm_line.h>
#include <encoder.h>

#define YYDEBUG 1

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
int yyerror(const char *p) { printf("Error!\n"); return 1; }

#ifdef USE_INTERNAL_DRIVER
    asm_line_t parser_asm_line;
#else
    extern asm_line_t parser_asm_line;
#endif

// https://www.geeksforgeeks.org/function-pointer-in-c/
void (*fp_emit)(asm_line_t*);


#line 104 "y.tab.c"

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
    ADD = 258,                     /* ADD  */
    ADDI = 259,                    /* ADDI  */
    BEQ = 260,                     /* BEQ  */
    JALR = 261,                    /* JALR  */
    LB = 262,                      /* LB  */
    LI = 263,                      /* LI  */
    SRLI = 264,                    /* SRLI  */
    SLLI = 265,                    /* SLLI  */
    SW = 266,                      /* SW  */
    NEW_LINE = 267,                /* NEW_LINE  */
    NUMERIC = 268,                 /* NUMERIC  */
    IDENTIFIER = 269,              /* IDENTIFIER  */
    SECTION = 270,                 /* SECTION  */
    GLOBAL = 271,                  /* GLOBAL  */
    DOT = 272,                     /* DOT  */
    COLON = 273,                   /* COLON  */
    COMMA = 274,                   /* COMMA  */
    OPENING_BRACKET = 275,         /* OPENING_BRACKET  */
    CLOSING_BRACKET = 276,         /* CLOSING_BRACKET  */
    REG_ZERO = 277,                /* REG_ZERO  */
    REG_RA = 278,                  /* REG_RA  */
    REG_SP = 279,                  /* REG_SP  */
    REG_GP = 280,                  /* REG_GP  */
    REG_TP = 281,                  /* REG_TP  */
    REG_T0 = 282,                  /* REG_T0  */
    REG_T1 = 283,                  /* REG_T1  */
    REG_T2 = 284,                  /* REG_T2  */
    REG_T3 = 285,                  /* REG_T3  */
    REG_T4 = 286,                  /* REG_T4  */
    REG_T5 = 287,                  /* REG_T5  */
    REG_T6 = 288,                  /* REG_T6  */
    REG_FP = 289,                  /* REG_FP  */
    REG_A0 = 290,                  /* REG_A0  */
    REG_A1 = 291,                  /* REG_A1  */
    REG_A2 = 292,                  /* REG_A2  */
    REG_A3 = 293,                  /* REG_A3  */
    REG_A4 = 294,                  /* REG_A4  */
    REG_A5 = 295,                  /* REG_A5  */
    REG_A6 = 296,                  /* REG_A6  */
    REG_A7 = 297,                  /* REG_A7  */
    REG_S0 = 298,                  /* REG_S0  */
    REG_S1 = 299,                  /* REG_S1  */
    REG_S2 = 300,                  /* REG_S2  */
    REG_S3 = 301,                  /* REG_S3  */
    REG_S4 = 302,                  /* REG_S4  */
    REG_S5 = 303,                  /* REG_S5  */
    REG_S6 = 304,                  /* REG_S6  */
    REG_S7 = 305,                  /* REG_S7  */
    REG_S8 = 306,                  /* REG_S8  */
    REG_S9 = 307,                  /* REG_S9  */
    REG_S10 = 308,                 /* REG_S10  */
    REG_S11 = 309                  /* REG_S11  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ADD 258
#define ADDI 259
#define BEQ 260
#define JALR 261
#define LB 262
#define LI 263
#define SRLI 264
#define SLLI 265
#define SW 266
#define NEW_LINE 267
#define NUMERIC 268
#define IDENTIFIER 269
#define SECTION 270
#define GLOBAL 271
#define DOT 272
#define COLON 273
#define COMMA 274
#define OPENING_BRACKET 275
#define CLOSING_BRACKET 276
#define REG_ZERO 277
#define REG_RA 278
#define REG_SP 279
#define REG_GP 280
#define REG_TP 281
#define REG_T0 282
#define REG_T1 283
#define REG_T2 284
#define REG_T3 285
#define REG_T4 286
#define REG_T5 287
#define REG_T6 288
#define REG_FP 289
#define REG_A0 290
#define REG_A1 291
#define REG_A2 292
#define REG_A3 293
#define REG_A4 294
#define REG_A5 295
#define REG_A6 296
#define REG_A7 297
#define REG_S0 298
#define REG_S1 299
#define REG_S2 300
#define REG_S3 301
#define REG_S4 302
#define REG_S5 303
#define REG_S6 304
#define REG_S7 305
#define REG_S8 306
#define REG_S9 307
#define REG_S10 308
#define REG_S11 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "../parser.y"

  int int_val; 
  char sym;

#line 267 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_ADDI = 4,                       /* ADDI  */
  YYSYMBOL_BEQ = 5,                        /* BEQ  */
  YYSYMBOL_JALR = 6,                       /* JALR  */
  YYSYMBOL_LB = 7,                         /* LB  */
  YYSYMBOL_LI = 8,                         /* LI  */
  YYSYMBOL_SRLI = 9,                       /* SRLI  */
  YYSYMBOL_SLLI = 10,                      /* SLLI  */
  YYSYMBOL_SW = 11,                        /* SW  */
  YYSYMBOL_NEW_LINE = 12,                  /* NEW_LINE  */
  YYSYMBOL_NUMERIC = 13,                   /* NUMERIC  */
  YYSYMBOL_IDENTIFIER = 14,                /* IDENTIFIER  */
  YYSYMBOL_SECTION = 15,                   /* SECTION  */
  YYSYMBOL_GLOBAL = 16,                    /* GLOBAL  */
  YYSYMBOL_DOT = 17,                       /* DOT  */
  YYSYMBOL_COLON = 18,                     /* COLON  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_OPENING_BRACKET = 20,           /* OPENING_BRACKET  */
  YYSYMBOL_CLOSING_BRACKET = 21,           /* CLOSING_BRACKET  */
  YYSYMBOL_REG_ZERO = 22,                  /* REG_ZERO  */
  YYSYMBOL_REG_RA = 23,                    /* REG_RA  */
  YYSYMBOL_REG_SP = 24,                    /* REG_SP  */
  YYSYMBOL_REG_GP = 25,                    /* REG_GP  */
  YYSYMBOL_REG_TP = 26,                    /* REG_TP  */
  YYSYMBOL_REG_T0 = 27,                    /* REG_T0  */
  YYSYMBOL_REG_T1 = 28,                    /* REG_T1  */
  YYSYMBOL_REG_T2 = 29,                    /* REG_T2  */
  YYSYMBOL_REG_T3 = 30,                    /* REG_T3  */
  YYSYMBOL_REG_T4 = 31,                    /* REG_T4  */
  YYSYMBOL_REG_T5 = 32,                    /* REG_T5  */
  YYSYMBOL_REG_T6 = 33,                    /* REG_T6  */
  YYSYMBOL_REG_FP = 34,                    /* REG_FP  */
  YYSYMBOL_REG_A0 = 35,                    /* REG_A0  */
  YYSYMBOL_REG_A1 = 36,                    /* REG_A1  */
  YYSYMBOL_REG_A2 = 37,                    /* REG_A2  */
  YYSYMBOL_REG_A3 = 38,                    /* REG_A3  */
  YYSYMBOL_REG_A4 = 39,                    /* REG_A4  */
  YYSYMBOL_REG_A5 = 40,                    /* REG_A5  */
  YYSYMBOL_REG_A6 = 41,                    /* REG_A6  */
  YYSYMBOL_REG_A7 = 42,                    /* REG_A7  */
  YYSYMBOL_REG_S0 = 43,                    /* REG_S0  */
  YYSYMBOL_REG_S1 = 44,                    /* REG_S1  */
  YYSYMBOL_REG_S2 = 45,                    /* REG_S2  */
  YYSYMBOL_REG_S3 = 46,                    /* REG_S3  */
  YYSYMBOL_REG_S4 = 47,                    /* REG_S4  */
  YYSYMBOL_REG_S5 = 48,                    /* REG_S5  */
  YYSYMBOL_REG_S6 = 49,                    /* REG_S6  */
  YYSYMBOL_REG_S7 = 50,                    /* REG_S7  */
  YYSYMBOL_REG_S8 = 51,                    /* REG_S8  */
  YYSYMBOL_REG_S9 = 52,                    /* REG_S9  */
  YYSYMBOL_REG_S10 = 53,                   /* REG_S10  */
  YYSYMBOL_REG_S11 = 54,                   /* REG_S11  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_asm_file = 56,                  /* asm_file  */
  YYSYMBOL_line_end = 57,                  /* line_end  */
  YYSYMBOL_asm_line = 58,                  /* asm_line  */
  YYSYMBOL_params = 59,                    /* params  */
  YYSYMBOL_param_1 = 60,                   /* param_1  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_param_2 = 62,                   /* param_2  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_param_3 = 64,                   /* param_3  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_label = 66,                     /* label  */
  YYSYMBOL_mnemonic = 67,                  /* mnemonic  */
  YYSYMBOL_register = 68,                  /* register  */
  YYSYMBOL_expr = 69,                      /* expr  */
  YYSYMBOL_assembler_instruction = 70,     /* assembler_instruction  */
  YYSYMBOL_section_name = 71               /* section_name  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  91

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    63,    63,    65,    67,    69,    71,    73,
      75,    77,    79,    80,    81,    83,    83,    84,    86,    86,
      87,    89,    89,    90,    92,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   139,   141,   144,
     146,   148
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
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "ADDI", "BEQ",
  "JALR", "LB", "LI", "SRLI", "SLLI", "SW", "NEW_LINE", "NUMERIC",
  "IDENTIFIER", "SECTION", "GLOBAL", "DOT", "COLON", "COMMA",
  "OPENING_BRACKET", "CLOSING_BRACKET", "REG_ZERO", "REG_RA", "REG_SP",
  "REG_GP", "REG_TP", "REG_T0", "REG_T1", "REG_T2", "REG_T3", "REG_T4",
  "REG_T5", "REG_T6", "REG_FP", "REG_A0", "REG_A1", "REG_A2", "REG_A3",
  "REG_A4", "REG_A5", "REG_A6", "REG_A7", "REG_S0", "REG_S1", "REG_S2",
  "REG_S3", "REG_S4", "REG_S5", "REG_S6", "REG_S7", "REG_S8", "REG_S9",
  "REG_S10", "REG_S11", "$accept", "asm_file", "line_end", "asm_line",
  "params", "param_1", "$@1", "param_2", "$@2", "param_3", "$@3", "label",
  "mnemonic", "register", "expr", "assembler_instruction", "section_name", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-16)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     183,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -15,   -14,     4,   183,    -7,   198,   -13,   -16,   -16,
     -11,    -6,   -16,   -16,   183,   -13,    23,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -12,   -16,   -16,    30,   -16,   -16,   -16,   -16,    29,
      71,   -16,   -16,   -16,    25,    27,   -16,    26,    29,   113,
     -16,   -16,    28,   -16,   -16,    64,    29,   -16,   -16,    65,
     -16
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       5,     0,     0,     0,     0,     0,    10,     9,    11,    24,
       0,     0,     1,     2,     4,     8,    67,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       7,    14,    68,    17,     0,    69,    70,     3,     6,     0,
       0,    71,    67,    15,    67,    13,    20,     0,     0,     0,
      16,    18,    67,    12,    23,     0,     0,    19,    21,     0,
      22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -16,   156,    34,   -16,    62,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,    72,   -16,    99,   -16,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    13,    14,    15,    60,    61,    77,    75,    85,    83,
      89,    16,    17,    62,    63,    18,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,    20,    21,    19,    22,    10,    64,    70,    66,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    72,    69,    71,    78,    79,    80,    86,    24,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    74,    87,    90,    68,    25,     0,
       0,     0,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    73,    76,
      23,     0,     0,     0,     0,     0,     0,    81,    84,     0,
      67,     0,     0,     0,     0,    88,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
      12,     1,     2,     3,     4,     5,     6,     7,     8,     9
};

static const yytype_int8 yycheck[] =
{
      13,    15,    16,    18,     0,    12,    17,    19,    14,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    13,    20,    14,    20,    19,    21,    20,    15,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    13,    21,    21,    25,    16,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    69,    70,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,
      24,    -1,    -1,    -1,    -1,    86,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      17,     3,     4,     5,     6,     7,     8,     9,    10,    11
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    14,    17,    56,    57,    58,    66,    67,    70,    18,
      15,    16,     0,    56,    57,    67,    13,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      59,    60,    68,    69,    17,    71,    14,    56,    59,    20,
      19,    14,    13,    69,    13,    62,    69,    61,    20,    19,
      21,    69,    13,    64,    69,    63,    20,    21,    69,    65,
      21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    56,    57,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    61,    60,    60,    63,    62,
      62,    65,    64,    64,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     3,     2,     2,     1,
       1,     1,     5,     3,     1,     0,     5,     1,     0,     5,
       1,     0,     5,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     2
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* asm_line: label mnemonic params  */
#line 67 "../parser.y"
                                 { /*print_asm_line(&parser_asm_line);*/ if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); } }
#line 1407 "y.tab.c"
    break;

  case 7: /* asm_line: mnemonic params  */
#line 69 "../parser.y"
                        { /*print_asm_line(&parser_asm_line);*/ if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); } }
#line 1413 "y.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 83 "../parser.y"
                                       { /*printf("OFFSET 1\n");*/ insert_offset(&parser_asm_line, (yyvsp[-1].sym), 0); }
#line 1419 "y.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 86 "../parser.y"
                                       { /*printf("OFFSET 2\n");*/ insert_offset(&parser_asm_line, (yyvsp[-1].sym), 1); }
#line 1425 "y.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 89 "../parser.y"
                                       { /*printf("OFFSET 3\n");*/ insert_offset(&parser_asm_line, (yyvsp[-1].sym), 2); }
#line 1431 "y.tab.c"
    break;

  case 25: /* mnemonic: ADD  */
#line 94 "../parser.y"
               { /*printf("Parser-ADD: %d\n", I_ADD);*/ parser_asm_line.instruction = I_ADD; parser_asm_line.instruction_type = IT_R; }
#line 1437 "y.tab.c"
    break;

  case 26: /* mnemonic: ADDI  */
#line 95 "../parser.y"
           { /*printf("Parser-ADDI: %d\n", I_ADDI);*/ parser_asm_line.instruction = I_ADDI; parser_asm_line.instruction_type = IT_R; }
#line 1443 "y.tab.c"
    break;

  case 27: /* mnemonic: BEQ  */
#line 96 "../parser.y"
          { /*printf("Parser-BEQ: %d\n", I_BEQ);*/ parser_asm_line.instruction = I_BEQ; parser_asm_line.instruction_type = IT_B; }
#line 1449 "y.tab.c"
    break;

  case 28: /* mnemonic: JALR  */
#line 97 "../parser.y"
           { /*printf("Parser-JALR: %d\n", I_JALR);*/ parser_asm_line.instruction = I_JALR; parser_asm_line.instruction_type = IT_J; }
#line 1455 "y.tab.c"
    break;

  case 29: /* mnemonic: LB  */
#line 98 "../parser.y"
         { /*printf("Parser-LB: %d\n", I_LB);*/ parser_asm_line.instruction = I_LB; parser_asm_line.instruction_type = IT_I; }
#line 1461 "y.tab.c"
    break;

  case 30: /* mnemonic: LI  */
#line 99 "../parser.y"
         { /*printf("Parser-LI: %d\n", I_LI);*/ parser_asm_line.instruction = I_LI; parser_asm_line.instruction_type = IT_I; }
#line 1467 "y.tab.c"
    break;

  case 31: /* mnemonic: SRLI  */
#line 100 "../parser.y"
           { /*printf("Parser-SRLI: %d\n", I_SRLI);*/ parser_asm_line.instruction = I_SRLI; parser_asm_line.instruction_type = IT_I; }
#line 1473 "y.tab.c"
    break;

  case 32: /* mnemonic: SLLI  */
#line 101 "../parser.y"
           { /*printf("Parser-SLLI: %d\n", I_SLLI);*/ parser_asm_line.instruction = I_SLLI; parser_asm_line.instruction_type = IT_I; }
#line 1479 "y.tab.c"
    break;

  case 33: /* mnemonic: SW  */
#line 102 "../parser.y"
         { /*printf("Parser-SW: %d\n", I_SW);*/ parser_asm_line.instruction = I_SW; parser_asm_line.instruction_type = IT_S; }
#line 1485 "y.tab.c"
    break;

  case 34: /* register: REG_ZERO  */
#line 104 "../parser.y"
                    { /*printf("REG_ZERO\n");*/ insert_register(&parser_asm_line, R_ZERO); }
#line 1491 "y.tab.c"
    break;

  case 35: /* register: REG_RA  */
#line 105 "../parser.y"
             { /*printf("REG_RA\n");*/ insert_register(&parser_asm_line, R_RA); }
#line 1497 "y.tab.c"
    break;

  case 36: /* register: REG_SP  */
#line 106 "../parser.y"
             { /*printf("REG_SP\n");*/ insert_register(&parser_asm_line, R_SP); }
#line 1503 "y.tab.c"
    break;

  case 37: /* register: REG_GP  */
#line 107 "../parser.y"
             { /*printf("REG_GP\n");*/ insert_register(&parser_asm_line, R_GP); }
#line 1509 "y.tab.c"
    break;

  case 38: /* register: REG_TP  */
#line 108 "../parser.y"
             { /*printf("REG_TP\n");*/ insert_register(&parser_asm_line, R_TP); }
#line 1515 "y.tab.c"
    break;

  case 39: /* register: REG_T0  */
#line 109 "../parser.y"
             { /*printf("REG_T0\n");*/ insert_register(&parser_asm_line, R_T0); }
#line 1521 "y.tab.c"
    break;

  case 40: /* register: REG_T1  */
#line 110 "../parser.y"
             { /*printf("REG_T1\n");*/ insert_register(&parser_asm_line, R_T1); }
#line 1527 "y.tab.c"
    break;

  case 41: /* register: REG_T2  */
#line 111 "../parser.y"
             { /*printf("REG_T2\n");*/ insert_register(&parser_asm_line, R_T2); }
#line 1533 "y.tab.c"
    break;

  case 42: /* register: REG_T3  */
#line 112 "../parser.y"
             { /*printf("REG_T3\n");*/ insert_register(&parser_asm_line, R_T3); }
#line 1539 "y.tab.c"
    break;

  case 43: /* register: REG_T4  */
#line 113 "../parser.y"
             { /*printf("REG_T4\n");*/ insert_register(&parser_asm_line, R_T4); }
#line 1545 "y.tab.c"
    break;

  case 44: /* register: REG_T5  */
#line 114 "../parser.y"
             { /*printf("REG_T5\n");*/ insert_register(&parser_asm_line, R_T5); }
#line 1551 "y.tab.c"
    break;

  case 45: /* register: REG_T6  */
#line 115 "../parser.y"
             { /*printf("REG_T6\n");*/ insert_register(&parser_asm_line, R_T6); }
#line 1557 "y.tab.c"
    break;

  case 46: /* register: REG_FP  */
#line 116 "../parser.y"
             { /*printf("REG_FP\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 1563 "y.tab.c"
    break;

  case 47: /* register: REG_A0  */
#line 117 "../parser.y"
             { /*printf("REG_A0\n");*/ insert_register(&parser_asm_line, R_A0); }
#line 1569 "y.tab.c"
    break;

  case 48: /* register: REG_A1  */
#line 118 "../parser.y"
             { /*printf("REG_A1\n");*/ insert_register(&parser_asm_line, R_A1); }
#line 1575 "y.tab.c"
    break;

  case 49: /* register: REG_A2  */
#line 119 "../parser.y"
             { /*printf("REG_A2\n");*/ insert_register(&parser_asm_line, R_A2); }
#line 1581 "y.tab.c"
    break;

  case 50: /* register: REG_A3  */
#line 120 "../parser.y"
             { /*printf("REG_A3\n");*/ insert_register(&parser_asm_line, R_A3); }
#line 1587 "y.tab.c"
    break;

  case 51: /* register: REG_A4  */
#line 121 "../parser.y"
             { /*printf("REG_A4\n");*/ insert_register(&parser_asm_line, R_A4); }
#line 1593 "y.tab.c"
    break;

  case 52: /* register: REG_A5  */
#line 122 "../parser.y"
             { /*printf("REG_A5\n");*/ insert_register(&parser_asm_line, R_A5); }
#line 1599 "y.tab.c"
    break;

  case 53: /* register: REG_A6  */
#line 123 "../parser.y"
             { /*printf("REG_A6\n");*/ insert_register(&parser_asm_line, R_A6); }
#line 1605 "y.tab.c"
    break;

  case 54: /* register: REG_A7  */
#line 124 "../parser.y"
             { /*printf("REG_A7\n");*/ insert_register(&parser_asm_line, R_A7); }
#line 1611 "y.tab.c"
    break;

  case 55: /* register: REG_S0  */
#line 125 "../parser.y"
             { /*printf("REG_S0\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 1617 "y.tab.c"
    break;

  case 56: /* register: REG_S1  */
#line 126 "../parser.y"
             { /*printf("REG_S1\n");*/ insert_register(&parser_asm_line, R_S1); }
#line 1623 "y.tab.c"
    break;

  case 57: /* register: REG_S2  */
#line 127 "../parser.y"
             { /*printf("REG_S2\n");*/ insert_register(&parser_asm_line, R_S2); }
#line 1629 "y.tab.c"
    break;

  case 58: /* register: REG_S3  */
#line 128 "../parser.y"
             { /*printf("REG_S3\n");*/ insert_register(&parser_asm_line, R_S3); }
#line 1635 "y.tab.c"
    break;

  case 59: /* register: REG_S4  */
#line 129 "../parser.y"
             { /*printf("REG_S4\n");*/ insert_register(&parser_asm_line, R_S4); }
#line 1641 "y.tab.c"
    break;

  case 60: /* register: REG_S5  */
#line 130 "../parser.y"
             { /*printf("REG_S5\n");*/ insert_register(&parser_asm_line, R_S5); }
#line 1647 "y.tab.c"
    break;

  case 61: /* register: REG_S6  */
#line 131 "../parser.y"
             { /*printf("REG_S6\n");*/ insert_register(&parser_asm_line, R_S6); }
#line 1653 "y.tab.c"
    break;

  case 62: /* register: REG_S7  */
#line 132 "../parser.y"
             { /*printf("REG_S7\n");*/ insert_register(&parser_asm_line, R_S7); }
#line 1659 "y.tab.c"
    break;

  case 63: /* register: REG_S8  */
#line 133 "../parser.y"
             { /*printf("REG_S8\n");*/ insert_register(&parser_asm_line, R_S8); }
#line 1665 "y.tab.c"
    break;

  case 64: /* register: REG_S9  */
#line 134 "../parser.y"
             { /*printf("REG_S9\n");*/ insert_register(&parser_asm_line, R_S9); }
#line 1671 "y.tab.c"
    break;

  case 65: /* register: REG_S10  */
#line 135 "../parser.y"
              { /*printf("REG_S10\n");*/ insert_register(&parser_asm_line, R_S10); }
#line 1677 "y.tab.c"
    break;

  case 66: /* register: REG_S11  */
#line 136 "../parser.y"
              { /*printf("REG_S11\n");*/ insert_register(&parser_asm_line, R_S11); }
#line 1683 "y.tab.c"
    break;

  case 67: /* expr: NUMERIC  */
#line 139 "../parser.y"
               { /*printf("PARSER-NUMERIC: %d\n", $1);*/ insert_integer_immediate(&parser_asm_line, (yyvsp[0].int_val)); }
#line 1689 "y.tab.c"
    break;


#line 1693 "y.tab.c"

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 172 "../parser.y"


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
