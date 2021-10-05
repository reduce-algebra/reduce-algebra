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

#define IDENTIFY_HASHTABLE_SIZE 65536
#define IDENTIFY_HASHTABLE_GROWTH 1

#define REMEMBER_HASHTABLE_SIZE 65536
#define REMEMBER_HASHTABLE_GROWTH 1
#define REMEMBER_LIMIT 65536

asserted procedure cl_initializeRemember(functionName: Id): Void;
   begin scalar hashTable;
      if REMEMBER_LIMIT <= 0 then
         return;
      hashTable := mkhash(REMEMBER_HASHTABLE_SIZE, 'equal, REMEMBER_HASHTABLE_GROWTH);
      put(functionName, 'remember, {hashTable, nil, nil, 0, REMEMBER_LIMIT})
   end;

cl_initializeRemember('cl_simplat);

asserted procedure cl_simplat(atf: AtFormula, sop: Id): QfFormula;
   % Common logic simplify atomic formula. The result is equivalent to atf. sop contains the logical
   % operator of the boolean level where atf occurred. This can help to decide about splitting or
   % not splitting atf. The actual simplification takes place in rl_simplat1 in the current
   % context. Here we implement the equivalent of a remember option.
   begin scalar hashTable, queue, lastNode, size, limit, key, entry, simplificationResult,
                oldestEntry;
      if REMEMBER_LIMIT = 0 then
         return rl_simplat1(atf, sop);
      {hashTable, queue, lastNode, size, limit} := get('cl_simplat, 'remember);
      key := {atf, sop, rl_cid!*, SiAtEnv_new()};
      if (entry := gethash(key, hashTable)) then
         return entry;
      simplificationResult := rl_simplat1(atf, sop);
      if size = limit then <<
         ASSERT( length(queue) = size );
         oldestEntry := pop queue;
         if null queue then
            lastNode := nil;
         remhash(oldestEntry, hashTable)
      >> else
         size := size + 1;
      if null queue then <<
         queue := {key};
         lastNode := queue
      >> else <<
         cdr lastNode := key . nil;
         lastNode := cdr lastNode
      >>;
      puthash(key, hashTable, simplificationResult);
      put('cl_simplat, 'remember, {hashTable, queue, lastNode, size, limit});
      return simplificationResult
   end;

asserted procedure cl_initializeIdentifyAt(): Void;
   begin scalar hashTable;
      hashTable := mkhash(IDENTIFY_HASHTABLE_SIZE, 'equal, IDENTIFY_HASHTABLE_GROWTH);
      put('cl_identifyat, 'hashTable, hashTable)
   end;

cl_initializeIdentifyAt();

asserted procedure cl_identifyat(atf: AtFormula): AtFormula;
   begin scalar hashTable, entry;
      hashTable := get('cl_identifyat, 'hashTable);
      if (entry := gethash(atf, hashTable)) then
         return entry;
      puthash(atf, hashTable, atf);
      put('cl_identifyat, 'hashTable, hashTable);
      return atf
   end;

endmodule;

end;
