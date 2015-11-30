module bibasis_interface;

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


inline procedure mk_sq(a); list('!*sq, a, t);


expr procedure bibasis(initialset, variableslist, monomialorder, togroebner);
begin scalar result, polynomlist;
    if and(initialset, car(initialset) neq 'list) then 
    << 
        mathprint(initialset);
        rederr "is not a polynomial list";
    >>;
    if null(cdr(initialset)) then 
    <<
        mathprint(initialset);
        rederr "polynomial list is empty";
    >>;
    if and(variableslist, car(variableslist) neq 'list) then 
    << 
        mathprint(variableslist);
        rederr "is not a variable list";
    >>;
    if null(cdr(variableslist)) then 
    <<
        mathprint(variableslist);
        rederr "variable list is empty";
    >>;
    if and(monomialorder neq 'lex,
           monomialorder neq 'deglex,
           monomialorder neq 'degrevlex) then
    <<
        mathprint(monomialorder);
        rederr " is unsupported monomial ordering";
    >>;
  
    fluidbibasisvariables := cdr(variableslist);
    fluidbibasismonomialorder := monomialorder;
    init();
    
    polynomlist := (nil . nil);
    if initialset then
    <<
        for each polynom in cdr(initialset) do
        <<
            sortedpolynomlistinsert(polynomlist, polynomread(numr(simp(reval(polynom)))));
        >>;
    >>;
    
    fluidbibasisrunningtime := time();
    fluidbibasisgctime := gctime();

    polynomlist := constructinvolutivebasis(polynomlist, togroebner);

    fluidbibasisgctime := gctime() - fluidbibasisgctime;
    fluidbibasisrunningtime := time() - fluidbibasisrunningtime - fluidbibasisgctime;
    
    while car(polynomlist) do
    <<
        result := mk_sq(!*f2q polynomwrite(car(polynomlist))) . result;
        polynomlist := cdr(polynomlist);
    >>;
  
    return 'list . reverse(result);
end;


expr procedure bibasis_print_statistics();
if car(fluidbibasissetq) = nil then
begin
    terpri();
    write "        Variables order = ", car(fluidbibasisvariables);
    for each x in cdr(fluidbibasisvariables) do 
    <<
        write " > ", x;
    >>;
    terpri();
    
    write "Normal forms calculated = ", fluidbibasisnormalforms; terpri();
    write "  Non-zero normal forms = ", fluidbibasisnonzeronormalforms; terpri();
    write "        Reductions made = ", fluidbibasisreductionsmade; terpri();
    write "Time: ", fluidbibasisrunningtime, " ms"; terpri();
    write "GC time: ", fluidbibasisgctime, " ms"; terpri();
end;


lisp operator bibasis, bibasis_print_statistics;

endmodule;
end;
