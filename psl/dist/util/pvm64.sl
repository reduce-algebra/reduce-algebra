%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           pvm64.sl
% Description:    Interface for pvm (3.4) connections
% Author:         Winfried Neun , ZIB Berlin
% Created:        1-March 2006
% Status:         Open Source: BSD License
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Revisions:
%
% This version will use pvm message passing for 64 bit items, even
% though pvm internally uses 32 bit elements.

% 15-Sep-1994 (Winfried Neun)
% fixed a problem with invocation of gc while preparing blocks for
% transport
% 20-April-1994 (Winfried Neun)
% Minor bug fixes, allowed vectors in lists to be transported
% preserving eq-ness of lists now.

% Note: 
% In most cases (i.e. PSL systems with the two heap model
% this PVM software uses the second heap in a similaar way like the garbage
% collector for intermediate storage. The gc may not be invoked while
% an expression is about to be sent.

(compiletime (load if-system))

(compiletime (flag '(nextobj pushnewitem pushnewitem1 popnewitem
		     writestringtopvm writeitemtopvm readitemfrompvm 
		     updateit wputv_spec getmem_spec gtheap_spec
		relocate-struct) 'iinternalfunction))

(compiletime (put 'memo 'opencode
                 '((*move (displacement (reg eax) 0) (reg eax)))))

(compiletime (put 'putmemo 'opencode
                 '((*move (reg ebx) (displacement (reg eax) 0)))))

(compiletime (ds mk32bititem(tag inf)
                (wor (wshift tag 27) (wand inf 16#3ffffff))))


% pvm constants
% return codes
%
(define-constant PvmOk               0)
(define-constant PvmBadparam        -2)
(define-constant PvmMismatch        -3)
(define-constant PvmNoData          -5)
(define-constant PvmNoHost          -6)
(define-constant PvmNoFile          -7)
(define-constant PvmNoMem           -10)
(define-constant PvmBadMsg          -12)
(define-constant PvmSysErr          -14)
(define-constant PvmNoBuf           -15)
(define-constant PvmNoSuchBuf       -16)
(define-constant PvmNullGroup       -17)
(define-constant PvmDupGroup        -18)
(define-constant PvmNoGroup         -19)
(define-constant PvmNotInGroup      -20)
(define-constant PvmNoInst          -21)
(define-constant PvmHostFail        -22)
(define-constant PvmNoParent        -23)
(define-constant PvmNotImpl         -24)
(define-constant PvmDSyserr         -25)
(define-constant PvmBadVersion      -26)
(define-constant PvmOutofRes        -27)
(define-constant PvmDupHost         -28)
(define-constant PvmCantStart       -29)
(define-constant PvmAlready         -30)
(define-constant PvmNoTask          -31)
(define-constant PvmNoEntry         -32)
(define-constant PvmDupEntry        -33)
(define-constant PvmOutOfResSMP	   -104) % Cray T3d only ?

%Option encoding

(define-constant PvmDataDefault     0)
(define-constant PvmDataRaw         1)
(define-constant PvmDataInPlace     2)

(define-constant PvmTaskDefault     0)
(define-constant PvmTaskHost        1)
(define-constant PvmTaskArch        2)
(define-constant PvmTaskDebug       4)

(define-constant PvmTaskExit        1)
(define-constant PvmHostDelete      2)
(define-constant PvmHostAdd         3)


(fluid '(*testpvm **allobjects** **allobjectsindex** *spec-pointer*))

(de start_slaves(nproc slave)
   (prog (mytid tids i who n msgtype data result hilf)

        (setq tids (gtwarray 32))
        (setq mytid (pvm_mytid))
        (pvm_spawn (strbase (strinf slave))
                0 0 (strbase (strinf "")) nproc tids)
        (pvm_initsend pvmdataraw)
	(setq **allobjectsindex** 256)  % 
	(return (cons mytid tids))))

(de order_slaves (tids nproc item taskname sendresult)

   (prog (i who n msgtype data result hilf)

% we have to ensure that we have a sufficient number of free cells.
% I hope 200000 is a good guess.

        (assert_space 200000)

	(setq **allobjects** NIL)
	(setq *spec-pointer* 0)

        (setq n 100 hilf (gtwarray 6))  % for &nproc etc
	(wputv hilf 4 (gtwarray 0))	% bottom pointer

	(writeitemtopvm 14 hilf tids nproc) % start of task
	(writeitemtopvm taskname hilf tids nproc)
	(writeitemtopvm sendresult  hilf tids nproc)
	(setq item (writeitemtopvm item hilf tids nproc))
	(when (pairp item)
		(wputv hilf 0
		  (wquotient *spec-pointer* addressingunitsperitem))
		(pvm_pkint hilf 2 1)
		(pvm_pkint oldheaplowerbound
		     (wtimes 2 
			(wquotient *spec-pointer* addressingunitsperitem)) 1)
		(pvm_mcast tids nproc (mkpair 0))
		(pvm_initsend pvmdataraw))
	(writeitemtopvm 17 hilf tids nproc)
	(delwarray (wgetv hilf 4) hilf)))

(de audition ()
   (let (result buf hilf bottom lastres taskname)

      (setq buf (pvm_nrecv -1 5))     % any message "5" around ?

      (if (izerop buf)  NIL
 
	(setq hilf (gtwarray 4))
	(setq bottom  (gtwarray 0))     % bottom pointer
	(pvm_bufinfo buf hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))
	(when *testpvm 
		(print (list "Getting a result from" (wgetv hilf 2))))
	(setq buf (pvm_recv (wgetv hilf 2) -1))
        (pvm_bufinfo buf hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))
        (setq taskname (wgetv hilf 1))
	(when *testpvm (print (list "taskname" taskname)))

	(while (not (eq result 17))
		(setq buf (pvm_recv (wgetv hilf 2) -1))
		(pvm_bufinfo buf hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))
		(setq result (wgetv hilf 1))
		(when (not (eq result 17))
			(setq lastres (readitemfrompvm result hilf t))
			(pushnewitem lastres (inf result))))

	(when *testpvm (print (list "arrived:" lastres)))
			
        (when (getd 'pvm_receive_hook) 
		(setq lastres (pvm_receive_hook lastres)))
	(delwarray bottom hilf)
	(cons taskname lastres))))

(de local_input ()
   (let (result buf hilf bottom lastres taskname sender mode)

      (setq buf (pvm_nrecv -1 14))     % any message "5" around ?

      (if (izerop buf)  NIL

        (setq hilf (gtwarray 4))
        (setq bottom  (gtwarray 0))     % bottom pointer
        (pvm_bufinfo buf hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))
	(setq sender (wgetv hilf 2))
        (when *testpvm
                (print (list "Getting a input from" sender)))
        (setq buf (pvm_recv sender  -1))
        (pvm_bufinfo buf hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))
        (setq taskname (wgetv hilf 1))
        (when *testpvm (print (list "taskname" taskname)))
	(setq buf (pvm_recv sender -1))
        (pvm_bufinfo buf hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))
	(setq mode (eq (wgetv hilf 1) 1))

        (while (not (eq result 17))
                (setq buf (pvm_recv sender -1))
                (pvm_bufinfo buf hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))
                (setq result (wgetv hilf 1))
                (when (not (eq result 17))
                        (setq lastres (readitemfrompvm result hilf nil))
                        (pushnewitem lastres (inf result))))

        (when *testpvm (print (list "arrived:" lastres)))

        (delwarray bottom hilf)
        (list sender (car lastres) (cdr lastres) mode taskname ))))


(de release_slaves (tids nproc)
	(writeitemtopvm 18 0 tids nproc)
	(pvm_exit))

(de nextobj (i)
    (let (res)
	(if (setq res (atsoc i **allobjects**) )
			(cdr res)
		(setq res **allobjectsindex**)
		(setq **allobjects** (cons (cons i res) **allobjects**))
		(setq **allobjectsindex** (iadd1 res))
		res)))

(compiletime
  (ds pointertagp (x)
    (and (wgreaterp x posint-tag) (wlessp x code-tag)))
)

(de pushnewitem (item num)
	(when (or (idp item) (pointertagp (tag item)))
	(setq **allobjects** (cons (cons num item) **allobjects**))))

(de pushnewitem1 (item num)
        (when (or (idp item) (pointertagp (tag item)))
        (setq **allobjects** (cons (cons item num) **allobjects**))))

(commentoutcode maybe that code is useless
(de pushnewitem (item num)
        (when (or (idp item) (pointertagp (tag item)))
	(setq *second_spec-pointer*
		 (wplus2 *second_spec-pointer*
			(wtimes2 -4 addressingunitsperitem)))
	(wputv *second_spec-pointer* 2 num)
	(wputv *second_spec-pointer* 3 item)
	(wputv *second_spec-pointer* 0 
		 (mkpair (wplus2 *second_spec-pointer*
                        (wtimes2 2 addressingunitsperitem))))
	(wputv *second_spec-pointer* 1 **allobjects**)
        (setq **allobjects** (mkpair *second_spec-pointer*))))

(de pushnewitem1 (item num)
        (when (or (idp item) (pointertagp (tag item)))
        (setq *second_spec-pointer*
                 (wplus2 *second_spec-pointer*
                        (wtimes2 -4 addressingunitsperitem)))
        (wputv *second_spec-pointer* 2 item)
        (wputv *second_spec-pointer* 3 num)
        (wputv *second_spec-pointer* 0
                 (mkpair (wplus2 *second_spec-pointer*
                        (wtimes2 2 addressingunitsperitem))))
        (wputv *second_spec-pointer* 1 **allobjects**)
        (setq **allobjects** (mkpair *second_spec-pointer*))))
)

(de popnewitem (item)
	(let (found)
		(setq found (assoc item **allobjects**))
		(unless found (print (list "** Lost  object"
				item "in " **allobjects**)) (fehler))
	(cdr found)))
	

(de writestringtopvm (item hilf)
	(wputv hilf 0 (size item))
        (pvm_pkint hilf 2 1)
        (pvm_pkstr (strbase (strinf item)))
        (mkstr (nextobj item)))

(de writeitemtopvm (item hilf tids nproc)
 (let (newitem len)
  (cond ((posintp item) (pvm_mcast tids nproc item) item)
        ((negintp item) (pvm_mcast tids nproc (wshift (wshift item 1) -1))
			item)
	((idp item)	(if (wlessp (idinf item) 255)
				(setq item (mkitem 14 (idinf item)))
			(writestringtopvm (symnam (idinf item)) hilf)
			(setq item (mkitem 14 (nextobj item)))
			(pvm_mcast tids nproc item))
			(pvm_initsend pvmdataraw)
			item)
        ((fixnp item)	(pvm_pkint (strbase (strinf item)) 2 1)
			(setq item (mkfixn (nextobj item)))
			(pvm_mcast tids nproc item)
			(pvm_initsend pvmdataraw)
			item)
        ((bigp item)	(setq len (bsize item))
			(wputv hilf 0
				(if (bminusp item) (minus len) len))
			(pvm_pkint hilf 2 1)
			(pvm_pkint (wplus2 (strinf item)
				 (times2 2 addressingunitsperitem))
				 (wties2 2 len) 1)
			(setq item (mkbign (nextobj item)))
			(pvm_mcast tids nproc item)
			(pvm_initsend pvmdataraw)
			item)
	((vectorp item) (if (setq newitem (atsoc item **allobjects**))
				(mkvec (cdr newitem))
			(setq len (veclen (vecinf item)))
			(setq newitem (gtheap_spec (wplus2 2 len)))
			(pushnewitem1 item newitem)
			(wputv_spec  newitem 0  (mkitem hvect-tag len))
			(for (from i 1 (wplus2 1 len))
			  (do (wputv_spec  newitem i (wgetv (inf item) i))
			      (updateit (wplus2 newitem 
					(wtimes2 i addressingunitsperitem))
					hilf tids nproc)))
                        (mkvec newitem)))
        ((floatp item)	(pvm_pkdouble (strbase (strinf item)) 1 1)
			(setq item (mkfltn (nextobj item)))
			(pvm_mcast tids nproc item)
			(pvm_initsend pvmdataraw)
			item)
	((stringp item) (setq item (writestringtopvm item hilf ))
			(pvm_mcast tids nproc item)
			(pvm_initsend pvmdataraw)
			item)
	((pairp item)   (if (setq newitem (atsoc item **allobjects**))
                                (mkpair (cdr newitem))
			(setq newitem (gtheap_spec (pairpack)))
			(pushnewitem1 item newitem)
			(wputv_spec newitem 0 (car item))
			(wputv_spec newitem 1 (cdr item))
			(updateit newitem hilf tids nproc)
			(updateit (wplus2 newitem addressingunitsperitem)
				hilf tids nproc)
			(mkpair newitem)))
	(t (fehler item))
)))

(de updateit (itp hilf tids nproc)
     (let ((it (getmem_spec itp)) newitem)
	(cond ((pairp it) (wputv_spec itp 0
			 (writeitemtopvm it hilf tids nproc)))
	      ((pointertagp (tag it)) (wputv_spec itp 0
			 (writeitemtopvm it hilf tids nproc)))
	      ((idp it) (if (wlessp (idinf it) 255)
				(wputv_spec itp 0 (mkitem 14 (idinf it)))
                           (if (setq newitem (atsoc it **allobjects**))
			     (wputv_spec itp 0 (mkitem 14 (cdr newitem)))
			     (wputv_spec itp 0 
			 	  (writeitemtopvm it hilf tids nproc))))
))))

(de wputv_spec (adr ind val)
	(setq adr (wplus2 oldheaplowerbound adr))
	(setq adr (wplus2 adr (wtimes2 ind addressingunitsperitem)))
	(putmem adr val))

(de getmem_spec (adr)
	(getmem (wplus2 oldheaplowerbound adr)))

(de gtheap_spec(n)
    (let ((res *spec-pointer*))
	(setq *spec-pointer*
		 (wplus2 *spec-pointer* 
			(wtimes2 n addressingunitsperitem)))
	res))

(de readitemfrompvm (item hilf huge)
 (let (newitem len)
  (cond ((posintp item) item)
	((eq (tag item) 15) (ashift (wshift item 1) -1))
			    % a negint!
	((eq (tag item) 14) % This is an ID in disguise
			(if (wlessp (idinf item) 256)
				 (mkid (idinf item))
			(setq newitem
			  (readitemfrompvm (mkstr (inf item)) hilf nil))
			(intern newitem)))
	((fixnp item)	(setq newitem (gtfixn))
			(pvm_upkint (strbase newitem) 2 1)
			(mkfixn newitem))
	((bigp item)	(pvm_upkint hilf 2 1)
			(setq len (wgetv hilf 0))
			(setq newitem (if (minusp len)
				(gtneg (setq len (minus len)))
				(gtpos len)))
			(pvm_upkint (wplus2 (strinf newitem)
				(times2 2 addressingunitsperitem))
				(wtimes2 2 len) 1)
			newitem)
	((floatp item)	(setq newitem (gtfltn))
			(pvm_upkdouble (strbase newitem) 1 1)
			(mkfltn newitem))
	((stringp item) (pvm_upkint hilf 2 1)
			(setq len (wgetv hilf 0))
			(setq newitem (gtstr len))
			(pvm_upkstr (strbase (strinf newitem)))
			(mkstr newitem))
	((pairp item)	(pvm_upkint hilf 2 1)
			(setq len (wgetv hilf 0))
			(setq newitem (gtheap len))
                (if (not huge)
		 (pvm_upkint newitem (wtimes2 2 len) 1)
                 (for (from i 1 (wquotient len 2048))
                    (do (progn (when *testpvm (print "reading 2048 words"))
			(pvm_upkint 
                          (wplus2 newitem
                                (wtimes2 (isub1 i) addressingunitsperitem))
                                2048 1))))
                 (when (not (eq 0 (wremainder len 2048)))
                       (pvm_upkint (wplus2 newitem (wtimes2 
                        (wtimes2 (wquotient len 2048) 2048)
                                addressingunitsperitem))                        
                        (wremainder len 2048) 1)))

			(relocate-struct newitem len)
			(mkpair (wplus2 newitem (inf item))))
	(t (fehler item))
)))

(de relocate-struct (newitem len)
 (let (it )
  (setq len (isub1 len))
  (for (from i 0 len 1)
	(do (setq it (wgetv newitem i))
	    (cond ((pairp it) (wputv newitem i (wplus2 (inf newitem) it)))
		((eq (tag it) 14)
	 	   (if (wlessp (idinf it) 255)
			(wputv newitem i (mkid (inf it)))
			(wputv newitem i (popnewitem (idinf it)))))
		((vectorp it) (wputv newitem i (wplus2 (inf newitem) it)))
		((pointertagp (tag it))
		   (wputv newitem i (popnewitem (idinf it)))))
))))

(de slave ()

   (prog (nproc mytid i n master result msgtype data hilf item olditem
		sendresult taskname tomove)

	(setq **allobjects** NIL **allobjectsindex** 256)
        (setq i 0 hilf (gtwarray 4))  % for &nproc etc

        (setq mytid (pvm_mytid))
        (setq msgtype 0 item 0)
	(setq master (gtwarray 1))
	(wputv master 0 (pvm_parent))

      (when *testpvm (print (list mytid " slave ready")))
	
      (while (not (eq item 18)) % sit here and wait for jobs
       (setq item 0)
       (while (not (eq item 17)) % loop over parts of a form
        (setq data (pvm_recv (wgetv master 0) -1))
        (pvm_bufinfo data hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))

	(setq olditem (wgetv hilf 1))
	(if (eq olditem 14) 
	    (progn (when *testpvm (print (list mytid "a new task")))
		(setq data (pvm_recv (wgetv master 0) -1))
		(pvm_bufinfo data hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))
		(setq taskname (wgetv hilf 1))
		(setq data (pvm_recv (wgetv master 0) -1))
                (pvm_bufinfo data hilf (wplus2 hilf addressingunitsperitem)
			 (wplus2 (wtimes2 2 addressingunitsperitem) hilf))
                (setq sendresult (eq (wgetv hilf 1) 1))
		(when *testpvm
		  (print (list mytid
			"taskname" taskname "sendresult" sendresult))))
	
	(when *testpvm
         (print (list mytid "Arrived" data (wgetv hilf 0)))
	 (print (list mytid "in LISP"  (tag olditem) (inf olditem))))
	(setq item (readitemfrompvm olditem hilf nil))
	(pushnewitem item (inf olditem))
	(when *testpvm
	 (print (list mytid "in LISP"  (tag item) (inf item) item)))

        (when (getd 'pvm_receive_hook)
                (setq item (pvm_receive_hook item)))
 
	(unless (eq item 17)
		(if (pairp item) (setq result (eval item))))))

	(when sendresult % send back result if master likes it
		(assert_space 200000)
		(setq *spec-pointer* 0 )
		(pvm_initsend pvmdataraw)
		(pvm_send (wgetv master 0) 5) % results will come
		(pvm_send (wgetv master 0) taskname)
		(setq item (writeitemtopvm result hilf master 1))
        	(when (pairp item)
                 (wputv hilf 0
		  (setq tomove
                   (wquotient *spec-pointer* addressingunitsperitem)))
		 (when *testpvm
			(prin2t (list "Words to move: " tomove)))
                 (pvm_pkint hilf 2 1)
		 (for (from i 1 (wquotient tomove 1024))
		    (do (when *testpvm
                        (printf "sending partial results%w %n"
				 (wquotient tomove 1024)))
			(pvm_pkint 
			  (wplus2 oldheaplowerbound
				(wtimes2 (isub1 i) addressingunitsperitem))
				2048 1)
		    (sleep 10)
		    (when *testpvm
			(print "sending partial results"))))
		 (when (not (eq 0 (wremainder tomove 2048)))
		       (pvm_pkint (wplus2 oldheaplowerbound (wtimes2 
			(wtimes2 (wquotient tomove 2048) 2048)
				addressingunitsperitem))
			(wremainder tomove 2048) 1))
                 (pvm_send (wgetv master 0) (mkpair 0))
                 (pvm_initsend pvmdataraw)
		 (setq **allobjects** NIL **allobjectsindex** 256))
		(pvm_send (wgetv master 0) 17)) % end of results
	)
	(pvm_exit)))

(de assert_space(n)
        (when (wlessp (known-free-space) n)
                (reclaim)
                (when (wlessp (known-free-space) n)
                    (set-heap-size (wplus2 (set-heap-size nil) n)))))


% The following examples are taken from the pvm user's manual
% and PSLified.
(commentoutcode 
(de master (nproc slave )

   (prog (mytid tids i who n msgtype data result hilf)

	(setq data (gtwarray 100))
	(setq result (gtwarray 32))
	(setq tids (gtwarray 32))
        (setq n 100 hilf (gtwarray 1))  % for &nproc etc

	(setq mytid (pvm_mytid))
	
        (pvm_spawn (strbase (strinf slave))
		0 0 (strbase (strinf "")) nproc tids)

	(for (from i 0 100) (do (wputv data i i)))

	(pvm_initsend pvmdataraw)
	(wputv hilf 0 nproc) (pvm_pkint hilf 2 1)
	(pvm_pkint tids nproc 1)
	(wputv hilf 0 n) (pvm_pkint hilf 2 1)
	(pvm_pkint data (wtimes2 2 n) 1)
	(pvm_mcast tids nproc 0)
	
	(setq msgtype 5)

	(for (from i 0 (isub1 nproc) 1) (do
		(pvm_recv -1 msgtype)
		(pvm_upkint hilf 2 1)
		(pvm_upkint (wplus2 result (wtimes2 (wgetv hilf 0)
					addressingunitsperitem)) 2 1)
		(printf "I got %w from %w %n" (wgetv result (wgetv hilf 0))
			(wgetv hilf 0))
		))
	(pvm_exit)))

(de slave ()

   (prog (nproc me mytid tids i n master msgtype data result hilf)

        (setq data (gtwarray 100))
        (setq tids (gtwarray 32))
        (setq i 0 hilf (gtwarray 1))  % for &nproc etc

        (setq mytid (pvm_mytid))

	(setq msgtype 0)

        (pvm_recv -1 msgtype)
        (pvm_upkint hilf 2 1) (setq nproc (wgetv hilf 0))
        (pvm_upkint tids nproc 1)
        (pvm_upkint hilf 2 1) (setq n (wgetv hilf 0))
        (pvm_upkint data 2 1)

 % determine which slave I am : 0 .. nproc -1

	(while (not me) 
		(if (eq mytid (wgetv tids i))
			(setq me i)
			(setq i (iadd1 i))))

	(setq result (for (from i 0 n ) (sum (wgetv data i))))
	(setq result (times2 result me))

 % result is  sum(data) mod me

 % send it back

        (pvm_initsend pvmdatadefault)
        (wputv hilf 0 me) (pvm_pkint hilf 2 1)
        (wputv hilf 0 result) (pvm_pkint hilf 2 1)
	(setq msgtype 5)
	
	(setq master (pvm_parent))
        (pvm_send master msgtype)

        (pvm_exit)))
)
