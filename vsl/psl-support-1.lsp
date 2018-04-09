% This file contains a mixture of two sorts of things:

% (A) PSL functions that are not defined in the files that I will
%     load to make myself a compiler, but that are required. For instance
%     various bits of the PSL compiler use "word" arithmetic (as in
%     wplus2). That would compile inline into a single machine code instruction
%     but it does not make good sense during cross-compilation where the issue
%     or word-length and data tagging on the host can not be relied on.
%
% (B) Replacements for some things that are defined in the compiler-related
%     sources but where the definitions are sufficiently PSL-specific that
%     I need to introduce my own replacements if I am to survive using some
%     alternative Lisp for bootstrapping. A significant set of functions
%     here are those that simulate a raw block of memory that can be accessed
%     either by bytes or words. Such memory is used to collect an image of
%     generated code and that is then written out to create a fasl file. PSL
%     can use memory directly. I simulate it using a vector in which I place
%     64-bit integers, and I have ugly code involving shift and mask operations
%     for when I need to accesss it as if it was arranged in bytes.
%     There are other places where the code exploits or relies on detailed
%     PSL representation of data (eg idinf).
%     A further understandable jolly is that the PSL sources contain a number
%     of instances of definitions along the line
%        (de stringp (u) (stringp u))
%     which rely on the compiler generating in-line code for the body of
%     the function. Some such definitions are present within files i wish to
%     load to pick up other things in them! So instating my own version and
%     then setting a 'lose flag lets me make progress.
%
% (C) At the end of this file I read in "mytrace.lsp" which is my own
%     implementation of tracing code. Both VSL and PSL have perfectly
%     respectable trace capabilities of their own, but having my own one
%     here lets me arrange that test runs produce (almost) identical output
%     whichever platform they are run on, and the ability to do direct
%     log file comparisons to track down discrepancies is very useful.
%
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

(de flag1 (x y) (flag (list x) y))

(de remflag1 (x y) (remflag (list x) y))

(dm control (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))
(dm cntrl (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))

(de continuableerror (errnum message errorform*)
  (progn (errorprintf "***** %l" message)))

(de main ())


% Now the things just needed for creating fasl files... I will add things in
% here to start with and maybe move them to psl-support-2.lsp later...

(de concat (a b) (string-concat a b))

(de binarywrite (stream val)
   (binarywritebyte stream val)
   (binarywritebyte stream (setq val (rsh val 8)))
   (binarywritebyte stream (setq val (rsh val 8)))
   (binarywritebyte stream (setq val (rsh val 8)))
   (binarywritebyte stream (setq val (rsh val 8)))
   (binarywritebyte stream (setq val (rsh val 8)))
   (binarywritebyte stream (setq val (rsh val 8)))
   (binarywritebyte stream (rsh val 8)))

% This writes 16 identical bytes as a way of putting a mark in a binary
% output stream...

(de binarymarker (stream n)
%-  (setq n (lor (lsh n 8) n))
%-  (setq n (lor (lsh n 16) n))
%-  (setq n (lor (lsh n 32) n))
%-  (binarywrite stream n)
%-  (binarywrite stream n)
   nil) 

(de binarywritebyte (stream val)
   (prog (of)
      (setq of (wrs stream))
      (prinbyte (land val 255))
      (wrs of)
      (return val)))


% I will simulate byte vectors using vectors of 64-bit integers, and here
% I will pack the bytes little-endian. Note that the implementation here
% requires that the Lisp used for bootstrapping can work with full 64-bit
% integers.

% I will arrange that 16, 32 and 64-bit values can be read and written
% from arbitrarily-aligned addresses. This is done by expanding the
% access code to work byte by byte.

(de byte (v n)
  (prog (o s)
     (setq n (plus2 v n))
     (setq o (rsh n 3))
     (setq s (times2 (land n 7) 8))
     (return (land 255 (rsh (getv memory o) s)))))

(de putbyte (v n val)
  (prog (o s w)
     (setq n (plus2 v n))
     (setq o (rsh n 3))
     (setq s (times (land n 7) 8))
     (setq w (getv memory o))
     (setq m (difference 16#ffffffffffffffff (lsh 16#ff s)))
     (setq w (land w m))
     (setq w (lor w (lsh val s)))
     (putv memory o w)
     (return val)))


% Now similar for halfwords (16 bits)

(de halfword (v n)
   (lor (byte v n)
        (lsh (byte v (plus n 1)) 8)))

(de puthalfword (v n val)
   (putbyte v n (land val 16#ff))
   (putbyte v (plus n 1) (land (rsh val 8) 16#ff))
   val)

% ... and 32-bit words

(de word32 (v n)
   (lor (halfword v n)
        (lsh (halfword v (plus n 2)) 16)))

(de putword32 (v n val)
   (puthalfword v n (land val 16#ffff))
   (puthalfword v (plus n 2) (land (rsh val 16) 16#ffff))
   val)

% This one tricked me for some while - a "halfword" here is a 32-bit value!

(de put_a_halfword (addr val)
  (putword32 addr 0 val))


(de word (v n)
   (lor (word32 v n)
        (lsh (word32 v (plus n 4)) 32)))

(de putword (v n val)
% PSL seems to be willing to pass NIL or a symbol whose name is a single
% character here. I will patch that up in a gruesome manner!
   (if (and (idp val) (leq (id2int val) 128))
       (setq val (plus (id2int val) (lsh 254 56))))
   (putword32 v n (land val 16#ffffffff))
   (putword32 v (plus n 4) (land (rsh val 32) 16#ffffffff))
   val)

(de wgetv (v n)
   (getv memory (plus (rsh v 3) n)))

(de wputv (v n val)
   (putv memory (plus (rsh v 3) n) val))



(de known-free-space ()
  (mkint (wquotient (wdifference heapupperbound heaplast) 
                    addressingunitsperitem)))

(de free-bps ()
  (wquotient (wdifference lastbps nextbps) 
	     addressingunitsperitem)
  )



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
% Note that wputv uses a word index not a byte one.
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
% Ensure that codebase* is 8-byte aligned.
    (setq codebase* (times 8 (quotient codebase* 8)))

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
         ((cdr (explode2 u)) 256)
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
  (prog (o b i lenb)
    (binarymarker stream 16#bb)
    (setq o (wrs stream))
    (setq i 0)
    (setq lenb (times len 8)) % length is given in WORDS
 top(cond
      ((not (lessp i lenb)) (go done)))
    (prinbyte (byte vec i))
    (setq i (add1 i))
    (go top)
 done
    (wrs o)
    (binarymarker stream 16#ee)
    (return len)))

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



(de stderror (msg)
  (error 99 msg))

(de exitlisp () (stop 0))

% copyd is invoked (bothtimes ..) within the for-macro.sl source file,
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

% This definition of totalcopy may be insufficient? The issue of copying
% strings and vectors presumably arises.

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


(de first (u) (car u))
(de second (u) (cadr u))
(de third (u) (caddr u))
(de fourth (u) (cadddr u))

(de nth (u n)
  (cond
    ((equal n 1) (car u))
    (t (nth (cdr u) (sub1 n)))))

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
    (compress (cons '!" (append (cons 'l x) '(!"))))))

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
         ((cdr (explode2 u)) 256)
         (t (char-code u))))

% Here we have sometihng of a joke! in PSL the compiler generates calls
% to functions that are part of the PSL kernel in an abbreviated way
% because it know that they are present in compiled not interpreted form.
% I have not yet understood what the consequences would be if a user then
% redefined one of these with an interpreted version! Anyway to have any
% prospect of binary compatibility between cross-build code and native
% build code I have to know what PSL had happened to implement this way!

(flag '(
  !%clear!-catch!-stack !%displaced!-macro !%get !%reclaim !%throw
  !%uncatch !*!*float!*!* !*catch !*define!-constant !*doubletofloat
  !*fassign !*fdifference !*fgreaterp !*flessp !*floattodouble
  !*fp!-check!-for!-exceptions !*fplus2 !*fquotient !*freset !*fsqrt
  !*ftimes2 !*load!-for!-compiler !*throw !*wfix !*wfloat !_slowcons
  !_slowgtfltn abs aconc add1 add1!-hardcase addload addressapply0
  adjoin adjoinq adjustcase alghandler allocate!-string allocate!-words
  allocatemorebps and ans anyuser!-homedir!-string append apply ass
  assoc assoc!* atom atsoc backtrace beforegcsystemhook bigp binaryclose
  binaryopenappend binaryopenread binaryopenupdate binaryopenwrite
  binarypositionfile binaryread binaryreadblock binarywrite binarywriteblock
  bindeval bldmsg bothtimes break breakcontinue breakedit breakerrmsg
  breakeval breakquit breakretry bstackoverflow bstackunderflow bstructp
  build!-trap!-message bvectorp caaaar caaadr caaar caadar caaddr caadr
  caar cadaar cadadr cadar caddar cadddr caddr cadr captureenvironment car
  case catch catch!-all catchsetup catchsetupaux cd cdaaar cdaadr cdaar
  cdadar cdaddr cdadr cdar cddaar cddadr cddar cdddar cddddr cdddr cddr
  cdr cfserror channeleject channelerror channelfindposition channelflush
  channellinelength channellposn channelnotopen channelposn channelprin1
  channelprin2 channelprin2t channelprinc channelprint channelprintbstruct
  channelprintbvector channelprintcontext channelprintevector channelprintf
  channelprintfunarg channelprintid channelprintpair channelprintsgd
  channelprintstring channelprintunbound channelprintvector channelread
  channelreadch channelreadchar channelreadeof channelreadline
  channelreadlistordottedpair channelreadquotedexpression
  channelreadrightparen channelreadtoken channelreadtokenwithhooks
  channelreadvector channelspaces channelspaces2 channeltab channelterpri
  channeltyi channeltyo channelunreadchar channelwritebitstraux
  channelwritebitstring channelwriteblankoreol channelwritebstruct
  channelwritebvector channelwritebytes channelwritechar
  channelwritecodepointer channelwritecontext channelwriteevector
  channelwritefixnum channelwritefloat channelwritefunarg
  channelwritehalfwords channelwriteid channelwriteinteger
  channelwritepair channelwritesgd channelwritestring channelwritesysfloat
  channelwritesysinteger channelwriteunbound channelwriteunknownitem
  channelwritevector channelwritewords charsininputbuffer checklinefit
  clear!-warray clear!-wstring clearbindings clearcompresschannel clearerr
  cleario clearonechannel close code!-number!-of!-arguments code!-putd
  codeaddressp codeapply codeevalapply codep coerce1 coerce2 commentoutcode
  compiledcallinginterpretedaux compiler!-constant compiletime compress
  compresserror compressreadchar compute!-prompt!-string compute!-relocation
  concat cond cons console!-newline console!-print!-number
  console!-print!-string const constantp conterror contextp
  continuableerror contopenerror copy copybytes copyevector copyevectortofrom
  copyfltn copyfromallbases copyfrombase copyfromrange copyfromstack
  copyfromstaticheap copyhalfwords copyhalfwordstofrom copyitem
  copyitem1 copypairitem copystring copystringtofrom copyvector
  copyvectortofrom copywarray copywrds copywrdstofrom ctime
  current!-stack!-pointer date date!-and!-time date!-int!-to!-string
  datebuffer!-to!-string de defconst define!-constant deflist del
  delasc delascip delatq delatqip delbps delete delete!-file deletip
  delheap delq delqip delwarray depositextrareglocation
  depositfunctioncelllocation depositvaluecelllocation df difference
  difference!-hardcase digit digittonumber divide dm dn do!-relocation
  do!-relocation!-new ds dskin dskin!-file dskin!-step dskin!-stream
  dumplisp echooff echoon egetv eject eputv eq eqcar eqn eqstr equal error
  errorprintf errorset errortrap errprin errset eupbv eval evalinitforms
  evand evcond evdefconst evectorequal evectorp evlis evload evor
  evprogn evreload exit exit!-with!-status exitlisp expand expand_file_name
  expandsetf explode explode2 explode2n explodecn exploden explodewritechar
  exprp expt!-rec external!-allocatemorebps external_alarm
  external_anyuser_homedir_string external_charsininputbuffer
  external_exit external_fullpath external_getenv external_link
  external_mkdir external_pwd external_rmdir external_setenv external_stat
  external_strlen external_system external_timc external_time
  external_ualarm external_unlink external_user_homedir_string faslin
  faslin!-bad!-file faslin!-intern fastapply fastlambdaapply fatalerror
  fclose fcntl fcodep fdummy fexprp fflush fgetc fgets filep filestatus
  findcatchmarkandthrow findfreechannel findposition first firstkernel
  fix fix!-hardcase fixp flag flagp flambdalinkp flatsize flatsize2
  flatsizewritechar float floatdifference floatgreaterp floatlessp floatp
  floatplus2 floatquotient floattimes2 floatzerop flock fluid fluid1
  fluidp flushbuffer flushstdoutputbuffer fopen force!-heap!-enlargement
  foreach fork fourth fpehandler fputc fread free!-bps fseek funargp
  funboundp function fwrite gc!-trap gc!-trap!-level gcstats gensym
  geq get get!-exec!-path get!-fullpath get!-heap!-trap get!-heap!-try!-reclaim
  get!-image!-path get!-registry!-value get_execfilepath get_file_status
  get_imagefilepath get_registry_value getd getenv getfcodepointer getfntype
  gethostid getpid getprintprecision getsocket getstartupname getunixargs
  getv gget global global1 globalinstall globallookup globalp globalremove
  go greaterp greaterp!-hardcase gtbps gtbps!-nil!-error gtbvect gtconststr
  gtcontext gtevect gtfixn gtfltn gthalfwords gtheap gtid gtstr gtvect
  gtwarray gtwrds hash!-function hash!-into!-table helpbreak hist
  history!-append history!-fetch history!-reset history!-set!-input
  history!-set!-output history!-state histprint id!-intern id2int
  id2string idapply idp ieee_flags ieee_handler illegalstandardchannelclose
  illhandler implode importforeignstring imports independentclosechannel
  independentreadchar independentwritechar indexerror indx init!-file!-string
  init!-fluids init!-gcarray init!-pointers initcode initialize!-new!-id
  initialize!-symbol!-table initialize!-warray initialize!-wstring
  initializeinterrupts initializeinterrupts!-1 inp input!-case
  instantiateinform int2code int2id intern internal_aftergcsystemhook
  internal_beforegcsystemhook interngensym internp interpbacktrace interrogate
  intersectionq intfloat inthandler ioerror iovhandler kernel!-fatal!-error
  killhandler known!-free!-space land land!-hardcase lapin lastcar lastkernel
  lastpair lbind1 lconc length leq lessp lessp!-hardcase linelength
  linux_close linux_open lisp2char list list2 list2set list2setq list2string
  list2vector list3 list4 list5 liter lnot lnot!-hardcase load
  load!-for!-compiler load1 loader!-main loadtime local!-to!-global!-id
  lor lor!-hardcase lposn lshift!-hardcase lxor lxor!-hardcase macrop
  make!-bytes make!-halfwords make!-manual!-evector make!-vector make!-words
  makeds makefcode makeflambdalink makefunbound makeidfreelist
  makeinputavailable makeunbound map map2 mapc mapc2 mapcan mapcar
  mapcon maplist mapobl markandcopyfromid max max2 mem member memq
  min min2 minus minus!-hardcase minusp minusp!-hardcase mkevector
  mkflagvar mkquote mkstring mkvect modeless!-dskin!-file modify
  modulep moreheap nconc ncons ne neq newid nexprp next noncharactererror
  noniderror noninteger2error nonintegererror noniochannelerror
  nonlisterror nonnumber1error nonnumber2error nonnumbererror nonpairerror
  nonpositiveintegererror nonsequenceerror nonstringerror nonvectorerror
  nonwordserror not nth null numberp oblist off old!-flag1 old!-put
  old!-remflag1 old!-remprop oldchannelprin1 oldchannelprin2 oldfloatfix
  on onep!-hardcase onoff!* open or os_cleanup_hook os_startup_hook
  output!-case package pair pairp pbind1 pclose plantcodepointer
  plantlambdalink plantunbound plus plus2 plus2!-hardcase pnth popen
  posn pp pre!-main prettyprint prin1 prin2 prin2l prin2t print printf
  printf1 printf2 printwithfreshline prog prog2 progn prop psl_main
  pslsignalhandler putc putentry putv putw pwd quit quote quotient
  quotient!-hardcase rangeerror rassoc ratom rdf rds read read!-id!-table
  readch readchar reader!-intern readinbuf readline readonlychannel
  real!-gtheap recip reclaim reclaim2 redo reload relocate!-inf relocate!-word
  remainder remainder!-hardcase remd remflag remob rempropl reset
  rest restoreenvironment return returnaddressp returnnil reverse reversip
  robustexpand rplaca rplacd rplacw safecar safecdr sassoc savesystem
  search!-string!-for!-character second seghandler semctl semget semop
  set set!-bndstk!-size set!-gc!-trap!-level set!-heap!-size set!-history!-state
  set_bndstk_size set_heap_size setenv setindx setlinebuf
  setmacroreference setprintprecision setprop setq setsub setsubseq
  sgdp shmat shmctl shmdt shmget signal sigrelse sigunwind size sleep
  spaces spaces2 standardlisp staticintfloat stderror step string string!=
  string!-intern string2list string2vector stringequal stringgensym stringp
  sub sub1 sub1!-hardcase subla sublis subseq substip suck!-in!-files
  sun3_sigset sys2fixn sys2int syscleario sysclose sysmaxbuffer sysopenread
  sysopenwrite syspowerof2p sysreadrec system systemmarkasclosedchannel
  systemopenfileforinput systemopenfileforoutput systemopenfilespecial
  syswriterec tab tconc terminalinputhandler terpri testlegalchannel
  third throw throwaux timc time times times2 times2!-hardcase
  top!-loop!-eval!-and!-print top!-loop!-read toploop tostringwritechar
  totalcopy tr trst try!-other!-bps!-spaces tyi tyo typeerror unbindn
  unboundp unchecked!-prop unchecked!-put unchecked!-setprop
  unchecked!-string!-equal unchecked!-string!-intern undefinedfunction!-aux
  unexec unfluid unfluid1 unionq unix!-profile unix!-time unixcd unixcleario
  unixclosesocket unixopen unixputc unixputn unixputs unixsocketopen
  unixstring unixstrlen unprotected!-dskin!-stream unreadchar unwind!-all
  unwind!-protect upbv usagetypeerror user!-homedir!-string uxacos
  uxasin uxassign uxatan uxatan2 uxcos uxdifference uxdoubletofloat uxexp
  uxfix uxfloat uxfloattodouble uxgreaterp uxlessp uxlog uxplus2
  uxquotient uxsin uxsqrt uxtan uxtimes2 uxwritefloat uxwritefloat8
  valuecell vaxreadchar vaxwritechar vector vector2list vector2string
  vectorp verbosebacktrace wait writechar writefloat writenumber1
  writeonlychannel writesocket writestring writesysinteger wrongcasecharp
  wrs xcons xgetw xidapply0 xidapply1 xidapply2 xidapply3 xidapply4
  xn xnq yesp zerop zerop!-hardcase)
  'fastcallable)

(de fastcallablep (u)
   (flagp u 'fastcallable))



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
  (cond ((stringp x) (difference (length (explode2 x)) 1))
        ((vectorp x) (upbv x))
        ((bignump x) (difference (length (cdr x)) 1))
        (t nil)))

(de indx (s n)
  (cond ((stringp s) (char-code (nth (explode2 s) (plus2 n 1))))
        (t nil)))

(de intp (x) (and (fixp x) (not (bignump x))))

(de sunsymbolp (x)
   (setq x (explode2 x))
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


(dm bothtimes (x) (cons 'progn (cdr x)))
(dm compiletime (x) (cons 'progn (cdr x)))
(dm loadtime (x) (cons 'progn (cdr x)))


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


% (de codewritestring (x)
%   (setq x (strinf x))
%   (setq s (strlen x))
%   (binarywrite codeout* s)
%   (binarywriteblock codeout* (strbase x) (strpack s)))

(de codewritestring (x)
  (prog (len w)
    (binarymarker codeout* 16#55)
    (setq x (explode2 x))
    (setq len (sub1 (length x)))
    (setq w (times 8 (strpack len))) % 8 bytes per word
    (binarywrite codeout* len)
    (foreach b in x do (binarywritebyte codeout* (char-code b)))
    (while (lessp (setq len (add1 len)) w)
      (binarywritebyte codeout* 0))))

(de codefiletrailer ()
  (prog (s len)
        (binarymarker codeout* 16#22)
        (systemfaslfixup)
        (binarywrite codeout* (idifference (isub1 nextidnumber*)
                                           first-local-id-number))
        (binarymarker codeout* 16#33)
        % Number of local IDs
        (foreach x in (car orderedidlist*) do
                 (progn (remprop x fasl-idnumber-property*)
                        (codewritestring (faslid2string x))))
        (binarymarker codeout* 16#44)
        (binarywrite codeout* % S is size in words
                     (setq s
                      (iquotient
                       (iplus2 currentoffset*
                        (isub1 addressingunitsperitem))
                       addressingunitsperitem)))
        (binarymarker codeout* 16#66)
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
           (setq b (explode2 (cdr b)))
           (setq len (length b))
           (setq s (times 8 s))
           (binarymarker codeout* 16#77)
           (foreach b1 in b do
              (binarywritebyte codeout* (char-code b1)))
           (while (lessp (setq len (add1 len)) s)
              (binarywritebyte codeout* 0))

%          (binarywriteblock codeout* (strbase(strinf (cdr b))) s)
         )
         (binarymarker codeout* 16#88)
         (progn
          (binarywrite codeout*
                     (setq s
                      (iquotient
                       (iplus2 bittableoffset*
                        (isub1 bittable-entries-per-word))
                       bittable-entries-per-word)))
          (binarywriteblock codeout* bittablebase* s)
        ))
        (binarymarker codeout* 16#99)
        (deallocatefaslspaces)))



(de compact-bittable(base max)
 (prog (i d bl b l s sb)
   (setq i (setq d 0))
    (ifor (from i 0 (isub1 max) 1)
     (do
      (progn
       (setq b (bittable base i))
       (if (or (not (eq b 0))  % nonzero entry
               (eq d 16#3f)    % maximum offset
           )
           (progn
               (push (logor (lsh b 6) d) bl)
               (setq d 1)
           )
           (setq d (iadd1 d))
       )
    )))
% OK - we have now built up a list bl of the non-zero entries. Each
% has the entry number in the low 6 bits and then 2 bits of data at the top.
    (setq bl (cons 0 bl))
    (setq bl (reversip bl))
% Now in the correct order.
    (setq l (length bl))
% I want to pack it as a string. BEWARE of several issues. Firstly this
% string contains a pretty arbitrary sequence of bytes, the last of which
% is a zero byte and that must be included as part of the string. It may
% not be valid UTF8 so passing it through print code could potentially cause
% trouble.
    (setq s (list-to-string bl))
%   (setq s (mkstring (isub1 l) 0))
%   (setq sb (strbase (strinf s)))
%   (setq b (isub1 l))
%   (ifor (from i 0 b 1) (do (setf (byte sb i) (pop bl))))
    (return (cons l s))))



(flag '(spaces intp flag1 remflag1 control cntrl continuableerror main
        concat binarywrite binarywritebyte byte putbyte halfword
        puthalfword put_a_halfword  putword wgetv wputv known-free-space
        free-bpsgtheap real-gtheap delheap gtstrgthalfwords gtvect
        gtevect gtcontext gtbvect gtfixn gtfltn try-other-bps-spaces
        delbps gtwarray delwarray allocatefaslspaces isinf
        findidnumber makerelocword makerelocinf makerelochalfword
        lsh rsh getbittable putbittable bittable mapobl binarywriteblock
        mkstring field stderror exitlisp copyd codep ncons posintp
        errorprintf1 remobtotalcopy variable-increment-ifor
        constant-increment-ifor onoff* int2id-internal evload load1
        unboundp fboundp funboundp dskin pp string-concat gtbps
        string-equal channelprin2 channelterpri stringgensym id2int
        id2int int2sys sys2fixn binaryopenwrite binaryclose wshift
        wplus2 wtimes2 wquotient wdifference wgreaterp wlessp wgeq wleq
        weq wand wor evectorp bigp isizev igetv channelposn
        channelwritechar idinf fastcallablep defun errorprintf foreach
        repeat ifor on off imports putmem putbyte put_a_halfword int2id
        load errset land lor iland ilor string putword next bothtimes
        compiletime loadtime mkitem imports codewritestring codefiletrailer
        compact-bittable)
      'lose)

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
