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


#line 112 "parser.c"

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

#include "parser.h"
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
  YYSYMBOL_ADD = 6,                        /* ADD  */
  YYSYMBOL_ADDI = 7,                       /* ADDI  */
  YYSYMBOL_BEQ = 8,                        /* BEQ  */
  YYSYMBOL_BNE = 9,                        /* BNE  */
  YYSYMBOL_BNEZ = 10,                      /* BNEZ  */
  YYSYMBOL_CALL = 11,                      /* CALL  */
  YYSYMBOL_J = 12,                         /* J  */
  YYSYMBOL_JALR = 13,                      /* JALR  */
  YYSYMBOL_LB = 14,                        /* LB  */
  YYSYMBOL_LI = 15,                        /* LI  */
  YYSYMBOL_LW = 16,                        /* LW  */
  YYSYMBOL_LUI = 17,                       /* LUI  */
  YYSYMBOL_MUL = 18,                       /* MUL  */
  YYSYMBOL_MV = 19,                        /* MV  */
  YYSYMBOL_SRLI = 20,                      /* SRLI  */
  YYSYMBOL_SLLI = 21,                      /* SLLI  */
  YYSYMBOL_SW = 22,                        /* SW  */
  YYSYMBOL_NEW_LINE = 23,                  /* NEW_LINE  */
  YYSYMBOL_NUMERIC = 24,                   /* NUMERIC  */
  YYSYMBOL_IDENTIFIER = 25,                /* IDENTIFIER  */
  YYSYMBOL_DOT = 26,                       /* DOT  */
  YYSYMBOL_COLON = 27,                     /* COLON  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_OPENING_BRACKET = 29,           /* OPENING_BRACKET  */
  YYSYMBOL_CLOSING_BRACKET = 30,           /* CLOSING_BRACKET  */
  YYSYMBOL_REG_ZERO = 31,                  /* REG_ZERO  */
  YYSYMBOL_REG_RA = 32,                    /* REG_RA  */
  YYSYMBOL_REG_SP = 33,                    /* REG_SP  */
  YYSYMBOL_REG_GP = 34,                    /* REG_GP  */
  YYSYMBOL_REG_TP = 35,                    /* REG_TP  */
  YYSYMBOL_REG_T0 = 36,                    /* REG_T0  */
  YYSYMBOL_REG_T1 = 37,                    /* REG_T1  */
  YYSYMBOL_REG_T2 = 38,                    /* REG_T2  */
  YYSYMBOL_REG_T3 = 39,                    /* REG_T3  */
  YYSYMBOL_REG_T4 = 40,                    /* REG_T4  */
  YYSYMBOL_REG_T5 = 41,                    /* REG_T5  */
  YYSYMBOL_REG_T6 = 42,                    /* REG_T6  */
  YYSYMBOL_REG_FP = 43,                    /* REG_FP  */
  YYSYMBOL_REG_A0 = 44,                    /* REG_A0  */
  YYSYMBOL_REG_A1 = 45,                    /* REG_A1  */
  YYSYMBOL_REG_A2 = 46,                    /* REG_A2  */
  YYSYMBOL_REG_A3 = 47,                    /* REG_A3  */
  YYSYMBOL_REG_A4 = 48,                    /* REG_A4  */
  YYSYMBOL_REG_A5 = 49,                    /* REG_A5  */
  YYSYMBOL_REG_A6 = 50,                    /* REG_A6  */
  YYSYMBOL_REG_A7 = 51,                    /* REG_A7  */
  YYSYMBOL_REG_S0 = 52,                    /* REG_S0  */
  YYSYMBOL_REG_S1 = 53,                    /* REG_S1  */
  YYSYMBOL_REG_S2 = 54,                    /* REG_S2  */
  YYSYMBOL_REG_S3 = 55,                    /* REG_S3  */
  YYSYMBOL_REG_S4 = 56,                    /* REG_S4  */
  YYSYMBOL_REG_S5 = 57,                    /* REG_S5  */
  YYSYMBOL_REG_S6 = 58,                    /* REG_S6  */
  YYSYMBOL_REG_S7 = 59,                    /* REG_S7  */
  YYSYMBOL_REG_S8 = 60,                    /* REG_S8  */
  YYSYMBOL_REG_S9 = 61,                    /* REG_S9  */
  YYSYMBOL_REG_S10 = 62,                   /* REG_S10  */
  YYSYMBOL_REG_S11 = 63,                   /* REG_S11  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_asm_file = 65,                  /* asm_file  */
  YYSYMBOL_line_end = 66,                  /* line_end  */
  YYSYMBOL_asm_line = 67,                  /* asm_line  */
  YYSYMBOL_params = 68,                    /* params  */
  YYSYMBOL_param_1 = 69,                   /* param_1  */
  YYSYMBOL_70_1 = 70,                      /* $@1  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_param_2 = 72,                   /* param_2  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_74_4 = 74,                      /* $@4  */
  YYSYMBOL_param_3 = 75,                   /* param_3  */
  YYSYMBOL_76_5 = 76,                      /* $@5  */
  YYSYMBOL_77_6 = 77,                      /* $@6  */
  YYSYMBOL_label = 78,                     /* label  */
  YYSYMBOL_expr = 79,                      /* expr  */
  YYSYMBOL_assembler_instruction = 80,     /* assembler_instruction  */
  YYSYMBOL_mnemonic = 81,                  /* mnemonic  */
  YYSYMBOL_register = 82                   /* register  */
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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   231

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    81,    83,    85,    87,    89,    91,    97,
     103,   107,   111,   122,   127,   130,   133,   138,   138,   143,
     143,   148,   155,   155,   160,   160,   165,   172,   172,   177,
     177,   182,   188,   194,   218,   223,   242,   259,   269,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330
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
  "GLOBL", "ADD", "ADDI", "BEQ", "BNE", "BNEZ", "CALL", "J", "JALR", "LB",
  "LI", "LW", "LUI", "MUL", "MV", "SRLI", "SLLI", "SW", "NEW_LINE",
  "NUMERIC", "IDENTIFIER", "DOT", "COLON", "COMMA", "OPENING_BRACKET",
  "CLOSING_BRACKET", "REG_ZERO", "REG_RA", "REG_SP", "REG_GP", "REG_TP",
  "REG_T0", "REG_T1", "REG_T2", "REG_T3", "REG_T4", "REG_T5", "REG_T6",
  "REG_FP", "REG_A0", "REG_A1", "REG_A2", "REG_A3", "REG_A4", "REG_A5",
  "REG_A6", "REG_A7", "REG_S0", "REG_S1", "REG_S2", "REG_S3", "REG_S4",
  "REG_S5", "REG_S6", "REG_S7", "REG_S8", "REG_S9", "REG_S10", "REG_S11",
  "$accept", "asm_file", "line_end", "asm_line", "params", "param_1",
  "$@1", "$@2", "param_2", "$@3", "$@4", "param_3", "$@5", "$@6", "label",
  "expr", "assembler_instruction", "mnemonic", "register", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     189,   -23,   -22,   -21,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,    15,     5,   189,   -17,   209,   -25,   -24,    17,
     -25,   -25,   -25,   -25,   -25,   189,   -24,    14,    53,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,    18,   -25,   -25,    16,   -25,   -25,    16,
      16,    56,   -25,   -25,   -25,   -25,   -25,    54,    55,    57,
     -25,    92,    93,    16,    16,    96,   -25,   -25,   -25,   -25,
      95,    97,   -25,   -25,   132,   136,    16,    16,   -25,   -25,
     -25,   -25,   138,   139,   -25,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     7,     0,     0,     6,     5,    12,    13,    11,     0,
      37,    38,    32,     1,     2,     4,    10,    33,    35,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     9,    16,    21,    34,     0,     3,     8,     0,
       0,     0,    33,    35,    36,    19,    17,    33,    35,    15,
      26,     0,     0,     0,     0,     0,    20,    18,    24,    22,
      33,    35,    14,    31,     0,     0,     0,     0,    25,    23,
      29,    27,     0,     0,    30,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -25,   137,    19,   -25,    50,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,    84,   -25,    99,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    23,    24,    25,    72,    73,    92,    91,    89,   105,
     104,   102,   113,   112,    26,    74,    27,    28,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    38,    29,    30,    31,    33,    21,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      82,    83,    32,    79,    35,    76,    81,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      87,    88,    80,    93,    94,    95,    78,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
     100,   101,    96,    97,   106,    36,   107,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      84,    34,   108,    85,    86,    90,   109,     0,   114,   115,
       0,     0,    77,     0,     0,     0,     0,    98,    99,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20
};

static const yytype_int8 yycheck[] =
{
      24,    25,    25,    25,    25,     0,    23,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      24,    25,    27,    29,    25,    28,    28,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      24,    25,    29,    29,    29,    28,    36,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      24,    25,    30,    30,    29,    26,    29,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      76,    24,    30,    79,    80,    81,    30,    -1,    30,    30,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    93,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    25,    65,    66,    67,    78,    80,    81,    25,
      25,    25,    27,     0,    65,    66,    81,    24,    25,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    68,    69,    79,    82,    28,    65,    68,    29,
      29,    28,    24,    25,    79,    79,    79,    24,    25,    72,
      79,    71,    70,    29,    29,    28,    30,    30,    79,    79,
      24,    25,    75,    79,    74,    73,    29,    29,    30,    30,
      79,    79,    77,    76,    30,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    65,    65,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    70,    69,    71,
      69,    69,    73,    72,    74,    72,    72,    76,    75,    77,
      75,    75,    78,    79,    79,    79,    80,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     1,     1,     3,     2,
       2,     1,     1,     1,     5,     3,     1,     0,     5,     0,
       5,     1,     0,     5,     0,     5,     1,     0,     5,     0,
       5,     1,     2,     1,     1,     1,     4,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 91 "parser.y"
                                 {
        //printf("label mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1408 "parser.c"
    break;

  case 9: /* asm_line: mnemonic params  */
#line 97 "parser.y"
                        {
        //printf("mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1418 "parser.c"
    break;

  case 10: /* asm_line: label mnemonic  */
#line 103 "parser.y"
                       {
        //printf("label mnemonic\n");
    }
#line 1426 "parser.c"
    break;

  case 11: /* asm_line: mnemonic  */
#line 107 "parser.y"
                 {
        //printf("mnemonic\n");
    }
#line 1434 "parser.c"
    break;

  case 12: /* asm_line: label  */
#line 111 "parser.y"
          {
        //printf("label\n");

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        //printf("label %s\n", parser_asm_line.label);

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1449 "parser.c"
    break;

  case 13: /* asm_line: assembler_instruction  */
#line 122 "parser.y"
                          {
        //printf("assembler_instruction\n");
        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1458 "parser.c"
    break;

  case 14: /* params: param_1 COMMA param_2 COMMA param_3  */
#line 127 "parser.y"
                                             {
        //printf("param_1 COMMA param_2 COMMA param_3\n");
    }
#line 1466 "parser.c"
    break;

  case 15: /* params: param_1 COMMA param_2  */
#line 130 "parser.y"
                            {
        //printf("param_1 COMMA param_2\n");
    }
#line 1474 "parser.c"
    break;

  case 16: /* params: param_1  */
#line 133 "parser.y"
              {
        //printf("param_1\n");
    }
#line 1482 "parser.c"
    break;

  case 17: /* $@1: %empty  */
#line 138 "parser.y"
                                    {
        //printf("identifier OFFSET 1\n");
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-2].string_val), 0);
    }
#line 1491 "parser.c"
    break;

  case 19: /* $@2: %empty  */
#line 143 "parser.y"
                                 {
        //printf("numeric OFFSET 1\n");
        insert_offset(&parser_asm_line, (yyvsp[-1].sym), 0);
        }
#line 1500 "parser.c"
    break;

  case 21: /* param_1: expr  */
#line 148 "parser.y"
         {
        //printf("expr 1\n");
        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1510 "parser.c"
    break;

  case 22: /* $@3: %empty  */
#line 155 "parser.y"
                                    {
        //printf("identifier OFFSET 2: %s\n", $1);
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-2].string_val), 1);
    }
#line 1519 "parser.c"
    break;

  case 24: /* $@4: %empty  */
#line 160 "parser.y"
                                 {
        //printf("numeric OFFSET 2\n");
        insert_offset(&parser_asm_line, (yyvsp[-1].sym), 1);
    }
#line 1528 "parser.c"
    break;

  case 26: /* param_2: expr  */
#line 165 "parser.y"
         {
        //printf("expr 2\n");
        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1538 "parser.c"
    break;

  case 27: /* $@5: %empty  */
#line 172 "parser.y"
                                    {
        //printf("identifier OFFSET 3\n");
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-2].string_val), 2);
    }
#line 1547 "parser.c"
    break;

  case 29: /* $@6: %empty  */
#line 177 "parser.y"
                                 {
        //printf("numeric OFFSET 3\n");
        insert_offset(&parser_asm_line, (yyvsp[-1].sym), 2);
    }
#line 1556 "parser.c"
    break;

  case 31: /* param_3: expr  */
#line 182 "parser.y"
         {
        //printf("expr 3\n");
        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1566 "parser.c"
    break;

  case 32: /* label: IDENTIFIER COLON  */
#line 188 "parser.y"
                         {
    strncpy((yyval.string_val), (yyvsp[-1].string_val), 100);
}
#line 1574 "parser.c"
    break;

  case 33: /* expr: NUMERIC  */
#line 194 "parser.y"
            {
        //printf("PARSER-NUMERIC: %08" PRIx32 "\n", $1);
        //insert_integer_immediate(&parser_asm_line, $1);

        if (current_node == NULL)
        {
            //current_node = new node_t;
            current_node = (node_t *)malloc(sizeof(node_t));
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
#line 1602 "parser.c"
    break;

  case 34: /* expr: register  */
#line 218 "parser.y"
             {
        //printf("expr - register\n");
        (yyval.expr_ptr) = current_node;
    }
#line 1611 "parser.c"
    break;

  case 35: /* expr: IDENTIFIER  */
#line 223 "parser.y"
               {
        //printf("expr - IDENTIFIER: %s \n", $1);

        if (current_node == NULL)
        {
            //current_node = new node_t;
            current_node = (node_t *)malloc(sizeof(node_t));

            reset_node(current_node);
            memset(current_node->string_val, 0, 100);
            memcpy(current_node->string_val, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

            (yyval.expr_ptr) = current_node;
        } else {
            printf("expr - IDENTIFIER: not null!\n");
        }
    }
#line 1633 "parser.c"
    break;

  case 36: /* assembler_instruction: EQU IDENTIFIER COMMA expr  */
#line 242 "parser.y"
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
#line 1654 "parser.c"
    break;

  case 37: /* assembler_instruction: SECTION IDENTIFIER  */
#line 259 "parser.y"
                       {

        parser_asm_line.asm_instruction = AI_SECTION;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        current_node = NULL;
    }
#line 1668 "parser.c"
    break;

  case 38: /* assembler_instruction: GLOBL IDENTIFIER  */
#line 269 "parser.y"
                     {

        parser_asm_line.asm_instruction = AI_GLOBL;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        current_node = NULL;

    }
#line 1683 "parser.c"
    break;

  case 39: /* mnemonic: ADD  */
#line 280 "parser.y"
               { /*printf("Parser-ADD: %d\n", I_ADD);*/ parser_asm_line.instruction = I_ADD; parser_asm_line.instruction_type = IT_R; }
#line 1689 "parser.c"
    break;

  case 40: /* mnemonic: ADDI  */
#line 281 "parser.y"
           { /*printf("Parser-ADDI: %d\n", I_ADDI);*/ parser_asm_line.instruction = I_ADDI; parser_asm_line.instruction_type = IT_R; }
#line 1695 "parser.c"
    break;

  case 41: /* mnemonic: BEQ  */
#line 282 "parser.y"
          { /*printf("Parser-BEQ: %d\n", I_BEQ);*/ parser_asm_line.instruction = I_BEQ; parser_asm_line.instruction_type = IT_B; }
#line 1701 "parser.c"
    break;

  case 42: /* mnemonic: BNE  */
#line 283 "parser.y"
          { /*printf("Parser-BNE: %d\n", I_BNE);*/ parser_asm_line.instruction = I_BNE; parser_asm_line.instruction_type = IT_B; }
#line 1707 "parser.c"
    break;

  case 43: /* mnemonic: BNEZ  */
#line 284 "parser.y"
           { /*printf("Parser-BNEZ: %d\n", I_BNEZ);*/ parser_asm_line.instruction = I_BNEZ; parser_asm_line.instruction_type = IT_P; }
#line 1713 "parser.c"
    break;

  case 44: /* mnemonic: CALL  */
#line 285 "parser.y"
           { /*printf("Parser-CALL: %d\n", I_CALL);*/ parser_asm_line.instruction = I_CALL; parser_asm_line.instruction_type = IT_P; }
#line 1719 "parser.c"
    break;

  case 45: /* mnemonic: J  */
#line 286 "parser.y"
        { /*printf("Parser-J: %d\n", I_J);*/ parser_asm_line.instruction = I_J; parser_asm_line.instruction_type = IT_P; }
#line 1725 "parser.c"
    break;

  case 46: /* mnemonic: JALR  */
#line 287 "parser.y"
           { /*printf("Parser-JALR: %d\n", I_JALR);*/ parser_asm_line.instruction = I_JALR; parser_asm_line.instruction_type = IT_J; }
#line 1731 "parser.c"
    break;

  case 47: /* mnemonic: LB  */
#line 288 "parser.y"
         { /*printf("Parser-LB: %d\n", I_LB);*/ parser_asm_line.instruction = I_LB; parser_asm_line.instruction_type = IT_I; }
#line 1737 "parser.c"
    break;

  case 48: /* mnemonic: LI  */
#line 289 "parser.y"
         { /*printf("Parser-LI: %d\n", I_LI);*/ parser_asm_line.instruction = I_LI; parser_asm_line.instruction_type = IT_I; }
#line 1743 "parser.c"
    break;

  case 49: /* mnemonic: LW  */
#line 290 "parser.y"
         { /*printf("Parser-LW: %d\n", I_LW);*/ parser_asm_line.instruction = I_LW; parser_asm_line.instruction_type = IT_I; }
#line 1749 "parser.c"
    break;

  case 50: /* mnemonic: LUI  */
#line 291 "parser.y"
          { /*printf("Parser-LUI: %d\n", I_LUI);*/ parser_asm_line.instruction = I_LUI; parser_asm_line.instruction_type = IT_U; }
#line 1755 "parser.c"
    break;

  case 51: /* mnemonic: MUL  */
#line 292 "parser.y"
          { /*printf("Parser-LW: %d\n", I_MUL);*/ parser_asm_line.instruction = I_MUL; parser_asm_line.instruction_type = IT_R; }
#line 1761 "parser.c"
    break;

  case 52: /* mnemonic: MV  */
#line 293 "parser.y"
         { /*printf("Parser-LW: %d\n", I_MV);*/ parser_asm_line.instruction = I_MV; parser_asm_line.instruction_type = IT_P; }
#line 1767 "parser.c"
    break;

  case 53: /* mnemonic: SRLI  */
#line 294 "parser.y"
           { /*printf("Parser-SRLI: %d\n", I_SRLI);*/ parser_asm_line.instruction = I_SRLI; parser_asm_line.instruction_type = IT_I; }
#line 1773 "parser.c"
    break;

  case 54: /* mnemonic: SLLI  */
#line 295 "parser.y"
           { /*printf("Parser-SLLI: %d\n", I_SLLI);*/ parser_asm_line.instruction = I_SLLI; parser_asm_line.instruction_type = IT_I; }
#line 1779 "parser.c"
    break;

  case 55: /* mnemonic: SW  */
#line 296 "parser.y"
         { /*printf("Parser-SW: %d\n", I_SW);*/ parser_asm_line.instruction = I_SW; parser_asm_line.instruction_type = IT_S; }
#line 1785 "parser.c"
    break;

  case 56: /* register: REG_ZERO  */
#line 298 "parser.y"
                    { /*printf("REG_ZERO\n");*/ insert_register(&parser_asm_line, R_ZERO); }
#line 1791 "parser.c"
    break;

  case 57: /* register: REG_RA  */
#line 299 "parser.y"
             { /*printf("REG_RA\n");*/ insert_register(&parser_asm_line, R_RA); }
#line 1797 "parser.c"
    break;

  case 58: /* register: REG_SP  */
#line 300 "parser.y"
             { /*printf("REG_SP\n");*/ insert_register(&parser_asm_line, R_SP); }
#line 1803 "parser.c"
    break;

  case 59: /* register: REG_GP  */
#line 301 "parser.y"
             { /*printf("REG_GP\n");*/ insert_register(&parser_asm_line, R_GP); }
#line 1809 "parser.c"
    break;

  case 60: /* register: REG_TP  */
#line 302 "parser.y"
             { /*printf("REG_TP\n");*/ insert_register(&parser_asm_line, R_TP); }
#line 1815 "parser.c"
    break;

  case 61: /* register: REG_T0  */
#line 303 "parser.y"
             { /*printf("REG_T0\n");*/ insert_register(&parser_asm_line, R_T0); }
#line 1821 "parser.c"
    break;

  case 62: /* register: REG_T1  */
#line 304 "parser.y"
             { /*printf("REG_T1\n");*/ insert_register(&parser_asm_line, R_T1); }
#line 1827 "parser.c"
    break;

  case 63: /* register: REG_T2  */
#line 305 "parser.y"
             { /*printf("REG_T2\n");*/ insert_register(&parser_asm_line, R_T2); }
#line 1833 "parser.c"
    break;

  case 64: /* register: REG_T3  */
#line 306 "parser.y"
             { /*printf("REG_T3\n");*/ insert_register(&parser_asm_line, R_T3); }
#line 1839 "parser.c"
    break;

  case 65: /* register: REG_T4  */
#line 307 "parser.y"
             { /*printf("REG_T4\n");*/ insert_register(&parser_asm_line, R_T4); }
#line 1845 "parser.c"
    break;

  case 66: /* register: REG_T5  */
#line 308 "parser.y"
             { /*printf("REG_T5\n");*/ insert_register(&parser_asm_line, R_T5); }
#line 1851 "parser.c"
    break;

  case 67: /* register: REG_T6  */
#line 309 "parser.y"
             { /*printf("REG_T6\n");*/ insert_register(&parser_asm_line, R_T6); }
#line 1857 "parser.c"
    break;

  case 68: /* register: REG_FP  */
#line 310 "parser.y"
             { /*printf("REG_FP\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 1863 "parser.c"
    break;

  case 69: /* register: REG_A0  */
#line 311 "parser.y"
             { /*printf("REG_A0\n");*/ insert_register(&parser_asm_line, R_A0); }
#line 1869 "parser.c"
    break;

  case 70: /* register: REG_A1  */
#line 312 "parser.y"
             { /*printf("REG_A1\n");*/ insert_register(&parser_asm_line, R_A1); }
#line 1875 "parser.c"
    break;

  case 71: /* register: REG_A2  */
#line 313 "parser.y"
             { /*printf("REG_A2\n");*/ insert_register(&parser_asm_line, R_A2); }
#line 1881 "parser.c"
    break;

  case 72: /* register: REG_A3  */
#line 314 "parser.y"
             { /*printf("REG_A3\n");*/ insert_register(&parser_asm_line, R_A3); }
#line 1887 "parser.c"
    break;

  case 73: /* register: REG_A4  */
#line 315 "parser.y"
             { /*printf("REG_A4\n");*/ insert_register(&parser_asm_line, R_A4); }
#line 1893 "parser.c"
    break;

  case 74: /* register: REG_A5  */
#line 316 "parser.y"
             { /*printf("REG_A5\n");*/ insert_register(&parser_asm_line, R_A5); }
#line 1899 "parser.c"
    break;

  case 75: /* register: REG_A6  */
#line 317 "parser.y"
             { /*printf("REG_A6\n");*/ insert_register(&parser_asm_line, R_A6); }
#line 1905 "parser.c"
    break;

  case 76: /* register: REG_A7  */
#line 318 "parser.y"
             { /*printf("REG_A7\n");*/ insert_register(&parser_asm_line, R_A7); }
#line 1911 "parser.c"
    break;

  case 77: /* register: REG_S0  */
#line 319 "parser.y"
             { /*printf("REG_S0\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 1917 "parser.c"
    break;

  case 78: /* register: REG_S1  */
#line 320 "parser.y"
             { /*printf("REG_S1\n");*/ insert_register(&parser_asm_line, R_S1); }
#line 1923 "parser.c"
    break;

  case 79: /* register: REG_S2  */
#line 321 "parser.y"
             { /*printf("REG_S2\n");*/ insert_register(&parser_asm_line, R_S2); }
#line 1929 "parser.c"
    break;

  case 80: /* register: REG_S3  */
#line 322 "parser.y"
             { /*printf("REG_S3\n");*/ insert_register(&parser_asm_line, R_S3); }
#line 1935 "parser.c"
    break;

  case 81: /* register: REG_S4  */
#line 323 "parser.y"
             { /*printf("REG_S4\n");*/ insert_register(&parser_asm_line, R_S4); }
#line 1941 "parser.c"
    break;

  case 82: /* register: REG_S5  */
#line 324 "parser.y"
             { /*printf("REG_S5\n");*/ insert_register(&parser_asm_line, R_S5); }
#line 1947 "parser.c"
    break;

  case 83: /* register: REG_S6  */
#line 325 "parser.y"
             { /*printf("REG_S6\n");*/ insert_register(&parser_asm_line, R_S6); }
#line 1953 "parser.c"
    break;

  case 84: /* register: REG_S7  */
#line 326 "parser.y"
             { /*printf("REG_S7\n");*/ insert_register(&parser_asm_line, R_S7); }
#line 1959 "parser.c"
    break;

  case 85: /* register: REG_S8  */
#line 327 "parser.y"
             { /*printf("REG_S8\n");*/ insert_register(&parser_asm_line, R_S8); }
#line 1965 "parser.c"
    break;

  case 86: /* register: REG_S9  */
#line 328 "parser.y"
             { /*printf("REG_S9\n");*/ insert_register(&parser_asm_line, R_S9); }
#line 1971 "parser.c"
    break;

  case 87: /* register: REG_S10  */
#line 329 "parser.y"
              { /*printf("REG_S10\n");*/ insert_register(&parser_asm_line, R_S10); }
#line 1977 "parser.c"
    break;

  case 88: /* register: REG_S11  */
#line 330 "parser.y"
              { /*printf("REG_S11\n");*/ insert_register(&parser_asm_line, R_S11); }
#line 1983 "parser.c"
    break;


#line 1987 "parser.c"

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

#line 356 "parser.y"


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
