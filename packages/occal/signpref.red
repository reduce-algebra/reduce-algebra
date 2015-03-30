
% Author: Rainer Schöpf 

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

COMMENT

The code in this file implements determination of signs of expressions;


fluid '(sign!-db!*);

fluid '(int!?);

symbolic procedure sign!-check u;
  begin scalar x;
    x := assoc(u,sign!-db!*);
    if not null x then return if numberp cdr x then cdr x else nil;
    if null int!? then return;
    x := ask!-sign u;
    sign!-db!* := (u . x) . sign!-db!*;
    if numberp x then return x;
  end;

symbolic operator sign!-check;

symbolic procedure ask!-sign u;
   begin scalar c;
     write "What is the sign of:";
     terpri();
     mathprint u;
     write "Please answer '+', '-', or 'n' (for 'unknown')";
     c := read!-char!-from!-terminal();
     return if c eq '!+ then 1
             else if c eq '!- then -1
             else nil
  end;

symbolic procedure read!-char!-from!-terminal;
   begin scalar c;
     repeat
       c := int2id channelreadchar 6
        until not seprp c;
     return c
   end;

fluid '(!*uncached);

symbolic procedure sign_eval1(u,int!?);
   <<u := reval {'sign, u};
     if numberp u then u else 'unknown     
   >>
    where !*uncached := t;
  % where sign!-db!* := sign!-db!*;

algebraic procedure sign_assert(x,y);
   <<let sign(x) = y;
     symbolic (sign!-db!* := (x . y) . sign!-db!*);
     0>>;

%algebraic
%(sign_rules :=
%   {
%     sign ~x => (if x>0 then 1 else if x<0 then -1 else 0)
%        when numberp x and impart x=0,
%     sign(-~x) => -sign(x),
%     sign( ~x * ~y) =>  sign x * sign y
%           when numberp sign x or numberp sign y,
%     sign( ~x / ~y) =>  sign x * sign y
%           when numberp sign x or numberp sign y,
%     sign( ~x + ~y) =>  sign x when sign x = sign y,
%     sign( ~x ^ ~n) => 1 when fixp (n/2) and lisp(not !*complex),
%     sign( ~x ^ ~n) => sign x^n when fixp n and numberp sign x,
%     sign( ~x ^ ~n) => sign x when fixp n and lisp(not !*complex),
%     sign(sqrt ~a)  => 1 when sign a=1,
%     sign( ~a ^ ~x) => 1 when sign a=1 and impart x=0,
%     sign(abs ~a)   => 1,
%     sign ~a => rd!-sign a when rd!-sign a
%   })$   % $ needed for bootstap.


algebraic <<
%  sign_rules := append(sign_rules,
   let
                       {sign(~x) => sign!-check x when sign!-check x}
   %);
%  let sign_rules
 >>;

end;
