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

(global '(heapupperbound heaplowerbound heaplast heaptrapbound heaplast
          heaptrapped nextbps lastbps))

(setq lastbps 20000)
(setq nextbps 0)
(setq bpsheap (mkvect (sub1 lastbps)))

(setq highpointer 20000)
(setq lowpointer 0)
(setq mainheap (mkvect (sub1 highpointer)))

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

(de gtstr (upper-bound)
  % Allocate a string of UPPER-BOUND+1 characters.
  (let* ((n-words  (strpack upper-bound))
	 (str      (gtheap (+ 1 n-words))))
    (setf (getmem str) (mkitem hbytes-tag upper-bound))
    (setf (wgetv str n-words) 0)  % clear last word, including last byte
    str
    ))

% GTCONSTSTR is defined in the kernel

(de gthalfwords (upper-bound)
  % Allocate space for a halfwords vector of UPPER-BOUND+1 elements.
  (let* ((n-words  (halfwordpack upper-bound))
	 (ptr      (gtheap (+ n-words 1))))
    (setf (getmem ptr) (mkitem hhalfwords-tag upper-bound))
    ptr
    ))

(de gtvect (upper-bound)
  % Allocate space for a vector of UPPER-BOUND+1 elements.
  (let ((ptr  (gtheap (+ (vectpack upper-bound) 1))))
    (setf (getmem ptr) (mkitem hvect-tag upper-bound))
    ptr
    ))

(de gtevect (upper-bound)
  % Allocate space for an evector of UPPER-BOUND+1 elements.
  (let ((ptr  (gtheap (+ (evectpack upper-bound) 1))))
    (setf (getmem ptr) (mkitem hvect-tag upper-bound))
    ptr
    ))

(de gtcontext ()
  % allocate space for an environment descriptor (7 entries)
  (let ((ptr (gtheap (+ (contextpack) 1))))
    (setf (getmem ptr) (mkitem hvect-tag (contextpack)))
    ptr))

(de gtbvect (upper-bound)
  % allocate space for a bvector - four words per entry
  (let ((ptr (gtheap (+ (bvectpack upper-bound) 1))))
    (setf (getmem ptr) (mkitem hvect-tag (bvectpack upper-bound)))
    ptr))

% GTWRDS is defined in the kernel

(de gtfixn ()
  % Allocate space for a fixnum.
  (let ((ptr  (gtheap (+ (fixpack) 1))))
    (setf (getmem ptr) (mkitem hwords-tag (- (fixpack) 1)))
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

(de idinf (u)
   (cond ((null u) 128)
         ((cdr (explodec u)) 256)
         (t (char-code u))))

% Redefine this because idinf used to be a macro...

(de findidnumber (u)
  (prog (i)
        (return (cond ((ileq (setq i (idinf u)) 128) i)
                      ((setq i (get u fasl-idnumber-property*)) i)
                      (t (put u fasl-idnumber-property* (setq i nextidnumber*))
                         (setq orderedidlist* (tconc orderedidlist* u))
                         (setq nextidnumber* (iadd1 nextidnumber*)) i)))))



(preserve)

