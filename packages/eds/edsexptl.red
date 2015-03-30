module edsexptl;

% Experimental (algebraic mode) operators

% Author: David Hartley

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


% These procedures need the other packages loaded during compilation

load_package 'xideal;

%%%% Characteristic variety, symbol relations and symbol matrix

COMMENT. At present, algebraic routines.

endcomment;

fluid '(!*varopt !*arbvars xvars!* !*allbranch);


symbolic operator indexnames;
symbolic procedure indexnames u;
   begin
   u := makelist uniqids foreach k in getrlist u collect !*a2k k;
   apply1('indexrange,{{'equal,gensym(),u}});
   return u;
   end;


algebraic procedure symbol_relations(s,name);
   % S:eds, name:id -> symbol_relations:list of 1-form
   begin scalar tbl,ix,sys,pis,!*varopt,!*arbvars;
   pform name(i,j) = 1;
   tbl := tableau s;
   ix := indexnames independence s;
   for i:=1:first length tbl do
      indexrange !!symbol!!index=i;
   pis := for i:=1:first length tbl collect
      foreach j in ix collect name(i,-j);
   sys := for i:=1:first length tbl join
      for j:=1:length ix collect (tbl(i,j) - part(pis,i,j));
   pis := foreach l in pis join l;
   sys := first solve(sys,append(cobasis s,pis));
   sys := foreach x in sys join
      if lhs x member pis then {lhs x - rhs x} else {};
   return sys;
   end;


algebraic procedure symbol_matrix(s,name);
   % S:eds, name:id -> symbol_matrix:matrix of 0-form
   begin scalar sys,wlist,n;
   pform name(i) = 0,{!!symbol!!pi(i,j),!!symbol!!w(i)}=1;
   n := first length tableau s;
   wlist := for i:=1:n collect !!symbol!!w(i);
   sys := symbol_relations(s,!!symbol!!pi);
   rl := for i:=1:n join
      foreach j in indexnames independence s collect
          make_rule(!!symbol!!pi(i,-j),!!symbol!!w(i)*name(-j));
   let rl;
%   sys := (sys where rl);
   sys := sys;
%   write showrules !!symbol!!pi;
   clearrules rl;
   matrix !!symbol!!mat(length sys,length wlist);
   for i:=1:length sys do
      for j:=1:length wlist do
         !!symbol!!mat(i,j) := coeffn(part(sys,i),part(wlist,j),1);
   return !!symbol!!mat;
   end;


algebraic procedure characteristic_variety(s,name);
   % S:eds, name:id -> characteristic_variety:{list of 0-form,list of
   % variable}
   begin scalar ix,m,sys;
         scalar xvars!*;  % make all 0-forms coefficients
   ix := indexnames independence s;
   m := symbol_matrix(s,name);
   if first length m > second length m then m := tp m;
   for i:=1:second length m do
      indexrange symbol!!index!!=i;
   wlist := for i:=1:second length m collect !!symbol!!w(i);
   www := 1;
   for i:=1:first length m do
      www := (for j:=1:length wlist sum m(i,j)*!!symbol!!w(j))^www;
   return {excoeffs www,foreach i in ix collect name(-i)};
   end;


algebraic procedure make_rule(lh,rh);
   lh => rh;


%%% Invariants, or first integrals.

fluid '(!*edsdebug print_ fname_ time_ xvars!* !*allbranch !*arbvars);


mkform!*('eds!:t,0);

algebraic procedure edsorderp(x,y);
   % Just a hook for sort
   if ordp(x,y) then 1 else 0;

put('invariants,'psopfn,'invariants);

symbolic procedure invariants u;
   if length u = 2 then
      (algebraic invariants0(x,y)) where x=car u, y=cadr u
   else if length u = 1 then
      (algebraic invariants0(x,y)) where x=car u, y=makelist nil
   else
      rederr "Wrong number of arguments to invariants";


algebraic procedure invariants0(s,c);
   begin scalar ans,inv,cfrm,z,xvars!*;
   load_package odesolve,crack;
   % Update for CRACK version 1-Dec-2002
   setcrackflags();
   cfrm := coframing();
   if part(s,0) = eds then
   << set_coframing s;
      if c = {} then c := coordinates s;
      s := systemeds s >> % Use systemeds rather than system for
                          % compiler.
   else
      s := xauto s;
   if c = {} then c := reverse sort(coordinates s,edsorderp);
   z := for a:=1:length s collect lisp mkform!*(mkid('eds!:u,a),0);
   ans := foliation(s,c,z);
   inv := solve(ans,z);
   if length z = 1 then
      inv := foreach x in inv collect {x};
   if lisp !*edsdebug then write "Constants";
   if lisp !*edsdebug then write inv;

   if length inv neq 1 then
      rederr "Not a unique solution";

   set_coframing cfrm;
   return foreach x in first inv collect rhs x;
   end;


algebraic procedure foliation(s,c,z);
   begin scalar r,n,x,s0,z0,g,q,f,f0;
               scalar print_,fname_,time_,!*allbranch,!*arbvars,xvars!*;
   % Constants
   r := length s;
   n := length c;
   fname_ := 'eds!:c;
   % Deal with errors and end case
   if r > n then
      rerror(eds,000,"Not enough coordinates in foliation");
   if r neq length z then
      rerror(eds,000,"Wrong number of invariant labels in foliation");
   if r = n then
   << g := for a:=1:r collect part(c,a) = part(z,a);
      lisp edsdebug("Intermediate result",g,'prefix);
      return g >>;
   % Choose truncation
   s0 := {}; z0 := {};
   while length s0 < r do
   << x := first c;
      c := rest c;
      z0 := x . z0;
      s0 := xauto(s xmod {d x}) >>;
   c := append(c,rest z0);
   lisp edsdebug("Truncating coordinate : ",x,'prefix);
   % Compute foliation for truncation
   g := foliation(s0,c,z);
   % Calculate ODE
   foreach y in z do
   << lisp(y := !*a2k y); fdomain y=y(eds!:t) >>;
   s := pullback(s,g);
   s := pullback(s,{x = eds!:t});
   q := foreach f in s collect @eds!:t _| f;
   q := solve(q,foreach y in z collect @(y,eds!:t));
   if r neq 1 then q :=  first q;
   q := foreach f in q collect (lhs f - rhs f);
   q := sub(partdf=df,q);
   lisp edsdebug("CRACK ODE",q,'prefix);
   % Solve ODE
   q := crack(q,{},z,{});
   % Restore 0-form properties of Z (cleared by CRACK)
   foreach y in z do
      << lisp(y := !*a2k y); lisp mkform!*(y, 0) >>;
   lisp edsdebug("CRACK solution",q,'prefix);
   % Analyse result for the general solution
   f := {};
   while q neq {} do
   << f := first q; q := rest q;
      z0 := third f;
      if first f = {} and length z0 = r then q := {}
      else if length z0 > r then
               if length(f0 := solve(first f,z)) = 0 then f := {}
               else
               << if r = 1 then f0 := {{first f0}};
            z0 := foreach v in z0 join
               if v member z then {} else {v};
            f := {{},append(second f,first f0),z0};
             q := {} >>
      else f := {} >>;
   foreach y in z do
      << lisp(y := !*a2k y); remfdomain y >>;
   if f = {} then
      rerror(eds,000,"Intermediate ODE general solution not found");
   % Compose general solution with truncated foliation
   g := sub(second f,g);
   f := (eds!:t = x) . for a := 1:r collect part(z0,a) = part(z,a);
   g := sub(f,g);
   lisp edsdebug("Intermediate result",g,'prefix);
   return g;
   end;


%%% Homotopy operator

algebraic procedure poincare df;
   % with df a closed p-form POINCARE returns a (p-1)-form f
   % satisfying df=d f.
   begin scalar f;
   pform !!lambda!! = 0;
   f := sub(for each c in coordinates df collect c = c * !!lambda!!,df);
%   f := sub(for each c in allcoords df collect c = c * !!lambda!!,df);
   f := @(!!lambda!!) _| f;
   f := int(f,!!lambda!!);
   f := sub(!!lambda!! = 1,f) - sub(!!lambda!! = 0,f);
%   if d f - df neq 0 then write "error in POINCARE";
   return reval f;
   end;


%%% Integrability conditions

put('integrability,'rtypefn,'quotelist);
put('integrability,'listfn,'evalintegrability);

symbolic procedure evalintegrability(s,v);
   % s:eds|rlist, v:bool -> evalintegrability:rlist
   if edsp(s := reval car s) then
      !*sys2a1(nonpfaffpart eds_sys edscall closure s,v)
   else
      algebraic append(s xmod one_forms s,d s xmod one_forms s);

endmodule;

end;
