% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 2014 T. Sturm
% ----------------------------------------------------------------------
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

module smtread;

global '(!$eof!$);
global '(!$eol!$);
global '(crbuf!*);
global '(crbuf1!*);
global '(crchar!*);
global '(curline!*);
global '(cursym!*);
global '(eof!*);
global '(ifl!*);
global '(nxtsym!*);
global '(outl!*);
global '(ttype!*);

fluid '(!*quotenewnam);
fluid '(!*raise);

% Values in ttype!*:
% 0  symbol                   a, b, c, word, !+
% 1  string                   "something"
% 2  number                   1, 2, 1.0, 2.0
% 3  operator-like character  +, -, ...
% 4  result of quotation      '(something)

% The function TOKEN defined below is used for reading identifiers
% and reserved characters (such as parentheses and infix operators).
% It is called by the function SCAN, which translates reserved
% characters into their internal name, and sets up the output of the
% input line.  The following definitions of TOKEN and SCAN are quite
% general, but also inefficient.  The reading process can often be
% speeded up considerably if these functions (especially token) are
% written in terms of the explicit LISP used.

algebraic operator _;

procedure smts_prin2x(u);
  outl!* := u . outl!*;

procedure smts_mkstrng(u);
   % Converts the uninterned id U into a string. If strings are not constants,
   % this should be replaced by list('string,u).
   u;

procedure smts_readch1();
   begin scalar x;
      if null terminalp() then <<
	 x := readch();
	 x eq !$eol!$ and (curline!* := curline!*+1);
	 return x
      >> else if crbuf1!* then <<
 	 x := car crbuf1!*;
 	 crbuf1!* := cdr crbuf1!*
      >> else
 	 x := readch();
      crbuf!* := x . crbuf!*;
      return x
   end;

procedure smts_token1();
   begin scalar x, y, z, raise, w; integer n, d, g;
      x := crchar!*;
   a:
      if seprp x then <<  % space, tab, newline, or carriage return
	 x := smts_readch1();
 	 go to a
      >> else if digit x then
      	 return token!-number x
      else if smts_liter x then
      	 go to letter
      else if x eq '!; then
      	 go to coment
      else if x eq '!! then
      	 go to escape
      else if x eq '!' then <<
      	 crchar!* := smts_readch1();
      	 nxtsym!* := mkquote smts_rread();
      	 ttype!* := 4;
      	 return nxtsym!*
      >> else if x eq '!" then
      	 go to string;
      ttype!* := 3;
      if x eq !$eof!$ then <<
 	 crchar!* := '! ;
	 smts_filenderr()
      >>;
      nxtsym!* := x;
   a1:
      if delcp x then
 	 crchar!*:= '!
      else
	 crchar!*:= smts_readch1();
      go to c;
   escape:
      raise := !*raise;
      !*raise := nil;
      y := x . y;
      x := smts_readch1();
      !*raise := raise;
   letter:
      ttype!* := 0;
   let1:
      y := x . y;
      if digit (x := smts_readch1()) or smts_liter x then
 	 go to let1
      else if x eq '!! then
 	 go to escape;
      for each l in y do w := '!! . l . w;
      nxtsym!* := intern compress w;
   b:
      crchar!* := x;
   c:
      return nxtsym!*;
   number:
      ttype!* := 2;
   num1:
      y := x . y;
      z := x;
      x := smts_readch1();
      if digit x or x eq '!. or x eq 'e or z eq 'e then
 	 go to num1;
      y := reversip!* y;
      w := memq('!., y);
      nxtsym!* := if w then <<
	 d := 10 ^ length cdr w;
	 n := compress delqip('!., y);
	 g := gcdn(n, d);
	 {'!/, n/g, d/g}
      >> else
      	 compress  y;
      go to b;
   string:
      raise := !*raise;
      !*raise := nil;
   strinx:
      y := x . y;
      x := smts_readch1();
      if x neq '!" then
 	 go to strinx;
      y := x . y;
      nxtsym!* := smts_mkstrng compress reversip!* y;
      !*raise := raise;
      ttype!* := 1;
      go to a1;
   coment:
      if smts_readch1() neq !$eol!$ then
 	 go to coment;
      x := smts_readch1();
      go to a
   end;

procedure token!-number(x);
   % Read and return a valid number from input. Adjusted by A.C. Norman to be
   % less sensitive to input case and to support hex numbers.
   begin scalar dotp, power, sign, y, z;
      power := 0;
      ttype!* := 2;
   num1:
      if y or null(x eq '!)) then
 	 y := x . y;
      if dotp then
 	 power := power - 1;
    num2:
       if (x := readch1()) eq '!. then
 	  if dotp then
 	     rerror('smtsupp, 3, "Syntax error: improper number")
	  else <<
	     dotp := t;
 	     go to num2
       	  >> else if digit x then
 	     go to num1
       	  else if y = '(!#) and (x eq '!x or x eq '!X) then
 	     go to hexnum
       	  else if x eq '!\ then <<
 	     readch();
 	     go to num2
       	  >> else if null(x eq '!e or x eq '!E) then
 	     go to ret;
       % Case of number with embedded or trailing E.
       dotp := t;
       if (x := readch1()) eq '!- then
 	  sign := t
       else if x eq '!+ then
 	  nil
       else if null digit x then
 	  go to ret
       else
 	  z := list x;
   nume1:
      if null digit(x := readch1()) then
 	 go to nume2;
      z := x . z;
      go to nume1;
   hexnum:
      y := 0;
   hexnum1:
      if not (z := get(x := readch1(), 'hexdigit)) then
 	 go to ret1;
      y := 16*y + z;
      go to hexnum1;
   nume2:
      if null z then
 	 rerror('smtsupp, 4, "Syntax error: improper number");
      z := compress reversip!* z;
      if sign then
 	 power := power - z
      else
 	 power := power + z;
   ret:
      y := compress reversip!* y;
   ret1:
      nxtsym!* := if dotp then
 	 '!:dn!: . (y . power)
      else y;
      crchar!* := x;
      return nxtsym!*
   end;

procedure smts_liter(x);
  liter x or x memq '(!~ !! !@ !$ !% !^ !& !* !_ !- !+ != !< !> !. !? !/);

procedure smts_token();
   % This provides a hook for a faster TOKEN.
   smts_token1();

procedure smts_filenderr();
   begin scalar m;
      eof!* := eof!* + 1;
      if terminalp() then
 	 error1()
      else <<
	 m := if ifl!* then
 	    {"End-of-file read in file", car ifl!*}
	 else
	    "End-of-file read";
 	 error(99, m)
      >>
   end;

procedure smts_ptoken();
   % An explicit reference to OUTL!* is used here.
   begin scalar x;
      x := smts_token();
      if x eq '!) and eqcar(outl!*,'! ) then
 	 outl!* := cdr outl!*;
      smts_prin2x x;
      if not (x eq '!( or x eq '!)) then
 	 smts_prin2x '! ;
      return x
   end;

procedure smts_rread1();
   % Modified to use QUOTENEWNAM's for ids.
   begin scalar x,y;
      x := smts_ptoken();
      if not eqn(ttype!*, 3) then
 	 return if null idp x or null !*quotenewnam
 	    or null(y := get(x,'quotenewnam))
	 then
 	    x
	 else
 	    y
      else if x eq '!( then
 	 return smts_rrdls()
      else if null (x eq '!+ or x eq '!-) then
 	 return x;
      y := smts_ptoken();
      if null numberp y then <<
 	 nxtsym!* := " ";
	 symerr("Syntax error: improper number", nil)
      >> else if x eq '!- then
 	 y := apply('minus, {y});
      % We need this construct for bootstrapping purposes.
      return y
   end;

procedure smts_rrdls();
   begin scalar x,y,z;
   a:
      x := smts_rread1();
      if not eqn(ttype!*, 3) then
 	 go to b
      else if x eq '!) then
 	 return z
      else if null (x eq '!.) then
 	 go to b;
      x := smts_rread1();
      y := smts_ptoken();
      if not eqn(ttype!*, 3) or y neq '!) then <<
	 nxtsym!* := " ";
	 symerr("Invalid S-expression", nil)
      >> else
 	 return nconc(z, x);
   b:
      z := nconc(z,list x);
      go to a
   end;

procedure smts_rread();
   <<
      smts_prin2x " '";
      smts_rread1()
   >>;

procedure smts_scan();
   begin scalar x,y;
      if null (cursym!* eq '!*semicol!*) then
 	 go to b;
   a:
      nxtsym!* := smts_token();
   b:
      if null atom nxtsym!* then
 	 go to q1
      else if nxtsym!* eq 'else or cursym!* eq '!*semicol!* then
 	 outl!* := nil;
      smts_prin2x nxtsym!*;
   c:
      if null idp nxtsym!* then
 	 go to l
      else if (x := get(nxtsym!*,'newnam)) and x neq nxtsym!* then
 	 go to new
      else if nxtsym!* eq '!; and eqn(ttype!*, 3) then
 	 go to comm
      else if null(ttype!* = 3) then
         go to l
      else if nxtsym!* eq !$eof!$ then
         return smts_filenderr()
      else if nxtsym!* eq '!' then
         go to quote
      else if not (x := get(nxtsym!*,'switch!*)) then
         go to l
      else if eqcar(cdr x,'!*semicol!*) then
         go to delim;
   sw1:
      nxtsym!* := smts_token();
      if not eqn(ttype!*, 3) then
 	 go to sw2
      else if nxtsym!* eq !$eof!$ then
 	 return smts_filenderr()
      else if car x then
 	 go to sw3;
   sw2:
      cursym!*:=cadr x;
      if cursym!* eq '!*rpar!* then
 	 go to l2
      else
 	 return cursym!*;
   sw3:
      y := atsoc(nxtsym!*,car x);
      if not y then
 	 go to sw2;
      smts_prin2x nxtsym!*;
      x := cdr y;
      go to sw1;
   comm:
      if delcp crchar!* then
 	 go to com1;
      crchar!* := readch();
      go to comm;
   com1:
      crchar!* := '! ;
      condterpri();
      go to a;
   delim:
      semic!*:=nxtsym!*;
      return (cursym!* := '!*semicol!*);
   new:
      nxtsym!* := x;
      if stringp x then
 	 go to l
      else if atom x then
 	 go to c
      else
 	 go to l;
  quote:
     nxtsym!* := mkquote smts_rread1();
     go to l;
   q1:
      if null (car nxtsym!* eq 'string) then
 	 go to l;
      smts_prin2x " ";
      smts_prin2x cadr(nxtsym!* := mkquote cadr nxtsym!*);
   l:
      cursym!*:=nxtsym!*;
   l1:
      nxtsym!* := smts_token();
      if nxtsym!* eq !$eof!$ and ttype!* = 3 then
 	 return smts_filenderr();
   l2:
      if numberp nxtsym!* or (atom nxtsym!* and null get(nxtsym!*,'switch!*)) then
 	 smts_prin2x " ";
      return cursym!*
   end;

endmodule;

end;
