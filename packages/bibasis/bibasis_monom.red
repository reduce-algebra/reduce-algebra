module bibasis_monom;

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


inline procedure bibasis_insert(y, x); rplaca(rplacd(y, car(y) . cdr(y)), x);
inline procedure bibasis_remove(y); rplacd(rplaca(y, cadr(y)), cddr(y));

expr procedure pushback(list, value);
begin scalar listiterator;
    listiterator := list;
    while car(listiterator) do
    <<
        listiterator := cdr(listiterator);
    >>;
    bibasis_insert(listiterator, value);
end;


%----------------------------------------------------------------------------
% monom x_1^k_1*...x_n^k_n = mkvect(1) 
% 0 - k_1+...+k_n
% 1 - k_1 . ... . k_n . (nil . nil)


expr procedure initmonomials();
begin
    fluidbibasisnumberofvariables := length(fluidbibasisvariables);
    fluidbibasissinglevariablemonomialss := mkvect(fluidbibasisnumberofvariables);
    for i:=1:fluidbibasisnumberofvariables do
    <<
        putv(fluidbibasissinglevariablemonomialss, i, createsinglevariablemonom(i));
    >>;
    fluidbibasistripleid := 0; %move somewhere else
end;


inline procedure getvariable(variable); getv(fluidbibasissinglevariablemonomialss, variable);
inline procedure monomgetdegree(monom); getv(monom, 0);
inline procedure monomsetdegree(monom, degree); putv(monom, 0, degree);
inline procedure monomgetexponent(monom); getv(monom, 1);
inline procedure monomsetexponent(monom, exponent); putv(monom, 1, exponent);


expr procedure monomgetvariabledegree(monom, variable); 
begin scalar exponent;
    exponent := monomgetexponent(monom);
    while and(car(exponent),
              car(exponent) > variable) do
    <<
        exponent := cdr(exponent);
    >>;
    if car(exponent) and car(exponent) = variable then
    <<
        return 1;
    >>
    else
    <<
       return 0; 
    >>;
end;


expr procedure createmonomunit();
begin scalar tmpmonom;
    tmpmonom := mkvect(1);
    monomsetdegree(tmpmonom, 0);
    monomsetexponent(tmpmonom, (nil . nil));
    return tmpmonom;
end;


expr procedure createsinglevariablemonom(variable);
begin scalar tmpmonom;
    tmpmonom := mkvect(1);
    monomsetdegree(tmpmonom, 1);
    monomsetexponent(tmpmonom, (variable . nil . nil));
    return tmpmonom;;
end;


expr procedure monomclone(monom);
if null(monom) then
    nil
else begin scalar tmpmonom, exponent, tmpexponent;
    tmpmonom := mkvect(1);
    monomsetdegree(tmpmonom, monomgetdegree(monom));
    exponent := monomgetexponent(monom);
    while exponent do
    <<
        tmpexponent := car(exponent) . tmpexponent;
        exponent := cdr(exponent);
    >>;
    monomsetexponent(tmpmonom, reverse(tmpexponent));
    return tmpmonom;
end;


expr procedure monommultiplybyvariable(monom, variable);
begin scalar exponent;
    exponent := monomgetexponent(monom);
    while and(car(exponent),
              car(exponent) > variable) do
    <<
        exponent := cdr(exponent);
    >>;
    if not(car(exponent) and car(exponent) = variable) then
    <<
        bibasis_insert(exponent, variable);
        monomsetdegree(monom, monomgetdegree(monom) + 1);
    >>;
end;


expr procedure monomcomparelex(monom1, monom2);
begin scalar exponent1, exponent2; integer i;
    exponent1 := cdr(reverse(nil . monomgetexponent(monom1)));
    exponent2 := cdr(reverse(nil . monomgetexponent(monom2)));
    i := 0;   
    while car(exponent1) and car(exponent2) do
    <<
        if car(exponent1) < car(exponent2) then
        <<
            i := 1;
            exponent1 := (nil . nil);
        >>
        else if car(exponent1) > car(exponent2) then
        <<
            i := -1;
            exponent1 := (nil . nil);
        >>
        else
        <<
            exponent1 := cdr(exponent1);
            exponent2 := cdr(exponent2)
        >>;
    >>;
    
    if i = 0 and car(exponent1) then
    <<
        i := 1;
    >>
    else if i = 0 and car(exponent2) then
    <<
        i := -1;
    >>;
    
    return i;
end;


expr procedure monomcomparedeglex(monom1, monom2);
begin scalar exponent1, exponent2; integer i;
    i := 0;
    if igreaterp(monomgetdegree(monom1), monomgetdegree(monom2)) then
    <<
        i := 1
    >>
    else if ilessp(monomgetdegree(monom1), monomgetdegree(monom2)) then
    <<
        i := -1
    >>
    else 
    <<
        exponent1 := cdr(reverse(nil . monomgetexponent(monom1)));
        exponent2 := cdr(reverse(nil . monomgetexponent(monom2)));
        while car(exponent1) and car(exponent2) do
        <<
            if car(exponent1) < car(exponent2) then
            <<
                i := 1;
                exponent1 := (nil . nil);
            >>
            else if car(exponent1) > car(exponent2) then
            <<
                i := -1;
                exponent1 := (nil . nil);
            >>
            else
            <<
                exponent1 := cdr(exponent1);
                exponent2 := cdr(exponent2)
            >>;
        >>;
    >>;
    return i;
end;


expr procedure monomcomparedegrevlex(monom1, monom2);
begin scalar exponent1, exponent2; integer i;
    if monomgetdegree(monom1) > monomgetdegree(monom2) then
    <<
        i := 1;
    >>
    else if monomgetdegree(monom1) < monomgetdegree(monom2) then
    <<
        i := -1;
    >>
    else 
    <<
        exponent1 := monomgetexponent(monom1);
        exponent2 := monomgetexponent(monom2);
        while car(exponent1) do
        <<
            if car(exponent1) < car(exponent2) then
            <<
                i := 1;
                exponent1 := (nil . nil);
            >>
            else if car(exponent1) > car(exponent2) then
            <<
                i := -1;
                exponent1 := (nil . nil);
            >>
            else
            <<
                exponent1 := cdr(exponent1);
                exponent2 := cdr(exponent2);
            >>;
        >>;
        if null(car(exponent2)) then
        <<
            i := 0;
        >>;
    >>;
    return i;
end;


expr procedure monomcompare(monom1, monom2);
begin
    if (eq(fluidbibasismonomialorder, 'lex)) then
    <<
        return monomcomparelex(monom1, monom2);
    >>
    else if (eq(fluidbibasismonomialorder, 'deglex)) then
    <<
        return monomcomparedeglex(monom1, monom2);
    >>
    else
    <<
        return monomcomparedegrevlex(monom1, monom2);
    >>    
end;


expr procedure monomisdivisibleby(monom1, monom2);
begin scalar exponent1, exponent2;
    exponent1 := monomgetexponent(monom1);
    exponent2 := monomgetexponent(monom2);
    while and(car(exponent1),
              car(exponent2)) do
    <<
        if car(exponent1) = car(exponent2) then
        <<
            exponent1 := cdr(exponent1);
            exponent2 := cdr(exponent2);
        >>
        else if car(exponent1) > car(exponent2) then
        <<
            exponent1 := cdr(exponent1);
        >>
        else
        <<
            exponent1 := (nil . nil);
        >>;
    >>;
    return null(car(exponent2));
end;


expr procedure monomispommaretdivisibleby(monom1, monom2);
begin scalar exponent1, exponent2, break;
    exponent1 := monomgetexponent(monom1);
    exponent2 := monomgetexponent(monom2);
    while and(car(exponent1),
              car(exponent1) > car(exponent2)) do
    <<
        exponent1 := cdr(exponent1);
    >>;
    
    while and(not(break),
              car(exponent1),
              car(exponent2)) do
    <<
        if neq(car(exponent1), car(exponent2)) then
        <<
            break := t;
        >>
        else
        <<
            exponent1 := cdr(exponent1);
            exponent2 := cdr(exponent2);
        >>;
    >>;
    return null(car(exponent1)) and null(car(exponent2));
end;


expr procedure monomdivide(monom1, monom2);
begin scalar tmpmonom, exponent1, exponent2, tmpexponent;
    tmpmonom := mkvect(1);
    monomsetdegree(tmpmonom, monomgetdegree(monom1) - monomgetdegree(monom2));
    exponent1 := monomgetexponent(monom1);
    exponent2 := monomgetexponent(monom2);
    while car(exponent1) do
    <<
        if car(exponent1) = car(exponent2) then
        <<
            exponent1 := cdr(exponent1);
            exponent2 := cdr(exponent2);
        >>
        else
        <<
            tmpexponent := car(exponent1) . tmpexponent;
            exponent1 := cdr(exponent1);
        >>;
    >>;
    tmpexponent := nil . tmpexponent;
    monomsetexponent(tmpmonom, reverse(tmpexponent));
    return tmpmonom;
end;


expr procedure monomgetfirstmultivar(monom);
begin
    return if car(getv(monom, 1)) then car(getv(monom, 1)) else 1;
end;


expr procedure monomwrite(monom);
begin scalar result, variables, exponent; integer previousvariable;
    previousvariable := fluidbibasisnumberofvariables;
    variables := fluidbibasisreversedvariables;
    exponent := monomgetexponent(monom);
    while car(exponent) do
    <<
        for i:=1:(previousvariable - car(exponent)) do
        <<
            variables := cdr(variables);
        >>;
        previousvariable := car(exponent);

        if result then
        <<
            result := (car(variables) . 1) . result . nil
        >>
        else
        <<
            result := (car(variables) . 1) . 1;
        >>;
        exponent := cdr(exponent);
    >>;
    return result;
end;


expr procedure monomprint(monom);
begin scalar variables, exponent; integer previousvariable;
    if monomgetdegree(monom) = 0 then
    <<
        prin2 "1";
    >>
    else
    <<
        previousvariable := 1;
        variables := fluidbibasisvariables;
        exponent := cdr(reverse(nil . monomgetexponent(monom)));
        for i:=1:(car(exponent) - previousvariable) do
        <<
            variables := cdr(variables);
        >>;
        previousvariable := car(exponent);
        prin2 car(variables);
        exponent := cdr(exponent);

        while car(exponent) do
        <<
            for i:=1:(car(exponent) - previousvariable) do
            <<
                variables := cdr(variables);
            >>;
            previousvariable := car(exponent);
            prin2 "*"; prin2 car(variables);
            exponent := cdr(exponent);
        >>;
    >>;
end;



endmodule;
end;
