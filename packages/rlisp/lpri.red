module lpri; % Functions for printing diagnostic and error messages.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

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


fluid '(!*defn !*echo !*fort !*int !*msg !*nat !*protfg errmsg!*);

global '(cursym!* erfg!* ofl!* outl!*);

symbolic procedure lpri u;
   while u do <<
      prin2 car u;
      prin2 " ";
      u := cdr u >>;

symbolic procedure lpriw(u, v);
   begin
      u := u . if v and atom v then list v else v;
      if null ofl!* then <<
% In the simple case where no "out" commands have been used this
% just calls lpri to display a message.
         terpri();
         lpri u;
         terpri() >>
      else <<
         if not (!*fort or not !*nat or !*defn) then <<
% Write the message to the current output unless current output satisfies
% various special conditions.
            terpri();
            lpri u;
            terpri() >>;
% Also write it to the standard output.
         wrs nil;
         lpri u;
         terpri();
         wrs cdr ofl!* >>
   end;


symbolic procedure lprim u;
   !*msg and lpriw("***",u);

symbolic procedure lprie u;
   begin
      scalar x;
     if not !*int then <<
        x := !*defn;
        !*defn := nil>>;
     erfg!* := t;
     lpriw("*****", u);
     if null !*int then !*defn := x
   end;

symbolic procedure printty u;
   begin
      scalar ofl;
      if null !*fort and !*nat then print u;
      if null ofl!* then return nil;
      ofl := ofl!*;
      wrs nil;
      print u;
      wrs cdr ofl
   end;

symbolic procedure rerror(packagename, number, message);
   << errmsg!* := message; rederr message >>;

symbolic procedure rederr u;
   begin if not !*protfg then lprie u; error1() end;

symbolic procedure symerr(u,v);
   begin
      scalar x;
      erfg!* := t;
      if numberp cursym!* or not(x := get(cursym!*,'prtch)) then
         x := cursym!*;
      terpri();
      if !*echo then terpri();
      outl!* := car outl!* . '!$!$!$ . cdr outl!*;
      comm1 t;
      outl!* := reversip!* outl!*;
      while outl!* do <<
         prin2 car outl!*;
         outl!* := cdr outl!* >>;
      terpri();
      if null v then rerror('rlisp,5,u)
      else rerror('rlisp, 6,
         if u then list(x, "invalid", "in", u, "statement")
         else list(x, "invalid"))
   end;

symbolic procedure typerr(u, v);
   rerror('rlisp, 6, list(u, "invalid as", v));

endmodule;

end;
