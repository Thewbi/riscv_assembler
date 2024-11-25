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
  YYSYMBOL_GLOBAL = 6,                     /* GLOBAL  */
  YYSYMBOL_TEXT = 7,                       /* TEXT  */
  YYSYMBOL_DATA = 8,                       /* DATA  */
  YYSYMBOL_BYTE = 9,                       /* BYTE  */
  YYSYMBOL_HALF = 10,                      /* HALF  */
  YYSYMBOL_WORD = 11,                      /* WORD  */
  YYSYMBOL_DWORD = 12,                     /* DWORD  */
  YYSYMBOL_ADD = 13,                       /* ADD  */
  YYSYMBOL_ADDI = 14,                      /* ADDI  */
  YYSYMBOL_AUIPC = 15,                     /* AUIPC  */
  YYSYMBOL_BEQ = 16,                       /* BEQ  */
  YYSYMBOL_BEQZ = 17,                      /* BEQZ  */
  YYSYMBOL_BGE = 18,                       /* BGE  */
  YYSYMBOL_BLT = 19,                       /* BLT  */
  YYSYMBOL_BGT = 20,                       /* BGT  */
  YYSYMBOL_BNE = 21,                       /* BNE  */
  YYSYMBOL_BNEZ = 22,                      /* BNEZ  */
  YYSYMBOL_CALL = 23,                      /* CALL  */
  YYSYMBOL_J = 24,                         /* J  */
  YYSYMBOL_JALR = 25,                      /* JALR  */
  YYSYMBOL_LD = 26,                        /* LD  */
  YYSYMBOL_LW = 27,                        /* LW  */
  YYSYMBOL_LH = 28,                        /* LH  */
  YYSYMBOL_LB = 29,                        /* LB  */
  YYSYMBOL_LI = 30,                        /* LI  */
  YYSYMBOL_LUI = 31,                       /* LUI  */
  YYSYMBOL_MUL = 32,                       /* MUL  */
  YYSYMBOL_MV = 33,                        /* MV  */
  YYSYMBOL_RET = 34,                       /* RET  */
  YYSYMBOL_SRLI = 35,                      /* SRLI  */
  YYSYMBOL_SLLI = 36,                      /* SLLI  */
  YYSYMBOL_SD = 37,                        /* SD  */
  YYSYMBOL_SW = 38,                        /* SW  */
  YYSYMBOL_SH = 39,                        /* SH  */
  YYSYMBOL_SB = 40,                        /* SB  */
  YYSYMBOL_NEW_LINE = 41,                  /* NEW_LINE  */
  YYSYMBOL_MODIFIER_HI = 42,               /* MODIFIER_HI  */
  YYSYMBOL_MODIFIER_LO = 43,               /* MODIFIER_LO  */
  YYSYMBOL_NUMERIC = 44,                   /* NUMERIC  */
  YYSYMBOL_IDENTIFIER = 45,                /* IDENTIFIER  */
  YYSYMBOL_DOT = 46,                       /* DOT  */
  YYSYMBOL_COLON = 47,                     /* COLON  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_OPENING_BRACKET = 49,           /* OPENING_BRACKET  */
  YYSYMBOL_CLOSING_BRACKET = 50,           /* CLOSING_BRACKET  */
  YYSYMBOL_REG_ZERO = 51,                  /* REG_ZERO  */
  YYSYMBOL_REG_RA = 52,                    /* REG_RA  */
  YYSYMBOL_REG_SP = 53,                    /* REG_SP  */
  YYSYMBOL_REG_GP = 54,                    /* REG_GP  */
  YYSYMBOL_REG_TP = 55,                    /* REG_TP  */
  YYSYMBOL_REG_T0 = 56,                    /* REG_T0  */
  YYSYMBOL_REG_T1 = 57,                    /* REG_T1  */
  YYSYMBOL_REG_T2 = 58,                    /* REG_T2  */
  YYSYMBOL_REG_T3 = 59,                    /* REG_T3  */
  YYSYMBOL_REG_T4 = 60,                    /* REG_T4  */
  YYSYMBOL_REG_T5 = 61,                    /* REG_T5  */
  YYSYMBOL_REG_T6 = 62,                    /* REG_T6  */
  YYSYMBOL_REG_FP = 63,                    /* REG_FP  */
  YYSYMBOL_REG_A0 = 64,                    /* REG_A0  */
  YYSYMBOL_REG_A1 = 65,                    /* REG_A1  */
  YYSYMBOL_REG_A2 = 66,                    /* REG_A2  */
  YYSYMBOL_REG_A3 = 67,                    /* REG_A3  */
  YYSYMBOL_REG_A4 = 68,                    /* REG_A4  */
  YYSYMBOL_REG_A5 = 69,                    /* REG_A5  */
  YYSYMBOL_REG_A6 = 70,                    /* REG_A6  */
  YYSYMBOL_REG_A7 = 71,                    /* REG_A7  */
  YYSYMBOL_REG_S0 = 72,                    /* REG_S0  */
  YYSYMBOL_REG_S1 = 73,                    /* REG_S1  */
  YYSYMBOL_REG_S2 = 74,                    /* REG_S2  */
  YYSYMBOL_REG_S3 = 75,                    /* REG_S3  */
  YYSYMBOL_REG_S4 = 76,                    /* REG_S4  */
  YYSYMBOL_REG_S5 = 77,                    /* REG_S5  */
  YYSYMBOL_REG_S6 = 78,                    /* REG_S6  */
  YYSYMBOL_REG_S7 = 79,                    /* REG_S7  */
  YYSYMBOL_REG_S8 = 80,                    /* REG_S8  */
  YYSYMBOL_REG_S9 = 81,                    /* REG_S9  */
  YYSYMBOL_REG_S10 = 82,                   /* REG_S10  */
  YYSYMBOL_REG_S11 = 83,                   /* REG_S11  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_asm_file = 85,                  /* asm_file  */
  YYSYMBOL_line_end = 86,                  /* line_end  */
  YYSYMBOL_asm_line = 87,                  /* asm_line  */
  YYSYMBOL_modifier = 88,                  /* modifier  */
  YYSYMBOL_params = 89,                    /* params  */
  YYSYMBOL_param_1 = 90,                   /* param_1  */
  YYSYMBOL_param_2 = 91,                   /* param_2  */
  YYSYMBOL_param_3 = 92,                   /* param_3  */
  YYSYMBOL_label = 93,                     /* label  */
  YYSYMBOL_expr = 94,                      /* expr  */
  YYSYMBOL_csv_identifier_list = 95,       /* csv_identifier_list  */
  YYSYMBOL_assembler_instruction = 96,     /* assembler_instruction  */
  YYSYMBOL_mnemonic = 97,                  /* mnemonic  */
  YYSYMBOL_register = 98                   /* register  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  95
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    85,    87,    89,    91,    93,    96,   109,
     119,   131,   140,   149,   161,   177,   179,   182,   185,   188,
     191,   194,   197,   202,   209,   216,   224,   230,   237,   244,
     252,   258,   265,   272,   280,   287,   292,   302,   328,   333,
     354,   356,   359,   377,   389,   400,   411,   419,   427,   436,
     445,   454,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524
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
  "GLOBL", "GLOBAL", "TEXT", "DATA", "BYTE", "HALF", "WORD", "DWORD",
  "ADD", "ADDI", "AUIPC", "BEQ", "BEQZ", "BGE", "BLT", "BGT", "BNE",
  "BNEZ", "CALL", "J", "JALR", "LD", "LW", "LH", "LB", "LI", "LUI", "MUL",
  "MV", "RET", "SRLI", "SLLI", "SD", "SW", "SH", "SB", "NEW_LINE",
  "MODIFIER_HI", "MODIFIER_LO", "NUMERIC", "IDENTIFIER", "DOT", "COLON",
  "COMMA", "OPENING_BRACKET", "CLOSING_BRACKET", "REG_ZERO", "REG_RA",
  "REG_SP", "REG_GP", "REG_TP", "REG_T0", "REG_T1", "REG_T2", "REG_T3",
  "REG_T4", "REG_T5", "REG_T6", "REG_FP", "REG_A0", "REG_A1", "REG_A2",
  "REG_A3", "REG_A4", "REG_A5", "REG_A6", "REG_A7", "REG_S0", "REG_S1",
  "REG_S2", "REG_S3", "REG_S4", "REG_S5", "REG_S6", "REG_S7", "REG_S8",
  "REG_S9", "REG_S10", "REG_S11", "$accept", "asm_file", "line_end",
  "asm_line", "modifier", "params", "param_1", "param_2", "param_3",
  "label", "expr", "csv_identifier_list", "assembler_instruction",
  "mnemonic", "register", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,     1,    38,     4,     4,   -39,   -39,   171,   171,   171,
     171,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
       8,    10,    50,     3,    15,   252,   -39,     9,    46,   -39,
      47,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,     3,   -39,     9,
     -39,   -39,    48,    49,    51,   -39,    54,   -39,   171,     4,
     -39,   -39,   171,   171,   171,    89,   -39,   -39,    53,    61,
      62,    55,    64,    65,    67,   -39,   -39,   -39,   -39,   171,
     171,   171,   131,    66,    68,    69,    71,    72,    77,    79,
     -39,   -39,   -39,   -39,   171,   171,   171,   -39,    78,    80,
      85,   -39,   -39,   -39
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    46,    47,     0,     0,     0,
       0,    52,    53,    54,    55,    56,    58,    60,    59,    57,
      61,    62,    63,    64,    69,    68,    66,    65,    67,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     7,
       0,     0,     0,     3,     6,    14,    12,    11,     0,    43,
      40,    44,    45,    37,    39,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    48,    38,
      49,    50,    51,    36,    35,     1,     2,     5,    13,    10,
      15,    16,    37,    39,     0,     9,    22,    26,     0,     0,
       4,     8,     0,     0,     0,    21,    42,    41,     0,     0,
       0,    37,    39,     0,    20,    30,    24,    23,    25,     0,
       0,     0,    19,     0,     0,     0,    37,    39,     0,    17,
      34,    28,    27,    29,     0,     0,     0,    18,     0,     0,
       0,    32,    31,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -38,    14,   -39,   -22,    -3,   -39,   -39,   -39,   -39,
      -7,     0,    84,    91,   -39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    42,    43,    44,   104,   105,   106,   124,   139,    45,
     107,    51,    46,    47,    89
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      88,    90,    91,    92,    52,    96,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    49,    48,    40,    41,    50,
      95,   100,   101,   102,   103,    93,    39,    94,    97,   110,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,   123,   108,   109,   111,   112,   113,     0,
     114,   116,   115,   126,   129,   118,   119,   120,   125,   117,
     138,   127,   128,   130,   131,   132,   141,     0,   142,   143,
     144,   145,   133,   134,   135,   140,   146,   147,   151,    98,
     152,   100,   101,   121,   122,   153,    99,   148,   149,   150,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,   100,   101,   136,   137,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    53,    54,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38
};

static const yytype_int16 yycheck[] =
{
       7,     8,     9,    10,     4,    43,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     7,    45,    44,    45,    45,
       0,    42,    43,    44,    45,    47,    41,    47,    44,    97,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   115,    48,    48,    99,    49,    49,    -1,
      49,   108,    48,    50,    49,   112,   113,   114,   115,   109,
     132,    50,    50,    49,    49,    48,    50,    -1,    50,    50,
      49,    49,   129,   130,   131,   132,    49,    48,    50,    45,
      50,    42,    43,    44,    45,    50,    45,   144,   145,   146,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    44,    45,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      44,    45,    85,    86,    87,    93,    96,    97,    45,     7,
      45,    95,    95,    44,    45,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    94,    98,
      94,    94,    94,    47,    47,     0,    85,    86,    96,    97,
      42,    43,    44,    45,    88,    89,    90,    94,    48,    48,
      85,    89,    49,    49,    49,    48,    94,    95,    94,    94,
      94,    44,    45,    88,    91,    94,    50,    50,    50,    49,
      49,    49,    48,    94,    94,    94,    44,    45,    88,    92,
      94,    50,    50,    50,    49,    49,    49,    48,    94,    94,
      94,    50,    50,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    84,    85,    85,    85,    85,    85,    86,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    91,    91,    91,
      91,    92,    92,    92,    92,    93,    93,    94,    94,    94,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     1,     1,     3,     2,
       2,     1,     1,     2,     1,     1,     1,     5,     6,     4,
       3,     2,     1,     4,     4,     4,     1,     4,     4,     4,
       1,     4,     4,     4,     1,     2,     2,     1,     1,     1,
       1,     3,     4,     2,     2,     2,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 96 "parser.y"
                          {
        //printf("label mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno -1);

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, (yyvsp[-2].string_val), strlen((yyvsp[-2].string_val)));

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1469 "parser.c"
    break;

  case 9: /* asm_line: mnemonic params  */
#line 109 "parser.y"
                        {
        //printf("mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno -1);

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1483 "parser.c"
    break;

  case 10: /* asm_line: label mnemonic  */
#line 119 "parser.y"
                       {
        //printf("label mnemonic\n");
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno - 1);

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, (yyvsp[-1].string_val), strlen((yyvsp[-1].string_val)));

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1499 "parser.c"
    break;

  case 11: /* asm_line: mnemonic  */
#line 131 "parser.y"
                 {
        //printf("mnemonic\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1512 "parser.c"
    break;

  case 12: /* asm_line: assembler_instruction  */
#line 140 "parser.y"
                          {
        printf("assembler_instruction without label\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1525 "parser.c"
    break;

  case 13: /* asm_line: label assembler_instruction  */
#line 149 "parser.y"
                                {
        printf("assembler_instruction  with label\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, (yyvsp[-1].string_val), strlen((yyvsp[-1].string_val)));

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1541 "parser.c"
    break;

  case 14: /* asm_line: label  */
#line 161 "parser.y"
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
#line 1560 "parser.c"
    break;

  case 15: /* modifier: MODIFIER_HI  */
#line 177 "parser.y"
                { printf("test_123\n"); strncpy((yyval.string_val), "HI", 2); }
#line 1566 "parser.c"
    break;

  case 16: /* modifier: MODIFIER_LO  */
#line 179 "parser.y"
                { printf("test_456\n"); strncpy((yyval.string_val), "LOW", 3); }
#line 1572 "parser.c"
    break;

  case 17: /* params: param_1 COMMA param_2 COMMA param_3  */
#line 182 "parser.y"
                                             {
        //printf("param_1 COMMA param_2 COMMA param_3\n");
    }
#line 1580 "parser.c"
    break;

  case 18: /* params: param_1 COMMA param_2 COMMA param_3 COMMA  */
#line 185 "parser.y"
                                                {
        //printf("param_1 COMMA param_2 COMMA param_3\n");
    }
#line 1588 "parser.c"
    break;

  case 19: /* params: param_1 COMMA param_2 COMMA  */
#line 188 "parser.y"
                                  {
        //printf("param_1 COMMA param_2\n");
    }
#line 1596 "parser.c"
    break;

  case 20: /* params: param_1 COMMA param_2  */
#line 191 "parser.y"
                            {
        //printf("param_1 COMMA param_2\n");
    }
#line 1604 "parser.c"
    break;

  case 21: /* params: param_1 COMMA  */
#line 194 "parser.y"
                    {
        //printf("param_1\n");
    }
#line 1612 "parser.c"
    break;

  case 22: /* params: param_1  */
#line 197 "parser.y"
              {
        //printf("param_1\n");
    }
#line 1620 "parser.c"
    break;

  case 23: /* param_1: IDENTIFIER OPENING_BRACKET expr CLOSING_BRACKET  */
#line 202 "parser.y"
                                                    {
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-3].string_val), 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1631 "parser.c"
    break;

  case 24: /* param_1: NUMERIC OPENING_BRACKET expr CLOSING_BRACKET  */
#line 209 "parser.y"
                                                 {
        insert_offset(&parser_asm_line, (yyvsp[-2].sym), 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1642 "parser.c"
    break;

  case 25: /* param_1: modifier OPENING_BRACKET expr CLOSING_BRACKET  */
#line 216 "parser.y"
                                                  {
        printf("modifier 1: '%s' \n", (char *) (yyvsp[-3].string_val));
        insert_modifier(&parser_asm_line, (char *)(yyvsp[-3].string_val), 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1654 "parser.c"
    break;

  case 26: /* param_1: expr  */
#line 224 "parser.y"
         {
        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1663 "parser.c"
    break;

  case 27: /* param_2: IDENTIFIER OPENING_BRACKET expr CLOSING_BRACKET  */
#line 230 "parser.y"
                                                    {
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-3].string_val), 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1674 "parser.c"
    break;

  case 28: /* param_2: NUMERIC OPENING_BRACKET expr CLOSING_BRACKET  */
#line 237 "parser.y"
                                                 {
        insert_offset(&parser_asm_line, (yyvsp[-2].sym), 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1685 "parser.c"
    break;

  case 29: /* param_2: modifier OPENING_BRACKET expr CLOSING_BRACKET  */
#line 244 "parser.y"
                                                  {
        printf("modifier 2: '%s' \n", (char *) (yyvsp[-3].string_val));
        insert_modifier(&parser_asm_line, (char *)(yyvsp[-3].string_val), 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1697 "parser.c"
    break;

  case 30: /* param_2: expr  */
#line 252 "parser.y"
         {
        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1706 "parser.c"
    break;

  case 31: /* param_3: IDENTIFIER OPENING_BRACKET expr CLOSING_BRACKET  */
#line 258 "parser.y"
                                                    {
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-3].string_val), 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1717 "parser.c"
    break;

  case 32: /* param_3: NUMERIC OPENING_BRACKET expr CLOSING_BRACKET  */
#line 265 "parser.y"
                                                 {
        insert_offset(&parser_asm_line, (yyvsp[-2].sym), 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1728 "parser.c"
    break;

  case 33: /* param_3: modifier OPENING_BRACKET expr CLOSING_BRACKET  */
#line 272 "parser.y"
                                                  {
        printf("modifier 3: '%s' \n", (char *) (yyvsp[-3].string_val));
        insert_modifier(&parser_asm_line, (char *)(yyvsp[-3].string_val), 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1740 "parser.c"
    break;

  case 34: /* param_3: expr  */
#line 280 "parser.y"
         {
        //printf("expr 3\n");
        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1750 "parser.c"
    break;

  case 35: /* label: IDENTIFIER COLON  */
#line 287 "parser.y"
                     {
        //printf("label A detected!\n");
        strncpy((yyval.string_val), (yyvsp[-1].string_val), 100);
    }
#line 1759 "parser.c"
    break;

  case 36: /* label: NUMERIC COLON  */
#line 292 "parser.y"
                  {
        //printf("label B detected!\n");
        char buffer[100];
        memset(buffer, 0, 100);
        snprintf(buffer, 100, "%d", (yyvsp[-1].int_val));
        strncpy((yyval.string_val), buffer, 100);
    }
#line 1771 "parser.c"
    break;

  case 37: /* expr: NUMERIC  */
#line 302 "parser.y"
            {
        printf("PARSER-NUMERIC: %16" PRIx64 "\n", (yyvsp[0].int_val));
        //insert_integer_immediate(&parser_asm_line, $1);

        if (current_node == NULL) {
            //current_node = new node_t;
            current_node = (node_t *)malloc(sizeof(node_t));

            //printf("Line: %d\n", yylineno);

            reset_node(current_node);

            //printf("PARSER-NUMERIC: creating node: %d\n", $1);
            printf("PARSER-NUMERIC: creating node: %16" PRIx64 "\n", (yyvsp[0].int_val));
            //current_node->int_val = sign_extend_20_bit_to_uint32_t($1);
            current_node->int_val = (yyvsp[0].int_val);
            //printf("PARSER-NUMERIC: creating node: %d\n", current_node->int_val);

            //printf("PARSER-NUMERIC: creating node: %d\n", current_node->int_val);

            (yyval.expr_ptr) = current_node;
        } else {
            printf("PARSER-NUMERIC: not null!\n");
        }
    }
#line 1801 "parser.c"
    break;

  case 38: /* expr: register  */
#line 328 "parser.y"
             {
        //printf("expr - register\n");
        (yyval.expr_ptr) = current_node;
    }
#line 1810 "parser.c"
    break;

  case 39: /* expr: IDENTIFIER  */
#line 333 "parser.y"
               {
        printf("expr - IDENTIFIER: %s \n", (yyvsp[0].string_val));

        if (current_node == NULL) {

            current_node = (node_t *)malloc(sizeof(node_t));

            reset_node(current_node);

            memset(current_node->string_val, 0, 100);
            memcpy(current_node->string_val, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

            (yyval.expr_ptr) = current_node;
        }

        //  else {
        //     printf("expr - IDENTIFIER: not null!\n");
        // }
    }
#line 1834 "parser.c"
    break;

  case 42: /* assembler_instruction: EQU IDENTIFIER COMMA expr  */
#line 359 "parser.y"
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
#line 1856 "parser.c"
    break;

  case 43: /* assembler_instruction: SECTION TEXT  */
#line 377 "parser.y"
                 {

        parser_asm_line.asm_instruction = AI_SECTION;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        //memcpy(parser_asm_line.asm_instruction_symbol, $2, strlen($2));
        memcpy(parser_asm_line.asm_instruction_symbol, ".text", strlen(".text"));

        current_node = NULL;

    }
#line 1872 "parser.c"
    break;

  case 44: /* assembler_instruction: GLOBL csv_identifier_list  */
#line 389 "parser.y"
                              {

        parser_asm_line.asm_instruction = AI_GLOBL;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        current_node = NULL;

    }
#line 1887 "parser.c"
    break;

  case 45: /* assembler_instruction: GLOBAL csv_identifier_list  */
#line 400 "parser.y"
                               {

        parser_asm_line.asm_instruction = AI_GLOBL;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        current_node = NULL;

    }
#line 1902 "parser.c"
    break;

  case 46: /* assembler_instruction: TEXT  */
#line 411 "parser.y"
         {

        parser_asm_line.asm_instruction = AI_TEXT;

        current_node = NULL;

    }
#line 1914 "parser.c"
    break;

  case 47: /* assembler_instruction: DATA  */
#line 419 "parser.y"
         {

        parser_asm_line.asm_instruction = AI_DATA;

        current_node = NULL;

    }
#line 1926 "parser.c"
    break;

  case 48: /* assembler_instruction: BYTE expr  */
#line 427 "parser.y"
              {

        parser_asm_line.asm_instruction = AI_BYTE;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 1939 "parser.c"
    break;

  case 49: /* assembler_instruction: HALF expr  */
#line 436 "parser.y"
              {

        parser_asm_line.asm_instruction = AI_HALF;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 1952 "parser.c"
    break;

  case 50: /* assembler_instruction: WORD expr  */
#line 445 "parser.y"
              {

        parser_asm_line.asm_instruction = AI_WORD;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 1965 "parser.c"
    break;

  case 51: /* assembler_instruction: DWORD expr  */
#line 454 "parser.y"
               {

        parser_asm_line.asm_instruction = AI_DWORD;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 1978 "parser.c"
    break;

  case 52: /* mnemonic: ADD  */
#line 463 "parser.y"
               { /*printf("Parser-ADD: %d\n", I_ADD);*/ /*parser_asm_line.instruction = I_ADD; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_ADD, IT_R); }
#line 1984 "parser.c"
    break;

  case 53: /* mnemonic: ADDI  */
#line 464 "parser.y"
           { /*printf("Parser-ADDI: %d\n", I_ADDI);*/ /*parser_asm_line.instruction = I_ADDI; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_ADDI, IT_R); }
#line 1990 "parser.c"
    break;

  case 54: /* mnemonic: AUIPC  */
#line 465 "parser.y"
            { /*printf("Parser-AUIPC: %d\n", I_AUIPC);*/ /*parser_asm_line.instruction = I_AUIPC; parser_asm_line.instruction_type = IT_U;*/ set_instruction(&parser_asm_line, I_AUIPC, IT_U); }
#line 1996 "parser.c"
    break;

  case 55: /* mnemonic: BEQ  */
#line 466 "parser.y"
          { /*printf("Parser-BEQ: %d\n", I_BEQ);*/ /*parser_asm_line.instruction = I_BEQ; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BEQ, IT_B); }
#line 2002 "parser.c"
    break;

  case 56: /* mnemonic: BEQZ  */
#line 467 "parser.y"
           { /*printf("Parser-BEQZ: %d\n", I_BEQZ);*/ /*parser_asm_line.instruction = I_BEQZ; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_BEQZ, IT_P); }
#line 2008 "parser.c"
    break;

  case 57: /* mnemonic: BNE  */
#line 468 "parser.y"
          { /*printf("Parser-BNE: %d\n", I_BNE);*/ /*parser_asm_line.instruction = I_BNE; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BNE, IT_B); }
#line 2014 "parser.c"
    break;

  case 58: /* mnemonic: BGE  */
#line 469 "parser.y"
          { /*printf("Parser-BGE: %d\n", I_BGE);*/ /*parser_asm_line.instruction = I_BGE; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BGE, IT_B); }
#line 2020 "parser.c"
    break;

  case 59: /* mnemonic: BGT  */
#line 470 "parser.y"
          { /*printf("Parser-BGT: %d\n", I_BGT);*/ /*parser_asm_line.instruction = I_BGT; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BGT, IT_B); }
#line 2026 "parser.c"
    break;

  case 60: /* mnemonic: BLT  */
#line 471 "parser.y"
          { /*printf("Parser-BLT: %d\n", I_BLT);*/ /*parser_asm_line.instruction = I_BLT; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BLT, IT_B); }
#line 2032 "parser.c"
    break;

  case 61: /* mnemonic: BNEZ  */
#line 472 "parser.y"
           { /*printf("Parser-BNEZ: %d\n", I_BNEZ);*/ /*parser_asm_line.instruction = I_BNEZ; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_BNEZ, IT_P); }
#line 2038 "parser.c"
    break;

  case 62: /* mnemonic: CALL  */
#line 473 "parser.y"
           { /*printf("Parser-CALL: %d\n", I_CALL);*/ /*parser_asm_line.instruction = I_CALL; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_CALL, IT_P); }
#line 2044 "parser.c"
    break;

  case 63: /* mnemonic: J  */
#line 474 "parser.y"
        { /*printf("Parser-J: %d\n", I_J);*/ /*parser_asm_line.instruction = I_J; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_J, IT_P); }
#line 2050 "parser.c"
    break;

  case 64: /* mnemonic: JALR  */
#line 475 "parser.y"
           { /*printf("Parser-JALR: %d\n", I_JALR);*/ /*parser_asm_line.instruction = I_JALR; parser_asm_line.instruction_type = IT_J;*/ set_instruction(&parser_asm_line, I_JALR, IT_J); }
#line 2056 "parser.c"
    break;

  case 65: /* mnemonic: LB  */
#line 476 "parser.y"
         { /*printf("Parser-LB: %d\n", I_LB);*/ /*parser_asm_line.instruction = I_LB; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LB, IT_I); }
#line 2062 "parser.c"
    break;

  case 66: /* mnemonic: LH  */
#line 477 "parser.y"
         { /*printf("Parser-LH: %d\n", I_LH);*/ /*parser_asm_line.instruction = I_LH; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LH, IT_I); }
#line 2068 "parser.c"
    break;

  case 67: /* mnemonic: LI  */
#line 478 "parser.y"
         { /*printf("Parser-LI: %d\n", I_LI);*/ /*parser_asm_line.instruction = I_LI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LI, IT_P); }
#line 2074 "parser.c"
    break;

  case 68: /* mnemonic: LW  */
#line 479 "parser.y"
         { /*printf("Parser-LW: %d\n", I_LW);*/ /*parser_asm_line.instruction = I_LW; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LW, IT_I); }
#line 2080 "parser.c"
    break;

  case 69: /* mnemonic: LD  */
#line 480 "parser.y"
         { /*printf("Parser-LD: %d\n", I_LD);*/ /*parser_asm_line.instruction = I_LD; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LD, IT_I); }
#line 2086 "parser.c"
    break;

  case 70: /* mnemonic: LUI  */
#line 481 "parser.y"
          { /*printf("Parser-LUI: %d\n", I_LUI);*/ /*parser_asm_line.instruction = I_LUI; parser_asm_line.instruction_type = IT_U;*/ set_instruction(&parser_asm_line, I_LUI, IT_U); }
#line 2092 "parser.c"
    break;

  case 71: /* mnemonic: MUL  */
#line 482 "parser.y"
          { /*printf("Parser-LW: %d\n", I_MUL);*/ /*parser_asm_line.instruction = I_MUL; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_MUL, IT_R); }
#line 2098 "parser.c"
    break;

  case 72: /* mnemonic: MV  */
#line 483 "parser.y"
         { /*printf("Parser-LW: %d\n", I_MV);*/ /*parser_asm_line.instruction = I_MV; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_MV, IT_P); }
#line 2104 "parser.c"
    break;

  case 73: /* mnemonic: RET  */
#line 484 "parser.y"
          { /*printf("Parser-RET: %d\n", I_RET);*/ /*parser_asm_line.instruction = I_RET; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_RET, IT_P); }
#line 2110 "parser.c"
    break;

  case 74: /* mnemonic: SRLI  */
#line 485 "parser.y"
           { /*printf("Parser-SRLI: %d\n", I_SRLI);*/ /*parser_asm_line.instruction = I_SRLI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_SRLI, IT_I); }
#line 2116 "parser.c"
    break;

  case 75: /* mnemonic: SLLI  */
#line 486 "parser.y"
           { /*printf("Parser-SLLI: %d\n", I_SLLI);*/ /*parser_asm_line.instruction = I_SLLI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_SLLI, IT_I); }
#line 2122 "parser.c"
    break;

  case 76: /* mnemonic: SD  */
#line 487 "parser.y"
         { /*printf("Parser-SD: %d\n", I_SD);*/ /*parser_asm_line.instruction = I_SD; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SD, IT_S); }
#line 2128 "parser.c"
    break;

  case 77: /* mnemonic: SW  */
#line 488 "parser.y"
         { /*printf("Parser-SW: %d\n", I_SW);*/ /*parser_asm_line.instruction = I_SW; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SW, IT_S); }
#line 2134 "parser.c"
    break;

  case 78: /* mnemonic: SH  */
#line 489 "parser.y"
         { /*printf("Parser-SH: %d\n", I_SH);*/ /*parser_asm_line.instruction = I_SH; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SH, IT_S); }
#line 2140 "parser.c"
    break;

  case 79: /* mnemonic: SB  */
#line 490 "parser.y"
         { /*printf("Parser-SB: %d\n", I_SB);*/ /*parser_asm_line.instruction = I_SB; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SB, IT_S); }
#line 2146 "parser.c"
    break;

  case 80: /* register: REG_ZERO  */
#line 492 "parser.y"
                    { /*printf("REG_ZERO\n");*/ insert_register(&parser_asm_line, R_ZERO); }
#line 2152 "parser.c"
    break;

  case 81: /* register: REG_RA  */
#line 493 "parser.y"
             { /*printf("REG_RA\n");*/ insert_register(&parser_asm_line, R_RA); }
#line 2158 "parser.c"
    break;

  case 82: /* register: REG_SP  */
#line 494 "parser.y"
             { /*printf("REG_SP\n");*/ insert_register(&parser_asm_line, R_SP); }
#line 2164 "parser.c"
    break;

  case 83: /* register: REG_GP  */
#line 495 "parser.y"
             { /*printf("REG_GP\n");*/ insert_register(&parser_asm_line, R_GP); }
#line 2170 "parser.c"
    break;

  case 84: /* register: REG_TP  */
#line 496 "parser.y"
             { /*printf("REG_TP\n");*/ insert_register(&parser_asm_line, R_TP); }
#line 2176 "parser.c"
    break;

  case 85: /* register: REG_T0  */
#line 497 "parser.y"
             { /*printf("REG_T0\n");*/ insert_register(&parser_asm_line, R_T0); }
#line 2182 "parser.c"
    break;

  case 86: /* register: REG_T1  */
#line 498 "parser.y"
             { /*printf("REG_T1\n");*/ insert_register(&parser_asm_line, R_T1); }
#line 2188 "parser.c"
    break;

  case 87: /* register: REG_T2  */
#line 499 "parser.y"
             { /*printf("REG_T2\n");*/ insert_register(&parser_asm_line, R_T2); }
#line 2194 "parser.c"
    break;

  case 88: /* register: REG_T3  */
#line 500 "parser.y"
             { /*printf("REG_T3\n");*/ insert_register(&parser_asm_line, R_T3); }
#line 2200 "parser.c"
    break;

  case 89: /* register: REG_T4  */
#line 501 "parser.y"
             { /*printf("REG_T4\n");*/ insert_register(&parser_asm_line, R_T4); }
#line 2206 "parser.c"
    break;

  case 90: /* register: REG_T5  */
#line 502 "parser.y"
             { /*printf("REG_T5\n");*/ insert_register(&parser_asm_line, R_T5); }
#line 2212 "parser.c"
    break;

  case 91: /* register: REG_T6  */
#line 503 "parser.y"
             { /*printf("REG_T6\n");*/ insert_register(&parser_asm_line, R_T6); }
#line 2218 "parser.c"
    break;

  case 92: /* register: REG_FP  */
#line 504 "parser.y"
             { /*printf("REG_FP\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 2224 "parser.c"
    break;

  case 93: /* register: REG_A0  */
#line 505 "parser.y"
             { /*printf("REG_A0\n");*/ insert_register(&parser_asm_line, R_A0); }
#line 2230 "parser.c"
    break;

  case 94: /* register: REG_A1  */
#line 506 "parser.y"
             { /*printf("REG_A1\n");*/ insert_register(&parser_asm_line, R_A1); }
#line 2236 "parser.c"
    break;

  case 95: /* register: REG_A2  */
#line 507 "parser.y"
             { /*printf("REG_A2\n");*/ insert_register(&parser_asm_line, R_A2); }
#line 2242 "parser.c"
    break;

  case 96: /* register: REG_A3  */
#line 508 "parser.y"
             { /*printf("REG_A3\n");*/ insert_register(&parser_asm_line, R_A3); }
#line 2248 "parser.c"
    break;

  case 97: /* register: REG_A4  */
#line 509 "parser.y"
             { /*printf("REG_A4\n");*/ insert_register(&parser_asm_line, R_A4); }
#line 2254 "parser.c"
    break;

  case 98: /* register: REG_A5  */
#line 510 "parser.y"
             { /*printf("REG_A5\n");*/ insert_register(&parser_asm_line, R_A5); }
#line 2260 "parser.c"
    break;

  case 99: /* register: REG_A6  */
#line 511 "parser.y"
             { /*printf("REG_A6\n");*/ insert_register(&parser_asm_line, R_A6); }
#line 2266 "parser.c"
    break;

  case 100: /* register: REG_A7  */
#line 512 "parser.y"
             { /*printf("REG_A7\n");*/ insert_register(&parser_asm_line, R_A7); }
#line 2272 "parser.c"
    break;

  case 101: /* register: REG_S0  */
#line 513 "parser.y"
             { /*printf("REG_S0\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 2278 "parser.c"
    break;

  case 102: /* register: REG_S1  */
#line 514 "parser.y"
             { /*printf("REG_S1\n");*/ insert_register(&parser_asm_line, R_S1); }
#line 2284 "parser.c"
    break;

  case 103: /* register: REG_S2  */
#line 515 "parser.y"
             { /*printf("REG_S2\n");*/ insert_register(&parser_asm_line, R_S2); }
#line 2290 "parser.c"
    break;

  case 104: /* register: REG_S3  */
#line 516 "parser.y"
             { /*printf("REG_S3\n");*/ insert_register(&parser_asm_line, R_S3); }
#line 2296 "parser.c"
    break;

  case 105: /* register: REG_S4  */
#line 517 "parser.y"
             { /*printf("REG_S4\n");*/ insert_register(&parser_asm_line, R_S4); }
#line 2302 "parser.c"
    break;

  case 106: /* register: REG_S5  */
#line 518 "parser.y"
             { /*printf("REG_S5\n");*/ insert_register(&parser_asm_line, R_S5); }
#line 2308 "parser.c"
    break;

  case 107: /* register: REG_S6  */
#line 519 "parser.y"
             { /*printf("REG_S6\n");*/ insert_register(&parser_asm_line, R_S6); }
#line 2314 "parser.c"
    break;

  case 108: /* register: REG_S7  */
#line 520 "parser.y"
             { /*printf("REG_S7\n");*/ insert_register(&parser_asm_line, R_S7); }
#line 2320 "parser.c"
    break;

  case 109: /* register: REG_S8  */
#line 521 "parser.y"
             { /*printf("REG_S8\n");*/ insert_register(&parser_asm_line, R_S8); }
#line 2326 "parser.c"
    break;

  case 110: /* register: REG_S9  */
#line 522 "parser.y"
             { /*printf("REG_S9\n");*/ insert_register(&parser_asm_line, R_S9); }
#line 2332 "parser.c"
    break;

  case 111: /* register: REG_S10  */
#line 523 "parser.y"
              { /*printf("REG_S10\n");*/ insert_register(&parser_asm_line, R_S10); }
#line 2338 "parser.c"
    break;

  case 112: /* register: REG_S11  */
#line 524 "parser.y"
              { /*printf("REG_S11\n");*/ insert_register(&parser_asm_line, R_S11); }
#line 2344 "parser.c"
    break;


#line 2348 "parser.c"

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

#line 548 "parser.y"


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
