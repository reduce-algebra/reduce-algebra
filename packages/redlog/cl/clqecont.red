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
#define QECONT_DYNAMICPROGRAMMING 4
#define QECONT_HASHTABLE 5
#define QECONT_REQUESTEDADDITIONS 6
#define QECONT_EFFECTIVEADDITIONS 7
#define QECONT_UPLIM 7

#define QECONT_HASHTABLE_SIZE 65536
#define QECONT_HASHTABLE_GROWTH 1.5

asserted procedure QeCont_new(traversalMode: Id, dynamicProgramming: Boolean): Vector;
   % QE data for a block new.
   begin scalar co, h;
      co := mkvect(QECONT_UPLIM);
      putv(co, QECONT_TAG, 'QeCont);
      putv(co, QECONT_NODES, nil);                         % list (stack or queue) of QE tree working nodes
      putv(co, QECONT_TRAVERSALMODE, traversalMode);       % 'bfs (breadth-first search) or 'dfs (depth-first search)
      putv(co, QECONT_DYNAMICPROGRAMMING, dynamicProgramming);
      if traversalMode eq 'bfs then <<
         putv(co, QECONT_LASTNODE, nil);                   % the last node in nodes
         putv(co, QECONT_HASHTABLE, 'unused)
      >> else if traversalMode eq 'dfs and dynamicProgramming then <<
         h := mkhash(QECONT_HASHTABLE_SIZE, 'equal, QECONT_HASHTABLE_GROWTH);
         putv(co, QECONT_HASHTABLE, h);                    % hashed dynamic programming data
         putv(co, QECONT_LASTNODE, 'unused)
      >> else <<
         ASSERT( traversalMode eq 'dfs and not dynamicProgramming );
         putv(co, QECONT_LASTNODE, 'unused);
         putv(co, QECONT_HASHTABLE, 'unused)
      >>;
      putv(co, QECONT_REQUESTEDADDITIONS, 0);
      putv(co, QECONT_EFFECTIVEADDITIONS, 0);
      return co
   end;

asserted procedure QeCont_print(co: Vector, externalIndent: String): Vector;
   begin scalar !*nat, indent, nextIndent;
      indent := "  ";
      nextIndent := lto_sconcat2(externalIndent, indent);
      ioto_tprin2t {externalIndent, "{"};
      ioto_tprin2t {externalIndent, indent, "Class:              ", getv(co, QECONT_TAG)};
      ioto_tprin2  {externalIndent, indent, "Nodes:              "};
      QeNode_printList(getv(co, QECONT_NODES), nextIndent);
      ioto_tprin2t {externalIndent, indent, "LastNode:           ",
         if getv(co, QECONT_LASTNODE) eq 'unused then 'unused else "(hidden)"};
      ioto_tprin2t {externalIndent, indent, "TraversalMode:      ", getv(co, QECONT_TRAVERSALMODE)};
      ioto_tprin2t {externalIndent, indent, "HashTable:          ",
         if getv(co, QECONT_HASHTABLE) eq 'unused then 'unused else "(hidden)"};
      ioto_tprin2t {externalIndent, indent, "RequestedAdditions: ", getv(co, QECONT_REQUESTEDADDITIONS)};
      ioto_tprin2t {externalIndent, indent, "EffectiveAdditions: ", getv(co, QECONT_EFFECTIVEADDITIONS)};
      ioto_tprin2t {externalIndent, "}"};
      return co
   end;

asserted procedure QeCont_add(co: Vector, newNodes: List): Vector;
   begin scalar nodes, lastNode, hashTable;
      if null newNodes then
         return co;
      if getv(co, QECONT_TRAVERSALMODE) eq 'bfs then <<
         nodes := getv(co, QECONT_NODES);
         lastNode := getv(co, QECONT_LASTNODE);
         if null lastNode then <<
            lastNode := nodes := {pop newNodes};
            putv(co, QECONT_REQUESTEDADDITIONS, getv(co, QECONT_REQUESTEDADDITIONS) + 1);
            putv(co, QECONT_EFFECTIVEADDITIONS, getv(co, QECONT_EFFECTIVEADDITIONS) + 1)
         >>;
         for each node in newNodes do <<
            putv(co, QECONT_REQUESTEDADDITIONS, getv(co, QECONT_REQUESTEDADDITIONS) + 1);
            if not QeCont_member(node, nodes) then <<
               cdr lastNode := node . nil;
               lastNode := cdr lastNode;
               putv(co, QECONT_EFFECTIVEADDITIONS, getv(co, QECONT_EFFECTIVEADDITIONS) + 1)
            >>
         >>;
         putv(co, QECONT_NODES, nodes);
         putv(co, QECONT_LASTNODE, lastNode);
         return co
      >>;
      ASSERT( getv(co, QECONT_TRAVERSALMODE) eq 'dfs );
      if getv(co, QECONT_DYNAMICPROGRAMMING) then <<
         nodes := getv(co, QECONT_NODES);
         for each node in newNodes do <<
            putv(co, QECONT_REQUESTEDADDITIONS, getv(co, QECONT_REQUESTEDADDITIONS) + 1);
            hashTable := getv(co, QECONT_HASHTABLE);
            if null gethash(QeNode_getVariables(node) . QeNode_getFormula(node), hashTable) then <<
               puthash(QeNode_getVariables(node) . QeNode_getFormula(node), hashTable, t);
               putv(co, QECONT_HASHTABLE, hashTable);
               nodes := node . nodes;
               putv(co, QECONT_EFFECTIVEADDITIONS, getv(co, QECONT_EFFECTIVEADDITIONS) + 1)
            >>
         >>;
         putv(co, QECONT_NODES, nodes);
         return co
      >>;
      ASSERT( getv(co, QECONT_TRAVERSALMODE) eq 'dfs and not getv(co, QECONT_DYNAMICPROGRAMMING) );
      nodes := getv(co, QECONT_NODES);
      for each node in newNodes do <<
         putv(co, QECONT_REQUESTEDADDITIONS, getv(co, QECONT_REQUESTEDADDITIONS) + 1);
         nodes := node . nodes;
         putv(co, QECONT_EFFECTIVEADDITIONS, getv(co, QECONT_EFFECTIVEADDITIONS) + 1)
      >>;
      putv(co, QECONT_NODES, nodes);
      return co
   end;

asserted procedure QeCont_member(node: List, nodes: List): Boolean;
   begin scalar found, variables, formula, currentNode;
      found := nil;
      variables := QeNode_getVariables(node);
      formula := QeNode_getFormula(node);
      while not null nodes and not found do <<
         currentNode := pop nodes;
         found := QeNode_getVariables(currentNode) = variables and QeNode_getFormula(currentNode) = formula
      >>;
      return found
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

asserted procedure QeCont_statistics(co: Vector): List;
   begin scalar statistics, statisticsEntry;
         integer thisLength, maxLength;
      for each node in getv(co, QECONT_NODES) do <<
         thisLength := length(QeNode_getVariables(node));
         if thisLength > maxLength then
            maxLength := thisLength;
         statisticsEntry := assoc(thisLength, statistics);
         if statisticsEntry then
            cdr statisticsEntry := cdr statisticsEntry + 1
         else
            push(thisLength . 1, statistics)
      >>;
      for key := 1 : maxLength do
         if not assoc(key, statistics) then
            push(key . 0, statistics);
      statistics := sort(statistics, function(lambda p1, p2; car p1 > car p2));
      return mapcar(statistics, 'cdr)
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
