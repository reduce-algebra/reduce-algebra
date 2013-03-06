%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:UXFLOAT.SL
% Title:          Floating point routines mapped to integer arithmetic
% Author:         Herbert Melenk
% Created:        11-Mar-90
% Modified:
% Mode:           Lisp
% Package:        Kernel
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 32-June-91 (H.Melenk)
% added functions for reusing boxes
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(**neg-zero** **neg-one**))

(compiletime
  (foreach f in 
    '(*wfloat *fplus2 *fdifference *ftimes2 *fquotient *fgreaterp
	  *flessp *wfix)
	  do (remprop f 'opencode) ))

(de *wfloat (x y)
  (uxfloat x y))

(de *fplus2 (x y z)
  (uxplus2 x y z))

(de *fdifference (x y z)
  (uxdifference x y z))

(de *ftimes2 (x y z)
  (uxtimes2 x y z))

(de *fquotient (x y z)
  (uxquotient x y z))

(de *fgreaterp (x y)
  (uxgreaterp x y 't 'nil))

(de *flessp (x y)
  (uxlessp x y 't 'nil))

(de *wfix (x)
  (uxfix x))

(de *fassign (x y)
  (uxassign x y))

(de *doubletofloat (x y)
  (uxdoubletofloat x y))

% These two statements must be at the end of the file because times2, and
% thus *ftimes2, must be defined before it is used.

% For DCM                                                                  
(de *floattodouble (x y)
  (uxfloattodouble x y))

% For DCM                                                                  

%
% this package assumes 32 bit words 
%
% data structure:
% numbers in IEEE double word (64 bit) format
% precision: 29 bits (2**28)


(compiletime 
  %(flag '(uxadd uxcompare uxmult uxquot1 uxresult) 'internalfunction)
   (define-constant IEEEzeroexp 28)
   (define-constant IEEEbias 1023)
   (flag '(ieeemant ieeeexpt) 'internalfunction)
   (ds floathighword (x) (floathighorder (wdifference  x 4)))
   (ds floatlowword (x) (floatloworder (wdifference  x 4)))
   (ds IEEEexpt(u) (wdifference (wand 2#11111111111 
           % select the exponent and reduce the bias
                                      (wshift (floatHighword u) -20)) 
                                 IEEEbias))
)

(fluid '(uxauxbox!* uxauxbox2!* floatprecision*))

(de IEEEmant (u)
          % select the mantissa and convert to a 29 bit number
    (prog (sig x)
      (setq x (floatHighword u))
	  (setq u (wshift (floatlowword u)(difference 8 32)))
      (when (eq x 0) (return 0))
      (setq sig (wshift x -31))
      (setq x (wor       16#100000
                  (wand   16#fffff
                           x)))
      (setq x (wor (wshift x 8) u))
      (return (if (weq sig 1) (wminus x) x))))

(setq uxauxbox!* (mkfltn (gtfltn )))
(setq uxauxbox2* (mkfltn (gtfltn )))

(de uxfloat (box u)
  (uxresult u IEEEzeroexp box))


(de uxfix (u)
 (let ((x (IEEEmant u))
       (y (wdifference (IEEEexpt u) IEEEzeroexp)))
   (cond ((wlessp y -31) 0)
         ((wgreaterp y 3) (stderror "float2fix: mantissa overflow")) 
         ((wgeq x 0) (wshift x y))
         (t (wminus (wshift (wminus x) y))))))

(de uxassign(u v)
    (setf (floatHighword u)  (floatHighword v))
    (setf (floatLowword u) (floatLowword v))
     u)

(de uxplus2 (box u v)
   (uxadd (IEEEmant u)(IEEEexpt u)
          (IEEEmant v)(IEEEexpt v)
          box))

(de uxdifference (box u v)
   (uxadd (IEEEmant u)(IEEEexpt u)
          (wminus(IEEEmant v))(IEEEexpt v)
          box))

(de uxminus (box u)
  (let ((b 1))
   (setq b (wshift b 31))
   (setf (floatHighword box) (wxor b (floatHighword u)))
   (setf (floatLowword box)  (floatLowword u))
    box))

(de uxtimes2 (box u v)
   (uxmult(IEEEmant u)(IEEEexpt u)
          (IEEEmant v)(IEEEexpt v)
           box))
 
(de uxquotient (box u v)
    % division: iterate over half precision division
   (prog (q delta bx bx2)
      (setq bx (wplus2 4 (inf uxauxbox*)))
	  (setq bx2 (wplus2 4 (inf uxauxbox2*)))
      (setq q (uxquot1 u v bx2))
      (setq delta (uxdifference bx (uxtimes2 bx v q) u))
      (setq delta (uxquot1 delta v delta))
      (setq q (uxdifference box q delta))
      (return q)))
 
(de uxgreaterp (u v dummy1 dummy1)
   (wgreaterp (uxcompare u v) 0))
 
(de uxlessp (u v dummy1 dummy1)
   (wlessp (uxcompare u v)0))



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  arithmetic
%

(de uxadd (m1 e1 m2 e2 box)
   % add (and subtract)
    (let ((d (wdifference e1 e2)))
       (cond ((wgreaterp d 0)
              (uxresult(wplus2 m1 (uxshift m2 (wminus d))) e1 box))
             ((wlessp d 0)
              (uxresult(wplus2 m2 (uxshift m1 d)) e2 box))
             (t(uxresult (wplus2 m1 m2) e1 box)))))

(de uxcompare (u v)
   % add (and subtract) and return mantissa only
   (prog (d m1 e1 m2 e2)
       (setq m1 (IEEEmant u) e1 (IEEEexpt u)
             m2 (IEEEmant v) e2 (IEEEexpt v))
       (setq d (wdifference e1 e2))
       (cond ((wgreaterp d 0)
              (return(wdifference m1 (uxshift m2 (wminus d)))))
             ((wlessp d 0)
              (return(wdifference (uxshift m1 d) m2)))
			 (t (return (wdifference m1 m2))))))

(de uxmult (m1 e1 m2 e2 box)
   % multiply
   (prog (minu m1r m2r a)
       (cond ((wlessp m1 0)
              (setq m1 (wminus m1))
              (setq minu t)))
       (cond ((wlessp m2 0)
              (setq m2 (wminus m2))
              (setq minu (not minu))))
       (setq m1r (wand m1 16#3fff))
       (setq m1 (wshift m1 -14))
       (setq m2r (wand m2 16#3fff))
       (setq m2 (wshift m2 -14))
       (setq a
           (wplus2(wtimes2 m1 m2)
                  (wshift
                      (wplus2 (wtimes2 m1 m2r)
                              (wtimes2 m1r m2))
                      -14)))
       (cond (minu (setq a (wminus a))))
       (return (uxresult a (wplus2 e1 e2) box)) ))


(de uxquot1 (u v box)
    % divison with half length divisor
   (prog (minu a m1 m2)
       (setq m1 (IEEEmant u))
       (setq m2 (IEEEmant v))
       (cond ((wlessp m1 0)
              (setq m1 (wminus m1))
              (setq minu t)))
       (cond ((wlessp m2 0)
              (setq m2 (wminus m2))
              (setq minu (not minu))))
       (setq m2 (wshift m2 -14))
       (setq a (wshift (wquotient m1 m2) 14))
       (cond (minu (setq a (wminus a))))
       (return (uxresult a (wdifference (IEEEexpt u)(IEEEexpt v)) box)) ))


(commentoutcode
(de uxresult(man exp box)
   % normalize number and put into box
  (cond ((weq man 0)
         (setf (floatHighword box) 0)
         (setf (floatLowword box) 0)
         box)
  (t
    (prog (minu x mant)
      (setq mant man)
      (cond ((wlessp mant 0)
             (setq minu t)
             (setq mant (wminus mant))))
      (when (not (weq (wshift mant -30) 0))
            (return (uxresult (wquotient man 2) (iadd1 exp) box)))
  loop
      (setq x (wshift mant -29))
      (cond ((not (weq x 0))
             (setq mant (wshift mant -1))
             (setq exp (wplus2 exp 1))
             (return (IEEEformat minu mant exp box))))
      (setq mant (wshift mant 1))
      (setq exp (wdifference exp 1))
      (go loop) ))))


(de uxresult(mant exp box)
   % normalize number and put into box
  (cond ((weq mant 0)
         (setf (floatHighword box) 0)
         (setf (floatLowword box) 0)
         box)
  (t
    (prog (minu x)
      (cond ((wlessp mant 0)
             (setq minu t)
             (setq mant (wminus mant))))
		 % scale such that bit 29 is 1,bits 30,31 are 0
      (while (not (weq (wshift mant -29) 0))
	         (setq mant (wshift mant -1))
			 (setq exp (iadd1 exp)))
      (while (weq (wshift mant -28) 0)
	         (setq mant (wshift mant 1))
			 (setq exp (isub1 exp)))
	    % mask to exactly 28 bits
	  (setq mant(wshift (wshift mant -1) 1))
      (return (IEEEformat minu mant exp box))))))
)


(lap'(
   (*ENTRY UXRESULT EXPR 3)
   (*JUMPNOTEQ (LABEL G0004) (REG 1) (QUOTE 0))
     (*MOVE (QUOTE 0) (MEMORY (REG 3) (WCONST 4)))
     (*MOVE (QUOTE 0) (MEMORY (REG 3) (WCONST 0)))
     (*MOVE (REG 3) (REG 1))
     (*exit 0)
   G0004
   (*MOVE (QUOTE NIL) (REG 5))
   (*JUMPWGEQ (LABEL G0007) (REG 1) (QUOTE 0))
     (*MOVE (QUOTE T) (reg 5))
     (*WMINUS (REG 1) (REG 1))
   G0007
   (*move (reg 1)(reg 4))
   (*WSHIFT (REG 4) (QUOTE -29))
   (*JUMPEQ (LABEL G0010) (REG 4) (QUOTE 0))
     (*WSHIFT (REG 1) (QUOTE -1))
     (*WPLUS2 (reg 2) (WCONST 1))
     (*JUMP (LABEL G0007))
   G0010
   (*move (reg 1)(reg 4))
   (*WSHIFT (REG 4) (QUOTE -28))
   (*JUMPnotEQ (LABEL G0015) (REG 4) (QUOTE 0))
     (*WSHIFT (REG 1) (QUOTE 1))
     (*WPLUS2 (reg 2) (WCONST -1))
     (*JUMP (LABEL G0010))
G0015
   (*WSHIFT (REG 1) (QUOTE -1))
   (*WSHIFT (REG 1) (QUOTE 1))
   (*move (reg 3)(reg 4))
   (*move (reg 2)(reg 3))
   (*move (reg 1)(reg 2))
   (*move (reg 5)(reg 1))
   (*LINKE 0 IEEEFORMAT EXPR 4)
   ))
(commentoutcode
(de IEEEformat(minu mant exp box)
   (setf (floatLowword box)  (wshift mant (difference 32 8)))
   (setq exp (wplus2 exp IEEEbias))
   (when (or (wlessp exp 0)
             (wgreaterp exp 2#011111111111))
         (return (stderror "floating point overflow")))
   (when minu (setq exp (wor exp 2#100000000000)))
   (setq exp (wshift exp 20))
   (setf (floatHighword box)
      (wor exp
           (wand 16#fffff (wshift mant -8 ))))
   (return box))
) %commentoutcode

(lap '(
   (*ENTRY IEEEFORMAT EXPR 4)
   (*alloc 0)
   (*MOVE (REG 2) (REG 5))
   (*WSHIFT (REG 5) (QUOTE 24))
   (*MOVE (REG 5) (MEMORY (REG 4) (WCONST 0)))

   (*move (reg 1)(reg 5))
   (*WPLUS2 (REG 3) (WCONST 1023))

   (*JUMPWLESSP (LABEL G0005) (REG 3) (QUOTE 0))
   (*JUMPWLEQ (LABEL G0003) (REG 3) (QUOTE 2047))
   (*LBL (LABEL G0005))
     (*MOVE (QUOTE "floating point overflow") (REG 1))
     (*LINKE 0 STDERROR EXPR 1)
   (*LBL (LABEL G0003))
   (*JUMPEQ (LABEL G0008) (reg 5) (QUOTE NIL))
     (*MOVE (WCONST 2048) (REG 1))
	 (*WOR (reg 3) (REG 1))
   (*LBL (LABEL G0008))
   (*WSHIFT (reg 3) (QUOTE 20))
   (*WSHIFT (REG 2) (QUOTE -8))
   (*WAND (REG 2) (WCONST 1048575))
   (*WOR (REG 2) (REG 3))
   (*MOVE (REG 2) (MEMORY (REG 4) (WCONST 4)))
   (*MOVE (REG 4) (REG 1))
   (*EXIT 0)
))

(de uxshift (u n)
   % arithmetic shift
    (cond ((wlessp n -31) 0)    % completely shifted out
          ((wlessp u 0) (wminus (wshift (wminus u) n)))
          (t (wshift u n))))

(loadtime (progn
            (setq **neg-one** -1.0)
            (setq **neg-zero** (times2 **neg-one** 0.0))))
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%    routines reusing the box of their 1st argument for the result

(de ==ipplus2(u v)
    (let ((ub (floatbase (fltinf u)))
          (vb (floatbase (fltinf v))))
        (*fplus2 ub ub vb)
       u))

(de ==ipdifference(u v)
    (let ((ub (floatbase (fltinf u)))
          (vb (floatbase (fltinf v))))
        (*fdifference ub ub vb)
       u))

(de ==ipquotient(u v)
       (let ((ub (floatbase (fltinf u)))
             (vb (floatbase (fltinf v))))
          (*fquotient ub ub vb)
        u))

(de ==iptimes2(u v)
       (let ((ub (floatbase (fltinf u)))
             (vb (floatbase (fltinf v))))
          (*ftimes2 ub ub vb)
        u))

%  reverse functions, reusing 2nd box

(de ==ipplus2r(u v)
    (let ((ub (floatbase (fltinf u)))
          (vb (floatbase (fltinf v))))
        (*fplus2 vb ub vb)
       v))

(de ==ipdifferencer(u v)
    (let ((ub (floatbase (fltinf u)))
          (vb (floatbase (fltinf v))))
        (*fdifference vb ub vb)
       v))

(de ==ipquotientr(u v)
       (let ((ub (floatbase (fltinf u)))
             (vb (floatbase (fltinf v))))
          (*fquotient vb ub vb)
        v))

(de ==iptimes2r(u v)
       (let ((ub (floatbase (fltinf u)))
             (vb (floatbase (fltinf v))))
          (*ftimes2 vb ub vb)
        v))

(de ==newbox(u)
     (let*((bn (gtfltn))
	       (bu (fltinf u)))
		(setf (wgetv bn 0)(wgetv bu 0))
		(setf (wgetv bn 1)(wgetv bu 1))
		(setf (wgetv bn 2)(wgetv bu 2))
		(mkfltn bn)))
