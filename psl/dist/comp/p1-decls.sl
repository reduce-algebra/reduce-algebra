%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PC:P1-DECLS.SL
% Description:  Machine-independent compiler declarations
% Author:       Eric Benson, Sam Sands
% Created:      19-Jun-84 16:28:45
% Modified:     16-Aug-84 08:48:45 (Brian Beach)
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1987, University of Utah
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 21-Jul-93 (Winfried Neun)
%  Added (w)quotient,wremainder to the list of side-effect-free functions.
% 16-Aug-84 08:43:27 (Brian Beach)
%  Removed PROGN from the list of side-effect-free functions.
% 19-Jun-84 16:28:56 (Jim Ambras/CRC)
%  Extracted this file from the first part of comp-decls.sl.
% 04-Jun-84 12:47:15 (Brian Beach)
%  Added type checking functions for EVECTORS.
% 25-Apr-84 08:15:38 (Brian Beach)
%  Pass 1 functions removed from this file.  They now reside in PASS-1.SL.
% 27-Mar-84 08:23:48 (Brian Beach)
%  Added COMPFNs for IDAPPLY and CODEAPPLY.
%  Added argument count properties for COMPFNs.
% 19-Apr-84 07:45:34 (Brian Beach)
%  Removed constructors from the list of side-effect-free functions, since
%  any subsequent modification of those constants will cause problems.
% 16-Mar-84 13:20:27 (Brian Beach)
%  Added declaration of variables known to be constant.
%  Added declaration of side-effect-free functions.  Removed &DOOP as DOFN
%  (on WSHIFT and WNOT) since constants are automatically handled now.
% 15-Dec-83 10:59:59 (Tim Tillson)
%  Added Brian Beach's pass1 functions for WARRAYS, WVARS and WSTRINGS to
%  Sam's D-register model version
%
%  <PSL.COMP>COMP-DECLS.RED.16,  3-Sep-82 09:46:43, Edit by BENSON
%  Added PA1REFORMFN for WNOT
%  <PSL.COMP>COMP-DECLS.RED.5,   3-Dec-82 18:20:08, Edit by PERDUE
%  Removed PA1REFORMFN for NE
%  <PSL.COMP>COMP-DECLS.RED.6,  24-Jan-83 16:04:00, Edit by MLGriss
%  Changed W to !%!%!%W in the EQCAR to avoid subst W into EQCAR form
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% IDs which are known to contain constant values:

(put 'nil   'constant?  t)
(put 't     'constant?  t)

% Things which can be compiled

(FLAG '(EXPR FEXPR MACRO NEXPR)             'COMPILE)

% Simplification

(put 'WPLUS2      'DOFN		'PLUS2)
(put 'WDIFFERENCE 'DOFN		'DIFFERENCE)
(put 'WMINUS 	  'DOFN		'MINUS)
(put 'WTIMES2 	  'DOFN		'TIMES2)
(put 'WQUOTIENT   'DOFN		'QUOTIENT)
(put 'WREMAINDER  'DOFN		'REMAINDER)
(put 'WAND 	  'DOFN		'LAND)
(put 'WOR 	  'DOFN		'LOR)
(put 'WXOR 	  'DOFN		'LXOR)
(put 'WNOT 	  'DOFN		'LNOT)
(put 'WSHIFT 	  'DOFN		'LSHIFT)

(put 'WPLUS2 	  'returns-untagged-value? 	t)
(put 'WDIFFERENCE 'returns-untagged-value? 	t)
(put 'WMINUS 	  'returns-untagged-value? 	t)
(put 'WTIMES2 	  'returns-untagged-value? 	t)
(put 'WQUOTIENT   'returns-untagged-value? 	t)
(put 'WREMAINDER  'returns-untagged-value? 	t)
(put 'WAND 	  'returns-untagged-value? 	t)
(put 'WOR 	  'returns-untagged-value? 	t)
(put 'WXOR 	  'returns-untagged-value? 	t)
(put 'WNOT 	  'returns-untagged-value? 	t)
(put 'WSHIFT 	  'returns-untagged-value? 	t)

(put 'WTIMES2 	  'ONE 		1)
(put 'WTIMES2 	  'ZERO 	0)
(put 'WPLUS2 	  'ONE 		0)
(put 'WPLUS2 	  'GROUPOPS 	'(WPLUS2 WDIFFERENCE WMINUS))
(put 'WMINUS 	  'GROUPOPS 	'(WPLUS2 WDIFFERENCE WMINUS))
(put 'WDIFFERENCE 'GROUPOPS 	'(WPLUS2 WDIFFERENCE WMINUS))
(put 'WAND 	  'ZERO 	0)
(put 'WOR 	  'ONE 		0)
(put 'WXOR 	  'ONE 		0)

%
% Functions which can be evaluated at compile time if all arguments are
% constants.
%
% The functions commented out are constructor functions, and cannot be
% evaluated since the result might be modified.  
%
% PROGN is not in the list because it is an FEXPR and cannot be applied.
%

(de props-all (names property value)
  (for (in item names)
       (do (put item property value))
       ))

(props-all 
 '(
%  adjoin adjoinq append concat cons del delasc delatq delete delq
%  string-right-trim string-to-list string-to-vector string2list
%  string2vector subla sublis subseq subst substring xcons 
   
   fast-times fast-plus & fast-difference fast-quotient // /= < << <=
   = > >= >> abs aconc acos acosd acot acotd acsc acscd add1 
   alphanumbericp alphap asec asecd asin asind ass assoc
   atan atan2 atan2d atand atom atsoc bldmsg bothcasep car cdr ceiling
   char-downcase char-equal char-font char-greaterp char-int char-lessp
   char-upcase char< char= char> constantp cos cosd cot
   cotdcsc cscd degreestodms degreestoradians
   difference digit digit-char digitp divide dmstodegrees
   dmstoradians eq eqcar eqn eqstr equal expt factorial fix fixp float
   floatp floor geq getv igets igetv isizes isizev land lastcar lastpair
   length leq lessp list lnot log log10 log2 lor lowercasep lshift lxor
   max2 member memq min2 minus minusp mkquote mod ne neq not nth null
   onep pairp plus2 pnth quotient radianstodegrees radianstodms recip
   remainder rest reserse round sec secd sin sind sizesqrt
   string-not-greaterp string-not-lessp string-repeat
   string-search string-search-equal string-search-from
   string-search-from-equal string-size
   strting-trim string-upcase string-upper-bound
   string< string<= string<> string= string> string>=
   stringp sub sub1 substring-equal
   substring= tan tand times2 upbv uppercasep vector-empty? vector-fetch
   vector-size vector-upper-bound vector2list vector2string vectorp
   wshift wquotient wremainder wnot ^ | ~ ~=)
 'no-side-effects?
 t
 )

%
% Tag properties
%

(flag '(!$GLOBAL !$FLUID !$LOCAL WVAR
       QUOTE WCONST IDLOC !*FRAMESIZE 
       REG LABEL FRAME IREG)                               'TERMINAL)
(flag '(!$GLOBAL !$FLUID !$LOCAL WVAR)                     'VAR)
(flag '(!$GLOBAL !$FLUID)                                  'EXTVAR)
(flag '(QUOTE WCONST IDLOC FRAMESIZE)                      'CONST)
(flag '(REG)                                               'REG)
(flag '(FRAMESIZE)                                         'ANYREG)%    scs  



%
% Compile functions
%

(put 'AND 	'COMPFN 	'&COMANDOR)
(put 'OR 	'COMPFN 	'&COMANDOR)
(put 'APPLY 	'COMPFN 	'&COMAPPLY)
(put 'CODEAPPLY 'COMPFN         '&COMCODEAPPLY)
(put 'CONS 	'COMPFN 	'&COMCONS)
(put 'COND 	'COMPFN 	'&COMCOND)
(put 'CASE 	'COMPFN 	'&COMCASE)
(put 'IDAPPLY   'COMPFN         '&COMIDAPPLY)
(put 'GO 	'COMPFN 	'&COMGO)
(put 'PROG2 	'COMPFN 	'&COMPROGN)
(put 'PROGN 	'COMPFN 	'&COMPROGN)
(put 'PROG 	'COMPFN 	'&COMPROG)
(put 'RETURN 	'COMPFN 	'&COMRETURN)

(put 'APPLY     'ARGUMENT-COUNT 2)
(put 'CODEAPPLY 'ARGUMENT-COUNT 2)
(put 'CONS      'ARGUMENT-COUNT 2)
(put 'IDAPPLY   'ARGUMENT-COUNT 2)
(put 'GO        'ARGUMENT-COUNT 1)
(put 'RETURN    'ARGUMENT-COUNT 1)

%
% Patterns for the tests 
%

(put 'EQ            'FLIPTST 'NE)
(put 'NE            'FLIPTST 'EQ)
(put 'WLESSP        'FLIPTST 'WGEQ)
(put 'WGEQ          'FLIPTST 'WLESSP)
(put 'WLEQ          'FLIPTST 'WGREATERP)
(put 'WGREATERP     'FLIPTST 'WLEQ)

(put 'ATOM          'FLIPTST 'PAIRP)
(put 'PAIRP         'FLIPTST 'ATOM)
(put 'STRINGP       'FLIPTST 'NOTSTRINGP)
(put 'NOTSTRINGP    'FLIPTST 'STRINGP)
(put 'BytesP        'FLIPTST 'NOTBytesP)
(put 'NOTBytesP     'FLIPTST 'BytesP)
(put 'WrdsP         'FLIPTST 'NOTWrdsP)
(put 'NOTWrdsP      'FLIPTST 'WrdsP)
(put 'HalfwordsP    'FLIPTST 'NOTHalfwordsP)
(put 'NOTHalfwordsP 'FLIPTST 'HalfwordsP)
(put 'CODEP         'FLIPTST 'NOTCODEP)
(put 'NOTCODEP      'FLIPTST 'CODEP)
(put 'IDP           'FLIPTST 'NOTIDP)
(put 'NOTIDP        'FLIPTST 'IDP)
(put 'INTP          'FLIPTST 'NOTINTP)
(put 'NOTINTP       'FLIPTST 'INTP)
(put 'POSINTP       'FLIPTST 'NOTPOSINTP)
(put 'NOTPOSINTP    'FLIPTST 'POSINTP)
(put 'NEGINTP       'FLIPTST 'NOTNEGINTP)
(put 'NOTNEGINTP    'FLIPTST 'NEGINTP)
(put 'FIXP          'FLIPTST 'NOTFIXP)
(put 'NOTFIXP       'FLIPTST 'FIXP)
(put 'NUMBERP       'FLIPTST 'NOTNUMBERP)
(put 'NOTNUMBERP    'FLIPTST 'NUMBERP)
(put 'FIXNP         'FLIPTST 'NOTFIXNP)
(put 'NOTFIXNP      'FLIPTST 'FIXNP)
(put 'FLOATP        'FLIPTST 'NOTFLOATP)
(put 'NOTFLOATP     'FLIPTST 'FLOATP)
(put 'BIGP          'FLIPTST 'NOTBIGP)
(put 'NOTBIGP       'FLIPTST 'BIGP)
(put 'VECTORP       'FLIPTST 'NOTVECTORP)
(put 'NOTVECTORP    'FLIPTST 'VECTORP)
(put 'evectorp      'fliptst 'notevectorp)
(put 'notevectorp   'fliptst 'evectorp)

% tests for additional CPSL datatypes

(put 'contextp 'fliptst 'notcontextp)
(put 'notcontextp 'fliptst 'contextp)
(put 'bvectorp 'fliptst 'notbvectorp)
(put 'notbvectorp 'fliptst 'bvectorp)
(put 'bstructp 'fliptst 'notbstructp)
(put 'notbstructp 'fliptst 'bstructp)
(put 'funargp 'fliptst  'notfunargp)
(put 'notfunargp 'fliptst  'funargp)
(put 'sgdp 'fliptst 'notsgdp)
(put 'notsgdp 'fliptst 'sgdp)

% End of file.
