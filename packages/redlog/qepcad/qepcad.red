% ----------------------------------------------------------------------
% $Id: qepcad.red,v 1.7 1997/08/18 17:29:55 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995, 1996, 1997
% Andreas Dolzmann and Thomas Sturm, Universitaet Passau
% ----------------------------------------------------------------------
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

% $Log: qepcad.red,v $
% Revision 1.7  1997/08/18 17:29:55  sturm
% Changes due to renaming:
%    "rl.red" -> "redlog.red"
%    "rl.tst" -> "redlog.tst"
%    "rl.texi" -> "redlog.texi".
%
% Revision 1.6  1997/03/14 16:42:54  sturm
% Treat truth values in the input correctly.
% Return nil to the AM with optional file name argument.
% Raise a "rederr" if QEPCAD fails.
% Run the interface under "errorset."
%
% Revision 1.5  1996/10/17 13:52:17  sturm
% Introduced services rlvarl, rlfvarl, and rlbvarl. Renamed cl_varl to
% cl_varl1 for this.
%
% Revision 1.4  1996/10/17 12:31:39  sturm
% Moved sconcat2, sconcat, and at2str from qepcad.red to lto.red.
%
% Revision 1.3  1996/07/13 11:25:12  dolzmann
% Fixed a bug in qepcad_qepcad: Proper treatment of calling qepacd
% without output of return value.
%
% Revision 1.2  1996/04/30 12:11:29  sturm
% Added create!-package statement.
%
% Revision 1.1  1996/03/22 12:16:33  sturm
% Moved. Added rl_set call.
%
% Revision 1.4  1996/03/18 15:47:00  sturm
% Moved rl operator classification predicates to module rl.
%
% Revision 1.3  1996/03/09 13:36:33  sturm
% Adapted the (now) rl access functions and cl predicates to the new
% names.
%
% Revision 1.2  1995/12/06  11:04:51  sturm
% Made results available to Reduce.
% Added proper treatment of the switches rlverbose and time.
%
% Revision 1.1  1995/08/30  08:15:51  sturm
% Initial check-in.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(qepcad_rcsid!* qepcad_copyright!*);
   qepcad_rcsid!* := "$Id: qepcad.red,v 1.7 1997/08/18 17:29:55 sturm Exp $";
   qepcad_copyright!* :=
      "Copyright (c) 1995, 1996, 1997 by A. Dolzmann and T. Sturm, Universitaet Passau"
>>;


module qepcad;

create!-package('(qepcad),nil);

load!-package 'redlog;
load!-package 'ofsf;
load!-package 'rltools;

fluid '(!*rlqepnf !*rlverbose !*echo !*time !*backtrace);

put('ofsf,'rl_services,
   '(rl_qepcad!* . qepcad_qepcad) . get('ofsf,'rl_services));

rl_mkserv('qepcad,'(rl_simp),'(reval),'(nil),
   function(lambda x; if x then rl_mk!*fof x),T);

rl_set '(ofsf);

procedure qepcad_qepcad(f,fn);
   begin scalar w,oldpprifn,oldprtch,scsemic,oldecho;
      oldpprifn := get('times,'pprifn);
      oldprtch := get('expt,'prtch);
      scsemic := semic!*;
      oldecho := !*echo;
      w := errorset({'qepcad_qepcad1,mkquote f,mkquote fn},T,!*backtrace);
      if errorp w then <<
      	 put('times,'pprifn,oldpprifn);
      	 put('expt,'prtch,oldprtch);
      	 semic!* := scsemic;
	 !*echo := oldecho;
      	 if w neq 99 then
	    rederr w;
	 % CTRL-C
	 return nil
      >>;
      return car w
   end;

procedure qepcad_qepcad1(f,fn);
   begin scalar w,free,oldprtch,oldpprifn,fn1,fn2,fh,result,oldecho,scsemic;
      scsemic := semic!*;
      fn1 := fn or lto_sconcat{"/tmp/",getenv "USER",".qepcad"};
      if null fn then
      	 fn2 := lto_sconcat{"/tmp/",getenv "USER",".qepcad2red"};
      if !*rlverbose then ioto_prin2 {"+++ creating ",fn1," ... "};
      oldpprifn := get('times,'pprifn);
      put('times,'pprifn,'qepcad_ppricadtimes);
      oldprtch := get('expt,'prtch);
      put('expt,'prtch,'!^);
      if !*rlqepnf then f := cl_pnf f;
      w := cl_varl1 f;
      free := length car w;
      if null cdr w then
	 rederr "no quantifier";
      w := nconc(reversip car w,reversip cdr w);
      out(fn1);
      prin2t "[]";
      prin2 "(";
      prin2 car w;
      for each x in cdr w do << prin2 ","; prin2 x >>;
      prin2t ")";
      prin2t free;
      terpri!* nil;
      qepcad_cadprint1 f;
      terpri!* nil;
      prin2t ".";
      prin2t "finish";
      shut(fn1);
      put('times,'pprifn,oldpprifn);
      put('expt,'prtch,oldprtch);
      if !*rlverbose then ioto_prin2 "done";
      if null fn then <<
      	 system lto_sconcat{"qepcad < ",fn1," | gawk -v rf=",fn2,
	    " -v verb=",lto_at2str !*rlverbose," -v time=",
	       lto_at2str !*time," -f qepcad.awk"};
	 oldecho := !*echo;
	 !*echo := nil;
	 fh := rds open(fn2,'input);
	 result := xread t;
	 close rds fh;
	 !*echo := oldecho;
	 system lto_sconcat{"rm -f ",fn1," ",fn2};
	 if null result then
	    rederr "qepcad failed";
	 result := rl_simp result
      >>;
      semic!* := scsemic:
      return result
   end;

procedure qepcad_cadprint1(f);
   begin scalar op,!*nat;
      op := rl_op f;
      if op eq 'ex then <<
	 prin2!* {"E",rl_var f};
	 prin2!* " ";
	 return qepcad_cadprint1 rl_mat f
      >>;
      if op eq 'all then <<
	 prin2!* {"A",rl_var f};
	 prin2!* " ";
      	 return qepcad_cadprint1 rl_mat f
      >>;
      prin2!* "[";
      qepcad_cadprint2 f;
      prin2!* "]"
   end;

procedure qepcad_cadprint2(f);
   begin scalar op,argl;
      op := rl_op f;
      if rl_cxp op then <<
	 if rl_tvalp op then <<
	    qepcad_cadprinttval f;
	    return nil
	 >>;
	 prin2!* "[";
	 argl := rl_argn f;
	 qepcad_cadprint2(car argl);
	 for each x in cdr argl do <<
	    qepcad_cadprintop op;
	    qepcad_cadprint2 x
	 >>;
	 prin2!* "]";
	 return nil
      >>;
      maprin prepf ofsf_arg2l f;
      qepcad_cadprintop op;
      prin2!* "0";
      return nil
   end;

procedure qepcad_cadprinttval(tv);
   if tv eq 'true then <<
      prin2!* "0";
      qepcad_cadprintop 'equal;
      prin2!* "0"
   >> else <<  % [tv eq 'false]
      prin2!* "0";
      qepcad_cadprintop 'neq;
      prin2!* "0"
   >>;

procedure qepcad_cadprintop(op);
   <<
      prin2!* " ";
      prin2!* cdr atsoc(op,'((equal . "=") (neq . "/=") (lessp . "<")
      	 (greaterp . ">") (geq . ">=") (leq . "<=") (or . "\/") (and . "/\")
      	    (impl . "==>") (equiv . "<==>")));
      prin2!* " "
   >>;

procedure qepcad_ppricadtimes(f,n);
   begin scalar w;
      w := (get(car f,'infix) < n);
      if w then prin2!* "(";
      maprin cadr f;
      for each x in cddr f do << prin2!* " "; maprin x >>;
      if w then prin2!* ")"
   end;

endmodule;

end;
