%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PC:PASS-2-3.SL
% Description:  Passes two and three of the PSL compiler
% Author:       M. Griss, E. Benson, J. Peterson
% Created:      
% Modified:     
% Package:      
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
%	Based on original Standard LISP Compiler by Griss and Hearn
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 22-Nov-94 (Herbert Melenk)
%  enable GO out of prog, including correct rebinding of fluids.
% 22-Nov-94 (Herbert Melenk)
%  &comperror redirected to stderror to avoid the generation of
%  damaged code.
% 15-May-92 (Winfried Neun) 
%  changed &freeregs to discard (reg 1) which produced wrong code in
%    (de hu (x) (prog (a) (return x)))
% 11-Jun-91 (Herbert Melenk and Winfried Neun)
%  Fixed usage of pregs& in &loadargs and &comload and &freeregs
% 31-Aug-90 (Herbert Melenk)
%  Fixed &storevar
% 31-Aug-88 (Bob Kessler, Herbert Melenk and Winfried Neun)
%  Updated &argloc to avoid using precomputed immediate integer constants.
% 26-May-87 (Leigh Stoller & Harold Carr)
%  Replaced &comandor with 3.2 version and copied 05-Nov-85 and 14-Sep-84
%   revision comments to this file.
% 05-Nov-85 09:17:59 (Robert Kessler)
%  Fixed bug in &comcond that caused multiple (cond (t 1) (t 3)) to
%  compile incorrectly.  Also, fixed bug in &comandor so (and) and
%  (or) compiled correctly.
% 14-Sep-84 14:04:19 (Robert Kessler and JCP)
%  Fix bug in comandor, see comment in that function.
% 31-Dec-84 10:00 (Brian Beach)
%  Merged COMPILER-RUNNING fix and COMCOND fix.
% 25-Jul-84 14:40:00 (Mike Creech)
%  Corrected comments for *COMPILER-RUNNING.
% 13-Jul-84 11:24:59 (Mike Creech)
%  Added fluild *COMPILER-RUNNING in COMPD that it T when the compiler is running
%  and NIL otherwise.
% 14-Nov-84 14:54:19 (Brian Beach)
%  Fixed COMCOND so that (COND (T 1) (T 2)) will work.
% 01-Aug-84 13:33:00 (Martin Griss)
%  Fixed &PROTECTARGREGS.
% 3:25pm  Friday, 30 March 1984  (Nancy Kendzierski)
%  Removed debugging (print args) statement from &comapply-aux.
% 2:37pm  Friday, 30 March 1984  (Brian Beach)
%  Fixed &COMCONS.  (setf exp (rest exp)) was missing.
% 27-Mar-84 08:13:21 (Brian Beach)
%  Added optimization for IDAPPLY and CODEAPPLY similar to that done for APPLY.
%  Added ARGUMENT-COUNT property for special compiler functions so that the
%  count doesn't have to be checked in each COMPFN.
%  Added use of *FAST-APPLY-LOAD Cmacro for loading the machine specific register
%  that hold the function or address being called.
% 20-Mar-84 14:00:20 (Brian Beach)
%  Removed if-system in COMAPPLY by introducing a new Cmacro: *FAST-APPLY-LOAD
%  to load the appropriate register with the function for FAST-APPLY.
% 14 Mar 1984 1340-PST (Nancy Kendzierski)
%  Changed calls on REGP to calls on RegisterP (it's defined in
%  common-predicates.sl, part of pass-1-lap)
% 29-Feb-84 11:20:26 (Brian Beach)
%  Removed &CONSTTAG function (equivalent function now is RESULT-TAG).
%  Changed ASSOCOPV so that it does not reorder non-constant parameters.
%  Removed functions for handling LISPVAR and PUTLISPVAR.
%  Ran through pretty printer.
% 19-Jan-84 18:32:20 (Tim Tillson and Sam Sands)
%   Revised function &COMCONS to change the order of evaluation of arguments.
% 18-Jan-84 (Sam Sands)
%   Added quick hack in &COMAPPLY to get it working on the VAX.  A better
%   solution must be found.
% 16-Jan-84 15:48:07 (Tim Tillson)
%    Added wconstevaluable-for-compiler which evaluates expressions only if
%    the function in question has the property DOFN; taken from the routine
%    in pc/anyreg-cmacro.sl
% 30 Dec 1983 1052-PST (Brian Beach)
%  Added stuff from build file.
% 20-Dec-83 16:09:48 (Sam Sands)
%    Fixed MKWCONST to fetch the actual constant value from the property list
% 19 Dec 1983 0900-PST (Brian Beach)
%   Changed WCONSTP so that any integer that is a fixnum or inum is a 
%   wconstant.  This change will go away as soon as syslisp mode goes away.
%   Only relevant on the DEC20 where there are still RED files.
% 14-Dec-83 14:44:06 (Tim Tillson)
%   Incorporated Brian's changes into Sam's D-model version;
%   should eventually remove all references to SYSLISP
%
%  10 November, 1983  Brian Beach
%    WCONSTP       - Accepts only forms prefixed by "WCONST" and, in
%                    SYSLISP mode, identifiers declared as WCONSTS.
%    MKWCONST      - Removed lookup of WCONST properties, just adds 
%                    WCONST prefix now.
%    ISAWCONST     - Removed check of *SYSLISP
%    PASS-1-WARRAY - Added
%    PASS-1-NOOP   - Added
%    &ASSOCOPV     - Now uses WconstEvaluable for constants.
%    &GETNUM       - Now calls WconstEvaluable to evaluate constants.
%
%  Nov-83  Sam Sands
%   Revised to support D REGISTER model, fix bugs, some optimizations, etc.
%
%     10/31/83 Gerrie Shults      Converted to Lisp syntax
%
% Edit by Cris Perdue, 20 May 1983 1004-PDT
% Added Galway's patch to !&ARGLOC, also extra check and warn clause
% Edit by Cris Perdue, 9 May 1983 1619-PDT
% Removed imports of compl-extra -- now an "extra" module that may be loaded
% with the compiler at a user's discretion.
% Edit by Cris Perdue, 28 Apr 1983 1758-PDT
% Now imports compl-extra, LISP syntax extras
%  <PSL.COMP>COMPILER.RED.21, 30-Mar-83 08:19:44, Edit by KESSLER
%  Fix !&REGMEM to safely check cadr.
% <PSL.COMP>COMPILER.RED.21,  4-Mar-83 01:55:41, Edit by GALWAY
%   Modified CMACRO expansion to check for correct number of arguments in
%   the function call being expanded.
% MLG: 15 Dec
%   added additional arguments to 
%    Compiler BUG message in &LOCATE to get more info
%  <PSL.COMP>COMPILER.RED.19,  3-Dec-82 18:21:21, Edit by PERDUE
%  Removed REFORMNE, which was over-optimizing sometimes
%  <PSL.COMP>COMPILER.RED.18,  1-Dec-82 15:59:45, Edit by BENSON
%  Fixed car of atom bug in &PaApply
%  <PSL.COMP>COMPILER.RED.4, 20-Sep-82 11:40:31, Edit by BENSON
%  Slight improvement to "FOO not compiled" messages
%  <PSL.COMP>COMPILER.RED.2, 20-Sep-82 10:32:51, Edit by BENSON
%  (DE FOO (LIST) (LIST LIST)) does the right thing
%  <PSL.COMP>COMPILER.RED.10, 10-Sep-82 12:43:27, Edit by BENSON
%  NONLOCALSYS calls NONLOCALLISP if not WVAR or WARRAY
%  <PSL.COMP>COMPILER.RED.9, 10-Sep-82 09:53:08, Edit by BENSON
%  Changed error and warning messages
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(global '(erfg*
	  maxnargs&
	  globalgensym&     % list of symbols to be re-used by the compiler
	  *nolinke 
	  *ord
	  *r2i
	  *unsafebinder
	  *noframefluid
	  *useregfluid
	  *installdestroy
	  *usingdestroy
	  *showdest
	  ))

(fluid '(dfprint*
         *msg
	 *plap
	 alsts&
	 flagg&
	 name&
	 golist&
	 codelist&
	 branchpoint&       %   REPLACES CONDTAIL!&   scs
	 tail&              %                         scs
	 llngth&
	 narg&              %% A-list database ((register . info) . . . ).  The info
	                    %% for each register seems to be a list of "expressions"
                	    %% whose values are available in the register. /csp
	 regs& 
	 exitt&
	 lblist&
	 jmplist& 
	 slst&              %% A-list database ((($LOCAL <name>) (FRAME <number>)) . . . )
                            %% Maps local name to frame slot and vice-versa. /csp
	 stomap& 
	 lastactualreg&
	 switch&
	 toplab&
	 freebound&
	 status&
	 regs1&
	 pregs&
	 gpregs& %  scs 
	 destreg&
	 exitregs&
	 dest&
	 environment&
	 holemap&
	 localgensym&      % traveling pointer into GLOBALGENSYM!&
	 ))


%COMMENT machine dependent parts are in a separate file; 
%
%COMMENT these include the macros described below and, in addition,
%	an auxiliary function !&MKFUNC which is required to pass
%	functional arguments (input as FUNCTION <func>) to the
%	loader. In most cases, !&MKFUNC may be defined as MKQUOTE; 
%
%COMMENT Registers used:
%1-MAXNARGS!&	used for args of link. result returned in reg 1; 
%
%COMMENT Macros used in this compiler; 
%
%COMMENT The following macros must NOT change REGS!& 1-MAXNARGS!&:
%!*ALLOC nw      	allocate new stack frame of nw words
%!*DEALLOC nw		deallocate above frame
%!*ENTRY	name type noargs   entry point to function name of type type
%			   with noargs args
%!*EXIT			EXIT to previously saved return address
%!*JUMP adr  		unconditional jump
%!*LBL adr		define label
%!*LAMBIND regs alst	bind free lambda vars in alst currently in regs
%!*PROGBIND alst		bind free prog vars in alst
%!*FREERSTR alst		unbind free variables in alst
%!*STORE reg floc	store contents of reg (or NIL) in floc
%
%COMMENT the following macro must only change specific register being
%	loaded:
%
%!*LOAD reg exp		load exp into reg; 
%
%COMMENT the following macros do not protect regs 1-MAXNARGS!&:
%
%!*LINK fn type nargs	  link to fn of type type with nargs args
%!*LINKE fn type nargs nw  link to fn of type type with nargs args
%			     and EXITT!& removing frame of nw words; 
%
%
%COMMENT variable types are: 
%
%  LOCAL		allocated on stack and known only locally
%  GLOBAL	accessed via cell (GLOBAL name) known to
%	        loader at load time
%  WGLOBAL	accessed via cell (WGLOBAL name) known to
%	        loader at load time, SYSLISP
%  FLUID		accessed via cell (FLUID name)
%		known to loader. This cell is rebound by LAMBIND/
%		PROGBIND if variable used in lambda/prog list
%		and restored by FREERSTR; 
%
%COMMENT global flags used in this compiler:
%!*UNSAFEBINDER	for Don's BAKER problem...GC may be called in
%		Binder, so regs cant be preserved
%!*MODULE	indicates block compilation (a future extension of
%		this compiler)
%!*NOLINKE 	if ON inhibits use of !*LINKE macro
%!*ORD		if ON forces left-to-right argument evaluation
%!*PLAP		if ON causes LAP output to be printed
%!*R2I		if ON causes recursion removal where possible;
%
%
%COMMENT global variables used:
%
%DFPRINT!*	name of special definition process (or NIL)
%ERFG!*		used by REDUCE to control error recovery
%MAXNARGS!&	maximum number of arguments permitted in implementation;
%
%
%
%%Standard LISP limit;
%
%COMMENT fluid variables used:
%
%ALSTS	alist of fluid parameters
%FLAGG	used in COMTST, and in FIXREST
%FREEBOUND indicates that some variables were FLUID
%GOLIST	storage map for jump labels
%PREGS   A list of protected registers
%CODELIST  code being built
%BRANCHPOINT   The point (in SLST) of most recent conditional branch     scs
%TAIL          The accumulated SLST on other branches of a conditional   scs
%CONDTAIL                                           (no longer used )    scs
%LLNGTH	cell whose CAR is length of frame
%NAME	NAME!& of function being currently compiled
%FNAME!&	name of function being currently compiled, set by COMPILE
%NARG	number of arguments in function
%REGS	known current contents of registers as an alist with elements 
%	of form (<reg> . <contents>)
%EXITT	label for *EXIT jump
%EXITREGS List or register statuses at return point
%LBLIST	list of label words
%JMPLIST	list of locations in CODELIST!& of transfers
%SLST	association list for stores which have not yet been used
%STOMAP	storage map for variables
%SWITCH	boolean expression value flag - keeps track of NULLs; 
%

% ---- Support Procedures --------

(de &mkfunc (fn)
  % Makes a procedure Name into a procedure object for compilation. 
  % Later do FUNARGS
  (mkquote fn))

(de &anyregp (x)
  % Test if X is an ANYREG
  (flagp x 'anyreg))

 (dm localf (u)
   % Declare functions internal, ala Franz
   % Not presently in use.
   (&comperror "De-implemented macro used: LOCALF")
   )

%************************************************************
%        The compiler
%************************************************************

(de compile (x)
  % Top level compile entry - X is list of functions to compile
  (for (in fname& x)
       (do (let ((exp (getd fname&)))
	     (cond ((null exp) 
		    (&compwarn (list "No definition for" fname&)))
		   ((codep (cdr exp)) 
		    (&compwarn (list fname& "already compiled")))
		   (t (compd fname& (car exp) (cdr exp)))
		   )))))

% COMPD - Single function compiler
% NAME!& is either the name of the function or the value
% ***Code**Pointer**, indicating that a code pointer is to be returned.
% Makes sure function type is compilable.  Sets up CFNTYPE
% property if necessary so the function's type will be known
% during its compilation and thereafter.
% Removes the property when through if it is redundant.
% Calls &COMPROC to compile and adds entry point to the LAP code generated.
% Shows LAP code when PLAP is on.
% Runs LAP.

% *COMPILER-RUNNING is a fluid variable that CANNOT be setf'ed to T at the
% beginning of this function and to NIL at the end of this function.
% This is because its purpose is to detect recursive calls on the compiler.
% A recursive call with this approach will set the variable to nil when
% it leaves COMPD -- making it nil to the calling COMPD.
(de COMPD (NAME& TY Exp) 
  (let ((*COMPILER-RUNNING T))
    (PROG nil 
     (cond ((not (FLAGP TY 'COMPILE)) 
	    (&COMPERROR (list "Uncompilable function type" TY)) 
	    (Return nil)))
     (cond ((not (EqCar Exp 'lambda)) 
	    (&COMPERROR(list "Attempt to compile non-lambda expression" Exp)) 
	    (Return nil))
	   (t
	    % The extra rlisp stuff following this function was right here.
	    (PROG (X) 
	     (cond ((memq TY '(expr fexpr)) 
		    (PUT NAME& 'CFNTYPE (list TY)))) 
	     (Setq X
		   (CONS (list '*ENTRY
			       NAME&
			       TY
			       (Length (Cadr Exp)))
			 (&COMPROC Exp 
				   (cond ((memq TY '(expr fexpr)) 
					  NAME&))))) 
	     (cond (*PLAP (foreach Y in X do (PRINTF "%f%p%n" Y)))) 
	     % ***Code**Pointer** is a magic token that tells
	     % COMPD to return a code pointer instead of an ID
	     (cond ((equal NAME& '***Code**Pointer***) 
		    (Setq NAME& (LAP X)))
		   (t 
		    (LAP X) 
		    %this is the hook to the assembler. LAP must
		    %remove old function definition if it exists;
		    (cond 
		     ((and (Setq X (GET NAME& 'CFNTYPE))
			   (EqCar (GETD NAME&) (car X))) 
		      (REMPROP NAME& 'CFNTYPE))))))))
     (Return NAME&))))

% This used to be in above, but noone has the guts to remove it.

%/        ELSE IF !*MODULE THEN MODCMP(NAME!&,TY,EXP)
%              ELSE IF DFPRINT!*
%               THEN APPLY(DFPRINT!*,LIST IF TY EQ 'EXPR
%                                  THEN 'DE . (NAME!& . CDR EXP)
%                                 ELSE IF TY EQ 'FEXPR
%                                  THEN 'DF . (NAME!& . CDR EXP)
%                                 ELSE IF TY EQ 'MACRO
%%                                  THEN 'DM . (NAME!& . CDR EXP)
%                                 ELSE IF TY EQ 'NEXPR
%                                  THEN 'DN . (NAME!& . CDR EXP)
%                                 ELSE LIST('PUTD,MKQUOTE NAME!&,
%                                           MKQUOTE TY,
%                                           MKQUOTE EXP))

(de &comproc (exp name&)
  % COMPROC does the dirty work - initializes variables and gets the 
  % three passes going.
  % compiles a function body, returning the generated LAP;
  (prog (narg& codelist& flagg& jmplist& lblist& localgensym& llngth& 
               regs& regs1& alsts& exitt& toplab& slst& stomap& condtail& 
               freebound& holemap& pregs& switch& exitregs& rn)
        (setq localgensym& globalgensym&)
        (setq pregs& nil)
        (setq regs& nil)
        (setq llngth& 0)
        (unless (eqcar exp 'lambda)
          (&comperror (list "Attempt to compile a non-lambda expression" 
                       exp))
          (return nil))
        (setq narg& (length (cadr exp)))
        (setq exitregs& nil)
        (setq exitt& (&genlbl))
        (setq toplab& (&genlbl))
        (setq stomap& nil)
        (setq codelist& (list '(*alloc (*framesize))))
        (&attlbl toplab&)
        (setq exp (compiler-pass-1 exp))
        (when (greaterp narg& maxnargs&)
          (&comperror (list "Too many arguments" narg&)))
        (setq alsts& (&varbind (cadr exp) t))
        % Generate LAMBIND
        (setq rn 1)
        (for (from i 1 (length (cadr exp)) 1) 
             (do (setq regs& (&addrvals (&mkreg i) regs& (list (&ireg i))))))
        (&pass2 (caddr exp))
        (&freerstr alsts& 1)
        %Restores old fluid bindings          %  1?  scs 
        (&pass3)
        (when (or *installdestroy *showdest)
          (&installdestroy name&))
        (&reformmacros)
        % Plugs compile time constants into macros. FIXFRM?
        (&remtags)
        % Kludge
        (return codelist&)))

%-------------------------------------------------------------------
% Pass2 of the COMPILER
%-------------------------------------------------------------------
(de &installdestroy (name&)
  %         scs
  % determine which (if any) registers are unaltered by the function.
  % Print this information out if !*SHOWDEST, install it on the
  % property list of the function if !*INSTALLDESTOY
  (prog (r usedregs)
        (when (equal (setq usedregs (&regsused codelist& nil nil t)) 'all)
          (return nil))
        % Incoming registers have a distinguished value, IREG n, placed
        % in register n.  If this value remains, it has not been destroyed.
        (for (from i 1 narg& 1) 
             (do (when (member (&ireg i) (&regval (setq r (&mkreg i))))
                   (setq usedregs (delete r usedregs)))))
        (when (null usedregs)
          (setq usedregs '((reg 1))))
        (when *installdestroy
          (put name& 'destroys usedregs))
        (when *showdest
          (prin2 name&)
          (prin2 " DESTROYS ")
          (prin2t usedregs))))

(de &ireg (n)
  % returns form ('IREG n)
  % Generates initial VALUES for REGISTERs to see if they are changed
  % changed by compialtion. Support for INSTALLDESTROY
  %/ Use of vector for efficiency, or for UNIQUE forms?
  (if (and (greaterp n 0) (leq n 15))
    (getv '[nil (ireg 1) (ireg 2) (ireg 3) (ireg 4) (ireg 5) (ireg 6) 
            (ireg 7) (ireg 8) (ireg 9) (ireg 10) (ireg 11) (ireg 12) 
            (ireg 13) (ireg 14) (ireg 15)]
          n)
    (list 'ireg n)))


%************************************************************
%      True Pass 2					    *
%************************************************************
(de &pass2 (exp)
  % scs
  % Initialize STATUS!&=1  (Top level)
  % 1 means want value
  % 2 means no value necessary
  % 3 means inside PROG, want value from RETURN but not from sequential exp's
  % 4 means inside PROG, no RETURN value necessary
  (&comval exp 1))

(de &comval (exp status&)
  % Compile EXP.  Special cases: if STATUS!&>1 (compiling for side effects),
  % anyreg functions are ignored since they have no side effects.
  % Otherwise, top level ANYREG stuff is factored out and done via a LOAD
  % instead of a LINK.
  (cond ((&anyreg exp) (if (greaterp status& 1)
           (progn
             (unless (member (car exp) '(quote $local $fluid))
               (&compwarn 
                (list "Value of" exp "not used, therefore not compiled")))
             nil)
           (&lreg1 exp)))
        % Just a LOAD
        % When not all ANYREG
        ((&anyregfnp exp) % Is the top level an ANYREG fn?
         (if (greaterp status& 1)
           (progn
             (&comval (cadr exp) status&)
             (&compwarn (list "Top level" (car exp) "in" exp 
                         "not used, therefore not compiled"))
             nil)
           (&comexp '(reg 1) exp)))
        % Preserve the anyreg fn
        (t (&comval1 exp stomap& status&)) % no anyregs in sight
	))

(de &comval1 (exp stomap& status&)

  % Generate code which loads the value of EXP into register 1
  %/ examine Patch to COMVAL1 for better register allocation

  (cond ((or (&anyreg exp) (&openfnp exp) (&anyregfnp exp)) 
         (cond ((and (greaterp status& 1) (&nosideeffectp exp)) %   scs
                (&compwarn (list exp " not compiled")))
               (t (&comexp (if (greaterp status& 1)
                     (&alloctemp exp)
                     '(reg 1)) exp))))

        ((not (atom (car exp))) % Non atomic function?
         (if (eq (caar exp) 'lambda)
           (&comply (car exp) (cdr exp) status&) % LAMBDA compilation
           (&comperror (list (car exp) "Invalid as function")))) %  Should be noticed in pass 1

        % Dispatch built in compiler functions
        ((get (car exp) 'compfn) (&special-comp-function exp status&))

        ((eq (car exp) 'lambda) 
         (&comperror (list "Invalid use of LAMBDA in COMVAL1" exp)))

        (t (&call (car exp) (cdr exp) status&)))  % Call a function

  nil)


(de &alloctemp (exp)
  % Allocate a temporary REG for OPEN exprs.
  % Uses PREGS& to keep track
  % Used only when STATUS!&>1 to
  % set up destination.  Only special case is SETQ.  SETQ tries to put the
  % value of X:=... into a register containing X (keeps variables in the same
  % register if possible.
  (cond ((equal (car exp) 'setq) 
         (cond ((equal (car (caddr exp)) 'setq) % Nested setq - move to actual RHS
                (&alloctemp (caddr exp)))
               (t (prog (reg)
                        (cond % LHS variable already in reg?
                              ((and 
                                (setq reg 
                                 (&rassoc (cadr (cadr exp)) regs&))
                                (not (member (car reg) pregs&)))
                               % and reg must be available
                               (return (car reg)))
                              (t % Return the reg previously used for the var
                               (return (&tempreg))))))))
        (t % Just get a temp
           (&tempreg))))

% not SETQ - any old temp will do
(de &call (fn args status&)
  % Issues instructions for Standard CALL on procedure, compiles
  % arguments to egisters 1..N
  (prog (dest& argno)
        (setq argno (length args))
        (if (&anyregp fn)
          (&comexp '(reg 1) (cons fn args))
          (progn
            (&comload args)
            (&attach (list '*link fn (&cfntype fn) argno))
            (&remmrefs)
            (&remvrefs)
            % Default - all registers destroyed
            (when *usingdestroy
              (setq dest& (get fn 'destroys)))
            (if (null dest&)
              (setq regs& nil)
              (prog (temp)
                    (setq temp nil)
                    (foreach r in regs& do (unless (member (car r) dest&)
                       (setq temp (cons r temp))))
                    (setq regs& temp)))))))

(de &comlis (exp)
  % COMLIS  returns LIST of "locations" of compiled arguments
  (reversip (&comlis1 exp)))

(de &comlis1 (exp)
  % Support for COMLIS, returns reversed list of compiled arguments;
  % Gathers a set of ANYREG expressions denoting
  % the params.  Code for non ANYREG stuff is emitted by ATTACH.  ACUSED is
  % name of psuedo variable holding results of non anyreg stuff.
  %/ See <griss> code to fix an ORD bug. Need to check SIDE-EFFECTS
  %/ more stringently
  (prog (acused y)
    (setq y nil)
    (while exp
      (cond ((or (&constp (car exp)) 
		 (and (&openp (car exp)) 
                      (or (not *ord) (&nosideeffectpl (cdr exp)))))
	     (setq y (cons (car exp) y)))
	    % Anyreg stuff is handled later.  Anyreg args are not loaded until after
	    % all others.
	    % If !*ORD is true, order is still switched unless no side effects
	    (t %/  Special coding for top level ANYREG
	     (cond ((and 
		     (or (&anyregfnp (car exp)) (&openfnp (car exp))) 
		     (or (not *ord) (&nosideeffectpl (cdr exp))))
		    (setq y 
		      (cons (cons (caar exp) (&comlis (cdar exp))) y)))
		   % Emit code to place arg in R1, generate a name for the result to put in R1
		   (t (&comval (car exp) 1) %    scs
		      (setq acused (list '$local (&gensym))) 
		      (setq regs& 
			(&addrvals '(reg 1) regs& (list acused)))
		      % REGS!& the new variable name goes on the code list (rest already emitted)
		      (setq y (cons acused y))))
	     (&saver1) %                scs
	     ))        % place arg in memory while doing others
      (setq exp (cdr exp)))
    (return y)))

(de &saver1 ()
  % Marks contents of REG 1 for storage.
  % Will allocate a FRAME location for ($LOCAL ) if needed
  (prog (x)
        (setq x (&regval '(reg 1)))
        % Contents of R1 
        (cond ((or (null x) (not (&varp (car x)))) (return nil))
              % Dont save constants
              ((not (assoc (car x) stomap&)) (&frame (car x))))
        % For temporaries
        % as generated in COMLIS
        (&storelocal (car x) '(reg 1))))

% Emit a store
(de &comply (fn args status&)
  % COMPFN: Compile LAMBDA expression.
  %/ Exists a bug and inefficiency. See <griss> files that
  %/ fix this.
  % SHouldnt just LOADARGs, should behave as some sort of PROG
  % hm: rebinding golist& to itself to enable jump out of a lambda form.
  (let (oldstomap oldcode alsts& (golist& golist&) vars n i )
        %     scs
        (setq vars (cadr fn))
        % Compile args to the lambda
        (setq n (length args))
        (when (greaterp n maxnargs&)
          (&comperror (list "Too many arguments in LAMBDA form" fn)))
        % Put the args into registers
        (&comload args)
        %  scs
        % Enter new ENVIRONMENT!&
        (setq args (&remvarl vars))
        % The stores that were protected;
        (setq oldstomap stomap&)
        %     scs
        (setq oldcode codelist&)
        %     scs
        (setq i 1)
        % Put this junk on the frame
        (setq alsts& (&varbind vars t))
        % hm
        (when alsts& (push (cons '&freerstr alsts&) golist&))
        %Old fluid values saved;
        % compile the body
        (&comval (caddr fn) status&)
        % Restore old fluids
        (&freerstr alsts& status&)
        % Go back to the old ENVIRONMENT!&
        (&fixfrm oldstomap oldcode) 
        %  let's see this work      scs
        (&rstvarl vars args)))

(de &loadargs (args status& dummy) % used to have 3 args 
  % Load a sequence of expressions into the registers
  % for CALL, COMPLY etc. Use after call on COMLIS1,
  % args are "ANYREG/OPEN" expressions in reverse order
  (prog (fn destreg& n)
        (setq n (length args))
        (when (greaterp n maxnargs&)
          (&comperror (list "Too many arguments" args)))
        (while args
          % Generate a load for each arg
          (progn
            (setq destreg& (&mkreg n))
            (&loadopenexp destreg& (car args) status& pregs&)
            (setq pregs& (cons destreg& pregs&))
            (setq n (difference n 1))
            (setq args (cdr args))))))

(de &comload (args)
  (let  (oldstomap oldcode (pregs& pregs&))
        (setq oldstomap stomap&)
        (setq oldcode codelist&)
        (&loadargs (&comlis1 args) 1 pregs&)
        %Emits loads to registers
        (&cleartemps oldstomap oldcode)))

(de &comexp (reg exp)
  (prog (oldstomap oldcode)
        (setq oldstomap stomap&)
        (setq oldcode codelist&)
        (&loadopenexp reg (cons (car exp) (&comlis (cdr exp))) status& 
                      pregs&)
        (&cleartemps oldstomap oldcode)))

(de &cleartemps (oldstomap oldcode)
  (when (neq oldstomap stomap&)
    (while (ne stomap& oldstomap)
      (&clrstr (caar stomap&))
      (setq stomap& (cdr stomap&)))
    (&fixfrm oldstomap oldcode)))

(de &lreg1 (x)
  % Load register 1 with X
  (&loadopenexp '(reg 1) x 1 pregs&))

% 1?    scs
(de &loadopenexp (destreg& arg status& pregs&)
  % FORCES LOADOPENEXP1 TO LOAD INTO DESTREG                           scs
  % (cond ((or (&ANYREG ARG) (&RAssoc ARG Regs&)) (&LREG DESTREG (&LOCATE ARG)))
  %       (t (PROG (DEST) 
  %	    (Setq DEST (&LOADOPENEXP1 DESTREG ARG STATUS PREGS PREGS)) 
  %	    (cond ((LESSP STATUS 2) (&LREG DESTREG DEST)))))
  %       )
  (prog (dest)
        (setq dest (&argloc arg))
        (when (lessp status& 2)
          (&lreg destreg& (&locate dest)))))

(de &loadopenexp1 (destreg& arg status& gpregs& pregs&)
  % RETURNS DESTREG!&, WHICH MAY BE MODIFIED BY CALLOPEN IF STATUS>0   scs 
  % Generates code to load an OPEN/or ANYREG expression into
  % the target register. Uses OPEN and ANYREG tables
  %/ Some bug relating to reusing a register before issuing store,
  %/ lose in &LOCATE. See <griss>partial fixes
  (prog (r)
        (cond %   ((&ANYREGFNP ARG)                                    I think this is dead
              %    (progn (&LOADOPENEXP DESTREG& (Cadr ARG) 1 PRegs&) 	%  1? scs
              %       (&LREG DESTREG& (&LOCATE (CONS (car ARG) (CONS DESTREG& (cddr ARG))))))) 
              (t %  Must be an open function
                 (prog (opfn adjfn anyregargs)
                       (setq anyregargs (&remopen destreg& (cdr arg) 1))
                       (setq opfn (get (car arg) 'openfn))
                       (if (idp opfn)
                         (apply opfn (list destreg& anyregargs arg))
                         (setq destreg& 
                          (&callopen opfn destreg& anyregargs (car arg)))))))
        (return destreg&)))

(de &remopen (destreg& args status&)
  %? Returns a LIST of ARGUMENT locations (ARGLOCs)
  (foreach arg in args collect (&argloc arg)))

(de &argloc (arg)
  % Returns a STORE or LHS form for argument
  % Also marks REG in use on PREGS for safety in TempAlloc
  (prog (loc dstreg)
	(when (and (eqcar arg 'QUOTE)
		   (fixp (cadr arg))
		   (leq (abs (cadr arg)) bitsperword))
	      (return arg))
	(cond ((eqcar arg '$name) %       (setq ARG (cadr ARG))
	       (cond ((eqcar (cadr arg) '$local) (return arg))
		     %   yuck
		     (t (setq arg (cadr arg)))))
	      (t (when (setq loc (&rassoc arg regs&))
		   (setq pregs& (cons (car loc) pregs&))
		   (return (car loc)))))
	(when (&constp arg) (return arg))
	(when (&anyreg arg) (return arg))
        (when (or (null destreg&) (member destreg& pregs&))
          (setq destreg& (&tempreg)))
        (setq dstreg (&loadopenexp1 destreg& arg status& pregs& pregs&))
        (if (registerp dstreg)
          (setq pregs& (cons dstreg pregs&))
          (&protectargregs (cdr dstreg)))
        (return dstreg)))

(de &protectargregs (exp)
  % PROTECT ALL THE REGISTERS IN EXPRESSON    scs
  (when exp
    (let ((e (car exp)))
      (cond ((registerp e) 
	     (setq pregs& (cons e pregs&)))
	    ((null (pairp e)) nil)    %/MLG
	    ((eq (car e) 'quote) nil) %/MLG
	    (t (&protectargregs (cdr e)))) %/MLG
      (&protectargregs (cdr exp))
      )))

(de &callopen (opfn dest& args op)
  %  RETURNS DEST!&, WHICH MAY BE MODIFIED BY MACRO PATTERN           scs
  %% OPFN is e.g. (ASSOCPAT *WPLUS2)
  %% DEST& (fluid) is e.g. (reg 1), a destination location
  %% ARGS is e.g. ((reg 1) (reg 2)), specifying locations of args
  %% OP is e.g. WPLUS2, apparently the LISP operator name. /csp
  %? Basic OPENFN pattern matcher
  %? Issues code to CALL expression that compiles open.
  %? Uses Pattern Tables to check register usage.
  %? Does Local REGISTER allocation
  %? Setup new ENVIRONMENT for generated temps
  (prog (pats params adjfn regfn environment&)
        (setq pats (car opfn))
        % E.g. ASSOCPAT /csp
        (when (idp pats)
          (setq pats (get pats 'pattern)))
        (setq params (cons op (cdr opfn)))
        % I.e. (<lisp fn> <cmacro name>) /csp
        (setq adjfn (car pats))
        (setq regfn (cadr pats))
        % I.e. ('*SET ... ) ('*DO ... ), etc. /csp
        (when adjfn
          (setq args (apply adjfn (list args))))
        (setq pats (cddr pats))
        % ((<pattern> . <cmacros) . . . ) /csp
        (while (and (not (null pats)) (not (&matches (caar pats) args)))
          (setq pats (cdr pats)))
        (when (null pats)
          (&comperror (list "Compiler bug - no pattern for" (cons op args)))
          (return nil))
        %% (CAR PATS) matched present situation.  Substitute first arg for A1,
        %% second for A2, CMACRO name for MAC, etc. in CMACROS in pattern. /csp
        (foreach mac in (cdar pats) do 
                 (&emitmac (&subargs mac args params)))
        %% Generally used to fix up REGS& database to reflect what has happened as
        %% part of "execution" of this operation. /csp
        (when regfn
          (if (idp regfn)
            (apply regfn (list op args))
            (&emitmac (&subargs regfn args params))))
        (return dest&)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Basic CALLOPEN Pattern Matching and Substitution functions
%%% &MATCHES is the pattern matcher for the pattern - cmacro mapping tables
%%% used by CALLOPEN.
(de &matches (pat subj)
  % Recursive matcher. 
  %? Cases handled are: ?
  (cond ((eqcar pat 'quote) (equal (cadr pat) subj))
        ((null pat) (null subj))
        ((eqcar pat 'noval) 
         (and (greaterp status& 1) (&matches (cdr pat) subj)))
        ((atom pat) (apply (get pat 'matchfn) (list subj)))
        (t (and (pairp pat) 
                (cond ((pairp subj) %   scs
                       (and (&matches (car pat) (car subj)) 
                        (&matches (cdr pat) (cdr subj))))
                      (t (and (&matches (car pat) nil) 
                          (&matches (cdr pat) nil))))))))

(de &any (u)
  t)

% Always TRUE
(de &dest (u)
  % Checks if U is the DEST& register
  (equal u dest&))

(de &usesdest (u)
  % Indicates an anyreg which uses DEST!& at any level
  % for Reservation of REGS?
  (or (&dest u) (and (pairp u) (&usesdestl (cdr u)))))

(de &usesdestl (u)
  % Support for USESDEST
  (and (pairp u) 
       (or (&dest (car u)) (&usesdest (car u)) (&usesdestl (cdr u)))))

(de &regfp (u)
  (or %? Check if U is a REG or LOCAL
      (&regp u) (eqcar u '$local)))

(de &regn (u)
  (or %? Check if U is REG or LOCAL or NIL
      (&regp u) (eqcar u '$local) (equal u ''nil)))

(de &mem (u)
  %? Check if can store into U
  (and (not (or (equal u ''nil) (eqcar u '$local))) 
       (or (&constp u) (&varp u) (equal (car u) 'memory))))

(de &notanyreg (u)
  %? Check if CANT use as an anyreg
  (or (&mem u) (&regfp u)))

(de &regnp (r)
  (and (registerp r) (not (member r gpregs&))))

(de &typeregnp (r regkindp)
  (and (apply regkindp (list r)) (&regnp r)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Pattern substitution functions used in CALLOPEN /csp
(de &subargs (mac args params)
  % Substitute into each element of MAC /csp
  (foreach arg in mac collect (&subarg arg args params)))

(de &subarg (arg args params)
  % Basic substituter.  ARG is substituted into.  ARGS is list of expressions
  % for actual operands for CMACROs as passed to &CALLOPEN.  PARAMS is list of
  % LISP and CMACRO operator names, respectively, to substitute for FN and
  % MAC. /csp
  (prog (argfn)
        (return (cond ((eqcar arg 'quote) (cadr arg))
                      ((pairp arg) (&subargs arg args params))
                      ((equal arg 'dest) dest&)
                      ((setq argfn (get arg 'substfn)) 
                       (apply argfn (list arg args params)))
                      (t (&comperror 
                          (list "Compiler bug" arg "invalid in macro")))))))

%% Popular (all?) SUBSTFNs for use by &SUBARG.  Trivial except for ones that
%% get temps. /csp
(de &arg1 (arg args params)
  % LOCATE ARG1 for OPEN funs
  (&locate (car args)))

(de &arg2 (arg args params)
  % LOCATE ARG2 for OPEN funs
  (&locate (cadr args)))

(de &arg3 (arg args params)
  % LOCATE ARG3 for OPEN funs
  (&locate (caddr args)))

(de &arg4 (arg args params)
  % LOCATE ARG4 for OPEN funs
  (&locate (cadddr args)))

(de &param1 (arg args params)
  % Reference PARAM1 for OPEN funs
  (car params))

(de &param2 (arg args params)
  % Reference PARAM2 for OPEN funs
  (cadr params))

(de &negparam2 (arg args params)
  % Reference the NEGATIVE JUMP for PARAM2 of OPEN tests
  (get (cadr params) 'negjmp))

(de &param3 (arg args params)
  % Reference PARAM3 for OPEN funs
  (caddr params))

(de &param4 (arg args params)
  % Reference PARAM4 for OPEN funs
  (cadddr params))

(de &gettemp (tname args params)
  %  scs
  % Allocate a new TEMPREG, and store name/value in ENVIRONMENT
  (&gettypetemp tname args params '&any))

(de &gettypetemp (tname args params regkindp)
  %  scs
  (prog (tn)
        (return (if (setq tn (assoc tname environment&))
                  (cdr tn)
                  (progn
                    (setq tn (&temptypereg regkindp))
                    (setq environment& (cons (cons tname tn) environment&))
                    (setq pregs& (cons tn pregs&))
                    tn)))))

(de &gettemplbl (lname args params)
  % Allocate a new TEMPLBL, and store name/value in ENVIRONMENT
  (prog (lab)
        (return (if (setq lab (assoc lname environment&))
                  (cdr lab)
                  (progn
                    (setq lab (&genlbl))
                    (setq environment& 
                     (cons (cons lname lab) environment&))
                    lab)))))

%%% End of substituter.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
(de &gensym ()
  % gensym local to compiler, reuses symbols
  % on LOCALGENSYM list
  (prog (symb)
        (when (null (cdr localgensym&))
          (rplacd localgensym& (list (gensym))))
        (setq symb (car localgensym&))
        (setq localgensym& (cdr localgensym&))
        (return symb)))

(de &comperror (u)
  % General COMPILER Error message
  %? Maybe should CALL THROW, rather than just setting ERFG!*
  %? Or maybe ERFG!* collects errors for end?
  (progn
    (stderror (bldmsg "Compiler: in %P: %L" name& u))
    (setq erfg* t)))

(de &compwarn (u)
  % General Compiler WARNING message
  % not as error
  (and *msg (errorprintf "*** in %P: %L" name& u)))

(de &emitmac (mac)
  %% Seems to serve 2 quite different purposes.  For ordinary CMACROS, just
  %% attaches its argument to the codelist, using &ATTACH.
  %% For *SET, etc., updates REGS& database to reflect new value in some
  %% register. /csp
  % Support function for CALLOPEN,
  % After Pattern match, emit form
  % clear destroyed regs, etc.
  (prog (emitfn)
        (cond ((equal (car mac) '*do) (apply (cadr mac) (cddr mac)))
              ((equal (car mac) '*destroy) %% Register now contains nothing of interest /csp
               (foreach reg in (cdr mac) do 
                        (setq regs& (delasc reg regs&))))
              ((equal (car mac) '*set) %% Compute all "expressions" whose value one might want to consider as
               %% being in the register, enter them them into database with register.
               %% See defn. of &REMREGSL for details. /csp
               (setq regs& 
                     (&repasc (cadr mac) (&remregsl (caddr mac)) regs&)))
              ((setq emitfn (get (car mac) 'emitfn)) 
               (apply emitfn (list mac)))
              (t (&attach mac)))))

(de &emitload (m)
  % Open support, emit a LOAD
  (&lreg (cadr m) (caddr m)))

(de &emitstore (m)
  % Open support, EMIT a STORE
  (&storevar (caddr m) (cadr m)))

(de &emitjump (m)
  % Open support, emit a jump
  (&attjmp (cadr m)))

(de &emitlbl (m)
  % Open support, emit a label
  (&attlbl (cadr m)))

(de &emitmemmod (m)
  % open support, emit a memory modifying instruction
  % will update SLST and REGS& since changed state
  (prog (y x)
        (setq x (cadr m))
        (&remrefs x)
        (when (eqcar x '$local)
          (&refstore x))
        %   scs   assumes $NAME  
        (when (eqcar x '$local)
          (setq m (cons (car m) (cons (&getfrm x) (cddr m)))))
        (&attach (cons (get (car m) 'unmemmod) (cdr m)))))

(de &uses (m)
  % PROTECTS A REGISTER WHICH WILL BE NEEDED LATER                 scs
  (setq pregs& (cons (cadr m) pregs&)))

(de &return (m)
  % INDICATES WHERE THE VALUE OF THE OPEN CODED FUNCTION IS        scs
  (setq dest& (cadr m)))

(de &noanyreg (args)
  % Support to patterns - register adjustment functions
  % remove all ANYREG stuff except top level MEMORY
  (if (null args)
    nil
    (cons (&noanyreg1 (car args)) (&noanyreg (cdr args)))))

(de &noanyreg1 (arg)
  % Support to NOANYREG
  (if (and (&anyregfnp arg) (not (eqcar arg 'memory)))
    (&loadtempreg arg)
    arg))

(de &inreg (args)
  %? Check if in regs; ensure that loaded?
  (if (not (&regfp (car args)))
    (list (&loadtempreg (car args)))
    args))

(de &regmem (args)
  %? Check if in REG or MEM/ensure that is loaded?
  (progn
    (setq args (&noanyreg args))
    (if (and (&mem (car args)) (pairp (cdr args)) (&mem (cadr args)))
      (cons (&loadtempreg (car args)) (cdr args))
      args)))

(de &destmem (args)
  % A1 in DEST!&, A2 in MEM, rest (if any) not anyreg
  (progn
    (setq args (cons (car args) (&noanyreg (cdr args))))
    (cond ((greaterp status& 1) (if (&regfp (car args))
             args
             (cons (&loadtempreg (car args)) (cdr args))))
          ((or (&dest (cadr args)) (&usesdest (cadr args))) 
           (&destmem (cons (car args) 
                      (cons (&loadtempreg (cadr args)) (cddr args)))))
          ((neq (car args) dest&) (&lreg dest& (&locate (car args))) 
           (cons dest& (cdr args)))
          (t args))))

(de &destmema (args)
  % put either a1or A2 into DEST!&, the other to MEM.
  (cond ((equal (car args) dest&) % A1 = DEST!&, make A1 mem or reg
         (if (and (&notanyreg (cadr args)) (not (&usesdest (cadr args))))
           args
           (&loadtemp2 args)))
        ((equal (cadr args) dest&) % A2 = DEST!&, make A2 mem or reg
         (if (and (&notanyreg (car args)) (not (&usesdest (car args))))
           args
           (&loadtemp1 args)))
        ((or (&notanyreg (cadr args)) (not (&notanyreg (car args)))) % A2 is MEM or A1 is anyreg: make A1 the destination
         (progn
           (when (or (not (&notanyreg (cadr args))) 
                     (&usesdest (cadr args)))
             (setq args (&loadtemp2 args)))
           (&lreg dest& (&locate (car args)))
           (cons dest& (cdr args))))
        (t % Make A2 the DEST!& - only when A2 is anyreg and a1 is mem
           (progn
             (when (or (not (&notanyreg (car args))) 
                       (&usesdest (car args)))
               (setq args (&loadtemp1 args)))
             (&lreg dest& (&locate (cadr args)))
             (list (car args) dest&)))))

(de &loadtemp1 (u)
  % Bring first arg into a temp
  (cons (&loadtempreg (car u)) (cdr u)))

(de &loadtemp2 (u)
  % put second arg in a temp
  (cons (car u) (cons (&loadtempreg (cadr u)) (cddr u))))

(de &consargs (args)
  %? Reassemble arguments, may need temp
  (if (or (and (not (&anyregfnp (cadr args))) (neq (cadr args) dest&)) 
          (and (not (&anyregfnp (car args))) (neq (car args) dest&)))
    args
    (list (car args) (&loadtempreg (cadr args)))))

(de &loadtempreg (arg)
  % Load ARG into a temporary register.  Return the register.
  (prog (temp)
        (setq temp (&tempreg))
        (setq pregs& (cons temp pregs&))
        (&lreg temp (&locate arg))
        (return temp)))

(de &fixregtest (op args)
  % Fixes up the registers after a conditional jump has been emitted.
  % For JUMPEQ and JUMPNE, equalities can be assumed in REGS!& or REGS1!&
  % For other jumps, REGS!& copied onto REGS1!&.
  (&fixregtest1 op (first args) (second args)))

(de &fixregtest1 (op a1 a2)
  % Support for FIXREGTEST
  (progn
    (setq regs1& regs&)
    (when (or (equal op 'eq) (equal op 'ne))
      (if (not (&regp a1))
        (progn
          (when (&regp a2)
            (&fixregtest1 op a2 a1)))
        (progn
          (if (equal op 'eq)
            (setq regs1& (&addrvals a1 regs1& (&remregs a2)))
            (setq regs& (&addrvals a1 regs& (&remregs a2)))))))))

(de &setregs1 (op args)
  % Saves REGS& in REGS!& for COND branches
  (setq regs1& regs&))

(de &locate (arg)
  %   scs
  (cond ((eqcar arg '$name) (cadr arg))
        %   yuck
        ((eqcar arg '$local) (&refstore arg) %  scs
         (cadr (assoc arg stomap&)))
        (t arg)))

(commentoutcode (de &locate (x)
                  %  scs 
                  % Find the location of a variable
                  % ie. an ANYREG expression that can be directly loaded
                  % Checks for: Const, $NAME, MEMORY,REG,ANYREG, FRAME
                  %             updates SLST if LOCAl (ie, "needed")
                  (prog (y vtype)
                        % Constants are their own location
                        (when (or (atom x) (eqcar x 'label) (&constp x))
                          (return x))
                        (when (eqcar x '$name)
                          (return (cadr x)))
                        (when (equal (car x) 'memory)
                          (return 
                           (cons (car x) 
                            (cons (&locate (cadr x)) (&locate (cddr x))))))
                        %  scs
                        (when (setq y (&rassoc x regs&))
                          (return (car y)))
                        % If in a register, return the register number
                        % Registers are their own location
                        % For ANYREG stuff, locate each constant 
                        (when (&anyregfnp x)
                          (return (cons (car x) (&locatel (cdr x)))))
                        (unless (eqcar x '$local)
                          (return x))
                        % Since the value of the variable has been referenced, a previous store was
                        % justified, so it can be removed from SLST!&
                        % Must be in the frame, otherwise make nonlocal (really ought to be an error)
                        % Frame location (<=0) is returned
                        (&refstore x)
                        %  scs
                        (when (setq y (assoc x stomap&))
                          (return (cadr y)))
                        % Nasty compiler bug.  Until we fix it, tell the user to simplify expressions
                        (&comperror 
                         (list 
                          "Compiler bug: expression too complicated, please simplify"
                          x))
                        (&comperror 
                         (list " Length CodeLIST " (length codelist&)))
                        (return ''verycomplexexpression)))
                % just so it doesn't blow up and can be seen
                (de &locatel (u)
                  % Locate a LIST of values
                  (foreach x in u collect (&locate x))))

(de &sameval (reg val actualval)
  (or (equal reg val) 
      (prog (regval)
            (when (setq regval (&regval reg))
              (return (while actualval
                        (when (member (car actualval) regval)
                          (return 't))
                        (setq actualval (cdr actualval))))))))

(de &lreg (reg val)
  % PARTIAL BUG FIX, &REMREGS RETURNS A LIST SO MUST TAKE CAR OF ACTUALVAL scs
  % Load register REG with value U. V (always NIL except when called from
  % LOADARGS) is a list of other loads to be done.
  % Adjust REGS&, issue MOVE if needed
  (prog (actualval)
        (when (&sameval reg val (setq actualval (&remregs val)))
          (return nil))
        (&attach (list '*move val reg))
        (setq regs& (&repasc reg actualval regs&))))

(de &jumpt (lab)
  % Emit a JUMPT
  (&attach (list '*jumpnoteq lab '(reg 1) ''nil)))

(de &jumpnil (lab)
  % EMit a JUMPN
  (&attach (list '*jumpeq lab '(reg 1) ''nil)))

%---------- Functions for Handling Non-local Variable Binding ----
(de &varbind (vars lambp)
  % bind FLUID variables in lambda or prog lists;
  % LAMBP is true for LAMBDA, false for PROG;
  (prog (i vlocs vnames fregs y reg tail)
        (setq i 1)
        (foreach x in vars do (progn
                   (setq reg (&mkreg i))
                   (cond ((eqcar x '$global) % whoops
                          (progn
                            (&compwarn 
                             (list "Illegal to bind global" (cadr x) 
                              "but binding anyway"))
                            (rplaca x '$fluid))))
                   % cheat a little
                   (cond ((eqcar x '$fluid) (setq freebound& t) 
                          (setq vnames (cons x vnames)) (unless *noframefluid
                            (setq vlocs (cons (&frame x) vlocs)))
                          (setq fregs (cons reg fregs)))
                         ((eqcar x '$local) (&frame x) 
                          (&storelocal x (if lambp
                             reg
                             nil)))
                         (t 
                          (&comperror 
                           (list "Cannot bind non-local variable" x))))
                   (when lambp
                     (if (eqcar x '$local)
                       (setq regs& (&repasc reg (list x) regs&))
                       (setq regs& (&repasc reg nil regs&))))
                   (setq i (plus i 1))))
        (when (null vnames)
          (return nil))
        (setq vnames (cons 'nonlocalvars vnames))
        (setq fregs (cons 'registers fregs))
        (setq vlocs (cons 'frames vlocs))
        (setq tail (if *noframefluid
                (list vnames)
                (list vnames vlocs)))
        (if lambp
          (&attach (cons '*lambind (cons fregs tail)))
          (&attach (cons '*progbind tail)))
        (when *unsafebinder
          (setq regs& nil))
        (return tail)))

(de &freerstr (alsts& status&)
  % restores FLUID variables  % why STATUS& ?  scs
  (when alsts&
    (&attach (cons '*freerstr alsts&))
    (when *unsafebinder
      (setq regs& nil))))

(de &attach (u)
  % ATTACH is used to emit code
  (setq codelist& (cons u codelist&)))

(de &storelocal (u reg)
  % marks expression U in register REG for storage
  % setting SLST and removing  unneeded stores from SLST
  (prog (x)
        (when (null reg)
          (setq reg ''nil))
        (setq x (list '*move reg (&getfrm u)))
        % Update list of stores done so far
        (&attach x)
        % Zap out earlier stores if there were never picked up
        % ie, if you store to X, then a ref to X will remove this store from
        % SLST!&.  Otherwise, the previous store will be removed by CLRSTR
        % SLST!& is for variables only (anything else?)
        (&clrstr u)
        (setq slst& (cons (cons u codelist&) slst&))))

(de &clrstr (var)
  % removes unneeded stores remembered on SLST
  % and removes the MOVE etc from CODELIST
  (prog (x sl)
        (setq sl slst&)
        (while sl
          (cond ((equal (car (setq x (car sl))) var) (rplaca x nil) % SLST!& := DelQIP(X,SLST!&);  scs
                 (&delmac (cdr x)))
                ((equal (car x) 'branch) (return nil)))
          (setq sl (cdr sl)))))

(de &refstore (var)
  (prog (x sl)
        (setq sl slst&)
        (while sl
          (when (equal (car (setq x (car sl))) var)
            (rplaca x nil))
          %   SLST!& := DELETIP(Y,SLST!&);         scs
          (setq sl (cdr sl)))))

%----------------- Functions for general tests --------------------
(de &comtst (exp labl)
  % compiles boolean expression EXP.
  % If EXP has the same value as SWITCH!& then branch to LABL,
  % otherwise fall through;
  % REGS& are active registers for fall through,
  % REGS1& for branch;

  (prog (x fn reg)

    % First factor out NOT's to set up the SWITCH!&
    (while (and (eqcar exp 'eq) (equal (caddr exp) ''nil))
      (setq switch& (not switch&))
      (setq exp (cadr exp)))

    % SWITCH!& is assumed to be true by fn's with
    % a flip test
    (when (and (not switch&) (setq fn (get (car exp) 'fliptst)))
      (setq exp (cons fn (cdr exp))))

    % Dispatch a built in compiling function
    (if (setq fn (get (car exp) 'opentst))
      (if (atom fn)
	(apply fn (list exp labl))
	(&comopentst fn exp labl pregs&))
      (if (eqcar exp 'quote)
	(progn
	  (setq regs1& regs&)
	  (when (or (and switch& (cadr exp)) 
		    (and (not switch&) (not (cadr exp))))
	    (&attjmp labl))
	  )
	(&comtst (list 'ne exp ''nil) labl)))))

(de &comopentst (pat exp destlab pregs&)
  %? Pattern match entru for OPENTST functions
  (prog (oldstomap oldcode)
        (setq oldstomap stomap&)
        (setq oldcode codelist&)
        (&callopen pat destlab (&remopen (&tempreg) (&comlis (cdr exp)) 1) 
                   (car exp))
        (&cleartemps oldstomap oldcode)))

(de &remvarl (vars)
  % Remove variables to avoid name conflicts:  Hide variable names which match
  % new names when entering an inner function.  Other names will be available
  % as global info.  VARS is the list of new variable names, the result is a
  % list of protected stores, ie (var . slst-entry)
  %? What about REGS contents
  % Support for nested environments and branches; ie
  % name of VAR used
  (foreach x in vars collect (&protect x)))

(de &protect (u)
  % WON'T HANDLE MULTIPLE INSTANCES
  % Support for REMVARL
  % Delete all references to U from SLST!&
  % return the protected store, to be put back later
  (prog (x)
        (&remrefs u)
        %  scs
        (return (when (setq x (assoc u slst&))
                  (rplaca x nil)
                  (cons u x)))))

%  scs
(de &rstvarl (vars lst)
  % Restore a previous set of names.  VARS is the list of variables taken out
  % of the SLST. LST is the list of protected stores.  One or zero
  % stores for each variable. 
  %/ What of REGS
  (while vars
    (&rstvar (car vars) (car lst))
    (setq vars (cdr vars))
    (setq lst (cdr lst))))

(de &rstvar (var val)
  % Support for RSTVARL
  % Restore a particular variable and STORE
  (prog nil
        (&remrefs var)
        % Remove new occurance from REGS
        (&clrstr var)
        % Flush from SLST, removing unneeded Stores
        % in cas
        % Put back old deferred stores  SLSTS
        (&unprotect val)))

(de &unprotect (val)
  %restores VAL to SLST!&;
  (when val
    (rplaca (cdr val) (car val))))

%             scs
(de &storevar (u v)
  % The store generated by a SETQ
  (prog (vtype x)
        (&remrefs u)
        (cond ((equal (car u) '$local) % assumes $NAME    
               (&storelocal u v))
              (t (&attach (list '*move v u))))
        (when (&regp v)
	  (setq regs& (&addrvals v regs& (&remregs u))))))
%%%%%      (setq regs& (&addrvals v regs& (list (&remregs u)))))))

%  scs
(de &references (exp var)
  % True if expression EXP (probably ANYREG) references VAR.
  (or (equal exp var) (if (or (atom exp) (flagp (car exp) 'terminal))
        nil
        (&referencesl (cdr exp) var))))

(de &referencesl (exp var)
  % Support for REFERENCES
  (if (null exp)
    nil
    (or (&references (car exp) var) (&referencesl (cdr exp) var))))

(de &cfntype (fn)
  % Look up the type of a function using its CFNTYPE property if
  % any.  Return EXPR by default.
  (prog (x)
        (return (cond ((setq x (get fn 'cfntype)) (car x))
                      ((setq x (getd fn)) (car x))
                      (t 'expr)))))

(de &genlbl ()
  % General an internal name for a temp label
  (prog (l)
        (setq l (list 'label (&gensym)))
        (setq lblist& (cons (list l) lblist&))
        (return l)))

(de &getlbl (labl)
  % Look up the Internal name of label in a prog
  (prog (x)
        (setq x (assoc labl golist&))
        (when (null x)
          (&comperror (list "Missing label" labl)))
        (return (cdr x))))

(de &attlbl (lbl)
  % Attach a label to codelist.
  % Handle the (!*LBL x) (!*LBL y) case by making y alias for x
  (if (eq (caar codelist&) '*lbl)
    (&defeqlbl lbl (cadr (car codelist&)))
    (&attach (list '*lbl lbl))))

(de &attjmp (lbl)
  % Attach a jump to codelist.
  % handle (JUMP l) (LBL l) case
  (prog nil
        (when (eq (caar codelist&) '*lbl)
          (&defeqlbl lbl (cadr (car codelist&)))
          (&delmac codelist&))
        (when (&transferp codelist&)
          (return nil))
        (&attach (list '*jump lbl))))

(de &transferp (x)
  % Check if previously emited CMACRO is an unconditional
  % transfer (jump or call).
  (if (equal (caar x) '*noop)
    (&transferp (cdr x))
    (flagp (if (eq (caar x) '*link)
             (cadar x)
             (caar x)) 'transfer)))

(de &defeqlbl (lab1 lab2)
  % Make labels LAB1 and LAB2 aliases for each other
  (setq lblist& (&defeqlbl1 lblist& lab1 lab2)))

(de &defeqlbl1 (labs lab1 lab2)
  % Support for DEFEQLBL
  (cond ((member lab1 (car labs)) (if (member lab2 (car labs))
           labs
           (cons (append (&labclass lab2) (car labs)) 
                 (&delclass lab2 (cdr labs)))))
        ((member lab2 (car labs)) 
         (cons (append (&labclass lab1) (car labs)) 
               (&delclass lab1 (cdr labs))))
        (t (cons (car labs) (&defeqlbl1 (cdr labs) lab1 lab2)))))

(de &labclass (lab)
  %? Compute label equivalence classes
  (prog (temp)
        (setq temp lblist&)
        (while (and temp (not (member lab (car temp))))
          (setq temp (cdr temp)))
        (return (if temp
                  (car temp)
                  nil))))

(de &delclass (lab labs)
  % Remove a label from an equivalence class
  (if (member lab (car labs))
    (cdr labs)
    (cons (car labs) (&delclass lab (cdr labs)))))

(de &lbleq (lab1 lab2)
  % Check if LAB1eq to LAB2 (in its equivalence class)
  (member lab1 (&labclass lab2)))

(de &frame (u)
  % allocates space for U in frame;
  %? How about reuse of STOMAP entries?
  %? on exit from LAMBDA/PROG, mark as free?
  (prog (z res)
        (setq z (if (null stomap&)
                1
                (plus 1 (cadr (cadar stomap&)))))
        (setq res (&mkframe z))
        (setq stomap& (cons (list u res) stomap&))
        (return res)))

(de &getfrm (u)
  % GETFRM returns the frame location of a local variable
  (prog (x)
        (when (setq x (assoc u stomap&))
          (return (cadr x)))
        (&comperror (list "Compiler bug: lost variable" u))))

%*************************************************************************
% The following functions determine classes or properties of expressions *
%*************************************************************************
(de &anyreg (u)
  % !&ANYREG determines if U is an ANYREG expression
  %
  % ANYREG expressions are those expressions which may be loaded into any
  % register without the use of (visable) temporary registers.  It is assumed
  % that ANYREG expressions have no side effects.
  %
  % ANYREG expressions are defined as constants, variables, and ANYREG functions
  % whose arguments are ANYREG expressions.  Note that ANYREG functions are
  % not necessarily a part of ANYREG expressions; their arguments may not be
  % ANYREG expressions.
  (or (&constp u) (&varp u) (and (&anyregfnp u) (&anyregl (cdr u)))))

(de &anyregl (u)
  (or % Are all expression in list U Anyreg
      (null u) (and (&anyreg (car u)) (&anyregl (cdr u)))))

(de &anyregfnp (u)
  % !&ANYREGFNP is true when U is an ANYREG function.  The arguments are not
  % checked
  (&anyregp (car u)))

(de &openp (u)
  % does U open compile?
  (or (&constp u) (&varp u) 
      (and (or (&anyregfnp u) (&openfnp u)) (&openpl (cdr u)))))

(de &openpl (u)
  % Do each expression in list U opencompile
  (or (null u) (and (&openp (car u)) (&openpl (cdr u)))))

(de &openfnp (u)
  % true if U is an OPENfn
  (get (car u) 'openfn))

(de &constp (u)
  % True if U is a constant expression
  (and (idp (car u)) (flagp (car u) 'const)))

(de &varp (u)
  % True if U is a variable: (LOCAL x),(FLUID x), ...
  (and (pairp u) (flagp (car u) 'var)))

(de &regp (u)
  % True if U is a Register expressions (REG and EXTRAREG?)
  (and (pairp u) (flagp (car u) 'reg)))

(de &nosideeffectp (u)
  % True if the expression U has no side effects.  ANYREG expressions and
  % functions are assumed to have no side effects; other functions must be
  % flagged NOSIDEEFFECT.  All arguments to a function must also be NOSIDEEFFECT.
  (or (&anyreg u) 
      (and (or (&anyregfnp u) (flagp (car u) 'nosideeffect)) 
           (&nosideeffectpl (cdr u)))))

(de &nosideeffectpl (u)
  % Support for LIST of NOSIDEEFFECTS
  (or (null u) (and (&nosideeffectp (car u)) (&nosideeffectpl (cdr u)))))

%**********************************************************************
%  Basic register manipulation utilities
%**********************************************************************
(de &rval (r rgs)
  % Return the set of values in register R as determined by register list RGS
  (cond ((null rgs) nil)
        ((equal (caar rgs) r) (cdar rgs))
        (t (&rval r (cdr rgs)))))

(de &regval (r)
  % Normally, register contents are found in register list REGS!&.
  (&rval r regs&))

(de &addrvals (reg rgs vals)
  % Add values VALS to contents of REG in register list RGS
  (cond ((null rgs) (list (cons reg vals)))
        ((equal (caar rgs) reg) 
         (cons (cons (caar rgs) (append vals (cdar rgs))) (cdr rgs)))
        (t (cons (car rgs) (&addrvals reg (cdr rgs) vals)))))

(de &mkreg (num)
  %  Generates a tagged register from a register number
  (prog (aentry)
        (return %/ use a vector?
                (if (setq aentry 
                     (assoc num 
                      '((1 reg 1) (2 reg 2) (3 reg 3) (4 reg 4) (5 reg 5) 
                        (6 reg 6) (7 reg 7) (8 reg 8) (9 reg 9))))
                  (cdr aentry)
                  (list 'reg num)))))

(de &mkframe (num)
  % Used to generate a tagged FRAME loc from a frame number
  (prog (aentry)
        (return %/ use a vector?
                (if (setq aentry 
                     (assoc num 
                      '((1 frame 1) (2 frame 2) (3 frame 3) (4 frame 4) 
                        (5 frame 5) (6 frame 6) (7 frame 7) (8 frame 8) 
                        (9 frame 9))))
                  (cdr aentry)
                  (list 'frame num)))))

(de &rassoc (val rgs)
  % Find a register in register list RGS which contains VAL.  NIL is returned if
  % VAL is not present in RGS
  (cond ((null rgs) nil)
        ((member val (cdar rgs)) (car rgs))
        (t (&rassoc val (cdr rgs)))))

(de &repasc (reg val regl)
  % Replace the contants of REG in list REGL by the value VAL
  (cond ((null regl) (list (cons reg val)))
        ((equal reg (caar regl)) (cons (cons reg val) (cdr regl)))
        (t (cons (car regl) (&repasc reg val (cdr regl))))))

(de &rmerge (u)
  % RMERGE takes a list of register contents representing the information
  % present in the registers from a number of different ways to reach the same
  % place.  RMERGE returns whatever information is known to be in the registers
  % regardless of which path was taken.
  (if (null u)
    nil
    (prog (res contents)
          (setq res nil)
          (foreach rg in (car u) do (progn
                     (setq contents nil)
                     (foreach thing in (cdr rg) do (when (&inall thing 
                                                          (car rg) (cdr u))
                        (setq contents (cons thing contents))))
                     (when contents
                       (setq res (cons (cons (car rg) contents) res)))))
          (return res))))

(de &inall (thing rg lst)
  % Support for RMERGE, check in all branches
  (or (null lst) 
      (and (member thing (&rval rg (car lst))) (&inall thing rg (cdr lst)))))

(de &tempreg ()
  %  scs
  % Allocate  Compiler TEMP reg for open compilation
  % PREGS& protects registers currently in use
  (&temptypereg '&any))

(de &temptypereg (regkindp)
  %  scs 
  (prog (i r empty unprot)
        (setq empty (setq unprot nil))
        (setq i 1)
        (while (and (leq i maxnargs&) (not empty))
          (setq r (&mkreg i))
          (when (and (apply regkindp (list r)) (not (member r pregs&)))
            (cond ((and (leq i lastactualreg&) (null (&regval r))) 
                   (setq empty r))
                  ((not unprot) (setq unprot r))))
          (setq i (plus i 1)))
        (when empty
          (return empty))
        (when unprot
          (return unprot))
        (&comperror "Compiler bug: Not enough registers")
        (return '(reg error))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Mostly functions to get lists of expressions equivalent to some
%%% potential CMACRO argument. /csp
(de &remregs (u)
  %% Given one expression (suitable for CMACRO operand), returns list of
  %% alternative expressions equivalent to it.  Weird name.  I don't
  %% understand the final "else" case. /csp
  (cond ((&regp u) (&regval u))
        ((eqcar u 'frame) (list (&getfvar u stomap&)))
        ((or (&constp u) (&varp u)) (list u))
        (t (&remregsl u))))

(de &getfvar (v smap)
  %% From database in the form ((<a> <b> ... ) . . . ) retrieves the <a> from
  %% the first element whose <b> matches V in SMAP.  In the  (typical?) case
  %% where SMAP is STOMAP&, gets ($LOCAL <name>) from (FRAME <n>). /csp
  (cond ((null smap) (&comperror (list "Compiler bug:" v "evaporated?")))
        ((equal (cadar smap) v) (caar smap))
        (t (&getfvar v (cdr smap)))))

(de &remregsl (u)
  %% U is a CMACRO such as (*WPLUS2 (reg 1) (reg 2)).  Computes "ALLARGS" list
  %% from CDR (CMACRO args) and tacks op name onto each thing returned. /csp
  (foreach arg in (&allargs (cdr u)) collect (cons (car u) arg)))

(de &allargs (arglst)
  %% Uses &REMREGS to compute list of alternative, equivalent "expressions"
  %% for each arg, generates cross product of alternatives so that every
  %% element of &ALLARGS of (<a> <b> <c>)) has as its first element one of the
  %% alternatives for <a>, an alternative for <b>, and one for <c>. /csp
  (cond ((null arglst) nil)
        ((null (cdr arglst)) 
         (foreach val in (&remregs (car arglst)) collect (list val)))
        (t (&allargs1 (&remregs (car arglst)) (&allargs (cdr arglst))))))

(de &allargs1 (firstargs restargs)
  %% Support for ALLARGS /csp
  (prog (res)
        (setq res nil)
        (foreach a1 in firstargs do 
                 (foreach a2 in restargs do 
                  (setq res (cons (cons a1 a2) res))))
        (return res)))

%%% End of CMACRO alternative expression guys. /csp
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
(de &remmrefs ()
  %? Remove MEMOERY references from values lists
  (setq regs& 
        (foreach r in regs& collect (cons (car r) (&remmrefs1 (cdr r))))))

(de &remmrefs1 (l)
  % Support for REMMREFS
  (cond ((null l) l)
        ((&refmemory (car l)) (&remmrefs1 (cdr l)))
        (t (cons (car l) (&remmrefs1 (cdr l))))))

(de &refmemory (exp)
  % Support for REMMREFS, check singel MEM cse
  (if (or (atom exp) (flagp (car exp) 'terminal))
    nil
    (or (member (car exp) '(memory car cdr)) (&refmemoryl (cdr exp)))))

(de &refmemoryl (l)
  % Support for REMEMORY
  (if (null l)
    nil
    (or (&refmemory (car l)) (&refmemoryl (cdr l)))))

(de &remvrefs ()
  %? Remove VARIABLE refs, and update SLST to ensure
  %? will be protected later
  (prog (s)
        (setq regs& 
              (foreach r in regs& collect 
                       (cons (car r) (&remvrefs1 (cdr r)))))
        % Slow version:
        %   SLST!& := FOR EACH S IN SLST!& CONC 
        %     IF !&EXTERNALVARP CAR S THEN NIL ELSE LIST S;
        % Faster version:
        %   while not null Slst!& and !&ExternalVarP car car Slst!& do
        %	Slst!& := cdr Slst!&;
        (setq s slst&)
        (while (not (null s))
          %              scs
          (progn
            (when (&externalvarp (car (car s)))
              (rplaca (car s) nil))
            (setq s (cdr s))))))

(de &remvrefs1 (l)
  %? support for REMVREFS
  (foreach thing in l conc (if (&refexternal thing)
             nil
             (list thing))))

(de &refexternal (exp)
  %? support for REMVREFS
  (cond ((atom exp) nil)
        ((&externalvarp exp) t)
        ((flagp (car exp) 'terminal) nil)
        (t (&refexternall (cdr exp)))))

(de &refexternall (exps)
  %? support for REMVREFS
  (if (null exps)
    nil
    (or (&externalvarp (car exps)) (&refexternall (cdr exps)))))

(de &externalvarp (u)
  %? support for REMVREFS
  (and (pairp u) (flagp (car u) 'extvar)))

(de &remrefs (v)
  % Remove all references to V from REGS!&
  (if (member (car v) '(memory car cdr))
    (&remmrefs)
    (setq regs& 
          (foreach r in regs& collect (cons (car r) (&remrefs1 v (cdr r)))))))

(de &remrefs1 (x lst)
  % Remove all expressions from LST which reference X
  (cond ((null lst) nil)
        ((&references (car lst) x) (&remrefs1 x (cdr lst)))
        (t (cons (car lst) (&remrefs1 x (cdr lst))))))

%************************************************************
%   Test functions
%************************************************************
(de &setbranch ()
  (setq slst& 
        (setq tail& 
              (setq branchpoint& 
                    (cons (list 'branch branchpoint& tail&) slst&)))))

(de &nextbranch ()
  (when (and branchpoint& (ne slst& branchpoint&))
    (prog (s1 s2)
          (when slst&
            (setq s1 slst&)
            (while (and (setq s2 (cdr s1)) (ne s2 branchpoint&))
              (setq s1 s2))
            (rplacd s1 tail&)
            (setq tail& slst&))
          (unless s2
            (rplacd branchpoint& nil))
          (setq slst& branchpoint&))))

(de &unbranch ()
  (while branchpoint&
    (&nextbranch)
    (setq slst& tail&)
    (rplaca (car branchpoint&) nil)
    (setq tail& (caddr (car branchpoint&)))
    (setq branchpoint& (cadr (car branchpoint&)))))

(de &tstandor (exp labl)
  % Compile TEST expressions in COND, WHILE, etc as conditional Jumps
  (prog (flg flg1 fn lab2 regsl regs1l)
        %    scs
        %FLG is initial SWITCH!& condition;
        %FN is appropriate AND/OR case;
        %FLG1 determines appropriate switching state;
        (setq flg switch&)
        (setq switch& nil)
        (setq fn (eq (car exp) 'and))
        (setq flg1 (eq flg fn))
        (setq exp (cdr exp))
        (setq lab2 (&genlbl))
        (while exp
          (setq switch& nil)
          (if (and (null (cdr exp)) flg1)
            (progn
              (when fn
                (setq switch& t))
              (&comtst (car exp) labl)
              (setq regsl (cons regs& regsl))
              (setq regs1l (cons regs1& regs1l)))
            (progn
              (unless fn
                (setq switch& t))
              (if flg1
                (progn
                  (&comtst (car exp) lab2)
                  (setq regsl (cons regs1& regsl))
                  (setq regs1l (cons regs& regs1l)))
                (progn
                  (&comtst (car exp) labl)
                  (setq regsl (cons regs& regsl))
                  (setq regs1l (cons regs1& regs1l))))))
          (setq exp (cdr exp))
          (when exp
            (&setbranch))
          nil)
        %         scs
        (&attlbl lab2)
        (setq regs& (if (not flg1)
                (car regsl)
                (&rmerge regsl)))
        (setq regs1& (if flg1
                (car regs1l)
                (&rmerge regs1l)))
        (setq switch& flg)))

%************************************************************
%  Pass2 compile functions
%************************************************************

(de &special-comp-function (exp status)
  (let* ((fn-name  (first exp))
	(arg-count  (get fn-name 'argument-count))
	(compfn     (get fn-name 'compfn)))
    (if (and arg-count
	     (ne arg-count (length (rest exp))))
      (&comperror (list "Incorrect number of arguments to" fn-name "in" exp))
      (apply compfn (list exp status))
      )))

(de &comandor (exp status&) 
   % COMPFN: AND and OR chains
   (prog (fn labl regsl) 
      % Added source transformation to handle problem that (and) or
      % (or) didn't compile correctly.
      (cond ((equal exp '(and)) (setq exp '(and 't))) 
      ((equal exp '(or)) (setq exp '(or 'nil)))) 
      (setq fn (eq (car exp) 'and)) 
      (setq labl (&genlbl)) 
      (setq exp (cdr exp)) 
      (while exp 
      (progn (&comval (car exp) (cond ((cdr exp) 1) (t status&))) 
        %to allow for recursion on last entry;
	% BUG Busters strike again.  The following line will reset the
	% store optimization list to NIL.  This will fix the following
	% code:
        % (de foo () 
        %  (prog (x)
        %    (or (setf x 1) (setf x 2))
        %    (print x)))
	% Which was optimizing away the first setf.
	(setq slst& nil) 
        (setq regsl (cons regs& regsl)) 
	(cond ((cdr exp) (cond (fn (&jumpnil labl)) (t (&jumpt labl))))) 
	(setq exp (cdr exp)))) 
      (setq regs& (&rmerge regsl)) 
      (&attlbl labl)))

(de &comapply (exp status)
  (&comapply-aux exp status 'apply 'fastapply)
  )

(de &comapply-aux (exp status slow-function fast-function)

  % COMPFN:  Look for LIST in APPLY(foo, LIST(a,,,))
  %          or use FAST-APPLY or APPLY for special cases
  %
  % The new Cmacro *FAST-APPLY-LOAD is used to load the machine-specific 
  % register which hold the function being called.
  %
  % The test for number of arguments was changed from greaterp to geq to allow the
  % dreg model a register for the fastapply function argument.
  % It is safe but unnecessary for the previous implementations. /csp

  (let* ((fn     (second exp))
	 (args   (consed-list (third exp))))
    (if (or (eq args 'not-a-consed-list)
	    (geq (length args) maxnargs&))
      (&call slow-function (rest exp) status)
      (let ((n-args (length args)))
	(setf args (append args (list fn)))
	(&comload args)
	(&attach (list '*fast-apply-load (&mkreg (plus n-args 1))))
	(&attach (list '*link fast-function 'expr n-args))
	(setf regs& nil)
	(&remvrefs)
	))))

(de consed-list (exp)
  % If exp is a list that can be decomposed by the compiler, a list
  % of its components is returned.  If not, 'NOT-A-CONSED-LIST is returned.
  (cond
   ((atom exp)
    'not-a-consed-list
    )
   ((memq (first exp) '(list ncons list1 list2 list3 list4 list5))
    (rest exp)
    )
 % ((eq (first exp) 'quote)  wrong handling modified; HM, 21-dec-89
 %  (second exp)
 %  )
   ((and (eqcar exp 'quote) (pairp (second exp)))
    (mapcar (second exp) (function mkquote))
    )
   (t
    'not-a-consed-list
    )
   ))

(de &comcodeapply (exp status)
  (&comapply-aux exp status 'codeapply 'fast-codeapply)
  )

(de &comcond (exp status&)

  % COMPFN: compiles conditional expressions;
  %         registers REGS!& are set for dropping through,
  %         REGS1  are set for a branch;
  %
  % EXP must be of the form: 
  %    (COND ((test1 form1)
  %           ...
  %           (testn formn) 
  %           ((QUOTE T) (formn+1)))
  %
  % NOTE: The code generated contains an extraneous jump from the end of 
  %       formn+1 to the bottom of the cond (the next instruction).  It
  %       is assumed that the optimizer will take care of this.

  (let* ((clauses       (rest exp))
	 (bottom-label  (&genlbl))
	 branch-regs              % Register values from each jump
                                  % to bottom-label.
	 branchpoint&
	 tail&
	 )

    (unless (and clauses
		 (for (in x clauses) (always (equal (length x) 2)))
		 (equal (first (lastcar clauses)) '(quote t)))
      (&comperror (bldmsg "Bad COND in pass 2 of compiler: %r" exp))
      )
    
    (for (in clause clauses)
	 (do
	  (let ((next-case-label (&genlbl))
		(switch&         nil)        % Used by &COMTST
		regs1&                       % Set by &COMTST
		)
	    (&comtst (first clause) next-case-label)
	    (&setbranch)
	    (&comval (second clause) status&)
	    (&nextbranch)
	    (&attjmp bottom-label)
	    (setq branch-regs (cons regs& branch-regs))
	    (setq regs& regs1&) % restore register status for next iteration;
	    (&attlbl next-case-label)
	    )))
    (setq regs& (&rmerge (cons regs& branch-regs)))
    (&attlbl bottom-label)
    (&unbranch)
    ))


(de &comcons (exp status&)
  % COMPFN: for CONS, in favor of NCONS and XCONS special cases
  (setf exp (rest exp))
  (cond ((equal (cadr exp) ''nil) (&call 'ncons (list (car exp)) status&))
        ((and (member (cadr exp) (&regval '(reg 1))) (&openp (car exp))) 
         (&call 'xcons (reverse exp) status&)) %  scs
        (t (&call 'cons exp status&))))   %  scs

(de &comcase (exp status&)
  % COMPFN: Compile CASE statement
  %         Look for special cases as JUMPON, JUMPEQ , JUMPWITHIN etc
  (prog (bottomlab regs1& jumps exps elselab high low saveregs jmps jlist 
                   ranges table branchpoint& tail&)
        %  scs
        (setq bottomlab (&genlbl))
        (setq regs1& nil)
        (&comval (cadr exp) 1)
        (setq jumps (setq exps nil))
        (foreach thing on (cddr exp) do 
                 (prog (lab)
                       (setq lab (&genlbl))
                       (setq jumps 
                        (nconc jumps (list (list (caar thing) lab))))
                       (setq exps 
                        (nconc exps (list (list lab (cadar thing)))))
                       (when (null (cdr thing))
                         (if (not (null (caar thing)))
                           (if (greaterp status& 1)
                             (progn
                               (setq regs1& (cons regs& regs1&))
                               (setq elselab bottomlab))
                             (setq exps 
                              (nconc exps 
                               (list (list (setq elselab (&genlbl)) ''nil)))))
                           (setq elselab lab)))))
        (setq ranges nil)
        (setq table nil)
        (foreach jmp in jumps do 
                 (foreach num in (car jmp) do (if (eqcar num 'range)
                    (prog (high low)
                          (setq low (&getnum (cadr num)))
                          (setq high (&getnum (caddr num)))
                          (when (geq high low)
                            (if (lessp (difference high low) 6)
                              (for (from i low high 1) 
                               (do 
                                (setq table (&instbl table i (cadr jmp)))))
                              (setq ranges 
                               (nconc ranges 
                                (list (list low high (cadr jmp))))))))
                    (setq table (&instbl table (&getnum num) (cadr jmp))))))
        (foreach r in ranges do 
                 (&attach (list '*jumpwithin (caddr r) (car r) (cadr r))))
        (while table
          (setq jmps (list (car table)))
          (setq low (setq high (caar table)))
          (setq jlist (list (cadar table)))
          (while (and (cdr table) (lessp (car (cadr table)) (plus high 5)))
            (setq table (cdr table))
            (while (lessp high (difference (caar table) 1))
              (setq high (plus high 1))
              (setq jlist (nconc jlist (list elselab))))
            (setq high (plus high 1))
            (setq jlist (nconc jlist (list (cadar table))))
            (setq jmps (nconc jmps (list (car table)))))
          (if (lessp (length jmps) 4)
            (foreach j in jmps do 
                     (&attach 
                      (list '*jumpeq (cadr j) '(reg 1) 
                       (list 'wconst (car j)))))
            (prog (reg)
                  (if (cdr table)
                    (progn
                      (setq reg '(reg 2))
                      %  scs
                      (&lreg reg '(reg 1)))
                    (setq reg '(reg 1)))
                  (&attach 
                   (cons '*jumpon (cons reg (cons low (cons high jlist)))))
                  (setq regs& (delasc reg regs&))))
          %  scs
          (setq table (cdr table)))
        (&attjmp elselab)
        (setq saveregs regs&)
        (&setbranch)
        %      scs
        (foreach thing in exps do (progn
                   (&attlbl (car thing))
                   (setq regs& saveregs)
                   (when (cadr thing)
                     (&comval (cadr thing) status&))
                   (&nextbranch)
                   %      scs
                   (unless (&transferp codelist&)
                     (&attjmp bottomlab)
                     (setq regs1& (cons regs& regs1&)))))
        (&attlbl bottomlab)
        (setq regs& (&rmerge regs1&))
        (&unbranch)))

%      scs
(de &instbl (tbl i l)
  % Support for COMCASE, one branch
  (cond ((null tbl) (list (list i l)))
        ((lessp i (caar tbl)) (cons (list i l) tbl))
        ((equal i (caar tbl)) (&comperror (list "Ambiguous case" tbl)))
        (t (cons (car tbl) (&instbl (cdr tbl) i l)))))

(de &getnum (x)
  % Support for CASE, check numeric tag
  (if (integer-constant? x)
    (constant-value x)
    (&comperror (list "Number expected for CASE label" x))
    ))

(de &comgo (exp status&)
  % COMPFN: Compile GO inside PROG.
  %/ Should SLST& be cleared like this?
  % hm: look for label "by hand" in order to rebind variables
  %   in between.
  (let((lab (cadr exp)) 
       nlab 
       (gl golist&))
    (while (and (null nlab) gl)
           (cond ((eq (caar gl) lab)(setq nlab (cdar gl)))
                 ((eq (caar gl) '&freerstr) (&freerstr (cdar gl))))
           (setq gl (cdr gl)))
    (cond ((and nlab (greaterp status& 2)) 
           (&attjmp nlab) 
           (setq slst& nil))
          (t % scs
             (&comperror (list exp "label not found"))))))

(de &comidapply (exp status)
  (&comapply-aux exp status 'idapply 'fast-idapply)
  )

(de &comprog (exp status&)
  % COMPFN: for PROG compiles program blocks;
  %/ need to improve SLST handling, binding
  %/ see LAMBDA
  % hm: rebind golist& for extension.
  (let (oldstomap oldcode i alsts& (golist& golist&) pg 
        proglis exitt& exitregs&)
        %  scs
        (setq exitregs& nil)
        (setq proglis (cadr exp))
        (setq exp (cddr exp))
        (setq exitt& (&genlbl))
        (setq pg (&remvarl proglis))
        %protect prog variables;
        (setq oldcode codelist&)
        %  scs
        (setq oldstomap stomap&)
        %  scs
        (setq alsts& (&varbind proglis nil))
         % hm
        (when alsts& (push (cons '&freerstr alsts&) golist&))
        (foreach x in exp do (when (atom x)
                   (setq golist& (cons (cons x (&genlbl)) golist&))))
        (while exp
          (if (atom (car exp))
            (progn
              (&attlbl (&getlbl (car exp)))
              (setq regs& nil))
            (&comval (car exp) (if (greaterp status& 1)
                       4
                       3)))
          %   scs
          (setq exp (cdr exp)))
        (when (and (not (&transferp codelist&)) (lessp status& 2))
          (&lreg1 ''nil))
        (&attlbl exitt&)
        (setq regs& (&rmerge (cons regs& exitregs&)))
        (&freerstr alsts& status&)
        (&fixfrm oldstomap oldcode)
        %  let's go for it  scs
        (&rstvarl proglis pg)))

(de &comprogn (exp status&)
  % COMPFN: Compile PROGN cases
  (prog nil
        (setq exp (cdr exp))
        (when (null exp)
          (return (&comval ''nil status&)))
        (while (cdr exp)
          (&comval (car exp) (if (lessp status& 2)
                     2
                     status&))
          (setq exp (cdr exp)))
        (&comval (car exp) status&)))

(de &comreturn (exp status&)
  % COMPFN: Compile RETURN inside PROG
  %/ Should be better SLSTS handling, last return
  %/ Cf LAMBDA case
  (setq exp (cdr exp))
  %  test for 1,2?   scs
  (when (or (lessp status& 4) (not (&nosideeffectp (car exp))))
    (&comload exp))
  (setq slst& nil)
  (setq exitregs& (cons regs& exitregs&))
  (&attjmp exitt&))

(de &delmac (x)
  % Delete macro CAR X from CODELIST!&
  (rplaca x '(*noop)))

%*************************************************************
%              Pass 3
%*************************************************************
%----------------------------- Post Code Generation Fixups; 
(de &pass3 ()
  % Pass 3 - optimization.
  %    The optimizations currently performed are:
  % 1. Deletion of stores not yet picked up from SLST!&.
  % 2. Removal of unreachable macros.
  % 3. A peep hole optimizer, currently only optmizing LBL macros.
  % 4. Removal of common code chains
  % 5. Changing LINK to LINKE where possible
  % 6. Squeezing out unused frame locations and mapping the stack onto
  %    the registers.
  % Other functions of PASS3 are to tack exit code on the end and reverse
  % the code list.
  (progn
    (foreach j in slst& do (when (car j)
               (&delmac (cdr j))))
    %    scs
    (&attlbl exitt&)
    (&attach '(*exit (*framesize)))
    (&remcode t)
    (&fixlabs)
    (&fixchains)
    (&fixlinks)
    (&remcode nil)
    (&fixfrm nil nil)
    %   scs
    (&peepholeopt)
    (&remcode nil)
    (setq codelist& (reversip codelist&))
    nil))

(de &insertmac (place mac)
  % Insert a CMACRO into CODELIST
  (rplacw place (cons mac (cons (car place) (cdr place)))))

(de &deletemac (place)
  % Delete a CMACRO from CODELIST
  (rplacw place (cdr place)))

(de &remcode (keeptop)
  %? Remove a block of code  for Unused labels
  (prog (unusedlbls)
        (setq unusedlbls (&unusedlbls keeptop))
        (&remunusedmac unusedlbls)
        (while (setq unusedlbls (&unusedlbls keeptop))
          (&remunusedmac unusedlbls))))

(de &unusedlbls (keeptop)
  %? Which labels are not used?
  (prog (used unused)
        (setq used nil)
        (setq unused lblist&)
        (when keeptop
          (setq used (cons (&labclass toplab&) used))
          (setq unused (&delclass toplab& unused)))
        (foreach mac in codelist& do (when (neq (car mac) '*lbl)
                   (foreach fld in (cdr mac) do (when (and 
                                                       (eqcar fld 'label) 
                                                       (&classmember fld 
                                                        unused))
                      (setq used (cons (&labclass fld) used))
                      (setq unused (&delclass fld unused))))))
        (setq lblist& used)
        (return unused)))

(de &classmember (lab classes)
  % support for label hacking
  (if (null classes)
    nil
    (or (member lab (car classes)) (&classmember lab (cdr classes)))))

(de &remunusedmac (unusedlabs)
  % Remove the !*NOOPs, or LBLS after transfers
  (prog (p q r)
        (setq codelist& (setq p (reversip codelist&)))
        (while (cdr p)
          (setq q (cdr p))
          (if (or (equal (caar q) '*noop) 
                  (and (&transferp p) (neq (caar q) '*lbl)) 
                  (and (equal (caar q) '*lbl) 
                       (&classmember (cadar q) unusedlabs)))
            (rplacd p (cdr q))
            (setq p (cdr p))))
        (setq codelist& (reversip codelist&))))

(de &fixlinks ()
  %
  % replace LINK by LINKE where appropriate
  %
  (when (and (not *nolinke) (not freebound&))
    (prog (switched)
          (foreach inst on codelist& do 
                   (prog (saverest)
                         (when (or 
                                (and exitt& 
                                 (equal (first (first inst)) '*jump) 
                                 (equal (second (first inst)) exitt&))
                                (equal (first (first inst)) '*exit))
                           (when (equal (first (second inst)) '*lbl)
                             (when (equal (first (third inst)) '*link)
                               (setq inst (cdr inst))
                               (setq saverest t)))
                           (when (equal (first (second inst)) '*link)
                             (if (and (eq (second (second inst)) name&) 
                                  *r2i)
                               (rplaca (rest inst) (list '*jump toplab&))
                               (rplaca (rest inst) 
                                (cons '*linke 
                                 (cons '(*framesize) (rest (second inst))))))
                             (unless saverest
                               (&deletemac inst)))))))))

(de &peepholeopt ()
  % table driven 'peep-hole' optimization for various cases;
  (prog (x z)
        (setq z codelist&)
        (while z
          (cond ((equal (caar z) '*noop) (&deletemac z))
                ((or (not (setq x (get (caar z) 'optfn))) 
                     (not (apply x (list z))))
                 (setq z (cdr z)))))))

%----------- Peep-hole optimization tables; 
(de &stopt (u)
  % OPTFN: Convert MOVEs + ALLOCS into PUSHES
  (cond ((and (equal (caadr u) '*alloc) (equal llngth& 1) 
              (equal (cddar u) '((frame 1))))
         (rplacw u (cons (list '*push (cadar u)) (cddr u))))
        ((and (equal (caadr u) '*move) (equal (caaddr u) '*alloc) 
              (equal llngth& 2) (equal (cddar u) '((frame 2))) 
              (equal (cddadr u) '((frame 1))))
         (rplacw u 
                 (cons (list '*push (cadadr u)) 
                       (cons (list '*push (cadar u)) (cdddr u)))))))

(de &lblopt (u)
  %? OPTFN: Convert some LABLE/JUMP chains
  (prog (z)
        (when (equal (cadr u) '*lbl)
          (&defeqlbl (cadr u) (cadr (cdr u)))
          (rplacd u (cddr u))
          (return t))
        (cond ((and (cdadr u) (eqcar (cadadr u) 'label) 
                    (&lbleq (cadar u) (cadadr u)))
               (return (rplacw (cdr u) (cddr u))))
              ((and (equal (caadr u) '*jump) 
                    (setq z (get (caaddr u) 'negjmp)) 
                    (&lbleq (cadar u) (cadr (caddr u))))
               (return (progn
                         (setq z 
                          (cons z (cons (cadadr u) (cddr (caddr u)))))
                         (rplacd u (cons z (cdddr u)))
                         t)))
              (t (return nil)))))

(de &jumpopt (u)
  % OPTFN: Convert JUMP to exit label into an EXIT
  (when (and (equal (cadar u) exitt&) (equal llngth& 0))
    (rplaca u '(*exit (*framesize)))))

(de &fixchains ()
  %? Fix common code chains
  (prog (lab)
        (foreach labcode on codelist& do 
                 (cond ((equal (caar labcode) '*lbl) % OR CAAR LABCODE = '!*JUMP	% croaks on this one
                        (progn
                          (setq lab (cadar labcode))
                          (foreach jumpcode on (cdr labcode) do (when (and 
                                                                       (equal
                                                                        (caar
                                                                         jumpcode)
                                                                        '*jump)
                                                                       (equal
                                                                        (cadar
                                                                         jumpcode)
                                                                        lab))
                             (&movejump labcode jumpcode)))))))))

(de &movejump (labcode jumpcode)
  %? OPTFN: Interchanges Moves and jumps inside Loops
  (when (equal (cadr labcode) (cadr jumpcode))
    (prog (lab)
          (repeat (progn
                    (when (equal (cadr labcode) (cadr jumpcode))
                      (setq jumpcode (cdr jumpcode))
                      (setq labcode (cdr labcode)))
                    (while (equal (caadr labcode) '*lbl)
                      (setq labcode (cdr labcode)))
                    (while (equal (caadr jumpcode) '*lbl)
                      (setq jumpcode (cdr jumpcode)))
                    nil)
                  (not (equal (cadr jumpcode) (cadr labcode))))
          (if (equal (caar labcode) '*lbl)
            (rplacd jumpcode 
                    (cons (list '*jump (cadr (car labcode))) 
                     (cdr jumpcode)))
            (progn
              (setq lab (&genlbl))
              (rplacd jumpcode (cons (list '*jump lab) (cdr jumpcode)))
              (rplacd labcode (cons (list '*lbl lab) (cdr labcode))))))))

(de &fixfrm (oldstomap oldcode)
  %       scs
  % Squeeze out HOLES
  %/ Should change FIXFRM to do sliding squeeze, not reorder;
  (prog (n freeregs framesused r fr p holemap oldp)

   % remove moves to frames which are not used later on
        (setq p codelist&)
        (while (not (eq p oldcode))
		(if (and  oldp (pairp (car p))
			   (eq (caar p) '*move)
			   (eq (caar (cddar p)) 'frame)
			   (not (&occurs (caddar p) oldstomap))
			   (&countoccurs (caddar p) codelist& oldcode nil))
			(rplacd oldp (cdr p))
		        (setq oldp p))
                     (setq p (cdr oldp)))
        (setq framesused (&getframes codelist& oldcode nil))
        (setq n 0)
        (foreach var in oldstomap do (progn
                   (setq n (max n (cadr (setq fr (cadr var)))))
                   (setq framesused (delete fr framesused))))
        (setq llngth& n)
        (unless framesused
          (return nil))
        (foreach frame in framesused do 
                 (setq llngth& (max llngth& (cadr frame))))
        (setq freeregs (unless (and freebound& (not *useregfluid))
                (&freeregs codelist& oldcode nil)))
        (setq holemap nil)
        (foreach frame in framesused do 
                 (setq holemap 
                       (cons 
                        (list frame (if freeregs
                           (progn
                             (setq r (car freeregs))
                             (setq freeregs (cdr freeregs))
                             (setq regs& (delasc r regs&))
                             r)
                           (&mkframe (setq n (plus n 1)))))
                        holemap)))
        (when (equal n llngth&)
          (return nil))
        (setq llngth& n)
        (setq p codelist&)
        (while (not (eq p oldcode))
          (rplaca p (&macrosubst (car p) holemap))
          (setq p (cdr p)))))

(de &occurs (x lis )
      (cond ((pairp lis) (or (member x lis)
                         (&occurs x (car lis)) (&occurs x (cdr lis))))))

(de &countoccurs (x code oldcode res)
  %? Support FIXFRAME
   (setq res (&countoccurs0 x code oldcode res))
   (not (member x (cdr (member x res)))))

(de &countoccurs0 (x code oldcode res)
  %? Support FIXFRAME
  (if (eq code oldcode)
    res
   (&countoccurs0 x (cdr code) oldcode (&countoccurs1 (cdar code) res))))

(de &countoccurs1 (macargs res)
  %? Support FIXFRAME
  (if (null macargs)
    res
    (&countoccurs1 (cdr macargs) (&countoccurs2 (car macargs) res))))

(de &countoccurs2 (macarg res)
  %? Support FIXFRAME
  (cond ((or (atom macarg) (&varp macarg) (&constp macarg) (&regp macarg))
         res)
        ((eqcar macarg 'frame) (cons macarg res))
        (t (&countoccurs1 (cdr macarg) res))))

(de &getframes (code oldcode res)
  %? Support FIXFRAME?
  (if (eq code oldcode)
    res
    (&getframes (cdr code) oldcode (&getframes1 (cdar code) res))))

(de &getframes1 (macargs res)
  %? Support FIXFRAME
  (if (null macargs)
    res
    (&getframes1 (cdr macargs) (&getframes2 (car macargs) res))))

(de &getframes2 (macarg res)
  %? Support FIXFRAME
  (cond ((or (atom macarg) (&varp macarg) (&constp macarg) (&regp macarg)) 
         res)
        ((eqcar macarg 'frame) (if (member macarg res)
           res
           (cons macarg res)))
        (t (&getframes1 (cdr macarg) res))))

(de &freeregs (start stop exitflag)
  %       scs
  (prog (i r usedregs freeregs)
        (when (equal (setq usedregs (&regsused start stop nil exitflag)) 
                     'all)
          (return 'nil))
        (for (from i lastactualreg& 2 -1) % do not use (reg 1) 
             (do (unless (member (setq r (&mkreg i)) usedregs)
                   (setq freeregs (cons r freeregs)))))
        (foreach reg in pregs& do (setq freeregs (delete reg freeregs)))
        (return freeregs)))

(de &regsused (start stop regsused exitflag)
  %        scs
  % Find which registers are used.  'ALL is returned if all are used.
  % Supports INSTALLDESTORY and Reg mapping
  (if (eq start stop)
    regsused
    (prog (mac instr fn nargs)
          (setq mac (car start))
          (setq instr (car mac))
          (when (and (setq nargs 
                      (cond ((eq instr '*link) (setq fn (cadr mac)) 
                             (cadddr mac))
                            ((or (eq instr '*linke) (eq instr '*linkef)) 
                             (setq fn (caddr mac)) (car (cddddr mac)))))
                     (not exitflag))
            (while (greaterp nargs 0)
              (setq regsused (adjoin (&mkreg nargs) regsused))
              (setq nargs (sub1 nargs))))
          (return (cond ((or (equal instr '*link) 
                          (and (equal instr '*linke) exitflag))
                         (cond ((equal fn name&) (if exitflag
                                  (&regsused (cdr start) stop regsused 
                                   exitflag)
                                  'all))
                               ((and *usingdestroy 
                                 (setq dest& (get fn 'destroys)))
                                (setq regsused (union dest& regsused)) 
                                (&regsused (cdr start) stop regsused 
                                 exitflag))
                               (t 'all)))
                        ((or (equal instr '*linkf) 
                          (and (equal instr '*linkef) exitflag))
                         'all)
                        (t 
                         (&regsused (cdr start) stop 
                          (&regsused1 regsused (cdr mac)) exitflag)))))))

(de &regsused1 (regsused args)
  %   scs
  %? Support REGSUSED
  (prog nil
        (foreach a in args do (setq regsused (&regsused2 regsused a)))
        (return regsused)))

(de &regsused2 (regsused arg)
  %     scs
  % Support REGSUSED
  (cond ((atom arg) regsused)
        ((not (atom (car arg))) (&regsused1 regsused arg))
        ((&constp arg) regsused)
        ((and (equal (car arg) 'reg) (numberp (cadr arg))) 
         (adjoin arg regsused))
        (t (&regsused1 regsused (cdr arg)))))

(de &reformmacros ()
  % Converts some pseudo-s into numbers
  (prog (finaltransform)
        (setq finaltransform (list (list '(*framesize) llngth&)))
        (foreach mac on codelist& do 
                 (rplaca mac (&macrosubst (car mac) finaltransform)))))

(de &fixlabs ()
  %  scs
  %? Fixup LABELS and JUMPS ?
  (prog (transform u instr0 instr long)
        (setq transform nil)
        (foreach lab in lblist& do 
                 (foreach eqlab in (cdr lab) do 
                  (setq transform (cons (list eqlab (car lab)) transform))))
        (foreach mac on codelist& do (progn
                   (setq instr0 (car mac))
                   (when (neq instr0 
                          (setq instr (&macrosubst instr0 transform)))
                     (when (setq long (get (car instr) 'longbranch))
                       (rplaca instr long))
                     (rplaca mac instr))))
        (when (setq u (assoc exitt& transform))
          (setq exitt& (cadr u)))
        (when (setq u (assoc toplab& transform))
          (setq toplab& (cadr u)))
        (setq lblist& (foreach lab in lblist& collect (list (car lab))))))

(de &macrosubst (mac alist)
  %? Pattern matchers?
  (cons (car mac) (&macrosubst1 (cdr mac) alist)))

(de &macrosubst1 (args alist)
  %? pattern Matchers?
  (foreach arg in args collect (&macrosubst2 arg alist)))

(de &macrosubst2 (arg alist)
  %? Pattern matchers
  (prog (u)
        (setq u (assoc arg alist))
        (return (cond (u (cadr u))
                      ((or (atom arg) (flagp (car arg) 'terminal)) arg)
                      (t (cons (car arg) (&macrosubst1 (cdr arg) alist)))))))

(de &remtags ()
  % Remove auxiliarry tags for old compiler model
  (foreach mac in codelist& do (&remtags1 mac)))

(de &remtags1 (mac)
  % Suppport REMTAGS
  (progn
    (when (equal (car mac) '*jumpon)
      (rplacd (cdddr mac) (list (cddddr mac))))
    (foreach macfield in (cdr mac) do (&remtags2 macfield))))

(de &remtags2 (u)
  % Support REMTAGS
  (when (eqcar u 'wconst)
    (&remtags3 (cadr u))))

(de &remtags3 (u)
  % Support REMTAGS
  (prog (dofn)
        (when (atom u)
          (return nil))
        (when (setq dofn (get (car u) 'dofn))
          (rplaca u dofn))
        (&remtags4 (cdr u))))

(de &remtags4 (u)
  % Support REMTAGS
  (foreach x in u do (&remtags3 x)))

%-------------Entry points used in setting up the system
%--- to declare in COMP-DECLS
(de &onereg (u)
  % Indicate these funs use only one reg
  (foreach x in u do (put x 'destroys '((reg 1)))))

(de &tworeg (u)
  % Indicate these funs use only two reg
  (foreach x in u do (put x 'destroys '((reg 1) (reg 2)))))

(de &threereg (u)
  % Indicate these funs use only three reg
  (foreach x in u do (put x 'destroys '((reg 1) (reg 2) (reg 3)))))

