module plot; % device and driver independent plot services.

% Author: Herbert Melenk.
%    Adjusted by A C Norman to be compatible with CSL - the original
%    was written to be fairly PSL-specific.

create!-package('(plot),nil);

global '(

      plotdriver!*         % modulename of the actual driver.

      plotmax!*            % maximal floating point number which
                           % gnuplot supports on the machine
                           % (mostly IEEE double or single precision).

      plotmin!*            % lower bound (=1/plotmax!*)

      variation!*          %  definition of y-bigstep for smooth

      plotoptions!*        % list for collecting the options.

);

fluid '(

      plotderiv!*          %  derivative for 2d plot

);


!#if (member 'psl lispsystem!*)

macro procedure !@if u;
   <<if eval cadr u then caddr u else cadddr u>>;

!@if(errorp errorset('!*writingfaslfile,nil,nil)
         or not !*writingfaslfile
         or errorp errorset('(load fcomp),nil,nil),
       <<prin2t "no support for fast float!";
% ACN believes that the following line is just WRONG in that the
% parentheses written in (x) are ignored by the RLISP parser, to the detriment
% of the way that DM will handle things!
         dm(fdeclare,(x),nil); dm(thefloat,(x),cadr x);>>,
       nil);

!#else

symbolic macro procedure fdeclare u; nil;
symbolic macro procedure thefloat u; cadr u;

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

!*msg := t;

global '(plot_xmesh plot_ymesh plot_xrange plot_yrange plot_zrange);
share plot_xmesh,plot_ymesh,plot_xrange,plot_yrange,plot_zrange;
plot_xmesh := 20;
plot_ymesh := 20;

global'(!*plotrefine);

fluid '(plotprecision!*);

plotprecision!* := 0.9995;

switch  plotrefine;        % if OFF no refinments are computed
                           % for 2D plot.

!*plotrefine:=t;

fluid '(!*show_grid);

switch show_grid;

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
  begin scalar m;
    if null plotdriver!* then
      rederr "no active device driver for PLOT";
    m:=plotrounded(nil);
    !*plotoverflow := nil;
    plotranges!* := plotfunctions!* := nil;
    plotstyle!* := 'lines;
    plotdriver(init);
    for each option in u do ploteval1 reval option;
    ploteval2();
    plotrounded(m);
  end;

symbolic procedure ploteval1 option;
   begin scalar x,do;
     do := get(plotdriver!*,'do);
     if pairp option and (x:=get(car option,do))
             then apply(x,list option) else
     if eqcar(option,'equal) and (x:=get(cadr  option,do))
             then apply(x,list caddr option)
       else ploteval0 option;
   end;

symbolic procedure ploteval0 option;
  begin scalar l,r,opt;
    opt:=get(plotdriver!*,'option);
    if flagp(option,opt) then
      <<plotoptions!*:=option . plotoptions!*; return>>;
    if eqcar(option,'list) then
      <<option := cdr option;
        if option and eqcar(car option,'list) then
          return (plotfunctions!*:=
             ('points.plotpoints option).plotfunctions!*);
        typerr(option,"plot option")
      >>;
    if eqcar(option,'equal) and flagp(cadr option,opt) then
      <<plotoptions!*:=(cadr option.caddr option). plotoptions!*;
       return>>;
    if not eqcar(option,'equal) then
      <<plotfunctions!*:= (nil.option) . plotfunctions!*; return>>;
    l:=reval cadr option;
    r:=reval caddr option;
    if l=0 or r=0 then return
      plotfunctions!*:=('implicit.if l=0 then r else l)
                       . plotfunctions!*;
    if not idp l then rederr "illegal option in PLOT";
    if l memq '(size terminal view) then
      <<plotoptions!*:=(l.r).plotoptions!*; return>>;
    if eqcar(r,'!*interval!*) then
      % must be a range
     <<r:='!*interval!* . revalnuminterval(r,t);
       plotranges!* := (l . r) . plotranges!*>>
      else
       plotfunctions!* := (l . r) . plotfunctions!*;
  end;

symbolic procedure ploteval2 ();
   % all options are collected now;
  begin scalar dvar,ivars;
   for each u in plotfunctions!* do
     <<if car u eq 'implicit and dvar and dvar neq car u then
          rederr "mixture of implicit and regular plot not supported";
       dvar:=car u or dvar;
       ivars := plotindepvars(cdr u,ivars)>>;
      % classify
   if null dvar then
   <<dvar:='(x y z);
     for each x in ivars do dvar:=delete(x,dvar);
     if dvar then dvar:=car dvar
   >>;
   if length ivars=1 then ploteval2x(car ivars,dvar) else
   if length ivars=2 then ploteval3xy(car ivars,cadr ivars,dvar)
    else typerr('list . for each p in plotfunctions!* collect
                         if null car p then cdr p else
                         {'equal,car p,cdr p},
                " plot option or function");
  plotdriver(show);
  end;

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
      if get(car u,'dname) then v else
      if member(car u,'(plus minus difference times quotient expt)) or
         get(car u,'!:RD!:) or get(car u,'simpfn) then
           <<for each x in cdr u do v:=plotindepvars(x,v); v>>
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
     % compute algebraic derivative.
    plotderiv!*:=reval {'df,f,x};
    plotderiv!*:= if smemq('df,plotderiv!*) then nil
        else rdwrap plotderiv!* . plotderiv!*;
    ff:=rdwrap f;
    plot_xmesh := reval plot_xmesh;
    p:=float plot_xmesh;
    d:=(d0:=(xhi-xlo))/p;
    v:=xlo;
    for i:=0:plot_xmesh do
     <<vv:=if i=0 or i=plot_xmesh then v
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
     variation!* :=
     if yhi and not(yhi=plotmax!*) then (yhi-ylo) else
        ploteval2xvariation l;

    if !*plotrefine then
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
       smooth1(z0,ff,f,x,cutmin,cutmax,grain,rat,0,8)
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
    fdeclare(x1,x2,x3,y1,y2,y3,rat,d,dx12,dx32,dy12,dy32);
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
       fdeclare(x1,x2,x3,y1,y2,y3,d,hidir);
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

module plotexp3; % Computing surface z=f(x,y) with regular grid.

% Author: Herbert Melenk, ZIB Berlin.

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
   begin scalar u,dx,dy,xx,yy,l,ff;
     ff := rdwrap f;
     xlo:=rdwrap xlo; xhi:=rdwrap xhi;
     ylo:=rdwrap ylo; yhi:=rdwrap yhi;
     plot_xmesh := reval plot_xmesh;
     plot_ymesh := reval plot_ymesh;
     dx:=float(xhi-xlo)/float(plot_xmesh);
     dy:=float(yhi-ylo)/float(plot_ymesh);
     l:=
     for j:=0:plot_ymesh collect
     <<
       for i:=0:plot_xmesh collect
       <<
        xx:=(xlo+i*dx); yy:=(ylo+j*dy);
        u:=plotevalform(ff,f,{x . xx,y . yy});
        if eqcar(u,'overflow) then u:=nil;
        if null u then  % look for an isolated singularity
          u:=ploteval3xysingular(ff,f,x,xx,dx,y,yy,dy,zhi,zlo);
        u := if zhi and u>zhi then zhi else
             if zlo and u<zlo then zlo else u;
        {xx,yy,u}
       >>
     >>;
     return l;
   end;

symbolic procedure ploteval3xysingular(ff,f,x,xx,dx,y,yy,dy,zhi,zlo);
 % set up an iteration approaching a cirital point.
   <<dx:=dx/4; dy:=dy/4;
     ploteval3xysingular1(ff,f,x,xx,dx,y,yy,dy,zhi,zlo,
       plotevalform(ff,f,{x . (xx+dx), y . (yy+dy)}),0)
    >>;

symbolic procedure ploteval3xysingular1(ff,f,x,xx,dx,y,yy,dy,zhi,zlo,w,c);
  if null w then 0 else if c>8 then w else
  if w>zhi then zhi else
  if w<zlo then zlo else
  begin scalar wnew;
    dx:=dx/2; dy:=dy/2;
    wnew := plotevalform(ff,f,{x . (xx+dx), y . (yy+dy)});
    return
     if null wnew then w else
     if abs(wnew-w) <abs wnew/20 then wnew else
       ploteval3xysingular1(ff,f,x,xx,dx,y,yy,dy,zhi,zlo,wnew,c+1);
  end;

endmodule;

module plotimp2; % Implicit plot: compute the varity {x,y|f(x,y)=0}.

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

fluid '(p3!-triacount!* p3!-trias!* !*p3!-trace);

symbolic procedure ploteval2xyimpl(rx,ry,f,x,y);
  begin scalar l,form,g;
    form := plot!-form!-prep(cdr f,x,y);
    l:=p3!-plot(car rx,cadr rx, car ry,cadr ry,reval plot_xmesh,form);
    if !*show_grid then g:= p3!-show!-meshes();
    plotdriver(plot!-2imp,x,y,l,g,car rx,cadr rx,car ry,cadr ry);
  end;

symbolic procedure p3!-init();
   <<p3!-triacount!*:=0;
     p3!-trias!*:=mkxvect();
   >>;

symbolic procedure mk!-point(x0,y0,fcn);
         {x0,y0,apply2(fcn,x0,y0)};

symbolic procedure p3!-delete!-pt!-reference(i,p);
    cdr cddr p := delete(i,cdddr p);

symbolic procedure mk!-tria(i,p1,p2,p3);
  % make a triangle from 3 points. If the number is given,
  % reuse it. Otherwise generate a fresh number.
  begin scalar p; integer i;
    i := i or (p3!-triacount!* := p3!-triacount!* #+1);
    p:={i,p1,p2,p3,p3!-tria!-zerop!*(p1,p2,p3)};
    xputv(p3!-trias!*,i,p);
    aconc(p1,i); aconc(p2,i); aconc(p3,i);
      if !*p3!-trace then print!-tria("new triangle ",p);
    return p;
  end;

symbolic procedure print!-tria(tx,w);
  <<prin2 tx; prin2 car w; w:=cdr w;
    prin2l {{car car w,cadr car w,{caddr car w}},
            {car cadr w,cadr cadr w,{caddr cadr w}},
            {car caddr w,cadr caddr w,{caddr caddr w}}};
      terpri();
  >>;

symbolic procedure p3!-tria!-zerop!*(p1,p2,p3);
 % Here I test whether the triangle contains a zero line.
  begin scalar f1,f2,f3;
    f1 := caddr p1;
    f2 := caddr p2;
    f3 := caddr p3;
    return f1*f2 <= 0.0 or f1*f3 <= 0.0;
  end;

symbolic procedure p3!-tria!-zerop(w);
 % Fast access to stored zerop property.
     cadddr cdr w;

symbolic procedure p3!-neighbours p;
 % Compute the direct neighbours of p - the traingles which have
 % two nodes respectively one complete edge in common with p.
  begin scalar l,p1,p2,p3; integer n;
   if fixp p then p:=xgetv(p3!-trias!*,p);
   n:= car p; p:=cdr p;
   p1:=delete(n,cdddr car p);
   p2:=delete(n,cdddr cadr p);
   p3:=delete(n,cdddr caddr p);
   l:={find!-one!-common(p1,p2),
       find!-one!-common(p2,p3),
       find!-one!-common(p3,p1)};
   while nil memq l do l:=delete(nil,l);
   return for each w in l collect xgetv(p3!-trias!*,w);
  end;

symbolic procedure p3!-edge!-length(p1,p2);
  begin scalar dx,dy;
    fdeclare('p3!-edge!-length,dx,dy);
    dx:=thefloat car p1 - thefloat car p2;
    dy:=thefloat cadr p1 - thefloat cadr p2;
    return sqrt(dx*dx + dy*dy)
  end;

symbolic procedure p3!-tria!-surface w;
 begin scalar x1,x2,x3,y1,y2,y3,p1,p2,p3;
   fdeclare('p3!-tria!-surface,x1,x2,x3,y1,y2,y3);
   w:=cdr w;
   x1:=car (p1:=car w); y1:=cadr p1;
   x2:=car (p2:=cadr w); y2:=cadr p2;
   x3:=car (p3:=caddr w); y3:=cadr p3;
   return abs ((0.5*(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))));
 end;

symbolic procedure p3!-tria!-length w;
 begin scalar p1,p2,p3;
   w:=cdr w;
   p1:=car w; p2:=cadr w; p3:=caddr w;
   return
    (0.3*(p3!-edge!-length(p1,p2)
            + p3!-edge!-length(p2,p3)
              + p3!-edge!-length(p3,p1)));
 end;

symbolic procedure p3!-tria!-midpoint(w);
   <<w:= cdr w;
     {(thefloat car car w
        + thefloat car cadr w
           + thefloat car caddr w)/3.0,
      (thefloat cadr car w
        + thefloat cadr cadr w
           + thefloat cadr caddr w)/3.0}
   >>;

symbolic procedure p3!-tria!-goodpoint(w);
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
       p3!-tria!-goodpoint1(p1,f1,p3,f3,p2,f2)
   else if s1=s3 then
       p3!-tria!-goodpoint1(p1,f1,p2,f2,p3,f3)
   else
       p3!-tria!-goodpoint1(p2,f2,p1,f1,p3,f3)
 end;

symbolic procedure p3!-tria!-goodpoint1(p1,f1,p2,f2,p3,f3);
 % Now I know that f2 has the opposite sign to f1 and f3.
 % I take the linearly interpolated zero of f on p1-p2 and p2-p3
 % return their arithmetic mean value which lies inside the
 % triangle.
  begin scalar x1,x2,y1,y2,s;
    fdeclare (x1,x2,y1,y2,s,f1,f2,f3);
    s:=f1-f2;
    x1:=(f1*thefloat car p2  - f2*thefloat car p1)/s;
    y1:=(f1*thefloat cadr p2 - f2*thefloat cadr p1)/s;
    s:=f3-f2;
    x2:=(f3*thefloat car p2  - f2*thefloat car p3)/s;
    y2:=(f3*thefloat cadr p2 - f2*thefloat cadr p3)/s;
    return {(x1+x2)*0.5, (y1+y2)*0.5};
  end;

symbolic procedure p3!-tri!-refine!-one!-tria (w,fn);
 % Refine one triangle by inserting a new point in the mid
 % of the longest edge. Also, refine the triangle adjacent
 % to that edge with the same point.
  begin scalar p1,p2,p3,pn,xn,yn,new,nb,y; integer i;
    scalar x1,x2,y1,y2,d1,d2,d3,s;
   fdeclare (x1,x2,y1,y2,s,d1,d2,d3);
   if fixp w then w :=xgetv(p3!-trias!*,w); % record.
     if !*p3!-trace then print!-tria("refine ",w);
   i:=car w; w :=cdr w;

     % delete reference to this triangle.
   p3!-delete!-pt!-reference(i,car w);
   p3!-delete!-pt!-reference(i,cadr w);
   p3!-delete!-pt!-reference(i,caddr w);

     % find longest edge
   d1:=p3!-edge!-length(car w,cadr w);
   d2:=p3!-edge!-length(cadr w,caddr w);
   d3:=p3!-edge!-length(car w,caddr w);
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
   if fixp w then w :=xgetv(p3!-trias!*,w); % record.
   i:=car w; w:=cdr w;
   p3!-delete!-pt!-reference(i,car w);
   p3!-delete!-pt!-reference(i,cadr w);
   p3!-delete!-pt!-reference(i,caddr w);

    % find the far point
   p3 := if not((y:=car w) eq p1 or y eq p2) then y else
         if not((y:=cadr w) eq p1 or y eq p2) then y else
         caddr w;
   goto construct;
  end;

%symbolic procedure p3!-tri!-refine!-one!-tria!-center (w,fn);
% % Refine one triangle by inserting a new point in the center.
%  begin scalar p1,p2,p3,pn,xn,yn,new,nb,y; integer i;
%    scalar x1,x2,x3,y1,y2,y3;
%   fdeclare (x1,x2,x3,y1,y2,y3);
%   if fixp w then w :=xgetv(p3!-trias!*,w); % record.
%     if !*p3!-trace then print!-tria("refine ",w);
%   i:=car w; w :=cdr w;
%
%     % delete reference to this triangle.
%   p3!-delete!-pt!-reference(i,car w);
%   p3!-delete!-pt!-reference(i,cadr w);
%   p3!-delete!-pt!-reference(i,caddr w);
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

symbolic procedure p3!-plot(xlo,xhi,ylo,yhi,pts,fcn);
  begin scalar p1,p2,p3,p4,sf,z;
   p3!-init();
    % setup initial triangularization.
   p1:=mk!-point(xlo,ylo,fcn);
   p2:=mk!-point(xhi,ylo,fcn);
   p3:=mk!-point(xhi,yhi,fcn);
   p4:=mk!-point(xlo,yhi,fcn);
   mk!-tria(nil,p1,p2,p3);
   mk!-tria(nil,p1,p3,p4);
   sf:=((xhi-xlo)+(yhi-ylo))*1.5/float pts;
   z:=p3!-plot!-refine(sf,fcn);
     if !*p3!-trace then
       for each w in z do print!-tria("zero triangle:",w);
   z:=p3!-plot!-collect(z);
   return p3!-plot!-draw(z);
   return nil;
 end;

symbolic procedure p3!-plot!-refine(sflimit,fcn);
  begin scalar z,zn,w,s,limit2,again;
    integer i;
    limit2 := 0.15*sflimit;

  % In the first stage I refine all triangles until they
  % are fine enough for a coarse overview.
    again := t;
phase1:
    z:=nil; again:=nil;
    for i:=p3!-triacount!* step -1 until 1 do
    << w := xgetv(p3!-trias!*,i);
       if p3!-tria!-length w > sflimit then
           <<again:=t; p3!-tri!-refine!-one!-tria (w,fcn)>>
        else if not again and p3!-tria!-zerop w
           then z:=car w.z;
    >>;
    if again then goto phase1;

 % Next I refine further only the triangles which contain a zero.
 % I must store in z only the numbers of triangles because these
 % may be modified as side effects by copying.
phase2:
    again:=nil;
    for each w in z do
      if (s:=p3!-tria!-length (w:=xgetv(p3!-trias!*,w))) >limit2 then
       <<for each q in p3!-tri!-refine!-one!-tria (w,fcn) do
           if p3!-tria!-zerop q and not memq(car q,zn)
              then zn:=car q.zn;
         again:=t>>
      else if p3!-tria!-zerop w and not memq(car w,zn)
          then zn:=car w.zn;
    z:=zn; zn:=nil;
    if again then goto phase2;

 % In the third phase I refine those critical triangles futher:
 % non-zeros with two zero neighbours. These may be turning points
 % or bifurcations.
phase3:
    for i:=p3!-triacount!* step -1 until 1 do
      p3!-refine!-phase3(i,i,6,fcn,limit2*0.3);

 % Return the final list of zeros in ascending order.
    z:=for i:=1:p3!-triacount!* join
      if p3!-tria!-zerop(w:=xgetv(p3!-trias!*,i)) then {w};
   return z;
  end;

symbolic procedure p3!-refine!-phase3(i,low,lev,fn,lth);
  begin scalar w; integer c;
    if lev=0 then return nil;
    w:=if numberp i then xgetv(p3!-trias!*,i) else i;
    if car w<low or p3!-tria!-length w < lth then return nil;
    lev:=lev-1;
    for each q in p3!-neighbours w do
      if p3!-tria!-zerop q then c:=c+1;
    if p3!-tria!-zerop w
       then (if c eq 2 then return nil)
       else (if c #< 2 then return nil);
    for each q in p3!-tri!-refine!-one!-tria (w,fn) do
        p3!-refine!-phase3(q,low,lev,fn,lth);
  end;

symbolic procedure p3!-plot!-collect(z);
   begin scalar lines,l,q,p,s;

    for each w1 in z do
       for each w2 in p3!-neighbours w1 do
          if car w2 > car w1 and p3!-tria!-zerop w2 then
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

symbolic procedure p3!-plot!-draw(l);
  begin scalar r,s;
  return
   for each w in l collect
   <<r:=nil;
     for each q in w join
       <<s:=p3!-tria!-goodpoint q;
         if r neq s then {r:=s}>>
   >>;
  end;


symbolic procedure p3!-show!-meshes();
 % generate plot of meshes;
  begin scalar d,l,w,s,p1,p2; integer i;
    i:=1;
 loop:
    w:=xgetv(p3!-trias!*,i);
    if null w then return l;
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

module plotnum; % Numeric evaluation of algebraic expressions.

fluid '(plotsynerr!* ploteval!-alist2!*);

global '(!*plotinterrupts);

symbolic procedure plotrounded d;
 % Switching rounded mode safely on and off.
  begin scalar o,!*protfg,c,r,!*msg;
   !*protfg:=t;
   if null d then
    <<c:='!*complex; r:=!*rounded;
      if not r and not c and dmode!* then
          <<o:=get(dmode!*,'dname); setdmode(o,nil)>>;
      o:={o,r,!*roundbf,c,precision 0};
      if not r then
      <<!*rounded:=t; setdmode('rounded,t)>>;
      !*roundbf:=nil;
      return o;
    >>
   else
    <<
      !*rounded:=cadr d;
      if not caddr d then
         <<!*roundbf:=nil; setdmode('rounded,nil)>>;
      if car(d) then setdmode(car d,t);
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
  else rdwrap1 car f . rdwrap1 cdr f;

symbolic procedure rdwrap!-dm f;
 % f is a domain element.
  if car f eq '!:RD!: then
          if atom cdr f then cdr f else bf2flr f
  else if car f eq '!:CR!: then rdwrap!-cr f
  else if car f eq '!:GI!: then rdwrap!-cmplex(f,float cadr f,float cddr f)
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
  if fixp caddr f then {'expt!-int,rdwrap1 cadr f,caddr f}
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

symbolic procedure plotevalform1(f,a);
 begin scalar x,w;
  if numberp f then return float f;
  if (x:=assoc(f,a)) then return plotevalform1(cdr x,a);
  if not atom f and flagp(car f,'plotevallisp) then
    return eval
      (car f . for each y in cdr f collect plotevalform1(y,a));
  if not atom f then f :=
    car f . for each y in cdr f collect prepf plotevalform2(y,a);
  w:=simp f;
  if denr w neq 1 or not domainp numr w then goto err;
  return rdwrap!* numr w;
 err:
  plotsynerr!*:=t;
  typerr(prepsq w,"numeric value");
end;

symbolic procedure plotevalform2(f,a);
 begin scalar x,w;
  if fixp f then return f;
  if floatp f then return rdunwrap f;
  if (x:=assoc(f,a)) then return plotevalform2(cdr x,a);
  if not atom f and flagp(car f,'plotevallisp) then
    return rdunwrap eval
      (car f . for each y in cdr f collect plotevalform1(y,a));
  if not atom f then f :=
    car f . for each y in cdr f collect prepf plotevalform2(y,a);
  w:=simp f;
  if denr w neq 1 or not domainp numr w then goto err;
  return numr w;
 err:
  plotsynerr!*:=t;
  typerr(prepsq w,"numeric value");
end;

flag('(plus difference times quotient exp expt expt!-int minus
       sin cos tan cot asin acos acot atan log),'plotevallisp);

symbolic procedure ploterrorp u;
   if u member !*plotinterrupts
      then rederr prin2 "***** plot killed"
    else atom u or cdr u;

endmodule;

module xvect; % Support for vectors with adaptive length.

% Author: Herbert Melenk, ZIB-Berlin.

symbolic procedure mkxvect(); {mkvect(1024)};

symbolic procedure xputv(v,n,w);
  begin scalar i,j;
    i:=iquotient(n,1024); j:=iremainder(n,1024);
    while(i>0) do
    <<if null cdr v then cdr v:= mkxvect();
      v:=cdr v; i:=i #- 1>>;
    iputv(car v,j,w);
    return w;
  end;

symbolic procedure xgetv(v,n);
  begin scalar i,j,w;
    i:=iquotient(n,1024); j:=iremainder(n,1024);
    while(i>0 and v) do
    <<v:=cdr v; i:=i #- 1>>;
    w:=if v then igetv(car v,j);
    return w
  end;

endmodule;

module gnuplot;  % REDUCE interace for gnuplot graphics.

create!-package('(gnuplot),nil);

global '(!*plotusepipe !*plotpause plotdta!* plotdta!*2 plotmax!*
         plotmin!* plotcmds!* plotcommand!* plotheader!*
         plotcleanup!* plottmp!* lispsystem!* !*plotinterrupts
         plotoptions!* plotdriver!*);

fluid '(plotstyle!*);

plotdriver!*:='gnuplot;

put('gnuplot,'do,'gp!-do);

put('gnuplot,'option,'gp!-option);


!#if (member 'psl lispsystem!*)

   !#if (member 'unix  lispsystem!*,

      in "$reduce/plot/rgpunx.red"$

   !#elif (intersection '(dos os2 winnt alphant) lispsystem!*)

      in "$reduce\plot\rgpwin.red"$

   !#elif (member 'vms lispsystem!*)

      in "$reduce/plot/rgpvms.red"$

   !#endif

!#elif (member 'csl lispsystem!*)

   in "../cslsrc/rgpcsl.red"$

!#endif

endmodule;

%==================================================================

module gnupldrv; % main GNUPLOT driver.

% Author: Herbert Melenk.

global '(!*plotusepipe !*trplot !*plotkeep !*plotrefine
         !*plotinterrupts);

switch  plotusepipe;       % use pipes

switch  trplot;            % list Gnuplot commands to REDUCE
                           % output (e.g. screen).

switch  plotkeep;          % if ON, the command and data files are
                           % not erased after calling Gnuplot.

global '(
        !*plotpause        % Gnuplot pause command at the end:
                           % nil: no pause
                           % -1: Gnuplot will ask the user for
                           %     a return key.
                           % number>0: Gnuplot will wait <number>
                           % seconds.


      plotcommand!*          % string: command to start gnuplot


      plotcmds!*             % file for collecting commands

      plotdta!*            % files for collecting data

      plotheader!*           % list of Gnuplot commands (strings)
                           % for initializing GNUPLOT

      plotcleanup!*          % list of system commands (strings)
                           % for cleaning up after gnuplot

);

if null plotcommand!* then rederr
      " no support of GNUPLOT for this installation";


fluid '(plot!-files!* plotpipe!*);

symbolic procedure gp!-init();
   <<
    plot!-files!* := plotdta!*;
    plotoptions!*:=  nil;
    PlotOpenDisplay();
  >>;

put('gnuplot,'init,'gp!-init);

symbolic procedure plot!-filename();
   <<plot!-files!* := cdr plot!-files!*; u>>
      where u=if null plot!-files!* then
          rederr "ran out of scratch files" else car plot!-files!*;

symbolic procedure gp!-reset();
   if !*plotusepipe and plotpipe!* then
    <<  plotprin2 "exit"; plotterpri();
        close plotpipe!*; plotpipe!*:=nil;>>;

put('gnuplot,'reset,'gp!-reset);

symbolic procedure PlotOpenDisplay();
   begin
    if null plotpipe!* then
    if not !*plotusepipe then plotpipe!* := open(plotcmds!*,'output)
        else <<plotpipe!* :=pipe!-open(plotcommand!*,'output)>>;
    if null plotheader!* then nil else
    if atom plotheader!* then <<plotprin2 plotheader!*; plotterpri()>>
     else if eqcar(plotheader!*,'list) then
      for each x in cdr plotheader!* do <<plotprin2 x; plotterpri()>>
     else typerr(plotheader!*,"gnuplot header");
   end;

symbolic procedure gp!-show();
   if !*plotusepipe and plotpipe!* then
     << channelflush  plotpipe!*; >>
    else
   <<if !*plotpause then plotprin2lt{"pause ",!*plotpause};
     close  plotpipe!*;
     plotpipe!* := nil;
     if plotcommand!* then
       <<plot!-exec plotcommand!*;
         if not !*plotkeep then
            for each u in plotcleanup!* do system u;
       >>;
    >>;

put('gnuplot,'show,'gp!-show);

symbolic procedure plot!-exec u; system u;

symbolic procedure plotprin2 u;
   <<prin2 u; wrs v;
     if !*trplot then prin2 u>> where v=wrs plotpipe!*,!*lower=t;

symbolic procedure plotterpri();
   <<terpri(); wrs v;
     if !*trplot then terpri() >> where v=wrs plotpipe!*;

symbolic procedure plotprin2lt l;
   <<for each x in l do plotprin2 x; plotterpri()>>;

fluid '(plotprinitms!*);

symbolic procedure plotprinexpr u;
   begin scalar plotprinitms!*,!*lower,v;
     !*lower:=t;
     v := wrs plotpipe!*;
     plotprinitms!* := 0;
     if eqcar(u,'file) then
        <<prin2 '!"; prin2 cadr u;prin2 '!"; prin2 " ">>
     else
        errorset(list('plotprinexpr1,mkquote u,nil),nil,nil);
     wrs v;
   end;

symbolic procedure plotprinexpr1(u,oldop);
   begin scalar op;
     if plotprinitms!* > 5 then
        <<prin2 "\"; terpri(); plotprinitms!*:=0>>;
     if atom u then
        <<prin2 if u='e then 2.718281 else
                if u='pi then 3.14159 else u;
          plotprinitms!* := plotprinitms!*+1>>
          else
     if eqcar(u,'!:rd!:) then
         plotprinexpr1 (if atom cdr u then cdr u else
                           bf2flr u,nil)
          else
     if (op:=car u) memq '(plus times difference quotient expt) then
           plotprinexpr2(cdr u,get(car u,'PRTCH),
               oldop and not (op memq(oldop memq
                      '(difference plus times quotient expt)))
               ,op)
          else
     if op='MINUS then
          <<prin2 "(-";
            plotprinexpr1(cadr u,t);
            prin2 ")">>
          else
     if get(car u,'!:RD!:) then
         <<prin2 car u; plotprinexpr2(cdr u,'!, ,t,nil)>>
          else
        typerr(u," expression for printing")
   end;

symbolic procedure plotprinexpr2(u,sep,br,op);
   <<if br then prin2 " (";
     while u do
     <<plotprinexpr1(car u,op);
       u := cdr u;
       if u then prin2 sep>>;
     if br then prin2 ") "
   >>;

symbolic procedure gnuploteval u;
 % Support of explicit calls to GNUPLOT in algebraic mode.
  begin scalar m,evallhseqp!*;
    evallhseqp!* := t;
    m:=plotrounded(nil);
    PlotOpenDisplay();
    for each v in u do
    <<plotprinexpr reval v; plotprin2 " ">>;
    plotterpri();
    plotrounded(m);
  end;

put('gnuplot,'psopfn,'gnuploteval);

% Declare options which are supported by GNUPLOT:

flag ('(

          % keyword options
    contour nocontour logscale nologscale surface nosurface

          % equation type options
    hidden3d xlabel ylabel zlabel title

),'gp!-option);

put('gnuplot,'option,'gp!-option);

symbolic procedure plotpoints u;
  begin scalar f,fn,of,dim,w;
     fn := plot!-filename();
     f := open(fn,'output);
     of := wrs f;
     w:={'plotpoints0,mkquote(nil.u)};
     dim:=errorset(w,t,nil);
     wrs of;
     close f;
     if ploterrorp dim then
        rederr "failure during plotting point set";
     return if car dim=2 then {'file,fn,'x} else {'file,fn,'x,'y};
  end;

symbolic procedure plotpoints0 u;
  begin scalar z,bool;
    integer n;
   for each x in cdr u do
    if not bool and eqcar(x,'list) then n:=plotpoints0 x
      else
     <<bool:=t; n:=n#+1;
       z:=rdwrap reval x;
       if not numberp z then <<wrs nil; typerr(x,"number")>>;
       prin2 z; prin2 " ";
     >>;
   terpri();
   return n;
  end;

symbolic procedure plotpoints1 u;
  begin scalar f,fn,of,y;
     fn :=  plot!-filename();
     f := open(fn,'output);
     of := wrs f;
     for each x in u do
     <<for each y in x do
       << if null y or nil member y then t else
           for each z in y do <<plotprin2number z; prin2 " ">>;
         terpri()
       >>;
       terpri();
     >>;
     wrs of;
     close f;
     return fn;
  end;

symbolic procedure plotprin2number u;
  prin2 if floatp u and abs u < plotmin!* then "0.0" else u;


flag ('(xlabel ylabel zlabel),'plotstring);

symbolic procedure gp!-plotoptions();
  <<if not('polar memq plotoptions!*)then
      plotoptions!* := 'nopolar . plotoptions!*;
    if not('contour memq plotoptions!*)then
      plotoptions!* := 'nocontour . plotoptions!*;
  for each x in plotoptions!* do
    <<plotprin2 "set ";
      if idp x then plotprin2 x else
      <<plotprin2 car x;
        plotprin2 " ";
        if flagp(car x,'plotstring) then plotprin2 '!";
        plotprin2 cdr x;
        if flagp(car x,'plotstring) then plotprin2 '!">>;
      plotterpri()
    >>;
  >>;

symbolic procedure plotstyle1();
   if plotstyle!* then
    <<plotprin2 " \";
     plotterpri();
     plotprin2 " with ";
     plotprin2 plotstyle!*;
     plotprin2 " ";
   >>;

symbolic procedure plottitle option;
  <<plotprin2 "set title ";
    plotprin2 '!";
    plotprin2 option;
    plotprin2 '!";
    plotterpri()>>;

put('title,'gp!-do,'plottitle);

symbolic procedure plotstyle option;
  if option memq'(lines points linespoints impulses dots errorbars)
     then plotstyle!* := option
  else typerr(caddr option, "plot style option");

put('style,'gp!-do,'plotstyle);


% Drivers for different picture types.

symbolic procedure gp!-2exp(x,y,pts,fp);
  % x:   name of x coordinate,
  % y:   name of y coordinate,
  % pts: list of computed point sets,
  % fp:  list of user supplied point sets.
  begin scalar cm;
     plotoptions!* := 'noparametric .  plotoptions!*;
     plotprin2lt{"set size 1,1"};
     plotprin2lt{"set xlabel ",'!",x,'!"};
     plotprin2lt{"set ylabel ",'!",y,'!"};
     gp!-plotoptions();
     plotprin2lt{"set nokey"};
     if pts or fp then plotprin2 "plot ";

     for each f in reversip pts do
     << if cm then <<plotprin2 ",\"; plotterpri()>>;
        plotprin2 "'"; plotprin2 plotpoints1 f; plotprin2 "'";
        plotprin2 " with lines"; cm:=t;
     >>;
     if fp then
     << if cm then <<plotprin2 ",\"; plotterpri()>>;
        plotprin2 "'"; plotprin2 fp; plotprin2 "'";
        plotprin2 if cm then " with points" else " with lines";
     >>;
     plotterpri();
  end;

put('gnuplot,'plot!-2exp,'gp!-2exp);

symbolic procedure gp!-3exp(x,y,z,f);
 % x:   name of x coordinate,
 % y:   name of y coordinate,
 % z:   name of z coordinate,
 % f:   orthogonal list of point lists.
  begin scalar h;
     h:=member('hidden3d,plotoptions!*);
     if h then f:=for each l in f collect
       for each p in l collect {caddr p};
     f:=plotpoints1 f;
     plotprin2lt{"set nohidden3d"};
     if not h then plotoptions!* := 'parametric .
           delete('noparametric,plotoptions!*)
        else
            plotoptions!* := 'noparametric .
           delete('parametric,plotoptions!*);
     plotprin2lt{"set view 60,30,1,1"};
     plotprin2lt{"set size 1,1"};
     if h then plotprin2lt{"set format xy ",'!",'!"};
     plotprin2lt{"set xlabel ",'!",x,'!"};
     plotprin2lt{"set ylabel ",'!",y,'!"};
     plotprin2lt{"set zlabel ",'!",z,'!"};
     gp!-plotoptions();
     plotprin2lt{"set nokey"};
     plotprin2 "splot ";
     plotprin2 "'"; plotprin2 f; plotprin2 "'";
     plotprin2 " with lines ";
     plotterpri();
     plotprin2lt{"set nohidden3d"};
     plotprin2lt{"set format xy"};
  end;

put('gnuplot,'plot!-3exp!-reg,'gp!-3exp);

symbolic procedure gp!-2imp(x,y,l,g,xmin,xmax,ymin,ymax);
 % x,y:   names of coordinates,
 % l:     point lists for funtion,
 % g:     nil or point lists for grid,
 % xmin..ymax: minimum and maximum coordinate values.
  begin scalar f,q;
    q:={{xmin,ymin},nil,{xmin,ymax},nil,
        {xmax,ymin},nil,{xmax,ymax}};
    plotoptions!* := 'noparametric .  plotoptions!*;
    f:=plotpoints1 (q.l);
    plotprin2lt{"set size 1,1"};
    plotprin2lt{"set xlabel ",'!",x,'!"};
    plotprin2lt{"set ylabel ",'!",y,'!"};
    gp!-plotoptions();
    plotprin2lt{"set nokey"};
    plotprin2 "plot "; plotprin2  "'"; plotprin2 f; plotprin2 "'";
    plotprin2 " with lines";
    if g then
    <<plotprin2 ", '"; plotprin2 plotpoints1 g;
      plotprin2 "' with lines";
    >>;
    plotterpri();
  end;

put('gnuplot,'plot!-2imp,'gp!-2imp);

endmodule;

end;
