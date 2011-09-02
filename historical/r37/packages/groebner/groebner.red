module groebner;
 
% Author: Herbert Melenk
% in cooperation with Winfried Neun, Michael Moeller.

% module structure:       
%
%     GROEBNER  package + GROEBNR2 package
%        polynomial arithmetic:
%         VDP2DIP package included in DIPOLY package
%        factorization:
%         GROEBFAC package is also included here, but could be loaded
%         on demand.

% Modifications:
%
% 17-Sep-1994 (HM):  The ideal variables are now declared in the TORDER
% statement.  The calling conventions can be still used, but are removed
% from the documents.

fluid '(currentvdpmodule!*);

currentvdpmodule!* := 'vdp2dip;

create!-package('(groebner grinterf grinter2 buchbg groebcri
	 groesolv groebopt groebsea groebsor groebspa groebfac
         groebidq kredelw traverso),
         '(contrib groebner));

put('groebner,'version,3.0);

% Other packages needed.

load!-package 'dipoly;

if(null v or v<4.0) where v=get('dipoly,'version) 
  then rederr "wrong dipoly module";

smacro procedure tt(s1,s2);
  % lcm of leading terms of s1 and s2
       vevlcm(vdpevlmon s1,vdpevlmon s2);

imports a2vdp,f2vdp,a2vbc,vdp2a,vdp2f,
        vdpfmon,vdpappendmon,vdpappendvdp,vdplbc,
        vdpred,vdplastmon,vevnth,

        vdpzero!?,vdpredzero!?,vdpone!?,vevzero!?,
        vbcplus!?,vbcone!?,vbcnumberp!?,vevdivides!?,vevcompless!?,
        vdpequal,vdpmember,vevequal,

        vdpsum,vdpdif,vdpprod,vdpdivmon,cdpcancelvev,vdplcomb1,vdpcontent,

        vbcsum,vbcdif,vbcneg,vbcprod,vbcquot,vbcinv,vbcgcd,vbcabs,vbcone!?,

        vevsum,vevdif,vevtdeg,vevzero,

        vdpputprop,vdpgetprop,vdplsort,vdplsortin,vdpprint,
        vdpprin3t,vdpcondense,vdplcm,vdprectoint,vdpsimpcont,vdpvbcprod,
        vdpcancelmvev,vdpprin2,

        vevweightedcomp2,vdplength,vdpilcomb1,

        vdpinit,vdpinit2,vdpcleanup;

exports groebnereval,groesolveeval,groepostsolveeval,idquotienteval,
        gdimensioneval,glexconvert,greduce,preduce,groebnert,dd_groebner,
        hilbertpolynomial,gsort,gsplit,gspoly,gzerodim!?;

endmodule;
 
end;
