module clqeenv;

revision('clqeenv, "$Id$");

copyright('clqeenv, "(c) 2021 A. Dolzmann, T. Sturm");

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

#define QEENV_TAG 0
#define QEENV_QEAPRECISE 1
#define QEENV_QEBACKSUB 2
#define QEENV_QEDFS 3
#define QEENV_QEDYN 4
#define QEENV_QEFB 5
#define QEENV_QEFILTERBOUNDS 6
#define QEENV_QEFULLANS 7
#define QEENV_QEGENCT 8
#define QEENV_QEGSD 9
#define QEENV_QEHEU 10
#define QEENV_QEIDENTIFY 11
#define QEENV_QELOG 12
#define QEENV_QEPNF 13
#define QEENV_QEPRECISE 14
#define QEENV_QEQSC 15
#define QEENV_QESQSC 16
#define QEENV_QESR 17
#define QEENV_QESTDANS 18
#define QEENV_QESTDANSINT 19
#define QEENV_QESTDANSQ 20
#define QEENV_QESTDANSVB 21
#define QEENV_QESUBF 22
#define QEENV_QEVARSEL 23
#define QEENV_QEVARSELTRY 24
#define QEENV_QEVB 25
#define QEENV_QEVBOLD 26
#define QEENV_UPLIM 46

switch rlqeaprecise;      off1 'rlqeaprecise;      % Try to avoid epsilon and infinity with rlqea
switch rlqebacksub;       on1  'rlqebacksub;       % Back substitution in answer
switch rlqedfs;           on1  'rlqedfs;           % Depth-first search
switch rlqedyn;           on1  'rlqedyn;           % Dynamic programming with depth-first search
switch rlqefb;            on1  'rlqefb;            % Use fallback QE in case of degree violations
switch rlqefilterbounds;  on1  'rlqefilterbounds;  % Remove bounds with false guards before counting
switch rlqefullans;       off1 'rlqefullans;       % Do not eliminate shift variables from answer
switch rlqegenct;         on1  'rlqegenct;         % Generate complex theory (non-atomic assumptions)
switch rlqegsd;           off1 'rlqegsd;           % Groebner simplifier before elimination of an ex block
switch rlqeheu;           off1 'rlqeheu;           % Traversal heuristics: DFS for outmost block, BFS otherwise
switch rlqeidentify;      off1 'rlqeidentify;      % Make equal atomic formulas eq in simplification
switch rlqelog;           off1 'rlqelog;           % Log elimination set generation
switch rlqepnf;           on1  'rlqepnf;           % Compute prenex normal form before elimination
switch rlqeprecise;       off1 'rlqeprecise;       % Try to avoid epsilon and infinity with rlqe
switch rlqeqsc;           off1 'rlqeqsc;           % Quadratic special case
switch rlqesqsc;          off1 'rlqesqsc;          % Super quadratic special case
switch rlqesr;            off1 'rlqesr;            % Seperate roots in midnight formula
switch rlqestdans;        off1 'rlqestdans;        % Remove pinf, minf, epsilon from answers for existential sentences
switch rlqestdansint;     on1  'rlqestdansint;     % Try to find integer answers
switch rlqestdansq;       on1  'rlqestdansq;       % Try to find rational answers
switch rlqestdansvb;      off1 'rlqestdansvb;      % Verbose output for rlqestdans computation
switch rlqesubf;          off1 'rlqesubf;          % Use subf for substituting SQ into atomic formulas
switch rlqevarsel;        on1  'rlqevarsel;        % Select best variable(s) to be eliminated next
switch rlqevarseltry;     off1 'rlqevarseltry;     % Select several candidate variables to be eliminated next
switch rlqevb;            on1  'rlqevb;            % Main switch for verbose output of cl/clqenew
switch rlqevbold;         off1 'rlqevbold;         % Old-style verbose output; not used in cl/clqenew anymore

asserted procedure QeEnv_new(): Vector;
   begin scalar env;
      env := mkvect(QEENV_UPLIM);
      putv(env, QEENV_TAG,            'QeEnv);
      putv(env, QEENV_QEAPRECISE,     !*rlqeaprecise);
      putv(env, QEENV_QEBACKSUB,      !*rlqebacksub);
      putv(env, QEENV_QEDFS,          !*rlqedfs);
      putv(env, QEENV_QEDYN,          !*rlqedyn);
      putv(env, QEENV_QEFB,           !*rlqefb);
      putv(env, QEENV_QEFILTERBOUNDS, !*rlqefilterbounds);
      putv(env, QEENV_QEFULLANS,      !*rlqefullans);
      putv(env, QEENV_QEGENCT,        !*rlqegenct);
      putv(env, QEENV_QEGSD,          !*rlqegsd);
      putv(env, QEENV_QEHEU,          !*rlqeheu);
      putv(env, QEENV_QEIDENTIFY,     !*rlqeidentify);
      putv(env, QEENV_QELOG,          !*rlqelog);
      putv(env, QEENV_QEPNF,          !*rlqepnf);
      putv(env, QEENV_QEPRECISE,      !*rlqeprecise);
      putv(env, QEENV_QEQSC,          !*rlqeqsc);
      putv(env, QEENV_QESQSC,         !*rlqesqsc);
      putv(env, QEENV_QESR,           !*rlqesr);
      putv(env, QEENV_QESTDANS,       !*rlqestdans);
      putv(env, QEENV_QESTDANSINT,    !*rlqestdansint);
      putv(env, QEENV_QESTDANSQ,      !*rlqestdansq);
      putv(env, QEENV_QESTDANSVB,     !*rlqestdansvb);
      putv(env, QEENV_QESUBF,         !*rlqesubf);
      putv(env, QEENV_QEVARSEL,       !*rlqevarsel);
      putv(env, QEENV_QEVARSELTRY,    !*rlqevarseltry);
      putv(env, QEENV_QEVB,           !*rlqevb);
      putv(env, QEENV_QEVBOLD,        !*rlqevbold);
      return env
   end;

asserted procedure QeEnv_getAprecise(env: Vector): Boolean;      getv(env, QEENV_QEAPRECISE);
asserted procedure QeEnv_getBacksub(env: Vector): Boolean;       getv(env, QEENV_QEBACKSUB);
asserted procedure QeEnv_getDfs(env: Vector): Boolean;           getv(env, QEENV_QEDFS);
asserted procedure QeEnv_getDyn(env: Vector): Boolean;           getv(env, QEENV_QEDYN);
asserted procedure QeEnv_getFb(env: Vector): Boolean;            getv(env, QEENV_QEFB);
asserted procedure QeEnv_getFilterbounds(env: Vector): Boolean;  getv(env, QEENV_QEFILTERBOUNDS);
asserted procedure QeEnv_getFullans(env: Vector): Boolean;       getv(env, QEENV_QEFULLANS);
asserted procedure QeEnv_getGenct(env: Vector): Boolean;         getv(env, QEENV_QEGENCT);
asserted procedure QeEnv_getGsd(env: Vector): Boolean;           getv(env, QEENV_QEGSD);
asserted procedure QeEnv_getHeu(env: Vector): Boolean;           getv(env, QEENV_QEHEU);
asserted procedure QeEnv_getIdentify(env: Vector): Boolean;      getv(env, QEENV_QEIDENTIFY);
asserted procedure QeEnv_getLog(env: Vector): Boolean;           getv(env, QEENV_QELOG);
asserted procedure QeEnv_getPnf(env: Vector): Boolean;           getv(env, QEENV_QEPNF);
asserted procedure QeEnv_getPrecise(env: Vector): Boolean;       getv(env, QEENV_QEPRECISE);
asserted procedure QeEnv_getQsc(env: Vector): Boolean;           getv(env, QEENV_QEQSC);
asserted procedure QeEnv_getSqsc(env: Vector): Boolean;          getv(env, QEENV_QESQSC);
asserted procedure QeEnv_getSr(env: Vector): Boolean;            getv(env, QEENV_QESR);
asserted procedure QeEnv_getStdans(env: Vector): Boolean;        getv(env, QEENV_QESTDANS);
asserted procedure QeEnv_getStdansint(env: Vector): Boolean;     getv(env, QEENV_QESTDANSINT);
asserted procedure QeEnv_getStdansq(env: Vector): Boolean;       getv(env, QEENV_QESTDANSQ);
asserted procedure QeEnv_getStdansvb(env: Vector): Boolean;      getv(env, QEENV_QESTDANSVB);
asserted procedure QeEnv_getSubf(env: Vector): Boolean;          getv(env, QEENV_QESUBF);
asserted procedure QeEnv_getVarsel(env: Vector): Boolean;        getv(env, QEENV_QEVARSEL);
asserted procedure QeEnv_getVarseltry(env: Vector): Boolean;     getv(env, QEENV_QEVARSELTRY);
asserted procedure QeEnv_getVb(env: Vector): Boolean;            getv(env, QEENV_QEVB);
asserted procedure QeEnv_getVbold(env: Vector): Boolean;         getv(env, QEENV_QEVBOLD);

endmodule;

end;
