%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           symget.sl
% Description:    fast access to 'first class' properties.
%                 used for reducing the number of propertylist requests
%                 includes former symflags module
% Author:         Winfried Neun , ZIB Berlin
% Created:        3 January 1991  
%
% Copyright (c) 1991, Konrad Zuse Zentrum Berlin, all rights reserved
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Usage:
% Get requests asking for a 'first class' property are handled via a two
% step vector access: first a vector (length maxsymbols) is inspected for
% an entry of 'first class' properties. If it exists, the second vector
% containing the special properties is used. Otherwise NIL.
% The vector for all ids is created at load time, the id specific second
% vector is created by put operation. Put also alters the property list to
% ensure correctness (e.g. in interpreter)
%
% For flags all property list activities are done via fast vector access.
%
% The property to be a 'first class' property must be set at the very
% early beginning of compilation
%

(load fast-vector) 
(on fast-vectors)

(compiletime (progn

 (setq *syslisp t)

 (load fast-vector) (on fast-vectors)
 (load if-system)

 (defmacro def-pass-1-macro (name args . body)
   (let ((fcn-name (intern (string-concat "PA1M-" (id2string name)))))
     `(progn
	(put (quote ,name) (quote pass-1-macro) (quote ,fcn-name))
	(defmacro ,fcn-name ,args ,@body)
    )))

 (remprop 'get 'pass-1-macro)   % avoid endless recursion
))

(ds symgt (id prop)
	((lambda (v propval)
	   (cond ((null v) NIL)
	         (t (igetv v propval))))
     %%        (symget (id2int id)) prop)) % id prop is checked already
	        (symget (inf id)) prop))

(de install-symflag (x val)
	(put x 'symflag? t)
	(put x 'symflagval val))

(de install-symget (x val)       % install a first class property
	(when (memq x '(symget? symgetval)) (return nil))
	(put x 'symget? t)        % Caution cant symget id symget itself!
	(put x 'symgetval val))

(put 'symflag 'openfn  '(nonassocpat *symflag))

(de *symflag (ArgOne ArgTwo)
    (expand2operandcmacro ArgOne ArgTwo '*symflag))

(defcmacro *symflag  ((*move argone (reg t5))
                      (*move ($fluid &symflag&) (reg t4))
		      (rldic  (reg t5) (reg t5) 3 5) % inf *8
                      (*wplus2 (reg t5) (reg t4))
                      (*field (reg t5) (reg t5) 8 56)
                      (*move (indexed (reg t5) 4) (reg t5))
                      (*wshift (reg t5) (minus argtwo))
                      (*wand (reg t5) 1)
                      (*move (reg t5) argone)))

(compiletime
(progn % MacG5
  (put 'putsymflag 'opencode '((*move ($fluid &symflag&) (reg 5))
			      (rldic  (reg 3) (reg 1) 3 5) % inf *8
			      (*wplus2 (reg 5) (reg 3))
			      (*field (reg 5) (reg 5) 8 56)
			      (*move (indexed (reg 5) 4) (reg 3))
			      (*move 1 (reg 4))
			      (sld (reg 4) (reg 4) (reg 2))
			      (*wor (reg 3) (reg 4))
			      (*move (reg 3) (indexed (reg 5) 4))))

  (put 'delsymflag 'opencode '((*move ($fluid &symflag&) (reg 5))
			      (rldic  (reg 3) (reg 1) 3 5) % inf *8
			      (*wplus2 (reg 5) (reg 3))
			      (*field (reg 5) (reg 5) 8 56)
			      (*move (indexed (reg 5) 4) (reg 3))
			      (*move 1 (reg 4))
			      (sld (reg 4) (reg 4) (reg 2))
			      (*wnot (reg 4) (reg 4))
			      (*wand (reg 3) (reg 4))
			      (*move (reg 3) (indexed (reg 5) 4)))))
)%end compiletime

(dm symflagp (u)
  (cond ((not (get (cadr (caddr u)) 'symflag?)) nil)
      (t `(weq (symflag ,(cadr u) ,(get (cadr(caddr u)) 'symflagval))1)
      )))

(fluid '(&symflag& symget &symgetsize&))

(de !%put (a b c)
  (prog (v pu)
    (setq pu (old-put a b c))  % does checks
    (when (get b 'symget?)                      % if first class and
	   (setq v (symget (id2int a)))          % vector not present
	   (when (null v) (setq v (mkvect &symgetsize&))  % make it
			    (wputv  (inf symget) (id2int a) v))
	   (iputv v (get b 'symgetval) c))       % store property
    (return pu)))

(when (funboundp 'old-put) (copyd 'old-put 'put)
			      (copyd 'put '!%put))

(when (funboundp '!%get) (copyd '!%get 'get))
 
(de !%remprop (a b)
  (prog (v pu)
    (setq pu (old-remprop a b))  % does checks
    (when (get b 'symget?)
	   (setq v (symget (id2int a)))
	   (when v (iputv v (get b 'symgetval) NIL)))
    (return pu)))

(compiletime (progn (console-print-string "aber ach") (console-newline)))
(when (funboundp 'old-remprop) (copyd 'old-remprop 'remprop)
			          (copyd 'remprop '!%remprop))

(de !%flag1 (a b)
	  (when (not (idp a)) (noniderror a 'flag1))
	  (when (get b 'symflag?) 
	        (putsymflag a (get b 'symflagval)))
	  (old-flag1 a b))

(when (funboundp 'old-flag1) (copyd 'old-flag1 'flag1)
			        (copyd 'flag1 '!%flag1))

(de !%remflag1 (a b)
	  (when (not (idp a)) (noniderror a 'remflag1))
	  (when (get b 'symflag?)
	          (delsymflag a (get b 'symflagval)))
	  (old-remflag1 a b))

(when (funboundp 'old-remflag1) (copyd 'old-remflag1 'remflag1)
			           (copyd 'remflag1 '!%remflag1))

(null (progn
	      (setq &symgetsize& 32)		  % default
%            (setq symget (gtwarray maxsymbols))
	      (setq &symflag& (make-words maxsymbols 0))))

(remob '!%put)
(remob '!%remprop)
(remob '!%flag1)
(remob '!%remflag1)

(def-pass-1-macro get (a b)
  (when (and (pairp b) (!%get (cadr b) 'symget?))
	   `((lambda (x)
	       (cond ((idp x) (symgt x ,(!%get (cadr b) 'symgetval)))
	             (t nil))) ,a )))

(def-pass-1-macro flagp (a b)
  (when (and (pairp b) (get (cadr b) 'symflag?))
	   `((lambda (x)
	        (cond ((and (idp x) (symflagp x ,b)) t)
			(t nil))) ,a )))
    
