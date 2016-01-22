%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:SYSTEM-EXTRAS.SL                                      
% Title:          HPUX Unix specific code for PSL                          
% Author:         Eric Benson                                              
% Created:        9 October 1981                                           
% Modified:       2-Jan-85 (Vicki O'Day)
% Package:        Kernel                                                   
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
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

(compiletime (load sys-consts sys-macros fast-vector inum))

%(compiletime (load include))
%(compiletime (include "C:/psl/kernel/winnt/psllcall.h"))

(compiletime (progn
(setq define-list '(
#define    YIELD             0
#define    PUTS              1
#define    PUTINT            2
#define    PUTOCT            3
#define    NEWLINE           4
#define    PUTC              5
#define    BINARYOPENREAD    6
#define    BINARYOPENWRITE   7
#define    BINARYCLOSE       8
#define    BINARYREADBLOCK   9
#define    BINARYWRITEBLOCK 10
#define    GETDATE          12
#define    TIMC             13
#define    SIGNAL           14
#define    CD               15
#define    FGETS            16
#define    SYSTEM           17
#define    YESP             18
#define    GETTIME          19
#define    LINELENGTH       20
#define    ASKUSER          21
#define    LSEEK            22
#define    HELP             23
#define    CONNECT_OPEN     24
#define    CONNECT_CLOSE    25
#define    CONNECT_FETCH    26
#define    CONNECT_SEND     27
#define    CONNECT_ASK      28
#define    CONNECT_BLOCK    29
#define    SLEEP            30
#define    PSLL_RESET       31
#define    EXIT_WITH_STATUS 32
#define    PIPE_OPEN        33
#define    PIPE_CLOSE       34
#define    PAGE             35
#define    MENU             36
#define    WIN_PAR          37
#define    FILE_TREE        38



#define PSLCALL_TERMINAL_INTERRUPT  0
#define PSLCALL_RESIZE              1 
#define PSLCALL_GRAPHICS_MODE       3
#define PSLCALL_GRAPHICS_MODE_ON    3
#define PSLCALL_GRAPHICS_MODE_OFF   4
#define PSLCALL_MENU                5
))
(while define-list
     (pop define-list)
     (pop define-list)
     (apply 'define-constant
       (list (list 'define-constant 
		   (pop define-list) 
		   (pop define-list)))))
))  % #include


(on fast-integers)

% Import Unix argument vector as a vector of strings.                      
(fluid '(unixargs*))

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

(de delete-file (unixstring)
  (if (stringp unixstring)
    (weq 0 (external_unlink (strbase (strinf unixstring))))
    (nonstringerror unixstring 'delete-file)))


(declare-warray filestatus-work size 13)

(compiletime (flag '(mkfiletime) 'internalfunction))

(de mkfiletime (low high)
   (let ((bi (gtpos 2)))
        (wputv (inf bi) 2 low)
        (wputv (inf bi) 3 high)
        (cons 'filetime bi)))

(de filestatus (filenamestring dostrings)
  (let ((status (get_file_status
		 (expand_file_name (unixstring filenamestring))
		 filestatus-work
		 (if dostrings 1 0))))
    (if (weq status -1) nil
     (when (and (weq status 0) (getd 'gtpos))    % 0 = success
	   (list (cons 'createtime (mkfiletime (wgetv filestatus-work 0)
					          (wgetv filestatus-work 1)))
		 (cons 'accesstime (mkfiletime (wgetv filestatus-work 2)
					          (wgetv filestatus-work 3)))
		 (cons 'writetime (mkfiletime (wgetv filestatus-work 4)
					          (wgetv filestatus-work 5))))
))))

	

(de old-filestatus (filenamestring dostrings)
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


% Inf is used heavily here just to mask off the high order byte.           
% 9836 assembler and linker generate addresses with high order             
% byte value -1.  PSL tends to generate addresses with high order          
% byte 0.  On 9836 these are equivalent, but we must mask them             
% off.  Comparing X against NextBps helps assure it points to       
% code, but more importantly assures it points to existing                 
% memory. /csp                                                             


(de returnaddressp (x)
  (prog (s y)
	(unless (and (intp x) (>= x 2000))
	  (return nil))
	% Actually, top bits must                                          
	% be 0 or -1 due to                                                
	% 9836 assembler, linker                                           
	(when (weq (wand x 1) 1)
	  (return nil))
	% if OddP X                                                        
	(setq x (inf x))
	(when (wlessp x 65536)    % bottom 64k is read-protected in win32
	  (return nil))
	(cond ((not (wlessp x (inf nextbps))) % Assures X points to real memory
	       (return nil)))
	(setq s (inf symfnc))
	(unless (weq (halfword x -3) 16#15ff) (return nil))
	% call longword                                                     
	(setq y (inf (wgetv x -1)))
	(setq y (wdifference y s))
	(setq y (wquotient y addressingunitsperfunctioncell))
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
(de importforeignstring (c_s)
  (prog (new_s len)
	(when (weq c_s 0)
	  (return nil))
	% Not a string, pass it on.                                        
	(setq len (wdifference (external_strlen c_s) 1))
	(setq new_s (gtstr len))
	(for (from i 0 len 1) 
	      (do (setf (strbyt new_s i) (byte c_s i))))
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
	(when (or (not(fixp argc))(wleq argc 1)) (return nil))
	(setq sz (wdifference argc 1))
	(setq v (vecbase (vecinf (setf unixargs* (mkvect sz)))))
	(for (from i 0 sz 1) 
	      (do (setf (wgetv v i) (importforeignstring (wgetv argv i)))))))

(loadtime (getunixargs))


(de get-image-path ()
  (prog (val)
        (setq val (get_imagefilepath))
	(cond ((eq val 0) (return nil))
	      (t (return (importforeignstring val))))))

(de get-exec-path ()
  (prog (val)
        (setq val (get_execfilepath))
	(cond ((eq val 0) (return nil))
	      (t (return (importforeignstring val))))))

(de get-fullpath (relpath)
  (prog (val)
        (setq val (external_fullpath (strbase (strinf relpath))))
	(cond ((eq val 0) (return nil))
	      (t (return (importforeignstring val))))))


% getStartupName - Figure out the filename that PSL was started from.      
(de getstartupname ()
  (prog (arg0 path pathsz dirstart i dir filename)
	(if (null unixargs*)
	    (getunixargs))
	% Just the 0th unix arg, if it is a full path starting with /.     
	(setq arg0 (indx unixargs* 0))
	(when (setq filename 
		    (progn (for (from i 0 (size arg0) 1) 
                            (do (when (or (eq (indx arg0 i) (char '/))
                                          (eq (indx arg0 i) (char '!\)))
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
				       "\"))
				     (when (or (equal dir ".\") 
					    (equal dir "\"))
				       (setq dir (pwd)))
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

%
% query the registry
% key must be one of the strings
%  HKCR HKCC HKCU HKLM HKU
%
% returns (type . data) where type is one of
% REG_SZ 1
% REG_EXPAND_SZ 2
% REG_BINARY 3
% REG_DWORD 4
% REG_MULTI_SZ 7
% REG_QUAD 11
% only 1 2 4 implemented

(declare-warray reg-infobuf size 3)

(de get-registry-value (key subkey name)
  (let ((result) (bufaddr) (type) (len) (str))
    (setq result (get_registry_value (strbase (strinf key))
                                     (strbase (strinf subkey)) 
                                     (if name
                                         (strbase (strinf name)) 
                                       0)
                                     reg-infobuf))
    (if (weq result 0)
        (progn
          (setq type (wgetv reg-infobuf 0))
          (setq len (wgetv reg-infobuf 1))
          (setq bufaddr (wgetv reg-infobuf 2))
          (cons type
            (cond ((weq type 4)    % REG_DWORD
                   (wgetv bufaddr 0))
                  ((or (weq type 1) (weq type 2))    % REG_SZ, REG_EXPAND_SZ
                   (if (weq 0 (byte bufaddr (isub1 len)))
                       (setq len (isub1 len)))
                   (setq str (gtstr (isub1 len)))
                   (for (from i 0 (isub1 len) 1)
                     (do (setf (strbyt str i) (byte bufaddr i))))
                   (mkstr str))))))))
           
  
%---------- windows callback functions ---------------------------------

(fluid '(win-messages))

(setq win-messages (make-vector 31 nil))

(de PowerOf2P (X)
  % If X is a positive power of 2, log base 2 of X is returned.  Otherwise
  % NIL is returned.
  (prog (N)
	(return (cond ((or (not (FixP X)) (MinusP X) (equal X 0)) NIL)
		      (t (progn (setq N 0)
				(while (not (equal (lor x 1) x))
				       (progn (setq N (add1 N))
					      (setq X (lsh X -1))))
				(cond ((equal X 1) N) (T NIL))))))))

(de psl_call1(mode p2 p3 p4)
 (let ((mod (powerof2p mode)))
  (cond ((eq mod PSLCALL_TERMINAL_INTERRUPT)  (terminal-interrupt))
        ((eq mod PSLCALL_RESIZE)          (channellinelength 1 p2))
        ((igetv win-messages mod)  (eval (igetv win-messages mod)))
        (t (stderror (bldmsg "unknown callback mode: %w" 
                              (list mode p2 p3 p4) ))) )))

(de psll-call(p1 p2 p3 p4)(psll_call p1 p2 p3 p4))

%---------- expand a filename from the environment ---------------------

(de fnexpand (na)
 (let ((s (explode na)) v w s1 c b)
     (while (and s (not b))
	(if (eq (setq c (pop s)) '$)
	    (setq b t)
	    (push c s1)))
     (while (and s b)
	(if (or (liter (setq c (pop s))) (digit c))
	    (push c v)
	    (progn (setq b nil)(push c s))))
     (when (null v)(return na))
     (setq w (getenv (compress (cons '!" (reversip (cons '!" v))))))
     (setq w (if w
	      (append (reversip s1) (append (explode2 w) s))
	      (delete '$ (explode na)) 
     )) 
     (compress (subst '!\ '!/ w))  ))
	      
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(fluid '(**windows))

(de win-yesp(s)
   (if (eq **windows 1)
       (wneq 0 (psll-call (strbase(strinf (bldmsg "%l" s) )) 0 0 18)) 
       (yesp s) ))

	     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Handling priority messages from Windows
%

(compiletime (load fast-vector))

(fluid '(win-messages))

(setq win-messages (make-vector 31 nil))
 
(iputv win-messages 0 '(channellinelength 1 (psll-call 0 0 0 20))) 

(de prio-message1(n)
 (ifor (from i 0 31 1)
    (do
     (progn
       (when (wneq 0 (wand n 1)) (eval (igetv win-messages i)))
       (setq n (wshift n -1))
))  ))

% enable windows interrupts
(de ! yield()(psll-call 0 0 0 0))

% send message box to user
(de tellUser(q)
 (when (weq **windows 1)
       (psll-call (strbase(strinf q)) 0 0 21))
 nil)

% prompt an item (returns a string)

(de askUser(q)
   (let(a c n)
     (cond ((weq **windows 1)
            (setq n  (psll-call (strbase(strinf q)) 0 0 21))

	       % convert string to list of chars
            (importforeignstring n))
	   (t (let ((out* 1)(in* 0))
		   (prin2t q)
		   (while (wneq (setq c(readch)) (char eol))
			  (push c a))
                   (if (null a)	  nil
                     (compress (cons '!" (reverse (cons '!" a))))))))

    ))
				       
(de file_tree()
   (let(a c n)
     (cond ((weq **windows 1)
	    (setq c (gtwrds 10))   % buffer for answer
	    (setq n
	       (psll-call 0
			  (strbase(strinf c))
			  40
			  38))
	       % convert string to list of chars
	    (ifor (from i 0 (isub1 n) 1)
		  (do (push (int2id (strbyt (strinf c) i)) a)))
	   ))
      (if (null a)
	  nil
	  (compress (cons '!" (reverse (cons '!" a))))) ))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   Menu interface
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(*win-input-buffer*))

(de psl-popup-menu(callback)
   (when (not (eq **windows 1))
	 (stderror "menu service only under windows"))
   (errorset (list callback) nil nil)
   (psll-call-continue)
   nil)

(de psl-popup-menu1(m s w)
 (prog (r)
  (when (or (eq m 0)(eq m 1))
	(setq s (strbase (strinf s))))
  (setq r (psll-call m s w 36))
  (when (eq m 2)(setq r(psll-call-prioloop)))
  (return r)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  General interface for message passing DDE for windows
%
%  H. Melenk, ZIB Berlin, January 1992
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(fluid '(*message-buffer* *token-buffer* *callback-functions*))
 
(setq *message-buffer* (mkstring 128 0)
      *token-buffer* (mkstring 128 0))
 
(de send-server(handle command text)
   (test-server handle 'send-server)
   (when (not (stringp command))
	 (nonstringerror command 'send-server))
   (when (not (stringp text))
	 (nonstringerror text 'send-server))
   (psll-call handle (strbase (strinf command))
		      (strbase (strinf text))
		      CONNECT_SEND))
 
(de fetch-server(handle command)
  (prog (l n r)
   (test-server handle 'fetch-server)
   (when (not (stringp command))
	 (nonstringerror command 'fetch-server))
   (setf (strbyt (strinf *message-buffer*) 0) 0)
   (setq n
    (psll-call handle (strbase (strinf command))
		      (strbase (strinf *message-buffer*))
		       CONNECT_FETCH))
   (when (or (wleq n 0)
	     (weq 0 (strbyt (strinf *message-buffer*) 0) ))
	 (return nil))
   (setq r (copy-message *message-buffer*))
   (return r)))
 
 
(de open-server(server topic callback)
 (prog(u)
   (when (not (stringp server))
	 (nonstringerror server 'open-server))
   (when (not (stringp topic))
	 (nonstringerror topic 'open-server))
   (setq u
    (psll-call (strbase (strinf server)) (strbase (strinf topic))
	       0 CONNECT_OPEN))
   (when (wleq u 0) (return nil))
   (when callback (push (cons u callback) *callback-functions*))
   (return u)))
 
 
(de close-server(handle)
     (delasc handle *callback-functions*)
     (psll-call handle 0 0 CONNECT_CLOSE))
 
(de message-handler()
    % this routine is called when an asynchronous message has arrived;
    % action: the handle, message type and message text picked up;
    %         if there is a callback function for the handle, this
    %         is executed with the message tag and text as arguments.
  (prog(hand cb tag)
    (setq hand
       (PSLL-call (strbase (strinf *token-buffer*))
		  (strbase (strinf *message-buffer*))
		  0
		  CONNECT_ASK))
    (when (or (wleq hand 0) (eq tag 'ACK)) (return nil))
    (setq tag (intern (copy-message *token-buffer*)))
    (setq cb (assoc hand *callback-functions*))
    (when cb (apply (cdr cb)
		   (list tag
			 (copy-message *message-buffer*) )))
    (return nil) ))
 
(de test-server(handle fcn)
   (when (not (and (fixp handle)(wgreaterp handle 0)))
	 (typeerror handle fcn 'handle)))
 
(de copy-message(msg)
 % copy characters from global buffer to local string.
 (prog(l r)
   (setq l 0)
   (while (not (izerop (strbyt (strinf msg) l)))
	  (setq l (iadd1 l)))
   (setq l (isub1 l))
   (setq r (mkstring l))
   (ifor (from i 0 l 1)
	 (do (setf (strbyt (strinf r) i)
		   (strbyt (strinf msg) i))))
   (return r) ))

(de sleep(n)
  (when (eq **windows 1)  
    (psll-call n 0 0 SLEEP)))

(de psll-reset(n)
  (when (eq **windows 1)  
    (psll-call n 0 0 PSLL_RESET)))


(off fast-integers)

%% End of File.
