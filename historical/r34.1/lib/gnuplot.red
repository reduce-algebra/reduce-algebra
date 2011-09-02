module gnuplot;
 
algebraic operator family;

global '(!*plot_pipe);
switch plot_pipe;

fluid '(plotranges!* plotfunctions!* plotpipe!*
        plotstyle!* plotoptions!*);
 
global '(plotcommand plotdata plotdata2 plotheader);

share plotdata,plotdata2,plotcommand,plotheader;
 
% Some systems might prefer that the first six characters are different
% in the following file names.

if null plotdata then plotdata:= "/tmp/plotdata";
if null plotdata2 then plotdata2:= "/tmp/plotdata2";
if null plotcommand then plotcommand:="gnuplot";
 
plotheader := "";

if atom errorset('(load pipes),nil,nil) then
    <<prin2t "PIPES not supported in this installation";
      prin2t "forced to buffer plot data to file";
      !*plot_pipe := nil;
    >> else !*plot_pipe := t;

symbolic procedure plotreset();
   if !*plot_pipe and plotpipe!* then
    <<close plotpipe!*; plotpipe!*:=nil;>>;
 
symbolic operator plotreset;

% Create .. as the infix operator if not yet done.

newtok '( (!. !.) !*interval!*);
precedence .., or;
algebraic operator ..;
put('!*interval!*,'PRTCH,'! !.!.! );

symbolic procedure adomainp u;
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

symbolic procedure PlotOpenDisplay();
   begin
    if null plotpipe!* then
    if not !*plot_pipe then plotpipe!* := open(plotdata,'output)
        else <<plotpipe!* :=pipe!-open(plotcommand,'output)>>;
    if atom plotheader then <<plotprin2 plotheader; plotterpri()>>
     else if eqcar(plotheader,'list) then
      for each x in cdr plotheader do <<plotprin2 x; plotterpri()>>
     else typerr(plotheader,"gnuplot header");
   end;

symbolic procedure plotshow();
   if !*plot_pipe and plotpipe!* then
     << channelflush  plotpipe!*; >> 
    else
   <<plotprin2 "pause -1 "; plotterpri(); close  plotpipe!*;
     plotpipe!* := nil;
     if getd 'system then
       if getd 'bldmsg then
          <<prin2t "enter <ret> in order to continue REDUCE ";
            system bldmsg("%w %w",plotcommand,plotdata);>>
        else begin scalar w1,w2;   % Added for systems without bldmsg.
         w1 := explode plotcommand;
         w2 := explode plotdata;
         w1 := append(reverse cdr reverse w1,'!  . cdr w2);
         w1 := compress w1;
         prin2 "About to execute: "; prin2t w1;
         prin2t "enter <ret> in order to continue REDUCE ";
         system w1
       end>>;

% This uses !*lower to lower case on output.  This is not part of
% Standard Lisp and so will not work in many systems.

symbolic procedure plotprin2 u;
   <<prin2 u; wrs v; >> where v=wrs plotpipe!*,!*lower=t;

symbolic procedure plotterpri();
   <<terpri(); wrs v; >> where v=wrs plotpipe!*;

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
                           cadr u * (10.0 ** cddr u),nil) 
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

       
symbolic procedure ploteval u;
  <<algebraic on rounded;
    plotoptions!*:= plotranges!* := plotfunctions!* := nil;
    plotstyle!* := 'lines;
    PlotOpenDisplay();
    for each option in u do ploteval1 reval option;
    ploteval2();
    >> where dmode!* = dmode!*;
 
symbolic procedure ploteval1 option;
   begin scalar x;
     if eqcar(option,'list) and eqcar(cadr option,'family) then
         % cure the linear distribution of list parmeters in R3.4.
        ploteval1('family . for each o in cdr option collect cadr o)
         else
     if pairp option and (x:=get(car option,'plotdo)) 
             then apply(x,list option) else
     if eqcar(option,'equal) and (x:=get(cadr  option,'plotdo))
             then apply(x,list caddr option) 
       else ploteval0 option;
   end;
  
symbolic procedure plotfamily u;
   <<u := cdr u;
     if pairp u and eqcar(car u,'list) then u := cdar u;
     for each o in u do ploteval1 reval o
   >>;

put('family,'plotdo,'plotfamily);

symbolic procedure ploteval0 option;
  begin scalar l,r;
    if option memq '(
            arrow noarrow contour nocontour
            autoscale noautoscale border noborder clip noclip
            polar nopolar grid nogrid key nokey label nolabel
            logscale nologscale surface nosurface tics time notime
            zeroaxis nozeroaxis 
            hidden3d nohidden3d) then
      <<plotoptions!*:=option . plotoptions!*; return>> else
    if eqcar(option,'list) then
      <<option := cdr option;
        if option and eqcar(car option,'list) then
          return (plotfunctions!*:= 
             (nil.plotpoints option).plotfunctions!*);
        typerr(option,"plot option")
      >>;
    if not eqcar(option,'equal) then 
      <<plotfunctions!*:= (nil.option) . plotfunctions!*; return>> else
    if not idp (l:=reval cadr option) then
      rederr "illegal option in PLOT";
    r:=reval caddr option;
    if l memq '(
                 angles contour arrow
                 noarrow autoscale noautoscale cntrparam isosamples
                 label nolabel key logscale nologscale mapping offsets
                 samples size terminal tics ticslevel time view
                 xlabel xtics ylabel ytics zlabel ztics
                 ) then
      <<plotoptions!*:=(l.r).plotoptions!*; return>>;
    if eqcar(r,'!*interval!*) then
      % must be a range
     <<r:='list . revalnuminterval(r,t);
       plotranges!* := (l . r) . plotranges!*>>
      else
       plotfunctions!* := (l . r) . plotfunctions!*;
  end;

symbolic procedure plotpoints u;
  begin scalar f,fn,of,dim,y;
     fn :=  plotdata2;
     dim := length car u -1;
     f := open(fn,'output);
     of := wrs f;
     for each x in u do
     <<x := cdr x;
       while x do
       <<y:= car x; x:= cdr x;
         writepri(" ",nil);
         writepri(mkquote y,if null x then 'last);
       >>;
     >>;
     wrs of;
     close f;
     return if dim=2 then {'file,fn,'x} else {'file,fn,'x,'y};
  end;
 
symbolic procedure ploteval2 ();
   % all options are collected now;
  begin scalar ivars;
   for each u in plotfunctions!* do ivars := plotindepvars(cdr u,ivars);
      % classify
   if ivars='(x) then ploteval2x() else
   if plotseteq('(x y),ivars) then ploteval3xy() else
   if plotseteq('(t),ivars) and length plotfunctions!* = 2 then 
             ploteval2t() else
   if plotseteq('(u v),ivars)
      and length plotfunctions!* = 3 then ploteval3uv()
    else typerr('list . for each p in plotfunctions!* collect 
                         if null car p then cdr p else
                         {'equal,car p,cdr p},
                " plot option or function");
   plotshow();
  end;
 

symbolic procedure plotinterval u;
   <<plotprin2 " [";
     plotprinexpr(car u);
     plotprin2 ":";
     plotprinexpr(cadr u);
     plotprin2 "]\";
     plotterpri();>>;
   
symbolic procedure plotoptions();
  <<if not 'polar memq plotoptions!* then
      plotoptions!* := 'nopolar . plotoptions!*;
  for each x in plotoptions!* do
    <<plotprin2 "set ";
      if idp x then plotprin2 x else
      <<plotprin2 car x; plotprin2 " "; plotprin2 cdr x>>;
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

symbolic procedure ploteval2x();
  begin scalar u;
     plotoptions!* := 'noparametric .  plotoptions!*;
     plotoptions();
     plotprin2 "plot ";
     u:=assoc('x,plotranges!*);
     if u then plotinterval(cddr u) else plotinterval '(-10 10);
     u:=assoc('y,plotranges!*);
     if u then plotinterval(cddr u);
     plotfunctions!* := reverse plotfunctions!*;
     while plotfunctions!* do
     <<plotprinexpr(cdar plotfunctions!*);
       plotfunctions!* := cdr plotfunctions!*;
       if plotfunctions!* then 
         <<plotprin2 ",\"; plotterpri();>>;
     >>;
     plotstyle1();
     plotterpri();
  end;
     
symbolic procedure ploteval2t();
  begin scalar u,v;
     plotoptions!* := 'parametric .  plotoptions!*;
     plotoptions();
     plotprin2 "plot ";
     u:=assoc('t,plotranges!*);
     if u then plotinterval(cddr u) else plotinterval '(-10 10);
     u:=assoc('x,plotranges!*);
     if u then plotinterval(cddr u);
     u:=assoc('y,plotranges!*);
     if u then plotinterval(cddr u);
     u:=assoc('x,plotfunctions!*);
     v:=assoc('y,plotfunctions!*);
     if null u or null v then 
        rederr "parametric curve must be given by 2 equations";
     plotprinexpr(cdr u);
     plotprin2 ",";
     plotprinexpr(cdr v);
     plotstyle1();
     plotterpri();
  end;

symbolic procedure ploteval3uv();
  begin scalar u,v,w;
     plotoptions!* := 'parametric .  plotoptions!*;
     plotoptions();
     plotprin2 "splot ";
     u:=assoc('u,plotranges!*);
     if u then plotinterval(cddr u) else plotinterval '(-10 10);
     u:=assoc('v,plotranges!*);
     if u then plotinterval(cddr u) else plotinterval '(-10 10);
     u:=assoc('x,plotranges!*);
     if u then plotinterval(cddr u);
     u:=assoc('y,plotranges!*);
     if u then plotinterval(cddr u);
     u:=assoc('z,plotranges!*);
     if u then plotinterval(cddr u);
     u:=assoc('x,plotfunctions!*);
     v:=assoc('y,plotfunctions!*);
     w:=assoc('z,plotfunctions!*);
     if null u or null v or null w then
        rederr "parametric surface must be given by 3 equations";
     plotprinexpr(cdr u);
     plotprin2 ",";
     plotprinexpr(cdr v);
     plotprin2 ",";
     plotprinexpr(cdr w);
     plotstyle1();
     plotterpri();
  end;

symbolic procedure ploteval3xy();
  begin scalar u;
     plotoptions!* := 'noparametric .  plotoptions!*;
     plotoptions();
     plotprin2 "splot ";
     u:=assoc('x,plotranges!*);
     if u then plotinterval(cddr u) else plotinterval '(-10 10);
     u:=assoc('y,plotranges!*);
     if u then plotinterval(cddr u) else plotinterval '(-10 10);
     u:=assoc('z,plotranges!*);
     if u then plotinterval(cddr u);
     plotfunctions!* := reverse plotfunctions!*;
     while plotfunctions!* do
     <<plotprinexpr(cdar plotfunctions!*);
       plotfunctions!* := cdr plotfunctions!*;
       if plotfunctions!* then
         <<plotprin2 ",\"; plotterpri();>>;
     >>;
     plotstyle1();
     plotterpri();
  end;


symbolic procedure plotseteq(u,v);
    null u and null v or car u member v 
       and plotseteq(cdr u,delete(car u,v));

symbolic procedure plotindepvars(u,v);
    if idp u then if member(u,v) or member(u,'(e pi)) then v 
                    else if u member '(x y u v r t) then u . v 
                    else typerr(u,"option or free variable in PLOT")
    else if eqcar(u,'file) then cddr u 
    else if pairp u then
      if get(car u,'dname) then v else
      if member(car u,'(plus minus difference times quotient expt)) or
         get(car u,'!:RD!:) then 
           <<for each x in cdr u do v:=plotindepvars(x,v); v>>
     else typerr(u,"expression in function to plot")
    else v;

symbolic procedure plottitle option;
  <<plotprin2 "set title "; 
    plotprin2 '!";
    plotprin2 option; 
    plotprin2 '!";
    plotterpri()>>;
 
put('title,'plotdo,'plottitle);
   
symbolic procedure plotstyle option;
  if option memq'(lines points linespoints impulses dots errorbars)
     then plotstyle!* := option
  else typerr(caddr option, "plot style option");

put('style,'plotdo,'plotstyle);

put('plot,'psopfn,'ploteval);
 
endmodule;
 
end;
