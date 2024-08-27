%***********************************************************************
%=======================================================================
%
% Code for the extension of the Matrix Package to include Sparse
% Matrices.
%
% Author: Stephen Scowcroft.                           Date: June 1995
%
%=======================================================================
%***********************************************************************

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

% $Id$

module sparsmat;

% This is an important line of code as it changes the way in which the
% current matrix package is evaluated (i.e through my function instead
% of matsm!*)

put('matrix,'evfn,'spmatsm!*);

% This is the function to create a matrix and declare it a sparse
% variable

symbolic procedure sparse u;
   % Declares list U as Sparse matrices.
   begin scalar v,w,x;
        for each j in u do
           if atom j then if null (x := gettype j)
                            then put(j,'rtype,'sparse)
                           else if x eq 'sparse
                            then <<lprim list(x,j,"redefined");
                                   put(j,'rtype,'sparse)>>
                           else typerr(list(x,j),"sparse")
            else if not idp car j
                   or length (v := revlis cdr j) neq 2
                   or not natnumlis v
             then errpri2(j,'hold)
            else if not (x := gettype car j) or x eq 'sparse
             then <<w:=nil;
                    put(car j,'rtype,'sparse);
                    put(car j,'avalue,list('sparse,list('sparsemat,
                            mkvect(cadr j),'spm . cdr j)));
                  >>
            else typerr(list(x,car j),"sparse")
   end;


 symbolic procedure natnumlis u;
   % True if U is a list of natural numbers.
   null u or fixp car u and car u>0 and natnumlis cdr u;

rlistat '(sparse);

%put('sparsemat,'stat,'matstat);

% symbolic procedure formmat(u,vars,mode);
%   'list . mkquote car u
%     . for each x in cdr u collect('list . formlis(x,vars,mode));

% put('sparsemat,'formfn,'spformmat);

% put('sparsemat,'i2d,'spmkscalmat);

% put('sparsemat,'lnrsolvefn,'splnrsolve);

put('sparsemat,'rtypefn,'spquotematrix);

symbolic procedure spquotematrix u; 'sparse;

flag('(sparsemat tp),'spmatflg);

flag('(sparsemat),'noncommuting);

put('sparsemat,'prifn,'myspmatpri2);

flag('(sparsemat),'struct);      % for parsing

put('sparse,'fn,'spmatflg);

put('sparse,'evfn,'spmatsm!*);

flag('(sparse),'prifn);
flag('(sparse),'sprifn);

put('sparse,'tag,'sparsemat);

put('sparse,'lengthfn,'spmatlength);

put('sparse,'getelemfn,'getspmatelem2);

put('sparse,'setelemfn,'setspmatelem2);

% This is a temporary function and will hopefully replace matsm!*
% i.e put('matrix,'evfn,'spmatsm!*);

symbolic procedure spmatsm!*(u,v);
begin scalar x;
% if pairp u
 << x:=spmatsm u;
      if eqcar(x,'sparsemat) then return x
       else return matsm!*1 x;
  >>
%   else << return cadr get(u,'avalue)>>;

end;


symbolic procedure spmkscalmat u;
   % Converts id u to 1 by 1 matrix.
   list('sparsemat,list('spm,1,1));

% A sorting function to include row elements in the sparse matrix list.

symbolic procedure sortrowelem (row,u,val,y,len);
 begin scalar x,v,elem,lis;
  v:=u;
  x:=u;
  lis:=u;
   while elem = nil do
  <<
    if v = nil then
           <<rplacd(x,list(row . (list val))); elem:=t>>
     else if not (car v=nil) then
      << if row < caar v then
         << if car v = car lis then
             rplacd(y,append(list((row . list val) . v),list(len)))
             else rplacd(x,rplacd(list(row . (list val)),v)); elem:=t>>
        else if row > caar v then <<elem:=nil; x:=u; u:=cdr u; v:=u>>
      >>
      else <<rplacd(y,list(list(row . (list val)),len)); elem:=t>>;
  >>;
  end;

% A sorting function to include column elements in the sparse matrix list.

symbolic procedure sortcolelem (col,u,val);
 begin scalar v,elem;
  v:=cdr u;
   while elem = nil do
  <<
    if v=nil then <<rplacd(u,list(col . val)); elem:=t>>
      else if col < caar v then <<rplacd(u,rplacd(list(col . val),v));
                            elem:=t>>
      else if col > caar v then <<elem:=nil; u:=cdr u; v:=cdr u>>;
  >>;
  end;

% This function returns the length of a sparse matrix.
% It replaces the old lengthreval function and extends it for Sparse.

symbolic procedure lengthreval u;
   begin scalar v,w,x;
      if length u neq 1
        then rerror(alg,11,
                    "LENGTH called with wrong number of arguments");
      u := car u;
      if idp u and arrayp u then return 'list . get(u,'dimension);
      v := aeval u;
      if (w := getrtype v) and (x := get(w,'lengthfn))
        then if w = 'sparse then return apply1(x,u)
               else return apply1(x,v)
       else if atom v then return 1
       else if not idp car v or not(x := get(car v,'lengthfn))
        then if w
          then lprie list("LENGTH not defined for argument of type",w)
         else typerr(u,"LENGTH argument")
       else return apply1(x,cdr v)
   end;

symbolic procedure spmatlength u;
 begin scalar y,x;
  if pairp u then x := u
   else x := cadr get(u,'avalue);
  y := cdr caddr x;
   if not eqcar(x,'sparsemat) then rerror(matrix,2,list("Matrix",u,"not set"))
    else return list('list,car y,cadr y);
   end;

% This enables elements of the sparse matrix to be obtained.

symbolic procedure getspmatelem2(u);
   begin scalar x,y,p;
      x := get(car u,'avalue);
      y:= cdr caddr cadr x;
      if null x or not(car x eq 'sparse) then typerr(car u,"sparse")
       else if not eqcar(x := cadr x,'sparsemat)
        then if idp x
         then return getmatelem2(x . cdr u)
         else rerror(sparse,1,list("Matrix",car u,"not set"))
         else if length (p := revlis cdr u) neq 2
	        or not(fixp car p and car p > 0)
 	        or not (fixp cadr p and cadr p > 0)
          then msgpri("Invalid sparse matrix index:",car u . p,nil,nil,t)
         else if car p > car y or cadr p > cadr y then
          typerr( car p,"The dimensions are wrong - matrix unaligned")
         else return findelem2(x,car p,cadr p);
   end;

% This is the finding function. It it used throughout the entire Sparse
% Matrix package.

symbolic procedure findelem2 (x,row,col);
begin scalar list,rlist,colist,res;
 if pairp x and car x eq 'sparsemat then list:=(cadr x)
  else list := x;
 rlist:=getv(list,row);
 colist:=atsoc(col,rlist);
  if colist =nil then res:=0
   else res:=cdr colist;
return res;
end;

symbolic procedure findrow(x,row);
begin scalar list,rlist;
 if pairp x and car x eq 'sparsemat then list:=(cadr x)
  else list := x;
 rlist:=getv(list,row);
 return rlist;
end;

symbolic procedure mkempspmat(row,len);
 begin scalar res;
  res:=list('sparsemat,mkvect(row),len);
  return res;
 end;

symbolic procedure sp!-copy!-vect(list,len);
 begin scalar oldvec,newvec;
  oldvec:=cadr list;
% newvec:=totalcopy(oldvec);
  newvec:=fullcopy(oldvec);
  %for i:=1:num do
  %<< %putv(newvec,i,getv(oldvec,i))>>;
 if not len then len:=caddr list;
 return list('sparsemat,
     newvec,len);
 end;

symbolic procedure fullcopy s;
   % A subset of the PSL totalcopy function.
   if pairp s then fullcopy car s . fullcopy cdr s
    else if vectorp s then
        begin scalar cop; integer si;
        si:=upbv s;
        cop:=mkvect si;
        for i:=0:si do putv(cop,i,fullcopy getv(s,i));
        return cop end
    else s;

% This is a very useful function and most of the matrix arithmetic
% functions rely on it.
% It enables me to rebuild a list of type Sparse having performed
% various functions on the old list.
% It is non-destructive.

symbolic procedure letmtr3(u,v,y,typ);
  begin scalar z,rowelem,colelem,len,list;
    %if length y=2 then len:=cadr y
    % else
    len:=caddr y;
    if cddr u=nil then
      << if not eqcar(y,'sparsemat)
      then rerror(matrix,10,list("Matrix",car u,"not set"))
         else if not numlis (z := revlis cdr u) or length z neq 1
           then return errpri2(u,'hold);
         putv(cadr y,cadr u,v);>>
    else
    <<
    if not eqcar(y,'sparsemat)
      then rerror(matrix,10,list("Matrix",car u,"not set"))
         else if not numlis (z := revlis cdr u) or length z neq 2
           then return errpri2(u,'hold);
        rowelem:=getv(cadr y,car z);
            if rowelem =nil then
             << if v=0 and not (typ='cx) then nil
                 else putv(cadr y,car z,list(list(nil),(cadr z . v)));>>
                  else <<colelem:=atsoc(cadr z, rowelem);
              if colelem=nil then
               << if v=0 and not (typ='cx) then nil
                    else sortcolelem(cadr z,rowelem,v);>>
              else << if v=0 and not (typ='cx) then
                        << if cddr rowelem = nil then
                            <<
                              putv(cadr y,car z,nil);
                            >>
                           else rplacd(rowelem,
                                   cdr delete(colelem,rowelem));
                         >>
                else rplacd(colelem,v);>>;
                  >>;
               >>;
    end;


% This enables sparse matrices to be created.
% Data is stored in a list by row with additional column and value pairs.

symbolic procedure setspmatelem2(u,v);
   begin scalar x,y,p;
      x := get(car u,'avalue);
      if null x or not (car x eq 'sparse) then typerr(car u,"sparse matrix")
       else if not eqcar(x := cadr x,'sparsemat)
        then rerror(sparse,10,list("Sparse matrix",car u,"not set"));
      y := cdr caddr x;
      p := revlis cdr u;
      if length p neq 2 or not(fixp car p and car p > 0)
 	   or not (fixp cadr p and cadr p > 0)
        then msgpri("Invalid sparse matrix index:",car u . p,nil,nil,t)
       else if car p > car y or cadr p > cadr y
              then typerr(car u,"The dimensions are wrong - matrix unaligned")
       else return letmtr3(u,v,x,nil);
   end;

% This is my sparse matrix printer.
%It will print out the single elements of the matrix.

symbolic procedure sp!-notempty!-p(vec,val);
  % Find the first nonempty row and return t; return nil if none found.
  begin scalar res,i;
    i:=1;
    while not res and i<=val do
       if not null getv(vec,i) then <<res:=t; goto done;>>
     	 else   i:=i+1;
 done:
    return res;
  end;

% This is my sparse matrix printer.
% It will print out the single elements of the matrix.

symbolic procedure sparpri(u,i,nam);
 begin scalar val,row;
  val:=u;
  row:=i;
  for each x in val do
     if !*fort then assgnpri(cdr x,list list(nam,row,(car x)),'only)
     else <<
 	writepri(list('quote,list('setq, list(nam,row,(car x)), cdr x)),
	   'first);
      	writepri(''!$, 'last)
     >>;
 end;

symbolic procedure myspmatpri2(u); myspmatpri1(u,nil);

symbolic procedure myspmatpri1(u,nam);
 begin scalar matr,nam,list,fl;
 % if   then print("The matrix is dense, contains only zeros")
  % else
    << matr:= cadr u;
       if null nam then nam:='spm;
       fl:=sp!-notempty!-p(matr,cadr caddr u);
       %for i:=1:cadr caddr u do
       %<< if not (getv(matr,i) = nil) then fl:=t;>>;
       if fl then
       << for i:=1:cadr caddr u do
           <<list:=getv(matr,i);
              if not (list=nil) then sparpri(cdr list,i,nam)>>;
       >>
        else print "Empty Matrix";
     >>;
 end;

symbolic procedure spsetmatpri(u,v);
   % Prints a sparse matrix v with name u
   myspmatpri1(v,u);

put('sparsemat,'setprifn,'spsetmatpri);

% This function returns the transpose of the sparse matrix.
% It should replace the current tp function as it is an extension to
% include the transpose of Sparse Matrices.

symbolic procedure smtp(u,typ);
  begin scalar x,tm,row,newcol,newrow,val,len,col,rows;
  if atom u then <<x := cadr get(u, 'avalue); len:= caddr x>>
   else if eqcar(u,'sparsemat) then <<x:=u; len:=caddr x>>
    else <<x:= smtp(cadr u,typ); len:=caddr x>>;
   row:=cadr len;
   col:=caddr len;
   tm:=mkempspmat(col,list('spm,col,row));
    if not eqcar(x,'sparsemat) then rerror(matrix,2,list("Matrix",u,"not set"))
    else for i:=1:row do
     << rows:=findrow(x,i);
        if not (rows=nil) then
        << newcol:=i;
           for each cols in cdr rows  do
            << newrow:=car cols;
               val:=cdr cols;
               letmtr3(list(tm,newrow,newcol), val, tm,typ)
            >>;
        >>;
       >>;
   return tm;
   end;

symbolic procedure tp u;
 if checksp(u) = 'sparse then smtp (spmatsm u,nil)
   else tp1 spmatsm u;


% put('tp2, 'psopfn, 'smtp);



% This function transforms a matrix of MATRIX type into one of SPARSE
% MATRIX type. It is destructive.
% It is very useful for creating Sparse Matrices as one can utilise all
% the matrix facilities and then convert to Sparse form.

symbolic procedure transmat1(u);
  begin scalar vec,v,x,rcnt,ccnt,elem,row,rlist;
   x:= cdr aeval (car u);
   rcnt:=0;
   ccnt:=0;
   v:=cdr matlength aeval(car u);
   vec:=mkempspmat(car v,('spm . v));
   rlist:=list(list(nil));
   for each rows in x do
    << row:=rows;
       rcnt:=rcnt + 1;
       for each cols in row do
        <<  elem:=cols;
            ccnt:=ccnt + 1;
            if elem = 0 then nil
             else rlist:=(ccnt . elem) . rlist
        >>;
        rlist:=reverse (rlist);
        if not (rlist=list(list(nil))) then
           letmtr3(list(vec,rcnt),rlist,vec,nil);
%)putv(vec,rcnt,rlist);
        ccnt:=0;
        rlist:=list(list nil);
    >>;
    put(car u,'avalue,list('sparse, vec));
    put(car u,'rtype,'sparse);
  end;

put('transmat,'psopfn,'transmat1);

% This is a funtion to transform matrix types into sparse types.
% It is non-destructive.
% This is used when performing matrix calculations of matrices of
% 'sparse and 'matrix type.

symbolic procedure sptransmat(u);
 begin scalar v,x,rcnt,ccnt,elem,row,rlist,vec;
   if pairp u then << x:=u; v:=cdr matlength u>>
    else << x:= aeval (u); v:=cdr matlength aeval(u)>>;
   rcnt:=0;
   ccnt:=0;
   vec:=mkempspmat(car v,('spm . v));
   rlist:=list(list nil);
   for each rows in cdr x do
    << row:=rows;
       rcnt:=rcnt + 1;
       for each cols in row do
        <<  elem:=cols;
            ccnt:=ccnt + 1;
            if elem = 0 then nil
             else rlist:=(ccnt . elem) . rlist
        >>;
        rlist:=reverse(rlist);
        if not (rlist=list(list(nil))) then
          letmtr3(list(vec,rcnt),rlist,vec,nil);
        ccnt:=0;
        rlist:=list(list nil);
    >>;
    return vec;
  end;

symbolic procedure trans(u);
 begin scalar x,res;
  while u do
  << x:=checksp(car u);
     if x=nil or x='sparse then <<res:=car u . res; u:=cdr u>>
      else if x='matrix then
      << if pairp car u then
          << if caar u='mat then res:=sptransmat car u . res
              else res:=trans car u . res;
          >>
          else res:=sptransmat car u . res;
          u:=cdr u;
      >>
       else <<res:=trans car u . res; u:=cdr u>>;
  >>;
   return reverse res;
 end;

% It is hoped that this will eventually replace the present matsm in
% the matrix package.
% This might be impossible due to the fact that some of the hierarchical
% REDUCE functions instinctively call matsm (rather than spmatsm).
% Perhaps it will be better to work along side matsm (is similar).

symbolic procedure spmatsm u;
   begin scalar x,y,r;
   if (r := getrtype u) eq 'yetunknowntype
     then u := eval!-yetunknowntypeexpr(u,nil);
       if pairp u then
        << if eqcar(u,'sparsemat) then r:='sparse
        else if checksp(u) = 'sparse then r :='sparse
         else if checksp(u) = 'matrix then r:='matrix
         else <<u:=trans u; r:='sparse>>;
        >>
       else if (r := checksp(u)) eq 'sparse
	  or null r and getrtype u eq 'sparse
       then r:='sparse
        else r:='matrix;
      for each j in nssimp(u,r) do % was 'sparse) do
         <<y := multsm(car j,matsm1 cdr j);
           x := if null x then y else addm(x,y)>>;
   if length x = 1 then return car x
    else return x
   end;

%symbolic procedure spmatsm!*1 u;
%   begin
%    if eqcar(u, 'sparsemat) then u:=u
%      else <<
%      % We use subs2!* to make sure each element simplified fully.
%      u := 'mat . for each j in u collect
%                     for each k in j collect !*q2a subs2!* k>>;
%      !*sub2 := nil;   % Since all substitutions done.
%      return u
%   end;

% This is to replace the current matsm1 function.
% Extended to include sparse matrices.

symbolic inline procedure matsm1!-xsimp u;
   if not lchk cdr u then rerror(matrix,3,"Matrix mismatch")
   else for each j in cdr u collect
      for each k in j collect xsimp k;

symbolic inline procedure sparsemat!-xsimp u;
   begin integer rows := sprow_dim u;
      scalar new,oldrow;
      new := mkempspmat(rows,caddr u);
      for i:=1:rows do <<
      	 oldrow := getv(cadr u,i);
	 if not null oldrow then
	    putv(cadr new,i,
	       list nil .
		  foreach el in cdr oldrow collect car el . expchk cdr el);
      >>;
      return new
   end;

symbolic inline procedure sparsemat!-subs2 u;
   begin integer rows := sprow_dim u;
      scalar new,oldrow;
      new := mkempspmat(rows,caddr u);
      for i:=1:rows do <<
      	 oldrow := getv(cadr u,i);
	 if not null oldrow then
	    putv(cadr new,i,
	       list nil .
	       	  foreach el in cdr oldrow collect
		     car el . <<!*sub2 := t; mk!*sq subs2 simp cdr el>>);
      >>;
      return new
   end;

symbolic procedure matsm1 u;
   %returns matrix canonical form for matrix symbol product U;
   begin scalar x,y,z,len; integer n;
    a:  if null u then return z
         else if eqcar(car u,'!*div) then go to d
         else if atom car u then go to er
         else if caar u eq 'mat
 	  then x := matsm1!-xsimp car u
         else if caar u eq 'sparsemat
          then x := sparsemat!-xsimp car u
         else if flagp(caar u,'matmapfn) and cdar u
            and getrtype cadar u eq 'matrix
          then x := matsm matrixmap(car u,nil)
         else if (x := get(caar u,'psopfn))
	 then <<x := lispapply(x,list cdar u); 
                if eqcar(x,'mat) then x := matsm x>>
         else if caar u eq 'sparsemat and length u = 1
                  then <<z:=u; go to c>>
         else <<x := lispapply(caar u,cdar u);
	        if eqcar(x,'mat) then x := matsm x
		else if eqcar(x,'sparsemat) then x := spmatsm x>>;
    b:  z := if null z then x
              else if null cdr z and null cdar z then multsm(caar z,x)
              else if car x eq 'sparsemat then spmultm(z,list x)
              else multm(x,z);
    c:  u := cdr u;
        go to a;
    d: if checksp(cadar u) = 'sparse then
         <<  y := spmatsm cadar u;
             len:= cdar reverse y;
              if not(car len = cadr len) then
                rerror(matrix,4,"Non square sparse matrix")
         >>
        else
         << y:= matsm cadar u;
            if (n := length car y) neq length y
             then rerror(matrix,4,"Non square matrix")
            else if (z and n neq length z)
             then rerror(matrix,5,"Matrix mismatch")
            else if cddar u then go to h
            else if null cdr y and null cdar y then go to e
         >>;
        x := subfg!*;
        subfg!* := nil;
        if null z then z := apply1(get('mat,'inversefn),y)
         else if caar z = 'sparsemat then
          << z:=spmultm(car apply1(get('mat,'inversefn),y),z);
             u:=cdr u;
          >>
         else if null(x := get('mat,'lnrsolvefn))
          then z := multm(apply1(get('mat,'inversefn),y),z)
         else z := apply2(get('mat,'lnrsolvefn),y,z);
        subfg!* := x;
        % Make sure there are no power substitutions.
        if caar z = 'sparsemat
	then <<
	   for i:=1:upbv cadr car z do <<
	      if not null row then <<
	      	 putv(cadr car z,i,
		    car row .
		       for each el in cdr row collect
		       	  <<!*sub2 := t; car el . mk!*sq subs2 simp cdr el>>)
	      >>
	   >> where row := getv(cadr car z,i);
	>>
        else
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

% To replace current function.
% Extended for sparse matrices.

symbolic procedure multsm(u,v);
 begin;
   %returns product of standard quotient U and matrix standard form V;
   if not (length v=1) and car v ='sparsemat then v:=list v;
   if u = (1 ./ 1) then return v
    else if caar v = 'sparsemat then return spmultsm(u,car v)
    else return for each j in v collect for each k in j collect multsq(u,k);
 end;

% This is the matrix multiplier function for Sparse Matrices and a
% single multiplier.

symbolic procedure spmultsm(u,v);
  begin scalar len,tm,row,col,newval,val,rows;
   len:= caddr v;
   tm:=mkempspmat(cadr len,len);
   for i:=1: cadr len do
   << rows:=findrow(v,i);
      row := i;
       if not (rows=nil) then
       << for each cols in cdr rows do
          << col:=car cols;
             val:=simp cdr cols;
             newval:=multsq(u,val);
             newval:=mk!*sq(newval);
             if not (newval = 0) then
             letmtr3(list(tm,row,col),newval,tm,nil);
          >>;
       >>;
     >>;
   return list(tm);
  end;

% To replace current function
% Extended for Sparse Matrices.

symbolic procedure addm(u,v);
   % Returns sum of two matrix canonical forms U and V.
   % Returns U + 0 as U. Patch by Francis Wright.
 begin scalar res;
   if not (length u=1) and car u='sparsemat then u:=list u;
   if not (length v=1) and car v='sparsemat then v:=list v;
   if caar u = 'sparsemat and caar v = 'sparsemat then
      res:=smaddm(car u,car v)
   else
   if v = '(((nil . 1))) then u else       % FJW.
   res:=for each j in addm1(u,v,function cons)
           collect addm1(car j,cdr j,function addsq);
   return res;
 end;

% To replace current function
% Extended for Sparse Matrices.

symbolic procedure addm1(u,v,w);
   if null u and null v then nil
    else if null u or null v then rerror(matrix,8,"Matrix mismatch")
    else apply2(w,car u,car v) . addm1(cdr u,cdr v,w);

% This function is part of the matrix addition code.

symbolic procedure smaddm(u,v);
 begin scalar lena,lenb,len;
  len:= caddr v;
  lena:= cdr caddr u;
  lenb:= cdr caddr v;
   if not (lena = lenb) then rerror(matrix,8,"Matrix mismatch")
    else return smaddm2(u,v,len);
 end;

% This is the function which performs the matrix addition for Sparse
% matrices.

symbolic procedure smaddm2(u,v,lena);
 begin scalar tm,rowas,rowbs,rowa,rowb,rowna,rownb,val1,val2,j,newval;
   rowas := u;
   rowbs := v;
   tm:=sp!-copy!-vect(rowbs,nil);
   for i:=1:cadr lena do
  << rowa:=findrow(rowas,i);
     rowna:=i;
     rowb:=findrow(rowbs,i);
     rownb:=i;
     if not (rowa=nil) then
     << for each xx in cdr rowa do
        << j:=car xx;
           val1:=cdr xx;
           val2:=atsoc(j,rowb);
           if val2=nil then
           << letmtr3(list(tm,i,j),val1,tm,nil)>>
           else
            <<val2:=cdr val2;
              newval:=addsq(simp val1,simp val2);
              newval:=mk!*sq(newval);
               letmtr3(list(tm,i,j),newval,tm,nil);
            >>;
         >>;
       >>;
    >>;
   return tm;
 end;

%This is now redundent code.

symbolic procedure smaddm1(u,v,lena);
 begin scalar tm,rowas,rowbs,rowa,rowb,cola,colb,colas,colbs,cols,
              col,newval,vala,valb,val,colna,colnb,rowna,rownb;
   tm:=mkempspmat(cadr lena,lena);
   rowas := cadr u;
   rowbs := cadr v;
  for i:=1:cadr lena do
  << rowa:=findrow(rowas,i);
     rowna:=i;
     rowb:=findrow(rowbs,i);
     rownb:=i;
    while not (rowa=nil or rowb=nil) do
    <<
    if rowna = rownb then
      <<colas:= cdr rowa;
        colbs:= cdr rowb;
       while not (colas = nil or colbs = nil) do
       <<
        cola:=car colas;
        colb:=car colbs;
        colna:=car cola;
        colnb:=car colb;

         if colna = colnb then
           <<vala:=simp cdr cola;
             valb:=simp cdr colb;
             newval:=addsq(vala,valb);
             newval:=mk!*sq(newval);
             if not (newval = 0) then
             letmtr3(list(tm,rowna,colna),newval,tm,nil);
             colbs:=cdr colbs;
             colas:=cdr colas
            >>
         else if colna > colnb then
           <<valb:=cdr colb;
             if not (valb = 0) then
             letmtr3(list(tm,rownb,colnb),valb,tm,nil);
             colbs:=cdr colbs
           >>
         else
           <<vala:=cdr cola;
             if not (vala = 0) then
             letmtr3(list(tm,rowna,colna),vala,tm,nil);
             colas:=cdr colas
           >>;
        >>;
        if not (colas = nil) then
         <<for each x in colas do
           <<letmtr3(list(tm,rowna,car x),cdr x,tm,nil)>>;
         >>
        else if not (colbs = nil) then
         <<for each x in colbs do
           <<letmtr3(list(tm,rowna,car x),cdr x,tm,nil)>>;
          >>;
         rowa:=nil;
         rowb:=nil;
        >>
      else if rowna > rownb then
        <<for each cols in cdr rowb do
           <<
             col:=car cols;
             val:=cdr cols;
             if not (val = 0) then
             letmtr3(list(tm,rownb,col),val,tm,nil)
            >>;
           rowb:=nil;
        >>
      else
        <<for each cols in cdr rowa do
           <<col:=car cols;
             val:=cdr cols;
             if not (val = 0) then
             letmtr3(list(tm,rowna,col),val,tm,nil)
           >>;
            rowa:=nil;
        >>;
    >>;
   if not (rowa = nil) then
     <<for each cols in cdr rowa do
        <<col:=car cols;
          val:=cdr cols;
          if not (val = 0) then
          letmtr3(list(tm,rowna,col),val,tm,nil)
         >>;
      >>
     else if not(rowb=nil) then
     <<for each cols in cdr rowb do
       <<col:=car cols;
         val:=cdr cols;
         if not (val = 0) then
          letmtr3(list(tm,rownb,col),val,tm,nil)
        >>;
     >>;
  >>;
   return tm;
  end;

% This is to perform matrix multiplication of Sparse Matrices.

symbolic procedure spmultm(u,v);
 begin scalar lena,lenb,nlen;
  if not (cdr v = nil) then<< v:=list(spmultm(car v,cdr v));
                               return spmultm(u,v)>>
   else
  <<
  lena:=caddr car v;
  lenb:=caddr u;
  nlen:=list('spm,cadr lena,caddr lenb);
 if not (caddr lena = cadr lenb) then rerror(matrix,8,"Matrix mismatch")
  else return spmultm2(car v,smtp (u,nil),nlen);
  >>;
 end;

% This is the actual multiplication function.

symbolic procedure spmultm2 (u,v,len);
 begin scalar tm,rowas,rowbs,rowa,rows,val1,val2,newval,smnewval,jj;
   tm:=mkempspmat(cadr len,len);
   if not sp!-notempty!-p(cadr u,cadr caddr u) or not sp!-notempty!-p(cadr v, cadr caddr v) then return tm
   else
   << rowas := cadr u;
      rowbs := cadr v;
      for i:=1:cadr caddr u do
        << rowa :=findrow(rowas,i);
           if rowa then
           <<for j:=1:cadr caddr v do
             <<rows:=findrow(rowbs,j);
               if rows then
               <<smnewval:=simp 0;
                 for each xx in cdr rowa do
                 <<jj:=car xx;
                   val1:=cdr xx;
                   val2:=atsoc(jj,rows);
                   if val2 then
                    << val2:=cdr val2;
                       newval:=multsq(simp val1,simp val2);
                       smnewval:=addsq(smnewval,newval);
                    >>
                   else <<smnewval:=smnewval>>;
                 >>;
                 newval:=mk!*sq(smnewval);
                 if not (newval=0) then
                 letmtr3(list(tm,i,j),newval,tm,nil);
                >>;
              >>;
            >>;
          >>;
      return tm;
     >>;
 end;

% This is now redundent code.

symbolic procedure spmultm1 (u,v,len);
 begin scalar tm,rowas,rowbs,rowa,rowna,rownb,colas,colbs,cola,colb,
              vala,valb,newval,smnewval,colna,colnb,rows;
   tm:=mkempspmat(cadr len,len);
   if not sp!-notempty!-p(cadr u,cadr caddr u) or not sp!-notempty!-p(cadr v, cadr caddr v) then return tm
    else
     << rowas := cadr u;
        rowbs := cadr v;
        for i:=1:cadr caddr u do
        << rowa :=findrow(rowas,i);
        while rowa do
        << for j:=1:cadr caddr v do
           << rows:=findrow(rowbs,j);
              if rows then
            << rowna:= i;
               colas:= cdr rowa;
               rownb:= j;
               colbs:=cdr rows;
               smnewval:=simp 0;
               while not (colas = nil or colbs = nil) do
                << cola:=car colas;
                   colb:=car colbs;
                   colna:=car cola;
                   colnb:=car colb;

                   if colna = colnb then
                    << vala:=simp cdr cola;
                       valb:=simp cdr colb;
                       newval:=multsq(vala,valb);
                       smnewval:=addsq(smnewval,newval);
                       colbs:=cdr colbs;
                       colas:=cdr colas
                    >>
                    else if colna > colnb then << colbs:=cdr colbs>>
                    else <<colas:=cdr colas>>;
                 >>;
             newval:=mk!*sq(smnewval);
             if not (newval = 0) then
             letmtr3(list(tm,rowna,rownb),newval,tm,nil);
              >>;
             >>;
           rowa:=nil;
          >>;
         >>;
      return tm
       >>;
  end;

% This is a function to enable me to determine whether I am dealing with
% Sparse Matrices or otherwise. This enables my Sparse code to run along
% side the present Matrix package.

% It is an important function as it is the one which enables me to
% extend the current matrix package to include the Sparse code.
% Allows both packages to work side by side.

symbolic procedure checksp(u);
 begin scalar x,sp,m;
  if atom u and not numberp u then
  << x:=get(u, 'avalue); if not (x=nil) then x:=car x>>
   else if pairp u then
   << if car u = 'sparsemat then sp:='sparse
       else if car u = 'mat then m:='matrix
       else
       <<while u do
         << if pairp car u then
            <<if car u='sparsemat then sp:='sparse
               else if car u='mat then m:='matrix
                else
                <<if not pairp u then x:=nil
                   else x:=list checksp(car u);
                  if not (x=nil) then x:=car x;
                  if x='sparse then sp:='sparse
                   else if x='matrix then m:='matrix;
                 %   else <<sp:='sparse; m:='matrix>>;
                 >>;
               u:=cdr u;
               if not pairp u then u:=nil;
            >>
             else
              <<x:=get(car u,'avalue);
                if not (x=nil) then x:=car x;
                if x='sparse then <<sp:='sparse; u:=cdr u>>
                 else if x='matrix then <<m:='matrix; u:=cdr u>>
                  else u:=cdr u;
                if not pairp u then u:=nil;
              >>;
         >>;
        >>;
      if sp and not m then x:=sp
       else if m and not sp then x:=m
        else x:=sp . m;
    >>
   else x:=nil;
    return x;
 end;

% The following function is to be used along side the function for the
% evaluation of determinants. This function returns the i,j th minor of
% a matrix.

symbolic procedure sprmcol(num,list);
 begin scalar row,roe,rlist,newlist;
  while list do
   << row := car list;
      roe := cdr row;
     % cnt := car row;
      rlist := car row . rlist;
      while roe do
       << if num = caar roe then roe := cdr roe
           else <<rlist := (car roe) . rlist; roe := cdr roe>>;
       >>;
      list := cdr list;
      newlist := reverse(rlist) . newlist;
      rlist := nil;
   >>;
  return reverse(newlist);
 end;

% This is the determinent function for sparse matrices.

% To replace current code.
% Extended for Sparse Matrices (unlke the Matrix det I only have one
% method of calculation).

symbolic procedure simpdet u;
   begin scalar x,y;
      y := spmatsm carx(u,'det);
      % We can't use the Bareiss code when rounded is on, since exact
      % division is required.
      return if checksp y = 'sparse then spdet y
              else if !*cramer or !*rounded or
                      (errorp(x := errorset({'bareiss!-det,mkquote u},nil,nil))
	    		 where !*protfg := t)
               then detq y
              else car x
   end;

symbolic procedure spdet(u);
 begin scalar len,lena,lenb,llist,ans;
  len:= cdr caddr u;
  lena:=car len;
  lenb:=cadr len;
  llist:=cadr u;
  if not (lena = lenb) then rederr "Non square sparse matrix"
   else if lena=2 then return twodet(llist)
   else if lena=1 then return findelem2(llist,1,1)
   else <<matrix_clrhash();
          ans := nsimpdet(llist,lena,lena,0,1);
          matrix_clrhash()>>>
  return ans;
end;


symbolic procedure nsimpdet(u,size,len,ignnum,firstrow);
   % u is two row vector of a sparse square matrix of order len.
   % Value is the determinant of u.
   % Algorithm is expansion by minors of first row.
   % ignnum is packed set of column indices to avoid.
   begin integer n2,i; scalar row,sign,z,x;
      row := getv(u,firstrow);   % Current row.
      if not null row then row := cdr row; % drop superfluous leading element
      n2 := 1;
      if len=1
        then return <<i := 1;		% column index
                      while twomem(n2,ignnum)
                         do <<n2 := 2*n2; i := i + 1>>;
                      if null(x := atsoc(i,row))
			then nil ./ 1
		       else simp cdr x>>;   % Last row, single element.
      if z := matrix_gethash ignnum then return cdr z;
      len := len-1;
      z := nil ./ 1;
      for colindex := 1:size do
        <<x := atsoc(colindex,row);
	  %% null x means that the matrix element is zero
          if not twomem(n2,ignnum)
            then <<if x and numr (x := simp cdr x)
                     then <<if sign then x := negsq x;
                            z:= addsq(multsq(x,nsimpdet(u,size,len,n2+ignnum,firstrow+1)),
                                        z)>>;
                   sign := not sign>>;
          n2 := 2*n2>>;
% z is a standard quotient and hence never NIL, and that makes this use
% of hash tables safe!
      matrix_puthash(ignnum,z);
      return z
   end;


% The determinant solver for 2 x 2 matrices.

symbolic procedure twodet(list);
 begin scalar val1,val2,res;
  val1:=multsq(simp findelem2(list,1,1), simp findelem2(list,2,2));
  val2:=multsq(simp findelem2(list,2,1), simp findelem2(list,1,2));
   res:=subtrsq(val1,val2);
  return res;
 end;



% This function produces an augmented matrix ready to perform Gaussian
% Elimination in order to calculate the inverse.

symbolic procedure spaugment(list,len);
 begin;
 % he:=car list;
 % tl := caddr list;
  %nlist:=list(he,sumsol(cadr list,0),tl);

  for i:= 1:len do
   <<letmtr3(list(list,i,i+len),1,list,nil)>>;
  return list;
 end;

% Gaussian Elimination.


% A function for row swapping.

symbolic procedure swap(row,rest,i);
 begin scalar rowb,len;
 len:=cadr caddr rest;
 if i=len then rerror(matrix,13,"Singular Matrix");
  rowb := findrow(rest,i+1);
 if i = caar cdr rowb then
  << letmtr3(list(rest,i),rowb,rest,nil);
     letmtr3(list(rest,i+1),row,rest,nil);
  >>
  else <<swap(rowb,rest,i+1) >>;
  return rest;
 end;

symbolic procedure spgauss(list,len);
 begin scalar rows,nrow,frow,row,cols,piv,plist,ndrow,drow,mval,clist,
               rown,rcnt,ccnt,rowlist;
  rows:=spaugment(list,len);
  rcnt := 0;
  for i:=1:cadr caddr list do
    << frow:=findrow(rows,i);
       if not (frow=nil) then
       <<
       row:=i;
       piv := 0;
    if not (row = rcnt + 1) then rerror(matrix,13,"Singular Matrix");
    while piv = 0 do
    << cols:= cdr frow;
       if caar cols = row then
        << piv := simp cdar cols;
           piv := (cdr piv . car piv)
        >>
       else
        << rowlist:=swap(frow,rows,i);
           frow := findrow(rowlist,i);
        >>;
     >>;

    %plist:=mkempspmat(1,list('spm,1,caddr caddr list));
    %letmtr3(list(clist,1),frow,clist,nil);
   if not (piv = simp 1) then
    << frow:=list(nil). for each xx in cdr frow collect
               (car xx . mk!*sq(multsq(piv,simp cdr xx)));
        %findrow(cadr car spmultsm(piv, clist),1);
    >>;
   %letmtr3(list(clist,1),frow,clist,nil);
   letmtr3(list(rows,i),frow,rows,nil);
   for j:=i+1:cadr caddr list do
   << drow := findrow(rows,j);
     if drow then
     << rown:=j;
      ccnt := caar cdr drow;
      if ccnt = row then
       << mval := simp cdadr drow;
              if mval = (nil ./ 1) then mval := mval
               else mval := ((- car mval) . cdr mval);
       >>
       else mval := simp 0;          %and also for 0 cols.
         clist:=mkempspmat(1,list('spm,1,1));
         plist:=mkempspmat(1,list('spm,1,1));
         letmtr3(list(clist,1),drow,clist,nil);
       if mval = simp 0 then ndrow := clist
         else
         <<nrow:= list(nil) . for each xx in cdr frow collect
                        (car xx . mk!*sq(multsq(mval,simp cdr xx)));
           letmtr3(list(plist,1),nrow,plist,nil);
           ndrow:=smaddm2(clist,plist,list('spm,1,caddr caddr list));
           ndrow:=findrow(cadr ndrow,1);
         if ndrow=nil then rerror(matrix,13,"Singular Matrix");
          letmtr3(list(rows,j),ndrow,rows,nil);
          >>;
       >>;
     >>;
    rcnt := rcnt + 1;
   >>
   else <<rcnt := rcnt + 1>>;
 >>;
  spback_sub(rows,len);
  return rows;
 end;

% This is the procedure for back substitution.

% This function re-writes the matrix list in order to print it out.

symbolic procedure sumsol(list,len);
 begin scalar clist,row;
  for i:=1:len do
  << row:=findrow(list,i);
     if not (row=nil) then
     << clist := for each x in row collect ((car x - len) . cdr x);
        letmtr3(list(list,i),list(nil) . clist,list,nil);
     >>;
  >>;
 end;

% Recursively the rows of the matrix are calculated for each row and
% column values.

symbolic procedure sumsol2(rows,row,listb,len);
 begin scalar rcnt,col,row,val,sum,rlist,lena,elist,llist,list,mval;
  rcnt := row;
  listb := cdr listb;
  elist := cdr listb;
   sum := 0;
   lena := len + 1;
 if row = len then return (elist);
 for i:=lena:2*len + 1 do
 << sum := simp 0;
    for each xx in elist do
     << val := simp cdr xx;
        col:=car xx;
        if col<len+1 then
        <<mval := findelem2(rows,col,lena);
          if mval = 0 then sum := sum
           else sum := addsq(sum,multsq(val,simp mval));
        >>;
      >>;
   list:=atsoc(lena,elist);
   llist := sol(list,sum,lena);
   if not (llist = nil) then rlist := llist . rlist
    else rlist := rlist;
  rcnt := row;
  lena := lena + 1;
  elist := cdr listb;
  >>;

  return (reverse rlist);
 end;

% This sub-function performs the actual calculation for the matrix.

symbolic procedure sol(list,sum,ccnt);
 begin scalar ccnt,col,val,nval,nlist;
  if list = nil then << col := ccnt; val := simp 0 >>
       else << col := car list; val := simp cdr list >>;
      if ccnt = col then val := val
       else val := simp 0;
      if sum = simp 0 then nval := mk!*sq val
       else nval := mk!*sq(subtrsq(val,sum));
      if not (nval = 0) then nlist := ccnt . nval;
  return nlist;
 end;

% The back-substitution function.

symbolic procedure spback_sub(list,len);
 begin scalar ilist,lrow,rcnt;
  rcnt := 0;
  for i:=len step -1 until 1 do
   << lrow := findrow(cadr list,i);
      if not (lrow=nil) then
       << ilist:= sumsol2(list,i,lrow,len);
          letmtr3(list(list,i),ilist,list,nil);
       >>;
   >>;
   sumsol(list,len);
   return list;
 end;

%The inverse functions, which call the gaussian elemination code.

symbolic procedure spmatinverse(list);
 begin scalar rows,len;
  len:=caddr list;
  rows:=mkempspmat(cadr len, len);
  rows:=sp!-copy!-vect(list,nil);
  rows:=spgauss(rows,cadr len);
  return list(rows);
 end;

% To replace current function.
% Extended for Sparse Matrices.

symbolic procedure matinverse u;
 if car u = 'sparsemat then spmatinverse(u)
  else lnrsolve(u,generateident length u);

% The following are the functions to calculate the trace of a matrix.

% To replace current function.
% Extended for Sparse Matrices.

symbolic procedure simptrace u;
   begin integer n; scalar z;
   if checksp u = 'sparse then z := sptrace spmatsm car u
    else
     << u := spmatsm carx(u,'trace);
        if length u neq length car u then rederr "Non square matrix";
        n := 1;
        z := nil ./ 1;
        for each x in u do <<z := addsq(nth(x,n),z); n := n+1>>;
      >>;
        return z
   end;

% The sparse trace function

symbolic procedure sptrace(list);
 begin scalar val,sum,rlist,len;
  len:= cadar reverse list;
  rlist := cadr list;
  sum := simp 0;
  for i:=1:len do
   << val := simp findelem2(rlist,i,i);
      sum := addsq(sum,val);
   >>;

  return sum;
 end;


% A function for finding the cofactor of a matrix.
% E.g The det of the matrix minor (with the row and col removed).

% To replace current code.
% Extended for Sparse Matrices.

symbolic procedure simpcofactor u;
  if checksp car u = 'sparse then
   spcofactor(spmatsm car u,ieval cadr u,ieval carx(cddr u,'cofactor))
  else
   cofactorq(spmatsm car u,ieval cadr u,ieval carx(cddr u,'cofactor));

% Two functions for removing columns and rows respectively.

symbolic procedure spremcol(num,list);
 begin scalar row,col,len;
 len:=cadr caddr list;
  for i:=1:len do
  << row := findrow(list,i);
     if not (row=nil) then
     <<
     col:=atsoc(num,row);
     if col then
     <<row:=delete(col,row);
       letmtr3(list(list,i),row,list,nil)>>;
     >>;
  >>;
 end;


symbolic procedure spremrow(num,list);
 begin;
 letmtr3(list(list,num),nil,list,nil);
 end;

% The function to hold it all together.

symbolic procedure spcofactor(list,row,col);
 begin scalar len,lena,lenb,rlist,res;
  len := caddr list;
  rlist := sp!-copy!-vect(list,len);
  lena := cadr len;
  lenb := caddr len;
  if not (row > 0 and row < lena + 1)
    then rerror(matrix,20,"Row number out of range");
  if not (col > 0 and col < lena + 1)
   then rerror(matrix,21,"Column number out of range");
  if not (lena = lenb)
   then rerror(matrix,22,"non-square matrix");

   spremrow(row,rlist);
   spremcol(col,rlist);

   if rlist = nil then res := simp nil
    else
     << rewrite(rlist,lena - 1,row,col);
        matrix_clrhash();
        res:= nsimpdet(rlist, lena - 1, lena - 1, 0, 1);
        matrix_clrhash();
        if remainder(row+col,2)=1 then res := negsq res;
      >>;
  return res;
 end;

% This function rewrites the Minor matrix when the rows and columns have
% been removed.
% This is necessary in order to use the nsimpdet function.

symbolic procedure rewrite(list,len,row,col);
 begin scalar rcnt,ccnt,rows,cols,cola,coln,rlist,cnt,val,rown,
              rrcnt,leng,unt;
  rcnt:=1;
  rrcnt := 1;
  leng:=caddr list;
  if cadr leng = caddr leng then unt:=len+1
   else unt:=len;
  for i:=1:unt do
  << rows := findrow(list,i);
   if not (rows=nil) then
   << cols := cdr rows;
      rown := i;
      if rcnt = row then rcnt := rcnt + 1;
      if rown = rcnt then
      << cnt:=1;
         ccnt:=1;
         rlist := nil;
         while cols and not (cnt = len + 1) do
          << cola:=car cols;
             coln:=car cola;
              val:=cdr cola;
              if cnt = col then ccnt:= ccnt + 1;

              if coln = ccnt then << rlist := (cnt . val) . rlist;
                                     cnt := cnt + 1;
                                     cols := cdr cols;
                                     ccnt := ccnt + 1>>
               else <<ccnt := ccnt + 1; cnt:=cnt+1 >>;
           >>;
        letmtr3(list(list,rrcnt),list(nil) . reverse rlist,list,nil);
        rrcnt := rrcnt + 1;
         rcnt:= rcnt + 1;
        >>
        else << rcnt := rcnt + 1; rrcnt := rrcnt + 1>>;
     >>
    else rcnt:=rcnt+1;
    >>;
   if len + 1 = cadr caddr list then
    letmtr3(list(list,len+1),nil,list,nil);
   return list;
 end;

endmodule;

end;

%***********************************************************************
%=======================================================================
%
% End of Code.
%
%=======================================================================
%***********************************************************************

%in "spmateigen.red";
%in "splinalg.red";


