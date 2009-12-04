%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:TOKEN-DECLS.SL 
% Description:  Declarations of token types. 
% Author:       Brian Beach, Hewlett-Packard CRC 
% Created:      23-Mar-84 
% Modified:     12-Sep-84 13:23:55 (Brian Beach)
% Mode:         Lisp 
% Package:      
% Status:       Experimental (Do Not Distribute) 
% Compile to:   PL:TOKEN-DECLS.B
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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

(ds tokentypeofchar (ch)
  (intinf (vecitm (vecinf currentscantable*) ch)))

(ds currentdiphthongindicator ()
  (vecitm (vecinf currentscantable*) 128))

(ds resetbuf ()
  (setq currentchar 0))

(ds backupbuf ()
  (setq currentchar (wdifference currentchar 1)))

(ds lowercasechar (ch)
  (and (wgeq ch (char !a)) (wleq ch (char !z))))
  
(ds raisechar (ch)
  (wplus2 (wdifference ch (char !a)) (char !A)))
