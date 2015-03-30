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

