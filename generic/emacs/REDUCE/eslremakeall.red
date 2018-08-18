%%% eslremakeall.red --- remake all ESL REDUCE fasl files.

%%% Author: Francis J. Wright.
%%% Based on code by Anthony C. Hearn.

%% Assume REDUCE has been started or a bootstrapping version has been
%% built in main memory, e.g. by evaluating (DSKIN "dbuild.el").

%% Then run this file, e.g. by executing
%% lisp infile "eslremakeall.red";

%% (/util/remake) Now build compiled versions of any updated source files.

symbolic;

or(!\file!-exists!-p "log", !\make!-directory "log"); % Elisp

wrs open("log/remake.log", 'output);

or(!\file!-exists!-p "fasl", !\make!-directory "fasl"); % Elisp

%% (/util/remake2) Compile key packages:

!*argnochk := t;

infile "eslremake.red";	% defines package!-remake and package!-remake2
package!-remake2('eslremake, nil);  load!-package 'eslremake;

%% Build other special support packages:

package!-remake2('eslprolo, nil);

package!-remake2('eslrend, nil);

% BEWARE: The entry module may not work correctly due to use of getd
% and putd with compiled functions:
package!-remake2('entry, 'support);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Now build all other packages in the "packages" directory

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Add folder property to module identifiers for use by package!-remake:
infile "package.red";

foreach x in '( rlisp poly alg arith mathpr ) do <<
   close wrs open(concat("log/", string!-downcase x, ".blg"), 'output);
   package!-remake x; load!-package x;
   >>;

foreach x in '( polydiv ezgcd factor hephys int matrix rlisp88 rprint fmprint pretty solve desir ineq modsr rsolve algint arnum assist dummy cantens atensor avector invbase misc boolean cedit rcref ftr reset cali camal changevr compact dfpart lie tmprint ) do <<
   close wrs open(concat("log/", string!-downcase x, ".blg"), 'output);
   package!-remake x;
   >>;


close wrs nil;
;end;


upackages2 := '( odesolve pf cvit noncom2 physop crack liepde applysym conlaw excalc gentran fide1 fide numeric randpoly reacteqn roots rlfi roots2 sets xideal eds dipoly groebner groebnr2 ideals linalg ncpoly normform orthovec plot gnuplot laplace pm qsum scope sparse spde specfn );

foreach x in upackages2 do <<
   close wrs open(concat("log/", string!-downcase x, ".blg"), 'output);
   package!-remake x;
   >>;

upackages3 := '( specfn2 specfaux specbess sfgamma tps limits defint fps trigint ratint mathml mathmlom redlog rltools cl cgb ofsf dvfsf acfsf sum zeilberg symaux symmetry taylor mrvlimit residue susy2 tri trigsimp xcolor wu ztrans geoprover rataprx rtrace );

foreach x in upackages3 do <<
   close wrs open(concat("log/", string!-downcase x, ".blg"), 'output);
   package!-remake x;
   >>;

close wrs nil;
;end;
