module matr;

% Author: Anthony C. Hearn;

% This module is rife with essential references to RPLAC-based
% functions.

fluid '(!*sub2);

global '(nxtsym!* subfg!*);

symbolic procedure matrix u;
   %declares list U as matrices;
   begin scalar v,w,x;
        for each j in u do
           if atom j then if null (x := gettype j)
                            then put(j,'rtype,'matrix)
                           else if x eq 'matrix             
                            then <<lprim list(x,j,"redefined");
                                   put(j,'rtype,'matrix)>>
                           else typerr(list(x,j),"matrix")
            else if not idp car j
                   or length (v := revlis cdr j) neq 2
                   or not natnumlis v
             then errpri2(j,'hold)
            else if not (x := gettype car j) or x eq 'matrix
             then <<w := nil;
                    for n := 1:car v do w := nzero cadr v . w;
                    put(car j,'rtype,'matrix);
                    put(car j,'rvalue,'mat . w)>>
            else typerr(list(x,car j),"matrix")
   end;

symbolic procedure natnumlis u;
   % True if U is a list of natural numbers.
   null u
      or numberp car u and fixp car u and car u>0 and natnumlis cdr u;

rlistat '(matrix);

symbolic procedure nzero n;
   % Returns a list of N zeros.
   if n=0 then nil else 0 . nzero(n-1);

% Parsing interface.

symbolic procedure matstat;
   % Read a matrix.
   begin scalar x,y;
   a: scan();
      scan();
      y := xread 'paren;
      if not eqcar(y,'!*comma!*) then y := list y else y := remcomma y;
      x := y . x;
      if nxtsym!* eq '!)
        then return <<scan(); scan(); 'mat . reversip x>>
       else if not(nxtsym!* eq '!,) then symerr("Syntax error",nil);
      go to a
   end;

put('mat,'stat,'matstat);

symbolic procedure formmat(u,vars,mode);
   'list . mkquote 'mat
     . for each x in cdr u collect('list . formlis(x,vars,mode));

put('mat,'formfn,'formmat);

put('mat,'i2d,'mkscalmat);

put('mat,'inversefn,'matinverse);

put('mat,'lnrsolvefn,'lnrsolve);

put('mat,'rtypefn,'(lambda (x) 'matrix));

flag('(mat tp),'matflg);

flag('(mat),'noncommuting);

put('mat,'prifn,'matpri);

flag('(mat),'struct);      % for parsing

put('matrix,'fn,'matflg);

put('matrix,'evfn,'matsm!*);

flag('(matrix),'sprifn);

put('matrix,'tag,'mat);

put('matrix,'lengthfn,'matlength);

put('matrix,'getelemfn,'getmatelem);

put('matrix,'setelemfn,'setmatelem);

symbolic procedure mkscalmat u;
   % Converts id u to 1 by 1 matrix.
   list('mat,list u);

symbolic procedure getmatelem u;
   begin scalar x;
      x := get(car u,'rvalue);
      if not eqcar(x,'mat) then rederr list("Matrix",car u,"not set")
       else if not numlis (u := revlis cdr u) or length u neq 2
        then errpri2(x . u,t);
      return nth(nth(cdr x,car u),cadr u)
   end;

symbolic procedure setmatelem(u,v); letmtr(u,v,get(car u,'rvalue));

symbolic procedure matlength u;
   if not eqcar(u,'mat) then rederr list("Matrix",u,"not set")
    else list('list,length cdr u,length cadr u);

symbolic procedure matsm!*(u,v);
   % Matrix expression simplification function.
   begin
        u := 'mat . for each j in matsm u collect
                        for each k in j collect mk!*sq2 k;
        !*sub2 := nil;   %since all substitutions done;
        return u
   end;

symbolic procedure mk!*sq2 u;
   begin scalar x;
        x := !*sub2;   %since we need value for each element;
        u := subs2 u;
        !*sub2 := x;
        return mk!*sq u
   end;

symbolic procedure matsm u;
   begin scalar x,y;
      for each j in nssimp(u,'matrix) do 
         <<y := multsm(car j,matsm1 cdr j);
           x := if null x then y else addm(x,y)>>;
      return x
   end;

symbolic procedure matsm1 u;
   %returns matrix canonical form for matrix symbol product U;
   begin scalar x,y,z; integer n;
    a:  if null u then return z
         else if eqcar(car u,'!*div) then go to d
         else if atom car u then go to er
         else if caar u eq 'mat then go to c1
         else x := apply(caar u,cdar u);
    b:  z := if null z then x
              else if null cdr z and null cdar z then multsm(caar z,x)
              else multm(x,z);
    c:  u := cdr u;
        go to a;
    c1: if not lchk cdar u then rederr "Matrix mismatch";
        x := for each j in cdar u collect
                for each k in j collect xsimp k;
        go to b;
    d:  y := matsm cadar u;
        if (n := length car y) neq length y
          then rederr "Non square matrix"
         else if (z and n neq length z) then rederr "Matrix mismatch"
         else if cddar u then go to h
         else if null cdr y and null cdar y then go to e;
        x := subfg!*;
        subfg!* := nil;
        if null z then z := apply1(get('mat,'inversefn),y)
         else if null(x := get('mat,'lnrsolvefn))
          then z := multm(apply1(get('mat,'inversefn),y),z)
         else z := apply2(get('mat,'lnrsolvefn),y,z);
        subfg!* := x;
        % Make sure there are no power substitutions.
        z := for each j in z collect for each k in j collect
                 <<!*sub2 := t; subs2 k>>;
        go to c;
    e:  if null caaar y then rederr "Zero denominator";
        y := revpr caar y;
        z := if null z then list list y else multsm(y,z);
        go to c;
     h: if null z then z := generateident n;
        go  to c;
    er: rederr list("Matrix",car u,"not set")
   end;

symbolic procedure lchk u;
   begin integer n;
        if null u or atom car u then return nil;
        n := length car u;
        repeat u := cdr u
           until null u or atom car u or length car u neq n;
        return null u
   end;

symbolic procedure addm(u,v);
   %returns sum of two matrix canonical forms U and V;
   for each j in addm1(u,v,function cons)
      collect addm1(car j,cdr j,function addsq);

symbolic procedure addm1(u,v,w);
   if null u and null v then nil
    else if null u or null v then rederr "Matrix mismatch"
    else apply(w,list(car u,car v)) . addm1(cdr u,cdr v,w);

symbolic procedure tp u; tp1 matsm u;

put('tp,'rtypefn,'getrtypecar);

symbolic procedure tp1 u;
   %returns transpose of the matrix canonical form U;
   %U is destroyed in the process;
   begin scalar v,w,x,y,z;
        v := w := list nil;
        while car u do
         <<x := u;
           y := z := list nil;
           while x do
             <<z := cdr rplacd(z,list caar x);
               x := cdr rplaca(x,cdar x)>>;
           w := cdr rplacd(w,list cdr y)>>;
        return cdr v
   end;

symbolic procedure scalprod(u,v);
   %returns scalar product of two lists (vectors) U and V;
   if null u and null v then nil ./ 1
    else if null u or null v then rederr "Matrix mismatch"
    else addsq(multsq(car u,car v),scalprod(cdr u,cdr v));

symbolic procedure multm(u,v);
   %returns matrix product of two matrix canonical forms U and V;
    (lambda x;
        for each y in u collect for each k in x collect scalprod(y,k))
     tp1 v;

symbolic procedure multsm(u,v);
   %returns product of standard quotient U and matrix standard form V;
   if u = (1 ./ 1) then v
    else for each j in v collect for each k in j collect multsq(u,k);

symbolic procedure letmtr(u,v,y);
   %substitution for matrix elements;
   begin scalar z;
        if not eqcar(y,'mat) then rederr list("Matrix",car u,"not set")
         else if not numlis (z := revlis cdr u) or length z neq 2
          then return errpri2(u,'hold);
        rplaca(pnth(nth(cdr y,car z),cadr z),v);
   end;

endmodule;


module matpri;   % Matrix printing routines.

% Author: Anthony C. Hearn;

global '(!*nat);

symbolic procedure setmatpri(u,v);
   matpri1(cdr v,u);

put('mat,'setprifn,'setmatpri);

symbolic procedure matpri u;
   matpri1(cdr u,"MAT");

symbolic procedure matpri1(u,x);
   %prints a matrix canonical form U with name X;
   begin scalar m,n;
        m := 1;
        for each y in u do
         <<n := 1;
           for each z in y do
              <<varpri(z,list('setq,list(x,m,n),z),'only); n := n+1>>;
        m := m+1>>
   end;

endmodule;


module bareiss; % Inversion routines using the Bareiss 2-step method.

% Author: Anthony C. Hearn;

% This module is rife with essential references to RPLAC-based
% functions.

fluid '(!*exp asymplis!*);

global '(wtl!*);

symbolic procedure matinverse u;
   lnrsolve(u,generateident length u);

symbolic procedure lnrsolve(u,v);
   %U is a matrix standard form, V a compatible matrix form.
   %Value is U**(-1)*V.
   begin integer n; scalar !*exp,temp;
        !*exp := t; n := length u;
        if asymplis!* or wtl!*
          then <<temp := asymplis!* . wtl!*;
                 asymplis!* := wtl!* := nil>>;
        v := backsub(bareiss car normmat augment(u,v),n);
        if temp then <<asymplis!* := car temp; wtl!* := cdr temp>>;
        u := rhside(car v,n);
        v := cdr v;
        return if temp
                 then for each j in u collect
                          for each k in j collect resimp(k ./ v)
                else for each j in u collect
                          for each k in j collect cancel(k ./ v)
   end;

symbolic procedure augment(u,v);
   if null u then nil else append(car u,car v) . augment(cdr u,cdr v);

symbolic procedure generateident n;
  %returns matrix canonical form of identity matrix of order N.
   begin scalar u,v;
        for i := 1:n do
         <<u := nil;
           for j := 1:n do u := ((if i=j then 1 else nil) . 1) . u;
           v := u . v>>;
        return v
   end;

symbolic procedure rhside(u,m);
   if null u then nil else pnth(car u,m+1) . rhside(cdr u,m);

symbolic procedure bareiss u;
  %The 2-step integer preserving elimination method of Bareiss
  %based on the implementation of Lipson.
  %If the value of procedure is NIL then U is singular, otherwise the
  %value is the triangularized form of U (in matrix polynomial form).
  begin scalar aa,c0,ci1,ci2,ik1,ij,kk1,kj,k1j,k1k1,ui,u1,x;
        integer k,k1;
        %U1 points to K-1th row of U
        %UI points to Ith row of U
        %IJ points to U(I,J)
        %K1J points to U(K-1,J)
        %KJ points to U(K,J)
        %IK1 points to U(I,K-1)
        %KK1 points to U(K,K-1)
        %K1K1 points to U(K-1,K-1)
        %M in comments is number of rows in U
        %N in comments is number of columns in U.
        aa:= 1;
        k:= 2;
        k1:=1;
        u1:=u;
        go to pivot;
   agn: u1 := cdr u1;
        if null cdr u1 or null cddr u1 then return u;
        aa:=nth(car u1,k);              %aa := u(k,k).
        k:=k+2;
        k1:=k-1;
        u1:=cdr u1;
   pivot:  %pivot algorithm.
        k1j:= k1k1 := pnth(car u1,k1);
        if car k1k1 then go to l2;
        ui:= cdr u1;                    %i := k.
   l:   if null ui then return nil
         else if null car(ij := pnth(car ui,k1))
          then go to l1;
   l0:  if null ij then go to l2;
        x:= car ij;
        rplaca(ij,negf car k1j);
        rplaca(k1j,x);
        ij:= cdr ij;
        k1j:= cdr k1j;
        go to l0;
   l1:  ui:= cdr ui;
        go to l;
   l2:  ui:= cdr u1;                    %i:= k;
   l21: if null ui then return; %if i>m then return;
        ij:= pnth(car ui,k1);
        c0:= addf(multf(car k1k1,cadr ij),
                    multf(cadr k1k1,negf car ij));
        if c0 then go to l3;
        ui:= cdr ui;                    %i:= i+1;
        go to l21;
   l3:  c0:= quotf!*(c0,aa);
        kk1 := kj := pnth(cadr u1,k1);  %kk1 := u(k,k-1);
        if cdr u1 and null cddr u1 then go to ev0
         else if ui eq cdr u1 then go to comp;
   l31: if null ij then go to comp;     %if i>n then go to comp;
        x:= car ij;
        rplaca(ij,negf car kj);
        rplaca(kj,x);
        ij:= cdr ij;
        kj:= cdr kj;
        go to l31;
        %pivoting complete.
    comp:
        if null cdr u1 then go to ev;
        ui:= cddr u1;                   %i:= k+1;
    comp1:
        if null ui then go to ev;       %if i>m then go to ev;
        ik1:= pnth(car ui,k1);
        ci1:= quotf!*(addf(multf(cadr k1k1,car ik1),
                           multf(car k1k1,negf cadr ik1)),
                     aa);
        ci2:= quotf!*(addf(multf(car kk1,cadr ik1),
                           multf(cadr kk1,negf car ik1)),
                     aa);
        if null cddr k1k1 then go to comp3;%if j>n then go to comp3;
        ij:= cddr ik1;                     %j:= k+1;
        kj:= cddr kk1;
        k1j:= cddr k1k1;
    comp2:
        if null ij then go to comp3;
        rplaca(ij,quotf!*(addf(multf(car ij,c0),
                               addf(multf(car kj,ci1),
                                  multf(car k1j,ci2))),
                     aa));
        ij:= cdr ij;
        kj:= cdr kj;
        k1j:= cdr k1j;
        go to comp2;
    comp3:
        ui:= cdr ui;
        go to comp1;
    ev0:if null c0 then return;
    ev: kj := cdr kk1;
        x := cddr k1k1;                 %x := u(k-1,k+1);
        rplaca(kj,c0);
    ev1:kj:= cdr kj;
        if null kj then go to agn;
        rplaca(kj,quotf!*(addf(multf(car k1k1,car kj),
                               multf(car kk1,negf car x)),
                     aa));
        x := cdr x;
        go to ev1
   end;

symbolic procedure backsub(u,m);
   begin scalar detm,det1,ij,ijj,ri,summ,uj,ur; integer i,jj;
   %N in comments is number of columns in U.
        if null u then rederr "Singular matrix";
        ur := reverse u;
        detm := car pnth(car ur,m);             %detm := u(i,j).
        if null detm then rederr "Singular matrix";
        i := m;
    rows:
        i := i-1;
        ur := cdr ur;
        if null ur then return u . detm;
                %if i=0 then return u . detm.
        ri := car ur;
        jj := m+1;
        ijj:=pnth(ri,jj);
    r2: if null ijj then go to rows;    %if jj>n then go to rows;
        ij := pnth(ri,i);               %j := i;
        det1 := car ij;                 %det1 := u(i,i);
        uj := pnth(u,i);
        summ := nil;                    %summ := 0;
    r3: uj := cdr uj;                   %j := j+1;
        if null uj then go to r4;       %if j>m then go to r4;
        ij := cdr ij;
        summ := addf(summ,multf(car ij,nth(car uj,jj)));
                %summ:=summ+u(i,j)*u(j,jj);
        go to r3;
    r4: rplaca(ijj,quotf!*(addf(multf(detm,car ijj),negf summ),det1));
                %u(i,j):=(detm*u(i,j)-summ)/det1;
        jj := jj+1;
        ijj := cdr ijj;
        go to r2
   end;

symbolic procedure normmat u; 
   %U is a matrix standard form.
   %Value is dotted pair of matrix polynomial form and factor.
   begin scalar x,y,z; 
      x := 1; 
      for each v in u do
         <<y := 1; 
           for each w in v do y := lcm(y,denr w);
           z := (for each w in v
                    collect multf(numr w,quotf(y,denr w)))
              . z; 
           x := multf(y,x)>>; 
      return reverse z . x
   end;

endmodule;


module det;   % Determinant and trace routines.

% Author: Anthony C. Hearn;

symbolic procedure simpdet u; detq matsm carx(u,'det);

% The hashing and determinant routines below are due to M. L. Griss.

comment Some general purpose hashing functions;

flag('(array),'eval);      %declared again for bootstrapping purposes;

array !$hash 64;  %general array for hashing;

symbolic procedure gethash key;
   %access previously saved element;
   assoc(key,!$hash(remainder(key,64)));

symbolic procedure puthash(key,valu);
   begin integer k; scalar buk;
      k := remainder(key,64);
      buk := (key . valu) . !$hash k;
      !$hash k := buk;
      return car buk
   end;

symbolic procedure clrhash;
   for i := 0:64 do !$hash i := nil;

comment Determinant Routines;

symbolic procedure detq u;
   %top level determinant function;
   begin integer len;
      len := length u;   %number of rows;
      for each x in u do
        if length x neq len then rederr "NON SQUARE MATRIX";
      if len=1 then return caar u;
      clrhash();
      u := detq1(u,len,0);
      clrhash();
      return u
   end;

symbolic procedure detq1(u,len,ignnum);
   %U is a square matrix of order LEN. Value is the determinant of U;
   %Algorithm is expansion by minors of first row;
   %IGNNUM is packed set of column indices to avoid;
   begin integer n2; scalar row,sign,z;
      row := car u;   %current row;
      n2 := 1;
      if len=1
        then return <<while twomem(n2,ignnum)
                         do <<n2 := 2*n2; row := cdr row>>;
                      car row>>;   %last row, single element;
      if z := gethash ignnum then return cdr z;
      len := len-1;
      u := cdr u;
      z := nil ./ 1;
      for each x in row do
        <<if not twomem(n2,ignnum)
            then <<if numr x
                     then <<if sign then x := negsq x;
                            z:= addsq(multsq(x,detq1(u,len,n2+ignnum)),
                                        z)>>;
                   sign := not sign>>;
          n2 := 2*n2>>;
      puthash(ignnum,z);
      return z
   end;

symbolic procedure twomem(n1,n2);
   %for efficiency reasons, this procedure should be coded in assembly
   %language;
   not evenp(n2/n1);

put('det,'simpfn,'simpdet);

symbolic procedure simptrace u;
   begin integer n; scalar z;
        u := matsm carx(u,'trace);
        if length u neq length car u then rederr "NON SQUARE MATRIX";
        n := 1;
        z := nil ./ 1;
        for each x in u do <<z := addsq(nth(x,n),z); n := n+1>>;
        return z
   end;

put('trace,'simpfn,'simptrace);

endmodule;


module glmat; % Routines for inverting matrices and finding eigen-values
              % and vectors. Methods are the same as in glsolve module.
 
% Author: Eberhard Schruefer.
 
fluid '(!*cramer !*gcd kord!*);
 
global '(!!arbint);

if null !!arbint then !!arbint := 0;

switch cramer;
 
put('cramer,'simpfg,
    '((t (put 'mat 'lnrsolvefn 'clnrsolve)
     (put 'mat 'inversefn 'matinv))
      (nil (put 'mat 'lnrsolvefn 'lnrsolve)
       (put 'mat 'inversefn 'matinverse))));
 
% algebraic operator arbcomplex;

% Done this way since it's also defined in the solve1 module.

deflist('((arbcomplex simpiden)),'simpfn);

symbolic procedure clnrsolve(u,v);
   %interface to matrix package.
   multm(matinv u,v);
 
symbolic procedure minv u;
   matinv matsm u;
 
put('minv,'rtypefn,'(lambda (x) 'matrix));

flag('(minv),'matflg);
 
%put('mateigen,'rtypefn,'(lambda (x) 'matrix));
remprop('mateigen,'rtypefn);
%flag('(mateigen),'matflg);
remflag('(mateigen),'matflg);
 
put('detex,'simpfn,'detex);
 
symbolic procedure matinv u;
   %u is a matrix form. Result is the inverse of matrix u.
   begin scalar sgn,x,y,z;
     integer l,m,lm;
     z := 1;
     lm := length car u;
     for each v in u do
       <<y := 1;
     for each w in v do y := lcm(y,denr w);
     m := lm;
     x := list(nil . (l := l + 1)) .* negf y .+ nil;
     for each j in reverse v do
       <<if numr j then
        x := list m .* multf(numr j,quotf(y,denr j)) .+ x;
         m := m - 1>>;
     z := c!:extmult(x,z)>>;
      if singularchk lpow z then rederr "singular matrix";
     sgn := evenp length lpow z;
      return for each k in lpow z collect
          <<sgn := not sgn;
            for each j in lpow z collect mkglimat(k,z,sgn,j)>>
   end;
 
symbolic procedure singularchk u;
   pairp car reverse u;
 
flag('(mateigen),'opfn);

flag('(mateigen),'noval);

symbolic procedure mateigen(u,eival);
   %u is a matrix form, eival an indeterminate naming the eigenvalues.
   %Result is a list of lists: 
   %  {{eival-eq1,multiplicity1,eigenvector1},....},
   %where eival-eq is a polynomial and eigenvector is a matrix.
%    How much should we attempt to solve the eigenvalue eq.? sqfr?
%    Sqfr is necessary if we want to have the full eigenspace. If there
%    are multiple roots another pass through eigenvector calculation
%    is needed(done).
%    We should actually perform the calculations in the extension
%    field generated by the eigenvalue equation(done inside).
%*** needs still checking; seems to do fairly well.
  begin scalar arbvars,exu,sgn,q,r,s,x,y,z,eivec;
     integer l,m,lm;
     z := 1;
     if not(getrtype u eq 'matrix) then typerr(u,"matrix");
     u := matsm u;
     lm := length car u;
     exu := for each v in u collect
          <<y := 1;
        for each w in v do y := lcm(y,denr w);
        m := lm;
        l := l + 1;
        x := nil;
        for each j in reverse v do
          <<if l=m then j := addsq(j,negsq !*k2q !*a2k eival);
            if numr j then
            x := list m .* multf(numr j,quotf(y,denr j)) .+ x;
            m := m - 1>>;
        y := z;
        z := c!:extmult(if null red x then <<
               q := (if p then (car p  . (cdr p + 1)) . delete(p,q)
                      else (lc x  . 1) . q) where p = assoc(lc x,q);
                        !*p2f lpow x>> else x,z);
        x>>;
     r := if minusf lc z then negf lc z else lc z;
     r := numr subs2(r ./ 1);
     kord!* := eival . kord!*;
     if domainp r then s := 1 else
     s := comfac!-to!-poly comfac(r := reorder r);
     r := quotf1(r,s);
     r := if domainp r then nil else sqfrf r;
     if null domainp s and (mvar s eq eival) then
     if red s then r := (s . 1) . r
     else r := (!*k2f eival . ldeg s) . r;
     for each j in q do r := (absf reorder car j . cdr j) . r;
     kord!* := cdr kord!*;
     r := for each j in r collect reorder car j . cdr j;
     l := length r;
     return 'list .
       for each j in r collect
     <<if null((cdr j = 1) and (l = 1)) then
         <<y := 1;
           for each k in exu do
         if x := reduce!-mod!-eig(car j,c!:extmult(k,y))
           then y := x>>;
       arbvars := nil;
       for each k in lpow z do
          if (y=1) or null(k member lpow y) then
         arbvars := (k . makearbcomplex()) . arbvars;
       sgn := (y=1) or evenp length lpow y;
       eivec := 'mat . for each k in lpow z collect list
                           if x := assoc(k,arbvars)
                              then mvar cdr x
                            else prepsq!* mkgleig(k,y,
                                    sgn := not sgn,arbvars);
       list('list,prepsq!*(car j ./ 1),cdr j,eivec)>>
   end;

symbolic procedure reduce!-mod!-eig(u,v);
   %reduces exterior product v wrt eigenvalue equation u.
   begin scalar x,y;
     for each j on v do
       if numr(y := reduce!-mod!-eigf(u,lc j)) then
      x := lpow j .* y .+ x;
     y := 1;
     for each j on x do y := lcm(y,denr lc j);
     return for each j on reverse x collect
          lpow j .* multf(numr lc j,quotf(y,denr lc j))
   end;
 
symbolic procedure reduce!-mod!-eigf(u,v);
   subs2 reduce!-eival!-powers(lpow u . negsq cancel(red u ./ lc u),v);
 
symbolic procedure reduce!-eival!-powers(v,u);
   if domainp u then u ./ 1
    else if mvar u eq caar v then reduce!-eival!-powers1(v,u ./ 1)
    else if ordop(caar v,mvar u) then u ./ 1
    else addsq(multpq(lpow u,reduce!-eival!-powers(v,lc u)),
           reduce!-eival!-powers(v,red u));
 
symbolic procedure reduce!-eival!-powers1(v,u);
   %reduces powers with the help of the eigenvalue polynomial;
   if domainp numr u or (ldeg numr u<pdeg car v) then u
    else if ldeg numr u=pdeg car v then
        addsq(multsq(cdr v,lc numr u ./ denr u),
          red numr u ./ denr u)
   else reduce!-eival!-powers1(v,
    addsq(multsq(multpf(mvar numr u .** (ldeg numr u-pdeg car v),
                lc numr u) ./ denr u,
         cdr v),red numr u ./ denr u));
 
symbolic procedure detex u;
   %u is a matrix form, result is determinant of u.
   begin scalar f,x,y,z;
     integer m,lm;
     z := 1;
     u := matsm car u;
     lm := length car u;
     f := 1;
     for each v in u do
       <<y := 1;
     for each w in v do y := lcm(y,denr w);
     f := multf(y,f);
     m := lm;
     x := nil;
     for each j in v do
       <<if numr j then
        x := list m .* multf(numr j,quotf(y,denr j)) .+ x;
         m := m - 1>>;
     z := c!:extmult(x,z)>>;
      return cancel(lc z ./ f)
   end;
 
symbolic procedure mkglimat(u,v,sgn,k);
   begin scalar s,x,y;
     x := nil ./ 1;
     y := lpow v;
     for each j on red v do
       if s := glmatterm(u,y,j,k)
      then x := addsq(cancel(s ./ lc v),x);
     return if sgn then negsq x else x
   end;
 
symbolic procedure glmatterm(u,v,w,k);
   begin scalar x,y,sgn;
     x := lpow w;
     a: if null x then return
       if pairp car y and (cdar y = k) then lc w else nil;
    if car x = u then return nil
         else if car x member v then <<x := cdr x;
                     if y then sgn := not sgn>>
         else if y then return nil
               else <<y := list car x; x := cdr x>>;
        go to a
   end;
 
symbolic procedure mkgleig(u,v,sgn,arbvars);
   begin scalar s,x,y,!*gcd;
     x := nil ./ 1;
     y := lpow v;
     !*gcd := t;
     for each j on red v do
       if s := glsoleig(u,y,j,arbvars)
      then x := addsq(cancel(s ./ lc v),x);
     return if sgn then negsq x else x
   end;
 
symbolic procedure glsoleig(u,v,w,arbvars);
   begin scalar x,y,sgn;
     x := lpow w;
     a: if null x then return
           if null car y then lc w
        else multf(cdr assoc(car y,arbvars),
               if sgn then negf lc w else lc w);
        if car x = u then return nil
         else if car x member v then <<x := cdr x;
                     if y then sgn := not sgn>>
         else if y then return nil
               else <<y := list car x; x := cdr x>>;
        go to a
   end;
 
 
%**** Support for exterior multiplication ****
% Data structure is lpow ::= list of col.-ind. in exterior product
%                            | nil . number of eq. for inhomog. terms.
%                   lc   ::= standard form
 
 
symbolic procedure c!:extmult(u,v);
   %Special exterior multiplication routine. Degree of form v is
   %arbitrary, u is a one-form.
   if null u or null v then  nil
    else if v = 1 then u                   %unity
    else (if x then cdr x .* (if car x then negf multf(lc u,lc v)
                   else multf(lc u,lc v))
              .+ c!:extadd(c!:extmult(!*t2f lt u,red v),
                       c!:extmult(red u,v))
       else c!:extadd(c!:extmult(!*t2f lt u,red v),
              c!:extmult(red u,v)))
      where x = c!:ordexn(car lpow u,lpow v);
 
symbolic procedure c!:extadd(u,v);
   if null u then v
    else if null v then u
    else if lpow u = lpow v then
            (lambda x,y; if null x then y else lpow u .* x .+ y)
        (addf(lc u,lc v),c!:extadd(red u,red v))
    else if c!:ordexp(lpow u,lpow v) then lt u .+ c!:extadd(red u,v)
    else lt v .+ c!:extadd(u,red v);
 
symbolic procedure c!:ordexp(u,v);
   if null u then t
    else if car u = car v then c!:ordexp(cdr u,cdr v)
    else c!:ordxp(car u,car v);
 
symbolic procedure c!:ordexn(u,v);
   %u is a single index, v a list. Returns nil if u is a member
   %of v or a dotted pair of a permutation indicator and the ordered
   %list of u merged into v.
   begin scalar s,x;
     a: if null v then return(s . reverse(u . x))
     else if (u = car v) or (pairp u and pairp car v)
         then return nil
     else if c!:ordxp(u,car v) then
         return(s . append(reverse(u . x),v))
         else  <<x := car v . x;
                 v := cdr v;
                 s := not s>>;
         go to a
   end;
 
symbolic procedure c!:ordxp(u,v);
   if pairp u then if pairp v then cdr u < cdr v
            else nil
    else if pairp v then t
    else u < v;
 
endmodule;


end;
