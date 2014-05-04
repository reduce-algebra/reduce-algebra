module rubi!-red; % Header for REDUCE integration package based on RUBI

% Authors: Albert D Rich and some conversion work by A. C. Norman and
%          Shreedipta Mitra.                                2012-2013

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

%
% *NOTE*
% At present the code here does NOT use the Rubi rewrites to perform any
% integration. The most I will do in the initial set of files here is to
% provide a script that can run the Rubi test files using the existing
% Reduce integration code. Because this task takes several hours to
% complete I will not set it up to be a standard "Reduce test script".
% Rather the user should run the script rubi_red.tst from this directory
% by hand.
%
% So "Work in progress"!   ACN. May 2013.

create!-package('(rubi_red
                  rubi_parse
                  rubi_rules),
                nil);

#if (memq 'psl lispsystem!*)
  flag('(rubi_rules),'lap);
#endif


defautoload(read_rubi_rules, rubi_parse, expr, 0);

endmodule;

end;
