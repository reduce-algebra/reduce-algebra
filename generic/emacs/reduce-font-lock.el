;;; reduce-font-lock.el --- Syntax highlighting for REDUCE IDE  -*- lexical-binding: t; -*-

;; Copyright (C) 2022-2024 Francis J. Wright

;; Author: Francis J. Wright <https://sites.google.com/site/fjwcentaur>
;; Created: 6 June 2022 as a separate file (was part of reduce-mode.el)
;; Time-stamp: <2024-01-28 17:23:07 franc>
;; Homepage: https://reduce-algebra.sourceforge.io/reduce-ide/

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

(eval-when-compile (require 'reduce-mode))

(defconst reduce-font-lock--keywords
  '(
    reduce-font-lock--keywords-0        ; Minimal = nil
    reduce-font-lock--keywords-1        ; Basic
    reduce-font-lock--keywords-2        ; Algebraic
    reduce-font-lock--keywords-3        ; Symbolic = t
    )
  "Syntax highlighting for editing REDUCE.
A list of symbols corresponding to increasing fontification.
Each is assigned a ‘font-lock-keywords’ value for REDUCE mode.
The symbols are in order of increasing fontification level, which
is selected by the value of ‘font-lock-maximum-decoration’.  This
defaults to t, meaning maximal fontification.  The levels are
strictly cumulative and their names should not be taken too
literally!")

(defconst reduce-font-lock--keywords-0 nil
  "Highlight strings and syntactic comments only – no keywords.")

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

(defun reduce-font-lock--kwd-search (regexp limit)
  "Reliably match REGEXP for a keyword between point and LIMIT.
Do not match if it is quoted, or preceded or followed by an
escaped character."
  ;; E.g. "alg/coeff.red" uses !*factor as a local variable.  Must
  ;; repeat until no further keywords can be found; see
  ;; "rlisp/inter.red" which contains 'pause.
  (let (found)
    (while (and
            (setq found (re-search-forward regexp limit t))
            (or (eq (char-after) ?!)
                (let ((before (1- (match-beginning 0))))
                  (or (eq (char-after before) ?')
                      (eq (char-before before) ?!))))))
    found))


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

(defconst reduce-font-lock--keywords-1
  `((reduce-font-lock--match-comment-statement
     1 font-lock-comment-face t)
    ;; Basic keywords:
    (lambda (limit)
      (reduce-font-lock--kwd-search
       reduce-font-lock--keyword-regexp limit))
    ;; Group delimiters:
    "<<\\|>>")
  "List of “basic” REDUCE fontification rules.
Highlight comment statements, main syntactic keywords and group
delimiters.")


;;;;; ***********************
;;;;; Algebraic fontification
;;;;; ***********************

(defconst reduce-font-lock--keywords-2
  `(,@reduce-font-lock--keywords-1

    ;; Procedure declarations...
    ;; procedure name ;
    ;; procedure name arg ;
    ;; procedure name ( arg1 , arg2 , ... ) ;
    (,(concat "\\_<procedure\\_>"
              reduce-whitespace-regexp "+"
              "\\(" reduce-identifier-regexp "\\)"
              reduce-whitespace-regexp "*" "\(?")
     (1 font-lock-function-name-face)
     ;; Highlight arguments:
     (,(concat "\\=" reduce-whitespace-regexp "*"
               "\\(" reduce-identifier-regexp "\\)"
               reduce-whitespace-regexp "*" "[,\)]?")
      nil nil
      (1 font-lock-variable-name-face)))

    ;; General type declarations:
    ((lambda (limit)
       (reduce-font-lock--kwd-search
        "\\_<\\(?:algebraic\\|scalar\\|integer\\|real\\|\
symbolic\\|lisp\\|inline\\|s?macro\\)\\_>"
        limit))
     . font-lock-type-face)

    ;; Local variable type declarations, e.g.
    ;; scalar var1 , var2 , ... ;
    (,(concat "\\_<\\(?:scalar\\|integer\\|real\\)"
              reduce-whitespace-regexp)
     ;; Highlight variables:
     (,(concat "\\=" reduce-whitespace-regexp "*"
               "\\(" reduce-identifier-regexp "\\)"
               reduce-whitespace-regexp "*" "\\s.")
      ;; Pre-form -- return position of terminator to limit search:
      (save-excursion (re-search-forward "[\;$]")) nil
      (1 font-lock-variable-name-face)))

    ;; Labels -- go to label; ... label :
    (,(concat "\\_<go\\(?:\\s-*to\\)?"
              reduce-whitespace-regexp "+"
              "\\(" reduce-identifier-regexp "\\)")
     1 font-lock-constant-face)
    (,(concat "\\(?:^\\|[\;$]\\)" reduce-whitespace-regexp "*"
              "\\(" reduce-identifier-regexp "\\)"
              reduce-whitespace-regexp "*" ":[^=]")
     1 font-lock-constant-face)

    ;; Operator declarations of the form ‘type op1, op2, ...’
    ((lambda (limit)
       (reduce-font-lock--kwd-search
        ,(regexp-opt
          '("even" "odd" "linear" "noncom"
            "symmetric" "antisymmetric"
            "operator" "infix" "vector")
          'symbols)
        limit))
     (1 font-lock-type-face)
     ;; Highlight function names:
     (,(concat "\\=" reduce-whitespace-regexp "*"
               "\\(" reduce-identifier-regexp "\\)"
               reduce-whitespace-regexp "*" "[,\;$]")
      ;; Pre-form -- return position of terminator to limit search:
      (save-excursion (re-search-forward "[\;$]")) nil
      (1 font-lock-function-name-face)))

    ;; Array and matrix type declarations: e.g.
    ;; array a 10, b(2,3,4);
    ;; matrix x(2,1),y(3,4),z;
    ((lambda (limit)
       (reduce-font-lock--kwd-search
        "\\_<\\(?:array\\|matrix\\)\\_>"
        limit))
     (0 font-lock-type-face)
     ;; Highlight array/matrix names:
     (,(concat "\\=" reduce-whitespace-regexp "*"
               "\\(" reduce-identifier-regexp "\\)"
               ;; Optional bounds with optional ():
               reduce-whitespace-regexp "*"
               "\\(?:\\(?:(.*?)\\)\\|\\w*\\)"
               reduce-whitespace-regexp "*" "[,\;$]")
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
Basic (‘reduce-font-lock--keywords-1’) plus procedure names and
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
       "\\(#define\\_>\\)"
       reduce-whitespace-regexp "+"
       "\\(" reduce-identifier-regexp "\\)"
       reduce-whitespace-regexp "+"
       "\\(" reduce-identifier-regexp "\\)")
     (1 font-lock-preprocessor-face)
     (2 font-lock-variable-name-face)
     (3 font-lock-variable-name-face))

    (,(concat "\\(#\\(?:el\\)?if\\_>\\)"
              reduce-whitespace-regexp "+" "\\(.*\\)")
     (1 font-lock-preprocessor-face)
     (2 'default))

    ("\\(#\\(?:else\\|endif\\)\\_>\\)"
     (1 font-lock-preprocessor-face)))
  "Rules to highlight preprocessor #-directives as in C, C++, etc.")

(defconst reduce-font-lock--asserted-type-rule
  `("\\_<procedure\\_>"
    ;; anchored-highlighter to handle the rest of the statement:
    ,(concat "[^!]:"
             reduce-whitespace-regexp "*"
             "\\(" reduce-identifier-regexp "\\)")
    nil nil
    (1 font-lock-type-face t))
  "Rule to highlight types of procedure arguments and return values.")

(defconst reduce-font-lock--assert-declare/struct-rules
  `((,(concat
       "\\(declare\\)"
       reduce-whitespace-regexp "+"
       "\\(" reduce-identifier-regexp "\\)"
       reduce-whitespace-regexp "*" ":")
     (1 font-lock-keyword-face)
     (2 font-lock-function-name-face)
     ;; anchored-highlighter to handle the rest of the statement:
     (,reduce-identifier-regexp nil nil (0 font-lock-type-face)))
    (,(concat
       "\\(struct\\)"
       reduce-whitespace-regexp "+"
       "\\(" reduce-identifier-regexp "\\)"
       ;; optionally followed by...
       "\\(?:" reduce-whitespace-regexp "+"
       "\\(\\(?:checked\\|asserted\\)"
       reduce-whitespace-regexp "+"
       "by\\)" reduce-whitespace-regexp "+"
       "\\(" reduce-identifier-regexp "\\)\\)?")
     (1 font-lock-keyword-face)
     (2 font-lock-type-face)
     (3 font-lock-keyword-face t t)           ; need not match
     (4 font-lock-function-name-face nil t))) ; need not match
  "Rules to highlight “declare” and “struct” statements, as used in “redlog”.")

(defconst reduce-font-lock--keywords-3
  `(;; Apply specific rules before more general rules:
    ,@reduce-font-lock--preprocessor-rules

    ;; Fluid and global type declarations, which involve special cases
    ;; of quoted lists:
    (,(concat "\\_<\\(fluid\\|global\\)\\_>"
              reduce-whitespace-regexp "*" "'\(")
     (1 font-lock-type-face)
     (,(concat "\\=" reduce-whitespace-regexp "*"
               "\\(" reduce-identifier-regexp "\\)")
      ;; Pre-form -- return position of terminator to limit search:
      (save-excursion (re-search-forward "[\;$]")) nil
      (1 font-lock-variable-name-face)))

    ;; Quoted identifiers:
    (,(concat "'\\(" reduce-identifier-regexp "\\)")
     (1 font-lock-constant-face))

    (;; Quoted lists (arbitrarily nested and multi-line):
     "'\\(\(\\)"
     (1 font-lock-constant-face)
     ("\\(?:.\\|\n\\)"     ; match anything including \n
      ;; This may be a hack but it seems to work!
      ;; Pre-form function sets search limit to end of list:
      (save-excursion (backward-char) (forward-sexp) (point))
      nil
      (0 font-lock-constant-face)))

    ,@reduce-font-lock--keywords-2
    ,reduce-font-lock--asserted-type-rule
    ,@reduce-font-lock--assert-declare/struct-rules

    ;; Module keyword and module name:
    (,(concat "\\(?:^\\|[^']\\)\\_<\\(module\\)"
              reduce-whitespace-regexp "+"
              "\\(" reduce-identifier-regexp "\\)")
     (1 font-lock-keyword-face)
     (2 font-lock-constant-face))

    ;; Endmodule and other symbolic-mode keywords:
    (lambda (limit)
      (reduce-font-lock--kwd-search
       "\\_<\\(?:\
endmodule\\|lambda\\|precedence\\|\
assert\\(?:_\\(?:un\\)?install\\(?:_all\\)?\\)?\
\\)\\_>" limit))

    ;; Symbolic-mode functions:
    ((lambda (limit)
       (reduce-font-lock--kwd-search
        "\\_<\\(?:\
function\\|newtok\\|\
get\\|put\\|deflist\\|flag\\|remprop\\|remflag\
\\)\\_>" limit))
     . font-lock-builtin-face)

    ;; Symbolic-mode types:
    ((lambda (limit)
       (reduce-font-lock--kwd-search
        "\\_<\\(?:switch\\|share\\|rlistat\\|asserted\\)\\_>" limit))
     . font-lock-type-face)

    ;; Lambda arguments:
    ;; lambda arg ;
    ;; lambda ( arg1 , arg2 , ... ) ;
    (,(concat "\\_<lambda\\_>"
              reduce-whitespace-regexp "*" "\(?")
     (,(concat "\\=" reduce-whitespace-regexp "*"
               "\\(" reduce-identifier-regexp "\\)"
               reduce-whitespace-regexp "*" "[,\)]?")
      nil nil
      (1 font-lock-variable-name-face))))
  "List of “symbolic” REDUCE fontification rules.
Algebraic (‘reduce-font-lock--keywords-2’) plus preprocessor
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
      (re-search-forward "[;$]" nil 1)  ; if un-terminated move to EOB
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
  (setq-local
   reduce-font-lock--level
   ;; The value of ‘font-lock-maximum-decoration’ may be an alist,
   ;; non-negative integer, t (meaning max) or nil (meaning 0).
   (let (level)
     (if (consp font-lock-maximum-decoration) ; alist
         (when (setq level (or (assoc 'reduce-mode font-lock-maximum-decoration)
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
    ["Symbolic (3)" (reduce-font-lock--change 3)
     :style radio :selected (eq reduce-font-lock--level 3) :active t
     :help "Algebraic plus main symbolic-mode constructs"]
    ["Algebraic (2)" (reduce-font-lock--change 2)
     :style radio :selected (eq reduce-font-lock--level 2) :active t
     :help "Basic plus procedures, blocks and types"]
    ["Basic (1)" (reduce-font-lock--change 1)
     :style radio :selected (eq reduce-font-lock--level 1) :active t
     :help "Minimal plus comment statements, main syntactic keywords and group delimiters"]
    ["Minimal (0)" (reduce-font-lock--change 0)
     :style radio :selected (eq reduce-font-lock--level 0) :active t
     :help "Strings, syntactic comments, warnings, errors and trace output only"]))

(easy-menu-define                       ; (symbol maps doc menu)
  reduce-fontification-submenu
  nil
  "REDUCE Fontification Submenu."
  reduce-font-lock--submenu)

(defvar reduce-mode-map)                ; defined in reduce-mode.el

(define-key-after (lookup-key reduce-mode-map [menu-bar REDUCE])
  [Fontification] (cons "Syntax Highlighting" reduce-fontification-submenu)
  t)

(defun reduce-font-lock--change (level)
  "Re-fontify at the specified LEVEL."
  (let ((name (elt ["minimal" "basic" "algebraic" "symbolic"] level)))
    (if (eq reduce-font-lock--level level)
        (message "REDUCE Font Lock decoration unchanged (level %d : %s)."
                 level name)
      (let ((font-lock-maximum-decoration level))
        (font-lock-refresh-defaults))
      (setq reduce-font-lock--level level)
      (message "REDUCE Font Lock decoration set to level %d : %s."
               level name))))


;;;;; *****************************
;;;;; REDUCE Run mode fontification
;;;;; *****************************

(defconst reduce-font-lock--run-keywords
  '(
    reduce-font-lock--run-keywords-0    ; Minimal = nil
    reduce-font-lock--run-keywords-1    ; Basic
    reduce-font-lock--run-keywords-2    ; Algebraic
    reduce-font-lock--run-keywords-3    ; Symbolic = t
    )
  "Syntax highlighting for running REDUCE.
A list of symbols corresponding to increasing fontification.
Each is assigned a ‘font-lock-keywords’ value for REDUCE Run
mode.  The symbols are in order of increasing fontification
level, which is selected by the value of
‘font-lock-maximum-decoration’.  This defaults to t, meaning
maximal fontification.  The levels are strictly cumulative and
their names should not be taken too literally!")

(defvar reduce-run-mode-map)           ; defined in reduce-run-mode.el

(defun reduce-font-lock--run-mode ()
  "Set up font-lock mode.  Called in ‘reduce-run-mode’."
  ;; These variables are automatically buffer-local:
  (setq font-lock-defaults
        ;; reduce-font-lock--run-keywords evaluates to a list of symbols!
        (list reduce-font-lock--run-keywords ; KEYWORDS
              nil                            ; KEYWORDS-ONLY
              t)                             ; CASE-FOLD
        font-lock-multiline t)               ; for comment statements
  ;; Additional support for comment statements:
  (add-to-list 'font-lock-extend-region-functions
               #'reduce-font-lock--extend-region-for-comment-statement)
  (reduce-font-lock--level)             ; for font-lock menu
  (define-key-after (lookup-key reduce-run-mode-map [menu-bar Run\ REDUCE])
    [Fontification] (cons "Syntax Highlighting" reduce-fontification-submenu)
    t))

(defconst reduce-font-lock--run-keywords-0
  '(;; REDUCE and CSL warning and error messages:
    ("\\(?:\\*\\*\\*\\|\\+\\+\\+\\).*" . font-lock-warning-face)
    ;; Rtrace output:
    ("^\\(?:Enter\\|Leave\\) ([0-9]+) [^ \n]+\\(?: =\\)?" . font-lock-warning-face)
    ("^Rule.*:" . font-lock-warning-face)
    ;; CSL trace output:
    ("^\\(?:Entering .*\\| *Arg[0-9]+:\\|Value = \\)" . font-lock-warning-face))
  "Syntax highlighting rules for REDUCE output.")

(defconst reduce-font-lock--run-keywords-1
  (append reduce-font-lock--run-keywords-0
          reduce-font-lock--keywords-1)
  "List of “basic” REDUCE Run mode fontification rules.")

(defconst reduce-font-lock--run-keywords-2
  (append reduce-font-lock--run-keywords-0
          reduce-font-lock--keywords-2)
  "List of “algebraic” REDUCE Run mode fontification rules.")

(defconst reduce-font-lock--run-keywords-3
  (append reduce-font-lock--run-keywords-0
          reduce-font-lock--keywords-3)
  "List of “symbolic” REDUCE Run mode fontification rules.")

(provide 'reduce-font-lock)

;;; reduce-font-lock.el ends here
