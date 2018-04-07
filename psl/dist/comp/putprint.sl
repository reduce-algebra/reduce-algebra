%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PC:PUTPRINT.SL
% Description:    Printing/reading compressed .SYM file
% Author:         Mark Swanson
% Created:        22-June-1983
% Modified:       16 Feb 1984 1536-PST (Nancy Kendzierski)
% Mode:           Lisp
% Package:        
% Status:         Open Source: BSD License
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
% 07-Apr-88 (Julian Padget)
%  added fluid declarations for outputsymfile* and tobecompiledexpressions*
% 16 Feb 1984 1538-PST (Nancy Kendzierski)
%    Added standard header
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% These routines are replacements for current ones in LAP-TO-ASM.SL.
% Their purpose is to produce a more compact xxx.SYM file, thereby avoiding
% the long read/write times for this file.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(outputsymfile* tobecompiledexpressions*))

(de writesymfile nil
  (prog (newout oldout)
        %    NilList := nil;
        (setq oldout (wrs (setq newout (open outputsymfile!* 'output))))
        (print (list 'saveforcompilation 
                     (mkquote 
                      (cons 'progn (car tobecompiledexpressions!*)))))
        (saveidlist)
        (setqprint 'nextidnumber!*)
        (setqprint 'stringgensym!*)
        (mapobl (function putprintentryandsym))
        %    print list('Flag,MkQuote NilList, Mkquote('NilInitialvalue));
        (wrs oldout)
        (close newout)))

(de putprintentryandsym (x)
  (prog (y z)
        (setq y (get x 'entrypoint))
        (setq z (get x 'idnumber))
        (cond (y (if z
                   (putprintboth x y z)
                   (putprintentry x y)))
              (z (putprintidnumber x z)))
        (commentoutcode (progn
                          (when (setq y (get x 'initialpropertylist))
                            (putprint x 'initialpropertylist y))
                          nil))
        (cond ((setq y (get x 'initialvalue)) (putprint x 'initialvalue y))
              ((flagp x 'nilinitialvalue) %        NilList := Cons(X, NilList);
               (putprintflag1 x 'nilinitialvalue)))
        (when (equal (get x 'scope) 'external)
          (putprint x 'scope 'external)
          (putprint x 'asmsymbol (get x 'asmsymbol))
          (cond ((get x 'wvar) (putprint x 'wvar x))
                ((get x 'warray) (putprint x 'warray x))
                ((get x 'wstring) (putprint x 'wstring x))
                ((setq y (get x 'wconst)) (putprint x 'wconst y))))))

(de putprintaux(X)
  (prin2 " ")
  (cond ((idp x)(putprinidorpair x))
	((numberp x) (prin1 x))
	((stringp x)(prin1 x))
	(t (putprinidorpair x))))

(de putprinidorpair (X)
%print an ID or PAIR with a leading "'" mark (instead of using (QUOTE ...))
  (prin2 '!')
  (prin1 x))

(de putprint(the!-id the!-indicator the!-value)
% Output a (PUT ...) that READ will accept, but which is as compact as possible
  (prin2 "(PUT")
  (putprintaux the!-id)
  (putprintaux the!-indicator)
  (putprintaux the!-value)
  (prin2 ")")
  (terpri))

(de putprintboth(x y z)
  (cond ((eq x y) (prin2 "(AsmPut"))
	(T (prin2 "(AsmPutB")))
  (putprintaux x)
  (cond ((neq x y) (putprintaux y)))
  (putprintaux z)
  (prin2 ")")
  (terpri))
  
(de putprintidnumber(x z)
  (prin2 "(AsmPutI")
  (putprintaux x)
  (putprintaux z)
  (prin2 ")")
  (terpri))
  
(de putprintentry(x y)
  (prin2 "(AsmPutE")
  (putprintaux x)
  (putprintaux y)
  (prin2 ")")
  (terpri))
  
(de putprintflag1 (x y)
  (prin2 "(FLAG1")
  (putprintaux x)
  (putprintaux y)
  (prin2 ")")
  (terpri))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Auxiliary functions used to input the compacted .SYM file

% PUTs idnumber property z on ID x
(de AsmPutI(the!-id z)
  (put the!-id 'idnumber z)
  )

% PUTs entrypoint property y on ID x
(de AsmPutE(the!-id y)
  (put the!-id 'entrypoint y)
  )

% Used when a generated entrypoint is necessary
(de AsmPutB(x y z)
  (AsmPutE x y)
  (AsmPutI x z)
  )

% Used when routine name and entrypoint are identical
(de AsmPut(x z)
  (AsmPutE x x)
  (AsmPutI x z)
  )

