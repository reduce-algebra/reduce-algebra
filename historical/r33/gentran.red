module util;    %%  GENTRAN Utility Functions  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Points:  ALL FUNCTIONS


symbolic$


% User-Accessible Primitive Function %
operator genstmtnum$

% User-Accessible Global Variables %
global '(genstmtincr!* genstmtnum!* tablen!*)$
share 'genstmtincr!*, 'genstmtnum!*, 'tablen!*$
genstmtincr!* := 1$
genstmtnum!*  := 25000$
tablen!*      := 4$

% GENTRAN Global Variables %
global '(!*lisparithexpops!* !*lispdefops!* !*lisplogexpops!*
         !*lispstmtgpops!* !*lispstmtops!* !*symboltable!*)$
!*lisparithexpops!* := '(expt minus plus quotient times)$
    %LISP arithmetic expression operators
!*lispdefops!*      := '(defun)$  %LISP function definition operator
!*lisplogexpops!*   := '(and equal geq greaterp leq lessp neq not or)$
    %LISP logical & relational exp operators
!*lispstmtgpops!*   := '(prog progn)$  %LISP statement group operators
!*lispstmtops!*     := '(break cond end for go read repeat
                         return setq stop while write)$
%LISP statement operators
!*symboltable!*     := '(!*main!*)$  %symbol table

global '(!*for!*)$


%%                                      %%
%% Statement Number Generation Function %%
%%                                      %%


procedure genstmtnum;
genstmtnum!* := genstmtnum!* + genstmtincr!*$


%%                                                        %%
%% Symbol Table Insertion, Retrieval & Deletion Functions %%
%%                                                        %%


procedure symtabput(name, type, value);
%                                                                      %
% CALL                                               INSERTS           %
% SymTabPut(subprogname, NIL,         NIL         )  subprogram name   %
% SymTabPut(subprogname, '!*Type!*,   subprogtype )  subprogram type   %
% SymTabPut(subprogname, '!*Params!*, paramlist   )  parameter list    %
% SymTabPut(subprogname, vname,  '(type d1 d2 ...))  type & dimensions %
%                                                    for variable,     %
%                                                    variable range,   %
%   if subprogname=NIL                               parameter, or     %
%      then subprogname <-- Car symboltable          function name     %
%                                                                      %
<<
    name := name or car !*symboltable!*;
    !*symboltable!* := name . delete(name, !*symboltable!*);
    if type memq '(!*type!* !*params!*) then
        put(name, type, value)
    else if type then
        begin
        scalar v, vtype, vdims, dec, decs;
        v := type;
        vtype := car value;
        vdims := cdr value;
        decs := get(name, '!*decs!*);
        dec := assoc(v, decs);
        decs := delete(dec, decs);
        vtype := vtype or (if length dec > 1 then cadr dec);
        vdims := vdims or (if length dec > 2 then cddr dec);
        dec := v . vtype . vdims;
        put(name, '!*decs!*, append(decs, list dec))
        end
>>$

procedure symtabget(name, type);
%                                                                      %
% CALL                                 RETRIEVES                       %
% SymTabGet(NIL,         NIL        )  all subprogram names            %
% SymTabGet(subprogname, '!*Type!*  )  subprogram type                 %
% SymTabGet(subprogname, '!*Params!*)  parameter list                  %
% SymTabGet(subprogname, vname      )  type & dimensions for variable, %
%                                      variable range, parameter, or   %
%                                      function name                   %
% SymTabGet(subprogname, '!*Decs!*  )  all types & dimensions          %
%                                                                      %
%   if subprogname=NIL & 2nd arg is non-NIL                            %
%      then subprogname <-- Car symboltable                            %
%                                                                      %
<<
    if type then name := name or car !*symboltable!*;
    if null name then
        !*symboltable!*
    else if type memq '(!*type!* !*params!* !*decs!*) then
        get(name, type)
    else
        assoc(type, get(name, '!*decs!*))
>>$

procedure symtabrem(name, type);
%                                                                      %
% CALL                                 DELETES                         %
% SymTabRem(subprogname, NIL        )  subprogram name                 %
% SymTabRem(subprogname, '!*Type!*  )  subprogram type                 %
% SymTabRem(subprogname, '!*Params!*)  parameter list                  %
% SymTabRem(subprogname, vname      )  type & dimensions for variable, %
%                                      variable range, parameter, or   %
%                                      function name                   %
% SymTabRem(subprogname, '!*Decs!*  )  all types & dimensions          %
%                                                                      %
%   if subprogname=NIL                                                 %
%      then subprogname <-- Car symboltable                            %
%                                                                      %
<<
    name := name or car !*symboltable!*;
    if null type then
        !*symboltable!* := delete(name, !*symboltable!*) or '(!*main!*)
    else if type memq '(!*type!* !*params!* !*decs!*) then
        remprop(name, type)
    else
        begin
        scalar v, dec, decs;
        v := type;
        decs := get(name, '!*decs!*);
        dec := assoc(v, decs);
        decs := delete(dec, decs);
        put(name, '!*decs!*, decs)
        end
>>$

procedure getvartype var;
begin
scalar type;
if listp var then
    var := car var;
type := symtabget(nil, var);
if type and length type >= 2 then
    type := cadr type
else
    type := nil;
return type
end$

procedure arrayeltp exp;
length symtabget(nil, car exp) > 2$


%%                                 %%
%% Functions for Making LISP Forms %%
%%                                 %%


procedure mkassign(var, exp);
list('setq, var, exp)$

procedure mkcond pairs;
'cond . pairs$

procedure mkdef(name, params, body);
append(list('defun, name, params), body)$

procedure mkreturn exp;
list('return, exp)$

procedure mkstmtgp(vars, stmts);
if numberp vars then
    'progn . stmts
else
    'prog . vars . stmts$


%% LISP Form Predicates %%


procedure lispassignp stmt;
   eqcar(stmt,'setq);

procedure lispbreakp form;
   eqcar(form,'break);

procedure lispcallp form;
listp form$

procedure lispcondp stmt;
   eqcar(stmt,'cond);

procedure lispdefp form;
   not atom form and car form memq !*lispdefops!*$

procedure lispexpp form;
atom form or
car form memq !*lisparithexpops!* or
car form memq !*lisplogexpops!* or
not (car form memq !*lispstmtops!*) and
not (car form memq !*lispstmtgpops!*) and
not (car form memq !*lispdefops!*)$

procedure lispendp form;
   eqcar(form,'end);

procedure lispforp form;
   eqcar(form,!*for!*);

procedure lispgop form;
   eqcar(form,'go);

procedure lisplabelp form;
atom form$

procedure lispprintp form;
   eqcar(form,'write);

procedure lispreadp form;
   eqcar(form,'read);

procedure lisprepeatp form;
   eqcar(form,'repeat);

procedure lispreturnp stmt;
   eqcar(stmt,'return);

procedure lispstmtp form;
atom form or
car form memq !*lispstmtops!* or
( atom car form and
  not (car form memq !*lisparithexpops!* or
       car form memq !*lisplogexpops!* or
       car form memq !*lispstmtgpops!* or
       car form memq !*lispdefops!*) )$

procedure lispstmtgpp form;
listp form and car form memq !*lispstmtgpops!*$

procedure lispstopp form;
   eqcar(form,'stop);

procedure lispwhilep form;
   eqcar(form,'while);


%%                                               %%
%% Type Predicates & Type List Forming Functions %%
%%                                               %%


procedure formtypelists varlists;
% ( (var TYPE d1 d2...)       ( (TYPE (var d1 d2...) ...)   %
%   :                     ==>   :                           %
%   (var TYPE d1 d2...) )       (TYPE (var d1 d2...) ...) ) %
begin
scalar type, typelists, tl;
for each vl in varlists do
<<
    type := cadr vl;
    if onep length(vl := delete(type, vl)) then
        vl := car vl;
    if (tl := assoc(type, typelists)) then
        typelists := delete(tl, typelists)
    else
        tl := list type;
    typelists := append(typelists, list append(tl, list vl))
>>;
return typelists
end$


procedure functionformp(stmt, name);
% Does stmt contain an assignment which assigns a value to name? %
% Does it contain a RETURN exp; stmt?                            %
% (i.e., (SETQ name exp) -or- (RETURN exp)                       %
if null stmt or atom stmt then
    nil
else if car stmt eq 'setq and cadr stmt eq name then
    t
else if car stmt eq 'return and cdr stmt then
    t
else
    eval('or . for each st in stmt collect functionformp(st, name))$

procedure implicitp type;
begin
scalar xtype, ximp, r;
xtype := explode2 type;
ximp := explode2 'implicit;
r := t;
repeat
    r := r and (car xtype eq car ximp)
until null(xtype := cdr xtype) or null(ximp := cdr ximp);
return r
end$


%%                 %%
%% Misc. Functions %%
%%                 %%


procedure insertcommas lst;
begin
scalar result;
if null lst then
    return nil;
result := list car lst;
while lst := cdr lst do
    result := car lst . '!, . result;
return reverse result
end$

procedure insertparens exp;
'!( . append(exp, list '!))$

procedure optype op;
get(op, '!*optype!*)$

put('minus,    '!*optype!*, 'unary )$
put('not,      '!*optype!*, 'unary )$
put('quotient, '!*optype!*, 'binary)$
put('expt,     '!*optype!*, 'binary)$
put('equal,    '!*optype!*, 'binary)$
put('neq,      '!*optype!*, 'binary)$
put('greaterp, '!*optype!*, 'binary)$
put('geq,      '!*optype!*, 'binary)$
put('lessp,    '!*optype!*, 'binary)$
put('leq,      '!*optype!*, 'binary)$
put('plus,     '!*optype!*, 'nary  )$
put('times,    '!*optype!*, 'nary  )$
put('and,      '!*optype!*, 'nary  )$
put('or,       '!*optype!*, 'nary  )$

procedure seqtogp lst;
if null lst or atom lst or lispstmtp lst or lispstmtgpp lst then
    lst
else if onep length lst and listp car lst then
    seqtogp car lst
else
    mkstmtgp(nil, for each st in lst collect seqtogp st)$

procedure stringtoatom a;
intern compress
    foreach c in append('!" . explode2 a, list '!")
        conc list('!!, c)$

procedure stripquotes a;
if atom a then
    intern compress
        for each c in explode2 a conc list('!!, c)
else if car a eq 'quote then
    stripquotes cadr a
else
    a$


endmodule;

module intrfc;    %%  GENTRAN Parsing Routines & Control Functions  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Points:
% DeclareStat, GENDECS, GenInStat (GentranIn), GenOutStat
% (GentranOutPush), GenPopStat (GentranPop), GenPushStat, GenShutStat
% (GentranShut), GenStat (Gentran), (GENTRANPAIRS),
% LiteralStat, SYM!-GENTRAN, SYM!-GENTRANIN, SYM!-GENTRANOUT,
% SYM!-GENTRANSHUT,
% SYM!-GENTRANPUSH, SYM!-GENTRANPOP


symbolic$


% GENTRAN Commands %
put('gentran,     'stat, 'genstat    )$
put('gentranin,   'stat, 'geninstat  )$
put('gentranout,  'stat, 'genoutstat )$
put('gentranshut, 'stat, 'genshutstat)$
put('gentranpush, 'stat, 'genpushstat)$
put('gentranpop,  'stat, 'genpopstat )$

% Form Analysis Function %
put('gentran,        'formfn, 'formgentran)$
put('gentranin,      'formfn, 'formgentran)$
put('gentranoutpush, 'formfn, 'formgentran)$
put('gentranshut,    'formfn, 'formgentran)$
put('gentranpop,     'formfn, 'formgentran)$

% GENTRAN Functions %
put('declare, 'stat, 'declarestat)$
put('literal, 'stat, 'literalstat)$

% GENTRAN Operators %
newtok '((!: !: !=)    lsetq )$  infix ::= $
newtok '((!: != !:)    rsetq )$  infix :=: $
newtok '((!: !: != !:) lrsetq)$  infix ::=:$

% User-Accessible Primitive Function %
operator gendecs$

% GENTRAN Mode Switches %
global '(!*gendecs)$
!*gendecs := t$
put('gendecs, 'simpfg, '((nil) (t (gendecs nil))))$
switch gendecs$

% GENTRAN Flags %
global '(
%%       !*GENTRANOPT
         !*gentranseg
         !*period)$
%%!*GENTRANOPT := NIL$
!*gentranseg := t$
switch gentranseg$

% User-Accessible Global Variable %
global '(gentranlang!*)$
share gentranlang!*$
gentranlang!* := 'fortran$

% GENTRAN Global Variable %
global '(!*term!* !*stdin!* !*stdout!* !*instk!* !*currin!* !*outstk!*
         !*currout!* !*outchanl!*)$
!*term!*     := (t . nil)$             %terminal filepair
!*stdin!*    := !*term!*$              %standard input filepair
!*stdout!*   := !*term!*$              %standard output filepair
!*instk!*    := list !*stdin!*$        %template file stack
!*currin!*   := car !*instk!*$         %current input filepair
!*outstk!*   := list !*stdout!*$       %output file stack
!*currout!*  := car !*outstk!*$        %current output filepair
!*outchanl!* := list cdr !*currout!*$  %current output channel list

global '(!*do!* !*for!*)$
off quotenewnam$
!*do!* := 'do$
!*for!* := 'for$
on quotenewnam$

% REDUCE Variables %
global '(cursym!* !*vars!*)$
fluid '(!*mode)$


%%                    %%
%%  PARSING ROUTINES  %%
%%                    %%


%%  GENTRAN Command Parsers  %%


procedure genstat;
%                     %
% GENTRAN             %
%     stmt            %
% [OUT f1,f2,...,fn]; %
%                     %
begin
scalar st;
flag('(out), 'delim);
st := xread t;
remflag('(out), 'delim);
if cursym!* eq 'out then
    return list('gentran, st, readfargs())
else if endofstmtp() then
    return list('gentran, st, nil)
else
    gentranerr('e, nil, "INVALID SYNTAX", nil)
end$


procedure geninstat;
%                     %
% GENTRANIN           %
%     f1,f2,...,fm    %
% [OUT f1,f2,...,fn]; %
%                     %
begin
scalar f1, f2;
flag('(out), 'delim);
f1 := xread nil;
if atom f1 then f1 := list f1 else f1 := cdr f1;
remflag('(out), 'delim);
if cursym!* eq 'out then
    f2 := readfargs();
return list('gentranin, f1, f2)
end$


procedure genoutstat;
%                          %
% GENTRANOUT f1,f2,...,fn; %
%                          %
list('gentranoutpush, readfargs())$


procedure genshutstat;
%                           %
% GENTRANSHUT f1,f2,...,fn; %
%                           %
list('gentranshut, readfargs())$


procedure genpushstat;
%                           %
% GENTRANPUSH f1,f2,...,fn; %
%                           %
list('gentranoutpush, readfargs())$


procedure genpopstat;
%                          %
% GENTRANPOP f1,f2,...,fn; %
%                          %
list('gentranpop, readfargs())$


%%  GENTRAN Function Parsers  %%


procedure declarestat;
%                              %
% DECLARE v1,v2,...,vn : type; %
%                              %
% DECLARE                      %
% <<                           %
%     v1,v2,...,vn1 : type1;   %
%     v1,v2,...,vn2 : type2;   %
%     .                        %
%     .                        %
%     v1,v2,...,vnn : typen    %
% >>;                          %
%                              %
begin
scalar res, varlst, type;
scan();
if cursym!* eq '!*lsqb!* then
<<
    scan();
    while cursym!* neq '!*rsqb!* do
    <<
        varlst := list xread1 'for;
        while cursym!* neq '!*colon!* do
            varlst := append(varlst, list xread 'for);
        type := declarestat1();
        res := append(res, list(type . varlst));
        if cursym!* eq '!*semicol!* then scan()
    >>;
    scan()
>>
else
<<
    varlst := list xread1 'for;
    while cursym!* neq '!*colon!* do
        varlst := append(varlst, list xread 'for);
    type := declarestat1();
    res := list (type . varlst);
>>;
if not endofstmtp() then
    gentranerr('e, nil, "INVALID SYNTAX", nil);
return ('declare . res)
end$

procedure declarestat1;
begin
scalar res;
scan();
if endofstmtp() then
    return nil;
if cursym!* eq 'implicit then
<<
    scan();
    res := intern compress append(explode 'implicit! , explode cursym!*)
>>
else
    res := cursym!*;
scan();
if cursym!* eq 'times then
<<
    scan();
    if numberp cursym!* then
    <<
        res := intern compress append(append(explode res, explode '!*),
                                      explode cursym!*);
        scan()
    >>
    else
        gentranerr('e, nil, "INVALID SYNTAX", nil)
>>;
return res
end$


procedure literalstat;
%                             %
% LITERAL arg1,arg2,...,argn; %
%                             %
begin
scalar res;
repeat
    res := append(res, list xread t)
until endofstmtp();
if atom res then
    return list('literal, res)
else if car res eq '!*comma!* then
    return rplaca(res, 'literal)
else
    return('literal . res)
end$


%%                           %%
%%  Symbolic Mode Functions  %%
%%                           %%


procedure sym!-gentran form;
eval formgentran(list('gentran, form, nil), !*vars!*, !*mode)$

procedure sym!-gentranin flist;
eval formgentran(list('gentranin,
                      if atom flist then list flist else flist,
                      nil),
                 !*vars!*, !*mode)$

procedure sym!-gentranout flist;
eval formgentran(list('gentranoutpush,
                      if atom flist then list flist else flist),
                 !*vars!*, !*mode)$

procedure sym!-gentranshut flist;
eval formgentran(list('gentranshut,
                      if atom flist then list flist else flist),
                 !*vars!*, !*mode)$

procedure sym!-gentranpush flist;
eval formgentran(list('gentranoutpush,
                      if atom flist then list flist else flist),
                 !*vars!*, !*mode)$

procedure sym!-gentranpop flist;
eval formgentran(list('gentranpop,
                      if atom flist then list flist else flist),
                 !*vars!*, !*mode)$


%%                           %%
%%  Form Analysis Functions  %%
%%                           %%


procedure formgentran(u, vars, mode);
(car u) . foreach arg in cdr u collect formgentran1(arg, vars, mode)$

procedure formgentran1(u, vars, mode);
if pairp u and not listp u then
    gentranerr('e, u, "SCALAR DEFINITIONS CANNOT BE TRANSLATED", nil)
else
if atom u then
    mkquote u
else if car u eq 'eval then
    list('aeval, form1(cadr u, vars, mode))
else if car u memq '(lsetq rsetq lrsetq) then
    % (LSETQ (var s1 s2 ... sn) exp)                                 %
    %   -> (SETQ (var (EVAL s1) (EVAL s2) ... (EVAL sn)) exp)        % 
    % (RSETQ var exp)                                                %
    %   -> (SETQ var (EVAL exp))                                     %
    % (LRSETQ (var s1 s2 ... sn) exp)                                %
    %   -> (SETQ (var (EVAL s1) (EVAL s2) ... (EVAL sn)) (EVAL exp)) %
    begin
    scalar op, lhs, rhs;
    op := car u;
    lhs := cadr u;
    rhs := caddr u;
    if op memq '(lsetq lrsetq) and listp lhs then
        lhs := car lhs . foreach s in cdr lhs collect list('eval, s);
    if op memq '(rsetq lrsetq) then
        rhs := list('eval, rhs);
    return formgentran1(list('setq, lhs, rhs), vars, mode)
    end
else
    'list . foreach elt in u
                collect formgentran1(elt, vars, mode)$


%%                     %%
%%  Control Functions  %%
%%                     %%


%%  Command Control Functions  %%


procedure gentran(forms, flist);
begin
if flist then
    eval list('gentranoutpush, list('quote, flist));
forms := preproc list forms;
gentranparse forms;
forms := lispcode forms;
%%IF !*GENTRANOPT THEN forms := Opt forms;
if !*gentranseg then forms := seg forms;
if gentranlang!* eq 'ratfor then
    formatrat ratcode forms
else if gentranlang!* eq 'c then
    formatc ccode forms
else
    formatfort fortcode forms;
if flist then
<<
    flist := car !*currout!* or ('list . cdr !*currout!*);
    eval '(gentranpop '(nil));
    return flist
>>
else
    return car !*currout!* or ('list . cdr !*currout!*)
end$


procedure gentranin(inlist, outlist);
begin
scalar ich;
foreach f in inlist do
    if listp f then
        gentranerr('e, f, "Wrong Type of Arg", nil)
    else if not !*filep!* f and f neq car !*stdin!* then
        gentranerr('e, f, "Nonexistent Input File", nil);
if outlist then
    eval list('gentranoutpush, mkquote outlist);
ich := rds nil;
foreach f in inlist do
<<
    if f = car !*stdin!* then
        pushinputstack !*stdin!*
    else if retrieveinputfilepair f then
        gentranerr('e, f, "Template File Already Open for Input", nil)
    else
        pushinputstack makeinputfilepair f;
    rds cdr !*currin!*;
    if gentranlang!* eq 'ratfor then
        procrattem()
    else if gentranlang!* eq 'c then
        procctem()
    else
        procforttem();
    rds ich;
    popinputstack()
>>;
if outlist then
<<
    outlist := car !*currout!* or ('list . cdr !*currout!*);
    eval '(gentranpop '(nil));
    return outlist
>>
else
    return car !*currout!* or ('list . cdr !*currout!*)
end$


procedure gentranoutpush flist;
<<
    if onep length (flist := fargstonames(flist, t)) then
        flist := car flist;
    pushoutputstack (retrieveoutputfilepair flist
                        or makeoutputfilepair flist);
    car !*currout!* or ('list . cdr !*currout!*)
>>$


procedure gentranshut flist;
%  close, delete, [output to T]  %
begin
scalar trm;
flist := fargstonames(flist, nil);
trm := if onep length flist then (car flist = car !*currout!*)
       else if car !*currout!*
        then (if car !*currout!* member flist then t)
       else eval('and . foreach f in cdr !*currout!*
                                collect (if f member flist then t));
deletefromoutputstack flist;
if trm and !*currout!* neq !*stdout!* then
    pushoutputstack !*stdout!*;
return car !*currout!* or ('list . cdr !*currout!*)
end$


procedure gentranpop flist;
<<
    if 'all!* member flist then
        while !*outstk!* neq list !*stdout!* do
            eval '(gentranpop '(nil))
    else
    <<
        flist := fargstonames(flist,nil);
        if onep length flist then
            flist := car flist;
        popoutputstack flist
    >>;
    car !*currout!* or ('list . cdr !*currout!*)
>>$


%%  Mode Switch Control Function  %%


procedure gendecs name;
%                      %
% ON/OFF GENDECS;      %
%                      %
% GENDECS subprogname; %
%                      %
<<
    if name equal 0 then name := nil;
    if gentranlang!* eq 'ratfor then
        formatrat ratdecs symtabget(name, '!*decs!*)
    else if gentranlang!* eq 'c then
        formatc cdecs symtabget(name, '!*decs!*)
    else
        formatfort fortdecs symtabget(name, '!*decs!*);
    symtabrem(name, nil);
    symtabrem(name, '!*decs!*)
>>$


%%  Misc. Control Functions  %%


procedure gentranpairs prs;
%                              %
% GENTRANPAIRS dottedpairlist; %
%                              %
if gentranlang!* eq 'ratfor then
    for each pr in prs do
        formatrat mkfratassign(lispcodeexp(car pr, !*period),
                               lispcodeexp(cdr pr, !*period))
else if gentranlang!* eq 'c then
    for each pr in prs do
        formatc mkfcassign(lispcodeexp(car pr, !*period),
                           lispcodeexp(cdr pr, !*period))
else
    for each pr in prs do
        formatfort mkffortassign(lispcodeexp(car pr, !*period),
                                 lispcodeexp(cdr pr, !*period))$


%%                                                  %%
%% Input & Output File Stack Manipulation Functions %%
%%                                                  %%


%%  Input Stack Manipulation Functions  %%


procedure makeinputfilepair fname;
(fname . open(mkfil fname, 'input))$

procedure retrieveinputfilepair fname;
retrievefilepair(fname, !*instk!*)$

procedure pushinputstack pr;
<<
    !*instk!* := pr . !*instk!*;
    !*currin!* := car !*instk!*;
    !*instk!*
>>$

procedure popinputstack;
begin scalar x;
x := !*currin!*;
if cdr !*currin!* then close cdr !*currin!*;
!*instk!* := cdr !*instk!* or list !*stdin!*;
!*currin!* := car !*instk!*;
return x
end$


%%  Output File Stack Manipulation Functions  %%


procedure makeoutputfilepair f;
if atom f then
    (f . open(mkfil f, 'output))
else
    aconc((nil . f) .
          foreach fn in f
                  conc if not retrieveoutputfilepair fn
                          then list makeoutputfilepair fn,
          (nil . nil))$

procedure retrieveoutputfilepair f;
if atom f
   then retrievefilepair(f, !*outstk!*)
   else retrievepfilepair(f, !*outstk!*)$

procedure pushoutputstack pr;
<<
    !*outstk!* := if atom cdr pr
                     then (pr . !*outstk!*)
                     else append(pr, !*outstk!*);
    !*currout!* := car !*outstk!*;
    !*outchanl!* := if car !*currout!*
                       then list cdr !*currout!*
                       else foreach f in cdr !*currout!*
                                   collect cdr retrieveoutputfilepair f;
    !*outstk!*
>>$

procedure popoutputstack f;
%  [close], remove top-most exact occurrence, reset vars  %
begin
scalar pr, s;
if atom f then
<<
    pr := retrieveoutputfilepair f;
    while !*outstk!* and car !*outstk!* neq pr do
        if caar !*outstk!* then
        <<s := aconc(s, car !*outstk!*);  !*outstk!* := cdr !*outstk!*>>
        else
        <<
            while car !*outstk!* neq (nil . nil) do
            <<  s := aconc(s, car !*outstk!*);
                !*outstk!* := cdr !*outstk!* >>;
                s := aconc(s, car !*outstk!*);
                !*outstk!* := cdr !*outstk!*
        >>;
    if !*outstk!* then s := append(s, cdr !*outstk!*);
    !*outstk!* := s;
    if not retrieveoutputfilepair f then close cdr pr
>>
else
<<
    pr := foreach fn in f collect retrieveoutputfilepair fn;
    while !*outstk!* and not filelistequivp(cdar !*outstk!*, f) do
        if caar !*outstk!* then
        <<  s := aconc(s, car !*outstk!*);
            !*outstk!* := cdr !*outstk!*  >>
        else
        <<
            while car !*outstk!* neq (nil . nil) do
            <<  s := aconc(s, car !*outstk!*);
                !*outstk!* := cdr !*outstk!* >>;
                s := aconc(s, car !*outstk!*);
                !*outstk!* := cdr !*outstk!*
        >>;
    if !*outstk!* then
    <<
        while car !*outstk!* neq (nil . nil) do
           !*outstk!* := cdr !*outstk!*;
        s := append(s, cdr !*outstk!*)
    >>;
    !*outstk!* := s;
    foreach fn in f do pr := delete(retrieveoutputfilepair fn, pr);
    foreach p in pr do close cdr p
>>;
!*outstk!* := !*outstk!* or list !*stdout!*;
!*currout!* := car !*outstk!*;
!*outchanl!* := if car !*currout!*
                   then list cdr !*currout!*
                   else foreach fn in cdr !*currout!*
                                collect cdr retrieveoutputfilepair fn;
return f
end$

procedure deletefromoutputstack f;
begin
scalar s, pr;
    if atom f then
    <<
        pr := retrieveoutputfilepair f;
        while retrieveoutputfilepair f do
            !*outstk!* := delete(pr, !*outstk!*);
        close cdr pr;
        foreach pr in !*outstk!* do
            if listp cdr pr and f member cdr pr then
                rplacd(pr, delete(f, cdr pr))
    >>
    else
    <<
        foreach fn in f do
            deletefromoutputstack fn;
        foreach fn in f do
            foreach pr in !*outstk!* do
                if listp cdr pr and fn member cdr pr then
                    rplacd(pr, delete(fn, cdr pr))
    >>;
    while !*outstk!* do
        if caar !*outstk!* and caar !*outstk!* neq 't then
        <<
            s := aconc(s, car !*outstk!*);
            !*outstk!* := cdr !*outstk!*
        >>
        else if cdar !*outstk!* and cdar !*outstk!* neq '(t) then
        <<
            while car !*outstk!* neq (nil . nil) do
            <<
                s := aconc(s, car !*outstk!*);
                !*outstk!* := cdr !*outstk!*
            >>;
            s := aconc(s, car !*outstk!*);
            !*outstk!* := cdr !*outstk!*
        >>
        else
            !*outstk!* := cddr !*outstk!*;
    !*outstk!* := s or list !*stdout!*;
    !*currout!* := car !*outstk!*;
    !*outchanl!* := if car !*currout!*
                       then list cdr !*currout!*
                       else foreach fn in cdr !*currout!*
                                 collect cdr retrieveoutputfilepair fn;
return f
end$


procedure retrievefilepair(fname, stk);
if null stk then
    nil
else if caar stk and mkfil fname = mkfil caar stk then
    car stk
else
    retrievefilepair(fname, cdr stk)$

procedure retrievepfilepair(f, stk);
if null stk then
    nil
else if null caar stk and filelistequivp(f, cdar stk) then
    list(car stk, (nil . nil))
else
    retrievepfilepair(f, cdr stk)$

procedure filelistequivp(f1, f2);
if listp f1 and listp f2 then
<<
    f1 := foreach f in f1 collect mkfil f;
    f2 := foreach f in f2 collect mkfil f;
    while (car f1 member f2) do
    <<
        f2 := delete(car f1, f2);
        f1 := cdr f1
    >>;
    null f1 and null f2
>>$


%%

procedure !*filep!* f;
   not errorp errorset(list('close,
                            list('open,list('mkfil,mkquote f),''input)),
                       nil,nil)$

%%                                     %%
%% Scanning & Arg-Conversion Functions %%
%%                                     %%


procedure endofstmtp;
if cursym!* member '(!*semicol!* !*rsqb!* end) then t$

procedure fargstonames(fargs, openp);
begin
scalar names;
fargs :=
    for each a in fargs conc
        if a memq '(nil 0) then
            if car !*currout!* then
                list car !*currout!*
            else
                cdr !*currout!*
        else if a eq 't then
            list car !*stdout!*
        else if a eq 'all!* then
            for each fp in !*outstk!* conc
               (if car fp and not(fp equal !*stdout!*) then list car fp)
        else if atom a then
            if openp then
            <<
                if !*filep!* a and null assoc(a, !*outstk!*) then
                    gentranerr('w, a, "OUTPUT FILE ALREADY EXISTS",
                               "CONTINUE?");
                list a
            >>
            else
                if retrieveoutputfilepair a then
                    list a
                else
                    gentranerr('w, a, "File not Open for Output", nil)
        else
            gentranerr('e, a, "WRONG TYPE OF ARG", nil);
repeat
    if not (car fargs member names) then
        names := append(names, list car fargs)
until null (fargs := cdr fargs);
return names
end$

procedure readfargs;
begin
scalar f;
while not endofstmtp() do
    f := append(f, list xread t);
return f or list nil
end$


endmodule;


module templt;    %%  GENTRAN Template Processing Routines  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Points:  ProcCTem, ProcFortTem, ProcRatTem


symbolic$

% User-Accessible Global Variables %
global '(gentranlang!* !*gendecs !$!#)$
share 'gentranlang!*, '!$!#$
gentranlang!* := 'fortran$
!$!# := 0$
switch gendecs$

global '(!*space!* !*stdout!* !$eof!$ !$eol!$)$
        % GENTRAN Global Variables      %

!*space!* := '! $

fluid '(!*mode)$


%%                          %%
%% Text Processing Routines %%
%%                          %%


%% FORTRAN %%


procedure procforttem;
begin
scalar c, linelen;
linelen := linelength 150;
c := procfortcomm();
while c neq !$eof!$ do
    if c memq '(!F !f !S !s) then
    <<
        pprin2 c;
        c := procsubprogheading c
    >>
    else if c eq !$eol!$ then
    <<
        pterpri();
        c := procfortcomm()
    >>
    else if c eq '!; then
        c := procactive()
    else
    <<
        pprin2 c;
        c := readch()
    >>;
linelength linelen
end$

procedure procfortcomm;
% <col 1>C ... <cr> %
% <col 1>c ... <cr> %
begin
scalar c;
while (c := readch()) memq '(!C !c) do
<<
    pprin2 c;
    repeat
        if (c := readch()) neq !$eol!$ then
           pprin2 c
    until c eq !$eol!$;
    pterpri()
>>;
return c
end$


%% RATFOR %%


procedure procrattem;
begin
scalar c, linelen;
linelen := linelength 150;
c := readch();
while c neq !$eof!$ do
    if c memq '(!F !f !S !s) then
    <<
        pprin2 c;
        c := procsubprogheading c
    >>
    else if c eq '!# then
        c := procratcomm()
    else if c eq '!; then
        c := procactive()
    else if c eq !$eol!$ then
    <<
        pterpri();
        c := readch()
    >>
    else
    <<
        pprin2 c;
        c := readch()
    >>;
linelength linelen
end$

procedure procratcomm;
% # ... <cr> %
begin
scalar c;
pprin2 '!#;
while (c := readch()) neq !$eol!$ do
    pprin2 c;
pterpri();
return readch()
end$


%%


procedure procsubprogheading c;
begin
scalar lst, name, i, propname;
lst := if c memq '(!F !f)
          then '((!U !u) (!N !n) (!C !c) (!T !t) (!I !i) (!O !o)
                 (!N !n))
          else '((!U !u) (!B !b) (!R !r) (!O !o) (!U !u)
                 (!T !t) (!I !i) (!N !n) (!E !e));
while lst and (c := readch()) memq car lst do
<<  pprin2 c;  lst := cdr lst  >>;
if lst then return c;
while seprp(c := readch()) do
    if c eq !$eol!$
        then pterpri()
        else pprin2 c;
while not(seprp c or c eq '!() do
<<  name := aconc(name, c);  pprin2 c;  c := readch()  >>;
name := intern compress name;
if not !*gendecs then
    symtabput(name, nil, nil);
propname := if gentranlang!* eq 'fortran
               then '!*fortranname!*
               else '!*ratforname!*;
put('!$0, propname, name);
while seprp c do
<<
    if c eq !$eol!$
        then pterpri()
        else pprin2 c;
    c := readch()
>>;
if c neq '!( then return c;
i := 1;
pprin2 c;
c := readch();
while c neq '!) do
<<
    while seprp c or c eq '!, do
    << 
        if c eq !$eol!$
            then pterpri()
            else pprin2 c;
        c := readch()
    >>;
    name := list c;
    pprin2 c;
    while not (seprp (c := readch()) or c memq list('!,, '!))) do
    <<  name := aconc(name, c);  pprin2 c  >>;
    put(intern compress append(explode2 '!$, explode2 i),
        propname,
        intern compress name);
    i := add1 i;
    while seprp c do
    <<
        if c eq !$eol!$
            then pterpri()
            else pprin2 c;
        c := readch()
    >>
>>;
!$!# := sub1 i;
while get(name := intern compress append(explode2 '!$, explode2 i),
          propname) do
    remprop(name, propname);
return c
end$


%% C %%


procedure procctem;
begin
scalar c, linelen;
linelen := linelength 150;
c := readch();
if c eq '!# then c := procc!#line c;
while c neq !$eof!$ do
    if c eq !$eol!$ then
        c := procc!#line c
    else if c eq '!/ then
        c := procccomm()
    else if c eq '!; then
        c := procactive()
    else
        c := proccheader(c);
linelength linelen
end$

procedure procc!#line c;
%  # ... <cr>  %
begin
if c eq !$eol!$ then
<<  pterpri();  c := readch()  >>;
if c eq '!# then
    repeat
    <<  pprin2 c;  c := readch()  >>
    until c eq !$eol!$;
return c
end$

procedure procccomm;
% /* ... */ %
begin
scalar c;
pprin2 '!/;
c := readch();
if c eq '!* then
<<
    pprin2 c;
    c := readch();
    repeat
    <<
        while c neq '!* do
        <<
            if c eq !$eol!$
                then pterpri()
                else pprin2 c;
            c := readch()
        >>;
        pprin2 c;
        c := readch()
    >>
    until c eq '!/;
    pprin2 c;
    c := readch()
>>;
return c
end$

procedure proccheader c;
begin
scalar name, i;
while seprp c and c neq !$eol!$ do
<<  pprin2 c;  c := readch()  >>;
while not(seprp c or c memq list('!/, '!;, '!()) do
<<  name := aconc(name, c);  pprin2 c;  c := readch()  >>;
if c memq list(!$eol!$, '!/, '!;) then return c;
while seprp c and c neq !$eol!$ do
<<  pprin2 c;  c := readch()  >>;
if c neq '!( then return c;
name := intern compress name;
if not !*gendecs then
    symtabput(name, nil, nil);
put('!$0, '!*cname!*, name);
pprin2 c;
i := 1;
c := readch();
while c neq '!) do
<<
    while seprp c or c eq '!, do
    <<
        if c eq !$eol!$
            then pterpri()
            else pprin2 c;
        c := readch()
    >>;
    name := list c;
    pprin2 c;
    while not(seprp (c := readch()) or c memq list('!,, '!))) do
    <<  name := aconc(name, c);  pprin2 c  >>;
    put(intern compress append(explode2 '!$, explode2 i),
        '!*cname!*,
        intern compress name);
    i := add1 i;
    while seprp c do
    <<
        if c eq !$eol!$
            then pterpri()
            else pprin2 c;
        c := readch()
    >>
>>;
!$!# := sub1 i;
while get(name := intern compress append(explode2 '!$, explode2 i),
          '!*cname!*) do
    remprop(name, '!*cname!*);
return proccfunction c
end$

procedure proccfunction c;
begin
scalar !{!}count;
while c neq '!{ do
    if c eq '!/ then
        c := procccomm()
    else if c eq '!; then
        c := procactive()
    else if c eq !$eol!$ then
    <<  pterpri();  c := readch()  >>
    else
    <<  pprin2 c;  c := readch()  >>;
pprin2 c;
!{!}count := 1;
c := readch();
while !{!}count > 0 do
    if c eq '!{ then
    <<  !{!}count := add1 !{!}count;  pprin2 c;  c := readch()  >>
    else if c eq '!} then
    <<  !{!}count := sub1 !{!}count;  pprin2 c;  c := readch()  >>
    else if c eq '!/ then
        c := procccomm()
    else if c eq '!; then
        c := procactive()
    else if c eq !$eol!$ then
    <<  pterpri();  c := readch()  >>
    else
    <<  pprin2 c;  c := readch()  >>;
return c
end$


%%                                   %%
%% Template File Active Part Handler %%
%%                                   %%


procedure procactive;
% active parts:  ;BEGIN; ... ;END; %
% eof markers:   ;END;             %
begin
scalar c, buf, mode, och;
c := readch();
if c eq 'e then
    if (c := readch()) eq 'n then
        if (c := readch()) eq 'd then
            if (c := readch()) eq '!; then
                return !$eof!$
            else buf := '!;end
        else buf := '!;en
    else buf := '!;e
else if c eq 'b then
    if (c := readch()) eq 'e then
        if (c := readch()) eq 'g then
            if (c := readch()) eq 'i then
                if (c := readch()) eq 'n then
                    if (c := readch()) eq '!; then
                    <<
                        mode := !*mode;
                        !*mode := 'algebraic;
                        och := wrs cdr !*stdout!*;
                        begin1();
                        wrs och;
                        !*mode := mode;
                        linelength 150;
                        return if (c := readch()) eq !$eol!$ 
                                  then readch()
                                  else c
                    >>
                    else buf := '!;begin
                else buf := '!;begi
            else buf := '!;beg
        else buf := '!;be
    else buf := '!;b
else buf := '!;;
pprin2 buf;
return c
end$


endmodule;


module pre;    %%  GENTRAN Preprocessing Module  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Point:  Preproc


symbolic$


procedure preproc exp;
begin
scalar r;
r := preproc1 exp;
if r then
    return car r
else
    return r
end$

procedure preproc1 exp;
if atom exp then
    list exp
else if car exp eq '!*sq then
    % (!*SQ dpexp) --> (PREPSQ dpexp) %
    preproc1 prepsq cadr exp
else if car exp eq 'procedure then
<<
    % Store subprogram name & parameters in symbol table %
    symtabput(cadr exp, '!*params!*, car cddddr exp);
    list for each e in exp
             conc preproc1 e
>>
else if car exp eq 'declare then
<<
    % Store type declarations in symbol table %
    exp := car preproc1 cdr exp;
    exp := preprocdec exp;
    for each dec in exp do
        for each var in cdr dec do
            if car dec memq '(subroutine function) then
                symtabput(var, '!*type!*, car dec)
            else
                symtabput(nil,
                          if atom var then var else car var,
                          if atom var then list car dec
                                      else (car dec . cdr var));
    nil
>>
else
    list for each e in exp
             conc preproc1 e$


procedure preprocdec arg;
% (TIMES type int) --> type!*int     %
% (IMPLICIT type) --> IMPLICIT! type %
% (DIFFERENCE v1 v2) --> v1!-v2      %
if atom arg then
    arg
else if car arg eq 'times then
    intern
         compress
            append( append( explode cadr arg, explode '!* ),
                    explode caddr arg )
else if car arg eq 'implicit then
    intern
        compress
            append( explode 'implicit! , explode preprocdec cadr arg )
else if car arg eq 'difference then
    intern
        compress
            append( append( explode cadr arg, explode '!- ),
                    explode caddr arg )
else
    for each a in arg collect
        preprocdec a$


endmodule;


module gparser;    %%  GENTRAN Parser Module  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Point:  GentranParse


symbolic$

% GENTRAN Global Variable %
global '(!*reservedops!*)$
!*reservedops!* := '(and block cond difference equal expt for geq go
                     greaterp leq lessp mat minus neq not or plus
                     procedure progn quotient read recip repeat return
                     setq times while write)$ %reserved operators


procedure gentranparse forms;
for each f in forms do
    if not(gpstmtp f or gpexpp f or gpdefnp f) then
        gentranerr('e, f, "CANNOT BE TRANSLATED", nil)$

procedure gpexpp exp;
%  exp  ::=  id | number | (PLUS exp exp') | (MINUS exp) |             %
%         (DIFFERENCE exp exp) | (TIMES exp exp exp') |                %
%         (RECIP exp) |(QUOTIENT exp exp) | (EXPT exp exp) | (id arg') %
if atom exp then
    idp exp or numberp exp
else
    if car exp eq 'plus then
        length exp >= 2 and gpexpp cadr exp and gpexp1p cddr exp
    else if car exp memq '(minus recip) then
        length exp=2 and gpexpp cadr exp
    else if car exp memq '(difference quotient expt) then
        length exp=3 and gpexpp cadr exp and gpexpp caddr exp
    else if car exp eq 'times then
        length exp >= 3 and gpexpp cadr exp and gpexpp caddr exp and
         gpexp1p cdddr exp
    else if unresidp car exp then
        gparg1p cdr exp$

procedure gpexp1p exp;
%  exp'  ::=  exp exp' | eps  %
null exp or (gpexpp car exp and gpexp1p cdr exp)$

procedure gplogexpp exp;
%  logexp  ::=  id | (EQUAL exp exp) | (NEQ exp exp) |                 %
%            (GREATERP exp exp) |(GEQ exp exp) | (LESSP exp exp) |     %
%            (LEQ exp exp) | (NOT logexp) | (AND logexp logexp logexp')%
%            | (OR logexp logexp logexp') | (id arg')                  %
if atom exp then
    idp exp
else
    if car exp memq '(equal neq greaterp geq lessp leq) then
        length exp=3 and gpexpp cadr exp and gpexpp caddr exp
    else if car exp eq 'not then
        length exp=2 and gplogexpp cadr exp
    else if car exp memq '(and or) then
        length exp >= 3 and gplogexpp cadr exp and gplogexpp caddr exp
        and gplogexp1p cdddr exp
    else if unresidp car exp then
        gparg1p cdr exp$

procedure gplogexp1p exp;
%  logexp'  ::=  logexp logexp' | eps  %
null exp or (gplogexpp car exp and gplogexp1p cdr exp)$

procedure gpargp exp;
%  arg  ::=  string | exp | logexp  %
stringp exp or gpexpp exp or gplogexpp exp$

procedure gparg1p exp;
%  arg'  ::=  arg arg' | eps  %
null exp or (gpargp car exp and gparg1p cdr exp)$

procedure gpvarp exp;
%  var  ::=  id | (id exp exp')  %
if atom exp then
    idp exp
else
    if unresidp car exp then
        length exp >= 2 and gpexpp cadr exp and gpexp1p cddr exp$

procedure gplistp exp;
%  list  ::=  (exp exp')  %
if listp exp then
    length exp >= 1 and gpexpp car exp and gpexp1p cdr exp$

procedure gplist1p exp;
%  list'  ::=  list list' | eps  %
null exp or (gplistp car exp and gplist1p cdr exp)$

procedure gpid1p exp;
%  id'  ::=  id id' | eps  %
null exp or (idp car exp and gpid1p cdr exp)$

procedure gpstmtp exp;
%  stmt  ::=  id | (SETQ setq') | (COND cond') | (WHILE logexp stmt) | %
%             (REPEAT stmt logexp) | (FOR var (exp exp exp) DO stmt) | %
%             (GO id) | (RETURN arg) | (WRITE arg arg') |              %
%             (PROGN stmt stmt') | (BLOCK (id') stmt') | (id arg')     %
if atom exp then
    idp exp
else
    if car exp eq 'setq then
        gpsetq1p cdr exp
    else if car exp eq 'cond then
        gpcond1p cdr exp
    else if car exp eq 'while then
        length exp=3 and gplogexpp cadr exp and gpstmtp caddr exp
    else if car exp eq 'repeat then
        length exp=3 and gpstmtp cadr exp and gplogexpp caddr exp
    else if car exp eq 'for then
        length exp=5 and gpvarp cadr exp and listp caddr exp and
         (length caddr exp=3 and gpexpp car caddr exp and
          gpexpp cadr caddr exp and gpexpp caddr caddr exp) and
           cadddr exp eq 'do and gpstmtp car cddddr exp
    else if car exp eq 'go then
        length exp=2 and idp cadr exp
    else if car exp eq 'return then
        length exp=2 and gpargp cadr exp
    else if car exp eq 'write then
        length exp >= 2 and gpargp cadr exp and gparg1p cddr exp
    else if car exp eq 'progn then
        length exp >= 2 and gpstmtp cadr exp and gpstmt1p cddr exp
    else if car exp eq 'block then
        length exp >= 2 and gpid1p cadr exp and gpstmt1p cddr exp
    else if unresidp car exp then
        gparg1p cdr exp$

procedure gpsetq1p exp;
%  setq'  ::=  id setq'' | (id exp exp') setq'''  %
if exp and length exp=2 then
    if atom car exp then
        idp car exp and gpsetq2p cdr exp
    else
        (length car exp >= 2 and idp car car exp
             and unresidp car car exp and gpexpp cadr car exp
             and gpexp1p cddr car exp) and gpsetq3p cdr exp$

procedure gpsetq2p exp;
%  setq''  ::=  (MAT list list') | setq'''  %
if exp then
    if listp car exp and caar exp eq 'mat then
        onep length exp and (gplistp cadar exp and gplist1p cddar exp)
    else
        gpsetq3p exp$

procedure gpsetq3p exp;
% setq''' ::= (FOR var (exp exp exp) forop exp) | (READ) | exp | logexp
if exp and onep length exp then
    gpexpp car exp or
     gplogexpp car exp or
        (if caar exp eq 'for then
            length car exp=5 and gpvarp cadar exp and
             (listp caddar exp and length caddar exp=3 and
              gpexpp car caddar exp and gpexpp cadr caddar exp and
               gpexpp caddr caddar exp) and gpforopp car cdddar exp and
                gpexpp cadr cdddar exp
        else if caar exp eq 'read then
            onep length car exp)$

procedure gpforopp exp;
%  forop  ::=  SUM | PRODUCT  %
exp memq '(sum product)$

procedure gpcond1p exp;
%  cond'  ::=  (logexp stmt) cond' | eps  %
null exp or
    (listp car exp and length car exp=2 and gplogexpp caar exp and
     gpstmtp cadar exp and gpcond1p cdr exp)$

procedure gpstmt1p exp;
%  stmt'  ::=  stmt stmt' | eps  %
null exp or (gpstmtp car exp and gpstmt1p cdr exp)$

procedure gpdefnp exp;
%  defn  ::=  (PROCEDURE id NIL EXPR (id') stmt)  %
listp exp and car exp eq 'procedure and length exp=6 and
 idp cadr exp and null caddr exp and atom cadddr exp and
  gpid1p car cddddr exp and gpstmtp cadr cddddr exp
   and not idp cadr cddddr exp$


%%            %%
%% Predicates %%
%%            %%


procedure unresidp id;
not (id memq !*reservedops!*)$


endmodule;


module redlsp;    %%  GENTRAN LISP Code Generation Module  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Point:  LispCode


symbolic$

% GENTRAN Global Variables %
global '(!*lisparithexpops!* !*lisplogexpops!* !*redarithexpops!*
        !*redlogexpops!* !*redreswds!* !*redstmtgpops!* !*redstmtops!*)$
!*redarithexpops!*:= '(difference expt minus plus quotient recip times)$
!*redlogexpops!*   := '(and equal geq greaterp leq lessp neq not or)$
!*redreswds!* := '(and block cond de difference end equal expt !~for for
                   geq getel go greaterp leq lessp list minus neq not or
                   plus plus2 prog progn procedure quotient read recip
                   repeat return setel setk setq stop times times2
                   while write)$ %REDUCE reserved words
!*redstmtgpops!*   := '(block progn)$
!*redstmtops!*     := '(cond end !~for for go repeat return setq stop
                        while write)$

% REDUCE Global Variable %
global '(!*period)$

global '(!*do!* !*for!*)$


procedure lispcode forms;
for each f in forms collect
    if redexpp f then
        lispcodeexp(f, !*period)
    else if redstmtp f or redstmtgpp f then
        lispcodestmt f
    else if reddefp f then
        lispcodedef f
    else if listp f then
        for each e in f collect lispcode e$

procedure lispcodeexp(form, fp);
% (RECIP exp) ==> (QUOTIENT 1.0 exp)                   %
% (DIFFERENCE exp1 exp2) ==> (PLUS exp1 (MINUS exp2))  %
% integer ==> floating point  iff  PERIOD flag is ON & %
%                                  not exponent &      %
%                                  not subscript &     %
%                                  not loop index      %
if numberp form then
    if fp then
        float form
    else
        form
else if atom form then
    form
else if car form eq 'expt then
    list('expt, lispcodeexp(cadr form, fp),
         lispcodeexp(caddr form, nil))
else if car form eq 'recip then
    if fp then
        list('quotient, 1.0, lispcodeexp(cadr form, fp))
    else
        list('quotient, 1, lispcodeexp(cadr form, fp))
else if car form eq 'difference then
    list('plus, lispcodeexp(cadr form, fp),
                list('minus, lispcodeexp(caddr form, fp)))
else if not car form memq !*lisparithexpops!* and
        not car form memq !*lisplogexpops!* then
    for each elt in form collect lispcodeexp(elt, nil)
else
    for each elt in form collect lispcodeexp(elt, fp)$


procedure lispcodestmt form;
if atom form then
    form
else if redassignp form then
    lispcodeassign form
else if redreadp form then
    lispcoderead form
else if redprintp form then
    lispcodeprint form
else if redwhilep form then
    lispcodewhile form
else if redrepeatp form then
    lispcoderepeat form
else if redforp form then
    lispcodefor form
else if redcondp form then
    lispcodecond form
else if redreturnp form then
    lispcodereturn form
else if redstmtgpp form then
    lispcodestmtgp form
else if reddefp form then
    lispcodedef form
else if car form eq 'literal then
    for each elt in form collect lispcodeexp(elt, nil)
else
    for each elt in form collect lispcodeexp(elt, !*period)$


procedure lispcodeassign form;
% (SETQ var (MAT lst lst')) --> (PROGN (SETQ (var 1 1) exp11)          %
%                                      (SETQ (var 1 2) exp12)          %
%                                       .                              %
%                                       .                              %
%                                      (SETQ (var m n) expmn))         %
if listp caddr form and caaddr form eq 'mat then
    begin
    scalar name, r, c, relts, result;
    name := cadr form;
    form := caddr form;
    r := c := 1;
    while form := cdr form do
    <<
        relts := car form;
        repeat
        <<
            result := mkassign(list(name, r, c),
                               lispcodeexp(car relts, !*period))
                                  . result;
            c := add1 c
        >>
        until null(relts := cdr relts);
        r := add1 r;
        c := 1
    >>;
    return mkstmtgp(nil, reverse result)
    end
else
    mkassign(lispcodeexp(cadr form, !*period),
             lispcodeexp(caddr form, !*period))$

procedure lispcoderead form;
% (SETQ var (READ)) --> (READ var) %
list('read, lispcodeexp(cadr form, nil))$

procedure lispcodeprint form;
'write . for each elt in cdr form collect lispcodeexp(elt, !*period)$

procedure lispcodewhile form;
'while . lispcodeexp(cadr form, !*period) .
         foreach st in cddr form collect lispcodestmt st$

procedure lispcoderepeat form;
begin
scalar body, logexp;
body := reverse cdr form;
logexp := car body;
body := reverse cdr body;
return 'repeat . append(foreach st in body collect lispcodestmt st,
                        list lispcodeexp(logexp, !*period))
end$

procedure lispcodefor form;
% (SETQ var1 (FOR var (exp1 exp2 exp3) SUM exp))
%   --> (PROGN (SETQ var1 0/0.0)
%             (FOR var (exp1 exp2 exp3) DO (SETQ var1 (PLUS var1 exp))))
% (SETQ var1 (FOR var (exp1 exp2 exp3) PRODUCT exp))
%   --> (PROGN (SETQ var1 1/1.0)
%            (FOR var (exp1 exp2 exp3) DO (SETQ var1 (TIMES var1 exp))))
if car form eq 'for then
    begin
    scalar explst, stmtlst;
    explst := list(cadr form, caddr form);
    stmtlst := cddddr form;
    return append(!*for!* .
                    foreach exp in explst collect lispcodeexp(exp, nil),
                  !*do!* .
                    foreach st in stmtlst collect lispcodestmt st)
    end
else
    begin
    scalar var1, var, explst, op, exp;
    var1 := cadr form;
    form := caddr form;
    var := cadr form;
    explst := caddr form;
    if cadddr form eq 'sum then
        op := 'plus
    else
        op := 'times;
    exp := car cddddr form;
    form := list('prog, nil,
                 list('setq, var1, if op eq 'plus then 0 else 1),
                 list(!*for!*, var, explst, !*do!*,
                      list('setq, var1, list(op, var1, exp))));
    return lispcodestmt form
    end$

procedure lispcodecond form;
begin
scalar result, pr;
while form := cdr form do
<<
    pr := car form;
    pr := lispcodeexp(car pr, !*period)
            . for each stmt in cdr pr collect lispcodestmt stmt;
    result := pr . result
>>;
return mkcond reverse result
end$

procedure lispcodereturn form;
% (RETURN NIL) --> (RETURN) %
if form member '((return) (return nil)) then
    list 'return
else
    mkreturn lispcodeexp(cadr form, !*period)$

procedure lispcodestmtgp form;
% (BLOCK () stmt1 stmt2 .. stmtm)      %
%   --> (PROG () stmt1 stmt2 .. stmtm) %
if car form memq '(prog block) then
    mkstmtgp(cadr form,
             for each stmt in cddr form collect lispcodestmt stmt)
else
    mkstmtgp(0, for each stmt in cdr form collect lispcodestmt stmt)$

procedure lispcodedef form;
% (PROCEDURE id NIL EXPR (p1 p2 .. pn) stmt') %
%   --> (DEFUN id (p1 p2 .. pn) stmt')        %
if car form eq 'procedure then
    mkdef(cadr form, car cddddr form, for each stmt in cdr cddddr form
                                              collect lispcodestmt stmt)
else
    mkdef(cadr form, caddr form, for each stmt in cdddr form
                                          collect lispcodestmt stmt)$


%% REDUCE Form Predicates %%


procedure redassignp form;
listp form and car form eq 'setq and redassign1p caddr form$

procedure redassign1p form;
if atom form then
    t
else if car form eq 'setq then
    redassign1p caddr form
else if car form memq '(read for) then
    nil
else
    t$

procedure redcondp form;
listp form and car form eq 'cond$

procedure reddefp form;
listp form and car form eq 'procedure$

procedure redexpp form;
atom form or
car form memq !*redarithexpops!* or
car form memq !*redlogexpops!* or
not(car form memq !*redreswds!*)$

procedure redforp form;
if listp form then
    if car form eq 'for then
        t
    else if car form eq 'setq then
        redfor1p caddr form$

procedure redfor1p form;
if atom form then
    nil
else if car form eq 'setq then
    redfor1p caddr form
else if car form eq 'for then
    t$

procedure redprintp form;
listp form and car form eq 'write$

procedure redreadp form;
listp form and car form eq 'setq and redread1p caddr form$

procedure redread1p form;
if atom form then
    nil
else if car form eq 'setq then
    redread1p caddr form
else if car form eq 'read then
    t$

procedure redrepeatp form;
listp form and car form eq 'repeat$

procedure redreturnp form;
listp form and car form eq 'return$

procedure redstmtp form;
atom form or
car form memq !*redstmtops!* or
atom car form and not(car form memq !*redreswds!*)$

procedure redstmtgpp form;
listp form and car form memq !*redstmtgpops!*$

procedure redwhilep form;
listp form and car form eq 'while$


endmodule;


module segmnt;    %%  Segmentation Module  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry points:  Seg, MARKEDVARP, MARKVAR, TEMPVAR, UNMARKVAR


symbolic$

% User-Accessible Global Variables %
global '(gentranlang!* maxexpprintlen!* tempvarname!* tempvarnum!*
         tempvartype!*)$
share 'gentranlang!*, 'maxexpprintlen!*, 'tempvarname!*, 'tempvarnum!*,
      'tempvartype!*$
maxexpprintlen!* := 800$
tempvarname!*    := 't$
tempvarnum!*     := 0$
tempvartype!*    := nil$

% User-Accessible Primitive Functions %
operator markedvarp, markvar, tempvar, unmarkvar$

global '(!*do!* !*for!*)$


%%                       %%
%% Segmentation Routines %%
%%                       %%


procedure seg forms;
% exp --+--> exp                                          %
%       +--> (assign    assign    ... assign      exp   ) %
%                   (1)       (2)           (n-1)    (n)  %
% stmt --+--> stmt                                        %
%        +--> stmtgp                                      %
% stmtgp --> stmtgp                                       %
% def --> def                                             %
for each f in forms collect
    if lispexpp f then
        if toolongexpp f then
            segexp(f, 'unknown)
        else
            f
    else if lispstmtp f then
        segstmt f
    else if lispstmtgpp f then
        if toolongstmtgpp f then
            seggroup f
        else
            f
    else if lispdefp f then
        if toolongdefp f then
            segdef f
        else
            f
    else
        f$


procedure segexp(exp, type);
% exp --> (assign    assign    ... assign      exp   ) %
%                (1)       (2)           (n-1)    (n)  %
reverse segexp1(exp, type)$

procedure segexp1(exp, type);
% exp --> (exp    assign      assign      ... assign   ) %
%             (n)       (n-1)       (n-2)           (1)  %
begin
scalar res;
res := segexp2(exp, type);
unmarkvar res;
if car res = cadadr res then
<<
    res := cdr res;
    rplaca(res, caddar res)
>>;
return res
end$

procedure segexp2(exp, type);
% exp --> (exp    assign      assign      ... assign   ) %
%             (n)       (n-1)       (n-2)           (1)  %
begin
scalar expn, assigns, newassigns, unops, op, termlist, var, tmp;
expn := exp;
while length expn=2 do
<<  unops := car expn . unops;  expn := cadr expn  >>;
op := car expn;
for each term in cdr expn do
<<
    if toolongexpp term then
    <<
        tmp := segexp2(term, type);
        term := car tmp;
        newassigns := cdr tmp
    >>
    else
        newassigns := '();
    if toolongexpp (op . term . termlist) and
       termlist and
       (length termlist > 1 or listp car termlist) then
        <<
            unmarkvar termlist;
            var := var or tempvar type;
            markvar var;
            assigns := mkassign(var, if onep length termlist
                                        then car termlist
                                        else op . termlist) . assigns;
            termlist := list(var, term)
        >>
        else
            termlist := append(termlist, list term);
        assigns := append(newassigns, assigns)
>>;
expn := if onep length termlist
           then car termlist
           else op . termlist;
while unops do
<<  expn := list(car unops, expn);  unops := cdr unops  >>;
if expn = exp then
<<
    unmarkvar expn;
    var := var or tempvar type;
    markvar var;
    assigns := list mkassign(var, expn);
    expn := var
>>;
return expn . assigns
end$


procedure segstmt stmt;
% assign --+--> assign %
%          +--> stmtgp %
% cond --+--> cond     %
%        +--> stmtgp   %
% while --+--> while   %
%         +--> stmtgp  %
% repeat --> repeat    %
% for --+--> for       %
%       +--> stmtgp    %
% return --+--> return %
%          +--> stmtgp %
if lispassignp stmt then
    if toolongassignp stmt then
        segassign stmt
    else
        stmt
else if lispcondp stmt then
    if toolongcondp stmt then
        segcond stmt
    else
        stmt
else if lispwhilep stmt then
    if toolongwhilep stmt then
        segwhile stmt
    else
        stmt
else if lisprepeatp stmt then
    if toolongrepeatp stmt then
        segrepeat stmt
    else
        stmt
else if lispforp stmt then
    if toolongforp stmt then
        segfor stmt
    else
        stmt
else if lispreturnp stmt then
    if toolongreturnp stmt then
        segreturn stmt
    else
        stmt
else
    stmt$


procedure segassign stmt;
% assign --> stmtgp %
begin
scalar var, exp, type;
var := cadr stmt;
type := getvartype var;
exp := caddr stmt;
stmt := segexp1(exp, type);
rplaca(stmt, mkassign(var, car stmt));
return mkstmtgp(nil, reverse stmt)
end$

procedure segcond condd;
% cond --+--> cond   %
%        +--> stmtgp %
begin
scalar tassigns, res, markedvars, type;
if gentranlang!* eq 'c
    then type := 'int
    else type := 'logical;
while condd := cdr condd do
    begin
    scalar exp, stmt;
    if toolongexpp(exp := caar condd) then
    <<
        exp := segexp1(exp, type);
        tassigns := append(cdr exp, tassigns);
        exp := car exp;
        markvar exp;
        markedvars := exp . markedvars
    >>;
    stmt := for each st in cdar condd conc seg list st;
    res := (exp . stmt) . res
    end;
unmarkvar markedvars;
return
    if tassigns then
        mkstmtgp(nil, reverse(mkcond reverse res . tassigns))
    else
        mkcond reverse res
end$

procedure segwhile stmt;
% while --+--> while  %
%         +--> stmtgp %
begin
scalar logexp, stmtlst, tassigns, type, res;
logexp := cadr stmt;
stmtlst := cddr stmt;
if toolongexpp logexp then
<<
    if gentranlang!* eq 'c
       then type := 'int
       else type := 'logical;
    tassigns := segexp1(logexp, type);
    logexp := car tassigns;
    tassigns := cdr tassigns
>>;
stmtlst := foreach st in stmtlst
                   conc seg list st;
res := 'while . logexp . stmtlst;
if tassigns then
<<
    res := append(res, reverse tassigns);
    res := 'progn . append(reverse tassigns, list res)
>>;
return res
end$

procedure segrepeat stmt;
% repeat --> repeat %
begin
scalar stmtlst, logexp, type;
stmt := reverse cdr stmt;
logexp := car stmt;
stmtlst := reverse cdr stmt;
stmtlst := foreach st in stmtlst conc seg list st;
if toolongexpp logexp then
<<
    if gentranlang!* eq 'c
       then type := 'int
       else type := 'logical;
    logexp := segexp1(logexp, type);
    stmtlst := append(stmtlst, reverse cdr logexp);
    logexp := car logexp
>>;
return 'repeat . append(stmtlst, list logexp)
end$

procedure segfor stmt;
% for --+--> for    %
%       +--> stmtgp %
begin
scalar var, loexp, stepexp, hiexp, stmtlst, tassigns1, tassigns2, type,
       markedvars, res;
var := cadr stmt;
type := getvartype var;
stmt := cddr stmt;
loexp := caar stmt;
stepexp := cadar stmt;
hiexp := caddar stmt;
stmtlst := cddr stmt;
if toolongexpp loexp then
<<
    loexp := segexp1(loexp, type);
    tassigns1 := reverse cdr loexp;
    loexp := car loexp;
    markvar loexp;
    markedvars := loexp . markedvars
>>;
if toolongexpp stepexp then
<<
    stepexp := segexp1(stepexp, type);
    tassigns2 := reverse cdr stepexp;
    stepexp := car stepexp;
    markvar stepexp;
    markedvars := stepexp . markedvars
>>;
if toolongexpp hiexp then
<<
    hiexp := segexp1(hiexp, type);
    tassigns1 := append(tassigns1, reverse cdr hiexp);
    tassigns2 := append(tassigns2, reverse cdr hiexp);
    hiexp := car hiexp
>>;
unmarkvar markedvars;
stmtlst := foreach st in stmtlst conc seg list st;
stmtlst := append(stmtlst, tassigns2);
res := !*for!* . var . list(loexp, stepexp, hiexp) . !*do!* . stmtlst;
if tassigns1 then
    return mkstmtgp(nil, append(tassigns1, list res))
else
    return res
end$

procedure segreturn ret;
% return --> stmtgp %
<<
    ret := segexp1(cadr ret, 'unknown);
    rplaca(ret, mkreturn car ret);
    mkstmtgp(nil, reverse ret)
>>$

procedure seggroup stmtgp;
% stmtgp --> stmtgp %
begin
scalar locvars, res;
if car stmtgp eq 'prog then
<<
    locvars := cadr stmtgp;
    stmtgp := cdr stmtgp
>>
else
    locvars := 0;
while stmtgp := cdr stmtgp do
    res := append(seg list car stmtgp, res);
return mkstmtgp(locvars, reverse res)
end$

procedure segdef deff;
% def --> def %
mkdef(cadr deff, caddr deff,
      for each stmt in cdddr deff conc seg list stmt)$


%%                                        %%
%% Long Statement & Expression Predicates %%
%%                                        %%


procedure toolongexpp exp;
numprintlen exp > maxexpprintlen!*$

procedure toolongstmtp stmt;
if atom stmt then nil else
if lispstmtp stmt then
    if lispcondp stmt then
        toolongcondp stmt
    else if lispassignp stmt then
        toolongassignp stmt
    else if lispreturnp stmt then
        toolongreturnp stmt
    else if lispwhilep stmt then
        toolongwhilep stmt
    else if lisprepeatp stmt then
        toolongrepeatp stmt
    else if lispforp stmt then
        toolongforp stmt
    else
        eval('or . for each exp in stmt collect  toolongexpp exp)
else
    toolongstmtgpp stmt$

procedure toolongassignp assign;
toolongexpp caddr assign$

procedure toolongcondp condd;
begin
scalar toolong;
while condd := cdr condd do
    if toolongexpp caar condd or toolongstmtp cadar condd then
        toolong := t;
return toolong
end$

procedure toolongwhilep stmt;
toolongexpp cadr stmt or
eval('or . foreach st in cddr stmt collect
                   toolongstmtp st        )$

procedure toolongrepeatp stmt;
<<
    stmt := reverse cdr stmt;
    toolongexpp car stmt or
    eval('or . foreach st in cdr stmt collect
                       toolongstmtp st       )
>>$

procedure toolongforp stmt;
eval('or . foreach exp in caddr stmt collect
                   toolongexpp exp          ) or
eval('or . foreach st in cddddr stmt collect
                   toolongstmtp st          )$

procedure toolongreturnp ret;
toolongexpp cadr ret$

procedure toolongstmtgpp stmtgp;
eval('or . for each stmt in cdr stmtgp collect
               toolongstmtp stmt              )$

procedure toolongdefp deff;
if lispstmtgpp cadddr deff then
    toolongstmtgpp cadddr deff
else
    eval('or . for each stmt in cdddr deff collect
                   toolongstmtp stmt             )$


%%                       %%
%% Print Length Function %%
%%                       %%


procedure numprintlen exp;
if atom exp then
    length explode exp
else if onep length exp then
    numprintlen car exp
else
    length exp + eval('plus . for each elt in cdr exp collect
                                numprintlen elt              )$


%%                                                              %%
%% Temporary Variable Generation, Marking & Unmarking Functions %%
%%                                                              %%


procedure tempvar type;
%                                                             %
%  IF type Member '(NIL 0) THEN type <- TEMPVARTYPE!*         %
%                                                             %
%  IF type Neq 'NIL And type Neq 'UNKNOWN THEN                %
%    var <- 1st unmarked tvar of VType type or of VType NIL   %
%           which isn't in the symbol table                   %
%    put type on var's VType property list                    %
%    put declaration in symbol table                          %
%  ELSE IF type = NIL THEN                                    %
%    var <- 1st unmarked tvar of type NIL which isn't in the  %
%           symbol table                                      %
%  ELSE type = 'UNKNOWN                                       %
%    var <- 1st unmarked tvar of type NIL which isn't in the  %
%           symbol table                                      %
%    put 'UNKNOWN on var's VType property list                %
%    print warning - "undeclared"                             %
%                                                             %
%  RETURN var                                                 %
%                                                             %
begin
scalar tvar, xname, num;
if type memq '(nil 0) then type := tempvartype!*;
xname := explode tempvarname!*;
num := tempvarnum!*;
if type memq '(nil unknown) then
    repeat
    <<
        tvar := intern compress append(xname, explode num);
        num := add1 num
    >>
    until not markedvarp tvar and not get(tvar, '!*vtype!*) and
          not getvartype tvar
else
    repeat
    <<
        tvar := intern compress append(xname, explode num);
        num := add1 num
    >>
    until not markedvarp tvar and
          (get(tvar, '!*vtype!*) eq type or
           not get(tvar, '!*vtype!*) and not getvartype tvar);
put(tvar, '!*vtype!*, type);
if type eq 'unknown then
    gentranerr('w, tvar, "UNDECLARED VARIABLE", nil)
else if type then
    symtabput(nil, tvar, list type);
return tvar
end$

procedure markvar var;
if numberp var then
    var
else if atom var then
<<  flag(list var, '!*marked!*);  var  >>
else
<<  for each v in var do markvar v;  var  >>$

procedure markedvarp var;
flagp(var, '!*marked!*)$

procedure unmarkvar var;
if atom var then
    if numberp var then
        var
    else
        remflag(list var, '!*marked!*)
else
    foreach elt in var do
        unmarkvar elt$


endmodule;


module lspfor;    %%  GENTRAN LISP-to-FORTRAN Translation Module  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Point:  FortCode


symbolic$


global '(!*gendecs)$
switch gendecs$

% User-Accessible Global Variables %
global '(fortcurrind!* tablen!*)$
share 'fortcurrind!*, 'tablen!*$
fortcurrind!* := 0$

% GENTRAN Global Variables %
global '(!*endofloopstack!* !*subprogname!*)$
!*endofloopstack!* := nil$
!*subprogname!*    := nil$  %name of subprogram being generated

global '(!*do!*)$


%%                                       %%
%% LISP-to-FORTRAN Translation Functions %%
%%                                       %%


%% Control Function %%


procedure fortcode forms;
for each f in forms conc
    if atom f then
        fortexp f
    else if lispstmtp f or lispstmtgpp f then
        if !*gendecs then
            begin
            scalar r;
            r := append(fortdecs symtabget('!*main!*, '!*decs!*),
                        fortstmt f);
            symtabrem('!*main!*, '!*decs!*);
            return r
            end
        else
            fortstmt f
    else if lispdefp f then
        fortsubprog f
    else
        fortexp f$


%% Subprogram Translation %%


procedure fortsubprog deff;
begin
scalar type, stype, name, params, body, lastst, r;
name := !*subprogname!* := cadr deff;
if onep length (body := cdddr deff) and lispstmtgpp car body then
<<  body := cdar body;  if null car body then body := cdr body  >>;
if lispreturnp (lastst := car reverse body) then
    body := append(body, list '(end))
else if not lispendp lastst then
    body := append(body, list('(return), '(end)));
if (type := symtabget(name, name)) then
<<  type := cadr type;  symtabrem(name, name)  >>;
stype := symtabget(name, '!*type!*) or
         (    if type or functionformp(body, name)
                 then 'function
                 else 'subroutine    );
symtabrem(name, '!*type!*);
params := symtabget(name, '!*params!*) or caddr deff;
symtabrem(name, '!*params!*);
r := mkffortsubprogdec(type, stype, name, params);
if !*gendecs then
    r := append(r, fortdecs symtabget(name, '!*decs!*));
r := append(r, for each s in body
                   conc fortstmt s);
if !*gendecs then
<<  symtabrem(name, nil);  symtabrem(name, '!*decs!*)  >>;
return r
end$


%% Generation of Declarations %%


procedure fortdecs decs;
for each tl in formtypelists decs
    conc mkffortdec(car tl, cdr tl)$


%% Expression Translation %%


procedure fortexp exp;
fortexp1(exp, 0)$

procedure fortexp1(exp, wtin);
if atom exp then
    list fortranname exp
else
    if onep length exp then
        fortranname exp
    else if optype car exp then
        begin
        scalar wt, op, res;
        wt := fortranprecedence car exp;
        op := fortranop car exp;
        exp := cdr exp;
        if onep length exp then
            res := op . fortexp1(car exp, wt)
        else
        <<
            res := fortexp1(car exp, wt);
            if op eq '!+ then
                while exp := cdr exp do
                <<
                    if atom car exp or caar exp neq 'minus then
                        res := append(res, list op);
                    res := append(res, fortexp1(car exp, wt))
                >>
            else
                while exp := cdr exp do
                    res := append(append(res, list op),
                                  fortexp1(car exp, wt))
        >>;
        if wtin > wt then res := insertparens res;
        return res
        end
    else if car exp eq 'literal then
        fortliteral exp
    else
        begin
        scalar op, res;
        op := fortranname car exp;
        exp := cdr exp;
        res := fortexp1(car exp, 0);
        while exp := cdr exp do
            res := append(append(res, list '!,),
                          fortexp1(car exp, 0));
        return op . insertparens res
        end$


procedure fortranop op;
get(op, '!*fortranop!*) or op$

put('or,       '!*fortranop!*, '!.or!. )$
put('and,      '!*fortranop!*, '!.and!.)$
put('not,      '!*fortranop!*, '!.not!.)$
put('equal,    '!*fortranop!*, '!.eq!. )$
put('neq,      '!*fortranop!*, '!.ne!. )$
put('greaterp, '!*fortranop!*, '!.gt!. )$
put('geq,      '!*fortranop!*, '!.ge!. )$
put('lessp,    '!*fortranop!*, '!.lt!. )$
put('leq,      '!*fortranop!*, '!.le!. )$
put('plus,     '!*fortranop!*, '!+     )$
put('times,    '!*fortranop!*, '!*     )$
put('quotient, '!*fortranop!*, '/      )$
put('minus,    '!*fortranop!*, '!-     )$
put('expt,     '!*fortranop!*, '!*!*   )$

procedure fortranname a;
if stringp a then
    stringtoatom a    %  convert a to atom containing "'s
else
    get(a, '!*fortranname!*) or a$

put(t,   '!*fortranname!*, '!.true!. )$
put(nil, '!*fortranname!*, '!.false!.)$

procedure fortranprecedence op;
get(op, '!*fortranprecedence!*) or 9$

put('or,       '!*fortranprecedence!*, 1)$
put('and,      '!*fortranprecedence!*, 2)$
put('not,      '!*fortranprecedence!*, 3)$
put('equal,    '!*fortranprecedence!*, 4)$
put('neq,      '!*fortranprecedence!*, 4)$
put('greaterp, '!*fortranprecedence!*, 4)$
put('geq,      '!*fortranprecedence!*, 4)$
put('lessp,    '!*fortranprecedence!*, 4)$
put('leq,      '!*fortranprecedence!*, 4)$
put('plus,     '!*fortranprecedence!*, 5)$
put('times,    '!*fortranprecedence!*, 6)$
put('quotient, '!*fortranprecedence!*, 6)$
put('minus,    '!*fortranprecedence!*, 7)$
put('expt,     '!*fortranprecedence!*, 8)$


%% Statement Translation %%


procedure fortstmt stmt;
if null stmt then
    nil
else if lisplabelp stmt then
    fortstmtnum stmt
else if car stmt eq 'literal then
    fortliteral stmt
else if lispreadp stmt then
    fortread stmt
else if lispassignp stmt then
    fortassign stmt
else if lispprintp stmt then
    fortwrite stmt
else if lispcondp stmt then
    fortif stmt
else if lispbreakp stmt then
    fortbreak stmt
else if lispgop stmt then
    fortgoto stmt
else if lispreturnp stmt then
    fortreturn stmt
else if lispstopp stmt then
    fortstop stmt
else if lispendp stmt then
    fortend stmt
else if lispwhilep stmt then
    fortwhile stmt
else if lisprepeatp stmt then
    fortrepeat stmt
else if lispforp stmt then
    fortfor stmt
else if lispstmtgpp stmt then
    fortstmtgp stmt
else if lispdefp stmt then
    fortsubprog stmt
else if lispcallp stmt then
    fortcall stmt$


procedure fortassign stmt;
mkffortassign(cadr stmt, caddr stmt)$

procedure fortbreak stmt;
if null !*endofloopstack!* then
    gentranerr('e, nil, "BREAK NOT INSIDE LOOP - CANNOT BE TRANSLATED",
               nil)
else if atom car !*endofloopstack!* then
    begin
    scalar n1;
    n1 := genstmtnum();
    rplaca(!*endofloopstack!*, list(car !*endofloopstack!*, n1));
    return mkffortgo n1
    end
else
    mkffortgo cadar !*endofloopstack!*$

procedure fortcall stmt;
mkffortcall(car stmt, cdr stmt)$

procedure fortfor stmt;
begin
scalar n1, result, var, loexp, stepexp, hiexp, stmtlst;
var := cadr stmt;
stmt := cddr stmt;
loexp := caar stmt;
stepexp := cadar stmt;
hiexp := caddar stmt;
stmtlst := cddr stmt;
n1 := genstmtnum();
!*endofloopstack!* := n1 . !*endofloopstack!*;
result := mkffortdo(n1, var, loexp, hiexp, stepexp);
indentfortlevel(+1);
result := append(result, for each st in stmtlst conc fortstmt st);
indentfortlevel(-1);
result := append(result, mkffortcontinue n1);
if listp car !*endofloopstack!* then
    result := append(result, mkffortcontinue cadar !*endofloopstack!*);
!*endofloopstack!* := cdr !*endofloopstack!*;
return result
end$

procedure fortend stmt;
mkffortend()$

procedure fortgoto stmt;
begin
scalar stmtnum;
if not ( stmtnum := get(cadr stmt, '!*stmtnum!*) ) then
    stmtnum := put(cadr stmt, '!*stmtnum!*, genstmtnum());
return mkffortgo stmtnum
end$

procedure fortif stmt;
begin
scalar n1, n2, res;
stmt := cdr stmt;
if onep length stmt then
    if caar stmt eq t then
        return for each st in cdar stmt conc fortstmt st
    else
        return
        <<
            n1 := genstmtnum();
            res := mkffortifgo(list('not, caar stmt), n1);
            indentfortlevel(+1);
            res := append(res,
                          for each st in cdar stmt conc fortstmt st);
            indentfortlevel(-1);
            append(res, mkffortcontinue n1)
        >>
else
    return
    <<
        n1 := genstmtnum();
        n2 := genstmtnum();
        res := mkffortifgo(list('not, caar stmt), n1);
        indentfortlevel(+1);
        res := append(res, for each st in cdar stmt conc fortstmt st);
        res := append(res, mkffortgo n2);
        indentfortlevel(-1);
        res := append(res, mkffortcontinue n1);
        indentfortlevel(+1);
        res := append(res, fortif('cond . cdr stmt));
        indentfortlevel(-1);
        append(res, mkffortcontinue n2)
    >>
end$

procedure fortliteral stmt;
mkffortliteral cdr stmt$

procedure fortread stmt;
mkffortread cadr stmt$

procedure fortrepeat stmt;
begin
scalar n, result, stmtlst, logexp;
stmtlst := reverse cdr stmt;
logexp := car stmtlst;
stmtlst := reverse cdr stmtlst;
n := genstmtnum();
!*endofloopstack!* := 'dummy . !*endofloopstack!*;
result := mkffortcontinue n;
indentfortlevel(+1);
result := append(result, for each st in stmtlst conc fortstmt st);
indentfortlevel(-1);
result := append(result, mkffortifgo(list('not, logexp), n));
if listp car !*endofloopstack!* then
    result := append(result, mkffortcontinue cadar !*endofloopstack!*);
!*endofloopstack!* := cdr !*endofloopstack!*;
return result
end$

procedure fortreturn stmt;
if onep length stmt then
    mkffortreturn()
else if !*subprogname!* then
    append(mkffortassign(!*subprogname!*, cadr stmt), mkffortreturn())
else
    gentranerr('e, nil,
               "RETURN NOT INSIDE FUNCTION - CANNOT BE TRANSLATED",
               nil)$

procedure fortstmtgp stmtgp;
<<
    if car stmtgp eq 'progn then
        stmtgp := cdr stmtgp
    else
        stmtgp := cddr stmtgp;
    for each stmt in stmtgp conc fortstmt stmt
>>$

procedure fortstmtnum label;
begin
scalar stmtnum;
if not ( stmtnum := get(label, '!*stmtnum!*) ) then
    stmtnum := put(label, '!*stmtnum!*, genstmtnum());
return mkffortcontinue stmtnum
end$

procedure fortstop stmt;
mkffortstop()$

procedure fortwhile stmt;
begin
scalar n1, n2, result, logexp, stmtlst;
logexp := cadr stmt;
stmtlst := cddr stmt;
n1 := genstmtnum();
n2 := genstmtnum();
!*endofloopstack!* := n2 . !*endofloopstack!*;
result := append(list(n1, '! ), mkffortifgo(list('not, logexp), n2));
indentfortlevel(+1);
result := append(result, for each st in stmtlst conc fortstmt st);
result := append(result, mkffortgo n1);
indentfortlevel(-1);
result := append(result, mkffortcontinue n2);
if listp car !*endofloopstack!* then
    result := append(result, mkffortcontinue cadar !*endofloopstack!*);
!*endofloopstack!* := cdr !*endofloopstack!*;
return result
end$

procedure fortwrite stmt;
mkffortwrite cdr stmt$


%%                                   %%
%% FORTRAN Code Formatting Functions %%
%%                                   %%


%% Statement Formatting %%


procedure mkffortassign(lhs, rhs);
append(append(mkforttab() . fortexp lhs, '!= . fortexp rhs),
       list mkfortterpri())$

procedure mkffortcall(fname, params);
<<
    if params then
        params := append(append(list '!(,
                                for each p in insertcommas params
                                              conc fortexp p),
                         list '!));
    append(append(list(mkforttab(), 'call, '! ), fortexp fname),
           append(params, list mkfortterpri()))
>>$

procedure mkffortcontinue stmtnum;
list(stmtnum, '! , mkforttab(), 'continue, mkfortterpri())$

procedure mkffortdec(type, varlist);
<<
    type := type or 'dimension;
    varlist := for each v in insertcommas varlist
                   conc fortexp v;
    if implicitp type then
        append(list(mkforttab(), type, '! , '!(),
               append(varlist, list('!), mkfortterpri())))
    else
        append(list(mkforttab(), type, '! ),
               append(varlist,list mkfortterpri()))
>>$

procedure mkffortdo(stmtnum, var, lo, hi, incr);
<<
    if onep incr then
        incr := nil
    else if incr then
        incr := '!, . fortexp incr;
    append(append(append(list(mkforttab(), !*do!*, '! , stmtnum, '! ),
                         fortexp var),
                  append('!= . fortexp lo, '!, . fortexp hi)),
           append(incr, list mkfortterpri()))
>>$

procedure mkffortend;
list(mkforttab(), 'end, mkfortterpri())$

procedure mkffortgo stmtnum;
list(mkforttab(), 'goto, '! , stmtnum, mkfortterpri())$

procedure mkffortifgo(exp, stmtnum);
append(append(list(mkforttab(), 'if, '! , '!(), fortexp exp),
       list('!), '! , 'goto, '! , stmtnum, mkfortterpri()))$

procedure mkffortliteral args;
for each a in args conc
    if a eq 'tab!* then
        list mkforttab()
    else if a eq 'cr!* then
        list mkfortterpri()
    else if listp a then
        fortexp a
    else
        list stripquotes a$

procedure mkffortread var;
append(list(mkforttab(), 'read, '!(!*!,!*!), '! ),
       append(fortexp var, list mkfortterpri()))$

procedure mkffortreturn;
list(mkforttab(), 'return, mkfortterpri())$

procedure mkffortstop;
list(mkforttab(), 'stop, mkfortterpri())$

procedure mkffortsubprogdec(type, stype, name, params);
<<
    if params then
        params := append('!( . for each p in insertcommas params
                                   conc fortexp p,
                          list '!));
    if type then
        type := list(mkforttab(), type, '! , stype, '! )
    else
        type := list(mkforttab(), stype, '! );
    append(append(type, fortexp name),
           append(params, list mkfortterpri()))
>>$

procedure mkffortwrite arglist;
append(append(list(mkforttab(), 'write, '!(!*!,!*!), '! ),
              for each arg in insertcommas arglist conc fortexp arg),
       list mkfortterpri())$


%% Indentation Control %%


procedure mkforttab;
list('forttab, fortcurrind!* + 6)$


procedure indentfortlevel n;
fortcurrind!* := fortcurrind!* + n * tablen!*$


procedure mkfortterpri;
list 'fortterpri$


endmodule;


module lsprat;    %%  GENTRAN LISP-to-RATFOR Translation Module  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Point:  RatCode


symbolic$


global '(!*gendecs)$
switch gendecs$

% User-Accessible Global Variables %
global '(ratcurrind!* tablen!*)$
share 'ratcurrind!*, 'tablen!*$
ratcurrind!* := 0$

global '(!*do!*)$


%%                                      %%
%% LISP-to-RATFOR Translation Functions %%
%%                                      %%


%% Control Function %%


procedure ratcode forms;
for each f in forms conc
    if atom f then
        ratexp f
    else if lispstmtp f or lispstmtgpp f then
        if !*gendecs then
            begin
            scalar r;
            r := append(ratdecs symtabget('!*main!*, '!*decs!*),
                        ratstmt f);
            symtabrem('!*main!*, '!*decs!*);
            return r
            end
        else
            ratstmt f
    else if lispdefp f then
        ratsubprog f
    else
        ratexp f$


%% Subprogram Translation %%


procedure ratsubprog deff;
begin
scalar type, stype, name, params, body, lastst, r;
name := cadr deff;
if onep length(body := cdddr deff) and lispstmtgpp car body then
<<  body := cdar body;  if null car body then body := cdr body  >>;
if lispreturnp (lastst := car reverse body) then
    body := append(body, list '(end))
else if not lispendp lastst then
    body := append(body, list('(return), '(end)));
if (type := symtabget(name, name)) then
<<  type := cadr type;  symtabrem(name, name)  >>;
stype := symtabget(name, '!*type!*) or
         (    if type or functionformp(body, name)
                 then 'function
                 else 'subroutine    );
symtabrem(name, '!*type!*);
params := symtabget(name, '!*params!*) or caddr deff;
symtabrem(name, '!*params!*);
r := mkfratsubprogdec(type, stype, name, params);
if !*gendecs then
    r := append(r, ratdecs symtabget(name, '!*decs!*));
r := append(r, for each s in body
                   conc ratstmt s);
if !*gendecs then
<<  symtabrem(name, nil);  symtabrem(name, '!*decs!*)  >>;
return r
end$


%% Generation of Declarations %%


procedure ratdecs decs;
for each tl in formtypelists decs
    conc mkfratdec(car tl, cdr tl)$


%% Expression Translation %%


procedure ratexp exp;
ratexp1(exp, 0)$

procedure ratexp1(exp, wtin);
if atom exp then
    list ratforname exp
else
    if onep length exp then
        ratforname exp
    else if optype car exp then
        begin
        scalar wt, op, res;
        wt := ratforprecedence car exp;
        op := ratforop car exp;
        exp := cdr exp;
        if onep length exp then
            res := op . ratexp1(car exp, wt)
        else
        <<
            res := ratexp1(car exp, wt);
            if op eq '!+ then
                while exp := cdr exp do
                <<
                    if atom car exp or caar exp neq 'minus then
                        res := append(res, list op);
                    res := append(res, ratexp1(car exp, wt))
                >>
            else
                while exp := cdr exp do
                    res := append(append(res, list op),
                                  ratexp1(car exp, wt))
        >>;
        if wtin > wt then res := insertparens res;
        return res
        end
    else if car exp eq 'literal then
        ratliteral exp
    else
        begin
        scalar op, res;
        op := ratforname car exp;
        exp := cdr exp;
        res := ratexp1(car exp, 0);
        while exp := cdr exp do
            res := append(append(res, list '!,), ratexp1(car exp, 0));
        return op . insertparens res
        end$


procedure ratforop op;
get(op, '!*ratforop!*) or op$

put('or,       '!*ratforop!*, '|   )$
put('and,      '!*ratforop!*, '&   )$
put('not,      '!*ratforop!*, '!!  )$
put('equal,    '!*ratforop!*, '!=!=)$
put('neq,      '!*ratforop!*, '!!!=)$
put('greaterp, '!*ratforop!*, '>   )$
put('geq,      '!*ratforop!*, '!>!=)$
put('lessp,    '!*ratforop!*, '<   )$
put('leq,      '!*ratforop!*, '!<!=)$
put('plus,     '!*ratforop!*, '!+  )$
put('times,    '!*ratforop!*, '*   )$
put('quotient, '!*ratforop!*, '/   )$
put('minus,    '!*ratforop!*, '!-  )$
put('expt,     '!*ratforop!*, '!*!*)$

procedure ratforname a;
if stringp a then
    stringtoatom a    % convert a to atom containing "'s
else
    get(a, '!*ratforname!*) or a$

put(t,   '!*ratforname!*, '!.true!. )$
put(nil, '!*ratforname!*, '!.false!.)$

procedure ratforprecedence op;
get(op, '!*ratforprecedence!*) or 9$

put('or,       '!*ratforprecedence!*, 1)$
put('and,      '!*ratforprecedence!*, 2)$
put('not,      '!*ratforprecedence!*, 3)$
put('equal,    '!*ratforprecedence!*, 4)$
put('neq,      '!*ratforprecedence!*, 4)$
put('greaterp, '!*ratforprecedence!*, 4)$
put('geq,      '!*ratforprecedence!*, 4)$
put('lessp,    '!*ratforprecedence!*, 4)$
put('leq,      '!*ratforprecedence!*, 4)$
put('plus,     '!*ratforprecedence!*, 5)$
put('times,    '!*ratforprecedence!*, 6)$
put('quotient, '!*ratforprecedence!*, 6)$
put('minus,    '!*ratforprecedence!*, 7)$
put('expt,     '!*ratforprecedence!*, 8)$


%% Statement Translation %%


procedure ratstmt stmt;
if null stmt then
    nil
else if lisplabelp stmt then
    ratstmtnum stmt
else if car stmt eq 'literal then
    ratliteral stmt
else if lispreadp stmt then
    ratread stmt
else if lispassignp stmt then
    ratassign stmt
else if lispprintp stmt then
    ratwrite stmt
else if lispcondp stmt then
    ratif stmt
else if lispbreakp stmt then
    ratbreak stmt
else if lispgop stmt then
    ratgoto stmt
else if lispreturnp stmt then
    ratreturn stmt
else if lispstopp stmt then
    ratstop stmt
else if lispendp stmt then
    ratend stmt
else if lisprepeatp stmt then
    ratrepeat stmt
else if lispwhilep stmt then
    ratwhile stmt
else if lispforp stmt then
    ratforfor stmt
else if lispstmtgpp stmt then
    ratstmtgp stmt
else if lispdefp stmt then
    ratsubprog stmt
else if lispcallp stmt then
    ratcall stmt$


procedure ratassign stmt;
mkfratassign(cadr stmt, caddr stmt)$

procedure ratbreak stmt;
mkfratbreak()$

procedure ratcall stmt;
mkfratcall(car stmt, cdr stmt)$

procedure ratforfor stmt;
begin
scalar r, var, loexp, stepexp, hiexp, stmtlst;
var := cadr stmt;
stmt := cddr stmt;
loexp := caar stmt;
stepexp := cadar stmt;
hiexp := caddar stmt;
stmtlst := cddr stmt;
r := mkfratdo(var, loexp, hiexp, stepexp);
indentratlevel(+1);
r := append(r, foreach st in stmtlst conc ratstmt st);
indentratlevel(-1);
return r
end$

procedure ratend stmt;
mkfratend()$

procedure ratgoto stmt;
begin
scalar stmtnum;
stmtnum := get(cadr stmt, '!*stmtnum!*) or
          put(cadr stmt, '!*stmtnum!*, genstmtnum());
return mkfratgo stmtnum
end$

procedure ratif stmt;
begin
scalar r, st;
r := mkfratif caadr stmt;
indentratlevel(+1);
st := seqtogp cdadr stmt;
if listp st and car st eq 'cond and length st=2 then
    st := mkstmtgp(0, list st);
r := append(r, ratstmt st);
indentratlevel(-1);
stmt := cdr stmt;
while (stmt := cdr stmt) and caar stmt neq t do
<<
    r := append(r, mkfratelseif caar stmt);
    indentratlevel(+1);
    st := seqtogp cdar stmt;
    if listp st and car st eq 'cond and length st=2 then
        st := mkstmtgp(0, list st);
    r := append(r, ratstmt st);
    indentratlevel(-1)
>>;
if stmt then
<<
    r := append(r, mkfratelse());
    indentratlevel(+1);
    st := seqtogp cdar stmt;
    if listp st and car st eq 'cond and length st=2 then
        st := mkstmtgp(0, list st);
    r := append(r, ratstmt st);
    indentratlevel(-1)
>>;
return r
end$

procedure ratliteral stmt;
mkfratliteral cdr stmt$

procedure ratread stmt;
mkfratread cadr stmt$

procedure ratrepeat stmt;
begin
scalar r, stmtlst, logexp;
stmt := reverse cdr stmt;
logexp := car stmt;
stmtlst := reverse cdr stmt;
r := mkfratrepeat();
indentratlevel(+1);
r := append(r, foreach st in stmtlst conc ratstmt st);
indentratlevel(-1);
return append(r, mkfratuntil logexp)
end$

procedure ratreturn stmt;
if cdr stmt then
    mkfratreturn cadr stmt
else
    mkfratreturn nil$

procedure ratstmtgp stmtgp;
begin
scalar r;
if car stmtgp eq 'progn then
    stmtgp := cdr stmtgp
else
    stmtgp := cddr stmtgp;
r := mkfratbegingp();
indentratlevel(+1);
r := append(r, for each stmt in stmtgp conc ratstmt stmt);
indentratlevel(-1);
return append(r, mkfratendgp())
end$

procedure ratstmtnum label;
begin
scalar stmtnum;
stmtnum := get(label, '!*stmtnum!*) or
          put(label, '!*stmtnum!*, genstmtnum());
return mkfratcontinue stmtnum
end$

procedure ratstop stmt;
mkfratstop()$

procedure ratwhile stmt;
begin
scalar r, logexp, stmtlst;
logexp := cadr stmt;
stmtlst := cddr stmt;
r := mkfratwhile logexp;
indentratlevel(+1);
r := append(r, foreach st in stmtlst conc ratstmt st);
indentratlevel(-1);
return r
end$

procedure ratwrite stmt;
mkfratwrite cdr stmt$


%%                                  %%
%% RATFOR Code Formatting Functions %%
%%                                  %%


%% Statement Formatting %%


procedure mkfratassign(lhs, rhs);
append(append(mkrattab() . ratexp lhs, '!= . ratexp rhs),
       list mkratterpri())$

procedure mkfratbegingp;
list(mkrattab(), '!{, mkratterpri())$

procedure mkfratbreak;
list(mkrattab(), 'break, mkratterpri())$

procedure mkfratcall(fname, params);
<<
    if params then
        params := append(append(list '!(,
                                for each p in insertcommas params
                                              conc ratexp p),
                         list '!));
    append(append(list(mkrattab(), 'call, '! ), ratexp fname),
           append(params, list mkratterpri()))
>>$

procedure mkfratcontinue stmtnum;
list(stmtnum, '! , mkrattab(), 'continue, mkratterpri())$

procedure mkfratdec(type, varlist);
<<
    type := type or 'dimension;
    varlist := for each v in insertcommas varlist
                   conc ratexp v;
    if implicitp type then
        append(list(mkrattab(), type, '! , '!(),
               append(varlist, list('!), mkratterpri())))
    else
        append(list(mkrattab(), type, '! ),
               append(varlist, list mkratterpri()))
>>$

procedure mkfratdo(var, lo, hi, incr);
<<
    if onep incr then
        incr := nil
    else if incr then
        incr := '!, . ratexp incr;
    append(append(append(list(mkrattab(), !*do!*, '! ), ratexp var),
                  append('!= . ratexp lo, '!, . ratexp hi)),
           append(incr, list mkratterpri()))
>>$

procedure mkfratelse;
list(mkrattab(), 'else, mkratterpri())$

procedure mkfratelseif exp;
append(append(list(mkrattab(), 'else, '! , 'if, '! , '!(), ratexp exp),
       list('!), mkratterpri()))$

procedure mkfratend;
list(mkrattab(), 'end, mkratterpri())$

procedure mkfratendgp;
list(mkrattab(), '!}, mkratterpri())$

procedure mkfratgo stmtnum;
list(mkrattab(), 'goto, '! , stmtnum, mkratterpri())$

procedure mkfratif exp;
append(append(list(mkrattab(), 'if, '! , '!(), ratexp exp),
       list('!), mkratterpri()))$

procedure mkfratliteral args;
for each a in args conc
    if a eq 'tab!* then
        list mkrattab()
    else if a eq 'cr!* then
        list mkratterpri()
    else if listp a then
        ratexp a
    else
        list stripquotes a$

procedure mkfratread var;
append(list(mkrattab(), 'read, '!(!*!,!*!), '! ),
       append(ratexp var, list mkratterpri()))$

procedure mkfratrepeat;
list(mkrattab(), 'repeat, mkratterpri())$

procedure mkfratreturn exp;
if exp then
    append(append(list(mkrattab(), 'return, '!(), ratexp exp),
           list('!), mkratterpri()))
else
    list(mkrattab(), 'return, mkratterpri())$

procedure mkfratstop;
list(mkrattab(), 'stop, mkratterpri())$

procedure mkfratsubprogdec(type, stype, name, params);
<<
    if params then
        params := append('!( . for each p in insertcommas params
                                  conc ratexp p,
                         list '!));
    if type then
        type := list(mkrattab(), type, '! , stype, '! )
    else
        type := list(mkrattab(), stype, '! );
    append(append(type, ratexp name),
           append(params,list mkratterpri()))
>>$

procedure mkfratuntil logexp;
append(list(mkrattab(), 'until, '! , '!(),
       append(ratexp logexp, list('!), mkratterpri())))$

procedure mkfratwhile exp;
append(append(list(mkrattab(), 'while, '! , '!(), ratexp exp),
       list('!), mkratterpri()))$

procedure mkfratwrite arglist;
append(append(list(mkrattab(), 'write, '!(!*!,!*!), '! ),
              for each arg in insertcommas arglist conc ratexp arg),
       list mkratterpri())$


%% Indentation Control %%


procedure mkrattab;
list('rattab, ratcurrind!*)$


procedure indentratlevel n;
ratcurrind!* := ratcurrind!* + n * tablen!*$


procedure mkratterpri;
list 'ratterpri$


endmodule;


module lspc;    %%  GENTRAN LISP-to-C Translation Module  %%

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Point:  CCode


symbolic$


global '(!*gendecs)$
switch gendecs$

% User-Accessible Global Variables %
global '(ccurrind!* tablen!*)$
share 'ccurrind!*, 'tablen!*$
ccurrind!* := 0$

global '(!*do!* !*for!*)$


%%                                 %%
%% LISP-to-C Translation Functions %%
%%                                 %%


%% Control Function %%


procedure ccode forms;
for each f in forms conc
    if atom f then
        cexp f
    else if lispstmtp f or lispstmtgpp f then
        if !*gendecs then
            begin
            scalar r;
            r := append(cdecs symtabget('!*main!*, '!*decs!*),
                        cstmt f);
            symtabrem('!*main!*, '!*decs!*);
            return r
            end
        else
            cstmt f
    else if lispdefp f then
        cproc f
    else
        cexp f$


%% Procedure Translation %%


procedure cproc deff;
begin
scalar type, name, params, paramtypes, vartypes, body, r;
name := cadr deff;
if onep length (body := cdddr deff) and lispstmtgpp car body then
<<  body := cdar body;  if null car body then body := cdr body  >>;
if (type := symtabget(name, name)) then
<<  type := cadr type;  symtabrem(name, name)  >>;
params := symtabget(name, '!*params!*) or caddr deff;
symtabrem(name, '!*params!*);
for each dec in symtabget(name, '!*decs!*) do
    if car dec memq params
       then paramtypes := append(paramtypes, list dec)
       else vartypes := append(vartypes, list dec);
r := append( append( mkfcprocdec(type, name, params),
                     cdecs paramtypes ),
             mkfcbegingp() );
indentclevel(+1);
if !*gendecs then
    r := append(r, cdecs vartypes);
r := append(r, for each s in body
                   conc cstmt s);
indentclevel(-1);
r := append(r, mkfcendgp());
if !*gendecs then
<<  symtabrem(name, nil);  symtabrem(name, '!*decs!*)  >>;
return r
end$


%% Generation of Declarations %%


procedure cdecs decs;
for each tl in formtypelists decs
    conc mkfcdec(car tl, cdr tl)$


%% Expression Translation %%


procedure cexp exp;
cexp1(exp, 0)$

procedure cexp1(exp, wtin);
if atom exp then
    list cname exp
else
    if onep length exp then
        append(cname exp, insertparens(()))
    else if car exp eq 'expt then
        'power . insertparens append(cexp1(cadr exp, 0),
                                     '!, . cexp1(caddr exp, 0))
    else if optype car exp then
        begin
        scalar wt, op, res;
        wt := cprecedence car exp;
        op := cop car exp;
        exp := cdr exp;
        if onep length exp then
            res := op . cexp1(car exp, wt)
        else
        <<
            res := cexp1(car exp, wt);
            if op eq '!+ then
                while exp := cdr exp do
                <<
                    if atom car exp or caar exp neq 'minus then
                        res := append(res, list op);
                    res := append(res, cexp1(car exp, wt))
                >>
            else
                while exp := cdr exp do
                    res := append(append(res, list op),
                                  cexp1(car exp, wt))
        >>;
        if wtin > wt then res := insertparens res;
        return res
        end
    else if car exp eq 'literal then
        cliteral exp
    else if arrayeltp exp then
        cname car exp . foreach s in cdr exp conc
                                insertbrackets cexp1(s, 0)
    else
        begin
        scalar op, res;
        op := cname car exp;
        exp := cdr exp;
        res := cexp1(car exp, 0);
        while exp := cdr exp do
            res := append(append(res, list '!,), cexp1(car exp, 0));
        return op . insertparens res
        end$


procedure cop op;
get(op, '!*cop!*) or op$

put('or,       '!*cop!*, '!|!|)$
put('and,      '!*cop!*, '!&!&)$
put('not,      '!*cop!*, '!!  )$
put('equal,    '!*cop!*, '!=!=)$
put('neq,      '!*cop!*, '!!!=)$
put('greaterp, '!*cop!*, '>   )$
put('geq,      '!*cop!*, '!>!=)$
put('lessp,    '!*cop!*, '<   )$
put('leq,      '!*cop!*, '!<!=)$
put('plus,     '!*cop!*, '!+  )$
put('times,    '!*cop!*, '*   )$
put('quotient, '!*cop!*, '/   )$
put('minus,    '!*cop!*, '!-  )$

procedure cname a;
if stringp a then
    stringtoatom a    % convert a to atom containing "'s
else
    get(a, '!*cname!*) or a$

put(t,   '!*cname!*, 1)$
put(nil, '!*cname!*, 0)$

procedure cprecedence op;
get(op, '!*cprecedence!*) or 8$

put('or,       '!*cprecedence!*, 1)$
put('and,      '!*cprecedence!*, 2)$
put('equal,    '!*cprecedence!*, 3)$
put('neq,      '!*cprecedence!*, 3)$
put('greaterp, '!*cprecedence!*, 4)$
put('geq,      '!*cprecedence!*, 4)$
put('lessp,    '!*cprecedence!*, 4)$
put('leq,      '!*cprecedence!*, 4)$
put('plus,     '!*cprecedence!*, 5)$
put('times,    '!*cprecedence!*, 6)$
put('quotient, '!*cprecedence!*, 6)$
put('not,      '!*cprecedence!*, 7)$
put('minus,    '!*cprecedence!*, 7)$


%% Statement Translation %%


procedure cstmt stmt;
if null stmt then
    nil
else if lisplabelp stmt then
    clabel stmt
else if car stmt eq 'literal then
    cliteral stmt
else if lispassignp stmt then
    cassign stmt
else if lispcondp stmt then
    cif stmt
else if lispbreakp stmt then
    cbreak stmt
else if lispgop stmt then
    cgoto stmt
else if lispreturnp stmt then
    creturn stmt
else if lispstopp stmt then
    cexit stmt
else if lisprepeatp stmt then
    crepeat stmt
else if lispwhilep stmt then
    cwhile stmt
else if lispforp stmt then
    cfor stmt
else if lispstmtgpp stmt then
    cstmtgp stmt
else if lispdefp stmt then
    cproc stmt
else
    cexpstmt stmt$


procedure cassign stmt;
mkfcassign(cadr stmt, caddr stmt)$

procedure cbreak stmt;
mkfcbreak()$

procedure cexit stmt;
mkfcexit()$

procedure cexpstmt exp;
append(mkctab() . cexp exp, list('!;, mkcterpri()))$

procedure cfor stmt;
begin
scalar r, var, loexp, stepexp, hiexp, stmtlst;
var := cadr stmt;
stmt := cddr stmt;
loexp := caar stmt;
stepexp := cadar stmt;
hiexp := caddar stmt;
stmtlst := cddr stmt;
r := mkfcfor(var, loexp, list('leq, var, hiexp), var,
             list('plus, var, stepexp));
indentclevel(+1);
r := append(r, foreach st in stmtlst conc cstmt st);
indentclevel(-1);
return r
end$

procedure cgoto stmt;
mkfcgo cadr stmt$

procedure cif stmt;
begin
scalar r, st;
r := mkfcif caadr stmt;
indentclevel(+1);
st := seqtogp cdadr stmt;
if listp st and car st eq 'cond and length st=2 then
    st := mkstmtgp(0, list st);
r := append(r, cstmt st);
indentclevel(-1);
stmt := cdr stmt;
while (stmt := cdr stmt) and caar stmt neq t do
<<
    r := append(r, mkfcelseif caar stmt);
    indentclevel(+1);
    st := seqtogp cdar stmt;
    if listp st and car st eq 'cond and length st=2 then
        st := mkstmtgp(0, list st);
    r := append(r, cstmt st);
    indentclevel(-1)
>>;
if stmt then
<<
    r := append(r, mkfcelse());
    indentclevel(+1);
    st := seqtogp cdar stmt;
    if listp st and car st eq 'cond and length st=2 then
        st := mkstmtgp(0, list st);
    r := append(r, cstmt st);
    indentclevel(-1)
>>;
return r
end$

procedure clabel label;
mkfclabel label$

procedure cliteral stmt;
mkfcliteral cdr stmt$

procedure crepeat stmt;
begin
scalar r, stmtlst, logexp;
stmt := reverse cdr stmt;
logexp := car stmt;
stmtlst := reverse cdr stmt;
r := mkfcdo();
indentclevel(+1);
r := append(r, foreach st in stmtlst conc cstmt st);
indentclevel(-1);
return append(r, mkfcdowhile list('not, logexp))
end$

procedure creturn stmt;
if cdr stmt then
    mkfcreturn cadr stmt
else
    mkfcreturn nil$

procedure cstmtgp stmtgp;
begin
scalar r;
if car stmtgp eq 'progn then
    stmtgp := cdr stmtgp
else
    stmtgp :=cddr stmtgp;
r := mkfcbegingp();
indentclevel(+1);
r := append(r, for each stmt in stmtgp conc cstmt stmt);
indentclevel(-1);
return append(r, mkfcendgp())
end$

procedure cwhile stmt;
begin
scalar r, logexp, stmtlst;
logexp := cadr stmt;
stmtlst := cddr stmt;
r := mkfcwhile logexp;
indentclevel(+1);
r := append(r, foreach st in stmtlst conc cstmt st);
indentclevel(-1);
return r
end$


%%                             %%
%% C Code Formatting Functions %%
%%                             %%


%% Statement Formatting %%


procedure mkfcassign(lhs, rhs);
begin
scalar st;
if length rhs = 3 and lhs member rhs then
    begin
    scalar op, exp1, exp2;
    op := car rhs;
    exp1 := cadr rhs;
    exp2 := caddr rhs;
    if op = 'plus then
        if onep exp1 or onep exp2 then
            st := ('!+!+ . cexp lhs)
        else if exp1 member '(-1 (minus 1))
           or exp2 member '(-1 (minus 1)) then
            st := ('!-!- . cexp lhs)
        else if listp exp1 and car exp1 = 'minus then
            st := append(cexp lhs, '!-!= . cexp cadr exp1)
        else if listp exp2 and car exp2 = 'minus then
            st := append(cexp lhs, '!-!= . cexp cadr exp2)
        else if exp1 = lhs then
            st := append(cexp lhs, '!+!= . cexp exp2)
        else
            st := append(cexp lhs, '!+!= . cexp exp1)
    else if op = 'difference and onep exp2 then
        st := ('!-!- . cexp lhs)
    else if op = 'difference and exp1 = lhs then
        st := append(cexp lhs, '!-!= . cexp exp2)
    else if op = 'times and exp1 = lhs then
        st := append(cexp lhs, '!*!= . cexp exp2)
    else if op = 'times then
        st := append(cexp lhs, '!*!= . cexp exp1)
    else if op = 'quotient and exp1 = lhs then
        st := append(cexp lhs, '!/!= . cexp exp2)
    else
        st := append(cexp lhs, '!= . cexp rhs)
    end
else
    st := append(cexp lhs, '!= . cexp rhs);
return append(mkctab() . st, list('!;, mkcterpri()))
end$

procedure mkfcbegingp;
list(mkctab(), '!{, mkcterpri())$

procedure mkfcbreak;
list(mkctab(), 'break, '!;, mkcterpri())$

procedure mkfcdec(type, varlist);
<<
    varlist := for each v in varlist collect
                   if atom v then
                       v
                   else
                       car v . for each dim in cdr v collect add1 dim;
    append(mkctab() . type . '!  . for each v in insertcommas varlist
                                       conc cexp v,
           list('!;, mkcterpri()))
>>$

procedure mkfcdo;
list(mkctab(), !*do!*, mkcterpri())$

procedure mkfcdowhile exp;
append(append(list(mkctab(), 'while, '! , '!(), cexp exp),
       list('!), '!;, mkcterpri()))$

procedure mkfcelse;
list(mkctab(), 'else, mkcterpri())$

procedure mkfcelseif exp;
append(append(list(mkctab(), 'else, '! , 'if, '! , '!(), cexp exp),
       list('!), mkcterpri()))$

procedure mkfcendgp;
list(mkctab(), '!}, mkcterpri())$

procedure mkfcexit;
list(mkctab(), 'exit, '!(, 0, '!), '!;, mkcterpri())$

procedure mkfcfor(var1, lo, cond, var2, nextexp);
<<
    if var1 then
        var1 := append(cexp var1, '!= . cexp lo);
    if cond then
        cond := cexp cond;
    if var2 then
    <<
        var2 := cdr mkfcassign(var2, nextexp);
        var2 := reverse cddr reverse var2
    >>;
    append(append(append(list(mkctab(), !*for!*, '! , '!(), var1),
                         '!; . cond),
           append('!; . var2, list('!), mkcterpri())))
>>$

procedure mkfcgo label;
list(mkctab(), 'goto, '! , label, '!;, mkcterpri())$

procedure mkfcif exp;
append(append(list(mkctab(), 'if, '! , '!(), cexp exp),
       list('!), mkcterpri()))$

procedure mkfclabel label;
list(label, '!:, mkcterpri())$

procedure mkfcliteral args;
for each a in args conc
    if a eq 'tab!* then
        list mkctab()
    else if a eq 'cr!* then
        list mkcterpri()
    else if listp a then
        cexp a
    else
        list stripquotes a$

procedure mkfcprocdec(type, name, params);
<<
    params := append('!( . for each p in insertcommas params
                              conc cexp p,
                     list '!));
    if type then
        append(mkctab() . type . '!  . cexp name,
               append(params,list mkcterpri()))
    else
        append(mkctab() . cexp name, append(params, list mkcterpri()))
>>$

procedure mkfcreturn exp;
if exp then
    append(append(list(mkctab(), 'return, '!(), cexp exp),
           list('!), '!;, mkcterpri()))
else
    list(mkctab(), 'return, '!;, mkcterpri())$

procedure mkfcwhile exp;
append(append(list(mkctab(), 'while, '! , '!(), cexp exp),
       list('!), mkcterpri()))$


%% Indentation Control %%


procedure mkctab;
list('ctab, ccurrind!*)$


procedure indentclevel n;
ccurrind!* := ccurrind!* + n * tablen!*$


procedure mkcterpri;
list 'cterpri$


%%                 %%
%% Misc. Functions %%
%%                 %%


procedure insertbrackets exp;
'![ . append(exp, list '!])$


endmodule;


module goutput;  % GENTRAN Code Formatting & Printing and Error Handler

%%  Author:  Barbara L. Gates  %%
%%  December 1986              %%

% Entry Points:  FormatC, FormatFort, FormatRat, GentranErr


symbolic$

% User-Accessible Global Variable %
global '(clinelen!* fortlinelen!* minclinelen!* minfortlinelen!*
         minratlinelen!* ratlinelen!*)$
share 'clinelen!*, 'fortlinelen!*, 'minclinelen!*, 'minfortlinelen!*,
      'minratlinelen!*, 'ratlinelen!*$
clinelen!*       := 80$
fortlinelen!*    := 72$
minclinelen!*    := 40$
minfortlinelen!* := 40$
minratlinelen!*  := 40$
ratlinelen!*     := 80$

% GENTRAN Global Variables %
global '(!*ccurrind!* !*errchan!* !*fortcurrind!* !*outchanl!*
         !*posn!* !*ratcurrind!* !*stdin!* !*stdout!* !$eol!$)$
!*ccurrind!*    := 0$     %current level of indentation for C code
!*errchan!*     := nil$   %error channel number
!*fortcurrind!* := 6$     %current level of indentation for FORTRAN code
!*posn!*        := 0$     %current position on output line
!*ratcurrind!*  := 0$     %current level of indentation for RATFOR code


%%                                      %%
%% Code Formatting & Printing Functions %%
%%                                      %%


%% FORTRAN Code Formatting & Printing Functions %%


procedure formatfort lst;
begin
scalar linelen;
linelen := linelength 300;
!*posn!* := 0;
for each elt in lst do
    if listp elt then
        eval elt
    else
    <<
        if !*posn!* + length explode2 elt > fortlinelen!* then
            fortcontline();
        pprin2 elt
    >>;
linelength linelen
end$

procedure fortcontline;
<<
    fortterpri();
    pprin2 "     .";
    forttab !*fortcurrind!*;
    pprin2 " "
>>$

procedure fortterpri;
pterpri()$

procedure forttab n;
<<
    !*fortcurrind!* := max(min0(n, fortlinelen!* - minfortlinelen!*),6);
    if (n := !*fortcurrind!* - !*posn!*) > 0 then pprin2 nspaces n
>>$


%% RATFOR Code Formatting & Printing Functions %%


procedure formatrat lst;
begin
scalar linelen;
linelen := linelength 300;
!*posn!* := 0;
for each elt in lst do
    if listp elt then
        eval elt
    else
    <<
        if !*posn!* + length explode2 elt > ratlinelen!* then
            ratcontline();
        pprin2 elt
    >>;
linelength linelen
end$

procedure ratcontline;
<<
    ratterpri();
    rattab !*ratcurrind!*;
    pprin2 " "
>>$

procedure ratterpri;
pterpri()$

procedure rattab n;
<<
    !*ratcurrind!* := min0(n, ratlinelen!* - minratlinelen!*);
    if (n := !*ratcurrind!* - !*posn!*) > 0 then pprin2 nspaces n
>>$


%% C Code Formatting & Printing Functions %%


procedure formatc lst;
begin
scalar linelen;
linelen := linelength 300;
!*posn!* := 0;
for each elt in lst do
    if listp elt then
        eval elt
    else
    <<
        if !*posn!* + length explode2 elt > clinelen!* then
            ccontline();
        pprin2 elt
    >>;
linelength linelen
end$

procedure ccontline;
<<
    cterpri();
    ctab !*ccurrind!*;
    pprin2 " "
>>$

procedure cterpri;
pterpri()$

procedure ctab n;
<<
    !*ccurrind!* := min0(n, clinelen!* - minclinelen!*);
    if (n := !*ccurrind!* - !*posn!*) > 0 then pprin2 nspaces n
>>$


%%                            %%
%% General Printing Functions %%
%%                            %%


procedure pprin2 arg;
begin
scalar ch;
ch := wrs nil;
for each c in !*outchanl!* do
<<  wrs c;  prin2 arg  >>;
!*posn!* := !*posn!* + length explode2 arg;
wrs ch
end$

procedure pterpri;
begin
scalar ch;
ch := wrs nil;
for each c in !*outchanl!* do
<<  wrs c;  terpri()  >>;
!*posn!* := 0;
wrs ch
end$


%%               %%
%% Error Handler %%
%%               %%


%% Error & Warning Message Printing Routine %%


procedure gentranerr(msgtype, exp, msg1, msg2);
begin
scalar holdich, holdoch, resp, emsg;
holdich := rds !*errchan!*;
holdoch := wrs !*errchan!*;
terpri();
if exp then prettyprint exp;
if msgtype eq 'e then
<<
    rds cdr !*stdin!*;
    wrs cdr !*stdout!*;
    rederr msg1
>>;
prin2 "*** ";
prin2t msg1;
if msg2 then resp := yesp msg2;
wrs holdoch;
rds holdich;
if not resp then error1()
end$


%%                 %%
%% Misc. Functions %%
%%                 %%


procedure min0(n1, n2);
max(min(n1, n2), 0)$

procedure nspaces n;
   % Note n is assumed > 0 here.
   begin scalar s;
      for i := 1:n do s := ('!! . '!  . s);
      return intern compress s
   end$


endmodule;


end;
