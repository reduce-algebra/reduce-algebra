% ----------------------------------------------------------------------
% $Id: qqe.red,v 1.33 2007/12/16 12:41:57 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2005-2008 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
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

% $Log: qqe.red,v $
% Revision 1.33  2007/12/16 12:41:57  sturm
% Added fluid declaration von !*rlsism.
%
% Revision 1.32  2007/12/05 14:10:54  sturm
% Removed duplicate definitions of qqe_arg2l and qqe_arg2r.
%
% Revision 1.31  2006/03/14 19:19:05  strasser
% Cosmetic changes.
%
% Revision 1.30  2006/03/03 00:39:42  strasser
% Better error messages for type/sort-error.
%
% Revision 1.29  2006/03/02 13:02:04  strasser
% Add global variable [qqe_debug!*].
%
% Revision 1.28  2006/01/08 17:19:29  strasser
% Renamed [qqe_marked_ids_rollback!*] into [qqe_marked!-ids!-rollback!*] and
% [qqe_qadd_location!*] into [qqe_qadd!-location!*]. Some corrections in
% arg-check algorithm.
%
% Revision 1.27  2006/01/03 00:48:21  strasser
% Add support for [qqeqemisc.red].
% Add fluid [qqe_elimb!*] denoting a switch to decide if QE should also
% eliminate quantifiers of basic type.
%
% Revision 1.26  2005/11/15 22:58:44  strasser
% Bugfix in [qqe_chsimpterm1].
%
% Revision 1.25  2005/11/13 23:45:22  strasser
% Fixed bug in [qqe_chsimpterm].
%
% Revision 1.24  2005/11/13 16:42:12  strasser
% Added functions [qqe_chsimpterm] and [qqe_chsimpterm1] for transformation
% of input ltail(p)^4 --> ltail(ltail(ltail(ltail(p)))). Modified funtion
% [qqe_chsimpat].
%
% Revision 1.23  2005/10/04 13:41:57  strasser
% Improved readability of code. in [qqesiat.red]: Split the function
% [qqe_simplterm] into [qqe_simplterm], [qqe_simplterm!-add],
% [qqe_simplterm!-tail] and [qqe_simplterm!-head]. Improved functionality
% of the term simplitfier.
%
% Revision 1.22  2005/10/04 10:15:38  strasser
% Removed bug from [qqe_arg!-check] and removed begin..end code where not
% needed.
%
% Revision 1.21  2005/10/04 01:40:13  strasser
% Minor changes in [qqe.red] and [qqeqe.red]. Improved handling of different
% standard represantations of atomic formulas in [qqetrans.red].
%
% Revision 1.20  2005/10/03 02:26:48  strasser
% Put infix preceedence information for [qequal] and [qneq] in [qqe_ofsf.red]
% after the declaration of the infix operators.
%
% Revision 1.19  2005/10/03 01:18:23  strasser
% Add [qqe_varsubstat] to [qqe.red]. Some minor changes and removing of
% debugging comments in [qqeqe.red], as well as in [qqetrans.red].
%
% Revision 1.18  2005/10/01 18:05:31  strasser
% Moved [qqe_simplat1], [qqe_simplequal], [qqe_simplqneq] into the new file
% [qqesiat.red]. Upgraded functionality of the simplifier for atomic formulas
% of queue type (qequal, qneq).
%
% Revision 1.17  2005/10/01 02:41:24  strasser
% Some further changes for compatibility with the wrapper packages in the
% file [qqeqe.red]. Comments were changed in [qqe.red].
%
% Revision 1.16  2005/10/01 02:33:26  strasser
% Moved simplifier for atomic formulas [qqe_simplat], [qqe_simplqequal],
% [qqe_simplqneq] from [qqeqe.red] to [qqe.red]. Many minor changes to
% make files from package [qqe]  compatible with wrapper packages, like for
% example [qqe_ofsf]. Changes mainly in [qqeqe.red] and [qqetrans.red].
%
% Revision 1.15  2005/09/29 17:56:25  strasser
% Conventionalized function names ("-" ---> "!-!). Moved the constructor
% functions [qqe_iterate_*] from [qqeqe.red] in [qqe.red] and fixed a bug
% in them.
%
% Revision 1.14  2005/09/29 15:04:31  strasser
% Changed the infix values of 'qequal and 'qneq as they were the same like
% the ones of 'and and 'or.
%
% Revision 1.13  2005/09/29 00:31:28  strasser
% Added function [qqe_prepterm] (it's just identity). Removed the [ofsf]-
% specific algebraic infix operators [equal] and [neq] in the package
% [qqe_ofsf]. Added functions [qqe_lengthat], [qqe_prepat](=id) and
% [qqe_chsimpat]. Made some (temporary(?)) addition to [qqe_enter].
%
% Revision 1.12  2005/09/28 21:43:50  strasser
% Moved the following functions from [qqe.red] to [qqe_ofsf.red]:
% [qqe_simpterm], [qqe_prepat], [qqe_resimpat], [qqe_lengthat],
% [qqe_chsimpat], [qqe_chsimpat1], [qqe_simpat]. Renamed the functions
% according to the new package, e.g. [qqe_...] -> [qqe_ofsf_...].
% Changed in the functions the behaviour of the wrapper.
%
% Revision 1.11  2005/09/27 18:31:39  sturm
% Some minor fixes.
%
% Revision 1.10  2005/09/27 18:08:42  sturm
% Finished first version of enter/exit in qqe.red.
% Moved params and services to qqe_ofsf and did some work there (for testing).
%
% Revision 1.9  2005/09/27 14:44:26  sturm
% Working on qqe_enter framework. Current status is not working!
%
% Revision 1.8  2005/09/26 11:01:45  strasser
% Temporary checkin for testing of reading of formulas.
%
% Revision 1.7  2005/09/19 15:10:12  strasser
% Added modules [qqemisc], [qqelim] and [qqesism]. [qqesism] is at the
% moment needed for compatibility reasons with [ofsf]. [qqemisc] contains
% miscellaneous functions which are needed in support of algorithms in
% various modules. [qqelim] contains quantorelimination of quantors of
% type queue.
%
% Revision 1.6  2005/09/13 11:20:14  strasser
% Corrected handling of 'equal.
% Added constant 'qepsilon.
% Added transformation of formulas containing ladd, radd into formulas only
% containing heads and tails, which is supposed to be the standard input
% format for qe over languages with queues. Add module qqetrans.
%
% Revision 1.5  2005/09/08 23:10:34  strasser
% Added some comments for the rollback process.
%
% Revision 1.4  2005/09/08 22:59:23  strasser
% Added typed identifier rollback for identifiers which got typed while
% processing an incorrect formula.
%
% Revision 1.3  2005/09/08 18:16:32  strasser
% Added fancy-print for qequal and qneq for texmacs support.
%
% Revision 1.2  2005/09/08 16:19:53  strasser
% Added internal representation of formulas with the queue operators.
% Recursivly checking atomic formulas for correct types of arguments.
% Has to be loaded by 'rlset qqe' and works at the moment with ofsf for
% the basic type.
%
% Revision 1.1  2005/09/05 18:39:26  sturm
% Initial check-in.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(qqe_rcsid!* qqe_copyright!*);
   qqe_rcsid!* := "$Id: qqe.red,v 1.33 2007/12/16 12:41:57 sturm Exp $";
   qqe_copyright!* := "Copyright (c) 2005-2008 by A. Dolzmann and T. Sturm"
>>;


module qqe;
% Quantorelimination for queues. Main module. Algorithms on formulas 
% in the two-sorted logic consisting of basic and queue sort. 
% The language contains additional binary functions ['ladd], ['radd],
% as well as unary functions ['lhead], ['rhead], ['ltail], ['rtail]. 
% Additional binary logic operators are ['qequal] and ['qneq].

create!-package('(qqe qqetrans qqemisc qqesism 
   qqeqe qqesiat qqeqemisc),nil);

load!-package 'rltools;
% load!-package 'qqe_ofsf;

exports qqe_chsimpat;

imports cl,rltools;

fluid '(qqe_marked!-ids!-rollback!* qqe_qadd!-location!* 
   qqe_elimb!* qqe_debug!* !*rlsism);

flag('(qqe),'rl_package);

put('qqe,'rl_enter,'qqe_enter);

put ('qqe,'simpfnname, 'rl_simpfn);

%% put('qqe,'rl_prepat,'qqe_prepat);
%% put('qqe,'rl_resimpat,'qqe_resimpat); 
put('qqe,'rl_lengthat,'qqe_lengthat);

put('qqe,'rl_prepterm,'qqe_prepterm);
put('qqe,'rl_simpterm,'qqe_simpterm);

algebraic infix qequal;
put('qequal,'rl_prepfn,'qqe_prepat);
put('qequal,'rl_simpfn,'qqe_chsimpat);
put('qequal,'number!-of!-args,2);
put('qequal,'rtypefn,'quotelog);
put('qequal,'fancy!-prifn,'qqe_fancy!-priqequal);
newtok '((!= !=) qequal);
flag('(qequal),'spaced);

algebraic infix qneq;
put('qneq,'rl_prepfn,'qqe_prepat);
put('qneq,'rl_simpfn,'qqe_chsimpat);
put('qneq,'number!-of!-args,2);
put('qneq,'rtypefn,'quotelog);
put('qneq,'fancy!-prifn,'qqe_fancy!-priqneq);
newtok '((!< !< !> !>) qneq);
flag('(qneq),'spaced);

algebraic operator qepsilon;  % -> qqe_enter TODO
put('qepsilon,'number!-of!-args,0);
put('qepsilon,'idtype,'qt);

algebraic operator ladd;
put('ladd,'qqe_number!-of!-args,2);

algebraic operator radd;
put('ladd,'qqe_number!-of!-args,2);

algebraic operator lhead;
put('ladd,'qqe_number!-of!-args,1);

algebraic operator rhead;
put('ladd,'qqe_number!-of!-args,1);

algebraic operator rtail;
put('ladd,'qqe_number!-of!-args,1);

algebraic operator ltail;
put('ladd,'qqe_number!-of!-args,1);

flag('(qqe_chsimpat),'full);
!*rlsism := nil;  
%else failure in simplifier cl_simpl  -> context switch

procedure qqe_enter(argl);
   begin scalar w,qqecid2;
      if null argl then
	 return nil . "base type context missing";

      qqe_elimb!* := nil;

      qqecid2 := intern compress nconc(explode 'qqe_,explode car argl);
      w := qqe_load!-basetype(qqecid2,cdr argl);
      if w then return nil . w;
      qqe_patch!-ctag(qqecid2,'qqe_params,'rl_params);
      qqe_patch!-ctag(qqecid2,'qqe_services,'rl_services);
      qqe_patch!-ctag(qqecid2,'qqe_cswitches,'rl_cswitches);

      % Begin CS
      put('qqe,'rl_resimpat,intern compress nconc(explode qqecid2,
         explode '!_resimpat));
      put('qqe,'rl_prepat,intern compress nconc(explode qqecid2,
         explode '!_prepat));
      % End CS

      % temporarily
      put('qneq,'infix,32);
      put('qequal,'infix,31);

      return t . argl  % means no error
   end;

procedure qqe_load!-basetype(qqecid2,argl);
   % Setup base type context. [cid2] is an identifier. This code
   % resembles rl_enter() in submodule rlcont.
   begin scalar w,enter;
      w := errorset({'load!-package,mkquote(qqecid2)},nil,!*backtrace)
	 where !*msg=nil;
      if errorp w then
	 return {"switching to base type wrapper",qqecid2,"failed"};
      if not flagp(qqecid2,'rl_package) then
	 return {qqecid2,"is not an rl package"};
      enter := get(qqecid2,'rl_enter);
      if null enter and argl then
	 lprim {"extra",ioto_cplu("argument",cdr argl),"ignored"};
      if enter then <<
      	 w := apply(enter,{argl});
      	 if not car w then
	    return cdr w
      	 else
	    argl := cdr w
      >>;
      return nil  % means no error
   end;

procedure qqe_patch!-ctag(qqecid2,qqeal,rlal);
   begin scalar w;
      w := get('qqe,qqeal);
      for each x in get(qqecid2,rlal) do
	 if not atsoc(car x,w) then
	    w := x . w;
      put('qqe,rlal,w)
   end;

procedure qqe_exit();
   ;

procedure qqe_lengthat(f);
   2;

procedure qqe_prepat(f);
   f;

procedure qqe_simpat(f);
   f;

procedure qqe_prepterm(f);
   f;

procedure qqe_chsimpat(f);
   begin
      cadr f := qqe_chsimpterm(qqe_arg2l f);
      caddr f := qqe_chsimpterm(qqe_arg2r f);
      qqe_arg!-check f;
      return f;
   end;

procedure qqe_chsimpterm(term);
   begin
      if atom term then term
      else if qqe_op term eq 'expt then term := qqe_chsimpterm1(term)
      else if qqe_op term memq '(ltail rtail) then 
         cadr term := qqe_chsimpterm(cadr term)
      else if qqe_op term memq '(ladd radd) then 
         caddr term := qqe_chsimpterm(caddr term)
      else if qqe_op term memq '(lhead rhead) then 
         cadr term := qqe_chsimpterm(cadr term);
      return term;
   end;

procedure qqe_chsimpterm1(term);
   begin scalar op, arg;
      op := qqe_op qqe_arg2l term;
      arg := qqe_chsimpterm qqe_arg2l term;
      for j:=1:(qqe_arg2r term)-1 do <<
         arg := op . {arg};
      >>;
      return arg;
   end;

procedure qqe_op(atf);
   % QQE operator. [atf] is an atomic formula
   % $R(t_1,t_2)$. Returns $R$.
   car atf;

procedure qqe_lhs(atf);
   cadr atf;

procedure qqe_rhs(atf);
   caddr atf;

procedure qqe_arg2l(atf);
   % qqe binary operator left hand side argument. [atf] is
   % an atomic formula $R(t_1,t_2)$. Returns $t_1$.
   cadr atf;

procedure qqe_arg2r(atf);
   % qqe binary operator right hand side argument. [atf] is
   % an atomic formula $R(t_1,t_2)$. Returns $t_2$.
   caddr atf;

procedure qqe_argn(atf);
   % qqe binary operator right hand side argument. [atf] is
   % an atomic formula $R(t_1,t_2)$. Returns the list $(t_1,t_2)$.
   {cadr atf,caddr atf};

procedure qqe_mk2(op,lhs,rhs);
   % qqe constructor for binary operator. [op] is a relation
   % [lhs] and [rhs] are terms. Returns the atomic formula
   % $[op]([lhs],[rhs])$.
   {op,lhs,rhs};

procedure qqe_0mk2(op,lhs);
   % qqe zero constructor for binary operator. [op] is a
   % relation [lhs] is a term. Returns the atomic formula
   % $[op]([lhs],0)$.
   {op,lhs,nil};

procedure qqe_mkn(op,argl);
   % qqe constructor for binary operator. [op] is a relation
   % [argl] is a list $(t_1,t_2)$ of terms. Returns the atomic formula
   % $[op](t_1,t_2)$.
   {op,car argl,cadr argl};

procedure qqe_rqopp(op);
   % qqe relation queue type operator predicate. [op] is an
   % S-expression. Returns [nil] if op is not a relation with queue
   % type arguments.
   op memq '(qequal qneq);

% should be replaced later in favour of dynamic application to 
% different basic theories, for example: 
% if rlset = ofsf then qqe_rbopp -> ofsf_opp
procedure qqe_rbopp(op);
   % qqe relation basic type operator predicate. [op] is an
   % S-expression. Returns [nil] if op is not a relation with
   % basic type arguments.
   op memq '(equal neq lessp leq geq greaterp);

% obsolete
%% procedure qqe_luopp(op);
%%    % qqe logic unary operator 
%%    op = 'neg;

procedure qqe_ropp(op);
   % qqe relation operator predicate. [op] is an
   % S-expression. Returns [nil] if op is not a relation.
   qqe_rqopp op or qqe_rbopp op;
   
procedure qqe_qopp(op);
   % qqe queue operator predicate. [op] is an
   % S-expression. Returns [nil] if op is not a function of queue type.    
   op memq '(radd ladd lhead rhead ltail rtail);
    
procedure qqe_qopheadp(op);
   % qqe queue operator lhead or rhead predicate. [op] is an
   % S-expression. Returns [nil] if op is not lhead or rhead.
   op memq '(lhead rhead);

procedure qqe_arg!-check(u);
    % qqe argument check. [u] is an S-expression.
    % Checks for lhs and rhs of an atomic formula
    % recursivly if arguments are of correct type else error msg.
    <<
       if qqe_rqopp op then qqe_arg!-check!-lq!-rq u

       else if qqe_rbopp op then qqe_arg!-check!-lb!-rb u
          
       else if qqe_qopheadp op or qqe_qoptailp op 
       then << if not qqe_arg!-check!-q cadr u then <<
          qqe_arg!-check!-marked!-ids!-rollback();
          typerr(u,"some arguments are not of queue type");
       >>;
       >>
          
       else if qqe_qopaddp op then qqe_arg!-check!-lb!-rq u
          
       else % plus, minus, etc.
       % <<  
          for each x in cdr u do
             if not qqe_arg!-check!-b x then <<
                qqe_arg!-check!-marked!-ids!-rollback();
                typerr(u,"some arguments are not of basic type");
             >>;
          
%%           if not qqe_arg!-check!-b lhs then 
%%           <<
%%              qqe_arg!-check!-marked!-ids!-rollback();
%%              typerr(u,"binary op with basic type args");
%%           >>;
%%           if rhs and not qqe_arg!-check!-b rhs then
%%           <<
%%              qqe_arg!-check!-marked!-ids!-rollback();
%%              typerr(u,"binary op with basic type args");
%%           >>;
%% 
%%        >> where lhs=cadr u, rhs=if cddr u then caddr u else nil;

    >> where op=car u;
  

procedure qqe_arg!-check!-lb!-rq(u);
   % qqe argument check lhs basic rhs queue type. 
   % [u] is an S-expression. 
   % Checks for lhs and rhs of a function
   % recursivly if arguments are of correct type else error msg.
   begin scalar lhs, rhs;
      lhs := cadr u; rhs := caddr u;
      % rhs
      if not qqe_arg!-check!-q rhs then
      <<
         qqe_arg!-check!-marked!-ids!-rollback();
         typerr(u,"type conflict: arguments don't fit 
            binary op with lhs basic type and rhs queue type");
      >>;

      % lhs
      if not qqe_arg!-check!-b lhs then
      <<
         qqe_arg!-check!-marked!-ids!-rollback();
         typerr(u,"type conflict: arguments don't fit
            binary op with lhs basic type and rhs queue type");
      >>;

   end;

procedure qqe_arg!-check!-lq!-rq(u);
   % qqe argument check lhs queue rhs queue type. 
   % [u] is an S-expression. 
   % Checks for lhs and rhs of a function
   % recursivly if arguments are of correct type else error msg.
   begin scalar lhs, rhs;
       lhs := cadr u; rhs := caddr u;
       % lhs
       if not qqe_arg!-check!-q lhs then
       <<
          qqe_arg!-check!-marked!-ids!-rollback();
          typerr(u,"type conflict: arguments don't fit 
             binary op with queue type args");
       >>;

       % rhs
       if not qqe_arg!-check!-q rhs then
       <<
          qqe_arg!-check!-marked!-ids!-rollback();
          typerr(u,"type conflict: arguments don't fit
             binary op with queue type args");
       >>;
   end;

procedure qqe_arg!-check!-q(u);
   % qqe argument check queue type. 
   % [u] is an S-expression. 
   % Checks for argument of a function
   % recursivly if arguments are of correct type else error msg.
   begin
      if not qqe_id!-nyt!-branchq u then return nil
      else if atom u and not numberp u then
      <<
         if qqe_btidp u then return nil
         else if qqe_nytidp u then 
         <<
            qqe_qtid u;
            qqe_add2rollbackids u;
            return t;
         >>
         else return t;
      >>
      else if not numberp u then 
      <<
         qqe_arg!-check u;
         return t;
      >>
   end;

procedure qqe_arg!-check!-b(u);
   % qqe argument check basic type. 
   % [u] is an S-expression. 
   % Checks for argument of a function
   % recursivly if arguments are of correct type else error msg.
   begin  
      if not qqe_id!-nyt!-branchb u then return nil
      else if atom u and not numberp u then 
      <<
         if qqe_qtidp u then return nil 
         else if qqe_nytidp u then 
         <<
            qqe_btid u;
            qqe_add2rollbackids u;
            return t;
         >>
         else return t;
      >>
      else if not atom u then 
      <<
         qqe_arg!-check u;
         return t;
      >>
      else return t; % numbers
   end;

procedure qqe_arg!-check!-lb!-rb(u);
   % qqe argument check lhs basic rhs basic type. 
   % [u] is an S-expression. 
   % Checks for lhs and rhs of a function
   % recursivly if arguments are of correct type else error msg.
   begin scalar lhs, rhs;
       lhs := cadr u; rhs := caddr u;
       % lhs
       if not qqe_arg!-check!-b lhs then
       <<
          qqe_arg!-check!-marked!-ids!-rollback();
          typerr(u,"type conflict: arguments don't fit
             binary op with basic type args");
       >>;

       % rhs
       if not qqe_arg!-check!-b rhs then
       <<
          qqe_arg!-check!-marked!-ids!-rollback();
          typerr(u,"type conflict: arguments don't fit 
             binary op with basic type args");
       >>;
   end;
    
procedure qqe_qoptailp(op);
    % qqe queue operator rtail or ltail. [op] is a
    % S-expression. Returns [nil] if op is not rtail or ltail.
    if op memq '(rtail ltail) then t;
    
procedure qqe_qopaddp(op);
   % qqe queue operator ladd or radd. [op] is a
    % S-expression. Returns [nil] if op is not ladd or radd.
    if op memq '(ladd radd) then t;
    
procedure qqe_id!-nyt!-branchq(u);
    % qqe identifier not yet typed branch queue type. checks if the 
    % argument u is of type queue or not yet typed.
    % Returns [nil] if argument is of type basic.
    if atom u then (qqe_qtidp u or qqe_nytidp u)
    else (qqe_qopaddp car u or qqe_qoptailp car u); 
   
procedure qqe_id!-nyt!-branchb(u);
   % qqe identifier not yet typed branch basic type. checks if the 
   % argument u is of type basic or not yet typed.
   % Returns [nil] if argument is of type queue.
   if atom u then (qqe_btidp u or qqe_nytidp u)
   else not(qqe_qopaddp car u or qqe_qoptailp car u);
   
procedure qqe_btid(u);
    % qqe basic type identifier. [u] is atom.    
    % Set idtype on basic type. Error msg if idtype of u 
    % is queue.
    % if qqe_qtidp u then typerr(u, "is queue type.")
    %    else 
    put(u,'idtype,'bt);

procedure qqe_qtid(u);
    % qqe queue type identifier. [u] is atom.
    % Set idtype on queue type. Error msg if idtype of u 
    % is basic.
    % if qqe_btidp u then typerr(u, "is basic type")
    %    else 
    put(u,'idtype,'qt);

procedure qqe_niltid(u);
   % qqe nil type identifier. [u] is atom.
   % Set idtype on nil. Needed for rollback of typed identifiers
   % while processing incorrect formula.
   put(u,'idtype,nil);
    
procedure qqe_btidp(u);
    % qqe basic type identifier predicate. [u] is atom. 
    % Returns [idtype] of u. Return [nil] if idtype is not yet set.
    get(u,'idtype) = 'bt;

procedure qqe_qtidp(u);
    % qqe queue type identifier predicate. [u] is atom. 
    % Returns [idtype] of u. Return [nil] if idtype is not yet set.
    get(u,'idtype) = 'qt; 

procedure qqe_nytidp(u);
   % qqe queue not yet set type identifier predicate. [u] is atom. 
   % Returns [true] if idtype is not set, [nil] if idtype is set.
   get(u, 'idtype) = nil;
    
procedure qqe_fancy!-priqequal(l);
   % qqe standard form texmacs print a queue equality. [l] is a
   % lisp prefix. Returns 'failed iff printing failed.
   if rl_texmacsp() then
      qqe_fancy!-priqequal!-texmacs l;

procedure qqe_fancy!-priqequal!-texmacs(l);
   % qqe standard form texmacs print a queue equality. [l] is a
   % lisp prefix. Returns 'failed iff printing failed.
   if null !*nat then 'failed
   else <<
      maprin cadr l; %lhs
      % other options: 
      % fancy!-prin2 "\mathop = \limits_{q}";
      % fancy!-prin2 "\circeq"; etc.
      fancy!-prin2 "\leftrightharpoons";
      % fancy!-prin2!-underscore();
      fancy!-prin2 " ";
      maprin caddr l; %rhs
   >>;
      
procedure qqe_fancy!-priqneq(l);
   % qqe standard form texmacs print a queue not equality. [l] is a
   % lisp prefix. Returns 'failed iff printing failed.
   if rl_texmacsp() then
      qqe_fancy!-priqneq!-texmacs l;

procedure qqe_fancy!-priqneq!-texmacs(l);
   % qqe standard form texmacs print a queue not equality. [l] is a
   % lisp prefix. Returns 'failed iff printing failed.
   if null !*nat then 'failed
   else <<
      maprin cadr l; %lhs
      fancy!-prin2 "\ll\gg";
      fancy!-prin2!-underscore();
      fancy!-prin2 " ";
      maprin caddr l; %rhs
   >>;

procedure qqe_arg!-check!-marked!-ids!-rollback();
   % qqe argument check marked identifiers rollback. While processing
   % a given formula with qqe_arg!-check identifiers get typed
   % according to which relation or functions they belong.
   % If processing an incorrect formula it can happen, that variables
   % get typed. This identifiers get stored in the list
   % qqe_marked!-ids!-rollback!*. Undo the typing of identifiers in
   % qqe_marked!-ids!-rollback!*.
   while qqe_marked!-ids!-rollback!* neq nil do
   <<
      qqe_niltid car qqe_marked!-ids!-rollback!*;
      qqe_marked!-ids!-rollback!* := cdr qqe_marked!-ids!-rollback!*;
   >>;

procedure qqe_add2rollbackids(u);
   % qqe add to rollback identifiers list. [u] is an atom.
   % Add variables being typed while processing a given formula with 
   % qqe_check_args to the list qqe_marked!-ids!-rollback!*.
   qqe_marked!-ids!-rollback!* := u . qqe_marked!-ids!-rollback!*;

procedure qqe_iterate!-ltail(j, arg);
   % Queue quantor elimination iterate ltail. [j] is an integer.
   % [arg] is a lisp prefix.
   % Function returns ltail**j(arg).
   begin scalar term;
      term := arg;
      for jj:=1:j do
      <<
         term := {'ltail, term};
      >>;
      return term;
   end;

procedure qqe_iterate!-rtail(j, arg);
   % Queue quantor elimination iterate rtail. [j] is an integer.
   % [arg] is a lisp prefix.
   % Function returns rtail**j(arg).
   begin scalar term;
      term := arg;
      for jj:=1:j do
      <<
         term := {'rtail, term};
      >>;
      return term;
   end;

procedure qqe_iterate!-radd(j,arg, list);
   % Queue quantor elimination iterate radd. [j] is an integer.
   % [arg] is a lisp prefix. [list] is a list of lisp prefixes.
   % Function returns radd(l(j),radd(l(j-1) ....,arg)))).
   begin scalar term,l;

      term := arg;
      l := list;

      for jj:=1:j do
      <<
         term := {'radd, car l, term};
         l := cdr l;
      >>;
      return term;

   end;

procedure qqe_iterate!-ladd(j,arg,list);
   % Queue quantor elimination iterate Ladd. [j] is an integer.
   % [arg] is a lisp prefix. [list] is a list of lisp prefixes.
   % Function returns ladd(l(j),ladd(l(j-1) ....,arg)))).
   begin scalar term,l;

      term := arg;
      l := list;

      for jj:=1:j do
      <<
         term := {'ladd, car l, term};
         l := cdr l;
      >>;
      return term;

   end;

procedure qqe_varsubstat(atf,new,old);
   % Ordered field standard form substitute variable for variable in
   % atomic formula. [atf] is an atomic formula; [new] and [old] are
   % variables. Returns an atomic formula equivalent to [atf] where
   % [old] is substituted with [new].
   qqe_mk2(qqe_op atf,subst(new, old, qqe_arg2l atf),
      subst(new,old,qqe_arg2r atf));

endmodule;  % [qqe]

end;  % of file
