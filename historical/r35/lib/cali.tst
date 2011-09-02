% Author H.-G. Graebe | Univ. Leipzig | Version 20.10.93
% graebe@informatik.uni-leipzig.d400.de

COMMENT

This is an example session demonstrating and testing the facilities
offered by the commutative algebra package CALI.

END COMMENT;

algebraic;
on echo;

% Example 1 : Generating ideals of affine and projective points.


    vars:={t,x,y,z};
    setring(vars,degreeorder vars,revlex);
    mm:=mat((1,1,1,1),(1,2,3,4),(2,1,4,3));

  % The ideal with zero set at the point in A^4 with coordinates
  % equal to the row vectors of mm :

    setideal(m1,affine_points mm);

  % All parameters are as they should be :

    gbasis m1$
    dim m1;
    degree m1;
    groebfactor m1;
    resolve m1$
    bettinumbers m1;

  % The ideal with zero set at the point in P^3 with homogeneous 
  % coordinates equal to the row vectors of mm :

    setideal(m2,proj_points mm);

  % All parameters as they should be ?

    gbasis m2$
    dim m2;
    degree m2;
    groebfactor m2;

  % It seems to be prime ?

    isprime m2;

  % Not, of course, but it is known to be unmixed. Hence we can use

    easyprimarydecomposition m2;

  
% Example 2 : 
% An affine monomial curve with generic point (t^7,t^9,t^10).

    setideal(m,affine_monomial_curve({7,9,10},{x,y,z}));

  % The base ring was changed as side effect :

    getring(); 
    vars:=first getring m;

  % Some advanced commutative algebra .
  % The analytic spread of m.

    analytic_spread m;

  % The Rees ring Rees_R(vars) over R=S/m.
    
    blowup(m,vars,{u,v,w}); 

  % gr_R(vars), the associated graded ring of the irrelevant ideal
  % over R. The short way.

    interreduce sub(x=0,y=0,z=0,ws); 

  % The long (and more general) way. Gives the result in another
  % embedding. 
  
    % Reste the base ring, since it was changed by blowup as a side
    % effect.  
    setring getring m$
    assgrad(m,vars,{u,v,w}); 

  % Comparing the Rees algebra and the symmetric algebra of M :
  
    setring getring m$
    setideal(rees,blowup({},m,{a,b,c}));
    setring getring m$
    setideal(sym,sym(m,{a,b,c}));
    gbasis rees$ gbasis sym$
    modequalp(rees,sym);

  % Symbolic powers :

    setring getring m$
    setideal(m2,idealpower(m,2));

  % Let's compute a second symbolic power :

    setideal(m3,symbolic_power(m,2));

  % It is different from the ordinary second power.
  % Hence m2 has a trivial component.

    gbasis m2$ gbasis m3$
    modequalp(m2,m3);

  % Here is the primary decomposition :

    pd:=primarydecomposition m2;

  % Compare the result with m2 :

    setideal(m4,matintersect(first first pd, first second pd));
    gbasis m4$
    modequalp(m2,m4);

  % Compare the result with m3 :

    setideal(m4,first first pd)$
    gbasis m4$
    modequalp(m3,m4);

  % The trivial component can also be removed with a 
  % stable quotient computation :

    setideal(m5,matstabquot(m2,vars))$
    gbasis m5$
    modequalp(m3,m5);


% Example 3 : The Macaulay curve.

    setideal(m,proj_monomial_curve({0,1,3,4},{w,x,y,z}));
    vars:=first getring();
    gbasis m;
 
  % Test whether m is prime :

    isprime m;

  % A resolution of m :
    
    resolve m;

  % m has depth = 1 as can be seen from the 
    
    gradedbettinumbers m; 

  % Another way to see the non perfectness of m :
    
    hilbseries m; 

  % Just a third approach. Divide out a parameter system :

    ps:=for i:=1:2 collect random_linear_form(vars,1000);
    setideal(m1,matsum(m,ps))$ gbasis m1$
 
    % dim should be zero and degree > degree m = 4.
    dim m1; 
    degree m1; 

  % The projections of m on the coord. hyperplanes.
 
    for each x in vars collect eliminate(m,{x}); 

% Example 4 : Two submodules of S^4.
  
  % Get the stored result of the earlier computation.

    r:=resolve m$

  % See whether cali!=degrees contains a relict from earlier
  % computations.  
  
    getdegrees();

  % Introduce the 2nd and 3rd syzygy module as new modules.
  % Both are submodules in S^4.

    setmodule(m1,second r)$ setmodule(m2,third r)$ 
    gbasis m1; 
 
  % The second is already a gbasis.

    setgbasis m2; 
    getleadterms m1; getleadterms m2;

  % Since rk(F/M)=rk(F/in(M)), they have ranks 1 resp. 3.

    dim m1;
    indepvarsets m1;

  % Its intersection is zero :

    matintersect(m1,m2);

  % Its sum :
 
    setmodule(m3,matsum(m1,m2));
    gbasis m3;
    dim m3;

  % Hence it has a nontrivial annihilator :

    annihilator m3;
 
  % To get a meaningful Hilbert series make m1 homogeneous :
 
    setdegrees {1,x,x,x}; 
 
  % Reevaluate m1 with the new column degrees. 

    setmodule(m1,m1)$
    gbasis m1;
    hilbseries m1;

% Example 5 : From the MACAULAY manual (D.Bayer, M.Stillman).
% An elliptic curve on the Veronese in P^5.

    rvars:={x,y,z}$ svars:={a,b,c,d,e,f}$
    r:=setring(rvars,degreeorder rvars,revlex)$
    s:=setring(svars,{for each x in svars collect 2},revlex)$
    map:={s,r,{a=x^2,b=x*y,c=x*z,d=y^2,e=y*z,f=z^2}};
    preimage({y^2z-x^3-x*z^2},map);

% Example 6 : The preimage under a rational map.

    r:=setring({x,y},{},lex)$ s:=setring({t},{},lex)$
    map:={r,s,{x=2t/(t^2+1),y=(t^2-1)/(t^2+1)}};
  
  % The preimage of (0) is the equation of the circle :

    ratpreimage({},map);

  % The preimage of the point (t=3/2) :

    ratpreimage({2t-3},map);


% Example 7 : A zerodimensional ideal.

    setring({x,y,z},{},lex)$
    setideal(n,{x**2 + y + z - 3,x + y**2 + z - 3,x + y + z**2 - 3});

  % The groebner algorithm with factorization :

    groebfactor n;

  % Change the term order and reevaluate n :

    setring({x,y,z},{{1,1,1}},revlex)$
    setideal(n,n);
    gbasis n;

  % its primes :
 
    zeroprimes n;

  % a vector space basis of S/n :

    getkbase n;

% Example 8 : A modular computation.

    on modular$
    setmod 181; setideal(n1,n); zeroprimes n1;
    setmod 7; setideal(n1,n); zeroprimes n1;
 
  % Hence some of the primes glue together mod 7.

    zeroprimarydecomposition n1;
    off modular$

% Example 9 : Independent sets once more.
  
    n:=10$
    vars:=for i:=1:(2*n) collect mkid(x,i)$
    setring(vars,{},lex)$
    setideal(m,for j:=0:n collect 
            for i:=(j+1):(j+n) product mkid(x,i));
    setgbasis m$
    indepvarsets m;
    dim m;
    degree m;


% Example 10 : An example from [ Alonso, Mora, Raimondo ] 

    vars := {z,x,y}$
    r:=setring(vars,{},lex)$
    setideal(m,{x^3+(x^2-y^2)*z+z^4,y^3+(x^2-y^2)*z-z^4});
    gbasis m$
    dim m;
    degree m;

  % 2 = codim m is the codimension of the curve m. The defining 
  % equations of the singular locus with their nilpotent structure.

    singular_locus(m,2); 
    groebfactor ws; 

  % Hence this curve has two singular points : 
  % (x=y=z=0) and (y=-x=256/81,z=64/27)
  % Let's find the brances of the curve through the origin.
  % The first critical tropism is (-1,-1,-1).

    off noetherian$
    setring(vars,{{-1,-1,-1}},lex)$
    setideal(m,m);
    % Let's test Lazard's approach.
    off lazy$
    gbasis m;
    dim m;
    degree m;

  % Find the tangent directions not in z-direction :

    tangentcone m; 
    setideal(n,sub(z=1,ws));
    setring r$ on noetherian$ setideal(n,n)$
    gbasis n;
    degree n;

  % The points of n outside the origin.

    matstabquot(n,{x,y}); 

  % Hence there are two branches x=z'*(a-3+x'),y=z'*(a+y'),z=z'
  % with the algebraic number a : a^2-3a+3=0
  % and the new equations for (z',x',y') :

    setrules {a^2=>3a-3};
    sub(x=z*(a-3+x),y=z*(a+y),m);
    setideal(m1,matqquot(ws,z));

  % This defines a loc. smooth system at the origin, since the
  % jacobian at the origin of the gbasis is nonsingular :

    off noetherian$
    % Test Mora's approach.
    on lazy$
    setring getring m;
    setideal(m1,m1);
    gbasis m1;

    % clear the rules previously set.
    setrules {}; 


% Example 11 : The standard basis of another example. 
% Comparing Mora's and Lazard's approaches.

    vars:={x,y}$
    setring(vars,localorder vars,lex);
    ff:=x^5+y^11+(x+x^3)*y^9;
    setideal(p,flatten matjac({ff},vars));

  % Mora's approach : Only top reduction allowed.
  
    gbasis p;

  % Lazard's approach : Total normal forms of homogenized polynomials
  % allowed. Hence the computation produces other normal forms.

    off lazy;
    setideal(p,p)$
    gbasis p;

    dim p;
    degree p;

% Example 12 : A local intersection.

    setring({x,y,z},{},revlex);
    on lazy;
    m1:=matintersect({x-y^2,y-x^2},{x-z^2,z-x^2},{y-z^2,z-y^2});
  
  % Delete polynomial units post factum :
  
    deleteunits ws;
    interreduce ws;

  % Detecting polynomial units early :

    on detectunits;
    m1:=matintersect({x-y^2,y-x^2},{x-z^2,z-x^2},{y-z^2,z-y^2});
    off detectunits;

  % Return to a noetherian term order:
   
    vars:={x,y,z}$
    setring(vars,degreeorder vars,revlex);
    on noetherian;

% Example 13 : Use of "mod".

  % Polynomials modulo ideals :

    setideal(m,{2x^2+y+5,3y^2+z+7,7z^2+x+1});
    x^2*y^2*z^2 mod m;

  % Lists of polynomials modulo ideals :

    {x^3,y^3,z^3} mod gbasis m;

  % Matrices modulo modules :

    mm:=mat((x^4,y^4,z^4));
    mm1:=tp<< ideal2mat m>>;
    mm mod mm1;

% Example 14 : Powersums through elementary symmetric functions.

    vars:={a,b,c,d,e1,e2,e3,e4}$
    setring(vars,{},lex)$
    m:=interreduce {a+b+c+d-e1,
        a*b+a*c+a*d+b*c+b*d+c*d-e2,
        a*b*c+a*b*d+a*c*d+b*c*d-e3,
        a*b*c*d-e4};
    
    for n:=1:5 collect a^n+b^n+c^n+d^n mod m;    

% Example 15 : The setrules mechanism. 

    setring({x,y,z},{},lex)$
    setrules {aa^3=>aa+1};
    setideal(m,{x^2+y+z-aa,x+y^2+z-aa,x+y+z^2-aa});
    gbasis m;
    
    % Clear the rules previously set.
    setrules {};

% Example 16 : The same example with advanced coefficient domains.

    load arnum;
    defpoly aa^3-aa-1;
    setideal(m,{x^2+y+z-aa,x+y^2+z-aa,x+y+z^2-aa});
    gbasis m;

  % The following needs some more time since factorization of arnum's
  % is not so easy :

    groebfactor m;
    off arnum;
    off rational;

% Example 17 : The square of the 2-minors of a symmetric 3x3-matrix.

    vars:=for i:=1:6 collect mkid(x,i);
    setring(vars,degreeorder vars,revlex);

  % Generating the ideal :

    mm:=mat((x1,x2,x3),(x2,x4,x5),(x3,x5,x6));
    m:=minors(mm,2);
    setideal(n,idealpower(m,2));

  % The ideal itself :

    gbasis n;
    length n;
    dim n;
    degree n;

  % Its unmixed radical.

    unmixedradical n;

  % Its equidimensional hull. This needs some more time :

    n1:=eqhull n;
    length n1;
    setideal(n1,n1)$ gbasis n1$
    submodulep(n,n1);
    submodulep(n1,n);

  % Hence there is an embedded component. Let's find it making an
  % excursion to symbolic mode. Of course, this can be done also 
  % algebraically.

    symbolic;
    n:=get('n,'basis);

  % This needs even more time than the eqhull, of course.

    u:=primarydecomposition!* n;
    for each x in u collect easydim!* second x;
    for each x in u collect degree!* first x;

  % Hence the embedded component is a trivial one. Let's divide it
  % out by a stable ideal quotient calculation :

    algebraic;
    setideal(n2,matstabquot(n,vars));
    gbasis n2$
    modequalp(n1,n2);

end;
