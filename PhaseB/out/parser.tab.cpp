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
#include "parser.tab.hpp"
#include "../src/symtable.hpp"

extern SymbolTable symTable;
extern bool inFunction;
extern int rabbitHole;
extern int yylex();

extern FILE *yyin;
extern FILE *yyout;
void myerror(YYLTYPE* loc, const char* msg);
void yyerror(const char* msg);


#line 91 "out/parser.tab.cpp"

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
  YYSYMBOL_IF = 31,                        /* IF  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_WHILE = 33,                     /* WHILE  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_FUNCTION = 35,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 36,                    /* RETURN  */
  YYSYMBOL_BREAK = 37,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 38,                  /* CONTINUE  */
  YYSYMBOL_TRUE = 39,                      /* TRUE  */
  YYSYMBOL_FALSE = 40,                     /* FALSE  */
  YYSYMBOL_NIL = 41,                       /* NIL  */
  YYSYMBOL_LOCAL = 42,                     /* LOCAL  */
  YYSYMBOL_AND = 43,                       /* AND  */
  YYSYMBOL_NOT = 44,                       /* NOT  */
  YYSYMBOL_OR = 45,                        /* OR  */
  YYSYMBOL_INTEGER = 46,                   /* INTEGER  */
  YYSYMBOL_REAL = 47,                      /* REAL  */
  YYSYMBOL_STRING = 48,                    /* STRING  */
  YYSYMBOL_IDENTIFIER = 49,                /* IDENTIFIER  */
  YYSYMBOL_ERROR_COMMENT = 50,             /* ERROR_COMMENT  */
  YYSYMBOL_ERROR_STRING = 51,              /* ERROR_STRING  */
  YYSYMBOL_ERROR_ESCAPE = 52,              /* ERROR_ESCAPE  */
  YYSYMBOL_UNDEF = 53,                     /* UNDEF  */
  YYSYMBOL_LOWER_THAN_ELSE = 54,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_UMINUS = 55,                    /* UMINUS  */
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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

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
       0,   133,   133,   138,   142,   146,   150,   154,   161,   168,
     174,   178,   182,   186,   191,   195,   200,   204,   208,   212,
     216,   220,   224,   228,   232,   236,   240,   244,   248,   252,
     256,   261,   265,   271,   275,   279,   283,   287,   291,   296,
     316,   320,   325,   329,   333,   337,   340,   345,   348,   352,
     356,   361,   365,   369,   373,   378,   382,   386,   391,   395,
     400,   405,   410,   414,   418,   423,   427,   432,   436,   441,
     446,   446,   454,   454,   477,   477,   501,   505,   509,   513,
     517,   521,   526,   540,   543,   548,   552,   557,   557,   565,
     565,   573,   576,   581,   587,   593,   599
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
  "LEFT_BRACKET", "RIGHT_BRACKET", "IF", "ELSE", "WHILE", "FOR",
  "FUNCTION", "RETURN", "BREAK", "CONTINUE", "TRUE", "FALSE", "NIL",
  "LOCAL", "AND", "NOT", "OR", "INTEGER", "REAL", "STRING", "IDENTIFIER",
  "ERROR_COMMENT", "ERROR_STRING", "ERROR_ESCAPE", "UNDEF",
  "LOWER_THAN_ELSE", "UMINUS", "$accept", "program", "stmt", "stmt_list",
  "expr", "term", "assignexpr", "primary", "lvalue", "member", "call",
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

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,   224,   -13,   -13,  -143,   -47,     3,  -143,   146,   -14,
    -143,  -143,     9,   185,     5,    12,  -143,  -143,  -143,   -30,
     224,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,    22,
      90,  -143,   271,  -143,  -143,  -143,   508,  -143,    73,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,     4,
      44,    73,    44,  -143,   289,    35,    90,   224,   300,    42,
      33,  -143,   224,    49,    61,  -143,    64,  -143,   318,  -143,
    -143,  -143,   502,  -143,  -143,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,  -143,   224,   224,  -143,
    -143,   224,   224,   224,    46,    50,   224,   224,  -143,  -143,
    -143,    51,   224,   224,    75,  -143,    81,    79,   343,   224,
    -143,    83,  -143,   363,   224,   224,    59,  -143,  -143,   209,
     502,   209,   209,   209,   369,   369,   369,   369,    -8,    -8,
      66,  -143,  -143,  -143,  -143,  -143,    88,    92,   387,  -143,
      94,   415,    81,   224,  -143,   224,  -143,  -143,    90,   430,
      97,  -143,   -10,    59,   224,  -143,  -143,  -143,  -143,    96,
     458,   101,    90,   224,    86,   117,    34,   120,  -143,  -143,
      90,  -143,   485,  -143,  -143,   117,  -143,  -143,   224,  -143,
     121,    90,  -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      15,     0,     0,     0,    12,     0,     0,    70,    64,     0,
      87,    89,     0,     0,     0,     0,    79,    80,    81,     0,
       0,    76,    77,    78,    47,    93,    94,    95,    96,     0,
      15,     2,     0,    30,    16,    38,    42,    50,    43,    44,
      10,    11,    46,     4,     5,     6,     7,    13,    32,     0,
      34,     0,    36,    49,     0,     0,    15,     0,    62,     0,
       0,    67,     0,     0,     0,    74,     0,    92,     0,     8,
       9,    48,    33,     1,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,    35,
      37,     0,     0,     0,     0,     0,    64,     0,    56,    58,
      59,     0,    64,     0,     0,    31,    45,     0,     0,    64,
      65,     0,    66,     0,     0,    64,    84,    72,    91,    17,
      18,    19,    20,    21,    23,    25,    22,    24,    26,    27,
      28,    29,    39,    40,    41,    51,     0,     0,     0,    53,
       0,     0,     0,    64,    71,     0,    63,    68,     0,     0,
       0,    82,     0,    84,    64,    60,    52,    55,    54,     0,
       0,    85,     0,     0,     0,     0,     0,     0,    57,    69,
       0,    88,     0,    83,    75,     0,    61,    86,    64,    73,
       0,     0,    90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -122,   -15,     0,  -143,  -143,  -143,    62,  -143,
      68,  -143,  -143,  -143,   -88,  -143,  -143,    38,  -142,  -143,
      -3,  -143,  -143,  -143,    -2,  -143,  -143,  -143,  -143,  -143,
    -143,  -143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    29,    30,    31,    58,    33,    34,    35,    36,    37,
      38,    98,    99,   100,    59,    39,    60,    61,    40,    56,
      41,   153,   116,    42,   152,    43,    44,    63,    45,    64,
      46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    48,    53,    55,    -1,    -1,    54,     1,   137,     5,
     164,    62,    49,    68,   140,    74,   165,     2,     3,    71,
      72,   146,    73,   174,    69,     5,   161,   150,     6,    19,
      32,    70,     8,   179,    65,    87,    24,    88,    12,    12,
     171,   107,    16,    17,    18,    19,   104,    20,   177,    21,
      22,    23,    24,   111,   164,   159,    32,   108,    66,   182,
     175,   106,   113,   112,    50,    52,   167,    94,    95,    96,
      51,    51,   110,    97,   114,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   115,   130,   131,   117,
     180,   132,   133,   134,     1,   135,   101,   138,   102,   136,
     139,   142,   103,   141,     2,     3,   143,   144,   151,     4,
      57,    88,     5,   154,   149,     6,   163,     7,   155,     8,
     157,     9,   168,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   170,    20,   173,    21,    22,    23,    24,
      25,    26,    27,    28,     7,   160,   176,   181,    32,   147,
       1,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,    32,   172,     0,     0,     0,     0,     5,     0,
      32,     6,     0,    57,     0,     8,     0,     0,     0,     0,
       0,    32,     0,     0,     0,    16,    17,    18,    19,     1,
      20,     0,    21,    22,    23,    24,     0,     0,     0,     2,
       3,     0,     0,     0,    67,     0,     0,     5,     0,     0,
       6,     0,    75,     0,     8,     0,     0,    80,    81,    82,
      83,    84,    85,     0,    16,    17,    18,    19,     1,    20,
       0,    21,    22,    23,    24,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     6,
       0,     0,    87,     8,    88,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,     0,    20,     0,
      21,    22,    23,    24,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
      86,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    87,   105,    88,     0,     0,     0,
     109,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    87,     0,    88,     0,     0,   118,     0,     0,
       0,     0,     0,    87,     0,    88,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,     0,
       0,    87,     0,    88,   145,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      -1,    84,    85,     0,     0,     0,    87,     0,    88,   148,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,     0,    87,     0,    88,     0,
       0,     0,    87,     0,    88,     0,     0,   156,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
      87,     0,    88,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,     0,    87,     0,
      88,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,    87,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    87,     0,    88,   178,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,    93,     0,    87,     0,
      88,    94,    95,    96,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,    87,     0,    88
};

static const yytype_int16 yycheck[] =
{
       0,     1,    49,     6,    12,    13,     6,     4,    96,    22,
      20,    25,    25,    13,   102,    30,    26,    14,    15,    49,
      20,   109,     0,   165,    19,    22,   148,   115,    25,    42,
      30,    19,    29,   175,    25,    43,    49,    45,    35,    35,
     162,    56,    39,    40,    41,    42,    49,    44,   170,    46,
      47,    48,    49,    20,    20,   143,    56,    57,    49,   181,
      26,    26,    62,    30,     2,     3,   154,    23,    24,    25,
       2,     3,    30,    29,    25,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    25,    87,    88,    25,
     178,    91,    92,    93,     4,    49,    23,    97,    25,    49,
      49,    26,    29,   103,    14,    15,    25,    28,    49,    19,
      27,    45,    22,    25,   114,    25,    19,    27,    26,    29,
      26,    31,    26,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    32,    44,    49,    46,    47,    48,    49,
      50,    51,    52,    53,    27,   145,    26,    26,   148,   111,
       4,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,   162,   163,    -1,    -1,    -1,    -1,    22,    -1,
     170,    25,    -1,    27,    -1,    29,    -1,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    39,    40,    41,    42,     4,
      44,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    19,    -1,    -1,    22,    -1,    -1,
      25,    -1,     3,    -1,    29,    -1,    -1,     8,     9,    10,
      11,    12,    13,    -1,    39,    40,    41,    42,     4,    44,
      -1,    46,    47,    48,    49,    -1,    -1,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    43,    29,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    44,    -1,
      46,    47,    48,    49,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      19,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    43,    26,    45,    -1,    -1,    -1,
      20,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    43,    -1,    45,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    43,    -1,    45,    21,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    43,    -1,    45,    26,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    -1,
      -1,    -1,    43,    -1,    45,    -1,    -1,    30,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      43,    -1,    45,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    43,    -1,
      45,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    43,    -1,    45,    19,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    43,    -1,
      45,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    14,    15,    19,    22,    25,    27,    29,    31,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      44,    46,    47,    48,    49,    50,    51,    52,    53,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    71,
      74,    76,    79,    81,    82,    84,    86,    87,    60,    25,
      64,    66,    64,    49,    60,    76,    75,    27,    60,    70,
      72,    73,    25,    83,    85,    25,    49,    19,    60,    19,
      19,    49,    60,     0,    59,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    19,    43,    45,    14,
      15,    16,    17,    18,    23,    24,    25,    29,    67,    68,
      69,    23,    25,    29,    76,    26,    26,    59,    60,    20,
      30,    20,    30,    60,    25,    25,    78,    25,    19,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    49,    49,    70,    60,    49,
      70,    60,    26,    25,    28,    21,    70,    73,    26,    60,
      70,    49,    80,    77,    25,    26,    30,    26,    30,    70,
      60,    58,    26,    19,    20,    26,    80,    70,    26,    28,
      32,    58,    60,    49,    74,    26,    26,    58,    19,    74,
      70,    26,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    65,    66,    66,    66,    67,    67,
      68,    69,    70,    70,    70,    71,    71,    72,    72,    73,
      75,    74,    77,    76,    78,    76,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    81,    81,    83,    82,    85,
      84,    86,    86,    87,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     0,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       3,     3,     1,     1,     1,     3,     1,     1,     2,     2,
       1,     3,     4,     3,     4,     4,     2,     6,     1,     1,
       3,     5,     1,     3,     0,     3,     3,     1,     3,     5,
       0,     4,     0,     7,     0,     6,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     5,     7,     0,     6,     0,
      10,     3,     2,     1,     1,     1,     1
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
                                fprintf(yyout, "[-] Reduced: program -> stmt_list\n");
                        }
#line 1755 "out/parser.tab.cpp"
    break;

  case 3: /* stmt: expr SEMICOLON  */
#line 138 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: stmt -> expr SEMICOLON\n");
                        }
#line 1763 "out/parser.tab.cpp"
    break;

  case 4: /* stmt: ifstmt  */
#line 142 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: stmt -> ifstmt\n");
                        }
#line 1771 "out/parser.tab.cpp"
    break;

  case 5: /* stmt: whilestmt  */
#line 146 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: stmt -> whilestmt\n");
                        }
#line 1779 "out/parser.tab.cpp"
    break;

  case 6: /* stmt: forstmt  */
#line 150 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: stmt -> forstmt\n");
                        }
#line 1787 "out/parser.tab.cpp"
    break;

  case 7: /* stmt: returnstmt  */
#line 154 "src/parser.y"
                        {       
                                if (!inFunction) {
                                    myerror(&(yylsp[0]), "Error: Return statement outside of function");
                                }
                                fprintf(yyout, "[-] Reduced: stmt -> returnstmt\n");
                        }
#line 1798 "out/parser.tab.cpp"
    break;

  case 8: /* stmt: BREAK SEMICOLON  */
#line 161 "src/parser.y"
                                {       
                                        if (rabbitHole < 1) {
                                            myerror(&(yylsp[-1]), "Error: Break statement outside of loop");
                                        }
                                        fprintf(yyout, "[-] Reduced: stmt -> BREAK SEMICOLON\n");
                                }
#line 1809 "out/parser.tab.cpp"
    break;

  case 9: /* stmt: CONTINUE SEMICOLON  */
#line 168 "src/parser.y"
                                {       
                                        if (rabbitHole < 1) {
                                            myerror(&(yylsp[-1]), "Error: Continue statement outside of loop");
                                        }
                                        fprintf(yyout, "[-] Reduced: stmt -> CONTINUE SEMICOLON\n");
                                }
#line 1820 "out/parser.tab.cpp"
    break;

  case 10: /* stmt: block  */
#line 174 "src/parser.y"
                                {       
                                        fprintf(yyout, "[-] Reduced: stmt -> block\n");
                                }
#line 1828 "out/parser.tab.cpp"
    break;

  case 11: /* stmt: funcdef  */
#line 178 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: stmt -> funcdef\n");
                                }
#line 1836 "out/parser.tab.cpp"
    break;

  case 12: /* stmt: SEMICOLON  */
#line 182 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: stmt -> SEMICOLON\n");
                                }
#line 1844 "out/parser.tab.cpp"
    break;

  case 13: /* stmt: errors  */
#line 186 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: stmt -> errors\n");
                                }
#line 1852 "out/parser.tab.cpp"
    break;

  case 14: /* stmt_list: stmt stmt_list  */
#line 191 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: stmt_list -> stmt stmt_list\n");
                                }
#line 1860 "out/parser.tab.cpp"
    break;

  case 15: /* stmt_list: %empty  */
#line 195 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: stmt_list -> /* empty */\n");
                                }
#line 1868 "out/parser.tab.cpp"
    break;

  case 16: /* expr: assignexpr  */
#line 200 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> assignexpr\n");
                                }
#line 1876 "out/parser.tab.cpp"
    break;

  case 17: /* expr: expr PLUS expr  */
#line 204 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> expr PLUS expr\n");
                                }
#line 1884 "out/parser.tab.cpp"
    break;

  case 18: /* expr: expr MINUS expr  */
#line 208 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> expr MINUS expr\n");
                                }
#line 1892 "out/parser.tab.cpp"
    break;

  case 19: /* expr: expr MULTIPLY expr  */
#line 212 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> expr MULTIPLY expr\n");
                                }
#line 1900 "out/parser.tab.cpp"
    break;

  case 20: /* expr: expr DIVIDE expr  */
#line 216 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> expr DIVIDE expr\n");
                                }
#line 1908 "out/parser.tab.cpp"
    break;

  case 21: /* expr: expr MODULO expr  */
#line 220 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> expr MODULO expr\n");
                                }
#line 1916 "out/parser.tab.cpp"
    break;

  case 22: /* expr: expr GREATER_THAN expr  */
#line 224 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN expr\n");
                                        }
#line 1924 "out/parser.tab.cpp"
    break;

  case 23: /* expr: expr LESS_THAN expr  */
#line 228 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN expr\n");
                                        }
#line 1932 "out/parser.tab.cpp"
    break;

  case 24: /* expr: expr GREATER_THAN_EQUAL expr  */
#line 232 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN_EQUAL expr\n");
                                        }
#line 1940 "out/parser.tab.cpp"
    break;

  case 25: /* expr: expr LESS_THAN_EQUAL expr  */
#line 236 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN_EQUAL expr\n");
                                        }
#line 1948 "out/parser.tab.cpp"
    break;

  case 26: /* expr: expr EQUAL expr  */
#line 240 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr EQUAL expr\n");
                                        }
#line 1956 "out/parser.tab.cpp"
    break;

  case 27: /* expr: expr NOT_EQUAL expr  */
#line 244 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr NOT_EQUAL expr\n");
                                        }
#line 1964 "out/parser.tab.cpp"
    break;

  case 28: /* expr: expr AND expr  */
#line 248 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr AND expr\n");
                                        }
#line 1972 "out/parser.tab.cpp"
    break;

  case 29: /* expr: expr OR expr  */
#line 252 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr OR expr\n");
                                        }
#line 1980 "out/parser.tab.cpp"
    break;

  case 30: /* expr: term  */
#line 256 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> term\n");
                                        }
#line 1988 "out/parser.tab.cpp"
    break;

  case 31: /* term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 261 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: term -> LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                }
#line 1996 "out/parser.tab.cpp"
    break;

  case 32: /* term: MINUS expr  */
#line 265 "src/parser.y"
                                                {

                                                        
                                                        fprintf(yyout, "[-] Reduced: term -> MINUS expr\n");
                                                }
#line 2006 "out/parser.tab.cpp"
    break;

  case 33: /* term: NOT expr  */
#line 271 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: term -> NOT expr\n");
                                                }
#line 2014 "out/parser.tab.cpp"
    break;

  case 34: /* term: INCREMENT lvalue  */
#line 275 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: term -> INCREMENT lvalue\n");
                                                }
#line 2022 "out/parser.tab.cpp"
    break;

  case 35: /* term: lvalue INCREMENT  */
#line 279 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue INCREMENT\n");
                                                }
#line 2030 "out/parser.tab.cpp"
    break;

  case 36: /* term: DECREMENT lvalue  */
#line 283 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: term -> DECREMENT lvalue\n");
                                                }
#line 2038 "out/parser.tab.cpp"
    break;

  case 37: /* term: lvalue DECREMENT  */
#line 287 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue DECREMENT\n");
                                                }
#line 2046 "out/parser.tab.cpp"
    break;

  case 38: /* term: primary  */
#line 291 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: term -> primary\n");
                                                }
#line 2054 "out/parser.tab.cpp"
    break;

  case 39: /* assignexpr: lvalue ASSIGN expr  */
#line 296 "src/parser.y"
                                                {       
                                                        SymEntry* found = symTable.lookup((yyvsp[-2].str_val));
                                                        if (!found) {
                                                                SymEntry* var = new SymEntry;
                                                                var->name = (yyvsp[-2].str_val);
                                                                var->type = VAR;
                                                                var->scope = symTable.getScope();
                                                                var->line = (yylsp[-2]).first_line;
                                                                var->isActive = true;

                                                                int res = symTable.insert(var);
                                                                if (res == 3) myerror(&(yylsp[-2]), "Error: Cannot shadow lib function.\n");

                                                                delete var;
                                                        } else if (found->type == FUNC) {
                                                                myerror(&(yylsp[-2]), "Error: Cannot assign to function.\n");
                                                        }
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
                                                }
#line 2078 "out/parser.tab.cpp"
    break;

  case 40: /* assignexpr: lvalue PLUS_ASSIGN expr  */
#line 316 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue PLUS_ASSIGN expr\n");
                                                }
#line 2086 "out/parser.tab.cpp"
    break;

  case 41: /* assignexpr: lvalue MINUS_ASSIGN expr  */
#line 320 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue MINUS_ASSIGN expr\n");
                                                }
#line 2094 "out/parser.tab.cpp"
    break;

  case 42: /* primary: lvalue  */
#line 325 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: primary -> lvalue\n");
                                }
#line 2102 "out/parser.tab.cpp"
    break;

  case 43: /* primary: call  */
#line 329 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: primary -> call\n");
                                }
#line 2110 "out/parser.tab.cpp"
    break;

  case 44: /* primary: objectdef  */
#line 333 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: primary -> objectdef\n");
                                }
#line 2118 "out/parser.tab.cpp"
    break;

  case 45: /* primary: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS  */
#line 337 "src/parser.y"
                                                        {
                                                            fprintf(yyout, "[-] Reduced: primary -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS\n");
                                                        }
#line 2126 "out/parser.tab.cpp"
    break;

  case 46: /* primary: const  */
#line 340 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: primary -> const\n");
                                }
#line 2134 "out/parser.tab.cpp"
    break;

  case 47: /* lvalue: IDENTIFIER  */
#line 345 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: lvalue -> IDENTIFIER\n");
                                }
#line 2142 "out/parser.tab.cpp"
    break;

  case 48: /* lvalue: LOCAL IDENTIFIER  */
#line 348 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: lvalue -> LOCAL IDENTIFIER\n");
                                }
#line 2150 "out/parser.tab.cpp"
    break;

  case 49: /* lvalue: DOUBLE_COLON IDENTIFIER  */
#line 352 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: lvalue -> DOUBLE_COLON IDENTIFIER\n");
                                        }
#line 2158 "out/parser.tab.cpp"
    break;

  case 50: /* lvalue: member  */
#line 356 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: lvalue -> member\n");
                                        }
#line 2166 "out/parser.tab.cpp"
    break;

  case 51: /* member: lvalue DOT IDENTIFIER  */
#line 361 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: member -> lvalue DOT IDENTIFIER\n");
                                }
#line 2174 "out/parser.tab.cpp"
    break;

  case 52: /* member: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 365 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: member -> lvalue LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }
#line 2182 "out/parser.tab.cpp"
    break;

  case 53: /* member: call DOT IDENTIFIER  */
#line 369 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: member -> call DOT IDENTIFIER\n");
                                                        }
#line 2190 "out/parser.tab.cpp"
    break;

  case 54: /* member: call LEFT_BRACKET expr RIGHT_BRACKET  */
#line 373 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: member -> call LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }
#line 2198 "out/parser.tab.cpp"
    break;

  case 55: /* call: call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 378 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: call -> call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
#line 2206 "out/parser.tab.cpp"
    break;

  case 56: /* call: lvalue callsuffix  */
#line 382 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: call -> lvalue callsuffix\n");
                                                        }
#line 2214 "out/parser.tab.cpp"
    break;

  case 57: /* call: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 386 "src/parser.y"
                                                                                                {
                                                                                                    fprintf(yyout, "[-] Reduced: call -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                }
#line 2222 "out/parser.tab.cpp"
    break;

  case 58: /* callsuffix: normcall  */
#line 391 "src/parser.y"
                                {
                                    fprintf(yyout, "[-] Reduced: callsuffix -> normcall\n");
                                }
#line 2230 "out/parser.tab.cpp"
    break;

  case 59: /* callsuffix: methodcall  */
#line 395 "src/parser.y"
                                {
                                    fprintf(yyout, "[-] Reduced: callsuffix -> methodcall\n");
                                }
#line 2238 "out/parser.tab.cpp"
    break;

  case 60: /* normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 400 "src/parser.y"
                                                        {
                                                            fprintf(yyout, "[-] Reduced: normcall -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
#line 2246 "out/parser.tab.cpp"
    break;

  case 61: /* methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 405 "src/parser.y"
                                                                                {
                                                                                    fprintf(yyout, "[-] Reduced: methodcall -> DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                }
#line 2254 "out/parser.tab.cpp"
    break;

  case 62: /* elist: expr  */
#line 410 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: elist -> expr\n");
                                }
#line 2262 "out/parser.tab.cpp"
    break;

  case 63: /* elist: expr COMMA elist  */
#line 414 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: elist -> expr COMMA elist\n");
                                }
#line 2270 "out/parser.tab.cpp"
    break;

  case 64: /* elist: %empty  */
#line 418 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: elist -> /* empty */\n");
                                }
#line 2278 "out/parser.tab.cpp"
    break;

  case 65: /* objectdef: LEFT_BRACKET elist RIGHT_BRACKET  */
#line 423 "src/parser.y"
                                                {
                                                    fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET elist RIGHT_BRACKET\n");
                                                }
#line 2286 "out/parser.tab.cpp"
    break;

  case 66: /* objectdef: LEFT_BRACKET indexed RIGHT_BRACKET  */
#line 427 "src/parser.y"
                                                {
                                                    fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET indexed RIGHT_BRACKET\n");
                                                }
#line 2294 "out/parser.tab.cpp"
    break;

  case 67: /* indexed: indexedelem  */
#line 432 "src/parser.y"
                                                {
                                                    fprintf(yyout, "[-] Reduced: indexed -> indexedelem\n");
                                                }
#line 2302 "out/parser.tab.cpp"
    break;

  case 68: /* indexed: indexed COMMA indexedelem  */
#line 436 "src/parser.y"
                                                {
                                                    fprintf(yyout, "[-] Reduced: indexed -> indexed COMMA indexedelem\n");
                                                }
#line 2310 "out/parser.tab.cpp"
    break;

  case 69: /* indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE  */
#line 441 "src/parser.y"
                                                        {
                                                            fprintf(yyout, "[-] Reduced: indexedelem -> LEFT_BRACE expr COLON expr RIGHT_BRACE\n");
                                                        }
#line 2318 "out/parser.tab.cpp"
    break;

  case 70: /* $@1: %empty  */
#line 446 "src/parser.y"
                        {     
                                if (!inFunction) symTable.enter_scope();
                        }
#line 2326 "out/parser.tab.cpp"
    break;

  case 71: /* block: LEFT_BRACE $@1 stmt_list RIGHT_BRACE  */
#line 448 "src/parser.y"
                                                {       
                                                        symTable.exit_scope();
                                                        fprintf(yyout, "[-] Reduced: block -> LEFT_BRACE stmt_list RIGHT_BRACE\n");
                                                }
#line 2335 "out/parser.tab.cpp"
    break;

  case 72: /* $@2: %empty  */
#line 454 "src/parser.y"
                                                                                        {       
                                                                                                SymEntry* func = new SymEntry;
                                                                                                func->name = (yyvsp[-1].str_val);
                                                                                                func->type = FUNC;
                                                                                                func->scope = symTable.getScope();
                                                                                                func->line = (yylsp[-1]).first_line;
                                                                                                func->isActive = true;

                                                                                                int res = symTable.insert(func);
                                                                                                if (res == 2) myerror(&(yylsp[-1]), "Error: Redeclaration of Identifier in the same scope.\n");
                                                                                                if (res == 3) myerror(&(yylsp[-1]), "Error: Cannot shadow lib function.\n");

                                                                                                delete func;
                                                                                                symTable.enter_scope();
                                                                                                inFunction = true;

                                                                                                fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION IDENTIFIER LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                        }
#line 2358 "out/parser.tab.cpp"
    break;

  case 73: /* funcdef: FUNCTION IDENTIFIER LEFT_PARENTHESIS $@2 idlist RIGHT_PARENTHESIS block  */
#line 473 "src/parser.y"
                                                                                        {        
                                                                                                symTable.exit_scope();
                                                                                                inFunction = false;
                                                                                        }
#line 2367 "out/parser.tab.cpp"
    break;

  case 74: /* $@3: %empty  */
#line 477 "src/parser.y"
                                        {       
                                                SymEntry* func = new SymEntry;
                                                func->name = "Anonymous";
                                                func->type = FUNC;
                                                func->scope = symTable.getScope();
                                                func->line = (yylsp[-1]).first_line;
                                                func->isActive = true;

                                                int res = symTable.insert(func);
                                                if (res == 2) myerror(&(yylsp[-1]), "Error: Redeclaration of Identifier in the same scope.\n");
                                                if (res == 3) myerror(&(yylsp[-1]), "Error: Cannot shadow lib function.\n");

                                                delete func;
                                                symTable.enter_scope();
                                                inFunction = true;
                                        }
#line 2388 "out/parser.tab.cpp"
    break;

  case 75: /* funcdef: FUNCTION LEFT_PARENTHESIS $@3 idlist RIGHT_PARENTHESIS block  */
#line 493 "src/parser.y"
                                                               {
                                                                symTable.exit_scope();
                                                                inFunction = false;
                                                                fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                        }
#line 2398 "out/parser.tab.cpp"
    break;

  case 76: /* const: INTEGER  */
#line 501 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> INTEGER\n");
                        }
#line 2406 "out/parser.tab.cpp"
    break;

  case 77: /* const: REAL  */
#line 505 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> REAL\n");
                        }
#line 2414 "out/parser.tab.cpp"
    break;

  case 78: /* const: STRING  */
#line 509 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> STRING\n");
                        }
#line 2422 "out/parser.tab.cpp"
    break;

  case 79: /* const: TRUE  */
#line 513 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> TRUE\n");
                        }
#line 2430 "out/parser.tab.cpp"
    break;

  case 80: /* const: FALSE  */
#line 517 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> FALSE\n");
                        }
#line 2438 "out/parser.tab.cpp"
    break;

  case 81: /* const: NIL  */
#line 521 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> NIL\n");
                        }
#line 2446 "out/parser.tab.cpp"
    break;

  case 82: /* idlist: IDENTIFIER  */
#line 526 "src/parser.y"
                        {       SymEntry* arg = new SymEntry;
                                arg->name = (yyvsp[0].str_val);
                                arg->type = FORARG;
                                arg->scope = symTable.getScope();
                                arg->line = (yylsp[0]).first_line;
                                arg->isActive = true;

                                int res = symTable.insert(arg);
                                if (res == 2) myerror(&(yylsp[0]), "Error: Redeclaration of argument.\n");
                                if (res == 3) myerror(&(yylsp[0]), "Error: Cannot use lib function as formal argument.\n");

                                delete arg;
                                fprintf(yyout, "[-] Reduced: idlist -> IDENTIFIER\n");
                        }
#line 2465 "out/parser.tab.cpp"
    break;

  case 83: /* idlist: idlist COMMA IDENTIFIER  */
#line 540 "src/parser.y"
                                    {
                                        fprintf(yyout, "[-] Reduced: idlist -> idlist COMMA IDENTIFIER\n");
                                    }
#line 2473 "out/parser.tab.cpp"
    break;

  case 84: /* idlist: %empty  */
#line 543 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: idlist -> /* empty */\n");
                                }
#line 2481 "out/parser.tab.cpp"
    break;

  case 85: /* ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt  */
#line 548 "src/parser.y"
                                                                                {
                                                                                    fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                                }
#line 2489 "out/parser.tab.cpp"
    break;

  case 86: /* ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt  */
#line 552 "src/parser.y"
                                                                                {
                                                                                    fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");
                                                                                }
#line 2497 "out/parser.tab.cpp"
    break;

  case 87: /* $@4: %empty  */
#line 557 "src/parser.y"
                        {
                                rabbitHole++;
                        }
#line 2505 "out/parser.tab.cpp"
    break;

  case 88: /* whilestmt: WHILE $@4 LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt  */
#line 559 "src/parser.y"
                                                                         {
                                                                                rabbitHole--;
                                                                                fprintf(yyout, "[-] Reduced: whilestmt -> WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                        }
#line 2514 "out/parser.tab.cpp"
    break;

  case 89: /* $@5: %empty  */
#line 565 "src/parser.y"
                {
                        rabbitHole++;
                }
#line 2522 "out/parser.tab.cpp"
    break;

  case 90: /* forstmt: FOR $@5 LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt  */
#line 567 "src/parser.y"
                                                                                                {
                                                                                                        rabbitHole--;
                                                                                                        fprintf(yyout, "[-] Reduced: forstmt -> FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt\n");
                                                                                                }
#line 2531 "out/parser.tab.cpp"
    break;

  case 91: /* returnstmt: RETURN expr SEMICOLON  */
#line 573 "src/parser.y"
                                        {
                                            fprintf(yyout, "[-] Reduced: returnstmt -> RETURN expr SEMICOLON\n");
                                        }
#line 2539 "out/parser.tab.cpp"
    break;

  case 92: /* returnstmt: RETURN SEMICOLON  */
#line 576 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN SEMICOLON\n");
                                        }
#line 2547 "out/parser.tab.cpp"
    break;

  case 93: /* errors: ERROR_COMMENT  */
#line 581 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_COMMENT\n");
                                myerror(&(yylsp[0]), "Error: Invalid comment");
                                exit(1);
                        }
#line 2557 "out/parser.tab.cpp"
    break;

  case 94: /* errors: ERROR_STRING  */
#line 587 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_STRING\n");
                                myerror(&(yylsp[0]), "Error: Invalid string");
                                exit(1);
                        }
#line 2567 "out/parser.tab.cpp"
    break;

  case 95: /* errors: ERROR_ESCAPE  */
#line 593 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_ESCAPE\n");
                                myerror(&(yylsp[0]), "Error: Invalid escape sequence");
                                exit(1);
                        }
#line 2577 "out/parser.tab.cpp"
    break;

  case 96: /* errors: UNDEF  */
#line 599 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> UNDEF\n");
                                myerror(&(yylsp[0]), "Error: Undefined token");     
                                exit(1);
                        }
#line 2587 "out/parser.tab.cpp"
    break;


#line 2591 "out/parser.tab.cpp"

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

#line 605 "src/parser.y"



void myerror(YYLTYPE* loc, const char* msg) {
    fprintf(stderr, "Error at line %d, column %d: %s\n", loc->first_line, loc->first_column, msg);
}

void yyerror(const char* msg) {
    fprintf(stderr, "Bison error: %s\n", msg);
}
