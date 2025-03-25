// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 13 "parser.y"

#include <iostream>
#include <string>
#include <cstdarg>
#include <cstdio>
#include "../symtable/symtable.hpp"

extern int yylex();
void yyerror(const char *s);


#line 53 "parser.tab.cpp"


#include "parser.tab.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 131 "parser.tab.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.move< float > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_REAL: // REAL
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {

#line 586 "parser.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -120;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      82,   251,    -1,    -1,  -120,   -35,   131,    82,   171,   -24,
      13,    17,    -5,   211,    37,    40,  -120,  -120,  -120,     1,
     251,  -120,  -120,  -120,  -120,    60,    82,  -120,   299,  -120,
    -120,  -120,    76,  -120,    24,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,    25,   -14,    24,   -14,  -120,   317,
      35,    38,   251,   328,    33,   -12,  -120,   251,   251,   251,
      42,  -120,   346,  -120,  -120,  -120,   517,  -120,  -120,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
    -120,   251,   251,  -120,  -120,   251,    16,    30,   251,   251,
    -120,  -120,  -120,    44,   251,   251,    56,  -120,    61,  -120,
     372,   251,  -120,    70,  -120,   392,   417,    69,    53,  -120,
      19,   517,    19,    19,    19,   194,   194,   194,   194,    -8,
      -8,    59,  -120,  -120,  -120,    81,    84,   442,  -120,    86,
     471,    61,   251,   251,  -120,  -120,    82,    82,   251,  -120,
      28,   251,  -120,  -120,  -120,  -120,    88,   487,    93,  -120,
     500,    78,   106,   112,  -120,  -120,    82,   251,  -120,  -120,
    -120,  -120,   113,    82,  -120
  };

  const signed char
  parser::yydefact_[] =
  {
      14,     0,     0,     0,    12,     0,     0,    14,    61,     0,
       0,     0,     0,     0,     0,     0,    72,    73,    74,     0,
       0,    69,    70,    71,    44,     0,    14,     2,     0,    29,
      15,    37,    39,    47,    40,    41,    10,    11,    43,     4,
       5,     6,     7,    31,     0,    33,     0,    35,    46,     0,
       0,     0,     0,    59,     0,     0,    64,     0,     0,    61,
       0,    83,     0,     8,     9,    45,    32,     1,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,    34,    36,     0,     0,     0,    61,     0,
      53,    55,    56,     0,    61,     0,     0,    30,    42,    67,
       0,    61,    62,     0,    63,     0,     0,     0,    77,    82,
      16,    17,    18,    19,    20,    22,    24,    21,    23,    25,
      26,    27,    28,    38,    48,     0,     0,     0,    50,     0,
       0,     0,    61,     0,    60,    65,     0,     0,     0,    75,
       0,    61,    57,    49,    52,    51,     0,     0,    78,    80,
       0,     0,     0,     0,    54,    66,     0,    61,    76,    68,
      58,    79,     0,     0,    81
  };

  const signed char
  parser::yypgoto_[] =
  {
    -120,  -120,  -119,     7,     0,  -120,  -120,  -120,    21,  -120,
      32,  -120,  -120,  -120,   -48,  -120,  -120,    39,   -11,    -3,
    -120,  -120,  -120,  -120,  -120,  -120
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    25,    26,    27,    53,    29,    30,    31,    32,    33,
      34,    90,    91,    92,    54,    35,    55,    56,    36,    37,
      38,   140,    39,    40,    41,    42
  };

  const short
  parser::yytable_[] =
  {
      28,    43,    57,    50,    -1,    -1,    49,    28,   103,    86,
      87,   107,    88,    62,    51,    48,    89,   148,   149,   104,
      66,     5,    69,    45,    47,    44,    28,    74,    75,    76,
      77,    78,    79,    68,    46,    46,    81,   161,    82,    58,
     126,    96,    19,    59,   164,    60,   129,    93,   151,    24,
      94,    65,   100,   134,    95,   152,    63,   105,   106,    64,
      67,    12,    98,    81,   102,    82,   124,    99,   108,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     125,   121,   122,   131,   146,   123,     1,   132,   138,   127,
      83,    84,    85,   153,   128,   130,     2,     3,    52,    86,
      87,     4,    88,   139,     5,    82,    89,   141,     6,   162,
       7,   142,     8,   144,     9,   154,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   156,    20,   158,    21,
      22,    23,    24,   147,     7,     1,    28,    28,   150,   160,
     163,   159,   135,     0,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     5,     0,     0,    28,     6,     0,     0,
       0,     8,     0,    28,     0,     0,     0,    12,     0,     0,
       0,    16,    17,    18,    19,     1,    20,     0,    21,    22,
      23,    24,     0,     0,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     6,     0,    52,
       0,     8,    -1,    -1,    -1,    -1,    78,    79,     0,     0,
       0,    16,    17,    18,    19,     1,    20,     0,    21,    22,
      23,    24,     0,     0,     0,     2,     3,     0,     0,     0,
      61,     0,     0,     5,     0,     0,     0,     6,    81,     0,
      82,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18,    19,     1,    20,     0,    21,    22,
      23,    24,     0,     0,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     6,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18,    19,     0,    20,     0,    21,    22,
      23,    24,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,     0,    80,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,    81,    97,    82,     0,     0,   101,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,    81,     0,    82,     0,   109,     0,     0,     0,     0,
       0,     0,    81,     0,    82,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
      81,     0,    82,   133,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,    82,   136,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,     0,    81,     0,    82,     0,
       0,     0,     0,     0,   137,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,    81,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,    81,     0,    82,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,   145,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,    81,   155,    82,     0,   157,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    81,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,    82
  };

  const short
  parser::yycheck_[] =
  {
       0,     1,    26,     6,    12,    13,     6,     7,    20,    23,
      24,    59,    26,    13,     7,    50,    30,   136,   137,    31,
      20,    22,     3,     2,     3,    26,    26,     8,     9,    10,
      11,    12,    13,    26,     2,     3,    44,   156,    46,    26,
      88,    44,    43,    26,   163,    50,    94,    23,    20,    50,
      26,    50,    52,   101,    30,    27,    19,    57,    58,    19,
       0,    36,    27,    44,    31,    46,    50,    29,    26,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      50,    81,    82,    27,   132,    85,     4,    26,    19,    89,
      14,    15,    16,   141,    50,    95,    14,    15,    28,    23,
      24,    19,    26,    50,    22,    46,    30,    26,    26,   157,
      28,    27,    30,    27,    32,    27,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    33,    45,    50,    47,
      48,    49,    50,   133,    28,     4,   136,   137,   138,    27,
      27,   152,   103,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,   156,    26,    -1,    -1,
      -1,    30,    -1,   163,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    40,    41,    42,    43,     4,    45,    -1,    47,    48,
      49,    50,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    26,    -1,    28,
      -1,    30,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    40,    41,    42,    43,     4,    45,    -1,    47,    48,
      49,    50,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      19,    -1,    -1,    22,    -1,    -1,    -1,    26,    44,    -1,
      46,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,     4,    45,    -1,    47,    48,
      49,    50,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    -1,    45,    -1,    47,    48,
      49,    50,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    19,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    44,    27,    46,    -1,    -1,    20,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    44,    -1,    46,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    46,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      44,    -1,    46,    21,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    27,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    27,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    44,    -1,    46,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    31,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    44,    29,    46,    -1,    19,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    46
  };

  const signed char
  parser::yystos_[] =
  {
       0,     4,    14,    15,    19,    22,    26,    28,    30,    32,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      45,    47,    48,    49,    50,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    69,    72,    73,    74,    76,
      77,    78,    79,    58,    26,    62,    64,    62,    50,    58,
      73,    57,    28,    58,    68,    70,    71,    26,    26,    26,
      50,    19,    58,    19,    19,    50,    58,     0,    57,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      19,    44,    46,    14,    15,    16,    23,    24,    26,    30,
      65,    66,    67,    23,    26,    30,    73,    27,    27,    29,
      58,    20,    31,    20,    31,    58,    58,    68,    26,    19,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    50,    50,    68,    58,    50,    68,
      58,    27,    26,    21,    68,    71,    27,    27,    19,    50,
      75,    26,    27,    31,    27,    31,    68,    58,    56,    56,
      58,    20,    27,    68,    27,    29,    33,    19,    50,    72,
      27,    56,    68,    27,    56
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    66,    67,    68,
      68,    68,    69,    69,    70,    70,    71,    72,    73,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    76,    76,
      77,    78,    79,    79
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     0,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     3,     4,
       3,     4,     4,     2,     6,     1,     1,     3,     5,     1,
       3,     0,     3,     3,     1,     3,     5,     3,     6,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     5,     7,
       5,     9,     3,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "LESS_THAN", "LESS_THAN_EQUAL",
  "GREATER_THAN", "GREATER_THAN_EQUAL", "EQUAL", "NOT_EQUAL", "INCREMENT",
  "DECREMENT", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "SEMICOLON",
  "COMMA", "COLON", "DOUBLE_COLON", "DOT", "DOUBLE_DOT", "TURNARY",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_BRACE", "RIGHT_BRACE",
  "LEFT_BRACKET", "RIGHT_BRACKET", "IF", "ELSE", "WHILE", "FOR",
  "FUNCTION", "RETURN", "BREAK", "CONTINUE", "TRUE", "FALSE", "NIL",
  "LOCAL", "AND", "NOT", "OR", "INTEGER", "REAL", "STRING", "IDENTIFIER",
  "IGNORED", "LOWER_THAN_ELSE", "UMINUS", "$accept", "program", "stmt",
  "stmt_list", "expr", "term", "assignexpr", "primary", "lvalue", "member",
  "call", "callsuffix", "normcall", "methodcall", "elist", "objectdef",
  "indexed", "indexedelem", "block", "funcdef", "const", "idlist",
  "ifstmt", "whilestmt", "forstmt", "returnstmt", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   123,   123,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   138,   139,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     159,   160,   161,   162,   163,   164,   165,   166,   169,   172,
     173,   174,   175,   176,   179,   180,   181,   182,   185,   186,
     187,   188,   191,   192,   193,   196,   197,   200,   203,   206,
     207,   208,   211,   212,   215,   216,   219,   222,   225,   228,
     229,   230,   231,   232,   233,   236,   237,   238,   241,   242,
     245,   248,   251,   252
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1378 "parser.tab.cpp"

#line 254 "parser.y"




void yyerror(const char *s, int line) {
    std::cerr << "Error at line " << line << ": " << s << std::endl;
    exit(1);
}
