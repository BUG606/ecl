/*
    clos.c -- CLOS bootstrap.
*/
/*
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

cl_object class_class, class_object, class_built_in;

/******************************* ------- ******************************/

static cl_object
make_our_hash_table(cl_object test, int size)
{
	enum httest htt;
	int i;
	cl_object rehash_size, rehash_threshold, h;

	rehash_size = make_shortfloat(1.5);
	rehash_threshold = make_shortfloat(0.7);

	if (test == @'eq')
		htt = htt_eq;
	else if (test == @'eql')
		htt = htt_eql;
	else if (test == @'equal')
		htt = htt_equal;

	h = cl_alloc_object(t_hashtable);
	h->hash.data = NULL;	/* for GC sake */
	h->hash.test = (short)htt;
	h->hash.size = size;
	h->hash.rehash_size = rehash_size;
	h->hash.threshold = rehash_threshold;
        h->hash.entries = 0;
	h->hash.data = (struct hashtable_entry *)cl_alloc_align(size * sizeof(struct hashtable_entry), sizeof(int));
	for(i = 0;  i < size;  i++) {
		h->hash.data[i].key = OBJNULL;
		h->hash.data[i].value = OBJNULL;
	}
	return(h);
}

@(defun find-class (name &optional (errorp Ct) env)
	cl_object class;
@
	class = gethash_safe(name, SYM_VAL(@'si::*class-name-hash-table*'), Cnil);
	if (class == Cnil) {
		if (!Null(errorp))
			FEerror("No class named ~S.", 1, name);
	}
	@(return class)
@)	

static void
clos_boot(void)
{

	SYM_VAL(@'si::*class-name-hash-table*') = make_our_hash_table(@'eq', 1024);

	/* booting Class CLASS */
	
  	class_class = cl_alloc_instance(4);
	register_root(&class_class);
	CLASS_OF(class_class) = class_class;
	CLASS_NAME(class_class) = @'class';
	CLASS_SUPERIORS(class_class) = Cnil;
	CLASS_INFERIORS(class_class) = Cnil;
	CLASS_SLOTS(class_class) = OBJNULL;	/* filled later */

	sethash(@'class', SYM_VAL(@'si::*class-name-hash-table*'), class_class);

	/* booting Class BUILT-IN-CLASS */
	
  	class_built_in = cl_alloc_instance(4);
	register_root(&class_built_in);
	CLASS_OF(class_built_in) = class_class;
	CLASS_NAME(class_built_in) = @'built-in-class';
	CLASS_SUPERIORS(class_built_in) = CONS(class_class, Cnil);
	CLASS_INFERIORS(class_built_in) = Cnil;
	CLASS_SLOTS(class_built_in) = OBJNULL;	/* filled later */

	sethash(@'built-in-class', SYM_VAL(@'si::*class-name-hash-table*'), class_built_in);

	/* booting Class T (= OBJECT) */
	
  	class_object = cl_alloc_instance(4);
	register_root(&class_object);
	CLASS_OF(class_object) = class_built_in;
	CLASS_NAME(class_object) = Ct;
	CLASS_SUPERIORS(class_object) = Cnil;
	CLASS_INFERIORS(class_object) = CONS(class_class, Cnil);
	CLASS_SLOTS(class_object) = Cnil;

	sethash(Ct, SYM_VAL(@'si::*class-name-hash-table*'), class_object);

	/* complete now Class CLASS */
	CLASS_SUPERIORS(class_class) = CONS(class_object, Cnil);
	CLASS_INFERIORS(class_class) = CONS(class_built_in, Cnil);
}

void
init_clos(void)
{
	SYM_VAL(@'si::*class-name-hash-table*') = OBJNULL;

	clos_boot();
}
