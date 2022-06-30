#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "targets/frame_size_calculator.h"
#include ".auto/all_nodes.h"  // all_nodes.h is automatically generated

//---------------------------------------------------------------------------

void l22::postfix_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void l22::postfix_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void l22::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  if (_inFunctionBody || _inProgramBody) {
    _pf.DOUBLE(node->value()); // load number to the stack
  } else {
    _pf.SDOUBLE(node->value());    // double is on the DATA segment
  }
}
void l22::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  node->argument()->accept(this, lvl + 2);
  _pf.INT(0);
  _pf.EQ();
}

void l22::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.AND();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

void l22::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JNZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.OR();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

void l22::postfix_writer::do_address_of_node(l22::address_of_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  // since the argument is an lvalue, it is already an address
  node->argument()->accept(this, lvl + 2);
}

void l22::postfix_writer::do_stop_node(l22::stop_node * const node, int lvl) {
  // EMPTY
}

void l22::postfix_writer::do_again_node(l22::again_node * const node, int lvl) {
  // EMPTY
}

void l22::postfix_writer::do_return_node(l22::return_node * const node, int lvl) {
  // should not reach here without returning a value (if not void)
  if(!_currentFunctionType.empty()){
    std::shared_ptr<cdk::functional_type> ftype = cdk::functional_type::cast(_currentFunctionType.top());
    if (ftype->output(0)->name() != cdk::TYPE_VOID) {
      node->retval()->accept(this, lvl + 2);
      if (ftype->output(0)->name() == cdk::TYPE_INT || ftype->output(0)->name() == cdk::TYPE_STRING
          || ftype->output(0)->name() == cdk::TYPE_POINTER) {
        _pf.STFVAL32();
      } else if (ftype->output(0)->name() == cdk::TYPE_DOUBLE) {
        if (node->retval()->type()->name() == cdk::TYPE_INT) _pf.I2D();
        _pf.STFVAL64();
      } else {
        std::cerr << node->lineno() << ": should not happen: unknown return type" << std::endl;
      }
    }
    _returnSeen = true;
  } else {
    _pf.INT(0);
    _pf.STFVAL32();
  }
}

void l22::postfix_writer::do_block_node(l22::block_node * const node, int lvl) {
  _symtab.push(); // for block-local vars
  if (node->declarations()) node->declarations()->accept(this, lvl + 2);
  if (node->instructions()) node->instructions()->accept(this, lvl + 2);
  _symtab.pop();
}

void l22::postfix_writer::do_index_node(l22::index_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if (node->base()) {
    node->base()->accept(this, lvl);
  } else {
    if (_function) {
      _pf.LOCV(-_function->type()->size());
    } else {
      std::cerr << "FATAL: " << node->lineno() << ": trying to use return value outside function" << std::endl;
    }
  }
  node->index()->accept(this, lvl);
  _pf.INT(3);
  _pf.SHTL();
  _pf.ADD(); // add pointer and index
}

void l22::postfix_writer::do_sizeof_node(l22::sizeof_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  _pf.INT(node->expression()->type()->size());
}

void l22::postfix_writer::do_variable_declaration_node(l22::variable_declaration_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  std::shared_ptr<l22::symbol> symbol = _symtab.find(node->identifier());
  if(!_inProgramBody && node->is_typed(cdk::TYPE_FUNCTIONAL) && !_inFunctionArgs){ //programbody? baaah
    if(node->initializer()){
      node->initializer()->accept(this,lvl);
    }   //local variable with initializer
    symbol->set_global(true);
    _pf.TEXT();
    _pf.ADDR(_functionName);
  }

  if(_inFunctionBody && _inFunctionArgs){ 
    symbol->set_offset(_offset);
    symbol->set_global(false);
    _offset += node->type()->size();
  }

  else if(_inFunctionBody && !_inFunctionArgs){
    _offset -= node->type()->size();
    symbol->set_offset(_offset);
    symbol->set_global(false);

    if(node->initializer()){       //local variable with initializer
      node->initializer()->accept(this,lvl);

    if(node->is_typed(cdk::TYPE_DOUBLE) && node->initializer()->is_typed(cdk::TYPE_INT))
      _pf.I2D();

    _pf.LOCAL(_offset);
    if(node->is_typed(cdk::TYPE_DOUBLE))
      _pf.STDOUBLE();
      
    else
      _pf.STINT();
    }
  }

  else if(_inProgramBody){   //local variable
    _offset -= node->type()->size();
    symbol->set_offset(_offset);
    

    if(node->initializer()){       //local variable with initializer
      node->initializer()->accept(this,lvl);

      if(node->is_typed(cdk::TYPE_DOUBLE) && node->initializer()->is_typed(cdk::TYPE_INT))
        _pf.I2D();

      _pf.LOCAL(_offset);
      if(node->is_typed(cdk::TYPE_DOUBLE))
        _pf.STDOUBLE();
      
      else
        _pf.STINT();
    }
  }

  else if(!_inFunctionBody && !_inFunctionArgs && !node->initializer()){
    _pf.BSS();
    _pf.ALIGN();

    if(node->is_public()){
      _pf.GLOBAL(node->identifier(), _pf.OBJ());
    }
    
    _pf.LABEL(node->identifier());
    _pf.SALLOC(node->type()->size());
  }

  else if(!_inFunctionBody && !node->initializer()){
    symbol->set_offset(_offset);
    symbol->set_global(false);
    _offset += node->type()->size();
  }

  else if(!_inFunctionBody && node->initializer()){
    int lbl1;

        
    if(node->initializer()->is_typed(cdk::TYPE_STRING)){  //create referenceable string first
      _pf.RODATA();
      _pf.ALIGN();
      _pf.LABEL(mklbl(lbl1 = ++_lbl));
      cdk::string_node *init_node = dynamic_cast<cdk::string_node*>(node->initializer());
      _pf.SSTRING(init_node->value());
    }

    _pf.DATA();
    _pf.ALIGN();
    if(node->is_public())
      _pf.GLOBAL(node->identifier(), _pf.OBJ());
    
    _pf.LABEL(node->identifier());

    if(node->initializer()->is_typed(cdk::TYPE_STRING)){
      _pf.SADDR(mklbl(lbl1));
    } else if(node->is_typed(cdk::TYPE_DOUBLE) && node->initializer()->is_typed(cdk::TYPE_INT)){
      cdk::integer_node *init_node = dynamic_cast<cdk::integer_node*>(node->initializer());
      _pf.SDOUBLE(init_node->value());
    } else if(node->initializer()->is_typed(cdk::TYPE_DOUBLE)){
      cdk::double_node *init_node = dynamic_cast<cdk::double_node*>(node->initializer());
      _pf.SDOUBLE(init_node->value());
    } else if(node->initializer()->is_typed(cdk::TYPE_INT)){
      cdk::integer_node *init_node = dynamic_cast<cdk::integer_node*>(node->initializer());
      _pf.SINT(init_node->value());
    } else if(node->initializer()->is_typed(cdk::TYPE_POINTER)){
      _pf.INT(0);
    } else if(node->initializer()->is_typed(cdk::TYPE_FUNCTIONAL)){
      _pf.SADDR(_functionName);
    }
  }
}

void l22::postfix_writer::do_null_node(l22::null_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS; 
  // a pointer is a 32-bit integer
  if (_inFunctionBody) {
    _pf.INT(0);
  } else {
    _pf.INT(0);
  }
}
void l22::postfix_writer::do_function_call_node(l22::function_call_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  size_t args_size = 0;
  _inFunctionCall = true;

  std::shared_ptr<cdk::functional_type> ftype = cdk::functional_type::cast(node->pointer()->type());
  _inFunctionCallArgs = true;

  if(node->arguments()->size() > 0){
    for(int i = node->arguments()->size() -1; i >= 0; i--){
      cdk::expression_node *arg = dynamic_cast<cdk::expression_node*>(node->arguments()->node(i));
      arg->accept(this, lvl+2);

      if(ftype->input(i)->name() == cdk::TYPE_DOUBLE && arg->is_typed(cdk::TYPE_INT)) {
        _pf.I2D();
      }

      args_size += ftype->input(i)->size();
    }
  }

  
  _inFunctionCallArgs = false;

  std::shared_ptr<cdk::basic_type> returnType = ftype->output(0);

  if(node->pointer()){
    node->pointer()->accept(this, lvl+2);
  }

  _pf.BRANCH();
  if(args_size != 0){
    _pf.TRASH(args_size);
  }

  if(returnType->name() == cdk::TYPE_INT || returnType->name() == cdk::TYPE_POINTER || returnType->name() == cdk::TYPE_STRING || returnType->name() == cdk::TYPE_FUNCTIONAL){
    _pf.LDFVAL32();
  } else if(returnType->name() == cdk::TYPE_DOUBLE){
    _pf.LDFVAL64();
  }

  _inFunctionCall = false;
}

void l22::postfix_writer::do_function_definition_node(l22::function_definition_node * const node, int lvl) {

  _function = new_symbol();
  reset_new_symbol();

  _currentBodyRetLabel = mklbl(++_lbl);
  _offset = 8;
  _symtab.push();

  if(node->arguments()->size() > 0){
    _inFunctionArgs = true;
    for (size_t i = 0; i < node->arguments()->size(); i++){
      cdk::basic_node *arg = node->arguments()->node(i);
      if(arg == nullptr)
        break;
      arg->accept(this, 0);
    }
    _inFunctionArgs = false;
  }
  std::string lbl = mklbl(++_lbl);
  _functionName = lbl;
  _pf.TEXT(_functionName);
  _pf.ALIGN();
  if(!_inProgramBody)
    _pf.GLOBAL(lbl, _pf.FUNC());
  _pf.LABEL(lbl);

  frame_size_calculator lsc(_compiler, _symtab, _function);
  node->accept(&lsc, lvl);
  _pf.ENTER(lsc.localsize());

  _offset = 0; // prepare for local variable
  if(node->is_typed(cdk::TYPE_FUNCTIONAL))
  _currentFunctionType.push(node->type());

  _inFunctionBody = true;
  node->block()->accept(this, lvl + 4); // block has its own scope
  _currentFunctionType.pop();
  
  _pf.LABEL(_currentBodyRetLabel);
  _pf.LEAVE();
  _pf.RET();
  _inFunctionBody = false;

  _symtab.pop(); // scope of arguments

}

void l22::postfix_writer::do_stack_alloc_node(l22::stack_alloc_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
  _pf.INT(3);
  _pf.SHTL();
  _pf.ALLOC(); // allocate
  _pf.SP();// put base pointer in stack
}
void l22::postfix_writer::do_identity_node(l22::identity_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  _pf.INT(node->value()); // push an integer
}

void l22::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.SSTRING(node->value()); // output string characters

  /* leave the address on the stack */
  _pf.TEXT(_functionName); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  _pf.NEG(); // 2-complement
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->left()->type()->name() == cdk::TYPE_INT) {
    _pf.I2D();
  } else if (node->type()->name() == cdk::TYPE_POINTER && node->left()->type()->name() == cdk::TYPE_INT) {
    _pf.INT(3);
    _pf.SHTL();
  }

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_INT) {
    _pf.I2D();
  } else if (node->type()->name() == cdk::TYPE_POINTER && node->right()->type()->name() == cdk::TYPE_INT) {
    _pf.INT(3);
    _pf.SHTL();
  }

  if (node->type()->name() == cdk::TYPE_DOUBLE)
    _pf.DADD();
  else
    _pf.ADD();
}

void l22::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
    node->left()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->left()->type()->name() == cdk::TYPE_INT) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_INT) {
    _pf.I2D();
  } else if (node->type()->name() == cdk::TYPE_POINTER && node->right()->type()->name() == cdk::TYPE_INT) {
    _pf.INT(3);
    _pf.SHTL();
  }

  if (node->type()->name() == cdk::TYPE_DOUBLE)
    _pf.DSUB();
  else
    _pf.SUB();
}

void l22::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->left()->type()->name() == cdk::TYPE_INT) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_INT) _pf.I2D();

  if (node->type()->name() == cdk::TYPE_DOUBLE)
    _pf.DMUL();
  else
    _pf.MUL();
}

void l22::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->left()->type()->name() == cdk::TYPE_INT) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_INT) _pf.I2D();

  if (node->type()->name() == cdk::TYPE_DOUBLE)
    _pf.DDIV();
  else
    _pf.DIV();
}

void l22::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}

void l22::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.LT();
}

void l22::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.LE();
}

void l22::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.GE();
}

void l22::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.GT();
}

void l22::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.NE();
}

void l22::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.EQ();
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  const std::string &id = node->name();
  auto symbol = _symtab.find(id);
  if (symbol->global()) {
    _pf.ADDR(symbol->name());
  } else {
    _pf.LOCAL(symbol->offset());
  }
}

void l22::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  if (node->is_typed(cdk::TYPE_DOUBLE)){
    _pf.LDDOUBLE(); // depends on type size
  }
  else{
    _pf.LDINT(); // depends on type size
  }
}

void l22::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->rvalue()->accept(this, lvl); // determine the new value
  if (node->is_typed(cdk::TYPE_DOUBLE)) {
    if (node->rvalue()->is_typed(cdk::TYPE_INT))
      _pf.I2D();
    _pf.DUP64();
  } else 
    _pf.DUP32();
  
  node->lvalue()->accept(this, lvl);

  if (node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.STDOUBLE();
  } else {
    _pf.STINT();
  }

}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_program_node(l22::program_node * const node, int lvl) {
  
  _function = new_symbol();
  reset_new_symbol();

  frame_size_calculator lsc(_compiler, _symtab, _function);
  node->accept(&lsc, lvl);

  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();
  _pf.GLOBAL("_main", _pf.FUNC());
  _pf.LABEL("_main");
  _pf.ENTER(lsc.localsize());
  _inProgramBody = true;

  node->block()->accept(this, lvl);

  // end the main function
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  for (std::string s : _functions_to_declare)
      _pf.EXTERN(s);
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_evaluation_node(l22::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  node->argument()->accept(this, lvl); // determine the value
  size_t size = node->argument()->type()->size();
  if(size != 0)
    _pf.TRASH(node->argument()->type()->size());
}

void l22::postfix_writer::do_write_node(l22::write_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  for (size_t ix = 0; ix < node->argument()->size(); ix++) {
    auto child = dynamic_cast<cdk::expression_node*>(node->argument()->node(ix));
    
    std::shared_ptr<cdk::basic_type> etype = child->type();
    child->accept(this, lvl); // expression to print
    if (etype->name() == cdk::TYPE_INT) {
      _functions_to_declare.insert("printi");
      _pf.CALL("printi");
      _pf.TRASH(4); // trash int
    } else if (etype->name() == cdk::TYPE_DOUBLE) {
      _functions_to_declare.insert("printd");
      _pf.CALL("printd");
      _pf.TRASH(8); // trash double
    } else if (etype->name() == cdk::TYPE_STRING) {
      _functions_to_declare.insert("prints");
      _pf.CALL("prints");
      _pf.TRASH(4); // trash char pointer
    } else {
      std::cerr << "cannot print expression of unknown type" << std::endl;
      return;
    }

  }

  if (node->newLine()) {
    _functions_to_declare.insert("println");
    _pf.CALL("println");
  }
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_input_node(l22::input_node * const node, int lvl) {
  /*ASSERT_SAFE_EXPRESSIONS;
  _pf.CALL("readi");
  _pf.LDFVAL32();
  node->argument()->accept(this, lvl);
  _pf.STINT();*/
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_while_node(l22::while_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  _pf.LABEL(mklbl(lbl1 = ++_lbl));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl2 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl1));
  _pf.LABEL(mklbl(lbl2));
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_if_node(l22::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void l22::postfix_writer::do_if_else_node(l22::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}
