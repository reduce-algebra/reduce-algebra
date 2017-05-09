module rlsupport;

put('rlsupport, 'revision, "$Id$");
put('rlsupport, 'copyright, "(c) 2016-2017 T. Sturm");

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

% This package collects code which for technical reasons must be compiled before
% the compilation of the Redlog main package in redlog/rl. Otherwise, I would
% love to have all the modules here as modules of the package redlog. A
% technically feasible alternative solution would be to place (relevant parts)
% of that code into the main module redlog/rl/redlog.red. However, from my point
% of view this breaks modularization and would make the entire architecture
% harder to understand for others.
%
% In fact, I believe that there is a problem in Reduce that modules are
% essentially sections of packages but not units that are independent w.r.t.
% compilation.

create!-package('(rlsupport rltype rlservice rlblackbox rlprovide rlhelp), nil);

exports revision;
exports copyright;
exports rl_provideService;
exports rl_type;
exports rl_service;
exports rl_blackbox;
% We do not expect explicit code outside this package to directly call
% rl_servicewrapper. However, such code is generated via compiletime calls to
% rl_service in rl/rlservices.red. As a consequence, rl_servicewrapper has to
% trigger an autoload to this package in support/entry.red. Hence, we feel we
% should export it here. This is a actually subtility about the semantics of
% the exports statement to be clarified at some point.
exports rl_servicewrapper;
exports rl_exc;
exports rl_excP;
exports rl_excErr;
exports rl_help;

asserted procedure revision(m: Id, rev: String): String;
   put(m, 'revision, rev);

asserted procedure copyright(m: Id, c: String): String;
   put(m, 'copyright, c);

inline procedure rl_skipequal(proc);
   <<
      scan();
      if cursym!* neq 'equal then
	 rederr {"expecting '=' in", proc, "but found", cursym!*}
   >>;

endmodule;

end;
