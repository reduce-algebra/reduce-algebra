% ----------------------------------------------------------------------
% $Id: redfront.red,v 1.11 2006/07/21 11:07:22 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: redfront.red,v $
% Revision 1.11  2006/07/21 11:07:22  sturm
% In redfront_oh call assgnpri with 3rd arg nil instead of 'only.
% Accordingly, read_until_prompt does not eat the first char anymore.
% This fixes 2 bugs: (1) With lisp write "Hallo", the first char did not
% appear. (2) There were two trailing $ with off nat.
% There is a cleaner treatment of control-d in read_valid_line now. Before
% (3) control-d within yesp freed a constant string.
%
% Revision 1.10  2006/06/03 11:34:29  sturm
% Fixed a bug with tensor printing in fide. This is a considerable
% modification of the outputhandler redfront_oh(). It appears that
% not maprin but assignpri() should be considered the canonical entry point
% for printing. This also resolves an old question about the terpri!* t in
% redfront_on(), which has changed to terpri!* nil now.
%
% Revision 1.9  2006/06/02 10:18:12  sturm
% Bug fix for "write 1,2,3".
%
% Revision 1.8  2006/05/19 05:42:48  sturm
% Added support for prin2!*.
% maprin stuff is printed in blue only if it is not combined with prin2!*
% stuff. This avoids linebreaks in typerr.
%
% Revision 1.7  2003/07/02 07:44:45  dolzmann
% Do not color output if it is redirected to a file.
%
% Revision 1.6  2003/07/02 07:38:36  sturm
% Changes prefixes.
%
% Revision 1.5  2003/06/27 12:12:22  sturm
% (x+1)**20 did not work.
%
% Revision 1.4  2003/06/25 12:06:26  sturm
% Added lithist option.
% acconfig.h and redfront_color.red are obsolete.
%
% Revision 1.3  1999/09/28 15:03:11  sturm
% Removed obsolete Xr coloring in yesp().
%
% Revision 1.2  1999/09/20 14:45:13  sturm
% Implement private PSL yesp() for 3.7.
%
% Revision 1.1  1999/09/20 13:37:53  sturm
% Private autoconf-based REDFRONT development branch by A. Dolzmann
% and T. Sturm.
% Initial check-in.
%
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

lisp <<
   fluid '(redfront_rcsid!* redfront_copyright!*);
   redfront_rcsid!* := "$Id: redfront.red,v 1.11 2006/07/21 11:07:22 sturm Exp $";
   redfront_copyright!* := "(c) 1999 A. Dolzmann and T. Sturm"
>>;


module coloutput;

fluid '(posn!* orig!*);

procedure redfront_oh(m,l);
   begin scalar outputhandler!*;
      if m eq 'maprin then
         if ofl!* or posn!* neq orig!* then
            maprin l
               else <<
            redfront_on();
             assgnpri(l,nil,nil);
            redfront_off()
         >>
      else if m eq 'prin2!* then
         prin2!* l
      else if m eq 'terpri then
         terpri!* l
      else
         rederr {"unknown method ",m," in redfront_oh"}
   end;

procedure redfront_on();
   <<
      terpri!* nil;
      prin2 int2id 3;
      terpri!* nil
   >>;

procedure redfront_off();
   <<
      terpri!* nil;
      prin2 int2id 4
   >>;

procedure redfront_formwrite(u,vars,mode);
   % Workaround to avoid linebreaks with "write 1,2,3". This is based
   % on a patch of the original formwrite(), which TS wanted to avoid.
   begin scalar z;
      z := formwrite(u,vars,mode);
      if null z then return nil;
      return {'cond,
         {{'and,{'eq,'outputhandler!*,'(quote redfront_oh)},'(not ofl!*)},
            {'prog,'(outputhandler!*),'(redfront_on),z,'(redfront_off)}},
         {t,z}}
   end;

put('write,'formfn,'redfront_formwrite);

outputhandler!*:='redfront_oh;

endmodule;  % coloutput;

module redfront;
% Prompt coloring for redfront.
% Written by Andreas Dolzmann and Thomas Sturm, 1998

fluid '(promptstring!* redfront_switches!* redfront_switches!-this!-sl!*
   lispsystem!*);

redfront_switches!* := {!*msg,!*output};

off1 'msg;
off1 'output;

procedure redfront_pslp();
   'psl memq lispsystem!*;

if redfront_pslp() then <<
   redfront_switches!-this!-sl!* := {!*usermode};
   off1 'usermode
>>;

procedure redfront_color(c);
   if stringp c then
      compress('!" . int2id 1 .
               reversip('!" . int2id 2 . cdr reversip cdr explode c))
   else
      intern compress(int2id 1 . nconc(explode c,{int2id 2}));

procedure redfront_uncolor(c);
   if stringp c then
      compress('!" . reversip('!" . cddr reversip cddr explode c))
   else
      intern compress('!! . reversip cdr reversip cdr explode c);

procedure redfront_setpchar!-psl(c);
   begin scalar w;
      w := redfront_setpchar!-orig c;
      promptstring!* := redfront_color promptstring!*;
      return redfront_uncolor w
   end;

procedure redfront_setpchar!-csl(c);
   redfront_uncolor redfront_setpchar!-orig redfront_color c;

copyd('redfront_setpchar!-orig,'setpchar);

if redfront_pslp() then
   copyd('setpchar,'redfront_setpchar!-psl)
else
   copyd('setpchar,'redfront_setpchar!-csl);

procedure redfront_yesp!-psl(u);
   begin scalar ifl,ofl,x,y;
      if ifl!* then <<
         ifl := ifl!* := {car ifl!*,cadr ifl!*,curline!*};
         rds nil
      >>;
      if ofl!* then <<
         ofl:= ofl!*;
          wrs nil
      >>;
      if null !*lessspace then
          terpri();
      if atom u then
          prin2 u
      else
          lpri u;
      if null !*lessspace then
          terpri();
      y := setpchar "?";
      x := yesp1();
      setpchar y;
      if ofl then wrs cdr ofl;
      if ifl then rds cadr ifl;
      cursym!* := '!*semicol!*;
      return x
   end;

if redfront_pslp() then <<
   remflag('(yesp),'lose);
   copyd('redfront_yesp!-orig,'yesp);
   copyd('yesp,'redfront_yesp!-psl);
   flag('(yesp),'lose)
>>;

% Color PSL prompts, in case user falls through:

procedure redfront_compute!-prompt!-string(count,level);
   redfront_color redfront_compute!-prompt!-string!-orig(count,level);

if redfront_pslp() then <<
   copyd('redfront_compute!-prompt!-string!-orig,'compute!-prompt!-string);
   copyd('compute!-prompt!-string,'redfront_compute!-prompt!-string)
>>;

procedure redfront_break_prompt();
   <<
      prin2 "break["; prin2 breaklevel!*; prin2 "]";
      promptstring!* := redfront_color promptstring!*
   >>;

if redfront_pslp() then <<
   copyd('break_prompt,'redfront_break_prompt);
   flag('(break_prompt),'lose);
>>;

if redfront_pslp() then
   onoff('usermode,car redfront_switches!-this!-sl!*);

onoff('msg,car redfront_switches!*);
onoff('output,cadr redfront_switches!*);

crbuf!* := nil;
inputbuflis!* := nil;
lessspace!* := t;
statcounter := 0;

endmodule;

end;
