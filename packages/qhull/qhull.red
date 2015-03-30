% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2013 Thomas Sturm
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

module qhull;
% Compute the convex hull of a list points as a subset of that list. This is an
% interface to qhull (www.qhull.org), which has to be installed externally.

create!-package('(qhull),nil);

load!-package 'assert;

switch qhullkeepfiles;

fluid '(qhull_call!* qhull_wd!*);

qhull_call!* := "qhull";
qhull_wd!* := "/tmp/";

operator qhull;

asserted procedure qhull(l: list): list;
   qhull_s2alist qhull_qhull qhull_a2slist l;

asserted procedure qhull_a2slist(l: list): list;
   for each pt in cdr l collect cdr pt;

asserted procedure qhull_s2alist(l: list): list;
   'list . for each pt in l collect 'list . pt;

asserted procedure qhull_qhull(l: list): list;
   begin scalar fn1, fn2, qhull, call, w; integer rnd, d, n;
      if null l then
 	 return nil;
      d := length car l;
      n := length l;
      rnd := lto_at2str random(10^5);
      fn1 := lto_sconcat {qhull_wd!*, getenv "USER", rnd, "-qhull.in"};
      fn2 := lto_sconcat {qhull_wd!*,getenv "USER", rnd, "-qhull.out"};
      qhull := getenv("QHULL") or qhull_call!*;
      call := lto_sconcat {qhull, " p < ", fn1, " > ", fn2};
      qhull_createinfile(l, d, n, fn1);
      w := system call;
      if not eqn(w, 0) then <<
	 if not !*qhullkeepfiles then
	    system lto_sconcat {"rm ", fn1};
	 rederr "qhull call failed"
      >>;
      w := qhull_parseoutfile fn2;
      if not !*qhullkeepfiles then
      	 system lto_sconcat {"rm ", fn1, " ", fn2};
      return w
   end;

asserted procedure qhull_createinfile(l: list, d: integer, n: integer, fn1: string): any;
   <<
      out fn1;
      prin2t d;
      prin2t n;
      for each pt in l do <<
      	 for each rptl on pt do <<
	    prin2 car rptl;
	    if cdr rptl then
	       prin2 " "
	 >>;
	 terpri()
      >>;
      shut fn1
   >>;

asserted procedure qhull_parseoutfile(fn2: string): list;
   begin scalar ch, res; integer d, n;
      ch := open(fn2, 'input);
      rds ch;
      d := read();
      n := read();
      res := for i := 1:n collect
	 for j := 1:d collect
	    read();
      rds nil;
      close ch;
      return res
   end;

endmodule;

end;
