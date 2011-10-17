module cvit;   % Header module for CVIT package.

% Authors:  A.Kryukov, A.Rodionov, A.Taranov.

% Copyright (C) 1988,1990, Institute of Nuclear Physics, Moscow State
%                          University.
% VERSION   2.1
% RELEASE   11-MAR-90

% 07.06.90 all MAP replaced by MAP_   RT
% 08.06.90 SOME MACROS FROM CVITMAP FILE ADDED to section IV RT
% 10.06.90 SOME MACROS FROM CVITMAP FILE ADDED  RT

% Modifications for Reduce 3.4.1 by John Fitch.

create!-package('(cvit red2cvit map2strn evalmaps intfierz cvitmap),
                '(contrib physics));

% The High Energy Physics package must be loaded first.

load_package hephys;

% These fluids and globals have been moved here for cleaner compilation.

  fluid  '(!*msg ndims!* dindices!*)$
  global '(windices!* indices!* !*cvit gamma5!* !*g5cvit)$
  if null windices!*
    then windices!*:=
            '(nil !_f0 !_f1 !_f2 !_f3 !_f4 !_f5 !_f6 !_f7 !_f8 !_f9)$

  if null gamma5!*
    then gamma5!*:=
            '(nil !_a0 !_a1 !_a2 !_a3 !_a4 !_a5 !_a6 !_a7 !_a8 !_a9)$

%GGGGGGGGGGGGGGGGGGGGGGGGG GLOBALS & FLUIDS FFFFFFFFFFFFFFFFFFFFFFFFF$


 global '( !_0edge)$

 fluid '( new_edge_list old_edge_list )$

      % NEW_EDGE_LIST - LIST OF CREATED EDGES$
      % OLD_EDGE_LIST - LIST OF INITIAL EDGES$

 fluid '(n_edge)$

      % N_EDGE - NUMBER OF CREATED EDGES$

% The following smacros need only be present during compilation.

  %************ SECTION I ************************************

  smacro   procedure hvectorp x$
     get(x,'rtype) eq 'hvector$

  smacro   procedure windexp x$
     x memq car windices!*$

  smacro   procedure replace_by_indexp v$
     get(v,'replace_by_index)$

  smacro   procedure indexp i$
     i memq indices!*$

  smacro   procedure replace_by_vectorp i$
     get(i,'replace_by_vector)$

  smacro   procedure replace_by_vector i$
     get(i,'replace_by_vector) or i$

  smacro   procedure gamma5p x$
     memq(x,car gamma5!*)$

  smacro   procedure nospurp x$
     flagp(x,'nospur)$

  smacro   procedure clear_gamma5()$
     gamma5!* := nil . append(reverse car gamma5!*,cdr gamma5!*)$

%********************* SECTION II **************************

symbolic smacro procedure p_empty_map_ map_$
% IS MAP_ EMPTY ? $
    null map_$

symbolic smacro procedure p_empty_vertex vertex$
% IS VERTEX EMPTY ? $
    null vertex$

%++++++++++++++++++++++++++ SELECTORS +++++++++++++++++++++++++++++++$

symbolic smacro procedure s_vertex_first map_$
% SELECT FIRST VERTEX IN MAP_ $
  car map_$

symbolic smacro procedure s_map__rest map_$
% SELECT TAIL OF MAP_ $
  cdr map_$

symbolic smacro procedure s_vertex_second map_$
% SELECT SECOND VERTEX IN MAP_ $
  s_vertex_first s_map__rest map_$

symbolic smacro procedure first_edge vertex$
% SELECT FIRST EDGE IN VERTEX $
  car vertex$

symbolic smacro procedure s_vertex_rest vertex$
% SELECT TAIL OF VERTEX $
  cdr vertex$

symbolic smacro procedure second_edge vertex$
% SELECT SECOND EDGE IN VERTEX $
  first_edge s_vertex_rest vertex$

symbolic smacro procedure s_edge_name edge$
% SELECT EDGE'S NAME $
  car edge$

symbolic smacro procedure s_edge_prop_ edge$
% SELECT PROP_ERTY OF AN EDGE (NAMES OF PARENTS OR NUMBERS)$
  cadr edge$

symbolic smacro procedure s_edge_type edge$
% SELEC TYPE (PARITY) OF AN EDGE$
  caddr edge$

%?????????????????????? CONSTRUCTORS ??????????????????????????????$

symbolic smacro procedure add_vertex (vertex,map_)$
% ADD VERTEX TO MAP_ $
  vertex . map_ $

symbolic smacro procedure add_edge (edge,vertex)$
% ADD EDGE TO VERTEX$
  edge . vertex$

symbolic smacro procedure append_map_s (map_1,map_2)$
% APPEND TWO MAP_S  $
  append(map_1,map_2)$

symbolic smacro procedure conc_map_s (map_1,map_2)$
% APPEND TWO MAP_S  $
 nconc(map_1,map_2)$

symbolic smacro procedure conc_vertex (vertex1,vertex2)$
% APPEND TWO VERTICES
 nconc(vertex1,vertex2)$

symbolic smacro procedure mk_name1 name$
 explode name$

symbolic smacro procedure mk_edge_prop_ (prop_1,prop_2)$
 prop_1 . prop_2 $

symbolic smacro procedure mk_edge_type (typ1,typ2)$
% DEFINED EDGE <=> TYPE T,
% UNDEFINED EDGE <=> TYPE NIL$
    typ1 and  typ2 $

symbolic smacro procedure mk_edge (name,prop_,type)$
% MAKE UP NEW EDGE $
 list(name,prop_,type)$

symbolic smacro procedure mk_edge3_vertex (edge1,edge2,edge3)$
% MAKES PRIMITIVE VERTEX  $
  list(edge1,edge2,edge3)$

symbolic smacro procedure mk_empty_map_ ()$
% GENERATE EMPTY MAP_ $
  nil $

symbolic smacro procedure mk_empty_vertex ()$
% GENERATE EMPTY VERTEX $
  nil $

symbolic smacro procedure mk_vertex1_map_ vertex1$
% MAKE MAP_ OF ONE VERTEX $
  list(vertex1)$

symbolic smacro procedure mk_vertex2_map_ (vertex1,vertex2)$
% MAKE MAP_ OF TWO VERTICES $
  list(vertex1,vertex2)$

symbolic smacro procedure mk_edge2_vertex (edge1,edge2)$
%MAKES VERTEX FROM TWO EDGES$
  list(edge1,edge2)$

 symbolic smacro procedure conc_vertex (vertex1,vertex2)$
  nconc(vertex1,vertex2)$

symbolic smacro procedure cycl_map_ map_$
% MAKES CYCLIC PERMUTATION OF MAP_$
    append(cdr map_,list car map_)$

symbolic smacro procedure cycl_vertex vertex$
% MAKES CYCLIC PERMUTATION OF VERTEX$
    append(cdr vertex,list car vertex)$

symbolic smacro procedure mk_world (actedges,world1)$
  list(actedges,list nil,world1)$

%====================== PREDICATES (CONTINUE) =====================$

symbolic smacro procedure p_member_edge (edge,vertex)$
% IS EDGE (WITH THE SAME NAME) CONTAINS IN VERTEX ?$
  assoc(s_edge_name edge,vertex)$

symbolic smacro procedure equal_edges (edge1,edge2)$
% IF EDGES HAVE THE SAME NAMES ? $
  eq   ( s_edge_name edge1, s_edge_name edge2)$

symbolic smacro procedure single_no_parents edges$
 length edges = 1 $

symbolic smacro procedure resto_map__order map_$
% REVERSE (BETTER REVERSIP) MAP_ $
  reverse map_$

symbolic smacro procedure map__length map_$
% NUMBER OF VERTICES IN MAP_$$
  length map_$

symbolic smacro procedure vertex_length vertex$
% NUMBER OF EDGES IN VERTEX $
  length vertex$

symbolic smacro procedure prepare_map_ map_$
 for each x in map_
  collect mk_old_edge x$

symbolic smacro procedure p_vertex_prim vertex$
% IS VERTEX PRIMITIVE ? $
  vertex_length (vertex) <= 3 $

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

symbolic smacro procedure reverse_map_ map_$
  reverse map_$

symbolic smacro procedure mk_edge1_vertex edge$
 list edge$

symbolic smacro procedure mk_edges_vertex edges$
  edges$

symbolic smacro procedure reversip_vertex vertex$
  reversip vertex$

symbolic smacro procedure append_vertex (vertex1,vertex2)$
   append(vertex1,vertex2)$

%symbolic smacro procedure conc_vertex (vertex1,vertex2)$
% nconc(vertex1,vertex2)$

symbolic smacro procedure mk_edge4_vertex (edge1,edge2,edge3,edge4)$
  list(edge1,edge2,edge3,edge4)$

symbolic smacro procedure p_old_edge edge$
 assoc(s_edge_name edge,old_edge_list )$


symbolic smacro procedure s_atlas_map_ atlas$
 car atlas$

symbolic smacro procedure s_atlas_coeff atlas$
 cadr atlas$

symbolic smacro procedure s_atlas_den_om atlas$
 caddr atlas$

symbolic smacro procedure mk_atlas (map_,atlases,den_om)$
 list(map_,atlases,den_om)$

symbolic smacro procedure vertex_edges edge$
  edge$

symbolic smacro procedure s_coeff_world1 world1$
 cadr world1 $

symbolic smacro procedure s_edgelist_world world$
 car world$

symbolic smacro procedure s_world1 world$
 caddr world $


symbolic smacro procedure s_world_var world$
 cadr world$

symbolic smacro procedure s_world_atlas world$
  caddr world$

symbolic smacro procedure s_world_edges world$
 car world$

endmodule;


module red2cvit;

% COPYRIGHT (C) 1988,1990,INSTITUTE OF NUCLEAR PHYSICS,MOSCOW STATE
%                          UNIV.
% PURPOSE   INTERFACE BETWEEN REDUCE AND CVITANOVICH ALGORITHM.
% AUTHOR    A.KRYUKOV
% VERSION   2.1
% RELEASE   11-MAR-90

  exports isimp1,replace_by_vector,replace_by_vectorp,gamma5p$
  imports calc_spur,isimp2$

  switch cvit$               % CVITANOVICH ALGORITHM SWITCH
  !*cvit := t$               % DEFAULT ON

  %************ ISIMP1 REDEFINITION ************************

  remflag('(isimp1),'lose)$

  symbolic procedure isimp1(u,i,v,w,x)$
     if null u then nil
      else if domainp u
         then if x then multd(u,if !*cvit
                                  then calc_spurx (i,v,w,x)
                                  else spur0 (car x,i,v,w,cdr x)
                             )
               else if v then multd(u,index_simp (1,i,v,w))
               else if w then multfs(emult w,isimp1(u,i,v,nil,nil))
               else u
      else addfs(isimp2(car u,i,v,w,x),isimp1(cdr u,i,v,w,x))$

  flag('(isimp1),'lose)$

  %************* INDEX_SIMP *******************************

  symbolic procedure index_simp (u,i,v,w)$
     if v then index_simp (multf(mksprod(caar v,cdar v),u),
                           update_index (i,car v),cdr v,w)
       else isimp1(u,i,nil,w,nil)$

  symbolic procedure mksprod(x,y)$
     mkdot(if indexp x then replace_by_vector x else x,
           if indexp y then replace_by_vector y else y)$

  symbolic procedure update_index (i,v)$
     % I  - LIST OF UNMATCH INDICES
     % V  - PAIR: (I/V . I/V)
     % VALUE - UPDATE LIST OF INDICES
     delete(cdr v,delete(car v,i))$

  %************ CALC_SPURX - MAIN PROCEDURE ***************

  symbolic procedure calc_spurx (i,v,w,x)$
     % I - LIST OF INDICES
     % V - LIST OF SCALAR PRODUCT:(<I/V> . <I/V>)
     % W - EPS-EXPR
     % X - LIST OF SPURS
     % VALUE - CALCULATED SPUR(S.F.)
     begin scalar u,         % SPUR: (LNAME G5SWITCH I/V I/V ... )
                  x1,        % (UN ... U1)
                  dindices!*,% A-LIST OF DUMMY INDICES: (I . NIL/T)
                  c$          % COEFFICIENT GENERATIED BY GX*GX
           if numberp ndims!* and null evenp ndims!*
             then cviterr list('calc_spur,":",ndims!*,
                     "is not even dimension of G-matrix space")$
           c := 1$            % INITIAL VALUE
           while x
             do << if nospurp caar x
                     then cviterr list "Nospur not yet implemented"$
                   u := cdar x$
                   x := cdr x$
                   if car u
                     then if evenp ndims!*
                            then u := next_gamma5() . reverse cdr u
                            else cviterr
                                   {"G5 invalid for non even dimension"}
                     else u := reverse cdr u$
                   if null u then nil                 % SP()
                     else if null evenp
                        length(if gamma5p car u and cdr u then cdr u
                                else u)
                            then x := c := nil        % ODD - VALUE=0
                     else << u := remove_gx!*gx u$
                             c := multf(car u,c)$
                             u := replace_vector(cdr u,i,v,w)$
                             i := cadr u$
                             v := caddr u$
                             w := cadddr u$
                             if u then x1 := car u . x1
                          >>
                >>$
           x1 := if null c then nil ./ 1         % ZERO
                   else if x1 then multsq(c ./ 1,calc_spur x1)
                   else c ./ 1$
           if denr x1 neq 1 then cviterr list('calc_spurx,":",x1,
                                    "has non unit denominator")$
           clear_windices ()$
           clear_gamma5 ()$
           return isimp1(numr x1,i,v,w,nil)
     end$

  symbolic procedure third_eq_indexp i$
     begin scalar z$
           if null(z := assoc(i,dindices!*))
             then dindices!* := (i . nil) . dindices!*
             else if null cdr z
                    then dindices!* := (i . t) . delete(z,dindices!*)$
           return if z then cdr z else nil
     end$

  symbolic procedure replace_vector(u,i,v,w)$
     % U  - SPUR (INVERSE)
     % I  - LIST OF UNMATCH INDICES
     % V  - A-LIST OF SCALAR PRODUCT
     % W  - EPS-EXPRESION
     % VALUE - LIST(U,UPDATE I,UPDATE V,UPDATE W)
     begin scalar z,y,x,    % WORK VARIABLES
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
                                         then cviterr
                                            list "G5 bad structure"
                                       else replace_by_index (x,z)
                                  >>$
                             u1 := z . u1
                          >>
                     else if gamma5p z then u1 := z . u1
                     else << z := replace_by_index (z,next_windex())$
                             u1 := z . u1
                          >>
                >>$
           return list(reverse u1,i,v,w)
     end$

  symbolic procedure replace_by_index (v,y)$
     begin scalar z$
           if (z := replace_by_vectorp y) eq v
             then cviterr list('replace_by_index,":",y,
                              "is already defined for vector",z)$
           put(y,'replace_by_vector ,v)$
           return y
     end$

  symbolic procedure remove_gx!*gx u$
     begin scalar x,c$
           integer l,l1$
           c := 1$
           l1 := l := length u$
           u := for each z in u                  % MAKE COPY
                  collect << if indexp z then
                               if third_eq_indexp z
                                 then cviterr
                                       list("Three indices have name",z)
                                 else nil
                               else if null hvectorp z then
                                      if cvitdeclp(z,'vector)
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
                          rplaca(u,caddr u)$    % YES - DELETE
                          rplacd(u,cdddr u)$
                          l1 := l := l - 2
                       >>
                  else << u := cdr u$            % NO - CHECK NEXT PAIR
                          l1 := l1 - 1
                       >>$
           x := cdr u$
           rplacd(u,nil)$                        % CUT CYCLE
           return (c . if cdr x and car x eq cadr x then nil else x)
     end$

  %************* ERROR,MESSAGE *****************************

  symbolic procedure cviterr u$
     << clear_windices()$
        clear_gamma5()$
        if u then rederr u else error(0,nil) >>$

  symbolic procedure cvitdeclp(u,v)$
     if null !*msg then nil
       else if terminalp()
              then yesp list("Declare",u,v,"?")
       else << lprim list(u,"Declare",v)$ t >>$

  %*********** WORK INDICES & VECTOR ***********************

  symbolic procedure clear_windices ()$
     while car windices!*
       do begin scalar z$
             z := caar windices!*$
             windices!* := cdar windices!* . z . cdr windices!*$
             remprop(z,'replace_by_vector)$
             indices!* := delete(z,indices!*)$
          end$

  symbolic procedure next_windex()$
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

  symbolic procedure next_gamma5()$
     begin scalar v$
           cviterr list "GAMMA5 is not yet implemented. use OFF CVIT";
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

endmodule;


module map2strn;

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
 cstimes(u,nil)$

symbolic procedure cstimes(u,s);
if null u then
  if null s then 1
  else if null cdr s then car s
       else 'times . s
else if car u = 1 then cstimes(cdr u,s)
     else cstimes(cdr u,car u . s)$

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
 csplus(u,nil)$

symbolic procedure csplus(u,s);
if null u then
  if null s then 0
  else if null cdr s then car s
       else 'plus . s
else if car u = 0 then csplus(cdr u,s)
     else csplus(cdr u,car u . s)$

%--------------------------------------------------------------------



%---------------- CONVERTING OF MAP TO STRAND DIAGRAM ---------------$

symbolic procedure map_!-to!-strand(edges,map_)$
%.....................................................................
% ACTION: CONVERTS "MAP_" WITH "EDGES" INTO STRAND DIAGRAM.
% STRAND ::= <LIST OF STRAND VERTICES>,
% STRAND VERTEX ::= <SVERTEX NAME> . (<LIST1 OF ROADS> <LIST2 ...>),
% ROAD ::= <ATOM> . <NUMBER>.
% LIST1,2 CORRESPOND TO OPPOSITE SIDES OF STRAND VERTEX.
% ROADS LISTED CLOCKWISE.
%....................................................................$
if null edges then nil
else mk!-strand!-vertex(car edges,map_) .
                                map_!-to!-strand(cdr edges,map_)$

%YMBOLIC PROCEDURE MAP_!-TO!-STRAND(EDGES,MAP_)$
%F NULL EDGES THEN NIL
%LSE (LAMBDA SVERT$ IF SVERT THEN SVERT .
%                               MAP_!-TO!-STRAND(CDR EDGES,MAP_)
%                   ELSE MAP_!-TO!-STRAND(CDR EDGES,MAP_) )
%          MK!-STRAND!-VERTEX(CAR EDGES,MAP_)$

symbolic procedure mk!-strand!-vertex(edge,map_)$
begin
  scalar vert1,vert2,tail$
         tail:=incident(edge,map_,1)$
         vert1:=car tail$
         tail:=incident(edge,cdr tail,add1 cdar vert1)$
         vert2:= if null tail then mk!-external!-leg edge
                 else car tail$
   return %F NULL VERT2 THEN NIL
               mk!-strand!-vertex2(edge,vert1,vert2)
end$

symbolic procedure incident(edge,map_,vertno)$
if null map_ then nil
else (lambda z$ if z then  z . cdr map_
                else incident(edge,cdr map_,add1 vertno) )
             incident1(              edge,car map_,vertno)$

symbolic procedure incident1(edname,vertex,vertno)$
if eq(edname,s!-edge!-name car vertex) then
             mk!-road!-name(cadr vertex,caddr vertex,vertno)
else if eq(edname,s!-edge!-name cadr vertex) then
         mk!-road!-name(caddr vertex,car vertex,vertno)
     else if eq(edname,s!-edge!-name caddr vertex) then
                 mk!-road!-name(car vertex,cadr vertex,vertno)
          else nil$

symbolic procedure mk!-strand!-vertex2(edge,vert1,vert2)$
list(edge,   vert1,             vert2)$

%------------------ COLOURING OF ROADS IN STRAND --------------------$

symbolic procedure color!-strand(alst,map_,count)$
%.....................................................................
% ACTION: GENERATE REC. ALIST COLORING STRAND, CORRESPONDING TO "MAP_".
% COLORING OF STRAND INDUCED BY "MAP_" COLORING, DEFINED BY ALIST
% "ALST". "COUNT" COUNTS MAP_ VERTICES. INITIALLY IS 1.
% REC.ALIST::= ( ... <(ATOM1 . COL1 ATOM2 . COL2 ...) . NUMBER> ... )
% WHERE COL1 IS COLOR OF ROAD=ATOM1 . NUMBER.
%....................................................................$
if null map_ then nil
else  (color!-roads(alst,car map_) . count) .
                          color!-strand(alst,cdr map_,add1 count)$

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
% ACTION: DELETES FROM "STRAND" VERTICES WITH NAMES HAVING 0-COLOR
% VIA MAP_-COLORING ALIST "ALST".
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

symbolic procedure contr2!-strand(st,rname,rand,flag_)$
if null st then rand
else (lambda z$
          if z then
            if member(car z,cdr z) then sappend(st,rand)  % 16.12 ****$
            else
                if null flag_ then
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
     else split!-road(single,car st) . contr2(single,cdr st,rand)$

symbolic procedure contr(single,strand)$
if null strand then nil
else split!-road(single,car strand) . contr(single,cdr strand)$

symbolic procedure split!-road(single,svertex)$
list(car svertex,
sroad(car single,cdr single,cadr svertex),
             sroad(car single,cdr single,caddr svertex))$

symbolic procedure sroad(line_,lines,lst)$
if null lst then nil
else if line_ = car lst then sappend(lines,cdr lst)
     else car lst . sroad(line_,lines,cdr lst)$

endmodule;


module evalmaps;  % Interaction with alg mode: variant without nonlocs;

  exports    strand!-alg!-top $
  imports    color!-strand,contract!-strand $

%------------------ AUXILIARY ROUTINES -----------------------------$

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

symbolic procedure strand!-alg!-top(strand,map_,edlst)$
begin
  scalar rlst$
      strand:=deletez1(strand,edlst)$
      rlst:=color!-strand(edlst,map_,1)$
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
      return (list replace_by_vector car rname) . dump$
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
begin scalar strand,edges,edgelsts,map_,w$
    edges:=car x$
    map_:=cadr x$
    edgelsts:=cddr x$
    strand := map_!-to!-strand(edges,map_)$
    w:= for each edlst in edgelsts collect
             strand!-alg!-top(strand,map_,edlst)$
    return reval('plus . w )
end$

symbolic procedure top1 x$
mathprint from!-rodionov to_taranov x$

%----------------------- COMBINATORIAL COEFFITIENTS -----------------$

symbolic procedure f!^(n,m)$
if n<m then cviterr "Incorrect args of f!^"
else if n = m then 1
     else n*f!^(sub1 n,m)$

%% This exists in basic REDUCE these days -- JPff
%%symbolic procedure factorial n$
%%f!^(n,0)$

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
       %      denr:=f!^(pk+k,k)*(cadar u)$
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


      return
        cvitimes2(car vrtx,
                  consplus (for each trm in cdr vrtx collect
                            cvitimes2(car trm,
                                      dstr!-to!-alg(cdr strand,rlst,
                                                    cdr trm))))$
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

endmodule;


module intfierz; % Interface with Rodionov-Fierzing Routine.

  exports  calc_map_tar,calc_den_tar,pre!-calc!-map_ $
  imports    mk!-numr,map_!-to!-strand $

lisp$

%----------- DELETING VERTS WITH _0'S ------------------------------$

%symbolic procedure sort!-map_(map_,tadepoles,deltas,s)$
%if null map_ then list(s,tadepoles,deltas)
%else
%  begin
%     scalar vert,edges$
%            vert:=incident1('!_0,car map_,'ll)$
%   return
%       if null vert then sort!-map_(cdr map_,tadepoles,deltas,
%                                                car map_ . s)
%       else if car vert = cadr vert then
%                sort!-map_(cdr map_,caar vert . tadepoles,deltas,s)
%            else sort!-map_(cdr map_,tadepoles,list('cons,caar vert,
%                                    caadr vert) . deltas,s)
% end$
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% modified 17.09.90 A.Taranov %%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
symbolic procedure sort!-map_(map_,tadepoles,deltas,poles,s)$
% tadepoles are verts with 1 0_ edge and contracted others
% deltas are verts with 1 0_ edge
% poles are verts with at list 2 0_ edges
if null map_ then list(s,tadepoles,deltas,poles)
else
  begin
  scalar vert,tdp$
    vert:=incident1('!_0,car map_,'ll)$
    if null vert then tdp:=tadepolep car map_
    else %%%% vertex contain !_0 edge
      return
        if (caar vert = '!_0) then
          sort!-map_(cdr map_,tadepoles,deltas,caadr vert . poles,s)
        else if (caadr vert = '!_0) then
             sort!-map_(cdr map_,tadepoles,deltas,caar vert . poles,s)
             else if car vert = cadr vert then
                    sort!-map_(cdr map_,caar vert . tadepoles,deltas,
                                poles,s)
                  else sort!-map_(cdr map_,tadepoles,list('cons,
                                   caar vert,caadr vert) . deltas,poles,
                                   s)$
   %%%%% here car Map_  was checked to be a real tadpole
   return
     if null tdp then sort!-map_(cdr map_,tadepoles,deltas,
                                        poles,car map_ . s)
     else sort!-map_(cdr map_,cadr tdp . tadepoles,deltas,
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

%--------------- EVALUATING MAP_S -----------------------------------$

symbolic procedure pre!-calc!-map_(map_,edges)$
% : (STRAND NEWMAP_ TADEPOLES DELTAS)$
begin
  scalar strand,w$
         w:=sort!-map_(map_,nil,list 1,nil,nil)$

%        delete from edge list deltas,poles and tades
         edges:=del!-deltas(caddr w,
                    del!-tades(cadr w,delete('!_0,edges)))$
         strand:= if car w then map_!-to!-strand(edges,car w)
                  else nil$
    return strand . w
end$


symbolic procedure calc_map_tar(gstrand,alst)$
% THIRD  VERSION.$
begin
 scalar poles,edges,strand,deltas,tades,map_$
        strand:=car gstrand$
        map_:=cadr gstrand$
        tades:=caddr gstrand     $
        deltas:=car cdddr gstrand $
        poles:= car cddddr gstrand $
 if ev!-poles(poles,alst) then   return 0;   %%%%% result is zero
 return constimes list(constimes deltas,
                      constimes ev!-tades(tades,alst),
                     (if null map_ then 1
                      else strand!-alg!-top(strand,map_,alst)))
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

symbolic procedure calc_den_tar(den_,alst)$
(lambda u$  if null u then 1
            else if null cdr u then car u
                 else constimes u           )
                                            denlist(den_,alst)$

symbolic procedure denlist(den_,alst)$
if null den_ then nil
else if length car den_ = 2 then
                   ev!-denom2(car den_,alst) . denlist(cdr den_,alst)
     else ev!-denom3(car den_,alst) . denlist(cdr den_,alst)$

endmodule;


module cvitmap;

  exports calc_spur$
  imports simp!*,reval,calc_map_tar ,calc_den_tar,spaces$

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
 % 07.06.90 all MAP was replaced by MAP_
 % 07.06.90 all DEN was replaced by DEN_
 % 07.06.90 all PROP was replaced by PROP_
 % SOME FUNCTIONS WAS MOVED TO SMACRO SECTION  08.06.90 10.06.90

%**********************************************************************
%                                                                     *
%                      _DATA_STRUCTURE                                *
%                                                                     *
%    WORLD::=(EDGELIST,VARIANTS,WORLD1)                               *
%    WORLD1::=(MAP_2,COEFF,DEN_OM)                                    *
%    MAP_2::=(MAP_S,VARIANTS,PLAN)                                    *
%    MAP_S::=(EDGEPAIR . GSTRAND)                                     *
%    MAP_1::=(EDGEPAIR . MAP_)                                        *
%    EDGEPAIR::=(OLDEDGELIST . NEWEDGELIST)                           *
%    COEFF::=LIST OF WORLDS (UNORDERED)                               *
%    ATLAS::=(MAP_,COEFF,DEN_OM)                                      *
%    MAP_::=LIST OF VERTICES (UNORDERED)                              *
%    VERTEX::=LIST OF EDGES (CYCLIC ORDER)                            *
%    VERTEX::=(NAME,PROP_ERTY,TYPE)                                   *
%    NAME::=ATOM                                                      *
%    PROP_ERTY::= (FIRSTPARENT . SECONDPARENT)                        *
%    TYPE::=T OR NIL                                                  *
%                                                                     *
%*********************************************************************$

%========================== PREDICATES =============================$


symbolic procedure is_indexp x$  % 01.09.90 RT
    (lambda z$
       z and cdr z)
     assoc(s_edge_name x,dindices!*)$

symbolic procedure mk_edge_name (name1,name2)$
% GENERATE NEW EDGE NAME $
<< n_edge := n_edge +1$
%INTERN COMPRESS APPEND(MK_NAME1 NAME1,
        compress append(mk_name1 name1,
                        append ( mk_name1 n_edge ,
                                 mk_name1 name2)) >> $

symbolic procedure new_edge (fedge,sedge)$
% GENERATE NEW EDGE $
begin
 scalar s$
 s:=
 mk_edge ( mk_edge_name ( s_edge_name fedge,
                          s_edge_name sedge),
            mk_edge_prop_ ( s_edge_name fedge,
                            s_edge_name sedge),
            mk_edge_type ( nil,
                           nil))$
 %          MK_EDGE_TYPE ( S_EDGE_TYPE FEDGE,
 %                         S_EDGE_TYPE SEDGE))$
 new_edge_list := s . new_edge_list $
 return s
 end$

symbolic procedure delete_vertex (vertex,map_)$
%DELETS VERTEX FROM MAP_$
if p_empty_map_ map_ then mk_empty_map_ ()
else
  if p_eq_vertex (vertex,s_vertex_first map_)
    then s_map__rest map_
  else
    add_vertex (s_vertex_first map_,
                 delete_vertex (vertex,s_map__rest map_))$

%====================== PREDICATES (CONTINUE) =====================$

symbolic procedure p_eq_vertex (vertex1,vertex2)$
% VERTICES ARE EQ IF THEY HAVE EQUAL NUMBER OF EDGES
% IN THE SAME ORDER WITH EQUAL _NAMES $
if p_empty_vertex vertex1 then p_empty_vertex vertex2
else
 if p_empty_vertex vertex2 then nil
 else
   if equal_edges (first_edge vertex1,
                    first_edge vertex2)
      then p_eq_vertex (s_vertex_rest vertex1,
                          s_vertex_rest vertex2)
   else nil$

%::::::::::::::::::::::: SOME ROUTINES :::::::::::::::::::::::::::::$

symbolic procedure mk_old_edge x$
 begin
  scalar s$
  s:=assoc(x,old_edge_list )$
  if s then return s$
  s:=mk_edge ( x,
                if not gamma5p x
                   then  mk_edge_prop_ (1,1)           %10.06.90 RT
                else     mk_edge_prop_ (ndim!*,ndim!*),
                mk_edge_type (t,t))$
 old_edge_list :=cons(s,old_edge_list )$
 return s
 end$

symbolic procedure change_name (name,edge)$
% CHANGES EDGE'S NAME $
mk_edge (name,
          s_edge_prop_ edge,
          s_edge_type edge )$

%======================= PREDICATES (CONTINUE) ================== $

symbolic procedure is_tadpole vertex$    %11.09.90 RT
% RETURNS T IF THERE IS ONLY ONE EXTERNAL LEG
    is_tadpolen(vertex) < 2$

symbolic procedure is_tadpolen vertex$    %11.09.90 RT
% RETURNS NUMBER OF EXTERNAL LEGS
  vertex_length diff_legs(vertex,mk_empty_vertex())$

symbolic procedure diff_legs(vertex,vertex1)$  %11.09.90 RT
% RETURNS LIST OF EXTERNAL LEGS
  if p_empty_vertex vertex then vertex1
  else  if p_member_edge(first_edge vertex,
                          s_vertex_rest vertex)
                      or
           p_member_edge(first_edge vertex,
                           vertex1)
           then diff_legs(s_vertex_rest vertex,vertex1)
         else  diff_legs(s_vertex_rest vertex,
                   add_edge(first_edge vertex,vertex1))$


symbolic procedure is_buble (vertex1,vertex2)$
% RETURNS NIL IF VERTEX1 AND VERTEX2 DOES NOT FORMED A BUBLE,
% OR N . MAP_ ,WHERE N IS A NUMBER OF EXTERNAL LINES ( 0 OR 2 ),
% MAP_ IS A MAP_ CONTAINING THIS BUBLE $
%NOT(IS_TADPOLE VERTEX1) AND NOT(IS_TADPOLE VERTEX2) AND  %14.09.90 RT
(lambda z$ if z >= 2 then nil
           else (2*z) . mk_vertex2_map_ (vertex1,vertex2))
vertex_length ( diff_vertex (vertex1,vertex2))$

%^^^^^^^^^^^^^^^^^^^^^^^ MAIN PROGRAM ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$

symbolic procedure transform_map_ map_$
% GENERATE SIMPLE MAP_ (ONLY PRIMITIVE VERTICES) FROM INITIAL ONE$
begin
 scalar n_edge$
 n_edge := 0$
 new_edge_list :=nil$
 old_edge_list :=nil$
return
mk_simple_map_
(for each vertex in map_ collect
   prepare_map_ vertex)$
end$


%,,,,,,,,,,,,,,,,,,,,,RODIONOV & TARANOV INTERFACE ,,,,,,,,,,,,,,,$

global '(bubltr freemap_)$

symbolic procedure to_taranov map_$
% MAP_ IS INITIAL MAP_,
% RETURNS (FULL LIST OF EDGES (INITIAL AND GENERATED) .
%         (MAP_ OF PRIMITIVE VERTICES )  .
%         (LIST OF ALL POSSIBLE ENUMERATION OF MAP_'S EDGES) $
begin
  scalar new_edge_list ,old_edge_list ,full_edge_list ,
         new_map_ ,free_map_ ,marks ,variants ,alst ,bubles$
  new_map_ :=transform_map_ map_$
  free_map_ :=find_bubltr new_map_ $
  bubles:=car free_map_ $
  bubltr:=bubles $
  free_map_ := cdr free_map_ $
  freemap_:=free_map_ $
  full_edge_list := for each edge in old_edge_list collect
                          s_edge_name edge $
  alst:=nconc(for each x in full_edge_list collect (x . 1) ,
              list('!_0 . 0) ) $                   %ADD EMPTY EDGE $
  marks:=set_mark (new_edge_list ,
                   nil,
                   buble_proves bubles,
                   new_map_ ,
                   add_tadpoles (bubles,alst))$
 variants:=edge_bind (marks,alst)$
  full_edge_list :=nconc (for each edge in new_edge_list collect
                              s_edge_name edge,
                          full_edge_list )$
return full_edge_list .
       new_map_ .
       variants
end$


 % TEST TEST TEST  TEST TEST TEST TEST TEST TEST TEST $
 % TO_TARANOV '((A B C C B A)) $


%END$    %cvit2.red
%********************************************************************
%                     NOW WE MARKED THE MAP_                        *
%*******************************************************************$

                  % 09.03.88  $
lisp$

global '(ndim!* )$

%ERROERRORERRORERRORERROR ERROR ROUTINES ERRORERRORERRORERRORERROR $

global '(!*cviterror)$

flag('(cviterror),'switch)$

!*cviterror:=t$           % IF T THEN ERROR MESSAGES WILL BE PRINTED$

% The FEXPR for set_error has been re-written by JPff
%%%  symbolic fexpr procedure set_error u$
%%%  if !*cviterror then set_error0 (u,alst)
%%%  else
%%%     error(55,"ERROR IN MAP_ CREATING ROUTINES")  $
symbolic macro procedure set_error u$
   list('set_error_real,mkquote cadr u,cons('list,cddr u))$

symbolic procedure set_error_real (u,v)$
<<
   if !*cviterror then <<
     prin2 "Function: "$
     prin2 car u$
     prin2 " Arguments: "$
     if v then for each x in v do <<
        prin2 x$ prin2 " IS " $
        prin2 x$
        terpri()  >>;
    >>;
    error(55,"Error in MAP_ creating routines")
>>$

%ERERERERERERERERERERERERERERERERERERERERERERERERERERERERERERERERE$

symbolic procedure mark_edges (newedges,oldedges,map_)$
  mk_proves (map_,oldedges) .
  set_mark (newedges,nil,nil,map_,
             for each x in oldedges collect (s_edge_name x .
                                             car s_edge_prop_ x ) ) $

symbolic procedure mk_proves (map_,oldedges)$
if p_empty_map_ map_ then nil
else
  if defined_vertex (s_vertex_first map_,oldedges) then
      s_vertex_first map_ .
      mk_proves (s_map__rest map_,oldedges)
  else
      mk_proves (s_map__rest map_,oldedges)$

symbolic procedure defined_vertex (vertex,oldedges)$
if p_empty_vertex vertex then t
else
 memq_edgelist (first_edge vertex,oldedges)
                and
 defined_vertex (s_vertex_rest vertex,oldedges)$

symbolic procedure set_mark (edges,notdef,toprove,map_,blst)$
% EDGES - LIST OF NEW EDGES CREATED WHILE MAKING A MAP_,
% NOTDEF - LIST OF EDGES WHICH CANNOT BE FULLY IDEN_TIFY,
% TOPROVE - LIST OF VERTICES FOR CHECKING TRIANGLE RULE,
% MAP_ - MAP_ CREATED EARLIER,
% BLST - ALIST OF BINDED EDGES$
if null edges then
    if notdef or toprove then          % 15.06.90 RT
                 set_error_real('set_mark,
                                list(edges,notdef,toprove,map_,blst))
    else nil
else
  (lambda z$
      if z then                  %THE EDGE IS FULLY DEFINED$
         set_prove (append(notdef,            %RESTOR LIST OF EDGES$
                            cdr edges),
                     car edges,
                     append(new_prove (car edges,    %ADD CHECKS$
                                        map_),
                            toprove),
                     map_,
                     (s_edge_name car edges . 0) .
                     blst)
     else
         set_mark (cdr edges,                   %TRY NEXT$
                    car edges . notdef,         % ADD NOT DEF. LIST$
                    toprove,
                    map_,
                    blst))
    ( assoc(caadar edges,blst)          %CHECK IF BOTH PARENT IS $
             and                        %ALREADY DEFINED         $
      assoc(cdadar edges,blst) ) $

symbolic procedure new_prove (edge,map_)$
% RETURNS NEW VERTEX FOR TRIANGLE RULE CHECKING LIST$
if null map_ then nil
else
  (lambda z$  if z then list z
              else new_prove (edge,cdr map_))
   new_provev (edge,car map_) $

 symbolic procedure new_provev (edge,vertex)$
 % CAN THIS VERTEX BE UTILIZED FOR CHECKING ? $
 if not member(edge,vertex) then nil
 else
  if (assoc(caadr edge,vertex)
           and
      assoc(cdadr edge,vertex))
    then nil
  else vertex $

symbolic procedure is_son (edge,vertex)$
 assoc(car s_edge_prop_ edge,vertex)$

symbolic procedure not_parents (edge,proves)$
if null proves then nil
else
  if is_son (edge,car proves)
     then cdr proves
  else car proves . not_parents (edge,cdr proves)$

symbolic procedure set_prove (edges,edge,toprove,map_,blst)$
% RETURNS A PAIR (EDGE . (LIST FOF VERICES FOR TRIANGLE RULE TEST))$
(lambda z$
   (edge . not_parents (edge,car z)) .
    set_mark (edges,nil,cdr z,map_,blst))
  find_proved (toprove,nil,nil,blst)$

symbolic procedure find_proved (toprove,proved,unproved,blst)$
% RETURNS A PAIR ((LIST OF ALREADY DEFINED VERTICES) .
%                 (LIST OF NOT YET DEFINED EDGES) ) $
if null toprove then proved . unproved
else
  if is_proved (car toprove,blst) then
                   find_proved (cdr toprove,
                                 car toprove . proved,
                                  unproved,
                                  blst)
  else             find_proved (cdr toprove,
                                 proved,
                                 car toprove . unproved,
                                 blst) $

symbolic procedure is_proved (vertex,blst)$
 if null vertex then t
 else if assoc(caar vertex,blst) then is_proved (cdr vertex,blst)
      else nil $

%@@@@@@@@@@@@@@@@@@@@@@@ NOW GENERATES ALL POSSIBLE NUMBERS @@@@@@@@$

symbolic procedure mk_binding (provedge,blst)$
 can_be_proved (car provedge,blst)
             and
 edge_bind (cdr provedge,blst)$

symbolic procedure edge_bind (edgelist,blst)$
if null edgelist then list blst
else
 begin
   scalar defedge,prop_,p,emin,emax,s,proves,i$
% DEFEDGE - EDGE WITH DEFINED RANG,
% PROP_ - ITS PROP_ERTY: (NUM1 . NUM2),
% P - ITS NAME,
% EMIN AND EMAX - RANGE OF P,
% S - TO STORE RESULTS,
% PROVES - CHECKS OF TRIANGLE LAW$
  defedge:=car edgelist$
  proves:=cdr defedge$
  defedge:=car defedge$
  edgelist:=cdr edgelist$
  p:=s_edge_name defedge$
  prop_:=s_edge_prop_ defedge$
  emin:=assoc(car prop_,blst)$
  emax:=assoc(cdr prop_,blst)$
 if null emin or null emax
   then set_error_real ('edge_bind,list(prop_,blst))$
 prop_:=(cdr emin) . (cdr emax)$
  emin:=abs((car prop_)-(cdr prop_))$
  emax:=(car prop_)+(cdr prop_)$
 if numberp ndim!* then              %NUMERICAL DIMENSIONAL$
    << emax:=min(emax,ndim!*)$
       if emin > ndim!* then return nil >> $
 i:=emin$
loop:
       if i > emax then return s$
       if can_be_proved (proves,(p . i) . blst)
         then s:=append(edge_bind (edgelist,
                                    (p . i) . blst),
                        s) $
       i:=i+2$
 go loop
end$

symbolic procedure can_be_proved (proves,blst)$
if null proves then t
else if can_be_p (car proves,blst) then
        can_be_proved (cdr proves,blst)
     else nil$

symbolic procedure can_be_p (vertex,blst)$
%CHECKS TRIANGLE RULE$
begin
  scalar i,j,k$
  i:=assoc(car car   vertex,blst)$
  j:=assoc(car cadr  vertex,blst)$
  k:=assoc(car caddr vertex,blst)$
  if null i or null j or null k then set_error_real('can_be_proved,
                                                     list(vertex,%%edge,
                                                     blst))$
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

symbolic procedure find_bubles atlas$
 find_bubles1 (atlas,old_edge_list )$

symbolic procedure find_bubles_coeff (atlaslist,edgelist,bubles)$
%F NULL BUBLES THEN NIL . ATLASLIST
%LSE
 find_bubles1_coeff (atlaslist,nil,edgelist,bubles)$

symbolic procedure find_bubles1_coeff (atlaslist,passed,edgelist,
                                                          bubles)$
if null atlaslist then bubles . passed
else
 (lambda z$             %Z - PAIR = (BUBLES . REDUCED MAP_)
    find_bubles1_coeff (cdr atlaslist,
                          cdr z . passed,
                          edgelist,
                          if null car z then bubles else
                          car z . bubles) )
  find_bubles1 (car atlaslist,edgelist) $

symbolic procedure mk_atlaslist (map_,coeff,den_om)$
 list mk_atlas (map_,coeff,den_om)$

symbolic procedure find_bubles1 (atlas,edgelist)$
  select_bubles (nil,
                 s_atlas_map_ atlas,
                 nil,
                 s_atlas_coeff atlas,
                 s_atlas_den_om atlas,
                 edgelist)$

symbolic procedure select_bubles(bubles,map_,passed,coeff,den_om,al)$
% RETURNS (LIST OF BUBLES ) . ATLAS,
% WHERE BUBLES ARE TWO OR ONE VERTICES MAP_S $
if p_empty_map_  map_ then
             (lambda x$
                     car x .
                           mk_atlas (passed,cdr x,den_om))
              find_bubles_coeff (coeff,
                                 union_edges (map__edges passed,
                                              al),
                                 bubles)
else
 if (map__length map_ + map__length passed) < 3 then
         select_bubles (bubles,
                        mk_empty_map_ (),
                        append_map_s(map_,
                                     passed),
                        coeff,
                        den_om,
                        al)
 else
  (lambda z$                          % Z IS NIL OR A PAIR
                                      % N . MAP_ ,WHERE
                                      % N - NUMBER OF FREE EDGES$
     if z then                                      %A BUBLE IS FIND$
      (lambda d$
       (lambda bool$              %BOOL=T IFF ALL EDGES CAN BE DEFINED$
      if car z = 0 then                             %NO EXTERNAL LINES$
       if bool then
        select_bubles ( z . bubles,
                         mk_empty_map_ (),
                         cdr z,
                         mk_atlaslist ( conc_map_s (passed,
                                                    delete_vertex (
                                                      s_vertex_second
                                                                cdr z,
                                                      s_map__rest
                                                                map_)),
                                         coeff,
                                         den_om),
                         nil,
                         al)
       else
        select_bubles ( z . bubles,               %ADD BUBLE$
                         delete_vertex (s_vertex_second cdr z,
                                         s_map__rest map_),
                         passed,
                         try_sub_atlas (mk_atlas (cdr z,
                                                  nil,
                                                  nil),
                                        coeff),
                         den_om,
                         al)
      else
       if not p_old_vertex d then
        if bool then
        select_bubles (z . bubles,
                        mk_empty_map_ (),
                        cdr z,
                        mk_atlaslist (conc_map_s (passed,
                                                  buble_vertex (
                                                    cdr z,
                                                    delete_vertex (
                                                     s_vertex_second
                                                        cdr z,
                                                     s_map__rest
                                                        map_ ),
                                                     al)),
                                       coeff,
                                       den_om),
                         list d,
                         al)
        else
        select_bubles ( z . bubles,               %ADD NEW BUBLE$
                        buble_vertex (cdr z,      %RENAME EDGES $
                             conc_map_s (passed,
                             delete_vertex (s_vertex_second cdr z,
                                            s_map__rest map_)),
                                        al),
                         mk_empty_map_ (),
                         try_sub_atlas (mk_atlas (cdr z,nil,list d),
                                        coeff),
                         den_om,
                         al)
       else
        if bool then
        select_bubles (z . bubles,
                        mk_empty_map_ (),
                        ren_vertmap_ (d,cdr z),
                        mk_atlaslist (
                          conc_map_s (
                            passed,
                            add_vertex (add_edge (!_0edge ,d),
                                        delete_vertex (
                                            s_vertex_second cdr z,
                                            s_map__rest map_ ))),
                          coeff,
                          den_om),
                        list ren_vertices (d,d),
                        al)
        else
        select_bubles (z . bubles,
                        add_vertex (add_edge (!_0edge ,d),
                                    delete_vertex(s_vertex_second cdr z,
                                                  s_map__rest map_)
                                    ),
                        passed,
                        try_sub_atlas (mk_atlas (ren_vertmap_
                                                    (d,cdr z),
                                                 nil,
                                                 list
                                                 ren_vertices (d,d)
                                                 ),
                                        coeff),
                        den_om,
                        al )
                                     )
   %      ALL_DEFINED (CDR Z,AL))
          t                           )
        delta_edges cdr z
     else
        select_bubles (bubles,
                       s_map__rest map_,
                       add_vertex (s_vertex_first map_,passed),
                       coeff,
                       den_om,
                       al )
                                )
   find_buble (s_vertex_first map_,
               s_map__rest map_ ) $

symbolic procedure p_old_vertex vertex$
% RETURNS T IFF ALL EDGES OF VERTEX ARE OLD OR VERTEX IS EMPTY ONE$
if p_empty_vertex vertex then t
else p_old_edge first_edge vertex
             and
     p_old_vertex s_vertex_rest vertex$

symbolic procedure renames_edges (vertex,al)$
rename_edges_par (first_edge vertex,
                    second_edge vertex,
                    al)$

symbolic procedure rename_edges_par (vertex1,vertex2,al)$
% Here VERTEX1 and VERTEX2 are edges!
if   defined_edge (vertex1,al)
     and not p_old_edge(vertex2)  then        % 14.09.90 RT
       replace_edge (vertex2,vertex1,new_edge_list )
else
  if defined_edge (vertex2,al)
     and not p_old_edge(vertex1)  then        % 14.09.90 RT
       replace_edge (vertex1,vertex2,new_edge_list )
  else
    if  p_old_edge (vertex1)
        and not p_old_edge(vertex2)  then        % 14.09.90 RT
         replace_edge (vertex2,vertex1,new_edge_list )
    else
      if p_old_edge (vertex2)
         and not p_old_edge(vertex1)  then        % 14.09.90 RT
          replace_edge (vertex1,vertex2,new_edge_list )
      else rename_edges (vertex1,vertex2)$

symbolic procedure buble_vertex (map_2,map_,al)$
if p_empty_map_ map_2 then mk_empty_map_ ()
else
  << renames_edges (delta_edges map_2,al)$
     map_ >> $

symbolic procedure delta_edges map_2$
% MAP_2 - MAP_ OF TWO VERTICES $
mk_edge2_vertex (
                   first_edge
                               diff_vertex (s_vertex_first map_2,
                                            s_vertex_second map_2),
                   first_edge
                               diff_vertex (s_vertex_second map_2,
                                            s_vertex_first map_2 )
                  )$

symbolic procedure delta_names map_2$
% MAP_2 - MAP_ OF TWO VERTICES $
(lambda z$
     s_edge_name first_edge car z .
     s_edge_name first_edge cdr z  )
 (diff_vertex (s_vertex_first map_2,
               s_vertex_second map_2) .
  diff_vertex (s_vertex_second map_2,
               s_vertex_first map_2) ) $

symbolic procedure old_rename_edges (names,map_)$
if p_empty_map_ map_ then mk_empty_map_ ()
else add_vertex (ren_edge (names,s_vertex_first map_),
                 old_rename_edges (names,
                                s_map__rest map_) ) $

symbolic procedure ren_vertmap_ (vertex1,map_)$
% VERTEX1 MUST BE TWO EDGE VERTEX,
% EDGES OF VERTEX2 TO BE RENAME$
if vertex_length vertex1 neq 2 then set_error_real ('ren_vertmap_  ,
                                                     list(vertex1,map_))
else old_rename_edges (s_edge_name first_edge vertex1 .
                       s_edge_name second_edge vertex1,
                       map_)$

symbolic procedure ren_vertices (vertex1,vertex2)$
% VERTEX1 MUST BE TWO EDGE VERTEX,
% EDGES OF VERTEX2 TO BE RENAME$
if vertex_length vertex1 neq 2
  then set_error_real ('ren_vertices,list(vertex1,vertex2))
else ren_edge (s_edge_name first_edge vertex1 .
               s_edge_name second_edge vertex1,
               vertex2)$

symbolic procedure ren_edge (names,vertex)$
% NAMES IS NAME1 . NAME2,
% CHANGE NAME1 TO NAME2$
if null assoc(car names,vertex) then vertex  %NO SUCH EDGES IN VERTEX$
else ren_edge1 (names,vertex)$

symbolic procedure ren_edge1 (names,vertex)$
if p_empty_vertex vertex then mk_empty_vertex ()
else if car names =s_edge_name first_edge vertex then
        add_edge ( change_name (cdr names,first_edge vertex),
                   ren_edge1 (names ,s_vertex_rest vertex))
     else
        add_edge ( first_edge vertex,
                   ren_edge1 (names,s_vertex_rest vertex))$

symbolic procedure find_buble (vertex,map_)$
if p_empty_map_ map_ then mk_empty_map_ ()
else
  is_buble (vertex,s_vertex_first map_)
  or
  find_buble (vertex,s_map__rest map_) $

symbolic procedure diff_vertex (vertex1,vertex2)$
if p_empty_vertex vertex1 then mk_empty_vertex ()
else
  if p_member_edge (first_edge vertex1,vertex2)
                    and
      not equal_edges (first_edge vertex1,!_0edge )
     then diff_vertex (s_vertex_rest vertex1,vertex2)
  else
    add_edge (first_edge vertex1,
              diff_vertex (s_vertex_rest vertex1,vertex2)) $

%SSSSSSSSSSSSSSSSSSSSSSSSSS NOW MAKES PROVES FROM BUBLE PPPPPPPPPPPPPP$

global '(!_0edge )$

!_0edge :=mk_edge ('!_0 ,
                   mk_edge_prop_ (0,0),
                   mk_edge_type (t,t)) $

symbolic procedure buble_proves bubles$
if null bubles then nil
else
  if caar bubles = 0                           %NO EXTERNAL LINES $
    then buble_proves cdr bubles
  else if caar bubles = 2 then
       mk_edge3_vertex (
                          first_edge diff_vertex (
                                      s_vertex_first cdar bubles,
                                      s_vertex_second cdar bubles),
                          first_edge diff_vertex (
                                      s_vertex_second cdar bubles,
                                      s_vertex_first cdar bubles),
                          !_0edge ) .
                                      buble_proves cdr bubles
        else
         if caar bubles = 3 then
               car cdar bubles .
                                 buble_proves cdr bubles
         else buble_proves cdr bubles $


symbolic procedure try_sub_atlas (atlas,atlaslist)$
if null atlaslist then list atlas
else
  if sub_map__p (s_atlas_map_ atlas,
                 s_atlas_den_om car atlaslist)
   then try_sub_atlas (mk_sub_atlas (atlas,car atlaslist),
%  THEN TRY_SUB_ATLAS (MK_SUB_ATLAS (CAR ATLASLIST,
%                                        ATLAS        ),
                         cdr atlaslist)
  else  car atlaslist .
        try_sub_atlas (atlas,cdr atlaslist)$

symbolic procedure sub_map__p (map_1,den_)$
%MAP_1 AND DEN_  HAVE COMMON VERTEX (DEN_ - DEN_OMINATOR)$
if p_empty_map_ map_1 then nil
else  sub_vertex_map_ (s_vertex_first map_1,den_)
                    or
      sub_map__p (s_map__rest map_1,den_)$

symbolic procedure sub_vertex_map_ (vertex,den_)$
if null den_ then nil
else p_common_den_ (vertex,car den_)
                  or
     sub_vertex_map_ (vertex,cdr den_)$

symbolic procedure  p_common_den_ (vertex,vertexd)$
(lambda n$
    if n = 3 then                                %TRIANGLE
             p_eq_vertex (vertex,vertexd)

    else
      if n = 2 then                              %KRONEKER
             p_member_edge (first_edge vertexd,vertex)
      else nil )
  vertex_length vertexd $

symbolic procedure mk_sub_atlas (atlas1,atlas2)$
 mk_atlas (s_atlas_map_ atlas1,
           atlas2 . s_atlas_coeff atlas1,
           s_atlas_den_om atlas1)$

symbolic procedure all_defined (map_,al)$
 all_defined_map_ (map_,
                   defined_append(map__edges map_,al))$

symbolic procedure all_defined_map_ (map_,al)$
 al1_defined_map_ (map_,mk_empty_map_ (),al)$

symbolic procedure al1_defined_map_ (map_,passed,al)$
% T IF ALL EDGES IN MAP_ CAN BE DEFINED $
if p_empty_map_ map_ then
 if p_empty_map_ passed then t
 else nil
else
 if all_defined_vertex (s_vertex_first map_,al) then
     al1_defined_map_ (conc_map_s(passed,s_map__rest map_),
                       mk_empty_map_ (),
                       append(vertex_edges s_vertex_first map_ ,al))
 else
     al1_defined_map_ (s_map__rest map_,
                       add_vertex (s_vertex_first map_,passed),
                       al)$

symbolic procedure all_defined_vertex (vertex,al)$
 al1_defined_vertex (vertex,mk_empty_vertex (),
                            mk_empty_vertex (),al)$

symbolic procedure al1_defined_vertex (vertex,passed,defined,al)$
% T IF ALL EDGES IN VERTEX CAN BE DEFINED $
if p_empty_vertex vertex then
 if p_empty_vertex passed then t
 else re_parents (passed,defined)
else
  if defined_edge (first_edge vertex,al)
                    then
     al1_defined_vertex (conc_vertex(passed,s_vertex_rest vertex),
                         mk_empty_vertex (),
                         add_edge (first_edge vertex,defined),
                         first_edge vertex . al)
  else
     al1_defined_vertex (s_vertex_rest vertex,
                         add_vertex (first_edge vertex,passed),
                         defined,
                         al)$

symbolic procedure re_parents (passed,defined)$
%TRY TO MAKE NEW PARENTS
if vertex_length passed = 1 and vertex_length defined = 2
  then make_new_parents (first_edge passed,defined)
else nil$

symbolic procedure make_new_parents (edge,vertex)$
%VERTEX CONSISTS OF TWO EDGES
 add_parents0 (edge,
               s_edge_name first_edge vertex .
               s_edge_name second_edge vertex ,
               t)$


%^.^.^.^.^.^.^.^.^.^.^.^.^.^.^..^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^
%          13.05.88


symbolic procedure p_def_edge edge$
 s_edge_type edge$
%P_OLD_EDGE EDGE$

symbolic procedure defined_edge (edge,al)$
  p_old_edge edge
      or
 defined_all_edge (all_edge (s_edge_name edge,new_edge_list ),
                   nil,
                   al) $

symbolic procedure all_edge (edgename,edgelist)$
if null edgelist then nil
else
  if edgename eq s_edge_name car edgelist then
                 car edgelist . all_edge (edgename,cdr edgelist)
  else all_edge (edgename,cdr edgelist)$

symbolic procedure def_edge (edge,al)$
(lambda z$
          assoc(car z,al) and assoc(cdr z,al))
 s_edge_prop_ edge$

symbolic procedure defined_all_edge (edgelist,passed,al)$
if null edgelist then nil
else
  if def_edge (car edgelist,al) then
    if p_def_edge car edgelist then t  %REPLACE WAS ALREADY DONE
    else  rep_edge_prop_ (nconc(passed,edgelist),
                          s_edge_prop_ car edgelist . list t)
  else defined_all_edge (cdr edgelist,
                         car edgelist . passed,
                         al)$

symbolic procedure rep_edge_prop_ (edgelist,prop_)$
if null edgelist then t
else << rplacd(car edgelist,prop_)$           %CHANGE EDGE PARENTS
        rep_edge_prop_ (cdr edgelist,prop_) >> $



%END$  %cvit6.red
%<><><><><><><><><><><> ROUTINES FOR SELECTING TRIANGLES <><><><><><>$
                            %24.05.88$

global '(!*cvitbtr !*cviterror)$

flag('(cvitbtr),'switch)$

!*cvitbtr:=t$           %IF T THEN BUBLES AND TRIANGLES  WILL BE
                        %     FACTORIZED

!*cviterror:=t$         %IF T THEN ERROR MESSAGES WILL BE PRINTED

symbolic procedure find_triangles atlas$
 find_triangles1 (atlas,old_edge_list)$

symbolic procedure find_triangles1 (atlas,al)$
 select_triangles (nil,
                   s_atlas_map_ atlas,
                   nil,
                   s_atlas_coeff atlas,
                   s_atlas_den_om atlas,
                   al)$

symbolic procedure find_triangl_coeff (atlaslist,edgelist,triangles)$
 find_triangle_coeff (atlaslist,nil,edgelist,triangles)$

symbolic procedure find_triangle_coeff(atlaslist,passed,edgelist,
                                         triangles)$
if null atlaslist then triangles . passed
else
 (lambda z$                 % Z - PAIR= (TRIANGLES . REDUCED MAP_)
     find_triangle_coeff (cdr atlaslist,
                          cdr z . passed,
                          edgelist,
                          if null car z then triangles
                          else car z . triangles))
  find_triangles1 (car atlaslist,edgelist)$

symbolic procedure select_triangles (triangles,map_,passed,
                                      coeff,den_om,al)$
%RETURNS A PAIR OF THE FORM ( (LIST OF TRIANGLES) . (ATL.WITHOUT TR.))$
if p_empty_map_ map_ then                       %No triangles found.
      (lambda x$
              car x .
              mk_atlas (passed,cdr x,den_om))
      find_triangl_coeff (coeff,
                          union_edges (map__edges passed,al),
                          triangles)
else
 if (map__length map_ + map__length passed) < 4 then
    select_triangles (triangles,
                      mk_empty_map_ (),
                      append_map_s (map_,passed),
                      coeff,
                      den_om,
                      al)
 else
 (lambda z$
    if z then                                    %TRIANGLE IS FOUND$
     (lambda trn$                                %TRN - NEW VERTEX $
     %IF ALL_DEFINED (CDDR Z,AL) THEN
      if t then
         select_triangles (
             z . triangles,
             mk_empty_map_ (),
             add_vertex (trn,cddr z),
             mk_atlaslist (
                  conc_map_s (
                      mk_vertex1_map_  trn,
                      conc_map_s (passed,delete_map_s (cddr z,map_))
                             ),
                  coeff,
%                 TRN . DEN_OM    ),
                  den_om    ),
%            NIL,
             list trn,
             al             )
       else
       select_triangles ( z . triangles,       %ADD NEW TRIANGLE $
 %     SELECT_TRIANGLES ( CDDR Z . TRIANGLES,  %ADD NEW TRIANGLE$
                           conc_map_s (mk_vertex1_map_
                                       trn,     %ADD NEW VERTEX$
                                       conc_map_s (passed,
                                                   delete_map_s(cddr z,
                                                                map_)
                                                  )
                                      ),
                          mk_empty_map_ (),
                          try_sub_atlas (
                              mk_atlas (add_vertex (trn,cddr z),
                                        nil,
                                        list trn),
                              coeff       ),
                          den_om,
                          al
                         )
                   )
      sk_vertextr z
    else
       select_triangles (triangles,
                         s_map__rest map_,
                         add_vertex (s_vertex_first map_,passed),
                         coeff,
                         den_om,
                         al
                         ) )
reduce_triangle
 find_triangle (s_vertex_first map_,
                s_map__rest map_) $

symbolic procedure vertex_neighbour (vertex,map_)$
%RETURNS A MAP_ OF VERTEX NEIGHBOURS $
if p_empty_vertex vertex
           or
   p_empty_map_ map_ then mk_empty_map_ ()
else
  (lambda z$             %Z - NIL OR A PAIR (EDGE . ADJACENT EDGE )$
     if z then
        add_vertex (cdr z,
                     vertex_neighbour (delete_edge (car z,vertex),
                                       delete_vertex (cdr z,map_)))
     else
        vertex_neighbour (vertex,s_map__rest map_))
   is_neighbour (vertex,
                  s_vertex_first map_)$

symbolic procedure delete_map_s (map_1,map_2)$
if p_empty_map_ map_1 then map_2
else delete_map_s (s_map__rest map_1,
                   delete_vertex (s_vertex_first map_1,map_2) ) $

symbolic procedure delete_edge (edge,vertex)$
%DELETES EDGE FROM VERTEX $
if p_empty_vertex vertex then mk_empty_vertex ()
else
  if equal_edges (edge,first_edge vertex)
   then s_vertex_rest vertex
  else
    add_edge (first_edge vertex,
               delete_edge (edge,
                            s_vertex_rest vertex ) ) $

symbolic procedure is_neighbourp (vertex1,vertex2)$
% ARE VERTEX1 AND VERTEX2 NEIGHBOURS ?
if p_empty_vertex vertex1 then nil         % NIL IF NOT NEIGHBOURS$
else
     p_member_edge (first_edge vertex1,vertex2)
                    or
     is_neighbourp (s_vertex_rest vertex1,vertex2)$

symbolic procedure is_neighbour (vertex1,vertex2)$
% ARE VERTEX1 AND VERTEX2 NEIGHBOURS ?
% IF THEY ARE THEN RETURN A PAIR: (ADJ.EDGE . VERTEX2)$
if p_empty_vertex vertex1 then nil         % NIL IF NOT NEIGHBOURS$
else
  (lambda z$
     if z then                   %FIRTS VERTEX IS ADJACENT TO VERTEX2$
          first_edge vertex1 . vertex2
     else is_neighbour (s_vertex_rest vertex1,
                         vertex2 ) )
   p_member_edge (first_edge vertex1,
                    vertex2)$

symbolic procedure find_triangle (vertex,map_)$
%FINDS TRIANGLE WICH INCLUDES THE VERTEX.
%RETURNS MAP_ OF THREE VERTICES (TRIANGLE) OR NIL $
(lambda z$               %Z - MAP_ OF VERTICES WICH ARE NEIGHBOURS
                         %  OF VERTEX OR (IF NO NEIGHBOURS) EMPTY MAP_$
   if map__length z neq 2 then nil
   else add_vertex (vertex,z) )
 is_closed vertex_neighbour (vertex,map_)$

symbolic procedure is_closed map_$
if p_empty_map_ map_   or
   p_empty_map_ s_map__rest map_ then mk_empty_map_ ()
else
    two_neighbour (s_vertex_first map_,
                    s_map__rest map_)
             or
    is_closed s_map__rest map_$

symbolic procedure two_neighbour (vertex,map_)$
% HAS VERTEX A NEIGHBOUR IN THE MAP_ ? $
if p_empty_map_ map_ then nil
else
 if is_neighbourp (vertex,s_vertex_first map_)
    then mk_vertex2_map_ (vertex,s_vertex_first map_)
 else two_neighbour (vertex,s_map__rest map_)$

symbolic procedure mk_vertextr map_$
%MAKES VERTEX FROM TRIANGLE MAP_$
if map__length map_ neq 3 then set_error_real ('mk_vertextr ,list(map_))
else
    mk_vertextr3 (map_,3)$

symbolic procedure add_edge1(edge,vertex)$ % 14.09.90 RT
 if null edge then vertex
 else add_edge(edge,vertex)$

symbolic procedure mk_vertextr3 (map_,n)$
if n <= 0 then mk_empty_map_ ()
else
  add_edge1 (take_edge (s_vertex_first map_,
                         s_map__rest map_),
             mk_vertextr3 (cycl_map_ map_,n-1)) $

symbolic procedure take_edge (vertex,map_)$
if p_empty_vertex vertex then nil    %14.09.90 RT
% SET_ERROR ('TAKE_EDGE ,VERTEX,MAP_)    % 14.09.90  RT
else
%  IF P_EMPTY_VERTEX S_VERTEX_REST VERTEX THEN FIRST_EDGE VERTEX
%  ELSE                                     % 14.09.90 RT
    if contain_edge (first_edge vertex,map_)
                 and
       not equal_edges (first_edge vertex,!_0edge )
     then take_edge (s_vertex_rest vertex,map_)
    else first_edge vertex$

symbolic procedure contain_edge (edge,map_)$
% IS THERE A VERTEX IN THE MAP_ CONTAINING THE EDGE? $
if p_empty_map_ map_ then nil
else
    p_member_edge (edge,s_vertex_first map_)
                    or
    contain_edge (edge,s_map__rest map_) $

% ,,,,,,,,,,,,,,,,,,,,,,,,,,,,SORTING AFTER FACTORIZATION ,,,,,,,,,,,$
%      19.05.88 $

symbolic procedure find_bubltr atlas$
if null !*cvitbtr then atlas else
begin
 scalar s$
 s:=errorset(list('find_bubltr0 ,mkquote atlas),
             !*cviterror,
             !*backtrace)$
 return
     if atom s then atlas
     else car s
 end$

symbolic procedure find_bubltr0 atlas$
%(LAMBDA Z$
%    IF CAR Z THEN  SORT_ATLAS CDR Z  %FACTORIZATION HAPPENED
%    ELSE CDR Z)
 sort_atlas cdr
  find_bubltr1 (atlas,old_edge_list )$

% ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$

symbolic procedure find_bubltr1 (atlas,al)$
%FINDS BOTH BUBLES AND TRIANGLES IN ATLAS$
begin
 scalar s,c,bubles$
 s:=find_bubles1 (atlas,al)$
 c:=car s$
 atlas:=cdr s$
 bubles:=append(c,bubles)$
loop:
 s:=find_triangles1 (atlas,al)$
 c:=car s$
 atlas:=cdr s$
 bubles:=append(c,bubles)$
 if null c then return bubles . atlas$
 s:=find_bubles1 (atlas,al)$
 c:=car s$
 atlas:=cdr s$
 bubles:=append(c,bubles)$
 if null c then return bubles . atlas$
 go loop
end$

symbolic procedure reduce_triangle triangle$
% RETURN (N . VERTEX . TRIANGLE) OR NIL,
% N - NUMBER OF EXTERNAL EDGES$
if null triangle then nil
else
  begin
    scalar extedges,vertex,n$
    %EXTEDGES - LIST OF EXTERNAL EDGES,
    % N - NUMBER OF EXTERNAL EDGES,
    %VERTEX - NEW VERTEX,MADE FROM TRIANGLE$
      vertex:=mk_vertextr triangle$
      extedges:=ext_edges vertex$
      n:=length extedges$
  return
         if n = 1 then nil            % 14.09.90    RT
         else                         % 14.09.90    RT
             n . vertex . triangle
end$

symbolic procedure sk_vertextr z$
% Z IS (N . VERTEX . TRIANGLE) $
if car z = 1 then mk_empty_vertex ()
else
 if car z = 3 then cadr z
 else set_error_real ('sk_vertextr,list z) $

symbolic procedure ext_edges vertex$
%SELECT EXTERNAL EDGES IN VERTEX $
if p_empty_vertex vertex then nil
else
  if p_member_edge (first_edge vertex,s_vertex_rest vertex)
                         or
     equal_edges (first_edge vertex,!_0edge )
   then ext_edges delete_edge (first_edge vertex,
                                 s_vertex_rest vertex)
  else first_edge vertex .
                           ext_edges s_vertex_rest vertex $

symbolic procedure ext_edges_map_ map_$
%SELECT EXTERNAL EDGES OF MAP_$
if p_empty_map_ map_ then nil
else
  ext_map__ver (ext_edges s_vertex_first map_,
                 ext_edges_map_ s_map__rest map_)$

symbolic procedure ext_map__ver (vlist,mlist)$
if null vlist then mlist
else
  if memq(car vlist,mlist) then
       ext_map__ver (cdr vlist,
                      delete(car vlist,mlist))
  else ext_map__ver (cdr vlist,car vlist . mlist)$

symbolic procedure add_tadpoles (bubles,alst)$
if null bubles then alst
else
  if caar bubles = 1 then
       add_tadpoles (cdr bubles,
                      cons(cons(car mk_vertextr cadr car bubles,
                                0),
                           alst))
   else add_tadpoles (cdr bubles,alst)$


%END$  %cvit8.red
%::::::::::::::::::::::: ATLAS SORTING ROUTINES ********************** $
% 13.06.88$

lisp$

global '(!*cvitrace)$

!*cvitrace:=nil$  %IF T THEN TRACE BACTRAKING WHILE ATLAS SORTING$

 flag('(cvitrace),'switch)$

symbolic procedure sort_atlas atlas$
%TOP LEVEL PROCEDURE
if null atlas then atlas
else
 (lambda z$
   if z then z        %ATLAS FULLY SORTED
   else set_error_real ('sort_atlas ,list atlas))
  sort_atlas1 atlas $

symbolic procedure sort_atlas1 atlas$
(lambda z$
   if z then z          %ATLAS FULLY SORTED
   else
     if !*cviterror then print_atlas_sort (atlas,nil)
     else nil )
 atlas_sort (atlas,old_edge_list )$

symbolic procedure print_atlas_sort (atlas,edgelist)$
<< print "Atlas not sorted "$
   print_atlas atlas$
   if edgelist then
      << print "Defined edges: "$
         for each edge in edgelist do print edge >> $
   nil >> $

symbolic procedure atlas_sort (atlas,edgelist)$
begin
  scalar z,newedges$
 newedges:=store_edges new_edge_list$
 z:=
 errorset(list('atlas_sort1 ,mkquote atlas,mkquote edgelist),
          !*cvitrace,
          !*backtrace)$
 return
 if atom z then        %ATLAS NOT SORTED
 << restor_edges (newedges,new_edge_list)$  %RESTORE EDGES PARENTS
    if !*cvitrace then print_atlas_sort (atlas,edgelist)
    else nil >>
 else car z
end$

symbolic procedure store_edges edgelist$
for each edge in edgelist collect
      (car edge . cdr edge)$

symbolic procedure restor_edges (edgelist,newedgelist)$
if null edgelist then
 if newedgelist
   then set_error_real ('restor_edges ,list(edgelist,newedgelist))
 else nil
else
 if null newedgelist then
           set_error_real ('restor_edges ,list(edgelist,newedgelist))
 else
  if s_edge_name car edgelist = s_edge_name car newedgelist then
      << rplacd(car newedgelist,cdar edgelist)$
         car newedgelist . restor_edges (cdr edgelist,
                                          cdr newedgelist) >>
  else
    set_error_real ('restor_edges ,list(edgelist,newedgelist))$

symbolic procedure defined_atlas (atlas,edgelist)$
(lambda edges$
    defined_edges (edges,
%                   DEFINED_APPEND(EDGES,EDGELIST)))
                    edgelist))
 atlas_edges atlas$

symbolic procedure defined_append (edges,edgelist)$
 if null edges then edgelist
 else if defined_edge (car edges,edgelist) then
          car edges . defined_append (cdr edges,edgelist)
      else defined_append (cdr edges,edgelist) $

symbolic procedure defined_edges (edges,edgelist)$
if null edges then t
else
  if defined_edge (car edges,edgelist)
              then
     defined_edges (cdr edges,car edges . edgelist)
  else definedl_edges (cdr edges,list car edges,edgelist)$

symbolic procedure definedl_edges (edges,passed,edgelist)$
if null edges then null passed
else
 if defined_edge (car edges,edgelist) then
    defined_edges (nconc(passed,cdr edges),car edges . edgelist)
 else definedl_edges (cdr edges,car edges . passed,edgelist)$

symbolic procedure atlas_sort1 (atlas,edgelist)$
if all_defined (s_atlas_map_ atlas,edgelist) then
     mk_atlas (s_atlas_map_ atlas,
                coeff_sortl( s_atlas_coeff atlas,
                              nil,
                              nconc( map__edges s_atlas_map_ atlas,
                                     edgelist)),
                s_atlas_den_om atlas)
else coeff_sort (coeff_ordn (s_atlas_coeff atlas,edgelist),
%LSE COEFF_SORT (S_ATLAS_COEFF ATLAS,
                  mk_atlaslist (s_atlas_map_ atlas,
                                 nil,
                                 s_atlas_den_om atlas),
                  edgelist)$

symbolic procedure coeff_sortl (atlaslist,passed,edgelist)$
 coeff_sortl1 (coeff_ordn (atlaslist,edgelist),passed,edgelist)$

symbolic procedure coeff_sort (atlaslist,passed,edgelist)$
if atlaslist then
  (lambda z$                   %Z - NIL OR SORDET ATLAS
      if z then                %FIRST ATLAS ALREADY DEFINED
         mk_atlas (s_atlas_map_ z,
                    coeff_sortl (append(s_atlas_coeff z,
                                        append(cdr atlaslist,passed)),
                                  nil,
                                  nconc(map__edges s_atlas_map_ z,
                                        edgelist)),
                    s_atlas_den_om z)
      else
          coeff_sort (cdr atlaslist,
                       car atlaslist . passed,
                       edgelist))
  atlas_sort (car atlaslist,edgelist)
else coeff_sort_f (passed,nil,edgelist)$

symbolic procedure coeff_sort_f (passed,farewell,edgelist)$
if null passed then
  if null farewell then nil
  else error(51,nil)
else
 if s_atlas_coeff car passed then          %NOT EMPTY COEFF
   coeff_sort (append(
                   s_atlas_coeff car passed,
                   mk_atlas (s_atlas_map_ car passed,
                              nil,
                              s_atlas_den_om car passed) .
                     append(cdr passed,farewell)),
                nil,
                edgelist)
 else coeff_sort_f (cdr passed,
                      car passed . farewell,
                      edgelist) $

%.......... 31.05.88 ::::::::::: $

symbolic procedure coeff_ordn (atlaslist,edgelist)$
for each satlas in
 coeff_ordn1 (mk_spec_atlaslist (atlaslist,edgelist),nil)
collect cdr satlas$

symbolic procedure mk_spec_atlaslist (atlaslist,edgelist)$
 for each atlas in atlaslist collect mk_spec_atlas (atlas,edgelist)$

symbolic procedure mk_spec_atlas (atlas,edgelist)$
%RETURN PAIR (PAIR1 . ATLAS)
%WHERE PAIR1 IS A PAIR - EDGES . PARENTS
%WHERE EDGES - ALL EDGES OF ATLAS
%WHERE PARENTS-THOSE PARENTS OF EDGES WICH NOT CONTAITED IN EDGELIST
(lambda edges$
(edges . diff_edges (edges_parents edges,edgelist)) . atlas)
 atlas_edges atlas$

symbolic procedure edges_parents edgelist$
if null edgelist then nil
else
  (lambda z$
     append(z ,edges_parents cdr edgelist))
   edge_new_parents car edgelist$

symbolic procedure edge_new_parents edge$
% SELECT EDGE PARENTS FROM NEW_EDGE_LIST$
if p_old_edge edge then nil else
(lambda names$
  edge_new_parent list(car names,cdr names))
 s_edge_prop_ edge$

symbolic procedure edge_new_parent namelist$
if null namelist then nil
else
 (lambda z$
    if z then z . edge_new_parent cdr namelist
    else edge_new_parent cdr namelist)
  assoc(car namelist,new_edge_list) $

symbolic procedure diff_edges (edgelist1,edgelist2)$
if null edgelist1 then nil
else
 if p_member_edge (car edgelist1,edgelist2) then
    diff_edges (cdr edgelist1,edgelist2)
 else  car edgelist1 .
       diff_edges (cdr edgelist1,edgelist2)$

symbolic procedure coeff_ordn1 (satlaslist,passed)$
if null satlaslist then passed
else
%IF NULL CAAR SATLASLIST THEN     %ATLAS HAS NO UNDEFINED
%      COEFF_ORDN1 (CDR SATLASLIST,CAR SATLASLIST . PASSED)
%ELSE
 (lambda z$                    % Z - NIL OR SATLASLIST
   if z then                   % SUBATLAS FINED AND ADDED$
        coeff_ordn1 (z,passed)
   else coeff_ordn1 (cdr satlaslist,car satlaslist . passed) )
  p_subsatlaslist (car satlaslist,cdr satlaslist,nil)$

symbolic procedure p_subsatlaslist (satlas,satlaslist,passed)$
if null satlaslist then nil
else
 if or_subsatlas(satlas,car satlaslist) then
            embed_satlases (satlas,car satlaslist) .
            nconc(passed,cdr satlaslist)
 else p_subsatlaslist (satlas,
                       cdr satlaslist,
                       car satlaslist . passed)$

symbolic procedure or_subsatlas (satlas1,satlas2)$
  p_subsatlas (satlas1,satlas2)
             or
  p_subsatlas (satlas2,satlas1) $

symbolic procedure p_subsatlas (satlas1,satlas2)$
 p_subedgelist (caar satlas1,caar satlas2)
               or
 p_inbothlists (cdar satlas1,caar satlas2) $

symbolic procedure p_inbothlists (edgelist1,edgelist2)$
if null edgelist1 then nil
else p_member_edge (car edgelist1,edgelist2)
                 or
     p_inbothlists (cdr edgelist1,edgelist2)$

symbolic procedure p_subedgelist (edgelist1,edgelist2)$
 if null edgelist1 then t
 else
   p_member_edge (car edgelist1,edgelist2)
              and
   p_subedgelist (cdr edgelist1,edgelist2)$

symbolic procedure embed_satlases (satlas1,satlas2)$
 if p_subsatlas (satlas1,satlas2) then embed_satlas (satlas1,satlas2)
 else
 if p_subsatlas (satlas2,satlas1) then embed_satlas (satlas2,satlas1)
 else set_error_real ('embed_satlases,list(satlas1,satlas2)) $

symbolic procedure embed_satlas (satlas1,satlas2)$
 car satlas2 . embed_atlas (cdr satlas1,cdr satlas2)$

symbolic procedure embed_atlas (atlas1,atlas2)$
%EMBED ATLAS1 INTO ATLAS2
 mk_atlas (s_atlas_map_ atlas2,
            atlas1 . s_atlas_coeff atlas2,
            s_atlas_den_om atlas2)$

symbolic procedure coeff_sortl1 (atlaslist,passed,edgelist)$
if null atlaslist then
 if null passed then nil
 else list coeff_sort_f (passed,nil,edgelist)
else
(lambda z$
 if z then      %ATLAS SORTED
      z . coeff_sortl1 (cdr atlaslist,passed,edgelist)
 else coeff_sortl1 (cdr atlaslist,car atlaslist . passed,edgelist))
 atlas_sort (car atlaslist,edgelist)$

% ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$


%END$  %cvit82.red
%:*:*:*:*:*:*:*:*:*:*:*:* FACTORIZATION OF MAP_S :*:*:*:*:*:*:*:*:*:$
% 19.05.88 $
lisp$

symbolic procedure renamel_edges edges$
if not equal_edges (car edges,cadr edges) then
  rename_edges (car edges ,cadr edges)$

symbolic procedure map__vertex_first map_$
  mk_vertex1_map_
                  s_vertex_first map_$

symbolic procedure  both_empty_map_s (map_1,map_2)$
 p_empty_map_ map_1
      and
 p_empty_map_ map_2 $

symbolic procedure has_parents edge$
 (lambda z$
           car z neq '!? and
           cdr z neq '!?    )
  s_edge_prop_ edge $

symbolic procedure less_edge (edge1,edge2,edgelist)$
% EDGE1 < EDGE2 IFF EDGE1 WAS CREATED EARLIER$
 less_edge_name (s_edge_name edge1,
                 s_edge_name edge2,
                 edgelist)$

symbolic procedure less_edge_name (name1,name2,edgelist)$
if null edgelist then set_error_real ('less_edge_name ,
                                      list(name1,name2,edgelist))
else
  if name1 eq s_edge_name car edgelist then nil
  else
    if name2 eq s_edge_name car edgelist then t
    else less_edge_name (name1,name2,cdr edgelist)$

symbolic procedure rename_edges (edge1,edge2)$
if p_old_edge edge1 then
 %IF P_OLD_EDGE EDGE2 THEN OLD_EDGE_LIST
  if p_old_edge edge2 then replace_old_edge (edge1,edge2)
  else replace_edge (edge2,edge1,new_edge_list )
else
  if p_old_edge edge2 then replace_edge (edge1,edge2,
                                         new_edge_list )
  else
    if has_parents edge1 then
      if has_parents edge2 then replace_new_edge (edge1,edge2)
      else replace_edge (edge2,edge1,new_edge_list )
    else
      if has_parents edge2 then
           replace_edge (edge1,edge2,new_edge_list )
      else replace_new_edge (edge1,edge2)$

symbolic procedure replace_new_edge (edge1,edge2)$
 replace_o_edge (edge1,edge2,new_edge_list )$

symbolic procedure replace_old_edge (edge1,edge2)$
% 31.08.90 RT
if is_indexp edge1 then
 if is_indexp edge2 then
     replace_o_edge (edge1,edge2,old_edge_list )
 else  replace_edge (edge1,edge2,old_edge_list)
else
  if is_indexp edge2 then
       replace_edge (edge2,edge1,old_edge_list)
  else
      replace_o_edge (edge1,edge2,old_edge_list )$

symbolic procedure replace_o_edge (edge1,edge2,edgelist)$
if less_edge (edge1,edge2,edgelist) then
              replace_edge (edge2,edge1,edgelist)
else          replace_edge (edge1,edge2,edgelist)$

symbolic procedure copy_edge edge$
 car edge . cadr edge . caddr edge . nil $


symbolic procedure replace_edge2 (oldedge,newedge)$
<< rplaca(oldedge,car newedge)$
   rplacd(oldedge,cdr newedge) >> $

symbolic procedure replace_edge (oldedge,newedge,edgelist)$
 replace1_edge (copy_edge oldedge,newedge,edgelist)$

symbolic procedure replace1_edge (oldedge,newedge,edgelist)$
if null edgelist then nil
else
  <<  if equal_edges (oldedge,car edgelist) then
                         replace_edge2 (car edgelist,newedge)$
      replace1_parents (oldedge,newedge,car edgelist)$
      replace1_edge (oldedge,newedge,cdr edgelist) >> $

symbolic procedure replace1_parents (oldedge,newedge,edge)$
 replace2_parents (s_edge_name oldedge,
                   s_edge_name newedge,
                   s_edge_prop_ edge)$

symbolic procedure replace2_parents (oldname,newname,edgeprop_)$
 << if oldname = car edgeprop_ then rplaca(edgeprop_,newname)$
    if oldname = cdr edgeprop_ then rplacd(edgeprop_,newname) >> $

symbolic procedure mk_simple_map_ inmap_$
  mk_simple_map_1 (inmap_,mk_empty_map_ (),nil,nil)$

symbolic procedure both_old edges$
 p_old_edge  car edges
        and
 p_old_edge cadr edges$

symbolic procedure both_vectors edges$   % 31.08.90 RT
 not is_indexp car edges
        and
 not is_indexp cadr edges$

symbolic procedure old_renamel_edv (vertex,edges)$
% RENAMES EDGES IN VERTEX$
 ren_edge (s_edge_name car edges .
           s_edge_name cadr edges,vertex)$

symbolic procedure mk1_simple_map_ map_d$
%MAP_D IS A PAIR (MAP_.DEN_OM)$
mk_simple_map_1 (car map_d,mk_empty_map_ (),list cdr map_d,nil)$

symbolic procedure mk_simple_map_1 (inmap_,outmap_,den_om,coeff)$
if p_empty_map_ inmap_ then <<
 %        FIND_BUBLTR
        outmap_ := mk_parents_map_ outmap_;
        mk_atlas  (outmap_ ,
                   if null coeff then nil
                    else for each map_ in coeff
                             collect mk1_simple_map_ map_,
                   den_om) >>
else
(lambda edges$
 (lambda n$
  if p_vertex_prim s_vertex_first inmap_ then
   if n=2 then                 % VERTEX=(A,B)=DELTA(A,B)  $
    if both_old edges and both_vectors edges then   % 31.08.90
          mk_simple_map_1 (s_map__rest inmap_,
                           add_vertex (s_vertex_first inmap_,outmap_),
                           den_om,
                           coeff)
    else
     << renamel_edges edges$
        if both_empty_map_s (s_map__rest inmap_,outmap_) then
          mk_simple_map_1 (s_map__rest inmap_,
                           add_vertex (s_vertex_first inmap_,outmap_),
                           den_om,
                           coeff)
        else
           mk_simple_map_1 (s_map__rest inmap_,
                            outmap_,
                            den_om,
                            coeff )
     >>
   else
      mk_simple_map_1 ( s_map__rest inmap_,
                        add_vertex ( s_vertex_first inmap_,outmap_),
                        den_om,
                        coeff)
  else
   if n=2  then
    if both_old edges  and both_vectors edges then  %11.09.90 RT
        mk_simple_map_1 (add_vertex (mk_edges_vertex edges,
                                     s_map__rest inmap_),
                          outmap_,
                          den_om,
                          (mk_vertex1_map_ (
                           old_renamel_edv(s_vertex_first inmap_,edges))
                         . old_renamel_edv(mk_edges_vertex edges,edges))
                         . coeff  )
    else
     << renamel_edges edges$
        mk_simple_map_1 (s_map__rest inmap_,
                         outmap_,
                         den_om,
                         (map__vertex_first inmap_ . edges) . coeff)
      >>
   else
   if n=3  and
     ((map__length (inmap_) + map__length (outmap_)) > 2 )
    then
     (lambda v$
     mk_simple_map_1 (add_vertex (v,s_map__rest inmap_),
                      outmap_,
                      den_om,
                      (add_vertex (v,map__vertex_first inmap_) . v)
                        . coeff))
      mk_edges_vertex edges
   else
    if
      (lambda k$
           k > 4 and
           n < k )              %NOT ALL LINES EXTERNAL $
           vertex_length s_vertex_first inmap_
    then
    (lambda firz$
    mk_simple_map_1 (append_map_s (firz,s_map__rest inmap_),
                     outmap_,
                     den_om,
                     coeff) )
     (mk_firz_op s_vertex_first inmap_)        %26.04.88
  else if t then
    mk_simple_map_1 (s_map__rest inmap_,
                     add_vertex (s_vertex_first inmap_,outmap_),
                     den_om,
                     coeff)
    else
    mk_simple_map_1 (append_map_s (mk_simple_vertex
                                   s_vertex_first inmap_,
                                   s_map__rest inmap_),
                      outmap_,
                      den_om,
                      coeff)  )
  length edges)
(ext_edges s_vertex_first inmap_) $


% ?^?^?^?^?^?^?^?^?^?^?^?^? FIERZ OPTIMIZATION ?^?^?^?^?^?^?^?^?^?^?^?$
%       13.05.88$


global '(!*cvitop)$

flag('(cvitop),'switch)$

symbolic procedure mk_firz_op vertex$
if null !*cvitop then mk_firz vertex
else firz_op vertex$

symbolic procedure firz_op vertex$
mk_firz find_cycle (optimal_edge vertex,
                    vertex,
                    mk_empty_vertex ())$

symbolic procedure find_cycle (edge,vertex,passed)$
if equal_edges (edge,first_edge vertex) then
   append_vertex (vertex,reversip_vertex passed)
else find_cycle (edge,
                 s_vertex_rest vertex,
                 add_edge (first_edge vertex,passed))$

symbolic procedure optimal_edge vertex$
optimal1_edge
 internal_edges (vertex,mk_empty_vertex ())$

symbolic procedure internal_edges (vertex1,vertex2)$
if p_empty_vertex vertex1 then vertex2
else
  if p_member_edge (first_edge vertex1,s_vertex_rest vertex1)
            or
     p_member_edge (first_edge vertex1,vertex2)
   then internal_edges (s_vertex_rest vertex1,
                        add_edge (first_edge vertex1,vertex2))
  else  internal_edges (s_vertex_rest vertex1,vertex2)$

symbolic procedure optimal1_edge vertex$
% VERTEX CONTAINS ONLY PAIRED EDGES
(lambda (l,z)$
   opt_edge (z,
             edge_distance (z,vertex,l),
             s_vertex_rest vertex,
             add_edge (z,mk_empty_vertex ()),
             l))
(vertex_length vertex,
 first_edge vertex)$

symbolic procedure edge_distance (edge,vertex,l)$
% L - FULL VERTEX LENGTH
(lambda n$
     min(n,l - n - 2))
 edge_dist (edge,s_vertex_rest vertex)$

symbolic procedure edge_dist (edge,vertex)$
if equal_edges (edge,first_edge vertex) then 0
else add1 edge_dist (edge,s_vertex_rest vertex)$

symbolic procedure opt_edge (edge,distance,vertex,passed,n)$
% N - FULL VERTEX LENGTH
if distance = 0 or p_empty_vertex vertex then edge
else
(lambda firstedge$
   if p_member_edge (firstedge,passed) then
              opt_edge (edge,
                        distance,
                        s_vertex_rest vertex,
                        passed,
                        n)
   else
 (lambda dist$
    if dist < distance then
              opt_edge (firstedge,
                        dist,
                        s_vertex_rest vertex,
                        add_edge (firstedge,passed),
                        n)
     else     opt_edge (edge,
                        distance,
                        s_vertex_rest vertex,
                        add_edge (firstedge,passed),
                        n))
  edge_distance (firstedge,vertex,n))
first_edge vertex $



%<?><?><?><?><?><?><?> END OF OPTIMIZATION PART <?><?><?><?><?><?> $

symbolic procedure mk_firz vertex$
% VERTEX=(A1,...,AM,Z,B1,...,BN,Z,C1,...,CK)
% RETURNS UNION MAP_ WHERE
% MAP_ =MAP_1 & MAP_2  WHERE
% MAP_1=((B1,...,BN,X)(Y,C1,...,CK,A1,...,AM)),
% MAP_2=((Z,X,Z,Y)) $
   mk_firz1 (vertex,mk_empty_vertex ())$

symbolic procedure mk_firz1 (vertex1,vertex2)$
if p_empty_vertex vertex1 then reversip_vertex vertex2
else
  (lambda z$
      if z then                   %FIRST EDGE CONTAINS TWICE$
         mk_firz2 (first_edge vertex1,
                   car z,
                   append_vertex (cdr z,reversip_vertex vertex2))
      else
         mk_firz1 (s_vertex_rest vertex1,
                   add_edge (first_edge vertex1,vertex2) ) )
   mp_member_edge (first_edge vertex1,
                     s_vertex_rest vertex1)$

symbolic procedure mk_firz2 (edge,vertex1,vertex2)$
%RETURNS MAP_ =MAP_1 & MAP_2 ,
%VERTEX1=(B1,...,BN),
%VERTEX2=(C1,...,CK,A1,...,AM)  $
(lambda (nedge,nedg1)$
 append_map_s (
  mk_coeff2 (edge,nedge,nedg1),
  mk_vertex2_map_ (conc_vertex (vertex1,mk_edge1_vertex nedge),
                   add_edge (nedg1,vertex2))
               ))
(mk_nedge (),
 mk_nedge ()) $

symbolic procedure mk_coeff2 (edge,nedge,nedg1)$
 mk_vertex1_map_ mk_edge4_vertex (edge,nedge,edge,nedg1)$

symbolic procedure mk_nedge $
(lambda edge$
   new_edge (edge,edge))
 mk_edge ('!?,'!? . '!?,nil) $

symbolic procedure mp_member_edge (edge,vertex)$
% RETURNS NIL OR PAIR.
% IF VERTEX=(A1,...,AM,EDGE,...,B1,...,BN) THEN
% PAIR= (A1,...,AM) . (B1,...,BM) $
  mp_member1_edge (edge,vertex,mk_empty_vertex ())$

symbolic procedure mp_member1_edge (edge,vertex,tail)$
if p_empty_vertex vertex then nil
else
 if
  equal_edges (edge,first_edge vertex) then
           reversip_vertex tail .
           s_vertex_rest vertex
 else mp_member1_edge (edge,
                       s_vertex_rest vertex,
                       add_edge (first_edge vertex,tail) ) $


%END$  %cvit10.red
% ()()()()()()()()()()()()()() PRINTING ATLAS AND MAP_ ROUTINES ()()().
lisp$             %30.01.87$

fluid '(ntab!*)$

symbolic procedure print_atlas atlas$
begin
  scalar ntab!*$
  ntab!*:=0$
  prin2_atlas atlas$
end$

symbolic procedure prin2_atlas atlas$
if null atlas then nil
else
    << print_map_ s_atlas_map_ atlas$
       print_den_om s_atlas_den_om atlas$
       print_coeff s_atlas_coeff atlas
     >> $

symbolic procedure print_map_ map_$
 << pttab ntab!*$
    prin2 "Map_ is: ("$
    prin2_map_ map_$
    prin2 " )"$
    terpri()  >> $

symbolic procedure prin2_map_ map_$
if p_empty_map_ map_ then nil
else
    << print_vertex s_vertex_first map_$
       prin2_map_ s_map__rest map_ >> $

symbolic procedure print_vertex vertex$
 <<
    prin2 "( "$
    prin2_vertex vertex$
    prin2 ")"      >> $

symbolic procedure prin2_vertex vertex$
if p_empty_vertex vertex then nil
else
    << print_edge first_edge vertex$
       prin2_vertex s_vertex_rest vertex >> $

symbolic procedure print_edge edge$
 << prin2_edge edge$
    prin2 " "    >> $

symbolic procedure prin2_edge edge$
 prin2 s_edge_name edge $

symbolic procedure pttab n$
  << spaces n $   % TTAB N$         % 07.06.90
     prin2 n$
     prin2 ":" >> $

symbolic procedure print_coeff coeff$
 << ntab!*:=ntab!*+1$
    prin2_coeff coeff$
    ntab!*:=ntab!*-1    >> $

symbolic procedure prin2_coeff atlases$
if null atlases then nil
else << prin2_atlas car atlases$
        prin2_coeff cdr atlases >> $

symbolic procedure print_den_om den_list$
 << pttab ntab!*$
    prin2 "DEN_OM is: "$
    if null den_list then prin2 nil
    else prin2_map_ den_list $
    terpri() >> $

unfluid '(ntab!*)$

symbolic procedure print_old_edges ()$
   print_edge_list old_edge_list $

symbolic procedure print_new_edges ()$
   print_edge_list new_edge_list $

symbolic procedure print_edge_list edgelist$
if null edgelist then nil
else << print car edgelist$
        print_edge_list cdr edgelist >> $


%END$  %cvit12.red
%---------------------- MAKES PARENTS AFTER FIERZING ----------------$

          %24.05.88$
 lisp$


symbolic procedure mk_simpl_map_ map_$
  mk_simpl_map_1 (map_,mk_empty_map_ ())$

symbolic procedure mk_simpl_map_1 (inmap_,outmap_)$
if p_empty_map_ inmap_ then resto_map__order outmap_
else
  if p_vertex_prim s_vertex_first inmap_ then
      mk_simpl_map_1 ( s_map__rest inmap_,
                       add_vertex(mk_parents_prim s_vertex_first inmap_,
                                   outmap_))
  else
    mk_simpl_map_1 (append_map_s(mk_simple_vertex s_vertex_first inmap_,
                                  s_map__rest inmap_),
                    outmap_)$

symbolic procedure mk_simple_vertex vertex$
 % VERTEX => MAP_ $
begin
 scalar nedge,fedge,sedge$
 fedge:=first_edge vertex$
 sedge:=second_edge vertex$
 if not has_parents fedge or not has_parents sedge then
    return mk_simple_vertex cycl_vertex vertex$
 nedge:=new_edge (fedge,sedge)$
 vertex:=s_vertex_rest
         s_vertex_rest vertex$
 return
     mk_vertex2_map_ ( mk_edge3_vertex (nedge,fedge,sedge),
                       add_edge (nedge,vertex))
end$

symbolic procedure mk_parents_map_ map_$
%MAKES PARENTS FOR ALL EDGES IN MAP_.
%THIS CAN BE DONE BECAUSE NEW EDGES NEVER CREATE CYCLES$
 standard_map_
 mk_simpl_map_
 mk_parents1_map_ (map_,mk_empty_map_ (),mk_empty_map_ ())$

symbolic procedure standard_map_ map_$
if p_empty_map_ map_ then mk_empty_map_ ()
else
 if vertex_length s_vertex_first map_ > 2 then
    add_vertex (s_vertex_first map_,
                standard_map_ s_map__rest map_)
 else standard_map_ add_vertex (add_0_edge s_vertex_first map_,
                                s_map__rest map_)$

symbolic procedure add_0_edge vertex$
%ADDS SPECIAL VERTEX$
add_edge (!_0edge ,vertex)$

symbolic procedure mk_parents1_map_ (inmap_,outmap_,passed)$
if p_empty_map_ inmap_ then
 if p_empty_map_ passed then outmap_     %ALL EDGES HAVE PARENTS$
 else mk_parents1_map_ (passed,outmap_,mk_empty_map_ ())
else
 (lambda edges$
   if null edges then        %IN FIRST VERTEX ALL EDGES HAVE PARENTS$
      mk_parents1_map_ (s_map__rest inmap_,
                        add_vertex (s_vertex_first inmap_,outmap_),
                        passed)
   else
    if single_no_parents edges then   %ONLY ONE EDGE IN THE VERTEX$
                                        %HAS NO PARENTS$
       mk_parents1_map_ (s_map__rest inmap_,
                         append_map_s (mk_parents_vertex
                                          s_vertex_first inmap_,
                                       outmap_),
                         passed)
    else
       mk_parents1_map_ (s_map__rest inmap_,
                         outmap_,
                         add_vertex (s_vertex_first inmap_,passed)))
  s_noparents s_vertex_first inmap_ $

symbolic procedure s_noparents vertex$
%SELECTS EDGES WITHOUT PARENTS IN VERTEX$
if p_empty_vertex vertex then nil
else
 if has_parents first_edge vertex then
         s_noparents s_vertex_rest vertex
 else
     first_edge vertex .
     s_noparents s_vertex_rest vertex$

symbolic procedure mk_parents_vertex vertex$
%MAKES PARENTS FOR THE SINGLE EDGE WITHOUT PARENTS IN VERTEX,
% (VERTEX HAS ONLY ONE EDGE WITHOUT PARENTS ^)       $
 mk_simpl_map_ mk_vertex1_map_ vertex$

symbolic procedure mk_parents_prim pvertex$
% CREATES PARENTS FOR THE ONLY EDGE WITHOUT PARENTS IN PRIMITIVE
% (THREE EDGES) VERTEX $
if vertex_length pvertex neq 3 then pvertex
else
  (lambda edges$
     if null edges then pvertex
     else
        << mk_edge_parents (pvertex,car edges)$
           pvertex >> )
   s_noparents pvertex$

symbolic procedure mk_edge_parents (vertex,edge)$
 mk_edge1_parents (delete_edge (edge,vertex),edge)$

symbolic procedure mk_edge1_parents (vertex2,edge)$
 add_parents (edge,
              mk_edge_prop_ (
                             s_edge_name first_edge vertex2,
                             s_edge_name second_edge vertex2))$

symbolic procedure add_parents (edge,names)$
  add_parents0(edge,names,nil)$

symbolic procedure add_parents0 (edge,names,bool)$
 addl_parents (new_edge_list,edge,names . list bool)$

symbolic procedure addl_parents (edgelist,edge,names)$
% NAMES IS A PAIR NAME1 . NAME2 $
if null edgelist then nil
else
(if equal_edges (car edgelist,edge) then
    rep_parents (car edgelist,names)
 else car edgelist) .
                      addl_parents (cdr edgelist,edge,names) $

symbolic procedure rep_parents (edge,names)$
 << rplacd(edge,names)$
    edge >> $

%END$  %cvit14.red
%EEEEEEEEEEEEEEEEEEEEEEEEE SELECT ALL EDGES %%%%%%%%%%%%%%%%%%%%%%%%% $

                       % 07.06.88$

lisp$

symbolic procedure atlas_edges atlas$
union_edges (
 union_edges (map__edges s_atlas_map_ atlas,
              den__edges s_atlas_den_om atlas),
 coeff_edges s_atlas_coeff atlas)$

symbolic procedure den__edges den_om$
 map__edges den_om$

symbolic procedure coeff_edges atlaslist$
 if null atlaslist then nil
 else union_edges (atlas_edges car atlaslist,
                   coeff_edges cdr atlaslist) $

symbolic procedure map__edges map_$
 if p_empty_map_ map_ then nil
 else union_edges (vertex_edges s_vertex_first map_,
                   map__edges s_map__rest map_)$

symbolic procedure union_edges (newlist,oldlist)$
if null newlist then oldlist
else union_edges (cdr newlist,
                  union_edge (car newlist,oldlist))$

symbolic procedure union_edge (edge,edgelist)$
 if memq_edgelist (edge,edgelist) then edgelist
 else edge . edgelist$

symbolic procedure memq_edgelist (edge,edgelist)$
 assoc(s_edge_name edge,
       edgelist)$

symbolic procedure exclude_edges (edgelist,exclude)$
% EXCLUDE IS A LIST OF EDGES TO BE EXCLUDED FROM EDGELIST$
 if null edgelist then nil
 else
   if memq_edgelist (car edgelist,exclude) then
           exclude_edges (cdr edgelist,exclude)
   else car edgelist .
           exclude_edges (cdr edgelist,exclude)  $


symbolic procedure constr_worlds (atlas,edgelist)$
(lambda edges$
   actual_edges_world (
      mk_world1 (actual_edges_map_ (edges,
                                    edgelist,
                                    s_atlas_map_ atlas),
                  constr_coeff (s_atlas_coeff atlas,
                                union_edges (edges,edgelist)),
                  s_atlas_den_om atlas
                  )
               ) )
union_edges(
  den__edges s_atlas_den_om atlas,
  map__edges s_atlas_map_ atlas)$

symbolic procedure constr_coeff (atlases,edgelist)$
 if null atlases then nil
 else
      constr_worlds (car atlases,edgelist) .
      constr_coeff (cdr atlases,edgelist)$

symbolic procedure actual_edges_map_ (edges,edgelist,map_)$
 actedge_map_ (edges,edgelist,list_of_parents(edges,edgelist),nil)
%ACTEDGE_MAP_ (EDGES,EDGELIST,NIL,NIL)
  . map_$

symbolic procedure list_of_parents (edges,edgelist)$
if null edges then nil
else append(list_of_parent (car edges,edgelist),
            list_of_parents (cdr edges,edgelist))$

symbolic procedure list_of_parent (edge,edgelist)$
if p_old_edge edge or memq_edgelist (edge,edgelist) then nil
               %IF EDGE IS DEF. THEN NO NEED IN ITS PARENTS
else
begin$
 scalar pr1,pr2,p,s$
 p:=s_edge_prop_ edge$
 pr1:=assoc(car p,edgelist)$
 if pr1 then s:=pr1 . s$
 pr2:=assoc(cdr p,edgelist)$
 if pr2 then s:=pr2 . s$
%IF NULL PR1 OR NULL PR2 THEN
% SET_ERROR (LIST_OF_PARENTS ,EDGE,EDGELIST)$
 return  s
end$

symbolic procedure actedge_map_ (edges,edgelist,old,new)$
if null edges then old . new
else
  if memq_edgelist (car edges,edgelist) then
       actedge_map_ (cdr edges,edgelist,car edges . old,new)
  else actedge_map_ (cdr edges,edgelist,old,car edges . new) $

symbolic procedure actual_edges_world world1$
 mk_world (actual_world (s_actual_world1 world1,
                         s_actual_coeff s_coeff_world1 world1),
            world1)$

symbolic procedure mk_world1 (edges!-map_,coeff,den_om)$
 mk_atlas (map_2_from_map_1 edges!-map_,coeff,den_om)$

symbolic procedure map_2_from_map_1 map_1$
 list(map_1_to_strand1 map_1,
      list nil,
      mark_edges (cdar map_1,
                % UNION_EDGES(OLD_EDGE_LIST,CAAR MAP_1),
                  caar map_1,
                  cdr map_1))$

symbolic procedure map_1_to_strand1 map_1$
car map_1 .
pre!-calc!-map_ (cdr map_1,
                 names_edgepair map__edges cdr map_1)$

symbolic procedure names_edgepair edgepair$
%NCONC(FOR EACH EDGE IN CAR EDGEPAIR COLLECT S_EDGE_NAME EDGE,
%      FOR EACH EDGE IN CDR EDGEPAIR COLLECT S_EDGE_NAME EDGE)$
       for each edge in edgepair collect s_edge_name edge $

symbolic procedure s_actual_world1 world1$
%RETURNS PAIR: OLDEDGES . NEWEDGES $
caar s_atlas_map_ world1$

symbolic procedure actual_world (map_edges,coeffedges)$
%MAP_EDGES IS A PAIR OLD . NEW,
%COEFFEDGES IS LIST OF ACTUAL EDGES OF COEEF.$
 union_edges (car map_edges,
              exclude_edges (coeffedges,cdr map_edges)) $

symbolic procedure s_actual_coeff worldlist$
if null worldlist then nil
else union_edges (s_edgelist_world car worldlist,
                  s_actual_coeff cdr worldlist) $

symbolic procedure world_from_atlas atlas$
%TOP LEVEL PROCEDURE$
 constr_worlds (atlas,old_edge_list )$


%END$  %cvit16.red
%^^^^^^^^^^^^^^^^^^^^^^^^^^ CALCULATION OF WORLDS ^^^^^^^^^^^^^^^^^^^ $
           %26.03.88$
lisp$

symbolic procedure s_world_names world$
for each edge in s_world_edges world
  collect s_edge_name edge$

symbolic procedure calc_world (world,alst)$
% ALST LIST OF VALUES OF EXTERNAL EDGES: (... (EDGNAME . NUMBER) ...)$
begin
  scalar s,v$
  alst:=actual_alst (alst,                   %SELECT ONLY THOSE
                     s_world_names world)$    %EDGES WICH ARE IN WORLD
  v:=s_world_var world $                      %SELECT DATA BASE
  s:=assoc(alst,cdr v)$                       %CALC. PREVIOSLY?
  if s then return cdr s$                     %PREV. RESULT$
  s:=reval
     calc_atlas (s_world_atlas world,alst)$   %REAL CALCULATION
  nconc (v,list(alst . s))$                   %MODIFY DATA BASE
  return s
end$

symbolic procedure actual_alst (alst,namelist)$
if null alst then nil
else
  if memq(caar alst,namelist) then
     car alst . actual_alst (cdr alst,namelist)
  else actual_alst (cdr alst,namelist)$

symbolic procedure calc_atlas (atlas,alst)$
        calc_map_2d (s_atlas_map_ atlas,
                     s_atlas_den_om atlas,
                     s_atlas_coeff atlas,
                     alst) $

symbolic procedure calc_coeff (worldlist,alst)$
if null worldlist then list 1
else
 (lambda x$
      if x=0 then list 0
      else x . calc_coeff (cdr worldlist,alst))
  calc_world (car worldlist,alst)$

symbolic procedure calc_map_2d (map_2,den_om,coeff,alst)$
coeff_calc (mk_names_map_2 caar map_2 .
                          cdar map_2 .
                          cadr map_2 .
                          den_om     ,
            coeff,
            mk_binding (caddr map_2,alst)) $

symbolic procedure mk_names_map_2 edgespair$
% EDGESPAIR IS PAIR OF LISTS OF EDGES
%   EDGELISTOLD . EDGELISTNEW         $
for each edge in append(car edgespair,cdr edgespair)
    collect s_edge_name edge$

symbolic procedure calc_coeffmap_ (s,coeff,alst)$
(lambda z$
    if z = 0 then 0
    else 'times . (z . calc_coeff (coeff,alst)))
 calc_map_ (s,alst)$

symbolic procedure calc_map_ (mvd,alst)$
begin
  scalar map_,v,names,s,den_om,al,d$
  names:=car mvd$                               %NAMES OF ALL EDGES
  map_:=cadr mvd$                               %SELECT MAP_
  v:=caddr mvd$                                 %SELECT DATA BASE
  den_om:=cdddr mvd$                            %SELECT DEN_OMINATOR
  al:=actual_alst (alst,names)$                 %ACTUAL ALIST
  if null al and names then return 0$           %NO VARIANTS OF
                                                %COLOURING
  s:=assoc(al,cdr v)$                           %PREV.CALCULATED?
  if s then  s:=cdr s                           %YES, TAKE IT
  else <<                                       %ELSE
       s:=reval calc_map_tar (map_,al)$         %REAL CALCULATION
       nconc(v,list(al . s))                    %MODIFY DATA BASE
       >>  $
  d:=calc_den_tar (den_om,alst)$                %CALC. DEN_OMINATOR
  return
        if d = 1 then s
        else list('quotient,s,d)                % 09.06.90 RT
end$

%SYMBOLIC PROCEDURE CALC_MAP_TAR (MAP_,BINDING)$
%1$

%SYMBOLIC PROCEDURE CALC_DEN_TAR (DEN_OMINATOR,BINDING)$
%1$

symbolic procedure coeff_calc (s,coeff,binding)$
%S IS EDGENAMES . MAP_ . DATABASE . DEN_OMINATOR $
 reval
     ('plus . coeff1_calc (s,coeff,binding))$

symbolic procedure coeff1_calc (s,coeff,binding)$
if null binding then list 0
else calc_coeffmap_ (s,coeff,car binding) .
     coeff1_calc (s,coeff,cdr binding) $

%TOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOPTOP$

symbolic procedure calc_spur0 u$
begin
 scalar s$
 if null u then return u$
 s:=transform_map_ u$
 old_edge_list := !_0edge . old_edge_list $
 s:=find_bubltr s$
 return
        calc_world (world_from_atlas s,
                     for each edge in old_edge_list
                         collect s_edge_name edge .
                                 car s_edge_prop_ edge )
end$

symbolic procedure calc_spur u$
 simp!* calc_spur0 u$                %FOR KRYUKOV NEEDS$

endmodule;


end;
