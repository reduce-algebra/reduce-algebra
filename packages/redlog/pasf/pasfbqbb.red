module pasfbqbb;
% Black boxes processing bounded quantifiers for cl services.

revision('pasfbqbb, "$Id$");

copyright('pasfbqbb, "(c) 2021 A. Dolzmann, T. Sturm");

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

asserted procedure pasf_BQapply2ats1(f: Formula, client: Applicable, xargs: List): Formula;
   % Apply also to atoms in bound.
   rl_mkbq(rl_op f, rl_var f, cl_apply2ats1(rl_b f, client, xargs), cl_apply2ats1(rl_mat f, client, xargs));

asserted procedure pasf_BQatnum(f: Formula): Integer;
   % Count atoms also in bound.
   cl_atnum(rl_mat f) + cl_atnum(rl_b f);

asserted procedure pasf_BQqnum(f: Formula): Integer;
   % Do not count bounded quantifiers.
   cl_qnum rl_mat f;

asserted procedure pasf_BQdepth(f: Formula): Integer;
   % Do not consider the bound.
   1 + cl_depth rl_mat f;

asserted procedure pasf_BQf2ml(f: Formula, client: Applicable): List;
   % Consider both bound and matrix.
   lto_almerge({cl_f2ml(rl_mat f, client), cl_f2ml(rl_b f, client)}, 'plus2);

endmodule;

end;
