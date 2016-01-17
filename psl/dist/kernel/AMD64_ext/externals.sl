%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:EXTERNALS.SL
% Description:  Definitions of foreign language functions
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      19-Apr-84
% Modified:     15-Feb-85 13:25:43
% Mode:         Lisp
% Package:
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 17-Feb-89 (Chris Burdorf)
% Changed name of sigset to sun3_sigset for sun os/4.
% 05-Apr-88 (Julian Padget)
%  Once more reinstated handle for alarm and ualarm.
% 29-May-87 (Harold Carr & Leigh Stoller)
%  Added external definition for setenv.
% 05-May-87 (Leigh Stoller)
%  Added external definitions for fast-math.sl. They are in float.c
% 13-Apr-87 (Leigh Stoller & Harold Carr)
%  Added external definition of allocatemorebps, defined in bpsheap.c.
% 26-Sep-86 (Leigh Stoller)
%  Added external entry for exit which is needed on the sun to pass an exit
%  code back to unix.
% 01-Sep-86 (Leigh Stoller)
%  Added external-system to do a standard system call from C.
% 19-Aug-86 (Leigh Stoller)
%  Added entries for get_file_status, sigrelse, and sigset.
% 15-Feb-85 13:25:18 (Brian Beach)
%  Commented out a couple of functions for Pisces.
% 01-Feb-85 (Bill Williams)
%  Add external entries for Lisp terminal emulator.
% 24-Jan-85 (Vicki O'Day)
%  Added sleep entry.
% 7-Jan-85 (Vicki O'Day)
%  Removed nmodekeys entry.
% 17-Dec-84 (Vicki O'Day)
%  Added setlinebuf entry.
%  Added syscall entry, for access to HP-UX system calls.  The syntax
%  of this command is (syscall <system call #> <arg1> <arg2> ...).
%  Currently, a limit of four arguments to the system call is imposed,
%  since no system calls that we can use have more than this.  The
%  various forms of execl do, but since we can't use fork now, we don't
%  need this.  When we can use fork, the number of arguments allowed
%  by syscall should be increased.
% 7-Dec-84 (Vicki O'Day)
%  Added nmodekeys entry, so 9836-users can call it.
% 27-Sep-84 19:57:38 (Dave Matthews)
%  Added an external function declaration for the new alterheapsize function.
% 17-Jul-84 22:51:12 (RAM)
%  Changed chdir to unixcd and time to external_time.
%  Added external_stat, link, and unlink.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(compiletime
 (setf *foreign-functions* nil)
 )
 
(compiletime
 (defmacro external-function (name args)
     (setf *foreign-functions* (cons name *foreign-functions*))
     (flag1 name 'foreignfunction)
     `(de ,name ,args
        (,name ,@args)
        )))
 
(off r2i)
 
% Defined in echo.c
%
(external-function echoon               ())
(external-function echooff              ())
(external-function external_charsininputbuffer    (chan))
(external-function flushstdoutputbuffer ())
(external-function external_user_homedir_string    ())
(external-function external_anyuser_homedir_string (user))
 
 
% Defined in bpsheap.c
%
(external-function alterheapsize        (integer))
(external-function allocatemorebps      (amount))
(external-function get_imagefilepath    ())
 
% Defined in file-status.c
%
(external-function get_file_status      (filename block flag))
 
 
% Defined in os-hooks.c
%
(external-function os_startup_hook      (pargc pargv))
(external-function os_cleanup_hook      ())
(external-function get_execfilepath	())
 
 
% Defined in pslextras.c
%
(external-function external_alarm      (sec))
(external-function external_ualarm     (usec repeat))
(external-function external_time       (buffer))
(external-function external_timc       (buffer))
(external-function external_stat       (path buf))
(external-function external_link       (path1 path2))
(external-function external_strlen     (strptr))
(external-function external_unlink     (path))
(external-function external_setenv     (varstring valstring))
(external-function external_rmdir      (path))
(external-function external_mkdir      (path mode))
(external-function external_getenv     (envstring))
(external-function uxfloat             (buffer integer))
(external-function uxfix               (buffer))
(external-function uxassign            (arg1-buffer arg2-buffere))
(external-function uxplus2             (result-buffer arg1-buffer arg2-buffer))
(external-function uxdifference        (result-buffer arg1-buffer arg2-buffer))
(external-function uxtimes2            (result-buffer arg1-buffer arg2-buffer))
(external-function uxquotient          (result-buffer arg1-buffer arg2-buffer))
(external-function uxgreaterp          (arg1-buffer arg2-buffer tee nill))
(external-function uxlessp             (arg1-buffer arg2-buffer tee nill))
(external-function uxwritefloat        (buffer floatptr convstr))
(external-function uxwritefloat8       (buffer floatptr convstr dummy))
(external-function uxdoubletofloat     (x y))
(external-function uxfloattodouble     (y y))
(external-function uxsin           (r x))
(external-function uxcos           (r x))
(external-function uxtan           (r x))
(external-function uxasin           (r x))
(external-function uxacos           (r x))
(external-function uxatan           (r x))
(external-function uxsqrt           (r x))
(external-function uxexp           (r x))
(external-function uxlog           (r x))
(external-function uxatan2           (r y x))
 
 
% Defined in pwd-fn.c
%
(external-function external_pwd         ())

 
% Defined in sigs.c
%
(external-function sun3_sigset               (signame handler))
(external-function sigrelse             (signame ))
 
 
% Defined In unexec.c
%
(external-function unexec               (newname aname dstart bstart))
 
 
% Defined in unix-io.c
%
(external-function unixputc             (ch))
(external-function unixputs             (str))
(external-function unixputn             (num))
(external-function unixcleario          ())
(external-function expand_file_name     (str))
(external-function unixopen             (name mode))
(external-function unixcd               (dir))
(external-function ctime                (buffer))
(external-function external_system      (command))
(external-function external_fullpath	(relpath))
 
 
% Defined In the C Library
%
(external-function external_exit        (status))
(external-function fopen                (name mode))
(external-function fclose               (fp))
(external-function fread                (buf size count fp))
(external-function fputc                (ch fp))
(external-function fgetc                (fp))
(external-function fgets                (buf count fp))
(external-function fwrite               (str strlen count fp))
(external-function fflush               (fp))
(external-function fseek                (fp offset ptrname))
(external-function clearerr             (fp))
(external-function xgetw                (fp))
(external-function putw                 (w fp))
(external-function signal               (signame handler))
(external-function sleep        (sec))
(external-function ieee_handler (str1 str2 handl)) 
(external-function ieee_flags		(str1 str2 str3 str4))
 
%% See $pxnk/sys-io.sl for the call to this. In SYS V, it may have to be
%% moved into the microkernel since it is not directly supported. Under
%% SYS V, buffering can only be changed before any writes on the stream,
%% which means it must be called before setupbpsandheap. Also, under BSD,
%% setlinebuf is a system call, while under SYS V, it must be written using
%% setbuf and setvbuf. See the Bobcat version of setlinebuf.c in $pb.
(external-function setlinebuf           (iobuff))
 
(external-function getpid ())
(external-function gethostid ())

%%socketinterface

(external-function unixsocketopen (name number))
(external-function getsocket (fd name number))
(external-function writesocket (fd name number))
(external-function unixclosesocket (number))

%% fork and wait

(external-function fork())
(external-function wait(ptr))

%% popen, pclose

(external-function popen                (cmd mode))
(external-function pclose               (stream))

%% shared memory , semaphores

(external-function shmctl (shmid cmd buf))
(external-function shmget (key size shmflg))
(external-function shmat  (shmid shmaddr  shmflag))
(external-function shmdt (shmaddr))

(external-function semctl (semid semnum cmd arg))
(external-function semget (key nsems semflg))
(external-function semop  (semid sembuf nsops))

% dynamic linking


(external-function dlopen (filenam flag))
(external-function dlerror (void))
(external-function dlsym (handle sym))
(external-function dlclose (handle))

 
(on r2i)
 
(compiletime
 (for (in name *foreign-functions*)
      (do (remflag1 name 'foreignfunction))
      ))

(compiletime (flag '(profil) 'foreignfunction))

(de unix-profile (a b c d)
   (profil a b c d))

(compiletime (remflag '(profil) 'foreignfunction)) 

