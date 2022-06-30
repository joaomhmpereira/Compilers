#include <string>
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated
#include <cdk/types/primitive_type.h>

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

//---------------------------------------------------------------------------

void l22::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void l22::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}

void l22::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}

void l22::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->type()->name() == cdk::TYPE_INT)
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if (node->argument()->type()->name() == cdk::TYPE_UNSPEC) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else
    throw std::string("wrong type in unary logical expression");
}

void l22::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}

void l22::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}

void l22::type_checker::do_address_of_node(l22::address_of_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  node->type(cdk::reference_type::create(4, node->argument()->type()));
}

void l22::type_checker::do_stop_node(l22::stop_node * const node, int lvl) {
  // EMPTY
}
void l22::type_checker::do_again_node(l22::again_node * const node, int lvl) {
  // EMPTY
}
void l22::type_checker::do_return_node(l22::return_node * const node, int lvl) {
  std::shared_ptr<cdk::functional_type> ftype = cdk::functional_type::cast(_functionStack.top());

  if (node->retval()) {
    if (ftype->output(0) != nullptr && ftype->output(0)->name() == cdk::TYPE_VOID) throw std::string(
        "initializer specified for void function.");
    node->retval()->accept(this, lvl + 2);

    if (_inBlockReturnType == nullptr) {
      _inBlockReturnType = node->retval()->type();
    } else {
      if (_inBlockReturnType != node->retval()->type()) {
        _function->set_type(cdk::primitive_type::create(0, cdk::TYPE_ERROR));  // probably irrelevant
        throw std::string("all return statements in a function must return the same type.");
      }
    }

    if (ftype->output(0)->name() == cdk::TYPE_INT) {
      if (!node->retval()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (ftype->output(0)->name() == cdk::TYPE_DOUBLE) {
      if (!node->retval()->is_typed(cdk::TYPE_INT) && !node->retval()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (ftype->output(0)->name() == cdk::TYPE_STRING) {
      if (!node->retval()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (ftype->output(0)->name() == cdk::TYPE_POINTER) {
      int ft = 0, rt = 0;
      auto type = ftype->output(0);
      while (type->name() == cdk::TYPE_POINTER) {
        ft++;
        type = cdk::reference_type::cast(type)->referenced();
      }
      auto rtype = node->retval()->type();
      while (rtype != nullptr && rtype->name() == cdk::TYPE_POINTER) {
        rt++;
        rtype = cdk::reference_type::cast(rtype)->referenced();
      }

      bool compatible = (ft == rt) && (rtype == nullptr || (rtype != nullptr && ftype->name() == rtype->name()));
      if (!compatible) throw std::string("wrong type for return expression (pointer expected).");

    } else {
      throw std::string("unknown type for initializer.");
    }
  }
}
void l22::type_checker::do_block_node(l22::block_node * const node, int lvl) {
  // EMPTY
}

void l22::type_checker::do_index_node(l22::index_node * const node, int lvl) {
  ASSERT_UNSPEC;
  std::shared_ptr < cdk::reference_type > btype;
  if (node->base()) {
    node->base()->accept(this, lvl + 2);
    btype = cdk::reference_type::cast(node->base()->type());
    if (!node->base()->is_typed(cdk::TYPE_POINTER)) throw std::string("pointer expression expected in index left-value");
  } 
  
  node->index()->accept(this, lvl + 2);
  if (!node->index()->is_typed(cdk::TYPE_INT)) throw std::string("integer expression expected in left-value index");
  node->type(btype->referenced());
}

void l22::type_checker::do_sizeof_node(l22::sizeof_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->expression()->accept(this, lvl + 2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_variable_declaration_node(l22::variable_declaration_node * const node, int lvl) {
  if(node->initializer() != nullptr){
    node->initializer()->accept(this, lvl+2);
    _isFunction = false;
    if(!node->type()){
      node->type(node->initializer()->type());
    }

    if (node->is_typed(cdk::TYPE_INT)){
      if (!node->initializer()->is_typed(cdk::TYPE_INT))
        throw std::string("wrong type for initializer (integer expected).");
    } else if (node->is_typed(cdk::TYPE_DOUBLE)){
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE))
        throw std::string("wrong type for initializer (integer or double expected).");
    } else if (node->is_typed(cdk::TYPE_STRING)){
      if (!node->initializer()->is_typed(cdk::TYPE_STRING))
        throw std::string("wrong type for initializer (string expected). ");
    } else if (node->is_typed(cdk::TYPE_POINTER)) {
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        auto in = (cdk::literal_node<int>*)node->initializer();
        if (in == nullptr || in->value() != 0) throw std::string("wrong type for initializer (pointer expected).");
      }
    } else if (node->is_typed(cdk::TYPE_FUNCTIONAL)) {
      _isFunction = true;
    } else {
      throw std::string("unknown type for initializer.");
    }
  }


  const std::string &id = node->identifier();
  auto symbol = l22::make_symbol(node->qualifier(), node->type(), id, (bool)node->initializer(), _isFunction);
  if(_isFunction){
    //_function->setName(node->identifier());
  }
  if (_symtab.insert(id, symbol)) {
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
  } else {
    throw std::string("variable '" + id + "' redeclared");
  }
}

void l22::type_checker::do_null_node(l22::null_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, nullptr));
}

void l22::type_checker::do_function_call_node(l22::function_call_node * const node, int lvl) {
  ASSERT_UNSPEC;

  if(node->pointer()){
    node->pointer()->accept(this, lvl+2);
    if(node->pointer()->is_typed(cdk::TYPE_FUNCTIONAL)){
      std::shared_ptr<cdk::functional_type> ftype = cdk::functional_type::cast(node->pointer()->type());

      if(node->arguments()->size() == ftype->input_length()){
        node->arguments()->accept(this, lvl+4);
        for (size_t ax = 0; ax < node->arguments()->size(); ax++) {


        if (node->argument(ax)->type() == ftype->input(ax)) continue;
        if (ftype->input(ax)->name() == cdk::TYPE_DOUBLE && node->argument(ax)->is_typed(cdk::TYPE_INT)) continue;
          throw std::string("type mismatch for argument " + std::to_string(ax + 1));
        }
      } else {
          throw std::string("conflicting length of input");
      }

      node->type(ftype->output(0));

    } else {
      throw std::string("not a function");
    }
  }
}

void l22::type_checker::do_function_definition_node(l22::function_definition_node * const node, int lvl) {
  std::shared_ptr<cdk::basic_type> output = node->returnType();
  // dealing with the types of the arguments
  std::vector<std::shared_ptr<cdk::basic_type>> argtypes;
  if(node->arguments()){

    node->arguments()->accept(this, lvl +2); // knowing their types in case of var

    for (size_t i = 0; i < node->arguments()->size(); i++){

      auto vardecnode =dynamic_cast<l22::variable_declaration_node*>(node->arguments()->node(i));
      argtypes.push_back(vardecnode->type());
    }
  }


  if (argtypes.size() > 0){
    node->type(cdk::functional_type::create(argtypes, output));
  } else {
    node->type(cdk::functional_type::create(output));
  }
  _functionStack.push(node->type());
  node->block()->accept(this, lvl + 2);
  _functionStack.pop();  
}

void l22::type_checker::do_stack_alloc_node(l22::stack_alloc_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  node->type(cdk::reference_type::create(4, cdk::primitive_type::create(1, cdk::TYPE_VOID)));
}

void l22::type_checker::do_identity_node(l22::identity_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}

//---------------------------------------------------------------------------

void l22::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in argument of unary expression");

  // in Simple, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------
void l22::type_checker::do_IntOnlyExpression(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() != cdk::TYPE_INT) throw std::string(
      "integer expression expected in binary operator (left)");

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() != cdk::TYPE_INT) throw std::string(
      "integer expression expected in binary operator (right)");

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------
void l22::type_checker::do_IDExpression(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_DOUBLE)
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_INT)
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE)
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_INT)
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if (node->left()->type()->name() == cdk::TYPE_UNSPEC && node->right()->type()->name() == cdk::TYPE_UNSPEC) {
// for @ in @ + @
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else
    throw std::string("wrong types in binary expression");
}

//---------------------------------------------------------------------------
void l22::type_checker::do_PIDExpression(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_DOUBLE)
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_INT)
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE)
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->type()->name() == cdk::TYPE_POINTER && node->right()->type()->name() == cdk::TYPE_INT){
    std::shared_ptr<cdk::reference_type> rtype = cdk::reference_type::cast(node->left()->type());
    node->type(cdk::reference_type::create(4, rtype->referenced()));
  }
  else if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_POINTER)
    node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
  else if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_INT)
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if (node->left()->type()->name() == cdk::TYPE_UNSPEC && node->right()->type()->name() == cdk::TYPE_UNSPEC) {
// for @ in @ + @
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else
    throw std::string("wrong types in binary expression");
}


void l22::type_checker::do_ScalarLogicalExpression(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() != cdk::TYPE_INT) throw std::string(
      "integer expression expected in binary logical expression (left)");

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() != cdk::TYPE_INT) throw std::string(
      "integer expression expected in binary logical expression (right)");

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_BooleanLogicalExpression(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() != cdk::TYPE_INT) throw std::string("integer expression expected in binary expression");

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() != cdk::TYPE_INT) throw std::string("integer expression expected in binary expression");

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_GeneralLogicalExpression(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  if (node->left()->type()->name() != node->right()->type()->name()) throw std::string(
      "same type expected on both sides of equality operator");
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void l22::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void l22::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  do_IDExpression(node, lvl);
}
void l22::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  do_IDExpression(node, lvl);
}
void l22::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  do_IntOnlyExpression(node, lvl);
}
void l22::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void l22::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void l22::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void l22::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void l22::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void l22::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<l22::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  } else {
    throw id + ": undeclared variable";
  }
}

void l22::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void l22::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;

  node->lvalue()->accept(this, lvl + 4);
  node->rvalue()->accept(this, lvl + 4);

  if (node->lvalue()->is_typed(cdk::TYPE_INT)){
  
    if (node->rvalue()->is_typed(cdk::TYPE_INT)){
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)){
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else {
      throw std::string("wrong assignment to integer");
    }
  
  } else if (node->lvalue()->is_typed(cdk::TYPE_POINTER)) {

    if (node->rvalue()->is_typed(cdk::TYPE_POINTER)) {
      node->type(node->rvalue()->type());
    } else if (node->rvalue()->is_typed(cdk::TYPE_INT)){
      //auto check_zero = dynamic_cast<cdk::integer_node*>(node->rvalue());
      //if (check_zero->value() != 0)
      //  throw std::string("expected 0 in assignment to pointer");
      node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
    } else {
      throw std::string("wrong assignment to pointer");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_DOUBLE)) {

    if (node->rvalue()->is_typed(cdk::TYPE_DOUBLE) || node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
      node->rvalue()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else {
      throw std::string("wrong assignment to real");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_STRING)) {

    if (node->rvalue()->is_typed(cdk::TYPE_STRING)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else {
      throw std::string("wrong assignment to string");
    }

  } else {
    throw std::string("wrong types in assignment");
  }
}

//---------------------------------------------------------------------------

void l22::type_checker::do_program_node(l22::program_node *const node, int lvl) {
  node->block()->accept(this, lvl+2);
}

void l22::type_checker::do_evaluation_node(l22::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void l22::type_checker::do_write_node(l22::write_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_input_node(l22::input_node *const node, int lvl) {
  node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
}

//---------------------------------------------------------------------------

void l22::type_checker::do_while_node(l22::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_if_node(l22::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (!node->condition()->is_typed(cdk::TYPE_INT)) 
    throw std::string("expected integer condition");
}

void l22::type_checker::do_if_else_node(l22::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}
