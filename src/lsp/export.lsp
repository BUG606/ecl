;;;;  Copyright (c) 1984, Taiichi Yuasa and Masami Hagiya.
;;;;  Copyright (c) 1990, Giuseppe Attardi.
;;;;
;;;;    This program is free software; you can redistribute it and/or
;;;;    modify it under the terms of the GNU Library General Public
;;;;    License as published by the Free Software Foundation; either
;;;;    version 2 of the License, or (at your option) any later version.
;;;;
;;;;    See file '../Copyright' for full details.
;;;;                    Exporting external symbols of LISP package

(si::select-package "CL")

; Safety measure
(setq *print-circle* t)

(export '(
	  &whole
	  &environment
	  &body
	  *
	  **
	  ***
	  *features*
	  *modules*
	  +
	  ++
	  +++
	  -
	  /
	  //
	  ///
	  COMMON
	  KYOTO
	  KCL
	  ECL
	  ECL
	  abs
	  acos
	  acosh
	  adjust-array
	  adjustable-array-p
	  apropos
	  apropos-list
	  array-dimension
	  array-dimensions
	  array-element-type
	  array-has-fill-pointer-p
	  array-in-bounds-p
	  array-rank
	  array-row-major-index
	  asin
	  asinh
	  assert
	  atanh
	  base-string
	  bit
	  bit-and
	  bit-andc1
	  bit-andc2
	  bit-eqv
	  bit-ior
	  bit-nand
	  bit-nor
	  bit-not
	  bit-orc1
	  bit-orc2
	  bit-xor
	  boolean
	  break
	  byte
	  byte-position
	  byte-size
	  ccase
	  cerror
	  char
	  check-type
	  cis
	  coerce
	  compile
	  compile-file
	  compile-file-pathname
	  complement
	  common-lisp
	  common-lisp-user
	  constantly
	  cl
	  cl-user
	  *compile-print*
	  *compile-verbose*
	  concatenate
	  cosh
	  count
	  count-if
	  count-if-not
	  ctypecase
	  decf
	  declaim
	  declaration
	  decode-universal-time
	  defconstant
	  define-modify-macro
	  define-setf-expander
	  define-symbol-macro
	  defmacro
	  defpackage
	  defparameter
	  defsetf
	  defstruct
	  deftype
	  defun
	  defvar
	  delete
	  delete-duplicates
	  delete-if
	  delete-if-not
	  delete-package
	  deposit-field
	  describe
	  destructuring-bind
	  disassemble
	  do*
	  do-all-symbols
	  do-external-symbols
	  do-symbols
	  documentation
	  dolist
	  dotimes
	  dpb
	  dribble
	  ecase
	  ed
	  eighth
	  encode-universal-time
	  error
	  etypecase
	  eval-when
	  every
	  fceiling
	  ffloor
	  fifth
	  fill
	  fill-pointer
	  find
	  find-all-symbols
	  find-if
	  find-if-not
	  first
	  float
	  format
	  fourth
	  fround
	  ftruncate
	  get-decoded-time
	  get-setf-expansion
	  get-universal-time
	  getf
	  ignore
	  in-package
	  incf
	  inspect
	  intersection
	  isqrt
	  ldb
	  ldb-test
	  lisp-implementation-type
	  load-time-value
	  locally
	  logandc1
	  logandc2
	  logical-pathname-translations
	  lognand
	  lognor
	  lognot
	  logorc1
	  logorc2
	  logtest
	  long-site-name
	  loop
	  loop-finish
	  machine-instance
	  machine-type
	  machine-version
	  make-array
	  make-sequence
	  map
	  map-into
	  mask-field
	  merge
	  mismatch
	  mod
	  multiple-value-setq
	  nil
	  nintersection
	  ninth
	  notany
	  notevery
	  nset-difference
	  nset-exclusive-or
	  nsubstitute
	  nsubstitute-if
	  nsubstitute-if-not
	  nunion
	  open
	  phase
	  pop
	  position
	  position-if
	  position-if-not
	  prin1-to-string
	  princ-to-string
	  prog1
	  prog2
	  prog*
	  provide
	  psetf
	  push
	  pushnew
	  rational
	  rationalize
	  read-from-string
	  reduce
	  rem
	  remf
	  remove
	  remove-duplicates
	  remove-if
	  remove-if-not
	  replace
	  require
	  rotatef
	  row-major-aref
	  room
	  sbit
	  search
	  second
	  set-difference
	  set-exclusive-or
	  setf
	  seventh
	  shiftf
	  short-site-name
	  simple-base-string
	  signum
	  sinh
	  sixth
	  software-type
	  software-version
	  some
	  sort
	  special-form-p
	  special-operator-p
	  stable-sort
	  step
	  structure
	  subsetp
	  substitute
	  substitute-if
	  substitute-if-not
	  subtypep
	  t
	  tanh
	  tenth
	  third
	  time
	  trace
	  type
	  typecase
	  typep
	  union
	  untrace
	  variable
	  vector
	  vector-pop
	  vector-push
	  vector-push-extend
	  warn
	  with-input-from-string
	  with-open-file
	  with-open-stream
	  with-output-to-string
	  with-standard-io-syntax
	  write-to-string
	  y-or-n-p
	  yes-or-no-p

	  proclaim
	  special
	  type
	  ftype
	  function
	  inline
	  notinline
	  ignore
	  optimize
	  speed
	  space
	  safety
	  compilation-speed

	  *eval-when-compile*
	  ))

(si::select-package "SI")

;;; ----------------------------------------------------------------------
;;;
(*make-special '*dump-defun-definitions*)
(setq *dump-defun-definitions* nil)
(*make-special '*dump-defmacro-definitions*)
(setq *dump-defmacro-definitions* *dump-defun-definitions*)

(si::fset 'defun
	  (si::bc-disassemble
	  #'(lambda-block defun (def env)
	      (let* ((name (second def))
		     (function `#'(lambda-block ,@(cdr def))))
		(when *dump-defun-definitions*
		  (print function)
		  (setq function `(si::bc-disassemble ,function)))
		`(si::fset ',name ,function))))
	  t)


(si::fset 'in-package
	  #'(lambda-block in-package (def env)
	      `(si::select-package ,(string (second def))))
	  t)

(defun eval-feature (x)
  (cond ((symbolp x)
         (member x *features*
                 :test #'(lambda (a b)
                           (or (eql a b)
			       (and (symbolp a) (symbolp b)
				    (string-equal (symbol-name a)
						  (symbol-name b)))))))
	((atom x) (error "~ is not allowed as a feature" x))
        ((eq (car x) 'AND)
         (dolist (x (cdr x) t) (unless (eval-feature x) (return nil))))
        ((eq (car x) 'OR)
         (dolist (x (cdr x) nil) (when (eval-feature x) (return t))))
        ((eq (car x) 'NOT)
	 (not (eval-feature (second x))))
	(t (error "~S is not a feature expression." x))))

;;; Revised by G. Attardi
(defun check-no-infix (stream subchar arg)
  (when arg
    (error "Reading from ~S: no number should appear between # and ~A"
	   stream subchar)))

(defun sharp-+-reader (stream subchar arg)
  (check-no-infix stream subchar arg)
  (let ((feature (read stream t nil t)))
    (if (and (not *read-suppress*) (eval-feature feature))
	(read stream t nil t)
	(let ((*read-suppress* t)) (read stream t nil t) (values)))))

(set-dispatch-macro-character #\# #\+ 'sharp-+-reader)
(set-dispatch-macro-character #\# #\+ 'sharp-+-reader
                              (sys::standard-readtable))

(defun sharp---reader (stream subchar arg)
  (check-no-infix stream subchar arg)
  (let ((feature (read stream t nil t)))
    (if (or *read-suppress* (eval-feature feature))
	(let ((*read-suppress* t)) (read stream t nil t) (values))
	(read stream t nil t))))

(set-dispatch-macro-character #\# #\- 'sharp---reader)
(set-dispatch-macro-character #\# #\- 'sharp---reader
                              (sys::standard-readtable))

;;; ----------------------------------------------------------------------

(in-package "CL")

#+CLOS
(export '(
	  add-method
	  call-next-method
	  change-class
	  class-changed
	  class-name
	  class-of
	  defclass
	  defgeneric
	  define-method-combination
	  defmethod
	  ensure-generic-function
	  find-class
	  generic-flet
	  generic-function
	  generic-labels
	  get-method
	  initialize-instance
	  invalid-method-error
	  make-instance
	  make-instances-obsolete
	  make-method-call
	  method
	  method-combination-error
	  method-qualifiers
	  next-method-p
	  no-applicable-method
	  print-object
	  print-unreadable-object
          reinitialize-instance
	  remove-method
          shared-initialize
	  slot-boundp
	  slot-exists-p
	  slot-makunbound
	  slot-missing
	  slot-unbound
	  slot-value
	  subclassp
	  symbol-macrolet
          update-instance-for-redefined-class
	  update-instance-structure
	  with-accessors
	  with-added-methods
	  with-slots

	  class
	  built-in
	  standard-class
	  standard-generic-function
	  standard-method
	  standard-object
	  structure-class
	  structure-object
	  ))

;
; Conditions system
;
(export '(*break-on-signals* *debugger-hook* signal
	  handler-case handler-bind ignore-errors define-condition make-condition
	  with-simple-restart restart-case restart-bind restart-name
	  restart-name find-restart compute-restarts invoke-restart
	  invoke-restart-interactively abort continue muffle-warning
	  store-value use-value invoke-debugger restart condition
	  warning serious-condition simple-condition simple-warning simple-error
	  simple-condition-format-string simple-condition-format-arguments
	  storage-condition stack-overflow storage-exhausted type-error
	  type-error-datum type-error-expected-type simple-type-error
	  program-error control-error stream-error stream-error-stream
	  end-of-file file-error file-error-pathname cell-error
	  unbound-variable undefined-function arithmetic-error
	  arithmetic-error-operation arithmetic-error-operands
	  package-error package-error-package
	  division-by-zero floating-point-overflow floating-point-underflow))
