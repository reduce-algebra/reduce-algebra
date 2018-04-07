%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:CARCDR.SL 
% Title:        Composites of CAR and CDR, up to 4 levels 
% Author:       Eric Benson 
% Created:      17 August 1981 
% Modified:     22-Mar-84 09:27:19 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
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
% 10-Sep-93 (Herbert Melenk)
%   (car nil) and (cdr nil) -> error unless *fastcar = NIL
% 01-Dec-83 14:19:55 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
 (flag '(safecar1 safecdr1) 'internalfunction))

(compiletime
 (foreach x in % remove all compiler optimizations

	  '(caaaar caaar caar % for CAR and CDR composites

		   caaadr caadr cadr caadar cadar cdar caaddr caddr cddr
		   cadaar cdaar cadadr cdadr caddar cddar cadddr cdddr
		   cdaaar cdaadr cdadar cdaddr cddaar cddadr cdddar
		   cddddr)
	  do (put x 'savecmacro (remprop x 'pass-1-macro))))

(fluid '(*fastcar))

(setq *fastcar t)

(de caaaar (u)
  (cond ((pairp u) (caaar (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'caaaar))))

(de caaadr (u)
  (cond ((pairp u) (caaar (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'caaadr))))

(de caadar (u)
  (cond ((pairp u) (caadr (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'caadar))))

(de caaddr (u)
  (cond ((pairp u) (caadr (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'caaddr))))

(de cadaar (u)
  (cond ((pairp u) (cadar (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cadaar))))

(de cadadr (u)
  (cond ((pairp u) (cadar (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cadadr))))

(de caddar (u)
  (cond ((pairp u) (caddr (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'caddar))))

(de cadddr (u)
  (cond ((pairp u) (caddr (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cadddr))))

(de cdaaar (u)
  (cond ((pairp u) (cdaar (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdaaar))))

(de cdaadr (u)
  (cond ((pairp u) (cdaar (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdaadr))))

(de cdadar (u)
  (cond ((pairp u) (cdadr (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdadar))))

(de cdaddr (u)
  (cond ((pairp u) (cdadr (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdaddr))))

(de cddaar (u)
  (cond ((pairp u) (cddar (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cddaar))))

(de cddadr (u)
  (cond ((pairp u) (cddar (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cddadr))))

(de cdddar (u)
  (cond ((pairp u) (cdddr (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdddar))))

(de cddddr (u)
  (cond ((pairp u) (cdddr (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cddddr))))

(de caaar (u)
  (cond ((pairp u) (caar (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'caaar))))

(de caadr (u)
  (cond ((pairp u) (caar (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'caadr))))

(de cadar (u)
  (cond ((pairp u) (cadr (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cadar))))

(de caddr (u)
  (cond ((pairp u) (cadr (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'caddr))))

(de cdaar (u)
  (cond ((pairp u) (cdar (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdaar))))

(de cdadr (u)
  (cond ((pairp u) (cdar (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdadr))))

(de cddar (u)
  (cond ((pairp u) (cddr (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cddar))))

(de cdddr (u)
  (cond ((pairp u) (cddr (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdddr))))

(de safecar1 (u)
  (cond ((pairp u) (car u))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'car))))

(de safecdr1 (u)
  (cond ((pairp u) (cdr u))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdr))))

(de safecar (u)
  (cond ((pairp u) (car u))
        ((null u) nil)
        (t (nonpairerror u 'car))))

(de safecdr (u)
  (cond ((pairp u) (cdr u))
        ((null u) nil)
        (t (nonpairerror u 'cdr))))


(de caar (u)
  %.
  (cond ((pairp u) (safecar1 (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'caar))))

(de cadr (u)
  %.
  (cond ((pairp u) (safecar1 (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cadr))))

(de cdar (u)
  %.
  (cond ((pairp u) (safecdr1 (car u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cdar))))

(de cddr (u)
  %.
  (cond ((pairp u) (safecdr1 (cdr u)))
        ((and (null u)(null *fastcar)) nil)
        (t (nonpairerror u 'cddr))))

(compiletime
  (foreach x in % restore compiler optimizations

           '(caaaar caaar caar % for CAR and CDR composites

                    caaadr caadr cadr caadar cadar cdar caaddr caddr cddr
                    cadaar cdaar cadadr cdadr caddar cddar cadddr cdddr
                    cdaaar cdaadr cdadar cdaddr cddaar cddadr cdddar
                    cddddr)
           do (put x 'cmacro (remprop x 'savecmacro))))

