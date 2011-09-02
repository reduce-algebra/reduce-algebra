module matrix;  % Header for matrix package.

% Author: Anthony C. Hearn.

% This module is rife with essential references to RPLAC-based
% functions.

create!-package('(matrix matpri bareiss det glmat nullsp rank
                  resultant cofactor),nil);

fluid '(!*sub2);

global '(nxtsym!* subfg!*);

symbolic procedure matrix u;
   % Declares list U as matrices.
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
                    put(car j,'avalue,list('matrix,'mat . w))>>
            else typerr(list(x,car j),"matrix")
   end;

symbolic procedure natnumlis u;
   % True if U is a list of natural numbers.
   null u or fixp car u and car u>0 and natnumlis cdr u;

rlistat '(matrix);

symbolic procedure nzero n;
   % Returns a list of N zeros.
   if n=0 then nil else 0 . nzero(n-1);

% Parsing interface.

symbolic procedure matstat;
   % Read a matrix.
   begin scalar x,y;
      if not (nxtsym!* eq '!() then symerr("Syntax error",nil);
   a: scan();
      if not (scan() eq '!*lpar!*) then symerr("Syntax error",nil);
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
   'list . mkquote car u
     . for each x in cdr u collect('list . formlis(x,vars,mode));

put('mat,'formfn,'formmat);

put('mat,'i2d,'mkscalmat);

put('mat,'inversefn,'matinverse);

put('mat,'lnrsolvefn,'lnrsolve);

put('mat,'rtypefn,'quotematrix);

symbolic procedure quotematrix u; 'matrix;

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
      x := get(car u,'avalue);
      if null x or not(car x eq 'matrix) then typerr(car u,"matrix")
       else if not eqcar(x := cadr x,'mat)
        then if idp x
         then return getmatelem (x . cdr u)
         else rerror(matrix,1,list("Matrix",car u,"not set"))
        else if not numlis (u := revlis cdr u) or length u neq 2
         then errpri2(x . u,t)
         else return nth(nth(cdr x,car u),cadr u);
   end;

symbolic procedure setmatelem(u,v); letmtr(u,v,cadr get(car u,'avalue));

symbolic procedure matlength u;
   if not eqcar(u,'mat) then rerror(matrix,2,list("Matrix",u,"not set"))
    else list('list,length cdr u,length cadr u);

% Aggregate Property.  Commented out for now.

% symbolic procedure matrixmap(u,v);
%    if flagp(car u,'matmapfn)
%     then matsm!*1 for each j in matsm cadr u collect
%             for each k in j collect simp!*(car u . mk!*sq k . cddr u)
%    else if flagp(car u,'matfn) then reval2(u,v)
%     else typerr(car u,"matrix operator");

% put('matrix,'aggregatefn,'matrixmap);

% flag('(int df),'matmapfn);

% flag('(det trace),'matfn);

symbolic procedure matsm!*(u,v);
   % Matrix expression simplification function.
   matsm!*1 matsm u;

symbolic procedure matsm!*1 u;
   begin scalar sub2;
      sub2 := !*sub2;  % Since we need value for each element.
      u := 'mat . for each j in u collect
                     for each k in j
                        collect <<!*sub2 := sub2; !*q2a subs2 k>>;
      !*sub2 := nil;   % Since all substitutions done.
      return u
   end;

symbolic procedure mk!*sq2 u;
   begin scalar x;
        x := !*sub2;   % Since we need value for each element.
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
         else x := lispapply(caar u,cdar u);
    b:  z := if null z then x
              else if null cdr z and null cdar z then multsm(caar z,x)
              else multm(x,z);
    c:  u := cdr u;
        go to a;
    c1: if not lchk cdar u then rerror(matrix,3,"Matrix mismatch");
        x := for each j in cdar u collect
                for each k in j collect xsimp k;
        go to b;
    d:  y := matsm cadar u;
        if (n := length car y) neq length y
          then rerror(matrix,4,"Non square matrix")
         else if (z and n neq length z)
          then rerror(matrix,5,"Matrix mismatch")
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
    e:  if null caaar y then rerror(matrix,6,"Zero divisor");
        y := revpr caar y;
        z := if null z then list list y else multsm(y,z);
        go to c;
     h: if null z then z := generateident n;
        go  to c;
    er: rerror(matrix,7,list("Matrix",car u,"not set"))
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
    else if null u or null v then rerror(matrix,8,"Matrix mismatch")
    else apply2(w,car u,car v) . addm1(cdr u,cdr v,w);

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
    else if null u or null v then rerror(matrix,9,"Matrix mismatch")
    else addsq(multsq(car u,car v),scalprod(cdr u,cdr v));

symbolic procedure multm(u,v);
   %returns matrix product of two matrix canonical forms U and V;
   (for each y in u
      collect for each k in x collect subs2 scalprod(y,k))
     where x = tp1 v;

symbolic procedure multsm(u,v);
   %returns product of standard quotient U and matrix standard form V;
   if u = (1 ./ 1) then v
    else for each j in v collect for each k in j collect multsq(u,k);

symbolic procedure letmtr(u,v,y);
   %substitution for matrix elements;
   begin scalar z;
        if not eqcar(y,'mat)
          then rerror(matrix,10,list("Matrix",car u,"not set"))
         else if not numlis (z := revlis cdr u) or length z neq 2
          then return errpri2(u,'hold);
        rplaca(pnth(nth(cdr y,car z),cadr z),v);
   end;

% Explicit substitution code for matrices.

symbolic procedure matsub(u,v);
   'mat . for each x in cdr v collect
              for each y in x collect subeval1(u,y);

put('matrix,'subfn,'matsub);

endmodule;


module matpri;   % Matrix printing routines.

% Author: Anthony C. Hearn.
% Modified by Arthur C. Norman.

fluid '(!*nat orig!* pline!* posn!* ycoord!* ymax!* ymin!*);

global '(obrkp!*);

symbolic procedure setmatpri(u,v);
   matpri1(cdr v,u);

put('mat,'setprifn,'setmatpri);

symbolic procedure matpri u;
   matpri1(cdr u,nil);

symbolic procedure matpri1(u,x);
   % Prints a matrix canonical form U with name X.
   % Tries to do fancy display if nat flag is on.
   begin scalar m,n,r,l,w,e,ll,ok,name,nw,widths,firstflag,toprow,lbar,
                rbar,realorig;
      if !*fort
        then <<m := 1;
               if null x then x := "MAT";
               for each y in u do
                  <<n := 1;
                    for each z in y do
                       <<varpri(z,list('setq,list(x,m,n),z),'only);
                         n := n+1>>;
                    m := m+1>>;
               return nil>>;
      terpri!* t;
      if x and !*nat then <<
         name := layout!-formula(x, 0, nil);
         if name then <<
           nw := cdar name + 4;
           ok := !*nat >>>>
       else <<nw := 0; ok := !*nat>>;
      ll := linelength nil - spare!* - orig!*;
      m := length car u;
      widths := mkvect(1 + m);
      for i := 1:m do putv(widths, i, 1);
      % Collect sizes for all elements to see if it will fit in
      % displayed matrix form.
      % We need to compute things wrt a zero orig for the following
      % code to work properly.
      realorig := orig!*;
      orig!* := 0;
      if ok then for each y in u do
       <<n := 1;
         l := nil;
         w := 0;
         if ok then for each z in y do if ok then <<
            e := layout!-formula(z, 0, nil);
              if null e then ok := nil
              else begin
                scalar col;
                col := max(getv(widths, n), cdar e);
% this allows for 2 blanks between cols, and also 2 extra chars, one
% for the left-bar and one for the right-bar.
                if (w := w + col + 2) > ll then ok := nil
                else <<
                  l := e . l;
                  putv(widths, n, col) >> end;
            n := n+1>>;
         r := (reverse l) . r >>;
         if ok then <<
         % Matrix will fit in displayed representation.
         % Compute format with respect to 0 posn.
         firstflag := toprow := t;
         r := for each py on reverse r collect begin
            scalar y, ymin, ymax, pos, pl, k, w;
            ymin := ymax := 0;
            pos := 1;    % Since "[" is of length 1.
            k := 1;
            pl := nil;
            y := car py;
            for each z in y do <<
               w := getv(widths, k);
               pl := append(update!-pline(pos+(w-cdar z)/2,0,caar z),
                            pl);      % Centre item in its field
               pos := pos + w + 2;    % 2 blanks between cols
               k := k + 1;
               ymin := min(ymin, cadr z);
               ymax := max(ymax, cddr z) >>;
            k := nil;
            if firstflag then firstflag := nil
             else ymax := ymax + 1;   % One blank line between rows
            for h := ymax step -1 until ymin do <<
               if toprow then <<
                  lbar := symbol 'mat!-top!-l;
                  rbar := symbol 'mat!-top!-r;
                  toprow := nil >>
                else if h = ymin and null cdr py then <<
                  lbar := symbol 'mat!-low!-l;
                  rbar := symbol 'mat!-low!-r >>
%               else lbar := rbar := symbol 'vbar;
                else <<lbar := symbol 'mat!-low!-l;
                       rbar := symbol 'mat!-low!-r>>;
               pl := ((((pos - 2) . (pos - 1)) . h) . rbar) . pl;
               k := (((0 . 1) . h) . lbar) . k >>;
            return (append(pl, k) . pos) . (ymin . ymax) end;
         orig!* := realorig;
         w := 0;
         for each y in r do w := w + (cddr y - cadr y + 1);
               % Total height.
         n := w/2;  % Height of mid-point.
         u := nil;
         for each y in r do <<
            u := append(update!-pline(0, n - cddr y, caar y), u);
            n := n - (cddr y - cadr y + 1) >>;
         if x then <<maprin x; oprin 'setq >>;
         pline!* := append(update!-pline(posn!*,ycoord!*,u),
                           pline!*);
         ymax!* := max(ycoord!* + w/2, ymax!*);
         ymin!* := min(ycoord!* + w/2 - w, ymin!*);
         terpri!*(not !*nat)>>
      else <<if x then <<maprin x; oprin 'setq>>; matpri2 u>>
   end;

symbolic procedure matpri2 u;
   begin scalar y;
      prin2!* 'mat;
      prin2!* "(";
      obrkp!* := nil;
      y := orig!*;
      orig!* := if posn!*<18 then posn!* else orig!*+3;
      while u do
         <<prin2!* "(";
           orig!* := orig!*+1;
           inprint('!*comma!*,0,car u);
           prin2!* ")";
           if cdr u
             then <<oprin '!*comma!*; orig!* := orig!*-1;
                    terpri!* !*nat>>;
           u := cdr u>>;
      obrkp!* := t;
      orig!* := y;
      prin2!* ")";
      if null !*nat then prin2!* "$";
      terpri!* t
   end;

endmodule;


module bareiss; % Inversion routines using the Bareiss 2-step method.

% Author: Anthony C. Hearn.

% This module is rife with essential references to RPLAC-based
% functions.

fluid '(!*exp asymplis!* wtl!*);

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
   (if null x then nil else cdr x) where x= bareiss1(u,nil);

symbolic procedure bareiss1(u,perm);
  % The 2-step integer preserving elimination method of Bareiss based on
  % the implementation of Lipson.  This is based on the original Bareiss
  % function in REDUCE, modified to reduce singular matrices.  If PERM
  % is nil, it behaves like the old BAREISS, except a pair is returned
  % for non-singular U, whose cdr is the triangularized U.  The car is
  % the rank of U, which in this case is always LENGTH(U).  Otherwise
  % PERM is a list of the integers 1,2...length(U).  As columns are
  % interchanged, then so are the elements of PERM.  In this case a pair
  % is returned whose car is the rank of U and whose cdr is the
  % triangularized U.  Note that, just as in BAREISS, the lower
  % triangular portion of the returned matrix standard form is only
  % implicitly all nils--the requisite RPLACAs are not performed.  Also,
  % if PERM is non-nil and the rank,r, of U is less than the order of U,
  % only the first r rows of the upper triangular portion are explicitly
  % set.  The all nil rows are only implicitly all nils.  U is a list of
  % lists of standard forms (a matrix standard form) corresponding to
  % the appropriate augmented matrix.  If the value of procedure is NIL
  % then U is singular, otherwise the value is the triangularized form
  % of U (in the same form).
  begin scalar aa,c0,ci1,ci2,ik1,ij,kk1,kj,k1j,k1k1,
               ui,u1,x,k1col,kij,flg;
        integer k,k1,col,maxcol;
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
        maxcol := length(u);
        aa:= 1;
        k:= 2;
        k1:=1;
        u1:=u;
        go to pivot;
   agn: u1 := cdr u1;
        if null cdr u1 or null cddr u1
          then return if perm and cdr u1 
                         and null car(ij := pnth(nth(u,maxcol),maxcol))
                 then if not allnils cdr ij then nil else (maxcol-1) . u
                 else maxcol . u;
        aa:=nth(car u1,k);              % aa := u(k,k).
        k:=k+2;
        k1:=k-1;
        u1:=cdr u1;
   pivot:  %pivot algorithm;
        col := k1;
        k1j:= k1k1 := pnth(car u1,k1);
  piv1: k1col := pnth(car(u1), col);
        if car k1col then go to l2;
        ui:= cdr u1;                    % i := k.
   l:   if null ui then
           if perm then
              if col>=maxcol then
                 return (k1-1).u
              else <<
                 col := col+1;
                 go to piv1 >>
           else
              return nil
        else if null car(ij := pnth(car ui,col))
          then go to l1;
   l0:  if null ij then go to l2;
        x := car ij;
        rplaca(ij,negf car k1col);
        rplaca(k1col,x);
        ij:= cdr ij;
        k1col:= cdr k1col;
        go to l0;
   l1:  ui:= cdr ui;
        go to l;
   l2:  swapcolumns(u, k1, col, perm);
        col := k;
  piv2: ui:= cdr u1;                    % i:= k.
   l21: if null ui then
           if perm then
              if col>=maxcol then <<
                 flg := t;
                 while flg and u1 do <<
                    ik1 := pnth(car(u1), k1);
                    ij := pnth(ik1, maxcol-k1+2);
                    kij := pnth(k1k1, maxcol-k1+2);
                    while flg and ij do
                       if addf(multf(car(k1k1), car(ij)),
                               multf(car(ik1), negf(car(kij))) )
                       then flg := nil
                       else ij := cdr(ij);
                    u1 := cdr(u1) >>;
                 if flg then
                    return (k-1).u
                 else
                    return nil >>
              else <<
                 col := col+1;
                 go to piv2 >>
           else
              return nil;
        ij:= pnth(car ui,k1);
        c0:= addf(multf(car k1k1,nth(ij, col-k+2)),
                  multf(nth(k1k1, col-k+2),negf car ij));
        if c0 then go to l3;
        ui:= cdr ui;                    % i:= i+1.
        go to l21;
   l3:  swapcolumns(u, k, col, perm);
        c0:= quotf!*(c0,aa);
        kk1 := kj := pnth(cadr u1,k1);  % kk1 := u(k,k-1).
        if cdr u1 and null cddr u1 then go to ev0
         else if ui eq cdr u1 then go to comp;
   l31: if null ij then go to comp;     % if i>n then go to comp.
        x:= car ij;
        rplaca(ij,negf car kj);
        rplaca(kj,x);
        ij:= cdr ij;
        kj:= cdr kj;
        go to l31;
        %pivoting complete;
    comp:
        if null cdr u1 then go to ev;
        ui:= cddr u1;                   % i:= k+1.
    comp1:
        if null ui then go to ev;       % if i>m then go to ev.
        ik1:= pnth(car ui,k1);
        ci1:= quotf!*(addf(multf(cadr k1k1,car ik1),
                           multf(car k1k1,negf cadr ik1)),
                     aa);
        ci2:= quotf!*(addf(multf(car kk1,cadr ik1),
                           multf(cadr kk1,negf car ik1)),
                     aa);
        if null cddr k1k1 then go to comp3; % if j>n then go to comp3.
        ij:= cddr ik1;                  % j := k+1.
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
        x := cddr k1k1;                 % x := u(k-1,k+1).
        rplaca(kj,c0);
    ev1:kj:= cdr kj;
        if null kj then go to agn;
        rplaca(kj,quotf!*(addf(multf(car k1k1,car kj),
                               multf(car kk1,negf car x)),
                     aa));
        x := cdr x;
        go to ev1
   end;

symbolic procedure allnils u; null u or null car u and allnils cdr u;

symbolic procedure swapcolumns(matrx,col1,col2,perm);
   if col1=col2 then matrx
    else <<swapelements(perm,col1,col2);
           for each u in matrx do swapelements(u,col1,col2);
           matrx>>;

symbolic procedure swapelements(lst,i,j);
   % Uses rplaca to swap ith and jth elements of the list lst. 
   % Returns nil.
   begin scalar temp;
      if i>j then <<temp := i; i := j; j := temp>>;
      lst := pnth(lst,i);
      i := j-i+1;
      temp := nth(lst,i);
      rplaca(pnth(lst,i),car lst);
      rplaca(lst,temp)
   end;

symbolic procedure backsub(u,m);
   begin scalar detm,det1,ij,ijj,ri,summ,uj,ur; integer i,jj;
   %N in comments is number of columns in U.
        if null u then rerror(matrix,11,"Singular matrix");
        ur := reverse u;
        detm := car pnth(car ur,m);             %detm := u(i,j).
        if null detm then rerror(matrix,12,"Singular matrix");
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

% Author: Anthony C. Hearn.

symbolic procedure simpdet u; detq matsm carx(u,'det);

% The hashing and determinant routines below are due to M. L. Griss.

Comment Some general purpose hashing functions;

flag('(array),'eval);      % Declared again for bootstrapping purposes.

array !$hash 64;  % General array for hashing.

symbolic procedure gethash key;
   % Access previously saved element.
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

Comment Determinant Routines;

symbolic procedure detq u;
   % Top level determinant function.
   begin integer len;
      len := length u;   % Number of rows.
      for each x in u do
        if length x neq len then rederr "Non square matrix";
      if len=1 then return caar u;
      clrhash();
      u := detq1(u,len,0);
      clrhash();
      return u
   end;

symbolic procedure detq1(u,len,ignnum);
   % U is a square matrix of order LEN. Value is the determinant of U.
   % Algorithm is expansion by minors of first row.
   % IGNNUM is packed set of column indices to avoid.
   begin integer n2; scalar row,sign,z;
      row := car u;   % Current row.
      n2 := 1;
      if len=1
        then return <<while twomem(n2,ignnum)
                         do <<n2 := 2*n2; row := cdr row>>;
                      car row>>;   % Last row, single element.
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
   % For efficiency reasons, this procedure should be coded in assembly
   % language.
   not evenp(n2/n1);

put('det,'simpfn,'simpdet);

flag('(det),'immediate);

symbolic procedure simptrace u;
   begin integer n; scalar z;
        u := matsm carx(u,'trace);
        if length u neq length car u then rederr "Non square matrix";
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
% Modification: James Davenport and Fran Burstall.
 
fluid '(!*cramer !*factor !*gcd !*sqfree !*sub2 kord!*);
 
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
   % Interface to matrix package.
   multm(matinv u,v);
 
symbolic procedure minv u;
   matinv matsm u;
 
put('minv,'rtypefn,'quotematrix);

%put('mateigen,'rtypefn,'quotematrix);

remprop('mateigen,'rtypefn);
 
put('detex,'simpfn,'detex);
 
symbolic procedure matinv u;
   % U is a matrix form. Result is the inverse of matrix u.
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
      if singularchk lpow z then rerror(matrix,13,"Singular matrix");
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
   % U is a matrix form, eival an indeterminate naming the eigenvalues.
   % Result is a list of lists:
   %   {{eival-eq1,multiplicity1,eigenvector1},....},
   % where eival-eq is a polynomial and eigenvector is a matrix.
%    How much should we attempt to solve the eigenvalue eq.? sqfr?
%    Sqfr is necessary if we want to have the full eigenspace. If there
%    are multiple roots another pass through eigenvector calculation
%    is needed(done).
%    We should actually perform the calculations in the extension
%    field generated by the eigenvalue equation(done inside).
  begin scalar arbvars,exu,sgn,q,r,s,x,y,z,eivec,!*factor,!*sqfree;
        integer l;
     if not(getrtype u eq 'matrix) then typerr(u,"matrix");
     eival := !*a2k eival;
     kord!* := eival . kord!*;
     exu := mateigen1(matsm u,eival);
     q := car exu;
     y := cadr exu;
     z := caddr exu;
     exu := cdddr exu;
     !*sqfree := t;
     for each j in cdr fctrf numr subs2(lc z ./ 1)
          do if null domainp car j and mvar car j eq eival
                then s := (if null red car j
                              then !*k2f mvar car j . (ldeg car j*cdr j)
                            else j) . s;
     for each j in q
       do (if x then rplacd(x,cdr x + cdr j)
             else s := (y . cdr j) . s)
            where x := assoc(y,s) where y := absf reorder car j;
     l := length s;
     r := 'list .
       for each j in s collect
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
       list('list,prepsq!*(car j ./ 1),cdr j,eivec)>>;
     kord!* := cdr kord!*;
     return r
   end;

symbolic procedure mateigen1(u,eival);
   begin scalar q,x,y,z; integer l,lm,m;
      lm := length car u;
      z := 1;
      u := for each v in u collect
          <<y := 1;
        for each w in v do y := lcm(y,denr w);
        m := lm;
        l := l + 1;
        x := nil;
        for each j in reverse v do
          <<if numr j or l = m then
            x := list m .* multf(if l = m then
                                  addf(numr j,
                                       negf multf(!*k2f eival,
                                                  denr j)) else numr j,
                                 quotf(y,denr j)) .+ x;
            m := m - 1>>;
        y := z;
        z := c!:extmult(if null red x then <<
               q := (if p then (car p  . (cdr p + 1)) . delete(p,q)
                      else (lc x  . 1) . q) where p = assoc(lc x,q);
                        !*p2f lpow x>> else x,z);
        x>>;
      return q . y . z . u
   end;

symbolic procedure reduce!-mod!-eig(u,v);
   % Reduces exterior product v wrt eigenvalue equation u.
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
   (subs2 reduce!-eival!-powers(lpow u . negsq cancel(red u ./ lc u),v))
    where !*sub2 = !*sub2;
 
symbolic procedure reduce!-eival!-powers(v,u);
   if domainp u or null(mvar u eq caar v) then u ./ 1
    else reduce!-eival!-powers1(v,u ./ 1);

symbolic procedure reduce!-eival!-powers1(v,u);
   % Reduces powers with the help of the eigenvalue polynomial.
   if domainp numr u or (ldeg numr u<pdeg car v) then u
    else if ldeg numr u=pdeg car v then
        addsq(multsq(cdr v,lc numr u ./ denr u),
          red numr u ./ denr u)
   else reduce!-eival!-powers1(v,
    addsq(multsq(multpf(mvar numr u .** (ldeg numr u-pdeg car v),
                lc numr u) ./ denr u,
         cdr v),red numr u ./ denr u));
 
symbolic procedure detex u;
   % U is a matrix form, result is determinant of u.
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
 

% Exterior multiplication and p-forms:
% Let V be a vector space of dimension n.
% We call the elements of V 1-forms and build new objects called
% p-forms as follows: define a multiplication on 1-forms ^ such that
%                v^w=-w^v
% then the linear span of such objects is the space of 2-forms and has
% dimension n(n-1)/2.  Indeed, if v_1,...,v_n is a basis of V then
% v_i^v_j for i<j is a basis for the 2-forms.
% We extend this multiplication (called exterior multiplication)
% to get products of p vectors, linear combinations of which are
% called p-forms: this extension is defined by the rule that v_1^...^v_p
% vanishes whenever some v_i=v_j (for i not j).  Thus the effect of
% permuting the order of the vectors in such a product is to multiply
% the product by the sign of the permutation.
% Using this it is not difficult to show:
% Theorem: Vectors v_1,...,v_p are linear independent iff their exterior
% product v_1^...^v_p is non-zero.
%
% For more information see F. Warner "Foundations of Differentiable
% Manifolds and Lie Groups" (Springer) Chapter 2. (Or any other book
% on differential geometry or multilinear algebra

symbolic procedure c!:extmult(u,v);
   % Special exterior multiplication routine. Degree of form v is
   % arbitrary, u is a one-form.
   if null u or null v then  nil
    else if v = 1 then u                   %unity
%   else (if x then cdr x .* (if car x
%                        then negf c!:subs2multf(lc u,lc v)
%          else c!:subs2multf(lc u,lc v))
%             .+ c!:extadd(c!:extmult(!*t2f lt u,red v),
%             ^^ this is bogus: .+ may not be valid in this circumstance
%                      c!:extmult(red u,v))
    else (if x then 
             c!:extadd(cdr x .* (if car x
                                 then negf c!:subs2multf(lc u,lc v)
                   else c!:subs2multf(lc u,lc v)) .+ nil,
                       c!:extadd(c!:extmult(!*t2f lt u,red v),
                                 c!:extmult(red u,v)))
       else c!:extadd(c!:extmult(!*t2f lt u,red v),
              c!:extmult(red u,v)))
      where x = c!:ordexn(car lpow u,lpow v);

symbolic procedure c!:subs2multf(u,v);
   (if denr x neq 1 then rerror(matrix,14,"Sub error in glnrsolve")
     else numr x)
   where x = subs2(multf(u,v) ./ 1) where !*sub2 = !*sub2;

 
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
   % U is a single index, v a list. Returns nil if u is a member
   % of v or a dotted pair of a permutation indicator and the ordered
   % list of u merged into v.
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


module nullsp;  % Compute the nullspace (basis vectors) of a matrix.
 
% Author: Herbert Melenk <melenk@sc.zib-berlin.de>.

% Algorithm:  Rational Gaussian elimination with standard qutotients.

put('nullspace,'psopfn,'nullspace!-eval);

symbolic procedure nullspace!-eval u;
   % interface for the nullspace calculation.
   begin scalar v,n,matinput;
     v := reval car u;
     if eqcar(v,'mat) then
        <<matinput:=t; v := cdr v>>
     else if eqcar(v,'list) then
      v := for each row in cdr v collect
        if not eqcar(row,'list) then typerr ("matrix",u) else
        <<row := cdr row;
          if null n then n := length row else
          if n neq length row
            then rerror(matrix,15,"lists not in matrix shape");
          row>> else rerror(matrix,16,"Not a matrix");
     v := nullspace!-alg v;
     return 'list . for each vect in v collect
         if matinput then 'mat . for each x in vect collect list x
           else 'list . vect;
   end;
     
symbolic procedure nullspace!-alg(m);
   % "M" is a Matrix, encoded as list of lists(=rows) of algebraic
   % expressions.
   % Result is the basis of the kernel of M in the same encoding.
   begin scalar mp,vars,rvars,r,res,oldorder; integer n;
     n := length car m;
     vars := for i:=1:n collect gensym();
     rvars := reverse vars;
     oldorder := setkorder rvars;
     mp := for each row in m collect
     <<r := nil ./ 1;
      for each col in pair(vars,row) do
         r := addsq(r,simp list('times,car col,cdr col));
      r>>;
     res := nullspace!-elim(mp,rvars);
     setkorder oldorder;
     return reverse for each q in res collect
       for each x in vars collect
        cdr atsoc(x,q);
   end;

symbolic procedure nullspace!-elim(m,vars);
   % "M" is a matrix encoded as list of linear polnomials (sq's) in
   % the variables "vars". The current korder cooresponds to vars.
   % Result is a basis for the null space of the matrix, encoded
   % as list of vectors, where each vector is an alist over vars.
   % A rational Gaussian elimination is performed and unit vectors
   % are substituted for the remaining unrestricted variables.
  begin scalar c,s,x,arbvars,depvars,row,res,break;
     while vars and not break do
     <<for each p in m do 
        if domainp numr p then if numr p then break:=t %unsolvable
                                else m:=delete(p,m);
       if not break then
       <<x:=car vars; vars:=cdr vars; row:=nil;
            % select row with x as leading variable.
         for each p in m do 
           if null row and mvar numr p = x then row:=p;
            % if none, then x is a free variable.
        if null row then arbvars:=x.arbvars else
        <<m:=delete(row,m);
          c:=multsq(negf denr row ./1, 1 ./ lc numr row);
          row := multsq(row,c);
            % collect formula for x,
          depvars := (x . (red numr row ./ denr row)) . depvars;
            % and perform elimination with this row.
          m:=for each p in m collect
           if mvar numr p=x then
            addsq(p, multsq(row,lc numr p ./ denr p))
                else p;
        >>;
      >>;
    >>;
    if break then return nil;
         % Constuct solutions by assigning unit vectors to the
         % free variables and perform backsubstitution.
    for each x in arbvars do
    << s := for each y in arbvars collect
          (y . if y=x then 1 else 0);
       for each y in depvars do
         s := (car y . prepsq subsq(cdr y,s)) . s;
       res := s . res;
    >>;
    return res;
  end;
 
endmodule;


module rank;

% Author: Eberhard Schruefer.

% Module for calculating the rank of a matrix or a system of linear
% equations.  It is assumed that glmat or glsolve are loaded.
% Format: rank <matrix> : rank <list of equations> :
%         rank(<list of equations>,<list of unknowns>)

symbolic procedure rank!-eval u;
   if getrtype car u eq 'matrix
      then if cdr u then rerror(matrix,17,"Wrong number of arguments")
             else rank!-matrix matsm car u
    else if null (getrtype car u eq 'list)
            then  rerror(matrix,18,"Wrong type")
    else begin scalar unknowns,equations,okord; integer n;
           if cdr u then
                 unknowns := for each j in cdr listeval(cadr u,nil)
                              collect !*a2k j;
              okord := setkorder append(unknowns,kord!*);
              equations := for each j in cdr listeval(car u,nil)
                               collect reorder numr simp!* j;
           if null unknowns
              then unknowns := allkernf equations;
           n := rank!-gleqs(equations,unknowns);
           setkorder okord;
           return n     
         end;

put('rank,'psopfn,'rank!-eval);

symbolic procedure rank!-gleqs(u,v);
   begin scalar x,y; integer n;
     n := 1;
     x := !*sf2ex(car u,v);
     u := cdr u;
     for each j in u do
            if y := extmult(!*sf2ex(j,v),x)
               then <<x := y;
                  n := n + 1>>;
     return n
   end;

symbolic procedure rank!-matrix u;
   begin scalar x,y,z; integer m,n;
     z := 1;
     for each v in u do
          <<y := 1;
        for each w in v do y := lcm(y,denr w);
        m := 1;
        x := nil;
        for each j in v do
          <<if numr j then
            x := list m .* multf(numr j,quotf(y,denr j)) .+ x;
            m := m + 1>>;
        if y := c!:extmult(x,z)
           then <<z := y; n := n + 1>>>>;
     return n
    end;

endmodule;


module resultant;

% Author: Eberhard Schruefer.

%**********************************************************************
%                                                                     *
% The resultant function defined here has the following properties:   *
%                                                                     *
%                           degr(p1,x)*degr(p2,x)                     *
%  resultant(p1,p2,x) = (-1)                     *resultant(p2,p1,x)  *
%                                                                     *
%                         degr(p2,x)                                  *
%  resultant(p1,p2,x) = p1             if p1 free of x                *
%                                                                     *
%  resultant(p1,p2,x) = 1  if p1 free of x and p2 free of x           *
%                                                                     *
%**********************************************************************

%exports resultant;

%imports reorder,setkorder,degr,addf,negf,multf,multpf;

fluid '(!*exp kord!*);

symbolic procedure resultant(u,v,w);
   %u and v are standard forms. Result is resultant of u and v
   %w.r.t. kernel w. Method is Bezout's determinant using exterior
   %multiplication for its calculation.
   begin scalar ap,ep,uh,ut,vh,vt;
         integer n,nm;
     if domainp u and domainp v then return 1;
     kord!* := w . kord!*;
     if null domainp u and null(mvar u eq w) then u := reorder u;
     if null domainp v and null(mvar v eq w) then v := reorder v;
     if domainp u or null(mvar u eq w)
        then <<setkorder cdr kord!*;
               return if not domainp v and mvar v eq w
                        then exptf(u,ldeg v)
                       else 1>>
      else if domainp v or null(mvar v eq w)
        then <<setkorder cdr kord!*;
               return if mvar u eq w then exptf(v,ldeg u)
                       else 1>>;
      n := ldeg u - ldeg v;
      ep := 1;
      if n<0 then
          <<for j := (-n-1) step -1 until 1 do
              ep := b!:extmult(!*sf2exb(multpf(w to j,u),w),ep);
              ep := b!:extmult(!*sf2exb(multd((-1)**(-n*ldeg u),u),
                                        w),
                               ep)>>
       else if n>0 then
            <<for j := (n-1) step -1 until 1 do
                ep := b!:extmult(!*sf2exb(multpf(w to j,v),w),ep);
              ep := b!:extmult(!*sf2exb(v,w),ep)>>;
     nm := max(ldeg u,ldeg v);
     uh := lc u;
     vh := lc v;
     ut := if n<0 then multpf(w to -n,red u)
           else red u;
     vt := if n>0 then multpf(w to n,red v)
            else red v;
     ap := addf(multf(uh,vt),negf multf(vh,ut));
     ep := if null ep then !*sf2exb(ap,w)
        else b!:extmult(!*sf2exb(ap,w),ep);
     for j := (nm - 1) step -1 until (abs n + 1) do
        <<if degr(ut,w) = j then
         <<uh := addf(lc ut,multf(!*k2f w,uh));
                   ut := red ut>>
       else    uh := multf(!*k2f w,uh);
          if degr(vt,w) = j then
         <<vh := addf(lc vt,multf(!*k2f w,vh));
                   vt := red vt>>
       else    vh := multf(!*k2f w,vh);
      ep := b!:extmult(!*sf2exb(addf(multf(uh,vt),
                    negf multf(vh,ut)),w),ep)>>;
     setkorder cdr kord!*;
     return if null ep then nil else lc ep
   end;

put('resultant,'simpfn,'simpresultant);

symbolic procedure simpresultant u;
   begin scalar !*exp;
     if length u neq 3
       then rerror(matrix,19,
                   "RESULTANT called with wrong number of arguments");
     !*exp := t;
     return resultant(!*q2f simp!* car u,
                      !*q2f simp!* cadr u,
                      !*a2k caddr u) ./ 1
   end;

symbolic procedure !*sf2exb(u,v);
   %distributes s.f. u with respect to powers in v.
   if degr(u,v)=0 then if null u then nil
                        else list 0 .* u .+ nil
    else list ldeg u .* lc u .+ !*sf2exb(red u,v);

%**** Support for exterior multiplication ****
% Data structure is lpow ::= list of degrees in exterior product
%                   lc   ::= standard form

symbolic procedure b!:extmult(u,v);
   %Special exterior multiplication routine. Degree of form v is
   %arbitrary, u is a one-form.
   if null u or null v then  nil
    else if v = 1 then u
    else (if x then cdr x .* (if car x then negf multf(lc u,lc v)
                   else multf(lc u,lc v))
              .+ b!:extadd(b!:extmult(!*t2f lt u,red v),
                    b!:extmult(red u,v))
       else b!:extadd(b!:extmult(red u,v),
              b!:extmult(!*t2f lt u,red v)))
      where x = b!:ordexn(car lpow u,lpow v);

symbolic procedure b!:extadd(u,v);
   if null u then v
    else if null v then u
    else if lpow u = lpow v then
            (lambda x,y; if null x then y else lpow u .* x .+ y)
        (addf(lc u,lc v),b!:extadd(red u,red v))
    else if b!:ordexp(lpow u,lpow v) then lt u .+ b!:extadd(red u,v)
    else lt v .+ b!:extadd(u,red v);

symbolic procedure b!:ordexp(u,v);
   if null u then t
    else if car u > car v then t
    else if car u = car v then b!:ordexp(cdr u,cdr v)
    else nil;

symbolic procedure b!:ordexn(u,v);
   %u is a single integer, v a list. Returns nil if u is a member
   %of v or a dotted pair of a permutation indicator and the ordered
   %list of u merged into v.
   begin scalar s,x;
     a: if null v then return(s . reverse(u . x))
     else if u = car v then return nil
     else if u and u > car v then
                 return(s . append(reverse(u . x),v))
         else  <<x := car v . x;
                 v := cdr v;
                 s := not s>>;
         go to a
   end;

endmodule;


module cofactor;   % Cofactor operator.

% Author: Alan Barnes <barnesa@kirk.aston.ac.uk>.

Comment

Syntax:  COFACTOR(MATRIX:matrix,ROW:integer,COLUMN:integer):algebraic

The cofactor of the element in row ROW and column COLUMN of matrix
MATRIX is returned.  Errors occur if ROW or COLUMN do not simplify to
integer expressions or if MATRIX is not square;

symbolic procedure cofactorq (u,i,j);
   begin integer len;
      len:= length u;
      if not(i>0 and i<len+1)
        then rerror(matrix,20,"Row number out of range");
      if not(j>0 and j<len+1)
       then rerror(matrix,21,"Column number out of range");
       foreach x in u do
         if length x neq len then rerror(matrix,22,"non-square matrix");
      u := remove(u,i);
      clrhash();
      u := detq1(u,len-1,2**(j-1));
      clrhash();
      if remainder(i+j,2)=1 then u := negsq u;
      return u;
  end;

put ('cofactor,'simpfn,'simpcofactor);

symbolic procedure simpcofactor u;
   cofactorq(matsm car u,ieval cadr u,ieval carx(cddr u,'cofactor));

endmodule;


end;
