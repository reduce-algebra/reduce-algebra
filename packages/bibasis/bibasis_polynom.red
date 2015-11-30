module bibasis_polynom;

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
% POSSIBILITY OF SUCH DAMAGE.


%----------------------------------------------------------------------------
% poly k_1 + ... k_n = k_1 . ... . k_n . (nil . nil)


accessors (polynomgetlm . _);

expr procedure polynomclone(polynom);
begin scalar tmppolynom, polynomiterator;
    polynomiterator := polynom;
    while polynomiterator do
    <<
        tmppolynom := monomclone(car(polynomiterator)) . tmppolynom;
        polynomiterator := cdr(polynomiterator);
    >>;
    return reverse(tmppolynom);
end;


% writes result in polynom
expr procedure polynommultiplybyvariable(polynom, variable);
begin scalar tmppolynomnovariable, polynomiterator;
    polynomiterator := polynom;
    while car(polynomiterator) do
    <<
        if eqn(monomgetvariabledegree(car(polynomiterator), variable), 0) then
        <<
            tmppolynomnovariable := car(polynomiterator) . tmppolynomnovariable;
            bibasis_remove(polynomiterator);
        >>
        else
        <<
            polynomiterator := cdr(polynomiterator);
        >>;
    >>;
    tmppolynomnovariable := nil . tmppolynomnovariable;
    tmppolynomnovariable := reverse(tmppolynomnovariable);
    
    polynomiterator := tmppolynomnovariable;
    while car(polynomiterator) do
    <<
        monommultiplybyvariable(car(polynomiterator), variable);
        polynomiterator := cdr(polynomiterator);
    >>;
    
    polynomadd(polynom, tmppolynomnovariable);
end;


% returns new polynom
expr procedure polynommultiplybymonom(polynom, monom);
if null(polynom) then
    nil
else begin scalar tmppolynom, exponent;
    tmppolynom := polynomclone(polynom);
    exponent := monomgetexponent(monom);
    while car(exponent) do
    <<
        polynommultiplybyvariable(tmppolynom, car(exponent));
        exponent := cdr(exponent);
    >>;
    return tmppolynom;
end;


% writes result in polynom1
expr procedure polynomadd(polynom1, polynom2);
begin scalar tmppolynom1, tmppolynom2; integer monomcompare;
    tmppolynom1 := polynom1;
    tmppolynom2 := polynom2;
    while and(polynomgetlm(tmppolynom1), polynomgetlm(tmppolynom2)) do 
    <<
        monomcompare := monomcompare(polynomgetlm(tmppolynom1), polynomgetlm(tmppolynom2));
        if monomcompare = 1 then
        <<
            tmppolynom1 := cdr(tmppolynom1);
        >>
        else if monomcompare = -1 then 
        <<
            bibasis_insert(tmppolynom1, car(tmppolynom2));
            tmppolynom1 := cdr(tmppolynom1);
            tmppolynom2 := cdr(tmppolynom2);
        >>
        else
        <<
            bibasis_remove(tmppolynom1);
            tmppolynom2 := cdr(tmppolynom2);
        >>;
    >>;
    if car(tmppolynom2) then
    <<
        bibasis_remove(rplacd(tmppolynom1, tmppolynom2));
    >>;
    return polynom1;
end;


% writes result in polynom1
expr procedure polynomreduceby(polynom1, polynom2);
begin scalar break, tmpmonom, tmppolynom;
    while (not break) do
    <<
        tmppolynom := polynom1;
        while and(polynomgetlm(tmppolynom),
                  not monomisdivisibleby(polynomgetlm(tmppolynom), polynomgetlm(polynom2))) do
        <<
            tmppolynom := cdr(tmppolynom);
        >>;
        
        if not polynomgetlm(tmppolynom) then
        <<
            break := t;
        >>
        else
        <<
            tmpmonom := monomdivide(polynomgetlm(tmppolynom), polynomgetlm(polynom2));
            polynomadd(polynom1, polynommultiplybymonom(polynom2, tmpmonom));
        >>;
    >>;
    fluidbibasisreductionsmade := iadd1(fluidbibasisreductionsmade);
end;


% writes result in polynom1
expr procedure polynomheadreduceby(polynom1, polynom2);
begin scalar break, tmpmonom;
    while and(polynomgetlm(polynom1), not break) do
    <<
        if monomisdivisibleby(polynomgetlm(polynom1), polynomgetlm(polynom2)) then
        <<
            tmpmonom := monomdivide(polynomgetlm(polynom1), polynomgetlm(polynom2));
            polynomadd(polynom1, polynommultiplybymonom(polynom2, tmpmonom));
        >>
        else
        <<
            break := t;
        >>;
    >>;
    fluidbibasisreductionsmade := iadd1(fluidbibasisreductionsmade);
end;


expr procedure polynomcompare(polynom1, polynom2);
begin scalar tmppolyiterator1, tmppolyiterator2; integer monomcompare;
    tmppolyiterator1 := polynom1;
    tmppolyiterator2 := polynom2;
    
    while car(tmppolyiterator1) and car(tmppolyiterator2) do
    <<
        monomcompare := monomcompare(car(tmppolyiterator1), car(tmppolyiterator2));
        if monomcompare = 1 then
        <<
            tmppolyiterator2 := (nil . nil);
        >>
        else if monomcompare = -1 then
        <<
            tmppolyiterator1 := (nil . nil);
        >>
        else
        <<
            tmppolyiterator1 := cdr(tmppolyiterator1);
            tmppolyiterator2 := cdr(tmppolyiterator2);
        >>;
    >>;
    
    if car(tmppolyiterator1) then
    <<
        return 1;
    >>
    else if car(tmppolyiterator2) then
    <<
        return -1;
    >>
    else
    <<
        return 0;
    >>;
end;


expr procedure polynomread(polynom);
if null(polynom) then 
<<
    (nil . nil)
>>
else if domainp(polynom) then 
<<
    if eqn(remainder(polynom, 2), 1) then
    <<
        (createmonomunit() . (nil . nil))
    >>
    else
    <<
        (nil . nil)
    >>
>>
else if member(mvar(polynom), fluidbibasisvariables) then
<<
    polynomadd(polynommultiplybymonom(polynomread(lc(polynom)), 
                                      cdr(assoc(mvar(polynom), fluidbibasissinglevariablemonomialsa))),
               polynomread(red(polynom)))
>>
else
<<
    polynomadd(polynommultiplybymonom(polynomread(lc(polynom)), createmonomunit()), polynomread(red(polynom)));
>>;


expr procedure polynomwrite(polynom);
if null(polynomgetlm(polynom)) then
<<
    nil
>>
else if monomgetdegree(polynomgetlm(polynom)) = 0 then
<<
    1
>>
else
<<
    (monomwrite(polynomgetlm(polynom)) . polynomwrite(cdr(polynom)))
>>;


expr procedure polynomprint(polynom);
begin scalar currentmonom;
    currentmonom := polynom;
    if null(car(currentmonom)) then
    <<
        prin2 "0";
    >>
    else
    <<
        monomprint(car(currentmonom));
        currentmonom := cdr(currentmonom);
        while car(currentmonom) do
        <<
            prin2 " + ";
            monomprint(car(currentmonom));
            currentmonom := cdr(currentmonom);
        >>;
    >>;
end;


endmodule;
end;
