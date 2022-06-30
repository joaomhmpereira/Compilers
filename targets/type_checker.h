#ifndef __L22_TARGETS_TYPE_CHECKER_H__
#define __L22_TARGETS_TYPE_CHECKER_H__

#include <stack>
#include "targets/basic_ast_visitor.h"

namespace l22 {

  /**
   * Print nodes as XML elements to the output stream.
   */
  class type_checker: public basic_ast_visitor {
    cdk::symbol_table<l22::symbol> &_symtab;
    std::shared_ptr<l22::symbol> _function;
    basic_ast_visitor *_parent;
    bool _isFunction;
    std::shared_ptr<cdk::basic_type> _inBlockReturnType = nullptr;
    std::stack<std::shared_ptr<cdk::basic_type>> _functionStack;


  public:
    type_checker(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<l22::symbol> &symtab, std::shared_ptr<l22::symbol> func, basic_ast_visitor *parent) :
        basic_ast_visitor(compiler), _symtab(symtab),_function(func), _parent(parent), _isFunction(false) {
    }

  public:
    ~type_checker() {
      os().flush();
    }

  protected:
    void do_IntOnlyExpression(cdk::binary_operation_node * const node, int lvl);
    void do_PIDExpression(cdk::binary_operation_node * const node, int lvl);
    void do_IDExpression(cdk::binary_operation_node * const node, int lvl);
  protected:
    void processUnaryExpression(cdk::unary_operation_node *const node, int lvl);
    void do_ScalarLogicalExpression(cdk::binary_operation_node * const node, int lvl);
    void do_GeneralLogicalExpression(cdk::binary_operation_node * const node, int lvl);
    void do_BooleanLogicalExpression(cdk::binary_operation_node * const node, int lvl);
    template<typename T>
    void process_literal(cdk::literal_node<T> *const node, int lvl) {
    }

  public:
    // do not edit these lines
#define __IN_VISITOR_HEADER__
#include ".auto/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
    // do not edit these lines: end

  };

} // l22

//---------------------------------------------------------------------------
//     HELPER MACRO FOR TYPE CHECKING
//---------------------------------------------------------------------------

#define CHECK_TYPES(compiler, symtab, function, node) { \
  try { \
    l22::type_checker checker(compiler, symtab,function ,this); \
    (node)->accept(&checker, 0); \
  } \
  catch (const std::string &problem) { \
    std::cerr << (node)->lineno() << ": " << problem << std::endl; \
    return; \
  } \
}

#define ASSERT_SAFE_EXPRESSIONS CHECK_TYPES(_compiler, _symtab, _function, node)

#endif
