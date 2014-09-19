%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:LOAD.SL 
% Title:        New version of LOAD function, with search path 
% Author:       Eric Benson 
% Created:      2 April 1982 
% Modified:     15-May-84 14:29:31 (Brian Beach) 
% Package:      Kernel 
%
% (c) Copyright 1987, University of Utah, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 17-Feb-89 (Chris Burdorf)
% Redefined faslin-bad-file so that it prints the file name.
%
% 21-May-87 (Leigh Stoller)
%  Incorporated addload function from utilities at Alpha1 request.
% 10-May-84 14:29:22 (Brian Beach)
%   7 Mar 1984 1632-PST (Nancy Kendzierski, Cris Perdue)
%    Rewrote LOAD1.  Now understands loads-in-progress, gives better warning
%    messages, and correctly completes loading and importing of files for a
%    module before believing loading is complete.
% 01-Dec-83 14:50:16 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid
 '(
   loaddirectories* % list of strings to append to front              
   loadextensions*  % a-list of (str . fn) to append to end and apply
   pendingloads*    % created by Imports, aux loads                      
   loads-in-progress*  % list of modules being loaded, but not done
   *lower           % print IDs in lowercase, for building filename for Unix
   *redefmsg        % controls printing of redefined function message
   *usermode        % Controls query of user for redefining system functions
   *insideload      % Controls "already loaded" message                    
   *verboseload     % Print REDEFs and LOAD file names                    
   *printloadnames  % Print Names of files loading                     
   options*
   ))

(compiletime (load if-system))

(if_system unix (setq loaddirectories* (list "" "$pl/")))

(setq loadextensions* (list (cons ".b" 'faslin) (cons ".lap" 'lapin)))

(setq *verboseload nil)

(setq *printloadnames nil)

(dm load (u)
  (list 'evload (mkquote (cdr u))))

(de evload (u)
  (foreach x in u do (load1 x)))

(dm reload (u)
  (list 'evreload (mkquote (cdr u))))

(de evreload (u)
  (foreach x in u do (setq options* (delete x options*)))
  (evload u))

(de load1 (u)
  % Don't load if already in process of or completely loaded.
  (if (memq u loads-in-progress*)
    (errorprintf
     "*** Warning: Load of %w previously requested, but incomplete" u)
    (if (memq u options*)
      (if *verboseload (errorprintf "*** %w already loaded" u))

      % Otherwise, try to load the module.
      (let ((pendingloads* nil)
	    (*insideload t)
	    (*redefmsg *verboseload)
	    (*usermode nil)
	    (loads-in-progress* (cons u loads-in-progress*))
	    ld le f found module)
	(setq ld loaddirectories*)

	% Try to find the actual file to load.
	(let ((*lower t))
	  (while (and ld (not found))
	    (setq le loadextensions*)
	    (while (and le (not found))
	      (when (filep "otto") %(setq f (bldmsg "%w%w%w"
					   %(first ld)
					   %u
					   %(car (first le)))))
		(setq found (cdr (first le))))
	      % Found is function to apply       
	      (setq le (rest le)))
	    (setq ld (rest ld))))

	(if (not found)
	  (stderror (bldmsg "%r load module not found" u))
	  (progn (when (or *verboseload *printloadnames)
		   (errorprintf "*** loading %w%n" f))
		 (apply found (list f))
		 ))

	% Perform import requests.
	(while pendingloads*
	  (setq module (car pendingloads*))
	  (setq pendingloads* (cdr pendingloads*))
	  (load1 module))

	% Done loading.
	(setq options* (cons u options*))
	(if *verboseload (errorprintf "*** %w loaded" u))))))

(de imports (l)
  (if *insideload
    (progn (foreach x in l do (unless (or (memq x options*) 
                                       (memq x pendingloads*))
                      (setq pendingloads* (append pendingloads* (list x))))))
    (evload l)))

%% Add a new load string to loaddirectories*, making sure that there is
%%  a trailing /, and that "" remains at the car of the loaddirectories*.

(de addload (dirstring)
  % Make sure there is a "/" on the name.
  (cond ((not (equal "/" (sub dirstring (size dirstring) 0)))
	 (setq dirstring (concat dirstring "/"))))
  (cond ((not (member dirstring loaddirectories!*))
	 (setq loaddirectories!*
	       (cons ""		% Preserve working dir at list top.
		     (cons dirstring (delete "" loaddirectories!*)))))))


(de faslin-bad-file (name)
  (printf "%w is not a FASL file%n" name))
