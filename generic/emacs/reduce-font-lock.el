;;; reduce-font-lock.el --- Syntax highlighting for REDUCE source code  -*- lexical-binding: t; -*-

;; Copyright (C) 2022 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Created: 6 June 2022 as a separate file (was part of reduce-mode.el)
;; Time-stamp: <2022-10-02 17:51:40 franc>
;; Keywords: languages, faces
;; Homepage: https://reduce-algebra.sourceforge.io/reduce-ide/
;; Package-Version: 1.8
;; Package-Requires: ((reduce-mode "1.6"))

;; This file is part of REDUCE IDE.

;; REDUCE IDE is free software: you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published
;; by the Free Software Foundation, either version 3 of the License,
;; or (at your option) any later version.

;; REDUCE IDE is distributed in the hope that it will be useful, but
;; WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;; General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with REDUCE IDE.  If not, see <https://www.gnu.org/licenses/>.

;;; Commentary:

;; Based on original code by Rainer Schöpf.

;; Note that Font Lock Mode is documented in the ELisp manual under
;; Major and Minor Modes.  Syntactic fontification happens first; it
;; finds %-comments, /**/-comments and string constants and highlights
;; them.  Search-based fontification happens second.

;; Regard quoted identifiers and lists as data and fontify as
;; constants.

;; Font Lock mode processes the elements of ‘font-lock-keywords’ one
;; by one, and for each element, it finds and handles all matches.
;; Ordinarily, once part of the text has been fontified already, this
;; cannot be overridden by a subsequent match in the same text; but
;; you can specify different behavior using the OVERRIDE element of a
;; SUBEXP-HIGHLIGHTER.

;; Generally, don't use OVERRIDE because then, for example,
;; commented-out REDUCE code may be mis-highlighted.

;;; Code:

(defconst reduce-font-lock--keywords
  '(
    reduce-font-lock--keywords-0     ; Basic = nil
    reduce-font-lock--keywords-1     ; Algebraic
    reduce-font-lock--keywords-2     ; Symbolic = t
    )
  "A list of symbols corresponding to increasing fontification.
Each is assigned a ‘font-lock-keywords’ value for REDUCE mode.
The symbols are in order of increasing fontification level, which
is selected by the value of ‘font-lock-maximum-decoration’.  This
defaults to t, meaning maximal fontification.  The levels are
strictly cumulative and their names should not be taken too
literally!")

(defun reduce-font-lock-mode ()
  "Set up font-lock mode.  Called in ‘reduce-mode’."
  ;; These variables are automatically buffer-local:
  (setq font-lock-defaults
        ;; reduce-font-lock--keywords evaluates to a list of symbols!
        (list reduce-font-lock--keywords ; KEYWORDS
              nil                        ; KEYWORDS-ONLY
              t)                         ; CASE-FOLD
        font-lock-multiline t)           ; for comment statements
  ;; Additional support for comment statements:
  (add-to-list 'font-lock-extend-region-functions
               #'reduce-font-lock--extend-region-for-comment-statement)
  (reduce-font-lock--level))             ; for font-lock menu


;;;;; *******************
;;;;; Basic fontification
;;;;; *******************

(defconst reduce-font-lock--keyword-regexp
  (regexp-opt
   '("procedure" "ws" "load_package"
     "begin" "end" "return" "go" "to" "goto"
     "if" "then" "else" "not" "or" "and"
     "eq" "neq" "member" "memq"
     "while" "do" "repeat" "until"
     "collect" "join" "conc" "sum" "product"
     "for" "all" "each" "forall" "foreach" "step"
     "in" "on" "off" "write" "pause"
     "such" "that" "where" "when"
     "let" "match" "clear" "clearrules"
     "order" "factor" "remfac" "showtime"
     "index" "mass" "mshell")
   'symbols)
  "Regular expression matching a basic REDUCE keyword.
It must be a distinct symbol and will be highlighted in
‘font-lock-keyword-face’.")

(defun reduce-font-lock--keyword-search (limit)
  "Match ‘reduce-font-lock--keyword-regexp’ between point and LIMIT.
But not if it is quoted, or preceded or followed by an escaped
character."
  ;; E.g. "alg/coeff.red" uses !*factor as a local variable.  Must
  ;; repeat until no further keywords can be found; see
  ;; "rlisp/inter.red" which contains 'pause.
  (let (found)
    (while
        (and
         (setq found (re-search-forward
                      reduce-font-lock--keyword-regexp limit t))
         (or (eq (char-after) ?!)
             (let ((before (1- (match-beginning 0))))
               (or (eq (char-after before) ?')
                   (eq (char-before before) ?!))))))
    found))

(defconst reduce-font-lock--keywords-0
  `((reduce-font-lock--match-comment-statement
     1 font-lock-comment-face t)
    ;; Basic keywords:
    reduce-font-lock--keyword-search
    ;; Group delimiters:
    "<<\\|>>")
  "List of “basic” REDUCE fontification rules.
Highlight comment statements, main syntactic keywords and group
delimiters.")


;;;;; ***********************
;;;;; Algebraic fontification
;;;;; ***********************

(defconst reduce-font-lock--identifier-regexp
  "\\(?:[[:alpha:]]\\|!.\\)\
\\(?:\\w\\|\\s_\\|!.\\)*"
  ;; Digits have word syntax and identifier cannot begin with a digit.
  "Regular expression matching a REDUCE identifier.
An identifier consists of one or more alphanumeric
characters (i.e. alphabetic letters or decimal digits), the first
of which must be alphabetic.  In addition, the underscore
character (_) is considered a letter if it is within an
identifier.  Special characters may be used in identifiers too,
even as the first character, but each must be preceded by an
exclamation mark in input.")

(defconst reduce-font-lock--type-regexp
  "algebraic\\|scalar\\|integer\\|real\\|symbolic\\|lisp\\|inline\\|s?macro"
  "Regexp that matches any single possible procedural type.")

(defconst reduce-font-lock--keywords-1
  `(,@reduce-font-lock--keywords-0

    ;; Procedure declarations (but not yet allowing /**/ comments)...
    ;; procedure name ;
    ;; procedure name arg ;
    ;; procedure name ( arg1 , arg2 , ... ) ;
    (,(concat "\\_<procedure\\_>"
              "\\s-+\\(" reduce-font-lock--identifier-regexp "\\)\\s-*\(?")
     (1 font-lock-function-name-face)
     ;; Highlight arguments:
     (,(concat "\\=\\s-*\\(" reduce-font-lock--identifier-regexp "\\)\\s-*[,\)]?")
      nil nil
      (1 font-lock-variable-name-face)))

    ;; General type declarations (ignore quoted keywords):
    (,(concat
       "\\(?:^\\|[^']\\)\\_<\\(" reduce-font-lock--type-regexp "\\)\\_>")
     (1 font-lock-type-face)
     ;; Highlight subsequent types:
     (,(concat "[^']\\_<\\(" reduce-font-lock--type-regexp "\\)\\_>")
      nil nil
      (1 font-lock-type-face)))

    ;; Local variable type declarations, e.g.
    ;; scalar var1 , var2 , ... ;
    ("\\_<\\(?:scalar\\|integer\\|real\\)\\s-"
     ;; Highlight variables:
     (,(concat "\\=\\s-*\\(" reduce-font-lock--identifier-regexp "\\)\\s-*\\s.")
      ;; Pre-form -- return position of terminator to limit search:
      (save-excursion (re-search-forward "[\;$]")) nil
      (1 font-lock-variable-name-face)))

    ;; Labels -- go to label; ... label :
    (,(concat "\\_<go\\(?:\\s-*to\\)?\\s-+"
              "\\(" reduce-font-lock--identifier-regexp "\\)")
     1 font-lock-constant-face)
    (,(concat "\\(?:^\\|[\;$]\\)\\s-*"
              "\\(" reduce-font-lock--identifier-regexp "\\)\\s-*:[^=]")
     1 font-lock-constant-face)

    ;; Operator declarations of the form ‘type op1, op2, ...’
    (,(concat "\\(?:^\\|[^']\\)\\_<\\("
              (mapconcat #'identity
                         '("even" "odd"
                           "linear" "noncom"
                           "\\(?:anti\\)?symmetric"
                           "operator" "infix"
                           "vector")
                         "\\|")
              "\\)\\_>\\s-")
     (1 font-lock-type-face)
     ;; Highlight function names:
     (,(concat "\\=\\s-*\\(" reduce-font-lock--identifier-regexp "\\)\\s-*[,\;$]")
      ;; Pre-form -- return position of terminator to limit search:
      (save-excursion (re-search-forward "[\;$]")) nil
      (1 font-lock-function-name-face)))

    ;; Array and matrix type declarations: e.g.
    ;; array a 10, b(2,3,4);
    ;; matrix x(2,1),y(3,4),z;
    ("\\(?:^\\|[^']\\)\\_<\\(array\\|matrix\\)\\_>\\s-"
     (1 font-lock-type-face)
     ;; Highlight array/matrix names:
     (,(concat "\\=\\s-*\\(" reduce-font-lock--identifier-regexp "\\)"
               ;; Optional bounds with optional ():
               "\\s-*\\(?:\\(?:(.*?)\\)\\|\\w*\\)\\s-*[,\;$]")
      ;; Pre-form -- return position of terminator to limit search:
      (save-excursion (re-search-forward "[\;$]"))
      nil (1 font-lock-function-name-face)))

    ;; Named constants (reserved variables).
    ;; Allow 5pi to match pi, etc.  Digits have word syntax.
    ;; Must also match within i*pi/2, etc.
    ;; But nil and t should not be used as variables.
    ("\\(?:\\(?:[^[:alpha:]_]\\(e\\|i\\|infinity\\|pi\\|\
Catalan\\|Euler_Gamma\\|Golden_Ratio\\|Khinchin\\)\\)\\|\
\\(?:\\_<\\(nil\\|t\\)\\)\\)\\_>"
     ;; Lax match since only one group can match:
     (1 font-lock-constant-face nil t)
     (2 font-lock-constant-face nil t)))
  "List of “algebraic” REDUCE fontification rules.
Basic (‘reduce-font-lock--keywords-0’) plus procedure names and
parameters; general types (e.g. “algebraic”), local variable
types (e.g. “scalar”) and names; goto and label names; operator,
operator type (e.g. “linear”) and vector declarations; array and
matrix declarations with or without bounds; named
constants (e.g. “pi”).")


;;;;; **********************
;;;;; Symbolic fontification
;;;;; **********************

;; Assertion and preprocessor rules based on code by Thomas Sturm.
;; A good test file for all assertion rules is "redlog/cl/clqe.red".

;; A constant with a name of the form ‘font-lock-rule’ becomes an
;; element of the list assigned by ‘reduce-mode’ to
;; ‘font-lock-keywords’, which directly controls search-based
;; fontification, whereas a constant with a name of the form
;; ‘font-lock-rules’ (plural) below becomes appended to or spliced
;; into the list assigned to ‘font-lock-keywords’.

(defconst reduce-font-lock--preprocessor-rules
  `((,(concat
       "\\(#define\\_>\\)\\s-+"
       "\\(" reduce-font-lock--identifier-regexp "\\)\\s-+"
       "\\(" reduce-font-lock--identifier-regexp "\\)")
     (1 font-lock-preprocessor-face)
     (2 font-lock-variable-name-face)
     (3 font-lock-variable-name-face))

    ("\\(#\\(?:el\\)?if\\_>\\)\\s-+\\(.*\\)"
     (1 font-lock-preprocessor-face)
     (2 'default))

    ("\\(#\\(?:else\\|endif\\)\\_>\\)"
     (1 font-lock-preprocessor-face)))
  "Rules to highlight preprocessor #-directives as in C, C++, etc.")

(defconst reduce-font-lock--asserted-type-rule
  `("\\_<procedure\\_>"
     ;; anchored-highlighter to handle the rest of the statement:
    ,(concat "[^!]:\\s-*\\(" reduce-font-lock--identifier-regexp "\\)")
    nil nil
    (1 font-lock-type-face t))
  "Rule to highlight types of procedure arguments and return values.")

(defconst reduce-font-lock--assert-declare/struct-rules
  `((,(concat
       "\\(declare\\)\\s-+"
       "\\(" reduce-font-lock--identifier-regexp "\\)\\s-*:")
     (1 font-lock-keyword-face)
     (2 font-lock-function-name-face)
     ;; anchored-highlighter to handle the rest of the statement:
     (,reduce-font-lock--identifier-regexp nil nil (0 font-lock-type-face)))
    (,(concat
       "\\(struct\\)\\s-+"
       "\\(" reduce-font-lock--identifier-regexp "\\)"
       ;; optionally followed by...
       "\\(?:\\s-+\\(\\(?:checked\\|asserted\\)\\s-+by\\)\\s-+"
       "\\(" reduce-font-lock--identifier-regexp "\\)\\)?")
     (1 font-lock-keyword-face)
     (2 font-lock-type-face)
     (3 font-lock-keyword-face t)
     (4 font-lock-function-name-face)))
  "Rules to highlight “declare” and “struct” statements, as used in “redlog”.")

(defconst reduce-font-lock--keywords-2
  `(;; Apply specific rules before more general rules:
    ,@reduce-font-lock--preprocessor-rules

    ;; Quoted identifiers:
    (,(concat "'\\(" reduce-font-lock--identifier-regexp "\\)")
     (1 font-lock-constant-face))

    (;; Quoted lists (arbitrarily nested and multi-line):
     "'\\(\(\\)"
     (1 font-lock-constant-face)
     ("\\(?:.\\|\n\\)"         ; match anything including \n
      ;; This may be a hack but it seems to work!
      ;; Pre-form function sets search limit to end of list:
      (save-excursion (backward-char) (forward-sexp) (point))
      nil
      (0 font-lock-constant-face)))

    ,@reduce-font-lock--keywords-1
    ,reduce-font-lock--asserted-type-rule
    ,@reduce-font-lock--assert-declare/struct-rules

    ;; Module keyword and module name:
    (,(concat "\\(?:^\\|[^']\\)\\_<\\(module\\)\\s-+"
              "\\(" reduce-font-lock--identifier-regexp "\\)")
     (1 font-lock-keyword-face)
     (2 font-lock-constant-face))

    ;; Endmodule and other symbolic-mode keywords:
    ("\\(?:^\\|[^']\\)\\_<\\(\
endmodule\\|lambda\\|precedence\\|\
assert\\(?:_\\(?:un\\)?install\\(?:_all\\)?\\)?\
\\)\\_>[^!]"
     1 font-lock-keyword-face)

    ;; Symbolic-mode functions:
    ("\\(?:^\\|[^']\\)\\_<\\(\
function\\|newtok\\|\
get\\|put\\|deflist\\|flag\\|remprop\\|remflag\
\\)\\_>[^!]"
     1 font-lock-builtin-face)

    ;; Symbolic-mode types:
    ("\\(?:^\\|[^']\\)\\_<\\(\
fluid\\|global\\|switch\\|share\\|rlistat\\|asserted\
\\)\\_>[^!]"
     1 font-lock-type-face)

    ;; Lambda arguments:
    ;; lambda arg ;
    ;; lambda ( arg1 , arg2 , ... ) ;
    ("\\_<lambda\\_>\\s-*\(?"
     (,(concat "\\=\\s-*\\(" reduce-font-lock--identifier-regexp "\\)\\s-*[,\)]?")
      nil nil
      (1 font-lock-variable-name-face))))
  "List of “symbolic” REDUCE fontification rules.
Algebraic (‘reduce-font-lock--keywords-1’) plus preprocessor
#-directives; quoted objects; asserted types; “declare” and
“struct” statements, as used in “redlog”; module name and
endmodule; symbolic-mode keywords, functions and types; lambda
argument.")


;;;; *********************************************************
;;;; Support functions for comment statements.  Being normally
;;;; multi-line, they require the support of the function
;;;; ‘reduce-font-lock--extend-region-for-comment-statement’.
;;;; *********************************************************

(defun reduce-font-lock--match-comment-statement (limit)
  "Search for a comment statement between point and LIMIT.
If successful, return non-nil and set the match data to describe
the match; otherwise return nil."
  ;; Fontification will call this function repeatedly with the same
  ;; limit, and with point where the previous invocation left it,
  ;; until it fails.  On failure, there is no need to reset point in
  ;; any particular way.
  (when
      (re-search-forward "\\(\\_<comment\\_>[^;$]*[;$]\\)" limit t)
    (let* ((start-of-comment (match-beginning 0)) (end-of-comment (point))
           (parse-state (syntax-ppss start-of-comment)))
      ;; NB: syntax-ppss call leaves point at start-of-comment.
      (cond
       ;; -- Check that the word "comment" is not in a string:
       ((nth 3 parse-state)
        (goto-char (nth 8 parse-state)) ; start of string
        ;; Skip string forwards:
        (forward-sexp)
        ;; Search again:
        (reduce-font-lock--match-comment-statement limit))
       ;; -- Check that the word "comment" is not in a % or /**/ comment:
       ((nth 4 parse-state)
        (goto-char (nth 8 parse-state)) ; start of % or /**/ comment
        ;; Skip white space and % or /**/ comments forwards:
        (forward-comment (buffer-size))
        ;; Search again:
        (reduce-font-lock--match-comment-statement limit))
       ;; -- Comment statement found:
       (t (goto-char end-of-comment) t)))))

(defvar font-lock-beg)
(defvar font-lock-end)

(defun reduce-font-lock--extend-region-for-comment-statement ()
  "Extend font-lock region if necessary and if so return non-nil.
Include all of any comment statements that font-lock region intersects.
This function is prepended to ‘font-lock-extend-region-functions’."
  (let (new-beg new-end)
    (goto-char font-lock-beg)
    ;; Is font-lock-beg within a comment?
    (save-excursion
      (if (and (re-search-backward "\\(comment\\)\\|\\([;$]\\)" nil t)
               (match-beginning 1))
          (setq new-beg (point))))
    (when (or new-beg
              ;; Or does a comment start in the font-lock region?
              (search-forward "comment" font-lock-end t))
      ;; If either of the above then...
      (re-search-forward "[;$]" nil 1) ; if un-terminated move to EOB
      ;; Do multiple comments start in the font-lock region?
      (while (and (< (point) font-lock-end)
                  (search-forward "comment" font-lock-end t))
        (re-search-forward "[;$]" nil 1)) ; if un-terminated move to EOB
      (if (> (point) font-lock-end)
          (setq new-end (point))))
    ;; Temporary message for testing:
    ;; (message "reduce-font-lock--extend-region-for-comment-statement: %s --> %s, %s --> %s"
    ;;       font-lock-beg new-beg font-lock-end new-end)
    ;; Return non-nil if font-lock region adjusted:
    (or (if new-beg (setq font-lock-beg new-beg))
        (if new-end (setq font-lock-end new-end)))))


;;;; ***********************************************************
;;;; Provide a REDUCE font-lock menu, based originally on
;;;; font-lock-menu.el by Simon Marshall <simon@gnu.ai.mit.edu>.
;;;; ***********************************************************

(defconst reduce-font-lock--level-max
  (1- (length reduce-font-lock--keywords))
  "Maximum REDUCE font-lock level.")

(defvar reduce-font-lock--level)

(defun reduce-font-lock--level ()
  "Establish the buffer-local variable ‘reduce-font-lock--level’.
It is used only to control the font-lock menu and is set for each
new buffer from the value of ‘font-lock-maximum-decoration’,
which must be done in ‘reduce-mode’."
  (set (make-local-variable 'reduce-font-lock--level)
       ;; The value of ‘font-lock-maximum-decoration’ may be an alist,
       ;; non-negative integer, t (meaning max) or nil (meaning 0).
       (let (level)
         (if (consp font-lock-maximum-decoration) ; alist
             (if (setq level (or (assoc 'reduce-mode font-lock-maximum-decoration)
                                 (assoc t font-lock-maximum-decoration)))
                 (setq level (cdr level)))
           (setq level font-lock-maximum-decoration)) ; not alist
         ;; level = integer, t or nil
         (cond ((numberp level)
                (cond ((< level 0) 0)
                      ((> level reduce-font-lock--level-max)
                       reduce-font-lock--level-max)
                      (t level)))
               ((eq level t) reduce-font-lock--level-max) ; t means max
               (t 0)))))                ; nil means 0

(defconst reduce-font-lock--submenu
  '("Syntax Highlighting"
    ["In Current Buffer" font-lock-mode
     :style toggle :selected font-lock-mode :active t]
    ["Highlight Buffer" font-lock-fontify-buffer t]
    "--"
    "Level:"
    ["Symbolic (2)" (reduce-font-lock--change 2)
     :style radio :selected (eq reduce-font-lock--level 2) :active t]
    ["Algebraic (1)" (reduce-font-lock--change 1)
     :style radio :selected (eq reduce-font-lock--level 1) :active t]
    ["Basic (0)" (reduce-font-lock--change 0)
     :style radio :selected (eq reduce-font-lock--level 0) :active t]))

(easy-menu-define                       ; (symbol maps doc menu)
  reduce-fontification-submenu
  nil
  "REDUCE Fontification Submenu."
  reduce-font-lock--submenu)

(defvar reduce-mode-map)                ; defined in reduce-mode.el

(define-key-after (lookup-key reduce-mode-map [menu-bar REDUCE])
  [Fontification] (cons "Syntax Highlighting" reduce-fontification-submenu)
  t)                                    ; was 'Make\ Proc\ Menu

(defconst reduce-font-lock--level-names
  '("minimal" "algebraic" "symbolic" "maximal"))

(defun reduce-font-lock--change (level)
  "Re-fontify at the specified LEVEL."
  ;; Do messages need to be saved in the messages buffer?
  ;; If interactive then needs to be more robust.
  ;; (interactive)
  (let ((name (nth level reduce-font-lock--level-names)))
    (if (eq reduce-font-lock--level level)
        (message "REDUCE Font Lock decoration unchanged (level %d : %s)."
                 level name)
      (let ((font-lock-maximum-decoration level))
        (font-lock-refresh-defaults))
      (setq reduce-font-lock--level level)
      (message "REDUCE Font Lock decoration set to level %d : %s."
               level name))))
;; (let ((name (nth (1- level) reduce-font-lock--level-names))
;;       (keywords (eval (nth (1- level) (car font-lock-defaults)))))
;;   ;; ‘font-lock-defaults’ is used in order to support both
;;   ;; reduce-mode and reduce-run with the same code!
;;   (setq keywords (font-lock-compile-keywords keywords)) ; Emacs 20 only!
;;   (if (and font-lock-mode (equal font-lock-keywords keywords))
;;       (message "REDUCE Font Lock decoration unchanged (level %d : %s)."
;;                level name)
;;     (font-lock-mode 0)
;;     (font-lock-set-defaults)
;;     (setq font-lock-keywords keywords)
;;     (font-lock-mode 1)
;;     (setq reduce-font-lock--level level)
;;     (message "REDUCE Font Lock decoration set to level %d : %s."
;;              level name))))

(provide 'reduce-font-lock)

;;; reduce-font-lock.el ends here
