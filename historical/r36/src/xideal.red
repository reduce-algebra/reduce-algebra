module xideal;

%
%                               XIDEAL
%
% Tools for calculations with ideals of polynomials in exterior algebra.
% Uses Groebner basis algorithms described in D Hartley and P A Tuckey,
% "A direct characterisation of Groebner bases in Clifford and Grassmann
% algebras", Preprint MPI-Ph/93-96 1993.
%
% Authors:      David Hartley           Philip A Tuckey
%               GMD, Institute I1       Max Planck Institute for Physics
%               Schloss Birlinghoven    Foehringer Ring 6
%               D-53757 St Augustin     D-80805 Munich
%               Germany                 Germany
%
%               email:  David.Hartley@gmd.de
%                       pht@iws170.mppmu.mpg.de
%
% Created:      1/5/92          as idl.red
%
% Modified:     5/8/92          Renamed ideal.red
%                               Chose xideal30 as algorithm
%                               Renamed mod -> xmodulo, ideal -> xideal
%                               Added xmodulop
%                               Added subform
%                               Added autoreduction (xfullreduce)
%               4/3/94          Renamed xideal.red
%                               Compiles independently
%                               Converted right reduction and spolys to
%                                  left
%                               Added graded lexicographical ordering
%                               Enabled non-graded ideals
%                               Fixed trivial ideal bug
%                               Removed subform
%                               Renamed xtrace -> xstats
%
%
% Algebraic mode entry points
%
% xideal(S) or xideal(S,r)
%  calculates an exterior Groebner basis for the list of generator S,
%  optionally up to degree r.
%
% xmodulo(F,S) or F xmodulo S
% reduces F with respect to an exterior Groebner basis for the list of
% generators S.  In the first format, F may be either a single exterior
% form, or a list of forms.  If this routine is used more than once,
% and S does not change between calls, then the Groebner basis is not
% recalculated.

% xmodulop(F,S) or F xmodulop S
% reduces F with respect to the set of exterior polynomials S, which is
% not necessarily a Groebner basis.  In the first format, F may be
% either a single exterior form, or a list of forms.  This routine can
% be used in conjunction with xideal to produce the same effect as
% xmodulo:  F xmodulo S = F xmodulop xideal(S,degree F).

% Switches
%
% xstats        - Produces counting and timing information (default OFF)
% xfullreduce   - Allows reduced Groebner bases to be calculated
%                    (default ON)

% ======================================================================


% ----------------------------------------------------------------------

create!-package('(xideal xutils),'(contrib xideal));

fluid '(!*xstats !*xfullreduce !*xdebug
        xtruncate!* xideal!* xbasis!* xdegree!*
        xidealtime!* xspolytime!* xwedgestime!*
        xreducetime!* xautoreducetime!*
        xwedges!* newxwedges!* xspolys!* newxspolys!*);

!*xdebug := nil;        % non-nil prints algorithm trace
xtruncate!* := nil;     % non-nil gives truncation degree for GB

xbasis!* := nil;        % last input set to xmodulo
xideal!* := nil;        % last output from xmodulo
xdegree!* := nil;       % largest recent degree to xmodulo

switch 'xstats;
!*xstats := nil;

switch 'xfullreduce;
!*xfullreduce := t;

infix xmodulo;
precedence xmodulo,freeof;

infix xmodulop;
precedence xmodulop,freeof;


% ----------------------------------------------------------------------

% These definitions copied from E. Schruefer's EXCALC for compilation.

global '(dimex!*);

smacro procedure ldpf u;
   %selector for leading standard form in patitioned sf;
   caar u;

smacro procedure !*k2pf u;
   u .* (1 ./ 1) .+ nil;

smacro procedure negpf u;
   multpfsq(u,(-1) ./ 1);

% ----------------------------------------------------------------------


symbolic operator xmodulo;
symbolic procedure xmodulo(x,l);
% x is prefix form or algebraic list, l is algebraic list, result is
% (possibly algebraic list of) !*sq prefix
% if generators haven't changed, use last ideal (speeds up loops)
begin scalar z;
 l := !*al2sl l;
 if atom x or car x neq 'list then
   z := x
 else   % extract maximum degree from list
   <<z := 0;
     x := 'list . !*al2sl x;
     for each y in cdr x do if xdegree y > xdegree z then z := y>>;
 xtruncate!* := xdegree!*; % just in case it was used in-between
 if (l neq xbasis!*) or xdegreecheck z then
   <<xideal!* := xideal0(l,xdegree z);
     xdegree!* := xdegree z;
     xbasis!* := l>>;
 z := if atom x or car x neq 'list then list x else cdr x;
 z := for each y in z collect
        mk!*sq !*pf2sq xreduce(xreorder partitop y,xideal!*);
 return if atom x or car x neq 'list then car z
         else purge strip0('list . z);
end;


% ----------------------------------------------------------------------


symbolic operator xmodulop;
symbolic procedure xmodulop(x,l);
% x is prefix form or algebraic list, l is algebraic list, result is
% (possibly algebraic list of) !*sq prefix
begin
 l := for each q in !*al2sl l collect xreorder partitop q;
 if atom x or car x neq 'list then
   return mk!*sq !*pf2sq xreduce(xreorder partitop x,l);
 return purge strip0('list . for each y in !*al2sl x collect
                         mk!*sq !*pf2sq xreduce(xreorder partitop y,l));
end;


% ----------------------------------------------------------------------


put('xideal,'psopfn,'xidealeval);

symbolic procedure xidealeval u;
% u is a list with one or two items: an algebraic list of p-forms
% and an integer
begin scalar l,r,n;
 n := length u;
 if n < 1 or n > 2 then rederr "Wrong number of arguments to XIDEAL";
 l := !*al2sl reval car u;
 if n = 2 then r := reval cadr u;
return 'list . for each f in xideal0(l,r) collect mk!*sq !*pf2sq f;
end;


% ----------------------------------------------------------------------


symbolic procedure xideal0(p,r);
% p is list of prefix, r is an integer or nil, result is list of pf's

xidealpf(for each f in p collect partitop f,r);


% ----------------------------------------------------------------------


symbolic procedure xidealpf(p,r);
% p is list of pf's, r is an integer or nil, result is list of pf's
begin scalar p1,p2,d,nongraded,vars;
 rmsubs();
 if !*xstats then xstatsinitialise();
 xtruncate!* := r;
 p := nil . p;
 while (p := cdr p) do
   begin
    vars := xvarcheck(car p,vars);
    d := xhomogeneous car p;
    if null d then <<nongraded := t; xtruncate!* := nil>>;
    if d = 0 then  % quick escape, trivial ideal
      <<p := p1 := list partitop 1; p2 := nil>>
    else if d = 1 then p1 := xreorder car p . p1
    else p2 := xreorder car p . p2;
  end;
 p1 := xautoreduce p1;
 for each s in p2 do
   if (s := xreduce(s,append(p1,p))) and not xdegreecheck ldpf s then
     begin
      p := xidealpf0(p,s);
      if !*xstats
        then <<prin2 "GB size  : "; prin2t(length p + length p1)>>;
      if !*xfullreduce then p := xautoreduce p;
      if !*xstats and !*xfullreduce then
        <<prin2 "RGB size : "; prin2t(length p + length p1)>>;
     end;
 p := append(p1,p);
 if nongraded and !*xfullreduce and p1 then p := xautoreduce p;
 if !*xstats then xstatsprint();
 return p;
end;


% ----------------------------------------------------------------------


symbolic procedure xstatsinitialise;
begin
 xidealtime!* := time(); xspolytime!* := 0; xwedgestime!* := 0;
 xreducetime!* := 0; xautoreducetime!* := 0;
 xwedges!* := 0; newxwedges!* := 0;
 xspolys!* := 0; newxspolys!* := 0;
end;


% ----------------------------------------------------------------------


symbolic procedure xstatsprint;
begin
 xidealtime!* := time() - xidealtime!*;
 prin2 "Wedges generated     : "; prin2t xwedges!*;
 prin2 "Wedges surviving     : "; prin2t newxwedges!*;
 prin2 "Survival rate        : ";
 if xwedges!* = 0 then prin2 0 else prin2((100*newxwedges!*)/xwedges!*);
 prin2t "%";
 prin2 "Spolys generated     : "; prin2t xspolys!*;
 prin2 "Spolys surviving     : "; prin2t newxspolys!*;
 prin2 "Survival rate        : ";
 if xspolys!* = 0 then prin2 0 else prin2((100*newxspolys!*)/xspolys!*);
 prin2t "%";
 prin2 "Total computing time : "; prin2 xidealtime!*; prin2t " ms";
 prin2 "Spoly time           : "; prin2 xspolytime!*; prin2t " ms";
 prin2 "Wedges time          : "; prin2 xwedgestime!*; prin2t " ms";
 prin2 "Reduction time       : "; prin2 xreducetime!*; prin2t " ms";
 prin2 "Auto-reduction time  : "; prin2 xautoreducetime!*; prin2t " ms";
end;


% ----------------------------------------------------------------------


symbolic procedure xidealpf0(p,s);
% p is list of pf's, s is pf, result is list of pf's
% p is a GB, result is a GB containing p and s.
begin scalar h,b,y;
 if !*xstats then
   <<newxspolys!* := newxspolys!* - 1;
     princ '#; if !*xdebug then prin2t s>>;
 while s do
   begin
    if !*xstats then newxspolys!* := newxspolys!* + 1;
    y := xwedges(s,append(p,h));
    if ldpf car y = 1 then % quick escape, trivial ideal
      return <<s := nil; h := nil; p := list partitop 1;>>;
    for each f in y do
      <<b := append(b,
             append(for each j in p collect list(j,f),
                    for each j in h collect list(j,f)));
        h := append(h,list f)>>;
    s := nil;
    while b and null s do
      <<s := xreduce(xspoly(car b),append(p,h));
        if !*xstats and s then
          <<princ "$";
            if !*xdebug then
              <<prin2t caar b; prin2 "*"; prin2t cadar b;
                prin2 " --> "; prin2t s>> >>;
        b := cdr b>>;
   end;
 if !*xstats then prin2t "";
 return append(p,h);
end;


% ----------------------------------------------------------------------


symbolic procedure xspoly p;
% p is a list of two reordered pf's, result is reordered pf
begin scalar u,v,lu,lv,cu,cv,z,t0;
 if !*xstats then t0 := time();
 u := car p; v := cadr p;
 if null u or null v then return nil;
 lu := ldpffax u;
 lv := ldpffax v;
 cu := setdiff(lu,lv);
 cv := setdiff(lv,lu);
 if (cu = lu) % cv = lv as well in this case
    or xdegreecheck('wedge . append(lu,cv)) then return nil;
 if null cu then cu := list 1;  if null cv then cv := list 1;
 u := partitwedge list('wedge . cv,mk!*sq !*pf2sq u);
 v := partitwedge list('wedge . cu,mk!*sq !*pf2sq v);
 z := negsq quotsq(lc u,lc v);
 z := xreorder addpf(u,multpfs(1 .* z .+ nil,v));
 if !*xstats then xspolys!* := xspolys!* + 1;
 if !*xstats then xspolytime!* := xspolytime!* + time() - t0;
 return z;
end;


% ----------------------------------------------------------------------


symbolic procedure xwedges(s,p);
% s is reordered pf, p is a list of reordered pf's,
% result is a list of reordered pf's (first element is always s, unless
% trivial ideal detected)
begin scalar t0,y,h,q,l;
 if xdegreecheck ldpf s then
   rederr "Major problem -- please contact XIDEAL authors";
 if d and d leq 1 where d = xhomogeneous s then return list s;
 if !*xstats then t0 := time();
 if xtruncate!* then xtruncate!* := xtruncate!* - 1;
 y := list s;
 h := p;
 while y do
   begin
    s := car y;
    y := cdr y;
    h := append(h,list s);
    if xdegreecheck ldpf s or null red s then return;
    l := nil . ldpffax s;
    while (l := cdr l) do
      begin
       if !*xstats then xwedges!* := xwedges!* + 1;
       q := xreorder wedgepf(!*k2pf car l,s);
       if null (q := xreduce(q,append(h,y))) then return;
       if !*xstats then
         <<newxwedges!* := newxwedges!* + 1;
           princ "^";
           if !*xdebug then
             <<prin2 car l; prin2 " --> "; prin2t q>> >>;
       if ldpf q = 1 then % quick escape, trivial ideal
         return <<l := list nil; y := nil; % terminate loops
                  h := append(p,list partitop 1)>>;
       y := append(y, list q);
      end;
   end;
 if xtruncate!* then xtruncate!* := xtruncate!* + 1;
 if !*xstats then xwedgestime!* := xwedgestime!* + time() - t0;
 return setdiff(h,p);
end;


% ----------------------------------------------------------------------


symbolic procedure xautoreduce0 p;
% p is a list of pf's, result is a list of pf's
% symbolic mode entry point to xautoreduce for unordered pf's
foreach g in xautoreduce(foreach f in p collect xreorder f)
  collect repartit g;


% ----------------------------------------------------------------------


symbolic procedure xautoreduce p;
% p is a list of reordered pf's, result is a list of reordered pf's
begin scalar xreducetime!*, % so reduction and auto-reduction times
                            % disjoint.
             q,s,x,t0;
 if !*xstats then xreducetime!* := t0 := time();
 while p do
   begin
%    s := xleast p; p := delete(s,p);
    s := car p; p := cdr p;     % seems to be faster
    x := xreduce(s,append(p,q));
    if x then q := x . q;
    if x neq s then
      <<p := append(p,q); q := nil>>;
   end;
 if !*xstats then xautoreducetime!* := xautoreducetime!* + time() - t0;
 return reverse q;
end;


% ----------------------------------------------------------------------


symbolic procedure xreduce0(s,p);
% s is pf, p is list of pf's, result is pf
% symbolic mode entry point to xreduce for unordered pf's

xreduce1(xreorder s,foreach f in p collect xreorder f);


% ----------------------------------------------------------------------


symbolic procedure xreduce(s,p);
% s is reordered pf, p is list of reordered pf's, result is reordered pf
begin scalar t0,xwedgestime!*; % so wedge and reduction times disjoint
 if !*xstats then t0 := time();
 s := xreorder xreduce1(s,p);
 if !*xstats then xreducetime!* := xreducetime!* + time() - t0;
 return s;
end;


% ----------------------------------------------------------------------


symbolic procedure xreduce1(s,p);
% s is reordered pf, p is list of reordered pf's, result is pf (NOT
% reordered)
if null s then nil else
begin scalar q,f,x,y,z;
 q := p;
 while s and q do
   begin
%    f := xleast q; q := delete(f,q);
    f := car q; q := cdr q;     % seems to be faster
    if x := xdivs(ldpffax s,ldpffax f) then
      <<y := partitsq!* simp list('wedge,x,prepsq !*pf2sq(lt f .+ nil));
        z := negsq quotsq(lc s,lc y);
        y := partitsq!* simp list('wedge,x,prepsq !*pf2sq f);
        % the repartit here needed because of ordering differences
        s := xreorder repartit addpf(s,multpfs(1 .* z .+ nil,y));
        q := p>>;
   end;
 return if s then addpf(lt s .+ nil,xreduce1(red s,p));
end;


% ----------------------------------------------------------------------


symbolic procedure xdivs(u,v);
% u,v are kernels, result is kernel
% seems to be faster than old one
begin scalar x;
 if setdiff(v,intersection(u,v)) then return nil;
 if (x := setdiff(u,v)) then return 'wedge . x
 else return 1;
end;


% ----------------------------------------------------------------------


symbolic procedure ldpffax u;
% returns list of factors in a wedge product (including single factors)

(if atom x or car x neq 'wedge then list x else cdr x) where x = ldpf u;


% ----------------------------------------------------------------------


symbolic procedure wedgepf(u,v);
% u and v are pf, result is pf
partitwedge list(mk!*sq !*pf2sq u,mk!*sq !*pf2sq v);


% ----------------------------------------------------------------------


symbolic procedure xreorder u;
% reorders pf u into (graded) lexicographical order. basic ordering
% of 1-forms determined by worderp.
sort(u,function xordpft);


% ----------------------------------------------------------------------


symbolic procedure xordpft(u,v);
% u and v are terms from a pf
apply(function xgradlexl,              % can put xlexl or xgradlexl here
      list(sort(ldpffax list u,function worderp),
           sort(ldpffax list v,function worderp)));


% ----------------------------------------------------------------------


symbolic procedure xlexl(u,v);
% u and v are sorted lists of factors from wedge products
if null v then t
else if null u then nil
else if car v = 1 then t
else if car u = 1 then nil
else if car u = car v then xlexl(cdr u,cdr v)
else worderp(car u,car v);


% ----------------------------------------------------------------------


symbolic procedure xgradlexl(u,v);
% u and v are sorted lists of factors from wedge products
if car v = 1 then t
else if car u = 1 then nil
else if length u = length v then xlexl(u,v)
else length u > length v;


% ----------------------------------------------------------------------


symbolic procedure xleast p;
% p is a list of reordered pf's, result is a reordered pf
begin scalar s,x,y;
 if p then s := car p;
 p := nil . p;
 while (p := cdr p) do
   if xordpft(lt s,lt car p) then s := car p;
 return s;
end;


% ----------------------------------------------------------------------


symbolic procedure xdegree qform;
% xdegree(qform: pform (prefix) )
% -> q: integer
%
% This procedure gives the degree of a homogeneous form.
% Can distinguish 0- and p-forms.
% Behaves erratically with inhomogeneous forms.

(if null x then 0 else x)
  where x = (deg!*form qf)
    where qf = if eqcar(qform,'!*sq) then prepsq cadr qform else qform;


% ----------------------------------------------------------------------


symbolic procedure xvarcheck(u,v);
% u is pf, v is list of kernels, result is list of kernels

if null u then v
else begin scalar vv;
 vv := setdiff(ldpffax u, 1 . v);
 v := append(v,vv);
 if fixp dimex!* and length v > dimex!* then
   rederr "more independent 1-forms than dimension of space in XIDEAL";
 foreach f in vv do if xdegree f > 1 then
   rederr "p-form with p > 1 in XIDEAL";
 return xvarcheck(red u,v);
end;


% ----------------------------------------------------------------------


symbolic procedure xhomogeneous u;
% u is pf, result is degree of u if homogeneous, otherwise nil

if null u then 0
else if length u = 1 then xdegree ldpf u
else (if d = xhomogeneous red u then d) where d = xdegree ldpf u;


% ----------------------------------------------------------------------


symbolic procedure xdegreecheck u;
% u is prefix
% result is non-nil if degree of u exceeds truncation in graded GB's

xtruncate!* and (xdegree u > xtruncate!*);


% ----------------------------------------------------------------------


xstatsinitialise(); % so that calls from other packages don't get
                    % non-numeric errors if xstats happens to be on.



% ----------------------------------------------------------------------


endmodule;


module xidealutils;

% Various list utilities

% ----------------------------------------------------------------------


symbolic procedure !*al2sl l;

% Converts algebraic mode lists to symbolic mode lists, with an error
% if conversion not possible

if atom l or car l neq 'list then typerr(l,'list) else
  for each j in cdr l collect if eqcar(j,'!*sq) then prepsq cadr j
                               else j;


% ----------------------------------------------------------------------


symbolic procedure deleteall(u,v);
% removes all top-level occurences of u from v
if null v then nil
else if car v = u then deleteall(u, cdr v)
     else car v . deleteall(u, cdr v);


% ----------------------------------------------------------------------


symbolic procedure purge l;
% removes extra copies of repeated elements from algebraic and symbolic
% lists
if null l then nil
else car l . purge deleteall(car l,cdr l);


% ----------------------------------------------------------------------


symbolic procedure strip0 l;
% removes all all NIL's and 0's from algebraic and symbolic lists
if null l then nil
else deleteall(0,deleteall(nil,l));


% ----------------------------------------------------------------------

endmodule;


end;
