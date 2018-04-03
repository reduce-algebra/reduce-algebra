%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:READ.SL 
% Title:        S-expression parser 
% Author:       Eric Benson 
% Created:      28 August 1981 
% Modified:     31-Dec-84 11:04:49 (Cris Perdue)
% Package:      Kernel 
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of in* and out*.
% 31-Dec-84 11:04:11 (Cris Perdue)
%  Added second argument to channelreadvector since it is passed
%  two, being a read macro.
% 31-May-84 10:53:10 (Brian Beach)
%  Call on IDAPPLY2 --> IDAPPLY.
% 01-Dec-83 15:01:01 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(in* out*))

(fluid '(currentreadmacroindicator* % Get to find read macro function

         currentscantable* % vector of character types

         lispscantable* % CurrentScanTable!* when READing

         *insidestructureread))

% indicates within compound read
(global '(toktype* % Set by token scanner, type of token
          $eof$))

% has value returned when EOF is read
(setq currentreadmacroindicator* 'lispreadmacro)

(compiletime
  (flag '(dotcontexterror) 'internalfunction))

(de channelreadtokenwithhooks (channel)
  % Scan token w/read macros
  %
  % This is ReadToken with hooks for read macros
  %
  (prog (tkn fn)
        (setq tkn (channelreadtoken channel))
        (when (and (eq toktype* 3)
                   (setq fn (get tkn currentreadmacroindicator*)))
          (return (idapply fn (list channel tkn))))
        (return tkn)))

(de channelread (channel)
  %. Parse S-expression from channel
  (prog (currentscantable* currentreadmacroindicator*)
        (setq currentscantable* lispscantable*)
        (setq currentreadmacroindicator* 'lispreadmacro)
        (return (channelreadtokenwithhooks channel))))

(de read ()
  % Parse S-expr from current input
  (makeinputavailable)
  (channelread in*)
  )

(de channelreadeof (channel ef)
  % Handle end-of-file in Read
  (if *insidestructureread
    (let (*insidestructureread)
    	 (stderror (bldmsg "Unexpected EOF while reading on channel %r" channel)))
    $eof$))

(de channelreadquotedexpression (channel qt)
  % read macro '
  (mkquote (channelreadtokenwithhooks channel)))

(de channelreadlistordottedpair (channel pa)
  % read macro (
  %
  % Read list or dotted pair.  Collect items until closing right paren.
  % Check for dot context errors.
  %
  (prog (elem startpointer endpointer *insidestructureread)
        (setq *insidestructureread t)
        (setq elem (channelreadtokenwithhooks channel))
        (when (eq toktype* 3)
          (cond ((eq elem '!.) (return (dotcontexterror)))
                ((eq elem '!)) (return nil))))
        (setq startpointer (setq endpointer (list elem)))
   loopbegin
        (setq elem (channelreadtokenwithhooks channel))
        (when (eq toktype* 3)
          (cond ((eq elem '!)) (return startpointer))
                ((eq elem '!.)
                 (setq elem (channelreadtokenwithhooks channel)) (if (and
                                                                      (eq
                                                                       toktype*
                                                                       3)
                                                                      (or
                                                                       (eq
                                                                        elem
                                                                        '!))
                                                                       (eq
                                                                        elem
                                                                        '!.)))
                   (return (dotcontexterror))
                   (progn (rplacd endpointer elem)
                          (setq elem (channelreadtokenwithhooks channel))
                          (if (and (eq toktype* 3) (eq elem '!)))
                            (return startpointer)
                            (return (dotcontexterror))))))))
        % If we had splice macros, I think they would be checked here
        (rplacd endpointer (list elem))
        (setq endpointer (cdr endpointer))
        (go loopbegin)))

(de channelreadrightparen (channel tok)
  % Ignore right parens at the top
  (if *insidestructureread
    tok
    (progn (cond ((not (eq channel stdin*)) % if not reading from the terminal

                  (errorprintf "*** Unmatched right parenthesis")))
           (channelreadtokenwithhooks channel))))

(de dotcontexterror ()
  % Parsing error
  (ioerror "Dot context error"))

% List2Vector is found in TYPE-CONVERSIONS.RED
(de channelreadvector (channel token)
  % read macro [
  (prog (elem startpointer endpointer *insidestructureread)
        (setq *insidestructureread t)
        (setq startpointer (setq endpointer (cons nil nil)))
        (while (progn (setq elem (channelreadtokenwithhooks channel))
                      (or (neq toktype* 3) (neq elem '!])))
          (rplacd endpointer (list elem))
          (setq endpointer (cdr endpointer)))
        (return (list2vector (cdr startpointer)))))

(put '!' 'lispreadmacro (function channelreadquotedexpression))
(put '!( 'lispreadmacro (function channelreadlistordottedpair))
(put '!) 'lispreadmacro (function channelreadrightparen))
(put '![ 'lispreadmacro (function channelreadvector))
(put (mkid (char eof)) 'lispreadmacro (function channelreadeof))

