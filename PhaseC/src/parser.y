%define         parse.error     verbose
%define         parse.trace   
%locations

%{
#include <iostream>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <vector>

#include "../src/symtable.hpp"
#include "../src/iopcode.hpp"

extern SymbolTable symTable;
extern bool skipBlockScope;
extern int yylex();
extern char* yytext;
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
extern int loopCounter;
extern std::stack<int> loopCounterStack;
int yyerror(const char* msg);

// Global variables
SymEntry* entryFuncDef = nullptr;
%}


%start program

%union {
        int int_val;
        float float_val;
        char *str_val;
        struct SymEntry *node;
        struct expr *expr;
        struct call *callval;
        struct indexed *indexed;
        struct stmt_t *stmtval;
        struct forprefix *forprefix;
}


/* OPS */
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token MODULO
%token LESS_THAN
%token LESS_THAN_EQUAL
%token GREATER_THAN
%token GREATER_THAN_EQUAL
%token EQUAL
%token NOT_EQUAL
%token INCREMENT
%token DECREMENT

/* ASSIGN */
%token ASSIGN
%token PLUS_ASSIGN
%token MINUS_ASSIGN


/* Delimeters */
%token SEMICOLON
%token COMMA
%token COLON
%token DOUBLE_COLON
%token DOT
%token DOUBLE_DOT
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS
%token LEFT_BRACE
%token RIGHT_BRACE
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token UMINUS

/* Keywords */
%token IF
%token ELSE
%token WHILE
%token FOR
%token FUNCTION
%token RETURN
%token BREAK
%token CONTINUE
%token TRUE
%token FALSE
%token NIL
%token LOCAL
%token AND 
%token NOT
%token OR 

/* Constants */
%token <int_val> INTEGER;
%token <float_val> REAL
%token <str_val> STRINGT
%token <str_val> IDENTIFIER 


/* Extra Tokens */
%token ERROR_COMMENT
%token ERROR_STRING
%token ERROR_ESCAPE
%token UNDEF


%type <expr>    expr term
%type <expr>    lvalue call primary objectdef
%type <expr>    assignexpr elist member idlist errors const
%type <node>    funcprefix funcdef
  
%type <stmtval> block stmt stmt_list ifstmt whilestmt forstmt loopstmt program returnstmt

%type <callval> callsuffix normcall methodcall 
%type <indexed> indexed indexedelem   
%type <str_val> funcname
%type<int_val> funcbody arithop relop
%type <int_val> ifprefix elseprefix N M
%type <forprefix> forprefix
%type <int_val> whilestart whilecond loopstart loopend




%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN
%left OR
%left AND 
%nonassoc EQUAL NOT_EQUAL
%nonassoc GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT INCREMENT DECREMENT UMINUS
%left DOT DOUBLE_DOT
%left LEFT_BRACKET RIGHT_BRACKET
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS  
%left LEFT_BRACE RIGHT_BRACE


%%
program: stmt_list      {       
                                fprintf(yyout, "[-] Reduced: program -> stmt_list\n");
                        }
        ;

stmt: expr SEMICOLON    {       
                                $$ = new stmt_t;
                                $$->breaklist = 0;
                                $$->contlist = 0; 
                                resettemp();
                                fprintf(yyout, "[-] Reduced: stmt -> expr SEMICOLON\n");
                        }

        | ifstmt        {
                                $$ = $1;
                                resettemp();
                                fprintf(yyout, "[-] Reduced: stmt -> ifstmt\n");
                        }

        | whilestmt     {
                                $$ = $1;
                                resettemp();
                                fprintf(yyout, "[-] Reduced: stmt -> whilestmt\n");
                        }

        | forstmt       {
                                $$ = $1;
                                resettemp();
                                fprintf(yyout, "[-] Reduced: stmt -> forstmt\n");
                        }

        | returnstmt    {
                                if (symTable.funcStack.empty()) fprintf(yyout, "      [!] Error: Return statement outside of function in line %d.\n", yylineno);
                                $$ = $1;
                                resettemp();
                                fprintf(yyout, "[-] Reduced: stmt -> returnstmt\n");
                        }

        | BREAK SEMICOLON       {       
                                        if (loopCounter == 0) {
                                                fprintf(yyout, "      [!] Error: Break statement outside of loop in line %d.\n", yylineno);
                                                $$ = new stmt_t;
                                                $$->breaklist = $$->contlist = 0;
                                        } else {
                                                $$ = new stmt_t;
                                                $$->contlist = newlist(nextquad());
                                                $$->breaklist = 0;
                                                emit(jump, nullptr, nullptr, newexpr_constnum(0));
                                        }
                                        resettemp();
                                        fprintf(yyout, "[-] Reduced: stmt -> BREAK SEMICOLON\n");
                                }

        | CONTINUE SEMICOLON    {       
                                        if (loopCounter == 0) {
                                                fprintf(yyout, "      [!] Error: Continue statement outside of loop in line %d.\n", yylineno);
                                                $$ = new stmt_t;
                                                $$->breaklist = $$->contlist = 0;
                                        } else {
                                                $$ = new stmt_t;
                                                $$->contlist = newlist(nextquad());
                                                $$->breaklist = 0;
                                                emit(jump, nullptr, nullptr, newexpr_constnum(0));
                                        }
                                        resettemp();
                                        fprintf(yyout, "[-] Reduced: stmt -> CONTINUE SEMICOLON\n");
                                }

        | block                 {       
                                        $$ = $1;
                                        resettemp();
                                        fprintf(yyout, "[-] Reduced: stmt -> block\n");
                                }

        | funcdef               {
                                        $$ = new stmt_t;
                                        $$->breaklist = 0;
                                        $$->contlist = 0;
                                        resettemp();
                                        fprintf(yyout, "[-] Reduced: stmt -> funcdef\n");
                                }

        | SEMICOLON             {       
                                        resettemp();
                                        fprintf(yyout, "[-] Reduced: stmt -> SEMICOLON\n");
                                }

        | errors                {
                                        $$ = new stmt_t;
                                        $$->breaklist = 0;
                                        $$->contlist = 0;
                                        resettemp();
                                        fprintf(yyout, "[-] Reduced: stmt -> errors\n");
                                }

        
        | error SEMICOLON       {       
                                        resettemp();
                                        fprintf(yyout, "      [!] Error: Illegal statement in line %d.\n", yylineno);
                                        yyerrok;
                                        yyclearin;
                                }
        
        ;
    
stmt_list:  stmt stmt_list      {
                                        $$ = new stmt_t;
                                        $$->breaklist = mergelist($1->breaklist, $2->breaklist);
                                        $$->contlist = mergelist($1->contlist, $2->contlist);
                                        fprintf(yyout, "[-] Reduced: stmt_list -> stmt stmt_list\n");
                                }

            | /* empty */       {       
                                        $$ = new stmt_t;
                                        $$->breaklist = 0;
                                        $$->contlist = 0;

                                        fprintf(yyout, "[-] Reduced: stmt_list -> /* empty */\n");
                                }
            ;

expr:   assignexpr              {       
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: expr -> assignexpr\n");
                                }

        | expr arithop expr             {       
                                                if (!(check_arith($1, "expr arithop expr") || !check_arith($3, "expr arithop expr"))) {
                                                        $$ = newexpr(nil_e);
                                                        fprintf(yyout, "      [!] Error: Invalid expression in line %d.\n", yylineno);
                                                        return;
                                                } 
                                                 
                                                if ($1->type == constnum_e && $3->type == constnum_e) {
                                                        $$ = newexpr(constnum_e);
                                                        switch ($2) {
                                                                case add: $$->numConst = $1->numConst + $3->numConst; break;
                                                                case sub: $$->numConst = $1->numConst - $3->numConst; break;
                                                                case mul: $$->numConst = $1->numConst * $3->numConst; break;
                                                                case div_op: if ($3->numConst == 0) goto fallback_nil; else $$->numConst = $1->numConst / $3->numConst; break;
                                                                case mod: if ($3->numConst == 0) goto fallback_nil; else $$->numConst = fmod($1->numConst, $3->numConst); break;        
                                                        }


                                                } else {
                                                        $$ = newexpr(arithexpr_e);
                                                        $$->sym = newtemp();
                                                        emit($2, $1, $3, $$);
                                                }

                                                fprintf(yyout, "[-] Reduced: expr -> expr arithop expr\n");
                                                return;

                                                fallback_nil:
                                                        fprintf(yyout, "      [!] Error: Division by zero in line %d.\n", yylineno);
                                                        $$ = newexpr(nil_e);
                                        }      

        | expr relop expr             {       
                                                bool invalid = false;

                                                if ($2 == if_greater || $2 == if_less || $2 == if_greatereq || $2 == if_lesseq) {
                                                        if ($1->type != constnum_e && $1->type != arith || $3->type != constnum_e && $3->type != arith) {
                                                                invalid = true;
                                                        }
                                                } else if ($2 == if_eq || $2 == if_noteq) {
                                                        if ($1->type != $3->type) {
                                                                if (!($1->type == tableitem_e && $3->type == nil_e) || ($1->type == nil_e && $3->type == tableitem_e)) {
                                                                        invalid = true;
                                                                }  
                                                        }
                                                }

                                                if (invalid) {
                                                        fprintf(yyout, "      [!] Error: Invalid operands for relational operator in line %d.\n", yylineno);
                                                        $$ = newexpr(nil_e);
                                                        return;
                                                }

                                                $$ = newexpr(boolexpr_e);
                                                $$->sym = newtemp();

                                                emit($2, $1, $3, newexpr_constnum(nextquad() + 3));
                                                emit(assign, newexpr_constnum(0), nullptr, $$);
                                                emit(jump, nullptr, nullptr, newexpr_constnum(nextquad() + 2));
                                                emit(assign, newexpr_constnum(1), nullptr, $$);

                                                fprintf(yyout, "[-] Reduced: expr -> expr relop expr\n");
                                        }

        |expr AND expr          {       
                                        convert_to_bool($1);
                                        patch($1->truelist, nextquad());
                                        
                                        
                                        convert_to_bool($3);
                                        $$ = newexpr(boolexpr_e);

                                        $$->truelist = $3->truelist;
                                        $$->falselist = merge($1->falselist, $3->falselist);

                                        fprintf(yyout, "[-] Reduced: expr -> expr AND expr\n");
                                }
        
        | expr OR expr           {       
                                        convert_to_bool($1);
                                        patchlist($1->falselist, nextquad());

                                        convert_to_bool($3);
                                        $$ = newexpr(boolexpr_e);

                                        $$->truelist = merge($1->truelist, $3->truelist);
                                        $$->falselist = $3->falselist;

                                        fprintf(yyout, "[-] Reduced: expr -> expr OR expr\n");
                                }

        | term                          {       
                                                $$ = $1;
                                                fprintf(yyout, "[-] Reduced: expr -> term\n");
                                        } 
        ;

arithop: PLUS {$$ = add}
        | MINUS {$$ = sub}
        | MULTIPLY {$$ = mul}
        | DIVIDE {$$ = div_op}
        | MODULO {$$ = mod}
        ;

relop: GREATER_THAN {$$ = if_greater}
        | LESS_THAN {$$ = if_less}
        | GREATER_THAN_EQUAL {$$ = if_greatereq}
        | LESS_THAN_EQUAL {$$ = if_lesseq}
        | EQUAL {$$ = if_eq}
        | NOT_EQUAL {$$ = if_noteq}
        ;


term:   LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {
                                                        $$ = $2;
                                                        fprintf(yyout, "[-] Reduced: term -> LEFT_PARENTHESIS expr RIGHT_PARENTHESIS\n");
                                                }

        | MINUS expr %prec UMINUS               {
                                                        check_arith($2, "unary minus (-expr)");
                                                        $$ = newexpr(arithexpr_e);
                                                        $$->sym = istempexpr($2)? $2->sym : newtemp();
                                                        emit(uminus, $2, nullptr, $$);
                                                        fprintf(yyout, "[-] Reduced: term -> MINUS expr\n");
                                                }

        | NOT expr                              { 
                                                        convert_to_bool($2);

                                                        $$ = newexpr(boolexpr_e);
                                                        $$->truelist = $2->falselist;
                                                        $$->falselist = $2->truelist;
                                                }

        | INCREMENT lvalue                      {       
                                                        check_arith($2, "increment (nonlval++)");
                                                        if ($2->type == tableitem_e) {
                                                                $$ = emit_iftableitem($2);
                                                                emit(add, $$, newexpr_constnum(1), $$);
                                                                emit(tablesetelem, $2, $2->index, $$);
                                                        } else {
                                                                emit(add, $2, newexpr_constnum(1), $2);
                                                                $$ = newexpr(arithexpr_e);
                                                                $$->sym = newtemp();
                                                                emit(assign, $2, nullptr, $$);
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> INCREMENT lvalue\n");
                                                }

        | lvalue INCREMENT                      {       
                                                        check_arith($1, "increment (nonlval++)");
                                                        $$ = newexpr(var_e);
                                                        $$->sym = newtemp();
                                                        if ($1->type == tableitem_e) {
                                                                expr* val = emit_iftableitem($1);
                                                                emit(assign, val, nullptr, $$);
                                                                emit(add, val, newexpr_constnum(1), val);
                                                                emit(tablesetelem, $1, $1->index, val);
                                                        } else {
                                                                emit(assign, $1, nullptr, $$);
                                                                emit(add, $1, newexpr_constnum(1), $1);
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue INCREMENT\n");
                                                }

        | DECREMENT lvalue                      {       
                                                        check_arith($2, "decrement (nonlval--)");
                                                        if ($2->type == tableitem_e) {
                                                                $$ = emit_iftableitem($2);
                                                                emit(sub, $$, newexpr_constnum(1), $$);
                                                                emit(tablesetelem, $2, $2->index, $$);
                                                        } else {
                                                                emit(sub, $2, newexpr_constnum(1), $2);
                                                                $$ = newexpr(arithexpr_e);
                                                                $$->sym = newtemp();
                                                                emit(assign, $2, nullptr, $$);
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> DECREMENT lvalue\n");
                                                }

        | lvalue DECREMENT                      {
                                                        check_arith($1, "decrement (nonlval--)");
                                                        $$ = newexpr(var_e);
                                                        $$->sym = newtemp();
                                                        if ($1->type == tableitem_e) {
                                                                expr* val = emit_iftableitem($1);
                                                                emit(assign, val, nullptr, $$);
                                                                emit(sub, val, newexpr_constnum(1), val);
                                                                emit(tablesetelem, $1, $1->index, val);
                                                        } else {
                                                                emit(assign, $1, nullptr, $$);
                                                                emit(sub, $1, newexpr_constnum(1), $1);
                                                        }
                                                        fprintf(yyout, "[-] Reduced: term -> lvalue DECREMENT\n");
                                                }        
        
        | primary                               {       
                                                        $$ = $1;
                                                        fprintf(yyout, "[-] Reduced: term -> primary\n");
                                                }
        ;

assignexpr:     lvalue ASSIGN expr              { 
                                                        if ($1->sym && $1->sym->type == LIBFUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc = expr) in line %d.\n", yylineno);
                                                                $$ = newexpr(nil_e);
                                                        } 
                                                                
                                                        if ($1->sym && $1->sym->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func = expr) in line %d.\n", yylineno);
                                                                $$ = newexpr(nil_e);       
                                                        }

                                                        if ($1->sym && $1->sym->type == NONLVAL) {
                                                                fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval = expr) in line %d.\n", yylineno);
                                                                $$ = newexpr(nil_e);
                                                        } else {
                                                                if ($1->type == tableitem_e) {
                                                                        emit(tablesetelem, $1, $1->index, $3);
                                                                        $$ = emit_iftableitem($1);
                                                                        $$->type = assignexpr_e;
                                                                } else {
                                                                        emit(assign, $3, nullptr, $1);
                                                                        $$ = newexpr(assignexpr_e);
                                                                        $$->sym = newtemp();
                                                                        emit(assign, $1, nullptr, $$);
                                                                } 
                                                        }
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue ASSIGN expr\n");
                                                }

                | lvalue PLUS_ASSIGN expr       {       
                                                        if ($1->sym && $1->sym->type == LIBFUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc += expr) in line %d.\n", yylineno);
                                                                $$ = newexpr(nil_e);
                                                        }
                                                        if ($1->sym && $1->sym->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func += expr) in line %d.\n", yylineno);
                                                                $$ = newexpr(nil_e);
                                                        }
                                                        if ($1->sym && $1->sym->type == NONLVAL) {
                                                                fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval += expr) in line %d.\n", yylineno);
                                                                $$ = newexpr(nil_e);
                                                        } else {
                                                                expr* lv = emit_iftableitem($1);
                                                                expr* temp = newexpr_tmpvar(arithexpr_e);
                                                                emit(add, temp, lv, $3);

                                                                if ($1->type == tableitem_e) {
                                                                emit(tablesetelem, $1, temp, $1->index);
                                                                } else {
                                                                emit(assign, $1, temp, nullptr);                     
                                                                }

                                                                $$ = $1;
                                                                $$->type = assignexpr_e; 
                                                        }
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue PLUS_ASSIGN expr\n");
                                                }

                | lvalue MINUS_ASSIGN expr      {
                                                        if ($1->sym && $1->sym->type == LIBFUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use library function as lvalue (libfunc -= expr) in line %d.\n", yylineno);
                                                                $$ = newexpr(nil_e);
                                                        }
                                                        if ($1->sym && $1->sym->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Cannot use function as lvalue (func -= expr) in line %d.\n", yylineno);
                                                                $$ = newexpr(nil_e);
                                                        }
                                                        if ($1->sym && $1->sym->type == NONLVAL) {
                                                                fprintf(yyout, "      [!] Error: Cannot use non-lvalue as lvalue (nonlval -= expr) in line %d.\n", yylineno);
                                                                $$ = newexpr(nil_e);
                                                        } else {
                                                                expr* lv = emit_iftableitem($1);               
                                                                expr* temp = newexpr_tmpvar(arithexpr_e);
                                                                emit(sub, temp, lv, $3);

                                                                if ($1->type == tableitem_e) {
                                                                emit(tablesetelem, $1, temp, $1->index);    
                                                                } else {
                                                                emit(assign, $1, temp, nullptr);                     
                                                                }

                                                                $$ = $1;
                                                                $$->type = assignexpr_e; 
                                                        }
                                                        fprintf(yyout, "[-] Reduced: assignexpr -> lvalue MINUS_ASSIGN expr\n");
                                                }
                ;

primary: lvalue                 {       
                                        $$ = emit_iftableitem($1);
                                        fprintf(yyout, "[-] Reduced: primary -> lvalue\n");
                                }

        | call                  {       
                                        if ($1->type == tableitem_e && !$1->sym) {
                                                fprintf(stderr, "[!] Invalid table item call at line %d\n", yylineno);
                                                $$ = newexpr(nil_e);
                                        } else {
                                                $$ = $1;
                                        }
                                        fprintf(yyout, "[-] Reduced: primary -> call\n");
                                }

        | objectdef             {       
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: primary -> objectdef\n");
                                }

        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS    {
                                                                $$ = newexpr(programfunc_e);
                                                                $$->sym = $2;
                                                                fprintf(yyout, "[-] Reduced: primary -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS\n");
                                                        }
        | const                 {
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: primary -> const\n");
                                }
        ;

lvalue: IDENTIFIER              {
                                        SymEntry* found = symTable.lookup($1);

                                        if (!found) {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = $1;
                                                entry->type = VAR;
                                                entry->scope = symTable.getScope();
                                                entry->line = yylineno;
                                                entry->isActive = true;
                                                entry->isGlobal = (entry->scope == 0);

                                                symTable.insert(entry);
                                                $$ = lvalue_expr(entry);
                                        } else {    
                                                if (found->type == LIBFUNC) {
                                                        $$ = newexpr(libfunc_e);
                                                        $$->sym = found;
                                                } else if (found->type == FUNC) {
                                                        $$ = newexpr(programfunc_e);
                                                        $$->sym = found;
                                                } else if (found->type == VAR || found->type == FORARG) {
                                                        if (symTable.funcStack.empty()) {
                                                                $$ = lvalue_expr(found);
                                                        } else {
                                                                if ((found->scope > symTable.funcStack.top()->scope && found->isActive) || found->scope == 0) {
                                                                        $$ = lvalue_expr(found);
                                                                } else {
                                                                     fprintf(yyout, "      [!] Error: Variable %s is not accessible in line %d.\n", $1, yylineno); 
                                                                }
                                                        }
                                                } else {
                                                        fprintf(yyout, "      [!] Warning: Unexpected symbol type in line %d.\n", yylineno);
                                                        $$ = lvalue_expr(found);
                                                }
                                        }

                                        fprintf(yyout, "[-] Reduced: lvalue -> IDENTIFIER\n");
                                }

        | LOCAL IDENTIFIER      {       
                                        SymEntry* found;
                                        if ((found = symTable.lookup($2, 0)) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Local variable is shadowing library function in line %d.\n", yylineno);
                                                $$ = newexpr(nil_e);
                                        } else if (!found || found->type != LIBFUNC) {
                                        
                                                found = symTable.lookup($2, symTable.getScope());

                                                if (!found) {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = $2;
                                                        entry->type = VAR;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;

                                                        entry->isGlobal = false;

                                                        symTable.insert(entry);
                                                
                                                } else if (found->type == FUNC) {
                                                        fprintf(yyout, "      [!] Warning: Local variable is shadowing function in line %d.\n", yylineno);
                                                }

                                                $$ = lvalue_expr(found);
                                        } 
                                        fprintf(yyout, "[-] Reduced: lvalue -> LOCAL IDENTIFIER\n");
                                }

        | DOUBLE_COLON IDENTIFIER       {       
                                                SymEntry* found = symTable.lookup($2, 0);
                                                if (!found) {
                                                        fprintf(yyout, "      [!] Error: Token %s has not been declared in global scope in line %d.\n", $2, yylineno);
                                                        $$ = newexpr(nil_e);
                                                } else if (found->type == LIBFUNC) {
                                                        $$ = newexpr(libfunc_e);
                                                        $$->sym = found;
                                                } else if (found->type == FUNC) {
                                                        $$ = newexpr(programfunc_e);
                                                        $$->sym = found;
                                                } else if (found->type == VAR) {
                                                        $$ = lvalue_expr(found);
                                                } else {
                                                        fprintf(yyout, "      [!] Warning: Unexpected symbol type in line %d.\n", yylineno);
                                                        $$ = lvalue_expr(found);
                                                }
                                                fprintf(yyout, "[-] Reduced: lvalue -> DOUBLE_COLON IDENTIFIER\n");
                                        }

        | member                        {       
                                                $$ = $1;
                                                fprintf(yyout, "[-] Reduced: lvalue -> member\n");
                                        }
        ;

member: lvalue DOT IDENTIFIER   {       
                                        $$ = member_item($1, $3);
                                        fprintf(yyout, "[-] Reduced: member -> lvalue DOT IDENTIFIER\n");
                                }

        | lvalue LEFT_BRACKET expr RIGHT_BRACKET        {
                                                                $1 = emit_iftableitem($1);
                                                                $$ = newexpr(tableitem_e);
                                                                $$->sym = $1->sym;
                                                                $$->index = $3;
                                                                fprintf(yyout, "[-] Reduced: member -> lvalue LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        }

        | call DOT IDENTIFIER                           {       
                                                                $$ = member_item($1, $3);
                                                                fprintf(yyout, "[-] Reduced: member -> call DOT IDENTIFIER\n");
                                                        }

        | call LEFT_BRACKET expr RIGHT_BRACKET          {
                                                                $$ = newexpr(tableitem_e);
                                                                $1 = emit_iftableitem($1);
                                                                $$->sym = $1->sym;
                                                                $$->index = $3;
                                                                
                                                                fprintf(yyout, "[-] Reduced: member -> call LEFT_BRACKET expr RIGHT_BRACKET\n");
                                                        } 
        ;

call:   call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS   {     
                                                                $$ = make_call($1, $3); 
                                                                fprintf(yyout, "[-] Reduced: call -> call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }

        | lvalue callsuffix                             {
                                                                $1 = emit_iftableitem($1);

                                                                if ($2->method) {
                                                                        expr* temp = $1;
                                                                        $1 = emit_iftableitem(member_item(temp, $2->name));
                                                                        $2->elist->next = temp;
                                                                }

                                                                $$ = make_call($1, $2->elist);
                                                                fprintf(yyout, "[-] Reduced: call -> lvalue callsuffix\n");
                                                        }

        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS   {
                                                                                                        expr* func = newexpr(programfunc_e);
                                                                                                        func->sym = $2;
                                                                                                        $$ = make_call(func, $5);
                                                                                                        fprintf(yyout, "[-] Reduced: call -> LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                                }
        ;

callsuffix: normcall            {
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: callsuffix -> normcall\n");
                                }

            | methodcall        {
                                        $$ = $1;
                                        fprintf(yyout, "[-] Reduced: callsuffix -> methodcall\n");
                                }
            ;

normcall:   LEFT_PARENTHESIS elist RIGHT_PARENTHESIS    {       
                                                                $$ = new struct call;
                                                                $$->elist = $2;
                                                                $$->method = 0;
                                                                $$->name = nullptr;
                                                                fprintf(yyout, "[-] Reduced: normcall -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                        }
            ;

methodcall: DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS      {       
                                                                                        $$->elist = $4;
                                                                                        $$->method = 1;
                                                                                        $$->name = $2;
                                                                                        fprintf(yyout, "[-] Reduced: methodcall -> DOUBLE_DOT IDENTIFIER LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                                                }
            ;

elist: expr                     {       
                                        $$ = $1;
                                        $$->next = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> expr\n");
                                }

        | elist COMMA expr      {       
                                        $3->next = $1;
                                        $$ = $3;
                                        fprintf(yyout, "[-] Reduced: elist -> expr COMMA elist\n");
                                }

        | /* empty */           {       
                                        $$ = nullptr;
                                        fprintf(yyout, "[-] Reduced: elist -> /* empty */\n");
                                }
        ;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET     {       
                                                        expr* obj = newexpr(newtable_e);
                                                        obj->sym = newtemp();
                                                        emit(tablecreate, obj, nullptr, nullptr);
                                                        for (int i = 0; $2; $2 = $2->next) {
                                                                emit(tablesetelem, obj, newexpr_constnum(i++), $2);
                                                        }
                                                        $$ = obj;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET elist RIGHT_BRACKET\n");
                                                }

        | LEFT_BRACKET indexed RIGHT_BRACKET    {       
                                                        expr* obj = newexpr(newtable_e);
                                                        obj->sym = newtemp();
                                                        emit(tablecreate, obj, nullptr, nullptr);
                                                        for (indexed* p = $2; p; p = p->next) {
                                                                emit(tablesetelem, obj, p->index, p->value);
                                                        }
                                                        $$ = obj;
                                                        fprintf(yyout, "[-] Reduced: objectdef -> LEFT_BRACKET indexed RIGHT_BRACKET\n");
                                                }
        ;

indexed: indexedelem                            {
                                                        $$ = $1;
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexedelem\n");
                                                }

        | indexed COMMA indexedelem             {
                                                        $3->next = $1;
                                                        $$ = $3;
                                                        fprintf(yyout, "[-] Reduced: indexed -> indexed COMMA indexedelem\n");
                                                }
        ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE     {
                                                                indexed* i = new indexed;
                                                                i->key = $2;
                                                                i->value = $4;
                                                                i->next = nullptr;
                                                                $$ = i;
                                                                fprintf(yyout, "[-] Reduced: indexedelem -> LEFT_BRACE expr COLON expr RIGHT_BRACE\n");
                                                        }
            ;

block: LEFT_BRACE       { 
                                if (skipBlockScope) {
                                        skipBlockScope = false;
                                } else {
                                        symTable.enter_scope();
                                }
                        } stmt_list RIGHT_BRACE {
                                                        symTable.exit_scope();   
                                                        $$ = $3;
                                                        fprintf(yyout, "[-] Reduced: block -> LEFT_BRACE stmt_list RIGHT_BRACE\n");
                                                }
        ;

funcblockstart: /* ε */ {
                                loopCounterStack.push(loopCounter);
                                loopCounter = 0;
                        }

funcblockend:   /* ε */ {
                                loopCounter = loopCounterStack.top();
                                loopCounterStack.pop();
                        }

funcname: IDENTIFIER            {       
                                        $$ = $1.str_val;
                                        fprintf(yyout, "[-] Reduced: funcname -> IDENTIFIER\n");
                                }

        | /* empty */           {       
                                        $$ = generateAnonymousName();
                                        fprintf(yyout, "[-] Reduced: funcname -> /* empty */\n");
                                }
        ;

funcprefix: FUNCTION funcname   {
                                        Symentry *found = symTable.lookup($2, 0);
                                        SymEntry *entry = nullptr;

                                        if(found && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Function shadowing library function in line %d.\n", yylineno);
                                        } else {
                                                found = symTable.lookup($2, symTable.getScope());

                                                if (!found) {
                                                        entry = new SymEntry;
                                                        entry->name = $2;
                                                        entry->type = FUNC;
                                                        entry->scope = symTable.getScope();
                                                        entry->line = yylineno;
                                                        entry->isActive = true;

                                                        symTable.funcStack.push(entry);
                                                        entry->args.clear();
                                                        symTable.insert(entry);

                                                        $$ = entry;
                                                        $$->iaddress = nextquad();
                                                        emit(funcstart, $$, nullptr, nullptr);
                                                        symTable.scopeOffsetStack.push(symTable.currScopeOffset());
                                                        symTable.enterScopeSpace();
                                                        symTable.resetFormalsOff();
                                                } else {
                                                        if (found->type == FUNC) {
                                                                fprintf(yyout, "      [!] Error: Function %s already declared in line %d.\n", $2, yylineno);
                                                        }
                                                        
                                                        if (found->type == VAR) {
                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing variable in line %d.\n", $2, yylineno);
                                                        }
                                                        
                                                        if (found->type == FORARG) {
                                                                fprintf(yyout, "      [!] Error: Function %s is shadowing formal argument in line %d.\n", $2, yylineno);
                                                        }
                                                }

                                                symTable.enter_scope();
                                                skipBlockScope = true;
                                                entryFuncDef = entry;
                                        }
                                }

funcargs: LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS   {
                                                        symTable.enterScopeSpace();
                                                        symTable.resetFuncLocalsOff();
                                                        fprintf(yyout, "[-] Reduced: funcargs -> LEFT_PARENTHESIS elist RIGHT_PARENTHESIS\n");
                                                }
        ;

funcbody: block {
                        $$ = symTable.currScopeOffset();
                        symTable.exitScopeSpace();
                }

funcdef: funcprefix funcargs funcblockstart funcbody funcblockend {
                                                symTable.exitScopeSpace();
                                                $1->totalLocals = $4;
                                                int offset = symTable.top_pop(symTable.scopeOffsetStack);
                                                symTable.restoreCurrScopeOffset(offset);
                                                $$ = $1;
                                                emit(funcend, $1, nullptr, nullptr); 
                                        }
        
const:  INTEGER         {       
                                $$ = newexpr_constnum(yylval.int_val);
                                $$->type = constnum_e; 
                                fprintf(yyout, "[-] Reduced: const -> INTEGER\n");
                        }

        | REAL          {       
                                $$ = newexpr_constnum(yylval.float_val);
                                $$->type = constnum_e; 
                                fprintf(yyout, "[-] Reduced: const -> REAL\n");
                        }
        
        | STRINGT       {       
                                $$ = newexpr_conststring(yylval.str_val);
                                $$->type = conststring_e;
                                fprintf(yyout, "[-] Reduced: const -> STRING\n");
                        }

        | TRUE          {       
                                $$ = newexpr_constbool(true);
                                $$->type = constbool_e;
                                $$->boolConst = true;
                                fprintf(yyout, "[-] Reduced: const -> TRUE\n");
                        }

        | FALSE         {       
                                $$ = newexpr_constbool(false);
                                $$->type = constbool_e;
                                $$->boolConst = false;
                                fprintf(yyout, "[-] Reduced: const -> FALSE\n");
                        }

        | NIL           {
                                $$ = newexpr(nil_e);
                                fprintf(yyout, "[-] Reduced: const -> NIL\n");
                        }
        ;

idlist: IDENTIFIER      {       
                                SymEntry* found;

                                if ((found = symTable.lookup($1, 0)) && found->type == LIBFUNC) {
                                        fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);

                                        $$ = newexpr(nil_e);
                                } else {
                                        if ((found = symTable.lookup($1, symTable.getScope()))) {
                                                if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                                $$ = lvalue_expr(found);
                                        } else {
                                                SymEntry* entry = new SymEntry;
                                                entry->name = $1;
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
                                                $$ = lvalue_expr(entry);
                                        }
                                }
                                fprintf(yyout, "[-] Reduced: idlist -> IDENTIFIER\n");
                        }
        | idlist COMMA IDENTIFIER   {   
                                        SymEntry* found;

                                        if ((found = symTable.lookup($3, 0)) && found->type == LIBFUNC) {
                                                fprintf(yyout, "      [!] Error: Formal argument is shadowing library function in line %d.\n", yylineno);
                                                $$ = newexpr(nil_e);
                                        } else {
                                                if ((found = symTable.lookup($3, symTable.getScope()))) {
                                                        if (found->type == FORARG) fprintf(yyout, "      [!] Error: Formal argument already declared in line %d.\n", yylineno);
                                                        $$ = lvalue_expr(found);
                                                } else {
                                                        SymEntry* entry = new SymEntry;
                                                        entry->name = $3;
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
                                                        $$ = lvalue_expr(entry);
                                                        
                                                }
                                        }
                                        fprintf(yyout, "[-] Reduced: idlist -> idlist COMMA IDENTIFIER\n");
                                    }
        | /* empty */           {
                                        $$ = nullptr;
                                        fprintf(yyout, "[-] Reduced: idlist -> /* empty */\n");
                                }
        ;

ifprefix: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS    {
                                                                convert_to_bool($3);

                                                                patchlist($3->truelist, nextquad());

                                                                $$ = $3->falselist;
                                                        }

elseprefix: ELSE        {
                                $$ = nextquad();
                                emit(jump, nullptr, nullptr, newexpr_constnum(0));
                        }


ifstmt: ifprefix stmt %prec LOWER_THAN_ELSE {
                                patchlist($1, nextquad());
                                $$ = nullptr;
                                fprintf(yyout, "[-] Reduced: ifstmt -> IF (...) stmt\n");
                        }

        | ifprefix stmt elseprefix stmt {
                                                patchlist($1, $3 + 1);
                                                patchlist($3, nextquad());
                                                $$ = nullptr; 
                                                fprintf(yyout, "[-] Reduced: ifstmt -> IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt\n");
                                        }
        ;

loopstart: /* ε*/      {
                                ++loopCounter;
                        }

loopend:   /* ε*/       {
                                --loopCounter;
                        }
loopstmt: loopstart stmt loopend        {
                                                $$ = $2;
                                        }

whilestart: WHILE       {
                                $$ = nextquad();
                        }

whilecond: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS      {
                                                                expr* e = convert_to_bool($2);
                                                                patchlist(e->truelist, nextquad());
                                                                $$ = e->falselist;
                                                        }

whilestmt: whilestart whilecond loopstmt    {
                                                emit(jump, nullptr, nullptr, newexpr_constnum($1));

                                                patchlist($2, nextquad());
                                                patchlist($3->breaklist, nextquad());
                                                patchlist($3->contlist, $1);
                                                $$ = nullptr;

                                                fprintf(yyout, "[-] Reduced: whilestmt -> WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt\n");
                                        }
        ;

N :     {
                $$ = nextquad();
                emit(jump, nullptr, nullptr, newexpr_constnum(0));
        }
;

M :     {
                $$ = nextquad();
        }
;

forprefix: FOR LEFT_PARENTHESIS  elist SEMICOLON M expr SEMICOLON {       
                                                                        $$ = new struct forprefix;
                                                                        $$->test = $5;

                                                                        expr* e = convert_to_bool($6);
                                                                        patchlist(e->truelist, nextquad());
                                                                        
                                                                        $$->enter = nextquad();
                                                                        emit(jump, nullptr, nullptr, newexpr_constnum(0));
                                                                }
;
                                                                

forstmt: forprefix N elist RIGHT_PARENTHESIS N loopstmt M   {
                                                                emit(jump, nullptr, nullptr, newexpr_constnum($1->test));

                                                                patchlist($6->breaklist, nextquad());
                                                                patchlist($6->contlist, $1->test);

                                                                patchlist($6->breaklist, nextquad());
                                                                patchlist($1->enter, $5 + 1);
                                                                patchlist($2, nextquad());
                                                                patchlist($5, $1->test);
                                                                patchlist($7, $2 + 1);

                                                                $$ = new stmt_t;
                                                                $$->breaklist = $6->breaklist;
                                                                $$->contlist = $6->contlist;

                                                                fprintf(yyout, "[-] Reduced: forstmt -> FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON N elist RIGHT_PARENTHESIS N stmt M\n");
                                                        }
        ;

returnstmt: RETURN expr SEMICOLON       {       
                                                if (symTable.funcStack.empty()) {
                                                        fprintf(yyout, "      [!] Error: Return statement outside function in line %d.\n", yylineno);
                                                } else {
                                                        emit(getretval, nullptr, nullptr, $2);
                                                }
                                                $$ = new stmt_t;
                                                $$->breaklist = 0;
                                                $$->contlist = 0;
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN expr SEMICOLON\n");
                                        }
            | RETURN SEMICOLON          {       
                                                if (symTable.funcStack.empty()) {
                                                        fprintf(yyout, "      [!] Error: Return statement outside function in line %d.\n", yylineno);
                                                } else {
                                                        emit(getretval, nullptr, nullptr, newexpr(nil_e));
                                                }

                                                $$ = new stmt_t;
                                                $$->breaklist = 0;
                                                $$->contlist = 0;
                                                fprintf(yyout, "[-] Reduced: returnstmt -> RETURN SEMICOLON\n");
                                        }
            ;

errors: ERROR_COMMENT   {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_COMMENT\n");
                                fprintf(yyout, "      [!] Error: Invalid comment in line %d.\n", yylineno);
                                exit(1);
                        }

        | ERROR_STRING  {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_STRING\n");
                                fprintf(yyout, "      [!] Error: Invalid string in line %d.\n", yylineno);
                                exit(1);
                        }

        | ERROR_ESCAPE  {
                                fprintf(yyout, "[-] Reduced: errors -> ERROR_ESCAPE\n");
                                fprintf(yyout, "      [!] Error: Invalid escape sequence in line %d.\n", yylineno);
                                exit(1);
                        }

        | UNDEF         {
                                fprintf(yyout, "[-] Reduced: errors -> UNDEF\n");
                                fprintf(yyout, "      [!] Error: Undefined variable in line %d.\n", yylineno);    
                                exit(1);
                        }
        ;
%%

int yyerror(const char *msg) {
    fprintf(stderr, "      [Line %d] Syntax error: %s (near token: \"%s\")\n", yylineno, msg, yytext);
    return 0;
}
