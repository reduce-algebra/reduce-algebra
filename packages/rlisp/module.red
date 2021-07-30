% module module; % Support for module and package use.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation.  All rights reserved.

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

% $Id: $

% The code here is loaded rather early in the bootstrap process, and so
% is processed by a provisional rather than the final version of the
% rlisp parser. Most features of the language are available, but do careful
% testing after any edits in case you faul foul of any of the restrictions!

fluid '(!*backtrace !*mode !*faslp);

global '(exportslist!* importslist!* loaded!-packages!* loaded!-modules!*
         mode!-list!*);

!*mode := 'symbolic;   % initial value.

remprop('exports,'stat);

remprop('imports,'stat);

remprop('module,'stat);

symbolic procedure exports u;
   begin exportslist!* := union(u,exportslist!*) end;

symbolic procedure imports u;
   begin importslist!* := union(u,importslist!*) end;

symbolic procedure module u;
   % Sets up a module definition.
   begin
      mode!-list!* := !*mode . mode!-list!*;
      !*mode := 'symbolic
   end;

symbolic procedure endmodule;
   begin
      if null mode!-list!*
        then rederr  "ENDMODULE called outside module";
      exportslist!* := nil;
      importslist!* := nil;
      !*mode := car mode!-list!*;
      mode!-list!* := cdr mode!-list!*
   end;

deflist('((exports rlis) (imports rlis) (module rlis)),'stat);

put('endmodule,'stat,'endstat);

flag('(endmodule),'go);

flag('(module endmodule),'eval);

put('xmodule,'newnam,'module);   % Hook for module extensions.

% Support for package loading.

put('load,'stat,'rlis);

put('load,'formfn,'formload);


symbolic procedure formload(u,vars,mode);
   if mode = 'symbolic then
      list('progn,
% Adapted to maintain loaded!-modules!*
           list('setq, 'loaded!-modules!*,
              list('union, 'loaded!-modules!*, mkquote cdr u)),
           list('evload, mkquote cdr u))
   else list('load!_package, mkquote cdr u);

symbolic procedure load!-package u;
   begin scalar x,y;
      if stringp u then return load!-package intern u
% And earlier comment said 'intern intern is needed for, e.g., "../huhu".'
% but when I try both PSL and CSL the string "../huhu" when passed to intern
% yields the symbol !.!.!/huhu as expected...
       else if null idp u then rederr list(u,"is not a package name")
       else if memq(u,loaded!-packages!*)
%       then << lprim list("Package",u,"already loaded"); return u >>
        then return u
       else if or(atom(x:= errorset(list('evload,list('quote,list u)),
                               nil,!*backtrace)),
                  cdr x)
        then rederr
           list("error in loading package",u,"or package not found");
       loaded!-packages!* := u . loaded!-packages!*;
       loaded!-modules!* := union(loaded!-modules!*, list u);
       x := get(u,'package);
       if x then x := cdr x;
       while x do <<
          if null atom get(car x,'package) then load!-package car x
          else if or(atom(y := errorset(list('evload,
                                            list('quote,list car x)),
                                       nil,!*backtrace)),
                     cdr y)
           then rederr list("module",car x,"of package",u,
                            "cannot be loaded");
         loaded!-modules!* := union(loaded!-modules!*, list car x);
         x := cdr x >>;
      return install!-patches u
   end;

% Now a more user-friendly version.

remprop('load!_package,'stat);

remprop('packages!_to!_load,'stat);

symbolic procedure load!_package u;
   begin
      while u do <<
         load!-package car u;
         u := cdr u >>
   end;

symbolic procedure packages!_to!_load u;
   %% FJW: Load other packages at package load time only, i.e. do not
   %% load during building (hence not to be flagged eval).
   if null !*faslp then load!_package u;

put('load!_package,'stat,'rlis);

put('packages!_to!_load,'stat,'rlis);

flag('(load!-package load!_package),'eval);


% Support for patching REDUCE sources. The whole mechanism set up here is
% now no longer used. In the past when distribution was on CD (or magnetic
% tape, or on large piles of floppy disc) users received a base version
% of the system and then relativly small patch files could be distributed
% to update the system or correct errors. Now with the faster networks
% this whole idea is not so necessary.

symbolic procedure patchstat;
   % Read a patch for a given package.
   begin scalar !*mode,u,v,x,y,z,z2;
      x := scan();   % Package name.
      scan();        % Remove semicolon.
 a:   !*mode := 'symbolic;
      y := xread nil;
      if eqcar(y,'symbolic) then y := cadr y
       else if flagpcar(y,'modefn)
        then << !*mode := car y; y := cadr y >>;
      if eq(y,'endpatch) then <<
         u := name!-for!-patched!-version(x, z);
         z2 := list('de,u,nil,'progn . reversip z) . z2;
         z2 := list('patches!-load!-check,mkquote x,mkquote u) . z2;
         return ('patch . reversip z2) >>
      else if eqcar(y,'procedure) then <<
         v := cadr y;
         u := name!-for!-patched!-version(v, y);
         z := list('instate!-patches,mkquote v,mkquote u,mkquote x) . z;
         z2  := convertmode(('procedure . u . cddr y),nil,
                             'symbolic,!*mode) . z2 >>
      else z := convertmode(y,nil,'symbolic,!*mode) . z;
      go to a;
   end;

symbolic procedure name!-for!-patched!-version(name, extra);
   % hashtagged!-name (in CSL) constructs a name that starts with NAME but
   % then continues with a hash value based on EXTRA. The improbability of
   % hash collisions then makes it reasonable to use an interned symbol.
   if member('psl, lispsystem!*) then gensym()
    else hashtagged!-name(name,extra);

symbolic procedure instate!-patches(new,old,pkg);
  begin scalar x;
     x := getd old;
     if x then putd(new,car x,cdr x)
     else rerror('module,1,list(new,"has a badly set-up patch"));
     return nil
  end;

symbolic procedure install!-patches u;
   if u = 'patches then nil
   else if (u := get(u,'patchfn)) then
   begin scalar !*usermode,!*redefmsg;
      eval list u
   end;

symbolic procedure patches!-load!-check(u,v);
   begin
      put(u,'patchfn,v);
      if memq(u,loaded!-packages!*) then install!-patches u
   end;

put('patch,'stat,'patchstat);

symbolic procedure formpatch(u,vars,mode);
   'progn . cdr u;

put('patch,'formfn,'formpatch);

% endmodule;

end;
