% Code to reset REDUCE to the initial state.
% John Fitch, Codemist Ltd 1988 <jpff@maths.bath.ac.uk>
% Given to the REDUCE community for what it is worth.
%
% The command RESETREDUCE works through the history of previous
% commands, and clears any values which have been assigned, plus any
% rules, arrays and the like.  It also sets the various switches to
% their initial values.  It is not complete, but does work for most
% things that cause a gradual loss of space.  It would be relatively
% easy to make it interactive, so allowing for selective resetting.

symbolic procedure resetreduce;
 begin
  scalar mode,statno,comm;
 % Set all switches back to initial values
 % These may vary from system to system!!
  !*algint:=nil;     !*allbranch:=t; !*allfac:=t;    !*backtrace:=nil;
                     !*comp:=nil;    !*complex:=nil; !*convert:=t;
  !*cramer:=nil;     !*cref:=nil;    !*defn:=nil;    !*demo:=nil;
  !*div:=nil;        !*echo:=nil;    !*errcont:=nil; !*exp:=t;
  !*ezgcd:=nil;      !*factor:=nil;  !*failhard:=nil;
  !*fort:=nil;       !*gcd:=nil;     !*heugcd:=nil;  !*ifactor:=nil;
  !*int:=t;          !*intstr:=nil;  !*lcm:=t;       !*list:=nil;
  !*mcd:=t;          !*modular:=nil; !*msg:=t;       !*nat:=t;
  !*nero:=nil;       !*nolnr:=nil;   !*numval:=nil;  !*output:=t;
  !*overview:=nil;   !*period:=t;    !*pgen:=nil;    !*pgwd:=nil;
  !*plap:=nil;       !*precise:=nil; !*pret:=nil;    !*pri:=t;
  !*pwrds:=t;        !*quotenewnam:=t;!*raise:=t;    !*rat:=nil;
  !*ratarg:=nil;     !*rational:=nil;                !*rationalize:=nil;
  !*ratpri:=t;       !*reduced:=nil; !*revpri:=nil;  !*savestructr:=nil;
  !*solvesingular:=t;!*time:=nil;    !*timings:=nil; !*trallfac:=nil;
  !*trfac:=nil;      !*trint:=nil;   !*rounded := nil;
  % Now work down previous inputs
  foreach stat in inputbuflis!* do <<
        statno:=car stat;
        mode:=cddr stat;
        comm:=cadr stat;
%       princ "Dealing with input "; princ statno;
%       princ " in mode "; print mode;
%       prin2t comm;
%       princ "car comm="; prin2t car comm;
        if mode='algebraic then algreset(comm)
        else if mode='symbolic then symbreset(comm)
    >>;
 inputbuflis!*:=nil
 end;

symbolic procedure algreset(comm);
 begin scalar forallfn;
    if atom comm then return nil;
    forallfn:='forall;
    if car comm='setk then remprop(cadadr comm,'avalue)
    else if car comm='arrayfn then
        foreach y in cdaddr comm do <<
            remprop(cadadr y,'dimension);
            remprop(cadadr y,'rvalue);
            remprop(cadadr y,'rtype) >>
    else if car comm='progn then foreach y in cdr comm do algreset(y)
    else if car comm='prog then foreach y in cdr comm do algreset(y)
    else if car comm='setq then nil
    else if car comm='go then nil
    else if car comm='cond then
        foreach y in cdr comm do <<
            algreset(car comm); algreset(cadr comm) >>      
    else if car comm='flag then eval('remflag . (cdr comm))
    else if car comm='de then remd cadr comm
    else if car comm='let then 
        foreach xx in cdadr comm do clear car cdaddr xx
    else if car comm='clear then nil
    else if car comm='forall and caadr cadddr cadr comm = 'let then
        foreach xx in cdadr cadddr cadr comm do
           forallfn list(cadr cadadr comm,cadr cadr cdadr comm,
                        list('clear, list('list, caddr cadr xx)))
 %   else I do not know what to do!!
 end;

symbolic procedure symbreset(comm);
  <<
    if car comm='setq then set(cadr comm,nil)
    else if car comm='progn then foreach y in cdr comm do symbreset(y)
    else if car comm='flag then eval('remflag . (cdr comm))
    else if car comm='de then remd cadr comm
%   else I do not know what to do!!
  >>;

put('resetreduce,'stat,'endstat);

end;
