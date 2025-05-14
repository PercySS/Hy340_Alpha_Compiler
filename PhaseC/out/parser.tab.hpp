/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_OUT_PARSER_TAB_HPP_INCLUDED
# define YY_YY_OUT_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MULTIPLY = 260,                /* MULTIPLY  */
    DIVIDE = 261,                  /* DIVIDE  */
    MODULO = 262,                  /* MODULO  */
    LESS_THAN = 263,               /* LESS_THAN  */
    LESS_THAN_EQUAL = 264,         /* LESS_THAN_EQUAL  */
    GREATER_THAN = 265,            /* GREATER_THAN  */
    GREATER_THAN_EQUAL = 266,      /* GREATER_THAN_EQUAL  */
    EQUAL = 267,                   /* EQUAL  */
    NOT_EQUAL = 268,               /* NOT_EQUAL  */
    INCREMENT = 269,               /* INCREMENT  */
    DECREMENT = 270,               /* DECREMENT  */
    ASSIGN = 271,                  /* ASSIGN  */
    PLUS_ASSIGN = 272,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 273,            /* MINUS_ASSIGN  */
    SEMICOLON = 274,               /* SEMICOLON  */
    COMMA = 275,                   /* COMMA  */
    COLON = 276,                   /* COLON  */
    DOUBLE_COLON = 277,            /* DOUBLE_COLON  */
    DOT = 278,                     /* DOT  */
    DOUBLE_DOT = 279,              /* DOUBLE_DOT  */
    LEFT_PARENTHESIS = 280,        /* LEFT_PARENTHESIS  */
    RIGHT_PARENTHESIS = 281,       /* RIGHT_PARENTHESIS  */
    LEFT_BRACE = 282,              /* LEFT_BRACE  */
    RIGHT_BRACE = 283,             /* RIGHT_BRACE  */
    LEFT_BRACKET = 284,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 285,           /* RIGHT_BRACKET  */
    UMINUS = 286,                  /* UMINUS  */
    IF = 287,                      /* IF  */
    ELSE = 288,                    /* ELSE  */
    WHILE = 289,                   /* WHILE  */
    FOR = 290,                     /* FOR  */
    FUNCTION = 291,                /* FUNCTION  */
    RETURN = 292,                  /* RETURN  */
    BREAK = 293,                   /* BREAK  */
    CONTINUE = 294,                /* CONTINUE  */
    TRUE = 295,                    /* TRUE  */
    FALSE = 296,                   /* FALSE  */
    NIL = 297,                     /* NIL  */
    LOCAL = 298,                   /* LOCAL  */
    AND = 299,                     /* AND  */
    NOT = 300,                     /* NOT  */
    OR = 301,                      /* OR  */
    INTEGER = 302,                 /* INTEGER  */
    REAL = 303,                    /* REAL  */
    STRINGT = 304,                 /* STRINGT  */
    IDENTIFIER = 305,              /* IDENTIFIER  */
    ERROR_COMMENT = 306,           /* ERROR_COMMENT  */
    ERROR_STRING = 307,            /* ERROR_STRING  */
    ERROR_ESCAPE = 308,            /* ERROR_ESCAPE  */
    UNDEF = 309,                   /* UNDEF  */
    LOWER_THAN_ELSE = 310          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "src/parser.y"

        int int_val;
        float float_val;
        char *str_val;
        struct SymEntry *node;
        struct expr *expr;
        struct call *callval;
        struct indexed *indexed;
        struct stmt_t *stmtval;
        struct forprefix *forprefix;

#line 131 "out/parser.tab.hpp"

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


#endif /* !YY_YY_OUT_PARSER_TAB_HPP_INCLUDED  */
