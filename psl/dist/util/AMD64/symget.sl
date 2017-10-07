%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           symget.sl
% Description:    fast access to 'first class' properties. (Cray version only)
%                 used for reducing the number of propertylist requests
%                 includes former symflags module
% Author:         Winfried Neun , ZIB Berlin
% Created:        3-September-1988
% Status:         Experimental (Do Not Distribute)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Usage:
% Get requests asking for a 'first class' property are handled via a two
% step vector access: first a vector (length maxsymbols) is inspected for
% an entry of 'first class' properties. If this exists the second vector
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

(on pcmac)
 (load fast-vector) (on fast-vectors)
 (load if-system)
 (load inum)

 (ds string-concat(a b)
       (compress (append (explode2 a)(explode2 b))))

 (defmacro def-pass-1-macro (name args . body)
   (let ((fcn-name (intern (string-concat "PA1M-" (id2string name)))))
     `(progn
       (put (quote ,name) (quote pass-1-macro) (quote ,fcn-name))
       (defmacro ,fcn-name ,args ,@body)
    )))

 (remprop 'get 'pass-1-macro)   % avoid endless recursion
))

%%% (ds symget (n) (wgetv (inf symget) n))  defined in $pxc/sys-dm 

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
       (cond ((memq x '(symget? symgetval)) nil)
             (t
              (put x 'symget? t)        % Caution cant symget id symget itself!
              (put x 'symgetval val))))

(put 'symflag 'openfn  '(nonassocpat *symflag)) % not really correct
 
(put 'nonassocpat 'pattern
     '(nil ('!*set dest (fn a1 a2))
	   ((dest any) (mac a1 a2))
	   ((any usesdest) ('!*load t1 a2) ('!*load dest a1) (mac dest t1))
	   (any ('!*load dest a1) (mac dest a2))))

(de *symflag (ArgOne ArgTwo)
    (expand2operandcmacro ArgOne ArgTwo '*symflag))

   (defcmacro *symflag  ((*move argone (reg t1))
			 (*move ($fluid &symflag&) (reg t2))
			 (*wshift (reg t1) 8)  % inf
			 (*wshift (reg t1) -5) % and * 4
			 (*wplus2 (reg t1) (reg t2))
			 (*wshift (reg t1) 8) % inf
			 (*wshift (reg t1) -8) % inf
			 (*move (memory (reg t1) 8) (reg t1))
			 (*wshift (reg t1) (minus argtwo))
			 (*wand (reg t1) 1)
			 (*move (reg t1) argone)))

(compiletime
  (put 'putsymflag 'opencode '((*move ($fluid &symflag&) (reg 5))
			       (*move (reg 1) (reg 3)) 
			       (*wshift (reg 3) 8)  % inf 
			       (*wshift (reg 3) -5) % *8 
			       (*wplus2 (reg 5) (reg 3))
			       (*wshift (reg 5) 8)
			       (*wshift (reg 5) -8) % inf
			       (*move (memory (reg 5) 8) (reg 4))
			       (*move 1 (reg t1))
			       (*wshift (reg t1) (reg 2))
			       (*wor  (reg 4) (reg t1))
			       (*move (reg 4) (memory (reg 5) 8))))

  (put 'delsymflag 'opencode '((*move ($fluid &symflag&) (reg 5))
			       (*move (reg 1) (reg 3))
			       (*wshift (reg 3) 8)  % inf
			       (*wshift (reg 3) -5) % *8
			       (*wplus2 (reg 5) (reg 3))
			       (*wshift (reg 5) 8) 
			       (*wshift (reg 5) -8) % inf 
			       (*move (memory (reg 5) 8) (reg 4))
			       (*move 1 (reg t1))
			       (*wshift (reg t1) (reg 2))
			       (*wnot (reg t1) (reg t1))
			       (*wand (reg 4) (reg t1))
			       (*move (reg 4) (memory (reg 5) 8)))))

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
	     (setq &symgetsize& 20)                  % default
%%%   (setq symget (gtwarray maxsymbols))     % geoeffnet
	     (ifor (from i 0 maxsymbols 1)
		   (do (setf (symget i) nil)))
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
