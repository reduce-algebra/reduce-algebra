module cslrend; % CSL REDUCE "back-end".

% Authors: Martin L. Griss and Anthony C. Hearn.
% Modified by Arthur Norman for use with CSL.

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

% $Id$

create!-package('(cslrend csl),nil);

fluid '(!*break
        !*echo
        !*eolinstringok
        !*int
        !*mode
        !*raise
        !*lower
        !*keepsqrts
        outputhandler!*
        !*savedef
        lispsystem!*);

global '(!$eol!$
         !*extraecho
         cr!*
         crchar!*
         date!*
         esc!*
         ff!*
         ifl!*
         ipl!*
         largest!-small!-modulus
         ofl!*
         spare!*
         statcounter
         crbuflis!*
         tab!*
         version!*
         author1!*
         author2!*
         loadable!-packages!*
         switches!*
         symchar!*);

author1!* := "A C Hearn, 2008-14";
author2!* := "Codemist Ltd, 2008-14";

% Lists of packages & switches...

% The following code arranges that the list of loadable packages
% is constructed once at compile time. That is good because at that time
% Reduce must be set up so as to have access to the path referred to
% here as "$reduce" and the package map will be within the source tree.
% Otherwise Reduce could not be being built!

symbolic macro procedure find!-loadable!-packages u;
  begin
    scalar i, w, e, r, r1;
% Configuration information is held in a file called something like
% "package.map".
    if boundp 'minireduce and symbol!-value 'minireduce then
         i := "package.map"
    else i := "$reduce/packages/package.map";
    i := open(i, 'input);
    i := rds i;
    e := !*echo;
    !*echo := nil;
    w := read();
    !*echo := e;
    i := rds i;
    close i;
% I make a list of all the packages that are tagged as suitable for use with
% CSL.
    w :=
      for each x in w conc
         if member('csl, cddr x) then list car x else nil;
% Now I delete the ones that will have already been loaded, since there
% would be no merit in loading any of those a second time.
    for each x in '(rlisp cslrend smacros poly arith alg
                    mathpr tmprint entry cslcompat user
                    cslprolo) do
      w := delete(x, w);
% Put things in alphabetic order at least to keep things neat.
    return mkquote sort(w, 'orderp)
  end;

loadable!-packages!* := find!-loadable!-packages();



% This amazingly long list of switches was created as a by-product
% of building the bootstrap version of Reduce. In that build use of
% the directive that introduces switches is logged. Not all of these switches
% are really aimed at the general public, and almost all only apply when
% some particular module is loaded.

% The extraction of this list from buildlogs/bootstrapreduce.log uses
%    grep "Declaring a switch" buildlogs/bootstrapreduce.log > ...
% followed by minor hand editing then use of sort and dups with a final
% editing pass to get the table neatly lined up.

% I could clearly automake this more thoroughly!

% This list included here was created on August 5th 2014 based on the
% development version of Reduce on that date. I rather expect that new
% flags only get added at a fairly slow rate so this list bot always
% being kept up to date noy not be a calamity.

switches!* := '(
    acinfo                    acn                       adjprec
    again                     algint                    algpri
    allbranch                 allfac                    allowdfint
    allpoly                   anticom                   anygcd
    arbvars                   arnum                     assert
    assertbreak               assertstatistics          asterisk
    backtrace                 balanced_mod              balanced_was_on
    batch_mode                bcsimp                    bezout
    bfspace                   boese                     both
    carcheckflag              carefuleq                 centergrid
    cgbcheckg                 cgbcontred                cgbcounthf
    cgbfaithful               cgbfullred                cgbgs
    cgbreal                   cgbsgreen                 cgbstat
    cgbupdb                   cgbverbose                clprlproject
    clprlverbose              coates                    combineexpt
    combinelogs               commutedf                 commuteint
    comp                      complex                   compxroots
    contract                  cramer                    cref
    cvit                      dcfsfold                  debug
    debug_times               defn                      demo
    derexp                    detectunits               dfint
    dfprint                   diffsoln                  dispjacobian
    distribute                div                       dolzmann
    double                    dqegradord                dqeoptqelim
    dqeoptsimp                dqeverbose                dummypri
    dzopt                     echo                      edsdebug
    edsdisjoint               edssloppy                 edsverbose
    eqfu                      errcont                   essl
    evalassert                evallhseqp                exdelt
    exp                       expanddf                  expandexpt
    expandlogs                ezgcd                     f90
    factor                    factorprimes              factorunits
    failhard                  fancy                     fancy_tex
    fast_la                   fastfor                   fastresexpand
    fastresvb                 fastsimplex               faststructs
    fastvector                fort                      fortupper
    fourier                   ftch                      fulleq
    fullpoly                  fullprec                  fullprecision
    fullroots                 gbltbasis                 gc
    gcd                       gcref                     gcrefall
    gcrefudg                  gdqe                      gdsmart
    gendecs                   genpos                    gentranopt
    gentranseg                getdecs                   gltbasis
    groebfac                  groebfullreduction        groebopt
    groebprot                 groebrm                   groebstat
    groebweak                 gsugar                    guardian
    hack                      hardzerotest              heugcd
    horner                    hyperbolic                ibalp_kapurdisablegb
    ibalp_kapurgb             ibalp_kapurgbdegd         ibalpbadvarsel
    ifactor                   imaginary                 imsl
    inputc                    instantiate               int
    int_test                  intern                    intstr
    kacem                     keepdecs                  lasimp
    latex                     lcm                       lessspace
    lexefgb                   lhyp                      limitedfactors
    list                      listargs                  lmon
    looking_good              lower                     lower_matrix
    lpdocoeffnorm             lpdodf                    lpdotrsym
    lpkeepfiles               ltrig                     makecalls
    mathml                    mcd                       mod_was_on
    modular                   msg                       multiplicities
    multiroot                 mymatch                   nag
    nat                       native_code               nero
    nested                    noacn                     noarg
    nocommutedf               nocompile                 noconvert
    noetherian                noint                     nointint
    nointsubst                nolnr                     nonlnr
    nopowers                  nopropzero                nosplit
    nosturm                   not_negative              notailcall
    novarmsg                  numval                    odesolve_basis
    odesolve_check            odesolve_diff             odesolve_equidim_y
    odesolve_expand           odesolve_explicit         odesolve_fast
    odesolve_full             odesolve_implicit         odesolve_noint
    odesolve_norecurse        odesolve_noswap           odesolve_simp_arbparam
    odesolve_verbose          onespace                  only_integer
    optdecs                   ord                       outerzeroscheck
    output                    overview                  partialint
    partialintdf              partialintint             period
    pgaftermath               pggeneric                 pginfosm
    pginfosol                 pgnoarbcomplex            pgsourcedirect
    pgspqe                    pgspsimpl                 pgverbose
    pgwd                      pidentmore                plap
    plotkeep                  plotusepipe               prapprox
    precise                   precise_complex           prefix
    prephold                  pret                      prfourmat
    pri                       priall                    primat
    prlinineq                 promptnumbers             psen
    pvector                   pwrds                     qgosper_down
    qgosper_specialsol        qhullkeepfiles            qsum_nullspace
    qsum_trace                qsumrecursion_certificate qsumrecursion_down
    qsumrecursion_exp         qsumrecursion_profile     quotenewnam
    r2i                       rahidepoly                raise
    ranpos                    ranum                     rasifac
    rasimpl                   rat                       ratarg
    rational                  rationalize               ratpri
    ratroot                   red_total                 redfront_mode
    reduce4                   reduced                   report_colons
    revalp                    revpri                    rladdcond
    rlanuexdifferentroots     rlanuexgcdnormalize       rlanuexpsremseq
    rlanuexsgnopt             rlanuexverbose            rlataltheo
    rlbnfsac                  rlbnfsm                   rlbqlimits
    rlbrkcxk                  rlbrop                    rlcadans
    rlcadaproj                rlcadaprojalways          rlcadbaseonly
    rlcaddebug                rlcaddecdeg               rlcaddnfformula
    rlcadextonly              rlcadfac                  rlcadfasteval
    rlcadfulldimonly          rlcadhongproj             rlcadisoallroots
    rlcadmc3                  rlcadpartial              rlcadpbfvs
    rlcadpreponly             rlcadprojonly             rlcadrawformula
    rlcadrmwc                 rlcadte                   rlcadtree2dot
    rlcadtrimtree             rlcadverbose              rldavgcd
    rldimaincludefirst        rldpepiverbose            rldpepverbose
    rlenf1twice               rlenffac                  rlenffacne
    rlenfsimpl                rlexprngnatural           rlffi
    rlgaussdebug              rlgausstheo               rlgetrtypecar
    rlgsbnf                   rlgserf                   rlgsprod
    rlgsrad                   rlgsred                   rlgssub
    rlgsutord                 rlgsvb                    rlgurobi
    rlhqeconnect              rlhqedim0                 rlhqegbdimmin
    rlhqegbred                rlhqestrconst             rlhqetfcfast
    rlhqetfcfullsplit         rlhqetfcsplit             rlhqetheory
    rlhqevarsel               rlhqevarselx              rlhqevb
    rlidentify                rlisp88                   rlkapurchkcont
    rlkapurchktaut            rlmrivb                   rlmrivb2
    rlmrivbio                 rlnzden                   rlopt1s
    rlourdet                  rlparallel                rlpasfbapprox
    rlpasfconf                rlpasfdnffirst            rlpasfdnfqeexblock
    rlpasfexpand              rlpasfgauss               rlpasfgc
    rlpasfintern              rlpasfsc                  rlpasfses
    rlpasfsimplify            rlpasfvb                  rlpcprint
    rlpcprintall              rlplsimpl                 rlposden
    rlpqeold                  rlpscsgen                 rlqeaprecise
    rlqeasri                  rlqebacksub               rlqedfs
    rlqedyn                   rlqeexpand                rlqefb
    rlqefbmma                 rlqefbqepcad              rlqefbslfq
    rlqefilterbounds          rlqefullans               rlqegen1
    rlqegenct                 rlqegsd                   rlqeheu
    rlqeidentify              rlqeinfirst               rlqelog
    rlqepnf                   rlqeprecise               rlqeqsc
    rlqesqsc                  rlqesr                    rlqestdans
    rlqestdansint             rlqestdansq               rlqestdansvb
    rlqesubf                  rlqesubi                  rlqevarsel
    rlqevarseltry             rlqevb                    rlqevbold
    rlrealtime                rlresi                    rlresolveuniversal
    rlsetequalqhash           rlsiatadv                 rlsichk
    rlsid                     rlsiexpl                  rlsiexpla
    rlsifac                   rlsifaco                  rlsiidem
    rlsimpl                   rlsimplfloor              rlsipd
    rlsiplugtheo              rlsipo                    rlsippatl
    rlsippsignchk             rlsippsubst               rlsipw
    rlsism                    rlsiso                    rlsisocx
    rlsitsqspl                rlsiverbose               rlslfqvb
    rlsmprint                 rlsusi                    rlsusiadd
    rlsusigs                  rlsusimult                rltabib
    rltnft                    rltropdel0                rltropilp
    rltropint                 rltroplcm                 rltropsos
    rlverbose                 rlvmatvb                  rlvsllearn
    rlvsllog                  rlxopt                    rlxoptpl
    rlxoptri                  rlxoptric                 rlxoptrir
    rlxoptsb                  rlxoptses                 rootmsg
    roundall                  roundbf                   rounded
    rtrace                    save_native               saveactives
    savedef                   saveprops                 savesfs
    savestructr               semantic                  sfto_musser
    sfto_tobey                sfto_yun                  show_grid
    sidrel                    simpnoncomdf              slat
    sllast                    smtslog                   smtsplain
    solvesingular             spec                      specification
    strict_argcount           strip_native              symmetric
    talpqegauss               talpqp                    taylorautocombine
    taylorautoexpand          taylorkeeporiginal        taylornocache
    taylorprintorder          tdusetorder               tensor
    test_plot                 testecho                  tex
    texbreak                  texindent                 time
    tr_lie                    tra                       tracefps
    tracelimit                traceratint               tracespecfns
    tracetrig                 trallfac                  trchrstrem
    trcompact                 trdesir                   trdint
    trfac                     trfield                   trgroeb
    trgroeb1                  trgroebr                  trgroebs
    trham                     trigform                  trint
    trintsubst                trinvbase                 trlinineq
    trlinineqint              trlinrec                  trmin
    trnonlnr                  trnumeric                 trode
    trplot                    trpm                      trroot
    trrubi                    trsolve                   trsum
    trtaylor                  trwu                      trxideal
    trxmod                    twogrid                   twosided
    unsafecar                 upper_matrix              useold
    usetaylor                 usez                      utf8
    utf82d                    utf82dround               utf8diffquot
    utf8exp                   utf8expall                utf8pad
    varopt                    vectorc                   verbatim
    verboseload               vslfast                   vslgreaterplem
    vslseprintnls             vslsprintil               vslsprintnl
    vslsprintsl               vtrace                    web
    windexpri                 wrchri                    xfullreduce
    xpartialint               xpartialintdf             xpartialintint
    zb_factor                 zb_inhomogeneous          zb_proof
    zb_timer                  zb_trace                  zeilberg
    zeropzero
);

% Constants used in scanner.

flag('(define!-constant),'eval);

cr!* := compress(list('!!, special!-char 6));   % carriage return
ff!* := compress(list('!!, special!-char 5));   % form feed
tab!*:= compress(list('!!, special!-char 3));   % tab key


% One inessential reference to REVERSIP in this module (left unchanged).

% This file defines the system dependent code necessary to run REDUCE
% under CSL.

Comment The following functions, which are referenced in the basic
REDUCE source (RLISP, ALG1, ALG2, MATR and PHYS) should be defined to
complete the definition of REDUCE:

        BYE
        EVLOAD
        ERROR1
        FILETYPE
        MKFIL
        ORDERP
        QUIT
        SEPRP
        SETPCHAR.

Prototypical descriptions of these functions are as follows;

remprop('bye,'stat);

symbolic procedure bye;
   %Returns control to the computer's operating system command level.
   %The current REDUCE job cannot be restarted;
   <<close!-output!-files(); stop 0>>;

deflist('((bye endstat)),'stat);

remprop('quit,'stat);

symbolic procedure quit;
   %Returns control to the computer's operating system command level.
   %The current REDUCE job cannot be restarted;
   <<close!-output!-files(); stop 0>>;

deflist('((quit endstat)),'stat);

symbolic procedure seprp u;
   % Returns true if U is a blank, end-of-line, tab, carriage return or
   % form feed.  This definition replaces the one in the BOOT file.
   u eq '!  or u eq tab!* or u eq !$eol!$ or u eq ff!* or u eq cr!*;

symbolic procedure filetype u;
   % Determines if string U has a specific file type.
   begin scalar v,w;
      v := cdr explode u;
      while v and not(car v eq '!.) do
        <<if car v eq '!< then while not(car v eq '!>) do v := cdr v;
          v := cdr v>>;
      if null v then return nil;
      v := cdr v;
      while v and not(car v eq '!") do <<w := car v . w; v := cdr v>>;
      return intern compress reversip w
   end;

symbolic procedure mkfil u;
   % Converts file descriptor U into valid system filename.
   if stringp u then u
    else if not idp u then typerr(u,"file name")
    else string!-downcase u;


Comment The following functions are only referenced if various flags are
set, or the functions are actually defined. They are defined in another
module, which is not needed to build the basic system. The name of the
flag follows the function name, enclosed in parentheses:

        CEDIT (?)
        COMPD (COMP)
        EDIT1   This function provides a link to an editor. However, a
                definition is not necessary, since REDUCE checks to see
                if it has a function value.
        EMBFN (?)
        EZGCDF (EZGCD)
        PRETTYPRINT (DEFN --- also called by DFPRINT)
                This function is used in particular for output of RLISP
                expressions in LISP syntax. If that feature is needed,
                and the prettyprint module is not available, then it
                should be defined as PRINT
        RPRINT (PRET)
        TIME (TIME) returns elapsed time from some arbitrary initial
                    point in milliseconds;



Comment The following operator is used to save a REDUCE session as a
file for later use;

symbolic procedure savesession u;
   preserve('begin);

flag('(savesession),'opfn);

flag('(savesession),'noval);


Comment make "system" available as an operator;

flag('(system),'opfn);

flag('(system),'noval);


Comment to make "faslend" an endstat;

put('faslend,'stat,'endstat);


Comment The current REDUCE model allows for the availability of fast
arithmetical operations on small integers (called "inums").  All modern
LISPs provide such support.  However, the program will still run without
these constructs.  The relevant functions that should be defined for
this purpose are as follows;

flag('(iplus itimes iplus2 itimes2 iadd1 isub1 iminus iminusp
       idifference iquotient iremainder ilessp igreaterp ileq igeq
       izerop ionep iequal apply1 apply2 apply3), 'lose);

#if (null (memq 'jlisp lispsystem!*))
flag('(fp!-infinite fp!-nan fp!-finite fp!-subnorm), 'lose);
#endif

Comment There are also a number of system constants required for each
implementation. In systems that don't support inums, the equivalent
single precision integers should be used;

% LARGEST!-SMALL!-MODULUS is the largest power of two that can
% fit in the fast arithmetic (inum) range of the implementation.
% This is constant for the life of the system and could be
% compiled in-line if the compiler permits it.

% As of December 2010 CSL will actually support up to 2^27, but until
% people have had several months to install a newly compiled CSL I will
% restrict myself to the limit that applied up until them.

% largest!-small!-modulus := 2**24 - 1;

% Well in August 2011 I conclude that matching the value that PSL uses is
% important for compatibility... so I hope that if PSL ever changes somebody
% will tell me.

largest!-small!-modulus := 2**23;

!#if (not (memq 'vsl lispsystem!*))

flag('(modular!-difference modular!-minus modular!-number
       modular!-plus modular!-quotient modular!-reciprocal
       modular!-times modular!-expt set!-small!-modulus
       safe!-modular!-reciprocal), 'lose);

!#endif

% flag('(random next!-random!-number), 'lose);

set!-small!-modulus 3;

% The following are now built into CSL, where by using the C library
% and (hence?) maybe low level tricks or special floating point
% tricks can help with speed.

!#if (memq  'vsl lispsystem!*)

flag('(cos exp expt log sin sqrt fix
       ceiling floor round clrhash puthash gethash remhash), 'lose);

!#else

flag('(acos acosd acosh acot acotd acoth acsc acscd acsch asec asecd
       asech asin asind asinh atan atand atan2 atan2d atanh cbrt cos
       cosd cosh cot cotd coth csc cscd csch exp expt hypot ln log
       logb log10 sec secd sech sin sind sinh sqrt tan tand tanh fix
       ceiling floor round clrhash puthash gethash remhash), 'lose);

!#endif


global '(loaded!-packages!* no!_init!_file personal!-dir!*);

personal!-dir!* := "$HOME";


% We need to define a function BEGIN, which acts as the top-level
% call to REDUCE, and sets the appropriate variables;

remflag('(begin),'go);

symbolic procedure begin;
  begin
     scalar w,!*redefmsg;
     !*echo := not !*int;
     !*extraecho := t;
% Enable heavy debugging option in bootstrap version. The effect of this
% will be that all errors display a backtrace even within a use of
% (errorset E nil nil). Some of these backtraces are a nuisance since
% the "error" is not in any sense a problem, but when things are going
% wrong it can be most frustrating if the evidence is hidden.
     if !*savedef and getd 'enable!-errorset then enable!-errorset(3,3);
     if modulep 'tmprint then <<
        w := verbos 0;
        load!-module 'tmprint;
        verbos w;
        if outputhandler!* = 'fancy!-output then fmp!-switch nil >>;
% If invoked from texmacs do something special...
     if getd 'fmp!-switch and member('texmacs, lispsystem!*) then <<
         w := verbos 0;
         fmp!-switch t;
         off1 'promptnumbers;
         load!-module 'tmprint;
         on1 'redfront_mode;
         verbos w >>
% If the tmprint module is loaded and I have a window that can support it
% I will display things in a "fancy" way within the CSL world.
     else if getd 'fmp!-switch then <<
        if member('showmath, lispsystem!*) then fmp!-switch t
        else if outputhandler!* = 'fancy!-output then fmp!-switch nil >>;
     ifl!* := ipl!* := ofl!* := nil;
     if date!* then <<
        verbos nil;
% The linelength may need to be adjusted if we are running in a window.
% To cope with this, CSL allows (linelength t) to set a "default" line
% length that can even vary as window sizes are changed. An attempt
% will be made to ensure that it is 80 at the start of a run, but
% (linelength nil) can return varying values as the user re-sizes the
% main window (in some versions of CSL). However this is still not
% perfect! The protocol
%   old := linelength nil;
%   <do something, possibly changing linelength as you go>
%   linelength old;
% can not restore the variability characteristic. However I make
%   old := linelength n; % n numeric or T
%   ...
%   linelength old;
% preserve things by returning T from (linelength n) in relevant cases.
        linelength t;
% The next four lines have been migrated into the C code in "restart.c"
% so that some sort of information gets back to the user nice and early.
%       prin2 version!*;
%       prin2 ", ";
%       prin2 date!*;
%       prin2t " ...";
        if getd 'addsq then <<
% I assume here that this is an algebra system if ADDSQ is defined, and
% in that case process an initialisation file. Starting up without ADDSQ
% defined means I either have just RLISP built or I am in the middle of
% some bootstrap process. Also if a variable no_init_file is set to TRUE
% then I avoid init file processing.
           !*mode := 'algebraic;
           if null no!_init!_file then begin
              scalar name;
              name := assoc('shortname, lispsystem!*);
              if atom name then name := "reduce"
              else name := list2string explode2lc cdr name;
              erfg!* := nil;
              read!-init!-file name end >>
        else !*mode := 'symbolic;
        % date!* := nil;
        >>;
% % If there is a patches module that is later than one that I currently
% % have installed then load it up now.
%      if version!* neq "REDUCE Development Version"
%        then load!-patches!-file();
     w := assoc('opsys, lispsystem!*);
     if not atom w then w := cdr w;
% For MOST systems I will let ^G (bell) be the escape character, but
% under win32 I use that as an interrupt character, and so there I go
% back and use ESC instead.  I do the check at BEGIN time rather than
% further out so that common checkpoint images can be used across
% systems.
     esc!*:= compress list('!!,
                special!-char (if w = 'win32 then 10 else 9));
     while errorp errorset('(begin1), !*backtrace, !*backtrace) do nil;
     prin2t "Leaving REDUCE ... "
  end;

flag('(begin),'go);

% The following function is used in some CSL-specific operations. It is
% also defined in util/rprint, but is repeated here to avoid loading
% that module unnecessarily, and because the definition given there is
% rather PSL specific.

% There is an ugliness here that arises because cslrend is processed during
% bootstrapping and then read a second time to create the version of it that
% will remain in the final working system. An effect is that a LOSE property
% established when it is initially loaded could cause the function concerned
% to be ignored the second time - with pretty bad conseqences. So any function
% that is defined here and needs to be tagged LOSE must have the LOSE
% property explicitly removed ahead of its definition. The same issue arises
% in a few other files that are loaded really early in the bootstrapping part
% of the Reduce build - and obviously for PSL just as much as for CSL.

remflag('(string!-downcase),'lose);

symbolic procedure string!-downcase u;
   compress('!" . append(explode2lc u,'(!")));

% princ!-upcase and princ!-downcase are used for fortran output

flag('(string!-downcase princ!-upcase princ!-downcase),'lose);

% This function is used in Rlisp '88.

symbolic inline procedure igetv(u,v); getv(u,v);
symbolic inline procedure iputv(u,v,w); putv(u,v,w);

% The following functions are NOT in Standard Lisp and should NOT be
% used anywhere in the REDUCE sources, but the amount of trouble I have
% had with places where they do creep in has encouraged me to define
% them here anyway and put up with the (small) waste of space.

% Well I note that avector/avector.red also defined these, and to keep
% the way I process inline definitions happy I must use the same name for
% the formal parameter here and there so that the definitions are exactly
% the same rather than merely equivalent in function. So it is important to
% use "u" here!

remflag('(first second third fourth rest), 'lose);

symbolic inline procedure first u; car u;

symbolic inline procedure second u; cadr u;

symbolic inline procedure third u; caddr u;

symbolic inline procedure fourth u; cadddr u;

symbolic inline procedure rest u; cdr u;

flag('(first second third fourth rest), 'lose);

Comment Initial setups for REDUCE;

spare!* := 0;    % We need this for bootstrapping.

symchar!* := t;  % Changed prompt when in symbolic mode.


% The current CSL gensym uses an upper case G as the root,
% which causes inconsistencies in some tests (e.g., int and qsum).
% This definition cures that.

symbolic smacro procedure gensym; gensym1 'g;


symbolic procedure initreduce;
   initrlisp();   % For compatibility.

symbolic procedure initrlisp;
  % Initial declarations for REDUCE
  <<statcounter := 0;
    crbuflis!* := nil;
    spare!* := 0;
    !*int := t;
  >>;

symbolic procedure rlispmain;
    lispeval '(begin);

flag('(rdf preserve reclaim),'opfn);

flag('(rdf preserve),'noval);

flag('(load reload),'noform);

deflist('((load rlis) (reload rlis)),'stat);

symbolic macro procedure load x; PSL!-load(cdr x, nil);
symbolic macro procedure reload x; PSL!-load(cdr x, t);

global '(PSL!-loaded!*);
PSL!-loaded!* := nil;

symbolic procedure PSL!-load(mods, reloadp);
  for each x in mods do <<
    if reloadp or not member(x, PSL!-loaded!*) then <<
%      load!-module x;
       load!-package x;
       PSL!-loaded!* := union(list x, PSL!-loaded!*) >> >>;

symbolic macro procedure tr x;
   list('trace, list('quote, cdr x));

symbolic macro procedure untr x;
   list('untrace, list('quote, cdr x));

symbolic macro procedure trst x;
   list('traceset, list('quote, cdr x));

symbolic macro procedure untrst x;
   list('untraceset, list('quote, cdr x));

flag('(tr untr
      trst untrst
      ),'noform);

deflist('((tr rlis)     (trst rlis)
          (untr rlis)   (untrst rlis)
         ),'stat);

% Now built-in to CSL
%symbolic procedure prop x; plist x;  % Yukky PSL compatibility.

Comment The following declarations are needed to build various modules;

flag('(mkquote spaces subla boundp error1),'lose);

% The exact order of items in the lists produced by these is important
% to REDUCE.
flag('(union intersection), 'lose);

!#if (null (memq 'vsl lispsystem!*))

flag('(safe!-fp!-plus safe!-fp!-times safe!-fp!-quot), 'lose);

!#endif

% I USED to flag ordp as LOSE, but there are three different definitions in
% different places within Reduce and the LOSE mechanism is not quite
% refined enough to allow for the single one of them that has a version
% built into CSL directly.

flag('(threevectorp), 'lose);

deflist('((imports rlis)),'stat);

flag('(sort stable!-sort stable!-sortip reversip2),'lose);

% We also need this.

flag('(lengthc),'lose);
#if (null (member 'jlisp lispsystem!*))
flag('(widelengthc),'lose);
#endif

symbolic procedure concat2(u,v); concat(u,v);

symbolic procedure concat(u,v);
   list2string append(string2list u, string2list v);

remflag('(copyd), 'lose);

symbolic procedure copyd(new,old);
% Copy the function definition from old id to new. For CSL this plays
% extra games with the '!*savedef property. The extra behaviour was
% originally to favour the Reduce "patching" scheme but that is no longer
% in use...
   begin scalar x;
      x := getd old;
% If loading with !*savedef = '!*savedef then the actual definitions
% do not get loaded, but the source forms do...
      if null x then progn(
        if not (!*savedef = '!*savedef)
          then rerror('rlisp,1,list(old,"has no definition in copyd")) )
      else progn(putd(new,car x,cdr x),
                 if flagp(old, 'lose) then flag(list new, 'lose) );
% The transfer of the saved definition is needed if the REDUCE "patch"
% mechanism is to work fully properly.
      if (x := get(old, '!*savedef)) then put(new, '!*savedef, x);
      return new
   end;

flag('(copyd), 'lose);

% The following is intended to run the test on a single package.
% In due course I will improve it so it also checks the output,
% but even as it is I find it useful to be able to say
%        test_package solve;
% to test the solve package (etc).

symbolic procedure test_package m;
 << load!-module 'remake;
    test_a_package list m;
    0 >>; % because test_a_package restarts Reduce the result here should
          % never actually end up being delivered.

flag('(test_package), 'opfn);

% Foreign functions are EXPERIMENTAL in CSL at the time I put this in,
% but the function to invoke one is variadic...

flag('(call!-foreign!-function), 'variadic);

% Arrange (for PSL compatibility) that "on gc;" and "off gc;" switch
% garbage collector messages on or off.

put('gc, 'simpfg, '((t (verbos t))
                    (nil (verbos nil))));

!#if (memq 'jlisp lispsystem!*)

% At present Jlisp does not support unwind-protect properly. It
% can interpret it, and it compiles it into bytecodes, but the bytecode
% interpreter then does not support those cases. So as a temporary measure
% here is something that does not actually deal with errors but gets the
% recovery form evaluated in the easy case when things do not exit
% abruptly. I had hoped I could macroexpand to something using errorset
% and obtain full functionality here but that seems to be unduly hard
% mainly because of access to local variables.

symbolic macro procedure unwind!-protect u;
  begin
    scalar g, x;
    u := cdr u;
    if not atom u then <<
       x := car u;
       u := cdr u >>;
    g := gensym();
    return list('prog, list g,
       list('setq, g, x),
       'progn . u,
       list('return, g))
  end;

symbolic procedure find!-gnuplot();
  "gnuplot";

!#endif

global '(!*psl !*csl);
!*psl := nil;
!*csl := t;

endmodule;

end;
