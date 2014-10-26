module reset;  % Code to reset REDUCE to the initial state.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%


% John Fitch, Codemist Ltd 1988 <jpff@maths.bath.ac.uk>
% Given to the REDUCE community for what it is worth.
% Revised August 1995 for Reduce 3.6.
%
create!-package('(reset),'(contrib misc));

% The command RESETREDUCE works through the history of previous
% commands, and clears any values which have been assigned, plus any
% rules, arrays and the like.  It also sets the various switches to
% their initial values.  It is not complete, but does work for most
% things that cause a gradual loss of space.  It would be relatively
% easy to make it interactive, so allowing for selective resetting.

global '(!*asterisk !*dfprint inputbuflis!* statcounter switchlist!*);

fluid '(!*fortupper !*horner !*list !*noarg !*nosplit !*ratpri !*revpri wtl!*);

%%% For the time being (ie until the default value of all switches in all
%%% packages is properly set), set default values here
put('allbranch,'switchdefault,t);
put('allfac,'switchdefault,t);
put('anygcd,'switchdefault,t);
put('arbvars,'switchdefault,t);
put('asterisk,'switchdefault,t);
put('evallhseqp,'switchdefault,t);
put('exp,'switchdefault,t);
put('expandexpt,'switchdefault,t);
put('fulltrace,'switchdefault,t);
put('int,'switchdefault,t);
put('lcm,'switchdefault,t);
put('mcd,'switchdefault,t);
put('msg,'switchdefault,t);
put('nat,'switchdefault,t);
put('noarg,'switchdefault,t);
put('nosplit,'switchdefault,t);
put('numval,'switchdefault,t);
put('output,'switchdefault,t);
put('period,'switchdefault,t);
put('precise,'switchdefault,t);
put('prephold,'switchdefault,t);
put('pri,'switchdefault,t);
put('quotenewnam,'switchdefault,t);
put('raise,'switchdefault,t);
put('ratpri,'switchdefault,t);
put('revalp,'switchdefault,t);
put('roundall,'switchdefault,t);
put('solvesingular,'switchdefault,t);
put('varopt,'switchdefault,t);
%%% assert
put('assertstatistics,'switchdefault,t);
%%% assist
put('onespace,'switchdefault,t);
%%% cali
put('factorprimes,'switchdefault,t);
put('red_total,'switchdefault,t);
put('bcsimp,'switchdefault,t);
put('noetherian,'switchdefault,t);
%%% cgb
put('cgbfullred,'switchdefault,t);
put('tdusetorder,'switchdefault,t);
%% clprl
put('clprlverbose,'switchdefault,t);
put('clprlproject,'switchdefault,t);
%%% crack
put('allowdfint,'switchdefault,t);
%%% fide
put('prfourmat,'switchdefault,t);
put('twogrid,'switchdefault,t);
put('fulleq,'switchdefault,t);
put('centergrid,'switchdefault,t);
%%% gcref
put('gcrefall,'switchdefault,t);
%%% gentran
put('gendecs,'switchdefault,t);
put('gentranseg,'switchdefault,t);
put('makecalls,'switchdefault,t);
put('double,'switchdefault,t);
%%% guardian
put('guardian,'switchdefault,t);
put('gdqe,'switchdefault,t);
put('gdmart,'switchdefault,t);
%%% hephys/cvit
put('cviterror,'switchdefault,t);
put('cvitbtr,'switchdefault,t);
put('mymatch,'switchdefault,t);
put('cvit,'switchdefault,t);
%%% lpdo
put('lpdodf,'switchdefault,t);
put('lpdocoeffnorm,'switchdefault,t);
%%% rlfi
put('lasimp,'switchdefault,t);
%%% odesolve
put('odesolve_equidim,'switchdefault,t);
put('NoIntInt,'switchdefault,t);
put('odesolve_plus_or_minus,'switchdefault,t);
put('odesolve_load_specfn,'switchdefault,t);
put('odesolve_diff,'switchdefault,t);
%%% pm
put('semantic,'switchdefault,t);
%%% qsum
put('qgosper_down,'switchdefault,t);
put('qgosper_specialsol,'switchdefault,t);
put('qsumrecursion_down,'switchdefault,t);
%%% redlog
put('rlkapursplitequiv,'switchdefault,t);
put('rlkapurmultimon,'switchdefault,t);
put('dqeverbose,'switchdefault,t);
put('dqegradord,'switchdefault,t);
put('dqeoptqelim,'switchdefault,t);
put('dqeoptsimp,'switchdefault,t);
put('rlpcprintall,'switchdefault,t);
put('rlmrivb,'switchdefault,t);
put('rlsimplfloor,'switchdefault,t);
put('rlpasfbapprox,'switchdefault,t);
put('rlpasfgauss,'switchdefault,t);
put('rlpasfgc,'switchdefault,t);
put('rlpasfsc,'switchdefault,t);
put('rlpasfses,'switchdefault,t);
put('rlpasfconf,'switchdefault,t);
put('rlqesubi,'switchdefault,t);
put('rlqepnf,'switchdefault,t);
put('useold,'switchdefault,t);
put('usez,'switchdefault,t);
put('rlcadmc3,'switchdefault,t);
put('rlpscsgen,'switchdefault,t);
put('rlcadtv,'switchdefault,t);
put('rlcadrmwc,'switchdefault,t);
put('rlqefbslfq,'switchdefault,t);
put('psen,'switchdefault,t);
put('sfto_yun,'switchdefault,t);
put('rlsetequalqhash,'switchdefault,t);
put('talpqegauss,'switchdefault,t);
put('talpqp,'switchdefault,t);
put('rlbrop,'switchdefault,t);
put('rlbnfsac,'switchdefault,t);
put('rlqepnf,'switchdefault,t);
put('rlsiso,'switchdefault,t);
put('rlsiidem,'switchdefault,t);
put('rlsichk,'switchdefault,t);
put('rlsism,'switchdefault,t);
put('rlsipo,'switchdefault,t);
put('rltabib,'switchdefault,t);
put('rlgssub,'switchdefault,t);
put('rlgsrad,'switchdefault,t);
put('rlgsred,'switchdefault,t);
put('rlfserf,'switchdefault,t);
put('rlgsvb,'switchdefault,t);
put('rlsiatadv,'switchdefault,t);
put('rlsipd,'switchdefault,t);
put('rlsiexpl,'switchdefault,t);
put('rlsiexpla,'switchdefault,t);
put('rlsifac,'switchdefault,t);
put('rlqeheu,'switchdefault,t);
put('rldavgcd,'switchdefault,t);
put('rlsitsqspl,'switchdefault,t);
put('rlgsbnf,'switchdefault,t);
put('rlqegenct,'switchdefault,t);
put('rltnft,'switchdefault,t);
put('rlqevarsel,'switchdefault,t);
put('rlsusimult,'switchdefault,t);
put('rlsusiadd,'switchdefault,t);
put('rlcadfac,'switchdefault,t);
put('rlcaddnfformula,'switchdefault,t);
put('rlcadverbose,'switchdefault,t);
put('rlcadfasteval,'switchdefault,t);
put('rlcadpartial,'switchdefault,t);
put('rlcadtrimtree,'switchdefault,t);
put('rlcadhongproj,'switchdefault,t);
put('rlanuexdifferentrools,'switchdefault,t);
put('rlanuexgcdnormalize,'switchdefault,t);
put('rlcadte,'switchdefault,t);
put('rlcadpbfvs,'switchdefault,t);
put('rlqefb,'switchdefault,t);
put('rlxopt,'switchdefault,t);
put('rlxoptsb,'switchdefault,t);
put('rlxoptpl,'switchdefault,t);
put('rlxoptri,'switchdefault,t);
put('rlxoptses,'switchdefault,t);
put('rlhqetfcsplit,'switchdefault,t);
put('rlhqevarsel,'switchdefault,t);
put('rlhqevarselx,'switchdefault,t);
put('rlhqetheory,'switchdefault,t);
put('rlhqestrconst,'switchdefault,t);
put('rlhqegbdimmin,'switchdefault,t);
put('rlresi,'switchdefault,t);
put('rlqeasri,'switchdefault,t);
put('rlqefilterbounds,'switchdefault,t);
put('rlsid,'switchdefault,t);
put('rlsiplugtheo,'switchdefault,t);
put('rlenffacne,'switchdefault,t);
put('rlplsimpl,'switchdefault,t);
put('rlsmprint,'switchdefault,t);
%%% roots
put('multiroot,'switchdefault,t);
%%% rtrace
put('rtrace,'switchdefault,t);
%%% scope
put('ftch,'switchdefault,t);
put('algpri,'switchdefault,t);
%%% solve
put('trigform,'switchdefault,t);
%%% sum
put('zb_factor,'switchdefault,t);
%%% taylor
put('taylorautocombine,'switchdefault,t);
put('taylorprintorder,'switchdefault,t);
%%% utf8
put('utf8,'switchdefault,t);
put('utf82d,'switchdefault,t);
put('utf82dround,'switchdefault,t);
put('utf8expall,'switchdefault,t);
put('utf8diffquot,'switchdefault,t);
put('utf8pad,'switchdefault,t);
%%% xideal
put('xfullreduce,'switchdefault,t);


symbolic procedure resetreduce;
 begin
  scalar mode,statno,comm;
 % Set all switches back to initial values
  foreach sw in switchlist!* do onoff!-reset sw;
  % Now work down previous inputs
  foreach stat in inputbuflis!* do <<
        statno:=car stat;
        mode:=cadr stat;
        comm:=caddr stat;
%       princ "Dealing with input "; princ statno;
%       princ " in mode "; print mode;
%       prin2t comm;
%       princ "car comm="; prin2t car comm;
        if not atom comm then reset!-undo(comm,mode)
    >>;
 inputbuflis!*:=nil;
 % reset statement counter and prompt
 statcounter := 0;
 end;

symbolic procedure reset!-undo(comm,mode);
 % reset command by undoing it
 % start with mode-independent undo
 if car comm eq 'progn then foreach y in cdr comm do reset!-undo(y,mode)
 else if car comm eq 'prog then foreach y in cddr comm do reset!-undo(y,mode)
 else if car comm eq 'go then nil
 else if car comm eq 'cond then
     foreach y in cdr comm do <<
            reset!-undo(car comm,mode); reset!-undo(cadr comm,mode) >>
 else if car comm memq '(while repeat) then
     <<reset!-undo(cadr comm,mode); reset!-undo(caddr comm,mode)>>
 else if car comm eq 'flag then lispeval('remflag . (cdr comm))
 else if car comm eq 'put then lispeval list('remprop,cadr comm,caddr comm)
 else if car comm eq 'arrayfn then
     foreach y in cdaddr comm do <<
            remprop(cadadr y,'dimension);
            remprop(cadadr y,'rvalue);
            remprop(cadadr y,'rtype) >>
 else if car comm eq 'setel then setel(lispeval cadr comm,0)
 else if mode='algebraic then algreset(comm)
 else if mode='symbolic then symbreset(comm);

symbolic procedure algreset(comm);
 begin scalar forallfn;
    if atom comm then return nil;
    forallfn:='forall;
    if car comm eq 'setk then
        if idp cadadr comm then remprop(cadadr comm,'avalue)
         else lispeval('clear . list cadr comm)
    else if car comm eq 'setq then nil
    else if car comm eq 'setq then nil
    else if car comm eq 'de then remd cadr comm
    else if car comm eq 'let then
        foreach xx in cdadr comm do clear car cdaddr xx
    else if car comm eq 'clear then nil
    else if car comm eq 'assgnpri then algreset(cadr comm)
    else if car comm eq 'infix then
        foreach xx in cdr cadr comm do <<
               remprop(xx,'infix);
               remprop(xx,'op);
               remprop(xx,'simpfn)>>
    else if car comm eq 'wtlevel then wtlevel 1
    else if car comm eq 'weight then
        foreach xx in cdr cadr comm do
            wtl!* := delasc(!*a2kwoweight cadr lispeval xx,wtl!*)
 %   else I do not know what to do!!
 end;

symbolic procedure symbreset(comm);
  if atom comm then nil
   else <<
    if car comm eq 'setq then set(cadr comm,nil)
    else if car comm eq 'de then remd cadr comm
    else if car comm eq 'define then
        foreach xx in cdr cadr comm do remprop(cadr caddr xx,'newnam)
    else if car comm eq 'switch then
        foreach xx in cdr cadr comm do
           if car xx='list then <<remflag(cadr caddr xx,'switch);
                                  remprop(cadr caddr xx,'switchdefault)>>
            else remflag(cadr xx,'switch)
    else if car comm eq 'matrix then
        for each xx in cdr cadr comm do clear cadr cadr xx
    else if car comm eq 'operator then
        foreach xx in cdr cadr comm do remprop(cadr xx,'simpfn)
    else if car comm eq 'share then
        foreach xx in cdr cadr comm do remflag(list xx,'share)
    else if car comm eq 'infix then
        foreach xx in cdr cadr comm do
              << remprop(xx,'infix); remprop(xx,'op)>>
    else if car comm eq 'precedence then
        foreach xx in cdr cadr comm do remprop(xx,'op)
    else if car comm eq 'depend then lispeval('nodepend . cdr comm)
    else if car comm eq 'forall and caadr cadddr cadr comm memq '(let saveas) then
        foreach xx in cdadr cadddr cadr comm do
           forallfn list(cadr cadadr comm,cadr cadr cdadr comm,
                        list('clear, list('list, caddr cadr xx)))
    else if car comm eq 'saveas then lispeval('clear . cdr comm)
%   else I do not know what to do!!
  >>;

put('resetreduce,'stat,'endstat);

endmodule;

end;
