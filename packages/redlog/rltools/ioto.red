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
   fluid '(ioto_rcsid!* ioto_copyright!*);
   ioto_rcsid!* := "$Id$";
   ioto_copyright!* := "Copyright (c) 1995-2009 by A. Dolzmann and T. Sturm"
>>;

module ioto;
% Input/Output tools.

fluid '(ioto_realtime!* datebuffer);

ioto_realtime!* := 0;

procedure ioto_prin2(l);
   % Input/Output tools prin2. [l] is an atom or a list. Returns ANY.
   % Prints either the atom [l] or each element in the list [l]
   % without any space between the elements. The output is not
   % buffered.
   ioto_prin21(l,nil,nil,nil);

procedure ioto_tprin2(l);
   % Input/Output tools conditional terpri prin2. [l] is an atom or a
   % list. Returns ANY. Equivalent to [ioto_cterpri();ioto_prin2(l)].
   ioto_prin21(l,t,nil,nil);

procedure ioto_prin2t(l);
   % Input/Output tools prin2 conditional terpri. [l] is an atom or a
   % list. Returns ANY. Equivalent to [ioto_prin2(l);ioto_cterpri()].
   ioto_prin21(l,nil,t,nil);

procedure ioto_tprin2t(l);
   % Input/Output tools conditional terpri prin2 conditional terpri.
   % [l] is an atom or a list. Returns ANY. Equivalent to
   % [ioto_cterpri();ioto_prin2(l);ioto_cterpri()].
   ioto_prin21(l,t,t,nil);

procedure ioto_prtmsg(l);
   % Input/Output tools print message. [l] is an atom or a list.
   % Returns ANY. Prints either the atom [l] or each element in the
   % list [l] seperated by one space between the elements. The output
   % is not buffered. Does before and after the printing an
   % [ioto_cterpri].
   ioto_prin21(l,t,t,t);

procedure ioto_prin21(l,flg1,flg2,spc);
   % Input/Output tools prin2 subroutine. [l] is an atom or a list;
   % [flg1], [flg2], and [spc] are Boolean. Returns ANY.
   <<
      if l and atom l then l := {l};
      if flg1 then ioto_cterpri();
      for each x in l do <<
 	 prin2 x;
 	 if spc then prin2 " "
      >>;
      ioto_flush();
      if flg2 then ioto_cterpri()
   >>;

procedure ioto_cterpri();
   % Input/Output tools conditional terpri. No parameter. Returns ANY.
   % Does a [terpri()] if the cursor is not on the beginning of a
   % line.
   if posn()>0 then
      terpri();

procedure ioto_nterpri(n);
   if posn() + n > linelength nil then
      terpri();

fluid '(fancy!-switch!-on!* fancy!-switch!-off!*);

procedure ioto_cplu(s,c);
   % Input/Output tools conditional plural. [s] is a string; [c] is
   % Boolean. Returns a string. Appends a ``s'' to [s], provided that
   % [c] is non-[nil].
   if c then compress reversip('!" . '!s . cdr reversip explode s) else s;

procedure ioto_realtime();
   % Input/Output tools real time. No parameter. Returns wall clock
   % seconds since previous call.
   begin scalar aa,res;
      aa := ioto_datestamp();
      res := aa - ioto_realtime!*;
      ioto_realtime!* := aa;
      return res
   end;

procedure ioto_flush();
   % Input/Output flush. No parameter. Returns ANY. Flushes the output
   % buffer.
#if (memq 'psl lispsystem!*)
   <<
      flushbuffer out!*;
      channelflush out!*
   >>;
#else
      flush();
#endif

procedure ioto_datestamp();
   % Input/Output datestamp. No parameter. Returns an integer the
   % number of secons since an fixed date.
#if (memq 'psl lispsystem!*)
   <<
      date();
      sys2int wgetv(datebuffer,0)
   >>;
#else
   datestamp();
#endif

procedure ioto_form2str(u);
   begin scalar buf;
      buf := ioto_prtb(buf, '!");
      buf := ioto_form2str1(buf, u, 0);
      buf := ioto_prtb(buf, '!");
      return compress reversip buf
   end;

procedure ioto_prtb(buf, u);
   <<
      for each x in explode2 u do
	 push(x, buf);
      buf
   >>;

procedure ioto_form2str1(b, u, p);
   begin scalar op, infx;
      if atom u then <<
	 b := ioto_prtb(b, u);
	 return b
      >>;
      op := pop u;
      infx := get(op, 'infix);
      if op eq 'minus then <<  % strange one!
	 b := ioto_prtbpar(b, '!(, p, infx);
      	 b := ioto_prtbop(b, op);
	 b := ioto_form2str1(b, pop u, infx);
	 b := ioto_prtbpar(b, '!), p, infx);
	 return b
      >>;
      if infx then <<
	 b := ioto_prtbpar(b, '!(, p, infx);
	 b := ioto_form2str1(b, car u, infx);
	 for each arg in cdr u do <<
	    if op neq 'plus or not eqcar(arg, 'minus) then  % hack
	       b := ioto_prtbop(b, op);
	    b := ioto_form2str1(b, arg, infx)
	 >>;
	 b := ioto_prtbpar(b, '!), p, infx);
	 return b
      >>;
      b := ioto_prtbop(b, op);
      b := ioto_prtb(b, '!();
      for each rargl on u do <<
	 b := ioto_form2str1(b, car rargl, 0);
      	 b := ioto_prtb(b, if cdr rargl then '!, else '!))
      >>;
      return b
   end;

procedure ioto_prtbpar(b, u, p, infx);
   if infx leq p then ioto_prtb(b, u) else b;

procedure ioto_prtbop(b, op);
   <<
      if flagp(op, 'spaced) then
	 b := ioto_prtb(b, '! );
      b := if op eq 'expt then
	 ioto_prtb(b, '!^)
      else
 	 ioto_prtb(b, get(op, 'prtch) or op);
      if flagp(op, 'spaced) then
	 b := ioto_prtb(b, '! );
      b
   >>;

asserted procedure ioto_sxread(s: String): Any;
   % Use the RLISP parser xread in rlisp/xread.red to parse a string. The RLISP
   % syntax within blocks suggests to some extent that !*semicol!* separates
   % expressions in contrast to terminating them. However, xread heavily relies
   % on finally coming across a !*semicol!*. We explicitly append a !*semicol!*
   % to the argument s here and parse only the first expression. That is, the
   % following all parse as (plus x 1):
   % (a) s = "x+1"
   % (b) s = "x+1;"
   % (c) s = "x+1; y;"
   % Unparsed characters like "y" in (c) will have no effect on the parser after
   % termination of ioto_sxread.
   %
   begin scalar peekchar!*;
      % In this particular situation TS feels safer to use {'!;} instead of
      % '(!;) although the latter should be fine.
      peekchar!* := nconc(explodec s, {'!;});
      return xread t
   end;

asserted procedure ioto_smaprin(u: List): String;
   % This function is a variant of mathprint that prints into strings instead of
   % stdout. At the present stage it forces "off nat" output.
   %
   begin scalar outputhandler!*, rlsmaprinbuf!*, !*nat;
      outputhandler!* := 'ioto_smaprinoh;
      maprin u;
      return id2string compress reversip rlsmaprinbuf!*
   end;

asserted procedure ioto_smaprinoh(m: Any, l: Any): Any;
   % An output handler to divert prin2!* output into a the fluid string
   % rlmaprinbuf!* for use with ioto_smaprin. This is quite provisional but
   % appears to work in the "off nat" situation. TS is a bit worried about not
   % handling m='assignpri.
   %
   if m eq 'maprin then
      maprint(l, 0)
   else if m eq 'prin2!* then
      for each c in explodec l do <<
	 push('!!, rlsmaprinbuf!*);
	 push(c, rlsmaprinbuf!*)
      >>
   else if m eq 'terpri then <<
      push('!!, rlsmaprinbuf!*);
      push(!$eol!$, rlsmaprinbuf!*)
   >> else
      rederr {"unknown method ", m, " in redfront_oh"};

endmodule;  % [ioto]

end;  % of file
