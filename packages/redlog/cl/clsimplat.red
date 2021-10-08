module clsimplat;

revision('clsimplat, "$Id$");

copyright('clsimplat, "(c) 2021 A. Dolzmann, T. Sturm");

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

#define IDENTIFY_SIZE 65536
#define IDENTIFY_GROWTH 1

#define REMEMBER_SIZE 65536
#define REMEMBER_GROWTH 1
#define REMEMBER_BOUND 65536

asserted procedure cl_initializeIdentifyAt(): Void;
   begin scalar hashTable;
      hashTable := mkhash(IDENTIFY_SIZE, 'equal, IDENTIFY_GROWTH);
      put('cl_identifyat, 'hashTable, hashTable)
   end;

asserted inline procedure cl_identifyatHashKey(atf: AtFormula): DottedPair;
   cadr atf . car atf . cddr atf;

asserted inline procedure cl_identifyats(f: QfFormula): QfFormula;
   if !*rlidentify then cl_apply2ats(f, 'cl_identifyat) else f;

asserted procedure cl_identifyat(atf: AtFormula): AtFormula;
   begin scalar hashTable, entry;
      hashTable := get('cl_identifyat, 'hashTable);
      if (entry := gethash(cl_identifyatHashKey(atf), hashTable)) then
         return entry;
      puthash(cl_identifyatHashKey(atf), hashTable, atf);
      % The mutability of hash tables allows us to save a put('cl_identifyat, 'hashtable, ...)
      return atf
   end;

put('cl_simplat, 'remember, BHashTable_new(REMEMBER_SIZE, REMEMBER_GROWTH, REMEMBER_BOUND));

asserted inline procedure cl_simplatHashKey(atf: AtFormula, sop: Id): DottedPair;
   cadr atf . car atf . cddr atf . sop . rl_cid!* . rl_argl!* . SiAtEnv_asInteger();

asserted procedure cl_simplat(atf: AtFormula, sop: Id): QfFormula;
   % Common logic simplify atomic formula. The result is equivalent to atf. sop contains the logical
   % operator of the boolean level where atf occurred. This can help to decide about splitting or
   % not splitting atf. The actual simplification takes place in rl_simplat1 in the current
   % context. Here we implement the equivalent of a remember option.
   begin scalar bHashTable, key, entry, simplificationResult;
      if REMEMBER_BOUND <= 0 then
         return cl_identifyats rl_simplat1(atf, sop);
      bHashTable := get('cl_simplat, 'remember);
      key := cl_simplatHashKey(atf, sop);
      if (entry := BHashTable_gethash(key, bHashTable)) then
         return entry;
      simplificationResult := cl_identifyats rl_simplat1(atf, sop);
      BHashTable_puthash(key, bHashTable, simplificationResult);
      if cl_atfp(simplificationResult) then <<
         key := cl_simplatHashKey(simplificationResult, sop);
         BHashTable_puthash(key, bHashTable, simplificationResult)
      >>;
      % The mutability of BHashTable allows us to save a put('cl_simplat, 'rememeber, ...)
      return simplificationResult
   end;

endmodule;

end;
