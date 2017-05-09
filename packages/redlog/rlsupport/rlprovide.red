module rlprovide;

revision('rlprovide, "$Id$");

copyright('rlprovide, "(c) 2017 T. Sturm");

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

put('rl_provideService, 'stat, 'rl_provideServiceStat);

asserted procedure rl_provideServiceStat(): List4;
   begin scalar rls, ps, bbl;
      scan();
      if not idp cursym!* then
	 rederr {"expecting identifier in rl_provideService but found", cursym!*};
      rls := cursym!*;
      rl_skipequal("rl_provideService");
      scan();
      if not idp cursym!* then
	 rederr {"expecting identifier in rl_provideService", rls, "but found", cursym!*};
      ps := cursym!*;
      scan();
      if cursym!* eq '!*semicol!* then
	 return {'rl_provideService, {rls, ps, nil}};
      if cursym!* neq 'using then
	 rederr {"expecting 'using' or delimiter in rl_provideService", rls, "=", ps, "but found", cursym!*};
      repeat <<
	 scan();
      	 if not idp cursym!* then
	    rederr {"expecting identifier in rl_provideService", rls, "=", ps, "but found", cursym!*};
	 bbl := lto_insertq(cursym!*, bbl);
	 scan();
      	 if not (cursym!* memq '(!*comma!* !*semicol!*)) then
	    rederr {"expecting ',' in rl_provideService", rls, "=", ps, "but found", cursym!*}
      >> until cursym!* eq '!*semicol!*;
      return {'rl_provideService, mkquote rls, mkquote ps, mkquote bbl}
   end;

flag('(rl_provideService), 'noform);

asserted procedure rl_provideService(rlservice: Id, pservice: Id, blackboxes: List);
   <<
      put(rlservice, 'rl_knownImplementations,
      	 lto_insertq(pservice, get(rlservice, 'rl_knownImplementations)));
      put(pservice, 'rl_providedService, rlservice);
      put(pservice, 'rl_registeredBlackboxes,
      	 union(get(pservice, 'rl_registeredBlackboxes), blackboxes))
   >>;

asserted procedure rl_providedServiceP(x: Any): ExtraBoolean;
   idp x and flagp(x, 'rl_providedService);

asserted procedure rl_registeredBlackboxes(x: Id): List;
   get(x, 'rl_registeredBlackboxes);

endmodule;

end;
