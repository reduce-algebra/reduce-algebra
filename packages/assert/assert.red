% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2010 Thomas Sturm
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

lisp <<
   fluid '(assert_rcsid!* assert_copyright!*);
   assert_rcsid!* := "$Id$";
   assert_copyright!* := "(c) 2010 T. Sturm"
>>;

module assert;

create!-package('(assert assertcheckfn),nil);

global '(exlist);

fluid '(!*assertcheck !*assertstatistics assertstatistics!* lispsystem!*);

switch assertcheck,assertbreak,assertstatistics;

off1 'assertcheck;
off1 'assertbreak;
on1 'assertstatistics;

macro procedure assert_check(l);
   begin scalar f,origfn,progn,argl,w,w1,w2,w3,w4,w5; integer n;
      f := cadr l;
      if not eqcar(getd f,'expr) then <<
	 lprim {f,"is not an expr procedure - ignoring assert"};
	    return nil
      >>;
      n := length cdr caddr l;
      if (w := get(f,'number!-of!-args)) and not eqn(w,n) then
	 rederr {"bad number of args in ",l};
      origfn := get(f,'assert_origfn);
      if not origfn then  <<
	 origfn := intern gensym();
	 progn := {'copyd,mkquote origfn,mkquote f} . progn;
      	 progn := {'put,mkquote f,''assert_origfn,mkquote origfn} . progn
      >>;
      argl := for i := 1:n collect mkid('a,i);
      w1 := mkquote f;
      w2 := mkquote origfn;
      w3 := 'list . argl;
      w4 := 'list . for each fn in cdr caddr l collect mkquote fn;
      w5 := mkquote cadddr l;
      progn := {'de,f,argl,{'assert_check1,w1,w2,w3,w4,w5}} . progn;
      if 'psl memq lispsystem!* then
      	 progn := {'compile,mkquote {f}} . progn
      else if 'csl memq lispsystem!* then
      	 progn := {'compile,mkquote f} . progn;
      progn := 'progn . reversip progn;
      return progn
   end;

procedure assert_check1(fn,origfn,argl,argtypel,restype);
   begin scalar cfn,w,res,scargtypel,bad; integer n;
      if !*assertstatistics then <<
      	 w := atsoc(fn,assertstatistics!*);
      	 if w then
 	    cadr w := cadr w + 1
      	 else
 	    assertstatistics!* := (fn . {1,0,0}) . assertstatistics!*
      >>;
      scargtypel := argtypel;
      for each a in argl do <<
	 n := n + 1;
	 if (cfn := get(car scargtypel,'assert_checkfn)) and not apply(cfn,{a}) then <<
	    bad := t;
	    assert_error(fn,argtypel,restype,n,car scargtypel,a)
	 >>;
	 scargtypel := cdr scargtypel
      >>;
      res := apply(origfn,argl);
      if (cfn := get(restype,'assert_checkfn)) and not apply(cfn,{w}) then <<
	 bad := t;
	 assert_error(fn,argtypel,restype,0,restype,w)
      >>;
      if !*assertstatistics and bad then <<
      	 w := cdr atsoc(fn,assertstatistics!*);
	 cadr w := cadr w + 1
      >>;
      return res
   end;

procedure assert_error(fn,argtypel,restype,typeno,type,arg);
   begin scalar w,msg;
      if !*assertstatistics then <<
      	 w := cdr atsoc(fn,assertstatistics!*);
	 caddr w := caddr w + 1
      >>;
      msg := if eqn(typeno,0) then
%	 {"result of",fn,"invalid as",type,":",arg}
	 {"assertion",assert_format(fn,argtypel,restype),"violated by result",arg}
      else
%	 {"argument",typeno,"of",fn,"invalid as",type,":",arg};
	 {"assertion",assert_format(fn,argtypel,restype),"violated by",
	    mkid('arg,typeno),arg};
      if !*assertbreak then
	 rederr msg
      else
	 lprim msg
   end;

procedure assert_format(fn,argtypel,restype);
   begin scalar ass;
      ass := explode restype;
      ass := '!! . '!) . '!! . '! . '!! . '!- . '!! . '!> . '!! . '! . ass;
      for each a in reverse argtypel do
	 ass := '!! . '!, . nconc(explode a,ass);
      ass := cddr ass;
      ass := '!! . '!: . '!! . '! . '!! . '!( . ass;
      ass := nconc(explode fn,ass);
      return compress ass
   end;

procedure assert_typedefstat();
   begin scalar type,cfn;
      type := scan();
      scan();
      if flagp(cursym!*,'delim) then <<
	 if not !*assertcheck then
	    return nil;
	 if !*msg then lprim {"type",type,"is not checked"};
      	 return nil
      >>;
      if cursym!* neq 'checked then
	 rederr {"expecting 'checked by' in typedef but found",cursym!*};
      if scan() neq 'by then
	 rederr {"expecting 'by' in typedef but found",cursym!*};
      cfn := scan();
      if not flagp(scan(),'delim) then
	 rederr {"expecting end of typedef but found",cursym!*};
      if not !*assertcheck then
	 return nil;
      return {'put,mkquote type,''assert_checkfn,mkquote cfn}
   end;

put('typedef,'stat,'assert_typedefstat);

operator assert_analyze;

procedure assert_analyze();
   begin scalar headline;
      headline := '(function . (!#calls  !#bad! calls !#assertion! violations));
      assertstatistics!* := sort(assertstatistics!*,
	 function(lambda x,y; ordp(car x,car y)));
      for each pr in headline . assertstatistics!* do <<
	 prin2 car pr;
	 for i := length explode car pr + length explode2 cadr pr : 24 do prin2 " ";
	 prin2 cadr pr;
	 for i := length explode2 caddr pr : 24 do prin2 " ";
	 prin2 caddr pr;
	 for i := length explode2 cadddr pr : 24 do prin2 " ";
	 prin2t cadddr pr
      >>;
      assertstatistics!* := nil
   end;

procedure assert_stat();
   begin scalar fn,argtypel,restype;
      fn := scan();
      if scan() neq '!*colon!* then
	 rederr {"expecting ':' in assert but found",cursym!*};
      argtypel := assert_stat1();
      if scan() neq 'difference or scan() neq 'greaterp then
	 rederr {"expecting '->' in assert but found",cursym!*};
      restype := scan();
      if not flagp(scan(),'delim) then
	 rederr {"expecting end of assert but found",cursym!*};
      if not !*assertcheck then
	 return nil;
      return {'assert_check,fn,'list . argtypel,restype}
   end;

procedure assert_stat1();
   begin scalar argtypel;
      if scan() neq '!*lpar!* then
	 rederr {"expecting '(' in assert but found",cursym!*};
      repeat <<
	 argtypel := scan() . argtypel;
	 scan();
      	 if cursym!* neq '!*comma!* and cursym!* neq '!*rpar!* then
	    rederr {"expecting ',' or ')' in assert but found",cursym!*};
      >> until cursym!* eq '!*rpar!*;
      return reversip argtypel
   end;

put('assert,'stat,'assert_stat);

endmodule;

end;  % of file
