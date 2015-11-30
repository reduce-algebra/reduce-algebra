module ocread;

% Author: Rainer Schöpf 

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


fluid '(!*oc!-dynamic!-variables!*
        !*oc!-control!-variables!*
        !*oc!-time!-variable!*
        !*oc!-abbreviations!*
        !*oc!-boundaries!*
        !*oc!-boundary!-conditions!*
        !*oc!-dgls!*
        !*oc!-constants!*
        !*oc!-parameters!*
        !*oc!-functional!*
        !*oc!-name!*
        !*oc!-title!*
        !*oc!-is!-free!*
        !*oc!-relations!*
        !*oc!-tempvar!-prefix!*
        !*oc!-target!-lang!*
       );

symbolic procedure rhs!-free u;
  if length u neq 1 then rederr "invalid call to SET_RIGHT_BD_FREE"
   else !*oc!-is!-free!* := (reval car u neq 0);

put ('set_right_bd_free, 'psopfn, 'rhs!-free);

symbolic procedure def!-dgl u;
  if length u neq 2
    then rederr "invalid call to DEFINE_DIFFERENTIAL_EQUATION"
   else begin scalar var, dgl;
        var := !*a2k car u;
        dgl := reval cadr u;
        if not (var member !*oc!-dynamic!-variables!*)
          then rederr {var, "not defined as dynamic variable"};
        if assoc (var, !*oc!-dgls!*)
          then rederr {"Differential equation for dynamic variable",
                       var,
                       "already defined"};
        !*oc!-dgls!* := (var . dgl) . !*oc!-dgls!*;
   end;

put ('define_differential_equation, 'psopfn, 'def!-dgl);

symbolic procedure def!-fctl u;
  if length u neq 1 then rederr "invalid call to DEFINE_FUNCTIONAL"
   else if not null !*oc!-functional!*
    then rederr "Functional already defined"
   else !*oc!-functional!* := reval car u;

put ('define_functional, 'psopfn, 'def!-fctl);

symbolic procedure def!-bc u;
  if length u neq 1 then rederr "invalid call to DEFINE_BC"
   else 'list . (!*oc!-boundary!-conditions!* :=
            (reval car u) . !*oc!-boundary!-conditions!*);

put ('define_bc, 'psopfn, 'def!-bc);

symbolic procedure def!-bnds u;
  if length u neq 2 then rederr "invalid call to DEFINE_BOUNDS"
   else if not null !*oc!-boundaries!*
    then rederr "Boundaries already defined"
   else 'list . (!*oc!-boundaries!* := revlis u);

put ('define_boundaries, 'psopfn, 'def!-bnds);

symbolic procedure def!-dvars u;
  if length u neq 1 or not eqcar (u := car u, 'list)
    then rederr "invalid call to DEFINE_DYNAMIC_VARIABLES"
   else if not null !*oc!-dynamic!-variables!*
    then rederr "dynamic variables already defined"
   else << for each el in cdr u do
             if not (el = reval el) then typerr (el, "dynamic variable")
              else <<
                !*oc!-dynamic!-variables!* :=
                    el . !*oc!-dynamic!-variables!*;
                mkop el>>;
           'list . !*oc!-dynamic!-variables!* >>;

put ('define_dynamic_variables, 'psopfn, 'def!-dvars);

symbolic procedure def!-cvars u;
  if length u neq 1 or not eqcar (u := car u, 'list)
    then rederr "invalid call to DEFINE_CONTROL_VARIABLES"
   else if not null !*oc!-control!-variables!*
    then rederr "control variables already defined"
   else << for each el in cdr u do
             if not (el = reval el) then typerr (el, "control variable")
              else !*oc!-control!-variables!* :=
                      el . !*oc!-control!-variables!*;
           'list . !*oc!-control!-variables!* >>;

put ('define_control_variables, 'psopfn, 'def!-cvars);

symbolic procedure def!-tvar u;
  if length u neq 1 then rederr "invalid call to DEFINE_TIME_VARIABLE"
   else if not null !*oc!-time!-variable!*
    then rederr "Time variable already defined"
   else !*oc!-time!-variable!* := !*a2k car u;

put ('define_time_variable, 'psopfn, 'def!-tvar);


symbolic procedure def!-cnst u;
  if length u neq 2 then rederr "invalid call to DEFINE_CONSTANT"
   else begin scalar cs, val;
     cs := !*a2k car u;
     if not (cs = car u) then typerr (car u, "defined constant");
     val := reval cadr u;
     if not idp cs then typerr (cs, "defined constant")
      else if not evalnumberp val 
       then typerr (cadr u, "constant value")
      else if assoc (cs, !*oc!-constants!*) 
       then rederr list ("constant", cs, "already defined")
      else !*oc!-constants!* := (cs . val) . !*oc!-constants!*;
   end;

put ('define_constant, 'psopfn, 'def!-cnst);

symbolic procedure def!-param u;
  if null u or length u > 2
    then rederr "invalid call to DEFINE_PARAMETER"
   else begin scalar cs, val;
     cs := !*a2k car u;
     if not (cs = car u) then typerr (car u, "parameter");
     val := if null cdr u then nil else reval cadr u;
     if not idp cs then typerr (cs, "parameter")
      else if assoc (cs, !*oc!-parameters!*) 
       then rederr list ("parameter", cs, "already defined")
      else !*oc!-parameters!* := (cs . val) . !*oc!-parameters!*;
   end;

put ('define_parameter, 'psopfn, 'def!-param);


symbolic procedure set_name u;
  !*oc!-name!* := u;

symbolic procedure set_title u;
  if not eqcar (u, 'list) then rederr "invalid argument to SET_TITLE"
   else << !*oc!-title!* := cdr u; u>>;

flag ('(set_name set_title), 'opfn);


symbolic procedure def!-tmpvar u;
  if length u neq 1 then rederr "invalid call to SET_TEMPVAR_PREFIX"
   else !*oc!-tempvar!-prefix!* := !*a2k car u;

put ('set_tempvar_prefix, 'psopfn, 'def!-tmpvar);


symbolic procedure def!-targetlang u;
  if length u neq 1 then rederr "invalid call to SET_TARGET_LANGUAGE"
   else if not (car u memq '(c fortran ratfor pascal))
    then rederr list("unknown language", car u)
   else !*oc!-target!-lang!* := car u;

put ('set_target_language, 'psopfn, 'def!-targetlang);

symbolic procedure set!-vname u;
  if length u neq 2 or not idp car u or not idp cadr u
    then rederr "invalid call to SET_VARIABLE_NAME"
   else put (car u, 'oc!-external!-varname, cadr u);

put ('set_variable_name, 'psopfn, 'set!-vname);

symbolic procedure set!-pname u;
  if length u neq 2 or not idp car u or not idp cadr u
    then rederr "invalid call to SET_PROCEDURE_NAME"
   else put (car u, 'oc!-external!-procname, cadr u);

put ('set_procedure_name, 'psopfn, 'set!-pname);

symbolic procedure form!-abbrev(u,vars,mode);
   <<if atom cdr u or cddr u
       then rederr "Invalid arguments to define_abbreviation";
     u := cadr u;
     if eqcar(u,'equal) or eqcar(u,'setq)
       then u := 'replaceby . cdr u;
     {'list, ''define_abbreviation, form1(u,vars,mode)}>>;

put('define_abbreviation,'formfn,'form!-abbrev);

symbolic procedure def!-abbrev u;
   <<u := reval car u;
     !*oc!-abbreviations!* := aconc!*(!*oc!-abbreviations!*,u);
     u>>;

put('define_abbreviation,'psopfn,'def!-abbrev);

endmodule;

end;
