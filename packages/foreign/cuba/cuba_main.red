% The interface between Reduce and Cuba (http://www.feynarts.de/cuba) is in two parts.
% Module 'alg_intf' and this module are part 1.  Part 2 is the file "redcuba.c", which is 
% used to make a C library 'libredcuba.so' serving as "glue" between Reduce/CSL and the 
% Cuba static library 'libcuba.a'. Note with caution that libcuba.a is subject
% to LGPL 3 and so a binary made by linking to it needs to adhere to whatever
% constraints that implies.

% Author: Kostas N. Oikonomou

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


module cuba_main;

% The next line is unsatisfactory (for much the reason it was in redlog)
% because it can ONLY behave while the Reduce source tree is available, and so
% it will FAIL when Reduce has been distributed as a binary archive and
% installed on a fresh computer. Furthermore if native windows is ever to
% be supported one would need a ".dll" suffix not ".so".
libredcuba_loc!* := lto_sconcat {rltools_trunk(),
                                 "packages/foreign/cuba/libredcuba.so"};
if filep libredcuba_loc!* then
   libredcuba!* := open!-foreign!-library(libredcuba_loc!*)
else
   redrror {"Can't open the Cuba library ", libredcuba_loc!*};

%% Setting parameters
cuba_statefile!*   := find!-foreign!-function("cuba_statefile", libredcuba!*);
cuba_verbosity!*   := find!-foreign!-function("cuba_verbosity", libredcuba!*);
cuba_set_flags_bit!*   := find!-foreign!-function("cuba_set_flags_bit",   libredcuba!*);
cuba_clear_flags_bit!* := find!-foreign!-function("cuba_clear_flags_bit", libredcuba!*);
cuba_gen_par!*     := find!-foreign!-function("cuba_gen_par", libredcuba!*);
cuba_vegas_par!*   := find!-foreign!-function("cuba_vegas_par", libredcuba!*);
cuba_suave_par!*   := find!-foreign!-function("cuba_suave_par", libredcuba!*);
cuba_divonne_par!* := find!-foreign!-function("cuba_divonne_par", libredcuba!*);
cuba_cuhre_par!*   := find!-foreign!-function("cuba_cuhre_par", libredcuba!*);

%% Arrays of doubles
newDoubleArray!*  := find!-foreign!-function("newDoubleArray", libredcuba!*);
setDoubleArray!*  := find!-foreign!-function("setDoubleArray", libredcuba!*);
freeDoubleArray!* := find!-foreign!-function("freeDoubleArray", libredcuba!*);

%% Integration algorithms
cuba_algorithms!* := {'!Vegas,'!Suave,'!Divonne,'!Cuhre};
% Set the shared variable cuba_algorithms to a proper algebraic-mode value:
cuba_algorithms := 'list . cuba_algorithms!*;
cuba_int!*      := find!-foreign!-function("cuba_int", libredcuba!*);
% Internal to the interface:
set_alg!*       := find!-foreign!-function("set_alg", libredcuba!*);
set_integrand!* := find!-foreign!-function("set_integrand", libredcuba!*);
get_result!*    := find!-foreign!-function("get_result",  libredcuba!*);

% ==========================================
% Setting algorithm parameters
% ==========================================

% 'par' is the parameter's name, a string; 'value' is a number/expression.
procedure cuba_gen_par(par,value);
   begin scalar savedmode, v;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      v := to_num(value);
      call!-foreign!-function(cuba_gen_par!*, 'string,par, 'double,v);
      if savedmode then off rounded;
   end;

procedure cuba_vegas_par(par,value);
   begin scalar savedmode, v;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      v := to_num(value);
      call!-foreign!-function(cuba_vegas_par!*, 'string,par, 'int32,v);
      if savedmode then off rounded;
   end;

procedure cuba_suave_par(par,value);
   begin scalar savedmode, v;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      v := to_num(value);
      call!-foreign!-function(cuba_suave_par!*, 'string,par, 'double,v);
      if savedmode then off rounded;
   end;

procedure cuba_divonne_par(par,value);
   begin scalar savedmode, v;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      v := to_num(value);
      call!-foreign!-function(cuba_divonne_par!*, 'string,par, 'double,v);
      if savedmode then off rounded;
   end;

procedure cuba_cuhre_par(par,value);
   begin scalar savedmode, v;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      v := to_num(value);
      call!-foreign!-function(cuba_cuhre_par!*, 'string,par, 'int32,v);
      if savedmode then off rounded;
   end;

procedure cuba_statefile(name);
    call!-foreign!-function(cuba_statefile!*, 'string,name);
procedure cuba_set_flags_bit(alg,i);
    call!-foreign!-function(cuba_set_flags_bit!*, 'string,alg, 'int32,i);
procedure cuba_clear_flags_bit(alg,i);
    call!-foreign!-function(cuba_clear_flags_bit!*, 'string,alg, 'int32,i);
procedure cuba_verbosity(level);
    call!-foreign!-function(cuba_verbosity!*, 'int32,level);

symbolic operator 
   cuba_gen_par, cuba_statefile, cuba_verbosity, 
   cuba_set_flags_bit, cuba_clear_flags_bit,
   cuba_vegas_par, cuba_suave_par, cuba_divonne_par, cuba_cuhre_par;


% ==========================================
% C arrays of doubles
% ==========================================

% These procedures are internal to the interface, they are not supposed to be
% used at the Reduce level!
procedure newDoubleArray(n);
   % the 'int64 represents the fact that the foreign function's result is a pointer
   call!-foreign!-function(newDoubleArray!*, 'int32,n, 'int64);
procedure setDoubleArray(a,i,x);
   call!-foreign!-function(setDoubleArray!*, 'int64,a, 'int32,i, 'double,x);
procedure freeDoubleArray(a);
   call!-foreign!-function(freeDoubleArray!*, 'int64,a);


% The interface gets very complicated here!!!  To understand why the following 3
% lines are here and not in redcuba.c, see the comments on the function "register_callback"
% in "C_call_CSL.h".
register_callback := find!-foreign!-function("register_callback", libredcuba!*); 
for i := 0:32 do
   call!-foreign!-function(register_callback, 'int32, i, 'int64, get!-callback(i));

% =====================================================================================
%  Single procedure interfacing to all algorithms
% =====================================================================================

% Decode the 'fail' code returned by cuba_int(...).
procedure decode(r);
   begin;
      return 
	 if r = 0 then "Success"
      	 else if r = -1 then "Dimension out of range!"
      	 else if r = -2 then "Invalid parameters!"
      	 else "Could not attain the specified accuracy!";
   end;

% 'cuba_int' returns a list {value, error, prob, num regions, num eval, status}.
% We deal with this list by making the C 'cuba_int' set a static variable
% (array) which we then read via procedure 'get_result!*'.
procedure cuba_int(integrand,bounds,alg);
   begin scalar savedmode, n, lb, ub, b1, Clb, Cub, r;
      if not getd(integrand) then
	 rederr {"'", integrand, "' is not defined!"};
      if member(alg, cuba_algorithms!*) then <<
	 % Here 'alg' and 'integrand' are symbols/identifiers. We need their
	 % names (strings).
	 call!-foreign!-function(set_alg!*, 'string, symbol!-name alg);
	 call!-foreign!-function(set_integrand!*, 'string, symbol!-name integrand);
      >>
      else
      <<
	 prin2 "Known algorithms are ";  prin2t cuba_algorithms!*;
	 rederr {"Unknown algorithm ", alg};
      >>;
      % rounded mode is necessary for the code in 'alg_intf.red' to work!
      if not !*rounded then <<
      	 savedmode := t;  on rounded
      >>;
      % What follows is tricky, and all of it is to handle the doubly-nested
      % list 'bounds'.
      % When cuba_int(...) is invoked from algebraic mode, say by
      %    cuba_int(f1,{{0.1,1},{0.2,11.0},{0.3,111.1}},Vegas);
      % the list passed to 'bounds' will be converted to fully-simplified algebraic form
      % (see sec. 5.2.2 of primer), which looks like this:
      %    (list (list (quotient 1 10) 1) (list (quotient 1 5) 11) (list (quotient 3 10) (
      %     quotient 1111 10)))
      % And extracting the numbers from this form takes work! See the procedure to_num()
      % in 'alg_intf.red'.
      if not listp(bounds) then rederr {"list expected!"};
      bounds := cdr bounds;  % remove top-level list tag.
      n := length(bounds);
      if n = 1 then rederr "dimension must be at least 2!";
      cuba_gen_par("ndim",n);
      % Here the best explanation is step-by-step.
      % First try
      %   lb := for each b in bounds collect cadr b, 
      %   ub := for each b in bounds collect caddr b, 
      % and see what you get when you call cuba with 'bounds'
      % (a) a list of integers,
      % (b) a list of reals, or a mixed list.
      % Then see what happens by turning on the switch 'rounded'.
      % Now what is b1?  First the effect of simp:
      % simp 1.1 -> (11 . 10).  simp 0 -> (nil . 1)!
      % And when 'rounded' is on, simp 1.1 -> ((!:rd!: . 1.1) . 1).
      % Then numr extracts the numerators of these quotients.
      % Finally, procedure to_num() in 'alg_intf.red'
      % (a) Checks for atoms. If b is (list 12 13), then in the 
      %     lb code b1 is the atom 12.
      % (b) Handles the fact that the simp turns 0 into the standard quotient (nil . 1).
      lb := for each b in bounds collect <<
	 b1 := numr simp cadr b;
	 to_num(b1)  % no ; here!
      >>;
      ub := for each b in bounds collect <<
	 b1 := numr simp caddr b;
	 to_num(b1)  % no ; here!
      >>;
      Clb := newDoubleArray(n);
      Cub := newDoubleArray(n);
      for i := 0:n-1 do <<
	 setDoubleArray(Clb, i, nth(lb,i+1));
	 setDoubleArray(Cub, i, nth(ub,i+1));
      >>;
      call!-foreign!-function(cuba_int!*, 'int64,Clb, 'int64,Cub);
      freeDoubleArray(Clb);
      freeDoubleArray(Cub);
      r := for i := 1:6 collect 
	 call!-foreign!-function(get_result!*, 'int32,i-1, 'double);
      % r is a Lisp list (value, error, prob, num regions, num eval, return code).
      for i := 4:6 do 
	 nth(r,i) := round(nth(r,i));  % integers
      nth(r,6) := decode(nth(r,6));
      if savedmode then off rounded;
      % Turn r into a Reduce list. See Primer, sec. 3.3.1:
      return 'list . r;
   end;

symbolic operator cuba_int;

endmodule;  % cuba_main

end;  % of file
