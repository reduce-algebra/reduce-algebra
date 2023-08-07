module ellipfn;  % Elliptic functions package for REDUCE.

% Author:  Alan Barnes December 2021
%          contribution from various authors ...

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

% $Id: specfn.red 6116 2021-10-26 09:00:52Z barnesa1 $

%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     Please report bugs to Alan Barnes                          %
%     by email to Alan.Barnes45678@gmail.com                     %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     This package provides algebraic and numeric                %
%     manipulations upon various elliptic functions:             %
%                                                                %
%              -- Jacobi Elliptic Functions                      %
%              -- Elliptic Integrals                             %
%              -- Jacobi Theta Functions                         %
%              -- Weierstrassian Elliptic Functions              %
%              -- Sigma Functions                                %
%              -- Inverse Jacobi Elliptic Functions              %
%              -- Various utility functions (not autoloading)    %
%                                                                %
%     accessible through the new operators:                      %
%     jacobi{am,sn,cn,dn,sc...}, elliptic{D,E,F,K...}, jacobiE     %
%     elliptictheta{1,2,3,4}                                     %
%     weierstrass, weierstrassZeta, Weierstrass1,                %
%     weierstrassZeta1, weierstrass_sigma, weierstrass_sigma1,   %
%     weierstrass_sigma2, weierstrass_sigma3                     %
%     arc{sn,cn,dn,sc,sd...}                                     %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %

% Remove autoloading simpfn's
remprop('jacobiam,'simpfn);
remprop('jacobisn,'simpfn);
remprop('jacobicn,'simpfn);
remprop('jacobidn,'simpfn);
remprop('jacobins,'simpfn);
remprop('jacobinc,'simpfn);
remprop('jacobind,'simpfn);
remprop('jacobisc,'simpfn);
remprop('jacobics,'simpfn);
remprop('jacobisd,'simpfn);
remprop('jacobids,'simpfn);
remprop('jacobicd,'simpfn);
remprop('jacobidc,'simpfn);
remprop('jacobie,'simpfn);
% 
remprop('elliptick,'simpfn);
remprop('elliptick!','simpfn);
remprop('elliptice,'simpfn);
remprop('ellipticd,'simpfn);
remprop('elliptice!','simpfn);
remprop('ellipticf,'simpfn);
remprop('ellipticpi,'simpfn);

remprop('elliptictheta1,'simpfn);
remprop('elliptictheta2,'simpfn);
remprop('elliptictheta3,'simpfn);
remprop('elliptictheta4,'simpfn);

remprop('arcsn,'simpfn);
remprop('arccn,'simpfn);
remprop('arcdn,'simpfn);
remprop('arcns,'simpfn);
remprop('arcnc,'simpfn);
remprop('arcnd,'simpfn);
remprop('arcsc,'simpfn);
remprop('arccs,'simpfn);
remprop('arcsd,'simpfn);
remprop('arcds,'simpfn);
remprop('arccd,'simpfn);
remprop('arcdc,'simpfn);

remprop('weierstrass,'simpfn);
remprop('weierstrass1,'simpfn);
remprop('weierstrasszeta,'simpfn);
remprop('weierstrasszeta1,'simpfn);
remprop('weierstrass_sigma,'simpfn);
remprop('weierstrass_sigma1,'simpfn);
remprop('weierstrass_sigma2,'simpfn);
remprop('weierstrass_sigma3,'simpfn);

create!-package ('(ellipfn efjacobi efellint efjacinv eftheta
                   efweier efnumeric efreim), '(contrib ellipfn));

%switch savesfs=on;

     
endmodule;

end;




