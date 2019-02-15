module remake; % Update the fast loading (fasl) version of a file.

% Authors: Martin L. Griss and Anthony C. Hearn.
% Modified by ACN for the Sourceforge version.
% Modified again by FJW for REDUCE on Common Lisp.
% The standard version is "packages/support/remake.red".

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Redistribution and use in source and binary forms, with or without		   %
% modification, are permitted provided that the following conditions are met:  %
%																			   %
%    * Redistributions of source code must retain the relevant copyright	   %
%      notice, this list of conditions and the following disclaimer.		   %
%    * Redistributions in binary form must reproduce the above copyright	   %
%      notice, this list of conditions and the following disclaimer in the	   %
%      documentation and/or other materials provided with the distribution.	   %
%																			   %
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  %
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,		   %
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR	   %
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR			   %
% CONTRIBUTORS																   %
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR	   %
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF		   %
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS	   %
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN	   %
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)	   %
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   %
% POSSIBILITY OF SUCH DAMAGE.												   %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fluid '(!*break
        !*faslp
        !*forcecompile
   	    !*int
        !*loadall
        !*writingfaslfile);

global '(loaded!-modules!*);

symbolic procedure olderfaslp(u,v);
   % Return t if file u does not exist or is older than file v.
   % (Return nil if file v does not exist, but this should not happen!)
   not filep u or
	  (filep v and file!-write!-date u < file!-write!-date v);

% Support for packages directory.

symbolic procedure package!-remake x;
   (if y then package!-remake2(x,y) else package!-remake2(x,x))
   where y=get(x,'folder);

fluid '(new_inline_definitions);

new_inline_definitions := nil;

% Now indicate where the file listing inline-definitions will live.
% Note that it is in different places for different flavours of Lisp.
% For now put it in the fasl directory.

symbolic procedure inline_defs_file();
   "fasl/inline-defs.dat";

symbolic procedure load_saved_inlines();
  begin
    scalar ff, u, v;
%
% There is another bit of fun here. I would like to be able to call
% module!-rebuild at any time, and that means that the current directory
% is uncertain when that happens. So with CSL I arrange that I always keep
% my "inline-defs.dat" file in the directory where generated C lives.
% For PSL I put things where fasl files go.
% FJW: CL follows PSL here.
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
   % Remake module u in directory packages/v or current directory if v
   % is nil.
   begin scalar y, !*int;		% to avoid faslout interaction message
      load_saved_inlines();
      new_inline_definitions := nil;
      update!-fasl2(u,v);
      evload list u;
	  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	  if u eq 'ibalp then
		 for each v in
			'(!A !B !C !D !E !F !G !H !I !J !K !L !M
			   !N !O !P !Q !R !S !T !U !V !W !X !Y !Z) do
				  remprop(v,'stat);
	  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      loaded!-modules!* := union(loaded!-modules!*, list u);
      y := get(u,'package);
      if y then y := cdr y;
      for each j in y do update!-fasl2(j,v);
      save_inlines();
   end;

symbolic procedure update!-fasl2(u,v);
   % Update fasl file for module u in directory packages/v or current
   % directory if v is nil.
   begin scalar y,z;
 	  y := concat2("fasl/", concat2(mkfil u, ".fasl"));
      z := module2!-to!-file(u,v);
      if olderfaslp(y,z) or !*forcecompile
        then <<terpri();
               terpri();
               if errorp errorset!*(list('upd!-fasl1,mkquote u,
                                                   mkquote z,
                                                   mkquote v),
                                  t)
                 then <<if !*writingfaslfile then lispeval '(faslend);
                        lprie list("Error during mkfasl of", u . v)>>>>
   end;

symbolic procedure upd!-fasl1(u,v,w);
   % Update fasl file for module u corresponding to file v in
   % directory packages/w or current directory if w is nil.
   begin scalar !*break,x;
      !*faslp := t;
      if !*loadall and w and w neq u then <<
         evload list w;
         loaded!-modules!* := union(loaded!-modules!*, list w) >>;
	  % The following is not currently useful for Common Lisp.
	  % E.g. x = (setq *fastfor t) for the factor module.
      % if x := get(u,'compiletime)
      %   then <<prin2 "*** Compile time: "; prin2t x; lispeval x>>;
      u := mkfil u;
      lprim list("Compiling",u,"...");
      terpri();
	  lispeval list('faslout, concat2("fasl/",u));
      infile v;
      lispeval '(faslend)
   end;

symbolic procedure module2!-to!-file(u,v);
   % Converts the module u in package directory v, or the current
   % directory if v is nil, to a file name.
   % Also defined in build.red!
   <<
   	  u := concat2(mkfil u, ".red");
   	  if v then concat2("$reduce/packages/", concat2(mkfil v, concat2("/", u)))
	  else u
   >>;

endmodule;

end;
