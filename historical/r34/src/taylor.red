module taylor;

%****************************************************************
%
%                      THE TAYLOR PACKAGE
%                      ==================
%
%****************************************************************
%
%  Copyright (C) 1989,1990,1991 by Rainer M. Schoepf,
%   all rights reserved.
%
%  Copying of this file is authorized only if either
%  (1) you make absolutely no changes to your copy, including name, or
%  (2) if you do make changes, you name it something other than
%      taylor.red.
%
%  Error reports please to: Rainer Schoepf
%                           Konrad-Zuse-Zentrum
%                           fuer Informationstechnik Berlin
%                           Heilbronner Str. 10
%                           W-1000 Berlin 31
%                           Federal Republic of Germany
%                   Email:  <SCHOEPF@SC.ZIB-Berlin.DE>
%
%
%  This package implements a new data structure:
%
%            >>> the TAYLOR KERNEL <<<
%
%  and the functions necessary to operate on it.
%
%  A TAYLOR KERNEL is a kernel of the following form:
%
%   (Taylor!* TayCoeffList TayTemplate TayOrig TayFlags)
%
%   where:
%    Taylor!*        is a symbol identifying the kernel.
%    TayCoeffList    is a list of TayCoeff's.
%                    A TayCoeff is a pair
%                     (TayPowerList . StandardQuotient).
%                    A TayPowerList is a list of TayDegreeList's,
%                    each of which is a list of integers that
%                    denote the exponents of the Taylor variables.
%    TayTemplate     is a list of lists, each containing the three
%                    elements  TayVars, TayExpPoint, TayMaxDegree
%                    (being the list of variables, the expansion point
%                     and the maximal power of the variable, resp.)
%                    It is used as a template for the car of the
%                    pairs in a TayCoeffList.
%    TayOrig         is the original expression to be Taylor expanded,
%                    as a standard quotient. It is held mainly for
%                    the use by possible future extensions.
%                    This part is nil if the switch taylorkeeporiginal
%                    was off during expansion.
%    TayFlags        is currently unused and reserved for future
%                    extensions.
%
%
%
%*****************************************************************
%
%       Revision history
%
%*****************************************************************
%
% 03-Jun-91    1.3
%   Started version for REDUCE 3.4.
%   Updated diffp according to changes for REDUCE 3.4.
%   Replaced freeof by has!-Taylor!* in taysimpf and taysimpt, and by
%    depends in difftaylor and taylor2e.
%   Changed module names to conform to file names.
%   Moved (nearly) all smacros into header (taylor) module,
%    made cst!-Taylor!* an smacro, moved remaining functions from
%    taymacros into tayutils, deleted taymacros module.
%   Made makecoeffpairs (in module taybasic) from smacro to expr.
%   Changed taylorsamevar to use TayOrig part of Taylor kernel if
%    present.
%   Changed Taylor printing functions since it is now possible to
%    pass information of operator precedence (via pprifn property).
%   Fixed bug in subsubtaylor (found by H. Melenk): did not substitute
%    in expansion point.
%   Changed error handling to call new function rerror instead of
%    rederr.
%   Changed for use of new hooks prepfn2, subfunc, and dfform
%    instead of redefining sqchk, subsublis, and diffp.
%
% 20-Oct-90    1.2j
%   Added check in subsubtaylor for variable dependency.
%   Fixed stupid bug in taylorsamevar.
%   Corrected taysimpexpt to handle rational exponents with ON RATIONAL.
%   Corrected expttayrat: looks now at first NON-ZERO coefficient to
%    determine whether root can safely be computed.
%   Fixed bug in mult!.comp!.tp..
%   Added error check in invtaylor1 and quottaylor1.
%   Fixed bug in quottaylor1 that produced wrong results for
%    multidimensional Taylor series, introduced taydegree!-min2 and
%    taydegree!-strict!-less!-or!-equal!-p.
%
% 05-Oct-90    1.2i
%   Replaced variable name nn by nm in taysimpsq to avoid name conflicts
%    with the SPDE package by Fritz Schwartz.
%   Replaced call to apply by apply1 in taysimpkernel.
%   Minor changes in expttayrat, taysimplog, taysimpexp, and taysimptan:
%    inserted explicit calls to invsq to allow negative numbers in
%    denominator.
%   Fixed bugs in difftaylorwrttayvar, inttaylorwrttayvar and
%    subsubtaylor: treatment of a Taylor kernel expanded about infinity
%    would give a wrong result.  Found by John Stewart.
%
% 11-Aug-90    1.2h
%   Replaced call to get!* by get in diffp since get!* will no longer
%    be available in REDUCE 3.4.
%   Fixed bug in multintocoefflist that was introduced by replacing
%    car by TayCfPl.
%   Moved setting of TayOrig part from taylor1 to taylorexpand.  This
%    avoids Taylor kernels in the TayOrig part of multidimensional
%    Taylor expansions.  It does not fully solve the problem since
%    they can still be generated by applying the Taylor operator to
%    expressions that do not contain fully Taylor-combined Taylor
%    kernels.
%   Reversed list of expansions in call to taylorexpand in simptaylor.
%    Modified taylor1 accordingly.  Previously this could trigger a
%    `This can't happen' error message (due to incorrect ordering of
%    the Taylor variables).
%   Removed procedures delete!-coeff and replace!-coeff since they are
%    no longer used.
%   Moved call to subs2 out of differentiation loop in taylor2f,
%    improves timing significantly; deleted superfluous declared
%    integer variable.
%   Fixed bug in taylorsamevar.
%   Added extra checks and double evaluation of lists in simptaylor.
%   Replaced a number of ./ by !*f2q, introduced some !*n2f conversion
%    functions.
%   Development frozen, version shipped out.
%
% 06-May-90    1.2g
%   Fixed bug in taylor2e that caused order of kernels in homogenous
%    expansions to be reverted.  Discovered by Karin Gatermann.
%   Removed binomial!-coeff since no longer needed (in expttayrat).
%   Replaced some forgotten car/cdr by TayCfPl/TayCfSq.
%   Reordered import declarations.
%   Replaced many semicolons by dollar signs.  Decreases amount of
%    printing during input of this file.
%   Minor bug fix in taysimpsin.
%   Minor change in taysimpasin and taysimpatan.
%   Split inttaylorwrttayvar into two procedures, added check for
%    logarithmic term in integration procedure inttaylorwrttayvar1.
%   Replaced combination of addsq and negsq by subtrsq in quottaylor1,
%    subsubtaylor and taysimplog.
%   Renamed taygetcoeff to TayGetCoeff (doesn't make any difference
%    on case-insensitive systems).
%   Minor changes in taymultcoeffs, multintocoefflist, resimptaylor,
%    taylor1sq, taylor2f, negtaylor1, quottaylor1, invtaylor1,
%    expttayrat, subsubtaylor, difftaylor, taysimpasin, taysimpatan,
%    taysimplog, taysimpexp, taysimptan, difftaylorwrttayvar,
%    inttaylorwrttayvar1, addtaylor1 (cons -> TayMakeCoeff).
%   Similar change in taysimpp (cons -> .**, i.e. to).
%
% 29-Mar-90    1.2f
%   Fixed bug in taysimpf (addition of Taylor kernels) that could cause
%    "This can't happen" message.
%   Fixed bug in difftaylorwrttayvar: arguments to make!-cst!-coefflis
%    were interchanged.
%   Fixed similar bug in expttayrat (this procedure was never used!)
%   Added forgotten call to list in taylor2f.
%   Changed representation of big-O notation: print O(x^3,y^3) instead
%    of O(x^3*y^3) if expansion was done up to x^2*y^2.
%   Introduced new version of expttayrat (algorithm as quoted by Knuth)
%    which is faster by about a factor of two.
%   Fixed Taylor!-gen!-big!-O so that expansion point at infinity
%    is treated correctly for homogeneously expanded series.
%
% 27-Feb-90    1.2e
%   Removed procedures addlogcoeffs, addexpcoeffs and addtancoeffs,
%    inserted code directly into taysimplog, taysimpexp, and
%    taysimptan.
%   taylorvars renamed to TayVars.
%   find!-non!-zero moved into Taylor!:macros module.
%
% 26-Feb-90    1.2d
%   Added following selector, constructor, and modification smacros:
%    TayCfPl, TayCfSq, TayMakeCoeff, set!-TayCfPl, set!-TayCfSq,
%    TayTpElVars, TayTpElPoint, TayTpElOrder.
%   Some minor changes in several procedures to improve readability.
%
% 19-Jan-90    1.2c
%   Removed first argument of addtaylor since never used.
%
% 14-Nov-89    1.2b
%   Added taysimpsin.
%   Split tayinpoly1 off from tayinpoly, modified expttayrat
%    accordingly.
%   Changed global declarations to fluid.  No reason to prevent
%    binding.
%
% 11-Nov-89    1.2a
%   Minor changes in the procedures changed yesterday (cleanup).
%   Added procedure taysimptan.
%   Replaced taylor1sq by taylorexpand in taysimpf1.
%   taysimpsq partly rewritten (will these bugs never die out?)
%   taysimpf1 renamed to taysimpf, taylor!*!-sf!-p to
%    Taylor!-kernel!-sf!-p.
%   Replaced a few of these by Taylor!-kernel!-sq!-p.
%
% 10-Nov-89    1.2
%   Introduced taylorexpand to be the heart of simptaylor and to
%    replace simptaylor in taysimpt and multpowerintotaylor.
%   Added new versions of procedures taysimplog and taysimpexp
%    (Knuth's algorithm).
%   Taylor!:basic module moved up (so that some smacros are
%    defined earlier).
%
%
% 09-Nov-89    1.1b
%   Fixed bug in taylor2e: quottaylor1 got the wrong template so
%    that it would truncate the resulting coeff list.
%   Added call to subs2 after call to diffsq in taylor2f so that
%    expressions containing radicals are simplified already at
%    this point.
%
% 21-Aug-89    1.1a
%   Fixed bug in taysimpp: it could return a s.q. instead of a s.f.
%   Added a few forgotten import declarations.
%
% 31-Jul-89    1.1
%   Slight changes in calls to confusion, minor change in taysimpp.
%   Introduced big-O notation, added taylorprintorder switch.
%   taysimpasin and taysimpatan now also calculate the inverse
%    hyperbolic functions.
%   New smacro Taylor!-kernel!-sq!-p replaces combinations of
%    kernp and Taylor!*p.
%
%
% 24-Jul-89    1.0a
%   Bug fix in constant!-sq!-p: mvar applied to s.q., not s.f.
%   Added safety check in taysimpt.
%
% 27-May-89    1.0
%   Decided to call this version 1.0, it seems to be sufficiently (?)
%    bug free to do so.
%   Minor bug fix in expttayrat (forgotten variable declaration).
%
%
% 25-May-89    0.9l
%   Bug fixed in taylor2e
%    (thanx to Rich Winkel from UMC for pointing out this one).
%   Cleaned up the code for truncating when combining Taylor kernels
%    of different order.
%   Introduced taysimpasin for computing the asin, acos, etc.
%    of a Taylor kernel.
%   Changed some internal procedures to call addtaylor1, etc.
%    instead of addtaylor, etc. if both arguments have the same
%    template.
%   Changed representation of the coefflist: expansion with respect
%    to one variable is a special case of homogeneous expansion.
%    This is now reflected in the internal representation.  These
%    changes make the code shorter since all expansions are
%    done the same way (fewer checks necessary).
%
% 23-Mar-89    0.9k
%   Numerous bug fixes.
%   Changed subsubtaylor to allow error checking in var!-is!-nth.
%   Rewrote taydegree!-lessp to iterate over its arguments rather
%    than call itself recursively.
%   Introduced exceeds!-order instead of taydegree!-lessp
%    (in truncate!-coefflist and multtaylor1).
%   Minor changes in Taylor!*!-sf!-p, taysimpexp, var!-is!-nth,
%    taysimpexpt, and inttaylorwrttayvar.
%   Changed simptaylor!* to apply resimp to all coefficients and
%    to the tayorig part.
%   Changed subsubtaylor to allow substitution of a kernel into a
%    homogeneously expanded expression.
%   Changed difftaylorwrttayvar to allow differentiation of
%    homogeneously expanded expressions.
%   Changed subsubtaylor so that substitution of a kernel is possible
%    (not only a variable).
%   New constructor smacros make!-Taylor!* and TayFlagsCombine replace
%    explicit list building.
%   New procedures: get!-degree and truncate!-coefflist induced
%    changes in addtaylor/multtaylor/quottaylor/invtaylor.
%    This fixes the other problem pointed out by H. Melenk.
%   Split addtaylor/multtaylor the same way as quottaylor/invtaylor.
%   Introduced taylorautocombine switch and interface to simp!*
%    (via mul!* list).
%   Added symbolic; statement in taylor!-intro module; necessary
%    until module/endmodule are fixed to work together with faslout.
%   Changed subsubtaylor to return a conventional prefix form
%    if all Taylor variables are substituted by constants.
%   Changed difftaylorwrttayvar to ensure that the coefflist of
%    the Taylor kernel it returns is not empty.
%   Changed subsubtaylor to avoid 0**n for n<=0 when substituting
%    a Taylor variable (to signal an error instead);  changed
%    taylor!-error accordingly.
%   Added taylortemplate operator, removed smacro
%    taylor!-map!-over!-coefficients.
%   Added code for expansion about infinity.
%   Split quottaylor into two parts: the driver (quottaylor) and
%    the routine doing the work (quottaylor1).  Same for invtaylor.
%   Rewrote the expansion procedures taylor1, taylor2,...
%   Change in taylor2e: added flg parameter, introduced
%    delete!-superfluous!-coeffs.
%   Added set!-tayorig and multintocoefflist.
%   Replaced simp by simp!* for simplication of tayorig part in
%    taysimplog and taysimpexpt.
%   Removed taysimpsq in taylorseriesp: it now returns t iff its
%    argument is a Taylor kernel disguised as a standard quotient.
%   Added taylororiginal operator.
%   Added a number of tests if tayorig of a Taylor kernel is non-nil
%    if !*taylorkeeporiginal is set.
%   Replaced calls to simpdiff in taylor2e and simpexpt by a call
%    to simp.
%   Minor change in taylor!*print!*1.
%   H. Melenk discovered that the code did not behave as documented:
%    addition of Taylor kernels differing only in their order did not
%    work, and Taylor expansion of a Taylor kernel w.r.t. one of its
%    variables would fail.
%    Corrected the latter problem by changing the substitution code
%    to allow a Taylor variable to be replaced by a constant.
%   taylorseriesp is now a boolean operator and therefore only
%    usable in if statements.
%   Replaced calls to subsq1/subf1 by subsq/subf,
%    definitions of subsq1 and taymaxdegree deleted.
%   Minor changes in taylor2hom and taylor2e.
%
% 28-Nov-88    0.9j
%   Changed printing of `. . . ' to `...'.
%   Changed simptrig to simp in taysimpatan.
%   Changed simptaylor to simplify all its arguments, not only
%    the first one.
%   Added !*verboseload switch to conditionalize printing of
%    loading info.
%   Changed taylor2 to call taylor!-error instead of rederr.
%    Modified taylor!-error accordingly.
%
% 16-Nov-88    0.9i
%   Fixed a Typo in quottaylor.
%   Inserted module/endmodule declarations.
%   Added errorset in taylor2 to catch zero denominators, etc.,
%    caused by expansion about essential singularities.
%
% 10-Nov-88    0.9h
%   Fixed bugs that caused taking car of an atom (found by A.C.Hearn).
%    taysimpt used multf instead of multpf.
%    I also discovered a car/cdr of nil in
%    makecoeffpairs1/makecoeffpairshom1.
%    Reason: (nil . nil) == (nil), but what I want is
%    ((nil . nil)) == ((nil)).  Stupid, eh?
%
% 23-Jul-88    0.9g
%   Added dmode!* to list of fluid variables,
%    removed taylor!-map!-over!-coefficients!-and!-orig.
%
% 26-May-88    0.9f
%   Minor bug fix in taydegree!-lessp.
%
% 25-May-88    0.9e
%   Fixed a number of smaller bugs.
%   Finally implemented multiplication and division for
%    homogeneously expanded Taylor series.
%   Today I realized that the procedure diffp in ALG2 had
%    been changed for REDUCE 3.3.
%
% 21-May-88    0.9d
%   Fixed bug in invtaylor.
%   Rewrote quottaylor to do direct division rather use invtaylor.
%
% 14-May-88    0.9c
%   Fixed substitution for expansion variable.
%
% 11-May-88    0.9b
%   Fixed user interface functions taylorseriesp and taylortostandard.
%
% 10-May-88    0.9a
%   Small changes in subsubtaylor and difftaylor to make the code
%    compilable, plus minor bug fixes.
%
% 08-May-88    0.9
%    invtaylor changed to allow inversion of multidimensional
%     Taylor kernels (but still not for homogeneous expansion).
%
%
% 06-May-88    0.8i
%   `conc' changed to `join' (for mnemonic purposes).
%
% 29-Apr-88    0.8h
%   Minor bug fix in invtaylor (missing quote).
%
% 21-Mar-88    0.8g
%   Minor change in TayDegreeSum.
%
% 17-Jan-88    0.8f
%   Started implementation of homogeneous expansion
%    (required change in conversion to prefix form).
%
% 16-Jan-88    0.8e
%   Minor change in the definition of confusion.
%
% 15-Jan-88    0.8d
%   Changed to conform to REDUCE 3.3
%    (SWITCH statement, minor changes in parsing).
%
% 03-Jan-88    0.8c
%   First version that is supposed to return always a correct result
%    (but not all possible cases are handled).
%
%
%*****************************************************************
%
%       Things to do:
%
%*****************************************************************
%
%     a) Finish implementation of homogeneous expansion (hard).
%     b) Find a method to handle singularities (very hard).
%     c) Perhaps I should change the definition of ORDP to order
%         Taylor kernels in some special way?
%     d) An interface for the PART operator is desirable.  Currently
%        Taylor kernels are converted into prefix form.
%        Alas, with REDUCE 3.x this requires redefinition of some
%         functions. (More hooks, please!)
%        Same applies to COEFF and COEFFN.
%     e) Rewrite the expansion code to recursively descend a standard
%         form.  This allows recognition of certain special functions,
%         e.g., roots and logarithms.  (Much work, requires rewriting
%         of a large part of the code.)
%     f) With e) it is easy to implement a DEFTAYLOR operator so that
%         the user may define the Taylor expansion of an unknown
%         function.
%     g) This would also allow the use of Taylor for power series
%         solutions of ODEs.
%     h) Implement a method to do series inversion.
%     i) Implement a sort of lazy evaluation scheme, similar to the
%         one used in the TPS package written by Alan Barnes and
%         Julian Padget.  This would allow the calculation of more
%         terms of a series when they are needed.
%     j) Replace all non-id kernels that are independent of the Taylor
%         variables by gensyms.  This would reduce the size of the
%         expressions.
%
%

create!-package('(taylor
                  tayintro
                  tayutils
                  tayinterf
                  taybasic
                  taysimp
                  taysubst
                  taydiff
                  tayconv
                  tayprint
                  tayfrontend
                  tayfns),
                '(contrib taylor));


%*****************************************************************
%
%       Non-local variables used in this package
%
%*****************************************************************

symbolic$ % Necessary until module/endmodule are fixed to work
          %  together with faslout

fluid  '(taylor!:version        % version number
         taylor!:date!*         % release date
         !*taylorkeeporiginal   % \
         !*taylorautoexpand     %  \  see
         !*taylorautocombine    %  /  below
         !*taylorprintorder     % /
         convert!-taylor!*
         !*verboseload)$

Comment This package has five switches:
        `TAYLORKEEPORIGINAL' causes the expression for which the
        expansion is performed to be kept.
        `TAYLORAUTOEXPAND' makes Taylor expressions ``contagious''
        in the sense that all other terms are automatically
        Taylor expanded and combined.
        `TAYLORAUTOCOMBINE' causes taysimpsq to be applied to all
        expressions containing Taylor kernels.  This is equivalent
        to applying `TAYLORCOMBINE' to all those expressions.
        If `TAYLORPRINTORDER' is set to ON Taylor kernels are
        printed in big-O notation instead of just printing three dots.
        `VERBOSELOAD' is a variable used by Portable Standard Lisp
        and causes a loading info to be printed;

switch taylorautocombine,
       taylorautoexpand,
       taylorkeeporiginal,
       taylorprintorder,
       verboseload$

convert!-taylor!* := nil$      % flag indicating that Taylor kernels
                               % should be converted to prefix forms
!*taylorkeeporiginal := nil$   % used to indicate if the original
                               % expressions (before the expansion)
                               % are to be kept.
!*taylorautoexpand := nil$     % set if non-taylor expressions are to
                               % be expanded automatically on
                               % combination.
!*taylorautocombine := nil$    % set if taysimpsq should be added to
                               % the MUL!* list.
%!*verboseload := nil$         % set if loading info should be printed
taylor!:version := "1.3"$      % version number of the package
taylor!:date!* := "03-Jun-91"$ % release date

if !*verboseload then
  << terpri ();
     prin2 "TAYLOR PACKAGE, version ";
     prin2 taylor!:version;
     prin2 ", as of ";
     prin2 taylor!:date!*;
     prin2t " for REDUCE 3.4 being loaded...";
     terpri () >> $



%*****************************************************************
%
%      General utility smacros
%
%*****************************************************************


symbolic smacro procedure nzerolist n;
  %
  % generates a list of n zeros
  %
  nlist (0, n)$

symbolic smacro procedure copy!-list l;
  %
  % produces a copy of list l.
  %
  append(l, nil)$



%*****************************************************************
%
%      Selector and constructor smacros for Taylor kernels
%
%*****************************************************************


exports add!-degrees, comp!.tp!.!-p, cst!-taylor!*, find!-non!-zero,
        get!-degree, has!-taylor!*, make!-cst!-coefflis,
        make!-cst!-powerlist, make!-taylor!*, mult!.comp!.tp!.,
        multintocoefflist, resimptaylor, set!-taycfpl, set!-taycfsq,
        set!-taycoefflist, set!-tayflags, set!-tayorig,
        set!-taytemplate, taycfpl, taycfsq, taycoefflist,
%        TayDegreeList,
        taydegreesum, tayflags, tayflagscombine,
        taygetcoeff, taylor!-kernel!-sf!-p, taylor!-kernel!-sq!-p,
        taylor!*p, tayvars, taymakecoeff, taymincoeff, taymultcoeffs,
        tayorig, taytemplate, taytpelpoint, taytpelorder, taytpelvars,
        tpdegreelist$

imports

% from REDUCE kernel:
        domainp, eqcar, kernp, lastpair, lc, ldeg, multsq, mvar, neq,
        numr, over, red, resimp, reversip, smember, subs2;


fluid '(!*taylorkeeporiginal)$


symbolic smacro procedure make!-taylor!* (cflis, tp, orig, flgs);
  %
  % Builds a new Taylor kernel structure out of its parts.
  %
  list ('taylor!*, cflis, tp, orig, flgs)$

symbolic smacro procedure taymakecoeff (u, v);
  %
  % Builds a coefficient from degreelist and s.q.
  %
  u . v$


Comment Selector smacros for the parts of a Taylor kernel;

symbolic smacro procedure taycoefflist u; cadr u$

symbolic smacro procedure taytemplate u; caddr u$

symbolic smacro procedure tayorig u; cadddr u$

symbolic smacro procedure tayflags u; car cddddr u$

symbolic smacro procedure taycfpl u; car u$

symbolic smacro procedure taycfsq u; cdr u$

symbolic smacro procedure tayvars u;
  for each x in taytemplate u join copy!-list car x$

symbolic smacro procedure taygetcoeff (degrlis, coefflis);
  (if null cc then nil ./ 1 else cdr cc)
    where cc := assoc (degrlis, coefflis)$

symbolic smacro procedure tpdegreelist tp;
  for each x in tp collect caddr x$

%symbolic smacro procedure TayDegreeList u;
%  TpDegreeList TayTemplate u$

symbolic smacro procedure taydegreesum u;
  for each x in taytemplate u sum caddr x$

symbolic smacro procedure taytpelvars u; car u$

symbolic smacro procedure taytpelpoint u; cadr u$

symbolic smacro procedure taytpelorder u; caddr u$


Comment Modification smacros;

symbolic smacro procedure set!-taycoefflist (u, v);
  %
  % Sets TayCoeffList part of Taylor kernel u to v
  %
  rplaca (cdr u, v)$

symbolic smacro procedure set!-taytemplate (u, v);
  %
  % Sets TayTemplate part of Taylor kernel u to v
  %
  rplaca (cddr u, v)$

symbolic smacro procedure set!-tayorig (u, v);
  %
  % Sets TayOrig part of Taylor kernel u to v
  %
  rplaca (cdddr u, v)$

symbolic smacro procedure set!-tayflags (u, v);
  %
  % Sets TayFlags part of Taylor kernel u to v
  %
  rplaca (cddddr u, v)$

symbolic smacro procedure set!-taycfpl (u, v);
  rplaca (u, v)$

symbolic smacro procedure set!-taycfsq (u, v);
  rplacd (u, v)$


Comment Smacros and procedures that are commonly used ;

symbolic smacro procedure tayflagscombine (u, v);
  %
  % Not much for now
  %
  nil$

symbolic smacro procedure get!-degree dg;
  %
  % Procedure to handle degree parts of Taylor kernels.
  %
  for each n in dg sum n$

symbolic smacro procedure taymincoeff cflis;
  %
  % Returns degree of first non-zero coefficient
  % or 0 if there isn't any.
  %
  begin
   loop:
    if not null numr taycfsq car cflis
      then return get!-degree car taycfpl car cflis;
    cflis := cdr cflis;
    if null cflis then return 0;
    goto loop
  end$

symbolic smacro procedure taymultcoeffs (c1, c2);
  %
  % (TayCoeff, TayCoeff) -> TayCoeff
  %
  % multiplies the two coefficients c1,c2.
  % both are of the form (TayPowerList . s.q.)
  % so generate an appropriate degreelist by adding the degrees.
  %
  taymakecoeff (add!-degrees (taycfpl c1, taycfpl c2),
                multsq (taycfsq c1, taycfsq c2))$

symbolic smacro procedure multintocoefflist (coefflis, sq);
  %
  % (TayCoeffList, s.q.) -> TayCoeffList
  %
  % Multiplies each coefficient in coefflis by the s.q. sq.
  %
  for each p in coefflis collect
    taymakecoeff(taycfpl p, multsq (taycfsq p, sq))$

symbolic smacro procedure resimptaylor u;
  %
  % (TaylorKernel) -> TaylorKernel
  %
  % u is a Taylor kernel, value is the Taylor kernel
  % with coefficients and TayOrig part resimplified
  %
  make!-taylor!* (
         (for each cc in taycoefflist u collect
            taymakecoeff (taycfpl cc, subs2 resimp taycfsq cc)),
         taytemplate u,
         if !*taylorkeeporiginal and tayorig u
           then resimp tayorig u else nil,
         tayflags u)$

symbolic smacro procedure make!-cst!-powerlist tp;
  %
  % (TayTemplate) -> TayPowerList
  %
  % Generates a powerlist for the constant coefficient
  % according to template tp
  %
  for each el in tp collect nzerolist length taytpelvars el$

symbolic smacro procedure make!-cst!-coefflis (cst, tp);
  %
  % (s.q., TayTemplate) -> TayCoeffList
  %
  % Generates the constant coefficient cst
  % according to Taylor template tp
  %
  list taymakecoeff (make!-cst!-powerlist tp, cst)$

symbolic smacro procedure cst!-taylor!* (cst, tp);
  %
  % (s.q., TayTemplate) -> TaylorKernel
  %
  % generates a Taylor kernel with template tp for the constant cst.
  %
  make!-taylor!* (
     make!-cst!-coefflis (cst, tp), tp, cst, nil)$


Comment Predicates;

symbolic smacro procedure has!-taylor!* u;
  %
  % (Any) -> Boolean
  %
  % checks if an expression u contains a Taylor kernel
  %
  smember ('taylor!*, u)$

symbolic smacro procedure taylor!*p u;
  %
  % (Kernel) -> Boolean
  %
  % checks if kernel u is a Taylor kernel
  %
  eqcar (u, 'taylor!*)$

symbolic smacro procedure taylor!-kernel!-sf!-p u;
  %
  % (s.f.) -> Boolean
  %
  % checks if s.f. u is a Taylor kernel
  %
  not domainp u and null red u and lc u = 1
     and ldeg u = 1 and taylor!*p mvar u$

symbolic smacro procedure taylor!-kernel!-sq!-p u;
  %
  % u is a standard quotient,
  % returns t if it is simply a Taylor kernel
  %
  kernp u and taylor!*p mvar numr u$

endmodule;


module tayintro;

%*****************************************************************
%
%          General utility functions
%
%*****************************************************************


exports
        confusion, constant!-sq!-p, delete!-nth, delete!-nth!-nth,
        replace!-nth, replace!-nth!-nth, smemberlp, taylor!-error,
        var!-is!-nth$

imports

% from REDUCE kernel
        denr, domainp, kernp, mvar, neq, nlist, numr, prin2t, rederr$


symbolic procedure var!-is!-nth (tp, var);
  %
  % Determines in which part of template tp the kernel var occurs.
  % Returns a pair (n . m) of positive integers which means
  %  that var is the mth subkernel in nth element of template tp
  % This would look a lot better if the loop statements allowed
  %  the use of the return statement.
  %
  begin scalar el, found; integer n, m;
    n := 0;
    repeat <<
      n := n + 1;
      el := caar tp;
      while el do <<
        m := 1;
        if var neq car el then << el := cdr el; m := m + 1 >>
         else << el := nil; found := t >> >>;
      tp := cdr tp >>
    until null tp or found;
    if not found then confusion 'var!-is!-nth
     else return (n . m)
  end$

symbolic procedure delete!-nth (l, n);
  %
  % builds a new list with nth element of list l removed
  %
  if n = 1 then cdr l else car l . delete!-nth (cdr l, n - 1)$

symbolic procedure delete!-nth!-nth (l, n, m);
  %
  % builds a new list with mth element of nth sublist of list l
  % removed
  %
  if n = 1 then delete!-nth (car l, m) . cdr l
   else car l . delete!-nth!-nth (cdr l, n - 1, m)$

symbolic procedure replace!-nth (l, n, v);
  %
  % builds a new list with the nth element of list l replaced by v
  %
  if n = 1 then v . cdr l else car l . replace!-nth (cdr l, n - 1, v)$

symbolic procedure replace!-nth!-nth (l, n, m, v);
  %
  % builds a new list with the mth element of nth sublist of list l
  % replaced by v
  %
  if n = 1 then replace!-nth (car l, m, v) . cdr l
   else car l . replace!-nth!-nth (cdr l, n - 1, m, v)$

symbolic procedure constant!-sq!-p u;
  %
  % returns t if s.q. u represents a constant
  %
  numberp denr u and domainp numr u
      or kernp u and atom (u := mvar u) and flagp (u, 'constant)$

symbolic procedure smemberlp (u, v);
  %
  % true if any member of list u is contained at any level in v
  %
  if null v then nil
   else if atom v then v member u
   else smemberlp (u, car v) or smemberlp (u, cdr v)$

symbolic procedure confusion msg;
  %
  % called if an internal error occurs.
  % (I borrowed the name from Prof. Donald E. Knuth's TeX program)
  %
  << terpri ();
     prin2 "TAYLOR PACKAGE (version ";
     prin2 taylor!:version;
     prin2 ", as of ";
     prin2 taylor!:date!*;
     prin2t "):";
     prin2 "This can't happen (";
     prin2 msg;
     prin2t ") !";
     rerror (taylor, 1,
             "Please send input and output to Rainer M. Schoepf!") >>$

symbolic procedure taylor!-error (type, info);
  %
  % called if a normal error occurs.
  % type is the type of error, info the error info.
  %
  begin scalar msg; integer errno;
    msg := if type eq 'not!-a!-unit then "Not a unit in argument to"
            else if type eq 'wrong!-no!-args
             then "Wrong number of arguments to"
            else if type eq 'expansion
             then "Error during expansion"
            else if type eq 'wrong!-type!-arg
             then "Wrong argument type"
            else if type eq 'no!-original
             then "Taylor kernel doesn't have an original part in"
            else if type eq 'zero!-denom
             then "Zero divisor in"
            else if type eq 'essential!-singularity
             then "Essential singularity in"
            else if type eq 'branch!-point
             then "Branch point detected in"
            else if type eq 'branch!-cut
             then "Expansion point lies on branch cut in"
            else if type eq 'inttaylorwrttayvar
             then
              "Integration of Taylor kernel yields non-analytical term"
            else if type eq 'dependent!-subst
             then "Substitution of dependent variables"
            else if type eq 'not!-implemented
             then "Not implemented yet"
            else confusion 'taylor!-error;
%    rerror (taylor, errno,
    rerror (taylor, 2,
            if null info then msg
             else if atom info then list (msg, info)
             else msg . info);
  end$

endmodule;


module tayutils;

%*****************************************************************
%
%       Utility functions that operate on Taylor kernels
%
%*****************************************************************


exports delete!-superfluous!-coeffs, enter!-sorted, exceeds!-order,
        taydegree!-lessp, truncate!-coefflist$

imports

% from the REDUCE kernel:
        lastpair, nth, reversip,

% from module Taylor!:macros:
        get!-degree, taycfpl$


fluid '(!*taylorkeeporiginal)$

symbolic procedure add!-degrees (dl1, dl2);
  %
  % calculates the sum of to degree lists dl1, dl2 (element-wise)
  %
  begin scalar dl, u, v, w;
    while dl1 do <<
      u := car dl1;
      v := car dl2;
      w := nil;
      while u do <<
        w := (car u + car v) . w;
        u := cdr u;
        v := cdr v >>;
      dl := reversip w . dl;
      dl1 := cdr dl1;
      dl2 := cdr dl2 >>;
    return reversip dl
  end$

symbolic procedure find!-non!-zero pl;
  %
  % pl is a power list.  Returns pair (n . m) of position of first
  % non zero degree.
  %
  begin scalar u; integer n, m;
    n := 1;
   loop:
    m := 1;
    u := car pl;
   loop2:
    if not (car u = 0) then return (n . m);
    u := cdr u;
    m := m + 1;
    if not null u then goto loop2;
    pl := cdr pl;
    n := n + 1;
    if null pl then confusion 'find!-non!-zero;
    goto loop
  end$

symbolic procedure comp!.tp!.!-p (u, v);
  %
  % Checks templates of Taylor kernels u and v for compatibility,
  % i.e. whether variables and expansion points match.
  % Returns t if possible.
  %
  begin;
    u := taytemplate u; v := taytemplate v;
    if length u neq length v then return nil;
   loop:
    if not (taytpelvars car u = taytpelvars car v
            and taytpelpoint car u = taytpelpoint car v)
      then return nil;
    u := cdr u; v := cdr v;
    if null u then return t;
    goto loop
  end$

symbolic procedure add!.comp!.tp!. (u, v);
  %
  % Checks templates of Taylor kernels u and v for compatibility
  % when adding them, i.e. whether variables and expansion points
  % match.
  % Returns either new Taylor template whose degrees are the minimum
  % of the corresponding degrees of u and v, or nil if variables or
  % expansion point(s) do not match.
  %
  begin scalar w;
    u := taytemplate u; v := taytemplate v;
    if length u neq length v then return nil;
   loop:
    if not (taytpelvars car u = taytpelvars car v
            and taytpelpoint car u = taytpelpoint car v)
      then return nil
     else w := list (taytpelvars car u,
                     taytpelpoint car u,
                     min2 (taytpelorder car u, taytpelorder car v))
                . w;
    u := cdr u; v := cdr v;
    if null u then return reversip w;
    goto loop
  end$

symbolic procedure mult!.comp!.tp!. (u, v, div!?);
  %
  % Checks templates of Taylor kernels u and v for compatibility
  % when multiplying or dividing them, i.e. whether variables and
  % expansion points match.  The difference to addition is that
  % in addition to the new template it returns two degreelists
  % to be used by truncate!-coefflist which
  % are made up so that the kernels have the same number of terms.
  %
  begin scalar w, w1, w2, cf1, cf2;
        integer !#terms!-1, dl1, dl2, mindg;
    cf1 := taycoefflist u;
    while cf1 and null numr taycfsq car cf1 do cf1 := cdr cf1;
    cf1 := taycfpl car cf1;
    cf2 := taycoefflist v;
    while cf2 and null numr taycfsq car cf2 do cf2 := cdr cf2;
    cf2 := taycfpl car cf2;
    u := taytemplate u; v := taytemplate v;
    if length u neq length v then return nil;
   loop:
    if not (taytpelvars car u = taytpelvars car v
            and taytpelpoint car u = taytpelpoint car v)
      then return nil;
    dl1 := get!-degree car cf1;
    dl2 := get!-degree car cf2;
    mindg := if div!? then dl1 - dl2 else dl1 + dl2;
    !#terms!-1 := min2 (taytpelorder car u - dl1,
                        taytpelorder car v - dl2);
    w1 := (!#terms!-1 + dl1) . w1;
    w2 := (!#terms!-1 + dl2) . w2;
    w := list (taytpelvars car u, taytpelpoint car u,
               mindg + !#terms!-1) . w;
    u := cdr u; v := cdr v; cf1 := cdr cf1; cf2 := cdr cf2;
    if null u then return list (reversip w, reversip w1, reversip w2);
    goto loop
  end$

symbolic smacro procedure taycoeff!-before (cc1, cc2);
  %
  % (TayCoeff, TayCoeff) -> Boolean
  %
  % returns t if coeff cc1 is ordered before cc2
  % both are of the form (degreelist . sq)
  %
  taydegree!-lessp (taycfpl cc1, taycfpl cc2)$

symbolic procedure taydegree!-lessp (u, v);
  %
  % (TayPowerList, TayPowerList) -> Boolean
  %
  % returns t if coefflist u is ordered before v
  %
  begin scalar u1, v1;
   loop:
    u1 := car u;
    v1 := car v;
   loop2:
     if car u1 < car v1 then return t;
     u1 := cdr u1;
     v1 := cdr v1;
     if not null u1 then go to loop2;
    u := cdr u;
    v := cdr v;
    if not null u then go to loop
  end$

symbolic procedure taydegree!-strict!-less!-or!-equal!-p (u, v);
  %
  % (TayPowerList, TayPowerList) -> Boolean
  %
  % returns t if every component coefflist u is less or equal than
  %  respective component of v
  %
  begin scalar u1, v1;
   loop:
    u1 := car u;
    v1 := car v;
   loop2:
     if car u1 > car v1 then return nil;
     u1 := cdr u1;
     v1 := cdr v1;
     if not null u1 then go to loop2;
    u := cdr u;
    v := cdr v;
    if not null u then go to loop;
    return t
  end$

symbolic procedure exceeds!-order (ordlis, cf);
  %
  % (List of Integers, TayCoeff) -> Boolean
  %
  % Returns t if the degrees in coefficient cf exceed those
  % in the degreelist ordlis
  %
  begin
   loop:
    if null ordlis then return;
    if get!-degree car cf > car ordlis then return t;
    cf := cdr cf;
    ordlis := cdr ordlis;
    go to loop
  end$

symbolic procedure enter!-sorted (u, alist);
  %
  % (TayCoeff, TayCoeffList) -> TayCoeffList
  %
  % enters u into the alist alist according to the standard
  % ordering for the car part
  %
  if null alist then list u
   else if taycoeff!-before (u, car alist) then u . alist
   else car alist . enter!-sorted (u, cdr alist)$

symbolic procedure delete!-superfluous!-coeffs (cflis, pos, n);
  %
  % (TayCoeffList, Integer, Integer) -> TayCoeffList
  %
  % This procedure deletes all coefficients of a TayCoeffList cflis
  % whose degree in position pos exceeds n.
  %
  for each cc in cflis join
     (if get!-degree nth (taycfpl cc, pos) > n then nil else list cc)$

symbolic procedure truncate!-coefflist (cflis, dl);
  %
  % (TayCoeffList, List of Integers) -> TayCoeffList
  %
  % Deletes all coeffs from coefflist cflis that have at least
  %  one degree greater than the corresponding degree in the
  %  degreelist dl.
  %
  begin scalar l;
    for each cf in cflis do
      if not exceeds!-order (dl, taycfpl cf) then l := cf . l;
    return reversip l
  end$

endmodule;


module tayinterf;

%*****************************************************************
%
%      The interface to the REDUCE simplificator
%
%*****************************************************************


exports simptaylor, simptaylor!*, taylorexpand$

imports

% from the REDUCE kernel:
        !*a2k, !*f2q, !*k2q, aconc!*, denr, depends, diffsq, eqcar,
        lastpair, leq, lprim, mkquote, mksq, multsq, mvar, neq, nth,
        numr, over, reval, reversip, simp, simp!*, subs2, subsq,
        typerr,

% from module Taylor!:intro:
        replace!-nth, smemberlp, taylor!-error, var!-is!-nth,

% from module Taylor!:macros:
        get!-degree, make!-taylor!*, multintocoefflist, resimptaylor,
        set!-tayorig, taycfpl, taycfsq, taycoefflist, tayflags,
        taymakecoeff, tayorig, taytemplate, taytpelorder, taytpelpoint,
        tayvars, taylor!-kernel!-sq!-p, taymincoeff,

% from module Taylor!:utils:
        delete!-superfluous!-coeffs,

% from module taylor!:basic:
        invtaylor1, quottaylor1,

% from module Taylor!:convert:
        preptaylor!*$


fluid '(!*backtrace !*taylorkeeporiginal !*taylorautocombine)$

global '(mul!* subfg!*)$

Comment The following statement forces all expressions to be
        re-simplified if the switch `taylorautocombine' is set to on,
        unfortunately, this is not always sufficient;

put ('taylorautocombine, 'simpfg, '((t (rmsubs))))$


symbolic procedure simptaylor u;
  %
  % (PrefixForm) -> s.q.
  %
  % This procedure is called directly by the simplifier.
  % Its argument list must be of the form
  %     (exp, [var, var0, deg, ...]),
  % where [...] indicate one or more occurences.
  % This means that exp is to be expanded w.r.t var about var0
  % up to degree deg.
  % var may also be a list of variables, which means that the
  % the expansion takes place in a homogeneous way.
  % If var0 is the special atom infinity var is replaced by 1/var
  % and the result expanded about 0.
  %
  if remainder (length u, 3) neq 1
    then taylor!-error ('wrong!-no!-args, 'taylor)
   else if null subfg!* then mksq ('taylor . u, 1)
   else begin scalar ll, f, var, var0, degree;
     %
     % Allow automatic combination of Taylor kernels.
     %
     if !*taylorautocombine and not ('taysimpsq memq mul!*)
       then mul!* := aconc!* (mul!*, 'taysimpsq);
     %
     % First of all, call the simplifier on exp (i.e. car u),
     %
     f := simp!* car u;
     u := cdr u;
     %
     % then scan the rest of the argument list.
     %
     while u do
       << var := reval car u; % reval instead of simp!* to handle lists
          var := if eqcar (var, 'list) then cdr var else list var;
          % In principle one should use !*a2k
          % but typerr (maprin) does not correctly print the atom nil
          for each el in var collect begin
            el := simp!* el;
            if kernp el then return mvar numr el
             else typerr(prepsq el, 'kernel)
            end;
          var0 := reval cadr u;
          degree := reval caddr u;
          if not fixp degree
            then typerr (degree, "order of Taylor expansion");
          u := cdddr u;
          ll := list (var, var0, degree) . ll >>;
     %
     % Now ll is a Taylor template, i.e. of the form
     %  ((var_1 var0_1 deg1) (var_2 var0_2 deg_2) ...)
     %
     return taylorexpand (f, reversip ll)
   end$

put('taylor,'simpfn,'simptaylor)$


symbolic procedure taylorexpand (f, ll);
  %
  % f is a s.q. that is expanded according to the list ll
  %  which has the form
  %  ((var_1 var0_1 deg1) (var_2 var0_2 deg_2) ...)
  %
  begin scalar result;
    result := f;
    for each el in ll do
      %
      % taylor1 is the function that does the real work
      %
      result := !*k2q taylor1 (result, car el, cadr el, caddr el);
      if !*taylorkeeporiginal then set!-tayorig (mvar numr result, f);
      return result
  end$


symbolic procedure taylor1 (f, varlis, var0, n);
  %
  % Taylor expands s.q. f w.r.t. varlis about var0 up to degree n.
  % var is a list of kernels, which means that the expansion
  % takes place in a homogeneous way if there is more than one
  % kernel.
  % If var0 is the special atom infinity all kernels in varlis are
  % replaced by 1/kernel.  The result is then expanded about 0.
  %
  taylor1sq (if var0 eq 'infinity
               then subsq (f,
                           for each krnl in varlis collect
                             (krnl . list ('quotient, 1, krnl)))
              else f,
             varlis, var0, n)$

symbolic procedure taylor1sq (f, varlis, var0, n);
  %
  % f is a standard quotient, value is a Taylor kernel.
  %
  % First check if it is a Taylor kernel
  %
  if taylor!-kernel!-sq!-p f
    then if smemberlp (varlis, tayvars mvar numr f)
           %
           % special case: f has already been expanded w.r.t. var.
           %
           then taylorsamevar (mvar numr f, varlis, var0, n)
          else begin scalar y, z;
            f := mvar numr f;
            %
            % taylor2 returns a list of the form
            %  ((deg1 . coeff1) (deg2 . coeff2) ... )
            % apply this to every coefficient in f.
            % car cc is the degree list of this coefficient,
            % cdr cc the coefficient itself.
            % Finally collect the new pairs
            %  (degreelist . coefficient)
            %
            z :=
              for each cc in taycoefflist f join
                for each cc2 in taylor2 (taycfsq cc, varlis, var0, n)
                  collect
                    taymakecoeff (append (taycfpl cc, taycfpl cc2),
                                  taycfsq cc2);
            %
            % Append the new list to the Taylor template and return.
            %
            y := append (taytemplate f, list list (varlis, var0, n));
            return make!-taylor!* (z, y, tayorig f, tayflags f)
            end
   %
   % Last possible case: f is not a Taylor expression.
   % Expand it.
   %
   else make!-taylor!* (
                 taylor2 (f, varlis, var0, n),
                 list list (varlis, var0, n),
                 if !*taylorkeeporiginal then f else nil,
                 nil)$

symbolic procedure taylor2 (f, varlis, var0, n);
  begin scalar result;
    result := errorset (list ('taylor2e,
                               mkquote f,
                               mkquote varlis,
                               mkquote var0,
                               mkquote n),
                        nil, !*backtrace);
    if atom result
      then taylor!-error ('expansion, "(possible singularity!)")
     else return car result
  end$

symbolic procedure taylor2e (f, varlis, var0, n);
  %
  % taylor2e expands s.q. f w.r.t. varlis about var0 up to degree n.
  % var is a list of kernels, which means that the expansion takes
  % place in a homogeneous way if there is more than one kernel.
  % The case that var0 is the special atom infinity has to be taken
  % care of by the calling function(s).
  % Expansion is carried out separately for numerator and
  % denominator.  This approach has the advantage of not producing
  % complicated s.q.'s which usually appear if an s.q. is
  % differentiated.  The procedure is (roughly) as follows:
  %  if the denominator of f is free of var
  %   then expand the numerator and divide,
  %  else if the numerator is free of var expand the denominator,
  %   take the reciprocal of the Taylor series and multiply,
  %  else expand both and divide the two series.
  % This fails if there are nontrivial dependencies, e.g.,
  %  if a variable is declared to depend on a kernel in varlis.
  % It is of course necessary that the denominator yields a unit
  %  in the ring of Taylor series. If not, an error will be
  %  signalled by invtaylor or quottaylor, resp.
  %
  if cdr varlis then taylor2hom (f, varlis, var0, n)
   else if denr f = 1 then taylor2f (numr f, car varlis, var0, n, t)
   else if not depends (denr f, car varlis)
    then multintocoefflist (taylor2f (numr f, car varlis, var0, n, t),
                            1 ./ denr f)
   else if numr f = 1
    then invtaylor1 (list list (varlis, var0, n),
                     taylor2f (denr f, car varlis, var0, n, nil))
   else if not depends (numr f, car varlis)
    then multintocoefflist
           (invtaylor1 (list list (varlis, var0, n),
                        taylor2f (denr f, car varlis, var0, n, nil)),
            !*f2q numr f)
   else begin scalar denom; integer n1;
     denom := taylor2f (denr f, car varlis, var0, n, nil);
     n1 := n + taymincoeff denom;
     return
       delete!-superfluous!-coeffs
         (quottaylor1 (list list (varlis, var0, n1),
                       taylor2f (numr f, car varlis, var0, n1, t),
                       denom),
          1, n)
  end$

symbolic procedure taylor2f (f, var, var0, n, flg);
  %
  % taylor2f is the procedure that does the actual expansion
  % of the s.f. f.
  % It returns a list of the form
  %  ((deglis1 . coeff1) (deglis2 . coeff2) ... )
  % For the use of the parameter `flg' see below.
  %
  begin scalar x, y, z; integer k;
    %
    % Calculate once what is needed several times.
    % var0 eq 'infinity is a special case that has already been taken
    % care of by the calling functions by replacing var by 1/var.
    %
    if var0 eq 'infinity then var0 := 0;
    x := list (var . var0);
    y := simp list ('difference, var, var0);
    %
    % The following is a first attempt to treat expressions
    % that have poles at the expansion point.
    % Currently nothing more than factorizable poles, i.e.
    % factors in the denominator are handled.
    %
    % We use the following trick to calculate enough terms:
    % If the first l coefficients of the Taylor series are zero
    % we replace n by n + l.  This is necessary since we separately
    % expand numerator and denominator of an expression.  If the
    % expansion of both parts starts with, say, the quadratic term
    % we have to expand them up to order (n+2) to get the correct
    % result up to order n.  It is important, however, to drop
    % the additional coefficients as soon as they are no longer
    % needed.
    % The parameter `flg' is used here to control this behaviour.
    % The calling function must pass the value `t' if it wants to
    % inhibit the calculation of additional coefficients.
    % This is currently the case if the s.q. f has a denominator
    % that may contain the expansion variable.
    % Otherwise `flg' is used to remember if we already
    % encountered a non-zero coefficient.
    %
    f := !*f2q f;
    z := subsq (f, x);
    if null numr z and not flg then n := n + 1 else flg := t;
    y := list taymakecoeff ((list list 0), z);
    k := 1;
    while k <= n and not null numr f do
      << f := multsq (diffsq (f, var), 1 ./ k);
                                             % k is always > 0!
         % subs2 added to simplify expressions involving roots
         z := subs2 subsq (f, x);
         if null numr z and not flg then n := n + 1 else flg := t;
         y := taymakecoeff(list list k, z) . y;
         k := k + 1 >>;
    return reversip y
  end$

symbolic procedure taylor2hom (f, varlis, var0, n);
  %
  % Homogeneous expansion of s.q. f wrt the variables in varlis,
  % i.e. the sum of the degrees of the kernels is varlis is <= n
  %
  if null cdr varlis then taylor2e (f, list car varlis, var0, n)
   else for each u in taylor2e (f, list car varlis, var0, n) join
     for each v in taylor2hom (cdr u,
                               cdr varlis,
                               var0,
                               n - get!-degree taycfpl car u)
           collect list (car taycfpl car u . taycfpl car v) . cdr v$

symbolic procedure taylorsamevar (u, varlis, var0, n);
  begin scalar tp; integer mdeg, pos;
    if cdr varlis
      then taylor!-error ('not!-implemented,
                          "(homogeneous expansion in TAYLORSAMEVAR)");
    tp := taytemplate u;
    pos := car var!-is!-nth (tp, car varlis);
    tp := nth (tp, pos);
    if taytpelpoint tp neq var0
      then return taylor1 (if not null tayorig u then tayorig u
                            else simp!* preptaylor!* u,
                           varlis, var0, n);
    mdeg := taytpelorder tp;
    if n > mdeg
      %
      % further expansion required
      %
      then << lprim "Cannot expand further... truncated.";
              return u >> ;
    return make!-taylor!* (
        for each cc in taycoefflist u join
          if nth (nth (taycfpl cc, pos), 1) > n
            then nil
           else list cc,
        replace!-nth (taytemplate u, pos,
                      list (varlis, taytpelpoint tp, n)),
        tayorig u, tayflags u)
  end$


Comment The `FULL' flag causes the whole term (including the
        Taylor!* symbol) to be passed to SIMPTAYLOR!* ;

symbolic procedure simptaylor!* u;
  << %
     % Allow automatic combination of Taylor kernels.
     %
     if !*taylorautocombine and not ('taysimpsq memq mul!*)
       then mul!* := aconc!* (mul!*, 'taysimpsq);
     !*k2q resimptaylor u >>$

flag ('(taylor!*), 'full)$

put ('taylor!*, 'simpfn, 'simptaylor!*)$

endmodule;


module taybasic;

%*****************************************************************
%
%      Functions that implement the basic operations
%       on Taylor kernels
%
%*****************************************************************


exports addtaylor, addtaylor1, invtaylor, invtaylor1, makecoeffpairs,
        multtaylor, multtaylor1, multtaylorsq, negtaylor, negtaylor1,
        quottaylor, quottaylor1$

imports

% from the REDUCE kernel:
        addsq, invsq, lastpair, multsq, negsq, nth, numr, over, quotsq,
        reversip, subtrsq, union,

% from module Taylor!:intro:
        confusion, taylor!-error,

% from module Taylor!:macros:
        add!.comp!.tp!., add!-degrees, make!-cst!-powerlist,
        make!-taylor!*, mult!.comp!.tp!., multintocoefflist, taycfpl,
        taycfsq, taycoefflist, tayflags, tayflagscombine, taygetcoeff,
        taymakecoeff, taymultcoeffs, tayorig, taytemplate,
        taytpelorder, tpdegreelist,

% from module Taylor!:utils:
        enter!-sorted, exceeds!-order, truncate!-coefflist$


fluid '(!*taylorkeeporiginal)$

symbolic procedure multtaylorsq (tay, sq);
  %
  % multiplies the s.q. sq into the Taylor kernel tay.
  % value is a Taylor kernel.
  % no check for variable dependency is done!
  %
  if null tay or null numr sq then nil
   else make!-taylor!* (
              multintocoefflist (taycoefflist tay, sq),
              taytemplate tay,
              if !*taylorkeeporiginal and tayorig tay
                then multsq (sq, tayorig tay)
               else nil,
              tayflags tay)$


symbolic smacro procedure degree!-union (u, v);
  union (u, v)$ % works for the moment;

symbolic procedure addtaylor (u, v);
  %
  % u and v are two Taylor kernels
  % value is their sum, as a Taylor kernel
  %
  begin scalar tp, dl;
    tp := add!.comp!.tp!. (u, v);
    dl := tpdegreelist tp;
    if null tp then confusion 'addtaylor
     else
       return
         make!-taylor!*
           (addtaylor1 (truncate!-coefflist (taycoefflist u, dl),
                        truncate!-coefflist (taycoefflist v, dl)),
            tp,
            if !*taylorkeeporiginal and tayorig u and tayorig v
              then addsq (tayorig u, tayorig v)
             else nil,
            tayflagscombine (u, v))
  end$

symbolic procedure addtaylor1 (l1, l2);
  %
  % Returns the coefflist that is the sum of coefflists l1, l2.
  %
  begin scalar degreelist, clist;
    degreelist := degree!-union (for each cc in l1 collect taycfpl cc,
                    for each cc in l2 collect taycfpl cc);
    for each degree in degreelist do
      clist := enter!-sorted (taymakecoeff (degree,
                 addsq (taygetcoeff (degree, l1),
                        taygetcoeff (degree, l2))), clist);
    return clist
  end$


symbolic procedure negtaylor u;
  make!-taylor!* (
         negtaylor1 taycoefflist u,
         taytemplate u,
         if !*taylorkeeporiginal and tayorig u
           then negsq tayorig u else nil,
         tayflags u)$

symbolic procedure negtaylor1 tcl;
  for each cc in tcl collect
    taymakecoeff (taycfpl cc, negsq taycfsq cc)$

symbolic procedure multtaylor (u, v);
  %
  % u and v are two Taylor kernels,
  % result is their product, as a Taylor kernel.
  %
  begin scalar tps;
    tps := mult!.comp!.tp!. (u, v, nil);
    if null tps then confusion 'multtaylor
     else
       return
         make!-taylor!*
           (multtaylor1 (car tps,
                      truncate!-coefflist (taycoefflist u, cadr tps),
                      truncate!-coefflist (taycoefflist v, caddr tps)),
            car tps,
            if !*taylorkeeporiginal and tayorig u and tayorig v
              then multsq (tayorig u, tayorig v)
             else nil,
            tayflagscombine (u, v))
  end$

symbolic procedure multtaylor1 (tp, l1, l2);
  %
  % Returns the coefflist that is the product of coefflists l1, l2,
  %  with respect to Taylor template tp.
  %
  begin scalar clist, cff, rlist;
    for i1 := 1:length l1 do
      for i2 := 1:length l2 do
        clist := taymultcoeffs (nth (l1, i1), nth (l2, i2)) . clist;
    tp := tpdegreelist tp;
    for each cc in clist do
      if not exceeds!-order (tp, car cc)
        then if (cff := assoc (car cc, rlist))
               then rplacd (cff, addsq (cdr cff, cdr cc))
              else rlist := enter!-sorted (cc, rlist);
    return rlist
  end$

Comment Implementation of Taylor division.
        We use the following algorithm:
        Suppose the numerator and denominator are of the form

                -----                    -----
                \          k             \          l
        f(x) =   >     a  x   ,  g(x) =   >     b  x   ,
                /       k                /       l
                -----                    -----
                k>=k0                    l>=l0

        respectively.  The quotient is supposed to be

                -----
                \          m
        h(x) =   >     c  x   .
                /       m
                -----
                m>=m0

        Clearly: m0 = k0 - l0.  This follows immediately from
        f(x) = g(x) * h(x) by comparing lowest order terms.
        This equation can now be written:

         -----            -----                 -----
         \          k     \             l+m     \              n
          >     a  x   =   >     b  c  x     =   >    b    c  x  .
         /       k        /       l  m          /      n-m  m
         -----            -----                 -----
         k>=k0            l>=l0              m0<=m<=n-l0
                          m>=m0                n>=l0+m0

        Comparison of orders leads immediately to

                  -----
                  \
          a    =   >    b    c   ,  n>=l0+m0 .
           n      /      n-m  m
                  -----
               m0<=m<=n-l0

        We write the last term of the series separately:

                  -----
                  \
          a    =   >    b    c   + b   c     ,  n>=l0+m0 ,
           n      /      n-m  m     l0  n-l0
                  -----
               m0<=m<n-l0

        which leads immediately to the recursion formula

                       /       -----           \
                   1   |       \               |
         c     = ----- | a  -   >     b    c   | .
          n-l0    b    |  n    /       n-m  m  |
                   l0  \       -----           /
                            m0<=m<n-l0

        Finally we shift n by l0 and obtain

                       /          -----              \
                   1   |          \                  |
         c     = ----- | a     -   >     b       c   | .  (*)
          n       b    |  n+l0    /       n-m+l0  m  |
                   l0  \          -----              /
                                 m0<=m<n

        For multidimensional Taylor series we can use the same
        expression if we interpret all indices as appropriate
        multiindices.

        For computing the reciprocal of a Taylor series we use
        the formula (*) above with f(x) = 1, i.e. lowest order
        coefficient = 1, all others = 0;


symbolic procedure quottaylor (u, v);
  %
  % Divides Taylor series u by Taylor series v.
  % Like invtaylor, it depends on ordering of the coefficients
  %  according to the degree of the expansion variables (lowest first).
  %
  begin scalar tps;
    tps := mult!.comp!.tp!. (u, v, t);
    if null tps then confusion 'quottaylor
     else return make!-taylor!* (
        quottaylor1 (car tps,
                     truncate!-coefflist (taycoefflist u, cadr tps),
                     truncate!-coefflist (taycoefflist v, caddr tps)),
              car tps,
              if !*taylorkeeporiginal and tayorig u and tayorig v
                then quotsq (tayorig u, tayorig v)
               else nil,
              tayflagscombine (u, v))
  end$

symbolic procedure quottaylor1 (tay, lu, lv);
  %
  % Does the real work, called also by the expansion procedures.
  % Returns the coefflist.
  %
  begin scalar clist, lminu, lminv, aminu, aminv, ccmin, coefflis;
    while lu and null numr taycfsq car lu do lu := cdr lu;
    aminu := taycfsq car lu;
    lminu := taycfpl car lu;
    for each el in cdr lu do
      lminu := taydegree!-min2 (lminu, taycfpl el);
    while lv and null numr taycfsq car lv do lv := cdr lv;
    if null lv then taylor!-error ('not!-a!-unit, 'quottaylor);
    if null lu then
      return list taymakecoeff(make!-cst!-powerlist tay, nil ./ 1);
    aminv := taycfsq car lv;   % first element is that of lowest degree
    lminv := taycfpl car lv;
    for each cf in cdr lv do
      if not taydegree!-strict!-less!-or!-equal!-p (lminv, taycfpl cf)
        then taylor!-error ('not!-a!-unit, 'quottaylor);
    (while lminu1 do <<
       ccmin := (for each pp in pair (taycfpl lminu1, taycfpl lminv1)
                                 collect (car pp - cdr pp)) . ccmin;
       lminu1 := cdr lminu1;
       lminv1 := cdr lminv1 >>)
            where lminu1 := lminu, lminv1 := lminv;
    ccmin := reversip ccmin;
    clist := list taymakecoeff(ccmin, quotsq (aminu, aminv));
    coefflis := makecoeffs for each term in pair (ccmin, tay) collect
            (car term . taytpelorder cdr term);
    for each cc in cdr coefflis do
      clist := taymakecoeff(cc,
        quotsq (subtrsq (taygetcoeff (add!-degrees (cc, lminv), lu),
                         addcoeffs (clist, lv, pair (ccmin, cc))),
                aminv))
                 . clist;
    return reversip clist
  end$

symbolic procedure taydegree!-min2 (u, v);
  %
  % (TayPowerList, TayPowerList) -> TayPowerList
  %
  % returns minimum of both powerlists
  %
  for i := 1 : length u collect begin scalar l1, l2;
    l1 := nth (u, i);
    l2 := nth (v, i);
    return
      for j := 1 : length l1 collect
        min2 (nth (l1, j), nth (l2, j))
  end$

symbolic procedure makecoeffshom (cmin, nterms);
  if null cmin then '(nil)
   else for i := 0 : nterms join
     for each l in makecoeffshom (cdr cmin, nterms - i) collect
           (car cmin + i) . l$

symbolic procedure makecoeffs pl;
  %
  % pl is a list of pairs, the car of each being the smallest,
  % the cdr number of terms.
  % It returns an ordered list of all index lists matching this
  % requirement.
  %
  if null pl then '(nil)
   else for each l1 in makecoeffs (cdr (pl)) join
        for each l2 in makecoeffshom (caar pl, cdar pl)
                 collect (l2 . l1)$

symbolic procedure makecoeffpairs1 (pl, lmin);
  if null pl then '((nil))
   else for each l1 in makecoeffpairs1 (cdr pl, cdr lmin) join
     for each l2 in makecoeffpairshom (caar pl, cdar pl, car lmin)
           collect (car l2 . car l1) . (cdr l2 . cdr l1)$

symbolic procedure makecoeffpairshom (clow, chigh, clmin);
  if null clmin then '((nil))
   else for i := car chigh step -1 until car clow join
      for each l in makecoeffpairshom (cdr clow,cdr chigh,cdr clmin)
          collect (i . car l) . ((car chigh + car clmin - i) . cdr l)$

symbolic procedure makecoeffpairs (pl, lmin);
  reversip cdr makecoeffpairs1 (pl, lmin)$

symbolic procedure addcoeffs (cl1, cl2, pl);
  begin scalar s;
    s := nil ./ 1;
    for each p in makecoeffpairs (pl, caar cl2) do
        s := addsq (s, multsq (taygetcoeff (car p, cl1),
                               taygetcoeff (cdr p, cl2)));
    return s
  end$

symbolic procedure invtaylor u;
  %
  % Inverts a Taylor series expansion,
  % depends on ordering of the coefficients according to the
  %  degree of the expansion variables (lowest first)
  %
  if null u then confusion 'invtaylor
   else make!-taylor!* (
               invtaylor1 (taytemplate u, taycoefflist u),
               taytemplate u,
               if !*taylorkeeporiginal and tayorig u
                then invsq tayorig u
                 else nil,
               tayflags u)$

symbolic procedure invtaylor1 (tay, l);
  %
  % Does the real work, called also by the expansion procedures.
  % Returns the coefflist.
  %
  begin scalar clist, amin, ccmin, coefflis;
    while l and null numr taycfsq car l do l := cdr l;
    if null l then taylor!-error ('not!-a!-unit, 'invtaylor);
    amin := taycfsq car l;  % first element must have lowest degree
    ccmin := taycfpl car l;
    for each cf in cdr l do
      if not taydegree!-strict!-less!-or!-equal!-p (ccmin, taycfpl cf)
        then taylor!-error ('not!-a!-unit, 'invtaylor);
    ccmin := for each m in ccmin collect
               for each m1 in m collect -m1;
    clist := list taymakecoeff(ccmin, invsq amin);
    coefflis := makecoeffs for each term in pair (ccmin, tay) collect
            (car term . taytpelorder cdr term);
    for each cc in cdr coefflis do
      clist := taymakecoeff(cc,
                 negsq quotsq (addcoeffs (clist, l, pair (ccmin, cc)),
                               amin))
                   . clist;
    return reversip clist
  end$

endmodule;


module taysimp;

%*****************************************************************
%
%     The special Taylor simplification functions
%
%*****************************************************************


exports taysimpp, taysimpsq, tayinpoly, expttayrat$

imports

% from the REDUCE kernel:
        !*f2q, !*k2f, !*k2q, !*n2f, !*p2f, !*p2q, !*t2f, addd, addf,
        addsq, denr, domainp, exptsq, invsq, kernp, mk!*sq, multf,
        multpf, multsq, mvar, negsq, neq, nth, numr, over, pdeg,
        prepsq, reversip, simp, simp!*, smemqlp, tc, to, tpow,

% from module Taylor!:intro:
        confusion, nzerolist, taylor!-error,

% from module Taylor!:macros:
        comp!.tp!.!-p, has!-taylor!*, find!-non!-zero,
        make!-cst!-coefflis, make!-cst!-powerlist, make!-taylor!*,
        resimptaylor, taycfpl, taycfsq, taycoefflist, tayflags,
        taygetcoeff, taylor!-kernel!-sf!-p, taylor!*p,
        taymakecoeff, taymultcoeffs, tayorig, taytemplate,
        taytpelorder, taytpelvars, tayvars,

% from module Taylor!:basic:
        addtaylor, addtaylor1, invtaylor, makecoeffpairs, makecoeffs,
        multtaylor, multtaylor1, multtaylorsq, quottaylor,

% from module Taylor!:interface:
        taylorexpand$


fluid '(!*taylorautoexpand !*taylorkeeporiginal)$

Comment The procedures in this module provide the higher taylor
        manipulation machinery.  Given any s.q. (s.f.,...) they
        return the equivalent Taylor kernel (disguised as a s.q.)
        if the argument contains a Taylor kernel and everything
        else may be Taylor expanded.
        Otherwise the Taylor kernels in the argument are only
        partially combined (but as far as possible);


symbolic procedure taysimpsq u;
  %
  % The argument u is any standard quotient.
  % numerator and denominator are first simplified independently,
  % then the quotient is built.
  % We have four possible cases here, as both expressions
  %  may or may not be Taylor kernels.
  %
  (lambda (nm, dd);
    if taylor!-kernel!-sf!-p dd
      then if taylor!-kernel!-sf!-p nm
        then if comp!.tp!.!-p (mvar nm, mvar dd)
          then !*k2q resimptaylor quottaylor (mvar nm, mvar dd)
         else nm ./ dd
       else if not smemqlp (tayvars mvar dd, nm)
        then !*k2q resimptaylor
                    multtaylorsq (invtaylor mvar dd, !*f2q nm)
       else if null !*taylorautoexpand or has!-taylor!* nm
        then nm ./ dd
       else !*k2q resimptaylor quottaylor (
                mvar numr taylorexpand (!*f2q nm, taytemplate mvar dd),
                mvar dd)
     else if taylor!-kernel!-sf!-p nm
      then if not smemqlp (tayvars mvar nm, dd)
             then !*k2q resimptaylor multtaylorsq (mvar nm, 1 ./ dd)
            else if null !*taylorautoexpand or has!-taylor!* dd
             then nm ./ dd
            else
              !*k2q resimptaylor quottaylor (mvar nm,
                mvar numr taylorexpand (!*f2q dd, taytemplate mvar nm))
     else nm ./ dd)
   (taysimpf numr u, taysimpf denr u)$

symbolic procedure taysimpf u;
  %
  % u is a standard form which may contain Taylor subexpressions;
  % value is a standard form
  %
  begin scalar tay, notay, x, flg;
    %
    % Remember the definition of a s.f.:
    %  it is either a domain element,
    %  or it's car is a standard term and it's cdr is a s.f.
    %
    while u do
      %
      % Split the constituents of the s.f. into non-Taylor and
      %  Taylor parts.  Taylor s.t.'s are simplified accordingly.
      % A domain element can never be a Taylor kernel.
      %
      << if domainp u then notay := addd (u, notay)
          else if not has!-taylor!* car u
           then notay := addf (notay, !*t2f car u)
          else << x := taysimpt car u;
                  if taylor!-kernel!-sf!-p x
                    then if null tay then tay := mvar x
                      else if comp!.tp!.!-p (tay, mvar x)
                             then tay := addtaylor (tay, mvar x)
                            else << flg := t;
                                    %
                                    % flg indicates that there are
                                    %  Taylor kernels whose templates
                                    %  are not compatible
                                    %
                                    notay := addf (notay, x) >>
                   else notay := addf (notay, x) >>;
         u := if domainp u then nil else cdr u >>;
    %
    % tay is now a Taylor kernel or nil.
    % If it is nil, return the non-taylor parts.
    %
    if null tay then return notay;
    %
    % Otherwise the non-taylor parts (if the are non-nil)
    % must be expanded if !*taylorautoexpand is non-nil.
    % The only exception are terms that do not contain
    % any of the Taylor variables: these are always expanded.
    %
    if null !*taylorautoexpand and smemqlp (tayvars tay, notay)
      then return addf (!*k2f tay, notay);
    if not null notay then
      if flg then return addf (!*k2f tay, notay)
       else <<
         notay := numr taylorexpand (!*f2q notay, taytemplate tay);
         return !*k2f addtaylor (mvar notay, tay) >>
     else return !*k2f tay
  end$

symbolic procedure taysimpt u;
  %
  % u is a standard term containing one or more Taylor kernels,
  % value is the simplified Taylor expression (also as a s.f.).
  %
  begin scalar rest, pow;
    %
    % Since the coefficient of a term is a s.f.
    % we call taysimpf on it.
    %
    rest := taysimpf tc u;
    pow := tpow u;
    %
    % Then we have to distinguish three cases:
    %   the case where no Taylor kernel appears was already caught
    %   by taysimpf before taysimpt was called.
    %
    % If combination of different Taylor kernels is impossible
    %   return them separately
    %
    % Remark: the call to SMEMQLP checks if rest contains one of
    %         the Taylor variables if it is not a Taylor kernel.
    %
    return if not has!-taylor!* pow
      then if taylor!-kernel!-sf!-p rest
             then multpowerintotaylor (pow, mvar rest)
            else multpf (pow, rest)
     else << pow := taysimpp pow;
             %
             % rest cannot be nil at this point
             % but we better check it
             %
             if null rest then confusion 'taysimpt
              else if not has!-taylor!* rest and
                      taylor!-kernel!-sf!-p pow
               then if smemqlp (tayvars mvar pow, rest)
                 then if !*taylorautoexpand
                   then !*k2f multtaylor (mvar pow,
                           mvar numr taylorexpand (!*f2q rest,
                                       taytemplate mvar pow))
                  else multf (pow, rest)
                else !*k2f multtaylorsq (mvar pow, !*f2q rest)
              else if taylor!-kernel!-sf!-p pow and
                      taylor!-kernel!-sf!-p rest and
                     comp!.tp!.!-p (mvar pow, mvar rest)
                     then !*k2f multtaylor (mvar pow, mvar rest)
                    else multf (pow, rest) >>
  end$

symbolic procedure multpowerintotaylor (p, tk);
  %
  % p is a standard power, tk a Taylor kernel
  % value is p expanded to a Taylor kernel multiplied by tk
  % this requires Taylor expansion of p if it contains
  % at least one of the expansion variables
  %
  % Remark: the call to SMEMQLP checks if p contains one of
  %         the Taylor variables.
  %
  if not smemqlp (tayvars tk, p)
    then !*k2f multtaylorsq (tk, !*p2q p)
   else if !*taylorautoexpand
    then !*k2f multtaylor (tk, mvar numr taylorexpand (!*p2q p,
                                     taytemplate tk))
   else multpf (p, !*k2f tk)$


symbolic procedure taysimpp u;
  %
  % u is a standard power containing a Taylor expression,
  % value is the simplified Taylor expression, as a s.f.
  %
  % We begin by isolating base and exponent.
  % First we simplify them separately.
  % Remember that the exponent is always an integer,
  % base is a kernel.
  %
  % If the main variable of the power is a kernel made of one
  %  of the functions known to the Taylor simplifier, call
  %  the appropriate simplification function.
  %  (There is a user hook here!)
  %
  if null car u or null pdeg u then confusion 'taysimpp
   else if not taylor!*p car u
    then ((if kernp x
             then if (x := mvar numr x) = car u
               then !*p2f u
              else taysimpp (x .** cdr u)
            else <<
              x := exptsq (x, cdr u);
              %
              % The following is nothing more than
              %  a `I don't know how to do it'.
              % Needs rewriting of the interfaces.
              %
              if denr x neq 1 then !*p2f u
               else taysimpf numr x >>)
          where x := (taysimpkernel car u))
   %
   % We know how to raise a Taylor series to a rational power:
   %  positive integer --> multiply
   %  negative integer --> multiply and invert
   % Zero exponent should not appear: should be already simplified
   %  to 1 by the standard simplifier
   %
   else if not fixp pdeg u or pdeg u = 0 then confusion 'taysimpp
   else !*k2f
     if pdeg u = 1 then car u
      else if pdeg u < 0 then invtaylor expttayi (car u, -pdeg u)
      else expttayi (car u, cdr u)$

symbolic procedure taysimpkernel u;
  begin scalar fn, x;
    u := simp!* u;
    if not kernp u then return u
     else << x := mvar numr u;
             if atom x or taylor!*p x then return u;
             fn := get (car x, 'taylorsimpfn);
             return if null fn then u
                     else apply1 (fn, x) >>
  end$


symbolic procedure expttayi (u, i);
  %
  % raise Taylor kernel u to positive integer power i
  % algorithm is the straightforward method: successive multiplication
  % should be replaced by a scheme that computes powers of two.
  %
  begin scalar v;
    v := u;
    for k:=1:i-1 do v := multtaylor (v, u);
    return v
  end$


Comment non-positive or non-integer powers of Taylor kernels;


symbolic procedure tayinpoly (polylist, tay);
  %
  % polylist is a list of the coefficients of a polynomial,
  % with the i-th element corresponding to the power var**(i-1)
  % result is the Taylor kernel tay substituted for the polynomial's
  %  variable
  %
  make!-taylor!* (
    tayinpoly1 (polylist, taytemplate tay, taycoefflist tay),
    taytemplate tay,
    nil,
    nil)$


symbolic procedure tayinpoly1 (polylist, tp, cflis);
  %
  % Does the work for tayinpoly.  Returns coeff list.
  % Uses Horner's scheme!
  % We use addtaylor1/multtaylor1 instead of addtaylor/multtaylor
  % since we are sure that the templates match.
  %
  begin scalar x;
    polylist := reversip polylist;
    x := make!-cst!-coefflis (car polylist, tp);
    polylist := cdr polylist;
    while polylist do
      << x := multtaylor1 (tp, x, cflis);
         if not null numr car polylist
           then x := addtaylor1 (x,
                               make!-cst!-coefflis (car polylist, tp));
         polylist := cdr polylist >>;
    return x
  end$


Comment The implementation of expttayrat follows the algorithm
        quoted by Knuth in the second volume of `The Art of
        Computer Programming', extended to the case of series in
        more than one variable.

        Assume you want to compute the series W(x) where

            W(x) = V(x)**alpha

        Differentiation of this equation gives

            W'(x) = alpha * V(x)**alpha * V'(x) .

        You make now the ansatz

                    -----
                    \           n
            W(x) =   >      W  x  ,
                    /        n
                    -----

        substitute this into the above equation and compare
        powers of x.  This yields the recursion formula

                       n-1
                      -----
                  1   \                  m      m
           W  = -----  >    (alpha (1 - ---) - --- ) W  V     .
            n    V    /                  n      n     m  n-m
                  0   -----
                       m=0

        The first coefficient must be calculated directly, it is

           W   = V  ** alpha .
            0     0

        To use this for series in more than one variable you have to
        calculate all partial derivatives: n and m refer then to the
        corresponding component of the multi index.  Looking closely
        one finds that there is an ambiguity: the same coefficient
        can be calculated using any of the partial derivatives.  The
        only restriction is that the corresponding component of the
        multi index must not be zero, since we have to divide by it.

        We resolve this ambiguity by simply taking the first nonzero
        component.

        We use it here only for the case that alpha is a rational
        number;


symbolic procedure expttayrat (tay, rat);
  %
  % tay is a Taylor kernel, rat is a s.q. of two integers
  % value is tay ** rat
  % algorithm as quoted by Knuth
  %
  begin scalar rat1, tc, tp, x;
    %
    % First of all we have to find out if we can raise the leading
    %  term to the power rat.
    % If so we calculate the reciprocal of this leading coefficient
    %  and multiply all other terms with it.
    % This guarantees that the resulting Taylor kernel starts with
    %  coefficient 1.
    %
    tc := taycoefflist tay;
    tp := taytemplate tay;
    rat1 := list ('quotient, car rat, cdr rat);
    %
    % Find first non-zero coefficient.
    %
    while not null tc and null taycfsq car tc do tc := cdr tc;
    if null tc
      then if minusp car rat
             then taylor!-error ('not!-a!-unit, 'expttayrat)
            else x := make!-cst!-coefflis (nil ./ 1, tp)
     else begin scalar c0, clist, coefflis, l, l0, l1;
       c0 := car tc;
       l1 := for each ll in taycfpl c0 collect
          for each p in ll collect <<
            x := divide (p * car rat, cdr rat);
            if cdr x neq 0
              then taylor!-error ('branch!-point, 'expttayrat);
            car x >>;
       l := for each ll in taycfpl c0 collect
              for each p in ll collect -p;
       l := taymakecoeff (l, invsq taycfsq c0);
       %
       % We divide the rest of the kernel (without the leading term)
       %  by the leading term.
       %
       l := for each el in cdr tc collect taymultcoeffs (el, l);
       %
       % Now we compute the coefficients
       %
       l0 := make!-cst!-powerlist tp;
       clist := list taymakecoeff (l0, 1 ./ 1);
       l := taymakecoeff (l0, 1 ./ 1) . l;
       coefflis := makecoeffs for each term in tp collect
                (nzerolist length taytpelvars term . taytpelorder term);
       for each cc in cdr coefflis do
         begin scalar s, pos, pp, q; integer n, n1;
           s := nil ./ 1;
           pos := find!-non!-zero cc;
           n := nth (nth (cc, car pos), cdr pos);
           pp := makecoeffpairs (pair (l0, cc), l0);
           for each p in pp do <<
             n1 := nth (nth (car p, car pos), cdr pos);
             q := quotsq (!*n2f (-n1) ./ 1, n ./ 1);
             s := addsq (s,
                         multsq (addsq (multsq (rat, addsq (1 ./ 1, q)),
                                        q),
                                 multsq (taygetcoeff (car p, clist),
                                         taygetcoeff (cdr p, l))))>>;
           clist := taymakecoeff(cc, s) . clist
         end;
       %
       % Next we multiply the resulting Taylor kernel by the leading
       %  coefficient raised to the power rat.
       %
       c0 :=
        taymakecoeff (l1, simp!* list ('expt, mk!*sq taycfsq c0, rat1));
       x := for each el in reversip clist collect taymultcoeffs (el, c0)
    end;
    %
    % Finally we fill in the original expression
    %
    return make!-taylor!* (x, tp,
      if !*taylorkeeporiginal and tayorig tay
        then simp list ('expt, prepsq tayorig tay, rat1)
       else nil,
      tayflags tay)
  end$

endmodule;


module taysubst;

%*****************************************************************
%
%      Interface to the substitution functions
%
%*****************************************************************


exports subsubtaylor$

imports

% from the REDUCE kernel:
        addsq, depends, exptsq, kernp, multsq, nth, numr, prepsq,
        reversip, simp!*, subsq, subtrsq, typerr,

% from module Taylor!:intro:
        constant!-sq!-p, delete!-nth, delete!-nth!-nth, replace!-nth,
        var!-is!-nth,

% from module Taylor!:macros:
        make!-taylor!*, set!-taycfsq, taycfpl, taycfsq, taycoefflist,
        tayflags, taylor!*p, taylor!-error, tayvars, taymakecoeff,
        tayorig, taytemplate, taytpelpoint, taytpelvars$


fluid '(!*taylorkeeporiginal)$

put ('taylor!*, 'subfunc, 'subsubtaylor);

symbolic procedure subsubtaylor (l, v);
  begin scalar x, clist, tp;
    clist := for each u in taycoefflist v collect
               taymakecoeff (taycfpl u, subsq (taycfsq u, l));
    tp := taytemplate v;
    %
    % Substitute in expansion point
    %
    tp := for each triple in tp collect
            list (taytpelvars triple,
                  reval subeval1 (l, taytpelpoint triple),
                  taytpelorder triple);
    %
    % Make x the list of substitutions of Taylor variables.
    %
    for each p in l do
      if car p member tayvars v
        %
        % The replacement of a Taylor variable must again be
        % a kernel.  If it is a constant, we have to delete it
        % from the list of Taylor variables.  Actually the main
        % problem is to distinguish kernels that are constant
        % expressions (e.g. sin (acos (4))) from others.
        %
        then begin scalar temp;
         temp := simp!* cdr p;
         if constant!-sq!-p temp
          then begin scalar about, ll, w, y, z; integer pos, pos1;
            %
            % Determine the position of the variable
            %
            w := var!-is!-nth (tp, car p);
            pos := car w;
            pos1 := cdr w;
            %
            % Calculate the difference (new_variable - expansion_point)
            %
            about := taytpelpoint nth (tp, pos);
            if about eq 'infinity
              then if null numr temp
                then taylor!-error ('zero!-denom, "Taylor Substitution")
               else temp := invsq temp
             else temp := subtrsq (temp, simp!* about);
            %
            % Substitute in every coefficient
            %
            for each cc in clist do begin scalar exponent;
              w := nth (taycfpl cc, pos);
              w := if null cdr w then delete!-nth (taycfpl cc, pos)
                    else delete!-nth!-nth (taycfpl cc, pos, pos1);
              exponent := nth (nth (taycfpl cc, pos), pos1);
              z := if exponent = 0 then taycfsq cc
                     else if exponent < 0 and null numr temp
                      then taylor!-error ('zero!-denom,
                                          "Taylor Substitution")
                     else multsq (taycfsq cc, exptsq (temp, exponent));
              y := assoc (w, ll);
              if y then set!-taycfsq (y, addsq (taycfsq y, z))
               else ll := taymakecoeff (w, z) . ll
             end;
            %
            % Delete zero coefficients
            %
            clist := nil;
            while ll do <<
              if not null numr taycfsq car ll
                then clist := car ll . clist;
              ll := cdr ll >>;
            << u := delete (car p, taytpelvars u) . cdr u;
               tp := if null car u
                       then delete!-nth (tp, pos)
                      else replace!-nth (tp, pos, u) >>
              where u := nth (tp, pos)
          end
         else if not kernp temp
          then typerr (cdr p, "Taylor variable")
         else <<
           for each el in tayvars v do
             if depends (temp, el)
               then taylor!-error ('dependent!-subst, list (cdr p, el));
           x := p . x >>
        end;
    x := reversip x;
    return if null tp
             then if null clist then 0 else prepsq taycfsq car clist
            else make!-taylor!* (clist, sublis (x, tp),
                        if !*taylorkeeporiginal and tayorig v
                          then subsq (tayorig v, l)
                         else nil,
                        tayflags v)
  end$

endmodule;


module taydiff$

%*****************************************************************
%
%        Differentiation of Taylor kernels
%
%*****************************************************************


exports difftaylorwrttayvar$

imports

% from the REDUCE kernel:
        !*f2q, !*k2q, diffsq, ldepends, multsq, nth, to,

% from module Taylor!:intro:
        replace!-nth, replace!-nth!-nth, var!-is!-nth,

% from module Taylor!:macros:
        make!-cst!-coefflis, make!-taylor!*, taycfpl, taycfsq,
        taycoefflist, tayflags, taylor!*p, taymakecoeff, tayorig,
        taytemplate, taytpelorder, taytpelpoint, taytpelvars, tayvars,

% from module Taylor!:basic:
        multtaylor,

% from module Taylor!:simp:
        taysimpp$


fluid '(!*taylorkeeporiginal)$

put ('taylor!*, 'dfform, 'taydiffp);

symbolic procedure taydiffp (u, v, n);
  %
  % differentiates u**n w.r.t. v, u is a Taylor kernel
  % value is a standard quotient
  %
  !*k2q if n=1 then difftaylor (u, v)
         else multtaylor (taysimpp (u to (n-1)), difftaylor (u, v))$

symbolic procedure difftaylor (u, kernel);
  if not ldepends(tayvars u, kernel)
    then make!-taylor!* (
                 for each cc in taycoefflist u collect
                   taymakecoeff (taycfpl cc,
                                 diffsq (taycfsq cc, kernel)),
                 taytemplate u,
                 if !*taylorkeeporiginal and tayorig u
                   then diffsq (tayorig u, kernel)
                  else nil,
                 tayflags u)
   else difftaylorwrttayvar (u, kernel)$

symbolic procedure difftaylorwrttayvar (u, kernel);
  %
  % kernel is one of the Taylor variables
  % differentiates Taylor kernel u wrt kernel
  %
  begin scalar v, w, w1; integer n, m;
    v := taytemplate u;
    w := var!-is!-nth (v, kernel);
    n := car w;
    m := cdr w;
    w := for each x in taycoefflist u join <<
           w := nth (taycfpl x, n);
           w1 := nth (w, m);
           if w1 = 0 then nil
            else list
              if taytpelpoint nth (v, n) eq 'infinity
                then taymakecoeff (
                        replace!-nth!-nth (taycfpl x, n, m, w1 + 1),
                        multsq (taycfsq x, !*f2q (- w1)))
               else taymakecoeff (
                        replace!-nth!-nth (taycfpl x, n, m, w1 - 1),
                        multsq (taycfsq x, !*f2q w1)) >>;
    return
      make!-taylor!* (
            if null w
              then make!-cst!-coefflis (nil ./ 1, v)
             else w,
            replace!-nth (v, n,
                          (list (taytpelvars w1,
                                 taytpelpoint w1,
                                 if taytpelpoint nth (v, n) eq 'infinity
                                   then taytpelorder w1 + 1
                                  else taytpelorder w1 - 1)
                              where w1 := nth (v, n))),
            if !*taylorkeeporiginal and tayorig u
              then diffsq (tayorig u, kernel)
             else nil,
            tayflags u)
  end$

endmodule;


module tayconv;

%*****************************************************************
%
%     Functions converting Taylor kernels to prefix forms
%
%*****************************************************************


exports preptaylor!*!*, preptaylor!*, preptaylor!*1,
        taylor!-gen!-big!-o$

imports

% from the REDUCE kernel:
        lastpair, prepsq!*, replus, retimes, reval,

% from module Taylor!:macros:
        taycfpl, taycfsq, taycoefflist, taytemplate, taytpelorder,
        taytpelpoint, taytpelvars$


fluid '(convert!-taylor!*)$


symbolic procedure preptaylor!*1 (coefflist, template);
  replus for each cc in coefflist join preptaylor!*2 (cc, template)$

symbolic procedure preptaylor!*2 (coeff, template);
  (lambda (pc);
     if pc = 0 then nil
      else list retimes (pc . preptaycoeff (taycfpl coeff, template)))
    (prepsq!* taycfsq coeff)$

symbolic procedure checkdifference (var, var0);
  if var0 = 0 then var else list ('difference, var, var0)$

symbolic procedure checkexp (bas, exp);
  if exp = 0 then 1
   else if exp = 1 then bas
   else list ('expt, bas, exp)$

symbolic smacro procedure checkpower (var, var0, n);
  if var0 eq 'infinity
    then if n = 0 then 1
          else list ('quotient, 1, checkexp (var, n))
   else checkexp (checkdifference (var, reval var0), n)$

symbolic procedure preptaycoeff (cc, template);
  begin scalar result;
    while not null template do begin scalar ccl;
      ccl := car cc;
      for each var in taytpelvars car template do <<
        result := checkpower (var, taytpelpoint car template, car ccl)
                    . result;
        ccl := cdr ccl >>;
      cc := cdr cc;
      template := cdr template
    end;
    return result
  end$

put ('taylor!*, 'prepfn2, 'preptaylor!*!*);

symbolic procedure preptaylor!*!* u;
   if null convert!-taylor!* then u else preptaylor!* u;

symbolic procedure preptaylor!* u;
   preptaylor!*1 (taycoefflist u, taytemplate u)$

symbolic procedure taylor!-gen!-big!-o tp;
  %
  % Generates a big-O notation for the Taylor template tp
  %
  'o . for each el in tp collect
          if null cdr taytpelvars el
            then checkpower (car taytpelvars el, taytpelpoint el,
                             taytpelorder el + 1)
           else begin scalar var0; integer n;
             var0 := reval taytpelpoint el;
             n := taytpelorder el + 1;
             return
               if var0 eq 'infinity
                 then list ('quotient, 1,
                            checkexp ('list . taytpelvars el, n))
                else checkexp (
                 'list .
                   for each krnl in taytpelvars el collect
                     checkdifference (krnl, var0),
                 n)
           end$

endmodule;


module tayprint$

%*****************************************************************
%
%     Functions for printing Taylor kernels
%
%*****************************************************************


exports taylor!*print$

imports

% from the REDUCE kernel:
        aconc, eqcar, fmprint, maprin, prin2!*,

% from module Taylor!:macros:
        taytemplate,

% from module Taylor!:convert:
        preptaylor!*, taylor!-gen!-big!-o$


fluid '(!*fort !*nat !*taylorprintorder)$

symbolic procedure taylor!*print (u, p);
   (if !*fort then fmprint (prepexpr, 0)
      else maprint (if null !*nat then prepexpr
                     else if not eqcar (prepexpr, 'plus)
                      then list ('plus, prepexpr or 0, dots)
                     else aconc (prepexpr, dots),
                    p))
       where
         prepexpr := preptaylor!* u,
         dots := if !*taylorprintorder
                   then taylor!-gen!-big!-o taytemplate u
                  else '!.!.!.$
 
put ('taylor!*, 'pprifn, 'taylor!*print)$

endmodule;


module tayfrontend;

%*****************************************************************
%
%          User interface
%
%*****************************************************************


exports taylorcombine, taylororiginal, taylorseriesp, taylortemplate,
        taylortostandard$

imports

% from the REDUCE kernel:
        eqcar, mk!*sq, mvar, numr, prepsq, simp!*, typerr,

% from module Taylor!:intro:
        taylor!-error,

% from module Taylor!:macros:
        taylor!-kernel!-sq!-p, tayorig, taytemplate,

% from module Taylor!:simp:
        taysimpsq$


symbolic procedure taylorseriesp u;
  (taylor!-kernel!-sq!-p sq)
      where sq := simp!* u$

symbolic procedure taylorcombine u;
  mk!*sq taysimpsq simp!* u$

symbolic procedure taylortostandard u;
  (prepsq if not eqcar (u, '!*sq) then simp!* u else cadr u)
          where convert!-taylor!* := t$

symbolic procedure taylororiginal u;
  (if not taylor!-kernel!-sq!-p sq
     then typerr (u, "Taylor kernel")
    else (if tayorig tay then mk!*sq tayorig tay
        else taylor!-error ('no!-original, 'taylororiginal))
           where tay := mvar numr sq)
     where sq := simp!* u$

symbolic procedure taylortemplate u;
  (if not taylor!-kernel!-sq!-p sq
     then typerr (u, "Taylor kernel")
    else 'list . for each triple in taytemplate mvar numr sq collect
              'list . ((if null cdr car triple then car car triple
                         else 'list . car triple)
                     . cdr triple))
     where sq := simp!* u$

flag ('(taylorseriesp taylorcombine taylortostandard taylororiginal
        taylortemplate),
      'opfn)$

flag ('(taylorseriesp), 'boolean)$

endmodule;


module tayfns;

%*****************************************************************
%
%       Simplification functions for special functions
%
%*****************************************************************


exports taysimpexpt, taysimpatan, taysimplog, taysimpexp,
        taysimptan, taysimpsin, taysimpasin$

imports

% from the REDUCE kernel:
        !*k2q, addsq, denr, evenp, kernp, mk!*sq, multsq, mvar, negsq,
        nth, numr, over, prepsq, quotsq, reversip, simp, simp!*,
        subtrsq,

% from the module Taylor!:intro:
        confusion, nzerolist, smemberlp, taylor!-error, var!-is!-nth,

% from the module Taylor!:macros:
        cst!-taylor!*, find!-non!-zero, get!-degree,
        make!-cst!-coefflis, make!-cst!-powerlist, make!-taylor!*,
        set!-tayflags, set!-tayorig, taycfpl, taycfsq, taycoefflist,
        tayflags, taygetcoeff, taylor!*p, taylor!-kernel!-sq!-p,
        taymakecoeff, tayorig, taytemplate, taytpelorder, taytpelpoint,
        taytpelvars, tayvars,

% from the module Taylor!:utils:
        replace!-nth, replace!-nth!-nth,

% from the module Taylor!:basic:
        addtaylor, addtaylor1, invtaylor, makecoeffs, makecoeffpairs,
        makecoeffpairs1, multtaylor, multtaylor1, multtaylorsq,
        negtaylor, negtaylor1, quottaylor,

% from the module Taylor!:simp:
        expttayrat, taysimpsq,

% from the module Taylor!:diff:
        difftaylorwrttayvar$


fluid '(!*taylorkeeporiginal)$

symbolic procedure taysimpexpt u;
  %
  % Argument is of the form ('expt base exponent)
  % where both base and exponent (but a least one of them)
  % may contain Taylor kernels given as prefix forms.
  % Value is the equivalent Taylor kernel.
  %
  if cadr u eq 'e then taysimpexp list ('exp, caddr u)
   else begin scalar bas, expn;
     bas := taysimpsq simp!* cadr u;
     expn := taysimpsq simp!* caddr u;
     if null kernp bas
       then return !*k2q list ('expt, prepsq bas, prepsq expn);
     if fixp numr expn and fixp denr expn
       then return !*k2q expttayrat (mvar numr bas, expn);
     if denr expn = 1 and eqcar (numr expn, '!:rn!:)
       then return !*k2q expttayrat (mvar numr bas, cdr numr expn);
     if null kernp expn
       then return !*k2q list ('expt, prepsq bas, prepsq expn);
     bas := mvar numr bas;
     expn := mvar numr expn;
     return if taylor!*p bas
       then if taylor!*p expn
         then if taytemplate bas = taytemplate expn
                then taysimpexp multtaylor (expn, taysimplog bas)
               else !*k2q list ('expt, bas, expn)
        else if not smemberlp (tayvars bas, expn)
               then taysimpexp multtaylorsq(taysimplog bas, expn)
              else !*k2q list ('expt, bas, expn)
      else if taylor!*p expn and not smemberlp (tayvars expn, bas)
       then !*k2q multtaylorsq (expn, simp!* list ('log, bas))
      else !*k2q list ('expt, bas, expn);
  end$

put ('expt, 'taylorsimpfn, 'taysimpexpt)$


symbolic procedure taycoefflist!-union u;
  if null cdr u then car u
   else taycoefflist!-union2 (car u, taycoefflist!-union cdr u)$

symbolic procedure taycoefflist!-union2 (x, y);
  %
  % returns union of TayCoeffLists x and y
  %
  << for each w in y do
       if null (assoc (car w, x)) then x := w . x;
     x >>$

symbolic procedure inttaylorwrttayvar (tay, var);
  %
  % integrates Taylor kernel tay wrt variable var
  %
  inttaylorwrttayvar1 (taycoefflist tay, taytemplate tay, var)$

symbolic procedure inttaylorwrttayvar1 (tcl, tp, var);
  %
  % integrates Taylor kernel with TayCoeffList tcl and template tp
  %  wrt variable var
  %
  begin scalar tt, u, w; integer n, n1, m;
    u := var!-is!-nth (tp, var);
    n := car u;
    n1 := cdr u;
    tt := nth (tp, n);
    u := for each cc in tcl collect <<
           m := nth (nth (taycfpl cc, n), n1);
           if taytpelpoint nth (tp, n) eq 'infinity
             then <<
               if m = 1 then taylor!-error ('inttaylorwrttayvar, nil);
               taymakecoeff (replace!-nth!-nth (taycfpl cc, n, n1, m-1),
                             multsq (taycfsq cc,
                                     invsq ((-m + 1) ./ 1))) >>
            else <<
               if m = -1 then taylor!-error ('inttaylorwrttayvar, nil);
               taymakecoeff (replace!-nth!-nth (taycfpl cc, n, n1, m+1),
                             multsq (taycfsq cc,
                                     invsq ((m + 1) ./ 1))) >> >>;
    w := list (taytpelvars tt, taytpelpoint tt,
               if null car taytpelvars tt
                 then if taytpelpoint tt eq 'infinity
                        then taytpelorder tt - 1
                       else taytpelorder tt + 1
                else taytpelorder tt);
    return make!-taylor!* (u, replace!-nth (tp, n, w), nil, nil)
%
% The following is not needed yet
%
%     return make!-Taylor!* (
%              u,
%              replace!-nth (TayTemplate tay, n, w),
%              if !*taylorkeeporiginal and TayOrig tay
%                then simp list ('int, mk!*sq TayOrig tay, var)
%               else nil,
%              TayFlags u)
  end$


Comment The inverse trigonometric and inverse hyperbolic functions
        of a Taylor kernel are calculated by first computing the
        derivative(s) with respect to the Taylor variable(s) and
        integrating the result.  The derivatives can easily be
        calculated by the manipulation functions defined above.

        The method is best illustrated with an example.  Let T(x)
        be a Taylor kernel depending on one variable x.  To compute
        the inverse tangent T1(x) = atan(T(x)) we calculate the
        derivative

                                T'(x)
                    T1'(x) = ----------- .
                                      2
                              1 + T(x)

        (If T and T1 depend on more than one variable replace
        the derivatives by gradients.)
        This is integrated again with the integration constant
        T1(x0) = atan(T(x0)) yielding the desired result.
        If there is more than variable we have to find the
        potential function T1(x1,...,xn) corresponding to
        the vector grad T1(x1,...,xn) which is always possible
        by construction.

        The prescriptions for the eight functions asin, acos, asec,
        acsc, asinh, acosh, asech, and acsch can be put together
        in one procedure since the expressions for their derivatives
        differ only in certain signs.  The same remark applies to
        the four functions atan, acot, atanh, and acoth.

        These expressions are:

         d                 1
         -- asin x = ------------- ,
         dx           sqrt(1-x^2)

         d                -1
         -- acos x = ------------- ,
         dx           sqrt(1-x^2)

         d                 1
         -- asinh x = ------------- ,
         dx            sqrt(1+x^2)

         d                 1
         -- acosh x = ------------- ,
         dx            sqrt(x^2-1)

         d               1
         -- atan x = --------- ,
         dx           1 + x^2

         d               -1
         -- acot x = --------- ,
         dx           1 + x^2

         d                1
         -- atanh x = --------- ,
         dx            1 - x^2

         d                1
         -- acoth x = --------- ,
         dx            1 - x^2

        together with the relations

                       1
         asec x = acos - ,
                       x

                       1
         acsc x = asin - ,
                       x

                         1
         asech x = acosh - ,
                         x

                         1
         acsch x = asinh -
                         x ;


symbolic procedure taysimpasin u;
  if not (car u memq '(asin acos acsc asec asinh acosh acsch asech))
     or cddr u
    then confusion 'taysimpasin
   else begin scalar l, l0, c0, v, tay, tay2, tp;
     tay := taysimpsq simp!* cadr u;
     if not taylor!-kernel!-sq!-p tay
       then return !*k2q list (car u, mk!*sq tay);
     tay := mvar numr tay; % asin's argument
     if car u memq '(asec acsc asech acsch) then tay := invtaylor tay;
     tp := taytemplate tay;
     l0 := make!-cst!-powerlist tp;
     c0 := car taycoefflist tay;
     for each el in taycfpl c0 do
       if get!-degree el < 0
         then taylor!-error ('essential!-singularity, car u);
     tay2 := multtaylor (tay, tay);
     if car u memq '(asin acos acsc asec)
       then tay2 := negtaylor tay2;
     tay2 := addtaylor (
               cst!-taylor!* (
                 !*f2q (if car u memq '(acosh asech) then -1 else 1),
                 tp),
               tay2);
     if null numr taygetcoeff (l0, taycoefflist tay2)
       then taylor!-error ('essential!-singularity, car u);
     tay2 := invtaylor expttayrat (tay2, 1 ./ 2);
     if car u eq '(acos asec) then tay2 := negtaylor tay2;
     l := for each krnl in tayvars tay collect
            taycoefflist inttaylorwrttayvar (
              multtaylor (difftaylorwrttayvar (tay, krnl), tay2),
              krnl);
     v := taycoefflist!-union l;
     %
     % special treatment for zeroth coefficient
     %
     c0 := simp list (car u,
                      mk!*sq taygetcoeff (l0, taycoefflist tay));
     v := taymakecoeff (l0, c0) . v;
     return !*k2q make!-taylor!* (v, tp,
                if !*taylorkeeporiginal and tayorig tay
                  then simp list (car u, mk!*sq tayorig tay)
                 else nil,
                tayflags tay)
  end$

put('asin, 'taylorsimpfn, 'taysimpasin)$
put('acos, 'taylorsimpfn, 'taysimpasin)$
put('asec, 'taylorsimpfn, 'taysimpasin)$
put('acsc, 'taylorsimpfn, 'taysimpasin)$
put('asinh, 'taylorsimpfn, 'taysimpasin)$
put('acosh, 'taylorsimpfn, 'taysimpasin)$
put('asech, 'taylorsimpfn, 'taysimpasin)$
put('acsch, 'taylorsimpfn, 'taysimpasin)$


symbolic procedure taysimpatan u;
  if not (car u memq '(atan acot atanh acoth)) or cddr u
    then confusion 'taysimpatan
   else begin scalar l, l0, c0, v, tay, tay2, tp;
     tay := taysimpsq simp!* cadr u;
     if not taylor!-kernel!-sq!-p tay
       then return !*k2q list (car u, mk!*sq tay);
     tay := mvar numr tay; % atan's argument
     tp := taytemplate tay;
     l0 := make!-cst!-powerlist tp;
     c0 := car taycoefflist tay;
     for each el in taycfpl c0 do
       if get!-degree el < 0
         then taylor!-error ('branch!-cut, car u);
     tay2 := multtaylor (tay, tay);
     if car u memq '(atanh acoth) then tay2 := negtaylor tay2;
     tay2 := addtaylor (cst!-taylor!* (1 ./ 1, tp), tay2);
     if null numr taygetcoeff (l0, taycoefflist tay2)
       then taylor!-error ('essential!-singularity, car u);
     tay2 := invtaylor tay2;
     if car u eq 'acot then tay2 := negtaylor tay2;
     l := for each krnl in tayvars tay collect
            taycoefflist inttaylorwrttayvar (
              multtaylor (difftaylorwrttayvar (tay, krnl), tay2),
              krnl);
     v := taycoefflist!-union l;
     %
     % special treatment for zeroth coefficient
     %
     c0 := simp list (car u,
                      mk!*sq taygetcoeff (l0, taycoefflist tay));
     v := taymakecoeff (l0, c0) . v;
     return !*k2q make!-taylor!* (v, tp,
                if !*taylorkeeporiginal and tayorig tay
                  then simp list (car u, mk!*sq tayorig tay)
                 else nil,
                tayflags tay)
  end$

put('atan, 'taylorsimpfn, 'taysimpatan)$
put('acot, 'taylorsimpfn, 'taysimpatan)$
put('atanh, 'taylorsimpfn, 'taysimpatan)$
put('acoth, 'taylorsimpfn, 'taysimpatan)$


Comment For the logarithm and exponential we use the extension of
        an algorithm quoted by Knuth who shows how to do this for
        series in one expansion variable.

        We extended this to the case of several variables which is
        straightforward except for one point, see below.
        Knuth's algorithm works as follows: Assume you want to compute
        the series W(x) where

            W(x) = log V(x)

        Differentiation of this equation gives

                    V'(x)
            W'(x) = ----- ,   or V'(x) = W'(x)V(x) .
                     V(x)

        You make now the ansatz

                    -----
                    \           n
            W(x) =   >      W  x  ,
                    /        n
                    -----

        substitute this into the above equation and compare
        powers of x.  This yields the recursion formula

                               n-1
                 V            -----
                  n       1   \
           W  = ---- - ------  >    m W  V     .
            n    V      n V   /        m  n-m
                  0        0  -----
                               m=0

        The first coefficient must be calculated directly, it is

           W   = log V  .
            0         0

        To use this for series in more than one variable you have to
        calculate all partial derivatives: n and m refer then to the
        corresponding component of the multi index.  Looking closely
        one finds that there is an ambiguity: the same coefficient
        can be calculated using any of the partial derivatives.  The
        only restriction is that the corresponding component of the
        multi index must not be zero, since we have to divide by it.

        We resolve this ambiguity by simply taking the first nonzero
        component.

        The case of the exponential is nearly the same: differentiation
        gives

            W'(x) = V'(x) W(x) ,

        from which we derive the recursion formula

                   n-1
                  -----
                  \     n-m
            W  =   >    --- W  V     , W  = exp V  .
             n    /      m   m  n-m     0        0
                  -----
                   m=0

        ;


symbolic procedure taysimplog u;
  %
  % Special Taylor expansion function for logarithms
  %
  if not (car u eq 'log) or cddr u then confusion 'taysimplog
   else begin scalar a0, clist, coefflis, l0, l, tay, tp;
            u := taysimpsq simp!* cadr u;
    if not taylor!-kernel!-sq!-p u
      then return !*k2q list ('log, mk!*sq u);
    tay := mvar numr u;
    tp := taytemplate tay;
    l0 := make!-cst!-powerlist tp;
    %
    % The following relies on the standard ordering of the
    % TayCoeffList.
    %
    l := taycoefflist tay;
    for each el in taycfpl car l do
      if get!-degree el < 0
        then taylor!-error ('essential!-singularity, 'logarithm);
    a0 := taygetcoeff (l0, l);
    if null numr a0 then taylor!-error ('not!-a!-unit, 'logarithm);
    clist := list taymakecoeff (l0, simp!* list ('log, mk!*sq a0));
    coefflis := makecoeffs for each term in tp collect
               (nzerolist length taytpelvars term . taytpelorder term);
    for each cc in cdr coefflis do
      begin scalar s, pos, pp; integer n, n1;
        s := nil ./ 1;
        pos := find!-non!-zero cc;
        n := nth (nth (cc, car pos), cdr pos);
        pp := makecoeffpairs (pair (l0, cc), taycfpl car l);
        for each p in pp do <<
          n1 := nth (nth (car p, car pos), cdr pos);
          s := addsq (s,
                      multsq (!*f2q !*n2f n1,
                              multsq (taygetcoeff (car p, clist),
                                      taygetcoeff (cdr p, l))))>>;
        clist :=
          taymakecoeff (cc,
                        quotsq (subtrsq (taygetcoeff (cc, l),
                                         multsq (s, invsq (n ./ 1))),
                                a0))
                  . clist
      end;
    return !*k2q make!-taylor!* (
      reversip clist,
      tp,
      if !*taylorkeeporiginal and tayorig tay
        then simp list ('log, mk!*sq tayorig tay)
       else nil,
      tayflags tay)
  end$

put('log, 'taylorsimpfn, 'taysimplog)$


symbolic procedure taysimpexp u;
  %
  % Special Taylor expansion function for exponentials
  %
  if not (car u eq 'exp) or cddr u then confusion 'taysimpexp
   else begin scalar a0, clist, coefflis, l0, l, tay, tp;
    u := taysimpsq simp!* cadr u;
    if not taylor!-kernel!-sq!-p u
      then return !*k2q list ('log, mk!*sq u);
    tay := mvar numr u;
    tp := taytemplate tay;
    l0 := make!-cst!-powerlist tp;
    %
    % The following relies on the standard ordering of the
    % TayCoeffList.
    %
    l := taycoefflist tay;
    for each el in taycfpl car l do
      if get!-degree el < 0
        then taylor!-error ('essential!-singularity, 'exp);
    a0 := taygetcoeff (l0, l);
    clist := list taymakecoeff (l0, simp!* list ('exp, mk!*sq a0));
    coefflis := makecoeffs for each term in tp collect
               (nzerolist length taytpelvars term . taytpelorder term);
    for each cc in cdr coefflis do
      begin scalar s, pos, pp; integer n, n1;
        s := nil ./ 1;
        pos := find!-non!-zero cc;
        n := nth (nth (cc, car pos), cdr pos);
        pp := makecoeffpairs (pair (l0, cc), taycfpl car l);
        for each p in pp do <<
          n1 := nth (nth (car p, car pos), cdr pos);
          s := addsq (s,
                      multsq (!*f2q !*n2f (n - n1),
                              multsq (taygetcoeff (car p, clist),
                                      taygetcoeff (cdr p, l))))>>;
        clist := taymakecoeff (cc, multsq (s, invsq (n ./ 1))) . clist
      end;
    return !*k2q make!-taylor!* (
      reversip clist,
      tp,
      if !*taylorkeeporiginal and tayorig tay
        then simp list ('exp, mk!*sq tayorig tay)
       else nil,
      tayflags tay)
  end$

put('exp, 'taylorsimpfn, 'taysimpexp)$


Comment The algorithm for the trigonometric functions is also
        derived from their differential equation.
        The simplest case is that of tangent whose equation is

                            2
           tan'(x) = 1 + tan (x) .          (*)

        For the others we have

                               2
           cot'(x) = - (1 + cot (x)),

                              2
           tanh'(x) = 1 - tanh (x),

                               2
           coth'(x) = -1 + coth (x) .



        Let T(x) be a Taylor series,

                  -----
                  \         N
           T(x) =  >    a  x
                  /      N
                  -----
                   N=0

        Now, let

                              -----
                              \         N
           T1(x) = tan T(x) =  >    b  x
                              /      N
                              -----
                               N=0

        from which we immediately deduce that b  = tan a .
                                               0        0

        From (*) we get
                              2
           T1'(x) = (1 + T1(x) ) T'(x) ,

        or, written in terms of the series:

        Inserting this into (*) we get

          -----              /     /  -----       \ 2 \  -----
          \           N-1    |     |  \         N |   |  \           L
           >    N b  x    =  | 1 + |   >    b  x  |   |   >    L a  x
          /        N         |     |  /      N    |   |  /        L
          -----              \     \  -----       /   /  -----
           N=1                         N=0                L=1

        We perform the square on the r.h.s. using Cauchy's rule
        and obtain:


           -----
           \           N-1
            >    N b  x    =
           /        N
           -----
            N=1

                              N
               /     -----  -----            \  -----
               |     \      \              N |  \           L
               | 1 +  >      >    b    b  x  |   >    L a  x  .
               |     /      /      N-M  M    |  /        L
               \     -----  -----            /  -----
                      N=0    M=0                 L=1

        Expanding this once again with Cauchy's product rule we get

           -----
           \           N-1
            >    N b  x    =
           /        N
           -----
            N=1

                                L-1     N
           -----      /        -----  -----                    \
           \      L-1 |        \      \                        |
            >    x    | L a  +  >      >    b    b  (L-N) a    | .
           /          |    L   /      /      N-M  M        L-N |
           -----      \        -----  -----                    /
            L=1                 N=0    M=0

        From this we immediately deduce the recursion relation

                      L-1                 N
                     -----              -----
                     \       L-N        \
           b  = a  +  >     ----- a      >    b    b  .  (**)
            L    L   /        L    L-N  /      N-M  M
                     -----              -----
                      N=0                M=0

        This relation is easily generalized to the case of a
        series in more than one variable, where the same comments
        apply as in the case of log and exp above.

        For the hyperbolic tangent the relation is nearly the same.
        Since its differential equation has a `-' where that of
        tangent has a `+' we simply have to do the same substitution
        in the relation (**).  For the cotangent we get an additional
        overall minus sign.

        ;


symbolic procedure taysimptan u;
  %
  % Special Taylor expansion function for circular and hyperbolic
  %  tangent and cotangent
  %
  if not (car u memq '(tan cot tanh coth)) or cddr u
    then confusion 'taysimptan
   else begin scalar a0, clist, coefflis, l0, l, tay, tp;
    tay := taysimpsq simp!* cadr u;
    if not taylor!-kernel!-sq!-p tay
      then return !*k2q list (car u, mk!*sq tay);
    tay := mvar numr tay;
    tp := taytemplate tay;
    l0 := make!-cst!-powerlist tp;
    %
    % The following relies on the standard ordering of the
    % TayCoeffList.
    %
    l := taycoefflist tay;
    for each el in taycfpl car l do
      if get!-degree el < 0
        then taylor!-error ('essential!-singularity, car u);
    a0 := taygetcoeff (l0, l);
    clist := list taymakecoeff (l0, simp!* list (car u, mk!*sq a0));
    coefflis := makecoeffs for each term in tp collect
               (nzerolist length taytpelvars term . taytpelorder term);
    for each cc in cdr coefflis do
      begin scalar cf, s, pos, pp, x, y; integer n, n1;
        s := nil ./ 1;
        pos := find!-non!-zero cc;
        n := nth (nth (cc, car pos), cdr pos);
        pp := makecoeffpairs (pair (l0, cc), l0);
        for each p in pp do <<
          x := reversip makecoeffpairs1 (pair (l0, car p), l0);
          y := nil ./ 1;
          for each z in x do
            y := addsq (y, multsq (taygetcoeff (car z, clist),
                                   taygetcoeff (cdr z, clist)));
          n1 := nth (nth (car p, car pos), cdr pos);
          s := addsq (s,
                      multsq (!*f2q !*n2f (n - n1),
                              multsq (y, taygetcoeff (cdr p, l))))>>;
        cf := multsq (s, invsq (n ./ 1));
        if car u memq '(tanh coth) then cf := negsq cf;
        cf := addsq (taygetcoeff (cc, l), cf);
        if car u memq '(cot coth) then cf := negsq cf;
        clist := taymakecoeff (cc, cf) . clist
      end;
    return !*k2q make!-taylor!* (
      reversip clist,
      tp,
      if !*taylorkeeporiginal and tayorig tay
        then simp list (car u, mk!*sq tayorig tay)
       else nil,
      tayflags tay)
  end$

put('tan, 'taylorsimpfn, 'taysimptan)$
put('cot, 'taylorsimpfn, 'taysimptan)$
put('tanh, 'taylorsimpfn, 'taysimptan)$
put('coth, 'taylorsimpfn, 'taysimptan)$


Comment For the sine, cosine (circular and hyperbolic) and their
        reciprocals we calculate the tangent and use the formulas

                            1
           cos x = ------------------- ,
                                   2
                    sqrt(1 + tan(x) )


                          tan x
           sin x = ------------------- ,
                                   2
                    sqrt(1 + tan(x) )


        etc.  This is not the most elegant way, but it's simpler
        to implement.

        ;


symbolic procedure taysimpsin u;
  %
  % Special Taylor expansion function for circular and hyperbolic
  %  sine, cosine and their reciprocals
  %
  if not (car u memq '(sin cos sec cosec sinh cosh sech cosech))
     or cddr u
    then confusion 'taysimpsin
   else begin scalar l, tay, tay2, tp;
    tay := taysimpsq simp!* cadr u;
    if not taylor!-kernel!-sq!-p tay
      then return !*k2q list (car u, mk!*sq tay);
    tay := mvar numr tay;
    tp := taytemplate tay;
    for each el in taycfpl car l do
      if get!-degree el < 0
        then taylor!-error ('essential!-singularity, car u);
    if car u memq '(sin cos sec cosec)
      then tay := taysimptan list ('tan, tay)
     else tay := taysimptan list ('tanh, tay);
    l := taycoefflist tay;
    l := multtaylor1 (tp, l, l);
    if car u memq '(sinh cosh sech cosech) then l := negtaylor1 l;
    tay2 := addtaylor1 (make!-cst!-coefflis (1 ./ 1, tp), l);
    %
    % check if you can calculate the root
    %
    for each ll in taycfpl car tay2 do
       for each p in ll do
         if not evenp p
           then taylor!-error ('branch!-point, 'taysimpsin);
    %
    % build the Taylor kernel for expttayrat
    %
    tay2 := make!-taylor!* (tay2, tp, nil, nil);
    tay2 := expttayrat (tay2, 1 ./ 2);
    if car u memq '(cos cosh)
      then tay2 := invtaylor tay2
     else if car u memq '(sin sinh)
      then tay2 := quottaylor (tay, tay2)
     else if car u memq '(cosec cosech)
      then tay2 := quottaylor (tay2, tay);
    set!-tayorig (tay2,
                  if !*taylorkeeporiginal and tayorig tay
                    then simp list (car u, mk!*sq tayorig tay));
    set!-tayflags (tay2, tayflags tay);
    return tay2
  end$

put('sin,    'taylorsimpfn, 'taysimpsin)$
put('cos,    'taylorsimpfn, 'taysimpsin)$
put('sec,    'taylorsimpfn, 'taysimpsin)$
put('cosec,  'taylorsimpfn, 'taysimpsin)$
put('sinh,   'taylorsimpfn, 'taysimpsin)$
put('cosh,   'taylorsimpfn, 'taysimpsin)$
put('sech,   'taylorsimpfn, 'taysimpsin)$
put('cosech, 'taylorsimpfn, 'taysimpsin)$

endmodule;


end;
