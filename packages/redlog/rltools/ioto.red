module ioto;  % Input/Output tools

revision('ioto, "$Id$");

copyright('ioto, "(c) 1995-2009 A. Dolzmann, T. Sturm, 2009-2017 T. Sturm");

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
   % stdout. It is expected to work with both "off nat" and "on nat." utf8 is
   % ignored, Fortran printing is not supported, and TeX printing via
   % tri/tri.red has not been considered so far. With "on nat" linelength() is
   % used. Leading and training newlines are trimmed. The "on nat" string prints
   % nicely with prin2t.
   %
   begin scalar outputhandler!*, rlsmaprinbuf!*, !*utf8;
      outputhandler!* := 'ioto_smaprinoh;
      % terpri!*() around maprin appears to be necessary for proper
      % initialization and finalization; compare mathprint in mathpr/mprint.red.
      % We use nil as an argument to supress newlines around our string.
      if !*nat then
 	 terpri!* nil;
      maprin u;
      if !*nat then
 	 terpri!* nil;
      % Trim one trailing newline (and preceding escape char):
      if !*nat then
      	 rlsmaprinbuf!* := cddr rlsmaprinbuf!*;
      return id2string compress reversip rlsmaprinbuf!*
   end;

asserted procedure ioto_smaprinoh(m: Any, l: Any): Any;
   % An output handler for use with ioto_smaprin. It diverts prin2!* output into
   % a the fluid string rlmaprinbuf!*.
   %
   if m eq 'maprin then
      % Recurse and on rely on what is there ...
      maprint(l, 0)
   else if m eq 'prin2!* then
      if !*nat then
	 % With "on nat" nothing is really printed. So we can rely on what is
	 % there. We must lambda bind outputhandler!* to nil to avoind an
	 % infinite recursion. A cleaner solution would be splitting prin2!*
	 % into a wrapper that checks for outputhandler!* and calls a work
	 % horse (as is the case with maprin/maprint above).
	 prin2!* l where outputhandler!* = nil
      else
	 % With "off nat" prin2!* would actually prin2 to stdout. We catch it.
	 % Luckily there is noting sophisticated to do.
      	 for each c in explodec l do
	    ioto_smaprinbuf c
   else if m eq 'terpri then
      % Here is where the actual printing takes place with "on nat." We must
      % catch this.
      ioto_terpri!* l
   else
      % m = 'assignpri might be something to add in the future. TS does not
      % quite understand whether this would be useful or occur naturally.
      rederr {"unknown method ", m, " in redfront_oh"};

asserted procedure ioto_terpri!*(u: Boolean);
   % This is an adapted copy of terpri!*() from mathpr/mprint.red. It would be
   % nicer not to duplicate code.
   %
   begin integer n;
      if testing!-width!* then
 	 return overflowed!* := t;
      if !*fort then
 	 rederr "ioto_smaprin: Fortran output not supported";
      if !*nat and pline!* then <<
	 pline!* := reverse pline!*;
	 for n := ymax!* step -1 until ymin!* do <<
	    ioto_scprint(pline!*, n);
	    ioto_smaprinbuf !$eol!$
 	 >>;
	 pline!* := nil
      >>;
      if u then
	 ioto_smaprinbuf !$eol!$;
      posn!* := orig!*;
      ycoord!* := ymax!* := ymin!* := 0
   end;

asserted procedure ioto_scprint(u: List, n: Integer);
   % This is an adapted copy of scprint() from mathpr/mprint.red. It would be
   % nicer not to duplicate code. u is one line of "on nat" output as a list
   % containing strings some compressed encoding of whitespace.
   %
   begin scalar m;
      posn!* := 0;
      for each v in u do <<
	 if cdar v = n then <<
	    m := caaar v - posn!*;
	    if m geq 0 then
 	       for i := 1:m do
		  ioto_smaprinbuf '! ;
	    for each c in explodec cdr v do
	       ioto_smaprinbuf c;
	    posn!* := cdaar v
 	 >>
      >>
   end;

asserted procedure ioto_smaprinbuf(c: Id): List;
   % This flushes characters into our print buffer for later compression into a
   % string. We preceed every char with a quoting exclamation mark. The chars
   % originate from explode c, which behaves like explode rather than like
   % explode2.
   %
   <<
      push('!!, rlsmaprinbuf!*);
      push(c, rlsmaprinbuf!*)
   >>;

endmodule;  % [ioto]

end;  % of file
