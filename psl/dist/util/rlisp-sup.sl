%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:RLISP-SUP.SL 
% Description:  
% Author:       
% Created:      
% Modified:
% Package:      Utilities 
% Status:       Open Source: BSD License
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
% 27-May-87 (Leigh Stoller & Harold Carr)
%  Added fluid declaration of key*.
% 27-Sep-85 (Russ Fish)
%   Make "rlisp()" the default rlisp toploop and put date in banner msg.
% 26-Jan-84 1115-PST  (Nancy Kendzierski)
%   Added a comment about the 12/1/83 change (which has not yet been
%   hand coded) at the outer level where this is used.  These functions
%   were commented out, and the comment merely warns that the ARRAY call
%   must be fixed if the commentoutcode is removed.
% 02-Dec-83 19:06:24 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
% 01-Dec-83 14:24:04  Nancy Kendzierski                                   
%   Commented out "ARRAY LIST (CAR X . Y);" in arrayfn, since it won't     
%   un-rlisp.  This will have to hand-corrected later.                     
% 30-Nov-83 17:20:58  Nancy Kendzierski                                   
%   Changed COMMENT to %COMMENT so un-rlisp wouldn't throw away the comment.
% 07-Apr-83 13:34:02, Edit by KENDZIERSKI 
%   Changed !*OUTPUT and SEMIC!* to fluid from global to agree w/kernel decls.
% 13-Oct-82 10:21:02, Edit by BENSON       
%   !*INT is globally T                                                     
% 5-Oct-82 11:05:30, Edit by BENSON       
%   Changed SaveSystem to 3 arguments                                       
% 20-Sep-82 11:57:21, Edit by BENSON       
%   Added Begin1 and BeginRlisp to IgnoredInBacktrace!*                     
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

                                                                           
(compiletime
  (remprop 'showtime 'stat))

%*********************************************************************     
%	RLISP and REDUCE Support Code for NEW-RLISP / On PSL               
%********************************************************************;     
(global '(flg!*))

(global '(blockp!* cmsg!* erfg!* initl!* letl!* preclis!* vars!* !*force 
                   cloc!* !*demo !*quiet otime!* !*slin lreadfn!* tslin!* 
                   !*nat nat!*!* crchar!* ifl!* ipl!* key!* key1!* ofl!* 
                   opl!* program!* programl!* eof!* techo!* !*int !*mode 
                   !*cref !*msg !*pret !*extraecho))

(fluid '(!*defn !*echo dfprint!* key!* !*time !*backtrace cursym!* semic!* 
		!*output rlispscantable*))

%	These global variables divide into two classes. The first          
%class are those which must be initialized at the top level of the         
%program. These are as follows;                                            
(setq blockp!* nil)

%keeps track of which block is active;                                     
(setq cmsg!* nil)

%shows that continuation msg has been printed;                             
(setq eof!* nil)

%flag indicating an end-of-file;                                           
(setq erfg!* nil)

%indicates that an input error has occurred;                               
(setq initl!* '(blockp!* vars!*))

%list of variables initialized in BEGIN1;                                  
(setq key!* 'symbolic)

%stores first word read in command;                                        
(setq letl!* nil)

%used in algebraic mode for special delimiters;                            
(setq lreadfn!* nil)

%used to define special reading function;                                  
%OUTL!* := NIL;		%storage for output of input line;                 
(setq preclis!* 
      '(or and not member memq equal neq eq geq greaterp leq lessp plus 
           difference times quotient expt cons))

%precedence list of infix operators;                                       
(setq techo!* nil)

%terminal echo status;                                                     
(setq vars!* nil)

%list of current bound variables during parse;                             
(setq !*backtrace nil)

%if ON, prints a LISP backtrace;                                           
(setq !*cref nil)

%used by cross-reference program;                                          
(setq !*demo nil)

% causes a PAUSE (READCH) in COMMAND loop                                  
(setq !*echo nil)

%indicates echoing of input;                                               
(setq !*force nil)

%causes all macros to expand;                                              
(setq !*int t)

% system is interactive                                                    
%!*LOSE := T;		%determines whether a function flagged LOSE        
%is defined;                                                               
%!*MSG:=NIL;		%flag to indicate whether messages should be       
%printed;                                                                  
(setq !*nat nil)

%used in algebraic mode to denote 'natural'                                
%output. Must be on in symbolic mode to                                    
%ensure input echoing;                                                     
(setq nat!*!* nil)

%temporary variable used in algebraic mode;                                
(setq !*output t)

%used to suppress output;                                                  
(setq !*slin nil)

%indicates that LISP code should be read;                                  
(setq !*time nil)

%used to indicate timing should be printed;                                
%	 The second class are those global variables which are             
%initialized within some function, although they do not appear in that     
%function's variable list. These are;                                      
% CRCHAR!*		next character in input line                       
% CURSYM!*		current symbol (i. e. identifier, parenthesis,     
%			delimiter, e.t.c,) in input line                   
% FNAME!*		name of a procedure being read                     
% FTYPES!*		list of regular procedure types                    
% IFL!* 		input file/channel pair - set in BEGIN to NIL      
% IPL!* 		input file list- set in BEGIN to NIL               
% KEY1!*		current key-word being analyzed - set in RLIS1;    
% NXTSYM!*		next symbol read in TOKEN                          
% OFL!* 		output file/channel pair - set in BEGIN to NIL     
% OPL!* 		output file list- set in BEGIN to NIL              
% PROGRAM!*		current input program                              
% PROGRAML!*		stores input program when error occurs for a       
%			later restart                                      
% SEMIC!*		current delimiter character (used to decide        
%			whether to print result of calculation)            
% TTYPE!*		current token type;                                
% WS 			used in algebraic mode to store top level value    
% !*FORT		used in algebraic mode to denote FORTRAN output    
% !*INT 		indicates interactive system use                   
% !*MODE		current mode of calculation                        
% !*PRET		indicates REDUCE prettyprinting of input;          
(fluid '(ignoredinbacktrace!*))

(setq ignoredinbacktrace!* 
      (append ignoredinbacktrace!* '(begin1 beginrlisp)))

(compiletime
  (flag '(flagp!*!* condterpri lispfilenamep mkfil setlispscantable 
                    setrlispscantable progvr)
        'internalfunction))

(compiletime
  (progn (dm pgline (u)
           ''(1 . 1))
         nil))

% needed for LOCN                                                          
%*********************************************************************     
%			   REDUCE SUPERVISOR                               
%********************************************************************;     
% The true REDUCE supervisory function is BEGIN, again defined in          
%the system dependent part of this program. However, most of the work      
%is done by BEGIN1, which is called by BEGIN for every file                
%encountered on input;                                                     
(de flagp!*!* (u v)
  (and (idp u) (flagp u v)))

(fluid '(promptstring!*))

(fluid '(statcounter!*))

(setq statcounter!* 0)

(de rlispprompt ()
  (bldmsg "[%w] " statcounter!*))

(put 'symbolic 'promptfn 'rlispprompt)

(de begin1 ()
  (prog (mode parserr result prompt wrksp modeprint promptfn resultl 
              promptstring!*)
   a0
        (setq cursym!* '!*semicol!*)
        (setq otime!* (time))
        (go a1)
   a
        %IF NULL IFL!* AND !*INT                                           
        % THEN <<%/CRBUFLIS!* := (STATCOUNTER!* . CRBUF!*) . CRBUFLIS!*;   
        % CRBUF!* := NIL>>;                                                
   a1
        (when (and (null ifl!*) !*int)
          (setq statcounter!* (plus statcounter!* 1)))
        (when (setq promptfn (get !*mode 'promptfn))
          (setq promptstring!* (apply promptfn nil)))
   a2
        (setq parserr nil)
        %	IF !*OUTPUT AND !*INT AND NULL IFL!* AND NULL OFL!*        
        %	    AND NULL !*DEFN                                        
        %	  THEN TERPRI();                                           
        (when !*time
          (showtime))
        (when tslin!*
          (setq !*slin (car tslin!*))
          (setq lreadfn!* (cdr tslin!*))
          (setq tslin!* nil))
        (mapc initl!* (function sinitl))
        (when !*int
          (setq erfg!* nil))
        %to make editing work properly;                                    
        (when (eq cursym!* 'end)
          (go nd0))
        (setq program!* (errorset '(command) t !*backtrace))
        (condterpri)
        (when (or (atom program!*) (cdr program!*))
          (go err1))
        (setq program!* (car program!*))
        (cond ((eq program!* !$eof!$) (go nd1))
              ((eqcar program!* '!*comma!*) (go er))
              ((eq cursym!* 'end) (go nd0))
              ((eqcar program!* 'retry) (setq program!* programl!*)))
        %	 ELSE IF PROGRAM!* EQ 'ED                                  
        %	   THEN PROGN(CEDIT NIL,GO TO A2)                          
        %	 ELSE IF EQCAR(PROGRAM!*,'ED)                              
        %	   THEN PROGN(CEDIT CDR PROGRAM!*,GO TO A2);               
        (when !*defn
          (go d))
   b
        %IF !*OUTPUT AND IFL!* AND !*ECHO THEN TERPRI();                   
        (setq resultl (errorset program!* t !*backtrace))
        (cond ((or (atom resultl) (cdr resultl) erfg!*) (go err2))
              (!*defn (go a)))
        (setq result (car resultl))
        (if (and (idp key!*) (eq (get key!* 'stat) 'modestat))
          (setq mode key!*)
          (setq mode !*mode))
        (when (or (null !*output) (and ifl!* !*quiet))
          (go c))
        (when (eq semic!* '!;)
          (setq modeprint (or (get mode 'modeprinfn) 'printwithfreshline))
          %	  IF NOT FLAGP(MODE,'NOTERPRI) THEN                        
          %	    TERPRI();                                              
          (apply modeprint resultl))
   c
        (when (setq wrksp (get mode 'workspace))
          (set wrksp result))
        (go a)
   d
        (cond (erfg!* (go a))
              ((or (flagp!*!* key!* 'ignore) (eqcar program!* 'quote)) 
               (go b)))
        (when program!*
          (dfprint program!*))
        (if (flagp!*!* key!* 'eval)
          (go b)
          (go a))
   nd0
        (comm1 'end)
   nd1
        (setq eof!* nil)
        (cond ((null ipl!*) %terminal END;                                  
               (prog nil
                     (when ofl!*
                       (wrs nil))
                aa
                     (when (null opl!*)
                       (return (setq ofl!* nil)))
                     (close (cdar opl!*))
                     (setq opl!* (cdr opl!*))
                     (go aa))))
        (return nil)
   err1
        (cond ((or eof!* (eq program!* !$eof!$)) (go nd1))
              ((eq program!* 'extra! begin) (go a))
              (t %	 ELSE IF PROGRAM!* EQ !*!*ESC THEN GO TO A0         
                 (go er1)))
   er
        (lprie (if (null (atom (cadr program!*)))
                 (list (caadr program!*) "UNDEFINED")
                 "SYNTAX ERROR"))
   er1
        (setq parserr t)
        (go err3)
   err2
        (setq programl!* program!*)
   err3
        (resetparser)
        %	IF NULL ERFG!* OR ERFG!* EQ 'HOLD                          
        %	 THEN LPRIE "ERROR TERMINATION *****";                     
        (setq erfg!* t)
        (when (null !*int)
          (go e))
        (setq result (pause1 parserr))
        (when result
          (return (null (eval result))))
        (setq erfg!* nil)
        (go a)
   e
        (setq !*defn t)
        %continue syntax analyzing but not evaluation;                     
        (setq !*echo t)
        (when (null cmsg!*)
          (lprie "CONTINUING WITH PARSING ONLY ..."))
        (setq cmsg!* t)
        (go a)))

(de condterpri ()
  (and !*output !*echo !*extraecho (or (null !*int) ifl!*) (null !*defn) 
       (greaterp (posn) 0) (terpri)))

(commentoutcode (progn (de assgnl (u)
                         (cond ((or (atom u) 
                                 (null (memq (car u) '(setk setq setel))))
                                nil)
                               ((atom (cadr u)) 
                                (cons (mkquote (cadr u)) 
                                 (assgnl (caddr u))))
                               (t (cons (cadr u) (assgnl (caddr u))))))
                       nil))

(de dfprint (u)
  %Looks for special action on a form, otherwise prettyprints it;          
  (cond (dfprint!* (apply dfprint!* (list u)))
        %    ELSE IF CMSG!* THEN NIL                                       
        ((null (eqcar u 'progn)) (printf "%f") (prettyprint u))
        (t (prog nil
            a
                 (setq u (cdr u))
                 (when (null u)
                   (return nil))
                 (dfprint (car u))
                 (go a)))))

(de showtime ()
  (prog (x)
        (setq x otime!*)
        (setq otime!* (time))
        (setq x (difference otime!* x))
        %      TERPRI();                                                   
        (prin2 "TIME: ")
        (prin2 x)
        (prin2t " MS")))

(de sinitl (u)
  (set u (get u 'initl)))

(flag '(in out on off shut) 'ignore)

%*********************************************************************     
%	       IDENTIFIER AND RESERVED CHARACTER READING                   
%********************************************************************;     
%	 The function TOKEN defined below is used for reading              
%identifiers and reserved characters (such as parentheses and infix        
%operators). It is called by the function SCAN, which translates           
%reserved characters into their internal name, and sets up the output      
%of the input line. The following definitions of TOKEN and SCAN are        
%quite general, but also inefficient. THE READING PROCESS CAN OFTEN        
%BE SPEEDED UP BY A FACTOR OF AS MUCH AS FIVE IF THESE FUNCTIONS           
%(ESPECIALLY TOKEN) ARE CODED IN ASSEMBLY LANGUAGE;                        
(commentoutcode (progn (de prin2x (u)
                         (setq outl!* (cons u outl!*)))
                       (de ptoken ()
                         (prog (x)
                               (setq x (token))
                               (when (and (eq x '!)) (eqcar outl!* '! ))
                                 (setq outl!* (cdr outl!*)))
                               %an explicit reference to OUTL!* used here; 
                               (prin2x x)
                               (when (null (or (eq x '!() (eq x '!))))
                                 (prin2x '! ))
                               (return x)))
                       nil))

(de mkex (u)
  (if (or (not (eq !*mode 'algebraic)) (eqcar u 'aeval))
    u
    nil))

%APROC(U,'AEVAL);                                                          
(de mksetq (u v)
  (list 'setq u v))

(de mkvar (u v)
  u)

(de rplcdx (u v)
  (if (equal (cdr u) v)
    u
    (rplacd u v)))

(de reform (u)
  (cond ((or (atom u) (eq (car u) 'quote)) u)
        ((eq (car u) 'cond) (cons 'cond (reform (cdr u))))
        ((eq (car u) 'prog) 
         (rplcdx (cdr u) (mapcar (cddr u) (function reform))) u)
        ((eq (car u) 'lambda) (rplaca (cddr u) (reform (caddr u))) u)
        ((and (eq (car u) 'function) (atom (cadr u))) 
         (prog (x)
               (cond ((and (null !*cref) (setq x (get (cadr u) 'smacro))) 
                      (return (list 'function x)))
                     ((or (get (cadr u) 'nmacro) (macrop (cadr u))) 
                      (rederr "MACRO USED AS FUNCTION"))
                     (t (return u)))))
        %    ELSE IF CAR U EQ 'MAT THEN RPLCDX(U,MAPC2(CDR U,FUNCTION REFORM))
                                                                           
        ((atom (car u)) 
         (prog (x y)
               (when (and (setq y (getd (car u))) (eq (car y) 'macro) 
                      (expandq (car u)))
                 (return (reform (apply (cdr y) (list u)))))
               (setq x (reformlis (cdr u)))
               (cond ((null (idp (car u))) (return (cons (car u) x)))
                     ((and (or (null !*cref) (expandq (car u))) 
                       (setq y (get (car u) 'nmacro)))
                      (return 
                       (apply y (if (flagp (car u) 'nospread)
                          (list x)
                          x))))
                     ((and (or (null !*cref) (expandq (car u))) 
                       (setq y (get (car u) 'smacro)))
                      (return (sublis (pair (cadr y) x) (caddr y))))
                     (t %we could use an atom SUBLIS here (eg, SUBLA);     
                        (return (progn (rplcdx u x)
                                       u))))))
        (t (cons (reform (car u)) (reformlis (cdr u))))))

(de reformlis (u)
  (if (atom u)
    u
    (cons (reform (car u)) (reformlis (cdr u)))))

(de expandq (u)
  %determines if macro U should be expanded in REFORM;                     
  (or (flagp u 'expand) (and !*force (null (flagp u 'noexpand)))))

(commentoutcode (progn (de arrayp (u)
                         (get u 'array))
                       (de gettype (u)
                         %it might be better to use a table here for more generality;
                                                                           
                         (cond ((null (atom u)) 'form)
                               ((numberp u) 'number)
                               ((arrayp u) 'array)
                               ((getd u) 'procedure)
                               ((globalp u) 'global)
                               ((fluidp u) 'fluid)
                               ((get u 'matrix) 'matrix)
                               ((or (get u 'simpfn) (get u 'msimpfn)) 
                                'operator)
                               ((flagp u 'parm) 'parameter)
                               (t nil)))
                       (de getels (u)
                         (getel (cons (car u) (evlis (cdr u)))))
                       (de setels (u v)
                         (setel (cons (car u) (evlis (cdr u))) v))
                       nil))

%. Top Level Entry Function                                                
%. --- Special Flags -----                                                 
% !*DEMO -                                                                 
(de command ()
  (prog (x y)
        (when (and !*demo (setq x ifl!*))
          (terpri)
          (rds nil)
          (readch)
          (rds (cdr x)))
        %	IF EDIT!* THEN EDITLINE() ELSE IF FLG!* THEN GO TO A;      
        (if !*slin
          (progn (setq key!* (setq semic!* '!;))
                 (setq cloc!* (if ifl!*
                         (cons (car ifl!*) (pgline))
                         nil))
                 (setq x (if lreadfn!*
                         (apply lreadfn!* nil)
                         (read)))
                 (when (eq key!* '!;)
                   (setq key!* (if (atom x)
                           x
                           (car x)))))
          (progn (setrlispscantable)
                 (makeinputavailable)
                 (scan)
                 (setq cloc!* (if ifl!*
                         (cons (car ifl!*) (pgline))
                         nil))
                 (setq key!* cursym!*)
                 (setq x (xread1 nil))))
        (when !*pret
          (terpri)
          (rprint x))
        (setq x (reform x))
        (cond ((and cloc!* (not (atom x)) (memq (car x) '(de df dm))) 
               (put (cadr x) 'locn cloc!*))
              ((and cloc!* (eqcar x 'progn) (cddr x) 
                    (not (atom (caddr x))) (memq (caaddr x) '(de df dm)))
               (put (cadr (caddr x)) 'locn cloc!*)))
        %	IF IFL!*='(DSK!: (INPUT . TMP)) AND                        
        %	   (Y:= PGLINE()) NEQ '(1 . 0)                             
        %	  THEN LPL!*:= Y;	%use of IN(noargs);                
        (when (or (null (idp key!*)) 
                  (and (null (eq (get key!* 'stat) 'modestat)) 
                       (null (eq key!* 'ed))))
          (setq x (mkex x)))
   a
        (when (and flg!* ifl!*)
          (prog nil
                (close (cdr ifl!*))
                (setq ipl!* (delete ifl!* ipl!*))
                (if ipl!*
                  (rds (cdar ipl!*))
                  (rds nil))
                (setq ifl!* nil)))
        (setq flg!* nil)
        (return x)))

(off r2i)

(de rprint (u)
  % Autoloading stub                                                       
  (progn (load rprint)
         (rprint u)))

(on r2i)

%*********************************************************************     
%			   GENERAL FUNCTIONS                               
%********************************************************************;     
%SYMBOLIC PROCEDURE MAPC2(U,V);                                            
%   %this very conservative definition is to allow for systems with        
%   %poor handling of functional arguments, and because of bootstrap-      
%   %ping difficulties;                                                    
%   BEGIN SCALAR X,Y,Z;                                                    
%   A: IF NULL U THEN RETURN REVERSIP Z;                                   
%      X := CAR U;                                                         
%      Y := NIL;                                                           
%   B: IF NULL X THEN GO TO C;                                             
%      Y := APPLY(V,LIST CAR X) . Y;                                       
%      X := CDR X;                                                         
%      GO TO B;                                                            
%   C: U := CDR U;                                                         
%      Z := REVERSIP Y . Z:                                                
%      GO TO A                                                             
%   END;                                                                   
%*********************************************************************     
%	 FUNCTIONS FOR PRINTING DIAGNOSTIC AND ERROR MESSAGES              
%********************************************************************;     
(de lprie (u)
  (errorprintf "***** %L" u)
  (setq erfg!* t))

(de lprim (u)
  (and !*msg (errorprintf "*** %L" u)))

(de rederr (u)
  (prog nil
        %TERPRI();                                                         
        (lprie u)
        (error 99 nil)))

(de progvr (var)
  (cond ((not (atom var)) nil)
        ((or (numberp var) (flagp var 'share) 
             (and (not (eq !*mode 'algebraic)) (fluidp var)))
         t)
        (t (prog (x)
                 (when (setq x (get var 'datatype))
                   (return (car x)))))))

(de mkarg (u)
  (cond ((null u) nil)
        ((atom u) (if (progvr u)
           u
           (mkquote u)))
        ((eq (car u) 'quote) (mkquote u))
        ((and (flagp!*!* (car u) 'nochange) (not (flagp key1!* 'quote))) u)
        (t (cons 'list (mapcar u (function mkarg))))))

(de mkprog (u v)
  (cons 'prog (cons u v)))

(commentoutcode (progn (de setdiff (u v)
                         (if (null v)
                           u
                           (setdiff (delete (car v) u) (cdr v))))
                       (de remtype (varlis)
                         (prog (x y)
                               (setq vars!* (setdiff vars!* varlis))
                          a
                               (when (null varlis)
                                 (return nil))
                               (setq x (car varlis))
                               (setq y (cdr (get x 'datatype)))
                               (if y
                                 (put x 'datatype y)
                                 (progn (remprop x 'datatype)
                                        (remflag (list x) 'parm)))
                               (setq varlis (cdr varlis))
                               (go a)))
                       nil))

(deflist '((lisp symbolic)) 'newnam)

(flag '(for) 'nochange)

(flag '(repeat) 'nochange)

(flag '(while) 'nochange)

% The ARRAY LIST call (see comment below) must be fixed if
% the following COMMENTOUTCODE is removed.
(commentoutcode (progn %COMMENT LISP arrays built with computed index into a vector;
                                                                           
                       % FLUID '(U V X Y N); %/ Fix for MAPC closed compile
                       (de array (u)
                         (foreach x in u do 
                          (prog (y)
                                (when (or (null (cdr x)) 
                                       (not (idp (car x))))
                                  (rederr 
                                   (list x "CANNOT BECOME AN ARRAY")))
                                (setq y 1)
                                (foreach v in (cdr x) do 
                                 (setq y (times y (plus v 1))))
                                (put (car x) 'array 
                                 (mkvect (difference y 1)))
                                (put (car x) 'dimension (add1lis (cdr x))))))
                       (de cindx!* (u)
                         (prog (n v)
                               (setq n 0)
                               (when (null (setq v (dimension (car u))))
                                 (rederr (list (car u) "NOT AN ARRAY")))
                               (foreach y in (cdr u) do 
                                (progn (when (null v)
                                         (rederr 
                                          (list u "TOO MANY INDICES")))
                                       (when (or (lessp y 0) 
                                              (greaterp y 
                                               (difference (car v) 1)))
                                         (rederr 
                                          (list u "INDEX OUT OF RANGE")))
                                       (setq n (plus y (times n (car v))))
                                       (setq v (cdr v))))
                               (when v
                                 (rederr (list u "TOO FEW INDICES")))
                               (return n)))
                       %UNFLUID '(U V X Y N); %/ Fix for MAPC closed compile
                                                                           
                       (de getel (u)
                         (getv (arrayp (car u)) (cindx!* u)))
                       (de setel (u v)
                         (putv (arrayp (car u)) (cindx!* u) v))
                       (de dimension (u)
                         (get u 'dimension))
                       %COMMENT further support for REDUCE arrays;         
                       (de typechk (u v)
                         (prog (x)
                               (cond ((or (eq (setq x (gettype u)) v) 
                                       (eq x 'parameter))
                                      (lprim 
                                       (list u "ALREADY DEFINED AS" v)))
                                     (x (rederr (list x u "INVALID AS" v))))))
                       (de numlis (u)
                         (or (null u) 
                          (and (numberp (car u)) (numlis (cdr u)))))
                       (compiletime
                         (remprop 'array 'stat))
                       %for bootstrapping purposes;                        
                       (de arrayfn (u)
                         (prog (x y)
                          a
                               (when (null u)
                                 (return nil))
                               (setq x (car u))
                               (cond ((atom x) (rederr "SYNTAX ERROR"))
                                     ((typechk (car x) 'array) (go b)))
                               (setq y (if (not (eq !*mode 'algebraic))
                                  (!*evlis (cdr x))
                                  (revlis (cdr x))))
                               (unless (numlis y)
                                 (lprie 
                                  (list "INCORRECT ARRAY ARGUMENTS FOR" 
                                   (car x))))
                               %  The following statement will have to be hand-coded into lisp syntax.
                               %  ARRAY LIST (CAR X . Y);            
                          b
                               (setq u (cdr u))
                               (go a)))
                       (de add1lis (u)
                         (if (null u)
                           nil
                           (cons (plus (car u) 1) (add1lis (cdr u)))))
                       nil))

%*********************************************************************     
%*********************************************************************     
%	REDUCE FUNCTIONS FOR HANDLING INPUT AND OUTPUT OF FILES            
%*********************************************************************     
%********************************************************************;     
(global '(contl!*))

(dm in (u)
  (list 'evin (mkquote (cdr u))))

(de evin (u)
  (prog (chan echo echop extn oslin olrdfn otslin)
        (setq echop (eq semic!* '!;))
        (setq echo !*echo)
        (when (null ifl!*)
          (setq techo!* !*echo))
        %terminal echo status;                                             
        (setq oslin !*slin)
        (setq olrdfn lreadfn!*)
        (setq otslin tslin!*)
        (setq tslin!* nil)
        (foreach fl in u do 
                 (progn (setq chan (open fl 'input))
                        (setq ifl!* (cons fl chan))
                        (setq ipl!* (cons ifl!* ipl!*))
                        (rds (if ifl!*
                           (cdr ifl!*)
                           nil))
                        (setq !*echo echop)
                        (setq !*slin t)
                        (if (lispfilenamep fl)
                          (setq lreadfn!* nil)
                          (setq !*slin oslin))
                        (begin1)
                        (when !*slin
                          (resetparser))
                        (when chan
                          (close chan))
                        (setq lreadfn!* olrdfn)
                        (setq !*slin oslin)
                        (if (eq fl (caar ipl!*))
                          (setq ipl!* (cdr ipl!*))
                          (rederr (list "FILE STACK CONFUSION" fl ipl!*)))))
        (setq !*echo echo)
        %restore echo status;                                              
        (setq tslin!* otslin)
        (if (and ipl!* (null contl!*))
          (setq ifl!* (car ipl!*))
          (setq ifl!* nil))
        (rds (if ifl!*
               (cdr ifl!*)
               nil))
        (return nil)))

(commentoutcode (progn (de redin (f)
                         (prog (!*echo !*output !*slin chan)
                               (setq ipl!* 
                                (cons 
                                 (setq ifl!* 
                                  (cons f (setq chan (open f 'input))))
                                 ipl!*))
                               (rds chan)
                               (begin1)
                               (setq ipl!* (cdr ipl!*))
                               (rds (if (not (null ipl!*))
                                  (cdr (first ipl!*))
                                  nil))))
                       nil))

(de lispfilenamep (s)
  %. Look for ".SL" or ".LSP"                                              
  (prog (c i ss)
        (setq ss (size s))
        (when (lessp ss 3)
          (return nil))
        (setq i ss)
   loop
        (when (lessp i 0)
          (return nil))
        (when (equal (indx s i) (char '!.))
          (go loopend))
        (setq i (difference i 1))
        (go loop)
   loopend
        (setq i (plus i 1))
        (setq c (difference ss i))
        (unless (member c '(1 2))
          (return nil))
        (setq c (subseq s i (plus ss 1)))
        (return (if (member c '("SL" "sl" "LSP" "lsp" "Sl" "Lsp"))
                  t
                  nil))))

(dm out (u)
  (list 'evout (mkquote (cdr u))))

(de evout (u)
  %U is a list of one file;                                                
  (prog (chan fl x)
        (cond ((null u) (return nil))
              ((eq (car u) 't) (return (progn (wrs (setq ofl!* nil))
                                              nil))))
        (setq fl (mkfil (car u)))
        (if (not (setq x (assoc fl opl!*)))
          (progn (setq chan (open fl 'output))
                 (setq ofl!* (cons fl chan))
                 (setq opl!* (cons ofl!* opl!*)))
          (setq ofl!* x))
        (wrs (cdr ofl!*))))

(dm shut (u)
  (list 'evshut (mkquote (cdr u))))

(de evshut (u)
  %U is a list of names of files to be shut;                               
  (prog (fl fl1)
   a
        (cond ((null u) (return nil))
              ((setq fl1 (assoc (setq fl (mkfil (car u))) opl!*)) (go b))
              ((not (setq fl1 (assoc fl ipl!*))) 
               (rederr (list fl "NOT OPEN"))))
        (if (neq fl1 ifl!*)
          (progn (close (cdr fl1))
                 (setq ipl!* (delete fl1 ipl!*)))
          (rederr (list "CANNOT CLOSE CURRENT INPUT FILE" (car fl))))
        (go c)
   b
        (setq opl!* (delete fl1 opl!*))
        (when (equal fl1 ofl!*)
          (setq ofl!* nil)
          (wrs nil))
        (close (cdr fl1))
   c
        (setq u (cdr u))
        (go a)))

%/ removed STAT property                                                   
%*********************************************************************     
%		FUNCTIONS HANDLING INTERACTIVE FEATURES                    
%********************************************************************;     
%GLOBAL Variables referenced in this Section;                              
(setq contl!* nil)

(de pause ()
  (pause1 nil))

(de pause1 (bool)
  (prog nil
        %      IF BOOL THEN                                                
        %	IF NULL IFL!*                                              
        %	 THEN RETURN IF !*INT AND GETD 'CEDIT AND YESP 'EDIT!?     
        %		       THEN CEDIT() ELSE                           
        %		       NIL                                         
        %	 ELSE IF GETD 'EDIT1 AND ERFG!* AND CLOC!* AND YESP 'EDIT!?
        %	  THEN RETURN <<CONTL!* := NIL;                            
        %	   IF OFL!* THEN <<LPRIM LIST(CAR OFL!*,'SHUT);            
        %			   CLOSE CDR OFL!*;                        
        %			   OPL!* := DELETE(OFL!*,OPL!*);           
        %			   OFL!* := NIL>>;                         
        %	   EDIT1(CLOC!*,NIL)>>                                     
        %	 ELSE IF FLG!* THEN RETURN (EDIT!* := NIL);                
        (when (or (null ifl!*) (yesp 'cont!?))
          (return nil))
        (setq contl!* (cons ifl!* (cons !*echo contl!*)))
        (rds (setq ifl!* nil))
        (setq !*echo techo!*)))

(de cont ()
  (prog (fl techo)
        (cond (ifl!* (return nil))
              %CONT only active from terminal;                             
              ((null contl!*) (rederr "NO FILE OPEN")))
        (setq fl (car contl!*))
        (setq techo (cadr contl!*))
        (setq contl!* (cddr contl!*))
        (if (equal fl (car ipl!*))
          (progn (setq ifl!* fl)
                 (rds (if fl
                        (cdr fl)
                        nil))
                 (setq !*echo techo))
          (progn (setq eof!* t)
                 (lprim (list fl "NOT OPEN"))
                 (error 99 nil)))))

%/DEFLIST ('((PAUSE ENDSTAT) (CONT ENDSTAT) (RETRY ENDSTAT)),'STAT);       
%/PUT('RETRY,'STAT,'ENDSTAT);                                              
(flag '(cont) 'ignore)

%******** "rend" fixups                                                    
(global '(!*int contl!* date!* !*mode imode!* crchar!* !*slin lreadfn!*))

(remflag '(beginrlisp) 'go)

%---- Merge into XREAD1 in command ----                                    
% Shouldnt USE Scan in COMMAND, since need change Parser first             
(fluid '(!*pecho))

(de xread1 (x)
  %. With Catches                                                          
  (prog (form!*)
        (setq form!* (parse0 0 nil))
        (when !*pecho
          (prin2t (list "parse>" form!*)))
        (return form!*)))

(de xread (x)
  (prog (form!*)
        (makeinputavailable)
        (setq form!* (parse0 0 t))
        (when !*pecho
          (prin2t (list "parse>" form!*)))
        (return form!*)))

(setq !*pecho nil)

(de beginrlisp ()
  (prog (a b promptstring!*)
        %/	!*BAKGAG := NIL;                                           
        (setq !*int t)
        (setq !*echo nil)
        (setq a !*slin)
        (setq !*slin (setq lreadfn!* nil))
        (setq contl!* 
              (setq ifl!* (setq ipl!* (setq ofl!* (setq opl!* nil)))))
        (setq !*mode imode!*)
        (setq crchar!* '! )
        %/	RDSLSH NIL;                                                
        %/	SETPCHAR '!*;                                              
        (setrlispscantable)
        %	IF SYSTEM!* NEQ 0 THEN CHKLEN();                           
        (when (eq date!* nil)
          (if a
            (progn (prin2 "Entering RLISP...")
                   (go b))
            (go a)))
        %/	IF FILEP '((REDUCE . INI)) THEN <<IN REDUCE.INI; TERPRI()>>;
                                                                           
        %/	ERRORSET(QUOTE LAPIN "PSL.INI", NIL, NIL);	% no error if not there
                                                                           
        (prin2 date!*)
        (setq date!* nil)
        %	IF SYSTEM!* NEQ 1 THEN GO TO A;                            
        %	IF !*HELP THEN PRIN2 "For help, type HELP()";              
   b
        (terpri)
   a
        (begin1)
        %	TERPRI();                                                  
        (setq !*slin t)
        %/        RDSLSH NIL;                                              
        (setlispscantable)
        (prin2t "Entering LISP...")))

(flag '(beginrlisp) 'go)

(putd 'begin 'expr (cdr (getd 'beginrlisp)))

(de mkfil (u)
  %converts file descriptor U into valid system filename;                  
  u)

(de newmkfil (u)
  %converts file descriptor U into valid system filename;                  
  u)

(de setpchar (c)
  %. Set prompt, return old one                                            
  (prog (oldprompt)
        (setq oldprompt promptstring!*)
        (setq promptstring!* 
              (cond ((stringp c) c)
                    ((idp c) (copystring (id2string c)))
                    (t (bldmsg "%w" c))))
        (return oldprompt)))

%COMMENT Some Global Variables required by REDUCE;                         
%GLOBAL '(!*!*ESC);                                                        
%                                                                          
%!*!*ESC := 'ESC!.NOT!.NEEDED!.NOW;   %to make it user settable (used to be a NEWNAM);
                                                                           
%COMMENT The remaining material in this file introduces extensions         
%	 or redefinitions of code in the REDUCE source files, and          
%	 is not really necessary to run a basic system;                    
(de setrlispscantable ()
  (setq currentreadmacroindicator!* 'rlispreadmacro)
  (setq currentscantable!* rlispscantable!*))

(de setlispscantable ()
  (setq currentreadmacroindicator!* 'lispreadmacro)
  (setq currentscantable!* lispscantable!*))

(putd 'lispsavesystem 'expr (cdr (getd 'savesystem)))

(de savesystem (s f i)
  %. Set up for saving EXE file                                            
  (progn (setq statcounter!* 0)
         (remd 'main)
         (copyd 'main 'rlispmain)
         (setq date!* (bldmsg "%w, %w" s (date)))
         (lispsavesystem s f i)))

(de rlispmain ()
  (rlisp)
  (standardlisp))

(de rlisp ()
  % Uses new top loop                                                      
  (progn (setrlispscantable)
         (toploop 'reformxread 'printwithfreshline 'eval "rlisp" 
                  lispbanner!*)))

(de reformxread ()
  (reform (xread t)))

(setq !*raise t)

%IF GETD 'ADDSQ THEN IMODE!* := 'ALGEBRAIC ELSE IMODE!* := 'SYMBOLIC;      
(setq imode!* 'symbolic)

(setq tslin!* nil)

(setq !*msg t)

% End of file.

