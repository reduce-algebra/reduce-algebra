module bibasis_janet_tree;

% Authors:  Yuri A. Blinkov
%           Saratov State University
%           Saratov, Russia
%           e-mail: BlinkovUA@info.sgu.ru
%
%           Mikhail V. Zinin
%           Joint Instutite for Nuclear Research
%           Dubna, Russia
%           e-mail: mzinin@gmail.com
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAG


%----------------------------------------------------------------------------
% JanetTreeNode = (degree . triple) . (nextdeg . nextvar)
%   integer   degree
%   Triple    ph
%   JanetTreeNode nextdeg
%   JanetTreeNode nextvar
% ph != NIL && nextvar == NIL && nextdeg == NIL  
% ph == NIL && nextvar != NIL && (nextdeg == NIL || degree < nextdeg.degree)

% The following structure is only used in this file.

inline procedure createjanettreenode(degree, triple, nextdegree, nextvariable);
   (degree . triple) . (nextdegree . nextvariable);

accessors (janettreenodegetdegree . janettreenodegettriple) .
          (janettreenodegetnextdegree . janettreenodegetnextvariable);

inline procedure janettreereset(); fluidbibasisjanettreerootnode := nil;


expr procedure janettreenodebuild(degree, variable, triple);
begin scalar tmpnode1, tmpnode2, monom;
    monom := triplegetlm(triple);
    tmpnode1 := createjanettreenode(monomgetvariabledegree(monom, variable), nil, nil, nil);
    tmpnode2 := tmpnode1;
    
    while igreaterp(degree, monomgetvariabledegree(monom, variable)) do 
    <<
        degree := idifference(degree, monomgetvariabledegree(monom, variable));
        variable := iadd1(variable);
        janettreenodegetnextvariable(tmpnode2) := createjanettreenode(monomgetvariabledegree(monom, variable), nil, nil, nil);
        tmpnode2 := janettreenodegetnextvariable(tmpnode2);
    >>;
    janettreenodegettriple(tmpnode2) := triple;
    return tmpnode1;
end;


expr procedure janettreenodeprint(node);
begin
    if null(node) then
    <<
        prin2 "((nil . nil) . (nil . nil))"; terpri();
    >>
    else
    <<
        prin2 "(("; prin2 janettreenodegetdegree(node); prin2 ") . ("; 
        prin2 if janettreenodegettriple(node) then triplegetlm(janettreenodegettriple(node)) else "nil"; 
        prin2 ")) . ((";
        
        if janettreenodegetnextdegree(node) then janettreenodeprint(janettreenodegetnextdegree(node)) else prin2 "nil";
        prin2 ") . (";
        if janettreenodegetnextvariable(node) then janettreenodeprint(janettreenodegetnextvariable(node)) else prin2 "nil";
        prin2 "))";
    >>;
end;


inline procedure janettreeprint(); janettreenodeprint(fluidbibasisjanettreerootnode);


expr procedure janettreeinsert(triple);
begin integer variable, degree; scalar nodeiterator, tmpnode, monom;
    monom := triplegetlm(triple);
    degree := monomgetdegree(monom);
    variable := 1;
    if null(fluidbibasisjanettreerootnode) then
    <<
        fluidbibasisjanettreerootnode := janettreenodebuild(degree, variable, triple);
    >>
    else
    <<
        nodeiterator := fluidbibasisjanettreerootnode;

        while degree > 0 do
        <<
            while and(nodeiterator,
                      janettreenodegetdegree(nodeiterator) < monomgetvariabledegree(monom, variable), 
                      janettreenodegetnextdegree(nodeiterator)) do 
            <<
                nodeiterator := janettreenodegetnextdegree(nodeiterator);
            >>;
   
            if and(nodeiterator,
                   janettreenodegetdegree(nodeiterator) > monomgetvariabledegree(monom, variable)) then
            <<
                tmpnode := janettreenodebuild(degree, variable, triple);
                degree := 0;
                
                janettreenodegetnextdegree(nodeiterator) := createjanettreenode(janettreenodegetdegree(nodeiterator),
                                                                                janettreenodegettriple(nodeiterator),
                                                                                janettreenodegetnextdegree(nodeiterator),
                                                                                janettreenodegetnextvariable(nodeiterator));
                janettreenodegetnextvariable(nodeiterator) := janettreenodegetnextvariable(tmpnode);
                janettreenodegetdegree(nodeiterator) := janettreenodegetdegree(tmpnode);
                janettreenodegettriple(nodeiterator) := janettreenodegettriple(tmpnode);
            >>
            else if and(nodeiterator,
                        janettreenodegetdegree(nodeiterator) = monomgetvariabledegree(monom, variable),
                        janettreenodegetnextvariable(nodeiterator)) then 
            <<
                degree := degree - monomgetvariabledegree(monom, variable);
                variable := variable + 1;
                nodeiterator := janettreenodegetnextvariable(nodeiterator);
            >>
            else if not(null(nodeiterator)) then
            <<
                janettreenodegetnextdegree(nodeiterator) := janettreenodebuild(degree, variable, triple);
                degree := 0;
            >>;
        >>;
    >>;
end;


expr procedure janettreefind(monom);
if null(fluidbibasisjanettreerootnode) then
    nil
else begin scalar result, nodeiterator; integer degree, variable;
    nodeiterator := fluidbibasisjanettreerootnode;
    degree := monomgetdegree(monom);
    variable := 1;
    while igreaterp(degree, 0) do 
    <<
        while and(janettreenodegetdegree(nodeiterator) < monomgetvariabledegree(monom, variable), 
                 janettreenodegetnextdegree(nodeiterator)) do 
        <<
            nodeiterator := janettreenodegetnextdegree(nodeiterator);
        >>;

        if neq(janettreenodegetdegree(nodeiterator), monomgetvariabledegree(monom, variable)) then
        <<
            degree := 0;
        >>
        else if janettreenodegetnextvariable(nodeiterator) then 
        <<
            degree := idifference(degree, monomgetvariabledegree(monom, variable));
            variable := iadd1(variable);
            nodeiterator := janettreenodegetnextvariable(nodeiterator);
        >>
        else 
        <<
            degree := 0;
            result := janettreenodegettriple(nodeiterator);
        >>;
    >>;
    return result;
end;


expr procedure janettreedelete(monom);
if not(null(fluidbibasisjanettreerootnode)) then
begin scalar nodeiterator, nodeiteratorparent, lastbifurcation, lastbifurcationparent, break, vardirection; integer variable, degree;
    nodeiterator := fluidbibasisjanettreerootnode;
    nodeiteratorparent := nil;
    lastbifurcation := fluidbibasisjanettreerootnode;
    lastbifurcationparent := nil;
    variable := 1;
    
    while not(break) do
    <<
        degree := monomgetvariabledegree(monom, variable);

        while and(nodeiterator,
                  ilessp(janettreenodegetdegree(nodeiterator), degree)) do
        <<
            if eq(lastbifurcation, nodeiterator) then
            <<
                vardirection := nil;
            >>;
            
            nodeiteratorparent := nodeiterator;
            nodeiterator := janettreenodegetnextdegree(nodeiterator);
            
            if and(nodeiterator,
                   janettreenodegetnextdegree(nodeiterator),
                   janettreenodegetnextvariable(nodeiterator)) then
            <<
                lastbifurcation := nodeiterator;
                lastbifurcationparent := nodeiteratorparent;
            >>;
        >>;

        if and(nodeiterator,
               janettreenodegetnextvariable(nodeiterator)) then
        <<
            variable := iadd1(variable);
            if eq(lastbifurcation, nodeiterator) then
            <<
                vardirection := t;
            >>;
            
            nodeiteratorparent := nodeiterator;
            nodeiterator := janettreenodegetnextvariable(nodeiterator);
            
            if and(nodeiterator,
                   janettreenodegetnextdegree(nodeiterator),
                   janettreenodegetnextvariable(nodeiterator)) then
            <<
                lastbifurcation := nodeiterator;
                lastbifurcationparent := nodeiteratorparent;
            >>;
        >>
        else
        <<
            break := t;
        >>;
    >>;
    
    if vardirection then
    <<
        if eq(lastbifurcation, fluidbibasisjanettreerootnode) then
        <<
            % if last bifurcation is root node, just replace root node with its next degree subtree
            fluidbibasisjanettreerootnode := janettreenodegetnextdegree(fluidbibasisjanettreerootnode);
        >>
        else
        <<
            % connect bifurcation parent with bifurcation's next degree subtree
            % as far as we are in binary ring, max degree is 1 and bifurcation is next degree subtree of it's parent
            janettreenodegetnextvariable(lastbifurcationparent) := janettreenodegetnextdegree(lastbifurcation);
        >>;
    >>
    else
    <<
        janettreenodegetnextdegree(lastbifurcation) := nil;
    >>;
    
    % there were no bifurcations, i.e. lastBifurcation = FluidBibasisJanetTreeRootNode
    if not(or(janettreenodegetnextdegree(lastbifurcation), 
              janettreenodegetnextvariable(lastbifurcation))) then
    <<
        fluidbibasisjanettreerootnode := nil;
    >>;
end;


endmodule;
end;
