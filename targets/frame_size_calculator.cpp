#include <string>
#include "targets/type_checker.h"
#include "targets/frame_size_calculator.h"
#include ".auto/all_nodes.h"  // all_nodes.h is automatically generated

//---------------------------------------------------------------------------

l22::frame_size_calculator::~frame_size_calculator() {
  os().flush();
}

void l22::frame_size_calculator::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_double_node(cdk::double_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_not_node(cdk::not_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_and_node(cdk::and_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_or_node(cdk::or_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_address_of_node(l22::address_of_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_stop_node(l22::stop_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_again_node(l22::again_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_return_node(l22::return_node * const node, int lvl) {
  // EMPTY
}

void l22::frame_size_calculator::do_index_node(l22::index_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_sizeof_node(l22::sizeof_node * const node, int lvl) {
  //EMPTY
}


void l22::frame_size_calculator::do_null_node(l22::null_node * const node, int lvl) {
    //EMPTY
}
void l22::frame_size_calculator::do_function_call_node(l22::function_call_node * const node, int lvl) {
  // EMPTY
}

void l22::frame_size_calculator::do_stack_alloc_node(l22::stack_alloc_node * const node, int lvl) {
  // EMPTY
}
void l22::frame_size_calculator::do_identity_node(l22::identity_node * const node, int lvl) {
    //EMPTY
}



//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_integer_node(cdk::integer_node * const node, int lvl) {
    //EMPTY

}

void l22::frame_size_calculator::do_string_node(cdk::string_node * const node, int lvl) {
    //EMPTY

}

//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_neg_node(cdk::neg_node * const node, int lvl) {
  //EMPTY
}

//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_add_node(cdk::add_node * const node, int lvl) {
  //EMPTY
}
void l22::frame_size_calculator::do_sub_node(cdk::sub_node * const node, int lvl) {
}
void l22::frame_size_calculator::do_mul_node(cdk::mul_node * const node, int lvl) {
}
void l22::frame_size_calculator::do_div_node(cdk::div_node * const node, int lvl) {
}
void l22::frame_size_calculator::do_mod_node(cdk::mod_node * const node, int lvl) {
}
void l22::frame_size_calculator::do_lt_node(cdk::lt_node * const node, int lvl) {
}
void l22::frame_size_calculator::do_le_node(cdk::le_node * const node, int lvl) {
}
void l22::frame_size_calculator::do_ge_node(cdk::ge_node * const node, int lvl) {
}
void l22::frame_size_calculator::do_gt_node(cdk::gt_node * const node, int lvl) {
}
void l22::frame_size_calculator::do_ne_node(cdk::ne_node * const node, int lvl) {
}
void l22::frame_size_calculator::do_eq_node(cdk::eq_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_variable_node(cdk::variable_node * const node, int lvl) {
}

void l22::frame_size_calculator::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
}

void l22::frame_size_calculator::do_assignment_node(cdk::assignment_node * const node, int lvl) {
}

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_evaluation_node(l22::evaluation_node * const node, int lvl) {
}

void l22::frame_size_calculator::do_write_node(l22::write_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_input_node(l22::input_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_while_node(l22::while_node * const node, int lvl) {
  node->block()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_if_node(l22::if_node * const node, int lvl) {
  node->block()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_if_else_node(l22::if_else_node * const node, int lvl) {
  node->thenblock()->accept(this, lvl + 2);
  if(node->elseblock()) node->elseblock()->accept(this, lvl + 2);
}


void l22::frame_size_calculator::do_block_node(l22::block_node * const node, int lvl) {
  if (node->declarations()) node->declarations()->accept(this, lvl + 2);
  if (node->instructions()) node->instructions()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void l22::frame_size_calculator::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    cdk::basic_node *n = node->node(i);
    if(n == nullptr) break;
    n->accept(this, lvl);
  }
}

void l22::frame_size_calculator::do_variable_declaration_node(l22::variable_declaration_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS; 
  _localsize += node->type()->size();
}

void l22::frame_size_calculator::do_program_node(l22::program_node * const node, int lvl) {
  node->block()->accept(this, lvl);
}

void l22::frame_size_calculator::do_function_definition_node(l22::function_definition_node * const node, int lvl) {
  node->block()->accept(this, lvl + 2);
}
