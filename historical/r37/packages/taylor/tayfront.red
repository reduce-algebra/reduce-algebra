module TayFront;

%*****************************************************************
%
%          User interface
%
%*****************************************************************


exports taylorcombine, taylororiginal, taylorprintorder,
        taylorseriesp, taylortemplate, taylortostandard;

imports

% from the REDUCE kernel:
        eqcar, mk!*sq, mvar, numr, prepsq, simp!*, typerr,

% from the header module:
        Taylor!-kernel!-sq!-p, TayOrig, TayTemplate, TayTpElOrder,
        TayTpElPoint, TayTpElVars,

% from module Tayintro:
        Taylor!-error,

% from module Taysimp:
        taysimpsq;


symbolic procedure taylorseriesp u;
  (Taylor!-kernel!-sq!-p sq)
      where sq := simp!* u;

symbolic procedure taylorcombine u;
  mk!*sq taysimpsq simp!* u;

symbolic procedure taylortostandard u;
  (prepsq if not eqcar (u, '!*sq) then simp!* u else cadr u)
          where convert!-Taylor!* := t;

symbolic procedure taylororiginal u;
  (if not Taylor!-kernel!-sq!-p sq
     then typerr (u, "Taylor kernel")
    else (if TayOrig tay then mk!*sq TayOrig tay
        else Taylor!-error ('no!-original, 'taylororiginal))
           where tay := mvar numr sq)
     where sq := simp!* u;

symbolic procedure taylortemplate u;
  (if not Taylor!-kernel!-sq!-p sq
     then typerr (u, "Taylor kernel")
    else 'list . for each quartet in TayTemplate mvar numr sq collect
              {'list,
               if null cdr TayTpElVars quartet
                 then car TayTpElVars quartet
                else 'list . TayTpElVars quartet,
               TayTpElPoint quartet,
               TayTpElOrder quartet})
     where sq := simp!* u;

flag ('(taylorseriesp taylorcombine taylortostandard taylororiginal
        taylortemplate),
      'opfn);

flag ('(taylorseriesp), 'boolean);

endmodule;

end;
