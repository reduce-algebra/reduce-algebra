module TayPart;

%*****************************************************************
%
%      The interface to the PART operator
%
%*****************************************************************

%exports Taylor!*part,Taylor!*setpart;
exports Taylor!*part;

imports

% from the REDUCE kernel:
        !*a2k, aeval, eqcar, parterr, rederr, revalsetp1, simp!*,
        typerr,

% from the header module:
        make!-Taylor!*, TayCoefflist, TayFlags, TaylorTemplate,
        TayOrig,

% from module TayConv:
        prepTaylor!*;


%fluid '(!*taylorprintorder TaylorPrintTerms);


symbolic procedure Taylor!*part(tay,n);
   begin scalar prep;
%     prep := (Taylor!*print1 tay) where !*taylorprintorder='t,
%                                        TaylorPrintTerms='all;
     prep := prepTaylor!* tay;
     if atom prep then parterr(prep,n);
     if n=0 then return car prep;
     prep := cdr prep;
     if n<0 then <<n := -n; prep := reverse prep>>;
     if length prep < n then parterr(tay,n);
     return nth(prep,n)
   end;

put('Taylor!*,'partop,'Taylor!*part);


%symbolic procedure Taylor!*setpart(tay,nl,repl);
%   if car nl=2
%     then make!-Taylor!*(
%            TayCoefflist tay,
%            list!-to!-template(
%              revalsetp1(TaylorTemplate tay,cdr nl,repl),
%              length TayTemplate tay),
%            TayOrig tay,
%            TayFlags tay)
%    else if car nl=3 and TayOrig tay
%     then make!-Taylor!*(
%            TayCoefflist tay,
%            TayTemplate tay,
%            simp!* revalsetp1(reval!* mk!*sq TayOrig tay,cdr nl,repl),
%            TayFlags tay)
%    else rederr {"Cannot replace part",car nl,"in Taylor kernel"};
%
%
%put('Taylor!*,'setpartop,'Taylor!*setpart);
%
%
%symbolic procedure list!-to!-template (ttp,l);
%   if not eqcar(ttp,'list) or length cdr ttp neq l
%     then typerr(ttp,"Taylor template")
%    else for each ttpel in cdr ttp collect list!-to!-tpel ttpel;
%
%symbolic procedure list!-to!-tpel ttpel;
%   if not eqcar(ttpel,'list) or length ttpel<4
%     then typerr(ttpel,"Taylor Template element")
%    else {if eqcar(cadr ttpel,'list)
%            then for each var in cdr cadr ttpel collect !*a2k var
%           else {!*a2k cadr ttpel},
%          caddr ttpel,
%          ((if fixp x then x else typerr(x,"number"))
%            where x := aeval cadddr ttpel)};

endmodule;

end;
