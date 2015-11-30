module bibasis_tset;

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
% T = triple_1 . ... . triple_n . (nil . nil) and triple_i >= triple_(i+1)


expr procedure settreset();
begin
    janettreereset();
    fluidbibasissett := (nil . nil);
end;


expr procedure settinsert(triple);
begin
    janettreeinsert(triple);
    fluidbibasissett := (triple . fluidbibasissett);
end;


expr procedure settcollectnonmultiprolongations(triplelist);
if car(fluidbibasissett) then
begin scalar lasttriple, tmppolynom, tmptriple; integer lastnonmultivar;
    lasttriple := car(fluidbibasissett);
    lastnonmultivar := isub1(monomgetfirstmultivar(triplegetlm(lasttriple)));
    for i:=1:lastnonmultivar do
    <<
        if not(tripleisprolongedby(lasttriple, i)) then
        <<
            tmppolynom := polynommultiplybymonom(triplegetpolynom(lasttriple), getvariable(i));
            triplesetprolongedby(lasttriple, i);
            if polynomgetlm(tmppolynom) then
            <<
                tmptriple := createtriplewithancestor(tmppolynom, triplegetancestorid(lasttriple));
                triplesetprolongset(tmptriple, triplegetprolongset(lasttriple));
                sortedtriplelistinsert(triplelist, tmptriple);
            >>;
        >>;
    >>;
end;


expr procedure settprint();
begin scalar currenttriple;
    prin2 "SetT( ";
    currenttriple := fluidbibasissett;
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
