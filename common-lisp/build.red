% module build;  % Code to help with bootstrapping REDUCE from Lisp.

% Author: Anthony C. Hearn.
% Modified by ACN for the Sourceforge version.
% Modified again by FJW for Common Lisp REDUCE.
% The standard version is "packages/support/build.red".

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

% The code here is loaded rather early in the bootstrap process, and
% so is processed by a provisional rather than the final version of
% the rlisp parser. Most features of the language are available, but
% do careful testing after any edits in case you fall foul of any of
% the restrictions!

global '(loaded!-packages!*);

% A few functions will appear again in remake.red, and xslrend.red but
% they are needed at this stage during the bootstrap build of REDUCE.
% So perhaps to avoid repetition I could find somewhere even earlier to
% include it, but for now there is repetition to should be kept in step.

% Since some of the early modules may have tabs in them, we must redefine
% seprp. Note that there is a TAB in this definition and that may not be
% readily visible when merely editing the file.

% FJW: Don't try to read this redefinition of seprp interactively --
% doing so breaks the RLISP parser!

symbolic procedure seprp u;
   or(u eq '! , u eq '!	, u eq !$eol!$);

% FJW: Note that typerr is not yet defined, so hope that it is not
% called!  But string-downcase is provided by Common Lisp.

symbolic procedure mkfil u;
   % Converts file descriptor U into valid system filename.
   if stringp u then u
    else if not idp u then typerr(u,"file name")
    else string!-downcase u;

symbolic procedure module2!-to!-file(u,v);
   % FJW: Convert the module u in package directory v, or the current
   % directory if v is nil, to a (lower-case) file name relative to
   % the directory containing packages.
   % Also defined in remake.red!
   <<
   	  u := concat2(mkfil u, ".red");
   	  if v then concat2("$reduce/packages/", concat2(mkfil v, concat2("/", u)))
	  else u
   >>;

% I do not do anything about a cache of inline procedure definitions here
% because the bootstrap build using load!-package!-sources happens all in
% one sequential process so definitions will be saved in memory anyway.

symbolic procedure inmodule(u,v);
   % FJW: Print name of file being read.
   begin scalar file;
	  terpri();
	  prin2 "+++ Reading file: ";
	  prin2(file := module2!-to!-file(u,v));
	  terpri();
      u := open(file, 'input);
      v := rds u;
      cursym!* := '!*semicol!*;
      while not (cursym!* eq 'end) do <<
         prin2 eval form xread nil; prin2 " " >>;
      rds v;
      close u;
   end;

symbolic procedure load!-package!-sources(u,v);
   begin scalar !*int,!*echo,w;
      % if and(member('csl, lispsystem!*), !*backtrace) then !*echo := t;
      inmodule(u,v);
      if (w := get(u,'package)) then w := cdr w;
      while w do <<
         inmodule(car w, v);
         w := cdr w >>;
      loaded!-packages!* := u . loaded!-packages!*;
   end;

% endmodule;

end;
