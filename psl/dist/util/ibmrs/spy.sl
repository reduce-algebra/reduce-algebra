%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:              spy.sl   
% Description:       Spying by ticks
% Author:            H. Melenk ,W. Neun       ZIB Berlin
% Created:           10-Mar-89 , derived from Cray version
% Mode:              Lisp
% Package:           Utilities (Cray-UNICOS)
% Status:            Experimental (Do not distribute)
%
% Copyright (c) 1989, Konrad Zuse Zentrum Berlin, all rights reserved
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% SPYing LISP via UNICOS SPY calls          %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(compiletime (remprop 'car 'openfn))
(compiletime (remprop 'cdr 'openfn)) 
 
(compiletime (flag '(spyjoin spysort spysort1 getaddresstable)
                                             'internalfunction))
 
(fluid '(&spylow& &spyhigh&  % interval of interest during spy run
         &spyres&     % intermediate: address list of functions
                      % list of pairs ( addr . function)
                      % will be sorted by addresses
         &spybucket&  % bucket size from initialization call
         &spyminimum& % minimum refs during printing
         &spying&     % indicator that spy is active
         &spymintime& % minimal time slice for spying
         &spytotal&   % total refs counter while printing
         &spysysrefs& % address table of those functions, which are
                      % not known at runtime via symfnc
                      % list of pairs ( addr . function)
         ))
 
(setq &spyminimum& 5)
(setq &spymintime& 40)
(setq &spying& nil)
(setq &spysysrefs& nil)
 
(de spyon (fwa lwa timeslice bucketsize power) %building table for f$spy
  (prog (vbl diff )
   (setq diff (wquotient (wplus2 (wdifference lwa fwa) bucketsize)
                            bucketsize))
   (setq &spying& (gtwarray (wshift (wplus2 3 diff) -1 )))
   (clear-memory &spying& (wshift (wplus2 3 diff) -1)) % set to zero
   (putmem &spying& (wshift (wplus2 2 diff) -1))
   (setq &spying& (mkvec &spying&))
   (setq vbl (gtvect 6))
   (unix-profile (wplus2 (mkstr &spying&) 4) % buffer
                 (wshift diff  1) % buffersize in bytes
                 fwa              % fwa
                 (wshift 16#10000 (wminus power))) % magic, see:  man profil
) )
 
(de spyoff (bufferleng) 
  (prog (vbl buffer)
   (unix-profile 0 0 0 0)   % spy off
   (setq buffer &spying&)
   (setq &spying& nil)
   (return buffer)
) )
 
(de spywhole (bucket)    %spy whole code area
    (prog (power)
    (if (memq bucket '(1 2 4 8 16 32 64 128 256)) t (setq bucket 4))
    (setq power (cadr (assoc bucket '((2 0) (4 1) (8 2) (16 3) (32 4)
                                     (64 5) (128 6) (256 7)))))
    (setq &spyhigh& nextbps)
    (setq &spylow&  bpslowerbound)
    (setq &spybucket&  bucket)
    (spyon &spylow& &spyhigh& &spymintime& bucket power)
))
 
(de spyprint ()         %print results sorted
    (prog (length result addresstable)
 
       (when (not &spying&) (return nil))
 
       (setq length (wquotient (wdifference &spyhigh& &spylow&)
                               &spybucket&))
       (setq length (wplus2 length 1))
       (setq result (spyoff length))
       (setq addresstable (getaddresstable))
       (setq addresstable (spyjoin addresstable result ))
       (mapc addresstable (function (lambda (x)
                                       (when (wgreaterp (car x)
                                                        &spyminimum&)
                                           (prin2 (car x))
                                           (tab 10)
                                          (let ((z (quotient
                                                   (times2 (car x)1000)
                                                    &spytotal& )))
                                           (prin2 (wquotient z 10))
                                           (prin2 ".")
                                           (prin2 (wremainder z 10))
                                           (prin2 "%")
                                           (tab 20)
                                           (prin2t (cdr x)))))))))
 
(de getaddresstable ()
     (setq &spyres& (append &spySysRefs& nil))
     (mapobl (function (lambda (x)
                         (cond
                           ((funboundp x) nil)
                           ((flambdalinkp x) nil)
                           (t (setq &spyres&
                                  (cons (cons (symfnc (idinf x)) x) &spyres&)))
     )        )        ) )
     (setq &spyres& (cons (cons heap 'end-of-code) &spyres&))
     (spysort (prog1 &spyres&
                     (setq &spyres& nil)))
)
 
(compiletime
   (ds spyvecitm (x y)
      (prog2
        (setq v (vecitm x (wshift y -1)))
        (if (eq (wand y 1) 1) (wand v 16#ffff)
                              (wshift v -16))))
)
        
(de spyjoin (addrtable vector)
     (prog (base counter currentfunction currenthigh currentcount
            final veclength nextbucket v)
          (setq veclength (veclen (vecinf vector)))
          (setq vector (inf vector))
          (setq counter 0)
          (setq &spytotal& 0)
      loop
          (while (and (wlessp counter veclength)
                      (spyvecitm vector (wplus2 counter 4))
                      (eq (spyvecitm vector counter) 0))
                           (setq counter (wplus2 counter 1)))
          (setq base (wplus2 &spylow& (wtimes2 &spybucket& counter)))
          (while (and addrtable (wlessp (caadr addrtable) base))
                  (setq addrtable (cdr addrtable)))
 
          (when (or (wgeq counter veclength) (not addrtable)
                    (not (spyvecitm vector (wplus2 counter 4))))
                     (return (spysort1 final)))
 
          (setq currentfunction (cdar addrtable))
          (setq currentcount 0)
          (setq currenthigh (caadr addrtable))
          (setq nextbucket (wplus2 base &spybucket&))
 
          (while (and (wleq nextbucket currenthigh)
                      (spyvecitm vector (wplus2 counter 4))
                      (wlessp counter veclength))
                  (setq currentcount (wplus2 currentcount
                                           (spyvecitm vector counter)))
                  (setq base (wplus2 base &spybucket&))
                  (setq nextbucket (wplus2 base &spybucket&))
                  (setq counter (wplus2 counter 1))
          )
          (setq currentcount (wplus2 currentcount
                                           (spyvecitm vector counter)))
          (when (and (wgreaterp currentcount 0)
                     (not (memq currentfunction '(buildrelocationfields
                          externalmarkfrombase updatesymbols
                          copyfromstaticheap current-stack-pointer
                          externalupdateitem makeidfreelist !%reclaim
                          markfromvectorregisters updateallbases))))
% keep gc off percentage
                 (setq &spytotal& (wplus2 &spytotal& currentcount))
                 (setq final
                      (cons (cons currentcount currentfunction) final)))
          (when (pairp addrtable) (setq addrtable (cdr addrtable)))
            % because vector size calculation is sometimes a little bit
            % wrong (too large)
          (go loop)
)  )
 
(de spysort (l)        % sort labels to ascending sequence
   (prog (changed actptr x1 caractptr cdractptr)
    loop (setq changed nil)
         (setq actptr l)
         (while (setq cdractptr (cdr actptr))
                (setq caractptr (car actptr)) 
                (when (wgreaterp (car caractptr) (caar cdractptr))
                      (setq changed t)
                      (setq x1 (car cdractptr))
                      (rplaca cdractptr caractptr)
                      (rplaca actptr x1))
                (setq actptr cdractptr))
         (when changed (go loop))
         (return l)
) )
 
(de spysort1 (l)        % sort labels to descending sequence
   (prog (changed actptr x1)
         (when (null l) (return NIL))
    loop (setq changed nil)
         (setq actptr l)
         (while (cdr actptr)
                (when (wlessp (caar actptr) (caadr actptr))
                      (setq changed t)
                      (setq x1 (cadr actptr))
                      (rplaca (cdr actptr)(car actptr))
                      (rplaca actptr x1))
                (setq actptr (cdr actptr)))
         (when changed (go loop))
         (return l)
) )
 
(de clear-memory (ptr amount)
%  (fast-clear ptr amount))
      (for (from i 0 amount)
       (do (putmem (wplus2 (inf ptr) i ) 0))))

(de quit ()
    (when &spying& (spyprint))
    (exit-with-status 0) )
