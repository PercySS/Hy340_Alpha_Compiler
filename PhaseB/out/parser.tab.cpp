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
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
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
  YYSYMBOL_STRINGT = 48,                   /* STRINGT  */
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
  YYSYMBOL_84_5 = 84,                      /* $@5  */
  YYSYMBOL_forstmt = 85,                   /* forstmt  */
  YYSYMBOL_86_6 = 86,                      /* $@6  */
  YYSYMBOL_87_7 = 87,                      /* $@7  */
  YYSYMBOL_returnstmt = 88,                /* returnstmt  */
  YYSYMBOL_errors = 89                     /* errors  */
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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   555

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
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
       0,   136,   136,   141,   145,   149,   153,   157,   162,   167,
     171,   175,   179,   183,   188,   192,   197,   201,   205,   209,
     213,   217,   221,   225,   229,   233,   237,   241,   245,   249,
     253,   258,   262,   266,   270,   275,   280,   285,   290,   295,
     301,   306,   312,   316,   320,   324,   327,   332,   370,   394,
     404,   409,   413,   417,   421,   426,   430,   434,   439,   443,
     448,   453,   458,   462,   466,   471,   475,   480,   484,   489,
     494,   494,   502,   502,   543,   543,   567,   571,   575,   579,
     583,   587,   592,   616,   640,   645,   649,   654,   656,   654,
     665,   667,   665,   676,   679,   684,   690,   696,   702
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
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "LESS_THAN", "LESS_THAN_EQUAL",
  "GREATER_THAN", "GREATER_THAN_EQUAL", "EQUAL", "NOT_EQUAL", "INCREMENT",
  "DECREMENT", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "SEMICOLON",
  "COMMA", "COLON", "DOUBLE_COLON", "DOT", "DOUBLE_DOT",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_BRACE", "RIGHT_BRACE",
  "LEFT_BRACKET", "RIGHT_BRACKET", "IF", "ELSE", "WHILE", "FOR",
  "FUNCTION", "RETURN", "BREAK", "CONTINUE", "TRUE", "FALSE", "NIL",
  "LOCAL", "AND", "NOT", "OR", "INTEGER", "REAL", "STRINGT", "IDENTIFIER",
  "ERROR_COMMENT", "ERROR_STRING", "ERROR_ESCAPE", "UNDEF",
  "LOWER_THAN_ELSE", "UMINUS", "$accept", "program", "stmt", "stmt_list",
  "expr", "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef", "indexed",
  "indexedelem", "block", "$@1", "funcdef", "$@2", "$@3", "const",
  "idlist", "ifstmt", "whilestmt", "$@4", "$@5", "forstmt", "$@6", "$@7",
  "returnstmt", "errors", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     146,   304,    15,    15,  -130,   -43,   187,  -130,   226,    16,
      21,    47,    -4,   265,    70,    78,  -130,  -130,  -130,    61,
     304,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,    93,
     146,  -130,    20,  -130,  -130,  -130,   190,  -130,   122,  -130,
    -130,  -130,  -130,    79,  -130,  -130,  -130,  -130,  -130,    77,
      44,   122,    44,  -130,   113,    87,   146,   304,   510,    22,
      23,  -130,   304,  -130,  -130,  -130,   116,  -130,   124,  -130,
    -130,  -130,   510,  -130,  -130,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,  -130,   304,   304,  -130,
    -130,   304,   304,   304,   100,   103,   304,   304,  -130,  -130,
    -130,   117,   304,   304,   146,   136,  -130,   147,   114,   351,
     304,  -130,   162,  -130,   371,   304,   304,   125,  -130,  -130,
      95,   510,    95,    95,    95,     5,     5,     5,     5,    -9,
      -9,   155,  -130,  -130,  -130,  -130,  -130,   178,    29,   395,
    -130,    34,   423,  -130,   147,   304,  -130,   304,   510,  -130,
     146,   438,    39,  -130,    74,   125,   304,  -130,  -130,  -130,
    -130,   128,   466,  -130,  -130,   304,   161,   184,   133,   137,
    -130,  -130,   146,   493,  -130,  -130,   184,  -130,  -130,   304,
    -130,   150,  -130,   146,  -130
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      15,     0,     0,     0,    12,     0,     0,    70,    64,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,     0,
       0,    76,    77,    78,    47,    95,    96,    97,    98,     0,
      15,     2,     0,    30,    16,    38,    42,    50,    43,    44,
      10,    11,    46,     4,     5,     6,     7,    13,    32,     0,
      34,     0,    36,    49,     0,     0,    15,     0,    62,     0,
       0,    67,     0,    87,    90,    74,     0,    94,     0,     8,
       9,    48,    33,     1,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,    35,
      37,     0,     0,     0,     0,     0,    64,     0,    56,    58,
      59,     0,    64,     0,     0,     0,    31,    45,     0,     0,
       0,    65,     0,    66,     0,     0,    64,    84,    72,    93,
      17,    18,    19,    20,    21,    23,    25,    22,    24,    26,
      27,    28,    29,    39,    40,    41,    51,     0,     0,     0,
      53,     0,     0,    86,     0,    64,    71,     0,    63,    68,
       0,     0,     0,    82,     0,    84,    64,    60,    52,    55,
      54,     0,     0,    85,    88,     0,     0,     0,     0,     0,
      57,    69,     0,     0,    83,    75,     0,    61,    89,    64,
      73,     0,    91,     0,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,   -84,   -21,    -1,  -130,  -130,  -130,     8,  -130,
      68,  -130,  -130,  -130,   -94,  -130,  -130,   105,  -129,  -130,
      -5,  -130,  -130,  -130,    63,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    98,    99,   100,    59,    39,    60,    61,    40,    56,
      41,   155,   117,    42,   154,    43,    44,   115,   172,    45,
     116,   183,    46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    55,   138,    -1,    -1,    54,    53,    58,   141,    74,
      50,    52,    68,    -1,    -1,    -1,    -1,    84,    85,    72,
     143,    65,   152,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    87,   108,    88,     5,   175,    86,
      49,    62,   110,   112,   105,    66,    63,   180,    87,   110,
      88,   161,   111,   113,   110,   157,   109,    19,   165,   110,
     159,   114,   169,    87,    24,    88,   163,    94,    95,    96,
      51,    51,    64,    97,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   181,   131,   132,   178,    69,
     133,   134,   135,    73,   166,    58,   139,    70,    75,   184,
     167,    58,   142,    80,    81,    82,    83,    84,    85,   148,
      71,   104,    12,   107,   151,    58,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    87,   106,
      88,   118,   146,   119,    58,   101,   162,   102,   110,   136,
       1,   103,   137,   166,   170,    58,    87,   110,    88,   176,
       2,     3,   144,   177,   173,     4,   140,    87,     5,    88,
     110,     6,   145,     7,   153,     8,   182,     9,    58,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    57,
      20,     1,    21,    22,    23,    24,    25,    26,    27,    28,
      88,     2,     3,   156,    89,    90,    91,    92,    93,     5,
     174,     7,     6,    94,    95,    96,     8,   149,   168,    97,
       0,     0,    12,     0,     0,     0,    16,    17,    18,    19,
       1,    20,     0,    21,    22,    23,    24,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,     5,     0,
       0,     6,     0,    57,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    18,    19,     1,
      20,     0,    21,    22,    23,    24,     0,     0,     0,     2,
       3,     0,     0,     0,    67,     0,     0,     5,     0,     0,
       6,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,     1,    20,
       0,    21,    22,    23,    24,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     6,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,     0,    20,     0,
      21,    22,    23,    24,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,   147,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,    88,   150,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    87,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,   158,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,    87,     0,
      88,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,     0,    87,     0,    88,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    87,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    87,
       0,    88,   179,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,    88
};

static const yytype_int16 yycheck[] =
{
       1,     6,    96,    12,    13,     6,    49,     8,   102,    30,
       2,     3,    13,     8,     9,    10,    11,    12,    13,    20,
     104,    25,   116,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    43,    56,    45,    22,   167,    19,
      25,    25,    20,    20,    49,    49,    25,   176,    43,    20,
      45,   145,    30,    30,    20,    26,    57,    42,    19,    20,
      26,    62,   156,    43,    49,    45,   150,    23,    24,    25,
       2,     3,    25,    29,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   179,    87,    88,   172,    19,
      91,    92,    93,     0,    20,    96,    97,    19,     3,   183,
      26,   102,   103,     8,     9,    10,    11,    12,    13,   110,
      49,    32,    35,    26,   115,   116,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    43,    26,
      45,    25,    28,    19,   145,    23,   147,    25,    20,    49,
       4,    29,    49,    20,    26,   156,    43,    20,    45,    26,
      14,    15,    26,    26,   165,    19,    49,    43,    22,    45,
      20,    25,    25,    27,    49,    29,    26,    31,   179,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    27,
      44,     4,    46,    47,    48,    49,    50,    51,    52,    53,
      45,    14,    15,    25,    14,    15,    16,    17,    18,    22,
      49,    27,    25,    23,    24,    25,    29,   112,   155,    29,
      -1,    -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,
       4,    44,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    27,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,     4,
      44,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    19,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,     4,    44,
      -1,    46,    47,    48,    49,    -1,    -1,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    44,    -1,
      46,    47,    48,    49,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    45,    26,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    43,    -1,
      45,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    43,    -1,    45,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    43,
      -1,    45,    19,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    14,    15,    19,    22,    25,    27,    29,    31,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      44,    46,    47,    48,    49,    50,    51,    52,    53,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    71,
      74,    76,    79,    81,    82,    85,    88,    89,    60,    25,
      64,    66,    64,    49,    60,    76,    75,    27,    60,    70,
      72,    73,    25,    25,    25,    25,    49,    19,    60,    19,
      19,    49,    60,     0,    59,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    19,    43,    45,    14,
      15,    16,    17,    18,    23,    24,    25,    29,    67,    68,
      69,    23,    25,    29,    32,    76,    26,    26,    59,    60,
      20,    30,    20,    30,    60,    83,    86,    78,    25,    19,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    49,    49,    70,    60,
      49,    70,    60,    58,    26,    25,    28,    21,    60,    73,
      26,    60,    70,    49,    80,    77,    25,    26,    30,    26,
      30,    70,    60,    58,    26,    19,    20,    26,    80,    70,
      26,    28,    84,    60,    49,    74,    26,    26,    58,    19,
      74,    70,    26,    87,    58
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
      79,    79,    80,    80,    80,    81,    81,    83,    84,    82,
      86,    87,    85,    88,    88,    89,    89,    89,    89
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
       1,     1,     1,     3,     0,     5,     3,     0,     0,     7,
       0,     0,    11,     3,     2,     1,     1,     1,     1
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
  case 2: /* program: stmt_list  */
#line 136 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: program -> stmt_list\n");
                        }
#line 1488 "out/parser.tab.cpp"
    break;

  case 3: /* stmt: expr SEMICOLON  */
#line 141 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: stmt -> expr SEMICOLON\n");
                        }
#line 1496 "out/parser.tab.cpp"
    break;

  case 4: /* stmt: ifstmt  */
#line 145 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: stmt -> ifstmt\n");
                        }
#line 1504 "out/parser.tab.cpp"
    break;

  case 5: /* stmt: whilestmt  */
#line 149 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: stmt -> whilestmt\n");
                        }
#line 1512 "out/parser.tab.cpp"
    break;

  case 6: /* stmt: forstmt  */
#line 153 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: stmt -> forstmt\n");
                        }
#line 1520 "out/parser.tab.cpp"
    break;

  case 7: /* stmt: returnstmt  */
#line 157 "src/parser.y"
                        {       
                                if (symTable.funcStack.empty()) fprintf(yyout, "      [!] Error: Return statement outside of function in line %d.", yylineno);
                                fprintf(yyout, "[-] Reduced: stmt -> returnstmt\n");
                        }
#line 1529 "out/parser.tab.cpp"
    break;

  case 8: /* stmt: BREAK SEMICOLON  */
#line 162 "src/parser.y"
                                {       
                                        if (rabbitHole < 1)  fprintf(yyout, "      [!] Error: Break statement outside of loop in line %d.", yylineno);
                                        fprintf(yyout, "[-] Reduced: stmt -> BREAK SEMICOLON\n");
                                }
#line 1538 "out/parser.tab.cpp"
    break;

  case 9: /* stmt: CONTINUE SEMICOLON  */
#line 167 "src/parser.y"
                                {       
                                        if (rabbitHole < 1) fprintf(yyout, "      [!] Error: Continue statement outside of loop in line %d.", yylineno);
                                        fprintf(yyout, "[-] Reduced: stmt -> CONTINUE SEMICOLON\n");
                                }
#line 1547 "out/parser.tab.cpp"
    break;

  case 10: /* stmt: block  */
#line 171 "src/parser.y"
                                {       
                                        fprintf(yyout, "[-] Reduced: stmt -> block\n");
                                }
#line 1555 "out/parser.tab.cpp"
    break;

  case 11: /* stmt: funcdef  */
#line 175 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: stmt -> funcdef\n");
                                }
#line 1563 "out/parser.tab.cpp"
    break;

  case 12: /* stmt: SEMICOLON  */
#line 179 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: stmt -> SEMICOLON\n");
                                }
#line 1571 "out/parser.tab.cpp"
    break;

  case 13: /* stmt: errors  */
#line 183 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: stmt -> errors\n");
                                }
#line 1579 "out/parser.tab.cpp"
    break;

  case 14: /* stmt_list: stmt stmt_list  */
#line 188 "src/parser.y"
                               {
                                        fprintf(yyout, "[-] Reduced: stmt_list -> stmt stmt_list\n");
                                }
#line 1587 "out/parser.tab.cpp"
    break;

  case 15: /* stmt_list: %empty  */
#line 192 "src/parser.y"
                                {       
                                        fprintf(yyout, "[-] Reduced: stmt_list -> /* empty */\n");
                                }
#line 1595 "out/parser.tab.cpp"
    break;

  case 16: /* expr: assignexpr  */
#line 197 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> assignexpr\n");
                                }
#line 1603 "out/parser.tab.cpp"
    break;

  case 17: /* expr: expr PLUS expr  */
#line 201 "src/parser.y"
                                {       
                                        fprintf(yyout, "[-] Reduced: expr -> expr PLUS expr\n");
                                }
#line 1611 "out/parser.tab.cpp"
    break;

  case 18: /* expr: expr MINUS expr  */
#line 205 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> expr MINUS expr\n");
                                }
#line 1619 "out/parser.tab.cpp"
    break;

  case 19: /* expr: expr MULTIPLY expr  */
#line 209 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> expr MULTIPLY expr\n");
                                }
#line 1627 "out/parser.tab.cpp"
    break;

  case 20: /* expr: expr DIVIDE expr  */
#line 213 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> expr DIVIDE expr\n");
                                }
#line 1635 "out/parser.tab.cpp"
    break;

  case 21: /* expr: expr MODULO expr  */
#line 217 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: expr -> expr MODULO expr\n");
                                }
#line 1643 "out/parser.tab.cpp"
    break;

  case 22: /* expr: expr GREATER_THAN expr  */
#line 221 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN expr\n");
                                        }
#line 1651 "out/parser.tab.cpp"
    break;

  case 23: /* expr: expr LESS_THAN expr  */
#line 225 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN expr\n");
                                        }
#line 1659 "out/parser.tab.cpp"
    break;

  case 24: /* expr: expr GREATER_THAN_EQUAL expr  */
#line 229 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr GREATER_THAN_EQUAL expr\n");
                                        }
#line 1667 "out/parser.tab.cpp"
    break;

  case 25: /* expr: expr LESS_THAN_EQUAL expr  */
#line 233 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr LESS_THAN_EQUAL expr\n");
                                        }
#line 1675 "out/parser.tab.cpp"
    break;

  case 26: /* expr: expr EQUAL expr  */
#line 237 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr EQUAL expr\n");
                                        }
#line 1683 "out/parser.tab.cpp"
    break;

  case 27: /* expr: expr NOT_EQUAL expr  */
#line 241 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr NOT_EQUAL expr\n");
                                        }
#line 1691 "out/parser.tab.cpp"
    break;

  case 28: /* expr: expr AND expr  */
#line 245 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr AND expr\n");
                                        }
#line 1699 "out/parser.tab.cpp"
    break;

  case 29: /* expr: expr OR expr  */
#line 249 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> expr OR expr\n");
                                        }
#line 1707 "out/parser.tab.cpp"
    break;

  case 30: /* expr: term  */
#line 253 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: expr -> term\n");
                                        }
#line 1715 "out/parser.tab.cpp"
    break;

  case 31: /* term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 258 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: term -> LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                }
#line 1723 "out/parser.tab.cpp"
    break;

  case 32: /* term: MINUS expr  */
#line 262 "src/parser.y"
                                                { 
                                                        fprintf(yyout, "[-] Reduced: term -> MINUS expr\n");
                                                }
#line 1731 "out/parser.tab.cpp"
    break;

  case 33: /* term: NOT expr  */
#line 266 "src/parser.y"
                                                { 
                                                        fprintf(yyout, "[-] Reduced: term -> NOT expr\n");
                                                }
#line 1739 "out/parser.tab.cpp"
    break;

  case 34: /* term: INCREMENT lvalue  */
#line 270 "src/parser.y"
                                                {       
                                                        if ((yyvsp[0].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (++func) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: term -> INCREMENT lvalue\n");
                                                }
#line 1748 "out/parser.tab.cpp"
    break;

  case 35: /* term: lvalue INCREMENT  */
#line 275 "src/parser.y"
                                                {       
                                                        if ((yyvsp[-1].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func++) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue INCREMENT\n");
                                                }
#line 1757 "out/parser.tab.cpp"
    break;

  case 36: /* term: DECREMENT lvalue  */
#line 280 "src/parser.y"
                                                {       
                                                        if ((yyvsp[0].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (--func) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: term -> DECREMENT lvalue\n");
                                                }
#line 1766 "out/parser.tab.cpp"
    break;

  case 37: /* term: lvalue DECREMENT  */
#line 285 "src/parser.y"
                                                {       
                                                        if ((yyvsp[-1].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func--) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue DECREMENT\n");
                                                }
#line 1775 "out/parser.tab.cpp"
    break;

  case 38: /* term: primary  */
#line 290 "src/parser.y"
                                                {
                                                        fprintf(yyout, "[-] Reduced: term -> primary\n");
                                                }
#line 1783 "out/parser.tab.cpp"
    break;

  case 39: /* assignexpr: lvalue ASSIGN expr  */
#line 295 "src/parser.y"
                                                {       
                                                        if ((yyvsp[-2].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func = expr) in line %d.", yylineno);
                                                        if ((yyvsp[-2].node)->type == LIBFUNC) fprintf(yyout, "      [!] Error: Cannot assign to library function in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
                                                }
#line 1793 "out/parser.tab.cpp"
    break;

  case 40: /* assignexpr: lvalue PLUS_ASSIGN expr  */
#line 301 "src/parser.y"
                                                {       
                                                        if ((yyvsp[-2].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func += expr) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue PLUS_ASSIGN expr\n");
                                                }
#line 1802 "out/parser.tab.cpp"
    break;

  case 41: /* assignexpr: lvalue MINUS_ASSIGN expr  */
#line 306 "src/parser.y"
                                                {
                                                        if ((yyvsp[-2].node)->type == FUNC) fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func -= expr) in line %d.", yylineno);
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue MINUS_ASSIGN expr\n");
                                                }
#line 1811 "out/parser.tab.cpp"
    break;

  case 42: /* primary: lvalue  */
#line 312 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: primary -> lvalue\n");
                                }
#line 1819 "out/parser.tab.cpp"
    break;

  case 43: /* primary: call  */
#line 316 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: primary -> call\n");
                                }
#line 1827 "out/parser.tab.cpp"
    break;

  case 44: /* primary: objectdef  */
#line 320 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: primary -> objectdef\n");
                                }
#line 1835 "out/parser.tab.cpp"
    break;

  case 45: /* primary: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS  */
#line 324 "src/parser.y"
                                                        {
                                                            fprintf(yyout, "[-] Reduced: primary -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS\n");
                                                        }
#line 1843 "out/parser.tab.cpp"
    break;

  case 46: /* primary: const  */
#line 327 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: primary -> const\n");
                                }
#line 1851 "out/parser.tab.cpp"
    break;

  case 47: /* lvalue: IDENTIFIER  */
#line 332 "src/parser.y"
                                {       
                                        SymEntry* found;
                                        // Check for libfunc shadowing
                                        if ((found = symTable.lookup((yyvsp[0].str_val), 0))) {
                                                if (found->type == LIBFUNC) (yyval.node) = found;
                                        }

                                        found = symTable.lookup((yyvsp[0].str_val));

                                        if (!found) {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = (yyvsp[0].str_val);
                                                entry->type = VAR;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;

                                                symTable.insert(entry);
                                                (yyval.node) = entry;
                                        } else {
                                                if (found->type == VAR) {
                                                        if (symTable.funcStack.empty()) {
                                                                (yyval.node) = found;
                                                        } else {
                                                                if (found->scope == symTable.getScope() || found->scope == 0) {
                                                                        (yyval.node) = found;
                                                                } else {
                                                                     fprintf(yyout, "      [!] Error: Variable %s is not accessible in line %d.", (yyvsp[0].str_val), yylineno); 
                                                                }
                                                        }
                                                } else {
                                                        (yyval.node) = found;
                                                }
                                        }

                                        fprintf(yyout, "[-] Reduced: lvalue -> IDENTIFIER\n");
                                }
#line 1893 "out/parser.tab.cpp"
    break;

  case 48: /* lvalue: LOCAL IDENTIFIER  */
#line 370 "src/parser.y"
                                {       
                                        SymEntry* found;
                                        if ((found = symTable.lookup((yyvsp[0].str_val), 0))) {
                                                if (found->type == LIBFUNC) fprintf(yyout, "      [!] Error: Local variable is shadowing library function in line %d.", yylineno);
                                        } 
                                        
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
                                        fprintf(yyout, "[-] Reduced: lvalue -> LOCAL IDENTIFIER\n");
                                }
#line 1921 "out/parser.tab.cpp"
    break;

  case 49: /* lvalue: DOUBLE_COLON IDENTIFIER  */
#line 394 "src/parser.y"
                                        {       
                                                SymEntry* found = symTable.lookup((yyvsp[0].str_val), 0);
                                                if (!found) {
                                                        fprintf(yyout, "      [!] Error: Token %s has not been declared in global scope in line %d.", (yyvsp[0].str_val), yylineno);
                                                } else {
                                                        (yyval.node) = found;
                                                }
                                                fprintf(yyout, "[-] Reduced: lvalue -> DOUBLE_COLON IDENTIFIER\n");
                                        }
#line 1935 "out/parser.tab.cpp"
    break;

  case 50: /* lvalue: member  */
#line 404 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: lvalue -> member\n");
                                        }
#line 1943 "out/parser.tab.cpp"
    break;

  case 51: /* member: lvalue DOT IDENTIFIER  */
#line 409 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: member -> lvalue DOT IDENTIFIER\n");
                                }
#line 1951 "out/parser.tab.cpp"
    break;

  case 52: /* member: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 413 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: member -> lvalue LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }
#line 1959 "out/parser.tab.cpp"
    break;

  case 53: /* member: call DOT IDENTIFIER  */
#line 417 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: member -> call DOT IDENTIFIER\n");
                                                        }
#line 1967 "out/parser.tab.cpp"
    break;

  case 54: /* member: call LEFT_BRACKET expr RIGHT_BRACKET  */
#line 421 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: member -> call LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }
#line 1975 "out/parser.tab.cpp"
    break;

  case 55: /* call: call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 426 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: call -> call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
#line 1983 "out/parser.tab.cpp"
    break;

  case 56: /* call: lvalue callsuffix  */
#line 430 "src/parser.y"
                                                        {
                                                                fprintf(yyout, "[-] Reduced: call -> lvalue callsuffix\n");
                                                        }
#line 1991 "out/parser.tab.cpp"
    break;

  case 57: /* call: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 434 "src/parser.y"
                                                                                                {
                                                                                                    fprintf(yyout, "[-] Reduced: call -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                }
#line 1999 "out/parser.tab.cpp"
    break;

  case 58: /* callsuffix: normcall  */
#line 439 "src/parser.y"
                                {
                                    fprintf(yyout, "[-] Reduced: callsuffix -> normcall\n");
                                }
#line 2007 "out/parser.tab.cpp"
    break;

  case 59: /* callsuffix: methodcall  */
#line 443 "src/parser.y"
                                {
                                    fprintf(yyout, "[-] Reduced: callsuffix -> methodcall\n");
                                }
#line 2015 "out/parser.tab.cpp"
    break;

  case 60: /* normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 448 "src/parser.y"
                                                        {
                                                            fprintf(yyout, "[-] Reduced: normcall -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
#line 2023 "out/parser.tab.cpp"
    break;

  case 61: /* methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 453 "src/parser.y"
                                                                                {
                                                                                    fprintf(yyout, "[-] Reduced: methodcall -> DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                }
#line 2031 "out/parser.tab.cpp"
    break;

  case 62: /* elist: expr  */
#line 458 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: elist -> expr\n");
                                }
#line 2039 "out/parser.tab.cpp"
    break;

  case 63: /* elist: elist COMMA expr  */
#line 462 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: elist -> expr COMMA elist\n");
                                }
#line 2047 "out/parser.tab.cpp"
    break;

  case 64: /* elist: %empty  */
#line 466 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: elist -> /* empty */\n");
                                }
#line 2055 "out/parser.tab.cpp"
    break;

  case 65: /* objectdef: LEFT_BRACKET elist RIGHT_BRACKET  */
#line 471 "src/parser.y"
                                                {
                                                    fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET elist RIGHT_BRACKET\n");
                                                }
#line 2063 "out/parser.tab.cpp"
    break;

  case 66: /* objectdef: LEFT_BRACKET indexed RIGHT_BRACKET  */
#line 475 "src/parser.y"
                                                {
                                                    fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET indexed RIGHT_BRACKET\n");
                                                }
#line 2071 "out/parser.tab.cpp"
    break;

  case 67: /* indexed: indexedelem  */
#line 480 "src/parser.y"
                                                {
                                                    fprintf(yyout, "[-] Reduced: indexed -> indexedelem\n");
                                                }
#line 2079 "out/parser.tab.cpp"
    break;

  case 68: /* indexed: indexed COMMA indexedelem  */
#line 484 "src/parser.y"
                                                {
                                                    fprintf(yyout, "[-] Reduced: indexed -> indexed COMMA indexedelem\n");
                                                }
#line 2087 "out/parser.tab.cpp"
    break;

  case 69: /* indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE  */
#line 489 "src/parser.y"
                                                        {
                                                            fprintf(yyout, "[-] Reduced: indexedelem -> LEFT_BRACE expr COLON expr RIGHT_BRACE\n");
                                                        }
#line 2095 "out/parser.tab.cpp"
    break;

  case 70: /* $@1: %empty  */
#line 494 "src/parser.y"
                        { 
                                if (!skipBlockScope) symTable.enter_scope(); 
                        }
#line 2103 "out/parser.tab.cpp"
    break;

  case 71: /* block: LEFT_BRACE $@1 stmt_list RIGHT_BRACE  */
#line 496 "src/parser.y"
                                                {
                                                        symTable.exit_scope();      
                                                        fprintf(yyout, "[-] Reduced: block -> LEFT_BRACE stmt_list RIGHT_BRACE\n");
                                                }
#line 2112 "out/parser.tab.cpp"
    break;

  case 72: /* $@2: %empty  */
#line 502 "src/parser.y"
                                              {
                                                skipBlockScope = true;
                                                SymEntry* found = symTable.lookup((yyvsp[-1].str_val), 0);

                                                if (found) {
                                                        if (found->type == LIBFUNC) fprintf(yyout, "      [!] Error : Function shadowing library function in line %d.", yylineno);
                                                }
                                                
                                                found = symTable.lookup((yyvsp[-1].str_val), symTable.getScope());

                                                if (!found) {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = (yyvsp[-1].str_val);
                                                        entry->type = FUNC;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;

                                                        symTable.funcStack.push(entry);
                                                        entry->args.clear();
                                                        symTable.insert(entry);
                                                        fprintf(yyout, "\n                       %s\n", symTable.funcStack.top()->name.c_str());
                                                } else {
                                                        if (found->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Function %s already declared in line %d.", (yyvsp[-1].str_val), yylineno);
                                                        } else if (found->type == VAR) {
                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing variable in line %d.", (yyvsp[-1].str_val), yylineno);
                                                        } else if (found->type == FORARG) {
                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing formal argument in line %d.", (yyvsp[-1].str_val), yylineno);
                                                        } 
                                                }
                                                symTable.enter_scope();

                                                }
#line 2151 "out/parser.tab.cpp"
    break;

  case 73: /* funcdef: FUNCTION IDENTIFIER LEFT_PARENTHESIS $@2 idlist RIGHT_PARENTHESIS block  */
#line 535 "src/parser.y"
                                                                                 {      
                                                                                        symTable.funcStack.pop();
                                                                                        if (symTable.funcStack.empty()) {
                                                                                                skipBlockScope = false;
                                                                                        }
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION IDENTIFIER LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
#line 2163 "out/parser.tab.cpp"
    break;

  case 74: /* $@3: %empty  */
#line 543 "src/parser.y"
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

                                                symTable.enter_scope();
                                                skipBlockScope = true;
                                        }
#line 2185 "out/parser.tab.cpp"
    break;

  case 75: /* funcdef: FUNCTION LEFT_PARENTHESIS $@3 idlist RIGHT_PARENTHESIS block  */
#line 559 "src/parser.y"
                                                                                {       
                                                                                        symTable.funcStack.pop();
                                                                                        skipBlockScope = false;
                                                                                        fprintf(yyout, "[-] Reduced: funcdef -> FUNCTION LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block\n");
                                                                                }
#line 2195 "out/parser.tab.cpp"
    break;

  case 76: /* const: INTEGER  */
#line 567 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> INTEGER\n");
                        }
#line 2203 "out/parser.tab.cpp"
    break;

  case 77: /* const: REAL  */
#line 571 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> REAL\n");
                        }
#line 2211 "out/parser.tab.cpp"
    break;

  case 78: /* const: STRINGT  */
#line 575 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> STRING\n");
                        }
#line 2219 "out/parser.tab.cpp"
    break;

  case 79: /* const: TRUE  */
#line 579 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> TRUE\n");
                        }
#line 2227 "out/parser.tab.cpp"
    break;

  case 80: /* const: FALSE  */
#line 583 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> FALSE\n");
                        }
#line 2235 "out/parser.tab.cpp"
    break;

  case 81: /* const: NIL  */
#line 587 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: const -> NIL\n");
                        }
#line 2243 "out/parser.tab.cpp"
    break;

  case 82: /* idlist: IDENTIFIER  */
#line 592 "src/parser.y"
                        {       
                                SymEntry* found;

                                if ((found = symTable.lookup((yyvsp[0].str_val), 0))) {
                                        if (found->type == LIBFUNC) fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.", yylineno);

                                }
                                
                                if ((found = symTable.lookup((yyvsp[0].str_val), symTable.getScope()))) {
                                        if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.", yylineno);
                                } else {
                                        SymEntry* entry = new SymEntry;
                                        entry->name = (yyvsp[0].str_val);
                                        entry->type = FORARG;
                                        entry->scope = symTable.getScope();
                                        entry->line = yylineno;
                                        entry->isActive = true;

                                        symTable.funcStack.top()->args.push_back(entry);
                                        symTable.insert(entry);
                                }
                                
                                fprintf(yyout, "[-] Reduced: idlist -> IDENTIFIER\n");
                        }
#line 2272 "out/parser.tab.cpp"
    break;

  case 83: /* idlist: idlist COMMA IDENTIFIER  */
#line 616 "src/parser.y"
                                    {   
                                        SymEntry* found;

                                        if ((found = symTable.lookup((yyvsp[0].str_val), 0))) {
                                                if (found->type == LIBFUNC) fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.", yylineno);

                                        } 
                                        
                                        if ((found = symTable.lookup((yyvsp[0].str_val), symTable.getScope()))) {
                                                if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.", yylineno);
                                        } else {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = (yyvsp[0].str_val);
                                                entry->type = FORARG;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;

                                                symTable.funcStack.top()->args.push_back(entry);
                                                symTable.insert(entry);
                                        }

                                        fprintf(yyout, "[-] Reduced: idlist -> idlist COMMA IDENTIFIER\n");
                                    }
#line 2301 "out/parser.tab.cpp"
    break;

  case 84: /* idlist: %empty  */
#line 640 "src/parser.y"
                                {
                                        fprintf(yyout, "[-] Reduced: idlist -> /* empty */\n");
                                }
#line 2309 "out/parser.tab.cpp"
    break;

  case 85: /* ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt  */
#line 645 "src/parser.y"
                                                                                {
                                                                                    fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                                }
#line 2317 "out/parser.tab.cpp"
    break;

  case 86: /* ifstmt: ifstmt ELSE stmt  */
#line 649 "src/parser.y"
                                       {
                                                                                    fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");
                                                                                }
#line 2325 "out/parser.tab.cpp"
    break;

  case 87: /* $@4: %empty  */
#line 654 "src/parser.y"
                                        {
                                        rabbitHole++;
                                        }
#line 2333 "out/parser.tab.cpp"
    break;

  case 88: /* $@5: %empty  */
#line 656 "src/parser.y"
                                                                        {
                                                                                symTable.enter_scope();
                                                                        }
#line 2341 "out/parser.tab.cpp"
    break;

  case 89: /* whilestmt: WHILE LEFT_PARENTHESIS $@4 expr RIGHT_PARENTHESIS $@5 stmt  */
#line 658 "src/parser.y"
                                                                                {       
                                                                                        rabbitHole--;
                                                                                        symTable.exit_scope();
                                                                                        fprintf(yyout, "[-] Reduced: whilestmt -> WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                                                                }
#line 2351 "out/parser.tab.cpp"
    break;

  case 90: /* $@6: %empty  */
#line 665 "src/parser.y"
                                {
                                        rabbitHole++;
                                }
#line 2359 "out/parser.tab.cpp"
    break;

  case 91: /* $@7: %empty  */
#line 667 "src/parser.y"
                                                                                         {
                                                                                                        symTable.enter_scope();
                                                                                                }
#line 2367 "out/parser.tab.cpp"
    break;

  case 92: /* forstmt: FOR LEFT_PARENTHESIS $@6 elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS $@7 stmt  */
#line 669 "src/parser.y"
                                                                                                         {       
                                                                                                        rabbitHole--;
                                                                                                        symTable.exit_scope();
                                                                                                        fprintf(yyout, "[-] Reduced: forstmt -> FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt\n");
                                                                                                }
#line 2377 "out/parser.tab.cpp"
    break;

  case 93: /* returnstmt: RETURN expr SEMICOLON  */
#line 676 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN expr SEMICOLON\n");
                                        }
#line 2385 "out/parser.tab.cpp"
    break;

  case 94: /* returnstmt: RETURN SEMICOLON  */
#line 679 "src/parser.y"
                                        {
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN SEMICOLON\n");
                                        }
#line 2393 "out/parser.tab.cpp"
    break;

  case 95: /* errors: ERROR_COMMENT  */
#line 684 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_COMMENT\n");
                                fprintf(yyout, "      [!] Error: Invalid comment in line %d.", yylineno);
                                exit(1);
                        }
#line 2403 "out/parser.tab.cpp"
    break;

  case 96: /* errors: ERROR_STRING  */
#line 690 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_STRING\n");
                                fprintf(yyout, "      [!] Error: Invalid string in line %d.", yylineno);
                                exit(1);
                        }
#line 2413 "out/parser.tab.cpp"
    break;

  case 97: /* errors: ERROR_ESCAPE  */
#line 696 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_ESCAPE\n");
                                fprintf(yyout, "      [!] Error: Invalid escape sequence in line %d.", yylineno);
                                exit(1);
                        }
#line 2423 "out/parser.tab.cpp"
    break;

  case 98: /* errors: UNDEF  */
#line 702 "src/parser.y"
                        {
                                fprintf(yyout, "[-] Reduced: errors -> UNDEF\n");
                                fprintf(yyout, "      [!] Error: Undefined variable in line %d.", yylineno);    
                                exit(1);
                        }
#line 2433 "out/parser.tab.cpp"
    break;


#line 2437 "out/parser.tab.cpp"

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

#line 708 "src/parser.y"


void yyerror(const char* msg) {
    fprintf(stderr, "Bison error: %s\n", msg);
}
