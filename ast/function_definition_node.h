#ifndef __L22_AST_FUNCTION_DEFINITION_H__
#define __L22_AST_FUNCTION_DEFINITION_H__

#include <string>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>
#include "ast/block_node.h"

namespace l22 {
  
  class function_definition_node: public cdk::expression_node {
    cdk::sequence_node *_arguments;
    std::shared_ptr<cdk::basic_type> _returnType;
    l22::block_node *_block;

  // VERIFICAR O TIPO VOID
  public:
    function_definition_node(int lineno, cdk::sequence_node *arguments, l22::block_node *block) :
        cdk::expression_node(lineno), _arguments(arguments), _returnType(cdk::primitive_type::create(0, cdk::TYPE_VOID)), _block(block) {
    }

    function_definition_node(int lineno, std::shared_ptr<cdk::basic_type> returnType, 
              cdk::sequence_node *arguments, l22::block_node *block) :
        cdk::expression_node(lineno), _arguments(arguments), _returnType(returnType), _block(block) {
    }

  public:
    cdk::sequence_node* arguments() {
      return _arguments;
    }
    cdk::expression_node* argument(size_t ax) {
      return dynamic_cast<cdk::expression_node*>(_arguments->node(ax));
    }
    inline bool noArguments() const {
      return _arguments->size() == 0;
    }
    std::shared_ptr<cdk::basic_type> returnType(){
      return _returnType;
    }
    l22::block_node* block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

}

#endif