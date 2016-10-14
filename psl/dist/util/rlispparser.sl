%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU: RLISPPARSER.SL 
% Description:  RLISP parser based on Nordstrom and Pratt model 
% Author:       Martin Griss and Eric Benson 
% Created:      May 1981 
% Modified:     02-Dec-83 19:04:21 (Nancy Kendzierski) 
% Package:      Utilities 
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
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 11-Sep-87 (Russ Fish)
%  Added rLet and rLet* .
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of in* and out*.
% 27-May-87 (Leigh Stoller & Harold Carr)
%  Added fluid declaration of key*.
% Mon Nov  3 1986 (Tim Mueller)
%   Added Fish's changes for 'for' loops and defmacro back in.
% 02-Dec-83 19:04:21 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
% 01-Dec-83 18:23:22  Nancy Kendzierski                                    
%   Modified .sl version (result of un-rlisp) of (setq rlispreadscantable*  
%   '[17 11 11 11 11 11 11 11 11 17 17 11 17 17 11 11   etc. to not be on   
%   only one line, since this breaks the RCOMPARE reader.                   
% Edit by Nancy Kendzierski, 07 Apr 1983 1337-PST                          
%   Changed SEMIC!* to fluid (also in rlisp-support) to match kernel decls.  
% Edit by Cris Perdue, 28 Jan 1983 2038-PST                                
%   Occurrences of "dipthong" changed to "diphthong"                         
% 16-Dec-82 12:11:15, Edit by KESSLER
%   Make SEMIC!* a Global (as in rlisp-support), so it won't be made fluid in 
%   compilation of Scan.                                                    
% 13-Dec-82 13:14:36, Edit by OTHMER       
%   Flagged EMB as 'FTYPE so debug functions will work                      
% 17-Mar-82 02:36:14, Edit by BENSON       
%   Finally infix as prefix works!!!                                        
% 14-Jan-82 13:16:34, Edit by BENSON       
%   Added JOIN to for each                                                  
% 30-Dec-81 01:01:30, Edit by BENSON       
%   Unfixed infix as prefix.  Have to check to make sure the thing is an arglist
% 28-Dec-81 15:22:37, Edit by BENSON       
%   fixed LAMBDA();...                                                      
% 28-Dec-81 15:21:43, Edit by BENSON       
%   Infix operators used as prefix are parsed correctly                     
% 28-Dec-81 14:44:47, Edit by BENSON       
%   Removed assign-op in favor of SetF                                      
% 5-Feb-82 07:17:34, Edit by GRISS        
%   Add NE as infix                                                         
%                                                                          
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Known Bugs and Problems:                                                 
%	Procedure TEMPLATES parsed at wrong precendence, so                
%	procedure x/y; is ok                                               
%	procedure (x/Y) fails!                                             
%                                                                          
%	IF a Then B;  ELSE c;  parses badly, doesnt catch ELSE             
%	QUOTIENT(A,B) parses as RECIP(A)                                   
%                                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
  (flag '(definebopx defineropx doinfixasprefix isopop doprefix doinfix 
                     makelocals mkquotlist precset infixop prefixop 
                     rlispread remsemicol symerr ratomhook commentpart)
        'internalfunction))

(fluid '(cursym* key* *insidestructureread semic*))
(fluid '(in* out*))

(setq cursym* '! )

(global '(toktype*))

(de symerr (x y)
  (stderror (bldmsg "Syntax error %r" x)))

(de scan ()
  (prog (x)
   a
        (setq cursym* (ratomhook))
        (cond ((eq toktype* 3) %/ Also a R,                                 
               (cond ((eq cursym* '!') 
                      (setq cursym* (list 'quote (rlispread))))
                     ((setq x (get cursym* 'newnam-op))
		      (when (eq x '*semicol*)
                        (setq semic* cursym*))
		      (setq cursym* x)))))
        (when (setq x (get cursym* 'newnam))
          (setq cursym* x))
        (when (eq cursym* 'comment)
          (while (not (memq (readch) '(; $)))
            nil)
          (go a))
        (return cursym*)))

(de resetparser ()
  (setq cursym* '! ))

%-----------------------------------------------------------------         
%--- Boot strap functions, move to build file-----;                        
(fluid %. Name of Grammer being defined                                     
       '(defprefix definfix gramprefix graminfix))

%. Name of grammer running                                                 
(setq defprefix 'rlispprefix)

%. Key for Grammer being defined                                           
(setq definfix 'rlispinfix)

%. Key for Grammer being defined                                           
(setq gramprefix 'rlispprefix)

%. Key for Grammer being defined                                           
(setq graminfix 'rlispinfix)

%. Key for Grammer being defined                                           
(df definebop (u)
  (definebopx u))

(de definebopx (u)
  % u=(opname, lprec, rprec,function)                                      
  (prog (w y)
        (setq w (eval (car u)))
        % Opname; Remove ' which used to suppress OP props                 
        (setq y % Lprec                                                     
              (cons (eval (cadr u)) % Rprec                                 
                    (cons (eval (caddr u)) 
                     (cond ((null (cdddr u)) nil)
                           % Default function is NIL                       
                           ((atom (cadddr u)) (cadddr u))
                           (t (list 'lambda '(x y) (cadddr u)))))))
        (put w definfix y)))

% Binop in CAR                                                             
(de infixop (u)
  % Used also in REDUCE                                                    
  (get u graminfix))

(de infixprec (u)
  % Used in REDUCE MathPrint                                               
  (prog (v)
        (when (null (setq v (infixop u)))
          (return nil))
        (when (and (pairp v) (numberp (car v)))
          (return (car v)))
        (return nil)))

(df definerop (u)
  (defineropx u))

(de defineropx (u)
  % u=(opname,lprec,function)                                              
  (prog (w y)
        (setq w (eval (car u)))
        % Name, remove ' mark                                              
        (setq y % Lprec                                                     
              (cons (eval (cadr u)) 
                    (cond ((null (cddr u)) nil)
                          % Default is NIL                                 
                          ((atom (caddr u)) (caddr u))
                          (t % function name                                
                           (list 'lambda '(x) (caddr u))))))
        %                                                                  
        (put w defprefix y)))

(de prefixop (u)
  (get u gramprefix))

(fluid '(op))

%. Current TOKEN being studied                                             
% ***** General Parser Functions *****;                                    
(de parse0 (rp prescan)
  %. Collect Phrase to LP<RP                                               
  (prog (cursym u)
        %/      IF COMPR!* AND CURSYM!* EQ CAAR COMPR!*                    
        %/        THEN <<CURSYM := CAR COMPR!*; COMPR!* := CDR COMPR!*>>;  
        (setq op (if prescan
                (scan)
                cursym*))
        %/      IF PRESCAN AND COMPR!* AND CURSYM!* EQ CAAR COMPR!*        
        %/        THEN <<CURSYM := CAR COMPR!*; COMPR!* := CDR COMPR!*>>;  
        (setq u (rdright rp op))
        %/      IF CURSYM THEN RPLACA(CURSYM,U);                           
        (return u)))

(de rdright (rp y)
  %. Collect phrase until OP with LP<RP                                    
  % Y is starting TOKEN.                                                   
  % RP=NIL - Caller applies Function to Y, without collecting RHS subphrase
  (prog (temp op1 tempscan tempop *insidestructureread)
        (setq *insidestructureread t)
        (cond ((null rp) (return y))
              %/       ELSE IF IDFLAG THEN OP := SCAN()	% Set IDFLAG if not Operator
                                                                           
              ((and (equal rp 0) (eq y '*semicol*)) (return nil))
              %/ Toplevel ; or $?                                          
              ((setq temp (prefixop y)) (setq tempscan (scan)) (if (strongerinfixop
                                                                    tempscan
                                                                    y 
                                                                    (car 
                                                                     temp))
                 (setq op tempscan)
                 (setq y 
                       (doprefix (cdr temp) y 
                        (rdright (car temp) tempscan)))))
              ((not (infixop y)) (setq op (scan)))
              %/ Binary OP in Prefix Position                              
              ((isopop op rp y) (setq op y) (setq y nil))
              (t (setq op (scan))))
        % Y:=DoINFIXasPREFIX(Y,OP:=SCAN());                                
   rdleft
        (cond %/IDFLAG OR                                                  
              ((not (setq temp (infixop op))) (if (null op)
                 (progn (setq y (list y nil))
                        (setq op (scan)))
                 (setq y (repcom y (rdright 99 op)))))
              %. Do as PREFIX                                              
              ((greaterp rp (car temp)) (return y))
              (t (setq op1 op) %/ !*ORD PROBLEM?                            
                 (setq tempscan (scan)) 
                 (cond ((and (equal tempscan '*lpar*) 
                         (not (funboundp op1)))
                        (setq op tempscan) %/ kludge to allow infix/prefix  
                        (setq tempscan (rdright (cadr temp) op)) (if (eqcar 
                                                                      tempscan
                                                                      '*comma*)
                          (setq y (list y (repcom op1 tempscan)))
                          (setq y (doinfix (cddr temp) y op1 tempscan))))
                       ((strongerinfixop tempscan op1 (cadr temp)) 
                        (setq y (list y op1)) (setq op tempscan))
                       (t 
                        (setq y 
                         (doinfix (cddr temp) y op1 
                          (rdright (cadr temp) tempscan)))))))
        (go rdleft)))

(de strongerinfixop (nextop lastop lastprec)
  (let (tempop
        matcher)
       (and (not (prefixop nextop)) (setq tempop (infixop nextop)) 
            (numberp lastprec) (numberp (car tempop)) (leq (car tempop) 6) 
            (leq (car tempop) lastprec) 
            (not (and (setq matcher (get lastop 'closer)) 
                      (eq matcher nextop)))
            (not (isopop nextop lastprec lastop)))))

(deflist '((begin end) (*lpar* *rpar*) (*lsqb* *rsqb*) (*lvec* *rvec*)) 
         'closer)

(de doinfixasprefix (lhs bop)
  (repcom lhs (rdright 99 bop)))

%. Note that PREFIX functions have next token SCANed, and get an argument, 
%. "X", that is either this TOKEN, or a complete parsed Phrase             
(de doprefix (act rop rhs)
  (if (null act)
    (list rop rhs)
    (apply act (list rhs))))

%. Note that INFIX functions have next token SCANed, and get two arguments,
%. "X" and "Y"; "X" is LHS phrase,                                         
%.  "Y"  is either the scanned TOKEN, or a complete parsed Phrase          
(de doinfix (act lhs bop rhs)
  (if (null act)
    (list bop lhs rhs)
    (apply act (list lhs rhs))))

(de isopop (xop rp y)
  %. Test for legal OP-> <-OP                                              
  (cond ((equal rp 2) (eq y '*rpar*))
        % LPAR scans for LP 2                                              
        ((and (equal rp 0) (eq xop 'end) 
              (member y '(*semicol* *colon* *rsqb* end)))
         t)
        ((memq y '(*semicol* end *rsqb*)) % Special cases in BEGIN-END      
         (or (equal rp -2) (memq xop '(*semicol* *colon* *rsqb*))))
        (t nil)))

(de parerr (x y)
  (stderror x))

(de remcom (x)
  %. (, x y z) -> (x y z)                                                  
  (if (eqcar x '*comma*)
    (cdr x)
    (list x)))

(de remsemicol (x)
  %. (; x y z) -> (x y z)                                                  
  (if (eqcar x '*semicol*)
    (cdr x)
    (list x)))

(de repcom (type x)
  %.  Create ARGLIST                                                       
  (cond ((eqcar x '*comma*) (cons type (cdr x)))
        ((eq x '*empty*) (list type))
        (t (list type x))))

%SYMBOLIC PROCEDURE SELF RHS;		%. Prefix Operator returns RHS     
%  RHS;                                                                    
(de parsenoop (x)
  (setq op (scan))
  x)

(definerop 'noop nil parsenoop)

%. Prevent TOKEN from being an OP                                          
(de mkquotlist (u)
  %this could be replaced by MKQUOTE in most cases;                        
  (cons 'list (foreach x in u collect (if (constantp x)
                         x
                         (mkquote x)))))

(de nary (xop lhs rhs)
  %. Remove repeated NARY ops                                              
  (if (eqcar lhs xop)
    (aconc lhs rhs)
    (list xop lhs rhs)))

% ***** Tables for Various Infix Operators *****;                          
(de parsecomma (x y)
  (nary '*comma* x y))

(definebop '*comma* 5 6 parsecomma)

(de parsesemicol (x y)
  (nary '*semicol* x y))

(definebop '*semicol* -1 0 parsesemicol)

(de parsesetq (lhs rhs)
  %. Extended SETQ                                                         
  (list (if (atom lhs)
          'setq
          'setf) lhs rhs))

(definebop 'setq 7 6 parsesetq)

(definebop 'cons 23 21)

(de parseplus2 (x y)
  (nary 'plus x y))

(definebop 'plus 17 18 parseplus2)

%SYMBOLIC PROCEDURE ParsePLUS1(X);                                         
%  IF EQCAR(X,'!*COMMA!*) THEN REPCOM('PLUS,X) ELSE X;                     
%                                                                          
%DEFINEROP('PLUS,26,ParsePLUS1);	%/ **** Prefix + sign...           
(definerop 'minus 26)

(de parsedifference (x)
  (cond ((numberp x) (difference 0 x))
        ((eqcar x '*comma*) (repcom 'difference x))
        (t (list 'minus x))))

(definerop 'difference 26 parsedifference)

(definebop 'difference 17 18)

(definebop 'times 19 20)

(de parsequotient (x)
  (if (not (eqcar x '*comma*))
    (list 'recip x)
    (repcom 'quotient x)))

(definerop 'quotient 26 parsequotient)

(definebop 'quotient 19 20)

(definerop 'recip 26)

(definebop 'expt 23 24)

(de parseor (x y)
  (nary 'or x y))

(definebop 'or 9 10 parseor)

%/DEFINEROP('OR,26,REPCOM('OR,X));                                         
(de parseand (x y)
  (nary 'and x y))

(definebop 'and 11 12 parseand)

%/DEFINEROP('AND,26,REPCOM('AND,X));                                       
(definerop 'not 14)

(definebop 'member 15 16)

%/DEFINEROP('MEMBER,26,REPCOM('MEMBER,X));                                 
(definebop 'memq 15 16)

%/DEFINEROP('MEMQ,26,REPCOM('MEMQ,X));                                     
(definebop 'eq 15 16)

%/DEFINEROP('EQ,26,REPCOM('EQ,X));                                         
(definebop 'equal 15 16)

(definebop 'geq 15 16)

(definebop 'greaterp 15 16)

(definebop 'leq 15 16)

(definebop 'lessp 15 16)

(definebop 'neq 15 16)

(definebop 'ne 15 16)

% ***** Tables and Definitions for Particular Parsing Constructs *****;    
% ***** IF Expression *****;                                               
(definerop 'if 4 parseif)

(definebop 'then 3 6)

(definebop 'else 3 6)

(de parseif (x)
  (prog (y z)
        (if (eq op 'then)
          (setq y (parse0 6 t))
          (parerr "IF missing THEN" t))
        (when (eq op 'else)
          (setq z (list (parse0 6 t))))
        (return (cons 'cond 
                      (cons (list x y) (if z
                         (if (eqcar (car z) 'cond)
                           (cdar z)
                           (list (cons t z)))
                         nil))))))

(de parsecase (x)
  %. Parser function                                                       
  (prog nil
        (unless (eq op 'of)
          (parerr "CASE Missing OF" t))
        (return (cons 'case (cons x (caselist))))))

(definebop 'of 3 6)

(definebop 'to 8 9)

(definerop 'case 4 parsecase)

(de caselist ()
  (prog (tg bod taglist bodlist)
   l1
        (setq op (scan))
        % Drop OF, : , etc                                                 
        (when (eq op 'end)
          (go l2))
        % For optional ; before END                                        
        (setq tg (parsetags))
        % The TAG expressions                                              
        (setq bod (parse0 6 t))
        % The expression                                                   
        (setq bodlist (cons (list tg bod) bodlist))
        (when (eq op '*semicol*)
          (go l1))
        (when (neq op 'end)
          (parerr "Expect END after CASE list" t))
   l2
        (setq op (scan))
        % Skip 'END                                                        
        (return (reverse bodlist))))

(de parsetags ()
  % Collects a single CASE-tag form; OP prescanned                         
  (prog (tg tglst)
        (setq tg (parse0 6 nil))
        % , and : below 6                                                  
        (when (eqcar tg 'to)
          (setq tg (cons 'range (cdr tg))))
        % TO is infix OP                                                   
        (when (memq tg '(otherwise default))
          (return (progn (when (neq op '*colon*)
                           (parerr "OTHERWISE in CASE must be SINGLE tag" 
                            t))
                         nil)))
        (when (eq op '*colon*)
          (return (list tg)))
        (when (eq op '*comma*)
          (return (progn (setq op (scan))
                         (setq tglst (parsetags))
                         (when (null tglst)
                           (parerr "OTHERWISE in CASE must be SINGLE tag" 
                            t))
                         (cons tg tglst))))
        (parerr "Expect one or more tags before : in CASE" t)))

% ***** Block Expression *****;                                            
(fluid '(blockenders*))

(setq blockenders* '(end *rpar* *semicol* else until *rsqb*))

(de parsebegin (x)
  (parsebegin1 (remsemicol x) (commentpart (scan) blockenders*)))

(definerop 'begin -2 parsebegin)

(definebop 'end -3 -2)

(de parsego (x)
  (cond ((eq x 'to) (list 'go (parse0 6 t)))
        (t % Why not Just SCAN?                                             
           (progn (setq op (scan))
                  (list 'go x)))))

(definerop 'go nil parsego)

(de parsegoto (x)
  (setq op (scan))
  (list 'go x))

(definerop 'goto nil parsegoto)

(de parsereturn (x)
  (let (xop)
       (list 'return (if (and (setq xop (infixop x)) (numberp (car xop)) 
                          (leq (car xop) 1))
               (progn (setq op x)
                      nil)
               (rdright 6 x)))))

(definerop 'return nil parsereturn)

(de parseexit (x)
  (let (xop)
       (list 'exit (if (and (setq xop (infixop x)) (numberp (car xop)) 
                        (leq (car xop) 1))
               (progn (setq op x)
                      nil)
               (rdright 6 x)))))

(definerop 'exit nil parseexit)

(definebop '*colon* 1 0)

(de commentpart (a l)
  (if (memq a l)
    (progn (setq op a)
           nil)
    (cons a (commentpart (scan) l))))

(de parsebegin1 (l compart)
  (prog (decls s)
        % Look for Sequence of Decls after Block Header                    
   a
        (cond ((null l) (go nd))
              %/      SCAN();                                              
              %/      IF CURSYM!* MEMQ '(INTEGER REAL SCALAR)              
              %/	THEN <<Z1:=REPCOM(CURSYM!*,PARSE0(0,NIL))>>; % Arg Decl;
                                                                           
              ((null (car l)) (setq l (cdr l)) (go a))
              ((eqcar (car l) 'declare) 
               (setq decls (append (cdar l) decls)) % Reverse order collection
                                                                            
               (setq l (cdr l)))
              (t (setq s l) (go b)))
        % Hold Body for Rescan                                             
        (go a)
   b
        (cond ((null l) (go nd))
              ((eqcar (car l) 'declare) 
               (parerr "DECLARATION invalid in BEGIN body" nil))
              ((eqcar (car l) '*colon*) (rplacd (cddar l) (cdr l)) 
               (rplacd l (cddar l)) (rplaca l (cadar l)))
              ((and (cdr l) (null (cadr l))) (rplacd l (cddr l)) 
               (setq l (cons nil l))))
        (setq l (cdr l))
        (go b)
   nd
        (return (cons 'prog (cons (makelocals decls) s)))))

(de makelocals (u)
  %. Remove Types from Reversed DECLARE                                    
  (if (null u)
    nil
    (append (cdar u) (makelocals (cdr u)))))

% ***** Procedure Expression *****;                                        
(global '(*mode))

(setq *mode 'symbolic)

(de nmodestat (vv)
  % Parses TOP-LEVEL mode ....;                                            
  (prog (tmode x)
        (setq x cursym*)
        % SCAN();                                                          
        (when (eq cursym* '*semicol*)
          (return (progn (newmode vv)
                         (setq op '*semicol*)
                         nil)))
        (when (flagp cursym* 'delim)
          (return (progn (newmode vv)
                         (setq op '*semicol*)
                         nil)))
        (setq tmode *mode)
        (setq *mode vv)
        % Local MODE change for MKPROC                                     
        (setq x (errorset '(parse0 0 nil) t *backtrace))
        (setq *mode tmode)
        (return (if (or (atom x) (cdr x))
                  nil
                  (car x)))))

(de newmode (vv)
  (print (list 'newmode (list 'quote vv)))
  (when (null vv)
    (setq vv 'symbolic))
  (setq *mode vv))

(commentoutcode (progn (fluid '(ftypes*))
                       (setq ftypes* '(expr fexpr macro))
                       (de oldprocstat ()
                         (prog (bool u type x y z)
                               (cond (fname* (go b))
                                     ((eq cursym* 'procedure) 
                                      (setq type 'expr))
                                     (t (setq type cursym*) (scan)))
                               (unless (eq cursym* 'procedure)
                                 (go c))
                               (setq x 
                                (errorset '(parse0 0 t) t *backtrace))
                               (cond ((or (atom x) (cdr x)) (go a))
                                     ((atom (setq x (car x))) 
                                      (setq x (list x))))
                               %no arguments;                              
                               (setq fname* (car x))
                               %function name;                             
                               (cond ((idp fname*) %AND NOT(TYPE MEMQ FTYPES!*);
                                                                           
                                      (cond ((or (null fname*) 
                                              (and 
                                               (setq z (gettype fname*)) 
                                               (not 
                                                (memq z 
                                                 '(procedure operator)))))
                                             (go d))
                                            ((not (getd fname*)) 
                                             (flag (list fname*) 'fnc)))))
                               %to prevent invalid use of function name in body;
                                                                           
                               (setq u (cdr x))
                               (setq y 
                                (errorset 
                                 (list 'flagtype (mkquote u) 
                                  (mkquote 'scalar))
                                 t *backtrace))
                               (if (or (atom y) (cdr y))
                                 (setq y nil)
                                 (setq y (car y)))
                               (setq x (cons (car x) y))
                          a
                               (setq z 
                                (errorset '(parse0 0 t) t *backtrace))
                               (when (and (not (atom z)) (null (cdr z)))
                                 (setq z (car z)))
                               (when (null erfg*)
                                 (setq z (procstat1 x z type)))
                               (remtype y)
                               (remflag (list fname*) 'fnc)
                               (setq fname* nil)
                               (when (and (not bool) erfg*)
                                 (rederr "ERROR TERMINATION"))
                               (return z)
                          b
                               (setq bool t)
                          c
                               (errorset '(symerr 'procedure t) t 
                                *backtrace)
                               (go a)
                          d
                               (lprie 
                                (list z fname* "INVALID AS PROCEDURE"))
                               (go a)))
                       nil))

% Some OLD Crap looks at 'STAT values!!!                                   
(deflist '((procedure procstat) (expr procstat) (fexpr procstat) 
           (emb procstat) (macro procstat) (nmacro procstat) 
           (smacro procstat))
         'stat)

(deflist '((algebraic modestat) (symbolic modestat) (syslsp modestat)) 
         'stat)

%/ STAT used for OLD style BEGIN KEY search                                
(deflist '((lisp symbolic)) 'newnam)

(definerop 'symbolic nil (nmodestat 'symbolic))

% Make it a Prefix OP                                                      
(definerop 'algebraic nil (nmodestat 'algebraic))

% Make it a Prefix OP                                                      
(definerop 'syslsp nil (nmodestat 'symbolic))

% Make it a Prefix OP                                                      
(definebop 'procedure 1 nil parseprocedure)

% Pick up MODE -- will go                                                  
(definerop 'procedure nil (parseprocedure 'expr x))

%/ Unary, use DEFAULT mode?                                                
(de parseprocedure2 (name varlis body type)
  (prog (y)
        %	IF FLAGP(NAME,'LOSE) AND (!*LOSE OR NULL !*DEFN)           
        %	  THEN RETURN PROGN(LPRIM LIST(NAME,                       
        %			    "Not defined (LOSE Flag)"),            
        %			NIL);                                      
        (cond ((setq y (get type 'functiondefiningfunction)) 
               (setq body (list y name varlis body)))
              ((setq y (get type 'immediatedefiningfunction)) 
               (return (apply y (list name varlis body))))
              (t (setq body 
                       (list 'putc (mkquote name) (mkquote type) 
                        (mkquote (list 'lambda varlis (reform body)))))))
        (return (when (neq *mode 'algebraic)
                  body))))

%/		ELSE LIST('PROGN,                                          
%/			 LIST('FLAG,MKQUOTE LIST NAME,MKQUOTE 'OPFN),      
%/			  BODY)                                            
(deflist '((expr de) (fexpr df) (macro dm) (nexpr dn) (smacro ds)) 
         'functiondefiningfunction)

(put 'emb 'immediatedefiningfunction 'embfn)

(de parseprocedure1 (nam args body argtype types)
  %/ Crude conversion of PROC to PUTD. Need make Etypes and Ftypes         
  %/  Keywords also.                                                       
  (prog (etype ftype)
        (setq etype *mode)
        (setq ftype 'expr)
        (unless (pairp types)
          (setq types (cons types nil)))
        (foreach z in types do 
                 (cond ((flagp z 'etype) (setq etype z))
                       ((flagp z 'ftype) (setq ftype z))))
        (return (parseprocedure2 nam args body ftype))))

(flag '(expr fexpr nexpr nfexpr macro smacro nmacro emb) 'ftype)

(flag '(symbolic algebraic lisp syslisp syslsp) 'etype)

(de parseprocedure (eftypes y)
  (prog (op1 z z1)
        (setq op (setq op1 (scan)))
        (cond ((eq op1 '*semicol*) (setq y (list y)))
              ((infixop op1) (setq y (list op1 y (parse0 8 t))))
              (t % Binary as Prefix                                         
                 (setq y (repcom y (parse0 8 nil)))))
        %/ Why 8                                                           
        (when (neq op '*semicol*)
          (parerr "PROCEDURE missing terminator after template" t))
        %/      SCAN();                                                    
        %/      IF CURSYM!* MEMQ '(INTEGER REAL SCALAR)                    
        %/	THEN <<Z1:=REPCOM(CURSYM!*,PARSE0(0,NIL))>>; % Arg Decl;   
        (setq z (parse0 0 t))
        (when (eqcar z 'declare)
          (setq z1 z)
          (setq z (parse0 0 t)))
        % repeated DECL?                                                   
        (return (parseprocedure1 (car y) (cdr y) z z1 eftypes))))

% Nam, args, body, arg decl, E/Fmode                                       
% ***** Left and Right Parentheses Handling *****;                         
(definerop '*lpar* nil parselpar)

(definebop '*rpar* 1 0)

(de parselpar (x)
  (prog (res)
        (if (eq x '*rpar*)
          (progn (setq op x)
                 (setq res '*empty*))
          (setq res (rdright 2 x)))
        (if (eq op '*rpar*)
          (setq op (scan))
          (parerr "Missing ) after argument list" nil))
        (return res)))

% ***** Left and Right << and >> Handling *****;                           
(definerop '*lsqb* -2 parsersqb)

(de parsersqb (x)
  (if (eq op '*rsqb*)
    (progn (setq op (scan))
           (cons 'progn (remsemicol x)))
    (parerr "Missing right >> after Group" nil)))

(definebop '*rsqb* -3 0)

%COMMENT ***** [] vector syntax;                                           
(remprop '![ 'newnam)

(remprop '!] 'newnam)

% ***** [] vector syntax;                                                  
(definebop '*lvec* 121 6 parselvec)

(de parselvec (x y)
  (if (eq op '*rvec*)
    (progn (setq op (scan))
           (list 'indx x y))
    (parerr "Missing ] in index expression " nil)))

% INDX is used for both Vectors and Strings in PSL.  You will need to      
% have INDX map to GETV in vanilla Standard Lisp                           
(definebop '*rvec* 5 7)

% ***** Lambda Expression *****;                                           
(definerop 'lambda 0 parselambda)

(de parselambda (x)
  (list 'lambda (if (and x (neq x '*empty*))
          (remcom x)
          nil) (parse0 6 t)))

% ***** Repeat Expression *****;                                           
(definerop 'repeat 4 parserepeat)

(de parserepeat (x)
  (list 'repeat x (if (eq op 'until)
          (parse0 6 t)
          (parerr "REPEAT missing UNTIL clause" t))))

(definebop 'until 3 6)

% ***** While Expression *****;                                            
(definerop 'while 4 parsewhile)

(de parsewhile (x)
  (list 'while x (if (eq op 'do)
          (parse0 6 t)
          (parerr "WHILE missing DO clause" t))))

(definebop 'do 3 6)

% ***** Declare Expression *****;                                          
(definerop 'declare 2 parsedecl)

(definerop 'dcl 2 parsedecl)

(de parsedecl (x)
  (prog (y z)
   a
        (when (neq op '*colon*)
          (parerr "DECLARE needs : before mode" t))
        (if (memq (setq z (scan)) '(integer real scalar))
          (setq op (scan))
          (setq z (parse0 6 nil)))
        (setq y (aconc y (cons z (remcom x))))
        (cond ((eq op '*semicol*) (return (cons 'declare y)))
              ((neq op '*comma*) 
               (parerr "DECLAREd variables separated by ," t)))
        (setq x (parse0 2 t))
        (go a)))

(df declare (u)
  %to take care of top level declarations;                                 
  (progn (lprim "Declarations are not permitted at the top level")
         (nmodestat u)))

% ***** For Expression *****;                                              
(definerop 'for nil parsefor)

(definebop 'step 3 6)

(definebop 'sum 3 6)

(definebop 'product 3 6)

(de parsefor (x)
  (prog (init stp untl action actexpr)
        (cond ((eq x 'each) (return (parseforeach (scan))))
              ((eq x 'all) (return (parseforall (parse0 4 t))))
              ((eq (setq op (scan)) 'setq) (setq init (parse0 6 t)))
              (t (parerr "FOR missing loop VAR assignment" t)))
        (cond ((eq op '*colon*) (setq stp 1) (setq op 'until))
              ((eq op 'step) (setq stp (parse0 6 t)))
              (t (parerr "FOR missing : or STEP clause" t)))
        (if (eq op 'until)
          (setq untl (parse0 6 t))
          (parerr "FOR missing UNTIL clause" t))
        (setq action op)
        (if (memq action '(do sum product collect conc))
          (setq actexpr (parse0 6 t))
          (parerr "FOR missing action keyword" t))
        (return (list 'for (list 'from x init untl stp) 
                      (list action actexpr)))))

% ***** Foreach Expression *****;                                          
(definerop 'foreach nil parseforeach)

(definebop 'collect 3 6)

(definebop 'conc 3 6)

(definebop 'join 3 6)

(de parseforeach (x)
  (prog (l inon action)
        (unless (or (eq (setq inon (scan)) 'in) (eq inon 'on))
          (parerr "FOR EACH missing iterator clause" t))
        (setq l (parse0 6 t))
        (unless (member (setq action op) '(do collect conc join))
          (parerr "FOR EACH missing action clause" t))
        (return (list 'foreach x inon l action (parse0 6 t)))))

% ***** Let Expression *****;                                              
(definebop 'let 1 0 parselet)

(definerop 'let 0 (parselet (cons nil nil) x))

(definebop 'clear 0 1 parseclear)

(definerop 'clear 0 (parseclear (cons nil nil) x))

(definebop 'such 3 6)

(de parselet (x y)
  (parselet1 x y nil))

(de parseclear (x y)
  (parselet1 x y t))

(de parselet1 (x y z)
  (list 'let* (car x) (remcom y) (cdr x) nil z))

(de parseforall (x)
  (prog (bool)
        (when (eq op 'such)
          (if (eq (scan) 'that)
            (setq bool (parse0 6 t))
            (parerr "FOR ALL missing SUCH THAT clause" t)))
        (unless (memq op '(let clear))
          (parerr "FOR ALL missing ACTION" t))
        (return (cons (remcom x) bool))))

% ******** Standard Qoted LIST collectors                                  
(de rlisf (u v w)
  %. Used to Collect a list of IDs to                                      
  %. FLAG with Something                                                   
  (prog nil
        (setq v (rdright 0 v))
        (setq v (cond ((eqcar v '*comma*) (cdr v))
                      (v (list v))
                      (t v)))
        (return (flag v u))))

(de flagop (u)
  %. Declare U as Flagger                                                  
  (rlistat u 'flagop))

(de rlistat (oplist b)
  %. Declare els of OPLIST to be RLIS                                      
  (foreach u in oplist do 
           (defineropx (list (mkquote u) nil 
                        (list (if (eq b 'flagop)
                           'rlisf
                           'rlis1) (mkquote u) 'x (mkquote b))))))

(de rlis1 (u v w)
  %. parse LIST of args, maybe quoted                                      
  % U=funcname, V=following Phrase, W=arg treatment                        
  (prog nil
        (if (eq v '*semicol*)
          (return (progn (setq op v)
                         (if (equal w 'noquote)
                           (list u)
                           (list u nil))))
          (setq v (rdright 0 v)))
        (setq v (cond ((eqcar v '*comma*) (cdr v))
                      (v (list v))
                      (t v)))
        (when (eq w 'io)
          (setq v (mapcar v (function (lambda (j)
                                              (newmkfil j))))))
        (return (if (eq w 'noquote)
                  (cons u v)
                  (list u (mkquotlist v))))))

% ***** Parsing Rules For Various IO Expressions *****;                    
(rlistat '(in out shut) 'noquote)

(rlistat '(tr untr br unbr) 'noquote)

% for mini-trace in PSL                                                    
(rlistat '(load help) 'noquote)

(flag '(in out shut on off tr untr untrst trst) 'nochange)

% No REVAL of args                                                         
(definerop 'fslend nil (estat 'faslend))

(definerop 'faslend nil (estat 'faslend))

(rlistat '(write) 'noquote)

(rlistat '(array) 1)

%		       2.11.3 ON/OFF STATEMENTS                            
(rlistat '(on off) 'noquote)

% ***** Parsing Rules for INTEGER/SCALAR/REAL *****;                       
% These will eventually be removed in favor of DECLARE;                    
(definerop 'integer 0 parseinteger)

(de parseinteger (x)
  (list 'declare (repcom 'integer x)))

(definerop 'real 0 parsereal)

(de parsereal (x)
  (list 'declare (repcom 'real x)))

(definerop 'scalar 0 parsescalar)

(de parsescalar (x)
  (list 'declare (repcom 'scalar x)))

%/ Cuase problems in INTEGER procedure foo;...                             
(de comm1 (u)
  %. general Comment Parser                                                
  (prog nil
        (when (eq u 'end)
          (scan))
   a
        (when (or (eq cursym* '*semicol*) 
                  (and (eq u 'end) 
                       (memq cursym* '(end else until *rpar* *rsqb*))))
          (return nil))
        (scan)
        (go a)))

(de estat (fn)
  %. returns (FN), dropping till semicol ;                                 
  (prog nil
        (while (neq cursym* '*semicol*)
          (scan))
        (setq op '*semicol*)
        (return (list fn))))

(de endstat ()
  %This procedure can also be used for any key-words  which  take  no      
  %arguments;                                                              
  (prog (x)
        (setq x op)
        (comm1 'end)
        (setq op '*semicol*)
        (return (list x))))

% Some useful ESTATs:                                                      
(definerop 'quit nil (estat 'quit))

(definerop 'pause nil (estat 'pause))

(definerop 'cont nil (estat 'cont))

(definerop 'reclaim nil (estat 'reclaim))

(definerop 'retry nil (estat 'retry))

(definerop 'showtime nil (estat 'showtime))

(flag '(fslend cont reclaim retry showtime quit pause) 'opfn)

% Symbolic OPS, or could use NOCHANGE                                      
(rlistat '(flagop) 1)

(commentoutcode (progn (de infix (x)
                         % Makes Left ASSOC, not like CONS                 
                         (foreach y in x do 
                          (definebopx (list (mkquote y) 8 9 nil))))
                       nil))

(flag '(newtok) 'eval)

(de precedence (u)
  (precset (car u) (cadr u)))

(de precset (u v)
  (prog (z)
        (if (or (null (setq z (infixop v))) (null (setq z (cdr z))))
          (rederr (list v "NOT INFIX"))
          (definebopx (list (mkquote u) (car z) (cadr z) nil)))))

(rlistat '(infix precedence) 3)

(remprop 'showtime 'stat)

%*********************************************************************     
%			   DEFINE STATEMENT                                
%********************************************************************;     
(de parsedefine (x)
  % X is following Token                                                   
  (prog (y z)
   b
        (cond ((eq x '*semicol*) 
               (return (progn (setq op '*semicol*)
                              (mkprog nil z))))
              ((eq x '*comma*) (setq x (scan)) %/ Should use SCAN0          
               (go b))
              ((not (idp x)) (go er)))
        (setq y (scan))
        (unless (eq y 'equal)
          (go er))
        (setq z 
              (aconc z 
                     (list 'put (mkquote x) (mkquote 'newnam) 
                      (mkquote (parse0 6 t)))))
        % So doesnt include ,                                              
        (setq x cursym*)
        (go b)
   er
        (symerr 'define t)))

(definerop 'define nil parsedefine)

(flag '(define) 'eval)

%*********************************************************************     
%			 3.2.4 WRITE STATEMENT                             
%********************************************************************;     
(de parsewrite (x)
  (prog (y z)
        (setq x (remcom (xread1 'lambda)))
   a
        (when (null x)
          (return (mkprog nil (cons '(terpri) y))))
        (setq z (list 'prin2 (car x)))
        (when (null (cdr x))
          (setq z (list 'return z)))
   b
        (setq y (aconc y z))
        (setq x (cdr x))
        (go a)))

(definerop 'write nil parsewrite)

%*********************************************************************
%			Rlisp defMacro.
%*********************************************************************

% Rlisp parser wrapping for defMacro, making it like a procedure defn.
%
% The macro name and formal argument structure s-expression are grouped
% together like an Rlisp calling sequence instead of as separate args,
% and followed by a semicolon.  The macro body statement follows just as in a
% "macro procedure" declaration.  (See defMacro and deSetQ in the PSL manual.)
%
% You can write (for example):
%	defMacro  foo( a b . c );	% a and b out of macro arg list,
%	    list( 'bar, a, b, c );	% c gets rest of the macro arg list.
% and then
%	foo( 1, 2, 3, 4 );
% will expand to call:
%	bar( 1, 2, list(3,4) );
%
% Note that the argument list is in Lisp structure form (no commas), just as
% if it had been read as a quoted s-expression.  A single argument with no
% parens, "defMacro bar U;" gets all the arguments as a list.  This is like
% "macro procedure bar U;", but the macro name is not in the arg list.  At the
% other extreme,
%	defMacro  foo( Arg1 Arg2 ... ArgN );
%	    codeTemplate( Arg1, Arg2, ... ArgN,
%		... fn body ...
%	    );
% completely parses the argument list, and is equivalent to
%	smacro procedure foo( Arg1, Arg2, ... ArgN );
%	    ... fn body ... ;
% Defmacro is for the functions in between the extremes of macro and smacro.
(imports '( c-template ))		% Make sure codetemplate gets loaded.

%% Modified from ParsePROCEDURE
(de parsedefmacro (macname)
  (prog (args body)
     (setq args (rlispread))	% Read arglist as if quoted.
     (setq op (scan)) 
     (when (neq op '*semicol*)
	(parerr "defmacro missing terminator after template" T)) 
     (setq body (parse0 0 T)) 
     (return (list 'defmacro macname args body))))

(definerop 'defmacro nil (parsedefmacro x))

%*********************************************************************
%			Rlisp let and let*
%*********************************************************************

% rLet - Rlisp macro providing access to the Lisp "let" function.
% The last argument is the body statement of the let, others are bindings
% of the form "Name( Value )", where the parenthesis are usually optional.
(defmacro rlet args
  (prog (n bindings body)
    (setq n (size args))
    (setq bindings (sub args 0 (sub1 n)))
    (setq body (lastcar args))
    (return (list 'let bindings body))))

% rLet* - Rlisp macro providing access to the Lisp "let*" function.
% The last argument is the body statement of the let*, others are bindings
% of the form "Name( Value )", where the parenthesis are usually optional.
(defmacro rlet* args
  (prog (n bindings body)
    (setq n (size args))
    (setq bindings (sub args 0 (sub1 n)))
    (setq body (lastcar args))
    (return (list 'let* bindings body))))

%*********************************************************************     
%			 VARIOUS DECLARATIONS                              
%********************************************************************;     
(de parseoperator (x)
  (prog (y)
        (setq y (remcom (parse0 0 nil)))
        (return (cond ((eq *mode 'symbolic) 
                       (mkprog nil 
                        (list (list 'flag (mkquote y) (mkquote 'opfn)))))
                      ((neq x 'operator) (if (eqcar (car y) 'prog)
                         (car y)
                         (cons x (mapcar (list y) (function mkarg)))))
                      ((and (neq key* 'operator) (get key* 'fn))
			 ((lambda (k) (mkprog nil (mapcar y (function
			    (lambda (j) (list 'flag
				(list 'list (mkquote j)) k k))))))
                          (mkquote (get key* 'fn))))
                      (t (mkprog nil (list (list 'operator (mkquote y)))))))))

(de operator (u)
  (mapcar u (function mkop)))

(definerop 'operator nil parseoperator)

%. Diphthongs and READtable Changes                                        
(de changechartype (tbl ch ty)
  %. Set Character type                                                    
  (prog (idnum)
        (if (and (idp ch) (lessp (setq idnum (id2int ch)) 128) 
                 (numberp ty) (geq ty 0) (leq ty 19))
          (putv tbl idnum ty)
          (error 99 "Cant Set ReadTable"))))

(de makediphthong (tbl dipindicator startch followch diphthong)
  (if (and (idp startch) (idp followch) (idp diphthong))
    (progn (changechartype tbl startch 13)
           (put startch dipindicator 
                (cons (cons followch diphthong) (get startch dipindicator))))
    (error 99 "Cant Declare Diphthong")))

(de mynewtok (x replace prtchars)
  (prog (y)
        (put x 'newnam-op replace)
        (cond ((null prtchars) (setq y (list x x)))
              ((idp prtchars) (setq y (list prtchars x)))
              (t (setq y prtchars)))
        (put replace 'prtch y)))

(mynewtok '; '*semicol* nil)

(mynewtok '$ '*semicol* nil)

(mynewtok '!, '*comma* nil)

(mynewtok '!. 'cons nil)

(mynewtok ':= 'setq '! :=! )

(mynewtok '!+ 'plus '! +! )

(mynewtok '!- 'difference '! -! )

(mynewtok '* 'times nil)

(mynewtok '/ 'quotient nil)

(mynewtok '** 'expt nil)

(mynewtok '^ 'expt nil)

(mynewtok '= 'equal nil)

(mynewtok ': '*colon* nil)

(mynewtok '!( '*lpar* nil)

(mynewtok '!) '*rpar* nil)

(mynewtok '{ '*lsqb* nil)

(mynewtok '} '*rsqb* nil)

(mynewtok '<< '*lsqb* nil)

(mynewtok '>> '*rsqb* nil)

(mynewtok '![ '*lvec* nil)

(mynewtok '!] '*rvec* nil)

(mynewtok '< 'lessp nil)

(mynewtok '<= 'leq nil)

(mynewtok '>= 'geq nil)

(mynewtok '> 'greaterp nil)

(fluid '(rlispscantable* rlispreadscantable*))

(setq rlispreadscantable* 
      '[17 11 11 11 11 11 11 11 11 17 17 11 17 17 11 11 11 11 11 11 11 11 
        11 11 11 11 11 11 11 11 11 11 17 14 15 11 11 12 11 11 11 11 13 19 
        11 18 20 11 0 1 2 3 4 5 6 7 8 9 13 11 13 11 13 11 11 10 10 10 10 
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 
        11 16 11 11 10 11 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 
        10 10 10 10 10 10 10 10 10 10 11 11 11 11 11 11 11 11 11 11 11 11
        11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11
        11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11
        11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11
        11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11
        11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11
        11 11 11 11 11 11 11 11 11 11 11 lispdiphthong])

(setq rlispscantable* (totalcopy rlispreadscantable*))

(putv rlispscantable* 256 'rlispdiphthong)

(changechartype rlispscantable* '!- 11)

(changechartype rlispscantable* '!+ 11)

(makediphthong rlispscantable* 'rlispdiphthong ': '= ':=)

(makediphthong rlispscantable* 'rlispdiphthong '< '= '<=)

(makediphthong rlispscantable* 'rlispdiphthong '> '= '>=)

(makediphthong rlispscantable* 'rlispdiphthong '< '< '<<)

(makediphthong rlispscantable* 'rlispdiphthong '> '> '>>)

(makediphthong rlispscantable* 'rlispdiphthong '* '* '**)

(de xreadeof (channel ef)
  (if *insidestructureread
    (stderror (bldmsg "Unexpected EOF while parsing on channel %r" channel))
    (throw '$error$ (list $eof$))))

% embarrasingly gross kludge                                               
(put (int2id (char eof)) 'rlispreadmacro 'xreadeof)

(de ratomhook ()
  %. To get READ MACRO', EG EOF                                            
  (channelreadtokenwithhooks in*))

(de rlispchannelread (channel)
  %. Parse S-expression from channel                                       
  (prog (currentscantable* currentreadmacroindicator* 
         currentdiphthongindicator*)
        (setq currentscantable* rlispreadscantable*)
        (setq currentreadmacroindicator* 'lispreadmacro)
        (setq currentdiphthongindicator* 'lispdiphthong)
        (return (channelreadtokenwithhooks channel))))

(de rlispread ()
  %. Parse S-expr from current input                                       
  (rlispchannelread in*))

% End of file.

