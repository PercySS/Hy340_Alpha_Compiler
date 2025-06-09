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
    SEMICOLON = 272,               /* SEMICOLON  */
    COMMA = 273,                   /* COMMA  */
    COLON = 274,                   /* COLON  */
    DOUBLE_COLON = 275,            /* DOUBLE_COLON  */
    DOT = 276,                     /* DOT  */
    DOUBLE_DOT = 277,              /* DOUBLE_DOT  */
    LEFT_PARENTHESIS = 278,        /* LEFT_PARENTHESIS  */
    RIGHT_PARENTHESIS = 279,       /* RIGHT_PARENTHESIS  */
    LEFT_BRACE = 280,              /* LEFT_BRACE  */
    RIGHT_BRACE = 281,             /* RIGHT_BRACE  */
    LEFT_BRACKET = 282,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 283,           /* RIGHT_BRACKET  */
    UMINUS = 284,                  /* UMINUS  */
    IF = 285,                      /* IF  */
    ELSE = 286,                    /* ELSE  */
    WHILE = 287,                   /* WHILE  */
    FOR = 288,                     /* FOR  */
    FUNCTION = 289,                /* FUNCTION  */
    RETURN = 290,                  /* RETURN  */
    BREAK = 291,                   /* BREAK  */
    CONTINUE = 292,                /* CONTINUE  */
    TRUE = 293,                    /* TRUE  */
    FALSE = 294,                   /* FALSE  */
    NIL = 295,                     /* NIL  */
    LOCAL = 296,                   /* LOCAL  */
    AND = 297,                     /* AND  */
    NOT = 298,                     /* NOT  */
    OR = 299,                      /* OR  */
    INTEGER = 300,                 /* INTEGER  */
    REAL = 301,                    /* REAL  */
    STRINGT = 302,                 /* STRINGT  */
    IDENTIFIER = 303,              /* IDENTIFIER  */
    ERROR_COMMENT = 304,           /* ERROR_COMMENT  */
    ERROR_STRING = 305,            /* ERROR_STRING  */
    ERROR_ESCAPE = 306,            /* ERROR_ESCAPE  */
    UNDEF = 307,                   /* UNDEF  */
    LOWER_THAN_ELSE = 308,         /* LOWER_THAN_ELSE  */
    PLUS_ASSIGN = 309,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 310             /* MINUS_ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "src/parser.y"

        int int_val;
        float float_val;
        char *str_val;
        struct SymEntry *node;
        struct expr *expr;
        struct call *callval;
        struct indexed *indexed;
        struct stmt_t *stmtval;
        unsigned offset;
        struct forprefix *forprefix;

#line 132 "out/parser.tab.hpp"

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
