module remake; % Update the fasl loading version and cross-reference of
               % a given file.

% Authors: Martin L. Griss and Anthony C. Hearn.
% Modified by ACN for the Sourceforge version...

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


fluid '(!*argnochk
        !*break
        !*cref
        !*crefchk
        !*faslp
        !*forcecompile
        !*int
        !*loadall
        !*usermode
        !*writingfaslfile
        lispsystem!*);

global '(nolist!* loaded!-modules!*);

symbolic procedure psl!-file!-write!-date u;
   % Returns write date of file u as an integer.
   (if null x then rederr list("file not found:",u)
    else cddr assoc('writetime,x))
   where x = filestatus(u,nil);

symbolic procedure olderfaslp(u,v);
   if 'psl memq lispsystem!*
     then null filep u
        or psl!-file!-write!-date u < psl!-file!-write!-date v
    else if null filedate v then rederr list("Missing file",v)
    else null modulep u or datelessp(modulep u,filedate v);

% Code for updating cross reference information.

nolist!* := append('(module endmodule),nolist!*);

% +++++ The cross-referencing capability probably no longer works.

symbolic procedure update!-cref x;
   % Updates cross-reference for x (module . path).
   begin scalar y,z;
      y := concat2("$rcref/",concat2(mkfil car x,".crf"));
      z := module2!-to!-file(car x,get(cdr x,'path));
      if olderfaslp(y,z) or !*forcecompile
        then <<terpri();
               terpri();
               if errorp errorset!*(list('upd!-cref1,mkquote car x,
                                                   mkquote z,mkquote y),
                                  t)
                 then lprie list("Error during cref of",x)>>
%                then errorprintf("***** Error during cref of %w%n",x)>>
   end;

symbolic procedure upd!-cref1(u,v,w);
   begin scalar !*break,!*cref,!*int,!*usermode,ochan,oldochan,oldll;
      lprim list("Cross referencing",u,"...");
%     prin2t bldmsg("*** Cross referencing %w ...",u);
      ochan := open(w,'output);
      oldochan := wrs ochan;
      oldll := linelength 75;
      crefon();   % this is entry point to cref routines
      !*cref := t;
      infile v;
      !*cref := nil;
      crefoff();
      close ochan;
      wrs oldochan;
      linelength oldll
   end;


% Support for packages directory.

symbolic procedure package!-remake x;
   (if y then package!-remake2(x,y) else package!-remake2(x,x))
   where y=get(x,'folder);

fluid '(new_inline_definitions);

new_inline_definitions := nil;

% If anybody wanted to support true parallel recompilation of Reduce
% packages than in addition to any other adjustments it would be
% important to make the following procedures atomic.

% Here I indicate where the file listing inline-definitions will live...
% Note that it is in different places for different flavours of Lisp. For
% CSL it is in the generated-c directory because several different variant
% builds may wish to share it.

symbolic procedure inline_defs_file();
% The PSL bootstrap build needs the "!" here
!#if (memq 'vsl lispsystem!*)
   "inline-defs.dat";
!#elif (memq 'cslplus lispsystem!*)
   "$reduce/cslplusbuild/generated-cpp/inline-defs.dat";
!#elif (memq 'csl lispsystem!*)
   "$reduce/cslbuild/generated-c/inline-defs.dat";
!#else
   "$fasl/inline-defs.dat";
!#endif

symbolic procedure load_saved_inlines();
  begin
    scalar ff, u, v;
%
% There is another bit of fun here. I would like to be able to call
% module!-rebuild at any time, and that means that the current directory
% is uncertain when that happens. So with CSL I arrange that I always keep
% my "inline-defs.dat" file in the directory where generated C lives.
% For PSL I put things where fasl files go.
%
    ff := inline_defs_file();
    if not filep ff then return nil;
    ff := open(ff, 'input);
    if null ff then return nil;
    u := rds ff;
    v := read();
    if atom v then v := nil; % E.g. if v = !$eof!$
    rds u;
    close ff;
    for each a in v do put(car a, 'inline, cdr a);
    return nil
  end;

% There is an ISSUE here. If a version of the souce code introduced an
% inline definition for a function (say FFF) then that definition gets lifted
% out and saved in inline-defs.dat. If the inline definition for FFF is
% changed then the new definition will eventually end up in inline-defs.dat.
% However if the inline definition is removed from the source files a version
% can persist in inline-defs.dat with no mechanical scheme to get rid of it.
% At present my stance is that anybody who changes what functions are tagged
% inline has a responsibility to do a "make clean" and in due course I will
% cause that to remove the cached definitions...

symbolic procedure save_inlines();
  begin
    scalar fname, ff, u, v, w, changed;
% If there are no new inline definition at all from this compilation or
% if new ones match what was already present then I will not want to update
% the file where definitions are saved. Then I can use a dependency on it
% in a Makefile to help me ensure I recompile enough times to get to a fully
% stable state.
    if null new_inline_definitions then <<
      lprim "No new inline definitions here";
      return nil>>;
    fname := inline_defs_file();
    if filep fname then <<
      ff := open(fname, 'input);
      if null ff then return nil; % Failed! Note filep had said it was there.
      u := rds ff;
      v := read();
      if atom v then v := nil;
      rds u;
      close ff >>
    else v := nil; % if "inline-defs.dat" does not exist at all treat it
                   % as if empty.
% Ok I have now read the current set of inline definitions. I had read it once
% at the start of rebuilding the current package, but I read it again
% here in case anybody has updated it since I started to rebuild this package.
    changed := nil;
    for each a in new_inline_definitions do <<
      w := assoc(car a, v);
      if not w then <<
        if posn() neq 0 then terpri();
        princ "+++ new inline definition for ";
        prin1 car a >>;
      if w and not (w = a) then <<
        if posn() neq 0 then terpri();
        princ "+++ inline definition for ";
        prin1 car a;
        printc " differs from previous version - please recompile everything";
        v := delasc(car a, v);
        w := nil >>; % Setting w to nil here discards the previous version
      if not w then << % If there was no previous version then I need to record
        v := a . v;
        changed := t >> >>;
    if changed then <<
      lprim "Need to rewrite inline-defs.dat file";
      ff := open(fname, 'output);
      if null ff then return nil; % Failed!
      u := wrs ff;
      prin2 "(";
      terpri();
      for each x in v do << print x; terpri() >>;
      prin2 ")";
      terpri();
      wrs u;
      close ff >>;
    return nil
  end;

symbolic procedure package!-remake2(u,v);
   begin scalar y;
%     if !*crefchk then update!-cref2(u . v);
      load_saved_inlines();
      new_inline_definitions := nil;
      update!-fasl2(u . v);
      evload list u;
      loaded!-modules!* := union(loaded!-modules!*, list u);
      y := get(u,'package);
      if y then y := cdr y;
      for each j in y do
         <<update!-fasl2(j . v);
%          if !*crefchk then update!-cref2(j . v)>>
         >>;
      save_inlines();
   end;

symbolic procedure update!-fasl2 x;
   begin scalar y,z;
      if 'psl memq lispsystem!*
        then y := concat2("$fasl/", concat2(mkfil car x, ".b"))
       else y := car x;
      z := module2!-to!-file(car x,cdr x);
      if olderfaslp(y,z) or !*forcecompile
        then <<terpri();
               terpri();
               if errorp errorset!*(list('upd!-fasl1,mkquote car x,
                                                   mkquote z,
                                                   mkquote cdr x),
                                  t)
                 then <<if !*writingfaslfile then lispeval '(faslend);
                        lprie list("Error during mkfasl of",x)>>>>
   end;

symbolic procedure upd!-fasl1(u,v,w);
   % We rebind *fastfor here because it's the only case of "compiletime"
   % at the moment (!).
   begin scalar !*fastfor,!*lower,!*usermode,!*quiet_faslout,!*break,x;
      !*faslp := t;
      !*quiet_faslout := t;
      if not('psl memq lispsystem!*) then !*lower := t;
      if !*loadall and w neq u then <<
         evload list w;
         loaded!-modules!* := union(loaded!-modules!*, list w) >>;
      if x := get(u,'compiletime)
        then <<prin2 "*** Compile time: "; prin2t x; lispeval x>>;
      u := mkfil u;
      lprim list("Compiling",u,"...");
%     prin2t bldmsg("*** Compiling %w ...",u);
      terpri();
      if 'psl memq lispsystem!*
        then lispeval list('faslout, concat2("$fasl/",u))
       else lispeval list('faslout,u);
      infile v;
      lispeval '(faslend)
   end;

symbolic procedure module2!-to!-file(u,v);
   % Converts the module u in package directory v to a fully rooted file
   % name.
   if memq('vsl, lispsystem!*) then
     concat2("../packages/",concat2(mkfil v,
            concat2("/",concat2(mkfil u,".red"))))
   else
     concat2("$reduce/packages/",concat2(mkfil v,
            concat2("/",concat2(mkfil u,".red"))));

endmodule;

end;
