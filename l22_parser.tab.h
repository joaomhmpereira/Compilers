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

#ifndef YY_YY_L22_PARSER_TAB_H_INCLUDED
# define YY_YY_L22_PARSER_TAB_H_INCLUDED
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
    tINTEGER = 258,                /* tINTEGER  */
    tIDENTIFIER = 259,             /* tIDENTIFIER  */
    tSTRING = 260,                 /* tSTRING  */
    tREAL = 261,                   /* tREAL  */
    tWHILE = 262,                  /* tWHILE  */
    tIF = 263,                     /* tIF  */
    tWRITE = 264,                  /* tWRITE  */
    tINPUT = 265,                  /* tINPUT  */
    tBEGIN = 266,                  /* tBEGIN  */
    tEND = 267,                    /* tEND  */
    tAT = 268,                     /* tAT  */
    tWRITELN = 269,                /* tWRITELN  */
    tELIF = 270,                   /* tELIF  */
    tAND = 271,                    /* tAND  */
    tOR = 272,                     /* tOR  */
    tNOT = 273,                    /* tNOT  */
    tINT = 274,                    /* tINT  */
    tDOUBLE = 275,                 /* tDOUBLE  */
    tTEXT = 276,                   /* tTEXT  */
    tAGAIN = 277,                  /* tAGAIN  */
    tRETURN = 278,                 /* tRETURN  */
    tSIZEOF = 279,                 /* tSIZEOF  */
    tPUBLIC = 280,                 /* tPUBLIC  */
    tFOREIGN = 281,                /* tFOREIGN  */
    tVAR = 282,                    /* tVAR  */
    tVOID = 283,                   /* tVOID  */
    tTHEN = 284,                   /* tTHEN  */
    tDO = 285,                     /* tDO  */
    tUSE = 286,                    /* tUSE  */
    tSTOP = 287,                   /* tSTOP  */
    tPRIVATE = 288,                /* tPRIVATE  */
    tARROW = 289,                  /* tARROW  */
    tNULL = 290,                   /* tNULL  */
    tELSE = 291,                   /* tELSE  */
    tEQ = 292,                     /* tEQ  */
    tNE = 293,                     /* tNE  */
    tGE = 294,                     /* tGE  */
    tLE = 295,                     /* tLE  */
    tUNARY = 296                   /* tUNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "l22_parser.y"

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


#line 127 "l22_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (std::shared_ptr<cdk::compiler> compiler);


#endif /* !YY_YY_L22_PARSER_TAB_H_INCLUDED  */
