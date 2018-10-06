%%% eslremakecore.red --- remake core ESL REDUCE fasl files.

%%% Author: Francis J. Wright.
%%% Based on code by Anthony C. Hearn.

%% Assume REDUCE has been started or a bootstrapping version has been
%% built in main memory, e.g. by evaluating (DSKIN "dbuild.el").

%% Then run this file, e.g. by executing
%% lisp infile "eslremakecore.red";

%% (/util/remake) Now build compiled versions of any updated source files.

symbolic;

or(!file!-exists!-p "log", !make!-directory "log"); % Elisp

wrs open("log/eslremakecore.log", 'output);

or(!file!-exists!-p "fasl", !make!-directory "fasl"); % Elisp

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

%% Now build the core packages in the "packages" directory

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Add folder property to module identifiers for use by package!-remake:
infile "package.red";

foreach x in '( rlisp poly alg arith mathpr ) do <<
   close wrs open(concat("log/", string!-downcase x, ".blg"), 'output);
   package!-remake x; load!-package x;
   >>;

close wrs nil;
end;
