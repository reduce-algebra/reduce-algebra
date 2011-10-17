From hearn@rand.orgSat Feb  3 09:55:22 1996
Date: Sat, 03 Feb 96 01:00:05 -0800
From: Tony Hearn <hearn@rand.org>
To: shar-list@rand.org
Subject: Shar File


# This is a shell archive.  Remove anything before this line, then
# unpack it by saving it in a file and typing "sh file".  (Files
# unpacked will be owned by you and have default permissions.)
#
# This archive contains:
# plot/plot.red

echo x - plot/plot.red
if [ -f plot/plot.red ]
   then
    mv plot/plot.red \
       plot/plot.red.old
  else
    echo  "*** New file plot/plot.red created"
fi
cat > "plot/plot.red" \
    << '//E*O*F plot/plot.red//'
module plot; % device and driver independent plot services.

% Author: Herbert Melenk.

% Minor corrections by Winfried Neun (October 1995)

create!-package('(plot),nil);

global '(

      plotdriver!*         % modulename of the actual driver.

      plotmax!*            % maximal floating point number which
                           % gnuplot supports on the machine
                           % (mostly IEEE double or single precision).

      plotmin!*            % lower bound (=1/plotmax!*)

      variation!*          %  defintion of y-bigstep for smooth

      plotoptions!*        % list for collecting the options.

);

fluid '(

      plotderiv!*          %  derivative for 2d plot

);

!#if(or (errorp (errorset '!*writingfaslfile nil nil)) 
        (not !*writingfaslfile) 
        (errorp (errorset '(load fcomp) nil nil)))
   prin2t "no support for fast float!"; 
   eval'(dm fdeclare (x) nil); 
   eval'(dm thefloat (x)(cadr x));
!#endif

endmodule;

module plotsynt; % Support for the syntax of the plot command.

% Author: Herbert Melenk.

% Create .. as the infix operator if not yet done.

!*msg := nil;  % prevent message  ".. redefined" during load

newtok '( (!. !.) !*interval!*);  

if not(gettype '!*interval!* = 'operator) then
<< 
   precedence .., or;
   algebraic operator ..;
   put('!*interval!*,'PRTCH,'! !.!.! );
>>;

mkop 'point;

!*msg := t;

fluid '(plot!-points!* plot!-refine!* plot!-contour!*);

global '(plot_xrange plot_yrange plot_zrange);
share plot_xmesh,plot_ymesh,plot_xrange,plot_yrange,plot_zrange;

fluid '(plotprecision!*);

plotprecision!* := 0.9995;

fluid '(!*show_grid test_plot);

switch show_grid;
switch test_plot; % for test printouts

if null plotmax!* then
<< 
   load!-package 'arith;
   if not !!plumax then roundconstants();
   plotmax!* := !!plumax;     % IEEE double precision 
>>;

plotmin!*:= 1.0/plotmax!*;


fluid '(plotranges!* plotfunctions!*  plotstyle!* !*plotoverflow
        !*roundbf);

put('plot,'psopfn,'ploteval);

% I need the following definition only at compile time.
macro procedure plotdriver u;
  {'apply,{'get,'plotdriver!*,mkquote cadr u},'list.cddr u};

symbolic procedure ploteval u;
  begin scalar m,!*exp;
    if null plotdriver!* then 
      rederr "no active device driver for PLOT";
    m:=plotrounded(nil);
    plot!-points!* := {20};
    plot!-refine!* := 8;
    !*plotoverflow := nil;
    plotranges!* := plotfunctions!* := nil;
    plotstyle!* := 'lines;
    plotdriver(init);
    for each option in u do ploteval1 plot!-reval option;
    errorset('(ploteval2),t,nil);
    plotrounded(m);
  end;
 
symbolic procedure plot!-reval u;
 % Protected call reval: simplify u, but don't call any 
 % algebraic procedure.
   begin scalar w;
     w:={nil};
     u:=plot!-reval1(u,w);
     return car w and u or reval u;
   end; 

symbolic procedure plot!-reval1(u,w);
  if idp u then reval u else
  if atom u or eqcar(u,'!:dn!:) or get(car u,'dname) then u else   %WN
  if eq(car u,'!*sq) then plot!-reval1 (reval u,w) else            %WN
  <<if flagp(car u,'opfn) and
         memq(car u,'(first second rest rhs lhs)) then
     << u := reval u;                                              %WN
        plot!-reval1(u,w)>> else
   << if flagp(car u,'opfn) then car w:=t;
    car u . for each q in cdr u collect plot!-reval1(q,w) >> >>;

symbolic procedure ploteval1 option;
   begin scalar x,do;
     do := get(plotdriver!*,'do);
     if pairp option and (x:=get(car option,do)) 
             then apply(x,list option) else
     if pairp option and (x:=get(car option,'plot!-do)) 
             then apply(x,list option) else
     if eqcar(option,'equal) and (x:=get(cadr option,do))
             then apply(x,list caddr option) else
     if eqcar(option,'equal) and (x:=get(cadr option,'plot!-do))
             then apply(x,list caddr option) 
       else ploteval0 option;
   end;
  
symbolic procedure ploteval0 option;
  begin scalar l,r,opt,w;
    opt:=get(plotdriver!*,'option);
    if flagp(option,opt) then
      <<plotoptions!*:=option . plotoptions!*; return>>;
    if eqcar(option,'list) then
      <<option := cdr option;
        if option and eqcar(car option,'list) then
          return (plotfunctions!*:= 
             ('points.plotpoints option).plotfunctions!*);
        for each o in option do ploteval0 o; return;
      >>;
    if eqcar(option,'equal) and flagp(cadr option,opt) then
      <<plotoptions!*:=(cadr option.caddr option). plotoptions!*; 
       return>>;
    if not eqcar(option,'equal) then 
      <<plotfunctions!*:= (nil.option) . plotfunctions!*; return>>;

      % Handle equations.
    l:=plot!-reval cadr option;
    r:=plot!-reval caddr option;
    if plot!-checkcontour(l,r) then return
      plotfunctions!*:=('implicit.l) . plotfunctions!*;
    if not idp l then typerr(option,"illegal option in PLOT");

    if l memq '(size terminal view) then
      <<plotoptions!*:=(l.r).plotoptions!*; return>>;

       % iteration over a range?
    if eqcar(r,'times) and eqcar(caddr r,'!*interval!*) 
        and evalnumberp(w:=cadr r) and evalgreaterp(w,0) and
        not evalgreaterp(w,1) 
     then <<plot!-points!*:=append(plot!-points!*,
              {l.reval{'floor,{'quotient,1,w}}});
            r:=caddr r>>;

    if eqcar(r,'quotient) and eqcar(cadr r,'!*interval!*) 
       and fixp caddr r and caddr r > 0
     then <<plot!-points!*:=append(plot!-points!*,{l.caddr r});
            r:=cadr r>>;

       % range?
    if eqcar(r,'!*interval!*) then
     <<r:='!*interval!* . revalnuminterval(r,t);
       plotranges!* := (l . r) . plotranges!*>>
      else
       plotfunctions!* := (l . r) . plotfunctions!*;
  end;

symbolic procedure ploteval2 ();
   % all options are collected now;
  begin scalar dvar,ivars,para,impl;
   for each u in plotfunctions!* do 
     <<impl:=impl or car u eq 'implicit;
       para:=eqcar(cdr u,'point);
       if impl and dvar and dvar neq car u then
          rederr "mixture of implicit and regular plot not supported";
       dvar:=car u or dvar;
       ivars := plotindepvars(cdr u,ivars)>>;
      % classify
   if null dvar then
   <<dvar:='(x y z);
     for each x in ivars do dvar:=delete(x,dvar);
     if dvar then dvar:=if 'y memq dvar then 'y else car dvar;
   >>;
   if para and length ivars=1 then plotevalpara1(car ivars) else
   if para and length ivars=2 then plotevalpara2(car ivars,cadr ivars)
    else if length ivars=1 then ploteval2x(car ivars,dvar) else
   if length ivars=2 then ploteval3xy(car ivars,cadr ivars,dvar) else
   if length ivars=3 and impl then 
            ploteval3impl(car ivars,cadr ivars,caddr ivars)
    else typerr('list . for each p in plotfunctions!* collect 
                         if null car p then cdr p else
                         {'equal,car p,cdr p},
                " plot option or function");
  plotdriver(show);
  end;

symbolic procedure plot!-checkcontour(l,r);
  % true if the job is a contour expression.
   if length plotindepvars(l,nil)=2 then
     if r=0 then <<plot!-contour!*:={0};t>>
       else eqcar(r,'list) and
     <<plot!-contour!*:= for each x in cdr r collect   
        <<x:=plot!-reval x; l:=l and adomainp x; x>>;
       l>>;

symbolic procedure plotrange(x,d);
   begin scalar y;
     y:=assoc(x,plotranges!*);
     y:=if y then cdr y else d;
     if y=0 or null y then % return nil;
     y:={'!*INTERVAL!*, - plotmax!*, plotmax!*};
     if not eqcar(y,'!*INTERVAL!*) then
        typerr(y,"plot range");
     return {plotevalform0(rdwrap cadr y,nil) , 
             plotevalform0(rdwrap caddr y,nil)};
   end;

symbolic procedure plot!-points(x);
  (if w then cdr w else car plot!-points!*)
    where w=assoc(x,cdr plot!-points!*);

symbolic procedure plotseteq(u,v);
    null u and null v or car u member v 
       and plotseteq(cdr u,delete(car u,v));

symbolic procedure plotindepvars(u,v);
    if idp u then 
       if member(u,v) or member(u,'(e pi)) 
                      or u eq 'i and !*complex then v 
               else  u . v 
    else if eqcar(u,'file) then cddr u 
    else if pairp u then
      if eqcar(u,'!:dn!:) or get(car u,'dname) then v else
      if member(car u,'(plus minus difference times quotient expt)) or
	 get(car u,'!:RD!:) or get(car u,'simpfn)
	    or eqcar(getd(car u),'expr)
       then <<for each x in cdr u do v:=plotindepvars(x,v); v>>
     else typerr(u,"expression in function to plot")
    else v;

remprop('plotshow,'stat);
 
symbolic procedure plotshow();
   plotdriver(show);

put('plotshow,'stat,'endstat);

remprop('plotreset,'stat);

symbolic procedure plotreset();
   plotdriver(reset);

put('plotreset,'stat,'endstat);

put('points,'plot!-do,
    function(lambda(x);car plot!-points!*:=ieval x));

put('refine,'plot!-do,
    function(lambda(x);plot!-refine!*:=ieval x));

endmodule; % plotsynt.

module plotexp2; % Compute explicit 2-dim graph y=f(x);

symbolic procedure ploteval2x(x,y);
  begin scalar xlo,xhi,ylo,yhi,rx,ry,fp,fcn,fcns,pts;
     if y='implicit then 
        rederr "no implicit plot in one dimension";  
     rx:=plotrange(x,
       reval(plot_xrange or '(!*interval!* -10 10)));
     xlo:=car rx;
     xhi:=cadr rx;
     fcns:= reverse plotfunctions!*;
     ry:=plotrange(y, reval(plot_yrange or nil));
     if ry then <<ylo:=car ry; yhi:=cadr ry>>;
     while fcns do
     <<fcn := car fcns; fcns := cdr fcns;
       if eqcar(fcn,'points) then fp:=caddr fcn else
       pts:=ploteval2x1(cdr fcn,x,xlo,xhi,ylo,yhi).pts;
     >>;
     plotdriver(plot!-2exp,x,y,pts,fp);
  end;

symbolic procedure ploteval2x1(f,x,xlo,xhi,ylo,yhi);
   begin scalar plotsynerr!*,l,d,d0,u,v,vv,p,mx,mn,ff;
        scalar plotderiv!*;
        integer nx;
     % compute algebraic derivative.
    ff:= errorset({'reval,mkquote {'df,f,x}},nil,nil); 
    if not errorp ff and not smemq('df,car ff) then 
% Hier irrte Goethe.  % This comment is for Herbert, please keep it
%      plotderiv!*:= rdwrap plotderiv!* . plotderiv!*;
       plotderiv!*:= rdwrap car ff . car ff;
    ff:=rdwrap f;
    p:=float (nx:=plot!-points(x));
    d:=(d0:=(xhi-xlo))/p;
    v:=xlo;
    for i:=0:nx  do
     <<vv:=if i=0 or i=nx  then v 
           else v+d*(random(100)-50)*0.001;
       u:= plotevalform(ff,f,{x.vv});
       if plotsynerr!* then typerr(f,"function to plot");
       if eqcar(u,'overflow) then u:=nil;
       if u then
       << 
          if yhi and u>yhi then u:=yhi else
          if ylo and u<ylo then u:=ylo;;
          if null mx or u>mx then mx:=u;
          if null mn or u<mn then mn:=u
       >>;
       l:=(vv.u).l;
       v:=v+d;
     >>;
     if null mx or null mn then rederr "plot, sampling failed";
     variation!* :=
     if yhi and not(yhi=plotmax!*) then (yhi-ylo) else
        (mx-mn); %  ploteval2xvariation l;

    if plot!-refine!*>0 then
        l:=smooth(reversip l,ff,f,x,mx,mn,ylo,yhi,d);
    return {for each x in l collect {car x,cdr x}};
   end;


symbolic procedure ploteval2xvariation l;
  begin scalar u;
   % compute geometric mean value.
    integer m;
    u:=1.0;
    for each p in l do
     <<m:=m+1; p:=cdr p;
       if p and p neq 0.0 then u:=u*abs p;
     >>;
    return expt(u,1/float m);
  end;
     
symbolic procedure smooth(l,ff,f,x,maxv,minv,ylo,yhi,d);
  begin scalar rat,grain,cutmax,cutmin,z,z0;
   z:=l;
   cutmax :=  yhi or (- 2*minv + 3*maxv);
   cutmin :=  ylo or (3*minv - 2*maxv);
   grain  :=  variation!* *0.05;
   rat := d / if numberp maxv and maxv > minv then (maxv - minv) 
               else 1;
    % Delete empty points in front of the point list.
   while z and null cdar z and cdr z and null cdadr z do z:=cdr z;
    % Find left starting point if there is no one yet.
   if z and null cdar z and cdr z then
   <<z0:= findsing(ff,f,x,ylo,yhi,cadr z,car z);
     if z0 then l:=z:=z0.cdr z; 
   >>;
   while z and cdr z do
   <<z0:=z; z:=cdr z;
       smooth1(z0,ff,f,x,cutmin,cutmax,grain,rat,0,plot!-refine!*)
   >>;
   return l;
  end;

symbolic procedure smooth1(l,ff,f,x,minv,maxv,g,rat,lev,ml);
    smooth2(l,ff,f,x,minv,maxv,g,rat,lev,ml);


symbolic procedure smooth2(l,ff,f,x,minv,maxv,g,rat,lev,ml);
  if lev >= ml then 
      smooth3(l,ff,f,x,minv,maxv,g,rat,lev,ml)
    else
  if null cdar l then t else
 begin scalar p0,p1,p2,p3,x1,x2,x3,y1,y2,y3,d;
       scalar dy12,dy32,dx12,dx32,z,a,w;
%%%%%    fdeclare(x1,x2,x3,y1,y2,y3,rat,d,dx12,dx32,dy12,dy32);
    lev:= add1 lev;
    p1:=car l; p3:=cadr l;
    x1:=car p1; y1:=cdr p1;
    x3:=car p3; y3:=cdr p3;
  nopoint:
    if null y3 then
    <<if null cddr l then return(cdr l:=nil);
      x2:=x3; y2:=y3; cdr l:=cddr l;
      p3:=cadr l; x3:=car p3; y3:=cdr p3;
      if y3 then goto outside else goto nopoint;
    >>;
    % Generate a new point
    x2:=(x1+x3)*0.5;
    if null (y2 := plotevalform(ff,f,{x.x2})) 
       or eqcar(y2,'overflow) then goto outside;
    if y2 < minv or y2 > maxv then goto outside;

    dy32 := (y3 - y2) * rat; dx32 := x3 - x2;
    dy12 := (y1 - y2) * rat; dx12 := x1 - x2;
    d :=  sqrt((dy32**2 + dx32**2) * (dy12**2 + dx12**2));
    if zerop d then return t;
    w := (dy32*dy12 + dx32*dx12);
    d:= errorset({'quotient,w,d},nil,nil);
     % d is cos of angle between the vectors p2p1 and p2p3.
     % d near to 1 means that the angle is almost 0 (needle).
    if ploterrorp d then goto disc else d:=car d;
    a:=abs(y3-y1)<g;
    if d > plotprecision!* and a and lev=ml then goto disc;

      % I have a good point, insert it with destructive replacement.
    cdr l := (x2 . y2) . cdr l;
      % When I have an almost 180 degree angle, I compare the
      % derivative at the midpoint with the difference quotient.
      % If these are close to each other, I stop the refinement.
    if -d  > plotprecision!* 
       and (null plotderiv!* 
             or
           ((w:=plotevalform(car plotderiv!*,cdr plotderiv!*,{x.x2}))
                and abs (w - (y3-y1)/(x3-x1))*rat <0.1))
      then return t;
    smooth2(cdr l,ff,f,x,minv,maxv,g,rat,lev,ml);
    smooth2(l,ff,f,x,minv,maxv,g,rat,lev,ml);
    return t;

    % Function has exceeded the boundaries. I try to locate the screen 
    % crossing point.
  outside:
    cdr l := (x2 . nil) . cdr l;
    z := cdr l;    % insert a break
    p2:= (x2 . y2);  % artificial midpoint

    p0:=findsing(ff,f,x, minv, maxv, p1, p2);
    if p0 then
      << cdr l := p0 . z;
         smooth2(l,ff,f,x,minv,maxv,g,rat,lev,ml) >>;
    p0 := findsing(ff,f,x, minv, maxv, p3, p2);
    if p0 then
      << cdr z := p0 . cdr z;
         smooth2(cdr z,ff,f,x,minv,maxv,g,rat,lev,ml) >>;
    return;
  
  disc:  % look for discontinuities.
    return smooth3(l,ff,f,x,minv,maxv,g,rat,lev,ml);
  end;

symbolic procedure smooth3(l,ff,f,x,minv,maxv,g,rat,lev,ml);
 % detect discontinuities.
 begin scalar p1,p2,p3,x1,x2,x3,y1,y2,y3,d;
       scalar x2hi,y2hi,x2lo,y2lo,dir,hidir,chi,clo;
       scalar lobound,hibound;
       integer n;
 %%%%%      fdeclare(x1,x2,x3,y1,y2,y3,d,hidir);
    p1:=car l; p3:=cadr l;
    x1:=car p1; y1:=cdr p1;
    x3:=car p3; y3:=cdr p3;
    if abs(y3-y1)<variation!* then return t;

  % Bigstep found. 
    hibound:=variation!**10.0; lobound:=-hibound;
    if y1>y3 then
    <<x2hi:=x1; y2hi:=y1; x2lo:= x3; y2lo:=y3; hidir:=-1.0>>
       else
    <<x2hi:=x3; y2hi:=y3; x2lo:= x1; y2lo:=y1; hidir:=1.0>>;
    n:=0; d:= (x3-x1)*0.5; x2:=x1+d;
  % intersection loop. Cut remaining interval into two parts.
  % If there is again a high increase in one direction we assume
  % a pole.
  next_point:
    if null (y2 := plotevalform(ff,f,{x.x2}))
       or eqcar(y2,'overflow) then goto outside;
    if y2 < minv then 
      <<x2lo:=x2;y2lo:=minv;dir:=hidir>> 
    else if y2 < y2lo then 
      <<if y2lo<0.0 and y2<y2lo+y2lo and y2<lobound then clo:=t;
        x2lo:=x2;y2lo:=y2;dir:=hidir;>> 
    else if y2 > maxv then 
     <<x2hi:=x2;y2hi:=maxv;dir:=-hidir>> 
    else if y2 > y2hi then 
     <<if y2hi>0.0 and y2>y2hi+y2hi and y2>hibound then chi:=t;
       x2hi:=x2;y2hi:=y2;dir:=-hidir;>> else
      goto no_disc;
    if dir and (n:=n+1)<20 and (not clo or not chi) then
    <<d:=d/2; x2:=x2+d*dir; goto next_point>>;
  no_disc:
    if null dir then return t;
    if clo then y2lo:=minv;
    if chi then y2hi:=maxv;
  outside:
    p1:=(x2hi.y2hi); p3:=(x2lo.y2lo);
    if hidir=1.0 then <<p2:=p3;p3:=p1;p1:=p2>>;
    cdr l := p1 . (car p1.nil) . p3 . cdr l;
    return;
  brk:
    cdr l := (car p1.nil)  . cdr l;
    return;
  end;
    
symbolic procedure findsing(ff,f,x,minv,maxv,p1,p3);
% P3 is a point with a singularity.
% Try to locate the point where we exceed minv/maxv by subdivision.
begin scalar p1, p2, p3, x1, x2, x3, y1, y2, y3, d, x2n;
    x1:=car p1; y1:=cdr p1;
    x3:=car p3; y3:=cdr p3;
    d := (x3-x1)*0.5; x2n:=x1+d;
    for i:=1:5 do
    << d:=d*0.5; x2:= x2n;
       if null(y2 := plotevalform(ff,f,{x.x2}))
          or eqcar(y2,'overflow)
          or y2 < minv or y2 > maxv
        then x2n := x2n - d
        else << p2 := (x2 . y2); x2n := x2n + d>>
    >>;
   if null p2 then return nil;

    % generate uniform maxima/minima
    x2 := car p2; y2 := cdr p2;
    y2 := if (eqcar(y2,'overflow) and cdr y2<0) or y2<minv 
          then minv 
     else if eqcar(y2,'overflow) or y2>maxv then maxv else y2;
    return (x2 . y2)
end;

endmodule;   % plotexp2

module pltpara; % Computing parametric curve.
                 % (x,y) = (x(t),y(t))
                 %     or
                 % (x,y,z) = (x(t),y(t),z(t))
                 %     or
                 % (x,y,z) = (x(t,u),y(t,u),z(t,u))

% Author: Herbert Melenk, ZIB Berlin.

symbolic procedure plotevalpara1(x);
  begin scalar xlo,xhi,ylo,yhi,rx,ry,fcn,fcns,pts;
     rx:=plotrange(x,
       reval(plot_xrange or '(!*interval!* -10 10)));
     xlo:=car rx;
     xhi:=cadr rx;
     fcns:= reverse plotfunctions!*;
     % ry:=plotrange(y, reval(plot_yrange or nil));
     if ry then <<ylo:=car ry; yhi:=cadr ry>>;
     while fcns do
     <<fcn := cddar fcns; fcns := cdr fcns;
       pts:=plotevalpara11(fcn,x,xlo,xhi).pts;
     >>;
     if length fcn=2 then  plotdriver(plot!-2exp,'x,'y,list pts,nil)
        else plotdriver(plot!-3exp!-reg,'x,'y,'z,pts)
   end;

symbolic procedure plotevalpara11(fm,x,xlo,xhi);
   begin scalar plotsynerr!*,l,d,d0,u,v,p,fl;
        scalar plotderiv!*;
        integer nx;
    fl:= for each f in fm collect rdwrap f.f;
    p:=float (nx:=plot!-points(x));
    d:=(d0:=(xhi-xlo))/p;
    v:=xlo;
    for i:=0:nx  do
     <<u:= for each f in fl collect plotevalform(car f,cdr f,{x.v});
       if plotsynerr!* then typerr(fm,"function to plot");
       if smemq('overflow,u) then u:=nil;
       l:=u.l;
       v:=v+d;
     >>;
    return reversip l;
   end;

symbolic procedure plotevalpara2(x,y);
  begin scalar xlo,xhi,ylo,yhi,rx,ry,fcn,fcns,pts;
     rx:=plotrange(x,
       reval(plot_xrange or '(!*interval!* -10 10)));
     xlo:=car rx; xhi:=cadr rx;
     fcns:= reverse plotfunctions!*;
     ry:=plotrange(y, 
       reval(plot_yrange or '(!*interval!* -10 10)));
     ylo:=car ry; yhi:=cadr ry;
     fcn := cddar fcns; fcns := cdr fcns;
     if length fcn neq 3 then typerr(cdar fcns,"function to plot");
     pts:=plotevalpara21(fcn,x,xlo,xhi,y,ylo,yhi);
     plotdriver(plot!-3exp!-reg,'x,'y,'z,pts)
   end;

symbolic procedure plotevalpara21(fm,x,xlo,xhi,y,ylo,yhi);
   begin scalar plotsynerr!*,l,ll,dx,dy,u,v,p,fl,w;
        scalar plotderiv!*;
        integer nx,ny;
    fl:= for each f in fm collect rdwrap f.f;
    p:=float(nx:=plot!-points(x));
    dx:=(xhi-xlo)/p; 
    p:=float(ny:=plot!-points(y));
    dy:=(yhi-ylo)/p;
    v:=xlo;
    for i:=0:nx  do
     <<w:= ylo; l:=nil;
       for j:=0:ny do 
       <<u:= for each f in fl collect 
              plotevalform(car f,cdr f,{x.v,y.w});
         if plotsynerr!* then typerr(fm,"function to plot");
         if smemq('overflow,u) then u:=nil;
         l:=u.l;
         w:=w+dy
       >>;
       v:=v+dx;
       ll:=l.ll;
     >>;
    return ll;
   end;

endmodule;

module plotexp3; % Computing surface z=f(x,y) with regular grid.

% Author: Herbert Melenk, ZIB Berlin.

% A rectangular grid is encoded as list of rows.
% A row is a list of points.
% A point is a list {v,h,x,y,z} where
%   z,y are the coordinates and z is the function value.
% The boolean values v ("vertical" = y direction) and 
%    h ("horizontal" = x direction) are true, 
%   if the connection to the neighbour point in that
%   direction is valid, nil if the connection is broken.

symbolic procedure ploteval3xy(x,y,z);
  begin scalar rx,ry,rz,f,fcn;     
     rx:=plotrange(x,
      reval(plot_xrange or '(!*interval!* -10 10)));
     ry:=plotrange(y,
      reval(plot_yrange or '(!*interval!* -10 10)));
     rz:=plotrange(z, reval(plot_zrange or nil));
     fcn := car reverse plotfunctions!*;
     if z='implicit then 
       return ploteval2xyimpl(rx,ry,fcn,x,y);
     f:= if eqcar(fcn,'points) then caddr fcn else
        ploteval3xy1(cdar plotfunctions!*,
         z,if rz then car rz, if rz then cadr rz,
         x,car rx,cadr rx,
         y,car ry,cadr ry);
     plotdriver(plot!-3exp!-reg,x,y,z,f);
  end;

symbolic procedure ploteval3xy1(f,z,zlo,zhi,x,xlo,xhi,y,ylo,yhi);
   begin scalar u,l,ll,ff,p,r,w;
%        scalar x1,x2,y1,y2,xx,yy,p1,p2,p3,p4,f1,f2,f3,f4;
        integer nx,ny;
     ff := rdwrap f;
     xlo:=rdwrap xlo; xhi:=rdwrap xhi;
     ylo:=rdwrap ylo; yhi:=rdwrap yhi;
     nx:=plot!-points(x); ny:=plot!-points(y);
       % compute the basic grid.
     r:=ploteval3xy1pts(f,ff,z,zlo,zhi,x,xlo,xhi,nx,y,ylo,yhi,ny);
     l:=cdr r;
     w:=car r;
     r:={l};
        % create refined environments for the bad points
     for each q in w do
      r:=cdr 
       ploteval3xy1pts(f,ff,z,zlo,zhi,x,car q,cadr q,4,y,caddr q,
		       cadddr q,4)
         .r;
%       % look for singularities or points of big variation
%     ll:=l;
%     while ll and cdr ll do
%     <<p := pair(car ll,cadr ll); ll:=cdr ll;
%       while p and cdr p do 
%       <<p1:=caar p; p2:=caadr p; p3:=cdar p; p4:=cdadr p; p:=cdr p;
%         if (f1:=car cdddr p1) and (f2:=car cdddr p2)
%                 and (f3:=car cdddr p3) and (f4:=car cdddr p4) then
%         <<xx:=((x1:=caddr p1) + (x2:=caddr p2))*0.5;
%           yy:=((y1:=cadddr p1) + (y2:=cadddr p3))*0.5;
%           u:=plotevalform(ff,f,{x . xx,y . yy});
%           if null u or eqcar(u,'overflow) or
%             numberp u and abs u > (abs f1+abs f2+abs f3+abs f4)*0.5
%              then 
%              <<r:=cdr
%                    ploteval3xy1pts(f,ff,z,zlo,zhi,x,x1,x2,3,y,y1,y2,3)
%                 .r;
%                   % cut connections
%                %car p1:= nil; cadr p1:= nil; 
%              >>;
%         >>;
%       >>;
%     >>;
     return ploteval3xy3 r;
   end;

symbolic procedure ploteval3xy1pts
          (f,ff,z,zlo,zhi,x,xlo,xhi,nx,y,ylo,yhi,ny);
  % Compute orthogonal graph over ordinary grid. Return additionally
  % a list of inner rectangles with singular points.  
   begin scalar u,dx,dy,xx,yy,l,w;
     dx:=float(xhi-xlo)/float(nx);
     dy:=float(yhi-ylo)/float(ny);
     l:=
     for j:=0:nx collect
     <<
       for i:=0:ny collect
       <<
        xx:=(xlo+i*dx); yy:=(ylo+j*dy);
        u:=plotevalform(ff,f,{x . xx,y . yy});
        if null u or eqcar(u,'overflow) 
         or numberp u and
             (zhi and u>zhi or zlo and u<zlo) then
        <<u:=nil;
          if 0<j and j<nx and 0<i and i<ny then
             w:={xx-dx,xx+dx,yy-dy,yy+dy}.w;
        >>;
        {t,t,xx,yy,u}
       >>
     >>;
     return w.l;
   end;

symbolic procedure ploteval3xy2 l;
    ploteval3xy3 {l};

symbolic procedure ploteval3xy3 ll;
  % Decompose ll into maximal regular grids.
 begin scalar l,lr,c,w,y,r,nw;
       integer n,m;
   while ll do
   <<l:=car ll; ll:=cdr ll;
       % find stripe with maximal lower left rectangle.
     w:={car l,cadr l}; l:=cdr l; 
     n:=min(ploteval3xybkpt(car w,0,nil),     % hor. only
            ploteval3xybkpt(cadr w,0,t));     %  hor. and vert
     c := t;
     while c and l and cdr l do
     <<m:=ploteval3xybkpt(cadr l,0,t);
       if izerop n and izerop m or n #>0 and not(n #> m) then
          <<l:= cdr l; w:=nconc(w,{car l})>>
       else c:=nil;
     >>;
     if cdr l then ll:=l . ll;
       % cut off subnet
     l:=nil; r:=nil; nw:=nil;
     for each row in w do
     <<if izerop n then row := cdr row
        else
       r:=(for i:=1:n collect <<y:=cddar row; row:=cdr row; y>>).r;
       if row then nw:=row.nw;
     >>;
     nw:= reversip nw;
        %print n;print{"streifen",length w,cddr caar w,
        %      cddr lastcar lastcar w};
        %print "gut";print r;print "rest";print nw;
        %if yesp "kill" then rederr "schluss";
     if nw then ll:=nw.ll;
     if r and cdr r then lr:=r.lr;
    >>;
    return lr;
  end;
          
symbolic procedure ploteval3xybkpt(w,n,m);
  % m=t: look for horizontal and vertical interrupts. Otherwise
  % look only for horizontal interrupts.
   if null w then n else
   if nil memq cddar w then n    % undefined point
    else
   if null cadar w               % x - break.
        or (m and null caar w)   % y - break
      then n+1 else
   ploteval3xybkpt(cdr w,n#+1,m);

endmodule;

module plotimp2; % Implicit plot: compute the varity {x,y|f(x,y)=c}.

% Author: Herbert Melenk, ZIB Berlin.

% data structure: 
%
%    point = {x,y,f(x,y),t1,t2,t3,...}
%               where ti are the numbers of the triangles which
%               have this point as a node. 
%               The point list is unique - adjacent triangles share
%               the list for equal nodes. The node numbers are
%               updated in place.
%
%    triangle = {t#,p1,p2,p3}
%       triangles are stored in triangle vector by number
%

fluid '(imp2!-triacount!* imp2!-trias!* !*imp2!-trace);

imp2!-triacount!*:=0;

symbolic procedure ploteval2xyimpl(rx,ry,f,x,y);
  begin scalar ll,l,form,g;
   for each c in plot!-contour!* do
   << form := plot!-form!-prep({'difference,cdr f,c},x,y);
      l:=imp2!-plot(car rx,cadr rx, car ry,cadr ry,
                   plot!-points(nil),form);
      ll:=append(ll,l);
    >>;
    if !*show_grid and null cdr plot!-contour!* 
         then g:= imp2!-show!-meshes();
    plotdriver(plot!-2imp,x,y,ll,g,car rx,cadr rx,car ry,cadr ry);   
  end;           

symbolic procedure imp2!-init();
  << imp2!-finit();
     if null imp2!-trias!* then imp2!-trias!* :=mkxvect()>>;

symbolic procedure imp2!-finit();
  <<if imp2!-trias!* then
      for i:=0:imp2!-triacount!* do xputv(imp2!-trias!*,i,nil);
    imp2!-triacount!*:=0;
  >>;

symbolic procedure mk!-point(x0,y0,fcn); 
         {x0,y0,apply2(fcn,x0,y0)};
 
symbolic procedure imp2!-delete!-pt!-reference(i,p);
    cdr cddr p := deletip(i,cdddr p);
 
symbolic procedure mk!-tria(i,p1,p2,p3);
  % make a triangle from 3 points. If the number is given,
  % reuse it. Otherwise generate a fresh number.
  begin scalar p; integer i;
    i := i or (imp2!-triacount!* := imp2!-triacount!* #+1);
    p:={i,p1,p2,p3,imp2!-tria!-zerop!*(p1,p2,p3)};
    xputv(imp2!-trias!*,i,p);
    aconc(p1,i); aconc(p2,i); aconc(p3,i);
      if !*imp2!-trace then print!-tria("new triangle ",p);
    return p;
  end;

symbolic procedure print!-tria(tx,w);
  <<prin2 tx; prin2 car w; w:=cdr w;
    prin2l {{car car w,cadr car w,{caddr car w}},
            {car cadr w,cadr cadr w,{caddr cadr w}},
            {car caddr w,cadr caddr w,{caddr caddr w}}};
      terpri();
  >>;

symbolic procedure imp2!-tria!-zerop!*(p1,p2,p3);
 % Here I test whether the triangle contains a zero line.
  begin scalar f1,f2,f3;
    f1 := caddr p1; 
    f2 := caddr p2;
    f3 := caddr p3;
    return f1*f2 <= 0.0 or f1*f3 <= 0.0;
  end;
    
symbolic procedure imp2!-tria!-zerop(w);
 % Fast access to stored zerop property.
     cadddr cdr w;

symbolic procedure imp2!-neighbours p;
 % Compute the direct neighbours of p - the traingles which have
 % two nodes respectively one complete edge in common with p.
  begin scalar l,p1,p2,p3; integer n;
   if fixp p then p:=xgetv(imp2!-trias!*,p);
   n:= car p; p:=cdr p;
   p1:=delete(n,cdddr car p);
   p2:=delete(n,cdddr cadr p);
   p3:=delete(n,cdddr caddr p);
   l:={find!-one!-common(p1,p2),
       find!-one!-common(p2,p3),
       find!-one!-common(p3,p1)};
   while nil memq l do l:=deletip(nil,l);
   return for each w in l collect xgetv(imp2!-trias!*,w);
  end;

symbolic procedure imp2!-edge!-length(p1,p2);
  begin scalar dx,dy;
    fdeclare('imp2!-edge!-length,dx,dy);
    dx:=thefloat car p1 - thefloat car p2;
    dy:=thefloat cadr p1 - thefloat cadr p2;
    return sqrt(dx*dx + dy*dy)
  end;

symbolic procedure imp2!-tria!-surface w;
 begin scalar x1,x2,x3,y1,y2,y3,p1,p2,p3;
   fdeclare('imp2!-tria!-surface,x1,x2,x3,y1,y2,y3);
   w:=cdr w;
   x1:=car (p1:=car w); y1:=cadr p1;
   x2:=car (p2:=cadr w); y2:=cadr p2;
   x3:=car (p3:=caddr w); y3:=cadr p3;
   return abs ((0.5*(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))));
 end;
    
symbolic procedure imp2!-tria!-length w;
 begin scalar p1,p2,p3;
   w:=cdr w;
   p1:=car w; p2:=cadr w; p3:=caddr w;
   return 
    (0.3*(imp2!-edge!-length(p1,p2) 
            + imp2!-edge!-length(p2,p3)
              + imp2!-edge!-length(p3,p1)));
 end;

symbolic procedure imp2!-tria!-midpoint(w);
   <<w:= cdr w;
     {(thefloat car car w 
        + thefloat car cadr w 
           + thefloat car caddr w)/3.0, 
      (thefloat cadr car w 
        + thefloat cadr cadr w 
           + thefloat cadr caddr w)/3.0}
   >>;

symbolic procedure imp2!-tria!-goodpoint(w,fn);
 % Here I assume that there is a zero in the triangle. Compute
 % a point inside the triangle which is as close as possible
 % to the desired line, but without local recomputation of
 % function values.
 begin scalar p1,p2,p3,f1,f2,f3,s1,s2,s3;
   w:=cdr w;
   p1:=car w; p2:=cadr w; p3:=caddr w;
   if (f1:=caddr p1)=0.0 then return {car p1,cadr p1} else
   if (f2:=caddr p2)=0.0 then return {car p2,cadr p2} else
   if (f3:=caddr p3)=0.0 then return {car p3,cadr p3};
   s1:=f1<0.0; s2:=f2<0.0; s3:=f3<0.0;
   return if s1=s2 then 
       imp2!-tria!-goodpoint1(p1,f1,p3,f3,p2,f2,fn)
   else if s1=s3 then
       imp2!-tria!-goodpoint1(p1,f1,p2,f2,p3,f3,fn)
   else
       imp2!-tria!-goodpoint1(p2,f2,p1,f1,p3,f3,fn)
 end;

%symbolic procedure imp2!-tria!-goodpoint1(p1,f1,p2,f2,p3,f3,fn);
% % Now I know that f2 has the opposite sign to f1 and f3.
% % I take the linearly interpolated zero of f on p1-p2 and p2-p3
% % return their arithmetic mean value which lies inside the 
% % triangle.
%  begin scalar x1,x2,y1,y2,s;
%    fdeclare (x1,x2,y1,y2,s,f1,f2,f3);
%    s:=f1-f2; 
%    x1:=(f1*thefloat car p2  - f2*thefloat car p1)/s;
%    y1:=(f1*thefloat cadr p2 - f2*thefloat cadr p1)/s;
%    s:=f3-f2; 
%    x2:=(f3*thefloat car p2  - f2*thefloat car p3)/s;
%    y2:=(f3*thefloat cadr p2 - f2*thefloat cadr p3)/s;
%    return {(x1+x2)*0.5, (y1+y2)*0.5};
%  end;

symbolic procedure imp2!-tria!-goodpoint1(p1,f1,p2,f2,p3,f3,fn);
 % Now I know that f2 has the opposite sign to f1 and f3.
 % F1 and f3 are non-zero.
 % I use the midpoint of the p1-p3 edge and look for an
 % approximation of a zero on the connection of the midpoint 
 % and p2 using regula falsi.
  begin scalar x1,x2,y1,y2,x3,y3,s;
    fdeclare (x1,x2,x3,y1,y2,y3,s,f1,f2,f3);
    f1:=(f1+f3)*0.5; 
    x1:=(thefloat car p1  + thefloat car p3)*0.5;
    y1:=(thefloat cadr p1  + thefloat cadr p3)*0.5;
    x2:=car p2; y2:=cadr p2;
    s:=f2-f1;
    x3:=(x1*f2 - x2*f1)/s;
    y3:=(y1*f2 - y2*f1)/s;
    f3:=apply2(fn,x3,y3);
    if f2*f3>=0 then
    <<s:=f1-f3; x3:=(x3*f1-x1*f3)/s; y3:=(y3*f1-y1*f3)/s>>
      else
    <<s:=f2-f3; x3:=(x3*f2-x2*f3)/s; y3:=(y3*f2-y2*f3)/s>>;
 done:
    return{x3,y3};
  end;

symbolic procedure imp2!-tri!-refine!-one!-tria (w,fn);
 % Refine one triangle by inserting a new point in the mid
 % of the longest edge. Also, refine the triangle adjacent
 % to that edge with the same point.
  begin scalar p1,p2,p3,pn,xn,yn,new,nb,y; integer i;
    scalar x1,x2,y1,y2,d1,d2,d3,s;
    fdeclare (x1,x2,y1,y2,s,d1,d2,d3);
   if fixp w then w :=xgetv(imp2!-trias!*,w); % record.
     if !*imp2!-trace then print!-tria("refine ",w);
   i:=car w; w :=cdr w;

     % delete reference to this triangle.
   imp2!-delete!-pt!-reference(i,car w);
   imp2!-delete!-pt!-reference(i,cadr w);
   imp2!-delete!-pt!-reference(i,caddr w);
  
     % find longest edge
   d1:=imp2!-edge!-length(car w,cadr w);
   d2:=imp2!-edge!-length(cadr w,caddr w);
   d3:=imp2!-edge!-length(car w,caddr w);
   if d1>=d2 and d1>=d3 then 
     <<p1:=car w; p2:=cadr w; p3:=caddr w>>
   else if d2>=d1 and d2>=d3 then 
     <<p1:=cadr w; p2:=caddr w; p3:=car w>>
   else 
     <<p1:=car w; p2:=caddr w, p3:=cadr w>>;
    % identify the neighbour triangle.
   nb := find!-one!-common(cdddr p1,cdddr p2);
    % compute new point almost at the mid.
   s:=0.45+0.01*random(10);  
   x1:=car p1; y1:=cadr p1;
   x2:=car p2; y2:=cadr p2;
   xn:=x1*s+x2*(1.0-s);
   yn:=y1*s+y2*(1.0-s);
   pn:=mk!-point(xn,yn,fn);
construct:
    % construct new triangles
   new:=mk!-tria(i,p1,pn,p3).new;
   new:=mk!-tria(nil,p2,pn,p3).new;
    % update the neighbour, if there is one
   if null nb then return new;
   w:=nb; nb:=nil;
   if fixp w then w :=xgetv(imp2!-trias!*,w); % record.
   i:=car w; w:=cdr w;
   imp2!-delete!-pt!-reference(i,car w);
   imp2!-delete!-pt!-reference(i,cadr w);
   imp2!-delete!-pt!-reference(i,caddr w);
   
    % find the far point
   p3 := if not((y:=car w) eq p1 or y eq p2) then y else
         if not((y:=cadr w) eq p1 or y eq p2) then y else
         caddr w;
   goto construct;
  end;

%symbolic procedure imp2!-tri!-refine!-one!-tria!-center (w,fn);
% % Refine one triangle by inserting a new point in the center.
%  begin scalar p1,p2,p3,pn,xn,yn,new,nb,y; integer i;
%    scalar x1,x2,x3,y1,y2,y3;
%   fdeclare (x1,x2,x3,y1,y2,y3);
%   if fixp w then w :=xgetv(imp2!-trias!*,w); % record.
%     if !*imp2!-trace then print!-tria("refine ",w);
%   i:=car w; w :=cdr w;
%
%     % delete reference to this triangle.
%   imp2!-delete!-pt!-reference(i,car w);
%   imp2!-delete!-pt!-reference(i,cadr w);
%   imp2!-delete!-pt!-reference(i,caddr w);
%  
%    % compute center.
%   p1:=car w; p2:=cadr w; p3:=caddr w;
%   x1:=car p1; y1:=cadr p1;
%   x2:=car p2; y2:=cadr p2;
%   x3:=car p3; y3:=cadr p3;
%   xn:=(x1+x2+x3)*0.33333;
%   yn:=(y1+y2+y3)*0.33333;
%   pn:=mk!-point(xn,yn,fn);
%construct:
%    % construct new triangles
%   new:=mk!-tria(i,p1,p2,pn).new;
%   new:=mk!-tria(nil,p2,p3,pn).new;
%   new:=mk!-tria(nil,p1,p3,pn).new;
%   return new;
%  end;

symbolic procedure find!-one!-common(u,v);
  % fast equivalent to "car intersection(u,v)".
  if null u then nil else
  if memq(car u,v) then car u else
     find!-one!-common(cdr u,v);

%%%%%% Main program for implicit plot.

symbolic procedure imp2!-plot(xlo,xhi,ylo,yhi,pts,fcn);
  begin scalar p1,p2,p3,p4,sf,z;
   imp2!-init();
    % setup initial triangularization.
   p1:=mk!-point(xlo,ylo,fcn); 
   p2:=mk!-point(xhi,ylo,fcn); 
   p3:=mk!-point(xhi,yhi,fcn); 
   p4:=mk!-point(xlo,yhi,fcn); 
   mk!-tria(nil,p1,p2,p3);
   mk!-tria(nil,p1,p3,p4);
   sf:=((xhi-xlo)+(yhi-ylo))*1.5/float pts;
   z:=imp2!-plot!-refine(sf,fcn);
     if !*imp2!-trace then 
       for each w in z do print!-tria("zero triangle:",w);
if !*test_plot then print "collect";
   z:=imp2!-plot!-collect(z);
if !*test_plot then print "draw";
   z:=imp2!-plot!-draw(z,fcn);
   if not !*show_grid then imp2!-finit();
   return z;
 end;
   
symbolic procedure imp2!-plot!-refine(sflimit,fcn);
  begin scalar z,zn,w,s,limit2,again;
    integer i,j;
    limit2 := 0.15*sflimit;
   
  % In the first stage I refine all triangles until they
  % are fine enough for a coarse overview.
    again := t;

if !*test_plot then print "phase1";
phase1:
    z:=nil; again:=nil;
    for i:=imp2!-triacount!* step -1 until 1 do
    << w := xgetv(imp2!-trias!*,i);
       if imp2!-tria!-length w > sflimit then
           <<again:=t; imp2!-tri!-refine!-one!-tria (w,fcn)>>
        else if not again and imp2!-tria!-zerop w 
           then z:=car w.z;
    >>;
    j:=j #+ 1;
    if j+j #< plot!-refine!* or again then goto phase1;
 
 % Next I refine further only the triangles which contain a zero.
 % I must store in z only the numbers of triangles because these
 % may be modified as side effects by copying.

if !*test_plot then print "phase2";
phase2:
    for each w in z do
      if (s:=imp2!-tria!-length (w:=xgetv(imp2!-trias!*,w))) >limit2
	 then <<for each q in imp2!-tri!-refine!-one!-tria (w,fcn) do
		if imp2!-tria!-zerop q and not memq(car q,zn)
		  then zn:=car q.zn>>;
    z:=zn; zn:=nil;
    if z then goto phase2;

 % In the third phase I refine those critical triangles futher:
 % non-zeros with two zero neighbours. These may be turning points
 % or bifurcations.

if !*test_plot then print "phase3";
phase3:
    for i:=imp2!-triacount!* step -1 until 1 do
      imp2!-refine!-phase3(i,i,plot!-refine!*/2,fcn,limit2*0.3);

 % Return the final list of zeros in ascending order.
    z:=for i:=1:imp2!-triacount!* join
      if imp2!-tria!-zerop(w:=xgetv(imp2!-trias!*,i)) then {w};
   return z;
  end;

symbolic procedure imp2!-refine!-phase3(i,low,lev,fn,lth);
  begin scalar w; integer c; 
    if lev=0 then return nil;
    w:=if numberp i then xgetv(imp2!-trias!*,i) else i;
    if car w<low or imp2!-tria!-length w < lth then return nil;
    lev:=lev-1;
    for each q in imp2!-neighbours w do
      if imp2!-tria!-zerop q then c:=c+1;
    if imp2!-tria!-zerop w  
       then (if c eq 2 then return nil)
       else (if c #< 2 then return nil);
    for each q in imp2!-tri!-refine!-one!-tria (w,fn) do
        imp2!-refine!-phase3(q,low,lev,fn,lth);
  end;

symbolic procedure imp2!-plot!-collect(z);
   begin scalar lines,l,q,p,s;

    for each w1 in z do
       for each w2 in imp2!-neighbours w1 do
          if car w2 > car w1 and imp2!-tria!-zerop w2 then
            q:=(w1.w2) . q;
 
 lineloop:
     if null q then return lines;
     l:={caar q, (p:=cdar q)}; q:= cdr q;
      % first I extend the back end.
     while q and p do
     <<
       if(s:= atsoc(p,q)) then l:=nconc(l,{p:=cdr s}) else
       if(s:=rassoc(p,q)) then l:=nconc(l,{p:=car s});
       if s then q:=delete(s,q) else p:=nil;
     >>;

      % next I extend the front end.
     p:=car l;
     while q and p do 
     <<
       if(s:=rassoc(p,q)) then l:=(p:=car s).l else
       if(s:= atsoc(p,q)) then l:=(p:=cdr s).l;
       if s then q:=delete(s,q) else p:=nil;
     >>;

     lines := l.lines;
     goto lineloop;
   end;

symbolic procedure imp2!-plot!-draw(l,fn);
  begin scalar r,s,q;
  q:=for each w in l collect
   <<r:=nil; 
     for each q in w join
       <<s:=imp2!-tria!-goodpoint(q,fn);
         if r neq s then {r:=s}>>
   >>;
  return q;
  end;


symbolic procedure imp2!-show!-meshes();
 % generate plot of meshes;
  begin scalar d,l,w,s,p1,p2; integer i;
    i:=1;
 loop:
    w:=xgetv(imp2!-trias!*,i);
    if null w then 
    <<imp2!-finit(); return l>>;
    w:=cdr w;
    d:= {{car car w, cadr car w},
         {car cadr w,cadr cadr w},
         {car caddr w,cadr caddr w},
         {car car w, cadr car w}} ;
    while d and cdr d do
    <<p1:=car d; p2:=cadr d; d:=cdr d;
      if car p1 > car p2 then <<w:=p2;p2:=p1;p1:=w>>;
      s:={p1,p2};
      if not member(s,l) then l:=s.l
    >>;
    i:=i+1;
    goto loop;
   end;
              
endmodule; % plotimp2

module plotimp3; % Implicit plot: compute the varity {x,y,z|f(x,y,z)=0}.

% Author: Herbert Melenk, ZIB Berlin.

% data structure: cubes. 

symbolic procedure ploteval3impl(x,y,z);
  begin scalar rx,ry,rz,f,fcn;     
     rx:=plotrange(x,
      reval(plot_xrange or '(!*interval!* -10 10)));
     ry:=plotrange(y,
      reval(plot_yrange or '(!*interval!* -10 10)));
     rz:=plotrange(z, 
      reval(plot_zrange or '(!*interval!* -10 10)));
     fcn := car reverse plotfunctions!*;
     f:= ploteval3impl1(cdar plotfunctions!*,
         x,car rx,cadr rx,
         y,car ry,cadr ry,
         z,car rz,cadr rz);
     plotdriver(plot!-3exp!-reg,x,y,z,f);
  end;

symbolic procedure ploteval3impl1(f,x,xlo,xhi,y,ylo,yhi,z,zlo,zhi);
   begin scalar u,dx,dy,dz,xx,yy,zz,l,ff,pts,val,w,q,qq,pt,found,done;
        integer nx,ny,nz;
     ff := rdwrap f;
     xlo:=rdwrap xlo; xhi:=rdwrap xhi;
     ylo:=rdwrap ylo; yhi:=rdwrap yhi;
     dx:=float(xhi-xlo)/float(nx:=plot!-points(x));
     dy:=float(yhi-ylo)/float(ny:=plot!-points(y));
     dz:=float(zhi-zlo)/float(nz:=plot!-points(z));
     pts := mk!-p!-array3(nx,ny,nz);
     val:= mk!-p!-array3(nx,ny,nz);

        % Step 1: compute a complete grid in 3d.
     for i:=0:nx do
     <<
       xx:=(xlo+i*dx);
       for j:=0:ny do
       <<
        yy:=(ylo+j*dy);
        for k:=0:nz do
        <<
          zz:=(zlo+k*dz);
          p!-put3(pts,i,j,k,{xx,yy,zz});
          u:=plotevalform(ff,f,{x . xx,y . yy,z . zz});
          if eqcar(u,'overflow) then u:=1.0;
          p!-put3(val,i,j,k,u);
        >>;
       >>
     >>;
 
        % Step 2: extract zero points.
   done := t;
   while done do
   <<done := nil; w:=
     for i:=0:nx #-1 collect
      for j:=0:ny #-1 collect
      <<q:=nil; found:=nil;
       pt := p!-get3(pts,i,j,1);
       for k:=nz step -1 until 0 do
        if null found then
        <<if null q then q:=p!-get3(val,i,j,k);
          qq:=p!-get3(val,i,j,k); 
          if q and qq and q*qq <= 0.0 then
            found := if q=0.0 then caddr p!-get3(pts,i,j,k)
                else ploteval3impl3(caddr p!-get3(pts,i,j,k),qq,
                                    caddr p!-get3(pts,i,j,k#+1),q);
          if q=0.0 or qq=0.0 or not found then p!-put3(val,i,j,k,nil);
          done:=done or found;
          q:=qq;
        >>;
        {t,t,car pt,cadr pt,found}
       >>;
     if done then l:=w.l;
    >>;
    return ploteval3xy3 l;
   end;

symbolic procedure ploteval3impl3(p1,f1,p2,f2);
  % linear interpolation
  <<
    fdeclare(f1,f2,p1,p2);
    (f1*p2 - f2*p1)/(f1-f2)>>; 

endmodule;

module plotnum; % Numeric evaluation of algebraic expressions.

fluid '(plotsynerr!* ploteval!-alist2!*);

global '(!*plotinterrupts);

flag('(plus plus2 difference times times2 quotient exp expt expt!-int
       minus sin cos tan cot asin acos acot atan log),'plotevallisp);

symbolic procedure plotrounded d;
 % Switching rounded mode safely on and off.
  begin scalar o,!*protfg,c,r,!*msg;
   !*protfg:=t;
   if null d then
    <<c:=!*complex; r:=!*rounded;
      if c then <<setdmode('complex,nil); !*complex := nil>>;
      if not r and dmode!* then
          <<o:=get(dmode!*,'dname); setdmode(o,nil)>>;
      o:={o,r,!*roundbf,c,precision 0};
      if not r then <<!*rounded:=t; setdmode('rounded,t)>>;
      !*roundbf:=nil;
      if c then <<setdmode('complex,t); !*complex := t>>;
      return o;
    >>
   else
    <<
       % reconstruct the previous configuration.
      if !*complex then setdmode('complex,nil);
      if null(!*rounded:=cadr d) then setdmode('rounded,nil);
      !*roundbf:=caddr d; 
      if car(d) then setdmode(car d,t);
      if !*complex then setdmode('complex,t);
      precision car cddddr d;
    >>;
   end;

symbolic procedure adomainp u;
 % numberp test in an algebraic form.
   numberp u or (pairp u and idp car u and get(car u,'dname))
             or eqcar(u,'minus) and adomainp cadr u;

symbolic procedure revalnuminterval(u,num);
 % Evaluate u as interval; numeric bounds required if num=T.
  begin scalar l;
    if not eqcar(u,'!*interval!*) then typerr(u,"interval");
    l:={reval cadr u,reval caddr u};
    if null num or(adomainp car l and adomainp cadr l)then return l;
    typerr(u,"numeric interval");
  end;

ploteval!-alist2!*:={{'x . 1},{'y . 2}};

symbolic procedure plot!-form!-prep(f,x,y);
  % f is a REDUCE function expression depending of x and y. 
  % Compute a form which allows me to evaluate "f(x,y)" as
  % a LISP expr.
  {'lambda,'(!&1 !&2),
     {'plot!-form!-call2,mkquote rdwrap f,mkquote f,
                mkquote x,'!&1,
                mkquote y,'!&2}};

symbolic procedure plot!-form!-call2(ff,f,x,x0,y,y0);
 % Here I hack into the statically allocated a-list in order
 % to save cons cells.
  begin scalar a;
     a:=car ploteval!-alist2!*;
     car a := x; cdr a := x0;
     a:=cadr ploteval!-alist2!*;   
     car a:= y; cdr a:= y0;
     return plotevalform(ff,f,ploteval!-alist2!*);
  end;

% The following routines are used to transform a REDUCE algebraic
% expression into a form which can be evaluated directly in LISP.

symbolic procedure rdwrap f;
  begin scalar r,!*msg,!*protfg;
    !*protfg:=t;
    r:=errorset({'rdwrap1,mkquote f},nil,nil);
    return if errorp r then 'failed else car r;
  end;

symbolic procedure rdwrap1 f;
if numberp f then float f
  else if f='pi then 3.141592653589793238462643
  else if f='e then 2.7182818284590452353602987
  else if f='i and !*complex then rederr "i not LISP evaluable" 
  else if atom f then f
  else if get(car f,'dname) then rdwrap!-dm f
  else if eqcar(f, 'MINUS) then
    begin scalar x;
       x := rdwrap1 cadr f;
       return if numberp x then minus float x else {'MINUS, x}
    end
  else if eqcar(f,'expt) then rdwrap!-expt f
  else
   begin scalar a,w;
     if null getd car f or not flagp(car f,'plotevallisp)
                then typerr(car f,"Lisp arithmetic function (warning)");
     a:=for each c in cdr f collect rdwrap1 c;
     if (w:=atsoc(car f,'((plus.plus2)(times.times2)))) 
             then return rdwrapn(cdr w,a);
     return car f . a;
   end;

symbolic procedure rdwrapn(f,a);
  % Unfold a n-ary arithmetic call.
   if null cdr a then car a else {f,car a,rdwrapn(f,cdr a)};

symbolic procedure rdwrap!-dm f;
 % f is a domain element.
  if car f eq '!:RD!: then 
          if atom cdr f then cdr f else bf2flr f
  else if car f eq '!:CR!: then rdwrap!-cr f
  else if car f eq '!:GI!:
   then rdwrap!-cmplex(f,float cadr f,float cddr f)
  else if car f eq '!:DN!: then rdwrap2 cdr f
  else << plotsynerr!*:=t;
       rerror(PLOTPACKAGE, 32, {get(car f, 'DNAME),
                                "illegal domain for PLOT"})
    >>;
  
symbolic procedure rdwrap!-cr f;
  begin scalar re,im;
    re := cadr f;
    if not atom re then re := bf2flr re;
    im := cddr f;
    if not atom im then im := bf2flr im;
    return rdwrap!-cmplx(f,re,im);
  end;

symbolic procedure rdwrap!-cmplx(f,re,im);
   if abs im * 1000.0 > abs re then typerr(f,"real number") else re;

symbolic procedure plotrepart u;
   if car u eq '!:rd!: then u else
   if car u memq '(!:gi!: !:cr!:) then '!:rd!: . cadr u;

symbolic procedure rdwrap!-expt f;
  % preserve integer second argument.
  if fixp caddr f then 
     if caddr f>0 then {'expt!-int,rdwrap1 cadr f,caddr f}
       else {'quotient,1,{'expt!-int,rdwrap1 cadr f,-caddr f}}
    else {'expt,rdwrap1 cadr f, rdwrap caddr f};

symbolic procedure rdwrap2 f;
% Convert from domain to LISP evaluable value.
  if atom f then f else float car f * 10^cdr f;

symbolic procedure rdwrap!* f;
  % convert a domain element to float.
  if null f then 0.0 else rdwrap f;

symbolic procedure rdunwrap f; 
    if f=0.0 then 0 else if f=1.0 then 1 else '!:rd!: . f;

symbolic procedure expt!-int(a,b); expt(a,fix b);

symbolic procedure plotevalform(ff,f,a);
  % ff is LISP evaluable,f REDUCE evaluable.
  begin scalar u,w,!*protfg,mn,r,!*msg;
    !*protfg := t;
    if ff='failed then goto non_lisp;
    u:= errorset({'plotevalform1,mkquote ff,mkquote a},nil,nil);
    if not ploterrorp u and numberp (u:=car u) then 
    <<if abs u > plotmax!* then return plotoverflow plotmax!* else
      return u;
    >>;
 non_lisp:
    w := {'simp, mkquote
     sublis(
       for each p in a collect (car p.rdunwrap cdr p),
       f)};
    u := errorset(w,nil,nil);
    if ploterrorp u or (u:=car u) eq 'failed then return nil;
    if denr u neq 1 then return nil;
    u:=numr u;
    if null u then return 0; % Wn
    if numberp u then <<r:=float u; goto x>>;
    if not domainp u or not memq(car u,'(!:rd!: !:gi!: !:cr!:)) 
          then return nil;
    if evalgreaterp(plotrepart u, fl2rd plotmax!*) then
     return plotoverflow plotmax!* else
    if evalgreaterp(fl2rd (-plotmax!*),plotrepart u) then
     return plotoverflow (-plotmax!*);
    r:=errorset({'rdwrap!-dm,mkquote u},nil,nil);
    if errorp r or(r:=car r) eq 'failed then return nil;
  x: return if mn then -r else r;
  end;

symbolic procedure plotoverflow u;
   <<if not !*plotoverflow then 
      lprim "plot number range exceeded";
     !*plotoverflow := t;
     'overflow . u
   >> where !*protfg = nil;

symbolic procedure plotevalform0(f,a);
  (if ploterrorp u 
       then typerr(f,"expression for plot") else car u)
     where u=
   errorset({'plotevalform1,mkquote f,mkquote a},nil,nil);

%symbolic procedure plotevalform1(f,a);
% begin scalar x,w;
%  if numberp f then return float f;
%  if (x:=assoc(f,a)) then return plotevalform1(cdr x,a);
%  if not atom f and flagp(car f,'plotevallisp) then
%    return eval 
%      (car f . for each y in cdr f collect plotevalform1(y,a));
%  if not atom f then f :=
%    car f . for each y in cdr f collect prepf plotevalform2(y,a);
%  w:=simp f;
%  if denr w neq 1 or not domainp numr w then goto err;
%  return rdwrap!* numr w;
% err:
%  plotsynerr!*:=t;
%  typerr(prepsq w,"numeric value");
%end;

symbolic procedure plotevalform1(f,a);
 begin scalar x;
  if numberp f then return float f;
  if (x:=assoc(f,a)) then return plotevalform1(cdr x,a);
  if atom f then go to err;
  return if cddr f then 
     idapply(car f,{plotevalform1(cadr f,a),plotevalform1(caddr f,a)})
    else
     idapply(car f,{plotevalform1(cadr f,a)}); 
 err:
  plotsynerr!*:=t;
  typerr(prepsq f,"numeric value");
end;


%symbolic procedure plotevalform2(f,a);
% begin scalar x,w;
%  if fixp f then return f;
%  if floatp f then return rdunwrap f;
%  if (x:=assoc(f,a)) then return plotevalform2(cdr x,a);
%  if not atom f and flagp(car f,'plotevallisp) then
%    return rdunwrap eval 
%      (car f . for each y in cdr f collect plotevalform1(y,a));
%  if not atom f then f :=
%    car f . for each y in cdr f collect prepf plotevalform2(y,a);
%  w:=simp f;
%  if denr w neq 1 or not domainp numr w then goto err;
%  return numr w;
% err:
%  plotsynerr!*:=t;
%  typerr(prepsq w,"numeric value");
%end;

symbolic procedure ploterrorp u;
   if u member !*plotinterrupts 
      then rederr prin2 "***** plot killed"
    else atom u or cdr u;

endmodule;

module parray; % multidimensional arrays.

symbolic procedure mk!-p!-array3(nx,ny,nz);
  <<for i:=0:nx do iputv(w,i,mk!-p!-array2(ny,nz)); w>>
       where w=mkvect(nx#+1);

symbolic procedure mk!-p!-array2(ny,nz);
  <<for i:=0:ny do iputv(w,i,mkvect(nz#+1)); w>>
       where w=mkvect(ny#+1);

symbolic procedure p!-get3(v,i,j,k);
  igetv(igetv(igetv(v,i),j),k);

symbolic procedure p!-put3(v,i,j,k,w);
  iputv(igetv(igetv(v,i),j),k,w);

endmodule;

module xvect; % Support for vectors with adaptive length.

% Author: Herbert Melenk, ZIB-Berlin.

symbolic procedure mkxvect(); {mkvect(128)};

symbolic procedure xputv(v,n,w);
  begin scalar i,j;
    i:=iquotient(n,128); j:=iremainder(n,128);
    while(i>0) do
    <<if null cdr v then cdr v:= mkxvect();
      v:=cdr v; i:=i #- 1>>;
    iputv(car v,j,w);
    return w;
  end;

symbolic procedure xgetv(v,n);
  begin scalar i,j,w;
    i:=iquotient(n,128); j:=iremainder(n,128);
    while(i>0 and v) do
    <<v:=cdr v; i:=i #- 1>>;
    w:=if v then igetv(car v,j);
    return w
  end;

endmodule;

end;
//E*O*F plot/plot.red//

exit 0
