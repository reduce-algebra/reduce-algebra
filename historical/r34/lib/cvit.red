module cvit;   % Header module for CVIT package.

% Authors:  A.Kryukov, A.Rodionov, A.Taranov.

% Copyright (C) 1988,1990, Institute of Nuclear Physics, Moscow State
%                          University.

% The CVITMAC module can be loaded for compilation only,
% and need not be present during run time.

% The High Energy Physics package must be loaded first.

load!-package 'hephys;

endmodule;


module cvitmac;  % smacro procedures for Cvitanovich package.

% COPYRIGHT (C) 1988,1990, INSTITUTE OF NUCLEAR PHYSICS, MOSCOW STATE
%                          UNIV.
% AUTHOR    A.KRYUKOV, A.RODIONOV, A.TARANOV
% VERSION   2.1
% RELEASE   11-MAR-90

% 07.06.90 all MAP replaced by MAP!_   RT
% 08.06.90 SOME MACROS FROM CVITMAP FILE ADDED to section IV RT
% 10.06.90 SOME MACROS FROM CVITMAP FILE ADDED  RT

 
  %************ SECTION I ************************************

  smacro   procedure hvectorp x$
     get(x,'rtype) eq 'hvector$

  smacro   procedure windexp x$
     x memq car windices!*$

  smacro   procedure replace!_by!_indexp v$
     get(v,'replace!_by!_index)$

  smacro   procedure indexp i$
     i memq indices!*$

  smacro   procedure replace!_by!_vectorp i$
     get(i,'replace!_by!_vector)$

  smacro   procedure replace!_by!_vector i$
     get(i,'replace!_by!_vector) or i$

  smacro   procedure gamma5p x$
     memq(x,car gamma5!*)$

  smacro   procedure nospurp x$
     flagp(x,'nospur)$

  smacro   procedure clear!_gamma5()$
     gamma5!* := nil . append(reverse car gamma5!*,cdr gamma5!*)$

%********************* SECTION II **************************

symbolic smacro procedure p!_empty!_map!_ map!_$
% IS MAP!_ EMPTY ? $
    null map!_$

symbolic smacro procedure p!_empty!_vertex vertex$
% IS VERTEX EMPTY ? $
    null vertex$

%++++++++++++++++++++++++++ SELECTORS +++++++++++++++++++++++++++++++$

symbolic smacro procedure s!_vertex!_first map!_$
% SELECT FIRST VERTEX IN MAP!_ $
  car map!_$

symbolic smacro procedure s!_map!_!_rest map!_$
% SELECT TAIL OF MAP!_ $
  cdr map!_$

symbolic smacro procedure s!_vertex!_second map!_$
% SELECT SECOND VERTEX IN MAP!_ $
  s!_vertex!_first s!_map!_!_rest map!_$

symbolic smacro procedure first!_edge vertex$
% SELECT FIRST EDGE IN VERTEX $
  car vertex$

symbolic smacro procedure s!_vertex!_rest vertex$
% SELECT TAIL OF VERTEX $
  cdr vertex$

symbolic smacro procedure second!_edge vertex$
% SELECT SECOND EDGE IN VERTEX $
  first!_edge s!_vertex!_rest vertex$

symbolic smacro procedure s!_edge!_name edge$
% SELECT EDGE'S NAME $
  car edge$

symbolic smacro procedure s!_edge!_prop!_ edge$
% SELECT PROP!_ERTY OF AN EDGE (NAMES OF PARENTS OR NUMBERS)$
  cadr edge$

symbolic smacro procedure s!_edge!_type edge$
% SELEC TYPE (PARITY) OF AN EDGE$
  caddr edge$

%?????????????????????? CONSTRUCTORS ??????????????????????????????$

symbolic smacro procedure add!_vertex (vertex,map!_)$
% ADD VERTEX TO MAP!_ $
  vertex . map!_ $

symbolic smacro procedure add!_edge (edge,vertex)$
% ADD EDGE TO VERTEX$
  edge . vertex$

symbolic smacro procedure append!_map!_s (map!_1,map!_2)$
% APPEND TWO MAP!_S  $
  append(map!_1,map!_2)$

symbolic smacro procedure conc!_map!_s (map!_1,map!_2)$
% APPEND TWO MAP!_S  $
 nconc(map!_1,map!_2)$

symbolic smacro procedure conc!_vertex (vertex1,vertex2)$
% APPEND TWO VERTECES
 nconc(vertex1,vertex2)$

symbolic smacro procedure mk!_name1 name$
 explode name$

symbolic smacro procedure mk!_edge!_prop!_ (prop!_1,prop!_2)$
 prop!_1 . prop!_2 $

symbolic smacro procedure mk!_edge!_type (typ1,typ2)$
% DEFINED EDGE <=> TYPE T,
% UNDEFINED EDGE <=> TYPE NIL$
    typ1 and  typ2 $

symbolic smacro procedure mk!_edge (name,prop!_,type)$
% MAKE UP NEW EDGE $
 list(name,prop!_,type)$

symbolic smacro procedure mk!_edge3!_vertex (edge1,edge2,edge3)$
% MAKES PRIMITIVE VERTEX  $
  list(edge1,edge2,edge3)$

symbolic smacro procedure mk!_empty!_map!_ ()$
% GENERATE EMPTY MAP!_ $
  nil $

symbolic smacro procedure mk!_empty!_vertex ()$
% GENERATE EMPTY VERTEX $
  nil $

symbolic smacro procedure mk!_vertex1!_map!_ vertex1$
% MAKE MAP!_ OF ONE VERTEX $
  list(vertex1)$

symbolic smacro procedure mk!_vertex2!_map!_ (vertex1,vertex2)$
% MAKE MAP!_ OF TWO VERTECES $
  list(vertex1,vertex2)$

symbolic smacro procedure mk!_edge2!_vertex (edge1,edge2)$
%MAKES VERTEX FROM TWO EDGES$
  list(edge1,edge2)$

 symbolic smacro procedure conc!_vertex (vertex1,vertex2)$
  nconc(vertex1,vertex2)$

symbolic smacro procedure cycl!_map!_ map!_$
% MAKES CYCLIC PERMUTATION OF MAP!_$
    append(cdr map!_,list car map!_)$

symbolic smacro procedure cycl!_vertex vertex$
% MAKES CYCLIC PERMUTATION OF VERTEX$
    append(cdr vertex,list car vertex)$

symbolic smacro procedure mk!_world (actedges,world1)$
  list(actedges,list nil,world1)$

%====================== PREDICATES (CONTINUE) =====================$

symbolic smacro procedure p!_member!_edge (edge,vertex)$
% IS EDGE (WITH THE SAME NAME) CONTAINS IN VERTEX ?$
  assoc(s!_edge!_name edge,vertex)$

symbolic smacro procedure equal!_edges (edge1,edge2)$
% IF EDGES HAVE THE SAME NAMES ? $
  eq   ( s!_edge!_name edge1,
         s!_edge!_name edge2)$

symbolic smacro procedure single!_no!_parents edges$
 length edges = 1 $

symbolic smacro procedure resto!_map!_!_order map!_$
% REVERSE (BETTER REVERSIP) MAP!_ $
  reverse map!_$

symbolic smacro procedure map!_!_length map!_$
% NUMBER OF VERTECES IN MAP!_$$
  length map!_$

symbolic smacro procedure vertex!_length vertex$
% NUMBER OF EDGES IN VERTEX $
  length vertex$

symbolic smacro procedure prepare!_map!_ map!_$
 for each x in map!_
  collect mk!_old!_edge x$

symbolic smacro procedure p!_vertex!_prim vertex$
% IS VERTEX PRIMITIVE ? $
  vertex!_length (vertex) <= 3 $

  %************ SECTION III ************************************

symbolic smacro procedure s!-edge!-name edge$ car edge$

symbolic smacro procedure sappend(x,y)$ append(x,y)$

symbolic smacro procedure sreverse y $ reverse   y$

symbolic smacro procedure getedge(x,y)$ cdr assoc(x,y)$

symbolic smacro procedure mk!-road!-name(x,y,n)$
list(car x . n,car y . n)$

symbolic smacro procedure mk!-external!-leg edge$
%< FLAG(LIST EDGE,'EXTRNL)$
list(    edge . 0)   $

symbolic smacro procedure index!-in(ind,l)$
if atom ind then nil
else member(ind,l)$

  %************ SECTION IV ************************************

symbolic smacro procedure reverse!_map!_ map!_$
  reverse map!_$

symbolic smacro procedure mk!_edge1!_vertex edge$
 list edge$

symbolic smacro procedure mk!_edges!_vertex edges$
  edges$

symbolic smacro procedure reversip!_vertex vertex$
  reversip vertex$

symbolic smacro procedure append!_vertex (vertex1,vertex2)$
   append(vertex1,vertex2)$

%symbolic smacro procedure conc!_vertex (vertex1,vertex2)$
% nconc(vertex1,vertex2)$

symbolic smacro procedure mk!_edge4!_vertex (edge1,edge2,edge3,edge4)$
  list(edge1,edge2,edge3,edge4)$

symbolic smacro procedure p!_old!_edge edge$
 assoc(s!_edge!_name edge,old!_edge!_list )$


symbolic smacro procedure s!_atlas!_map!_ atlas$
 car atlas$

symbolic smacro procedure s!_atlas!_coeff atlas$
 cadr atlas$

symbolic smacro procedure s!_atlas!_den!_om atlas$
 caddr atlas$

symbolic smacro procedure mk!_atlas (map!_,atlases,den!_om)$
 list(map!_,atlases,den!_om)$

symbolic smacro procedure vertex!_edges edge$
  edge$

symbolic smacro procedure s!_coeff!_world1 world1$
 cadr world1 $

symbolic smacro procedure s!_edgelist!_world world$
 car world$

symbolic smacro procedure s!_world1 world$
 caddr world $


symbolic smacro procedure s!_world!_var world$
 cadr world$

symbolic smacro procedure s!_world!_atlas world$
  caddr world$

symbolic smacro procedure s!_world!_edges world$
 car world$

endmodule;


module red!_to!_cvit!_interface$

% COPYRIGHT (C) 1988,1990, INSTITUTE OF NUCLEAR PHYSICS, MOSCOW STATE
%                          UNIV.
% PURPOSE   INTERFACE BETWEEN REDUCE AND CVITANOVICH ALGORITHM.
% AUTHOR    A.KRYUKOV
% VERSION   2.1
% RELEASE   11-MAR-90

  exports isimp1,replace!_by!_vector, replace!_by!_vectorp, gamma5p$
  imports calc!_spur, isimp2$

  fluid  '(!*msg ndims!* dindices!*)$
  global '(windices!* indices!* !*cvit gamma5!* !*g5cvit)$
  if null windices!*
    then windices!*:=
            '(nil !_f0 !_f1 !_f2 !_f3 !_f4 !_f5 !_f6 !_f7 !_f8 !_f9)$

  if null gamma5!*
    then gamma5!*:=
            '(nil !_a0 !_a1 !_a2 !_a3 !_a4 !_a5 !_a6 !_a7 !_a8 !_a9)$

  switch cvit$               % CVITANOVICH ALGORITHM SWITCH
  !*cvit := t$               % DEFAULT ON

  %************ ISIMP1 REDEFINITION ************************

  remflag('(isimp1),'lose)$

  symbolic procedure isimp1(u,i,v,w,x)$
     if null u then nil
      else if domainp u
         then if x then multd(u,if !*cvit
                                  then calc!_spurx (i,v,w,x)
                                  else spur0 (car x,i,v,w,cdr x)
                             )
               else if v then multd(u,index!_simp (1,i,v,w))
               else if w then multfs(emult w,isimp1(u,i,v,nil,nil))
               else u
      else addfs(isimp2(car u,i,v,w,x),isimp1(cdr u,i,v,w,x))$

  flag('(isimp1),'lose)$

  %************* INDEX!_SIMP *******************************

  symbolic procedure index!_simp (u,i,v,w)$
     if v then index!_simp (multf(mksprod(caar v,cdar v),u),
                            update!_index (i,car v),cdr v,w)
       else isimp1(u,i,nil,w,nil)$

  symbolic procedure mksprod(x,y)$
     mkdot(if indexp x then replace!_by!_vector x else x,
           if indexp y then replace!_by!_vector y else y)$

  symbolic procedure update!_index (i,v)$
     % I  - LIST OF UNMATCH INDICES
     % V  - PAIR: (I/V . I/V)
     % VALUE - UPDATE LIST OF INDICES
     delete(cdr v,delete(car v,i))$

  %************ CALC!_SPURX - MAIN PROCEDURE ***************

  symbolic procedure calc!_spurx (i,v,w,x)$
     % I - LIST OF INDICES
     % V - LIST OF SCALAR PRODUCT:(<I/V> . <I/V>)
     % W - EPS-EXPR
     % X - LIST OF SPURS
     % VALUE - CALCULATED SPUR(S.F.)
     begin scalar u,          % SPUR: (LNAME G5SWITCH I/V I/V ... )
                  x1,         % (UN ... U1)
                  dindices!*, % A-LIST OF DUMMY INDICES: (I . NIL/T)
                  c$          % COEFFICIENT GENERATIED BY GX*GX
           if numberp ndims!* and null evenp ndims!*
             then cviterr list('calc!_spur, ":", ndims!*,
                     "IS NOT EVEN DIMENSION OF G-MATRIX SPACE")$
           c := 1$            % INITIAL VALUE
           while x
             do << if nospurp caar x
                     then cviterr list "NOSPUR NOT YET IMPLEMENTED"$
                   u := cdar x$
                   x := cdr x$
                   if car u
                     then if evenp ndims!*
                            then u := next!_gamma5() . reverse cdr u
                            else cviterr
                                   list("G5 INVALID FOR NON EVEN DIM")
                     else u := reverse cdr u$
                   if null u then nil                 % SP()
                     else if null evenp length(if gamma5p car u
                                                    and cdr u
                                                 then cdr u
                                                 else u)
                            then x := c := nil        % ODD - VALUE=0
                     else << u := remove!_gx!*gx u$
                             c := multf(car u,c)$
                             u := replace!_vector(cdr u,i,v,w)$
                             i := cadr u$
                             v := caddr u$
                             w := cadddr u$
                             if u then x1 := car u . x1
                          >>
                >>$
           x1 := if null c then nil ./ 1         % ZERO
                   else if x1 then multsq(c ./ 1,calc!_spur x1)
                   else c ./ 1$
           if denr x1 neq 1 then cviterr list('calc!_spurx, ":",x1,
                                    "HAS NON UNIT DENOMINATOR")$
           clear!_windices ()$
           clear!_gamma5 ()$
           return isimp1(numr x1,i,v,w,nil)
     end$

  symbolic procedure third!_eq!_indexp i$
     begin scalar z$
           if null(z := assoc(i,dindices!*))
             then dindices!* := (i . nil) . dindices!*
             else if null cdr z
                    then dindices!* := (i . t) . delete(z,dindices!*)$
           return if z then cdr z else nil
     end$

  symbolic procedure replace!_vector(u,i,v,w)$
     % U  - SPUR (INVERSE)
     % I  - LIST OF UNMATCH INDICES
     % V  - A-LIST OF SCALAR PRODUCT
     % W  - EPS-EXPRESION
     % VALUE - LIST(U,UPDATE I,UPDATE V,UPDATE W)
     begin scalar z,y,x,     % WORK VARIABLES
                  u1$        % SPUR WITHOUT VECTOR
           while u
             do << z := car u$
                   u := cdr u$
                   if indexp z
                     then << % REMOVE DUMMY INDICES
                             while (y := bassoc(z,v))
                               do << i := delete(z,i)$
                                     v := delete(y,v)$
%                                    W := ....
                                     x := if z eq car y then cdr y
                                            else car y$
                                     if indexp x then z := x
                                       else if gamma5p x
                                         then cviterr list
                                                "G5 BAD STRUCTURE"
                                       else replace!_by!_index (x,z)
                                  >>$
                             u1 := z . u1
                          >>
                     else if gamma5p z then u1 := z . u1
                     else << z := replace!_by!_index (z,next!_windex())$
                             u1 := z . u1
                          >>
                >>$
           return list(reverse u1,i,v,w)
     end$

  symbolic procedure replace!_by!_index (v,y)$
     begin scalar z$
           if (z := replace!_by!_vectorp y) eq v
             then cviterr list('replace!_by!_index, ":",y,
                              "IS ALREADY DEFINED FOR VECTOR",z)$
           put(y,'replace!_by!_vector ,v)$
           return y
     end$

  symbolic procedure remove!_gx!*gx u$
     begin scalar x,c$
           integer l,l1$
           c := 1$
           l1 := l := length u$
           u := for each z in u                  % MAKE COPY
                  collect << if indexp z
                               then if third!_eq!_indexp z
                                      then cviterr list(
                                           "THREE INDICES HAVE NAME",z)
                                      else nil
                               else if null hvectorp z
                                      then if cvitdeclp(z,'vector)
                                             then vector1 list z
                                             else cviterr nil
                               else nil$
                             z
                          >>$
           if l < 2 then return u$
           x := u$
           while cdr x do x := cdr x$
           rplacd(x,u)$                          % MAKE CYCLE
           while l1 > 0
             do if car u eq cadr u               % EQUAL ?
                  then << c := multf(if indexp car u then ndims!*
                                       else mkdot(car u,car u)
                                    ,c)$
                          rplaca(u,caddr u)$     % YES - DELETE
                          rplacd(u,cdddr u)$
                          l1 := l := l - 2
                       >>
                  else << u := cdr u$            % NO - CHECK NEXT PAIR
                          l1 := l1 - 1
                       >>$
           x := cdr u$
           rplacd(u,nil)$                        % CUT CYCLE
           return (c . if cdr x and car x eq cadr x then nil
                         else x)
     end$

  %************* ERROR,MESSAGE *****************************

  symbolic procedure cviterr u$
     << clear!_windices()$
        clear!_gamma5()$
        if u then rederr u else error(0,nil) >>$

  symbolic procedure cvitdeclp(u,v)$
     if null !*msg then nil
       else if terminalp()
              then yesp list("DECLARE",u,v,"?")
       else << lprim list(u,"DECLARE",v)$ t >>$

  %*********** WORK INDICES & VECTOR ***********************

  symbolic procedure clear!_windices ()$
     while car windices!*
       do begin scalar z$
             z := caar windices!*$
             windices!* := cdar windices!* . z . cdr windices!*$
             remprop(z,'replace!_by!_vector)$
             indices!* := delete(z,indices!*)$
          end$

  symbolic procedure next!_windex()$
     begin scalar i$
           windices!* := if null cdr windices!*
                           then (intern gensym() . car windices!*) .
                                cdr windices!*
                           else (cadr windices!* . car windices!*) .
                                cddr windices!*$
           i := caar windices!*$
           vector1 list i$
           indices!* := i . indices!*$
           return i
     end$

  symbolic procedure next!_gamma5()$
     begin scalar v$
           cviterr list "GAMMA5 IS NOT YET IMPLEMENTED. USE OFF CVIT";
           gamma5!* := if null cdr gamma5!*
                           then (intern gensym() . car gamma5!*) .
                                cdr gamma5!*
                           else (cadr gamma5!* . car gamma5!*) .
                                cddr gamma5!*$
           v := list caar gamma5!*$
           vector1 v$
           return car v
     end$

  %************ END ****************************************

%prin2t "_Cvitanovich_algorithm_is_ready"$

endmodule$


module map!_to!_strand$

%************* TRANSFORMATION OF MAP TO STRAND **********************$
%                                                                    $
%                       25.11.87                                     $
%                                                                    $
%********************************************************************$

  exports    color!-strand,contract!-strand $
  imports  nil$
  
%---------------- utility added 09.06.90 ---------------------------
symbolic procedure constimes u;
% u=list of terms
% inspect u, delete all 1's
% and form smar product   $
 ctimes(u,nil)$
 
symbolic procedure ctimes(u,s);
if null u then
  if null s then 1
  else if null cdr s then car s 
       else 'times . s 
else if car u = 1 then ctimes(cdr u,s)
     else ctimes(cdr u,car u . s)$
     
symbolic procedure consrecip u;
% do same as consTimes
if or(car u = 1,car u = -1) then car u
else 'recip . u$

symbolic procedure listquotient(u,v)$
% the same !!!
if v=1 then u 
else 
  if v = u then 1
  else list('quotient,u,v)$

symbolic procedure consplus u;
% u=list of terms
% inspect u, delete all 0's
% and form smar sum   $
 cplus(u,nil)$
 
symbolic procedure cplus(u,s);
if null u then
  if null s then 0
  else if null cdr s then car s 
       else 'plus . s 
else if car u = 0 then cplus(cdr u,s)
     else cplus(cdr u,car u . s)$
     
%--------------------------------------------------------------------
   
  

%---------------- CONVERTING OF MAP TO STRAND DIAGRAM ---------------$

symbolic procedure map!_!-to!-strand(edges,map!_)$
%.....................................................................
% ACTION: CONVERTS "MAP!_" WITH "EDGES" INTO STRAND DIAGRAM.
% STRAND ::= <LIST OF STRAND VERTECES>,
% STRAND VERTEX ::= <SVERTEX NAME> . (<LIST1 OF ROADS> <LIST2 ...>),
% ROAD ::= <ATOM> . <NUMBER>.
% LIST1,2 CORRESPOND TO OPPOSITE SIDES OF STRAND VERTEX.
% ROADS LISTED CLOCKWISE.
%....................................................................$
if null edges then nil
else mk!-strand!-vertex(car edges,map!_) .
                                map!_!-to!-strand(cdr edges,map!_)$

%YMBOLIC PROCEDURE MAP!_!-TO!-STRAND(EDGES,MAP!_)$
%F NULL EDGES THEN NIL
%LSE (LAMBDA SVERT$ IF SVERT THEN SVERT .
%                               MAP!_!-TO!-STRAND(CDR EDGES,MAP!_)
%                   ELSE MAP!_!-TO!-STRAND(CDR EDGES,MAP!_) )
%          MK!-STRAND!-VERTEX(CAR EDGES,MAP!_)$

symbolic procedure mk!-strand!-vertex(edge,map!_)$
begin
  scalar vert1,vert2,tail$
         tail:=incident(edge,map!_,1)$
         vert1:=car tail$
         tail:=incident(edge,cdr tail,add1 cdar vert1)$
         vert2:= if null tail then mk!-external!-leg edge
                 else car tail$
   return %F NULL VERT2 THEN NIL
               mk!-strand!-vertex2(edge,vert1,vert2)
end$

symbolic procedure incident(edge,map!_,vertno)$
if null map!_ then nil
else (lambda z$ if z then  z . cdr map!_
                else incident(edge,cdr map!_,add1 vertno) )
             incident1(              edge,car map!_,vertno)$

symbolic procedure incident1(edname,vertex,vertno)$
if eq(edname,s!-edge!-name car vertex) then
             mk!-road!-name(cadr vertex,caddr vertex,vertno)
else if eq(edname,s!-edge!-name cadr vertex) then
         mk!-road!-name(caddr vertex,car vertex,vertno)
     else if eq(edname,s!-edge!-name caddr vertex) then
                 mk!-road!-name(car vertex,cadr vertex,vertno)
          else nil$

symbolic procedure mk!-strand!-vertex2(edge,vert1,vert2)$
list(edge,    vert1,              vert2)$

%------------------ COLOURING OF ROADS IN STRAND --------------------$

symbolic procedure color!-strand(alst,map!_,count)$
%.....................................................................
% ACTION: GENERATE REC. ALIST COLORING STRAND,CORRESPONDING TO "MAP!_".
% COLORING OF STRAND INDUCED BY "MAP!_" COLORING, DEFINED BY ALIST
% "ALST". "COUNT" COUNTS MAP!_ VERTECES. INITIALLY IS 1.
% REC.ALIST::= ( ... <(ATOM1 . COL1 ATOM2 . COL2 ...) . NUMBER> ... )
% WHERE COL1 IS COLOR OF ROAD=ATOM1 . NUMBER.
%....................................................................$
if null map!_ then nil
else  (color!-roads(alst,car map!_) . count) .
                          color!-strand(alst,cdr map!_,add1 count)$

symbolic procedure color!-roads(alst,vertex)$
begin
    scalar e1,e2,e3,lines$
    e1:=getedge(s!-edge!-name car vertex,alst)$
    e2:=getedge(s!-edge!-name cadr vertex,alst)$
    e3:=getedge(s!-edge!-name caddr vertex,alst)$
    lines:=(e1+e2+e3)/2$
    e1:=lines-e1$
    e2:=lines-e2$
    e3:=lines-e3$
  return list(
               s!-edge!-name car vertex . e1,
               s!-edge!-name cadr vertex . e2,
               s!-edge!-name caddr vertex . e3)
end$

symbolic procedure zero!-roads l$
%---------------------------------------------------------------------
% L IS OUTPUT OF COLOR!-STRAND
%--------------------------------------------------------------------$
if null l then nil
else (lambda z$ if z then z . zero!-roads cdr l
                else zero!-roads cdr l)
              z!-roads car l$

symbolic procedure z!-roads y$
(lambda w$  w and (car w . cdr y))
    ( if (0=cdr caar y)then caar y
      else if  (0=cdr cadar y) then cadar y
           else if (0=cdr caddar y) then caddar y
                else nil)$

%------------------- CONTRACTION OF STRAND --------------------------$

symbolic procedure deletez1(strand,alst)$
%.....................................................................
% ACTION: DELETES FROM "STRAND" VERTECES WITH NAMES HAVING 0-COLOR
% VIA MAP!_-COLORING ALIST "ALST".
%....................................................................$
if null strand then nil
else if 0 = cdr assoc(caar strand,alst) then
                          deletez1(cdr strand,alst)
     else car strand . deletez1(cdr strand,alst)$

symbolic procedure contract!-strand(strand,slst)$
%.....................................................................
% ACTION: CONTRACTS "STRAND".
% "SLST" IS REC. ALIST COLORING "STRAND"
%....................................................................$
contr!-strand(strand,zero!-roads slst)$

symbolic procedure contr!-strand(strand,zlst)$
if null zlst then strand
else contr!-strand(contr1!-strand(strand,car zlst),cdr zlst)$

symbolic procedure contr1!-strand(strand,rname)$
contr2!-strand(strand,rname,nil,nil)$

symbolic procedure contr2!-strand(st,rname,rand,flag!_)$
if null st then rand
else (lambda z$
          if z then
            if member(car z,cdr z) then sappend(st,rand)  % 16.12 ****$
            else
                if null flag!_ then
                  contr2!-strand(contr2(z,cdr st,rand),rname,nil,t)
                else contr2(z,cdr st,rand)
          else contr2!-strand(cdr st,rname,car st . rand,nil)  )
      contrsp(car st,rname)$

symbolic procedure contrsp(svertex,rname)$
contrsp2(cadr svertex,caddr svertex,rname)
                or
contrsp2(caddr svertex,cadr svertex,rname)$

symbolic procedure contrsp2(l1,l2,rname)$
if 2 = length l1 then
 if rname = car l1 then (cadr l1) . l2
 else if rname = cadr l1 then (car l1) . l2
else nil$

symbolic procedure contr2(single,st,rand)$
if null st then contr(single,rand)
else if null rand then contr(single,st)
     else
          split!-road(single,car st) . contr2(single,cdr st,rand)$

symbolic procedure contr(single,strand)$
if null strand then nil
else split!-road(single,car strand) . contr(single,cdr strand)$

symbolic procedure split!-road(single,svertex)$
list(car svertex,
sroad(car single,cdr single,cadr svertex),
             sroad(car single,cdr single,caddr svertex))$

symbolic procedure sroad(line!_,lines,lst)$
if null lst then nil
else if line!_ = car lst then sappend(lines,cdr lst)
     else car lst . sroad(line!_,lines,cdr lst)$

endmodule$


%********************************************** **********************
%******************** INTERACTION WITH ALG MODE **********************
%********************       11.12.87            **********************
%******************** VARIANT WITHOUT NONLOCALS **********************
%********************************************************************$
module eval!_map!_s$
  exports    strand!-alg!-top $
  imports    color!-strand,contract!-strand $

lisp$

%------------------ AUXILIARRY ROUTINES -----------------------------$

symbolic procedure permpl(u,v)$
if null u then t
else if car u = car v then permpl(cdr u,cdr v)
     else not permpl(cdr u,l!-subst1(car v,car u,cdr v))$

symbolic procedure repeatsp u$
if null u then nil
else (member(car u,cdr u) or repeatsp cdr u )$

symbolic procedure l!-subst1(new,old,l)$
if null l then nil
else if old = car l then new . cdr l
     else (car l) . l!-subst1(new,old,cdr l)$

%-------------------FORMING ANTISYMMETRIHERS -----------------------$

symbolic procedure propagator(u,v)$
if null u then      1
else if (repeatsp u) or (repeatsp v) then 0
     else 'plus . propag(u,permutations v,v)$

symbolic procedure propag(u,l,v)$
if null l then      nil
else (if permpl(v,car l) then 'times . prpg(u,car l)
      else list('minus,'times . prpg(u,car l) ) ) . propag(u,cdr l,v)$

symbolic procedure prpg(u,v)$
if null u then nil
else list('cons,car u,car v) . prpg(cdr u,cdr v)$

symbolic procedure line(x,y)$
propagator(cdr x,cdr y)$

%------------------ INTERFACE  WITH CVIT3 ---------------------------$

symbolic procedure strand!-alg!-top(strand,map!_,edlst)$
begin
  scalar rlst$
      strand:=deletez1(strand,edlst)$
      rlst:=color!-strand(edlst,map!_,1)$
      strand:=contract!-strand(strand,rlst) $
 %RINT STRAND$ TERPRI()$
 %RINT RLST$ TERPRI()$
 %RINT EDLST$ TERPRI()$
 return dstr!-to!-alg(strand,rlst,nil)
%ATHPRINT REVAL(W)$ RETURN W
end$


symbolic procedure mktails(side,rlst,dump)$
begin
  scalar pntr,newdump,w,z$
    if null side then return nil . dump$
    pntr:=side$
    newdump:=dump$
 while pntr do  <<  w:=mktails1(car pntr,rlst,newdump)$
                    newdump:=cdr w$
                    z:=sappend(car w,z)$
                    pntr:=cdr pntr >>$
    return z . newdump
end$

symbolic procedure mktails1(rname,rlst,dump)$
begin
 scalar color,prename,z$
       color:=getroad(rname,rlst)$
     if 0 = color then return nil . dump$
     if 0 = cdr rname then
      return (list replace!_by!_vector car rname) . dump$
 %   IF FREEIND CAR RNAME THEN RETURN (LIST CAR RNAME) . DUMP$
       z:=assoc(rname,dump)$
     if z then return
                if null cddr z then  cdr z . dump
                else (sreverse cdr z) . dump$
  %    PRENAME:=APPEND(EXPLODE CAR RNAME,EXPLODE CDR RNAME)$
       prename:=rname$
       z:= mkinds(prename,color)$
   return z . ((rname . z) . dump)
end$

symbolic procedure mkinds(prename,color)$
if color = 0 then nil
else
     begin
         scalar indx$
    %     INDX:=INTERN COMPRESS APPEND(PRENAME,EXPLODE COLOR)$
          indx:=                       prename . color $
       return indx . mkinds(prename,sub1 color)
     end$

symbolic procedure getroad(rname,rlst)$
if null rlst then 1 % ******EXT LEG IS ALWAYS SUPPOSET TO BE SIMPLE $
else if cdr rname = cdar rlst then
              cdr qassoc(car rname,caar rlst)
     else getroad(rname,cdr rlst) $


symbolic procedure qassoc(atm,alst)$
if null alst then nil
else if eq(atm,caar alst) then car alst
     else qassoc(atm,cdr alst)$

%------------- INTERACTION WITH RODIONOV ---------------------------$

symbolic procedure from!-rodionov x$
begin
  scalar strand,edges,edgelsts,map!_,w$
            edges:=car x$
            map!_:=cadr x$
            edgelsts:=cddr x$
         strand := map!_!-to!-strand(edges,map!_)$
     w:= for each edlst in edgelsts collect
             strand!-alg!-top(strand,map!_,edlst)$
     return reval('plus . w )
end$

symbolic procedure top1 x$
mathprint from!-rodionov to!_taranov x$

%----------------------- COMBINATORIAL COEFFITIENTS -----------------$

symbolic procedure f!^(n,m)$
if n<m then cviterr "INCORRECT ARGS OF F!^"
else if n = m then 1
     else n*f!^(sub1 n,m)$

symbolic procedure factorial n$
f!^(n,0)$

symbolic procedure mk!-coeff1(alist,rlst)$
if null alist then 1
else
   eval ('times .
   for each x in alist collect factorial getroad(car x,rlst) )$

%--------------- CONTRACTION OF DELTA'S -----------------------------$

symbolic procedure prop!-simp(l1,l2)$
prop!-simp1(l1,l2,nil,0,1)$

symbolic procedure prop!-simp1(l1,l2,s,lngth,sgn)$
if null l2 then list(lngth,sgn) . (l1 . sreverse s)
else
 (lambda z$ if null z then
                          prop!-simp1(l1,cdr l2,car l2 . s,lngth,sgn)
            else prop!-simp1(cdr z,cdr l2,s,add1 lngth,
         (car z)*sgn*(-1)**(length s)) )
      prop!-simp2(l1,car l2)$

symbolic procedure prop!-simp2(l,ind)$
begin
  scalar sign$
if sign:=index!-in(ind,l) then
      return ((-1)**(length(l)-length(sign))) . delete(ind,l)
 else return nil
end$

symbolic procedure mk!-contract!-coeff u$
if caar u = 0 then 1
else
    begin
      scalar numr,denr,pk,k$
              pk:=caar u$
               k:=length cadr u$
              numr:=constimes ((cadar u) .mk!-numr(ndim!*,k,k+pk))$
       %      DENR:=F!^(PK+K, K)*(CADAR U)$
         return                numr
    end$

symbolic procedure mk!-numr(n,k,p)$
if k=p then nil
else (if k=0 then n else list('difference,n,k)) . mk!-numr(n,add1 k,p)$

symbolic procedure mod!-index(term,dump)$
%-------------------------------------------------------------------
% MODYFIES INDECES OF "DUMP" VIA DELTAS IN "TERM"
% DELETES UTILIZED DELTAS FROM "TERM"
% RETURNS "TERM" . "DUMP"
%------------------------------------------------------------------$
begin
  scalar coeff,sign$
      coeff:=list 1$
      term:= if sign:= eq(car term,'minus) then cdadr term
             else cdr term$
  while term do << if free car term       then
                                coeff:=(car term) . coeff
                   else dump:=mod!-dump(cdar term,dump)$
                   term:=cdr term                         >>$
  return
       ( if sign then
              if null cdr coeff then (-1)
              else 'minus . list(constimes coeff)
        else if null cdr coeff then 1
             else constimes coeff ) . dump
end$

symbolic procedure dpropagator(l1,l2,dump)$
(lambda z$
     if z=0       then z
     else if z=1 then nil . dump
          else  for each trm in cdr z collect
                             mod!-index(trm,dump) )
   propagator(l1,l2)$

symbolic procedure dvertex!-to!-projector(svert,rlst,dump)$
begin
  scalar l1,l2,coeff,w$
       l1:=mktails(cadr svert,rlst,dump)$
        if repeatsp car l1 then return 0$
       l2:= mktails(caddr svert,rlst,cdr l1)$
        if repeatsp car l2 then return 0$
       dump:=cdr l2$
       w:=prop!-simp(car l1,sreverse car l2)$
       coeff:=mk!-contract!-coeff w$
 return coeff . dpropagator(cadr w,cddr w,dump)
end$

%SYMBOLIC PROCEDURE DSTR!-TO!-ALG(STRAND,RLST,DUMP)$
%IF NULL STRAND THEN LIST('RECIP,MK!-COEFF1(DUMP,RLST))
%ELSE
%  BEGIN
%    SCALAR VRTX$
%      VRTX:=DVERTEX!-TO!-PROJECTOR(CAR STRAND,RLST,DUMP)$
%      IF 0=VRTX THEN RETURN 0$
%      IF NULL CADR VRTX THEN RETURN
%      LIST('TIMES,CAR VRTX,DSTR!-TO!-ALG(CDR STRAND,RLST,CDDR VRTX))$
%
% RETURN LIST('TIMES,CAR VRTX,
%        'PLUS . (FOR EACH TRM IN CDR VRTX COLLECT
%      LIST('TIMES,CAR TRM,DSTR!-TO!-ALG(CDR STRAND,RLST,CDR TRM))) )

%===MODYFIED 4.07.89

remflag('(dstr!-to!-alg),'lose)$

symbolic procedure dstr!-to!-alg(strand,rlst,dump)$
%IF NULL STRAND THEN LIST('RECIP,MK!-COEFF1(DUMP,RLST))
if null strand then consrecip list(mk!-coeff1(dump,rlst))
else
  begin
    scalar vrtx$
      vrtx:=dvertex!-to!-projector(car strand,rlst,dump)$
      if 0=vrtx then return 0$
      if null cadr vrtx then return
         if 1 = car(vrtx) then
                           dstr!-to!-alg(cdr strand,rlst,cddr vrtx)
         else
           cvitimes2(car vrtx,
                     dstr!-to!-alg(cdr strand,rlst,cddr vrtx))$


 return cvitimes2(car vrtx,
                  consplus (for each trm in cdr vrtx collect
      cvitimes2(car trm,dstr!-to!-alg(cdr strand,rlst,cdr trm))) )$
end$

flag('(dstr!-to!-alg),'lose)$

symbolic procedure cvitimes2(x,y)$
if (x=0) or (y=0) then 0
else if x = 1 then y
     else if y = 1 then x
          else list('times,x,y)$


symbolic procedure free dlt$
(freeind cadr dlt) and (freeind caddr dlt)$

symbolic procedure freeind ind$
atom ind $
%       AND
%LAGP(IND,'EXTRNL)$

symbolic procedure mod!-dump(l,dump)$
if not freeind car l then mod!-dump1(cadr l,car l,dump)
else mod!-dump1(car l,cadr l,dump)$

symbolic procedure mod!-dump1(new,old,dump)$
if null dump then nil
else ( (caar dump) . l!-subst(new,old,cdar dump) ) .
                    mod!-dump1(new,old,cdr dump)$

symbolic procedure l!-subst(new,old,l)$
if null l then nil
else if old = car l then new . l!-subst(new,old,cdr l)
     else car l . l!-subst(new,old,cdr l) $

endmodule$


%********************************************************************$
%                                                                    $
%   INTERFACE WITH RODIONOV!-FIERZING ROUTE.           17.02.88      $
%                                                                    $
%********************************************************************$

module interfierz$
  exports  calc!_map!_tar,calc!_den!_tar,pre!-calc!-map!_ $
  imports    mk!-numr,map!_!-to!-strand $

lisp$

%----------- DELETING VERTS WITH !_0'S ------------------------------$

%SYMBOLIC PROCEDURE SORT!-MAP!_(MAP!_,TADEPOLES,DELTAS,S)$
%IF NULL MAP!_ THEN LIST(S,TADEPOLES,DELTAS)
%ELSE
%  BEGIN
%     SCALAR VERT,EDGES$
%            VERT:=INCIDENT1('!_0,CAR MAP!_,'LL)$
%   RETURN
%       IF NULL VERT THEN SORT!-MAP!_(CDR MAP!_,TADEPOLES,DELTAS,
%                                                CAR MAP!_ . S)
%       ELSE IF CAR VERT = CADR VERT THEN
%                SORT!-MAP!_(CDR MAP!_,CAAR VERT . TADEPOLES,DELTAS,S)
%            ELSE SORT!-MAP!_(CDR MAP!_,TADEPOLES,LIST('CONS,CAAR VERT,
%                                    CAADR VERT) . DELTAS,S)
% END$
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% modified 17.09.90 A.Taranov %%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
symbolic procedure sort!-map!_(map!_,tadepoles,deltas,poles,s)$
% tadepoles are verts with 1 0!_ edge and contracted others
% deltas are verts with 1 0!_ edge
% poles are verts with at list 2 0!_ edges
if null map!_ then list(s,tadepoles,deltas,poles)
else
  begin
  scalar vert,tdp$
    vert:=incident1('!_0,car map!_,'ll)$
    if null vert then tdp:=tadepolep car map!_ 
    else %%%% vertex contain !_0 edge
      return 
        if (caar vert = '!_0) then
          sort!-map!_(cdr map!_,tadepoles,deltas,caadr vert . poles,s)
        else if (caadr vert = '!_0) then
             sort!-map!_(cdr map!_,tadepoles,deltas,caar vert . poles,s)
             else if car vert = cadr vert then
                    sort!-map!_(cdr map!_,caar vert . tadepoles,deltas,
                                poles,s)
                  else sort!-map!_(cdr map!_,tadepoles,list('cons,
                                   caar vert,caadr vert) . deltas,poles,
                                   s)$
   %%%%% here car Map!_  was checked to be a real tadpole               
   return                                
     if null tdp then sort!-map!_(cdr map!_,tadepoles,deltas,
                                        poles,car map!_ . s)
     else sort!-map!_(cdr map!_,cadr tdp . tadepoles,deltas,
                      caar tdp . poles,s)
 end$
 
symbolic procedure tadepolep vrt;   %%%%%% 17.09.90
% return edge1 . edge2 if vrt is tadpole,
% NIL otherwise. 
% edge1 correspond to 'pole', edge2 - to 'loop' of a tadpole.
if car vrt = cadr vrt then caddr vrt . car vrt
else if car vrt = caddr vrt then cadr vrt . car vrt
     else if cadr vrt = caddr vrt then car vrt . cadr vrt
          else nil;

symbolic procedure del!-tades(tades,edges)$
if null tades then edges
else del!-tades(cdr tades,delete(car tades,edges))$

symbolic procedure del!-deltas(deltas,edges)$
if null cdr deltas then edges
else del!-deltas(cdr deltas,del!-tades(cdar deltas,edges))$

%--------------- EVALUATING MAP!_S -----------------------------------$

symbolic procedure pre!-calc!-map!_(map!_,edges)$
% : (STRAND NEWMAP!_ TADEPOLES DELTAS)$
begin
  scalar strand, w$
         w:=sort!-map!_(map!_,nil,list 1,nil,nil)$
         
%        delete from edge list deltas, poles and tades
         edges:=del!-deltas(caddr w,
                    del!-tades(cadr w,delete('!_0,edges)))$
         strand:= if car w then map!_!-to!-strand(edges,car w)
                  else nil$
    return strand . w
end$


symbolic procedure calc!_map!_tar(gstrand,alst)$
% THIRD  VERSION.$
begin
 scalar poles,edges,strand,deltas,tades,map!_$
        strand:=car gstrand$
        map!_:=cadr gstrand$
        tades:=caddr gstrand     $
        deltas:=car cdddr gstrand $
        poles:= car cddddr gstrand $
 if ev!-poles(poles,alst) then   return 0;   %%%%% result is zero
 return constimes list(constimes deltas,
                      constimes ev!-tades(tades,alst),
                     (if null map!_ then 1
                      else strand!-alg!-top(strand,map!_,alst)))
end$

symbolic procedure ev!-poles(poles,alst)$ %%% 10.09.90
 if null poles then nil
 else if getedge(car poles,alst) = 0 then ev!-poles(cdr poles,alst)
      else poles$


symbolic procedure ev!-deltas(deltas)$
  if null deltas then list 1
  else ('cons . car deltas) . ev!-deltas(cdr deltas)$

symbolic procedure ev!-tades(tades,alst)$
  if null tades then list 1
  else binc(ndim!*,getedge(car tades,alst))
                                        . ev!-tades(cdr tades,alst)$

%------------------------ DENOMINATOR CALCULATION -------------------$

symbolic        procedure ev!-edgeloop(edge,alst)$
% EVALUATES LOOP OF 'EDGE' COLORED VIA 'ALST'$
binc(ndim!*,getedge(s!-edge!-name edge,alst) )$

symbolic procedure ev!-denom2(vert,alst)$
% EVALUATES DENOM FOR PROPAGATOR$
ev!-edgeloop(car vert,alst)$

symbolic procedure ev!-denom3(vert,alst)$
% EVALUATES DENOM FOR 3 - VERTEX$
begin
    scalar e1,e2,e3,lines,sign,!3j,numr$
    e1:=getedge(s!-edge!-name car vert,alst)$
    e2:=getedge(s!-edge!-name cadr vert,alst)$
    e3:=getedge(s!-edge!-name caddr vert,alst)$
    lines:=(e1+e2+e3)/2$
    e1:=lines-e1$
    e2:=lines-e2$
    e3:=lines-e3$
    sign:=(-1)**(e1*e2+e1*e3+e2*e3)$
    numr:=mk!-numr(ndim!*,0,lines)$
    numr:=(if numr then (constimes numr)
           else 1)$
    !3j:=listquotient(numr,
                   factorial(e1)*factorial(e2)*factorial(e3)*sign)$
 return !3j
end$

symbolic procedure binc(n,p)$
% BINOMIAL COEFF C(N,P)$
if 0 = p then 1 else
listquotient(constimes mk!-numr(n,0,p),factorial p)$

symbolic procedure calc!_den!_tar(den!_,alst)$
(lambda u$  if null u then 1
            else if null cdr u then car u
                 else constimes u           )
                                            denlist(den!_,alst)$

symbolic procedure denlist(den!_,alst)$
if null den!_ then nil
else if length car den!_ = 2 then
                   ev!-denom2(car den!_,alst) . denlist(cdr den!_,alst)
     else ev!-denom3(car den!_,alst) . denlist(cdr den!_,alst)$

endmodule$


module cvitmapping$

  exports calc!_spur$
  imports simp!*,reval,calc!_map!_tar ,calc!_den!_tar, spaces$

% SIMP!* AND REVAL REDUCE SYSTEM GENERAL FUNCTIONS FOR
% EVALUATING ALGEBRAIC EXPRESSIONS.

%*********************************************************************
%                                                                    *
%                        FOR CVITANOVIC GAMMA MATRICES               *
%                                CALCULATIONS                        *
%                                                                    *
%                                                                    *
%                       18.03.88  10.06.90  15.06.90 31.08.90        *
%                       01.09.90  11.09.90  14.09.90                 *
%********************************************************************$
 lisp$
 % 07.06.90 all MAP was replaced by MAP!_ 
 % 07.06.90 all DEN was replaced by DEN!_ 
 % 07.06.90 all PROP was replaced by PROP!_ 
 % SOME FUNCTIONS WAS MOVED TO SMACRO SECTION  08.06.90 10.06.90

%**********************************************************************
%                                                                     *
%                      _DATA_STRUCTURE                                *
%                                                                     *
%    WORLD::=(EDGELIST,VARIANTS,WORLD1)                               *
%    WORLD1::=(MAP!_2,COEFF,DEN!_OM)                                  *
%    MAP!_2::=(MAP!_S,VARIANTS,PLAN)                                  *
%    MAP!_S::=(EDGEPAIR . GSTRAND)                                    *
%    MAP!_1::=(EDGEPAIR . MAP!_)                                      *
%    EDGEPAIR::=(OLDEDGELIST . NEWEDGELIST)                           *
%    COEFF::=LIST OF WORLDS (UNORDERED)                               *
%    ATLAS::=(MAP!_,COEFF,DEN!_OM)                                    *
%    MAP!_::=LIST OF VERTECES (UNORDERED)                             *
%    VERTEX::=LIST OF EDGES (CYCLIC ORDER)                            *
%    VERTEX::=(NAME,PROP!_ERTY,TYPE)                                  *
%    NAME::=ATOM                                                      *
%    PROP!_ERTY::= (FIRSTPARENT . SECONDPARENT)                       *
%    TYPE::=T OR NIL                                                  *
%                                                                     *
%*********************************************************************$

%GGGGGGGGGGGGGGGGGGGGGGGGG GLOBALS & FLUIDS FFFFFFFFFFFFFFFFFFFFFFFFF$


 global '( !_0edge)$

 fluid '( new!_edge!_list old!_edge!_list )$

      % NEW!_EDGE!_LIST - LIST OF CREATED EDGES$
      % OLD!_EDGE!_LIST - LIST OF INITIAL EDGES$

 fluid '(n!_edge)$

      % N!_EDGE - NUMBER OF CREATED EDGES$

%========================== PREDICATES =============================$


symbolic procedure is!_indexp x$  % 01.09.90 RT
    (lambda z$
       z and cdr z)   
     assoc(s!_edge!_name x,dindices!*)$
     
symbolic procedure mk!_edge!_name (name1,name2)$
% GENERATE NEW EDGE NAME $
<< n!_edge := n!_edge +1$
%INTERN COMPRESS APPEND(MK!_NAME1 NAME1,
        compress append(mk!_name1 name1,
                        append ( mk!_name1 n!_edge ,
                                 mk!_name1 name2)) >> $

symbolic procedure new!_edge (fedge,sedge)$
% GENERATE NEW EDGE $
begin
 scalar s$
 s:=
 mk!_edge ( mk!_edge!_name ( s!_edge!_name fedge,
                             s!_edge!_name sedge),
            mk!_edge!_prop!_ ( s!_edge!_name fedge,
                             s!_edge!_name sedge),
            mk!_edge!_type ( nil,
                             nil))$
 %          MK!_EDGE!_TYPE ( S!_EDGE!_TYPE FEDGE,
 %                           S!_EDGE!_TYPE SEDGE))$
 new!_edge!_list := s . new!_edge!_list $
 return s
 end$

symbolic procedure delete!_vertex (vertex,map!_)$
%DELETS VERTEX FROM MAP!_$
if p!_empty!_map!_ map!_ then mk!_empty!_map!_ ()
else
  if p!_eq!_vertex (vertex,s!_vertex!_first map!_)
    then s!_map!_!_rest map!_
  else
    add!_vertex (s!_vertex!_first map!_,
                 delete!_vertex (vertex,s!_map!_!_rest map!_))$

%====================== PREDICATES (CONTINUE) =====================$

symbolic procedure p!_eq!_vertex (vertex1,vertex2)$
% VERTECES ARE EQ IF THEY HAVE EQUAL NUMBER OF EDGES
% IN THE SAME ORDER WITH EQUAL _NAMES $
if p!_empty!_vertex vertex1 then p!_empty!_vertex vertex2
else
 if p!_empty!_vertex vertex2 then nil
 else
   if equal!_edges (first!_edge vertex1,
                    first!_edge vertex2)
      then p!_eq!_vertex (s!_vertex!_rest vertex1,
                          s!_vertex!_rest vertex2)
   else nil$

%::::::::::::::::::::::: SOME ROUTINES :::::::::::::::::::::::::::::$

symbolic procedure mk!_old!_edge x$
 begin
  scalar s$
  s:=assoc(x,old!_edge!_list )$
  if s then return s$
  s:=mk!_edge ( x,
                if not gamma5p x
                   then  mk!_edge!_prop!_ (1,1)           %10.06.90 RT 
                else     mk!_edge!_prop!_ (ndim!*,ndim!*),
                mk!_edge!_type (t,t))$
 old!_edge!_list :=cons(s,old!_edge!_list )$
 return s
 end$

symbolic procedure change!_name (name,edge)$
% CHANGES EDGE'S NAME $
mk!_edge (name,
          s!_edge!_prop!_ edge,
          s!_edge!_type edge )$

%======================= PREDICATES (CONTINUE) ================== $

symbolic procedure is!_tadpole vertex$    %11.09.90 RT
% RETURNS T IF THERE IS ONLY ONE EXTERNAL LEG
    is!_tadpolen(vertex) < 2$

symbolic procedure is!_tadpolen vertex$    %11.09.90 RT
% RETURNS NUMBER OF EXTERNAL LEGS
  vertex!_length diff!_legs(vertex,mk!_empty!_vertex())$

symbolic procedure diff!_legs(vertex,vertex1)$  %11.09.90 RT
% RETURNS LIST OF EXTERNAL LEGS
  if p!_empty!_vertex vertex then vertex1 
  else  if p!_member!_edge(first!_edge vertex,
                          s!_vertex!_rest vertex)
                      or
           p!_member!_edge(first!_edge vertex,
                           vertex1)
           then diff!_legs(s!_vertex!_rest vertex,vertex1)
         else  diff!_legs(s!_vertex!_rest vertex,
                   add!_edge(first!_edge vertex,vertex1))$
    
  
symbolic procedure is!_buble (vertex1,vertex2)$
% RETURNS NIL IF VERTEX1 AND VERTEX2 DOES NOT FORMED A BUBLE,
% OR N . MAP!_ ,WHERE N IS A NUMBER OF EXTERNAL LINES ( 0 OR 2 ),
% MAP!_ IS A MAP!_ CONTAINING THIS BUBLE $
%NOT(IS!_TADPOLE VERTEX1) AND NOT(IS!_TADPOLE VERTEX2) AND  %14.09.90 RT
(lambda z$ if z >= 2 then nil
           else (2*z) . mk!_vertex2!_map!_ (vertex1,vertex2))
vertex!_length ( diff!_vertex (vertex1,vertex2))$

%^^^^^^^^^^^^^^^^^^^^^^^ MAIN PROGRAM ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$

symbolic procedure transform!_map!_ map!_$
% GENERATE SIMPLE MAP!_ (ONLY PRIMITIVE VERTECES) FROM INITIAL ONE$
begin
 scalar n!_edge$
 n!_edge := 0$
 new!_edge!_list :=nil$
 old!_edge!_list :=nil$
return
mk!_simple!_map!_
(for each vertex in map!_ collect
   prepare!_map!_ vertex)$
end$


%,,,,,,,,,,,,,,,,,,,,, RODIONOV & TARANOV INTERFACE ,,,,,,,,,,,,,,, $

global '(bubltr freemap!_)$

symbolic procedure to!_taranov map!_$
% MAP!_ IS INITIAL MAP!_,
% RETURNS (FULL LIST OF EDGES (INITIAL AND GENERATED) .
%         (MAP!_ OF PRIMITIVE VERTECES )  .
%         (LIST OF ALL POSSIBLE ENUMERATION OF MAP!_'S EDGES) $
begin
  scalar new!_edge!_list , old!_edge!_list , full!_edge!_list ,
         new!_map!_ , free!_map!_ , marks , variants , alst , bubles$
  new!_map!_ :=transform!_map!_ map!_$
  free!_map!_ :=find!_bubltr new!_map!_ $
  bubles:=car free!_map!_ $
  bubltr:=bubles $
  free!_map!_ := cdr free!_map!_ $
  freemap!_:=free!_map!_ $
  full!_edge!_list := for each edge in old!_edge!_list collect
                          s!_edge!_name edge $
  alst:=nconc(for each x in full!_edge!_list collect (x . 1) ,
              list('!_0 . 0) ) $                   %ADD EMPTY EDGE $
  marks:=set!_mark (new!_edge!_list ,
                    nil,
                    buble!_proves bubles,
                    new!_map!_ ,
                    add!_tadpoles (bubles,alst))$
 variants:=edge!_bind (marks,alst)$
  full!_edge!_list :=nconc (for each edge in new!_edge!_list collect
                                s!_edge!_name edge,
                            full!_edge!_list )$
return full!_edge!_list .
       new!_map!_ .
       variants
end$


 % TEST TEST TEST  TEST TEST TEST TEST TEST TEST TEST $
 % TO!_TARANOV '((A B C C B A)) $


%END$    %cvit2.red
%********************************************************************
%                     NOW WE MARKED THE MAP!_                         *
%*******************************************************************$

                  % 09.03.88  $
lisp$

global '(ndim!* )$

%ERROERRORERRORERRORERROR ERROR ROUTINES ERRORERRORERRORERRORERROR $

global '(!*cviterror)$

flag('(cviterror),'switch)$

!*cviterror:=t$           % IF T THEN ERROR MESSAGES WILL BE PRINTED$

fluid '(alst)$

symbolic fexpr procedure set!_error u$
if !*cviterror then set!_error0 (u,alst)
else
   error(55,"ERROR IN MAP!_ CREATING ROUTINES")  $

symbolic procedure set!_error0 (u,alst)$
<< prin2 "FUNCTION: "$
   prin2 car u$
   prin2 " ARGUMENTS: "$
   set!_error1(cdr u,alst)  >> $

symbolic procedure set!_error1(u,alst)$
<< if u then for each x in u do error2!_print (x,alst)$
   error(55,"ERROR IN MAP!_ CREATING ROUTINES") >> $

symbolic procedure error2!_print (x,alst)$
<< prin2 x$ prin2 " IS " $
   prin2 !%eval(x,alst)$
   terpri()  >> $

%ERERERERERERERERERERERERERERERERERERERERERERERERERERERERERERERERE$

symbolic procedure mark!_edges (newedges,oldedges,map!_)$
  mk!_proves (map!_,oldedges) .
  set!_mark (newedges,nil,nil,map!_,
             for each x in oldedges collect (s!_edge!_name x .
                                             car s!_edge!_prop!_ x ) ) $

symbolic procedure mk!_proves (map!_,oldedges)$
if p!_empty!_map!_ map!_ then nil
else
  if defined!_vertex (s!_vertex!_first map!_,oldedges) then
      s!_vertex!_first map!_ .
      mk!_proves (s!_map!_!_rest map!_,oldedges)
  else
      mk!_proves (s!_map!_!_rest map!_,oldedges)$

symbolic procedure defined!_vertex (vertex,oldedges)$
if p!_empty!_vertex vertex then t
else
 memq!_edgelist (first!_edge vertex,oldedges)
                and
 defined!_vertex (s!_vertex!_rest vertex,oldedges)$

symbolic procedure set!_mark (edges,notdef,toprove,map!_,blst)$
% EDGES - LIST OF NEW EDGES CREATED WHILE MAKING A MAP!_,
% NOTDEF - LIST OF EDGES WHICH CANNOT BE FULLY IDEN!_TIFY,
% TOPROVE - LIST OF VERTECES FOR CHECKING TRIANGLE RULE,
% MAP!_ - MAP!_ CREATED EARLIER,
% BLST - ALIST OF BINDED EDGES$
if null edges then
    if notdef or toprove then          % 15.06.90 RT
                 set!_error (set!_mark,edges,notdef,toprove,map!_,blst)
    else nil
else
  (lambda z$
      if z then                  %THE EDGE IS FULLY DEFINED$
         set!_prove (append(notdef,             %RESTOR LIST OF EDGES$
                            cdr edges),
                     car edges,
                     append(new!_prove (car edges,     %ADD CHECKS$
                                        map!_),
                            toprove),
                     map!_,
                     (s!_edge!_name car edges . 0) .
                     blst)
     else
         set!_mark (cdr edges,                   %TRY NEXT$
                    car edges . notdef,          % ADD NOT DEF. LIST$
                    toprove,
                    map!_,
                    blst))
    ( assoc(caadar edges,blst)          %CHECK IF BOTH PARENT IS $
             and                        %ALREADY DEFINED         $
      assoc(cdadar edges,blst) ) $

symbolic procedure new!_prove (edge,map!_)$
% RETURNS NEW VERTEX FOR TRIANGLE RULE CHECKING LIST$
if null map!_ then nil
else
  (lambda z$  if z then list z
              else new!_prove (edge,cdr map!_))
   new!_provev (edge,car map!_) $

 symbolic procedure new!_provev (edge,vertex)$
 % CAN THIS VERTEX BE UTILIZED FOR CHECKING ? $
 if not member(edge,vertex) then nil
 else
  if (assoc(caadr edge,vertex)
           and
      assoc(cdadr edge,vertex))
    then nil
  else vertex $

symbolic procedure is!_son (edge,vertex)$
 assoc(car s!_edge!_prop!_ edge,vertex)$

symbolic procedure not!_parents (edge,proves)$
if null proves then nil
else
  if is!_son (edge,car proves)
     then cdr proves
  else car proves . not!_parents (edge,cdr proves)$

symbolic procedure set!_prove (edges,edge,toprove,map!_,blst)$
% RETURNS A PAIR (EDGE . (LIST FOF VERICES FOR TRIANGLE RULE TEST))$
(lambda z$
   (edge . not!_parents (edge,car z)) .
    set!_mark (edges,nil,cdr z,map!_,blst))
  find!_proved (toprove,nil,nil,blst)$

symbolic procedure find!_proved (toprove,proved,unproved,blst)$
% RETURNS A PAIR ((LIST OF ALREADY DEFINED VERTECES) .
%                 (LIST OF NOT YET DEFINED EDGES) ) $
if null toprove then proved . unproved
else
  if is!_proved (car toprove,blst) then
                   find!_proved (cdr toprove,
                                 car toprove . proved,
                                  unproved,
                                  blst)
  else             find!_proved (cdr toprove,
                                 proved,
                                 car toprove . unproved,
                                 blst) $

symbolic procedure is!_proved (vertex,blst)$
 if null vertex then t
 else if assoc(caar vertex,blst) then is!_proved (cdr vertex,blst)
      else nil $

%@@@@@@@@@@@@@@@@@@@@@@@ NOW GENERATES ALL POSSIBLE NUMBERS @@@@@@@@$

symbolic procedure mk!_binding (provedge,blst)$
 can!_be!_proved (car provedge,blst)
             and
 edge!_bind (cdr provedge,blst)$

symbolic procedure edge!_bind (edgelist,blst)$
if null edgelist then list blst
else
 begin
   scalar defedge,prop!_,p,emin,emax,s,proves,i$
% DEFEDGE - EDGE WITH DEFINED RANG,
% PROP!_ - ITS PROP!_ERTY: (NUM1 . NUM2),
% P - ITS NAME,
% EMIN AND EMAX - RANGE OF P,
% S - TO STORE RESULTS,
% PROVES - CHECKS OF TRIANGLE LAW$
  defedge:=car edgelist$
  proves:=cdr defedge$
  defedge:=car defedge$
  edgelist:=cdr edgelist$
  p:=s!_edge!_name defedge$
  prop!_:=s!_edge!_prop!_ defedge$
  emin:=assoc(car prop!_,blst)$
  emax:=assoc(cdr prop!_,blst)$
 if null emin or null emax then set!_error ('edge!_bind, prop!_,
                                             blst)$
 prop!_:=(cdr emin) . (cdr emax)$
  emin:=abs((car prop!_)-(cdr prop!_))$
  emax:=(car prop!_)+(cdr prop!_)$
 if numberp ndim!* then              %NUMERACAL DIMENTIONAL$
    << emax:=min(emax,ndim!*)$
       if emin > ndim!* then return nil >> $
 i:=emin$
loop:
       if i > emax then return s$
       if can!_be!_proved (proves,(p . i) . blst)
         then s:=append(edge!_bind (edgelist,
                                    (p . i) . blst),
                        s) $
       i:=i+2$
 go loop
end$

symbolic procedure can!_be!_proved (proves,blst)$
if null proves then t
else if can!_be!_p (car proves,blst) then
        can!_be!_proved (cdr proves,blst)
     else nil$

symbolic procedure can!_be!_p (vertex,blst)$
%CHECKS TRIANGLE RULE$
begin
  scalar i,j,k$
  i:=assoc(car car   vertex,blst)$
  j:=assoc(car cadr  vertex,blst)$
  k:=assoc(car caddr vertex,blst)$
  if null i or null j or null k then set!_error ('can!_be!_proved,
                                                  edge,blst)$
  i:=cdr i$
  j:=cdr j$
  k:=cdr k$
  if numberp ndim!* and (i+j+k) > (2*ndim!*) then
    return nil $                           %SINCE S+T+U<NDIM!* $
 % ======== NOW CHECK TRIANGLE RULE ======= $
  return
        if not evenp(i+j+k) or
           k < abs(i-j)     or
           k > (i+j)
         then nil
        else t
end$

%END$  %cvit4.red
%OOOOOOOOOOOOOOOOOOOOOOOOO ROUTINES TO SELECT BUBLES OOOOOOOOOOOOOOOO$

lisp$                                   %24.05.88$

symbolic procedure find!_bubles atlas$
 find!_bubles1 (atlas,old!_edge!_list )$

symbolic procedure find!_bubles!_coeff (atlaslist,edgelist,bubles)$
%F NULL BUBLES THEN NIL . ATLASLIST
%LSE
 find!_bubles1!_coeff (atlaslist,nil,edgelist,bubles)$

symbolic procedure find!_bubles1!_coeff (atlaslist,passed,edgelist,
                                                          bubles)$
if null atlaslist then bubles . passed
else
 (lambda z$             %Z - PAIR = (BUBLES . REDUCED MAP!_)
    find!_bubles1!_coeff (cdr atlaslist,
                          cdr z . passed,
                          edgelist,
                          if null car z then bubles else
                          car z . bubles) )
  find!_bubles1 (car atlaslist,edgelist) $

symbolic procedure mk!_atlaslist (map!_,coeff,den!_om)$
 list mk!_atlas (map!_,coeff,den!_om)$

symbolic procedure find!_bubles1 (atlas,edgelist)$
  select!_bubles (nil,
                  s!_atlas!_map!_ atlas,
                  nil,
                  s!_atlas!_coeff atlas,
                  s!_atlas!_den!_om atlas,
                  edgelist)$

symbolic procedure select!_bubles(bubles,map!_,passed,coeff,den!_om,al)$
% RETURNS (LIST OF BUBLES ) . ATLAS,
% WHERE BUBLES ARE TWO OR ONE VERTECES MAP!_S $
if p!_empty!_map!_  map!_ then
             (lambda x$
                     car x .
                           mk!_atlas (passed,cdr x,den!_om))
              find!_bubles!_coeff (coeff,
                                   union!_edges (map!_!_edges passed,
                                                 al),
                                   bubles)
else
 if (map!_!_length map!_ + map!_!_length passed) < 3 then
         select!_bubles (bubles,
                         mk!_empty!_map!_ (),
                         append!_map!_s(map!_,
                                      passed),
                         coeff,
                         den!_om,
                         al)
 else
  (lambda z$                          % Z IS NIL OR A PAIR
                                      % N . MAP!_ , WHERE
                                      % N - NUMBER OF FREE EDGES$
     if z then                                      %A BUBLE IS FIND$
      (lambda d$
       (lambda bool$              %BOOL=T IFF ALL EDGES CAN BE DEFINED$
      if car z = 0 then                             %NO EXTERNAL LINES$
       if bool then
        select!_bubles ( z . bubles,
                         mk!_empty!_map!_ (),
                         cdr z,
                         mk!_atlaslist ( conc!_map!_s (passed,
                                                    delete!_vertex (
                                                      s!_vertex!_second
                                                                cdr z,
                                                      s!_map!_!_rest
                                                                map!_)),
                                         coeff,
                                         den!_om),
                         nil,
                         al)
       else
        select!_bubles ( z . bubles,                %ADD BUBLE$
                         delete!_vertex (s!_vertex!_second cdr z,
                                         s!_map!_!_rest map!_),
                         passed,
                         try!_sub!_atlas (mk!_atlas (cdr z,
                                                     nil,
                                                     nil),
                                          coeff),
                         den!_om,
                         al)
      else
       if not p!_old!_vertex d then
        if bool then
        select!_bubles (z . bubles,
                        mk!_empty!_map!_ (),
                        cdr z,
                        mk!_atlaslist (conc!_map!_s (passed,
                                                   buble!_vertex (
                                                     cdr z,
                                                     delete!_vertex (
                                                      s!_vertex!_second
                                                         cdr z,
                                                      s!_map!_!_rest
                                                         map!_ ),
                                                      al)),
                                        coeff,
                                        den!_om),
                         list d,
                         al)
        else
        select!_bubles ( z . bubles,                %ADD NEW BUBLE$
                         buble!_vertex (cdr z,      %RENAME EDGES $
                             conc!_map!_s (passed,
                             delete!_vertex (s!_vertex!_second
                                                cdr z,
                                             s!_map!_!_rest map!_)),
                                        al),
                         mk!_empty!_map!_ (),
                         try!_sub!_atlas (mk!_atlas (cdr z,
                                                     nil,
                                                     list d),
                                          coeff),
                         den!_om,
                         al)
       else
        if bool then
        select!_bubles (z . bubles,
                        mk!_empty!_map!_ (),
                        ren!_vertmap!_ (d,cdr z),
                        mk!_atlaslist (
                          conc!_map!_s (
                            passed,
                            add!_vertex (add!_edge (!_0edge ,d),
                                         delete!_vertex (
                                            s!_vertex!_second cdr z,
                                            s!_map!_!_rest map!_ ))),
                          coeff,
                          den!_om),
                        list ren!_verteces (d,d),
                        al)
        else
        select!_bubles (z . bubles,
                        add!_vertex (add!_edge (!_0edge ,d),
                                     delete!_vertex (s!_vertex!_second
                                                      cdr z,
                                                   s!_map!_!_rest map!_)
                                    ),
                        passed,
                        try!_sub!_atlas (mk!_atlas (ren_vertmap!_
                                                    (d,cdr z),
                                                    nil,
                                                    list
                                                     ren!_verteces
                                                          (d,d)
                                                    ),
                                         coeff),
                        den!_om,
                        al )
                                     )
   %      ALL!_DEFINED (CDR Z,AL))
          t                           )
        delta!_edges cdr z
     else
        select!_bubles (bubles,
                        s!_map!_!_rest map!_,
                        add!_vertex (s!_vertex!_first map!_,
                                     passed),
                        coeff,
                        den!_om,
                        al )
                                )
   find!_buble (s!_vertex!_first map!_,
                s!_map!_!_rest map!_ ) $

symbolic procedure p!_old!_vertex vertex$
% RETURNS T IFF ALL EDGES OF VERTEX ARE OLD OR VERTEX IS EMPTY ONE$
if p!_empty!_vertex vertex then t
else p!_old!_edge first!_edge vertex
             and
     p!_old!_vertex s!_vertex!_rest vertex$

symbolic procedure renames!_edges (vertex,al)$
rename!_edges!_par (first!_edge vertex,
                    second!_edge vertex,
                    al)$

symbolic procedure rename!_edges!_par (vertex1,vertex2,al)$
% Here VERTEX1 and VERTEX2 are edges!
if   defined!_edge (vertex1,al)
     and not p!_old!_edge(vertex2)  then        % 14.09.90 RT
       replace!_edge (vertex2,vertex1,new!_edge!_list )
else
  if defined!_edge (vertex2,al) 
     and not p!_old!_edge(vertex1)  then        % 14.09.90 RT
       replace!_edge (vertex1,vertex2,new!_edge!_list )
  else
    if  p!_old!_edge (vertex1)
        and not p!_old!_edge(vertex2)  then        % 14.09.90 RT
         replace!_edge (vertex2,vertex1,new!_edge!_list )
    else
      if p!_old!_edge (vertex2) 
         and not p!_old!_edge(vertex1)  then        % 14.09.90 RT
          replace!_edge (vertex1,vertex2,new!_edge!_list )
      else rename!_edges (vertex1,vertex2)$

symbolic procedure buble!_vertex (map!_2,map!_,al)$
if p!_empty!_map!_ map!_2 then mk!_empty!_map!_ ()
else
  << renames!_edges (delta!_edges map!_2,al)$
     map!_ >> $

symbolic procedure delta!_edges map!_2$
% MAP!_2 - MAP!_ OF TWO VERTICES $
mk!_edge2!_vertex (
                   first!_edge
                               diff!_vertex (s!_vertex!_first map!_2,
                                             s!_vertex!_second map!_2),
                   first!_edge
                               diff!_vertex (s!_vertex!_second map!_2,
                                             s!_vertex!_first map!_2 )
                  )$

symbolic procedure delta!_names map!_2$
% MAP!_2 - MAP!_ OF TWO VERTICES $
(lambda z$
     s!_edge!_name first!_edge car z .
     s!_edge!_name first!_edge cdr z  )
 (diff!_vertex (s!_vertex!_first map!_2,
                s!_vertex!_second map!_2) .
  diff!_vertex (s!_vertex!_second map!_2,
                s!_vertex!_first map!_2) ) $

symbolic procedure old!_rename!_edges (names,map!_)$
if p!_empty!_map!_ map!_ then mk!_empty!_map!_ ()
else add!_vertex (ren!_edge (names,s!_vertex!_first map!_),
                  old!_rename!_edges (names,
                                 s!_map!_!_rest map!_) ) $

symbolic procedure ren!_vertmap!_ (vertex1,map!_)$
% VERTEX1 MUST BE TWO EDGE VERTEX,
% EDGES OF VERTEX2 TO BE RENAME$
if vertex!_length vertex1 neq 2 then set!_error (ren!_vertmap!_  ,
                                                 vertex1,map!_)
else old!_rename!_edges (s!_edge!_name first!_edge vertex1 .
                         s!_edge!_name second!_edge vertex1,
                         map!_)$

symbolic procedure ren!_verteces (vertex1,vertex2)$
% VERTEX1 MUST BE TWO EDGE VERTEX,
% EDGES OF VERTEX2 TO BE RENAME$
if vertex!_length vertex1 neq 2 then set!_error (ren!_verteces ,
                                                 vertex1,vertex2)
else ren!_edge (s!_edge!_name first!_edge vertex1 .
                s!_edge!_name second!_edge vertex1,
                vertex2)$

symbolic procedure ren!_edge (names,vertex)$
% NAMES IS NAME1 . NAME2,
% CHANGE NAME1 TO NAME2$
if null assoc(car names,vertex) then vertex  %NO SUCH EDGES IN VERTEX$
else ren!_edge1 (names,vertex)$

symbolic procedure ren!_edge1 (names,vertex)$
if p!_empty!_vertex vertex then mk!_empty!_vertex ()
else if car names =s!_edge!_name first!_edge vertex then
        add!_edge ( change!_name (cdr names,first!_edge vertex),
                    ren!_edge1 (names ,
                               s!_vertex!_rest vertex))
     else
        add!_edge ( first!_edge vertex,
                    ren!_edge1 (names ,
                               s!_vertex!_rest vertex))$

symbolic procedure find!_buble (vertex,map!_)$
if p!_empty!_map!_ map!_ then mk!_empty!_map!_ ()
else
  is!_buble (vertex,s!_vertex!_first map!_)
  or
  find!_buble (vertex, s!_map!_!_rest map!_) $

symbolic procedure diff!_vertex (vertex1,vertex2)$
if p!_empty!_vertex vertex1 then mk!_empty!_vertex ()
else
  if p!_member!_edge (first!_edge vertex1,vertex2)
                     and
      not equal!_edges (first!_edge vertex1,!_0edge )
     then diff!_vertex (s!_vertex!_rest vertex1,vertex2)
  else
    add!_edge (first!_edge vertex1,
               diff!_vertex (s!_vertex!_rest vertex1,vertex2)) $

%SSSSSSSSSSSSSSSSSSSSSSSSSS NOW MAKES PROVES FROM BUBLE PPPPPPPPPPPPPP$

global '(!_0edge )$

!_0edge :=mk!_edge ('!_0 ,
                     mk!_edge!_prop!_ (0,0),
                     mk!_edge!_type (t,t)) $

symbolic procedure buble!_proves bubles$
if null bubles then nil
else
  if caar bubles = 0                           %NO EXTERNAL LINES $
    then buble!_proves cdr bubles
  else if caar bubles = 2 then
       mk!_edge3!_vertex (
                          first!_edge diff!_vertex (
                                      s!_vertex!_first cdar bubles,
                                      s!_vertex!_second cdar bubles),
                          first!_edge diff!_vertex (
                                      s!_vertex!_second cdar bubles,
                                      s!_vertex!_first cdar bubles),
                          !_0edge ) .
                                      buble!_proves cdr bubles
        else
         if caar bubles = 3 then
               car cdar bubles .
                                 buble!_proves cdr bubles
         else buble!_proves cdr bubles $


symbolic procedure try!_sub!_atlas (atlas,atlaslist)$
if null atlaslist then list atlas
else
  if sub!_map!_!_p (s!_atlas!_map!_ atlas,
                  s!_atlas!_den!_om car atlaslist)
   then try!_sub!_atlas (mk!_sub!_atlas (atlas,
                                         car atlaslist),
%  THEN TRY!_SUB!_ATLAS (MK!_SUB!_ATLAS (CAR ATLASLIST,
%                                        ATLAS        ),
                         cdr atlaslist)
  else  car atlaslist .
        try!_sub!_atlas (atlas,
                         cdr atlaslist)$

symbolic procedure sub!_map!_!_p (map!_1,den!_)$
%MAP!_1 AND DEN!_  HAVE COMMON VERTEX (DEN!_ - DEN!_OMINATOR)$
if p!_empty!_map!_ map!_1 then nil
else  sub!_vertex!_map!_ (s!_vertex!_first map!_1,den!_)
                    or
      sub!_map!_!_p (s!_map!_!_rest map!_1,den!_)$

symbolic procedure sub!_vertex!_map!_ (vertex,den!_)$
if null den!_ then nil
else p!_common!_den!_ (vertex,car den!_)
                  or
     sub!_vertex!_map!_ (vertex,cdr den!_)$

symbolic procedure  p!_common!_den!_ (vertex,vertexd)$
(lambda n$
    if n = 3 then                                %TRIANGLE
             p!_eq!_vertex (vertex,vertexd)

    else
      if n = 2 then                              %KRONEKER
             p!_member!_edge (first!_edge vertexd,vertex)
      else nil )
  vertex!_length vertexd $

symbolic procedure mk!_sub!_atlas (atlas1,atlas2)$
 mk!_atlas (s!_atlas!_map!_ atlas1,
            atlas2 . s!_atlas!_coeff atlas1,
            s!_atlas!_den!_om atlas1)$

symbolic procedure all!_defined (map!_,al)$
 all!_defined!_map!_ (map!_,
                    defined!_append(map!_!_edges map!_,al))$

symbolic procedure all!_defined!_map!_ (map!_,al)$
 al1!_defined!_map!_ (map!_,mk!_empty!_map!_ (),al)$

symbolic procedure al1!_defined!_map!_ (map!_,passed,al)$
% T IF ALL EDGES IN MAP!_ CAN BE DEFINED $
if p!_empty!_map!_ map!_ then
 if p!_empty!_map!_ passed then t
 else nil
else
 if all!_defined!_vertex (s!_vertex!_first map!_,al)
                    then
     al1!_defined!_map!_ (conc!_map!_s(passed,s!_map!_!_rest map!_),
                        mk!_empty!_map!_ (),
                        append(vertex!_edges s!_vertex!_first map!_ ,
                               al))
 else
     al1!_defined!_map!_ (s!_map!_!_rest map!_,
                        add!_vertex (s!_vertex!_first map!_,passed),
                        al)$

symbolic procedure all!_defined!_vertex (vertex,al)$
 al1!_defined!_vertex (vertex,mk!_empty!_vertex (),
                              mk!_empty!_vertex (),al)$

symbolic procedure al1!_defined!_vertex (vertex,passed,defined,al)$
% T IF ALL EDGES IN VERTEX CAN BE DEFINED $
if p!_empty!_vertex vertex then
 if p!_empty!_vertex passed then t
 else re!_parents (passed,defined)
else
  if defined!_edge (first!_edge vertex,al)
                    then
     al1!_defined!_vertex (conc!_vertex(passed,s!_vertex!_rest vertex),
                           mk!_empty!_vertex (),
                           add!_edge (first!_edge vertex,defined),
                           first!_edge vertex . al)
  else
     al1!_defined!_vertex (s!_vertex!_rest vertex,
                           add!_vertex (first!_edge vertex,passed),
                           defined,
                           al)$

symbolic procedure re!_parents (passed,defined)$
%TRY TO MAKE NEW PARENTS
if vertex!_length passed = 1 and vertex!_length defined = 2
  then make!_new!_parents (first!_edge passed,defined)
else nil$

symbolic procedure make!_new!_parents (edge,vertex)$
%VERTEX CONSITS OF TWO EDGES
 add!_parents0 (edge,
                s!_edge!_name first!_edge vertex .
                s!_edge!_name second!_edge vertex ,
                t)$


%^.^.^.^.^.^.^.^.^.^.^.^.^.^.^..^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^
%          13.05.88


symbolic procedure p!_def!_edge edge$
 s!_edge!_type edge$
%P!_OLD!_EDGE EDGE$

symbolic procedure defined!_edge (edge,al)$
  p!_old!_edge edge
      or
 defined!_all!_edge (all!_edge (s!_edge!_name edge,new!_edge!_list ),
                     nil,
                     al) $

symbolic procedure all!_edge (edgename,edgelist)$
if null edgelist then nil
else
  if edgename eq s!_edge!_name car edgelist then
                 car edgelist . all!_edge (edgename,cdr edgelist)
  else all!_edge (edgename,cdr edgelist)$

symbolic procedure def!_edge (edge,al)$
(lambda z$
          assoc(car z,al) and assoc(cdr z,al))
 s!_edge!_prop!_ edge$

symbolic procedure defined!_all!_edge (edgelist,passed,al)$
if null edgelist then nil
else
  if def!_edge (car edgelist,al) then
    if p!_def!_edge car edgelist then t  %REPLACE WAS ALREADY DONE
    else  rep!_edge!_prop!_ (nconc(passed,edgelist),
                           s!_edge!_prop!_ car edgelist . list t)
  else defined!_all!_edge (cdr edgelist,
                           car edgelist . passed,
                           al)$

symbolic procedure rep!_edge!_prop!_ (edgelist,prop!_)$
if null edgelist then t
else << rplacd(car edgelist,prop!_)$           %CHANGE EDGE PARENTS
        rep!_edge!_prop!_ (cdr edgelist,prop!_) >> $



%END$  %cvit6.red
%<><><><><><><><><><><> ROUTINES FOR SELECTING TRIANGLES <><><><><><>$
                            %24.05.88$

global '(!*cvitbtr !*cviterror)$

flag('(cvitbtr),'switch)$

!*cvitbtr:=t$           %IF T THEN BUBLES AND TRIANGLES  WILL BE
                        %     FACTORIZED

!*cviterror:=t$         %IF T THEN ERROR MESSAGES WILL BE PRINTED

symbolic procedure find!_triangles atlas$
 find!_triangles1 (atlas,old!_edge!_list)$

symbolic procedure find!_triangles1 (atlas,al)$
 select!_triangles (nil,
                    s!_atlas!_map!_ atlas,
                    nil,
                    s!_atlas!_coeff atlas,
                    s!_atlas!_den!_om atlas,
                    al)$

symbolic procedure find!_triangl!_coeff (atlaslist,edgelist,triangles)$
 find!_triangle!_coeff (atlaslist,nil,edgelist,triangles)$

symbolic procedure find!_triangle!_coeff(atlaslist,passed,edgelist,
                                         triangles)$
if null atlaslist then triangles . passed
else
 (lambda z$                 % Z - PAIR= (TRIANGLES . REDUCED MAP!_)
     find!_triangle!_coeff (cdr atlaslist,
                            cdr z . passed,
                            edgelist,
                            if null car z then triangles
                            else car z . triangles))
  find!_triangles1 (car atlaslist,edgelist)$

symbolic procedure select!_triangles (triangles,map!_,passed,
                                      coeff,den!_om,al)$
%RETURNS A PAIR OF THE FORM ( (LIST OF TRIANGLES) . (ATL.WITHOUT TR.))$
if p!_empty!_map!_ map!_ then                       %No triangles found.
      (lambda x$
              car x .
              mk!_atlas (passed,cdr x,den!_om))
      find!_triangl!_coeff (coeff,
                            union!_edges (map!_!_edges passed,
                                          al),
                            triangles)
else
 if (map!_!_length map!_ + map!_!_length passed) < 4 then
    select!_triangles (triangles,
                       mk!_empty!_map!_ (),
                       append!_map!_s (map!_,
                                     passed),
                       coeff,
                       den!_om,
                       al)
 else
 (lambda z$
    if z then                                    %TRIANGLE IS FOUND$
     (lambda trn$                                %TRN - NEW VERTEX $
     %IF ALL!_DEFINED (CDDR Z,AL) THEN
      if t then
         select!_triangles (
             z . triangles,
             mk!_empty!_map!_ (),
             add!_vertex (trn,cddr z),
             mk!_atlaslist (
                  conc!_map!_s (
                      mk!_vertex1!_map!_  trn,
                      conc!_map!_s (passed,
                                  delete!_map!_s (cddr z,map!_)
                                 )
                             ),
                  coeff,
%                 TRN . DEN!_OM    ),
                  den!_om    ),
%            NIL,
             list trn,
             al             )
       else
       select!_triangles ( z . triangles,        %ADD NEW TRIANGLE $
 %     SELECT!_TRIANGLES ( CDDR Z . TRIANGLES,   %ADD NEW TRIANGLE$
                           conc!_map!_s (mk!_vertex1!_map!_
                                       trn,      %ADD NEW VERTEX$
                                         conc!_map!_s (passed,
                                                     delete!_map!_s (
                                                             cddr z,
                                                             map!_  )
                                                    )
                                      ),
                          mk!_empty!_map!_ (),
                          try!_sub!_atlas (
                              mk!_atlas (add!_vertex (trn,cddr z),
                                         nil,
                                         list trn),
                              coeff       ),
                          den!_om,
                          al
                         )
                   )
      sk!_vertextr z
    else
       select!_triangles (triangles,
                          s!_map!_!_rest map!_,
                          add!_vertex (s!_vertex!_first map!_,passed),
                          coeff,
                          den!_om,
                          al
                         ) )
reduce!_triangle
 find!_triangle (s!_vertex!_first map!_,
                 s!_map!_!_rest map!_) $

symbolic procedure vertex!_neighbour (vertex,map!_)$
%RETURNS A MAP!_ OF VERTEX NEIGHBOURS $
if p!_empty!_vertex vertex
           or
   p!_empty!_map!_ map!_ then mk!_empty!_map!_ ()
else
  (lambda z$             %Z - NIL OR A PAIR (EDGE . ADJACENT EDGE )$
     if z then
        add!_vertex (cdr z,
                     vertex!_neighbour (delete!_edge (car z,vertex),
                                        delete!_vertex (cdr z,map!_)))
     else
        vertex!_neighbour (vertex,
                           s!_map!_!_rest map!_))
   is!_neighbour (vertex,
                  s!_vertex!_first map!_)$

symbolic procedure delete!_map!_s (map!_1,map!_2)$
if p!_empty!_map!_ map!_1 then map!_2
else delete!_map!_s (s!_map!_!_rest map!_1,
                   delete!_vertex (s!_vertex!_first map!_1,
                                   map!_2) ) $

symbolic procedure delete!_edge (edge,vertex)$
%DELETES EDGE FROM VERTEX $
if p!_empty!_vertex vertex then mk!_empty!_vertex ()
else
  if equal!_edges (edge,first!_edge vertex)
   then s!_vertex!_rest vertex
  else
    add!_edge (first!_edge vertex,
               delete!_edge (edge,
                             s!_vertex!_rest vertex ) ) $

symbolic procedure is!_neighbourp (vertex1,vertex2)$
% ARE VERTEX1 AND VERTEX2 NEIGHBOURS ?
if p!_empty!_vertex vertex1 then nil         % NIL IF NOT NEIGHBOURS$
else
     p!_member!_edge (first!_edge vertex1,vertex2)
                    or
     is!_neighbourp (s!_vertex!_rest vertex1,vertex2)$

symbolic procedure is!_neighbour (vertex1,vertex2)$
% ARE VERTEX1 AND VERTEX2 NEIGHBOURS ?
% IF THEY ARE THEN RETURN A PAIR: (ADJ.EDGE . VERTEX2)$
if p!_empty!_vertex vertex1 then nil         % NIL IF NOT NEIGHBOURS$
else
  (lambda z$
     if z then                   %FIRTS VERTEX IS ADJACENT TO VERTEX2$
          first!_edge vertex1 . vertex2
     else is!_neighbour (s!_vertex!_rest vertex1,
                         vertex2 ) )
   p!_member!_edge (first!_edge vertex1,
                    vertex2)$

symbolic procedure find!_triangle (vertex,map!_)$
%FINDS TRIANGLE WICH INCLUDES THE VERTEX.
%RETURNS MAP!_ OF THREE VERTECES (TRIANGLE) OR NIL $
(lambda z$               %Z - MAP!_ OF VERTECES WICH ARE NEIGHBOURS
                         %  OF VERTEX OR (IF NO NEIGHBOURS) EMPTY MAP!_$
   if map!_!_length z neq 2 then nil
   else add!_vertex (vertex,z) )
 is!_closed vertex!_neighbour (vertex,map!_)$

symbolic procedure is!_closed map!_$
if p!_empty!_map!_ map!_   or
   p!_empty!_map!_ s!_map!_!_rest map!_ then mk!_empty!_map!_ ()
else
    two!_neighbour (s!_vertex!_first map!_,
                    s!_map!_!_rest map!_)
             or
    is!_closed s!_map!_!_rest map!_$

symbolic procedure two!_neighbour (vertex,map!_)$
% HAS VERTEX A NEIGHBOUR IN THE MAP!_ ? $
if p!_empty!_map!_ map!_ then nil
else
 if is!_neighbourp (vertex,s!_vertex!_first map!_)
    then mk!_vertex2!_map!_ (vertex,s!_vertex!_first map!_)
 else two!_neighbour (vertex, s!_map!_!_rest map!_)$

symbolic procedure mk!_vertextr map!_$
%MAKES VERTEX FROM TRIANGLE MAP!_$
if map!_!_length map!_ neq 3 then set!_error ('mk!_vertextr ,map!_)
else
    mk!_vertextr3 (map!_,3)$

symbolic procedure add!_edge1(edge,vertex)$ % 14.09.90 RT
 if null edge then vertex
 else add!_edge(edge,vertex)$

symbolic procedure mk!_vertextr3 (map!_,n)$
if n <= 0 then mk!_empty!_map!_ ()
else
  add!_edge1 (take!_edge (s!_vertex!_first map!_,
                         s!_map!_!_rest map!_),
             mk!_vertextr3 (cycl!_map!_ map!_,n-1)) $

symbolic procedure take!_edge (vertex,map!_)$
if p!_empty!_vertex vertex then nil    %14.09.90 RT
% SET!_ERROR ('TAKE!_EDGE ,VERTEX,MAP!_)    % 14.09.90  RT
else
%  IF P!_EMPTY!_VERTEX S!_VERTEX!_REST VERTEX THEN FIRST!_EDGE VERTEX
%  ELSE                                     % 14.09.90 RT
    if contain!_edge (first!_edge vertex,map!_)
                 and
       not equal!_edges (first!_edge vertex,!_0edge )
     then take!_edge (s!_vertex!_rest vertex,map!_)
    else first!_edge vertex$

symbolic procedure contain!_edge (edge,map!_)$
% IS THERE A VERTEX IN THE MAP!_ CONTAINING THE EDGE? $
if p!_empty!_map!_ map!_ then nil
else
    p!_member!_edge (edge,s!_vertex!_first map!_)
                    or
    contain!_edge (edge,s!_map!_!_rest map!_) $

% ,,,,,,,,,,,,,,,,,,,,,,,,,,,, SORTING AFTER FACTORIZATION ,,,,,,,,,,,$
%      19.05.88 $

symbolic procedure find!_bubltr atlas$
if null !*cvitbtr then atlas else
begin
 scalar s$
 s:=errorset(list('find!_bubltr0 ,mkquote atlas),
             !*cviterror,
             !*backtrace)$
 return
     if atom s then atlas
     else car s
 end$

symbolic procedure find!_bubltr0 atlas$
%(LAMBDA Z$
%    IF CAR Z THEN  SORT!_ATLAS CDR Z  %FACTORIZATION HAPPENED
%    ELSE CDR Z)
 sort!_atlas cdr
  find!_bubltr1 (atlas,old!_edge!_list )$

% ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, $

symbolic procedure find!_bubltr1 (atlas,al)$
%FINDS BOTH BUBLES AND TRIANGLES IN ATLAS$
begin
 scalar s,c,bubles$
 s:=find!_bubles1 (atlas,al)$
 c:=car s$
 atlas:=cdr s$
 bubles:=append(c,bubles)$
loop:
 s:=find!_triangles1 (atlas,al)$
 c:=car s$
 atlas:=cdr s$
 bubles:=append(c,bubles)$
 if null c then return bubles . atlas$
 s:=find!_bubles1 (atlas,al)$
 c:=car s$
 atlas:=cdr s$
 bubles:=append(c,bubles)$
 if null c then return bubles . atlas$
 go loop
end$

symbolic procedure reduce!_triangle triangle$
% RETURN (N . VERTEX . TRIANGLE) OR NIL,
% N - NUMBER OF EXTERNAL EDGES$
if null triangle then nil
else
  begin
    scalar extedges,vertex,n$
    %EXTEDGES - LIST OF EXTERNAL EDGES,
    % N - NUMBER OF EXTERNAL EDGES,
    %VERTEX - NEW VERTEX,MADE FROM TRIANGLE$
      vertex:=mk!_vertextr triangle$
      extedges:=ext!_edges vertex$
      n:=length extedges$
  return
         if n = 1 then nil            % 14.09.90    RT
         else                         % 14.09.90    RT
             n . vertex . triangle
end$

symbolic procedure sk!_vertextr z$
% Z IS (N . VERTEX . TRIANGLE) $
if car z = 1 then mk!_empty!_vertex ()
else
 if car z = 3 then cadr z
 else set!_error ('sk!_vertextr,z) $

symbolic procedure ext!_edges vertex$
%SELECT EXTERNAL EDGES IN VERTEX $
if p!_empty!_vertex vertex then nil
else
  if p!_member!_edge (first!_edge vertex,s!_vertex!_rest vertex)
                         or
     equal!_edges (first!_edge vertex,!_0edge )
   then ext!_edges delete!_edge (first!_edge vertex,
                                 s!_vertex!_rest vertex)
  else first!_edge vertex .
                           ext!_edges s!_vertex!_rest vertex $

symbolic procedure ext!_edges!_map!_ map!_$
%SELECT EXTERNAL EDGES OF MAP!_$
if p!_empty!_map!_ map!_ then nil
else
  ext!_map!_!_ver (ext!_edges s!_vertex!_first map!_,
                 ext!_edges!_map!_ s!_map!_!_rest map!_)$

symbolic procedure ext!_map!_!_ver (vlist,mlist)$
if null vlist then mlist
else
  if memq(car vlist,mlist) then
       ext!_map!_!_ver (cdr vlist,
                      delete(car vlist,mlist))
  else ext!_map!_!_ver (cdr vlist,car vlist . mlist)$

symbolic procedure add!_tadpoles (bubles,alst)$
if null bubles then alst
else
  if caar bubles = 1 then
       add!_tadpoles (cdr bubles,
                      cons(cons(car mk!_vertextr cadr car bubles,
                                0),
                           alst))
   else add!_tadpoles (cdr bubles,alst)$


%END$  %cvit8.red
%::::::::::::::::::::::: ATLAS SORTING ROUTINES ********************** $
% 13.06.88$

lisp$

global '(!*cvitrace)$

!*cvitrace:=nil$  %IF T THEN TRACE BACTRAKING WHILE ATLAS SORTING$

 flag('(cvitrace),'switch)$

symbolic procedure sort!_atlas atlas$
%TOP LEVEL PROCEDURE
if null atlas then atlas
else
 (lambda z$
   if z then z        %ATLAS FULLY SORTED
   else set!_error (sort!_atlas ,atlas))
  sort!_atlas1 atlas $

symbolic procedure sort!_atlas1 atlas$
(lambda z$
   if z then z          %ATLAS FULLY SORTED
   else
     if !*cviterror then print!_atlas!_sort (atlas,nil)
     else nil )
 atlas!_sort (atlas,old!_edge!_list )$

symbolic procedure print!_atlas!_sort (atlas,edgelist)$
<< print "ATLAS NOT SORTED "$
   print!_atlas atlas$
   if edgelist then
      << print "DEFINED EDGES: "$
         for each edge in edgelist do print edge >> $
   nil >> $

symbolic procedure atlas!_sort (atlas,edgelist)$
begin
  scalar z,newedges$
 newedges:=store!_edges new!_edge!_list$
 z:=
 errorset(list('atlas!_sort1 ,mkquote atlas,mkquote edgelist),
          !*cvitrace,
          !*backtrace)$
 return
 if atom z then        %ATLAS NOT SORTED
 << restor!_edges (newedges,new!_edge!_list)$  %RESTORE EDGES PARENTS
    if !*cvitrace then print!_atlas!_sort (atlas,edgelist)
    else nil >>
 else car z
end$

symbolic procedure store!_edges edgelist$
for each edge in edgelist collect
      (car edge . cdr edge)$

symbolic procedure restor!_edges (edgelist,newedgelist)$
if null edgelist then
 if newedgelist then set!_error (restor!_edges , edgelist,newedgelist)
 else nil
else
 if null newedgelist then
           set!_error (restor!_edges , edgelist,newedgelist)
 else
  if s!_edge!_name car edgelist = s!_edge!_name car newedgelist then
      << rplacd(car newedgelist,cdar edgelist)$
         car newedgelist . restor!_edges (cdr edgelist,
                                          cdr newedgelist) >>
  else
    set!_error (restor!_edges , edgelist,newedgelist)$

symbolic procedure defined!_atlas (atlas,edgelist)$
(lambda edges$
    defined!_edges (edges,
%                   DEFINED!_APPEND(EDGES,EDGELIST)))
                    edgelist))
 atlas!_edges atlas$

symbolic procedure defined!_append (edges,edgelist)$
 if null edges then edgelist
 else if defined!_edge (car edges,edgelist) then
          car edges . defined!_append (cdr edges,edgelist)
      else defined!_append (cdr edges,edgelist) $

symbolic procedure defined!_edges (edges,edgelist)$
if null edges then t
else
  if defined!_edge (car edges,edgelist)
              then
     defined!_edges (cdr edges,car edges . edgelist)
  else definedl!_edges (cdr edges,list car edges,edgelist)$

symbolic procedure definedl!_edges (edges,passed,edgelist)$
if null edges then null passed
else
 if defined!_edge (car edges,edgelist) then
    defined!_edges (nconc(passed,cdr edges),car edges . edgelist)
 else definedl!_edges (cdr edges,car edges . passed,edgelist)$

symbolic procedure atlas!_sort1 (atlas,edgelist)$
if all!_defined (s!_atlas!_map!_ atlas,edgelist) then
     mk!_atlas (s!_atlas!_map!_ atlas,
                coeff!_sortl( s!_atlas!_coeff atlas,
                              nil,
                              nconc( map!_!_edges s!_atlas!_map!_ atlas,
                                     edgelist)),
                s!_atlas!_den!_om atlas)
else coeff!_sort (coeff!_ordn (s!_atlas!_coeff atlas,edgelist),
%LSE COEFF!_SORT (S!_ATLAS!_COEFF ATLAS,
                  mk!_atlaslist (s!_atlas!_map!_ atlas,
                                 nil,
                                 s!_atlas!_den!_om atlas),
                  edgelist)$

symbolic procedure coeff!_sortl (atlaslist,passed,edgelist)$
 coeff!_sortl1 (coeff!_ordn (atlaslist,edgelist),passed,edgelist)$

symbolic procedure coeff!_sort (atlaslist,passed,edgelist)$
if atlaslist then
  (lambda z$                   %Z - NIL OR SORDET ATLAS
      if z then                %FIRST ATLAS ALREADY DEFINED
         mk!_atlas (s!_atlas!_map!_ z,
                    coeff!_sortl (append(s!_atlas!_coeff z,
                                        append(cdr atlaslist,passed)),
                                  nil,
                                  nconc(map!_!_edges s!_atlas!_map!_ z,
                                        edgelist)),
                    s!_atlas!_den!_om z)
      else
          coeff!_sort (cdr atlaslist,
                       car atlaslist . passed,
                       edgelist))
  atlas!_sort (car atlaslist,edgelist)
else coeff!_sort!_f (passed,nil,edgelist)$

symbolic procedure coeff!_sort!_f (passed,farewell,edgelist)$
if null passed then
  if null farewell then nil
  else error(51,nil)
else
 if s!_atlas!_coeff car passed then          %NOT EMPTY COEFF
   coeff!_sort (append(
                   s!_atlas!_coeff car passed,
                   mk!_atlas (s!_atlas!_map!_ car passed,
                              nil,
                              s!_atlas!_den!_om car passed) .
                     append(cdr passed,farewell)),
                nil,
                edgelist)
 else coeff!_sort!_f (cdr passed,
                      car passed . farewell,
                      edgelist) $

%.......... 31.05.88 ::::::::::: $

symbolic procedure coeff!_ordn (atlaslist,edgelist)$
for each satlas in
 coeff!_ordn1 (mk!_spec!_atlaslist (atlaslist,edgelist),nil)
collect cdr satlas$

symbolic procedure mk!_spec!_atlaslist (atlaslist,edgelist)$
 for each atlas in atlaslist collect mk!_spec!_atlas (atlas,edgelist)$

symbolic procedure mk!_spec!_atlas (atlas,edgelist)$
%RETURN PAIR (PAIR1 . ATLAS)
%WHERE PAIR1 IS A PAIR - EDGES . PARENTS
%WHERE EDGES - ALL EDGES OF ATLAS
%WHERE PARENTS-THOSE PARENTS OF EDGES WICH NOT CONTAITED IN EDGELIST
(lambda edges$
(edges . diff!_edges (edges!_parents edges,edgelist)) . atlas)
 atlas!_edges atlas$

symbolic procedure edges!_parents edgelist$
if null edgelist then nil
else
  (lambda z$
     append(z , edges!_parents cdr edgelist))
   edge!_new!_parents car edgelist$

symbolic procedure edge!_new!_parents edge$
% SELECT EDGE PARENTS FROM NEW!_EDGE!_LIST$
if p!_old!_edge edge then nil else
(lambda names$
  edge!_new!_parent list(car names,cdr names))
 s!_edge!_prop!_ edge$

symbolic procedure edge!_new!_parent namelist$
if null namelist then nil
else
 (lambda z$
    if z then z . edge!_new!_parent cdr namelist
    else edge!_new!_parent cdr namelist)
  assoc(car namelist,new!_edge!_list) $

symbolic procedure diff!_edges (edgelist1,edgelist2)$
if null edgelist1 then nil
else
 if p!_member!_edge (car edgelist1,edgelist2) then
    diff!_edges (cdr edgelist1,edgelist2)
 else  car edgelist1 .
       diff!_edges (cdr edgelist1,edgelist2)$

symbolic procedure coeff!_ordn1 (satlaslist,passed)$
if null satlaslist then passed
else
%IF NULL CAAR SATLASLIST THEN     %ATLAS HAS NO UNDEFINED
%      COEFF!_ORDN1 (CDR SATLASLIST,CAR SATLASLIST . PASSED)
%ELSE
 (lambda z$                    % Z - NIL OR SATLASLIST
   if z then                   % SUBATLAS FINED AND ADDED$
        coeff!_ordn1 (z,passed)
   else coeff!_ordn1 (cdr satlaslist,car satlaslist . passed) )
  p!_subsatlaslist (car satlaslist,cdr satlaslist,nil)$

symbolic procedure p!_subsatlaslist (satlas,satlaslist,passed)$
if null satlaslist then nil
else
 if or!_subsatlas(satlas,car satlaslist) then
            embed!_satlases (satlas,car satlaslist) .
            nconc(passed,cdr satlaslist)
 else p!_subsatlaslist (satlas,
                        cdr satlaslist,
                        car satlaslist . passed)$

symbolic procedure or!_subsatlas (satlas1,satlas2)$
  p!_subsatlas (satlas1,satlas2)
             or
  p!_subsatlas (satlas2,satlas1) $

symbolic procedure p!_subsatlas (satlas1,satlas2)$
 p!_subedgelist (caar satlas1,caar satlas2)
               or
 p!_inbothlists (cdar satlas1,caar satlas2) $

symbolic procedure p!_inbothlists (edgelist1,edgelist2)$
if null edgelist1 then nil
else p!_member!_edge (car edgelist1,edgelist2)
                 or
     p!_inbothlists (cdr edgelist1,edgelist2)$

symbolic procedure p!_subedgelist (edgelist1,edgelist2)$
 if null edgelist1 then t
 else
   p!_member!_edge (car edgelist1,edgelist2)
              and
   p!_subedgelist (cdr edgelist1,edgelist2)$

symbolic procedure embed!_satlases (satlas1,satlas2)$
 if p!_subsatlas (satlas1,satlas2) then embed!_satlas (satlas1,satlas2)
 else
 if p!_subsatlas (satlas2,satlas1) then embed!_satlas (satlas2,satlas1)
 else set!_error (embed!_satlases,satlas1,satlas2) $

symbolic procedure embed!_satlas (satlas1,satlas2)$
 car satlas2 . embed!_atlas (cdr satlas1,cdr satlas2)$

symbolic procedure embed!_atlas (atlas1,atlas2)$
%EMBED ATLAS1 INTO ATLAS2
 mk!_atlas (s!_atlas!_map!_ atlas2,
            atlas1 . s!_atlas!_coeff atlas2,
            s!_atlas!_den!_om atlas2)$

symbolic procedure coeff!_sortl1 (atlaslist,passed,edgelist)$
if null atlaslist then
 if null passed then nil
 else list coeff!_sort!_f (passed,nil,edgelist)
else
(lambda z$
 if z then      %ATLAS SORTED
      z . coeff!_sortl1 (cdr atlaslist,passed,edgelist)
 else coeff!_sortl1 (cdr atlaslist,car atlaslist . passed,edgelist))
 atlas!_sort (car atlaslist,edgelist)$

% ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, $


%END$  %cvit82.red
%:*:*:*:*:*:*:*:*:*:*:*:* FACTORIZATION OF MAP!_S :*:*:*:*:*:*:*:*:*:$
% 19.05.88 $
lisp$

symbolic procedure renamel!_edges edges$
if not equal!_edges (car edges,cadr edges) then
  rename!_edges (car edges , cadr edges)$

symbolic procedure map!_!_vertex!_first map!_$
  mk!_vertex1!_map!_
                  s!_vertex!_first map!_$

symbolic procedure  both!_empty!_map!_s (map!_1,map!_2)$
 p!_empty!_map!_ map!_1
      and
 p!_empty!_map!_ map!_2 $

symbolic procedure has!_parents edge$
 (lambda z$
           car z neq '!? and
           cdr z neq '!?    )
  s!_edge!_prop!_ edge $

symbolic procedure less!_edge (edge1,edge2,edgelist)$
% EDGE1 < EDGE2 IFF EDGE1 WAS CREATED EARLIER$
 less!_edge!_name (s!_edge!_name edge1,
                   s!_edge!_name edge2,
                   edgelist)$

symbolic procedure less!_edge!_name (name1,name2,edgelist)$
if null edgelist then set!_error ('less!_edge!_name ,name1,name2,
                                   edgelist)
else
  if name1 eq s!_edge!_name car edgelist then nil
  else
    if name2 eq s!_edge!_name car edgelist then t
    else less!_edge!_name (name1,name2,cdr edgelist)$

symbolic procedure rename!_edges (edge1,edge2)$
if p!_old!_edge edge1 then
 %IF P!_OLD!_EDGE EDGE2 THEN OLD!_EDGE!_LIST
  if p!_old!_edge edge2 then replace!_old!_edge (edge1,edge2)
  else replace!_edge (edge2,edge1,new!_edge!_list )
else
  if p!_old!_edge edge2 then replace!_edge (edge1,edge2,
                                            new!_edge!_list )
  else
    if has!_parents edge1 then
      if has!_parents edge2 then replace!_new!_edge (edge1,edge2)
      else replace!_edge (edge2,edge1,new!_edge!_list )
    else
      if has!_parents edge2 then
           replace!_edge (edge1,edge2,new!_edge!_list )
      else replace!_new!_edge (edge1,edge2)$

symbolic procedure replace!_new!_edge (edge1,edge2)$
 replace!_o!_edge (edge1,edge2,new!_edge!_list )$

symbolic procedure replace!_old!_edge (edge1,edge2)$
% 31.08.90 RT
if is!_indexp edge1 then
 if is!_indexp edge2 then
     replace!_o!_edge (edge1,edge2,old!_edge!_list )
 else  replace!_edge (edge1,edge2,old!_edge!_list)
else
  if is!_indexp edge2 then
       replace!_edge (edge2,edge1,old!_edge!_list)
  else
      replace!_o!_edge (edge1,edge2,old!_edge!_list )$

symbolic procedure replace!_o!_edge (edge1,edge2,edgelist)$
if less!_edge (edge1,edge2,edgelist) then
              replace!_edge (edge2,edge1,edgelist)
else          replace!_edge (edge1,edge2,edgelist)$

symbolic procedure copy!_edge edge$
 car edge . cadr edge . caddr edge . nil $


symbolic procedure replace!_edge2 (oldedge,newedge)$
<< rplaca(oldedge,car newedge)$
   rplacd(oldedge,cdr newedge) >> $

symbolic procedure replace!_edge (oldedge,newedge,edgelist)$
 replace1!_edge (copy!_edge oldedge,newedge,edgelist)$

symbolic procedure replace1!_edge (oldedge,newedge,edgelist)$
if null edgelist then nil
else
  <<  if equal!_edges (oldedge,car edgelist) then
                         replace!_edge2 (car edgelist,newedge)$
      replace1!_parents (oldedge,newedge,car edgelist)$
      replace1!_edge (oldedge,newedge,cdr edgelist) >> $

symbolic procedure replace1!_parents (oldedge,newedge,edge)$
 replace2!_parents (s!_edge!_name oldedge,
                    s!_edge!_name newedge,
                    s!_edge!_prop!_ edge)$

symbolic procedure replace2!_parents (oldname,newname,edgeprop!_)$
 << if oldname = car edgeprop!_ then rplaca(edgeprop!_,newname)$
    if oldname = cdr edgeprop!_ then rplacd(edgeprop!_,newname) >> $

symbolic procedure mk!_simple!_map!_ inmap!_$
  mk!_simple!_map!_1 (inmap!_,mk!_empty!_map!_ (),nil,nil)$

symbolic procedure both!_old edges$
 p!_old!_edge  car edges
        and
 p!_old!_edge cadr edges$

symbolic procedure both!_vectors edges$   % 31.08.90 RT
 not is!_indexp car edges
        and
 not is!_indexp cadr edges$

symbolic procedure old!_renamel!_edv (vertex,edges)$
% RENAMES EDGES IN VERTEX$
 ren!_edge (s!_edge!_name car edges .
            s!_edge!_name cadr edges,vertex)$

symbolic procedure mk1!_simple!_map!_ map!_d$
%MAP!_D IS A PAIR (MAP!_.DEN!_OM)$
mk!_simple!_map!_1 (car map!_d,mk!_empty!_map!_ (),list cdr map!_d,nil)$

symbolic procedure mk!_simple!_map!_1 (inmap!_,outmap!_,den!_om,coeff)$
if p!_empty!_map!_ inmap!_ then
 %        FIND!_BUBLTR
               mk!_atlas  (mk!_parents!_map!_ outmap!_ ,
                           if null coeff then nil
                           else
                             for each map!_ in coeff collect
                                               mk1!_simple!_map!_ map!_,
                           den!_om)
else
(lambda edges$
 (lambda n$
  if p!_vertex!_prim s!_vertex!_first inmap!_ then
   if n=2 then                 % VERTEX=(A,B)=DELTA(A,B)  $
    if both!_old edges and both!_vectors edges then   % 31.08.90
          mk!_simple!_map!_1 (s!_map!_!_rest inmap!_,
                            add!_vertex (s!_vertex!_first inmap!_,
                                         outmap!_),
                            den!_om,
                            coeff)
    else
     << renamel!_edges edges$
        if both!_empty!_map!_s (s!_map!_!_rest inmap!_,outmap!_) then
          mk!_simple!_map!_1 (s!_map!_!_rest inmap!_,
                            add!_vertex (s!_vertex!_first inmap!_,
                                         outmap!_),
                            den!_om,
                            coeff)
        else
           mk!_simple!_map!_1 (s!_map!_!_rest inmap!_,
                             outmap!_,
                             den!_om,
                             coeff )
     >>
   else
      mk!_simple!_map!_1 ( s!_map!_!_rest inmap!_,
                         add!_vertex ( s!_vertex!_first inmap!_,
                                       outmap!_),
                         den!_om,
                         coeff)
  else
   if n=2  then
    if both!_old edges  and both!_vectors edges then  %11.09.90 RT
        mk!_simple!_map!_1 (add!_vertex (mk!_edges!_vertex edges,
                                       s!_map!_!_rest inmap!_),
                          outmap!_,
                          den!_om,
                         (mk!_vertex1!_map!_ (
                            old!_renamel!_edv (s!_vertex!_first inmap!_,
                                               edges) ) .
                          old!_renamel!_edv (mk!_edges!_vertex edges,
                                             edges))
                                                . coeff  )
    else
     << renamel!_edges edges$
        mk!_simple!_map!_1 (s!_map!_!_rest inmap!_,
                          outmap!_,
                          den!_om,
                         (map!_!_vertex!_first inmap!_ . edges)
                             . coeff)
      >>
   else
   if n=3  and
     ((map!_!_length (inmap!_) + map!_!_length (outmap!_)) > 2 )
    then
     (lambda v$
     mk!_simple!_map!_1 (add!_vertex (v,
                                    s!_map!_!_rest inmap!_),
                       outmap!_,
                       den!_om,
                      (add!_vertex (v,
                                    map!_!_vertex!_first inmap!_) . v)
                        . coeff))
      mk!_edges!_vertex edges
   else
    if
      (lambda k$
           k > 4 and
           n < k )              %NOT ALL LINES EXTERNAL $
           vertex!_length s!_vertex!_first inmap!_
    then
    (lambda firz$
    mk!_simple!_map!_1 (append!_map!_s (firz,s!_map!_!_rest inmap!_),
                      outmap!_,
                      den!_om,
                      coeff) )
     (mk!_firz!_op s!_vertex!_first inmap!_)        %26.04.88
  else if t then
    mk!_simple!_map!_1 (s!_map!_!_rest inmap!_,
                      add!_vertex (s!_vertex!_first inmap!_,outmap!_),
                      den!_om,
                      coeff)
    else
    mk!_simple!_map!_1 (append!_map!_s (mk!_simple!_vertex
                                      s!_vertex!_first inmap!_,
                                    s!_map!_!_rest inmap!_),
                      outmap!_,
                      den!_om,
                      coeff)  )
  length edges)
(ext!_edges s!_vertex!_first inmap!_) $


% ?^?^?^?^?^?^?^?^?^?^?^?^? FIERZ OPTIMIZATION ?^?^?^?^?^?^?^?^?^?^?^?$
%       13.05.88$


global '(!*cvitop)$

flag('(cvitop),'switch)$

symbolic procedure mk!_firz!_op vertex$
if null !*cvitop then mk!_firz vertex
else firz!_op vertex$

symbolic procedure firz!_op vertex$
mk!_firz find!_cycle (optimal!_edge vertex,
                      vertex,
                      mk!_empty!_vertex ())$

symbolic procedure find!_cycle (edge,vertex,passed)$
if equal!_edges (edge,first!_edge vertex) then
   append!_vertex (vertex,reversip!_vertex passed)
else find!_cycle (edge,
                  s!_vertex!_rest vertex,
                  add!_edge (first!_edge vertex,passed))$

symbolic procedure optimal!_edge vertex$
optimal1!_edge
 internal!_edges (vertex,mk!_empty!_vertex ())$

symbolic procedure internal!_edges (vertex1,vertex2)$
if p!_empty!_vertex vertex1 then vertex2
else
  if p!_member!_edge (first!_edge vertex1,s!_vertex!_rest vertex1)
                     or
     p!_member!_edge (first!_edge vertex1,vertex2)
   then internal!_edges (s!_vertex!_rest vertex1,
                         add!_edge (first!_edge vertex1,vertex2))
  else  internal!_edges (s!_vertex!_rest vertex1,vertex2)$

symbolic procedure optimal1!_edge vertex$
% VERTEX CONTAINS ONLY PAIRED EDGES
(lambda (l,z)$
   opt!_edge (z,
              edge!_distance (z,vertex,l),
              s!_vertex!_rest vertex,
              add!_edge (z,mk!_empty!_vertex ()),
              l))
(vertex!_length vertex,
 first!_edge vertex)$

symbolic procedure edge!_distance (edge,vertex,l)$
% L - FULL VERTEX LENGTH
(lambda n$
     min(n,l - n - 2))
 edge!_dist (edge,s!_vertex!_rest vertex)$

symbolic procedure edge!_dist (edge,vertex)$
if equal!_edges (edge,first!_edge vertex) then 0
else add1 edge!_dist (edge,s!_vertex!_rest vertex)$

symbolic procedure opt!_edge (edge,distance,vertex,passed,n)$
% N - FULL VERTEX LENGTH
if distance = 0 or p!_empty!_vertex vertex then edge
else
(lambda firstedge$
   if p!_member!_edge (firstedge,passed) then
              opt!_edge (edge,
                         distance,
                         s!_vertex!_rest vertex,
                         passed,
                         n)
   else
 (lambda dist$
    if dist < distance then
              opt!_edge (firstedge,
                         dist,
                         s!_vertex!_rest vertex,
                         add!_edge (firstedge,passed),
                         n)
     else     opt!_edge (edge,
                         distance,
                         s!_vertex!_rest vertex,
                         add!_edge (firstedge,passed),
                         n))
  edge!_distance (firstedge,vertex,n))
first!_edge vertex $



%<?><?><?><?><?><?><?> END OF OPTIMIZATION PART <?><?><?><?><?><?> $

symbolic procedure mk!_firz vertex$
% VERTEX=(A1,...,AM,Z,B1,...,BN,Z,C1,...,CK)
% RETURNS UNION MAP!_ WHERE
% MAP!_ =MAP!_1 & MAP!_2  WHERE
% MAP!_1=((B1,...,BN,X)(Y,C1,...,CK,A1,...,AM)),
% MAP!_2=((Z,X,Z,Y)) $
   mk!_firz1 (vertex,mk!_empty!_vertex ())$

symbolic procedure mk!_firz1 (vertex1,vertex2)$
if p!_empty!_vertex vertex1 then reversip!_vertex vertex2
else
  (lambda z$
      if z then                   %FIRST EDGE CONTAINS TWICE$
         mk!_firz2 (first!_edge vertex1,
                    car z,
                    append!_vertex (cdr z,
                                    reversip!_vertex vertex2))
      else
         mk!_firz1 (s!_vertex!_rest vertex1,
                    add!_edge (first!_edge vertex1,
                               vertex2) ) )
   mp!_member!_edge (first!_edge vertex1,
                     s!_vertex!_rest vertex1)$

symbolic procedure mk!_firz2 (edge,vertex1,vertex2)$
%RETURNS MAP!_ =MAP!_1 & MAP!_2 ,
%VERTEX1=(B1,...,BN),
%VERTEX2=(C1,...,CK,A1,...,AM)  $
(lambda (nedge,nedg1)$
 append!_map!_s (
  mk!_coeff2 (edge,nedge,nedg1),
  mk!_vertex2!_map!_ (conc!_vertex (vertex1,
                                  mk!_edge1!_vertex nedge),
                    add!_edge (nedg1,vertex2))
               ))
(mk!_nedge (),
 mk!_nedge ()) $

symbolic procedure mk!_coeff2 (edge,nedge,nedg1)$
 mk!_vertex1!_map!_
                 mk!_edge4!_vertex (edge,nedge,edge,nedg1)$

symbolic procedure mk!_nedge $
(lambda edge$
   new!_edge (edge,edge))
 mk!_edge ('!?,'!? . '!?,nil) $

symbolic procedure mp!_member!_edge (edge,vertex)$
% RETURNS NIL OR PAIR.
% IF VERTEX=(A1,...,AM,EDGE,...,B1,...,BN) THEN
% PAIR= (A1,...,AM) . (B1,...,BM) $
  mp!_member1!_edge (edge,vertex,mk!_empty!_vertex ())$

symbolic procedure mp!_member1!_edge (edge,vertex,tail)$
if p!_empty!_vertex vertex then nil
else
 if
  equal!_edges (edge,first!_edge vertex) then
           reversip!_vertex tail .
           s!_vertex!_rest vertex
 else mp!_member1!_edge (edge,
                         s!_vertex!_rest vertex,
                         add!_edge (first!_edge vertex,
                                    tail) ) $


%END$  %cvit10.red
% ()()()()()()()()()()()()()() PRINTING ATLAS AND MAP!_ ROUTINES ()()().
lisp$             %30.01.87$

fluid '(ntab!*)$

symbolic procedure print!_atlas atlas$
begin
  scalar ntab!*$
  ntab!*:=0$
  prin2!_atlas atlas$
end$

symbolic procedure prin2!_atlas atlas$
if null atlas then nil
else
    << print!_map!_ s!_atlas!_map!_ atlas$
       print!_den!_om s!_atlas!_den!_om atlas$
       print!_coeff s!_atlas!_coeff atlas$
                >> $

symbolic procedure print!_map!_ map!_$
 << pttab ntab!*$
    prin2 "MAP!_ IS: ("$
    prin2!_map!_ map!_$
    prin2 " )"$
    terpri()  >> $

symbolic procedure prin2!_map!_ map!_$
if p!_empty!_map!_ map!_ then nil
else
    << print!_vertex s!_vertex!_first map!_$
       prin2!_map!_ s!_map!_!_rest map!_ >> $

symbolic procedure print!_vertex vertex$
 <<
    prin2 "( "$
    prin2!_vertex vertex$
    prin2 ")"      >> $

symbolic procedure prin2!_vertex vertex$
if p!_empty!_vertex vertex then nil
else
    << print!_edge first!_edge vertex$
       prin2!_vertex s!_vertex!_rest vertex >> $

symbolic procedure print!_edge edge$
 << prin2!_edge edge$
    prin2 " "    >> $

symbolic procedure prin2!_edge edge$
 prin2 s!_edge!_name edge $

symbolic procedure pttab n$
  << spaces n $   % TTAB N$         % 07.06.90
     prin2 n$
     prin2 ":" >> $

symbolic procedure print!_coeff coeff$
 << ntab!*:=ntab!*+1$
    prin2!_coeff coeff$
    ntab!*:=ntab!*-1    >> $

symbolic procedure prin2!_coeff atlases$
if null atlases then nil
else
    << prin2!_atlas car atlases$
       prin2!_coeff cdr atlases >> $

symbolic procedure print!_den!_om den!_list$
 << pttab ntab!*$
    prin2 "DEN!_OM IS: "$
    if null den!_list then prin2 nil
    else prin2!_map!_ den!_list $
    terpri() >> $

unfluid '(ntab!*)$

symbolic procedure print!_old!_edges ()$
   print!_edge!_list old!_edge!_list $

symbolic procedure print!_new!_edges ()$
   print!_edge!_list new!_edge!_list $

symbolic procedure print!_edge!_list edgelist$
if null edgelist then nil
else << print car edgelist$
        print!_edge!_list cdr edgelist >> $


%END$  %cvit12.red
%---------------------- MAKES PARENTS AFTER FIERZING ----------------$

          %24.05.88$
 lisp$


symbolic procedure mk!_simpl!_map!_ map!_$
  mk!_simpl!_map!_1 (map!_,mk!_empty!_map!_ ())$

symbolic procedure mk!_simpl!_map!_1 (inmap!_,outmap!_)$
if p!_empty!_map!_ inmap!_ then
                           resto!_map!_!_order outmap!_
else
  if p!_vertex!_prim s!_vertex!_first inmap!_ then
      mk!_simpl!_map!_1 ( s!_map!_!_rest inmap!_,
                         add!_vertex (mk!_parents!_prim
                                            s!_vertex!_first inmap!_,
                                      outmap!_))
  else
    mk!_simpl!_map!_1 (append!_map!_s (mk!_simple!_vertex
                                      s!_vertex!_first inmap!_,
                                    s!_map!_!_rest inmap!_),
                      outmap!_)$

symbolic procedure mk!_simple!_vertex vertex$
 % VERTEX => MAP!_ $
begin
 scalar nedge,fedge,sedge$
 fedge:=first!_edge vertex$
 sedge:=second!_edge vertex$
 if not has!_parents fedge or not has!_parents sedge then
    return mk!_simple!_vertex cycl!_vertex vertex$
 nedge:=new!_edge (fedge,sedge)$
 vertex:=s!_vertex!_rest
         s!_vertex!_rest vertex$
 return
     mk!_vertex2!_map!_ ( mk!_edge3!_vertex (nedge,fedge,sedge),
                        add!_edge (nedge,vertex))
end$

symbolic procedure mk!_parents!_map!_ map!_$
%MAKES PARENTS FOR ALL EDGES IN MAP!_.
%THIS CAN BE DONE BECAUSE NEW EDGES NEVER CREATE CYCLES$
 standard!_map!_
 mk!_simpl!_map!_
 mk!_parents1!_map!_ (map!_,mk!_empty!_map!_ (),mk!_empty!_map!_ ())$

symbolic procedure standard!_map!_ map!_$
if p!_empty!_map!_ map!_ then mk!_empty!_map!_ ()
else
 if vertex!_length s!_vertex!_first map!_ > 2 then
    add!_vertex (s!_vertex!_first map!_,
                 standard!_map!_ s!_map!_!_rest map!_)
 else standard!_map!_ add!_vertex (add!_0!_edge s!_vertex!_first map!_,
                                 s!_map!_!_rest map!_)$

symbolic procedure add!_0!_edge vertex$
%ADDS SPECIAL VERTEX$
add!_edge (!_0edge ,vertex)$

symbolic procedure mk!_parents1!_map!_ (inmap!_,outmap!_,passed)$
if p!_empty!_map!_ inmap!_ then
 if p!_empty!_map!_ passed then outmap!_     %ALL EDGES HAVE PARENTS$
 else mk!_parents1!_map!_ (passed,outmap!_,mk!_empty!_map!_ ())
else
 (lambda edges$
   if null edges then        %IN FIRST VERTEX ALL EDGES HAVE PARENTS$
      mk!_parents1!_map!_ (s!_map!_!_rest inmap!_,
                         add!_vertex (s!_vertex!_first inmap!_,
                                      outmap!_),
                         passed)
   else
    if single!_no!_parents edges then   %ONLY ONE EDGE IN THE VERTEX$
                                        %HAS NO PARENTS$
       mk!_parents1!_map!_ (s!_map!_!_rest inmap!_,
                          append!_map!_s (mk!_parents!_vertex
                                            s!_vertex!_first inmap!_,
                                        outmap!_),
                          passed)
    else
       mk!_parents1!_map!_ (s!_map!_!_rest inmap!_,
                          outmap!_,
                          add!_vertex (s!_vertex!_first inmap!_,
                                       passed))
                                               )
  s!_noparents s!_vertex!_first inmap!_ $

symbolic procedure s!_noparents vertex$
%SELECTS EDGES WITHOUT PARENTS IN VERTEX$
if p!_empty!_vertex vertex then nil
else
 if has!_parents first!_edge vertex then
         s!_noparents s!_vertex!_rest vertex
 else
     first!_edge vertex .
     s!_noparents s!_vertex!_rest vertex$

symbolic procedure mk!_parents!_vertex vertex$
%MAKES PARENTS FOR THE SINGLE EDGE WITHOUT PARENTS IN VERTEX,
% (VERTEX HAS ONLY ONE EDGE WITHOUT PARENTS ^)       $
 mk!_simpl!_map!_ mk!_vertex1!_map!_ vertex$

symbolic procedure mk!_parents!_prim pvertex$
% CREATES PARENTS FOR THE ONLY EDGE WITHOUT PARENTS IN PRIMITIVE
% (THREE EDGES) VERTEX $
if vertex!_length pvertex neq 3 then pvertex
else
  (lambda edges$
     if null edges then pvertex
     else
        << mk!_edge!_parents (pvertex,car edges)$
           pvertex >> )
   s!_noparents pvertex$

symbolic procedure mk!_edge!_parents (vertex,edge)$
 mk!_edge1!_parents (delete!_edge (edge,
                                   vertex),
                     edge)$

symbolic procedure mk!_edge1!_parents (vertex2,edge)$
 add!_parents (edge,
               mk!_edge!_prop!_ (
                               s!_edge!_name first!_edge vertex2,
                               s!_edge!_name second!_edge vertex2))$

symbolic procedure add!_parents (edge,names)$
  add!_parents0(edge,names,nil)$

symbolic procedure add!_parents0 (edge,names,bool)$
 addl!_parents (new!_edge!_list ,edge,names . list bool)$

symbolic procedure addl!_parents (edgelist,edge,names)$
% NAMES IS A PAIR NAME1 . NAME2 $
if null edgelist then nil
else
(if equal!_edges (car edgelist,edge) then
    rep!_parents (car edgelist,names)
 else car edgelist) .
                      addl!_parents (cdr edgelist,edge,names) $

symbolic procedure rep!_parents (edge,names)$
 << rplacd(edge,names)$
    edge >> $

%END$  %cvit14.red
%EEEEEEEEEEEEEEEEEEEEEEEEE SELECT ALL EDGES %%%%%%%%%%%%%%%%%%%%%%%%% $

                       % 07.06.88$

lisp$

symbolic procedure atlas!_edges atlas$
union!_edges (
 union!_edges (map!_!_edges s!_atlas!_map!_ atlas,
               den!_!_edges s!_atlas!_den!_om atlas),
 coeff!_edges s!_atlas!_coeff atlas)$

symbolic procedure den!_!_edges den!_om$
 map!_!_edges den!_om$

symbolic procedure coeff!_edges atlaslist$
 if null atlaslist then nil
 else union!_edges (atlas!_edges car atlaslist,
                    coeff!_edges cdr atlaslist) $

symbolic procedure map!_!_edges map!_$
 if p!_empty!_map!_ map!_ then nil
 else union!_edges (vertex!_edges s!_vertex!_first map!_,
                    map!_!_edges s!_map!_!_rest map!_)$

symbolic procedure union!_edges (newlist,oldlist)$
if null newlist then oldlist
else union!_edges (cdr newlist,
                   union!_edge (car newlist,oldlist))$

symbolic procedure union!_edge (edge,edgelist)$
 if memq!_edgelist (edge,edgelist) then edgelist
 else edge . edgelist$

symbolic procedure memq!_edgelist (edge,edgelist)$
 assoc(s!_edge!_name edge,
       edgelist)$

symbolic procedure exclude!_edges (edgelist,exclude)$
% EXCLUDE IS A LIST OF EDGES TO BE EXCLUDED FROM EDGELIST$
 if null edgelist then nil
 else
   if memq!_edgelist (car edgelist,exclude) then
           exclude!_edges (cdr edgelist,exclude)
   else car edgelist .
           exclude!_edges (cdr edgelist,exclude)  $


symbolic procedure constr!_worlds (atlas,edgelist)$
(lambda edges$
   actual!_edges!_world (
      mk!_world1 (actual!_edges!_map!_ (edges,
                                      edgelist,
                                      s!_atlas!_map!_ atlas),
                  constr!_coeff (s!_atlas!_coeff atlas,
                                 union!_edges (edges,edgelist)),
                  s!_atlas!_den!_om atlas
                  )
               ) )
union!_edges(
  den!_!_edges s!_atlas!_den!_om atlas,
  map!_!_edges s!_atlas!_map!_ atlas)$

symbolic procedure constr!_coeff (atlases,edgelist)$
 if null atlases then nil
 else
      constr!_worlds (car atlases,edgelist) .
      constr!_coeff (cdr atlases,edgelist)$

symbolic procedure actual!_edges!_map!_ (edges,edgelist,map!_)$
 actedge!_map!_ (edges,edgelist,list!_of!_parents(edges,edgelist),nil)
%ACTEDGE!_MAP!_ (EDGES,EDGELIST,NIL,NIL)
  . map!_$

symbolic procedure list!_of!_parents (edges,edgelist)$
if null edges then nil
else append(list!_of!_parent (car edges,edgelist),
            list!_of!_parents (cdr edges,edgelist))$

symbolic procedure list!_of!_parent (edge,edgelist)$
if p!_old!_edge edge or memq!_edgelist (edge,edgelist) then nil
               %IF EDGE IS DEF. THEN NO NEED IN ITS PARENTS
else
begin$
 scalar pr1,pr2,p,s$
 p:=s!_edge!_prop!_ edge$
 pr1:=assoc(car p,edgelist)$
 if pr1 then s:=pr1 . s$
 pr2:=assoc(cdr p,edgelist)$
 if pr2 then s:=pr2 . s$
%IF NULL PR1 OR NULL PR2 THEN
% SET!_ERROR (LIST!_OF!_PARENTS ,EDGE,EDGELIST)$
 return  s
end$

symbolic procedure actedge!_map!_ (edges,edgelist,old,new)$
if null edges then old . new
else
  if memq!_edgelist (car edges,edgelist) then
       actedge!_map!_ (cdr edges,edgelist,car edges . old,new)
  else actedge!_map!_ (cdr edges,edgelist,old,car edges . new) $

symbolic procedure actual!_edges!_world world1$
 mk!_world (actual!_world (s!_actual!_world1 world1,
                           s!_actual!_coeff
                              s!_coeff!_world1 world1),
            world1)$

symbolic procedure mk!_world1 (edges!-map!_,coeff,den!_om)$
 mk!_atlas (map!_2!_from!_map!_1 edges!-map!_,coeff,den!_om)$

symbolic procedure map!_2!_from!_map!_1 map!_1$
 list(map!_1!_to!_strand1 map!_1,
      list nil,
      mark!_edges (cdar map!_1,
                 % UNION!_EDGES(OLD!_EDGE!_LIST,CAAR MAP!_1),
                   caar map!_1,
                   cdr map!_1))$

symbolic procedure map!_1!_to!_strand1 map!_1$
car map!_1 .
pre!-calc!-map!_ (cdr map!_1,
                names!_edgepair map!_!_edges cdr map!_1)$

symbolic procedure names!_edgepair edgepair$
%NCONC(FOR EACH EDGE IN CAR EDGEPAIR COLLECT S!_EDGE!_NAME EDGE,
%      FOR EACH EDGE IN CDR EDGEPAIR COLLECT S!_EDGE!_NAME EDGE)$
       for each edge in edgepair collect s!_edge!_name edge $

symbolic procedure s!_actual!_world1 world1$
%RETURNS PAIR: OLDEDGES . NEWEDGES $
caar s!_atlas!_map!_ world1$

symbolic procedure actual!_world (map!_edges,coeffedges)$
%MAP!_EDGES IS A PAIR OLD . NEW,
%COEFFEDGES IS LIST OF ACTUAL EDGES OF COEEF.$
 union!_edges (car map!_edges,
               exclude!_edges (coeffedges,cdr map!_edges)) $

symbolic procedure s!_actual!_coeff worldlist$
if null worldlist then nil
else union!_edges (s!_edgelist!_world car worldlist,
                   s!_actual!_coeff cdr worldlist) $

symbolic procedure world!_from!_atlas atlas$
%TOP LEVEL PROCEDURE$
 constr!_worlds (atlas,old!_edge!_list )$


%END$  %cvit16.red
%^^^^^^^^^^^^^^^^^^^^^^^^^^ CALCULATION OF WORLDS ^^^^^^^^^^^^^^^^^^^ $
           %26.03.88$
lisp$

symbolic procedure s!_world!_names world$
for each edge in s!_world!_edges world
  collect s!_edge!_name edge$

symbolic procedure calc!_world (world,alst)$
% ALST LIST OF VALUES OF EXTERNAL EDGES: (... (EDGNAME . NUMBER) ...)$
begin
  scalar s,v$
  alst:=actual!_alst (alst,                    %SELECT ONLY THOSE
                      s!_world!_names world)$  %EDGES WICH ARE IN WORLD
  v:=s!_world!_var world $                     %SELECT DATA BASE
  s:=assoc(alst,cdr v)$                        %CALC. PREVIOSLY?
  if s then return cdr s$                      %PREV. RESULT$
  s:=reval
     calc!_atlas (s!_world!_atlas world,alst)$ %REAL CALCULATION
  nconc (v,list(alst . s))$                    %MODIFY DATA BASE
  return s
end$

symbolic procedure actual!_alst (alst,namelist)$
if null alst then nil
else
  if memq(caar alst,namelist) then
     car alst . actual!_alst (cdr alst,namelist)
  else actual!_alst (cdr alst,namelist)$

symbolic procedure calc!_atlas (atlas,alst)$
        calc!_map!_2d (s!_atlas!_map!_ atlas,
                     s!_atlas!_den!_om atlas,
                     s!_atlas!_coeff atlas,
                     alst) $

symbolic procedure calc!_coeff (worldlist,alst)$
if null worldlist then list 1
else
 (lambda x$
      if x=0 then list 0
      else x . calc!_coeff (cdr worldlist,alst))
  calc!_world (car worldlist,alst)$

symbolic procedure calc!_map!_2d (map!_2,den!_om,coeff,alst)$
coeff!_calc (mk!_names!_map!_2 caar map!_2 .
                             cdar map!_2 .
                             cadr map!_2 .
                             den!_om     ,
             coeff,
             mk!_binding (caddr map!_2,alst)) $

symbolic procedure mk!_names!_map!_2 edgespair$
% EDGESPAIR IS PAIR OF LISTS OF EDGES
%   EDGELISTOLD . EDGELISTNEW         $
for each edge in append(car edgespair,cdr edgespair)
    collect s!_edge!_name edge$

symbolic procedure calc!_coeffmap!_ (s,coeff,alst)$
(lambda z$
    if z = 0 then 0
    else 'times . (z . calc!_coeff (coeff,alst)))
 calc!_map!_ (s,alst)$

symbolic procedure calc!_map!_ (mvd,alst)$
begin
  scalar map!_,v,names,s,den!_om,al,d$
  names:=car mvd$                              %NAMES OF ALL EDGES
  map!_:=cadr mvd$                               %SELECT MAP!_
  v:=caddr mvd$                                %SELECT DATA BASE
  den!_om:=cdddr mvd$                            %SELECT DEN!_OMINATOR
  al:=actual!_alst (alst,names)$               %ACTUAL ALIST
  if null al and names then return 0$          %NO VARIANTS OF
                                               %COLOURING
  s:=assoc(al,cdr v)$                          %PREV.CALCULATED?
  if s then  s:=cdr s                          %YES, TAKE IT
  else <<                                      %ELSE
       s:=reval calc!_map!_tar (map!_,al)$         %REAL CALCULATION
       nconc(v,list(al . s))                   %MODIFY DATA BASE
       >>  $
  d:=calc!_den!_tar (den!_om,alst)$                %CALC. DEN!_OMINATOR
  return
        if d = 1 then s
        else list('quotient,s,d)               % 09.06.90 RT
end$

%SYMBOLIC PROCEDURE CALC!_MAP!_TAR (MAP!_,BINDING)$
%1$

%SYMBOLIC PROCEDURE CALC!_DEN!_TAR (DEN!_OMINATOR,BINDING)$
%1$

symbolic procedure coeff!_calc (s,coeff,binding)$
%S IS EDGENAMES . MAP!_ . DATABASE . DEN!_OMINATOR $
 reval
     ('plus . coeff1!_calc (s,coeff,binding))$

symbolic procedure coeff1!_calc (s,coeff,binding)$
if null binding then list 0
else calc!_coeffmap!_ (s,coeff,car binding) .
     coeff1!_calc (s,coeff,cdr binding) $

%TOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOP$

symbolic procedure calc!_spur0 u$
begin
 scalar s$
 if null u then return u$
 s:=transform!_map!_ u$
 old!_edge!_list := !_0edge . old!_edge!_list $
 s:=find!_bubltr s$
 return
        calc!_world (world!_from!_atlas s,
                     for each edge in old!_edge!_list
                         collect s!_edge!_name edge .
                                 car s!_edge!_prop!_ edge )
end$

symbolic procedure calc!_spur u$
 simp!* calc!_spur0 u$                %FOR KRYUKOV NEEDS$

endmodule$

end;
