%
% Read and save the Rubi rules.
%
%                                                   A C Norman, 2013

module 'rubi_rules;

% Author: Arthur Norman

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
%

% $Id: $

% I now have something that is basically a horrible trick that results
% in the parsing of rule-files being performed while this source file
% is compiled. When Reduce parses anything it will expand macros. In this
% case that act will cause it to invoke read_rubi_rules(). The end
% effect will be that the invocation of save_rubi_rules will expand
% to  "rubi_rules := '(some big list);".
% At present the big list is merely a raw parse of the original information
% but in a while I will arrange that it is a "compiled" version of the
% rule-set in the form of some variety of decision tree. Maybe.

% Note that all the code used by the macro must be loaded for this to
% behave properly. That is achieved here by having rubi_red.red set
% an autoload action on read_rubi_rules such that the module rubi_parse
% gets loaded as needbe.

fluid '(rubi_rules);

symbolic macro procedure save_rubi_rules u;
    list('setq, 'rubi_rules, mkquote read_rubi_rules());

save_rubi_rules();

endmodule;

end;

