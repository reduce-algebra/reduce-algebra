(off immediatequote)

(off usermode)
(copyd 'inump 'fixp)
(compiletime (copyd '*jumpon '*xjumpon))

%(on pcmac)% (tr depositinstruction)
(load "$pxnk/cross")
(load "$pnkl/sys-faslin")

(de binarywriteblock (channel blockbase blocksize)
  (fwrite blockbase 8 (quotient (plus2 1 blocksize) 2)  channel))
                                                                                
(setq loaddirectories!* (cons "/Users/winfried/psl/dist/lap/MacG4/"
loaddirectories!*))

(setq faslout-magic 199)
(setq addressingunitsperitem 8)
(load hash-decls)
(setq hash-table-size 18013)
(setq maxsymbols 15000)

(DefCMacro *JumpInType
       ((regp Anyp) (*tag (reg t5) ArgOne)
		     (cmpi 0 (reg t5) ArgTwo )
		     (bc false GT ArgThree)
		     (cmpi 0 (reg t5) 255) % negint-tag)
		     (bc true eq ArgThree))
       (             (*move ArgOne (reg t5))
		     (*tag (reg t6) (reg t5))
		     (cmpi 0 (reg t6) ArgTwo)
		     (bc false GT ArgThree)
		     (cmpi 0 (reg t6) 255) % negint-tag
		     (bc true eq ArgThree)))

(DefCMacro *JumpNotInType
       ((regp Anyp) (*tag (reg t5) ArgOne)
		     (cmpi 0 (reg t5) 255) % negint-tag
		     (bc true eq templabel)
		     (cmpi 0 (reg t5) ArgTwo)
		     (bc true gt ArgThree)
		    templabel)
       (             (*move ArgOne (reg t5))
		     (*tag (reg t5) (reg t5))
		     (cmpi 0 (reg t5) 255) % negint-tag
		     (bc true eq templabel)
		     (cmpi 0 (reg t5) ArgTwo)
		     (bc true gt ArgThree)
		    templabel))

(DefCMacro *wtimes3
           ((regp regp regp) (mulld ArgOne ArgTwo Argthree))
           ((regp regp short-immediate-p)
                             (mulli ArgOne ArgTwo Argthree))
           ((regp short-immediate-p regp)
                              (mulli ArgOne Argthree ArgTwo))
           ((regp regp anyp) (*move argthree (reg t1))
                             (*wtimes3 ArgOne ArgTwo (reg t1)))
           (        (*move ArgTwo (Reg t1))
                    (*move ArgThree (reg t2))
                    (mulld (reg t1) (Reg t1) (reg t2))
                    (*move (reg t1) ArgOne)))


%(faslout "load-psl")
%(de hu (x) 
%  (if x (progn (console-print-string (car x))
%               (console-newline)
%       (hu (cdr x)))))

%(hu '( "1" "2" "3"))

%(console-print-string "aha")
%(console-newline)
%(de hugo (x) (console-print-string x))
%(hugo "das sieht gut aus")
%(console-print-string "das wars")
%(console-newline)


%(faslend)


