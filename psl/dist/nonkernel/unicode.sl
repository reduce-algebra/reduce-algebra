%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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

(compiletime (load unicode-decls io-decls))

% The current version of utf8-to-codepoint returns unicode-codepoint-invalid-char (0xfffd)
% for invalid utf8 characters.

(de utf8-to-codepoint (ch)
  (cond
   ((weq (wand (wconst 16#ffffff80) ch) 0) ch)
   ((and (weq (wand ch (wconst 16#ffffe000)) (wconst 16#c000))
	 (weq (wand (wconst 16#c0) ch) (wconst 16#80)))
    (wor (wand (wconst 16#3f) ch) (wand (wconst 16#7c0) (wshift ch -2))))
   ((and (weq (wand ch (wconst 16#fff00000)) (wconst 16#e00000))
	 (weq (wand (wconst 16#c000) ch) (wconst 16#8000))
	 (weq (wand (wconst 16#c0) ch) (wconst 16#80)))
    (wor (wand (wconst 16#3f) ch)
	 (wand (wconst 16#fc0) (wshift ch -2))
	 (wand (wconst 16#f000) (wshift ch -4))))
   ((and (weq (wand ch (wconst 16#f8000000)) (wconst 16#f0000000))
	 (weq (wand (wconst 16#c00000) ch) (wconst 16#800000))
	 (weq (wand (wconst 16#c000) ch) (wconst 16#8000))
	 (weq (wand (wconst 16#c0) ch) (wconst 16#80)))
    (wor (wand (wconst 16#3f) ch)
	 (wand (wconst 16#fc0) (wshift ch -2))
	 (wand (wconst 16#3f000) (wshift ch -4))
	 (wand (wconst 16#1c0000) (wshift ch -6)))   )
%   (t ch)
   (t (wconst unicode-codepoint-invalid-char)) % replacement character
   ))

(de utf8-char-length (ch)
  (cond ((wneq (wand (wconst 16#ff000000) ch) 0) 4)
        ((wneq (wand (wconst 16#ff0000) ch) 0) 3)
        ((wneq (wand (wconst 16#ff00) ch) 0) 2)
        (t 1)))

(de insert-utf8-char-into-tokenbuffer (ch pos)
  (let ((len (utf8-char-length ch)))
    (for (from i (isub1 len) 0 -1)
      (do
        (setf (strbyt tokenbuffer (wplus2 pos i)) (wand 16#ff ch))
        (setq ch (wand (wconst 16#ffffff) (wshift ch -8)))))
    % adjust tokenbuffer length
    (setf (wgetv tokenbuffer 0)
      (if (weq pos 0)
        (isub1 len)
        (wplus2 (wgetv tokenbuffer 0) len)))

    % Make sure word is padded to end with nulls.
    % To do this, just add charactersperword nulls onto the end of the string.
    (let ((limit
           (wdifference (wplus2 pos (wplus2 len charactersperword) 1))))
      % Don't run over the end of the buffer.
      (if (wgeq limit maxtokensize)
        (setq limit (wdifference maxtokensize 1)))
      (for (from i (wplus2 pos len) limit 1)
           (do (setf (strbyt tokenbuffer i) (char null)))))
  ))

