module 'corrundum; % Header for REDUCE integration package based on RUBI

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

% $Id$
%

% *NOTE*
% Over the summer of 2024 I have been working on an update to this based
% on a set of Rubi files a decade newer than the ones here at present. I am
% calling the new version "corrundum" which is of course the mineral that
% ends up as Ruby if if has extras that lead it to being deep red. Renaming
% the package here is a preliminary step towards replacing all the files
% here. As of mid November the new version can perform an interesting range
% of integrals, but there are still enough bugs that I continue to
% work on it as a separate project. But this comment should be taken as
% a statement of confidence that I am making enough progress that I expect
% to be able to merghe it into Reduce "sometime soon".
%
% The new version uses an enhanced version of the parser for Mathematica
% syntax that is here. The big new body of code is a rewrite system with
% a pattern matcher that tries quite hard to do what Mathematica does, and
% as small a set of interface functions as I can get away with that map
% between the algebraic operations (eg partial fraction decomposition) that
% Rubi needs and that it asks for in Mathematica-ese and versions that do
% more or less the eqauivalent in Reduce.
%
% Since the code here has been sitting in place for a decade while I hoped
% that somebody would get keen and adopt it and get it working - and nobody
% seem to have - and the files as present here do not really provide an
% end to end solution I rather hope that messing with this will not cause
% pain to anybody. Provided only that I ensure that the system still builds.
%                                              Arthur Norman. November 2024



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


create!-package('(corrundum
                  rubi_parse
                  rubi_rules),
                nil);

#if (memq 'psl lispsystem!*)
  flag('(rubi_rules),'lap);
#endif


defautoload(read_rubi_rules, rubi_parse, expr, 0);

endmodule;

end;
