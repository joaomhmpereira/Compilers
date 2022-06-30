#ifndef __L22_AST_ADDRESS_OF_NODE_H__
#define __L22_AST_ADDRESS_OF_NODE_H__

#include <cdk/ast/lvalue_node.h>
#include <cdk/ast/expression_node.h>

namespace l22 {

  /**
   * Class for describing address_of nodes.
   */
  class address_of_node: public cdk::expression_node {
    cdk::lvalue_node *_argument;

  public:
    inline address_of_node(int lineno, cdk::lvalue_node *argument) :
        cdk::expression_node(lineno), _argument(argument) {
    }

  public:
    inline cdk::lvalue_node *argument() {
      return _argument;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_address_of_node(this, level);
    }

  };

} // l22

#endif
