#ifndef __L22_AST_WRITE_NODE_H__
#define __L22_AST_WRITE_NODE_H__

#include <cdk/ast/sequence_node.h>

namespace l22 {

  /**
   * Class for describing print nodes.
   */
  class write_node: public cdk::basic_node {
    cdk::sequence_node *_argument;
    bool _newLine = false;

  public:
    inline write_node(int lineno, cdk::sequence_node *argument, bool newLine = false) :
        cdk::basic_node(lineno), _argument(argument), _newLine(newLine) {
    }

  public:
    inline cdk::sequence_node *argument() {
      return _argument;
    }

    bool newLine() {
      return _newLine;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_write_node(this, level);
    }

  };

}

#endif
