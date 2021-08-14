module clsusi;
% Common logic "super simplifier"

revision('clsusi, "$Id$");

copyright('clsusi, "(c) 1995-2021 A. Dolzmann, T. Sturm");

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

%DS
% <KNOWL> ::= (..., <LAT>, ...)
% <LAT> ::= (<ATOMIC FORMULA> . <LABEL>)
% <LABEL> ::= <INTEGER> | ['ignore]

% Black boxes:
% rl_susipost: post-processing; currently only a hook for Groebner simplification
% rl_susitf: transform; handle sipo, sipw, and similar
% rl_susibin

asserted procedure cl_susimkatl(op: Id, knowl: List, newknowl: List, n: Integer): List;
   % Common logic susi make atomic formula list. [op] is one of the
   % operators [and], [or]; [knowl], [newknowl] are KNOWL's; [n] is an
   % integer. Returns a list $L$ of atomic formulas. All knowledge
   % tagged with [n] is extraced from [newknowl] into $L$.
   begin scalar res;
      res := for each pair in newknowl join
	 if cdr pair = n then {car pair};
      if null res then return nil;
      res := rl_susipost(res, knowl);  % TRUE | FALSE | INCTHEO | atl
      if rl_tvalp res then
	 return {cl_cflip(res, op eq 'and)};
      if res eq 'inctheo then 	              % Das hatte man auch frueher
	 return cl_cflip('false, op eq 'and);  % wissen koennen.
      if op eq 'or then
      	 res := for each at in res collect rl_negateat at;
      res := for each at in res collect rl_susitf(at, knowl);
      return res
   end;

asserted procedure cl_susicpknowl(knowl: List): List;
   % Common logic susi copy knowledge. [knowl] is a KNOWL. Returns a
   % KNOWL. Copies the toplevel and the LAT's of [knowl].
   for each p in knowl collect (car p . cdr p);

asserted procedure cl_susiupdknowl(op: Id, atl: List, knowl: List, n: Integer): List;
   % Common logic susi update knowledge. [op] is one of the operators
   % [and], [or]; [atl] is a list of (simplified) atomic formulas;
   % [knowl] is a KNOWL; [n] is the current level. Returns a KNOWL.
   % Destructively updates [knowl] wrt. the [atl] information.
   begin scalar at;
      while atl do <<
	 at := pop atl;
      	 knowl := cl_susiupdknowl1(op, at, knowl, n);
	 if knowl eq 'false then <<
	    atl := nil;
	    at := 'break
	 >>
      >>;
      if at eq 'break then
	 return 'false
      else
      	 return knowl
   end;

asserted procedure cl_susiupdknowl1(op: Id, at: Atom, knowl: List, n: Integer): List;
   % Common logic susi update knowledge subroutine. [op] is one of
   % [and], [or]; [at] is a (simplified) atomic formula; [knowl] is a
   % KNOWL; [n] is the current level. Returns a KNOWL. Destructively
   % updates [knowl] wrt. [at].
   if op eq 'and then
      cl_susiupdknowl2((at . n), knowl, n)
   else <<
      ASSERT( op eq 'or );
      cl_susiupdknowl2(((rl_negateat at) . n), knowl, n)
   >>;

asserted procedure cl_susiupdknowl2(lat: DottedPair, knowl: List, n: Integer): List;
   % Common logic susi update knowledge subroutine. [lat] is a LAT;
   % [knowl] is a KNOWL; [n] is the current level. Returns a KNOWL.
   % Destructively updates [knowl] wrt. [lat].
   begin scalar a, w, sck, ignflg, delflg, addl, term;
      sck := knowl;
      while sck do <<
	 a := pop sck;
	 w := rl_susibin(a, lat);  % 'true | 'false | nil | {commands, ...}
	 if w eq 'false then  % What happens with atoms neq false?
	    sck := nil
	 else <<
	    ASSERT( w neq 'true );
	    w := cl_susiinter(w, knowl, a);
	    addl := nconc(addl, cadr w);
	    knowl := car w;
	    if caddr w then
	       ignflg := t;
	    if cadddr w then <<
	       delflg := t;
	       sck := nil
	    >>
	 >>
      >>;
      if w eq 'false then return 'false;
      if null delflg then <<
	 % if ignflg then cdr lat := 'ignore;
	 knowl := lat . knowl
      >>;
      while addl do <<
	 knowl := cl_susiupdknowl2(car addl, knowl, n);
	 if knowl eq 'false then
	    addl := nil
	 else
	    addl := cdr addl
      >>;
      return knowl;
   end;

asserted procedure cl_susiinter(prg: List, knowl: List, a: DottedPair): List4;
   % Common logic susi interpreter. [prg] is a SUSIPRG; [knowl] is a KNOWL; [a]
   % is a LAT. Returns a list $(\kappa,\alpha,\iota,\delta)$, where $\kappa$ and
   % $\alpha$ are KNOWL's; $\iota$ and $\delta$ are flags.
   begin scalar addl, ignflg, delflg;
      for each p in prg do
	 if car p eq 'delete or car p eq 'ignore then
%%       	 if car p eq 'ignore then
%% 	    if cdr p then <<
%% 	       ignflg := T;
%% 	       addl := cdr p . addl;
%% 	    >> else
%% 	       cdr a := 'ignore
%%       	 else if car p eq 'delete then
	    if cdr p then
	       delflg := t
	    else
	       knowl := lto_delqip(a, knowl)
      	 else if car p eq 'add then
	    addl := cdr p . addl;
     return {knowl, addl, ignflg, delflg}
   end;

asserted procedure cl_susiminlevel(l1: Atom, l2: Atom): Atom;
   if l1 eq 'ignore then l2 else if l2 eq 'ignore then l1 else min(l1, l2);

endmodule;

end;
