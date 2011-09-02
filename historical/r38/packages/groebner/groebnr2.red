module groebnr2;% Part 2 of the Groebner package.
 
create!-package('(groebnr2 groebman glexconv groebmes groebrst groebtra%groebres
 groeweak hilberts hilbertp hggroeb kuechl greduo), '(contrib groebner));

load!-package 'groebner;

imports a2vdp,f2vdp,a2vbc,vdp2a,vdp2f,vbc2a,
        vdpfmon,vdpappendvdp,vdplbc,
        vdpred,vdplastmon,vevnth,

        vdpzero!?,vdpredzero!?,vdpone!?,vevzero!?,
        vbcplus!?,vbcone!?,vbcnumberp!?,vevdivides!?,vevcompless!?,
        vdpequal,vdpmember,vevequal,

        vdpsum,vdpprod,vdpdivmon,cdpcancelvev,vdplcomb1,vdpcontent,
        vdpsimpcont,vdplcm,vdpresimp,

        vbcsum,vbcdif,vbcneg,vbcprod,vbcquot,vbcinv,vbcgcd,

        vevsum,vevsum0,vevdif,vevtdeg,vevzero,

        vdpilcomb1,vdpprin2,

        vdpputprop,vdpgetprop,vdplsort,vdplsortin,vdpprint,
        vdpprin3t,vdprectoint,

        groebmess24,groebmess4,groebmess2,groebmess51,groebmess8,
        groebmessff,groebmess5,groebmess34,groebmess29,groebmess32,
        groebmess30,groebmess31,groebmess36,groebmess37,groebmess35,
        groebmess33,

        vevweightedcomp2,vdpvbcprod,vdpcanelmvev,

        gsetsugar,

        rnonep!:,rntimes!:,!*i2rn,rnminusp!:,rndifference!:,rnzerop!:,
        rnplus!:,rnquotient!:,rnequiv,rnprep!:,mkrn,

        vdpcoeffcientsfromdomain!?,

        simp,addsq,multsq,

        rerror,vdpcleanup,torder2;

exports gdimensioneval,glexconvert,greduce,preduce,groebnert,dd_groebner,
 hilbertpolynomial,gsort,gsplit,gspoly,gzerodim!?,groeb!-w1;

endmodule;;end;
