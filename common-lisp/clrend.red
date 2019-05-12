module rend;  % CL REDUCE "back-end".

% Authors: Anthony C. Hearn, Martin L. Griss, Arthur C. Norman, et al.
% Modified by FJW for Common Lisp REDUCE.
% The standard version is "$reduce/packages/support/*rend.red".

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Redistribution and use in source and binary forms, with or without		   %
% modification, are permitted provided that the following conditions are met:  %
%																			   %
%    * Redistributions of source code must retain the relevant copyright	   %
%      notice, this list of conditions and the following disclaimer.		   %
%    * Redistributions in binary form must reproduce the above copyright	   %
%      notice, this list of conditions and the following disclaimer in the	   %
%      documentation and/or other materials provided with the distribution.	   %
%																			   %
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  %
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE	   %
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   %
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE	   %
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR		   %
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF		   %
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS	   %
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN	   %
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)	   %
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   %
% POSSIBILITY OF SUCH DAMAGE.												   %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

create!-package('(clrend),nil);

fluid '(!*echo
        !*int
        !*mode
        ifl!*
        lispsystem!*
        promptstring!*
		outputhandler!*);

global '(!*extraecho
         !*loadversion
         date!*
         esc!*
         ipl!*
         largest!-small!-modulus
         ofl!*
         spare!*
         statcounter
		 version!*
		 seprp!*
		 symchar!*);

switch break, gc, printlower, redefmsg, debug, verboseload;

% This procedure definition taken from "pslrend.red" is required for
% the factor module:
symbolic procedure carcheck fff;
   nil;  % CSL function used much as setting !*fastcar in PSL.

Comment The following functions, which are referenced in the basic
REDUCE source (RLISP, ALG1, ALG2, MATR and PHYS) should be defined to
complete the definition of REDUCE:

	BYE
	EVLOAD -- defined in "clprolo.red"
	ERROR1 -- defined in "sl-on-cl.lisp"
	MKFIL
	ORDERP -- defined in "clprolo.red"
	QUIT
	SEPRP
	SETPCHAR.

Prototypical descriptions of these functions are as follows;

remprop('bye,'stat);

fluid '(bye!-actions!*);

% A package may put a call to some termination code on top of this list.

bye!-actions!* := '((close!-output!-files) (quit));

symbolic procedure bye;
   eval('progn . bye!-actions!*);

deflist('((bye endstat)),'stat);

Comment to make "bye" and "quit" equivalent, as stated by the REDUCE
manual;

put('quit,'newnam,'bye);

symbolic procedure mkfil u;
   % Converts file descriptor U into valid system filename.
   % FJW: I define string!-downcase in "sl-on-cl.lisp".
   if stringp u then u
   else if not idp u then typerr(u,"file name")
   else string!-downcase u;

seprp!* := {'! , '!	, '!, '!, !$eol!$}; % FJW

symbolic procedure seprp u;
   % Returns true if U is a blank or other separator (eg, tab or ff).
   % This definition replaces one in the BOOT file (and another in "build.red").
   u memq seprp!*;

procedure setpchar c;
   % Set prompt, return old one.
   begin scalar oldprompt;
      oldprompt := promptstring!*;
      promptstring!* := if stringp c then c
	  else if idp c then id2string c
	  % FJW: I don't really want to import the CL format function just
	  % to use it here.  Is this line actually used?
	  else error(0, "Unexpected prompt in setpchar");
	  % else format(nil, "~a", c);
    return oldprompt
   end;

% This procedure has already been defined in rlisp/superv, but must be
% redefined for Common Lisp to call force-output so that the prompt
% appears when it should.  This is the approach taken in the SBCL
% default top-level REPL.
symbolic procedure printprompt u;
   %Prints the prompt expression for input;
   << ofl!* and wrs nil; prin2 u; force!-output(); ofl!* and wrs cdr ofl!* >>;


Comment The following functions are only referenced if various flags are
set, or the functions are actually defined. They are defined in another
module, which is not needed to build the basic system. The name of the
flag follows the function name, enclosed in parentheses:

	CEDIT (?)
	COMPD (COMP)
	EDIT1   This function provides a link to an editor. However, a
		definition is not necessary, since REDUCE checks to see
		if it has a function value.
	EZGCDF (EZGCD)
	PRETTYPRINT (DEFN --- also called by DFPRINT)
		This function is used in particular for output of RLISP
		expressions in LISP syntax. If that feature is needed,
		and the prettyprint module is not available, then it
		should be defined as PRINT
	RPRINT (PRET)
	TIME (TIME) returns elapsed time from some arbitrary initial
		    point in milliseconds;


% Operating system interface:

flag('(system pwd cd getenv),'opfn);

flag('(system),'noval);


Comment There are a number of system constants required for each
implementation. In systems that don't support inums, the equivalent
single precision integers should be used;

% LARGEST!-SMALL!-MODULUS is the largest power of two that can
% fit in the fast arithmetic (inum) range of the implementation.
% This is constant for the life of the system and could be
% compiled in-line if the compiler permits it.

largest!-small!-modulus := 2**23;

% If the (small) modular arithmetic is always limited to LARGEST-SMALL-
% MODULUS, it all fits in the inum range of the machine, with the
% exception of modular-times, that needs to use generic arithmetic for
% the multiplication.  However, on some machines (e.g., the VAX), it is
% possible to 'borrow' the extra precision needed, so that the following
% definition works.  This will not work of course for non-inums.


Comment We need to define a function BEGIN, which acts as the top-level
call to REDUCE, and sets the appropriate variables;

remflag('(begin),'go);

symbolic procedure begin;
   begin
        !*echo := not !*int;
        !*extraecho := t;
        ifl!* := ipl!* := ofl!* := nil;
        if null date!* then go to a;
        if !*loadversion then errorset('(load entry),nil,nil);
		linelength 80;
		prin2 version!*;
		prin2 ", ";
        prin2 date!*;
        prin2t " ...";
        !*mode := if getd 'addsq then 'algebraic else 'symbolic;
        if !*mode eq 'algebraic then !*break := nil;
           %since most REDUCE users won't use LISP
        date!* := nil;
  a:    if errorp errorset('(begin1),nil,nil) then go to a;
        prin2t "Entering LISP ... "
   end;

flag('(begin),'go);


Comment Initial setups for REDUCE;

spare!* := 0;		   % We need this for bootstrapping. (FJW: Maybe!)

symchar!* := t;				   % Changed prompt when in symbolic mode.

symbolic procedure initreduce;
   % Initial declarations for REDUCE
   <<
	  statcounter := 0;
      spare!* := 0;
      !*int := t;
      crbuflis!* := nil;     % We don't want to leave old input around.
      % eval '(begin);
   >>;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Common LISP specific definitions.

% flag('(load),'opfn); % unnecessary ? -- see rlisp/module.red


% tr etc. are defined as macros in "trace.lisp".
% The following two declarations are from pslrend/cslrend:
flag('(tr untr trst untrst),'noform);
deflist('((tr rlis) (untr rlis) (trst rlis) (untrst rlis)),'stat);


% The following function is necessary in Common Lisp startup sequence,
% since initial packages are not loaded with load-package.

% symbolic procedure fixup!-packages!*;
%    for each x in '(rlisp clrend entry poly arith alg mathpr) do
%       if not(x memq loaded!-packages!*)
%         then <<loaded!-packages!* := x . loaded!-packages!*;
%                if (x := get(x,'patchfn)) then eval list x>>;


% FLOOR is already defined.

% flag('(floor),'lose);

% CL doesn't like '(function ...) in defautoload (module entry).

% remflag('(mkfunction),'lose);

% inline procedure mkfunction u; mkquote u;

% flag('(mkfunction),'lose);

%% Fix problems in the arith package
%% =================================

% Procedure find!!minnorm causes float overflow. Not sure why, but
% circumvent it for now by using a Common Lisp
% Implementation-Dependent Numeric Constant:

% symbolic procedure find!!minnorm();
%    <<
% 	  !!minnorm := least!-positive!-normalized!-single!-float;
% 	  !!minnegnorm := -!!minnorm;
%    >>;

% flag('(find!!minnorm), 'lose);


% Some CSL compatibility, taken from support/psl{,rend}.red:

% symbolic inline procedure princ x; prin2 x;

% princ is defined in rlisp/rsupport.red, but the above inline
% definition would be better!

symbolic inline procedure prin x;  prin1 x;

remflag('(printc), 'lose);

% printc is defined in int/int.red to be prin2t, but this inline
% definition is better and is available without loading int:
symbolic inline procedure printc x; << prin2 x; terpri(); x >>;

flag('(printc), 'lose);

symbolic procedure ttab n;  while posn() < n do prin2 " ";

symbolic inline procedure explodec x; explode2 x;

% This function is called in redlog but only defined for PSL or CSL
% specifically.  Otherwise, it only gets an autoload definition that
% causes infinite recursion when called.  This stub is an attempt to
% avoid this error, but nothing more.  It will need attention later!

remflag('(systo_get!-resource!-directory), 'lose);

procedure systo_get!-resource!-directory; "";

flag('(systo_get!-resource!-directory), 'lose);

% This function is called in tmprint and apparently defined in PSL.
% This stub is an attempt to avoid an error, but nothing more.  It
% will need attention later!

procedure compute!-prompt!-string(count,level); "";

% Make ON DEFN load the prettyprinter if necessary and
% OFF DEFN reinstate property lists saved during ON DEFN:
% put('defn, 'simpfg, '((t (!require '!eslpretty))
%                       (nil (!esl!-reinstate!-plists))));

#if (memq 'sbcl lispsystem!*)
% Make the COMP switch control the SBCL evaluation mode:
put('comp, 'simpfg, '((t (compilation t))
                      (nil (compilation nil))));
#endif

% This procedure is defined in "rlisp88/inspect.red", but it prints
% all letters as lower case.  This version fixes that:

remflag('(i!&prn), 'lose);

procedure i!&prn x;
   % I!&PRN(x) -- Display the characters of list x and then terminate
   % the line.
   begin scalar !*printlower;
      for each c in x do prin2 c;
   	  terpri()
   end;

flag('(i!&prn), 'lose);

% Fixes for the crack suite
% =========================

% "crack/crinit.red" defines procedure random_init for PSL or CSL
% specifically with no generic definition, so here is a CL version.
% Procedure `random_new_seed' is defined in "rlisp/random.red" to take
% a single argument, offset, which must be a positive integer.
% Function `datestamp' is defined in "sl-on-cl" to return the number
% of seconds that have elapsed since some epoch.

symbolic procedure random_init(); random_new_seed datestamp();

% "crack/crutil.red" defines this procedure only for PSL.
% Using the CL version directly doesn't work in all cases, so I
% redefine it here as in crack!

symbolic procedure rename!-file(fromname, toname)$
   % Rename fromname to toname and return t on success.
   % (it is defined in csl)
   system bldmsg("mv %w %w", fromname, toname) = 0;

% From "pslrend.red"; does this also apply to Common Lisp? Not
% required to run "crack.tst"!

% In the crack code it is essential that subst arranges to share some of
% its output with its input. The same may be the case for sublist too?
% The standard implementation of subst in PSL does not do this.

%% symbolic procedure subst(a, b, c);
%%   if c = b then a
%%   else if atom c then c
%%   else begin
%%     scalar sa, sd;
%%     sa := subst(a, b, car c);
%%     sd := subst(a, b, cdr c);
%%     if sa eq car c and sd eq cdr c then return c
%%     else return sa . sd
%%   end;

endmodule;

end;
