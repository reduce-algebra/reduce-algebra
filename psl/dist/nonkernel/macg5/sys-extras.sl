%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:SYSTEM-EXTRAS.SL                                      
% Title:          HPUX Unix specific code for PSL                          
% Author:         Eric Benson                                              
% Created:        9 October 1981                                           
% Modified:       2-Jan-85 (Vicki O'Day)
% Package:        Kernel                                                   
%
% (c) Copyright 1987, University of Utah, all rights reserved.       
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 15-Apr-89 (Winfried Neun)
%  Changed getbyte back to byte.
% 10-Aug-88 (Julian Padget)
%  Redefined returnaddressp for the Sun 4.
% 25-Aug-87 (Leigh Stoller)
%  Added definition of external-allocatemorebps to map to allocatemorebps.
%   Vax nameing convention fix.
% 29-May-87 (Leigh Stoller & Harold Carr)
%  Added setenv function.
% 28-May-87 (Leigh Stoller & Harold Carr)
%  Added unix-time function for pcls.
% 02-Sep-86 (Harold Carr)
%  Made QUIT call exit-with-status with 0 instead of doing a
%  (throw 'reset 'quit).  (throw 'reset 'quit) makes it impossible to
%  make special PSLs with initcode to do some work and then call
%  (exitlisp) or (quit).  The initcode is evaluated before the reset
%  tag is in place.
% 01-Sep-86 (Leigh Stoller)
%  Modified the system function to call an external C routine that does
%  makes the actual call to system and returns the value.
% 19-Aug-86 (Leigh Stoller)
%  Added the filestatus function.
% 03-Aug-86 (Leigh Stoller)
%  Modified the quit function so that it looks at the break loop level to
%  determine if a nonzero status should be returned to the OS.
% 2-Jan-85 (Vicki O'Day)
%  Now that system signal-handler frames are popped from the stack, deref
%  isn't necessary, so it was removed.
% 21-Dec-84 (Vicki O'Day)
%  Added new check to returnaddressp: it now calls a function "deref",
%  which invokes the C routine "dereference" to find out if dereferencing
%  an address is safe.
% 14-Nov-84 (Vicki O'Day)
%  Changed returnaddressp to check for address >= 2000, to account
%  for HP-UX mapping above ROM.
% 17-Jul-84 23:13:12 (RAM)
%  Removed coredump routines because they kept getting in the way.
%  Changed call to chdir to a call on unixcd, to incorporate expand_file_name.
% 12 June 84 (Vicki O'Day)                                                 
%  Added routines to turn coredumps on and off, with the help of           
%  a super-user owned "createcore" program.                                
% 11-May-84 10:00:00 (Vicki O'Day)                                         
%  Changed system to call nof_system, a no-fork version.                   
%  This is part of Bill Watkins' escape-to-shell mechanism.                
% 27-Feb-84 16:52:12 (RAM)                                                 
%  Pathin the appropriate files for HPUX200.                               
%  Set system_list* to reasonable HPUX200 default.                         
%  Modified quit, exitlisp, and returnaddressp to do right things.         
%  Added system function, like elsewhere on VAX version.                   
%  Changed all references to _filepointerofchannel to channeltable.        
%  Changed call to byte in importforeignstring to getbyte since byte not   
%  defined yet.                                                            
%  Fixed some bugs in getstartupname.                                      
% 2-Dec-83  16:00:00 (Brian Beach)                                         
%   Translated from Rlisp to Lisp.                                         
%                                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
%                                                                          
%  $pv/system-extras.red, Tue Nov 23 16:43:32 1982, Edit by fish           
%  Added getUnixArgs and getStartupName, factored out importForeignString. 
%  $pv/system-extras.red, Nov  1 12:41:36 1982, Edit by fish               
%  Added cd, pwd, channelFlush.                                            
%  <PSL.KERNEL-VAX>SYSTEM-EXTRAS.RED.5, 22-Sep-82 10:57:37, Edit by BENSON 
%  Added user-homedir-string and getenv to end of file                     
%  $pi/system-extras.red, Aug 11 07:19:06 1982, Edit by fish               
%  Added flushStdOutputBuffer for Emode.                                   

(compiletime (load sys-consts sys-macros))

(on fast-integers)

% Import Unix argument vector as a vector of strings.                      
(fluid '(unixargs*))

(global '(bpslowerbound))

%(de quit ()
%  (errorprintf "%f%nQuitting")
%  (throw 'reset 'quit))
%
% Quit know looks at the break loop level to determine if we are exiting
%  with a truly 0 status. If breaklevel* is > 0, then something is wrong, and
%  we should return some other value besides the default zero status. /LBS

(de quit ()
    (errorprintf "%f%nQuitting")
    (cond
     ((greaterp breaklevel* 0)
      (exit-with-status -1))
     (t
      (exit-with-status 0))))

(de exitlisp ()
  (quit))

(de system (unixstring)
  (if (stringp unixstring)
    (external_system (strbase (strinf unixstring)))
    (nonstringerror unixstring 'system)))


(declare-warray filestatus-work size 13)

(de filestatus (filenamestring dostrings)
  (let ((status (get_file_status
		 (expand_file_name (unixstring filenamestring))
		 filestatus-work
		 (if dostrings 1 0))))
    (when (weq status 0)      % 0 = success
      (for (from i 0 12 2)
	   (in label '(user group mode size writetime accesstime
			    statuschangetime))
	   (collect (cons label
			  (cons
			   (importforeignstring  (wgetv filestatus-work i))
			   (sys2int (wgetv filestatus-work (+ i 1))))))
	   ))))

(de returnaddressp (x)
  (prog (y)
        % if it is in code space
        (unless (and (posintp x) (codeaddressp x)) (return nil))
        % and word aligned
        (unless (weq 0 (wand x 3)) (return nil))
	(unless (weq 4 (wshift (getmem (wplus2 x -4)) -28)) (return nil))
        % then extract word offset from x and compute func cell addr
        (setq y (wand (getmem (wplus2 x -8)) 16#ffff))
        % turn that into an id-number
        % is it in the symbol table?
        (if (or (wlessp y 0) (wgreaterp y maxsymbols))
          (return nil)
          (return (mkid y)))))

% ****************************************************************         
% EMODE terminal control functions, passed through to C code.              
% To allow same names as C routines.                                       

(fluid '(channeltable))

(de charsininputbuffer ()
  % Returns nbr of input chars waiting.                                    
  (external_charsininputbuffer (wgetv channeltable 0)))

(de channelflush (chnl)
  % Flush any channel.                                                     
  (fflush (wgetv channeltable chnl)))

% ****************************************************************         
% String-oriented Unix interface functions.                                

% Copy and tag a Lisp string, given a C string pointer.                    

(compiletime (put 'specbyte 'opencode '((lbzx (reg 1) (reg 2) (reg 1)))))

(de importforeignstring (c_s)
  (prog (new_s len)
        (when (weq c_s 0)
          (return nil))
        % Not a string, pass it on.                                        
        (setq len (wdifference (external_strlen c_s) 1))
        (setq new_s (gtstr len))
        (for (from i 0 len 1) 
%             (do (setf (strbyt new_s i) (getbyte c_s i))))
	      (do (setf (strbyt new_s i) (specbyte c_s i))))
        (return (mkstr new_s))))

(de external-allocatemorebps ()
  (allocatemorebps))

(de init-file-string (program-name)
  % Build init file name.                                                  
  (bldmsg "%w.%wrc" (user-homedir-string) program-name))

(de user-homedir-string ()
  (concat (importforeignstring (external_user_homedir_string)) "/"))

(de anyuser-homedir-string (username)
  (if (stringp username)
    (concat (importforeignstring 
             (external_anyuser_homedir_string (strbase (strinf username))))
            "/")
    (nonstringerror username 'anyuser-homedir-string)))

(de getenv (s)
  % String from environment, or NIL.                                       
  (prog nil
        (unless (stringp s)
          (return nil))
        (return (importforeignstring (external_getenv (strbase (strinf s)))))))

(de setenv (var val)
 (cond ((not (stringp var))
        (nonstringerror var 'setenv))
       ((not (stringp val))
        (nonstringerror val 'setenv))
       (t
        (external_setenv (strbase (strinf var)) (strbase (strinf val)))
        NIL)))

(de cd (s)                              % Set current working directory.
  (when (stringp s)
   (weq 0 (unixcd (strbase (strinf s))))))     % 0 is success.

(de pwd ()                              % Return current working directory.
  (importforeignstring (external_pwd)))

(dm vecbase (u)                         % Missing, along with wrdBase.
  (list 'wplus2 (cadr u) 4))

% Fluid to stash the arg vector.

(fluid '(argc argv))

(de getunixargs () % (argc argv)
  (prog (sz v)
        (setq sz (wdifference argc 1))
        (setq v (vecbase (vecinf (setf unixargs* (mkvect sz)))))
        (for (from i 0 sz 1) 
              (do (setf (wgetv v i) (importforeignstring (wgetv argv i)))))))

%(loadtime (getunixargs))

% getStartupName - Figure out the filename that PSL was started from.      
(de getstartupname ()
  (prog (arg0 path pathsz dirstart i dir filename)
        (if (null unixargs*)
            (getunixargs))
        % Just the 0th unix arg, if it is a full path starting with /.     
        (setq arg0 (indx unixargs* 0))
        (when (setq filename 
                    (progn (for (from i 0 (size arg0) 1) 
                            (do (when (eq (indx arg0 i) (char '/))
                               (return arg0))))))
          (return filename))
        % Otherwise, have to look along the PATH environment var for directory.
                                                                           
        (setq path (concat (getenv "PATH") ":"))
        (setq pathsz (size path))
        (setq dirstart 0)
        (setq i 0)
        (repeat (progn (cond ((eq (indx path i) (char ':)) % Dir strings are separated by colons.
                                                                           
                              (progn (setq dir 
                                      (concat 
                                       (sub path dirstart 
                                        (difference 
                                         (difference i dirstart) 1))
                                       "/"))
                                     (when (or (equal dir "./") 
                                            (equal dir "/"))
                                       (setq dir (pwd)))
                                     (when (equal dir "//")
                                       (setq dir "/"))
                                     % Dot is current directory.           
                                     (setq filename (concat dir arg0))
                                     % Build a name.                       
                                     (unless (filep filename)
                                       (setq filename nil))
                                     % Keep going if not found there.      
                                     (setq dirstart (plus i 1)))))
                       % Next one starts after colon.                      
                       (setq i (plus i 1)))
                (or filename (greaterp i pathsz)))
        (return filename)))

(de unix-time ()
  (sys2int (external_time 0)))

(off fast-integers)

%% End of File.
(de sys2fixn (n) % can be removed when nbig30 is available
  (prog (fx)
        (setf savefixn-tag (tag n))
        (setf savefixn-inf (inf n))
        (setf n 0)
        (setq fx (gtfixn))
        (setf (fixval fx) (mkitem savefixn-tag savefixn-inf))
        (return (mkfixn fx))))

