module desir;  % Special case differential equation solver.

algebraic;

%        ***************************************************************
%        *                                                             *
%        *                           DESIR                             *
%        *                           =====                             *
%        *                                                             *
%        *      SOLUTIONS FORMELLES  D'EQUATIONS DIFFERENTIELLES       *
%        *                                                             *
%        *                   LINEAIRES ET HOMOGENES                    *
%        *                                                             *
%        * AU VOISINAGE DE POINTS SINGULIERS REGULIERS ET IRREGULIERS  *
%        *                                                             *
%        ***************************************************************
%
%             Differential linear homogenous Equation Solutions in the
%                   neighbourhood of Irregular and Regular points
%
%                            Version 3.1  -  Septembre 89
%
%
%                       Groupe de Calcul Formel de Grenoble
%                                laboratoire TIM3
%
%                          E-mail: dicresc@afp.imag.fr


% Ce logiciel permet l'etude des solutions formelles d'une equation
%   differentielle ordinaire homogene a coefficients polynomiaux sur Q
%   et d'ordre quelconque au voisinage de l'origine point singulier
%   regulier ou irregulier, ou point ordinaire.  Des outils ont ete
%   ajoutes afin de pouvoir traiter des equations avec un second membre
%   polynomial, des parametres et en un point singulier autre que
%   l'origine.

% Il peut etre utilise de 2 manieres: * directe ( procedure DELIRE )
%                                     * interactive ( procedure DESIR )

% La procedure de base est la procedure DELIRE qui permet de calculer
%   les solutions d'une equation differentielle lineaire homogene
%   au voisinage de l'origine.

% La procedure DESIR est une procedure sans parametre qui permet
% d'appeler DELIRE sans avoir a "preparer" les donnees, c'est-a-dire de
% maniere interactive, autonome et qui propose, de plus, certaines
% transformations sur l'equation initiale.  Ceci permet de partir d'une
% equation ayant des points singuliers differents de l'origine, un
% second membre polynomial, des parametres, de maniere tres confortable.


%                       **************************
%                       *                        *
%                       *  FORMES DES SOLUTIONS  *
%                       *                        *
%                       **************************


% Nous avons cherche a representer les solutions sous la forme la plus
% simple possible.  Pour cela nous avons ete amenes a choisir
% differentes formes selon la complexite de l'equation (parametres) et
% l'utilisation ulterieure que l'on veut faire de ces solutions.
%
% "solution generale"  =  {......, { sol_eclate , cond },....}
% -------------------
%
%           ( s'il y a des parametres, les solutions de base peuvent
%             avoir des expressions differentes selon les valeurs des
%             parametres )
%
%     cond = liste des conditions ou liste vide (s'il n'y a pas de
%            condition)
%
%     sol_eclate = { q , grille , polysol , r }
%            ( " solution eclatee " permet d'obtenir immediatement des
%             renseignements precis sur la solution )
%
% La variable dans l'operateur differentiel etudie etant x, les
% solutions s'expriment en fonction d'une nouvelle variable &x, qui est
% une puissance fractionnaire de x, de la facon suivante :
%
%         q       : polynome  en 1/&x a coefficients complexes
%         grille  : &x = x**grille
%         polysol : polynome en log(&x) a coefficients des series
%                   formelles en &x
%         r       : racine de l'equation indicielle conduisant a cette
%                   solution
%
%                         qx  r*grille
% "solution standard"  = e   x         polysolx
%  -----------------
%         qx et polysolx etant les expressions q et polysol dans
%         lesquelles on a remplace &x par x**grille
%
% N.B. : la forme de ces solutions se simplifie suivant la nature du
%        point origine.
%   - si 0 est point singulier regulier : les series apparaissant dans
%     polysol sont convergentes, grille = 1 et q = 0.
%   - si 0 est point regulier, on a de plus : polysol est constant en
%     log(&x) (pas de termes logarithmiques).


%                   ***********************************
%                   *                                 *
%                   *     UTILISATION INTERACTIVE     *
%                   *                                 *
%                   ***********************************
%

fluid '(!*trdesir);

symbolic switch trdesir;

global '(multiplicities!*);

flag('(multiplicities!*),'share);   % Since SOLVE not loaded when file
                                    % compiled.

procedure desir ;
%===============;
%
% Calcul des solutions formelles d'une equation differentielle lineaire
% homogene de maniere interactive.
% La variable dans cette equation est obligatoirement x.
%                                     -----------------
% La procedure demande l'ordre et les coefficients de l'equation, le
% nom des parametres s'il y en a, puis si l'on souhaite une
% transformation de cette equation et laquelle ( par exemple, ramener
% un point singulier a l'origine - voir les procedures changehom,
% changevar, changefonc - ).
%
% Cette procedure ECRIT les solutions et RETOURNE une liste de terme
% general { lcoeff, {....,{ solution_generale },....}}. Le nombre
% d'elements de cette liste est lie au nombre de transformations
% demandees :
%   * lcoeff : liste des coefficients de l'equation differentielle
%   * solution_generale : solution ecrite sous la forme generale
begin
  scalar k,grille,repetition,lcoeff,param,n,ns,solutions,lsol ;
  integer j;
  if (repetition neq non ) and (repetition neq nonon ) then
    << write
          "   ATTENTION : chaque donnee doit etre suivie de ; ou de $" ;
       repetition:=nonon ;
    >> ;
  solutions:={};
  lsol:={} ;
  % lecture des donnees ;
  lcoeff:= lectabcoef();
  param:=second lcoeff;
  lcoeff:=first lcoeff;
  continue:=oui;
  write "transformation ? (oui;/non;)  ";
  ok:=xread t;
  while continue eq oui do
   <<
     if ok eq oui then <<lcoeff:=transformation(lcoeff,param);
                         param:=second lcoeff;
                         lcoeff:=first lcoeff;
                       >>;

     write "nombre de termes desires pour la solution ?" ;
     k:=xread t;
     if k neq 0 then
      <<
       grille:=1 ;
       if repetition neq non and lisp !*trdesir then
        << write " ";
          write "a chaque etape le polygone NRM sera visualise par la ",
                 "donnee des aretes modifiees , sous la forme :" ;
           write " " ;
           write
             "    ARETE No i : coordonnees de l'origine gauche, pente,",
                 " longueur " ;
        >> ;
       write " " ;
       on div ;

       on gcd ;
       solutions:=  delire(x,k,grille,lcoeff,param);
       ns:=length solutions;  n:=length lcoeff -1;
       if ns neq 0 then
         << write "LES ",ns," SOLUTIONS CALCULEES SONT LES SUIVANTES";
              j:=1;
              for each elt in solutions do
                     << write " " ; write " ==============" ;
                        write  "  SOLUTION No ",j ;
                        write " ==============" ;
                        sorsol(elt);
                        j:=j+1;
                     >> ;
         >>;
       off div ;
       if ns neq n then write n-ns," solutions n'ont pu etre calculees";
       repetition:=non ;
       lsol:= append(lsol,{{lcoeff,solutions}}) ;
       write "voulez-vous continuer ? ";
       write
         "'non;' : la liste des solutions calculees est affichee (sous";
       write " forme generalisee).";
       write "'non$' : cette liste n'est pas affichee.";
       continue:=xread t; ok:=oui;
     >>
    else
     continue:=non;
   >>;

  return lsol ;
end;

procedure solvalide(solutions,solk,k) ;
%==================================== ;
%
% Verification de la validite de la solution numero solk dans la liste
% solutions : {lcoeff,{....,{solution_generale},....}}.
% On reporte la solution dans l'equation : le resultat a en facteur un
% polynome en xt qui doit etre de degre > une valeur calculee en
% fonction de k, nombre de termes demandes dans le developpement
% asymptotique.  Ne peut etre utilisee si la solution numero solk est
% liee a une condition.
%
% ECRIT et RETOURNE l'evaluation de ce report.
begin
  scalar z,lcoeff,sol,essai,qx,gri,r,coeff1,d,zz;
  integer j;
  lcoeff:=first solutions;
  sol:=part(second solutions,solk);
  if length sol > 1
    then write("presence de solutions conditionnelles :",
               " cette procedure ne peut pas etre appelee.")
                    else
 << z:=first sol;
    essai:=first z; qx:=first essai;
                    essai:=rest essai;
                    gri:= first essai;
    sol:=second essai; r:=third essai;
    essai:=second z ;if length(essai)>0 then
    write "presence d'une condition : cette procedure ne peut pas etre
           appelee."
   else
   <<%calcul de la valuation theorique du polynome reste
              coeff1:=for each elt in lcoeff collect
                         sub(x=xt**(1/gri),elt);
              if qx neq 0 then <<d:=solvireg(coeff1,qx,xt);
              out dum;
              coeff1:=changefonc(coeff1,xt,!&phi,e**qx*!&phi);
              out t;>>;
              d:=altmin(coeff1,xt)-d;

      qx:=sub(xt=x**gri,qx);
      sol:=sub(lambd=r,sol);
      sol:=e**qx*x**(r*gri)*sub(xt=x**gri,sol);
      write "La solution numero ",solk," est ",sol;
      write "La partie reguliere du reste est de l'ordre de x**",
            gri*(k+1+d+r);
      z:=0;
      for each elt in lcoeff do
         << z:=z+elt*df(sol,x,j);j:=j+1;>>;
      zz:=e**(-qx)*x**(-r*gri)*z;
      zz:=sub(x=xt**(1/gri),zz);
      on rational;
 write "Si on reporte cette solution dans l'equation, le terme ",
       "significatif du reste"," est : ",
       e**qx*x**(r*gri)*sub(xt=x**gri,valterm(zz,xt));
      off rational;
      return z ;
    >> ;
  >>;
end;

procedure solvireg(lcoeff,q,x);
%=============================;
begin scalar f;
      integer j,n;
      depend !&y,x;
      depend !&phi,x;
      l:=lcoeff;
      while l neq {} do
         <<f:=f+(first l)*df(!&y,x,j);j:=j+1;l:=rest l>>;
      n:=length(lcoeff);
      let !&y=e**q*!&phi;
      for j:=1:n do f:=sub(df(!&phi,x,j)=zz**j,f);
      f:=sub(!&phi=1,f);
      clear !&y;
      nodepend !&y,x;
      nodepend !&phi,x;
      return deg(den(f),x);
end;

procedure altmin(lcoeff,x);
%=========================;
begin
integer j,min,d;
min:=deg(valterm(first lcoeff,x),x);
for each elt in rest lcoeff do <<
           j:=j+1;
           d:=deg(valterm(elt,x),x);
           if d-j<min then min:=d-j;>>;
return min;
end;

procedure valterm(poly,x);
%=========================;
%retourne le terme de plus bas degre de poly;
begin
scalar l,elt;
integer j;
l:=coeff(poly,x);
elt:=first l;
while elt=0 do <<j:=j+1;l:=rest l; elt:=first l;>>;
return elt*x**j;
end;

procedure standsol(solutions) ;
%============================== ;
%
% PERMET d'avoir l'expression simplifiee de chaque solution a partir de
% la liste des solutions {lcoeff,{....,{solution_generale},....}}, qui
% est retournee par DELIRE ou qui est un des elements de la liste
% retournee par DESIR.
%
% RETOURNE une liste de 3 elements : { lcoeff , solstand, solcond }
%     * lcoef = liste des coefficients de l'equation differentielle
%     * solstand = liste des solutions sous la forme standard
%     * solcond  = liste des solutions conditionnelles n'ayant pu etre
%                  mises sous la forme standard. Ces solutions restent
%                  sous la forme generales
%
% Cette procedure n'a pas de sens pour les solutions "conditionnelles".
% Pour celles-ci, il est indispensable de donner une valeur aux
% parametres, ce que l'on peut faire, soit en appelant la procedure
% SORPARAM, qui ecrit et retourne ces solutions dans la forme standard,
% soit en appelant la procedure SOLPARAM qui les retourne dans la forme
% generale.
begin
  scalar z,lcoeff,sol,solnew,solcond,essai,qx,gri,r;
  integer j;
  solnew:={};
  solcond:= {} ;
  lcoeff:=first solutions;
  for each elt in second solutions do
  if length elt > 1 then solcond:=append(solcond,{elt})
    else
     << z:=first elt;
        essai:=first z;
        qx:=first essai;
        essai:=rest essai;
        gri:= first essai;
        qx:=sub(xt=x**gri,qx);
        sol:=second essai; r:=third essai;
        essai:=second z ;
        if length(essai)>0 then solcond:=append(solcond,{elt})
         else
          << sol:=sub(lambd=r,sol);
             sol:=e**qx*x**(r*gri)*sub(xt=x**gri,sol);
             solnew:=append(solnew,{sol});
          >> ;
      >>;
return {lcoeff,solnew,solcond};
end;

procedure sorsol(sol);
%=====================
%
% ecriture, sous forme standard, de la solution sol donnee sous la forme
% generale, avec enumeration des differentes conditions (s'il y a lieu).
%
begin
  scalar essai,qx,gri,sol,r;
  nonnul:="  non nul";
  entnul:="  nul";
  nonent:="  non entier" ;
  entpos:= "  entier positif" ;
  entneg:= "  entier negatif" ;

  for each z in sol do
    << essai:=first z;
       qx:=first essai;
       essai:=rest essai;
       gri:= first essai;
       qx:=sub(xt=x**gri,qx);
       sol:=second essai;
       r:=third essai;
       essai:=second z ;
       if length(essai)>0 then
         <<if deg(num sol,lambd)=0 then
             << write e**qx*x**(r*gri)*sub(xt=x**gri,sol) ;
                write "Si : ";
    if lisp !*trdesir then
                if length essai =2 then write first essai, second essai
                      else
                        << write (first essai,second essai,third essai);
                           essai:=rest rest rest essai;
                           for each w in essai do
                           write ("                    +-",w);
                        >>
                else
                write first essai,second essai;
              >>;
           >>
         else
           << sol:=sub(lambd=r,sol);
              write e**qx*x**(r*gri)*sub(xt=x**gri,sol);
           >>;
   >>;
clear nonnul,entnul,nonent,entpos,entneg;
end;

procedure changehom(lcoeff,x,secmembre,id);
%========================================
%
% derivation d'une equation avec second membre.
%   * lcoeff : liste des coefficients de l'equation
%   * x : variable
%   * secmembre : second membre
%   * id : ordre de la derivation
%
% retourne la liste des coefficients de l'equation derivee
% permet de transforme une equation avec second membre polynomial en une
% equation homogene en derivant id fois, id = degre(secmembre) + 1.
%
begin scalar l,fct,cf,n;
      integer j;
      depend !&y,x;
      fct:=secmembre;
      l:=lcoeff;
      while l neq {} do
         <<fct:=fct+(first l)*df(!&y,x,j);j:=j+1;l:=rest l>>;
      fct:=df(fct,x,id);
      n:=length(lcoeff)+id;
      for j:=1:n do fct:=sub(df(!&y,x,j)=zz**j,fct);
      fct:=sub(!&y=1,fct);
      cf:=coeff(fct,zz);
      j:=0;
      for each elt in cf do <<write "a(",j,") = ", elt;j:=j+1;>>;
      nodepend !&y,x;
      return cf;
end;

procedure changevar(lcoeff,x,v,fct);
%=================================
%
% changement de variable dans l'equation homogene definie par la liste,
%    lcoeff, de ses coefficients :
%    l'ancienne variable x et la nouvelle variable v sont liees par la
%    relation x = fct(v)
%
% retourne la liste des coefficients en la variable v de la nouvelle
%          equation
% Exemples d'utilisation :
%   - translation permettant de ramener une singularite rationnelle a
%     l'origine
%   - x = 1/v ramene l'infini en 0.
%
begin scalar f,cf;
      integer j,n;
      depend !&y,x;
      l:=lcoeff;
      while l neq {} do
         <<f:=f+(first l)*df(!&y,x,j);j:=j+1;l:=rest l>>;
      n:=length(lcoeff);
      f:=change(!&y,x,v,fct,f,n);
      for j:=1:n do f:=sub(df(!&y,v,j)=zz**j,f);
      f:=sub(!&y=1,f);
      cf:=coeff(num(f),zz);
      j:=0;
      for each elt in cf do <<write "a(",j,") = ", elt;j:=j+1;>>;
      nodepend !&y,x;
      return cf;
      end;

procedure changefonc(lcoeff,x,q,fct);
%================================
%
% changement de fonction inconnue dans l'equation homogene definie par
% la liste lcoeff de ses coefficients :
%   * lcoeff : liste des coefficients de l'equation initiale
%   * x : variable
%   * q : nouvelle fonction inconnue
%   * fct : y etant la fonction inconnue y = fct(q)
%
% retourne la liste des coefficients de la nouvelle equation
%
% Exemple d'utilisation : permet de calculer, au voisinage d'une
% singularite irreguliere, l'equation reduite associee a l'une des
% pentes (polygone de Newton ayant une pente nulle de longueur non
% nulle).  Cette equation fournit de nombreux renseignements sur la
% serie divergente associee.
%
begin scalar f,cf;
      integer j,n;
      depend !&y,x;
      depend q,x;
      l:=lcoeff;
      while l neq {} do
         <<f:=f+(first l)*df(!&y,x,j);j:=j+1;l:=rest l>>;
      n:=length(lcoeff);
      let !&y=fct;
      for j:=1:n do f:=sub(df(q,x,j)=zz**j,f);
      f:=sub(q=1,f);
      cf:=coeff(num(f),zz); j:=1;
      for each elt in cf do <<write "a(",j,") = ", elt;j:=j+1;>>;
      clear !&y;
      nodepend !&y,x;
      nodepend q,x;
      return cf;
end;

procedure sorparam(solutions,param);
%==================================
%
% procedure interactive d'ecriture des solutions evaluees : la valeur
% des parametres est demandee.
%  * solutions :  {lcoeff,{....,{solution_generale},....}}
%  * param : liste des parametres;
%
% retourne la liste formee des 2 elements :
%    * liste des coefficients evalues de l'equation
%    * liste des solutions standards evaluees pour les valeurs des
%      parametres
%
begin
  scalar essai,sec,qx,gri,sol,sol1,r,solnew, coefnew, omega,omegac ;
  integer j,iparam;
  solnew:={};
  iparam:=length param;
  if iparam=0
    then rederr "La liste des parametres est vide : utiliser STANDSOL";
  array parm(iparam),parmval(iparam);
  j:=1;
  for each elt in param do
    << write "donner la valeur du parametre ", elt;
       parm(j):=elt;parmval(j):=xread t;j:=j+1;
    >>;
  j:=1;
  for each elt in second solutions do
    << sol:=0;for each z in elt do
         << essai:=first z;
            qx:=first essai;
            essai:=rest essai;
            gri:= first essai;
            qx:=sub(xt=x**gri,qx);
            sol1:=second essai;
            r:=third essai;
            essai:=second z ;
            if essai ={} then
            << sol:=e**qx*x**(r*gri)*sub(xt=x**gri,sol1);
                  for j:=1:iparam do sol:=sub(parm(j)=parmval(j),sol);
               >>
            else <<
            omega:=first essai;
            sec:= second essai ;
            for j:=1:iparam do omega:=sub(parm(j)=parmval(j),omega);
            omegac:=append(coeff(omega,i),{0});
            on rounded;
            if not numberp(first omegac) or not numberp(second omegac)
              then rederr list("Les valeurs donnees aux parametres ne",
      "permettent pas de choisir parmi les solutions conditionnelles.");
            off rounded;
          % il ne faut traiter qu'une seule fois  la solution
            if sec=nonnul then
              if omega neq 0 then
               << sol:=e**qx*x**(r*gri)*sub(xt=x**gri,sol1);
                  for j:=1:iparam do sol:=sub(parm(j)=parmval(j),sol);
               >>;
            if sec= entnul then
              if omega=0 then
               << sol:=e**qx*x**(r*gri)*sub(xt=x**gri,sol1);
                  for j:=1:iparam do sol:=sub(parm(j)=parmval(j),sol);
               >>;
            if sec=nonent then
              if not fixp(omega) then
               << sol:=e**qx*x**(r*gri)*sub(xt=x**gri,sol1);
                  for j:=1:iparam do sol:=sub(parm(j)=parmval(j),sol);
               >>;
            if sec=entpos then
              if fixp(omega) and (omega>0) then
                << sol:=e**qx*x**(r*gri)*sub(xt=x**gri,sol1);
                   for j:=1:iparam do sol:=sub(parm(j)=parmval(j),sol);
                >>;

            if sec=entneg then
              if fixp(omega) and (omega<0) then
                << sol:=e**qx*x**(r*gri)*sub(xt=x**gri,sol1);
                   for j:=1:iparam do sol:=sub(parm(j)=parmval(j),sol);
                >>;

            if deg(num sol,lambd) neq 0 then
              << sol:=sub(lambd=r,sol);
                 for j:=1:iparam do sol:=sub(parm(j)=parmval(j),sol);
              >>;
           >>;
         >>;
      write " " ; write " ==============" ;
      write  "  SOLUTION No ",j ;
      write " ==============" ;
      if sol neq 0 then
      <<write sol; solnew:=append(solnew,{sol})>>
      else write "solution non calculee";
      j:=j+1;
    >> ;
  coefnew:= for each elt in first solutions collect
              begin scalar cof;
                cof:=elt ;
                for j:=1:iparam do cof:=sub(parm(j)=parmval(j),cof);
                return cof
              end;
  clear parm,parmval;
  return { coefnew, solnew };
end;

procedure solparam(solutions,param,valparam);
%===========================================
%
% Cette procedure evalue, pour les valeurs des parametres donnees dans
% valparam les solutions generalisees et les retourne sous forme
% generalisee.
%
%  * solutions :  {lcoeff,{....,{solution_generale},....}}
%  * param : liste des parametres;
%  * valparam : liste des valeurs des parametres
%
% retourne la liste formee des 2 elements :
%    * liste des coefficients evalues de l'equation
%    * liste des solutions sous la forme generalisee evaluees pour les
%      valeurs des parametres
%
begin
  scalar essai,sec,qx,gri,sol,sol1,solg,r,solnew, coefnew,omega,omegac ;
  integer j,iparam;
  solnew:={};
  iparam:=length param;
if iparam=0
 then rederr "La liste des parametres est vide : utiliser STANDSOL";
  array parm(iparam),parmval(iparam);
  j:=1;
  for each elt in param do
    << parm(j):=elt ; j:=j+1 >>;
  j:=1;
  for each elt in valparam do
    << parmval(j):=elt ; j:=j+1 >>;
  for each elt in second solutions do
    << for each z in elt do
         << solg:=first z;
            essai:=second z ;
            if essai ={} then
            sol1:=solg
            else <<
            omega:=first essai;
            sec:= second essai ;
            for j:=1:iparam do omega:=sub(parm(j)=parmval(j),omega);
            omegac:=append(coeff(omega,i),{0});
            on rounded;
            if not numberp(first omegac) or not numberp(second omegac)
              then rederr list("Les valeurs donnees aux parametres",
   "ne permettent pas de choisir parmi les solutions conditionnelles.");
            off rounded;
          % il ne faut traiter qu'une seule fois  la solution
            sol1:={};
            if sec= nonnul then
              if omega neq 0 then
                sol1:= for each elem in solg collect
                         begin
                          sol:=elem ;
                          for j:=1:iparam do
                             sol:=sub(parm(j)=parmval(j),sol);
                          return sol
                         end ;
            if sec= entnul then
              if omega=0 then
                sol1:= for each elem in solg collect
                         begin
                          sol:=elem ;
                          for j:=1:iparam do
                             sol:=sub(parm(j)=parmval(j),sol);
                          return sol
                         end ;

            if sec=nonent then
              if not fixp(omega) then
                sol1:= for each elem in solg collect
                         begin
                          sol:=elem ;
                          for j:=1:iparam do
                             sol:=sub(parm(j)=parmval(j),sol);
                          return sol
                         end ;

            if sec=entpos then
              if fixp(omega) and (omega>0) then
                sol1:= for each elem in solg collect
                         begin
                          sol:=elem ;
                          for j:=1:iparam do
                             sol:=sub(parm(j)=parmval(j),sol);
                          return sol
                         end ;

            if sec=entneg then
              if fixp(omega) and (omega<0) then
                sol1:= for each elem in solg collect
                         begin
                          sol:=elem ;
                          for j:=1:iparam do
                             sol:=sub(parm(j)=parmval(j),sol);
                          return sol
                         end ;
            >>;
            if sol1 neq {} then
              << essai:=rest(rest(sol1)) ; r:=second essai;
                 if deg(num(sol:=first(essai)),lambd) neq 0 then
                   << sol:=sub(lambd=r,sol);
                      for j:=1:iparam do
                         sol:=sub(parm(j)=parmval(j),sol);
                   >>;
                 sol1:={first(sol1), second(sol1),sol,r};
                 solnew:=append(solnew,{{{sol1,{}}}});
              >> ;
         >>;
    >> ;
  coefnew:= for each elt in first solutions collect
              begin scalar cof;
                cof:=elt ;
                for j:=1:iparam do cof:=sub(parm(j)=parmval(j),cof);
                return cof
              end;
  clear parm,parmval;
  return { coefnew, solnew };
end;

procedure lectabcoef( ) ;
%---------------------- ;
% Lecture des coefficients de l'equation (dans l'ordre croissant des
% derivations).
% lecture de n    : ordre de l'equation.
% lecture des parametres (s'il apparait une variable differente de x
% dans les coefficients).
% les coefficients sont ranges dans la liste lcoeff (le tableau tabcoef
% est utilise temporairement).
% Retourne la liste { lcoeff , param } formee de la liste des
% coefficients et de la liste des parametres (qui peut etre vide).
%
begin
  scalar n, ok,iparam,lcoeff,param ;

  write " " ;
  write "                     *****  INTRODUCTION DES DONNEES  ***** ";
  write " " ;
  write "  L' equation est  de la forme";
  write "      a(0)(x)d^0 + a(1)(x)d^1 + .... + a(n)(x)d^n = 0 " ;
  write " ordre de l'equation ? " ;
  n:=xread t ;
  array tabcoef(n);
  write "  Donner les coefficients   a(j)(x), j = 0..n" ;
  for j:=0:n do tabcoef(j):=xread t;
  for j:=0:n do write "a(",j,") = ",tabcoef(j);
  write "  " ;
  write "correction ? ( oui; / non; )   " ;
  ok:=xread t;
  while ok eq oui do
    <<       write "valeur de j :" ; j:=xread t;
       write "expression du coefficient :";tabcoef(j):=xread t;
       write "correction ?";ok:=xread t;
    >> ;

lcoeff:={tabcoef(n)};
for j:=n-1 step -1 until 0 do lcoeff:=tabcoef(j).lcoeff;
if testparam(lcoeff,x) then
<<write "nombre de parametres ?  ";
  iparam:=xread t;
  if iparam neq 0 then
      <<param:={};
        if iparam=1 then write "donner ce parametre :"
                    else write "donner ces parametres :";
        for i:=1:iparam do param:=xread t . param;
      >>;
>> else param:={};
clear tabcoef ;
return {lcoeff,param};
end;


%                   ***********************************
%                   *                                 *
%                   *       UTILISATION STANDARD      *
%                   *                                 *
%                   ***********************************
%



procedure delire(x,k,grille,lcoeff,param) ;
%=========================================;
%
% cette procedure calcule les solutions formelles d'une equation
% differentielle lineaire homogene, a coefficients polynomiaux sur Q et
% d'ordre quelconque, au voisinage de l'origine, point singulier
% regulier ou irregulier ou point regulier. En fait, elle initialise
% l'appel de la procedure NEWTON qui est une procedure recursive
% (algorithme de NEWTON-RAMIS-MALGRANGE)
%
%  x      : variable
%  k      : nombre de termes desires dans le developpement asymptotique
%  grille : les coefficients de l'operateur differentiel sont des
%           polynomes en x**grille (en general grille=1)
%  lcoeff : liste des coefficients de l'operateur differentiel (par
%           ordre croissant)
%  param  : liste des parametres
%
% RETOURNE la liste des solutions "generales".
%             -----
%
begin
  integer prof,ordremax,ns ;
  scalar n,l;
  n:=length lcoeff -1;
  array der(n),!&solution(n),!&aa(n) ;
  array gri(20),lu(20),qx(20),equ(20),cl(20,n),clu(20,n) ;
  array nbarete(20),xpoly(20,n),ypoly(20,n),ppoly(20,n),lpoly(20,n) ;
  array xsq(n+1),ysq(n+1),rxm(n+1) ;
  array ru(20,n) ,multi(20,n) ,nbracine(20) ;
  array rac(10),ordremult(10);
  array condprof(20),solparm(n); % liste des conditions dans Newton
  array solequ(n);
  on gcd ;

  % initialisation du tableau cl ;
  l:=lcoeff;
  for i:=0:n do
     << cl(0,i):= first l; l:=rest l;>>;

  % initialisation du tableau des parametres ;
    iparam:=length param;
    array parm(iparam);
    parm(0):=iparam;
    for i:=1:iparam do parm(i):=part(param,i);

  % initialisation de la grille : les coef de L sont des polynomes
  % en x**gri(0) ;
   gri(0):=grille ;

  % substitution de d/dx par ( d/dx - (&lamb*!&u)/x**(&lamb+1) ) ;
  der(0):=!&ff(x) ;
  for ik:=1:n do
    der(ik):=df(der(ik-1),x)-((!&lamb*!&u)/x**(!&lamb+1))*der(ik-1) ;

  % initialisation de l'exponentielle ;
  qx(0):=0 ;

  % l'appel initial de l'algorithme NEWTON se fait avec l'operateur
  % complet l'ordre maximum (ordremax) pour lequel on calcule le
  % polygone NRM est n;
  ordremax:=n ;

  % initialisation de prof :  prof indique le nombre d'appels recursifs
  % de l'algorithme NEWTON ;
  prof:=1 ;

  condprof(0):={};
  % appel de l'algorithme NEWTON ;
  ns:=newton(prof,ordremax,n,x,k,0) ;
  l:=for i:=1:ns collect solequ(i);
  clear der,!&solution,!&aa,gri,lu,qx,equ,cl,clu,nbarete,xpoly,ypoly,
        ppoly,lpoly,xsq,ysq,rxm,tj,ru,multi,nbracine,parm ;
  clear rac,ordremult;
  clear condprof,solparm,solequ;

  return l ;
end;

procedure testparam(l,x);
%-----------------------;
% l : liste des coefficients;
% retourne t si presence de parametres (variable differente de x);
%          nil sinon;
begin
  scalar b,l1,l2;
  b:=nil; l1:=l;
  while b=nil and l1 neq{} do << l2:=coeffp({first l1},{x});
                                 for each elt in l2 do
                                   <<if not numberp elt then b:=true;>>;
                                 l1:=rest l1;>>;
  return b;
end;

procedure coeffp(poly,var);
%-------------------------;
% poly : liste des polynomes
% var : liste des variables
% retourne la liste des coefficients
begin
  scalar l,l1 ;
  if var={} then return poly;
  l:={};
  for each elt in poly do <<l1:=coeff(elt,first var);
                            for each el1 in l1 do if el1 neq 0 then
                                      l:=append(l,{el1})
                          >>;
  return coeffp(l,rest var);
end;




procedure transformation(lcoeff,param);
%-------------------------------------;
% Entree : liste des coefficients de l'equation
%          liste des parametres
% Sortie : liste des coefficients de l'equation transformee
begin
      scalar f,id,fct,fct1,coeff1,lsor;
      ok:=oui;coeff1:=lcoeff;
      while ok eq oui do <<write "derivation : 1; ";
                           write "changement de variable : 2; ";
                           write "changement de fonction inconnue : 3;";
                           write "substitution : 4;";
      ichoix:=xread t;

      if ichoix=1 then
       << write "donner le second membre : ";
          f:=xread t;
          write "donner le nombre de derivations : ";
          id:=xread t;
          coeff1:=changehom(coeff1,x,f,id) ;
          lsor:={coeff1,param}
       >>;

      if ichoix=2 then
       << write "valeur de x en fonction de la nouvelle variable v ? ";
          fct:=xread t;
          coeff1:=changevar(coeff1,x,v,fct);
          coeff1:=for each elt in coeff1 collect(sub(v=x,elt));
          lsor:={coeff1,param}
       >>;

      if ichoix=3 then
       << write
         "valeur de y en fonction de la nouvelle fonction inconnue q ?";
          fct:=xread t; coeff1:=changefonc(coeff1,x,q,fct);
          lsor:={coeff1,param}
       >>;

      if ichoix=4 then
       << write "donner la regle de substitution , ";
          write "le premier membre de l'{galit{ ,puis le second : ";
          fct:=xread t;
          fct1:=xread t;
          lsor:=subsfonc(coeff1,param,fct,fct1);
          coeff1:=first lsor;
       >>;

      write "transformation ? (oui;/non;)  ";
      ok:=xread t;   >>;
      return lsor;
end;

procedure subsfonc(lcoeff,param,fct,fct1);
%----------------------------------------;
% Effectue la substitution de fct par fct1
begin
 scalar lsor,lsor1;integer j;
 lsor:= for each elt in lcoeff collect sub(fct=fct1,elt);
 for each elt in lsor do <<j:=j+1;write"a(",j,") = ",elt>>;
 lsor1:= for each elt in param do if fct neq elt then collect elt;
 if lsor1=0 then <<
 write "nouvelle liste de parametres : ",{};
 return {lsor,{}};>>
            else <<
 write "nouvelle liste de parametres : ",lsor1;
 return {lsor,lsor1};>>;
end;

procedure change(y,x,v,fct,exp,n);
%---------------------------------
% exp est une expression dependant de x, de y(x), et de ses derivees
% d'ordre inferieur ou egal a n.
% change retourne la meme expression apres avoir fait le changement de
% variable x=fct(v).
begin
  scalar !&exp;
  !&hp(xt):=1/df(sub(v=xt,fct),xt);
  !&exp:=exp;
  for i:=n step -1 until 0 do !&exp:=sub(df(y,x,i)=!&d(xt,i),!&exp);
  !&exp:=sub(x=fct,!&exp);
  depend y,v;
  for i:=n step -1 until 0 do
     !&exp:=sub(df(!&fg(xt),xt,i)=df(y,v,i),!&exp);
  return sub(xt=v,!&exp);
end;


%                   +++++++++++++++++++++++++++++++++++++++++
%                   +                                       +
%                   +         ALGORITHME DE NEWTON          +
%                   +                                       +
%                   +++++++++++++++++++++++++++++++++++++++++
%;



operator !&ff,!&hp,!&fg ;
procedure !&d(xt,n);
begin
if n=0 then return !&fg(xt)
else if fixp n and (n>0) then return !&hp(xt)*df(!&d(xt,n-1),xt) ;
end;


procedure newton(prof,ordremax,n,x,k,ns) ;
%======================================= ;

% algorithme de NEWTON-RAMIS-MALGRANGE.
% Cette procedure, recursive, est appelee par la procedure DELIRE.
%
% Elle NE PEUT PAS ETRE APPELEE SEULE car un certain nombre de tableaux
% doivent etre declares et initialises.
%
%  prof   : niveau de recursivite
%  ordremax : ordre de l'operateur differentiel traite par cet appel
%  x      : variable de l'equation differentielle
%  n      : ordre de l'operateur differentiel initial
%  k      : nombre de terme du developpement asymptotique des solutions
%  ns     : nombre de solutions deja calculees lors de l'appel
%
% cette procedure retourne le nombre de solutions calculees ;
begin
  integer nba, nadep, nbsol, q ;
  scalar nbs,condit,sol,substitution ;

  nbs:=ns ;

  % construction du polygone N-R-M de l'operateur defini par
  % cl(prof-1,i) avec i=0..ordremax ;
  nba:=polygoneNRM(prof,ordremax,x) ;

  % dessin ;
  if lisp !*trdesir then for j:=1:nba do
  write xpoly(prof,j),"  ",ypoly(prof,j),"  ",ppoly(prof,j),"  ",
        lpoly(prof,j) ;

  % si la premiere arete a une pente nulle, on va calculer par FROBENIUS
  % lpoly(prof,1) solutions en utilisant cl(prof-1,i) ,i=0..n et
  % qx(prof-1) . ;
  % nadep = numero de la premiere arete a traiter de pente non nulle ;
  nadep:=1 ;

  % si la 1ere pente est nulle : appel de frobenius et calcul des
  % solutions;
  if num(ppoly(prof,1)) = 0 then
      << nbsol := lpoly(prof,1) ;
         nouveauxaj(prof,n,x) ;
         condl:=condprof(prof);
         nbsol:=frobenius (n,xt,k) ;
         if nbsol neq 0 then
            for i:=1:nbsol do
         << solequ(nbs+i):={};
            for each el in solparm(i) do
           << if length(el) > 1 then condit:=second el else condit:={};
              sol:=first el;
         sol:=append({sub(x=xt**(1/gri(prof-1)),qx(prof-1)),
                        gri(prof-1)},sol);
              solequ(nbs+i):=append (solequ(nbs+i),{{sol,condit}});
             >> ;
          >> ;
         nbs:=nbs+nbsol ;
         nadep:=2 ;
         clear !&f,!&degrec ;
      >> ;

  % iteration sur le nombre d'aretes ;
  for na:=nadep:nbarete(prof) do
        nbs:=newtonarete(prof,na,n,x,k,nbs);
           % iteration sur les aretes ;

  return nbs ;
end ;

procedure newtonarete(prof,na,n,x,k,nbs);
%---------------------------------------;
begin  scalar q,ordremax;
         q:=den(ppoly(prof,na)) ;
         if lisp !*trdesir then
         write "        ",xpoly(prof,na),"  ",ypoly(prof,na),"  ",
                    ppoly(prof,na),"  ",lpoly(prof,na) ;

         % calcul de la grille ;
         if lpoly(prof,na)=1
             then gri(prof):=gri(prof-1)
             else gri(prof):=gcd(q,1/gri(prof-1))*gri(prof-1)/q;

         % substitution dans l'operateur defini par cl(prof-1,i),i=0..n;
         lu(prof):= sub(!&lamb=ppoly(prof,na),cl(prof-1,0)*der(0)) ;
         for ik:=1:n do
            lu(prof):=lu(prof)+sub(!&lamb=ppoly(prof,na),
                                   cl(prof-1,ik)*der(ik));

         % decomposition de l'operateur lu ;
         % selon les coefficients clu(prof,i) des derivees , i=0..n ;
         % calcul de l'equation caracteristique ,equ(prof) :
         % coefficient du terme constant de clu(prof,0) ;
         decomplu(prof,n,x,na) ;

         % calcul des racines de equ(prof) ;
         racinesequ(prof,na) ;

         % iteration sur les racines de l'equation caracteristique  ;
         for nk:=1:nbracine(prof) do
           << % completer l'exponentielle  ;
              qx(prof):=qx(prof-1)+ru(prof,nk)/x**ppoly(prof,na)  ;

              % definition du nouvel operateur ;
              for ik:=0:n do cl(prof,ik):=sub(!&u=ru(prof,nk),
                                                         clu(prof,ik));
              % definition de l'ordre jusqu'auquel on calcule le nouveau
              % polygone-nrm : ordremax  ;
              ordremax:=multi(prof,nk)  ;

              if prof <20 then nbs:=newton(prof+1,ordremax,n,x,k,nbs)
                          else write "la profondeur 20 est atteinte :",
                              " le calcul est arrete pour cette racine";
           >> ; % fin de l'iteration sur les racines  ;
return nbs;
end;

procedure squelette (prof,ordremax,x) ;
%------------------------------------ ;
% definition du squelette du polygone de NEWTON-R-M defini par
% cl(prof-1,i), avec i=0..ordremax ;
% retourne le nombre de minima ;
begin
  scalar t00,tq,yi,cc ;
  integer ik,nk,nbelsq,degden,degre, rxi ;

   condprof(prof):=condprof(prof-1);

 % base du squelette ;
 % abscisse , numerotee de 1 a nbelsq ;
    t00:=0 ;
    for ik:=0 : ordremax do
       if cl(prof-1,ik)neq 0 then << nk:=nk+1 ; xsq(nk):=ik >> ;
    nbelsq:=nk ;

 % ordonnee ;
    for nk:=1:nbelsq do
       <<tq:=sub(x=!&t**(1/gri(prof-1)),cl(prof-1,xsq(nk))) ;
         degden:=deg(den(tq),!&t) ;
         cc:=coeff(num(tq),!&t) ;
         ik:=0 ;
         while (first cc =0) do << ik:=ik+1 ; cc:= rest cc >>;
         ysq(nk):=(ik-degden)*gri(prof-1)-xsq(nk) ;
         trav1(nk):=first cc;
       >> ;

 % minima successifs ;
 % le tableau rxm contiendra le rang de l'abscisse des minima successifs
 % du squelette ;
 % de 1 au nombre de minima ;
    rxm(0):=0 ;
    ik:=0 ;
    while rxm(ik)< nbelsq do
       <<rxi:=rxm(ik)+1 ;
         yi:=ysq(rxi) ;
         for j:=rxi+1 : nbelsq do
            if num(ysq(j)-yi) <= 0 then << yi:=ysq(j) ; rxi:=j >> ;
         ik:=ik+1 ;
         rxm(ik):=rxi ;
       >> ;
    return ik ;
end ;

procedure polygoneNRM(prof,ordremax,x) ;
%------------------------------------- ;
% construction du polygone N-R-M de l'operateur defini par cl(prof-1,i),
% avec i=0..ordremax ;
%
% les aretes seront numerotees de 1 a nbarete(prof)  ;
% i=nombre d'aretes deja construites ;
% l'arete i est definie par :
%      xpoly(prof,i)  abscisse du sommet gauche
%      ypoly(prof,i)  ordonnee du sommet gauche
%      ppoly(prof,i)  pente de l'arete
%      lpoly(prof,i) "longueur" de l'arete : abscisse du sommet droite -
%                                            abscisse du sommet gauche;
% retourne le nombre d'aretes ;
begin
  scalar ydep,yfinal,pente ;
  integer ik,imin,jmin,nbmin,rxmin,long,xfinal,xdep,deg1,rxi ;
  array trav1(20);

  nbmin:=squelette(prof,ordremax,x) ;
  ik:=0 ;
  xfinal:=xsq(rxm(1)) ;
  yfinal:=ysq(rxm(1)) ;
  xpoly(prof,1):=0 ;
  ypoly(prof,1):=yfinal ;
  ppoly(prof,1):=0 ;

         rxi:=rxm(1);
         for i:=1:parm(0) do
         deg1:=deg1+deg(trav1(rxi),parm(i));
         if deg1 neq 0 then
             << if lisp !*trdesir
                  then write "Si : ",trav1(rxi)," non nul";
         condprof(prof):=append(condprof(prof),
         { trav1(rxi),nonnul }); >>;

  if xfinal neq 0 then << ik:=1 ; lpoly(prof,1):=xfinal >> ;
  jmin:=1 ;
  while xfinal <ordremax do
     <<ik:=ik+1 ;

       % initialisation de l'arete ik ;
       xpoly(prof,ik):=xfinal ; xdep:=xfinal ;
       ypoly(prof,ik):=yfinal ; ydep:=yfinal ;
       imin:=jmin+1 ;
       jmin:=imin ;
       xfinal:=xsq(rxm(imin)) ;
       yfinal:=ysq(rxm(imin)) ;
       lpoly(prof,ik):=xfinal-xdep ;
       ppoly(prof,ik):=(yfinal-ydep)/lpoly(prof,ik) ;

       % recherche du point final de l'arete ik ;
       while imin < nbmin do
          <<imin:=imin+1 ;
            rxmin:=rxm(imin) ;
            long:=xsq(rxmin)-xdep ;
            pente:=(ysq(rxmin)-ydep)/long ;
            if num(pente-ppoly(prof,ik)) <= 0 then
              <<lpoly(prof,ik):=long ;
                ppoly(prof,ik):=pente ;
                xfinal:=xsq(rxmin);
                yfinal:=ysq(rxmin) ;
                jmin:=imin ;
              >> ;
          >> ;

         for ii:=1:parm(0) do
         deg1:=deg1+deg(trav1(rxi),parm(ii));
         if deg1 neq 0 then
             << if lisp !*trdesir
                  then write "Si : ",trav1(rxi)," non nul";
         condprof(prof):=append(condprof(prof),
         { trav1(rxi), nonnul }); >>;

     >> ;
  nbarete(prof):=ik ;
clear trav1;
  return ik ;
end ;

procedure nouveauxaj(prof,n,x) ;
%------------------------------ ;
% construction des coefficients !&aa(j) de l'operateur envoye a
% FROBENIUS.
begin
  scalar gr,t00,coeffs ;
  for i:=0:n do !&aa(i):=cl(prof-1,i) ;
  gr:=1/gri(prof-1);

  % changement de x en xt**gr ;
    % calcul des derivees en xt ;
      !&hp(xt):=1/df(xt**gr,xt);

    % calcul de l'operateur ;
      t00:=num( for j:=0:n sum sub(x=xt**gr,!&aa(j))*!&d(xt,j)) ;

    % calcul des nouveaux !&aa(j) ;
      for j:=0:n do
       <<coeffs:= if j=0 then coeff(t00,!&fg(xt))
                        else if j=1 then coeff(t00,df(!&fg(xt),xt))
                                 else coeff(t00,df(!&fg(xt),xt,j));
          if length coeffs=1 then !&aa(j):=0
                             else !&aa(j):=second coeffs;
          t00:=first coeffs
       >> ;
end ;

procedure decomplu(prof,n,x,na) ;
%------------------------------- ;
% decomposition de l'operateur lu ;
% selon les coefficients clu(prof,i) des derivees , i=0..n ;
% calcul de l'equation caracteristique ,equ(prof) : coefficient du terme
% constant de clu(prof,0) ;
begin
  scalar gr,t00,tq,tj1,tj1c,coeffs ;
  gr:=1/gri(prof) ;
  t00:=num(lu(prof)) ; tq:=den(lu(prof)) ;
  for j:=0:n  do
    << coeffs:= if j=0 then coeff(t00,!&ff(x))
                      else if j=1 then coeff(t00,df(!&ff(x),x))
                                  else coeff(t00,df(!&ff(x),x,j)) ;
       if length coeffs=1 then << clu(prof,j):=0 ; t00:=first coeffs >>
                  else << tj1:=sub(x=!&t**gr,second coeffs) ;
                          tj1c:=coeff(tj1,!&t) ;
                          while first tj1c =0 do tj1c:= rest tj1c;
                          t00:=first coeffs ;
                          if j=0 then <<clu(prof,j):=second coeffs/tq ;
                                        equ(prof):=num(first tj1c)/
                                       !&u**(deg(num(first tj1c),!&u)
                                               -lpoly(prof,na))
                                      >>
                                 else clu(prof,j):=second coeffs/tq ;
                       >> ;
   >> ;
end ;

procedure racinesequ(prof,na) ;
%----------------------------- ;
% calcul des racines de equ(prof) ;
begin
  scalar nrac ;
  integer nk,q1,gq,g1,dequ ;
  dequ:=deg(equ(prof),!&u) ;
  g1:=den(gri(prof-1)) ;q1:=den(ppoly(prof,na)) ;
  gq:=gcd(g1,q1) ;
  while gq > 1 do << g1:=g1/gq ;q1:=q1/gq ;
                     gq:=gcd(g1,q1) >> ;
  let !&u**q1=!&t ;
  nrac:=racine (equ(prof),!&t) ;
  for ik:=1:nrac do
    for j:=1:q1 do
      << multi(prof,(ik-1)*q1+j):=ordremult(ik) ;
         ru(prof,(ik-1)*q1+j):=rac(ik)**(1/q1)*e**(2*(j-1)*i*pi/q1);
         nk:=nk+ordremult(ik) ;
      >> ;
  nbracine(prof):= nrac*q1 ;
  clear !&u**q1 ;
  if (dequ-nk) neq 0 then
             write "IL Y A ",ik," SOLUTIONS RELATIVES A L'ARETE "
             ,na," QUI NE PEUVENT PAS ETRE ATTEINTES : ",
             "equation a resoudre de degre >=3 " ;
end ;


%                   +++++++++++++++++++++++++++++++++++++++++
%                   +                                       +
%                   +       ALGORITHME DE FROBENIUS         +
%                   +                                       +
%                   +++++++++++++++++++++++++++++++++++++++++
%;



operator !&g ;
% definition de  !&w ;
% ------------------ ;
procedure !&w(ii,x,lambd,k);
if fixp k then for j:=0:k sum (df(!&g(j),lambd,ii)*x**j);



procedure frobenius ( n,x,k ) ;
%============================ ;

% Soit l'operateur differentielle :  l  d'ordre : n
%
%    l(y)=a(n)*y(n)+a(n-1)*y(n-1)+.....a(0)*y(0)
%        avec les  a(i) = series d'ordre m en x
%
% On recherche une solution au voisinage d'un point singulier regulier
% de l'equation differentielle l(y)=0 sous la forme :
%      y = x**lambda*(g(0)+g(1)*x+.....g(k)*x**k)
% on va determiner:
%        - l'equation indicielle
%        - les equations lineaires recurentes qui permettent de trouver
%          les g(i) par identification des coefficients de x dans
%          l'equation differentielle l(y)=0 ;
%
% Elle NE PEUT PAS ETRE APPELEE SEULE car un certain nombre de tableaux
% doivent etre declares et initialises.
%
%  n      : ordre de l'operateur
%  x      : variable
%  k      : nombre de termes du developpement asymptotique
%
% Cette procedure retourne le nombre de solutions calculees.
begin
  integer nb,nbrac,nbsolution ;
  scalar ss,sy, essai;
  equaind(n,x,k);   % calcul de f(0) : equation indicielle;
  if lisp !*trdesir then write "f(0) = ",!&f(0) ;
  nb:=racine (!&f(0),lambd);               % calcul des racines de f(0);

  % verification sur le calcul des racines;
  if nb=0 then
    <<
      write "le calcul des racines est impossible dans ce cas.  ",
                    "Utilisez la version ALGEBRIQUE. ";
      nbsolution:=0; %cette valeur sert de test dans DELIRE;
      return nbsolution ;
    >> ;

%etude en fonction du nombre de racines et de leur classification;
  nbrac:=for i:=1:nb sum ordremult(i);

%  CLASSEMENT des RACINES de l'EQUATION INDICIELLE
%  cas particulier:
%  ----------------   1ou 2 racines ;
if nbrac=1 then
<<
  %cas d'une racine simple;
  nbsolution:=1;
  frobeniussimple(x,k,rac(1),1);
  solparm(1):={{{!&solution(1),rac(1)},condl} };
>>;

if nbrac=2 then <<
if ordremult(1)=2 then rac(2):=rac(1);
omega:=rac(1)-rac(2);
if fixp(omega) then
          << nbsolution:=2;
             if rac(2) > rac(1) then << ss:=rac(1); rac(1):=rac(2) ;
                                        rac(2):=ss ;
                                     >> ;
             frobeniusgeneral(x,k,nbsolution);
     for i:=1:nbsolution do
        solparm(i):={{{!&solution(i),rac(i)},condl}};
          >>
     else
        if parm(0)=0 then
         << nbsolution:=2;
            frobeniussimple(x,k,rac(1),1);
            %pour la 2ieme solution les G(I) sont deja calcules;
            !&solution(2):=
                     (for i:=0:k sum(sub(lambd=rac(2),!&g(i))*x**i));
    for i:=1:nbsolution do solparm(i):={{{!&solution(i),rac(i)},condl}};
         >>
         else
       <<
%cas omega non_entier
            nbsolution:=2;
            frobeniussimple(x,k,rac(1),1);
     essai:= for i:=1:k join if !&g(i)=0 then { i } else { } ;
     if length(essai) > 0 then essai:= ", sauf :" . essai;
            essai:=append({ omega, nonent }, essai);
            essai:=append(condl,essai);
            !&solution(2):=
                    (for i:=0:k sum(sub(lambd=rac(2),!&g(i))*x**i));
    for i:=1:nbsolution do solparm(i):={{{!&solution(i),rac(i)},essai}};
%cas omega >0
       for i:=0:k do clear !&g(i);
            nbsolution:=2;
%           for i:=1:nbsolution do solparm(i):={};
            frobeniusgeneral(x,k,nbsolution);
            essai:=append(condl,{ omega, entpos});
            for i:=1:nbsolution do
      solparm(i):=append(solparm(i),{{{!&solution(i),rac(i)},essai}});
%cas omega <0
       for i:=0:k do clear !&g(i);
            nbsolution:=2; ss:=rac(1);rac(1):=rac(2);rac(2):=ss;
            frobeniusgeneral(x,k,nbsolution);
            essai:=append(condl,{ omega, entneg});
            for i:=1:nbsolution do
      solparm(i):=append(solparm(i),{{{!&solution(i),rac(i)},essai}});
%cas omega =0
       for i:=0:k do clear !&g(i);
            nbsolution:=2; rac(2):=rac(1);
            frobeniusgeneral(x,k,nbsolution);
            essai:=append(condl,{ omega, entnul});
            for i:=1:nbsolution do
      solparm(i):=append(solparm(i),{{{!&solution(i),rac(i)},essai}});
         >>
   >>;

if nbrac=3 then
   << classement3r(x,k) ;
      nbsolution:=3;
   >>;
% nettoyage des variables ;
if nbrac>3
  then write "ce cas n'est pas traite. Utilisez la version ALGEBRIQUE"
  else for i:=0:k do clear !&g(i);
%fin cas ou il existe 1 ou plusieurs racines;
return nbsolution;
end  ;

procedure classement3r(x,k) ;
%-------------------------- ;
% calcul des solutions lorsque l'equation indicielle a 3 racines ;
% cette procedure est appelee par FROBENIUS ;
begin
  scalar ss,sy,nbsolution ;
  if ordremult(1)=3 then
              <<
                % cas des racines triples;
                rac(2):=rac(3):=rac(1)
              >>;
   if (ordremult(1)=1) and (ordremult(2)=2)
     then << ss:=rac(1); sy:=ordremult(1);
             rac(1):=rac(2); ordremult(1):=ordremult(2);
             rac(3):=ss; ordremult(3):=sy;
          >>
     else
       if ordremult(1)=2 then
          <<
             %decalage de l'indice 2 puis de 1 ;
             rac(3):=rac(2); ordremult(3):=ordremult(2);
             rac(2):=rac(1); ordremult(2):=ordremult(1);
          >>;

  %classement des racines ;
  if ordremult(1)=3 then
    <<
      nbsolution:=3;
      frobeniusgeneral(x,k,nbsolution)
    >>
  else
    <<  % analyse des autres cas;
        %ordremult(1)=1;
    if fixp(rac(1)-rac(2)) and fixp(rac(2)-rac(3)) then
      << %ordonner les racines;
         if rac(1)<rac(3) then << ss:=rac(1) ;
                                  rac(1):=rac(3); rac(3):=ss ;
                               >> ;
         nbsolution:=3;
         frobeniusgeneral(x,k,nbsolution);
      >>;
    if rac(1)=rac(2) and not fixp(rac(2)-rac(3)) then
      <<
        nbsolution:=2;
        frobeniusgeneral(x,k,nbsolution);
        for i:=0:k do clear !&g(i);
        nbsolution:=3;
        frobeniussimple(x,k,rac(3),3);
      >>;
    if not fixp(rac(1)-rac(2)) and fixp(rac(2)-rac(3)) then
        <<
          frobeniussimple(x,k,rac(1),3);
          % arranger les racines avant l'appel;
          rac(1):=rac(2); rac(2):=rac(3);
          nbsolution:=2;
          for i:=0:k do clear !&g(i);
          frobeniusgeneral(x,k,nbsolution);
          nbsolution:=3;
        >>;
        %cas des racines toutes distinctes n'est pas traite;
    if not fixp(rac(1)-rac(2)) and not fixp(rac(2)-rac(3)) then
           %ajout 5-5-88
           if fixp(rac(1)-rac(3)) then
        <<
          frobeniussimple(x,k,rac(2),3);
          % arranger les racines avant l'appel;
          rac(2):=rac(3);
          nbsolution:=2;
          for i:=0:k do clear !&g(i);
          frobeniusgeneral(x,k,nbsolution);
          nbsolution:=3;
        >>
           else
        << nbsolution:=3;
           frobeniussimple(x,k,rac(1),1);
           %pour la 2ieme solution les G(I) sont deja calcules;
           !&solution(2):=
                  (for i:=0:k sum(sub(lambd=rac(2),!&g(i))*x**i));
           !&solution(3):=
                  (for i:=0:k sum(sub(lambd=rac(3),!&g(i))*x**i));
        >>;
         %fin ajout;
%       write "ce cas n'est pas traite. Utilisez la version ALGEBRIQUE";
  >>;
        for i:=1:nbsolution do
           solparm(i):={{{!&solution(i),rac(i)},condl}};
end;


procedure equaind (n,x,k) ;
%-------------------------- ;
% calcul de l'equation indicielle ;
% cette procedure declare un tableau f et le remplit.
% f(0) est l'equation indicielle ;

%  n      : ordre de l'operateur
%  x      : variable
%  k      : nombre de termes demandes pour la solution ;
begin
  scalar l,denoml,ff ;
  integer m,di,minai,lff ;
  % Recherche de M=degre maximum des A(i);
  m:=deg(!&aa(0),x);
  for i:=1:n do if deg(!&aa(i),x)>m then m:=deg(!&aa(i),x);

  array !&y(n),degrai(n),!&f(k+m+n+1);

  % forme generale de la solution;
  !&y(0):=x**lambd*(for i:=0:k sum !&g(i)*x**i);

  % determination des derivees successives de !&y;
  for ii:=1:n do
  !&y(ii):=df(!&y(ii-1),x);

  % substitution des derivees dans l;
  l:=!&aa(0)*!&y(0)$
  for ii:=1:n do l:=l+!&aa(ii)*!&y(ii)$
  if den(l) neq 1 then << denoml:=den(l);
                          l:=num(l);
                       >>
                  else denoml:=1;
  for ii:=0:n do
    << if denoml neq 1 then !&aa(ii):=!&aa(ii)*denoml;
       degrai(ii):= if den(!&aa(ii)) eq 1 or fixp den(!&aa(ii))
                              then length coeff(!&aa(ii),x) -1
    >>;

  % recherche du minimum entre degree(!&aa(i)) et  i  ;
  minai:=0$
  maxai:=0$

  for ii:=0:n do
    << di:=degrai(ii)-ii;
       if (di<0) and (di<minai) then minai:=di;
       if (di>maxai) then maxai:=di;
    >>;

  % on divise  l  par x**(lambd+minai);
  l:=l/x**(lambd+minai)$
  maxai:=maxai-minai;

  % calcul des differentes valeurs de : !&f(i);
  ff:=coeff(l,x)$

  % verification si l n'est pas divisible par : x**i;
  while first ff = 0 do ff:= rest ff;
  lff:=length ff -1;
  for i:=0:lff do
    !&f(i):=part(ff,i+1);
  !&degrec:=maxai;

  !&f(0):=!&f(0)/!&g(0);
  clear !&y,degrai ;
end  ;

procedure frobeniussimple (x,k,rac,nbsol) ;
%---------------------------------------- ;
%   Cette procedure est particuliere a la recherche des
%  solutions formelles d'une equation differentielle dont les solution
%  sont simples , c.a.d. ne comportant pas de log

%  x      : variable de l'equation traitee ;
%  k      : nombre de termes demande pour la solution
%  rac    : racine de l'equation indicielle
%  nbsol  : no de la solution calculee ;
%           en fait on calcule !&solution(nbsol) ;
begin
  scalar fcoeff; array ff(k);
  for i:=1:k do ff(i):=!&f(i);
  !&g(0):=1;  %choix arbitraire;
  for ii:=1:k do
    <<
      if den ff(ii) neq 1 then ff(ii):=num(ff(ii));
      if ff(ii) eq 0 then !&g(ii):=0
                    else
                      <<
                        fcoeff:=coeff(ff(ii),!&g(ii));
                        !&g(ii):=-first fcoeff / second fcoeff;
                      >>;
    >>;
  !&solution(nbsol):= (for ii:=0:k sum(sub(lambd=rac,!&g(ii))*x**ii));
  clear ff;
end ;

procedure frobeniusgeneral(x,k,nbsolution) ;
%----------------------------------------- ;
%  x      : variable de l'equation traitee ;
%  k      : nombre de termes demande pour la solution
%  nbsolution  : no de la solution calculee ;
begin
  scalar omega,fcoeff ; array ff(k);
  % determination des : G(i) , ce sont des fonctions de lambda ;
  % choix de g(0);
  for i:=1:k do ff(i):=!&f(i);
  if nbsolution = 2 then
  <<
  if rac(1)=rac(2) then !&g(0):=1
  else
    <<
      % on suppose que les racines sont ordonnees de facon croissante
      % c.a.d. rac(1)>rac(2);
      omega:=rac(1)-rac(2);
      !&g(0):=sub(lambd=lambd+omega,!&f(0));
    >>;
>>;
if nbsolution = 3 then
<<
  omega:=rac(1)-rac(3);
  if omega<0 then omega :=-omega;
%     probleme pour la determination de G(0) - A revoir et verifier;

  !&g(0):=for i:=1:omega product( sub(lambd=lambd+i,!&f(0)) );
>>;

for i:=1:k do
<<
  %rappel K fixe (nombre de terme demande);
  ff(i):=num(ff(i));
  if ff(i) eq 0 then !&g(i):=0
     else
    <<
      fcoeff:=coeff(ff(i),!&g(i));
      !&g(i):=-first fcoeff/second fcoeff;
    >>;
>>;

%determination des solutions;

if rac(1)=rac(2) then
<<
  !&solution(1):=sub(lambd=rac(1),!&w(0,x,lambd,k));
  !&solution(2):=sub(lambd=rac(1),!&w(0,x,lambd,k))
                    *log(x)
          + sub(lambd=rac(1),!&w(1,x,lambd,k));
>>
else
  <<
    !&solution(1):=sub(lambd=rac(1),!&w(0,x,lambd,k));
    if parm(0)=0 then
    !&solution(2):=sub(lambd=rac(2),!&w(0,x,lambd,k))
                    *log(x) +
            sub(lambd=rac(2),!&w(1,x,lambd,k))
    else
    !&solution(2):=!&w(0,x,lambd,k)
                    *log(x) + !&w(1,x,lambd,k);
   >>;

  if nbsolution = 3 then
        !&solution(3):=sub(lambd=rac(3),!&w(0,x,lambd,k))
                       *(log x)**2
            + 2*sub(lambd=rac(3),!&w(1,x,lambd,k))
                       *log(x)
            + sub(lambd=rac(3),!&w(2,x,lambd,k) ) ;
  clear ff;
end ;



%                   +++++++++++++++++++++++++++++++++++++++++++++++
%                   +                                             +
%                   +           PROCEDURES   UTILITAIRES          +
%                   +                                             +
%                   +++++++++++++++++++++++++++++++++++++++++++++++
%;



procedure racine(f,x) ;
%-------------------- ;
% procedure qui calcule les racines quelconques ( et leur ordre de
% multiplicite ) d'une equation algebrique ;
%
%  f     : on cherche les racines de l'equation algebrique f(x)=0
%  x     : variable
%
%  rac   : tableau a une dimension des racines distinctes (de 1 a nbrac)
%  ordremult : tableau correspondand de leur ordre de multiplicite
% cette procedure retourne le nombre de racines distinctes ;
begin
  integer nbrac ;
  scalar sol, multsol ;
  nbrac:=0 ;
  sol:=solve(f,x);
  multsol:=multiplicities!* ;
  for each elt in sol do
    if lhs(elt) = x then
      << nbrac:=nbrac+1 ;
         ordremult(nbrac):=first(multsol);
         multsol:=rest(multsol) ;
         rac(nbrac):=rhs(elt) ;
      >>
      else multsol:=rest(multsol) ;
 return nbrac ;
end ;



symbolic ;
terpri() ; terpri() ;
princ " DESIR : solutions formelles d'equations differentielles" ;
terpri() ;
princ "          lineaires homogenes au voisinage de zero, point " ;
terpri() ;
princ "          singulier regulier ou irregulier, ou point regulier" ;
terpri() ; terpri() ;
princ "                Version  3.1  -  Septembre 1989 " ;  terpri() ;
princ "                   Appel par desir();        " ;  terpri() ;
terpri() ;

on gcd ;

endmodule;

end;
