#define CL_ORDINARY 1
#define CL_SPECIAL 2
#define SI_SPECIAL 3
#define SI_ORDINARY 4
#define KEYWORD 5

#ifdef DPP
#define SW(a,b,c) a
#else
#define SW(a,b,c) {a, b, c}
#endif

#define ECL_NUM_SYMBOLS_IN_CORE	393

const struct {
	const char *name;
#ifndef DPP
	int type;
	cl_object *loc;
#endif
} all_symbols[ECL_NUM_SYMBOLS_IN_CORE + 1] = {

SW("NIL", CL_ORDINARY, NULL),
SW("T", CL_ORDINARY, NULL),

/* LISP PACKAGE */
SW("&ALLOW-OTHER-KEYS", CL_ORDINARY, &clSAallow_other_keys),
SW("&AUX", CL_ORDINARY, &clSAaux),
SW("&KEY", CL_ORDINARY, &clSAkey),
SW("&OPTIONAL", CL_ORDINARY, &clSAoptional),
SW("&REST", CL_ORDINARY, &clSArest),
SW("*", CL_ORDINARY, &clV),
SW("*DEBUG-IO*", CL_SPECIAL, &clVdebug_io),
SW("*DEFAULT-PATHNAME-DEFAULTS*", CL_SPECIAL, &clVdefault_pathname_defaults),
SW("*ERROR-OUTPUT*", CL_SPECIAL, &clVerror_output),
SW("*FEATURES*", CL_SPECIAL, &clVfeatures),
SW("*GENSYM-COUNTER*", CL_SPECIAL, &clVgensym_counter),
SW("*LOAD-PRINT*", CL_SPECIAL, &clVload_print),
SW("*LOAD-VERBOSE*", CL_SPECIAL, &clVload_verbose),
SW("*MACROEXPAND-HOOK*", CL_SPECIAL, &clVmacroexpand_hook),
SW("*PACKAGE*", CL_SPECIAL, &clVpackage),
SW("*PRINT-ARRAY*", CL_SPECIAL, &clVprint_array),
SW("*PRINT-BASE*", CL_SPECIAL, &clVprint_base),
SW("*PRINT-CASE*", CL_SPECIAL, &clVprint_case),
SW("*PRINT-CIRCLE*", CL_SPECIAL, &clVprint_circle),
SW("*PRINT-ESCAPE*", CL_SPECIAL, &clVprint_escape),
SW("*PRINT-GENSYM*", CL_SPECIAL, &clVprint_gensym),
SW("*PRINT-LENGTH*", CL_SPECIAL, &clVprint_length),
SW("*PRINT-LEVEL*", CL_SPECIAL, &clVprint_level),
SW("*PRINT-PRETTY*", CL_SPECIAL, &clVprint_pretty),
SW("*PRINT-RADIX*", CL_SPECIAL, &clVprint_radix),
SW("*QUERY-IO*", CL_SPECIAL, &clVquery_io),
SW("*RANDOM-STATE*", CL_SPECIAL, &clVrandom_state),
SW("*READ-BASE*", CL_SPECIAL, &clVread_base),
SW("*READ-DEFAULT-FLOAT-FORMAT*", CL_SPECIAL, &clVread_default_float_format),
SW("*READ-SUPPRESS*", CL_SPECIAL, &clVread_suppress),
SW("*READTABLE*", CL_SPECIAL, &clVreadtable),
SW("*STANDARD-INPUT*", CL_SPECIAL, &clVstandard_input),
SW("*STANDARD-OUTPUT*", CL_SPECIAL, &clVstandard_output),
SW("*TERMINAL-IO*", CL_SPECIAL, &clVterminal_io),
SW("*TRACE-OUTPUT*", CL_SPECIAL, &clVtrace_output),
SW("AND", CL_ORDINARY, &clSand),
SW("APPEND", CL_ORDINARY, &clSappend),
SW("APPLY", CL_ORDINARY, &clSapply),
SW("ARITHMETIC-ERROR", CL_ORDINARY, &clSarithmetic_error),
SW("ARRAY", CL_ORDINARY, &clSarray),
SW("BASE-CHAR", CL_ORDINARY, &clSbase_char),
SW("BIGNUM", CL_ORDINARY, &clSbignum),
SW("BIT", CL_ORDINARY, &clSbit),
SW("BIT-VECTOR", CL_ORDINARY, &clSbit_vector),
SW("BLOCK", CL_ORDINARY, &clSblock),
SW("BROADCAST-STREAM", CL_ORDINARY, &clSbroadcast_stream),
SW("BUILT-IN-CLASS", CL_ORDINARY, &clSbuilt_in_class),
SW("BYTE8", CL_ORDINARY, &clSbyte8),
SW("CELL-ERROR", CL_ORDINARY, &clScell_error),
SW("CHARACTER", CL_ORDINARY, &clScharacter),
SW("CLASS", CL_ORDINARY, &clSclass),
SW("COMMON", CL_ORDINARY, &clScommon),
SW("COMPILE", CL_ORDINARY, &clScompile),
SW("COMPILED-FUNCTION", CL_ORDINARY, &clScompiled_function),
SW("COMPLEX", CL_ORDINARY, &clScomplex),
SW("CONCATENATED-STREAM", CL_ORDINARY, &clSconcatenated_stream),
SW("CONDITION", CL_ORDINARY, &clScondition),
SW("CONS", CL_ORDINARY, &clScons),
SW("DECLARE", CL_ORDINARY, &clSdeclare),
SW("DEFMACRO", CL_ORDINARY, NULL),
SW("DEFUN", CL_ORDINARY, NULL),
SW("DISPATCH-FUNCTION", CL_ORDINARY, &clSdispatch_function),
SW("DIVISION-BY-ZERO", CL_ORDINARY, &clSdivision_by_zero),
SW("DOUBLE-FLOAT", CL_ORDINARY, &clSdouble_float),
SW("ECHO-STREAM", CL_ORDINARY, &clSecho_stream),
SW("END-OF-FILE", CL_ORDINARY, &clSend_of_file),
SW("EQ", CL_ORDINARY, &clSeq),
SW("EQL", CL_ORDINARY, &clSeql),
SW("EQUAL", CL_ORDINARY, &clSequal),
SW("ERROR", CL_ORDINARY, &clSerror),
SW("EVAL", CL_ORDINARY, &clSeval),
SW("EXTENDED-CHAR", CL_ORDINARY, &clSextended_char),
SW("FILE-ERROR", CL_ORDINARY, &clSfile_error),
SW("FILE-STREAM", CL_ORDINARY, &clSfile_stream),
SW("FIXNUM", CL_ORDINARY, &clSfixnum),
SW("FLOAT", CL_ORDINARY, &clSfloat),
SW("FLOATING-POINT-INEXACT", CL_ORDINARY, &clSfloating_point_inexact),
SW("FLOATING-POINT-INVALID-OPERATION", CL_ORDINARY, &clSfloating_point_invalid_operation),
SW("FLOATING-POINT-OVERFLOW", CL_ORDINARY, &clSfloating_point_overflow),
SW("FLOATING-POINT-UNDERFLOW", CL_ORDINARY, &clSfloating_point_underflow),
SW("FUNCALL", CL_ORDINARY, &clSfuncall),
SW("FUNCTION", CL_ORDINARY, &clSfunction),
SW("HASH-TABLE", CL_ORDINARY, &clShash_table),
SW("INSTANCE", CL_ORDINARY, &clSinstance),
SW("INTEGER", CL_ORDINARY, &clSinteger),
SW("INTEGER8", CL_ORDINARY, &clSinteger8),
SW("KEYWORD", CL_ORDINARY, &clSkeyword),
SW("LAMBDA", CL_ORDINARY, &clSlambda),
SW("LAMBDA-BLOCK", CL_ORDINARY, &clSlambda_block),
SW("LIST", CL_ORDINARY, &clSlist),
SW("LIST*", CL_ORDINARY, &clSlistX),
SW("LOAD", CL_ORDINARY, &clSload),
SW("LOGICAL-PATHNAME", CL_ORDINARY, &clSlogical_pathname),
SW("LONG-FLOAT", CL_ORDINARY, &clSlong_float),
SW("MACRO", CL_ORDINARY, &clSmacro),
SW("MEMBER", CL_ORDINARY, &clSmember),
SW("MOD", CL_ORDINARY, &clSmod),
SW("NCONC", CL_ORDINARY, &clSnconc),
SW("NOT", CL_ORDINARY, &clSnot),
SW("NULL", CL_ORDINARY, &clSnull),
SW("NUMBER", CL_ORDINARY, &clSnumber),
SW("OR", CL_ORDINARY, &clSor),
SW("OTHERWISE", CL_ORDINARY, &clSotherwise),
SW("PACKAGE", CL_ORDINARY, &clSpackage),
SW("PACKAGE-ERROR", CL_ORDINARY, &clSpackage_error),
SW("PARSE-ERROR", CL_ORDINARY, &clSparse_error),
SW("PATHNAME", CL_ORDINARY, &clSpathname),
SW("PLUSP", CL_ORDINARY, &clSplusp),
SW("PRINT-NOT-READABLE", CL_ORDINARY, &clSprint_not_readable),
SW("PRINT-OBJECT", CL_ORDINARY, &clSprint_object),
SW("PROGN", CL_ORDINARY, &clSprogn),
SW("PROGRAM-ERROR", CL_ORDINARY, &clSprogram_error),
SW("PSETF", CL_ORDINARY, &clSpsetf),
SW("QUOTE", CL_ORDINARY, &clSquote),
SW("RANDOM-STATE", CL_ORDINARY, &clSrandom_state),
SW("RATIO", CL_ORDINARY, &clSratio),
SW("RATIONAL", CL_ORDINARY, &clSrational),
SW("READER-ERROR", CL_ORDINARY, &clSreader_error),
SW("READTABLE", CL_ORDINARY, &clSreadtable),
SW("REAL", CL_ORDINARY, &clSreal),
SW("SATISFIES", CL_ORDINARY, &clSsatisfies),
SW("SEQUENCE", CL_ORDINARY, &clSsequence),
SW("SERIOUS-CONDITION", CL_ORDINARY, &clSserious_condition),
SW("SETF", CL_ORDINARY, &clSsetf),
SW("SHORT-FLOAT", CL_ORDINARY, &clSshort_float),
SW("SIGNED-BYTE", CL_ORDINARY, &clSsigned_byte),
SW("SIGNED-CHAR", CL_ORDINARY, &clSsigned_char),
SW("SIGNED-SHORT", CL_ORDINARY, &clSsigned_short),
SW("SIMPLE-ARRAY", CL_ORDINARY, &clSsimple_array),
SW("SIMPLE-BIT-VECTOR", CL_ORDINARY, &clSsimple_bit_vector),
SW("SIMPLE-CONDITION", CL_ORDINARY, &clSsimple_condition),
SW("SIMPLE-ERROR", CL_ORDINARY, &clSsimple_error),
SW("SIMPLE-STRING", CL_ORDINARY, &clSsimple_string),
SW("SIMPLE-TYPE-ERROR", CL_ORDINARY, &clSsimple_type_error),
SW("SIMPLE-VECTOR", CL_ORDINARY, &clSsimple_vector),
SW("SIMPLE-WARNING", CL_ORDINARY, &clSsimple_warning),
SW("SINGLE-FLOAT", CL_ORDINARY, &clSsingle_float),
SW("SPECIAL", CL_ORDINARY, &clSspecial),
SW("STANDARD-CHAR", CL_ORDINARY, &clSstandard_char),
SW("STORAGE-CONDITION", CL_ORDINARY, &clSstorage_condition),
SW("STREAM", CL_ORDINARY, &clSstream),
SW("STREAM-ERROR", CL_ORDINARY, &clSstream_error),
SW("STRING", CL_ORDINARY, &clSstring),
SW("STRING-STREAM", CL_ORDINARY, &clSstring_stream),
SW("STRUCTURE", CL_ORDINARY, &clSstructure),
SW("STRUCTURE-OBJECT", CL_ORDINARY, &clSstructure_object),
SW("STYLE-WARNING", CL_ORDINARY, &clSstyle_warning),
SW("SUBTYPEP", CL_ORDINARY, &clSsubtypep),
SW("SYMBOL", CL_ORDINARY, &clSsymbol),
SW("SYNONYM-STREAM", CL_ORDINARY, &clSsynonym_stream),
SW("TAG", CL_ORDINARY, &clStag),
SW("TWO-WAY-STREAM", CL_ORDINARY, &clStwo_way_stream),
SW("TYPE-ERROR", CL_ORDINARY, &clStype_error),
SW("TYPEP", CL_ORDINARY, &clStypep),
SW("UNBOUND-SLOT", CL_ORDINARY, &clSunbound_slot),
SW("UNBOUND-VARIABLE", CL_ORDINARY, &clSunbound_variable),
SW("UNDEFINED-FUNCTION", CL_ORDINARY, &clSundefined_function),
SW("UNSIGNED-BYTE", CL_ORDINARY, &clSunsigned_byte),
SW("UNSIGNED-CHAR", CL_ORDINARY, &clSunsigned_char),
SW("UNSIGNED-SHORT", CL_ORDINARY, &clSunsigned_short),
SW("VALUES", CL_ORDINARY, &clSvalues),
SW("VECTOR", CL_ORDINARY, &clSvector),
SW("WARN", CL_ORDINARY, &clSwarn),
SW("WARNING", CL_ORDINARY, &clSwarning),

/* SYSTEM PACKAGE */
SW("SI::#!", SI_ORDINARY, &siSsharp_exclamation),
SW("SI::*CLASS-NAME-HASH-TABLE*", SI_SPECIAL, &siVclass_name_hash_table),
SW("SI::*GC-MESSAGE*", SI_SPECIAL, &siVgc_message),
SW("SI::*GC-VERBOSE*", SI_SPECIAL, &siVgc_verbose),
SW("SI::*IGNORE-EOF-ON-TERMINAL-IO*", SI_SPECIAL, &siVignore_eof_on_terminal_io),
SW("SI::*INDENT-FORMATTED-OUTPUT*", SI_SPECIAL, &siVindent_formatted_output),
SW("SI::*INHIBIT-MACRO-SPECIAL*", SI_SPECIAL, &siVinhibit_macro_special),
SW("SI::*INIT-FUNCTION-PREFIX*", SI_SPECIAL, &siVinit_function_prefix),
SW("SI::*KEEP-DEFINITIONS*", SI_SPECIAL, &siVkeep_definitions),
SW("SI::*LOAD-HOOKS*", SI_SPECIAL, &siVload_hooks),
SW("SI::*PRINT-PACKAGE*", SI_SPECIAL, &siVprint_package),
SW("SI::*PRINT-STRUCTURE*", SI_SPECIAL, &siVprint_structure),
SW("SI::,", SI_ORDINARY, &siScomma),
SW("SI::,.", SI_ORDINARY, &siScomma_dot),
SW("SI::,@", SI_ORDINARY, &siScomma_at),
SW("SI::CLEAR-COMPILER-PROPERTIES", SI_ORDINARY, &siSclear_compiler_properties),
SW("SI::COMPUTE-APPLICABLE-METHODS", SI_ORDINARY, &siScompute_applicable_methods),
SW("SI::COMPUTE-EFFECTIVE-METHOD", SI_ORDINARY, &siScompute_effective_method),
SW("SI::EXPAND-DEFMACRO", SI_ORDINARY, &siSexpand_defmacro),
SW("SI::GENERIC-FUNCTION-METHOD-COMBINATION", SI_ORDINARY, &siSgeneric_function_method_combination),
SW("SI::GENERIC-FUNCTION-METHOD-COMBINATION-ARGS", SI_ORDINARY, &siSgeneric_function_method_combination_args),
SW("SI::LINK-FROM", SI_ORDINARY, NULL),
SW("SI::LINK-TO", SI_ORDINARY, NULL),
SW("SI::PRETTY-PRINT-FORMAT", SI_ORDINARY, &siSpretty_print_format),
SW("SI::SETF-LAMBDA", SI_ORDINARY, &siSsetf_lambda),
SW("SI::SETF-METHOD", SI_ORDINARY, &siSsetf_method),
SW("SI::SETF-SYMBOL", SI_ORDINARY, &siSsetf_symbol),
SW("SI::SETF-UPDATE", SI_ORDINARY, &siSsetf_update),
SW("SI::SIMPLE-CONTROL-ERROR", SI_ORDINARY, &siSsimple_control_error),
SW("SI::SIMPLE-PROGRAM-ERROR", SI_ORDINARY, &siSsimple_program_error),
#ifndef CLOS
SW("SI::STRUCTURE-INCLUDE", SI_ORDINARY, &siSstructure_include),
#endif
SW("SI::STRUCTURE-PRINT-FUNCTION", SI_ORDINARY, &siSstructure_print_function),
SW("SI::STRUCTURE-SLOT-DESCRIPTIONS", SI_ORDINARY, &siSstructure_slot_descriptions),
SW("SI::SYMBOL-MACRO", SI_ORDINARY, &siSsymbol_macro),
SW("SI::TERMINAL-INTERRUPT", SI_ORDINARY, &siSterminal_interrupt),
SW("SI::UNIVERSAL-ERROR-HANDLER", SI_ORDINARY, &siSuniversal_error_handler),

#ifdef PROFILE
SW("SI::*PROFILE-ARRAY*", SI_SPECIAL, &sSAprofile_arrayA),
#endif

#ifdef ECL_CLOS_STREAMS
SW("STREAM-CLEAR-INPUT", CL_ORDINARY, &clSstream_clear_input),
SW("STREAM-CLEAR-OUTPUT", CL_ORDINARY, &clSstream_clear_output),
SW("STREAM-CLOSE", CL_ORDINARY, &clSstream_close),
SW("STREAM-FORCE-OUTPUT", CL_ORDINARY, &clSstream_force_output),
SW("STREAM-INPUT-P", CL_ORDINARY, &clSstream_input_p),
SW("STREAM-LISTEN", CL_ORDINARY, &clSstream_listen),
SW("STREAM-OUTPUT-P", CL_ORDINARY, &clSstream_output_p),
SW("STREAM-READ-CHAR", CL_ORDINARY, &clSstream_read_char),
SW("STREAM-UNREAD-CHAR", CL_ORDINARY, &clSstream_unread_char),
SW("STREAM-WRITE-CHAR", CL_ORDINARY, &clSstream_write_char),
#endif

#ifdef PDE
SW("SI::*RECORD-SOURCE-PATHNAME-P*", SI_SPECIAL, &siVrecord_source_pathname_p),
SW("SI::*SOURCE-PATHNAME*", SI_SPECIAL, &siVsource_pathname),
SW("SI::RECORD-SOURCE-PATHNAME", SI_ORDINARY, &siSrecord_source_pathname),
#endif

#ifdef THREADS
SW("CONT", CL_ORDINARY, &clScont),
SW("DEAD", CL_ORDINARY, &clSdead),
SW("RUNNING", CL_ORDINARY, &clSrunning),
SW("STOPPED", CL_ORDINARY, &clSstopped),
SW("SUSPENDED", CL_ORDINARY, &clSsuspended),
SW("THREAD", CL_ORDINARY, &clSthread),
SW("SI::THREAD-TOP-LEVEL", SI_ORDINARY, &siSthread_top_level),
SW("WAITING", CL_ORDINARY, &clSwaiting),
#endif

/* KEYWORD PACKAGE */
SW(":ABORT", KEYWORD, &Kabort),
SW(":ABSOLUTE", KEYWORD, &Kabsolute),
SW(":ALLOW-OTHER-KEYS", KEYWORD, &Kallow_other_keys),
SW(":APPEND", KEYWORD, &Kappend),
SW(":ARRAY", KEYWORD, &Karray),
SW(":BASE", KEYWORD, &Kbase),
SW(":BLOCK", KEYWORD, &Kblock),
SW(":CAPITALIZE", KEYWORD, &Kcapitalize),
SW(":CASE", KEYWORD, &Kcase),
SW(":CATCH", KEYWORD, &Kcatch),
SW(":CATCHALL", KEYWORD, &Kcatchall),
SW(":CIRCLE", KEYWORD, &Kcircle),
SW(":COMPILE-TOPLEVEL", KEYWORD, &Kcompile_toplevel),
SW(":CREATE", KEYWORD, &Kcreate),
SW(":DATUM", KEYWORD, &Kdatum),
SW(":DEFAULT", KEYWORD, &Kdefault),
SW(":DEFAULTS", KEYWORD, &Kdefaults),
SW(":DEVICE", KEYWORD, &Kdevice),
SW(":DIRECTION", KEYWORD, &Kdirection),
SW(":DIRECTORY", KEYWORD, &Kdirectory),
SW(":DOWNCASE", KEYWORD, &Kdowncase),
SW(":ELEMENT-TYPE", KEYWORD, &Kelement_type),
SW(":END", KEYWORD, &Kend),
SW(":END1", KEYWORD, &Kend1),
SW(":END2", KEYWORD, &Kend2),
SW(":ERROR", KEYWORD, &Kerror),
SW(":ESCAPE", KEYWORD, &Kescape),
SW(":EXECUTE", KEYWORD, &Kexecute),
SW(":EXPECTED-TYPE", KEYWORD, &Kexpected_type),
SW(":EXTERNAL", KEYWORD, &Kexternal),
SW(":FORMAT-ARGUMENTS", KEYWORD, &Kformat_arguments),
SW(":FORMAT-CONTROL", KEYWORD, &Kformat_control),
SW(":FUNCTION", KEYWORD, &Kfunction),
SW(":GENSYM", KEYWORD, &Kgensym),
SW(":HOST", KEYWORD, &Khost),
SW(":IF-DOES-NOT-EXIST", KEYWORD, &Kif_does_not_exist),
SW(":IF-EXISTS", KEYWORD, &Kif_exists),
SW(":INHERITED", KEYWORD, &Kinherited),
SW(":INITIAL-ELEMENT", KEYWORD, &Kinitial_element),
SW(":INPUT", KEYWORD, &Kinput),
SW(":INTERNAL", KEYWORD, &Kinternal),
SW(":IO", KEYWORD, &Kio),
SW(":JUNK-ALLOWED", KEYWORD, &Kjunk_allowed),
SW(":KEY", KEYWORD, &Kkey),
SW(":LENGTH", KEYWORD, &Klength),
SW(":LEVEL", KEYWORD, &Klevel),
SW(":LIST-ALL", KEYWORD, &Klist_all),
SW(":LOAD-TOPLEVEL", KEYWORD, &Kload_toplevel),
SW(":NAME", KEYWORD, &Kname),
SW(":NEW-VERSION", KEYWORD, &Knew_version),
SW(":NEWEST", KEYWORD, &Knewest),
SW(":NICKNAMES", KEYWORD, &Knicknames),
SW(":OUTPUT", KEYWORD, &Koutput),
SW(":OVERWRITE", KEYWORD, &Koverwrite),
SW(":PATHNAME", KEYWORD, &Kpathname),
SW(":PRETTY", KEYWORD, &Kpretty),
SW(":PRINT", KEYWORD, &Kprint),
SW(":PROBE", KEYWORD, &Kprobe),
SW(":PROTECT", KEYWORD, &Kprotect),
SW(":RADIX", KEYWORD, &Kradix),
SW(":REHASH-SIZE", KEYWORD, &Krehash_size),
SW(":REHASH-THRESHOLD", KEYWORD, &Krehash_threshold),
SW(":RELATIVE", KEYWORD, &Krelative),
SW(":RENAME", KEYWORD, &Krename),
SW(":RENAME-AND-DELETE", KEYWORD, &Krename_and_delete),
SW(":SET-DEFAULT-PATHNAME", KEYWORD, &Kset_default_pathname),
SW(":SIZE", KEYWORD, &Ksize),
SW(":START", KEYWORD, &Kstart),
SW(":START1", KEYWORD, &Kstart1),
SW(":START2", KEYWORD, &Kstart2),
SW(":STREAM", KEYWORD, &Kstream),
SW(":SUPERSEDE", KEYWORD, &Ksupersede),
SW(":TAG", KEYWORD, &Ktag),
SW(":TEST", KEYWORD, &Ktest),
SW(":TEST-NOT", KEYWORD, &Ktest_not),
SW(":TYPE", KEYWORD, &Ktype),
SW(":UNSPECIFIC", KEYWORD, &Kunspecific),
SW(":UP", KEYWORD, &Kup),
SW(":UPCASE", KEYWORD, &Kupcase),
SW(":USE", KEYWORD, &Kuse),
SW(":VERBOSE", KEYWORD, &Kverbose),
SW(":VERSION", KEYWORD, &Kversion),
SW(":WILD", KEYWORD, &Kwild),
SW(":WILD-INFERIORS", KEYWORD, &Kwild_inferiors),

/* Tag for end of list */
SW((const char*)NULL, CL_ORDINARY, NULL)};

