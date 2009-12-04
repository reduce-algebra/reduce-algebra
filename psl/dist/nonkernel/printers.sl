%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:PRINTERS.SL 
% Title:        Printing functions for various data types 
% Author:       Eric Benson 
% Created:      27 August 1981 
% Modified:     28-Sep-87
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
% 27-Jan-95 (Herbert Melenk)
%  Introduced function >output-case< for supporting upper case output.
% 03-NOV-94 (Herbert Melenk)
%  Installed switching to lower case PSL **low-case.
% 06-APR-88 (Julian Padget)
%  Incorporated stuff for printing extra CPSL datatypes.
% 19 Mar 1988 (Julian Padget)
%  As immediately below for stack group descriptors.
% 28-Sep-87 (Harold Carr)
%  Copied compiletime macro definition of isinum from arithemetic.sl to here.
%  Then used it in ChannelWriteBitStrAux instead of INUMP.
% 04-Sep-87 (Leigh Stoller & Harold Carr)
%  Made ChannelWriteBitStrAux make sure that the value returned by
%   intlshift is a machine word since the recursive calls expect words.
% 26-Aug-87 (Leigh Stoller)
%  Removed internal functions.
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of in* and out*.
% Thu Feb 19 20:18:49 1987, originally Wed Mar 14 08:15:11 1984 (Russ Fish)
%   Fix infinite loop in ChannelWriteBitStrAux due to sign extension of
%   negative numbers by WShift on the VAX.  Use IntLShift fn instead.
%JAP: 02 Sep 1986 (Julian Padget)
%JAP:  Added extra type tests to recursivechannelprin1 to recognise the new
%JAP:  data types added to support the new binder
% 19-Jul-84 10:00 (Brian Beach)
%  Added (STRINF ...) around uses of DIGITSTRING in STRBYT.
% 12-Jul-84 10:00 (Brian Beach)
%  Added compile-time load of sys-macros for warray declarations.
% 31-May-84 10:46:35 (Brian Beach)
%  Call on IDAPPLY2 --> IDAPPLY.
% 10-May-84 14:19:21 (Brian Beach)
%  <PSL.KERNEL>PRINTERS.RED.18,  6-Feb-84 10:30:27, Edit by KESSLER
%  As Per Hearn - Floating Point right offset is too large.  Changed from
%   30 to 14.  
%  
% 22-Mar-84 11:42:42 (Brian Beach)
%  Added compiletime load of io-decls.
% 01-Dec-83 14:57:36 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load io-decls token-decls sys-consts sys-macros if-system))

(compiletime (flag '(charneedsescape output-switch-case) 'internalfunction))

(on fast-integers)

(fluid '(in* out*))

(fluid '(outputbase* % current output base
	 prinlength % length of structures to print
	 prinlevel % level of recursion to print
	 currentscantable*
	 lispscantable*
	 idescapechar*
	 *lower    % print IDs with uppercase chars lowered / outmoded
	 **low-case % lower case PSL
     output-case*  % eq 'raise: print IDs with lowercase chars raised
	 ))


(loadtime
  (progn (setq outputbase* 10)
	 (setq idescapechar* 33)    % (char !!)
	 (setq currentscantable* lispscantable*))) % so TokenTypeOfChar works right

(compiletime
  (progn (ds uppercasep (ch) (and (wgeq ch (char !A)) (wleq ch (char !Z))))
	 (ds lowercasep (ch) (and (wgeq ch (char !a)) (wleq ch (char !z))))
	 (ds raisechar (ch) (wplus2 (wdifference ch (char !a)) (char !A)))
	 (ds lowerchar (ch) (wplus2 (wdifference ch (char !A)) (char !a)))
	 ))

(compiletime
 (dm isinum (u)
   (list '(lambda (x)
	    (eq (signedfield x
			     (isub1 infstartingbit)
			     (iadd1 infbitlength))
		x))
	 (second u))
   ))

(de output-case(u)
  (let((c output-case*))
   (when (and u (not (eq u 'raise))) 
	 (typeerror u 'output-case "a supported mode"))
   (setq output-case* u)
   c))

%. Writes EOL first if given Len causes max line length to be exceeded
(de checklinefit (len chn fn itm)
  (when (and (wgreaterp (wplus2 (wgetv lineposition chn) len)
			(wgetv maxline chn))
	     (wgreaterp (wgetv maxline chn) 0))
    (channelwritechar chn (char eol)))
  (idapply fn (list chn itm)))

(de channelwritestring (channel strng)
  %
  % Strng may be tagged or not, but it must have a length field accesible
  % by StrLen.
  %
  (prog (uplim)
	(setq uplim (strlen (strinf strng)))
	(for (from i 0 uplim 1)
	      (do (channelwritechar channel (strbyt (strinf strng) i))))))

(de writestring (s)
  (channelwritestring out* s))

(fluid '(digitstring))

(setq digitstring "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ")

(declare-wstring writenumberbuffer size 100)

(de channelwritesysinteger (channel number radix)
  (let ((exponent (syspowerof2p radix)))

    (cond (exponent
	   (channelwritebitstring channel number (wdifference radix 1)
				  exponent))
	  ((wlessp number 0)
	   (channelwritechar channel (char '!-))
	   (writenumber1 channel (wminus (wquotient number radix))
			 radix)
	   % To catch largest NEG

	   (channelwritechar channel
			     (strbyt (strinf digitstring) 
				     (wminus (wremainder number radix)))))
	  ((weq number 0) 
	   (channelwritechar channel (char !0)))
	  (t
	   (writenumber1 channel number radix)))))

(de writenumber1 (channel number radix)
  (if (weq number 0)
    channel
    (progn (writenumber1 channel (wquotient number radix) radix)
	   (channelwritechar channel
	    (strbyt (strinf digitstring) 
		    (wremainder number radix))))))

(de channelwritebitstring (channel number digitmask exponent)
  (if (weq number 0)
    (channelwritechar channel (char !0))
    (channelwritebitstraux channel number digitmask exponent)))

(de channelwritebitstraux (channel number digitmask exponent)
  (cond ((weq number 0) channel)
	(t % Channel means nothing here just trying to fool the compiler
	   (progn
	      (channelwritebitstraux
		  channel
		  (if_system VAX     % Avoid wshift sign extension on the Vax.
		      (prog (u)
			    (cond ((not (isinum
					 (setq u
					       (intlshift number
							  (wminus exponent)))))
				   (return (fixval (fixinf u))))
				  (t
				   (return u))))
		      (wshift number (wminus exponent)))
		  digitmask
		  exponent)
	      (channelwritechar channel
		  (strbyt (strinf digitstring) (wand number digitmask)))))))

(de writesysinteger (number radix)
  (channelwritesysinteger out* number radix))

(de channelwritefixnum (channel num)
  (channelwriteinteger channel (fixval (fixinf num))))

(de channelwriteinteger (channel num)
  (when (wneq outputbase* 10)
    (channelwritesysinteger channel outputbase* 10)
    (channelwritechar channel (char !#)))
  (channelwritesysinteger channel num outputbase*)
  )

(de channelwritesysfloat (channel floatptr)
  (prog (ch chindex)
	(writefloat writenumberbuffer floatptr)
	(channelwritestring channel writenumberbuffer)))

(de channelwritefloat (channel lispfloatptr)
  (channelwritesysfloat channel (floatbase (fltinf lispfloatptr))))

(de channelprintstring (channel strng)
  (prog (len ch)
    (channelwritechar channel (char !"))
    (setq len (strlen (strinf strng)))
    (for (from i 0 len 1)
	 (do (progn (setq ch (strbyt (strinf strng) i))
		    (when (weq ch (char !"))
		      (channelwritechar channel (char !")))
		    (channelwritechar channel ch))))
    (channelwritechar channel (char !"))))

(de output-switch-case(ch)
  (if **low-case 
       (if (lowercasep ch) (raisechar ch) ch)
       (if (uppercasep ch) (lowerchar ch) ch)))

(de channelwriteid (channel itm)
  (cond ((or (and **low-case (not (eq output-case* 'raise)))
	     (and (not **low-case) (not *lower)))
	 (channelwritestring channel (symnam (idinf itm))))
	(t
    (prog (ch len)
      (setq itm (strinf (symnam (idinf itm))))
      (setq len (strlen itm))
      (for (from i 0 len 1)
	   (do (progn (setq ch (output-switch-case (strbyt itm i)))
		      (channelwritechar channel ch))))))))

(de channelwriteunbound (channel itm)
  (channelwritestring channel "#<Unbound:")
  (channelwriteid channel itm)
  (channelwritechar channel (char '>)))

(de charneedsescape(ch)
   (or (and (null **low-case) (lowercasep ch))
       (and **low-case (uppercasep ch))))

(de channelprintid (channel itm)
  (prog (len ch tokentype)
    (setq itm (strinf (symnam (idinf itm))))
    (setq len (strlen itm))
    (setq ch (strbyt itm 0))
    (when (or (wneq (tokentypeofchar ch) 10) (charneedsescape ch))
      (channelwritechar channel idescapechar*))
    (if (or (and **low-case (not (eq output-case* 'raise))) 
	    (and (not **low-case) (not *lower)))
      (progn (channelwritechar channel ch)
	     (for (from i 1 len 1)
		  (do
		   (progn (setq ch (strbyt itm i))
			  (setq tokentype (tokentypeofchar ch))
			  (unless (or (wleq tokentype 10)
				      (weq tokentype plussign)
				      (weq tokentype minussign))
			    (channelwritechar channel idescapechar*))
			  (when (charneedsescape ch)
			    (channelwritechar channel idescapechar*))
			  (channelwritechar channel ch)))))
      (progn (channelwritechar channel (output-switch-case ch))
	     (for (from i 1 len 1)
		  (do
		   (progn (setq ch (strbyt itm i))
			  (setq tokentype (tokentypeofchar ch))
			  (unless (or (wleq tokentype 10)
				      (weq tokentype plussign)
				      (weq tokentype minussign))
			    (channelwritechar channel idescapechar*))
			  (when (charneedsescape ch)
			    (channelwritechar channel idescapechar*))
			  (setq ch (output-switch-case ch))
			  (channelwritechar channel ch))))))))

(de channelprintunbound (channel itm)
  (channelwritestring channel "#<Unbound ")
  (channelprintid channel itm)
  (channelwritechar channel (char '>)))

(de channelwritecodepointer (channel cp)
  (prog (n)
	(setq cp (codeinf cp))
	(channelwritestring channel "#<Code ")
	(setq n (!%code-number-of-arguments cp))
	(when (and (wgeq n 0) (wleq n maxargs))
	  (channelwritesysinteger channel n 10)
	  (channelwritechar channel (char blank)))
	(channelwritesysinteger channel cp compressedbinaryradix)
	(channelwritechar channel (char '>))))

(de channelwriteunknownitem (channel itm)
  (channelwritestring channel "#<Unknown ")
  (channelwritesysinteger channel itm compressedbinaryradix)
  (channelwritechar channel (char >)))

(de channelwriteblankoreol (channel)
  (if (and (wgeq (wplus2 (wgetv lineposition channel) 1)
		 (wgetv maxline channel))
	   (wgreaterp (wgetv maxline channel) 0))
    (channelwritechar channel (char eol))
    (channelwritechar channel (char ! ))))

(de channelwritepair (channel itm level)
  (if (and (intp prinlevel) (wgeq level prinlevel))
    (channelwritechar channel (char '!#))
    (prog (n)
	  (setq level (wplus2 level 1))
	  (checklinefit 1 channel 'channelwritechar (char !())
	  (if (or (not (intp prinlength)) (wleq 1 prinlength))
	    (progn (recursivechannelprin2 channel (car itm) level)
		   (setq n 2)
		   (setq itm (cdr itm))
		   (while (and (pairp itm)
			   (or (not (intp prinlength)) (wleq n prinlength)))
		     (channelwriteblankoreol channel)
		     (recursivechannelprin2 channel (car itm) level)
		     (setq n (wplus2 n 1))
		     (setq itm (cdr itm)))
		   (cond ((pairp itm)
			  (checklinefit 3 channel 'channelwritestring
			   " ..."))
			 (itm
			  (checklinefit 3 channel 'channelwritestring
			   " . ")
			  (recursivechannelprin2 channel itm level))))
	    (checklinefit 3 channel 'channelwritestring "..."))
	  (checklinefit 1 channel 'channelwritechar (char !))))))

(de channelprintpair (channel itm level)
  (if (and (intp prinlevel) (wgeq level prinlevel))
    (channelwritechar channel (char '!#))
    (prog (n)
	  (setq level (wplus2 level 1))
	  (checklinefit 1 channel 'channelwritechar (char !())
	  (if (or (not (intp prinlength)) (wleq 1 prinlength))
	    (progn (recursivechannelprin1 channel (car itm) level)
		   (setq n 2)
		   (setq itm (cdr itm))
		   (while (and (pairp itm)
			   (or (not (intp prinlength)) (wleq n prinlength)))
		     (channelwriteblankoreol channel)
		     (recursivechannelprin1 channel (car itm) level)
		     (setq n (wplus2 n 1))
		     (setq itm (cdr itm)))
		   (cond ((pairp itm)
			  (checklinefit 3 channel 'channelwritestring
			   " ..."))
			 (itm
			  (checklinefit 3 channel 'channelwritestring
			   " . ")
			  (recursivechannelprin1 channel itm level))))
	    (checklinefit 3 channel 'channelwritestring "..."))
	  (checklinefit 1 channel 'channelwritechar (char !))))))

(de channelwritevector (channel vec level)
  (if (and (intp prinlevel) (wgeq level prinlevel))
    (channelwritechar channel (char '!#))
    (prog (len i)
	  (setq level (wplus2 level 1))
	  (checklinefit 1 channel 'channelwritechar (char '![))
	  (setq len (veclen (vecinf vec)))
	  (when (wlessp len 0)
	    (return (checklinefit 1 channel 'channelwritechar (char '!]))))
	  (setq i 0)
     loopbegin
	  (if (or (not (intp prinlength)) (wlessp i prinlength))
	    (progn (recursivechannelprin2 channel (vecitm (vecinf vec) i)
		    level)
		   (when (wleq (setq i (wplus2 i 1)) len)
		     (channelwriteblankoreol channel)
		     (go loopbegin)))
	    (checklinefit 3 channel 'channelwritestring "..."))
	  (checklinefit 1 channel 'channelwritechar (char '!])))))

(de channelprintvector (channel vec level)
  (if (and (intp prinlevel) (wgeq level prinlevel))
    (channelwritechar channel (char '!#))
    (prog (len i)
	  (setq level (wplus2 level 1))
	  (checklinefit 1 channel 'channelwritechar (char '![))
	  (setq len (veclen (vecinf vec)))
	  (when (wlessp len 0)
	    (return (checklinefit 1 channel 'channelwritechar (char '!]))))
	  (setq i 0)
     loopbegin
	  (if (or (not (intp prinlength)) (wlessp i prinlength))
	    (progn (recursivechannelprin1 channel (vecitm (vecinf vec) i)
		    level)
		   (when (wleq (setq i (wplus2 i 1)) len)
		     (channelwriteblankoreol channel)
		     (go loopbegin)))
	    (checklinefit 3 channel 'channelwritestring "..."))
	  (checklinefit 1 channel 'channelwritechar (char '!])))))

(de channelwriteevector (channel evec level)
  (prog (handler)
	(cond ((and (intp prinlevel) (wgeq level prinlevel))
	       (channelwritechar channel (char '!#)))
	      ((and (getd 'object-get-handler-quietly)
		    (setq handler
		     (object-get-handler-quietly evec 'channelprin)))
	       (apply handler (list evec channel level nil)))
	      (t (channelwritestring channel "#<EVector ")
		 (channelwritesysinteger channel (evecinf evec)
					 compressedbinaryradix)
		 (channelwritechar channel (char '>)) nil))))

(de channelprintevector (channel evec level)
  (prog (handler)
	(cond ((and (intp prinlevel) (wgeq level prinlevel))
	       (channelwritechar channel (char '!#)))
	      ((and (getd 'object-get-handler-quietly)
		    (setq handler
		     (object-get-handler-quietly evec 'channelprin)))
	       (apply handler (list evec channel level t)))
	      (t (channelwritestring channel "#<EVector ")
		 (channelwritesysinteger channel (evecinf evec)
					 compressedbinaryradix)
		 (channelwritechar channel (char '>)) nil))))

(de channelwritecontext (channel itm level)
  (if (and (intp prinlevel) (wgeq level prinlevel))
      (channelwritechar channel (char '!#))
      (progn
	(channelwritestring channel "#<Context seq:")
	(channelwritesysinteger channel (seq itm) 10)

	(channelwritestring channel " span:")
	(channelwritesysinteger channel (span itm) 10)

	(channelwritestring channel " gen:")
	(channelwritesysinteger channel (gen itm) 10)

	(channelwritestring channel " alink:")
	(channelwritestring channel "#<Context ")
	(channelwritesysinteger channel (alink itm) compressedbinaryradix)
	(channelwritechar channel (char '!>))

	(channelwritestring channel " clink:")
	(channelwritestring channel "#<Context ")
	(channelwritesysinteger channel (clink itm) compressedbinaryradix)
	(channelwritechar channel (char '!>))

	(channelwritestring channel " refc:")
	(channelwritesysinteger channel (refc itm) 10)

	(channelwritestring channel " bvec:")
	(channelwritestring channel "#<Bvector ")
	(channelwritesysinteger channel (bvec itm) compressedbinaryradix)
	(channelwritechar channel (char '!>))

	(channelwritestring channel " root:")
	(channelwritestring channel "#<Context ")
	(channelwritesysinteger channel (root itm) compressedbinaryradix)
	(channelwritechar channel (char '!>))
	(channelwritechar channel (char '!>)))))

(de channelprintcontext (channel itm level)
  (if (and (intp prinlevel) (wgeq level prinlevel))
      (channelwritechar channel (char '!#))
      (progn
	(channelwritestring channel "#<Context seq:")
	(channelwritesysinteger channel (seq itm) 10)

	(channelwritestring channel " span:")
	(channelwritesysinteger channel (span itm) 10)

	(channelwritestring channel " gen:")
	(channelwritesysinteger channel (gen itm) 10)

	(channelwritestring channel " alink:")
	(channelwritestring channel "#<Context ")
	(channelwritesysinteger channel (alink itm) compressedbinaryradix)
	(channelwritechar channel (char '!>))

	(channelwritestring channel " clink:")
	(channelwritestring channel "#<Context ")
	(channelwritesysinteger channel (clink itm) compressedbinaryradix)
	(channelwritechar channel (char '!>))

	(channelwritestring channel " refc:")
	(channelwritesysinteger channel (refc itm) 10)

	(channelwritestring channel " bvec:")
	(channelwritestring channel "#<Bvector ")
	(channelwritesysinteger channel (bvec itm) compressedbinaryradix)
	(channelwritechar channel (char '!>))

	(channelwritestring channel " root:")
	(channelwritestring channel "#<Context ")
	(channelwritesysinteger channel (root itm) compressedbinaryradix)
	(channelwritechar channel (char '!>))
	(channelwritechar channel (char '!>)))))

(de channelwritebstruct (channel itm level)
  (channelwritestring channel "#<Bstruct ")
  (channelwritesysinteger channel itm compressedbinaryradix)
  (channelwritechar channel (char '!>)))

(de channelprintbstruct (channel itm level)
  (channelwritestring channel "#<Bstruct ")
  (channelwritesysinteger channel itm compressedbinaryradix)
  (channelwritechar channel (char '!>)))

(de channelwritebvector (channel itm level)
  (channelwritestring channel "#<Bvector ")
  (channelwritesysinteger channel itm compressedbinaryradix)
  (channelwritechar channel (char '!>)))

(de channelprintbvector (channel itm level)
  (channelwritestring channel "#<Bvector ")
  (channelwritesysinteger channel itm compressedbinaryradix)
  (channelwritechar channel (char '!>)))

(de channelwritefunarg (channel itm level)
  (if (and (intp prinlevel) (wgeq level prinlevel))
      (channelwritechar channel (char '!#))
      (progn
	(channelwritestring channel "#<Funarg context:")
	(channelwritesysinteger channel (car itm) compressedbinaryradix)
	(channelwritestring channel " expression:")
	(channelwritesysinteger channel (cdr itm) compressedbinaryradix)
	(channelwritechar channel (char '!>)))))

(de channelprintfunarg (channel itm level)
  (if (and (intp prinlevel) (wgeq level prinlevel))
      (channelwritechar channel (char '!#))
      (progn
	(channelwritestring channel "#<Funarg context:")
	(channelwritesysinteger channel (car itm) compressedbinaryradix)
	(channelwritestring channel " expression:")
	(channelwritesysinteger channel (cdr itm) compressedbinaryradix)
	(channelwritechar channel (char '!>)))))

(de channelwritesgd (channel itm level)
  (channelwritestring channel "#<SGD ")
  (channelwritesysinteger channel itm compressedbinaryradix)
  (channelwritechar channel (char '!>)))

(de channelprintsgd (channel itm level)
  (channelwritestring channel "#<SGD ")
  (channelwritesysinteger channel itm compressedbinaryradix)
  (channelwritechar channel (char '!>)))

(de channelwritewords (channel itm)
  (prog (len i)
	(channelwritestring channel "#<Words:")
	(setq len (wrdlen (wrdinf itm)))
	(when (wlessp len 0)
	  (return (checklinefit 1 channel 'channelwritechar (char '>))))
	(setq i 0)
   loopbegin
	(if (or (not (intp prinlength)) (wlessp i prinlength))
	  (progn (checklinefit 10 channel 'channelwriteinteger
		  (wrditm (wrdinf itm) i))
		 (when (wleq (setq i (wplus2 i 1)) len)
		   (channelwriteblankoreol channel)
		   (go loopbegin)))
	  (checklinefit 3 channel 'channelwritestring "..."))
	(checklinefit 1 channel 'channelwritechar (char '>))))

(de channelwritehalfwords (channel itm)
  (prog (len i)
	(channelwritestring channel "#<Halfwords:")
	(setq len (halfwordlen (halfwordinf itm)))
	(when (wlessp len 0)
	  (return (checklinefit 1 channel 'channelwritechar (char '>))))
	(setq i 0)
   loopbegin
	(if (or (not (intp prinlength)) (wlessp i prinlength))
	  (progn (checklinefit 10 channel 'channelwriteinteger
		  (halfworditm (halfwordinf itm) i))
		 (when (wleq (setq i (wplus2 i 1)) len)
		   (channelwriteblankoreol channel)
		   (go loopbegin)))
	  (checklinefit 3 channel 'channelwritestring "..."))
	(checklinefit 1 channel 'channelwritechar (char '>))))

(de channelwritebytes (channel itm)
  (prog (len i)
	(channelwritestring channel "#<Bytes:")
	(setq len (strlen (strinf itm)))
	(when (wlessp len 0)
	  (return (checklinefit 1 channel 'channelwritechar (char '>))))
	(setq i 0)
   loopbegin
	(if (or (not (intp prinlength)) (wlessp i prinlength))
	  (progn (checklinefit 10 channel 'channelwriteinteger
		  (strbyt (strinf itm) i))
		 (when (wleq (setq i (wplus2 i 1)) len)
		   (channelwriteblankoreol channel)
		   (go loopbegin)))
	  (checklinefit 3 channel 'channelwritestring "..."))
	(checklinefit 1 channel 'channelwritechar (char '>))))

(de channelprin2 (channel itm)
  %. Display Itm on Channel
  (recursivechannelprin2 channel itm 0))

(de recursivechannelprin2 (channel itm level)
  (case (tag itm)
    ((posint-tag negint-tag)
	(if (eq channel 4) % explode , flatsize etc
		 (checklinefit 10 channel 'channelwriteinteger itm)
	  (checklinefit (flatsize2 itm) channel 'channelwriteinteger itm)))
    ((id-tag)
     (checklinefit (wplus2 (strlen (strinf (symnam (idinf itm)))) 1)
		   channel 'channelwriteid itm))
    ((unbound-tag)
     (checklinefit (wplus2 (strlen (strinf (symnam (idinf itm)))) 12)
		   channel 'channelwriteunbound itm))
    ((string-tag)
     (checklinefit (wplus2 (strlen (strinf itm)) 1) channel
		   'channelwritestring itm))
    ((code-tag)
     (checklinefit 14 channel 'channelwritecodepointer itm))
    ((fixnum-tag) 
	(if (eq channel 4) % explode , flatsize etc
		 (checklinefit 20 channel 'channelwritefixnum itm)
	  (checklinefit (flatsize2 itm) channel 'channelwritefixnum itm)))
    ((floatnum-tag)
	(if (eq channel 4) % explode , flatsize etc
		 (checklinefit 20 channel 'channelwritefloat itm)
	  (checklinefit (flatsize2 itm) channel 'channelwritefloat itm)))
    ((words-tag) (channelwritewords channel itm))
    ((halfwords-tag) (channelwritehalfwords channel itm))
    ((bytes-tag) (channelwritebytes channel itm))
    ((pair-tag) (channelwritepair channel itm level))
    ((vector-tag) (channelwritevector channel itm level))
    ((evector-tag) (channelwriteevector channel itm level))
    ((context-tag) (channelwritecontext channel itm level))
    ((bstruct-tag) (channelwritebstruct channel itm level))
    ((bvector-tag) (channelwritebvector channel itm level))
    ((funarg-tag) (channelwritefunarg channel itm level))
    ((sgd-tag) (channelwritesgd channel itm level))
    (nil (checklinefit 20 channel 'channelwriteunknownitem itm)))
  itm)

(de prin2 (itm)
  %. ChannelPrin2 to current channel
  (channelprin2 out* itm))

(de channelprin1 (channel itm)
  %. Display Itm in READable form
  (recursivechannelprin1 channel itm 0))

(de recursivechannelprin1 (channel itm level)
  (case (tag itm)
    ((posint-tag negint-tag)
	(if (eq channel 4) % explode , flatsize etc
		 (checklinefit 10 channel 'channelwriteinteger itm)
	  (checklinefit (flatsize itm)  channel 'channelwriteinteger itm)))
    ((id-tag) % leave room for possible escape chars
     (checklinefit (wplus2 (strlen (strinf (symnam (idinf itm)))) 1)
		   channel 'channelprintid itm))
    ((unbound-tag) % leave room for possible escape chars
     (checklinefit (wplus2 (strlen (strinf (symnam (idinf itm)))) 16)
		   channel 'channelprintunbound itm))
    ((string-tag)
     (checklinefit (wplus2 (strlen (strinf itm)) 1) channel
		   'channelprintstring itm))
    ((code-tag)
     (checklinefit 14 channel 'channelwritecodepointer itm))
    ((fixnum-tag)
	(if (eq channel 4) % explode , flatsize etc
		 (checklinefit 20 channel 'channelwritefixnum itm)
	  (checklinefit (flatsize itm)  channel 'channelwritefixnum itm)))
    ((floatnum-tag) 
	(if (eq channel 4) % explode , flatsize etc
		 (checklinefit 20 channel 'channelwritefloat itm)
	  (checklinefit (flatsize itm)  channel 'channelwritefloat itm)))
    ((words-tag) (channelwritewords channel itm))
    ((halfwords-tag) (channelwritehalfwords channel itm))
    ((bytes-tag) (channelwritebytes channel itm))
    ((pair-tag) (channelprintpair channel itm level))
    ((vector-tag) (channelprintvector channel itm level))
    ((evector-tag) (channelprintevector channel itm level))
    ((context-tag) (channelprintcontext channel itm level))
    ((bstruct-tag) (channelprintbstruct channel itm level))
    ((bvector-tag) (channelprintbvector channel itm level))
    ((funarg-tag) (channelprintfunarg channel itm level))
    ((sgd-tag) (channelprintsgd channel itm level))
    (nil (checklinefit 20 channel 'channelwriteunknownitem itm)))
  itm)

(de prin1 (itm)
  %. ChannelPrin1 to current output
  (channelprin1 out* itm))


(off fast-integers)

%% End of file.
