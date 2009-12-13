%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU: btimes32.sl
% Description:  karatsuba multiply as part of bignum package     
% Author:       H. Melenk
% Created:      22 Sep 1993
% Modified:     
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Experimental 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% see : R. Maeder, DISCO'93, p 59 ff

% to be compiled as part of NBIG32a.sl

(compiletime (flag '(
            multiplyinto
	    multiplyintodigit romanclear copyto addto subfrom
           newkaratsuba newkaratsubaw newkaratsuba1 newkaratsuba
    ) 'internalfunction))


(compiletime (progn

  (if_system HP-RISC (define-constant *karatsubabound* 17))
  (if_system I386    (define-constant *karatsubabound* 10))
  (if_system MIPS    (define-constant *karatsubabound* 17))
  (if_system SPARC   (define-constant *karatsubabound* 10))
  (if_system ALPHA   (define-constant *karatsubabound* 14))

  (when bigtest (remprop '*karatsubabound* 'CONSTANT?))

  (dm set-karatsuba(u)
     (if (get '*karatsubabound* 'CONSTANT?)
         nil
         `(progn
             (fluid '(*karatsubabound*))
             (setq *karatsubabound* 11) )))

))

(set-karatsuba)

%--------------- local macros --------------------------------------

(compiletime
  (put 'cleanloop 'opencode '(
  clean-loop
    (*jumpwgreaterp (label clean-done)(reg 1)(reg 2))
    (*move 0 (memory (reg 3) 0))
    (*wplus2 (reg 3) addressingunitsperitem)
    (*wplus2 (reg 1) 1)
    (*jump (label clean-loop))
  clean-done
)))

(compiletime (progn
   (ds *2 (a) (wshift a 1))
   (ds /2 (a) (wshift a -1))
))

%--------------- main entry point ---------------------------------

(de btimes2 (u v)
 % Karatsuba dispatch routine.
  (prog (lu lv lw snu snv w n m p)
    (setq lu (bbsize u)) (setq lv (bbsize v))
      % ensure that u is the longer number.
    (when (igreaterp lv lu) (setq w u) (setq u v) (setq v w)
                            (setq lw lu) (setq lu lv) (setq lv lw))

      % result vector. 
    (setq n (iadd1 (wplus2 lu lv)))
    (setq p (if (eq (igetv u 0)(igetv v 0))
                (gtpos n) (gtneg n)))
    (cleanloop 1 n (loc (igetv p 1)))

      % below Karatsuba limit?
    (when (wleq lv *karatsubabound*)
      (multiplyinto (loc (igetv u 1)) (loc (igetv v 1)) (loc (igetv p 1))
         (bbsize u) (bbsize v))
      (go done))

      % find auxiliary storage, best in BPS. 
    (setq m (newkaratsubaw lu))
    (setq w
      (if (wgreaterp
            (wdifference lastbps nextbps)
            (wtimes2 m addressingunitsperitem))
          nextbps
          (loc (igetv (gtpos m) 0))))

    (newkaratsuba(loc (igetv u 1)) (loc (igetv v 1)) (loc (igetv p 1))
         (loc (igetv w 1)) (bbsize u) (bbsize v))
 done
    (setq *second-value* 0)
    (return (trimbignum p n))))

(compiletime 
  (ds offset(a b)
    (wplus2 a (wtimes2 b addressingunitsperitem))))

(de multiplyinto(a b c la lb)
 (let (mem_b)
     (setq carry* 0)
     (while (igreaterp lb 0)
         (setq mem_b (getmem b))
         (if (izerop mem_b) c (multiplyintodigit a la mem_b c))
         (setq b (wplus2 b addressingunitsperitem))
         (setq c (wplus2 c addressingunitsperitem))
         (setq lb (isub1 lb))
     )
     (setq *second-value* 0)  % 01-Nov-94
))

(de multiplyintodigit (a l dig c)
  %(if (izerop dig) c
   (prog (carry w temp1 t2)
      (setq carry 0)
      (while (igreaterp l 0)
           (setq temp1 (wtimesdouble (getmem a) dig))
           (setq w (+x+c temp1 carry))
           (putmem c (+x+c w (getmem c)))
           (setq carry *second-value*)
           (setq a (wplus2 a addressingunitsperitem))
           (setq c (wplus2 c addressingunitsperitem))
           (setq l (isub1 l))
          )
      (putmem c (+c carry (getmem c)))
      (while (not (eq carry* 0))
             (setq c (wplus2 c addressingunitsperitem))
             (putmem c (+c 0 (getmem c))))
    %%  (setq *second-value* 0)  % 01-Nov-94
)))

(de romanclear(a l)
   (while (igreaterp l 0)
      (putmem a 0)
      (setq a (wplus2 a addressingunitsperitem))
      (setq l (isub1 l))))

(de copyto(a b l)
   (while (igreaterp l 0)
      (putmem a (getmem b))
      (setq a (wplus2 a addressingunitsperitem))
      (setq b (wplus2 b addressingunitsperitem))
      (setq l (isub1 l))))

(de addto(a b l)
  % a + b -> a
   (setq carry* 0)
    (while (igreaterp l 0)
      (putmem a (+c (getmem a)(getmem b)))
      (setq a (wplus2 a addressingunitsperitem))
      (setq b (wplus2 b addressingunitsperitem))
      (setq l (isub1 l)))
    (while (not (eq carry* 0))
      (putmem a (+c (getmem a) 0))
      (setq a (wplus2 a addressingunitsperitem))))

(de subfrom(a b l)
   (setq carry* 0)
    (while (igreaterp l 0)
      (putmem a (-c (getmem a)(getmem b)))
      (setq a (wplus2 a addressingunitsperitem))
      (setq b (wplus2 b addressingunitsperitem))
      (setq l (isub1 l)))
    (while (not (eq carry* 0))
      (putmem a (-c (getmem a) 0))
      (setq a (wplus2 a addressingunitsperitem))))

(de newkaratsubaw(n)

  % compute size of needed auxilary memory.
   (if (wleq n *karatsubabound*) 0
       (+w (newkaratsubaw (iadd1 (wshift (iadd1 n) -1)))
           (wshift (iadd1 (wshift (iadd1 n) -1))1 ))))

(de newkaratsuba1(a b c w laa lbb)
  % Karatsuba multiply: add the product of a and b to c.
  % here *karatsubabound* < la and la/2 < lb <= la
  (prog(m m1 mm lt la lb)
   (setq la laa)
   (setq lb lbb)
   (setq m (/2 (iadd1 la) )) % (la+1)/2
   (setq m1 (iadd1 m) mm (iplus2 m m))
   (copyto w a m)                                  % alow
   (putmem (offset w m) 0)
   (addto w (offset a m) (-w la m))                % alow + ahigh
   (copyto (offset w  m1) b m)                % blow
   (putmem (offset w (+w m m1)) 0)
   (addto (offset w m1) (offset b m) (-w lb m)) % blow + bhigh
             % (alow+ahigh)*(blow+bhigh) -> c(m)
   (newkaratsuba w (offset w m1) (offset c m)
                   (offset w (*2 m1)) m1 m1)
   (setq lt (+w (-w la m) (iadd1 (-w lb m))))
   (romanclear w lt)
     % compute ah*bh into w0,...
   (newkaratsuba (offset a m)(offset b m) w (offset w lt)
                 (-w la m) (-w lb m))
   (setq lt (+w (-w la m)(-w lb m)))
   (addto (offset c mm) w lt)
   (subfrom (offset c m) w lt)
   (setq lt (+w m m1))
   (romanclear w lt)
    % compute al*bl into w0,...
   (newkaratsuba a b w (offset w lt) m m)
   (addto c w mm)
   (subfrom (offset c m) w mm)
))

(de newkaratsuba(a b c w laa lbb)
  % add the product of a and b to c.
(let ((la laa) (lb lbb))
 (cond 
  ((wleq lb *karatsubabound*) (multiplyinto a b c la lb))
  ((wgreaterp lb (/2 (iadd1 la))) (newkaratsuba1 a b c w la lb))
  (t
           % lb < la/2: subdivide a into pieces of length lb
           % add the shifted products with b into c
   (let ((j 0) ld)
    (while (wlessp j la)
     (setq ld (idifference la j))
     (if (wgeq ld lb) 
         (progn (setq ld lb)
                (newkaratsuba1 b (offset a j) (offset c j) w lb ld))
         (newkaratsuba b (offset a j) (offset c j) w lb ld))
     (setq j (wplus2 j lb))
    )
)))))
    
(commentoutcode
(de kprint(txt a n)
 (prog(l)
  (prin2 txt)
  (while (greaterp n 0)
         (setq l (cons (sys2int  (getmem a)) l))
         (setq n (sub1 n))
         (setq a (wplus2 a addressingunitsperitem)))
  (foreach x in l do (progn(prin2 x)(prin2 " ")))
  (terpri)))
)

(commentoutcode

% for time fine tuning

(null (setq b (expt 3 40000)))

(for (from k 5 30 1)
     (do
       (setq *karatsubabound* k)
       (setq t1 (time))
       (times b b)
       (print (list k (difference (time) t1)))))

on time;
aa := factorial 20000$
bb := factorial 30000$

aa * bb $
)

