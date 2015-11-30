%% Basic utilities of an interface from symbolic Reduce/CSL mode to
%% algebraic mode.

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


module alg_intf;

%% Construct an identifier corresponding to the given name (string).
%% E.g. if the string is "f12", the result is 'f12.
%    intern name;
%% Do the reverse: given an identifier/symbol 'id', return its string name.
%    symbol!-name id;

%% Convert an algebraic form list to a Lisp list.  This procedure must be
%%   (a) INVOKED within 'on rounded'.
%%   (b) its result must be USED within that environment also!
%% See the comments in procedure cuba_int() in cuba/cuba_main.red.
procedure alg_to_lisp_list(a);
   begin scalar y, l;
      % the cdr removes the top-level list tag:
      l := for each x in cdr a collect <<
	 y := numr simp x;
      	 % Handle 0, which is represented by the standard quotient (nil . 1).
      	 y :=
	    if atom y then
	       (if y = nil then 0 else y)
      	    else cdr y  % no ; here!
      >>;
      return l;
   end;


%% Convert the SQ form x (could already be a number) to a number,
%% real or integer. 
%% This procedure must be
%%   (a) INVOKED within 'on rounded'.
%%   (b) its result must be USED within that environment also!

procedure to_num(x);
   begin scalar y;
      y := numr simp x;
      % Handle the fact that 0 is represented by the standard
      % quotient (nil . 1).
      y :=
	 if atom y then
	    (if y = nil then 0 else y)
      	 else cdr y;
      return y;
   end;



%% Evaluate a Reduce call to an algebraic function 'fn' that takes a Reduce list
%% of reals and delivers either a single real or another list of reals.
%% An example where a we use a list as the returned value is in the NLopt interface,
%% rednlopt.c, function red_mfunc_wrap.
%% Awfully tricky!  Needs 'on rounded'.

% ACN explanation: A REDUCE list of floats will have an internal representation
% of the form (list (!:rd!: . 1.111) (!:rd!: . 2.222) (!:rd!: . 3.333)) rather
% than the Lisp version which is simply (1.111 2.222 3.333).  (Anyhow, the
% latter would denote a formula that has the value 1.111 as its leading
% operator; this is most likely an invalid situation).  So I create (fn (list
% (!:rd!: . 1.111) ...  Now to process that and get an algebraic answer I need
% to pass that to the aeval function.  I use errorset, which is a function that
% evaluates something but traps errors, so that if evaluation fails you do not
% lose control.  The extra arguments control how many messages you get on any
% such error.  So what I will evaluate will be a call (aeval (quote (fn (list
% ....  and you see that again to help debug and show what is going on I display
% the raw result that errorset returns.  If that is atomic (the errorp test
% checks for that) here I merely return 0.0.  What is the best thing to do there
% is not clear to me!  Otherwise the CAR of the result of errorset is the actual
% value.  If that is truly a single floating point value as expected, then
% Reduce will have notated that as (!*sq ((!:rd!: . fff) . 1) t).  Now you may
% view that as baroque, but note that when Reduce simplifes a formula the result
% will generally end up as a full algebraic form with variables and operators
% such as trig functions etc left in there, and the representation it uses is
% designed to emcompass all that generality.  For instance the outer (!*sq ...)
% bit helps track when the inner bit remains valid and when it might need to be
% re-simplified because a user has introduced a new LET statement...  So
% cautiously I check that there is !*sq and !:rd!: as predicted.  Finally I
% return the raw floating point number.

% So this procedure manages the interaction between symbolic (Lisp) mode data
% structures and the activation of algebraic mode processing in Reduce, with
% roughly the first half of the function converting in one direction and the
% second converting back.

procedure call_alg_fn_list2list(fn, ll);
   begin scalar w;
      w := list(fn, 'list . for each v in ll collect ('!:rd!: . v));
      % call the algebraic evaluator (Primer, sec. 3.4); result is in *SQ form.
      w := list('aeval, mkquote w);
      %    princ "Thing to evaluate: "; print w;
      w := errorset(w, !*backtrace, !*backtrace);
      %    princ "From errorset: "; print w;
      if errorp w then rederr {"**a",ll,w}; % 0.0;
      w := car w;
      if not eqcar(w, 'list) then <<
       	 % the result of 'fn' is not a list
       	 return process_single(w,ll);
      >>
      else <<
       	 % the result of 'fn' is a list
       	 % An example where this is used is in the NLopt interface, file
       	 % rednlopt.c, function red_mfunc_wrap.
       	 w := cdr w;
       	 return for each y in w collect process_single(y,ll);
      >>
   end;


procedure process_single(z,ll);
   begin;
      if numberp z then return float z;
      z := numr cadr z;
      if not eqcar(z, '!:rd!:) then rederr {"**b",ll,z}; % 0.0;
      return cdr z;
   end;


endmodule;  % alg_intf

end;        % of file
