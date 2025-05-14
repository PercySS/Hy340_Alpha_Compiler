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

extern SymbolTable symTable;
extern bool skipBlockScope;
extern int rabbitHole;
extern int yylex();
extern char* yytext;
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
int yyerror(const char* msg);

// Global variables
SymEntry* entryFuncDef = nullptr;

#line 94 "out/parser.tab.cpp"

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
  YYSYMBOL_funcdef = 76,                   /* funcdef  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_78_3 = 78,                      /* $@3  */
  YYSYMBOL_const = 79,                     /* const  */
  YYSYMBOL_idlist = 80,                    /* idlist  */
  YYSYMBOL_ifstmt = 81,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 82,                 /* whilestmt  */
  YYSYMBOL_83_4 = 83,                      /* $@4  */
  YYSYMBOL_forstmt = 84,                   /* forstmt  */
  YYSYMBOL_85_5 = 85,                      /* $@5  */
  YYSYMBOL_returnstmt = 86,                /* returnstmt  */
  YYSYMBOL_errors = 87                     /* errors  */
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
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   729

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

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
       0,   133,   133,   139,   143,   148,   153,   158,   164,   172,
     180,   185,   190,   197,   203,   211,   216,   222,   227,   234,
     241,   248,   255,   262,   269,   276,   283,   290,   297,   304,
     311,   318,   326,   331,   336,   341,   351,   361,   371,   381,
     387,   397,   407,   418,   423,   430,   435,   439,   445,   481,
     505,   518,   524,   531,   538,   545,   553,   560,   565,   573,
     580,   588,   596,   604,   609,   614,   620,   627,   635,   640,
     646,   652,   652,   667,   667,   715,   715,   739,   744,   749,
     754,   759,   764,   770,   798,   826,   834,   839,   845,   845,
     854,   854,   863,   867,   873,   882,   891,   900
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
  "indexedelem", "block", "$@1", "funcdef", "$@2", "$@3", "const",
  "idlist", "ifstmt", "whilestmt", "$@4", "forstmt", "$@5", "returnstmt",
  "errors", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-162)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     203,     4,   473,    -7,    -7,  -162,   -48,   353,  -162,   393,
      19,    26,    35,   -11,   433,    23,    53,  -162,  -162,  -162,
      24,   473,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
      99,   148,  -162,    22,  -162,  -162,  -162,   356,  -162,    38,
    -162,  -162,  -162,  -162,    68,  -162,  -162,  -162,  -162,  -162,
    -162,    71,    25,    38,    25,  -162,   114,    82,   257,   473,
     663,   -14,    17,  -162,   473,  -162,  -162,  -162,    84,  -162,
     125,  -162,  -162,  -162,  -162,  -162,  -162,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,  -162,   473,
     473,  -162,  -162,   473,   473,   473,    61,    62,   473,   473,
    -162,  -162,  -162,    63,   473,   473,   311,    88,  -162,   116,
     111,   521,   473,  -162,   115,  -162,   540,   473,   473,    93,
    -162,  -162,    15,    15,  -162,  -162,  -162,   205,   205,   205,
     205,   689,   689,   716,   674,   663,   663,   663,  -162,   121,
     -17,   551,  -162,    20,   566,  -162,   116,   473,  -162,   473,
     663,  -162,   311,   595,    36,  -162,    32,    93,   473,  -162,
    -162,  -162,  -162,    45,   619,  -162,   311,   473,   100,   124,
      69,    74,  -162,  -162,  -162,   645,  -162,  -162,   124,  -162,
     473,  -162,    78,   311,  -162
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    12,     0,     0,    71,    65,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
       0,     0,    77,    78,    79,    48,    94,    95,    96,    97,
       0,     0,     2,     0,    31,    17,    39,    43,    51,    44,
      45,    10,    11,    47,     4,     5,     6,     7,    13,    14,
      33,     0,    35,     0,    37,    50,     0,     0,     0,     0,
      63,     0,     0,    68,     0,    88,    90,    75,     0,    93,
       0,     8,     9,    49,    34,     1,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,    36,    38,     0,     0,     0,     0,     0,    65,     0,
      57,    59,    60,     0,    65,     0,     0,     0,    32,    46,
       0,     0,     0,    66,     0,    67,     0,     0,    65,    85,
      73,    92,    18,    19,    20,    21,    22,    24,    26,    23,
      25,    27,    28,    29,    30,    40,    41,    42,    52,     0,
       0,     0,    54,     0,     0,    87,     0,    65,    72,     0,
      64,    69,     0,     0,     0,    83,     0,    85,    65,    61,
      53,    56,    55,     0,     0,    86,     0,     0,     0,     0,
       0,     0,    58,    70,    89,     0,    84,    76,     0,    62,
      65,    74,     0,     0,    91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,   -93,   -20,    -2,  -162,  -162,  -162,    66,  -162,
     102,  -162,  -162,  -162,   -94,  -162,  -162,    39,  -161,  -162,
      -6,  -162,  -162,  -162,    -3,  -162,  -162,  -162,  -162,  -162,
    -162,  -162
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   100,   101,   102,    61,    40,    62,    63,    41,    58,
      42,   157,   119,    43,   156,    44,    45,   117,    46,   118,
      47,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    57,    55,   112,   140,    56,   112,    60,   177,   159,
     143,    76,    70,   145,    67,     6,   113,   181,    51,    74,
      79,    80,    81,    49,   154,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    20,   114,   110,    68,
     112,    88,    71,    25,    64,   107,   161,   115,    96,    97,
      98,    65,   168,   163,    99,   167,   112,   111,   169,   165,
      66,   103,   116,   104,   171,   112,    89,   105,    90,    52,
      54,   172,    72,   174,    73,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   182,   133,   134,   168,
     184,   135,   136,   137,   112,   178,    60,   141,   112,    75,
     179,   106,    60,   144,   183,    53,    53,    13,   109,   120,
     150,   138,   139,   142,   146,   153,    60,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   148,
     108,   147,    59,   155,   121,    60,   158,   164,   -16,     1,
     176,     8,     2,   151,   170,     0,    60,     0,    89,     0,
      90,     0,     3,     4,     0,   175,     0,     5,     0,    89,
       6,    90,     0,     7,     0,     8,   -16,     9,    60,     0,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,    21,     0,    22,    23,    24,    25,    26,
      27,    28,    29,   -16,     1,     0,     0,     2,    77,    78,
      79,    80,    81,   -17,   -17,   -17,   -17,     3,     4,     0,
       0,     0,     5,     0,     0,     6,     0,     0,     7,     0,
       8,     0,     9,     0,     0,    10,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,     1,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     0,     0,     0,     5,     0,     0,     6,
       0,     0,     7,     0,     8,   -16,     9,     0,     0,    10,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,    21,     0,    22,    23,    24,    25,    26,    27,
      28,    29,     1,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     0,     0,     0,
       5,     0,     0,     6,     0,     0,     7,     0,     8,     0,
       9,     0,     0,    10,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,     2,    22,    23,
      24,    25,    26,    27,    28,    29,     0,     3,     4,     0,
      91,    92,    93,    94,    95,     6,     0,     0,     7,    96,
      97,    98,     9,     0,     0,    99,     0,     0,     0,    13,
       0,     0,     0,    17,    18,    19,    20,     2,    21,     0,
      22,    23,    24,    25,     0,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     7,     0,
      59,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,    20,     2,    21,     0,
      22,    23,    24,    25,     0,     0,     0,     3,     4,     0,
       0,     0,    69,     0,     0,     6,     0,     0,     7,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,    20,     2,    21,     0,
      22,    23,    24,    25,     0,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     7,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,    20,     0,    21,     0,
      22,    23,    24,    25,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,   149,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    89,   152,    90,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,   160,     0,     0,    89,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,    89,   162,    90,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
      89,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,   166,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,    89,
       0,    90,     0,     0,     0,     0,     0,   173,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,    89,   180,    90,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,    89,
       0,    90,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   -17,   -17,     0,     0,     0,     0,    89,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
       2,     7,    50,    20,    98,     7,    20,     9,   169,    26,
     104,    31,    14,   106,    25,    22,    30,   178,    25,    21,
       5,     6,     7,    19,   118,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    43,    20,    58,    50,
      20,    19,    19,    50,    25,    51,    26,    30,    23,    24,
      25,    25,    20,   147,    29,    19,    20,    59,    26,   152,
      25,    23,    64,    25,   158,    20,    44,    29,    46,     3,
       4,    26,    19,   166,    50,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   180,    89,    90,    20,
     183,    93,    94,    95,    20,    26,    98,    99,    20,     0,
      26,    33,   104,   105,    26,     3,     4,    36,    26,    25,
     112,    50,    50,    50,    26,   117,   118,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    28,
      26,    25,    27,    50,    19,   147,    25,   149,     0,     1,
      50,    27,     4,   114,   157,    -1,   158,    -1,    44,    -1,
      46,    -1,    14,    15,    -1,   167,    -1,    19,    -1,    44,
      22,    46,    -1,    25,    -1,    27,    28,    29,   180,    -1,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    45,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,     0,     1,    -1,    -1,     4,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    22,    -1,    -1,    25,    -1,
      27,    -1,    29,    -1,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    45,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    -1,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      19,    -1,    -1,    22,    -1,    -1,    25,    -1,    27,    -1,
      29,    -1,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,     4,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    14,    15,    -1,
      14,    15,    16,    17,    18,    22,    -1,    -1,    25,    23,
      24,    25,    29,    -1,    -1,    29,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    40,    41,    42,    43,     4,    45,    -1,
      47,    48,    49,    50,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,     4,    45,    -1,
      47,    48,    49,    50,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,     4,    45,    -1,
      47,    48,    49,    50,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    -1,    45,    -1,
      47,    48,    49,    50,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    44,    26,    46,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    30,    -1,    -1,    44,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    30,    46,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    28,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    44,    19,    46,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    44,
      -1,    46,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    44,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     4,    14,    15,    19,    22,    25,    27,    29,
      32,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    45,    47,    48,    49,    50,    51,    52,    53,    54,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      71,    74,    76,    79,    81,    82,    84,    86,    87,    19,
      60,    25,    64,    66,    64,    50,    60,    76,    75,    27,
      60,    70,    72,    73,    25,    25,    25,    25,    50,    19,
      60,    19,    19,    50,    60,     0,    59,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    19,    44,
      46,    14,    15,    16,    17,    18,    23,    24,    25,    29,
      67,    68,    69,    23,    25,    29,    33,    76,    26,    26,
      59,    60,    20,    30,    20,    30,    60,    83,    85,    78,
      25,    19,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    50,    50,
      70,    60,    50,    70,    60,    58,    26,    25,    28,    21,
      60,    73,    26,    60,    70,    50,    80,    77,    25,    26,
      30,    26,    30,    70,    60,    58,    26,    19,    20,    26,
      80,    70,    26,    28,    58,    60,    50,    74,    26,    26,
      19,    74,    70,    26,    58
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
      73,    75,    74,    77,    76,    78,    76,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    81,    81,    83,    82,
      85,    84,    86,    86,    87,    87,    87,    87
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
       5,     0,     4,     0,     7,     0,     6,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     5,     3,     0,     6,
       0,    10,     3,     2,     1,     1,     1,     1
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
#line 133 "src/parser.y"
                        {       
                                (yyval.node) = (yyvsp[0].node);
                                fprintf(yyout, "[-] Reduced: program -> stmt_list\n");
                        }
#line 1795 "out/parser.tab.cpp"
    break;

  case 3: /* stmt: expr SEMICOLON  */
#line 139 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: stmt -> expr SEMICOLON\n");
                        }
#line 1803 "out/parser.tab.cpp"
    break;

  case 4: /* stmt: ifstmt  */
#line 143 "src/parser.y"
                        {
                                (yyval.node) = (yyvsp[0].node);
                                fprintf(yyout, "[-] Reduced: stmt -> ifstmt\n");
                        }
#line 1812 "out/parser.tab.cpp"
    break;

  case 5: /* stmt: whilestmt  */
#line 148 "src/parser.y"
                        {
                                (yyval.node) = (yyvsp[0].node);
                                fprintf(yyout, "[-] Reduced: stmt -> whilestmt\n");
                        }
#line 1821 "out/parser.tab.cpp"
    break;

  case 6: /* stmt: forstmt  */
#line 153 "src/parser.y"
                        {
                                (yyval.node) = (yyvsp[0].node);
                                fprintf(yyout, "[-] Reduced: stmt -> forstmt\n");
                        }
#line 1830 "out/parser.tab.cpp"
    break;

  case 7: /* stmt: returnstmt  */
#line 158 "src/parser.y"
                        {
                                if (symTable.funcStack.empty()) fprintf(yyout, "      [!] Error: Return statement outside of function in line %d.\n", yylineno);
                                (yyval.node) = (yyvsp[0].node);
                                fprintf(yyout, "[-] Reduced: stmt -> returnstmt\n");
                        }
#line 1840 "out/parser.tab.cpp"
    break;

  case 8: /* stmt: BREAK SEMICOLON  */
#line 164 "src/parser.y"
                                {       
                                        if (rabbitHole < 1)  fprintf(yyout, "      [!] Error: Break statement outside of loop in line %d.\n", yylineno);
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: stmt -> BREAK SEMICOLON\n");
                                }
#line 1852 "out/parser.tab.cpp"
    break;

  case 9: /* stmt: CONTINUE SEMICOLON  */
#line 172 "src/parser.y"
                                {       
                                        if (rabbitHole < 1) fprintf(yyout, "      [!] Error: Continue statement outside of loop in line %d.\n", yylineno);
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: stmt -> CONTINUE SEMICOLON\n");
                                }
#line 1864 "out/parser.tab.cpp"
    break;

  case 10: /* stmt: block  */
#line 180 "src/parser.y"
                                {       
                                        (yyval.node) = (yyvsp[0].node);
                                        fprintf(yyout, "[-] Reduced: stmt -> block\n");
                                }
#line 1873 "out/parser.tab.cpp"
    break;

  case 11: /* stmt: funcdef  */
#line 185 "src/parser.y"
                                {
                                        (yyval.node) = (yyvsp[0].node);
                                        fprintf(yyout, "[-] Reduced: stmt -> funcdef\n");
                                }
#line 1882 "out/parser.tab.cpp"
    break;

  case 12: /* stmt: SEMICOLON  */
#line 190 "src/parser.y"
                                {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: stmt -> SEMICOLON\n");
                                }
#line 1893 "out/parser.tab.cpp"
    break;

  case 13: /* stmt: errors  */
#line 197 "src/parser.y"
                                {
                                        (yyval.node) = (yyvsp[0].node);
                                        fprintf(yyout, "[-] Reduced: stmt -> errors\n");
                                }
#line 1902 "out/parser.tab.cpp"
    break;

  case 14: /* stmt: error SEMICOLON  */
#line 203 "src/parser.y"
                                {       
                                        fprintf(yyout, "      [!] Error: Illegal statement in line %d.\n", yylineno);
                                        yyerrok;
                                        yyclearin;
                                }
#line 1912 "out/parser.tab.cpp"
    break;

  case 15: /* stmt_list: stmt stmt_list  */
#line 211 "src/parser.y"
                                {
                                        (yyval.node) = nullptr;
                                        fprintf(yyout, "[-] Reduced: stmt_list -> stmt stmt_list\n");
                                }
#line 1921 "out/parser.tab.cpp"
    break;

  case 16: /* stmt_list: %empty  */
#line 216 "src/parser.y"
                                {       
                                        (yyval.node) = nullptr;    
                                        fprintf(yyout, "[-] Reduced: stmt_list -> /* empty */\n");
                                }
#line 1930 "out/parser.tab.cpp"
    break;

  case 17: /* expr: assignexpr  */
#line 222 "src/parser.y"
                                {       
                                        (yyval.node) = (yyvsp[0].node);
                                        fprintf(yyout, "[-] Reduced: expr -> assignexpr\n");
                                }
#line 1939 "out/parser.tab.cpp"
    break;

  case 18: /* expr: expr PLUS expr  */
#line 227 "src/parser.y"
                                {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr PLUS expr\n");
                                }
#line 1950 "out/parser.tab.cpp"
    break;

  case 19: /* expr: expr MINUS expr  */
#line 234 "src/parser.y"
                                {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr MINUS expr\n");
                                }
#line 1961 "out/parser.tab.cpp"
    break;

  case 20: /* expr: expr MULTIPLY expr  */
#line 241 "src/parser.y"
                                {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr MULTIPLY expr\n");
                                }
#line 1972 "out/parser.tab.cpp"
    break;

  case 21: /* expr: expr DIVIDE expr  */
#line 248 "src/parser.y"
                                {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr DIVIDE expr\n");
                                }
#line 1983 "out/parser.tab.cpp"
    break;

  case 22: /* expr: expr MODULO expr  */
#line 255 "src/parser.y"
                                {
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: expr -> expr MODULO expr\n");
                                }
#line 1994 "out/parser.tab.cpp"
    break;

  case 23: /* expr: expr GREATER_THAN expr  */
#line 262 "src/parser.y"
                                        {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                (yyval.node) = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN expr\n");
                                        }
#line 2005 "out/parser.tab.cpp"
    break;

  case 24: /* expr: expr LESS_THAN expr  */
#line 269 "src/parser.y"
                                        {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                (yyval.node) = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN expr\n");
                                        }
#line 2016 "out/parser.tab.cpp"
    break;

  case 25: /* expr: expr GREATER_THAN_EQUAL expr  */
#line 276 "src/parser.y"
                                        {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                (yyval.node) = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN_EQUAL expr\n");
                                        }
#line 2027 "out/parser.tab.cpp"
    break;

  case 26: /* expr: expr LESS_THAN_EQUAL expr  */
#line 283 "src/parser.y"
                                        {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                (yyval.node) = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN_EQUAL expr\n");
                                        }
#line 2038 "out/parser.tab.cpp"
    break;

  case 27: /* expr: expr EQUAL expr  */
#line 290 "src/parser.y"
                                        {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                (yyval.node) = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr EQUAL expr\n");
                                        }
#line 2049 "out/parser.tab.cpp"
    break;

  case 28: /* expr: expr NOT_EQUAL expr  */
#line 297 "src/parser.y"
                                        {       
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                (yyval.node) = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr NOT_EQUAL expr\n");
                                        }
#line 2060 "out/parser.tab.cpp"
    break;

  case 29: /* expr: expr AND expr  */
#line 304 "src/parser.y"
                                        {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                (yyval.node) = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr AND expr\n");
                                        }
#line 2071 "out/parser.tab.cpp"
    break;

  case 30: /* expr: expr OR expr  */
#line 311 "src/parser.y"
                                        {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = VAR;
                                                (yyval.node) = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> expr OR expr\n");
                                        }
#line 2082 "out/parser.tab.cpp"
    break;

  case 31: /* expr: term  */
#line 318 "src/parser.y"
                                        {
                                                SymEntry* dummy = new SymEntry;
                                                dummy->type = NONLVAL;
                                                (yyval.node) = dummy;
                                                fprintf(yyout, "[-] Reduced: expr -> term\n");
                                        }
#line 2093 "out/parser.tab.cpp"
    break;

  case 32: /* term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 326 "src/parser.y"
                                                {
                                                        (yyval.node) = (yyvsp[-1].node);
                                                        fprintf(yyout, "[-] Reduced: term -> LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                }
#line 2102 "out/parser.tab.cpp"
    break;

  case 33: /* term: MINUS expr  */
#line 331 "src/parser.y"
                                                {
                                                        (yyval.node) = (yyvsp[0].node);
                                                        fprintf(yyout, "[-] Reduced: term -> MINUS expr\n");
                                                }
#line 2111 "out/parser.tab.cpp"
    break;

  case 34: /* term: NOT expr  */
#line 336 "src/parser.y"
                                                { 
                                                        (yyval.node) = (yyvsp[0].node);
                                                        fprintf(yyout, "[-] Reduced: term -> NOT expr\n");
                                                }
#line 2120 "out/parser.tab.cpp"
    break;

  case 35: /* term: INCREMENT lvalue  */
#line 341 "src/parser.y"
                                                {       
                                                        if ((yyvsp[0].node)->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (++libfunc) in line %d.\n", yylineno);
                                                        if ((yyvsp[0].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (++func) in line %d.\n", yylineno);
                                                        if ((yyvsp[0].node)->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (++nonlval) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        (yyval.node) = dummy;
                                                        fprintf(yyout, "[-] Reduced: term -> INCREMENT lvalue\n");
                                                }
#line 2134 "out/parser.tab.cpp"
    break;

  case 36: /* term: lvalue INCREMENT  */
#line 351 "src/parser.y"
                                                {       
                                                        if ((yyvsp[-1].node)->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc++) in line %d.\n", yylineno);
                                                        if ((yyvsp[-1].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func++) in line %d.\n", yylineno);
                                                        if ((yyvsp[-1].node)->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval++) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        (yyval.node) = dummy;
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue INCREMENT\n");
                                                }
#line 2148 "out/parser.tab.cpp"
    break;

  case 37: /* term: DECREMENT lvalue  */
#line 361 "src/parser.y"
                                                {       
                                                        if ((yyvsp[0].node)->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (--libfunc) in line %d.\n", yylineno);
                                                        if ((yyvsp[0].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (--func) in line %d.\n", yylineno);
                                                        if ((yyvsp[0].node)->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (--nonlval) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        (yyval.node) = dummy;
                                                        fprintf(yyout, "[-] Reduced: term -> DECREMENT lvalue\n");
                                                }
#line 2162 "out/parser.tab.cpp"
    break;

  case 38: /* term: lvalue DECREMENT  */
#line 371 "src/parser.y"
                                                {
                                                        if ((yyvsp[-1].node)->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc--) in line %d.\n", yylineno);
                                                        if ((yyvsp[-1].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func--) in line %d.\n", yylineno);
                                                        if ((yyvsp[-1].node)->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval--) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        (yyval.node) = dummy;
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue DECREMENT\n");
                                                }
#line 2176 "out/parser.tab.cpp"
    break;

  case 39: /* term: primary  */
#line 381 "src/parser.y"
                                                {       
                                                        (yyval.node) = (yyvsp[0].node);
                                                        fprintf(yyout, "[-] Reduced: term -> primary\n");
                                                }
#line 2185 "out/parser.tab.cpp"
    break;

  case 40: /* assignexpr: lvalue ASSIGN expr  */
#line 387 "src/parser.y"
                                                {       
                                                        if ((yyvsp[-2].node)->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc = expr) in line %d.\n", yylineno);
                                                        if ((yyvsp[-2].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func = expr) in line %d.\n", yylineno);
                                                        if ((yyvsp[-2].node)->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval = expr) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        (yyval.node) = dummy;
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
                                                }
#line 2199 "out/parser.tab.cpp"
    break;

  case 41: /* assignexpr: lvalue PLUS_ASSIGN expr  */
#line 397 "src/parser.y"
                                                {       
                                                        if ((yyvsp[-2].node)->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc += expr) in line %d.\n", yylineno);
                                                        if ((yyvsp[-2].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func += expr) in line %d.\n", yylineno);
                                                        if ((yyvsp[-2].node)->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval += expr) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        (yyval.node) = dummy;
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue PLUS_ASSIGN expr\n");
                                                }
#line 2213 "out/parser.tab.cpp"
    break;

  case 42: /* assignexpr: lvalue MINUS_ASSIGN expr  */
#line 407 "src/parser.y"
                                                {
                                                        if ((yyvsp[-2].node)->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc -= expr) in line %d.\n", yylineno);
                                                        if ((yyvsp[-2].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func -= expr) in line %d.\n", yylineno);
                                                        if ((yyvsp[-2].node)->type == NONLVAL) fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval -= expr) in line %d.\n", yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = NONLVAL;
                                                        (yyval.node) = dummy;
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue MINUS_ASSIGN expr\n");
                                                }
#line 2227 "out/parser.tab.cpp"
    break;

  case 43: /* primary: lvalue  */
#line 418 "src/parser.y"
                                {       
                                        (yyval.node) = (yyvsp[0].node);
                                        fprintf(yyout, "[-] Reduced: primary -> lvalue\n");
                                }
#line 2236 "out/parser.tab.cpp"
    break;

  case 44: /* primary: call  */
#line 423 "src/parser.y"
                                {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = NONLVAL;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: primary -> call\n");
                                }
#line 2247 "out/parser.tab.cpp"
    break;

  case 45: /* primary: objectdef  */
#line 430 "src/parser.y"
                                {       
                                        (yyval.node) = (yyvsp[0].node);
                                        fprintf(yyout, "[-] Reduced: primary -> objectdef\n");
                                }
#line 2256 "out/parser.tab.cpp"
    break;

  case 46: /* primary: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS  */
#line 435 "src/parser.y"
                                                        {       
                                                                (yyval.node) = (yyvsp[-1].node);
                                                                fprintf(yyout, "[-] Reduced: primary -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS\n");
                                                        }
#line 2265 "out/parser.tab.cpp"
    break;

  case 47: /* primary: const  */
#line 439 "src/parser.y"
                                {
                                        (yyval.node) = (yyvsp[0].node);
                                        fprintf(yyout, "[-] Reduced: primary -> const\n");
                                }
#line 2274 "out/parser.tab.cpp"
    break;

  case 48: /* lvalue: IDENTIFIER  */
#line 445 "src/parser.y"
                                {
                                        SymEntry* found = symTable.lookup((yyvsp[0].str_val));

                                        if (!found) {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = (yyvsp[0].str_val);
                                                entry->type = VAR;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;
                                                entry->isGlobal = entry->scope == 0 ? true : false;
                                                symTable.insert(entry);
                                                (yyval.node) = entry;
                                        } else {    
                                                if (found->type == LIBFUNC) {
                                                        (yyval.node) = found;
                                                }

                                                if (found->type == VAR || found->type == FORARG) {
                                                        if (symTable.funcStack.empty()) {
                                                                (yyval.node) = found;
                                                        } else {
                                                                if ((found->scope > symTable.funcStack.top()->scope && found->isActive) || found->scope == 0) {
                                                                        (yyval.node) = found;
                                                                } else {
                                                                     fprintf(yyout, "      [!] Error: Variable %s is not accessible in line %d.\n", (yyvsp[0].str_val), yylineno); 
                                                                }
                                                        }
                                                } else {
                                                        (yyval.node) = found;
                                                }
                                        }

                                        fprintf(yyout, "[-] Reduced: lvalue -> IDENTIFIER\n");
                                }
#line 2314 "out/parser.tab.cpp"
    break;

  case 49: /* lvalue: LOCAL IDENTIFIER  */
#line 481 "src/parser.y"
                                {       
                                        SymEntry* found;
                                        if ((found = symTable.lookup((yyvsp[0].str_val), 0)) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Local variable is shadowing library function in line %d.\n", yylineno);
                                        } else if (!found || found->type != LIBFUNC) {
                                        
                                                found = symTable.lookup((yyvsp[0].str_val), symTable.getScope());

                                                if (found) {
                                                        (yyval.node) = found;
                                                } else {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = (yyvsp[0].str_val);
                                                        entry->type = VAR;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;
                                                        symTable.insert(entry);
                                                        (yyval.node) = entry;
                                                }
                                        } 
                                        fprintf(yyout, "[-] Reduced: lvalue -> LOCAL IDENTIFIER\n");
                                }
#line 2342 "out/parser.tab.cpp"
    break;

  case 50: /* lvalue: DOUBLE_COLON IDENTIFIER  */
#line 505 "src/parser.y"
                                        {       
                                                SymEntry* found = symTable.lookup((yyvsp[0].str_val), 0);
                                                if (!found) {
                                                        fprintf(yyout, "      [!] Error: Token %s has not been declared in global scope in line %d.\n", (yyvsp[0].str_val), yylineno);
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = VAR;
                                                        (yyval.node) = dummy;
                                                } else {
                                                        (yyval.node) = found;
                                                }
                                                fprintf(yyout, "[-] Reduced: lvalue -> DOUBLE_COLON IDENTIFIER\n");
                                        }
#line 2359 "out/parser.tab.cpp"
    break;

  case 51: /* lvalue: member  */
#line 518 "src/parser.y"
                                        {       
                                                (yyval.node) = (yyvsp[0].node);
                                                fprintf(yyout, "[-] Reduced: lvalue -> member\n");
                                        }
#line 2368 "out/parser.tab.cpp"
    break;

  case 52: /* member: lvalue DOT IDENTIFIER  */
#line 524 "src/parser.y"
                                {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: member -> lvalue DOT IDENTIFIER\n");
                                }
#line 2379 "out/parser.tab.cpp"
    break;

  case 53: /* member: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 531 "src/parser.y"
                                                        {
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = VAR;
                                                                (yyval.node) = dummy;
                                                                fprintf(yyout, "[-] Reduced: member -> lvalue LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }
#line 2390 "out/parser.tab.cpp"
    break;

  case 54: /* member: call DOT IDENTIFIER  */
#line 538 "src/parser.y"
                                                        {       
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = VAR;
                                                                (yyval.node) = dummy;
                                                                fprintf(yyout, "[-] Reduced: member -> call DOT IDENTIFIER\n");
                                                        }
#line 2401 "out/parser.tab.cpp"
    break;

  case 55: /* member: call LEFT_BRACKET expr RIGHT_BRACKET  */
#line 545 "src/parser.y"
                                                        {       
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = VAR;
                                                                (yyval.node) = dummy;
                                                                fprintf(yyout, "[-] Reduced: member -> call LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }
#line 2412 "out/parser.tab.cpp"
    break;

  case 56: /* call: call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 553 "src/parser.y"
                                                        {       
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = NONLVAL;
                                                                (yyval.node) = dummy;       
                                                                fprintf(yyout, "[-] Reduced: call -> call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
#line 2423 "out/parser.tab.cpp"
    break;

  case 57: /* call: lvalue callsuffix  */
#line 560 "src/parser.y"
                                                        {
                                                                (yyval.node) = (yyvsp[-1].node);
                                                                fprintf(yyout, "[-] Reduced: call -> lvalue callsuffix\n");
                                                        }
#line 2432 "out/parser.tab.cpp"
    break;

  case 58: /* call: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 565 "src/parser.y"
                                                                                                {       
                                                                                                        SymEntry* dummy = new SymEntry;
                                                                                                        dummy->type = NONLVAL;
                                                                                                        (yyval.node) = dummy;
                                                                                                        fprintf(yyout, "[-] Reduced: call -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                }
#line 2443 "out/parser.tab.cpp"
    break;

  case 59: /* callsuffix: normcall  */
#line 573 "src/parser.y"
                                {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = NONLVAL;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: callsuffix -> normcall\n");
                                }
#line 2454 "out/parser.tab.cpp"
    break;

  case 60: /* callsuffix: methodcall  */
#line 580 "src/parser.y"
                                {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = NONLVAL;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: callsuffix -> methodcall\n");
                                }
#line 2465 "out/parser.tab.cpp"
    break;

  case 61: /* normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 588 "src/parser.y"
                                                        {       
                                                                SymEntry* dummy = new SymEntry;
                                                                dummy->type = VAR;
                                                                (yyval.node) = dummy;
                                                                fprintf(yyout, "[-] Reduced: normcall -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
#line 2476 "out/parser.tab.cpp"
    break;

  case 62: /* methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 596 "src/parser.y"
                                                                                {       
                                                                                        SymEntry* dummy = new SymEntry;
                                                                                        dummy->type = VAR;
                                                                                        (yyval.node) = dummy;
                                                                                        fprintf(yyout, "[-] Reduced: methodcall -> DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                }
#line 2487 "out/parser.tab.cpp"
    break;

  case 63: /* elist: expr  */
#line 604 "src/parser.y"
                                {       
                                        (yyval.node) = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> expr\n");
                                }
#line 2496 "out/parser.tab.cpp"
    break;

  case 64: /* elist: elist COMMA expr  */
#line 609 "src/parser.y"
                                {       
                                        (yyval.node) = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> expr COMMA elist\n");
                                }
#line 2505 "out/parser.tab.cpp"
    break;

  case 65: /* elist: %empty  */
#line 614 "src/parser.y"
                                {       
                                        (yyval.node) = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> /* empty */\n");
                                }
#line 2514 "out/parser.tab.cpp"
    break;

  case 66: /* objectdef: LEFT_BRACKET elist RIGHT_BRACKET  */
#line 620 "src/parser.y"
                                                {       
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = VAR;
                                                        (yyval.node) = dummy;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET elist RIGHT_BRACKET\n");
                                                }
#line 2525 "out/parser.tab.cpp"
    break;

  case 67: /* objectdef: LEFT_BRACKET indexed RIGHT_BRACKET  */
#line 627 "src/parser.y"
                                                {       
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = VAR;
                                                        (yyval.node) = dummy;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET indexed RIGHT_BRACKET\n");
                                                }
#line 2536 "out/parser.tab.cpp"
    break;

  case 68: /* indexed: indexedelem  */
#line 635 "src/parser.y"
                                                {
                                                        (yyval.node) = nullptr;
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexedelem\n");
                                                }
#line 2545 "out/parser.tab.cpp"
    break;

  case 69: /* indexed: indexed COMMA indexedelem  */
#line 640 "src/parser.y"
                                                {
                                                        (yyval.node) = nullptr;
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexed COMMA indexedelem\n");
                                                }
#line 2554 "out/parser.tab.cpp"
    break;

  case 70: /* indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE  */
#line 646 "src/parser.y"
                                                        {
                                                                (yyval.node) = nullptr;
                                                                fprintf(yyout, "[-] Reduced: indexedelem -> LEFT_BRACE expr COLON expr RIGHT_BRACE\n");
                                                        }
#line 2563 "out/parser.tab.cpp"
    break;

  case 71: /* $@1: %empty  */
#line 652 "src/parser.y"
                        { 
                                if (skipBlockScope) {
                                        skipBlockScope = false;
                                } else {
                                        symTable.enter_scope();
                                }
                        }
#line 2575 "out/parser.tab.cpp"
    break;

  case 72: /* block: LEFT_BRACE $@1 stmt_list RIGHT_BRACE  */
#line 658 "src/parser.y"
                                                {
                                                        symTable.exit_scope();   
                                                        SymEntry* dummy = new SymEntry;
                                                        dummy->type = VAR;
                                                        (yyval.node) = dummy;   
                                                        fprintf(yyout, "[-] Reduced: block -> LEFT_BRACE stmt_list RIGHT_BRACE\n");
                                                }
#line 2587 "out/parser.tab.cpp"
    break;

  case 73: /* $@2: %empty  */
#line 667 "src/parser.y"
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

                                                                symTable.enter_scope();
                                                                skipBlockScope = true;
                                                                entryFuncDef = entry;
                                                        }
                                                }
#line 2631 "out/parser.tab.cpp"
    break;

  case 74: /* funcdef: FUNCTION IDENTIFIER LEFT_PARENTHESIS $@2 idlist RIGHT_PARENTHESIS block  */
#line 705 "src/parser.y"
                                                                                 {
                                                                                        if (!symTable.funcStack.empty()) {
                                                                                                symTable.funcStack.pop();
                                                                                        } 
                                                                                        SymEntry* dummy = new SymEntry;
                                                                                        dummy->type = VAR;
                                                                                        (yyval.node) = entryFuncDef ? entryFuncDef : dummy;
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION IDENTIFIER LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
#line 2645 "out/parser.tab.cpp"
    break;

  case 75: /* $@3: %empty  */
#line 715 "src/parser.y"
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
                                                symTable.enter_scope();
                                                skipBlockScope = true;
                                        }
#line 2667 "out/parser.tab.cpp"
    break;

  case 76: /* funcdef: FUNCTION LEFT_PARENTHESIS $@3 idlist RIGHT_PARENTHESIS block  */
#line 731 "src/parser.y"
                                                                                {       
                                                                                        symTable.funcStack.pop();
                                                                                        (yyval.node) = entryFuncDef;
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
#line 2677 "out/parser.tab.cpp"
    break;

  case 77: /* const: INTEGER  */
#line 739 "src/parser.y"
                        {       
                                (yyval.node) = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> INTEGER\n");
                        }
#line 2686 "out/parser.tab.cpp"
    break;

  case 78: /* const: REAL  */
#line 744 "src/parser.y"
                        {       
                                (yyval.node) = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> REAL\n");
                        }
#line 2695 "out/parser.tab.cpp"
    break;

  case 79: /* const: STRINGT  */
#line 749 "src/parser.y"
                        {       
                                (yyval.node) = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> STRING\n");
                        }
#line 2704 "out/parser.tab.cpp"
    break;

  case 80: /* const: TRUE  */
#line 754 "src/parser.y"
                        {       
                                (yyval.node) = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> TRUE\n");
                        }
#line 2713 "out/parser.tab.cpp"
    break;

  case 81: /* const: FALSE  */
#line 759 "src/parser.y"
                        {       
                                (yyval.node) = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> FALSE\n");
                        }
#line 2722 "out/parser.tab.cpp"
    break;

  case 82: /* const: NIL  */
#line 764 "src/parser.y"
                        {
                                (yyval.node) = nullptr;
                                fprintf(yyout, "[-] Reduced: const -> NIL\n");
                        }
#line 2731 "out/parser.tab.cpp"
    break;

  case 83: /* idlist: IDENTIFIER  */
#line 770 "src/parser.y"
                        {       
                                SymEntry* found;

                                if ((found = symTable.lookup((yyvsp[0].str_val), 0)) && found->type == LIBFUNC) {
                                        fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);

                                        (yyval.node) = found;
                                } else {
                                        if ((found = symTable.lookup((yyvsp[0].str_val), symTable.getScope()))) {
                                                if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                        } else {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = (yyvsp[0].str_val);
                                                entry->type = FORARG;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;

                                                symTable.insert(entry);

                                                if (!symTable.funcStack.empty() && symTable.funcStack.top()->scope == entry->scope - 1) {
                                                        symTable.funcStack.top()->args.push_back(entry);
                                                }  
                                                (yyval.node) = entry;
                                        }
                                }
                                fprintf(yyout, "[-] Reduced: idlist -> IDENTIFIER\n");
                        }
#line 2764 "out/parser.tab.cpp"
    break;

  case 84: /* idlist: idlist COMMA IDENTIFIER  */
#line 798 "src/parser.y"
                                    {   
                                        SymEntry* found;

                                        if ((found = symTable.lookup((yyvsp[0].str_val), 0)) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);
                                                (yyval.node) = found;
                                        } else {
                                                if ((found = symTable.lookup((yyvsp[0].str_val), symTable.getScope()))) {
                                                        if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                                } else {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = (yyvsp[0].str_val);
                                                        entry->type = FORARG;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;

                                                        symTable.insert(entry);

                                                        if (!symTable.funcStack.empty() && symTable.funcStack.top()->scope == entry->scope - 1) {
                                                                symTable.funcStack.top()->args.push_back(entry);
                                                        }  
                                                        (yyval.node) = entry;
                                                        
                                                }
                                        }
                                        fprintf(yyout, "[-] Reduced: idlist -> idlist COMMA IDENTIFIER\n");
                                    }
#line 2797 "out/parser.tab.cpp"
    break;

  case 85: /* idlist: %empty  */
#line 826 "src/parser.y"
                                {       
                                        SymEntry* dummy = new SymEntry;
                                        dummy->type = VAR;
                                        (yyval.node) = dummy;
                                        fprintf(yyout, "[-] Reduced: idlist -> /* empty */\n");
                                }
#line 2808 "out/parser.tab.cpp"
    break;

  case 86: /* ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt  */
#line 834 "src/parser.y"
                                                                                {       
                                                                                        (yyval.node) = nullptr;
                                                                                        fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                                }
#line 2817 "out/parser.tab.cpp"
    break;

  case 87: /* ifstmt: ifstmt ELSE stmt  */
#line 839 "src/parser.y"
                                        {
                                                (yyval.node) = nullptr;
                                                fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");
                                        }
#line 2826 "out/parser.tab.cpp"
    break;

  case 88: /* $@4: %empty  */
#line 845 "src/parser.y"
                                        {
                                                rabbitHole++;
                                        }
#line 2834 "out/parser.tab.cpp"
    break;

  case 89: /* whilestmt: WHILE LEFT_PARENTHESIS $@4 expr RIGHT_PARENTHESIS stmt  */
#line 847 "src/parser.y"
                                                                        {       
                                                                                rabbitHole--;
                                                                                (yyval.node) = nullptr;
                                                                                fprintf(yyout, "[-] Reduced: whilestmt -> WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                        }
#line 2844 "out/parser.tab.cpp"
    break;

  case 90: /* $@5: %empty  */
#line 854 "src/parser.y"
                                {
                                        rabbitHole++;
                                }
#line 2852 "out/parser.tab.cpp"
    break;

  case 91: /* forstmt: FOR LEFT_PARENTHESIS $@5 elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt  */
#line 856 "src/parser.y"
                                                                                                {       
                                                                                                        rabbitHole--;
                                                                                                        (yyval.node) = nullptr;
                                                                                                        fprintf(yyout, "[-] Reduced: forstmt -> FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt\n");
                                                                                                }
#line 2862 "out/parser.tab.cpp"
    break;

  case 92: /* returnstmt: RETURN expr SEMICOLON  */
#line 863 "src/parser.y"
                                        {
                                                (yyval.node) = nullptr;
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN expr SEMICOLON\n");
                                        }
#line 2871 "out/parser.tab.cpp"
    break;

  case 93: /* returnstmt: RETURN SEMICOLON  */
#line 867 "src/parser.y"
                                        {       
                                                (yyval.node) = nullptr;
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN SEMICOLON\n");
                                        }
#line 2880 "out/parser.tab.cpp"
    break;

  case 94: /* errors: ERROR_COMMENT  */
#line 873 "src/parser.y"
                        {       
                                SymEntry* dummy = new SymEntry;
                                dummy->type = VAR;
                                (yyval.node) = dummy;
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_COMMENT\n");
                                fprintf(yyout, "      [!] Error: Invalid comment in line %d.\n", yylineno);
                                exit(1);
                        }
#line 2893 "out/parser.tab.cpp"
    break;

  case 95: /* errors: ERROR_STRING  */
#line 882 "src/parser.y"
                        {       
                                SymEntry* dummy = new SymEntry;
                                dummy->type = VAR;
                                (yyval.node) = dummy;
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_STRING\n");
                                fprintf(yyout, "      [!] Error: Invalid string in line %d.\n", yylineno);
                                exit(1);
                        }
#line 2906 "out/parser.tab.cpp"
    break;

  case 96: /* errors: ERROR_ESCAPE  */
#line 891 "src/parser.y"
                        {       
                                SymEntry* dummy = new SymEntry;
                                dummy->type = VAR;
                                (yyval.node) = dummy;
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_ESCAPE\n");
                                fprintf(yyout, "      [!] Error: Invalid escape sequence in line %d.\n", yylineno);
                                exit(1);
                        }
#line 2919 "out/parser.tab.cpp"
    break;

  case 97: /* errors: UNDEF  */
#line 900 "src/parser.y"
                        {       
                                SymEntry* dummy = new SymEntry;
                                dummy->type = VAR;
                                (yyval.node) = dummy;
                                fprintf(yyout, "[-] Reduced: errors -> UNDEF\n");
                                fprintf(yyout, "      [!] Error: Undefined variable in line %d.\n", yylineno);    
                                exit(1);
                        }
#line 2932 "out/parser.tab.cpp"
    break;


#line 2936 "out/parser.tab.cpp"

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

#line 909 "src/parser.y"


int yyerror(const char *msg) {
    fprintf(stderr, "      [Line %d] Syntax error: %s (near token: \"%s\")\n", yylineno, msg, yytext);
    return 0;
}
