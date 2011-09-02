module symmetry;
%
% ----------------------------------------------------------
%                       Symmetry Package 
% ----------------------------------------------------------
%
% Author : Karin Gatermann
%          Konrad-Zuse-Zentrum fuer
%          Informationstechnik Berlin
%          Heilbronner Str. 10
%          W-1000 Berlin 31
%          Germany
%          Email: Gatermann@sc.ZIB-Berlin.de
%
% Version 1.0   9. December 1991
% 
% Abstract:
% ---------
% This program is an implementation of the algorithm
% for computation of symmetry adapted bases from the
% theory of linear representations of finite grous.
% Projections for the computation of block diagonal form 
% of matrices are computed having the symmetry of a group.
%
% 
% REDUCE 3.4 is required.
%
% References:
% -----------
% J.-P. Serre, Linear Representations of Finite Groups.
% Springer, New York (1977).
% E. Stiefel, A. F{\"a}ssler, Gruppentheoretische
%  Methoden und ihre Anwendung. Teubner, Stuttgart (1979). 
%  (English translation to appear by Birkh\"auser (1992)).
%
% Keywords: 
% --------
%           linear representations, symmetry adapted bases,
%           matrix with the symmetry of a group,
%           block diagonalization
%
% symmetry.red
% definition of available algebraic operators

% To build a fast loading version of this package, the following
% sequence of commands should be used:

% faslout "symmetry";
% in "symmetry.red"$
% faslend;

load_package matrix;

% CREATE!-PACKAGE('(symmetry
%                   symatvec
%                   symcheck
%                   symchrep
%                   symhandl
%                   sympatch
%                   symwork
%                   symdata1
%                   symdata2),
%                 '(contrib symmetry));

algebraic(operator @);
algebraic( infix @);
algebraic( precedence @,*);

symbolic procedure give!_groups (u);
% prints the elements of the abstract group
begin
  return mk!+outer!+list(get!*available!*groups());
end;

put('availablegroups,'psopfn,'give!_groups);


symbolic procedure print!_group (groupname);
% prints the elements of the abstract group
begin
scalar g;
  if length(groupname)>1 then rederr("too many arguments");
  if length(groupname)<1 then rederr("group as argument missing");
  g:=reval car groupname;
  if available!*p(g) then
  return alg!:print!:group(g);
end;

put('printgroup,'psopfn,'print!_group);

symbolic procedure print!_generators (groupname);
% prints the generating elements of the abstract group
begin
scalar g;
  if length(groupname)>1 then rederr("too many arguments");
  if length(groupname)<1 then rederr("group as argument missing");
  g:=reval car groupname;
  if  available!*p(g) then
  return alg!:generators(g);
end;

put('generators,'psopfn,'print!_generators);


symbolic procedure character!_table (groupname);
% prints the characters of the group
begin
scalar g;
  if length(groupname)>1 then rederr("too many arguments");
  g:=reval car groupname;
  if available!*p(g) then
  return alg!:characters(g);
end;

put('charactertable,'psopfn,'character!_table);

symbolic procedure character!_nr (groupname);
% prints the characters of the group
begin
scalar group,nr,char1;
  if length(groupname)>2 then rederr("too many arguments");
  if length(groupname)<2 then rederr("group or number missing");
  group:=reval car groupname;
  nr:=reval cadr groupname;
  if not(available!*p(group)) then 
     rederr("no information upon group available");
  if not(irr!:nr!:p(nr,group)) then 
       rederr("no character with this number");
  if !*complex then 
     char1:=get!*complex!*character(group,nr) else
     char1:=get!*real!*character(group,nr);
  return alg!:print!:character(char1);
end;

put('characternr,'psopfn,'character!_nr);

symbolic procedure irreducible!_rep!_table (groupname);
% prints the irreducible representations of the group
begin
scalar g;
  if length(groupname)>1 then rederr("too many arguments");
  if length(groupname)<1 then rederr("group missing");
  g:=reval car groupname;
  if available!*p(g) then
  return alg!:irr!:reps(g);
end;

put('irreduciblereptable,'psopfn,'irreducible!_rep!_table);

symbolic procedure irreducible!_rep!_nr (groupname);
% prints the irreducible representations of the group
begin
scalar g,nr;
  if length(groupname)>2 then rederr("too many arguments");
  if length(groupname)<2 then rederr("group or number missing");
  g:=reval car groupname;
  if not(available!*p(g)) then 
     rederr("no information upon group available");
  nr:=reval cadr groupname;
  if not(irr!:nr!:p(nr,g)) then 
       rederr("no irreducible representation with this number");
  if !*complex then 
       return 
    alg!:print!:rep(get!*complex!*irreducible!*rep(g,nr))
       else return
    alg!:print!:rep(get!*real!*irreducible!*rep(g,nr));
end;

put('irreduciblerepnr,'psopfn,'irreducible!_rep!_nr);

symbolic procedure canonical!_decomposition(representation);
% computes the canonical decomposition of the given representation
begin
scalar repr;
   if length(representation)>1 then rederr("too many arguments");
   repr:=reval car representation;
   if representation!:p(repr) then
   return alg!:can!:decomp(mk!_internal(repr));
end;

put('canonicaldecomposition,'psopfn,'canonical!_decomposition);

symbolic procedure sym!_character(representation);
% computes the character of the given representation
begin
scalar repr;
   if length(representation)>1 then rederr("too many arguments");
   if length(representation)<1 then 
   rederr("representation list missing");
   repr:=reval car representation;
   if representation!:p(repr) then
   return alg!:print!:character(mk!_character(mk!_internal(repr))) else
     rederr("that's no representation");
end;


put('character,'psopfn,'sym!_character);

symbolic procedure symmetry!_adapted!_basis (arg);
% computes the first part of the symmetry adapted bases of 
% the nr-th component
% arg = (representation,nr)
begin
scalar repr,nr,res;
   if length(arg)>2 then rederr("too many arguments");
   if length(arg)<2 then rederr("group or number missing");
   repr:=reval car arg;
   nr:=reval cadr arg;
   if representation!:p(repr) then
         repr:=mk!_internal(repr) else 
         rederr("that's no representation");
   if irr!:nr!:p(nr,get!_group!_in(repr)) then
       <<
          if not(null(mk!_multiplicity(repr,nr))) then 
             res:= mk!+outer!+mat(mk!_part!_sym!_all(repr,nr)) 
             else
             res:=nil;
       >> else
        rederr("wrong number of an irreducible representation");
   return res;
end;

put('symmetrybasis,'psopfn,'symmetry!_adapted!_basis);

symbolic procedure symmetry!_adapted!_basis!_part (arg);
% computes the first part of the symmetry adapted bases 
% of the nr-th component
% arg = (representation,nr)
begin
scalar repr,nr,res;
   if length(arg)>2 then rederr("too many arguments");
   if length(arg)<2 then rederr("group or number missing");
   repr:=reval car arg;
   nr:=reval cadr arg;
   if representation!:p(repr) then
         repr:=mk!_internal(repr) else 
         rederr("that's no representation");
   if irr!:nr!:p(nr,get!_group!_in(repr)) then
       <<
          if not(null(mk!_multiplicity(repr,nr))) then 
             res:= mk!+outer!+mat(mk!_part!_sym1(repr,nr)) 
             else
             res:=nil;
       >> else
        rederr("wrong number of an irreducible representation");
   return res;
end;

put('symmetrybasispart,'psopfn,'symmetry!_adapted!_basis!_part);

symbolic procedure symmetry!_bases (representation);
% computes the complete symmetry adapted basis
begin
scalar repr,res;
   if length(representation)>1 then rederr("too many arguments");
   if length(representation)<1 then rederr("representation missing");
   repr:=reval car representation;
   if representation!:p(repr) then
     <<
         res:= mk!+outer!+mat(mk!_sym!_basis(mk!_internal(repr)));
     >> else
       rederr("that's no representation");
    return res;
end;

put('allsymmetrybases,'psopfn,'symmetry!_bases);

symbolic procedure sym!_diagonalize (arg);
% diagonalizes a matrix with respect to a given representation
begin
scalar repr,matrix1;
   if (length(arg)>2) then rederr("too many arguments");
   if (length(arg)<2) then rederr("representation or matrix missing");
   repr:=reval cadr arg;
   matrix1:=reval (car arg);
   if alg!+matrix!+p(matrix1) then
        matrix1:=mk!+inner!+mat(matrix1)
        else
        rederr("first argument must be a matrix");
   if representation!:p(repr) then
       repr:=mk!_internal(repr) else
       rederr("that's no representation");
   if symmetry!:p(matrix1,repr) then
   return mk!+outer!+mat(mk!_diagonal(
          matrix1,repr)) else
   rederr("matrix has not the symmetry of this representation");
end;

put('diagonalize,'psopfn,'sym!_diagonalize);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% function to add new groups to the database by the user
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure set!_generators!_group (arg);
% a group is generated by some elements
begin
scalar group, generators,relations,rel;
   if length(arg)>3 then rederr("too many arguments");
   if length(arg)<2 then
      rederr("group identifier or generator list missing");
   group:=reval car arg;
   generators:=reval cadr arg;
   if length(arg)=3 then 
          relations:=reval caddr arg else 
          relations:=nil;
   if not(idp(group)) then
        rederr("first argument must be a group identifier");
   generators:=mk!+inner!+list(generators);
   if not(identifier!:list!:p(generators)) then
     rederr("second argument must be a list of generator identifiers")
        else set!*generators(group,generators);
   relations:=mk!_relation!_list(relations);
   for each rel in relations do 
       if not(relation!:list!:p(group,rel)) then 
          rederr("equations in generators are demanded");
   set!*relations(group,relations);
   writepri("setgenerators finished",'only);
end;

put('setgenerators,'psopfn,'set!_generators!_group);

symbolic procedure set!_elements(arg);
% each element<>id of a group has a representation
% as product of generators
% the identity is called id
begin
scalar elemreps,replist,elems,group;
   if length(arg)>2 then rederr("too many arguments");
   if length(arg)<2 then 
 rederr("missing group or list with group elements with generators ");
   group:=reval car arg;
   if not(idp(group)) then
        rederr("first argument must be a group identifier");
   elemreps:=reval cadr arg;
   elemreps:=mk!_relation!_list(elemreps);
   for each replist in elemreps do
     if not(generator!:list!:p(group,cadr replist)) then
       rederr("group elements should be represented in generators");
   for each replist in elemreps do
     if not((length(car replist)=1) and idp(caar replist)) then
       rederr("first must be one group element");
   elems:= for each replist in elemreps collect caar replist;
   elems:=append(list('id),elems);
   set!*elems!*group(group,elems);
   set!*elemasgen(group,elemreps);
   writepri("setelements finished",'only);
end;

put('setelements,'psopfn,'set!_elements);

symbolic procedure set!_group!_table (arg);
% a group table gives the result of the product of two elements
begin
scalar table,group,z,s;
   if length(arg)>2 then rederr("too many arguments");
   if length(arg)<2 then 
      rederr("missing group or group table as a matrix ");
   group:=reval car arg;
   if not(idp(group)) then
        rederr("first argument must be a group identifier");
   table:=reval cadr arg;
   if alg!+matrix!+p(table) then 
       table:=mk!+inner!+mat(table);
   table:=for each z in table collect
        for each s in z collect prepsq(s);
   if group!:table!:p(group,table) then
     <<
        set!*grouptable(group,table);
        set!*inverse(group,mk!*inverse!*list(table));
        set!*group(group,mk!*equiclasses(table));
        set!*storing(group);
     >> else rederr("table is not a group table");
   writepri("setgrouptable finished",'only);
end;

put('setgrouptable,'psopfn,'set!_group!_table);

symbolic procedure set!_real!_rep(arg);
% store the real irreducible representations
begin
scalar replist,type;
   if length(arg)>2 then rederr("too many arguments");
   if length(arg)<2 then 
      rederr("representation or type missing");
   replist:=reval car arg;
   type:=reval cadr arg;
   if (not(type= 'realtype) and not(type = 'complextype)) then
       rederr("only real or complex types possible"); 
   if get!*order(get!_group!_out(replist))=0 then 
         rederr("elements of the groups must be set first");
   if representation!:p(replist) then
         replist:=(mk!_internal(replist));
   set!*representation(get!_group!_in(replist),
          append(list(type),cdr replist),'real);
   writepri("Rsetrepresentation finished",'only);
end;

put('Rsetrepresentation,'psopfn,'set!_real!_rep);

symbolic procedure set!_complex!_rep(arg);
% store the complex irreducible representations
begin
scalar replist;
   if length(arg)>1 then rederr("too many arguments");
   if length(arg)<1 then 
      rederr("representation missing");
   replist:=reval car arg;
   if get!*order(get!_group!_out(replist))=0 then 
         rederr("elements of the groups must be set first");
   if representation!:p(replist) then
         replist:=(mk!_internal(replist));
   set!*representation(get!_group!_in(replist),cdr replist,'complex);
   writepri("Csetrepresentation finished",'only);
end;

put('Csetrepresentation,'psopfn,'set!_complex!_rep);

symbolic procedure mk!_available(arg);
% group is only then made available, if all information was given
begin
scalar group;
   if length(arg)>1 then rederr("too many arguments");
   if length(arg)<1 then 
      rederr("group identifier missing");
   group:=reval car arg;
   if check!:complete!:rep!:p(group) then
       set!*available(group);
   writepri("setavailable finished",'only);
end;

put('setavailable,'psopfn,'mk!_available);

symbolic procedure update!_new!_group (arg);
% stores the user defined new abstract group in a file
begin
scalar group;
   if length(arg)>2 then rederr("too many arguments");
   if length(arg)<2 then 
      rederr("group or filename missing");
   group:=reval car arg;
   if available!*p(group) then write!:to!:file(group,reval cadr arg);
   writepri("storegroup finished",'only);
end;

put('storegroup,'psopfn,'update!_new!_group);

procedure loadgroups(fname);
% loads abstract groups from a file which was created from a user
% by newgroup and updategroup
begin
  in fname;
  write"group loaded";
end;

endmodule;

module symatvec;

% Symmetry 

% Author : Karin Gatermann
%         Konrad-Zuse-Zentrum fuer
%         Informationstechnik Berlin
%         Heilbronner Str. 10
%         W-1000 Berlin 31
%         Germany
%         Email: Gatermann@sc.ZIB-Berlin.de


% symatvec.red

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  functions for matrix vector operations
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure gen!+can!+bas(dimension);
% returns the canonical basis of R^dimension as a vector list
begin
scalar eins,nullsq,i,j,ll;
   eins:=(1 ./ 1);
   nullsq:=(nil ./ 1);
   ll:= for i:=1:dimension collect
           for j:=1:dimension collect
              if i=j then eins else nullsq;
   return ll; 
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  matrix functions
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure alg!+matrix!+p(mat1);
% returns true if the matrix is a matrix from algebraic level
begin
scalar len,elem;
  if length(mat1)<1 then rederr("should be a matrix");
  if not(car (mat1) = 'mat) then rederr("should be a matrix");
  mat1:=cdr mat1;
  if length(mat1)<1 then rederr("should be a matrix");
  len:=length(car mat1);
  for each elem in cdr mat1 do
    if not(length(elem)=len) then rederr("should be a matrix");
  return t;
end;

symbolic procedure matrix!+p(mat1);
% returns true if the matrix is a matrix in internal structure
begin
scalar dimension,z,res;
  if length(mat1)<1 then return nil;
  dimension:=length(car mat1);
  res:=t;
  for each z in cdr mat1 do
    if not(dimension = length(z)) then res:=nil;
  return res;
end;

symbolic procedure squared!+matrix!+p(mat1);
% returns true if the matrix is a matrix in internal structure
begin
  if (matrix!+p(mat1) and (get!+row!+nr(mat1) = get!+col!+nr(mat1)))
      then return t;
end;

symbolic procedure equal!+matrices!+p(mat1,mat2);
% returns true if the matrices are equal ( internal structure)
begin
scalar s,z,helpp,mathelp,sum,rulesum,rule1,rule2;
   if (same!+dim!+squared!+p(mat1,mat2)) then
       <<
           mathelp:=
             mk!+mat!+plus!+mat(mat1,
                 mk!+scal!+mult!+mat((-1 ./ 1),mat2));
           sum:=(nil ./ 1);
           for each z in mathelp do
                for each s in z do
                  if !*complex then
                     sum:=addsq(sum,multsq(s,mk!+conjugate!+sq s)) else
                     sum:=addsq(sum,multsq(s,s));
      %      print!-sq(sum);
      rulesum:=change!+sq!+to!+algnull(sum);
      if rulesum = 0 then helpp:=t else helpp:=nil;
 %     print!-sq(simp rulesum);
%           if null(numr(simp prepsq(sum))) then helpp:=t 
% else helpp:=nil;
       >> else helpp:=nil;
   return helpp;
end;

symbolic procedure get!+row!+nr(mat1);
% returns the number of rows
begin
   return length(mat1);
end;

symbolic procedure get!+col!+nr(mat1);
% returns the number of columns
begin
   return length(car mat1);
end;

symbolic procedure get!+mat!+entry(mat1,z,s);
% returns the matrix element in row z and column s
begin
   return nth(nth(mat1,z),s);
end;

symbolic procedure same!+dim!+squared!+p(mat1,mat2);
% returns true if the matrices are both squared matrices 
% of the same dimension
% (internal structur)
begin
  if (squared!+matrix!+p(mat1) and squared!+matrix!+p(mat2) and
       (get!+row!+nr(mat1) = get!+row!+nr(mat1))) 
          then return t;
end;

symbolic procedure mk!+transpose!+matrix(mat1);
% returns the transposed matrix (internal structure)
begin
scalar z,s,tpmat;
  if not(matrix!+p(mat1)) then rederr("no matrix in transpose");
  tpmat:=for z:=1:get!+col!+nr(mat1) collect
           for s:=1:get!+row!+nr(mat1) collect
                get!+mat!+entry(mat1,s,z);
  return tpmat; 
end;

symbolic procedure mk!+conjugate!+matrix(mat1);
% returns the matrix with conjugate elements (internal structure)
begin
scalar z,s,tpmat;
  if not(matrix!+p(mat1)) then rederr("no matrix in conjugate matrix");
  tpmat:=for z:=1:get!+row!+nr(mat1) collect
           for s:=1:get!+col!+nr(mat1) collect
              mk!+conjugate!+sq(get!+mat!+entry(mat1,z,s));
  return tpmat; 
end;

symbolic procedure mk!+hermitean!+matrix(mat1);
% returns the transposed matrix (internal structure)
begin
   if !*complex then
   return mk!+conjugate!+matrix(mk!+transpose!+matrix(mat1)) else
   return mk!+transpose!+matrix(mat1);
end;

symbolic procedure unitarian!+p(mat1);
% returns true if matrix is orthogonal or unitarian resp.
begin
scalar mathermit,unitmat;
  mathermit:=mk!+mat!+mult!+mat(mk!+hermitean!+matrix(mat1),mat1);
  unitmat:=mk!+unit!+mat(get!+row!+nr(mat1));
  if equal!+matrices!+p(mathermit,unitmat) then return t;
end;

symbolic procedure mk!+mat!+mult!+mat(mat1,mat2);
% returns a matrix= matrix1*matrix2 (internal structure)
begin
scalar dims1,dimz1,dims2,s,z,res,sum,k;
  if not(matrix!+p(mat1)) then rederr("no matrix in mult");
  if not(matrix!+p(mat2)) then rederr("no matrix in mult");
  dims1:=get!+col!+nr(mat1);
  dimz1:=get!+row!+nr(mat1);
  dims2:=get!+col!+nr( mat2);
  if not(dims1 = get!+row!+nr(mat2)) then 
     rederr("matrices can not be multiplied");
  res:=for z:=1:dimz1 collect
         for s:=1:dims2 collect
           <<
              sum:=(nil ./ 1);
              for k:=1:dims1 do 
               sum:=addsq(sum,
                      multsq(
                       get!+mat!+entry(mat1,z,k),
                       get!+mat!+entry(mat2,k,s)
                             )
                          );
              sum:=subs2 sum where !*sub2=t;
              sum
           >>;
   return res;
end;

symbolic procedure mk!+mat!+plus!+mat(mat1,mat2);
% returns a matrix= matrix1 + matrix2 (internal structure)
begin
scalar dims,dimz,s,z,res,sum;
  if not(matrix!+p(mat1)) then rederr("no matrix in add");
  if not(matrix!+p(mat2)) then rederr("no matrix in add");
  dims:=get!+col!+nr(mat1);
  dimz:=get!+row!+nr(mat1);
  if not(dims = get!+col!+nr(mat2)) then
          rederr("wrong dimensions in add");
  if not(dimz = get!+row!+nr(mat2)) then
          rederr("wrong dimensions in add");
  res:=for z:=1:dimz collect
          for s:=1:dims collect
           <<
            sum:=addsq(
                   get!+mat!+entry(mat1,z,s),
                   get!+mat!+entry(mat2,z,s)
                 );
              sum:=subs2 sum where !*sub2=t;
              sum      
           >>;
  return res;
end;

symbolic procedure mk!+mat!*mat!*mat(mat1,mat2,mat3);
% returns a matrix= matrix1*matrix2*matrix3 (internal structure)
begin
scalar res;
  res:= mk!+mat!+mult!+mat(mat1,mat2);
  return mk!+mat!+mult!+mat(res,mat3);
end;

symbolic procedure add!+two!+mats(mat1,mat2);
% returns a matrix=( matrix1, matrix2 )(internal structure)
begin
scalar dimz,z,res;
  if not(matrix!+p(mat1)) then rederr("no matrix in add");
  if not(matrix!+p(mat2)) then rederr("no matrix in add");
  dimz:=get!+row!+nr(mat1);
  if not(dimz = get!+row!+nr(mat2)) then rederr("wrong dim in add");
  res:=for z:=1:dimz collect
      append(nth(mat1,z),nth(mat2,z));
  return res;
end;

symbolic procedure mk!+scal!+mult!+mat(scal1,mat1);
% returns a matrix= scalar*matrix (internal structure)
begin
scalar res,z,s,prod;
  if not(matrix!+p(mat1)) then rederr("no matrix in add");
  res:=for each z in mat1 collect
         for each s in z collect
           <<
              prod:=multsq(scal1,s);
              prod:=subs2 prod where !*sub2=t;
              prod
           >>;
  return res;
end;

symbolic procedure mk!+trace(mat1);
% returns the trace of the matrix (internal structure)
begin
scalar spur,s;
  if not(squared!+matrix!+p(mat1)) then
          rederr("no square matrix in add");
  spur:=(nil ./ 1);
  for s:=1:get!+row!+nr(mat1) do
     spur:=addsq(spur,get!+mat!+entry(mat1,s,s));
   spur:=subs2 spur where !*sub2=t;
  return spur;
end;

symbolic procedure mk!+block!+diagonal!+mat(mats);
% returns a blockdiagonal matrix from 
% a list of matrices (internal structure)
begin
  if length(mats)<1 then rederr("no list in mkdiagonalmats");
  if length(mats)=1 then return car mats else
     return fill!+zeros(car mats,mk!+block!+diagonal!+mat(cdr(mats)));
end;

symbolic procedure fill!+zeros(mat1,mat2);
% returns a blockdiagonal matrix from 2 matrices (internal structure)
begin
scalar nullmat1,nullmat2;
  nullmat1:=mk!+null!+mat(get!+row!+nr(mat2),get!+col!+nr(mat1));
  nullmat2:=mk!+null!+mat(get!+row!+nr(mat1),get!+col!+nr(mat2));
  return append(add!+two!+mats(mat1,nullmat2),
                    add!+two!+mats(nullmat1,mat2));
end;

symbolic procedure mk!+outer!+mat(innermat);
% returns a matrix for algebraic level
begin
 scalar res,s,z;
 if not(matrix!+p(innermat)) then rederr("no matrix in mkoutermat");
 res:= for each z in innermat collect
        for each s in z collect
            prepsq s;
 return append(list('mat),res);
end;

symbolic procedure mk!+inner!+mat(outermat);
% returns a matrix in internal structure
begin
   scalar res,s,z;
   res:= for each z in cdr outermat collect
          for each s in z collect
             simp s;
   if matrix!+p(res) then return res else 
        rederr("incorrect input in mkinnermat");
end;

symbolic procedure mk!+resimp!+mat(innermat);
% returns a matrix in internal structure
begin
   scalar res,s,z;
   res:= for each z in innermat collect
          for each s in z collect
             resimp s;
   return res;
end;

symbolic procedure mk!+null!+mat(dimz,dims);
% returns a matrix of zeros in internal structure
begin
scalar nullsq,s,z,res;
   nullsq:=(nil ./ 1);
   res:=for z:=1:dimz collect
           for s:=1:dims collect  nullsq;
  return res;
end;

symbolic procedure mk!+unit!+mat(dimension);
% returns a squared unit matrix in internal structure
begin
   return gen!+can!+bas(dimension);
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  vector functions
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure vector!+p(vector1);
% returns the length of a vector
% vector -- list of sqs
begin
  if length(vector1)>0 then return t;
end;

symbolic procedure get!+vec!+dim(vector1);
% returns the length of a vector
% vector -- list of sqs
begin
  return length(vector1);
end;

symbolic procedure get!+vec!+entry(vector1,elem);
% returns the length of a vector
% vector -- list of sqs
begin
  return nth(vector1,elem);
end;

symbolic procedure mk!+mat!+mult!+vec(mat1,vector1);
% returns a vector= matrix*vector (internal structure)
begin
scalar z;
  return for each z in mat1 collect
           mk!+real!+inner!+product(z,vector1);
end;

symbolic procedure mk!+scal!+mult!+vec(scal1,vector1);
% returns a vector= scalar*vector (internal structure)
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

symbolic procedure mk!+vec!+add!+vec(vector1,vector2);
% returns a vector= vector1+vector2 (internal structure)
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
% returns a scalar= sum vector_i^2 (internal structure)
begin
   return mk!+inner!+product(vector1,vector1);
end;

symbolic procedure my!+nullsq!+p(scal);
% returns true, if ths sq is zero
begin
   if null(numr( scal)) then return t;
end;

symbolic procedure mk!+null!+vec(dimen);
% returns a vector of zeros
begin
scalar nullsq,i,res;
   nullsq:=(nil ./ 1);
   res:=for i:=1:dimen collect nullsq;
   return res;
end;

symbolic procedure mk!+conjugate!+vec(vector1);
% returns a vector of zeros
begin
scalar z,res;
   res:=for each z in vector1  collect mk!+conjugate!+sq(z);
   return res;
end;

symbolic procedure null!+vec!+p(vector1);
% returns a true, if vector is the zero vector
begin
    if my!+nullsq!+p(mk!+squared!+norm(vector1)) then
       return t;
end;

symbolic procedure mk!+normalize!+vector(vector1);
% returns a normalized vector (internal structure)
begin
scalar scalo,vecres;
  scalo:=simp!* {'sqrt, mk!*sq(mk!+squared!+norm(vector1))};
  if my!+nullsq!+p(scalo) then 
     vecres:= mk!+null!+vec(get!+vec!+dim(vector1)) else
      <<
         scalo:=simp prepsq scalo;
         scalo:=quotsq((1 ./ 1),scalo);
         vecres:= mk!+scal!+mult!+vec(scalo,vector1);
      >>;
  return vecres;
end;

symbolic procedure mk!+inner!+product(vector1,vector2);
% returns the inner product of vector1 and vector2 (internal structure)
begin
scalar z,sum,vec2;
  if not(get!+vec!+dim(vector1) = get!+vec!+dim(vector2)) then
        rederr("wrong dimensions in innerproduct");
  sum:=(nil ./ 1);
  if !*complex then vec2:=mk!+conjugate!+vec(vector2) else
    vec2:=vector2;
  for z:=1:get!+vec!+dim(vector1) do 
      sum:=addsq(sum,multsq(
            get!+vec!+entry(vector1,z),
            get!+vec!+entry(vec2,z)
                           )
                );
  sum:=subs2 sum where !*sub2=t;
  return sum;
end;

symbolic procedure mk!+real!+inner!+product(vector1,vector2);
% returns the inner product of vector1 and vector2 (internal structure)
begin
scalar z,sum;
  if not(get!+vec!+dim(vector1) = get!+vec!+dim(vector2)) then
        rederr("wrong dimensions in innerproduct");
  sum:=(nil ./ 1);
  for z:=1:get!+vec!+dim(vector1) do 
      sum:=addsq(sum,multsq(
            get!+vec!+entry(vector1,z),
            get!+vec!+entry(vector2,z)
                           )
                );
  sum:=subs2 sum where !*sub2=t;
  return sum;
end;

symbolic procedure mk!+Gram!+Schmid(vectorlist,vector1);
% returns a vectorlist of orthonormal vectors
% assumptions: vectorlist is orthonormal basis, internal structure
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
  if null!+vec!+p(orthovec) then 
     vectors:=vectorlist else
     vectors:=add!+vector!+to!+list(orthovec,vectorlist);
  return vectors;
end;

symbolic procedure Gram!+Schmid(vectorlist);
% returns a vectorlist of orthonormal vectors
begin
scalar ortholist,i;
  if length(vectorlist)<1 then rederr("error in Gram Schmid");
  if vector!+p(car vectorlist) then    
      ortholist:=nil
        else rederr("strange in Gram-Schmid");
  for i:=1:length(vectorlist) do
        ortholist:=mk!+Gram!+Schmid(ortholist,nth(vectorlist,i));
  return ortholist;
end;

symbolic procedure add!+vector!+to!+list(vector1,vectorlist);
% returns a list of vectors consisting of vectorlist 
% and the vector1 at the end
% internal structure
begin
    return append(vectorlist,list(vector1));
end;

symbolic procedure mk!+internal!+mat(vectorlist);
% returns a matrix consisting of columns 
% equal to the vectors in vectorlist
% internal structure
begin
  return mk!+transpose!+matrix(vectorlist);
end;

symbolic procedure mat!+veclist(mat1);
% returns a vectorlist consisting of the columns of the matrix
% internal structure
begin
  return mk!+transpose!+matrix(mat1);
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% some useful functions
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure change!+sq!+to!+int(scal1);
% scal1 -- sq which is an integer
% result is a nonnegative integer
begin 
  scalar nr;
  nr:=simp!* prepsq scal1;
  if (denr(nr) = 1) then return numr(nr) else
    rederr("no integer in change!+sq!+to!+int");
end;

symbolic procedure change!+int!+to!+sq(scal1);
% scal1 --  integer for example 1 oder 2 oder 3
% result is a sq
begin 
  return (scal1 ./ 1);
end;

symbolic procedure change!+sq!+to!+algnull(scal1);
begin
scalar rulesum,storecomp;
           if !*complex then
              <<
                 storecomp:=t;
                 off complex;
              >> else
              <<
                 storecomp:=nil;
              >>;
          rulesum:=evalwhereexp ({'(list (list 
 (REPLACEBY 
   (COS (!~ X))
   (TIMES
      (QUOTIENT 1 2)
 (PLUS (EXPT E (TIMES I (!~ X))) (EXPT E (MINUS (TIMES I (!~ X))))) ))
 (REPLACEBY 
   (SIN (!~ X))
   (TIMES
      (QUOTIENT 1 (times 2 i))
 (difference (EXPT E (TIMES I (!~ X)))
      (EXPT E (MINUS (TIMES I (!~ X))))) ))

))
, prepsq(scal1)});
  rulesum:=reval rulesum;
  if storecomp then on complex;
 % print!-sq(simp (rulesum));
  return rulesum;
end;

symbolic procedure mk!+conjugate!+sq(mysq);
begin
    return conjsq(mysq);
 %   return subsq(mysq,'(( i . (minus i))));
end;

symbolic procedure mk!+equation(arg1,arg2);
begin
  return list('equal,arg1,arg2);
end;

symbolic procedure outer!+equation!+p(outerlist);
begin
    if eqcar(outerlist, 'equal) then return t
end;

symbolic procedure mk!+outer!+list(innerlist);
begin
  return append (list('list),innerlist)
end;

symbolic procedure mk!+inner!+list(outerlist);
begin
   if outer!+list!+p(outerlist) then return cdr outerlist;
end;

symbolic procedure outer!+list!+p(outerlist);
begin
  if eqcar(outerlist, 'list) then return t
end;

symbolic procedure equal!+lists!+p(ll1,ll2);
begin
  return (list!+in!+list!+p(ll1,ll2) and list!+in!+list!+p(ll2,ll1));
end;

symbolic procedure list!+in!+list!+p(ll1,ll2);
begin
  if length(ll1)=0 then return t else
       return (memq(car ll1,ll2) and list!+in!+list!+p(cdr ll1,ll2));
end;

symbolic procedure print!-matrix(mat1);
begin
  writepri (mkquote mk!+outer!+mat(mat1),'only);
end;

symbolic procedure print!-sq(mysq);
begin
  writepri (mkquote prepsq(mysq),'only);
end;

endmodule;

module symcheck;
%
% Symmetry Package 
%
% Author : Karin Gatermann
%         Konrad-Zuse-Zentrum fuer
%         Informationstechnik Berlin
%         Heilbronner Str. 10
%         W-1000 Berlin 31
%         Germany
%         Email: Gatermann@sc.ZIB-Berlin.de


% symcheck.red

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  check user input -- used by functions in sym_main.red
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure representation!:p(rep);
% returns true, if rep is a representation
begin
scalar group,elem,mats,mat1,dim1;
  if length(rep)<0 then rederr("list too short");
  if not(outer!+list!+p(rep)) then rederr("argument should be a list");
  if (length(rep)<2) then rederr("empty list is not a representation");
  group:=get!_group!_out(rep);
  if not(available!*p(group) or storing!*p(group)) then 
   rederr("one element must be an identifier of an available group");
  mats:=for each elem in get!*generators(group) collect
        get!_repmatrix!_out(elem,rep);
  for each mat1 in mats do
     if not(alg!+matrix!+p(mat1)) then 
        rederr("there should be a matrix for each generator");
  mats:=for each mat1 in mats collect mk!+inner!+mat(mat1);
  for each mat1 in mats do
     if not(squared!+matrix!+p(mat1)) then 
        rederr("matrices should be squared");
  mat1:=car mats;
  mats:=cdr mats;
  dim1:=get!+row!+nr(mat1);
  while length(mats)>0 do
    <<
      if not(dim1=get!+row!+nr(car mats)) then 
         rederr("representation matrices must have the same dimension");
      mat1:=car mats;
      mats:= cdr mats;
    >>;
  return t;
end;

symbolic procedure irr!:nr!:p(nr,group);
% returns true, if group is a group and information is available
% and nr is number of an irreducible representation
begin
  if not(fixp(nr)) then rederr("nr should be an integer");
  if (nr>0 and nr<= get!_nr!_irred!_reps(group)) then
        return t;
end;

symbolic procedure symmetry!:p(matrix1,representation);
% returns true, if the matrix has the symmetry of this representation
% internal structures
begin
scalar group,glist,symmetryp,repmat;
   group:=get!_group!_in(representation);
   glist:=get!*generators(group);
   symmetryp:=t;
   while (symmetryp and (length(glist)>0)) do
      <<
         repmat:=get!_rep!_matrix!_in(car glist,representation);
         if not (equal!+matrices!+p(
                mk!+mat!+mult!+mat(repmat,matrix1),
                mk!+mat!+mult!+mat(matrix1,repmat)) ) then
                  symmetryp:=nil;
         glist:= cdr glist;
      >>;
  return symmetryp;
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  check functions used by definition of the group
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure identifier!:list!:p(idlist);
% returns true if idlist is a list of identifiers
begin
  if length(idlist)>0 then 
      <<
         if idp(car idlist) then 
             return identifier!:list!:p(cdr idlist);
      >> else
      return t;
end;

symbolic procedure generator!:list!:p(group,generatorl);
% returns true if generatorl is an idlist 
% consisting of the generators of the group
begin
scalar element,res;
  res:=t;
  if length(generatorl)<1 then 
              rederr("there should be a list of generators");
  if length(get!*generators(group))<1 then 
              rederr("there are no group generators stored");
  if not(identifier!:list!:p(generatorl)) then return nil;
  for each element in generatorl do
        if not(g!*generater!*p(group,element)) then
            res:=nil;
  return res;
end;

symbolic procedure relation!:list!:p(group,relations);
% relations -- list of two generator lists
begin
  if length(get!*generators(group))<1 then 
              rederr("there are no group generators stored");
  return (relation!:part!:p(group,car relations) and
          relation!:part!:p(group,cadr relations))
end;

symbolic procedure relation!:part!:p(group,relationpart);
% relations -- list of two generator lists
begin
scalar generators,res,element;
  res:=t;
  generators:=get!*generators(group);
  if length(generators)<1 then 
              rederr("there are no group generators stored");
  if length(relationpart)<1 then 
              rederr("wrong relation given");
  if not(identifier!:list!:p(relationpart)) then return nil;
  generators:=append(list('id),generators);
  for each element in relationpart do
       if not(memq(element,generators)) then res:=nil;
  return res;
end;

symbolic procedure group!:table!:p(group,gtable);
% returns true, if gtable is a group table
% gtable - matrix in internal representation
begin
scalar row;
  if not(get!+mat!+entry(gtable,1,1) = 'grouptable) then 
  rederr("first diagonal entry in a group table must be grouptable");
  for each row in gtable do
       if not(group!:elemts!:p(group,cdr row)) then 
            rederr("this should be a group table");
  for each row in mk!+transpose!+matrix(gtable) do
       if not(group!:elemts!:p(group,cdr row)) then 
            rederr("this should be a group table");
  return t;
end;

symbolic procedure group!:elemts!:p(group,elems);
% returns true if each element of group appears exactly once in the list
begin
   return equal!+lists!+p(get!*elements(group),elems);
end;

symbolic procedure check!:complete!:rep!:p(group);
% returns true if sum ni^2 = grouporder and
%                 sum realni = sum complexni 
begin
scalar nr,j,sum,dime,order1,sumreal,chars,complexcase;
    nr:=get!*nr!*complex!*irred!*reps(group);
    sum:=(nil ./ 1);
    for j:=1:nr do 
       <<
         dime:=change!+int!+to!+sq( get!_dimension!_in(
                get!*complex!*irreducible!*rep(group,j)));
         sum:=addsq(sum,multsq(dime,dime));
       >>;
    order1:=change!+int!+to!+sq(get!*order(group));
    if not(null(numr(addsq(sum,negsq(order1))))) then 
        rederr("one complex irreducible representation missing or
                    is not irreducible");
    sum:=(nil ./ 1);
    for j:=1:nr do 
       <<
         dime:=change!+int!+to!+sq( get!_dimension!_in(
                get!*complex!*irreducible!*rep(group,j)));
         sum:=addsq(sum,dime);
       >>;
    chars:=for j:=1:nr collect  
            get!*complex!*character(group,j);
    if !*complex then
      <<
        complexcase:=t;
      >> else
      <<
        complexcase:=nil;
        on complex;
      >>;
    if not(orthogonal!:characters!:p(chars)) then
          rederr("characters are not orthogonal");
    if null(complexcase) then off complex;
    nr:=get!*nr!*real!*irred!*reps(group);
    sumreal:=(nil ./ 1);
    for j:=1:nr do 
       <<
         dime:=change!+int!+to!+sq( get!_dimension!_in(
                get!*real!*irreducible!*rep(group,j)));
         sumreal:=addsq(sumreal,dime);
       >>;
    chars:=for j:=1:nr collect  
            get!*real!*character(group,j);
    if not(orthogonal!:characters!:p(chars)) then
          rederr("characters are not orthogonal");
    if not(null(numr(addsq(sum,negsq(sumreal))))) then 
  rederr("list real irreducible representation incomplete or wrong");
  return t;
end;

symbolic procedure orthogonal!:characters!:p(chars);
% returns true if all characters in list are pairwise orthogonal
begin
scalar chars1,chars2,char1,char2;
  chars1:=chars;
  while (length(chars1)>0) do
    <<
      char1:=car chars1;
      chars1:=cdr chars1;
      chars2:=chars1;
         while (length(chars2)>0) do
            <<
               char2:=car chars2;
               chars2:=cdr chars2;
               if not(change!+sq!+to!+algnull(
                      char!_prod(char1,char2))=0) 
                  then rederr("not orthogonal");
            >>;
    >>;
  return t; 
end;

symbolic procedure write!:to!:file(group,filename);
begin
scalar nr,j;
if not(available!*p(group)) then rederr("group is not available");
out filename;
rprint(list
   ('off, 'echo));
rprint('symbolic);
rprint(list
   ('set!*elems!*group ,mkquote group,mkquote get!*elements(group)));
rprint(list
   ('set!*generators, mkquote group,mkquote get!*generators(group)));
rprint(list
   ('set!*relations, mkquote group,
       mkquote get!*generator!*relations(group)));
rprint(list
   ('set!*grouptable, mkquote group,mkquote get(group,'grouptable)));
rprint(list
   ('set!*inverse, mkquote group,mkquote get(group,'inverse)));
rprint(list
   ('set!*elemasgen, mkquote group
          ,mkquote get(group,'elem!_in!_generators)));
rprint(list
   ('set!*group, mkquote group,mkquote get(group,'equiclasses)));

nr:=get!*nr!*complex!*irred!*reps(group);
   for j:=1:nr do
     <<
       rprint(list
   ('set!*representation, mkquote group,
           mkquote cdr get!*complex!*irreducible!*rep(group,j),
            mkquote 'complex));
     >>;
nr:=get!*nr!*real!*irred!*reps(group);
   for j:=1:nr do
     <<
       rprint(list
   ('set!*representation, mkquote group,
           mkquote get(group,mkid('realrep,j)),mkquote 'real));
     >>;
rprint(list(
    'set!*available,mkquote group));
rprint('algebraic);
rprint('end);
shut filename;
end;


symbolic procedure mk!_relation!_list(relations);
% input: outer structure : reval of {r*s*r^2=s,...}
% output: list of pairs of lists
begin
scalar twolist,eqrel;
  if not(outer!+list!+p(relations)) then 
       rederr("this should be a list");
  twolist:=for each eqrel in mk!+inner!+list(relations) collect
       change!_eq!_to!_lists(eqrel);
  return twolist;
end;

symbolic procedure change!_eq!_to!_lists(eqrel);
begin
 if not(outer!+equation!+p(eqrel)) then 
    rederr("equations should be given");
 return list(mk!_side!_to!_list(reval cadr eqrel),
             mk!_side!_to!_list(reval caddr eqrel));
end;

symbolic procedure mk!_side!_to!_list(identifiers);
begin
scalar i;
  if idp(identifiers) then return list(identifiers);
  if eqcar(identifiers,'Plus) then rederr("no addition in this group");
  if eqcar(identifiers,'EXPT) then 
     return for i:=1:(caddr identifiers) collect (cadr identifiers);
  if eqcar(identifiers,'TIMES) then 
     rederr("no multiplication with * in this group");
if eqcar(identifiers,'!@) then
     return append(mk!_side!_to!_list(cadr identifiers),
                  mk!_side!_to!_list(caddr identifiers));
end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  pass to algebraic level
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure alg!:print!:group(group);
% returns the group element list in correct algebraic mode
begin
  return mk!+outer!+list(get!*elements(group));
end;

symbolic procedure alg!:generators(group);
% returns the generator list of a group in correct algebraic mode
begin
  return append(list('list),get!*generators(group));
end;

symbolic procedure alg!:characters(group);
% returns the (real od complex) character table 
% in correct algebraic mode
begin
scalar nr,i,charlist,chari;
  nr:=get!_nr!_irred!_reps(group);
  charlist:=for i:=1:nr collect
     if !*complex then 
        get!*complex!*character(group,i) else
        get!*real!*character(group,i);
  charlist:= for each chari in charlist collect
        alg!:print!:character(chari);
  return mk!+outer!+list(charlist);
end;

symbolic procedure alg!:irr!:reps(group);
% returns the (real od complex) irr. rep. table 
% in correct algebraic mode
begin
scalar repi,reps,nr,i;
  nr:=get!_nr!_irred!_reps(group);
  reps:=for i:=1:nr collect
     if !*complex then 
        get!*complex!*irreducible!*rep(group,nr) else
        get!*real!*irreducible!*rep(group,i);
  reps:= for each repi in reps collect
        alg!:print!:rep(repi);
  return mk!+outer!+list(reps);
end;

symbolic procedure alg!:print!:rep(representation);
% returns the representation in correct algebraic mode
begin
scalar pair,repr,group,mat1,g;
  group:=get!_group!_in(representation);
  repr:=eli!_group!_in(representation);
  repr:= for each pair in repr collect
      <<
          mat1:=cadr pair;
          g:=car pair;
          mat1:=mk!+outer!+mat(mat1);
          mk!+equation(g,mat1)
      >>;
  repr:=append(list(group),repr);
  return mk!+outer!+list(repr)
end;

symbolic procedure alg!:can!:decomp(representation);
% returns the canonical decomposition in correct algebraic mode
% representation in internal structure
begin
scalar nr,nrirr,ints,i,sum;
   nrirr:=get!_nr!_irred!_reps(get!_group!_in(representation));
   ints:=for nr:=1:nrirr collect
       mk!_multiplicity(representation,nr);
   sum:=( nil ./ 1);
   ints:= for i:=1:length(ints) do
      sum:=addsq(sum,
             multsq(change!+int!+to!+sq(nth(ints,i)),
                   simp mkid('teta,i)
                  )
                );
   return mk!+equation('teta,prepsq sum);
end;

symbolic procedure alg!:print!:character(character);
% changes the character from internal representation
% to printable representation
begin
scalar group,res,equilists;
  group:=get!_char!_group(character);
  res:=get!*all!*equi!*classes(group);
  res:= for each equilists in res collect
         mk!+outer!+list(equilists);
  res:= for each equilists in res collect
          mk!+outer!+list( list(equilists,
            prepsq get!_char!_value(character,cadr equilists)));
  res:=append(list(group),res);
  return mk!+outer!+list(res);
end;

endmodule;

module symchrep;
%
% Symmetry Package 
%
% Author : Karin Gatermann
%         Konrad-Zuse-Zentrum fuer
%         Informationstechnik Berlin
%         Heilbronner Str. 10
%         W-1000 Berlin 31
%         Germany
%         Email: Gatermann@sc.ZIB-Berlin.de


% symchrep.red

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  functions for representations in iternal structure
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure mk!_internal(representation);
% transfers the user given representation structure to the
% internal structure
begin
scalar group,elems,generators,repgenerators,g,res;
  group:=get!_group!_out(representation);
  elems:=get!*elements(group);
  generators:=get!*generators(group);
  repgenerators:=mk!_rep!_relation(representation,generators);
  if not(hard!_representation!_check!_p(group,repgenerators)) then
      rederr("this is no representation");
  res:=for each g in elems collect
       list(g,
           mk!_rep!_mat(
                 get!*elem!*in!*generators(group,g),
                 repgenerators)
           );
  return append(list(group),res);
end;

symbolic procedure hard!_representation!_check!_p(group,repgenerators);
% repgenerators -- ((g1,matg1),(g2,matg2),...)
begin
scalar checkp;
  checkp:=t;
  for each relation in get!*generator!*relations(group) do
    if not(relation!_check!_p(relation,repgenerators)) then 
        checkp:=nil;
  return checkp;
end;

symbolic procedure relation!_check!_p(relation,repgenerators);
begin
scalar mat1,mat2;
  mat1:=mk!_relation!_mat(car relation, repgenerators);
  mat2:=mk!_relation!_mat(cadr relation, repgenerators);
  return equal!+matrices!+p(mat1,mat2);
end;

symbolic procedure mk!_relation!_mat(relationpart,repgenerators);
begin
scalar mat1,g;
   mat1:=mk!+unit!+mat(get!+row!+nr(cadr car repgenerators));
   for each g in relationpart do
     mat1:=mk!+mat!+mult!+mat(mat1,get!_mat(g,repgenerators));
  return mat1;
end;

symbolic procedure get!_mat(elem,repgenerators);
begin
scalar found,res;
  if elem='id then 
    return mk!+unit!+mat(get!+row!+nr(cadr car repgenerators));
  found:=nil;
  while ((length(repgenerators)>0) and (null found)) do 
    <<
       if elem = caar repgenerators then
         <<
           res:=cadr car repgenerators;
           found := t;
         >>;
       repgenerators:=cdr repgenerators;
    >>;
  if found then return res else
       rederr("error in get_mat");
end;

symbolic procedure mk!_rep!_mat(generatorl,repgenerators);
% returns the representation matrix (internal structure) 
% of a group element represented in generatorl
begin
scalar mat1;
   mat1:=mk!+unit!+mat(get!+row!+nr(cadr(car(repgenerators))));
   for each generator in generatorl do
     mat1:=mk!+mat!+mult!+mat(mat1,
                              get!_rep!_of!_generator(
                                generator,repgenerators)
                             );
   return mat1;
end;

symbolic procedure get!_rep!_of!_generator(generator,repgenerators);
% returns the representation matrix (internal structure) 
% of the generator
begin
 scalar found,mate,ll;
  if (generator='id) then return mk!+unit!+mat(
                  get!+row!+nr(cadr(car(repgenerators))));
   found:=nil;
   ll:=repgenerators;
   while (not(found) and (length(ll)>0)) do
      <<
        if (caar(ll)=generator) then
           <<
              found:=t;
              mate:=cadr(car(ll));
           >>; 
         ll:=cdr ll;
      >>;
  if found then return mate else
    rederr(" error in get rep of generators");
end;

symbolic procedure get!_group!_in(representation);
% returns the group of the internal data structure representation
begin
  return car representation;
end;

symbolic procedure eli!_group!_in(representation);
% returns the internal data structure representation without group
begin
  return cdr representation;
end;

symbolic procedure get!_rep!_matrix!_in(elem,representation);
% returns the matrix of the internal data structure representation
begin
scalar found,mate,replist;
   found:=nil;
   replist:=cdr representation;
   while (null(found) and length(replist)>0) do
     <<
       if ((caar(replist)) = elem) then 
             <<
                mate:=cadr(car (replist));
                found:=t;
             >>;
       replist:=cdr replist;
     >>;
  if found then return mate else
       rederr("error in get representation matrix");
end;

symbolic procedure get!_dimension!_in(representation);
% returns the dimension of the representation (internal data structure)
% output is an integer
begin
   return change!+sq!+to!+int(mk!+trace(get!_rep!_matrix!_in('id,
      representation)));
end;

symbolic procedure get!_rep!_matrix!_entry(representation,elem,z,s);
% get a special value of the matrix representation of group
% get the matrix of this representatiuon corresponding 
% to the element elem
% returns the matrix element of row z and column s
begin
  return get!+mat!+entry(
           get!_rep!_matrix!_in(elem,representation),
            z,s) ;
end;

symbolic procedure mk!_resimp!_rep(representation);
begin
scalar group,elem,res;
  group:=get!_group!_in(representation);
  res:=for each elem in get!*elements(group) collect
 list(elem,mk!+resimp!+mat(get!_rep!_matrix!_in(elem,representation)));
  return append(list(group),res);
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  functions for characters in iternal structure
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure get!_char!_group(char1);
% returns the group of the internal data structure character
begin
  return car char1;
end;

symbolic procedure get!_char!_dim(char1);
% returns the dimension of the internal data structure character
% output is an integer
begin
   return change!+sq!+to!+int(get!_char!_value(char1,'id));
end;

symbolic procedure get!_char!_value(char1,elem);
% returns the value of an element 
% of the internal data structure character
begin
scalar found,value,charlist;
   found:=nil;
   charlist:=cdr char1;
   while (null(found) and length(charlist)>0) do
     <<
       if ((caar(charlist)) = elem) then 
             <<
                value:=cadr(car (charlist));
                found:=t;
             >>;
       charlist := cdr charlist;
     >>;
  if found then return value else
       rederr("error in get character element");
end;

endmodule;

module symhandl;
%
% Symmetry Package 
%
% Author: Karin Gatermann
%         Konrad-Zuse-Zentrum fuer
%         Informationstechnik Berlin
%         Heilbronner Str. 10
%         W-1000 Berlin 31
%         Germany
%         Email: Gatermann@sc.ZIB-Berlin.de

%  symhandl.red

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% functions to get the stored information of groups
% booleans first
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

symbolic procedure available!*p(group);
% returns true, if the information 
% concerning irreducible representations
% of the group are in this database
begin
   if not(idp(group)) then rederr("this is no group identifier");
   return flagp(group,'available);
end;

symbolic procedure storing!*p(group);
% returns true, if the information concerning generators 
% and group elements
% of the group are in this database
begin
   return flagp(group,'storing);
end;

symbolic procedure g!*element!*p(group,element);
% returns true, if element is an element of the abstract group
begin
   if memq(element,get!*elements(group)) then return t else return nil;
end;

symbolic procedure g!*generater!*p(group,element);
% returns true, if element is a generator of the abstract group
begin
  if memq(element,get!*generators(group)) then return t else return nil;
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% operators for abstract group
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure get!*available!*groups;
% returns the available groups as a list
begin
  return get('availables,'groups);
end;

symbolic procedure get!*order(group);
% returns the order of group as integer
begin
  return length(get!*elements(group));
end;

symbolic procedure get!*elements(group);
% returns the abstract elements of group
% output list of identifiers
begin
scalar ll;
  return get(group,'elems);
end;

symbolic procedure get!*generators(group);
% returns a list abstract elements of group which generates the group
begin
   return get(group,'generators);
end;

symbolic procedure get!*generator!*relations(group);
% returns a list with relations 
% which are satisfied for the generators of the group
begin
   return get(group,'relations);
end;

symbolic procedure get!*product(group,elem1,elem2);
% returns the element elem1*elem2  of  group
begin
scalar table,above,left;
    table:=get(group,'grouptable);
    above:= car table;
    left:=for each row in table collect car row;
    return get!+mat!+entry(table,
                give!*position(elem1,left),
                give!*position(elem2,above));
end;

symbolic procedure get!*inverse(group,elem);
% returns the inverse element of the element elem in group
% invlist = ((g1,g2,..),(inv1,inv2,...))
begin
scalar invlist;
    invlist:=get(group,'inverse);
    return nth(cadr invlist,give!*position(elem,car invlist));
end;

symbolic procedure give!*position(elem,ll);
begin
scalar j,found;
j:=1; found:=nil;
    while (null(found) and (j<=length(ll))) do
       <<
          if (nth(ll,j)=elem) then found:=t else j:=j+1;
       >>;
    if null(found) then rederr("error in give position");  
    return j;
end;

symbolic procedure get!*elem!*in!*generators(group,elem);
% returns the element representated by the generators of group
begin
scalar ll,found,res;
    ll:=get(group,'elem!_in!_generators);
    if (elem='id) then return list('id); 
    found:=nil;
    while (null(found) and (length(ll)>0)) do
      <<
         if (elem=caaar ll) then
           <<
              res:=cadr car ll;
              found:=t;
           >>;
          ll:=cdr ll;
      >>;
  if found then return res else
       rederr("error in get!*elem!*in!*generators"); 
end;

symbolic procedure get!*nr!*equi!*classes(group);
% returns the number of equivalence classes of group
begin
    return length(get(group,'equiclasses));
end;

symbolic procedure get!*equi!*class(group,elem);
% returns the equivalence class of the element elem  in  group
begin
scalar ll,equic,found;
    ll:=get(group,'equiclasses);
    found:=nil;
    while (null(found) and (length(ll)>0)) do
      <<
         if memq(elem,car ll) then
           <<
              equic:=car ll;
              found:=t;
           >>;
          ll:=cdr ll;
      >>;
  if found then return equic;
end;

symbolic procedure get!*all!*equi!*classes(group);
% returns the equivalence classes of the element elem  in  group
% list of lists of identifiers
begin
    return get(group,'equiclasses);
end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% functions to get information of real irred. representation of group
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure get!*nr!*real!*irred!*reps(group);
% returns number of real irreducible representations of group
begin
  return get(group,'realrepnumber);
end;

symbolic procedure get!*real!*character(group,nr);
% returns the nr-th real character of the group group
begin
   return mk!_character(get!*real!*irreducible!*rep(group,nr));
end;

symbolic procedure get!*real!*comp!*chartype!*p(group,nr);
% returns true if the type of the real irreducible rep.
% of the group is complex
begin
  if eqcar( get(group,mkid('realrep,nr)) ,'complextype) then return t;
end;

symbolic procedure get!*real!*irreducible!*rep(group,nr);
% returns the real nr-th irreducible matrix representation of group
begin
  return mk!_resimp!_rep(append(list(group),
    cdr get(group,mkid('realrep,nr))));
end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% functions to get information of
%  complex irreducible representation of group
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


symbolic procedure get!*nr!*complex!*irred!*reps(group);
% returns number of complex irreducible representations of group
begin
  return get(group,'complexrepnumber);
end;

symbolic procedure get!*complex!*character(group,nr);
% returns the nr-th complex character of the group group
begin
   return mk!_character(get!*complex!*irreducible!*rep(group,nr));
end;

symbolic procedure get!*complex!*irreducible!*rep(group,nr);
% returns the complex nr-th irreduciblematrix representation of group
begin
  return mk!_resimp!_rep(append(list(group), 
      get(group,mkid('complexrep,nr))));
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  set information upon group
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure set!*group(group,equiclasses);
%
begin
  put(group,'equiclasses,equiclasses);
end;

symbolic procedure set!*elems!*group(group,elems);
%
begin
  put(group,'elems,elems);
end;

symbolic procedure set!*generators(group,generators);
%
begin
  put(group,'generators,generators);
end;

symbolic procedure set!*relations(group,relations);
%
begin
  put(group,'relations,relations);
end;

symbolic procedure set!*available(group);
begin
scalar grouplist;
  flag(list(group),'available);
  grouplist:=get('availables,'groups);
  grouplist:=append(grouplist,list(group));
  put('availables,'groups,grouplist);
end;

symbolic procedure set!*storing(group);
begin
  flag(list(group),'storing);
end;

symbolic procedure set!*grouptable(group,table);
%
begin
  put(group,'grouptable,table);
end;

symbolic procedure set!*inverse(group,invlist);
% stores the inverse element list in group
begin
  put(group,'inverse,invlist);
end;

symbolic procedure set!*elemasgen(group,glist);
%
begin
  put(group,'elem!_in!_generators,glist);
end;

symbolic procedure set!*representation(group,replist,type);
%
begin
scalar nr;
  nr:=get(group,mkid(type,'repnumber));
  if null(nr) then nr:=0;
  nr:=nr+1;
  put(group,mkid(mkid(type,'rep),nr),replist);
  set!*repnumber(group,type,nr);
end;

symbolic procedure set!*repnumber(group,type,nr);
%
begin
  put(group,mkid(type,'repnumber),nr);
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  functions to build information upon group
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure mk!*inverse!*list(table);
% returns ((elem1,elem2,..),(inv1,inv2,..))
begin
scalar elemlist,invlist,elem,row,column;
  elemlist:=cdr(car (mk!+transpose!+matrix(table)));
  invlist:=for each elem in elemlist collect
    <<
      row:=give!*position(elem,elemlist);
      column:=give!*position('id,cdr nth(table,row+1));
      nth(cdr(car table),column)
    >>;
  return list(elemlist,invlist);
end;

symbolic procedure mk!*equiclasses(table);
% returns ((elem1,elem2,..),(inv1,inv2,..))
begin
scalar elemlist,restlist,s,r,tt,ts;
scalar rows,rowt,columnt,columnr,equiclasses,equic,firstrow;
  elemlist:=cdr(car (mk!+transpose!+matrix(table)));
  restlist:=elemlist;
  firstrow:=cdr car table;
  equiclasses:=nil;
  while (length(restlist)>0) do
     <<
        s:=car restlist;
        rows:=give!*position(s,elemlist);
        equic:=list(s);
        restlist:=cdr restlist;
        for each tt in elemlist do
         <<
           columnt:=give!*position(tt,firstrow);
           rowt:=give!*position(tt,elemlist);
           ts:=get!+mat!+entry(table,rows+1,columnt+1);
           columnr:=give!*position(ts,cdr nth(table,rowt+1));
           r:=nth(firstrow,columnr);
           equic:=union(equic,list(r));
           restlist:=delete(r,restlist);
         >>;
     equiclasses:=append(equiclasses,list(equic));
     >>; 
  return equiclasses;
end;

endmodule;

module sympatch;
% from rprint.red
load!_package 'rprint;

fluid '(!*n buffp combuff!* curmark curpos orig pretop pretoprinf rmar);

symbolic procedure rprint u;
   begin integer !*n; scalar buff,buffp,curmark,rmar,x;
      curmark := 0;
      buff := buffp := list list(0,0);
      rmar := linelength nil;
      x := get('!*semicol!*,pretop);
      !*n := 0;
      mprino1(u,list(caar x,cadar x));
    %  prin2ox ";";
      prin2ox "$"; %3.11 91 KG
      omarko curmark;
      prinos buff
   end;

% error in treatment of roots in connection 
% with conjugate of complex numbers

symbolic procedure reimexpt u; 
   if cadr u eq 'e
     then addsq(reimcos list('cos,reval list('times,'i,caddr u)),
                multsq(simp list('minus,'i),
                    reimsin list('sin,reval list('times,'i,caddr u))))
    else if fixp cadr u and cadr u > 0
              and eqcar(caddr u,'quotient)
              and fixp cadr caddr u
              and fixp caddr caddr u
     then mksq(u,1)
    else addsq(mkrepart u,multsq(simp 'i,mkimpart u));

put('expt,'cmpxsplitfn,'reimexpt);
put('cos,'cmpxsplitfn,'reimcos);
put('sin,'cmpxsplitfn,'reimsin);
endmodule;

% algebraic repart(pi):=pi;   % Present in 3.4.1 and later versions.
% algebraic impart(pi):=0;

% error in treatment of roots in connection
% with conjugate of complex numbers
% end;

module symwork;
%
% Symmetry Package 
%
% Author : Karin Gatermann
%         Konrad-Zuse-Zentrum fuer
%         Informationstechnik Berlin
%         Heilbronner Str. 10
%         W-1000 Berlin 31
%         Germany
%         Email: Gatermann@sc.ZIB-Berlin.de


% symwork.red
% underground functions

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Boolean functions
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%symbolic procedure complex!_case!_p();
% returns true, if complex arithmetic is desired
%begin
%  if !*complex then return t else return nil;
%end;

switch outerzeroscheck;

symbolic procedure correct!_diagonal!_p(matrix,representation,mats);
% returns true, if matrix may be block diagonalized to mats
begin
scalar basis,diag;
   basis:=mk!_sym!_basis (representation);
   diag:= mk!+mat!*mat!*mat(
             mk!+hermitean!+matrix(basis),
             matrix,basis);
   if equal!+matrices!+p(diag,mats) then return t;
end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% functions on data depending on real or complex case
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


symbolic procedure get!_nr!_irred!_reps(group);
% returns number of irreducible representations of group
begin
  if !*complex then 
      return get!*nr!*complex!*irred!*reps(group) else
      return get!*nr!*real!*irred!*reps(group);
end;

symbolic procedure get!_dim!_irred!_reps(group,nr);
% returns dimension of nr-th irreducible representations of group
begin
scalar rep;
%   if !*complex then
%        return get!_char!_dim(get!*complex!*character(group,nr)) else
%        return get!_char!_dim(get!*real!*character(group,nr));
   if !*complex then
        rep:= get!*complex!*irreducible!*rep(group,nr) else
        rep:= get!*real!*irreducible!*rep(group,nr);
   return get!_dimension!_in(rep);
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  functions for user given representations
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure get!_group!_out(representation);
% returns the group identifier given in representation
begin
   scalar group,found,eintrag,repl;
   found:=nil;
   repl:=cdr representation;
   while (not(found) and (length(repl)>1)) do
     <<
        eintrag:=car repl;
        repl:=cdr repl;
        if idp(eintrag) then
          <<
             group:=eintrag;
             found:=t;
          >>; 
      >>;
  if found then return group else
  rederr("group identifier missing");
end;

symbolic procedure get!_repmatrix!_out(elem,representation);
% returns the representation matrix of elem given in representation
% output in internal structure
begin
scalar repl,found,matelem,eintrag;
   found:=nil;
   repl:= cdr representation;
   while (null(found) and (length(repl)>0)) do
     <<
        eintrag:=car repl;
        repl:=cdr repl;
        if eqcar(eintrag,'equal) then
           <<
              if not(length(eintrag) = 3) then
                       rederr("incomplete equation");
              if (cadr(eintrag) = elem) then
                <<
                   found:=t;
                   matelem:=caddr eintrag;
                >>;
           >>;
     >>;
   if found then return matelem else
        rederr("representation matrix for one generator missing");
end;

symbolic procedure mk!_rep!_relation(representation,generators);
% representation in user given structure
% returns a list of pairs with generator and its representation matrix
% in internal structure
begin
scalar g,matg,res;
  res:=for each g in generators collect
     <<
        matg:= mk!+inner!+mat(get!_repmatrix!_out(g,representation));
        if not(unitarian!+p(matg)) then
             rederr("please give an orthogonal or unitarian matrix");
        list(g,matg)
      >>;
  return res;
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% functions which compute, do the real work, get correct arguments
%                    and use get-functions from sym_handle_data.red   
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure mk!_character(representation);
% returns the character of the representation (in internal structure)
% result in internal structure
begin
scalar group,elem,char;
   group:=get!_group!_in(representation);
   char:= for each elem in get!*elements(group) collect
             list(elem,
                  mk!+trace(get!_rep!_matrix!_in(
                              elem,representation)
                           )
                  );
   char:=append(list(group),char);
   return char;
end;

symbolic procedure mk!_multiplicity(representation,nr);
% returns the multiplicity of the nr-th rep. in representation 
% internal structure
begin
scalar multnr,char1,group;
     group:=get!_group!_in(representation);
  if !*complex then 
     char1:=mk!_character(get!*complex!*irreducible!*rep(group,nr))
         else
     char1:=mk!_character(get!*real!*irreducible!*rep(group,nr));
  multnr:=char!_prod(char1,mk!_character(representation));
% complex case factor 1/2 !!
     if (not(!*complex) and 
         (get!*real!*comp!*chartype!*p(group,nr))) then 
         multnr:=multsq(multnr,(1 ./ 2));
     return change!+sq!+to!+int(multnr);
end;


symbolic procedure char!_prod(char1,char2);
% returns the inner product of the two characters as sq
begin
scalar group,elems,sum,g,product;
  group:=get!_char!_group(char1);
  if not(group = get!_char!_group(char2))
      then rederr("no product for two characters of different groups");
  if not (available!*p(group)) and not(storing!*p(group)) then 
       rederr("strange group in character product");
  elems:=get!*elements(group);
  sum:=nil ./ 1;
  for each g in elems do
    <<
      product:=multsq(
        get!_char!_value(char1,g),
        get!_char!_value(char2,get!*inverse(group,g))
                     );
      sum:=addsq(sum,product);
    >>;
  return quotsq(sum,change!+int!+to!+sq(get!*order(group)));
end;

symbolic procedure mk!_proj!_iso(representation,nr);
% returns the projection onto the isotypic component nr
begin
scalar group,elems,g,charnr,dimen,mapping,fact;
  group:=get!_group!_in(representation);
  if not (available!*p(group)) then 
       rederr("strange group in projection");
  if not(irr!:nr!:p(nr,group)) then 
       rederr("incorrect number of representation");
  elems:=get!*elements(group);
  if !*complex then 
      charnr:=
          mk!_character(get!*complex!*irreducible!*rep(group,nr))
  else
      charnr:=mk!_character(get!*real!*irreducible!*rep(group,nr));
  dimen:=get!_dimension!_in(representation);
  mapping:=mk!+null!+mat(dimen,dimen);
  for each g in elems do
    <<
      mapping:=mk!+mat!+plus!+mat(
              mapping,
              mk!+scal!+mult!+mat(
        get!_char!_value(charnr,get!*inverse(group,g)),
        get!_rep!_matrix!_in(g,representation)
                                 )
                                 );
    >>;
  fact:=quotsq(change!+int!+to!+sq(get!_char!_dim(charnr)),
         change!+int!+to!+sq(get!*order(group)));
  mapping:=mk!+scal!+mult!+mat(fact,mapping);
% complex case factor 1/2 !!
  if (not(!*complex) and 
    (get!*real!*comp!*chartype!*p(group,nr))) then 
       mapping:=mk!+scal!+mult!+mat((1 ./ 2),mapping);
  return mapping;
end;

symbolic procedure mk!_proj!_first(representation,nr);
% returns the projection onto the first vector space of the 
% isotypic component nr
begin
scalar group,elems,g,irrrep,dimen,mapping,fact,charnr,irrdim;
  group:=get!_group!_in(representation);
  if not (available!*p(group)) then 
       rederr("strange group in projection");
  if not(irr!:nr!:p(nr,group)) then 
       rederr("incorrect number of representation");
  elems:=get!*elements(group);
  if !*complex then 
      irrrep:=get!*complex!*irreducible!*rep(group,nr) else
      irrrep:=get!*real!*irreducible!*rep(group,nr);
  dimen:=get!_dimension!_in(representation);
  mapping:=mk!+null!+mat(dimen,dimen);
  for each g in elems do
    <<
      mapping:=mk!+mat!+plus!+mat(
              mapping,
              mk!+scal!+mult!+mat(
        get!_rep!_matrix!_entry(irrrep,get!*inverse(group,g),1,1),
        get!_rep!_matrix!_in(g,representation)
                                 )
                                 );
    >>;
  irrdim:=get!_dimension!_in(irrrep);
  fact:=quotsq(change!+int!+to!+sq(irrdim),
         change!+int!+to!+sq(get!*order(group)));
  mapping:=mk!+scal!+mult!+mat(fact,mapping);
% no special rule for real irreducible representations of complex type
  return mapping;
end;

symbolic procedure mk!_mapping(representation,nr,count);
% returns the mapping from V(nr 1) to V(nr count) 
% output is internal matrix
begin
scalar group,elems,g,irrrep,dimen,mapping,fact,irrdim;
  group:=get!_group!_in(representation);
  if not (available!*p(group)) then 
       rederr("strange group in projection");
  if not(irr!:nr!:p(nr,group)) then 
       rederr("incorrect number of representation");
  elems:=get!*elements(group);
  if !*complex then 
      irrrep:=get!*complex!*irreducible!*rep(group,nr) else
      irrrep:=get!*real!*irreducible!*rep(group,nr);
  dimen:=get!_dimension!_in(representation);
  mapping:=mk!+null!+mat(dimen,dimen);
  for each g in elems do
    <<
      mapping:=mk!+mat!+plus!+mat(
              mapping,
              mk!+scal!+mult!+mat(
        get!_rep!_matrix!_entry(irrrep,get!*inverse(group,g),1,count),
        get!_rep!_matrix!_in(g,representation)
                                 )
                                 );
    >>;
  irrdim:=get!_dimension!_in(irrrep);
  fact:=quotsq(change!+int!+to!+sq(irrdim),
         change!+int!+to!+sq(get!*order(group)));
  mapping:=mk!+scal!+mult!+mat(fact,mapping);
% no special rule for real irreducible representations of complex type
  return mapping;
end;

symbolic procedure mk!_part!_sym (representation,nr);
% computes the symmetry adapted basis of component nr
% output matrix
begin
scalar unitlist, veclist2, mapping, v;
  unitlist:=gen!+can!+bas(get!_dimension!_in(representation));
  mapping:=mk!_proj!_iso(representation,nr);
  veclist2:= for each v in unitlist collect 
             mk!+mat!+mult!+vec(mapping,v);
  return mk!+internal!+mat(Gram!+Schmid(veclist2));
end;

symbolic procedure mk!_part!_sym1 (representation,nr);
% computes the symmetry adapted basis of component V(nr 1)
% internal structure for in and out
% output matrix
begin
scalar unitlist, veclist2, mapping, v,group;
  unitlist:=gen!+can!+bas(get!_dimension!_in(representation));
  group:=get!_group!_in (representation);
  if (not(!*complex) and
       get!*real!*comp!*chartype!*p(group,nr)) then
     <<
        mapping:=mk!_proj!_iso(representation,nr);
     >> else
        mapping:=mk!_proj!_first(representation,nr);
  veclist2:= for each v in unitlist collect 
             mk!+mat!+mult!+vec(mapping,v);
  veclist2:=mk!+resimp!+mat(veclist2);
  return mk!+internal!+mat(Gram!+Schmid(veclist2));
end;

symbolic procedure mk!_part!_symnext (representation,nr,count,mat1);
% computes the symmetry adapted basis of component V(nr count)
% internal structure for in and out -- count > 2
% bas1 -- internal matrix
% output matrix
begin
scalar veclist1, veclist2, mapping, v;
  mapping:=mk!_mapping(representation,nr,count);
  veclist1:=mat!+veclist(mat1);
  veclist2:= for each v in veclist1 collect
      mk!+mat!+mult!+vec(mapping,v);
  return mk!+internal!+mat(veclist2);
end;

symbolic procedure mk!_sym!_basis (representation);
% computes the complete symmetry adapted basis
% internal structure for in and out
begin
scalar nr,anz,group,dimen,mats,matels,mat1,mat2;
   group:=get!_group!_in(representation);
   anz:=get!_nr!_irred!_reps(group);
   mats:=for nr := 1:anz join
     if not(null(mk!_multiplicity(representation,nr))) then
     <<
       if get!_dim!_irred!_reps(group,nr)=1 then
           mat1:=mk!_part!_sym (representation,nr)
        else 
           mat1:=mk!_part!_sym1 (representation,nr);
       if (not(!*complex) and 
              get!*real!*comp!*chartype!*p(group,nr)) then
           <<
              matels:=list(mat1);
           >> else
           <<
              if get!_dim!_irred!_reps(group,nr)=1 then
                <<
                   matels:=list(mat1);
                >> else
                <<
                   matels:= 
                  for dimen:=2:get!_dim!_irred!_reps(group,nr) collect
                        mk!_part!_symnext(representation,nr,dimen,mat1);
                   matels:=append(list(mat1),matels);
                >>;
           >>;
       matels
     >>;
  if length(mats)<1 then rederr("no mats in mk!_sym!_basis");
  mat2:=car mats;
  for each mat1 in cdr mats do
      mat2:=add!+two!+mats(mat2,mat1);
  return mat2;
end;

symbolic procedure mk!_part!_sym!_all (representation,nr);
% computes the complete symmetry adapted basis
% internal structure for in and out
begin
scalar group,dimen,matels,mat1,mat2;
   group:=get!_group!_in(representation);
   if get!_dim!_irred!_reps(group,nr)=1 then
      mat1:=mk!_part!_sym (representation,nr)
      else 
        <<
           mat1:=mk!_part!_sym1 (representation,nr);
       if (not(!*complex) and 
              get!*real!*comp!*chartype!*p(group,nr)) then
           <<
              mat1:=mat1;
           >> else
           <<
              if get!_dim!_irred!_reps(group,nr)>1 then
                << matels:=                     
                  for dimen:=2:get!_dim!_irred!_reps(group,nr) collect
                     mk!_part!_symnext(representation,nr,dimen,mat1);
                  for each mat2 in matels do
                   mat1:=add!+two!+mats(mat1,mat2);
                >>;
           >>;
        >>;
  return mat1;
end;

symbolic procedure mk!_diagonal (matrix1,representation);
% computes the matrix in diagonal form
% internal structure for in and out
begin
scalar nr,anz,mats,group,mat1,diamats,matdia,dimen;
   group:=get!_group!_in(representation);
   anz:=get!_nr!_irred!_reps(group);
   mats:=for nr := 1:anz join
     if not(null(mk!_multiplicity(representation,nr))) then
     <<
       if get!_dim!_irred!_reps(group,nr)=1 then
           mat1:=mk!_part!_sym (representation,nr)
        else 
           mat1:=mk!_part!_sym1 (representation,nr);
%        if (not(!*complex) and 
%              get!*real!*comp!*chartype!*p(group,nr)) then
%                mat1:=add!+two!+mats(mat1,
%                          mk!_part!_symnext(representation,nr,2,mat1));
        matdia:= mk!+mat!*mat!*mat(
                  mk!+hermitean!+matrix(mat1),matrix1,mat1
                              );
        if (not(!*complex) and 
              get!*real!*comp!*chartype!*p(group,nr)) then
           <<
             diamats:=list(matdia);
           >> else
           <<
             diamats:=
                  for dimen:=1:get!_dim!_irred!_reps(group,nr) collect
                     matdia;
            >>;
        diamats
     >>;
  mats:=mk!+block!+diagonal!+mat(mats);
  if !*outerzeroscheck then 
    if not(correct!_diagonal!_p(matrix1,representation,mats)) then
       rederr("wrong diagonalisation");
  return mats;
end;

endmodule;


%  Data for symmetry package, part 1.

% symbolic$  % Turning this on here causes problems with some builds.
set!*elems!*group('z2,'(id sz2))$
set!*generators('z2,'(sz2))$
set!*relations('z2,'(((sz2 sz2) (id))))$
set!*grouptable('z2,'((grouptable id sz2) (id id sz2) (sz2 sz2 id)))$
set!*inverse('z2,'((id sz2) (id sz2)))$
set!*elemasgen('z2,'(((sz2) (sz2))))$
set!*group('z2,'((id) (sz2)))$
set!*representation('z2,'((id (((1 . 1)))) (sz2 (((1 . 1))))),'complex)$
set!*representation('z2,
  '((id (((1 . 1)))) (sz2 (((-1 . 1))))),'complex)$
set!*representation('z2,
  '(realtype (id (((1 . 1)))) (sz2 (((1 . 1))))),'real)$
set!*representation('z2,
  '(realtype (id (((1 . 1)))) (sz2 (((-1 . 1))))),'real)$
set!*available 'z2$

set!*elems!*group('k4,'(id s1k4 s2k4 rk4))$
set!*generators('k4,'(s1k4 s2k4))$
set!*relations('k4,
               '(((s1k4 s1k4) (id))
                 ((s2k4 s2k4) (id))
                 ((s1k4 s2k4) (s2k4 s1k4))))$
set!*grouptable('k4,
                '((grouptable id s1k4 s2k4 rk4)
                  (id id s1k4 s2k4 rk4)
                  (s1k4 s1k4 id rk4 s2k4)
                  (s2k4 s2k4 rk4 id s1k4)
                  (rk4 rk4 s2k4 s1k4 id)))$
set!*inverse('k4,'((id s1k4 s2k4 rk4) (id s1k4 s2k4 rk4)))$
set!*elemasgen('k4,
  '(((s1k4) (s1k4)) ((s2k4) (s2k4)) ((rk4) (s1k4 s2k4))))$
set!*group('k4,'((id) (s1k4) (s2k4) (rk4)))$
set!*representation('k4,
                    '((id (((1 . 1))))
                      (s1k4 (((1 . 1))))
                      (s2k4 (((1 . 1))))
                      (rk4 (((1 . 1))))),'complex)$
set!*representation('k4,
                    '((id (((1 . 1))))
                      (s1k4 (((-1 . 1))))
                      (s2k4 (((1 . 1))))
                      (rk4 (((-1 . 1))))),'complex)$
set!*representation('k4,
                    '((id (((1 . 1))))
                      (s1k4 (((1 . 1))))
                      (s2k4 (((-1 . 1))))
                      (rk4 (((-1 . 1))))),'complex)$
set!*representation('k4,
                    '((id (((1 . 1))))
                      (s1k4 (((-1 . 1))))
                      (s2k4 (((-1 . 1))))
                      (rk4 (((1 . 1))))),'complex)$
set!*representation('k4,
                    '(realtype
                      (id (((1 . 1))))
                      (s1k4 (((1 . 1))))
                      (s2k4 (((1 . 1))))
                      (rk4 (((1 . 1))))),'real)$
set!*representation('k4,
                    '(realtype
                      (id (((1 . 1))))
                      (s1k4 (((-1 . 1))))
                      (s2k4 (((1 . 1))))
                      (rk4 (((-1 . 1))))),'real)$
set!*representation('k4,
                    '(realtype
                      (id (((1 . 1))))
                      (s1k4 (((1 . 1))))
                      (s2k4 (((-1 . 1))))
                      (rk4 (((-1 . 1))))),'real)$
set!*representation('k4,
                    '(realtype
                      (id (((1 . 1))))
                      (s1k4 (((-1 . 1))))
                      (s2k4 (((-1 . 1))))
                      (rk4 (((1 . 1))))),'real)$
set!*available 'k4$

set!*elems!*group('d3,'(id rd3 rot2d3 sd3 srd3 sr2d3))$
set!*generators('d3,'(rd3 sd3))$
set!*relations('d3,
               '(((sd3 sd3) (id))
                 ((rd3 rd3 rd3) (id))
                 ((sd3 rd3 sd3) (rd3 rd3))))$
set!*grouptable('d3,
                '((grouptable id rd3 rot2d3 sd3 srd3 sr2d3)
                  (id id rd3 rot2d3 sd3 srd3 sr2d3)
                  (rd3 rd3 rot2d3 id sr2d3 sd3 srd3)
                  (rot2d3 rot2d3 id rd3 srd3 sr2d3 sd3)
                  (sd3 sd3 srd3 sr2d3 id rd3 rot2d3)
                  (srd3 srd3 sr2d3 sd3 rot2d3 id rd3)
                  (sr2d3 sr2d3 sd3 srd3 rd3 rot2d3 id)))$
set!*inverse('d3,
   '((id rd3 rot2d3 sd3 srd3 sr2d3) (id rot2d3 rd3 sd3 srd3 sr2d3)))$
set!*elemasgen('d3,
               '(((rd3) (rd3))
                 ((rot2d3) (rd3 rd3))
                 ((sd3) (sd3))
                 ((srd3) (sd3 rd3))
                 ((sr2d3) (sd3 rd3 rd3))))$
set!*group('d3,'((id) (rd3 rot2d3) (sr2d3 sd3 srd3)))$
set!*representation('d3,
                    '((id (((1 . 1))))
                      (rd3 (((1 . 1))))
                      (rot2d3 (((1 . 1))))
                      (sd3 (((1 . 1))))
                      (srd3 (((1 . 1))))
                      (sr2d3 (((1 . 1))))),'complex)$
set!*representation('d3,
                    '((id (((1 . 1))))
                      (rd3 (((1 . 1))))
                      (rot2d3 (((1 . 1))))
                      (sd3 (((-1 . 1))))
                      (srd3 (((-1 . 1))))
                      (sr2d3 (((-1 . 1))))),'complex)$
set!*representation('d3,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (rot2d3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sd3 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr2d3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (1 . 2))))),'complex)$
set!*representation('d3,
                    '(realtype
                      (id (((1 . 1))))
                      (rd3 (((1 . 1))))
                      (rot2d3 (((1 . 1))))
                      (sd3 (((1 . 1))))
                      (srd3 (((1 . 1))))
                      (sr2d3 (((1 . 1))))),'real)$
set!*representation('d3,
                    '(realtype
                      (id (((1 . 1))))
                      (rd3 (((1 . 1))))
                      (rot2d3 (((1 . 1))))
                      (sd3 (((-1 . 1))))
                      (srd3 (((-1 . 1))))
                      (sr2d3 (((-1 . 1))))),'real)$
set!*representation('d3,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd3
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (rot2d3
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sd3 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd3
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr2d3
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (1 . 2))))),'real)$
set!*available 'd3$

set!*elems!*group('d4,'(id rd4 rot2d4 rot3d4 sd4 srd4 sr2d4 sr3d4))$
set!*generators('d4,'(rd4 sd4))$
set!*relations('d4,
               '(((sd4 sd4) (id))
                 ((rd4 rd4 rd4 rd4) (id))
                 ((sd4 rd4 sd4) (rd4 rd4 rd4))))$
set!*grouptable('d4,
                '((grouptable id rd4 rot2d4 rot3d4 sd4 srd4 sr2d4 sr3d4)
                  (id id rd4 rot2d4 rot3d4 sd4 srd4 sr2d4 sr3d4)
                  (rd4 rd4 rot2d4 rot3d4 id sr3d4 sd4 srd4 sr2d4)
                  (rot2d4 rot2d4 rot3d4 id rd4 sr2d4 sr3d4 sd4 srd4)
                  (rot3d4 rot3d4 id rd4 rot2d4 srd4 sr2d4 sr3d4 sd4)
                  (sd4 sd4 srd4 sr2d4 sr3d4 id rd4 rot2d4 rot3d4)
                  (srd4 srd4 sr2d4 sr3d4 sd4 rot3d4 id rd4 rot2d4)
                  (sr2d4 sr2d4 sr3d4 sd4 srd4 rot2d4 rot3d4 id rd4)
                  (sr3d4 sr3d4 sd4 srd4 sr2d4 rd4 rot2d4 rot3d4 id)))$
set!*inverse('d4,
             '((id rd4 rot2d4 rot3d4 sd4 srd4 sr2d4 sr3d4)
               (id rot3d4 rot2d4 rd4 sd4 srd4 sr2d4 sr3d4)))$
set!*elemasgen('d4,
               '(((rd4) (rd4))
                 ((rot2d4) (rd4 rd4))
                 ((rot3d4) (rd4 rd4 rd4))
                 ((sd4) (sd4))
                 ((srd4) (sd4 rd4))
                 ((sr2d4) (sd4 rd4 rd4))
                 ((sr3d4) (sd4 rd4 rd4 rd4))))$
set!*group('d4,'((id) (rd4 rot3d4) (rot2d4) (sd4 sr2d4) (sr3d4 srd4)))$
set!*representation('d4,
                    '((id (((1 . 1))))
                      (rd4 (((1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((1 . 1))))
                      (sd4 (((1 . 1))))
                      (srd4 (((1 . 1))))
                      (sr2d4 (((1 . 1))))
                      (sr3d4 (((1 . 1))))),'complex)$
set!*representation('d4,
                    '((id (((1 . 1))))
                      (rd4 (((1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((1 . 1))))
                      (sd4 (((-1 . 1))))
                      (srd4 (((-1 . 1))))
                      (sr2d4 (((-1 . 1))))
                      (sr3d4 (((-1 . 1))))),'complex)$
set!*representation('d4,
                    '((id (((1 . 1))))
                      (rd4 (((-1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((-1 . 1))))
                      (sd4 (((1 . 1))))
                      (srd4 (((-1 . 1))))
                      (sr2d4 (((1 . 1))))
                      (sr3d4 (((-1 . 1))))),'complex)$
set!*representation('d4,
                    '((id (((1 . 1))))
                      (rd4 (((-1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((-1 . 1))))
                      (sd4 (((-1 . 1))))
                      (srd4 (((1 . 1))))
                      (sr2d4 (((-1 . 1))))
                      (sr3d4 (((1 . 1))))),'complex)$
set!*representation('d4,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd4 (((nil . 1) (1 . 1)) ((-1 . 1) (nil . 1))))
                 (rot2d4 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                 (rot3d4 (((nil . 1) (-1 . 1)) ((1 . 1) (nil . 1))))
                      (sd4 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd4 (((nil . 1) (1 . 1)) ((1 . 1) (nil . 1))))
                      (sr2d4 (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                 (sr3d4 (((nil . 1) (-1 . 1)) ((-1 . 1) (nil . 1))))),
                    'complex)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1))))
                      (rd4 (((1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((1 . 1))))
                      (sd4 (((1 . 1))))
                      (srd4 (((1 . 1))))
                      (sr2d4 (((1 . 1))))
                      (sr3d4 (((1 . 1))))),'real)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1))))
                      (rd4 (((1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((1 . 1))))
                      (sd4 (((-1 . 1))))
                      (srd4 (((-1 . 1))))
                      (sr2d4 (((-1 . 1))))
                      (sr3d4 (((-1 . 1))))),'real)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1))))
                      (rd4 (((-1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((-1 . 1))))
                      (sd4 (((1 . 1))))
                      (srd4 (((-1 . 1))))
                      (sr2d4 (((1 . 1))))
                      (sr3d4 (((-1 . 1))))),'real)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1))))
                      (rd4 (((-1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((-1 . 1))))
                      (sd4 (((-1 . 1))))
                      (srd4 (((1 . 1))))
                      (sr2d4 (((-1 . 1))))
                      (sr3d4 (((1 . 1))))),'real)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd4 (((nil . 1) (1 . 1)) ((-1 . 1) (nil . 1))))
                  (rot2d4 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                  (rot3d4 (((nil . 1) (-1 . 1)) ((1 . 1) (nil . 1))))
                      (sd4 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd4 (((nil . 1) (1 . 1)) ((1 . 1) (nil . 1))))
                  (sr2d4 (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                  (sr3d4 (((nil . 1) (-1 . 1)) ((-1 . 1) (nil . 1))))),
                    'real)$
set!*available 'd4$

set!*elems!*group('d5,
   '(id rd5 r2d5 r3d5 r4d5 sd5 srd5 sr2d5 sr3d5 sr4d5))$
set!*generators('d5,'(rd5 sd5))$
set!*relations('d5,
               '(((sd5 sd5) (id))
                 ((rd5 rd5 rd5 rd5 rd5) (id))
                 ((sd5 rd5 sd5) (rd5 rd5 rd5 rd5))))$
set!*grouptable('d5,
      '((grouptable id rd5 r2d5 r3d5 r4d5 sd5 srd5 sr2d5 sr3d5 sr4d5)
               (id id rd5 r2d5 r3d5 r4d5 sd5 srd5 sr2d5 sr3d5 sr4d5)
               (rd5 rd5 r2d5 r3d5 r4d5 id sr4d5 sd5 srd5 sr2d5 sr3d5)
               (r2d5 r2d5 r3d5 r4d5 id rd5 sr3d5 sr4d5 sd5 srd5 sr2d5)
               (r3d5 r3d5 r4d5 id rd5 r2d5 sr2d5 sr3d5 sr4d5 sd5 srd5)
               (r4d5 r4d5 id rd5 r2d5 r3d5 srd5 sr2d5 sr3d5 sr4d5 sd5)
               (sd5 sd5 srd5 sr2d5 sr3d5 sr4d5 id rd5 r2d5 r3d5 r4d5)
               (srd5 srd5 sr2d5 sr3d5 sr4d5 sd5 r4d5 id rd5 r2d5 r3d5)
               (sr2d5 sr2d5 sr3d5 sr4d5 sd5 srd5 r3d5 r4d5 id rd5 r2d5)
               (sr3d5 sr3d5 sr4d5 sd5 srd5 sr2d5 r2d5 r3d5 r4d5 id rd5)
        (sr4d5 sr4d5 sd5 srd5 sr2d5 sr3d5 rd5 r2d5 r3d5 r4d5 id)))$
set!*inverse('d5,
             '((id rd5 r2d5 r3d5 r4d5 sd5 srd5 sr2d5 sr3d5 sr4d5)
               (id r4d5 r3d5 r2d5 rd5 sd5 srd5 sr2d5 sr3d5 sr4d5)))$
set!*elemasgen('d5,
               '(((rd5) (rd5))
                 ((r2d5) (rd5 rd5))
                 ((r3d5) (rd5 rd5 rd5))
                 ((r4d5) (rd5 rd5 rd5 rd5))
                 ((sd5) (sd5))
                 ((srd5) (sd5 rd5))
                 ((sr2d5) (sd5 rd5 rd5))
                 ((sr3d5) (sd5 rd5 rd5 rd5))
                 ((sr4d5) (sd5 rd5 rd5 rd5 rd5))))$
set!*group('d5,
 '((id) (rd5 r4d5) (r2d5 r3d5) (srd5 sr2d5 sd5 sr4d5 sr3d5)))$
set!*representation('d5,
                    '((id (((1 . 1))))
                      (rd5 (((1 . 1))))
                      (r2d5 (((1 . 1))))
                      (r3d5 (((1 . 1))))
                      (r4d5 (((1 . 1))))
                      (sd5 (((1 . 1))))
                      (srd5 (((1 . 1))))
                      (sr2d5 (((1 . 1))))
                      (sr3d5 (((1 . 1))))
                      (sr4d5 (((1 . 1))))),'complex)$
set!*representation('d5,
                    '((id (((1 . 1))))
                      (rd5 (((1 . 1))))
                      (r2d5 (((1 . 1))))
                      (r3d5 (((1 . 1))))
                      (r4d5 (((1 . 1))))
                      (sd5 (((-1 . 1))))
                      (srd5 (((-1 . 1))))
                      (sr2d5 (((-1 . 1))))
                      (sr3d5 (((-1 . 1))))
                      (sr4d5 (((-1 . 1))))),'complex)$
set!*representation('d5,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd5
                  (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                  (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                  ((((((sin (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                  (((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1))))
                      (r2d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                    (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                    (((cos (quotient (times 2 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                      (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                     (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                     (((cos (quotient (times 2 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                        (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                     (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4d5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                        (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                          (((cos (quotient (times 2 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))
                      (sd5 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd5
                  (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                  (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                  ((((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1)
               (((((cos (quotient (times 2 pi) 5)) . 1) . -1)) . 1))))
                      (sr2d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                        (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -1))
                          . 1))))
                      (sr3d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . -1))
                          . 1))))
                      (sr4d5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                            (((cos (quotient (times 2 pi) 5)) . 2) . 6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . -1))
                          . 1))))),'complex)$
set!*representation('d5,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd5
                   (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                   (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                (((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1))))
                      (r2d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4d5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))
                      (sd5 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd5
                 (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                 (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                 ((((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1)
                 (((((cos (quotient (times 4 pi) 5)) . 1) . -1)) . 1))))
                      (sr2d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 2) . -1))
                          . 1))))
                      (sr3d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                       . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . -1))
                          . 1))))
                      (sr4d5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                            (((cos (quotient (times 4 pi) 5)) . 2) . 6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . -1))
                          . 1))))),'complex)$
set!*representation('d5,
                    '(realtype
                      (id (((1 . 1))))
                      (rd5 (((1 . 1))))
                      (r2d5 (((1 . 1))))
                      (r3d5 (((1 . 1))))
                      (r4d5 (((1 . 1))))
                      (sd5 (((1 . 1))))
                      (srd5 (((1 . 1))))
                      (sr2d5 (((1 . 1))))
                      (sr3d5 (((1 . 1))))
                      (sr4d5 (((1 . 1))))),'real)$
set!*representation('d5,
                    '(realtype
                      (id (((1 . 1))))
                      (rd5 (((1 . 1))))
                      (r2d5 (((1 . 1))))
                      (r3d5 (((1 . 1))))
                      (r4d5 (((1 . 1))))
                      (sd5 (((-1 . 1))))
                      (srd5 (((-1 . 1))))
                      (sr2d5 (((-1 . 1))))
                      (sr3d5 (((-1 . 1))))
                      (sr4d5 (((-1 . 1))))),'real)$
set!*representation('d5,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd5
                 (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                  (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                 (((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1))))
                      (r2d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                        (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 1) . 2)))
                        . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                         (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4d5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                          (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                          (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                           (((cos (quotient (times 2 pi) 5)) . 1) . -4))
                          (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))
                      (sd5 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd5
                 (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                 (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                 ((((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1)
                (((((cos (quotient (times 2 pi) 5)) . 1) . -1)) . 1))))
                      (sr2d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                        (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                       (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                        . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . 1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . -1))
                          . 1))))
                      (sr3d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . -1))
                          . 1))))
                      (sr4d5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                            (((cos (quotient (times 2 pi) 5)) . 2) . 6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . -1))
                          . 1))))),'real)$
set!*representation('d5,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd5
                  (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                   (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                  (((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1))))
                   (r2d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                        . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                        (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                         (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4d5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                         (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                           (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                           (((cos (quotient (times 4 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))
                      (sd5 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd5
                  (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                   (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1)
               (((((cos (quotient (times 4 pi) 5)) . 1) . -1)) . 1))))
                      (sr2d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                       . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -1))
                         . 1))))
                      (sr3d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . -1))
                          . 1))))
                      (sr4d5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                           (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                            (((cos (quotient (times 4 pi) 5)) . 2) . 6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . -1))
                          . 1))))),'real)$
set!*available 'd5$

set!*elems!*group('d6,
                  '(id
                    rd6
                    r2d6
                    r3d6
                    r4d6
                    r5d6
                    sd6
                    srd6
                    sr2d6
                    sr3d6
                    sr4d6
                    sr5d6))$
set!*generators('d6,'(rd6 sd6))$
set!*relations('d6,
               '(((sd6 sd6) (id))
                 ((rd6 rd6 rd6 rd6 rd6 rd6) (id))
                 ((sd6 rd6 sd6) (rd6 rd6 rd6 rd6 rd6))))$
set!*grouptable('d6,
                '((grouptable
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6)
                  (id
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6)
                  (rd6
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6)
                  (r2d6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   rd6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6)
                  (r3d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   rd6
                   r2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6)
                  (r4d6
                   r4d6
                   r5d6
                   id
                   rd6
                   r2d6
                   r3d6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6)
                  (r5d6
                   r5d6
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6)
                  (sd6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6)
                  (srd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   r5d6
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6)
                  (sr2d6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   r4d6
                   r5d6
                   id
                   rd6
                   r2d6
                   r3d6)
                  (sr3d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   rd6
                   r2d6)
                  (sr4d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   rd6)
                  (sr5d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   id)))$
set!*inverse('d6,
       '((id rd6 r2d6 r3d6 r4d6 r5d6 sd6 srd6 sr2d6 sr3d6 sr4d6 sr5d6)
       (id r5d6 r4d6 r3d6 r2d6 rd6 sd6 srd6 sr2d6 sr3d6 sr4d6 sr5d6)))$
set!*elemasgen('d6,
               '(((rd6) (rd6))
                 ((r2d6) (rd6 rd6))
                 ((r3d6) (rd6 rd6 rd6))
                 ((r4d6) (rd6 rd6 rd6 rd6))
                 ((r5d6) (rd6 rd6 rd6 rd6 rd6))
                 ((sd6) (sd6))
                 ((srd6) (sd6 rd6))
                 ((sr2d6) (sd6 rd6 rd6))
                 ((sr3d6) (sd6 rd6 rd6 rd6))
                 ((sr4d6) (sd6 rd6 rd6 rd6 rd6))
                 ((sr5d6) (sd6 rd6 rd6 rd6 rd6 rd6))))$
set!*group('d6,
           '((id)
             (rd6 r5d6)
             (r2d6 r4d6)
             (r3d6)
             (sr2d6 sd6 sr4d6)
             (srd6 sr5d6 sr3d6)))$
set!*representation('d6,
                    '((id (((1 . 1))))
                      (rd6 (((1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((1 . 1))))
                      (sd6 (((1 . 1))))
                      (srd6 (((1 . 1))))
                      (sr2d6 (((1 . 1))))
                      (sr3d6 (((1 . 1))))
                      (sr4d6 (((1 . 1))))
                      (sr5d6 (((1 . 1))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1))))
                      (rd6 (((1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((1 . 1))))
                      (sd6 (((-1 . 1))))
                      (srd6 (((-1 . 1))))
                      (sr2d6 (((-1 . 1))))
                      (sr3d6 (((-1 . 1))))
                      (sr4d6 (((-1 . 1))))
                      (sr5d6 (((-1 . 1))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1))))
                      (rd6 (((-1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((-1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((-1 . 1))))
                      (sd6 (((1 . 1))))
                      (srd6 (((-1 . 1))))
                      (sr2d6 (((1 . 1))))
                      (sr3d6 (((-1 . 1))))
                      (sr4d6 (((1 . 1))))
                      (sr5d6 (((-1 . 1))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1))))
                      (rd6 (((-1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((-1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((-1 . 1))))
                      (sd6 (((-1 . 1))))
                      (srd6 (((1 . 1))))
                      (sr2d6 (((-1 . 1))))
                      (sr3d6 (((1 . 1))))
                      (sr4d6 (((-1 . 1))))
                      (sr5d6 (((1 . 1))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd6
                  (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (r2d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                  (r3d6 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (r4d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r5d6
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sd6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd6
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sr2d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                   (sr3d6 (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (sr4d6
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (sr5d6
              (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                   ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r2d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r3d6 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (r4d6
                 (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                 ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r5d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sd6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr2d6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (sr3d6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (sr4d6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr5d6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                (1 . 2))))),'complex)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1))))
                      (rd6 (((1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((1 . 1))))
                      (sd6 (((1 . 1))))
                      (srd6 (((1 . 1))))
                      (sr2d6 (((1 . 1))))
                      (sr3d6 (((1 . 1))))
                      (sr4d6 (((1 . 1))))
                      (sr5d6 (((1 . 1))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1))))
                      (rd6 (((1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((1 . 1))))
                      (sd6 (((-1 . 1))))
                      (srd6 (((-1 . 1))))
                      (sr2d6 (((-1 . 1))))
                      (sr3d6 (((-1 . 1))))
                      (sr4d6 (((-1 . 1))))
                      (sr5d6 (((-1 . 1))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1))))
                      (rd6 (((-1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((-1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((-1 . 1))))
                      (sd6 (((1 . 1))))
                      (srd6 (((-1 . 1))))
                      (sr2d6 (((1 . 1))))
                      (sr3d6 (((-1 . 1))))
                      (sr4d6 (((1 . 1))))
                      (sr5d6 (((-1 . 1))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1))))
                      (rd6 (((-1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((-1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((-1 . 1))))
                      (sd6 (((-1 . 1))))
                      (srd6 (((1 . 1))))
                      (sr2d6 (((-1 . 1))))
                      (sr3d6 (((1 . 1))))
                      (sr4d6 (((-1 . 1))))
                      (sr5d6 (((1 . 1))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd6
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (r2d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r3d6 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (r4d6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r5d6
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sd6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd6
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sr2d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                    (sr3d6 (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (sr4d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (sr5d6
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r2d6
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                     (r3d6 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (r4d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r5d6
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
            ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                    (sd6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr2d6
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                   (sr3d6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (sr4d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr5d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (1 . 2))))),'real)$
set!*available 'd6$

set!*elems!*group('c3,'(id rc3 r2c3))$
set!*generators('c3,'(rc3))$
set!*relations('c3,'(((rc3 rc3 rc3) (id))))$
set!*grouptable('c3,
                '((grouptable id rc3 r2c3)
                  (id id rc3 r2c3)
                  (rc3 rc3 r2c3 id)
                  (r2c3 r2c3 id rc3)))$
set!*inverse('c3,'((id rc3 r2c3) (id r2c3 rc3)))$
set!*elemasgen('c3,'(((rc3) (rc3)) ((r2c3) (rc3 rc3))))$
set!*group('c3,'((id) (rc3) (r2c3)))$
set!*representation('c3,
             '((id (((1 . 1)))) (rc3 (((1 . 1)))) (r2c3 (((1 . 1))))),
                    'complex)$
set!*representation('c3,
                    '((id (((1 . 1))))
                      (rc3
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r2c3
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))),'complex)$
set!*representation('c3,
                    '((id (((1 . 1))))
                      (rc3
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r2c3
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))),'complex)$
set!*representation('c3,
                    '(realtype
                      (id (((1 . 1))))
                      (rc3 (((1 . 1))))
                      (r2c3 (((1 . 1))))),'real)$
set!*representation('c3,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r2c3
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))),'real)$
set!*available 'c3$

set!*elems!*group('c4,'(id rc4 r2c4 r3c4))$
set!*generators('c4,'(rc4))$
set!*relations('c4,'(((rc4 rc4 rc4 rc4) (id))))$
set!*grouptable('c4,
                '((grouptable id rc4 r2c4 r3c4)
                  (id id rc4 r2c4 r3c4)
                  (rc4 rc4 r2c4 r3c4 id)
                  (r2c4 r2c4 r3c4 id rc4)
                  (r3c4 r3c4 id rc4 r2c4)))$
set!*inverse('c4,'((id rc4 r2c4 r3c4) (id r3c4 r2c4 rc4)))$
set!*elemasgen('c4,
    '(((rc4) (rc4)) ((r2c4) (rc4 rc4)) ((r3c4) (rc4 rc4 rc4))))$
set!*group('c4,'((id) (rc4) (r2c4) (r3c4)))$
set!*representation('c4,
                    '((id (((1 . 1))))
                      (rc4 (((1 . 1))))
                      (r2c4 (((1 . 1))))
                      (r3c4 (((1 . 1))))),'complex)$
set!*representation('c4,
                    '((id (((1 . 1))))
                      (rc4 (((-1 . 1))))
                      (r2c4 (((1 . 1))))
                      (r3c4 (((-1 . 1))))),'complex)$
set!*representation('c4,
                    '((id (((1 . 1))))
                      (rc4 ((((((i . 1) . 1)) . 1))))
                      (r2c4 (((-1 . 1))))
                      (r3c4 ((((((i . 1) . -1)) . 1))))),'complex)$
set!*representation('c4,
                    '((id (((1 . 1))))
                      (rc4 ((((((i . 1) . -1)) . 1))))
                      (r2c4 (((-1 . 1))))
                      (r3c4 ((((((i . 1) . 1)) . 1))))),'complex)$
set!*representation('c4,
                    '(realtype
                      (id (((1 . 1))))
                      (rc4 (((1 . 1))))
                      (r2c4 (((1 . 1))))
                      (r3c4 (((1 . 1))))),'real)$
set!*representation('c4,
                    '(realtype
                      (id (((1 . 1))))
                      (rc4 (((-1 . 1))))
                      (r2c4 (((1 . 1))))
                      (r3c4 (((-1 . 1))))),'real)$
set!*representation('c4,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc4 (((nil . 1) (-1 . 1)) ((1 . 1) (nil . 1))))
                      (r2c4 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
             (r3c4 (((nil . 1) (1 . 1)) ((-1 . 1) (nil . 1))))),'real)$
set!*available 'c4$

set!*elems!*group('c5,'(id rc5 r2c5 r3c5 r4c5))$
set!*generators('c5,'(rc5))$
set!*relations('c5,'(((rc5 rc5 rc5 rc5 rc5) (id))))$
set!*grouptable('c5,
                '((grouptable id rc5 r2c5 r3c5 r4c5)
                  (id id rc5 r2c5 r3c5 r4c5)
                  (rc5 rc5 r2c5 r3c5 r4c5 id)
                  (r2c5 r2c5 r3c5 r4c5 id rc5)
                  (r3c5 r3c5 r4c5 id rc5 r2c5)
                  (r4c5 r4c5 id rc5 r2c5 r3c5)))$
set!*inverse('c5,'((id rc5 r2c5 r3c5 r4c5) (id r4c5 r3c5 r2c5 rc5)))$
set!*elemasgen('c5,
               '(((rc5) (rc5))
                 ((r2c5) (rc5 rc5))
                 ((r3c5) (rc5 rc5 rc5))
                 ((r4c5) (rc5 rc5 rc5 rc5))))$
set!*group('c5,'((id) (rc5) (r2c5) (r3c5) (r4c5)))$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5 (((1 . 1))))
                      (r2c5 (((1 . 1))))
                      (r3c5 (((1 . 1))))
                      (r4c5 (((1 . 1))))),'complex)$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5
              (((((((sin (quotient (times 2 pi) 5)) . 1) ((i . 1) . 1))
                           (((cos (quotient (times 2 pi) 5)) . 1) . 1))
                          . 1))))
                      (r2c5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 1)
                             ((i . 1) . 2)))
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
                       (((((((sin (quotient (times 2 pi) 5)) . 3)
                            ((i . 1) . -1))
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 2)
                             ((i . 1) . 3)))
                         (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1)
                             ((i . 1) . -4)))
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 3)
                             ((i . 1) . 4)))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))),'complex)$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5
             (((((((sin (quotient (times 4 pi) 5)) . 1) ((i . 1) . 1))
                           (((cos (quotient (times 4 pi) 5)) . 1) . 1))
                          . 1))))
                      (r2c5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 1)
                             ((i . 1) . 2)))
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
                       (((((((sin (quotient (times 4 pi) 5)) . 3)
                            ((i . 1) . -1))
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 2)
                             ((i . 1) . 3)))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1)
                             ((i . 1) . -4)))
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 3)
                             ((i . 1) . 4)))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))),'complex)$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5
                       (((((((sin (quotient (times 4 pi) 5)) . 1)
                            ((i . 1) . -1))
                           (((cos (quotient (times 4 pi) 5)) . 1) . 1))
                          . 1))))
                      (r2c5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 1)
                             ((i . 1) . -2)))
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
               (((((((sin (quotient (times 4 pi) 5)) . 3) ((i . 1) . 1))
                           (((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 2)
                             ((i . 1) . -3)))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1)
                             ((i . 1) . 4)))
                           (((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 3)
                             ((i . 1) . -4)))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))),'complex)$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5
                       (((((((sin (quotient (times 2 pi) 5)) . 1)
                            ((i . 1) . -1))
                           (((cos (quotient (times 2 pi) 5)) . 1) . 1))
                          . 1))))
                      (r2c5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 1)
                             ((i . 1) . -2)))
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
             (((((((sin (quotient (times 2 pi) 5)) . 3) ((i . 1) . 1))
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 2)
                             ((i . 1) . -3)))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1)
                             ((i . 1) . 4)))
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 3)
                             ((i . 1) . -4)))
                        (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))),'complex)$
set!*representation('c5,
                    '(realtype
                      (id (((1 . 1))))
                      (rc5 (((1 . 1))))
                      (r2c5 (((1 . 1))))
                      (r3c5 (((1 . 1))))
                      (r4c5 (((1 . 1))))),'real)$
set!*representation('c5,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc5
                 (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                 (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                  ((((((sin (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                (((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1))))
                      (r2c5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))),'real)$
set!*representation('c5,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc5
                  (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                  (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                 (((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1))))
                      (r2c5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))),'real)$
set!*available 'c5$


%  Symmetry data, part 2.

set!*elems!*group('c6,'(id rc6 r2c6 r3c6 r4c6 r5c6))$
set!*generators('c6,'(rc6))$
set!*relations('c6,'(((rc6 rc6 rc6 rc6 rc6 rc6) (id))))$
set!*grouptable('c6,
                '((grouptable id rc6 r2c6 r3c6 r4c6 r5c6)
                  (id id rc6 r2c6 r3c6 r4c6 r5c6)
                  (rc6 rc6 r2c6 r3c6 r4c6 r5c6 id)
                  (r2c6 r2c6 r3c6 r4c6 r5c6 id rc6)
                  (r3c6 r3c6 r4c6 r5c6 id rc6 r2c6)
                  (r4c6 r4c6 r5c6 id rc6 r2c6 r3c6)
                  (r5c6 r5c6 id rc6 r2c6 r3c6 r4c6)))$
set!*inverse('c6,
  '((id rc6 r2c6 r3c6 r4c6 r5c6) (id r5c6 r4c6 r3c6 r2c6 rc6)))$
set!*elemasgen('c6,
               '(((rc6) (rc6))
                 ((r2c6) (rc6 rc6))
                 ((r3c6) (rc6 rc6 rc6))
                 ((r4c6) (rc6 rc6 rc6 rc6))
                 ((r5c6) (rc6 rc6 rc6 rc6 rc6))))$
set!*group('c6,'((id) (rc6) (r2c6) (r3c6) (r4c6) (r5c6)))$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6 (((1 . 1))))
                      (r2c6 (((1 . 1))))
                      (r3c6 (((1 . 1))))
                      (r4c6 (((1 . 1))))
                      (r5c6 (((1 . 1))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6 (((-1 . 1))))
                      (r2c6 (((1 . 1))))
                      (r3c6 (((-1 . 1))))
                      (r4c6 (((1 . 1))))
                      (r5c6 (((-1 . 1))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6
                (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . 1)
                       . 2))))
                      (r2c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r3c6 (((-1 . 1))))
                      (r4c6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r5c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . 1)
                          . 2))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r2c6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r3c6 (((1 . 1))))
                      (r4c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r5c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                       . 2))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r2c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r3c6 (((1 . 1))))
                      (r4c6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r5c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                        . 2))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . 1)
                          . 2))))
                      (r2c6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r3c6 (((-1 . 1))))
                      (r4c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r5c6
                (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . 1)
                          . 2))))),'complex)$
set!*representation('c6,
                    '(realtype
                      (id (((1 . 1))))
                      (rc6 (((1 . 1))))
                      (r2c6 (((1 . 1))))
                      (r3c6 (((1 . 1))))
                      (r4c6 (((1 . 1))))
                      (r5c6 (((1 . 1))))),'real)$
set!*representation('c6,
                    '(realtype
                      (id (((1 . 1))))
                      (rc6 (((-1 . 1))))
                      (r2c6 (((1 . 1))))
                      (r3c6 (((-1 . 1))))
                      (r4c6 (((1 . 1))))
                      (r5c6 (((-1 . 1))))),'real)$
set!*representation('c6,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc6
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (r2c6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                     (r3c6 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (r4c6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r5c6
                 (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (1 . 2))))),'real)$
set!*representation('c6,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r2c6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r3c6 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (r4c6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r5c6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))),'real)$
set!*available 'c6$

set!*elems!*group('s4,
                  '(id
                    bacd
                    acbd
                    abdc
                    dbca
                    cabd
                    bcad
                    dacb
                    bdca
                    dbac
                    cbda
                    adbc
                    acdb
                    badc
                    cdab
                    dcba
                    cbad
                    adcb
                    bcda
                    bdac
                    cadb
                    dabc
                    cdba
                    dcab))$
set!*generators('s4,'(bacd acbd abdc dbca))$
set!*relations('s4,
               '(((bacd bacd) (id))
                 ((acbd acbd) (id))
                 ((abdc abdc) (id))
                 ((dbca) (bacd acbd abdc acbd bacd))))$
set!*grouptable('s4,
                '((grouptable
                   dcab
                   dcba
                   dbac
                   dbca
                   dabc
                   dacb
                   cdab
                   cdba
                   cbad
                   cbda
                   cabd
                   cadb
                   bdac
                   bdca
                   bcad
                   bcda
                   bacd
                   badc
                   adbc
                   adcb
                   acbd
                   acdb
                   id
                   abdc)
                  (dcab
                   badc
                   abdc
                   cadb
                   acdb
                   cbda
                   bcda
                   bacd
                   id
                   dacb
                   adcb
                   dbca
                   bdca
                   cabd
                   acbd
                   dabc
                   adbc
                   dcba
                   cdba
                   cbad
                   bcad
                   dbac
                   bdac
                   dcab
                   cdab)
                  (dcba
                   bacd
                   id
                   cabd
                   acbd
                   cbad
                   bcad
                   badc
                   abdc
                   dabc
                   adbc
                   dbac
                   bdac
                   cadb
                   acdb
                   dacb
                   adcb
                   dcab
                   cdab
                   cbda
                   bcda
                   dbca
                   bdca
                   dcba
                   cdba)
                  (dbac
                   bcda
                   acdb
                   cbda
                   abdc
                   cadb
                   badc
                   bdca
                   adcb
                   dbca
                   id
                   dacb
                   bacd
                   cdba
                   adbc
                   dcba
                   acbd
                   dabc
                   cabd
                   cdab
                   bdac
                   dcab
                   bcad
                   dbac
                   cbad)
                  (dbca
                   bcad
                   acbd
                   cbad
                   id
                   cabd
                   bacd
                   bdac
                   adbc
                   dbac
                   abdc
                   dabc
                   badc
                   cdab
                   adcb
                   dcab
                   acdb
                   dacb
                   cadb
                   cdba
                   bdca
                   dcba
                   bcda
                   dbca
                   cbda)
                  (dabc
                   bdca
                   adcb
                   cdba
                   adbc
                   cdab
                   bdac
                   bcda
                   acdb
                   dcba
                   acbd
                   dcab
                   bcad
                   cbda
                   abdc
                   dbca
                   id
                   dbac
                   cbad
                   cadb
                   badc
                   dacb
                   bacd
                   dabc
                   cabd)
                  (dacb
                   bdac
                   adbc
                   cdab
                   adcb
                   cdba
                   bdca
                   bcad
                   acbd
                   dcab
                   acdb
                   dcba
                   bcda
                   cbad
                   id
                   dbac
                   abdc
                   dbca
                   cbda
                   cabd
                   bacd
                   dabc
                   badc
                   dacb
                   cadb)
                  (cdab
                   abdc
                   badc
                   acdb
                   cadb
                   bcda
                   cbda
                   id
                   bacd
                   adcb
                   dacb
                   bdca
                   dbca
                   acbd
                   cabd
                   adbc
                   dabc
                   cdba
                   dcba
                   bcad
                   cbad
                   bdac
                   dbac
                   cdab
                   dcab)
                  (cdba
                   id
                   bacd
                   acbd
                   cabd
                   bcad
                   cbad
                   abdc
                   badc
                   adbc
                   dabc
                   bdac
                   dbac
                   acdb
                   cadb
                   adcb
                   dacb
                   cdab
                   dcab
                   bcda
                   cbda
                   bdca
                   dbca
                   cdba
                   dcba)
                  (cbad
                   acdb
                   bcda
                   abdc
                   cbda
                   badc
                   cadb
                   adcb
                   bdca
                   id
                   dbca
                   bacd
                   dacb
                   adbc
                   cdba
                   acbd
                   dcba
                   cabd
                   dabc
                   bdac
                   cdab
                   bcad
                   dcab
                   cbad
                   dbac)
                  (cbda
                   acbd
                   bcad
                   id
                   cbad
                   bacd
                   cabd
                   adbc
                   bdac
                   abdc
                   dbac
                   badc
                   dabc
                   adcb
                   cdab
                   acdb
                   dcab
                   cadb
                   dacb
                   bdca
                   cdba
                   bcda
                   dcba
                   cbda
                   dbca)
                  (cabd
                   adcb
                   bdca
                   adbc
                   cdba
                   bdac
                   cdab
                   acdb
                   bcda
                   acbd
                   dcba
                   bcad
                   dcab
                   abdc
                   cbda
                   id
                   dbca
                   cbad
                   dbac
                   badc
                   cadb
                   bacd
                   dacb
                   cabd
                   dabc)
                  (cadb
                   adbc
                   bdac
                   adcb
                   cdab
                   bdca
                   cdba
                   acbd
                   bcad
                   acdb
                   dcab
                   bcda
                   dcba
                   id
                   cbad
                   abdc
                   dbac
                   cbda
                   dbca
                   bacd
                   cabd
                   badc
                   dabc
                   cadb
                   dacb)
                  (bdac
                   cbda
                   cadb
                   bcda
                   badc
                   acdb
                   abdc
                   dbca
                   dacb
                   bdca
                   bacd
                   adcb
                   id
                   dcba
                   dabc
                   cdba
                   cabd
                   adbc
                   acbd
                   dcab
                   dbac
                   cdab
                   cbad
                   bdac
                   bcad)
                  (bdca
                   cbad
                   cabd
                   bcad
                   bacd
                   acbd
                   id
                   dbac
                   dabc
                   bdac
                   badc
                   adbc
                   abdc
                   dcab
                   dacb
                   cdab
                   cadb
                   adcb
                   acdb
                   dcba
                   dbca
                   cdba
                   cbda
                   bdca
                   bcda)
                  (bcad
                   cadb
                   cbda
                   badc
                   bcda
                   abdc
                   acdb
                   dacb
                   dbca
                   bacd
                   bdca
                   id
                   adcb
                   dabc
                   dcba
                   cabd
                   cdba
                   acbd
                   adbc
                   dbac
                   dcab
                   cbad
                   cdab
                   bcad
                   bdac)
                  (bcda
                   cabd
                   cbad
                   bacd
                   bcad
                   id
                   acbd
                   dabc
                   dbac
                   badc
                   bdac
                   abdc
                   adbc
                   dacb
                   dcab
                   cadb
                   cdab
                   acdb
                   adcb
                   dbca
                   dcba
                   cbda
                   cdba
                   bcda
                   bdca)
                  (bacd
                   cdab
                   cdba
                   bdac
                   bdca
                   adbc
                   adcb
                   dcab
                   dcba
                   bcad
                   bcda
                   acbd
                   acdb
                   dbac
                   dbca
                   cbad
                   cbda
                   id
                   abdc
                   dabc
                   dacb
                   cabd
                   cadb
                   bacd
                   badc)
                  (badc
                   cdba
                   cdab
                   bdca
                   bdac
                   adcb
                   adbc
                   dcba
                   dcab
                   bcda
                   bcad
                   acdb
                   acbd
                   dbca
                   dbac
                   cbda
                   cbad
                   abdc
                   id
                   dacb
                   dabc
                   cadb
                   cabd
                   badc
                   bacd)
                  (adbc
                   dbca
                   dacb
                   dcba
                   dabc
                   dcab
                   dbac
                   cbda
                   cadb
                   cdba
                   cabd
                   cdab
                   cbad
                   bcda
                   badc
                   bdca
                   bacd
                   bdac
                   bcad
                   acdb
                   abdc
                   adcb
                   id
                   adbc
                   acbd)
                  (adcb
                   dbac
                   dabc
                   dcab
                   dacb
                   dcba
                   dbca
                   cbad
                   cabd
                   cdab
                   cadb
                   cdba
                   cbda
                   bcad
                   bacd
                   bdac
                   badc
                   bdca
                   bcda
                   acbd
                   id
                   adbc
                   abdc
                   adcb
                   acdb)
                  (acbd
                   dacb
                   dbca
                   dabc
                   dcba
                   dbac
                   dcab
                   cadb
                   cbda
                   cabd
                   cdba
                   cbad
                   cdab
                   badc
                   bcda
                   bacd
                   bdca
                   bcad
                   bdac
                   abdc
                   acdb
                   id
                   adcb
                   acbd
                   adbc)
                  (acdb
                   dabc
                   dbac
                   dacb
                   dcab
                   dbca
                   dcba
                   cabd
                   cbad
                   cadb
                   cdab
                   cbda
                   cdba
                   bacd
                   bcad
                   badc
                   bdac
                   bcda
                   bdca
                   id
                   acbd
                   abdc
                   adbc
                   acdb
                   adcb)
                  (id
                   dcab
                   dcba
                   dbac
                   dbca
                   dabc
                   dacb
                   cdab
                   cdba
                   cbad
                   cbda
                   cabd
                   cadb
                   bdac
                   bdca
                   bcad
                   bcda
                   bacd
                   badc
                   adbc
                   adcb
                   acbd
                   acdb
                   id
                   abdc)
                  (abdc
                   dcba
                   dcab
                   dbca
                   dbac
                   dacb
                   dabc
                   cdba
                   cdab
                   cbda
                   cbad
                   cadb
                   cabd
                   bdca
                   bdac
                   bcda
                   bcad
                   badc
                   bacd
                   adcb
                   adbc
                   acdb
                   acbd
                   abdc
                   id)))$
set!*inverse('s4,
             '((dcab
                dcba
                dbac
                dbca
                dabc
                dacb
                cdab
                cdba
                cbad
                cbda
                cabd
                cadb
                bdac
                bdca
                bcad
                bcda
                bacd
                badc
                adbc
                adcb
                acbd
                acdb
                id
                abdc)
               (cdba
                dcba
                cbda
                dbca
                bcda
                bdca
                cdab
                dcab
                cbad
                dbac
                bcad
                bdac
                cadb
                dacb
                cabd
                dabc
                bacd
                badc
                acdb
                adcb
                acbd
                adbc
                id
                abdc)))$
set!*elemasgen('s4,
               '(((bacd) (bacd))
                 ((acbd) (acbd))
                 ((abdc) (abdc))
                 ((dbca) (dbca))
                 ((cabd) (bacd acbd))
                 ((bcad) (acbd bacd))
                 ((dacb) (dbca bacd))
                 ((bdca) (bacd dbca))
                 ((dbac) (abdc dbca))
                 ((cbda) (dbca abdc))
                 ((adbc) (acbd abdc))
                 ((acdb) (abdc acbd))
                 ((badc) (bacd abdc))
                 ((cdab) (abdc bacd acbd dbca))
                 ((dcba) (acbd dbca))
                 ((cbad) (bacd acbd bacd))
                 ((adcb) (dbca bacd dbca))
                 ((bcda) (abdc acbd bacd))
                 ((bdac) (acbd bacd abdc))
                 ((cadb) (abdc bacd acbd))
                 ((dabc) (bacd acbd abdc))
                 ((cdba) (bacd acbd dbca))
                 ((dcab) (abdc acbd dbca))))$
set!*group('s4,
           '((dcab dabc cadb bdac bcda cdba)
             (dcba badc cdab)
             (dbac dacb cabd adbc acdb bcad bdca cbda)
             (dbca adcb abdc acbd bacd cbad)
             (id)))$
set!*representation('s4,
                    '((id (((1 . 1))))
                      (bacd (((1 . 1))))
                      (acbd (((1 . 1))))
                      (abdc (((1 . 1))))
                      (dbca (((1 . 1))))
                      (cabd (((1 . 1))))
                      (bcad (((1 . 1))))
                      (dacb (((1 . 1))))
                      (bdca (((1 . 1))))
                      (dbac (((1 . 1))))
                      (cbda (((1 . 1))))
                      (adbc (((1 . 1))))
                      (acdb (((1 . 1))))
                      (badc (((1 . 1))))
                      (cdab (((1 . 1))))
                      (dcba (((1 . 1))))
                      (cbad (((1 . 1))))
                      (adcb (((1 . 1))))
                      (bcda (((1 . 1))))
                      (bdac (((1 . 1))))
                      (cadb (((1 . 1))))
                      (dabc (((1 . 1))))
                      (cdba (((1 . 1))))
                      (dcab (((1 . 1))))),'complex)$
set!*representation('s4,
                    '((id (((1 . 1))))
                      (bacd (((-1 . 1))))
                      (acbd (((-1 . 1))))
                      (abdc (((-1 . 1))))
                      (dbca (((-1 . 1))))
                      (cabd (((1 . 1))))
                      (bcad (((1 . 1))))
                      (dacb (((1 . 1))))
                      (bdca (((1 . 1))))
                      (dbac (((1 . 1))))
                      (cbda (((1 . 1))))
                      (adbc (((1 . 1))))
                      (acdb (((1 . 1))))
                      (badc (((1 . 1))))
                      (cdab (((1 . 1))))
                      (dcba (((1 . 1))))
                      (cbad (((-1 . 1))))
                      (adcb (((-1 . 1))))
                      (bcda (((-1 . 1))))
                      (bdac (((-1 . 1))))
                      (cadb (((-1 . 1))))
                      (dabc (((-1 . 1))))
                      (cdba (((-1 . 1))))
                      (dcab (((-1 . 1))))),'complex)$
set!*representation('s4,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bacd
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (acbd
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (abdc
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dbca
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (cabd
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (bcad
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                    ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (dacb
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (bdca
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dbac
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (cbda
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (adbc
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (acdb
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (badc (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cdab (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (dcba (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cbad (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (adcb (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bcda (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bdac
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (cadb
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                      ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (dabc (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cdba
                  (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dcab
                  (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))),'complex)$
set!*representation('s4,
                    '((id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (bacd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (acbd
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (abdc
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (dbca
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cabd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcad
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dacb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (bdca
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (dbac
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cbda
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (adbc
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acdb
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (badc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cdab
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dcba
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cbad
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (adcb
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (bcda
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (bdac
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cadb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dabc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cdba
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (dcab
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))),'complex)$
set!*representation('s4,
                    '((id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (bacd
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acbd
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (abdc
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dbca
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cabd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcad
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dacb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (bdca
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (dbac
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cbda
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (adbc
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acdb
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (badc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cdab
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dcba
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cbad
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (adcb
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcda
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bdac
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cadb
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (dabc
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (cdba
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dcab
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))),'complex)$
set!*representation('s4,
                    '(realtype
                      (id (((1 . 1))))
                      (bacd (((1 . 1))))
                      (acbd (((1 . 1))))
                      (abdc (((1 . 1))))
                      (dbca (((1 . 1))))
                      (cabd (((1 . 1))))
                      (bcad (((1 . 1))))
                      (dacb (((1 . 1))))
                      (bdca (((1 . 1))))
                      (dbac (((1 . 1))))
                      (cbda (((1 . 1))))
                      (adbc (((1 . 1))))
                      (acdb (((1 . 1))))
                      (badc (((1 . 1))))
                      (cdab (((1 . 1))))
                      (dcba (((1 . 1))))
                      (cbad (((1 . 1))))
                      (adcb (((1 . 1))))
                      (bcda (((1 . 1))))
                      (bdac (((1 . 1))))
                      (cadb (((1 . 1))))
                      (dabc (((1 . 1))))
                      (cdba (((1 . 1))))
                      (dcab (((1 . 1))))),'real)$
set!*representation('s4,
                    '(realtype
                      (id (((1 . 1))))
                      (bacd (((-1 . 1))))
                      (acbd (((-1 . 1))))
                      (abdc (((-1 . 1))))
                      (dbca (((-1 . 1))))
                      (cabd (((1 . 1))))
                      (bcad (((1 . 1))))
                      (dacb (((1 . 1))))
                      (bdca (((1 . 1))))
                      (dbac (((1 . 1))))
                      (cbda (((1 . 1))))
                      (adbc (((1 . 1))))
                      (acdb (((1 . 1))))
                      (badc (((1 . 1))))
                      (cdab (((1 . 1))))
                      (dcba (((1 . 1))))
                      (cbad (((-1 . 1))))
                      (adcb (((-1 . 1))))
                      (bcda (((-1 . 1))))
                      (bdac (((-1 . 1))))
                      (cadb (((-1 . 1))))
                      (dabc (((-1 . 1))))
                      (cdba (((-1 . 1))))
                      (dcab (((-1 . 1))))),'real)$
set!*representation('s4,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bacd
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (acbd
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (abdc
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dbca
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (cabd
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (bcad
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                      ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (dacb
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (bdca
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dbac
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (cbda
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (adbc
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (acdb
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (badc (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cdab (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (dcba (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cbad (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (adcb (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bcda (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bdac
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (cadb
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (dabc (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cdba
                 (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dcab
                 (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))),'real)$
set!*representation('s4,
                    '(realtype
                      (id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (bacd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (acbd
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (abdc
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (dbca
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cabd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcad
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dacb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (bdca
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (dbac
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cbda
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (adbc
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acdb
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (badc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cdab
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dcba
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cbad
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (adcb
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (bcda
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (bdac
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cadb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dabc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cdba
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (dcab
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))),'real)$
set!*representation('s4,
                    '(realtype
                      (id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (bacd
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acbd
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (abdc
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dbca
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cabd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcad
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dacb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (bdca
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (dbac
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cbda
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (adbc
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acdb
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (badc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cdab
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dcba
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cbad
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (adcb
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcda
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bdac
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cadb
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (dabc
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (cdba
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dcab
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))),'real)$
set!*available 's4$

set!*elems!*group('a4,
                  '(id ta4 t2a4 xa4 ya4 za4 txa4 tya4 tza4 t2xa4 t2ya4
                       t2za4))$
set!*generators('a4,'(ta4 xa4 ya4 za4))$
set!*relations('a4,
               '(((za4) (ta4 xa4 ta4 ta4))
                 ((ya4) (ta4 za4 ta4 ta4))
                 ((xa4) (ta4 ya4 ta4 ta4))
                 ((ta4 ta4 ta4) (id))
                 ((xa4 xa4) (id))
                 ((ya4 ya4) (id))
                 ((za4 za4) (id))
                 ((xa4 ya4) (za4))))$
set!*grouptable('a4,
                '((grouptable
                   id
                   ta4
                   t2a4
                   xa4
                   ya4
                   za4
                   txa4
                   tya4
                   tza4
                   t2xa4
                   t2ya4
                   t2za4)
                  (id id ta4 t2a4 xa4 ya4 za4 txa4 tya4 tza4 t2xa4
                      t2ya4 t2za4)
                  (ta4 ta4 t2a4 id txa4 tya4 tza4 t2xa4 t2ya4 t2za4 xa4
                       ya4 za4)
                  (t2a4
                   t2a4
                   id
                   ta4
                   t2xa4
                   t2ya4
                   t2za4
                   xa4
                   ya4
                   za4
                   txa4
                   tya4
                   tza4)
                  (xa4 xa4 tya4 t2za4 id za4 ya4 tza4 ta4 txa4 t2ya4
                       t2xa4 t2a4)
                  (ya4 ya4 tza4 t2xa4 za4 id xa4 tya4 txa4 ta4 t2a4
                       t2za4 t2ya4)
                  (za4 za4 txa4 t2ya4 ya4 xa4 id ta4 tza4 tya4 t2za4
                       t2a4 t2xa4)
                  (txa4
                   txa4
                   t2ya4
                   za4
                   ta4
                   tza4
                   tya4
                   t2za4
                   t2a4
                   t2xa4
                   ya4
                   xa4
                   id)
                  (tya4
                   tya4
                   t2za4
                   xa4
                   tza4
                   ta4
                   txa4
                   t2ya4
                   t2xa4
                   t2a4
                   id
                   za4
                   ya4)
                  (tza4
                   tza4
                   t2xa4
                   ya4
                   tya4
                   txa4
                   ta4
                   t2a4
                   t2za4
                   t2ya4
                   za4
                   id
                   xa4)
                  (t2xa4
                   t2xa4
                   ya4
                   tza4
                   t2a4
                   t2za4
                   t2ya4
                   za4
                   id
                   xa4
                   tya4
                   txa4
                   ta4)
                  (t2ya4
                   t2ya4
                   za4
                   txa4
                   t2za4
                   t2a4
                   t2xa4
                   ya4
                   xa4
                   id
                   ta4
                   tza4
                   tya4)
                  (t2za4
                   t2za4
                   xa4
                   tya4
                   t2ya4
                   t2xa4
                   t2a4
                   id
                   za4
                   ya4
                   tza4
                   ta4
                   txa4)))$
set!*inverse('a4,
            '((id ta4 t2a4 xa4 ya4 za4 txa4 tya4 tza4 t2xa4 t2ya4 t2za4)
              (id t2a4 ta4 xa4 ya4 za4 t2za4 t2xa4 t2ya4 tya4 tza4 txa4)
            ))$
set!*elemasgen('a4,
               '(((ta4) (ta4))
                 ((t2a4) (ta4 ta4))
                 ((xa4) (xa4))
                 ((ya4) (ya4))
                 ((za4) (za4))
                 ((txa4) (ta4 xa4))
                 ((tya4) (ta4 ya4))
                 ((tza4) (ta4 za4))
                 ((t2xa4) (ta4 ta4 xa4))
                 ((t2ya4) (ta4 ta4 ya4))
                 ((t2za4) (ta4 ta4 za4))))$
set!*group('a4,
           '((id) (txa4 ta4 tza4 tya4) (t2za4 t2a4 t2ya4 t2xa4)
                  (ya4 xa4 za4)))$
set!*representation('a4,
                    '((id (((1 . 1))))
                      (ta4 (((1 . 1))))
                      (t2a4 (((1 . 1))))
                      (xa4 (((1 . 1))))
                      (ya4 (((1 . 1))))
                      (za4 (((1 . 1))))
                      (txa4 (((1 . 1))))
                      (tya4 (((1 . 1))))
                      (tza4 (((1 . 1))))
                      (t2xa4 (((1 . 1))))
                      (t2ya4 (((1 . 1))))
                      (t2za4 (((1 . 1))))),'complex)$
set!*representation('a4,
                    '((id (((1 . 1))))
                      (ta4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (t2a4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (xa4 (((1 . 1))))
                      (ya4 (((1 . 1))))
                      (za4 (((1 . 1))))
                      (txa4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (tya4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (tza4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (t2xa4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (t2ya4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (t2za4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1))
                               . -1)
                          . 2))))),'complex)$
set!*representation('a4,
                    '((id (((1 . 1))))
                      (ta4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (t2a4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (xa4 (((1 . 1))))
                      (ya4 (((1 . 1))))
                      (za4 (((1 . 1))))
                      (txa4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (tya4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (tza4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (t2xa4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (t2ya4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (t2za4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))),'complex)$
set!*representation('a4,
                    '((id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (ta4
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (t2a4
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (xa4
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (ya4
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (za4
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (txa4
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (tya4
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (tza4
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (t2xa4
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (t2ya4
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (t2za4
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))),'complex)$
set!*representation('a4,
                    '(realtype
                      (id (((1 . 1))))
                      (ta4 (((1 . 1))))
                      (t2a4 (((1 . 1))))
                      (xa4 (((1 . 1))))
                      (ya4 (((1 . 1))))
                      (za4 (((1 . 1))))
                      (txa4 (((1 . 1))))
                      (tya4 (((1 . 1))))
                      (tza4 (((1 . 1))))
                      (t2xa4 (((1 . 1))))
                      (t2ya4 (((1 . 1))))
                      (t2za4 (((1 . 1))))),'real)$
set!*representation('a4,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (ta4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . 1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (t2a4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . -1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))
                      (xa4 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (ya4 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (za4 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (txa4
                       (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (tya4
                       (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (tza4
                       (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (t2xa4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . -1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))
                      (t2ya4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . -1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))
                      (t2za4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . -1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))),'real)$
set!*representation('a4,
                    '(realtype
                      (id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (ta4
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (t2a4
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (xa4
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (ya4
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (za4
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (txa4
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (tya4
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (tza4
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (t2xa4
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (t2ya4
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (t2za4
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))),'real)$
set!*available 'a4$

end;
