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
  YYSYMBOL_DOT_EQU = 3,                    /* DOT_EQU  */
  YYSYMBOL_DOT_SECTION = 4,                /* DOT_SECTION  */
  YYSYMBOL_DOT_GLOBL = 5,                  /* DOT_GLOBL  */
  YYSYMBOL_DOT_GLOBAL = 6,                 /* DOT_GLOBAL  */
  YYSYMBOL_DOT_TEXT = 7,                   /* DOT_TEXT  */
  YYSYMBOL_DOT_DATA = 8,                   /* DOT_DATA  */
  YYSYMBOL_DOT_BYTE = 9,                   /* DOT_BYTE  */
  YYSYMBOL_DOT_HALF = 10,                  /* DOT_HALF  */
  YYSYMBOL_DOT_WORD = 11,                  /* DOT_WORD  */
  YYSYMBOL_DOT_DWORD = 12,                 /* DOT_DWORD  */
  YYSYMBOL_DOT_FILE = 13,                  /* DOT_FILE  */
  YYSYMBOL_DOT_RODATA = 14,                /* DOT_RODATA  */
  YYSYMBOL_DOT_ASCIZ = 15,                 /* DOT_ASCIZ  */
  YYSYMBOL_DOT_SKIP = 16,                  /* DOT_SKIP  */
  YYSYMBOL_DOT_STRING = 17,                /* DOT_STRING  */
  YYSYMBOL_ADD = 18,                       /* ADD  */
  YYSYMBOL_ADDI = 19,                      /* ADDI  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_ANDI = 21,                      /* ANDI  */
  YYSYMBOL_AUIPC = 22,                     /* AUIPC  */
  YYSYMBOL_BEQ = 23,                       /* BEQ  */
  YYSYMBOL_BEQZ = 24,                      /* BEQZ  */
  YYSYMBOL_BGE = 25,                       /* BGE  */
  YYSYMBOL_BLT = 26,                       /* BLT  */
  YYSYMBOL_BGT = 27,                       /* BGT  */
  YYSYMBOL_BNE = 28,                       /* BNE  */
  YYSYMBOL_BNEZ = 29,                      /* BNEZ  */
  YYSYMBOL_CALL = 30,                      /* CALL  */
  YYSYMBOL_J = 31,                         /* J  */
  YYSYMBOL_JR = 32,                        /* JR  */
  YYSYMBOL_JALR = 33,                      /* JALR  */
  YYSYMBOL_LD = 34,                        /* LD  */
  YYSYMBOL_LW = 35,                        /* LW  */
  YYSYMBOL_LH = 36,                        /* LH  */
  YYSYMBOL_LB = 37,                        /* LB  */
  YYSYMBOL_LBU = 38,                       /* LBU  */
  YYSYMBOL_LI = 39,                        /* LI  */
  YYSYMBOL_LUI = 40,                       /* LUI  */
  YYSYMBOL_MUL = 41,                       /* MUL  */
  YYSYMBOL_MV = 42,                        /* MV  */
  YYSYMBOL_NOP = 43,                       /* NOP  */
  YYSYMBOL_NOT = 44,                       /* NOT  */
  YYSYMBOL_RET = 45,                       /* RET  */
  YYSYMBOL_SRLI = 46,                      /* SRLI  */
  YYSYMBOL_SLLI = 47,                      /* SLLI  */
  YYSYMBOL_SD = 48,                        /* SD  */
  YYSYMBOL_SW = 49,                        /* SW  */
  YYSYMBOL_SH = 50,                        /* SH  */
  YYSYMBOL_SB = 51,                        /* SB  */
  YYSYMBOL_WFI = 52,                       /* WFI  */
  YYSYMBOL_NEW_LINE = 53,                  /* NEW_LINE  */
  YYSYMBOL_MODIFIER_HI = 54,               /* MODIFIER_HI  */
  YYSYMBOL_MODIFIER_LO = 55,               /* MODIFIER_LO  */
  YYSYMBOL_NUMERIC = 56,                   /* NUMERIC  */
  YYSYMBOL_IDENTIFIER = 57,                /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 58,            /* STRING_LITERAL  */
  YYSYMBOL_DOT = 59,                       /* DOT  */
  YYSYMBOL_COLON = 60,                     /* COLON  */
  YYSYMBOL_COMMA = 61,                     /* COMMA  */
  YYSYMBOL_OPENING_BRACKET = 62,           /* OPENING_BRACKET  */
  YYSYMBOL_CLOSING_BRACKET = 63,           /* CLOSING_BRACKET  */
  YYSYMBOL_REG_ZERO = 64,                  /* REG_ZERO  */
  YYSYMBOL_REG_RA = 65,                    /* REG_RA  */
  YYSYMBOL_REG_SP = 66,                    /* REG_SP  */
  YYSYMBOL_REG_GP = 67,                    /* REG_GP  */
  YYSYMBOL_REG_TP = 68,                    /* REG_TP  */
  YYSYMBOL_REG_T0 = 69,                    /* REG_T0  */
  YYSYMBOL_REG_T1 = 70,                    /* REG_T1  */
  YYSYMBOL_REG_T2 = 71,                    /* REG_T2  */
  YYSYMBOL_REG_T3 = 72,                    /* REG_T3  */
  YYSYMBOL_REG_T4 = 73,                    /* REG_T4  */
  YYSYMBOL_REG_T5 = 74,                    /* REG_T5  */
  YYSYMBOL_REG_T6 = 75,                    /* REG_T6  */
  YYSYMBOL_REG_FP = 76,                    /* REG_FP  */
  YYSYMBOL_REG_A0 = 77,                    /* REG_A0  */
  YYSYMBOL_REG_A1 = 78,                    /* REG_A1  */
  YYSYMBOL_REG_A2 = 79,                    /* REG_A2  */
  YYSYMBOL_REG_A3 = 80,                    /* REG_A3  */
  YYSYMBOL_REG_A4 = 81,                    /* REG_A4  */
  YYSYMBOL_REG_A5 = 82,                    /* REG_A5  */
  YYSYMBOL_REG_A6 = 83,                    /* REG_A6  */
  YYSYMBOL_REG_A7 = 84,                    /* REG_A7  */
  YYSYMBOL_REG_S0 = 85,                    /* REG_S0  */
  YYSYMBOL_REG_S1 = 86,                    /* REG_S1  */
  YYSYMBOL_REG_S2 = 87,                    /* REG_S2  */
  YYSYMBOL_REG_S3 = 88,                    /* REG_S3  */
  YYSYMBOL_REG_S4 = 89,                    /* REG_S4  */
  YYSYMBOL_REG_S5 = 90,                    /* REG_S5  */
  YYSYMBOL_REG_S6 = 91,                    /* REG_S6  */
  YYSYMBOL_REG_S7 = 92,                    /* REG_S7  */
  YYSYMBOL_REG_S8 = 93,                    /* REG_S8  */
  YYSYMBOL_REG_S9 = 94,                    /* REG_S9  */
  YYSYMBOL_REG_S10 = 95,                   /* REG_S10  */
  YYSYMBOL_REG_S11 = 96,                   /* REG_S11  */
  YYSYMBOL_YYACCEPT = 97,                  /* $accept  */
  YYSYMBOL_asm_file = 98,                  /* asm_file  */
  YYSYMBOL_line_end = 99,                  /* line_end  */
  YYSYMBOL_asm_line = 100,                 /* asm_line  */
  YYSYMBOL_modifier = 101,                 /* modifier  */
  YYSYMBOL_params = 102,                   /* params  */
  YYSYMBOL_param_1 = 103,                  /* param_1  */
  YYSYMBOL_param_2 = 104,                  /* param_2  */
  YYSYMBOL_param_3 = 105,                  /* param_3  */
  YYSYMBOL_label = 106,                    /* label  */
  YYSYMBOL_expr = 107,                     /* expr  */
  YYSYMBOL_csv_identifier_list = 108,      /* csv_identifier_list  */
  YYSYMBOL_csv_numeric_list = 109,         /* csv_numeric_list  */
  YYSYMBOL_assembler_instruction = 110,    /* assembler_instruction  */
  YYSYMBOL_mnemonic = 111,                 /* mnemonic  */
  YYSYMBOL_register = 112                  /* register  */
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
#define YYFINAL  113
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   351


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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    86,    88,    90,    92,    94,    97,   110,
     120,   132,   141,   150,   162,   178,   183,   189,   192,   195,
     198,   201,   204,   209,   216,   223,   231,   239,   245,   252,
     259,   267,   275,   281,   288,   295,   305,   315,   322,   327,
     337,   363,   368,   388,   403,   405,   408,   413,   419,   431,
     442,   453,   464,   475,   483,   491,   502,   511,   520,   529,
     538,   547,   556,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649
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
  "\"end of file\"", "error", "\"invalid token\"", "DOT_EQU",
  "DOT_SECTION", "DOT_GLOBL", "DOT_GLOBAL", "DOT_TEXT", "DOT_DATA",
  "DOT_BYTE", "DOT_HALF", "DOT_WORD", "DOT_DWORD", "DOT_FILE",
  "DOT_RODATA", "DOT_ASCIZ", "DOT_SKIP", "DOT_STRING", "ADD", "ADDI",
  "AND", "ANDI", "AUIPC", "BEQ", "BEQZ", "BGE", "BLT", "BGT", "BNE",
  "BNEZ", "CALL", "J", "JR", "JALR", "LD", "LW", "LH", "LB", "LBU", "LI",
  "LUI", "MUL", "MV", "NOP", "NOT", "RET", "SRLI", "SLLI", "SD", "SW",
  "SH", "SB", "WFI", "NEW_LINE", "MODIFIER_HI", "MODIFIER_LO", "NUMERIC",
  "IDENTIFIER", "STRING_LITERAL", "DOT", "COLON", "COMMA",
  "OPENING_BRACKET", "CLOSING_BRACKET", "REG_ZERO", "REG_RA", "REG_SP",
  "REG_GP", "REG_TP", "REG_T0", "REG_T1", "REG_T2", "REG_T3", "REG_T4",
  "REG_T5", "REG_T6", "REG_FP", "REG_A0", "REG_A1", "REG_A2", "REG_A3",
  "REG_A4", "REG_A5", "REG_A6", "REG_A7", "REG_S0", "REG_S1", "REG_S2",
  "REG_S3", "REG_S4", "REG_S5", "REG_S6", "REG_S7", "REG_S8", "REG_S9",
  "REG_S10", "REG_S11", "$accept", "asm_file", "line_end", "asm_line",
  "modifier", "params", "param_1", "param_2", "param_3", "label", "expr",
  "csv_identifier_list", "csv_numeric_list", "assembler_instruction",
  "mnemonic", "register", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -38,    99,     3,     3,   -48,   -48,    13,   245,   245,
     245,   245,   245,   245,     1,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,    10,    11,    72,     5,    54,   162,   -48,     9,    48,
     -48,   -48,    49,   -48,   -48,   -48,    50,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,     5,   -48,     9,    52,    53,
      55,    57,    58,   -48,    51,   -48,   245,     3,    60,   -48,
     -48,   245,   245,   245,   245,   245,   161,   -48,   -48,   -48,
      59,    68,    69,    70,    71,    73,    74,    75,    77,   -48,
     -48,   -48,   -48,   -48,   -48,   245,   245,   245,   204,    76,
      78,    79,    81,    82,    83,    85,   -48,   -48,   -48,   -48,
     245,   245,   245,   -48,    88,    89,    90,   -48,   -48,   -48
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    71,    73,    72,    70,    74,    75,    76,    77,
      78,    84,    83,    81,    79,    80,    82,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       7,     0,     0,     0,     3,     6,    14,    12,    11,     0,
      49,    50,    44,    51,    52,    46,    55,    40,    42,    43,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    56,    41,    57,    58,    59,    60,    61,
      62,    39,    38,     1,     2,     5,    13,    10,     0,     0,
      40,    42,    26,     9,    22,    27,     0,     0,     0,     4,
       8,     0,     0,     0,     0,     0,    21,    48,    45,    47,
       0,     0,     0,     0,     0,    40,    42,    31,    20,    32,
      15,    16,    24,    23,    25,     0,     0,     0,    19,     0,
       0,     0,    40,    42,    36,    17,    37,    29,    28,    30,
       0,     0,     0,    18,     0,     0,     0,    34,    33,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -47,    66,   -48,   -28,    23,   -48,   -48,   -48,   -48,
      -8,     2,   -48,    98,   100,   -48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    53,    54,    55,   122,   123,   124,   148,   165,    56,
     125,    63,    66,    57,    58,   104
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     103,   105,   106,   107,   108,   109,    64,   114,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    59,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,   110,
      62,    51,    52,   118,   119,   120,   121,    69,   129,    65,
     111,   112,   113,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    60,    50,   147,   126,
     127,   128,   136,    61,   131,   132,   139,   133,   137,   134,
     135,   115,   150,   140,   141,   142,   143,   144,   149,   138,
     164,   151,   152,   153,   154,   155,   156,   157,   158,   167,
     130,   168,   169,   170,   171,   172,   173,   159,   160,   161,
     166,   177,   178,   179,   116,     0,   117,     0,     0,     0,
       0,     0,   174,   175,   176,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,   118,   119,   145,   146,    69,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   118,   119,
     162,   163,    69,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    67,    68,    69,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102
};

static const yytype_int16 yycheck[] =
{
       8,     9,    10,    11,    12,    13,     4,    54,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    57,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    58,
      57,    56,    57,    54,    55,    56,    57,    58,   115,    56,
      60,    60,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     7,    53,   136,    61,
      61,    61,    61,    14,    62,    62,    56,    62,   126,    62,
      62,    55,    63,   131,   132,   133,   134,   135,   136,   127,
     158,    63,    63,    63,    63,    62,    62,    62,    61,    63,
     117,    63,    63,    62,    62,    62,    61,   155,   156,   157,
     158,    63,    63,    63,    56,    -1,    56,    -1,    -1,    -1,
      -1,    -1,   170,   171,   172,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    56,    57,    98,    99,   100,   106,   110,   111,    57,
       7,    14,    57,   108,   108,    56,   109,    56,    57,    58,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,   107,   112,   107,   107,   107,   107,   107,
      58,    60,    60,     0,    98,    99,   110,   111,    54,    55,
      56,    57,   101,   102,   103,   107,    61,    61,    61,    98,
     102,    62,    62,    62,    62,    62,    61,   107,   108,    56,
     107,   107,   107,   107,   107,    56,    57,   101,   104,   107,
      63,    63,    63,    63,    63,    62,    62,    62,    61,   107,
     107,   107,    56,    57,   101,   105,   107,    63,    63,    63,
      62,    62,    62,    61,   107,   107,   107,    63,    63,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    97,    98,    98,    98,    98,    98,    99,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   106,   106,
     107,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     1,     1,     3,     2,
       2,     1,     1,     2,     1,     4,     4,     5,     6,     4,
       3,     2,     1,     4,     4,     4,     1,     1,     4,     4,
       4,     1,     1,     4,     4,     4,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     3,     1,     3,     4,     2,
       2,     2,     2,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 97 "parser.y"
                          {
        //printf("label mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno -1);

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, (yyvsp[-2].string_val), strlen((yyvsp[-2].string_val)));

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1510 "parser.c"
    break;

  case 9: /* asm_line: mnemonic params  */
#line 110 "parser.y"
                        {
        //printf("mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno -1);

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1524 "parser.c"
    break;

  case 10: /* asm_line: label mnemonic  */
#line 120 "parser.y"
                       {
        //printf("label mnemonic\n");
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno - 1);

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, (yyvsp[-1].string_val), strlen((yyvsp[-1].string_val)));

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1540 "parser.c"
    break;

  case 11: /* asm_line: mnemonic  */
#line 132 "parser.y"
                 {
        //printf("mnemonic\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1553 "parser.c"
    break;

  case 12: /* asm_line: assembler_instruction  */
#line 141 "parser.y"
                          {
        printf("assembler_instruction without label\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1566 "parser.c"
    break;

  case 13: /* asm_line: label assembler_instruction  */
#line 150 "parser.y"
                                {
        printf("assembler_instruction with label\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, (yyvsp[-1].string_val), strlen((yyvsp[-1].string_val)));

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
#line 1582 "parser.c"
    break;

  case 14: /* asm_line: label  */
#line 162 "parser.y"
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
#line 1601 "parser.c"
    break;

  case 15: /* modifier: MODIFIER_HI OPENING_BRACKET expr CLOSING_BRACKET  */
#line 178 "parser.y"
                                                     {
        /*printf("MODIFIER_HI\n");*/
        strncpy((yyval.string_val), "HI", 2);
    }
#line 1610 "parser.c"
    break;

  case 16: /* modifier: MODIFIER_LO OPENING_BRACKET expr CLOSING_BRACKET  */
#line 183 "parser.y"
                                                     {
        /*printf("MODIFIER_LO\n");*/
        strncpy((yyval.string_val), "LO", 2);
    }
#line 1619 "parser.c"
    break;

  case 17: /* params: param_1 COMMA param_2 COMMA param_3  */
#line 189 "parser.y"
                                             {
        //printf("param_1 COMMA param_2 COMMA param_3\n");
    }
#line 1627 "parser.c"
    break;

  case 18: /* params: param_1 COMMA param_2 COMMA param_3 COMMA  */
#line 192 "parser.y"
                                                {
        //printf("param_1 COMMA param_2 COMMA param_3\n");
    }
#line 1635 "parser.c"
    break;

  case 19: /* params: param_1 COMMA param_2 COMMA  */
#line 195 "parser.y"
                                  {
        //printf("param_1 COMMA param_2\n");
    }
#line 1643 "parser.c"
    break;

  case 20: /* params: param_1 COMMA param_2  */
#line 198 "parser.y"
                            {
        //printf("param_1 COMMA param_2\n");
    }
#line 1651 "parser.c"
    break;

  case 21: /* params: param_1 COMMA  */
#line 201 "parser.y"
                    {
        //printf("param_1\n");
    }
#line 1659 "parser.c"
    break;

  case 22: /* params: param_1  */
#line 204 "parser.y"
              {
        //printf("param_1\n");
    }
#line 1667 "parser.c"
    break;

  case 23: /* param_1: IDENTIFIER OPENING_BRACKET expr CLOSING_BRACKET  */
#line 209 "parser.y"
                                                    {
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-3].string_val), 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1678 "parser.c"
    break;

  case 24: /* param_1: NUMERIC OPENING_BRACKET expr CLOSING_BRACKET  */
#line 216 "parser.y"
                                                 {
        insert_offset(&parser_asm_line, (yyvsp[-2].sym), 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1689 "parser.c"
    break;

  case 25: /* param_1: modifier OPENING_BRACKET expr CLOSING_BRACKET  */
#line 223 "parser.y"
                                                  {
        printf("modifier 1: '%s' \n", (char *) (yyvsp[-3].string_val));
        insert_modifier(&parser_asm_line, (char *)(yyvsp[-3].string_val), 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1701 "parser.c"
    break;

  case 26: /* param_1: modifier  */
#line 231 "parser.y"
             {
        printf("modifier 1: '%s' \n", (char *) (yyvsp[0].string_val));
        insert_modifier(&parser_asm_line, (char *)(yyvsp[0].string_val), 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1713 "parser.c"
    break;

  case 27: /* param_1: expr  */
#line 239 "parser.y"
         {
        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
#line 1722 "parser.c"
    break;

  case 28: /* param_2: IDENTIFIER OPENING_BRACKET expr CLOSING_BRACKET  */
#line 245 "parser.y"
                                                    {
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-3].string_val), 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1733 "parser.c"
    break;

  case 29: /* param_2: NUMERIC OPENING_BRACKET expr CLOSING_BRACKET  */
#line 252 "parser.y"
                                                 {
        insert_offset(&parser_asm_line, (yyvsp[-2].sym), 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1744 "parser.c"
    break;

  case 30: /* param_2: modifier OPENING_BRACKET expr CLOSING_BRACKET  */
#line 259 "parser.y"
                                                  {
        //printf("modifier 2: '%s' \n", (char *) $1);
        insert_modifier(&parser_asm_line, (char *)(yyvsp[-3].string_val), 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1756 "parser.c"
    break;

  case 31: /* param_2: modifier  */
#line 267 "parser.y"
             {
        //printf("modifier 2: '%s' \n", (char *) $1);
        insert_modifier(&parser_asm_line, (char *)(yyvsp[0].string_val), 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1768 "parser.c"
    break;

  case 32: /* param_2: expr  */
#line 275 "parser.y"
         {
        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
#line 1777 "parser.c"
    break;

  case 33: /* param_3: IDENTIFIER OPENING_BRACKET expr CLOSING_BRACKET  */
#line 281 "parser.y"
                                                    {
        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[-3].string_val), 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1788 "parser.c"
    break;

  case 34: /* param_3: NUMERIC OPENING_BRACKET expr CLOSING_BRACKET  */
#line 288 "parser.y"
                                                 {
        insert_offset(&parser_asm_line, (yyvsp[-2].sym), 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1799 "parser.c"
    break;

  case 35: /* param_3: modifier OPENING_BRACKET expr CLOSING_BRACKET  */
#line 295 "parser.y"
                                                  {
        //printf("modifier 3: '%s' \n", (char *) $1);


        insert_modifier(&parser_asm_line, (char *)(yyvsp[-3].string_val), 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1813 "parser.c"
    break;

  case 36: /* param_3: modifier  */
#line 305 "parser.y"
             {
        //printf("modifier 3: '%s' \n", (char *) $1);


        insert_modifier(&parser_asm_line, (char *)(yyvsp[0].string_val), 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1827 "parser.c"
    break;

  case 37: /* param_3: expr  */
#line 315 "parser.y"
         {
        //printf("expr 3\n");
        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
#line 1837 "parser.c"
    break;

  case 38: /* label: IDENTIFIER COLON  */
#line 322 "parser.y"
                     {
        //printf("label A detected!\n");
        strncpy((yyval.string_val), (yyvsp[-1].string_val), 100);
    }
#line 1846 "parser.c"
    break;

  case 39: /* label: NUMERIC COLON  */
#line 327 "parser.y"
                  {
        //printf("label B detected!\n");
        char buffer[100];
        memset(buffer, 0, 100);
        snprintf(buffer, 100, "%d", (yyvsp[-1].int_val));
        strncpy((yyval.string_val), buffer, 100);
    }
#line 1858 "parser.c"
    break;

  case 40: /* expr: NUMERIC  */
#line 337 "parser.y"
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
#line 1888 "parser.c"
    break;

  case 41: /* expr: register  */
#line 363 "parser.y"
             {
        //printf("expr - register\n");
        (yyval.expr_ptr) = current_node;
    }
#line 1897 "parser.c"
    break;

  case 42: /* expr: IDENTIFIER  */
#line 368 "parser.y"
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
#line 1921 "parser.c"
    break;

  case 43: /* expr: STRING_LITERAL  */
#line 388 "parser.y"
                   {
        if (current_node == NULL) {

            current_node = (node_t *)malloc(sizeof(node_t));

            reset_node(current_node);

            memset(current_node->string_val, 0, 100);
            memcpy(current_node->string_val, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

            (yyval.expr_ptr) = current_node;
        }
    }
#line 1939 "parser.c"
    break;

  case 46: /* csv_numeric_list: NUMERIC  */
#line 409 "parser.y"
    {
        insert_numeric_list_raw_data(&parser_asm_line, (yyvsp[0].int_val));
    }
#line 1947 "parser.c"
    break;

  case 47: /* csv_numeric_list: csv_numeric_list COMMA NUMERIC  */
#line 414 "parser.y"
    {
        insert_numeric_list_raw_data(&parser_asm_line, (yyvsp[0].int_val));
    }
#line 1955 "parser.c"
    break;

  case 48: /* assembler_instruction: DOT_EQU IDENTIFIER COMMA expr  */
#line 419 "parser.y"
                                  {

        parser_asm_line.asm_instruction = AI_EQU;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[-2].string_val), strlen((yyvsp[-2].string_val)));

        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);
        current_node = NULL;

    }
#line 1971 "parser.c"
    break;

  case 49: /* assembler_instruction: DOT_SECTION DOT_TEXT  */
#line 431 "parser.y"
                         {

        parser_asm_line.asm_instruction = AI_SECTION;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, ".text", strlen(".text"));

        current_node = NULL;

    }
#line 1986 "parser.c"
    break;

  case 50: /* assembler_instruction: DOT_SECTION DOT_RODATA  */
#line 442 "parser.y"
                           {

        parser_asm_line.asm_instruction = AI_SECTION;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, ".rodata", strlen(".rodata"));

        current_node = NULL;

    }
#line 2001 "parser.c"
    break;

  case 51: /* assembler_instruction: DOT_GLOBL csv_identifier_list  */
#line 453 "parser.y"
                                  {

        parser_asm_line.asm_instruction = AI_GLOBL;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        current_node = NULL;

    }
#line 2016 "parser.c"
    break;

  case 52: /* assembler_instruction: DOT_GLOBAL csv_identifier_list  */
#line 464 "parser.y"
                                   {

        parser_asm_line.asm_instruction = AI_GLOBL;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, (yyvsp[0].string_val), strlen((yyvsp[0].string_val)));

        current_node = NULL;

    }
#line 2031 "parser.c"
    break;

  case 53: /* assembler_instruction: DOT_TEXT  */
#line 475 "parser.y"
             {

        parser_asm_line.asm_instruction = AI_TEXT;

        current_node = NULL;

    }
#line 2043 "parser.c"
    break;

  case 54: /* assembler_instruction: DOT_DATA  */
#line 483 "parser.y"
             {

        parser_asm_line.asm_instruction = AI_DATA;

        current_node = NULL;

    }
#line 2055 "parser.c"
    break;

  case 55: /* assembler_instruction: DOT_BYTE csv_numeric_list  */
#line 491 "parser.y"
                              {

        parser_asm_line.asm_instruction = AI_BYTE;

        insert_numeric_list_end_raw_data(&parser_asm_line, (yyvsp[0].int_val));
        //parser_asm_line.asm_instruction_expr = $2;

        //current_node = NULL;

    }
#line 2070 "parser.c"
    break;

  case 56: /* assembler_instruction: DOT_HALF expr  */
#line 502 "parser.y"
                  {

        parser_asm_line.asm_instruction = AI_HALF;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 2083 "parser.c"
    break;

  case 57: /* assembler_instruction: DOT_WORD expr  */
#line 511 "parser.y"
                  {

        parser_asm_line.asm_instruction = AI_WORD;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 2096 "parser.c"
    break;

  case 58: /* assembler_instruction: DOT_DWORD expr  */
#line 520 "parser.y"
                   {

        parser_asm_line.asm_instruction = AI_DWORD;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 2109 "parser.c"
    break;

  case 59: /* assembler_instruction: DOT_FILE expr  */
#line 529 "parser.y"
                  {

        parser_asm_line.asm_instruction = AI_FILE;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 2122 "parser.c"
    break;

  case 60: /* assembler_instruction: DOT_ASCIZ expr  */
#line 538 "parser.y"
                   {

        parser_asm_line.asm_instruction = AI_ASCIZ;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 2135 "parser.c"
    break;

  case 61: /* assembler_instruction: DOT_SKIP expr  */
#line 547 "parser.y"
                  {

        parser_asm_line.asm_instruction = AI_SKIP;
        parser_asm_line.asm_instruction_expr = (yyvsp[0].expr_ptr);

        current_node = NULL;

    }
#line 2148 "parser.c"
    break;

  case 62: /* assembler_instruction: DOT_STRING STRING_LITERAL  */
#line 556 "parser.y"
                              {

        printf("DOT_STRING STRING_LITERAL %s, %d \n\n", __FILE__, __LINE__);

        parser_asm_line.asm_instruction = AI_STRING;
        //parser_asm_line.asm_instruction_expr = $2;

        insert_identifier_offset(&parser_asm_line, (char *)(yyvsp[0].string_val), 0);

        // if (current_node == NULL) {

        //     current_node = (node_t *)malloc(sizeof(node_t));

        //     reset_node(current_node);

        //     parser_asm_line.asm_instruction_expr = current_node;

        //     memset(parser_asm_line.asm_instruction_expr->string_val, 0, 100);
        //     memcpy(parser_asm_line.asm_instruction_expr->string_val, $2, strlen($2));
        // }

        current_node = NULL;

    }
#line 2177 "parser.c"
    break;

  case 63: /* mnemonic: ADD  */
#line 581 "parser.y"
               { /*printf("Parser-ADD: %d\n", I_ADD);*/ /*parser_asm_line.instruction = I_ADD; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_ADD, IT_R); }
#line 2183 "parser.c"
    break;

  case 64: /* mnemonic: ADDI  */
#line 582 "parser.y"
           { /*printf("Parser-ADDI: %d\n", I_ADDI);*/ /*parser_asm_line.instruction = I_ADDI; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_ADDI, IT_R); }
#line 2189 "parser.c"
    break;

  case 65: /* mnemonic: AND  */
#line 583 "parser.y"
          { set_instruction(&parser_asm_line, I_AND, IT_R); }
#line 2195 "parser.c"
    break;

  case 66: /* mnemonic: ANDI  */
#line 584 "parser.y"
           { set_instruction(&parser_asm_line, I_ANDI, IT_I); }
#line 2201 "parser.c"
    break;

  case 67: /* mnemonic: AUIPC  */
#line 585 "parser.y"
            { /*printf("Parser-AUIPC: %d\n", I_AUIPC);*/ /*parser_asm_line.instruction = I_AUIPC; parser_asm_line.instruction_type = IT_U;*/ set_instruction(&parser_asm_line, I_AUIPC, IT_U); }
#line 2207 "parser.c"
    break;

  case 68: /* mnemonic: BEQ  */
#line 586 "parser.y"
          { /*printf("Parser-BEQ: %d\n", I_BEQ);*/ /*parser_asm_line.instruction = I_BEQ; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BEQ, IT_B); }
#line 2213 "parser.c"
    break;

  case 69: /* mnemonic: BEQZ  */
#line 587 "parser.y"
           { /*printf("Parser-BEQZ: %d\n", I_BEQZ);*/ /*parser_asm_line.instruction = I_BEQZ; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_BEQZ, IT_P); }
#line 2219 "parser.c"
    break;

  case 70: /* mnemonic: BNE  */
#line 588 "parser.y"
          { /*printf("Parser-BNE: %d\n", I_BNE);*/ /*parser_asm_line.instruction = I_BNE; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BNE, IT_B); }
#line 2225 "parser.c"
    break;

  case 71: /* mnemonic: BGE  */
#line 589 "parser.y"
          { /*printf("Parser-BGE: %d\n", I_BGE);*/ /*parser_asm_line.instruction = I_BGE; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BGE, IT_B); }
#line 2231 "parser.c"
    break;

  case 72: /* mnemonic: BGT  */
#line 590 "parser.y"
          { /*printf("Parser-BGT: %d\n", I_BGT);*/ /*parser_asm_line.instruction = I_BGT; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BGT, IT_B); }
#line 2237 "parser.c"
    break;

  case 73: /* mnemonic: BLT  */
#line 591 "parser.y"
          { /*printf("Parser-BLT: %d\n", I_BLT);*/ /*parser_asm_line.instruction = I_BLT; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BLT, IT_B); }
#line 2243 "parser.c"
    break;

  case 74: /* mnemonic: BNEZ  */
#line 592 "parser.y"
           { /*printf("Parser-BNEZ: %d\n", I_BNEZ);*/ /*parser_asm_line.instruction = I_BNEZ; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_BNEZ, IT_P); }
#line 2249 "parser.c"
    break;

  case 75: /* mnemonic: CALL  */
#line 593 "parser.y"
           { /*printf("Parser-CALL: %d\n", I_CALL);*/ /*parser_asm_line.instruction = I_CALL; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_CALL, IT_P); }
#line 2255 "parser.c"
    break;

  case 76: /* mnemonic: J  */
#line 594 "parser.y"
        { /*printf("Parser-J: %d\n", I_J);*/ /*parser_asm_line.instruction = I_J; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_J, IT_P); }
#line 2261 "parser.c"
    break;

  case 77: /* mnemonic: JR  */
#line 595 "parser.y"
         { /*printf("Parser-JR: %d\n", I_JR);*/ /*parser_asm_line.instruction = I_JR; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_JR, IT_P); }
#line 2267 "parser.c"
    break;

  case 78: /* mnemonic: JALR  */
#line 596 "parser.y"
           { /*printf("Parser-JALR: %d\n", I_JALR);*/ /*parser_asm_line.instruction = I_JALR; parser_asm_line.instruction_type = IT_J;*/ set_instruction(&parser_asm_line, I_JALR, IT_J); }
#line 2273 "parser.c"
    break;

  case 79: /* mnemonic: LB  */
#line 597 "parser.y"
         { /*printf("Parser-LB: %d\n", I_LB);*/ /*parser_asm_line.instruction = I_LB; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LB, IT_I); }
#line 2279 "parser.c"
    break;

  case 80: /* mnemonic: LBU  */
#line 598 "parser.y"
          { set_instruction(&parser_asm_line, I_LBU, IT_I); }
#line 2285 "parser.c"
    break;

  case 81: /* mnemonic: LH  */
#line 599 "parser.y"
         { /*printf("Parser-LH: %d\n", I_LH);*/ /*parser_asm_line.instruction = I_LH; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LH, IT_I); }
#line 2291 "parser.c"
    break;

  case 82: /* mnemonic: LI  */
#line 600 "parser.y"
         { /*printf("Parser-LI: %d\n", I_LI);*/ /*parser_asm_line.instruction = I_LI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LI, IT_P); }
#line 2297 "parser.c"
    break;

  case 83: /* mnemonic: LW  */
#line 601 "parser.y"
         { /*printf("Parser-LW: %d\n", I_LW);*/ /*parser_asm_line.instruction = I_LW; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LW, IT_I); }
#line 2303 "parser.c"
    break;

  case 84: /* mnemonic: LD  */
#line 602 "parser.y"
         { /*printf("Parser-LD: %d\n", I_LD);*/ /*parser_asm_line.instruction = I_LD; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LD, IT_I); }
#line 2309 "parser.c"
    break;

  case 85: /* mnemonic: LUI  */
#line 603 "parser.y"
          { /*printf("Parser-LUI: %d\n", I_LUI);*/ /*parser_asm_line.instruction = I_LUI; parser_asm_line.instruction_type = IT_U;*/ set_instruction(&parser_asm_line, I_LUI, IT_U); }
#line 2315 "parser.c"
    break;

  case 86: /* mnemonic: MUL  */
#line 604 "parser.y"
          { /*printf("Parser-LW: %d\n", I_MUL);*/ /*parser_asm_line.instruction = I_MUL; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_MUL, IT_R); }
#line 2321 "parser.c"
    break;

  case 87: /* mnemonic: MV  */
#line 605 "parser.y"
         { /*printf("Parser-LW: %d\n", I_MV);*/ /*parser_asm_line.instruction = I_MV; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_MV, IT_P); }
#line 2327 "parser.c"
    break;

  case 88: /* mnemonic: NOP  */
#line 606 "parser.y"
          { set_instruction(&parser_asm_line, I_NOP, IT_P); }
#line 2333 "parser.c"
    break;

  case 89: /* mnemonic: NOT  */
#line 607 "parser.y"
          { /*printf("Parser-NOT: %d\n", I_NOT);*/ /*parser_asm_line.instruction = I_NOT; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_NOT, IT_P); }
#line 2339 "parser.c"
    break;

  case 90: /* mnemonic: RET  */
#line 608 "parser.y"
          { /*printf("Parser-RET: %d\n", I_RET);*/ /*parser_asm_line.instruction = I_RET; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_RET, IT_P); }
#line 2345 "parser.c"
    break;

  case 91: /* mnemonic: SRLI  */
#line 609 "parser.y"
           { /*printf("Parser-SRLI: %d\n", I_SRLI);*/ /*parser_asm_line.instruction = I_SRLI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_SRLI, IT_I); }
#line 2351 "parser.c"
    break;

  case 92: /* mnemonic: SLLI  */
#line 610 "parser.y"
           { /*printf("Parser-SLLI: %d\n", I_SLLI);*/ /*parser_asm_line.instruction = I_SLLI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_SLLI, IT_I); }
#line 2357 "parser.c"
    break;

  case 93: /* mnemonic: SD  */
#line 611 "parser.y"
         { /*printf("Parser-SD: %d\n", I_SD);*/ /*parser_asm_line.instruction = I_SD; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SD, IT_S); }
#line 2363 "parser.c"
    break;

  case 94: /* mnemonic: SW  */
#line 612 "parser.y"
         { /*printf("Parser-SW: %d\n", I_SW);*/ /*parser_asm_line.instruction = I_SW; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SW, IT_S); }
#line 2369 "parser.c"
    break;

  case 95: /* mnemonic: SH  */
#line 613 "parser.y"
         { /*printf("Parser-SH: %d\n", I_SH);*/ /*parser_asm_line.instruction = I_SH; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SH, IT_S); }
#line 2375 "parser.c"
    break;

  case 96: /* mnemonic: SB  */
#line 614 "parser.y"
         { /*printf("Parser-SB: %d\n", I_SB);*/ /*parser_asm_line.instruction = I_SB; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SB, IT_S); }
#line 2381 "parser.c"
    break;

  case 97: /* mnemonic: WFI  */
#line 615 "parser.y"
          { set_instruction(&parser_asm_line, I_WFI, IT_SYSTEM); }
#line 2387 "parser.c"
    break;

  case 98: /* register: REG_ZERO  */
#line 617 "parser.y"
                    { /*printf("REG_ZERO\n");*/ insert_register(&parser_asm_line, R_ZERO); }
#line 2393 "parser.c"
    break;

  case 99: /* register: REG_RA  */
#line 618 "parser.y"
             { /*printf("REG_RA\n");*/ insert_register(&parser_asm_line, R_RA); }
#line 2399 "parser.c"
    break;

  case 100: /* register: REG_SP  */
#line 619 "parser.y"
             { /*printf("REG_SP\n");*/ insert_register(&parser_asm_line, R_SP); }
#line 2405 "parser.c"
    break;

  case 101: /* register: REG_GP  */
#line 620 "parser.y"
             { /*printf("REG_GP\n");*/ insert_register(&parser_asm_line, R_GP); }
#line 2411 "parser.c"
    break;

  case 102: /* register: REG_TP  */
#line 621 "parser.y"
             { /*printf("REG_TP\n");*/ insert_register(&parser_asm_line, R_TP); }
#line 2417 "parser.c"
    break;

  case 103: /* register: REG_T0  */
#line 622 "parser.y"
             { /*printf("REG_T0\n");*/ insert_register(&parser_asm_line, R_T0); }
#line 2423 "parser.c"
    break;

  case 104: /* register: REG_T1  */
#line 623 "parser.y"
             { /*printf("REG_T1\n");*/ insert_register(&parser_asm_line, R_T1); }
#line 2429 "parser.c"
    break;

  case 105: /* register: REG_T2  */
#line 624 "parser.y"
             { /*printf("REG_T2\n");*/ insert_register(&parser_asm_line, R_T2); }
#line 2435 "parser.c"
    break;

  case 106: /* register: REG_T3  */
#line 625 "parser.y"
             { /*printf("REG_T3\n");*/ insert_register(&parser_asm_line, R_T3); }
#line 2441 "parser.c"
    break;

  case 107: /* register: REG_T4  */
#line 626 "parser.y"
             { /*printf("REG_T4\n");*/ insert_register(&parser_asm_line, R_T4); }
#line 2447 "parser.c"
    break;

  case 108: /* register: REG_T5  */
#line 627 "parser.y"
             { /*printf("REG_T5\n");*/ insert_register(&parser_asm_line, R_T5); }
#line 2453 "parser.c"
    break;

  case 109: /* register: REG_T6  */
#line 628 "parser.y"
             { /*printf("REG_T6\n");*/ insert_register(&parser_asm_line, R_T6); }
#line 2459 "parser.c"
    break;

  case 110: /* register: REG_FP  */
#line 629 "parser.y"
             { /*printf("REG_FP\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 2465 "parser.c"
    break;

  case 111: /* register: REG_A0  */
#line 630 "parser.y"
             { /*printf("REG_A0\n");*/ insert_register(&parser_asm_line, R_A0); }
#line 2471 "parser.c"
    break;

  case 112: /* register: REG_A1  */
#line 631 "parser.y"
             { /*printf("REG_A1\n");*/ insert_register(&parser_asm_line, R_A1); }
#line 2477 "parser.c"
    break;

  case 113: /* register: REG_A2  */
#line 632 "parser.y"
             { /*printf("REG_A2\n");*/ insert_register(&parser_asm_line, R_A2); }
#line 2483 "parser.c"
    break;

  case 114: /* register: REG_A3  */
#line 633 "parser.y"
             { /*printf("REG_A3\n");*/ insert_register(&parser_asm_line, R_A3); }
#line 2489 "parser.c"
    break;

  case 115: /* register: REG_A4  */
#line 634 "parser.y"
             { /*printf("REG_A4\n");*/ insert_register(&parser_asm_line, R_A4); }
#line 2495 "parser.c"
    break;

  case 116: /* register: REG_A5  */
#line 635 "parser.y"
             { /*printf("REG_A5\n");*/ insert_register(&parser_asm_line, R_A5); }
#line 2501 "parser.c"
    break;

  case 117: /* register: REG_A6  */
#line 636 "parser.y"
             { /*printf("REG_A6\n");*/ insert_register(&parser_asm_line, R_A6); }
#line 2507 "parser.c"
    break;

  case 118: /* register: REG_A7  */
#line 637 "parser.y"
             { /*printf("REG_A7\n");*/ insert_register(&parser_asm_line, R_A7); }
#line 2513 "parser.c"
    break;

  case 119: /* register: REG_S0  */
#line 638 "parser.y"
             { /*printf("REG_S0\n");*/ insert_register(&parser_asm_line, R_S0); }
#line 2519 "parser.c"
    break;

  case 120: /* register: REG_S1  */
#line 639 "parser.y"
             { /*printf("REG_S1\n");*/ insert_register(&parser_asm_line, R_S1); }
#line 2525 "parser.c"
    break;

  case 121: /* register: REG_S2  */
#line 640 "parser.y"
             { /*printf("REG_S2\n");*/ insert_register(&parser_asm_line, R_S2); }
#line 2531 "parser.c"
    break;

  case 122: /* register: REG_S3  */
#line 641 "parser.y"
             { /*printf("REG_S3\n");*/ insert_register(&parser_asm_line, R_S3); }
#line 2537 "parser.c"
    break;

  case 123: /* register: REG_S4  */
#line 642 "parser.y"
             { /*printf("REG_S4\n");*/ insert_register(&parser_asm_line, R_S4); }
#line 2543 "parser.c"
    break;

  case 124: /* register: REG_S5  */
#line 643 "parser.y"
             { /*printf("REG_S5\n");*/ insert_register(&parser_asm_line, R_S5); }
#line 2549 "parser.c"
    break;

  case 125: /* register: REG_S6  */
#line 644 "parser.y"
             { /*printf("REG_S6\n");*/ insert_register(&parser_asm_line, R_S6); }
#line 2555 "parser.c"
    break;

  case 126: /* register: REG_S7  */
#line 645 "parser.y"
             { /*printf("REG_S7\n");*/ insert_register(&parser_asm_line, R_S7); }
#line 2561 "parser.c"
    break;

  case 127: /* register: REG_S8  */
#line 646 "parser.y"
             { /*printf("REG_S8\n");*/ insert_register(&parser_asm_line, R_S8); }
#line 2567 "parser.c"
    break;

  case 128: /* register: REG_S9  */
#line 647 "parser.y"
             { /*printf("REG_S9\n");*/ insert_register(&parser_asm_line, R_S9); }
#line 2573 "parser.c"
    break;

  case 129: /* register: REG_S10  */
#line 648 "parser.y"
              { /*printf("REG_S10\n");*/ insert_register(&parser_asm_line, R_S10); }
#line 2579 "parser.c"
    break;

  case 130: /* register: REG_S11  */
#line 649 "parser.y"
              { /*printf("REG_S11\n");*/ insert_register(&parser_asm_line, R_S11); }
#line 2585 "parser.c"
    break;


#line 2589 "parser.c"

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

#line 673 "parser.y"


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
