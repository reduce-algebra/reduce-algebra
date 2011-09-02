module linalg;   % The Linear Algebra package.

%**********************************************************************%
%                                                                      %
% Author: Matt Rebbeck, March-July 1994 (at ZIB).                      %
%                                                                      %
% Please report bugs to: Winfried Neun,                                %
%                        Konrad-Zuse-Zentrum                           %
%                           fuer Informationstechnik Berlin            %
%                        Heilbronner Str. 10                           %
%                        10711 Berlin - Wilmersdorf                    %
%                        Federal Republic of Germany                   %
%                                                                      %
%                (email) neun@sc.ZIB-Berlin.de                         %
%                                                                      %
%                                                                      %
%                                                                      %
% This package provides a selection of useful functions in the field   %
% of linear algebra:                                                   %
%                                                                      %
%   add_columns      add_rows       add_to_columns    add_to_rows      %
%   augment_columns  band_matrix    block_matrix      char_matrix      %
%   char_poly        cholesky       coeff_matrix      column_dim       %
%   companion        copy_into      diagonal          extend           %
%   get_columns      get_rows       gram_schmidt      hermitian_tp     %
%   hessian          hilbert        jacobian          jordan_block     %
%   lu_decom         make_identity  matrix_augment    matrixp          %
%   matrix_stack     minor          mult_column       mult_row         %
%   pivot            pseudo_inverse random_matrix     remove_columns   %
%   remove_rows      row_dim        rows_pivot        simplex          %
%   squarep          stack_rows     sub_matrix        svd              %
%   swap_columns     swap_entries   swap_rows         symmetricp       %
%   toeplitz         vandermonde    kronecker_product                  %
%                                                                      %
%                                                                      %
%                                                                      %
% The package implements the following switches:                       %
%                                                                      %
%  imaginary     \                                                     %
%  lower_matrix   \                                                    %
%  not_negative    )  for details see the random_matrix comments.      %
%  only_integer   /                                                    %
%  upper_matrix  /                                                     %
%                                                                      %
%  fast_la  (see below).                                               %
%                                                                      %
%                                                                      %
%                                                                      %
% For further details about the linear algebra package see the         %
% linear_algebra.tex file.                                             %
%                                                                      %
%                                                                      %
%                                                                      %
% NB: The functions in this package are written to be used from the    %
% user level. Some of them may well need a bit of fiddling with to get %
% them to work from symbolic mode.                                     %
%                                                                      %
%**********************************************************************%

load_package matrix;

create!-package ('(  linalg
                     lamatrix
                     gramschm
                     lu_decom
                     cholesky
                     svd
                     simplex  ),
                 '(contrib linalg));


switch fast_la;  % If ON, then the following functions will be faster:

%   add_columns      add_rows         augment_columns  column_dim      %
%   copy_into        make_identity    matrix_augment   matrix_stack    %
%   minor            mult_column      mult_row         pivot           %
%   remove_columns   remove_rows      rows_pivot       squarep         %
%   stack_rows       sub_matrix       swap_columns     swap_entries    %
%   swap_rows        symmetricp                                        %

% This is basically done by removing some error checking and doesn't
% speed things up too much. You'll need to be making alot of calls to
% see the difference. If you get strange error messages with fast_la
% ON then thoroughly check your input.



symbolic smacro procedure my_reval(n);
  %
  % Only revals if it needs to.
  %
  if fixp(n) then n else reval(n);



symbolic procedure swap_elt(in_list,elt1,elt2);
  %
  % Swaps elt elt1 with elt elt2 in in_list.
  %
  % NB: destructive.
  %
  begin
    scalar bucket;
    bucket := nth(in_list,elt1);
    nth(in_list,elt1) := nth(in_list,elt2);
    nth(in_list,elt2) := bucket;
  end;



symbolic procedure row_dim(in_mat);
  %
  % Finds row dimension of a matrix.
  %
  begin
    if not !*fast_la and not matrixp(in_mat) then
     rederr "Error in row_dim: input should be a matrix.";
    return first size_of_matrix(in_mat);
  end;



symbolic procedure column_dim(in_mat);
  %
  % Finds column dimension of a matrix.
  %
  begin
    if not !*fast_la and not matrixp(in_mat) then
     rederr "Error in column_dim: input should be a matrix.";
    return second size_of_matrix(in_mat);
  end;

flag('(row_dim,column_dim),'opfn);



symbolic procedure matrixp(a);
  %
  % Tests if input is a matrix (boolean).
  %
  if not eqcar(a,'mat) then nil else t;

flag('(matrixp),'boolean);
flag('(matrixp),'opfn);



symbolic procedure size_of_matrix(a);
  %
  % Takes matrix and returns list {no. of rows, no. of columns}.
  %
  begin
    integer row_dim,column_dim;
    row_dim := -1 + length a;
    column_dim := length cadr a;
    return {row_dim,column_dim};
  end;



symbolic procedure companion(poly,x);
  %
  % Takes as input a monic univariate polynomial in a variable x.
  % Returns a companion matrix associated with the polynomial poly(x).
  %
  % If C := companion(p,x) and p is a0+a1*x+...+x^n (a univariate monic
  % polynomial), them C(i,n) = -coeff(p,x,i-1), C(i,i-1) = 1 (i=2..n)
  % and C(i,j) = 0 for all other i and j.
  %
  begin
    scalar mat1;
    integer n;
    n := deg(poly,x);
    if my_reval coeffn(poly,x,n) neq 1 then msgpri
      ("Error in companion(first argument): Polynomial",
      poly, "is not monic.",nil,t);

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



symbolic procedure find_companion(r,x);
  %
  % Given a companion matrix, find_companion will return the associated
  % polynomial.
  %
  begin
    scalar  p;
    integer rowdim,k;
    if not matrixp(r) then rederr
     {"Error in find_companion(first argument): should be a matrix."};
    rowdim := row_dim(r);
    k := 2;
    while k<=rowdim and getmat(r,k,k-1)=1 do k:=k+1;
    p := 0;
    for j:=1:k-1 do
    <<
      p:={'plus,p,{'times,{'minus,getmat(r,j,k-1)},{'expt,x,j-1}}};
    >>;
    p := {'plus,p,{'expt,x,k-1}};
    return p;
  end;

flag('(companion,find_companion),'opfn);



symbolic procedure jordan_block(const,mat_dim);
  %
  % Takes a constant (const) and an integer (mat_dim) and creates
  % a jordan block of dimension mat_dim x mat_dim.
  %
  begin
    scalar jb;
    if not fixp mat_dim then rederr
     "Error in jordan_block(second argument): should be an integer.";
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

flag ('(jordan_block),'opfn);



symbolic procedure sub_matrix(a,row_list,col_list);
  %
  % Removes the sub_matrix from A consisting of the rows in row_list and
  % the columns in col_list. (Both row_list and col_list can be single
  % integer values).
  %
  begin
    scalar new_mat;
    if not !*fast_la and not matrixp(a) then rederr
     "Error in sub_matrix(first argument): should be a matrix.";
    new_mat := stack_rows(a,row_list);
    new_mat := augment_columns(new_mat,col_list);
    return new_mat;
  end;

flag('(sub_matrix),'opfn);



symbolic procedure copy_into(bb,aa,p,q);
  %
  % Copies matrix BB into AA with BB(1,1) at AA(p,q).
  %
  begin
    scalar a,b;
    integer m,n,r,c;
    if not !*fast_la then
    <<
      if not matrixp(bb) then rederr
       "Error in copy_into(first argument): should be a matrix.";
      if not matrixp(aa) then rederr
       "Error in copy_into(second argument): should be a matrix.";
      if not fixp p then rederr
       "Error in copy_into(third argument): should be an integer.";
      if not fixp q then rederr
       "Error in copy_into(fourth argument): should be an integer.";
      if p = 0 or q = 0 then
      <<
        prin2t
         "***** Error in copy_into: 0 is out of bounds for matrices.";
        prin2t
         "      The top left element is labelled (1,1) and not (0,0).";
        return;
      >>;
    >>;
    m := row_dim(aa);
    n := column_dim(aa);
    r := row_dim(bb);
    c := column_dim(bb);
    if not !*fast_la and (r+p-1>m or c+q-1>n) then
    <<
      % Only print offending matrices if they're not too big.
      if m*n<26 and r*c<26 then
      <<
        prin2t "***** Error in copy_into: the matrix";
        matpri(bb);
        prin2t "      does not fit into";
        matpri(aa);
        prin2  "      at position ";
        prin2 p;
        prin2 ",";
        prin2 q;
        prin2t ".";
        return;
      >>
      else
      <<
        prin2 "***** Error in copy_into: first matrix does not fit ";
        prin2 "      into second matrix at defined position.";
        return;
      >>;
    >>;
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

flag ('(copy_into),'opfn);



symbolic procedure copy_mat(u);
   if pairp u then cons (copy_mat car u, copy_mat cdr u) else u;



put('diagonal,'psopfn,'diagonal1); % To allow variable input.
symbolic procedure diagonal1(mat_list);
  %
  % Can take either a list of arguments or the arguments seperately.
  %
  % Takes any number of either scalar entries or square matrices and
  % creates the diagonal.
  %
  begin
    scalar diag_mat;
    if pairp mat_list and pairp car mat_list and caar mat_list = 'list
     then mat_list := cdar mat_list;
    mat_list := for each elt in mat_list collect reval elt;
    for each elt in mat_list do
    <<
      if matrixp(elt) and not squarep(elt) then
      <<
        % Only print offending matrix if it's not too big.
        if row_dim(elt)<5 or column_dim(elt)> 5 then
        <<
          prin2t "***** Error in diagonal: ";
          matpri(elt);
          prin2t "      is not a square matrix.";
          rederr "";
        >>
        else
         rederr "Error in diagonal: input contains non square matrix.";
      >>;
    >>;
    diag_mat := diag({mat_list});
    return diag_mat;
  end;



symbolic procedure diag(uu);
  %
  % Takes square or scalar matrix entries and creates a matrix with
  % these matrices on the diagonal.
  %
  % What a horrible way to do it!
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
        bigsize:=bigsize+row_dim(arg);
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
        smallsize:= row_dim(arg);
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



symbolic procedure band_matrix(elt_list,sq_size);
  %
  % A square band matrix b is created. The elements of the diagonal
  % are the middle element of elt_list. The elements to the left are
  % used to fill the required number of subdiagonals and the elements
  % to the right the superdiagonals.
  %
  begin
    scalar band_matrix;
    integer i,j,no_elts,middle_pos;
    if not fixp sq_size then rederr
     "Error in band_matrix(second argument): should be an integer.";
    if atom elt_list then elt_list := {elt_list}
     else if car elt_list = 'list then elt_list := cdr elt_list
      else rederr
"Error in band_matrix(first argument): should be single value or list.";
    no_elts := length elt_list;
    if evenp no_elts then rederr
"Error in band matrix(first argument): number of elements must be odd.";
    middle_pos := reval{'quotient,no_elts+1,2};
    if my_reval middle_pos > sq_size then rederr
 "Error in band_matrix: too many elements. Band matrix is overflowing."
     else band_matrix := mkmatrix(sq_size,sq_size);
    for i:=1:sq_size do
    <<
      for j:=1:sq_size do
      <<
        if middle_pos-i+j > 0 and middle_pos-i+j <= no_elts then
        setmat(band_matrix,i,j,nth(elt_list,middle_pos-i+j));
      >>;
    >>;
    return band_matrix;
  end;

flag('(band_matrix),'opfn);



symbolic procedure make_identity(sq_size);
  %
  % Creates identity matrix.
  %
  if not !*fast_la and not fixp sq_size then
   rederr "Error in make_identity: non integer input."
   else 'mat. (for i:=1:sq_size collect
                 for j:=1:sq_size collect if i=j then 1 else 0);

flag('(make_identity),'opfn);



symbolic procedure squarep(in_mat);
  %
  % Tests matrix is square. (boolean).
  %
  begin
    scalar tmp;
    if not !*fast_la and not matrixp(in_mat) then
     rederr "Error in squarep: non matrix input";
    tmp := size_of_matrix(in_mat);
    if first tmp neq second tmp
     then return nil
      else return t;
  end;

flag('(squarep),'boolean);
flag('(squarep),'opfn);



symbolic procedure swap_rows(in_mat,row1,row2);
  %
  % Swaps row1 with rows.
  %
  begin
    scalar new_mat;
    integer rowdim;
    if not !*fast_la then
    <<
      if not matrixp in_mat then
       rederr "Error in swap_rows(first argument): should be a matrix.";
      rowdim := row_dim(in_mat);
      if not fixp row1 then rederr
       "Error in swap_rows(second argument): should be an integer.";
      if not fixp row2 then
     rederr "Error in swap_rows(third argument): should be an integer.";
      if row1>rowdim or row1=0 then rederr
  "Error in swap_rows(second argument): out of range for input matrix.";
      if row2>rowdim or row2=0 then rederr
  "Error in swap_rows(third argument): out of range for input matrix.";
    >>;
    new_mat := copy_mat(in_mat);
    swap_elt(cdr new_mat,row1,row2);
    return new_mat;
  end;



symbolic procedure swap_columns(in_mat,col1,col2);
  %
  % Swaps col1 with col2.
  %
  begin
    scalar new_mat;
    integer coldim;
    if not !*fast_la then
    <<
      if not matrixp in_mat then rederr
       "Error in swap_columns(first argument): should be a matrix.";
      coldim := column_dim(in_mat);
      if not fixp col1 then rederr
       "Error in swap_columns(second argument): should be an integer.";
      if not fixp col2 then rederr
       "Error in swap_columns(third argument): should be an integer.";
      if col1>coldim or col1=0 then rederr
     "Error in swap_columns(second argument): out of range for matrix.";
      if col2>coldim or col2=0 then rederr
"Error in swap_columns(third argument): out of range for input matrix.";
    >>;
    new_mat := copy_mat(in_mat);
    for each row in cdr new_mat do swap_elt(row,col1,col2);
    return new_mat;
  end;



symbolic procedure swap_entries(in_mat,entry1,entry2);
  %
  % Swaps the two entries in in_mat.
  %
  % entry1 and entry2 must be lists of the form
  % {row position,column position}.
  %
  begin
    scalar new_mat;
    integer rowdim,coldim;
    if not matrixp(in_mat) then rederr
     "Error in swap_entries(first argument): should be a matrix.";
    if atom entry1 or car entry1 neq 'list or length cdr entry1 neq 2
     then rederr
"Error in swap_entries(second argument): should be list of 2 elements."
     else entry1 := cdr entry1;
     if atom entry2 or car entry2 neq 'list or length cdr entry2 neq 2
      then rederr
"Error in swap_entries(third argument): should be a list of 2 elements."
      else entry2 := cdr entry2;
    if not !*fast_la then
    <<
      rowdim := row_dim(in_mat);
      coldim := column_dim(in_mat);
      if not fixp car entry1 then
      <<
        prin2  "***** Error in swap_entries(second argument): ";
        prin2t "      first element in list must be an integer.";
        return;
      >>;
      if not fixp cadr entry1 then
      <<
        prin2  "***** Error in swap_entries(second argument): ";
        prin2t "      second element in list must be an integer.";
        return;
      >>;
      if car entry1 > rowdim or car entry1 = 0 then
      <<
        prin2  "***** Error in swap_entries(second argument): ";
        prin2t "      first element is out of range for input matrix.";
      return;
      >>;
      if cadr entry1 > coldim or cadr entry1 = 0 then
      <<
        prin2  "***** Error in swap_entries(second argument): ";
        prin2t "      second element is out of range for input matrix.";
        return;
      >>;
      if not fixp car entry2 then
      <<
        prin2  "***** Error in swap_entries(third argument): ";
        prin2t "      first element in list must be an integer.";
        return;
      >>;
      if not fixp cadr entry2 then
      <<
        prin2  "***** Error in swap_entries(third argument): ";
        prin2t "      second element in list must be an integer.";
        return;
      >>;
      if car entry2 > rowdim or car entry2 = 0 then
      <<
        prin2  "***** Error in swap_entries(third argument): ";
        prin2t "      first element is out of range for input matrix.";
        return;
      >>;
      if cadr entry2 > coldim then
      <<
        prin2  "***** Error in swap_entries(third argument): ";
        prin2t "      second element is out of range for input matrix.";
        return;
      >>;
    >>;
    new_mat := copy_mat(in_mat);
    setmat(new_mat,car entry1,cadr entry1,
            getmat(in_mat,car entry2,cadr entry2));
    setmat(new_mat,car entry2,cadr entry2,
            getmat(in_mat,car entry1,cadr entry1));
  return new_mat;
  end;

flag('(swap_rows,swap_columns,swap_entries),'opfn);



symbolic procedure get_rows(in_mat,row_list);
  %
  % Input is a matrix and either a single row number or a list of row
  % numbers.
  %
  % Extracts either a single row or a number of rows and returns them
  % in a list of row matrices.
  %
  begin
    integer rowdim,coldim;
    scalar ans,tmp;
    if not matrixp(in_mat) then
     rederr "Error in get_rows(first argument): should be a matrix.";
    if atom row_list then row_list := {row_list}
     else if car row_list = 'list then row_list := cdr row_list
      else
      <<
        prin2  "***** Error in get_rows(second argument): ";
      prin2t "      should be either an integer or a list of integers.";
        return;
      >>;
    rowdim := row_dim(in_mat);
    coldim := column_dim(in_mat);
    for each elt in row_list do
    <<
      if not fixp elt then rederr
       "Error in get_rows(second argument): contains non integer.";
      if elt>rowdim or elt=0 then
      <<
        prin2  "***** Error in get_rows(second argument): ";
        rederr
         "contains row number which is out of range for input matrix.";
      >>;
      tmp := 'mat.{nth(cdr in_mat,elt)};
      ans := append(ans,{tmp});
    >>;
    return 'list.ans;
  end;



symbolic procedure get_columns(in_mat,col_list);
  %
  % Input is a matrix and either a single column number or a list of
  % column numbers.
  %
  % Extracts either a single column or a series of adjacent columns and
  % returns them in a list of column matrices.
  %
  begin
    integer rowdim,coldim;
    scalar ans,tmp;
    if not matrixp(in_mat) then
     rederr "Error in get_columns(first argument): should be a matrix.";
    if atom col_list then col_list := {col_list}
     else if car col_list = 'list then col_list := cdr col_list
      else
      <<
        prin2 "***** Error in get_columns(second argument): ";
        prin2t
         "     should be either an integer or a list of integers.";
        return;
      >>;
    rowdim := row_dim(in_mat);
    coldim := column_dim(in_mat);
    for each elt in col_list do
    <<
      if not fixp elt then rederr
       "Error in get_columns(second argument): contains non integer.";
      if elt>coldim or elt=0 then
      <<
        prin2 "***** Error in get_columns(second argument): ";
        rederr
       "contains column number which is out of range for input matrix.";
      >>;
      tmp := 'mat.for each row in cdr in_mat collect {nth(row,elt)};
      ans := append(ans,{tmp});
    >>;
    return 'list.ans;
  end;

flag('(get_rows,get_columns),'opfn);



symbolic procedure stack_rows(in_mat,row_list);
  %
  % Stacks all rows pointed to in row_list to form a new matrix.
  %
  % row_list can be either an integer or a list of integers.
  %
  begin
    if not !*fast_la and not matrixp in_mat then
     rederr "Error in stack_rows(first argument): should be a matrix.";
    if atom row_list then row_list := {row_list}
     else if car row_list = 'list then row_list := cdr row_list;
    return 'mat.for each elt in row_list collect nth(cdr in_mat,elt);
  end;



symbolic procedure augment_columns(in_mat,col_list);
  %
  % Augments all columns pointed to in col_list to form a new matrix.
  %
  % col_list can be either an integer or a list of integers.
  %
  begin
    if not !*fast_la and not matrixp in_mat then rederr
     "Error in augment_columns(first argument): should be a matrix.";
    if atom col_list then col_list := {col_list}
     else if car col_list = 'list then col_list := cdr col_list;
    return 'mat.for each row in cdr in_mat collect
                for each elt in col_list collect nth(row,elt);
  end;

flag('(stack_rows,augment_columns),'opfn);



symbolic procedure add_rows(in_mat,r1,r2,mult1);
  %
  % Replaces row2 (r2) by mult1*r1 + r2.
  %
  begin
    scalar new_mat;
    integer i,rowdim,coldim;
    coldim := column_dim(in_mat);
    if not !*fast_la then
    <<
      if not matrixp in_mat then
       rederr "Error in add_rows(first argument): should be a matrix.";
      rowdim := row_dim(in_mat);
      if not fixp r1 then
     rederr "Error in add_rows(second argument): should be an integer.";
      if not fixp r2 then
     rederr "Error in add_rows(third argument): should be an integer.";
      if r1>rowdim or r1=0 then rederr
   "Error in add_rows(second argument): out of range for input matrix.";
      if r2>rowdim or r2=0 then rederr
   "Error in add_rows(third argument): out of range for input matrix.";
    >>;
    new_mat := copy_mat(in_mat);
    % Efficiency.
    if (my_reval mult1) = 0 then return new_mat;
    for i:=1:coldim do
     setmat(new_mat,r2,i,reval {'plus,{'times,mult1,
                          getmat(new_mat,r1,i)},getmat(in_mat,r2,i)});
    return new_mat;
  end;



symbolic procedure add_columns(in_mat,c1,c2,mult1);
  %
  % Replaces column2 (c2) by mult1*c1 + c2.
  %
  begin
    scalar new_mat;
    integer i,rowdim,coldim;
    rowdim := row_dim(in_mat);
    if not !*fast_la then
    <<
      if not matrixp in_mat then
     rederr "Error in add_columns(first argument): should be a matrix.";
      coldim := column_dim(in_mat);
      if not fixp c1 then rederr
       "Error in add_columns(second argument): should be an integer.";
      if not fixp c2 then rederr
       "Error in add_columns(third argument): should be an integer.";
      if c1>coldim or c1=0 then rederr
"Error in add_columns(second argument): out of range for input matrix.";
      if c2>rowdim or c2=0 then rederr
 "Error in add_columns(third argument): out of range for input matrix.";
    >>;
    new_mat := copy_mat(in_mat);
    % Why not be efficient.
    if (my_reval mult1) = 0 then return new_mat;
    for i:=1:rowdim do
      setmat(new_mat,i,c2,{'plus,{'times,mult1,getmat(new_mat,i,c1)},
                           getmat(in_mat,i,c2)});
    return new_mat;
  end;

flag('(add_rows,add_columns),'opfn);



symbolic procedure add_to_rows(in_mat,row_list,value);
  %
  % Adds value to each element in each row in row_list.
  %
  % row_list can be either an integer or a list of integers.
  %
  begin
    scalar new_mat;
    integer i,rowdim,coldim;
    if not matrixp in_mat then
     rederr "Error in add_to_row(first argument): should be a matrix.";
    if atom row_list then row_list := {row_list}
     else if car row_list = 'list then row_list := cdr row_list
      else
      <<
        prin2  "***** Error in add_to_rows(second argument): ";
        prin2t "      should be either integer or a list of integers.";
        return;
      >>;
    rowdim := row_dim(in_mat);
    coldim := column_dim(in_mat);
    new_mat := copy_mat(in_mat);
    for each row in row_list do
    <<
      if not fixp row then rederr
       "Error in add_to_row(second argument): should be an integer.";
      if row>rowdim or row=0 then
      <<
        prin2  "***** Error in add_to_rows(second argument): ";
        rederr "contains row which is out of range for input matrix.";
      >>;
      for i:=1:coldim do
       setmat(new_mat,row,i,{'plus,getmat(new_mat,row,i),value});
    >>;
    return new_mat;
  end;



symbolic procedure add_to_columns(in_mat,col_list,value);
  %
  % Adds value to each element in each column in col_list.
  %
  % col_list can be either an integer or a list of integers.
  %
  begin
    scalar new_mat;
    integer i,rowdim,coldim;
    if not matrixp in_mat then rederr
     "Error in add_to_columns(first argument): should be a matrix.";
    if atom col_list then col_list := {col_list}
     else if car col_list = 'list then col_list := cdr col_list
      else
      <<
        prin2  "***** Error in add_to_columns(second argument): ";
        prin2t "      should be either integer or list of integers.";
        return;
      >>;
    rowdim := row_dim(in_mat);
    coldim := column_dim(in_mat);
    new_mat := copy_mat(in_mat);
    for each col in col_list do
    <<
      if not fixp col then rederr
      "Error in add_to_columns(second argument): should be an integer.";
      if col>coldim or col=0 then
      <<
        prin2  "***** Error in add_to_columns(second argument): ";
        rederr
         "contains column which is out of range for input matrix.";
      >>;
      for i:=1:rowdim do
       setmat(new_mat,i,col,{'plus,getmat(new_mat,i,col),value});
    >>;
    return new_mat;
  end;

flag('(add_to_rows,add_to_columns),'opfn);



symbolic procedure mult_rows(in_mat,row_list,mult1);
  %
  % Replaces rows specified in row_list by row * mult1.
  %
  begin
    scalar new_mat;
    integer i,rowdim,coldim;
    if not !*fast_la and not matrixp(in_mat) then
     rederr "Error in mult_rows(first argument): should be a matrix.";
    if atom row_list then row_list := {row_list}
     else if car row_list = 'list then row_list := cdr row_list;
    rowdim := row_dim(in_mat);
    coldim := column_dim(in_mat);
    new_mat := copy_mat(in_mat);
    for each row in row_list do
    <<
      if not !*fast_la and not fixp row then rederr
       "Error in mult_rows(second argument): contains non integer.";
      if not !*fast_la and (row>rowdim or row=0) then
      <<
        prin2  "***** Error in mult_rows(second argument): ";
        rederr "contains row that is out of range for input matrix.";
      >>;
      for i:=1:coldim do
      <<
        setmat(new_mat,row,i,reval {'times,mult1,getmat(in_mat,row,i)});
      >>;
    >>;
    return new_mat;
  end;


symbolic procedure mult_columns(in_mat,column_list,mult1);
  %
  % Replaces columns specified in column_list by column * mult1.
  %
  begin
    scalar new_mat;
    integer i,rowdim,coldim;
    if not !*fast_la and not matrixp(in_mat) then
    rederr "Error in mult_columns(first argument): should be a matrix.";
    if atom column_list then column_list := {column_list}
    else if car column_list = 'list then column_list := cdr column_list;
    rowdim := row_dim(in_mat);
    coldim := column_dim(in_mat);
    new_mat := copy_mat(in_mat);
    for each column in column_list do
    <<
      if not !*fast_la and not fixp column then rederr
       "Error in mult_columns(second argument): contains non integer.";
      if not !*fast_la and (column>coldim or column=0) then
      <<
        prin2  "***** Error in mult_columns(second argument): ";
        rederr "contains column that is out of range for input matrix.";
      >>;
      for i:=1:coldim do
      <<
        setmat(new_mat,i,column,
               reval {'times,mult1,getmat(in_mat,i,column)});
      >>;
    >>;
    return new_mat;
  end;

flag('(mult_rows,mult_columns),'opfn);



%%%%%%%%%%%%%%%%%%%%% matrix_augment/matrix_stack %%%%%%%%%%%%%%%%%%%%%%
put('matrix_augment,'psopfn,'matrix_augment1);
symbolic procedure matrix_augment1(matrices);
  %
  % Takes any number of matrices and joins them horizontally.
  %
  % Can take either a list of matrices or the matrices as seperate
  % arguments.
  %
  begin
    scalar mat_list,new_list,new_row;
    if pairp matrices and pairp car matrices and caar matrices = 'list
     then matrices := cdar matrices;
    if not !*fast_la then
    <<
      mat_list := for each elt in matrices collect reval elt;
      for each elt in mat_list do
        if not matrixp(elt) then
         rederr "Error in matrix_augment: non matrix in input.";
    >>;
    const_rows_test(mat_list);
    for i:=1:row_dim(first mat_list) do
    <<
      new_row := {};
      for each mat1 in mat_list do
       new_row := append(new_row,nth(cdr mat1,i));
      new_list := append(new_list,{new_row});
    >>;
    return 'mat.new_list;
  end;



put('matrix_stack,'psopfn,'matrix_stack1);
symbolic procedure matrix_stack1(matrices);
  %
  % Takes any number of matrices and joins them vertically.
  %
  % Can take either a list of matrices or the matrices as seperate
  % arguments.
  %
  begin
    scalar mat_list,new_list;
    if pairp matrices and pairp car matrices and caar matrices = 'list
     then matrices := cdar matrices;
    if not !*fast_la then
    <<
      mat_list := for each elt in matrices collect reval elt;
      for each elt in mat_list do
       if not matrixp(elt) then
        rederr "Error in matrix_stack: non matrix in input.";
    >>;
    const_columns_test(mat_list);
    for each mat1 in mat_list do new_list := append(new_list,cdr mat1);
    return 'mat.new_list;
  end;




symbolic procedure no_rows(mat_list);
  %
  % Takes list of matrices and sums the no. of rows.
  %
  for each mat1 in mat_list sum row_dim(mat1);




symbolic procedure no_cols(mat_list);
  %
  % Takes list of matrices and sums the no. of columns.
  %
  for each mat1 in mat_list sum column_dim(mat1);



symbolic procedure const_rows_test(mat_list);
  %
  % Tests that each matrix in mat_list has the same number of rows
  % (otherwise augmentation not possible).
  %
  begin
    integer i,listlen,rowdim;
    listlen := length(mat_list);
    rowdim := row_dim(car mat_list);
    i := 1;
    while i<listlen and row_dim(car mat_list) = row_dim(cadr mat_list)
     do << i := i+1; mat_list := cdr mat_list; >>;
    if i=listlen then return rowdim
     else
     <<
       prin2  "***** Error in matrix_augment: ";
       rederr "all input matrices must have the same row dimension.";
     >>;
  end;



symbolic procedure const_columns_test(mat_list);
  %
  % Tests that each matrix in mat_list has the same number of columns
  % (otherwise stacking not possible).
  %
  begin
    integer i,listlen,coldim;
    listlen := length(mat_list);
    coldim := column_dim(car mat_list);
    i := 1;
    while i<listlen and column_dim(car mat_list) =
                         column_dim(cadr mat_list)
     do << i := i+1; mat_list := cdr mat_list; >>;
    if i=listlen then return coldim
     else
     <<
       prin2  "***** Error in matrix_stack: ";
       rederr
        "all input matrices must have the same column dimension.";
       return;
     >>;
  end;

%%%%%%%%%%%%%%%%%%%% end matrix_augment/matrix_stack %%%%%%%%%%%%%%%%%%%



%%%%%%%%%%%%%%%%%%%%%%%%%%% block_matrix %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure block_matrix(rows,cols,mat_list);
  %
  % Creates a matrix consisting of rows*cols matrices which are taken
  % sequentially from the mat_list.
  %
  begin
    scalar block_mat,row_list;
    integer rowdim,coldim,start_row,start_col,i,j;
    if not fixp rows then rederr
     "Error in block_matrix(first argument): should be an integer.";
    if rows=0 then
    <<
      prin2  "***** Error in block_matrix(first argument): ";
      prin2t "      should be an integer greater than 0.";
      return;
    >>;
    if not fixp cols then rederr
     "Error in block_matrix(second argument): should be an integer.";
    if cols=0 then
    <<
     prin2  "***** Error in block_matrix(second argument): ";
      prin2t "      should be an integer greater than 0.";
      return;
    >>;
    if matrixp mat_list then mat_list := {mat_list}
     else if pairp mat_list and car mat_list = 'list then
     mat_list := cdr mat_list
      else
      <<
        prin2  "***** Error in block_matrix(third argument): ";
        prin2t
        "      should be either a single matrix or a list of matrices.";
        return;
      >>;
    if rows*cols neq length mat_list then rederr
 "Error in block_matrix(third argument): Incorrect number of matrices.";
    row_list := create_row_list(rows,cols,mat_list);
    rowdim := check_rows(row_list);
    coldim := check_cols(row_list);
    block_mat := mkmatrix(rowdim,coldim);
    start_row := 1; start_col := 1;
    for i:=1:length row_list do
    <<
      for j:=1:cols do
      <<
        block_mat := copy_into(nth(nth(row_list,i),j),block_mat,
                                start_row,start_col);
        start_col := start_col + column_dim(nth(nth(row_list,i),j));
      >>;
      start_col := 1;
      start_row := start_row + row_dim(nth(nth(row_list,i),1));
    >>;
    return block_mat;
  end;

flag('(block_matrix),'opfn);



symbolic procedure create_row_list(rows,cols,mat_list);
  %
  % Takes mat_list and creates a list of rows elements each of which is
  % a list containing cols elements (ordering left to right).
  % eg: create_row_list(3,2,{a,b,c,d,e,f}) will return
  %     {{a,b},{c,d},{e,f}}.
  %
  begin
    scalar row_list,tmp_list;
    integer i,j,increment;
    increment := 1;
    for i:=1:rows do
    <<
      tmp_list := {};
      for j:=1:cols do
      <<
        tmp_list := append(tmp_list,{nth(mat_list,increment)});
        increment := increment + 1;
      >>;
      row_list := append(row_list,{tmp_list});
    >>;
    return row_list;
  end;



symbolic procedure check_cols(row_list);
  %
  % Checks each element in row_list has same number of columns.
  % Returns this number.
  %
  begin
    integer i,listlen;
    i := 1;
    listlen := length(row_list);
    while i<listlen
    and no_cols(nth(row_list,i)) = no_cols(nth(row_list,i+1))
     do i:=i+1;
    if i=listlen then return no_cols(nth(row_list,i))
     else
     <<
       prin2
        "***** Error in block_matrix: column dimensions of matrices ";
       prin2t "      into block_matrix are not compatible";
       return;
     >>;
  end;



symbolic procedure check_rows(row_list);
  %
  % Checks all matrices in each element in row_list contains same
  % amount of rows.
  % Returns the sum of all of these row numbers (ie: number of rows
  % required in the block matrix).
  %
  begin
    integer i,listlen,rowdim,eltlen,j;
    i := 1;
    listlen := length(row_list);
    while i<=listlen do
    <<
      eltlen := length nth(row_list,i);
      j := 1;
      while j<eltlen do
      <<
        if row_dim(nth(nth(row_list,i),j)) =
            row_dim(nth(nth(row_list,i),j+1)) then j := j+1
         else
         <<
           prin2  "***** Error in block_matrix: row dimensions of ";
           rederr "matrices into block_matrix are not compatible";
         >>;
      >>;
      rowdim := rowdim + row_dim(nth(nth(row_list,i),j));
      i := i+1;
    >>;
    return rowdim;
  end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%% end block_matrix %%%%%%%%%%%%%%%%%%%%%%%%%%


put('vandermonde,'psopfn,'vandermonde1);
symbolic procedure vandermonde1(variables);
  %
  % Input can be either a list or individual arguments.
  %
  % Creates the Vandermonde matrix.
  % ie: the square matrix in which the (i,j)'th entry is
  %     nth(variables,i)^(j-1).
  %
  begin
    scalar vand,in_list;
    integer i,j,sq_size;
    if pairp variables and pairp car variables
        and caar variables = 'list then variables := cdar variables;
    in_list := for each elt in variables collect my_reval elt;
    sq_size := length in_list;
    vand := mkmatrix(sq_size,sq_size);
    for i:=1:sq_size do
    <<
      for j:=1:sq_size do
      <<
        setmat(vand,i,j,
               reval{'expt,nth(in_list,i),{'plus,j,{'minus,1}}});
      >>;
    >>;
    return vand;
  end;



put('toeplitz,'psopfn,'toeplitz1);
symbolic procedure toeplitz1(variables);
  %
  % Input can be either a list or individual arguments.
  %
  % Creates the Toeplitz matrix.
  % ie: the square matrix in which the first element is placed on the
  % diagonal and the nth(variables,i) element is placed on the (i-1)
  % sub and super diagonals.
  %
  begin
    scalar toep,in_list;
    integer i,j,sq_size;
    if pairp variables and pairp car variables
        and caar variables = 'list then variables := cdar variables;
    in_list := for each elt in variables collect my_reval elt;
    sq_size := length in_list;
    toep := mkmatrix(sq_size,sq_size);
    for i:=1:sq_size do
    <<
      for j:=0:i-1 do
      <<
        setmat(toep,i,i-j,nth(in_list,j+1));
        setmat(toep,i-j,i,nth(in_list,j+1));
      >>;
    >>;
    return toep;
  end;

%%%%%%%%%%%%%%%%%%%%%%%%% kronecker_product %%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure kronecker_product(aa,bb);
  %
  % Copies matrix BB into AA with BB(1,1) at AA(p,q).
  %
  begin
    scalar a,b; integer m,n,r,c;
    if not !*fast_la then
    <<
      if not matrixp(aa) then rederr
     "Error in kronecker_product (first argument): should be a matrix.";
      if not matrixp(bb) then rederr
    "Error in kronecker_product (second argument): should be a matrix.";
    >>;
    m := row_dim(aa);
    n := column_dim(aa);
    r := row_dim(bb);
    c := column_dim(bb);

    a := mkmatrix(m*r,n*c);
    for i:=1:m do
     for j:=1:n do <<
         b := getmat(aa,i,j);
         for ii:=1:c do
           for jj := 1 : r do
                setmat(a,(i-1)*r+jj,(j-1)*c+ii,
                   reval list('times,b, getmat(bb,jj,ii)));
                >>;
    return a;
  end;

flag('(kronecker_product),'opfn);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% minor %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure minor(in_mat,row,col);
  %
  % Removes row (row) and column (col) from in_mat.
  %
  begin
    scalar min;
    if not !*fast_la then
    <<
      if not matrixp(in_mat) then
       rederr "Error in minor(first argument): should be a matrix.";
      if not fixp row then
       rederr "Error in minor(second argument): should be an integer.";
      if row>row_dim(in_mat) or row=0 then rederr
      "Error in minor(second argument): out of range for input matrix.";
      if not fixp col then
       rederr "Error in minor(third argument): should be an integer.";
      if col>column_dim(in_mat) or col=0 then rederr
      "Error in minor(second argument): out of range for input matrix.";
    >>;
    min := remove_rows(in_mat,row);
    min := remove_columns(min,col);
    return min;
  end;



symbolic procedure remove_rows(in_mat,row_list);
  %
  % Removes each row in row_list from in_mat.
  %
  % row_list can be either an integer or a list of integers.
  %
  begin
    scalar unique_row_list,new_list;
    integer rowdim,row;
    if not !*fast_la and not matrixp(in_mat) then
     rederr "Error in remove_rows(first argument): non matrix input.";
    if atom row_list then row_list := {row_list}
     else if car row_list = 'list then row_list := cdr row_list
      else
      <<
        prin2  "***** Error in remove_rows(second argument): ";
        prin2t
         "      should be either an integer or a list of integers.";
        return;
      >>;
    % Remove any repititions in row_list (I'm assuming here that if the
    % user has inputted the same row more than once then the meaning
    % is to only remove that row once).
    unique_row_list := {};
    for each row in row_list do
    <<
      if not intersection({row},unique_row_list) then
       unique_row_list := append(unique_row_list,{row});
    >>;
    rowdim := row_dim(in_mat);
    if not !*fast_la then
    <<
      for each row in unique_row_list do if not fixp row then rederr
       "Error in remove_rows(second argument): contains a non integer.";
%      rowdim := row_dim(in_mat);
%      coldim := column_dim(in_mat);
      for each row in unique_row_list do if row>rowdim or row=0 then
       rederr
"Error in remove_rows(second argument): out of range for input matrix.";
      if length unique_row_list = rowdim then
      <<
        prin2  "***** Warning in remove_rows:";
        prin2t "      all the rows have been removed. Returning nil.";
        return nil;
      >>;
    >>;
    for row:=1:rowdim do if not intersection({row},unique_row_list)
     then new_list := append(new_list,{nth(cdr in_mat,row)});
    return 'mat.new_list;
  end;




symbolic procedure remove_columns(in_mat,col_list);
  %
  % Removes each column in col_list from in_mat.
  %
  % col_list can be either an integer or a list of integers.
  %
  begin
    scalar unique_col_list,new_list,row_list;
    integer coldim,row,col;
    if not !*fast_la and not matrixp(in_mat) then rederr
     "Error in remove_columns(first argument): non matrix input.";
    if atom col_list then col_list := {col_list}
     else if car col_list = 'list then col_list := cdr col_list
      else
      <<
        prin2  "***** Error in remove_columns(second argument): ";
        prin2t
         "      should be either an integer or a list of integers.";
        return;
      >>;

    % Remove any repititions in col_list (I'm assuming here that if the
    % user has inputted the same column more than once then the meaning
    % is to only remove that column once).
    unique_col_list := {};
    for each col in col_list do
    <<
      if not intersection({col},unique_col_list) then
       unique_col_list := append(unique_col_list,{col});
    >>;
    coldim := column_dim(in_mat);
    if not !*fast_la then
    <<
      for each col in unique_col_list do if not fixp col then rederr
    "Error in remove_columns(second argument): contains a non integer.";
      for each col in unique_col_list do if col>coldim or col=0 then
       rederr
   "Error in remove_columns(second argument): out of range for matrix.";
      if length unique_col_list = coldim then
      <<
        prin2  "***** Warning in remove_columns: ";
       prin2t "      all the columns have been removed. Returning nil.";
        return nil;
      >>;
    >>;
    for each row in cdr in_mat do
    <<
      row_list := {};
      for col:=1:coldim do
      <<
        if not intersection({col},unique_col_list)
         then row_list := append(row_list,{nth(row,col)});
      >> ;
      new_list := append(new_list,{row_list});
    >>;
    return 'mat.new_list;
  end;

flag('(minor,remove_rows,remove_columns),'opfn);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% end  minor %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



%%%%%%%%%%%%%%%%% begin random_matrix/im_random_matrix %%%%%%%%%%%%%%%%%

switch imaginary;     % If ON, then random_matrix creates a random
                      % matrix with imaginary entries.

switch not_negative;  % If ON, then the random matrix functions create
                      % matrices with only positive entries. In the
                      % imaginary case, each entry x+iy will have x and
                      % y both > 0. Not that this really means a great
                      % deal mathematically apart from each guy sitting
                      % right up there in the top right hand corner of
                      % the argand plane but oh well.

switch only_integer;  % If ON, then the random matrix functions will
                      % create matrices with only integer entries. In
                      % the imaginary case, each entry x+iy will have
                      % x and y as integers.

switch symmetric;     % If ON, random matrix is symmetric.

switch upper_matrix;  % If ON, then the random matrix is an upper
                      % triagonal matrix.

switch lower_matrix;  % If ON, then the random matrix is a lower
                      % triagonal matrix.



symbolic smacro procedure random_minus(limit);
  %
  % Creates random number in the range -limit < number < limit.
  %
  if evenp random(1000) then {'minus,random(limit)} else random(limit);



symbolic smacro procedure random_make_minus(u);
  %
  % Randomly makes u negative.
  %
  if evenp random(1000) then {'minus,u} else u;



symbolic procedure random_matrix(rowdim,coldim,limit);
  %
  % Creates an rowdim by coldim matrix with random entries in the bound
  % -limit < entry < limit.
  %
  begin
    scalar randmat,random_decimal;
    integer i,j,start,current_precision;
    if !*lower_matrix and !*upper_matrix then
    <<
      prin2  "***** Error in random matrix: ";
     prin2t "      both upper_matrix and lower_matrix switches are on.";
      return;
    >>;
    if !*upper_matrix and !*symmetric then
    <<
      prin2  "***** Error in random_matriix: ";
      prin2t "      both upper_matrix and symmetric switches are on.";
      return;
    >>;
    if !*lower_matrix and !*symmetric then
    <<
      prin2  "***** Error in random_matrix: ";
      prin2t "      both lower_matrix and symmetric switches are on.";
      return;
    >>;
    if not fixp limit then limit := algebraic floor(abs(limit));
    if not fixp rowdim then rederr
     "Error in random_matrix(first argument): should be an integer.";
    if rowdim=0 then rederr
  "Error in random_matrix(first argument): should be integer > than 0.";
    if not fixp coldim then rederr
     "Error in random_matrix(second argument): should be an integer.";
    if coldim=0 then
    <<
      prin2  "***** Error in random_matrix(second argument): ";
      prin2t "      should be an integer greater than 0.";
      return;
    >>;
    current_precision := precision 0;
    if !*imaginary then randmat := im_random_matrix(rowdim,coldim,limit)
    else
    <<
      start := 1;
      randmat := mkmatrix(rowdim,coldim);
      for i:=1:rowdim do
     <<
        if !*symmetric or !*lower_matrix then coldim := i
        else if !*upper_matrix then start := i;
        for j:=start:coldim do
        <<
          random_decimal := {'plus,random(limit),{'quotient,
                             random(10^current_precision),
                             10^current_precision}};
          if !*only_integer and !*not_negative then
          setmat(randmat,i,j,random(limit))
           else if !*only_integer then
           setmat(randmat,i,j,random_minus(limit))
            else if !*not_negative then
            setmat(randmat,i,j,random_decimal)
             else setmat(randmat,i,j,random_make_minus(random_decimal));
          if !*symmetric then setmat(randmat,j,i,getmat(randmat,i,j));
        >>;
      >>;
    >>;
    return randmat;
  end;

flag('(random_matrix),'opfn);



symbolic procedure im_random_matrix(rowdim,coldim,limit);
  %
  % Creates an rowdim by coldim matrix with random imaginary entries.
  % The entrirs are of the form x+iy where x and y are in the bound
  % -limit < x,y < limit.
  %
  begin
    scalar randmat,random_decimal,im_random_decimal;
    integer i,j,start,current_precision;
    start := 1;
    current_precision := precision 0;
    randmat := mkmatrix(rowdim,coldim);
    for i:=1:rowdim do
    <<
      if !*symmetric or !*lower_matrix then coldim := i
       else if !*upper_matrix then start := i;
      for j:=start:coldim do
      <<
        random_decimal := {'plus,random(limit),{'quotient,
                            random(10^current_precision),
                            10^current_precision}};
        im_random_decimal := {'plus,random(limit),{'quotient,
                               random(10^current_precision),
                               10^current_precision}};
        if !*only_integer and !*not_negative then
        setmat(randmat,i,j,{'plus,random(limit),
                            {'times,'i,random(limit)}})
         else if !*only_integer then
         setmat(randmat,i,j,{'plus,random_minus(limit),
                             {'times,'i,random_minus(limit)}})
          else if !*not_negative then
          setmat(randmat,i,j,{'plus,random_decimal,
                          {'times,'i,im_random_decimal}})
           else
           setmat(randmat,i,j,{'plus,random_make_minus(random_decimal),
                               {'times,'i,
                                random_make_minus(im_random_decimal)}});
        if !*symmetric then setmat(randmat,j,i,getmat(randmat,i,j));
      >>;
    >>;
    return randmat;
  end;

flag('(im_random_matrix),'opfn);


%%%%%%%%%%%%%%%%%% end random_matrix/im_random_matrix %%%%%%%%%%%%%%%%%%



symbolic procedure extend(in_mat,rows,cols,entry);
  %
  % Extends in_mat by rows rows (!) and cols columns. New entries are
  % initialised to entry.
  %
  begin
    scalar ex_mat;
    integer rowdim,coldim,i,j;
    if not matrixp(in_mat) then
     rederr "Error in extend(first argument): should be a matrix.";
    if not fixp rows then
     rederr "Error in extend(second argument): should be an integer.";
    if not fixp cols then
     rederr "Error in extend(third argument): should be an integer.";
    rowdim := row_dim(in_mat);
    coldim := column_dim(in_mat);
    ex_mat := mkmatrix(rowdim+rows,coldim+cols);
    ex_mat := copy_into(in_mat,ex_mat,1,1);
    for i:=1:rowdim+rows do
    <<
      for j:=1:coldim+cols do
      <<
        if i<=rowdim and j<=coldim then <<>>
        else setmat(ex_mat,i,j,entry);
      >>;
    >>;
    return ex_mat;
  end;

flag('(extend),'opfn);



%%%%%%%%%%%%%%%%%%%%% begin char_matrix/char_poly %%%%%%%%%%%%%%%%%%%%%%

symbolic procedure char_matrix(in_mat,lmbda);
  %
  % Create characteristic matrix. ie: C := lmbda*I - in_mat.
  % in_ mat must be square.
  %
  begin
    scalar carmat;
    integer rowdim;
    if not matrixp(in_mat) then
     rederr "Error in char_matrix(first argument): should be a matrix.";
    if not squarep(in_mat) then rederr
     "Error in char_matrix(first argument): must be a square matrix.";
    rowdim := row_dim(in_mat);
    carmat := {'plus,{'times,lmbda,make_identity(rowdim)},
               {'minus,in_mat}};
    return carmat;
  end;



symbolic procedure char_poly(in_mat,lmbda);
  %
  % Finds characteristic polynomial of matrix in_mat.
  % ie: det(lmbda*I - in_mat).
  %
  begin
    scalar chpoly,carmat;
    if not matrixp(in_mat) then
     rederr "Error in char_poly(first argument): should be a matrix.";
    carmat := char_matrix(in_mat,lmbda);
    chpoly := algebraic det(carmat);
    return chpoly;
  end;

flag('(char_matrix,char_poly),'opfn);

%%%%%%%%%%%%%%%%%%%%%%%% end char_matrix/char_poly %%%%%%%%%%%%%%%%%%%%%



%%%%%%%%%%%%%%%%%%%%%%%%%% begin pivot/rows_pivot %%%%%%%%%%%%%%%%%%%%%%

symbolic procedure pivot(in_mat,pivot_row,pivot_col);
  %
  % Converts all elements in pivot column (apart from the one in pivot
  % row) to 0.
  %
  begin
    scalar piv_mat,ratio;
    integer i,j,rowdim,coldim;
    if not !*fast_la and not matrixp(in_mat) then
     rederr "Error in pivot(first argument): should be a matrix.";
    rowdim := row_dim(in_mat);
    coldim := column_dim(in_mat);
    if not !*fast_la then
    <<
    if not fixp pivot_row then
     rederr "Error in pivot(second argument): should be an integer.";
    if pivot_row>rowdim or pivot_row=0 then rederr
     "Error in pivot(second argument): out of range for input matrix.";
    if not fixp pivot_col then rederr
     "Error in pivot(third argument): should be an integer.";
    if pivot_col>coldim or pivot_col=0 then rederr
     "Error in pivot(third argument): out of range for input matrix.";
    if getmat(in_mat,pivot_row,pivot_col) = 0 then
     rederr "Error in pivot: cannot pivot on a zero entry.";
    >>;
    piv_mat := copy_mat(in_mat);
    piv_mat := copy_mat(in_mat);
    for i:=1:rowdim do
    <<
      for j:=1:coldim do
      <<
        if i = pivot_row then <<>>
        else
        <<
           ratio := {'quotient,getmat(in_mat,i,pivot_col),
                     getmat(in_mat,pivot_row,pivot_col)};
           setmat(piv_mat,i,j,{'plus,getmat(in_mat,i,j),{'minus,
                  {'times,ratio,getmat(in_mat,pivot_row,j)}}});
        >>;
      >>;
    >>;
    return piv_mat;
  end;



symbolic procedure rows_pivot(in_mat,pivot_row,pivot_col,row_list);
  %
  % Same as pivot but only rows a .. to .. b, where row_list = {a,b},
  % are changed.
  %
  % rows_pivot will work if row_list is just an integer.
  %
  begin
    scalar piv_mat,ratio;
    integer j,rowdim,coldim;
    rowdim := row_dim(in_mat);
    coldim := column_dim(in_mat);
    if not !*fast_la then
    <<
      if not matrixp(in_mat) then
      rederr "Error in rows_pivot(first argument): should be a matrix.";
      rowdim := row_dim(in_mat);
      coldim := column_dim(in_mat);
      if not fixp pivot_row then
       rederr "Error in pivot(second argument): should be an integer.";
      if pivot_row>rowdim or pivot_row=0 then rederr
 "Error in rows_pivot(second argument): out of range for input matrix.";
      if not fixp pivot_col then
       rederr "Error in pivot(third argument): should be an integer.";
      if pivot_col>coldim or pivot_col=0 then rederr
  "Error in rows_pivot(third argument): out of range for input matrix.";
    >>;
    if atom row_list then row_list := {row_list}
     else if pairp row_list and car row_list = 'list
     then row_list := cdr row_list
      else
      <<
        prin2  "***** Error in rows_pivot(fourth argument): ";
        prin2t
         "      should be either an integer or a list of integers.";
        return;
      >>;
    if getmat(in_mat,pivot_row,pivot_col) = 0 then
     rederr "Error in rows_pivot: cannot pivot on a zero entry.";
    piv_mat := copy_mat(in_mat);
    for each elt in row_list do
    <<
      if not !*fast_la then
      <<
        if not fixp elt then rederr
         "Error in rows_pivot: fourth argument contains a non integer.";
        if elt>rowdim or elt=0 then
        <<
          prin2  "***** Error in rows_pivot(fourth argument): ";
          rederr "contains row which is out of range for input matrix.";
        >>;
      >>;
      for j:=1:coldim do
      <<
        if elt = pivot_row then <<>>
        else
        <<
           ratio := {'quotient,getmat(in_mat,elt,pivot_col),
                     getmat(in_mat,pivot_row,pivot_col)};
           setmat(piv_mat,elt,j,{'plus,getmat(in_mat,elt,j),{'minus,
                  {'times,ratio,getmat(in_mat,pivot_row,j)}}});
        >>;
      >>;
    >>;
    return piv_mat;
  end;

flag('(pivot,rows_pivot),'opfn);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% end pivot/rows_pivot %%%%%%%%%%%%%%%%%%%%%



symbolic procedure jacobian(exp_list,var_list);
  %
  % jacobian(exp,var) computes the Jacobian matrix of exp w.r.t. var.
  % The (i,j)'th entry is diff(nth(exp,i),nth(var,j)).
  %
  begin
    scalar jac,exp1,var1;
    integer i,j,rowdim,coldim;
    if atom exp_list then exp_list := {exp_list}
     else if car exp_list neq 'list then rederr
     "Error in jacobian(first argument): expressions must be in a list."
      else exp_list := cdr exp_list;
    if atom var_list then var_list := {var_list}
     else if car var_list neq 'list then rederr
      "Error in jacobian(second argument): variables must be in a list."
      else var_list := cdr var_list;
    rowdim := length exp_list;
    coldim := length var_list;
    jac := mkmatrix(rowdim,coldim);
    for i:=1:rowdim do
    <<
      for j:=1:coldim do
      <<
        exp1 := nth(exp_list,i);
        var1 := nth(var_list,j);
        setmat(jac,i,j,algebraic df(exp1,var1));
      >>;
    >>;
    return jac;
  end;

flag('(jacobian),'opfn);



symbolic procedure hessian(poly,variables);
  %
  % variables can be either a list or a single variable.
  %
  % A Hessian matrix is a matrix whose (i,j)'th entry is
  %       df(df(poly,nth(var,i)),nth(var,j))
  %
  % where df is the derivative.
  %
  begin
    scalar hess_mat,part1,part2,elt;
    integer row,col,sq_size;
    if atom variables then variables := {variables}
     else if car variables = 'list then variables := cdr variables
      else
      <<
        prin2  "***** Error in hessian(second argument): ";
        prin2t
     "      should be either a single variable or a list of variables.";
        return;
      >>;
    sq_size := length variables;
    hess_mat := mkmatrix(sq_size,sq_size);
    for row:=1:sq_size do
    <<
      for col:=1:sq_size do
      <<
        part1 := nth(variables,row);
        part2 := nth(variables,col);
        elt := algebraic df(df(poly,part1),part2);
        setmat(hess_mat,row,col,elt);
      >>;
    >>;
    return hess_mat;
  end;

flag('(hessian),'opfn);



symbolic procedure hermitian_tp(in_mat);
  %
  % Computes the Hermitian transpose (HT say) of in_mat.
  %
  % The (i,j)'th element of HT = conjugate of the (j,i)'th element of
  % in__mat.
  %
  begin
    scalar h_tp,element;
    integer row,col;
    if not matrixp(in_mat) then
     rederr "Error in hermitian_tp: non matrix input.";
    h_tp := algebraic tp(in_mat);
    for row:=1:row_dim(h_tp) do
    <<
      for col:=1:column_dim(h_tp) do
      <<
        element := getmat(h_tp,row,col);
        setmat(h_tp,row,col,
               algebraic (repart(element) - i*impart(element)));
      >>;
    >>;
    return h_tp;
  end;

flag('(hermitian_tp),'opfn);



symbolic procedure hilbert(sq_size,value);
  %
  % The Hilbert matrix is symmetric and the (i,j)'th entry in
  % 1/(i+j-x).
  %
  begin
    scalar hil_mat,denom;
    integer row,col;
    if not fixp sq_size or sq_size<1 then rederr
     "Error in hilbert(first argument): must be a positive integer.";
    hil_mat := mkmatrix(sq_size,sq_size);
    for row:=1:sq_size do
    <<
      for col:=1:sq_size do
      <<
        if (denom := reval{'plus,row,col,{'minus,value}}) = 0 then
         rederr "Error in hilbert: division by zero."
         else setmat(hil_mat,row,col,{'quotient,1,denom});
      >>;
    >>;
    return hil_mat;
  end;

flag('(hilbert),'opfn);



%%%%%%%%%%%%%%%%%%%%%%%% begin coeff_matrix  %%%%%%%%%%%%%%%%%%%%%%%%%%%

put('coeff_matrix,'psopfn,'coeff_matrix1); % To allow variable input.
symbolic procedure coeff_matrix1(equation_list);
  %
  % Given the system of linear equations, coeff_matrix returns {A,X,b}
  % s.t. AX = b.
  %
  % Input can be either a list of linear equations or the linear
  % equations as individual arguments.
  %
  begin
    scalar variable_list,a,x,b;
    if pairp car equation_list and caar equation_list = 'list then
     equation_list := cdar equation_list;
    equation_list := remove_equals(equation_list);
    variable_list := get_variable_list(equation_list);
    if variable_list = nil then
     rederr "Error in coeff_matrix: no variables in input.";
    check_linearity(equation_list,variable_list);
    a := get_a(equation_list,variable_list);
    x := get_x(variable_list);
    b := get_b(equation_list,variable_list);
    return {'list,a,x,b};
  end;



symbolic procedure remove_equals(equation_list);
  %
  % If any of the equations are equalities the equalities are removed
  % to leave a list of polynomials.
  %
  begin
     equation_list := for each equation in equation_list collect
      if pairp equation and car equation = 'equal then
       reval{'plus,cadr equation,{'minus,caddr equation}}
        else equation;
     return equation_list;
  end;



symbolic procedure get_variable_list(equation_list);
  %
  % Gets hold of all variables from the equations in equation_list.
  %
  begin
    scalar variable_list;
    for each equation in equation_list do
     variable_list := union(get_coeffs(equation),variable_list);
    return reverse variable_list;
  end;



symbolic procedure check_linearity(equation_list,variable_list);
  %
  % Checks that we really are dealing with a system of linear equations.
  %
  for each equation in equation_list do
  <<
    for each variable in variable_list do
    <<
      if deg(equation,variable) > 1 then
       rederr "Error in coeff_matrix: the equations are not linear.";
    >>;
  >>;



symbolic procedure get_a(equation_list,variable_list);
  begin
    scalar a,element,var_elt;
    integer row,col,length_equation_list,length_variable_list;
    length_equation_list := length equation_list;
    length_variable_list := length variable_list;
    a := mkmatrix(length equation_list,length variable_list);
    for row:=1:length_equation_list do
    <<
      for col:=1:length_variable_list do
      <<
        element := nth(equation_list,row);
        var_elt := nth(variable_list,col);
        setmat(a,row,col,algebraic coeffn(element,var_elt,1));
      >>;
    >>;
    return a;
  end;



symbolic procedure get_b(equation_list,variable_list);
  %
  % Puts the integer parts of all the equations into a column matrix.
  %
  begin
    scalar substitution_list,integer_list,b;
    integer length_integer_list,row;
    substitution_list :=
     'list.for each variable in variable_list collect
                                               {'equal,variable,0};
    integer_list := for each equation in equation_list collect
      algebraic sub(substitution_list,equation);
    length_integer_list := length integer_list;
    b := mkmatrix(length_integer_list,1);
    for row:=1:length_integer_list do
     setmat(b,row,1,-nth(integer_list,row));
    return b;
  end;



symbolic procedure get_x(variable_list);
  begin
    scalar x;
    integer row,length_variable_list;
    length_variable_list := length variable_list;
    x := mkmatrix(length_variable_list,1);
    for row := 1:length variable_list do
     setmat(x,row,1,nth(variable_list,row));
    return x;
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

%%%%%%%%%%%%%%%%%%%%%%%%%% end coeff_matrix  %%%%%%%%%%%%%%%%%%%%%%%%%%%

% Smacro used in other modules.

symbolic smacro procedure my_revlis(u);
  %
  % As my_reval but for lists.
  %
  for each j in u collect my_reval(j);



endmodule;  %linear algebra.


module lmatrix;

%**********************************************************************%
%                                                                      %
% This module forms the ability for matrices to be passed locally.     %
%                                                                      %
% Authors: W. Neun (customised by Matt Rebbeck).                       %
%                                                                      %
%**********************************************************************%

switch mod_was_on;  % Used internally to keep track of the modular
                    % switch.


symbolic procedure mkmatrix(n,m);
  %
  % Create an nXm matrix.
  %
   'mat . (for i:=1:n collect
           for j:=1:m collect 0);



symbolic procedure setmat(matri,i,j,val);
  %
  % Set matrix element (i,j) to val.
  %
  <<   if !*modular then << off modular; on mod_was_on; >>;
       i := my_reval i;
       j := my_reval j;
       my_letmtr(list(matri,i,j),val,matri);
       if !*mod_was_on then << on modular; off mod_was_on; >>;
       matri>>;



symbolic procedure getmat(matri,i,j);
  %
  % Get matrix element (i,j).
  %
  <<   if !*modular then << off modular; on mod_was_on; >>;
       i := my_reval i;
       j := my_reval j;
       if !*mod_was_on then << on modular; off mod_was_on; >>;
       unchecked_getmatelem list(matri,i,j)>>;



symbolic procedure unchecked_getmatelem u;
  begin scalar x;
         if not eqcar(x :=  car u,'mat)
          then  rerror(matrix,1,list("Matrix",car u,"not set"))
         else return nth(nth(cdr x,cadr u),caddr u);
   end;



symbolic procedure my_letmtr(u,v,y);
  %
  % Substitution for matrix elements with reval only when necessary.
  %
  begin
    scalar z;
    if not eqcar(y,'mat) then
     rerror(matrix,10,list("Matrix",car u,"not set"))
      else if not numlis (z := my_revlis cdr u) or length z neq 2
       then return errpri2(u,'hold);
    rplaca(pnth(nth(cdr y,car z),cadr z),v);
  end;


endmodule;  % lmatrix.


module gramchmd;

%**********************************************************************%
%                                                                      %
% Computation of the Gram Schmidt Orthonormalisation process. The      %
% input vectors are represented by lists.                              %
%                                                                      %
% Authors: Karin Gatermann (used symbolically in her symmetry package).%
%          Matt Rebbeck (first few lines of code that make it          %
%                        available from the user level).   May 1994.   %
%                                                                      %
%**********************************************************************%



put('gram_schmidt,'psopfn,'gram_schmidt1); % To allow variable input.
symbolic procedure gram_schmidt1(vec_list);
  %
  % Can take a list of lists(which are representing vectors) or any
  % number of arguments each being a list(again which represent the
  % vectors).
  %
  % Karin used lists of standard quotient elements as vectors so a bit
  % of fiddling is required to get the input/output right.
  %
  begin
    scalar gs_list;
    % Deal with the possibility of the user entering a list of lists.
    if pairp vec_list and pairp car vec_list and caar vec_list = 'list
     and pairp cdar vec_list and pairp cadar vec_list
      and caadar vec_list = 'list
       then vec_list := cdar vec_list;
    vec_list := convert_to_sq(vec_list);
    % This bit does all the real work.
    gs_list := gram!+schmid(vec_list);
    return convert_from_sq(gs_list);
  end;



symbolic procedure convert_to_sq(vec_list);
  %
  % Takes algebraic list and converts to sq form for input into
  % GramSchmidt.
  %
  begin
    scalar sq_list;
    sq_list := for each list in vec_list collect
      for each elt in cdr list collect simp!* elt;
    return sq_list;
  end;



symbolic procedure convert_from_sq(sq_list);
  %
  % Converts sq_list to a readable (from algebraic mode) form.
  %
  begin
    scalar gs_list;
    gs_list := 'list.for each elt1 in sq_list collect
                'list.for each elt in elt1 collect prepsq elt;
    return gs_list;
  end;


%
% All the rest is Karin's.
%

symbolic procedure vector!+p(vector1);
  %
  % returns the length of a vector
  % vector -- list of sqs
  %
  begin
    if length(vector1)>0 then return t;
  end;



symbolic procedure get!+vec!+dim(vector1);
  %
  % returns the length of a vector
  % vector -- list of sqs
  %
  begin
    return length(vector1);
  end;



symbolic procedure get!+vec!+entry(vector1,elem);
  %
  % returns the length of a vector
  % vector -- list of sqs
  %
  begin
    return nth(vector1,elem);
  end;



symbolic procedure mk!+vec!+add!+vec(vector1,vector2);
  %
  % returns a vector= vector1+vector2 (internal structure)
  %
  begin
    scalar ent,res,h;
    res:=for ent:=1:get!+vec!+dim(vector1) collect
    <<
      h:= addsq(get!+vec!+entry(vector1,ent),
             get!+vec!+entry(vector2,ent));
      h:=subs2 h where !*sub2=t;
      h
    >>;
    return res;
  end;



symbolic procedure mk!+squared!+norm(vector1);
  %
  % returns a scalar= sum vector_i^2 (internal structure)
  %
  begin
    return mk!+inner!+product(vector1,vector1);
  end;



symbolic procedure my!+nullsq!+p(scal);
  %
  % returns true, if ths sq is zero
  %
  begin
    if null(numr( scal)) then return t;
  end;



symbolic procedure mk!+null!+vec(dimen);
  %
  % returns a vector of zeros
  %
  begin
    scalar nullsq,i,res;
    nullsq:=(nil ./ 1);
    res:=for i:=1:dimen collect nullsq;
    return res;
  end;



symbolic procedure null!+vec!+p(vector1);
  %
  % returns a true, if vector is the zero vector
  begin
    if my!+nullsq!+p(mk!+squared!+norm(vector1)) then return t;
  end;



symbolic procedure mk!+normalize!+vector(vector1);
  %
  % returns a normalized vector (internal structure)
  %
  begin
    scalar scalo,vecres;
    scalo:=simp!* {'sqrt, mk!*sq(mk!+squared!+norm(vector1))};
    if my!+nullsq!+p(scalo) then
     vecres:= mk!+null!+vec(get!+vec!+dim(vector1))
     else
     <<
       scalo:=simp prepsq scalo;
       scalo:=quotsq((1 ./ 1),scalo);
       vecres:= mk!+scal!+mult!+vec(scalo,vector1);
     >>;
    return vecres;
  end;



symbolic procedure mk!+gram!+schmid(vectorlist,vector1);
  %
  % returns a vectorlist of orthonormal vectors
  % assumptions: vectorlist is orthonormal basis, internal structure
  %
  begin
    scalar i,orthovec,scalo,vectors;
    orthovec:=vector1;
    for i:=1:(length(vectorlist)) do
    <<
      scalo:= negsq(mk!+inner!+product(orthovec,nth(vectorlist,i)));
      orthovec:=mk!+vec!+add!+vec(orthovec,
         mk!+scal!+mult!+vec(scalo,nth(vectorlist,i)));
    >>;
    orthovec:=mk!+normalize!+vector(orthovec);
    if null!+vec!+p(orthovec) then vectors:=vectorlist
     else vectors:=add!+vector!+to!+list(orthovec,vectorlist);
    return vectors;
  end;



symbolic procedure gram!+schmid(vectorlist);
  %
  % returns a vectorlist of orthonormal vectors
  %
  begin
    scalar ortholist,i;
    if length(vectorlist)<1
      then rederr "Error in Gram Schmidt: no input.";
    if vector!+p(car vectorlist) then ortholist:=nil
     else rederr "Error in Gram_schmidt: empty input.";
    for i:=1:length(vectorlist) do
     ortholist:=mk!+gram!+schmid(ortholist,nth(vectorlist,i));
    return ortholist;
  end;



symbolic procedure add!+vector!+to!+list(vector1,vectorlist);
  %
  % returns a list of vectors consisting of vectorlist
  % and the vector1 at the end
  % internal structure
  begin
    return append(vectorlist,list(vector1));
  end;



symbolic procedure mk!+inner!+product(vector1,vector2);
  %
  % returns the inner product of vector1 and vector2
  % (internal structure)
  %
  begin
    scalar z,sum,vec2;
    if not(get!+vec!+dim(vector1) = get!+vec!+dim(vector2)) then rederr
   "Error in Gram_schmidt: each list in input must be the same length.";
    sum:=(nil ./ 1);
    if !*complex then vec2:=mk!+conjugate!+vec(vector2)
     else vec2:=vector2;
    for z:=1:get!+vec!+dim(vector1) do
     sum:=addsq(sum,multsq(
            get!+vec!+entry(vector1,z),
            get!+vec!+entry(vec2,z)
                           )
                );
    sum:=subs2 sum where !*sub2=t;
    return sum;
  end;



symbolic procedure mk!+scal!+mult!+vec(scal1,vector1);
  %
  % returns a vector= scalar*vector (internal structure)
  %
  begin
    scalar entry,res,h;
    res:=for each entry in vector1 collect
    <<
      h:=multsq(scal1,entry);
      h:=subs2 h where !*sub2=t;
      h
    >>;
    return res;
  end;


endmodule;  % gram_schmidt.


module lu_decom;

%**********************************************************************%
%                                                                      %
% Computation of the LU decomposition of dense unsymmetric matrices    %
% containing either numeric entries or complex numbers with numeric    %
% coefficients.                                                        %
%                                                                      %
% Author: Matt Rebbeck, June 1994.                                     %
%                                                                      %
% The algorithm was taken from "Linear Algebra" - J.H.Wilkinson        %
%                                                  & C. Reinsch        %
%                                                                      %
%                                                                      %
% NB: By using the same rounded number techniques as used in svd this  %
%     could be made a lot faster.                                      %
%                                                                      %
%**********************************************************************%



%%%%%%%%%%%%%%%%%%%%%%%%%%% begin get_num_part %%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                      %
% This bit of code is used in lu_decom, cholesky, and svd.             %
%                                                                      %

symbolic procedure get_num_part f;
  %
  % When comparing (ie: a < b) we need to get hold of the actual
  % numerical values. That's what this does.
  %
  % Nicked from H. Melenk's gnuplot code.
  %
  if f = 0 then f
   else if numberp f then float f
%   else if f='pi then 3.141592653589793238462643
%   else if f='e then 2.7182818284590452353602987
   else if atom f then f
   else if eqcar(f, '!:rd!:) then
          if atom cdr f then cdr f else bf2flr f
   else if eqcar(f, '!:dn!:) then rdwrap2 cdr f
   else if eqcar(f, 'minus) then
    begin scalar x;
       x := get_num_part cadr f;
       return if numberp x then minus float x else {'minus,x}
    end
   else if eqcar(f,'expt) then rdwrap!-expt f
   else get_num_part car f . get_num_part cdr f;



symbolic procedure rdwrap!-expt f;
% preserve integer second argument.
  if fixp caddr f then {'expt!-int,get_num_part cadr f,caddr f}
   else  {'expt,get_num_part cadr f, get_num_part caddr f};



symbolic procedure rdwrap2 f;
% Convert from domain to LISP evaluable value.
  if atom f then f else float car f * 10^cdr f;



symbolic procedure rdwrap!* f;
% convert a domain element to float.
  if null f then 0.0 else get_num_part f;



symbolic procedure expt!-int(a,b); expt(a,fix b);

%                                                                      %
%                                                                      %
%                                                                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%% end get_num_part %%%%%%%%%%%%%%%%%%%%%%%%%%%



symbolic procedure lu_decom(in_mat);
  %
  % Runs the show!
  %
  begin
    scalar ans,i_turned_rounded_on;
    integer sq_size;
    if not matrixp(in_mat) then
     rederr "Error in lu_decom: non matrix input.";
    if not squarep(in_mat) then
     rederr "Error in lu_decom: input matrix should be square.";
    if not !*rounded then << i_turned_rounded_on := t; on rounded; >>;
    sq_size := first size_of_matrix(in_mat);
    if cx_test(in_mat,sq_size) then ans := compdet(in_mat)
     else ans := unsymdet(in_mat);
    if i_turned_rounded_on then off rounded;
    return ans;
  end;

flag('(lu_decom),'opfn);  % So it can be used from algebraic mode.



symbolic procedure cx_test(in_mat,sq_size);
  %
  % Tests to see if any elts are complex. (boolean).
  %
  begin
    scalar bool,elt;
    integer i,j;
    i := 1;
    while not bool and i<=sq_size do
    <<
      j := 1;
      while not bool and j<=sq_size do
      <<
        elt := getmat(in_mat,i,j);
        if algebraic(impart(elt)) neq 0 then bool := t;
        j := j+1;
      >>;
      i := i+1;
    >>;
    return bool;
  end;

flag('(cx_test),'boolean);



symbolic procedure unsymdet(mat1);
  %
  % LU decomposition is performed on the unsymmetric matrix A.
  % ie: A := LU.
  % The determinant (d1*2^d2) of A is also computed as a by product but
  % has been commented out as it is not necessary. A record of any
  % interchanges made to the rows of A is kept in int_vec[i] (i=1...n)
  % such that the i'th row and the int_vec[i]'th row were interchanged
  % at the i'th step.The procedure will fail if A, modified by rounding
  % errors, is singular or singular within the bounds of the machine
  % accuracy (ie: acc s.t. 1+acc > 1).
  %
  begin
    scalar x,y,in_mat,tmp,int_vec,l,u; %d1,d2,det;
    integer i,j,k,l,n;
    j := 1;
    in_mat := copy_mat(mat1);
    n := first size_of_matrix(in_mat);
    int_vec := mkvect(n-1);
    for i:=1:n do
    <<
      y := innerprod(1,1,n,0,row_vec(in_mat,i,n),row_vec(in_mat,i,n));
      putv(int_vec,i-1,{'quotient,1,{'sqrt,y}});
    >>;
%   d1 := 1;
%   d2 := 0;
    for k:=1:n do
    <<
      l := k;
      x := 0;
      for i:=k:n do
      <<
        y := innerprod(1,1,k-1,{'minus,getmat(in_mat,i,k)},
                       row_vec(in_mat,i,n),col_vec(in_mat,k,n));
        setmat(in_mat,i,k,{'minus,y});
        y := abs(get_num_part(reval{'times,y,getv(int_vec,i-1)}));
        if y>get_num_part(my_reval(x)) then
        <<
          x := y;
          l := i;
        >>;
      >>;
      if l neq k then
      <<
%       d1 := {'minus,d1};
        for j:=1:n do
        <<
          y := getmat(in_mat,k,j);
          setmat(in_mat,k,j,getmat(in_mat,l,j));
          setmat(in_mat,l,j,y);
        >>;
        putv(int_vec,l-1,getv(int_vec,k-1));;
      >>;
      putv(int_vec,k-1,l);
%     d1 := {'times,d1,getmat(in_mat,k,k)};
      if get_num_part(my_reval(x)) <
          get_num_part(reval{'times,8,rd!-tolerance!*}) then rederr
"Error in lu_decom: matrix is singular. LU decomposition not possible.";
%    while abs(get_num_part(reval(d1))) >= 1 do
%    <<
%      d1 := {'times,d1,0.0625};
%      d2 := d2+4;
%    >>;
%   while abs(get_num_part(reval(d1))) < 0.0625 do
%      <<
%        d1 := {'times,d1,16};
%        d2 := d2-4;
%      >>;
      x := {'quotient,{'minus,1},getmat(in_mat,k,k)};
      for j:=k+1:n do
      <<
        y := innerprod(1,1,k-1,{'minus,getmat(in_mat,k,j)},
                       row_vec(in_mat,k,n),col_vec(in_mat,j,n));
        setmat(in_mat,k,j,{'times,x,y});
      >>;
    >>;
    tmp := get_l_and_u(in_mat,n);
    l := first tmp;
    u := second tmp;
    % Compute determinant.
    %det := {'times,d1,{'expt,2,d2}};
    return {'list,l,u,int_vec};
  end;



symbolic procedure innerprod(l,s,u,c1,vec_a,vec_b);
  %
  % This procedure accumulates the sum of products vec_a*vec_b and adds
  % it to the initial value c1.  (ie: the scalar product).
  %
  begin
    scalar s1,d1;
    s1 := c1;
    d1 := s1;
    for k:=l step s until u do
    <<
      s1 := {'plus,s1,{'times,getv(vec_a,k),getv(vec_b,k)}};
      d1 := s1;
    >>;
    return d1;
  end;



symbolic procedure row_vec(in_mat,row_no,length_of);
  %
  % Converts matrix row into vector.
  %
  begin
    scalar row_vec;
    integer i;
    row_vec := mkvect(length_of);
    for i:=1:length_of do putv(row_vec,i,getmat(in_mat,row_no,i));
    return row_vec;
  end;



symbolic procedure col_vec(in_mat,col_no,length_of);
  %
  % Converts matrix column into vector.
  %
  begin
    scalar col_vec;
    integer i;
    col_vec := mkvect(length_of);
    for i:=1:length_of do putv(col_vec,i,getmat(in_mat,i,col_no));
    return col_vec;
  end;



symbolic procedure get_l_and_u(in_mat,sq_size);
  %
  % Takes the combined LU matrix and returns L and U.
  % sq_size is the no of rows (and columns) of in_mat.
  %
  begin
    scalar l,u;
    integer i,j;
    l := mkmatrix(sq_size,sq_size);
    u := mkmatrix(sq_size,sq_size);
    for i:=1:sq_size do
    <<
      for j:=1:i do
      <<
        setmat(l,i,j,getmat(in_mat,i,j));
      >>;
    >>;
    for i:=1:sq_size do
    <<
      setmat(u,i,i,1);
      for j:=i+1:sq_size do
      <<
        setmat(u,i,j,getmat(in_mat,i,j));
      >>;
    >>;
    return {l,u};
  end;



symbolic procedure compdet(mat1);
  %
  % LU decomposition is performed on the complex unsymmetric matrix A.
  % ie: A := LU.
  %
  % The calculation is computed in the nX2n matrix so that the general
  % element is a[i,2j-1]+i*a[i,2j]. A record of any interchanges made
  % to the rows of A is kept in int_vec[i] (i=1...n) such that the i'th
  % row and the int_vec[i]'th row were interchanged at the i'th step.
  % The determinant (detr+i*deti)*2^dete of A is also computed but has
  % been comented out as it is not necessary. The procedure will fail
  % if A, modified by rounding errors, is singular.
  %
  begin
    scalar x,y,in_mat,tmp,int_vec,l,u,p,pp,v,w,z; %detr,deti,dete,det;
    integer i,j,k,l,n;
    if algebraic (det(mat1)) = 0 then rederr
"Error in lu_decom: matrix is singular. LU decomposition not possible.";
    j := 1;
    n := first size_of_matrix(mat1);
    in_mat := im_uncompress(mat1,n);
    int_vec := mkvect(n-1);
    for i:=1:n do
    <<
      putv(int_vec,i-1,innerprod(1,1,n+n,0,row_vec(in_mat,i,n+n),
                                          row_vec(in_mat,i,n+n)));
    >>;
%    detr := 1;
%    deti := 0;
%    dete := 0;
    for k:=1:n do
    <<
      l := k;
      p := k+k;
      pp := p-1;
      z := 0;
      for i:=k:n do
      <<
        tmp := cxinnerprod(1,1,k-1,getmat(in_mat,i,pp),
               getmat(in_mat,i,p),re_row_vec(in_mat,i,n),
               cx_row_vec(in_mat,i,n),col_vec(in_mat,pp,n),
               col_vec(in_mat,p,n));
        x := first tmp;
        y := second tmp;
        setmat(in_mat,i,pp,x);
        setmat(in_mat,i,p,y);
        x := {'quotient,{'plus,{'expt,x,2},{'expt,y,2}},
                   getv(int_vec,i-1)};
        if get_num_part(reval(x))>get_num_part(reval(z)) then
        <<
          z := x;
          l := i;
        >>;
      >>;
      if l neq k then
      <<
%        detr := {'minus,detr};
%        deti := {'minus,deti};
        for j:=n+n step -1 until 1 do
        <<
          z := getmat(in_mat,k,j);
          setmat(in_mat,k,j,getmat(in_mat,l,j));
          setmat(in_mat,l,j,z);
        >>;
        putv(int_vec,l-1,getv(int_vec,k-1));;
      >>;
      putv(int_vec,k-1,l);
      x := getmat(in_mat,k,pp);
      y := getmat(in_mat,k,p);
      z := {'plus,{'expt,x,2},{'expt,y,2}};
%      w := {'plus,{'times,x,detr},{'minus,{'times,y,deti}}};
%      deti := {'plus,{'times,x,deti},{'times,y,detr}};
%      detr :=  w;
%      if abs(get_num_part(reval(detr)))<abs(get_num_part(reval(deti)))
%       then w := deti;
%     if w=0 then rederr{"Matrix ",mat1," is singular. LU decomposition
%                           is not possible."};
%      if abs(get_num_part(reval(x))) >= 1 then
%      <<
%        w := {'times,w,0.0625};
%        detr := {'times,detr,0.0625};
%        deti := {'times,deti,0.0625};
%        dete := {'plus,dete,4};
%      >>;
%      while abs(get_num_part(reval(w))) < 0.0625 do
%      <<
%        w := {'times,w,16};
%        detr := {'times,detr,16};
%        deti := {'times,deti,16};
%        dete := {'plus,dete,-4};
%      >>;
      for j:=k+1:n do
      <<
        p := j+j;
        pp := p-1;
        tmp := cxinnerprod(1,1,k-1,getmat(in_mat,k,pp),
               getmat(in_mat,k,p),re_row_vec(in_mat,k,n),
               cx_row_vec(in_mat,k,n),col_vec(in_mat,pp,n),
               col_vec(in_mat,p,n));
        v := first tmp;
        w := second tmp;
        setmat(in_mat,k,pp,{'quotient,{'plus,{'times,v,x},
               {'times,w,y}},z});
        setmat(in_mat,k,p,{'quotient,{'plus,{'times,w,x},
               {'minus,{'times,v,y}}},z});
      >>;
    >>;
    in_mat := im_compress(in_mat,n);
    tmp := get_l_and_u(in_mat,n);
    l := first tmp;
    u := second tmp;
    % Compute determinant.
    %det := {'times,{'plus,detr,{'times,'i,deti}},{'expt,2,dete}};
    return {'list,l,u,int_vec};
  end;



symbolic procedure cxinnerprod(l,s,u,cr,ci,vec_ar,vec_ai,vec_br,vec_bi);
  %
  % Computes complex innerproduct.
  %
  begin
    scalar h,dr,di;
    h := innerprod(l,s,u,{'minus,cr},vec_ar,vec_br);
    dr := innerprod(l,s,u,{'minus,h},vec_ai,vec_bi);
    h := innerprod(l,s,u,{'minus,ci},vec_ai,vec_br);
    di := {'minus,innerprod(l,s,u,h,vec_ar,vec_bi)};
    return {dr,di};
  end;



symbolic procedure cx_row_vec(in_mat,row_no,length_of);
  %
  % Takes uncompressed matrix and creates a vector consisting of the
  % complex elements of row (row_no).
  %
  begin
    scalar cx_row_vec;
    integer i;
    cx_row_vec := mkvect(length_of);
    for i:=1:length_of do putv(cx_row_vec,i,getmat(in_mat,row_no,2*i));
    return cx_row_vec;
  end;



symbolic procedure re_row_vec(in_mat,row_no,length_of);
  %
  % Takes uncompressed matrix and creates a vector consisting of the
  % real elements of row (row_no).
  %
  begin
    scalar re_row_vec;
    integer i;
    re_row_vec := mkvect(length_of);
    for i:=1:length_of do
     putv(re_row_vec,i,getmat(in_mat,row_no,2*i-1));
    return re_row_vec;
  end;



symbolic procedure im_uncompress(in_mat,n);
  %
  % Takes square(nXn) matrix containing imaginary elements and creates
  % a new nX2n matrix s.t. in_mat(i,j) is cx_mat(i,2j-1)+i*cx_mat(i,2j).
  %
  begin
    scalar cx_mat,tmp;
    integer i,j;
    cx_mat := mkmatrix(n,2*n);
    for i:=1:n do
    <<
      for j:=1:n do
      <<
        tmp := getmat(in_mat,i,j);
        setmat(cx_mat,i,2*j-1,algebraic repart(tmp));
        tmp := getmat(in_mat,i,j);
        setmat(cx_mat,i,2*j,algebraic impart(tmp));
      >>;
    >>;
    return cx_mat;
  end;



symbolic procedure im_compress(cx_mat,n);
  %
  % Performs the opposite to im_uncompress.
  %
  begin
    scalar comp_mat;
    integer i,j;
    comp_mat := mkmatrix(n,n);
    for i:=1:n do
    <<
      for j:=1:n do
      <<
        setmat(comp_mat,i,j,{'plus,getmat(cx_mat,i,2*j-1),
               {'times,'i,getmat(cx_mat,i,2*j)}});
      >>;
    >>;
    return comp_mat;
  end;




symbolic procedure convert(in_mat,int_vec);
  %
  % The lu decomposition algorithm may swap some of the rows of A such
  % that L * U does not equal A but a row rearrangement of A. The
  % lu_decom returns as a third argument a vector that describes which
  % rows have been swapped.
  %
  % Given a matrix A, then
  %  convert(first lu_decom(A) * second lu_decom(A),third lu_decom(A))
  % will return A.
  %
  % convert(A,third lu_decom(A)) will give you L * U.
  %
  begin
    scalar new_mat;
    integer i;
    if not matrixp(in_mat) then
     rederr "Error in convert(first argument): should be a matrix.";
    new_mat := copy_mat(in_mat);
    for i:=1:upbv(int_vec)+1 do
    <<
      if getv(int_vec,i-1) neq i then
       new_mat := swap_rows(new_mat,i,getv(int_vec,i-1));
    >>;
    return new_mat;
  end;

flag('(convert),'opfn);


endmodule;  % lu_decom.


module cholesky;

%**********************************************************************%
%                                                                      %
% Computation of the Cholesky decomposition of dense positive definite %
% matrices containing numeric entries.                                 %
%                                                                      %
% Author: Matt Rebbeck, May 1994.                                      %
%                                                                      %
% The algorithm was taken from "Linear Algebra" - J.H.Wilkinson        %
%                                                  & C. Reinsch        %
%                                                                      %
%                                                                      %
% NB: By using the same rounded number techniques as used in svd this  %
%     could be made a lot faster.                                      %
%                                                                      %
%**********************************************************************%



symbolic procedure cholesky(mat1);
  %
  % A must be a positive definite symmetric matrix.
  %
  % LU decomposition of matrix A. ie: A=LU, where U is the transpose
  % of L. The determinant of A is also computed as a side effect but
  % has been commented out as it is not necessary. The procedure will
  % fail if A is unsymmetric. It will also fail if A, modified by
  % rounding errors, is not positive definite.
  %
  % The reciprocals of the diagonal elements are stored in p and the
  % matrix is then 'dragged' out and 'glued' back together in get_l.
  %
  %
  begin
    scalar x,p,in_mat,l,u,i_turned_rounded_on;  % d1,d2;
    integer i,j,n;
    if not !*rounded then << i_turned_rounded_on := t; on rounded; >>;
    if not matrixp(mat1) then
     rederr "Error in cholesky:  non matrix input.";
    if not symmetricp(mat1) then
     rederr "Error in cholesky: input matrix is not symmetric.";
    in_mat := copy_mat(mat1);
    n := first size_of_matrix(in_mat);
    p := mkvect(n);
%    d1 := 1;
%    d2 := 0;
    for i:=1:n do
    <<
      for j:=i:n do
      <<
        x := innerprod(1,1,i-1,{'minus,getmat(in_mat,i,j)},
                       row_vec(in_mat,i,n),row_vec(in_mat,j,n));
        x := reval{'minus,x};
        if j=i then
        <<
%          d1 := reval{'times,d1,x};
          if get_num_part(my_reval(x))<=0 then rederr
           "Error in cholesky: input matrix is not positive definite.";
%          while abs(get_num_part(d1)) >= 1 do
%          <<
%            d1 := reval{'times,d1,0.0625};
%            d2 := d2+4;
%          >>;
%          while abs(get_num_part(d1)) < 0.0625 do
%          <<
%            d1 := reval{'times,d1,16};
%            d2 := d2-4;
%          >>;
          putv(p,i,reval{'quotient,1,{'sqrt,x}});
        >>
        else
        <<
          setmat(in_mat,j,i,reval{'times,x,getv(p,i)});
        >>;
      >>;
    >>;
    l := get_l(in_mat,p,n);
    u := algebraic tp(l);
    if i_turned_rounded_on then off rounded;
    return {'list,l,u};
  end;

flag('(cholesky),'opfn);  % So it can be used from algebraic mode.



symbolic procedure get_l(in_mat,p,sq_size);
  %
  % Pulls out L from in_mat and p.
  %
  begin
    scalar l;
    integer i,j;
    l := mkmatrix(sq_size,sq_size);
    for i:=1:sq_size do
    <<
      setmat(l,i,i,{'quotient,1,getv(p,i)});
      for j:=1:i-1 do
      <<
        setmat(l,i,j,getmat(in_mat,i,j));
      >>;
    >>;
    return l;
  end;



symbolic procedure symmetricp(in_mat);
  %
  % Checks input is symmetric. ie: transpose(A) = A. (boolean).
  %
  if algebraic (tp(in_mat)) neq in_mat then nil else t;

flag('(symmetricp),'boolean);
flag('(symmetricp),'opfn);


endmodule;  % cholesky.


module svd;

%**********************************************************************%
%                                                                      %
% Computation of the Singular Value Decomposition of dense matrices    %
% containing numeric entries. Uses specific rounded number routines to %
% speed things up.                                                     %
%                                                                      %
% Author: Matt Rebbeck, June 1994.                                     %
%                                                                      %
% The algorithm was taken from "Linear Algebra" - J.H.Wilkinson        %
%                                                  & C. Reinsch        %
%                                                                      %
%**********************************************************************%



symbolic smacro procedure my_minus(u);
  %
  % Efficiently performs reval({'minus,u}).
  %
  if atom u then {'minus,u}
   else if car u = 'minus then cadr u
    else {'minus,u};



symbolic procedure svd(a);
  %
  % Computation of the singular values and complete orthogonal
  % decomposition of a real rectangular matrix A.
  %
  %      A = tp(U) diag(q) V,   U tp(U) = V tp(V) = I,
  %
  % and q contains the singular values along the diagonal.
  % (tp => transpose).
  %
  % Algorithm taken from "Linear Algebra"
  %                      J.H.Wilkinson & C.Reinsch
  %
  begin
    scalar ee,u,v,g,x,eps,tolerance,q,s,f,h,y,test_f_splitting,
           cancellation,test_f_convergence,convergence,c,z,denom,q_mat,
           i_rounded_turned_on,trans_done;
    integer i,j,k,l,l1,m,n;
    trans_done := i_rounded_turned_on := nil;
    if not !*rounded then << on rounded; i_rounded_turned_on := t; >>;

    if not matrixp(a) then
     rederr "Error in svd: non matrix input.";

    % The value of eps can be decreased to increase accuracy.
    % As usual, doing this will slow things down (and vice versa).
    % It should not be made smaller than the value of rd!-tolerance!*.
    eps := get_num_part(my_reval({'times,1.5,{'expt,10,-8}}));
    tolerance := get_num_part(my_reval({'expt,10,-31}));

    % Algorithm requires m >= n. If this is not the case then transpose
    % the input and swap U and V in the output (as A = tp(U) diag(q) V
    % but tp(A) = tp(V) diag(q) U  ).
    if row_dim(a) < column_dim(a) then
    << a := algebraic tp(a); trans_done := t; >>;

    m := row_dim(a);
    n := column_dim(a);

    u := rd_copy_mat(a);
    v := mkmatrix(n,n);
    ee := mkvect(n);
    q := mkvect(n);

    % Householder's reduction to bidiagonal form:
    g := x := 0;
    for i:=1:n do
    <<
      putv(ee,i,g);
      s := 0;
      l := i+1;
      for j:=i:m do s := specrd!:plus(s,specrd!:expt(getmat(u,j,i),2));
      if get_num_part(s) < tolerance then g := 0
      else
      <<
        f := getmat(u,i,i);
        if get_num_part(f)<0 then g := specrd!:sqrt(s)
         else g := my_minus(specrd!:sqrt(s));
        h := specrd!:plus(specrd!:times(f,g),my_minus(s));
        setmat(u,i,i,specrd!:plus(f,my_minus(g)));
        for j:=l:n do
        <<
          s := 0;
          for k:=i:m do
           s := specrd!:plus(s,specrd!:times(getmat(u,k,i),
                                             getmat(u,k,j)));
          f := specrd!:quotient(s,h);
          for k:=i:m do
           setmat(u,k,j,specrd!:plus(getmat(u,k,j),
                        specrd!:times(f,getmat(u,k,i))));
        >>;
      >>;
      putv(q,i,g);
      s := 0;
      for j:=l:n do s := specrd!:plus(s,specrd!:expt(getmat(u,i,j),2));
      if get_num_part(s) < tolerance then g := 0
      else
      <<
        f := getmat(u,i,i+1);
        if get_num_part(f)<0 then g := specrd!:sqrt(s)
         else g := my_minus(specrd!:sqrt(s));
        h := specrd!:plus(specrd!:times(f,g),my_minus(s));
        setmat(u,i,i+1,specrd!:plus(f,my_minus(g)));
        for j:=l:n do putv(ee,j,specrd!:quotient(getmat(u,i,j),h));
        for j:=l:m do
        <<
          s := 0;
          for k:=l:n do
           s := specrd!:plus(s,specrd!:times(getmat(u,j,k),
                                             getmat(u,i,k)));
          for k:=l:n do
           setmat(u,j,k,specrd!:plus(getmat(u,j,k),
                        specrd!:times(s,getv(ee,k))));
        >>;
      >>;
      y := specrd!:plus(abs(get_num_part(getv(q,i))),
                        abs(get_num_part(getv(ee,i))));
      if get_num_part(y) > get_num_part(x) then x := y;
    >>;

    % Accumulation of right hand transformations:
    for i:=n step -1 until 1 do
    <<
      if get_num_part(g) neq 0 then
      <<
        h := specrd!:times(getmat(u,i,i+1),g);
        for j:=l:n do setmat(v,j,i,specrd!:quotient(getmat(u,i,j),h));
        for j:=l:n do
        <<
          s := 0;
          for k:=l:n do
           s := specrd!:plus(s,specrd!:times(getmat(u,i,k),
                                             getmat(v,k,j)));
          for k:=l:n do
           setmat(v,k,j,specrd!:plus(getmat(v,k,j),
                        specrd!:times(s,getmat(v,k,i))));
        >>;
      >>;
      for j:=l:n do << setmat(v,i,j,0); setmat(v,j,i,0); >>;
      setmat(v,i,i,1);
      g := getv(ee,i);
      l := i;
    >>;

    % Accumulation of left hand transformations:
    for i:=n step -1 until 1 do
    <<
      l := i+1;
      g := getv(q,i);
      for j:=l:n do setmat(u,i,j,0);
      if get_num_part(g) neq 0 then
      <<
        h := specrd!:times(getmat(u,i,i),g);
        for j:=l:n do
        <<
          s := 0;
          for k:=l:m do
           s := specrd!:plus(s,specrd!:times(getmat(u,k,i),
                                             getmat(u,k,j)));
          f := specrd!:quotient(s,h);
          for k:=i:m do
           setmat(u,k,j,specrd!:plus(getmat(u,k,j),
                        specrd!:times(f,getmat(u,k,i))));
        >>;
        for j:=i:m do setmat(u,j,i,specrd!:quotient(getmat(u,j,i),g));
      >>
      else for j:=i:m do setmat(u,j,i,0);
      setmat(u,i,i,specrd!:plus(getmat(u,i,i),1));
    >>;

    % Diagonalisation of the bidiagonal form:
    eps := get_num_part(specrd!:times(eps,x));
    test_f_splitting := t;
    k := n;
    while k>=1 do
    <<
      convergence := nil;
      if test_f_splitting then
      <<
        l := k;
        test_f_convergence := cancellation := nil;
        while l>=1 and not (test_f_convergence or cancellation) do
        <<
          if abs(get_num_part(getv(ee,l))) <= eps
           then test_f_convergence := t
          else if abs(get_num_part(getv(q,l-1))) <= eps
           then cancellation := t
          else l := l-1;
        >>;
      >>;

      % Cancellation of e[l] if l>1:
      if not test_f_convergence then
      <<
        c := 0; s := 1; l1 := l-1;
        i := l;
        while i<=k and not test_f_convergence do
        <<
          f := specrd!:times(s,getv(ee,i));
          putv(ee,i,specrd!:times(c,getv(ee,i)));
          if abs(get_num_part(f)) <= eps then
           test_f_convergence := t
          else
          <<
            g := getv(q,i);
            h := specrd!:sqrt(specrd!:plus(specrd!:times(f,f),
                                           specrd!:times(g,g)));
            putv(q,i,h);
            c := specrd!:quotient(g,h);
            s := specrd!:quotient(my_minus(f),h);
            for j:=1:m do
            <<
              y := getmat(u,j,l1);
              z := getmat(u,j,i);
              setmat(u,j,l1,specrd!:plus(specrd!:times(y,c),
                                         specrd!:times(z,s)));
              setmat(u,j,i,specrd!:difference(specrd!:times(z,c),
                                              specrd!:times(y,s)));
            >>;
            i := i+1;
          >>;
        >>;
      >>;
      z := getv(q,k);
      if l = k then convergence := t;

      if not convergence then
      <<
        % Shift from bottom 2x2 minor:
        x := getv(q,l);
        y := getv(q,k-1);
        g := getv(ee,k-1);
        h := getv(ee,k);
        f := specrd!:quotient(specrd!:plus(specrd!:times(
              specrd!:plus(y,my_minus(z)),specrd!:plus(y,z)),
               specrd!:times(specrd!:plus(g,my_minus(h)),
                specrd!:plus(g,h))),specrd!:times(
                 specrd!:times(2,h),y));
        g := specrd!:sqrt(specrd!:plus(specrd!:times(f,f),1));
        % Needed to change < here to <=.
        if get_num_part(f)<=0 then
        denom := specrd!:plus(f,my_minus(g))
         else denom := specrd!:plus(f,g);
        f := specrd!:quotient(specrd!:plus(specrd!:times(
              specrd!:plus(x,my_minus(z)),specrd!:plus(x,z)),
               specrd!:times(h,specrd!:quotient(y,
                specrd!:plus(denom,my_minus(h))))),x);

        % Next QR transformation:
        c := s := 1;
        for i:=l+1:k do
        <<
          g := getv(ee,i);
          y := getv(q,i);
          h := specrd!:times(s,g);
          g := specrd!:times(c,g);
          z := specrd!:sqrt(specrd!:plus(specrd!:times(f,f),
                                         specrd!:times(h,h)));
          putv(ee,i-1,z);
          c := specrd!:quotient(f,z);
          s := specrd!:quotient(h,z);
          f := specrd!:plus(specrd!:times(x,c),specrd!:times(g,s));
          g := specrd!:plus(specrd!:times(my_minus(x),s),
                            specrd!:times(g,c));
          h := specrd!:times(y,s);
          y := specrd!:times(y,c);
          for j:=1:n do
          <<
            x := getmat(v,j,i-1);
            z := getmat(v,j,i);
            setmat(v,j,i-1,specrd!:plus(specrd!:times(x,c),
                                        specrd!:times(z,s)));
            setmat(v,j,i,specrd!:difference(specrd!:times(z,c),
                                            specrd!:times(x,s)));
          >>;
          z := specrd!:sqrt(specrd!:plus(specrd!:times(f,f),
                                         specrd!:times(h,h)));
          putv(q,i-1,z);
          c := specrd!:quotient(f,z);
          s := specrd!:quotient(h,z);
          f := specrd!:plus(specrd!:times(c,g),specrd!:times(s,y));
          x := specrd!:plus(specrd!:times(my_minus(s),g),
                            specrd!:times(c,y));
          for j:=1:m do
          <<
                y := getmat(u,j,i-1);
                z := getmat(u,j,i);
            setmat(u,j,i-1,specrd!:plus(specrd!:times(y,c),
                                        specrd!:times(z,s)));
            setmat(u,j,i,specrd!:difference(specrd!:times(z,c),
                                            specrd!:times(y,s)));
          >>;
        >>;
        putv(ee,l,0);
        putv(ee,k,f);
        putv(q,k,x);
      >>
      else % convergence:
      <<
        if get_num_part(z)<0 then
        <<
          % q[k] is made non-negative:
          putv(q,k,my_minus(z));
          for j:=1:n do setmat(v,j,k,my_minus(getmat(v,j,k)));
        >>;
        k := k-1;
      >>;
    >>;

    q_mat := q_to_diag_matrix(q);
    if i_rounded_turned_on then off rounded;
    if trans_done then
     return {'list,algebraic tp v,q_mat,algebraic tp u}
      else return {'list,algebraic tp u,q_mat,algebraic tp v};
  end;

flag('(svd),'opfn); % To make it available from algebraic (user) mode.



symbolic procedure q_to_diag_matrix(q);
  %
  % Converts q (a vector) to a diagonal matrix with the elements of
  % q on the diagonal.
  %
  begin
    scalar q_mat;
    integer i,sq_dim_q;
    sq_dim_q := upbv(q);
    q_mat := mkmatrix(sq_dim_q,sq_dim_q);
    for i:=1:sq_dim_q do setmat(q_mat,i,i,getv(q,i));
    return q_mat;
  end;


symbolic procedure pseudo_inverse(in_mat);
  %
  % Also known as the Moore-Penrose Inverse.
  %
  % Given the singular value decomposition A := tp(U) diag(q) V
  % the pseudo inverse A^(-1) is defined as
  %
  %   A^(-1) = tp(V) (diag(q))^(-1) U.
  %
  % NB: this can be quite handy as we can take the inverse of non
  % square matrices (A * pseudo_inverse(A) = identity).
  %
  begin
    scalar psu_inv,svd_list;
    svd_list := svd(in_mat);
    psu_inv := algebraic
                (tp(third svd_list)*(1/second svd_list)*first svd_list);
    return psu_inv;
  end;

flag('(pseudo_inverse),'opfn);



symbolic procedure rd_copy_mat(a);
  %
  % Creates a copy of the input matrix and returns it aswell as
  % reval-ing each elt to get them in !:rd!: form;
  %
  begin
    scalar c;
    integer row_dim,column_dim;
    row_dim := first size_of_matrix(a);
    column_dim := second size_of_matrix(a);
    c := mkmatrix(row_dim,column_dim);
    for i:=1:row_dim do
    <<
      for j:=1:column_dim do
      <<
        setmat(c,i,j,my_reval(getmat(a,i,j)));
      >>;
    >>;
    return c;
  end;



%
% All computation is done with rounded mode on and with all numbers
% in !:rd!: form. The following specrd!: functions makes the algebraic
% computation of these numbers very efficient.
%
symbolic procedure specrd!:times(u,v);
  begin
    scalar negsign;
    u := add_minus(u);
    v := add_minus(v);
    if eqcar(u,'minus) then << u := cadr u; negsign := t>>;
    if eqcar(v,'minus) then << v := cadr v; negsign := not negsign>>;
    if atom u then u := mkround float u;
    if atom v then v := mkround float v;
    return if negsign then list('minus,rd!:times(u,v))
            else rd!:times(u,v);
  end;



symbolic procedure specrd!:quotient(u,v);
  begin
    scalar negsign;
    u := add_minus(u);
    v := add_minus(v);
    if eqcar(u,'minus) then << u := cadr u; negsign := t>>;
    if eqcar(v,'minus) then << v := cadr v; negsign := not negsign>>;
    if atom u then u := mkround float u;
    if atom v then v := mkround float v;
    return if negsign then list('minus,rd!:quotient(u,v))
            else rd!:quotient(u,v);
  end;



symbolic procedure specrd!:expt(u,v);
  begin
    if (u = '(!:rd!: . 0.0) or u = 0) then return '(!:rd!: . 0.0);
    if eqcar(u,'minus) then u := ('!:rd!: . -cdadr u);
    if eqcar(v,'minus) then v := ('!:rd!: . -cdadr v);
    if atom u then u := mkround float u;
    if atom v then v := mkround float v;
    return rdexpt!*(u,v);
  end;



symbolic procedure specrd!:sqrt(u);
  specrd!:expt(u,0.5);



symbolic procedure specrd!:plus(u,v);
  begin
    scalar negsign;
    negsign := 0;
    u := add_minus(u);
    v := add_minus(v);
    if eqcar(u,'minus) then << u := cadr u; negsign := 1>>;
    if eqcar(v,'minus) then << v := cadr v; negsign := negsign +2>>;
    if atom u then u := mkround float u;
    if atom v then v := mkround float v;
    return if negsign = 0 then rd!:plus(u,v)
            else if negsign = 3 then list('minus,rd!:plus(u,v))
             else if negsign =2 then rd!:difference (u,v)
               else rd!:difference(v,u);
  end;


symbolic procedure specrd!:difference(u,v);
  begin
    scalar negsign;
    negsign := 0;
    u := add_minus(u);
    v := add_minus(v);
    if eqcar(u,'minus) then << u := cadr u; negsign := 1>>;
    if eqcar(v,'minus) then << v := cadr v; negsign := negsign +2>>;
    if atom u then u := mkround float u;
    if atom v then v := mkround float v;
    return if negsign = 0 then rd!:difference(u,v)
            else if negsign = 3 then list('minus,rd!:difference(u,v))
             else if negsign =2 then rd!:plus (u,v)
              else list('minus,rd!:plus(v,u));
  end;



symbolic procedure add_minus(u);
  %
  % Things like (!:rd!: . -0.12345) can cause problems as negsign does
  % not notice the negative. This function converts that to
  % {'minus,(!:rd!: . 0.12345)}. Unfortunately it slows things down but
  % it works.
  %
  begin
    if atom u then return u
    else if car u = '!:rd!: and cdr u >= 0 then return u
    else if car u = '!:rd!: and cdr u < 0 then
     return {'minus,('!:rd!: . abs(cdr u))}
    else if car u = 'minus and numberp cadr u then return u
    else if car u = 'minus and cdadr u < 0 then
     return ('!:rd!: . abs(cdadr u))
    else if car u = 'minus then return u
    else if cdr u < 0 then return {'minus,('!:rd!: . abs(cdr u))}
    else return u;
  end;



endmodule;  % svd.


module simplex;

%**********************************************************************%
%                                                                      %
% Computation of the optimal value of an objective function given a    %
% number of linear inequalities using the SIMPLEX algorithm.           %
%                                                                      %
% Author: Matt Rebbeck, June 1994.                                     %
%                                                                      %
% Many of the ideas were taken from "Linear Programming" by            %
%                                                 M.J.Best & K. Ritter %
%                                                                      %
% Minor changes: Herbert Melenk, Jan 1995                              %
%                                                                      %
%   replacing first, second etc. by car, cadr                          %
%   converted big smacros to ordinary procedures                       %
%                                                                      %
%**********************************************************************%

if not get('leq,'simpfn) then
<<
   algebraic operator <=;
   algebraic operator >=;
>>;

symbolic smacro procedure smplx_prepsq u;
  %
  % If u in (!*sq) standard quotient form then get !:rd!: part.
  %
  if atom u then u
  else if car u = 'minus and atom cadr u then u
  else if car u = 'minus and caadr u = '!*sq then {'minus,car cadadr u}
  else if car u = 'minus and caadr u = '!:rd!: then u
  else if car u = '!:rd!: then u
  else if car u = '!*sq then prepsq cadr u;



symbolic smacro procedure fast_row_dim(in_mat);
  %
  % Finds row dimension of a matrix with no error checking.
  %
  length in_mat #- 1;



symbolic smacro procedure fast_column_dim(in_mat);
  %
  % Finds column dimension of a matrix with no error checking.
  %
  length cadr in_mat;



symbolic smacro procedure fast_stack_rows(in_mat,row_list);
  %
  % row_list is always an integer in simplex.
  %
  'mat.{nth(cdr in_mat,row_list)};




symbolic smacro procedure fast_getmat(matri,i,j);
  %
  % Get matrix element (i,j).
  %
  fast_unchecked_getmatelem list(matri,i,j);



symbolic smacro procedure fast_my_letmtr(u,v,y);
  rplaca(pnth(nth(cdr y,car my_revlis cdr u),cadr my_revlis cdr u),v);



put('simplex,'psopfn,'simplex1);

symbolic procedure simplex1(input);
  %
  % The simplex problem is:
  %
  % min {c'x | Ax = b, x>=0},
  %
  % where Ax = b describes the linear equations and c is the function
  % that is to be optimised.
  %
  % This code implements the basic phaseI-phaseII revised simplex
  % algorithm. (phaseI checks for feasibility and phaseII finds the
  % optimal solution).
  %
  % A general idea of tha algorithm is as follows:
  %
  % 1: create phase 1 data.
  %
  %    Add slack and artificial variables to equations to create matrix
  %    A1. The initial basis (ib) consists of the numbers of the columns
  %    relating to the artificial variables. The basic feasible solution
  %    (xb) (if one exists) is  B^(-1)*b where b is the r.h.s. of the
  %    equations. Throughout, cb denotes the columns of the objective
  %    matrix corresponding to ib.
  %    This data goes to the revised simplex algorithm(2).
  %
  % 2: revised simplex:
  %
  %    step 1: Computation of search direction sb.
  %
  %    Compute u = -(B^(-1))'*cb, the smallest index k, and vk s.t.
  %
  %               vk = min{c(i) + A(i)'u | i not elt of ib}.
  %
  %    If vk>=0, stop with optimal solution xb = B^(-1)*b.
  %    If vk<0, set sb = B^(-1)*A(k) and go to step 2.
  %
  %    step 2: Computation of maximum feasible step size Ob.
  %
  %    If sb<=0 then rederr "Problem unbounded from below".
  %    If (sb)(i) >0 for at least one i, compute Ob and the smallest
  %      index l s.t.
  %
  %              (xb)(l)       { (xb)(i) |                      }
  %         Ob = ------- = min { ------  | all i with (sb)(i)>0 },
  %              (sb)(l)       { (sb)(i) |                      }
  %
  %    and go to step 3.
  %
  %    step3: Update.
  %
  %    Replace B^(-1) with [phiprm((B^(-1)',A(k),l)]', xb with B^(-1)*b
  %    and the l'th elt in ib with k. Compute cb'xb and go to step 1.
  %
  % 3: If we get this far (ie: we are feasible) then apply revised
  %    simplex to A (equations with slacks added), and the new xb,
  %    Binv, and ib.
  %
  %
  % Further details and far more advanced algorithms can be found
  % in almost any linear programming book. The above was adapted from
  % "Linear Programming"  M.J.Best and K. Ritter. To date, the code
  % contains no anti_cycling algorithm.
  %
  begin
    scalar max_or_min,objective,equation_list,tmp,a,b,obj_mat,x,a1,
           phase1_obj,ib,xb,binv,simp_calc,phase1_obj_value,big,sum,
           stop,work,i_turned_rounded_on,ans_list,optimal_value;
    integer m,n,k,i,ell,no_coeffs,no_variables,equation_variables;
    max_or_min := reval car input;
    objective := reval cadr input;
    equation_list := reval caddr input;
    if not !*rounded then << i_turned_rounded_on := t; on rounded; >>;

    if (max_or_min neq 'max) and (max_or_min neq 'min) then rederr
     "Error in simplex(first argument): must be either max or min.";

    if pairp equation_list and car equation_list = 'list then
     equation_list := cdr equation_list
     else rederr "Error in simplex(third argument}: must be a list.";

    % get rid of any two (or more) equal equations! Probably makes
    % things faster in general.
    tmp := unique_equation_list(equation_list);
    equation_list := car tmp;
    equation_variables := cadr tmp;

    % If r.h.s. and l.h.s. of inequalities are both <0 then multiply
    % by -1.
    equation_list := make_equations_positive(equation_list);

    % If there are variables in the objective function that are not in
    % the equation_list then add these variables to the equation list.
    % (They are added as variable>=0).
    equation_list :=
     add_not_defined_variables(objective,equation_list,
                               equation_variables);

    tmp := initialise(max_or_min,objective,equation_list);
    a := car tmp;
    b := cadr tmp;
    obj_mat := caddr tmp;
    x := cadddr tmp;
    % no_variables is the number of variables in the input equation
    % list. this is used in make_answer_list.
    no_variables := car cddddr tmp;

    % r.h.s. (i.e. b matrix) must be positive.
    tmp := check_minus_b(a,b);
    a := car tmp;
    b := cadr tmp;

    m := fast_row_dim(a);
    n := no_coeffs := fast_column_dim(a);

    tmp := create_phase1_a1_and_obj_and_ib(a);
    a1 := car tmp;
    phase1_obj := cadr tmp;
    ib := caddr tmp;
    xb := copy_mat(b);
    binv := fast_make_identity(fast_row_dim(a));
    % Phase 1 data is now ready to go...

    simp_calc := simplex_calculation(phase1_obj,a1,b,ib,binv,xb);

    phase1_obj_value := car simp_calc;
    xb := cadr simp_calc;
    binv := cadddr(simp_calc);
    if get_num_part(phase1_obj_value) neq 0
     then rederr "Error in simplex: Problem has no feasible solution.";

    % Are any artificials still basic?
    for ell:=1:m do if nth(ib,ell) <= n then <<>>
    else
    <<
      % so here, an artificial is basic in row ell.
      big := -1;
      k := 0;
      stop := nil;
      i := 1;
      while i<=n and not stop do
      <<
        sum := get_num_part(smplx_prepsq(fast_getmat(reval
                {'times,fast_stack_rows(binv,ell),
                 fast_augment_columns(a,i)},1,1)));
        if abs(sum) leq big then stop := t
        else
        <<
          big := abs(sum);
          k := i;
        >>;
        i := i+1;
      >>;
      if big geq 0 then <<>>
      else rederr {"Error in simplex: constraint",k," is redundant."};
      work := fast_augment_columns(a,k);
      binv := phiprm(binv,work,ell);
      nth(ib,ell) := k;
    >>;

    % Into Phase 2.
    simp_calc := simplex_calculation(obj_mat,a,b,ib,binv,xb);
    optimal_value := car simp_calc;
    xb := cadr simp_calc;
    ib := caddr simp_calc;
    ans_list := make_answer_list(xb,ib,no_coeffs,x,no_variables);
    if i_turned_rounded_on then off rounded;
    if max_or_min = 'max then
     optimal_value := my_reval{'minus,optimal_value};
    return {'list,optimal_value,'list.ans_list};
  end;

flag('(simplex1),'opfn);



symbolic procedure unique_equation_list(equation_list);
  %
  % Removes repititions in input. Also returns coeffecients in equation
  % list.
  %
  begin
    scalar unique_equation_list,coeff_list;
    for each equation in equation_list do
    <<
      if not intersection({equation},unique_equation_list) then
      <<
        unique_equation_list := append(unique_equation_list,{equation});
        coeff_list := union(coeff_list,get_coeffs(cadr equation));
      >>;
    >>;
    return {unique_equation_list,coeff_list};
  end;



symbolic procedure make_equations_positive(equation_list);
  %
  % If r.h.s. and l.h.s. of inequality are <0 then mult. both sides by
  % -1.
  %
  for each equation in equation_list collect
   if pairp cadr equation and caadr equation = 'minus and
      pairp caddr equation and caaddr equation = 'minus
    then {car equation,my_minus(cadr equation),my_minus(caddr equation)}
     else equation;



symbolic procedure add_not_defined_variables
                    (objective,equation_list,equation_variables);
  %
  % If variables in the objective have not been defined in the
  % inequalities(equation_list) then add them. They are added as
  % variable >= 0.
  %
  begin
    scalar obj_variables;
    obj_variables := get_coeffs(objective);
    if length obj_variables = length equation_variables then
     return equation_list;
    for each variable in obj_variables do
    <<
      if not intersection({variable},equation_variables) then
      <<
        prin2
         "*** Warning: variable ";
        prin2 variable;
        prin2t " not defined in input. Has been defined as >=0.";
       equation_list := append(equation_list,{{'geq,variable,0}});
      >>;
    >>;
    return equation_list;
  end;



symbolic procedure initialise(max_or_min,objective,equation_list);
  %
  % Creates A (with slack variables included), b (r.h.s. of equations),
  % the objective matrix (obj_mat) and X s.t. AX=b and
  % obj_mat * X = objective function.
  % Also returns the number of equations in the equation_list so we know
  % where to stop making answers in make_answer_list.
  %
  begin
    scalar more_init,a,b,obj_mat,x;
    integer no_variables;
    if max_or_min = 'max then
     objective := reval{'times,objective,-1};
    more_init := more_initialise(objective,equation_list);
    a := car more_init;
    b := cadr more_init;
    obj_mat := caddr more_init;
    x := cadddr more_init;
    no_variables := car cddddr more_init;
    return {a,b,obj_mat,x,no_variables};
  end;



symbolic procedure more_initialise(objective,equation_list);
  begin
    scalar objective,equation_list,non_slack_variable_list,obj_mat,
           no_of_non_slacks,tmp,variable_list,slack_equations,a,b,x;
    non_slack_variable_list :=
     get_preliminary_variable_list(equation_list);
    no_of_non_slacks := length non_slack_variable_list;
    tmp := add_slacks_to_equations(equation_list);
    slack_equations := car tmp;
    b := cadr tmp;
    variable_list := union(non_slack_variable_list,caddr tmp);
    tmp := get_x_and_obj_mat(objective,variable_list);
    x := car tmp;
    obj_mat := cadr tmp;
    a := simp_get_a(slack_equations,variable_list);
    return {a,b,obj_mat,x,no_of_non_slacks};
  end;



symbolic procedure check_minus_b(a,b);
  %
  % The algorithm requires the r.h.s. (i.e. the b matrix) to contain
  % only positive entries.
  %
  begin
    for i:=1:row_dim(b) do
    <<
      if get_num_part( reval getmat(b,i,1) ) < 0 then
      <<
        b := mult_rows(b,i,-1);
        a := mult_rows(a,i,-1);
      >>;
    >>;
    return {a,b};
  end;



symbolic procedure create_phase1_a1_and_obj_and_ib(a);
  begin
    scalar phase1_obj,a1,ib;
    integer column_dim_a1,column_dim_a,row_dim_a1,i;
    column_dim_a := fast_column_dim(a);
    % Add artificials to A.
    a1 := fast_matrix_augment({a,fast_make_identity(fast_row_dim(a))});
    column_dim_a1 := fast_column_dim(a1);
    row_dim_a1 := fast_row_dim(a1);
    phase1_obj := mkmatrix(1,fast_column_dim(a1));
    for i:=column_dim_a+1:fast_column_dim(a1) do
     fast_setmat(phase1_obj,1,i,1);
    ib := for i:=column_dim_a+1:fast_column_dim(a1) collect i;
    return {a1,phase1_obj,ib};
  end;



symbolic procedure simplex_calculation(obj_mat,a,b,ib,binv,xb);
  %
  % Applies the revised simplex algorithm. See above for details.
  %
  begin
    scalar rs1,sb,rs2,rs3,u,continue,obj_value;
    integer k,iter,ell;
    obj_value := compute_objective(get_cb(obj_mat,ib),xb);
    while continue neq 'optimal do
    <<
      rs1 := rstep1(a,obj_mat,binv,ib);
      sb := car rs1;
      k := cadr rs1;
      u := caddr rs1;
      continue := cadddr rs1;
      if continue neq 'optimal then
      <<
        rs2 := rstep2(xb,sb);
        ell := cadr rs2;
        rs3 := rstep3(xb,obj_mat,b,binv,a,ib,k,ell);
        iter := iter + 1;
        binv := car rs3;
        obj_value := cadr rs3;
        xb := caddr rs3;
      >>;
    >>;
    return {obj_value,xb,ib,binv};
  end;



symbolic procedure get_preliminary_variable_list(equation_list);
  %
  % Gets all variables before slack variables are added.
  %
  begin
    scalar variable_list;
    for each equation in equation_list do
     variable_list := union(variable_list,get_coeffs(cadr equation));
    return variable_list;
  end;



symbolic procedure add_slacks_to_equations(equation_list);
  %
  % Takes list of equations (=, <=, >=) and adds required slack
  % variables. Also returns all the rhs integers in a column matrix,
  % and a list of the added slack variables.
  %
  begin
    scalar slack_list,rhs_mat,slack_variable,slack_variable_list;
    integer i,row;
    rhs_mat := mkmatrix(length equation_list,1);
    row := 1;
    for each equation in equation_list do
    <<
      if not numberp reval caddr equation then
      <<
        prin2 "***** Error in simplex(third argument): ";
        rederr "right hand side of each inequality must be a number";
      >>
      else fast_setmat(rhs_mat,row,1,caddr equation);

      row := row+1;

      %
      % Put in slack/surplus variables where required.
      %
      if car equation = 'geq then
      <<
        i := i+1;
        slack_variable := mkid('sl_var,i);
        equation := {'plus,{'minus,mkid('sl_var,i)},cadr equation};
        slack_variable_list := append(slack_variable_list,
                                      {slack_variable});
      >>
      else if car equation = 'leq then
      <<
        i := i+1;
        slack_variable := mkid('sl_var,i);
        equation := {'plus,mkid('sl_var,i),cadr equation};
        slack_variable_list := append(slack_variable_list,
                                      {slack_variable});
      >>
      else if car equation = 'equal then equation := cadr equation
      else
      <<
        prin2 "***** Error in simplex(third argument):";
        rederr "inequalities must contain either >=, <=, or =.";
      >>;

      slack_list := append(slack_list,{equation});
    >>;
    return {slack_list,rhs_mat,slack_variable_list};
  end;

flag('(add_slacks_to_list),'opfn);



symbolic procedure simp_get_a(slack_equations,variable_list);
  %
  % Extracts the A matrix from the slack equations.
  %
  begin
    scalar a,slack_elt,var_elt;
    integer row,col,length_slack_equations,length_variable_list;
    length_slack_equations := length slack_equations;
    length_variable_list := length variable_list;
    a := mkmatrix(length slack_equations,length variable_list);
    for row := 1:length_slack_equations do
    <<
      for col := 1:length_variable_list do
      <<
        slack_elt := nth(slack_equations,row);
        var_elt := nth(variable_list,col);
        fast_setmat(a,row,col,smplx_prepsq(
                               algebraic coeffn(slack_elt,var_elt,1)));
      >>;
    >>;
    return a;
  end;



symbolic procedure get_x_and_obj_mat(objective,variable_list);
  %
  % Converts the variable list into a matrix and creates the objective
  % matrix. This is the matrix s.t. obj_mat * X = objective function.
  %
  begin
    scalar x,obj_mat;
    integer i,length_variable_list,tmp;
    length_variable_list := length variable_list;
    x := mkmatrix(length_variable_list,1);
    obj_mat := mkmatrix(1,length_variable_list);
    for i := 1:length variable_list do
    <<
      fast_setmat(x,i,1,nth(variable_list,i));
      tmp := nth(variable_list,i);
      fast_setmat(obj_mat,1,i,algebraic coeffn(objective,tmp,1));
    >>;
    return {x,obj_mat};
  end;



symbolic procedure get_cb(obj_mat,ib);
  %
  % Gets hold of the columns of the objective matrix that are pointed
  % at in ib.
  %
  fast_augment_columns(obj_mat,ib);



symbolic procedure compute_objective(cb,xb);
  %
  % Objective value := cb * xb (both are matrices)
  %
  fast_getmat(reval {'times,cb,xb},1,1);



symbolic procedure rstep1(a,obj_mat,binv,ib);
  %
  % Implements step 1 of the revised simplex algorithm.
  % ie: Computation of search direction sb.
  %
  % See above for details. (comments in simplex).
  %
  begin
    scalar u,sb,sum,i_in_ib;
    integer i,j,m,n,k,vkmin;
    m := fast_row_dim(a);
    n := fast_column_dim(a);
    u := mkmatrix(m,1);
    sb := mkmatrix(m,1);
    %  Compute u.
    u := reval {'times,{'minus,algebraic (tp(binv))},
                algebraic tp(symbolic get_cb(obj_mat,ib))};
    k := 0;
    vkmin := 10^10;
    i := 1;
    for i:=1:n do
    <<
      i_in_ib := nil;
      % Check if i is in ib.
      for j:=1:m do
      <<
        if i = nth(ib,j) then i_in_ib := t;
      >>;
      if not i_in_ib then
      <<
        sum := specrd!:plus(smplx_prepsq(fast_getmat(obj_mat,1,i)),
                two_column_scalar_product(fast_augment_columns(a,i),u));
        % if i is not in ib.
        %sum := fast_getmat(obj_mat,1,i);
        %for p:=1:m do
        %<<
          %sum := reval
          % {'plus,sum,{'times,fast_getmat(A,p,i),fast_getmat(u,p,1)}};
        %>>;
        if get_num_part(sum) geq get_num_part(vkmin) then <<>>
        else
        <<
          vkmin := sum;
          k := i;
        >>;
      >>;
    >>;
    % Do we need a tolerance here?
    if get_num_part(vkmin) < 0 then
    <<
      % Form sb.
      for i:=1:m do
      <<
        sum := 0;
        for j:=1:m do sum := specrd!:plus(sum,
         specrd!:times(fast_getmat(binv,i,j),fast_getmat(a,j,k)));
        fast_setmat(sb,i,1,sum);
      >>;
      return {sb,k,u,nil};
    >>
    else return {sb,k,u,'optimal};
  end;



symbolic procedure rstep2(xb,sb);
  %
  % step 2: Computation of maximum feasible step size Ob.
  %
  % see above for details. (comments in simplex).
  %
  begin
    scalar ratio;
    integer ell,sigb;
    sigb := 1*10^30;
    for i:=1:fast_row_dim(sb) do
    <<
      if get_num_part(my_reval fast_getmat(sb,i,1)) leq 0 then <<>>
      else
      <<
        ratio := specrd!:quotient(smplx_prepsq(fast_getmat(xb,i,1)),
                                  smplx_prepsq(fast_getmat(sb,i,1)));
        if get_num_part(ratio) geq get_num_part(sigb) then <<>>
        else
        <<
          sigb := ratio;
          ell := i;
        >>;
      >>;
    >>;
    if ell= 0 then
     rederr "Error in simplex: The problem is unbounded.";
    return {sigb,ell};
  end;



symbolic procedure rstep3(xb,obj_mat,b,binv,a,ib,k,ell);
  %
  % step3: Update.
  %
  % see above for details. (comments in simplex).
  %
  begin
    scalar work,binv;
    work := fast_augment_columns(a,k);
    binv := phiprm(binv,work,ell);
    xb := reval{'times,binv,b};
    nth(ib,ell) := k;
    obj_mat := compute_objective(get_cb(obj_mat,ib),xb);
    return {binv,obj_mat,xb};
  end;



symbolic procedure phiprm(binv,d,ell);
  %
  % Replaces B^(-1) with [phi((B^(-1)',A(k),l)]'.
  %
  begin
    scalar sum,temp;
    integer m,j;
    m := fast_column_dim(binv);
    sum := scalar_product(fast_stack_rows(binv,ell),d);
%    if get_num_part(sum) = 0 then
%     rederr
%{"Error in simplex: new matrix would be singular. Inner product = 0."};
    if not zerop get_num_part(sum) then
     sum := specrd!:quotient(1,sum);
    binv := fast_mult_rows(binv,ell,sum);
    for j:=1:m do
    <<
      if j = ell then <<>>
      else
      <<
        temp := fast_getmat(reval{'times,fast_stack_rows(binv,j),d},
                            1,1);
        binv := fast_add_rows(binv,ell,j,{'minus,temp});
      >>;
    >>;
    return binv;
  end;



symbolic procedure make_answer_list(xb,ib,no_coeffs,x,no_variables);
  %
  % Creates a list of the values of the variables at the optimal
  % solution.
  %
  begin
    scalar x_mat,ans_list;
    integer i;
    x_mat := mkmatrix(1,no_coeffs);
    i := 1;
    for each elt in ib do
     <<
       if fast_getmat(xb,i,1) neq 0 then
        fast_setmat(x_mat,1,elt,fast_getmat(xb,i,1)); i := i+1;
     >>;
     ans_list := for i:=1:no_variables collect
                 {'equal,my_reval fast_getmat(x,i,1),
                 get_num_part(my_reval fast_getmat(x_mat,1,i))};
    return ans_list;
  end;



% Speed functions


symbolic procedure fast_add_rows(in_mat,r1,r2,mult1);
  %
  % Replaces row2 (r2) by mult1*r1 + r2 without messing around.
  %
  begin
    scalar new_mat,fast_getmatel;
    integer i,coldim;
    coldim := fast_column_dim(in_mat);
    new_mat := copy_mat(in_mat);
    if (my_reval mult1) = 0 then return new_mat;
    for i:=1:coldim do
    <<
      if not((fast_getmatel :=my_reval fast_getmat(new_mat,r1,i)) = 0)
      then fast_setmat(new_mat,r2,i,specrd!:plus(specrd!:times(
      smplx_prepsq(mult1),smplx_prepsq(fast_getmatel)),smplx_prepsq(
      fast_getmat(in_mat,r2,i))));
    >>;
    return new_mat;
  end;



symbolic procedure fast_augment_columns(in_mat,col_list);
  %
  % Quickly augments columns of in_mat specified in col_list.
  %
  if atom col_list then 'mat.for i:=1:fast_row_dim(in_mat)
                              collect {fast_getmat(in_mat,i,col_list)}
   else 'mat.for each row in cdr in_mat
              collect for each elt in col_list collect nth(row,elt);


symbolic procedure fast_matrix_augment(mat_list);
  %
  % As in linear_algebra package but doesn't produce !*sq output.
  %
  begin
  scalar ll,new_list;
    if length mat_list = 1 then return mat_list
     else
     <<
       new_list := {};
       for i:=1:fast_row_dim(car mat_list) do
       <<
         ll := {};
         for each mat1 in mat_list do ll := append(ll,nth(cdr mat1,i));
         new_list := append(new_list,{ll});
       >>;
       return 'mat.new_list;
     >>;
  end;



symbolic procedure fast_setmat(matri,i,j,val);
  %
  % Set matrix element (i,j) to val.
  %
  fast_my_letmtr(list(matri,i,j),val,matri);



symbolic procedure fast_unchecked_getmatelem u;
  nth(nth(cdr car u,cadr u),caddr u);



symbolic procedure fast_mult_rows(in_mat,row_list,mult1);
  %
  % In simplex row_list is always an integer.
  %
  begin
    scalar new_list,new_row;
    integer row_no;
    row_no := 1;
    for each row in cdr in_mat do
    <<
      if row_no neq row_list then new_list := append(new_list,{row})
      else
      <<
        new_row := for each elt in row collect
                    my_reval{'times,mult1,elt};
        new_list := append(new_list,{new_row});
      >>;
      row_no := row_no+1;
    >>;
    return 'mat.new_list;
  end;



symbolic procedure fast_make_identity(sq_size);
  %
  % Creates identity matrix.
  %
  'mat. (for i:=1:sq_size collect
           for j:=1:sq_size collect if i=j then 1 else 0);



symbolic procedure two_column_scalar_product(col1,col2);
  %
  % Calculates tp(col1)*col2.
  %
  % Uses sparsity efficiently.
  %
  begin
    scalar sum;
    sum := 0;
    for i:=1:length cdr col1 do
    <<
      if car nth(cdr col1,i)=0 or car nth(cdr col2,i)=0 then <<>>
       else
       sum := specrd!:plus(sum,specrd!:times(smplx_prepsq(
                           car nth(cdr col1,i)),smplx_prepsq(
                           car nth(cdr col2,i))));
    >>;
    return sum;
  end;



symbolic procedure scalar_product(row,col);
  %
  % Calculates row*col.
  %
  % Uses sparsity efficiently.
  %
  begin
    scalar sum;
    sum := 0;
    for i:=1:length cadr row do
    <<
      if nth(cadr row,i)=0 or car nth(cdr col,i)=0 then <<>>
       else
       sum := specrd!:plus(sum,
                           specrd!:times(smplx_prepsq(nth(cadr row,i)),
                                     smplx_prepsq(car nth(cdr col,i))));
    >>;
    return sum;
  end;


endmodule;  % simplex.


end;
