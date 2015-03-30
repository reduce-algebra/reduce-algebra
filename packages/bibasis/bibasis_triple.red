module bibasis_triple;

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
% triple := mkvect(3);
% 0 - ID
% 1 - polynom
% 2 - ancestor ID
% 3 - prolong set


inline procedure createprolongset(); (nil . nil);


expr procedure createtriple(polynom);
begin scalar tmptriple;
    tmptriple := mkvect(3);
    putv(tmptriple, 0, fluidbibasistripleid);
    putv(tmptriple, 1, polynom);
    putv(tmptriple, 2, fluidbibasistripleid);
    putv(tmptriple, 3, createprolongset());
    fluidbibasistripleid := iadd1(fluidbibasistripleid);
    return tmptriple;
end;


expr procedure createtriplewithancestor(polynom, ancestorid);
begin scalar tmptriple;
    tmptriple := mkvect(3);
    putv(tmptriple, 0, fluidbibasistripleid);
    putv(tmptriple, 1, polynom);
    putv(tmptriple, 2, ancestorid);
    putv(tmptriple, 3, createprolongset());
    fluidbibasistripleid := iadd1(fluidbibasistripleid);
    return tmptriple;
end;


inline procedure triplegetid(triple); getv(triple, 0);
inline procedure triplegetpolynom(triple); getv(triple, 1);
inline procedure triplegetancestorid(triple); getv(triple, 2);
inline procedure triplegetlm(triple); polynomgetlm(getv(triple, 1));
inline procedure triplegetprolongset(triple); getv(triple, 3);


expr procedure tripleisprolongedby(triple, variable);
begin scalar set;
    set := triplegetprolongset(triple);
    while and(car(set),
              car(set) > variable) do
    <<
        set := cdr(set);
    >>;
    if car(set) and car(set) = variable then
    <<
        return t;
    >>
    else
    <<
       return nil; 
    >>;
end;


expr procedure triplesetprolongedby(triple, variable);
begin scalar set;
    set := triplegetprolongset(triple);
    while and(car(set),
              car(set) > variable) do
    <<
        set := cdr(set);
    >>;
    if not(car(set) and car(set) = variable) then
    <<
        bibasis_insert(set, variable);
    >>;
end;


expr procedure triplesetprolongset(triple, prolongset);
begin scalar set;
    while prolongset do
    <<
        set := car(prolongset) . set;
        prolongset := cdr(prolongset);
    >>;
    putv(triple, 3, reverse(set));
end;


endmodule;
end;
