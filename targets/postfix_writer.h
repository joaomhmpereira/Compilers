#ifndef __L22_TARGETS_POSTFIX_WRITER_H__
#define __L22_TARGETS_POSTFIX_WRITER_H__

#include "targets/basic_ast_visitor.h"

#include <set>
#include <stack>
#include <sstream>
#include <cdk/emitters/basic_postfix_emitter.h>

namespace l22 {

  //!
  //! Traverse syntax tree and generate the corresponding assembly code.
  //!
  class postfix_writer: public basic_ast_visitor {
    cdk::symbol_table<l22::symbol> &_symtab;
    cdk::basic_postfix_emitter &_pf;
    int _lbl;
    std::set<std::string> _functions_to_declare;
    std::shared_ptr<l22::symbol> _function; // for keeping track of the current function and its arguments
    bool _errors, _inFunctionBody, _inFunctionArgs, _inProgramBody;
    bool _returnSeen; // when building a function
    bool _inFunctionCall, _inFunctionCallArgs;
    std::stack<int> _whileIni, _whileEnd; // for break/repeat
    int _offset; // current framepointer offset (0 means no vars defined)
    std::stack<std::shared_ptr<cdk::basic_type>> _currentFunctionType;
    std::string _functionName;
    std::string _currentBodyRetLabel;

  public:
    postfix_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<l22::symbol> &symtab,
                   cdk::basic_postfix_emitter &pf) :
        basic_ast_visitor(compiler), _symtab(symtab), _pf(pf), _lbl(0), _function(nullptr), _errors(false), 
              _inFunctionBody(false), _inFunctionArgs(false), _inProgramBody(false), _returnSeen(false),_offset(0),
               _functionName(""), _currentBodyRetLabel("") {
    }

  public:
    ~postfix_writer() {
      os().flush();
    }

  private:
    /** Method used to generate sequential labels. */
    inline std::string mklbl(int lbl) {
      std::ostringstream oss;
      if (lbl < 0)
        oss << ".L" << -lbl;
      else
        oss << "_L" << lbl;
      return oss.str();
    }

  public:
  // do not edit these lines
#define __IN_VISITOR_HEADER__
#include ".auto/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
  // do not edit these lines: end

  };

} // l22

#endif
