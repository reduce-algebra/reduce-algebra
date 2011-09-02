
% These are packages that get built into the base system that is used
% to compile what follows...

(support rlisp alg poly polydiv arith mathpr ezgcd factor hephys
 int matrix rlisp88 rprint fmprint pretty solve desir ineq modsr
 rsolve algint arnum assist dummy cantens atensor avector invbase
 misc boolean cedit rcref ftr reset cali camal changevr compact
 dfpart lie)

% The next set of modules are all built using a system that has the
% above set available. The key issue here is that the packages in
% this list of "extensions" can all be built independently of each
% other.

(odesolve pf cvit noncom2 physop crack liepde applysym conlaw excalc
 gentran fide1 fide numeric randpoly reacteqn roots rlfi roots2 sets
 xideal eds dipoly groebner groebnr2 ideals linalg ncpoly normform
 orthovec plot gnuplot laplace pm qsum scope sparse spde specfn specfn2
 specfaux specbess sfgamma tps limits defint fps trigint ratint mathml
 mathmlom rltools redlog cl cgb ofsf dvfsf acfsf sum zeilberg symaux
 symmetry taylor mrvlimit residue susy2 tri trigsimp xcolor wu ztrans
 geoprover rataprx rtrace tmprint)

% Finally we have a list of all the test scripts that REDUCE is shipped
% with.

(alg poly polydiv arith factor int matrix solve desir ineq modsr rsolve
 algint arnum assist dummy cantens atensor avector invbase boolean cali
 camal changevr compact dfpart lie odesolve pf cvit physop crack liepde
 applysym conlaw excalc gentran fide numeric randpoly reacteqn roots
 rlfi sets xideal eds groebner ideals linalg ncpoly normform orthovec
 laplace pm qsum scope sparse spde specfn tps limits defint fps trigint
 ratint mathml mathmlom redlog cgb sum zeilberg symmetry taylor mrvlimit
 residue susy2 tri trigsimp xcolor wu ztrans geoprover rataprx)

% End of configuration file
