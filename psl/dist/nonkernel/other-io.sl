%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:OTHER-IO.SL 
% Title:        Miscellaneous input and output functions 
% Author:       Eric Benson 
% Created:      28 August 1981 
% Modified:     03-Aug-84 09:58:56 
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
%  Changed declaration of in* and out* from global to fluid.
% 03-Aug-84 09:58:35 (Jim Ambras/CRC)
%  Modified channelprinc to correct type in channelprin2 call.
% 22-Mar-84 11:40:52 (Brian Beach)
%  Added compiletime load of io-decls.
% 01-Dec-83 14:56:28 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load io-decls))

(fluid '(in* out*))

(fluid '(*raise **low-case)) % controls case conversion of IDs

(de channeleject (c)
  % Skip to top of next output page
  (progn (channelwritechar c (char ff))
         nil))

% write a formfeed
(de eject ()
  % Skip to top of next output page
  (channeleject out*))

(de channellinelength (chn len)
  % Set maximum line length
  (prog (oldlen striplen)
        (setq oldlen (wgetv maxline chn))
        (when len
          (if (and (intp len) (wgeq len 0)) 
            (setf (wgetv maxline chn) len)
            (stderror (bldmsg '"%r is an invalid line length" len))))
        (return oldlen)))

% if Len is NIL, just return current
(de linelength (len)
  % Set maximum line length
  (channellinelength out* len))

(de channelposn (chn)
  (wgetv lineposition chn))

(de posn ()
  % Number of characters since last EOL
  (channelposn out*))

(de channellposn (chn)
  (wgetv pageposition chn))

(de lposn ()
  % Number of EOLs since last FF
  (channellposn out*))

(de channelreadch (chn)
  % Read a single character ID
    (prog (x)
        % for Standard Lisp compatibility
        (setq x (channelreadchar chn))
        % converts when *RAISE
    (if **low-case
        (when (and *raise (wgeq x (char !A)) (wleq x (char !Z)))
          (setq x (wplus2 (char !a) (wdifference x (char !A)))))
        (when (and *raise (wgeq x (char !a)) (wleq x (char !z)))
          (setq x (wplus2 (char !A) (wdifference x (char !a)))))
    )
    (return (mkid x))))

(de readch ()
  % Read a single character ID
  (channelreadch in*))

(de channelterpri (chn)
  % Terminate current output line
  (progn (channelwritechar chn (char eol))
         nil))

(de terpri ()
  % Terminate current output line
  (channelterpri out*))

(de princ (x)
  (prin2 x))

(de channelprinc (c x)
  (channelprin2 c x))
