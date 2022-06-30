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
#line 1 "l22_parser.y"

//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#line 85 "l22_parser.tab.c"

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

#include "l22_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tINTEGER = 3,                   /* tINTEGER  */
  YYSYMBOL_tIDENTIFIER = 4,                /* tIDENTIFIER  */
  YYSYMBOL_tSTRING = 5,                    /* tSTRING  */
  YYSYMBOL_tREAL = 6,                      /* tREAL  */
  YYSYMBOL_tWHILE = 7,                     /* tWHILE  */
  YYSYMBOL_tIF = 8,                        /* tIF  */
  YYSYMBOL_tWRITE = 9,                     /* tWRITE  */
  YYSYMBOL_tINPUT = 10,                    /* tINPUT  */
  YYSYMBOL_tBEGIN = 11,                    /* tBEGIN  */
  YYSYMBOL_tEND = 12,                      /* tEND  */
  YYSYMBOL_tAT = 13,                       /* tAT  */
  YYSYMBOL_tWRITELN = 14,                  /* tWRITELN  */
  YYSYMBOL_tELIF = 15,                     /* tELIF  */
  YYSYMBOL_tAND = 16,                      /* tAND  */
  YYSYMBOL_tOR = 17,                       /* tOR  */
  YYSYMBOL_tNOT = 18,                      /* tNOT  */
  YYSYMBOL_tINT = 19,                      /* tINT  */
  YYSYMBOL_tDOUBLE = 20,                   /* tDOUBLE  */
  YYSYMBOL_tTEXT = 21,                     /* tTEXT  */
  YYSYMBOL_tAGAIN = 22,                    /* tAGAIN  */
  YYSYMBOL_tRETURN = 23,                   /* tRETURN  */
  YYSYMBOL_tSIZEOF = 24,                   /* tSIZEOF  */
  YYSYMBOL_tPUBLIC = 25,                   /* tPUBLIC  */
  YYSYMBOL_tFOREIGN = 26,                  /* tFOREIGN  */
  YYSYMBOL_tVAR = 27,                      /* tVAR  */
  YYSYMBOL_tVOID = 28,                     /* tVOID  */
  YYSYMBOL_tTHEN = 29,                     /* tTHEN  */
  YYSYMBOL_tDO = 30,                       /* tDO  */
  YYSYMBOL_tUSE = 31,                      /* tUSE  */
  YYSYMBOL_tSTOP = 32,                     /* tSTOP  */
  YYSYMBOL_tPRIVATE = 33,                  /* tPRIVATE  */
  YYSYMBOL_tARROW = 34,                    /* tARROW  */
  YYSYMBOL_tNULL = 35,                     /* tNULL  */
  YYSYMBOL_tELSE = 36,                     /* tELSE  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_tEQ = 38,                       /* tEQ  */
  YYSYMBOL_tNE = 39,                       /* tNE  */
  YYSYMBOL_40_ = 40,                       /* '>'  */
  YYSYMBOL_41_ = 41,                       /* '<'  */
  YYSYMBOL_tGE = 42,                       /* tGE  */
  YYSYMBOL_tLE = 43,                       /* tLE  */
  YYSYMBOL_44_ = 44,                       /* '+'  */
  YYSYMBOL_45_ = 45,                       /* '-'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_48_ = 48,                       /* '%'  */
  YYSYMBOL_tUNARY = 49,                    /* tUNARY  */
  YYSYMBOL_50_ = 50,                       /* '?'  */
  YYSYMBOL_51_ = 51,                       /* '['  */
  YYSYMBOL_52_ = 52,                       /* ']'  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* ';'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_ = 59,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_file = 61,                      /* file  */
  YYSYMBOL_declarations = 62,              /* declarations  */
  YYSYMBOL_declaration = 63,               /* declaration  */
  YYSYMBOL_vardecl = 64,                   /* vardecl  */
  YYSYMBOL_data_type = 65,                 /* data_type  */
  YYSYMBOL_func_type = 66,                 /* func_type  */
  YYSYMBOL_return_type = 67,               /* return_type  */
  YYSYMBOL_data_types = 68,                /* data_types  */
  YYSYMBOL_program = 69,                   /* program  */
  YYSYMBOL_block = 70,                     /* block  */
  YYSYMBOL_innerdecls = 71,                /* innerdecls  */
  YYSYMBOL_instructions = 72,              /* instructions  */
  YYSYMBOL_instruction = 73,               /* instruction  */
  YYSYMBOL_cond_instruction = 74,          /* cond_instruction  */
  YYSYMBOL_it_instruction = 75,            /* it_instruction  */
  YYSYMBOL_elif = 76,                      /* elif  */
  YYSYMBOL_expressions = 77,               /* expressions  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_fundef = 79,                    /* fundef  */
  YYSYMBOL_func_cal = 80,                  /* func_cal  */
  YYSYMBOL_argdecs = 81,                   /* argdecs  */
  YYSYMBOL_argdec = 82,                    /* argdec  */
  YYSYMBOL_lval = 83,                      /* lval  */
  YYSYMBOL_integer = 84,                   /* integer  */
  YYSYMBOL_real = 85,                      /* real  */
  YYSYMBOL_string = 86                     /* string  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 75 "l22_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 209 "l22_parser.tab.c"


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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   700

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
       2,     2,     2,     2,     2,     2,     2,    48,     2,     2,
      53,    54,    46,    44,    56,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    55,
      41,    37,    40,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      35,    36,    38,    39,    42,    43,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    80,    80,    81,    82,    83,    86,    87,    90,    91,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   105,
     106,   107,   108,   109,   112,   113,   116,   117,   120,   121,
     124,   128,   129,   130,   131,   132,   135,   136,   140,   141,
     142,   143,   144,   145,   146,   149,   150,   151,   152,   153,
     154,   155,   158,   159,   162,   166,   167,   168,   171,   172,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   206,
     207,   210,   211,   212,   213,   214,   215,   218,   219,   222,
     225,   226,   229,   230,   231,   232
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
  "\"end of file\"", "error", "\"invalid token\"", "tINTEGER",
  "tIDENTIFIER", "tSTRING", "tREAL", "tWHILE", "tIF", "tWRITE", "tINPUT",
  "tBEGIN", "tEND", "tAT", "tWRITELN", "tELIF", "tAND", "tOR", "tNOT",
  "tINT", "tDOUBLE", "tTEXT", "tAGAIN", "tRETURN", "tSIZEOF", "tPUBLIC",
  "tFOREIGN", "tVAR", "tVOID", "tTHEN", "tDO", "tUSE", "tSTOP", "tPRIVATE",
  "tARROW", "tNULL", "tELSE", "'='", "tEQ", "tNE", "'>'", "'<'", "tGE",
  "tLE", "'+'", "'-'", "'*'", "'/'", "'%'", "tUNARY", "'?'", "'['", "']'",
  "'('", "')'", "';'", "','", "'{'", "'}'", "':'", "$accept", "file",
  "declarations", "declaration", "vardecl", "data_type", "func_type",
  "return_type", "data_types", "program", "block", "innerdecls",
  "instructions", "instruction", "cond_instruction", "it_instruction",
  "elif", "expressions", "expression", "fundef", "func_cal", "argdecs",
  "argdec", "lval", "integer", "real", "string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-138)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-29)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     482,   -44,  -138,  -138,  -138,   142,   217,    14,  -138,   217,
     217,    20,   482,  -138,   -23,    33,  -138,    29,  -138,   197,
      28,    50,    51,    85,    89,    57,    91,    44,  -138,  -138,
    -138,  -138,    61,   138,  -138,  -138,  -138,  -138,    47,    56,
      18,  -138,    62,    18,    18,  -138,    18,    75,  -138,  -138,
      18,    18,   471,   363,  -138,  -138,  -138,    98,    73,   253,
     308,   308,   623,  -138,  -138,    60,  -138,  -138,   109,  -138,
      18,    95,    97,  -138,    18,  -138,  -138,    18,  -138,   -29,
     104,    18,    18,    18,    79,   623,   391,    79,   637,   623,
      18,    86,    86,   590,   111,   134,   501,   -21,  -138,   308,
    -138,  -138,    90,  -138,   308,  -138,  -138,  -138,    18,    18,
      18,    18,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,  -138,   415,  -138,   623,    18,    18,   623,
     623,   217,  -138,   518,   537,    18,  -138,     2,   554,  -138,
     217,  -138,    94,   116,   217,    96,  -138,  -138,   637,   637,
     649,   649,   235,   235,   235,   235,    13,    13,    86,    86,
      86,   606,   623,  -138,    11,   623,   623,  -138,   122,   135,
     623,  -138,  -138,  -138,   -16,   443,   217,  -138,  -138,  -138,
    -138,   -44,   -44,   -44,  -138,    12,   -15,  -138,    15,  -138,
    -138,   -44,   112,   -44,  -138,  -138,    18,  -138,   573,   139,
     -44,    15,  -138
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    20,    21,    19,     0,     0,     0,    27,     0,
       0,     0,     3,     6,     9,    26,    23,     0,     4,     0,
       0,     0,     0,    26,    26,     0,    26,    26,     1,     7,
       5,     8,    14,     0,   102,   100,   104,   103,     0,     0,
       0,    85,     0,     0,     0,    48,     0,     0,    49,    63,
       0,     0,     0,     0,    32,    36,    51,     0,     0,    38,
      39,    40,    45,    64,    65,    66,    60,    61,    62,    30,
       0,     0,    11,    18,     0,    12,    22,     0,    25,    26,
       0,     0,     0,     0,    46,    58,     0,    47,    84,    50,
       0,    83,    82,     0,     0,    26,     0,     0,    97,     0,
      33,    37,     0,    31,     0,    42,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,     0,   105,    16,     0,     0,    17,
      13,     0,    24,     0,     0,     0,    94,     0,     0,    88,
       0,    99,    87,     0,     0,     0,    34,    41,    80,    81,
      79,    78,    75,    74,    76,    77,    69,    70,    71,    72,
      73,     0,    67,    92,     0,    15,    10,    29,     0,     0,
      59,    93,    86,    26,     0,     0,     0,    98,    35,   101,
      91,     0,     0,     0,    96,     0,     0,    54,    52,    90,
      95,     0,     0,     0,    53,    89,     0,    55,     0,     0,
       0,    56,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,     0,  -138,    -4,  -138,  -137,    36,   159,
      -1,  -138,   127,  -138,  -138,  -138,   -28,   -34,   -36,  -138,
    -138,  -138,    30,  -138,  -138,  -138,  -138
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    17,    80,    18,
      56,    57,    58,    59,    60,    61,   194,    84,    62,    63,
      64,    97,    98,    65,    66,    67,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    23,    24,   174,    85,    26,    27,    85,    88,    87,
      89,   -28,    29,    19,    91,    92,    93,    96,    25,    55,
      28,    34,    35,    36,    37,    33,    33,   131,    41,    79,
     192,    42,    31,   143,   126,   144,    44,    32,   129,   186,
      69,   130,    47,   183,   191,   133,   134,    93,    27,    95,
      85,   193,   137,    49,   138,    71,   171,   101,   135,   118,
     119,   120,    50,    51,   121,   180,   190,   135,   135,    83,
      33,    53,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    70,    85,    72,
     164,   165,   166,    73,    74,    75,    76,   122,    77,   170,
      81,    34,    35,    36,    37,    38,    39,    40,    41,    82,
     123,    42,    43,   124,   125,    86,    44,     2,     3,     4,
      45,    46,    47,     5,     6,     7,     8,    79,    90,     9,
      48,   103,   127,    49,   128,   135,   173,   121,   141,    85,
      95,   185,    50,    51,   132,   140,    21,   175,   146,    52,
     176,    53,   181,    99,   178,    19,   100,     2,     3,     4,
     198,     2,     3,     4,   182,   196,     8,   167,   200,    22,
       8,    30,   173,   202,   177,     0,     0,     0,    78,     0,
     187,   188,   189,     0,   102,     0,   105,   106,   107,    10,
     195,     0,   197,    10,     0,     0,     0,     0,     0,   201,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
      42,    43,     0,     0,     0,    44,     2,     3,     4,    45,
      46,    47,     5,     6,     7,     8,   145,     0,     9,    48,
       0,   147,    49,     0,     0,     0,     2,     3,     4,     0,
       0,    50,    51,     0,     0,     8,     0,     0,    52,     0,
      53,     0,     0,     0,    19,    54,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,    42,    43,    10,     0,
       0,    44,     0,     0,     0,    45,    46,    47,     0,   116,
     117,   118,   119,   120,     0,    48,   121,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,     0,
       0,     0,     0,     0,    83,     0,    53,     0,   104,     0,
      19,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,    42,    43,     0,     0,     0,    44,     0,     0,     0,
      45,    46,    47,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    51,     0,     0,     0,     0,     0,    83,
       0,    53,     0,     0,     0,    19,    34,    35,    36,    37,
       0,     0,     0,    41,     0,     0,    42,     0,     0,     0,
       0,    44,     2,     3,     4,     0,     0,    47,     0,     0,
       0,     8,     0,     0,    34,    35,    36,    37,    49,     0,
       0,    41,     0,     0,    42,     0,     0,    50,    51,    44,
       0,     0,     0,     0,    52,    47,    53,    94,    34,    35,
      36,    37,     0,     0,     0,    41,    49,     0,    42,     0,
       0,     0,     0,    44,     0,    50,    51,     0,     0,    47,
       0,     0,    83,     0,    53,   136,    34,    35,    36,    37,
      49,     0,     0,    41,     0,     0,    42,     0,     0,    50,
      51,    44,     0,     0,     0,     0,    83,    47,    53,   163,
       0,     0,     0,     0,    34,    35,    36,    37,    49,     0,
       0,    41,     0,     0,    42,     0,     0,    50,    51,    44,
       2,     3,     4,     1,    83,    47,    53,   184,     0,     8,
       0,     2,     3,     4,     0,     0,    49,     5,     6,     7,
       8,     0,     0,     9,     0,    50,    51,   108,   109,     0,
       0,     0,    52,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,    10,   108,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,   121,   108,   109,   142,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,   121,
     108,   109,   168,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,   121,   108,
     109,   169,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,   121,   108,   109,   172,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   108,   109,   121,     0,     0,   199,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   108,
     109,   121,   139,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,     0,     0,   121,   179,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     0,     0,   121,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,   121,   112,
     113,   114,   115,   116,   117,   118,   119,   120,     0,     0,
     121
};

static const yytype_int16 yycheck[] =
{
       1,     5,     6,   140,    40,     9,    10,    43,    44,    43,
      46,    40,    12,    57,    50,    51,    52,    53,     4,    19,
       0,     3,     4,     5,     6,    41,    41,    56,    10,    33,
      15,    13,    55,    54,    70,    56,    18,     4,    74,   176,
      12,    77,    24,    59,    59,    81,    82,    83,    52,    53,
      86,    36,    86,    35,    90,     4,    54,    57,    56,    46,
      47,    48,    44,    45,    51,    54,    54,    56,    56,    51,
      41,    53,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    37,   124,     4,
     124,   127,   128,     4,    37,     4,    52,    37,    37,   135,
      53,     3,     4,     5,     6,     7,     8,     9,    10,    53,
      50,    13,    14,    53,     5,    53,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   131,    53,    31,
      32,    58,    37,    35,    37,    56,   140,    51,     4,   175,
     144,   175,    44,    45,    40,    34,     4,    53,    58,    51,
      34,    53,    30,    55,    58,    57,    58,    19,    20,    21,
     196,    19,    20,    21,    29,    53,    28,   131,    29,    27,
      28,    12,   176,   201,   144,    -1,    -1,    -1,    40,    -1,
     181,   182,   183,    -1,    57,    -1,    59,    60,    61,    51,
     191,    -1,   193,    51,    -1,    -1,    -1,    -1,    -1,   200,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    99,    -1,    31,    32,
      -1,   104,    35,    -1,    -1,    -1,    19,    20,    21,    -1,
      -1,    44,    45,    -1,    -1,    28,    -1,    -1,    51,    -1,
      53,    -1,    -1,    -1,    57,    58,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    14,    51,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    -1,    44,
      45,    46,    47,    48,    -1,    32,    51,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,
      57,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    -1,    -1,    24,    -1,    -1,
      -1,    28,    -1,    -1,     3,     4,     5,     6,    35,    -1,
      -1,    10,    -1,    -1,    13,    -1,    -1,    44,    45,    18,
      -1,    -1,    -1,    -1,    51,    24,    53,    54,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    35,    -1,    13,    -1,
      -1,    -1,    -1,    18,    -1,    44,    45,    -1,    -1,    24,
      -1,    -1,    51,    -1,    53,    54,     3,     4,     5,     6,
      35,    -1,    -1,    10,    -1,    -1,    13,    -1,    -1,    44,
      45,    18,    -1,    -1,    -1,    -1,    51,    24,    53,    54,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    35,    -1,
      -1,    10,    -1,    -1,    13,    -1,    -1,    44,    45,    18,
      19,    20,    21,    11,    51,    24,    53,    54,    -1,    28,
      -1,    19,    20,    21,    -1,    -1,    35,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    44,    45,    16,    17,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    16,    17,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    51,    16,    17,    54,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    51,
      16,    17,    54,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    51,    16,
      17,    54,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    51,    16,    17,    54,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    16,    17,    51,    -1,    -1,    54,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    16,
      17,    51,    52,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    51,    52,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    51,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    51,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    19,    20,    21,    25,    26,    27,    28,    31,
      51,    61,    62,    63,    64,    65,    66,    67,    69,    57,
      70,     4,    27,    65,    65,     4,    65,    65,     0,    63,
      69,    55,     4,    41,     3,     4,     5,     6,     7,     8,
       9,    10,    13,    14,    18,    22,    23,    24,    32,    35,
      44,    45,    51,    53,    58,    63,    70,    71,    72,    73,
      74,    75,    78,    79,    80,    83,    84,    85,    86,    12,
      37,     4,     4,     4,    37,     4,    52,    37,    40,    65,
      68,    53,    53,    51,    77,    78,    53,    77,    78,    78,
      53,    78,    78,    78,    54,    65,    78,    81,    82,    55,
      58,    63,    72,    58,    55,    72,    72,    72,    16,    17,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    51,    37,    50,    53,     5,    78,    37,    37,    78,
      78,    56,    40,    78,    78,    56,    54,    77,    78,    52,
      34,     4,    54,    54,    56,    72,    58,    72,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    54,    77,    78,    78,    68,    54,    54,
      78,    54,    54,    65,    67,    53,    34,    82,    58,    52,
      54,    30,    29,    59,    54,    77,    67,    70,    70,    70,
      54,    59,    15,    36,    76,    70,    53,    70,    78,    54,
      29,    70,    76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    70,    70,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    76,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      83,    83,    84,    85,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     2,     1,
       5,     3,     3,     4,     2,     5,     4,     4,     3,     1,
       1,     1,     3,     1,     4,     3,     1,     1,     1,     3,
       3,     3,     2,     3,     4,     5,     1,     2,     1,     1,
       1,     3,     2,     2,     2,     1,     2,     2,     1,     1,
       2,     1,     6,     7,     6,     2,     6,     7,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     1,     4,     3,     3,     7,
       6,     4,     3,     4,     3,     6,     5,     1,     3,     2,
       1,     4,     1,     1,     1,     2
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
        yyerror (compiler, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (compiler);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, compiler);
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
                 int yyrule, std::shared_ptr<cdk::compiler> compiler)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YY_USE (yyvaluep);
  YY_USE (compiler);
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
yyparse (std::shared_ptr<cdk::compiler> compiler)
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
  case 2: /* file: %empty  */
#line 80 "l22_parser.y"
                                           { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE)); }
#line 1401 "l22_parser.tab.c"
    break;

  case 3: /* file: declarations  */
#line 81 "l22_parser.y"
                                           { compiler->ast((yyvsp[0].sequence)); }
#line 1407 "l22_parser.tab.c"
    break;

  case 4: /* file: program  */
#line 82 "l22_parser.y"
                                           { compiler->ast((yyvsp[0].node)); }
#line 1413 "l22_parser.tab.c"
    break;

  case 5: /* file: declarations program  */
#line 83 "l22_parser.y"
                                           { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence))); }
#line 1419 "l22_parser.tab.c"
    break;

  case 6: /* declarations: declaration  */
#line 86 "l22_parser.y"
                                              { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1425 "l22_parser.tab.c"
    break;

  case 7: /* declarations: declarations declaration  */
#line 87 "l22_parser.y"
                                              { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1431 "l22_parser.tab.c"
    break;

  case 8: /* declaration: vardecl ';'  */
#line 90 "l22_parser.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1437 "l22_parser.tab.c"
    break;

  case 9: /* declaration: vardecl  */
#line 91 "l22_parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1443 "l22_parser.tab.c"
    break;

  case 10: /* vardecl: tPUBLIC data_type tIDENTIFIER '=' expression  */
#line 94 "l22_parser.y"
                                                                        { (yyval.node) = new l22::variable_declaration_node(LINE, tPUBLIC, (yyvsp[-3].type), *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1449 "l22_parser.tab.c"
    break;

  case 11: /* vardecl: tPUBLIC data_type tIDENTIFIER  */
#line 95 "l22_parser.y"
                                                                        { (yyval.node) = new l22::variable_declaration_node(LINE, tPUBLIC, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1455 "l22_parser.tab.c"
    break;

  case 12: /* vardecl: tUSE data_type tIDENTIFIER  */
#line 96 "l22_parser.y"
                                                                        { (yyval.node) = new l22::variable_declaration_node(LINE, tUSE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1461 "l22_parser.tab.c"
    break;

  case 13: /* vardecl: data_type tIDENTIFIER '=' expression  */
#line 97 "l22_parser.y"
                                                                        { (yyval.node) = new l22::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-3].type), *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1467 "l22_parser.tab.c"
    break;

  case 14: /* vardecl: data_type tIDENTIFIER  */
#line 98 "l22_parser.y"
                                                                        { (yyval.node) = new l22::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1473 "l22_parser.tab.c"
    break;

  case 15: /* vardecl: tPUBLIC tVAR tIDENTIFIER '=' expression  */
#line 99 "l22_parser.y"
                                                                        { (yyval.node) = new l22::variable_declaration_node(LINE, tPUBLIC, (yyvsp[0].expression)->type(), *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1479 "l22_parser.tab.c"
    break;

  case 16: /* vardecl: tPUBLIC tIDENTIFIER '=' expression  */
#line 100 "l22_parser.y"
                                                                        { (yyval.node) = new l22::variable_declaration_node(LINE, tPUBLIC, (yyvsp[0].expression)->type(), *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1485 "l22_parser.tab.c"
    break;

  case 17: /* vardecl: tVAR tIDENTIFIER '=' expression  */
#line 101 "l22_parser.y"
                                                                        { (yyval.node) = new l22::variable_declaration_node(LINE, tPRIVATE, (yyvsp[0].expression)->type(), *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1491 "l22_parser.tab.c"
    break;

  case 18: /* vardecl: tFOREIGN data_type tIDENTIFIER  */
#line 102 "l22_parser.y"
                                                                        { (yyval.node) = new l22::variable_declaration_node(LINE, tFOREIGN, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1497 "l22_parser.tab.c"
    break;

  case 19: /* data_type: tTEXT  */
#line 105 "l22_parser.y"
                                               { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
#line 1503 "l22_parser.tab.c"
    break;

  case 20: /* data_type: tINT  */
#line 106 "l22_parser.y"
                                               { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT); }
#line 1509 "l22_parser.tab.c"
    break;

  case 21: /* data_type: tDOUBLE  */
#line 107 "l22_parser.y"
                                               { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
#line 1515 "l22_parser.tab.c"
    break;

  case 22: /* data_type: '[' data_type ']'  */
#line 108 "l22_parser.y"
                                               { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type));}
#line 1521 "l22_parser.tab.c"
    break;

  case 23: /* data_type: func_type  */
#line 109 "l22_parser.y"
                                               { (yyval.type) = (yyvsp[0].type); }
#line 1527 "l22_parser.tab.c"
    break;

  case 24: /* func_type: return_type '<' data_types '>'  */
#line 112 "l22_parser.y"
                                                  { (yyval.type) = cdk::functional_type::create(*(yyvsp[-1].vector), (yyvsp[-3].type)); }
#line 1533 "l22_parser.tab.c"
    break;

  case 25: /* func_type: return_type '<' '>'  */
#line 113 "l22_parser.y"
                                                  { (yyval.type) = cdk::functional_type::create(*(new std::vector<std::shared_ptr<cdk::basic_type>>()), (yyvsp[-2].type)); }
#line 1539 "l22_parser.tab.c"
    break;

  case 26: /* return_type: data_type  */
#line 116 "l22_parser.y"
                                               { (yyval.type) = (yyvsp[0].type); }
#line 1545 "l22_parser.tab.c"
    break;

  case 27: /* return_type: tVOID  */
#line 117 "l22_parser.y"
                                               { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
#line 1551 "l22_parser.tab.c"
    break;

  case 28: /* data_types: data_type  */
#line 120 "l22_parser.y"
                                               { (yyval.vector) = new std::vector<std::shared_ptr<cdk::basic_type>>(); (yyval.vector)->insert((yyval.vector)->begin(), (yyvsp[0].type)); }
#line 1557 "l22_parser.tab.c"
    break;

  case 29: /* data_types: data_type ',' data_types  */
#line 121 "l22_parser.y"
                                               { (yyval.vector) = (yyvsp[0].vector); (yyval.vector)->insert((yyval.vector)->begin(), (yyvsp[-2].type)); }
#line 1563 "l22_parser.tab.c"
    break;

  case 30: /* program: tBEGIN block tEND  */
#line 124 "l22_parser.y"
                                        { (yyval.node) = new l22::program_node(LINE, (yyvsp[-1].block)); }
#line 1569 "l22_parser.tab.c"
    break;

  case 31: /* block: '{' instructions '}'  */
#line 128 "l22_parser.y"
                                                       { (yyval.block) = new l22::block_node(LINE, nullptr, (yyvsp[-1].sequence)); }
#line 1575 "l22_parser.tab.c"
    break;

  case 32: /* block: '{' '}'  */
#line 129 "l22_parser.y"
                                                       { (yyval.block) = new l22::block_node(LINE, nullptr, new cdk::sequence_node(LINE)); }
#line 1581 "l22_parser.tab.c"
    break;

  case 33: /* block: '{' innerdecls '}'  */
#line 130 "l22_parser.y"
                                                       { (yyval.block) = new l22::block_node(LINE, (yyvsp[-1].sequence), new cdk::sequence_node(LINE) ); }
#line 1587 "l22_parser.tab.c"
    break;

  case 34: /* block: '{' innerdecls instructions '}'  */
#line 131 "l22_parser.y"
                                                       { (yyval.block) = new l22::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1593 "l22_parser.tab.c"
    break;

  case 35: /* block: '{' innerdecls ';' instructions '}'  */
#line 132 "l22_parser.y"
                                                       { (yyval.block) = new l22::block_node(LINE, (yyvsp[-3].sequence), (yyvsp[-1].sequence)); }
#line 1599 "l22_parser.tab.c"
    break;

  case 36: /* innerdecls: declaration  */
#line 135 "l22_parser.y"
                                                { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1605 "l22_parser.tab.c"
    break;

  case 37: /* innerdecls: innerdecls declaration  */
#line 136 "l22_parser.y"
                                                { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1611 "l22_parser.tab.c"
    break;

  case 38: /* instructions: instruction  */
#line 140 "l22_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1617 "l22_parser.tab.c"
    break;

  case 39: /* instructions: cond_instruction  */
#line 141 "l22_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1623 "l22_parser.tab.c"
    break;

  case 40: /* instructions: it_instruction  */
#line 142 "l22_parser.y"
                                                       { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1629 "l22_parser.tab.c"
    break;

  case 41: /* instructions: instruction ';' instructions  */
#line 143 "l22_parser.y"
                                                       { std::reverse((yyvsp[0].sequence)->nodes().begin(), (yyvsp[0].sequence)->nodes().end()); (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-2].node), (yyvsp[0].sequence)); std::reverse((yyval.sequence)->nodes().begin(), (yyval.sequence)->nodes().end()); }
#line 1635 "l22_parser.tab.c"
    break;

  case 42: /* instructions: instruction instructions  */
#line 144 "l22_parser.y"
                                                       { std::reverse((yyvsp[0].sequence)->nodes().begin(), (yyvsp[0].sequence)->nodes().end()); (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[0].sequence)); std::reverse((yyval.sequence)->nodes().begin(), (yyval.sequence)->nodes().end()); }
#line 1641 "l22_parser.tab.c"
    break;

  case 43: /* instructions: cond_instruction instructions  */
#line 145 "l22_parser.y"
                                                       { std::reverse((yyvsp[0].sequence)->nodes().begin(), (yyvsp[0].sequence)->nodes().end()); (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[0].sequence)); std::reverse((yyval.sequence)->nodes().begin(), (yyval.sequence)->nodes().end()); }
#line 1647 "l22_parser.tab.c"
    break;

  case 44: /* instructions: it_instruction instructions  */
#line 146 "l22_parser.y"
                                                       { std::reverse((yyvsp[0].sequence)->nodes().begin(), (yyvsp[0].sequence)->nodes().end()); (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[0].sequence)); std::reverse((yyval.sequence)->nodes().begin(), (yyval.sequence)->nodes().end()); }
#line 1653 "l22_parser.tab.c"
    break;

  case 45: /* instruction: expression  */
#line 149 "l22_parser.y"
                                        { (yyval.node) = new l22::evaluation_node(LINE, (yyvsp[0].expression)); }
#line 1659 "l22_parser.tab.c"
    break;

  case 46: /* instruction: tWRITE expressions  */
#line 150 "l22_parser.y"
                                        { (yyval.node) = new l22::write_node(LINE, (yyvsp[0].sequence), false); }
#line 1665 "l22_parser.tab.c"
    break;

  case 47: /* instruction: tWRITELN expressions  */
#line 151 "l22_parser.y"
                                        { (yyval.node) = new l22::write_node(LINE, (yyvsp[0].sequence), true); }
#line 1671 "l22_parser.tab.c"
    break;

  case 48: /* instruction: tAGAIN  */
#line 152 "l22_parser.y"
                                        { (yyval.node) = new l22::again_node(LINE); }
#line 1677 "l22_parser.tab.c"
    break;

  case 49: /* instruction: tSTOP  */
#line 153 "l22_parser.y"
                                        { (yyval.node) = new l22::stop_node(LINE); }
#line 1683 "l22_parser.tab.c"
    break;

  case 50: /* instruction: tRETURN expression  */
#line 154 "l22_parser.y"
                                        { (yyval.node) = new l22::return_node(LINE, (yyvsp[0].expression)); }
#line 1689 "l22_parser.tab.c"
    break;

  case 51: /* instruction: block  */
#line 155 "l22_parser.y"
                                        { (yyval.node) = (yyvsp[0].block); }
#line 1695 "l22_parser.tab.c"
    break;

  case 52: /* cond_instruction: tIF '(' expression ')' tTHEN block  */
#line 158 "l22_parser.y"
                                                                { (yyval.node) = new l22::if_node(LINE, (yyvsp[-3].expression), (yyvsp[0].block)); }
#line 1701 "l22_parser.tab.c"
    break;

  case 53: /* cond_instruction: tIF '(' expression ')' tTHEN block elif  */
#line 159 "l22_parser.y"
                                                                { (yyval.node) = new l22::if_else_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].block), (yyvsp[0].node)); }
#line 1707 "l22_parser.tab.c"
    break;

  case 54: /* it_instruction: tWHILE '(' expression ')' tDO block  */
#line 162 "l22_parser.y"
                                                           { (yyval.node) = new l22::while_node(LINE, (yyvsp[-3].expression), (yyvsp[0].block)); }
#line 1713 "l22_parser.tab.c"
    break;

  case 55: /* elif: tELSE block  */
#line 166 "l22_parser.y"
                                                                      { (yyval.node) = (yyvsp[0].block); }
#line 1719 "l22_parser.tab.c"
    break;

  case 56: /* elif: tELIF '(' expression ')' tTHEN block  */
#line 167 "l22_parser.y"
                                                                      { (yyval.node) = new l22::if_node(LINE, (yyvsp[-3].expression), (yyvsp[0].block)); }
#line 1725 "l22_parser.tab.c"
    break;

  case 57: /* elif: tELIF '(' expression ')' tTHEN block elif  */
#line 168 "l22_parser.y"
                                                                      { (yyval.node) = new l22::if_else_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].block), (yyvsp[0].node)); }
#line 1731 "l22_parser.tab.c"
    break;

  case 58: /* expressions: expression  */
#line 171 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression)); }
#line 1737 "l22_parser.tab.c"
    break;

  case 59: /* expressions: expressions ',' expression  */
#line 172 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 1743 "l22_parser.tab.c"
    break;

  case 60: /* expression: integer  */
#line 175 "l22_parser.y"
                                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 1749 "l22_parser.tab.c"
    break;

  case 61: /* expression: real  */
#line 176 "l22_parser.y"
                                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 1755 "l22_parser.tab.c"
    break;

  case 62: /* expression: string  */
#line 177 "l22_parser.y"
                                                            { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1761 "l22_parser.tab.c"
    break;

  case 63: /* expression: tNULL  */
#line 178 "l22_parser.y"
                                                            { (yyval.expression) = new l22::null_node(LINE); }
#line 1767 "l22_parser.tab.c"
    break;

  case 64: /* expression: fundef  */
#line 179 "l22_parser.y"
                                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 1773 "l22_parser.tab.c"
    break;

  case 65: /* expression: func_cal  */
#line 180 "l22_parser.y"
                                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 1779 "l22_parser.tab.c"
    break;

  case 66: /* expression: lval  */
#line 181 "l22_parser.y"
                                                            { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1785 "l22_parser.tab.c"
    break;

  case 67: /* expression: lval '=' expression  */
#line 182 "l22_parser.y"
                                                            { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 1791 "l22_parser.tab.c"
    break;

  case 68: /* expression: lval '?'  */
#line 183 "l22_parser.y"
                                                            { (yyval.expression) = new l22::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 1797 "l22_parser.tab.c"
    break;

  case 69: /* expression: expression '+' expression  */
#line 184 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1803 "l22_parser.tab.c"
    break;

  case 70: /* expression: expression '-' expression  */
#line 185 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1809 "l22_parser.tab.c"
    break;

  case 71: /* expression: expression '*' expression  */
#line 186 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1815 "l22_parser.tab.c"
    break;

  case 72: /* expression: expression '/' expression  */
#line 187 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1821 "l22_parser.tab.c"
    break;

  case 73: /* expression: expression '%' expression  */
#line 188 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1827 "l22_parser.tab.c"
    break;

  case 74: /* expression: expression '<' expression  */
#line 189 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1833 "l22_parser.tab.c"
    break;

  case 75: /* expression: expression '>' expression  */
#line 190 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1839 "l22_parser.tab.c"
    break;

  case 76: /* expression: expression tGE expression  */
#line 191 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1845 "l22_parser.tab.c"
    break;

  case 77: /* expression: expression tLE expression  */
#line 192 "l22_parser.y"
                                                            { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1851 "l22_parser.tab.c"
    break;

  case 78: /* expression: expression tNE expression  */
#line 193 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1857 "l22_parser.tab.c"
    break;

  case 79: /* expression: expression tEQ expression  */
#line 194 "l22_parser.y"
                                                                { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1863 "l22_parser.tab.c"
    break;

  case 80: /* expression: expression tAND expression  */
#line 195 "l22_parser.y"
                                                            { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1869 "l22_parser.tab.c"
    break;

  case 81: /* expression: expression tOR expression  */
#line 196 "l22_parser.y"
                                                            { (yyval.expression) = new cdk::or_node (LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1875 "l22_parser.tab.c"
    break;

  case 82: /* expression: '-' expression  */
#line 197 "l22_parser.y"
                                                            { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 1881 "l22_parser.tab.c"
    break;

  case 83: /* expression: '+' expression  */
#line 198 "l22_parser.y"
                                                            { (yyval.expression) = new l22::identity_node(LINE, (yyvsp[0].expression)); }
#line 1887 "l22_parser.tab.c"
    break;

  case 84: /* expression: tNOT expression  */
#line 199 "l22_parser.y"
                                                            { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 1893 "l22_parser.tab.c"
    break;

  case 85: /* expression: tINPUT  */
#line 200 "l22_parser.y"
                                                            { (yyval.expression) = new l22::input_node(LINE);  }
#line 1899 "l22_parser.tab.c"
    break;

  case 86: /* expression: tSIZEOF '(' expression ')'  */
#line 201 "l22_parser.y"
                                                            { (yyval.expression) = new l22::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 1905 "l22_parser.tab.c"
    break;

  case 87: /* expression: '(' expression ')'  */
#line 202 "l22_parser.y"
                                                            { (yyval.expression) = (yyvsp[-1].expression); }
#line 1911 "l22_parser.tab.c"
    break;

  case 88: /* expression: '[' expression ']'  */
#line 203 "l22_parser.y"
                                                            { (yyval.expression) = new l22::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 1917 "l22_parser.tab.c"
    break;

  case 89: /* fundef: '(' argdecs ')' tARROW return_type ':' block  */
#line 206 "l22_parser.y"
                                                                    { (yyval.expression) = new l22::function_definition_node(LINE, (yyvsp[-2].type), (yyvsp[-5].sequence), (yyvsp[0].block)); }
#line 1923 "l22_parser.tab.c"
    break;

  case 90: /* fundef: '(' ')' tARROW return_type ':' block  */
#line 207 "l22_parser.y"
                                                                    { (yyval.expression) = new l22::function_definition_node(LINE, (yyvsp[-2].type), new cdk::sequence_node(LINE), (yyvsp[0].block)); }
#line 1929 "l22_parser.tab.c"
    break;

  case 91: /* func_cal: lval '(' expressions ')'  */
#line 210 "l22_parser.y"
                                                            { (yyval.expression) = new l22::function_call_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lvalue)), (yyvsp[-1].sequence)); }
#line 1935 "l22_parser.tab.c"
    break;

  case 92: /* func_cal: lval '(' ')'  */
#line 211 "l22_parser.y"
                                                            { (yyval.expression) = new l22::function_call_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-2].lvalue))); }
#line 1941 "l22_parser.tab.c"
    break;

  case 93: /* func_cal: tAT '(' expressions ')'  */
#line 212 "l22_parser.y"
                                                            { (yyval.expression) = new l22::function_call_node(LINE, nullptr, (yyvsp[-1].sequence)); }
#line 1947 "l22_parser.tab.c"
    break;

  case 94: /* func_cal: tAT '(' ')'  */
#line 213 "l22_parser.y"
                                                            { (yyval.expression) = new l22::function_call_node(LINE, nullptr); }
#line 1953 "l22_parser.tab.c"
    break;

  case 95: /* func_cal: '(' expression ')' '(' expressions ')'  */
#line 214 "l22_parser.y"
                                                            { (yyval.expression) = new l22::function_call_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].sequence)); }
#line 1959 "l22_parser.tab.c"
    break;

  case 96: /* func_cal: '(' expression ')' '(' ')'  */
#line 215 "l22_parser.y"
                                                            { (yyval.expression) = new l22::function_call_node(LINE, (yyvsp[-3].expression)); }
#line 1965 "l22_parser.tab.c"
    break;

  case 97: /* argdecs: argdec  */
#line 218 "l22_parser.y"
                                     { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1971 "l22_parser.tab.c"
    break;

  case 98: /* argdecs: argdecs ',' argdec  */
#line 219 "l22_parser.y"
                                     { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1977 "l22_parser.tab.c"
    break;

  case 99: /* argdec: data_type tIDENTIFIER  */
#line 222 "l22_parser.y"
                                       { (yyval.node) = new l22::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1983 "l22_parser.tab.c"
    break;

  case 100: /* lval: tIDENTIFIER  */
#line 225 "l22_parser.y"
                                                  { (yyval.lvalue) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 1989 "l22_parser.tab.c"
    break;

  case 101: /* lval: expression '[' expression ']'  */
#line 226 "l22_parser.y"
                                                  { (yyval.lvalue) = new l22::index_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1995 "l22_parser.tab.c"
    break;

  case 102: /* integer: tINTEGER  */
#line 229 "l22_parser.y"
                                               { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 2001 "l22_parser.tab.c"
    break;

  case 103: /* real: tREAL  */
#line 230 "l22_parser.y"
                                               { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 2007 "l22_parser.tab.c"
    break;

  case 104: /* string: tSTRING  */
#line 231 "l22_parser.y"
                                               { (yyval.s) = (yyvsp[0].s); }
#line 2013 "l22_parser.tab.c"
    break;

  case 105: /* string: string tSTRING  */
#line 232 "l22_parser.y"
                                               { (yyval.s) = new std::string(*(yyvsp[-1].s) + *(yyvsp[0].s)); delete (yyvsp[-1].s); delete (yyvsp[0].s); }
#line 2019 "l22_parser.tab.c"
    break;


#line 2023 "l22_parser.tab.c"

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
      yyerror (compiler, YY_("syntax error"));
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
                      yytoken, &yylval, compiler);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, compiler);
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
  yyerror (compiler, YY_("memory exhausted"));
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
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 235 "l22_parser.y"

