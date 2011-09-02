module normform; % Package for the computation of several normal forms.
%                                                                      %
% This file contains routines for computation of the following         %
% normal forms of matrices:                                            %
%                                                                      %
%  - smithex_int                                                       %
%  - smithex                                                           %
%  - frobenius                                                         %
%  - ratjordan                                                         %
%  - jordansymbolic                                                    %
%  - jordan                                                            %
%                                                                      %
% The manual for this package is found in the normform.tex file.       %
% It includes descriptions of the various normal forms.                %
%                                                                      %
% Further examples are found in the normform.log file.                 %
%                                                                      %
% For a description of the algorithms see the comments.                %
%                                                                      %
%                                                                      %
% Author: Matt Rebbeck   Nov '93 - Feb '94                             %
%                                                                      %
% This code has been converted from the normform and Normform packages %
% written by T.M.L. Mulders and A.H.M. Levelt for Maple.               %
%                                                                      %
% normform contains one switch: looking_good. If using xr, the X       %
% interface for REDUCE, switching this on will improve the appearance  %
% of the output. The switch serves no (useful) purpose in standard     %
% REDUCE (ie: not using xr).                                           %
%                                                                      %
%**********************************************************************%

create!-package('(normform jordan jordsymb ratjord froben matarg
                  nestdom smithex smithex1),'(contrib normform));

endmodule;


module jordan; % Computation of the Jordan normal form of a matrix.
                                                 %

load!-package 'matrix;  %  Otherwise setmat can fail (letmtr undefined).

load!-package 'arnum; % So we can test whether it's in use or not.

% The following functions may be useful by themselves. They can be     %
% called from algebraic mode: companion, copyinto, deg_sort,           %
% jordanblock, submatrix.                                              %
%                                                                      %

%**********************************************************************%

% jordan(A) computes the Jordan normal form of a square matrix A.
% First jordansymbolic is applied to A, then the symbolic zeroes of the
% characteristic polynomial are replaced by the actual zeroes. The
% zeroes of the characteristic polynomial of A are computed exactly if
% possible. The zeroes which cannot be computed exactly are
% approximated by floating point numbers.

% Specifically:
%
% - jordan(A) will return {J,P,Pinv} where J, P, and Pinv
%   are such that P*J*Pinv = A.
%

% For more details of the algorithm and general workings of jordan
% see jordansymbolic.


symbolic procedure jordan(a);
  begin
    scalar aa,l,tmp,p,pinv,ans,ans_mat,full_coeff_list,rule_list,
           input_mode;

    matrix_input_test(a);
    if (car size_of_matrix(a)) neq (cadr size_of_matrix(a))
     then rederr "ERROR: expecting a square matrix. ";

    input_mode := get(dmode!*,'dname);
    if input_mode = 'modular then rederr
    "ERROR: jordan does not work with modular on. Try jordansymbolic. ";
    %
    % If arnum is on then we keep it on else we want
    % rational on.
    %
    if input_mode neq 'arnum and input_mode neq 'rational
     then on rational;
    on combineexpt;

    tmp := nest_input(a);
    aa := car tmp;
    full_coeff_list := cadr tmp;

    l := jordansymbolicform(aa, full_coeff_list);

    tmp := jordanform(l, full_coeff_list);
    ans := car tmp;
    p := cadr tmp;
    pinv := caddr tmp;
    %
    %  Set up rule list for removing nests.
    %
    rule_list := {'co, 2,{'~, 'int}}=>'int when numberp(int);
    for each elt in full_coeff_list do
    <<
      tmp := {'co, 2, {'~, elt}}=>elt;
      rule_list := append (tmp, rule_list);
    >>;
    %
    %  Remove nests.
    %
    let rule_list;
    ans_mat := de_nest_mat(ans);
    p := de_nest_mat(p);
    pinv := de_nest_mat(pinv);
    clearrules rule_list;
    %
    % Return to original mode.
    %
    if input_mode neq 'arnum and input_mode neq 'rational then
    <<
      % onoff('nil,t) doesn't work so...
      if input_mode = 'nil then off rational
      else onoff(input_mode,t);
    >>;
    off combineexpt;

    return {'list, ans_mat, p, pinv};
  end;

flag ('(jordan),'opfn);  %  So it can be used from algebraic mode.



symbolic procedure jordanform(l, full_coeff_list);
  begin
    scalar jj,z,zeroes,p,pinv,x,tmp,tmp1,de_nest;
    integer n,d;

    p := nth(l,3);
    pinv := nth(l,4);

    n := length nth(nth(l,2),1);
    x := nth (nth(l,2),2);
    jj := nth(l,1);

    for i:=1:n do
    <<
      d := deg(nth(nth(nth(l,2),1),i),x);
      if d>1 then
      <<
        %
        %  Determine zeroes.
        %
        z := nth(nth(nth(l,2),1),i);
        zeroes := {};
        %  de-nest as solve sometimes fails with nests.
        de_nest := de_nest_list(z,full_coeff_list);
        tmp := algebraic solve(de_nest,x);
        tmp := cdr tmp;  %  Remove algebraic 'list.
        for j:=1:length tmp do
        <<
          if test_for_root_of(nth(tmp,j)) then
          <<
            %  If poly is univariate then can solve using roots.
            if length get_coeffs(de_nest) = 1 then
            <<
              on complex;
              tmp1 := algebraic roots(z);
              off complex;
            >>
            else
            <<
              on fullroots;
              prin2t "***** WARNING: fullroots turned on.";
              prin2t "               May take a while.";
              system "sleep 3";
              tmp1 := algebraic solve(de_nest,x);
              off fullroots;
              tmp1 := re_nest_list(tmp1,full_coeff_list);
            >>;
            zeroes := append(zeroes,tmp1);
            zeroes := cdr zeroes;
          >>
         else
          <<
            tmp1 := algebraic solve(z,x);
            tmp1 := cdr tmp1;
            zeroes := append(zeroes,{nth(tmp1,j)});
          >>;
        >>;
        %
        %  Substitute zeroes for symbolic names.
        %
        for j:=1:length zeroes do
        <<
          tmp := nth(zeroes,j);
          tmp := caddr tmp;
          jj := algebraic sub(mkid(x,off_mod_reval{'plus,
                              {'times,10,i},j})=tmp, jj);
        >>;

        for j:=1:length zeroes do
        <<
          tmp := nth(zeroes,j);
          tmp := caddr tmp;
          p := algebraic sub(mkid(x,off_mod_reval{'plus,
                             {'times,10,i},j})=tmp,p);
        >>;

        for j:=1:length zeroes do
        <<
          tmp := nth(zeroes,j);
          tmp := caddr tmp;
          pinv := algebraic sub(mkid(x,off_mod_reval{'plus,
                                {'times,10,i},j})= tmp, pinv);
        >>;
      >>;
    >>;

    return {jj,p,pinv};
  end;




symbolic procedure test_for_root_of(input);
  %
  % Goes through a list testing to see if there is a 'root-of
  % contained within it.
  %
  begin
    scalar tmp,copy_input,boolean,tmp1;

    boolean := nil;
    copy_input := input;

    if atom copy_input then <<>>
    else if car copy_input = 'root_of
     then boolean := t
    else while copy_input and boolean = nil do
    <<
      tmp := copy_input;
      tmp :=  car copy_input;
      if tmp = 'root_of then boolean := t
      else while pairp tmp and boolean = nil do
      <<
        tmp1 := tmp;
        if car tmp1 = 'root_of then boolean := t
        else if atom tmp1 then <<>>
        else while pairp tmp1 and boolean = nil do
        <<
          if car tmp1 = 'root_of then boolean := t
          else tmp1 := car tmp1;
        >>;
        tmp := cdr tmp;
      >>;
      copy_input := cdr copy_input;
    >>;

    return boolean;
  end;

flag ('(test_for_root_of),'boolean);

endmodule;


module jordsymb; % Computation of the Jordan normal form of a matrix.
                                                   %

% The function jordansymbolic computes the Jordan normal form J of a
% matrix A, the transformation matrix P and its inverse P^(-1).
% Here symbolic names are used for the zeroes of the characteristic
% polynomial p not in K. Also a list of irreducible factors of p is
% returned.
%
% Specifically:
%
% - jordansymbolic(A) will return {J,l,P,Pinv} where J, P, and
%   Pinv are such that P*J*Pinv = A. J is calculated with symbolic
%   names if necessary. l is {ll,x} where x is a name and ll
%   is a list of irreducible factors of p(x). If symbolic names are
%   used then xij is a zero of ll(i).

% Global description of the algorithm:
%
% For a given n by n matrix A over a field K, we car compute the
% rational Jordan normal form R of A. Then we compute the Jordan normal
% form of R, which is also the Jordan normal form of A.
% car consider the case where R=C(p), the companion matrix of the
% monic, irreducible polynomial p=x^n+p(n-1)*x^(n-1)+..+p1*x+p0.
% If y is a zero of p then
% (y^(n-1)+p(n-1)*y^(n-2)+..+p2*y+p1,y^(n-2)+p(n-1)*y^(n-3)+..+p3*y+p2,
% ....,y^2+p(n-1)*y+p(n-2),y+p(n-1),1)
% is an eigenvector of R with eigenvalue y.
%
% Let v1     = x^(n-1)+p(n-1)*x^(n-2)+..+p2*x+p1,
%     v2     = x^(n-2)+p(n-1)*x^(n-3)+..+p3*x+p2,
%     ...
%     v(n-2) = x^2+P(n-1)*x+p(n-2),
%     v(n-1) = x+p(n-1),
%     vn     = 1.
%
% If y1,..,yn are the different zeroes of p in a splitting field of p
% over K (we asssume that p is separable, this is always true if K is a
% perfect field) we get:
%
%       inverse(V)*R*V=diag(y1,..,yn),
%
% where
%
%          [ v1(y1) v1(y2) ... v1(yn) ]
%          [ v2(y1) v2(y2) ... v2(yn) ]
%      V = [  ...    ...   ...  ...   ]
%          [  ...    ...   ...  ...   ]
%          [ vn(y1) vn(y2) ... vn(yn) ]
%
%
% One can prove that
%
%      [1 y1 ... y1^(n-1)] [v1(y1) v1(y2) ... v1(yn)]
%      [1 y2 ... y2^(n-1)] [v2(y1) v2(y2) ... v2(yn)]
%      [.................] [........................] =
%      [.................] [........................]
%      [1 yn ... yn^(n-1)] [vn(y1) vn(y2) ... vn(yn)]
%
%    = diag(diff(p,x)(y1),diff(p,x)(y2),...,diff(p,x)(yn)).
%
% If s and t are such that s*p+t*diff(p,x)=1 then we get
%
%                                           [1 y1 ... y1^(n-1) ]
%                                           [1 y2 ... y2^(n-1) ]
%    inverse(V)=diag(t(y1),t(y2),...,t(yn))*[................. ]
%                                           [................. ]
%                                           [1 yn ... yn^(n-1) ]
%
% Let Y=diag(y1,..,yn). From V^(-1)*R*V=Y it follows that
%
%                          [C(p)  I             ]
%                          [    C(p)  I         ]
%   diag(V^(-1),..,V^(-1))*[          .   .     ]*diag(V,..,V)=
%                          [            C(p)  I ]
%                          [                C(p)]
%
%          [ Y I       ]
%          [   Y I     ]
%        = [     . .   ]
%          [       Y I ]
%          [         Y ]
%
% It is now easy to see that to get our general result, we only have to
% permute diag(V,..,V) and diag(V^(-1),..,V^(-1)).

% looking_good controls formating output to print the greek character
% xi instead of lambda. At present xr does not support indexing of
% lambda but it does for all other greek letters, which is the reason
% for this switch.
%
% Only  helpful when using xr.

switch looking_good;


switch balanced_was_on;
symbolic procedure jordansymbolic(a);
  begin
    scalar aa,p,pinv,tmp,ans_mat,ans_list,full_coeff_list,rule_list,
           output,input_mode;

    matrix_input_test(a);
    if (car size_of_matrix(a)) neq (cadr size_of_matrix(a))
     then rederr "ERROR: expecting a square matrix. ";

    if !*balanced_mod then
    <<
      off balanced_mod;
      on balanced_was_on;
    >>;

    input_mode := get(dmode!*,'dname);
    %
    % If modular or arnum are on then we keep them on else we want
    % rational on.
    %
    if input_mode neq 'modular and input_mode neq 'arnum and
     input_mode neq 'rational then on rational;
    on combineexpt;

    tmp := nest_input(a);
    aa := car tmp;
    full_coeff_list := cadr tmp;

    tmp := jordansymbolicform(aa,full_coeff_list);
    ans_mat := car tmp;
    ans_list := cadr tmp;
    p := caddr tmp;
    pinv := caddr rest tmp;
    %
    %  Set up rule list for removing nests.
    %
    rule_list := {'co,2,{'~,'int}}=>'int when numberp(int);
    for each elt in full_coeff_list do
    <<
      tmp := {'co,2,{'~,elt}}=>elt;
      rule_list := append (tmp,rule_list);
    >>;
    %
    % Remove nests.
    %
    let rule_list;
    ans_mat := de_nest_mat(ans_mat);
    car ans_list := append({'list},car ans_list);
    ans_list := append({'list},ans_list);
    cadr ans_list := for each elt in cadr ans_list collect reval elt;
    p := de_nest_mat(p);
    pinv := de_nest_mat(pinv);
    clearrules rule_list;
    %
    % Return to original mode.
    %
    if input_mode neq 'modular and input_mode neq 'arnum and
     input_mode neq 'rational then
       <<
         % onoff('nil,t) doesn't work so ...
         if input_mode = 'nil then off rational
         else onoff(input_mode,t);
       >>;
    if !*balanced_was_on then on balanced_mod;
    off combineexpt;

    output := {'list,ans_mat,ans_list,p,pinv};
    if !*looking_good then output := looking_good(output);
    return output;
  end;

flag ('(jordansymbolic),'opfn);  %  So it can be used from
                                 %  algebraic mode.



symbolic procedure jordansymbolicform(a,full_coeff_list);
  begin
    scalar l,r,tt,tinv,s,sinv,tmp,p,pinv,invariant;

    tmp := ratjordanform(a,full_coeff_list);
    r := car tmp;
    tt := cadr tmp;
    tinv := caddr tmp;

    tmp := ratjordan_to_jordan(r);
    l := car tmp;
    s := cadr tmp;
    sinv := caddr tmp;

    p := off_mod_reval {'times,tt,s};
    pinv := off_mod_reval {'times,sinv,tinv};

    invariant := invariant_to_jordan(nth(l,1));

    return {invariant,nth(l,2),p,pinv};
  end;




symbolic procedure find_companion(r,rr,x);
  begin
    scalar  p;
    integer row_dim,k;

    row_dim := car size_of_matrix(r);
    k := rr+1;

    while k<=row_dim and getmat(r,k,k-1)=1 do k:=k+1;

    p := 0;
    for j:=rr:k-1 do
    <<
      p:={'plus,p,{'times,{'minus,getmat(r,j,k-1)},{'expt,x,j-rr}}};
    >>;
    p := {'plus,p,{'expt,x,k-rr}};

    return p;
  end;




symbolic procedure find_ratjblock(r,rr,x);
  begin
    scalar p,continue;
    integer k,e,row_dim;

    row_dim := car size_of_matrix(r);
    p := reval find_companion(r,rr,x);
    e := 1;
    k:= off_mod_reval({'plus,rr,deg(p,x)});

    continue := t;
    while continue do
    <<
      if k>row_dim then continue := nil;
      if identitymatrix(r,k-deg(p,x),k,deg(p,x)) then
      <<
        e:=e+1;
        k:=k+deg(p,x);
      >>
      else
      <<
        continue := nil;
      >>;
    >>;

    return({p,e});
  end;




symbolic procedure identitymatrix(a,i,j,m);
  %
  % Tests if the submatrix of A, starting at position (i,j) and of
  % square size m, is an identity matrix.
  %
  begin
    integer row_dim;

    row_dim := car size_of_matrix(a);
    if i+m-1>row_dim or j+m-1>row_dim then return nil
    else
    <<
      if submatrix(a,{i,i+m-1},{j,j+m-1}) = make_identity(m,m) then
         return t
      else return nil;
    >>;
  end;

flag ('(identitymatrix),'boolean);



symbolic procedure invariant_to_jordan(invariant);
  begin
    scalar block_list;
    integer n,m;

    n := length invariant;
    block_list := {};

    for i:=1:n do
    <<
      m := length nth(nth(invariant,i),2);
      for j:=1:m do
      <<
        block_list := append(block_list,
                      {jordanblock(nth(nth(invariant,i),1),
                      nth(nth(nth(invariant,i),2),j))});
      >>;
    >>;
    return (reval {'diagi,block_list});
  end;




symbolic procedure jordanblock(const,mat_dim);
  %
  % Takes a constant (const) and an integer (mat_dim) and creates
  % a jordan block of dimension mat_dim x mat_dim.
  %
  % Can be used independently from algebraic mode.
  %
  begin
    scalar jb;

    jb := mkmatrix(mat_dim,mat_dim);
    for i:=1:mat_dim do
    <<
      for j:=1:mat_dim do
      <<
        if i=j then
        <<
          setmat(jb,i,j,const);
          if i<mat_dim then setmat(jb,i,j+1,1);
        >>;
      >>;
    >>;

    return jb;
  end;

flag ('(jordanblock),'opfn); %  So it can be used independently
                             %  from algebraic mode.



switch mod_was_on;
symbolic procedure ratjordan_to_jordan(r);
  begin
    scalar prim_inv,tt,tinv,tinvlist,tlist,exp_list,invariant,p,partt,
           parttinv,s1,t1,v,w,sum1,tmp,s,sinv,x;
    integer nn,n,d;
    %
    % lambda would be better but as yet reduce can't output lambda with
    % indices (under discussion), so we use xi. If it is decided that
    % lambda can be used with indices then change xi to lambda both
    % here and in the functions looking_good and make_rule.
    %
    if !*looking_good then x := 'xi
    else x := 'lambda;

    prim_inv := ratjordan_to_priminv(r,x);

    invariant := {};
    tlist := {};
    tinvlist := {};

    nn := length prim_inv;
    for i:=1:nn do
    <<
      p := nth(nth(prim_inv,i),1);
      exp_list := nth(nth(prim_inv,i),2);
      d := off_mod_reval(deg(p,x));
      if d=1 then
      <<
        invariant := append(invariant,{{reval {'minus,coeffn(p,x,0)},
                            exp_list}});
      >>
      else
      <<
        for j:=1:d do
        <<
          invariant := append(invariant,{{mkid(x,off_mod_reval{'plus,
                              {'times,10,i},j}),exp_list}});
        >>;
      >>;
      %
      % Compute eigenvector of C(p) with eigenvalue x.
      %
      v := mkvect(d);
      putv(v,d,1);
      for j:=d-1 step -1 until 1 do
      <<
        tmp := 0;
        sum1 := 0;
        for k:=j:d-1 do
        <<
          tmp := reval{'times,coeffn(p,x,k),{'expt,x,k-j}};
          sum1 := reval{'plus,sum1,tmp};
        >>;
        putv(v,j,reval {'plus,sum1,{'expt,x,d-j}});
      >>;

      sum1 := 0;
      for j:=1:length exp_list do
      <<
        tmp := reval nth(exp_list,j);
        sum1 := reval {'plus,sum1,tmp};
      >>;
      n := sum1;

      partt := mkmatrix(n*d,n);
      for j:=1:n do
      <<
        for k:=1:d do
        <<
          setmat(partt,(j-1)*d+k,j,getv(v,k));
        >>;
      >>;

      tt := mkmatrix(n*d,n*d);
      if d=1 then
      <<
        %
        % off modular else the mkid number part will be calculated
        % in modular mode.
        %
        if !*modular then << off modular; on mod_was_on; >>;
        tt := copyinto(algebraic (sub({x=-coeffn(p,x,0)},partt)),
                       tt,1,1);
        if !*mod_was_on then << on modular; off mod_was_on; >>;
      >>
      else for j:=1:d do
      <<
        %
        % off modular else the mkid number part will be calculated
        % in modular mode.
        %
        if !*modular then << off modular; on mod_was_on; >>;
        tt := copyinto(algebraic sub(x=mkid(x,off_mod_reval{'plus,
                       {'times,10,i},j}),partt),tt,1,(j-1)*n+1);
        if !*mod_was_on then << on modular; off mod_was_on; >>;
      >>;
      tlist := append(tlist,{tt});

      tmp := algebraic df(p,x);
      tmp := calc_exgcd(p,tmp,x);
      s1 := cadr tmp;
      t1 := caddr tmp;
      w := mkvect(d);
      putv(w,1,t1);

      for j:=2:d do
      <<
        putv(w,j,get_rem(reval{'times,x,getv(w,j-1)},p));
      >>;

      parttinv := mkmatrix(n,n*d);
      for j:=1:n do
      <<
        for k:=1:d do
        <<
          setmat(parttinv,j,(j-1)*d+k,getv(w,k));
        >>;
      >>;

      tinv := mkmatrix(n*d,n*d);
      if d=1 then
      <<
        %
        % off modular else the mkid number part will be calculated
        % in modular mode.
        %
        if !*modular then << off modular; on mod_was_on; >>;
        tinv := reval copyinto(algebraic sub(x=-coeffn(p,x,0),parttinv)
                               ,tinv,1,1);
        if !*mod_was_on then << on modular; off mod_was_on; >>;
      >>
      else for j:=1:d do
      <<
        %
        % off modular else the mkid number part will be calculated
        % in modular mode.
        %
        if !*modular then << off modular;  on mod_was_on; >>;
        tinv := reval copyinto(algebraic sub(x=mkid(x,off_mod_reval
                {'plus,{'times,10,i},j}),parttinv),tinv,(j-1)*n+1,1);
        if !*mod_was_on then << on modular; off mod_was_on; >>;
      >>;
      tinvlist := append(tinvlist,{tinv});

    >>;

    s := reval{'diagi,tlist};
    sinv := reval{'diagi,tinvlist};
    tmp := {for i:=1:nn collect nth(nth(prim_inv ,i),1)};
    tmp := append(tmp,{x});
    tmp := append({invariant},{tmp});

    return {tmp,s,sinv};
  end;




symbolic procedure ratjordan_to_priminv(r,x);
  %
  % ratjordan_to_priminv(R,x) computes the primary invariant of a matrix
  % R which is in rational Jordan normal form.
  %
  begin
    scalar p,plist,exp_list,l,prim_inv;
    integer n,rr,ii,nn;

    n := car size_of_matrix(r);
    rr := 1;

    plist := {};
    while rr<=n do
    <<
      l := find_ratjblock(r,rr,x);
      plist := append(plist,{l});
      rr := off_mod_reval({'plus,rr,{'times,nth(l,2),deg(nth(l,1),x)}});
    >>;

    p := reval nth(nth(plist,1),1);
    exp_list := {nth(nth(plist,1),2)};
    prim_inv := {};
    nn := length plist;
    ii := 2;
    while ii<=nn do
    <<
      if reval nth(nth(plist,ii),1) = p then
      <<
        exp_list := append(exp_list,{nth(nth(plist,ii),2)})
      >>
      else
      <<
        prim_inv := append(prim_inv,{{p,exp_list}});
        p := reval nth(nth(plist,ii),1);
        exp_list := {nth(nth(plist,ii),2)};
      >>;
      ii := ii+1;
    >>;
    prim_inv := append(prim_inv,{{p,exp_list}});

    return prim_inv;
  end;




symbolic procedure submatrix(a,row_list,col_list);
  %
  % Creates the submatrix of A from rows  p to q (row_list = {p,q})
  % and columns r to s (col_list = {r,s}).
  %
  % Can be used independently from algebraic mode.
  %
  begin
    scalar aa;
    integer row_dim,col_dim,car_row,last_row,car_col,last_col,
            a_row_dim,a_col_dim;

    matrix_input_test(a);

    %  If algebraic input remove 'list.
    if car row_list = 'list then row_list := cdr row_list;
    if car col_list = 'list then col_list := cdr col_list;

    car_row := car row_list;
    last_row := cadr row_list;
    row_dim := last_row - car_row + 1;
    car_col := car col_list;
    last_col := cadr col_list;
    col_dim := last_col - car_col + 1;

    a_row_dim := car size_of_matrix(a);
    a_col_dim := cadr size_of_matrix(a);
    if car_row = 0 or last_row = 0 then rederr
     {"0 is out of range for ",a,". The car row is labelled 1."};
    if car_col = 0 or last_col = 0 then rederr
     {"0 is out of range for",a,". The car column is labelled 1."};
    if car_row > a_row_dim then rederr
     {a,"doesn't have",car_row,"rows."};
    if last_row > a_row_dim then rederr
     {a,"doesn't have",last_row,"rows."};
    if car_col > a_col_dim then rederr
     {a,"doesn't have",car_col,"columns."};
    if last_col > a_col_dim then rederr
     {a,"doesn't have",last_col,"columns."};

    aa := mkmatrix(row_dim,col_dim);
    for i:=1:row_dim do
    <<
      for j:=1:col_dim do
      <<
        setmat(aa,i,j,getmat(a,i+car_row-1,j+car_col-1));
      >>;
    >>;

    return aa;
  end;

flag ('(submatrix),'opfn);  %  So it can be used independently
                            %  from algebraic mode.



symbolic procedure looking_good(output);
  %
  % Converts output for correct display of indices with greek
  % font. Only used when switch looking_good is on, which is only on
  % when using xr.
  %
  % xiab => xi(a,b) is used instead of xiab => xi(ab) to reduce problems
  % when using modular arithmetic. In mod 17 (for example) xi(21) will
  % get converted to xi(2,1) but the alternative would give xi(4) -
  % wrong! Unfortunately the alternative probably looks a bit nicer but
  % there you go. If the modulus is <= 7 then this may give problems,
  % eg: xi55 in mod 5 will give xi(0,0). These cases will be very rare
  % but if they occur turn OFF looking_good.
  %
  begin
    scalar rule_list;

    algebraic operator xi;
    algebraic print_indexed(xi);
    %
    % Create rule list to convert xiab => xi(a,b) for a,b:=1:9.
    %
    rule_list := make_rule();

    let rule_list;
    output := reval output;
    clearrules rule_list;

    return output;
  end;




symbolic procedure make_rule();
  begin
    scalar rule_list,tmp,tmp1;

    rule_list := {};
    for i:=1:9 do
      <<
        for j:=1:9 do
        <<
          tmp1 := reval mkid('xi,i);
          tmp1 := reval mkid(tmp1,j);
          tmp := {'replaceby,tmp1,{'xi,i,j}};
          rule_list := append(rule_list,{tmp});
        >>;
      >>;
      rule_list := append({'list},rule_list);
      return rule_list;
  end;

endmodule;


module ratjord; %Computation of rational Jordan normal form of a matrix.

% The function ratjordan computes the rational Jordan normal form R of
% a matrix A, the transformation matrix P and its inverse P^(-1).
%
% Specifically:
%
% - ratjordan(A) will return {R,P,Pinv} where R, P, and Pinv
%   are such that P*R*Pinv = A.

% Global description of the algorithm:
%
% For a given n by n matrix A over a field K, we first compute the
% Frobenius normal form F of A. Then we compute the rational Jordan
% normal form of F, which is also the rational Jordan normal form of A.
% If F=diag(C1,..,Cr), where Ci is the companion matrix associated with
% a polynomial pi in K[x], we first compute the rational Jordan normal
% form of C1 to Cr. From these we then extract the rational Jordan
% normal form of F.

null(load!-package 'specfn);  % To use binomial, but not load during
                              % compilation.

symbolic procedure ratjordan(a);
  begin
    scalar aa,tmp,ans,p,pinv,full_coeff_list,rule_list,input_mode;

    matrix_input_test(a);
    if (car size_of_matrix(a)) neq (cadr size_of_matrix(a))
     then rederr "ERROR: expecting a square matrix. ";

    input_mode := get(dmode!*,'dname);
    %
    % If modular or arnum are on then we keep them on else we want
    % rational on.
    %
    if input_mode neq 'modular and input_mode neq 'arnum and
     input_mode neq 'rational then on rational;
    on combineexpt;

    tmp := nest_input(a);
    aa := car tmp;
    full_coeff_list := cadr tmp;

    tmp := ratjordanform(aa,full_coeff_list);
    ans := car tmp;
    p := cadr tmp;
    pinv := caddr tmp;
    %
    %  Set up rule list for removing nests.
    %
    rule_list := {'co,2,{'~,'int}}=>'int when numberp(int);
    for each elt in full_coeff_list do
    <<
      tmp := {'co,2,{'~,elt}}=>elt;
      rule_list := append (tmp,rule_list);
    >>;
    %
    %  Remove nests.
    %
    let rule_list;
    ans := de_nest_mat(ans);
    p := de_nest_mat(p);
    pinv := de_nest_mat(pinv);
    clearrules rule_list;
    %
    % Return to original mode.
    %
    if input_mode neq 'modular and input_mode neq 'arnum and
     input_mode neq 'rational then
       <<
         % onoff('nil,t) doesn't work so ...
         if input_mode = 'nil then off rational
         else onoff(input_mode,t);
       >>;
    off combineexpt;

    return {'list,ans,p,pinv};
  end;

flag ('(ratjordan),'opfn);  %  So it can be used from
                            %  algebraic mode.



symbolic procedure ratjordanform(a,full_coeff_list);
  begin
    scalar tmp,f,tt,tinv,prim_inv,s,sinv,p,pinv,x;

    x := mkid('x,0);

    tmp := frobeniusform(a);
    f := car tmp;
    tt := cadr tmp;
    tinv := caddr tmp;

    tmp := frobenius_to_ratjordan(f,full_coeff_list,x);
    prim_inv := car tmp;
    s := cadr tmp;
    sinv := caddr tmp;

    p := reval {'times,tt,s};
    pinv := reval {'times,sinv,tinv};

    prim_inv := priminv_to_ratjordan(prim_inv,x);

    return {prim_inv,p,pinv};
  end;




% companion_to_ratjordan computes the rational Jordan normal form of a
% matrix C which is the companion matrix of a polynomial p. Since the
% factors of p are known, the rational Jordan normal form of C is also
% known, so in fact we only have to compute the transition matrix.

% Global description of the algorithm:
%
% car consider the case where p=q^e, q irreducible. Let n=degree(p).
% Then we have the following diagram:
%
%                           ~
%                   K^n <------- K[x]/q^e
%
%                    |               |
%                    |               |
%                    |C              |x
%                    |               |
%                    |               |
%                   \ /             \ /
%                           ~
%                   K^n <------- K[x]/q^e
%
% We look for a K-basis (b1,..,bn) of K[x]/q^e such that we get the
% following diagram:
%
%                       ~                ~
%               K^n <------- K[x]/q^e -------> K^n
%
%                |               |              |
%                |               |              |
%                |C              |x             |ratj(q,e)
%                |               |              |
%                |               |              |
%               \ /             \ /            \ /
%                       ~                ~
%               K^n <------- K[x]/q^e -------> K^n
%
% Let q=x^d+q(d-1)*x^(d-1)+..+q1*x+q0. It follows that b1,..,bn must
% satisfy the following relations:
%
% x*b1      = b2
% x*b2      = b3
% ...
% x*bd      = -q0*b1-q1*b2-..-q(d-1)*bd
% x*b(d+1)  = b(d+2)+b1
% x*b(d+2)  = b(d+3)+b2
% ...
% x*b(2d)   = -q0*b(d+1)-q1*b(d+2)-..-q(d-1)*b(2d)+bd
% x*b(2d+1) = b(2d+2)+b(d+1)
% ...
% x*bn      = -q0*b(n-d+1)-q1*b(n-d+2)-..-q(d-1)*bn+b(n-d)
%
% From this we deduce that b1,b(d+1),b(2d+1),... must satisfy the
% following relations:
%
% q*b1      = 0
% q*b(d+1)  = q'*b1
% q*b(2d+1) = q'*b(d+1)-1/2*q''*b1
% q*b(3d+1) = q'*b(2d+1)-1/2*q''*b(d+1)+1/6*q'''*b1
% q*b(4d+1) = q'*b(3d+1)-1/2*q''*b(2d+1)+1/6*q'''*b(d+1)-1/24*q''''*b1
% ...
%
% where ' stands for taking the derivative with respect to x.
% If we choose b1=q^(e-1) we can compute b2,..,bn from the relations
% above. We assume that K is a perfect field, so q' is not zero. From
% this we see that q^(e-i-1) divides b(id+1) while q^(e-i) does not
% divide b(di+1). In particular we have gcd(b((e-1)i+1),q)=1.
% Notice also the following relations which can be easily proved:
%
% x^i*b1      = b(i+1)
% x^i*b(d+1)  = b(d+i+1)+binomial(i,1)*bi
% x^i*b(2d+1) = b(2d+i+1)+binomial(i,1)*b(d+i)+binomial(i,2)*b(i-1)
% ...
%
% Now the general case where p=q1^e1*q2^e2*..*qr^er. To compose the
% partial results we use the following diagram:
%
%      ~       ~                            ~
% K^n<--K[x]/p-->K[x]/q1^e1 X..X K[x]/qr^er-->K^n1 X......X K^nr
%
%  |       |         |               |          |             |
%  |       |         |               |          |             |
%  |C      |x        |x              |x         |  ratj       | ratj
%  |       |         |               |          |( q1,e1)     |(qr,er)
%  |       |         |               |          |             |
% \ /     \ /       \ /             \ /        \ /           \ /
%
%      ~       ~                            ~
% K^n<--K[x]/p-->K[x]/q1^e1 X..X K[x]/qr^er-->K^n1 X......X K^nr
%
% In order to compose the K_bases of K[x]/q1^e1 through K[x]/qr^er to
% a K-basis of K[x]/p we compute polynomials u1,..,ur such that
% (ui mod qi^ei)=1 and (ui mod qj^ej)=0.


symbolic procedure companion_to_ratjordan(fact_list,f,x);
  begin
    scalar g_list,u_list,bbasis,q1,e,qpower,diffq,part_basis,
           ratj_basis,s,tt,g,rowqinv,pol_lincomb,qq,rr,lincomb,index1,v,
           u,a,tmp,qinv,q,sum1;
    integer r,n,d;

    r := length fact_list;
    n := deg(f,x);

    g_list := for i:=1:r collect reval{'expt,nth(nth(fact_list,i),1),
                                       nth(nth(fact_list,i),2)};

    %%%%%%%%%%%%%%%%%%%
    % Compute u1,..,ur.
    %%%%%%%%%%%%%%%%%%%
    u_list := mkvect(r);
    if r=1 then putv(u_list,1,1)
    else
    <<
      tmp := calc_exgcd(nth(g_list,1),nth(g_list,2),x);
      s := cadr tmp;
      tt := caddr tmp;
      putv(u_list,1,{'times,tt,nth(g_list,2)});
      putv(u_list,2,{'times,s,nth(g_list,1)});
      g := {'times,nth(g_list,1),nth(g_list,2)};
      for i:=3:r do
      <<
        tmp := calc_exgcd(g,nth(g_list,i),x);
        s := cadr tmp;
        tt := caddr tmp;
        for j:=1:i-1 do
        <<
          putv(u_list,j,get_rem({'times,getv(u_list,j),tt,nth(g_list,i)}
               ,f));
        >>;
        putv(u_list,i,{'times,s,g});
        g := {'times,g,nth(g_list,i)};
      >>;
    >>;
    %%%%%%%%%%%%%%%%%%%

    bbasis := {};    %  Basis will contain a K-basis of K[x]/f.
    rowqinv := 0;

    q := mkmatrix(n,n);
    qinv := mkmatrix(n,n);

    for i:=1:r do
    <<
      q1 := nth(nth(fact_list,i),1);
      e := reval nth(nth(fact_list,i),2);
      d := deg(q1,x);

      qpower := mkvect(e+1);
      putv(qpower,1,1);
      for j:=2:e+1 do
      <<
        putv(qpower,j,{'times,q1,getv(qpower,j-1)});
      >>;

      if e>1 then
      <<
        diffq := mkvect(e-1);
        putv(diffq,1,reval algebraic df(q1,x));
        for j:=2:e-1 do
        <<
          tmp := reval getv(diffq,j-1);
          putv(diffq,j,reval algebraic df(tmp,x));
        >>;
      >>;

      %%%%%%%%%%%%%%%%%%%
      % Compute b1,b(d+1),b(2d+1),...
      %%%%%%%%%%%%%%%%%%%
      part_basis := mkvect(e);
      putv(part_basis,1,reval {'expt,q1,e-1});

      for j:=2:e do
      <<
        sum1 := 0;
        for k:=1:j-1 do
        <<
          tmp := reval{'times, reval {'quotient,reval {'expt,-1,k-1},
                       reval{'factorial,k}},reval getv(diffq,k),
                       reval getv(part_basis,j-k)};
          sum1 := reval{'plus,sum1,tmp};
        >>;
        putv(part_basis,j,reval{'quotient,sum1,q1});
      >>;
      %%%%%%%%%%%%%%%%%%%

      %%%%%%%%%%%%%%%%%%%
      % Compute b1,..,bni.
      %%%%%%%%%%%%%%%%%%%
      ratj_basis := mkvect(e*d);
      putv(ratj_basis,1,getv(part_basis,1));

      for k:=2:d do
      <<
        putv(ratj_basis,k,{'times,x,getv(ratj_basis,k-1)});
      >>;

      for j:=2:e do
      <<
        putv(ratj_basis,(j-1)*d+1,getv(part_basis,j));
        for k:=2:d do
        <<
          putv(ratj_basis,(j-1)*d+k,{'plus,{'times,x,getv(ratj_basis,
               (j-1)*d+k-1)},{'minus,getv(ratj_basis,(j-2)*d+k-1)}});
        >>;
      >>;

      %%%%%%%%%%%%%%%%%%%

      %%%%%%%%%%%%%%%%%%%
      % Complete basis.
      %%%%%%%%%%%%%%%%%%%
      for k:=1:e*d do
      <<
        tt := get_rem({'times,getv(u_list,i),getv(ratj_basis,k)},f);
        bbasis := append(bbasis,{tt});
      >>;
      %%%%%%%%%%%%%%%%%%%

      %%%%%%%%%%%%%%%%%%%
      % Compute next e*d rows of Qinv (see diagram above).
      %%%%%%%%%%%%%%%%%%%

      %%%%%%%%%%%%%%%%%%%
      % Compute coordinates of 1 with respect to basis (b1,..,bn).
      % Use fact that q1^(e-i-1) divides b(id+1) and gcd(b((e-1)d+1),q1)
      %  = 1
      %%%%%%%%%%%%%%%%%%%
      pol_lincomb := mkvect(e);
      for j:=1:e do putv(pol_lincomb,j,0);
      tmp := calc_exgcd(getv(part_basis,e),getv(qpower,e+1),x); % =1
      s := cadr tmp;
      tt := caddr tmp;
      putv(pol_lincomb,e,s);

      for j:=e step -1 until 1 do
      <<
        qq := get_quo(getv(pol_lincomb,j),q1);
        rr := get_rem(getv(pol_lincomb,j),q1);
        putv(pol_lincomb,j,rr);

        for k:=1:j-1 do
        <<
          putv(pol_lincomb,j-k,get_rem({'plus,getv(pol_lincomb,j-k),
               {'times,qq,getv(diffq,k),{'expt,-1,{'quotient,k,
               {'factorial,k}}}}},getv(qpower,j+1)));
        >>;

      >>;

      lincomb := mkvect(e*d);
      for j:=1:e do
      <<
        for k:=1:d do
        <<
          index1 := (j-1)*d+k;
          putv(lincomb,index1,coeffn(getv(pol_lincomb,j),x,k-1));

          for v:=1:min(j-1,k-1) do
          <<
            putv(lincomb,index1-v*d-v,reval{'plus,getv(lincomb,
                 index1-v*d-v),{'times,coeffn(getv(pol_lincomb,j),x,k-1)
                 ,binomial(k-1,v)}});
          >>;

        >>;
      >>;

      for u:=1:e*d do
      <<
        rowqinv:=rowqinv+1;
        setmat(qinv,rowqinv,1,getv(lincomb,u));
      >>;
      %%%%%%%%%%%%%%%%%%%

      %%%%%%%%%%%%%%%%%%%
      % Compute coordinates of x^v with respect to basis (b1,..,bn).
      %%%%%%%%%%%%%%%%%%%
      for v:=2:n do
      <<
        %
        % a := copy(lincomb).
        %
        a := mkvect(upbv lincomb);
        for i:=1:upbv lincomb do
        <<
          putv(a,i,getv(lincomb,i));
        >>;

        index1 := 0;
        for j:=1:e-1 do
        <<
          index1 := index1 + 1;
          putv(lincomb,index1,reval{'plus,{'times,
               {'minus,coeffn(q1,x,0)},getv(a,j*d)},getv(a,j*d+1)});

          for k:=2:d do
          <<
            index1 := index1+1;
            putv(lincomb,index1,reval{'plus,{'plus,getv(a,(j-1)*d+k-1),
                 {'times,{'minus,coeffn(q1,x,k-1)},getv(a,j*d)},
                 getv(a,j*d+k)}});
          >>;

        >>;

        index1 := index1 + 1;
        putv(lincomb,index1,reval{'times,{'minus,coeffn(q1,x,0)},
             reval getv(a,e*d)});

        for k:=2:d do
        <<
          index1 := index1 + 1;
          putv(lincomb,index1,reval{'plus,getv(a,(e-1)*d+k-1),{'times,
               {'minus,coeffn(q1,x,k-1)},getv(a,e*d)}});
        >>;

        rowqinv := rowqinv-e*d;
        for u:=1:e*d do
        <<
          rowqinv := rowqinv +1;
          setmat(qinv,rowqinv,v,getv(lincomb,u));
        >>;

      >>;
      %%%%%%%%%%%%%%%%%%%

      %%%%%%%%%%%%%%%%%%%
    >>;

    %%%%%%%%%%%%%%%%%%%
    % Compute Q (see diagram above).
    %%%%%%%%%%%%%%%%%%%
    for j:=1:n do
    <<
      for k:=1:n do
      <<
        setmat(q,k,j,coeffn(nth(bbasis,j),x,k-1));
      >>;
    >>;
    %%%%%%%%%%%%%%%%%%%

    return {q,qinv};
  end;




symbolic procedure convert_to_mult(faclist,x);
  %
  % This function takes as input a list of factors from factorize
  % and converts it to a list as follows: {{fac,mult},{fac,mult}...},
  % where mult is the multiplicity of that factorial.
  %
  % No need to deal with cases such as {x,x,x,x+1,x+1,x,x,x,x+1}
  % (for example) as factorize groups factorials together.
  %
  % Note that {x,-x} will give {{x,2}}.
  %
  % The factorials are normalised w.r.t. x. ie: 5*x^2 -> x^2.
  % NB: This does not normalise multivariate polynomials as completely
  %     as the maple "factors" does. This may cause a bug in the matrix
  %     normforms but all cases tried so far seem to work.
  %
  begin
    scalar multlist,z;
    integer mult1;

    faclist := cdr faclist; % Remove 'list that is added by factorize.

    %  Remove non polynomial (integer) factor if it's there.
    if numberp car faclist then faclist := cdr faclist;

    multlist := {};

    for i:=2:length faclist+1 do
    <<
      mult1 := 1;

      % While we're in faclist and abs value of adjacent elt's is equal.
      while i<= length faclist and numberp(z := reval {'quotient,
            nth(faclist,i-1),nth(faclist,i)}) and abs z = 1 do
      <<
        mult1 := mult1+1;
        i := i+1;
      >>;
      %
      %  Normalise list so that lcof of each elt wrt x is +1.
      %  NB: no need to consider case where lcof(int,x) gives 0 as
      %  faclist will never contain integers.
      %
      if numberp off_mod_lcof(nth(faclist,i-1),x) and
         off_mod_lcof(nth(faclist,i-1),x) neq 0 then
      <<
          multlist := append(multlist,{{reval {'quotient,
                             nth(faclist,i-1),off_mod_lcof
                             (nth(faclist,i-1),x)},mult1}});
      >>
      % Make -elt -> elt.
      else if car nth(faclist,i-1) = 'minus then
      <<
        multlist := append(multlist,{{cadr nth(faclist,i-1),mult1}});
      >>
      else multlist := append(multlist,{{nth(faclist,i-1),mult1}});

    >>;

    return multlist;
  end;




symbolic procedure copyinto(bb,aa,p,q);
  %
  % Copies matrix BB into AA with BB(1,1) at AA(p,q).
  % Returns newly formed matrix A.
  %
  % Can be used independently from algebraic mode.
  %
  begin
    scalar a,b;
    integer m,n,r,c;

    matrix_input_test(aa);
    matrix_input_test(bb);

    if p = 0 or q = 0 then
     rederr "     0 is out of bounds for matrices.
     The top left element is laballed (1,1) and not (0,0).";

    m := car size_of_matrix(aa);
    n := cadr size_of_matrix(aa);
    r := car size_of_matrix(bb);
    c := cadr size_of_matrix(bb);

    if r+p-1>m or c+q-1>n then rederr
     {"The matrix",bb,"does not fit into",aa,"at position",p,q,"."};

    a := mkmatrix(m,n);
    b := mkmatrix(r,c);

    for i:=1:m do
    <<
      for j:=1:n do
      <<
        setmat(a,i,j,getmat(aa,i,j));
      >>;
    >>;

    for i:=1:r do
    <<
      for j:=1:c do
      <<
        setmat(b,i,j,getmat(bb,i,j));
      >>;
    >>;

    for i:=1:r do
    <<
      for j:=1:c do
      <<
        setmat(a,p+i-1,q+j-1,getmat(b,i,j));
      >>;
    >>;

    return a;
  end;

flag ('(copyinto),'opfn);  %  So it can be used independently
                           %  from algebraic mode.



symbolic procedure de_nest_list(input,full_coeff_list);
  %
  % Takes as input a list of nested polys and de-nests them all.
  %
  begin
    scalar tmp,copy,rule_list;

    if full_coeff_list = nil then copy := input
    else
    <<
      copy := input;
      %
      %  Set up rule list for removing nests.
      %
      rule_list := {'co,2,{'~,'int}}=>'int when numberp(int);
      for each elt in full_coeff_list do
      <<
        tmp := {'co,2,{'~,elt}}=>elt;
        rule_list := append (tmp,rule_list);
      >>;
      %
      %  Remove nests.
      %
      let rule_list;
      if atom copy then copy := reval copy
      else copy := for each elt in copy collect reval elt;
      clearrules rule_list;
    >>;

    return copy;
  end;




symbolic procedure deg_sort(l,x);
  %
  % Takes a list of polys and sorts them into increasing order.
  %
  % Has been written so that it can also be run independently
  % from algebraic mode.
  %
  begin
    scalar ll,alg;
    integer n;
    %
    %  If input from algebraic mode then car is 'list. In the normal
    %  forms, l in entered without the 'list.
    %
    if car l = 'list then
    <<
      ll := cdr l;
      alg := t;
    >>
    else ll := l;

    %  Get no of elts.
    n := length ll;

    for i:=1:n-1 do
    <<
      for j:=i+1:n do
      <<
        if deg(nth(ll,j),x) < deg(nth(ll,i),x) then
        <<
          ll := append(append(append(for k:=1:i-1 collect nth(ll,k),
                       {nth(ll,j)}),for k:=i:j-1 collect nth(ll,k)),
                       for k:=j+1:n collect nth(ll,k));
        >>;
      >>;
    >>;

    %  If input from algebraic mode then make output algebraic
    %  compatible.
    if alg then ll := append({'list},ll);

    return ll;
  end;

flag ('(deg_sort),'opfn);  %  So it can be used independently from
                           %  algebraic mode.



symbolic procedure frobenius_to_invfact(f,x);
  %
  % For a matrix F in Frobenius normal form, frobenius_to_invfact(F,x)
  % computes inv_fact := {p1,..,pr} such that
  % F=invfact_to_frobenius(plist,x).
  %
  begin
    scalar p,inv_fact;
    integer row_dim,m,k;

    row_dim := car size_of_matrix(f);
    inv_fact := {};
    k := 1;

    while k<=row_dim do
    <<
      p := 0;
      m := k+1;
      while m<=row_dim and getmat(f,m,m-1)=1 do m:=m+1;
      for j:=k:m-1 do
      <<
        p := reval{'plus,p,{'times,{'minus,getmat(f,j,m-1)},
                   {'expt,x,j-k}}};
      >>;
      p := reval{'plus,p,{'expt,x,m-k}};
      inv_fact := append(inv_fact,{p});
      k := m;
    >>;

    return inv_fact;
  end;




symbolic procedure frobenius_to_ratjordan(f,full_coeff_list,x);
  %
  % frobenius_to_ratjordan computes the rational Jordan form R of a
  % matrix F which is in Frobenius normal form. Say F=diag(C1,..,Cr),
  % where Ci is the companion matrix associated with the polynomial pi.
  % first we determine the irreducible factors p1,..,pN which appear
  % in p1 through pr and build a matrix fact_mat such that pi=
  % product(Pj^fact_mat(i,j),j=1..N). This matrix is used a several
  % places in the algorithm.
  % In fact we can immediately extract from fact_mat the rational
  % Jordan normal of F. We compute the transformation matrix by
  % rearranging the former results.
  % If R is the matrix in rational Jordan normalform corresponding to
  % prim_inv:=[[q1,[e11,e12,...]],[q2,[e21,e22,...]],....], then
  % prim_inv is returned by frobenius_to_ratjordan.
  %
  begin
    scalar inv_fact,gg,l,m,h,p,fact_mat,g,ii,pp,ff,j,t_list,tinv_list,
           facts,tmp,q,qinv,degp,d,tt,s,cols,count,tinv,sinv,exp_list,
           prim_inv,nn,prod;
    integer r,n;

    %  Compute p1,..,pr.
    inv_fact := frobenius_to_invfact(f,x);
    r := length inv_fact;

    %%%%%%%%%%%%%%%%%%%
    % Compute fact_mat
    %%%%%%%%%%%%%%%%%%%
    gg := append({nth(inv_fact,1)},for i:=2:r collect
    get_quo(nth(inv_fact,i),nth(inv_fact,i-1)));

    l := {};
    for i:=1:r do
    <<

      % the problem is that den co(2,?) gives 1 and not ? so we
      % have to de_nest it first (then use co(2,m) later).
      prod := 1;
      for j:=0:deg(nth(gg,i),x) do
      <<
        %
        %  In the following code we take the denominator of a
        %  polynomial.
        %  There are two problems:
        %  1) den co(2,?) gives 1 and not ?.
        %  2) with rational on den(1/3) = 1 (we require 3).
        %  To solve problem 1 we de_nest the polynomial.
        %  To solve problem 2 the easy solution would be to turn
        %  rational off. Unfortunately arnum may be on so we can't do
        %  this. Thus we test to see if poly is a number and then a
        %  quotient. If it is we take the den using get_den. If poly is
        %  not a  number then problem 2 does not apply.
        %
        tmp := de_nest(reval coeffn(nth(gg,i),x,j));
        if evalnumberp tmp then
        <<
          if quo_test(tmp) then tmp := get_den(tmp)
          else tmp := 1;
        >>
        %  else coeffn is a poly in which case den will work.
        else
        <<
          tmp := den(tmp);
        >>;
        prod := reval {'times,tmp,prod};
      >>;
      m := prod;

      %  Next lines not necesary but quicker.
      if m = 1 and nth(gg,i) = 1 then h := {}
      else if m = 1 then
      <<
        tmp := de_nest_list(nth(gg,i),full_coeff_list);
        tmp := factorize(tmp);
        tmp := re_nest_list(tmp,full_coeff_list);
        h := (convert_to_mult(tmp,x));
      >>
      else
      <<
        tmp := reval{'times,{'co,2,m},nth(gg,i)};
        tmp := de_nest_list(tmp,full_coeff_list);
        tmp := factorize(tmp);
        tmp := re_nest_list(tmp,full_coeff_list);
        h := (convert_to_mult(tmp,x));
      >>;
      l := append(l,(for j:=1:length h collect {i,{'quotient,
                  nth(nth(h,j),1),off_mod_lcof(nth(nth(h,j),1),x)},
                  nth(nth(h,j),2)}));
    >>;

    p := deg_sort(for i:=1:length l collect nth(nth(l,i),2),x);
    n := length p;
    g := mkmatrix(r,n);
    fact_mat := mkmatrix(r,n);

    for k:=1:length l do
    <<
      ii := nth(nth(l,k),1);
      pp := nth(nth(l,k),2);
      ff := nth(nth(l,k),3);
      j := 1;
      while pp neq nth(p,j) and j<=n do j:=j+1;
      setmat(g,ii,j,ff);
    >>;

    for j:=1:n do setmat(fact_mat,1,j,getmat(g,1,j));
    for i:=2:r do
    <<
      for j:=1:n do
      <<
        setmat(fact_mat,i,j,{'plus,getmat(fact_mat,i-1,j),
               getmat(g,i,j)});
      >>;
    >>;
    %%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%
    % Compute transition matrix for C1 through Cr.
    %%%%%%%%%%%%%%%%%%%
    t_list := {};
    tinv_list := {};
    for i:=1:r do
    <<
      facts := {};

      for j:=1:n do
      <<
        if getmat(fact_mat,i,j) neq 0 then
        <<
          facts := append(for each elt in facts collect elt,
                          {{nth(p,j),getmat(fact_mat,i,j)}});
        >>;
      >>;

      tmp := companion_to_ratjordan(facts,nth(inv_fact,i),x);
      q := car tmp;
      qinv := cadr tmp;
      tinv_list := append(tinv_list,{qinv});
      t_list := append(t_list,{q});
    >>;
    %%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%
    % Compute transition matrix by permuting diag(t_list(1),..,
    % t_list(r)).
    %%%%%%%%%%%%%%%%%%%
    d := mkmatrix(r,n);
    degp := mkvect(r);
    for i:=1:r do
    <<
      for j:=1:n do
      <<
        setmat(d,i,j,{'times,deg(nth(p,j),x),getmat(fact_mat,i,j)});
      >>;
      putv(degp,i,for j:=1:n sum off_mod_reval(getmat(d,i,j)));
    >>;

    cols := {};
    for j:=1:n do
    <<
      for i:=1:r do
      <<
        count := reval{'plus,for k:=1:i-1 sum off_mod_reval
                       (getv(degp,k)),for k:=1:j-1 sum reval
                       getmat(d,i,k)};
        for h:=1:off_mod_reval(getmat(d,i,j)) do
        <<
          cols := append(cols,{reval{'plus,count,h}});
        >>;
      >>;
    >>;

    tt := reval{'diagi,t_list};
    nn := car size_of_matrix(tt);
    s := mkmatrix(nn,nn);
    for i:=1:nn do
    <<
      for j:=1:nn do
      <<
        setmat(s,i,j,getmat(tt,i,nth(cols,j)));
      >>;
    >>;

    tinv := reval{'diagi,tinv_list};
    sinv := mkmatrix(nn,nn);
    for i:=1:nn do
    <<
      for j:=1:nn do
      <<
        setmat(sinv,i,j,getmat(tinv,nth(cols,i),j));
      >>;
    >>;
    %%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%
    % Compute prim_inv.
    %%%%%%%%%%%%%%%%%%%
    prim_inv := {};
    for j:=1:n do
    <<
      exp_list:={};
      for i:=1:r do
      <<
        if getmat(fact_mat,i,j) neq 0
         then exp_list := append(exp_list,{getmat(fact_mat,i,j)});
      >>;
      prim_inv := append(prim_inv,{{nth(p,j),exp_list}});
    >>;
    %%%%%%%%%%%%%%%%%%%

    return {prim_inv,s,sinv};
  end;

symbolic procedure get_den(input);
  %
  % Gets denominator, ignoring sign.
  %
  begin
    scalar denom,copy;
    copy := input;
    if car copy = 'minus then copy := cadr copy;
    denom := caddr copy;
    return denom;
  end;

symbolic procedure make_ratj_block(p,e,x);
  %
  % For a monic polynomial p in x and a positive integer e,
  % make_ratj_block(p,e,x) returns the matrix ratj(p,e).
  %
  begin
    scalar c,j_block;
    integer d,n;

    c := companion(p,x);

    d := deg(p,x);
    e := off_mod_reval(e);
    n := d*e;
    j_block  := mkmatrix(n,n);

    for i:=1:e do
    <<
      j_block := copyinto(c,j_block,(i-1)*d+1,(i-1)*d+1);
    >>;

    for i:=1:n-d do
    <<
      setmat(j_block,i,i+d,1);
    >>;

    return j_block;
  end;




symbolic procedure priminv_to_ratjordan(prim_inv,x);
  %
  % For a primary invariant prim_inv, priminv_to_ratjordan(prim_inv,x)
  % returns the matrix R in rational Jordan normal form corresponding to
  % prim_inv.
  %
  begin
    scalar p,exp_list,block_list;
    integer r;

    r := length prim_inv;
    block_list := {};

    for i:=1:r do
    <<
      p := nth(nth(prim_inv,i),1);
      exp_list := nth(nth(prim_inv,i),2);
      for j:=1:length exp_list do
      <<
        block_list := append(block_list,{make_ratj_block(p,
    nth(exp_list,j),x)});
      >>;
    >>;

    return reval{'diagi,block_list};
  end;




symbolic procedure quo_test(input);
  %
  % Tests for quotient returning t or nil;
  %
  begin
    scalar boolean,copy;
    copy := input;
    if atom copy then <<>> else
    <<
      if car copy = 'minus then copy := cadr copy;
      if car copy := 'quotient then boolean := t else boolean := nil;
    >>;
    return boolean;
  end;




symbolic procedure re_nest_list(input,full_coeff_list);
  %
  % Re_nests the list that has been de_nested.
  %
  begin
    scalar tmp,copy;

    copy := input;

    for each elt in full_coeff_list do
    <<
      tmp := {'co,2,elt};
      copy := algebraic (sub(elt=tmp,copy));
    >>;

    return copy;
  end;

endmodule;


module froben; % Computation of the frobenius normal form of a matrix.
                                                    %

% The function frobenius computes the Frobenius normal form F of a
% matrix A, the transformation matrix P and its inverse P^(-1).
%
% Specifically:
%
% - frobenius(A) will return {F,P,Pinv} where F, P, and Pinv
%   are such that P*F*Pinv=A.

% Global description of the algorithm:
%
% For a given n by n matrix A over a field K, let L be the linear
% transformation of K^n induced by A. A polycyclic basis of K^n with
% respect to L is a basis of the following form:
% v1,L*v1,.,L^(d1-1)*v1,v2,L*v2,.,L^(d2-1)*v2,.,vr,L*vr,., L^(dr-1)*vr
% such that v1,L*v1,..,L^(d1-1)*v1,..,vi,L*vi,..,L^(di-1)*vi,L^di*vi
% are linearly dependent for i=1..r.
% It is easy to see that the matrix B of L with respect to a polycyclic
% basis is of the form plist_to_polycompanion(plist,x), where plist is
% a list of monic elements of K[x] of strictly increasing degree (for
% a description of plist_to_polycompanion see below).
% The computation of a polycyclic basis of K^n and the transformation
% matrix from A to B is performed in the function cyclic_vectors.
% Next we view K^n as a K[x]-module via x*v=B*v. Suppose that
% B=plist_to_polycompanion(plist,x), where plist=[p1,..,pr] and
% degree(pi)=di. Let G be the r by r upper triangular matrix such that
% G(i,j) satisfies:
%  pj=G(1,j)+G(2,j)*x^d1+G(3,j)*x^d2+..+G(j,j)*x^d(j-1),
% where degree(G(j,j))=dj-d(j-1) and degree(G(i,j))<di-d(i-1) (d0=0).
% Let R be the K[x]-submodule of K[x]^r generated by the columns of G.
% Representants for the elements of the quotient module K[x]^r/R are
% the vectors [L1,L2,..,Lr] where degree(Li)<di-d(i-1). By taking the
% coefficients of the Li the quotient module is identified with K^n.
% The multiplication by x on the quotient module is identified with
% the multiplication by B on K^n.
% Next we compute the Smith normal form S of G. Say L*S*R=G. If R' is
% the K[x]-submodule of K[x]^r generated by the columns of S we get
% the following diagram:
%
%            ~                 ~                 ~
%    K^n <------- K[x]^r/R' -------> K[x]^r/R -------> K^n
%                              L
%     |               |                  |              |
%     |               |                  |              |
%     |F              |x                 |x             |B
%     |               |                  |              |
%     |               |                  |              |
%    \ /             \ /                \ /            \ /
%            ~                 ~                 ~
%    K^n <------- K[x]^r/R' -------> K[x]^r/R -------> K^n
%                              L
%
% Here F is in Frobenius normal form and thus it is the Frobenius
% normal form of B (and thus of A). The computation of the Smith
% normal form of G is performed in the function cyclic_to_frobenius.


symbolic procedure frobenius(a);
  begin
    scalar aa,p,pinv,ans,tmp,full_coeff_list,rule_list,input_mode;

    matrix_input_test(a);
    if (car size_of_matrix(a)) neq (cadr size_of_matrix(a))
     then rederr "ERROR: expecting a square matrix. ";

    input_mode := get(dmode!*,'dname);
    %
    % If modular or arnum are on then we keep them on else we want
    % rational on.
    %
    if input_mode neq 'modular and input_mode neq 'arnum and
     input_mode neq 'rational then on rational;
    on combineexpt;

    tmp := nest_input(a);
    aa := car tmp;
    full_coeff_list := cadr tmp;

    tmp := frobeniusform(aa);
    ans := car tmp;
    p := cadr tmp;
    pinv := caddr tmp;
    %
    %  Set up rule list for removing nests.
    %
    rule_list := {'co,2,{'~,'int}}=>'int when numberp(int);
    for each elt in full_coeff_list do
    <<
      tmp := {'co,2,{'~,elt}}=>elt;
      rule_list := append (tmp,rule_list);
    >>;
    %
    %  Remove nests.
    %
    let rule_list;
    ans := de_nest_mat(ans);
    p := de_nest_mat(p);
    pinv := de_nest_mat(pinv);
    clearrules rule_list;
    %
    % Return to original mode.
    %
    if input_mode neq 'modular and input_mode neq 'arnum and
     input_mode neq 'rational then
       <<
         % onoff('nil,t) doesn't work so ...
         if input_mode = 'nil then off rational
         else onoff(input_mode,t);
       >>;
    off combineexpt;

    return {'list,ans,p,pinv};
  end;

flag ('(frobenius),'opfn);  %  So it can be used from algebraic mode.



symbolic procedure frobeniusform(a);
  begin
    scalar ans,plist,tmp,p,pinv,inv_fact,t1,tinv,v,vinv,x;

    x := mkid('x,0);

    tmp := cyclic_vectors(a,x);
    plist := car tmp;
    v := cadr tmp;
    vinv := caddr tmp;

    tmp := cyclic_to_frobenius(plist,x);
    inv_fact := car tmp;
    t1 := cadr tmp;
    tinv := caddr tmp;

    p:= reval {'times,v,t1};
    pinv:= reval {'times,tinv,vinv};

    ans := invfact_to_frobenius(inv_fact,x);

    return {ans,p,pinv};
  end;




symbolic procedure basis(n,i);
  %
  % Basis creates an element of the natural basis of a vector space.
  %
  begin
    scalar vv;
    vv := mkmatrix(1,n);
    setmat(vv,1,i,1);
    return vv;
  end;




symbolic procedure calc_exgcd(poly1,poly2,x);
  %
  % Extended Euclidean algorithm for polynomials.
  % poly1, and poly2 are polynomials in x.
  % Returns gcd, s1, and t1 such that s1 * poly1 + t1 * poly2 = gcd,
  % with degree(s1,x)<degree(poly2,x) and degree(t1,x)<degree(poly1,x).
  %
  begin
    scalar gcd,c,c1,c2,d,d1,d2,q,r,r1,r2,s1,t1;

    if poly1 = 0 and poly2 = 0 then return {0,0,0} else
    <<

      poly1 := reval poly1;
      poly2 := reval poly2;

      c := reval norm(poly1,x);
      d := reval norm(poly2,x);

      c1 := 1;
      d1 := 0;
      c2 := 0;
      d2 := 1;

      while reval d neq 0 do
      <<
        q  := reval get_quo(c,d);
        r  := reval {'plus,c,{'minus,{'times,q,d}}};
        r1 := reval {'plus,c1,{'minus,{'times,q,d1}}};
        r2 := reval {'plus,c2,{'minus,{'times,q,d2}}};
        c  := reval d;
        c1 := reval d1;
        c2 := reval d2;
        d  := reval r;
        d1 := reval r1;
        d2 := reval r2;
      >>;

      gcd := reval norm(c,x);
      s1  := reval{'quotient,c1,{'times,unit(poly1,x),unit(c,x)}};
      t1  := reval{'quotient,c2,{'times,unit(poly2,x),unit(c,x)}};

    return {gcd,s1,t1};
    >>;
  end;



symbolic procedure norm(poly,x);
  begin
    scalar normal;
    if poly = 0 then normal := 0
    else if lcof(poly,x) = 0 then normal := 1
    else normal := reval{'quotient,poly,lcof(poly,x)};
    return normal;
  end;



symbolic procedure unit(poly,x);
  begin
    scalar unit1;
    if poly = 0 then unit1 := 1
    else if lcof(poly,x) = 0 then unit1 := poly
    else unit1 := reval lcof(poly,x);
    return unit1;
  end;




symbolic procedure companion(poly,x);
  %
  % Takes as input a monic univariate polynomial in a variable x.
  % Returns a companion matrix associated with the polynomial poly(x).
  % If C := companion(p,x) and p is a0+a1*x+...+x^n (a univariate monic
  % polynomial), them C(i,n) = -coeff(p,x,i-1), C(i,i-1) = 1 (i=2..n)
  % and C(i,j) = 0 for all other i and j.
  %
  % Can be used independently from algebraic mode.
  %
   begin
    scalar mat1;
    integer n;

    n := deg(poly,x);

    if de_nest(reval coeffn(poly,x,n)) neq 1
     then rederr {"ERROR: polynomial",poly," is not monic."};

    mat1 := mkmatrix(n,n);
    setmat(mat1,1,n,{'minus,coeffn(poly,x,0)});

    for i:=2:n do
    <<
      setmat(mat1,i,i-1,1);
    >>;

    for j:=2:n do
    <<
      setmat(mat1,j,n,{'minus,coeffn(poly,x,j-1)});
    >>;

    return mat1;
  end;

flag('(companion),'opfn);  %  So it can be used independently from
                           %  algebraic mode.



symbolic procedure compute_g(r,dd,plist,x);
  begin
    scalar g,tmp,new_elt;

    g := mkmatrix(r,r);

    for j:=1:r do
    <<
      for i:=1:j-1 do
      <<
        new_elt := 0;
        for k:=getmat(dd,1,i):getmat(dd,1,i+1)-1 do
        <<
          tmp := {'times,coeffn(nth(plist,j),x,k),{'expt,x,{'plus,k,
                  {'minus,getmat(dd,1,i)}}}};
          new_elt := {'plus,new_elt,tmp};
        >>;
        setmat(g,i,j,new_elt);
      >>;

      new_elt := 0;
      for k:=getmat(dd,1,j):getmat(dd,1,j+1) do
      <<
        tmp := {'times,coeffn(nth(plist,j),x,k),{'expt,x,{'plus,k,
                {'minus,getmat(dd,1,j)}}}};
        new_elt := {'plus,new_elt,tmp};
      >>;

      setmat(g,j,j,new_elt);

    >>;

    return g;
  end;




symbolic procedure copy_mat(a);
  %
  % Creates a copy of the input and returns it;
  %
  begin
    scalar c;
    integer row_dim,col_dim;

    matrix_input_test(a);

    row_dim := car size_of_matrix(a);
    col_dim := cadr size_of_matrix(a);

    c := mkmatrix(row_dim,col_dim);

    for i:=1:row_dim do
    <<
      for j:=1:col_dim do
      <<
        setmat(c,i,j,getmat(a,i,j));
      >>;
    >>;

    return c;
  end;




symbolic procedure cyclic_to_frobenius(plist,x);
  %
  % A matrix B=plist_to_polycompanion(plist,x) is transformed to its
  % Frobenius normal form F.
  % If F=diag(C1,..,Cr) where Ci is the companion matrix associated with
  % pi, then cyclic_to_frobenius will return {p1,..,pr}.
  % Let G be the matrix as described before. We compute the Smith normal
  % form S of G. Then S=diag(p1,..,pr), where pi in K[x] such that pi
  % pi divides p(i+1) for i=1..(r-1), and
  % F=invfact_to_frobenius({p1,..,pr},x) is the frobenius normal form of
  % B (for description of invfact_to_frobenius see invfact_to_frobenius)
  % .
  % Remark: to compute the smith normal form of G we car simplify G
  % using the fact that G is upper triangular. Then we use a modified
  % version of smithex.
  begin
    scalar dd,d,us,s,g,c,t1,tinv,inv_fact,l,linv,columnt,rowt,rr,q,
           columntinv,rowtinv,tmp,tmp1;
    integer r,n;

    r := length plist;

    dd := mkmatrix(1,r+1);
    for j:=1:r do
    <<
      setmat(dd,1,j+1,deg(nth(plist,j),x));
    >>;

    n:= getmat(dd,1,r+1);

    %%%%%%%%%%%%%%%%%%%
    % Compute matrix G.
    %%%%%%%%%%%%%%%%%%%
    g:=compute_g(r,dd,plist,x);
    %%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%
    % Compute smith normal form of G.
    %%%%%%%%%%%%%%%%%%%
    tmp := uppersmith(g,x);
    us:=car tmp;
    l := cadr tmp;
    linv := caddr tmp;

    tmp:=mysmith(us,l,linv,x);
    s:=car tmp;
    l := cadr tmp;
    linv := caddr tmp;
    %%%%%%%%%%%%%%%%%%%

    d := mkmatrix(1,r);
    for i:=1:r do
    <<
      setmat(d,1,i,deg(getmat(s,i,i),x));
    >>;

    %%%%%%%%%%%%%%%%%%%
    % Compute transformation matrix.
    %%%%%%%%%%%%%%%%%%%
    c := mkmatrix(1,r);
    t1 := mkmatrix(n,n);
    columnt:=0;

    for i:=1:r do
    <<
      for k:=1:r do
      <<
        setmat(c,1,k,getmat(l,k,i));
      >>;
      for j:=1:getmat(d,1,i) do
      <<
        columnt:=columnt+1;
        for ii:=r step -1 until 1 do
        <<
          q:=get_quo(getmat(c,1,ii),getmat(g,ii,ii));
          rr:=get_rem(getmat(c,1,ii),getmat(g,ii,ii));
          setmat(c,1,ii,rr);
          for jj:=1:(ii-1) do
          <<
            setmat(c,1,jj,reval {'plus,reval getmat(c,1,jj),{'times,
                   {'minus,q},reval getmat(g,jj,ii)}});
          >>;
        >>;
        rowt:=0;
        for ii:=1:r do
        <<
          tmp := reval{'plus,getmat(dd,1,ii+1),{'minus,
                       getmat(dd,1,ii)}};
          for jj:=1:tmp do
          <<
            rowt:=rowt+1;
            tmp1 := coeffn(getmat(c,1,ii),x,jj-1);
            setmat(t1,rowt,columnt,tmp1);
          >>;
        >>;
        for ii:=1:r do setmat(c,1,ii,{'times,getmat(c,1,ii),x});
      >>;
    >>;
    %%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%
    % Compute inverse transformation matrix
    %%%%%%%%%%%%%%%%%%%
    <<
      tinv := mkmatrix(n,n);
      columntinv:=0;

      for i:=1:r do
      <<
        for k:=1:r do setmat(c,1,k,getmat(linv,k,i));
        for j:=1:reval {'plus,getmat(dd,1,i+1),{'minus,
                        getmat(dd,1,i)}} do
        <<
          columntinv:=columntinv+1;
          rowtinv:=0;
          for ii:=1:r do
          <<
            setmat(c,1,ii,get_rem(getmat(c,1,ii),getmat(s,ii,ii)));
            for jj:=1:reval getmat(d,1,ii) do
            <<
              rowtinv:=rowtinv+1;
              setmat(tinv,rowtinv,columntinv,reval
                     coeffn(getmat(c,1,ii),x,jj-1));
            >>;
          >>;
          for ii:=1:r do setmat(c,1,ii,{'times,getmat(c,1,ii),x});
        >>;
      >>;

    >>;
    %%%%%%%%%%%%%%%%%%%

    inv_fact := {};

    for i:=1:r do
    <<
      if getmat(d,1,i)>0 then
      <<
        inv_fact := append(inv_fact,{getmat(s,i,i)});
      >>;
    >>;

    return {inv_fact,t1,tinv};
  end;




symbolic procedure cyclic_vectors(a,x);
  %
  % cyclic_vectors computes a polycyclic basis of K^n with respect to A.
  % If this basis is (b1,..,bn)=
  % (v1,A*v1,..,A^(d1-1)*v1,v2,A*v2,.,A*(d2-1)*v2,..,vr,A*vr,..,A^(dr-1)
  % *vr)  and a1*b1+..+a(d1+..+di)*b(d1+..+di)+A^di*vi=0 we set
  % pi=a1+a2*x+..+a(d1+..+di)*x^(d1+..+di-1)+x^(d1+..di).
  % cyclic_vectors returns {p1,..,pr}.
  % The matrix of A on this basis (b1,..,bn) is
  % plist_to_polycompanion([p1,..,pr],x).
  %
  begin
    scalar v,vinv,plist,u,uinv,s,carrier,lincomb,vv,uu,ss,l,car,c,
           tmp,ans,q,break;
    integer n,r;

    n := car size_of_matrix(a);

    u := mkmatrix(n,n);
    s := mkmatrix(n,n);
    plist := {};
    v := mkmatrix(n,n);
    vinv := mkmatrix(n,n);
    carrier := mkvect(n);
    lincomb := mkvect(n);

    r := 0;  %  No. of elements already computed.

    while r<n do
    <<

      %%%%%%%%%%%%%%%%%%%
      % Start new cycle.
      %%%%%%%%%%%%%%%%%%%
      q := 1;
      while getv(carrier,q) neq nil do q:=q+1;  %  Find car gap.
      vv := basis(n,q);
      %%%%%%%%%%%%%%%%%%%

      break := nil; %  Controls break out of loop.
      while not break do
      <<
        uu := copy_mat(vv);
        for i:=1:n do putv(lincomb,i,0);

        %  Always VV=UU+U*lincomb.
        for i:=1:n do
        <<
          car:= getv(carrier,i);

          if car neq nil and getmat(uu,1,i) neq 0 then
          <<
            c := {'quotient,getmat(uu,1,i),getmat(u,i,car)};
            setmat(uu,1,i,0);

            for j:=i+1:n do
            <<
              tmp := {'times,c,getmat(u,j,car)};
              setmat(uu,1,j,reval {'plus,getmat(uu,1,j),{'minus,{'times,
                     c,getmat(u,j,car)}}});
            >>;

            putv(lincomb,car,c);
          >>;

        >>;

        q := 1;
        while q<=n and reval getmat(uu,1,q)=0 do
        <<
          q:=q+1;
        >>;

        if q<=n then
        <<

          %  New element of basis.
          r:=r+1;
          putv(carrier,q,r); % This basis-element carries coordinates q.

          %  Always U=V*S.
          for j:=q:n do setmat(u,j,r,getmat(uu,1,j));
          for j:=1:n do setmat(v,j,r,getmat(vv,1,j));

          for j:=1:r-1 do
          <<
            tmp:=getv(lincomb,j);
            for l:=j+1:r-1 do tmp:={'plus,tmp,{'times,getmat(s,j,l),
                                    getv(lincomb,l)}};
            setmat(s,j,r,{'minus,tmp});
          >>;
          setmat(s,r,r,1);

          %  Compute A*VV.
          for i:=1:n do
          <<
            tmp:=0;
            for j:=1:n do
            <<
             tmp:=reval{'plus,tmp,reval{'times,reval getmat(a,i,j),
                        reval getmat(vv,1,j)}};
            >>;
            setmat(uu,1,i,tmp);
          >>;

          for i:=1: cadr size_of_matrix(uu) do
          <<
            setmat(vv,1,i,getmat(uu,1,i));
          >>;

        >>
        else
        <<
          break := t;
        >>;

      >>;

      %%%%%%%%%%%%%%%%%%%
      % New cycle found
      %%%%%%%%%%%%%%%%%%%
      ss := mkmatrix(1,r);

      for j:=1:r do
      <<
        tmp:=reval getv(lincomb,j);

        for l:=j+1:r do
        <<
          tmp:=reval{'plus,tmp,{'times,reval getmat(s,j,l),
                     reval getv(lincomb,l)}};
        >>;

        setmat(ss,1,j,tmp);
      >>;

      ans := nil;
      for j:=1:r do
      <<
        tmp := {'times,getmat(ss,1,r+1-j),{'expt,x,r-j}};
        ans := reval{'plus,ans,tmp};
      >>;

      tmp := reval{'plus,{'expt,x,r},{'minus,ans}};
      plist := append(plist,{tmp});
      %%%%%%%%%%%%%%%%%%%

    >>; %  End while r<n.

    uinv := inv(u,carrier);

    for i:=1:n do
    <<
      for j:=1:n do
      <<
        tmp:=0;
        for l:=i:n do
        <<
          tmp:=reval {'plus,tmp,{'times,reval getmat(s,i,l),
                      reval getmat(uinv,l,j)}};
         >>;
        setmat(vinv,i,j,tmp);
      >>;
    >>;

    return {plist,v,vinv};
  end;




symbolic procedure de_nest(input);
  %
  % Takes simple nested input and de-nests it.
  %
  begin
    scalar output;
    if atom input then output := input
    else if car input neq 'co then output := input
    else output := caddr input;
    return output;
  end;




symbolic procedure de_nest_mat(mat1);
  %
  % Removes nests from each elt of input matrix.
  % Rules being applied from outside.
  %
  begin
    integer row_dim,col_dim;

    row_dim := car size_of_matrix(mat1);
    col_dim := cadr size_of_matrix(mat1);

    for i:=1:row_dim do
    <<
      for j:=1:col_dim do
      <<
        setmat(mat1,i,j,getmat(mat1,i,j));
      >>;
    >>;

    return mat1;
  end;




%  Allow variable input.
put('diagi,'psopfn,'diag);
symbolic procedure diag(uu);
  %
  % Takes square or scalar matrix entries and creates a matrix with
  % these matrices on the diagonal.
  %
  begin
    scalar biga,arg,input,u;
    integer nargs,n,aidx,stp,bigsize,smallsize;

    u := car uu;
    input := u;
    bigsize:=0;

    nargs:=length input;
    for i:=1:nargs do
    <<
      arg:=car input;
      % If scalar entry.
      if algebraic length(arg) = 1 then bigsize:=bigsize+1
      else
      <<
        bigsize:=bigsize+car size_of_matrix(arg);
      >>;
      input := cdr input;
    >>;

    biga := mkmatrix(bigsize,bigsize);
    aidx:=1;
    input := u;
    for k:=1:nargs do
    <<
      arg:=car input;
      % If scalar entry.
      if algebraic length(arg) = 1 then
      <<
        setmat(biga,aidx,aidx,arg);
        aidx:=aidx+1;
        input := cdr input;
      >>
      else
      <<
        smallsize:= car size_of_matrix(arg);
        stp:=smallsize+aidx-1;
        for i:=aidx:stp do
        <<
          for j:=aidx:stp do
          <<
            arg:=car input;
            % Find (i-Aidx+1)'th row.
            arg := cdr arg;
            <<
              n:=1;
              while n < (i-aidx+1) do
              <<
                arg := cdr arg;
                n:=n+1;
              >>;
            >>;
            arg := car arg;
            %
            %  Find (j-Aidx+1)'th column elt of i'th row.
            %
            <<
              n:=1;
              while n < (j-aidx+1) do
              <<
                arg := cdr arg;
                n:=n+1;
              >>;
            >>;
            arg := car arg;

            setmat(biga,i,j,arg);
          >>;
        >>;
        aidx := aidx+smallsize;
        input := cdr input;
      >>;
    >>;

    return biga;
  end;





symbolic procedure get_coeffs(poly);
  %
  % Gets all kernels in a poly.
  %
  begin
    scalar ker_list_num,ker_list_den;

    ker_list_num := kernels !*q2f simp reval num poly;
    ker_list_den := kernels !*q2f simp reval den poly;

    ker_list_num := union(ker_list_num,ker_list_den);

    return ker_list_num;
  end;




symbolic procedure get_quo(poly1,poly2);
  %
  % Gets quotient of two polys.
  %
  begin
    scalar quo1,input1,input2;

    if input1 = 0 and input2 = 0 then return 0
    else
    <<
      input1 := reval poly1;
      input2 := reval poly2;
      algebraic (quo1 := (input1-remainder(input1,input2))/input2);
      quo1 := reval quo1;
      return quo1;
    >>;
  end;




symbolic procedure get_rem(poly1,poly2);
  %
  % Gets remainder of two polys.
  %
  begin
    scalar rem1,input1,input2;

    input1 := reval poly1;
    input2 := reval poly2;

    algebraic (rem1 := remainder(input1,input2));
    rem1 := reval rem1;

    return rem1;
  end;




symbolic procedure inv(u,carrier);
  %
  % inv computes the inverse of a permuted upper triangular matrix. The
  % permutation is given by carrier.
  %
  begin
    scalar uinv,tmp;
    integer n;

    n:= car size_of_matrix(u);
    uinv := mkmatrix(n,n);

    for i:=1:n do
    <<

      for j:=1:i-1 do
      <<
        tmp:=0;

        for k:=j:i-1 do
        <<
          tmp := {'plus,tmp,{'times,getmat(u,i,getv(carrier,k)),
                  getmat(uinv,getv(carrier,k),j)}};
        >>;

        setmat(uinv,getv(carrier,i),j,{'quotient,{'minus,tmp},
               getmat(u,i,getv(carrier,i))});
      >>;

      setmat(uinv,getv(carrier,i),i,{'quotient,1,getmat(u,i,
             getv(carrier,i))});
      for j:=i+1:n do setmat(uinv,getv(carrier,i),j,0);
    >>;

    return uinv;
  end;




symbolic procedure invfact_to_frobenius(inv_fact,x);
  %
  % For plist={p1,..,pr] where pi is a monic polynomial in x,
  % invfact_to_frobenius(plist,x) makes a square matrix with diagonal
  % blocks C1,..,Cr where Ci is the companion matrix to pi.
  %
  begin
    scalar diag_mat,tmp;
    integer num;
    num := length inv_fact;
    tmp:=for i:=1:num collect companion(nth(inv_fact,i),x);
    diag_mat := reval{'diagi, tmp};
    return diag_mat;
  end;




symbolic procedure make_identity(row_dim,col_dim);
  %
  % Creates identity matrix.
  %
  begin
    scalar a;
    a := mkmatrix(row_dim,col_dim);
    for i:=1:row_dim do
    <<
      for j:=1:col_dim do
      <<
        if i=j then setmat(a,i,i,1);
      >>
    >>;
    return a;
  end;





symbolic procedure matrix_input_test(a);
  begin
    if not eqcar(a,'mat) then rederr
     {"ERROR: `",a,"' is non matrix input."}
    else return a;
  end;




symbolic procedure mysmith(us,l,linv,x);
  %
  % The Smith normal form S of a matrix US is computed. L and Linv are
  % also computed where L*S*R=US.
  % For description of mysmith see smithex.
  %
  begin
    scalar s,a,b,g,jj,s1,t1,tmp,isclear,q,lc,poly1,poly2,input1,input2;
    integer n,r;

    n:= car size_of_matrix(us);

    s := copy_mat(us);

    for k:=1:n do
    <<

      isclear := nil;
      while not isclear do
      <<
        for i:= k+1:n do
        <<

          if getmat(s,i,k) = 0 then <<>>
          else
          <<

            poly1 := getmat(s,k,k);
            poly2 := getmat(s,i,k);
            tmp := calc_exgcd(poly1,poly2,x);
            g := car tmp;
            s1 := cadr tmp ;
            t1 := caddr tmp ;
            a := get_quo(poly1,g);
            b := get_quo(poly2,g);
            for j:=k+1:n do
            <<
              input1 := getmat(s,k,j);
              input2 := getmat(s,i,j);
              tmp := {'plus,{'times,s1,input1},{'times,t1,input2}};
              setmat(s,i,j,{'plus,{'times,a,input2},{'minus,{'times,b,
                     input1}}});
              setmat(s,k,j,tmp);
            >>;

            for j:=1:n do
            <<
              tmp := reval{'plus,{'times,a,getmat(l,j,k)},{'times,b,
                           getmat(l,j,i)}};
              setmat (l,j,i,reval{'plus,{'times,{'minus,t1},
                      getmat(l,j,k)},{'times,s1,getmat(l,j,i)}});
              setmat (l,j,k,tmp);
            >>;

            for j:=1:n do
            <<
              tmp := reval{'plus,{'times,s1,getmat(linv,k,j)},
                           {'times,t1,getmat(linv,i,j)}};
              setmat (linv,i,j,reval{'plus,{'times,a,getmat(linv,i,j)},
                      {'times,{'minus,b},getmat(linv,k,j)}});
              setmat (linv,k,j,tmp);
            >>;

            setmat(s,k,k,g);
            setmat(s,i,k,0);

          >>;

        >>;
        isclear := t;

        for i:=k+1:n do
        <<
          poly1:=getmat(s,k,i);
          poly2:=getmat(s,k,k);
          setmat(s,k,i,get_rem(poly1,poly2));
          q := get_quo(poly1,poly2);
        >>;

        for i:=k+1:n do
        <<
          if getmat(s,k,i) = 0 then <<>>
          else
          <<
            poly1:=getmat(s,k,k);
            poly2:=getmat(s,k,i);
            tmp := calc_exgcd(poly1,poly2,x);
            g:= car tmp;
            s1 := cadr tmp;
            t1 := caddr tmp;
            a:=get_quo(poly1,g);
            b:=get_quo(poly2,g);

            for j:=k+1:n do
            <<
              input1 := getmat(s,j,k);
              input2 := getmat(s,j,i);
              tmp := {'plus,{'times,s1,input1},{'times,t1,input2}};
              setmat(s,j,i,{'plus,{'times,a,input2},{'minus,{'times,b,
                     input1}}});
              setmat(s,j,k,tmp);
            >>;

            setmat(s,k,k,g);
            setmat(s,k,i,0);
            isclear := nil;
          >>;
        >>;

      >>;
    >>;

    r:=0;
    for i:=1:n do
    <<

      if getmat(s,i,i) neq 0 then
      <<
        r:=r+1;
        %  Watch out for integers giving lc = 0.
        if off_mod_lcof(getmat(s,i,i),x) = 0 then lc := getmat(s,i,i)
        else lc := off_mod_lcof(getmat(s,i,i),x);
        setmat(s,r,r,{'quotient,getmat(s,i,i),lc});
        if i neq r then
        <<
          setmat(s,i,i,0);

          for j:=1:n do
          <<
            tmp := reval getmat(l,j,r);
            setmat(l,j,r,reval getmat(l,i,j));

            setmat(l,j,i,tmp);
          >>;

          for j:=1:n do
          <<
            tmp := reval getmat(linv,r,j);
            setmat(linv,r,j,reval getmat(linv,i,j));
            setmat(linv,i,j,tmp);
          >>;

        >>;
      >>;

    >>;



    for i:=1:r-1 do
    <<
      jj:=i+1;
      <<
        while reval getmat(s,i,i) neq 1 and jj <= r do
        <<
          poly1:=reval getmat(s,i,i);
          poly2:=reval getmat(s,jj,jj);
          tmp := calc_exgcd(poly1,poly2,x);
          g:= car tmp;
          s1 := cadr tmp;
          t1 := caddr tmp;
          a:=get_quo(poly1,g);
          b:=get_quo(poly2,g);
          setmat(s,i,i,g);
          setmat(s,jj,jj,{'times,a,poly2});

          for k:=1:n do
          <<
            tmp := reval {'plus,{'times,a,getmat(l,k,i)},{'times,b,
                          getmat(l,k,jj)}};
            setmat (l,k,jj,reval {'plus,{'times,{'minus,t1},
                    getmat(l,k,i)},{'times,s1,getmat(l,k,jj)}});
            setmat (l,k,i,tmp);
          >>;

          for k:=1:n do
          <<
            tmp := reval {'plus,{'times,s1,getmat(linv,i,k)},{'times,t1,
                          getmat(linv,jj,k)}};
            setmat(linv,jj,k,reval {'plus,{'times,a,getmat(linv,jj,k)},
                   {'times,{'minus,b},getmat(linv,i,k)}});
            setmat(linv,i,k,tmp);
          >>;

          jj:=jj+1;
        >>;
      >>;
    >>;

    return {s,l,linv};
  end;




symbolic procedure nest_input(a);
  %
  % Takes a matrix and converts all elements into nested form.
  % Also finds union of all coefficients in all elements and
  % returns them in a list, along with the new matrix.
  %
  begin
    scalar tmp,coeff_list,full_coeff_list,aa;
    integer row_dim,col_dim;

    full_coeff_list := nil;
    coeff_list := nil;

    aa := copy_mat(a);

    row_dim := car size_of_matrix(aa);
    col_dim := cadr size_of_matrix(aa);

    for i := 1:row_dim do
    <<
      for j := 1:col_dim do
      <<
        coeff_list := get_coeffs(getmat(aa,i,j));
        if coeff_list = nil then <<>>
        else full_coeff_list := union(coeff_list,full_coeff_list);
        for each elt in coeff_list do
        <<
          tmp := {'co,2,elt};
          setmat(aa,i,j,algebraic (sub(elt=tmp,getmat(aa,i,j))));
        >>;
      >>;
    >>;


    return {aa,full_coeff_list};
  end;




symbolic procedure off_mod_lcof(input,x);
  begin
    if !*modular then
    <<
      off modular;
      input := lcof (input,x);
      on modular;
    >>
    else input := lcof (input,x);
    return input;
  end;




symbolic procedure off_mod_reval(input);
  %
  %  In certain cases it is required to reval with modular off,
  %  eg: when calculating degrees of polys.
  %
  begin
    if !*modular then
    <<
      off modular;
      input := reval input;
      on modular;
    >>
    else input := reval input;
    return input;
  end;

flag('(off_mod_reval),'opfn);  %  So it can be used from
                               %  algebraic mode.



symbolic procedure plist_to_polycompanion(plist,x);
  %
  % This is not used.
  % It is here to help explain what's going on.
  %
  % If a=a0+a1*x+x^2, b=b0+b1*x+b2*x^2+x^3 and
  % c=c0+c1*x+c2*x^2+c3*x^3+c4*x^4+x^5, then
  % plist_to_polycompanion({a,b,c},x) yields
  %
  %      [ 0  -a0  -b0   0   -c0 ]
  %      [                       ]
  %      [ 1  -a1  -b1   0   -c1 ]
  %      [                       ]
  %      [ 0   0   -b2   0   -c2 ]
  %      [                       ]
  %      [ 0   0    0    0   -c3 ]
  %      [                       ]
  %      [ 0   0    0    1   -c4 ]
  %
  begin
    scalar d,a;
    integer r,n;

    r := length plist;
    d := mkvect(r);
    putv(d,0,0);

    for i:=1:r do putv(d,i,deg(nth(plist,i),x));

    n := getv(d,r);
    a := mkmatrix(n,n);

    for i:=1:r do
    <<
      for j:=getv(d,i-1)+2:getv(d,i) do setmat(a,j,j-1,1);
      for j:=i:r do
      <<
        for k:=getv(d,i-1)+1:getv(d,i) do
        <<
          setmat(a,k,getv(d,j),{'minus,coeffn(nth(plist,j),x,k-1)});
        >>;
      >>;
    >>;

    return a;
  end;




symbolic procedure size_of_matrix(a);
  %
  % Takes matrix and returns list {no. of rows, no. of columns).
  %
  begin
    integer row_dim,col_dim;
    matrix_input_test(a);
    row_dim := -1 + length a;
    col_dim := length cadr a;
    return {row_dim,col_dim};
  end;




symbolic procedure uppersmith(g,x);
  %
  % An upper triangular matrix G is simplified. Entry G(i,j) is reduced
  % modulo gcd(G(i,i),G(j,j)). L and L^(-1) are also comnputed where
  % L*G'*R=G, where G' is the reduced matrix.
  %
  begin

    scalar us,l,linv,g,s1,t1,q,r,tmp;
    integer n;

    n:= car size_of_matrix(g);

    us:=copy_mat(g);

    l := make_identity(n,n);
    linv := make_identity(n,n);

    for j:=2:n do
    <<
      for i:=1:j-1 do
      <<
        tmp:=calc_exgcd(getmat(us,i,i),getmat(us,j,j),x);
        g:= car tmp;
        s1:= cadr tmp;
        t1 := caddr tmp;
        q := get_quo(getmat(us,i,j),g);
        r := get_rem(getmat(us,i,j),g);

        setmat(us,i,j,r);

        for k:=1:i-1 do
        <<
          tmp := getmat(us,k,i);
          setmat(us,k,j,{'plus,getmat(us,k,j),{'times,{'minus,q},s1,
                 getmat(us,k,i)}});
        >>;

        for k:=j+1:n do
        <<
          setmat(us,i,k,{'plus,getmat(us,i,k),{'times,{'minus,q},t1,
                 getmat(us,j,k)}});
        >>;

        for k:=1:i do
        <<
          setmat(l,k,j,{'plus,getmat(l,k,j),{'times,q,t1,
                 getmat(l,k,i)}});
        >>;

        setmat(linv,i,j,{'times,{'minus,q},t1});
      >>;
    >>;

    return {us,l,linv};
  end;

endmodule;


module matarg;
               % This module forms the ability for matrices to be passed
               % between functions.
               %
               % This module can be used independently from algebraic
               % mode.
               %
               % It was written by W. Neun.
               %

symbolic procedure mkmatrix(n,m);
   'mat . (for i:=1:n collect
           for j:=1:m collect 0);

symbolic procedure setmat(matri,i,j,val);
    <<   if !*modular then << off modular; on mod_was_on; >>;
         i := reval i;
         j := reval j;
         val := mk!*sq simp reval val;
         letmtr(list(matri,i,j),val,matri);
         if !*mod_was_on then << on modular; off mod_was_on; >>;
         matri>>;

symbolic procedure getmat(matri,i,j);
    <<   i := off_mod_reval i;
         j := off_mod_reval j;
         unchecked_getmatelem list(matri,i,j)>>;

symbolic procedure unchecked_getmatelem u;
  begin scalar x;
         if not eqcar(x :=  car u,'mat)
          then  rerror(matrix,1,list("Matrix",car u,"not set"))
         else return nth(nth(cdr x,cadr u),caddr u);
   end;

flag('(setmat,getmat,mkmatrix,letmtr),'opfn);  %  So they can be used
                                               %  independently from
                                               %  algebraic mode.

endmodule;


module nestdom; %
                % nested domain: domain elements are standard quotients.
                % Coefficients are taken from the integers or another
                % dnest.
                %
                % This module was written by H. Melenk.
                %

%%%%%%%%%
% Adaption to allow convertion between arnum and nested.
%%%%%%%%%
symbolic procedure ident(x);x;
put('!:ar!:,'!:nest!:,'ident);
%%%%%%%%%


% data structure:
%  a domain element is a list
%      ('!:nest!: level# dmode* . sq)

smacro procedure nestlevel u; cadr u;
smacro procedure nestdmode u; caddr u;
smacro procedure nestsq u; cdddr u;

global '(domainlist!*);

fluid '(alglist!* nestlevel!*);
nestlevel!* := 0;

switch nested;

domainlist!* := union('(!:nest!:),domainlist!*);

put('nested,'tag,'!:nest!:);
put('!:nest!:,'dname,'nested);
flag('(!:nest!:),'field);
flag('(!:nest!:),'convert);
put('!:nest!:,'i2d,'!*i2nest);
% PUT('!:nest!:,'!:BF!:,'nestCNV);
% PUT('!:nest!:,'!:FT!:,'nestCNV);
% PUT('!:nest!:,'!:RN!:,'nestCNV);
put('!:nest!:,'!:bf!:,mkdmoderr('!:nest!:,'!:bf!:));
put('!:nest!:,'!:ft!:,mkdmoderr('!:nest!:,'!:ft!:));
put('!:nest!:,'!:rn!:,mkdmoderr('!:nest!:,'!:rn!:));
put('!:nest!:,'minusp,'nestminusp!:);
put('!:nest!:,'plus,'nestplus!:);
put('!:nest!:,'times,'nesttimes!:);
put('!:nest!:,'difference,'nestdifference!:);
put('!:nest!:,'quotient,'nestquotient!:);
put('!:nest!:,'divide,'nestdivide!:);
% PUT('!:nest!:,'gcd,'nestgcd!:);
put('!:nest!:,'zerop,'nestzerop!:);
put('!:nest!:,'onep,'nestonep!:);
% PUT('!:nest!:,'factorfn,'factornest!:);
put('!:nest!:,'prepfn,'nestprep!:);
put('!:nest!:,'prifn,'prin2);
put('!:rn!:,'!:nest!:,'rn2nest);

symbolic procedure !*i2nest u;
   %converts integer U to nested form;
   if domainp u then u else
   '!:nest!: . 0 . dmode!* . (u ./ 1);

symbolic procedure rn2nest u;
   %converts integer U to nested form;
   if domainp u then u else
   '!:nest!: . 0 . dmode!* . (cdr u);

symbolic procedure nestcnv u;
   rederr list("Conversion between `nested' and",
                get(car u,'dname),"not defined");

symbolic procedure nestminusp!: u;
   nestlevel u = 0 and minusf car nestsq u;

symbolic procedure sq2nestedf sq;
  '!:nest!: . nestlevel!* . dmode!* . sq;

symbolic procedure nest2op!:(u,v,op);
  (begin scalar r,nlu,nlv,nlr,dm,nestlevel!*;
     nlu := if not eqcar (u,'!:nest!:) then 0 else nestlevel u;
     nlv := if not eqcar (v,'!:nest!:) then 0 else nestlevel v;
     if nlu = nlv then goto case1
     else if nlu #> nlv then goto case2
     else goto case3;
   case1:    % same level for u and v
            dm := nestdmode u;
            if dm then setdmode(dm,t);
            nlr := nlu;
            nestlevel!* := nlu - 1;
            r := apply(op,list(nestsq u,nestsq v));
            goto ready;
   case2:    % v below u
            dm := nestdmode u;
            if dm then setdmode(dm,t);
            nlr := nlu;
            nestlevel!* := nlv;
            r := apply(op,list (nestsq u, v ./ 1));
            goto ready;
   case3:     % u below v
            dm := nestdmode v;
            if dm then setdmode(dm,t);
            nlr := nlv;
            nestlevel!* := nlu;
            r := apply(op,list (u ./ 1,nestsq v));
   ready:
            r := if null numr r then nil
            else if domainp numr r and denr r = 1 then numr r
            else '!:nest!: . nlr . dm . r;
     if dm then setdmode (dm,nil);
     return r;
    end )  where dmode!* = nil;

symbolic procedure nestplus!:(u,v); nest2op!:(u,v,'addsq);

symbolic procedure nesttimes!:(u,v); nest2op!:(u,v,'multsq);

symbolic procedure nestdifference!:(u,v);
    nest2op!:(u,v,function (lambda(x,y); addsq(x,negsq y)));

symbolic procedure nestdivide!:(u,v); nest2op!:(u,v,'quotsq) . 1;

%symbolic procedure nestgcd!:(u,v); !*i2nest 1;

symbolic procedure nestquotient!:(u,v); nest2op!:(u,v,'quotsq);

symbolic procedure nestzerop!: u; null numr nestsq u;

symbolic procedure nestonep!: u;
       (car v = 1 and cdr v = 1) where v = nestsq u;

initdmode 'nested;


% nested routines are defined in the GENnest nestule with the exception
% of the following:

symbolic procedure setnest u;
   begin
      u := reval u;
      if not fixp u then typerr(u,"nestulus");
      nestlevel!* := u;
   end;

flag('(setnest),'opfn);   %to make it a symbolic operator;

flag('(setnest),'noval);

algebraic operator co;

symbolic procedure simpco u;
 % conmvert an expression to a nested coefficient
   begin scalar  sq,lev;
     if not (length u = 2 and fixp car u) then
             typerr(u,"nested coefficient");
     sq := simp cadr u;
     lev := car u;
     return (if null numr sq then nil else ('!:nest!: . lev . dmode!* .
sq)) ./ 1;
   end;

put('co,'simpfn,'simpco);

symbolic procedure nestprep!: u; list('co,nestlevel u,prepsq nestsq u);

endmodule;


module smithex; % Computation of the Smithex normal form of a matrix.
                                                   %

% The function smithex computes the Smith normal form S of an n by m
% rectangular matrix of univariate polynomials in x.
%
% Specifically:
%
% - smithex(A,x) will return {S,P,Pinv} where S, P, and Pinv
%   are such that P*S*Pinv = A.

symbolic procedure smithex(mat1,x);
  begin
    scalar a,left,right,tmp,isclear,g,l,r1,poly1,poly2,quo1,quo2,r,
           lc,tquo,q,full_coeff_list,rule_list,input_mode;
    integer i,j,n,m;

    matrix_input_test(mat1);

    input_mode := get(dmode!*,'dname);
    if input_mode = 'modular
     then rederr "ERROR: smithex does not work with modular on.";
    all_integer_entries_test(mat1);
    if input_mode neq 'arnum and input_mode neq 'rational
     then on rational;
    on combineexpt;

    tmp := nest_input_smith(mat1,x);
    a := car tmp;
    full_coeff_list := cadr tmp;

    n := car size_of_matrix(a); %  No. of rows.
    m := cadr size_of_matrix(a); %  No. of columns.

    left := make_identity(n,n) ;
    right := make_identity(m,m);

    for k:=1:min(n,m) do
    <<
      %
      %  Pivot selection from row k to column k.
      %
      i := k; while i <= n and getmat(a,i,k) = 0 do i := i+1;
      j := k; while j <= m and getmat(a,k,j) = 0 do j := j+1;

      if i > n and j > m then <<>>
      else
      <<
        %
        %  Select smallest non-zero entry as pivot.
        %
        for l:=i+1:n do
        <<
          if getmat(a,l,k) = 0 then l := l+1
          else if deg(getmat(a,l,k),x) < deg(getmat(a,i,k),x) then
          i := l;
        >>;

        for l:=j+1:m do
        <<
          if getmat(a,k,l) = 0 then l := l+1
          else if deg(getmat(a,k,l),x) < deg(getmat(a,k,j),x) then
          j := l;
        >>;

        if i <= n and (j > m or deg(getmat(a,i,k),x) <
                                 deg(getmat(a,k,j),x))
    then
        %
        %  Pivot is A(i,k), interchange row k,i if necessary.
        %
        <<
          if i neq k then
          <<

            for l:=k:m do
            <<
              tmp := getmat(a,i,l);
              setmat(a,i,l,getmat(a,k,l));
              setmat(a,k,l,tmp);
            >>;

            for l:=1:n do
            <<
              tmp := getmat(left,l,i);
              setmat(left,l,i,getmat(left,l,k));
              setmat(left,l,k,tmp);
            >>;

          >>
        >>
        else
        %
        %  Pivot is A(k,j), interchange column k,j if necessary.
        %
        <<
          if j neq k then
          <<

            for l:=k:n do
            <<
              tmp := getmat(a,l,j);
              setmat(a,l,j,getmat(a,l,k));
              setmat(a,l,k,tmp);
            >>;

            for l:=1:m do
            <<
              tmp := getmat(right,j,l);
              setmat(right,j,l,getmat(right,k,l));
              setmat(right,k,l,tmp);
            >>;

          >>;
        >>;

        isclear := nil;

        while not isclear do
        %
        %  0 out column k from k+1 to n.
        %
        <<
          for i:=k+1:n do
          <<
            if getmat(a,i,k) = 0 then <<>>
            else
            <<
              poly1 := getmat(a,k,k);
              poly2 := getmat(a,i,k);
              tmp := calc_exgcd(poly1,poly2,x);
              g := car tmp;
              l := cadr tmp;
              r1 := caddr tmp;
              quo1 := get_quo(poly1,g);
              quo2 := get_quo(poly2,g);

              for j:=k+1:m do
              <<
                tmp := {'plus,{'times,l,getmat(a,k,j)},{'times,r1,
                        getmat(a,i,j)}};
                setmat(a,i,j,{'plus,{'times,quo1,getmat(a,i,j)},{'times,
                       {'minus,quo2},getmat(a,k,j)}});
                setmat(a,k,j,tmp);
              >>;

              for j:=1:n do
              <<
                tmp := {'plus,{'times,quo1,getmat(left,j,k)},
                        {'times,quo2,getmat(left,j,i)}};
                setmat(left,j,i,{'plus,{'times,{'minus,r1},
                       getmat(left,j,k)},{'times,l,getmat(left,j,i)}});
                setmat(left,j,k,tmp);
              >>;

              setmat(a,k,k,g);
              setmat(a,i,k,0);
            >>;
          >>;

          isclear := t;
          %
          % 0 out row k from k+1 to m.
          %
          for i:=k+1:m do
          <<
            q := get_quo(getmat(a,k,i),getmat(a,k,k));
            setmat(a,k,i,get_rem(getmat(a,k,i),getmat(a,k,k)));

            for j:=1:m do
            <<
              setmat(right,k,j,{'plus,getmat(right,k,j),{'times,q,
                     getmat(right,i,j)}});
            >>;

          >>;

          for i:=k+1:m do
          <<
            if getmat(a,k,i) = 0 then <<>>
            else
            <<
              poly1 := getmat(a,k,k);
              poly2 := getmat(a,k,i);
              tmp := calc_exgcd(poly1,poly2,x);
              g := car tmp;
              l := cadr tmp;
              r1 := caddr tmp;
              quo1 := get_quo(poly1,g);
              quo2 := get_quo(poly2,g);

              for j:=k+1:n do
              <<
                tmp := {'plus,{'times,l,getmat(a,j,k)},{'times,r1,
                        getmat(a,j,i)}};
                setmat(a,j,i,{'plus,{'times,quo1,getmat(a,j,i)},{'times,
                       {'minus,quo2},getmat(a,j,k)}});
                setmat(a,j,k,tmp);
              >>;

              for j:=1:m do
              <<
                tmp := {'plus,{'times,quo1,getmat(right,k,j)},
                        {'times,quo2,getmat(right,i,j)}};
                setmat(right,i,j,{'plus,{'times,{'minus,r1},
                       getmat(right,k,j)},
                       {'times,l,getmat(right,i,j)}});
                setmat(right,k,j,tmp);
              >>;

              setmat(a,k,k,g);
              setmat(a,k,i,0);
              isclear := nil;
            >>;
          >>;

        >>;
      >>;
    >>;

    r := 0;
    %
    %  At this point, A is diagonal: some A(i,i) may be zero.
    %  Move non-zero's up also making all entries unit normal.
    %
    for i:=1:min(n,m) do
    <<
      if getmat(a,i,i) neq 0 then
      <<
        r := r+1;
        % Watch out for integers giving lc = 0.
        if lcof(getmat(a,i,i),x) = 0  then lc := getmat(a,i,i)
        else lc := lcof(getmat(a,i,i),x);
        setmat(a,r,r,{'quotient,getmat(a,i,i),lc});

        if i = r then
        <<
          for j:=1:m do
          <<
            setmat(right,i,j,{'times,getmat(right,i,j),lc});
          >>;
        >>
        else
        <<
          setmat(a,i,i,0);
          for j:=1:n do
          <<
            tmp := getmat(left,j,r);
            setmat(left,j,r,getmat(left,j,i));
            setmat(left,j,i,tmp);
          >>;
          for j:=1:m do
          <<
            tmp := {'times,getmat(right,i,j),lc};
            setmat(right,i,j,{'quotient,getmat(right,r,j),lc});
            setmat(right,r,j,tmp);
          >>;
        >>;

      >>;
    >>;
    %
    %  Now make A(i,i) | A(i+1,i+1) for 1 <= i < r.
    %
    for i:=1:r-1 do
    <<
      j:=i+1;
      <<
        while getmat(a,i,i) neq 1 and j <= r do
        <<
          poly1 := getmat(a,i,i);
          poly2 := getmat(a,j,j);
          tmp := calc_exgcd(poly1,poly2,x);
          g := car tmp;
          l := cadr tmp;
          r1 := caddr tmp;
          quo1 := get_quo(poly1,g);
          quo2 := get_quo(poly2,g);

          setmat(a,i,i,g);
          setmat(a,j,j,{'times,quo1,getmat(a,j,j)});

          for k:=1:n do
          <<
            tmp := {'plus,{'times,quo1,getmat(left,k,i)},{'times,quo2,
                    getmat(left,k,j)}};
            setmat(left,k,j,{'plus,{'times,{'minus,r1},
                   getmat(left,k,i)},{'times,l,getmat(left,k,j)}});
            setmat(left,k,i,tmp);
          >>;

          for k:=1:m do
          <<
            tquo := {'times,r1,quo2};
            tmp := {'plus,{'times,{'plus,1,{'minus,tquo}},
                    getmat(right,i,k)},{'times,tquo,getmat(right,j,k)}};
            setmat(right,j,k,{'plus,{'minus,getmat(right,i,k)},
                   getmat(right,j,k)});
            setmat(right,i,k,tmp);
          >>;

          j := j+1;
        >>;
      >>;
    >>;
    %
    %  Set up rule list for removing nests.
    %
    rule_list := {'co,2,{'~,'int}}=>'int when numberp(int);
    for each elt in full_coeff_list do
    <<
      tmp := {'co,2,{'~,elt}}=>elt;
      rule_list := append (tmp,rule_list);
    >>;
    %
    %  Remove nests.
    %
    let rule_list;
    a := de_nest_mat(a);
    left := de_nest_mat(left);
    right := de_nest_mat(right);
    clearrules rule_list;
    %
    % Return to original mode.
    %
    if input_mode neq 'rational and input_mode neq 'arnum then
    <<
      % onoff('nil,t) doesn't work so...
      if input_mode = 'nil then off rational
      else onoff(input_mode,t);
    >>;
    off combineexpt;

    return {'list,a,left,right};
  end;

flag ('(smithex),'opfn);  %  So it can be used from algebraic mode.



symbolic procedure get_coeffs_smith(poly,x);
  %
  % Gets all kernels in a poly.
  %
  % This is the version form smithex. The polynomials are
  % known to be in x (smithex(matrix,x)) so this is removed
  % from the output so as to not be nested in
  % nest_input_smith.
  %
  begin
    scalar ker_list_num,ker_list_den,new_list;

    ker_list_num := kernels !*q2f simp reval num poly;
    ker_list_den := kernels !*q2f simp reval den poly;

    ker_list_num := union(ker_list_num,ker_list_den);

    if ker_list_num = nil then new_list := nil
    else
    <<
      %  Remove x.
      for i:=1:length ker_list_num do
      <<
        if car ker_list_num = x then new_list := new_list
        else new_list := car ker_list_num.new_list;
        ker_list_num := cdr ker_list_num;
      >>;
    >>;

    return new_list;
  end;




symbolic procedure nest_input_smith(a,x);
  %
  % Takes a matrix and converts all elements into nested form.
  % Also finds all coefficients and returns them in a list.
  %
  % With Smithex all polynomials are in x (input by user) so
  % this is removed from the full_coeff_list (see get_coeffs),
  % and is thus not nested.
  %
  begin
    scalar tmp,coeff_list,full_coeff_list,aa;

    integer row_dim,col_dim;

    full_coeff_list := nil;
    coeff_list := nil;

    aa := copy_mat(a);

    row_dim := car size_of_matrix(aa);
    col_dim := cadr  size_of_matrix(aa);

    for i := 1:row_dim do
    <<
      for j := 1:col_dim do
      <<
        coeff_list := get_coeffs_smith(getmat(aa,i,j),x);
        if coeff_list = nil then <<>>
        else full_coeff_list := union(coeff_list,full_coeff_list);
        for each elt in coeff_list do
        <<
          tmp := {'co,2,elt};
          setmat(aa,i,j,algebraic (sub(elt=tmp,getmat(aa,i,j))));
        >>;
      >>;
    >>;


    return {aa,full_coeff_list};
  end;




switch int_test;
symbolic procedure all_integer_entries_test(mat1);
  begin
    on int_test;
    for i:=1:car size_of_matrix(mat1) do
    <<
      for j:=1:cadr size_of_matrix(mat1) do
      <<
        if not numberp getmat(mat1,i,j) and !*int_test
         then off int_test;
      >>;
    >>;
    if !*int_test then prin2t
    "*** WARNING: all matrix entries are integers.
    If calculations in Z(the integers) are required, use smithex_int.";
    system "sleep 3";
  end;

endmodule;


module smithex1;
%                                                                      %
%**********************************************************************%

% The function smithex_int computes the Smith normal form S of an n by
% m rectangular matrix of integers.
%
% Specifically:
%
% - smithex_int(A) will return {S,P,Pinv} where S, P, and Pinv
%   are such that inverse(P)*A*P = S.




symbolic procedure smithex_int(b);
  begin
    scalar left,right,isclear,a;
    integer n,m,i,j,k,l,tmp,g,ll,rr,int1,int2,quo1,quo2,r,sgn,rrquo,
            q,input_mode;

    matrix_input_test(b);

    input_mode := get(dmode!*,'dname);
    if input_mode = 'modular
     then rederr "ERROR: smithex_int does not work with modular on.";

    integer_entries_test(b);

    a := copy_mat(b);

    n := car size_of_matrix(a); %  No. of rows.
    m := cadr size_of_matrix(a); %  No. of columns.

    left := make_identity(n,n) ;
    right := make_identity(m,m);

    for k:=1:min(n,m) do
    <<
      %
      %  Pivot selection from row k to column k.
      %
      i := k; while i<= n and getmat(a,i,k) = 0 do i:=i+1;
      j := k; while j<= m and getmat(a,k,j) = 0 do j:=j+1;

      if i>n and j>m then <<>>
      else
      <<
        %
        %  Select smallest non-zero entry as pivot.
        %
        for l:=i+1:n do
        <<
          if getmat(a,l,k) = 0 then l := l+1
          else if abs(getmat(a,l,k)) < abs(getmat(a,i,k)) then i := l;
        >>;

        for l:=j+1:m do
        <<
          if getmat(a,k,l) = 0 then l := l+1
          else if abs(getmat(a,k,l)) < abs(getmat(a,k,j)) then j := l;
        >>;

        if i<=n and (j>m or abs(getmat(a,i,k))<abs(getmat(a,k,j))) then
        %
        %  Pivot is A(i,k), interchange row k,i if necessary.
        %
        <<
          if i neq k then
          <<

            for l:=k:m do
            <<
              tmp:= getmat(a,i,l);
              setmat(a,i,l,getmat(a,k,l));
              setmat(a,k,l,tmp);
            >>;

            for l:=1:n do
            <<
              tmp:= getmat(left,l,i);
              setmat(left,l,i,getmat(left,l,k));
              setmat(left,l,k,tmp);
            >>;

          >>
        >>
        else
        %
        %  Pivot is A(k,j), interchange column k,j if necessary.
        %
        <<
          if j neq k then
          <<

            for l:=k:n do
            <<
              tmp:= getmat(a,l,j);
              setmat(a,l,j,getmat(a,l,k));
              setmat(a,l,k,tmp);
            >>;

            for l:=1:m do
            <<
              tmp:= getmat(right,j,l);
              setmat(right,j,l,getmat(right,k,l));
              setmat(right,k,l,tmp);
            >>;

          >>;
        >>;

        isclear := nil;

        while not isclear do
        %
        %  0 out column k from k+1 to n.
        %
        <<
          for i:=k+1:n do
          <<
            if getmat(a,i,k) = 0 then <<>>
            else
            <<
              int1 := getmat(a,k,k);
              int2 := getmat(a,i,k);
              tmp := (calc_exgcd_int(int1,int2));
              g := car tmp;
              ll := cadr tmp;
              rr := caddr tmp;
              quo1 := get_quo_int(getmat(a,k,k),g);
              quo2 := get_quo_int(getmat(a,i,k),g);

              %
              %  We have  ll A(k,k)/g + rr A(i,k)/g = 1
              %
              %       [  ll     rr   ]  [ A[k,k]  A[k,j] ]   [ g  ... ]
              %       [              ]  [                ] = [        ]
              %       [ -quo2  quo1  ]  [ A[i,k]  A[i,j] ]   [ 0  ... ]
              %
              %       for j = k+1..m  where note  ll quo1 + rr quo2 = 1
              %

              for j:=k+1:m do
              <<
                tmp := ll*getmat(a,k,j)+rr*getmat(a,i,j);
                setmat(a,i,j,quo1*getmat(a,i,j)-quo2*getmat(a,k,j));
                setmat(a,k,j,tmp);
              >>;

              for j:=1:n do
              <<
                tmp := quo1*getmat(left,j,k)+quo2*getmat(left,j,i);
                setmat(left,j,i,-rr*getmat(left,j,k)+ll*
                       getmat(left,j,i));
                setmat(left,j,k,tmp);
              >>;

              setmat(a,k,k,g);
              setmat(a,i,k,0);
            >>;
          >>;

          isclear := t;
          %
          %  0 out row k from k+1 to m.
          %
          for i:=k+1:m do
          <<
            q := get_quo_int(getmat(a,k,i),getmat(a,k,k));
            setmat(a,k,i,get_rem_int(getmat(a,k,i),getmat(a,k,k)));

            for j:=1:m do
            <<
              setmat(right,k,j,getmat(right,k,j)+q*getmat(right,i,j));
            >>;

          >>;

          for i:=k+1:m do
          <<
            if getmat(a,k,i) = 0 then <<>>
            else
            <<
              tmp := calc_exgcd_int( getmat(a,k,k),getmat(a,k,i));
              g := car tmp;
              ll := cadr tmp;
              rr := caddr tmp;
              quo1 := get_quo_int(getmat(a,k,k),g);
              quo2 := get_quo_int(getmat(a,k,i),g);

              for j:=k+1:n do
              <<
                tmp := ll*getmat(a,j,k) + rr*getmat(a,j,i);
                setmat(a,j,i,quo1*getmat(a,j,i)-quo2*getmat(a,j,k));
                setmat(a,j,k,tmp);
              >>;

              for j:=1:m do
              <<
                tmp := quo1*getmat(right,k,j)+quo2*getmat(right,i,j);
                setmat(right,i,j,-rr*getmat(right,k,j)+ll*
                       getmat(right,i,j));
                setmat(right,k,j,tmp);
              >>;

              setmat(a,k,k,g);
              setmat(a,k,i,0);

              isclear := nil;
            >>;
          >>;

        >>;
      >>;
    >>;

    r := 0;
    %
    %  At this point, A is diagonal: some A(i,i) may be zero.
    %  Move non-zero's up also making all entries unit normal.
    %
    for i:=1:min(n,m) do
    <<
      if getmat(a,i,i) neq 0 then
      <<
        r := r+1;
        sgn := algebraic (sign(getmat(a,i,i)));
        setmat(a,r,r,sgn*getmat(a,i,i));
        if i = r then
        <<

          for j:=1:m do
          <<
            setmat(right,i,j,getmat(right,i,j)*sgn);
          >>;

        >>
        else
        <<
          setmat(a,i,i,0);

          for j:=1:n do
          <<
            tmp := getmat(left,j,r);
            setmat(left,j,r,getmat(left,j,i));
            setmat(left,j,i,tmp);
          >>;

          for j:=1:m do
          <<
            tmp := getmat(right,i,j)*sgn;
            setmat(right,i,j,getmat(right,r,j)*sgn);
            setmat(right,r,j,tmp);
          >>;

        >>;
      >>;
    >>;
    %
    %  Now make A(i,i) | A(i+1,i+1) for 1 <= i < r.
    %
    for i:=1:r-1 do
    <<
      j:=i+1;
      <<
        while getmat(a,i,i) neq 1 and j <= r do
        <<
          int1 := getmat(a,i,i);
          int2 := getmat(a,j,j);
          g := car (calc_exgcd_int(int1,int2));
          ll := cadr (calc_exgcd_int(int1,int2));
          rr := caddr (calc_exgcd_int(int1,int2));
          quo1 := get_quo_int(getmat(a,i,i),g);
          quo2 := get_quo_int(getmat(a,j,j),g);

          setmat(a,i,i,g);
          setmat(a,j,j,quo1*getmat(a,j,j));

          for k:=1:n do
          <<
            tmp := quo1*getmat(left,k,i)+quo2*getmat(left,k,j);
            setmat(left,k,j,-rr*getmat(left,k,i)+ll*
                   getmat(left,k,j));
            setmat(left,k,i,tmp);
          >>;

          for k:=1:m do
          <<
            rrquo := rr*quo2;
            tmp := (1-rrquo)*getmat(right,i,k)+rrquo*
                   getmat(right,j,k);
            setmat(right,j,k,-getmat(right,i,k)+getmat(right,j,k));
            setmat(right,i,k,tmp);
          >>;

          j := j+1;
        >>;
      >>;
    >>;

    return {'list,a,left,right};
  end;

flag ('(smithex_int),'opfn);  %  So it can be used from algebraic mode.



symbolic procedure calc_exgcd_int(int1,int2);
  begin
    integer gcd,c,c1,c2,d,d1,d2,q,r,r1,r2,s1,t1;

    if int1 = 0 and int2 = 0  then return {0,0,0}
    else
    <<

      c := reval int1;
      d := reval int2;

      c1 := 1;
      d1 := 0;
      c2 := 0;
      d2 := 1;

      while d neq 0 do
      <<
        q  := get_quo_int(c,d);
        r  := c - q*d;
        r1 := c1 - q*d1;
        r2 := c2 - q*d2;
        c  := d;
        c1 := d1;
        c2 := d2;
        d  := r;
        d1 := r1;
        d2 := r2;
      >>;

      gcd := abs(c);
      s1  := c1;
      t1  := c2;

      if c < 0 then
      <<
        s1 := -s1;
        t1 := -t1;
      >>;

      return {gcd,s1,t1};
    >>;
  end;


symbolic procedure get_quo_int(int1,int2);
  begin
    integer quo1,input1,input2;

    input1 := reval int1;
    input2 := reval int2;

    if input1 = 0 and input2 = 0 then return 0
    else
    <<
      if input1 < 0 and input2 < 0 then
      <<
        (input1 := abs(input1));
        (input2 := abs(input2));
      >>;

      if (input1/input2) < 0 then
      <<
        quo1 :=ceiling(input1/input2);
      >>
      else
      <<
        quo1 :=floor(input1/input2);
      >>;

      return quo1;
    >>;
  end;


symbolic procedure get_rem_int(int1,int2);
  begin
    integer rem1,input1,input2;
    input1 := reval int1;
    input2 := reval int2;
    rem1 := input1 - get_quo_int(input1,input2)*input2;
    return rem1;
  end;


symbolic procedure integer_entries_test(b);
  begin
    for i:=1:car size_of_matrix(b) do
    <<
      for j:=1:cadr size_of_matrix(b) do
      <<
        if not numberp getmat(b,i,j) then rederr
         "ERROR: matrix contains non_integer entries. Try smithex. "
      >>;
    >>;
  end;

endmodule;


end;
