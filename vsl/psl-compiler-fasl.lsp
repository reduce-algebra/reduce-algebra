% This builds a PSL compiler that creates binary FASL files ...

% For VSL the treatment of file-names written as "$xxx/..." is that a Lisp
% variable called "@xxx" is inspected to find the actual path required.

(setq @psl  "../psl/dist")

(setq @psys "../psl/dist/bin/AMD64_ext")

(setq @pl   "../psl/dist/lap/AMD64_ext")

(setq @pk   "../psl/dist/kernel")
(setq @pxk  "../psl/dist/kernel/AMD64_ext")

(setq @pnk  "../psl/dist/nonkernel")
(setq @pxnk "../psl/dist/nonkernel/AMD64_ext")
(setq @pnkl "../psl/dist/nonkernel/AMD64_ext/lap")

(setq @pc   "../psl/dist/comp")
(setq @pxc  "../psl/dist/comp/AMD64_ext")

(setq @pu   "../psl/dist/util")
(setq @pxu  "../psl/dist/util/AMD64_ext")

(setq @pdist   "../psl/dist/distrib")
(setq @pxdist  "../psl/dist/distrib/AMD64_ext")


(rdf "psl-support-1.lsp")



(rdf "$pnk/lisp-macros.sl")

(rdf "$pu/defmacro1.sl")
(rdf "$pu/defmacro2.sl")
(rdf "$pu/set1-macros.sl")
(rdf "$pu/set2-macros.sl")
(rdf "$pu/iter-macros.sl")
(rdf "$pu/for-macro.sl")
(rdf "$pu/cond-macros.sl")
(rdf "$pu/numeric-ops.sl")

(rdf "$pnk/easy-non-sl.sl")
(rdf "$pnk/sets.sl")
%(rdf "$pnk/type-error.sl")

% $pu/if.sl defines an IF macro that uses symbols as keywords THEN, ELIF
% and ELSE. It is coded using the NEXT macro from $pnk/loop-macros.sl, but
% if I load that file then it gives a version of FOR that conflicts with
% $pu/for-macro.sl. So I will provide NEXT manually here - not that I think
% that use of it was a good idea!

(dm next (u)  % Continue Loop
  '(go $loop$))

(rdf "$pu/if.sl")

(rdf "$pu/if-system.sl")

% At least for bootstrapping I need to restore MY version of SPACES
(de spaces (n)                 % Print n blanks.
   (cond
      ((zerop n) nil)
      (t (princ " ") (spaces (sub1 n)))))

(de intp (x) (and (fixp x) (not (bignump x))))
(flag '(intp) 'lose)

(de flag1 (x y) (flag (list x) y))

(de remflag1 (x y) (remflag (list x) y))

(dm control (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))
(dm cntrl (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))

(de continuableerror (errnum message errorform*)
  (progn (errorprintf "***** %l" message)))

(de main ())

% The paths used here suppose that the current directory is the VSL
% one. This is a bit unsatisfactory at present.

(rdf "$pnk/carcdr.sl")
(rdf "$pnk/def-smacro.sl")
(rdf "$pnk/defconst.sl")
(rdf "$pnk/constants.sl")

(rdf "$pnk/eval-when.sl")

(dm bothtimes (x) (cons 'progn (cdr x)))
(dm compiletime (x) (cons 'progn (cdr x)))
(dm loadtime (x) (cons 'progn (cdr x)))

(rdf "$pc/datamachine.sl")
(rdf "$pc/pass-1.sl")
(rdf "$pc/pass-2-3.sl")
(rdf "$pc/pass-1-lap.sl")


(rdf "$pc/anyreg-cmac.sl")
(rdf "$pc/cmacros.sl")
(rdf "$pc/bare-psl.sym")
(rdf "$pc/big-faslend.sl")
(rdf "$pc/comasm.sl")
(rdf "$pc/p1-decls.sl")
(rdf "$pc/p-lambind.sl")
(rdf "$pc/predicates.sl")
(rdf "$pc/pslcomp.sl")
(rdf "$pc/putprint.sl")


(rdf "$pxc/compat.sl")
(rdf "$pxc/sys-consts.sl")
(rdf "$pxc/sys-dm.sl")
(rdf "$pxc/tags.sl")
(rdf "$pxc/AMD64-lap.sl")
(rdf "$pxc/AMD64-cmac.sl")
(rdf "$pxc/AMD64-comp.sl")
(rdf "$pc/faslout.sl")
(rdf "$pxc/AMD64-spec.sl")
%         (rdf "$pxc/carcdrnil.sl")
(rdf "$pxc/comp-decls.sl")
(rdf "$pxc/compiler.sl")
(rdf "$pxc/nbittab.sl")
(rdf "$pxc/neweq.sl")

% redefine as macros since VSL doesn't support functions with
% a variable number of arguments
(dm codeprintf (x) (cons 'fprintf (cons 'codeout* (cdr x))))
(dm dataprintf (x) (cons 'fprintf (cons 'dataout* (cdr x))))


% (rdf "$pxc/unixAMD64-lap-to-asm.sl")
% (rdf "$pxc/unixAMD64-asm.sl")


(rdf "psl-support-2.lsp")

% Now the things just needed for creating fasl files...

(de concat (a b) (string-concat a b))

(de binarywrite (file val)
   (prog (of n)
      (setq of (wrs file))
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

% Code here derived from nonkernel/allocators.sl but adapted for use with
% cross-compilation via VSL.

% I will set up a regular Lisp array to model a chunk of the sort of
% memory that the target machine will have. I will use this as an array of
% 64-bit integers. At present an array of size 100,000 (ie 800 Kbytes)
% as as large as VSL will support. If needbe I can enlarge it!

(global '(totalbytes))

(setq totalbytes 800000)

(global '(memory))
(upbv (setq memory (mkvect (quotient totalbytes 8))))
(dotimes (i (add1 (quotient totalbytes 8))) (putv memory i 0))

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

% And finally 64-bit items
% I force the retrieved value to be positive.

(de wgetv (v n)
   (land (getv memory (plus2 (irsh v 3) n)) 16#ffffffffffffffff))

(de wputv (v n val)
   (putv memory (plus2 (irsh v 3) n) val))



(global '(heapupperbound heaplowerbound heaplast heaptrapbound heaplast
          heaptrapped nextbps lastbps))

% I set up the simulated memory so half is for BPS and half is for heap.

(setq lastbps (quotient totalbytes 2))
(setq nextbps 0)
(setq heapupperbound (setq highpointer totalbytes))
(setq lowpointer lastbps)

(de known-free-space ()
  (mkint (wquotient (wdifference heapupperbound heaplast) 
                    addressingunitsperitem)))

(de free-bps ()
  (wquotient (wdifference lastbps nextbps) 
	     addressingunitsperitem)
  )


(setq heaplast lowpointer)
(setq heaptrapbound (sub1 highpointer))

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

(if_system sel
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

(de gtfltn ()
  % Allocate space for a floating point number.
  (let ((ptr  (gtheap (+ (floatpack) 1))))
    (setf (getmem ptr) (mkitem hwords-tag (- (floatpack) 1)))
    ptr
    ))
)

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

(de idinf (u)
   (cond ((null u) 128)
         ((cdr (explodec u)) 256)
         (t (char-code u))))

% Redefine this because idinf used to be a macro and so its expansion had
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
  (iplus2 (ilsh reloctag 30) (iland relocinf 16#3fffffff)))

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
  (iplus2 (ilsh reloctag 54) (LOGAND relocinf 16#003fffffffffffff)))

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

(preserve)

