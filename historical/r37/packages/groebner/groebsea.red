module groebsea;
 
% support of search for reduction polynomials
 
fluid '(thirdvalue!* fourthvalue!* hcount!* !*groebWeak);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  search for reduction candidates in a list
 
symbolic procedure groebsearchinlist (vev,g);
  % search for a polynomial in the list G, such that the lcm divides
  % vev; G is expected to be sorted in descending sequence
    if null G then nil
    else if buch!-vevdivides!?(vdpevlmon car g, vev) then car g
    else groebsearchinlist (vev,cdr g);
 
 
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  search tree for polynomials
%  simple variant: mapped to search list
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
symbolic procedure groebstreeadd (poly,stru);
% add one polynomial to the tree
% if this is a simple polynomial (mono or bino), reform
% the tree
   if hcount!* #< 5000 then vdplsortin(poly,stru)
     else vdplsortinreplacing(poly,stru);
 
symbolic procedure groebsearchinstree (vev,stru);
% search a polynomial corresponding to the exponent vector vev
     groebsearchinlist (vev,stru);

symbolic procedure groebstreeextract stru;
% gives a linear list of all polynomials in the tree
                 stru;

symbolic procedure groebstreereconstruct u;
% reconstructs a tree from a linear list of polynomials
               vdplsort u;

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
% reforming G, D and G99 when a very simple polynomial was
% found (e.g. a monomial, a binomial)
 
symbolic procedure groebsecondaryreduction(poly,g,g99,d,gc,mode);
    % if poly is a simple polynomial, the polynomials in G and G99
    % are reduced in a second pass. Result is G, secondvalue is G99.
    % mode says, that G99 has to be modified in place.
  begin scalar vev,p,pl,x,rep,first,rpoly,break;
    mode := nil;
    secondvalue!* := g99; thirdvalue!* := d; fourthvalue!* := gc;
    vev := vdpevlmon poly; rpoly := vdpred poly;
        % cancel redundant elements in G99
    for each p in g99 do if buch!-vevdivides!?(vev,vdpevlmon p) 
                  then g99:=delete(p,g99);
    if vdplength poly > 2 or  vevzero!? vev then return g;
    if !*groebweak and not vdpzero!? rpoly 
       and (groebweaktestbranch!=1(poly,g,d)) then return 'abort;
        !*trgroeb and groebmess50 g;
    pl := union(g,g99);
    first := t;
    while pl and not break do
      << p:= car pl; pl := cdr pl;
         if groebprofitsfromvev(p,vev) then
                          % replace by simplified version
            <<x := groebnormalform1(p,poly);
              x := groebsimpcontnormalform x;
              x := vdpenumerate x;
                 if first then !*trgroeb and groebmess20(poly);
                      first := nil;
                      !*trgroeb and groebmess21(p,x);
                  rep := (p . x) . rep;
              if not vdpzero!? x and
		 vevzero!? vdpevlmon x then break := t; % 1 found 
             >> >>;
    if break then return 'abort;
                           % reform G99
    g99 := for each p in g99 collect groebsecondaryreplace(p,rep);
    secondvalue!* :=  groebsecondaryremovemultiples g99;
                           % reform D
    thirdvalue!* := d;
                          % reform Gc
    fourthvalue!* :=
      groebsecondaryremovemultiples
        for each y in gc collect groebsecondaryreplace(y,rep);
    g:=for each y in g collect groebsecondaryreplace(y,rep);
         !*trgroeb and groebmess50 g;
    return groebsecondaryremovemultiples g;
  end;

symbolic procedure groebsecondaryremovemultiples g;
    if null g then nil else
    if vdpzero!? car g or member(car g,cdr g) then 
		groebsecondaryremovemultiples cdr g else
    car g  . groebsecondaryremovemultiples cdr g;

symbolic procedure groebsecondaryreplace(x,rep);
   (if y then cdr y else x) where y = atsoc(x,rep);

endmodule;
 
end;
