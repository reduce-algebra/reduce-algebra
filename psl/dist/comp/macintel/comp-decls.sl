%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PVC:COMP-DECLS.SL
% Description:  Not quite Machine-independent compiler declarations
% Author:       Eric Benson, Sam Sands
% Created:      16-October-1981
% Modified:     28 Mar 1984 1510-PST (Nancy Kendzierski)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 17-Aug 1993 (Herbert Melenk)
%   Introduced TVPAT-eq and TVPAT-tag for simple comparisons returning
%   NIL/T.
% 27-Aug-88 (Julian Padget)
%  Removed various bits that had been moved to p1-decls but not removed
%  from here (see Ambras 13-Jun-84)
% 05-Apr-88 (Julian Padget)
%  Restored various bits for the extra types that CPSL has for
%  fliptst, opentst and openfn properties
% 5 May 1984 (Brian Beach)
%  Removed machine independent parts into PASS-1-DECLS.SL.
% 28 Mar 1984 1509-PST (Nancy Kendzierski)
%  Fixed file name in header.  Merged in two previous changes.
% 28-Mar-84 13:45:59 (Jim Ambras/CRC)
%  Added two puts related to the function EQ to catch an unfolded constant.
% 27-Mar-84 08:23:48 (Brian Beach)
%  Added COMPFNs for IDAPPLY and CODEAPPLY.
%  Added argument count properties for COMPFNs.
% 12-Jan-84          (Sam Sands)
%   Removed M68000 specific stuff for benefit of VAX et. al.
% 15-Dec-83 10:59:59 (Tim Tillson)
%  Added Brian Beech's pass1 functions for WARRAYS, WVARS and WSTRINGS to
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

(put '!*JUMPNOTEQ      'NEGJMP '!*JUMPEQ)
(put '!*JUMPWLESSP     'NEGJMP '!*JUMPWGEQ)
(put '!*JUMPWGEQ       'NEGJMP '!*JUMPWLESSP)
(put '!*JUMPWLEQ       'NEGJMP '!*JUMPWGREATERP)
(put '!*JUMPWGREATERP  'NEGJMP '!*JUMPWLEQ)

(put '!*JUMPTYPE       'NEGJMP '!*JUMPNOTTYPE)
(put '!*JUMPNOTTYPE    'NEGJMP '!*JUMPTYPE)
(put '!*JUMPINTYPE     'NEGJMP '!*JUMPNOTINTYPE)
(put '!*JUMPNOTINTYPE  'NEGJMP '!*JUMPINTYPE)

(put 'AND 	'OPENTST 	'&TSTANDOR)
(put 'OR 	'OPENTST 	'&TSTANDOR)

(put 'EQ 	'OPENTST 	'(TSTPAT  !*JUMPEQ       ))
(put 'NE 	'OPENTST 	'(TSTPAT  !*JUMPNOTEQ    ))

(put 'wgreaterp 'opentst        '(tstpatc *jumpwgreaterp *jumpwlessp))
(put 'wleq      'opentst        '(tstpatc *jumpwleq      *jumpwgeq))
(put 'wgeq      'opentst        '(tstpatc *jumpwgeq      *jumpwleq))
(put 'wlessp    'opentst        '(tstpatc *jumpwlessp    *jumpwgreaterp))

(put 'PAIRP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    PAIR-TAG))
(put 'ATOM 	'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE PAIR-TAG))
(put 'STRINGP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    STRING-TAG))
(put 'NOTSTRINGP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE STRING-TAG))
(put 'VECTORP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    VECTOR-TAG))
(put 'NOTVECTORP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE VECTOR-TAG))
(put 'EVECTORP	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    EVECTOR-TAG))
(put 'NOTEVECTORP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE EVECTOR-TAG))
(put 'CODEP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    CODE-TAG))
(put 'NOTCODEP 	'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE CODE-TAG))
(put 'FLOATP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    FLOATNUM-TAG))
(put 'NOTFLOATP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE FLOATNUM-TAG))

(put 'INTP 	'OPENTST 	'(TSTPAT2 !*JUMPINTYPE  POSINT-TAG))
(put 'NOTINTP 	'OPENTST 	'(TSTPAT2 !*JUMPNOTINTYPE POSINT-TAG))
(put 'FIXP 	'OPENTST 	'(TSTPAT2 !*JUMPINTYPE  BIGNUM-TAG))
(put 'NOTFIXP 	'OPENTST 	'(TSTPAT2 !*JUMPNOTINTYPE BIGNUM-TAG))
(put 'NUMBERP 	'OPENTST 	'(TSTPAT2 !*JUMPINTYPE  FLOATNUM-TAG))
(put 'NOTNUMBERP 'OPENTST 	'(TSTPAT2 !*JUMPNOTINTYPE FLOATNUM-TAG))

(put 'FIXNP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    FIXNUM-TAG))
(put 'NOTFIXNP 	'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE FIXNUM-TAG))
(put 'BIGP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    BIGNUM-TAG))
(put 'NOTBIGP 	'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE BIGNUM-TAG))
(put 'POSINTP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    POSINT-TAG))
(put 'NOTPOSINTP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE POSINT-TAG))
(put 'NEGINTP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    NEGINT-TAG))
(put 'NOTNEGINTP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE NEGINT-TAG))
(put 'IDP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    ID-TAG))
(put 'NOTIDP 	'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE ID-TAG))
(put 'BYTESP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    BYTES-TAG))
(put 'NOTBYTESP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE BYTES-TAG))
(put 'WRDSP 	'OPENTST 	'(TSTPAT2 !*JUMPTYPE    WORDS-TAG))
(put 'NOTWRDSP 	'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE WORDS-TAG))
(put 'HALFWORDSP 'OPENTST 	'(TSTPAT2 !*JUMPTYPE    HALFWORDS-TAG))
(put 'NOTHALFWORDSP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE HALFWORDS-TAG))


%JAP: So the compiler can understand the new types

(put 'CONTEXTP 'OPENTST 	'(TSTPAT2 !*JUMPTYPE    CONTEXT-TAG))
(put 'NOTCONTEXTP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE CONTEXT-TAG))
(put 'BVECTORP 'OPENTST 	'(TSTPAT2 !*JUMPTYPE    BVECTOR-TAG))
(put 'NOTBVECTORP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE BVECTOR-TAG))
(put 'BSTRUCTP 'OPENTST 	'(TSTPAT2 !*JUMPTYPE    BSTRUCT-TAG))
(put 'NOTBSTRUCTP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE BSTRUCT-TAG))
(put 'FUNARGP 'OPENTST	 	'(TSTPAT2 !*JUMPTYPE    FUNARG-TAG))
(put 'NOTFUNARGP 'OPENTST 	'(TSTPAT2 !*JUMPNOTTYPE FUNARG-TAG))

(put 'SGDP 'OPENTST	 	'(TSTPAT2 !*JUMPTYPE    SGD-TAG))
(put 'NOTSGDP 'OPENTST	 	'(TSTPAT2 !*JUMPNOTTYPE SGD-TAG))

(put 'EQ 	'OPENFN 	'(TVPAT-eq !*JUMPEQ       ))
(put 'NE 	'OPENFN 	'(TVPAT-eq !*JUMPNOTEQ    ))

(put 'WGREATERP 'OPENFN 	'(TVPAT !*JUMPWGREATERP))
(put 'WLEQ 	'OPENFN 	'(TVPAT !*JUMPWLEQ     ))
(put 'WGEQ 	'OPENFN 	'(TVPAT !*JUMPWGEQ     ))
(put 'WLESSP 	'OPENFN 	'(TVPAT !*JUMPWLESSP   ))

(put 'PAIRP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    PAIR-TAG))
(put 'ATOM 	'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE PAIR-TAG))
(put 'STRINGP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    STRING-TAG))
(put 'NOTSTRINGP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE STRING-TAG))
(put 'VECTORP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    VECTOR-TAG))
(put 'NOTVECTORP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE VECTOR-TAG))
(put 'EVECTORP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    EVECTOR-TAG))
(put 'NOTEVECTORP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE EVECTOR-TAG))
(put 'CODEP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    CODE-TAG))
(put 'NOTCODEP 	'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE CODE-TAG))
(put 'FLOATP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    FLOATNUM-TAG))
(put 'NOTFLOATP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE FLOATNUM-TAG))

(put 'INTP 	'OPENFN 	'(TVPAT1 !*JUMPINTYPE  POSINT-TAG))
(put 'NOTINTP 	'OPENFN 	'(TVPAT1 !*JUMPNOTINTYPE POSINT-TAG))
(put 'FIXP 	'OPENFN 	'(TVPAT1 !*JUMPINTYPE  BIGNUM-TAG))
(put 'NOTFIXP 	'OPENFN 	'(TVPAT1 !*JUMPNOTINTYPE BIGNUM-TAG))
(put 'NUMBERP 	'OPENFN 	'(TVPAT1 !*JUMPINTYPE  FLOATNUM-TAG))
(put 'NOTNUMBERP 'OPENFN 	'(TVPAT1 !*JUMPNOTINTYPE FLOATNUM-TAG))

(put 'FIXNP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    FIXNUM-TAG))
(put 'NOTFIXNP 	'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE FIXNUM-TAG))
(put 'BIGP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    BIGNUM-TAG))
(put 'NOTBIGP 	'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE BIGNUM-TAG))
(put 'POSINTP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    POSINT-TAG))
(put 'NOTPOSINTP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE POSINT-TAG))
(put 'NEGINTP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    NEGINT-TAG))
(put 'NOTNEGINTP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE NEGINT-TAG))
(put 'IDP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    ID-TAG))
(put 'NOTIDP 	'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE ID-TAG))
(put 'BYTESP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    BYTES-TAG))
(put 'NOTBYTESP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE BYTES-TAG))
(put 'WRDSP 	'OPENFN 	'(TVPAT-tag !*JUMPTYPE    WORDS-TAG))
(put 'NOTWRDSP 	'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE WORDS-TAG))
(put 'HALFWORDSP 'OPENFN 	'(TVPAT-tag !*JUMPTYPE    HALFWORDS-TAG))
(put 'NOTHALFWORDSP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE HALFWORDS-TAG))

%JAP: So the compiler can understand the new types

(put 'CONTEXTP 'OPENFN 		'(TVPAT-tag !*JUMPTYPE    CONTEXT-TAG))
(put 'NOTCONTEXTP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE CONTEXT-TAG))
(put 'BVECTORP 'OPENFN 		'(TVPAT-tag !*JUMPTYPE    BVECTOR-TAG))
(put 'NOTBVECTORP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE BVECTOR-TAG))
(put 'BSTRUCTP 'OPENFN 		'(TVPAT-tag !*JUMPTYPE    BSTRUCT-TAG))
(put 'NOTBSTRUCTP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE BSTRUCT-TAG))
(put 'FUNARGP 'OPENFN	 	'(TVPAT-tag !*JUMPTYPE    FUNARG-TAG))
(put 'NOTFUNARGP 'OPENFN 	'(TVPAT-tag !*JUMPNOTTYPE FUNARG-TAG))

(put 'SGDP 'OPENFN	 	'(TVPAT-tag !*JUMPTYPE    SGD-TAG))
(put 'NOTSGDP 'OPENFN 		'(TVPAT-tag !*JUMPNOTTYPE SGD-TAG))

(put 'wplus2    'openfn         '(assocpat *wplus2))
(put 'wdifference 'openfn       '(subpat *wdifference))
(put 'wtimes2   'openfn         '(assocpat *wtimes2))
(put 'wminus    'openfn         '(unarypat *wminus))
(put 'wand      'openfn         '(assocpat *wand))
(put 'wor       'openfn         '(assocpat *wor))
(put 'wxor      'openfn         '(assocpat *wxor))
(put 'wnot      'openfn         '(unarypat *wnot))
(put 'wshift    'openfn         '(nonassocpat *wshift))
(put 'wlshift   'openfn         '(nonassocpat *wlshift))
(put 'wrshift   'openfn         '(nonassocpat *wrshift))
(put 'ASHIFT 	'OPENFN         '(NONASSOCPAT *ASHIFT))          %      scs
(put 'mkitemrev 'openfn         '(nonassocpat *mkitem))
(put 'loc       'openfn         '(unarypat *loc))
(put 'field     'openfn         '(fieldpat *field))
(put 'signedfield 'openfn       '(fieldpat *signedfield))
(put 'putfieldrev 'openfn       '(putfieldpat *putfield))

(put '$NAME     'OPENFN         '$NAME)             % DUMMY     %   scs
(put 'CAR       'OPENFN         '(CARCDRPAT CAR))               %   scs
(put 'CDR       'OPENFN         '(CARCDRPAT CDR))               %   scs
(put 'MEMORY    'OPENFN         '(MEMORYPAT MEMORY))            %   scs

(put 'SETQ 	'OPENFN 	'(SETQPAT NIL))
(put 'RPLACA 	'OPENFN 	'(RPLACPAT CAR))
(put 'RPLACD 	'OPENFN 	'(RPLACPAT CDR))

% In memory operations

(put '*addmem   'openfn         '(modmempat *addmem *wplus2 ))
% (put '*mpymem   'openfn         '(modmempat *mpymem *wtimes2))

(flag '(!*ADDMEM !*MPYMEM)       'MEMMOD)   

(put 'WPLUS2       'MEMMODFN  '!*ADDMEM)
% (put 'WTIMES2      'MEMMODFN  '!*MPYMEM) 

(put '!*ADDMEM  'UNMEMMOD  '!*WPLUS2) 
% (put '!*MPYMEM  'UNMEMMOD  '!*WTIMES2) 


% Match functions

(put 'ANY       'MATCHFN '&ANY)
(put 'VAR       'MATCHFN '&VAR)
(put 'REG       'MATCHFN '&REGFP)
(put 'DEST      'MATCHFN '&DEST)
(put 'USESDEST  'MATCHFN '&USESDEST)
(put 'REGN      'MATCHFN '&REGN)
(put 'NOTDEST   'MATCHFN '&NOTDEST)
(put 'NOTANYREG 'MATCHFN '&NOTANYREG)
(put 'MEM       'MATCHFN '&MEM)
(put 'ANYREGFN  'MATCHFN '&ANYREGFNP)

(put 'REGNP     'MATCHFN  '&REGNP)                           %     scs 
(put 'CONST     'MATCHFN  '&CONSTP)                          %     scs


% Macro functions

(put 'A1  'SUBSTFN '&ARG1)
(put 'A2  'SUBSTFN '&ARG2)
(put 'A3  'SUBSTFN '&ARG3)
(put 'A4  'SUBSTFN '&ARG4)
(put 'FN  'SUBSTFN '&PARAM1)
(put 'MAC 'SUBSTFN '&PARAM2)
(put 'P2  'SUBSTFN '&PARAM3)
(put 'P3  'SUBSTFN '&PARAM4)
(put 'T1  'SUBSTFN '&GETTEMP)
(put 'T2  'SUBSTFN '&GETTEMP)
(put 'T3  'SUBSTFN '&GETTEMP)
(put 'T4  'SUBSTFN '&GETTEMP)
(put 'L1  'SUBSTFN '&GETTEMPLBL)
(put 'L2  'SUBSTFN '&GETTEMPLBL)
(put 'L3  'SUBSTFN '&GETTEMPLBL)
(put 'L4  'SUBSTFN '&GETTEMPLBL)
(put 'LA1 'SUBSTFN '&LOCARG1)                                           % scs
                                                                       
(de &LOCARG1  (TNAME ARGS PARAMS) (&LOCATE (&ARG1 TNAME ARGS PARAMS)))  % scs



% Emit functions

(put '!*LOAD    'EMITFN '&EMITLOAD)
(put '!*STORE   'EMITFN '&EMITSTORE)
(put '!*JUMP    'EMITFN '&EMITJUMP)
(put '!*LBL     'EMITFN '&EMITLBL)
(put '!*ADDMEM  'EMITFN '&EMITMEMMOD)
(put '!*MPYMEM  'EMITFN '&EMITMEMMOD)

(put '!*USES    'EMITFN '&USES)                                 %       scs
(put '!*RETURN  'EMITFN '&RETURN)                               %       scs


% Optimizing functions

(put '!*LBL 	'OPTFN 	'&LBLOPT)
(put '!*MOVE 	'OPTFN 	'&STOPT)
(put '!*JUMP 	'OPTFN 	'&JUMPOPT)		

% Assorted other flags

(flag '(!*JUMP !*LINKE !*EXIT)                'TRANSFER)
(flag '(!*LINK !*LINKE)                       'UNKNOWNUSE)

(put '!*LINK  'EXITING  '!*LINKE)

% Initialize variables

(setq !*MSG             T)				% Do print messages
(setq !*INSTALLDESTROY  NIL)
(setq !*USINGDESTROY    T)
(setq !*SHOWDEST        NIL)
(setq !*NOFRAMEFLUID    T)
(setq !*USEREGFLUID     NIL)
(setq !*NOLINKE         NIL)       %. Permit LINKE
(setq !*ORD             NIL)		%. Dont force ORDER
(setq !*R2I             T)		%. Do convert Rec to Iter
(setq GLOBALGENSYM&     (LIST (GENSYM)))	 % initialize symbol list


(setq MAXNARGS&       15)   
(setq LASTACTUALREG&   5)

