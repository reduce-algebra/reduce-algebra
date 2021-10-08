module bhashtable;

revision('bhashtable, "$Id$");

copyright('bhashtable, "(c) 2021 T. Sturm");

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

#define BHASHTABLE_TAG 0
#define BHASHTABLE_HTABLE 1
#define BHASHTABLE_QUEUE 2
#define BHASHTABLE_LASTNODE 3
#define BHASHTABLE_NUMELEMS 4
#define BHASHTABLE_BOUND 5
#define BHASHTABLE_UPLIM 5

asserted procedure BHashTable_new(size: Integer, growth: Integer, bound: Integer): Vector;
   begin scalar bHashTable;
      bHashTable := mkvect(BHASHTABLE_UPLIM);
      putv(bHashTable, BHASHTABLE_TAG,      'BHashTable);
      putv(bHashTable, BHASHTABLE_HTABLE,   mkhash(size, 'equal, growth));
      putv(bHashTable, BHASHTABLE_QUEUE,    nil);
      putv(bHashTable, BHASHTABLE_LASTNODE, nil);
      putv(bHashTable, BHASHTABLE_NUMELEMS, 0);
      putv(bHashTable, BHASHTABLE_BOUND,    bound);
      return bHashTable
   end;

asserted procedure BHashTable_gethash(key: Any, bHashTable: Vector): ExtraBoolean;
   % We adopt the argument order of gethash instead of using our usual object-oriented order.
   gethash(key, getv(bHashTable, BHASHTABLE_HTABLE));

asserted procedure BHashTable_puthash(key: Any, bHashTable: Vector, entry: Any);
   % We adopt the argument order of puthash instead of using our usual object-oriented order.
   begin scalar hashTable, queue, lastNode, numberOfElements, oldestEntry;
      hashTable := getv(bHashTable, BHASHTABLE_HTABLE);
      queue := getv(bHashTable, BHASHTABLE_QUEUE);
      lastNode := getv(bHashTable, BHASHTABLE_LASTNODE);
      numberOfElements := getv(bHashTable, BHASHTABLE_NUMELEMS);
      if eqn(numberOfElements, getv(bHashTable, BHASHTABLE_BOUND)) then <<
         ASSERT( length(queue) = numberOfElements );
         oldestEntry := pop queue;
         if null queue then
            lastNode := nil;
         remhash(oldestEntry, hashTable)
      >> else
         numberOfElements := numberOfElements + 1;
      if null queue then <<
         queue := {key};
         lastNode := queue
      >> else <<
         cdr lastNode := key . nil;
         lastNode := cdr lastNode
      >>;
      puthash(key, hashTable, entry);
      putv(bHashTable, BHASHTABLE_QUEUE, queue);
      putv(bHashTable, BHASHTABLE_LASTNODE, lastNode);
      putv(bHashTable, BHASHTABLE_NUMELEMS, numberOfElements)
   end;

endmodule;

end;
