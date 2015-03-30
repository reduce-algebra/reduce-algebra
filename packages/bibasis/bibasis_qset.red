module bibasis_qset;

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
% Q = triple_1 . ... . triple_n . (nil . nil) and triple_i <= triple_(i+1)


expr procedure sortedtriplelistinsert(triplelist, triple);
begin scalar tmpmonom, triplelistiterator;
    tmpmonom := triplegetlm(triple);
    triplelistiterator := triplelist;
    while and(car(triplelistiterator),
              neq(monomcompare(triplegetlm(car(triplelistiterator)), tmpmonom), 1)) do
    <<
        triplelistiterator := cdr(triplelistiterator);
    >>;
    bibasis_insert(triplelistiterator, triple);
end;


inline procedure setqreset(); fluidbibasissetq := (nil . nil);
inline procedure setqisempty(); null(car(fluidbibasissetq));
inline procedure setqinsert(triple); sortedtriplelistinsert(fluidbibasissetq, triple);


expr procedure setqinsertlist(triplelist);
begin scalar iteratorq, iteratorlist; integer monomcompare;
    iteratorq := fluidbibasissetq;
    iteratorlist := triplelist;
    while and(car(iteratorq), car(iteratorlist)) do 
    <<
        monomcompare := monomcompare(triplegetlm(car(iteratorq)), triplegetlm(car(iteratorlist)));
        if or(monomcompare = -1,
              monomcompare = 0) then
        <<
            iteratorq := cdr(iteratorq);
        >>
        else
        <<
            bibasis_insert(iteratorq, car(iteratorlist));
            iteratorq := cdr(iteratorq);
            iteratorlist := cdr(iteratorlist);
        >>;
    >>;
    if car(iteratorlist) then
    <<
        bibasis_remove(rplacd(iteratorq, iteratorlist));
    >>;
end;


expr procedure setqget();
begin scalar triple;
    triple := car(fluidbibasissetq);
    bibasis_remove(fluidbibasissetq);
    return triple;
end;


expr procedure setqdeletedescendants(ancestorid);
begin scalar currenttriple;
    currenttriple := fluidbibasissetq;
    while car(currenttriple) do
    <<
        if triplegetancestorid(car(currenttriple)) = ancestorid then
        <<
            bibasis_remove(currenttriple);
        >>
        else
        <<
            currenttriple := cdr(currenttriple);
        >>;
    >>;
end;


expr procedure setqprint();
begin scalar currenttriple;
    prin2 "SetQ( ";
    currenttriple := fluidbibasissetq;
    while car(currenttriple) do
    <<
        prin2 car(currenttriple);
        prin2 ", ";
        currenttriple := cdr(currenttriple);
    >>;
    prin2 " )"; 
    terpri();
end;


endmodule;
end;
