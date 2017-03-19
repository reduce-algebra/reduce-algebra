module rltools;  % Redlog tools.

revision('rltools, "$Id$");

copyright('rltools, "(c) 1995-2009 A. Dolzmann, T. Sturm, 2010-2017 T. Sturm");

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

create!-package('(rltools systo ioto lto sfto sftoresultant),nil);

fluid '(!*rlbrkcxk);
fluid '(!*rlverbose);

fluid '(kord!*);

fluid '(!*fort);
fluid '(posn!*);
fluid '(orig!*);
fluid '(ycoord!*);
fluid '(ymax!*);
fluid '(ymin!*);
fluid '(pline!*);
fluid '(overflowed!*);
fluid '(testing!-width!*);
fluid '(rlsmaprinbuf!*);

switch rlgensymintern;

global '(rlgensymlen!*);
rlgensymlen!* := rlgensymlen!* or 0;

global '(rlgensymbase!*);
rlgensymbase!* := rlgensymbase!* or '!_k;

global '(rlgensymfast!*);
rlgensymfast!* := rlgensymfast!* or ('!_k . 0);

global '(rlgensymcountal!*);
rlgensymcountal!* := rlgensymcountal!* or {rlgensymfast!*};

#if (and (memq 'psl lispsystem!*) (not (getd 'modulep)))
   fluid '(!*lower loadextentions!*);

   procedure modulep(u);
      begin scalar found,ld,le,!*lower;
      	 !*lower := t;
      	 ld := loaddirectories!*;
      	 while ld and not found do <<
	    le := loadextensions!*;
	    while le and not found do <<
	       if filep bldmsg("%w%w%w",first ld,u,car first le) then
	       	  found := cdr first le;
	       	  le := rest le
	    >>;
	    ld := rest ld
      	 >>;
      	 return not null found
      end;
#endif

if 'csl memq lispsystem!* or 'psl memq lispsystem!* then <<
   if modulep 'groebner then
      load!-package 'groebner;
   if modulep 'groebnr2 then
      load!-package 'groebnr2
>>;

endmodule;  % [rltools]

end;  % of file
