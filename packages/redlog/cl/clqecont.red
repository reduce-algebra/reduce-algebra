module clqecont;
% A container of QeNode working nodes.

revision('clqecont, "$Id$");

copyright('clqecont, "(c) 2021 A. Dolzmann, T. Sturm");

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

#define QECONT_TAG 0
#define QECONT_NODES 1
#define QECONT_LASTNODE 2
#define QECONT_TRAVERSALMODE 3
#define QECONT_HASHTABLE 4
#define QECONT_REQUESTEDADDITIONS 5
#define QECONT_EFFECTIVEADDITIONS 6
#define QECONT_UPLIM 6

asserted procedure QeCont_new(traversalMode: Id): Vector;
   % QE data for a block new.
   begin scalar co;
      co := mkvect(QECONT_UPLIM);
      putv(co, QECONT_TAG, 'qeco);
      putv(co, QECONT_NODES, nil);                    % list (stack or queue) of QE tree working nodes
      putv(co, QECONT_TRAVERSALMODE, traversalMode);  % 'bfs (breadth-first search) or 'dfs (depth-first search)
      if traversalMode eq 'dfs then <<
         putv(co, QECONT_LASTNODE, 'unused);
         putv(co, QECONT_HASHTABLE, nil)              % hashed dynamic programming data
      >> else <<
         ASSERT( traversalMode eq 'bfs );
         putv(co, QECONT_LASTNODE, nil);              % the last node in nodes
         putv(co, QECONT_HASHTABLE, 'unused)
      >>;
      putv(co, QECONT_REQUESTEDADDITIONS, 0);
      putv(co, QECONT_EFFECTIVEADDITIONS, 0);
      return co
   end;

asserted procedure QeCont_add(co: Vector, new: List): Vector;
   begin scalar nodes, lastNode;
      if null new then
         return co;
      nodes := getv(co, QECONT_NODES);
      if getv(co, QECONT_TRAVERSALMODE) eq 'bfs then <<
         lastNode := getv(co, QECONT_LASTNODE);
         if null lastNode then
            lastNode := nodes := {pop new};
         for each node in new do <<
            putv(co, QECONT_REQUESTEDADDITIONS, getv(co, QECONT_REQUESTEDADDITIONS) + 1);
            if not member(node, nodes) then <<
               cdr lastNode := node . nil;
               lastNode := cdr lastNode;
               putv(co, QECONT_EFFECTIVEADDITIONS, getv(co, QECONT_EFFECTIVEADDITIONS) + 1)
            >>
         >>;
         putv(co, QECONT_NODES, nodes);
         putv(co, QECONT_LASTNODE, lastNode)
      >> else <<
         ASSERT( getv(co, QECONT_TRAVERSALMODE) eq 'dfs );
         for each node in new do <<
            putv(co, QECONT_REQUESTEDADDITIONS, getv(co, QECONT_REQUESTEDADDITIONS) + 1);
            if not lto_hmember(node, getv(co, QECONT_HASHTABLE), 'co_hfn) then <<
               putv(co, QECONT_HASHTABLE, lto_hinsert(node, getv(co, QECONT_HASHTABLE), 'co_hfn));
               nodes := node . nodes;
               putv(co, QECONT_EFFECTIVEADDITIONS, getv(co, QECONT_EFFECTIVEADDITIONS) + 1)
            >>
         >>;
         putv(co, QECONT_NODES, nodes)
      >>;
      return co
   end;

asserted procedure QeCont_firstNode(co: Vector): List;
   car getv(co, QECONT_NODES);

asserted procedure QeCont_fetch(co: Vector): List;
   begin scalar nodes, node;
      nodes := getv(co, QECONT_NODES);
      ASSERT( not null nodes );
      node := pop nodes;
      if null nodes and getv(co, QECONT_TRAVERSALMODE) eq 'bfs then
         putv(co, QECONT_LASTNODE, nil);
      putv(co, QECONT_NODES, nodes);
      return node
   end;

asserted procedure QeCont_isEmpty(co: Vector): Boolean;
   null getv(co, QECONT_NODES);

asserted procedure QeCont_length(co: Vector): Integer;
   length getv(co, QECONT_NODES);

asserted procedure QeCont_statistics(co: Vector): DottedPair;
   % Returns the maximum length of the "Variables" fields in the contained nodes, along with the
   % number of occurrences of corresponding nodes. This is used for verbose output with DFS.
   begin integer thisLength, maxLength, maxCount;
      for each node in getv(co, QECONT_NODES) do <<
         thisLength := length(QeNode_getVariables(node));
         if thisLength > maxLength then <<
            maxLength := thisLength;
            maxCount := 1
         >> else if thisLength = maxLength then <<
            maxCount := maxCount + 1
         >>
      >>;
      return maxLength . maxCount
   end;

asserted procedure QeCont_getEffectiveAdditions(co: Vector): Integer;
   getv(co, QECONT_EFFECTIVEADDITIONS);

asserted procedure QeCont_setEffectiveAdditions(co: Vector, n: Integer): Vector;
   << putv(co, QECONT_EFFECTIVEADDITIONS, n); co >>;

asserted procedure QeCont_getRequestedAdditions(co: Vector): Integer;
   getv(co, QECONT_REQUESTEDADDITIONS);

asserted procedure QeCont_setRequestedAdditions(co: Vector, n: Integer): Vector;
   << putv(co, QECONT_REQUESTEDADDITIONS, n); co >>;

endmodule;

end;
