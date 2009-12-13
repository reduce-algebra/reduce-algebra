%
% BUILD.RED - Compile a module from .BUILD or .RED file
% 
% Author:      Eric Benson
%	       Symbolic Computation Group
%              Computer Science Dept.
%              University of Utah
% Date:        23 March 1982
% (c) Copyright 1982, University of Utah
%
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
% Edit by Russ Fish, Tue Oct 20 18:15 1987
%  Reorder the extensions list so 14-character filename Unix machines
%  don't always assume a truncated filename is a .build file.
% Edit by Tim Mueller, Mon Nov  3 11:18:47 1986
%  Converted to lisp syntax.
% Edit by Russ Fish, Sat Apr 14 07:37:25 1984
%  Add BuildErrorExit mode to return error status instead of ignoring it.
%  Look for other extensions: .r and .rl for rlisp, .lsp for lisp syntax.
%  Echo .build files as before, suppress echo for source files.
% Edit by MLG, 9 April 1983
%  added MakeBuildFilename, and ERRSET, so Build more  robust
%  and more like  Compile-file. Also turned off break,
%  and do closing FASLEND in case of error.
% Edit by Cris Perdue, 23 Mar 1983 0856-PST
%  Added BuildFileFormat for Apollo as requested by Kessler
% 07-Mar-83  Nancy Kendzierski
%  Added load if-system, since many .build files use the if_system macro.
% 09-Feb-83  MLG
%  Changed Buildformat to use $pl/
% <PSL.UTIL>BUILD.RED.3,  1-Dec-82 16:12:33, Edit by BENSON
%  Added if_system(HP9836, ... )

(compiletime (load if-system))
(imports '(if-system))                  % useful for most "built" systems

(fluid '(*quiet_faslout                 % turns off welcome message in faslout
	*lower                          % lowercase ids on output
	*usermode                       % query on redefinition
	buildfileformat*))


(if_system tops20 
	  (setq buildfileformat* "pl:%w"))
(if_system unix 
	  (setq buildfileformat* "$pl/%w"))
(if_system hp9836 
	  (setq buildfileformat* "pl:%w"))
(if_system apollo 
          (setq buildfileformat* "~p/l/%w"))

(de makebuildfilename (modulename extlist) 
% Try to construct Filename form Modulename
 (prog (y) 
  (cond ((null extlist) (return (stderror 
	 (bldmsg "Cant find a complete filename for %r" modulename))))) 
  (cond ((filep (setq y (bldmsg "%w.%w" modulename (car extlist)))) 
	(return 
	(progn 
	    % Echo .build files, suppress echo for source files.
	    (setq semic* (cond ((eq (car extlist) 'build) '\;) (t '$))) 
	    (errorprintf "--- Building %w%n" y) 
	    y)))) 
	
  (return (makebuildfilename modulename (cdr extlist)))))
 

(fluid '(*builderrorexit))              % For scripts: if on, exits with error status.

(de build (x) 
 (prog (result) 
	(setq result (errset (buildaux x) t)) 
	(cond ((fixp result) 
	    (progn (cond (*writingfaslfile (faslend))) 
	      (errorprintf "***** Error during build of %w%n" x) 
	      (cond (*builderrorexit 
		  (exit-with-status (cond ((neq result 0) result) (t -1))))))))))
 

(de buildaux (x) 
(prog (*usermode *quiet_faslout y *break result) 
    (setq *quiet_faslout t) 
    ((lambda (*lower) 
    (progn (setq y (makebuildfilename x '(r rl red build sl lsp))) 
        (faslout (bldmsg buildfileformat* x)))) t) 
    (evin (list y))           % Lisp input for .SL, .LSP, otherwise Rlisp.
    (faslend)))





