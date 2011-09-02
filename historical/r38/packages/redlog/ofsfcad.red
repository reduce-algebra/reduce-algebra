% ----------------------------------------------------------------------
% $Id: ofsfcad.red,v 1.32 2004/05/03 09:02:32 dolzmann Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2000 Andreas Dolzmann, Andreas Seidl, and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: ofsfcad.red,v $
% Revision 1.32  2004/05/03 09:02:32  dolzmann
% Added procedure ofsf_cadpnum for computing the number of cells of a
% partial cad.
%
% Revision 1.31  2003/12/08 16:09:00  dolzmann
% Changed begin scalar; to begin. (Code generation for begin scalar;
% binds nil).
%
% Revision 1.30  2003/10/12 14:38:02  sturm
% Fxed fluid on atom.
%
% Revision 1.29  2003/09/25 07:31:38  seidl
% Some changes.
%
% Revision 1.28  2003/08/28 13:51:03  seidl
% Worked on projection orders.
%
% Revision 1.27  2003/02/02 22:25:22  seidl
% Theory is now being simplified again.
%
% Revision 1.26  2003/02/02 22:13:49  seidl
% Global Variable ofsf_cadtheo!* eliminated. Verbose output changed.
%
% Revision 1.25  2003/01/31 15:31:54  sturm
% Worked on verbosity output of QE routines.
%
% Revision 1.24  2003/01/30 12:35:49  sturm
% Commented procedure ofsf_evalqff!-fast and children.
%
% Revision 1.23  2003/01/29 17:35:29  seidl
% Even second-level verbose output now depends on switch rlverbose.
%
% Revision 1.22  2003/01/29 10:43:12  sturm
% Moved fluid declaration to ofsf.red, where all such declarations belong.
% Moved list2set and list2vector to lto.red.
%
% Revision 1.21  2003/01/29 08:50:08  seidl
% Added changes suggested by Tony Hearn. Changed Copyright note.
%
% Revision 1.20  2003/01/25 11:49:38  sturm
% Changed return value and interface for rlcadporder/ofsf_cadporder and
% rlgcadporder/ofsf_gcadporder. They return a list of variables now.
% s2a conversion is done in the scheduler now. Adapted rlcad/ofsf_cad and
% rlgcad/ofsf_gcad accordingly.
%
% Revision 1.19  2003/01/11 20:01:09  seidl
% McCallum projection used for 3 variable level, if temporary switch rlcadmc3
% is turned on (default). Improved solution formula construction, if first
% attempt fails, then second try with all possible projection factors.
%
% Revision 1.18  2003/01/11 17:57:58  sturm
% Added AM services rlcadporder, rlgcadporder for ofsf.
%
% Revision 1.17  2003/01/10 15:16:45  seidl
% Temporary switch definition.
%
% Revision 1.16  2003/01/06 18:23:15  seidl
% Verbose output changed.
%
% Revision 1.15  2003/01/04 09:07:49  seidl
% Changes to CADDATA.
%
% Revision 1.14  2002/06/05 17:50:48  seidla
% rlgcad makes generic projection. Temporary switch rlqegen1 enables 1-generic
% cad, but beware: only turn on this switch when rlgcad is used. Bug fixed in
% deciding compatibility for signatures. caddata_print1 gives less output.
%
% Revision 1.13  2002/05/30 22:24:34  seidla
% Generic modified to 1-generic cad.
%
% Revision 1.12  2002/05/29 17:56:48  seidla
% Fixed problem in solution formula construction.
%
% Revision 1.11  2002/05/29 14:06:29  sturm
% Added in ofsf_gcad() simplification of the final theory and corresponding
% simplification of the result.
%
% Revision 1.10  2002/05/29 13:28:28  seidla
% Assumptions are collected in ofsf_cadtheo!*. Verbose output for generic case
% and for the case rlcadfulldimonly is switched on.
%
% Revision 1.9  2002/05/29 12:16:13  seidla
% Throw away cells for generic CAD and print (!).
%
% Revision 1.8  2002/05/29 11:46:33  sturm
% Provided ofsf_gcad() and corresponding AM interface.
%
% Revision 1.7  2002/05/28 13:06:52  seidla
% New datatype caddata. PCAD 2nd inprovement.
%
% Revision 1.6  2002/03/12 18:07:57  seidla
% New data type CADDATA allows for ofsf_cad to be more modular.
%
% Revision 1.5  2002/02/19 13:34:00  seidla
% varl is sooner reversed to be x1,...,xr. Cad data as verbose output.
% Set of polynomials of which signatures are generated might be too
% large.
%
% Revision 1.4  2002/01/25 14:42:33  sturm
% Added switch rlcaddecdeg, off by default.
%
% Revision 1.3  2002/01/25 12:35:38  sturm
% Removed obsolete argument [n] from ofsfcad().
% Added degree decreaser ofsf_decdeg0() to ofsfcad().
%
% Revision 1.2  2002/01/18 15:33:02  seidla
% Renamed prefixes to ofsf, acell or atree, respectively. Removed some
% procedures or marked as unused.
%
% Revision 1.1  2002/01/16 13:03:48  seidla
% Imported CAD from rlprojects.
%
% Revision 1.43  2002/01/16 11:14:14  seidla
% Switches rlcadisoallroots and rlcadtrimtree added.
%
% Preparation of projection polynomials in acad_treeovercell moved to
% seperate function acad_tocprepare.
%
% reduce added after squarefree in treeovercell. additional information
% for verbose output of extension phase. verbose output for solution
% formula construction changed.
%
% New version of ofsfcad, features partial CAD.
%
% Revision 1.42  2001/12/11 17:38:31  seidla
% cad_switches written and declared as an algebraic operator. fixed
% reorder bug in projection phase. removed dead code (alternative base
% phase).
%
% Revision 1.41  2001/12/01 20:40:27  seidla
% ofsf_cad revamped: parameters given to ofsf_cadproj have changed, now
% augmented projection can be done when needed. many variable names
% changed and some code rearranged. there is a problem in the projection
% phase (v1.7), hence the program works not correct on many examples.
% this is not a bug but due to contradictionary information in the
% literature.
%
% Revision 1.40  2001/11/23 10:55:54  seidla
% Simple solution formula construction implemented (Hong92): Projection
% polynomials are used to construct the solution formula. This won't
% work in all cases, but it will rarely fail. Code for projection phase
% moved to file ofsfcadproj.red.
%
% Revision 1.39  2001/08/08 11:14:53  seidla
% ofsf_cad now returns in any case an equivalent formula, in case of a
% decision problem this formula is true or false.  Removed parameter qff
% from acad_base and parameters k,r from acad_cadext.  Removed garbage
% code from acad_base, acad_cadext, acad_cadextop and others.  Changed
% comments in acad_subsp and acad_subsp. Moved acad_subspv to module
% asolution. Changed comment of acad_constrsol.  Added comments to
% contructors and access functions of ACELL. Renamed acell_puttp to
% acell_putsp. +++ instead of *** or $$$. Testfile runs with anuex 1.23.
%
% Revision 1.38  2001/08/07 19:31:41  sturm
% Minor changes, mainly in comments.
%
% Revision 1.37  2001/08/07 12:55:51  seidla
% Code structure altered. New module ACELL. Prefix of
% anu_mk0frombasecellxi, a_constrsol, a_eval*, a_subsignat, a_cadbase
% and a_mkvarl changed to acad. a_cadexp renamed to acad_ext, a_cadextop
% renamed to acad_expop. aex_subspffs renamed to acad_subsp,
% aex_subspffsv renamed to acad_subspv. aex_mapmkaex0d and
% anu_findrootsoflist moved to package ANUEX. anu_evalsignf from package
% ANUEX renamed to acad_evalsignf and moved to here.
%
% Revision 1.36  2001/06/19 14:22:01  seidla
% Verbose output is more customized now by the switches rlvervose,
% rlcadverbose and anuexverbose. For minimal output, just enable switch
% rlverbose. If rlcadverbose is switched on in addition, more explicit
% output is given during expansion. This output is especially needed
% when anuexverbose is switched on. Furthermore, the switches
% rlcadprojonly, rlcadbaseonly, rlcadexpansiononly allow for termination
% after the projection-, base- or expansion-phase, respectively, and the
% order will be restored if changed.
%
% Revision 1.35  2001/06/15 12:45:35  seidla
% Truth values will be calculated for decompositions D_k,...,D_r. Decission
% problem can be solved now. Omission in acell_mkcellsofcylinder filled,
% hence hack in anu_evalsignf is obsolete now.
%
% Revision 1.34  2001/06/15 11:19:22  sturm
% Added fast version of a_evalqff. Currently toggled by switch rlcadfasteval,
% which is on by default. Moved a_evalqff code to module asolution.
% Compute in a_constrsol a negation normal form as expected by a_evalqff!-fast.
%
% Revision 1.33  2001/06/14 21:13:33  sturm
% Added procedure a_evalqff.
% Started solution formula construction. Can evaluate the truth values for
% the cells of the full-dimensional decomposition currently. This is
% returned to AM.
% Everything is terribly dirty.
%
% Revision 1.32  2001/06/14 17:21:30  seidla
% Small changes wrt verbose output.
%
% Revision 1.31  2001/06/13 11:52:19  seidla
% Expansion phase written. This includes: new datatypes ACELL, IDX, SP,
% DESC; new functions acell_*, acell_mkcellsofcylinder, a_cadexp,
% a_cadexpop, aex_subspffs, aex_mapmkaex0d, and modifications in
% ofsf_cad, a_cadbase. In acell_mkcellsofcylinder there is still a spot
% to fix. New switch rlcadbaseonly. On explicit termination, old order
% will be restored.
%
% Revision 1.30  2001/05/30 15:04:39  seidla
% Small changes, works with revision 1.17 of anuex.
%
% Revision 1.29  2001/05/24 15:25:24  sturm
% Ongoing implementation of base phase based on anuex.
%
% Revision 1.28  2001/03/20 19:55:04  sturm
% Introduced the data structure <Sturm TESTPT>.
%
% Revision 1.27  2001/03/20 18:33:35  sturm
% Added verbosity output.
% Slightly improved sfto_evalsp :)
%
% Revision 1.26  2001/03/20 15:59:05  sturm
% Restructured ofsf_cadbase. Use the correct variable in ofsf_sq2tp now.
%
% Revision 1.25  2001/03/20 15:22:26  sturm
% ofsf_cadbase returns a cell decomposition (CDEC) instead of a list of
% test points (TESTPT) now. Test example is sub(x=0,cox14v) in file clo.
%
% Revision 1.24  2001/03/16 15:15:58  sturm
% Readded procedures that had been accidently removed.
%
% Revision 1.23  2001/03/13 17:47:41  sturm
% Commented.
% Removed garbage code.
%
% Revision 1.22  2000/11/21 17:13:23  sturm
% Did a lot of isolation for base phase.
%
% Revision 1.21  2000/10/04 11:28:13  gilch
% Improved ofsf_newpolynomials, ofsf_verttangents, ofsf_crossings.
% Fixed a bug in sfto_isolater.
%
% Revision 1.20  2000/09/28 15:46:19  dolzmann
% Added datastructure CAD and access functions.
%
% Revision 1.19  2000/09/28 15:37:42  dolzmann
% Renamed sfto_isolater to sfto_isolater0. Added procedure sfto_isolater
% calling sfto_isolater0 with default arguments.
%
% Revision 1.18  2000/09/28 15:33:45  dolzmann
% ofsf_crossings computes only half of all pairs.
%
% Revision 1.17  2000/09/28 15:23:04  dolzmann
% Split into submodules.
% Added interface sfto_isolater to isolater.
%
% Revision 1.16  2000/09/28 11:32:05  gilch
% Fixed a bug in ofsf_cadproj.
% Improved ofsf_getcfs, ofsf_crossings.
% Updated all comments.
%
% Revision 1.15  2000/09/27 12:58:19  sturm
% Renamed switch rlfctrfallp to rlcadfac (on by default).
% Included patched Bareiss determinant code.
% Fixed bug in factorization.
% Improved ofsf_clean: make primitive now.
% Added optional parameter to rlcad: maximum number of projection steps.
%
% Revision 1.14  2000/09/27 11:57:55  gilch
% Added switch rlfctrfallp. Added Factorizing in ofsf_cadproj by subroutine
% ofsf_cadproj1. Implemented ofsf_clean, ofsf_factors, ofsf_factors1,
% ofsf_factors2. Renamed ofsf_newpolynoms to ofsf_newpolynomials.
% Added comments.
%
% Revision 1.13  2000/09/26 12:34:28  sturm
% Fixed a bug in the interface ofsf_cad.
% Added verbosity output.
%
% Revision 1.12  2000/09/26 11:58:20  sturm
% Built interface.
% Adding all reducta now.
%
% Revision 1.11  2000/09/22 13:43:32  gilch
% Patch for ofsf_newpolynoms and ofsf_derivatives
%
% Revision 1.8  2000/09/21 12:44:50  gilch
% Changed all functions. Implemented new functions ofsf_cadproj,
% ofsf_reducta1, ofsf_pscmatrix1, ofsf_getcfs1, ofsf_getcfs2,
% ofsf_mkmatrix, ofsf_removerows, ofsf_removecolumns, ofsf_verttangents and
% ofsf_newpolynoms
%
% Revision 1.7  2000/09/20 12:25:07  gilch
% Implemented ofsf_det,ofsf_crossings
%
% Revision 1.4  2000/09/19 15:53:47  gilch
% Implementations for osfs_derivatives,ofsf_derivative,ofsf_getcfs,ofsf_reducta, ofsf_ldcfs, ofsf_pot and template for ofsf_pscmatrix,ofsf_crossings
%
% Revision 1.3  2000/09/18 13:30:45  sturm
% Added template for procedure ofsf_cadproj.
%
% Revision 1.2  2000/09/18 12:34:40  gilch
% Changed result of ofsf_cad to 'false.
%
% Revision 1.1  2000/09/18 12:19:01  sturm
% Initial check-in.
%
% ----------------------------------------------------------------------

lisp <<
   fluid '(ofsfcad_rcsid!* ofsfcad_copyright!*);
   ofsfcad_rcsid!* := "$Id: ofsfcad.red,v 1.32 2004/05/03 09:02:32 dolzmann Exp $";
   ofsfcad_copyright!* := "(c) 2000 by A. Dolzmann, A. Seidl, T. Sturm"
>>;

module ofsfcad;

switch rlqegen1,rlcadmcproj,rlpscsgen;
fluid '(rlcadguessnoc!*);

off1 'rlqegen1;
off1 'rlcadmcproj;
on1 'rlpscsgen;

procedure ofsf_cadverbosep();
   % CAD verbose predicate.
   !*rlverbose and !*rlcadverbose;

procedure ofsf_gcad(phi,mkvarlres);
   % Ordered field standard form generic cylindrical algebraic
   % decomposition. [f] is a formula. Returns a pair $(\Theta,\phi')$,
   % where $\Theta$ is a list of inequalities, and $\phi'$ is a
   % quantifier-free formula. We have
   % $\bigwedge\Theta\longrightarrow([phi]\longleftrightarrow\phi')$.
   begin scalar !*rlqegen;
      !*rlqegen := t;
      return ofsf_cad(phi,mkvarlres);
   end;

fluid '(kord!*);

procedure ofsf_cad(phi,mkvarlres);
   % Ordered field standard form cylindrical algebraic decomposition.
   % [f] is a formula, [n] is a non-negative integer. If [f] is
   % closed (and rlcadanuex is switched on) a quantifier-free formula
   % equivalent to [f] is returned, otherwise [f] is returned in
   % prenex normal form.
   begin scalar cd;
	 %ophi,phiprime,tmp,varl,qal,k,r,oldorder,ff,ffr,dd,psi,w;
      % Preparation phase. Kernel order is changed.
      cd := ofsf_cadpreparation(phi,mkvarlres);
      if !*rlverbose then caddata_print1 cd;
      if !*rlcadpreponly then return ofsf_cadfinish cd;
      % Projection phase
      ofsf_cadprojection cd;
      if !*rlcadprojonly then <<
	 ioto_prin2t {"+ Theory: "};
	 for each x in caddata_theo cd do mathprint rl_prepfof x;
	 return ofsf_cadfinish cd
      >>;
      % Extension phase (build partial cad tree)
      ofsf_cadextension(cd);
      if !*rlcadextonly then return ofsf_cadfinish cd;
      % Solution formula construction
      ofsf_solutionformula cd;
      % Finish cad. Kernel order is restored.
      return ofsf_cadfinish cd;
   end;

procedure ofsf_cadpnum(phi,mkvarlres);
   % Ordered field standard form cylindrical algebraic decomposition.
   % [f] is a formula, [n] is a non-negative integer. If [f] is
   % closed (and rlcadanuex is switched on) a quantifier-free formula
   % equivalent to [f] is returned, otherwise [f] is returned in
   % prenex normal form.
   begin scalar cd,!*rlcadtrimtree,kord!*;
	 %ophi,phiprime,tmp,varl,qal,k,r,oldorder,ff,ffr,dd,psi,w;
      % Preparation phase. Kernel order is changed.
      cd := ofsf_cadpreparation(phi,mkvarlres);
      % Projection phase
      ofsf_cadprojection cd;
      % Extension phase (build partial cad tree)
      ofsf_cadextension(cd);
      return length atree_yield caddata_dd cd
   end;

procedure ofsf_cadproj(phi,mkvarlres);
   begin scalar cd,oldorder,phiprime,ophi,theo,ffl;
      % Preparation phase. Kernel order is changed.
      cd := ofsf_cadpreparation(phi,mkvarlres);
      if !*rlverbose then caddata_print1 cd;
      % Projection phase
      ofsf_cadprojection cd;
      % Finish
      for each x in caddata_theo cd do mathprint rl_prepfof x;
      oldorder := caddata_oldorder cd;
      phiprime := caddata_phiprime cd;
      ophi := caddata_ophi cd;
      if oldorder neq 'undefined then setkorder oldorder;
      if !*rlverbose and ofsf_cadverbosep() then
	 ioto_tprin2 {"+ Order restored."};
      theo := for each fo in caddata_theo cd collect cl_apply2ats(fo,
	    function(lambda(x); ofsf_0mk2(ofsf_op x,reorder ofsf_arg2l x)));
      % Fr,...,F1
      ffl := reversip for j := 1 : caddata_r cd collect
	 for each f in caddata_ffj(cd,j) collect reorder f;
      return theo . ffl
   end;
  
procedure ofsf_cadpreparation(phi,mkvarlres);
   % Cad preparation. [phi] is a ofsf formula; [mkvarlres] is a list
   % of variables encoding an addmitted projection order. Returns a
   % CADDATA.
   begin scalar w,ophi,tmp,varl,qal,r,k,oldorder,psi,ffr,ff;
      if !*rlverbose then ioto_tprin2t "+++ Preparation Phase";
      if !*rlcaddecdeg then <<
	 if !*rlverbose then ioto_prin2 "+ decrease degrees: ";
      	 w := ofsf_decdeg0 phi;
      	 phi := car w;
      	 if !*rlverbose then
	    ioto_prin2 for each x in cdr w join {"(",car x,"^",cdr x,")"};
      >>;
      ophi := phi := cl_pnf phi; % ophi with old term order
      tmp := ofsf_mkvarl phi;  % ((xr,...,x_1).((x_r.Q_r),...,(x_k+1.Q_k+1)))
      if mkvarlres then <<
	 varl := mkvarlres;
	 qal := for each x in cdr tmp collect << %%% dodgy, use assoc
	    w := car mkvarlres;
	    mkvarlres := cdr mkvarlres;
	    w . cdr x
	 >>
      >> else <<
      	 varl := car tmp; % (xr,...,x_1)
      	 qal := cdr tmp   % ((x_r.Q_r),...,(x_k+1.Q_k+1))
      >>;
      r := length varl;
      k := r - length qal;
      % reordering wrt. x_(c+1),xr,...,x_1
      oldorder := setkorder varl; %setkorder('xcplus1 . varl);
      varl := reverse varl; % (x1,...,xr) % reversip would affect kernel order
      qal := reversip qal; % ((x_k+1.Q_k+1),...,(x_r.Q_r))
      phi := cl_apply2ats(phi,
	 function(lambda(x); ofsf_0mk2(ofsf_op x,reorder ofsf_arg2l x)));
      psi := cl_matrix phi; % phi = Q_k+1 x_k+1 ... Q_r x_r psi
      ffr := for each f in cl_terml phi collect f;
      ff := mkvect(r);
      putv(ff,r,ffr);
      return caddata_mk(phi,k,r,varl,qal,psi,ff,'undefined,'undefined,
	 oldorder,ophi,'undefined,nil)	 
   end;

procedure ofsf_cadprojection(cd);
   begin scalar varl,k,r,ff;
      varl := caddata_varl cd;
      k := caddata_k cd;
      r := caddata_r cd;
      ff := caddata_ff cd; % list (nil,...,nil,Fr)
      %ffr := getv(ff,r);
      if !*rlverbose then ioto_tprin2t {"+++ Projection Phase"};     
      ofsf_cadprojection1(cd); % here F and J is computed
      ff := caddata_ffl cd; % list (F1,...,Fr)
      if !*rlcadprojonly and ofsf_cadverbosep() then for i := 1 : r do <<
	 ioto_tprin2t {"+ projection factors level ",r-i+1};
	 mathprint ('list . for each f in nth(ff,r-i+1) collect prepf f);
	 %for each f in nth(ff,r-i+1) do mathprint prepf f
      >>;	 
      if !*rlverbose  then <<
	 ioto_tprin2t {"+ (#F1,...,#Fr)=",
	    for each ffi in ff collect length ffi}; >>;
      if !*rlcadprojonly then <<
	 ioto_tprin2t "+ switch rlcadprojonly: stopped, order unchanged.";
	 %setkorder oldorder;
	 return ; % rl_mk!*fof ophi;
      >>;
      %caddata_putff(cd,list2vector (nil . ff));
      return nil;
   end;

procedure ofsf_cadextension(cd);
   begin scalar ff,varl,qal,psi,r,dd;
      ff := caddata_ff cd;
      varl := caddata_varl cd;
      qal := caddata_qal cd;
      psi := caddata_psi cd;
      r := caddata_r cd;
      if !*rlverbose then
	 ioto_tprin2t {"+++ Partial CAD (extension and truth values)"};
      %dd := ofsf_cadext(ff,varl); % D_r,...,D0
      %dd := ofsf_tree(cdr vector2list ff,varl,qal,cl_nnf psi);
      dd := ofsf_tree cd;
       if !*rlverbose then 
	 ioto_tprin2t {"+ (#D0,...,#Dr)=",
	    for i := 0 : r collect length atree_levellabels(dd,i)};
      if !*rlcadextonly then <<
	 %setkorder oldorder;
	 ioto_tprin2t "+ switch rlcadextonly: stopped, order restored.";
	 return dd; %rl_mk!*fof ophi;
      >>;
      caddata_putdd(cd,dd);
      return nil;
   end;

procedure ofsf_cadfinish(cd);
   % Finish. [cd] is CADDATA. Returns a foformula. Depending on
   % whether a phiprime was found, a q.f. fof or simply the input
   % formula is returned.
   begin scalar oldorder,phiprime,ophi,theo;
      if !*rlverbose then
	 ioto_tprin2t {"+++ Finish CAD"};
      oldorder := caddata_oldorder cd;
      phiprime := caddata_phiprime cd;
      ophi := caddata_ophi cd;
      %%% 2=rlcadgenlevel
      if !*rlqegen1 then
	 for j := 1 : min2(1,caddata_k cd) do 
            caddata_puttheo(cd,append(for each f in caddata_ffj(cd,j) collect
	       ofsf_0mk2('neq,f),caddata_theo cd));
      if oldorder neq 'undefined then setkorder oldorder;
      if !*rlverbose and ofsf_cadverbosep() then
	 ioto_tprin2 {"+ Order restored."};
      theo := for each fo in caddata_theo cd collect cl_apply2ats(fo,
	    function(lambda(x); ofsf_0mk2(ofsf_op x,reorder ofsf_arg2l x)));
      if phiprime neq 'undefined then phiprime := cl_apply2ats(phiprime,
	 function(lambda(x); ofsf_0mk2(ofsf_op x,reorder ofsf_arg2l x)));      
      if !*rlqegen then theo := ofsf_thsimpl theo;
      return (if phiprime neq 'undefined then
	 theo . cl_simpl(phiprime,theo,-1)
      else
	 theo . ophi)
   end;

procedure ofsf_cadswitches();
   % Switches. Prints the status of all switches relevant for cad.
   <<
      ioto_tprin2 ".:: list of switches ::.";
      ioto_tprin2 "------------------------";
      ioto_tprin2 "verbose switches:";
      ofsf_cadswitchprint(!*rlverbose); ioto_prin2 "rlverbose"; 
      ofsf_cadswitchprint(ofsf_cadverbosep()); ioto_prin2 "rlcadverbose"; 
      %ofsf_cadswitchprint(!*anuexverbose); ioto_prin2 "anuexverbose"; 
      ioto_tprin2 "general switches:";
      ofsf_cadswitchprint(!*rlcadpreponly); ioto_prin2 "rlcadpreponly"; 
      ofsf_cadswitchprint(!*rlcadprojonly); ioto_prin2 "rlcadprojonly"; 
      ofsf_cadswitchprint(!*rlcadbaseonly); ioto_prin2 "rlcadbaseonly"; 
      ofsf_cadswitchprint(!*rlcadextonly);  ioto_prin2 "rlcadextonly";
      ioto_tprin2 "switches for preparation phase:";
      ofsf_cadswitchprint(!*rlcaddecdeg);      ioto_prin2 "rlcaddecdeg"; 
      ioto_tprin2 "switches for projection phase:";
      ofsf_cadswitchprint(!*rlcadaproj);      ioto_prin2 "rlcadaproj"; 
      ofsf_cadswitchprint(!*rlcadaprojalways);ioto_prin2 "rlcadaprojalways";
      ofsf_cadswitchprint(!*rlcadhongproj);   ioto_prin2 "rlcadhongproj";
      ofsf_cadswitchprint(!*rlcadfac);  ioto_prin2 "rlcadfac";
      ioto_tprin2 "switches for extension phase";
      ofsf_cadswitchprint(!*rlcadpartial); ioto_prin2 "rlcadpartial"; 
      ofsf_cadswitchprint(!*rlcadisoallroots); ioto_prin2 "rlcadisoallroots"; 
      ofsf_cadswitchprint(!*rlcadtrimtree); ioto_prin2 "rlcadtrimtree";
      ofsf_cadswitchprint(!*rlcadfasteval); ioto_prin2 "rlcadfasteval"; 
      ofsf_cadswitchprint(!*rlcadfulldimonly); ioto_prin2 "rlcadfulldimonly"; 
      ofsf_cadswitchprint(!*rlcadte); ioto_prin2 "rlcadte"; 
      ofsf_cadswitchprint(!*rlcadpbfvs); ioto_prin2 "rlcadpbfvs"; 
      ioto_tprin2 "switches for solution formula construction phase";
      ofsf_cadswitchprint(!*rlcadrawformula); ioto_prin2 "rlcadrawformula"; 
      ofsf_cadswitchprint(!*rlcaddnfformula); ioto_prin2 "rlcaddnfformula"; 
      ioto_tprin2 "switches for algebraic numbers (do not change)";
   >>;

procedure ofsf_cadswitchprint(b);   
   % Switch print. [b] is a BOOL.
   if b then ioto_tprin2 " ON  -- " else ioto_tprin2 " OFF -- ";
   
% module acell;
% Andreas' cell. Constructors and access functions for data type ACELL
% plus the code for decomposing the cylinder over a given cell.

%DS
% <CAD> ::= (..., <CDEC>, ...)
% <CDEC> ::= (..., <ACELL>, ...)
% <ACELL> ::= (<IDX> . (<SP> . <TV> . <DESC> . nil)) (an alist)
% <IDX> ::= List of natural numbers
% <SP> ::= List of ANU's
% <DESC> ::= "quantifier-free formula"

procedure acell_mk(idx,tp,tv,desc);
   % Cell make. [idx] is an IDX, [tp] is a SP, [tv] is [true] or
   % [false], [desc] is a DESC. Returns an ACELL.
   idx . (tp . tv . desc . nil);

procedure acell_getidx(c);
   % Cell get index. [c] is an ACELL. Returns a IDX
   car c;

procedure acell_getsp(c);
   % Cell get sample point. [c] is an ACELL. Returns a SP.
   cadr c;

procedure acell_gettv(c);
   % Cell get truth value. [c] is an ACELL. Returns [true] or [false].
   caddr c;

procedure acell_getdesc(c);
   % Cell get index. [c] is an ACELL. Returns a quantifier-free formula.
   cadddr c;   

procedure acell_putsp(c,sp);
   % Cell put truth value. [c] is an ACELL, [sp] is a SP. Returns [c]
   % with the truth value changed.
   cadr c := sp;

procedure acell_puttv(c,tv);
   % Cell put truth value. [c] is an ACELL, [tv] is [true] or
   % [false]. Returns [c] with the truth value changed.
   caddr c := tv;

procedure acell_putdesc(c,desc);
   % Cell put description. [c] is an ACELL, [desc] is a signature or a
   % quantifier-free formula. Returns [c] with the description
   % changed.
   cadddr c := desc;

procedure acell_tvasstring(c);
   % truth value as string
   if acell_gettv c eq 'true then "T" else
      if acell_gettv c eq 'false then "F" else
	 "?";

% module cadtree;

%dd := ofsf_tree(cdr vector2list ff,varl,qal,cl_nnf psi);
%procedure ofsf_tree(ff,varl,qal,psi);

procedure ofsf_tree(cd);   
   ofsf_treeovercell(basecell,cdr vector2list caddata_ff cd,
      caddata_varl cd,caddata_qal cd,cl_nnf caddata_psi cd)
	 % this is the only cell of D0
	 where basecell=acell_mk(nil,nil,nil,'true);

procedure ofsf_treeovercell(basecell,ff,varl,qal,psi);
   % Cad tree over cell. basecell is a cell in D_j-1, ff is Fj,...,Fr,
   % varl is x1,...,x_r, qal is x_{k+1}.theta_{k+1},...,x_r,theta_r,
   % and psi the qf. part of the input formula. Returns a tree over
   % the basecell. Intuition: Finds for a cell C in D_j a partial cad
   % tree that has C as a root; if j>=k then C has a truth value.
   begin scalar r,k,j,ffj,xj,sp,cell,treel,thetaj,neutral,nrdata,ncbuffer,res,
	 tv;
      integer d,n;
      if ofsf_cadverbosep() then ioto_prin2 {"(",length acell_getsp basecell};
      %ioto_tprin2t {"tree over: ",basecell}; % verbose output, sometimes needed
      r := length varl; k := r-length qal; j := r-length ff+1;
      sp := acell_getsp basecell;
      if !*rlcaddebug and (length ff + length sp) neq r then
 	 prin2t "***** ofsf_treeovercell: argument invalid";
      % 1. BASE CASE: j=r, evaluation case. The base cell is a leaf.
      if j > r then <<
	 acell_puttv(basecell,ofsf_evalqff(psi,sp,varl));
	 if ofsf_cadverbosep() then ioto_prin2 ")";
      	 return atree_new basecell
      >>;
      % trial evaluation
      if !*rlcadte then <<
	 %ioto_tprin2t "----------";
	 %ioto_prin2t {"sp: ",sp};
	 %ioto_prin2t {"psi: ",psi};
      	 psi := cl_simpl(cl_apply2ats1(psi,
	    function(lambda x,sp; ofsf_0mk2(ofsf_op x,
	       ofsf_trialevalsgnf(ofsf_arg2l x,sp))),{sp}),nil,-1);
      	 if (psi eq 'true or psi eq 'false) then <<
	    acell_puttv(basecell,psi);
	    if ofsf_cadverbosep() then ioto_prin2 "TE)";
	    return atree_new basecell
      	 >>;
	 %ioto_prin2t "------noTE";	 
      >>;
      % Prepare Polynomials
      xj := nth(varl,j);
      ffj := ofsf_tocprepare(ff,xj,sp,varl);
      nrdata := rip_init(ffj,xj); % initialize next root data
      rip_putpscl(nrdata,for each psc in rip_pscl nrdata join
	 if (d := aex_stchsgnch(cdr psc,xj,'minfty) -
	    aex_stchsgnch(cdr psc,xj,'infty)) neq 0 then <<n := n+d;{psc}>>);
      if ofsf_cadverbosep() then ioto_prin2 {":",2*n+1};
      % mildly generic CAD: add assumptions
      %if !*rlqegen1 and j<=min2(1,k) then
%	 ofsf_cadtheo!* := append(for each f in ffj collect
%	    ofsf_0mk2('neq,numr aex_ex f),ofsf_cadtheo!*); 
      ncbuffer := ofsf_ncinit();
      % 2. RECURSION CASE: j<=r
      % 2a. 0<=j<=k
      if 0<=j and j<=k then % full dec., no truth values
	 while cell := ofsf_nextcell(ncbuffer,sp,nrdata,xj,j,k) do
	    treel := ofsf_treeovercell(cell,cdr ff,varl,qal,psi) . treel
      else << % 2b. k<=j<r
      	 % set tv of basecell to neutral element wrt theta_j+1
      	 thetaj := cdr nth(qal,j-k);
      	 neutral := if thetaj eq 'all then 'true else 'false;
      	 acell_puttv(basecell,neutral);
      	 % as long as the truth value of the basecell is unknown
      	 while (acell_gettv basecell eq neutral) and (cell :=
	    ofsf_nextcell(ncbuffer,sp,nrdata,xj,j,k)) do <<	 
	       treel := ofsf_treeovercell(cell,cdr ff,varl,qal,psi) . treel; 
	       acell_puttv(basecell,acell_gettv atree_rootlabel car treel)
	    >>;
	 % add remaining cells, if wanted
	 if not !*rlcadpartial then
	    while cell := ofsf_nextcell(ncbuffer,sp,nrdata,xj,j,k) do
	       treel := ofsf_treeovercell(cell,cdr ff,varl,qal,psi) . treel;
      >>;
      if !*rlcadisoallroots then while aex_nextroot(nrdata,xj) do ;
      if ofsf_cadverbosep() then ioto_prin2 {"_",(2*n+1)-length treel,")"};
      % construct result tree
      if !*rlcadtrimtree and j > k then res := atree_new basecell
	 else res := atree_addchildlistip(atree_new basecell,treel);
      % propagation below free variable space
      if not !*rlcadpbfvs then return res;
      tv := list2set for each b in treel collect acell_gettv atree_rootlabel b;
      if length tv eq 1 then acell_puttv(atree_rootlabel res, car tv); 
      return res
   end;

algebraic procedure doc(pl,ql);
   begin scalar np,qp,caa,cbb,ccc,p_i,pj,qi,qj,sd;
      caa := cbb := ccc := 0;
      np := length pl;
      ng := length ql;
      if np neq ng then rederr "doc: parameter lists have different lengths";
      for i := 1 : np-1 do
	 for j := i+1 : ng do
	 <<
	    p_i := mynth(pl,i); pj := mynth(pl,j);
	    qi := mynth(ql,i); qj := mynth(ql,j);
	    if p_i <> -1 and pj <> -1 and qi <> -1 and qj <> -1 then
	    <<
	       caa := caa+1;
	       sd := abs(sign(p_i-pj)-sign(qi-qj));
	       if sd=0 then cbb := cbb+1
	       else if sd=1 then ccc := ccc+1;		  	      
	    >>
	 >>;
      return (cbb+1/2*ccc)/caa
   end;


algebraic procedure degreeofcorrespondence(pl,gl);
   begin scalar np,ng;
      np := length pl;
      ng := length gl;
      n := for i := 1 : np-1 sum
	 for j := i+1 : ng sum
	    quality1(mynth(pl,i),mynth(pl,j),mynth(gl,i),mynth(gl,j));
      d := for i := 1 : np-1 sum for j := i+1 : ng sum
	 if mynth(pl,i)<>mynth(pl,j) then 1;
      write d;
      if d=0 then return 1;
      return n/d
   end;

algebraic procedure quality1(p1,p2,g1,g2);
   if p1=p2 then 0
   else if p1<p2 then
      (if g1>g2 then 0 else if g1=g2 then 1/2 else 1)
   else % p1>p2
      quality1(p2,p1,g2,g1);

algebraic procedure rlcadnumauto(phi);
%   rlcadnum(rlcadproj(phi,pord),pord)
%      where pord=>for each vb in rlcadvbl phi join vb;
   begin scalar plist,pord;
      pord := for each vb in rlcadvbl rlpnf phi join vb;
      plist := rlcadproj(phi,pord);
      return rlcadnum(plist,pord)
   end;

algebraic procedure rlcaddefaultorder(phi);
   for each vb in rlcadvbl rlpnf phi join vb;

algebraic procedure rlcadnum(pl,pord);
   first rlcadnum1(pl,pord);

algebraic procedure rlcadguessauto(phi);
   begin scalar plist,pord;
      pord := for each vb in rlcadvbl rlpnf phi join vb;
      plist := rlcadproj(phi,pord);
      return rlcadguess(plist,pord)
   end;

algebraic procedure rlcadguess(pl,pord);
   for each n in rlcadguess1(pl,pord) product n;

symbolic operator rlcadnum1;
lisp procedure rlcadnum1(pl,pord);
   % . [pl] is a list (Fr,...,F1) of projection factors, [pord] is a
   % list (xr,...,x1) of variables. Returns a list (#Dr,...,#D1) of numbers.
   begin scalar oldorder,w,ff,varl;
      oldorder := setkorder pord;
      w := for each ffj in cdr pl collect
 	 for each f in cdr ffj collect reorder numr simp f;
      ff := reverse w;
      varl := reverse cdr pord;
      w := reversip ofsf_cadnum1(ff,varl,nil); % (#Dr,...,#D1)
      setkorder oldorder;
      return 'list . w;
   end;

symbolic operator rlcadpnum;
procedure rlcadpnum(phi,pord);
   ofsf_cadpnum(rl_simp phi,cdr pord);
   
symbolic operator rlcadguess1;
lisp procedure rlcadguess1(pl,pord);
   % . [pl] is a list (Fr,...,F1) of projection factors, [pord] is a
   % list (xr,...,x1) of variables. Returns a list (#Dr,...,#D1) of numbers.
   begin scalar oldorder,w,ff,varl,!*rlacdguessnoc;
      oldorder := setkorder pord;
      w := for each ffj in cdr pl collect
 	 for each f in cdr ffj collect reorder numr simp f;
      ff := reverse w;
      varl := reverse cdr pord;
      %on1 !*rlcadguessnoc;      
      w := ofsf_cadnum1(ff,varl,t);
      %off1 !*rlcadguessnoc;
      w := reversip w; % (#Dr,...,#D1)
      setkorder oldorder;
      return 'list . w;
   end;

procedure ofsf_cadnum1(ff,varl,probe);
   begin scalar w;
      w := ofsf_fulltree(ff,varl,probe);
      return for i := 0 : length varl collect length atree_levellabels(w,i)
   end;

procedure ofsf_fulltree(ff,varl,probe);   
   ofsf_fulltreeovercell(basecell,ff,varl,'unknown,'unknown,probe)
	 % this is the only cell of D0
	 where basecell=acell_mk(nil,nil,nil,'true);

procedure ofsf_fulltreeovercell(basecell,ff,varl,qal,psi,probe);
   % Cad full tree over cell. basecell is a cell in D_j-1, ff is
   % Fj,...,Fr, varl is x1,...,x_r, qal and psi are not needed.
   % Returns a tree over the basecell. Intuition: Finds for a cell C
   % in D_j a full cad tree that has C as a root; each cell has a
   % sample point, but no truth values.
   begin scalar r,k,j,ffj,xj,sp,cell,treel,thetaj,neutral,nrdata,ncbuffer,res,
	 tv;
      integer d,n;
      if ofsf_cadverbosep() then ioto_prin2 {"(",length acell_getsp basecell};
      %ioto_tprin2t {"tree over: ",basecell}; % vb output, sometimes needed
      r := length varl;
      k := r; % not needed, nextcell would need it for fulldimonly and gen1
      j := r-length ff+1;
      sp := acell_getsp basecell;
      % 1. BASE CASE: j=r, evaluation case. The base cell is a leaf.
      if j > r then <<
	 if ofsf_cadverbosep() then ioto_prin2 ")";
      	 return atree_new basecell
      >>;
      % Prepare Polynomials
      xj := nth(varl,j);
      ffj := ofsf_tocprepare(ff,xj,sp,varl);
      nrdata := rip_init(ffj,xj); % initialize next root data
      rip_putpscl(nrdata,for each psc in rip_pscl nrdata join
	 if (d := aex_stchsgnch(cdr psc,xj,'minfty) -
	    aex_stchsgnch(cdr psc,xj,'infty)) neq 0 then <<n := n+d;{psc}>>);
      if ofsf_cadverbosep() then ioto_prin2 {":",2*n+1};
      ncbuffer := ofsf_ncinit();
      % 2. RECURSION CASE: j<=r
      if 0<=j and j<=r then % full dec., no truth values
	 if probe then <<
	    cell := ofsf_nextcell(ncbuffer,sp,nrdata,xj,j,k);
	    treel := ofsf_fulltreeovercell(cell,cdr ff,varl,qal,psi,probe) . treel;
	    for i := 1 : (2*n+1)-1 do
	       treel := atree_new basecell . treel;
	 >> else while cell := ofsf_nextcell(ncbuffer,sp,nrdata,xj,j,k) do
	    treel := ofsf_fulltreeovercell(cell,cdr ff,varl,qal,psi,probe) . treel;
      % construct result tree
      return atree_addchildlistip(atree_new basecell,treel);
   end;

procedure ofsf_tocprepare(ff,xj,sp,varl);
   % Tree over cell prepare polynomials. [ff] is a list of SF's, [xj]
   % is a variable. Intuition: ff=Fj,...,Fr
   begin scalar ffj;
      ffj := car ff;      
      if null sp then <<
	 if ofsf_cadverbosep() then ioto_prin2 "(base case)";
	 ffj := if !*rlcadfac then
	    for each f in ffj collect aex_fromsf f
	 else
	    for each f in ofsf_cadproj1(ffj) collect aex_fromsf f; %%% unused?
      >> else <<
      	 % convert SF to AEX and substitute sample point from basecell
      	 ffj := for each f in ffj collect
	    ofsf_subsp(aex_fromsf f,sp,varl); % list of univar AEX
      	 % make elements of ffj smaller and throw away null and const polys
      	 ffj := for each ae in ffj collect aex_mklcnt aex_reduce ae;
      	 ffj := for each ae in ffj join
	    if not aex_simplenumberp ae then {aex_reduce aex_sqfree(ae,xj)};
      	 if !*rlcaddebug then
	    for each f in ffj do if aex_sgn aex_lc(f,xj) eq 0 then
	       prin2t "ofsf_tocprepare: smaller but lc trivial";
      	 if !*rlcaddebug then
	    for each f in ffj do if aex_simplenumberp f then
	       prin2t "ofsf_tocprepare: smaller but number";
      	 % make elements of ffj pairwise prime (paarweise teilerfremd)      
      	 ffj := aex_pairwiseprime(ffj,xj);
      	 if !*rlcaddebug then
	    for each f in ffj do if aex_sgn aex_lc(f,xj) eq 0 then
	       prin2t "ofsf_tocprepare: pairwiseprime but lc trivial";
      	 if !*rlcaddebug then
	    for each f in ffj do if aex_simplenumberp f then
	       prin2t "ofsf_tocprepare: pairwiseprime but number";
      >>;
      return ffj;
   end;

procedure caddata_mk(phi,k,r,varl,qal,psi,ff,dd,phiprime,oldorder,ophi,jj,theo);
   % Make. [phi] is an ofsf formula, k and r are integers, [varl] is a
   % list of identifiers, [qal] is a list of dotted pairs (x . q), ff
   % is a vector of SF, DD is a ATREE, [phiprime] is a quantifier-free
   % ofsf formula, [oldorder] is a list of identifiers and ff is a
   % vector of SF. Returns CADDATA. Undefined entries should have the
   % value $'undefined$. Returns CADDATA.
   begin scalar cd;
      cd := mkvect(13);
      putv(cd,1,phi); % [phi] is an ofsf formula in PNF
      putv(cd,2,k); % [k] is an integer
      putv(cd,3,r); % [r] is an integer
      putv(cd,4,varl); % [varl] is a list of identifiers
      putv(cd,5,qal); % [qal] is a list of dotted pairs (x . q)
      putv(cd,6,psi); % [psi] is a q.-free fof
      putv(cd,7,ff); % [ff] is a vector of SF
      putv(cd,8,dd); % [dd] is an atree
      putv(cd,9,phiprime); % [phiprime] is a q.-free fof
      putv(cd,10,oldorder); % [oldorder] is a list of kernels
      putv(cd,11,ophi); % [ophi] is a fof, the original input formula
      putv(cd,12,jj);
      putv(cd,13,theo); % [theo] is a list of negated atoms
      return cd
   end;

%%% --- basic access functions --- %%%

procedure caddata_phi(cd);      getv(cd,1);
procedure caddata_k(cd);        getv(cd,2);
procedure caddata_r(cd);        getv(cd,3);
procedure caddata_varl(cd);     getv(cd,4);
procedure caddata_xj(cd,j);     nth(getv(cd,4),j);
procedure caddata_qal(cd);      getv(cd,5);
procedure caddata_psi(cd);      getv(cd,6);
procedure caddata_ff(cd);       getv(cd,7);
procedure caddata_ffj(cd,j);    getv(getv(cd,7),j);
procedure caddata_ffv(cd);      getv(cd,7);
procedure caddata_ffl(cd);      cdr vector2list getv(cd,7);
procedure caddata_dd(cd);       getv(cd,8);
procedure caddata_phiprime(cd); getv(cd,9);
procedure caddata_oldorder(cd); getv(cd,10);
procedure caddata_ophi(cd);     getv(cd,11);
procedure caddata_jj(cd);       getv(cd,12);
procedure caddata_theo(cd);     getv(cd,13);

procedure caddata_bvl(cd);
   % bound variable list
   for i := caddata_k cd + 1:caddata_r cd collect nth(caddata_varl cd,i); 

procedure caddata_fvl(cd);
   % free variable list
   for i := 1:caddata_k cd collect nth(caddata_varl cd,i); 

procedure caddata_putphi(cd,phi);           putv(cd,1,phi);
procedure caddata_putk(cd,k);               putv(cd,2,k);
procedure caddata_putr(cd,r);               putv(cd,3,r);
procedure caddata_putvarl(cd,varl);         putv(cd,4,varl);
procedure caddata_putqal(cd,qal);           putv(cd,5,qal);
procedure caddata_putpsi(cd,psi);           putv(cd,6,psi);
procedure caddata_putff(cd,ff);             putv(cd,7,ff);
procedure caddata_putdd(cd,dd);             putv(cd,8,dd);
procedure caddata_putphiprime(cd,phiprime); putv(cd,9,phiprime);
procedure caddata_putoldorder(cd,oldorder); putv(cd,10,oldorder);
procedure caddata_putophi(cd,phi);          putv(cd,11,phi);
procedure caddata_putjj(cd,jj);             putv(cd,12,jj);
procedure caddata_puttheo(cd,theo);         putv(cd,13,theo);

procedure caddata_print(cd);
   begin
      ioto_prin2t "+ caddata:";
      if caddata_phi cd neq 'undefined then ioto_prin2t{"phi := ",caddata_phi cd};
      if caddata_k cd neq 'undefined then ioto_prin2t{"k := ",caddata_k cd};
      if caddata_r cd neq 'undefined then ioto_prin2t{"r := ",caddata_r cd};
      if caddata_varl cd neq 'undefined then ioto_prin2t{"varl := ",caddata_varl cd};
      if caddata_qal cd neq 'undefined then ioto_prin2t{"qal := ",caddata_qal cd};
      if caddata_psi cd neq 'undefined then ioto_prin2t{"psi := ",caddata_psi cd};
      if caddata_ff cd neq 'undefined then ioto_prin2t{"ff := ",caddata_ff cd};
      if caddata_dd cd neq 'undefined then ioto_prin2t{"dd := ",caddata_dd cd};
      if caddata_phiprime cd neq 'undefined then ioto_prin2t{"phiprime := ",caddata_phiprime cd};
      if caddata_oldorder cd neq 'undefined then ioto_prin2t{"oldorder := ",caddata_oldorder cd};
      if caddata_ophi cd neq 'undefined then ioto_prin2t{"ophi := ",caddata_ophi cd};
      %if caddata_ cd neq 'undefined then ioto_prin2t{"",caddata_ cd};
   end;

procedure caddata_print1(cd);
   begin
      ioto_prin2t "+ caddata:";
      if caddata_k cd neq 'undefined then ioto_prin2t{"k := ",caddata_k cd};
      if caddata_r cd neq 'undefined then ioto_prin2t{"r := ",caddata_r cd};
      if caddata_varl cd neq 'undefined then ioto_prin2t{"varl := ",caddata_varl cd};
      if caddata_qal cd neq 'undefined then ioto_prin2t{"qal := ",caddata_qal cd};
      if caddata_oldorder cd neq 'undefined then ioto_prin2t{"oldorder := ",caddata_oldorder cd};
   end;

procedure ofsf_ncinit;
   % ncbuffer nets to hold at most one cell
   {nil};

procedure ofsf_nextcell(ncbuffer,sp,nrdata,xj,j,k);
   % Returns a cell. Caveat: j eq length sp +1, i.e. j is the level of
   % the newly generated cells.
   begin scalar root,cell;
      if car ncbuffer eq 'finished then return nil;
      %ioto_prin2 {"[",length sp,"]"};
      % there is a cell left in ncbuffer (a 0-dim one)
      %   (!*rlcadfulldimonly and j>k): throw away
      %   (!*rlqegen1 and j<=k): throw away, generic cad
      if car ncbuffer then 
	 if not((!*rlcadfulldimonly and j>k) or
	    (!*rlqegen1 and j<=min2(1,k))) then <<
	       cell := car ncbuffer;
	       car ncbuffer := nil;
	       return cell;
      	    >> else <<
	       car ncbuffer := nil;
	       if !*rlverbose and !*rlqegen1 and j<=min2(1,k) then
	       	  ioto_prin2 {"(",j,"!gen)"};
	       if !*rlverbose and !*rlcadfulldimonly and j>k then
	       	  ioto_prin2 {"(",j,"!fdo)"};
	    >>;
      % there is no cell left, so we need to get a root to get the next
      % two cells.
      if root := aex_nextroot(nrdata,xj) then <<
	 % drop one cell in buffer (the 0-dim one)...
	 car ncbuffer := acell_mk(2*(length rip_rootl nrdata)-1,
	    root . sp,nil,nil);
	 % ... and return the other cell (the full-dim one)	 
	 return acell_mk(2*(length rip_rootl nrdata)-2,
	    anu_fromrat(xj,iv_lb anu_iv root,'dontmind) . sp,nil,nil);
      >>;
      % there is no cell and no root left.      
      car ncbuffer := 'finished;
      % if there was no root, make cell with 0 as sample point
      if null rip_rootl nrdata then
	 return acell_mk(0,anu_fromrat(xj,rat_0(),'dontmind) . sp,nil,nil);
      % search rootlist for the maximum of all right bounds. make cell.  
      return acell_mk(2*(length rip_rootl nrdata),anu_fromrat(xj,   
	 rat_mapmax for each r in rip_rootl nrdata collect iv_rb anu_iv r,
	 'dontmind) . sp,nil,nil);      
   end;

procedure ofsf_subsp(ae,sp,varl);
   % ae is an AEX, sp is a sample point of length j-1, varl is
   % x1,...,x_{j-1} or a longer list. Returns an AEX, an univariate
   % algebraic polynomial.
   begin
%      if !*rlcaddebug and not (length sp eq length varl) then
%	 prin2 "***** aecad_subsp: length of sp and val do not match";
      sp := reverse sp;
      while sp do <<
      	 ae := aex_bind(ae,car varl,car sp);
      	 sp := cdr sp; varl := cdr varl
      >>;
      return ae;
   end;

procedure ofsf_subsp!*(ae,sp);
   % In ae, each anu is bound to the main variable of its defining
   % polynomial. Henct no variable list required.
   << sp := reverse sp;
      while sp do << %%% for loop now possible
      	 ae := aex_bind(ae,aex_mvar anu_dp car sp,car sp);
      	 sp := cdr sp;
      >>;
      ae
   >>;

procedure atree_new(a);
   {'tree,a};

procedure atree_rootlabel(tt);
   cadr tt;

procedure atree_addchildip(tt,c);
   cddr tt := c . cddr tt;

procedure atree_addchildlistip(tt,cl);
   << cddr tt := nconc(cl,cddr tt); tt >>;
   
procedure atree_childlist(tt);
   cddr tt;

procedure atree_firstchild(tt);
   if atree_childlist tt then car atree_childlist tt;

procedure atree_levellabels(tt,n);
   if n eq 0 then
      {atree_rootlabel tt}
   else
      for each child in atree_childlist tt join
      	 atree_levellabels(child,n-1);

procedure atree_yield(tt);
   % Truth value yield labels. [tt] is a tree. Returns a list of ACELL.
   if null atree_childlist tt then
      {atree_rootlabel tt}
   else
      for each subtt in atree_childlist tt join atree_yield subtt;

procedure atree_tvyield(tt);
   % Truth value yield labels. [tt] is a tree. Returns a list of ACELL.
   if acell_gettv atree_rootlabel tt neq nil then % undef. tv: nil
      {atree_rootlabel tt}
   else
      for each subtt in atree_childlist tt join atree_tvyield subtt;

procedure atree_print(tt);
for each e in atree_print1(tt,0) do ioto_tprin2t e;

procedure atree_print1(tt,l2sfn);
   % acell_tvasstring atree_rootlabel dd;
   % atree_print1(tt,nil);
   % l2sfn is a function which converts a label to a string. returns a
   % list of strings.
   begin scalar childl, rootlabel;
      childl := atree_childlist(tt);
      rootlabel := atree_rootlabel(tt);
      if null childl then %return %{apply1(l2sfn,rootlabel)};
      return {acell_tvasstring rootlabel};
      return for each s in childl collect
	 (acell_tvasstring rootlabel . ("---" . atree_print1(s,l2sfn)))
   end;

procedure atree_print1(tt,d);
   % atree_print(dd);
   % l2sfn is a function which converts a label to a string. returns a
   % list of strings. returns a list of list of strings.
   begin scalar childl,rootlabel,w;
      childl := atree_childlist(tt);
      rootlabel := atree_rootlabel(tt);
      if null childl then return {{acell_tvasstring rootlabel}};      
      w := for each s in childl join
	 for each l in atree_print1(s,d+1) collect (" " . "   " . l);
      caar w := acell_tvasstring rootlabel;
      cadar w := "---";
      return w
   end;

procedure atree_print1raw(tt,d);
   % returns a list of strings.
   begin scalar childl,w;
      childl := atree_childlist(tt);
      if null childl then return {{d}};      
      w := for each s in childl join
	 for each l in atree_print1raw(s,d+1) collect (" " . l);
      caar w := d;
      return w
   end;

procedure atree_printlin(tt,d);
   % print linear.
   if null atree_childlist tt then
      ioto_prin2 {"(",d,")"}
   else <<
      ioto_prin2 {"(",d};
      for each c in atree_childlist tt do atree_printlin(c,d+1);
      ioto_prin2 ")";
   >>;


%procedure lto_take(l,n);
%   begin scalar rl; % result list
%      while n>0 do <<
%	 rl := car l . rl; l := cdr l; n := n-1;
%      >>;
%      return reversip rl
%   end;

% module acadextension;
% Andreas' CAD extension phase. Includes additional explicit base phase
% code, which is used for efficiency (factorization is possible).
% Extension code is also correct for the special case of the base
% phase.

procedure ofsf_mkvarl(f);
   % Make variable list. [f] is a prenex formula. Returns a dotted
   % pair [(vl . qal)], where [vl] corresponds to the free variables
   % and [qal] is a list of dotted pairs [x . Q], where [x] is a
   % kernel and [Q] the corresponding Quantifier. The first pair in
   % [qal] corresponds to the innermost variable plus quantifier
   begin scalar qal,vl;
      vl := cl_fvarl1 f;  % list of free variables
      while rl_quap rl_op f do <<
	 qal := (rl_var f . rl_op f) . qal;
	 vl := rl_var f . vl;
	 f := rl_mat f
      >>;
      return vl . qal
   end;
   	    
% module asolution;
% Andreas' solution formula construction for the decision case. That
% is, the solution formula is either [true] or [false].

procedure ofsf_solutionformula_old(cd);
   % old version which looks only at cells of level ddk 
   % ff is (F_1,...,Fr), dd is a cad tree
   begin scalar ff,dd,k,ddk,ffk,phiprime,cellstogo;
      if !*rlverbose then
	 ioto_tprin2t "+++ Solution Formula Construction Phase";
      ff := cdr vector2list caddata_ff cd;
      dd := caddata_dd cd;
      k := caddata_k cd;
      if k eq 0 then <<
	 caddata_putphiprime(cd,acell_gettv atree_rootlabel dd);
	 return nil
      >>;
      ddk := atree_levellabels(dd,k);
      %ffk := nth(ff,k);
      ffk := for i := 1 : k join nth(ff,i); %%% too much?
      % acdecl = (D_k,...,D_0). ff = (F_1,...,Fr)
      if !*rlverbose then
	 ioto_tprin2t {"+ generating signatures for ", length ffk,
	    " polynomials in ",length ddk," cells"};
      cellstogo := length ddk; % for verbose output
      for each cell in ddk do <<
	 acell_putdesc(cell,ofsf_signature(ffk,acell_getsp cell));
	 if ofsf_cadverbosep() then
	    ioto_prin2 {"[",cellstogo,%"idx",acell_getidx cell," ",
	       (if acell_gettv cell eq 'true then
	       " tt" else " ff"),%acell_getdesc cell,
	       "] "};
	 cellstogo := cellstogo-1;
      >>;
      phiprime := ofsf_sfchong(ffk,ddk);
      if phiprime eq 'ssfcfailed then <<
	 if !*rlverbose then
	 ioto_tprin2t "+ Solution formula construction ssfc failed. ";
	 return nil
      >> else <<
	 if !*rlverbose then
	    ioto_tprin2t "+ Solution formula construction ssfc successful.";
	 if !*rlcadrawformula then
	    caddata_putphiprime(cd,phiprime)
	 else
	    caddata_putphiprime(cd,rl_dnf phiprime)
      >>;
      return nil;	 
   end;

procedure ofsf_solutionformula(cd);
   % Solution formula construction. cd is CADDATA. Returns nil, the
   % argument is changed.
   % ff is (F_1,...,Fr), dd is a cad tree
   begin scalar ff,dd,k,yy,yyi,ffk,phiprime,cellstogo;
      if !*rlverbose then
	 ioto_tprin2t "+++ Solution Formula Construction Phase";
      ff := cdr vector2list caddata_ff cd;
      dd := caddata_dd cd;
      k := caddata_k cd;     
      if memq(acell_gettv atree_rootlabel dd,{'true,'false}) then <<
	 caddata_putphiprime(cd,acell_gettv atree_rootlabel dd);
	 return nil
      >>;
      %ddk := atree_levellabels(dd,k);
      yy := atree_tvyield(dd);
      %%% ffk: "projection polynomials"
      yyi := list2set for each cell in yy collect length acell_getsp cell;
      if !*rlverbose then ioto_prin2t {"+ Levels to be considered: ",yyi};
      ffk := for each i in yyi join append(nth(ff,i),nil);
      phiprime := ofsf_solutionformula1(dd,ff,ffk,yy,yyi,k);
      if phiprime eq 'ssfcfailed then <<
	 if !*rlverbose then
	 ioto_tprin2t "++ SSFC failed, trying all possible projection factors.";
	 yyi := for i := 1 : k collect i;
	 if !*rlverbose then ioto_prin2t {"+ Levels to be considered: ",yyi};
	 ffk := for each i in yyi join append(nth(ff,i),nil);
	 phiprime := ofsf_solutionformula1(dd,ff,ffk,yy,yyi,k);
      >>;      
      if phiprime eq 'ssfcfailed then <<
	 if !*rlverbose then
	 ioto_tprin2t "++ Simple solution formula construction failed. ";
	 return nil
      >> else <<
	 if !*rlverbose then
	    ioto_tprin2t "++ Simple solution formula construction successful.";
	 if !*rlcadrawformula then
	    caddata_putphiprime(cd,phiprime)
	 else
	    caddata_putphiprime(cd,rl_dnf phiprime)
      >>;
      return nil;	 
   end;

procedure ofsf_solutionformula1(dd,ff,ffk,yy,yyi,k);
   begin scalar cellstogo;
      if !*rlverbose then
	 ioto_tprin2t {"+ generating signatures for ", length ffk,
	    " polynomials in ",length yy," cells; (Dk: ",
	    length atree_levellabels(dd,k)," cells)"};
      cellstogo := length yy; % for verbose output
      for each cell in yy do <<
	 acell_putdesc(cell,ofsf_signature4(ffk,acell_getsp cell));
	 if ofsf_cadverbosep() then
	    ioto_prin2 {"[",cellstogo,
	       %"idx",acell_getidx cell," ",%
	       "sig",acell_getdesc cell," ",
	       (if acell_gettv cell eq 'true then
	       " tt" else " ff"),%acell_getdesc cell,
	       "] "};
	 cellstogo := cellstogo-1;
      >>;
      return ofsf_ssfc2(ffk,yy);
   end;
      

procedure ofsf_sfchong(ffk,ddk);
   % Solution formula construction by Hong90. signatures are already
   % calculated.
   begin scalar wwt,wwf,wwc;
      wwt := ofsf_signaturesbytv(ddk,'true);
      wwf := ofsf_signaturesbytv(ddk,'false);
      wwc := intersection(wwt,wwf);
      if null wwc then
	 return rl_smkn('or,
	    for each sig in wwt collect
	       ofsf_sigbasedfo(ffk,sig))
      else
	 return 'ssfcfailed;
   end;

procedure ofsf_ssfc2(ffk,yy);
   % Solution formula construction by Hong90. signatures are already
   % calculated.
   begin scalar wwt,wwf,wwc;
      wwt := ofsf_signaturesbytv(yy,'true);
      wwf := ofsf_signaturesbytv(yy,'false);
      wwc := ofsf_compsig(wwt,wwf);
      if ofsf_cadverbosep() and wwc then
	 ioto_prin2t {"+ SSFC failed because of these compatible signatures: ",
	    wwc};
      if null wwc then
	 return rl_smkn('or,
	    for each sig in wwt collect
	       ofsf_sigbasedfo(ffk,sig))
      else
	 return 'ssfcfailed;
   end;

procedure ofsf_compsig(ww1,ww2);
   % Compatible signatures. ww1 and ww2 are lists of signatures; all
   % signatures have same length. Returns nil, if there are no
   % compatible signatures, (w1,w2), if w1 of ww1 is compatible to w2
   % of ww2.
   begin scalar ww2copy, retvalue;
      if null ww1 then return nil;
      while ww1 and not retvalue do <<
	 ww2copy := ww2;
	 while ww2copy and not retvalue do <<
	    if ofsf_compsig1(car ww1, car ww2copy) then
 	       retvalue := {car ww1, car ww2copy};
	    ww2copy := cdr ww2copy
	 >>;
	 ww1 := cdr ww1
      >>;
      return retvalue
   end;

procedure ofsf_compsig1(w1,w2);
   % compatible signatrues subroutine. w1, w2 are signatures of same
   % length; both should be not empty except for recursive calls.
   % Returns nil or t. Remark: this is a fold, the first element of
   % the disjunction is neutral wrt or for the base case.
   (null w1 or null w2) or
      ((car w1 eq car w2 or car w1 equal "?" or car w2 equal "?") and
 	 ofsf_compsig1(cdr w1,cdr w2));

procedure ofsf_sigbasedfo(ffk,sig);
   % signature based formula. ffk is a list of SF, sig is a signature
   % (can include "?"). returns a qf. FOF.
   begin scalar fo;
      for each f in ffk do <<
	 if not (car sig equal "?") then
	    fo := ofsf_signofpolyfo(f,car sig) . fo;
	 sig := cdr sig
      >>;
      return rl_smkn('and,fo)
   end;

procedure ofsf_signofpolyfo(sf,sigma);
   % sf is a standard form. sigma is in {-1,0,1}.
   if sigma eq -1 then
      ofsf_0mk2('lessp,sf)
   else if sigma eq 0 then
      ofsf_0mk2('equal,sf)
   else if sigma eq 1 then
      ofsf_0mk2('greaterp,sf);

procedure ofsf_evalqff(f,sp,idl);
   % Evaluate quantifier-free formula at sample point. [f] is a
   % quantifier-free OFSF formula; [sp] is a sample point. Returns
   % ['true] or ['false]. Returns the truth value of
   % $f(x_1,\ldots,x_r)$ at point [sp].
   if !*rlcadfasteval then
      ofsf_evalqff!-fast(f,sp,idl)
   else
      cl_simpl(cl_apply2ats1(f,function ofsf_subsignat,{sp,idl}),nil,-1);

%procedure ofsf_trialevalqff(psi,sp);
%   % [psi] is a qf fof, sp is a sample point. returns a simplified
%   % version of psi.
%   cl_apply2ats(psi,
%      function(lambda(x); ofsf_0mk2(ofsf_op x,reorder ofsf_arg2l x)));

procedure ofsf_evalsignf(f,s,idl);
   % Algebraic number evaluate sign of standard form at sample point.
   % f is a SF, s is a Samplepoint, idl is a list of ids. Returns a
   % SF.
   numr simp aex_sgn ofsf_subsp(aex_fromsf f,s,idl);

procedure ofsf_trialevalsgnf(f,sp);
   % Trial evaluation of sign of a sf at sample point. Returns a sf.
   % The sample point needs not to provide a number for each variable.
   <<
      f := ofsf_subsp!*(aex_fromsf f,sp);
      if aex_constp f then
	 numr simp aex_sgn f
      else
	 ratpoly_tosf aex_ex f
   >>;

procedure ofsf_sgnf4(f,sp);
  <<
      f := ofsf_subsp!*(aex_fromsf f,sp);
      if aex_constp f then
	 aex_sgn f
      else
	 "?"
   >>;

procedure ratpoly_tosf(rp);
   % warning: denominator might be negative.
   << %if abs denr rp neq 1 then prin2t "***** ratpolx_tosf: invalid argument";
      if sgn denr rp eq 1 then numr rp
      else multf((-1),numr rp)
   >>;

procedure ofsf_subsignat(at,sp,idl);
   % Substitute sign in atomic formula. [at] is an OFSF atomic
   % formula; [sp] is a sample point. Returns an OFSF atomic formula.
   % Returns [at] with the left-hand side $f$ replaced by the sign of
   % $f([sp])$, or a simpler version of f under the context of sp.
   ofsf_0mk2(ofsf_op at,ofsf_evalsignf(ofsf_arg2l at,sp,idl));

procedure ofsf_evalqff!-fast(f,sp,idl);
   % Evaluate quantifier-free formula at sample point fastly. [f] is a
   % quantifier-free OFSF formula in NNF; [sp] is a sample point;
   % [idl] is a LIST of identifiers. Returns ['true] or ['false].
   % Returns the truth value of $f(x_1,\ldots,x_r)$ at point [sp].
   if cl_atfp f then
      ofsf_simplat1(ofsf_subsignat(f,sp,idl),nil)
   else
      ofsf_evalqff!-fast1(f,sp,idl);

procedure ofsf_evalqff!-fast1(f,sp,idl);
   % Evaluate quantifier-free formula at sample point fastly
   % subroutine. [f] is a quantifier-free OFSF formula in NNF; [sp] is
   % a sample point; [idl] is a LIST of identifiers. Returns ['true]
   % or ['false]. Returns the truth value of $f(x_1,\ldots,x_r)$ at
   % point [sp].
   if rl_tvalp f then
      f
   else
      ofsf_evalqff!-gand(rl_op f,rl_argn f,sp,idl);

procedure ofsf_evalqff!-gand(gand,argl,sp,idl);
   % Evaluate quantifier-free formula at sample point generic and.
   % [gand] is one of [and], [or]; [argl] is a list of formulas; [sp]
   % is a sample point; [idl] is a LIST of identifiers. Returns
   % ['true] or ['false]. Returns the truth value of $([gand] .
   % [argl])(x_1,\ldots,x_r)$ at point [sp].
   begin scalar gfalse,arg,cargl,c;
      gfalse := cl_cflip('false,gand eq 'and);
      c := t; while argl and c do <<
	 arg := car argl;
	 argl := cdr argl;
	 if cl_atfp arg then
	    (if ofsf_simplat1(ofsf_subsignat(arg,sp,idl),nil) eq gfalse then
	       c := nil)
	 else
	    cargl := arg . cargl
      >>;
      if not c then
	 return gfalse;
      c := t; while cargl and c do <<
	 arg := car cargl;
	 cargl := cdr cargl;
	 if ofsf_evalqff!-fast1(arg,sp,idl) eq gfalse then
	    c := nil
      >>;
      if not c then
	 return gfalse;
      return cl_flip gfalse
   end;

procedure ofsf_signature(fk,sp);
   % signature. [fk] is a list of standard forms (in, say, variables
   % x1,...,xk), [sp] is sample point (a list (ak,...,a1) of algebraic
   % numbers. returns a list (sigma1,...,sigmak) of elements of
   % (-1,0,1}.
   for each f in fk collect
      aex_sgn ofsf_subsp!*(aex_fromsf f,sp);

procedure ofsf_signature4(fk,sp);
   % signature. [fk] is a list of standard forms (in, say, variables
   % x1,...,xk), [sp] is sample point (a list (al,...,a1) of algebraic
   % numbers with l <= k). returns a list (sigma1,...,sigmak) of
   % elements of (-1,0,1,?).
   for each f in fk collect
      ofsf_sgnf4(f,sp);

procedure ofsf_signaturesbytv(ddk,tv);
   % Signatures by truth value. [ddk] is a list of cells.
   for each c in ddk join
      if acell_gettv c eq tv then {acell_getdesc c};

%%% unused
procedure ofsf_sortsignatures(sl);
   %[sl] is a non-empty list of signatures.
   % {{0,1},{0,0},{1,1},{-1,1},{0,-1}}
   <<
      for i := length car sl step -1 until 1 do
      	 sl := append(ofsf_s1(sl,i,-1),append(ofsf_s1(sl,i,0),ofsf_s1(sl,i,1)));
      sl
   >>;

%%% unused
procedure lto_orderedlist2set(s);
   begin scalar cs;
      if null s or null cdr s then
      	 return s
      else <<
      	 cs := lto_orderedlist2set cdr s;
      	 if car s eq car cs then return cs else return car s . cs
      >>
   end;

%procedure setminus(ss1,ss2);
%   for each s1 in ss1 join if not member(s1,ss2) then {s1};

%procedure intersection(ss1,ss2);
%   setminus(ss1,setminus(ss1,ss2));

procedure ofsf_s1(sl,n,sign);
   % picks the signatures from [sl], where the [n]th element equals [sign].
   for each s in sl join if nth(s,n) eq sign then {s};

%%% --- Types --- %%%

lisp procedure type_checking(ob,tp); type_checking1(ob,tp,"");

lisp procedure type_checking1(ob,tp,str);
   % Type checking. [ob] is anything, [tp] is a type, [str] is
   % anything. Return value is not used.
   if not type_check(ob,tp) then
      rederr {str,":",ob,"does not match type """,tp,""""};

lisp procedure type_check(ob,tp);
   % Type check. [ob] is anything, [tp] is a type. Returns a truth value.
   begin
      %if not type_typep tp then rederr {"type_check:",tp,"is not a type"};
      % atomic types
      if tp eq 'type then return type_typep ob;
      type_checking1(tp,'type,"type_check");
      if tp eq 'any then return t;
      if tp eq 'num then return numberp ob;
      if tp eq 'atom then return atom ob;
      if tp eq 'id then return idp ob;
      if tp eq 'sf then return type_sfp ob;
      if tp eq 'sq then return type_sqp ob;
      % algebraic types
      if atom tp then rederr "type_check: unknown atomic type specified";
      if car tp eq 'pair then
	 return pairp ob and type_check(car ob,cadr tp) and
	 type_check(cdr ob,caddr tp);
      if car tp eq 'list then
	 return type_listp ob and type_checkl1(ob,cadr tp);
      if car tp eq 'mat then
	 return type_check(ob,{'list,{'list,cadr tp}});
      if car tp eq 'sum then
	 return type_check1l(ob,cdr tp);      
   end;

lisp procedure type_s2a(ob,tp);
   % Symbolic to algebraic mode conversion wrt. a type. [ob] is
   % anything, [tp] is a type. Returns a truth value.
   begin
      %type_checking1(ob,tp,"type_s2a");
      % atomic type
      if tp memq '(type any num atom id) then return ob;
      if tp eq 'sf then return prep ob;
      if tp eq 'sq then return {'quotient,prep numr ob,prep denr ob};
      if tp eq 'fof then return rl_prep ob;
      % algebraic types
      if atom tp then rederr {"type_s2a: unknown atomic type",tp};
      if car tp eq 'pair then % make a two-element list
	 return {'list,type_s2a(car ob,cadr tp),type_s2a(cdr ob,caddr tp)};
      if car tp eq 'list then
	 return 'list . for each o in ob collect type_s2a(o,cadr tp);
      if car tp eq 'mat then
	 return 'mat . for each l in ob collect
	    for each c in l collect type_s2a(c,cadr tp);
      if car tp eq 'sum then
	 return type_s2a!-1l(ob,cdr tp);      
   end;

% type_s2a ( 1 . 2 ,'(pair num num));
% type_s2a ( {{1},{},{3,4}} ,'(list (list num)));
% type_s2a ( {1,2,{3,4}} ,'(list (sum num (list num))));

lisp procedure type_s2a!-1l(ob,tpl);
   % Symbolic to algebraic mode conversion subroutine. [ob] is any,
   % [tpl] is (list type).
   if null tpl then rederr "type_s2a!-1l: found no matching type"
   else if type_check(ob,car tpl) then type_s2a(ob,car tpl)
   else type_s2a!-1l(ob,cdr tpl);

lisp procedure type_a2s(ob,tp);
   % Algebraic to symbolic mode conversion wrt. a type. [ob] is
   % anything, [tp] is a type. Returns a truth value.
   begin
      % atomic type
      if tp memq '(type any num atom id) then return ob;
      if tp eq 'sf then return numr simp ob; % optional: check denr = 1
      if tp eq 'sq then return simp ob;
      if tp eq 'fof then return rl_simp ob;
      % algebraic types
      if atom tp then rederr {"type_a2s: unknown atomic type",tp};
      if car tp eq 'pair then % make pair from two-element list
	 return type_a2s(cadr ob,cadr tp) . type_a2s(caddr ob,caddr tp);
      if car tp eq 'list then
	 return for each o in cdr ob collect type_a2s(o,cadr tp);
      if car tp eq 'mat then
	 return for each l in cdr ob collect
	    for each c in l collect type_a2s(c,cadr tp);
%      if car tp eq 'sum then
%	 return type_a2s!-1l(ob,cdr tp);
      rederr {"type_a2s: unknown or yet unsupported type",tp};
   end;

% type_a2s('(quotient 1 2),'sq);
% type_a2s('(list 1 (quotient 1 2)),'(pair num sq));
% type_a2s('(list 1 2 3 4),'(list num));
% type_a2s('(list (list 1) (list) (list 3 4)),'(list (list num)));

lisp procedure type_checkl1(obl,tp);
   % Type check subroutine. [obl] is (list any), [tp] is a type.
   % Returns a truth value.
   null obl or (type_check(car obl,tp) and type_checkl1(cdr obl,tp));

lisp procedure type_check1l(ob,tpl);
   % Type check subroutine. [ob] is any, [tpl] is (list type). 
   % Returns a truth value.
    not null tpl and (type_check(ob,car tpl) or type_check1l(ob,cdr tpl));

lisp procedure type_typep(a);
   % Type predicate. [a] is anything. Returns a truth value.
   begin
      if a memq '(type any num atom id sf sq) then return t;
      if not pairp a then return nil;
      if car a eq 'pair and type_listp a and length a=3 and type_typep1 cdr a
	 then return t;
      if car a eq 'list and type_listp a and length a=2 and type_typep1 cdr a
	 then return t;
      if car a eq 'mat and type_listp a and length a=2 and type_typep1 cdr a
	 then return t;
      if car a eq 'sum and type_listp a and length a>1 and type_typep1 cdr a
	 then return t;
      % ...
      return nil; % sure, unnecessary
   end;

lisp procedure type_typep1(al);
   null al or (type_typep car al and type_typep1 cdr al);

% type_typep 'any;
%type_typep '(sum any);

lisp procedure type_listp(a);
   % List predicate. [a] is anything. Returns a truth value.
   null a or (pairp a and type_listp cdr a); 

procedure type_sfp(f);
   % Standard form with an identifier as a kernel predicate. [f] is
   % anything. Returns a truth value.
   null f or domainp f or
      (pairp f and type_sfp cdr f and
	 pairp car f and type_sfp cdar f and
	    pairp caar f and idp caaar f and numberp cdaar f);

procedure type_sqp(q);
   % Standard quotient with an identifier as a kernel predicate. [f]
   % is anything. Returns a truth value.
   pairp q and type_sfp car q and type_sfp cdr q;

% type_listp {1,2,3};
% type_check({1,2,3},'(list num));
% type_check({1,2,3},'(list any));
% type_check(5,'(sum id num iv));
% type_check(5,'(sum id (list any)));
% type_check({1,'x},'(list (sum id num)));
% type_check({{1,2},{3,4}},'(mat num));

endmodule;   % asolution

end;  % of file
