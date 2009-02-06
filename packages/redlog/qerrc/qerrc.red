% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 1995-2009 Andreas Dolzmann and Thomas Sturm
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
   fluid '(qerrc_rcsid!* qerrc_copyright!*);
   qerrc_rcsid!* :=
      "$Id$";
   qerrc_copyright!* := "Copyright (c) 1995-2009 A. Dolzmann and T. Sturm"
>>;

module qerrc;

create!-package('(qerrc),nil);

load!-package 'redlog;
load!-package 'ofsf;
load!-package 'rltools;

fluid '(!*rlqepnf !*rlverbose qerrc_torder!* qerrc_tlevel!* qerrc_masmem!*
   semic!*);

switch qcfac,qcgb,qcgen,qcpqe;
on1 'qcfac; on1 'qcgb; off1 'qcgen; off1 'qcpqe;
off1 'rlsimpl;
qerrc_tlevel!* := 2;
qerrc_torder!* := 8;
qerrc_masmem!* := "8000";

rl_mkserv('qerrc,'(rl_simp),'(reval),'(nil),'rl_mk!*fof,T);
rl_serviadd('ofsf,'rl_qerrc!*,'qerrc_qerrc);
rl_updcache();

procedure qerrc_qerrc(f,fn);
   begin scalar w,oldpprifn,fn1,fn2,fn3,oldecho,result,fh,scsemic;
      scsemic := semic!*;
      fn1 := fn or lto_sconcat {"/tmp/",getenv "USER",".qcin"};
      if null fn then <<
      	 fn2 := lto_sconcat {"/tmp/",getenv "USER",".qc2red"};
      	 fn3 := lto_sconcat {"/tmp/",getenv "USER",".qcout"}
      >>;
      if !*rlverbose then ioto_prin2 {"+++ creating ",fn1," ... "};
      oldpprifn := get('times,'pprifn);
      put('times,'pprifn,'qerrc_ppricadtimes);
      if !*rlqepnf then f := cl_pnf f;
      w := cl_varl1 f;
      if null cdr w then
	 rederr "no quantifier";
      w := nconc(reversip car w,reversip cdr w);
      out(fn1);
      prin2t "PRAGMA(TIME).";
      prin2t "BEGIN ";	 
      prin2 "  CGBOPT(LIST(0,";
      prin2 if !*qcfac then 1 else 0;
      prin2 ",0,";
      prin2 if !*qcgb then 2 else 0;      
      prin2 ",0,";
      prin2 qerrc_torder!*;
      prin2 ",";
      prin2 qerrc_torder!*;
      prin2 ",";
      prin2 if !*qcgen then 1 else 0;
      prin2t "));";
      prin2 "  RQEOPTSET(LIST(";
      prin2 if !*rlverbose then qerrc_tlevel!* else -2;
      prin2 ",";
      prin2 if !*qcpqe then 1 else 0;      
      prin2t "));";
      prin2 "  PQPRING(LIST(-1,-1,";
      prin2 qerrc_torder!*;
      prin2t "));";
      prin2t "  phi:=PQIREAD();";
%      prin2t "  PQTEXW(phi);";
      prin2t "  w := PQSIMPLIFY(PQMKPOS(RQEQE(phi)));";
      prin2t "  BLINES(0);";
      prin2t "  SWRITE(""An equivalent quantifier-free formula:"");";
      prin2t "  BLINES(0);";      
      prin2t "  PQPPRT(w);";
      prin2t "  BLINES(0);";      
      prin2t "  SWRITE(""====="");";
%      prin2t "  PQTEXW(w);";	    
      prin2t "END.";
      prin2 "{DOMAIN=INT,VALIS=(";
      prin2 car w;
      for each x in cdr w do << prin2 ","; prin2 x >>;
      prin2t ")}";
      terpri!* nil;
      qerrc_cadprint1 f;
      terpri!* nil;
      prin2t ".";
      shut(fn1);
      put('times,'pprifn,oldpprifn);
      if !*rlverbose then ioto_prin2 "done";
      if null fn then <<
	 ioto_cterpri();
	 if !*rlverbose then
	    system lto_sconcat {"mas -m ",qerrc_masmem!*," -e -E -f ",fn1,
	       " | tee ",fn3}
	 else
	    system lto_sconcat {"mas -m ",qerrc_masmem!*," -e -E -f ",fn1,
	       " > ",fn3};
	 system lto_sconcat {"gawk -v rf=",fn2," -v time=",
	    lto_at2str !*time," -f qerrc.awk ",fn3};
	 oldecho := !*echo;
	 !*echo := nil;
	 fh := rds open(fn2,'input);
	 result := xread t;
	 close rds fh;
	 !*echo := oldecho;
	 system lto_sconcat {"rm -f ",fn1," ",fn2," ",fn3};
	 semic!* := scsemic;
	 return rl_simp result
      >>;
      semic!* := scsemic;
      return rl_simp 'true
   end;

procedure qerrc_cadprint1(f);
   begin scalar op,!*nat;
      op := rl_op f;
      if op eq 'ex then <<
	 prin2!* "E ";
	 prin2!* rl_var f;
	 prin2!* ":";
	 return qerrc_cadprint1 rl_mat f
      >>;
      if op eq 'all then <<
	 prin2!* "all ";
	 prin2!* rl_var f;
	 prin2!* ":";
      	 return qerrc_cadprint1 rl_mat f
      >>;
      prin2!* "(";
      qerrc_cadprint2 f;
      prin2!* ")"
   end;

procedure qerrc_cadprint2(f);
   begin scalar op,argl;
      op := rl_op f;
      if rl_tvalp op then rederr "truthval";
      if rl_cxp op then <<
	 prin2!* "(";
	 argl := rl_argn f;
	 qerrc_cadprint2(car argl);
	 for each x in cdr argl do <<
	    qerrc_cadprintop op;
	    qerrc_cadprint2 x
	 >>;
	 prin2!* ")";
	 return nil
      >>;
      prin2!* "[(";
      maprin prepf ofsf_arg2l f;
      prin2!* ")";
      qerrc_cadprintop op;
      prin2!* "0";
      prin2!* "]";
      return nil;
   end;

procedure qerrc_cadprintop(op);
   <<
      prin2!* " ";
      prin2!* cdr atsoc(op,'((equal . "=") (neq . "<>") (lessp . "<")
      	 (greaterp . ">") (geq . ">=") (leq . "<=") (or . "\/") (and . "/\")
      	    (impl . "==>") (equiv . "<==>")));
      prin2!* " "
   >>;

procedure qerrc_ppricadtimes(f,n);
   begin scalar w;
      w := (get(car f,'infix) < n);
      if w then prin2!* "(";
      maprin cadr f;
      for each x in cddr f do << prin2!* " "; maprin x >>;
      if w then prin2!* ")"
   end;

procedure rlqctorder(tor);
   begin scalar w;
      w := qerrc_torder!*;
      qerrc_torder!*:=tor;
      return w
   end;

procedure rlqctlevel(level);
   begin scalar w;
      w := qerrc_tlevel!*;
      qerrc_tlevel!*:=level;
      return w
   end;

procedure rlqcmasmem(mem);
   begin scalar w;
      w := qerrc_masmem!*;
      qerrc_masmem!*:=mem;
      return w
   end;

symbolic operator rlqctorder;
symbolic operator rlqctlevel;
symbolic operator rlqcmasmem;

endmodule;  % qerrc

end;  % of file
