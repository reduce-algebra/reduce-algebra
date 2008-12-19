% ----------------------------------------------------------------------
% $Id: qqeqe.red,v 1.40 2007/12/16 12:43:37 sturm Exp $
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

% $Log: qqeqe.red,v $
% Revision 1.40  2007/12/16 12:43:37  sturm
% Renamed qqe_exit to qqe_qeexit to avoid ambiguity  with the by now empty
% exit function for the context.
%
% Revision 1.39  2007/07/23 16:41:31  strasser
% Bugfix in [qqe_qe!-clause]: After the call of [qqe_qe!-dna] formulas in
% [qqe_resf!*] were not taken into account, which lead in some cases to
% false results.
%
% Revision 1.38  2006/03/20 03:12:25  strasser
% Updated for support of better simplification algorithm. Exchanged the word
% "quantor" with "quantifier".
%
% Revision 1.37  2006/03/14 19:20:43  strasser
% Cometic changes and a small bugfix in [qqe_qe].
%
% Revision 1.36  2006/03/03 00:40:43  strasser
% Removed procedure [qqe_atf!-dna!-nfd!-phi] which is no longer needed.
% Some minor fixes.
%
% Revision 1.35  2006/03/02 17:38:21  strasser
% Making quantifier switch from 'all' to 'ex' the property of being a
% harmless formula could get lost. Fixed that.
%
% Revision 1.34  2006/03/02 13:09:41  strasser
% Debug messages now depend on the variable [qqe_debug!*]. Minor fixes.
%
% Revision 1.33  2006/01/17 05:22:11  strasser
% Add support for the new min/maxlength calculation from module
% [qqemisc.red]. Instead of [qqe_length!-graph!-clause] now
% [qqe_clause!-update!-lengths] is called.
%
% Revision 1.32  2006/01/08 17:36:54  strasser
% Added a case distincion in [qqe_qe!-clause].
%
% Revision 1.31  2006/01/03 00:35:23  strasser
% Add a lot of comments. Removed comments which were for coding purposes.
% [qqe_ndna] has now four instead of five arguments. Removed procedure
% [qqe_make!-phi2]. Add procedure [qqe_ndna!-qneq!-ext!-phi2!-true] and
% [qqe_ndna!-qneq!-ext]. Introduced switch [qqe_elimb!*] deciding if [qqe_qe]
% eliminates also quantifiers of basic type.
%
% Revision 1.30  2006/01/02 01:59:38  strasser
% Split module [[qqeqe.red]] in [[qqeqe.red]] and [[qqeqemisc.red]].
% Moved the following functions in [[qqeqemisc.red]]:
% - qqe_insert!-resf
% - qqe_insert!-qvarf
% - qqe_sort!-resf!-qvarf
% - qqe_atf!-qequal!-ext!-c
% - qqe_atf!-qequal!-ext!-p
% - qqe_atf!-equal!-ext
% - qqe_atf!-equal!-int
% - qqe_atf!-qequal!-int
% - qqe_atf!-qneq!-ext
% - qqe_atf!-qneq!-ext!-qepsilon
% - qqe_atf!-neq
% - qqe_atf!-qneq!-int
% - qqe_atf!-misc!-basic
% - qqe_sort!-atf
% - qqe_la
% - qqe_max!-lefts!-bs!-recursive
% - qqe_max!-lefts!-ls!-recursive
% - qqe_max!-lefts!-term!-recursive
% - qqe_max!-lefts!-lhs
% - qqe_max!-lefts!-bs
% - qqe_max!-rights!-lhs
% - qqe_max!-rights!-bs
% - qqe_ra
% - qqe_max!-rights!-bs!-recursive
% - qqe_max!-rights!-ls!-recursive
% - qqe_max!-rights!-term!-recursive
% - qqe_minlength
% - qqe_max!-prefix!-length!-term!-recursive
% - qqe_maxlength
% - qqe_maxlength1
% - qqe_patpos
% - qqe_pat!-lengths
% - qqe_pat!-length
% - qqe_get!-quantor!-sequenz
% - qqe_atf!-qequal!-ext!-min!-prefix
% - qqe_atf!-qequal!-ext!-p!-min!-lefts
% - qqe_atf!-qequal!-ext!-p!-min!-rights
% - qqe_qprefix!-var
% - qqe_new!-ids!-x
% - qqe_make!-id!-x
% - qqe_list!-take!-n
% - qqe_subst
% - qqe_subst!-batf
% - qqe_subst!-bterm
% - qqe_subst!-qequal!-ext!-p
% - qqe_subst!-qneq!-ext
% - qqe_makef!-qneq2equal
% - qqe_subst!-qneq!-int
% - qqe_subst!-qequal!-int
% - qqe_makef!-list2qneq
% - qqe_makef!-list2equal
% - qqe_makef!-qequal2equal
% - qqe_makef!-termlength!-l
% - qqe_makef!-termlength!-g
% - qqe_subst!-simplterm
% - qqe_subst!-simplterm!-lhead
% - qqe_subst!-simplterm!-rhead
% - qqe_ndna!-qneq!-ext
% - qqe_iterate!-quantor!-ex
% - qqe_iterate!-quantor.
%
% Revision 1.29  2006/01/02 01:17:57  strasser
% Changed some code in order to achieve smaller satlengths.
% Add fluid [[qqe_atf!-qneq!-ext!-qepsilon!*]].
% Add function [[qqe_atf!-qneq!-ext!-qepsilon]].
% Add basic type qe for the extra variables of basic type, which
% are generated in the qqe.
%
% Revision 1.28  2005/12/18 18:57:23  strasser
% Add some comments. QE works now also with "all" quantifiers. Bugfixes in
% the function tree of [qqe_subst] and [qqe_ndna!-qneq!-ext].
%
% Revision 1.27  2005/12/16 23:55:04  strasser
% Add functions: [qqe_list!-take!-n], [qqe_subst], [qqe_subst!-batf],
% [qqe_subst!-bterm], [qqe_subst!-qequal!-ext!-p], [qqe_subst!-qneq!-ext],
% [qqe_makef!-qneq2equal], [qqe_subst!-qneq!-int], [qqe_subst!-qequal!-int],
% [qqe_makef!-list2qneq], [qqe_makef!-list2equal], [qqe_makef!-qequal2equal],
% [qqe_makef!-termlength!-l], [qqe_makef!-termlength!-g],
% [qqe_subst!-simplterm], [qqe_subst!-simplterm!-lhead],
% [qqe_subst!-simplterm!-rhead].
% This speeds up the qe very much, as it provides on-the-fly translation,
% which is specially adapted to the format of the terms containing l/radds
% produced by the qe-procedure, so that module [qqetrans] has only to be called
% in the beginning of the qe.
%
% Revision 1.26  2005/12/16 02:15:03  strasser
% Add functions [qqe_make!-phi2] and [qqe_ndna!-qneq!-ext].
% Changes in [qqe_satlengths] and [qqe_ndna].
%
% Revision 1.25  2005/11/20 19:25:09  strasser
% Bugfix in [qqe_qe!-dna!-nfd]. Added functions [qqe_make!-cpg],
% [qqe_cpg!-make!-root], [qqe_cpg!-make!-node], [qqe_cpg!-make!-supernode],
% [qqe_cpg!-supernode!-last], [qqe_cpg!-supernode!-first], [qqe_cpg!-incl],
% [qqe_cpg!-excl], [qqe_cpg!-make!-incl], [qqe_cpg!-insert],
% [qqe_cpg!-make!-excl], [qqe_cpg!-empty!-graph],
% [qqe_cpg!-insert!-supernode], [qqe_cpg!-minlength!-node],
% [qqe_cpg!-maxlength!-node], [qqe_cpg!-var], [qqe_cpg!-insert!-incl],
% [qqe_cpg!-insert!-excl]. Some other minor changes.
%
% Revision 1.24  2005/11/15 22:45:28  strasser
% QE uses now the routines [qqe_harmless!-formula!-test!-clause1] to produce
% error message for a big class of non harmless formulas and
% [qqe_simpl!-clause] for simplification with help of min-/maxlength
% calculation.
%
% Revision 1.23  2005/11/14 13:31:15  strasser
% Bugfix in [qqe_satlengths].
%
% Revision 1.22  2005/11/13 23:50:45  strasser
% Added support for the min- and maxlength calculation from module [qqemisc].
%
% Revision 1.21  2005/11/09 21:59:29  strasser
% For module [qqeqe.red] changes in calculation of satlengths. For module
% [qqesiat]: added functions [qqe_simplbtat], [qqe_eta!-in!-term],
% [qqe_eta!-in!-term1]. In [qqetrans.red] minor changes.
%
% Revision 1.20  2005/11/08 03:08:28  strasser
% In module [qqetrans.red] changes in function-tree [qqe_la2lth!-addin].
% In module [qqeqe.red] changes in functions for calculating satlengths.
% Both areas are still under construction.
%
% Revision 1.19  2005/10/30 22:04:44  strasser
% Added [qqe_bridge], [qqe_bridge!-list], [qqe_qe!-clause!-init] to
% [qqeqe.red]. Changes in [qqe_satlengths]. Some minor changes in
% [qqemisc.red].
%
% Revision 1.18  2005/10/29 18:19:12  strasser
% Removed a bug in [qqe_atf!-dna!-nfd!-rho]. Removed some debug messages.
%
% Revision 1.16  2005/10/26 01:19:20  strasser
% Changed variable and function names [qqe_con!-...] in
% [qqe_atf!-...]. Added variable [qqe_atf!-misc!-basic!*], function
% [qqe_atf!-misc!-basic], [qqe_max!-lefts!-term!-recursive],
% [qqe_max!-lefts!-ls!-recursive], [qqe_max!-lefts!-bs!-recursive], and
% analogous for rights, [qqe_max!-prefix!-length!-term!-recursive],
% [qqe_atf!-qequal!-ext!-max!-prefix], [qqe_atf!-dna!-nfd!-psi!-subst].
% Made sorting of atomic formulas with the function tree [qqe_sort!-atf]
% more efficient. Changes in the function tree [qqe_qe!-dna!-nfd] to use
% less basic type quantifiers in the elimination process. Many minor
% changes in various places. Some work still to do, that means: file is
% compiling but not working at the moment.
% ----------------------------------------------------------------------
% ----------------------------------------------------------------------
%
% Revision 1.15  2005/10/06 01:55:46  strasser
% Some changes in [qqe_prefix!-lefts] and [qqe_prefix!-rights], as well as a
% bugfix in [qqe_lcm!-list]. Worked on [qqe_satlengths] and functions in that
% execution tree.
%
% Revision 1.14  2005/10/04 13:41:57  strasser
% Improved readability of code. in [qqesiat.red]: Split the function
% [qqe_simplterm] into [qqe_simplterm], [qqe_simplterm!-add],
% [qqe_simplterm!-tail] and [qqe_simplterm!-head]. Improved functionality
% of the term simplitfier.
%
% Revision 1.13  2005/10/04 01:40:13  strasser
% Minor changes in [qqe.red] and [qqeqe.red]. Improved handling of different
% standard represantations of atomic formulas in [qqetrans.red].
%
% Revision 1.12  2005/10/03 19:28:37  strasser
% Added use of blackboxes [rl_prepat] and [rl_chsimpat] instead of direct
% access to wrapper functions.
%
% Revision 1.11  2005/10/03 01:18:23  strasser
% Add [qqe_varsubstat] to [qqe.red]. Some minor changes and removing of
% debugging comments in [qqeqe.red], as well as in [qqetrans.red].
%
% Revision 1.10  2005/10/02 18:52:18  strasser
% Fixed a syntax failure in the output of the function [qqe_qe!-dna!-nfd].
% The sequenz of quantors of basic type is now placed correctly.
%
% Revision 1.9  2005/10/02 02:40:11  strasser
% Many smaller bugfixes for the elimination process for arbitrary formulas.
%
% Revision 1.8  2005/10/01 20:37:20  strasser
% Some minor changes.
%
% Revision 1.7  2005/10/01 15:49:04  strasser
% Moved the functions [qqe_prefix!-length], [qqe_prefix!-lefts],
% [qqe_prefix!-rights], [qqe_lcm], [qqe_lcm!-list], [qqe_plcm],
% [qqe_plcm!-list], [qqe_quicksort]. Made [qqe_prefix!-*] ofsf-compatible.
%
% Revision 1.6  2005/10/01 02:41:24  strasser
% Some further changes for compatibility with the wrapper packages in the
% file [qqeqe.red]. Comments were changed in [qqe.red].
%
% Revision 1.5  2005/10/01 02:33:26  strasser
% Moved simplifier for atomic formulas [qqe_simplat], [qqe_simplqequal],
% [qqe_simplqneq] from [qqeqe.red] to [qqe.red]. Many minor changes to
% make files from package [qqe]  compatible with wrapper packages, like for
% example [qqe_ofsf]. Changes mainly in [qqeqe.red] and [qqetrans.red].
%
% Revision 1.4  2005/09/29 17:56:25  strasser
% Conventionalized function names ("-" ---> "!-!). Moved the constructor
% functions [qqe_iterate_*] from [qqeqe.red] in [qqe.red] and fixed a bug
% in them.
%
% Revision 1.3  2005/09/29 15:04:31  strasser
% Changed the infix values of 'qequal and 'qneq as they were the same like
% the ones of 'and and 'or.
%
% Revision 1.2  2005/09/27 14:32:02  sturm
% Some corrections within the header.
%
% Revision 1.1  2005/09/26 22:05:39  strasser
% Adding file qqemisc.red, qqeqe.red, qqesism.red and qqetrans.red now
% with correct headers as well as the lisp header block.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(qqe_qe_rcsid!* qqe_qe_copyright!*);
   qqe_qe_rcsid!* := "$Id: qqeqe.red,v 1.40 2007/12/16 12:43:37 sturm Exp $";
   qqe_qe_copyright!* := "Copyright (c) 2005-2008 by A. Dolzmann and T. Sturm"
>>;


module qqeqe;
% Quantifierelimination for queues. Module with algorithms
% for elimination process.



fluid '(qqe_resf!*  % list of atomic formulas not containing the 
                       % bounded variable -qvar-, which actually has
                       % to be eliminated
   qqe_qvarf!*      % list of atomic formulas containing qvar
   qqe_atf!-qequal!-ext!-c!* % list of atomic formulas of form: q == p
   qqe_atf!-qequal!-ext!-p!* % list of atomic formulas of form: Lq == p
   qqe_atf!-equal!-ext!* % list of at. formulas of form: t( ..,Lq,..) = ..
   qqe_atf!-equal!-int!* % list of atomic formulas of form: 
                         % t(...,Lq,...)=t(...,Mq,...)
   qqe_atf!-misc!-basic!* % list of atf of basic type not = or neq
   qqe_atf!-qequal!-int!*   % list of atomic formulas of form: Lq == Mq
   qqe_la!*         % left area
   qqe_ra!*         % right area
   qqe_pat!-lengths!* % list of pattern lengths
   qqe_sf!*         % formula to be quantifiereliminated
   qqe_atf!-qneq!-int!* % list of atomic formulas of form: Lq<<>>Mq
   qqe_atf!-qneq!-ext!* % list of atomic formulas of form: Lq<<>>p
   qqe_atf!-qneq!-ext!-qepsilon!* % list of atform. of form Lq <<>> qeps.
   qqe_atf!-neq!*    % list of atomic formulas of form: t(..,Lq,..) neq ..
   % qqe_atf!-neq!-int!-s!* % list of atomic formulas of form: 
                          % head(..(p)) neq head(..(p))
   qqe_var!*         % quantifier which binds qqe_var!* has to be 
                        % eliminated
   qqe_qqu!-list!*    % list of quantifiers of type queue which have to
                        % to be eliminated
   qqe_bqu!-list!*    % list of quantifiers of basic type
   % qqe_id_counter!*   % counts the number of new id's already used
   );

imports qqeqemisc.red;


procedure qqe_satlengths(minlength, maxlength, lcm, lara);
   % Queue quantifier elimination saturation lengths. Returns a list of
   % integers representing lengths which have to be considered for the
   % equivalent quantifierfree formula. [[minlength]], [[maxlength]], are
   % positive integer, [[lcm]] is nil in case there are no pattern in
   % the formula, else a positive integer, [[lara]] is a positive
   % integer denoting left area + right area.
   begin scalar list, sll;
      % if there are pattern in formula then add the corresponding
      % satlengths (lowest common multiplier of pat lengths!)
      if lcm then
         for j:=0:(lcm-1) do
            sll := append(sll, {j})
      else sll := {0};

      for j:=minlength:(max(lara,minlength)) do 
      <<
         for each x in sll do
            if null maxlength or maxlength >= j+x then
               list := lto_insertq(j + x,list);
      >>;
      
      if null lcm and qqe_atf!-qneq!-int!* then
         list := lto_insertq(lara +1,list);
      
      return qqe_quicksort list;
                        
   end;

% ------------------ Quantifierelimination ------------------------------

procedure qqe_qe(u);
   % Queue quantifier elimination entry function. [u] is a formula 
   % for which a existential quantifier binding [qvar] has to be
   % eliminated. The function initiates a scan of [u] to decide,
   % what further steps have to be done.
   begin scalar f;
   
      f := rl_pnf(u);
      f := cadr qqe_get!-quantifier!-sequenz(f);
      
      f := qqe_la2lth f;
      qqe_elimb!* := t;
      if null qqe_qqu!-list!* then <<
         if qqe_elimb!* then <<
            % return qqe_qe!-basic u
            f := qqe_simpl!-dnf rl_dnf qqe_qe!-basic 
               qqe_iterate!-quantifier(qqe_bqu!-list!*,f);
            qqe_qeexit();
            return f;
         >>
         else << qqe_qeexit(); return u;>>;
      >>;
      
      for each q in qqe_qqu!-list!* do
      <<
         if not atom f then <<
            if car q eq 'ex then f := cadr qqe_get!-quantifier!-sequenz f 
            else <<
               f := rl_dnf cadr qqe_get!-quantifier!-sequenz {'not, f};
               f := qqe_make!-harmless f;
               %pause;
            >>;
            
            f := qqe_la2lth f;
            
            f := rl_dnf f;
            
            if car q eq 'ex then f := rl_pnf qqe_qe!-dnf(f,cadr q) 
            else f := rl_pnf {'not,qqe_qe!-dnf(f,cadr q)};
      
         >>;
      >>;
      
      f := rl_pnf rl_simpl(f,nil,-1);
      if not atom f then <<
         << if x then f := cadr x >>
            where x=qqe_get!-quantifier!-sequenz f;
         f := qqe_simpl!-dnf rl_dnf f;
         f := qqe_iterate!-quantifier(qqe_bqu!-list!*,f);
      >>;
      qqe_qeexit();
      return if qqe_elimb!* then qqe_qe!-basic f else f;
            
   end;

procedure qqe_qeexit();
   % QQE exit. Exit function. Free memory.
   begin
      qqe_resf!* := nil;
      qqe_qvarf!* := nil;    
      qqe_atf!-qequal!-ext!-c!* := nil;
      qqe_atf!-qequal!-ext!-p!* := nil;
      qqe_atf!-equal!-ext!* := nil;
      qqe_atf!-equal!-int!* := nil;
      qqe_atf!-misc!-basic!* := nil;
      qqe_atf!-qequal!-int!* := nil;  
      qqe_la!* := nil;    
      qqe_ra!* := nil;
      qqe_pat!-lengths!* := nil;
      qqe_sf!* := nil;       
      qqe_atf!-qneq!-int!* := nil;
      qqe_atf!-qneq!-ext!* := nil;
      qqe_atf!-qneq!-ext!-qepsilon!* := nil;
      qqe_atf!-neq!* := nil;  
      qqe_var!* := nil;   
      qqe_qqu!-list!* := nil;
      qqe_bqu!-list!* := nil;
   end;

procedure qqe_qe!-clause!-init(u);
   % initialize fluids
   begin
      qqe_resf!* := nil; 
      qqe_qvarf!* := nil;
      qqe_atf!-qequal!-ext!-c!* := nil;
      qqe_atf!-qequal!-ext!-p!* := nil;
      qqe_atf!-equal!-ext!* := nil;
      qqe_atf!-equal!-int!* := nil; 
      qqe_atf!-misc!-basic!* := nil; 
      qqe_atf!-qequal!-int!* := nil; 
      qqe_la!* := nil;
      qqe_ra!* := nil;
      qqe_pat!-lengths!* := nil; 
      qqe_sf!* := nil;
      qqe_atf!-qneq!-int!* := nil;
      qqe_atf!-qneq!-ext!* := nil;
      qqe_atf!-qneq!-ext!-qepsilon!* := nil;
      qqe_atf!-neq!* := nil;
      %% qqe_atf!-neq!-int!-s!* := nil;
      qqe_var!* := nil;
      % qqe_qqu!-list!* := nil;
      % qqe_bqu!-list!* := nil;

      % return  qqe_length!-graph!-clause u;
      return qqe_clause!-update!-lengths(u,t);
   end;

procedure qqe_qe!-dnf(u,q);
   % Queue quantifier elimination for disjunctive normal form.
   % [u] is dnf. Quantifier of variable [q] is has to be eliminated. 
   begin scalar f, temp;
      if u memq '(true false) then return u
      else if car u eq 'or then
      <<
         f := {'or};
         if cddr u then 
         <<
            for each x in cdr u do 
            <<
               temp := qqe_qe!-clause(x,q);
               f := append(f, {temp});  
            >>;
         >>
         else 
            f := qqe_qe!-clause(cadr u,q);
      >>
      else f := qqe_qe!-clause(u,q);
      
      return f;
   end;

procedure qqe_qe!-clause(u,q);
   % Queue quantifier elimination for clause of dnf.  [u] is a
   % conjunctive clause. Quantifier of variable [q] is has to be
   % eliminated.
   begin scalar f, list; 
      list := qqe_qe!-clause!-init(u);
      if list eq 'false then u := 'false
      else if list then <<
         if null qqe_harmless!-formula!-test!-clause1(u, list) then <<
            qqe_length!-graph!-delete list;
            qqe_qeexit();
            rederr("input formula is not harmless");
         >>;
      >>;

      if not atom u then u := qqe_simpl!-clause(u);

      if idp u then <<
         if list neq 'false then qqe_length!-graph!-delete(list);
         return u;
      >>;

      f := u;

      % initialization of fluids
      qqe_var!* := q;
      qqe_sf!* := f;

      qqe_sort!-atf(qqe_sf!*, qqe_var!*);
      
      if null qqe_qvarf!* then <<
         qqe_length!-graph!-delete(list);
         return f;
      >>;

      % calculation of left and right area
      qqe_la!* := qqe_la();
      qqe_ra!* := qqe_ra();
  
      % decision how to proceed according to structure of input formula
      if qqe_atf!-qequal!-ext!-c!* or qqe_atf!-qequal!-ext!-p!* 
      then <<
	 f := qqe_qe!-dna();
	 if qqe_resf!* then
            f := append({'and,f},qqe_resf!*);
      >>
      else <<
         if qqe_atf!-qneq!-ext!* then f:= qqe_ndna!-qneq!-ext()
         else f := qqe_ndna(nil,nil ,nil, qqe_la!* + qqe_ra!*); 
         if qqe_resf!* then
            f := append({'and,f},qqe_resf!*);
      >>;
  
      f := rl_simpl(f,nil,-1);
     
      qqe_length!-graph!-delete(list);
      
      return f;      
   end;

procedure qqe_qe!-dna();
   % Queue quantifier elimination determined neutral area. Initiates
   % quantifier elimination for the case that the neutral area is
   % fully determined.
   if qqe_atf!-qequal!-ext!-c!* then qqe_qe!-dna!-fd()
   else qqe_qe!-dna!-nfd();
   
procedure qqe_qe!-dna!-fd();
   % Queue quantifier elimination determined neutral area with [qqe_sf!*]
   % is fully determined, e.g. a atomic formula of the form: q==p exists.
   qqe_simpl!-clause subst(qqe_arg2r car qqe_atf!-qequal!-ext!-c!*,
      qqe_var!*, qqe_sf!*);
  
procedure qqe_qe!-dna!-nfd();
   % Queue quantifier elimination determined neutral area with [qqe_sf!*]
   % is not fully determined with a formula of the form q == p.
   begin scalar l,r,j, phi, rho, phi_e, k, idlist, minlength, maxlength;
      % init of variables   
      minlength := get(qqe_var!*,'minlength);
      if null minlength then minlength := 0;
      maxlength := get(qqe_var!*,'maxlength);
      if qqe_debug!* then 
	 prin2t{"minlength=",minlength," maxlength=", maxlength};
      j := qqe_atf!-qequal!-ext!-min!-prefix();
      l := qqe_atf!-qequal!-ext!-p!-min!-lefts(minlength, cadr j);
      r := qqe_atf!-qequal!-ext!-p!-min!-rights(minlength,cadr j);
      k := car l + car r;
      if maxlength then k := min(maxlength, k);
      idlist := qqe_new!-ids!-x(k, qqe_sf!*);

      % subformula generation
      % - rho
      if minlength + 1 < k then
         rho := qqe_atf!-dna!-nfd!-rho(idlist, minlength, k)
       else rho := 'false; 
      % - phi
      phi := qqe_simpl!-clause subst(
         qqe_atf!-dna!-nfd!-psi!-subst(l,r,j, idlist), qqe_var!*, qqe_sf!*);
      % - phi_e
      if minlength = 0 then
         phi_e := qqe_simpl!-clause subst('qepsilon, qqe_var!*, qqe_sf!*)
      else phi_e := 'false; 
      if qqe_debug!* then <<prin2t{phi,rho,phi_e};pause;>>;

      return qqe_qe!-basic qqe_iterate!-quantifier!-ex(k, idlist, 
        qqe_la2lth {'or, rho, phi, phi_e});
   end;


procedure qqe_atf!-dna!-nfd!-rho(idlist, minlength, kup);
   begin scalar f, ff, idlistx;
      for j:=max(minlength,1):kup do 
      <<
         idlistx := qqe_list!-take!-n(idlist,kup,j);
         f := qqe_subst(j,idlistx);         
         ff := f . ff;
      >>;
      
      if null cdr ff then return car ff
      else return 'or . ff;
   end;

procedure qqe_atf!-dna!-nfd!-rho!-subst(list,k);
   % obsolete - but eventually needed later
   begin scalar x, f;
      x := list;
      f := 'qepsilon;

      for j:=1:k do
      <<
         f := {'radd, car x, f};
         x := cdr x;
      >>;
      return f;
   end;

procedure qqe_atf!-dna!-nfd!-psi!-subst(l,r,j, idlist);
   % QQE atomic formula determined neutral area not fully determined
   % psi substitution. [l], [r], [j] are natural
   % numbers. [idlist] is a list of identifiers.
   begin scalar x, f;
      
      x := idlist;
      f := qqe_arg2r cadr j;

      if cadr l neq cadr j then
      <<
         for jj:=0:
            (qqe_prefix!-lefts qqe_arg2l cadr j - 
               qqe_prefix!-lefts qqe_arg2l cadr l - 1)
               do f := {'ladd, {'lhead, 
                  qqe_iterate!-rtail(jj, qqe_arg2r cadr l)}, f};
      >>;

      if car l neq 0 then
      <<
         for j:=1:car l do
         <<
            f := {'ladd, car x, f};
            x := cdr x;
         >>;
      >>;
      
      if cadr r neq cadr j then
      <<
         for jj:=0:
            (qqe_prefix!-rights qqe_arg2l cadr j - 
               qqe_prefix!-rights qqe_arg2l cadr r - 1)
                  do f:= {'radd,{'rhead, 
                     qqe_iterate!-ltail(jj, qqe_arg2r cadr r)}, f};
      >>;
      
      if car r neq 0 then
      <<
         for jj:=1:car r do
         <<
            f := {'radd, car x, f};
            x := cdr x;
         >>;
      >>;
      return f;
   end;

procedure qqe_ndna(minlength, maxlength,lcm, lara);
   % Queue quantifier elimination not determined neutral area.
   % [minlength], [maxlength], [lcm] are natural numbers, or nil.
   begin scalar satlengths,f, new_ids, new_idsx;
      
      if null minlength then minlength := get(qqe_var!*,'minlength);
      if null maxlength then maxlength := get(qqe_var!*,'maxlength);
      if null minlength then minlength := 0;

      if null qqe_pat!-lengths!* and qqe_atf!-qequal!-int!* then
      <<
         qqe_pat!-lengths!* := qqe_pat!-lengths(lara);
         if null lcm then
            lcm := qqe_lcm!-list qqe_pat!-lengths!*;
      >>;

      satlengths := qqe_satlengths(minlength, maxlength, lcm, lara);

      if qqe_debug!* then 
         prin2t{"satlengths=",satlengths, "for ", qqe_var!*};

      new_ids := qqe_new!-ids!-x(car satlengths, qqe_sf!*);
      
      f := nil;
      for each x in satlengths do
      << %!!!
         new_idsx := qqe_list!-take!-n(new_ids,car satlengths,x);
         f := qqe_qe!-basic(qqe_iterate!-quantifier!-ex(x,new_idsx,
            qqe_subst(x, new_idsx))) . f;
      >>;
      if cdr satlengths then f := 'or . f else f := car f;
      return f;
   end;

procedure qqe_ndna!-qneq!-ext!-phi2!-true();
   if qqe_atf!-qequal!-ext!-c!* or qqe_atf!-qequal!-ext!-p!* or
      qqe_atf!-equal!-ext!* or qqe_atf!-equal!-int!* or
      qqe_atf!-misc!-basic!* or qqe_atf!-qequal!-int!* or
      qqe_atf!-qneq!-int!* or qqe_atf!-neq!* 
   then nil
   else 'true;
  
procedure qqe_ndna!-qneq!-ext();
   % QQE not determined neutral area for the case that
   % [qqe_atf!-qneq!-ext!*] is not nil.
   begin scalar phi1, phi2, lcm, lara;
      
      lara := qqe_la!* + qqe_ra!*;
      if qqe_atf!-qequal!-int!* then
      <<
         qqe_pat!-lengths!* := qqe_pat!-lengths(lara);
         lcm := qqe_lcm!-list qqe_pat!-lengths!*;
      >>
      else lcm := 1;
      
      phi1 := rl_simpl(qqe_ndna(nil,nil, lcm, lara),nil,-1);
      if qqe_debug!* then pause;
      phi2 := qqe_ndna!-qneq!-ext!-phi2!-true(); 
   
      qqe_atf!-qneq!-ext!* := nil;
      qqe_atf!-qneq!-ext!-qepsilon!* := nil;
      if null phi2 then phi2 := rl_simpl(qqe_ndna(lara + lcm, 
         lara + 2 * lcm - 1, lcm, lara + lcm),nil,-1);
      if qqe_debug!* then pause;
      return {'or, phi1, phi2};
   end;
      
endmodule;

end;
