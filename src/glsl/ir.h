/* -*- c++ -*- */
/*
 * Copyright © 2010 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#pragma once
#ifndef IR_H
#define IR_H

#include <cstdio>
#include <cstdlib>

extern "C" {
#include <talloc.h>
}

#include "list.h"
#include "ir_visitor.h"
#include "ir_hierarchical_visitor.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#endif

struct ir_program {
   void *bong_hits;
};

/**
 * Base class of all IR instructions
 */
class ir_instruction : public exec_node {
public:
   const struct glsl_type *type;

   class ir_constant *constant_expression_value();

   /** ir_print_visitor helper for debugging. */
   void print(void) const;

   virtual void accept(ir_visitor *) = 0;
   virtual ir_visitor_status accept(ir_hierarchical_visitor *) = 0;
   virtual ir_instruction *clone(struct hash_table *ht) const = 0;

   /**
    * \name IR instruction downcast functions
    *
    * These functions either cast the object to a derived class or return
    * \c NULL if the object's type does not match the specified derived class.
    * Additional downcast functions will be added as needed.
    */
   /*@{*/
   virtual class ir_variable *          as_variable()         { return NULL; }
   virtual class ir_function *          as_function()         { return NULL; }
   virtual class ir_dereference *       as_dereference()      { return NULL; }
   virtual class ir_dereference_array *	as_dereference_array() { return NULL; }
   virtual class ir_dereference_variable *as_dereference_variable() { return NULL; }
   virtual class ir_rvalue *            as_rvalue()           { return NULL; }
   virtual class ir_loop *              as_loop()             { return NULL; }
   virtual class ir_assignment *        as_assignment()       { return NULL; }
   virtual class ir_call *              as_call()             { return NULL; }
   virtual class ir_return *            as_return()           { return NULL; }
   virtual class ir_if *                as_if()               { return NULL; }
   virtual class ir_swizzle *           as_swizzle()          { return NULL; }
   virtual class ir_constant *          as_constant()         { return NULL; }
   /*@}*/

protected:
   ir_instruction()
   {
      /* empty */
   }
};


class ir_rvalue : public ir_instruction {
public:
   virtual ir_rvalue * as_rvalue()
   {
      return this;
   }

   virtual bool is_lvalue()
   {
      return false;
   }

   /**
    * Get the variable that is ultimately referenced by an r-value
    */
   virtual ir_variable *variable_referenced()
   {
      return NULL;
   }


   /**
    * If an r-value is a reference to a whole variable, get that variable
    *
    * \return
    * Pointer to a variable that is completely dereferenced by the r-value.  If
    * the r-value is not a dereference or the dereference does not access the
    * entire variable (i.e., it's just one array element, struct field), \c NULL
    * is returned.
    */
   virtual ir_variable *whole_variable_referenced()
   {
      return NULL;
   }

protected:
   ir_rvalue()
   {
      /* empty */
   }
};


enum ir_variable_mode {
   ir_var_auto = 0,
   ir_var_uniform,
   ir_var_in,
   ir_var_out,
   ir_var_inout
};

enum ir_variable_interpolation {
   ir_var_smooth = 0,
   ir_var_flat,
   ir_var_noperspective
};


class ir_variable : public ir_instruction {
public:
   ir_variable(const struct glsl_type *, const char *);

   virtual ir_instruction *clone(struct hash_table *ht) const;

   virtual ir_variable *as_variable()
   {
      return this;
   }

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);


   /**
    * Get the string value for the interpolation qualifier
    *
    * \return
    * If none of \c shader_in or \c shader_out is set, an empty string will
    * be returned.  Otherwise the string that would be used in a shader to
    * specify \c mode will be returned.
    */
   const char *interpolation_string() const;

   /**
    * Calculate the number of slots required to hold this variable
    *
    * This is used to determine how many uniform or varying locations a variable
    * occupies.  The count is in units of floating point components.
    */
   unsigned component_slots() const;

   const char *name;

   /**
    * Highest element accessed with a constant expression array index
    *
    * Not used for non-array variables.
    */
   unsigned max_array_access;

   unsigned read_only:1;
   unsigned centroid:1;
   unsigned invariant:1;
   /** If the variable is initialized outside of the scope of the shader */
   unsigned shader_in:1;
   /**
    * If the variable value is later used outside of the scope of the shader.
    */
   unsigned shader_out:1;

   unsigned mode:3;
   unsigned interpolation:2;

   /**
    * Flag that the whole array is assignable
    *
    * In GLSL 1.20 and later whole arrays are assignable (and comparable for
    * equality).  This flag enables this behavior.
    */
   unsigned array_lvalue:1;

   /**
    * Storage location of the base of this variable
    *
    * The precise meaning of this field depends on the nature of the variable.
    *
    *   - Vertex shader input: one of the values from \c gl_vert_attrib.
    *   - Vertex shader output: one of the values from \c gl_vert_result.
    *   - Fragment shader input: one of the values from \c gl_frag_attrib.
    *   - Fragment shader output: one of the values from \c gl_frag_result.
    *   - Uniforms: Per-stage uniform slot number.
    *   - Other: This field is not currently used.
    *
    * If the variable is a uniform, shader input, or shader output, and the
    * slot has not been assigned, the value will be -1.
    */
   int location;

   /**
    * Emit a warning if this variable is accessed.
    */
   const char *warn_extension;

   /**
    * Value assigned in the initializer of a variable declared "const"
    */
   ir_constant *constant_value;
};


/*@{*/
/**
 * The representation of a function instance; may be the full definition or
 * simply a prototype.
 */
class ir_function_signature : public ir_instruction {
   /* An ir_function_signature will be part of the list of signatures in
    * an ir_function.
    */
public:
   ir_function_signature(const glsl_type *return_type);

   virtual ir_instruction *clone(struct hash_table *ht) const;

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   /**
    * Get the name of the function for which this is a signature
    */
   const char *function_name() const;

   /**
    * Check whether the qualifiers match between this signature's parameters
    * and the supplied parameter list.  If not, returns the name of the first
    * parameter with mismatched qualifiers (for use in error messages).
    */
   const char *qualifiers_match(exec_list *params);

   /**
    * Replace the current parameter list with the given one.  This is useful
    * if the current information came from a prototype, and either has invalid
    * or missing parameter names.
    */
   void replace_parameters(exec_list *new_params);

   /**
    * Function return type.
    *
    * \note This discards the optional precision qualifier.
    */
   const struct glsl_type *return_type;

   /**
    * List of ir_variable of function parameters.
    *
    * This represents the storage.  The paramaters passed in a particular
    * call will be in ir_call::actual_paramaters.
    */
   struct exec_list parameters;

   /** Whether or not this function has a body (which may be empty). */
   unsigned is_defined:1;

   /** Body of instructions in the function. */
   struct exec_list body;

private:
   /** Function of which this signature is one overload. */
   class ir_function *function;

   friend class ir_function;
};


/**
 * Header for tracking multiple overloaded functions with the same name.
 * Contains a list of ir_function_signatures representing each of the
 * actual functions.
 */
class ir_function : public ir_instruction {
public:
   ir_function(const char *name);

   virtual ir_instruction *clone(struct hash_table *ht) const;

   virtual ir_function *as_function()
   {
      return this;
   }

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   void add_signature(ir_function_signature *sig)
   {
      sig->function = this;
      signatures.push_tail(sig);
   }

   /**
    * Get an iterator for the set of function signatures
    */
   exec_list_iterator iterator()
   {
      return signatures.iterator();
   }

   /**
    * Find a signature that matches a set of actual parameters, taking implicit
    * conversions into account.
    */
   const ir_function_signature *matching_signature(exec_list *actual_param);

   /**
    * Find a signature that exactly matches a set of actual parameters without
    * any implicit type conversions.
    */
   ir_function_signature *exact_matching_signature(exec_list *actual_ps);

   /**
    * Name of the function.
    */
   const char *name;

private:
   /**
    * List of ir_function_signature for each overloaded function with this name.
    */
   struct exec_list signatures;
};

inline const char *ir_function_signature::function_name() const
{
   return function->name;
}
/*@}*/


/**
 * IR instruction representing high-level if-statements
 */
class ir_if : public ir_instruction {
public:
   ir_if(ir_rvalue *condition)
      : condition(condition)
   {
      /* empty */
   }

   virtual ir_instruction *clone(struct hash_table *ht) const;

   virtual ir_if *as_if()
   {
      return this;
   }

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   ir_rvalue *condition;
   /** List of ir_instruction for the body of the then branch */
   exec_list  then_instructions;
   /** List of ir_instruction for the body of the else branch */
   exec_list  else_instructions;
};


/**
 * IR instruction representing a high-level loop structure.
 */
class ir_loop : public ir_instruction {
public:
   ir_loop() : from(NULL), to(NULL), increment(NULL), counter(NULL)
   {
      /* empty */
   }

   virtual ir_instruction *clone(struct hash_table *ht) const;

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   virtual ir_loop *as_loop()
   {
      return this;
   }

   /**
    * Get an iterator for the instructions of the loop body
    */
   exec_list_iterator iterator()
   {
      return body_instructions.iterator();
   }

   /** List of ir_instruction that make up the body of the loop. */
   exec_list body_instructions;

   /**
    * \name Loop counter and controls
    */
   /*@{*/
   ir_rvalue *from;
   ir_rvalue *to;
   ir_rvalue *increment;
   ir_variable *counter;
   /*@}*/
};


class ir_assignment : public ir_rvalue {
public:
   ir_assignment(ir_rvalue *lhs, ir_rvalue *rhs, ir_rvalue *condition);

   virtual ir_instruction *clone(struct hash_table *ht) const;

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   virtual ir_assignment * as_assignment()
   {
      return this;
   }

   /**
    * Left-hand side of the assignment.
    */
   ir_rvalue *lhs;

   /**
    * Value being assigned
    */
   ir_rvalue *rhs;

   /**
    * Optional condition for the assignment.
    */
   ir_rvalue *condition;
};

/* Update ir_expression::num_operands() and operator_strs when
 * updating this list.
 */
enum ir_expression_operation {
   ir_unop_bit_not,
   ir_unop_logic_not,
   ir_unop_neg,
   ir_unop_abs,
   ir_unop_sign,
   ir_unop_rcp,
   ir_unop_rsq,
   ir_unop_sqrt,
   ir_unop_exp,
   ir_unop_log,
   ir_unop_exp2,
   ir_unop_log2,
   ir_unop_f2i,      /**< Float-to-integer conversion. */
   ir_unop_i2f,      /**< Integer-to-float conversion. */
   ir_unop_f2b,      /**< Float-to-boolean conversion */
   ir_unop_b2f,      /**< Boolean-to-float conversion */
   ir_unop_i2b,      /**< int-to-boolean conversion */
   ir_unop_b2i,      /**< Boolean-to-int conversion */
   ir_unop_u2f,      /**< Unsigned-to-float conversion. */

   /**
    * \name Unary floating-point rounding operations.
    */
   /*@{*/
   ir_unop_trunc,
   ir_unop_ceil,
   ir_unop_floor,
   ir_unop_fract,
   /*@}*/

   /**
    * \name Trigonometric operations.
    */
   /*@{*/
   ir_unop_sin,
   ir_unop_cos,
   /*@}*/

   /**
    * \name Partial derivatives.
    */
   /*@{*/
   ir_unop_dFdx,
   ir_unop_dFdy,
   /*@}*/

   ir_binop_add,
   ir_binop_sub,
   ir_binop_mul,
   ir_binop_div,

   /**
    * Takes one of two combinations of arguments:
    *
    * - mod(vecN, vecN)
    * - mod(vecN, float)
    *
    * Does not take integer types.
    */
   ir_binop_mod,

   /**
    * \name Binary comparison operators
    */
   /*@{*/
   ir_binop_less,
   ir_binop_greater,
   ir_binop_lequal,
   ir_binop_gequal,
   ir_binop_equal,
   ir_binop_nequal,
   /*@}*/

   /**
    * \name Bit-wise binary operations.
    */
   /*@{*/
   ir_binop_lshift,
   ir_binop_rshift,
   ir_binop_bit_and,
   ir_binop_bit_xor,
   ir_binop_bit_or,
   /*@}*/

   ir_binop_logic_and,
   ir_binop_logic_xor,
   ir_binop_logic_or,

   ir_binop_dot,
   ir_binop_min,
   ir_binop_max,

   ir_binop_pow
};

class ir_expression : public ir_rvalue {
public:
   ir_expression(int op, const struct glsl_type *type,
		 ir_rvalue *, ir_rvalue *);

   virtual ir_instruction *clone(struct hash_table *ht) const;

   static unsigned int get_num_operands(ir_expression_operation);
   unsigned int get_num_operands() const
   {
      return get_num_operands(operation);
   }

   /**
    * Return a string representing this expression's operator.
    */
   const char *operator_string();

   /**
    * Do a reverse-lookup to translate the given string into an operator.
    */
   static ir_expression_operation get_operator(const char *);

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   ir_expression_operation operation;
   ir_rvalue *operands[2];
};


/**
 * IR instruction representing a function call
 */
class ir_call : public ir_rvalue {
public:
   ir_call(const ir_function_signature *callee, exec_list *actual_parameters)
      : callee(callee)
   {
      assert(callee->return_type != NULL);
      type = callee->return_type;
      actual_parameters->move_nodes_to(& this->actual_parameters);
   }

   virtual ir_instruction *clone(struct hash_table *ht) const;

   virtual ir_call *as_call()
   {
      return this;
   }

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   /**
    * Get a generic ir_call object when an error occurs
    *
    * Any allocation will be performed with 'ctx' as talloc owner.
    */
   static ir_call *get_error_instruction(void *ctx);

   /**
    * Get an iterator for the set of acutal parameters
    */
   exec_list_iterator iterator()
   {
      return actual_parameters.iterator();
   }

   /**
    * Get the name of the function being called.
    */
   const char *callee_name() const
   {
      return callee->function_name();
   }

   const ir_function_signature *get_callee()
   {
      return callee;
   }

   /**
    * Generates an inline version of the function before @ir,
    * returning the return value of the function.
    */
   ir_rvalue *generate_inline(ir_instruction *ir);

private:
   ir_call()
      : callee(NULL)
   {
      /* empty */
   }

   const ir_function_signature *callee;

   /* List of ir_rvalue of paramaters passed in this call. */
   exec_list actual_parameters;
};


/**
 * \name Jump-like IR instructions.
 *
 * These include \c break, \c continue, \c return, and \c discard.
 */
/*@{*/
class ir_jump : public ir_instruction {
protected:
   ir_jump()
   {
      /* empty */
   }
};

class ir_return : public ir_jump {
public:
   ir_return()
      : value(NULL)
   {
      /* empty */
   }

   ir_return(ir_rvalue *value)
      : value(value)
   {
      /* empty */
   }

   virtual ir_instruction *clone(struct hash_table *) const;

   virtual ir_return *as_return()
   {
      return this;
   }

   ir_rvalue *get_value() const
   {
      return value;
   }

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   ir_rvalue *value;
};


/**
 * Jump instructions used inside loops
 *
 * These include \c break and \c continue.  The \c break within a loop is
 * different from the \c break within a switch-statement.
 *
 * \sa ir_switch_jump
 */
class ir_loop_jump : public ir_jump {
public:
   enum jump_mode {
      jump_break,
      jump_continue
   };

   ir_loop_jump(jump_mode mode)
   {
      this->mode = mode;
      this->loop = loop;
   }

   virtual ir_instruction *clone(struct hash_table *) const;

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   bool is_break() const
   {
      return mode == jump_break;
   }

   bool is_continue() const
   {
      return mode == jump_continue;
   }

   /** Mode selector for the jump instruction. */
   enum jump_mode mode;
private:
   /** Loop containing this break instruction. */
   ir_loop *loop;
};

/**
 * IR instruction representing discard statements.
 */
class ir_discard : public ir_jump {
public:
   ir_discard()
   {
      this->condition = NULL;
   }

   ir_discard(ir_rvalue *cond)
   {
      this->condition = cond;
   }

   virtual ir_instruction *clone(struct hash_table *ht) const;

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   ir_rvalue *condition;
};
/*@}*/


/**
 * Texture sampling opcodes used in ir_texture
 */
enum ir_texture_opcode {
   ir_tex,		/* Regular texture look-up */
   ir_txb,		/* Texture look-up with LOD bias */
   ir_txl,		/* Texture look-up with explicit LOD */
   ir_txd,		/* Texture look-up with partial derivatvies */
   ir_txf		/* Texel fetch with explicit LOD */
};


/**
 * IR instruction to sample a texture
 *
 * The specific form of the IR instruction depends on the \c mode value
 * selected from \c ir_texture_opcodes.  In the printed IR, these will
 * appear as:
 *
 *                              Texel offset
 *                              |       Projection divisor
 *                              |       |   Shadow comparitor
 *                              |       |   |
 *                              v       v   v
 * (tex (sampler) (coordinate) (0 0 0) (1) ( ))
 * (txb (sampler) (coordinate) (0 0 0) (1) ( ) (bias))
 * (txl (sampler) (coordinate) (0 0 0) (1) ( ) (lod))
 * (txd (sampler) (coordinate) (0 0 0) (1) ( ) (dPdx dPdy))
 * (txf (sampler) (coordinate) (0 0 0)         (lod))
 */
class ir_texture : public ir_rvalue {
public:
   ir_texture(enum ir_texture_opcode op)
      : op(op), projector(NULL), shadow_comparitor(NULL)
   {
      /* empty */
   }

   virtual ir_instruction *clone(struct hash_table *) const;

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   /**
    * Return a string representing the ir_texture_opcode.
    */
   const char *opcode_string();

   /** Set the sampler and infer the type. */
   void set_sampler(ir_dereference *sampler);

   /**
    * Do a reverse-lookup to translate a string into an ir_texture_opcode.
    */
   static ir_texture_opcode get_opcode(const char *);

   enum ir_texture_opcode op;

   /** Sampler to use for the texture access. */
   ir_dereference *sampler;

   /** Texture coordinate to sample */
   ir_rvalue *coordinate;

   /**
    * Value used for projective divide.
    *
    * If there is no projective divide (the common case), this will be
    * \c NULL.  Optimization passes should check for this to point to a constant
    * of 1.0 and replace that with \c NULL.
    */
   ir_rvalue *projector;

   /**
    * Coordinate used for comparison on shadow look-ups.
    *
    * If there is no shadow comparison, this will be \c NULL.  For the
    * \c ir_txf opcode, this *must* be \c NULL.
    */
   ir_rvalue *shadow_comparitor;

   /** Explicit texel offsets. */
   signed char offsets[3];

   union {
      ir_rvalue *lod;		/**< Floating point LOD */
      ir_rvalue *bias;		/**< Floating point LOD bias */
      struct {
	 ir_rvalue *dPdx;	/**< Partial derivative of coordinate wrt X */
	 ir_rvalue *dPdy;	/**< Partial derivative of coordinate wrt Y */
      } grad;
   } lod_info;
};


struct ir_swizzle_mask {
   unsigned x:2;
   unsigned y:2;
   unsigned z:2;
   unsigned w:2;

   /**
    * Number of components in the swizzle.
    */
   unsigned num_components:3;

   /**
    * Does the swizzle contain duplicate components?
    *
    * L-value swizzles cannot contain duplicate components.
    */
   unsigned has_duplicates:1;
};


class ir_swizzle : public ir_rvalue {
public:
   ir_swizzle(ir_rvalue *, unsigned x, unsigned y, unsigned z, unsigned w,
              unsigned count);

   ir_swizzle(ir_rvalue *val, const unsigned *components, unsigned count);

   ir_swizzle(ir_rvalue *val, ir_swizzle_mask mask);

   virtual ir_instruction *clone(struct hash_table *) const;

   virtual ir_swizzle *as_swizzle()
   {
      return this;
   }

   /**
    * Construct an ir_swizzle from the textual representation.  Can fail.
    */
   static ir_swizzle *create(ir_rvalue *, const char *, unsigned vector_length);

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   bool is_lvalue()
   {
      return val->is_lvalue() && !mask.has_duplicates;
   }

   /**
    * Get the variable that is ultimately referenced by an r-value
    */
   virtual ir_variable *variable_referenced();

   ir_rvalue *val;
   ir_swizzle_mask mask;

private:
   /**
    * Initialize the mask component of a swizzle
    *
    * This is used by the \c ir_swizzle constructors.
    */
   void init_mask(const unsigned *components, unsigned count);
};


class ir_dereference : public ir_rvalue {
public:
   virtual ir_dereference *as_dereference()
   {
      return this;
   }

   bool is_lvalue();

   /**
    * Get the variable that is ultimately referenced by an r-value
    */
   virtual ir_variable *variable_referenced() = 0;
};


class ir_dereference_variable : public ir_dereference {
public:
   ir_dereference_variable(ir_variable *var);

   virtual ir_instruction *clone(struct hash_table *) const;

   virtual ir_dereference_variable *as_dereference_variable()
   {
      return this;
   }

   /**
    * Get the variable that is ultimately referenced by an r-value
    */
   virtual ir_variable *variable_referenced()
   {
      return this->var;
   }

   virtual ir_variable *whole_variable_referenced()
   {
      /* ir_dereference_variable objects always dereference the entire
       * variable.  However, if this dereference is dereferenced by anything
       * else, the complete deferefernce chain is not a whole-variable
       * dereference.  This method should only be called on the top most
       * ir_rvalue in a dereference chain.
       */
      return this->var;
   }

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   /**
    * Object being dereferenced.
    */
   ir_variable *var;
};


class ir_dereference_array : public ir_dereference {
public:
   ir_dereference_array(ir_rvalue *value, ir_rvalue *array_index);

   ir_dereference_array(ir_variable *var, ir_rvalue *array_index);

   virtual ir_instruction *clone(struct hash_table *) const;

   virtual ir_dereference_array *as_dereference_array()
   {
      return this;
   }

   /**
    * Get the variable that is ultimately referenced by an r-value
    */
   virtual ir_variable *variable_referenced()
   {
      return this->array->variable_referenced();
   }

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   ir_rvalue *array;
   ir_rvalue *array_index;

private:
   void set_array(ir_rvalue *value);
};


class ir_dereference_record : public ir_dereference {
public:
   ir_dereference_record(ir_rvalue *value, const char *field);

   ir_dereference_record(ir_variable *var, const char *field);

   virtual ir_instruction *clone(struct hash_table *) const;

   /**
    * Get the variable that is ultimately referenced by an r-value
    */
   virtual ir_variable *variable_referenced()
   {
      return this->record->variable_referenced();
   }

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   ir_rvalue *record;
   const char *field;
};


/**
 * Data stored in an ir_constant
 */
union ir_constant_data {
      unsigned u[16];
      int i[16];
      float f[16];
      bool b[16];
};


class ir_constant : public ir_rvalue {
public:
   ir_constant(const struct glsl_type *type, const ir_constant_data *data);
   ir_constant(bool b);
   ir_constant(unsigned int u);
   ir_constant(int i);
   ir_constant(float f);

   /**
    * Construct an ir_constant from a list of ir_constant values
    */
   ir_constant(const struct glsl_type *type, exec_list *values);

   /**
    * Construct an ir_constant from a scalar component of another ir_constant
    *
    * The new \c ir_constant inherits the type of the component from the
    * source constant.
    *
    * \note
    * In the case of a matrix constant, the new constant is a scalar, \b not
    * a vector.
    */
   ir_constant(const ir_constant *c, unsigned i);

   virtual ir_instruction *clone(struct hash_table *) const;

   virtual ir_constant *as_constant()
   {
      return this;
   }

   virtual void accept(ir_visitor *v)
   {
      v->visit(this);
   }

   virtual ir_visitor_status accept(ir_hierarchical_visitor *);

   /**
    * Get a particular component of a constant as a specific type
    *
    * This is useful, for example, to get a value from an integer constant
    * as a float or bool.  This appears frequently when constructors are
    * called with all constant parameters.
    */
   /*@{*/
   bool get_bool_component(unsigned i) const;
   float get_float_component(unsigned i) const;
   int get_int_component(unsigned i) const;
   unsigned get_uint_component(unsigned i) const;
   /*@}*/

   ir_constant *get_record_field(const char *name);

   /**
    * Determine whether a constant has the same value as another constant
    */
   bool has_value(const ir_constant *) const;

   /**
    * Value of the constant.
    *
    * The field used to back the values supplied by the constant is determined
    * by the type associated with the \c ir_instruction.  Constants may be
    * scalars, vectors, or matrices.
    */
   union ir_constant_data value;

   exec_list components;

private:
   /**
    * Parameterless constructor only used by the clone method
    */
   ir_constant(void);
};

void
visit_exec_list(exec_list *list, ir_visitor *visitor);

void validate_ir_tree(exec_list *instructions);

extern void
_mesa_glsl_initialize_variables(exec_list *instructions,
				struct _mesa_glsl_parse_state *state);

extern void
_mesa_glsl_initialize_functions(exec_list *instructions,
				struct _mesa_glsl_parse_state *state);

#endif /* IR_H */