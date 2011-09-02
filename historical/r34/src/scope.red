module scope;   % Header module for SCOPE package.

% ------------------------------------------------------------------- ;
%                                                                     ;
%       SCOPE : A SOURCE CODE OPTIMIZATION PACKAGE FOR REDUCE         ;
%                                                                     ;
% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Authors :   J.A. van Hulzen, B.J.A. Hulshof, B.L. Gates, M.C. van   ;
%             Heerwaarden and J.C.A. Smit.                            ;
% Email address: infhvh@cs.utwente.nl                                 ;
% ------------------------------------------------------------------- ;
%                                                                     ;
%  A SHORT DESCRIPTION                                                ;
% The present version of SCOPE, completely written in RLISP, allows   ;
% one to subject a (set of) proper REDUCE statement(s) S, viewed as a ;
% block B of straightline code, to a heuristic search for common sub- ;
% expressions (cse's), thus attempting to reduce the arithmetic com-  ;
% plexity AC of B, i.e. the number of elementary arithmetic operations;
% reflected by it. At present the default domain facilities are as-   ;
% sumed.  These cse's c(i) are replaced by new names n(i) and state-
% ments of the form n(i):=c(i) are correctly inserted in the thus mod-;
% ified set of input expressions S.                                   ;
% To achieve this the elements of S are transformed into multivariate ;
% polynomials, by generating new names for non-variable kernels, and  ;
% by adequately storing information about these kernels as to allow a ;
% correct output construction. These polynomials are decomposed in two;
% interrelated sets consisting of linear expressions and power prod.s,;
% resp. Both sets are stored in sparse "incidence" matrices (the + and;
% the * scheme, resp.). The rows define (sub)expressions and the      ;
% columns variable occurrences. The matrices are subjected to a       ;
% Breuer-like search for cse's. Then cse's, reduced to variables are  ;
% removed from the +(*) scheme and inserted in the *(+) scheme when   ;
% ever possible. In addition the distributive law is applied to       ;
% migrate information from the * scheme to the + scheme. Before       ;
% printing the new representation a finishing touch is carried out    ;
% to further reduce the AC: Addition chain like algorithms are applied;
% to completely remove integral powers. Redundant multiplications,    ;
% imposed by repeated occurrences of single variable multiples, are   ;
% removed through a combination of locally factoring out coefficient  ;
% gcd's and by replacing identical multiples by new variables. These  ;
% searches are essentially done in single rows and columns. The Breuer;
% searches however are based on zero-minor detection.                 ;
%                                                                     ;
%  STRUCTURE OF THE SOURCE CODE                                       ;
%  The program is distributed over the following modules:             ;
% -COSMAC    - contains a collection of smacros for direct access     ;
%              to the incidence matrices.                             ;
% -CODCTL    - contains the definitions of the supervising commands,  ;
%              such as initialization,optimization,output preparation ;
%  name selection and operator counts.                                ;
% -CODMAT    - consists of a set of more extended access functions,   ;
%              allowing to store,retrieve or modify information,given ;
% in the matrices. It also contains a number of histogram operations  ;
% The hashing-like histogram techniques improve the performance of    ;
% the heuristic searches. The second part of this module consists of  ;
% input transformation functions.                                     ;
% -CODOPT    - covers the functions required for the Breuer-like      ;
%              searches.                                              ;
% -CODPRI    - consists of three parts. The first is a set of print   ;
%              routines for vizualizing the matrices. The second part ;
% allows creating an intermediate associationlist, called prefixlist, ;
% of pair    - he form (n(i).v(i)), which is used to print the optimi-;
% zed version of the input : a sequence of statements n(i):=v(i),     ;
% i=1,2,... The third part consists of functions applied to remove    ;
% redundancy from the prefixlist, i.e. cse-names finally occurring    ;
% only once in the output are replaced by their value.                ;
% -CODAD1    - contains information migration facilities and the func-;
%              tions defining the application of the distributive law.;
% Functions for removal of different names for identical subexpres-   ;
% sions are also contained in this module.                            ;
% -CODAD2    - defines the functions responsible for the finishing    ;
%              touch.                                                 ;
% -CODINT    - consists of the functions interfacing SCOPE with       ;
%              GENTRAN and REDUCE.                                    ;
% -CODDEC    - gives the functions, operating with GENTRAN's symbol   ;
%              table and on the final version of Prefixlist, to produ-;
% ce a list of declarations for the output.                           ;
% In addition, the following two modules are available separately:    ;
% -GHORNER   - contains Horner-rule facilities.                       ;
% -GSTRUCTR  - contains modified STRUCTR facilities.                  ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% ----- INCIDENCE MATRIX AND HISTOGRAM ------------------------------ ; 
% The module COSMAC contains all direct access functions to the incid-;
% ence matrix and histogram and for subexpressions ordering.          ;
%                                                                     ;
% The incidence matrix is represented by a vector CODMAT.             ;
% Indices smaller then Maxvar represent the columns.                  ;
% The other indices represent rows of the incidence matrix.           ;
% All elements of the matrix are stored twice. So the incidencematrix ;
% is represented by the rows as well as by the columns.               ;
% Each matrix-element in a row(column) also contains the column(row)  ;
% index to which the element also belongs.                            ;
% The histogram is represented by a vector CODHISTO of length         ;
% HISTOLEN.                                                           ;
%                                                                     ;
% ------ THE STRUCTURE OF A ROW(COLUMN) IN LISP NOTATION ------------ ;
%                                                                     ;
% Row(X)=(Free,Wght,OpVal,Farvar,Zstrt,Chrow,CofExp,HiR,Ordr)         ;
%        For a column Chrow,CofExp,HiR and Ordr do not exist.         ;
%  Free: Indicates whether a row(column) has to be (temporarily)      ;
%        disregarded.                                                 ;
%  Wght=((AWght.MWght).HWght)                                         ;
%   AWght: Additive weight of row X                                   ;
%   MWght: Multiplicative weight of row X                             ;
%   HWght: Histogram weight of row X (AWght+3*MWght)                  ;
%  OpVal: Operator for the arguments given in Zstrt and Chrow:The +   ;
%         and * schemes are merged into one matrix via CODMAT.        ;
%  Farvar: For a row : The index of the father or, if the row repre-  ;
%          sents the primitive part of a top-level sum or product,the ;
%          name of that sum or product.                               ;
%          For a column : the template of the column variable.        ;
%  Zstrt=(Z Z Z Z...Z) where                                          ;
%   Z: Element of the row or column if Row X representing a product   ;
%      or sum. Z is one of the arguments of the operator if X repre-  ;
%      sents another operator. If an argument is not an atom it is    ;
%      replaced by NIL and put in the Chrow.                          ;
%   Z=(X(Y)ind.Val) if Row X represents a product or sum, where       ;
%    X(Y)ind: A column(row) index orthogonal to the to row(column) to ;
%             which Z also belongs.                                   ;
%    Val=(IVal.BVal) where                                            ;
%     IVal: The coefficient (for a sum) or the exponent (for a        ;
%           product) of element of Row X.                             ;
%     BVal: The name representing the Z-element on output (seeCODPRI).;
%  Chrow: For a row : Indices of the children                         ;
%  CofExp: The coefficient of Row X if X represents a product or the  ;
%          exponent otherwise.                                        ;
%  HiR=(PHiR.NHiR)                                                    ;
%   PHiR: Previous row index in histogram                             ;
%   NHiR: Next row index in histogram                                 ;
%  Remark: If CODHISTO(i)=k then HWght(k)=i.                          ;
%  The pairs (PHiR.NHiR) are used to create a double linked list of   ;
%  rows with identical histogram weights i. The list is accessable    ;
%  through CODHISTO(i).                                               ;
%  Ordr: A list of row indices of cse's and/or of names of kernels,   ;
%        which have to be printed before this row,as to guarantee a   ;
%        correct evaluation sequence.                                 ;
% Warning: When X does not represent a product or sum, the ordering   ;
%  of the Chrow and Zstrt should be left intact,because the first NIL ;
%  element in Zstrt corresponds with the first child in Chrow,etc.    ;
% ------------------------------------------------------------------- ;

create!-package('(scope codint codctl codmat codopt codad1 codad2 codpri
                  coddec ghorner gstructr),
                '(contrib scope));

% Other packages needed with SCOPE package.

load!-package 'gentran;

% module cosmac;   % Smacro definitions for access functions.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Authors :   J.A. van Hulzen, B.J.A. Hulshof.                        ;
% ------------------------------------------------------------------- ;
% ------------------------------------------------------------------- ;
% The module COSMAC contains the SMACRO-definitions of access func-   ;
% tions used during the optimization process.                         ;
% ------------------------------------------------------------------- ;

symbolic$

% ------------------------------------------------------------------- ;
% Access functions for the incidence matrix                           ;
% ------------------------------------------------------------------- ;

global '(codmat maxvar)$

define lenrow=8,lencol=4;
% ------------------------------------------------------------------- ;
% Length of the rows and the columns                                  ;
% ------------------------------------------------------------------- ;

symbolic smacro procedure row x$
   getv(codmat,maxvar+x)$

symbolic smacro procedure free x$
   getv(row x,0)$

symbolic smacro procedure wght x$
   getv(row x,1)$

symbolic smacro procedure awght x$
   caar(wght x)$

symbolic smacro procedure mwght x$
   cdar(wght x)$

symbolic smacro procedure hwght x$
   cdr(wght x)$

symbolic smacro procedure opval x$
   getv(row x,2)$

symbolic smacro procedure farvar x$
   getv(row x,3)$

symbolic smacro procedure zstrt x$
   getv(row x,4)$

symbolic smacro procedure chrow x$
   getv(row x,5)$

symbolic smacro procedure expcof x$
   getv(row x,6)$

symbolic smacro procedure hir x$
   getv(row x,7)$

symbolic smacro procedure phir x$
   car(hir x)$

symbolic smacro procedure nhir x$
   cdr(hir x)$

% ------------------------------------------------------------------- ;
% Assignments in the incidence matrix                                 ;
% ------------------------------------------------------------------- ;

symbolic smacro procedure fillrow(x,v)$
   putv(codmat,maxvar+x,v)$

symbolic smacro procedure setoccup x$
   putv(row x,0,nil)$

symbolic smacro procedure setfree x$
   putv(row x,0,t)$

symbolic smacro procedure setwght(x,v)$
   putv(row x,1,v)$


symbolic smacro procedure setopval(x,v)$
   putv(row x,2,v)$

symbolic smacro procedure setfarvar(x,v)$
   putv(row x,3,v)$

symbolic smacro procedure setzstrt(x,v)$
   putv(row x,4,v)$

symbolic smacro procedure setchrow(x,v)$
   putv(row x,5,v)$

symbolic smacro procedure setexpcof(x,v)$
   putv(row x,6,v)$

symbolic smacro procedure sethir(x,v)$
   putv(row x,7,v)$

symbolic smacro procedure setphir(x,v)$
   rplaca(hir x,v)$

symbolic smacro procedure setnhir(x,v)$
   rplacd(hir x,v)$

% ------------------------------------------------------------------- ;
% Access functions for Z elements                                     ;
% ------------------------------------------------------------------- ;

symbolic smacro procedure xind z$
   car z$

symbolic smacro procedure yind z$
   car z$

symbolic smacro procedure val z$
   cdr z$

symbolic smacro procedure ival z$
   car val z$

symbolic smacro procedure bval z$
   cdr val z$

% ------------------------------------------------------------------- ;
% Assignment functions for Z elements                                 ;
% ------------------------------------------------------------------- ;

symbolic smacro procedure setival(z,v)$
   rplaca(val z,v)$

symbolic smacro procedure setbval(z,v)$
   rplacd(val z,v)$

symbolic smacro procedure mkzel(n,iv)$
   if atom(iv) then n.(iv.nil) else n.iv$
    % --------------------------------------------------------------- ;
    % Distinguish between atom and non atom for IVAL and BVAL.        ;
    % --------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% Access functions for ordening subexpressions                        ;
% ------------------------------------------------------------------- ;

symbolic smacro procedure ordr x$
   getv(row x,8)$

symbolic smacro procedure setordr(x,l)$
   putv(row x,8,l)$

% ------------------------------------------------------------------- ;
% Access functions for Histogram                                      ;
% ------------------------------------------------------------------- ;

global '(codhisto)$

codhisto:=nil;

define histolen=200$

symbolic smacro procedure histo x$
   getv(codhisto,x)$

symbolic smacro procedure sethisto(x,v)$
   putv(codhisto,x,v)$

endmodule;


module codint;  % Interface between SCOPE and REDUCE and GENTRAN.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Author :   B.L. Gates.                                              ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% The module CODINT contains the functions defining the interface     ;
% between SCOPE and REDUCE and GENTRAN.                               ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% Some GENTRAN modules  are required to obtain a correct interface.   ;
% The file names are installation dependent.                          ;
% ------------------------------------------------------------------- ;

%%%%  BOTHTIMES (load "/usr/Compalg/Reduce/bin/gentran/util");
%%%%  BOTHTIMES (load "/usr/Compalg/Reduce/bin/gentran/intrfc");
%%%%  BOTHTIMES (load "/usr/Compalg/Reduce/bin/gentran/templt");
%%%%  BOTHTIMES (load "/usr/Compalg/Reduce/bin/gentran/pre");
%%%%  BOTHTIMES (load "/usr/Compalg/Reduce/bin/gentran/gparser");
%%%%  BOTHTIMES (load "/usr/Compalg/Reduce/bin/gentran/redlsp");
%%%%  BOTHTIMES (load "/usr/Compalg/Reduce/bin/gentran/segmnt");
%%%%  BOTHTIMES (load "/usr/Compalg/Reduce/bin/gentran/lspfor",
%%%%            "/usr/Compalg/Reduce/bin/gentran/lsprat",
%%%%            "/usr/Compalg/Reduce/bin/gentran/lsppasc",
%%%%            "/usr/Compalg/Reduce/bin/gentran/lspc");
%%%%  BOTHTIMES (load "/usr/Compalg/Reduce/bin/gentran/goutput");


%IN "$gentranutil/sun-gentran-load"$
 
% ------------------------------------------------------------------- ;
%   ALGEBRAIC MODE COMMAND PARSER                                     ;
% ------------------------------------------------------------------- ;

put('optimize, 'stat, 'optimizestat);

global '(!*evalcommands!*);
!*evalcommands!* := '(gstructr ghorner);

global '(!*evalfunctions!*);
!*evalfunctions!* := nil;

global '(gentraning!* preprefixlist);

symbolic expr procedure optimizestat;
    % --------------------------------------------------------------- ;
    %  OPTIMIZE command parser.                                       ;
    % --------------------------------------------------------------- ;
    begin scalar forms, vname, infiles, outfile, x, decs, kwds, delims;

    % mcd 22/7/89
    gentraning!* := 'nil;

    symtabrem('!*main!*,'!*decs!*);
    kwds := append(!*evalcommands!*, '(iname in out declare));
    delims := append(kwds, '(!*semicol!* !*rsqb!* end));
    flag(kwds, 'delim);
    while not memq(cursym!*, delims) do
        if (x := xreadforms()) then
            forms := append(forms, x);
    while memq(cursym!*, kwds) do
        if eq(cursym!*, 'iname) then
            vname := xread t
        else if eq(cursym!*, 'in) then
            if atom (x := xread nil) then
                infiles := list x
            else if eqcar(x, '!*comma!*) then
                infiles := cdr x
            else
                infiles := x
        else if eq(cursym!*, 'out) then
            outfile:=xread t
        else if eq(cursym!*, 'declare) then
            decs := append(decs, cdr declarestat())
        else if get(cursym!*, 'stat) then
            forms := append(forms,
                            list lispeval list get(cursym!*, 'stat));
    remflag(kwds, 'delim);
    return list('symoptimize, mkquote forms,
                              mkquote infiles,
                              mkquote outfile,
                              mkquote vname,
                              mkquote decs)
    end;


% ------------------------------------------------------------------- ;
%   SYMBOLIC MODE PROCEDURE                                           ;
% ------------------------------------------------------------------- ;

fluid '(!*algpri !*optdecs)$

switch algpri,optdecs$

symbolic expr procedure symoptimize(forms,infiles,outfile,vname,decs) ;
    % --------------------------------------------------------------- ;
    %  Symbolic mode function.                                        ;
    % --------------------------------------------------------------- ;
    begin scalar algpri,echo,res;
    echo:=!*echo;
    lispeval list('off, mkquote list 'echo);
    if infiles then
        forms := append(forms, files2forms infiles);
    algpri := !*algpri;
    !*echo:=echo;
    if decs then !*optdecs:=t;
    lispeval list('off, mkquote list 'algpri);
    forms := foreach f in forms conc
                if listp f and memq(car f, !*evalcommands!*) then
                    lispeval (car f .
                              foreach x in cdr f collect mkquote x)
                else
                    list f;
    !*algpri := algpri;
    preproc1 ('declare . decs);
    res := lispeval formoptimize(list('optimizeforms,forms,outfile,
                                      vname),
                             !*vars!*,
                             !*mode)
    end;


symbolic expr procedure xreadforms;
    begin scalar x;
    x := xread t;
    if listp x and eqcar(x, 'list) then
        return car flattenlist x
    else if x then
        return list x
    else
        return x
    end;

symbolic expr procedure flattenlist x;
    if atom x then
        list x
    else if eqcar(x, 'list) then
        flattenlist cdr x
    else
        list foreach y in x conc flattenlist y;

symbolic expr procedure files2forms flist;
    begin scalar ch, holdch, x, forms;
    holdch := rds nil;
    forms := nil;
    foreach f in flist do
    <<
        ch := open(mkfil f, 'input);
        rds ch;
        while (x := xreadforms()) do
            forms := append(forms, x);
        rds holdch;
        close ch
    >>;
    return forms
    end;


symbolic expr procedure formoptimize(u, vars, mode);
    car u . foreach arg in cdr u
                collect formoptimize1(arg, vars, mode);

symbolic expr procedure formoptimize1(u, vars, mode);
    if atom u then
        mkquote u
    else if eqcar(u, 'eval) then
        if listp cadr u and memq(caadr u, !*evalfunctions!*) then
            mkquote lispeval cadr u
        else
            list('sq2pre, list('aeval, form1(cadr u, vars, mode)))
    else if car u memq '(lsetq rsetq lrsetq) then
        begin scalar op, lhs, rhs;
        op := car u;
        lhs := cadr u;
        rhs := caddr u;
        if op memq '(lsetq lrsetq) and listp lhs then
            lhs := car lhs . foreach s in cdr lhs
                                collect list('eval, s);
        if op memq '(rsetq lrsetq) then
            rhs := list('eval, rhs);
        return formoptimize1(list('setq, lhs, rhs), vars, mode)
        end
    else
        ('list . foreach elt in u
                        collect formoptimize1(elt, vars, mode));

symbolic expr procedure sq2pre f;
    if atom f then
        f
    else if listp f and eqcar(f, '!*sq) then
        prepsq cadr f
    else
        prepsq f;


% ------------------------------------------------------------------- ;
%   CALL CODE OPTIMIZER                                               ;
% ------------------------------------------------------------------- ;

global '(!*again !*crunch !*prefix prefixlist);

switch crunch,again,prefix;

fluid '(!*gentranopt);

switch gentranopt;

symbolic expr procedure optimizeforms(forms, outfile, vname);
  begin scalar ch,holdch;
        if vname then iname vname;
        if outfile then << holdch:=wrs nil;
                           ch:=open(mkfil outfile,'output);
                           wrs ch >>; 
        if not ((!*crunch or !*again) and prefixlist) then init 200;
        foreach item in forms do ffvar!!(cadr item, caddr item);
        lispeval '(calc);
        if outfile then << wrs holdch; close ch >>
  end;


symbolic procedure opt forms;
    % --------------------------------------------------------------- ;
    %  Replace each sequence of one or more assignment(s) by its      ;
    %  optimized equivalent sequence.                                 ;
    % --------------------------------------------------------------- ;
    %
    % Called by Gentran to optimise a sequence of assignments (or
    % whatever).  We set the global flag GENTRANING!* to tell the
    % various bits of the optimiser that its been called via GENTRAN.
    % We don't use !*GENTRANOPT (as in the original code) because that
    % switch might be set perfectly legally while the optimiser is
    % being called directly, causing much unpleasantness.
    %
    % mcd 22/7/89
    %
    begin scalar seq, res;

        gentraning!* := 't;

        if atom forms then
            res := forms
        else if eqcar(forms, 'setq) then
        <<
            optimizeforms(list forms, nil, nil);
            res := foreach pr in prefixlist collect
                            list('setq, car pr, cdr pr);
            if onep length res
                then res := car res
                else res := mkstmtgp(0, res)
         >>
        else if atom car forms then
            res := (car forms . opt cdr forms)
        else
        <<
            seq := nil;
            while forms and listp car forms and eqcar(car forms, 'setq)
               do <<seq := (car forms . seq); forms := cdr forms>>;
            if seq then
            <<
                optimizeforms(reverse seq, nil, nil);
                seq := foreach pr in prefixlist collect
                            list('setq, car pr, cdr pr);
                if length seq > 1 then
                    seq := list mkstmtgp(0, seq);
                res := append(seq, opt forms)
            >>
            else
                res := (opt car forms . opt cdr forms);
        >>;

        % This would normally have been done by manageoutput.
        % mcd 22/7/89
        prefixlist:=preprefixlist:=nil;

        gentraning!* := 'nil;
        return res;
    end;


symbolic expr procedure subscriptedvarp v;
    % --------------------------------------------------------------- ;
    %  Returns t if and only if v has been declared to be a           ;
    %  subscripted variable name.                                     ;
    % --------------------------------------------------------------- ;
    length symtabget(nil, v) > 2;

global '(!*symboltable!*);

symbolic expr procedure dumpsymtab;
    begin scalar res;
    res :=
        foreach pn in !*symboltable!* conc
                list(
                     list('symtabput,mkquote pn, mkquote '!*type!*,
                                     mkquote symtabget(pn, '!*type!*)),
                     list('symtabput,mkquote pn, mkquote '!*params!*,
                                     mkquote symtabget(pn,'!*params!*)),
                     list('symtabput,mkquote pn, mkquote '!*decs!*,
                                     mkquote symtabget(pn, '!*decs!*))
                     );
    res := 'progn . list('setq,'!*symboltable!*,mkquote !*symboltable!*)
                   . res;
    return res
    end;

endmodule;


module codctl;  % Facilities for controlling the overall optimization.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Authors :   J.A. van Hulzen, B.J.A. Hulshof, M.C. van Heerwaarden.  ;
% ------------------------------------------------------------------- ;
% The content of CODCTL consists of facilities for controlling the    ;
% overall optimization process, making use of a number of global      ;
% variables and switches, and for the creation of an initial operating;
% environment for the optimization process.                           ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% The optimization process is initialized by applying the function    ;
% INIT, designed to create the initial state of the data strcutures,  ;
% used to store the input, which will bw subjected to a heuristic     ;
% search for common sub-expressions (cse's).                          ;
% During input translation the incidence matrix(CODMAT) is partly     ;
% made, by creating its row structure via FFVAR!!, given in the module;
% CODMAT.  Once input is processed the optimization activities are    ;
% activated by applying the function CALC.The kernel of the body of   ;
% this function is the procedure OPTIMIZE.First the function SSETVSARS;
% (see CODMAT module) is applied to complete the matrix CODMAT (column;
% creation), before performing the optimize-loop , being a repeated   ;
% search for cse's, using facilities, defined in the modules CODOPT   ;
% and CODAD1.  During these searches different cse-names for identical;
% cse's might be created,for instance due to EXPAND- and SHRINK-      ;
% activities (see CODOPT), an inefficiency repaired via IMPROVELAYOUT ;
% (see the module CODAD1). When either !*CRUNCH or !*AGAIN is T,      ;
% prefixlist is created (see CODPRI) without performing the finishing ;
% touch (see CODAD2). Then prefixlist is used,via the function        ;
% PROCESSPREFIXLIST, to combine this result with the next input set.  ;
% Output is created through the function MANAGEOUTPUT, which also     ;
% restores the REDUCE environment, which  existed  before the         ;
% optimization activities.                                            ;
% ------------------------------------------------------------------- ;

fluid '(!*fort !*optdecs);

global '(codmat endmat anop!* anop!^ !*acinfo prevlst !*sidrel maxvar
        rowmax rowmin !*priall !*primat codbexl!* !*prtinf !*prefix
        !*crunch !*again bnlst io!* ops nop!f inames kvarlst cname!*
        cindex!* optlang!* prefixlist preprefixlist varlst!* varlst!+)$

global '(gentraning!*); %mcd 22/7/89

switch  acinfo,sidrel,priall,primat,prtinf,prefix,crunch,optdecs,again$

% ------------------------------------------------------------------- ;
% Initial settings for the globals.                                   ;
% ------------------------------------------------------------------- ;
codmat:=!*priall:=!*primat:=!*sidrel:=!*optdecs:=optlang!*:=nil;
!*prtinf:=!*crunch:=!*again:=!*prefix:=nil;
rowmin:=maxvar:=anop!*:=anop!^:=nop!f:=0;
rowmax:=-1;
!*acinfo:=nil;    % MCD changed the default setting
bnlst:=nil;
io!*:=1;
ops:=list(0,0,0,0);

% ------------------------------------------------------------------- ;
% Description of global variables and switches.                       ;
% ------------------------------------------------------------------- ;
% MATRIX ACCESS:                                                      ;
%                                                                     ;
% CODMAT : is a vector used to store the +,* matrices,merged in CODMAT;
% MAXVAR : The size of this merged matrix is 2*MAXVAR.                ;
% ROWMAX : Largest actual row index.                                  ;
% ROWMIN : Smallest actual column index.                              ;
% ENDMAT : Value of MAXVAR when cse-search starts.                    ;
%                                                                     ;
% Remark - The storage strategy can be vizualized as follows:         ;
%                                                                     ;
%  MAXVAR + MAXVAR                                                    ;
%  -------|------------------------------------------------|          ;
%         | Storage left for cse's                         |          ;
%  -------|------------------------------------------------|          ;
%  MAXVAR + ROWMAX (ENDMAT when input processing completed)|          ;
%  -------|------------------------------------------------|          ;
%         | Matrix Rows:Input decomposition                |          ;
%  -------|------------------------------------------------|          ;
%  MAXVAR + 0                                              |          ;
%  -------|------------------------------------------------|          ;
%         | Matrix columns:Variable occurrence information |          ;
%  -------|------------------------------------------------|          ;
%  MAXVAR - ROWMIN                                         |          ;
%  -------|------------------------------------------------|          ;
%         | Storage left for cse-occurrence information    |          ;
%  -------|------------------------------------------------|          ;
%  MAXVAR - MAXVAR                                         |          ;
%                                                                     ;
%  OPERATOR COUNTS (Arithmetic Complexity)                            ;
%                                                                     ;
% The counts,mainly done with the procedure COUNTNOP,are based on the ;
% actual state of the incidence matrix CODMAT.However some resettings ;
% are performed outside this routine when replacing integer powers by ;
% repeated multiplications and when dealing with kernels,being        ;
% functions. This requires thus some global variables which can be    ;
% further used in COUNTNOP. The routine itself is activated when the  ;
% flag !*ACINFO is on.                                                ;
%                                                                     ;
% ANOP!* : Number of multilpications                                  ;
% ANOP!^ : Number of integer exponentiations                          ;
% Nop!f  : Number of functions                                        ;
% IO!*   : Integer used to control kind of counts. When even the input;
%          complexity is computed in a cumulative way.When odd the    ;
%          output complexity is computed.In case of input partitioning;
%          the reductions are given during intermediate steps and the ;
%          complexity of the final result is given at the end of the  ;
%          whole process.                                             ;
% OpS    : =(Nop!+,Nop!*,Nop!^,Nop!f)                                 ;
%          OpS is used in combination with input partitioning:        ;
%          OpS=0 and PreviousOutput=0                                 ;
%          REPEAT <<                                                  ;
%          Input:=Union(PreviousOutput,ContentNextInputSet)           ;
%          ACtemp:=COUNTNOP(Input)                                    ;
%          PRINT[AC(Input):=OpS:=OpS+ACtemp]                          ;
%          AC(Output):=COUNTNOP(OptimizedInput)                       ;
%          PRINT[ACreduction:=OpS:=AC(Input)-AC(Output)]              ;
%          UNTIL >> Ready(i.e. No NextInputSet)                       ;
%          PRINT[AC(Output after Finishing Touch)]                    ;
%                                                                     ;
%  CSE-NAME SELECTION                                                 ;
%                                                                     ;
%  Cname!* : Created in INAME and exploded representation of letter-  ;
%            part of current cse-name.                                ;
%  Cindex!*: Current cse-number. If cindex!*:=Nil then GENSYM() is use;
%  Bnlst   : List of initial cse-names. When !*AGAIN=T used to save   ;
%            these names via CSES:=('PLUS.Bnlst).If necessary extended;
%            with last GENSYM-generation(see MAKEPREFIXLIST). This    ;
%            assignment statement preceeds other output and is used in;
%            FFVAR!! (see module CODMAT) to flag all old cse-names    ;
%            with NEWSYM when continuing with next set of input files.;
%  Inames  : List of letterparts of elements of Bnlst,temporarily used;
%            in FFVAR!! for switch operations, needed to distinguish  ; 
%            expression recognizers and cse-names (see IMPROVELAYOUT).;
%                                                                     ;
%  The cse-name generation process is organized by the procedures     ;
%  INAME,NEWSYM1 and FNEWSYM. The procedure DIGITPART is needed in    ;
%  FFVAR!! (via RestoreCseInfo)  to restore the cse-name flags NEWSYM.;
%  This information is saved by SaveCseInfo (see MAKEPREFIXLST).      ;
%                                                                     ;
%  SWITCHES : THE ON-EFFECT IS DESCRIBED                              ;
%                                                                     ;
%    ACinfo   : (Evaluated) input and Operation counts displayed with-;
%               out disturbing Outfile declarations.                  ;
%    Primat   : Initial and final state of matrix CODMAT is printed.  ;
%    Prtinf   : Timings for subtasks printed.If T before INAME is used;
%               Bnlst is printed too.                                 ;
%    Priall   : Turns !*ACinfo,!*Primat and !*Prtinf on.              ;
%    Prefix   : Output in pretty printed prefixform.                  ;
%    Crunch   : A sequence of different but related input "sets" is   ;
%               processed. Finishing touch delayed if !*Again=T.      ;
%    Again    : Optimization of partioned input will be continued a   ;
%               next time. Cse's added to prefixlist and finishing    ;
%               touch delayed.                                        ;
%    SidRel   : The Optimizer output, collected in Prefixlist, is re- ;
%               written, using the procedure EvalPart, defined in this;
%               module, resulting in a list of (common sub)expressions;
%               with PLUS or DIFFERENCE as their leading operator.    ;
%    Optdecs :  The output is preceded by a list of declarations.     ;
%                                                                     ;
%  REMAINING GLOBALS                                                  ;
%                                                                     ;
%  Prefixlist : Association list defining output. Built in CODPRI-part;
%               2 and used either via VARPRI (ON FORT or ON/OFF NAT)  ; 
%               or via PRETTYPRINT (ON PREFIX) or in the procedure    ;
%               PROCESSPREFIXLIST to combine output with next input   ; 
%               file (ON CRUNCH).                                     ;
% Pre-                                                                ;
% Prefixlist :  Rational exponentiations require special provisions   ;
%               during parsing, such as the production of this list of;
%               special assignments, made as side-effect of the appli-;
%               cation of the function PrepMultMat in SSetVars (see   ;
%               the module CODMAT). This list is put in front of the  ;
%               list Prefixlist.                                      ;
%  Prevlst    : Used in FFVAR!! to store information about expression ;
%               hierarchy when translating input.                     ; 
%               Later used (initialized in SSETVARS) to obtain correct;
%               (sub)expression ordering.                             ;
%  Kvarlst    : Used for storing information about kernels.           ;
%  Optlang!*  : Its value ('FORTRAN, 'C, for instance) denotes the    ;
%               target language selection for the output production.  ;
%  CodBexl!*  : List consisting of expression recognizers. It guaran- ;
%               tees a correct output sequence. Its initial structure ;
%               is built in FFVAR!! and modified in IMPROVELAYOUT,for ;
%               instance, when superfluous intermediate cse-names are ;
%               removed.                                              ;
% ------------------------------------------------------------------- ;
                                                                       
symbolic procedure init n;
% ------------------------------------------------------------------- ;
% arg: Size of the matrix N.                                          ;
% eff: Initial state (re)created by (re)initializing the matrix CODMAT;
%      and some related identifiers.                                  ;
% ------------------------------------------------------------------- ;
begin scalar var;
  for y:=rowmin:rowmax do
  if row(y) and not numberp(var:=farvar y)
  then
  <<remprop(var,'npcdvar); remprop(var,'nvarlst);
    remprop(var,'varlst!+); remprop(var,'varlst!*);
    remprop(var,'rowindex);
    remprop(var,'nex); remprop(var,'inlhs);
  >>;
  if maxvar=n
    then for x:=0:2*n do putv(codmat,x,nil)
    else codmat:=mkvect(2*n);
  if kvarlst then 
               foreach item in kvarlst do remprop(cadr item,'kvarlst);
  foreach item in '(plus minus difference times expt sqrt) do
                                               remprop(item,'kvarlst);
  bnlst:=varlst!*:=varlst!+:=prevlst:=kvarlst:=codbexl!*:=nil;
  rowmax:=-1; maxvar:=n; 
  rowmin:=anop!*:=anop!^:=nop!f:=0;
  io!*:=1;ops:=list(0,0,0,0);
end;

symbolic procedure origst;
% ------------------------------------------------------------------- ;
% Original state  reset after error termination during optimization.  ;
% ------------------------------------------------------------------- ;
begin scalar var;
  for y:=rowmin:rowmax do
  if row(y) and not numberp(var:=farvar y)
  then
  <<remprop(var,'npcdvar); remprop(var,'nvarlst);
    remprop(var,'varlst!+); remprop(var,'varlst!*);
    remprop(var,'rowindex);
    remprop(var,'nex); remprop(var,'inlhs)
  >>;
  foreach item in kvarlst do remprop(cadr item,'kvarlst);
  foreach item in '(plus minus difference times expt sqrt) do
   remprop(item,'kvarlst);
  bnlst:=varlst!*:=varlst!+:=codmat:=prevlst:=kvarlst:=codbexl!*:=nil;
  rowmax:=-1;
  rowmin:=anop!*:=anop!^:=nop!f:=maxvar:=0;
  io!*:=1;ops:=list(0,0,0,0);
end;

% ------------------------------------------------------------------- ;
% REDUCE Interface for OrigSt, allowing the command OrigSt instead of ;
% OrigSt().                                                           ;
% ------------------------------------------------------------------- ;
put('origst,'stat,'endstat);

% ------------------------------------------------------------------- ;
symbolic procedure calc;
% ------------------------------------------------------------------- ;
% CALC produces,via OPTIMIZE,the association list PREFIXLIST. This    ;
% list is used,via PROCESSPREFIXLIST, to reinitialize CODMAT when     ;
% handling partioned input (ON CRUNCH).                               ;
% ------------------------------------------------------------------- ;
begin scalar fil,primat,acinfo,prtinf;
  if !*priall
  then                             % Save previous flag configuration.;
  <<primat:=!*primat;
    acinfo:=!*acinfo;
    prtinf:=!*prtinf;
    !*primat:=!*acinfo:=!*prtinf:=t
  >>;
  if !*sidrel
  then                             % Save previous flag configuration.;
  <<primat:=!*primat;
    acinfo:=!*acinfo;
    prtinf:=!*prtinf;
    !*primat:=!*acinfo:=!*prtinf:=nil
  >>;
  fil:=wrs(nil);              % Save name output file,which has to be ;
  optimize!!(fil);            % used for storing the final results    ;
  if !*crunch then processprefixlist();
  if !*priall or !*sidrel
  then                         % Restore original flag configuration. ;
  <<!*primat:=primat;
    !*acinfo:=acinfo;
    !*prtinf:=prtinf
  >>
end;

% ------------------------------------------------------------------- ;
% Reduce interface for CALC, allowing the command CALC instead of     ;
% CALC().                                                             ; 
% ------------------------------------------------------------------- ;

put('calc,'stat,'endstat);

symbolic procedure processprefixlist;
% ------------------------------------------------------------------- ;
% Contents of PREFIXLIST,i.e. output of some previous run is stored in;
% CODMAT.                                                             ;
% ------------------------------------------------------------------- ;
foreach item in prefixlist do ffvar!!(car item,cdr item);

symbolic procedure optimize!!(fil);
% ------------------------------------------------------------------- ;
% Once CODMAT is completed via SSETVARS optimization can start via    ;
% OPTIMIZELOOP. If !*CRUNCH=T then input partitioning, i.e.MAKEPREFIXL;
% is used to make the association-list PREFIXLIST and the process is  ;
% re-initialized via INIT. If NULL(!*CRUNCH) then MANAGEOUTPUT(actual ;
% Outfile name) is executed.                                          ;
% ------------------------------------------------------------------- ;
<<ssetvars();
  inames:=nil;
  if !*primat then primat();
  if !*acinfo then countnop();
  if !*prtinf then showtime;
  optimizeloop();
  if !*crunch
  then
  <<if !*acinfo then countnop();
    if !*primat
    then
    <<terpri();
      for x:=rowmin:rowmax do
      if farvar(x)=-1 or farvar(x)=-2
      then setoccup(x)
      else setfree(x);
      primat();
      terpri()
    >>;
    makeprefixl();
    init(maxvar);
  >>
  else if !*sidrel then makeprefixl()
                   else manageoutput(fil);
>>;

symbolic procedure optimizeloop;
% ------------------------------------------------------------------- ;
% Iterative cse-search.                                               ;
% ------------------------------------------------------------------- ;
begin scalar b1,b2,b3;
  repeat
  <<extbrsea();
    % --------------------------------------------------------------- ;
    % Extended Breuer search (see module CODOPT):                     ;
    % Common linear expressions or power products are heuristically   ;
    % searched for using methods which are partly based on Breuer's   ;
    % grow factor algorithm.                                          ;
    % --------------------------------------------------------------- ;
    if !*prtinf
    then
    <<terpri();
      write "Breuer search : ";
      showtime;
      terpri();
    >>;
    b1:=improvelayout();
    % --------------------------------------------------------------- ;
    % Due to search strategy, employed in EXTBRSEA, identical cse's   ;
    % can have different names. IMPROVELAYOUT (see module CODAD1 is   ;
    % used to detect such situations and to remove double names.      ;
    % --------------------------------------------------------------- ;
    if !*prtinf
    then
    <<terpri();
      write "Removal of different names for identical cse's : ";
      showtime;
      terpri();
    >>;
    b2:=tchscheme();
    % --------------------------------------------------------------- ;
    % Migration of information, i.e. the newly generated cse-names for;
    % linear expressions occuring as factor in a product are transfer-;
    % red from the + to the * scheme. Similar operations are performed;
    % for power products acting as terms. File CODAD1.RED contains    ;
    % TCHSCHEME.                                                      ;
    % --------------------------------------------------------------- ;
    if !*prtinf
    then
    <<terpri();
      write "Change Scheme : ";
      showtime;
      terpri();
    >>;
    b3:=codfac();
    % --------------------------------------------------------------- ;
    % Application of the distributive law,i.e. a*b + a*c is changed in;
    % a*(b + c) and expression storage in CODMAT is modified according;
    % ly. File CODAD1.RED contains CODFAC.                            ;
    % --------------------------------------------------------------- ;
    if !*prtinf
    then
    <<terpri();
      write "Local Factorization : ";
      showtime;
      terpri();
    >>;
  >>
  until not(b1 or b2 or b3);
end;

symbolic procedure manageoutput(outfil);
% ------------------------------------------------------------------- ;
% Essentially PRIRESULT is used to write output -the optimized version;
% of the input- on file OutFil. All remaining information produced via;
% COUNTNOP ,PRIMAT ,.... is given on the terminal.                    ;
% ------------------------------------------------------------------- ;
<<wrs(outfil);
  priresult();
  if getd('newsym) then remd('newsym);
  bnlst:=nil;
  wrs(nil);
  if !*acinfo
  then
  <<terpri();
    countnop();
    terpri();
  >>;
  if !*primat 
  then
  <<terpri();
    for x:=rowmin:rowmax do
    if farvar(x)=-1 or farvar(x)=-2
    then setoccup(x)
    else setfree(x);
    primat();
    terpri();
  >>;
  if !*prtinf then <<terpri(); showtime;terpri()>>;
  if null gentraning!*
    then prefixlist:=preprefixlist:=nil; % mcd 22/7/89
>>;

symbolic procedure countnop;
% ------------------------------------------------------------------- ;
% Counts and prints the number of (+,-) symbols,the number of * sym-  ;
% bols the number of integer exponentiations and function calls(inclu-;
% ding /).                                                            ;
% ------------------------------------------------------------------- ;
begin scalar s,zz,nop!+,nop!*,nop!^,qr,sign,freqtest,freq,var,temp!*,
                                              temp!f,temp!+,temp!^,dac;
  nop!+:=nop!^:=0; nop!*:=anop!*;
  io!*:=io!*+1;
  qr:=divide(io!*,2);
  if cdr(qr)=0
  then  % Input.
   << sign:=1; freqtest:=mkvect(rowmax)>>
  else % Output.
   << sign:=-1; nop!f:=length(kvarlst)+length(preprefixlist)>>;
  for x:=0:rowmax do
   if not (var:=farvar(x))=-1
    then
     << if cdr(qr)=0
        then
         <<if not numberp(var) 
            then 
             << freq:=get(var,'freq);
                if not numberp(freq) then freq:=1
                                     else remprop(var,'freq)
             >>
            else
             if not numberp(freq:=getv(freqtest,x)) then freq:=1
         >>
        else
         freq:=1;
        temp!*:=temp!+:=temp!^:=temp!f:=0;
        zz:=zstrt x; s:=opval(x);
        if s eq 'times
         then << if not (temp!*:=length zz + length(chrow x) -1)>0
                  then temp!*:=0;
                 if abs(expcof x)>1 then  temp!*:=temp!*+1;
                 foreach z in zz do
                  (if x memq (dac:=get(farvar xind z,'decreaseac))
                    then <<temp!f:=temp!f+1;
                           if dac:=delete(x,dac)
                            then put(farvar xind z,'decreaseac,dac)
                            else remprop(farvar xind z,'decreaseac)
                         >>
                    else if ival(z)>1 and null(bval z) 
                          then temp!^:=temp!^+1)
              >>
         else
          if s eq 'plus
           then << if not (temp!+:=length zz + length(chrow x) -1)>0
                    then temp!+:=0;
                   if expcof(x)>1 then temp!^:=temp!^ + 1;
                   foreach z in zz do
                   if abs(ival z)>1 and not ((farvar yind z) eq '!+one)
                    then temp!*:=temp!*+1
                >>;
         nop!*:=nop!* + freq*temp!*;
         nop!+:=nop!+ + freq*temp!+;
         nop!^:=nop!^ + freq*temp!^;
         nop!f:=nop!f + freq*temp!f;
         if freq>1 then
          foreach elem in chrow(x) do putv(freqtest,elem,freq)
     >>;
  if !*crunch or !*again
  then
   % ---------------------------------------------------------------- ;
   % A number of input sets has to be processed.                      ;
   % ---------------------------------------------------------------- ;
  <<nop!+:=sign*nop!++car(ops);
    nop!*:=sign*nop!*+cadr(ops);
    nop!^:=sign*nop!^+caddr(ops);
    nop!f:=sign*nop!f+cadddr(ops);
    ops:=list(nop!+,nop!*,nop!^,nop!f);
    if sign=1
    then
     % -------------------------------------------------------------- ;
     % Input information. OpS gives the number of operations in the   ;
     % first car(qr) input sets.                                      ;
     % -------------------------------------------------------------- ;
    <<terpri();
      if car(qr)=1
      then  write "Number of operations in the first input set:"
      else  write "Number of operations in the first ",car qr,
                                                       " input sets:";
      terpri()
    >>
    else
     % -------------------------------------------------------------- ;
     % Output information. OpS contains the thus far achieved         ;
     % reductions.                                                    ;
     % -------------------------------------------------------------- ;
    <<terpri();
      write "Total number of reductions is now:";
      terpri();
    >>
  >>
  else
   % ---------------------------------------------------------------- ;
   % One set to be optimized, or processing of the last set of a      ;
   % sequence.                                                        ;
   % ---------------------------------------------------------------- ;
    if sign=1
    then
     % -------------------------------------------------------------- ;
     % Input information. OpS superfluous when one set is handled.    ;
     % -------------------------------------------------------------- ;
    <<terpri();
      if car(qr)=1
      then write "Number of operations in the input is: "
      else write "Number of operations in the total input, i.e. in",
                 " the ", car qr, " input sets is: ";
      nop!+:=nop!++car(ops);
      nop!*:=nop!*+cadr(ops);
      nop!^:=nop!^+caddr(ops);
      nop!f:=nop!f+cadddr(ops);
      freqtest:=nil;
      terpri()
    >>
    else
     % -------------------------------------------------------------- ;
     % Output information.                                            ;
     % -------------------------------------------------------------- ;
    <<terpri();
      ops:=list(0,0,0,0);
      write "Number of operations after optimization is:";
      terpri();
      io!*:=1
    >>;
  terpri();
  write "Number of (+,-)-operations : ",nop!+;
  terpri();
  write "Number of (*)-operations : ",nop!*;
  terpri();
  write "Number of integer exponentiations : ",nop!^;
  terpri();
  write "Number of other operations : ",nop!f;
  terpri()
end;

symbolic procedure priresult;
% ------------------------------------------------------------------- ;
% Besides flag settings, file handling and the like the essential     ;
% action is performed by MAKEPREFIXL.                                 ;
% ------------------------------------------------------------------- ;
%
% Altered to make PREFIX work even if OPTLANG!* is non-null. mcd 22/7/89
%
begin scalar kvl,nat,fil,pfl;
  fil:=wrs(nil);
  kvl:=kvarlst;
  makeprefixl();
  kvarlst:=kvl;
  wrs(fil);
  if !*fort then optlang!* := 'fortran;
  if !*optdecs or gentraning!* then typeall prefixlist; % mcd 22/7/89
  if not gentraning!*
  then if optlang!*
       then << pfl := foreach pr in prefixlist collect
                          list('setq, car pr,lispcodeexp(cdr pr,'fp));
               pfl := list mkstmtgp(0, pfl);
               terpri();
               terpri();
               apply1(get(optlang!*, 'formatter),
                      apply1(get(optlang!*, 'codegen), pfl));
            >>
       else if !*prefix
            then << terpri();
                    write "Prefixlist:=";
                    terpri();
                    prettyprint(prefixlist);
                    terpri();
                 >>
            else << terpri();
                    if !*optdecs then printdecs();
                    terpri();
                    if not !*again
                     then
                      foreach item in prefixlist do
                       varpri(cdr item,list('setq,car item,'nil),t)
                     else
                      << nat:=!*nat; !*nat:=nil;
                         varpri(append(list('list),
                                foreach item in prefixlist
                                collect list('setq,car item,cdr item)),
                                nil,t);
                          write ";end;";!*nat:=nat 
                      >>;
                    terpri()
                  >>;
  if !*fort then optlang!*:=nil;
  if !*optdecs then !*optdecs:=nil
end;    
        
symbolic procedure printdecs;
% ------------------------------------------------------------------- ;
% A list of declarations is printed.                                  ;
% ------------------------------------------------------------------- ;
<< terpri!* t;
   for each typelist in formtypelists symtabget('!*main!*, '!*decs!*)
   do << prin2!* car typelist;
         prin2!* " ";
         inprint('!*comma!*, 0, cdr typelist);
         terpri!* t                 
      >>
>>;
        
symbolic procedure makeprefixl;
% ------------------------------------------------------------------- ;
% If the finishing touch is appropriate, i.e. if both OFF AGAIN and   ;
% OFF CRUNCH hold, PREPFINALPLST is called before producing PREFIXLIST;
% using a FOREACH-statement. If the optimization attempts have to be  ;
% continued during another session(i.e. OFF CRUNCH and ON AGAIN)      ;
% SAVECSEINFO is called to guarantee all relevant cse-information to  ;
% be saved.                                                           ; 
% ------------------------------------------------------------------- ;
<<prefixlist:=nil;
  anop!*:=anop!^:=0;
  if not (!*again or !*crunch) then prepfinalplst();
  for x:=0:rowmax do setfree(x);
  foreach bex in reverse(codbexl!*) do
  <<if numberp(bex)                % -------------------------------- ;
    then prfexp(bex)               % Leading operator is ^,*,+ or - . ;
    else prfkvar(bex);             % Another leading operator.        ;
  >>;                              % -------------------------------- ;
  % ----------------------------------------------------------------- ;
  % Possibly, information about primitive factors of the form         ;
  % ('EXPT <identifier> <rational exponent>) as given in the list     ;
  % PrePrefixlist is put in front of Prefixlist.                      ; 
  % ----------------------------------------------------------------- ;
  prefixlist:=append(preprefixlist,reverse(prefixlist));
  cleanupprefixlist();
  if !*sidrel then prefixlist:=evalpart prefixlist;
  if !*again then savecseinfo();
>>;
 
symbolic procedure prepfinalplst;
% ------------------------------------------------------------------- ;
% The refinements defined by this procedure - the socalled finishing  ;
% touch - are only applied directly before producing the final version;
% of the output, i.e. the optimized version of the input.             ;
% These refinements are:                                              ;
% - POWEROFSUMS (see module CODAD2): Replace (a+b+...)^intpower by    ;
%                                   cse1=(a+b+...),cse1^intpower.     ;
% - CODGCD     (see module CODAD2): Replace 4.a+2.b+2.c+4.d by        ;
%                                   2.(2.(a+d)+b+c),where a,b,c,d can ;
%                                   be composite as well.             ;
% - REMREPMULTVARS (see   CODAD2) : Replace 3.a+b,3.a+c by            ;
%                                   cse3=3.a,cse3+b,cse3+c.           ;
% - UPDATEMONOMIALS (see  CODAD2) : Replace 3.a.b, 3.a.c., 6.a.d,     ;
%                                   6.a.f by                          ;
%                                   cse4=3.a, cse4.b, cse4.c, cse5=6.a;
%                                   cse5.d, cse5.f.                   ;
% ------------------------------------------------------------------- ;
begin 
  powerofsums();
  remrepmultvars(); 
  updatemonomials();
   codgcd();
   if !*prtinf
   then
   <<terpri();
     write "Additional optimization during finishing touch :";
     showtime;
     terpri();
   >>;
  if not !*sidrel then preppowls();
  % ----------------------------------------------------------------- ;
  % PREPPOWLS (see module CODPRI, part 2) serves to create addition   ;
  % chains for integer powers, such as cse1^intpower (due to          ;
  % POWEROFSUMS) and cse4=a^3 (produced by UPDATEMONOMIALS).          ;
  % ----------------------------------------------------------------- ;
end;

symbolic procedure evalpart prefixl;
% ------------------------------------------------------------------- ;
% Evaluate partially the elements of Prefixlist leading to alist of   ;
% (sub)expressions, which have either PLUS or MINUS as their leading  ;
% operator.                                                           ;
% ------------------------------------------------------------------- ;
begin scalar newprefixlist,pair;
 while not null prefixl do
  <<if pair:=evalpart1 car prefixl
     then newprefixlist:=pair.newprefixlist;
   prefixl:=cdr prefixl
  >>;
 return(reverse(newprefixlist))
end;

symbolic procedure evalpart1 pair;
begin scalar x;
 if not (car(x:=reval cdr pair) memq '(plus difference)) and
    flagp(car pair,'newsym)
  then setk(car pair,mk!*sq simp!* x)
  else return (car pair).x
end;

symbolic procedure savecseinfo;
% ------------------------------------------------------------------- ;
% If ON AGAIN then cse-information have to be saved. This is done by  ;
% extending PREFIXLIST resulting in:                                  ;
% ((CSES.cses) (GSYM.gsym) PREFIXLIST) or                             ;
% ((CSES.cses) (BINF.binf) PREFIXLIST).                               ;
% Here                                                                ;
% CSES=first cse nsme[+...+ last cse name],                           ;
% GSYM=GENSYM(), if GENSYM has been used for cse-name generation,     ;
%      because we do not want to generate identical cse-names during a;
%      next run when using GENSYM.                                    ;
%      If GENSYM is not used then we create                           ;
% BINF=first initial cse-name[+...+ last initial cse-name],thus saving;
%      the Bnlst.                                                     ;
% ------------------------------------------------------------------- ;
begin scalar cses,gsym,binf;
 % Added tests to prevent taking car and cdr nil.  mcd 22/7/89
 foreach item in prefixlist do
  if pairp(item) and flagp( car(item),'newsym)
    then cses:=car(item).cses;
  if pairp(cses) then if cdr(cses) then cses:='plus.cses
                                   else cses:=car cses;
  prefixlist:=('cses.cses).prefixlist;
  if null(bnlst) or null(cindex!*) 
    then << gsym:=gensym();
            prefixlist:=('gsym.gsym).prefixlist >>;
  if bnlst then << if cdr bnlst then binf:='plus.bnlst 
                                else binf:=car bnlst;
                   prefixlist:=('binf.binf).prefixlist >>;
end;

symbolic procedure iname(nm);
% ------------------------------------------------------------------- ;
% Construction of initial cse-name, extension of Bnlst and creation of;
% NEWSYM procedure via MOVD and using NEWSYM1.                        ;
% If, for instance, the initial name is aa55 then NEWSYM1 generates   ;
% aa55, aa56 , aa57, etc.                                             ;
% ------------------------------------------------------------------- ;
  begin scalar digitl,dlst,nb,dg,initname;
      digitl:='((!1 . 1) (!2 . 2) (!3 . 3) (!4 . 4) (!5 . 5)
                (!6 . 6) (!7 . 7) (!8 . 8) (!9 . 9) (!0 . 0));
      cname!*:=nil;
      dlst:=reverse explode nm;
      repeat
%%%%
%%%%  <<if Numberp(dg:=Cdr(Assoc(Car dlst,digitl))) % takes (CDR NIL) !!
%%%%
      <<if (dg:=(assoc(car dlst,digitl))) and numberp (dg:=cdr dg)
%%%%
%%%%
         then << dlst:=cdr dlst;
                 nb:= dg.nb >>
         else << cname!*:=reverse dlst;
                 cindex!*:=0;
                 dg:=length(nb);
                 for i:=1:dg do
                  <<cindex!*:=10*cindex!*+car(nb);
                    nb:=cdr(nb)>> >>
      >>
      until cname!* or null(dlst);
      if null(bnlst) then movd('newsym,'newsym1);
      % ------------------------------------------------------------- ;
      % Bnlst is empty if INAME is used for the first time, i.e. if   ;
      % NEWSYM has to be identified with NEWSYM1.                     ;
      % ------------------------------------------------------------- ;
      initname:=newsym();
      cindex!*:=cindex!*-1;
      bnlst:=initname.bnlst;
      if !*prtinf then
      <<terpri();
        write "First cse-name is now:",initname;
        terpri();
        write "Initial names for cse-searches are:";
        terpri();
        prin2 bnlst;
        terpri();
      >>
end;

symbolic procedure movd(tod,fromd);
% ------------------------------------------------------------------- ;
% Transfer of a procedure description from Fromd to Tod.              ;
% ------------------------------------------------------------------- ;
begin scalar s;
  s:=getd(fromd);
  putd(tod,car s,cdr s);
end;
 
symbolic procedure newsym1();
% ------------------------------------------------------------------- ;
% Global variables:                                                   ;
% cname!* is exploded letterpart of current cse-name.                 ;
% cindex!* is current cse-index.                                      ;
% ------------------------------------------------------------------- ;
  begin scalar x;
        x:=explode cindex!*;
        cindex!*:=cindex!*+1;
        return compress append(cname!*,x)
  end;

symbolic procedure fnewsym;
begin scalar x;
  if getd('newsym) 
   then x:=newsym() 
   else << x:=gensym();
           x:=compress(append(explode(letterpart(x)),
                              explode(digitpart(x))))
        >>;
 % X:=Intern(X); % Might be necessary for some REDUCE systems;
  flag(list x,'newsym);
  return x;
end;

symbolic procedure letterpart(name);
% ------------------------------------------------------------------- ;
% Eff: Letterpart of Name returned,i.e. aa of aa55.                   ;
% ------------------------------------------------------------------- ;
begin scalar digitl,letters,el;
    digitl:='((!1 . 1) (!2 . 2) (!3 . 3) (!4 . 4) (!5 . 5)
                (!6 . 6) (!7 . 7) (!8 . 8) (!9 . 9) (!0 . 0));
    letters:=reverse explode name;
    % Tried to take cdr nil - fixed mcd 21/7/89
    while (el := assoc(car letters,digitl)) and numberp cdr el do 
      << letters:=cdr letters >>;
    return compress reverse letters;
end;

symbolic procedure digitpart(name);
% ------------------------------------------------------------------- ;
% Eff: Digitpart of Name returned,i.e. 55 of aa55.                    ;
% ------------------------------------------------------------------- ;
begin scalar digitl,nb,dg,dlst;
   digitl:='((!1 . 1) (!2 . 2) (!3 . 3) (!4 . 4) (!5 . 5)
                (!6 . 6) (!7 . 7) (!8 . 8) (!9 . 9) (!0 . 0));
   dlst:= reverse explode name;
   nb:=nil;
   % Tried to take cdr nil - fixed mcd 21/7/89 
   while (dg:=assoc(car dlst,digitl)) and numberp(dg := cdr dg) do
     << dlst:=cdr dlst; nb:=dg.nb >>;
   dg:=0;
   foreach digit in nb do dg:=10*dg+digit;
   return dg;
 end;

endmodule;


module codmat;  %  Support for matrix optimization.

% -------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer    ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands. ;
% Authors :   J.A. van Hulzen, B.J.A. Hulshof, M.C. van Heerwaarden,   ;
%             J.C.A. Smit.                                             ;
% -------------------------------------------------------------------- ;

% -------------------------------------------------------------------- ;
% The module CODMAT consists of two parts:                             ;
%  1 - A collection of Extended Access Functions to the CODMAT-matrix  ;
%      and the associated hashvector CODHISTO.                         ;
%  2 - Routines for constructing the incidence matrix CODMAT via par-  ;
%      sing and storage of a set of input expressions.                 ;
% -------------------------------------------------------------------- ;
%                                                                      ;
% -------------------------------------------------------------------- ;
% PART 1 : EXTENDED ACCESS FUNCTIONS                                   ;
% -------------------------------------------------------------------- ;
%                                                                      ;
% These functions allow to STORE,RETRIEVE or MODIFY information stored ;
% in CODMAT and CODHISTO, used for hashing.                            ;
% Remark:A detailed description of the vectors CODMAT and CODHISTO and ;
% their DIRECT ACCESS FUNCTIONS, heavily used here, is given in the    ;
% module COSYMP.                                                       ;
%                                                                      ;
% ------ A CLASSIFICATION OF THE EXTENDED ACCESS FUNCTIONS ------      ;
%                                                                      ;
% - STORAGE : SetRow,InsZZZ,InsZZZn,InsZZZr,PnthXZZ.                   ;
% - HISTOGRAM OPERATIONS : InsHisto,DelHisto,,Downwght,Downwght1,Upwght;
%   Upwght1,Initwght.                                                  ;
% - MODIFICATION : Rowdel,Rowins,RemZZZZ,Chdel,DelYZZ,Clearrow.        ;
% - PRINTING TESTRUNS : ChkCodMat.                                     ;
%                                                                      ;
% ------ TERMINOLOGY USED ------                                       ;
% ZZ stands for a Zstrt and Z for a single item in ZZ.  A Zstrt is a   ;
% list of pairs (row(column)index . coeff(exponent)information).Hence a;
% double linked list representation is used. Both X and Y denote indi- ;
% ces.The Cdr-part of a Z-element is in fact again a dotted pair (IVal.;
% BVal). The BValue however is only used in CODPRI.RED for printing    ;
% purposes,related to the finishing touch. Therefore we only take IVal ;
% as Cdr-part in the                                                   ;
% Example :                               +| a b c d                   ;
%  Let                                    -+---------                  ;
%  f =  a + 2*b + 3*c                     f| 1 2 3                     ;
%  g =2*a + 4*b + 5*d                     g| 2 4   5                   ;
%                                                                      ;
% Taking MaxVar=4 results in :                                         ;
%                                                                      ;
% CODMAT index=|I| |Zstrt ZZ            |                              ;
% -------------+-+-+--------------------+----------------------------- ;
% .......      | | |                    |Rows: Structure created by    ;
% .......      | | |                    |Fvar or FFvar using I=MaxVar+ ;
% .......      | | |                    |RowMax (See Row and FillRow,  ;
% Rowmax= 1    |5|g|((-4.5)(-2.4)(-1.2))|defined in module COSYMP      ;
% Rowmax= 0    |4|f|((-3.3)(-2.2)(-1.1))|and used in SETROW).          ;
% -------------+-+-+--------------------+----------------------------- ;
% Rowmin=-1    |3|a|((1.2)(0.1))        |Columns:Created by SSetVars(  ;
% Rowmin=-2    |2|b|((1.4)(0.2))        |part 2 of this module) : I=   ;
% Rowmin=-3    |1|c|((0.3))             |Maxvar+Rowmin. The Zstrts of  ;
% Rowmin=-4    |0|d|((1.5))             | the rows are also completed  ;
% .......      | | |                    | by SSetvars.                 ;
% -------------------------------------------------------------------- ;
%                                                                      ;
% Remarks :                                                            ;
% -1- The CODMAT index I used in the above example is thus the physical;
%     value of the subscript. This in contrast to the indices used when;
%     calling routines like SETROW, which operate on Rowmax or Rowmin  ;
%     values (details are given in CODCTL.RED and in the routine ROW in;
%     COSYMP.RED).                                                     ;
% -2- A similar picture is produced for f=a*b^2*c^3 and g=a^2*b^4*d^5. ;
%     When introducing monomials as terms or sum as factors also the   ;
%     Child-facilities have to be used like done for operators other   ;
%     than + or *.                                                     ;
% -------------------------------------------------------------------- ;

fluid '(!*fort);

global '(!*sidrel preprefixlist codmat maxvar rowmin
         rowmax endmat codhisto headhisto)$

switch sidrel$

% ____________________________________________________________________ ;
% A description of these globals is given in the module CODCTL         ;
% -------------------------------------------------------------------- ;

symbolic procedure setrow(n,op,fa,s,zz);
% -------------------------------------------------------------------- ;
% arg : N : Row(column)index of the row(column) of which the value has ;
%           to be (re)set. Physically we need MaxVar + N(see ROW in    ;
%           COSYMP.RED).                                               ;
%       Op: Operator value to be stored in Opval,i.e. 'PLUS,'TIMES or  ;
%           some other operator.                                       ;
%       Fa: For a row the name (toplevel) or index (subexpression) of  ;
%           the father.For a column the template of the column variable;
%       S : Compiled code demands atmost 5 parameters,atleast for some ;
%           REDUCE implementations. Therefore S stands for a list of   ;
%           Chrow information,if necessary extended with the monomial  ;
%           coefficient(Opval='TIMES) or the exponent of a linear ex-  ;
%           pression(Opval='PLUS),to be stored in the CofExp-field.    ;
%       ZZ: The Z-street.                                              ;
% eff : Row(column) N is created and set. If necessary,i.e. if N>MaxVar;
%       then CODMAT is doubled in size.                                ;
% -------------------------------------------------------------------- ;
begin scalar codmat1;
  if abs(n)>maxvar
  then % Double the size of CODMAT.
    <<codmat1:=mkvect(4*maxvar);
      for x:=max(rowmin,-maxvar):min(rowmax,maxvar) do
      putv(codmat1,x+2*maxvar,row x);
      codmat:=codmat1;
      maxvar:=2*maxvar;
    >>;
 % --------------------------------------------------------------------;
 % Now the values are set,using LenCol=4 and LenRow=8,i.e. the fields  ;
 % Chrow,CofExp,HiR and Ordr are not in use for columns because:       ;
 % - Chrow and CofExp are irrelevant for storing information about     ;
 %   variable occurrences.                                             ;
 % - Hashing(HiR) and CSE-insertion(Ordr) are based on row-information ;
 %   only.                                                             ;
 % --------------------------------------------------------------------;
  if n<0
  then fillrow(n,mkvect lencol)
  else
  <<fillrow(n,mkvect lenrow);
    setchrow(n,car s);
    if cdr s
    then setexpcof(n,cadr s)
    else setexpcof(n,1)>>;
  setfree(n);
  setopval(n,op);
  setfarvar(n,fa);
  setzstrt(n,zz)
end;

symbolic procedure inszzz(z,zz);
% -------------------------------------------------------------------- ;
% arg : Z : A matrix element.                                          ;
%       ZZ: A set of matrix elements with indices in descending order. ;
% eff : A set of matrix elements including Z and ZZ,again in ascending ;
%       order,such that in case Z's index already exists the Ival-     ;
%       pars of both element are added together.                       ;
% -------------------------------------------------------------------- ;
if null zz or xind(car zz)<xind(z)
then z.zz
else
  if xind(car zz)=xind(z)
  then <<setival(car zz,ival(car zz)+ival(z)); zz>>
  else car(zz).inszzz(z,cdr zz);

symbolic procedure inszzzn(z,zz);
% -------------------------------------------------------------------- ;
% eff : Similar to InsZZZ.However,Z is only inserted if its index is   ;
%       not occuring as car-part of one of the elements of ZZ.         ;
% -------------------------------------------------------------------- ;
if null(zz) or xind(car zz)<xind(z)
then z.zz
else
  if xind(car zz)=xind(z)
  then zz
  else car(zz).inszzzn(z,cdr zz);

symbolic procedure inszzzr(z,zz);
% -------------------------------------------------------------------- ;
% eff :  Similar to InsZZZ,but the indices of ZZ are now given in as-  ;
%        cending order.                                                ;
% -------------------------------------------------------------------- ;
if null(zz) or xind(car zz)>xind(z)
then z.zz
else
  if xind(car zz)=xind(z)
  then <<setival(car zz,ival(car zz)+ival(z)); zz>>
  else car(zz).inszzzr(z,cdr zz);

symbolic procedure pnthxzz(x,zz);
% -------------------------------------------------------------------- ;
% arg : X is a row(column)index and ZZ a Z-street.                     ;
% res : A sublist of ZZ such that Caar ZZ = X.                         ;
% -------------------------------------------------------------------- ;
if null(zz) or xind(car zz)=x
then zz
else pnthxzz(x,cdr zz);

symbolic procedure inshisto(x);
% -------------------------------------------------------------------- ;
% arg : Rowindex X.                                                    ;
% eff : X is inserted in the Histogram-hierarchy.                      ;
%                                                                      ;
% The insertion can be vizualized in the following way :               ;
%                                                                      ;
%    CODHISTO                 CODMAT                                   ;
%                                                                      ;
% index  value      Row Hwght      HiR                                 ;
%  200   +---+      index     (PHiR . NHiR)                            ;
%        |   |      .   .   .                                          ;
%        :   :      :   :   :                                          ;
%        |   |      :   :   :                                          ;
%        +---+      |   |   |                                          ;
%   i    | k | <--> +---+---+---------------+                          ;
%        +---+      | k | i |   Nil .  m    |                          ;
%        |   |      +---+---+---------------+                          ;
%        :   :      |   |   |               |                          ;
%        |   |      :   :   :               :                          ;
%        +---+      |   |   |               |                          ;
%   0    |   |      +---+---+---------------+                          ;
%        +---+      | m | i |     k .  p    |                          ;
%                   +---+---+---------------+                          ;
%                   |   |   |               |                          ;
%                   :   :   :               :                          ;
%                   |   |   |               |                          ;
%                   +---+---+---------------+                          ;
%                   | p | i |     m . Nil   |                          ;
%                   +---+---+---------------+                          ;
%                   :   :   :               :                          ;
%                                                                      ;
% -------------------------------------------------------------------- ;
if free(x) and x>=0
then
begin scalar y,hv;
  if y:=histo(hv:=hwght x)
  then setphir(y,x)
  else
    if hv>headhisto
    then headhisto:=hv;
  sethir(x,nil.y);
  sethisto(hv,x)
end;

symbolic procedure delhisto(x);
% -------------------------------------------------------------------- ;
% arg : Rowindex X.                                                    ;
% eff : Removes X from the histogram-hierarchy.                        ;
% -------------------------------------------------------------------- ;
if free(x) and x>=0
then
begin scalar y,z,hv;
  y:=phir x;
  z:=nhir x;
  hv:=hwght(x);
  if y then setnhir(y,z) else sethisto(hv,z);
  if z then setphir(z,y);
end;

symbolic procedure rowdel x;
% -------------------------------------------------------------------- ;
% arg : Row(column)index X.                                            ;
% eff : Row X is deleted from CODMAT. SetOccup ensures that row X is   ;
%       disregarded until further notice. Although the Zstrt remains,  ;
%       the weights of the corresponding columns are reset like the    ;
%       Histogram info.                                                ;
% -------------------------------------------------------------------- ;
<<delhisto(x);
  setoccup(x);
  foreach z in zstrt(x) do
  downwght(yind z,ival z)>>;

symbolic procedure rowins x;
% -------------------------------------------------------------------- ;
% arg : Row(column)index X.                                            ;
% eff : Reverse of the Rowdel operations.                              ;
% -------------------------------------------------------------------- ;
<<setfree(x);
  inshisto(x);
  foreach z in zstrt(x) do
  upwght(yind z,ival z)>>;

symbolic procedure downwght(x,iv);
% -------------------------------------------------------------------- ;
% arg : Row(column)index X. Value IV.                                  ;
% eff : The weight of row X is adapted because an element with value IV;
%       has been deleted.                                              ;
% -------------------------------------------------------------------- ;
<<delhisto(x);
  downwght1(x,iv);
  inshisto(x)>>;

symbolic procedure downwght1(x,iv);
% -------------------------------------------------------------------- ;
%  eff : Weight values reset in accordance with defining rules given in;
%        COSYMP.RED and further argumented in CODOPT.RED.              ;
% -------------------------------------------------------------------- ;
if abs(iv)>1
then setwght(x,((awght(x)-1).(mwght(x)-1)).(hwght(x)-4))
else setwght(x,((awght(x)-1).mwght(x)).(hwght(x)-1));

symbolic procedure upwght(x,iv);
% -------------------------------------------------------------------- ;
% arg : Row(column)index X. value IV.                                  ;
% eff : The weight of row X is adapted because an element with value IV;
%       is brought into the matrix.                                    ;
% -------------------------------------------------------------------- ;
<<delhisto(x);
  upwght1(x,iv);
  inshisto(x)>>;

symbolic procedure upwght1(x,iv);
% -------------------------------------------------------------------- ;
%  eff : Functioning similar to Downwght1.                             ;
% -------------------------------------------------------------------- ;
if abs(iv)>1
then setwght(x,((awght(x)+1).(mwght(x)+1)).min(hwght(x)+4,histolen))
else setwght(x,((awght(x)+1).mwght(x)).min(hwght(x)+1,histolen));

symbolic procedure initwght(x);
% -------------------------------------------------------------------- ;
% arg : Row(column)index X.                                            ;
% eff : The weight of row(column) X is initialized.                    ;
% -------------------------------------------------------------------- ;
begin scalar an,mn;
  an:=mn:=0;
  foreach z in zstrt(x) do
  if free(xind z)
  then
  <<if abs(ival z)>1 then mn:=mn+1;
    an:=an+1>>;
  setwght(x,((an.mn).min(an+3*mn,histolen)));
%  IF X>=0 THEN SetHiR(X,NIL.NIL); % To be sure;
end;

symbolic procedure remzzzz(zz1,zz2);
% -------------------------------------------------------------------- ;
% arg : Zstrt ZZ1 and ZZ2, where ZZ1 is a part of ZZ2.                 ;
% res : All elements of ZZ2, without the elements of ZZ2.              ;
% -------------------------------------------------------------------- ;
if null(zz1)
then zz2
else
  if yind(car zz1)=yind(car zz2)
  then remzzzz(cdr zz1,cdr zz2)
  else car(zz2).remzzzz(zz1,cdr zz2);

symbolic procedure chdel(fa,x);
% -------------------------------------------------------------------- ;
% arg : Father Fa of child X.                                          ;
% eff : Child X is removed from the Chrow of Fa.                       ;
% -------------------------------------------------------------------- ;
setchrow(fa,delete(x,chrow fa));

symbolic procedure delyzz(y,zz);
% -------------------------------------------------------------------- ;
% arg : Column(row)index Y. Zstrt ZZ.                                  ;
% res : Zstrt without the element corresponding with Y.                ;
% -------------------------------------------------------------------- ;
if y=yind(car zz)
then cdr(zz)
else car(zz).delyzz(y,cdr zz);

symbolic procedure clearrow(x);
% -------------------------------------------------------------------- ;
% arg : Rowindex X.                                                    ;
% eff : Row X is cleared. This can be recognized since the father is   ;
%       set to -1.                                                     ;
% -------------------------------------------------------------------- ;
<<setzstrt(x,nil);
  if x>=0 
  then
  <<setchrow(x,nil);
    if not numberp(farvar x)
    then remprop(farvar x,'rowindex)
  >>;
  setwght(x,nil);
  setfarvar(x,-1)
>>;

symbolic procedure chkcodmat;
% -------------------------------------------------------------------- ;
% eff : Checks whether the matrix is consistent.                       ;
% -------------------------------------------------------------------- ;
begin scalar z1,rowindx,colindx;
  for x:=rowmin:rowmax do
  if not farvar(x)=-1
  then
    foreach z in zstrt(x) do
    <<if x<0
      then <<colindx:=x; rowindx:=xind(z)>>
      else <<colindx:=yind(z); rowindx:=x>>;
      if not opval(colindx)=opval(rowindx)
      then
      <<terpri();
        write "Mixed entry detected in matrix for element (",rowindx,
              ",",colindx,")"
      >>;
      if null(z1:=assoc(x,zstrt yind z))
      then
      <<terpri();
        write "Entry (",rowindx,",",colindx,") missing in ",yind z,
              " or superfluous in ",x     
      >>
      else
        if not (val(z) eq val(z1))
        then
        <<terpri();
          write "Matrix entry not unique for (",rowindx,",",colindx,")"
        >>
    >>;
  for y:=rowmin:(-1) do
  if not farvar(y)=-1 and zstrt(y)
  then
  <<rowindx:=xind(car zstrt y);
    foreach z in cdr(zstrt y) do
    <<if not xind(z)<rowindx
      then
      <<terpri();
        write "Incorrect ordering for column ",y
      >>;
      rowindx:=xind(z);
    >>
  >>;
  for x:=0:rowmax do
  if not farvar(x)=-1
  then
  <<if zstrt(x)
    then
    <<colindx:=yind(car zstrt x);
      foreach z in cdr(zstrt x) do
      <<if not yind(z)>colindx
        then
        <<terpri();
          write "Incorrect ordering for row ",x
        >>;
        colindx:=yind(z)
      >>
    >>;
    if numberp(farvar x) and not member(x,chrow farvar x)
    then
    <<terpri();
      write "Father-Child link fails for father ",farvar x," and child "
      ,x
    >>;
    foreach ch in chrow(x) do
    if not farvar(ch)=x
    then
    <<terpri();
      write "Father-Child link fails for father ",x," and child ",ch
    >>
  >>;
  terpri();write "It was my pleasure!";terpri();
end;



% -------------------------------------------------------------------- ;
% PART 2 : PROCEDURES FOR THE CONSTRUCTION OF THE MATRIX CODMAT,i.e.   ;
%          FOR INPUT PARSING                                           ;
% -------------------------------------------------------------------- ;
%                                                                      ;
% ------ GENERAL STRATEGY ------                                       ;
% REDUCE assignment statements of the form "Nex:=Expression" are trans-;
% formed into pairs (Nex,Ex(= prefixform of the Expression)), using    ;
% GENTRAN-facilities.The assignment operator := defines a literal trans;
% lation of  both Nex and Ex. Replacing this operator by :=: results in;
% translation of the simplified form of Ex. When taking ::=: or ::= the;
% Nex is evaluated before translation, i.e. the subscripts occurring in;
% Nex are evaluated before the translation is performed.               ;
% Once input reading is completed(i.e. when calling CALC) the data-    ;
% structures can and have to be completed (column info and the like)   ;
% using SSETVARS (called in OPTIMIZE (see CODCTL.RED)) before the CSE- ;
% search actually starts.                                              ;
%                                                                      ;
% ------ PRESUMED EXPRESSION STRUCTURE ------                          ;
% Each expression is considered to be an (exponentiated) sum,a product ;
% or something else and to consist of an (eventually empty) primitive  ;
% part and an (also eventually empty) composite part. The primitive    ;
% part of a sum is a linear combination of atoms(variables) and its    ;
% composite part consists of terms which are products or functions. The;
% primitive part of a product is a monomial in atoms and its composite ;
% part is formed by factors which are again expressions(Think of OFF   ;
% EXP).Primitive parts are stored in Zstrts as lists of pairs (RCindex.;
% COFEXP). Composite parts are stored in and via Chrows.               ;
% The RCindex denotes a Row(Column)index in CODMAT if the Zstrt defines;
% a column(row). Rows describe primitive parts. Due to the assumption  ;
% that the commutative law holds column information is not completely  ;
% available as long as input processing is not finished.               ;
% Conclusion : Zstrts cannot be completed (by SSETVARS in CALC or in   ;
% HUGE (see CODCTL.RED)) before input processing is completed,i.e.tools;
% to temporarily store Zstrt info are required. They consist of certain;
% lists,which are built up during parsing, being :                     ;
% The identifiers Varlst!+, Varlst!*  and Kvarlst play a double role.  ;
% They are used as indicators in certain propertylists and also as glo-;
% bal variables carrying information during parsing and optimization.  ;
% To distinguish between these two roles we quote the indicator name   ;
% in the comment given below.                                          ;
% -- Varlst!+  : A list of atoms occuring in primitive sum parts of the;
%                input expressions,i.e. variables used to construct the;
%                sum part of CODMAT.                                   ;
% -- 'Varlst!+ : The value of this indicator,associated with each atom ;
%                of Varlst!+, is a list of dotted pairs (X,IV),where X ;
%                is a rowindex and IV a coefficient,i.e.IV*atom occurs ;
%                as term of a primitive part of some input expression  ;
%                defined by row X.                                     ;
% -- Varlst!*  : Similar to Varlst!+ when replacing the word sum by mo-;
%                nomial and the word coefficient by exponent.          ;
% -- 'Varlst!* : The value of this indicator,occuring on the property  ;
%                list of each element of Varlst!*, is  a list of dotted;
%                pairs of the form (X.IV),where X is a rowindex and IV ;
%                an exponent,i.e. atom^IV occurs as factor in a mono-  ;
%                mial,being a primitive (sub)product,defined through   ;
%                row X.                                                ;
% Remark : Observe that it is possible that an atom possesses both     ;
% 'Varlst!+ and 'Varlst!*,i.e. plays a role in the + - and in the * -  ;
% part of CODMAT.                                                      ;
% -- Kvarlst   : A list of dotted pairs (var.F),where var is an identi-;
%                fier (system selected via FNEWSYM,if necessary) and   ;
%                where F is a list of the form (Functionname . (First  ;
%                argument ... Last argument)). The arguments are either;
%                atoms or composite,and in the latter case replaced by ;
%                a system selected identifier. This identifier is asso-;
%                ciated with the CODMAT-row which is used to define the;
%                composite argument.                                   ;
%                Remark : Kvarlst is also used in CODPRI.RED to guaran-;
%                tee the F's to be printed in due time,i.e.directly    ;
%                after all its composite arguments.                    ;
% -- 'Kvarlst  : This indicator is associated with each operator name  ;
%                during input processing. Its value consists of a list ;
%                of pairs os the form (F.var). To avoid needless name- ;
%                selections this list if values is consulted whenever  ;
%                necessary to see of an expression of the form F is    ;
%                already associated with a system selected identifier. ;
%                As soon as input processing is completed the 'Kvarlst ;
%                values are removed.                                   ;
% -- Prevlst   : This list is also constructed during input processing.;
%                It is a list of dotted pairs (Father.Child),where     ;
%                Child is like Father a rowindex or a system selected  ;
%                identifier name. Prevlst is employed,using SETPREV,to ;
%                store in the ORDR-field of CODMAT-rows relevant info  ;
%                about the structure of the input expressions. During  ;
%                the iterative CSE-search the ORDR-info is updated when;
%                ever necessary.                                       ;
% -- CodBexpl!*: A list consisting of CODMAT-row indices associated    ;
%                with input expression toplevel(i.e. the FarVar-field  ;
%                contains the expression name).                        ;
%                This list is used on output to obtain a correct input ;
%                reflection (see procedures MAKEPREFIXL and PRIRESULT  ;
%                in CODCTL.RED).                                       ;
%                                                                      ;
% ------ PARSING PATHS and PROCEDURE CLASSIFICATION ------             ;
% A prefix-form parsing is performed via FFVAR!!,FFVAR!* and FFVAR!+.  ;
% During parsing,entered via FFVAR!!, the procedure FVAROP is used to  ;
% analyse and transform functions( Operators in the REDUCE terminology);
% and thus also to construct Kvarlst and Prevlst. FVAROP is indirectly ;
% activated through the routines PVARLST!* and PVARLST!+, which assist ;
% in preparing (')Varlst!* and (')Varlst!+,respectively.               ;
% FCOFTRM ,assisting in detecting prim.parts, is used in FFVAR!!2.     ;
% PPRINTF is used (in FFVAR!!) to obtain an input echo on the terminal ;
% (when ON ACINFO, the default setting, holds).                        ;
% RESTORECSEINFO serves to restore the CSE-info when combining the re- ;
% sult of a previous session with the present one( see also CODCTL.RED);
% SSETVARS,and thus SSETVARS1, serves to complete CODMAT once input    ;
% processing is finished. PREPMULTMAT is used to preprocess *-columns  ;
% if one of the exponents, occuring in it, is rational, i.e. when the  ;
% with this column corresponding indentifier has the flag Ratexp.      ;
% SETPREV is used for maintaining consistency in input expression orde-;
% ring and thus for consequent information retrieval at a later stage, ;
% such as during printing.                                             ;
% -------------------------------------------------------------------- ;
global '(varlst!+ varlst!* kvarlst prevlst !*acinfo nop!f anop!* 
                                         preprefixlist codbexl!* bnlst);

varlst!+:=varlst!*:=kvarlst:=nil;

% -------------------------------------------------------------------- ;
% ------ THE PREFIX FORM PARSING  ------                               ;
% FFvar!! is the main procedure activating parsing. Besides some house-;
% keeping,information is send to either FFvar!* (either a product (but ;
% not a prim. term) or a 'EXPT-application) or FFvar!+(a  sum or a     ;
% function application).                                               ;
% The parsing is based on the following Prefix-Form syntax:            ;
% -------------------------------------------------------------------- ;
% This syntax needs some revision!!!                                   ;
% -------------------------------------------------------------------- ;
% <expression>           ::= <sumform>|<productform>                   ;
% <sumform>              ::= <sum>|('EXPT <sum> <exponent>)            ;
% <productform>          ::= <product>|                                ;
%                            ('TIMES <constant> <factor>)|             ;
%                            ('TIMES <constant> <list of factors>)|    ;
%                            ('MINUS <productform>)                    ;
% <sum>                  ::= <term>|('PLUS.<list of terms>)            ;
% <list of terms>        ::= (<term> <term>)|(<term> <list of terms>)  ;
% <term>                 ::= <primitive term>|<productform>|<sumform>  ;
% <primitive term>       ::= <constant>|<variable>|                    ;
%                            ('TIMES <constant> <variable>)|           ;
%                            <function application>                    ;
% <product>              ::= <factor>|('TIMES.<list of factors>)       ;
% <list of factors>      ::= (<factor> <factor>)|(<factor> <list of    ;
%                                                             factors>);
% <factor>               ::= <primitive factor>|<sumform>|<productform>;
% <primitive factor>     ::= <variable>|('EXPT <variable> <exponent>)| ;
%                            <function application>                    ;
% <function application> ::= <function symbol>.<list of expressions>   ;
% <function symbol>      ::= identifier, where identifier is not       ;
%                            in {'PLUS,'TIMES,'EXPT,'MINUS,'DIFFERENCE,;
%                                'SQRT,dmode!*}.                       ;
%                            Obvious elements are sin,cos,tan,etc.     ;
%                            The function applications are further     ;
%                            analyzed in FvarOp.                       ;
% <list of expressions>  ::= (<expression>)|<expression>.<list of      ;
%                                                          expressions>;
% <variable>             ::= element of the set of variable names,     ;
%                            either delivered as input or produced by  ;
%                            the Optimizer when the need to introduce  :
%                            cse-names exists. This is done with the   ;
%                            procedure FNewSym(see CODCTL.RED) which is;
%                            initiated either using the result of the  ;
%                            procedure INAME(see CODCTL.RED) or simply ;
%                            by using GENSYM().                        ;
% <constant>             ::= element of the set of integers            ;
%                            representable by REDUCE | domain element  ;
% <exponent>             ::= element of the set of integer an rational ;
%                            numbers representable by REDUCE.          ;
% -------------------------------------------------------------------- ;

symbolic procedure ffvar!!(nex,ex);
% -------------------------------------------------------------------- ;
% arg : An expression Ex in Prefix-Form, and its associated name NEx.  ;
% eff : The expression Ex is added to the incidence matrix CODMAT.     ;
%       Parsing is based on the above given syntax.                    ;
% -------------------------------------------------------------------- ;
begin scalar n, nnex, var;
 if nex memq '(cses gsym binf)
 then restorecseinfo(nex,ex)
 else
 << n:=rowmax:=rowmax+1;
    codbexl!*:=n.codbexl!*;
    if not atom nex
     then
      << nnex:=fnewsym(); nex:=remdiff nex;
         put(nnex,
             'nex,
             car(nex) .
              foreach arg in cdr nex collect if pairp arg
               then <<var:=fvarop(arg,n);put(var,'inlhs,nnex);var>>
               else arg
            )
      >>
     else nnex := nex;
     if atom(nex) and flagp(nex,'newsym) then put(nex,'rowindex,n);
     if !*acinfo and not(!*sidrel) then pprintf(ex,nex);
     ffvar!!2(n,nnex,remdiff ex)
 >>
end;

symbolic procedure restorecseinfo(nex,ex);
% -------------------------------------------------------------------- ;
% arg : Nex is an element of the set {CSES,GSYM,BINF} and Ex a corres- ;
%       pondig information carrier.                                    ;
% eff : RestoreCseInfo is called in FFvar!! when during input parsing  ;
%       name Nex belongs to the above given set. In this case the input;
%       is coming from a file which is prepared during a previous run. ;
%       It contains all output from this previous run, preceded by     ;
%       system prepared cse-info stored as value of the 4 system       ;
%       variables CSES,GSYM and BINF (see the function SaveCseInfo  in ;
%       CODCTL.RED for further information).                           ;
% -------------------------------------------------------------------- ;
begin scalar inb,nb;
if nex eq 'cses 
 then (if atom(ex) then flag(list ex,'newsym)
                   else foreach el in cdr(ex) do flag(list el,'newsym));
if nex eq 'gsym
 then << nb:=digitpart(ex);
         inb:=digitpart(gensym());
         for j:=inb:nb do gensym() >>;
 if nex eq 'binf 
  then ( if atom(ex) then bnlst:=reverse(ex.reverse(bnlst))
                     else bnlst:=append(bnlst,cdr(ex)) );
end;

symbolic procedure remdiff f;
% -------------------------------------------------------------------- ;
% Replace all occurrences of (DIFFERENCE A B) in F for arbitrary A and ;
% B by (PLUS A (MINUS B)).                                             ;
% -------------------------------------------------------------------- ;
if atom(f) then f
 else
  if car(f) eq 'difference 
   then f:=list('plus,remdiff cadr f,list('minus,remdiff caddr f))
   else car(f) . (foreach op in cdr(f) collect remdiff(op));

symbolic procedure ffvar!!2(n, nex, ex);
% -------------------------------------------------------------------- ;
% Serviceroutine used in FFvar!!.                                      ;
% -------------------------------------------------------------------- ;
  if eqcar(ex, 'times) and not fcoftrm ex
   then setrow(n, 'times, nex, ffvar!*(cdr ex, n), nil)
   else
    if eqcar(ex, 'expt) and (numberp(caddr ex) or rationalexponent(ex))
     then setrow(n, 'times, nex, ffvar!*(list ex, n), nil)
     else setrow(n, 'plus, nex, ffvar!+(list ex, n), nil);

symbolic procedure fcoftrm f;
% -------------------------------------------------------------------- ;
% arg : A prefix form F.                                               ;
% res : T if F is a (simple) term with an integer coefficient, NIL     ;
%       otherwise.                                                     ;
% -------------------------------------------------------------------- ;
(null(cdddr f) and cddr f) and
(numberp(cadr f) and not (pairp(caddr f) and 
      caaddr(f) memq '(expt times plus difference minus)));

symbolic procedure rationalexponent(f);
% -------------------------------------------------------------------- ;
% arg : F is an atom or a  prefixform.                                 ;
% res : T if F is an 'EXPT with a rational exponent.                   ;
% -------------------------------------------------------------------- ;
(pairp caddr f) and (caaddr f eq 'quotient) and (numberp(cadr caddr f)
                                            and numberp(caddr caddr f));

symbolic procedure pprintf(ex,nex);
% -------------------------------------------------------------------- ;
% arg : The name Nex of an experssion Ex.                              ;
% eff : Nex:=Ex is printed using Varpri on the output medium without   ;
%       disturbing the current file management and output flagsettings.;
% -------------------------------------------------------------------- ;
begin scalar s,fil,fort,nat;
  terpri();
  fil:=wrs(nil);
  if not(!*nat) or !*fort then << s:=t;
                                  nat:=!*nat;
                                  !*nat:=t;
                                  fort:=!*fort;
                                  !*fort:=nil >>;
  varpri(ex,list('setq,nex,'nil),t);
  wrs(fil);
  if s then << !*nat:=nat;
               !*fort:=fort >>;
end;


symbolic procedure ffvar!+(f,ri);
% -------------------------------------------------------------------- ;
% arg : F is a list of terms,i.e. th sum SF='PLUS.F is parsed. Info    ;
%       storage starts in row RI resulting in                          ;
% res : a list (CH) formed by all the indices of rows where the descrip;
%       tion of children(composite terms) starts. As a by product(via  ;
% eff : PVARLST!+) the required Zstrt info is made.                    ;
% N.B.: Possible forms for the terms of SF( the elements of F) are:    ;
%       -a sum     - which is recursively managed after minus-symbol   ;
%                    distribution.                                     ;
%       -a product - of the form constant*atom : which is as term of a ;
%                    prim. sum treated by PVARLST!+.                   ;
%                    of another form : which is managed via FFVAR!*.   ;
%       -a constant                                                    ;
%            power - of a product of atoms : is transformed into a prim;
%                    product and then treated as such.                 ;
%                    of something else : is always parsed via FFVAR!*. ;
%       -a function- application is managed via PVARLST!+,i.e. via     ;
%                    FVAROP with additional Varlst!+ storage of system ;
%                    selected subexpression names.                     ;
% -------------------------------------------------------------------- ;
begin scalar ch,n,s,b,s1;
  foreach trm in f do
  <<b:=s:=nil;
    while pairp(trm) and (s:=car trm) eq 'minus do
    <<trm:=cadr trm;
      b:=not b>>;
    if s eq 'difference
     then 
     <<trm:=list('plus,cadr trm,list('minus,caddr trm));
       s:='plus>>;
    if s eq 'plus
     then
     <<s1:=ffvar!+(if b
                   then foreach el in cdr(trm) collect list('minus,el)
                   else cdr trm,ri);
       ch:=append(ch,car s1)>>
     else
      if s eq 'times
     then
      <<% ------------------------------------------------------------ ;
        % Trm is a <productform>, which might have the form            ;
        % ('TIMES <constant> <function application>). Here the         ;
        % <function application> can be ('SQRT <expression>) , i.e. has;
        %  to be changed into :                                        ;
        % ('TIMES <constant> ('EXPT <expression> ('QUOTIENT 1 2)))     ;
        % ------------------------------------------------------------ ;
        if pairp caddr trm and caaddr trm eq 'sqrt and null cdddr trm
        then
          trm := list('times,cadr trm,list('expt,cadr caddr trm,
                                                  list('quotient,1,2)));
        if fcoftrm trm
          % ---------------------------------------------------------- ;
          % Trm is ('TIMES <constant> <variable>)                      ;
          % ---------------------------------------------------------- ;
         then pvarlst!+(caddr trm,ri,if b then -cadr trm else cadr trm)
         else
          % ---------------------------------------------------------- ;
          % Trm is a <productform>                                     ;
          % ---------------------------------------------------------- ;
         <<n:=rowmax:=rowmax+1;
           s1:=ffvar!*(cdr trm,n);
           if b
            then setrow(n,'times,ri,list(car s1,-cadr s1),nil)
            else setrow(n,'times,ri,s1,nil);
           ch:=n.ch>>
        >>
        else
        <<if s eq 'sqrt
          then
          % ---------------------------------------------------------- ;
          % Trm is a <primitive term> which is a <function application>;
          % which is ('SQRT <expression>) which is of course           ;
          % ('EXPT <expression> <exponent>)                            ;
          % ---------------------------------------------------------- ;
          <<trm := cons('expt,cons(cadr trm,list list('quotient,1,2)));
            s := 'expt
          >>;
          if s eq 'expt and
                          (numberp(caddr trm) or rationalexponent(trm))
          then
          <<n:=rowmax:=rowmax+1;
            s1:=ffvar!*(list trm,n);
            if b
             then setrow(n,'times,ri,list(car s1,-1),nil)
             else setrow(n,'times,ri,s1,nil);
            ch:=n.ch
          >>
          else pvarlst!+(trm,ri,if b then -1 else 1)
        >>;
  >>;
  return list(ch)
end;

symbolic procedure pvarlst!+(var,x,iv);
% -------------------------------------------------------------------- ;
% arg : Var is one of the first 2 alternatives for a kernel,i.e. a vari;
%       able or an operator with a simplified list of arguments (like  ;
%       sin(x)) with a coefficient IV,belonging to a Zstrt which will  ;
%       be stored in row X.                                            ;
% eff : If the variable happens to be a constant a special internal var;
%       !+ONE is introduced to assist in defining the constant contribu;
%       tions to primitive sumparts in accordance with the chosen data-;
%       structures.                                                    ;
%       When Var is an operator(etc.) Fvarop is used for a further ana-;
%       lysis and a system selected name for var is returned. Then this;
%       name,!+ONE or the variable name Var are used to eventually     ;
%       extend Varlst!+ with a new name.The pair (rowindex.coeff.value);
%       is stored on the property list of this var as pair of the list ;
%       'Varlst!+,which is used in SSETVARS1 to built the Zstrts associ;
%       ated with this variable.                                       ;
% -------------------------------------------------------------------- ;
begin scalar s;
  if numberp var then <<iv:=iv*var; var:='!+one>>;
  if not atom(var) then var:=fvarop(var,x);
  if null(s:=get(var,'varlst!+)) then varlst!+:=var.varlst!+;
  put(var,'varlst!+,(x.iv).s)
end;

symbolic procedure ffvar!*(f,ri);
% -------------------------------------------------------------------- ;
% arg : F is a list of factors,i.e. the product PF='TIMES.F is parsed. ;
%       Info storage starts in row RI,resulting in                     ;
% res : a list (CH COF),where CH is a list of all the indices of rows  ;
%       where the description of children of PF(composite factors)     ;
% eff : starts. As a by product(via the procedure PVARLST!*) Zstrt info;
%       is made.                                                       ;
% N.B.: Possible forms for the factors of PF( the elements of F) are:  ;
%       -a constant- contributing as factor to COF.                    ;
%       -a variable- contributing as factor to a prim.product,stored in;
%                    a Zstrt(via SSETVARS) after initial management via;
%                    PVARLST!* and storage in Varlst!* and 'Varlst!*'s.;
%       -a product - Recursively managed via FFVAR!*,implying that CH:=;
%                    Append(CH,latest version created via FFVAR!* and  ;
%                    denoted by Car S).                                ;
%       -a sum     - (or difference or negation) contributing as comp. ;
%                    factor and demanding a subexpression row  N to    ;
%                    start its description. Storage management is done ;
%                    via FFVAR!+,implying that CH:=N.CH.               ;
%       -a power   - of the form sum^integer : and managed like a sum. ;
%                    of the form atom^integer: and managed like single ;
%                    atom as part of a prim. product.                  ;
%       -a function- application,which is managed via PVARLST!*,i.e.via;
%                    FVAROP with additional Varlst!* storage of system ;
%                    selected subexpression names.                     ;
% -------------------------------------------------------------------- ;
begin scalar cof,ch,n,s,b,rownr,pr;
  cof:=1;
  foreach fac in f do
   if numberp fac
    then cof:=fac*cof
    else
     if atom fac
      then pvarlst!*(fac,ri,1)
      else
       if (s:=car fac) eq 'times
        then
         <<s:=ffvar!*(cdr fac,ri);
           ch:=append(ch,car s);
           cof:=cof*cadr(s)
         >>
        else
         if s memq '(plus difference minus)
          then
           <<n:=rowmax:=rowmax+1;
             if (not b) then <<b:=t; rownr:=n>>;
             setrow(n,'plus,ri,ffvar!+(list fac,n),nil);
             ch:=n.ch
           >>
          else
          <<if s eq 'sqrt
            then
            % -------------------------------------------------------- ;
            % The primitive factor is a <function application>. In this;
            % case a ('SQRT <expression>) which is of course           ;
            % ('EXPT <expression> ('QUOTIENT 1 2)).                    ;
            % -------------------------------------------------------- ;
            <<fac:=cons('expt,cons(cadr fac,list list('quotient,1,2)));
              s:='expt
            >>;
            if s eq 'expt and 
               (numberp(caddr fac) or rationalexponent(fac))
            then % --------------------------------------------------- ;
                 % Fac = (EXPT <expression or variable>                ;
                 %                       <integer or rational number>) ;
                 % --------------------------------------------------- ;
                 pvarlst!*(cadr fac,ri,
                           if numberp(caddr fac)
                            then caddr fac
                            else (cadr caddr fac . caddr caddr fac))
            else pvarlst!*(fac,ri,1)
          >>;
  if b and cof > 1
   then
    % ---------------------------------------------------------------- ;
    % The product Cof*....*(c1*a+....+cn*z) is replaced by             ;
    % the product ....*({Cof*c1}*a+...+{Cof*cn}*z), assuming Cof, c1,..;
    % ..,cn are numerical constants.                                   ;
    % ---------------------------------------------------------------- ;
    << foreach el in chrow(rownr) do setexpcof(el,cof*expcof(el));
       foreach var in varlst!+ do
                         if (pr:=assoc(rownr,get(var,'varlst!+)))
                          then rplacd(pr,cdr(pr)*cof);
       cof:=1; anop!*:=1+anop!* 
                                   
    >>;
  return list(ch,cof)
end;

symbolic procedure pvarlst!*(var,x,iv);
% -------------------------------------------------------------------- ;
%  eff : Similar to Pvarlst!+.                                         ;
%      : The flag Ratexp is associated with Var if one of its exponents;
%        is rational. This flag is used in the function PrepMultMat.   ;
% -------------------------------------------------------------------- ;
begin scalar s;
 if numberp(var)
  then
   <<var:=fvarop(if iv='(1 . 2) then list('sqrt,var)
                  else list('expt,var,list('quotient,car iv,cdr iv)),x);
     iv:=1>>;
 if not atom(var) then var:=fvarop(var,x);
 if null(s:=get(var,'varlst!*)) then varlst!*:=var.varlst!*;
 if pairp(iv) then flag(list(var),'ratexp);
 put(var,'varlst!*,(x.iv).s)
end;

symbolic procedure fvarop(f,x);
% -------------------------------------------------------------------- ;
% arg : F is a prefixform, being <operator>.<list of arguments>. X is  ;
%       the index of the CODMAT row where the description of F has to  ;
%       start.                                                         ;
% -------------------------------------------------------------------- ;
begin scalar var,varf,valf,n,fargl,s,lst,b;
 lst:='(plus minus times expt);
 if (b:=(not (car f memq lst)) 
          or
        (car(f) eq 'expt 
          and 
        ((idp(cadr(f)) and not numberp( caddr f))
           or 
         (cadr(f) eq 'e)
           or
         (numberp(cadr(f))))))
  then nop!f:=nop!f+1;
 if varf:=assoc(f,s:=get(car f,'kvarlst))
  then
  << valf:=car(varf); varf:=cdr(varf);  
     if idp varf and numberp(get(varf,'freq))
      then increaseac(varf)
      else  
       << while valf and not (pairp(car valf) and caar valf memq lst)
           do valf:=cdr valf;
          if not atom valf
             and (var:=assoc(car valf,get(caar valf,'kvarlst)))
           then increaseac(cdr var)
       >>
  >>
  else
  << varf:=fnewsym();
     put(car f,'kvarlst,(f.varf).s);
     if not b
      then
       << put(varf,'rowindex,n:=rowmax:=rowmax+1);
          increaseac(varf);
          prevlst:=(x.n).prevlst;
          ffvar!!2(n,varf,f)
       >>
      else
       << foreach arg in cdr(f) do
           if not atom(arg)
            then fargl:=fvarop(arg,x).fargl
            else fargl:=arg.fargl;
          f:=car(f).reverse(fargl);
          kvarlst:=(varf.f).kvarlst;
       >>
  >>;
 prevlst:=(x.varf).prevlst;
 return varf
end;

symbolic procedure increaseac(var);
% -------------------------------------------------------------------- ;
% The function CountNop, given in the module CODCTL, is used for       ;
% counting the number of arithmetic operations. Since identical        ;
% function patterns are only stored once in Codmat, their number of    ;
% occurrences, denoted by freq(uency) is stored during parsing. The    ;
% indicator freq is used in CountNop to obtain the arithmetic complexi-;
% ty of the input.                                                     ;
% -------------------------------------------------------------------- ;
put(var,'freq,if numberp(get(var,'freq)) then 1+get(var,'freq) else 1);

symbolic procedure ssetvars;
% -------------------------------------------------------------------- ;
% eff : The information stored on the property lists of the elements of;
%       the lists Varlst!+ and Varlst!* is stored in the matrix CODMAT,;
%       i.e.the Z-streets are produced via the SSetvars1 calls.        ;
%       Before doing so PrepMultMat is used to modify, if necessary,the;
%       Varlst!* information by incorporating information about ratio- ;
%       nal exponents.                                                 ;
%       Furthermore the elements of Prevlst are used to store the hier-;
%       archy information in the ORDR-fields in the matrix CODMAT. In  ;
%       addition some bookkeeping activities are performed: Needless   ;
%       information is removed from property lists and not longer need-;
%       ed lists are cleared. EndMat is also initialized.              ;
% -------------------------------------------------------------------- ;
<<prepmultmat();
  ssetvars1('varlst!+,'plus);
  ssetvars1('varlst!*,'times);
  varlst!+:=varlst!*:=nil;
  foreach el in reverse(prevlst) do setprev(car el,cdr el);
  foreach el in kvarlst do remprop(cadr el,'kvarlst);
  foreach el in '(plus minus difference times sqrt expt) do
                                                   remprop(el,'kvarlst);
  endmat:=rowmax
>>;
 
symbolic procedure ssetvars1(varlst,opv);
% -------------------------------------------------------------------- ;
% eff : Zstrt's are completed via a double loop and association of     ;
%       column indices(if necessary for both the + and  the * part of  ;
%       CODMAT) with the var's via storage on the var property lists.  ;
% -------------------------------------------------------------------- ;
begin scalar z,zz,zzel;
  foreach var in lispeval(varlst) do
  <<zz:=nil;
    rowmin:=rowmin-1;
    foreach el in get(var,varlst) do
    <<z:=mkzel(rowmin,cdr el);
      if null(zzel:=zstrt car el) or not xind(car zzel)=rowmin
       % To deal with X*X OR X+X;
      then setzstrt(car el,z.zzel);
      zz:=inszzz(mkzel(car el,val z),zz)
    >>;
    put(var,varlst,rowmin); % Save column index for later use;
    setrow(rowmin,opv,var,nil,zz)
  >>;
end;

symbolic procedure prepmultmat;
% -------------------------------------------------------------------- ;
% eff : The information concerning rational exponents and stored in the;
%       Varlst!* lists is used to produce exact integer exponents,to be;
%       stored in the Z-streets of the matrix Codmat:                  ;
%       For all elements in Varlst!* the Least Common Multiplier (LCM) ;
%       of their exponent-denominators is computed.                    ;
%       If LCM > 1 the element has a rational exponent. The exponent of;
%       each element is re-calculated  to obtain LCM * the orig. exp.  ;
%       Renaming is adequately introduced when necessary.              ;
%       Furhtermore the corresponding column names receive a flag      ;
%       DecreaseAC, to be used in the function CountNop to compute a   ;
%       correct number of arithmetic operations, defined by the origi- ;
%       nal input.                                                     ;
% -------------------------------------------------------------------- ;
begin scalar tlcm,var,varexp,hvarlst;
 preprefixlist := hvarlst:= nil;
 while not null (varlst!*) do
 <<var := car varlst!*; varlst!* := cdr varlst!*;
   if flagp(var,'ratexp)
    then
     <<tlcm:=1;
       remflag(list var,'ratexp);
       foreach elem in get(var,'varlst!*) do
        if pairp cdr elem then tlcm := lcm(tlcm,cddr elem);
       if numberp(get(var,'rowindex))   % Var denotes a (sub)expression;
           or
          pairp(assoc(var,kvarlst))     % Var denotes a kernel         ;
           or
          get(var,'varlst!+)            % Var also plays an add. role  ;
        then
         << varexp:=fnewsym();
            prevlst:=subst(varexp,var,prevlst);
            kvarlst:=
             (varexp.(if tlcm = 2
                       then list('sqrt,var)
                       else list('expt,var,list('quotient,'1,tlcm))))
                                                              . kvarlst;
            put(varexp,'varlst!*,get(var,'varlst!*));
            remprop(var,'varlst!*)
         >>
        else
         << preprefixlist :=
             (var.(if tlcm = 2
                    then list('sqrt,var)
                    else list('expt,var,list('quotient,'1,tlcm))))
                                                        . preprefixlist;
            varexp:=var
         >>;
       foreach elem in get(varexp,'varlst!*) do
       % ------------------------------------------------------------- ;
       % If Cdr Elem is a pair, i.e. if the exponent is rational, the  ;
       % computation of the arithmetic complexity of the input needs   ;
       % some preprocessing: A rational exponent, implying a function- ;
       % application is replaced by an integer exponentiation. We store;
       % the rowindx in the list denoted by DecreaseAC. When applying  ;
       % CountNop, given in the file CODCTL.RED, this list is used to  ;
       % correct the function and exponentiation counts.               ;
       % If cdr Elem is an integer similar actions are required in case;
       % the original exponent is 1.                                   ;
       % ------------------------------------------------------------- ;
        if pairp cdr elem
         then
          << rplacd(elem,(tlcm * cadr elem)/(cddr elem));
             put(varexp,'decreaseac,
                       append(list(car elem),get(varexp,'decreaseac)))
          >>
         else
          << rplacd(elem,tlcm * cdr elem);
             if cdr(elem)=tlcm 
              then put(varexp,'decreaseac,
                        append(list(car elem),get(varexp,'decreaseac)))
          >>;
       var:=varexp;
     >>;
    hvarlst:=var.hvarlst
  >>;
 varlst!* := hvarlst;
end;

% -------------------------------------------------------------------- ;
% ORDERING OF (SUB)EXPRESSIONS :                                       ;
% -------------------------------------------------------------------- ;
% It is based op the presumption that the ordering of the input expres-;
% sions has to remain unchanged when attempting to optimize their des- ;
% cription. This ordering is stored in the list CodBexl!* via FFVAR    ;
% and used in the procedure MAKEPREFIXL( via PRIRESULT and also given  ;
% in CODCTL.RED) for managing output. Hence any subexpression found by ;
% whatever means has to be inserted in the latest version of the       ;
% description of the set ahead of the first expression in which it     ;
% occurs and assuming its occurences are replaced by a system selected ;
% name which is also used as subexpression recognizer(i.e., as assigned;
% var). We distinguish between different types of subexpressions:      ;
% Some are directly recognizable : sin(x),a(1,1) and the like. Others  ;
% need optimizer searches to be found: sin(a+2*b),f(a,c,d+g(a)),etc.   ;
% Via FVAROP an expression like sin(x) is replaced by a system selected;
% name(g001,for instance),the pair (g001.sin(x)) is added to the       ;
% Kvarlst, the pair (sin(x).g001) is added to the 'Kvarlst of sin,thus ;
% allowing a test to be able to uniquely use the name g001 for sin(x). ;
% Finally the pair (rowindex of father of this occurence of sin(x) .   ;
% g001) is added to Prevlst. However if the argument of a sin applica- ;
% tion is not directly recognizable(a*b+a*c or a*(b+c),etc) the argu-  ;
% ment is replaced by a system selected name(g002,for instance),which  ;
% then needs incorporation in the administration. This is also done in ;
% FVAROP: The index of the CODMAT-row used to start the description of ;
% this argument is stored on the property list of g002 as value of the ;
% indicator Rowindex and the Prevlist is now extended with the pair    ;
% (father indx. g002 indx).When storing nested expressions in CODMAT   ;
% the father-child relations based on interchanges of + and * symbols  ;
% are treated in a similar way.So the Prevlst consists of two types of ;
% pairs: (row number.row number) and (row number.subexpression name).  ;
% The CODMAT-row, where the description of this subexpression starts   ;
% can be found on the property list of the subexpression name as value ;
% of the indicator Rowindex. All function applications are stored uni- ;
% quely in Kvarlst. This list is consulted in CODPRI.RED when construc-;
% ting PREFIXLIST,which represents the result as a list of dotted pairs;
% of the form ((sub)expr.name . (sub)expr.value) as to guarantee a cor-;
% rect insertion of the function appl.,i.e. directly ahead of the first;
% (sub)expr. it is part of.After inserting the pair (subexpression name;
% . function application) the corresponding description is removed from;
% the Kvarlst,thus avoiding a multiple insertion. This demands for a   ;
% tool to know when to consult the Kvarlst.This is provided by the ORDR;
% field of the CODMAT-rows.It contains a list of row indices and func- ;
% tion application recognizers, which is recursively built up when     ;
% searching for subexpressions,after its initialization in SSETVARS,   ;
% using the subexpression recognizers introduced during parsing.       ;
% -------------------------------------------------------------------- ;

symbolic procedure setprev(x,y);
% -------------------------------------------------------------------- ;
% arg : Both X and Y are rowindices.                                   ;
% eff : Y is the index of a row where the description of a subexpr.    ;
%       starts. If X is the index of the row where the description of a;
%       toplevel expression starts( an input expression recognizable by;
%       the father-field Farvar) Y is put on top of the list of indices;
%       of subexpressions which have to be printed ahead of this top-  ;
%       level expression.Otherwise we continue searching for this top- ;
%       level father via a recursive call of SetPrev.                  ;
% -------------------------------------------------------------------- ;
if numberp(farvar x)
then setprev(farvar x,y)
else setordr(x,y.ordr(x));
 
endmodule;


module codopt;   % Generalization of Breuer's Growth Factor Algorithm.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Authors :   J.A. van Hulzen, B.J.A. Hulshof.                        ;
% ------------------------------------------------------------------- ;

%-------------------------------------------------------------------- ;
% The module CODOPT contains:                                         ;
%                                                                     ;
% THE GENERALIZED VERSION OF BREUER'S GROWTH FACTOR ALGORITHM         ;
%                                                                     ;
% A description can be found in :                                     ;
% M.A. Breuer : "Generation of Optimal Code for Expressions via       ;
%      Factorization", Comm.ACM 12, 333-340 (1969).                   ;
% J.A. van Hulzen : "Breuer's Grow Factor Algorithm in Computer       ;
%      Algebra",Proceedings SYMSAC '81 (P.S. Wang, ed.), 100-104, New ;
%      York: ACM(1981).                                               ;
% J.A. van Hulzen : "Code Optimization of Multivariate Polynomial     ;
%      Schemes : A Pragmatic Approach", Proceedings EUROCAL '83 (J.A. ;
%      van Hulzen, ed.),Springer LNCS-series nr 162, 286-300 (1983).  ;
% ------------------------------------------------------------------- ;
%                                                                     ;
% ------ DATA STRUCTURES AND WEIGHTS ------                           ;
% Via FFVAR!! and in combination with SSETVARS(also the CODMAT module);
% a set of input-expressions is decomposed and stored in the "matrix" ;
% CODMAT.                                                             ;
% The Breuer-like searches, for finding common subexpressions (cse's  ;
% for short), concentrate on Zstrt's, defining the primitive parts    ;
% (pp's for short) of input-expressions. These pp's are either linear ;
% expressions (Opval='PLUS) or monomials (Opval='TIMES). The pp's be- ;
% long to larger expressions if CHROW is not NIL at the same level or ;
% if the FarVar-field of the row contains a rowindex (of a father ex- ;
% pression).                                                          ;
% The Zstrt is a list of pairs Z.Such a Z consists of a (column)index,;
% denoted by XIND(Z) or YIND(Z) and an integer value IVAL(Z), being   ;
% the exponent (or coefficient) of the variable corresponding with the;
% column-index, occurring in this pair. In a similar way columns are  ;
% used to define the occurrences of variables in the description of   ;
% the input-expressions( see the CODMAT module).                      ;
% Each row or column has a weight WGHT=((AWght.MWght).HWght), where   ;
% HWght=AWght + 3*MWght. The A(dditive)W(ei)ght is the length of the  ;
% Zstrt. The M(ultiplicative)W(ei)ght is its number of (|IVAL|>1)-ele-;
% ments. The factor 3 reflects the assumption that multiplication is 3;
% times as expensive as addition. The HWghts play an essential role in;
% the heuristics (on which the Breuer searches are based) and are com-;
% puted and stored via application of the procedure INITWGHT (see the ;
% CODMAT module).                                                     ;
% NOTE : It is of course possible to make the factor 3 a parameter.   ;
% This requires some resettings in the weight-routines (see the module;
% CODMAT).                                                            ;
% HWghts can be associated with both rows and columns.                ;
% This allows to produce weightfactors (see the references),  to be   ;
% associated with rows (or columns) to refine heuristic decisions, if ;
% required. The weightfactor of a row(column) is the sum of the HWghts;
% of those columns(rows) which share a non-zero entry with it.Although;
% the use  of weightfactors might improve decision making, its over-  ;
% head in computational cost can be considerable, certainly when the  ;
% CODMAT-matrix is large. The visual intuitive selection-mechanisms   ;
% for cse-building (extend a set of column-indices against the price  ;
% of reducing the number of parents (rows)) can be impractical, becau-;
% se - certainly initially - the number of variables is a fraction of ;
% the number of rows, corresponding with (sub)pp's.                   ;
% So we drop the weightfactors and we select rows instead of columns. ;
% To speed up the row-selection all rows with an equal HWght are col- ;
% lected in a double linked list, using the HiR-fields. These sets are;
% accessible via the elements of the CODHISTO-vector (details are gi- ;
% ven in the CODMAT module, procedure INSHISTO). We recall only that  ;
% CODHISTO(i) = k means that HWght(k) = i and that HiR(k) allows to   ;
% access the FILO-list of rows j with HWght(j) = i.                   ;
% NOTE : These FILO-lists, a kind of buckets, can contain both PLUS-  ;
% and TIMES-rows if both are SETFREE (see the COSYMP module and again ;
% INSHISTO). The operator-type is irrelevant during the Breuer-search.;
% In fact, it is only explicitly required in the procedure ADDCSE.    ;
%                                                                     ;
% ------ THE SEARCHES : THE ESSENTIALS ------                         ;
% Initially the cse's are either linear expressions or monomials. To  ;
% discover them the integer-matrices (CODMAT-parts with PLUS and TIMES;
% Opval-fields,respectively), are heuristically searched for submatri-;
% ces of rank 1 of maximal size. The size is determined, using a      ;
% profit-criterium. A basic scan is used, which can be qualified as   ;
% "test whether the determinant of a (2,2)-matrix of non-zero entries ;
% is zero". Its use is based on information about the row-weights,    ;
% which allow to locate completely dense submatrices. The row-weight  ;
% is a reflection of the arithmetic complexity of the pp,corresponding;
% with the row. Since we want to reduce the arithmetic complecity AC =;
% (n+,n*) of the set of input-expressions, a cse-selection ought to   ;
% contribute to a reduction of the number of additions (n+) and/or the;
% number of multiplications (n*). This is only possible if the cse oc-;
% curs at least twice and if the additive weight AWght is at least 2. ;
% The profit-criterium WSI is based on this assumption. Its actual va-;
% lue is (|Psi|-1) * (|Jsi|-1). Here Psi is the set of Parent- row in-;
% dices and Jsi is the set of indices of columns, which are associated;
% with variables occurring in the cse under construction.             ;
% Once a cse is found its description is removed from the rows,defined;
% by Psi, and from the columns, with indices in Jsi. The cse itself is;
% added to CODMAT as a new row. It has a system-selected name (given  ;
% in the FarVar-field and produced with FNEWSYM (see CODCTL module)), ;
% which is also used as recognizer of the new column added to CODMAT, ;
% to define the occurrences of the new cse (via the Psi-set). In addi-;
% tion the HWghts of the Psi rows, used in the previous resettings are;
% recomputed and reinserted via CODHISTO and the cse-row is entered in;
% CODHISTO, to allow it to play its own role in the optimization. We  ;
% also insert the new cse in the output hierarchy via the ORDR-field  ;
% of the Psi-parents, associated with the cse. We finally remark that ;
% it also might be possible that the cse is identical to one or more  ;
% of its parent-pp's. In this case it might be necessary to migrate   ;
% information from the PLUS(TIMES)-matrix to the TIMES(PLUS)-matrix.  ;
% Further details are given in the source, contained in this module.  ;
%                                                                     ;
% Essentially all searches are done in Zstrt's. A Zstrt is a list of  ;
% pairs (index . value). The ordering in the Zstrt is based on the    ;
% indices. A column-Zstrt contains (positive) row-indices, given in   ;
% descending order. A row-Zstrt contains (negative) column-indices,   ;
% given in ascending order. The indices define relative positions. In ;
% all operations on CODMAT information-pieces (except for MKZEL-calls);
% these relative positions, produced via Rowmax and Rowmin value chan-;
% ges, are needed for information retrieval and information storage.  ;
% These relative CODMAT-positions are used during the searches, i.e.  ;
% the sets (lists) Psi and Jsi are built with them.During the searches;
% ordering is only relevant if the procedure PnthXZZ is used. The ap- ;
% plication PnthXZZ(A,B) delivers the Zstrt B, but after removal of   ;
% the elements preceding the Z-element with the A-index. This Z-elem. ;
% can thus be obtained as CAR(PnthXZZ(A,B)). Since the searches are   ;
% based on row-selection followed by Jsi-resettings, only ordering in ;
% Jsi is relevant. When a cse is found, Psi is ordered, before making ;
% and adding to CODMAT the corresponding Zstrt.                       ;
%                                                                     ;
% ------ DOMAIN CONSIDERATIONS ------                                 ;
% As stipulated above operator considerations are hardly relevant du- ;
% ring cse-searches. Identical tests can be applied for cse's occur-  ;
% ring in linear expressions as well as in monomials, albeit that via ;
% the Expand- and ShrinkProd mechanism additional searches are perfor-;
% med for monomial-cse's, simply because the mathematical context is  ;
% somewhat richer. When allowing various coefficient domains, a dis-  ;
% tinction between coefficient- and exponent searches is needed :     ;
% Assuming MkZel, SetIVal and IVal become generic functions, the fol- ;
% lowing changes in CODOPT are required :                             ;
% - ExtBrsea - A double CODHISTO-mechanism ( to allow to analyse PLUS ;
%              and TIMES rows separately) is required and doubles in  ;
%              fact initialization, as well as appl. of ExtBrsea1.    ;
% - TestPr   - The zero-minor test has to be made generic.            ;
% - RZstrtCse- The GC-computations uses ABS-value computations, which ;
%               ought to be generic, as well as the gcd comp.'s with  ;
% - Gcd2     - This routine must be generic.                          ;
% - CZstrtCse- The ZZcse-construction requires multiplication factor  ;
%              computations, i.e. divisions of domain-elements, which ;
%              ought to be generic.                                   ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% The global identifiers needed in this module are :                  ;
% ------------------------------------------------------------------- ;
 
global '(psi jsi npsi njsi wsi rcoccup roccup1 roccup2 newjsi newnjsi
         codhisto headhisto rowmin rowmax )$
 
% ------------------------------------------------------------------- ;
% Description of the global variables used in this module (see also   ;
% the CODMAT module):                                                 ;
% ------------------------------------------------------------------- ;
%   Roccup1 : Indices of rows, which become (temporarily) irrelevant  ;
%             during a cse search (see procedure FindOptRow).         ;
%   Roccup2 : Indices of rows, which were (temporarily) selected as   ;
%             candidate-parent row (see procedure FindOptRow).        ; 
%   RCoccup : Indices of rows and columns, either used for building   ;
%             the cse or leading to a failure, i.e. to Wsi=0.         ;
%       Psi : Indices of the parents of the cse.                      ;
%      NPsi : Number of elments in Psi.                               ;
%       Jsi : A list of column indices representing the current cse.  ;
%      NJsi : Number of elements in Jsi.                              ;
%    NewJsi : Contains the new Jsi if a certain rowindex is added to  ;
%             Psi (see FINDOPTROW).                                   ;
%   NewNJsi : Number of elements in NewJsi.                           ;
%       Wsi : Profitfunction = (|Psi|-1)*(|Jsi|-1). See proc. TestRed.;
%  CodHisto : Vector representing the Histogram.                      ;
% Headhisto : CodHisto(i) = 0 if i > Headhisto, i.e. the list of rows ;
%             with HWght = HeadHisto is accessible via CodHisto(Head- ;
%             Histo).                                                 ;
%-------------------------------------------------------------------- ;
 

rcoccup:=roccup1:=roccup2:=nil;
 
 
symbolic procedure extbrsea;
% ------------------------------------------------------------------- ;
% The main procedure governing the Breuer-searches. Both,monomials and;
% linear expressions, can be found as cse.                            ;
% ------------------------------------------------------------------- ;
begin scalar further;
   % ---------------------------------------------------------------- ;
   % We start excluding those rows and columns, which are irrelevant  ;
   % for our searches : Either the FarVar-field = -1 (This setting is ;
   % performed by application of the procedure ClearRow, defined in   ;
   % the module CODMAT, and expresses that a row or column is not in  ;
   % use anymore) or = -2 (Columns reservedto store temporarily mono- ;
   % mial information created in ExpandProd and removed in ShrinkProd);
   % ---------------------------------------------------------------- ;
   for x:=rowmin:rowmax do
    if farvar(x)=-1 or farvar(x)=-2
    then setoccup(x)
    else setfree(x);
   % ---------------------------------------------------------------- ;
   % After initialization the searches are performed.                 ;
   % ---------------------------------------------------------------- ;
   initbrsea();
   extbrsea1();
   % ---------------------------------------------------------------- ;
   % The remaining monomials can further be analysed for cse-occurren-;
   % ces when they are temporarily expanded, using a specific addition;
   % chain mechanism (see procedure EXPANDPROD).                      ;
   % ---------------------------------------------------------------- ;
   repeat
    <<expandprod();
      for x:=rowmin:rowmax do
       if not farvar(x)=-1 and opval(x) eq 'times 
        then setfree(x) 
        else setoccup(x);
      initbrsea();
      extbrsea1();
      % ------------------------------------------------------------- ;
      % Once the continued searches, based on expanded monomial infor-;
      % mation, are completed, the original monomial-variable informa-;
      % tion structure is restored by shrinking the sets of columns,  ;
      % associated with the various monomial-variables, together into ;
      % the originally used columns (details are given in the procedu-;
      % re SHRINKPROD).                                               ;
      % ------------------------------------------------------------- ;
      further:=shrinkprod()
    >>
   until not(further);
   % ---------------------------------------------------------------- ;
   % Once the Breuer-searches are completed control is passed over to ;
   % IMPROVELAYOUT, before TCHScheme and finally CODFAC are used.     ;
   % TCHScheme allows information migration and CODFAC application of ;
   % the distributive law. Application of IMPROVELAYOUT might lead to ;
   % the conclusion that the Expand-Shrink activities resulted in re- ;
   % dundant cse-names, such as a double name for x^2 or the like.    ;
   % Details are given in OPTIMIZELOOP (see the module CODCTL).       ;
   % ---------------------------------------------------------------- ;
end;
 
symbolic procedure initbrsea;
% ------------------------------------------------------------------- ;
% The CODMAT-submatrices are prepared for the Breuer-searches.        ;
% The weights are set, the vector CODHISTO gets its initial values    ;
% and redundant information is temporarily removed. It is of course   ;
% needed again for output and eventually during later stages of the   ;
% optimization process, due to information migration. Information is  ;
% redundant when a row or column, i.e a Zstrt, only contains one Z-   ;
% element. This demands for a recursive search through CODMAT, since  ;
% a redundant row can lead to a redundant column if the element they  ;
% share ought to be disregarded.                                      ;
% ------------------------------------------------------------------- ;
begin scalar hlen;
  hlen:=histolen;
  for x:=rowmin:rowmax do
  if free(x) then initwght(x);
  % ----------------------------------------------------------------- ;
  % Only the weights for relevant rows and columns are computed. Once ;
  % the weights are known, the redundancy can be removed using :      ;
  % ----------------------------------------------------------------- ;
  redcodmat();
  % ----------------------------------------------------------------- ;
  % If the vector CODHISTO is already known, it might have been crea- ;
  % ted during a previous use of the Optimizer. In this case its en-  ;
  % tries are set to NIL. Otherwise it is created, before the HWght-  ;
  % information is stored in the HiR-fields and in CODHISTO.          ;
  % ----------------------------------------------------------------- ;
  if codhisto
   then for x:=0:histolen do sethisto(x,nil)
   else codhisto:=mkvect(hlen);
  headhisto:=0;
  for x:=0:rowmax do
   inshisto(x);
end;
 
symbolic procedure redcodmat;
% ------------------------------------------------------------------- ;
% Recursive removal of redundant information using the procedure      ;
% TestRed.                                                            ;
% ------------------------------------------------------------------- ;
for x:=rowmin:rowmax do testred(x);
 
symbolic procedure testred(x);
% ------------------------------------------------------------------- ;
% If the row or column X is still relevant but has an additive weight ;
% of 1 or 0 its information is irrelevant for the searches.           ;
% Remark : It is possible to consider the LOWER BOUND of 2 as a PARA- ;
% METER. If we are only interested in cse's of a LENGTH of AT LEAST M ;
% we have to replace the 2 by M and to MAKE this M GLOBAL. It demands ;
% a revision of the procedure DOWNWGHT1 and similar routines, given in;
% the CODMAT module, and a modification of the profit criterium WSI   ;
% (see the procedure EXTBRSEA1).                                      ;
% So when a row is redundant we declare it to be occupied and reduce  ;
% the weights of the column its shares its element with, before we    ;
% test if this column is now redundant as well. The role of rows and  ;
% columns are thus interchangeable.                                   ;
% ------------------------------------------------------------------- ;
if free(x) and awght(x)<2
then
 <<setoccup(x);
   foreach z in zstrt(x) do
    <<downwght1(yind z,ival z);
      testred(yind z)>>
 >>;
 
symbolic procedure extbrsea1;
% ------------------------------------------------------------------- ;
% This procedure defines the kernel of the generalized Breuer-search. ;
% It is based on the basic scan for zero-determinants. An explanation ;
% is given, using a (6,4)-matrix B of integers, which can also be     ;
% found in Van Hulzen '83, p.295 :                                    ;
%                                                                     ;
% column -4 -3 -2 -1                                                  ;
%                                                                     ; 
% row 6 | 0  0  1  1 | AWght = 2 MWght = 0 HWght = 2 CodHisto( 2) = 6 ;
%     5 | 0  1  2  2 |         3         2         9         ( 9)   5 ;
%     4 | 0  2  2  3 |         3         3        12         (12)   4 ;
%     3 | 2  3  4  5 |         4         4        16         (16)   3 ;
%     2 | 4  6  0  0 |         2         2         8         ( 8)   2 ;
%     1 | 1  6  8 10 |         4         3        13         (13)   1 ;
%                                                                     ;
% AWght = 3  5  5  5                                                  ;
%                                                                     ;
% Hence Zstrt(-4) = ((3.2) (2.4) (1.1))                               ;
%   and Zstrt( 6) = ((-2.1)(-1.1)).                                   ;
% ------------------------------------------------------------------- ;
begin scalar hr,hc,x;
  while hr:=findhr() do
  % ----------------------------------------------------------------- ;
  % ExtBrsea1 consists of a WHILE-loop,which is executed as long as   ;
  % a first parent-row can be found using CODHISTO, via FindHR. So    ;
  % initially Psi = (HR).                                             ;
  % ----------------------------------------------------------------- ;
   if hc:=findhc(hr)
   % ---------------------------------------------------------------- ;
   % As long as a row HC can be found, which can be used in combinati-;
   % on with HR, the cse-search continues. Since redundancy is removed;
   % the AWght of HC is at least 2. Via FINDHC the column with maximal;
   % AWght, which shares a non-zero element with Row(HR) is selected. ;
   % ---------------------------------------------------------------- ;
    then
     <<wsi:=0;
       while x:=findoptrow(hr,hc,(wsi/npsi)+1) do
        brupdate(x);
       % ------------------------------------------------------------ ;
       % The Breuer-search continues as long as profit is gained. The ;
       % minimal rowlength for continuation is Floor(Wsi/NPsi) + 2.   ;
       % The number of rows is iteratively extended :                 ;
       % NPs(i+1) = NPs(i) + 1 or NPsi = NPs(i+1) - 1.                ;
       % Since Ws(i+1) > Ws(i) or NPsi * (NJs(i+1) - 1) > Ws(i), the  ;
       % number of columns, which are required for a further cse-exten;
       % sion is at least NJs(i+1),i.e. is larger than Floor(Wsi/NPsi);
       % + 1.                                                         ;
       % ------------------------------------------------------------ ;
       foreach x in roccup1 do
        setfree(x);
       % ------------------------------------------------------------ ;
       % Not usable during construction of the present cse. Given free;
       % again for a next attempt, with of course another HR.         ;
       % ------------------------------------------------------------ ;
       foreach x in roccup2 do
        setfree(x);
       % ------------------------------------------------------------ ;
       % Used for cse-construction, but now possibly reusable.        ;
       % ------------------------------------------------------------ ;
       roccup1:=roccup2:=nil;
       if wsi>0
        then
         <<foreach x in rcoccup do
            setfree(x);
           rcoccup:=nil;
           % -------------------------------------------------------- ;
           % Rows and Columns used for building the cse can eventually;
           % be usable again. Hence also given free again.            ;
           % Finally all necessary resettings in CODMAT and CODHISTO  ;
           % are performed with AddCse, before the search for further ;
           % cse's is continued.                                      ;
           % -------------------------------------------------------- ;
           addcse()>>
         else
          if npsi=1
           then
            << % ---------------------------------------------------- ;
               % If Wsi = 0 and NPsi = 1 the (HR,HC)-selection was un-;
               % lucky.No cse is found, i.e. HC has to be disregarded.;
               % ---------------------------------------------------- ;
               setoccup(hc);
               rcoccup:=hc.rcoccup
            >>
      >>
     else
      << % ---------------------------------------------------------- ;
         % No columns available for cse-construction using the row HR.;
         % Hence HR is an unlucky choise. The elements of RCoccup are ;
         % freed to be reused. HR is disregarded via RowDel(HR), with ;
         % as a consequence a possible, intermediate introduction of  ;
         % redundancy, which can be removed by applying TestredZZ.    ;
         % ---------------------------------------------------------- ;
         foreach x in rcoccup do
          setfree(x);
         rcoccup:=nil;
         rowdel(hr);
         testredzz(hr)
      >>
end;
 
symbolic procedure findhr;
% ------------------------------------------------------------------- ;
% CODHISTO is subjected to a top-down search to find the non-zero en- ;
% try with maximal index, i.e. to find the index of the most interes- ;
% ting row. This is row 3 in the example in the comment in ExtBrsea1. ;
% This value is returned. In addition Psi, NPsi and RCoccur are initia;
% lized (Psi = (3), NPsi = 1 and RCoccur = (3),for example). Finally  ;
% row X (= 3), selected as most attractive row, is removed from the   ;
% candidate rows, by assigning NIL to the FREE-field.                 ;
% Note that X = Nil is possible, implying that the search, defined in ;
% ExtBrsea1,is finished during this stage of the optimization process.;
% ------------------------------------------------------------------- ;
begin scalar x;
  while headhisto>0 and null(x:=histo headhisto) do
  headhisto:=headhisto-1;
  if x
  then 
  <<psi:=list x;
    npsi:=1;
    setoccup(x);
    rcoccup:=x.rcoccup>>;
  return x
end;
 
symbolic procedure findhc(hr);
% ------------------------------------------------------------------- ;
% HR is the index of a row, for instance selected with FindHR.        ;
% The Zstrt of HR is used to select the column, which can best be used;
% in combination with the row HR to start constructing a cse, i.e. the;
% "leftmost" column with locally maximal AWght. When looking at the   ;
% example in ExtBrsea1 this will be column -3.                        ;
% In addition Jsi and NJsi are initialized. Only the columns, which   ;
% are FREE are used( Jsi = (-1 -2 -3 -4), NJsi = 4).The return value  ;
% is Y = -3.                                                          ;
% NOTE :ExtBrsea1 is applied as long as it is possible.This might lead;
% to the need of disregarding columns during some stage in the itera- ;
% tive process. Therefore the test FREE(Y1:=Yind Z) is required.      ;
% ------------------------------------------------------------------- ;
begin scalar y,y1,aw,awmax;
  awmax:=njsi:=0;
  jsi:=nil;
  foreach z in zstrt(hr) do
  if free(y1:=yind z)
  then
  <<jsi:=y1.jsi;
    njsi:=njsi+1;
    if (aw:=awght y1)>awmax
    then
    <<awmax:=aw;
      y:=y1>>
  >>;
  jsi:=reverse(jsi);
  return y
end;
 
symbolic procedure findoptrow(hr,hc,lmax);
% ------------------------------------------------------------------- ;
% The row-index HR and the column-index HC are used to  find a Row(X),;
% applying the test defined in the procedure TestPr, such that Row(HR);
% and Row(X) have a cse of at least a length Lmax + 1.                ;
% If HR =3 and HC = -3  FindOptRow will produce X = 1.                ;
% In TestPr a zero-minor-test is performed, always using B(HR,HC), and;
% here for shortness called Bil. Bil is used in all the TestPr-tests. ;
% These tests are done for all rows, which share a non-zero element   ;
% with the column HC, and which are not yet disregarded for further   ;
% searches.The new version of Jsi is assigned to the local variable S,;
% i.e. the return-value of TestPr. If S is a list of one element, HC, ;
% its Cdr is Nil, i.e Row(X1) does not contribute to a possible cse,  ;
% contained in a pp, defined by Row(HR). Then X1 is added to the list ;
% Roccup1. If the profit is satisfactory, i.e. if the list S is longer;
% than Lmax a new set of column-indices, called NewJsi, is created and;
% the index X1 is also renamed and returned. Hence when no X1 is found;
% X is not initialized, implying that Nil is returned.                ;
% Regardless of X1's role, it is added to the list Roccup2 if S con-  ;
% tains at least 2 elements. Before returning to the calling procedure;
% ExtBrsea1, the FREE-field of Row(X1) is set to Nil, implying that it;
% is disregarded until further notice.                                ;
% TestPr produces S = (-1 -2 -3).                                     ;
% ------------------------------------------------------------------- ;
begin scalar l,s,x,x1,bil;
  bil:=ival(car pnthxzz(hc,zstrt hr));
  foreach z in zstrt(hc) do
   if free(x1:=xind z)
    then
     <<if null(cdr(s:=testpr(x1,hr,ival z,bil)))
        then roccup1:=x1.roccup1
        else
         <<if (l:=length s)>lmax
            then
             <<newnjsi:=lmax:=l;
               x:=x1;
               newjsi:=s
             >>;
           roccup2:=x1.roccup2
         >>;
        setoccup(x1)
     >>;
  return x
end;
 
symbolic procedure testpr(x,hr,bkl,bil);
% ------------------------------------------------------------------- ;
% TestPr is a procedure to perform zero-minor tests.                  ;
% X and HR are row-indices. Bkl = B(X,HC) and Bil = B(HR,HC).         ;
% The test is : Is Bil*Bkj - Bij*Bkl = 0?                             ;
% Assumptions : Bkj = B(X,j) and Bij = B(HR,j), where j is running    ;
% through Jsi, the set of indices of columns, which share a non-zero  ;
% element with Row(HR).HC is an element of Jsi.                       ;
% The new JSI-set is returned. It contains at least HC.               ;
% ------------------------------------------------------------------- ;
begin scalar zz,zzhr,x1,p,ljsi,cljsi;
  ljsi:=jsi;
  zz:=zstrt(x);
  zzhr:=zstrt(hr);
  while ljsi and zz do
  if (cljsi:=car ljsi)=(x1:=xind car zz)
  then
  << % -------------------------------------------------------------- ;
     % The list LJsi is initially equal to the already existing Jsi,a ;
     % list consisting of column-indices. The lists ZZ and ZZHR are,  ;
     % initially the Zstrt's of Row(X) and Row(HR), respectively. The ;
     % Zstrt's consist of pairs (column-index . coefficient/exponent).;
     % The WHILE-loop is performed as long as the lists LJsi and ZZ   ;
     % are not yet empty. The test defining alternative actions is ba-;
     % sed on a comparison of the car-elements of the remaining parts ;
     % of these lists, which are given in ascending index-order.      ;
     % -------------------------------------------------------------- ;
     zzhr:=pnthxzz(cljsi,zzhr);
     % -------------------------------------------------------------- ;
     % The Zstrt ZZHR is also in ascending order. If the Car of LJsi, ;
     % CLJsi, is equal to X1, the column-index of the Car of Zstrt(X),;
     % the elements of Zstrt(HR), preceding the element, containing   ;
     % CLJSI as column-index,are removed from ZZHR.                   ;
     % This can imply that ZZHR =(),i.e. that Car(ZZHR) = Nil and that;
     % IVal(Car(ZZHR)) = 0.                                           ;
     % -------------------------------------------------------------- ;
     if ival(car zz)*bil=ival(car zzhr)*bkl
      then p:=cljsi.p;
     % -------------------------------------------------------------- ;
     % CLJsi can be added to the new Jsi-list, which is under construc;
     % tion, using P, if the test succeeds.Here Ival(Car ZZ) = Bkj and;
     % IVal(Car ZZHR) = Bij.                                          ;
     % -------------------------------------------------------------- ;
     ljsi:=cdr(ljsi);
     zz:=cdr(zz)
  >>
  else
    if cljsi>x1
    % --------------------------------------------------------------- ;
    % The lists are in ascending order. Hence if the Car's do not     ;
    % match one of the two has to be skipped.                         ;
    % --------------------------------------------------------------- ;
     then zz:=cdr(zz)
     else ljsi:=cdr(ljsi);
  return p
end;
 
symbolic procedure brupdate(x);
% ------------------------------------------------------------------- ;
% Assume Row(X) was found with procedure FindOptRow. It is the most   ;
% recently found cse-parent. Therefore the administration needs some  ;
% updating : The set Psi of parents must be extended with X, the set  ;
% Jsi of column-indices ought to be replaced by NewJsi and (de)activa-;
% tion of relevant rows(columns) ought to take place.                 ;
% ------------------------------------------------------------------- ;
<<psi:=x.psi;
  npsi:=npsi+1;
  jsi:=reverse(newjsi);
  njsi:=newnjsi;
  wsi:=(njsi-1)*(npsi-1);
  % ----------------------------------------------------------------- ;
  % Roccup2 is the set of indices of rows, which can possibly contri- ;
  % bute to a cse. During the previous FindOptRow-step Row(X) received;
  % apparently a higher priority. Row(X) is not longer a candidate pa-;
  % rent for the cse, presently being built.                          ;
  % ----------------------------------------------------------------- ;
  foreach x in roccup2 do
  setfree(x);
  roccup2:=nil;
  setoccup(x);
  rcoccup:=x.rcoccup
>>;
 
symbolic procedure addcse;
% ------------------------------------------------------------------- ;
% The cse defined by the index-sets Psi and Jsi is added to CODMAT.   ;
% So its occurrences in the rows,which have an index in Psi, are remo-;
% ved, the description of the cse is added as a new row to CODMAT and ;
% the system-selected cse-name is used to head a new column,defining  ;
% occurrences in the parent-rows. In combination with these measures  ;
% some weights have to be reset and thus also some information in     ;
% CODHISTO. The cse-ordering has - finally - to be taken care of via  ;
% the procedure SETPREV (see the CODMAT module for comment).           ;
% ------------------------------------------------------------------- ;
begin scalar zz,zzr,zzc,lzzr,lzzc,opv,var,gc;
  zzr:=lzzr:=rzstrtcse() ;      
  lzzc:=czstrtcse(ival car zzr);
  gc:=ival car lzzc;
  zz:=lzzc;
  while gc>1 and cdr zz do
  << zz:=cdr zz; gc:=gcd2(gc,ival car zz)>>;
  if gc>1 then
           << zz:=nil;
              foreach z in zzr do zz:=mkzel(xind z,ival(z)*gc).zz;
              zzr:=lzzr:=reverse zz;
              zz:=nil;
              foreach z in lzzc do zz:=mkzel(xind z,ival(z)/gc).zz;
              lzzc:=reverse zz
            >>;
   zz:=nil;
               
  % ----------------------------------------------------------------- ;
  % ZZr and LZZr are assigned a row-Zstrt, in ascending order, defi-  ;
  % ning the cse, which must be added to CODMAT, in row Rowmax.       ;
  % LZZc is the column-Zstrt of the cse in ascending, thus "wrong" or-;
  % der. But LZZc is reversed, when updating the parent-rows in the   ;
  % Psi-loop. Similarly LZZr is used in the Jsi-loop for updating co- ;
  % lumns.                                                            ;
  % ----------------------------------------------------------------- ;
  var:=fnewsym();
  rowmax:=rowmax+1;
  setrow(rowmax,opv:=opval car jsi,var,list nil,zzr);
  % ----------------------------------------------------------------- ;
  % List Nil, parameter 4, defines the empty list of children and ex- ;
  % presses that also the EXPCOF-field of row(Rowmax) remains unused. ;
  % ----------------------------------------------------------------- ;
  rowmin:=rowmin-1;
  setrow(rowmin,opv,var,nil,nil);
  % ----------------------------------------------------------------- ;
  % The column(Rowmin) is reserved for the cse-description reverse(   ;
  % LZZc). Only the name Var is stored in the FarVar-field, like the  ;
  % operator-value in the OPVAL-field.                                ;
  % ----------------------------------------------------------------- ;
  if opv eq 'plus
   then put(var,'varlst!+,rowmin)
   else put(var,'varlst!*,rowmin);
  put(var,'rowindex,rowmax);
  % ----------------------------------------------------------------- ;
  % The new cse-name is stored either in the list of add.variables or ;
  % in the list of multiplicative variables. Its row-index is stored  ;
  % to allow retrieval of relevant information later on.              ;
  % ----------------------------------------------------------------- ;
  foreach x in psi do
  <<zz:=remzzzz(zzr,zstrt x);
    zzc:=car(lzzc).zzc;
    setzstrt(x,mkzel(rowmin,val car lzzc).zz);
    delhisto(x);
    initwght(x);
    inshisto(x);
    setprev(x,rowmax);
    lzzc:=cdr(lzzc)
    % --------------------------------------------------------------- ;
    % The cse Zstrt-description is removed from all the parent-Zstrt's;
    % before the thus shortened Zstrt's are extended with the required;
    % information about occurence and multiplicity of the new cse,re- ;
    % presented by column(Rowmin). Since column-indices are negative  ;
    % and row-Zstrt's are in ascending order a dotted pair constructi-;
    % on the SetZstrt-application is used. The Psi-loop allows to step;
    % wise reverse the column-Zstrt LZZc to produce the required form ;
    % ZZc, a Zstrt in descending order.                               ;
    % Once a row is modified it is removed from the CODHISTO-hierarchy;
    % and its HWght is recomputed before it is reinserted via CODHISTO;
    % Finally the ORDR-fields in  the parents are reset, by adding the;
    % location of the new cse to the already stored information about ;
    % the output ordering.(see for SetPrev the module CODMAT).        ;
    % --------------------------------------------------------------- ;
  >>;
  foreach y in jsi do
  <<setzstrt(y,mkzel(rowmax,val car lzzr).remzzzz(zzc,zstrt y));
    lzzr:=cdr lzzr;
    initwght(y)>>;
  setzstrt(rowmin,zzc);
  % ----------------------------------------------------------------- ;
  % The column-Zstrt ZZc is removed from all the Jsi columns it is oc-;
  % curring in and ZZc itself is stored in column(Rowmin), already re-;
  % served for this purpose. All relevant column-HWghts are recomputed;
  % like done for row(Rowmax) :                                       ;
  % ----------------------------------------------------------------- ;
  initwght(rowmax);
  inshisto(rowmax);
  initwght(rowmin);
  % ----------------------------------------------------------------- ;
  % Finally we test the modified columns and rows for redundancy.     ;
  % ----------------------------------------------------------------- ;
  foreach x in jsi do
   testredh(x);
  foreach x in psi do
   testredh(x)
end;
 
symbolic procedure rzstrtcse;
% ------------------------------------------------------------------- ;
% The Zstrt defining the cse,associated with Psi and Jsi, is made.    ;
% Psi is a list of row-indices, defining the parents.                 ;
% Jsi is a list of column -indices, defining the variables, occurring ;
% in the cse.                                                         ;
% Jsi is in ascending order. Psi is - in fact - not ordered.          ;
% This is due to the construction process.                            ;
% The cse-Zstrt is made out of the Zstrt of Row(Car Psi). The IVal's  ;
% in this Zstrt (coefficients or exponents) ought to be integers. The ;
% parents contain an integer-multiple( or integral power) of the cse. ;
% When constructing the cse-Zstrt such that the IVal's are relative   ;
% prime all further required resettings lead to integer IVal's in     ;
% CODMAT.                                                             ;
% ------------------------------------------------------------------- ;
begin scalar ljsi,zz,zzcse,gc;
  zz:=pnthxzz(car jsi,zstrt car psi);
  zzcse:=list(car zz);
  gc:=abs(ival(car zz));
  ljsi:=cdr(jsi);
  % ----------------------------------------------------------------- ;
  % All initializations for the WHILE-loop are made :                 ;
  % ZZ is that part of the Zstrt(Car Psi) that starts with the element;
  % containing the leftmost element of Jsi in its index-field.        ;
  % So its first element is also the first element of the cse-Zstrt.  ;
  % The IVal-value of this head-element is assumed to contain the gcd ;
  % of all the IVal's of the cse. During the WHILE-loop other elements;
  % of Jsi,collected in LJsi are consumed,thus producing the cse-Zstrt;
  % ----------------------------------------------------------------- ;
  while ljsi do
  <<zz:=pnthxzz(car ljsi,zz);
    gc:=gcd2(gc,abs(ival car zz));
    ljsi:=cdr ljsi;
    zzcse:=car(zz).zzcse
  >>;
  return
    if gc=1 or expshrtest()
     then reverse(zzcse)
     % -------------------------------------------------------------- ;
     % If GC = 1 the IVal's are relative prime. The ZZcse ought to be ;
     % reversed, because the cons-construction reverses the original  ;
     % information.                                                   ;
     % The alternative expresses that the GC(d) of the exponents, de- ;
     % fining a monomial-cse, obtained after temporarily expanding the;
     % TIMES-columns, has not to be divided out, since it is in con-  ;
     % flict with the information storage and retrieval of the tempo- ;
     % rarily used TIMES-columns, as realized by using the NPCD- and  ;
     % PCDvar indicators in ExpandProd and ShrinkProd.                ;
     % -------------------------------------------------------------- ;
     else
     <<zz:=nil;
       foreach z in zzcse do
         zz:=mkzel(xind z,ival(z)/gc).zz;
         % ---------------------------------------------------------- ;
         % Due to the cons-construction, reversion is now superfluous.;
         % The GC is divided out to get relative prime IVal's.        ;
         % ---------------------------------------------------------- ;
       zz
     >>
end;
 
symbolic procedure gcd2(a1,a2);
% ------------------------------------------------------------------- ;
% The Gcd of A1 and A2 is computed. The value returned is positive, if;
% A1 and A2 are positive.                                             ;
% ------------------------------------------------------------------- ;
begin scalar a3;
  a3:=remainder(a1,a2);
  return
    if a3=0
      then a2
      else gcd2(a2,a3)
end;
 
symbolic procedure expshrtest;
% ------------------------------------------------------------------- ;
% ExpShrTest returns T is Jsi contains atleast one index of a column, ;
% which is temporarily used to store (part of) the expanded represen- ;
% tation of a column, defining a TIMES-variable. Such a column has a  ;
% -2 Farvar-value. Details : Expandprod and ShrinkProd.               ;
% ------------------------------------------------------------------- ;
begin scalar ljsi,further;
 if not (opval(car jsi) eq 'plus)
  then << ljsi:=jsi;
          while (ljsi and not further) do
           << further:=(farvar(car ljsi)=-2);
              ljsi:=cdr ljsi>>
       >>;
 return(further)
end;

symbolic procedure czstrtcse(iv);
% ------------------------------------------------------------------- ;
% The row-Zstrt of the actual cse is made by applying RZstrtCse. The  ;
% parameter IV is the IVal of the head-element of this Zstrt. It will ;
% be used to compute the multiplicity of the cse in the different pa- ;
% rents. These multiplicities are stored as IVal's in the column-Zstrt;
% associated with the new life of the cse as new variable.            ;
% ------------------------------------------------------------------- ;
begin scalar lpsi,zz,zzcse;
  zz:=zstrt(car jsi);
  lpsi:=ordn(psi); % Standard Reduce function ;
  psi:=nil;
  % ----------------------------------------------------------------- ;
  % The set LPsi defines Psi in descending order, i.e. the ordering   ;
  % needed for the construction of the column-Zstrt. ZZ is the Zstrt  ;
  % of the column,which contains the parameter IV as one of its IVal's;
  % ZZ is used to produce the Psi elements, which form the cse-Zstrt, ;
  % called ZZcse.ZZ is in descending order. During the WHILE-loop exe-;
  % cution Psi is reconstructed in ascending order.                   ;
  % ----------------------------------------------------------------- ;
  while lpsi do
   <<zz:=pnthxzz(car lpsi,zz);
     zzcse:=mkzel(car lpsi,ival(car zz)/iv).zzcse;
     psi:=car(lpsi).psi;
     lpsi:=cdr(lpsi)
     % -------------------------------------------------------------- ;
     % ZZ is used to built ZZcse. Using Car(LPsi) the non-relevant e- ;
     % lements of ZZ are removed, allowing to access the next column- ;
     % element, which can be used to produce the cse-column. The mul- ;
     % tiplicity has to be stored as IVal of the actual Z-element, and;
     % is found by dividing the IVal of the present Car of ZZ by IV.  ;
     % The IVal's of the row-Zstrt of the cse are relative prime, im- ;
     % plying that the IVal's of the relevant elements of ZZ are all  ;
     % integral multiples of IV.                                      ;
     % ZZcse is made in ascending order.                              ;
     % -------------------------------------------------------------- ;
   >>;
  return zzcse 
end;
 
symbolic procedure testredzz(x);
% ------------------------------------------------------------------- ;
% TestredZZ is mutually recursive with TestredH and use in combination;
% with this routine to remove redundancy from CODMAT. Always of course;
% on a temporary basis.                                               ;
% ------------------------------------------------------------------- ;
foreach z in zstrt(x) do testredh(yind z);
 
symbolic procedure testredh(x);
% ------------------------------------------------------------------- ;
% Row (column) X is disregarded during further searches and its infor-;
% mation is deleted from CODHISTO, if the length of Zstrt(X) is redu- ;
% ced to 1. This redundancy test has to be done recursively.          ;
% ------------------------------------------------------------------- ;
if free(x) and awght(x)<2
 then
  <<rowdel(x);
    testredzz(x)>>;
 
symbolic procedure expandprod;
% ------------------------------------------------------------------- ;
% Only linear-expression like monomial cse's are found when applying  ;
% ExtBrsea1. The zero-minor condition is too strong. Monomial cse be- ;
% haviour is additive. Therefore addition chain mechanisms are employ-;
% ed to extend the relevant TIMES-columns in a number of temporarily  ;
% used columns, of which all the non-zero elements have the same expo-;
% nent value. Then ExtBrsea1 can be applied again, after relevant re- ;
% settings in CODHISTO. Procedure Shrinkprod is applied to undo this  ;
% expansion after the additional searches.                            ;
% Expandprod's functioning is illustrated by an example :             ;
% Assume : Y = -15, Var (= FarVar Y) = X and                          ;
%          Zstrt(Y) = ((6.1)(5.5)(4.5)(3.3)(2.5)(1.2)).               ; 
% Zstrt(Y) is transformed into a matrix, using algorithm 2.1, given in;
% van Hulzen '83, page 296-297. The overall functioning can be vizua- ;
% lized in the following way :                                        ;
%                                                                     ;
%     Before      Expandprod Application         After                ;
%                                                                     ;
%  column|-15|                       column|-15 -23 -24 -40 |         ;
%        +---+                             +----------------+         ;
%  row 1 | 2 |                       row 1 | 1   1          |         ;
%      2 | 5 |                           2 | 1   1   1   2  |         ;
%      3 | 3 |                           3 | 1   1   1      |         ;
%      4 | 5 |                           4 | 1   1   1   2  |         ;
%      5 | 5 |                           5 | 1   1   1   2  |         ;
%      6 | 1 |                           6 | 1              |         ;
%        -----                             ------------------         ;
%                                                                     ;
% ------------------------------------------------------------------- ;
begin scalar var,pcvary,pcdvar,zzr,ivalz,n,npcdvar,npcdv,col!*,relcols;
  for y:=rowmin:(-1) do
   if opval(y) eq 'times and not numberp(farvar y) and testrel(y)
    then relcols:=y . relcols;
  foreach y in relcols do
  << var := farvar y;
     % -------------------------------------------------------------- ;
     % TIMES-columns are only elaborated, when their Farvar-field is  ;
     % not a number, i.e. is the name of a variable or a cse, and if  ;
     % their Zstrt consists of at least 2 elements, which are not all ;
     % equal 1.                                                       ;
     % The Zstrt of such a column contains IVal's being powers of Var,;
     % the name associated with the column.                           ;
     % -------------------------------------------------------------- ;
     pcvary:=pcdvar:=zzr:=nil;
     foreach zel in zstrt(y) do
      if not (ivalz:=ival zel)=1
       then
        <<setival(zel,1);
          % --------------------------------------------------------- ;
          % Zstrt(Y) is modified. All exponents are reduced to 1, i.e.;
          % Zstrt(Y) := ((6.1)(5.1)(4.1)(3.1)(2.1)(1.1)).             ;
          % The remaining exponent parts are saved in PCvarY, using   ;
          % InsPCvv, as pairs of the form ((exponent-1).(list of indi-;
          % ces of associated rows). So                               ;
          % PCvarY := ((1.(1))(2.(3))(4.(2 4 5))).                    ;
          % --------------------------------------------------------- ;
          pcvary:=inspcvv(xind zel,ivalz-1,pcvary)
        >>;
     pcdvar:=inspcvv(y,1,pcdvar);
     % -------------------------------------------------------------- ;
     % PCDvar is a list of pairs consisting of an exponent EXPO and a ;
     % list of indices of columns, which were (temporarily) used to   ;
     % store occurrences of Var^EXPO. Initially holds :               ;
     % PCDvar := ((1.(-15))).                                         ;
     % -------------------------------------------------------------- ;
     n:=0;
     npcdv:=npcdvar:=get(var,'npcdvar);
     % -------------------------------------------------------------- ;
     % NPCDvar is a list of column-indices, which were used during a  ;
     % previous ExpandProd activity, to store temporarily the additio-;
     % nal columns, to be produced with PCvarY. NPCDvar was stored on ;
     % the property-list of Var, during a previous application of     ;
     % Expandprod, and using the actual value of NPCDv. Assume now,   ;
     % for the example, that NPCDvar = (-23 -24).                     ;
     % NPCDv is initially the previous version of NPCDvar, but eventu-;
     % ally extended, during an ExpandProd-application. This new value;
     % is stored on the property-list of Var before leaving ExpandProd;
     % Hence the columns, associated with NPCDvar are reused when ever;
     % necessary. Their Farvar-fields will always contain the value -2;
     % to avoid a wrong use.                                          ;
     % -------------------------------------------------------------- ;
     foreach pc in pcvary do
     % -------------------------------------------------------------- ;
     % Each item of the PCvarY list is now used to make a new column, ;
     % starting with the smallest exponent value.                     ;
     % -------------------------------------------------------------- ;
      <<if npcdvar
         then
          <<col!*:=car(npcdvar);
            npcdvar:=cdr(npcdvar);
            % ------------------------------------------------------- ;
            % The first 2 columns, which are selected are -23 and -24.;
            % ------------------------------------------------------- ;
          >>
         else 
          <<col!*:=rowmin:=rowmin-1;
            npcdv:=col!*.npcdv;
            % ------------------------------------------------------- ;
            % All additional columns, which are needed are newly gene-;
            % rated. Assume their indices to be -40, -41, ...         ;
            % ------------------------------------------------------- ;
          >>;
        %------------------------------------------------------------ ;
        % Hence, whenever necessary a new column-index is made and ad-;
        % ded to the set (list) NPCDv.                                ; 
        % ----------------------------------------------------------- ;
        zzr:=mkzel(col!*,car(pc)-n).zzr;
        % ----------------------------------------------------------- ;
        % ZZr is a Zstrt, used to produce relevant additional row in- ;
        % formation, needed on a temporary basis, when expanding mono-;
        % mial row descriptions. ZZr is growing during the execution  ;
        % of the current ForEach-loop in the following way :          ;
        % ZZr := ((-23 . 1)),                                         ;
        % ZZr := ((-24 . 1) (-23 . 1)),                               ;
        % ZZr := ((-40 . 2) (-24 . 1) (-23 . 1)).                     ;
        % ----------------------------------------------------------- ;
        setrow(col!*,'times,-2,nil,nil);
        % ----------------------------------------------------------- ;
        % FarVar := -2 setting of column COL!*.                       ;
        % ----------------------------------------------------------- ;
        foreach x in cdr(pc) do
         % ---------------------------------------------------------- ;
         % PC is a pair (reduced exponent . list of indices of rows,of;
         % which the Zstrt ought to be temporarily modified).         ;
         % ---------------------------------------------------------- ;
         foreach z in zzr do
          <<setzstrt(x,inszzzr(z,zstrt x));
            % ------------------------------------------------------- ;
            % Every element of ZZr is inserted in Zstrt(X), where X is;
            % running through the row-index list, defined by PC.      ;
            % ------------------------------------------------------- ;
            setzstrt(yind z,inszzz(mkzel(x,val z),zstrt yind z))
            % ------------------------------------------------------- ;
            % The Zstrts of the corresponding col.s are also modified.;
            % ------------------------------------------------------- ;
          >>;
        % ----------------------------------------------------------- ;
        % This double FOREACH-loop is executed inside the PC-FOREACH- ;
        % loop. For the example holds :                               ;
        % PC=(1.(1)) & ZZr=((-23 . 1)) gives insertion of (-23 . 1) in;
        % Zstrt(row(1)) and of (1 . 1) in Zstrt(col(-23)).            ;
        % PC=(2.(3)) & ZZr=((-24 .1 )(-23 . 1)) gives insertion of    ;
        % (-24 . 1) and (-23 . 1) in Zstrt(row(3)) and of (3 . 1) in  ;
        % Zstrt(col(-23)) and Zstrt(col(-24)).                        ;
        % Finally PC=(4.(2 4 5)) & ZZr=((-40 . 2)(-24 . 1)(-23 . 1))  ;
        % gives insertion of (-40 . 2),(-24 . 1) and (-23 . 1) in     ;
        % in Zstrt(row(2)), Zstrt(row(4)) and Zstrt(row(5)),of (2 . 2);
        % (4 . 2) and (5 . 2) in Zstrt(col(-40)), and of (2 . 1),(4 . ;
        % 1) and (5 . 1), finally, in both Zstrt(col(-23)) and Zstrt( ;
        % col(-24)).                                                  ;
        % See also the matrix shown above.                            ;
        % ----------------------------------------------------------- ;
        pcdvar:=inspcvv(col!*,car(pc)-n,pcdvar);
        % ----------------------------------------------------------- ;
        % The PCDvar-list is also iteratively built up. This list is  ;
        % needed in Shrinkprod. Its final form for the example is :   ;
        % ((1.(-15 -23 -24)) (2.(-40)))                               ;
        % ----------------------------------------------------------- ;
        n:=car(pc);
        % ----------------------------------------------------------- ;
        % N is used to compute the reduced exponents iteratively.     ;
        % ----------------------------------------------------------- ;
      >>;
     put(var,'pcdvar,pcdvar);
     put(var,'npcdvar,npcdv);
   >>
end;

symbolic procedure testrel colindex;
% ------------------------------------------------------------------- ;
% TestRel(evance) is used to determine if the TIMES-column with index ;
% Y possesses a Zstrt n which at least 2 elements obey the condition  ;
% that their IVal-value is at least 2. This test is either performed  ;
% in EXPANDPROD or in SHRINKPROD. In the latter case the test is need-;
% ed to be able to decide if a next application of EXPANDPROD is re-  ;
% quired. If so this is indicated by setting the flag EXPSHR. Hence   ;
% its existence is tested in the former case. When the flag proves to ;
% have been set it is removed to allow a possible next test. If it was;
% not yet set the TIMES-column with the index Y has not been used be- ;
% fore in an application of EXPANDPROD.                               ;
% ------------------------------------------------------------------- ;
begin scalar btst,mn,rcol,relcols,relrow,onerows,orows;
  if(btst:=flagp(list(farvar(colindex)),'expshr))
    then remflag(list(farvar(colindex)),'expshr)
    else
      << mn:=0;
         foreach z in zstrt(colindex) do
          if ival(z)>1 then << mn:=mn+1;
                               if mn=1 then relrow:=xind z
                            >>
                       else onerows:=xind(z).onerows;
         if not (btst:=(mn>1)) and mn=1 and
            onerows and length(zstrt(relrow))>1
            then
             << mn:=0;
                foreach z in zstrt(relrow) do
                 if (yind(z) neq colindex)
                  then << mn:=mn+1; relcols:=yind(z).relcols >>;
                if mn>0
                 then
                  while relcols and not(btst) do
                   << rcol:=car relcols; relcols:=cdr relcols;
                      orows:=onerows;
                      while orows and not(btst) do
                       << btst:=pnthxzz(car orows,zstrt rcol);
                          orows:=cdr orows
                       >>
                   >>
             >>
      >>;
  return(btst)
end;

symbolic procedure inspcvv(x,iv,s);
% ------------------------------------------------------------------- ;
% S is a list of pairs, given in ascending Car-ordering. The Cars are ;
% integers IV and the Cdrs are lists of objects X. Application of     ;
% InsPCvv leads to inclusion of the object X in the list associated   ;
% with IV. This Integer Value might be an exponent and the objects can;
% be row-indices, for instance.                                       ;
% ------------------------------------------------------------------- ;
if null(s) 
 then list(iv.list(x))
 else
  if iv=caar(s)
   then (iv.(x.cdar(s))).cdr(s)
   else
    if iv<caar(s)
     then (iv.list(x)).s
     else car(s).inspcvv(x,iv,cdr s);


symbolic procedure shrinkprod;
% ------------------------------------------------------------------- ;
% After expansion of certain Times-columns additional Breuer-searches ;
% are performed. Shrinkprod is used to restore the remaining informa- ;
% tion in the standard form. So the distributed exponent portions are ;
% added together and stored in the original column. For the example,  ;
% introduced in Expandprod all remaining information is to be collect-;
% ed in column -15.                                                   ;
% Assume the Breuer-searches to have produced the following result :  ;
%                                                                     ;
% column|-15 -23 -24 -40|-60 -61 -62|     Row(7) and column(-60)      ;
%       +---------------+-----------+     define cse X5=X^2*X3.       ;
% row 1 |               |         1 |                                 ;
%     2 |               | 1         |     Row(8) and column(-61)      ;
%     3 |               |     1     |     define cse X3=X*X2.         ;
%     4 |               | 1         |                                 ;
%     5 |               | 1         |     Row(9) and column(-62)      ;
%     6 | 1             |           |     define cse X2=X*X.          ;
%       +---------------+-----------+                                 ;
%     7 |             2 |     1     |     The columns -15,-23 and -24 ;
%     8 |         1     |         1 |     define X-occurrences and    ;
%     9 | 1   1         |           |     the column -40 defines an   ;
%       -----------------------------     X^2-occurrence.             ;
%                                                                     ;
% ShrinkProd is used to recombine the information of column -15 and   ;
% those given in the PCDvar-list. The result is :                     ;
%                                                                     ;
% column|-15 -23 -24 -40|-60 -61 -62|                                 ;
%       +---------------+-----------+                                 ;
% row 1 |               |         1 |    The columns -23, -24 and -40 ;
%     2 |               | 1         |    remain unused until the next ;
%     3 |               |     1     |    application of ExpandProd.   ;
%     4 |               | 1         |    The indices remain stored in ;
%     5 |               | 1         |    the list NPCDvar (see the    ;
%     6 | 1             |           |    procedure ExpandProd).       ;
%       +---------------+-----------+    X^2 can again be found as a  ;
%     7 | 2             |     1     |    cse (see column -15). Hence  ;
%     8 | 1             |         1 |    ImproveLayout(see the module ;
%     9 | 2             |           |    CODAD1) is needed.           ;
%       -----------------------------                                 ;
%                                                                     ;
% ------------------------------------------------------------------- ;
begin scalar var,pcdvar,zstreet,el,exp,collst,indx,further;
  for y:=rowmin:(-1) do
  if not numberp(var:=farvar y) and (pcdvar:=get(var,'pcdvar)) 
                                and opval(y) eq 'times
  then
  << % -------------------------------------------------------------- ;
     % Only Times-columns are elaborated, which are associated with   ;
     % those Var's of which the PCDvar-indicator has a nonNil value.  ;
     % The Opval test is needed because Var's are in general associa- ;
     % ted with both PLUS and TIMES-columns.                          ;
     % For the example holds : Var = X and PCDvar = ((1.(-15 -23 -24) ;
     % (2.(-40))).                                                    ;
     % -------------------------------------------------------------- ;
     zstreet:=zstrt(y);
     % -------------------------------------------------------------- ;
     % Initially holds : Zstrt(Y) = Zstreet = ((9.1)(6.1)).           ;
     % Application of ShrinkProd leads to : Zstreet = ((9.2)(8.1)(7.2);
     % (6.1)). This also affects the Zstrt's of the rows 7,8 and 9 and;
     % of the columns -23,-24 and -40.                                ;
     % -------------------------------------------------------------- ;
     foreach pcd in pcdvar do
      <<% ----------------------------------------------------------- ;
        % Pcd gets 2 different values for the example :               ;
        % (1.(-15=Y -23 -24)) and (2.(-40)).                          ;
        % ----------------------------------------------------------- ;
        exp:=car(pcd);
        collst:=delete(y,cdr pcd);
        % ----------------------------------------------------------- ;
        % The original Var!* column is left out during the now follow-;
        % ing reconstruction process, because it is Zstreet = Zstrt(Y);
        % which is restored.                                          ;
        % ----------------------------------------------------------- ;
        foreach col in collst do
        % ----------------------------------------------------------- ;
        % These Col's are all FarVar = -2 columns.                    ;
        % ----------------------------------------------------------- ;
         <<foreach z in zstrt(col) do
            <<% ----------------------------------------------------- ;
              % These Z's are pairs (row-index . exponent-value).     ;
              % ----------------------------------------------------- ;
              indx:=xind(z);
              if el:=assoc(indx,zstreet)
               then setival(el,ival(el)+exp)
                    % ----------------------------------------------- ;
                    % If the row-index Indx is already used in the des;
                    % cription of Zstreet (i.e. in the column -15 of  ;
                    % the example) only the value in the exponent-    ;
                    % field of the Z-element has to be reset. This is ;
                    % done with SetIval, implying that through a      ;
                    % Replaca command  Zstreet is also modified!      ;
                    % ----------------------------------------------- ;
               else 
                <<% ------------------------------------------------- ;
                  % If the row-index Indx is not yet used in the des- ;
                  % cription of Zstreet a new element has to be added ;
                  % to both Zstreet and the Zstrt of the row Indx.    ;
                  % ------------------------------------------------- ;
                  zstreet:=inszzz(el:=mkzel(indx,exp),zstreet);
                  setzstrt(indx,inszzzr(mkzel(y,val el),zstrt indx))
                >>;
              setzstrt(indx,delyzz(col,zstrt indx))
              % ----------------------------------------------------- ;
              % Now the element Z is removed from the Zstrt of row    ;
              % Indx. The complete column Col is emptied and can thus ;
              % freely be reused during a next application of Expandp.;
              % To avoid any confusion ClearRow is used, implying that;
              % the FarVar-field of the column Col gets the value -1. ;
              % ----------------------------------------------------- ;
            >>;
           clearrow(col)
         >>
       >>;
      setzstrt(y,zstreet);
      remprop(var,'pcdvar);
      % ------------------------------------------------------------- ;
      % The final Zstreet-value is stored in column Y ( in the example;
      % column -15) and the PCDvar information is removed from the    ;
      % property list of Var.                                         ;
      % ------------------------------------------------------------- ;
      if testrel(y) then <<further:=t;flag(list(var),'expshr)>>
      % ------------------------------------------------------------- ;
      % After regrouping TIMES-column information it is tested if a   ;
      % next application of EXPANDPROD is needed. If so T is returned.;
      % This value is used in EXTBRSEA to decide if the EXPAND-SHRINK ;
      % repeat-loop has to be continued or not.                       ;
      % ------------------------------------------------------------- ;
    >>;
    return(further)
 end;

endmodule;


module codad1;  % Description of some procedures.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Authors :   J.A. van Hulzen, B.J.A. Hulshof.                        ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% The module CODAD1 contains the description of the procedures        ;
% IMPROVELAYOUT (part 1), TCHSCHEME (part 2) and CODFAC (part 3),     ;
% which are used in the procedure OPTIMIZELOOP (see the module CODCTL);
% to complete the effect of an application of EXTBRSEA (see the module;
% CODOPT). Application of each of these routines is completed by re-  ;
% turning a Boolean value, which is used to decide if further optimi- ;
% zation is still profitable.                                         ;
% The Smacro's Find!+Var and Find!*Var form service facilities, needed;
% at different places in this module. These Smacro's define an applic-;
% ation of the procedure GetCind.                                     ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% Global identifiers needed in this module are:                       ;
% ------------------------------------------------------------------- ;

global '(rowmin rowmax kvarlst codbexl!*);

% ------------------------------------------------------------------- ;
% The meaning of these globals is given in the module CODMAT.         ;
% ------------------------------------------------------------------- ;

symbolic procedure getcind(var,varlst,op,fa,iv);
% ------------------------------------------------------------------- ;
% The purpose of the procedure GetCind is to create a column in CODMAT;
% which will be associated with the variable Var if this variable does;
% not yet belong to the set Varlst,i.e.does not yet play a role in the;
% corresponding PLUS- or TIMES setting (known by the value of Op).Once;
% the column exists (either created or already available), its Zstrt  ;
% is modified by inserting the Z-element (Fa,IV) in it. Finally the   ;
% corresponding Z-element for the father-row, i.e. (Y,IV) is returned.;
% ------------------------------------------------------------------- ;
begin scalar y,z;
  if null(y:=get(var,varlst))
  then
  <<y:=rowmin:=rowmin-1;
    put(var,varlst,y);
    setrow(y,op,var,nil,nil)
  >>;
  setzstrt(y,inszzzn(z:=mkzel(fa,iv),zstrt y));
  return mkzel(y,val z)
end;
 
symbolic smacro procedure find!+var(var,fa,iv);
getcind(var,'varlst!+,'plus,fa,iv);

symbolic smacro procedure find!*var(var,fa,iv);
getcind(var,'varlst!*,'times,fa,iv);

% ------------------------------------------------------------------- ;
% PART 1 : LAYOUT IMPROVEMENT                                         ;
% ------------------------------------------------------------------- ;

symbolic procedure improvelayout;
% ------------------------------------------------------------------- ;
% During optimization, and thus during common subexpression generation;
% it might happen that a (sub)expression is reduced to a single varia-;
% ble, leading to output containing the assignment statements :       ;
%  b:=b-thing;                                                        ;
%  ......                                                             ;
%  a:=b;                                                              ;
% This redundancy can be removed by replacing all occurrences of b by ;
% a, by replacing b:=b-thing by a:=b=thing and by removing a:=b. Here ;
% we assume a,b to be only cse-names.                                 ;
% ------------------------------------------------------------------- ;
begin scalar var,b;
  for x:=0:rowmax do
  if not (numberp(var:=farvar x)
          or
          pairp(var)
          or
          (member(x,codbexl!*)
           and
           (get(var,'nex) or not (flagp(var, 'newsym)))))
     and testononeel(var,x) then b:=t;
  % ----------------------------------------------------------------- ;
  % If B=T redundancy was removed from CODMAT, but not necessarily    ;
  % from Kvarlst, the list of pairs of kernels and names associated   ;
  % with them. ImproveKvarlst is applied to achieve this.             ;
  % ----------------------------------------------------------------- ;
  if b then improvekvarlst();
  return b
end;

 
symbolic procedure testononeel(var,x);
% ------------------------------------------------------------------- ;
% Row X,having Var as its assigned variable, and defining some expres-;
% sion, through its Zstrt, Chrow and ExpCof, is analysed.             ;
% If this row defines a redundant assignment statement the above indi-;
% cated actions are performed.                                        ;
% ------------------------------------------------------------------- ;
begin
  scalar scol,srow,el,signiv,signec,zz,ordrx,oldvar,b,scof,bop!+,lhs;
  if (zz:=zstrt x) and null(cdr zz) and null(chrow x) and
      ((signiv:=ival(el:=car zz))=1 or signiv=-1) and
      ((signec:=expcof(x))=1 or signec=-1)
  then
   << % ------------------------------------------------------------- ;
      % Row(X) defines a Zstreet, consisting of one Z-element. The    ;
      % variable-name, associated with this element is stored in the  ;
      % FarVar-field of the column, whose index is in the Yind-part of;
      % this Z-element,i.e. Oldvar:=FarVar(SCol),the b mentioned above;
      % The IVal-value of this element, an exponent or a coefficient, ;
      % is 1 or -1 and the ExpCof-value, a coefficient or an exponent,;
      % is also 1 or -1. Realistic possibilities are of course only   ;
      % 1*Oldvar^1 or -1*Oldvar^1 (i.e. 1*b^1 or -1*b^1).             ;
      % ------------------------------------------------------------- ;
      scol:=yind el;
      oldvar:=farvar(scol);
      if srow:=get(oldvar,'rowindex)
       then b:=t
       else
        if assoc(oldvar,kvarlst) and
           signiv=1 and signec=1 and not member(oldvar,codbexl!*)
         then b:=t;
      % ------------------------------------------------------------- ;
      % So B=T if either Oldvar has its own defining row, whose index ;
      % is stored as value of the indicator Rowindex, i.e. if Oldvar  ;
      % defines a cse, or if Oldvar is the name of a kernel, stored in;
      % Kvarlst, as cdr-part of the pair having Oldvar as its car-part;
      % ------------------------------------------------------------- ;
       if b
        then
         << % ------------------------------------------------------- ;
            % We start replacing all occurrences of Oldvar by Var, in ;
            % both the PLUS- and the TIMES-part of CODMAT, by applying;
            % the function TShrinkCol. In addition all eventually exis; 
            % ting occurences of Oldvar in Kvarlst have to replaced as;
            % well by Var(,the a mentioned above).                    ;
            % ------------------------------------------------------- ;
            setzstrt(scol,delyzz(x,zstrt scol));
            tshrinkcol(oldvar,var,'varlst!+);
            tshrinkcol(oldvar,var,'varlst!*);
            kvarlst:=subst(var,oldvar,kvarlst);
            if (lhs:=get(oldvar,'inlhs)) 
             then
              << put(lhs,'nex,subst(var,oldvar,get(lhs,'nex)));
                 remprop(oldvar,'inlhs)>>;
            if srow
            then
             << % --------------------------------------------------- ;
                % Oldvar is the name of a cse, defined through the row;
                % index Srow. So this cse-definition has to be assign-;
                % ed to Var as new value and the Srow itself has to be;
                % made redundant. The Ordr-field of Var has to be chan;
                % ged to be able to remain guaranteeing a correct out-;
                % put sequence.                                       ;
                % --------------------------------------------------- ;
                ordrx:=ordr(x);
                bop!+:=opval(srow) eq 'plus;
                if bop!+ then scof:=expcof srow
                         else scof:=signec*expcof(srow);
                setrow(x,opval srow,var,list(chrow srow,scof),
                                                           zstrt srow);
                setordr(x,append(ordr srow,remordr(srow,ordrx)));
                if signiv=-1
                 then
                  <<foreach z in zstrt(scol) do setival(z,-ival(z));
                    foreach ch in chrow(x) do setexpcof(ch,-expcof(ch))
                  >>;
                foreach ch in chrow(srow) do setfarvar(ch,x);
                clearrow(srow);
                setordr(srow,nil);
                codbexl!*:=subst(x,srow,codbexl!*);
                foreach z in zstrt(x) do
                 <<if bop!+ then setival(z,signiv*ival(z));
                   setzstrt(yind z,inszzz(mkzel(x,val z),
                                            delyzz(srow,zstrt yind z)))
                 >>;
                for sindex:=0:rowmax
                 do setordr(sindex,subst(x,srow,ordr sindex));
                testononeel(var,x)
             >>
            else
             << % --------------------------------------------------- ;
                % Oldvar is the system-generated name of a kernel.    ;
                % The internal administration is modified, as to pro- ;
                % vide Var with its new role.                         ;
                % As a side-effect the index X of the kernel defining ;
                % row is replaced in CodBexl!* by the name Var, if oc-;
                % curring of course, i.e. if this function definition ;
                % was given at toplevel on input.                     ;
                % This information is used in ImproveKvarlst.         ;
                % --------------------------------------------------- ;
                codbexl!*:=subst(var,x,codbexl!*);
                ordrx:=remordr(oldvar,ordr x);
                clearrow(x);
                setordr(x,nil);
                for sindex:=0:rowmax do
                 setordr(sindex,
                              updordr(ordr sindex,var,oldvar,ordrx,x));
                improvekvarlst()
             >>
         >>
   >>;
  return b;
end;

symbolic procedure remordr(x,olst);
% ------------------------------------------------------------------- ;
% Olst is the value of the Ordr-field of a row of CODMAT. Olst defines;
% in which order the cse's, occurring in the (sub)expression, whose   ;
% description starts in this row, have to be printed ahead of this    ;
% (sub)expression. It is a list of kernelnames and/or indices of rows ;
% where cse-descriptions start.                                       ;
% RemOrdr returns Olst after removal of X, if occcurring.             ;
% ------------------------------------------------------------------- ;
if null(olst)
then olst
else
  if car(olst)=x
  then remordr(x,cdr olst)
  else car(olst).remordr(x,cdr olst);

symbolic procedure updordr(olst,var,oldvar,ordrx,x);
% ------------------------------------------------------------------- ;
% Olst is described in RemOrdr. OrdrX is the Olst of row X after remo-;
% val Oldvar from it. Row X defines Var:=Oldvar. Oldvar, a kernelname,;
% is replaced by Var in Olst. If X is occurring in Olst OrdrX have to ;
% be inserted in Olst. The thus modified version of Olst is returned. ;
% ------------------------------------------------------------------- ;
if null(olst)
then olst
else
  if car(olst) eq oldvar
  then var.updordr(cdr olst,var,oldvar,ordrx,x)
  else
    if car(olst)=x
    then append(var.ordrx,updordr(cdr olst,var,oldvar,ordrx,x))
    else car(olst).updordr(cdr olst,var,oldvar,ordrx,x);

symbolic procedure improvekvarlst;
% ------------------------------------------------------------------- ;
% Kvarlst, a list of pairs (name . function definition) is improved,if;
% necessary. This is only required if in the list CodBexl!* occuring  ;
% names are not yet used in Kvarlst. Hence adequate rewriting of      ;
% b:=sin(x)                                                           ;
% ........                                                            ;
% a:=b                                                                ;
% into                                                                ;
% a:=sin(x) is needed,i.e. replacement of (b . sin(x)) by (a . sin(x));
% in Kvarlst.                                                         ;
% ------------------------------------------------------------------- ;
begin scalar invkvl,newkvl,x,y,kv,lkvl,cd,cd1;
  newkvl:=kvarlst;
  repeat
  <<lkvl:=kvarlst:=newkvl;
    invkvl:=newkvl:=nil;
    while lkvl do
    <<kv:=car(lkvl);
      lkvl:=cdr(lkvl);
      cd1:=member(car kv,codbexl!*);
      x:=assoc(cdr kv,invkvl);
      if x
      then cd:=(cd1 and member(cdr x,codbexl!*));
      if x and not cd
      then
      <<kv:=car(kv);
        x:=cdr(x);
        if cd1
        then <<y:=x;
               x:=kv;
               kv:=y>>;
        tshrinkcol(kv,x,'varlst!+);
        tshrinkcol(kv,x,'varlst!*);
        for rindx:=0:rowmax do
        setordr(rindx,subst(x,kv,ordr rindx));
        newkvl:=subst(x,kv,newkvl);
        invkvl:=subst(x,kv,invkvl);
        lkvl:=subst(x,kv,lkvl)
      >>
      else
      <<invkvl:=(cdr(kv).car(kv)).invkvl;
        newkvl:=kv.newkvl
      >>
    >>
  >>
  until length(kvarlst)=length(newkvl);
end;

symbolic procedure tshrinkcol(oldvar,var,varlst);
% ------------------------------------------------------------------- ;
% All occurrences of Oldvar have to be replaced by Var. This is done  ;
% by replacing the PLUS and TIMES column-indices of Oldvar by the cor-;
% responding indices of Var. Y1 and Y2 get the value of the Oldvar-   ;
% index and the Var-index, respectively. As a side-effect, all additi-;
% onal information, stored in the property-list of Oldvar is removed. ;
% ------------------------------------------------------------------- ;
begin scalar y1,y2;
  if y1:=get(oldvar,varlst)
  then
  <<if y2:=get(var,varlst)
    then
    <<foreach z in zstrt(y1) do
      <<setzstrt(y2,inszzzn(z,zstrt y2));
        setzstrt(xind z,inszzzr(mkzel(y2,val z),
                 delyzz(y1,zstrt xind z)))
      >>;
      clearrow(y1)
    >>
    else
    <<setfarvar(y1,var);
      put(var,varlst,y1)
    >>;
    remprop(oldvar,varlst)
  >>;
  remprop(oldvar,'npcdvar);
  remprop(oldvar,'nvarlst);
end;


% ------------------------------------------------------------------- ;
% PART 2 : INFORMATION MIGRATION                                      ;
% ------------------------------------------------------------------- ;
symbolic procedure tchscheme;
% ------------------------------------------------------------------- ;
% A product(sum) -reduced to a single element- can eventually be remo-;
% ved from the TIMES(PLUS)-part of CODMAT. If certain conditions are  ;
% fulfilled (defined by the function TransferRow) it is transferred to;
% the Zstreet of its father PLUS(TIMES)-row and its index is removed  ;
% from the ChRow of its father.                                       ;
% T is returned if atleast one such a migration event takes place.    ;
% NIL is returned otherwise.                                          ;
% ------------------------------------------------------------------- ;
begin scalar zz,b;
  for x:=0:rowmax do
  if (not farvar(x)=-1)
     and (zz:=zstrt x) and null(cdr zz) and transferrow(x,ival car zz)
   then <<chscheme(x,car zz); b:=t>>;
  return b;
end;

symbolic procedure chscheme(x,z);
% ------------------------------------------------------------------- ;
% The Z-element Z, the only element the Zstreet of row(X) has, has to ;
% be transferred from the PLUS(TIMES)-part to the TIMES(PLUS)-part of ;
% CODMAT.                                                             ; 
% ------------------------------------------------------------------- ;
begin scalar fa,opv,cof,exp;
    setzstrt(yind z,delyzz(x,zstrt yind z));
    setzstrt(x,nil);
    if opval(x) eq 'plus
    then <<exp:=1; cof:=ival z>>
    else <<exp:=ival z; cof:=1>>;
 l1: fa:=farvar(x);
     opv:=opval(x);
     if opv eq 'plus
     then
     <<cof:=cof**expcof(x);
       exp:=expcof(x)*exp;
       chdel(fa,x);
       clearrow(x);
       if null(zstrt fa) and transferrow(fa,exp)
       then <<x:=fa; goto l1>>
     >>
     else
       if opv eq 'times
       then
       <<cof:=cof*expcof(x);
         chdel(fa,x);
         clearrow(x);
         if null(zstrt fa) and transferrow(fa,cof)
         then <<x:=fa; goto l1>>
       >>;
     updfa(fa,exp,cof,z)
end;

symbolic procedure updfa(fa,exp,cof,z);
% ------------------------------------------------------------------- ;
%  FA is the index of the father-row of the Z-element Z,which has to  ;
% be incorporated in the Zstreet of this row. Its exponent is Exp and ;
% its coefficient is Cof, both computed in its calling function       ;
% ChScheme.                                                           ;
% ------------------------------------------------------------------- ;
if opval(fa) eq 'plus
then setzstrt(fa,inszzzr(find!+var(farvar yind z,fa,cof),zstrt fa))
else 
<<setzstrt(fa,inszzzr(find!*var(farvar yind z,fa,exp),zstrt fa));
  setexpcof(fa,cof*expcof(fa))
>>;

symbolic procedure transferrow(x,iv);
% ------------------------------------------------------------------- ;
% IV is the Ivalue of the Z-element, oreming the Zstreet of row X.    ;
% This element can possibly be transferred.                           ;
% T is returned if this element can be transferred. NIL is returned   ;
% otherwise.                                                          ;
% ------------------------------------------------------------------- ;
if opval(x) eq 'plus
 then transferrow1(x) and opval(farvar x) eq 'times
 else transferrow1(x) and transferrow2(x,iv);

symbolic procedure transferrow1(x);
% ------------------------------------------------------------------- ;
% T is returned if row(X) defines a primitive expression (no children);
% which is part of a larger expression, i.e. row(X) defines a child-  ;
% expression.                                                         ;
% ------------------------------------------------------------------- ;
null(chrow x) and numberp(farvar x);

symbolic procedure transferrow2(x,iv);
% ------------------------------------------------------------------- ;
% Row(X) defines a product of the form ExpCof(X)*(a variable) ^ IV,   ;
% which is part of a sum.                                             ;
% X is temporarily removed from the list of its fathers children when ;
% computing B, the return-value.                                      ;
% B=T if the father-row defines a sum and if either the exponent IV=1 ;
% or if the father-Zstreet is empty (no primitive terms) and the fa-  ;
% ther itself can be transferred, i.e. if ExpCof(X)*(a variable) ^ (IV;
% *ExpCof(Fa)) can be incorporated in the Zstreet of the grandfather- ;
% row (,which again defines a product).                               ;
% ------------------------------------------------------------------- ;
begin scalar fa,b;
  fa:=farvar(x);
  chdel(fa,x);
  b:=opval(fa) eq 'plus and (iv=1 or (null(zstrt fa) and
                                       transferrow(fa,iv*expcof(fa))));
  setchrow(fa,x.chrow(fa));
  return b;
end;

% ------------------------------------------------------------------- ;
% PART 3 : APPLICATION OF THE DISTRIBUTIVE LAW.                       ;
% ------------------------------------------------------------------- ;
% An expression of the form a*b + a*c + d is distributed over 3 rows  ;
% of CODMAT : One to store the sum structure, i.e. to store the pp of ;
% the sum, being d, in a Zstrt and 2 others to store the composite    ;
% terms a*b and a*c as monomials. The indices of the latter rows are  ;
% also stored in the list Chrow, associated with the sum-row.         ;
% In addition 4 columns are introduced. One to store the 2 occurrences;
% of a and 3 others to store the information about b,c and d. The a,b ;
% and c column belong to the set of TIMES-columns, i.e. a,b and c are ;
% elements of the list Varlst!* (see the module CODMAT). Similarly the;
% d belongs to Varlst!+. If this sum is remodelled to obtain a*(b + c);
% + d changes have to be made in the CODMAT-structure:                ;
% Now 2 sum-rows are needed and only 1 product-row. Hence the Chrow-  ;
% information of the original sum-row has to be changed and the 2 pro-;
% duct-rows have to be removed and replaced by one new row, defining  ;
% the Zstrt for a and the Chrow to find the description of b + c back.;
% In addition the column-information for all 4 columns has to be reset;
% This is a simple example. In general more complicated situations can;
% be expected. An expression like a*b + a*sin(c) + d requires 4 rows, ;
% for instance . A CODFAC-application always follows a ExtBrsea-execu-;
% tion. This implies that potential common factors, defined through *-;
% col's always have an exponent-value = 1. A common factor like a^3 is;
% always replaced by a cse (via an appl. of Expand- and Shrinkprod),  ;
% before the procedure CODFAC is applied. Hence atmost 1 exponent in a;
% column is not equal 1.                                              ;
% ------------------------------------------------------------------- ;

symbolic procedure codfac;
% ------------------------------------------------------------------- ;
% An application of the procedure CodFac results in an exhaustive all-;
% level application of the distributive law on the present structure  ;
% of the set of input-expressions, as reflected by the present version;
% of CODMAT.                                                          ;
% If any application of the distributive law proves to be possible the;
% value T is returned.This is an indication for the calling routine   ;
% OptimizeLoop that an additional application of ExtBrsea might be    ;
% profitable.                                                         ;
% If such an application is not possible the value Nil is returned.   ;
% ------------------------------------------------------------------- ;
begin scalar b,lxx;
  for y:=rowmin:(-1) do
   % ---------------------------------------------------------------- ;
   % The Zstrts of all *-columns, which are usable (because their Far-;
   % Var-field contains a Var-name), are examined by applying the pro-;
   % cedure SameFar. If this application leads to a non empty list LXX;
   % with information, needed to be able to apply the distributive law;
   % the local variable B is set T, possibly the value to be returned.;
   % B gets the initial value Nil, by declaration.                    ;
   % ---------------------------------------------------------------- ;
   if not (farvar(y)=-1 or farvar(y)=-2) and
                                opval(y) eq 'times and (lxx:=samefar y)
    then
     <<b:=t;
       foreach el in lxx do commonfac(y,el)
     >>;
  return b
end;

symbolic procedure samefar(y);
% ------------------------------------------------------------------- ;
% Y is the index of a TIMES-column. The procedure SameFar is designed ;
% to allow to find and return a list Flst consisting of pairs, formed ;
% by a father-index and a sub-Zstrt of the Zstrt(Y), consisting of Z's;
% such that Farvar(Xind Z) = Car Flst, i.e. the Xind(Z)-rows define   ;
% (composite) productterms of the same sum, which contain the variable;
% corresponding with column Y as factor in their primitive part.      ;
% ------------------------------------------------------------------- ;
begin scalar flst,s,far;
  foreach z in zstrt(y) do
   if numberp(far:=farvar xind z) and opval(far) eq 'plus
    then
     if s:=assoc(far,flst)
      then rplacd(s,inszzz(z,cdr(s)))
      else flst:=(far.inszzz(z,s)).flst;
  return
    foreach el in flst conc
    if cddr(el)
    then list(el)
    else nil
end;

symbolic procedure commonfac(y,xx);
% ------------------------------------------------------------------- ;
% Y is the index of a TIMES-column and XX an element of LXX, made with;
% SameFar(Y), i.e. a pair consisting of the index Far of a father-sum ;
% row and a sub-Zstrt,consisting of Z-elements, defining factors in   ;
% productterms of this father-sum.                                    ;
% These factors are defined by Z-elements (Y.exponent). Atmost one of ;
% these exponents is greater than 1.                                  ;
% The purpose of CommonFac is to factor out this element,i.e. to remo-;
% ve a Z-element (Y.1) from the Zstrts of the children and also its   ;
% corresponding occurrences from ZZ3 = Zstrt(Y), to combine the remai-;
% ning sum-information in a new PLUS-row, with index Nsum, and to cre-;
% ate a TIMES-row, with index Nprod, defining the product of the sum, ;
% given by the row Nsum, and the variable corresponding with column Y.;
% ZZ2 and CH2 are used to (re)structure information, by allowing to   ;
% combine the remaining portions of the child-rows.The father (with   ;
% index Far) is defined by a Zstrt (its primitive part) and by CH1 =  ;
% Chrow (its composite part). ZZ4 and CH4 are used to identify the    ;
% Zstrts of the children after removal of a (Y.1)-element and the     ;
% Chrow's,respectively.If exponent>1 in (Y.exponent) the Zstrt has to ;
% be modified to obtain ZZ4, instead of a simple removal of (Y.1) from;
% from Zstrt X.                                                       ;
% Alternatives for the structure of the such a child-row are :        ;
% -1- A combination of a non-empty Zstrt and a non-empty list Chrow   ;
%     of children.                                                    ;
% -2- An empty Zstrt, but a non-empty Chrow.                          ;
% -3- A non-empty Zstrt, but an empty Chrow.                          ;
% Special attention is required when in case -3- the Zstrt consists of;
% only 1 Z-element besides the element shared with column Y.          ;
% In case -2- similar care have to be taken when Chrow consists of 1  ; 
% row index only.                                                     ;
% Remark : Since the overall intention is optimization, i.e. reduction;
% of the arithmetic complexity of a set of expressions, viewed as ru- ;
% les to perform arithmetic operations, expression parts like a*b + a ;
% are not changed into a*(b + 1). Hence a forth alternative, being an ;
% empty Zstrt and an empty Chrow is irrelevant.                       ;
% ------------------------------------------------------------------- ;
begin scalar far,ch1,ch2,ch4,chindex,zel,zeli,zz2,zz3,zz4,
                                         nsum,nprod,opv,y1,cof,x,ivalx;
  far:=car(xx);
  ch1:=chrow(far);
  zz3:=zstrt(y);
  nprod:=rowmax+1;
  nsum:=rowmax:=rowmax+2;
  % ----------------------------------------------------------------- ;
  % After some initial settings all children,accessible via the Z-el.s;
  % collected in Cdr(XX) are examined using a FOREACH_loop.           ;
  % ----------------------------------------------------------------- ;
  foreach item in cdr(xx) do
  <<x:=xind item;
    if (ivalx:=ival item)=1
     then zz4:=delyzz(y,zstrt x)
     else zz4:=inszzzr(zeli:=mkzel(y,ivalx-1),delyzz(y,zstrt x));
    ch4:=chrow(x);
    cof:=expcof(x);
    % --------------------------------------------------------------- ;
    % (Y.1) is removed from the child's Zstrt, defining a monomial,   ;
    % without the coefficient, stored in Cof.                         ;
    % --------------------------------------------------------------- ;
    if null(zz4) and (null(cdr ch4) and car(ch4))
    then
    <<% ------------------------------------------------------------- ;
      % This is the special case of possibility -2-. ZZ4 is empty and ;
      % CH4 contains only 1 index.                                    ;
      % ------------------------------------------------------------- ;
      if (opv:=opval(ch4:=car ch4)) eq 'plus and expcof(ch4)=1
      then
      <<% ----------------------------------------------------------- ;
        % The child with row-index CH4 has the form (..+..+..)^1 = ..+;
        %  ..+.. . Its definition has to be moved to the row Nsum.    ;
        % The different terms can be either primitive or composite and;
        % have all to be multiplied by Cof. Both Zstrt(CH4) - the pri-;
        % mitives - and Chrow(CH4) - the composites - have to be exa- ;
        % mined.                                                      ;
        % ----------------------------------------------------------- ;
        foreach z in zstrt(ch4) do
        <<% --------------------------------------------------------- ;
          % A new Zstrt ZZ2 is made with the primitive elements of the;
          % the different Zstrt(CH4)'s. InsZZZr guarantees summation  ;
          % of the Ival's if the Xind's are equal (see module CODMAT).;
          % ZZ2 is build using the FOREACH X loop. The Zstrt's of the ;
          % columns, which share an element with ZZ2,are also updated:;
          % The CH4-indexed elements are removed and the Nsum-indexed ;
          % elements are inserted.                                    ;
          % --------------------------------------------------------- ;
          zel:=mkzel(xind z,ival(z)*cof);
          zz2:=inszzzr(zel,zz2);
          setzstrt(yind z,inszzz(mkzel(nsum,ival zel),
                                  delyzz(ch4,zstrt yind z)))
        >>;
        foreach ch in chrow(ch4) do
        <<% --------------------------------------------------------- ;
          % The row CH defines a child directly if Cof = 1. In all    ;
          % other cases a multiplication with Cof has to be performed.;
          % Either by changing the ExpCof field if the child is a pro-;
          % duct or by introducing a new TIMES-row.                   ;
          % --------------------------------------------------------- ;
          chindex:=ch;
          if cof neq 1
           then
            if opval(ch) eq 'times
             then
              << setexpcof(ch,cof*expcof(ch));
                 setfarvar(ch,nsum)
              >>
             else
              << chindex:=rowmax:=rowmax+1;
                 setrow(chindex,'times,nsum,(ch).cof,nil)
              >>
           else  setfarvar(ch,nsum); 
          ch2:=chindex.ch2
        >>;
        % ----------------------------------------------------------- ;
        % The row CH4 is not longer needed in CODMAT, because its     ;
        % content is distributed over other rows.                     ;
        % ----------------------------------------------------------- ;
        clearrow(ch4);
      >>
      else
      <<% ----------------------------------------------------------- ;
        % This is still the special case -2-. (CH4) contains 1 child  ;
        % index. The leading operator of this child is not PLUS. So   ;
        % CH4 is simply added to the list of children indices CH2 and ;
        % the father index of row CH4 is changed into Nsum.           ;
        % ----------------------------------------------------------- ;
        setfarvar(ch4,nsum); 
        ch2:=ch4.ch2
      >>;
      % ------------------------------------------------------------- ;
      % The row X is not longer needed in CODMAT, because its content ;
      % is distributed over other rows.                               ;
      % ------------------------------------------------------------- ;
      clearrow(x)
    >>
    else
     if null(ch4) and (null(cdr zz4) and car(zz4))
      then
      <<% ----------------------------------------------------------- ;
        % This is the special case of possibility -3-: A Zstrt ZZ4    ;
        % consisting of only one Z-element.                           ;
        % This Z-element defines just a variable if IVal(Car ZZ4) =1. ;
        % It is a power of a variable in case IVal-value > 1 holds.   ;
        % In the latter situation Nsum ought to become the new father ;
        % index of the row with index Xind Car ZZ4.In the former case ;
        % the single variable is added to the Zstrt ZZ2, before row X ;
        % can be cleared.                                             ;
        % ----------------------------------------------------------- ;
        if not (ival(car(zz4)) = 1)
         then
          << setfarvar(x,nsum);
             setzstrt(x,zz4);
             ch2:=x.ch2
          >>
         else
          << zz2:=inszzzr(find!+var(farvar(y1:=yind car zz4),nsum,
                                                            cof),zz2);
             setzstrt(y1,delyzz(x,zstrt y1));
             clearrow(x)
          >>
      >>
      else
      <<% ----------------------------------------------------------- ;
        % Now the general form of one of the 3 alternatives holds.    ;
        % Row index X is added to the list of children indices CH2    ;
        % and the new father index for row X becomes Nsum. The Zstrt  ;
        % of X is also reset. It becomes ZZ4, i.e. the previous Zstrt ;
        % after removal of (Y.1).                                     ;
        % ----------------------------------------------------------- ;
        ch2:=x.ch2;
        setfarvar(x,nsum);
        setzstrt(x,zz4)
      >>;
    % --------------------------------------------------------------- ;
    % The previous "life" of X is skipped by removing its impact from ;
    % the "history book" CODMAT.                                      ;
    % --------------------------------------------------------------- ;
    ch1:=delete(x,ch1);
    zz3:=delyzz(x,zz3);
    if ivalx > 2 then zz3:=inszzz(mkzel(x,val(zeli)),zz3)
  >>;
  % ----------------------------------------------------------------- ;
  % Some final bookkeeping is needed :                                ;
  % -1- (Y.1) was deleted from the ZZ4's. Its new role, factor in the ;
  %     product,defined via the row Nprod, has still to be establish- ;
  %     ed by inserting this information in Y's Zstrt.                ;
  % ----------------------------------------------------------------- ;
  setzstrt(y,(zel:=mkzel(nprod,1)).zz3);
  % ----------------------------------------------------------------- ;
  % -2- The list of indices of children of the row with index Far     ;
  %     ought to be extended with Nprod.                              ;
  % ----------------------------------------------------------------- ;
  setchrow(far,nprod.ch1);
  % ----------------------------------------------------------------- ;
  % -3- Finally the new rows Nprod and Nsum have to be filled. How-   ;
  %     ever the :=: assignment-option might cause - otherwise non-   ;
  %     existing - problems, because simplification is skipped before ;
  %     parsing input and storing the relevant information in CODMAT. ;
  % An input expression of the form x*(a + t) + x*(a - t) can thus be ;
  % transformed - by an application of CODFAC - into the form         ;
  % x*(2*a + 0). Its Zstrt can contain an element (index  . 0), like  ;
  % the Zstrt associated with t. The latter is due to the coefficient ;
  % addition, implied by insert-operations, like InsZZZ or InsZZZr.   ;
  % Hence a test is made to discover if a Z-element Zel exists, such  ;
  % that IVal(Zel)=0. If so, its occurrence is removed from both ZZ2  ;
  % and the Zstrt of the t-column.                                    ;
  % If now Null(CH2) and Null(Cdr ZZ2) holds the PLUS-row Nsum is     ;
  % superfluous. Only 2*a*x has to be stored in Nprod. The row Nsum   ;
  % is removed when it is easily detectable, because this index is    ;
  % not used anymore and anywhere, when the above limitations are     ;
  % valid.                                                            ;
  % ----------------------------------------------------------------- ;
  foreach z in zz2 do if ival(z)=0 then
     << zz2:=delyzz(y1:=xind z,zz2);
        setzstrt(y1,delyzz(nsum,zstrt y1))
     >>;
  % ----------------------------------------------------------------- ;
  % Expressions like x(a-w)+x(a+w) lead to printable, but not yet to  ;
  % completely satisfactory prefixlist-representations. This problem  ;
  % is solved in the module CODPRI in the function  ConstrExp.        ;
  % ----------------------------------------------------------------- ;
  setrow(nprod,'times,far,list list nsum,list mkzel(y,val zel));
  setrow(nsum,'plus,nprod,list ch2,zz2)
 end;

endmodule;


module codad2;   % Facilities applied after optimization.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Authors : J.A. van Hulzen, B.J.A. Hulshof.                          ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% The module CODAD2 contains a number of facilities, to be applied    ;
% when the optimization process itself is finished and before  produ- ;
% cing output. This finishing touch, obtained by applying the function;
% PrepFinalplst (see the module CODCTL), covers the following one-row ;
% and/or one-column operations:                                       ;
%                                                                     ;
% PART 1 : Sum restructuring : s = (t1 + ... + tn) ^ exponent is re-  ;
%          placed by name := t1 + ... + tn; s:= name ^ exponent.      ;
%          Remark : This form allows application of an addition chain ;
%          algorithm on the exponent, as part of the print process,   ;
%          and as defined in the module CODPRI.                       ;
%                                                                     ;
% PART 2 : REMoval of REPeatedly occurring MULTiples of VARiables in  ;
%          linear (sub)expressions, which could not be replaced by a  ;
%          Breuer-search, since it requires one-column operations in  ;
%          the PLUS-part of CodMat. If such a multiple occurs atleast ;
%          twice, it is replaced by a new name. The TIMES-part of     ;
%          CodMat is consulted  if such a multiple is found to allow  ;
%          the replacement of such multiples in monomials as well. So ;
%          x = 3.a + b, y = 3.a + c, z = 3.a.b + c                    ;
%          is replaced by                                             ;
%          s = 3.a                                                    ;
%          x = s + b, y = s + c, z = s.b + c.                         ;
%                                                                     ;
% PART 3 : An UPDATE of MONOMIALS is performed. Constant multilpes of ;
%          identifiers are selected using the TIMES-part of CodMat.   ;
%          Since the PLUS-part is already checked with REMREPMULTVARS ;
%          the search is limited to the TIMES-part. Replacement by a  ;
%          new name is only effectuated if such a multiple literally  ;
%          occurs twice. So                                           ;
%          x = 3.a.b + 6.b.c, y = 3.a.c + 6.a.b                       ;
%          is replaced by                                             ;
%          s1 = 3.a, s2 = 6.b                                         ;
%          x = s1.b + s2.c, y = s1.c + s2.a.                          ;
%                                                                     ;
% PART 4 : An all level factoring out of gcd's of constant coeff.'s in;
%          (composite) sums, using the function CODGCD. For example   ;
%           sum = 9.a - 18.b + 6.sin(x) + 5.c -5.d                    ;
%          can be rewritten into                                      ;
%           sum = 3.(3.a - 6.b + 2.sin(x)) + 5.(c - d).               ;
%          But the arithmetic complexity of both representations of   ;
%          sum is equal. We therefore produce                         ;
%           sum = 9.a - 18.b + 6.sin(x) + 5.(c - d).                  ;
%          Regrouping of (composite) products demands for an identical;
%          algorithm. For instance                                    ;
%                   9 18   6                                          ;
%           prod = a b  sin (x)                                       ;
%          can be rewritten into                                      ;
%                               3                                     ;
%                    3 6   2                                          ;
%           prod = {a b sin (x)}                                      ;
%          thus reducing the required number of multiplications.      ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% Global identifiers needed in this module are :                      ;
% ------------------------------------------------------------------- ;

global '(rowmin rowmax);

% ------------------------------------------------------------------- ;
% The meaning of these globals is given in the module CODMAT.         ;
% ------------------------------------------------------------------- ;

symbolic smacro procedure find!+var(var,fa,iv);
getcind(var,'varlst!+,'plus,fa,iv);

symbolic smacro procedure find!*var(var,fa,iv);
getcind(var,'varlst!*,'times,fa,iv);

symbolic procedure getcind(var,varlst,op,fa,iv);
% ------------------------------------------------------------------- ;
% REMARK : GETCIND is also defined in the module CODAD1. This copy    ;
%          allows seperate compilation.                               ;
% ------------------------------------------------------------------- ;
% The purpose of the procedure GetCind is to create a column in CODMAT;
% which will be associated with the variable Var if this variable does;
% not yet belong to the set Varlst,i.e.does not yet play a role in the;
% corresponding PLUS- or TIMES setting (known by the value of Op).Once;
% the column exists (either created or already available), its Zstrt  ;
% is modified by inserting the Z-element (Fa,IV) in it. Finally the   ;
% corresponding Z-element for the father-row, i.e. (Y,IV) is returned.;
% ------------------------------------------------------------------- ;
begin scalar y,z;
  if null(y:=get(var,varlst))
  then
  <<y:=rowmin:=rowmin-1;
    put(var,varlst,y);
    setrow(y,op,var,nil,nil)
  >>;
  setzstrt(y,inszzzn(z:=mkzel(fa,iv),zstrt y));
  return mkzel(y,val z)
end;
 
% ------------------------------------------------------------------- ;
% PART 1 : SUM RESTRUCTURING                                          ;
% ------------------------------------------------------------------- ;
symbolic procedure powerofsums;
% ------------------------------------------------------------------- ;
% The CODMAT PLUS-rows are investigated, who have an ExpCof-value > 1.;
% Such rows define a sum raised to the exponent ExpCof(rowindex).     ;
% ------------------------------------------------------------------- ;
begin scalar var,z,rmax;
  rmax:=rowmax;
  for x:=0:rmax do
  if opval(x) eq 'plus and expcof(x)>1 and not farvar(x)=-1
  then
   <<var:=fnewsym();
     setrow(rowmax:=rowmax+1,'plus,var,list chrow x,zstrt x);
     % -------------------------------------------------------------- ;
     % A new name Var is introduced and 2 new CODMAT-rows to store the;
     % information about the new expression,in connection with the al-;
     % raedy available information. Furthermore some bookkeeping is   ;
     % required.                                                      ;
     % The new row above contains all the information about the sum,  ;
     % except its exponent.Below the second row is used to store Var ^;
     % ExpCof in the form of a Z-element in a TIMES-row.              ;
     % This row becomes the only child of the old sum-defining row.   ;
     % -------------------------------------------------------------- ;
     put(var,'rowindex,rowmax);
     foreach z in zstrt(x) do
      setzstrt(yind z,mkzel(rowmax,val z).delyzz(x,zstrt yind z));
     foreach ch in chrow(x) do setfarvar(ch,rowmax);
     setprev(x,rowmax); % Preserve ordening;
     setrow(rowmax:=rowmax+1,'times,x,list nil,
                            list(z:=mkzel(rowmin:=rowmin-1,expcof x)));
     % -------------------------------------------------------------- ;
     % The new row for the power of the sum is based on indirection to;
     % guarantee a correct functioning of the function Tchscheme.     ;
     % -------------------------------------------------------------- ;
     setrow(rowmin,'times,var,nil,list mkzel(rowmax,val z));
     % -------------------------------------------------------------- ;
     % A new column is generated, associated with the new name genera-;
     % ted for the sum.                                               ;
     % -------------------------------------------------------------- ;
     setchrow(x,list rowmax);
     put(var,'varlst!*,rowmin);
     setzstrt(x,nil);
     setexpcof(x,1)
   >>;
end;

% ------------------------------------------------------------------- ;
% PART 2 : REMoval of REPeatedly Occurring Constant MULTiples of PLUS ;
%          VARiableS.                                                 ;
% ------------------------------------------------------------------- ;
symbolic procedure remrepmultvars;
% ------------------------------------------------------------------- ;
% All PLUS-columns of CODMAT are investigated. Let Var be the variable;
% associated with thw column Y. A list P(lus)col(umn)inf(ormation) is ;
% made out of the Zstreet of column Y. Pcolinf consists of pairs of   ;
% the form  constant(k). list of pairs (rowindex.sign(constant(k))),  ;
% such that 0<constant(i)<constant(j) if i<j and also such that coef- ;
% ficient of Var in Zstreet(rowindex) is sign(k)*constant(k).         ;
% Then for each element of this list Pcolinf a corresponding list with;
% T(imes)col(umn)inf(ormation) is made. This is a list consisting of  ;
% pairs of the form (rowindex . Z-element with the same index as value;
% of its index-part and taken from the Zstreet of the column with the ;
% index Prod(uct)col(umn)i(ndex), whose Expcof-value is a multiple of ;
% the car of the element of Pcolinf, which is under consideration).   ;
% So assuming some multiples 3*A occur in some sums, which are easily ;
% retrievable using the corresponding element of Pcolinf, we also re- ;
% place parts of monomials of the same form. Hence 6*A^2*B is replaced;
% by 2*A*B*(cse-name for 3*A).This does not increase the multiplicati-;
% ve complexity. It can even decrease if some monomials of the form   ;
% 3*A*(something else) occur in the set of expressions currently being;
% investigated.                                                       ;
% ------------------------------------------------------------------- ;
begin
  scalar
     rmin,var,prodcoli,pcolinf,mmult,srows,tcolinf,rindx,nvar,z,zz,zz1;
  rmin:=rowmin;
  for y:=rmin:(-1) do
  % ----------------------------------------------------------------- ;
  % Analysis of Zstreets of the PLUS-columns, which are associated    ;
  % with variables Var.                                               ;
  % ----------------------------------------------------------------- ;
  if (not numberp(var:=farvar y)) and (var neq '!+one) and
                                                   (opval(y) eq 'plus)
  then
  <<prodcoli:=get(var,'varlst!*);
    pcolinf:=nil;
    foreach z in zstrt(y) do
    if abs(ival z)>1
    then pcolinf:=inspcvv(xind(z).(if ival(z)<0 then -1 else 1),
                          abs ival z,pcolinf);
    % --------------------------------------------------------------- ;
    % The function InsPCvv, defined in the module CODOPT, is used to  ;
    % produce the list Pcolinf. The NIL-initialisation is necessary   ;
    % since a fresh start is required for each column under investiga-;
    % tion. The different elements of Pcolinf are used for a closer   ;
    % look.                                                           ;
    % --------------------------------------------------------------- ;
    foreach cseinfo in pcolinf do
    <<mmult:=car(cseinfo);
      srows:=cdr(cseinfo);
      tcolinf:=nil;
      if prodcoli
      then
        foreach z in zstrt(prodcoli) do
        <<rindx:=xind(z);
          if remainder(abs expcof rindx,mmult)=0
          then tcolinf:=(rindx.z).tcolinf
        >>;
      % ------------------------------------------------------------- ;
      % The list Tcolinf is now ready.If the number of elem.s of Srows;
      % and Tcolinf together is atleast 2 the multiplicative complexi-;
      % ty is not increasing if say 3*A is replaced by cse-name.      ;
      % ------------------------------------------------------------- ;
      if length(srows)+length(tcolinf)>1
      then
       << % --------------------------------------------------------- ;
          % A new expression is made and all required bookkeeping ac- ;
          % tions are performed. So all occurrences of say 3*A are re-;
          % moved from the Zstreet of the corresponding PLUS-column, a;
          % new column to store the placeholder for this 3*A is crea- ;
          % ted and all required modifications in the affected Zstrts ;
          % are carries out.                                          ;
          % --------------------------------------------------------- ;
          z:=mkzel(y,mmult);
          nvar:=fnewsym();
          rowmax:=rowmax+1;
          setrow(rowmax,'plus,nvar,list nil,list z);
          put(nvar,'rowindex,rowmax);
          rowmin:=rowmin-1;
          zz:=nil;
          foreach rowinf in srows do
            <<rindx:=car(rowinf);
              zz:=mkzel(rindx,cdr rowinf).zz;
              setzstrt(rindx,mkzel(rowmin,val car zz).
                                              delyzz(y,zstrt rindx));
              setprev(rindx,rowmax)
            >>;
          setzstrt(y,mkzel(rowmax,val z).remzzzz(zz,zstrt y));
          setrow(rowmin,'plus,nvar,nil,zz);
          put(nvar,'varlst!+,rowmin);
          if tcolinf
           then
            << % --------------------------------------------------- ;
               % Since Tcolinf is not empty some monomials have to be;
               % modified as well.                                   ;
               % --------------------------------------------------- ;
               rowmin:=rowmin-1;
               zz1:=zz:=nil;
               foreach rowinf in tcolinf do
                 <<rindx:=car(rowinf);
                   z:=cdr(rowinf);
                   zz:=mkzel(rindx,1).zz;
                   if ival(z)>1
                    then setival(z,ival(z)-1)
                    else
                     <<zz1:=car(zz).zz1;
                       setzstrt(rindx,delyzz(prodcoli,zstrt rindx))
                     >>;
                   setzstrt(rindx,mkzel(rowmin,val car zz).
                                                       zstrt(rindx));
                   setprev(rindx,rowmax);
                   setexpcof(rindx,expcof(rindx)/mmult)
                 >>;
               setzstrt(prodcoli,remzzzz(zz1,zstrt prodcoli));
               setrow(rowmin,'times,nvar,nil,zz);
               put(nvar,'varlst!*,rowmin)
            >>
         >>
      >>
  >>
end;

% ------------------------------------------------------------------- ;
% PART 3 : An UPDATE of MONOMIALS via a TIMES-columns search.         ;
% ------------------------------------------------------------------- ;
symbolic procedure updatemonomials;
% ------------------------------------------------------------------- ;
% For each column, which is associated with an identifier, a Gclst is ;
% produced. The syntax of such a list is given in PART 4. Each element;
% of such a list, is itself a list, consisting of a constant and      ;
% structural information about the occurrences of this constant. These;
% sublists are used to deside if constant multiples can be replaced by;
% new names. The decision are made by applying the function REMGCMON. ;
% ------------------------------------------------------------------- ;
for y:=rowmin:(-1) do
if not numberp(farvar y) and opval(y) eq 'times
 then foreach gcel in mkgclstmon(y) do remgcmon(gcel,y);

symbolic procedure mkgclstmon(y);
% ------------------------------------------------------------------- ;
% All monomial coefficients of the TIMES-rows sharing an element with ;
% the current TIMES-column are grouped in a Gclst if their absolute   ;
% value is atleast 2.                                                 ;
% ------------------------------------------------------------------- ;
begin scalar gclst,cof;
  foreach z in zstrt(y) do
   if (cof:=abs expcof xind z)>1
    then gclst:=insgclst(cof,z,gclst,1);
  return gclst
end;

symbolic procedure remgcmon(gcel,y);
% ------------------------------------------------------------------- ;
% RemGcMon is recursively applied on Gcel. Its purpose is finding re- ;
% peatedly occurring multiples of idntifiers in monomials. However 6.a;
% is not considered when 3.a proves to be a cse, simply because it    ;
% does not reduce the multiplicative complexity of the set of expres- ;
% sions being optimized.                                              ;
% The srategy employed is very similar to the techniques used in PART ;
% 4.                                                                  ;
% ------------------------------------------------------------------- ;
begin scalar x,nvar,gc,zel,zzy,zzgc,ivalz;
 if length(cadr gcel)>1
  then
   << gc:=car gcel;
      rowmin:=rowmin-1; rowmax:=rowmax+1;
      nvar:=fnewsym();
      zel:=mkzel(y,1);
      setrow(rowmax,'times,nvar,list(nil,gc),list(zel));
      put(nvar,'rowindex,rowmax);
      zzy:=mkzel(rowmax,val(zel)).zstrt(y);
      zzgc:=nil;
      foreach z in cadr(gcel) do
       << x:=car(z);
          setexpcof(x,1);
          setprev(x,rowmax);
          zel:=car(pnthxzz(x,zzy));
          if ival(zel)>1
           then
            << zzy:=inszzz(mkzel(x,ivalz:=ival(zel)-1),delyzz(x,zzy));
               setzstrt(x,inszzzr(mkzel(y,ivalz),delyzz(y,zstrt x)))
            >>
           else
            << zzy:=delyzz(x,zzy);
               setzstrt(x,delyzz(y,zstrt x))
            >>;
          zzgc:=inszzz(zel:=mkzel(x,1),zzgc);
          setzstrt(x,mkzel(rowmin,val zel).zstrt(x))
       >>;
     setzstrt(y,zzy);
     setrow(rowmin,'times,nvar,nil,zzgc);
     put(nvar,'varlst!*,rowmin)
   >>;
  if cddr(gcel) then foreach item in cddr(gcel) do remgcmon(item,y)
end;

% ------------------------------------------------------------------- ;
% PART 4 : Gcd-based expression rewriting                             ;
% ------------------------------------------------------------------- ;
% We employ a two stage strategy. We start producing a Gclst, consis- ;
% ting of row-information. If relevant, Gclst is used to rewrite the  ;
% expression (part), defined by the current row of CodMat. The Gclst- ;
% syntax is :                                                         ;
%                                                                     ;
% Gclst ::= (Gcdlst  Gcdlst  ... Gcdlst ) , n >= 1 .                  ;
%                  1       2           n                              ;
% Gcdlst ::= (G Glocations glst  ... glst ) , m >= 0 .                ;
%                              1         m                            ;
% G ::= positive integer                                              ;
% Glocations ::= (location  ... location ) , k >= 0 .                 ;
%                         1             k                             ;
% location ::= (index . coeffsign)                                    ;
% coeffsign ::= +1 | -1                                               ;
% index ::= columnindex | rowindex                                    ;
% columnindex ::= negative integer (relative value, see CodMat def.)  ;
% rowindex ::= non-negative integer (relative value, see Codmat def.) ;
% glst ::= (g Glocations)                                             ;
% g ::= positive integer                                              ;
%                                                                     ;
% Semantics : We assume G = gcd(g1,...,gm) > 1. When other domains are;
% introduced, the presumed domain is not longer Z, implying that Gcd2,;
% * and / have to be made generic, when producing Gclst and rewriting ;
% the expression using the function RemGc.                            ;
% When m = 0, i.e. no glst's occur, the absolute value of all coeffi- ;
% cients is equal to G.                                               ;
% Glocations can be an empty list,as shown in the following example : ;
%                                                                     ;
% ((3 NIL (9 ((a.1))) (18 ((b.-1))) (6 ((sin(x).1))))                 ;
%  (5 ((c.1) (d.-1))))                                                ;
%                                                                     ;
% is the Gclst, associated with                                       ;
% sum = 9.a - 18.b + 6.sin(x) + 5.c - 5.d,                            ;
% when replacing the negative, relative column-indices by a,b,c and d,;
% and the positive relative child row-index by sin(x).                ;
% This list is used for the remodelling. The Glocations list is NIL,  ;
% because sum has no coefficients equal to either 3 or -3.            ;
% ------------------------------------------------------------------- ;

symbolic procedure codgcd();
begin scalar presentrowmax;
% ------------------------------------------------------------------- ;
% For all relevant rows of CodMat we compute the Gclst, by applying   ;
% the function MkGclst. Then each item in this list, a Gcdlst, is used;
% for a reconstruction of the expression( part) defined by row X.     ;
% ------------------------------------------------------------------- ;
presentrowmax:=rowmax;
for x:=0:presentrowmax do
  if not farvar(x)=-1 then foreach gcel in mkgclst(x) do remgc(gcel,x)
end;

symbolic procedure mkgclst(x);
% ------------------------------------------------------------------- ;
% The Gclst of row X is produced and returned.                        ;
% ------------------------------------------------------------------- ;
begin scalar gclst,iv,opv;
  foreach z in zstrt(x) do
   if abs(iv:=ival z)>1
    then
     % -------------------------------------------------------------- ;
     % The location (Yind(Z).coeffsign) is added to the glst with g = ;
     % abs(IV).                                                       ;
     % -------------------------------------------------------------- ;
     if iv<0
      then gclst:=insgclst(-iv,yind(z).(-1),gclst,1)
      else gclst:=insgclst(iv,yind(z) . 1,gclst,1);
  opv:=opval(x);
  foreach ch in chrow(x) do
   if not opval(ch)=opv and (iv:=expcof ch)>1
    % --------------------------------------------------------------- ;
    % Only non *(+)-children of *(+)-parents are considered.          ;
    % --------------------------------------------------------------- ;
    then
      % ------------------------------------------------------------- ;
      % The location (CH(=rowindex of child).coeffsign) is added to   ;
      % the glst with g = abs(IV).                                    ;
      % ------------------------------------------------------------- ;
      if iv<0
       then gclst:=insgclst(-iv,ch.(-1),gclst,1)
       else gclst:=insgclst(iv,ch . 1,gclst,1);
  return gclst;
end;

symbolic procedure insgclst(iv,y,gclst,gc0);
% ------------------------------------------------------------------- ;
% The most recent version of Gclst is returned after being updated by ;
% adding the location Y to the glst with g = abs(IV) in Gclst, assu-  ;
% ming that G = Gc0.                                                  ;
% ------------------------------------------------------------------- ;
begin scalar gc;
  return
    if null(gclst)
     then
      % ------------------------------------------------------------- ;
      % Start making such a list : If Y = (-1 . 1) and IV = 4 then we ;
      % get ((4 ((-1 . 1)))).                                         ;
      % ------------------------------------------------------------- ;
      list(iv.(list(y).nil))
     else
      % ------------------------------------------------------------- ;
      % Extend the Gclst.                                             ;
      % ------------------------------------------------------------- ;
      if caar(gclst)=iv
       % ------------------------------------------------------------ ;
       % Then IV = G (of Gcdlst ) and Y is added to Glocations  as new;
       %                       1                              1       ;
       % location (since Cadar(Gclst) = Glocations of Gcdlst , Cddar  ;
       %                                                    1         ;
       % (Gclst) = (glst  ... glst ) and Cdr(Gclst) = (Gcdlst  ...    ;
       %                1         m                           2       ;
       % Gcdlst )).                                                   ;
       %       n                                                      ;
       % If now IV = 4 and Y =(-2 . 1) then Gclst = ((4 ((-1 . 1))))  ;
       % is extended to ((4 ((-2 . 1) (-1 . 1)))).                    ;
       % ------------------------------------------------------------ ;
       then (iv.((y.cadar(gclst)).cddar(gclst))).(cdr gclst)
       else
        if (gc:=gcd2(iv,caar gclst))>gc0
        % ----------------------------------------------------------- ;
        % Gc = gcd(IV,G ) > Gc0 (=1, initially).                      ;
        %              1                                              ;
        % ----------------------------------------------------------- ;
         then
          if gc=caar(gclst)
           % -------------------------------------------------------- ;
           % IV > Gc = G , implying that the (IV,Y)-info has to be    ;
           %            1                                             ;
           % stored in one of the Gcdlst  lists, i > 1.               ;
           %                            i                             ;
           % So if IV=8 and Y=(-2 . 1) then Gclst = ((4 ((-1 . 1))))  ;
           % is extended to ((4 ((-1 . 1)) (8 ((-2 . 1)))).           ;
           % -------------------------------------------------------- ;
           then (append
                  (list(gc,cadar gclst),insdiff(iv,y,cddar gclst))).
                                                            (cdr gclst)
           else
            if gc=iv
            % ------------------------------------------------------- ;
            % Gc = IV < G  demands for remodelling of Gcdlst , such   ;
            %            1                                  1         ;
            % that now Gcdlst  = (Gc Etc).So if IV = 2 and Y =(-2 . 1);
            %                1                                        ;
            % then Gclst = ((4 ((-1 . 1)))) is extended to the list   ;
            % ((2 ((-2 . 1)) (4 ((-1 . 1))))).                        ;
            % ------------------------------------------------------- ;
             then <<if caddar(gclst) 
                     then (append(list(gc,list(y),list(caar gclst,
                             cadar gclst)),cddar gclst)).(cdr gclst)
                     else (gc.(list(y).list(car gclst))).(cdr gclst)>>
             else
             % ------------------------------------------------------ ;
             % Gc < IV and Gc < G , i.e. Glocations := NIL. So if IV =;
             %                   1                 1                  ;
             % 6 and Y = (-2 . 1) then Gclst = ((4 (-1 . 1)))0 is ex- ;
             % tended to ((2 NIL (6 ((-2 . 1))) (4 ((-1 . 1))))).     ;
             % ------------------------------------------------------ ;
               (gc.(nil.append(list(iv.(list(y).nil)),
                    if cddar gclst 
                     then append(list(list(caar gclst,cadar gclst)),
                                                           cddar gclst)
                     else list(list(caar gclst,cadar gclst)))))
                     .(cdr gclst)
         else
         % ---------------------------------------------------------- ;
         % IV and G  are relative prime. The elements Gcdlst , i > 1, ;
         %                                                  i         ;
         % are further investigated, if existing.                     ;
         % So if IV = 5 and Y = (-2 . 1) then Gclst = ((4 (-1 . 1)))) ;
         % is extended to ((4 ((-1 . 1))) (5 ((-2 . 1))))).           ;
         % ---------------------------------------------------------- ;
          car(gclst).insgclst(iv,y,cdr gclst,gc0);
end;

symbolic procedure insdiff(iv,y,glsts);
% ------------------------------------------------------------------- ;
% glstst is a list of glst 's, i >= 0. If IV = g , k<= i, then Y is   ;
%                         i                     k                     ;
% inserted in glocations  and else list(IV.(list(Y).NIL)) is added to ;
%                       k                                             ;
% glsts.                                                              ;
% ------------------------------------------------------------------- ;
begin scalar b,rlst;
 while glsts and (not b) do
  << if caar(glsts)=iv 
      then <<rlst:=list(iv,append(list(y),cadar glsts)).rlst;
             b:=t >>
      else rlst:=car(glsts).rlst;
     glsts:=cdr(glsts)
  >>;
 return if b 
         then append(reverse(rlst),glsts)
         else append(list(iv.(list(y).nil)),reverse(rlst))
end;


symbolic procedure remgc(gcel,x);
% ------------------------------------------------------------------- ;
% RemGc allows a recursive investigation of Gcel, a Gcdlst being an   ;
% element of the Gclst of row X. Therefore it returns a list of loca- ;
% tions, which can be empty as well. These locations are remodelled   ;
% into Zstrt-elements, subject to some profitability criteria, which  ;
% will be explained in the body of this function.                     ;
% Once the list of remodelled locations is ready, it is used to re-   ;
% arrange the corresponding CodMat-elements into the desired form.    ;
% ------------------------------------------------------------------- ;
begin scalar zzch,zzchl,zzr,chr,zz,ch,nsum,nprod,ns,np,opv,gc,cof,
                                                   cofloc,iv,var1,var2;
  % ----------------------------------------------------------------- ;
  % Gcel is a Gcdlst, i.e. it has the structure (G Glocations glst's).;
  % So Cddr(Gcel) = (glsts's) =(glst  ... glst ), m>= 0. A glst itself;
  %                                 1         m                       ;
  % has the structure (g Glocations), i.e. Cddr(glst) = NIL.          ;
  % Hence Gcel is either a Gcdlst or a glst. For both alternatives    ;
  % holds : Car(Gcel) = a positive integer (G or g) and Cadr(Gcel) =  ;
  % a Glocations-list, i.e. each element of Cadr(Gcel) ia a pair      ;
  % (index.coeffsign), where Car(Gcel) is the absolute value of the   ;
  % coefficient (exponent) to be associated with row X and a column-  ;
  % index or the row-index of a child, respectively.                  ;
  % If Gcel defines the structure of a monomial the description is im-;
  % proved if atleast 2 exponents are G or if the exponents have a gcd;
  %               6 6      6 9                         2 3 3          ;
  % > 1. So both a b  and a b  are restructured into (a b )  and      ;
  %     6                                                             ;
  % (ab) , respectively.                                              ;
  % If Gcel defines the structure of a sum coefficients are factored  ;
  % out (recursively), i.e. 6.a + 9.b remains unchanged and 6.a + 6.b ;
  % is restructured into 6.(a + b). The Gcel is (3 NIL (6 ((a.1)))    ;
  % (9 ((b.1)))) and (6 ((a.1) (b.1))), respectively.                 ;
  % Restructuring requires a new TIMES(PLUS)-row to store the EXPCOF  ;
  % value GC (6) and a new PLUS(TIMES)-row to store its base ab or    ;
  % factor a + b, respectively.                                       ;
  % ----------------------------------------------------------------- ;
  if ((opv:=opval(x)) eq 'times and
     (length(cadr gcel)>1 or cddr(gcel))) or
     ((opv eq 'plus) and (length(cadr gcel)>1))
  then
   <<if opv eq 'times
      then
       << nsum:=rowmax:=rowmax+1;
          var1:=fnewsym();
          put(var1,'rowindex,nsum);
          setprev(x,nsum);
          setrow(rowmin:=rowmin-1,'times,var1,nil,
                                      list(iv:=mkzel(x,gc:=car gcel)));
          setzstrt(x,inszzzr(mkzel(rowmin,val iv),zstrt x));
          put(var1,'varlst!*,rowmin);
          setrow(nsum,'times,var1,list nil,nil)
       >>
     else
       << nprod:=rowmax+1; nsum:=rowmax:=rowmax+2;
          setchrow(x,nprod.chrow(x));
          setrow(nprod,if opv eq 'plus then 'times else 'plus,x,
                                    list(list(nsum),gc:=car gcel),nil);
          setrow(nsum,opv,nprod,list nil,nil)
       >>;
     zzch:=updaterowinf(x,nsum,1,cadr gcel,zzr,chr);
     foreach y in cddr gcel do
      <<cof:=car(y)/gc; cofloc:=cadr y;
        if cdr cofloc
         then
          << if opv eq 'plus
              then
               << np:=rowmax+1; ns:=rowmax:=rowmax+2;
                  setrow(np,if opv eq 'plus then 'times else 'plus,
                                          nsum,list(list(ns),cof),nil);
                  setrow(ns,opv,np,list nil,nil);
                  setchrow(nsum,np.chrow(nsum))
               >>
              else
               << ns:=rowmax:=rowmax+1;
                  var2:=fnewsym();
                  put(var2,'rowindex,ns);
                  setprev(var1,ns);
                  setrow(rowmin:=rowmin-1,'times,var2,nil,
                                             list(iv:=mkzel(nsum,cof)));
                  setzstrt(nsum,inszzzr(mkzel(rowmin,val iv),
                           zstrt nsum));
                  put(var2,'varlst!*,rowmin);
                  setrow(ns,'times,var2,list nil,nil)
               >>;
            zz:=ch:=nil;
            zzchl:=updaterowinf(x,ns,1,cofloc,zz,ch);
            setzstrt(ns,car zzchl);
            setchrow(ns,cdr zzchl)
          >>
         else
          zzch:=updaterowinf(x,nsum,cof,cofloc,car zzch,cdr zzch)
      >>;
     setzstrt(nsum,car zzch);
     setchrow(nsum,if chrow(nsum) then append(chrow(nsum),cdr zzch)
                                  else cdr zzch)
  >>
else 
 foreach item in cddr gcel do remgc(item,x)
end;


symbolic procedure updaterowinf(x,nrow,cof,infolst,zz,ch);
% ------------------------------------------------------------------- ;
% UpdateRowInf is used in the function RemGc to construct the Zstrt   ;
% ZZ and the list of children CH of row Nrow and using the Infol(i)st.;
% Infolst is a glst.                                                  ;
% ------------------------------------------------------------------- ;
begin scalar indx,iv;
 foreach item in infolst do
  << indx:=car(item);
     if indx < 0
      then
       << zz:=inszzzr(iv:=mkzel(indx,cof*cdr(item)),zz);
          setzstrt(indx,inszzz(mkzel(nrow,val(iv)),
                                               delyzz(x,zstrt indx)));
          setzstrt(x,delyzz(indx,zstrt x))
       >>
      else
       << ch:=indx.ch;
          chdel(x,indx);
          setfarvar(indx,nrow);
          setexpcof(indx,cof)
       >>
  >>;
 return zz.ch
 end;

endmodule;


module codpri;  % Support for visualizing output.

% -------------------------------------------------------------------- ;
% Copyright : J.A. Van Hulzen, Twente University, Dept. of Computer    ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands. ;
% Authors :   J.A. van Hulzen, B.J.A. Hulshof, M.C. van Heerwaarden.   ;
% -------------------------------------------------------------------- ;

% -------------------------------------------------------------------- ;
% The module CODPRI consists of three parts:                           ;
%  1 - Facilities to vizualize the data structures on user request,i.e.;
%      when ON PRIMAT or ON PRIALL is set(see CODCTL.RED).             ;
%  2 - Routines for constructing PREFIXLIST. The value of this variable;
%      is an association list,consisting of pairs (name.value),where   ;
%      name is the (sub)expression name and where value stands for the ;
%      prefixform of the corresponding (sub)expression. Its construc-  ;
%      tion is activated via the procedure MAKEPREFIXL used in OPTIMIZE;
%      directly or via the route MANAGEOUTPUT -> PRIRESULT(see the     ;
%      module CODCTL).                                                 ;
%  3 - Functions for improving the final layout of the output. These   ;
%      functions are applied on the final form of Codmat before the    ;
%      preparations for the printing process start.Calling the function;
%      ImproveFinalLayout suffices.                                    ;
% -------------------------------------------------------------------- ;

% -------------------------------------------------------------------- ;
% Global identifiers needed in this module are :                       ;
% -------------------------------------------------------------------- ;

global '(codbexl!* rowmax rowmin lintlst kvarlst endmat)$

% -------------------------------------------------------------------- ;
% LINTLST is a list of integers which are too long to be included in   ;
% the schemes directly.LINTLST is built up in the procedure PRINUMB and;
% used in the procedure PRISCHEME via the procedure PRILINT.           ;
% The globals ROWMAX,ROWMIN and ENDMAT are defined in CODCTL.RED. The  ;
% global KVARLST is introduced in CODMAT.RED.                          ;
% -------------------------------------------------------------------- ;

% -------------------------------------------------------------------- ;
% PART 1 : PROCEDURES FOR VIZUALIZING THE DATA STRUCTURES              ;
% -------------------------------------------------------------------- ;
% These print facilities are mainly designed as debugging tool.They are;
% usable via an ON PRIMAT or an ON PRIALL setting.The governing routine;
% is PRIMAT,called in the procedure OPTIMIZE (used in both CALC and    ;
% HUGE) to vizualize the result of parsing a set of input expressions  ;
% and in OPTIMIZE (ON CRUNCH) or MANAGEOUTPUT (OFF CRUNCH) to show the ;
% result of optimizing this set.                                       ;
% In PRIMAT the linelength is temporarily reset to 120,thus limiting   ;
% the size of the matrix schemes produced by PRISCHEME('PLUS) and      ;
% PRISCHEME('TIMES) in PRIMAT.                                         ;
% In PRISCHEME(Operator) a message is generated when the linelength is ;
% not sufficient telling that printing is impossible.In all other cases;
% the procedure PRISCHEME produces a compact version of reality.It uses;
% the routines PRI(nt)NUMB(er),PRI(nt)ROW,PRI(nt)VAR(iable) and PRI(nt);
% L(ong)INT(eger). The procedures TESTPROW and MEMPQ are used for test-;
% ing details in PRISCHEME and PRIROW,resp. To simplify explaining the ;
% code we give a simple example :                                      ;
%                                                                      ;
% Assume we have :                                                     ;
%                                       8  2                   8       ;
% U := ((A + 2*B)*SIN(A + 2*B)*A*B + 2*A *B  + 2*A + 4*B - 677)  + 1234;
%                                                                      ;
% Then PRIMAT produces via PRISCHEME :                                 ;
%                                                                      ;
% Sumscheme :                                                          ;
%                                                                      ;
%    |  3  4  5| EC|Far                                                ;
% ---------------------                                                ;
%   0|        X|  1| U                                                 ;
%   2|  2  4  X|  8| 1                                                 ;
%   4|  1  2   |  1! 3                                                 ;
%   5|  1  2   |  1| S0                                                ;
% ---------------------                                                ;
% The following integers ought to replace the X-entries of the matrix  ;
% in a left-to-right-and-top-down order : 1234  -677                   ;
% 3 : A                                                                ;
% 4 : B                                                                ;
% 5 : +ONE                                                             ;
%                                                                      ;
% Productscheme :                                                      ;
%                                                                      ;
%    |  0  1  2| EC|Far                                                ;
% ---------------------                                                ;
%   1|         |  1| 0                                                 ;
%   3|  1  1  1|  1| 2                                                 ;
%   6|     8  2|  2| 2                                                 ;
% ---------------------                                                ;
% 0 : S1=SIN(S0)                                                       ;
% 1 : A                                                                ;
% 2 : B                                                                ;
%                                                                      ;
% If Far has a name (U,S0) as value its row defines the prim.part of   ;
% the expression assigned to this name.Its composite parts can be found;
% in those rows of the other scheme,which have the index of the present;
% row in their Far-field( i.e. their father). The EC-field shows the   ;
% E(xponent of a sum) or the C(oefficient of a product).               ;
% The column numbers in the schemes correspondent with the CODMAT co-  ;
% lumn indices. These numbers are used to give a (vertical) list of    ;
% pairs (number : varname),where varname is either a variable name,the ;
% special symbol !+ONE( for the constants in a sum) or an assignment   ;
% like S1=SIN(S0),indicating that function applications are replaced by;
% system selected names.                                               ;
% When exponents or coefficients are too long to be printed,i.e. when  ;
% entry>999 or when entry<-99 an X is printed instead. A sequence of   ;
% integers corresponding with these X's in the scheme is given directly;
% below it in a left-to-right-and-top-down order. Hence :              ;
%                                                                      ;
% U     := 1234 + prod1(= product defined in row 1)                    ;
% prod1 := 1 * sum2(= sum defined in row 2)                            ;
% sum2  := (2*A + 4*B -677 + prod3 + prod6)^8                          ;
% prod3 := S1 * A * B * sum4                                           ;
% sum4  := A + 2*B                                                     ;
% S1    := SIN(S0)                                                     ;
% S0    := A + 2*B                                                     ;
% prod6 := 2 * A^8 * B^2                                               ;
% -------------------------------------------------------------------- ;

symbolic smacro procedure testprow(y,opv);
% -------------------------------------------------------------------- ;
% arg : Column index Y. Operator value Opv.                            ;
% res : T if the column Y is part of the Opv-scheme,NIL otherwise.     ;
% -------------------------------------------------------------------- ;
free(y) and opval(y) eq opv;


symbolic procedure primat;
% -------------------------------------------------------------------- ;
% res : A reflection is produced of the state of the matrix CODMAT     ;
% -------------------------------------------------------------------- ;
begin scalar l;
  l:=linelength(nil);
  linelength(120);
  terpri();
  prin2 "Sumscheme :";
  prischeme('plus);
  terpri();
  terpri();
  terpri();
  prin2 "Productscheme :";
  prischeme('times);
  linelength(l);
end;

% -------------------------------------------------------------------- ;
% The procedure Primat1 can be used for testing new features.          ;
% -------------------------------------------------------------------- ;
global '(freevec freetest)$
freetest:=nil;

symbolic procedure primat1;
begin scalar freevec1,rmin,rmax; 
 rmin:=rowmin; rmax:=rowmax;
 if null freetest or freetest<maxvar
  then <<freetest:=maxvar;
         freevec1:=mkvect(2*maxvar);
         freevec:=freevec1
       >>;
 for j:=rmin:rmax do <<putv(freevec,j+maxvar,free(j));setfree(j)>>;
 primat();
 for j:=rmin:rmax do
  << if not getv(freevec,j+maxvar) then setoccup(j);
     terpri();
     if j<0 then write "col(",j,")=",getv(codmat,maxvar+j)
     else write "row(",j,")=",getv(codmat,maxvar+j)
  >>;
 terpri()
end;
 
symbolic procedure prischeme(opv);
% -------------------------------------------------------------------- ;
% arg : The value of Opv is either 'TIMES or 'PLUS.                    ;
% eff : The Opv-scheme is printed                                      ;
% -------------------------------------------------------------------- ;
begin scalar n,yl;
  n:=0;
  lintlst:=nil;
  terpri();
  terpri();
  prin2 "   |";
  for y:=rowmin:(-1) do
  if testprow(y,opv)
  then <<prinumb(y+abs(rowmin)); yl:=y.yl; n:=n+1>>;
  prin2 "| EC|Far";
  terpri();
  n:=3*n+12;
  if n>120 then <<prin2 "Scheme to large to be printed"; return>>;
  for j:=1:n do prin2 "-";
  yl:=reverse(yl);
  for x:=0:rowmax do
  if testprow(x,opv)
  then prirow(x,opv,yl);
  terpri();
  for j:=1:n do prin2 "-";
  prilint();
  terpri();
  for y:=rowmin:(-1) do
  if testprow(y,opv)
  then
  <<prin2(yl:=y+abs(rowmin));
    if yl < 10 then prin2 "  : " else prin2 " : ";
    privar(farvar y);
    if n:=assoc(farvar y,kvarlst)
    then <<prin2 "="; privar(cdr n)>>;
    terpri()
  >>;
end;

symbolic procedure prirow(x,opv,yl);
% -------------------------------------------------------------------- ;
% arg : Index X of a row of the Opv-scheme. Y1 is the list of column   ;
%       indices which occur in the Opv-scheme.                         ;
% eff : Row X of the Opv-scheme is printed in the above discussed way. ;
% -------------------------------------------------------------------- ;
begin
  terpri();
  prinumb(x);
  prin2 "|";
  foreach z in zstrt(x) do
  if testprow(yind z,opv)
  then
  <<yl:=memqp(yind z,yl);
    prinumb(ival z)>>;
  for j:=1:length(yl) do prin2 "   ";
  prin2 "|";
  prinumb(expcof x);
  prin2 "| ";
  privar(farvar x);
end;

symbolic procedure memqp(y,yl);
% -------------------------------------------------------------------- ;
% arg : Y is the index of the column of which the exponent/coefficient ;
%       of the corresponding variable has to be printed. Y1 is the list;
%       of indices of columns which can also contribute to the row     ;
%       which is now in the process of being printed.                  ;
% eff : If Y=Car(Y1) the calling routine,PRIROW,can continue its prin- ;
%       ting activities directly with the exp./coeff. in question. If  ;
%       not we have to print blanks to indicate that the column and row;
%       have nothing in common. We continue with the Cdr of the list Y1;
% -------------------------------------------------------------------- ;
if y=car(yl)
then cdr(yl)
else
<<prin2 "   ";
  memqp(y,cdr yl)>>;

symbolic procedure prinumb(n);
% -------------------------------------------------------------------- ;
% arg : An integer N.                                                  ;
% eff : N is printed using atmost three positions if possible.In case  ;
%       the size of the integer is to large we print "  X" and add N to;
%       then list LINTLST of long integers,which are printed once the  ;
%       the scheme is completed.                                       ;
% -------------------------------------------------------------------- ;
<<if minusp(n)
  then
    (if n>-10
     then prin2 " "
     else
      if n<=-100
      then <<lintlst:=n.lintlst; n:="  X">>)
  else
   (if n<10
    then prin2 "  "
    else
      if n<100
      then prin2 " "
      else
        if n>=1000
        then <<lintlst:=n.lintlst; n:="  X">>);
  prin2 n;
>>;

symbolic procedure prilint;
% -------------------------------------------------------------------- ;
% eff : The list of "long" integers LINTLST,produced in the procedure  ;
%       PRINUMB,is printed.                                            ;
% -------------------------------------------------------------------- ;
if lintlst
then
<<terpri();
  prin2
  "The following integers ought to replace the X-entries of the matrix";
  terpri();
  prin2 "in a left-to-right-and top-down order : ";
  foreach n in reverse(lintlst) do <<prin2 n; prin2 "  ">>;
>>;

symbolic procedure privar(var);
% -------------------------------------------------------------------- ;
% arg : The template VAR  for a variable,a list defining a kernel in   ;
%       prefix notation,i.e.(a b c) in stead of a(b,c) or a constant.  ;
% eff : VAR is printed.                                                ;
% -------------------------------------------------------------------- ;
if atom(var)
then prin2 var
else
<<prin2(car var);
  prin2 "(";
  var:=cdr var;
  while var do
  <<prin2(car var);
   if var:=cdr(var) then prin2 ",">>;
  prin2 ")";
>>;

 
% -------------------------------------------------------------------- ;
% PART 2 : PRODUCTION OF PREFIXLIST - THE FINAL RESULT                 ;
% -------------------------------------------------------------------- ;
% Given :                                                              ;
%                                       8  2                   8       ;
% U := ((A + 2*B)*SIN(A + 2*B)*A*B + 2*A *B  + 2*A + 4*B - 677)  + 1234;
%                                                                      ;
% The optimizer produces the sequence of assignment statements :       ;
%                                                                      ;
%    S0 := A + 2*B                                                     ;
%    S1 := SIN(S0)                                                     ;
%    S3 := A*B                                                         ;
%    S9 := A*A                                                         ;
%    S8 := A*S9                                                        ;
%    S7 := S8*S8                                                       ;
%    S5 := 2*S0 - 677 + S3*(S0*S1 + 2*S3*S7)                           ;
%    S9 := S5*S5                                                       ;
%    S8 := S9*S9                                                       ;
%    S6 := S8*S8                                                       ;
%    U := 1234 + S6                                                    ;
%                                                                      ;
% The above given REDUCE infix notation can be replaced by FORTRAN or a;
% prefix form. This depends on the current flag settings. But for prin-;
% ting we always use the value of PREFIXLIST,which is in this particu- ;
% lar case :                                                           ;
%                                                                      ;
%   ((S0 PLUS A (TIMES 2 B))                                           ;
%    (S1 SIN S0)                                                       ;
%    (S3 TIMES A B)                                                    ;
%    (S9 TIMES A A)                                                    ;
%    (S8 TIMES A S9)                                                   ;
%    (S7 TIMES S8 S8)                                                  ;
%    (S5                                                               ;
%       PLUS                                                           ;
%       (TIMES 2 S0)                                                   ;
%       (MINUS 677)                                                    ;
%       (TIMES S3 (PLUS (TIMES S0 S1) (TIMES 2 S3 S7))))               ;
%    (S9 TIMES S5 S5)                                                  ;
%    (S8 TIMES S9 S9)                                                  ;
%    (S6 TIMES S8 S8)                                                  ;
%    (U PLUS 1234 (TIMES S6)))                                         ;
%                                                                      ;
% PREFIXLIST is iteratively constructed by the procedure MAKEPREFIXL   ;
% (see CODCTL.RED),by successively using the items of the (global) list;
% CodBexl!* via a ForEach-statement. Such an item is either an index of;
% a row,where the description of the corresponding assignment statement;
% starts(in the above example U) or of a system generated cse-name.    ;
% These alternatives demand for either a call of PRFEXP(rowindex) or of;
% PRFKVAR(cse-name).The routines PR(epare pre)F(ix form of an )EXP(res-;
% sion) and PR(epare pre)F(ix form of an element of)KVAR(lst) call each;
% other and the procedures CONSTR(uct an)EXP(ression),PR(epare the list;
% of operands in pre)F(ix form of the pri)M(.part of an)EX(pression),  ;
% (prepare the list of operands in prefix form of the)COMP(osite part  ;
% of an)EX(pression) and PR(epare in pre)F(ix form a redefinition of a);
% POW(er into a)L(ist of multiplications(i.d. an addition chain mecha- ;
% nism)). The last routine uses the additional procedures PREPPOWLS    ;
% and INSEXPLST. For further comment : see below.                      ;
% -------------------------------------------------------------------- ;

global '(!*crunch !*prefix !*again anop!* prefixlist )$
prefixlist:=nil;

% -------------------------------------------------------------------- ;
% These globals are already introduced in CODCTL.RED.                  ;
% -------------------------------------------------------------------- ;

symbolic procedure prfexp(x);
% -------------------------------------------------------------------- ;
% arg : X is the CODMAT-index of the row where the description of a top;
%       level sum or product starts.                                   ;
% eff : The prefix definition of this expression ,a dotted pair (name. ;
%       value) is added to PREFIXLIST,in combination with all its cse's;
%       which have to precede the expression when printing the result. ;
%       Since "consing" is used for the construction of PREFIXLIST it  ;
%       ought to be reversed before it can be used for the actual prin-;
%       ting.The cse-ordering is defined by the value of the ORDR-field;
%       of row X of CODMAT,a list built up during input parsing (see   ;
%       CODMAT.RED) and optimization(see CODOPT.RED) using the procedu-;
%       re SETPREV(see CODMAT.RED,part 2).                             ;
% -------------------------------------------------------------------- ;
begin scalar xx,nex;
 if free(x)
 then % Start with cse's.;
 <<foreach y in reverse(ordr x) do
   if numberp(y)
   then prfexp(y)
   else
   <<prfkvar(y);
     if get(y,'nvarlst) 
     then <<prfpowl(y); remprop(y,'nvarlst)>>
   >>;
    % ---------------------------------------------------------------- ;
    % Continue with expression itself if it has not yet been printed as;
    % part of an addition chain ('Bexl:=T,see PREPPOWLS).              ;
    % ---------------------------------------------------------------- ;
   if not get(farvar x,'bexl)
    then if nex:=get(farvar x,'nex)
          then << foreach arg in cdr nex do
                   if xx := get(arg, 'rowindex)
                     then prfexp xx
                     else prfkvar arg;
                  remprop(farvar x,'nex);
                  prefixlist:=(nex.constrexp(x)).prefixlist;
                  symtabrem(nil, farvar x)
               >>
          else prefixlist:=(farvar(x).constrexp(x)).prefixlist
     else remprop(farvar x,'bexl);
   setoccup(x)
 >>;
end;
 
symbolic procedure constrexp(x);
% -------------------------------------------------------------------- ;
% arg : X is the CODMAT-index of the row where the description starts  ;
%       of the expression to be added to PREFIXLIST.                   ;
% res : Construction of the expression in prefix form. The result is   ;
%       used in PRFEXP.                                                ;
% -------------------------------------------------------------------- ;
begin scalar s,ec,opv,ch,ls;
  if (opv:=opval x) eq 'times
  then
  <<s:=append(prfmex(zstrt x,'times),compex chrow x);
    if null(s) then s:=list 0;
    ec:=expcof(x);ls:=length(s);
    if ec=1
     then if ls>1 then s:='times.s else s:=car(s)
     else
       if ec=-1
        then s:=(if ls>1 then list('minus,'times.s)
                                              else list('minus,car s))
        else
         if minusp(ec)
          then s:=list('minus,'times.((-ec).s))
          else s:='times.(ec.s)
  >>
  else
    if opv eq 'plus
    then
    <<s:=append(prfmex(zstrt x,'plus),compex chrow x);
      if null(s) then s:=list 0;
      if length(s)>1 then s:='plus.shiftminus(s) else s:=car(s);
      if (ec:=expcof(x))>1 then s:=list('expt,s,ec)
    >>
    else
    <<ch:=chrow(x);
      foreach z in zstrt(x) do
      if null(z)
      then <<s:=constrexp(car ch).s; ch:=cdr(ch)>>
      else s:=z.s;
      s:=car(opv).reverse(s);
      foreach op in cdr(opv) do
      s:=list(op,s);
      if (ec:=expcof x)>1
      then s:=list('expt,s,ec)
    >>;
  return s
end;

symbolic procedure shiftminus(s);
begin scalar ts,head;
 ts:=s; head:=nil;
 while ts and (pairp(car ts) and caar(ts) eq 'minus) do
  << head:=car(ts).head; ts:=cdr ts>>;
 return if ts then append(ts,reverse head) else s
end;

symbolic procedure prfmex(zz,op);
% -------------------------------------------------------------------- ;
% arg : ZZ is a Zstrt and Op an element of {'PLUS,'TIMES}.             ;
% res : List of operands in prefix form,i.e. a list of multiples or a  ;
%       list of powers of variables.                                   ;
% -------------------------------------------------------------------- ;
foreach z in zz collect
begin scalar var,nex;
  var:=farvar(yind z);
  if nex:=get(var,'nex) then << var:=nex; symtabrem(nil,var)>>;
  if var eq '!+one
  then % A constant.;
    if ival(z)<0
    then return list('minus,-ival(z))
    else return ival(z);
  if abs(ival z)>1
  then
    if op eq 'plus
    then var:=list('times,abs ival z,var)
    else
      if bval(z)
      then var:=bval(z)
      else var:=list('expt,var,ival z);
  if minusp(ival z)
  then var:=list('minus,var);
  return var;
end;

symbolic procedure compex(chr);
% -------------------------------------------------------------------- ;
% arg : Chr is a list of indices of rows where the description starts  ;
%       of (sub)expressions,being composite terms or factors.          ;
% res : A list of these (sub)expressions in prefix form.               ;
% -------------------------------------------------------------------- ;
foreach ch in chr collect
constrexp(ch);

symbolic procedure prfkvar(kv);
% -------------------------------------------------------------------- ;
% arg : Kv is the Car-part of an element (Var.F) of the Kvarlst,where F;
%       is a list of the form (function-name (list of arguments)),if   ;
%       not already added to PREFIXLIST                                ;
% eff : The occurence of Kv in Kvarlst is tested. If Kv is still there ;
%       the corresponding dotted pair is used for extending PREFIXLIST ;
%       before it is removed from Kvarlst.                             ;
% -------------------------------------------------------------------- ;
begin scalar kvl,x,kvl1,nex;
  while kvarlst and not (kv=caar(kvarlst)) do
  <<kvl:=car(kvarlst).kvl;
    kvarlst:=cdr(kvarlst)
  >>;
  if null(kvarlst)
  then 
  <<% KVar already printed;
    kvarlst:=kvl;
  >>
  else
  <<kvl1:=car(kvarlst);
    kvarlst:=append(kvl,cdr kvarlst);
     % Restore Kvarlst before next recursive check;
    foreach var in cddr(kvl1) do
    % ---------------------------------------------------------------- ;
    % Add argument description,if composite,to Prefixlist before func. ;
    % application itself.                                              ;
    % ---------------------------------------------------------------- ;
    if x:=get(var,'rowindex) then prfexp(x) else prfkvar(var);  
    if nex:=get(kv,'nex)
     then << for each arg in cdr nex do
               if x:=get(arg,'rowindex) then prfexp x else prfkvar arg;
            symtabrem(nil, kv);
            % -------------------------------------------------------- ;
            % Otherwise, this further non-used temporary variable will ;
            % also be declared.                                        ;
            % -------------------------------------------------------- ;
            kv := nex
         >>;
    prefixlist:=(kv.cdr(kvl1)).prefixlist;
  >>
end;

% -------------------------------------------------------------------- ;
% COMPUTATION RULES FOR POWERS : AN ADDITION CHAIN MECHANISM           ;
%                                                                      ;
% The above given Optimizer output contains the following subsequences ;
%  ................                                                    ;
%  S9 := A * A          A ^ 2   ( 2 = 1 + 1 )                          ;
%  S8 := A * S9         A ^ 3   ( 3 = 2 + 1 )                          ;
%  S7 := S8 * S8        A ^ 6   ( 6 = 3 + 3 )                          ;
%  ................                                                    ;
%  S9 := S5 * S5       S5 ^ 2   ( 2 = 1 + 1 )                          ;
%  S8 := S9 * S9       S5 ^ 4   ( 4 = 2 + 2 )    S9 is re used         ;
%  S6 := S8 * S8       S5 ^ 8   ( 8 = 4 + 4 )    S8 is re used         ;
%                                                                      ;
% Printing a view on CODMAT (after the above given output is produced) ;
% using the procedure PRIMAT (see part 1 of this module) shows:        ;
%                                                                      ;
%  Sumscheme :                                                         ;
%                                                                      ;
%     |  7 11 12 13| EC|Far                                            ;
%  ------------------------                                            ;
%    0|          X |  1| U                                             ;
%    5|     1  2   |  1| S0                                            ;
%   10|            |  1| 9                                             ;
%   12|  2       X |  1| S5                                            ;
%  ------------------------                                            ;
%  The following integers ought tp replace the X-entries of the matrix ;
%  in a left-to-right-and-top-down order : 1234  -677                  ;
%  7  : S0                                                             ;
%  11 : A                                                              ;
%  12 : B                                                              ;
%  13 : +ONE                                                           ;
%                                                                      ;
%  Productscheme :                                                     ;
%                                                                      ;
%     |  1  3  4  8  9 10| EC|Far                                      ;
%  ------------------------------                                      ;
%    1|  8               |  1| 0                                       ;
%    3|     1     1      |  1| 10                                      ;
%    6|        1     6   |  2| 10                                      ;
%    8|              1  1|  1| S3                                      ;
%    9|        1         |  1| 12                                      ;
%  ------------------------------                                      ;
%  1  : S5                                                             ;
%  3  : S0                                                             ;
%  4  : S3                                                             ;
%  8  : S1=SIN(S0)                                                     ;
%  9  : A                                                              ;
%  10 : B                                                              ;
%                                                                      ;
% S5 ^ 8 and A ^ 6 are still there,in contrast to S6,S7,S8 and S9, be- ;
% cause the latter group is produced in a different way. S6 and S7 are ;
% generated via PREPPOWLS,called in PREPFINALPLST(see CODCTL.RED),acti-;
% vated in MAKEPREFIXL,assuming OFF CRUNCH or OFF AGAIN holds.         ;
% In PREPPOWLS the Nvarlst's ((8.S6)(1.S5)) and ((6.S7)(1.A)) are made ;
% and via their property lists associated with S5 and A,respectively.  ;
% These lists are used in PRFPOWL to produce the above given chains.   ;
% The addition chain-like algorithm used is reflected by the structure ;
% of PRFPOWL : Given a list of at least two exponents(integers),being  ;
% the Car's of the elements of Nvarlst,produce an intuitively minimal  ;
% number of additions by halving even numbers and by making odd numbers;
% even by substracting 1. Hence (63 1) leads to :                      ;
% 63=62+1,62=31+31,31=30+1,30=15+15,15=14+1,14=7+7,7=6+1,6=3+3,3=2+1,  ;
% 2=1+1. Since the Nvarlst might be longer,for instance (63 28 15 1),  ;
% PRFPOWL allows a more general approach,which for example leads to :  ;
% 63=62+1,62=31+31,31=28+3,28=15+13,15=13+2,13=12+1,12=6+6,6=3+3,3=2+1,;
% 2=1+1.                                                               ;
% -------------------------------------------------------------------- ;

symbolic procedure preppowls;
% -------------------------------------------------------------------- ;
% eff : This procedure is called before the actual printing starts,i.e.;
%       before PREFIXLIST is made. This allows to refer to results     ;
%       produced by this routine in PRFEXP at two different places. The;
%       value of the indicators 'Nvarlst(i.e. exists such a list?) and ;
%       'Bexl(=T if the corresponding (sub)expression name is part of a;
%       chain) are used in PRFEXP.                                     ;
%       The Zstrt's of all relevant 'TIMES-columns are analysed. If non;
%       one elements occur they are stored in a so called Nvarlst,asso-;
%       ciated with these relevant columns as value of the indicator   ;
%       'Nvarlst,which is put on the property list of the variable gi- ;
%       ving the column its identity via its FarVar-value. Nvarlst is a;
%       list of pairs (exponent=IVal(Zstrt-element) . associated name).;
%       This name can be newly generated(such as S6 and S7 in the above;
%       example) or already exist if,for instance, FarVar^exponent is  ;
%       itself an expression.This is marked with the indicator 'Bexl=T.;
%       The incorporation of this expression in PREFIXLIST is now done ;
%       via the production of the addition chain,implying that it is no;
%       longer necessary to treat it seperately.                       ;
% -------------------------------------------------------------------- ;
begin scalar var,nvar,nvarlst,rindx;
  for y:=rowmin:(-1) do
  if not numberp(var:=farvar y) and opval(y) eq 'times
  then
  <<foreach z in zstrt(y) do
    if ival(z)=1
    then setbval(z,var)
    else
    <<rindx:=xind(z);
      setprev(rindx,var);
      if not nvarlst then nvarlst:=list(1 . var);
      if numberp(nvar:=farvar rindx) or pairp(nvar) or 
         not (null(cdr zstrt rindx) and null(chrow rindx)
         and expcof(rindx)=1)
       then nvar:=fnewsym()
       else put(nvar,'bexl,t);
      setbval(z,nvar);
      nvarlst:=insexplst(ival(z).nvar,nvarlst);
    >>;
    if nvarlst then <<put(var,'nvarlst,nvarlst);
                      nvarlst:=nil>>
  >>
end;

symbolic procedure prfpowl(y);
% -------------------------------------------------------------------- ;
% arg : Y is a variable with an NVarlst in its property list.          ;
% res : The NVarlst is used to produce an addition chain in the above  ;
%       suggested way.Its is produced in the form of a list Powlst of  ;
%       dotted pairs which can be included in PREFIXLIST directly. So  ;
%       the pairs have a name as Car-part and a product of 2 variables ;
%       as Cdr-part.                                                   ;
% -------------------------------------------------------------------- ;
begin scalar nvarlst,explst,first,cfirst,csecond,diff,var,
             powlst,var1,var2;
  nvarlst:=explst:=get(y,'nvarlst);
  repeat
  <<first:=car(explst);
    cfirst:=car(first);
    csecond:=caar(explst:=cdr explst);
    diff:=cfirst-csecond;
    if diff>csecond
    then
    <<if remainder(cfirst,2)=1
      then
      <<cfirst:=cfirst-1;
        var:=fnewsym();
        powlst:=(cdr(first).list('times,y,var)).powlst;
        anop!*:=anop!*+1; % Extra product;
        first:=(cfirst.var);
        nvarlst:=first.nvarlst
      >>;
      diff:=csecond:=cfirst/2;
    >>;
    if null(assoc(diff,nvarlst))
    then
    <<var:=fnewsym();
      nvarlst:=(diff.var).nvarlst
    >>;
    var1:=cdr(assoc(diff,nvarlst));
    var2:=cdr(assoc(csecond,nvarlst));
    powlst:=(cdr(first).list('times,var1,var2)).powlst;
    anop!*:=anop!*+1;
    explst:=insexplst((diff.var1),explst);
  >>
  until diff=csecond and csecond=1;
  prefixlist:=append(reverse(powlst),prefixlist);
end;

symbolic procedure insexplst(el,explst);
% -------------------------------------------------------------------- ;
% arg : EL is a dotted pair (integer . name). Explst is a list of such ;
%       dotted pairs . The car-parts of the list elements define a de- ;
%       cending order for the elements of Explst.                      ;
% res : EL is inserted in Explst,but only if the Car-part was not yet  ;
%       available.                                                     ;
% -------------------------------------------------------------------- ;
if null(explst) or car(el)>caar(explst)
then el.explst
else 
  if car(el)=caar(explst)
  then explst
  else car(explst).insexplst(el,cdr explst);


% -------------------------------------------------------------------- ;
% PART 3 : IMPROVEMENT OF THE FINAL FORM OF PREFIXLIST                 ;
% -------------------------------------------------------------------- ;
% The function CleanupPrefixlist is used in MakePrefixlist, defined in ;
% CODCTL.RED, for back substitution of identifiers, which occur only   ;
% once in  the set of right hand sides, defining the optimized version ;
% of the input.                                                        ;
% -------------------------------------------------------------------- ;

symbolic procedure cleanupprefixlist;
% -------------------------------------------------------------------- ;
% This function is used for backsubstitution of values of identifiers  ;
% in rhs's if the corresponding identifier occurs only once in the set ;
% of rhs's. Prefixlist is thus made shorter if possible.               ;
% -------------------------------------------------------------------- ;
begin scalar lpl,lhs,rhs,protectednames,j,var,freq,k,firstocc,templist,
             complhs,lhsocc,comptemp;
 lpl:=length(prefixlist);
 lhs:=mkvect(lpl); rhs:=mkvect(lpl);
 foreach indx in codbexl!* do
  if numberp(indx) then protectednames:=farvar(indx) . protectednames;
 j:=0;
 foreach item in prefixlist do
  <<putv(lhs,j:=j+1,car item); putv(rhs,j,cdr item);
    if pairp(car item) then complhs:=j . complhs>>;
    complhs:=reverse complhs;
 for j:=1:lpl do
  if not member(var:=getv(lhs,j),protectednames)
   then
    << freq:=0; k:=j; firstocc:=lhsocc:=0;
       while freq=0 and k<lpl do
       << if (freq:=numberofocc(var,getv(rhs,k:=k+1)))=1 and firstocc=0
           then <<firstocc:=k; freq:=0>>;
          if firstocc>0 and freq>0 then firstocc:=0
       >>;
       if atom(var) and complhs and freq=0 
        then
         << while complhs and (car(complhs)<j) do complhs:=cdr complhs;
            freq:=0; comptemp:=complhs;
            while freq=0 and comptemp do
             << if (freq:=numberofocc(var,getv(lhs,car comptemp)))=1 
                   and lhsocc=0
                 then <<lhsocc:=car comptemp; freq:=0>>;
                comptemp:=cdr comptemp;
                if lhsocc>0 and freq>0 then lhsocc:=0
             >>;
            if freq>0 and firstocc>0 then firstocc:=0
         >>;
       if (firstocc=0 and lhsocc=0) or (firstocc>0 and lhsocc>0)
        then templist:=(getv(lhs,j) . getv(rhs,j)) . templist
        else  
          if lhsocc>0 
           then putv(lhs,lhsocc,
                     replacein(getv(lhs,lhsocc),var,getv(rhs,j)))
           else putv(rhs,firstocc,
                         replacein(getv(rhs,firstocc),var,getv(rhs,j)))
    >>
    else templist:=(getv(lhs,j) . getv(rhs,j)) . templist;
 prefixlist:=reverse(templist);
end;

symbolic procedure numberofocc(var,expression);
% -------------------------------------------------------------------- ;
% The number of occurrences of Var in Expression is computed and       ;
% returned.                                                            ;
% -------------------------------------------------------------------- ;
if atom(expression)
 then
  if var=expression then 1 else 0
 else
 (if cdr expression
   then numberofocc(var,cdr expression)
   else 0)
 +
 (if var=car expression
   then 1
   else
    if not atom car expression
     then numberofocc(var,car expression)
     else 0);

symbolic procedure replacein(expr1,var,expr2);
% -------------------------------------------------------------------- ;
% The occurrence of Var in Expr1 is replaced by Expr2 and the thus     ;
% rewritten form of Expr1 is returned.                                 ;
% -------------------------------------------------------------------- ;
begin scalar listofops,tempops,temp,ready;
  if atom(expr1)
   then if var=expr1 then return(expr2) else return(expr1)
   else
    if atom(expr2)
     then return(subst(expr2,var,expr1))
     else
      if var memq cdr expr1
       then 
        if car(expr1) neq car(expr2)
         then return(subst(expr2,var,expr1))
         else return(substops(cdr expr2,var,expr1))
       else
        << listofops:=cdr expr1;
           while not(ready) and listofops do
            << temp:=replacein(car listofops,var,expr2);
               if temp=car listofops
                then << tempops:=car(listofops).tempops;
                        listofops:=cdr listofops >>
                else ready:=t
            >>;
           if ready
            then tempops:=
                       append(append(reverse tempops,list(temp)),
                              cdr(listofops))
            else tempops:=cdr expr1;
           return car(expr1).tempops
        >>
end;

symbolic procedure substops(expr2,var,expr1);
begin scalar done,tempops,listofops;
 listofops:=cdr expr1;
 while not(done) and listofops do
  if car(listofops) neq var
   then << tempops:=car(listofops).tempops; listofops:=cdr listofops >>
   else << done:=tempops:=
           append(append(reverse tempops,expr2),cdr listofops) >>;
 return car(expr1).tempops
 end;

endmodule;


module coddec;  % Functions for generating declarations.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Author  :   M.C. van Heerwaarden.                                   ;
% ------------------------------------------------------------------- ;
%                                                                     ;
% ------------------------------------------------------------------- ;
% The module CODDEC contains the functions, which have to be used to  ;
% generate declarations, associated with the optimized version of a   ;
% set of input expressions when the switch Optdecs is turned on.      ;
% It can also be used via GENTRAN, when the SCOPE-GENTRAN interface is;
% modified, by adding the command TYPEALL Prefixlist;                 ;
% GLOBALS   : -                                                       ;
% INDICATORS: CHKTYPE, ARGTYPE                                        ;
% ENTRIES   : dettype, typecheck, argnrcheck                          ;
% IMPORTED  : Subscriptedvarp, symtabput, symtabget                   ;
%             FROM $gentransrc/util.red                               ;
% CONVERSION: Conversion imposes a partial ordering on types. With    ;
%             respect to this ordering, we can speak of types being   ; 
%             greater or less than others. Uncertainty in the type of ;
%             a certain variable or function is expressed by typing   ;
%             the variable in combination with type-bounds, i.e. a    ;
%             variable for which nothing is certain is typed as       ;
%             '(UNKNOWN ALL).                                         ;
% REMARK    : POSSIBLE REFINEMENTS FOR FORTRAN TYPES                  ;
%             FORTRAN knows types in different lengths. This can be   ;
%             introduced in the ordering. The FORTRAN type complex can;
%             be divided in complex-integer and complex-real. A       ;
%             procedure should be written to check whether a variable ;
%             is declared implicitly.                                 ; 
% ------------------------------------------------------------------- ;

global '(fortconv!* optlang!*)$

symbolic procedure typeall forms;
   begin
      scalar b, declst;
      declst := symtabget(nil, '!*decs!*);
      if optlang!* = 'fortran
      then while declst and not b
           do << b := cadar declst = 'complex;
                 declst := cdr declst >>;
      if b
      then fortconv!* := '(unknown
                             (integer real complex all)
                             (bool all)
                             (char string all)
                           );
      foreach ass in forms do asstype(car ass, cdr ass);
      finish!-typing forms;
      fortconv!* := '(unknown
                         (integer real all)
                         (bool all)
                         (char string all)
                     );
   end;

symbolic procedure asstype(lhs, rhs);
% ------------------------------------------------------------------- ;
% Performs typechecking on the assignment statement lhs-rhs, leading  ;
% to a lhs-type, which fits in the ordering imposed by the rhs.       ;
% ------------------------------------------------------------------- ;
begin
   scalar lhstype;
   lhstype := 
        typecheck(dettype(lhs, 'unknown), dettype(rhs, 'unknown), rhs);
   if atom lhs
   then symtabput(nil, lhs, list lhstype)
   else if subscriptedvarp car lhs 
   then symtabput(nil, car lhs, list lhstype)
   else symtabput(nil, car lhs, append(list if atom lhstype
                                            then list lhstype
                                            else lhstype,
                                       for each ndx in cdr lhs
                                       collect 'n
                 )                    )
end;

symbolic procedure dettype(xpr, minimumtype);
% ------------------------------------------------------------------- ;
% args: xpr = some expression                                         ;
%       minimumtype = minimum type xpr should have. This is set when  ;
%                     operators are encountered.                      ;
% eff : Determine type of xpr and typecheck arguments of operators in ;
%       xpr.                                                          ;
% ret : Type of xpr. If no type is known, '(UNKNOWN ALL) is returned. ;
% ------------------------------------------------------------------- ;
%
% Fixed to handle a NIL returned from OPCHECK mcd 22/7/89
%
begin
   scalar type, dtype, optype, mtype,  mntype, mxtype;
   return if atom xpr
          then if numberp xpr
               then if dmode!*
                    then if smember(dmode!*, '(!:rn!: !:ft!: !:bf!:))
                         then 'real
                         else if smember(dmode!*, '(!:gf!: !:gi!:))
                         then 'complex
                         else 'integer
                    else 'integer
               else if (type := symtabget(nil, xpr))
                   and (type := cadr type)
               then if greatertype(minimumtype, mintype type)
                    then if greatertype(minimumtype, maxtype type)
                         then typerror(1, xpr)
                         else
                          << symtabput(nil,xpr,list(type:=returntype 
                                      list(minimumtype,maxtype type)));
                             type
                          >>
                    else type
               else << symtabput(nil,xpr,list list(minimumtype,'all));
                       list(minimumtype, 'all) 
                    >> 
          else if subscriptedvarp car xpr 
          then << for each ndx in cdr xpr
                  do typecheck('integer, dettype(ndx, 'integer), ndx);
                     % argument minimumtype independent of parameter
                     % minimumtype
                  cadr symtabget(nil, car xpr)
               >>
          else if smember('argtype,
                          car( (optype := opcheck xpr) or '(nil)))
          then << mtype:=mntype:=mxtype:=
                                    car lispeval get(car xpr,'argtype);
                  % mxtype now contains the first type of the class in 
                  % which the arguments must be
                  for each arg in cdr xpr 
                  do << dtype := dettype(arg, mtype);
                        if greatertype(type := maxtype dtype, mxtype)
                        then mxtype := type;
                        if greatertype(type := mintype dtype, mntype)
                        then mntype := type
                     >>;
                  if cdr optype = 'argtype
                  then returntype list(mntype, mxtype)
                  else cdr optype
               >>
          else if optype
          then << type := car optype; 
                  if atom type then type := list type;
                  foreach arg in cdr xpr 
                                       % Number of args already checked
                  do << mtype := firstinclass car type;
                        typecheck(car type, dettype(arg, mtype), arg);
                        type := cdr type 
                     >>;
                  cdr optype
               >>
          else << for each arg in cdr xpr
                  do dettype(arg, 'unknown);
                  list(minimumtype, 'all)
               >> 
end;

symbolic procedure typecheck(lhstype, rhstype, rhs);
% ------------------------------------------------------------------- ;
% args: lhstype = type as known so far for lhs of ass. stat.          ;
%       rhstype = type as known so far for rhs of ass. stat.          ;
%       rhs     = rhs of ass. stat                                    ;
% eff : The rules used for typechecking are :                         ;
%                                                                     ;
%                      Condition:                        Check:       ;
%                                                                     ;
% lhs        |---|                                                    ;
% rhs  |---|           mintype(lhs) > maxtype(rhs)       OK           ;
%                                                                     ;
% lhs  |---|                                                          ;
% rhs        |---|     maxtype(lhs) < mintype(rhs)       ERROR        ;
%                                                                     ;
% lhs      |-----|     mintype(lhs) >= mintype(rhs) AND               ;
% rhs  |-----|         maxtype(lhs) >= maxtype(rhs)      OK           ;
%                                                                     ;
%      ---->                                                          ;
% lhs  |-----|         mintype(lhs) < mintype(rhs)  AND               ;
%            <----                                       OK when      ;
%                                                          adjustments; 
% rhs      |-----|     maxtype(lhs) < maxtype(rhs)         possible   ;
%                                                                     ;
% lhs    |-----|       mintype(lhs) >= mintype(rhs) AND               ;
%              <--                                       OK when      ;
%                                                          adjustments; 
% rhs  |---------|     maxtype(lhs) < maxtype(rhs)         possible   ;
%                                                                     ;
%      -->                                                            ;
% lhs  |---------|     mintype(lhs) < mintype(rhs) AND    OK when     ;
%                                                          adjustments;
% rhs    |-----|       maxtype(lhs) >= maxtype(rhs)        possible   ;
%                                                                     ;
% ret: The - possibly adjusted type of lhs.                           ;
% ------------------------------------------------------------------- ;
   if greatertype(mintype lhstype, maxtype rhstype)
   then returntype lhstype
   else if lesstype(maxtype lhstype, mintype rhstype)
   then typerror(2, lhstype . rhs)
   else if geqtype(mintype lhstype, mintype rhstype)
   then if geqtype(maxtype lhstype, maxtype rhstype)
        then returntype lhstype
        else if putmaxtype(rhs, maxtype lhstype)
             then returntype lhstype
             else typerror(2, lhstype . rhs)
   else if geqtype(maxtype lhstype, maxtype rhstype)
        then returntype list(mintype rhstype, maxtype lhstype)
        else if putmaxtype(rhs, maxtype lhstype)
             then returntype list(mintype rhstype, maxtype lhstype)
             else typerror(2, lhstype . rhs);

symbolic procedure mintype type;
% ------------------------------------------------------------------- ;
% A type may be a pair (l u) wher l is the minimum type for a variable;
% and u is the maximum type. This procedure returns the minimum type. ;
% ------------------------------------------------------------------- ;
   if atom type
   then type
   else car type;

symbolic procedure maxtype type;
% ------------------------------------------------------------------- ;
% A type may be a pair (l u) wher l is the minimum type for a variable;
% and  u is the maximum type. This procedure returns the maximum type.;
% ------------------------------------------------------------------- ;
   if atom type
   then type
   else cadr type;

symbolic procedure returntype type;
% ------------------------------------------------------------------- ;
% ret: returns mintype if mintype and maxtype are equal and type      ;
% otherwise.                                                          ;
% ------------------------------------------------------------------- ;
   if mintype type = maxtype type
   then mintype type
   else if greatertype(mintype type, maxtype type)
        then typerror(7, nil)
        else type;

symbolic procedure putmaxtype(xpr, type);
% ------------------------------------------------------------------- ;
% args: xpr = some expression                                         ;
%       type = maximum type for variables and for the result type of  ;
%              operators.                                             ;
% eff : To generate a correctly typed program,the maximum type for xpr; 
%       should be Type. If the result type of the main operator of Xpr;
%       is not dependent of its arguments, it is sufficient to check  ;
%       this result type. Otherwise, putmaxtype must be applied to all;
%       arguments.                                                    ;
%       When xpr is a variable and its maximum type is greater than   ;
%       Type the maximum type is tried to be smallened to Type.If this;
%       is not possible, an error occurs.                             ;
% ret:  T if xpr is of correct type, i.e. smaller than Type           ;
%       NIL if it is not possible to smallen the type of xpr when     ;
%       necessary.                                                    ;
% note: Perhaps this procedure does not choose consequently between   ;
%       returning an error and returning NIL.                         ;
% ------------------------------------------------------------------- ;
% 
% Fixed to handle a NIL returned from OPCHECK mcd 22/7/89 
%
begin
   scalar restype, b;
   return if null xpr
          then t
          else if atom xpr
          then if numberp xpr
               then geqtype(type, dettype(xpr, 'integer))
               else if restype := cadr symtabget(nil, xpr)
               then if atom restype
                    then geqtype(type, restype)
                    else if geqtype(type, mintype restype)
                    then << if type = mintype restype
                            then symtabput(nil, xpr, list type)
                            else symtabput(nil, xpr, 
                                           list list(mintype restype, 
                                                     type
                                          )         );
                            t
                         >>
                    else nil
               else typerror(3, xpr)
          else if subscriptedvarp car xpr
          then geqtype(type, cadr symtabget(nil, car xpr))
               % No uncertainty allowed in type of matrix
          else if (restype := cdr (opcheck(xpr) or '(nil))) = 'argtype
          then << b := t;
                  for each arg in cdr xpr
                  do b := b and putmaxtype(arg, type);
                  b
               >>
          else if restype
          then geqtype(type, restype)
          else geqtype(type, 'unknown)
end;

% ------------------------------------------------------------------- ;
% MODULE    : CONVERSION fortconv!*, cconv!*, ratconv!*, pasconv!*    ;
% STRUCTURE : conv!* ::= (UNKNOWN (class-list)-list)                  ;
%             class-list ::= ordered list of types: a type can be     ;
%             converted to the types which occur in the rest of the   ;
%             list.                                                   ;
% OPERATIONS: greatertype, geqtype, lesstype, getnum                  ;
% GLOBALS   : fortconv!*, cconv!*, ratconv!*, pasconv!*               ;
% INDICATORS: conversion                                              ;
% ------------------------------------------------------------------- ;

global '(fortconv!* cconv!* ratconv!* pasconv!* optlang!*);

put('fortran, 'conversion, 'fortconv!*);
put('c, 'conversion, 'cconv!*);
put('ratfor, 'conversion, 'ratconv!*);
put('pascal, 'conversion, 'pasconv!*);

fortconv!* := '(unknown
                   (integer real complex all)
                   (bool all)
                   (char string all)
               );

cconv!* := ratconv!* := pasconv!* :=
              '(unknown
                   (integer real all)
                   (bool all)
                   (char string all)
               );

symbolic procedure getnum;
% ------------------------------------------------------------------- ;
% Returns class of numeric types.                                     ;
% ------------------------------------------------------------------- ;
begin
  scalar conv, found;
  conv := lispeval
             get(if optlang!* then optlang!* else 'c, 'conversion);
  while not found and (conv := cdr conv)
  do if caar conv = 'integer
     then found := t;
  return car conv
end;

symbolic procedure greatertype(t1, t2);
% ------------------------------------------------------------------- ;
% args: t1 = t2 = type                                                ;
% ret : T       if t1 >  t2                                           ;
%                      t                                              ;
%                                                                     ;
%       NIL     if t1 <=  t2                                          ;
%                       t                                             ;
% note: >  means greater in the sense of the ordering which is        ;
%        t                                                            ;
%       described above for various languages.                        ;
% ------------------------------------------------------------------- ;
begin
  scalar conv, class, found, found1, found2, f;
  conv := lispeval
             get(if optlang!* then optlang!* else 'c, 'conversion);
  if car conv = t2
  then f := t
  else if car conv = t1
  then nil
  else << while (conv := cdr conv) and not found
          do << class := car conv;
                while class and not found2
                do << if car class = t1
                      then found1 := t;
                      if car class = t2
                      then found2 := t
                      else class := cdr class
                   >>;
                if found2
                then << class := cdr class;
                        while class and not f
                        do if car class = t1
                           then found1 := f := t
                           else class := cdr class;
                     >>;
                if (found1 and not found2) or (not found1 and found2)
                then typerror(4, t1 . t2)
                else if found1 and found2 then found := t
       >>    >>;
  return f
end;
                        
symbolic procedure geqtype(t1, t2);
% ------------------------------------------------------------------- ;
% args: t1 = t2 = type                                                ;
% ret : T       if t1 >=  t2                                          ;
%                       t                                             ;
%                                                                     ;
%       NIL     if t1 <  t2                                           ;
%                      t                                              ;
% Note: See greatertype.                                              ;
% ------------------------------------------------------------------- ;
begin
  scalar conv, class, found, found1, found2, f;
  conv := lispeval
             get(if optlang!* then optlang!* else 'c, 'conversion);
  if car conv = t2
  then f := t
  else if car conv = t1
  then nil
  else << while (conv := cdr conv) and not found
          do << class := car conv;
                while class and not found2
                do << if car class = t1
                      then found1 := t;
                      if car class = t2
                      then found2 := t
                      else class := cdr class
                   >>;
                if found2
                then while class and not f
                     do if car class = t1
                        then found1 := f := t
                        else class := cdr class;
                if (found1 and not found2) or (not found1 and found2)
                then typerror(4, t1 . t2)
                else if found1 and found2 then found := t
       >>    >>;
  return f
end;
                              
symbolic procedure lesstype(t1, t2);
   greatertype(t2, t1);

symbolic procedure firstinclass type;
% ------------------------------------------------------------------- ;
% Return : First (smallest) type of the class of types in which Type  ;
% belongs.                                                            ;
% ------------------------------------------------------------------- ;
begin
   scalar conv, found, class, mclass;
   conv := lispeval
              get(if optlang!* then optlang!* else 'c, 'conversion);
   return if (type = 'all) or (type = 'unknown)
          then 'unknown
          else << while (conv := cdr conv) and not found
                  do << mclass := car(class := car conv);
                        while class and not found
                        do << if car class = type
                              then found := t;
                              class := cdr class
                     >>    >>;
                  if found
                  then mclass
                  else typerror(5, type)
               >>
end;

symbolic procedure lastinclass type;
% ------------------------------------------------------------------- ;
% Returns : Last (greatest) type of the class of types in which Type  ;
% belongs.                                                            ;
% ------------------------------------------------------------------- ;
begin
   scalar conv, found, class;
   conv := lispeval
              get(if optlang!* then optlang!* else 'c, 'conversion);
   if type neq 'all
   then while (conv := cdr conv) and not found
        do << class := car conv;
              while class and not found
              do if car class = type
                 then << found := t;
                         repeat type := car class
                         until (class := cdr class) = '(all)
                      >>
                 else class := cdr class
           >>;
   return type
end;

% ------------------------------------------------------------------- ;
% MODULE    : FUNCTION TYPING                                         ;
% STRUCTURE :                                                         ;
% OPERATIONS: resulttype                                              ;
% GLOBALS   :                                                         ;
% INDICATORS: type: (argumenttype . resulttype)                       ;
%             argumenttype:                                           ;
%              Atom ==> 1 argument                                    ;
%              List with 1 type ==> number of arguments must be >= 2  ;
%              List with > 1 type ==> number of types = number        ;
%                                                         of arguments;
%             argtype:                                                ;
%              The type of a function or argument can be one of a     ;
%              class of types. Evaluation of the value of this        ;
%              indicator returns the whole class.                     ;
% ------------------------------------------------------------------- ;

for each op in '(times plus difference)
do << put(op, 'chktype, '((argtype) . argtype));
      put(op, 'argtype, '(getnum))
   >>;
put('quotient, 'chktype, '((argtype argtype) . real));
% ------------------------------------------------------------------- ;
% Needs refinement for complex numbers.                               ;
% ------------------------------------------------------------------- ;
put('quotient, 'argtype, '(getnum));
put('expt, 'chktype, '((argtype argtype) . argtype));
put('expt, 'argtype, '(getnum));
put('minus, 'chktype, '(argtype . argtype));
put('minus, 'argtype, '(getnum));
for each op in '(or and)
do put(op, 'chktype, '((bool) . bool));
put('not, 'chktype, '(bool . bool));
for each op in '(eq leq geq greaterp lessp neq)
do << put(op, 'chktype, '((argtype argtype) . bool));
      put(op, 'argtype, '(getnum))
   >>;
for each op in '(sin cos tan asin acos atan sinh cosh tanh asinh 
                                            acosh atanh cot log sqrt)
do put(op, 'chktype, '(real . real));

symbolic procedure opcheck op;    
% ------------------------------------------------------------------- ;
% args: op = operator                                                 ;
% eff : performs a check on the number of arguments                   ;
% ret : Complete type of operator, i.e.                               ;
%       (type-of-arguments-list .  resulttype)                        ;
% note: Decisions about what to do when Op's type is ARGTYPE are left ;
%       to the calling procedures.                                    ;
% ------------------------------------------------------------------- ;
begin
   scalar optype;
   return if not(optype := get(car op, 'chktype))
          then 'nil
          else if atom car optype
          then if length cdr op = 1
               then optype
               else typerror(6, car op)
          else if cdar optype
          then if length cdr op = length car optype
               then optype
               else typerror(6, car op)
          else if length cdr op >= 2
               then optype
               else typerror(6, car op)
end;
               
% ------------------------------------------------------------------- ;
% MODULE finish type analysis & checking.                             ;
%        Each variable will be bound to a single type.                ;
% ------------------------------------------------------------------- ;

symbolic procedure finish!-typing prflst;
% ------------------------------------------------------------------- ;
% args: prflst = the prefixlist from the optimizera                   ;
% eff : After some simple checks, each variable in the assignment has ;
%       a definite type. This type can be found in the symbol table.  ;
% ret : -                                                             ;
% ------------------------------------------------------------------- ;
begin
   scalar ltype, rtype;
   for each item in prflst
   do if (ltype := det!&bind(car item, 'all))
      then << if ltype = 'all
              then if (rtype := det!&bind(cdr item, ltype)) = 'all
                   then
                     write list("Unknown type for operator", cdr item)
                   else ltype := lastinclass rtype
              else rtype := det!&bind(cdr item, ltype);
              if greatertype(rtype, ltype)
              then typerror(2, item)
              else if atom car item
              then symtabput(nil, car item, list ltype)
              else symtabput(nil, caar item, list ltype)
           >>
      else % When a lhs variable is not declared, it is a variable
           % generated by the optimizer which still needs typing.
           symtabput(nil, car item, list det!&bind(cdr item, 'all))
end;
 
symbolic procedure det!&bind(xpr, maximumtype);
% ------------------------------------------------------------------- ;
% args: xpr = expression for which a definite type must be determined ;
%       maximumtype = the maximum type which Xpr may obtain; only used;
%                     in cases where the variable's type is           ;
%                     (UNKNOWN ALL).                                  ;
%                     Typechecking is done in finish!-typing.         ;
% eff : if xpr is a variable,its definite type is stored on the symbol;
%       table.                                                        ;
% ret : the type of Xpr after binding all variables to a certain type.;
% ------------------------------------------------------------------- ;
% 
% Fixed to handle a NIL returned from OPCHECK mcd 22/7/89 
%
begin
   scalar type, mtype, optype;
   return if atom xpr 
          then if numberp xpr
               then dettype(xpr, 'integer)
               else det!&bindmax(xpr, maximumtype)
          else if subscriptedvarp car xpr
          then << for each ndx in cdr xpr
                  do det!&bind(ndx, 'integer);
                  det!&bindmax(car xpr, maximumtype)
               >>
          else if smember('argtype,
                          car((optype := opcheck xpr) or '(nil)))
          then << mtype := 'unknown;
                  for each arg in cdr xpr do
                  if greatertype(type:=
                                      det!&bind(arg,maximumtype),mtype)
                     then mtype := type;
                  if cdr optype = 'argtype
                  then mtype
                  else cdr optype
               >>
          else if optype
          then << type := car optype;
                  if atom type then type := list type;
                  for each arg in cdr xpr
                  do << det!&bind(arg, car type);
                        type := cdr type
                     >>;
                  cdr optype
               >>
          else << for each arg in cdr xpr
                  do det!&bind(arg, 'all);
                  maximumtype
               >>
end;

symbolic procedure det!&bindmax(xpr, maximumtype);
begin
   scalar type;
   if pairp(type := cadr symtabget(nil, xpr))
   then if maxtype type = 'all
        then if mintype type = 'unknown
             then << type := maximumtype;
                     symtabput(nil, xpr, list maximumtype)
                  >>
             else << type := lastinclass mintype type;
                     symtabput(nil, xpr, list type)
                  >>
        else symtabput(nil, xpr, 
                       list(type := maxtype type));
    return type
end;

symbolic procedure typerror(errornr, xpr);
% ------------------------------------------------------------------- ;
% eff : Besides the error message, the declarations known so far are  ;
%       printed.                                                      ;
% ------------------------------------------------------------------- ;
   if errornr = 6 
   then rerror(scope,6,list("Wrong number of arguments for", xpr))
   else << terpri!* t;
           write("***** Type error:");
           terpri!* t;
           printdecs();
           if errornr = 1
           then rerror(scope,1,list("Wrong type for variable", xpr))
           else if errornr = 2
           then <<varpri(cdr xpr, list('setq, car xpr, cdr xpr), t);
                  rerror(scope,2,list("Wrong typing"))>>
           else if errornr = 3
           then rerror(scope,3,list(xpr, "not checked on type"))
           else if errornr = 4
           then rerror(scope,4,
             list(car xpr, "and", cdr xpr, "in different type classes"))
           else if errornr = 5
           then rerror(scope,5,list(xpr, "is an unknown type"))
           else if errornr = 7
           then rerror(scope,7,list("Wrong reasoning"))
           else rerror(scope,8,list("Unknown type error"))
        >>;

endmodule;


module ghorner;   % Generalized Horner support.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Author  :   M.C. van Heerwaarden.                                   ;
% ------------------------------------------------------------------- ;
% ------------------------------------------------------------------- ;
% This module contains procedures which implement a generalized Horner;
% scheme. There are two generalizations:                              ;
% 1. It is possible to offer a set of assignment statements. Each RHS ;
%    will be transformed into a Horner scheme.;                       ;
% 2. A list of identifiers is accepted as input.The polynomial will be; 
%    hornered w.r.t. the first identifier in the list, then the       ;
%    coefficients are hornered w.r.t. the second identifier, etc.     ;
%                                                                     ; 
% The following steps are taken to achieve this result.               ;
%                                                                     ;
% The polynomial P is expanded by turning on the switch EXP and by    ;
% applying Aeval on P. Each term of the expanded polynomial is brought;
% in a normal form. The terms are sorted using a binary tree represen-;
% tation. From this tree a list of terms is extracted with the powers ;
% in descending order.This list is rewritten into a Horner scheme.    ;
%                                                                     ;
% The 'normal form' of a term is:                                     ;
%      (TIMES COEF (EXPT X N))                                        ;
% It may be degenerated to:                                           ;
%      (EXPT X N)                for COEF = 1                         ;
%      (TIMES COEF X)            for N = 1                            ;
%      (COEF)                    for N = 0                            ;
% When a term is a minus term, the minus is handled as a part of the  ;
% coefficient.                                                        ;
% ------------------------------------------------------------------- ;

fluid '(!*algpri);

global '(autohorn);

switch algpri;

!*algpri := t;

% ------------------------------------------------------------------- ;
% ALGEBRAIC MODE COMMAND PARSER                                       ;
% ------------------------------------------------------------------- ;
% The -STAT and FORM- procedures provide an interface with the        ;
% algebraic mode. To horner a set of expressions, one can use the     ;
% HORNER command, which has the following syntax:                     ;
%   <HORNER command> ::= GHORNER <ass. list> [VORDER <ID-list>]       ;
%   <ass. list>      ::= <assignment statement> |                     ;
%                        << <assignment statement>                    ;
%                                        {; <assignment statement>} >>;
%   <ID-list>        ::= <ID> | <ID> {, <ID>}                         ;
% When the switch ALGPRI is ON, the results are printed using Varpri. ;
% When used inside a SCOPE-command the switch ALGPRI is turned OFF    ;
% automatically. However the current ALGPRI-setting is automatically  ;
% restored by SCOPE.                                                  ;
% ------------------------------------------------------------------- ;

put('ghorner, 'stat, 'ghornerstat);

symbolic procedure ghornerstat;
begin
    scalar x,y;
    % --------------------------------------------------------------- ;
    % GHORNER has already been read.                                  ;
    % --------------------------------------------------------------- ;
    flag('(vorder), 'delim);
    flag('(!*rsqb), 'delim);
    if car(x := xread t) = 'progn   % Read expressions;
    then x := cdr x                 % Remove keyword PROGN;
    else x := list x;               % An assignment is also an asslist;
    if not cursym!* eq 'vorder
    then if cursym!* eq '!*semicol!*
         then autohorn := t
         else symerr('ghorner, t)
    else << autohorn := nil;
            y := remcomma xread nil   % Read variable ordering list;
         >>;
    remflag('(vorder), 'delim); 
    remflag('(!*rsqb), 'delim);
    return list('ghorner, x, y) 
end;

put('ghorner, 'formfn, 'formghorner);

symbolic procedure formghorner(u, vars, mode);
    list('ghorner, mkquote cadr u, mkquote caddr u);

symbolic procedure ghorner(assset, varlist);
% ------------------------------------------------------------------- ;
% arg: assset = set of assignment statements                          ;
%      varlist = a list of variables                                  ;
% eff: For each assignment statement in assset, the RHS is turned into;
%      a Horner scheme. When varlist is not empty, the first variable ;
%      from varlist is used to form the scheme. The cdr of varlist is ;
%      used to transform the coefficients into a Horner scheme.       ;
%      Implicitly, the assignment is executed by putting the SQ-form  ;
%      of the Horner scheme on the property-list of the LHS-variable. ;
%      This means that the Horner scheme is available in the algebraic;
%      mode. When the switch ALGPRI is ON, the list of assignment     ;
%      statements is printed.                                         ;
% res: If ALGPRI is OFF the list with hornered assignment statements  ;
%      is returned. Nothing is returned when ALGPRI is ON.            ;
% ------------------------------------------------------------------- ;

begin
    scalar h, hexp, res;
    hexp := !*exp;
    !*exp := nil;
    res := for each ass in assset collect 
               if not eqcar(ass, 'setq)
               then 
                rederr("Assignment statement expected")
               else
                << h:=inithorner(caddr ass, varlist);
                   if !*algpri
                    then << if eqcar(h, 'quotient)
                             then
                              put(cadr ass,'avalue, 
                               list('scalar, 
                                     mk!*sq(numr !*f2q !*a2f cadr h ./ 
                                            numr !*f2q !*a2f caddr h)))
                              else
                               put(cadr ass,'avalue, 
                                list('scalar, mk!*sq !*f2q !*a2f h));
                             varpri(h, list('setq, cadr ass,nil), t);
                             terpri()
                          >>
                     else list(car ass,cadr ass,h)
                 >>;
    autohorn := nil;
    !*exp := hexp;
    if not !*algpri
    then return res
end;

symbolic procedure inithorner(p, varlist);
% ------------------------------------------------------------------- ;
% arg: p = polynomial                                                 ;
%      varlist = list of variables                                    ;
% eff: p is expanded and hornered to the various variables            ;
% res: the hornered version of p                                      ;
% ------------------------------------------------------------------- ;
begin scalar hmcd, res;
    hmcd := !*mcd;
    !*mcd := t;
    p := reval p;
    res := hornersums(p, varlist);
    !*mcd := hmcd;
    return res
end;

symbolic procedure hornersums(p, varlist);
    if atom p
    then p
    else if eqcar(p, 'plus)
         then horner(p, varlist)
    else append(list car p,
                     for each elt in cdr p
                     collect hornersums(elt, varlist));

symbolic procedure horner(p, varlist);
% ------------------------------------------------------------------- ;
% arg: p = polynomial                                                 ;
%      varlist = a list of variables for which the scheme must be made;
% res: A Horner scheme of p with respect to first variable in varlist ;
% ------------------------------------------------------------------- ;
begin
    scalar hexp, tree, var;
    hexp := !*exp;
    !*exp := t;
    p := reval p;
    tree := '(nil nil nil);
    var := if varlist
           then car varlist
           else if autohorn
                then mainvar2 p
                else nil;
    if var
    then << for each kterm in cdr p
            do tree := puttree(tree, 
                               orderterm(kterm, var), 
                               var);
            p := gathertree(tree, var . cdr varlist);
            p := schema(p, var, kpow(car p, var))
          >>;
    !*exp := hexp;
    return p
end;


symbolic procedure hornercoef(term, varlist);
% ------------------------------------------------------------------- ;
% arg: term = term of a polynomial in 'normal form'                   ;
%      varlist = the list of variables, including the one which just  ;
%                has been used to create the scheme.                  ;
% res: The same term is returned, but the coefficient has been turned ;
%      into a Horner scheme, using the second variable of varlist as  ;
%      main variable.                                                 ;
% ------------------------------------------------------------------- ;
begin
    scalar n, cof;
    return if null(cof := kcof(term, (n := kpow(term, car varlist))))
           then nil
           else if atom cof 
                then term
                else if n = 0
                     then hornersums(cof, cdr varlist)
                     else list(car term,
                               hornersums(cof, cdr varlist),
                               caddr term)
end;

symbolic procedure puttree(tree, term, var);
% ------------------------------------------------------------------- ;
% arg: tree = tree structure ( node, left edge, right edge), in which ;
%             the ordered terms are present.                          ;
%      term = the term which has to be put in                         ;
%      var = the variable for which the Horner scheme must be made    ;
% res: When the power of term is higher than the power of the node of ;
%      the root, puttree is called to place term in the right subtree ;
%      If the power is lower, term is placed in the left subtree. If  ;
%      the powers are equal the coefficients are added.               ;
% ------------------------------------------------------------------- ;
begin
    scalar c, n, m;
    return if null tree or null car tree
           then list (term, nil, nil)
           else if (n := kpow(term, var)) < (m := kpow(car tree, var))
                then list(car tree,
                          puttree(cadr tree, term, var),
                          caddr tree)
                else if n > m
                     then list(car tree,
                               cadr tree,
                               puttree(caddr tree, term, var))
                     else << % n = m so at least one term has been    ;
                             % inserted. Terms are added using only   ;
                             % one plus.                              ;
                             c := kcof(car tree, n);
                             if pairp c and car c = 'plus
                             then c := cdr c
                             else c := list c;
                             if n = 0
                             then 
                              list(append('(plus),
                                         append(list(kcof(term,n)),c)),
                                   cadr tree, 
                                   caddr tree)
                             else 
                              list(list('times,
                                         append('(plus), 
                                         append(list(kcof(term,n)),c)),
                                         if car c = 1
                                          then car tree
                                          else caddar tree
                                        ),
                                   cadr tree,
                                   caddr tree)>>
end;


symbolic procedure gathertree(tree, varlist);
% ------------------------------------------------------------------- ;
% arg: tree = a tree as made by puttree                               ;
%      varlist = list of variables                                    ;
% res: a list of the terms which are stored in the tree. The term with;
%      the highest power is first in the list. For every term found, a;
%      Horner-scheme is made for the coefficients of this term.At this;
%      point the current variable remains on varlist.                 ;
% ------------------------------------------------------------------- ;
begin
    % This is a reversed depth-first search;
    return if null tree
           then nil 
           else append(gathertree(caddr tree, varlist),
                       append(list hornercoef(car tree, varlist),
                              gathertree(cadr tree, varlist)))
end;


symbolic procedure orderterm(tt, var);
% ------------------------------------------------------------------- ;
% arg: tt = one term from the expanded polynomial                     ;
%      var = the variable for which the Horner scheme must be made    ;
% res: the term tt is returned in the 'normal form' which is described;
%      in the opening section.                                        ;
% ------------------------------------------------------------------- ;
begin
    scalar h, res, factr, min;
    min := nil;
    if tt = var
    then res := tt
    else << if eqcar(tt, 'minus)
            then << min := t;
                    tt := cadr tt
                 >>;
            if not eqcar(tt,'times)
            then if min
                 then if tt=var or (eqcar(tt,'expt) and cadr tt=var)
                      then res := list('times, '(minus 1), tt)
                      else res := list('minus, tt)
                 else res := tt
            else << while not null (tt := cdr tt)
                    do << if pairp(h := car tt) and eqcar(h, 'minus)
                          then << min := not min;
                                  h := cadr h
                               >>;
                          if h = var
                          then factr := h
                          else << if eqcar(h, 'expt) and cadr h = var
                                  then factr := h
                                  else res := append(res, list h)
                               >>
                       >>;
                    if min
                    then << h := list('minus, car res);
                            if null cdr res
                            then res := list h
                            else res := append(list h, cdr res)
                         >>;
                    res := if null factr
                           then cons('times, res)
                           else if null cdr res
                                then list('times, car res, factr)
                                else list('times, 
                                          append('(times), res), 
                                          factr)
                 >>
         >>;
    return res
end;

symbolic procedure schema(pn, var, n);
% ------------------------------------------------------------------- ;
% arg: pn  = the polynomial pn given as a list of terms in 'normal    ;
%            form' in decsending order w.r.t. the powers of these     ;
%            terms.                                                   ;
%      var = the Horener-scheme variable.                             ;
%      n   = degree of the polynomial.                                ;
% eff: Some effort is made to change "(TIMES var 1)" to "var" and to  ;
%      turn "...(TIMES var (TIMES var..." into                        ;
%           "...(TIMES (EXPT var n) ..."                              ;
% res: Horner scheme for the polynomial pn.                           ;
% ------------------------------------------------------------------- ;
begin
    scalar hn, k!+1mis;
    hn := kcof(car pn, n); % The n-th term always exists;
    pn := cdr pn;
    for k := (n - 1) step -1 until 0
    do << % --------------------------------------------------------- ;
          % hn contains the coefficients for the terms var^n upto     ;
          % var^(k+1). The var for term var^(k+1) is still missing.   ;
          % This is correct when for k=0 the last var will be added.  ;
          % --------------------------------------------------------- ;
          if kpow(car pn, var) = k
          then << % k-th term exists;
                  hn := list('plus, kcof(car pn, k),
                             if hn = 1
                             then var
                             else if not (k = n-1) and k!+1mis
                                  then 
                                   if pairp hn and car hn = 'times
                                    then list('times,list('expt,var,
                                              kpow(cadr hn, var) + 1),
                                                 caddr hn)
                                    else list('expt,var,
                                                 kpow(hn, var) + 1)
                                  else list('times, var, hn)
                            );
                  k!+1mis := nil;
                  pn := cdr pn
               >>
          else << % k-th term misses;
                  hn := if hn = 1
                        then var
                        else if not (k = n-1) and k!+1mis
                             then 
                              if pairp hn and car hn = 'times
                               then list('times,list('expt,var,
                                               kpow(cadr hn, var) + 1),
                                          caddr hn)
                               else list('expt, var, kpow(hn, var) + 1)
                             else list('times, var, hn);
                  k!+1mis := t
               >>
       >>;
    return hn
end;

symbolic procedure kpow(term, var);
% ------------------------------------------------------------------- ;
% arg: term = term of a polynomial in 'normal form'                   ;
%      var  = the variable for which the Horner scheme must be made   ;
% res: the power of var in term                                       ;
% ------------------------------------------------------------------- ;
begin
    scalar h;
    return if null term 
           then nil 
           else if (h := term) = var
                then 1
                else if eqcar(h, 'expt) and eqcar(cdr h, var)
                     then caddr h
                     else if eqcar(h, 'times)
                          then if (h := caddr h) = var
                               then 1
                               else if not atom h and eqcar(cdr h, var)
                                    then caddr h
                                    else 0
                          else 0
end;


symbolic procedure kcof(term, n);
% ------------------------------------------------------------------- ;
% arg: term = term of a polynomial in 'normal form'                   ;
%      n    = the power of term                                       ;
% res: the coefficient of var in term                                 ; 
% ------------------------------------------------------------------- ;
    if null n
    then nil
    else if n = 0
         then term
         else if n = 1
              then if not eqcar(term, 'times)
                   then 1
                   else cadr term
              else if eqcar(term, 'expt)
                   then 1
                   else cadr term;

symbolic procedure mainvar2 u;
% ------------------------------------------------------------------- ;
% Same procedure as mainvar from ALG2.RED, but returns NIL instead of ;
% 0 and does not allow a mainvar of the form (EXPT E X) to be returned;
% ------------------------------------------------------------------- ;
begin
   scalar res;
   res := if domainp(u := numr simp!* u) 
          then nil
          else if sfp(u := mvar u) 
               then prepf u
               else u;
   if eqcar(res, 'expt)
   then res := nil;
   return res
 end;

endmodule;


module gstructr;  % Generalized structure routines.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Author  :   M.C. van Heerwaarden, J.A. van Hulzen                   ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% This module contains an extended version of the structr facility of ;
% REDUCE.                                                             ;
%                                                                     ;
% Author of structr-routines: Anthony C. Hearn.                       ;
%                                                                     ;
% Copyright (c) 1987 The RAND Corporation. All rights reserved.       ;
%                                                                     ;
% ------------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% This is a generalization of the STRUCTR-command. Instead of one     ;
% expression, GSTRUCTR takes as input a list of assignment statements.;
% SYNTAX:                                                             ;
%        <gstructr-command> ::= GSTRUCTR <ass-list> NAME <id>         ;
%        <ass-list>         ::= {<assignments> | <matrix>}            ;
%        <id>               ::= <name for CSE>                        ;
% As a result, all assignments are printed with substitutions for the ;
% CSE's. Then WHERE is printed, followed by the list of CSE's. These  ;
% CSE's are printed in reversed order. Matrices are treated as if     ;
% assignments were made for all matrix elements.                      ;
% When the switch FORT is ON, the statements will be in  FORTRAN execu;
% table order. Be sure PERIOD is OFF when using a matrix,since FORTRAN;
% expects integer subscripts, and REDUCE generates a floating point   ;
% representation for these subscripts when PERIOD is ON.              ;
% The switch ALGPRI can be turned OFF when the list of assignments is ;
% needed in prefix-form.                                              ;
% ------------------------------------------------------------------- ;

fluid '(countr svar !*varlis);

fluid '(!*algpri !*fort !*nat !*savestructr);

global'(varnam!*);

switch savestructr, algpri;

on algpri;

% ***** two essential uses of RPLACD occur in this module.

put('gstructr, 'stat, 'gstructrstat);

symbolic procedure gstructrstat;
begin
    scalar x,y;
    flag('(name), 'delim);
    if eqcar(x := xread t, 'progn)
    then x := cdr x
    else x := list x;
    if cursym!* = 'name
    then y := xread t;
    remflag('(name), 'delim);
    return list('gstructr, x, y)
end;

put('gstructr, 'formfn, 'formgstructr);

symbolic procedure formgstructr(u, vars, mode);
list('gstructr, mkquote cadr u, mkquote caddr u);

symbolic procedure gstructr(assset, name);
begin
  !*varlis := nil;
  countr := 0;
  for each ass in assset
  do if not pairp ass
     then if get(ass, 'rtype) = 'matrix
            then prepstructr(cadr get(ass,'avalue),name,ass)
           else rederr(ass, "is not a matrix")
     else prepstructr(caddr ass, name, cadr ass);
  if !*algpri
  then print!*varlis()
  else return remredundancy(for each x in reversip!* !*varlis
              collect list('setq, cadr x, cddr x))
end;

symbolic procedure prepstructr(u, name, fvar);
   begin scalar i, j;
      %!*VARLIS is a list of elements of form:
      %(<unreplaced expression> . <newvar> . <replaced exp>);
      if name
      then svar := name
      else svar := varnam!*;
      u := aeval u;
      if flagpcar(u, 'struct)
      then << i := 0;
              u:= car u .
                   (for each row in cdr u collect 
                    << i := i + 1;
                       j := 0;
                       for each column in row collect 
                       << j := j + 1;
                          !*varlis := (nil .
                                       list(fvar,i,j) .
                                       prepsq prepstruct!*sq column) .
                                       !*varlis
                    >> >>
                   )
           >>
      else if getrtype u
           then typerr(u,"STRUCTR argument")
           else !*varlis:=(nil.fvar.prepsq prepstruct!*sq u).!*varlis
   end;

symbolic procedure print!*varlis;
begin
  if !*fort 
  then !*varlis := reversip!* !*varlis;
  if not !*fort 
  then << for each x in reverse !*varlis 
          do if null car x
             then << varpri(cddr x,list('setq,cadr x,mkquote cddr x),t);
                     if not flagpcar(cddr x,'struct) then terpri();
                     if null !*nat then terpri()
                  >>;
          if countr=0 then return nil;
          prin2t "   where"
       >>;
  for each x in !*varlis 
  do if !*fort or car x
     then <<terpri!* t;
            if null !*fort then prin2!* "      ";
            varpri(cddr x,list('setq,cadr x,mkquote cddr x),t)
          >>;
  if !*savestructr
    then <<if arrayp svar
           then <<put(svar,'array,
                        mkarray(list(countr+1),'algebraic));
                  put(svar,'dimension,list(countr+1))>>;
           for each x in !*varlis do
              if car x then setk2(cadr x,mk!*sq !*k2q car x)>>
end;

symbolic procedure setk2(u,v);
   if atom u then setk1(u,v,t) else setelv(u,v);

symbolic procedure prepstruct!*sq u;
if eqcar(u,'!*sq)
   then prepstructf numr cadr u ./ prepstructf denr cadr u
   else u;

symbolic procedure prepstructf u;
if null u
then nil
else if domainp u
     then u
     else begin
            scalar x,y;
            x := mvar u;
            if sfp x
            then if y := assoc(x,!*varlis)
                 then x:=cadr y
                 else x:=prepstructk(prepsq!*(prepstructf x ./ 1),
                                     prepstructvar(),x)
            else if not atom x and not atomlis cdr x
                 then if y := assoc(x,!*varlis)
                      then x := cadr y
                      else x := prepstructk(x,prepstructvar(),x);
            return x .** ldeg u .* prepstructf lc u .+ prepstructf red u
          end;

symbolic procedure prepstructk(u,id,v);
begin
  scalar x;
  if x := prepsubchk1(u,!*varlis,id)
     then rplacd(x,(v . id . u) . cdr x)
     else if x := prepsubchk2(u,!*varlis)
             then !*varlis := (v . id . x) . !*varlis
             else !*varlis := (v . id . u) . !*varlis;
  return id
end;

symbolic procedure prepsubchk1(u,v,id);
   begin scalar w;
      while v do
       <<smember(u,cddar v)
            and <<w := v; rplacd(cdar v,subst(id,u,cddar v))>>;
         v := cdr v>>;
      return w
   end;

symbolic procedure prepsubchk2(u,v);
   begin scalar bool;
      for each x in v do
       smember(cddr x,u)
          and <<bool := t; u := subst(cadr x,cddr x,u)>>;
      if bool then return u else return nil
   end;

symbolic procedure prepstructvar;
   begin
      countr := countr + 1;
      return if arrayp svar then list(svar,countr)
       else compress append(explode svar,explode countr)
   end;

symbolic procedure remredundancy setqlist;
% -------------------------------------------------------------------- ;
% This function is used for backsubstitution of values of identifiers  ;
% in rhs's if the corresponding identifier occurs only once in the set ;
% of rhs's. SetqList is thus made shorter if possible.                 ;
% An element of Setqlist has the form (SETQ assname value), where      ;
% assname can be redundant if                                          ;
% Atom(assname) and Letterpart(assname) = svar                         ;
% -------------------------------------------------------------------- ;
begin scalar lsl,lhs,rhs,relevant,j,var,freq,k,firstocc,templist;
 lsl:=length(setqlist);
 lhs:=mkvect(lsl); rhs:=mkvect(lsl); relevant:=mkvect(lsl);
 j:=0; var:=explode(svar);
 foreach item in setqlist do
  <<putv(lhs,j:=j+1,cadr item); putv(rhs,j,caddr item);
    if atom(cadr item ) and letterparts(cadr item) = var
     then putv(relevant,j,t)
  >>;
 for j:=1:lsl do
  if getv(relevant,j)
   then
    << var:=getv(lhs,j); freq:=0; k:=j; firstocc:=0;
       while freq=0 and k<lsl do
       << if (freq:=numberofoccs(var,getv(rhs,k:=k+1)))=1 and firstocc=0
           then <<firstocc:=k; freq:=0>>;
          if firstocc>0 and freq>0 then firstocc:=0
       >>;
       if firstocc=0
        then templist:=list('setq,getv(lhs,j),getv(rhs,j)) . templist
        else  putv(rhs,firstocc,
                            subst(getv(rhs,j),var,getv(rhs,firstocc)))
    >>
    else templist:=list('setq,getv(lhs,j),getv(rhs,j)) . templist;
 return reverse(templist);
end;

symbolic procedure letterparts(name);
   % ----------------------------------------------------------------- ;
   % Eff: The exploded form of the Letterpart of Name returned, i.e.   ;
   % (!a !a) if Name=aa55.                                             ;
   % ----------------------------------------------------------------- ;
   begin scalar letters;
       letters:=reversip explode name;
       while digit car letters do letters:=cdr letters;
       return reversip letters
   end;

symbolic procedure numberofoccs(var,expression);
% -------------------------------------------------------------------- ;
% The number of occurrences of Var in Expression is computed and       ;
% returned.                                                            ;
% -------------------------------------------------------------------- ;
if atom(expression)
 then
  if var=expression then 1 else 0
 else
 (if cdr expression
   then numberofoccs(var,cdr expression)
   else 0)
 +
 (if var=car expression
   then 1
   else
    if not atom car expression
     then numberofoccs(var,car expression)
     else 0);

endmodule;


end;
