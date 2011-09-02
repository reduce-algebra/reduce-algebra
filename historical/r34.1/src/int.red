module int; % Header for REDUCE integration package.

% Authors: A. C. Norman and P. M. A. Moore.
% Modified by: J. Davenport, J. P. Fitch, A. C. Hearn.

% Note that at one point, INT had been flagged SIMP0FN.  However, that
% lead to problems when the arguments of INT contained pattern
% variables.

create!-package('(int contents csolve idepend df2q distrib divide driver
                  intfac ibasics makevars jpatches reform  % simplog
                  simpsqrt hacksqrt sqrtf isolve tidysqrt trcase
                  halfangle trialdiv vect),
                  % cuberoot d3d4 factr kron lowdeg unifac uniform tdiff
                '(int trans));

fluid '(!*noextend !*pvar gaussiani);

global '(frlis!* gensymcount initl!*);

!*pvar:='!_a;

gaussiani := !*kk2f '(sqrt -1);

gensymcount := 0;

initl!* := append('(!*noextend), initl!*);

flag('(interr),'transfer);   %For the compiler;

flag ('(atan dilog erf expint expt log tan),'transcendental);

Comment Kludge to define derivative of an integral and integral of
        a derivative;

frlis!* := union('(!=x !=y),frlis!*);

put('df,'opmtch,'(((int !=y !=x) !=x) (nil . t)
                  (evl!* !=y) nil) . get('df,'opmtch));

put('int,'opmtch,'(((df !=y !=x) !=x) (nil . t)
                  (evl!* !=y) nil) . get('int,'opmtch));

put('evl!*,'opmtch,'(((!=x) (nil . t) !=x nil)));

put('evl!*,'simpfn,'simpiden);


% Various functions used throughout the integrator.

symbolic procedure flatten u;
   if null u then nil
    else if atom u then list u
    else if atom car u then car u . flatten cdr u
    else nconc(flatten car u,flatten cdr u);

symbolic procedure int!-gensym1 u;
   <<gensymcount:=gensymcount+1;
     compress append(explode '!!,
                     append(explode u,explode gensymcount))>>;

symbolic procedure mknill n; if n=0 then nil else nil . mknill(n-1);

symbolic procedure printc u; prin2t u;   % This could be an smacro.


% Selector written as an smacro.

smacro procedure argof u;
   % Argument of a unary function.
   cadr u;

put('nthroot,'simpfn,'simpiden);
% The binary n-th root operator nthroot(x,2)=sqrt(x)
% no simplification is used here.
% Hope is that pbuild introduces it, and simplog removes it.

endmodule;


module contents;

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(content indexlist sqfr varlist zlist);   % clogflag

exports contents,contentsmv,dfnumr,difflogs,factorlistlist, % multsqfree
        multup,sqfree,sqmerge;

imports int!-fac,fquotf,gcdf,interr,!*multf,partialdiff,quotf,ordop,
        addf,negf,domainp,difff,mksp,negsq,invsq,addsq,!*multsq,diffsq;


Comment we assume no power substitution is necessary in this module;

symbolic procedure contents(p,v);
% Find the contents of the polynomial p wrt variable v;
% Note that v may not be the main variable of p;
    if domainp(p) then p
    else if v=mvar p then contentsmv(p,v,nil)
    else if ordop(v,mvar p) then p
    else contentsmv(makemainvar(p,v),v,nil);

symbolic procedure contentsmv(p,v,sofar);
% Find contents of polynomial P;
% V is main variable of P;
% SOFAR is partial result;
    if sofar=1 then 1
    else if domainp p then gcdf(p,sofar)
    else if not v=mvar p then gcdf(p,sofar)
    else contentsmv(red p,v,gcdf(lc p,sofar));

symbolic procedure makemainvar(p,v);
% Bring v up to be the main variable in polynomial p.
% Note that the reconstructed p must be used with care since
% it does not conform to the normal REDUCE ordering rules.
    if domainp p then p
    else if v=mvar p then p
    else mergeadd(mulcoeffsby(makemainvar(lc p,v),lpow p,v),
      makemainvar(red p,v),v);

symbolic procedure mulcoeffsby(p,pow,v);
% Multiply each coefficient in p by the standard power pow;
    if null p then nil
    else if domainp p or not v=mvar p then ((pow .* p) .+ nil)
    else (lpow p .* ((pow .* lc p) .+ nil)) .+ mulcoeffsby(red p,pow,v);

symbolic procedure mergeadd(a,b,v);
% Add polynomials a and b given that they have same main variable v;
    if domainp a or not v=mvar a then
      if domainp b or not v=mvar b then addf(a,b)
      else lt b .+ mergeadd(a,red b,v)
    else if domainp b or not v=mvar b then
      lt a .+ mergeadd(red a,b,v)
    else (lambda xc;
      if xc=0 then (lpow a .* addf(lc a,lc b)) .+
            mergeadd(red a,red b,v)
      else if xc>0 then lt a .+ mergeadd(red a,b,v)
      else lt b .+ mergeadd(a,red b,v))
        (tdeg lt a-tdeg lt b);

symbolic procedure sqfree(p,vl);
    if (null vl) or (domainp p) then
        <<content:=p; nil>>
    else begin    scalar w,v,dp,gg,pg,dpg,p1,w1;
        w:=contents(p,car vl); % content of p ;
        p:=quotf(p,w); % make p primitive;
        w:=sqfree(w,cdr vl); % process content by recursion;
        if p=1 then return w;
        v:=car vl; % pick out variable from list;
        while not (p=1) do <<
            dp:=partialdiff(p,v);
            gg:=gcdf(p,dp);
            pg:=quotf(p,gg);
            dpg:=negf partialdiff(pg,v);
            p1:=gcdf(pg,addf(quotf(dp,gg),dpg));
            w1:=p1.w1;
            p:=gg>>;
        return sqmerge(reverse w1,w,t)
        end;

symbolic procedure sqmerge(w1,w,simplew1);
% w and w1 are lists of factors of each power. if simplew1 is true
% then w1 contains only single factors for each power. ;
    if null w1 then w
    else if null w then if car w1=1 then nil.sqmerge(cdr w1,w,simplew1)
          else (if simplew1 then list car w1 else car w1).
sqmerge(cdr w1,w,simplew1)
    else if car w1=1 then (car w).sqmerge(cdr w1,cdr w,simplew1) else
        append(if simplew1 then list car w1 else car w1,car w).
        sqmerge(cdr w1,cdr w,simplew1);

symbolic procedure multup l;
% l is a list of s.f.'s. result is s.f. for product of elements of l;
   begin         scalar res;
      res:=1;
      for each j in l do res := multf(res,j);
%     while not null l do <<
%        res:=multf(res,car l);
%        l:=cdr l >>;
      return res
   end;

symbolic procedure diflist(l,cl,x,rl);
% Differentiates l (list of s.f.'s) wrt x to produce the sum of
% terms for the derivative of numr of 1st part of answer.  cl is
% coefficient list (s.f.'s) & rl is list of derivatives we have
% dealt with so far.  Result is s.q.;
   if null l then nil ./ 1
   else begin    scalar temp;
      temp:=!*multf(multup rl,multup cdr l);
      temp:=!*multsq(difff(car l,x),!*f2q temp);
      temp:=!*multsq(temp,(car cl) ./ 1);
      return addsq(temp,diflist(cdr l,cdr cl,x,(car l).rl))
   end;

%symbolic procedure multsqfree w;
%% W is list of sqfree factors. result is product of each list in w
%% to give one polynomial for each sqfree power.
%   if null w then nil
%    else (multup car w) . multsqfree cdr w;

symbolic procedure l2lsf l;
% L is a list of kernels. result is a list of same members as s.f.'s;
   if null l then nil
   else ((mksp(car l,1) .* 1) .+ nil).l2lsf cdr l;

symbolic procedure dfnumr(x,dl);
% Gives the derivative of the numr of the 1st part of answer.
% dl is list of any exponential or 1+tan**2 that occur in integrand
% denr. these are divided out from result before handing it back.
% result is s.q., ready for printing.
   begin         scalar temp1,temp2,coeflist,qlist,count;
      if not null sqfr then <<
      count:=0;
      qlist:=cdr sqfr;
      coeflist:=nil;
      while not null qlist do <<
         count:=count+1;
         coeflist:=count.coeflist;
         qlist:=cdr qlist >>;
      coeflist:=reverse coeflist >>;
      temp1:=!*multsq(diflist(l2lsf zlist,l2lsf indexlist,x,nil),
                      !*f2q multup sqfr);
      if not null sqfr and not null cdr sqfr then <<
          temp2:=!*multsq(diflist(cdr sqfr,coeflist,x,nil),
                          !*f2q multup l2lsf zlist);
      temp2:=!*multsq(temp2,(car sqfr) ./ 1) >>
      else temp2:=nil ./ 1;
      temp1:=addsq(temp1,negsq temp2);
      temp2:=cdr temp1;
      temp1:=car temp1;
      qlist:=nil;
      while not null dl do <<
         if not car dl member qlist then qlist:=(car dl).qlist;
         dl:=cdr dl >>;
      while not null qlist do <<
         temp1:=quotf(temp1,car qlist);
         qlist:=cdr qlist >>;
      return temp1 ./ temp2
   end;

symbolic procedure difflogs(ll,denm1,x);
% LL is list of log terms (with coeffts), den is common denominator
% over which they are to be put.  Result is s.q. for derivative of all
% these wrt x.
   if null ll then nil ./ 1
   else begin    scalar temp,qu,cvar,logoratan,arg;
      logoratan:=caar ll;
      cvar:=cadar ll;
      arg:=cddar ll;
      temp:=!*multsq(cvar ./ 1,diffsq(arg,x));
      if logoratan='iden then qu:=1 ./ 1
        else if logoratan='log then qu:=arg
        else if logoratan='atan then qu:=addsq(1 ./ 1,!*multsq(arg,arg))
        else interr "Logoratan=? in difflogs";
%Note call to special division routine;
      qu:=fquotf(!*multf(!*multf(denm1,numr temp),
                denr qu),numr qu);
                        %*MUST* GO EXACTLY;
     temp:=!*multsq(!*invsq (denr temp ./ 1),qu);
                 %result of fquotf is a s.q;
      return !*addsq(temp,difflogs(cdr ll,denm1,x))
   end;

symbolic procedure factorlistlist w;
% W is list of lists of sqfree factors in s.f.  Result is list of log
% terms required for integral answer. the arguments for each log fn
% are in s.q.
    begin scalar res,x,y;
        while not null w do <<
            x:=car w;
            while not null x do <<
                y:=facbypp(car x,varlist);
                while not null y do <<
                    res:=append(int!-fac car y,res);
                    y:=cdr y >>;
                x:=cdr x >>;
            w:=cdr w >>;
        return res
    end;

symbolic procedure facbypp(p,vl);
% Use contents/primitive parts to try to factor p.
    if null vl then list p
    else begin scalar princilap!-part,co;
        co:=contents(p,car vl);
        vl:=cdr vl;
        if co=1 then return facbypp(p,vl); %this var no help.
        princilap!-part:=quotf(p,co); %primitive part.
        if princilap!-part=1 then return facbypp(p,vl); % again no help
        return nconc(facbypp(princilap!-part,vl),facbypp(co,vl))
    end;

endmodule;


module csolve;   % routines to do with the C constants.

% Author: John P. Fitch.

fluid '(!*trint ccount cmap cmatrix cval loglist neweqn);

exports backsubst4cs,createcmap,findpivot,printvecsq, % printspreadc
   spreadc,subst4eliminateds;

imports nth,interr,!*multf,printsf,printsq,quotf,putv,negf,invsq,
   negsq,addsq,multsq,mksp,addf,domainp,pnth;

symbolic procedure findpivot cvec;
% Finds first non-zero element in CVEC and returns its cell number.
% If no such element exists, result is nil.
   begin         scalar i,x;
      i:=1;
      x:=getv(cvec,i);
      while i<ccount and null x do
      << i:=i+1;
         x:=getv(cvec,i) >>;
      if null x then return nil;
      return i
   end;

symbolic procedure subst4eliminatedcs(neweqn,substorder,ceqns);
% Substitutes into NEWEQN for all the C's that have been eliminated so
% far. These are given by CEQNS. SUBSTORDER gives the order of
% substitution as well as the constant multipliers. Result is the
% transformed NEWEQN.
   if null substorder then neweqn
   else begin    scalar nxt,row,cvar,temp;
      row:=car ceqns;
      nxt:=car substorder;
      if null (cvar:=getv(neweqn,nxt)) then
         return subst4eliminatedcs(neweqn,cdr substorder,cdr ceqns);
      nxt:=getv(row,nxt);
      for i:=0 : ccount do
      << temp:=!*multf(nxt,getv(neweqn,i));
         temp:=addf(temp,negf !*multf(cvar,getv(row,i)));
         putv(neweqn,i,temp) >>;
      return subst4eliminatedcs(neweqn,cdr substorder,cdr ceqns)
   end;


symbolic procedure backsubst4cs(cs2subst,cs2solve,cmatrix);
% Solves the C-eqns and sets vector CVAL to the C-constant values
% CMATRIX is a list of matrix rows for C-eqns after Gaussian
% elimination has been performed. CS2SOLVE is a list of the remaining
% C's to evaluate and CS2SUBST are the C's we have evaluated already.
   if null cmatrix then nil
   else begin    scalar eqnn,cvar,already,substlist,temp,temp2;
      eqnn:=car cmatrix;
      cvar:=car cs2solve;
      already:=nil ./ 1; % The S.Q. nil.
      substlist:=cs2subst;
% Now substitute for previously evaluated c's:
      while not null substlist do
      << temp:=car substlist;
         if not null getv(eqnn,temp) then
            already:=addsq(already,multsq(getv(eqnn,temp) ./ 1,
                                 getv(cval,temp)));
         substlist:=cdr substlist >>;
% Now solve for the c given by cvar (any remaining c's assumed zero).
      temp:=negsq addsq(getv(eqnn,0) ./ 1,already);
      if not null (temp2:=quotf(numr temp,getv(eqnn,cvar))) then
                                       temp:=temp2 ./ denr temp
      else temp:=multsq(temp,invsq(getv(eqnn,cvar) ./ 1));
      if not null numr temp then putv(cval,cvar,
                resimp rootextractsq subs2q temp);
      backsubst4cs(reversip(cvar . reversip cs2subst),
            cdr cs2solve,cdr cmatrix)
   end;

%**********************************************************************
% Routines to deal with linear equations for the constants C.
%**********************************************************************

symbolic procedure createcmap;
%Sets LOGLIST to list of things of form (LOG C-constant f), where f is
% function linear in one of the z-variables and C-constant is in S.F.
% When creating these C-constant names, the CMAP is also set up and
% returned as the result.
   begin         scalar i,l,c;
      l:=loglist;
      i:=1;
      while not null l do <<
         c:=(int!-gensym1('c) . i) . c;
         i:=i+1;
         rplacd(car l,((mksp(caar c,1) .* 1) .+ nil) . cdar l);
         l:=cdr l >>;
      if !*trint
        then printc ("Constants Created for log and tan terms:" . c);
      return c
   end;


symbolic procedure spreadc(eqnn,cvec1,w);
% Sets a vector 'cvec1' to coefficients of c<i> in eqnn.
    if domainp eqnn then putv(cvec1,0,addf(getv(cvec1,0),
                                !*multf(eqnn,w)))
    else begin    scalar mv,t1,t2;
        spreadc(red eqnn,cvec1,w);
        mv:=mvar eqnn;
        t1:=assoc(mv,cmap); %tests if it is a c var.
        if not null t1 then return <<
            t1:=cdr t1; %loc in vector for this c.
            if not (tdeg lt eqnn=1) then interr "Not linear in c eqn";
            t2:=addf(getv(cvec1,t1),!*multf(w,lc eqnn));
            putv(cvec1,t1,t2) >>;
        t1:=((lpow eqnn) .* 1) .+ nil; %this main var as sf.
        spreadc(lc eqnn,cvec1,!*multf(w,t1))
    end;

% symbolic procedure printspreadc cvec1;
%     begin
%         for i:=0 : ccount do <<
%            prin2 i;
%            printc ":";
%            printsf(getv(cvec1,i)) >>;
%         printc "End of printspreadc output"
%     end;

% symbolic procedure printvecsq cvec;
% % Print contents of cvec which contains s.q.'s (not s.f.'s).
% % Starts from cell 1 not 0 as above routine (printspreadc).
%    begin
%       for i:=1 : ccount do <<
%         prin2 i;
%         printc ":";
%         if null getv(cvec,i) then printc "0"
%         else printsq(getv(cvec,i)) >>;
%       printc "End of printvecsq output"
%    end;

endmodule;


module idepend;  % Routines for considering dependency among variables.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(taylorvariable);

exports dependspl,dependsp,involvesq,involvsf;

imports domainp;

symbolic procedure dependsp(x,v);
   if null v then t
    else if depends(x,v) then x
    else if atom x then if x eq v then x else nil
    else if car x = '!*sq then involvesq(cadr x,v)
    else if taylorp x
     then if v eq taylorvariable then taylorvariable else nil
    else begin scalar w;
       if x=v then return v;
       % Check if a prefix form expression depends on the variable v.
       % Note this assumes the form x is in normal prefix notation;
       w := x; % preserve the dependency;
       x := cdr x; % ready to recursively check arguments;
 scan: if null x then return nil; % no dependency found;
       if dependsp(car x,v) then return w;
       x:=cdr x;
       go to scan
    end;

symbolic procedure involvesq(sq,term);
   involvesf(numr sq,term) or involvesf(denr sq,term);

symbolic procedure involvesf(sf,term);
   if domainp sf or null sf then nil
    else dependsp(mvar sf,term)
       or involvesf(lc sf,term)
       or involvesf(red sf,term);

symbolic procedure dependspl(dep!-list,var);
   % True if any member of deplist (a list of prefix forms) depends on
   % var.
   dep!-list
      and (dependsp(car dep!-list,var) or dependspl(cdr dep!-list,var));

symbolic smacro procedure taylorfunction u; caar u;

symbolic procedure taylorp exxpr;
   % Sees if a random entity is a taylor expression.
   not atom exxpr
       and not atom car exxpr
       and flagp(taylorfunction exxpr,'taylor);

endmodule;


module df2q;   % Conversion from distributive to standard forms.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(indexlist zlist);

exports df2q;

imports addf,gcdf,mksp,!*multf,quotf;

Comment We assume that results already have reduced powers, so
        that no power substitution is necessary;

symbolic procedure df2q p;
   % Converts distributed form P to standard quotient.
   begin scalar n,d,w;
        if null p then return nil ./ 1;
        d:=denr lc p;
        w:=red p;
        while w do
           <<n:=gcdf(d,denr lc w); % Get denominator of answer ...
             d:=!*multf(d,quotf(denr lc w,n));
                 % ... as lcm of denoms in input.
             w:=red w>>;
        n := nil; % Place to build numerator of answer.
        while p do
           <<w := sqrt2top lc p;
             n := addf(n,quotf(!*multf(xl2f(lpow p,zlist,indexlist),
                                       !*multf(numr w,d)),
                       denr w));
             p:=red p>>;
        return n ./ d
    end;

symbolic procedure xl2f(l,z,il);
% L is an exponent list from a D.F., Z is the Z-list,
% IL is the list of indices.
% Value is L converted to standard form. ;
    if null z then 1
        else if car l=0 then xl2f(cdr l,cdr z,cdr il)
        else if not atom car l then
            begin       scalar temp;
                if caar l=0 then temp:= car il
                else temp:=list('plus,car il,caar l);
                temp:=mksp(list('expt,car z,temp),1);
                return !*multf(((temp .* 1) .+ nil),
                               xl2f(cdr l,cdr z,cdr il))
            end
%       else if minusp car l then                                     ;
%            multsq(invsq (((mksp(car z,-car l) .* 1) .+ nil)),       ;
%                  xl2f(cdr l,cdr z,cdr il))                          ;
        else !*multf((mksp(car z,car l) .* 1) .+ nil,
                    xl2f(cdr l,cdr z,cdr il));

endmodule;


module distrib;  % Routines for manipulating distributed forms.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(indexlist sqrtlist zlist);

exports dfprintform,multbyarbpowers,negdf,quotdfconst,sub1ind, % var2df,
   vp1,vp2,plusdf,multdf,multdfconst,orddf;

imports interr,addsq,negsq,exptsq,simp,domainp,mk!*sq,addf,
   multsq,invsq,minusp,mksp,sub1;

%***********************************************************************
% NOTE:     The expressions lt,red,lc,lpow have been used on distributed
%           forms as the latter's structure is sufficiently similar to
%           s.f.'s.  However lc df is a s.q. not a s.f. and lpow df is a
%           list of the exponents of the variables.  This also makes
%           lt df different.  Red df is d.f. as expected.
%***********************************************************************

symbolic procedure plusdf(u,v);
% U and V are D.F.'s. Value is D.F. for U+V.
    if null u then v
        else if null v then u
        else if lpow u=lpow v then
            (lambda(x,y); if null numr x then y else (lpow u .* x) .+ y)
            (!*addsq(lc u,lc v),plusdf(red u,red v))
        else if orddf(lpow u,lpow v) then lt u .+ plusdf(red u,v)
        else (lt v) .+ plusdf(u,red v);

symbolic procedure orddf(u,v);
% U and V are the LPOW of a D.F. - i.e. the list of exponents.
% Value is true if LPOW U '>' LPOW V and false otherwise.
    if null u then if null v then interr "Orddf = case"
        else interr "Orddf v longer than u"
        else if null v then interr "Orddf u longer than v"
        else if exptcompare(car u,car v) then t
        else if exptcompare(car v,car u) then nil
        else orddf(cdr u,cdr v);

symbolic procedure exptcompare(x,y);
    if atom x then if atom y then x>y else nil
        else if atom y then t
        else car x > car y;

symbolic procedure negdf u;
    if null u then nil
        else (lpow u .* negsq lc u) .+ negdf red u;

symbolic procedure multdf(u,v);
% U and V are D.F.'s. Value is D.F. for U*V.
% Reduces squares of square-roots as it goes.
    if null u or null v then nil
    else begin scalar y;
        % use (a+b)*(c+d) = (a*c) + a*(c+d) + b*(c+d).
        y:=multerm(lt u,lt v); %leading terms;
        y:=plusdf(y,multdf(red u,v));
        y:=plusdf(y,multdf((lt u) .+ nil,red v));
        return y
    end;

symbolic procedure multerm(u,v);
% Multiply two terms to give a D.F.
    begin scalar coef;
       coef:=!*multsq(cdr u,cdr v); % coefficient part.
       return multdfconst(coef,mulpower(car u,car v))
    end;

symbolic procedure mulpower(u,v);
% U and v are exponent lists. multiply corresponding forms.
    begin scalar r,s;
       r:=addexptsdf(u,v);
       if not null sqrtlist then s:=reduceroots(r,zlist);
       r:=(r .* (1 ./ 1)) .+ nil;
       if not (s=nil) then r:=multdf(r,s);
       return r
    end;

symbolic procedure reduceroots(r,zl);
    begin scalar s;
       while not null r do <<
          if eqcar(car zl,'sqrt) then
              s:=tryreduction(r,car zl,s);
          r:=cdr r; zl:=cdr zl >>;
       return s
    end;

symbolic procedure tryreduction(r,var,s);
   begin scalar x;
      x:=car r; % current exponent.
      if not atom x then << r:=x; x:=car r >>; % numeric part.
      if (x=0) or (x=1) then return s; % no reduction possible.
      x:=divide(x,2);
      rplaca(r,cdr x); % reduce exponent as redorded.
      x:=car x;
      var:=simp cadr var; % sqrt arg as a s q.
      var:=!*exptsq(var,x);
      x:=multdfconst(1 ./ denr var,f2df numr var); % distribute.
      if s=nil then s:=x
      else s:=multdf(s,x);
      return s
   end;



symbolic procedure addexptsdf(x,y);
% X and Y are LPOW's of D.F. Value is list of sum of exponents.
    if null x then if null y then nil else interr "X too long"
        else if null y then interr "Y too long"
        else exptplus(car x,car y).addexptsdf(cdr x,cdr y);

symbolic procedure exptplus(x,y);
    if atom x then if atom y then x+y else list (x+car y)
        else if atom y then list (car x +y)
        else interr "Bad exponent sum";

symbolic procedure multdfconst(x,u);
% X is S.Q. not involving Z variables of D.F. U. Value is D.F. for X*U.
    if (null u) or (null numr x) then nil
        else lpow u .* !*multsq(x,lc u) .+ multdfconst(x,red u);

%symbolic procedure quotdfconst(x,u);
%    multdfconst(!*invsq x,u);

symbolic procedure f2df p;
% P is standard form. Value is P in D.F.
    if domainp p then dfconst(p ./ 1)
        else if mvar p member zlist then
             plusdf(multdf(vp2df(mvar p,tdeg lt p,zlist),f2df lc p),
                    f2df red p)
        else plusdf(multdfconst(((lpow p .* 1) .+ nil) ./ 1,f2df lc p),
                    f2df red p);

% SYMBOLIC PROCEDURE VAR2DF(VAR,N,ZLIST);
%    ((VP1(VAR,N,ZLIST) .* (1 ./ 1)) .+ NIL);

symbolic procedure vp1(var,degg,z);
% Takes VAR and finds it in Z (=list), raises it to power DEGG and puts
% the result in exponent list form for use in a distributed form.
    if null z then interr "Var not in z-list after all"
        else if var=car z then degg.vp2 cdr z
        else 0 . vp1(var,degg,cdr z);

symbolic procedure vp2 z;
% Makes exponent list of zeroes.
    if null z then nil
        else 0 . vp2 cdr z;

symbolic procedure vp2df(var,exprn,z);
% Makes VAR**EXPRN into exponent list and then converts the resulting
% power into a distributed form.  Special care needed with square-roots.
    if eqcar(var,'sqrt) and (exprn>1) then
        mulpower(vp1(var,exprn,z),vp2 z)
    else (vp1(var,exprn,z) .* (1 ./ 1)) .+ nil;

symbolic procedure dfconst q;
% Makes a distributed form from standard quotient constant Q.
    if numr q=nil then nil
        else ((vp2 zlist) .* q) .+ nil;

% Df2q moved to a section of its own.

symbolic procedure df2printform p;
% Convert to a standard form good enough for printing.
    if null p then nil
    else begin
        scalar mv,co;
        mv:=xl2q(lpow p,zlist,indexlist);
        if mv=(1 ./ 1) then <<
            co:=lc p;
            if denr co=1 then return addf(numr co,
                df2printform red p);
            co:=mksp(mk!*sq co,1);
            return (co .* 1) .+ df2printform red p >>;
        co:=lc p;
        if not (denr co=1) then mv:=!*multsq(mv,1 ./ denr co);
        mv:=mksp(mk!*sq mv,1) .* numr co;
        return mv .+ df2printform red p
    end;


symbolic procedure xl2q(l,z,il);
% L is an exponent list from a D.F.,Z is the Z-list, IL is the list of
% indices.  Value is L converted to standard quotient.
    if null z then 1 ./ 1
        else if car l=0 then xl2q(cdr l,cdr z,cdr il)
        else if not atom car l then
            begin    scalar temp;
                if caar l=0 then temp:= car il
                else temp:=list('plus,car il,caar l);
                temp:=mksp(list('expt,car z,temp),1);
                return !*multsq(((temp .* 1) .+ nil) ./ 1,
                               xl2q(cdr l,cdr z,cdr il))
            end
        else if minusp car l then
             !*multsq(!*invsq(((mksp(car z,-car l) .* 1) .+ nil) ./ 1),
                         xl2q(cdr l,cdr z,cdr il))
        else !*multsq(((mksp(car z,car l) .* 1) .+ nil) ./ 1,
                    xl2q(cdr l,cdr z,cdr il));


%symbolic procedure sub1ind power;
%     if atom power then power-1 else list sub1 car power;

symbolic procedure multbyarbpowers u;
% Multiplies the ordinary D.F., U, by arbitrary powers
% of the z-variables,
%       i-1  j-1  k-1
% i.e. x    z    z    ... so result is D.F. with the exponent list
%            1    2
%appropriately altered to contain list elements instead of numeric ones.
   if null u then nil
   else ((addarbexptsdf lpow u) .* lc u) .+ multbyarbpowers red u;

symbolic procedure addarbexptsdf x;
% Adds the arbitrary powers to powers in exponent list, X, to produce
% new exponent list.  e.g. 3 -> (2) to represent x**3 now becoming :
%          3    i-1    i+2
%         x  * x    = x      .
   if null x then nil
    else list exptplus(car x,-1) . addarbexptsdf cdr x;

endmodule;


module divide;  % Exact division of standard forms to give a S Q.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(!*trdiv !*trint residue sqrtlist zlist);

exports fquotf,testdivdf,dfquotdf;

imports df2q,f2df,gcdf,interr,multdf,negdf,plusdf,printdf,printsf,
   quotf,multsq,invsq,negsq;

% Intended for dividing out known factors as produced by the
% integration program. Horrible and slow, I expect!!

symbolic procedure dfquotdf(a,b);
    begin       scalar residue;
        if (!*trint or !*trdiv) then <<
            printc "Dividing out a simple factor of "; printdf b >>;
        a:=dfquotdf1(a,b);
        if (!*trint or !*trdiv) then <<
            printc "Remaining term to be factorised is ";
            printdf a >>;
        if not null residue then begin
            scalar gres,w;
            % Make one more check for a zero residue.
            if null numr df2q residue then return nil;
            if !*trint or !*trdiv then <<
            printc "Failure in factorisation:";
            printdf residue;
            printc "Which should be zero";
            w:=residue;
            gres:=numr lc w; w:=red w;
            while not null w do <<
                gres:=gcdf(gres,numr lc w);
                w:=red w >>;
            printc "I.e. the following vanishes";
            printsf gres>>;
            interr "Non-exact division due to a log term"
            end;
        return a
   end;

symbolic procedure fquotf(a,b);
% Input: a and b standard quotients with (a/b) an exact
% division with respect to the variables in zlist,
% but not necessarily obviously so. the 'non-obvious' problems
% will be because of (e.g.) square-root symbols in b
% output: standard quotient for (a/b)
% (prints message if remainder is not 'clearly' zero.
% A must not be zero.
    begin         scalar t1;
        if null a then interr "a=0 in fquotf";
        t1:=quotf(a,b); %try it the easy way
        if not null t1 then return t1 ./ 1; %ok
        return df2q dfquotdf(f2df a,f2df b)
    end;

symbolic procedure dfquotdf1(a,b);
    begin       scalar q;
        if null b then interr "Attempt to divide by zero";
        q:=sqrtlist; %remove sqrts from denominator, maybe.
        while not null q do begin
            scalar conj;
            conj:=conjsqrt(b,car q); %conjugate wrt given sqrt
            if not (b=conj) then <<
                a:=multdf(a,conj);
                b:=multdf(b,conj) >>;
            q:=cdr q end;
        q:=dfquotdf2(a,b);
        residue:=reversip residue;
        return q
    end;

symbolic procedure dfquotdf2(a,b);
% As above but a and b are distributed forms, as is the result.
    if null a then nil
    else begin scalar xd,lcd;
        xd:=xpdiff(lpow a,lpow b);
        if xd='failed then <<
            xd:=lt a; a:=red a;
            residue:=xd .+ residue;
            return dfquotdf2(a,b) >>;
        lcd:= !*multsq(lc a,!*invsq lc b);
        if null numr lcd then return dfquotdf2(red a,b);
           % Should not be necessary;
        lcd := xd .* lcd;
        xd:=plusdf(a,multdf(negdf (lcd .+ nil),b));
        if xd and (lpow xd = lpow a % Again, should not be necessary;
                   or xpdiff(lpow xd,lpow b) = 'failed)
          then <<if !*trint or !*trdiv
                   then <<printc "Problems in dividing:"; printdf xd>>;
                 xd := rootextractdf xd;
                 if !*trint or !*trdiv then printdf xd>>;
        return lcd .+ dfquotdf2(xd,b)
    end;

symbolic procedure rootextractdf u;
   if null u then nil
    else begin scalar v;
      v := resimp rootextractsq lc u;
      return if null numr v then rootextractdf red u
              else (lpow u .* v) .+ rootextractdf red u
    end;

symbolic procedure rootextractsq u;
   if null numr u then u
    else rootextractf numr u ./ rootextractf denr u;

symbolic procedure rootextractf v;
   if domainp v then v
    else begin scalar u,r,c,x,p;
      u := mvar v;  p := ldeg v;
      r := rootextractf red v;
      c := rootextractf lc v;
      if null c then return r
       else if atom u then return (lpow v .* c) .+ r
       else if car u eq 'sqrt
        or car u eq 'expt and eqcar(caddr u,'quotient)
           and car cdaddr u = 1 and numberp cadr cdaddr u
        then <<p := divide(p,if car u eq 'sqrt then 2
                              else cadr cdaddr u);
      if car p = 0
        then return if null c then r else (lpow v .* c) .+ r
       else if numberp cadr u
        then <<c := multd(cadr u ** car p,c); p := cdr p>>
       else <<x := simpexpt list(cadr u,car p);
              if denr x = 1
                then <<c := multf(numr x,c); p := cdr p>>>>>>;
      % D. Dahm suggested an additional call of rootextractf on the
      % result here.  This does cause some expressions to simplify
      % sooner, but also leads to infinite loops with expressions
      % like (a*x+b)**p.
      return if p=0 then addf(c,r)
              else if null c then r
              else ((u to p) .* c) .+ r
   end;

% The following hack makes sure that the results of differentiation
% gets passed through ROOTEXTRACT
% a) This should not be done this way, since the effect is global
% b) Should this be done via TIDYSQRT?

put('df,'simpfn,'simpdf!*);

symbolic procedure simpdf!* u;
  begin scalar v,v1;
        v:=simpdf u;
        v1:=rootextractsq v;
        if not(v1=v) then return resimp v1
        else return v
end;

symbolic procedure xpdiff(a,b);
%Result is list a-b, or 'failed' if a member of this would be negative.
    if null a then if null b then nil
        else interr "B too long in xpdiff"
    else if null b then interr "A too long in xpdiff"
    else if car b>car a then 'failed
    else (lambda r;
        if r='failed then 'failed
        else (car a-car b) . r) (xpdiff(cdr a,cdr b));


symbolic procedure conjsqrt(b,var);
% Subst(var=-var,b).
    if null b then nil
    else conjterm(lpow b,lc b,var) .+ conjsqrt(red b,var);

symbolic procedure conjterm(xl,coef,var);
% Ditto but working on a term.
    if involvesp(xl,var,zlist) then xl .* negsq coef
    else xl .* coef;

symbolic procedure involvesp(xl,var,zl);
% Check if exponent list has non-zero power for variable.
    if null xl then interr "Var not found in involvesp"
    else if car zl=var then car xl neq 0
    else involvesp(cdr xl,var,cdr zl);

endmodule;


module driver;  % Driving routines for integration program.

% Author: Mary Ann Moore and Arthur C. Norman.
% Modifications by: John P. Fitch.

fluid '(!*algint
        !*backtrace
        !*exp
        !*failhard
        !*gcd
        !*intflag!*
        !*keepsqrts
        !*limitedfactors
        !*mcd
        !*nolnr
        !*purerisch
        !*rationalize
        !*structure
        !*trdint
        !*trint
        !*uncached
        basic!-listofnewsqrts
        basic!-listofallsqrts
        gaussiani
        intvar
        kord!*
        listofnewsqrts
        listofallsqrts
        loglist
        sqrt!-intvar
        sqrt!-places!-alist
        varlist
        varstack!*
        xlogs
        zlist);

exports integratesq,simpint,simpint1;

imports algebraiccase,algfnpl,findzvars,getvariables,interr,printsq,
  transcendentalcase,varsinlist,kernp,simpcar,prepsq,mksq,simp,
   opmtch,formlnr;

switch algint,nolnr,trdint,trint;

% Form is   int(expr,var,x1,x2,...);
% meaning is integrate expr wrt var, given that the result may
% contain logs of x1,x2,...
% x1, etc are intended for use when the system has to be helped
% in the case that expr is algebraic.
% Extended arguments x1, x2, etc., are not currently supported.

symbolic procedure simpint u;
% Simplifies an integral. First two components of U are the integrand
% and integration variable respectively. Optional succeeding components
% are log forms for the final integral.
   if atom u or null cdr u or cddr u and (null cdddr u or cddddr u)
     then rerror(int,1,"Improper number of arguments to INT")
    else if cddr u
     then if getd 'simpdint then simpdint u
           else rerror(int,2,"Improper number of arguments to INT")
    else begin scalar ans,expression,variable,loglist,w,oldvarstack,
                 !*intflag!*,!*purerisch,intvar,listofnewsqrts,
                 listofallsqrts,sqrtfn,sqrt!-intvar,sqrt!-places!-alist,
                 basic!-listofallsqrts,basic!-listofnewsqrts,coefft;
    !*intflag!* := t;     % Shows we are in integrator.
    variable := !*a2k cadr u;
    intvar := variable;   % Used in SIMPSQRT and algebraic integrator.
    w := cddr u;
    if w then rerror(int,3,"Too many arguments to INT");
    listofnewsqrts:= list mvar gaussiani; % Initialize for SIMPSQRT.
    listofallsqrts:= list (argof mvar gaussiani . gaussiani);
    sqrtfn := get('sqrt,'simpfn);
    put('sqrt,'simpfn,'proper!-simpsqrt);
    % We need explicit settings of several switches during integral
    % evaluation.  In addition, the current code cannot handle domains
    % like floating point, so we suppress it while the integral is
    % calculated.  UNCACHED is turned on since integrator does its own
    % caching.
    % Any changes made to these settings must also be made in wstrass.
    begin scalar dmode!*,!*exp,!*gcd,!*keepsqrts,!*limitedfactors,!*mcd,
                 !*rationalize,!*structure,!*uncached,kord!*,
                 ans1,denexp,badbit,nexp,oneterm;    % JPff
       !*keepsqrts := !*limitedfactors := t;     % !*sqrt := t;
       !*exp := !*gcd := !*mcd := !*structure := !*uncached := t;
       dmode!* := nil;
       if !*algint
         then <<
            % Start a clean slate (in terms of SQRTSAVE) for this
            % integral.
            sqrt!-intvar:=!*q2f simpsqrti variable;
            if (red sqrt!-intvar) or (lc sqrt!-intvar neq 1)
                or (ldeg sqrt!-intvar neq 1)
              then interr "Sqrt(x) not properly formed"
              else sqrt!-intvar:=mvar sqrt!-intvar;
            basic!-listofallsqrts:=listofallsqrts;
            basic!-listofnewsqrts:=listofnewsqrts;
            sqrtsave(basic!-listofallsqrts,basic!-listofnewsqrts,
                         list(variable . variable))>>;
       coefft := (1 ./ 1);           % Collect simple coefficients.
       expression := int!-simp car u;
       denexp := 1 ./ denr expression;          % Get into two bits
       nexp := numr expression;
       while not atom nexp and null cdr nexp and
          not depends(mvar nexp,variable) do
              <<coefft := multsq(coefft,(((caar nexp) . 1) . nil) ./ 1);
                nexp := lc nexp>>;
       ans1 := nil;
       while nexp do begin              % Collect by zvariables
           scalar x,zv,tmp;
           if atom nexp then << x:=!*f2q nexp; nexp:=nil >>
           else << x:=!*t2q car nexp; nexp:=cdr nexp >>;
           x := multsq(x,denexp);
           zv := findzvars(getvariables x,list variable,variable,nil);
           begin scalar oldzlist;
               while oldzlist neq zv do <<
                    oldzlist := zv;
                    foreach zz in oldzlist do
                    zv:=findzvars(distexp(pseudodiff(zz,variable)),
                                  zv,variable,t)>>;
               % The following line was added to make, for example,
               % int(df(sin(x)/x),x) return the expected result.
               zv := sort(zv, function ordp)
           end;
           tmp := ans1;
           while tmp do
              <<if zv=caar tmp
                  then <<rplacd(car tmp,addsq(cdar tmp,x));
                         tmp := nil; zv := nil>>
                 else tmp := cdr tmp>>;
           if zv then ans1 := (zv . x) . ans1
       end;
       if length ans1 = 1 then oneterm := t; % Efficiency
       nexp := ans1;
       ans := nil ./ 1;
       badbit:=nil ./ 1;                        % SQ zero
       while nexp do                            % Run down the terms
        <<u := cdar nexp;
          if !*trdint
            then <<princ "Integrate"; printsq u;
                   princ "with Zvars "; print caar nexp>>;
          ans1 := errorset!*(list('integratesq,mkquote u,
                             mkquote variable,mkquote loglist,
                             mkquote caar nexp),
                             !*backtrace);
          nexp := cdr nexp;
          if errorp ans1 then badbit := addsq(badbit,u)
           else <<ans := addsq(caar ans1, ans);
                  badbit:=addsq(cdar ans1,badbit)>>>>;
       if !*trdint
         then <<prin2 "Partial answer="; printsq ans;
                prin2 "To do="; printsq badbit>>;
       % We have run down the terms.  If there are any bad bits, redo
       % them.  However, since a non-zero badbit implies that
       % integratesq aborted, the internal variable order may be
       % confused.  So we reset kord!* and reorder expressions in this
       % case.
       if badbit neq '(nil . 1)
         then <<setkorder nil;
                badbit := reordsq badbit;
                ans := reordsq ans;
                coefft := reordsq coefft;
          if !*trdint then <<princ "Retrying..."; printsq badbit>>;
          if oneterm and ans = '(nil . 1) then ans1 := nil
            else ans1 := errorset!*(list('integratesq,mkquote badbit,
                                  mkquote variable,mkquote loglist,nil),
                                  !*backtrace);
          if null ans1 or errorp ans1
            then ans := addsq(ans,simpint1(badbit . variable . w))
           else <<ans := addsq(ans,caar ans1);
                  if cdar ans1 neq '(nil . 1)
                    then ans := addsq(ans,
                                    simpint1(cdar ans1 . variable . w))
                >>>>;
    end;
    ans := multsq(ans, coefft);                 % Put back coefficient
%    if errorp ans
%      then return <<put('sqrt,'simpfn,sqrtfn);
%                    if !*failhard then error1();
%                    simpint1(expression . variable . w)>>
%     else ans := car ans;
%   expression := sqrtchk numr ans ./ sqrtchk denr ans;
    if !*trdint then << printc "Resimp and all that"; printsq ans >>;
    % We now need to check that all simplifications have been done
    % but we have to make sure INT is not resimplified, and that SIMP
    % does not complain at getting the same argument again.
    put('int,'simpfn,'simpiden);
    put('sqrt,'simpfn,sqrtfn);
    oldvarstack := varstack!*;
    varstack!* := nil;
    ans := errorset!*(list('resimp,mkquote ans),t);
    put('int,'simpfn,'simpint);
    varstack!* := oldvarstack;
    return if errorp ans then error1() else car ans
   end;

% symbolic procedure sqrtchk u;
%    % U is a standard form. Result is another standard form with square
%    % roots replaced by half powers.
%    if domainp u then u
%     else if not eqcar(mvar u,'sqrt)
%      then addf(multpf(lpow u,sqrtchk lc u),sqrtchk red u)
% %   else if mvar u = '(sqrt -1)
% %    then addf(multpf(mksp('i,ldeg u),sqrtchk lc u),sqrtchk red u)
%     else addf(multpf(mksp(list('expt,cadr mvar u,'(quotient 1 2)),
%                           ldeg u),
%                      sqrtchk lc u),
%               sqrtchk red u);

symbolic procedure int!-simp u;
   % Converts U to canonical form, including the resimplification of
   % *sq forms.
   subs2 resimp simp!* u;

put('int,'simpfn,'simpint);

symbolic procedure integratesq(integrand,var,xlogs,zv);
 begin scalar varlist,zlist;
    if !*trint then <<
        printc "Start of Integration; integrand is ";
        printsq integrand >>;
    varlist:=getvariables integrand;
    varlist:=varsinlist(xlogs,varlist); %in case more exist in xlogs
    if zv then zlist := zv
     else <<zlist := findzvars(varlist,list var,var,nil);
            % Important kernels.
    % The next section causes problems with nested exponentials or logs.
            begin scalar oldzlist;
                while oldzlist neq zlist do
                 <<oldzlist := zlist;
                   foreach zz in oldzlist do
                   zlist := findzvars(distexp(pseudodiff(zz,var)),
                                        zlist,var,t)>>
            end>>;
    if !*trint  then <<
      printc "Determination of the differential field descriptor";
      printc "gives the functions:";
      print zlist >>;
    if !*purerisch and not allowedfns zlist
      then return (nil ./ 1) . integrand;
      % If it is not suitable for Risch.
    varlist := setdiff(varlist,zlist);
%   varlist := purge(zlist,varlist);
    % Now zlist is list of things that depend on x, and varlist is list
    % of constant kernels in integrand.
    if !*algint and cdr zlist and algfnpl(zlist,var)
      then return algebraiccase(integrand,zlist,varlist)
     else return transcendentalcase(integrand,var,xlogs,zlist,varlist)
 end;

symbolic procedure distexp(l);
    if null l then nil
    else if atom car l then car l . distexp cdr l
    else if (caar l = 'expt) and (cadar l = 'e) then
        begin scalar ll;
            ll:=caddr car l;
            if eqcar(ll,'plus) then <<
                ll:=foreach x in cdr ll collect list('expt,'e,x);
                return ('times . ll) . distexp cdr l >>
            else return car l . distexp cdr l
        end
    else distexp car l . distexp cdr l;

symbolic procedure pseudodiff(a,var);
    if atom a then nil
    else if car a
               memq '(atan equal log plus quotient sqrt times minus)
        then begin scalar aa,bb;
            foreach zz in cdr a do <<
                bb:=pseudodiff(zz,var);
                aa:= union(bb,aa) >>;
            return aa
        end
      else if car a eq 'expt
        then if depends(cadr a,var) then
            if depends(caddr a,var) then
                prepsq simp list('log,cadr a) . %% a(x)^b(x)
                cadr a .
                caddr a .
                union(pseudodiff(cadr a,var),pseudodiff(caddr a,var))
            else cadr a . pseudodiff(cadr a,var)        %% a(x)^b
        else caddr a . pseudodiff(caddr a,var)          %% a^b(x)
    else list prepsq simpdf(list(a,var));

symbolic procedure simpint1 u;
   % Varstack* rebound, since FORMLNR use can create recursive
   % evaluations.  (E.g., with int(cos(x)/x**2,x)).
   begin scalar !*keepsqrts,v,varstack!*;
      u := 'int . prepsq car u . cdr u;
      if (v := formlnr u) neq u
        then if !*nolnr
               then <<v := simp subst('int!*,'int,v);
                      return remakesf numr v ./ remakesf denr v>>
              else <<!*nolnr := nil . !*nolnr;
                     v:=errorset!*(list('simp,mkquote v),!*backtrace);
                     if pairp v then v := car v else v := simp u;
                     !*nolnr := cdr !*nolnr;
                     return v>>;
      return if (v := opmtch u) then simp v
              else if !*failhard
               then rerror(int,4,"FAILHARD switch set")
              else mksq(u,1)
   end;

mkop 'int!*;

put('int!*,'simpfn,'simpint!*);

symbolic procedure simpint!* u;
   begin scalar x;
      return if (x := opmtch('int . u)) then simp x
              else simpiden('int!* . u)
   end;

symbolic procedure remakesf u;
   %remakes standard form U, substituting operator INT for INT!*;
   if domainp u then u
    else addf(multpf(if eqcar(mvar u,'int!*)
                       then mksp('int . cdr mvar u,ldeg u)
                      else lpow u,remakesf lc u),
               remakesf red u);

symbolic procedure allowedfns u;
if null u
  then t
  else if atom car u or
      flagp(caar u,'transcendental)
    then allowedfns cdr u
    else nil;

endmodule;


module intfac;   % Interface between integrator and factorizer.

% Author:  Anthony C. Hearn.

% Based on earlier versions by James Davenport, Mary Ann Moore and
% Arthur Norman.

fluid '(!*intfac !*surds kord!* zlist);  % clogflag

exports int!-fac;

symbolic procedure int!-fac x;
   % X is a primitive, square-free polynomial, except for monomial
   % factors.  Result is a list of 'factors' wrt zlist.
   % Throughout most of the integrator we want to add new surds, so we
   % turn surds on.  However, we use *intfac to inhibit use of quadratic
   % factorizer in the poly/primfac module, since things don't work
   % properly if this is used.
   begin scalar !*intfac,!*surds;
      !*intfac := !*surds := t;
      return int!-fac!-inner x;
   end;

symbolic procedure int!-fac!-inner x;
   % X is a primitive, square-free polynomial, except for monomial
   % factors.  Result is a list of  'factors' wrt zlist.
   begin scalar factors;
      factors := fctrf x;
      factors := cdr factors; % Ignore monomial factor.
      % Make sure x really square-free.
      factors := for each u in factors
                    collect if cdr u=1 then car u
                             else interr list(x,"not square free");
      % It seems we need the logs ordered ahead of atans, hence reverse.
      return reversip for each u in factors join fac2int u
   end;

symbolic procedure fac2int u;
   % Returns a list of all the arctangents and logarithms arising from
   % an attempt to take the one irreducible (but not necessarily the
   % absolutely irreducible) factor u.
   begin scalar degrees,x;
      degrees := for each w in zlist collect (degreef(u,w) . w);
      if assoc(1,degrees) then return list ('log . (u ./ 1))
      % An irreducible polynomial of degree 1 is absolutely irreducible.
       else if x := assoc(2,degrees) then return int!-quadterm(u,cdr x)
       else if assoc(0,degrees) then return list('log . (u ./ 1));
      % This suggests a surd occurs. Should that be an error?
      if !*trint
        then <<printc "*** Polynomial";
               printsf u;
               printc "has not been completely factored">>;
      return list ('log . (u ./ 1))
   end;

symbolic procedure degreef(pol,var);
   % Find degree of variable var in standard form pol.
   if domainp pol then 0
    else if mvar pol = var then ldeg pol
    else max(degreef(lc pol,var),degreef(red pol,var));

symbolic procedure int!-quadterm(pol,var);
   % Add in logs and atans corresponding to splitting the polynomial pol
   % given it is quadratic wrt var.  Does not assume pol is univariate.
   begin scalar a,b,c,discrim,kord,res,w;
      kord := setkorder(var . kord!*);   % It shouldn't matter if
                                         % var occurs twice.
      c := reorder pol;
      if ldeg c neq 2
        then <<setkorder kord;
               rerror(int,5,"Invalid polynomial in int-quadterm")>>;
      a := lc c;
      c := red c;
      if not domainp c and mvar c = var and ldeg c = 1
        then <<b := lc c; c := red c>>;
      setkorder kord;
      discrim := powsubsf addf(multf(b,b),multd(-4,multf(a,c)));
      if null discrim then interr "discrim is zero in quadterm";
      % A quadratic usually implies an atan term.
%     if not clogflag
%       then <<w := rootxf(negf discrim,2);
%              if not(w eq 'failed) then go to atancase>>;
      w := rootxf(negf discrim,2);
      if not(w eq 'failed) then go to atancase;
      w := rootxf(discrim,2);
      if w eq 'failed then return list ('log . !*f2q pol);
%     if w eq 'failed then rederr "Integration failure in int-quadterm";
      discrim := w;
      w := multpf(mksp(var,1),a);
      w := addf(multd(2,w),b);   % 2*a*x + b.
      a := addf(w,discrim);
      b := addf(w,negf discrim);
      % Remove monomial multipliers.
      a := quotf(a,cdr comfac a);
      b := quotf(b,cdr comfac b);
      return ('log . !*f2q a) . ('log . !*f2q b) . res;
   atancase:
      res := ('log . !*f2q pol) . res;   % One part of answer.
      a := multpf(mksp(var,1),a);
      a := addf(b,multd(2,a));
      a := fquotf(a,w);
      return ('atan . a) . res
   end;

endmodule;


module ibasics;   % Some basic support routines for integrator.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(!*backtrace !*gcd !*sqfree !*trint indexlist sqrtflag sqrtlist
        varlist zlist);

exports partialdiff,printdf,interr;

imports df2printform,printsf,varsinsf,addsq,multsq,multd,mksp;

symbolic procedure printdf u;
% Print distributed form via cheap conversion to reduce structure.
    begin scalar !*gcd;
       printsf df2printform u;
    end;

% symbolic procedure indx(n);
%    if n<2 then (list 1) else(n . indx(isub1 n));

symbolic procedure interr mess;
   <<if !*trint or !*backtrace
       then <<prin2 "***** INTEGRATION PACKAGE ERROR:  "; printc mess>>;
     error1()>>;

symbolic procedure partialdiff(p,v);
% Partial differentiation of p wrt v - p is s.f. as is result.
    if domainp p then nil
    else
        if v=mvar p then
            (lambda x; if x=1 then lc p
             else ((mksp(v,x-1) .* multd(x,lc p))
                         .+ partialdiff(red p,v)))
            (tdeg lt p)
        else
            (lambda x; if null x then partialdiff(red p,v)
             else ((lpow p .* x) .+ partialdiff(red p,v)))
            (partialdiff(lc p,v));

put('pdiff,'simpfn,'simppdiff);

symbolic procedure mkilist(old,term);
   if null old then nil
    else term.mkilist(cdr old,term);

% symbolic procedure addin(lista,first,listb);
% if null lista
%  then nil
%  else ((first.car listb).car lista).addin(cdr lista,first,cdr listb);

symbolic procedure removeduplicates(u);
  % Purges duplicates from the list passed to it.
if null u then nil
  else if (atom u) then u.nil
    else if member(car u,cdr u)
      then removeduplicates cdr u
      else (car u).removeduplicates cdr u;

symbolic procedure jsqfree(sf,var);
begin
  varlist:=getvariables(sf ./ 1);
  zlist:=findzvars(varlist,list var,var,nil);
  sqrtlist:=findsqrts varlist; % before the purge
  sqrtflag:=not null sqrtlist;
  varlist := setdiff(varlist,zlist);
  return if sf eq !*sqfree then list list sf else sqfree(sf,zlist)
  end;

symbolic procedure stt(u,x);
  if domainp u
    then if u eq nil
      then ((-1) . nil)
      else (0 . u)
    else if mvar u eq x
      then ldeg  u . lc u
      else if ordop(x,mvar u)
        then (0 . u)
        else begin
          scalar ltlc,ltrest;
          ltlc:=stt(lc u,x);
          ltrest:= stt(red u,x);
          if car ltlc = car ltrest then go to merge;
          if car ltlc > car ltrest
            then return car ltlc .
                             !*multf(cdr ltlc,(lpow u .* 1) .+ nil)
            else return ltrest;
        merge:
          return car ltlc.addf(cdr ltrest,
                               !*multf(cdr ltlc,(lpow u .* 1) .+ nil))
          end;

symbolic procedure mapply(funct,l);
   if null l then rerror(int,6,"Empty list to mapply")
    else if null cdr l then car l
    else apply2(funct,car l,mapply(funct,cdr l));

% symbolic procedure intersect(x,y);
%    if null x then nil else if member(car x,y) then
%     car(x) . intersect(cdr x,y) else
%          intersect(cdr x,y);

symbolic procedure mapvec(v,f);
   begin
      scalar n;
      n:=upbv v;
      for i:=0:n do apply1(f,getv(v,i))
   end;

endmodule;


module makevars; % Make dummy variables for integration process.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(!*gensymlist!* !*purerisch);

% exports getvariables,varsinlist,varsinsf,findzvars,  % varsinsq
%         createindices,mergein;

% imports dependsp,union;

% Note that 'i' is already maybe committed for sqrt(-1),
% also 'l' and 'o' are not used as they print badly on certain
% terminals etc and may lead to confusion.

!*gensymlist!* := '(! j ! k ! m ! n ! p ! q ! r ! s ! t ! u ! v ! w ! x
                    ! y ! z);

%mapc(!*gensymlist!*,function remob); %REMOB protection;


symbolic procedure varsinlist(l,vl);
% L is a list of s.q. - find all variables mentioned,
% given thal vl is a list already known about.
    begin       while not null l do <<
            vl:=varsinsf(numr car l,varsinsf(denr car l,vl));
            l:=cdr l >>;
        return vl
    end;

symbolic procedure getvariables sq;
    varsinsf(numr sq,varsinsf(denr sq,nil));

symbolic procedure varsinsf(form,l);
   if domainp form then l
   else begin
     while not domainp form do <<
        l:=varsinsf(lc form,union(l,list mvar form));
        form:=red form >>;
     return l
   end;

symbolic procedure findzvars(vl,zl,var,flg);
    begin scalar v;
   % VL is the crude list of variables found in the original integrand.
   % ZL must have merged into it all EXP, LOG etc terms from this.
   % If FLG is true then ignore DF as a function.
scan: if null vl then return zl;
         v:=car vl; % next variable.
         vl:=cdr vl;
   % At present items get put onto ZL if they are non-atomic
   % and they depend on the main variable. The arguments of
   % functions are decomposed by recursive calls to findzvar.
   % Give up if V has been declared dependent on other things.
        if atom v and v neq var and depends(v,var) then
           rerror(int,7,
                  "Can't integrate in the presence of side-relations")
         else if not atom v and (not v member zl) and dependsp(v,var)
         then if car v='!*sq then zl:=findzvarssq(cadr v,zl,var)
         else if car v memq '(times quotient plus minus difference)
                 or (((car v) eq 'expt) and fixp caddr v)
             then
                 zl:=findzvars(cdr v,zl,var,flg)
         else if flg and car v eq 'df
          then <<!*purerisch := t; return zl>> % try and stop it
             else zl:=v . findzvars(cdr v,zl,var,flg);
                 % scan arguments of fn.
             %ACH: old code used to look only at CADR if a DF involved.
        go to scan
   end;

symbolic procedure findzvarssq(sq,zl,var);
    findzvarsf(numr sq,findzvarsf(denr sq,zl,var),var);

symbolic procedure findzvarsf(sf,zl,var);
    if domainp sf then zl
    else findzvarsf(lc sf,
                    findzvarsf(red sf,
                               findzvars(list mvar sf,zl,var,nil),
                               var),
                  var);

symbolic procedure createindices zl;
% Produces a list of unique indices, each associated with a ; 
% different Z-variable; 
     reversip crindex1(zl,!*gensymlist!*);

symbolic procedure crindex1(zl,gl);
 begin if null zl then return nil;
    if null gl then << gl:=list int!-gensym1 'i; %new symbol needed;
        nconc(!*gensymlist!*,gl) >>;
    return (car gl) . crindex1(cdr zl,cdr gl) end;

symbolic procedure rmember(a,b);
    if null b then nil
    else if a=cdar b then car b
    else rmember(a,cdr b);

symbolic procedure mergein(dl,ll);
    % Adjoin logs of things in dl to existing list ll.
    if null dl then ll
    else if rmember(car dl,ll) then mergein(cdr dl,ll)
    else mergein(cdr dl,('log . car dl) . ll);

endmodule;


module jpatches;   % Routines for manipulating sf's with power folding.

% Author: James H. Davenport.

fluid '(sqrtflag);

exports !*addsq,!*multsq,!*invsq,!*multf,!*exptsq,!*exptf; %squashsqrtsq

% !*MULTF(A,B) multiplies the polynomials (standard forms) U and V
% in much the same way as MULTF(U,V) would, EXCEPT...
%     (1) !*MULTF inhibits the action of OFF EXP and of non-commutative
%         multiplications
%     (2) Within !*MULTF powers of square roots, and powers of
%         exponential kernels are reduced as if substitution rules
%         such as FOR ALL X LET SQRT(X)**2=X were being applied;

% Note that !*MULTF comes between MULTF and !*Q2F SUBS2F MULTF in its
% behaviour, and that it is the responsibility of the user to call it
% in sensible places where its services are needed.

% Similarly for the other functions defined here.


%symbolic procedure !*addsq(u,v);
   %U and V are standard quotients.
%  %Value is canonical sum of U and V;
%   if null numr u then v
%    else if null numr v then u
%    else if denr u=1 and denr v=1 then addf(numr u,numr v) ./ 1
%    else begin scalar nu,du,nv,dv,x;
%        x := gcdf(du:=denr u,dv:=denr v);
%        du:=quotf(du,x); dv:=quotf(dv,x);
%        nu:=numr u; nv:=numr v;
%        u:=addf(!*multf(nu,dv),!*multf(nv,du));
%        if u=nil then return nil ./ 1;
%        v:=!*multf(du,denr v);
%        return !*ff2sq(u,v)
%    end;

%symbolic procedure !*multsq(a,b);
%  begin
%    scalar n,d;
%    n:=!*multf(numr a,numr b);
%    d:=!*multf(denr a,denr b);
%    return !*ff2sq(n,d)
%  end;

%symbolic procedure !*ff2sq(a,b);
%  begin
%    scalar gg;
%    if null a then return nil ./ 1;
%    gg:=gcdf(a,b);
%    if not (gg=1) then <<
%        a:=quotf(a,gg);
%        b:=quotf(b,gg) >>;
%    if minusf b then <<
%        a:=negf a;
%        b:=negf b >>;
%    return a ./ b
%  end;

symbolic procedure !*addsq(u,v);
   %U and V are standard quotients.
   %Value is canonical sum of U and V;
   if null numr u then v
    else if null numr v then u
    else if denr u=1 and denr v=1 then addf(numr u,numr v) ./ 1
    else begin scalar du,dv,x,y,z;
        x := gcdf(du:=denr u,dv:=denr v);
        du:=quotf(du,x); dv:=quotf(dv,x);
        y:=addf(!*multf(dv,numr u),!*multf(du,numr v));
        if null y then return nil ./ 1;
        z:=!*multf(denr u,dv);
        if minusf z then <<y := negf y; z := negf z>>;
        % In this case (as opposed to ADDSQ), Y and Z may have
        % developed common factors from SQRT expansion, so a
        % gcd of Y and Z is needed.
        x := gcdf(y,z);
        return if x=1 then y ./ z else quotf(y,x) ./ quotf(z,x)
    end;

symbolic procedure !*multsq(u,v);
   %U and V are standard quotients. Result is the canonical product of
   %U and V with surd powers suitably reduced.
   if null numr u or null numr v then nil ./ 1
    else if denr u=1 and denr v=1 then !*multf(numr u,numr v) ./ 1
    else begin scalar w,x,y;
     x := gcdf(numr u,denr v);
     y := gcdf(numr v,denr u);
     w := !*multf(quotf(numr u,x),quotf(numr v,y));
     x := !*multf(quotf(denr u,y),quotf(denr v,x));
     if minusf x then <<w := negf w; x := negf x>>;
     y := gcdf(w,x);  % another factor may have been generated.
     return if y=1 then w ./ x else quotf(w,y) ./ quotf(x,y)
    end;

symbolic procedure !*invsq a;
   % Note that several examples (e.g., int(1/(x**8+1),x)) give a more
   % compact result when SQRTFLAG is true if SQRT2TOP is not called.
   if sqrtflag then sqrt2top invsq a else invsq a;

symbolic procedure !*multf(u,v);
  % U and V are standard forms
  % Value is SF for U*V;
  begin
    scalar x,y;
      if null u or null v
      then return nil
      else if u = 1
        then return squashsqrt v
        else if v = 1
        then return squashsqrt u
        else if domainp u
          then return multd(u,squashsqrt v)
          else if domainp v
            then return multd(v,squashsqrt u);
      x:=mvar u;
      y:=mvar v;
      if x eq y
        then go to c
        else if ordop(x,y)
          then go to b;
      x:=!*multf(u,lc v);
      y:=!*multf(u,red v);
      return if null x then y
              else if not domainp lc v
                and mvar u eq mvar lc v
                and not atom mvar u
                and car mvar u memq '(expt sqrt)
               then addf(!*multf(x,!*p2f lpow v),y) % what about noncom?
              else makeupsf(lpow v,x,y);
  b:  x:=!*multf(lc u,v);
      y:=!*multf(red u,v);
      return if null x then y
              else if not domainp lc u
                and mvar lc u eq mvar v
                and not atom mvar v
                and car mvar v memq '(expt sqrt)
               then addf(!*multf(!*p2f lpow u,x),y)
              else makeupsf(lpow u,x,y);
  c:  y:=addf(!*multf(list lt u,red v),!*multf(red u,v));
      if eqcar(x,'sqrt)
        then return addf(squashsqrt y,!*multfsqrt(x,
                        !*multf(lc u,lc v),ldeg u + ldeg v))
        else if eqcar(x,'expt) and prefix!-rational!-numberp caddr x
          then return addf(squashsqrt y,!*multfexpt(x,
                        !*multf(lc u,lc v),ldeg u + ldeg v));
      x:=mkspm(x,ldeg u + ldeg v);
      return if null x or null (u:=!*multf(lc u,lc v))
               then y
               else addf(multpf(x,u),y)
    end;

symbolic procedure makeupsf(u,x,y);
% Makes u .* x .+ y  except when u is not a valid lpow (because of
% sqrts).
   if atom car u or cdr u = 1 then addf(multpf(u,x),y)
     else if caar u eq 'sqrt then addf(!*multfsqrt(car u,x,cdr u),y)
       else if <<begin scalar v;
                    v:=car u;
                    if car v neq 'expt then return nil;
                    v:=caddr v;
                    if atom v then return nil;
                    return (car v eq 'quotient
                            and numberp cadr v
                            and numberp caddr v)
                 end >>
         then addf(!*multfexpt(car u,x,cdr u),y)
         else addf(multpf(u,x),y);


symbolic procedure !*multfsqrt(x,u,w);
   % This code (Due to Norman a& Davenport) squashes SQRT(...)**2.
   begin scalar v;
     w:=divide(w,2);
     v:=!*q2f simp cadr x;
     u:=!*multf(u,exptf(v,car w));
     if cdr w neq 0 then u:=!*multf(u,!*p2f mksp(x,1));
     return u
   end;


symbolic procedure !*multfexpt(x,u,w);
  begin scalar expon,v;
    expon:=caddr x;
    x:=cadr x;
    w:=w * cadr expon;
    expon:=caddr expon;
    v:=gcdn(w,expon);
    w:=w/v;
    v:=expon/v;
    if not (w > 0) then rerror(int,8,"Invalid exponent")
     else if v = 1
      then return !*multf(u,exptf(if numberp x then x
                                    else if atom x then !*k2f x
                                    else !*q2f if car x eq '!*sq
                                                 then argof x
                                                else simp x,
                          w));
    expon:=0;
    while not (w < v) do <<expon:=expon + 1; w:=w-v>>;
    if expon>0 then u:=!*multf(u,exptf(!*q2f simp x,expon));
    if w = 0 then return u;
    x:=list('expt,x,list('quotient,1,v));
    return multf(squashsqrt u,!*p2f mksp(x,w))   % Cannot be *MULTF.
  end;

symbolic procedure prefix!-rational!-numberp u;
  % Tests for m/n in prefix representation.
    eqcar(u,'quotient) and numberp cadr u and numberp caddr u;

% symbolic procedure squashsqrtsq sq;
%    !*multsq(squashsqrt numr sq ./ 1,1 ./ squashsqrt denr sq);

symbolic procedure squashsqrt sf;
if (not sqrtflag) or atom sf or atom mvar sf
  then sf
  else if car mvar sf eq 'sqrt and ldeg sf > 1
    then addf(squashsqrt red sf,!*multfsqrt(mvar sf,lc sf,ldeg sf))
    else if car mvar sf eq 'expt
       and prefix!-rational!-numberp caddr mvar sf
       and ldeg sf >= caddr caddr mvar sf
      then addf(squashsqrt red sf,!*multfexpt(mvar sf,lc sf,ldeg sf))
      else (if null x then squashsqrt red sf
            else lpow sf .* x .+ squashsqrt red sf)
           where x = squashsqrt lc sf;

%remd 'simpx1;

% The following definition requires frlis!* declared global.

%symbolic procedure simpx1(u,m,n);
%   %u,m and n are prefix expressions;
%   %value is the standard quotient expression for u**(m/n);
%   begin scalar flg,z;
%        if null frlis!* or null intersection(frlis!*,flatten (m . n))
%          then go to a;
%        exptp!* := t;
%        return !*k2q list('expt,u,if n=1 then m
%                                   else list('quotient,m,n));
%    a:  if numberp m and fixp m then go to e
%         else if atom m then go to b
%         else if car m eq 'minus then go to mns
%         else if car m eq 'plus then go to pls
%         else if car m eq 'times and numberp cadr m and fixp cadr m
%                and numberp n
%          then go to tms;
%    b:  z := 1;
%    c:  if atom u and not numberp u then flag(list u,'used!*);
%        u := list('expt,u,if n=1 then m else list('quotient,m,n));
%        if not u member exptl!* then exptl!* := u . exptl!*;
%    d:  return mksq(u,if flg then -z else z); %u is already in lowest
%%       %terms;
%    e:  if numberp n and fixp n then go to int;
%        z := m;
%        m := 1;
%        go to c;
%    mns: m := cadr m;
%        if !*mcd then return invsq simpx1(u,m,n);
%        flg := not flg;
%        go to a;
%    pls: z := 1 ./ 1;
%    pl1: m := cdr m;
%        if null m then return z;
%        z := multsq(simpexpt list(u,
%                        list('quotient,if flg then list('minus,car m)
%                                        else car m,n)),
%                    z);
%        go to pl1;
%    tms: z := gcdn(n,cadr m);
%        n := n/z;
%        z := cadr m/z;
%        m := retimes cddr m;
%        go to c;
%    int:z := divide(m,n);
%        if cdr z<0 then z:= (car z - 1) . (cdr z+n);
%        if 0 = cdr z
%          then return simpexpt list(u,car z);
%        if n = 2
%          then return multsq(simpexpt list(u,car z),
%                             simpsqrti u);
%        return multsq(simpexpt list(u,car z),
%                        mksq(list('expt,u,list('quotient,1,n)),cdr z))
%   end;

symbolic procedure !*exptsq(a,n);
% Raises A to the power N using !*MULTSQ.
    if n=0 then 1 ./ 1
    else if n=1 then a
    else if n<0 then !*exptsq(invsq a,-n)
    else begin
      scalar q,r;
      q:=divide(n,2);
      r:=cdr q; q:=car q;
      q:=!*exptsq(!*multsq(a,a),q);
      if r=0 then return q
      else return !*multsq(a,q)
    end;


symbolic procedure !*exptf(a,n);
% Raises A to the power N using !*MULTF.
    if n=0 then 1
    else if n=1 then a
    else begin
      scalar q,r;
      q:=divide(n,2);
      r:=cdr q; q:=car q;
      q:=!*exptf(!*multf(a,a),q);
      if r=0 then return q
      else return !*multf(a,q)
    end;

endmodule;


module reform; % Reformulate expressions using C-constant substitution.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(!*trint cmap cval loglist ulist);

exports logstosq,substinulist;

imports prepsq,mksp,nth,multsq,addsq,domainp,invsq,plusdf;

symbolic procedure substinulist ulst;
   % Substitutes for the C-constants in the values of the U's given in
   % ULST. Result is a D.F.
   if null ulst then nil
    else begin scalar temp,lcu;
       lcu:=lc ulst;
       temp:=evaluateuconst numr lcu;
       if null numr temp then temp:=nil
        else temp:=((lpow ulst) .*
                   !*multsq(temp,!*invsq(denr lcu ./ 1))) .+ nil;
       return plusdf(temp,substinulist red ulst)
     end;

symbolic procedure evaluateuconst coefft;
% Substitutes for the C-constants into COEFFT (=S.F.). Result is S.Q.;
    if null coefft or domainp coefft then coefft ./ 1
    else begin scalar temp;
      if null(temp:=assoc(mvar coefft,cmap)) then
            temp:=(!*p2f lpow coefft) ./ 1
      else temp:=getv(cval,cdr temp);
      temp:=!*multsq(temp,evaluateuconst(lc coefft));
   % Next line had addsq previously
      return !*addsq(temp,evaluateuconst(red coefft))
    end;

symbolic procedure logstosq;
% Converts LOGLIST to sum of the log terms as a S.Q.;
   begin scalar lglst,logsq,i,temp;
      i:=1;
      lglst:=loglist;
      logsq:=nil ./ 1;
loop: if null lglst then return logsq;
      temp:=cddr car lglst;
%%      if !*trint
%%        then <<printc "SF arg for log etc ="; printc temp>>;
      if not (caar lglst='iden) then <<
          temp:=prepsq temp; %convert to prefix form.
          temp:=list(caar lglst,temp); %function name.
          temp:=((mksp(temp,1) .* 1) .+ nil) ./ 1 >>;
      temp:=!*multsq(temp,getv(cval,i));
      % Next line had addsq previously
      logsq:=!*addsq(temp,logsq);
      lglst:=cdr lglst;
      i:=i+1;
      go to loop
   end;

endmodule;


module simpsqrt;   % Simplify square roots.

% Authors: Mary Ann Moore and Arthur C. Norman.
% Heavily modified by J.H. Davenport for algebraic functions.

fluid '(!*galois !*pvar !*tra !*trint basic!-listofallsqrts
        gaussiani basic!-listofnewsqrts intvar kord!* knowntobeindep
        listofallsqrts listofnewsqrts sqrtflag sqrtlist
        sqrt!-places!-alist varlist zlist);

% This module should be rewritten in terms of the REDUCE function
% SIMPSQRT.

% remd 'simpsqrt;

exports proper!-simpsqrt,simpsqrti,simpsqrtsq,simpsqrt2,sqrtsave,
        newplace,actualsimpsqrt,formsqrt;

symbolic procedure proper!-simpsqrt(exprn);
   simpsqrti carx(exprn,'proper!-simpsqrt);


symbolic procedure simpsqrti sq;
begin
   scalar u;
   if atom sq
     then if numberp sq
       then return (simpsqrt2 sq) ./ 1
       else if (u:=get(sq,'avalue))
         then return simpsqrti cadr u
           % BEWARE!!! This is VERY system dependent.
         else return simpsqrt2((mksp(sq,1) .* 1) .+ nil) ./ 1;
           % If it doesn't have an AVALUE then it is itself.
   if car sq eq 'times
     then return mapply(function multsq,
                        mapcar(cdr sq,function simpsqrti));
   if car sq eq 'quotient
     then return multsq(simpsqrti cadr sq,
                        invsq simpsqrti caddr sq);
   if car sq eq 'expt and numberp caddr sq
     then if evenp caddr sq
       then return simpexpt list(cadr sq,caddr sq / 2)
       else return simpexpt
                     list(mk!*sq simpsqrti cadr sq,caddr sq);
  if car sq = '!*sq
    then return simpsqrtsq cadr sq;
  return simpsqrtsq tidysqrt simp!* sq
  end;


symbolic procedure simpsqrtsq sq;
(simpsqrt2 numr sq) ./ (simpsqrt2 denr sq);


symbolic procedure simpsqrt2 sf;
if minusf sf
  then if sf iequal -1
    then gaussiani
    else begin
      scalar u;
      u:=negf sf;
      if numberp u
        then return multf(gaussiani,simpsqrt3 u);
      % we cannot negate general expressions for the following reason:
%       (%%%thesis remark%%%)
%       sqrt(x*x-1) under x->1/x gives sqrt(1-x*x)/x=i*sqrt(x*x-1)/x
%                 under x->1/x gives x*i*sqrt(-1+1/x*x)=i**2*sqrt(x*x-1)
%       hence an abysmal catastrophe.
      return simpsqrt3 sf
      end
  else simpsqrt3 sf;


symbolic procedure simpsqrt3 sf;
begin
  scalar u;
  u:=assoc(sf,listofallsqrts);
  if u
    then return cdr u;
  % now see if 'knowntobeindep'can help.
  u:=atsoc(listofnewsqrts,knowntobeindep);
  if null u
    then go to no;
  u:=assoc(sf,cdr u);
  if u
    then <<
      listofallsqrts:=u.listofallsqrts;
      return cdr u >>;
no:
  u:=actualsimpsqrt sf;
  listofallsqrts:=(sf.u).listofallsqrts;
  return u
  end;


symbolic procedure sqrtsave(u,v,place);
begin
  scalar a;
  %u is new value of listofallsqrts, v of new.
  a:=assoc(place,sqrt!-places!-alist);
  if null a
    then sqrt!-places!-alist:=(place.(listofnewsqrts.listofallsqrts))
           .sqrt!-places!-alist
    else rplacd(a,listofnewsqrts.listofallsqrts);
      listofnewsqrts:=v;
      % throw away things we are not going to need in future.
      if not !*galois
        then listofallsqrts:=u;
        % we cannot guarantee the validity of our calculations.
      if listofallsqrts eq u
        then return nil;
      v:=listofallsqrts;
      while not (cdr v eq u) do
        v:=cdr v;
      rplacd(v,nil);
      % listofallsqrts is all those added since routine was entered.
      v:=atsoc(listofnewsqrts,knowntobeindep);
      if null v
        then knowntobeindep:=(listofnewsqrts.listofallsqrts)
                              . knowntobeindep
        else rplacd(v,union(cdr v,listofallsqrts));
      listofallsqrts:=u;
      return nil
  end;


symbolic procedure newplace(u);
% Says to restart algebraic bases at a new place u.
begin
  scalar v;
  v:=assoc(u,sqrt!-places!-alist);
  if null v
    then <<
      listofallsqrts:=basic!-listofallsqrts;
      listofnewsqrts:=basic!-listofnewsqrts >>
    else <<
      v:=cdr v;
      listofnewsqrts:=car v;
      listofallsqrts:=cdr v >>;
  return if v then v
              else listofnewsqrts.listofallsqrts
  end;


symbolic procedure mknewsqrt u;
% U is prefix form.
begin
  scalar v,w;
  if not !*galois then go to new;
    % no checking required.
  v:=addf(!*p2f mksp(!*pvar,2),negf !*q2f tidysqrt simp u);
  w:=errorset!*(list('afactor,mkquote v,mkquote !*pvar),t);
  if atom w
    then go to new
    else w:=car w; %the actual result of afactor.
  if cdr w
    then go to notnew;
new:
% w:=sqrtify u;
  w := mksqrt u;
  listofnewsqrts:=w . listofnewsqrts;
  return !*kk2f w;
notnew:
  w:=car w;
  v:=stt(w,!*pvar);
  if car v neq 1 then errach list("Error in mknewsqrt: ",v);
  w:=addf(w,multf(cdr v,(mksp(!*pvar,car v) .* -1) .+nil));
  w:=sqrt2top(w ./ cdr v);
  w:=quotf(numr w,denr w);
  if null w then errach list("Division failurein mknewsqrt",u);
  return w
  end;


symbolic procedure actualsimpsqrt(sf);
if sf iequal -1
  then gaussiani
  else actualsqrtinner(sf,listofnewsqrts);


symbolic procedure actualsqrtinner(sf,l);
   if sf =1 then 1
    else if null l
       or domainp sf or ldeg sf=1
   % Patch by A.C. Norman to prevent recursion errors.
     then actualsimpsqrt2 sf
    else begin scalar z;
       if numberp sf and (z := list('sqrt,sf)) member l
         then return !*kk2f z;
       z := argof car l;
       if z member l then z := !*kk2f car l else z := !*q2f simp z;
       if z = -1 then return actualsqrtinner(sf,cdr l);
       z:=quotf(sf,z);
       if null z then return actualsqrtinner(sf,cdr l)
        else return !*multf(!*kk2f car l,actualsimpsqrt z)
     end;


symbolic procedure actualsimpsqrt2(sf);
 if atom sf
   then if null sf
     then nil
     else if numberp sf
       then if sf < 0
         then multf(gaussiani,actualsimpsqrt2(- sf))
           %Above 2 lines inserted JHD 4 Sept 80;
           % test case: SQRT(B*X**2-C)/SQRT(X);
         else begin
           scalar n;
           n:=int!-sqrt sf;
           % Changed for conformity with DEC20 LISP JHD July 1982;
           if not fixp n
             then return mknewsqrt sf
             else return n
           end
     else mknewsqrt(sf)
   else begin
     scalar form;
     form:=comfac sf;
     if car form
       then return multf((if null cdr sf and (car sf = form)
                            then formsqrt(form .+ nil)
                            else simpsqrt2(form .+ nil)),
                            %The above 2 lines changed by JHD;
                            %(following suggestions of Morrison);
                            %to conform to Standard LISP 4 Sept 80;
                         simpsqrt2 quotf(sf,form .+ nil));
     % we have killed common powers.
     form:=cdr form;
     if form neq 1
       then return multf(simpsqrt2 form,
                          simpsqrt2 quotf(sf,form));
     % remove a common factor from the sf.
     return formsqrt sf
     end;


symbolic procedure int!-sqrt n;
   % Return sqrt of n if same is exact, or something non-numeric
   % otherwise.
    if not numberp n then 'nonnumeric
    else if n<0 then 'negative
    else if floatp n then sqrt n
    else if n<2 then n
    else int!-nr(n,(n+1)/2);


symbolic procedure int!-nr(n,root);
% root is an overestimate here. nr moves downwards to root;
 begin
    scalar w;
    w:=root*root;
    if n=w then return root;
    w:=(root+n/root)/2;
    if w>=root then return !*q2f simpsqrt list n;
    return int!-nr(n,w)
 end;


 symbolic procedure formsqrt(sf);
 if (null red sf)
   then if (lc sf iequal 1) and (ldeg sf iequal 1)
     then mknewsqrt mvar sf
     else multf(if evenp ldeg sf
                  then !*p2f mksp(mvar sf,ldeg sf / 2)
                  else exptf(mknewsqrt mvar sf,ldeg sf),simpsqrt2 lc sf)
   else begin
     scalar varlist,zlist,sqrtlist,sqrtflag;
     scalar v,l,n,w;
     % This returns a list, the i-th member of which is
%      a list of the factors of multiplicity i (as s.f's);
     v:=jsqfree(sf,if intvar and involvesf(sf,intvar) then intvar
                     else findatom mvar sf);
                     % intvar is the best thing to do square-free
                     % decompositions with respect to, but anything
                     % else will do if intvar is not set.
     if null cdr v and null cdar v then return mknewsqrt prepf sf;
       % The JSQFREE did nothing.
     l:=nil;
     n:=0;
     while v do <<
       n:=n+1;
       w:=car v;
       while w do <<
         l:=list('expt,mk!*sq !*f2q car w,n) . l;
         w:=cdr w >>;
       v:=cdr v >>;
     if null cdr l
       then l:=car l
       else l:='times.l;
       % makes L into a valid prefix form;
     return !*q2f simpsqrti l
     end;


symbolic procedure findatom pf;
if atom pf
  then pf
  else findatom argof pf;

flag('(sqrtify),'lose);   % No longer used.

symbolic procedure sqrtify u;
% Actually creates the sqrt.
begin
  scalar v,n,prinlist;
  n:=degreenest(u,nil);
% v:=list('sqrt,u);
  v := mksqrt u;   % To ensure sqrt**2 rule set.
  prinlist:=member(v,kord!*);
  if prinlist then return car prinlist;
  % This might improve sharing.
  % anyway, we mustn't re-add this object to KORD!*;
  while kord!* and
        eqcar(car kord!*,'sqrt) and
        (degreenest(argof car kord!*,nil) > n) do <<
    prinlist:=(car kord!*) . prinlist;
    kord!*:=cdr kord!* >>;
  kord!*:=v . kord!*;
  while prinlist do <<
    kord!*:=(car prinlist) . kord!*;
    prinlist:=cdr prinlist >>;
  return v
  end;


% deflist ('((sqrt (((x) quotient (sqrt x) (times 2 x))))),'dfn);

% put('sqrt,'simpfn,'proper!-simpsqrt); % Now in driver.

endmodule;


module hacksqrt;  % Routines for manipulation of sqrt expressions.

% Author: James H. Davenport.

fluid '(nestedsqrts thisplace);

exports sqrtsintree,sqrtsinsq,sqrtsinsql,sqrtsinsf,sqrtsign;
exports degreenest,sortsqrts;

imports mkvect,interr,getv,dependsp,union;

symbolic procedure sqrtsintree(u,var,slist);
% Adds to slist all the sqrts in the prefix-type tree u.
if atom u
  then slist
  else if car u eq '!*sq
    then union(slist,sqrtsinsq(cadr u,var))
    else if car u eq 'sqrt
      then if dependsp(argof u,var)
        then <<
          slist:=sqrtsintree(argof u,var,slist);
          %  nested square roots
          if member(u,slist)
            then slist
            else u.slist >>
        else slist
      else sqrtsintree(car u,var,sqrtsintree(cdr u,var,slist));


symbolic procedure sqrtsinsq(u,var);
   % Returns list of all sqrts in sq.
   sqrtsinsf(denr u,sqrtsinsf(numr u,nil,var),var);


symbolic procedure sqrtsinsql(u,var);
% Returns list of all sqrts in sq list.
if null u
  then nil
  else sqrtsinsf(denr car u,
      sqrtsinsf(numr car u,sqrtsinsql(cdr u,var),var),var);


symbolic procedure sqrtsinsf(u,slist,var);
% Adds to slist all the sqrts in sf.
if domainp u or null u
  then slist
  else <<
    if  eqcar(mvar u,'sqrt) and
        dependsp(argof mvar u,var) and
        not member(mvar u,slist)
      then begin
        scalar slist2;
        slist2:=sqrtsintree(argof mvar u,var,nil);
        if slist2
          then <<
            nestedsqrts:=t;
            slist:=union(slist2,slist) >>;
        slist:=(mvar u).slist
        end;
    sqrtsinsf(lc u,sqrtsinsf(red u,slist,var),var) >>;


symbolic procedure easysqrtsign(slist,things);
% This procedure builds a list of all substitutions for all possible
% combinations of square roots in list.
if null slist
  then things
  else easysqrtsign(cdr slist,
                    nconc(mapcons(things,(car slist).(car slist)),
                          mapcons(things,
                                  list(car slist,'minus,car slist))));

symbolic procedure hardsqrtsign(slist,things);
% This procedure fulfils the same role for nested sqrts
% ***assumption: the simpler sqrts come further up the list.
if null slist
  then things
  else begin
    scalar thisplace,answers,pos,neg;
    thisplace:=car slist;
    answers:=mapcar(things,function (lambda u;sublis(u,thisplace).u));
    pos:=mapcar(answers,function (lambda u;(thisplace.car u).(cdr u)));
    % pos is sqrt(f) -> sqrt(innersubst f)
    neg:=mapcar(answers,
        function (lambda u;list(thisplace,'minus,car u).(cdr u)));
    % neg is sqrt(f) -> -sqrt(innersubst f)
    return hardsqrtsign(cdr slist,nconc(pos,neg))
    end;


symbolic procedure degreenest(pf,var);
% Returns the maximum degree of nesting of var
% inside sqrts in the prefix form pf.
if atom pf
  then 0
  else if car pf eq 'sqrt
    then if dependsp(cadr pf,var)
      then iadd1 degreenest(cadr pf,var)
      else 0
    else if car pf eq 'expt
      then if dependsp(cadr pf,var)
        then if eqcar(caddr pf,'quotient)
          then iadd1 degreenest(cadr pf,var)
          else degreenest(cadr pf,var)
        else 0
      else degreenestl(cdr pf,var);

symbolic procedure degreenestl(u,var);
%Returns max degreenest from list of pfs u.
if null u
  then 0
  else max(degreenest(car u,var),
           degreenestl(cdr u,var));


symbolic procedure sortsqrts(u,var);
% Sorts list of sqrts into order required by hardsqrtsign
% (and many other parts of the package).
begin
  scalar i,v;
  v:=mkvect(10); %should be good enough!
  while u do <<
    i:=degreenest(car u,var);
    if i iequal 0
      then interr "Non-dependent sqrt found";
    if i > 10
      then interr
         "Degree of nesting exceeds 10 (recompile with 10 increased)";
    putv(v,i,(car u).getv(v,i));
    u:=cdr u >>;
  u:=getv(v,10);
  for i :=9 step -1 until 1 do
    u:=nconc(getv(v,i),u);
  return u
  end;


symbolic procedure sqrtsign(sqrts,x);
   if nestedsqrts then hardsqrtsign(sortsqrts(sqrts,x),list nil)
    else easysqrtsign(sqrts,list nil);

endmodule;


module sqrtf;   % Square root of standard forms.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(!*noextend zlist);

exports nrootn,domainp,minusf;  % minusdfp,sqrtdf

imports contentsmv,gcdf,interr,!*multf,partialdiff,printdf,quotf,
   simpsqrt2,vp2;

% symbolic procedure minusdfp a;
%   % Test sign of leading coedd of d.f.
%     if null a then interr "Minusdfp 0 illegal"
%     else minusf numr lc a;

% symbolic procedure sqrtdf l;
%    % Takes square root of distributive form. "Failed" usually means
%    % that the square root is not among already existing objects.
%     if null l then nil
%     else begin scalar c;
%         if lpow l=vp2 zlist then go to ok;
%         c:=sqrtsq df2q l;
%         if numr c eq 'failed
%           then return 'failed;
%         if denr c eq 'failed
%           then return 'failed;
%         return for each u in f2df numr c
%                  collect (car u).!*multsq(cdr u,1 ./ denr c);
%     ok: c:=sqrtsq lc l;
%         if  numr c eq 'failed or
%             denr c eq 'failed
%           then return 'failed
%           else return (lpow l .* c) .+nil
%     end;

% symbolic procedure sqrtsq a;
%     sqrtf numr a ./ sqrtf denr a;

symbolic procedure sqrtf p;
    begin       scalar ip,qp;
        if null p then return nil;
        ip:=sqrtf1 p;
        qp:=cdr ip;
        ip:=car ip; %respectable and nasty parts of the sqrt.
        if qp=1 then return ip; %exact root found.
         if !*noextend then return 'failed;
            % We cannot add new square roots in this case, since it is
            % then impossible to determine if one square root depends
            % on another if new ones are being added all the time.
         if zlistp qp then return 'failed;
            % Liouville's theorem tells you that you never need to add
            % new algebraics depending on the variable of integration.
        qp:=simpsqrt2 qp;
        return !*multf(ip,qp)
    end;

symbolic procedure zlistp qp;
if atom qp then member(qp,zlist)
  else or(member(mvar qp,zlist),zlistp lc qp,zlistp red qp);

symbolic procedure sqrtf1 p;
  % Returns a . b with p=a**2*b.
    if domainp p
     then if fixp p then nrootn(p,2)
           else !*q2f simpsqrt list prepf p . 1
    else begin scalar co,pp,g,pg;
        co:=contentsmv(p,mvar p,nil); %contents of p.
        pp:=quotf(p,co); %primitive part.
        co:=sqrtf1(co); %process contents via recursion.
        g:=gcdf(pp,partialdiff(pp,mvar pp));
        pg:=quotf(pp,g);
        g:=gcdf(g,pg); %a repeated factor of pp.
        if g=1 then pg:=1 . pp
        else <<
            pg:= quotf(pp,!*multf(g,g)); %what is still left.
            pg:=sqrtf1(pg); %split that up.
            rplaca(pg,!*multf(car pg,g))>>;
                 %put in the thing found here.
        rplaca(pg, !*multf(car pg,car co));
        rplacd(pg, !*multf(cdr pg,cdr co));
        return pg
    end;

% NROOTN removed as in REDUCE base.

endmodule;


module isolve;   % Routines for solving the final reduction equation.

% Author: Mary Ann Moore and Arthur C. Norman.
% Modifications by: John P. Fitch.

fluid '(!*trint
        badpart
        ccount
        cmap
        cmatrix
        cval
        indexlist
        lhs!*
        lorder
        orderofelim
        power!-list!*
        pt
        rhs!*
        sillieslist
        tanlist
        ulist
        zlist);

global '(!*number!* !*statistics);

exports solve!-for!-u;

imports nth,findpivot,gcdf,int!-gensym1,mkvect,interr,multdfconst,
   !*multf!*,negdf,orddf,plusdf,printdf,printsf,printspreadc,printsq,
   quotf,putv,spreadc,subst4eliminatedcs,mknill,pnth,domainp,addf,
   invsq,multsq;

symbolic procedure uterm(powu,rhs!*);
% Finds the contribution from RHS!* of reduction equation, of the
% U-coefficient given by POWU. Result is in D.F.
   if null rhs!* then nil
   else begin    scalar coef,power;
      power:=addinds(powu,lpow rhs!*);
      coef:=evaluatecoeffts(numr lc rhs!*,powu);
      if null coef then return uterm(powu,red rhs!*);
      coef:=coef ./ denr lc rhs!*;
      return plusdf((power .* coef) .+ nil,uterm(powu,red rhs!*))
   end;

symbolic procedure solve!-for!-u(rhs!*,lhs!*,ulist);
% Solves the reduction eqn LHS!*=RHS!*. Returns list of U-coefficients
% and their values (ULIST are those we have so far), and a list of
% C-equations to be solved (CLIST are the eqns we have so far).
begin
top:
   if null lhs!* then return ulist
   else begin    scalar u,lpowlhs;
      lpowlhs:=lpow lhs!*;
      begin scalar ll,m1,chge; ll:=maxorder(power!-list!*,zlist,0);
        m1:=lorder;
        while m1 do << if car ll < car m1 then
                << chge:=t; rplaca(m1,car ll) >>;
            ll:=cdr ll; m1:=cdr m1 >>;
        if !*trint and chge then <<
           princ
           "Maximum order for undetermined coefficients is reduced to ";
           printc lorder >>
      end;
      u:=pickupu(rhs!*,lpow lhs!*,t);
      if null u then
      << if !*trint then <<
             printc "***** Equation for a constant to be solved:";
             printsf numr lc lhs!*;
             printc "    = 0";
             printc " ">>;
          % Remove a zero constant from the lhs, rather than use
          % Gauss Elim;
        if gausselimn(numr lc lhs!*,lt lhs!*) then <<
                 lhs!*:=squashconstants(red lhs!*); u := t >>
        else lhs!*:=red lhs!* >>
      else
      << ulist:=(car u .
           !*multsq(coefdf(lhs!*,lpowlhs),invsq cdr u)).ulist;
                % used to be subs2q multsq
        if !*statistics then !*number!*:=!*number!*+1;
         if !*trint then <<
                printc "A coefficient of numerator has been determined";
                prin2 "***** U"; prin2 car u; prin2t " =";
                printsq multsq(coefdf(lhs!*,lpowlhs),invsq cdr u);
                printc " ">>;
         lhs!*:=plusdf(lhs!*,
                negdf multdfconst(cdar ulist,uterm(car u,rhs!*))) >>;
      if !*trint and u then << printc "Terms remaining are:";
          printdf lhs!*;
          printc " ">>;
   end;
   go to top
end;

symbolic procedure squashconstants(express);
begin scalar constlst,ii,xp,cl,subby,cmt,xx;
        constlst:=reverse cmap;
        cmt:=cmatrix;
xxx:    xx:=car cmt;            % Look at next row of Cmatrix
        cl:=constlst;           % and list of the names.
        ii:=1;                  % will become index of removed constant.
        while not getv(xx,ii) do
                << ii:=ii+1; cl:=cdr cl >>;
        subby:=caar cl;         %II is now index, and SUBBY the name.
        if member(subby,sillieslist) then
                <<cmt:=cdr cmt; go to xxx>>; %This loop must terminate.
                        % This is because at least one constant remains.
        xp:=prepsq !*f2q getv(xx,0);    % start to build up the answer.
        cl:=cdr cl;
        if not (ccount=ii) then for jj:=ii+1:ccount do <<
                if getv(xx,jj) then
                        xp:=list('plus,xp,
                                list('times,caar cl,
                                        prepsq !*f2q getv(xx,jj)));
                cl:=cdr cl >>;
        xp:=list('quotient,list('minus,xp),
                        prepsq !*f2q getv(xx,ii));
        if !*trint then <<
                prin2 "Replace constant "; prin2 subby;
                prin2 " by "; printsq simp xp >>;
        sillieslist:=subby . sillieslist;
        return subdf(express,xp,subby)
end;

symbolic procedure checku(ulst,u);
   % Checks that U is not already in ULST - ie. that this u-coeff
   % has not already been given a value.
   ulst and (car u = caar ulst or checku(cdr ulst,u));

symbolic procedure checku1(powu,rhs!*);
% Checks that use of a particular U-term will not cause trouble
% by introducing negative exponents into lhs when it is used.
    begin
    top:
        if null rhs!* then return nil;
        if negind(powu,lpow rhs!*) then
          if not null evaluatecoeffts(numr lc rhs!*,powu) then return t;
        rhs!*:=red rhs!*;
        go to top
    end;

symbolic procedure negind(pu,pr);
% Check if substituting index values in power gives rise to -ve
% exponents.
    pu and ((car pu+caar pr)<0 or negind(cdr pu,cdr pr));

symbolic procedure evaluatecoeffts(coefft,indlist);
% Substitutes the values of the i,j,k,...'s that appear in the S.F.
% COEFFT (=coefficient of r.h.s. of reduction equation). Result is S.F.
   if null coefft or domainp coefft then
      if coefft=0 then nil else coefft
   else begin    scalar temp;
      if mvar coefft member indexlist then
         temp:=valuecoefft(mvar coefft,indlist,indexlist)
      else temp:=!*p2f lpow coefft;
      temp:=!*multf(temp,evaluatecoeffts(lc coefft,indlist));
      return addf(temp,evaluatecoeffts(red coefft,indlist))
   end;

symbolic procedure valuecoefft(var,indvalues,indlist);
% Finds the value of VAR, which should be in INDLIST, given INDVALUES,
% the corresponding values of INDLIST variables.
   if null indlist then interr "Valuecoefft - no value"
   else if var eq car indlist then
      if car indvalues=0 then nil
      else car indvalues
   else valuecoefft(var,cdr indvalues,cdr indlist);

symbolic procedure addinds(powu,powrhs);
% Adds indices in POWU to those in POWRHS. Result is LPOW of D.F.
   if null powu then if null powrhs then nil
      else interr "Powrhs too long"
   else if null powrhs then interr "Powu too long"
   else (car powu + caar powrhs).addinds(cdr powu,cdr powrhs);


symbolic procedure pickupu(rhs!*,powlhs,flg);
% Picks up the 'lowest' U coefficient from RHS!* if it exists and
% returns it in the form of LT of D.F..
% Returns NIL if no legal term in RHS!* can be found.
% POWLHS is the power we want to match (LPOW of D.F).
% and COEFFU is the list of previous coefficients that must be zero.
 begin scalar coeffu,u;
    pt:=rhs!*;
top:
    if null pt then return nil; %no term found - failed.
    u:=nextu(lt pt,powlhs); %check this term...
    if null u then go to notthisone;
    if not testord(car u,lorder) then go to neverthisone;
    if not checkcoeffts(coeffu,car u) then go to notthisone;
    %that inhibited clobbering things already passed over.
    if checku(ulist,u) then go to notthisone;
    %that avoided redefining a u value.
    if checku1(car u,rhs!*) then go to neverthisone;
    %avoid introduction of negative exponents.
    if flg then
        u:=patchuptan(list u,powlhs,red pt,rhs!*);
    return u;
neverthisone:
    coeffu:=(lc pt) . coeffu;
notthisone:
    pt:=red pt;
    go to top
 end;

symbolic procedure patchuptan(u,powlhs,rpt,rhs!*);
        begin
            scalar uu,cc,dd,tanlist,redu,redu1,mesgiven,needsquash;
            pt:=rpt;
            while pt do <<
                if (uu:=pickupu(pt,powlhs,nil))
                        and testord(car uu,lorder) then <<
                                % Nasty found, patch it up.
                    cc:=(int!-gensym1 'c . caar u) . cc;
                                % CC is an alist of constants.
                    if !*trint then <<
                        if not mesgiven then << %% Changed by JPff
                          prin2t
                         "*** Introduce new constants for coefficients";
                          mesgiven := t >>;
                        prin2 "***** U";
                        prin2 caar u;
                        prin2t " =";
                        print caar cc >>;
                    redu:=plusdf(redu,
                        multdfconst(!*k2q caar cc,uterm(caar u,rhs!*)));
                    u:=uu.u
                >>;
                if pt then pt:=red pt >>;
            redu1:=redu;
            while redu1 do begin scalar xx; xx:=car redu1;
                if !*trint
                  then << prin2 "Introduced terms: ";
                          prin2 car xx; princ "*(";
                          printsq cdr xx; printc ")">>;
                if (not testord(car xx,lorder)) then <<
                    if !*trint then printc "  =  0";
                    if dd:=killsingles(cadr xx,cc) then <<
                        redu:=subdf(redu,0,car dd);
                        redu1:=subdf(redu1,0,car dd);
                        ulist:=((cdr dd).(nil ./ 1)).ulist;
                        u:=rmve(u,cdr dd);
                        cc:=purgeconst(cc,dd) >>
                    else <<
                        needsquash := t;
                        redu1 :=cdr redu1
                    >>
                >>
                else redu1:=cdr redu1  end;
            for each xx in redu do <<
                if (not testord(car xx,lorder)) then <<
                    while cc do <<
                                addctomap(caar cc);
                                ulist:=((cdar cc).(!*k2q caar cc))
                                          . ulist;
                                if !*statistics
                                  then !*number!*:=!*number!*+1;
                                cc:=cdr cc >>;
                        gausselimn(numr lc redu,lt redu)>> >>;
            if redu then << while cc do << addctomap(caar cc);
                        ulist:=((cdar cc).(!*k2q caar cc)).ulist;
                        if !*statistics then !*number!*:=!*number!*+1;
                        cc:=cdr cc >>;
                lhs!*:=plusdf(lhs!*,negdf redu);
                if needsquash then lhs!*:=squashconstants(lhs!*) >>;
        return car u
end;

symbolic procedure killsingles(xx,cc);
  if atom xx then nil
  else if not (cdr xx eq nil) then nil
  else begin scalar dd;
    dd:=assoc(caaar xx,cc);
    if dd then return dd;
    return killsingles(cdar xx,cc)
end;

symbolic procedure rmve(l,x);
   if caar l=x then cdr l else cons(car l,rmve(cdr l,x));

symbolic procedure subdf(a,b,c);
% Substitute b for c into the df a. Used to get rid of silly constants
% introduced.
if a=nil then nil else
  begin scalar x;
    x:=subs2q subf(numr lc a,list (c . b)) ;
    if x=(nil . 1) then return subdf(red a,b,c)
        else return plusdf(
                list ((lpow a).((car x).!*multf(cdr x,denr lc a))),
                subdf(red a,b,c))
end;

symbolic procedure testord(a,b);
% Test order of two DF's in recursive fashion.
  if null a then t
    else if car a leq car b then testord(cdr a,cdr b)
    else nil;

symbolic procedure tansfrom(rhs,z,indexlist,n);
% We notice that in all bad cases we have (j-num)tan**j...;
% Extract the num to get list of all maxima;
if null z then nil else
begin scalar zz,r, rr, ans;
    r:=rhs;
    zz := car z;
    ans := 0;
    if not(atom zz) and car zz = 'tan then
      while  r do <<
        rr:=caar r;  % The list of powers;
        for i:=1:n do rr:=cdr rr;
        if fixp caar rr then
                ans := max(ans,tanextract(car indexlist,prepsq cdar r));
        r:=cdr r;
      >>;
    return cons(ans,tansfrom(rhs, cdr z,cdr indexlist,n+1))
end;

symbolic procedure tanextract(var, exp);
% Find the value of the variable which makes the expression vanish.
% The coefficients must be linear.
begin scalar ans, c0, c1;
  ans := cdr coeff1(exp,var,nil);
  if length ans = 2 and
     not(car ans = 0) then <<
        c0 := car ans; c1 := cadr ans;
        if eqcar(c0,'!*sq) then c0 := cadr c0 else c0 := c0 ./ 1;
        if eqcar(c1,'!*sq) then c1 := cadr c1 else c1 := c1 ./ 1;
        ans := multsq(c0, invsq c1);
        if atom ans then return 0;
        if (cdr ans = 1) and fixp (car ans) then return -(car ans);
        return 0 >>;
  return 0;
end;

symbolic procedure coefdf(y,u);
  if y=nil then nil
  else if lpow y=u then lc y
  else coefdf(red y,u);


symbolic procedure purgeconst(a,b);
% Remove a constant from and expression. May be the same as DELETE?
  if null a then nil
  else if car a=b then purgeconst(cdr a,b)
  else cons(car a,purgeconst(cdr a,b));

symbolic procedure maxorder(minpowers,z,n);
% Find a limit on the order of terms, this is ad hoc;
  if null z then nil
    else if eqcar(car z,'sqrt) then
        cons(1,maxorder(cdr minpowers,cdr z,n+1))
    else if (atom car z) or (caar z neq 'tan) then
        cons(maxfrom(lhs!*,n)+1,maxorder(cdr minpowers,cdr z,n+1))
    else cons(max(car minpowers, maxfrom(lhs!*,n)),
              maxorder(cdr minpowers,cdr z,n+1));

symbolic procedure maxfrom(l,n); maxfrom1(l,n+1,0);

symbolic procedure maxfrom1(l,n,v);
   % Largest order in the nth variable.
   if null l then v
    else <<v := max(nth(caar l,n),v); maxfrom1(cdr l,n,v)>>;

symbolic procedure addctomap cc;
begin
    scalar ncval;
    ccount:=ccount+1;
    ncval:=mkvect(ccount);
    for i:=0:(ccount-1) do putv(ncval,i,getv(cval,i));
    putv(ncval,ccount,nil ./ 1);
    cval:=ncval;
    cmap:=(cc . ccount).cmap;
    if !*trint then << prin2 "Constant map changed to "; print cmap >>;
    cmatrix:=mapcar(cmatrix,function addtovector);
end;

symbolic procedure addtovector v;
    begin scalar vv;
        vv:=mkvect(ccount);
        for i:=0:(ccount-1) do putv(vv,i,getv(v,i));
        putv(vv,ccount,nil);
        return vv
    end;

symbolic procedure checkcoeffts(cl,indv);
% checks to see that the coefficients in CL (coefficient list - S.Q.s)
% are zero when the i,j,k,... are given values in INDV (LPOW of
% D.F.). if so the result is true else NIL=false.
    if null cl then t
    else begin    scalar res;
        res:=evaluatecoeffts(numr car cl,indv);
        if not(null res or res=0) then return nil
        else return checkcoeffts(cdr cl,indv)
    end;

symbolic procedure nextu(ltrhs,powlhs);
% picks out the appropriate U coefficients for term: LTRHS to match the
% powers of the z-variables given in POWLHS (= exponent list of D.F.).
% return this coefficient in form LT of D.F. If U coefficient does
% not exist then result is NIL. If it is multiplied by a zero then
% result is NIL.
   if null ltrhs then nil
   else begin    scalar indlist,ucoefft;
      indlist:=subtractinds(powlhs,car ltrhs,nil);
      if null indlist then return nil;
      ucoefft:=evaluatecoeffts(numr cdr ltrhs,indlist);
      if null ucoefft or ucoefft=0 then return nil;
      return indlist .* (ucoefft ./ denr cdr ltrhs)
   end;

symbolic procedure subtractinds(powlhs,l,sofar);
% subtract the indices in list L from those in POWLHS to find
% appropriate values for i,j,k,... when equating coefficients of terms
% on lhs of reduction eqn. SOFAR is the resulting value list we have
% constructed so far. if any i,j,k,... value is -ve then result is NIL.
    if null l then reversip sofar
    else if ((car powlhs)-(caar l))<0 then nil
    else subtractinds(cdr powlhs,cdr l,
        ((car powlhs)-(caar l)) . sofar);

symbolic procedure gausselimn(equation,tokill);
% Performs Gaussian elimination on the matrix for the c-equations
% as each c-equation is found. EQUATION is the next one to deal with.
   begin         scalar newrow,pivot;
      if ccount=0 then go to noway; % failure.
      newrow:=mkvect(ccount);
      spreadc(equation,newrow,1);
      subst4eliminatedcs(newrow,reverse orderofelim,reverse cmatrix);
      pivot:=findpivot newrow;
      if null pivot then go to nopivotfound;
      orderofelim:=pivot . orderofelim;
      newrow:=makeprim newrow; % remove hcf from new equation.
      cmatrix:=newrow . cmatrix;
%      if !*trint then printspreadc newrow;
      return t;
 nopivotfound:
      if null getv(newrow,0) then <<
        if !*trint then printc "This equation adds no new information";
        return nil>>; % equation was 0=0.
 noway:
      badpart:=tokill . badpart; % non-integrable term.
      if !*trint then
        <<printc "Inconsistency in equations for constants,";
          printc "  so non integrable">>;
      return nil
   end;

symbolic procedure makeprim row;
    begin scalar g;
        g:=getv(row,0);
        for i:=1:ccount do g:=gcdf(g,getv(row,i));
        if g neq 1 then
           for i:=0:ccount do putv(row,i,quotf(getv(row,i),g));
        for i := 0:ccount do
          <<g := getv(row,i);
            if g and not domainp g
              then putv(row,i,numr resimp((rootextractf g) ./ 1))>>;
        return row
    end;

endmodule;


module tidysqrt;  % General tidying up of square roots.

% Authors: Mary Ann Moore and Arthur C. Norman.
% Modifications by J.H. Davenport.

exports sqrt2top,tidysqrt;

%symbolic procedure tidysqrtdf a;
%    if null a then nil
%    else begin    scalar tt,r;
%        tt:=tidysqrt lc a;
%        r:=tidysqrtdf red a;
%        if null numr tt then return r;
%        return ((lpow a) .* tt) .+ r
%    end;
%
symbolic procedure tidysqrt q;
    begin    scalar n1,dd;
        n1:=tidysqrtf numr q;
        if null n1 then return nil ./ 1; %answer is zero.
        dd:=tidysqrtf denr q;
        return multsq(n1,invsq dd)
    end;

symbolic procedure tidysqrtf p;
%Input - standard form.
%Output - standard quotient.
%Simplifies sqrt(a)**n with n>1.
    if domainp p then p ./ 1
    else begin    scalar v,w;
        v:=lpow p;
        if car v='i then v:=mksp('(sqrt -1),cdr v); %I->sqrt(-1);
        if eqcar(car v,'sqrt) and not onep cdr v
          then begin    scalar x;
             %here we have a reduction to apply.
            x:=divide(cdr v,2); %halve exponent.
            w:=exptsq(simp cadar v,car x); %rational part of answer.
            if cdr x neq 0
              then w := multsq(w,((mksp(car v,1) .* 1) .+ nil) ./ 1);
            %the next line allows for the horrors of nested sqrts.
            w:=tidysqrt w
            end
        else w:=((v .* 1) .+ nil) ./ 1;
        v:=multsq(w,tidysqrtf lc p);
        return addsq(v,tidysqrtf red p)
    end;


symbolic procedure multoutdenr q;
  % Move sqrts in a sq to the numerator.
    begin  scalar n,d,root,conj;
        n:=numr q;
        d:=denr q;
        while (root:=findsquareroot d) do <<
          conj:=conjugatewrt(d,root);
          n:=!*multf(n,conj);
          d:=!*multf(d,conj) >>;
        while (root:=findnthroot d) do <<
          conj:=conjugateexpt(d,root,kord!*);
          n:=!*multf(n,conj);
          d:=!*multf(d,conj) >>;
        return (n . d);
        end;

symbolic procedure conjugateexpt(d,root,kord!*);
  begin scalar ord,ans,repl,xi;
  ord:=caddr caddr root; % the denominator of the exponent;
  ans:=1;
  kord!*:= (xi:=gensym()) . kord!*;
  % XI is an ORD'th root of unity;
  for i:=1:ord-1 do <<
    ans:=!*multf(ans,numr subf(d,
                   list(root . list('times,root,list('explt,xi,i)))));
    while (mvar ans eq xi) and ldeg ans > ord do
      ans:=addf(red ans,(xi) to (ldeg ans - ord) .* lc ans .+ nil);
    if (mvar ans eq xi) and ldeg ans = ord then
      ans:=addf(red ans,lc ans) >>;
  if (mvar ans eq xi) and ldeg ans = ord-1 then <<
    repl:=-1;
    for i:=1:ord-2 do
      repl:=(xi) to i .* -1 .+ repl;
    ans:=addf(red ans,!*multf(lc ans,repl)) >>;
  if not domainp ans and mvar ans eq xi
    then interr "Conjugation failure";
  return ans;
  end;

symbolic procedure sqrt2top q;
begin
  scalar n,d;
  n:=multoutdenr q;
  d:=denr n;
  n:=numr n;
  if d eq denr q
    then return q;%no change.
  if d iequal 1
    then return (n ./ 1);
  q:=gcdcoeffsofsqrts n;
  if q iequal 1
    then if minusf d
      then return (negf n ./ negf d)
      else return (n ./ d);
  q:=gcdf(q,d);
  n:=quotf(n,q);
  d:=quotf(d,q);
  if minusf d
    then return (negf n ./ negf d)
    else return (n ./ d)
    end;

%symbolic procedure denrsqrt2top q;
%begin
%  scalar n,d;
%  n:=multoutdenr q;
%  d:=denr n;
%  n:=numr n;
%  if d eq denr q
%    then return d; % no changes;
%  if d iequal 1
%    then return 1;
%  q:=gcdcoeffsofsqrts n;
%  if q iequal 1
%    then return d;
%  q:=gcdf(q,d);
%  if q iequal 1
%    then return d
%    else return quotf(d,q)
%  end;

symbolic procedure findsquareroot p;
  % Locate a sqrt symbol in poly p.
    if domainp p then nil
    else begin scalar w;
        w:=mvar p; %check main var first.
        if atom w
          then return nil; %we have passed all sqrts.
        if eqcar(w,'sqrt) then return w;
        w:=findsquareroot lc p;
        if null w then w:=findsquareroot red p;
        return w
    end;

symbolic procedure findnthroot p;
   nil;   % Until corrected.

% symbolic procedure x!-findnthroot p;
%     % Locate an n-th root symbol in poly p.
%     if domainp p then nil
%     else begin scalar w;
%         w:=mvar p; %check main var first.
%         if atom w
%           then return nil; %we have passed all sqrts.
%         if eqcar(w,'expt) and eqcar(caddr w,'quotient) then return w;
%         w:=findnthroot lc p;
%         if null w then w:=findnthroot red p;
%         return w
%     end;

symbolic procedure conjugatewrt(p,var);
  % Var -> -var in form p.
    if domainp p then p
    else if mvar p=var then begin
        scalar x,c,r;
        x:=tdeg lt p; %degree
        c:=lc p; %coefficient
        r:=red p; %reductum
        x:=remainder(x,2); %now just 0 or 1.
        if x=1 then c:=negf c; %-coefficient.
        return (lpow p .* c) .+ conjugatewrt(r,var) end
    else if ordop(var,mvar p) then p
    else (lpow p .* conjugatewrt(lc p,var)) .+
        conjugatewrt(red p,var);

symbolic procedure gcdcoeffsofsqrts u;
if atom u
  then if numberp u and minusp u
    then -u
    else u
  else if eqcar(mvar u,'sqrt)
    then begin
      scalar v;
      v:=gcdcoeffsofsqrts lc u;
      if v iequal 1
        then return v
        else return gcdf(v,gcdcoeffsofsqrts red u)
      end
    else begin
      scalar root;
      root:=findsquareroot u;
      if null root
        then return u;
      u:=makemainvar(u,root);
      root:=gcdcoeffsofsqrts lc u;
      if root iequal 1
        then return 1
        else return gcdf(root,gcdcoeffsofsqrts red u)
      end;

endmodule;


module trcase;  % Driving routine for integration of transcendental fns.

% Authors: Mary Ann Moore and Arthur C. Norman.
% Modifications by: John P. Fitch.

fluid '(!*backtrace
        !*failhard
        !*nowarnings
        !*purerisch
        !*reverse
        !*trint
        badpart
        ccount
        cmap
        cmatrix
        content
        cval
        denbad
        denominator
        indexlist
        lhs!*
        loglist
        lorder
        orderofelim
        power!-list!*
        rhs!*
        sillieslist
        sqfr
        sqrtflag
        sqrtlist
        tanlist
        svar
        varlist
        xlogs
        zlist);

% !*reverse:       flag to re-order zlist.
% !*nowarnings:    flag to lose messages.

global '(!*number!*
         !*ratintspecial
         !*seplogs
         !*spsize!*
         !*statistics
         gensymcount);

switch failhard;

exports transcendentalcase;

imports backsubst4cs,countz,createcmap,createindices,df2q,dfnumr,
  difflogs,fsdf,factorlistlist,findsqrts,findtrialdivs,gcdf,mkvect,
  interr,logstosq,mergin,multbyarbpowers,!*multf, % multsqfree,
  printdf,printsq,quotf,rationalintegrate,putv,
  simpint1,solve!-for!-u,sqfree,sqmerge,sqrt2top,substinulist,trialdiv,
  mergein,negsq,addsq,f2df,mknill,pnth,invsq,multsq,domainp,mk!*sq,
  mksp,prettyprint;

% Note that SEPLOGS keeps logarithmic part of result together as a
% kernel form, but this can lead to quite messy results.

symbolic
   procedure transcendentalcase(integrand,svar,xlogs,zlist,varlist);
   begin scalar divlist,jhd!-content,content,prim,sqfr,dfu,indexlist,
%      JHD!-CONTENT is local, while CONTENT is free (set in SQFREE).
      sillieslist,originalorder,wrongway,power!-list!*,
      sqrtlist,tanlist,loglist,dflogs,eprim,dfun,unintegrand,
      sqrtflag,badpart,rhs!*,lhs!*,gcdq,cmap,cval,orderofelim,cmatrix;
      scalar ccount,denominator,result,denbad;
        gensymcount:=0;
      integrand:=sqrt2top integrand; % Move the sqrts to the numerator.
      if !*trint then << printc "Extension variables z<i> are";
          print zlist>>;
%     if !*ratintspecial and null cdr zlist then
%           return rationalintegrate(integrand,svar);
     % *** now unnormalize integrand, maybe ***.
     begin scalar w,gg;
        gg:=1;
        foreach z in zlist do
           <<w := subs2 diffsq(simp z,svar);   % subs2q?
             gg := !*multf(gg,quotf(denr w,gcdf(denr w,gg)))>>;
        gg := quotf(gg,gcdf(gg,denr integrand));
        unintegrand := (!*multf(gg,numr integrand)
                        ./ !*multf(gg,denr integrand));  % multf?
        if !*trint then <<
                printc "After unnormalization the integrand is ";
                printsq unintegrand >>
      end;
      divlist := findtrialdivs zlist;
         % Also puts some things on loglist sometimes.
      sqrtlist := findsqrts zlist;
      divlist := trialdiv(denr unintegrand,divlist);
      % N.B. the next line also sets 'content' as a free variable.
      % Since SQFREE may be used later, we copy it into JHD!-CONTENT.
      prim := sqfree(cdr divlist,zlist);
      jhd!-content := content;
      printfactors(prim,nil);
      eprim := sqmerge(countz car divlist,prim,nil);
      printfactors(eprim,t);
%     if !*trint then <<terpri();
%         printsf denominator;
%         terpri();
%         printc "...content is:";
%         printsf jhd!-content>>;
      sqfr := for each u in eprim collect multup u;
%      sqfr := multsqfree eprim;
%     if !*trint then <<printc "...sqfr is:";
%         prettyprint sqfr>>;
      if !*reverse then zlist := reverse zlist; % Alter order function.
      indexlist := createindices zlist;
%     if !*trint then << printc "...indices are:";
%         prettyprint indexlist>>;
      dfu:=dfnumr(svar,car divlist);
%     if !*trint then << terpri();
%         printc "************ Derivative of u is:";
%         printsq dfu>>;
      loglist := append(loglist,factorlistlist prim); %%% nconc?
      loglist := mergein(xlogs,loglist);
      loglist := mergein(tanlist,loglist);
      cmap := createcmap();
      ccount := length cmap;
      if !*trint then <<printc "Loglist "; print loglist>>;
      dflogs := difflogs(loglist,denr unintegrand,svar);
      if !*trint
        then <<printc "************ 'Derivative' of logs is:";
               printsq dflogs>>;
      dflogs := addsq((numr unintegrand) ./ 1,negsq dflogs);
      % Put everything in reduction eqn over common denominator.
      gcdq := gcdf(denr dflogs,denr dfu);
      dfun := !*multf(numr dfu,denbad:=quotf(denr dflogs,gcdq));
      denbad := !*multf(denr dfu,denbad);
      denbad := !*multf(denr unintegrand,denbad);
      dflogs := !*multf(numr dflogs,quotf(denr dfu,gcdq));
      dfu := dfun;
      % Now DFU and DFLOGS are S.F.s.
      rhs!* := multbyarbpowers f2df dfu;
      if checkdffail(rhs!*,svar)
        then <<if !*trint then printsq checkdffail(rhs!*,svar);
      interr "Simplification fails on above expression">>;
      if !*trint then <<
          printc "Distributed Form of Numerator is:";
          printdf rhs!*>>;
      lhs!* := f2df dflogs;
%     if checkdffail(lhs!*,svar) then interr "Simplification failure";
      if !*trint then << printc "Distributed Form of integrand is:";
          printdf lhs!*;
          terpri()>>;
      cval := mkvect(ccount);
      for i := 0:ccount do putv(cval,i,nil ./ 1);
      power!-list!* := tansfrom(rhs!*,zlist,indexlist,0);
      lorder:=maxorder(power!-list!*,zlist,0);
      originalorder := for each x in lorder collect x;
           % Must copy as it is overwritten.
        if !*trint then <<
                printc "Maximum order for variables determined as ";
                print lorder >>;
        if !*statistics then << !*number!*:=0;
                !*spsize!*:=1;
                foreach xx in lorder do
                   !*spsize!*:=!*spsize!* * (xx+1) >>;
                % That calculates the largest U that can appear.
      dfun:=solve!-for!-u(rhs!*,lhs!*,nil);
      backsubst4cs(nil,orderofelim,cmatrix);
%      if !*trint then if ccount neq 0 then printvecsq cval;
        if !*statistics then << prin2 !*number!*; prin2 " used out of ";
                printc !*spsize!* >>;
      badpart:=substinulist badpart;
                 %substitute for c<i> still in badpart.
      dfun:=df2q substinulist dfun;
      result:= !*multsq(dfun,!*invsq(denominator ./ 1));
      result:= !*multsq(result,!*invsq(jhd!-content ./ 1));
      dflogs:=logstosq();
      if not null numr dflogs then <<
          if !*seplogs and (not domainp numr result) then <<
              result:=mk!*sq result;
              result:=(mksp(result,1) .* 1) .+ nil;
              result:=result ./ 1 >>;
          result:=addsq(result,dflogs)>>;
      if !*trint
        then  << %% prettyprint result;
          terpri();
          printc
          "*****************************************************";
          printc
           "************ THE INTEGRAL IS : **********************";
          printc
           "*****************************************************";
          terpri();
          printsq result;
          terpri()>>;
      if badpart then begin scalar n,oorder;
          if !*trint
            then printc "plus a part which has not been integrated";
          lhs!*:=badpart;
          lorder:=maxorder(power!-list!*,zlist,0);
          oorder:=originalorder;
          n:=length lorder;
          while lorder do <<
                if car lorder > car originalorder then
                        wrongway:=t;
                if car lorder=car originalorder then n:= n-1;
                lorder:=cdr lorder;
                originalorder:=cdr originalorder >>;
          if n=0 then wrongway:=t;      % Nothing changed
          if !*trint and wrongway then printc "Went wrong way";
          dfun:=df2q badpart;
%%          if !*trint
%%            then <<printsq dfun; printc "Denbad = "; printsf denbad>>;
          dfun:= !*multsq(dfun,invsq(denbad ./ 1));
          badpart := dfun;      %%% *****
          if wrongway then <<
                if !*trint then printc "Resetting....";
                result:=nil ./ 1;
                dfun := integrand; badpart:=dfun >>;
          if rootcheckp(unintegrand,svar) then
                return simpint1(integrand . svar.nil) . (nil ./ 1)
          else if !*purerisch or allowedfns zlist then
              << badpart := dfun;
                 dfun := nil ./ 1 >>    % JPff
           else << !*purerisch:=t;
                if !*trint
                  then <<printc "   Applying transformations ...";
                         printsq dfun>>;
              denbad:=transform(dfun,svar);
              if denbad=dfun
                then << dfun:=nil ./ 1; badpart:=denbad >>
             else <<denbad:=errorset!*(list('integratesq,mkquote denbad,
                                      mkquote svar,mkquote xlogs, nil),
                                      !*backtrace);
           %%% JPF fix for distributive version
                     if not atom denbad then <<
                        denbad:=car denbad;     % As from an errorset
                        dfun:=untan car denbad;
                        if (dfun neq '(nil . 1)) then
                            badpart:=untan cdr denbad;
           % There is still a chance that we went the wrong way.
           % Decide that it is better if there is no bad part
                        if car badpart and not(badpart=denbad) then <<
                          wrongway:=nil;
                          lhs!*:=f2df car badpart;
                          lorder:=maxorder(power!-list!*,zlist,0);
                          n:=length lorder;
                          while lorder do <<
                                if car lorder > car oorder then
                                        wrongway:=t;
                                if car lorder=car oorder then n:= n-1;
                                lorder:=cdr lorder;
                                oorder:=cdr oorder >>;
                          if wrongway or (n=0) then <<
                               if !*trint then printc "Still backwards";
                               dfun := nil ./ 1;
                               badpart := integrand>>>>>>
                     else <<badpart := dfun; dfun := nil ./ 1 >>>>>>;
          if !*failhard then rerror(int,9,"FAILHARD switch set");
          if !*seplogs and not domainp result then <<
                result:=mk!*sq result;
                if not numberp result
                  then result:=(mksp(result,1) .* 1) .+ nil;
                result:=result ./ 1>>;
          result:=addsq(result,dfun) end
         else badpart:=nil ./ 1;
      return (sqrt2top result . badpart)                % JPff
   end;

symbolic procedure checkdffail(u,v);
   % Sometimes simplification fails and this gives the integrator the
   % idea that something is a constant when it is not.  Check for this.
   if null u then nil
    else if depends(lc u,v) then lc u
    else checkdffail(red u,v);

symbolic procedure printfactors(w,prdenom);
    % W is a list of factors to each power. If PRDENOM is true
    % this prints denominator of answer, else prints square-free
    % decomposition.
    begin         scalar i,wx;
        i:=1;
        if prdenom then <<
            denominator:=1;
            if !*trint
              then printc "Denominator of 1st part of answer is:";
            if not null w then w:=cdr w >>;
loopx:  if w=nil then return;
        if !*trint then <<prin2 "Factors of multiplicity ";
                          prin2 i;
                          prin2t ":";
                          terpri()>>;
        wx:=car w;
        while not null wx do <<
            if !*trint then printsf car wx;
            for j:=1 : i do
                denominator:= !*multf(car wx,denominator);
            wx:=cdr wx >>;
        i:=i+1;
        w:=cdr w;
        go to loopx
    end;

% unfluid '(dfun svar xlogs);

endmodule;


module halfangle;  % Routines for conversion to half angle tangents.

% Author: Steve Harrington.
% Modifications by: John P. Fitch.

fluid '(!*gcd);

exports halfangle,untan;

symbolic procedure transform(u,x);
   % Transform the SQ U to remove the 'bad' functions sin, cos, cot etc.
   % in favor of half angles.
   % Do this with regard to cases like sin(x)*tan(x/2), so attempt to
   % limit times we use half angles.
   begin scalar zl,tnarg,substlist;
      zl := zlist;
      while car(tnarg := tan!-function!-in zl)
         and halfangle!-confusion(zlist,cadar tnarg)
       do <<zl := cdr tnarg;
            tnarg := car tnarg;
            if eqcar(tnarg,'tan)
              then substlist := (gensym() . tnarg) . substlist
             else substlist := (gensym() .
                                  list('quotient,1,('tan . cdr tnarg)))
                                  . substlist;
            u := subst(caar substlist,tnarg,u)>>;
      return if substlist
               then simp sublis(substlist,prepsq halfangle(u,x))
              % simp prepsq was added so that 1/(e**x*cos(1/e**x)**2)
              % for example returns a closed-form result.
              else simp prepsq halfangle(u,x)
   end;

symbolic procedure tan!-function!-in zz;
   % Look at zlist for tangents or cotangents.
   <<while zz and not eqcar(car zz,'tan) and not eqcar(car zz,'cot)
        do zz := cdr zz;
     if null zz then nil . nil else zz>>;

symbolic procedure halfangle!-confusion(zz,tnarg);
   % Is there a function in the zlist with twice the tangent argument?
   <<while zz and (atom car zz
              or not(tnarg = prepsq simp list('quotient,cadar zz,2)))
        do zz := cdr zz;
     zz>>;

symbolic procedure quotqq(u1,v1);
   multsq(u1,invsq(v1));

symbolic procedure !*subtrq(u1,v1);
   addsq(u1, negsq(v1));

symbolic procedure !*int2qm(u1);
   if u1=0 then nil . 1 else u1 . 1;

symbolic procedure halfangle(r,x);
   % Top level procedure for converting;
   % R is a rational expression to be converted,
   % X the integration variable.
   % A rational expression is returned.
   quotqq(hfaglf(numr(r),x), hfaglf(denr(r),x));

symbolic procedure hfaglf(p,x);
   % Converting polynomials,  a rational expression is returned.
   if domainp(p) then !*f2q(p)
    else subs2q addsq(multsq(exptsq(hfaglk(mvar(p),x), ldeg(p)),
                             hfaglf(lc(p),x)),
                      hfaglf(red(p),x));

symbolic procedure hfaglk(k,x);
   % Converting kernels,  a rational expression is returned.
   begin
      scalar kt;
      if atom k or not member(x,flatten(cdr(k))) then return !*k2q k;
      k := car(k) . hfaglargs(cdr(k), x);
      kt := simp list('tan, list('quotient, cadr(k), 2));
      return if car(k) = 'sin
       then quotqq(multsq(!*int2qm(2),kt), addsq(!*int2qm(1),
                            exptsq(kt,2)))
      else if car(k) = 'cos
       then quotqq(!*subtrq(!*int2qm(1),exptsq(kt,2)),addsq(!*int2qm(1),
         exptsq(kt,2)))
      else if car(k) = 'tan
       then quotqq(multsq(!*int2qm(2),kt), !*subtrq(!*int2qm(1),
                            exptsq(kt,2)))
      else if car(k) = 'cot
       then quotqq(!*subtrq(!*int2qm(1),
                   exptsq(kt,2)),multsq(!*int2qm(2),kt))
      else if car(k) = 'sec
       then quotqq(addsq(!*int2qm(1), exptsq(kt,2)),
                   !*subtrq(!*int2qm(1),exptsq(kt,2)))
      else if car(k) = 'cosec
       then quotqq(addsq(!*int2qm(1),exptsq(kt,2)),
                   !*subtrq(!*int2qm(1),exptsq(kt,2)))
      else if car(k) = 'sinh then
        quotqq(!*subtrq(!*p2q mksp('expt.('e. cdr k),2),
        !*int2qm(1)), multsq(!*int2qm(2),
                             !*p2q mksp('expt . ('e . cdr(k)),1)))
      else if car(k) = 'cosh then
        quotqq(addsq(!*p2q mksp('expt.('e. cdr k),2),
        !*int2qm(1)), multsq(!*int2qm(2),
                             !*p2q mksp('expt . ('e . cdr(k)),1)))
      else if car(k) = 'tanh then
        quotqq(!*subtrq(!*p2q mksp('expt.('e. cdr k),2),
        !*int2qm(1)), addsq(!*p2q mksp ('expt.('e.cdr(k)),2),
        !*int2qm(1)))
      else if car(k) = 'coth then
        quotqq(addsq(!*p2q mksp('expt.('e.cdr(k)),2), !*int2qm(1)),
              !*subtrq(!*p2q mksp('expt.('e . cdr k),2),!*int2qm(1)))
      else if car(k) = 'acot then
        !*p2q mksp(list('atan, list('quotient, 1, cadr k)),1)
      else !*k2q(k);  % additional transformation might be added here.
   end;

symbolic procedure hfaglargs(l,x);
   % Conversion of argument list.
   if null l then nil
    else prepsq(hfaglk(car(l),x)) . hfaglargs(cdr(l),x);

symbolic procedure untanf x;
   % This should be done by a table.
   begin scalar y,z,w;
      if domainp x then return x . 1;
      y := mvar x;
      if eqcar(y,'int) then error1();  % assume all is hopeless.
      z := ldeg x;
      w := 1 . 1;
      y :=
       if atom y then !*k2q y
        else if car y eq 'tan
         then begin scalar yy;
%%              printc "Recursive tan"; printc cadr y;
                yy := prepsq untan simp cadr y . nil;
%%              princ "==> "; printc yy;
                if evenp z
                then <<z := z/2;
                       return simp list('quotient,
                                        list('plus,
                                             list('minus,
                                                  list('cos,
                                                       'times
                                                         . (2 . yy))),
                                             1),list('plus,
                                                     list('cos,
                                                          'times
                                                            . (2 . yy)),
                                              1))>>
               else if z=1
                then return simp list('quotient,
                                      list('plus,
                                           list('minus,
                                                list('cos,
                                                    'times . (2 . yy))),
                                           1),list('sin,
                                                   'times . (2 . yy)))
               else <<z := (z - 1)/2;
                      w :=
                       simp list('quotient,
                                 list('plus,
                                      list('minus,
                                           list('cos,
                                                'times
                                                  . (2 . yy))),
                                      1),list('sin,
                                              'times
                                                . (2 . yy)));
                      return simp list('quotient,
                                       list('plus,
                                            list('minus,
                                                 list('cos,
                                                      'times
                                                        . (2 . yy))),
                                            1),list('plus,
                                                    list('cos,
                                                         'times
                                                           . (2 . yy)),
                                                    1)) >>
        end
        else simp y;
      return addsq(multsq(multsq(exptsq(y,z),untanf lc x),w),
                   untanf red x)
   end;

% symbolic procedure untanlist(y);
%    if null y then nil
%      else (prepsq (untan(simp car y)) . untanlist(cdr y));

symbolic procedure untan(x);
   % Expects x to be canonical quotient.
   begin scalar y;
      y:=cossqchk sinsqrdchk multsq(untanf(numr x),
                                    invsq untanf(denr x));
      return if length flatten y>length flatten x then x else y
   end;

symbolic procedure sinsqrdchk(x);
   multsq(sinsqchkf(numr x), invsq sinsqchkf(denr x));

symbolic procedure sinsqchkf(x);
   begin
      scalar y,z,w;
      if domainp x then return x . 1;
      y := mvar x;
      z := ldeg x;
      w := 1 . 1;
      y := if eqcar(y,'sin) then if evenp z
       then <<z := quotient(z,2);
              simp list('plus,1,list('minus,
                                     list('expt,('cos . cdr(y)),2)))>>
      else if z = 1 then !*k2q y
      else  << z := quotient(difference(z,1),2); w := !*k2q y;
             simp list('plus,1,list('minus,
                                    list('expt,('cos . cdr(y)),2)))>>
       else !*k2q y;
      return addsq(multsq(multsq(exptsq(y,z),sinsqchkf(lc x)),w),
                   sinsqchkf(red x));
   end;

symbolic procedure cossqchkf(x);
   begin
      scalar y,z,w,x1,x2;
      if domainp x then return x . 1;
      y := mvar x;
      z := ldeg x;
      w := 1 . 1;
      x1 := cossqchkf(lc x);
      x2 := cossqchkf(red x);
      x := addsq(multsq(!*p2q lpow x,x1),x2);
      y := if eqcar(y,'cos) then if evenp z
       then <<z := quotient(z,2);
              simp list('plus,1,list('minus,
                                     list('expt,('sin . cdr(y)),2)))>>
      else if z = 1 then !*k2q y
      else  << z := quotient(difference(z,1),2); w := !*k2q y;
             simp list('plus,1,list('minus,
                                    list('expt,('sin . cdr(y)),2)))>>
       else !*k2q y;
      y := addsq(multsq(multsq(exptsq(y,z),w),x1),x2);
      return if length(y) > length(x) then x else y;
   end;

symbolic procedure cossqchk(x);
begin scalar !*gcd;
   !*gcd := t;
   return multsq(cossqchkf(numr x), invsq cossqchkf(denr x))
end;

symbolic procedure lrootchk(l,x);
   % Checks each member of list l for a root.
   if null l then nil else krootchk(car l, x) or lrootchk(cdr l, x);

symbolic procedure krootchk(f,x);
   % Checks a kernel to see if it is a root.
   if atom f then nil
    else if car(f) = 'sqrt and member(x, flatten cdr f) then t
   else if car(f) = 'expt
        and not atom caddr(f)
        and caaddr(f) = 'quotient
        and member(x, flatten cadr f)  then t
   else lrootchk(cdr f, x);

symbolic procedure rootchk1p(f,x);
   % Checks polynomial for a root.
   if domainp f then nil
    else krootchk(mvar f,x) or rootchk1p(lc f,x) or rootchk1p(red f,x);

symbolic procedure rootcheckp(f,x);
   % Checks rational (standard quotient) for a root.
   rootchk1p(numr f,x) or rootchk1p(denr f,x);

endmodule;


module trialdiv;  % Trial division routines.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(!*trint denominator loglist tanlist);

exports countz,findsqrts,findtrialdivs,trialdiv,simp,mksp;

imports !*multf,printsf,quotf;

symbolic procedure countz dl;
% DL is a list of S.F.s;
    begin         scalar s,n,rl;
loop2:  if null dl then return arrangelistz rl;
        n:=1;
loop1:  n:=n+1;
        s:=car dl;
        dl:=cdr dl;
        if not null dl and (s eq car dl) then
            go to loop1
        else rl:=(s.n).rl;
        go to loop2
    end;

symbolic procedure arrangelistz d;
    begin         scalar n,s,rl,r;
        n:=1;
        if null d then return rl;
loopd:  if (cdar d)=n then s:=(caar d).s
        else r:=(car d).r;
        d:=cdr d;
        if not null d then go to loopd;
        d:=r;
        rl:=s.rl;
        s:=nil;
        r:=nil;
        n:=n+1;
        if not null d then go to loopd;
        return reversip rl
    end;

symbolic procedure findtrialdivs zl;
%zl is list of kernels found in integrand. result is a list
%giving things to be treated specially in the integration
%viz: exps and tans.
%Result is list of form ((a . b) ...)
% with a a kernel and car a=expt or tan
% and b a standard form for either expt or (1+tan**2).
    begin         scalar dlists1,args1;
        while not null zl do <<
            if exportan car zl then <<
                if caar zl='tan
                  then << args1:=(mksp(car zl,2) .* 1) .+ 1;
                    tanlist:=(args1 ./ 1) . tanlist>>
                else args1:=!*k2f car zl;
                dlists1:=(car zl . args1) . dlists1>>;
            zl:=cdr zl >>;
        return dlists1
    end;

symbolic procedure exportan dl;
    if atom dl then nil
    else begin
    % extract exp or tan fns from the z-list.
    if eq(car dl,'tan) then return t;
nxt:    if not eq(car dl,'expt) then return nil;
        dl:=cadr dl;
        if atom dl then return t;
% Make sure we find nested exponentials?
        go to nxt
    end;

symbolic procedure findsqrts z;
    begin  scalar r;
        while not null z do <<
            if eqcar(car z,'sqrt) then r:=(car z) . r;
            z:=cdr z >>;
        return r
    end;

symbolic procedure trialdiv(x,dl);
    begin         scalar qlist,q;
    while not null dl do
        if not null(q:=quotf(x,cdar dl)) then <<
            if (caaar dl='tan) and not eqcar(qlist,cdar dl) then
                loglist:=('iden . simp cadr caar dl) . loglist;
                         %tan fiddle!
            qlist:=(cdar dl).qlist;
            x:=q >>
        else dl:=cdr dl;
    return qlist.x
    end;

endmodule;


module vect;  % Vector support routines.

% Authors: Mary Ann Moore and Arthur C. Norman.
% Modified by: James H. Davenport.

exports mkuniquevect,mkvec,mkvecf2q,mkidenm,copyvec,vecsort,swap,
        non!-null!-vec,mkvect2;

symbolic procedure mkuniquevect v;
begin scalar u,n;
  n:=upbv v;
  for i:=0:n do begin
    scalar uu;
    uu:=getv(v,i);
    if not (uu member u)
      then u:=uu.u
    end;
  return mkvec u
  end;

symbolic procedure mkvec(l);
begin scalar v,i;
  v:=mkvect(isub1 length l);
  i:=0;
  while l do <<putv(v,i,car l); i:=iadd1 i; l:=cdr l>>;
  return v
  end;

symbolic procedure mkvecf2q(l);
begin
  scalar v,i,ll;
  v:=mkvect(isub1 length l);
  i:=0;
  while l do <<
    ll:=car l;
    if ll = 0 then ll:=nil;
    putv(v,i,!*f2q ll);
    i:=iadd1 i;
    l:=cdr l >>;
  return v
  end;

symbolic procedure mkidenm n;
begin
  scalar ans,u;
  scalar c0,c1;
  c0:=nil ./ 1;
  c1:= 1 ./ 1;
  % constants.
  ans:=mkvect(n);
  for i:=0 step 1 until n do <<
    u:=mkvect n;
    for j:=0 step 1 until n do
      if i iequal j
        then putv(u,j,c1)
        else putv(u,j,c0);
    putv(ans,i,u) >>;
  return ans
  end;

symbolic procedure copyvec(v,n);
   begin scalar new;
    new:=mkvect(n);
    for i:=0:n do putv(new,i,getv(v,i));
    return new
   end;

symbolic procedure vecsort(u,l);
% Sorts vector v of numbers into decreasing order.
% Performs same interchanges of all vectors in the list l.
begin
  scalar j,k,n,v,w;
  n:=upbv u;% elements 0...n exist.
  % algorithm used is a bubble sort.
  for i:=1:n do begin
    v:=getv(u,i);
    k:=i;
  loop:
    j:=k;
    k:=isub1 k;
    w:=getv(u,k);
    if v<=w
      then goto ordered;
    putv(u,k,v);
    putv(u,j,w);
    mapc(l,function (lambda u;swap(u,j,k)));
    if k>0
      then goto loop;
  ordered:
    end;
  return nil
  end;

symbolic procedure swap(u,j,k);
if null u
  then nil
  else begin
    scalar v;
    %swaps elements i,j of vector u.
    v:=getv(u,j);
    putv(u,j,getv(u,k));
    putv(u,k,v)
    end;

symbolic procedure non!-null!-vec v;
begin
  scalar cnt;
  cnt := 0;
  for i:=0:upbv v do
    if getv(v,i)
      then cnt:=iadd1 cnt;
  return cnt
  end;

symbolic procedure mkvect2(n,initial);
begin
  scalar u;
  u:=mkvect n;
  for i:=0:n do
    putv(u,i,initial);
  return u
  end;

endmodule;


end;
