%option c++ prefix="l22_scanner_" outfile="l22_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "l22_parser.tab.h"

// output stream for building string literals
static std::ostringstream strlit;

static bool restart_functions = false;

static int lLevelsToPop = 0, lIndex = 0;
static std::vector<int> indents;   // known indentation levels

inline bool valid(int indent) {
    lLevelsToPop = lIndex = -1;
    bool indentOk = false;
    for (size_t ix = 0; ix < indents.size(); ix++) {
        if (indent == indents[ix]) {
            lLevelsToPop = indents.size() - ix - 1;
            lIndex = ix;
            indentOk = true;
        }
    }
    return indentOk;
}

// don't change this
#define yyerror LexerError
%}

SPACE     [ ]
%x X_STRING X_COMMENT X_BACKSLASH X_SKIP
%x X_NEWLINE
%%
  /*yydebug=1; set_debug(1);*/
  {
        //std::cerr << "################" << std::endl;
        //set_debug(true);
        if (restart_functions) {
          //std::cerr << "POPPING FUNCTIONS (" << indents.size() << ")" << std::endl;
          indents.pop_back();
          if (indents.size() == 0) restart_functions = false;
          return '}';
        }
        else {
          if (lLevelsToPop > 0) {
            //std::cerr << "POPPING LEVELS (" << lLevelsToPop << ")" << std::endl;
            lLevelsToPop--;
            indents.pop_back();
            return '}';
          }
        }
        
  }

  /* ====================================================================== */
  /* ====[                        3.2.2 - INDENTATION                 ]==== */
  /* ====================================================================== */

\n                   yy_push_state(X_NEWLINE); /* delay decision */

<X_NEWLINE>^{SPACE}+  {
    yy_pop_state();

    if (valid(yyleng)) {
          //std::cerr << "CASE 1" << std::endl;
          if (lLevelsToPop == 0) {
            // at the same level: ignore index
            // do not return tINDENT;
            //std::cerr << "CASE 1a (levels to pop = 0)" << std::endl;
            return ';';
          }
          else {
            // nothing is done here: the scanner will ignore the input while levels > 0
            // and send block-end tokens to the parser
            //std::cerr << "CASE 1b (levels to pop = " << lLevelsToPop << ")" << std::endl;
            // at least one has to be returned here...
            if (lLevelsToPop > 0) {
              //std::cerr << "POPPING LEVELS (" << lLevelsToPop << ")" << std::endl;
              lLevelsToPop--;
              indents.pop_back();
              return '}';
            }
          }
    }
    else if (indents.size() == 0) {
          // first block to open
          //std::cerr << "CASE 2" << std::endl;
          indents.push_back(yyleng);
          return '{';
    }
    else if (yyleng > indents.back()) {
          // this is like the one before, but not the first
          //std::cerr << "CASE 3" << std::endl;
          indents.push_back(yyleng);
          return '{';
    }
    else {
          // something wrong: bad indent: communicate to user
          //std::cerr << "CASE 4" << std::endl;
          //std::cerr << "bad indent at line " << yylineno;
    }

}
<X_NEWLINE>\n      ; // ignore successive newline chars
<X_NEWLINE>.       {
  // in this case, we have a new function starting
  // first, return whatever we are seeing to the input
  yyless(0);
  yy_pop_state();
  if (indents.size() > 0) {
    //std::cerr << "should restart " << indents.size() << " functions at " << yylineno << std::endl;
    indents.pop_back();
    if (indents.size() > 0) { restart_functions = true; }
    return '}';
  }
  else return ';'; // top-level declarations
}

  /* ====================================================================== */
  /* ====[                      3.3 - COMMENTS                        ]==== */
  /* ====================================================================== */

{SPACE}*"..."\n        ;

";".*                ; /* ignore comments */

"(*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"(*"        yy_push_state(X_COMMENT);
<X_COMMENT>"*)"        yy_pop_state();
<X_COMMENT>.           ; /* ignore comments */


  /* ====================================================================== */
  /* ====[               3.6 - Operadores de expressões               ]==== */
  /* ====================================================================== */

">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE;
"input"                return tINPUT;
"and"                  return tAND;
"or"                   return tOR;
"not"                  return tNOT;
"sizeof"               return tSIZEOF;


  /* ====================================================================== */
  /* ====[                  3.9   - Literais                          ]==== */
  /* ====================================================================== */

"int"                  return tINT;
"double"               return tDOUBLE;
"text"                 return tTEXT;
"void"                 return tVOID;

"null"                 return tNULL;

"\""                      yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\\              yy_push_state(X_BACKSLASH);
<X_STRING>"\""            {
                            yylval.s = new std::string(strlit.str());
                            strlit.str("");
                            yy_pop_state();
                            return tSTRING;
                          }
<X_STRING>.               strlit << *yytext;

<X_BACKSLASH>"0"          yy_push_state(X_SKIP);
<X_BACKSLASH>n            strlit << '\n'; yy_pop_state();
<X_BACKSLASH>r            strlit << '\r'; yy_pop_state();
<X_BACKSLASH>t            strlit << '\t'; yy_pop_state();
<X_BACKSLASH>\\           strlit << '\\'; yy_pop_state();

<X_BACKSLASH>[0-6]{1,3}   {
                            strlit << (char)(unsigned char)strtoul(yytext, NULL, 7);
                            if (errno == ERANGE) yyerror("Overflow string base 7");
                            yy_pop_state();
                          }
<X_BACKSLASH>.            strlit << *yytext; yy_pop_state();

<X_SKIP>"\""                  {
                                yy_pop_state();yy_pop_state();yy_pop_state();
                                yylval.s = new std::string(strlit.str());
                                strlit.str("");
                                return tSTRING;
                                }
                                
<X_SKIP>.                     ;

0[0-6]+              {  yylval.i = strtoul(yytext, NULL, 7); 
                        if (errno == ERANGE) yyerror("Overflow base 7"); 
                        else return tINTEGER;
                     }
0[0-9]+              yyerror("Invalid base 7 number.");

0|[1-9][0-9]*        {  yylval.i = strtol(yytext, nullptr, 10); 
                        if (errno == ERANGE) yyerror("Overflow base 10"); 
                        else return tINTEGER;
                     }

([0-9]*\.[0-9]+|[0-9]+\.[0-9]*|[0-9]+)([Ee][-+]?[0-9]+)? { yylval.d = strtod(yytext, NULL); 
                                                            if (errno == ERANGE) yyerror("Overflow double"); 
                                                            else return tREAL;
                                                         }


  /* ====================================================================== */
  /* ====[                  4.5   - Símbolos globais                  ]==== */
  /* ====================================================================== */

"public"               return tPUBLIC;
"foreign"              return tFOREIGN;
"use"                  return tUSE;
"var"                  return tVAR;  

  /* ====================================================================== */
  /* ====[                  5   - Funções                             ]==== */
  /* ====================================================================== */

"@"                    return tAT;
"->"                   return tARROW;

  /* ====================================================================== */
  /* ====[                 6.2 - Instrução condicional                ]==== */
  /* ====================================================================== */

"if"                   return tIF; 
"else:"                return tELSE; 
"then:"                return tTHEN;
"elif"                 return tELIF;

  /* ====================================================================== */
  /* ====[                 6.2 - Instrução condicional                ]==== */
  /* ====[                 6.3 - Instrução de iteração                ]==== */
  /* ====[                 6.4 - Instrução de terminação              ]==== */
  /* ====[                 6.5 - Instrução de continuação             ]==== */
  /* ====[                 6.6 - Instrução de retorno                 ]==== */
  /* ====[                 6.8 - Instrução de impressão               ]==== */
  /* ====================================================================== */

"while"                return tWHILE;
"do:"                  return tDO;
"stop"                 return tSTOP;
"again"                return tAGAIN;
"return"               return tRETURN;
"write"                return tWRITE; 
"writeln"              return tWRITELN;


  /* ====================================================================== */
  /* ====[        5.4 - Função principal e execução de programas      ]==== */
  /* ====================================================================== */

"begin"                return tBEGIN; 
"end"                  return tEND;  

  

  /* ====================================================================== */
  /* ====[                3.8 - Identificadores (nomes)               ]==== */
  /* ====================================================================== */

[A-Za-z]([A-Za-z_]|[[:digit:]])*  yylval.s = new std::string(yytext); return tIDENTIFIER;

  /* ====================================================================== */
  /* ====[                     Other symbols                          ]==== */
  /* ====================================================================== */

[-()<>=+*/%;{}.:,\[\]?]       return *yytext;

[\n]+                   ; /* ignore whitespace */
[ ]+                    ; /* ignore whitespace */
           
.                      yyerror("Unknown character");

%%
