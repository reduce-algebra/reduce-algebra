% ----------------------------------------------------------------------
% $Id: rlcont.red,v 1.5 1999/03/23 09:23:56 dolzmann Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: rlcont.red,v $
% Revision 1.5  1999/03/23 09:23:56  dolzmann
% Changed copyright information.
%
% Revision 1.4  1999/03/22 12:41:42  dolzmann
% Reimplemented procedure rl_set for calling the exit functions of the
% context before calling the enter function of the new context. The old
% version could not handle the calling sequence rlset(dvfsf,5);
% rlset(dvfsf) correctly.
%
% Revision 1.3  1996/10/07 12:03:55  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.2  1996/09/05 11:16:59  dolzmann
% Added procedures rl_serviadd and rl_bbiadd.
%
% Revision 1.1  1996/03/22 12:18:29  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(rl_cont_rcsid!* rl_cont_copyright!*);
   rl_cont_rcsid!* :=
      "$Id: rlcont.red,v 1.5 1999/03/23 09:23:56 dolzmann Exp $";
   rl_cont_copyright!* := "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module rlcont;
% Reduce logic component context selection. Submodule of [redlog].

put('rlset,'psopfn,'rl_set!$);

procedure rl_set!$(argl);
   begin scalar w;
      if argl then <<
      	 w := reval car argl;
      	 if eqcar(w,'list) then <<
	    if cdr argl then rederr "too many arguments";
	    argl := cdr w
      	 >> else
	    argl := w . for each x in cdr argl collect reval x
      >>;
      return 'list . rl_set argl
   end;

procedure rl_set(argl);
   begin scalar cntxt,w;
      cntxt := if rl_cid!* then rl_cid!* . rl_argl!* else nil;
      if null argl then return cntxt;
      if rl_cid!* then rl_exit();
      w := rl_enter(argl);
      if w then <<
	 if cntxt then rl_enter(cntxt);
	 rederr w
      >>;
      return cntxt;
   end;

procedure rl_exit();
   begin scalar w;
      w := for each pair in get(rl_cid!*,'rl_cswitches) collect
	 car pair . rl_onp car pair;
      put(rl_cid!*,'rl_cswitches,w);
      for each pair in rl_ocswitches!* do
	 rl_vonoff(car pair,cdr pair);
      if (w := get(rl_cid!*,'rl_exit)) then
	 apply(w,nil);
   end;

procedure rl_enter(argl);
   begin scalar w,enter,cid;
      cid := car argl;
      argl := cdr argl;
      w := errorset({'load!-package,mkquote(cid)},nil,!*backtrace)
	 where !*msg=nil;
      if errorp w then
	 return {"switching to context",cid,"failed"};
      if not flagp(cid,'rl_package) then
	 return {cid,"is not an rl package"};
      enter := get(cid,'rl_enter);
      if null enter and argl then <<
	 lprim {"extra",ioto_cplu("argument",cddr argl),"ignored"};
	 argl := nil;
      >>;
      if enter then <<
      	 w := apply(enter,{argl});
      	 if not car w then
	    return cdr w
      	 else
	    argl := cdr w
      >>;
      rl_cid!* := cid;
      rl_argl!* := argl;
      rl_ocswitches!* := nil;
      for each pair in get(rl_cid!*,'rl_cswitches) do <<
	 rl_ocswitches!* := (car pair . rl_onp car pair) . rl_ocswitches!*;
	 rl_vonoff(car pair,cdr pair)
      >>;
      rl_ocswitches!* := reversip rl_ocswitches!*;
      rl_updcache();
      rmsubs();
      return nil
   end;

procedure rl_onp(s);
   eval intern compress append(explode '!*,explode s);

procedure rl_vonoff(sw,v);
   % Verbose [onoff]. [sw] is a switch; [v] is Bool.
   if v neq rl_onp sw then <<
      lprim {"turned",if rl_onp sw then "off" else "on","switch",sw};
      onoff(sw,v)
   >>;

procedure rl_updcache();
   % Update cache.
   <<
      for each bbv in rl_bbl!* do
	 set(bbv,nil);
      for each x in get(rl_cid!*,'rl_params) do
      	 set(car x,cdr x);
      for each sv in rl_servl!* do
	 set(sv,nil);
      for each x in get(rl_cid!*,'rl_services) do
      	 set(car x,cdr x)
   >>;

procedure rl_serviadd(tag,name,value);
   rl_sbiadd(tag,'rl_services,name,value);

procedure rl_bbiadd(tag,name,value);
   rl_sbiadd(tag,'rl_params,name,value);

procedure rl_sbiadd(tag,prp,name,value);
   begin scalar w,al,old;
      if not flagp(tag,'rl_package) then
	 rederr {tag,"is not a context identifier"};
      al := get(tag,prp);
      w := atsoc(name,al);
      if null w then <<
	 al := (name . value) . al;
      	 put(tag,prp,al);
	 return nil
      >>;
      old := cdr w;
      cdr w := value;
      lprim {"Changed definition of",name};
      put(tag,prp,al);
      return old
   end;

(if w then
   rl_deflang!* := {intern compress reversip cdr reversip cdr explode w})
      where w=getenv("RLDEFLANG");
if rl_deflang!* then rl_set rl_deflang!*;

endmodule;  % [rlcont]

end;  % of file
