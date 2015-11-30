
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

symbolic procedure mkgroup;
   %Expects a list of statements terminated by a >>;
   begin scalar lst,delim;
    a:      lst := aconc(lst,xread 'group);
        if cursym!* eq '!*rsqb!* then go to b
         else if null delim then delim := cursym!*
         else if not(delim eq cursym!*)
          then symerr("Syntax error: mixed , and ; in group",nil);
        go to a;
    b:  scan();
        return if delim eq '!*semicol!* then 'progn . lst
                else 'vect . lst
   end;

put('!*lsqb!*,'stat,'mkgroup);

newtok '((![) !*lsqb!*);

newtok '((!]) !*rsqb!*);

symbolic procedure formvect(u,vars,mode);
   begin integer n; scalar v;
      u := for each x in u collect form1(x,vars,mode); % was FORMC
      v := mkvect(length u-1);
      n := 0;
      for each x in u do <<putv(v,n,x); n := n+1>>;
      return v
   end;

put('vect,'formfn,'formvect);

put('vecexprp,'evfn,'evvector);

symbolic procedure !*!*a2s(u,vars);
   if u = '(quote nil) then nil
%   else if eqcar(u,'for) and not(cadddr u eq 'do)
%    then list('foraeval,u)
    else if vectorp u then list(!*!*a2sfn,u)
    else if null u or constantp u and null fixp u
      or intexprnp(u,vars) and null !*composites
      or not atom u and idp car u
         and flagp(car u,'nochange) and not(car u eq 'getel)
     then u
    else list(!*!*a2sfn,u);

symbolic procedure vecexprp u;
   % Determines if U is a valid vector expression.
   if vectorp u then t
    else if atom u then nil
    else if car u eq 'plus then vecexprlisp cdr u
    else if car u eq 'times then onevecexprlisp cdr u
    else if car u eq 'minus then vecexprp cadr u
    else if car u eq 'quotient
     then vecexprp cadr u and not vecexprp caddr u
    else nil;

symbolic procedure vecexprlisp u;
   null u or vecexprp car u and vecexprlisp cdr u;

symbolic procedure onevecexprlisp u;
   if null u then nil
    else if vecexprp car u then notvecexprlisp cdr u
    else onevecexprlisp cdr u;

symbolic procedure notvecexprlisp u;
   null u or not vecexprp car u and notvecexprlisp cdr u;

symbolic procedure evvector(u,v);
   % Simplification function for a vector expression.
   if vectorp u then evvect(u,nil,nil)
    else nil;

symbolic procedure evvect(u,opr,arg);
   begin integer n; scalar v;
      n := upbv u;
      v := mkvect n;
      for i := 0:n do putv(v,i,
                           reval if null opr then getv(u,i)
                                  else list(opr,getv(u,i),arg));
      return v
   end;

end;

