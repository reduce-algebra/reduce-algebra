;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; File:         PU:FAST-STRUCT.LSP 
; Description:  
; Author:       
; Created:      
; Modified:     28-Aug-84 08:58:23 (Brian Beach)
; Status:       Open Source: BSD License
; Mode:         Lisp 
; Package:      Utilities 
; Compile to:   none
;
;% (c) Copyright 1983, Hewlett-Packard Company, see the file
;%            HP_disclaimer at the root of the PSL file tree
;%
;%
;% Redistribution and use in source and binary forms, with or without
;% modification, are permitted provided that the following conditions are met:
;%
;%    * Redistributions of source code must retain the relevant copyright
;%      notice, this list of conditions and the following disclaimer.
;%    * Redistributions in binary form must reproduce the above copyright
;%      notice, this list of conditions and the following disclaimer in the
;%      documentation and/or other materials provided with the distribution.
;%
;% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
;% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
;% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
;% CONTRIBUTORS
;% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;% POSSIBILITY OF SUCH DAMAGE.
;
; This file is included in PU:NSTRUCT.LSP
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Revisions:
;
; 19 Jan 1984 1431-PST (Brian Beach)
;   Added standard header.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defstruct-define-type :fast-vector
  (:named :named-fast-vector)			; but probably not much point
  (:cons
    (arg description etc) :list
    description		;ignored
    etc			;ignored
    `(vector ,@arg))
  (:defstruct (x) (let ((*insideload t)) (load fast-vector) nil))
  (:ref
    (n description arg)
    description		;ignored
    `(igetv ,arg ,n)))

;added for PSL

(defstruct-define-type :named-fast-vector
  (:keywords :make-vector)
  :named (:overhead 1)
  (:cons
    (arg description etc) :list
    description		;ignored
    etc			;ignored
    `(vector ',(defstruct-description-name) ,@arg))
  (:defstruct (x) (let ((*insideload t)) (load fast-vector) nil))
  (:ref
    (n description arg)
    description		;ignored
    `(igetv ,arg ,(add1 n))))

(defstruct-define-type hashed-list
  (:named :named-hashed-list)
  (:cons
    (arg description etc) :list
    description		;ignored
    etc			;ignored
    `(hlist . ,arg))
  (:ref
    (n description arg)
    description		;ignored
    #+Multics `(,(let ((i (\ n 4)))
		   (cond ((= i 0) 'car)
			 ((= i 1) 'cadr)
			 ((= i 2) 'caddr)
			 (t 'cadddr)))
		,(do ((a arg `(cddddr ,a))
		      (i (// n 4) (1- i)))
		     ((= i 0) a)))
;     PSL change     incompatible NTH
    #-Multics `(nth ,arg ,(add1 n))))
;    #-Multics `(nth ,n ,arg)))

(defstruct-define-type :named-hashed-list
  :named (:overhead 1)
  (:cons
    (arg description etc) :list
    etc			;ignored
    `(hlist ',(defstruct-description-name) . ,arg))
  (:ref
    (n description arg)
    description		;ignored
;    #+Multics `(,(let ((i (\ (1+ n) 4)))
;		   (cond ((= i 0) 'car)
;			 ((= i 1) 'cadr)
;			 ((= i 2) 'caddr)
;			 (t 'cadddr)))
;		,(do ((a arg `(cddddr ,a))
;		      (i (// (1+ n) 4) (1- i)))
;		     ((= i 0) a)))
;     PSL change	incompatible NTH
     #-Multics `(nth ,arg ,(+ n 2))))
;    #-Multics `(nth ,(1+ n) ,arg)))

(defstruct-define-type :hashed-list*
  (:cons
    (arg description etc) :list
    description		;ignored
    etc			;ignored
    `(hcons . ,arg))
  (:ref
    (n description arg)
;     PSL change	1- ==> sub1
    (let ((size (sub1 (defstruct-description-size))))
;    (let ((size (1- (defstruct-description-size))))
      #+Multics (do ((a arg `(cddddr ,a))
		     (i (// n 4) (1- i)))
		    ((= i 0)
		     (let* ((i (\ n 4))
			    (a (cond ((= i 0) a)
				     ((= i 1) `(cdr ,a))
				     ((= i 2) `(cddr ,a))
				     (t `(cdddr ,a)))))
		       (if (< n size) `(car ,a) a))))
      #-Multics (if (< n size)
;     PSL change	incompatible NTH
		    `(nth ,arg ,(add1 n))
		    `(pnth ,arg ,(add1 n)))))
;		    `(nth ,n ,arg)
;		    `(nthcdr ,n ,arg))))
  (:defstruct (description)
    (and (defstruct-description-include)
	 (defstruct-error
	   "Structure of type hashed-list* cannot include another"
	   (defstruct-description-name)))
    nil))

(defstruct-define-type :hashed-tree
  (:cons
    (arg description etc) :list
    etc			;ignored
    (if (null arg) (defstruct-error
		     "defstruct cannot make an empty tree"
		     (defstruct-description-name)))
    (make-hashed-tree-for-defstruct arg (defstruct-description-size)))
  (:ref
    (n description arg)
    (do ((size (defstruct-description-size))
	 (a arg)
	 (tem))
	(())
      (cond ((= size 1) (return a))
;     PSL change	// ==> /
	    ((< n (setq tem (/ size 2)))
;	    ((< n (setq tem (// size 2)))
	     (setq a `(car ,a))
	     (setq size tem))
	    (t (setq a `(cdr ,a))
	       (setq size (- size tem))
	       (setq n (- n tem))))))
  (:defstruct (description)
    (and (defstruct-description-include)
	 (defstruct-error
	   "Structure of type tree cannot include another"
	   (defstruct-description-name)))
    nil))

(defun make-hashed-tree-for-defstruct (arg size)
       (cond ((= size 1) (car arg))
	     ((= size 2) `(hcons ,(car arg) ,(cadr arg)))
	     (t (do ((a (cdr arg) (cdr a))
;     PSL change	// ==> /, 1- ==> sub1
		     (m (/ size 2))
		     (n (sub1 (/ size 2)) (sub1 n)))
;		     (m (// size 2))
;		     (n (1- (// size 2)) (1- n)))
		    ((zerop n)
		     `(hcons
			,(make-hashed-tree-for-defstruct arg m)
			,(make-hashed-tree-for-defstruct a (- size m))))))))
