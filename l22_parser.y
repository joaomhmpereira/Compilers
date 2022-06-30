%{
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
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!
  
  double                                          d;
  int                                             i;	/* integer value */
  std::string                                     *s;	/* symbol name or string literal */
  cdk::basic_node                                 *node;	/* node pointer */
  cdk::sequence_node                              *sequence;
  cdk::expression_node                            *expression; /* expression nodes */
  cdk::lvalue_node                                *lvalue;
  l22::block_node                                 *block;
  std::vector<std::shared_ptr<cdk::basic_type>>   *vector;

};

%token <i> tINTEGER
%token <s> tIDENTIFIER tSTRING
%token <d> tREAL
%token tWHILE tIF tWRITE tINPUT tBEGIN tEND tAT
%token tWRITELN tELIF tAND tOR tNOT tINT tDOUBLE tTEXT tAGAIN tRETURN tSIZEOF
%token tPUBLIC tFOREIGN tVAR tVOID tTHEN tDO tUSE tSTOP tPRIVATE tARROW
%token<expression> tNULL

%nonassoc tIF
%nonassoc tTHEN tDO
%nonassoc tELSE tELIF

%right '='
%left tAND tOR
%nonassoc tNOT
%left tEQ tNE 
%left '>' '<' tGE tLE
%left '+' '-'
%left '*' '/' '%'
%right tUNARY
%nonassoc '?' '[' ']'
//assim resolve conflito do estado 142
%right '(' ')' 

%type<node> instruction declaration program elif cond_instruction it_instruction
%type<node> vardecl argdec
%type<sequence> expressions argdecs
%type<sequence> file declarations innerdecls instructions
%type<expression> expression integer real fundef func_cal
%type<lvalue> lval
%type<block> block
%type<vector> data_types

%type<s> string
%type<type> data_type func_type return_type

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file           :   /* empty */             { compiler->ast($$ = new cdk::sequence_node(LINE)); }
               |   declarations            { compiler->ast($1); }
               |   program                 { compiler->ast($1); }
               |   declarations program    { compiler->ast($$ = new cdk::sequence_node(LINE, $2, $1)); }
               ;

declarations   :              declaration     { $$ = new cdk::sequence_node(LINE, $1); }
               | declarations declaration     { $$ = new cdk::sequence_node(LINE, $2, $1); }
               ;

declaration    :    vardecl ';' { $$ = $1; }
               |    vardecl     { $$ = $1; }
               ;

vardecl        :    tPUBLIC  data_type tIDENTIFIER '=' expression       { $$ = new l22::variable_declaration_node(LINE, tPUBLIC, $2, *$3, $5); }
               |    tPUBLIC  data_type tIDENTIFIER                      { $$ = new l22::variable_declaration_node(LINE, tPUBLIC, $2, *$3, nullptr); }
               |    tUSE     data_type tIDENTIFIER                      { $$ = new l22::variable_declaration_node(LINE, tUSE, $2, *$3, nullptr); }
               |             data_type tIDENTIFIER '=' expression       { $$ = new l22::variable_declaration_node(LINE, tPRIVATE, $1, *$2, $4); }
               |             data_type tIDENTIFIER                      { $$ = new l22::variable_declaration_node(LINE, tPRIVATE, $1, *$2, nullptr); }
               |    tPUBLIC  tVAR      tIDENTIFIER '=' expression       { $$ = new l22::variable_declaration_node(LINE, tPUBLIC, $5->type(), *$3, $5); }
               |    tPUBLIC            tIDENTIFIER '=' expression       { $$ = new l22::variable_declaration_node(LINE, tPUBLIC, $4->type(), *$2, $4); }
               |             tVAR      tIDENTIFIER '=' expression       { $$ = new l22::variable_declaration_node(LINE, tPRIVATE, $4->type(), *$2, $4); }
               |    tFOREIGN data_type tIDENTIFIER                      { $$ = new l22::variable_declaration_node(LINE, tFOREIGN, $2, *$3, nullptr); }
               ;

data_type      : tTEXT                         { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
               | tINT                          { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT); }
               | tDOUBLE                       { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
               | '[' data_type ']'             { $$ = cdk::reference_type::create(4, $2);}
               | func_type                     { $$ = $1; }
               ;

func_type      : return_type '<' data_types '>'   { $$ = cdk::functional_type::create(*$3, $1); }
               | return_type '<' '>'              { $$ = cdk::functional_type::create(*(new std::vector<std::shared_ptr<cdk::basic_type>>()), $1); }
               ;

return_type    : data_type                     { $$ = $1; }
               | tVOID                         { $$ = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
               ;

data_types     : data_type                     { $$ = new std::vector<std::shared_ptr<cdk::basic_type>>(); $$->insert($$->begin(), $1); }
               | data_type ',' data_types      { $$ = $3; $$->insert($$->begin(), $1); }
               ;

program        : tBEGIN block tEND      { $$ = new l22::program_node(LINE, $2); }
               ;


block          : '{'                instructions '}'   { $$ = new l22::block_node(LINE, nullptr, $2); }
               | '{'                             '}'   { $$ = new l22::block_node(LINE, nullptr, new cdk::sequence_node(LINE)); }
               | '{' innerdecls                  '}'   { $$ = new l22::block_node(LINE, $2, new cdk::sequence_node(LINE) ); }
               | '{' innerdecls     instructions '}'   { $$ = new l22::block_node(LINE, $2, $3); }
               | '{' innerdecls ';' instructions '}'   { $$ = new l22::block_node(LINE, $2, $4); }
               ;  

innerdecls     :            declaration         { $$ = new cdk::sequence_node(LINE, $1); }
               | innerdecls declaration         { $$ = new cdk::sequence_node(LINE, $2, $1); }
               ;


instructions   :    instruction                        { $$ = new cdk::sequence_node(LINE, $1); }
               |    cond_instruction                   { $$ = new cdk::sequence_node(LINE, $1); }
               |    it_instruction                     { $$ = new cdk::sequence_node(LINE, $1); }
               |    instruction ';' instructions       { std::reverse($3->nodes().begin(), $3->nodes().end()); $$ = new cdk::sequence_node(LINE, $1, $3); std::reverse($$->nodes().begin(), $$->nodes().end()); }
               |    instruction instructions           { std::reverse($2->nodes().begin(), $2->nodes().end()); $$ = new cdk::sequence_node(LINE, $1, $2); std::reverse($$->nodes().begin(), $$->nodes().end()); }
               |    cond_instruction instructions      { std::reverse($2->nodes().begin(), $2->nodes().end()); $$ = new cdk::sequence_node(LINE, $1, $2); std::reverse($$->nodes().begin(), $$->nodes().end()); }
               |    it_instruction instructions        { std::reverse($2->nodes().begin(), $2->nodes().end()); $$ = new cdk::sequence_node(LINE, $1, $2); std::reverse($$->nodes().begin(), $$->nodes().end()); }
               ;

instruction    : expression             { $$ = new l22::evaluation_node(LINE, $1); }
               | tWRITE expressions     { $$ = new l22::write_node(LINE, $2, false); }
               | tWRITELN expressions   { $$ = new l22::write_node(LINE, $2, true); }
               | tAGAIN                 { $$ = new l22::again_node(LINE); }
               | tSTOP                  { $$ = new l22::stop_node(LINE); }
               | tRETURN expression     { $$ = new l22::return_node(LINE, $2); }
               | block                  { $$ = $1; }
               ;

cond_instruction    : tIF '(' expression ')' tTHEN block        { $$ = new l22::if_node(LINE, $3, $6); }
                    | tIF '(' expression ')' tTHEN block elif   { $$ = new l22::if_else_node(LINE, $3, $6, $7); }
                    ;    

it_instruction : tWHILE '(' expression ')' tDO block       { $$ = new l22::while_node(LINE, $3, $6); }
               ;


elif           : tELSE block                                          { $$ = $2; }
               | tELIF '(' expression ')' tTHEN block                 { $$ = new l22::if_node(LINE, $3, $6); }
               | tELIF '(' expression ')' tTHEN block elif            { $$ = new l22::if_else_node(LINE, $3, $6, $7); }
               ;  

expressions    :                 expression       { $$ = new cdk::sequence_node(LINE, $1); }
               | expressions ',' expression       { $$ = new cdk::sequence_node(LINE, $3, $1); }
               ;

expression     : integer                                    { $$ = $1; }
               | real                                       { $$ = $1; }
               | string                                     { $$ = new cdk::string_node(LINE, $1); }
               | tNULL                                      { $$ = new l22::null_node(LINE); }
               | fundef                                     { $$ = $1; }
               | func_cal                                   { $$ = $1; }
               | lval                                       { $$ = new cdk::rvalue_node(LINE, $1); }
               | lval       '=' expression                  { $$ = new cdk::assignment_node(LINE, $1, $3); }
               | lval '?'                                   { $$ = new l22::address_of_node(LINE, $1); }
               | expression '+' expression	                { $$ = new cdk::add_node(LINE, $1, $3); }
               | expression '-' expression	                { $$ = new cdk::sub_node(LINE, $1, $3); }
               | expression '*' expression	                { $$ = new cdk::mul_node(LINE, $1, $3); }
               | expression '/' expression	                { $$ = new cdk::div_node(LINE, $1, $3); }
               | expression '%' expression	                { $$ = new cdk::mod_node(LINE, $1, $3); }
               | expression '<' expression	                { $$ = new cdk::lt_node(LINE, $1, $3); }
               | expression '>' expression	                { $$ = new cdk::gt_node(LINE, $1, $3); }
               | expression tGE expression	                { $$ = new cdk::ge_node(LINE, $1, $3); }
               | expression tLE expression                  { $$ = new cdk::le_node(LINE, $1, $3); }
               | expression tNE expression	                { $$ = new cdk::ne_node(LINE, $1, $3); }
               | expression tEQ expression	                { $$ = new cdk::eq_node(LINE, $1, $3); }
               | expression tAND  expression                { $$ = new cdk::and_node(LINE, $1, $3); }
               | expression tOR   expression                { $$ = new cdk::or_node (LINE, $1, $3); }
               | '-' expression %prec tUNARY                { $$ = new cdk::neg_node(LINE, $2); }
               | '+' expression %prec tUNARY                { $$ = new l22::identity_node(LINE, $2); }
               | tNOT expression                            { $$ = new cdk::not_node(LINE, $2); }
               | tINPUT                                     { $$ = new l22::input_node(LINE);  }
               | tSIZEOF '(' expression ')'                 { $$ = new l22::sizeof_node(LINE, $3); }
               | '(' expression ')'                         { $$ = $2; }
               | '[' expression ']'                         { $$ = new l22::stack_alloc_node(LINE, $2); }                                  
               ;

fundef         :    '(' argdecs ')' tARROW return_type ':' block    { $$ = new l22::function_definition_node(LINE, $5, $2, $7); }
               |    '('         ')' tARROW return_type ':' block    { $$ = new l22::function_definition_node(LINE, $4, new cdk::sequence_node(LINE), $6); }
               ;

func_cal       : lval               '(' expressions ')'     { $$ = new l22::function_call_node(LINE, new cdk::rvalue_node(LINE, $1), $3); }
               | lval               '('             ')'     { $$ = new l22::function_call_node(LINE, new cdk::rvalue_node(LINE, $1)); }
               | tAT                '(' expressions ')'     { $$ = new l22::function_call_node(LINE, nullptr, $3); }
               | tAT                '('             ')'     { $$ = new l22::function_call_node(LINE, nullptr); }
               | '(' expression ')' '(' expressions ')'     { $$ = new l22::function_call_node(LINE, $2, $5); }
               | '(' expression ')' '('             ')'     { $$ = new l22::function_call_node(LINE, $2); }
               ;
          
argdecs        :             argdec  { $$ = new cdk::sequence_node(LINE, $1);     }
               | argdecs ',' argdec  { $$ = new cdk::sequence_node(LINE, $3, $1); }
               ;

argdec         : data_type tIDENTIFIER { $$ = new l22::variable_declaration_node(LINE, tPRIVATE, $1, *$2, nullptr); }
               ;

lval           : tIDENTIFIER                      { $$ = new cdk::variable_node(LINE, $1); }
               | expression '[' expression ']'    { $$ = new l22::index_node(LINE, $1, $3); }
               ;

integer        : tINTEGER                      { $$ = new cdk::integer_node(LINE, $1); };
real           : tREAL                         { $$ = new cdk::double_node(LINE, $1); };
string         : tSTRING                       { $$ = $1; }
               | string tSTRING                { $$ = new std::string(*$1 + *$2); delete $1; delete $2; }
               ;

%%
