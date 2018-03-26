% This file contains a mixture of two sorts of things:

% (A) PSL functions that are not defined in the files that I will
%     load to make myself a compiler, but that are required.
%
% (B) Replacements for some things that are defined in the compiler-related
%     sources but where the definitions are sufficiently PSL-specific that
%     I need to introduce my own replacements if I am to survive using some
%     alternative Lisp for bootstrapping.
%
% I hope that every function (and macro) defined here ends up flagged
% as 'lose so that a subsequent apparent definition in a PSL file that I
% process does not override it.


% At least for bootstrapping I need to restore MY version of SPACES
(de spaces (n)                 % Print n blanks.
   (cond
      ((zerop n) nil)
      (t (princ " ") (spaces (sub1 n)))))

(de intp (x) (and (fixp x) (not (bignump x))))

(flag '(spaces intp) 'lose)

(de flag1 (x y) (flag (list x) y))

(de remflag1 (x y) (remflag (list x) y))

(dm control (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))
(dm cntrl (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))

(de continuableerror (errnum message errorform*)
  (progn (errorprintf "***** %l" message)))

(de main ())

(flag '(flag1 remflag1 control cntrl continuableerror main) 'lose)

% Now the things just needed for creating fasl files... I will add things in
% here to start with and maybe move them to psl-support-2.lsp later...

(de concat (a b) (string-concat a b))

(de binarywrite (stream val)
   (prog (of n)
      (setq of (wrs stream))
      (prinbyte (setq n (land val 0xff)))
      (setq val (lshift (difference val n) -8))
      (prinbyte (setq n (land val 0xff)))
      (setq val (lshift (difference val n) -8))
      (prinbyte (setq n (land val 0xff)))
      (setq val (lshift (difference val n) -8))
      (prinbyte (setq n (land val 0xff)))
      (setq val (lshift (difference val n) -8))
      (prinbyte (setq n (land val 0xff)))
      (setq val (lshift (difference val n) -8))
      (prinbyte (setq n (land val 0xff)))
      (setq val (lshift (difference val n) -8))
      (prinbyte (setq n (land val 0xff)))
      (setq val (lshift (difference val n) -8))
      (prinbyte (setq n (land val 0xff)))
      (wrs of)))

(de binarywritebyte (stream val)
   (prog (of)
      (setq of (wrs stream))
      (prinbyte (land val 0xff))
      (wrs of)))

(flag '(concat binarywrite binarywritebyte) 'lose)

% I will simulate byte vectors using vectors of 64-bit integers, and here
% I will pack the bytes little-endian. Note that the implementation here
% requires that the Lisp used for bootstrapping can work with full 64-bit
% integers.

(de byte (v n)
  (prog (o s)
     (setq n (plus2 v n))
     (setq o (irsh n 3))
     (setq s (itimes2 (iland n 7) 8))
     (return (iland 16#ff (irsh (getv memory o) s)))))

(de putbyte (v n val)
  (prog (o s w)
     (setq n (plus2 v n))
     (setq o (irsh n 3))
     (setq s (itimes (iland n 7) 8))
     (setq w (getv memory o))
     (setq m (difference 16#ffffffffffffffff (lsh 16#ff s)))
     (setq w (land w m))
     (setq w (lor w (ilsh val s)))
     (putv memory o w)
     (return val)))

(flag '(byte putbyte) 'lose)

% Now similar for halfwords (16 bits)

(de halfword (v n)
  (prog (o s)
     (setq n (plus2 (irsh v 1) n))
     (setq o (irsh n 2))
     (setq s (itimes2 (iland n 3) 16))
     (return (iland 16#ffff (irsh (getv memory o) s)))))

(de puthalfword (v n val)
  (prog (o s w)
     (setq n (plus2 (irsh v 1) n))
     (setq o (irsh n 2))
     (setq s (itimes (iland n 3) 16))
     (setq w (getv memory o))
     (setq m (difference 16#ffffffffffffffff (lsh 16#ffff s)))
     (setq w (land w m))
     (setq w (lor w (lsh val s)))
     (putv memory o w)
     (return val)))

(de put_a_halfword (addr val)
  (puthalfword addr 0 val))

(flag '(halfword puthalfword put_a_halfword) 'lose)

% ... and 32-bit words

(de word (v n)
  (prog (o s)
     (setq n (plus2 (irsh v 2) n))
     (setq o (irsh n 1))
     (setq s (itimes2 (iland n 1) 32))
     (return (land 16#ffffffff (rsh (getv memory o) s)))))

(de putword (v n val)
  (prog (o s w)
     (setq n (plus2 (irsh v 2) n))
     (setq o (irsh n 1))
     (setq s (itimes (iland n 1) 32))
     (setq w (getv memory o))
     (setq m (difference 16#ffffffffffffffff (lsh 16#ffffffff s)))
     (setq w (iland w m))
     (setq w (ilor w (ilsh val s)))
     (putv memory o w)
     (return val)))

(flag '(word putword) 'lose)

% And finally 64-bit items
% I force the retrieved value to be positive.

(de wgetv (v n)
   (land (getv memory (plus2 (irsh v 3) n)) 16#ffffffffffffffff))

(de wputv (v n val)
   (putv memory (plus2 (irsh v 3) n) val))

(flag '(wgetv wputv) 'lose)

(de known-free-space ()
  (mkint (wquotient (wdifference heapupperbound heaplast) 
                    addressingunitsperitem)))

(de free-bps ()
  (wquotient (wdifference lastbps nextbps) 
	     addressingunitsperitem)
  )


(flag '(known-free-space free-bps) 'lose)

(de gtheap (number-of-items)
  % Allocates heap space.  As soon as all uses of (GTHEAP NIL) are
  % removed from code, this function can be removed, and REAL-GTHEAP
  % can become GTHEAP.
  (if (null number-of-items)
    (known-free-space)
    (real-gtheap number-of-items)
    )
  )


(de real-gtheap (number-of-items)
  % This function handles the normal case where there is no trap handling
  % to be done.  It is written so that no stack frame is allocated, which
  % vastly improves performance (at least on the 68000).
  (let ((result heaplast))
    (setf heaplast (wplus2 heaplast (wtimes2 number-of-items
                                             addressingunitsperitem)))
    (if (wlessp heaplast heaptrapbound)
      result
      (error "out of heap"))))

(de delheap (lowpointer highpointer)
  (when (weq highpointer heaplast)
    (setq heaplast lowpointer)))

%(de gtstr (upper-bound)
%  % Allocate a string of UPPER-BOUND+1 characters.
%  (let* ((n-words  (strpack upper-bound))
%	 (str      (gtheap (+ 1 n-words))))
%    (setf (getmem str) (mkitem hbytes-tag upper-bound))
%    (setf (wgetv str n-words) 0)  % clear last word, including last byte
%    str
%    ))

(de gtstr (upper-bound)
  % Allocate a string of UPPER-BOUND+1 characters.
  (let* ((n-words  (strpack upper-bound))
	 (str      (gtheap (+ 1 n-words))))
    (wputv str 0 (mkitem hbytes-tag upper-bound))
    (wputv str n-words 0)  % clear last word, including last byte
    str
    ))


% GTCONSTSTR is defined in the kernel

%(de gthalfwords (upper-bound)
%  % Allocate space for a halfwords vector of UPPER-BOUND+1 elements.
%  (let* ((n-words  (halfwordpack upper-bound))
%	 (ptr      (gtheap (+ n-words 1))))
%    (setf (getmem ptr) (mkitem hhalfwords-tag upper-bound))
%    ptr
%    ))

(de gthalfwords (upper-bound)
  % Allocate space for a halfwords vector of UPPER-BOUND+1 elements.
  (let* ((n-words  (halfwordpack upper-bound))
	 (ptr      (gtheap (+ n-words 1))))
    (wputv ptr 0 (mkitem hhalfwords-tag upper-bound))
    ptr
    ))

%(de gtvect (upper-bound)
%  % Allocate space for a vector of UPPER-BOUND+1 elements.
%  (let ((ptr  (gtheap (+ (vectpack upper-bound) 1))))
%    (setf (getmem ptr) (mkitem hvect-tag upper-bound))
%    ptr
%    ))

(de gtvect (upper-bound)
  % Allocate space for a vector of UPPER-BOUND+1 elements.
  (let ((ptr  (gtheap (+ (vectpack upper-bound) 1))))
    (wputv ptr 0 (mkitem hvect-tag upper-bound))
    ptr
    ))

%(de gtevect (upper-bound)
%  % Allocate space for an evector of UPPER-BOUND+1 elements.
%  (let ((ptr  (gtheap (+ (evectpack upper-bound) 1))))
%    (setf (getmem ptr) (mkitem hvect-tag upper-bound))
%    ptr
%    ))

(de gtevect (upper-bound)
  % Allocate space for an evector of UPPER-BOUND+1 elements.
  (let ((ptr  (gtheap (+ (evectpack upper-bound) 1))))
    (wputv ptr 0 (mkitem hvect-tag upper-bound))
    ptr
    ))

%(de gtcontext ()
%  % allocate space for an environment descriptor (7 entries)
%  (let ((ptr (gtheap (+ (contextpack) 1))))
%    (setf (getmem ptr) (mkitem hvect-tag (contextpack)))
%    ptr))

(de gtcontext ()
  % allocate space for an environment descriptor (7 entries)
  (let ((ptr (gtheap (+ (contextpack) 1))))
    (wputv ptr 0 (mkitem hvect-tag (contextpack)))
    ptr))

%(de gtbvect (upper-bound)
%  % allocate space for a bvector - four words per entry
%  (let ((ptr (gtheap (+ (bvectpack upper-bound) 1))))
%    (setf (getmem ptr) (mkitem hvect-tag (bvectpack upper-bound)))
%    ptr))

(de gtbvect (upper-bound)
  % allocate space for a bvector - four words per entry
  (let ((ptr (gtheap (+ (bvectpack upper-bound) 1))))
    (wputv ptr 0 (mkitem hvect-tag (bvectpack upper-bound)))
    ptr))

% GTWRDS is defined in the kernel

%(de gtfixn ()
%  % Allocate space for a fixnum.
%  (let ((ptr  (gtheap (+ (fixpack) 1))))
%    (setf (getmem ptr) (mkitem hwords-tag (- (fixpack) 1)))
%    ptr
%    ))

(de gtfixn ()
  % Allocate space for a fixnum.
  (let ((ptr  (gtheap (+ (fixpack) 1))))
    (wputv ptr 0 (mkitem hwords-tag (- (fixpack) 1)))
    ptr
    ))

(de gtfltn ()
  % Allocate space for a floating point number on a double-word boundary.
  (let ((x (gtheap 0))
	ptr)
    (if (neq (remainder x 8) 4)
	(gtheap 1))
    (setf ptr  (gtheap (+ (floatpack) 1)))
    (setf (getmem ptr) (mkitem hwords-tag (- (floatpack) 1)))
    ptr
    ))


% GTID is defined in the kernel.

% GTBPS is defined in the kernel.

%% Attempt to allocate more bps space at the end of the image by calling
%% external-allocatemorebps. Warn user and set fluid so we can head off
%% an unexec.
%%
(de try-other-bps-spaces (number-of-items)
  (let ((morebps (external-allocatemorebps)))
    (when (wgreaterp morebps 0)
      (printf "Warning, allocating additional bps space of %w items.%n"
	      (quotient morebps 4))
      (printf "  Cannot savesystem after allocating additional bps space.%n")
      (setq using-other-bps-spaces* t))))

% Return space to BPS, but make sure that nextbps will not intrude down into
%  the heap, as might be the case after calling try-other-bps-spaces.
(de delbps (bottom top)
  (when (and (weq nextbps top)
	     (wgreaterp bottom bpslowerbound))
    (setq nextbps bottom)))

(de gtwarray (n)
  %. Allocate N words for WVar/WArray/WString                              
  (if (null n)
    (wquotient (wdifference lastbps nextbps) 
	       addressingunitsperitem)
    (let ((b (wdifference lastbps (wtimes2 n addressingunitsperitem))))
      (if (wgreaterp nextbps b)
	(stderror '"Ran out of WArray space")
	(setq lastbps b))
      )))

(de delwarray (bottom top)
  %. Return space for WArray                                               
  (when (weq lastbps bottom)
    (setq lastbps top)))

(de allocatefaslspaces ()
  (prog (b)
    (setq b (gtwarray nil))
    % how much is left?
    (setq b (idifference b (iquotient b 3)))
    (setq faslblockend* (gtwarray 0))
    % pointer to top of space
    (setq bittablebase* (gtwarray b))
    % take 2/3 of whatever's left
    (setq currentoffset* 0)
    (setq bittableoffset* 0)

% The "loc" here seems to be much like the C use of "&" to grab an
% address. Well (loc (wgetv a n)) might be rather like (plus a n) but
% in the end I will need to worry about byte vs word addressing.

%    (setq codebase*
%      (loc (wgetv bittablebase* % split the space between
%                  (iquotient b % bit table and code
%                             (iquotient bittable-entries-per-word
%                                        addressingunitsperitem)))))
% Here is a first-try re-work.
    (setq codebase*
      (plus bittablebase* % split the space between
                  (iquotient b % bit table and code
                             (iquotient bittable-entries-per-word
                                        addressingunitsperitem))))

    (setq maxfasloffset* (idifference faslblockend* codebase*))
    (setq orderedidlist* (cons nil nil))
    (setq nextidnumber* first-local-id-number)))

% This mess yields a value in the range 0 to 127 for symbols that are
% 1 character long if that character has ASCII code in the range 0 to 127.
% I also force nil to yield 128. For other symbols I return 256 and hope that
% the only call to this is from findidnumber!

(setq **nil-id-value** 128)

(de idinf (u)
   (cond ((null u) **nil-is-value**)
         ((cdr (explodec u)) 256)
         (t (char-code u))))


% been inserted early, and a simple redefinition of idinf was thus
% ineffective.

(de findidnumber (u)
  (prog (i)
        (return (cond ((ileq (setq i (idinf u)) 128) i)
                      ((setq i (get u fasl-idnumber-property*)) i)
                      (t (put u fasl-idnumber-property* (setq i nextidnumber*))
                         (setq orderedidlist* (tconc orderedidlist* u))
                         (setq nextidnumber* (iadd1 nextidnumber*)) i)))))

% OK, I am reconstructing my understanding by inspecting the code here..
% this makes relocation information as 2 bits of tag within a 16, 32 or
% 64 bit item, with the relocinf in the rest. Well in a 64-bit item
% the tag has space for 10 bits. I think that is probably because it is in
% the top 8 bits of where a fixnum could go, leaving the high 8 bits for the
% tag that PSL uses for identifying sorts of data.
%
%(de makerelocword (reloctag relocinf)
%  (iplus2 (ilsh reloctag 30) (ilsh (ilsh relocinf 2) -2)))

(de makerelocword (reloctag relocinf)
  (plus (lsh reloctag 30) (land relocinf 16#3fffffff)))

% My belief is that the "54" here is so that there can be 2 bits of tag
% just below where there would be 8 bits of PSL tag in a PSL finum. Now
% on a 32-bit system one might still imagine 8 bits of PSL tag and 2 bits
% of relocation-type tag leaving 22 bits for the real information in a
% relocation word. However on a 64-bit system with the PSL tag in bits
% 56-63 and the relocation tag in bits 54 and 55 that leaves 54 rather then
% 22 bits for useful purposes. So my suspicion is that somebody was not
% thinking things fully through when they adapted this bit of code...

%(de makerelocinf (reloctag relocinf)
%  (iplus2 (ilsh reloctag 54) (field relocinf 42 22)))

(de makerelocinf (reloctag relocinf)
  (plus2 (lsh reloctag 54) (land relocinf 16#003fffffffffffff)))

% For a word the stored inf just loses the top 2 bits of the inf to
% leave 30 bits.
% For the "inf" case it keeps the low 22 (or matbe 54!) bits of 64
% For the halfword case I suspect it is keeping the bottom 14 bits of 32. On
% a 64-bit system this feels like the low 14 bits up the upper 32 bits of the
% word ???????? So I will comment this out and expect that on a 64-it
% target it is never used - if it is I will need to think harder.

% (de makerelochalfword (reloctag relocinf)
%  (iplus2 (ilsh reloctag 14) (field relocinf 18 14)))

% I think that the use if "field" here is not at all a help as regards
% clarity! Simpler use of shift and mask operations will leave things
% easier to understand!


% (de getbittable (baseaddress bitoffset)
%   (field (ilsh (byte baseaddress (ilsh bitoffset -2))
%                (idifference (itimes2 (field bitoffset 62 2) 2) 6))
%          62 2))
%
% (de putbittable (baseaddress bitoffset value2)
%   (prog (m b c)
%         (setq b
%               (iland (byte baseaddress (setq m (ilsh bitoffset -2)))
%                      (ilsh (idifference -1 (itimes2 3 256))
%                       (idifference -2
%                        (setq c (itimes2 (field bitoffset 62 2) 2))))))
%         (putbyte baseaddress m (if (eq value2 0)
%                    b
%                    (ilor b (ilsh value2 (idifference 6 c)))))))

% getbittable(base, offset) =
%    w = byte(base, offset/4);   % 4 bitpairs per byte
%    n = offset & 3;
%    return (w >> (2*n)) & 3

% I will find bits of this code look way neater if I have a right
% shift operator as well as a left shift one.

(de rsh (w n) (lsh w (iminus n)))
(de irsh (w n) (ilsh w (iminus n)))

% I am writing these out as sequences of operations and avoiding
% use of the PSL "field" selector because I believe that what I have here
% is much easier for me to read and understand.

(de getbittable (baseaddress bitoffset)
  (prog (o b s)
     (setq o (irsh bitoffset 2))   % 4 nybbles in each byte
     (setq b (byte baseaddress o)) % the byte with data in
     (setq s (itimes 2 (iland bitoffset 3))) % bit position
     (setq s (idifference 6 s))    % make big-endian
     (return (iland (irsh b s) 3))))

(de putbittable (baseaddress bitoffset value2)
  (prog (o b m s)
     (setq o (irsh bitoffset 2))   % address of relevant byte
     (setq b (byte baseaddress o)) % byte to work within
     (setq s (itimes 2 (iland bitoffset 3))) % position within byte
     (setq s (idifference 6 s))    % make big-endian
     (setq m (idifference 16#ff (ilsh 3 s))) % mask
     (setq b (iland b m))           % Clear existing
     (setq b (ilor b (ilsh value2 s)))
     (putbyte baseaddress o b)))

% Maybe somebody needed to work out what name they were using...
(de bittable (a b) (getbittable a b))

(de mapobl (ff)
   (mapc (oblist) ff))

(de binarywriteblock (stream vec len)
  (prog (o b i)
    (setq o (wrs stream))
    (setq i 0)
    (setq len (times len 8)) % length is given in WORDS
 top(cond
      ((not (lessp i len)) (go done)))
    (prinbyte (byte vec i))
    (setq i (add1 i))
    (go top)
 done
    (wrs o)))

(de mkstring (bound fill)
  (prog (s)
    (setq s (gtstr bound))
    (dotimes (i (add1 bound))
             (putbyte s i fill))
    (return (mkstr s))))

% I think that PSL made a mistake when it defined FIELD to count bits
% from the most significant, because that puts implicit information about
% whether we are thinking of a 32 or 64 bit system within it.

(de field (x start length)
   (prog ()
      (setq x (rsh x (difference 64 (plus start length))))
      (return (land x (sub1 (lsh 1 length))))))

(flag '(gtheap real-gtheap delheap gtstr gthalfwords gtvect
        gtevect gtcontext gtbvect gtfixn gtfltn try-other-bps-spaces
        delbps gtwarray delwarray allocatefaslspaces isinf
        findidnumber makerelocword makerelocinf makerelochalfword
        lsh rsh getbittable putbittable bittable mapobl
        binarywriteblock mkstring field) 'lose)


(de stderror (msg)
  (error 99 msg))

(de exitlisp () (stop 0))

% copyd is invoked (botimes ..) within the for-macro.sl source file,
% but easy-non-sl.sl uses some macros defined in for-macro. To break the
% circularity I define copyd here.

(de copyd (new old)
  (prog (olddef)
        (setq olddef (getd old))
        (if (pairp olddef)
          (putd new (car olddef) (cdr olddef))
          (stderror (bldmsg "%r has no definition in CopyD" old)))
        (return new)))

(dm defun (u) (cons 'de (cdr u)))

(de codep (u) nil)

(de ncons (u) (cons u nil))

(de posintp (n) (and (fixp n) (geq n 0)))

(dm errorprintf (u)
  (list 'errorprintf1 (cadr u) (cons 'list (cddr u))))

(de errorprintf1 (fmt args)
  (terpri)
  (printf_internal fmt args)
  nil) 

(de remob (u)
  (terpri)
  (princ "+++ REMOB not performed on ")
  (print u)
  u)

% This definition of totalcopy is probably insufficient...
(de totalcopy (x)
  (copy x))

% This definition is from nonkernel/loop-macros.sl, but that file contains
% a definition of FOR that clashes with the version that I seem to need (which
% is in util/for-macro.sl).

(dm foreach (u)
  %. Macro for MAP functions
  %
  % From RLISP
  %
  % Possible forms are:
  % (foreach x in u do (foo x))	   --> (mapc u (function (lambda (x) (foo x))))

  % (foreach x in u collect (foo x)) --> (mapcar u ...)
  % (foreach x in u conc (foo x))	   --> (mapcan u ...)
  % (foreach x in u join (foo x))	   --> (mapcan u ...)
  % (foreach x on u do (foo x))	   --> (map u ...)
  % (foreach x on u collect (foo u)) --> (maplist u ...)
  % (foreach x on u conc (foo x))	   --> (mapcon u ...)
  % (foreach x on u join (foo x))	   --> (mapcon u ...)
  %
  (prog (action body fn lst mod var)
        (setq var (cadr u))
        (setq u (cddr u))
        (setq mod (car u))
        (setq u (cdr u))
        (setq lst (car u))
        (setq u (cdr u))
        (setq action (car u))
        (setq body (cdr u))
        (setq fn
              (cond ((eq action 'do) (if (eq mod 'in)
                       'mapc
                       'map))
                    ((or (eq action 'conc) (eq action 'join)) (if (eq mod
                                                                   'in)
                       'mapcan
                       'mapcon))
                    ((eq action 'collect) (if (eq mod 'in)
                       'mapcar
                       'maplist))
                    (t (stderror
                        (bldmsg "%r is an illegal action in ForEach"
                         action)))))
        (return (list fn lst
                      (list 'function
                       (cons 'lambda (cons (list var) body)))))))


(dm repeat (u)
  %
  % From RLISP
  % Form is (repeat exp1 ... expN bool)
  % Repeat until bool is true, similar to Pascal, etc.
  %
  (cons 'prog
        (cons 'nil
              (cons '$loop$
                    (foreach x on (cdr u) collect (if (null (cdr x))
                       (list 'cond (list (list 'not (car x)) '(go $loop$)))
                       (car x)))))))


% I will also want IFOR, but the other things defined in util/inum.sl would
% potentially clobber VSL versions of iplus etc.. so I lift the definition
% out to here.

(dm ifor (u)
  % U is of the form: (IFOR (FROM var start end step) (DO body))

  (let ((step (nth (second u) 5)))
    (if (fixp step)
      (constant-increment-ifor u)
      (variable-increment-ifor u)
      )))

(de variable-increment-ifor (u)
  (let* ((var       (second (second u)))
       (start     (third  (second u)))
       (finish    (fourth (second u)))
       (step      (nth    (second u) 5))
       (action    (first (third u)))
       (body      (cons 'progn (cdr (third u))))
       (result    (list (list 'setq var start)))
       (x         (list 'IDIFFERENCE finish var))
       (label1    (gensym))
       (label2    (gensym)))
    (unless (onep step)
      (setf x (list 'ITIMES2 step x))
      )
    (unless (eq action 'DO)
      (stderror "Only do expected in SysLisp FOR")
      )
    `(PROG (,var)
       (SETQ ,var ,start)
       ,label1
       (COND ((ILESSP ,x 0) (GO ,label2)))
       ,body
       (SETQ ,var (IPLUS2 ,var ,step))
       (GO ,label1)
       ,label2
       )))

(de constant-increment-ifor (u)
  (let* ((var       (second (second u)))
       (start     (third  (second u)))
       (finish    (fourth (second u)))
       (step      (nth    (second u) 5))
       (action    (first (third u)))
       (body      (cons 'progn (cdr (third u))))
       (result    (list (list 'setq var start)))
       (comparison(if (minusp step) 'ILESSP 'IGREATERP))
       (label1    (gensym)))
    (unless (eq action 'DO)
      (stderror "Only do expected in SysLisp FOR")
      )
    `(PROG (,var)
       (SETQ ,var ,start)
       ,label1
       (COND ((,comparison ,var ,finish) (RETURN 0)))
       ,body
       (SETQ ,var (IPLUS2 ,var ,step))
       (GO ,label1)
       )))


(de onoff* (u val)
  (foreach x in u do 
    (cond ((idp x) (set (intern (list2string (cons '!* (explode2 x)))) val)))))

(dm on (u)
   (list 'onoff* (mkquote (cdr u)) t))

(dm off (u)
   (list 'onoff* (mkquote (cdr u)) nil))

(flag '(on off) 'ignore)

(de int2id-internal (u)
  (cond ((equal u **nil-id-value**) nil)
        ((and (greaterp u -1) (lessp u 256)) (code-char u))
        (t 'unknown)))

(dm load (x)
  (list 'evload (mkquote (cdr x))))

(de evload (x)
  (foreach u in x do (load1 u)))

(setq modules-loaded* nil)

(de load1 (u)
  (cond ((memq u modules-loaded*) nil)
        ((memq u '(fasl-decls hash-decls))
         (dskin (string-concat "$pxk/" (string-concat (id2string u) ".sl"))))
       ((memq u '(fast-vector))
         (dskin (string-concat "$pu/" (string-concat (id2string u) ".sl"))))
  )
  (setq modules-loaded* (cons u modules-loaded*)))

(de unboundp (u) (not (boundp u)))

(de fboundp (u) (not (null (getd u))))

(de funboundp (u) (null (getd u)))

(de dskin (u) (rdf u))

(flag '(dskin) 'ignore)

(de pp (x) (prettyprint x))

(de string-concat (a b)
  (setq a (explode a))
  (setq b (explode b))
  (compress (append
    (reverse (cdr (reverse a)))
    (cdr b))))

%%%% This doesn't work,  as gtbps must return the address of the vector
%(de gtbps (n) (mkvect n))
(de gtbps (n) 47114711)

(de string-equal (x y) (equal x y))

(de channelprin2 (ch x)
   (let!* ((s (wrs ch)))
      (prog1
         (prin2 x)
         (wrs s))))

(de channelterpri (ch)
   (let!* ((s (wrs ch)))
      (prog1
         (terpri)
         (wrs s))))

(setq stringgensymcounter* 0)
(de stringgensym ()
  (let ((x (explode2 (setq stringgensymcounter* (plus2 stringgensymcounter* 1)))))
    (while (lessp (length x) 4)
      (setq x (cons '!0 x)))
    (compress (cons '!" (append (cons '!L x) '(!"))))))

(dm errset (u)
    (list 'errorset (list 'quote (cadr u))
	  (if (null (cddr u)) t (caddr u))
	  nil))

(de id2int (x) (print (list "ID2INT called on" x)) 4711)
(de id2int (x)
  (cond ((null x) **nil-id-value**)
        ((equal (length (explode2 x)) 1) (char-code (car (explode2 x))))
        (t 4711)))

% converts a binary integer in a machine word into a lisp integer
(de int2sys (x) x)

(de sys2fixn (x) x)

(de binaryopenwrite (name) (open name 'output))
(de binaryclose (ff) (close ff))

% Functions that operate on machine words
% use integer functions for now
(de wshift (x y) (lshift x y))
(de wplus2 (x y) (plus2 x y))
(de wtimes2 (x y) (times2 x y))
(de wquotient (x y) (quotient x y))
(de wdifference (x y) (difference x y))
(de wgreaterp (x y) (greaterp x y))
(de wlessp (x y) (lessp x y))
(de wgeq (x y) (geq x y))
(de wleq (x y) (leq x y))
(de weq (a b) (equal a b))
(de wand (x y) (logand x y))
(de wor (x y) (logor x y))

(dm land (u) (cons 'logand (cdr u)))
(dm lor (u) (cons 'logor (cdr u)))
(dm iland (u) (cons 'logand (cdr u)))
(dm ilor (u) (cons 'logor (cdr u)))

(dm string (u) (list 'list2string (cons 'list (cdr u))))

(dm putword (u)
    (cons 'wputv (cdr u)))

(de evectorp (x) nil)

(de bigp (u) (bignump u))
 
(de isizev (u) (size u))
(de igetv (a b) (indx a b))

(de channelposn (f)
  (prog (r)
    (setq f (wrs f))
    (setq r (posn))
    (wrs f)
    (return r)))

(de channelwritechar (f ch)
  (setq f (wrs f))
  (prin2 (if (numberp ch) (code-char ch) ch))
  (wrs f)
  ch)

% This mess yields a value in the range 0 to 127 for symbols that are
% 1 character long if that character has ASCII code in the range 0 to 127.
% I also force nil to yield 128. For other symbols I return 256 and hope that
% the only call to this is from findidnumber!

(de idinf (u)
   (cond ((null u) 128)
         ((cdr (explodec u)) 256)
         (t (char-code u))))

(de fastcallablep (u)
   (member u '(putentry)))

(flag '(
   stderror exitlisp copyd codep ncons posintp errorprintf1 remob
   totalcopy variable-increment-ifor constant-increment-ifor
   onoff* int2id-internal evload load1 unboundp fboundp
   funboundp dskin pp string-concat %gtbps gtbps string-equal channelprin2
   channelterpri stringgensym id2int id2int int2sys sys2fixn
   binaryopenwrite binaryclose wshift wplus2 wtimes2 wquotient
   wdifference wgreaterp wlessp wgeq wleq weq wand wor evectorp bigp
   isizev igetv channelposn channelwritechar idinf fastcallablep defun
   errorprintf foreach repeat ifor on off imports putmem putbyte
   put_a_halfword int2id load errset land
   lor iland ilor string putword) 'lose)


% Redefine a couple of functions that do not work out of the box

(de printexpression (x)
  ((lambda (expressioncount*)
     (prog (hd tl fn)
	   (setq x (resolvewconstexpression x))
 	   (cond ((or (numberp x) (stringp x)) (prin2 x))
		 ((idp x) (prin2 (findlabel x)))
		 ((atom x) 
		  (errorprintf "***** Oddity in expression %r" x) 
		  (prin2 x))
		 (t
		  (setq hd (car x)) (setq tl (cdr x)) 
		  (cond
		   ((setq fn (get hd 'binaryasmop))
		    (when (greaterp expressioncount* 0)
			  (prin2 asmopenparen*))
		    (printexpression (car tl)) (prin2 fn) 
		    (printexpression (cadr tl))
		    (when (greaterp expressioncount* 0)
			  (prin2 asmcloseparen*)))
		   ((setq fn (get hd 'unaryasmop)) (prin2 fn) 
		    (printexpression (car tl)))
		   ((setq fn (get hd 'asmexpressionformat)) 
		    (apply 'printf_internal
			   (list fn 
				 (foreach y in tl collect 
					  (list 'printexpression
						(mkquote y))))))
		   ((and (setq fn (getd hd)) 
			 (equal (car fn) 'macro))
		    (printexpression (apply (cdr fn) (list x))))
		   ((setq fn (get hd 'asmexpressionfunction)) 
		    (apply fn (list x)))
		   (t 
		    (errorprintf "***** Unknown expression %r" 
				 x)
		    (printf "*** Expression error %r ***" x)))))))
   (plus expressioncount* 1)))

(de size (x) 
  (cond ((stringp x) (difference (length (explodec x)) 1))
        ((vectorp x) (upbv x))
        ((bignump x) (difference (length (cdr x)) 1))
        (t nil)))

(de indx (s n)
  (cond ((stringp s) (char-code (nth (explodec s) (plus2 n 1))))
        (t nil)))

(de intp (x) (and (fixp x) (not (bignump x))))

(de sunsymbolp (x)
   (setq x (explodec x))
   (prog nil
     lbl
     (cond ((null x) (return t))
           ((not (or (liter (car x)) (eq (car x) '!_))) (return nil)))
     (setq x (cdr x))
     (go lbl)))

(de asm-char-downcase (c)
    (if (and (leq 65 c) (leq c 90))
	(plus c 32)
      x)))

(de auxaux (i)
  (list2string (list (code-char i))))

(dm codeprintf (x) (cons 'fprintf (cons 'codeout* (cdr x))))
(dm dataprintf (x) (cons 'fprintf (cons 'dataout* (cdr x))))

%(def-pass-1-macro Char (u)
%. PSL Character constant macro
%  (DoChar U))

% Table driven char macro expander
(de DoChar (u)
  (cond
    ((idp u) (or
               (get u 'charvalue) 
               ((lambda (n) (cond ((lessp n 128) n))) (id2int u))
               (CharError u)))
    ((pairp u) % Here's the real change -- let users add "functions"
      ((lambda (fn)
         (cond 
           (fn (apply fn (list (dochar (cadr u)))))
           (t (CharError u))))
       (cond ((idp (car u)) (get (car u) 'char-prefix-function)))))
    ((and (fixp u) (geq u 0) (leq u 9)) (plus u 48))  % 48 = (char 0)
    (t (CharError u))))

(de CharError (u)
  (ErrorPrintF "*** Unknown character constant: %r" u)
  0)


% This is needed for ASM generation, see $pxk/main-start.sl
(put 'symnam 'symbol 'symnam)
(put 'symfnc 'symbol 'symfnc)
(put 'symget 'symbol 'symget)
(put 'symval 'symbol 'symval)
(put 'symprp 'symbol 'symprp)

(setq toploopeval* 'eval)
 
%(de OperandPrintIndirect (x)            % (Indirect x)
%  (progn (setq x (cadr x)) 
%         (if (regp x) (progn
%                        (prin2 "(")
%                        (PrintOperand x) 
%                        (Prin2 ")"))
%               (prin2 "*")
%               (PrintOperand x)
%               (prin2 "         / ")
%	       (prin1 x)
%               (Prin2 "")) 
%))
%
%
%(de asmprintvaluecell (x)
%  (printexpression (list 'plus2 'symval 
%                         (list 'times (compiler-constant 'addressingunitsperitem) 
%                          (list 'idloc (cadr x)))))
%  (princ "     / ")
%  (prin1 x))

(flag '(evload) 'ignore)
% $pu/if.sl defines an IF macro that uses symbols as keywords THEN, ELIF
% and ELSE. It is coded using the NEXT macro from $pnk/loop-macros.sl, but
% if I load that file then it gives a version of FOR that conflicts with
% $pu/for-macro.sl. So I will provide NEXT manually here - not that I think
% that use of it was a good idea!

(dm next (u)  % Continue Loop
  '(go $loop$))

(flag '(next) 'lose)

(dm bothtimes (x) (cons 'progn (cdr x)))
(dm compiletime (x) (cons 'progn (cdr x)))
(dm loadtime (x) (cons 'progn (cdr x)))

(flag '(bothtimes compiletime loadtime) 'lose)

% This seems to be called at cross-compile time with NIL as the
% second argument. That seems a bit weird to me.

(de mkitem (tag x)
  (cond
    ((null (integerp tag)) (print (list '++++ 'mkitem tag x)) (mkitem 0 x))
    ((null (integerp x))  (print (list '++++ 'mkitem tag x)) (mkitem tag 0))
    (t (land 16#ffffffffffffffff (lor
         (lsh tag 56)
         (land x 16#00ffffffffffffff))))))

(de imports (u) nil)

(flag '(mkitem imports) 'lose)

% (de codewritestring (x)
%   (setq x (strinf x))
%   (setq s (strlen x))
%   (binarywrite codeout* s)
%   (binarywriteblock codeout* (strbase x) (strpack s)))

(de codewritestring (x)
  (prog (len w)
    (setq x (explode2 x))
    (setq len (sub1 (length x)))
    (setq w (times 8 (strpack len))) % 8 bytes per word
    (binarywrite codeout* len)
    (foreach b in x do (binarywritebyte codeout* (char-code b)))
    (while (lessp len w)
      (progn (binarywritebyte codeout* 0)
      (setq len (add1 len))))))

(de codefiletrailer ()
  (prog (s)
        (systemfaslfixup)
        (binarywrite codeout* (idifference (isub1 nextidnumber*)
                                           first-local-id-number))
        % Number of local IDs
        (foreach x in (car orderedidlist*) do
                 (progn (remprop x fasl-idnumber-property*)
                        (codewritestring (faslid2string x))))
        (binarywrite codeout* % S is size in words
                     (setq s
                      (iquotient
                       (iplus2 currentoffset*
                        (isub1 addressingunitsperitem))
                       addressingunitsperitem)))
        (binarywrite codeout* initoffset*)
        (binarywriteblock codeout* codebase* s)
        (if *compact-bittable
         (let((b (compact-bittable bittablebase* bittableoffset*))
              (bpw (quotient bitsperword 8)))
           (binarywrite codeout*
            (setq s (iquotient
                       (iplus2 (car b)
                        (isub1 bpw))
                       bpw)))
           (binarywriteblock codeout* (strbase(strinf (cdr b))) s)
         )
         (progn
          (binarywrite codeout*
                     (setq s
                      (iquotient
                       (iplus2 bittableoffset*
                        (isub1 bittable-entries-per-word))
                       bittable-entries-per-word)))
          (binarywriteblock codeout* bittablebase* s)
        ))
        (deallocatefaslspaces)))

(flag '(codewritestring codefiletrailer) 'lose)

(rdf "mytrace.lsp")

% A function ASSOC1 is defined using LAP in one of the source files
% I need to load as part of the compiler - thus tending to require that
% a working compiler/LAP is available at an early stage. By putting in
% a dummy definition here I avoid that crashing things, and as I read in
% more files I will instate a locally workable version of LAP - but note
% that I will install one suitable for cross rather than local compilation.

(de lap (u)
  (print "+++++ lap called before it is defined +++++")
  (print u)
  nil)

% end of file
