/*
    typespec.c -- Type specifier routines.
*/
/*
    Copyright (c) 1984, Taiichi Yuasa and Masami Hagiya.
    Copyright (c) 1990, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#include "ecl.h"

/******************************* EXPORTS ******************************/

cl_object TSnon_negative_integer;
cl_object TSpositive_number;

/**********************************************************************/

void
FEtype_error_character(cl_object x) {
	FEwrong_type_argument(@'character', x);
}

void
FEtype_error_cons(cl_object x) {
	FEwrong_type_argument(@'cons', x);
}

void
FEtype_error_number(cl_object x) {
	FEwrong_type_argument(@'number', x);
}

void
FEtype_error_real(cl_object x) {
	FEwrong_type_argument(@'real', x);
}

void
FEtype_error_float(cl_object x) {
	FEwrong_type_argument(@'float', x);
}

void
FEtype_error_integer(cl_object x) {
	FEwrong_type_argument(@'integer', x);
}

void
FEtype_error_list(cl_object x) {
	FEwrong_type_argument(@'list', x);
}

void
FEtype_error_proper_list(cl_object x) {
	FEcondition(9, @'simple-type-error', @':format-control',
		    make_simple_string("Not a proper list ~D"),
		    @':format-arguments', list(1, x),
		    @':expected-type', @'list',
		    @':datum', x);
}

void
FEtype_error_alist(cl_object x)
{
	FEcondition(9, @'simple-type-error', @':format-control',
		    make_simple_string("Not a valid association list ~D"),
		    @':format-arguments', list(1, x),
		    @':expected-type', @'list',
		    @':datum', x);
}

void
FEtype_error_plist(cl_object x)
{
	FEcondition(9, @'simple-type-error', @':format-control',
		    make_simple_string("Not a valid property list ~D"),
		    @':format-arguments', list(1, x),
		    @':expected-type', @'list',
		    @':datum', x);
}

void
FEcircular_list(cl_object x)
{
	/* FIXME: Is this the right way to rebind it? */
	bds_bind(@'*print-circle*', Ct);
	FEcondition(9, @'simple-type-error', @':format-control',
		    make_simple_string("Circular list ~D"),
		    @':format-arguments', list(1, x),
		    @':expected-type', @'list',
		    @':datum', x);
}

void
FEtype_error_index(cl_object x)
{
	FEcondition(9, @'simple-type-error', @':format-control',
		    make_simple_string("Index out of bounds ~D"),
		    @':format-arguments', list(1, x),
		    @':expected-type', @'fixnum',
		    @':datum', x);
}

void
FEtype_error_string(cl_object s)
{
	FEwrong_type_argument(@'string', s);
}

void
FEtype_error_stream(cl_object strm)
{
	FEwrong_type_argument(@'stream', strm);
}

/**********************************************************************/

void
assert_type_integer(cl_object p)
{
	cl_type t = type_of(p);
	if (t != t_fixnum && t != t_bignum)
		FEtype_error_integer(p);
}

void
assert_type_non_negative_integer(cl_object p)
{
	cl_type t = type_of(p);

	if (t == t_fixnum) {
		if (FIXNUM_PLUSP(p))
			return;
	} else if (t == t_bignum) {
		if (big_sign(p) >= 0)
			return;
	}
	FEwrong_type_argument(TSnon_negative_integer, p);
}

void
assert_type_character(cl_object p)
{
	if (!CHARACTERP(p))
		FEtype_error_character(p);
}

void
assert_type_symbol(cl_object p)
{
	if (!SYMBOLP(p))
		FEwrong_type_argument(@'symbol', p);
}

void
assert_type_package(cl_object p)
{
	if (type_of(p) != t_package)
		FEwrong_type_argument(@'package', p);
}

void
assert_type_string(cl_object p)
{
	if (type_of(p) != t_string)
		FEtype_error_string(p);
}

void
assert_type_cons(cl_object p)
{
	if (ATOM(p))
		FEwrong_type_argument(@'cons', p);
}

void
assert_type_list(cl_object p)
{
	if (ATOM(p) && p != Cnil)
		FEtype_error_list(p);
}

void
assert_type_proper_list(cl_object p)
{
	if (ATOM(p) && p != Cnil)
		FEtype_error_list(p);
	if (list_length(p) == Cnil)
		FEcircular_list(p);
}

void
assert_type_stream(cl_object p)
{
	if (type_of(p) != t_stream)
		FEwrong_type_argument(@'stream', p);
}

void
assert_type_readtable(cl_object p)
{
	if (type_of(p) != t_readtable)
		FEwrong_type_argument(@'readtable', p);
}

void
assert_type_hash_table(cl_object p)
{
	if (type_of(p) != t_hashtable)
		FEwrong_type_argument(@'hash-table', p);
}

void
assert_type_array(cl_object p)
{
	if (!ARRAYP(p))
		FEwrong_type_argument(@'array', p);
}

void
assert_type_vector(cl_object p)
{
	if (!VECTORP(p))
		FEwrong_type_argument(@'vector', p);
}

cl_object
TYPE_OF(cl_object x)
{
	switch (type_of(x)) {
#ifdef CLOS
        case t_instance:
		{ cl_object cl = CLASS_OF(x);
		  if (CLASS_NAME(cl) != Cnil)
		    return(CLASS_NAME(cl));
		  else
		    return(cl);
		}
#endif

	case t_fixnum:
		return(@'fixnum');

	case t_bignum:
		return(@'bignum');

	case t_ratio:
		return(@'ratio');

	case t_shortfloat:
		return(@'short-float');

	case t_longfloat:
		return(@'long-float');

	case t_complex:
		return(@'complex');

	case t_character: {
		int i = CHAR_CODE(x);
		if ((' ' <= i && i < '\177') || i == '\n')
			return(@'standard-char');
		else
			return(@'base-char');
	}

	case t_symbol:
		if (x == Cnil)
			return(@'null');
		if (x->symbol.hpack == keyword_package)
			return(@'keyword');
		else
			return(@'symbol');

	case t_package:
		return(@'package');

	case t_cons:
		return(@'cons');

	case t_hashtable:
		return(@'hash-table');

	case t_array:
		if (x->array.adjustable ||
		    Null(CAR(x->array.displaced)))
			return(@'array');
		else
			return(@'simple-array');

	case t_vector:
		if (x->vector.adjustable ||
		    x->vector.hasfillp ||
		    Null(CAR(x->vector.displaced)) ||
		    (cl_elttype)x->vector.elttype != aet_object)
			return(@'vector');
		else
			return(@'simple-vector');

	case t_string:
		if (x->string.adjustable ||
		    x->string.hasfillp ||
		    Null(CAR(x->string.displaced)))
			return(@'string');
		else
			return(@'simple-string');

	case t_bitvector:
		if (x->vector.adjustable ||
		    x->vector.hasfillp ||
		    Null(CAR(x->vector.displaced)))
			return(@'bit-vector');
		else
			return(@'simple-bit-vector');

#ifndef CLOS
	case t_structure:
		return(x->str.name);
#endif

	case t_stream:
		switch (x->stream.mode) {
		case smm_synonym:	return @'synonym-stream';
		case smm_broadcast:	return @'broadcast-stream';
		case smm_concatenated:	return @'concatenated-stream';
		case smm_two_way:	return @'two-way-stream';
		case smm_string_input:
		case smm_string_output:	return @'string-stream';
		case smm_echo:		return @'echo-stream';
		default:		return @'file-stream';
		}

	case t_readtable:
		return(@'readtable');

	case t_pathname:
		if (x->pathname.logical)
			return @'logical-pathname';
		return(@'pathname');

	case t_random:
		return(@'random-state');

	case t_bytecodes:
	case t_cfun:
	case t_cclosure:
		return(@'function');

#ifdef THREADS
	case t_cont:
		return(@'cont');

	case t_thread:
		return(@'thread');
#endif
#ifdef CLOS
	case t_gfun:
		return(@'dispatch-function');
#endif

	default:
		error("not a lisp data object");
	}
}

@(defun type_of (x)
@
	@(return TYPE_OF(x))
@)

void
init_typespec(void)
{

	TSnon_negative_integer = list(3, @'integer', MAKE_FIXNUM(0), @'*');
	register_root(&TSnon_negative_integer);
	TSpositive_number = list(2, @'satisfies', @'plusp');
	register_root(&TSpositive_number);
}				
