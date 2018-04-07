%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:TOKEN-DECLS.SL 
% Description:  Declarations of token types. 
% Author:       Brian Beach, Hewlett-Packard CRC 
% Created:      23-Mar-84 
% Modified:     12-Sep-84 13:23:55 (Brian Beach)
% Mode:         Lisp 
% Package:      
% Status:       Open Source: BSD License
% Compile to:   PL:TOKEN-DECLS.B
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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

% DIGITS are 0..9
(define-constant letter            10)
(define-constant delimiter         11)
(define-constant commentchar       12)
(define-constant diphthongstart    13)
(define-constant idescapechar      14)
(define-constant stringquote       15)
(define-constant packageindicator  16)
(define-constant ignore            17)
(define-constant minussign         18)
(define-constant plussign          19)
(define-constant decimalpoint      20)
(define-constant idsurround        21)
(define-constant escapeiffirst     22)

(ds tokentypeofchar (ch)
  (intinf (vecitm (vecinf currentscantable*) ch)))

(ds currentdiphthongindicator ()
  (vecitm (vecinf currentscantable*) 256))

(ds resetbuf ()
  (setq currentchar 0))

(ds backupbuf ()
  (setq currentchar (wdifference currentchar 1)))

(ds lowercasechar (ch)
  (and (wgeq ch (char !a)) (wleq ch (char !z))))
  
(ds raisechar (ch)
  (wplus2 (wdifference ch (char !a)) (char !A)))
