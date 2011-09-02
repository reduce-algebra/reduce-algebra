module gnuplot;  % REDUCE interace for gnuplot graphics.

create!-package('(gnuplot rgpunx rgpdos gnuplot2),'(contrib plot));

global '(!*plotusepipe !*plotpause plotdta!* plotdta!*2 plotmax!*
         plotmin!* plotcmds!* plotcommand!* plotheader!* 
         plotcleanup!* plottmp!* lispsystem!* !*plotinterrupts);

endmodule;

module rgpunx.red; % REDUCE-gnuplot configuration for UNIX/PSL

flag('(cond),'eval);  % for system dependent compilation

global '(plottemp!*);

if 'psl member lispsystem!* and 'unix member lispsystem!* then
<<
   !*plotusepipe:=t;               % pipes: yes
   load pipes;
   !*plotpause:=nil;                 % pause: no
   plottemp!* := "/tmp/";
   if getenv "LOGNAME" then
      plottemp!* := bldmsg("%w%w.",plottemp!*,getenv "LOGNAME")
    else if getenv "USER" then
      plottemp!* := bldmsg("%w%w.",plottemp!*,getenv "USER");
   plotdta!* := bldmsg("%wplotdta!*",plottemp!*); % scratch data files
   plotdta!*2:= bldmsg("%wplotdta*2",plottemp!*);
   plotcmds!* :=bldmsg("%wplotcmds*",plottemp!*); % if pipes not accessible
   plotcommand!* :=  if getenv "gnuplot" then 
      bldmsg("cd %w/;gnuplot",getenv "gnuplot") else 
      bldmsg("cd %w/plot/;gnuplot",getenv "reduce");
   plotheader!* :=  "set term x11";  % header: set terminal to X11
   plotcleanup!* :=                  % delete scratch files
       {"rm /tmp/plotdt*","rm /tmp/plotcmds!*"};
   !*plotinterrupts := '(10002);
>>;

remflag('(cond),'eval); 

endmodule;

module rgpdos; %  REDUCE-gnuplot configuration for DOS,Windows,OS2/PSL.

fluid '(!*!*windows);

flag('(cond),'eval); 

if 'psl member lispsystem!* and
        intersection('(dos os2 winnt),lispsystem!*) then
<<
   plottmp!* := getenv "tmp" or getenv "temp" or "c:\";
   !*plotpause:=nil;                       % no pause 
   plotdta!* := bldmsg("%w\plotdta",plottmp!*);          
   plotdta!*2:= bldmsg("%w\plotdta2",plottmp!*);

   if !*!*windows eq 1 or getenv("OS") = "Windows NT" then
   <<    
      % for windows:
      %  use plot pipe
     load pipes;
     !*plotusepipe:=t;     
     plotcmds!* := bldmsg("%w\plotcmds",plottmp!*);;           
     plotcommand!* := bldmsg(
       "%w\plot\wgnuplot.exe;wgnuplot_parent;wgnuplot_text",
        getenv("reduce"));
     plotheader!* := "";
    >> 
  else if getenv("system") = "OS2" then
     rederr "gnuplot for OS2 not yet available"
  else 
    <<
      % for dos:
      %   pass commands as parameter file
      %   write command file and data to directory /tmp

     !*plotusepipe:=nil;                   % no pipes
     plotcmds!* := bldmsg("%w\plotcmds",plottmp!*);
     plotcommand!* := 
     fnexpand bldmsg("$reduce\plot\gnuplot.exe %w",plotcmds!*);
     plotheader!* :=  "set term vga";
    >>;

  plotcleanup!* :=                     % delete scratch files
   {bldmsg("del %w\plotdt*",plottmp!*), 
    bldmsg("del %w",plotcmds!*)};

  plotmax!* := 3e36;                    % IEEE single precision 
  !*plotinterrupts := '(10002);
>>;

remflag('(cond),'eval); 

endmodule;

module rgpcsl.red; % REDUCE-gnuplot configuration for CSL

flag('(cond),'eval);  % for system dependent compilation

global '(plottemp!*);

if 'csl member lispsystem!* then
<<
% The following tests need to be done when GNUPLOT is loaded, since
% it may be that the module is compiled on a machine with different
% characteristics to the one on which it will eventually run.
   symbolic procedure channelflush x;
     << x := wrs x; flush(); wrs x >>;
   !*plotpause := -1;                % wait for newline from user
   plotdta!* := tmpnam();            % Files to use if pipes not available
   plotdta!*2:= tmpnam();
   plotcmds!*:= tmpnam();
% plotcleanup!* is a list of commands to be obeyed after a gnuplot run.
% it is mainly needed to get rid of the data file (used even when pipes
% are available).
   plotcleanup!* := {};
%      {bldmsg("%w %w", delcmd, plotdta!*),
%       bldmsg("%w %w", delcmd, plotdta!*2),
%       bldmsg("%w %w", delcmd, plotcmds!*)};
%
% If a shell variable "gnuplot" is set it is expected to be the
% directory within which gnuplot binaries can be found.
   plotdir!* := getenv "gnuplot";
   dirchar!* := "/";
   plotcommand!* := "gnuplot";
   opsys!* := assoc('opsys, lispsystem!*);
   if null opsys!* then opsys!* := 'unknown
   else opsys!* := cdr opsys!*;
   if opsys!* = 'win32 then <<
% For Microsoft Windows use I try to use "wgnuplot" rather than "gnuplot",
% and the options provided are copied from the PSL case above.
      plotcommand!* := "wgnuplot;wgnuplot_parent;wgnuplot_text";
      plotheader!* := "";
      dirchar!* := "\";
      plotcleanup!* :=
        {bldmsg("erase %w", plotdta!*),
         bldmsg("erase %w", plotdta!*2),
         bldmsg("erase %w", plotcmds!*)} >>
   else if opsys!* = 'msdos then <<
% Under MSDOS the PSL version sets a VGA screen explicitly - that seems to
% upset the version of gnuplot that I have to test.  Also I find "tmpnam"
% somewhat unhelpful, I can do a bit better (I hope) here.
      plotheader!* := "";      % ?? "set term vga";
      dirchar!* := "\";
      plotdta!* := "gnutmp1.tmp";
      plotdta!*2:= "gnutmp2.tmp";
      plotcmds!*:= "gnutmp3.tmp";
      plotcleanup!* := {"erase gnutmp*.tmp"} >>
   else if opsys!* = 'riscos then <<
% Under RiscOS I need to be running under the window syatem for GNUPLOT
% to be available. I will not test for that here but will expect the
% "PLOT" command to fail if run from the command line.
      plotheader!* := "";
      dirchar!* := ".";
      plotcleanup!* :=
        {bldmsg("remove %w", plotdta!*),
         bldmsg("remove %w", plotdta!*2),
         bldmsg("remove %w", plotcmds!*)} >>
   else if opsys!* = 'unix then <<
% For Unix I assume X11.
      plotheader!* := "set term x11";
      plotcleanup!* :=
        {bldmsg("rm %w", plotdta!*),
         bldmsg("rm %w", plotdta!*2),
         bldmsg("rm %w", plotcmds!*)} >>
   else <<
% Other systems set up for a dumb terminal.  This is probably unsatisfactory,
% but you can easily change the source here to adjust for what you want.
% If you just comment out the "rederr" line you will have gnuplot working
% in dumb-terminal mode.
      rederr bldmsg("gnuplot for %w not available yet", opsys!*);
      plotheader!* := "set term dumb" >>;
% If there are no pipes available gnuplot will need a command-line
% argument indicating where its input file is.
   if 'pipes member lispsystem!* then !*plotusepipe:=t
   else plotcommand!* := bldmsg("%w %w", plotcommand!*, plotcmds!*);
% If I have a directory to look for gnuplot in I either just give a
% full path or (under Unix) I temporarily switch current directories
% to there.
   if plotdir!* then <<
      if opsys!* = 'unix then
         plotcommand!* := bldmsg("pushd %w; %w ; popd",
                                 plotdir!*, plotcommand!*)
      else plotcommand!* := bldmsg("%w%w%w",
                                 plotdir!*, dirchar!*, plotcommand!*) >>;
>>;

endmodule;

module gnuplot2;
 
global '(!*plotusepipe !*trplot !*plotkeep !*plotrefine
         !*plotinterrupts); 

switch  plotusepipe;       % use pipes 

switch  trplot;            % list Gnuplot commands to REDUCE
                           % output (e.g. screen).

switch  plotkeep;          % if ON, the command and data files are
                           % not erased after calling Gnuplot.

switch  plotrefine;        % if OFF no refinments are computed
                           % for 2D plot.

global '(
        !*plotpause        % Gnuplot pause command at the end:
                           % nil: no pause
                           % -1: Gnuplot will ask the user for
                           %     a return key.
                           % number>0: Gnuplot will wait <number>
                           % seconds.


      plotcommand!*          % string: command to start gnuplot


      plotcmds!*             % file for collecting commands
        
      plotdta!* plotdta!*2     % files for collecting data
        
      plotheader!*           % list of Gnuplot commands (strings) 
                           % for initializing GNUPLOT

      plotcleanup!*          % list of system commands (strings)
                           % for cleaning up after gnuplot

      plotmax!*            % maximal floating point number which
                           % gnuplot supports on the machine
                           % (mostly IEEE double or single precision).

      plotmin!*            % lower bound (=1/plotmax!*)

      variation!*          %  defintion of y-bigstep for smooth

);

if null plotcommand!* then rederr
      " no support of GNUPLOT for this installation";


!*plotrefine:=t;

if null plotmax!* then
<< 
   load!-package 'arith;
   if not !!plumax then roundconstants();
   plotmax!* := !!plumax;     % IEEE double precision 
>>;

plotmin!*:= 1.0/plotmax!*;


fluid '(plotranges!* plotfunctions!* plotpipe!*
        plotstyle!* plotoptions!* !*plotoverflow
        !*roundbf);


symbolic procedure plotreset();
   if !*plotusepipe and plotpipe!* then
    <<  plotprin2 "exit"; plotterpri();
        close plotpipe!*; plotpipe!*:=nil;>>;
 
symbolic operator plotreset;
put('plotreset,'stat,'endstat);

% Create .. as the infix operator if not yet done.

newtok '( (!. !.) !*interval!*);
precedence .., or;
algebraic operator ..;
put('!*interval!*,'PRTCH,'! !.!.! );

global '(plot_xmesh plot_ymesh plot_xrange plot_yrange plot_zrange);
share plot_xmesh,plot_ymesh,plot_xrange,plot_yrange,plot_zrange;
plot_xmesh := 20;
plot_ymesh := 20;

fluid '(plotprecision!*);

plotprecision!* := 0.9995;

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
    if not !*plotusepipe then plotpipe!* := open(plotcmds!*,'output)
        else <<plotpipe!* :=pipe!-open(plotcommand!*,'output)>>;
    if atom plotheader!* then <<plotprin2 plotheader!*; plotterpri()>>
     else if eqcar(plotheader!*,'list) then
      for each x in cdr plotheader!* do <<plotprin2 x; plotterpri()>>
     else typerr(plotheader!*,"gnuplot header");
   end;

symbolic procedure plotshow();
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

symbolic procedure plotrounded d;
  begin scalar o;
   if null d then
    <<if dmode!* then <<o:=get(dmode!*,'dname); setdmode(o,nil)>>;
      o:={o,!*rounded,!*roundbf,!*complex,precision 0};
      !*rounded:=t; !*roundbf:=nil;
      setdmode('rounded,t);
      return o;
    >>
   else
    <<setdmode('rounded,nil);
      if car(d) then setdmode(car d,t);
      !*rounded:=cadr d;
      !*roundbf:=caddr d;
      !*complex:=cadddr d;
      precision car cddddr d;
    >>;
   end;


symbolic procedure gnuploteval u;
  begin scalar m;
    m:=plotrounded(nil);
    PlotOpenDisplay();
    for each v in u do
    <<plotprinexpr reval v; plotprin2 " ">>;
    plotterpri();
    plotrounded(m);
  end;

put('gnuplot,'psopfn,'gnuploteval);
put('plotshow,'stat,'endstat);
       
symbolic procedure ploteval u;
  begin scalar m;
    m:=plotrounded(nil);
    !*plotoverflow := nil;
    plotoptions!*:= plotranges!* := plotfunctions!* := nil;
    plotstyle!* := 'lines;
    PlotOpenDisplay();
    for each option in u do ploteval1 reval option;
    ploteval2();
    plotrounded(m);
  end;
 
symbolic procedure ploteval1 option;
   begin scalar x;
     if pairp option and (x:=get(car option,'plotdo)) 
             then apply(x,list option) else
     if eqcar(option,'equal) and (x:=get(cadr  option,'plotdo))
             then apply(x,list caddr option) 
       else ploteval0 option;
   end;
  
symbolic procedure ploteval0 option;
  begin scalar l,r;
    if option memq '(
            contour nocontour
            logscale nologscale surface nosurface 
            hidden3d) then
      <<plotoptions!*:=option . plotoptions!*; return>>;
    if eqcar(option,'list) then
      <<option := cdr option;
        if option and eqcar(car option,'list) then
          return (plotfunctions!*:= 
             ('points.plotpoints option).plotfunctions!*);
        typerr(option,"plot option")
      >>;
    if eqcar(option,'equal) and memq(cadr option,
        '(xlabel ylabel zlabel title)) then
      <<plotoptions!*:=(cadr option.caddr option). plotoptions!*; 
       return>>;
    if not eqcar(option,'equal) then 
      <<plotfunctions!*:= (nil.option) . plotfunctions!*; return>>;
    if not idp (l:=reval cadr option) then
      rederr "illegal option in PLOT";
    r:=reval caddr option;
    if l memq '(size terminal view) then
      <<plotoptions!*:=(l.r).plotoptions!*; return>>;
    if eqcar(r,'!*interval!*) then
      % must be a range
     <<r:='!*interval!* . revalnuminterval(r,t);
       plotranges!* := (l . r) . plotranges!*>>
      else
       plotfunctions!* := (l . r) . plotfunctions!*;
  end;

symbolic procedure plotpoints u;
  begin scalar f,fn,of,dim,y,w;
     fn :=  plotdta!*2;
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
  begin scalar y,z,bool;
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
  begin scalar f,fn,of,dim,y;
     fn :=  plotdta!*;
     dim := length car u -1;
     f := open(fn,'output);
     of := wrs f;
     for each x in u do
     <<for each y in x do
       << if nil member y then t else
           for each z in y do <<plotprin2number z; prin2 " ">>;
         terpri()
       >>;
       terpri();
     >>;
     wrs of;
     close f;
     return plotdta!*;
  end;

symbolic procedure plotprin2number u;
  prin2 if floatp u and abs u < plotmin!* then "0.0" else u;

symbolic procedure ploteval2 ();
   % all options are collected now;
  begin scalar dvar,ivars;
   for each u in plotfunctions!* do 
     <<dvar:=car u or dvar;
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
  apply('plotshow,nil);
  end;
 

symbolic procedure plotinterval u;
   <<plotprin2 " [";
     plotprinexpr(car u);
     plotprin2 ":";
     plotprinexpr(cadr u);
     plotprin2 "]\";
     plotterpri();>>;
   
flag ('(xlabel ylabel zlabel),'plotstring);

symbolic procedure plotoptions();
  <<if not 'polar memq plotoptions!* then
      plotoptions!* := 'nopolar . plotoptions!*;
    if not 'contour memq plotoptions!* then
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

symbolic procedure ploteval2x(x,y);
  begin scalar u,iv,xlo,xhi,ylo,yhi,rx,ry,f,fp,fcn,fcns,pts;
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
       pts:=nconc(ploteval2x1(cdr fcn,x,xlo,xhi,ylo,yhi),pts);
       if fcns then pts:=nil.pts;
     >>;
     if pts then f:=plotpoints1 pts;
     plotoptions!* := 'noparametric .  plotoptions!*;
     plotprin2lt{"set size 1,1"};
     plotprin2lt{"set xlabel ",'!",x,'!"};
     plotprin2lt{"set ylabel ",'!",y,'!"};
     plotoptions();
     plotprin2lt{"set nokey"};
     if f or fp then plotprin2 "plot ";

     if f then
     << plotprin2 "'"; plotprin2 f; plotprin2 "'";
        plotprin2 " with lines";
     >>;
     if fp then
     << if f then plotprin2 ",";
        plotprin2 "'"; plotprin2 fp; plotprin2 "'";
        plotprin2 if f then " with points" else " with lines";
     >>;
     plotterpri();
  end;

symbolic procedure ploteval2x1(f,x,xlo,xhi,ylo,yhi);
   begin scalar plotsynerr!*,l,d,d0,u,v,vv,p,mx,mn,ff;
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
       if p and not p = 0.0 then u:=u*abs p;
     >>;
    return expt(u,1/float m);
  end;
     
symbolic procedure smooth(l,ff,f,x,maxv,minv,ylo,yhi,d);
  begin scalar rat,grain,cutmax,cutmin,z,z0,p0,p1,p2,p3;
   z:=l;
   cutmax :=  yhi or (- 2*minv + 3*maxv);
   cutmin :=  ylo or (3*minv - 2*maxv);
   grain  :=  variation!* *0.05;
   rat := d / if maxv > minv then (maxv - minv) else 1;
   while z and null cdar z do z:=cdr z;
   while z and cdr z do
   <<z0:=z; z:=cdr z;
       smooth1(z0,ff,f,x,cutmin,cutmax,grain,rat,0,8)
   >>;
   return l;
  end;

symbolic procedure smooth1(l,ff,f,x,minv,maxv,g,rat,lev,ml);
    smooth2(l,ff,f,x,minv,maxv,g,rat,lev,ml);


symbolic procedure smooth2(l,ff,f,x,minv,maxv,g,rat,lev,ml);
  if lev >= ml then % t % cdr l := {nil} . cdr l
      smooth3(l,ff,f,x,minv,maxv,g,rat,lev,ml)
    else
  if null cdar l then t else
 begin scalar p0,p1,p2,p3,x1,x2,x3,y1,y2,y3,d;
       scalar dy12,dy32,dx12,dx32,z,a,ty,w;
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
    if ploterrorp d then goto disc else d:=-car d;
    a:=abs(y3-y1)<g;
    if d > plotprecision!* and a then goto disc;

    % We have a good point, insert it with destructive replacement.
    % If the angle is greater than 8 degrees or the vertical distance
    % is too great, do a double refinement otherwise quit.
    cdr l := (x2 . y2) . cdr l;
     smooth2(cdr l,ff,f,x,minv,maxv,g,rat,lev,ml);
     smooth2(l,ff,f,x,minv,maxv,g,rat,lev,ml);
    return t;

    % Function exceeded boundaries. Try to locate the screen crossing point.
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
 begin scalar p0,p1,p2,p3,x1,x2,x3,y1,y2,y3,xt,yt,d;
       scalar x2hi,y2hi,x2lo,y2lo,dir,hidir,chi,clo;
       scalar lobound,hibound;
       integer n;
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
% Try to locate the point where we exceed minv/maxv by subdivision.
begin scalar p1, p2, p3, i1, x1, x2, x3, y1, y2, y3, d, x2n;
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

symbolic procedure plotrange(x,d);
   begin scalar y,z;
     y:=assoc(x,plotranges!*);
     y:=if y then cdr y else d;
     if y=0 or null y then % return nil;
     y:={'!*INTERVAL!*, - plotmax!*, plotmax!*};
     if not eqcar(y,'!*INTERVAL!*) then
        typerr(y,"plot range");
     return {plotevalform0(rdwrap cadr y,nil) , 
             plotevalform0(rdwrap caddr y,nil)};
   end;

symbolic procedure ploteval3xy(x,y,z);
  begin scalar rx,ry,rz,h,f,fcn;
     h:=member('hidden3d,plotoptions!*);
     rx:=plotrange(x,
      reval(plot_xrange or '(!*interval!* -10 10)));
     ry:=plotrange(y,
      reval(plot_yrange or '(!*interval!* -10 10)));
     rz:=plotrange(z, reval(plot_zrange or nil));
     fcn := car reverse plotfunctions!*;
     f:= if eqcar(fcn,'points) then caddr fcn else
        ploteval3xy1(cdar plotfunctions!*,
         z,if rz then car rz, if rz then cadr rz,
         x,car rx,cadr rx,
         y,car ry,cadr ry,h);
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
     plotoptions();
     plotprin2lt{"set key"};
     plotprin2 "splot ";
     plotprin2 "'"; plotprin2 f; plotprin2 "'";
     plotprin2 " with lines ";
     plotterpri();
     plotprin2lt{"set nohidden3d"};
     plotprin2lt{"set format xy"};
  end;


symbolic procedure ploteval3xy1(f,z,zlo,zhi,x,xlo,xhi,y,ylo,yhi,h);
   begin scalar u,dx,dy,datafile,cmdfile,xx,yy,l,w,ff;
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
        if h then {u} else {xx,yy,u}
       >>
     >>;
     return plotpoints1 l;
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

symbolic procedure plotseteq(u,v);
    null u and null v or car u member v 
       and plotseteq(cdr u,delete(car u,v));

symbolic procedure plotindepvars(u,v);
    if idp u then if member(u,v) or member(u,'(e pi)) then v 
                    else  u . v 
    else if eqcar(u,'file) then cddr u 
    else if pairp u then
      if get(car u,'dname) then v else
      if member(car u,'(plus minus difference times quotient expt)) or
         get(car u,'!:RD!:) or get(car u,'simpfn)='simpiden then 
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
 

module ploteval;

fluid '(plotsynerr!*);

symbolic procedure rdwrap f;
if numberp f then float f
  else if f='pi then 3.141592653589793238462643
  else if f='e then 2.7182818284590452353602987
  else if atom f then f
  else if eqcar(f, '!:RD!:) then 
          if atom cdr f then cdr f else bf2flr f
  else if eqcar(f, '!:DN!:) then rdwrap2 cdr f
  else if eqcar(f, 'MINUS) then
    begin scalar x;
       x := rdwrap cadr f;
       return if numberp x then minus float x else {'MINUS, x}
    end
  else if get(car f, 'DNAME) then
    << plotsynerr!*:=t;
       rerror(PLOTPACKAGE, 32, {get(car f, 'DNAME),
                                "illegal domain for PLOT"})
    >>
  else if eqcar(f,'expt) then rdwrap!-expt f
  else rdwrap car f . rdwrap cdr f;

symbolic procedure rdwrap!-expt f;
  % preserve integer second argument.
  if fixp caddr f then {'expt!-int,rdwrap cadr f,caddr f}
    else {'expt,rdwrap cadr f, rdwrap caddr f};

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
  begin scalar u,w,!*protfg;
    !*protfg := t;
    u:= errorset({'plotevalform1,mkquote ff,mkquote a},nil,nil);
    if not ploterrorp u then return car u;
    w := {'reval, mkquote
     sublis(
       for each p in a collect (car p.rdunwrap cdr p),
       f)};
    u := errorset(w,nil,nil);
    if ploterrorp u then return nil;
    u:=car u;
    if numberp u then return float u;
    if not eqcar(u,'!:rd!:) then return nil;
    if evalgreaterp(u, fl2rd plotmax!*) then
     return plotoverflow plotmax!* else
    if evalgreaterp(fl2rd (-plotmax!*),u) then
     return plotoverflow (-plotmax!*)
    else return cflot u;
  end;

symbolic procedure plotoverflow u;
   <<if not !*plotoverflow then 
      lprim "gnuplot number range exceeded";
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
    car f . for each y in cdr f collect rdunwrap plotevalform1(y,a);
  w:=simp f;
  if not denr w=1 or not domainp numr w then goto err;
  return rdwrap!* numr w;
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

end;
