%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:SYS-DM.SL
% Title:        Lisp item constructors & selectors for 68000 Syslisp
% Author:       Eric Benson, University of Utah
% Created:	10-Jul-1981
% Modified:     21-Jun-84 (Vicki O'Day)
% Status:       Experimental (Do Not Distribute)
% Mode:         Lisp
% Package:      Compiler
% Compile to:   PL:SYS-DM.B
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 20-Jun-89 (Winfried Neun)
% added symget access
% 21-Jun-84 (Vicki O'Day)
%  Made HP-UX corrections to system-list.  Took out constant declarations
%  that were duplicates of some in sys-consts.
% 04-Jun-84 12:52:35 (Brian Beach)
%  This file is now a separately compilable module which is loaded by data-machine.
% 17-Nov-83 (Brian Beach)
%   Translated to LISP from RLISP.  Cleaned up the macros some.
%
% 22-Jul-83  Nancy Kendzierski
%   Changed use of "autodecrement" (in a comment) to "predecrement".
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(load tags)

(define-constant *system-list* '(mc68000 chipmunk hpux200 unix))

(fluid '(symfnc))

% Retrieve the address stored in the function cell
(ds symfnc (function-cell)
  (getmem (wplus2 symfnc (wtimes2 function-cell 
				   addressingunitsperfunctioncell)
			  )))

% Can't really do PutSymFnc
(dm putsymfnc (u)
  '(stderror '"PutSymFnc does not exist on the i386"))

% access to SYMget vector
 
(dm Symget (U)
       (List 'wgetv 'Symget (cadr U)))
 
% Macros for building stack pointers
(ds makestackpointerfromaddress (u)
  u
  )

(ds makeaddressfromstackpointer (u)
  u
  )

(ds adjuststackpointer (pointer amount)
  (wdifference pointer amount)
  )

(loadtime 
 (put 'eof 'charconst (char (cntrl z)))
 (remprop 'adjuststackpointer 'openfn)
 )


(ds FloatHighOrder (address)
  (wgetv address 1))

(ds FloatLowOrder (address)
  (wgetv address 1))
