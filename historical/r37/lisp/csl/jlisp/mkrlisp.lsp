%
%           jlisp -z -orlisp.img mkrlisp.lsp -lrlisp.log
%
% where this job rebuilds RLISP etc etc from scratch
%
%
% Build a CSL REDUCE "in core" as first stage of a bootstrap.  To be
% run starting from a cold-start CSL, i.e. with the -z option.
%

% Author: Anthony C. Hearn.
%         Modifications by Stanley L. Kameny and Arthur Norman

(verbos 3)

(rdf "compat.lsp")
(rdf "extras.lsp")
(rdf "compiler.lsp")

% (compile!-all)

(setq !*comp nil)

(setq !*echo t)

% The curious arrangement of rds and oldchan!* is because the
% source file ../src/boot.sl ends by doing an (rds oldchan!*), which
% avoids it hitting the end of file, and probably fits PSL very well.
% If that line were not there I could just go (rdf "$cslbase/../src/boot.sl")
% and that would cope with the file closing as well.

(rds (setq oldchan!* (rds nil)))

(rds (setq xxx (open "../src/boot.sl" 'input)))

(close xxx)

(begin2)

% "cslprolo.red" can contain thigs that are system dependent
% but which HAVE to be loaded before "rlisp.red" is.

rds(xxx := open("../src/cslprolo.red",'input));

(close xxx)

(begin2)

rds(xxx := open("../src/module.red",'input));

(close xxx)

(begin2)

rds(xxx := open("../src/rlisp.red",'input));

(close xxx)

(begin2)

% "cslrend.red" contains CSL specific definitions of a few functions
% required by Reduce, and can flag things as 'lose where that will help
% performance by allowing versions of functions built into the CSL kernel
% to remain active.

rds(xxx := open("../src/cslrend.red",'input));

(close xxx)

(begin)

symbolic;

<< initreduce();
   date!* := "RLISP";
% I call mapstore() here to reset all counts to zero,
% thereby making future statistics at least marginally meaningful!
   mapstore 4;
   !*savedef := nil;

   preserve('begin, "RLISP ...") >>;

% end of mkrlisp.lsp

quit;
