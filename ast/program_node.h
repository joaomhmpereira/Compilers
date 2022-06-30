#ifndef __L22_AST_PROGRAM_NODE_H__
#define __L22_AST_PROGRAM_NODE_H__

#include <cdk/ast/basic_node.h>
#include "ast/block_node.h"

namespace l22 {

  /**
   * Class for describing program nodes.
   */
  class program_node: public cdk::basic_node {
    l22::block_node *_block;

  public:
    inline program_node(int lineno, l22::block_node *block) :
        cdk::basic_node(lineno), _block(block) {
    }

  public:
    inline cdk::basic_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_program_node(this, level);
    }

  };

} // l22

#endif
