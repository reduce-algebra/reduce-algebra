module clsimplatenv;

revision('clsimplatenv, "$Id$");

copyright('clsimplatenv, "(c) 2021 A. Dolzmann, T. Sturm");

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

#define SIATENV_TAG 0
#define SIATENV_SIATADV 1
#define SIATENV_SIEXPL 2
#define SIATENV_SIEXPLA 3
#define SIATENV_SIFAC 4
#define SIATENV_SIFACO 5
#define SIATENV_SIPD 6
#define SIATENV_SITSQSPL 7
#define SIATENV_UPLIM 7

switch rlidentify;                     % Make equal atomic formulas eq
switch rlsiatadv;   on1  'rlsiatadv;   % Main switch for advanced simplifications of atomic formulas
switch rlsiexpl;    on1  'rlsiexpl;    % Split f*g=0 and f*g<>0 within dis- and conjunctions, resp.
switch rlsiexpla;   on1  'rlsiexpla;   % Generally split f*g=0 and f*g<>0 into several atomic formulas
switch rlsifac;     on1  'rlsifac;     % Factorize left hand sides equations and inequations
switch rlsifaco;    off1 'rlsifaco;    % Factorize left hand sides of inequalities
switch rlsipd;      on1  'rlsipd;      % Degree parity decompositon of left hand sides
switch rlsitsqspl;  on1  'rlsitsqspl;  % Split trivial square sums into several atomic formulas

put('rlidentify, 'simpfg, '((t   (cl_initializeIdentifyAt))
                            (nil (remprop 'cl_identifyat 'hashTable))));

asserted procedure SiAtEnv_new(): Vector;
   begin scalar env;
      env := mkvect(SIATENV_UPLIM);
      putv(env, SIATENV_TAG,      'SiAtEnv);
      putv(env, SIATENV_SIATADV,  !*rlsiatadv);
      putv(env, SIATENV_SIEXPL,   !*rlsiexpl);
      putv(env, SIATENV_SIEXPLA,  !*rlsiexpla);
      putv(env, SIATENV_SIFAC,    !*rlsifac);
      putv(env, SIATENV_SIFACO,   !*rlsifaco);
      putv(env, SIATENV_SITSQSPL, !*rlsitsqspl);
      return env
   end;

asserted procedure SiAtEnv_asList(): List;
   {!*rlsiatadv, !*rlsiexpl, !*rlsiexpla, !*rlsifac, !*rlsifaco, !*rlsitsqspl};

macro procedure SiAtEnv_binaryEncoding(argl);
   begin scalar bit, encoding;
      argl := cdr argl;
      if null argl then
         rederr "SiAtEnv_binaryEncoding requires at least one argument";
      encoding := {'cond, {car argl, 1}, {t, 0}};
      argl := cdr argl;
      while argl do <<
         bit := {'cond, {car argl, 1}, {t, 0}};
         encoding := {'iplus2, bit, {'itimes2, 2, encoding}};
         argl := cdr argl
      >>;
      return encoding
   end;

asserted procedure SiAtEnv_asInteger(): Integer;
   SiAtEnv_binaryEncoding(!*rlsiatadv, !*rlsiexpl, !*rlsiexpla, !*rlsifac, !*rlsifaco, !*rlsitsqspl);

endmodule;

end;
