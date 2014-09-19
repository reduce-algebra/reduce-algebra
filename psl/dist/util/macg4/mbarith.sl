%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         $(PXU)/mbarith.sl 
% Description:  Generic arithmetic routines for IBM RS/6000 PSL
% Author:       Winfried Neun
% Created:      4 January 1991
% Mode:         Lisp
%
% (c) Copyright 1991, Konrad-Zuse-Zentrum Berlin , all rights reserved
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% New arithmetic: 
%
% The main goal of this module is to provide a fast arithmetic, which is
% (of course) less elegant than a portable version. The main ideas for speedup
% are: 
% - avoiding unnecessary coercing in dispatch,
% - usage of double precision hardware,
% - usage of mixed bignum/sysint arithmetic  
% - insertion of checks for trivial cases,
% - immediate evaluation of predicates from type information.
%
% NOTE This implementation is (at the moment) for 32 bit systems ONLY!
%      It required the 30 bit bignum arithmetic by Herbert Melenk
% 
% Details:
%
% Number ranges:
%                    ints :       27 bits stored in inf field, sign included
%                                 in the tag (posint/negint tag) 
%                 fixnums :       2 words in heap, first is hwords-header
%                                 second is 30 bit integer
%                 bignums :       n words in heap, first is hwords-header
%                                 second is sign (T = neg; NIL = positive)
%                                 next are 30 bit integers
%                  floats :       hardware format for doubles
%
% The limitation to 30 bit integers was made such that any two integers
% can be treated by signed integer arithmetic.
%
% Coding technique:
% 
% The dispatch (for two arguments) is done by hashing the tags of the operands
% to a number in the range of 0 .. 24 which presents the 5*5 combinations of
% numeric types. Then a (case construct can handle all different cases
% individually. This certainly lacks of coding elegance, but there are not
% many arithmetic ops which have exactly the same restrictions on arguments
% and results,e.g. + and - ; but + is not the same as / and not the same as *.
% In the following code the combined types are:

%  0 negint/negint    8 posint/bignum   13 fixnum/bignum         
%  1 negint/posint   15 bignum/negint   17 bignum/fixnum     
%  5 posint/negint   16 bignum/posint   14 fixnum/float      
%  6 posint/posint    4 negint/float    18 bignum/bignum     
%  2 negint/fixnum    9 posint/float    22 float /fixnum     
%  7 posint/fixnum   20 float /negint   19 bignum/float      
% 10 fixnum/negint   21 float /posint   23 float /bignum     
% 11 fixnum/posint   12 fixnum/fixnum   24 float /float      
%  3 negint/bignum   

% The formula:   5 * ( (tagx + 1) & 31) + ((tagy + 1) & 31)      
 
% One argument arithmetic is simpler, but in the same style.

% Arithmetic predicates can in some cases already be decided from type infor-
% mation or from sign without calculation, e.g. positive bignum is always
% greater than a fixnum.

(fluid '(staticfloatloc *second-value*))

(loadtime (setq staticfloatloc (gtwarray 3)))

(compiletime (load muls))

(flag '(sysxx2int wgcdn-aux) 'internalfunction)

(de sys2fixn (n)
  (prog (fx fixn-tag)
	(setf fixn-tag (tag n))
	(setf n (inf n))        % this 'sport' is for GC! 
	(setq fx (gtfixn))
	(setf (fixval fx) (mkitem fixn-tag n))
	(return (mkfixn fx))))

(compiletime
 (ds isys2int (n)
   ((lambda (**n**)
        (if (weq (signedfield **n** (wdifference infstartingbit 1)
                                    (wplus2 infbitlength 1))
           **n**) **n** (sys2int **n**))) n)))
     
(de sys2int (nn)% a new variant; has to make a bignum eventually
                % Convert word to Lisp number
                % be careful with largest negative fixnum
 ((lambda (n athree)
  (if (weq (signedfield n (wdifference infstartingbit 1)
                          (wplus2 infbitlength 1))
           n)
    n
    (if (and (weq (signedfield n 1 31) n) (not (eq n (wshift athree 30))))
                                     (sys2fixn n)
                                     (sys2big n)))) nn 3))

(de sysx2int (u)    
  % convert a sysnumber plus *second-value* which contains the upper bits
  % into a sysnumber, fixnumber or bignumber 
    (prog (secundus big lower27 upper3 sign)
       (setq secundus *second-value*) % the overflow

       (cond ((and (eq 0  secundus) (wgeq u 0)) (return (sys2int u)))
	     ((and (eq -1 secundus) (wlessp u 0)) (return (sys2int u)))
	     ((wlessp secundus 0)
	             (setq secundus    (wnot secundus))
	             (setq u (wplus2 1 (wnot u)))
                     (when (eq u 0) (setq secundus (wplus2 1 secundus)))
				 % a carry
	             (setq sign t)))

	       % now all positive, must be hidden for gc !

       (setq lower27 (inf u)  upper3 (wshift (wshift u 2) -29))
       (setq *second-value* 0)

       (setq secundus (wor (wshift secundus 2) (wshift u -30)))
       (setq u (tag secundus))
       (setq secundus (inf secundus))

       (setq big (if sign (gtneg 2) (gtpos 2)))
       (iputv big 2 (wor (wshift u 27) secundus))
       (iputv big 1 (wor lower27 (wshift upper3 27)))
       (return big)))

(de sysxx2int (u)          % this is for divide
     (prog (secundus)
       (setq secundus (sys2int *second-value*))
       (return (cons (sys2int u) secundus))))

(compiletime (progn

   (ds deffloatentry (name prim)
      (de name (x y)
	(prog (f)
	     (setq f (gtfltn))
	     (prim (floatbase f) (fltinf x) (fltinf y))
	     (return (mkfltn f)))))

   (ds staticintfloat (x)
	(!*wfloat (loc (wgetv staticfloatloc 1)) x)
	(mkfltn (loc (wgetv staticfloatloc 0))))
))
 
%(copyd 'oldtimes2 'times2)
%(de times2 (x y) (prog (r1 r2) (setq r1 (oldtimes2 x y))
% (setq r2 (ztimes2 x y)) (if (equal r1 r2) (return r1) 
%  (return (print (list "**FEHLER**" x y r1 r2))))))
(de times2 (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'times2)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                      tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0 1 5 6)                           % int int
	         (sysx2int (wxtimes2 x y)))
	   ((2 7)                               % int fixnum
	         (sysx2int (wxtimes2 x (fixval (fixinf y))))) 
	   ((10 11)                             % fixnum int
	         (sysx2int (wxtimes2 (fixval (fixinf x)) y)))
	   ((3 8)                               % int bignum
	         (bigtimes2 (sys2big x) y))
	   ((15 16)                             % bignum int
	         (bigtimes2 x (sys2big y)))
	   ((4 9)                               % int floatnum
	         (floattimes2 (staticintfloat x) y)) 
	   ((20 21)                             % floatnum int
	         (floattimes2 x (staticintfloat y)))
	   ((12)                                % fixnum fixnum
	         (sysx2int (wxtimes2 (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13)                                % fixnum bignum
	         (bigtimes2 (sys2big (fixval (fixinf x))) y)) 
	   ((17)                                % bignum fixnum
	         (bigtimes2 x (sys2big (fixval (fixinf y)))))
	   ((14)                                % fixnum floatnum
	         (floattimes2 (staticintfloat (fixval (fixinf x))) y))
	   ((18)                                % bignum bignum
	         (bigtimes2 x y))
	   ((22)                                % floatnum fixnum
	         (floattimes2 x (staticintfloat (fixval (fixinf y)))))
	   ((19)                                % bignum floatnum
	         (floattimes2 (floatfrombignum x) y))
	   ((23)                                % floatnum bignum
	         (floattimes2 x (floatfrombignum y)))
	   ((24)                                % floatnum floatnum 
	         (floattimes2 x y)) 
	   (nil      (nonnumber2error x y 'times2)))
))) 

(de plus2 (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'plus2)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                   tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0 1 5 6) (isys2int (wplus2 x y)))  % int int
	   ((2 7)                               % int fixnum
	         (sys2int (wplus2 x (fixval (fixinf y))))) 
	   ((10 11)                             % fixnum int
	         (sys2int (wplus2 (fixval (fixinf x)) y)))
	   ((3 8) (bigplus2 (sys2big x) y))     % int bignum
	   ((15 16) (bigplus2 x (sys2big y)))   % bignum int
	   ((4 9)                               % int floatnum
	         (floatplus2 (staticintfloat x) y)) 
	   ((20 21)                             % floatnum int
	         (floatplus2 x (staticintfloat y)))
	   ((12)                                % fixnum fixnum
	         (sys2int (wplus2 (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13)                                % fixnum bignum
	         (bigplus2 (sys2big (fixval (fixinf x))) y)) 
	   ((17)                                % bignum fixnum
	         (bigplus2 x (sys2big (fixval (fixinf y)))))
	   ((14)                                % fixnum floatnum
	         (floatplus2 (staticintfloat (fixval (fixinf x))) y))
	   ((18) (bigplus2 x y))                % bignum bignum
	   ((22)                                % floatnum fixnum
	         (floatplus2 x (staticintfloat (fixval (fixinf y)))))
	   ((19)                                % bignum floatnum
	         (floatplus2  (floatfrombignum x) y))
	   ((23)                                % floatnum bignum
	         (floatplus2 x (floatfrombignum y)))
	   ((24) (floatplus2 x y))           % floatnum floatnum 
	   (nil      (nonnumber2error x y 'plus2)))
))) 

(de difference (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'difference)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                   tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0 1 5 6)                           % int int
	         (isys2int (wdifference x y)))
	   ((2 7)                               % int fixnum
	         (sys2int (wdifference x (fixval (fixinf y))))) 
	   ((10 11)                             % fixnum int
	         (sys2int (wdifference (fixval (fixinf x)) y)))
	   ((3 8)                               % int bignum
	         (bigdifference (sys2big x) y))
	   ((15 16)                             % bignum int
	         (bigdifference x (sys2big y)))
	   ((4 9)                               % int floatnum
	         (floatdifference (staticintfloat x) y)) 
	   ((20 21)                             % floatnum int
	         (floatdifference x (staticintfloat y)))
	   ((12)                                % fixnum fixnum
	        (sys2int (wdifference (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13)                                % fixnum bignum
	         (bigdifference (sys2big (fixval (fixinf x))) y)) 
	   ((17)                                % bignum fixnum
	         (bigdifference x (sys2big (fixval (fixinf y)))))
	   ((14)                                % fixnum floatnum
	         (floatdifference (staticintfloat (fixval (fixinf x))) y))
	   ((18)                                % bignum bignum
	         (bigdifference x y))
	   ((22)                                % floatnum fixnum
	         (floatdifference x (staticintfloat (fixval (fixinf y)))))
	   ((19)                                % bignum floatnum
	         (floatdifference (floatfrombignum x) y))
	   ((23)                                % floatnum bignum
	         (floatdifference x (floatfrombignum y)))
	   ((24)                                % floatnum floatnum 
	         (floatdifference x y)) 
	   (nil      (nonnumber2error x y 'difference)))
))) 

(de quotient (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'quotient)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                   tagy))   % 0 <= bothtags =< 186
       (when (eq 1 y) (return x))
       (when (eq 0 y) (return (stderror " Zero Division ")))
       (return  
	 (case bothtags 
	   ((0)  (isys2int (wquotient x y)))    % negint negint
           ((1 5 6) (wquotient x y))            % int int
           ((7)   0)                            % posint fixnum
           ((2) (if (eq 0 (inf x)) (wquotient x (fixval (fixinf y)))
                                   0))          % negint fixnum
	   ((10 11)                             % fixnum int
	         (sys2int (wquotient (fixval (fixinf x)) y)))
	   ((3 8)   0)                          % int bignum
	   ((15 16) (bigquotient x (sys2big y)))% bignum int
	   ((4 9)                               % int floatnum
	         (floatquotient (staticintfloat x) y)) 
	   ((20 21)                             % floatnum int
	         (floatquotient x (staticintfloat y)))
	   ((12)                                % fixnum fixnum
	         (sys2int (wquotient (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13) 0)                             % fixnum bignum
	   ((17) (bigquotient x (sys2big (fixval (fixinf y))))) % bignum fixnum
	   ((14)                                % fixnum floatnum
	         (floatquotient (staticintfloat (fixval (fixinf x))) y))
	   ((18) (bigquotient x y))             % bignum bignum
	   ((22)                                % floatnum fixnum
	         (floatquotient x (staticintfloat (fixval (fixinf y)))))
	   ((19)                                % bignum floatnum
	         (floatquotient  (floatfrombignum x) y))
	   ((23)                                % floatnum bignum
	         (floatquotient x (floatfrombignum y)))
	   ((24) (floatquotient x y))        % floatnum floatnum 
	   (nil      (nonnumber2error x y 'quotient)))
))) 

(de remainder (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'remainder)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                   tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0 1 5 6)                           % int int
	         (wremainder x y))
           ((2) (if (eq 0 (inf x)) (wremainder x (fixval (fixinf y))) x))
                                              % negint fixnum
           ((7) x)                            % posint fixnum
	   ((10 11)                             % fixnum int
	         (wremainder (fixval (fixinf x)) y))
	   ((3 8) x)                            % int bignum
	   ((15 16)                             % bignum int
	         (bigremainder x (sys2big y)))
	   ((4 9)                               % int floatnum
	         (floatremainder (staticintfloat x) y)) 
	   ((20 21)                             % floatnum int
	         (floatremainder x (staticintfloat y)))
	   ((12)                                % fixnum fixnum
	       (sys2int (wremainder (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13) x)                             % fixnum bignum
	   ((17)                                % bignum fixnum
	         (bigremainder x (sys2big (fixval (fixinf y)))))
	   ((14)                                % fixnum floatnum
	         (floatremainder (staticintfloat (fixval (fixinf x))) y))
	   ((18)                                % bignum bignum
	         (bigremainder x y))
	   ((22)                                % floatnum fixnum
	         (floatremainder x (staticintfloat (fixval (fixinf y)))))
	   ((19)                                % bignum floatnum
	         (floatremainder  (floatfrombignum x) y))
	   ((23)                                % floatnum bignum
	         (floatremainder x (floatfrombignum y)))
	   ((24)                                % floatnum floatnum 
	         (floatremainder x y)) 
	   (nil      (nonnumber2error x y 'remainder)))
))) 

(de floatremainder (x Y)
        (stderror "Floatremainder should never be called"))

(de divide (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'divide)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                   tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags                       % negint negint
	   ((0)  (cons (isys2int(wdivide x y)) *second-value*))
           ((1 5 6)                           % int int
	         (cons (wdivide x y) *second-value*))
           ((7) (cons 0 x))                   % posint fixnum
           ((2) (if (not (eq 0 (inf x)))
                        (cons 0 x)            % negint fixnum
                        (sysxx2int (wdivide x (fixval (fixinf y))))))
	   ((10 11)                             % fixnum int
	         (sysxx2int (wdivide (fixval (fixinf x)) y)))
	   ((3 8) (cons 0 x))                   % int bignum
	   ((15 16)                             % bignum int
	         (bigdivide x (sys2big y)))
	   ((4 9)                               % int floatnum
	         (floatdivide (staticintfloat x) y)) 
	   ((20 21)                             % floatnum int
	         (floatdivide x (staticintfloat y)))
	   ((12)                                % fixnum fixnum
	         (sysxx2int (wdivide (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13) (cons 0 x))                    % fixnum bignum
	   ((17)                                % bignum fixnum
	         (bigdivide x (sys2big (fixval (fixinf y)))))
	   ((14)                                % fixnum floatnum
	         (floatdivide (staticintfloat (fixval (fixinf x))) y))
	   ((18)                                % bignum bignum
	         (bigdivide x y))
	   ((22)                                % floatnum fixnum
	         (floatdivide x (staticintfloat (fixval (fixinf y)))))
	   ((19)                                % bignum floatnum
	         (floatdivide  (floatfrombignum x) y))
	   ((23)                                % floatnum bignum
	         (floatdivide x (floatfrombignum y)))
	   ((24)                                % floatnum floatnum 
	         (floatdivide x y)) 
	   (nil      (nonnumber2error x y 'divide)))
))) 

(de floatdivide (x Y) 
        (stderror "Floatdivide  should never be called")) 

(de gcdn (x y)
     (prog (tagx tagy bothtags)
        (cond ((eq x 1) (return 1))
              ((eq y 1) (return 1)))
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'gcdn)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                   tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0)  (isys2int (wgcdn-aux (wminus x) (wminus y))))
                                                % negint negint
           ((1)  (isys2int (wgcdn-aux (wminus x) y))) % negint posint
           ((5)  (isys2int (wgcdn-aux x (wminus y)))) % posint negint
	   ((6)  (wgcdn-aux x y))               % posint posint
	   ((2 7)                               % int fixnum
	         (sys2int (wgcdn (fixval (fixinf y)) x)))
	   ((10 11)                             % fixnum int
	         (sys2int (wgcdn (fixval (fixinf x)) y)))
	   ((3 8) (if (eq 0 x) (abs y)          % int bignum
	             (isys2int (wgcdn x (remainder y x)))))
	   ((15 16) (if (eq 0 y) (abs x)        % bignum int
	             (isys2int (wgcdn y (remainder x y)))))
	   ((4 9)                               % int floatnum
	         (floatgcdn (staticintfloat x) y)) 
	   ((20 21)                             % floatnum int
	         (floatgcdn x (staticintfloat y)))
	   ((12)                                % fixnum fixnum
	         (sys2int (wgcdn (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13)                                % fixnum bignum
	         (gcdn x (remainder y x))) 
	   ((17)                                % bignum fixnum
	         (gcdn y (remainder x y)))
	   ((14)                                % fixnum floatnum
	         (floatgcdn (staticintfloat (fixval (fixinf x))) y))
	   ((18) (biggcdn x y))                 % bignum bignum
	   ((22)                                % floatnum fixnum
	         (floatgcdn x (staticintfloat (fixval (fixinf y)))))
	   ((19)                                % bignum floatnum
	         (floatgcdn  (floatfrombignum x) y))
	   ((23)                                % floatnum bignum
	         (floatgcdn x (floatfrombignum y)))
	   ((24)                                % floatnum floatnum 
	         (floatgcdn x y)) 
	   (nil      (nonnumber2error x y 'gcdn)))
))) 

(de wgcdn ( x y )
   (when (wlessp y 0) (setq y (wminus y)))
   (when (wlessp x 0) (setq x (wminus x)))
   (wgcdn-aux  x y))

(de wgcdn-aux ( x y ) % positive operands
   (cond ((eq 0 y) x)
	 ((wlessp x y) (wgcdn-aux y x))
	 (t (wgcdn-aux y (wremainder x y)))))
 
(de greaterp (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'greaterp)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                   tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0 6) (wgreaterp x y))              % same type ints
	   ((1)   NIL)                          % negint posint
	   ((5)   T)                            % posint negint
	   ((2 7)                               % int fixnum
	         (wgreaterp x (fixval (fixinf y)))) 
	   ((10 11)                             % fixnum int
	         (wgreaterp (fixval (fixinf x)) y))
	   ((3 8) (bminusp y))                  % int bignum
	   ((15 16) (not (bminusp x)))          % bignum int
	   ((4 9)                               % int floatnum
	         (floatgreaterp (staticintfloat x) y)) 
	   ((20 21)                             % floatnum int
	         (floatgreaterp x (staticintfloat y)))
	   ((12)                                % fixnum fixnum
	         (wgreaterp (fixval (fixinf x)) (fixval (fixinf y))))
	   ((13) (bminusp y))                   % fixnum bignum
	   ((17) (not (bminusp x)))             % bignum fixnum
	   ((14)                                % fixnum floatnum
	         (floatgreaterp (staticintfloat (fixval (fixinf x))) y)) 
	   ((18)                                % bignum bignum
	         (biggreaterp x y))
	   ((22)                                % floatnum fixnum
	         (floatgreaterp x (staticintfloat (fixval (fixinf y)))))
	   ((19)                                % bignum floatnum
	         (floatgreaterp  (floatfrombignum x) y))
	   ((23)                                % floatnum bignum
	         (floatgreaterp x (floatfrombignum y)))
	   ((24)                                % floatnum floatnum 
	         (floatgreaterp x y)) 
	   (nil      (nonnumber2error x y 'greaterp))) 
))) 

(de lessp (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'lessp)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                   tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0 6) (wlessp x y))                 % same type ints
	   ((1)   T)                            % negint posint
	   ((5)   NIL)                          % posint negint
	   ((2 7)                               % int fixnum
	         (wlessp x (fixval (fixinf y)))) 
	   ((10 11)                             % fixnum int
	         (wlessp (fixval (fixinf x)) y))
	   ((3 8) (not (bminusp y)))            % int bignum
	      
	   ((15 16) (bminusp x))                % bignum int
	   ((4 9)                               % int floatnum
	         (floatlessp (staticintfloat x) y)) 
	   ((20 21)                             % floatnum int
	         (floatlessp x (staticintfloat y)))
	   ((12)                                % fixnum fixnum
	         (wlessp (fixval (fixinf x)) (fixval (fixinf y))))
	   ((13) (not (bminusp y)))             % fixnum bignum
	   ((17) (bminusp x))                   % bignum fixnum
	   ((14)                                % fixnum floatnum
	         (floatlessp (staticintfloat (fixval (fixinf x))) y))
	   ((18) (biglessp x y))                % bignum bignum
	   ((22)                                % floatnum fixnum
	         (floatlessp x (staticintfloat (fixval (fixinf y)))))
	   ((19)                                % bignum floatnum
	         (floatlessp  (floatfrombignum x) y))
	   ((23)                                % floatnum bignum
	         (floatlessp x (floatfrombignum y)))
	   ((24)                                % floatnum floatnum 
	         (floatlessp x y)) 
	   (nil      (nonnumber2error x y 'lessp)))
)))

(de minus (x)
	(case (wand (wplus2 (tag x) 1) 31)  
           ((0 1) (isys2int (wminus x)))                  % posint negint
	   ((2)   (sys2int (wminus (fixval (fixinf x))))) % fixnum
	   ((3)   (bigminus x))                           % bignum
	   ((4)   (floatdifference '0.0 x))               %floatnum            
	   (nil   (nonnumber1error x 'minus))
)) 

(de add1 (x)
	(case (wand (wplus2 (tag x) 1) 31)  
	   ((0 1) (isys2int (wplus2 1 x)))                   % posint negint
	   ((2)   (sys2int (wplus2 1 (fixval (fixinf x))))) % fixnum
	   ((3)   (bigadd1 x))                              % bignum
	   ((4)   (floatplus2 '1.0 x))                      %floatnum            
	   (nil   (nonnumber1error x 'add1))
))
 
(de sub1 (x)
	(case (wand (wplus2 (tag x) 1) 31)  
	   ((0 1) (isys2int (wplus2 x -1)))                   % posint negint
	   ((2)   (sys2int (wplus2 -1 (fixval (fixinf x))))) % fixnum
	   ((3)   (bigsub1 x))                               % bignum
	   ((4)   (floatdifference x '1.0))                  %floatnum            
	   (nil   (nonnumber1error x 'sub1))
)) 

(de fix (x)
	(case (wand (wplus2 (tag x) 1) 31)  
	   ((0 1 2 3) x)                % posint negint fixnum bignum
	   ((4)   (floatfix x))               %floatnum            
	   (nil   (nonnumber1error x 'fix))
))

%(de floatfix (x)
%  (sys2int (**wfix x)))
% this disturbs nbig30a

 
(de float (x)
	(case (wand (wplus2 (tag x) 1) 31)  
	   ((0 1) (intfloat x))                 % posint negint
	   ((2)   (intfloat (fixval (fixinf x)))) % fixnum
	   ((3)   (floatfrombignum x))          % bignum
	   ((4)   x)                            %floatnum            
	   (nil   (nonnumber1error x 'float))
)) 

(de intfloat (n)
  (prog (fx ffff-tag)
        (setf ffff-tag (tag n))
        (setf n (inf n))        % this 'sport' is for GC!
        (setq fx (gtfltn))
        (*wfloat (floatbase fx) (mkitem ffff-tag n))
        (return (mkfltn fx))))
 

%
% The arithmetic predicates
%

(de minusp (x)
   (case (wand (wplus2 (tag x) 1) 31)  
	   ((0)   T)                              % negint
	   ((1)   NIL)                            % posint
	   ((2)   (wlessp (fixval (fixinf x)) 0)) % fixnum
	   ((3)   (bigminusp x))                  % bignum
	   ((4)   (floatlessp  x '0.0 ))            %floatnum            
	   (nil   NIL)
))

(de onep (x)
    % tagx is now in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
      (case (wand (wplus2 (tag x) 1) 31)  
	   ((0) NIL)             % negint 
	   ((1) (eq x 1))        % posint 
	   ((2) NIL)             % fixnum
	   ((3) NIL)             % bignum
	   ((4) (equal x  '1.0 ))%floatnum            
           (nil NIL)
))

(de zerop (x)
      (case (wand (wplus2 (tag x) 1) 31)  
	   ((0) NIL)             % negint 
	   ((1) (eq x 0))        % posint 
	   ((2) NIL)             % fixnum
	   ((3) NIL)             % bignum
	   ((4) (floatzerop x))  %floatnum            
	   (nil NIL)
))

(de floatzerop (x) (and  (eq 0 (wshift (wshift (wgetv (inf x) 1) 1) -1))
                         (eq 0 (wgetv (inf x) 2))))


%
% logical functions: land, lor, lxor, lnot
%

(de land (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'land)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                      tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0 1 5 6) (wand x y))               % int int
	   ((2 7)                               % int fixnum
	         (sys2int (wand x (fixval (fixinf y))))) 
	   ((10 11)                             % fixnum int
	         (sys2int (wand (fixval (fixinf x)) y)))
	   ((3 8)                               % int bignum
	         (bigland (sys2big x) y))
	   ((15 16)                             % bignum int
	         (bigland x (sys2big y)))
	   ((4 9)   (fdummy x y))               % int floatnum
	   ((20 21) (fdummy x y))               % floatnum int
	   ((12)                                % fixnum fixnum
	         (sys2int (wand (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13)                                % fixnum bignum
	         (bigland (sys2big (fixval (fixinf x))) y)) 
	   ((17)                                % bignum fixnum
	         (bigland x (sys2big (fixval (fixinf y)))))
	   ((14) (fdummy x y))                  % fixnum floatnum
	   ((18) (bigland x y))                 % bignum bignum
	   ((22) (fdummy x y))                  % floatnum fixnum
	   ((19) (fdummy x y))                  % bignum floatnum
	   ((23) (fdummy x y))                  % floatnum bignum
	   ((24) (fdummy x y))                  % floatnum floatnum 
	   (nil      (nonnumber2error x y 'land)))
))) 


(de lxor (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'lxor)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                      tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0 1 5 6) (wxor x y))               % int int
	   ((2 7)                               % int fixnum
	            (sys2int (wxor x (fixval (fixinf y))))) 
	   ((10 11)                             % fixnum int
	            (sys2int (wxor (fixval (fixinf x)) y)))
	   ((3 8)   (biglxor (sys2big x) y))    % int bignum
	   ((15 16) (biglxor x (sys2big y)))    % bignum int
	   ((4 9)   (fdummy x y))               % int floatnum
	   ((20 21) (fdummy x y))               % floatnum int
	   ((12)                                % fixnum fixnum
	            (sys2int (wxor (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13)                                % fixnum bignum
	            (biglxor (sys2big (fixval (fixinf x))) y)) 
	   ((17)                                % bignum fixnum
	            (biglxor x (sys2big (fixval (fixinf y)))))
	   ((14)    (fdummy x y))               % fixnum floatnum
	   ((18)    (biglxor x y))              % bignum bignum
	   ((22)    (fdummy x y))               % floatnum fixnum
	   ((19)    (fdummy x y))               % bignum floatnum
	   ((23)    (fdummy x y))               % floatnum bignum
	   ((24)    (fdummy x y))               % floatnum floatnum 
	   (nil     (nonnumber2error x y 'lxor)))
))) 

(de lor (x y)
     (prog (tagx tagy bothtags)
	(setq tagx (wand (wplus2 (tag x) 1) 31) 
	      tagy (wand (wplus2 (tag y) 1) 31))
    % tagx and tagy now are in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
       (when (wgreaterp tagy 4) (return (nonnumber2error x y 'lor)))
       (setq bothtags (wplus2 (wplus2 (wshift tagx 2) tagx) % its times 5
	                      tagy))   % 0 <= bothtags =< 186
       (return  
	 (case bothtags 
	   ((0 1 5 6) (wor x y))                % int int
	   ((2 7)                               % int fixnum
	            (sys2int (wor x (fixval (fixinf y))))) 
	   ((10 11)                             % fixnum int
	            (sys2int (wor (fixval (fixinf x)) y)))
	   ((3 8)   (biglor (sys2big x) y))     % int bignum
	   ((15 16) (biglor x (sys2big y)))     % bignum int
	   ((4 9)   (fdummy x y))               % int floatnum
	   ((20 21) (fdummy x y))               % floatnum int
	   ((12)                                % fixnum fixnum
	            (sys2int (wor (fixval (fixinf x)) (fixval (fixinf y)))))
	   ((13)                                % fixnum bignum
	            (biglor (sys2big (fixval (fixinf x))) y)) 
	   ((17)                                % bignum fixnum
	            (biglor x (sys2big (fixval (fixinf y)))))
	   ((14)    (fdummy x y))               % fixnum floatnum
	   ((18)    (biglor x y))               % bignum bignum
	   ((22)    (fdummy x y))               % floatnum fixnum
	   ((19)    (fdummy x y))               % bignum floatnum
	   ((23)    (fdummy x y))               % floatnum bignum
	   ((24)    (fdummy x y))               % floatnum floatnum 
	   (nil     (nonnumber2error x y 'lor)))
))) 

(de lnot (x)
    % tagx is now in the range of 0 (negint) and 31 (id)
    % numbers are 0...4
      (case (wand (wplus2 (tag x) 1) 31)
           ((0 1) (wnot x))      % negint posint
           ((2)   (sys2int (wnot (fixval (fixinf x)))))   % fixnum
           ((3)   (biglnot x))     % bignum
           ((4)   (fdummy1 x))     %floatnum
           (nil   (nonnumber1error x 'lnot))
))

%
% lshift is a very special case; will be treted by bignums arithmetic
% 
%%%(de lshift (x y) (wshift x y))   % until bignums are loade

(de noninteger2error (x y f)
  (continuableerror 99 "Non-integer argument in arithmetic"
                    (list f (mkquote x) (mkquote y))))

(de nonnumber1error (x f)
  (continuableerror 99 "Non-numeric argument in arithmetic"
                    (list f (mkquote x))))

(de nonnumber2error (x y f)
  (continuableerror 99 "Non-numeric argument in arithmetic"
                    (list f (mkquote x) (mkquote y))))

(de fdummy (x y) 
  (stderror "Fdummy should never be called"))

(de fdummy1 (x)
  (stderror "Fdummy should never be called"))

