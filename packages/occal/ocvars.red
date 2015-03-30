module ocvars;

% Author: Rainer Schöpf 

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


fluid '(!*oc!-dynamic!-variables!*
        !*oc!-control!-variables!*
        !*oc!-adjoint!-variables!*
        !*oc!-abbreviations!*
        !*oc!-time!-variable!*
        !*oc!-boundaries!*
        !*oc!-boundary!-conditions!*
        !*oc!-left!-bcs!*
        !*oc!-right!-bcs!*
        !*oc!-dgls!*
        !*oc!-constants!*
        !*oc!-parameters!*
        !*oc!-functional!*
        !*oc!-name!*
        !*oc!-title!*
        !*oc!-is!-free!*
        !*oc!-relations!*
        !*oc!-tempvar!-prefix!*
        !*oc!-target!-lang!*
        !*oc!-mulcon!-param!*
        !*oc!-mulcon!-param!-left!*
        !*oc!-mulcon!-param!-right!*
        !*oc!-mulcon!-param!-start!*
        !*oc!-msh!-pts!*
        !*oc!-msh!-values!*
        !*oc_trace
       );

switch oc_trace;

symbolic procedure clear_oc_variables ();
  <<for each var in !*oc!-dynamic!-variables!* do remprop(var,'simpfn);
    !*oc!-dynamic!-variables!* := nil;
    for each var in !*oc!-adjoint!-variables!* do remprop(var,'simpfn);
    !*oc!-adjoint!-variables!* := nil;
    !*oc!-control!-variables!* := nil;
    !*oc!-abbreviations!* := nil;
    !*oc!-time!-variable!* := nil;
    !*oc!-boundaries!* := nil;
    !*oc!-boundary!-conditions!* := nil;
    !*oc!-dgls!* := nil;
    !*oc!-constants!* := nil;
    !*oc!-parameters!* := nil;
    !*oc!-functional!* := nil;
    !*oc!-name!* := nil;
    !*oc!-title!* := nil;
    !*oc!-is!-free!* := nil;
    !*oc!-tempvar!-prefix!* := 'ans;
    !*oc!-target!-lang!* := 'c;
%    !*oc_trace := nil
    >>;

flag ('(clear_oc_variables), 'opfn);

endmodule;

end;
