module bibasis_involutive;

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


expr procedure init();
begin integer i;
    fluidbibasisreversedvariables := reverse(fluidbibasisvariables);
    
    initmonomials();
    
    i := 0;
    fluidbibasissinglevariablemonomialsa := for each v in fluidbibasisvariables collect(v . getv(fluidbibasissinglevariablemonomialss, i := i+1));
    
    settreset();
    setqreset();
    
    fluidbibasisreductionsmade := 0;
    fluidbibasisnormalforms := 0;
    fluidbibasisnonzeronormalforms := 0;
end;


expr procedure sortedpolynomlistinsert(polynomlist, polynom);
begin scalar polynomlistiterator;
    polynomlistiterator := polynomlist;
    while and(car(polynomlistiterator),
              neq(polynomcompare(car(polynomlistiterator), polynom), -1)) do
    <<
        polynomlistiterator := cdr(polynomlistiterator);
    >>;
    bibasis_insert(polynomlistiterator, polynom);
end;


expr procedure polynomlistfinddivisor(polynomlist, polynom, togroebner);
if or(null(polynomgetlm(polynom)),
      null(car(polynomlist))) then
    nil
else begin scalar tmpmonom, currentpolynom, break;
    tmpmonom := polynomgetlm(polynom);
    currentpolynom := polynomlist;
    
    while and(car(currentpolynom), not(break)) do
    <<
        if or(and(togroebner, monomisdivisibleby(tmpmonom, polynomgetlm(car(currentpolynom)))),
              and(not(togroebner), monomispommaretdivisibleby(tmpmonom, polynomgetlm(car(currentpolynom))))
              ) then
        <<
            break := t;
        >>
        else
        <<
            currentpolynom := cdr(currentpolynom);
        >>;
    >>;
    return car(currentpolynom);
end;


%returns new polynom, the argument polynom itself will be destroyed
expr procedure polynomlistreduce(polynomlist, polynom, togroebner);
begin scalar result, divisor;
    result := (nil . nil);
    if null(polynomgetlm(polynom)) then
    <<
        return result;
    >>;
    
    while polynomgetlm(polynom) do
    <<
        divisor := polynomlistfinddivisor(polynomlist, polynom, togroebner);
        while divisor do
        <<
            polynomreduceby(polynom, divisor);
            divisor := polynomlistfinddivisor(polynomlist, polynom, togroebner);
        >>;
        if polynomgetlm(polynom) then
        <<
            polynomadd(result, (polynomgetlm(polynom) . (nil . nil)));
            bibasis_remove(polynom);
        >>;
    >>;
    
    return result;
end;


expr procedure polynomlistautoreduce(polynomlist, togroebner);
begin scalar tmppolynomlist, tmppolynom, tmpmonom, tmppolynomiterator;
    tmppolynomlist := (nil . nil);
    
    while car(polynomlist) do
    <<
        tmppolynom := polynomlistreduce(tmppolynomlist, car(polynomlist), togroebner);
        bibasis_remove(polynomlist);
        
        if polynomgetlm(tmppolynom) then
        <<
            tmpmonom := polynomgetlm(tmppolynom);
            tmppolynomiterator := tmppolynomlist;
            while car(tmppolynomiterator) do
            <<
                if monomisdivisibleby(polynomgetlm(car(tmppolynomiterator)), tmpmonom) then
                <<
                    pushback(polynomlist, car(tmppolynomiterator));
                    bibasis_remove(tmppolynomiterator);
                >>
                else
                <<
                    tmppolynomiterator := cdr(tmppolynomiterator);
                >>;
            >>;
            pushback(tmppolynomlist, tmppolynom);
        >>;
    >>;

    tmppolynomiterator := tmppolynomlist;
    while car(tmppolynomiterator) do
    <<
        tmppolynom := car(tmppolynomiterator);
        bibasis_remove(tmppolynomiterator);

        tmppolynom := polynomlistreduce(tmppolynomlist, tmppolynom, togroebner);

        if tmppolynom and polynomgetlm(tmppolynom) then
        <<
            bibasis_insert(tmppolynomiterator, tmppolynom);
            tmppolynomiterator := cdr(tmppolynomiterator);
        >>;
    >>;

    return tmppolynomlist;
end;


%returns new polynom, the argument polynom itself will be destroyed
expr procedure normalform(polynom);
begin scalar involutivedivisor, normalform;
    normalform := (nil . nil);
    if null(polynomgetlm(polynom)) then
    <<
        return normalform;
    >>;
    fluidbibasisnormalforms := iadd1(fluidbibasisnormalforms);

    while polynomgetlm(polynom) do
    <<
        involutivedivisor := janettreefind(polynomgetlm(polynom));
        while involutivedivisor do
        <<
            polynomheadreduceby(polynom, triplegetpolynom(involutivedivisor));
            if polynomgetlm(polynom) then
            <<
                involutivedivisor := janettreefind(polynomgetlm(polynom));
            >>
            else
            <<
                involutivedivisor := nil;
            >>;
        >>;
        if polynomgetlm(polynom) then
        <<
            polynomadd(normalform, (polynomgetlm(polynom) . (nil . nil)));
            bibasis_remove(polynom);
        >>;
    >>;

    return normalform;
end;


expr procedure constructinvolutivebasis(polynomlist, togroebner);
begin scalar tmptriple, tmpmonom, normalform, normalformlm, settiterator, newtriplelist;
    polynomlist := polynomlistautoreduce(polynomlist, t);
    while car(polynomlist) do
    <<
        setqinsert(createtriple(car(polynomlist)));
        polynomlist := cdr(polynomlist);
    >>;

    while not(setqisempty()) do
    <<
        tmptriple := setqget();
        tmpmonom := triplegetlm(tmptriple);
        normalform := normalform(triplegetpolynom(tmptriple));
        normalformlm := polynomgetlm(normalform);

        if normalformlm then
        <<
            fluidbibasisnonzeronormalforms := iadd1(fluidbibasisnonzeronormalforms);
            
            newtriplelist := (nil . nil);
            settiterator := fluidbibasissett;
            while car(settiterator) do
            <<
                if monomisdivisibleby(triplegetlm(car(settiterator)), normalformlm) then
                <<
                    setqdeletedescendants(triplegetid(car(settiterator)));
                    sortedtriplelistinsert(newtriplelist, car(settiterator));
                    janettreedelete(triplegetlm(car(settiterator)));
                    bibasis_remove(settiterator);
                >>
                else
                <<
                    settiterator := cdr(settiterator);
                >>;
            >>;

            if eq(tmpmonom, normalformlm) then
            <<
                settinsert(createtriplewithancestor(normalform, triplegetancestorid(tmptriple)));
                triplesetprolongset(car(fluidbibasissett), triplegetprolongset(tmptriple));
            >>
            else
            <<
                settinsert(createtriple(normalform));
            >>;
            settcollectnonmultiprolongations(newtriplelist);
            
            if eqn(monomgetdegree(normalformlm), 0) then
            <<
                setqreset();
            >>
            else
            <<
                setqinsertlist(newtriplelist);
            >>;
        >>;
    >>;

    polynomlist := (nil . nil);
    settiterator := fluidbibasissett;
    while car(settiterator) do
    <<
        sortedpolynomlistinsert(polynomlist, triplegetpolynom(car(settiterator)));
        settiterator := cdr(settiterator);
    >>;
    polynomlist := polynomlistautoreduce(polynomlist, togroebner);
    return polynomlist;
end;


endmodule;
end;
