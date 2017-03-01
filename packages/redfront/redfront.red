module redfront;

revision('redfront, "$Id$");

copyright('redfront, "(c) 1999-2009 A. Dolzmannm, T. Sturm, 2010-2017 T. Sturm");

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

global '(statcounter);

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

fluid '(promptstring!* redfront_switches!* redfront_switches!-this!-sl!*
   lispsystem!* breaklevel!* input!-libraries output!-library);

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

global '(redfront_setpchar_redefined!*);

if not redfront_setpchar_redefined!* then
  copyd('redfront_setpchar!-orig,'setpchar);

if redfront_pslp() then
   copyd('setpchar,'redfront_setpchar!-psl)
else
   copyd('setpchar,'redfront_setpchar!-csl);

redfront_setpchar_redefined!* := t;

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

% Support for editline completion

procedure redfront_learncolor(c);
   if stringp c then
      compress('!" . int2id 5 .
               reversip('!" . int2id 6 . cdr reversip cdr explode c))
   else
      intern compress(int2id 5 . nconc(explode c,{int2id 6}));


!#if (memq 'psl lispsystem!*)

fluid '(redfront_l!*);

symbolic procedure redfront_oblist_sub x;
  redfront_l!* := x . redfront_l!*;

symbolic procedure redfront_oblist();
  begin
    scalar redfront_l!*;
    mapobl function redfront_oblist_sub;
    return redfront_l!*;
  end;

!#else

symbolic procedure redfront_oblist(); oblist();

!#endif

procedure redfront_swl();
   begin scalar swl;
      swl := for each x in redfront_oblist() join if flagp(x,'switch) then {x};
      return sort(swl,'ordp)
   end;

procedure redfront_send!-switches();
   <<
      for each sw in redfront_swl() do
	 prin2t redfront_learncolor sw;
      statcounter := statcounter - 1;
      nil
   >>;

procedure redfront_modl();
   begin scalar libl,l;
      if redfront_pslp() then
      	 return nil;
      libl := input!-libraries;
      if output!-library then
	 libl := output!-library . libl;
      l := for each x in libl join library!-members x;
      return sort(l,'ordp)
   end;

procedure redfront_send!-modules();
   <<
      for each mod in redfront_modl() do
	 prin2t redfront_learncolor mod;
      statcounter := statcounter - 1;
      nil
   >>;

% Making this a MACRO means that its body gets evaluated at the the
% that a use of it is COMPILED. That means that the path to package.map
% as used here is only relevant at system-building time, which is a time
% when the full source tree is guaranteed to be available. The notation
% "$reduce" is set up (at that time, but not when the fully built system
% is complete. During a PSL build a shell variable called "reduce" should
% be set and so I make a path by concatenating based on that.

% An issue I found awkward when coding this is that in PSL a function that is
% defined here is not made available immediatly, and so if expanding a macro
% depends on it you are out of luck. I had to work around that by implementing
% the macro as one big function rather than several several smaller ones.

symbolic macro procedure redfront_package_names u;
  begin
    scalar fn,i,w,e,basel,extral;;
    fn := "$reduce/packages/package.map";
    if memq('psl, lispsystem!*) then
    begin
      scalar r1, r2, r3;
      r2 := explode2 (r1 := getenv "reduce");
      r3 := explode2 "/cygdrive/";
% I will map a prefix "/cygdrive/x" to "x:"
      while r2 and r3 and car r2 = car r3 do <<
        r2 := cdr r2;
        r3 := cdr r3 >>;
      if null r3 then
        r1 := list2string (car r2 . '!: . '!/ . cddr r2);
      fn := concat(r1, "/packages/package.map");
    end;
    prin2 "**** File name for packages = "; print fn;
    i := fn;
    i := open(i, 'input);
    i := rds i;
    e := !*echo;
    !*echo := nil;
    w := read();
    !*echo := e;
    i := rds i;
    close i;
    basel := for each x in w join
      if member('core, cddr x) then {car x};
    extral := for each x in w join
      if not member('core, cddr x) then {car x};
    return mkquote (basel . extral)
  end;


procedure redfront_send!-packages(fn);
   <<
      for each pack in cdr redfront_package_names() do
	 prin2t redfront_learncolor pack;
      statcounter := statcounter - 1;
      nil
   >>;

procedure redfront_fwl();
   begin scalar fwl;
      fwl := for each x in redfront_oblist() join
 	 if get(x, 'psopfn) or get(x, 'opfn) or get(x, 'polyfn) then
 	    {x};
      return sort(fwl,'ordp)
   end;

procedure redfront_send!-functions();
   <<
      for each fw in redfront_fwl() do
	 prin2t redfront_learncolor fw;
      statcounter := statcounter - 1;
      nil
   >>;

onoff('msg,car redfront_switches!*);
onoff('output,cadr redfront_switches!*);

crbuf!* := nil;
inputbuflis!* := nil;
%!*lessspace := t;
statcounter := 0;

endmodule;

end;
