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
#line 5 "src/parser.y"

#include <iostream>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <vector>

#include "../src/symtable.hpp"
#include "../src/iopcode.hpp"

extern SymbolTable symTable;
extern bool skipBlockScope;
extern int loopCounter;
extern int yylex();
extern char* yytext;
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
extern std::stack<int> loopStack;
int yyerror(const char* msg);

// Global variables
SymEntry* entryFuncDef = nullptr;

#line 96 "out/parser.tab.cpp"

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

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MULTIPLY = 5,                   /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 6,                     /* DIVIDE  */
  YYSYMBOL_MODULO = 7,                     /* MODULO  */
  YYSYMBOL_LESS_THAN = 8,                  /* LESS_THAN  */
  YYSYMBOL_LESS_THAN_EQUAL = 9,            /* LESS_THAN_EQUAL  */
  YYSYMBOL_GREATER_THAN = 10,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_THAN_EQUAL = 11,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_EQUAL = 12,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 13,                 /* NOT_EQUAL  */
  YYSYMBOL_INCREMENT = 14,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 15,                 /* DECREMENT  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_PLUS_ASSIGN = 17,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 18,              /* MINUS_ASSIGN  */
  YYSYMBOL_SEMICOLON = 19,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_COLON = 21,                     /* COLON  */
  YYSYMBOL_DOUBLE_COLON = 22,              /* DOUBLE_COLON  */
  YYSYMBOL_DOT = 23,                       /* DOT  */
  YYSYMBOL_DOUBLE_DOT = 24,                /* DOUBLE_DOT  */
  YYSYMBOL_LEFT_PARENTHESIS = 25,          /* LEFT_PARENTHESIS  */
  YYSYMBOL_RIGHT_PARENTHESIS = 26,         /* RIGHT_PARENTHESIS  */
  YYSYMBOL_LEFT_BRACE = 27,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 28,               /* RIGHT_BRACE  */
  YYSYMBOL_LEFT_BRACKET = 29,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 30,             /* RIGHT_BRACKET  */
  YYSYMBOL_UMINUS = 31,                    /* UMINUS  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_FOR = 35,                       /* FOR  */
  YYSYMBOL_FUNCTION = 36,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 37,                    /* RETURN  */
  YYSYMBOL_BREAK = 38,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 39,                  /* CONTINUE  */
  YYSYMBOL_TRUE = 40,                      /* TRUE  */
  YYSYMBOL_FALSE = 41,                     /* FALSE  */
  YYSYMBOL_NIL = 42,                       /* NIL  */
  YYSYMBOL_LOCAL = 43,                     /* LOCAL  */
  YYSYMBOL_AND = 44,                       /* AND  */
  YYSYMBOL_NOT = 45,                       /* NOT  */
  YYSYMBOL_OR = 46,                        /* OR  */
  YYSYMBOL_INTEGER = 47,                   /* INTEGER  */
  YYSYMBOL_REAL = 48,                      /* REAL  */
  YYSYMBOL_STRINGT = 49,                   /* STRINGT  */
  YYSYMBOL_IDENTIFIER = 50,                /* IDENTIFIER  */
  YYSYMBOL_ERROR_COMMENT = 51,             /* ERROR_COMMENT  */
  YYSYMBOL_ERROR_STRING = 52,              /* ERROR_STRING  */
  YYSYMBOL_ERROR_ESCAPE = 53,              /* ERROR_ESCAPE  */
  YYSYMBOL_UNDEF = 54,                     /* UNDEF  */
  YYSYMBOL_LOWER_THAN_ELSE = 55,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_stmt = 58,                      /* stmt  */
  YYSYMBOL_stmt_list = 59,                 /* stmt_list  */
  YYSYMBOL_expr = 60,                      /* expr  */
  YYSYMBOL_term = 61,                      /* term  */
  YYSYMBOL_assignexpr = 62,                /* assignexpr  */
  YYSYMBOL_primary = 63,                   /* primary  */
  YYSYMBOL_lvalue = 64,                    /* lvalue  */
  YYSYMBOL_member = 65,                    /* member  */
  YYSYMBOL_call = 66,                      /* call  */
  YYSYMBOL_callsuffix = 67,                /* callsuffix  */
  YYSYMBOL_normcall = 68,                  /* normcall  */
  YYSYMBOL_methodcall = 69,                /* methodcall  */
  YYSYMBOL_elist = 70,                     /* elist  */
  YYSYMBOL_objectdef = 71,                 /* objectdef  */
  YYSYMBOL_indexed = 72,                   /* indexed  */
  YYSYMBOL_indexedelem = 73,               /* indexedelem  */
  YYSYMBOL_block = 74,                     /* block  */
  YYSYMBOL_75_1 = 75,                      /* $@1  */
  YYSYMBOL_funcblockstart = 76,            /* funcblockstart  */
  YYSYMBOL_funcblockend = 77,              /* funcblockend  */
  YYSYMBOL_funcdef = 78,                   /* funcdef  */
  YYSYMBOL_79_2 = 79,                      /* $@2  */
  YYSYMBOL_80_3 = 80,                      /* $@3  */
  YYSYMBOL_81_4 = 81,                      /* $@4  */
  YYSYMBOL_82_5 = 82,                      /* $@5  */
  YYSYMBOL_const = 83,                     /* const  */
  YYSYMBOL_idlist = 84,                    /* idlist  */
  YYSYMBOL_ifprefix = 85,                  /* ifprefix  */
  YYSYMBOL_elseprefix = 86,                /* elseprefix  */
  YYSYMBOL_ifstmt = 87,                    /* ifstmt  */
  YYSYMBOL_loopstart = 88,                 /* loopstart  */
  YYSYMBOL_loopend = 89,                   /* loopend  */
  YYSYMBOL_loopstmt = 90,                  /* loopstmt  */
  YYSYMBOL_whilestart = 91,                /* whilestart  */
  YYSYMBOL_whilecond = 92,                 /* whilecond  */
  YYSYMBOL_whilestmt = 93,                 /* whilestmt  */
  YYSYMBOL_N = 94,                         /* N  */
  YYSYMBOL_M = 95,                         /* M  */
  YYSYMBOL_forprefix = 96,                 /* forprefix  */
  YYSYMBOL_forstmt = 97,                   /* forstmt  */
  YYSYMBOL_returnstmt = 98,                /* returnstmt  */
  YYSYMBOL_errors = 99                     /* errors  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   773

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


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
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   152,   160,   165,   170,   175,   181,   196,
     209,   214,   221,   225,   233,   241,   248,   257,   262,   280,
     295,   311,   333,   355,   371,   387,   404,   421,   438,   455,
     472,   489,   495,   500,   508,   515,   530,   546,   561,   577,
     583,   612,   641,   671,   681,   691,   696,   700,   706,   742,
     771,   782,   788,   797,   810,   815,   825,   830,   843,   851,
     857,   864,   873,   881,   888,   893,   899,   910,   922,   927,
     934,   944,   944,   957,   962,   967,  1009,   967,  1031,  1053,
    1031,  1068,  1074,  1080,  1086,  1093,  1100,  1106,  1140,  1174,
    1180,  1189,  1195,  1201,  1209,  1213,  1216,  1220,  1224,  1233,
    1248,  1254,  1259,  1272,  1290,  1297,  1306,  1312,  1318,  1324
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "LESS_THAN", "LESS_THAN_EQUAL",
  "GREATER_THAN", "GREATER_THAN_EQUAL", "EQUAL", "NOT_EQUAL", "INCREMENT",
  "DECREMENT", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "SEMICOLON",
  "COMMA", "COLON", "DOUBLE_COLON", "DOT", "DOUBLE_DOT",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_BRACE", "RIGHT_BRACE",
  "LEFT_BRACKET", "RIGHT_BRACKET", "UMINUS", "IF", "ELSE", "WHILE", "FOR",
  "FUNCTION", "RETURN", "BREAK", "CONTINUE", "TRUE", "FALSE", "NIL",
  "LOCAL", "AND", "NOT", "OR", "INTEGER", "REAL", "STRINGT", "IDENTIFIER",
  "ERROR_COMMENT", "ERROR_STRING", "ERROR_ESCAPE", "UNDEF",
  "LOWER_THAN_ELSE", "$accept", "program", "stmt", "stmt_list", "expr",
  "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef", "indexed",
  "indexedelem", "block", "$@1", "funcblockstart", "funcblockend",
  "funcdef", "$@2", "$@3", "$@4", "$@5", "const", "idlist", "ifprefix",
  "elseprefix", "ifstmt", "loopstart", "loopend", "loopstmt", "whilestart",
  "whilecond", "whilestmt", "N", "M", "forprefix", "forstmt", "returnstmt",
  "errors", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-177)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     187,    -6,   457,   -10,   -10,  -177,   -23,   337,  -177,   377,
     -15,  -177,    17,   -24,   417,     6,    30,  -177,  -177,  -177,
       1,   457,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
      66,   132,  -177,   505,  -177,  -177,  -177,    40,  -177,     9,
    -177,  -177,  -177,  -177,   295,  -177,    43,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,    54,    -1,     9,    -1,  -177,   522,
      73,   241,   457,   718,   -12,   -11,  -177,   457,   457,  -177,
      77,  -177,   533,  -177,  -177,  -177,  -177,  -177,  -177,   457,
     457,   457,   457,   457,   457,   457,   457,   457,   457,   457,
    -177,   457,   457,  -177,  -177,   457,   457,   457,    58,    61,
     457,   457,  -177,  -177,  -177,    79,   457,   457,    83,   457,
    -177,   457,   104,  -177,   106,   107,   550,   457,  -177,   110,
    -177,   577,    10,    84,  -177,  -177,   108,   108,  -177,  -177,
    -177,    67,    67,    67,    67,   115,   115,   745,   729,   718,
     718,   718,  -177,   113,    -9,   601,  -177,    15,   629,  -177,
     295,   645,   295,  -177,    19,   106,   457,  -177,   457,   718,
    -177,  -177,   457,  -177,    26,    84,   457,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,    27,   657,   701,    89,  -177,
      74,    78,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,   114,  -177,  -177,  -177,   114,  -177,  -177,  -177
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    12,     0,     0,    71,    65,
       0,    97,     0,     0,     0,     0,     0,    84,    85,    86,
       0,     0,    81,    82,    83,    48,   106,   107,   108,   109,
       0,     0,     2,     0,    31,    17,    39,    43,    51,    44,
      45,    10,    11,    47,     0,     4,     0,     5,   100,     6,
       7,    13,    14,    33,     0,    35,     0,    37,    50,     0,
       0,     0,     0,    63,     0,     0,    68,     0,    65,    78,
       0,   105,     0,     8,     9,    49,    34,     1,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,    36,    38,     0,     0,     0,     0,     0,
      65,     0,    57,    59,    60,     0,    65,     0,    92,     0,
      94,    65,     0,    32,    46,     0,     0,     0,    66,     0,
      67,     0,     0,    89,    75,   104,    18,    19,    20,    21,
      22,    24,    26,    23,    25,    27,    28,    29,    30,    40,
      41,    42,    52,     0,     0,     0,    54,     0,     0,    91,
       0,     0,     0,    99,     0,     0,    65,    72,     0,    64,
      69,    90,     0,    87,     0,    89,    65,    61,    53,    56,
      55,    93,    98,    95,   100,     0,     0,     0,     0,    79,
       0,     0,    96,    94,    58,    70,   102,    88,    73,    76,
      62,   101,     0,    73,   103,    74,     0,    80,    74,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,   -40,   -25,     0,  -177,  -177,  -177,    56,  -177,
     102,  -177,  -177,  -177,   -63,  -177,  -177,    21,  -176,  -177,
     -51,   -55,    -4,  -177,  -177,  -177,  -177,  -177,   -21,  -177,
    -177,  -177,  -177,  -177,   -38,  -177,  -177,  -177,   -26,  -177,
    -177,  -177,  -177,  -177
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    30,    31,    32,    63,    34,    35,    36,    37,    38,
      39,   102,   103,   104,    64,    40,    65,    66,    41,    61,
     192,   197,    42,   165,   193,   123,   188,    43,   164,    44,
     150,    45,   152,   182,   153,    46,   110,    47,   111,   194,
      48,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    69,    53,    60,   108,   122,    78,    59,   117,   119,
      67,   117,     6,    52,    72,    54,   195,   167,   118,   120,
     198,    76,    98,    99,   100,    73,    70,    58,   101,   162,
     117,    33,   105,    20,   106,   117,   115,   144,   107,   117,
      25,   169,    68,   147,    33,   174,   178,   117,   154,    74,
     112,    75,   179,   184,    93,    94,    95,    96,    97,    55,
      57,    33,   116,    98,    99,   100,    77,   121,   109,   101,
      79,    80,    81,    82,    83,   -17,   -17,   -17,   -17,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
      13,   137,   138,   175,   178,   139,   140,   141,   117,   114,
     189,   145,   124,   181,   190,    56,    56,   148,   142,   151,
     171,   143,   173,    81,    82,    83,   149,   159,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   -17,   -17,   146,
     155,   156,   -16,     1,   163,   157,     2,    62,   166,   187,
     160,     8,   196,   199,   180,   191,     3,     4,   183,     0,
      33,     5,    33,     0,     6,     0,     0,     7,   176,     8,
     -16,     9,   177,     0,    10,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,     0,    22,
      23,    24,    25,    26,    27,    28,    29,   -16,     1,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     0,     0,     0,     5,     0,     0,     6,
       0,     0,     7,     0,     8,     0,     9,     0,     0,    10,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,    21,     0,    22,    23,    24,    25,    26,    27,
      28,    29,     1,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     0,     0,     0,
       5,     0,     0,     6,     0,     0,     7,     0,     8,   -16,
       9,     0,     0,    10,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,     0,    22,    23,
      24,    25,    26,    27,    28,    29,     1,     0,     0,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     0,     0,     0,     5,     0,     0,     6,     0,     0,
       7,     0,     8,     0,     9,     0,     0,    10,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
      21,     2,    22,    23,    24,    25,    26,    27,    28,    29,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     7,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,    17,    18,    19,
      20,     2,    21,     0,    22,    23,    24,    25,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     7,     0,    62,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,     2,    21,     0,    22,    23,    24,    25,     0,     0,
       0,     3,     4,     0,     0,     0,    71,     0,     0,     6,
       0,     0,     7,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,     2,    21,     0,    22,    23,    24,    25,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     7,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,     0,    21,     0,    22,    23,    24,    25,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,    90,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,   113,    91,
       0,    92,   125,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,    91,     0,    92,     0,
       0,   158,     0,     0,     0,     0,     0,    91,     0,    92,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    91,     0,    92,     0,     0,     0,
       0,     0,     0,   161,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    91,     0,    92,     0,     0,     0,     0,     0,     0,
       0,   168,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,    91,     0,    92,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   170,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,   172,     0,    91,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,     0,     0,     0,    91,
       0,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,     0,    92,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
     186,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,    91,     0,    92,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    91,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,    91
};

static const yytype_int16 yycheck[] =
{
       0,    25,     2,     7,    44,    68,    31,     7,    20,    20,
      25,    20,    22,    19,    14,    25,   192,    26,    30,    30,
     196,    21,    23,    24,    25,    19,    50,    50,    29,    19,
      20,    31,    23,    43,    25,    20,    61,   100,    29,    20,
      50,    26,    25,   106,    44,    26,    20,    20,   111,    19,
      54,    50,    26,    26,    14,    15,    16,    17,    18,     3,
       4,    61,    62,    23,    24,    25,     0,    67,    25,    29,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      36,    91,    92,   156,    20,    95,    96,    97,    20,    26,
      26,   101,    25,   166,    26,     3,     4,   107,    50,   109,
     150,    50,   152,     5,     6,     7,    33,   117,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    50,
      26,    25,     0,     1,    50,    28,     4,    27,    25,    50,
     119,    27,   193,   198,   165,   183,    14,    15,   174,    -1,
     150,    19,   152,    -1,    22,    -1,    -1,    25,   158,    27,
      28,    29,   162,    -1,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    45,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    -1,    25,    -1,    27,    -1,    29,    -1,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      19,    -1,    -1,    22,    -1,    -1,    25,    -1,    27,    28,
      29,    -1,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,     1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    19,    -1,    -1,    22,    -1,    -1,
      25,    -1,    27,    -1,    29,    -1,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      45,     4,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    41,    42,
      43,     4,    45,    -1,    47,    48,    49,    50,    -1,    -1,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    27,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,     4,    45,    -1,    47,    48,    49,    50,    -1,    -1,
      -1,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,     4,    45,    -1,    47,    48,    49,    50,    -1,    -1,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    -1,    45,    -1,    47,    48,    49,    50,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    19,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    26,    44,
      -1,    46,    19,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    44,    -1,    46,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    44,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    26,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    44,    -1,    46,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    30,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    26,    -1,    44,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    44,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    46,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      19,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    44,    -1,    46,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     4,    14,    15,    19,    22,    25,    27,    29,
      32,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    45,    47,    48,    49,    50,    51,    52,    53,    54,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      71,    74,    78,    83,    85,    87,    91,    93,    96,    97,
      98,    99,    19,    60,    25,    64,    66,    64,    50,    60,
      78,    75,    27,    60,    70,    72,    73,    25,    25,    25,
      50,    19,    60,    19,    19,    50,    60,     0,    59,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      19,    44,    46,    14,    15,    16,    17,    18,    23,    24,
      25,    29,    67,    68,    69,    23,    25,    29,    58,    25,
      92,    94,    78,    26,    26,    59,    60,    20,    30,    20,
      30,    60,    70,    81,    25,    19,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    50,    50,    70,    60,    50,    70,    60,    33,
      86,    60,    88,    90,    70,    26,    25,    28,    21,    60,
      73,    26,    19,    50,    84,    79,    25,    26,    30,    26,
      30,    58,    26,    58,    26,    70,    60,    60,    20,    26,
      84,    70,    89,    94,    26,    28,    19,    50,    82,    26,
      26,    90,    76,    80,    95,    74,    76,    77,    74,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    62,    63,    63,    63,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    65,    66,    66,    66,    67,
      67,    68,    69,    70,    70,    70,    71,    71,    72,    72,
      73,    75,    74,    76,    77,    79,    80,    78,    81,    82,
      78,    83,    83,    83,    83,    83,    83,    84,    84,    84,
      85,    86,    87,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    98,    99,    99,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     2,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     3,     3,     1,     1,     1,     3,     1,     1,     2,
       2,     1,     3,     4,     3,     4,     4,     2,     6,     1,
       1,     3,     5,     1,     3,     0,     3,     3,     1,     3,
       5,     0,     4,     0,     0,     0,     0,    10,     0,     0,
       9,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       4,     1,     2,     4,     0,     0,     3,     1,     3,     3,
       0,     0,     6,     7,     3,     2,     1,     1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: stmt_list  */
#line 147 "src/parser.y"
                        {       
                                fprintf(yyout, "[-] Reduced: program -> stmt_list\n");
                        }
#line 1828 "out/parser.tab.cpp"
    break;

  case 3: /* stmt: expr SEMICOLON  */
#line 152 "src/parser.y"
                        {       
                                (yyval.stmtval) = new stmt_t;
                                (yyval.stmtval)->breaklist = 0;
                                (yyval.stmtval)->contlist = 0;
                                /* resettemp(); */
                                fprintf(yyout, "[-] Reduced: stmt -> expr SEMICOLON\n");
                        }
#line 1840 "out/parser.tab.cpp"
    break;

  case 4: /* stmt: ifstmt  */
#line 160 "src/parser.y"
                        {
                                (yyval.stmtval) = (yyvsp[0].stmtval);
                                fprintf(yyout, "[-] Reduced: stmt -> ifstmt\n");
                        }
#line 1849 "out/parser.tab.cpp"
    break;

  case 5: /* stmt: whilestmt  */
#line 165 "src/parser.y"
                        {
                                (yyval.stmtval) = (yyvsp[0].stmtval);
                                fprintf(yyout, "[-] Reduced: stmt -> whilestmt\n");
                        }
#line 1858 "out/parser.tab.cpp"
    break;

  case 6: /* stmt: forstmt  */
#line 170 "src/parser.y"
                        {
                                (yyval.stmtval) = (yyvsp[0].stmtval);
                                fprintf(yyout, "[-] Reduced: stmt -> forstmt\n");
                        }
#line 1867 "out/parser.tab.cpp"
    break;

  case 7: /* stmt: returnstmt  */
#line 175 "src/parser.y"
                        {
                                if (symTable.funcStack.empty()) fprintf(yyout, "      [!] Error: Return statement outside of function in line %d.\n", yylineno);
                                (yyval.stmtval) = (yyvsp[0].stmtval);
                                fprintf(yyout, "[-] Reduced: stmt -> returnstmt\n");
                        }
#line 1877 "out/parser.tab.cpp"
    break;

  case 8: /* stmt: BREAK SEMICOLON  */
#line 181 "src/parser.y"
                                {       
                                        if (loopCounter == 0) {
                                                fprintf(yyout, "      [!] Error: Break statement outside of loop in line %d.\n", yylineno);
                                                (yyval.stmtval) = new stmt_t;
                                                (yyval.stmtval)->breaklist = 0;
                                                (yyval.stmtval)->contlist = 0;
                                        } else {
                                                (yyval.stmtval) = new struct stmt_t;
                                                (yyval.stmtval)->contlist = newlist(nextquad());
                                                (yyval.stmtval)->breaklist = 0;
                                                emit(jump, nullptr, nullptr, newexpr_constnum(0));
                                        }
                                        fprintf(yyout, "[-] Reduced: stmt -> BREAK SEMICOLON\n");
                                }
#line 1896 "out/parser.tab.cpp"
    break;

  case 9: /* stmt: CONTINUE SEMICOLON  */
#line 196 "src/parser.y"
                                {       
                                        if (loopCounter == 0) {
                                                fprintf(yyout, "      [!] Error: Continue statement outside of loop in line %d.\n", yylineno);
                                                (yyval.stmtval) = new stmt_t;
                                        } else {
                                                (yyval.stmtval) = new stmt_t;
                                                (yyval.stmtval)->contlist = newlist(nextquad());
                                                (yyval.stmtval)->breaklist = 0;
                                                emit(jump, nullptr, nullptr, newexpr_constnum(0));
                                        }
                                        fprintf(yyout, "[-] Reduced: stmt -> CONTINUE SEMICOLON\n");
                                }
#line 1913 "out/parser.tab.cpp"
    break;

  case 10: /* stmt: block  */
#line 209 "src/parser.y"
                                {       
                                        (yyval.stmtval) = (yyvsp[0].stmtval);
                                        fprintf(yyout, "[-] Reduced: stmt -> block\n");
                                }
#line 1922 "out/parser.tab.cpp"
    break;

  case 11: /* stmt: funcdef  */
#line 214 "src/parser.y"
                                {
                                        (yyval.stmtval) = new stmt_t;
                                        (yyval.stmtval)->breaklist = 0;
                                        (yyval.stmtval)->contlist = 0;
                                        fprintf(yyout, "[-] Reduced: stmt -> funcdef\n");
                                }
#line 1933 "out/parser.tab.cpp"
    break;

  case 12: /* stmt: SEMICOLON  */
#line 221 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: stmt -> SEMICOLON\n");
                                }
#line 1941 "out/parser.tab.cpp"
    break;

  case 13: /* stmt: errors  */
#line 225 "src/parser.y"
                                {
                                        (yyval.stmtval) = new stmt_t;
                                        (yyval.stmtval)->breaklist = 0;
                                        (yyval.stmtval)->contlist = 0;
                                        fprintf(yyout, "[-] Reduced: stmt -> errors\n");
                                }
#line 1952 "out/parser.tab.cpp"
    break;

  case 14: /* stmt: error SEMICOLON  */
#line 233 "src/parser.y"
                                {       
                                        fprintf(yyout, "      [!] Error: Illegal statement in line %d.\n", yylineno);
                                        yyerrok;
                                        yyclearin;
                                }
#line 1962 "out/parser.tab.cpp"
    break;

  case 15: /* stmt_list: stmt stmt_list  */
#line 241 "src/parser.y"
                                {
                                        (yyval.stmtval) = new stmt_t;
                                        (yyval.stmtval)->breaklist = mergelist((yyvsp[-1].stmtval)->breaklist, (yyvsp[0].stmtval)->breaklist);
                                        (yyval.stmtval)->contlist = mergelist((yyvsp[-1].stmtval)->contlist, (yyvsp[0].stmtval)->contlist);
                                        fprintf(yyout, "[-] Reduced: stmt_list -> stmt stmt_list\n");
                                }
#line 1973 "out/parser.tab.cpp"
    break;

  case 16: /* stmt_list: %empty  */
#line 248 "src/parser.y"
                                {       
                                        (yyval.stmtval) = new stmt_t;
                                        (yyval.stmtval)->breaklist = 0;
                                        (yyval.stmtval)->contlist = 0;

                                        fprintf(yyout, "[-] Reduced: stmt_list -> /* empty */\n");
                                }
#line 1985 "out/parser.tab.cpp"
    break;

  case 17: /* expr: assignexpr  */
#line 257 "src/parser.y"
                                {       
                                        (yyval.expr) = (yyvsp[0].expr);
                                        fprintf(yyout, "[-] Reduced: expr -> assignexpr\n");
                                }
#line 1994 "out/parser.tab.cpp"
    break;

  case 18: /* expr: expr PLUS expr  */
#line 262 "src/parser.y"
                                {
                                        check_arith((yyvsp[-2].expr), "left operand of plus (+)");
                                        check_arith((yyvsp[0].expr), "right operand of plus (+)");

                                        if (istempexpr((yyvsp[-2].expr))) {
                                                emit(add, (yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-2].expr));
                                                /* release_temp($3); */
                                                (yyval.expr) = (yyvsp[-2].expr);
                                        } else {
                                                (yyval.expr) = newexpr(arithexpr_e);
                                                (yyval.expr)->sym = newtemp();
                                                emit(add, (yyvsp[-2].expr), (yyvsp[0].expr), (yyval.expr));
                                                /* if (istempexpr($1)) release_temp($1);
                                                if (istempexpr($3)) release_temp($3); */
                                        }
                                        fprintf(yyout, "[-] Reduced: expr -> expr PLUS expr1\n");
                                }
#line 2016 "out/parser.tab.cpp"
    break;

  case 19: /* expr: expr MINUS expr  */
#line 280 "src/parser.y"
                                {       
                                        check_arith((yyvsp[-2].expr), "left operand of minus (-)");
                                        check_arith((yyvsp[0].expr), "right operand of minus (-)");

                                        if (istempexpr((yyvsp[-2].expr))) {
                                                emit(sub, (yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-2].expr));
                                                (yyval.expr) = (yyvsp[-2].expr);
                                        } else {
                                                (yyval.expr) = newexpr(arithexpr_e);
                                                (yyval.expr)->sym = newtemp();
                                                emit(sub, (yyvsp[-2].expr), (yyvsp[0].expr), (yyval.expr));
                                        }
                                        fprintf(yyout, "[-] Reduced: expr -> expr MINUS expr\n");
                                }
#line 2035 "out/parser.tab.cpp"
    break;

  case 20: /* expr: expr MULTIPLY expr  */
#line 295 "src/parser.y"
                                {
                                        check_arith((yyvsp[-2].expr), "left operand of multiply (*)");
                                        check_arith((yyvsp[0].expr), "right operand of multiply (*)");

                                        if (istempexpr((yyvsp[-2].expr))) {
                                                emit(mul, (yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-2].expr));
                                                (yyval.expr) = (yyvsp[-2].expr);
                                        } else {
                                                (yyval.expr) = newexpr(arithexpr_e);
                                                (yyval.expr)->sym = newtemp();
                                                emit(mul, (yyvsp[-2].expr), (yyvsp[0].expr), (yyval.expr));
                                        }

                                        fprintf(yyout, "[-] Reduced: expr -> expr MULTIPLY expr\n");
                                }
#line 2055 "out/parser.tab.cpp"
    break;

  case 21: /* expr: expr DIVIDE expr  */
#line 311 "src/parser.y"
                                {       
                                        check_arith((yyvsp[-2].expr), "left operand of divide (/)");
                                        check_arith((yyvsp[0].expr), "right operand of divide (/)");

                                        if ((yyvsp[0].expr)->type == constnum_e && (yyvsp[0].expr)->numConst == 0) {
                                                fprintf(yyout, "      [!] Error: Division by zero in line %d.\n", yylineno);
                                                (yyval.expr) = newexpr(nil_e);
                                        } else if ((yyvsp[-2].expr)->type == constnum_e && (yyvsp[0].expr)->type == constnum_e) {
                                                (yyval.expr) = newexpr(constnum_e);
                                                (yyval.expr)->numConst = (yyvsp[-2].expr)->numConst / (yyvsp[0].expr)->numConst;
                                        } else if (istempexpr((yyvsp[-2].expr))) {
                                                emit(div_op, (yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-2].expr));
                                                (yyval.expr) = (yyvsp[-2].expr);
                                        } else {
                                                (yyval.expr) = newexpr(arithexpr_e);
                                                (yyval.expr)->sym = newtemp();
                                                emit(div_op, (yyvsp[-2].expr), (yyvsp[0].expr), (yyval.expr));
                                        }

                                        fprintf(yyout, "[-] Reduced: expr -> expr DIVIDE expr\n");
                                }
#line 2081 "out/parser.tab.cpp"
    break;

  case 22: /* expr: expr MODULO expr  */
#line 333 "src/parser.y"
                                {       
                                        check_arith((yyvsp[-2].expr), "left operand of modulo (%)");
                                        check_arith((yyvsp[0].expr), "right operand of modulo (%)");

                                        if ((yyvsp[0].expr)->type == constnum_e && (yyvsp[0].expr)->numConst == 0) {
                                                fprintf(yyout, "      [!] Error: Division by zero in line %d.\n", yylineno);
                                                (yyval.expr) = newexpr(nil_e);
                                        } else if ((yyvsp[-2].expr)->type == constnum_e && (yyvsp[0].expr)->type == constnum_e) {
                                                (yyval.expr) = newexpr(constnum_e);
                                                (yyval.expr)->numConst = (int)(yyvsp[-2].expr)->numConst % (int)(yyvsp[0].expr)->numConst;
                                        } else if (istempexpr((yyvsp[-2].expr))) {
                                                emit(mod, (yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-2].expr));
                                                (yyval.expr) = (yyvsp[-2].expr);
                                        } else {
                                                (yyval.expr) = newexpr(arithexpr_e);
                                                (yyval.expr)->sym = newtemp();
                                                emit(mod, (yyvsp[-2].expr), (yyvsp[0].expr), (yyval.expr));
                                        }

                                        fprintf(yyout, "[-] Reduced: expr -> expr MODULO expr\n");
                                }
#line 2107 "out/parser.tab.cpp"
    break;

  case 23: /* expr: expr GREATER_THAN expr  */
#line 355 "src/parser.y"
                                        {       
                                                if ((yyvsp[-2].expr)->type == constnum_e && (yyvsp[0].expr)->type == constnum_e) {
                                                        (yyval.expr) = newexpr(constbool_e);
                                                        (yyval.expr)->boolConst = (yyvsp[-2].expr)->numConst > (yyvsp[0].expr)->numConst;
                                                } else {
                                                        (yyval.expr) = newexpr(boolexpr_e);
                                                        (yyval.expr)->sym = newtemp();

                                                        emit(if_greater, (yyvsp[-2].expr), (yyvsp[0].expr), newexpr_constnum(nextquad() + 3));
                                                        emit(assign, newexpr_constbool(false), nullptr, (yyval.expr));
                                                        emit(jump, nullptr, nullptr, newexpr_constnum(nextquad() + 2));
                                                        emit(assign, newexpr_constbool(true), nullptr, (yyval.expr));
                                                }
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN expr\n");
                                        }
#line 2127 "out/parser.tab.cpp"
    break;

  case 24: /* expr: expr LESS_THAN expr  */
#line 371 "src/parser.y"
                                        {       
                                                if ((yyvsp[-2].expr)->type == constnum_e && (yyvsp[0].expr)->type == constnum_e) {
                                                        (yyval.expr) = newexpr(constbool_e);
                                                        (yyval.expr)->boolConst = (yyvsp[-2].expr)->numConst < (yyvsp[0].expr)->numConst;
                                                } else {
                                                        (yyval.expr) = newexpr(boolexpr_e);
                                                        (yyval.expr)->sym = newtemp();

                                                        emit(if_less, (yyvsp[-2].expr), (yyvsp[0].expr), newexpr_constnum(nextquad() + 3));
                                                        emit(assign, newexpr_constbool(false), nullptr, (yyval.expr));
                                                        emit(jump, nullptr, nullptr, newexpr_constnum(nextquad() + 2));
                                                        emit(assign, newexpr_constbool(true), nullptr, (yyval.expr));
                                                }
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN expr\n");
                                        }
#line 2147 "out/parser.tab.cpp"
    break;

  case 25: /* expr: expr GREATER_THAN_EQUAL expr  */
#line 387 "src/parser.y"
                                        {
                                                if ((yyvsp[-2].expr)->type == constnum_e && (yyvsp[0].expr)->type == constnum_e) {
                                                        (yyval.expr) = newexpr(constbool_e);
                                                        (yyval.expr)->boolConst = (yyvsp[-2].expr)->numConst >= (yyvsp[0].expr)->numConst;
                                                } else {
                                                        (yyval.expr) = newexpr(boolexpr_e);
                                                        (yyval.expr)->sym = newtemp();

                                                        emit(if_greatereq, (yyvsp[-2].expr), (yyvsp[0].expr), newexpr_constnum(nextquad() + 3));
                                                        emit(assign, newexpr_constbool(false), nullptr, (yyval.expr));
                                                        emit(jump, nullptr, nullptr, newexpr_constnum(nextquad() + 2));
                                                        emit(assign, newexpr_constbool(true), nullptr, (yyval.expr));
                                                }

                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN_EQUAL expr\n");
                                        }
#line 2168 "out/parser.tab.cpp"
    break;

  case 26: /* expr: expr LESS_THAN_EQUAL expr  */
#line 404 "src/parser.y"
                                        {
                                                if ((yyvsp[-2].expr)->type == constnum_e && (yyvsp[0].expr)->type == constnum_e) {
                                                        (yyval.expr) = newexpr(constbool_e);
                                                        (yyval.expr)->boolConst = (yyvsp[-2].expr)->numConst <= (yyvsp[0].expr)->numConst;
                                                } else {
                                                        (yyval.expr) = newexpr(boolexpr_e);
                                                        (yyval.expr)->sym = newtemp();

                                                        emit(if_lesseq, (yyvsp[-2].expr), (yyvsp[0].expr), newexpr_constnum(nextquad() + 3));
                                                        emit(assign, newexpr_constbool(false), nullptr, (yyval.expr));
                                                        emit(jump, nullptr, nullptr, newexpr_constnum(nextquad() + 2));
                                                        emit(assign, newexpr_constbool(true), nullptr, (yyval.expr));
                                                }

                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN_EQUAL expr\n");
                                        }
#line 2189 "out/parser.tab.cpp"
    break;

  case 27: /* expr: expr EQUAL expr  */
#line 421 "src/parser.y"
                                        {
                                                if ((yyvsp[-2].expr)->type == constnum_e && (yyvsp[0].expr)->type == constnum_e) {
                                                        (yyval.expr) = newexpr(constbool_e);
                                                        (yyval.expr)->boolConst = (yyvsp[-2].expr)->numConst == (yyvsp[0].expr)->numConst;
                                                } else {
                                                        (yyval.expr) = newexpr(boolexpr_e);
                                                        (yyval.expr)->sym = newtemp();

                                                        emit(if_eq, (yyvsp[-2].expr), (yyvsp[0].expr), newexpr_constnum(nextquad() + 3));
                                                        emit(assign, newexpr_constbool(false), nullptr, (yyval.expr));
                                                        emit(jump, nullptr, nullptr, newexpr_constnum(nextquad() + 2));
                                                        emit(assign, newexpr_constbool(true), nullptr, (yyval.expr));
                                                }

                                                fprintf(yyout, "[-] Reduced: expr -> expr EQUAL expr\n");
                                        }
#line 2210 "out/parser.tab.cpp"
    break;

  case 28: /* expr: expr NOT_EQUAL expr  */
#line 438 "src/parser.y"
                                        {
                                                if ((yyvsp[-2].expr)->type == constnum_e && (yyvsp[0].expr)->type == constnum_e) {
                                                        (yyval.expr) = newexpr(constbool_e);
                                                        (yyval.expr)->boolConst = (yyvsp[-2].expr)->numConst != (yyvsp[0].expr)->numConst;
                                                } else {
                                                        (yyval.expr) = newexpr(boolexpr_e);
                                                        (yyval.expr)->sym = newtemp();

                                                        emit(if_noteq, (yyvsp[-2].expr), (yyvsp[0].expr), newexpr_constnum(nextquad() + 3));
                                                        emit(assign, newexpr_constbool(false), nullptr, (yyval.expr));
                                                        emit(jump, nullptr, nullptr, newexpr_constnum(nextquad() + 2));
                                                        emit(assign, newexpr_constbool(true), nullptr, (yyval.expr));
                                                }

                                                fprintf(yyout, "[-] Reduced: expr -> expr NOT_EQUAL expr\n");
                                        }
#line 2231 "out/parser.tab.cpp"
    break;

  case 29: /* expr: expr AND expr  */
#line 455 "src/parser.y"
                                        {       
                                                expr* left = convert_to_bool((yyvsp[-2].expr));
                                                expr* right = convert_to_bool((yyvsp[0].expr));

                                                if (left->type == constbool_e && right->type == constbool_e) {
                                                        (yyval.expr) = newexpr(constbool_e);
                                                        (yyval.expr)->boolConst = left->boolConst && right->boolConst;
                                                } else {
                                                        (yyval.expr) = newexpr(boolexpr_e);
                                                        (yyval.expr)->sym = newtemp();

                                                        emit(and_op, left, right, (yyval.expr));
                                                }

                                                fprintf(yyout, "[-] Reduced: expr -> expr AND expr\n");
                                        }
#line 2252 "out/parser.tab.cpp"
    break;

  case 30: /* expr: expr OR expr  */
#line 472 "src/parser.y"
                                        {       
                                                expr* left = convert_to_bool((yyvsp[-2].expr));
                                                expr* right = convert_to_bool((yyvsp[0].expr));

                                                if (left->type == constbool_e && right->type == constbool_e) {
                                                        (yyval.expr) = newexpr(constbool_e);
                                                        (yyval.expr)->boolConst = left->boolConst || right->boolConst;
                                                } else {
                                                        (yyval.expr) = newexpr(boolexpr_e);
                                                        (yyval.expr)->sym = newtemp();

                                                        emit(or_op, left, right, (yyval.expr));
                                                }

                                                fprintf(yyout, "[-] Reduced: expr -> expr OR expr\n");
                                        }
#line 2273 "out/parser.tab.cpp"
    break;

  case 31: /* expr: term  */
#line 489 "src/parser.y"
                                        {       
                                                (yyval.expr) = (yyvsp[0].expr);
                                                fprintf(yyout, "[-] Reduced: expr -> term\n");
                                        }
#line 2282 "out/parser.tab.cpp"
    break;

  case 32: /* term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 495 "src/parser.y"
                                                {
                                                        (yyval.expr) = (yyvsp[-1].expr);
                                                        fprintf(yyout, "[-] Reduced: term -> LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                }
#line 2291 "out/parser.tab.cpp"
    break;

  case 33: /* term: MINUS expr  */
#line 500 "src/parser.y"
                                                {
                                                        check_arith((yyvsp[0].expr), "unary minus (-expr)");
                                                        (yyval.expr) = newexpr(arithexpr_e);
                                                        (yyval.expr)->sym = istempexpr((yyvsp[0].expr))? (yyvsp[0].expr)->sym : newtemp();
                                                        emit(uminus, (yyvsp[0].expr), nullptr, (yyval.expr));
                                                        fprintf(yyout, "[-] Reduced: term -> MINUS expr\n");
                                                }
#line 2303 "out/parser.tab.cpp"
    break;

  case 34: /* term: NOT expr  */
#line 508 "src/parser.y"
                                                { 
                                                        (yyval.expr) = newexpr(boolexpr_e);
                                                        (yyval.expr)->sym = newtemp();
                                                        emit(not_op, (yyvsp[0].expr), nullptr, (yyval.expr));
                                                        fprintf(yyout, "[-] Reduced: term -> NOT expr\n");
                                                }
#line 2314 "out/parser.tab.cpp"
    break;

  case 35: /* term: INCREMENT lvalue  */
#line 515 "src/parser.y"
                                                {       
                                                        check_arith((yyvsp[0].expr), "increment (nonlval++)");
                                                        if ((yyvsp[0].expr)->type == tableitem_e) {
                                                                (yyval.expr) = emit_iftableitem((yyvsp[0].expr));
                                                                emit(add, (yyval.expr), newexpr_constnum(1), (yyval.expr));
                                                                emit(tablesetelem, (yyvsp[0].expr), (yyvsp[0].expr)->index, (yyval.expr));
                                                        } else {
                                                                emit(add, (yyvsp[0].expr), newexpr_constnum(1), (yyvsp[0].expr));
                                                                (yyval.expr) = newexpr(arithexpr_e);
                                                                (yyval.expr)->sym = newtemp();
                                                                emit(assign, (yyvsp[0].expr), nullptr, (yyval.expr));
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> INCREMENT lvalue\n");
                                                }
#line 2333 "out/parser.tab.cpp"
    break;

  case 36: /* term: lvalue INCREMENT  */
#line 530 "src/parser.y"
                                                {       
                                                        check_arith((yyvsp[-1].expr), "increment (nonlval++)");
                                                        (yyval.expr) = newexpr(var_e);
                                                        (yyval.expr)->sym = newtemp();
                                                        if ((yyvsp[-1].expr)->type == tableitem_e) {
                                                                expr* val = emit_iftableitem((yyvsp[-1].expr));
                                                                emit(assign, val, nullptr, (yyvsp[-1].expr));
                                                                emit(add, val, newexpr_constnum(1), val);
                                                                emit(tablesetelem, (yyvsp[-1].expr), (yyvsp[-1].expr)->index, val);
                                                        } else {
                                                                emit(assign, (yyvsp[-1].expr), nullptr, (yyval.expr));
                                                                emit(add, (yyvsp[-1].expr), newexpr_constnum(1), (yyvsp[-1].expr));
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue INCREMENT\n");
                                                }
#line 2353 "out/parser.tab.cpp"
    break;

  case 37: /* term: DECREMENT lvalue  */
#line 546 "src/parser.y"
                                                {       
                                                        check_arith((yyvsp[0].expr), "decrement (nonlval--)");
                                                        if ((yyvsp[0].expr)->type == tableitem_e) {
                                                                (yyval.expr) = emit_iftableitem((yyvsp[0].expr));
                                                                emit(sub, (yyval.expr), newexpr_constnum(1), (yyval.expr));
                                                                emit(tablesetelem, (yyvsp[0].expr), (yyvsp[0].expr)->index, (yyval.expr));
                                                        } else {
                                                                emit(sub, (yyvsp[0].expr), newexpr_constnum(1), (yyvsp[0].expr));
                                                                (yyval.expr) = newexpr(arithexpr_e);
                                                                (yyval.expr)->sym = newtemp();
                                                                emit(assign, (yyvsp[0].expr), nullptr, (yyval.expr));
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> DECREMENT lvalue\n");
                                                }
#line 2372 "out/parser.tab.cpp"
    break;

  case 38: /* term: lvalue DECREMENT  */
#line 561 "src/parser.y"
                                                {
                                                        check_arith((yyvsp[-1].expr), "decrement (nonlval--)");
                                                        (yyval.expr) = newexpr(var_e);
                                                        (yyval.expr)->sym = newtemp();
                                                        if ((yyvsp[-1].expr)->type == tableitem_e) {
                                                                expr* val = emit_iftableitem((yyvsp[-1].expr));
                                                                emit(assign, val, nullptr, (yyvsp[-1].expr));
                                                                emit(sub, val, newexpr_constnum(1), val);
                                                                emit(tablesetelem, (yyvsp[-1].expr), (yyvsp[-1].expr)->index, val);
                                                        } else {
                                                                emit(assign, (yyvsp[-1].expr), nullptr, (yyval.expr));
                                                                emit(sub, (yyvsp[-1].expr), newexpr_constnum(1), (yyvsp[-1].expr));
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue DECREMENT\n");
                                                }
#line 2392 "out/parser.tab.cpp"
    break;

  case 39: /* term: primary  */
#line 577 "src/parser.y"
                                                {       
                                                        (yyval.expr) = (yyvsp[0].expr);
                                                        fprintf(yyout, "[-] Reduced: term -> primary\n");
                                                }
#line 2401 "out/parser.tab.cpp"
    break;

  case 40: /* assignexpr: lvalue ASSIGN expr  */
#line 583 "src/parser.y"
                                                { 
                                                        if ((yyvsp[-2].expr)->sym && (yyvsp[-2].expr)->sym->type == LIBFUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc = expr) in line %d.\n", yylineno);
                                                                (yyval.expr) = newexpr(nil_e);
                                                        } 
                                                                
                                                        if ((yyvsp[-2].expr)->sym && (yyvsp[-2].expr)->sym->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func = expr) in line %d.\n", yylineno);
                                                                (yyval.expr) = newexpr(nil_e);       
                                                        }

                                                        if ((yyvsp[-2].expr)->sym && (yyvsp[-2].expr)->sym->type == NONLVAL) {
                                                                fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval = expr) in line %d.\n", yylineno);
                                                                (yyval.expr) = newexpr(nil_e);
                                                        } else {
                                                                if ((yyvsp[-2].expr)->type == tableitem_e) {
                                                                        emit(tablesetelem, (yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-2].expr)->index);
                                                                        (yyval.expr) = emit_iftableitem((yyvsp[-2].expr));
                                                                        (yyval.expr)->type = assignexpr_e;
                                                                } else {
                                                                        emit(assign, (yyvsp[0].expr), nullptr, (yyvsp[-2].expr));
                                                                        expr* temp = newexpr_tmpvar(assignexpr_e);
                                                                        emit(assign, (yyvsp[-2].expr), nullptr, temp);
                                                                        (yyval.expr) = temp;
                                                                } 
                                                        }
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
                                                }
#line 2434 "out/parser.tab.cpp"
    break;

  case 41: /* assignexpr: lvalue PLUS_ASSIGN expr  */
#line 612 "src/parser.y"
                                                {       
                                                        if ((yyvsp[-2].expr)->sym && (yyvsp[-2].expr)->sym->type == LIBFUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc += expr) in line %d.\n", yylineno);
                                                                (yyval.expr) = newexpr(nil_e);
                                                        }
                                                        if ((yyvsp[-2].expr)->sym && (yyvsp[-2].expr)->sym->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func += expr) in line %d.\n", yylineno);
                                                                (yyval.expr) = newexpr(nil_e);
                                                        }
                                                        if ((yyvsp[-2].expr)->sym && (yyvsp[-2].expr)->sym->type == NONLVAL) {
                                                                fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval += expr) in line %d.\n", yylineno);
                                                                (yyval.expr) = newexpr(nil_e);
                                                        } else {
                                                                expr* lv = emit_iftableitem((yyvsp[-2].expr));
                                                                expr* temp = newexpr_tmpvar(arithexpr_e);
                                                                emit(add, temp, lv, (yyvsp[0].expr));

                                                                if ((yyvsp[-2].expr)->type == tableitem_e) {
                                                                emit(tablesetelem, (yyvsp[-2].expr), temp, (yyvsp[-2].expr)->index);
                                                                } else {
                                                                emit(assign, (yyvsp[-2].expr), temp, nullptr);                     
                                                                }

                                                                (yyval.expr) = (yyvsp[-2].expr);
                                                                (yyval.expr)->type = assignexpr_e; 
                                                        }
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue PLUS_ASSIGN expr\n");
                                                }
#line 2467 "out/parser.tab.cpp"
    break;

  case 42: /* assignexpr: lvalue MINUS_ASSIGN expr  */
#line 641 "src/parser.y"
                                                {
                                                        if ((yyvsp[-2].expr)->sym && (yyvsp[-2].expr)->sym->type == LIBFUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc -= expr) in line %d.\n", yylineno);
                                                                (yyval.expr) = newexpr(nil_e);
                                                        }
                                                        if ((yyvsp[-2].expr)->sym && (yyvsp[-2].expr)->sym->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func -= expr) in line %d.\n", yylineno);
                                                                (yyval.expr) = newexpr(nil_e);
                                                        }
                                                        if ((yyvsp[-2].expr)->sym && (yyvsp[-2].expr)->sym->type == NONLVAL) {
                                                                fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval -= expr) in line %d.\n", yylineno);
                                                                (yyval.expr) = newexpr(nil_e);
                                                        } else {
                                                                expr* lv = emit_iftableitem((yyvsp[-2].expr));               
                                                                expr* temp = newexpr_tmpvar(arithexpr_e);
                                                                emit(sub, temp, lv, (yyvsp[0].expr));

                                                                if ((yyvsp[-2].expr)->type == tableitem_e) {
                                                                emit(tablesetelem, (yyvsp[-2].expr), temp, (yyvsp[-2].expr)->index);    
                                                                } else {
                                                                emit(assign, (yyvsp[-2].expr), temp, nullptr);                     
                                                                }

                                                                (yyval.expr) = (yyvsp[-2].expr);
                                                                (yyval.expr)->type = assignexpr_e; 
                                                        }
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue MINUS_ASSIGN expr\n");
                                                }
#line 2500 "out/parser.tab.cpp"
    break;

  case 43: /* primary: lvalue  */
#line 671 "src/parser.y"
                                {       
                                        if ((yyvsp[0].expr)->type == tableitem_e && !(yyvsp[0].expr)->sym) {
                                                fprintf(stderr, "[!] Invalid table item lvalue at line %d\n", yylineno);
                                                (yyval.expr) = newexpr(nil_e);
                                        } else {
                                                (yyval.expr) = (yyvsp[0].expr);
                                        }
                                        fprintf(yyout, "[-] Reduced: primary -> lvalue\n");
                                }
#line 2514 "out/parser.tab.cpp"
    break;

  case 44: /* primary: call  */
#line 681 "src/parser.y"
                                {       
                                        if ((yyvsp[0].expr)->type == tableitem_e && !(yyvsp[0].expr)->sym) {
                                                fprintf(stderr, "[!] Invalid table item call at line %d\n", yylineno);
                                                (yyval.expr) = newexpr(nil_e);
                                        } else {
                                                (yyval.expr) = (yyvsp[0].expr);
                                        }
                                        fprintf(yyout, "[-] Reduced: primary -> call\n");
                                }
#line 2528 "out/parser.tab.cpp"
    break;

  case 45: /* primary: objectdef  */
#line 691 "src/parser.y"
                                {       
                                        (yyval.expr) = (yyvsp[0].expr);
                                        fprintf(yyout, "[-] Reduced: primary -> objectdef\n");
                                }
#line 2537 "out/parser.tab.cpp"
    break;

  case 46: /* primary: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS  */
#line 696 "src/parser.y"
                                                        {
                                                                (yyval.expr) = (yyvsp[-1].expr);
                                                                fprintf(yyout, "[-] Reduced: primary -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS\n");
                                                        }
#line 2546 "out/parser.tab.cpp"
    break;

  case 47: /* primary: const  */
#line 700 "src/parser.y"
                                {
                                        (yyval.expr) = (yyvsp[0].expr);
                                        fprintf(yyout, "[-] Reduced: primary -> const\n");
                                }
#line 2555 "out/parser.tab.cpp"
    break;

  case 48: /* lvalue: IDENTIFIER  */
#line 706 "src/parser.y"
                                {
                                        SymEntry* found = symTable.lookup((yyvsp[0].str_val));

                                        if (!found) {
                                                SymEntry* entry = new SymEntry;
                                                entry->name     = (yyvsp[0].str_val);
                                                entry->type     = VAR;
                                                entry->scope    = symTable.getScope();
                                                entry->line     = yylineno;
                                                entry->isActive = true;
                                                entry->isGlobal = (entry->scope == 0);
                                                entry->space    = symTable.currScopeSpace();
                                                entry->offset   = symTable.currScopeOffset();


                                                symTable.incCurrScopeOffset();
                                                symTable.insert(entry);

                                                (yyval.expr) = lvalue_expr(entry);
                                        } else if (found->type == LIBFUNC) {
                                                (yyval.expr) = newexpr(libraryfunc_e);
                                                (yyval.expr)->sym = found;
                                        } else if (found->type == VAR || found->type == FORARG) {
                                                if (symTable.funcStack.empty() || found->scope > symTable.funcStack.top()->scope || found->scope == 0) {
                                                        (yyval.expr) = lvalue_expr(found);
                                                } else {
                                                        fprintf(yyout, "      [!] Error: Variable %s is not active in line %d.\n", (yyvsp[0].str_val), yylineno);
                                                        (yyval.expr) = newexpr(nil_e);                                                
                                                }
                                        } else {
                                                (yyval.expr) = lvalue_expr(found);
                                        }
                                        fprintf(yyout, "[-] Reduced: lvalue -> IDENTIFIER\n");
                                }
#line 2594 "out/parser.tab.cpp"
    break;

  case 49: /* lvalue: LOCAL IDENTIFIER  */
#line 742 "src/parser.y"
                                {       
                                        SymEntry* found;
                                        if ((found = symTable.lookup((yyvsp[0].str_val), 0)) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Local variable is shadowing library function in line %d.\n", yylineno);
                                                (yyval.expr) = newexpr(nil_e);
                                        } else {
                                                found = symTable.lookup((yyvsp[0].str_val), symTable.getScope());

                                                if (found) {
                                                        (yyval.expr) = lvalue_expr(found);
                                                } else {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = (yyvsp[0].str_val);
                                                        entry->type = VAR;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;
                                                        entry->isGlobal = entry->scope == 0;
                                                        entry->space = symTable.currScopeSpace();
                                                        entry->offset = symTable.currScopeOffset();

                                                        symTable.incCurrScopeOffset();
                                                        symTable.insert(entry);
                                                        (yyval.expr) = lvalue_expr(entry);
                                                }
                                        } 
                                        fprintf(yyout, "[-] Reduced: lvalue -> LOCAL IDENTIFIER\n");
                                }
#line 2627 "out/parser.tab.cpp"
    break;

  case 50: /* lvalue: DOUBLE_COLON IDENTIFIER  */
#line 771 "src/parser.y"
                                        {       
                                                SymEntry* found = symTable.lookup((yyvsp[0].str_val), 0);
                                                if (!found) {
                                                        fprintf(yyout, "      [!] Error: Token %s has not been declared in global scope in line %d.\n", (yyvsp[0].str_val), yylineno);
                                                        (yyval.expr) = newexpr(nil_e);
                                                } else {
                                                        (yyval.expr) = lvalue_expr(found);
                                                }
                                                fprintf(yyout, "[-] Reduced: lvalue -> DOUBLE_COLON IDENTIFIER\n");
                                        }
#line 2642 "out/parser.tab.cpp"
    break;

  case 51: /* lvalue: member  */
#line 782 "src/parser.y"
                                        {       
                                                (yyval.expr) = (yyvsp[0].expr);
                                                fprintf(yyout, "[-] Reduced: lvalue -> member\n");
                                        }
#line 2651 "out/parser.tab.cpp"
    break;

  case 52: /* member: lvalue DOT IDENTIFIER  */
#line 788 "src/parser.y"
                                {       
                                        if (!(yyvsp[-2].expr) || !(yyvsp[-2].expr)->sym) {
                                                fprintf(stderr, "[!] member_item: NULL sym in lvalue\n");
                                                exit(1);
                                        }
                                        (yyval.expr) = member_item((yyvsp[-2].expr), (yyvsp[0].str_val));
                                        fprintf(yyout, "[-] Reduced: member -> lvalue DOT IDENTIFIER\n");
                                }
#line 2664 "out/parser.tab.cpp"
    break;

  case 53: /* member: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 797 "src/parser.y"
                                                        {
                                                                if (!(yyvsp[-3].expr) || !(yyvsp[-1].expr)) {
                                                                        fprintf(yyout, "      [!] member: null lvalue or index at line: %d\n", yylineno);
                                                                        (yyval.expr) = newexpr(nil_e);
                                                                } else {
                                                                        (yyvsp[-3].expr) = emit_iftableitem((yyvsp[-3].expr));
                                                                        (yyval.expr) = newexpr(tableitem_e);
                                                                        (yyval.expr)->sym = (yyvsp[-3].expr)->sym;
                                                                        (yyval.expr)->index = (yyvsp[-1].expr);
                                                                }
                                                                fprintf(yyout, "[-] Reduced: member -> lvalue LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }
#line 2681 "out/parser.tab.cpp"
    break;

  case 54: /* member: call DOT IDENTIFIER  */
#line 810 "src/parser.y"
                                                        {       
                                                                (yyval.expr) = member_item((yyvsp[-2].expr), (yyvsp[0].str_val));
                                                                fprintf(yyout, "[-] Reduced: member -> call DOT IDENTIFIER\n");
                                                        }
#line 2690 "out/parser.tab.cpp"
    break;

  case 55: /* member: call LEFT_BRACKET expr RIGHT_BRACKET  */
#line 815 "src/parser.y"
                                                        {
                                                                (yyval.expr) = newexpr(tableitem_e);
                                                                (yyvsp[-3].expr) = emit_iftableitem((yyvsp[-3].expr));
                                                                (yyval.expr)->sym = (yyvsp[-3].expr)->sym;
                                                                (yyval.expr)->index = (yyvsp[-1].expr);
                                                                
                                                                fprintf(yyout, "[-] Reduced: member -> call LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }
#line 2703 "out/parser.tab.cpp"
    break;

  case 56: /* call: call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 825 "src/parser.y"
                                                        {     
                                                                (yyval.expr) = make_call((yyvsp[-3].expr), (yyvsp[-1].expr)); 
                                                                fprintf(yyout, "[-] Reduced: call -> call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
#line 2712 "out/parser.tab.cpp"
    break;

  case 57: /* call: lvalue callsuffix  */
#line 830 "src/parser.y"
                                                        {
                                                                (yyvsp[-1].expr) = emit_iftableitem((yyvsp[-1].expr));

                                                                if ((yyvsp[0].callval)->method) {
                                                                        expr* temp = (yyvsp[-1].expr);
                                                                        (yyvsp[-1].expr) = emit_iftableitem(member_item((yyvsp[-1].expr), (yyvsp[0].callval)->name));
                                                                        (yyvsp[0].callval)->elist->next = temp;
                                                                }

                                                                (yyval.expr) = make_call((yyvsp[-1].expr), (yyvsp[0].callval)->elist);
                                                                fprintf(yyout, "[-] Reduced: call -> lvalue callsuffix\n");
                                                        }
#line 2729 "out/parser.tab.cpp"
    break;

  case 58: /* call: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 843 "src/parser.y"
                                                                                                {
                                                                                                        expr* func = newexpr(programfunc_e);
                                                                                                        func->sym = (yyvsp[-4].expr)->sym;
                                                                                                        (yyval.expr) = make_call(func, (yyvsp[-1].expr));
                                                                                                        fprintf(yyout, "[-] Reduced: call -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                }
#line 2740 "out/parser.tab.cpp"
    break;

  case 59: /* callsuffix: normcall  */
#line 851 "src/parser.y"
                                {       
                                        (yyval.callval) = new struct call;
                                        (yyval.callval) = (yyvsp[0].callval);
                                        fprintf(yyout, "[-] Reduced: callsuffix -> normcall\n");
                                }
#line 2750 "out/parser.tab.cpp"
    break;

  case 60: /* callsuffix: methodcall  */
#line 857 "src/parser.y"
                                {       
                                        (yyval.callval) = new struct call;
                                        (yyval.callval) = (yyvsp[0].callval);
                                        fprintf(yyout, "[-] Reduced: callsuffix -> methodcall\n");
                                }
#line 2760 "out/parser.tab.cpp"
    break;

  case 61: /* normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 864 "src/parser.y"
                                                        {       
                                                                (yyval.callval) = new struct call;
                                                                (yyval.callval)->elist = (yyvsp[-1].expr);
                                                                (yyval.callval)->name = nullptr;
                                                                (yyval.callval)->method = 0;
                                                                fprintf(yyout, "[-] Reduced: normcall -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
#line 2772 "out/parser.tab.cpp"
    break;

  case 62: /* methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 873 "src/parser.y"
                                                                                {       
                                                                                        (yyval.callval)->elist = (yyvsp[-1].expr);
                                                                                        (yyval.callval)->name = (yyvsp[-3].str_val);
                                                                                        (yyval.callval)->method = 1;
                                                                                        fprintf(yyout, "[-] Reduced: methodcall -> DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                }
#line 2783 "out/parser.tab.cpp"
    break;

  case 63: /* elist: expr  */
#line 881 "src/parser.y"
                                {       
                                        expr *e = (yyvsp[0].expr);
                                        if (!e) fprintf(yyout, "      [!] Error: elist -> expr is null\n");
                                        (yyval.expr) = e;
                                        fprintf(yyout, "[-] Reduced: elist -> expr\n");
                                }
#line 2794 "out/parser.tab.cpp"
    break;

  case 64: /* elist: elist COMMA expr  */
#line 888 "src/parser.y"
                                {       
                                        (yyval.expr) = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> expr COMMA elist\n");
                                }
#line 2803 "out/parser.tab.cpp"
    break;

  case 65: /* elist: %empty  */
#line 893 "src/parser.y"
                                {       
                                        (yyval.expr) = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> /* empty */\n");
                                }
#line 2812 "out/parser.tab.cpp"
    break;

  case 66: /* objectdef: LEFT_BRACKET elist RIGHT_BRACKET  */
#line 899 "src/parser.y"
                                                {       
                                                        expr* obj = newexpr(newtable_e);
                                                        obj->sym = newtemp();
                                                        emit(tablecreate, obj, nullptr, nullptr);
                                                        for (int i = 0; (yyvsp[-1].expr); (yyvsp[-1].expr) = (yyvsp[-1].expr)->next) {
                                                                emit(tablesetelem, obj, newexpr_constnum(i++), (yyvsp[-1].expr));
                                                        }
                                                        (yyval.expr) = obj;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET elist RIGHT_BRACKET\n");
                                                }
#line 2827 "out/parser.tab.cpp"
    break;

  case 67: /* objectdef: LEFT_BRACKET indexed RIGHT_BRACKET  */
#line 910 "src/parser.y"
                                                {       
                                                        expr* obj = newexpr(newtable_e);
                                                        obj->sym = newtemp();
                                                        emit(tablecreate, obj, nullptr, nullptr);
                                                        for (indexed* p = (yyvsp[-1].indexed); p; p = p->next) {
                                                                emit(tablesetelem, obj, p->key, p->value);
                                                        }
                                                        (yyval.expr) = obj;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET indexed RIGHT_BRACKET\n");
                                                }
#line 2842 "out/parser.tab.cpp"
    break;

  case 68: /* indexed: indexedelem  */
#line 922 "src/parser.y"
                                                {
                                                        (yyval.indexed) = (yyvsp[0].indexed);
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexedelem\n");
                                                }
#line 2851 "out/parser.tab.cpp"
    break;

  case 69: /* indexed: indexed COMMA indexedelem  */
#line 927 "src/parser.y"
                                                {
                                                        (yyvsp[0].indexed)->next = (yyvsp[-2].indexed);
                                                        (yyval.indexed) = (yyvsp[0].indexed);
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexed COMMA indexedelem\n");
                                                }
#line 2861 "out/parser.tab.cpp"
    break;

  case 70: /* indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE  */
#line 934 "src/parser.y"
                                                        {
                                                                indexed* i = new indexed;
                                                                i->key = (yyvsp[-3].expr);
                                                                i->value = (yyvsp[-1].expr);
                                                                i->next = nullptr;
                                                                (yyval.indexed) = i;
                                                                fprintf(yyout, "[-] Reduced: indexedelem -> LEFT_BRACE expr COLON expr RIGHT_BRACE\n");
                                                        }
#line 2874 "out/parser.tab.cpp"
    break;

  case 71: /* $@1: %empty  */
#line 944 "src/parser.y"
                        { 
                                if (skipBlockScope) {
                                        skipBlockScope = false;
                                } else {
                                        symTable.enter_scope();
                                }
                        }
#line 2886 "out/parser.tab.cpp"
    break;

  case 72: /* block: LEFT_BRACE $@1 stmt_list RIGHT_BRACE  */
#line 950 "src/parser.y"
                                                {
                                                        symTable.exit_scope();   
                                                        (yyval.stmtval) = (yyvsp[-1].stmtval);
                                                        fprintf(yyout, "[-] Reduced: block -> LEFT_BRACE stmt_list RIGHT_BRACE\n");
                                                }
#line 2896 "out/parser.tab.cpp"
    break;

  case 73: /* funcblockstart: %empty  */
#line 957 "src/parser.y"
                         {
                                loopStack.push(loopCounter);
                                loopCounter = 0;
                        }
#line 2905 "out/parser.tab.cpp"
    break;

  case 74: /* funcblockend: %empty  */
#line 962 "src/parser.y"
                         {
                                loopCounter = loopStack.top();
                                loopStack.pop();
                        }
#line 2914 "out/parser.tab.cpp"
    break;

  case 75: /* $@2: %empty  */
#line 967 "src/parser.y"
                                                {
                                                        SymEntry* found = symTable.lookup((yyvsp[-1].str_val), 0);
                                                        SymEntry* entry = nullptr;

                                                        if (found && found->type == LIBFUNC) {
                                                                fprintf(yyout, "      [!] Error : Function shadowing library function in line %d.\n", yylineno);
                                                        } else {
                                                                found = symTable.lookup((yyvsp[-1].str_val), symTable.getScope());

                                                                if (!found) {
                                                                        entry = new SymEntry;
                                                                        entry->name = (yyvsp[-1].str_val);
                                                                        entry->type = FUNC;
                                                                        entry->scope = symTable.getScope();
                                                                        entry->line = yylineno;
                                                                        entry->isActive = true;

                                                                        symTable.funcStack.push(entry);
                                                                        entry->args.clear();
                                                                        symTable.insert(entry);
                                                                } else {
                                                                        if (found->type == FUNC) {
                                                                                fprintf(yyout, "      [!] Error: Function %s already declared in line %d.\n", (yyvsp[-1].str_val), yylineno);
                                                                        }
                                                                        
                                                                        if (found->type == VAR) {
                                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing variable in line %d.\n", (yyvsp[-1].str_val), yylineno);
                                                                        }
                                                                        
                                                                        if (found->type == FORARG) {
                                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing formal argument in line %d.\n", (yyvsp[-1].str_val), yylineno);
                                                                        }
                                                                }

                                                                symTable.scopeOffsetStack.push(symTable.currScopeOffset());
                                                                symTable.enterScopeSpace();
                                                                symTable.resetFormalsOff();

                                                                symTable.enter_scope();
                                                                skipBlockScope = true;
                                                                entryFuncDef = entry;
                                                        }
                                                }
#line 2962 "out/parser.tab.cpp"
    break;

  case 76: /* $@3: %empty  */
#line 1009 "src/parser.y"
                                                                                {
                                                                                        symTable.exitScopeSpace();
                                                                                        symTable.enterScopeSpace();
                                                                                        symTable.resetFuncLocalsOff();
                                                                                }
#line 2972 "out/parser.tab.cpp"
    break;

  case 77: /* funcdef: FUNCTION IDENTIFIER LEFT_PARENTHESIS $@2 idlist RIGHT_PARENTHESIS $@3 funcblockstart block funcblockend  */
#line 1013 "src/parser.y"
                                                                                                                   {
                                                                                        if (!symTable.funcStack.empty()) {
                                                                                                symTable.funcStack.pop();
                                                                                        } 

                                                                                        symTable.restoreCurrScopeOffset(symTable.top_pop(symTable.scopeOffsetStack));
                                                                                        symTable.exitScopeSpace();

                                                                                        if (entryFuncDef) {
                                                                                                emit(funcend, lvalue_expr(entryFuncDef), nullptr, nullptr);
                                                                                                (yyval.expr) = lvalue_expr(entryFuncDef);
                                                                                                (yyval.expr)->type = programfunc_e;
                                                                                        } else {
                                                                                                (yyval.expr) = newexpr(nil_e);
                                                                                        }
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION IDENTIFIER LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
#line 2994 "out/parser.tab.cpp"
    break;

  case 78: /* $@4: %empty  */
#line 1031 "src/parser.y"
                                        {
                                                SymEntry* entry = new SymEntry;

                                                entry->name = generateAnonymousName();
                                                entry->type = FUNC;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;
                                                entry->args.clear();

                                                symTable.funcStack.push(entry);

                                                symTable.insert(entry);
                                                entryFuncDef = entry;

                                                symTable.scopeOffsetStack.push(symTable.currScopeOffset());
                                                symTable.enterScopeSpace();
                                                symTable.resetFormalsOff();


                                                symTable.enter_scope();
                                                skipBlockScope = true;
                                        }
#line 3022 "out/parser.tab.cpp"
    break;

  case 79: /* $@5: %empty  */
#line 1053 "src/parser.y"
                                                                        {
                                                                                symTable.exitScopeSpace();           
                                                                                symTable.enterScopeSpace();          
                                                                                symTable.resetFuncLocalsOff();  
                                                                        }
#line 3032 "out/parser.tab.cpp"
    break;

  case 80: /* funcdef: FUNCTION LEFT_PARENTHESIS $@4 idlist RIGHT_PARENTHESIS $@5 funcblockstart block funcblockend  */
#line 1057 "src/parser.y"
                                                                                                            {       
                                                                                        symTable.funcStack.pop();
                                                                                        symTable.restoreCurrScopeOffset(symTable.top_pop(symTable.scopeOffsetStack));
                                                                                        symTable.exitScopeSpace();
                                                                                        (yyval.expr) = lvalue_expr(entryFuncDef);
                                                                                        (yyval.expr)->type = programfunc_e;
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
#line 3045 "out/parser.tab.cpp"
    break;

  case 81: /* const: INTEGER  */
#line 1068 "src/parser.y"
                        {       
                                (yyval.expr) = newexpr_constnum(yylval.int_val);
                                (yyval.expr)->type = constnum_e; 
                                fprintf(yyout, "[-] Reduced: const -> INTEGER\n");
                        }
#line 3055 "out/parser.tab.cpp"
    break;

  case 82: /* const: REAL  */
#line 1074 "src/parser.y"
                        {       
                                (yyval.expr) = newexpr_constnum(yylval.float_val);
                                (yyval.expr)->type = constnum_e; 
                                fprintf(yyout, "[-] Reduced: const -> REAL\n");
                        }
#line 3065 "out/parser.tab.cpp"
    break;

  case 83: /* const: STRINGT  */
#line 1080 "src/parser.y"
                        {       
                                (yyval.expr) = newexpr_conststring(yylval.str_val);
                                (yyval.expr)->type = conststring_e;
                                fprintf(yyout, "[-] Reduced: const -> STRING\n");
                        }
#line 3075 "out/parser.tab.cpp"
    break;

  case 84: /* const: TRUE  */
#line 1086 "src/parser.y"
                        {       
                                (yyval.expr) = newexpr_constbool(true);
                                (yyval.expr)->type = constbool_e;
                                (yyval.expr)->boolConst = true;
                                fprintf(yyout, "[-] Reduced: const -> TRUE\n");
                        }
#line 3086 "out/parser.tab.cpp"
    break;

  case 85: /* const: FALSE  */
#line 1093 "src/parser.y"
                        {       
                                (yyval.expr) = newexpr_constbool(false);
                                (yyval.expr)->type = constbool_e;
                                (yyval.expr)->boolConst = false;
                                fprintf(yyout, "[-] Reduced: const -> FALSE\n");
                        }
#line 3097 "out/parser.tab.cpp"
    break;

  case 86: /* const: NIL  */
#line 1100 "src/parser.y"
                        {
                                (yyval.expr) = newexpr(nil_e);
                                fprintf(yyout, "[-] Reduced: const -> NIL\n");
                        }
#line 3106 "out/parser.tab.cpp"
    break;

  case 87: /* idlist: IDENTIFIER  */
#line 1106 "src/parser.y"
                        {       
                                SymEntry* found;

                                if ((found = symTable.lookup((yyvsp[0].str_val), 0)) && found->type == LIBFUNC) {
                                        fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);

                                        (yyval.expr) = newexpr(nil_e);
                                } else {
                                        if ((found = symTable.lookup((yyvsp[0].str_val), symTable.getScope()))) {
                                                if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                                (yyval.expr) = lvalue_expr(found);
                                        } else {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = (yyvsp[0].str_val);
                                                entry->type = FORARG;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;

                                                entry->isGlobal = entry->scope == 0 ? true : false;
                                                entry->space = symTable.currScopeSpace();
                                                entry->offset = symTable.currScopeOffset();
                                                symTable.incCurrScopeOffset();

                                                symTable.insert(entry);

                                                if (!symTable.funcStack.empty() && symTable.funcStack.top()->scope == entry->scope - 1) {
                                                        symTable.funcStack.top()->args.push_back(entry);
                                                }  
                                                (yyval.expr) = lvalue_expr(entry);
                                        }
                                }
                                fprintf(yyout, "[-] Reduced: idlist -> IDENTIFIER\n");
                        }
#line 3145 "out/parser.tab.cpp"
    break;

  case 88: /* idlist: idlist COMMA IDENTIFIER  */
#line 1140 "src/parser.y"
                                    {   
                                        SymEntry* found;

                                        if ((found = symTable.lookup((yyvsp[0].str_val), 0)) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);
                                                (yyval.expr) = newexpr(nil_e);
                                        } else {
                                                if ((found = symTable.lookup((yyvsp[0].str_val), symTable.getScope()))) {
                                                        if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                                        (yyval.expr) = lvalue_expr(found);
                                                } else {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = (yyvsp[0].str_val);
                                                        entry->type = FORARG;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;

                                                        entry->isGlobal = entry->scope == 0 ? true : false;
                                                        entry->space = symTable.currScopeSpace();
                                                        entry->offset = symTable.currScopeOffset();
                                                        symTable.incCurrScopeOffset();

                                                        symTable.insert(entry);

                                                        if (!symTable.funcStack.empty() && symTable.funcStack.top()->scope == entry->scope - 1) {
                                                                symTable.funcStack.top()->args.push_back(entry);
                                                        }  
                                                        (yyval.expr) = lvalue_expr(entry);
                                                        
                                                }
                                        }
                                        fprintf(yyout, "[-] Reduced: idlist -> idlist COMMA IDENTIFIER\n");
                                    }
#line 3184 "out/parser.tab.cpp"
    break;

  case 89: /* idlist: %empty  */
#line 1174 "src/parser.y"
                                {
                                        (yyval.expr) = nullptr;
                                        fprintf(yyout, "[-] Reduced: idlist -> /* empty */\n");
                                }
#line 3193 "out/parser.tab.cpp"
    break;

  case 90: /* ifprefix: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 1180 "src/parser.y"
                                                        {
                                                                expr* cond = convert_to_bool((yyvsp[-1].expr));

                                                                emit(if_eq, cond, newexpr_constbool(true), newexpr_constnum(nextquad() + 2));

                                                                (yyval.int_val) = nextquad();
                                                                emit(jump, nullptr, nullptr, newexpr_constnum(0));
                                                        }
#line 3206 "out/parser.tab.cpp"
    break;

  case 91: /* elseprefix: ELSE  */
#line 1189 "src/parser.y"
                        {
                                (yyval.int_val) = nextquad();
                                emit(jump, nullptr, nullptr, newexpr_constnum(0));
                        }
#line 3215 "out/parser.tab.cpp"
    break;

  case 92: /* ifstmt: ifprefix stmt  */
#line 1195 "src/parser.y"
                                            {
                                patchlabel((yyvsp[-1].int_val), nextquad()); 
                                (yyval.stmtval) = nullptr;
                                fprintf(yyout, "[-] Reduced: ifstmt -> IF (...) stmt\n");
                        }
#line 3225 "out/parser.tab.cpp"
    break;

  case 93: /* ifstmt: ifprefix stmt elseprefix stmt  */
#line 1201 "src/parser.y"
                                        {
                                                patchlabel((yyvsp[-3].int_val), (yyvsp[-1].int_val) + 1);
                                                patchlabel((yyvsp[-1].int_val), nextquad());
                                                (yyval.stmtval) = nullptr; 
                                                fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");
                                        }
#line 3236 "out/parser.tab.cpp"
    break;

  case 94: /* loopstart: %empty  */
#line 1209 "src/parser.y"
                        {
                                ++loopCounter;
                        }
#line 3244 "out/parser.tab.cpp"
    break;

  case 95: /* loopend: %empty  */
#line 1213 "src/parser.y"
                         {
                                --loopCounter;
                        }
#line 3252 "out/parser.tab.cpp"
    break;

  case 96: /* loopstmt: loopstart stmt loopend  */
#line 1216 "src/parser.y"
                                        {
                                                (yyval.stmtval) = (yyvsp[-1].stmtval);
                                        }
#line 3260 "out/parser.tab.cpp"
    break;

  case 97: /* whilestart: WHILE  */
#line 1220 "src/parser.y"
                        {
                                (yyval.int_val) = nextquad();
                        }
#line 3268 "out/parser.tab.cpp"
    break;

  case 98: /* whilecond: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 1224 "src/parser.y"
                                                        {
                                                                expr* cond = convert_to_bool((yyvsp[-1].expr));

                                                                emit(if_eq, cond, newexpr_constbool(true), newexpr_constnum(nextquad() + 2));

                                                                (yyval.int_val) = nextquad();
                                                                emit(jump, nullptr, nullptr, newexpr_constnum(0));
                                                        }
#line 3281 "out/parser.tab.cpp"
    break;

  case 99: /* whilestmt: whilestart whilecond loopstmt  */
#line 1233 "src/parser.y"
                                            {
                                                emit(jump, nullptr, nullptr, newexpr_constnum((yyvsp[-1].int_val)));
                                                
                                                patchlabel((yyvsp[-2].int_val), nextquad());


                                                patchlist((yyvsp[0].stmtval)->breaklist, nextquad());
                                                patchlist((yyvsp[0].stmtval)->contlist, (yyvsp[-2].int_val));

                                                (yyval.stmtval) = nullptr;

                                                fprintf(yyout, "[-] Reduced: whilestmt -> WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                        }
#line 3299 "out/parser.tab.cpp"
    break;

  case 100: /* N: %empty  */
#line 1248 "src/parser.y"
        {
                (yyval.int_val) = nextquad();
                emit(jump, nullptr, nullptr, newexpr_constnum(0));
        }
#line 3308 "out/parser.tab.cpp"
    break;

  case 101: /* M: %empty  */
#line 1254 "src/parser.y"
        {
                (yyval.int_val) = nextquad();
        }
#line 3316 "out/parser.tab.cpp"
    break;

  case 102: /* forprefix: FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON  */
#line 1259 "src/parser.y"
                                                                {       
                                                                        (yyval.forprefix) = new struct forprefix;
                                                                        (yyval.forprefix)->test = nextquad();

                                                                        expr* cond = convert_to_bool((yyvsp[-1].expr));
                                                                        emit(if_eq, cond, newexpr_constbool(true), newexpr_constnum(0));

                                                                        (yyval.forprefix)->enter = nextquad();
                                                                        emit(jump, nullptr, nullptr, newexpr_constnum(0));
                                                                }
#line 3331 "out/parser.tab.cpp"
    break;

  case 103: /* forstmt: forprefix N elist RIGHT_PARENTHESIS N loopstmt M  */
#line 1272 "src/parser.y"
                                                            {
                                                               emit(jump, nullptr, nullptr, newexpr_constnum((yyvsp[-6].forprefix)->test));
                                                               
                                                                patchlabel((yyvsp[-6].forprefix)->enter, (yyvsp[-2].int_val) + 1);
                                                                patchlabel((yyvsp[-5].int_val), nextquad());
                                                                patchlabel((yyvsp[-2].int_val), (yyvsp[-6].forprefix)->test);
                                                                patchlabel((yyvsp[0].int_val), (yyvsp[-2].int_val) + 1);

                                                                patchlist((yyvsp[-1].stmtval)->breaklist, nextquad());
                                                                patchlist((yyvsp[-1].stmtval)->contlist, (yyvsp[-6].forprefix)->test);

                                                                (yyval.stmtval) = new stmt_t;
                                                                (yyval.stmtval)->breaklist = (yyvsp[-1].stmtval)->breaklist;
                                                                (yyval.stmtval)->contlist = (yyvsp[-1].stmtval)->contlist;
                                                                fprintf(yyout, "[-] Reduced: forstmt -> FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON N elist RIGHT_PARENTHESIS N stmt M\n");
                                                        }
#line 3352 "out/parser.tab.cpp"
    break;

  case 104: /* returnstmt: RETURN expr SEMICOLON  */
#line 1290 "src/parser.y"
                                        {
                                                emit(getretval, nullptr, nullptr, (yyvsp[-1].expr));
                                                (yyval.stmtval) = new stmt_t;
                                                (yyval.stmtval)->breaklist = 0;
                                                (yyval.stmtval)->contlist = 0;
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN expr SEMICOLON\n");
                                        }
#line 3364 "out/parser.tab.cpp"
    break;

  case 105: /* returnstmt: RETURN SEMICOLON  */
#line 1297 "src/parser.y"
                                        {       
                                                emit(getretval, nullptr, nullptr, nullptr);
                                                (yyval.stmtval) = new stmt_t;
                                                (yyval.stmtval)->breaklist = 0;
                                                (yyval.stmtval)->contlist = 0;
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN SEMICOLON\n");
                                        }
#line 3376 "out/parser.tab.cpp"
    break;

  case 106: /* errors: ERROR_COMMENT  */
#line 1306 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_COMMENT\n");
                                fprintf(yyout, "      [!] Error: Invalid comment in line %d.\n", yylineno);
                                exit(1);
                        }
#line 3386 "out/parser.tab.cpp"
    break;

  case 107: /* errors: ERROR_STRING  */
#line 1312 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_STRING\n");
                                fprintf(yyout, "      [!] Error: Invalid string in line %d.\n", yylineno);
                                exit(1);
                        }
#line 3396 "out/parser.tab.cpp"
    break;

  case 108: /* errors: ERROR_ESCAPE  */
#line 1318 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_ESCAPE\n");
                                fprintf(yyout, "      [!] Error: Invalid escape sequence in line %d.\n", yylineno);
                                exit(1);
                        }
#line 3406 "out/parser.tab.cpp"
    break;

  case 109: /* errors: UNDEF  */
#line 1324 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> UNDEF\n");
                                fprintf(yyout, "      [!] Error: Undefined variable in line %d.\n", yylineno);    
                                exit(1);
                        }
#line 3416 "out/parser.tab.cpp"
    break;


#line 3420 "out/parser.tab.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1330 "src/parser.y"


int yyerror(const char *msg) {
    fprintf(stderr, "      [Line %d] Syntax error: %s (near token: \"%s\")\n", yylineno, msg, yytext);
    return 0;
}
