%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:EXPLODE-COMPRESS.SL 
% Title:        Write to/read from a list; includes FlatSize 
% Author:       Eric Benson 
% Created:      24 September 1981 
% Modified:     22-Mar-84 11:28:56 (Brian Beach) 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% (c) Copyright 1982, University of Utah
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
%
% Revisions:
%
% 8 Aug 1992 (Winfried Neun)
%  Optimized flatsize and flatsize2 for special case (big bignums)
% 22 Oct 1984 2142-PDT (Brian Beach)
%  Made COMPRESS turn off COMPRESSING* when an error occurs.
% 26 Jan 1984 0959-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:43:48 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(explodeendpointer* % pointer used to RplacD new chars onto

         compresslist* % list being compressed

         *compressing))

% if T, don't intern IDs when read
(fluid '(unreadbuffer lineposition))

(de explodewritechar (channel ch)
  (rplacd explodeendpointer* (list (mkid ch)))
  (setf explodeendpointer* (cdr explodeendpointer*)))

(de explode (u)
  %. S-expr --> char-list
  (prog (result)
        (setq result (setf explodeendpointer* (cons nil nil)))
        (setf (wgetv lineposition 3) 0)
        (channelprin1 '3 u)
        (return (cdr result))))

(de explode2 (u)
  %. Prin2 version of Explode
  (prog (result)
        (setq result (setf explodeendpointer* (cons nil nil)))
        (setf (wgetv lineposition 3) 0)
        (channelprin2 '3 u)
        (return (cdr result))))

(fluid '(flatsizeaccumulator))

(setq flatsizeaccumulator nil)

(de flatsizewritechar (channel ch)
  (setq flatsizeaccumulator (wplus2 flatsizeaccumulator 1)))

(compiletime (flag '(expt10) 'internalfunction))

(fluid '(bbits!*))

(de flatsize (u)
  %. character length of S-expression
  (if (and (bigp u) (eq outputbase* 10) (wgreaterp (bsize u) 9)
		    (posintp bbits!*) (wleq bbits!* bitsperword))
	(prog (length quot)
		(setq length (wtimes2 bbits!* (isub1 (bsize u))))
		(setq length (fix (times2 length 0.30102999566))) % log10 (2)
%		(setq quot (quotient u (expt10 length)))
                (setq quot (quotient (lshift u (minus length))
                                        (expt 5 length)))
		(setq flatsizeaccumulator 0)
		(setf (wgetv lineposition 4) 0)
		(channelprin1 '4 quot)
		(return (plus2 length (mkint flatsizeaccumulator))))

   (progn
    (setq flatsizeaccumulator 0)
    (setf (wgetv lineposition 4) 0)
    (channelprin1 '4 u)
    (mkint flatsizeaccumulator))))


(de flatsize2 (u)
  %. Prin2 version of FlatSize
  (if (and (bigp u) (eq outputbase* 10) (wgreaterp (bsize u) 9)
		    (posintp bbits!*) (wleq bbits!* bitsperword))
        (prog (length quot)
                (setq length (wtimes2 bbits!* (isub1 (bsize u))))
                (setq length (fix (times2 length 0.30102999566))) % log10 (2)
		(setq quot (quotient u (expt10 length)))
                (setq flatsizeaccumulator 0)
                (setf (wgetv lineposition 4) 0)
                (channelprin2 '4 quot)
                (return (plus2 length (mkint flatsizeaccumulator))))

  (progn 
   (setq flatsizeaccumulator 0)
   (setf (wgetv lineposition 4) 0)
   (channelprin2 '4 u)
   (mkint flatsizeaccumulator))))

(fluid '(exptlist!*))

(de expt10(n)

(prog (el x xx)

   (when (not (posintp n)) (return (expt 10 n)))

   (setq x 1 el exptlist!*)

   (while (and (neq n 0) el)
       (when (eq (iland n 1) 1) (setq  x (times2 (car el)  x)))
       (setq n  (wquotient n 2))
       (setq el (cdr el )))

   (if (eq n 0) (return x)
             (setq xx (lastcar exptlist!*))
	     (setq xx (times2 xx  xx))
             (setq exptlist!* (append exptlist!* (ncons xx ))))
 
   (while (neq n 0)
       (when (eq (iland n 1) 1) (setq x (times2 x  xx)))
       (when (neq 0 (setq n  (wquotient n 2)))
            (setq xx (times2 xx  xx))))

   (return x)

))

(setq exptlist!* (list 10 100 10000))

(fluid '(atendoflist))

(setq atendoflist nil)

(de compressreadchar (channel)
  (prog (nextentry)
        (when atendoflist
          (return (compresserror)))
        (unless (pairp compresslist*)
          (setq atendoflist 't)
          (return (char blank)))
        (setq nextentry (car compresslist*))
        (setf compresslist* (cdr compresslist*))
        (return (lisp2char nextentry))))

(de clearcompresschannel ()
  (setf (wgetv unreadbuffer 3) (char null))
  (setq atendoflist 'nil))

(de compresserror ()
  (setf *compressing nil)
  (stderror "Poorly formed S-expression in COMPRESS")
  )

(de compress (compresslist*)
  %. Char-list --> S-expr
  (prog (*compressing)
        (setq *compressing t)
        (clearcompresschannel)
        (return (channelread 3))))

(de implode (compresslist*)
  %. Compress with IDs interned
  (progn (clearcompresschannel)
         (channelread 3)))

