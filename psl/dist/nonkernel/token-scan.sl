%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:TOKEN-SCAN.SL 
% Title:        Table-driven token scanner 
% Author:       Eric Benson 
% Created:      27 August 1981 
% Modified:     
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
% 24-Nov-2007 (Winfried Neun) Made tokenbuffer resizeable
% 03-NOV-94 (Herbert Melenk)
%  Installed switching to lower case PSL **low-case. New input case
%  control: (input-case mode), currently supported 'lower or nil 
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of in* and out*.
% Mon Apr 6 1987 (Leigh Stoller & Robert Kessler)
%  Modified makebufintoid to always put charactersperword nulls onto the
%   end of the string. Previously, if the word ended on a word boundry, it
%   only added 3 nulls.
% Mon Nov 24 (Robert Kessler, Stan Shebs, and Leigh Stoller)
%  Changed calls to float to by **float**, so the compiler doesn't open code 
%  the calls to float into a deposit.  This makes it portable.
% Mon Oct 20 15:24:44 1986 (Leigh Stoller)
%  Use (float const) instead of floating constants because the cross compiler
%  doesn't cross-compile the ability to read floats correctly.
% Tue Mar 11 09:35:17 1986, Edit by Fish
%   MakeBufIntoFloat has used floating point since 1982, time
%   to remove the limitation of fractions to 9 digits.
% 06-Jan-86 10:35 (Kessler and Shebs)
%  Changed mkid in reader on + and - so it actually calls reader-intern.
%  That way, + and - will be interned into the current package instead of
%  always going into the psl: package.  Search for **MKID** change to 
%  find location of change.
% 16-Dec-84 10:00 (Brian Beach)
%  Fixed MAKEBUFINTOID:  changed (strbyt tokenbuffer) to (strbyt tokenbuffer i)
% 21-Sep-84 13:00:24 (Brian Beach)
%  Included following change:
% 28-Jun-84 10:31:34 (Cris Perdue)
%  Rewrote makebufintoid.  Always calls reader-intern.  Always
%  pads tokenbuffer to end of current word with nulls.
%  Call to intern changed to call reader-intern so initial pkg
%  system can redefine that rather than intern.
% 12-Jul-84 10:00 (Brian Beach)
%  Added compile time load of sys-macros for warray declarations.
% 22-Mar-84 14:45:42 (Brian Beach)
%  Added compile time load of io-decls.  Removed WFORS.
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 15:03:08 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(compiletime (load io-decls sys-macros))

(fluid '(in* out*))

(fluid '(currentscantable* 
	 *raise
	 *compressing
	 *eolinstringok
	 currentpackage*
         input-case*
         **low-case
	 ))

(loadtime
  (progn (setq *raise t)
         (setq *compressing nil)
         (setq *eolinstringok nil)
         (setq **low-case (eq t '!t))
         ))

(compiletime
  (flag '(makebufintoid makebufintostring makebufintolispinteger
                    makebufintosysnumber makebufintofloat
                    makestringintosysinteger makestringintobitstring
                    scannererror scanpossiblediphthong)
        'internalfunction))

(compiletime (load token-decls))

(fluid '(tokfloatexponent tokfloatexponentsign tokfloatfractionlength
         toksign tokradix changedpackages currentchar chtokentype
         tokchannel tokch))

(de input-case(mode)
  (let ((w (if *raise 'lower nil)))
    (if **low-case 
        (setq *raise (eq mode 'lower))
        (setq *raise (eq mode 'raise)) )w))

(fluid '(bigtokenbuffersize))
(setq tokenbuffer (gtwarray 25000))
(setq bigtokenbuffersize (times2 charactersperword 250000))

% for compatibiliy, the old tokenbuffer still works.

(de readinbuf ()
  (setq tokch (channelreadchar tokchannel))
  (setf (strbyt tokenbuffer currentchar) tokch)
  (setq chtokentype (tokentypeofchar tokch))
  (cond ((wlessp currentchar bigtokenbuffersize)
         (setq currentchar (wplus2 currentchar 1)))
        ((weq currentchar bigtokenbuffersize)
         (errorprintf "***** READ Buffer overflow, Truncating")
         (setq currentchar (wplus2 bigtokenbuffersize 1)))
        (t (setq currentchar (wplus2 bigtokenbuffersize 1)))))

(compiletime
  (progn (ds unreadlastchar nil (channelunreadchar channel tokch))
         (ds raiselastchar nil (when (wrongcasecharp tokch)
               (setf (strbyt tokenbuffer (wdifference currentchar 1))
                     (adjustcase tokch))))
         (ds uppercasechar(ch) (and (wgeq ch (char !A)) (wleq ch (char !Z))))
         nil))

(de wrongcasecharp(ch)
    (if **low-case (uppercasechar ch) (lowercasechar ch)))

(de adjustcase(ch) 
    (if **low-case (wplus2 ch 32) (wdifference ch 32)))

(de makebufintoid ()
  (setf toktype* '0)
  % Set the length of the string.
  (setf (wgetv tokenbuffer 0) 
    (wdifference currentchar 1))
  (if *compressing
    (newid (copystring tokenbuffer))
    % else
    % Make sure word is padded to end with nulls.
    % To do this, just add charactersperword nulls onto the end of the string.
    (let ((limit
	   (wdifference (wplus2 currentchar charactersperword) 1)))
      % Don't run over the end of the buffer.
      (if (wgeq limit maxtokensize)
	(setq limit (wdifference maxtokensize 1)))
      (for (from i currentchar limit 1)
	   (do (setf (strbyt tokenbuffer i) (char null)))))
    (reader-intern (mkstr tokenbuffer))))

(de makebufintostring ()
  (setf toktype* '1)
  (setf (strbyt tokenbuffer currentchar) 0)
  (setf (wgetv tokenbuffer 0) (wdifference currentchar 1))
  (copystring tokenbuffer))

(de makebufintosysnumber (radix sign)
  (setf (strbyt tokenbuffer currentchar) 0)
  (setf (wgetv tokenbuffer 0) (wdifference currentchar 1))
  (makestringintosysinteger tokenbuffer radix sign))

(de makebufintolispinteger (radix sign)
  (setf toktype* '2)
  (setf (strbyt tokenbuffer currentchar) 0)
  (setf (wgetv tokenbuffer 0) (wdifference currentchar 1))
  (makestringintolispinteger (mkstr tokenbuffer) radix sign))

(declare-warray floatzero      size 2)
(declare-warray floatten       size 2)
(declare-warray makefloattemp1 size 2)
(declare-warray makefloattemp2 size 2)

(commentoutcode
% Changed to use floating point arithmetic on the characters, rather
% than converting to an integer.  This avoids overflow problems.
(de makebufintofloat (exponent minusp)
  (prog (f n)
    (*wfloat floatten 10)
    (*wfloat makefloattemp1 0)
    (*wfloat floatzero 0)
    (setq n (wdifference currentchar 1))
    (for (from i 0 n 1)
	 (do (progn (*wfloat makefloattemp2
			     (digittonumber (strbyt tokenbuffer i)))
		    (*ftimes2 makefloattemp1 makefloattemp1 floatten)
		    (*fplus2 makefloattemp1 makefloattemp1
			     makefloattemp2))))
    (cond ((wgreaterp exponent 0)
	   (for (from i 1 exponent 1)
		(do (*ftimes2 makefloattemp1 makefloattemp1 floatten))))
	  ((wlessp exponent 0) (setq exponent (wminus exponent))
	   (for (from i 1 exponent 1)
		(do (*fquotient makefloattemp1 makefloattemp1
				floatten)))))
    (when minusp
      (*fdifference makefloattemp1 floatzero makefloattemp1))
    (setf toktype* '2)
    (setq f (gtfltn))
    (*fassign (floatbase f) makefloattemp1)
    (return (mkfltn f))))
)

% A horrible hack so the compiler doesn't open code float 0 into 0.0.
(de **float** (u) (float u))

(de makebufintofloat (exponent minusp)
  (let ((temp    (**float** 0))
	(n       (- currentchar 1)))
    (for (from i 0 n 1)
	 (do  (setf temp (plus (times temp (**float** 10))
			       (float (digittonumber (strbyt tokenbuffer i)))
			       ))
	      ))
    (cond ((wgreaterp exponent 0)
	   (for (from i 1 exponent 1)
		(do (setf temp (times temp (**float** 10))))
		))
	  ((wlessp exponent 0) (setq exponent (wminus exponent))
	   (for (from i 1 exponent 1)
		(do (setf temp (quotient temp (**float** 10))))
		)))
    (when minusp
      (setf temp (minus temp)))
    (setf toktype* '2)
    temp
    ))

(de channelreadtoken (channel)
  %. Token scanner
  %
  % This is the basic Lisp token scanner.  The value returned is a Lisp
  % item corresponding to the next token from the input stream.  IDs will
  % be interned.  The global Lisp variable TokType!* will be set to
  %	0 if the token is an ordinary ID,
  %	1 if the token is a string (delimited by double quotes),
  %	2 if the token is a number, or
  %	3 if the token is an unescaped delimiter.
  % In the last case, the value returned by this function will be the single

  % character ID corresponding to the delimiter.
  %
  (prog nil
        (setq tokchannel channel)
        (setq changedpackages 0)
        (resetbuf)
   startscanning
        (setq tokch (channelreadchar channel))
        (setq chtokentype (tokentypeofchar tokch))
        (when (weq chtokentype ignore)
          (go startscanning))
        (setf (strbyt tokenbuffer currentchar) tokch)
        (setq currentchar (wplus2 currentchar 1))
        (case chtokentype
              (((range 0 9)) % digit

               (progn (setq toksign 1)
                      (go insidenumber)))
              ((10) % Start of ID

               (progn (if (null *raise)
                        (go insideid)
                        (progn (raiselastchar)
                               (go insideraisedid)))))
              ((11 22) % Delimiter, but not beginning of Diphthong
	               %  or delimiter if first char in token (like _ in rlisp) 

               (progn (setf toktype* '3)
                      (return (mkid tokch))))
              ((12) % Start of comment

               (go insidecomment))
              ((13) % Diphthong start - Lisp
		    % function uses P-list of starting char

               (return (scanpossiblediphthong tokchannel (mkid tokch))))
              ((14) % ID escape character

               (progn (if (null *raise)
                        (go gotescape)
                        (go gotescapeinraisedid))))
              ((15) % string quote

               (progn (backupbuf)
                      (go insidestring)))
              ((16) % Package indicator - at start of token
		    % means use global package

               (progn (resetbuf)
                      (setq changedpackages 1)
                      (package 'global)
                      (if (null *raise)
                        (go gotpackagemustgetid)
                        (go gotpackagemustgetidraised))))
              ((17) % Ignore - can't ever happen

               (scannererror "Internal error - consult a wizard"))
              ((18) % Minus sign

               (progn (setq toksign -1)
                      (go gotsign)))
              ((19) % Plus sign

               (progn (setq toksign 1)
                      (go gotsign)))
              ((20) % decimal point

               (progn (resetbuf)
                      (readinbuf)
                      (if (wgeq chtokentype 10)
                        (progn (unreadlastchar)
                               (return
                                (scanpossiblediphthong tokchannel '!.)))
                        (progn (setq toksign 1)
                               (setq tokfloatfractionlength 1)
                               (go insidefloatfraction)))))
              ((21) % IDSURROUND, i.e. vertical bars

               (progn (backupbuf)
                      (go insideidsurround)))
              (nil (return (scannererror "Unknown token type"))))
   gotescape
        (backupbuf)
        (readinbuf)
        (go insideid)
   insideid
        (readinbuf)
        (cond ((or (wleq chtokentype 10)
		   (weq chtokentype escapeiffirst)
                   (weq chtokentype plussign)
                   (weq chtokentype minussign))
               (go insideid))
              ((weq chtokentype idescapechar) (go gotescape))
              ((weq chtokentype packageindicator) (backupbuf)
               (setq changedpackages 1) (package (makebufintoid))
               (resetbuf) (go gotpackagemustgetid))
              (t (unreadlastchar) (backupbuf) (when (wneq changedpackages
                                                     0)
                   (package currentpackage*)) (return (makebufintoid))))
   gotpackagemustgetid
        (readinbuf)
        (cond ((weq chtokentype letter) (go insideid))
              ((weq chtokentype idescapechar) (go gotescape))
              (t (scannererror
                  "Illegal to follow package indicator with non ID")))
   gotescapeinraisedid
        (backupbuf)
        (readinbuf)
        (go insideraisedid)
   insideraisedid
        (readinbuf)
        (cond ((or (wlessp chtokentype 10)
                   (weq chtokentype plussign)
                   (weq chtokentype minussign))
               (go insideraisedid))
              ((weq chtokentype 10) (raiselastchar) (go insideraisedid))
              ((weq chtokentype idescapechar)
               (go gotescapeinraisedid))
              ((weq chtokentype packageindicator) (backupbuf)
               (setq changedpackages 1) (package (makebufintoid))
               (resetbuf) (go gotpackagemustgetidraised))
              (t (unreadlastchar) (backupbuf) (when (wneq changedpackages
                                                     0)
                   (package currentpackage*)) (return (makebufintoid))))
   gotpackagemustgetidraised
        (readinbuf)
        (cond ((weq chtokentype letter) (raiselastchar)
               (go insideraisedid))
              ((weq chtokentype idescapechar)
               (go gotescapeinraisedid))
              (t (scannererror
                  "Illegal to follow package indicator with non ID")))
   insidestring
        (readinbuf)
        (cond ((weq chtokentype stringquote) (backupbuf)
               (readinbuf) (if (weq chtokentype stringquote)
                 (go insidestring)
                 (progn (unreadlastchar)
                        (backupbuf)
                        (return (makebufintostring)))))
              ((and (weq tokch (char eol)) (not *eolinstringok))
               (errorprintf "*** String continued over end-of-line"))
              ((weq tokch (char eof))
               (scannererror "EOF encountered inside a string")))
        (go insidestring)
   insideidsurround
        (readinbuf)
        (cond ((weq chtokentype idsurround) (backupbuf)
               (return (makebufintoid)))
              ((weq chtokentype idescapechar) (backupbuf)
               (readinbuf))
              ((weq tokch (char eof))
               (scannererror "EOF encountered inside an ID")))
        (go insideidsurround)
   gotsign
        (resetbuf)
        (readinbuf)
        (cond ((weq tokch (char !.)) (putstrbyt tokenbuffer 0 (char !0))
               (setq currentchar 2) (go insidefloat))
              ((or (weq chtokentype letter)
                   (weq chtokentype minussign)  
				% patch to be able to read 1+ and 1-
                   (weq chtokentype plussign))
               (resetbuf)
               (setf (strbyt tokenbuffer 0) (if (wlessp toksign 0)
                       (char !-)
                       (char !+)))
               (setf (strbyt tokenbuffer 1) tokch)
	       (setq currentchar 2)
 	       (if *raise
                 (progn (raiselastchar)
                        (go insideraisedid))
                 (go insideid)))
              ((weq chtokentype idescapechar) (resetbuf)
               (setf (strbyt tokenbuffer 0) (if (wlessp toksign 0)
                       (char !-)
                       (char !+)))
               (setq currentchar 1) (if *raise
                 (go gotescapeinraisedid)
                 (go gotescape)))
              ((wgreaterp chtokentype 9) (unreadlastchar)
			% Allow + or - to start a Diphthong

               (return (scanpossiblediphthong channel
                        % **MKID** Change - used to call mkid on
                        % char - and char +.
                        (reader-intern (if (wlessp toksign 0)
                           "-"
                           "+")))))
              (t (go insidenumber)))
   insidenumber
        (readinbuf)
        (when (wlessp chtokentype 10)
          (go insidenumber))
        (cond ((weq tokch (char !#)) (backupbuf)
               (setq tokradix (makebufintosysnumber 10 1))
	       (resetbuf)
	       (when (or (wlessp tokradix 2) (wgreaterp tokradix 36))
                        (return (scannererror "Radix out of range")))
               (if (wleq tokradix 10)
                 (go insideintegerradixunder10)
                 (go insideintegerradixover10)))
              ((weq tokch (char !.)) (go insidefloat))
              ((or (weq tokch (char b)) (weq tokch (char !b))) (backupbuf)
               (return (makebufintolispinteger 8 toksign)))
              ((or (weq tokch (char !E)) (weq tokch (char !e)))
               (setq tokfloatfractionlength 0) (go insidefloatexponent))
              ((or (weq chtokentype letter)
                   (weq chtokentype minussign)
			% patch to be able to read 1+ and 1-
                   (weq chtokentype plussign))
               (if *raise
                 (progn (raiselastchar)
                        (go insideraisedid))
                 (go insideid)))
              ((weq chtokentype idescapechar) (if *raise
                 (go gotescapeinraisedid)
                 (go gotescape)))
              (t (unreadlastchar) (backupbuf)
                 (return (makebufintolispinteger 10 toksign))))
   insideintegerradixunder10
        (readinbuf)
        (when (wlessp chtokentype tokradix)
          (go insideintegerradixunder10))
        (when (wlessp chtokentype 10)
          (return (scannererror "Digit out of range")))
   numreturn
        (unreadlastchar)
        (backupbuf)
        (return (makebufintolispinteger tokradix toksign))
   insideintegerradixover10
        (readinbuf)
        (when (wlessp chtokentype 10)
          (go insideintegerradixover10))
        (when (wgreaterp chtokentype 10)
          (go numreturn))
        (when (lowercasechar tokch)
          (setq tokch (raisechar tokch))
          (setf (strbyt tokenbuffer (wdifference currentchar 1)) tokch))
        (when (wgeq tokch (wplus2 (wdifference (char !A) 10) tokradix))
          (go numreturn))
        (go insideintegerradixover10)
   insidefloat
        % got decimal point inside number
        (backupbuf)
        (readinbuf)
        (when (or (weq tokch (char !E)) (weq tokch (char !e)))
          (setq tokfloatfractionlength 0)
          (go insidefloatexponent))
        (cond ((wgeq chtokentype 10) % nnn. is floating point number
               (progn (unreadlastchar)
                      (backupbuf)
                      (return (makebufintofloat 0 (wlessp toksign 0))))))
        (setq tokfloatfractionlength 1)
   insidefloatfraction
        (readinbuf)
        (when (wlessp chtokentype 10)
          (setq tokfloatfractionlength (wplus2 tokfloatfractionlength 1))
          % don't overflow mantissa
          (go insidefloatfraction))
        (when (or (weq tokch (char !E)) (weq tokch (char !e)))
          (go insidefloatexponent))
        (unreadlastchar)
        (backupbuf)
        (return (makebufintofloat (wminus tokfloatfractionlength)
                 (wlessp toksign 0)))
   insidefloatexponent
        (backupbuf)
        (setq tokfloatexponentsign 1)
        (setq tokfloatexponent 0)
        (setq tokch (channelreadchar tokchannel))
        (setq chtokentype (tokentypeofchar tokch))
        (when (wlessp chtokentype 10)
          (setq tokfloatexponent chtokentype)
          (go digitsinsideexponent))
        (cond ((weq tokch (char '!-)) (setq tokfloatexponentsign -1))
              ((wneq tokch (char '!+))
               (return (scannererror "Missing exponent in float"))))
        (setq tokch (channelreadchar tokchannel))
        (setq chtokentype (tokentypeofchar tokch))
        (when (wgeq chtokentype 10)
          (return (scannererror "Missing exponent in float")))
        (setq tokfloatexponent chtokentype)
   digitsinsideexponent
        (setq tokch (channelreadchar tokchannel))
        (setq chtokentype (tokentypeofchar tokch))
        (when (wlessp chtokentype 10)
          (setq tokfloatexponent
                (wplus2 (wtimes2 tokfloatexponent 10) chtokentype))
          (go digitsinsideexponent))
        (channelunreadchar channel tokch)
        (return (makebufintofloat
                 (wdifference
                  (wtimes2 tokfloatexponentsign tokfloatexponent)
                  tokfloatfractionlength)
                 (wlessp toksign 0)))
   insidecomment
        (cond ((weq (setq tokch (channelreadchar channel)) (char eol))
               (resetbuf) (go startscanning))
              ((weq tokch (char eof)) (return $eof$))
              (t (go insidecomment)))))

(de ratom ()
  %. Read token from current input
  (channelreadtoken in*))

(de digittonumber (d)
  %
  % if D is not a digit then it is assumed to be an uppercase letter
  %
  (if (and (wgeq d (char !0)) (wleq d (char !9)))
    (wdifference d (char !0))
    (wdifference d (wdifference (char !A) 10))))

(de makestringintolispinteger (s radix sign)
  (sys2int (makestringintosysinteger s radix sign)))

(de makestringintosysinteger (strng radix sign)
  %
  % Unsafe string to integer conversion.  Strng is assumed to contain
  % only digits and possibly uppercase letters for radices > 10.  Since it
  % uses multiplication, arithmetic overflow may occur. Sign is +1 or -1
  %
  (prog (count tot radixexponent)
    (when (setq radixexponent (syspowerof2p radix))
      (return (makestringintobitstring strng radix radixexponent sign)))
    (setq strng (strinf strng))
    (setq count (strlen strng))
    (setq tot 0)
    (for (from i 0 count 1)
	 (do (setq tot
	       (wplus2 (wtimes2 tot radix)
		       (digittonumber (strbyt strng i))))))
    (return (if (wlessp sign 0)
	      (wminus tot)
	      tot))))

(de makestringintobitstring (strng radix radixexponent sign)
  (prog (count tot)
    (setq strng (strinf strng))
    (setq count (strlen strng))
    (setq tot 0)
    (for (from i 0 count 1)
	 (do (progn (setq tot (wshift tot radixexponent))
		    (setq tot
		      (wor tot (digittonumber (strbyt strng i)))))))
    (when (wlessp sign 0)
      (return (wminus tot)))
    (return tot)))

(de syspowerof2p (num)
  (case num ((1) 0) ((2) 1) ((4) 2) ((8) 3) ((16) 4) ((32) 5) (nil nil)))

(de scannererror (message)
  (stderror (bldmsg "***** Error in token scanner: %s" message)))

(de scanpossiblediphthong (channel startchar)
  (prog (alst target ch)
        (setf toktype* '3)
        (when (null (setq alst (get startchar (currentdiphthongindicator))))
          (return startchar))
        (when (null (setq target
                     (atsoc (setq ch (mkid (channelreadchar channel)))
                      alst)))
          (channelunreadchar channel (idinf ch))
          (return startchar))
        (return (cdr target))))

(de readline ()
  (makeinputavailable)
  (channelreadline in*))

(de channelreadline (chn)
  (prog (c)
        (setf (wgetv tokenbuffer 0) -1)
        (while (and (wneq (setq c (channelreadchar chn)) (char eol))
                    (wneq c (char eof)))
          (setf (wgetv tokenbuffer 0) (wplus2 (wgetv tokenbuffer 0) 1))
          (setf (strbyt tokenbuffer (wgetv tokenbuffer 0)) c))
        (return (if (wgeq (wgetv tokenbuffer 0) 0)
                  (progn (setf
                          (strbyt tokenbuffer
                           (wplus2 (wgetv tokenbuffer 0) 1))
                          (char null))
                         (copystring (mkstr tokenbuffer)))
                  '""))))

% Dummy definition of package conversion function
(de package (u)
  nil)

% Dummy definition of MakeInputAvailable, redefined by Emode
(de makeinputavailable ()
  nil)

(off fast-integers)
