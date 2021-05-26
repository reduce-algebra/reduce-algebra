#! /bin/bash -v

bare-psl <<'XX' | tee buildpsl.log

% The mess here is because I want to be able to define some functions
% for use in the reduce sources so that they match historical versions -
% but that will often clash with the current definition while needing to
% be expressed in terms of the current dialect of Lisp. This is achieved
% by having a custom read-eval-print loop that makes substitutions within
% material that is read so that overwritten names are converted from
% (eg) Name to new!-Name. Also if anything is tagged as loseDef its
% definition within the reduce code will be ignored.

(off usermode)

(de printc (u) (prin2 u) (terpri))

(de gensym1 (u) (gensym))

(de list!-to!-string (u) (list2string u))

(de seprp (u) (or (eq u '! ) (eq u !$eol!$) (eq u '!
)))

(on comp)
(de orderp (u v)
   (prog (i j k l m)
      (cond
         ((idp u) (setq u (strinf (symnam (idinf u)))) )
         (t (return (typerr u "identifier"))))
      (cond
         ((idp v) (setq v (strinf (symnam (idinf v)))) )
         (t (return (typerr v "identifier"))))
      (setq i 0)
      (setq j (strlen u))
      (setq k (strlen v))
a     (cond
         ((null (eq (setq l (strbyt u i)) (setq m (strbyt v i))))
            (return (ilessp l m)))
         ((eq i j) (return (null (igreaterp j k))))
         ((eq i k) (return nil)))
      (setq i (iplus2 i 1))
      (go a)))
(off comp)

(de stop (x) (exitlisp))

(global '(nameChanges))

(de redefiner (name bvl body)
   (prog (newName oldNameChanges)
      (setq oldNameChanges nameChanges)
      (setq newName (compress (append (explode 'new!-) (explode name))))
      (setq nameChanges (cons (cons name newName) nameChanges))
      (return (cons 'de (cons newName (cons bvl (sublis oldNameChanges body)))))))

(dm redefine (u)
  (redefiner (cadr u) (caddr u) (cdddr u))) 

(de readFile (u)
  (prog (file save)
    (setq file (open u 'input))
    (setq save (rds file))
    (specialReadEvalPrint)
    (rds save)
    (close file)
    (return nil)))

(de convert (u)
  (prog nil
    (cond
      ((eqcar u 'redefine)
        (setq u (redefiner (cadr u) (caddr u) (cdddr u))))
      ((and (eqcar u 'de) (flagp (cadr u) 'loseDef))
        (setq u (list 'list ''!_____ (mkquote (cadr u)) ''not ''defined)))
      ((eqcar u 'rdf)
        (progn
          (princ "About to read ")
          (print (cadr u))
          (readFile (cadr u))
          (printc "+++ File read")
          (setq u (list 'list ''end ''of ''file (mkquote (cadr u))))))
      (t (setq u (sublis NameChanges u))))
    (return u)))

(de specialReadEvalPrint ()
  (prog (u !*echo)
    (setq !*echo t)
  top
    (setq u (read))
    (cond
      ((or (eq u !$eof!$) (eq u 'quit))
        (progn
          (printc "+++++ End of file or QUIT found")
          (return nil))))
    (setq u (convert u))
    (cond
      ((null (zerop (posn))) (terpri)))
    (setq u (errorset u t t))
    (cond
      ((atom u)
        (progn
          (terpri)
          (printc "+++++ Stopping!")
          (stop 0)))
      (t (setq u (car u))))
    (cond
      ((null (zerop (posn))) (terpri)))
    (print u)
    (go top)))

% OK - all set up now

(specialReadEvalPrint)

% The following try to adapt things for use with the PSL Lisp system.

(de !*eval (u) (eval u))
(de !*apply (u v) (apply u v))
(redefine compress (u)
   (prog (v)
      (setq v (compress u))
      (return (cond ((idp v) (intern v)) (t v)))))
(redefine put (u v w) (cond ((idp u) (put u v w))))
(redefine time (u) (time))
(flag '(assoc) 'loseDef)
%redefine assoc twice so that the recursive call goes to the redefined version
(redefine assoc (u v)
   (cond ((atom v) nil)
         ((and (not (atom (car v))) (eq u (caar v))) (car v))
         (t (assoc u (cdr v)))))
(redefine assoc (u v)
   (cond ((atom v) nil)
         ((and (not (atom (car v))) (eq u (caar v))) (car v))
         (t (assoc u (cdr v)))))
(dm special (u)
   (list 'fluid (mkquote (cdr u))))
(de ascii (n) (int2id n))
(de pts (u v) (set u v))
(de gts (u) (eval u))
(de !~map (a b) (map a b))
(fluid '(!*!*dollar !*!*eof !*!*esc !*!*fmark !*!*qmark !*!*xmark !*!*smark))
(setq !*!*dollar '!$)
(setq !*!*eof    !$eof!$)
(setq !*!*esc    '!#)
(setq !*!*fmark  '!&)
(setq !*!*qmark  '!')
(setq !*!*xmark  '!!)
(setq !*!*smark  '!")

(redefine explode (x) (explode2 x))

% % I suspect that compress was expected to form a symbol without regard
% % for special characters, so here I insert escapes everywhere before
% % using the current version.
% (redefine compress (l)
%   (prog (w)
%     (cond
%       ((digit (car l)) (return (compress l))))
%   top
%     (cond
%       ((null l) (return (compress (reverse w)))))
%     (setq w (cons (car l) (cons '!! w)))
%     (setq l (cdr l))
%     (go top)))

(flag '(getd putd compress deflist assoc) 'loseDef)

(fluid '(
   !*test
   echol!*
   ipl!*
   ifl!*
   iecho!*
   opl!*
   ibase
   erfg!*
   cloc!*
   flg!*
   sos!*
   contl!*
   cursym!*
   !*fort
   !*nat
   time2!*
   time1!*
   !*int
   alglist!*
   imode!*
   !*mode
   crchar!*
   tmode!*
   programl!*
   semic!*
   !*ans
   key!*
   !*!*smark
   nxtsym!*
   key1!*
   fname!*
   tstack!*
   orig!*
   posn!*
   count!*
   fortvar!*
   ycoord!*
   ymin!*))

(redefine open (u v)
  (prog (ff)
    (setq ff (open u v))
    (cond
      ((eq v 'input) (setq ipl!* (cons ff ipl!*)))
      (t (setq opl!* (cons ff opl!*))))
    (return ff)))

(redefine rds (u)
  (cond
    ((null u) (rds nil))
    ((member u ipl!*) (rds u))
    (t (rederr (cons "RDS GIVEN CLOSED FILE" u)))) )

(redefine wrs (u)
  (cond
    ((null u) (wrs nil))
    ((member u opl!*) (wrs u))
    (t (rederr (cons "WRS GIVEN CLOSED FILE" u)))) )

(redefine close (u)
  (cond
    ((null u) nil)
    ((member u ipl!*)
      (progn 
        (setq ipl!* (delete u ipl!*))
        (close u)))
    ((member u opl!*)
      (progn 
        (setq opl!* (delete u opl!*))
        (close u)))
    (t (rederr (cons "CLOSE GIVEN CLOSED FILE" u)))) )

(redefine readch ()
  (prog (!*echo)
    (return (readch))))

(flag '(open rds wrs close) 'loseDef)

(de sprint (x n m) (prettyprint x))

(setq nameChanges (cons '(posn . new!-posn) nameChanges))

% Now read the main Reduce source.

(rdf "reduce.lsp")
quit

(setq !*msg nil)
(setq !*echo nil)

%(savesystem "REDUCE 2" "redpsl2" '((begin)))
(savesystem "REDUCE 2" "redpsl2" 'nil)

XX
