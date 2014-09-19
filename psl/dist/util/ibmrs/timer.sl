(off usermode)
(load if-system)
(setq system_list* '(cray))
(faslout "timer")
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         TIMER.SL
% Description:  The timer function for Gabriel's test suite.
% Author:       Robert Kessler, Utah Pass Project
% Created:      05-Mar-84
% Modified:     9-May-84 (William Galway)
% Mode:         Lisp
% Package:
% Status:       Experimental (Do Not Distribute)
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 9-May-84 11:11  (William Galway)
%  Added (LOAD STRINGS) so that string-concat will work.
% 7-May-84 22:34  (William Galway)
%  Added if_system for Vax/Unix
% 23-Apr-84 09:06:22  (Robert Kessler)
%  Added if_system for the Cray.
% 21-Mar-84 21:21  (William Galway)
%  Misc cosmetic changes, mostly work on the TIMER macro so that it prints
%  information in a more readable format.  Moved call RECLAIM to come
%  before printing of test message, commented out stuff for printing
%  wholine time.   Timing tests now bracketed with dashes and start with an
%  identifier-string passed as an argument to the TIMER macro.
% 19-Mar-84 23:06   (William Galway)
%  Converted "//$" to "/$", since that's what the MacLisp function is
%  really called.  Confusion was caused by use of "/" as an escape
%  character in MacLisp.
% 6-Mar-84 21:15:47 (William Galway)
%  Moved LOAD of numeric operators to the front so that the definition of
%  DECLARE in this file isn't overridden by the loading of the COMMON
%  library later on.
% 6-Mar-84 10:26:50 (William Galway)
%  Converted FEXPRs into MACROs.  Changed some code to use READ-FROM-STRING
%  instead of COMPRESS/EXPLODE.  Added Jerry Duggan's stuff for
%  DATE-AND-TIME and LOADAV (inside of If_System DEC-20).  Also added stuff
%  to set up the global variable "MACHINE".
%
% 05-Mar-84 15:45:07 (Robert Kessler)
%  Added Machine to print, so we can tell which machine test was run
%  on.  Also, added a reclaim at the top, so when the test is run as a
%  file, all instances will start with the same amount of memory.
%  Finally, put in the useful functions that allow the code to be run
%  without much change.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(bothtimes (load numeric-ops if-system strings))
 
(FLUID '(MACHINE))
 
(DefMacro declare decllist
  % This version of declare maps SPECIAL declarations into FLUID
  % declarations.  It ignores FIXNUM (and any other) declarations.
  (let ((special-list
          (for (in eachdecl decllist)
            % The "join" clause appends everything together, thus one level
            % of parenthesis gets stripped off everything and NILs
            % disappear.
            (join
              (if (eqcar eachdecl 'special)
                (cdr eachdecl))))))
 
    (if special-list
      % Only declare FLUID's if there's something to declare.
      `(FLUID
         ',special-list))))
 
% Include can be ignored.
(de include (x)
  nil)
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Various machine dependent things...
(bothtimes
  (If_System DEC20
    (progn
      (load exec)
      (setf MACHINE "DEC-20")
 
      (de date-and-time ()
        (clocktimedate 1))
 
      (de loadav ()
        (read-from-string (getloadaverage))))))
 
(bothtimes
  (If_System VAX
    (progn
      (setf MACHINE "VAX/Unix")
 
      (de date-and-time ()
        % Just return the date with a dummy time value.
        (string-concat (date) " 12:00:00")
        )
 
      (de loadav ()
        % Just return a "dummy" load average.
        0
))))
 
(bothtimes
  (If_System CRAY
    (progn
      (setf MACHINE "CRAY")
 
      % Put in a dummy date-and-time to return constants.
      (de date-and-time ()
      "23-apr-84 12:00:00")
      % And a dummy loadav that will return 0.
      (de loadav ()
      0))))
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% Make a smarter 1-, so it will be fast.
(defmacro 1- (u)
  (if !*fast-integers `(isub1 ,u)
    `(sub1 ,u)))
 
% Ditto for 1+
(defmacro 1+ (u)
  (if !*fast-integers `(iadd1 ,u)
    `(add1 ,u)))
 
%;;;BEGIN
%;;; THE FILE "TIMER.LSP"
%(declare (setq defmacro-for-compiling ()) (*expr ttime dtime loadav))
%;;; date and time processing
%
%(defmacro pp-time ()
%      `(let ((time (status daytime)))
%          (implode (append (pp-two-digits (car time))
%                       '(K:K)
%                       (pp-two-digits (cadr time))
%                       '(K:K)
%                       (pp-two-digits (caddr time))))))
%
%(defmacro pp-date ()
%      '(let ((date (status date))
%           (dow (exploden (status dow))))
%          (implode (append (pp-process-dow dow)
%                       '(K K)
%                       (pp-two-digits (cadr date))
%                       '(K//K)
%                       (pp-two-digits (caddr date))
%                       '(K//K)
%                       (pp-two-digits (car date))))))
%
%(defmacro pp-two-digits (n)
%       `((lambda (n)
%               (declare (fixnum n))
%               (list (+ (car (exploden 'K0K)) (quotient n 10.))
%                   (+ (car (exploden 'K0K)) (remainder n 10.))))
%         ,n))
%
%(defmacro pp-process-dow (dow)
%  `(let ((dow ,dow))
%      (cons (car dow)
%            (do ((chars (cdr dow) (cdr chars))
%               (newchars () (cons (+ diff (car chars)) newchars))
%               (diff (- (car (exploden 'KaK))
%                      (car (exploden 'KAK)))))
%              ((null chars)
%               (nreverse newchars))))))
%
 
% Slight modifications of the functions for PSL:
%  Just calls Date-and-time directly, instead of pp-* functions.
%  Values returned by runtime, dtime, etc are of a different base than
%  was expected.  We ended up with integer overflows, by compensating
%  the function definition, so instead changed the divisor.
(defmacro timer (identifier-string name form . args)
  % The TIMER macro is used to construct timing functions.
  %  (TIMER identifier-string name form . args)
  % defines the function "name" that runs "form" with arguments
  % "args".  You must call "name" to actually run the timing function.  The
  % identifier-string is printed by the timing function before it runs the
  % timing test.
  `(defun ,name ,args
     % Make all tests start with a reclaim so that we start out with a
     % "clean" stack.
     (reclaim)
     (terpri)
     (princ "------------------------------------------------------------")
     (terpri)
     (princ ,identifier-string)(terpri)
     (princ "Timing performed on ")
     (princ Machine)
     (terpri)
     % Use psl's date-and-time function, instead of fooling around with the
     % pp- routines for printing date, time, etc.
     (princ (date-and-time))
%  (princ (pp-date))
%  (princ " at ")
%  (princ (pp-time))
     (princ".")
     ((lambda (t1 t2 t3 gt lb la)
        ,form
        (setq t1 (- (runtime) t1)
          t2 (- (dtime) t2)
          t3 (- (ttime) t3)
          gt (- (status gctime) gt)
          la (loadav))
        (terpri)
        (princ "........................................")
        (terpri)
        (princ "Cpu (- GC) Time = ")
        (princ (/$ (FLOAT  (- t1 gt))
                 % was divide by 1000000.0
                 1000.0))
        (princ " secs")
        (terpri)
        (princ "Elapsed Time = ")
        % Was divide by 60.0, changed to be by 1.0
        (princ (/$ (float t2) 1.0))
        (princ " secs")
        (terpri)
%*        (princ "Wholine Time = ")
%*        % Was divide by 60.0, changed to be by 1
%*        (princ (/$ (float t3) 1.0))
%*        (terpri)
        (princ "GC Time = ")
        % was divide by 1000000.0
        (princ (/$ (float gt) 1000.0))
        (princ " secs")
        (terpri)
        (princ "Load Average Before  = ")
        (princ lb)
        (terpri)
        (princ "Load Average After   = ")
        (princ la)(terpri)
        (princ "Average Load Average = ")
        (princ  (/$ (+$ la lb) 2.0))(terpri)
        (princ "------------------------------------------------------------")
        (terpri)
        )
       (runtime) (dtime) (ttime) (status gctime) (loadav) 0)))
 
%(*rset (nouuo ()))
%;;;THE FILE "TTIME.LAP[MAC,LSP]
 
%;;; Return the total wholine time
%(time)
%(lap ttime subr)
%(args ttime (nil . 0))
%(defsym ttime #o214)      ;where wholine time is
%(defsym fltr 127_26.)
%
%      (calli t 30)      ;gets jobnum in tt
%      (movei tt ttime)
%      (calli tt 33)      ;get that table
%      (add tt t)      ;add jobnum
%      (calli tt 33)
%      (jrst 0 fix1)      ;return fixnum
%()
%
%(lap dtime subr)
%(args dtime (nil . 0))
%      (calli tt 22)
%      (jrst 0 fix1)
%()
%
%(lap loadav subr)
%(args loadav (nil . 0))
%      (movei tt #o331)
%      (calli tt 33)
%      (hlrz d tt)
%      (idivi d #o1000)
%      (add d (+ d 1))
%      (movei r 1)
%      (lsh r 0 d)
%      (hrrzs 0 tt)
%      (calli tt 33)
%      (127_27. tt tt)
%      (127_27. r r)
%      (fdv tt r)
%      (jrst 0 float1)
%()
 
(DefMacro status (a)
  % Status with argument 'GCTIME returns time spent by the garbage
  % collector.  We use psl's gctime!*, which is in microseconds.
  (if (eq a 'gctime) 'gctime!*))
 
% Runtime is what is returned by PSL's time function.  Except they
% expect in nanoseconds or something.  PSL returns in microseconds.
(de runtime ()
 (time))
 
% Wholine time.  Don't know what this is.
(de ttime ()
  0)
 
(de dtime ()
  % Return elapsed time in seconds.  A real kludge, have to pick it up from
  % the date and time string.
  (prog (dt hour min sec)
    (setf dt (date-and-time))
    % format is "05-mar-84 09:49:50"
    (setf hour (read-from-string (sub dt 10 1)))
    (setf min (read-from-string (sub dt 13 1)))
    (setf sec (read-from-string (sub dt 16 1)))
    (return (+ sec (* 60 (+ min (* 60 hour)))))))
 
% MacLisp's floating-point divide.
(de /$ (a b)
  (/ a b))
 
% MacLisp's floating-point plus.
(de +$ (a b)
  (+ a b))
 
%;;;THE REAL END
 
(de set-heap-size (x) nil)

(faslend)
 
 
(quit)
 
