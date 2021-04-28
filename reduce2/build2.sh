#! /bin/bash -v

# Hah - I had not known about using quotes in the "<<'XX'" here, but
# putting them there leaves the here document utterly unchanged so that
# use of dollars within it do not get treated as introducing references to
# shell variables.

csl -w -i- -o reduce2.img -l build2.log <<'XX'

% Ensure that the new image will be fully free-standing.
(copy!-module 'compat)
(copy!-module 'compiler)

(setq !*comp t)
(enable!-errorset 3 3)

% The mess here is because I want to be able to define some functions
% for use in the reduce sources so that they match historical versions -
% but that will often clash with the current definition while needing to
% be expressed in terms of the current dialect of Lisp. This is achieved
% by having a custom read-eval-print loop that makes substitutions within
% material that is read so that overwritten names are converted from
% (eg) Name to new!-Name. Also if anything is tagged as loseDef its
% definition within the reduce code will be ignored.

(global '(nameChanges))

(de redefiner (name bvl body)
   (prog (newName oldNameChanges)
      (setq oldNameChanges nameChanges)
      (setq newName (compress (append (explode 'new!-) (explode name))))
      (setq nameChanges (cons (cons name newName) nameChanges))
      (return (list!* 'de newName bvl (sublis oldNameChanges body)))))

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

% The following try to adapt things for use with the CSL Lisp system.

(de !*eval (u) (eval u))
(de !*apply (u v) (apply u v))
(redefine time (u) (time))
(dm special (u)
   (list 'fluid (mkquote (cdr u))))
(de ascii (n) (code!-char n))
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

(redefine explode (x) (explodec x))

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

(flag '(getd putd compress deflist) 'loseDef)

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

(preserve)

XX

