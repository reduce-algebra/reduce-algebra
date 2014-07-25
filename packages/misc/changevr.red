module changevr;   % Facility to perform CHANGE of independent VARs.

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


%*********************************************************************;
%                   -------------------------------                   ;
%                      C  H  A  N  G  E  V  A  R                      ;
%                   -------------------------------                   ;
%                                                                     ;
%   A REDUCE facility to perform CHANGE of independent VARiable(s)    ;
%   in differential equation (or a set of them).                      ;
%                                                                     ;
%                                                                     ;
%   Author : Gokturk Ucoluk                                           ;
%   Date   : Oct. 1989                                                ;
%   Place  : Middle East Tech. Univ., Physics Dept., Turkey.          ;
%   Email  : A07917 @ TRMETU.BITNET  or   A06794 @ TRMETU.BITNET      ;
%                                                                     ;
%   Version: 1.00                                                     ;
%                                                                     ;
%        ( *** Requires: REDUCE 3.0 or greater *** )                  ;
%        ( *** Requires: Matrix package to be present *** )           ;
%                                                                     ;
%   There exists a document written in LaTeX that explains the        ;
%   package in more detail.                                           ;
%                                                                     ;
%   Keywords : differential equation, change of variable, Jacobian    ;
%                                                                     ;

%*********************************************************************;

create!-package('(changevr),'(contrib misc));

load!-package 'matrix;

fluid '(powlis!* wtl!*);

global '(!*derexp !*dispjacobian);
switch derexp, dispjacobian ;  % on derexp       : Smart chain ruling
                               % on dispjacobian : Displays inverse
                               %                   Jacobian.
symbolic procedure simpchangevar v;
begin scalar u,f,j,dvar,flg;
     dvar := if pairp car v then cdar v else car v.nil;
     v := cdr v;                        % Dvar: list of depend. var
     u :=  if pairp car v then cdar v else car v.nil;
     v := cdr v;                        % u: list of new variables
     if eqcar(car v,'list) then v := append(cdar v,cdr v);
     while cdr v do
       << if caar v neq 'equal
            then rederr "improper new variable declaration";
          f := cdar v . f;  % f: list of entries (oldvar  func(newvrbs))
          v := cdr v >>;    %                           i     i
     v := reval car v;     % v: holds now last expression (maybe a list)
     if length u < length f then  rederr "Too few new variables"
      else if length u > length f then rederr "Too few old variables";
     % Now we form the Jacobian matrix ;
     j := for each entry in f collect
            for each newvrb in u collect
                reval list('df,cadr entry, newvrb);
     j := cdr aeval list('quotient,1,'mat.j);
          % j: holds inverse Jacobian.
     % We have to define the dependencies of old variables to new
     % variables.
     for each new in u do
       for each old in f do
          depend1(new, car old, t);
     % Below everything is perplexed :
     % The aim is to introduce  LET DF(new   ,old   ) = jacobian
     %                                   row    col            row,col
     % With the pairing trick below we do it in one step.
     %  new   : car row,   old   : caar col,   jacobian       : cdr col
     %     row                col                      row,col
     %
     for each row in pair(u,j) do
       for each col in pair(f,cdr row) do
        <<
          let2(list('df,car row,caar col), sqchk cdr col, nil, t);
          if !*dispjacobian and !*msg then
             mathprint list('equal,list('df,car row,caar col),
                            sqchk cdr col)
        >>;
%     flg := !*derexp;
%     !*derexp := t;
     begin scalar !*expanddf; !*expanddf := t; 
     v := changearg(dvar,u,v);

     for each  entry in f do
       v := subcare(car entry, cadr entry, v);
     % now here comes the striking point ... we evaluate the last
     % argument.
     v := simp!* v;
     % Now clean up the mess of LET;
     for each new in u do
       for each old in f do
          << let2(list('df,new,car old), nil, nil, nil);
             let2(list('df,new,car old), nil, t,   nil) >>;
%     !*derexp := flg;
     end;
     return v;
end;

put('changevar,'simpfn,'simpchangevar);

symbolic procedure changearg(f,u,x);
if atom x then x
 else if car x memq f then car x . u
 else changearg(f,u,car x) . changearg(f,u,cdr x);


 symbolic procedure subcare(x,y,z);   % shall be used after changearg ;
 if null z then nil
  else if x = z then y
  else if atom z or get(car z,'subfunc) then z
  else (subcare(x,y,car z) . subcare(x,y,cdr z));


% Updated version of DIFFP.. chain rule handling is smarter. ;
% Example: If F is an operator and R has a implicit dependency on X,
%          declared by a preceding DEPEND R,X .. then the former version
%          of DIFFP, provided in REDUCE 3.3, was such that an algebraic
%          evaluation of    DF(F(R),X)    will evaluate to itself, that
%          means no change will happen. With the below given update this
%          is improved.   If the new provided flag DEREXP is OFF  then
%          the differentiation functions exactly like it was before,
%          but if DEREXP is ON then the chain rule is taken further to
%          yield the result:    DF(F(R),R)*DF(R,X)  .

%% RmS: commented out since it is no longer necessary to redefine diffp

%% remflag('(diffp),'lose);   % Since we want to reload it.
%%
%% symbolic procedure diffp(u,v);
%%    % U is a standard power, V a kernel.
%%    % Value is the standard quotient derivative of U wrt V.
%%    begin scalar n,w,x,y,z,key; integer m;
%%         n := cdr u;     % integer power.
%%         u := car u;     % main variable.
%%         % Take care with noncommuting expressions.
%%         if n>1 and noncomp u
%%           then return addsq(multsq(simpdf {u,v},simpexpt {u,n - 1}),
%%                             multpq(u .** 1,diffp(u . (n - 1),v)))
%%          else if u eq v and (w := 1 ./ 1) then go to e
%%          else if atom u then go to f
%%          %else if (x := assoc(u,dsubl!*)) and (x := atsoc(v,cdr x))
%% %               and (w := cdr x) then go to e   % deriv known.
%%              % DSUBL!* not used for now.
%%          else if (not atom car u and (w:= difff(u,v)))
%%                   or (car u eq '!*sq and (w:= diffsq(cadr u,v)))
%%           then go to c  % extended kernel found.
%%          else if x := get(car u,'dfform) then return apply3(x,u,v,n)
%%          else if x:= get(car u,dfn_prop u) then nil
%%          else if car u eq 'plus and (w := diffsq(simp u,v))
%%           then go to c
%%          else go to h;  % unknown derivative.
%%         y := x;
%%         z := cdr u;
%%     a:  w := diffsq(simp car z,v) . w;
%%         if caar w and null car y then go to h;  % unknown deriv.
%%         y := cdr y;
%%         z := cdr z;
%%         if z and y then go to a
%%          else if z or y then go to h;  % arguments do not match.
%%         y := reverse w;
%%         z := cdr u;
%%         w := nil ./ 1;
%%         % computation of kernel derivative.
%%         repeat <<
%%           if caar y
%%             then w := addsq(multsq(car y,simp subla(pair(caar x,z),
%%                                                     cdar x)),
%%                             w);
%%           x := cdr x;
%%           y := cdr y >>
%%          until null y;
%%     c:  % save calculated deriv in case it is used again.
%%         % if x := atsoc(u,dsubl!*) then go to d
%%         %  else x := u . nil;
%%         % dsubl!* := x . dsubl!*;
%%   % d:   rplacd(x,xadd(v . w,cdr x,t));
%%     e:  % allowance for power.
%%         % first check to see if kernel has weight.
%%         if (x := atsoc(u,wtl!*))
%%           then w := multpq('k!* .** (-cdr x),w);
%%         m := n-1;
%%         % Evaluation is far more efficient if results are rationalized.
%%         return rationalizesq if n=1 then w
%%                 else if flagp(dmode!*,'convert)
%%                      and null(n := int!-equiv!-chk
%%                                            apply1(get(dmode!*,'i2d),n))
%%                  then nil ./ 1
%%                 else multsq(!*t2q((u .** m) .* n),w);
%%     f:  % Check for possible unused substitution rule.
%%         if not depends(u,v)
%%            and (not (x:= atsoc(u,powlis!*))
%%                  or not depends(cadddr x,v))
%%            and null !*depend
%%           then return nil ./ 1;
%%         % Derivative of a dependent identifier; maybe apply chain
%%         % rule.  Suppose u(v) = u(a(v),b(v),...), i.e. given
%%         % depend {u}, a, b, {a, b}, v;
%%         % then (essentially) depl!* = ((b v) (a v) (u b a))
%%         if !*expanddf
%%            and (not (x := atsoc(u,powlis!*)) or not depends(cadddr x,v))
%%            and (x := atsoc(u, depl!*)) and not(v memq (x:=cdr x)) then <<
%%            w := df!-chain!-rule(u, v, x);
%%            go to e
%%         >>;
%%         w := list('df,u,v);
%%         w := if x := opmtch w then simp x else mksq(w,1);
%%         go to e;
%%     h:  % Final check for possible kernel deriv.
%%         if car u eq 'df then <<         % multiple derivative
%%            key:=t;
%%            if cadr u eq v then <<
%%               % (df (df v x y z ...) v) ==> 0 if commutedf
%%               if !*commutedf and null !*depend then return nil ./ 1
%%               else if !*simpnoncomdf and (w:=atsoc(v, depl!*))
%%                  and null cddr w % and (cadr w eq (x:=caddr u))
%%               then
%%                  % (df (df v x) v) ==> (df v x 2)/(df v x) etc.
%%                  % if single independent variable
%%                  <<
%%                     x := caddr u;
%%                     % w := simp {'quotient, {'df,u,x}, {'df,v,x}};
%%                     w := quotsq(simp{'df,u,x},simp{'df,v,x});
%%                     go to e
%%                  >>
%%               >>
%%            else if eqcar(cadr u, 'int) then
%%               % (df (df (int F x) A) v) ==> (df (df (int F x) v) A) ?
%%               % Commute the derivatives to differentiate the integral?
%%               if caddr cadr u eq v then
%%                  % Evaluating (df u v) where u = (df (int F v) A)
%%                  % Just return (df F A) - derivative absorbed
%%                  << w := 'df . cadr cadr u . cddr u;  go to j >>
%%               else if !*allowdfint and
%%                  % Evaluating (df u v) where u = (df (int F x) A)
%%                  % (If dfint is also on then this will not arise!)
%%                  % Commute only if the result simplifies:
%%                  not_df_p(w := diffsq(simp!* cadr cadr u, v))
%%               then <<
%%                  % Generally must re-evaluate the integral (carefully!)
%%                  w := 'df . reval{'int, mk!*sq w, caddr cadr u} . cddr u;
%%                  go to j >>;  % derivative absorbed
%%            %
%%            % Try chain rule for nested derivatives:
%%            % (df (df v x y z ...) a) where v depends on a
%%            %
%%            if !*expanddf and depends(cadr u,v)
%%               and (not (x := atsoc(cadr u,powlis!*)) or not depends(cadddr x,v))
%%              then <<
%%                 if not smember(v, cadr u)
%%                  then <<
%%                   % first check for declared dependency of kernel cadr u on v
%%                   x := assoc(cadr u, depl!*);
%%                   % then if cadr u is not a simple symbol,
%%                   %  check whether anything in cdr cadr u has an explicit
%%                   %  dependency on v by collecting all kernels in cdr cadr u
%%                   y := (not atom cadr u and cdr cadr u and get!-all!-kernels cdr cadr u);
%%                   % but take care to exclude the kernel v when checking dependencies
%% 		  if x and y and ldepends(delete(v,y),v) then <<
%%                	  % possible inconsistent dependencies, do not apply chain rule
%% %                   msgpri("Possible inconsistent dependencies in",u,
%% %                         nil,nil,nil);
%%                     nil >>
%%                    else if x and not(v memq (x:=cdr x))
%%                     % declared indirect dependency, 
%%                     then << w := df!-chain!-rule(u, v, x); go to e>>
%%                    else if y and not smember(v,y)
%%                     % possible indirect dependency of kernel arglist on v
%%                     then << w := df!-chain!-rule(u, v, y); go to e>>
%%                   >>
%%               >>;
%%            if (x := find_sub_df(w:= cadr u . merge!-ind!-vars(u,v),
%%                                            get('df,'kvalue)))
%%                           then <<w := simp car x;
%%                                  for each el in cdr x do
%%                                     for i := 1:cdr el do
%%                                         w := diffsq(w,car el);
%%                                  go to e>>
%%                        else w := 'df . w
%%         >> else if !*df_partial and !*expanddf and not atom cadr u then <<
%%            % Derivative of an algebraic operator u(a(v),...) via the
%%            % chain rule: df(u(v),v) = u_1(a(v),b(v),...)*df(a,v) + ...
%%            x := intern compress nconc(explode car u, '(!! !! !_));
%%            y := cdr u;  w := nil ./ 1;  m := 0;
%%            for each a in y do
%%            begin scalar b;
%%               m:=m+1;
%%               if numr(b:=simp{'df,a,v}) then <<
%%                  z := mkid(x, m);
%%                  put(z, 'simpfn, 'simpiden);
%%                  w := addsq(w, multsq(simp(z . y), b))
%%               >>
%%            end;
%%            go to e
%%         >> else w := {'df,u,v};
%%    j:   if (x := opmtch w) then w := simp x
%%          % At this point nested df's may have been collapsed, so
%%          % we have to consider all dependencies on all variables
%%          % and be very careful about returning zero.
%%          else if not depends(u,v)
%%                  and (not (x:= atsoc(u:=cadr w,powlis!*))
%%                        or not dependsl(cadddr x,cddr w))
%%                  and null !*depend then return nil ./ 1
%%          % do not try to apply the chain rule to cases that are handled earlier
%%          % (i.e. for nested/multiple derivatives, or differentiation of integrals)
%%          % or that may come from inconsistent dependencies, e.g. after
%%          %  depend u(v),a;
%%          % do not replace df(u(v),v) by df(u(v),a)*df(a,v) 
%%          else if !*expanddf and not atom u and null cdddr w
%%                  and not(car u memq '(df int)) and not smember(v,u)
%%                  and (not (x:= atsoc(u,powlis!*)) or not depends(cadddr x,v))
%%           then <<
%%             % first check for declared dependency of kernel u on v
%%             x := assoc(u, depl!*);
%%             % then check whether anything in cdr u has an explicit
%%             % dependence on v by collecting all kernels in cdr u
%%             y := (cdr u and get!-all!-kernels cdr u);
%%             % but take care to exclude the kernel v when checking dependencies
%%             if x and y and ldepends(delete(v,y),v) then <<
%%                % possible inconsistent dependencies, do not apply chain rule
%%                msgpri("Possible inconsistent dependencies in",u,
%%                       nil,nil,nil);
%%                w := mksq(w,1) >>
%%              else if x then
%%                 % declared dependency
%%                 if (v memq (x:=cdr x))
%%                   then w := mksq(w,1)
%%                  else w := df!-chain!-rule(u, v, x)
%%              else if y then
%%               % possible dependency of kernel arglist on v
%%               w := if smember(v,y) then mksq(w,1) else df!-chain!-rule(u, v, y)
%%              else w := mksq(w,1)
%%            >>
%% %         else if !*derexp then
%% %               if atom cadr w then w := mksq(w,1)
%% %                else <<
%%          else if !*derexp and not atom cadr w then <<
%%                    w := nil ./ 1;
%%                    for each m in cdr(if key then cadr u else u) do
%%                      w := addsq(multsq(
%%                             if (x := opmtch (z :=
%%                              'df . if key then (cadr u.derad(m,cddr u))
%%                                     else list(u,m) )) then
%%                              simp x else mksq(z,1),
%%                              diffsq(simp m,v)),
%%                              w)>>
%%          else w := mksq(w,1);
%%       go to e
%%    end;

endmodule;

end;
