;;; reduce-font-lock.el --- Syntax highlighting for REDUCE source code

;; Copyright (C) 2022 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Created: 6 June 2022 as a separate file (was part of reduce-mode.el)
;; Time-stamp: <2022-09-14 17:25:41 franc>
;; Keywords: languages, faces
;; Homepage: https://reduce-algebra.sourceforge.io/reduce-ide/
;; Package-Version: 1.7
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

;; Based on code by Rainer Schöpf.

;; Note that Font Lock Mode is documented in the ELisp manual under
;; Major and Minor Modes.  Syntactic fontification happens first; it
;; finds %-comments and string constants and highlights them.
;; Search-based fontification happens second.

;; Regard quoted identifiers and lists as data and don't fontify them.

;; Font Lock mode processes the elements of ‘font-lock-keywords’ one
;; by one, and for each element, it finds and handles all matches.
;; Ordinarily, once part of the text has been fontified already, this
;; cannot be overridden by a subsequent match in the same text; but
;; you can specify different behavior using the OVERRIDE element of a
;; SUBEXP-HIGHLIGHTER.

;;; Code:

(defconst reduce-font-lock--keywords
  '(
    reduce-font-lock--keywords-0     ; Minimal = nil
    reduce-font-lock--keywords-1     ; Algebraic
    reduce-font-lock--keywords-2     ; Symbolic
    reduce-font-lock--keywords-3     ; Maximal = t
    )
  "A list of symbols corresponding to increasing fontification.
Each is assigned a ‘font-lock-keywords’ value for REDUCE mode.
The symbols are in order of increasing fontification level, which
is selected by the value of ‘font-lock-maximum-decoration’.
This defaults to t, meaning maximal fontification.")

(defconst reduce-font-lock--syntactic-keywords
  ;; ((MATCHER SUBEXP SYNTAX OVERRIDE LAXMATCH) ... )
  ;; where SYNTAX = (SYNTAX-CODE . MATCHING-CHAR)
  ;;   If this proves unreliable, try
  ;;    '(("\".*\\(!\\)\"" 1 (1 . nil)))
  ;;   i.e. only mark ! at end of a string as punctuation.
  ;;   But this may be slow!
  '(("[^'\(]\\(!\\)\"" 1 (1 . nil)))
  "Mark ! followed by \" as having punctuation syntax (syntax-code 1)
unless preceded by ' or (, for correct syntax highlighing of strings.")

(defun reduce-font-lock-mode ()
  "Set up font-lock mode."
  ;; Variables automatically buffer-local.
  (setq font-lock-defaults
        ;; reduce-font-lock--keywords evaluates to a list of symbols!
        (list reduce-font-lock--keywords     ; KEYWORDS
              nil                            ; KEYWORDS-ONLY
              t                              ; CASE-FOLD
              nil                            ; SYNTAX-ALIST
              (cons                          ; (VARIABLE . VALUE) ...
               'font-lock-syntactic-keywords ; obsolete since 24.1! Use
                                        ; syntax-propertize-function
                                        ; instead!
               reduce-font-lock--syntactic-keywords)
              ))
  (reduce-font-lock--level)             ; for font-lock menu
  (setq font-lock-multiline t)          ; for comment statements
  ;; Additional support for comment statements:
  (add-to-list 'font-lock-extend-region-functions
               #'reduce-font-lock--extend-region-for-comment-statement)
  ;; Make all parsing respect the syntax property set by the above
  ;; font-lock option (which is essential to parse "...!"):
  (set (make-local-variable 'parse-sexp-lookup-properties) t))


;;;; **************************
;;;; Search-based Fontification
;;;; **************************

;;;;; Minimal fontification

(defconst reduce-identifier-regexp
  "\\(?:[a-z]\\|!.\\)\
\\(?:\\w\\|\\s_\\|!.\\)*"
  ;; NB: digits have word syntax
  "Regular expression matching a REDUCE identifier.
Identifiers consist of one or more alphanumeric
characters (i.e. alphabetic letters or decimal digits) the first
of which must be alphabetic.  In addition, the underscore
character (_) is considered a letter if it is within an
identifier.  Special characters may be used in identifiers too,
even as the first character, but each must be preceded by an
exclamation mark in input.")

(defconst reduce-infix-regexp
  "where\\|when\\|or\\|and\\|member\\|memq\\|neq\\|eq")

(defconst reduce-keyword-regexp
  (mapconcat #'identity
             (list
              "begin" "end" "return" "<<" ">>"
              "if" "then" "else" "ws"
              "while" "do" "repeat" "until"
              "collect" "join" "conc" "sum" "product"
              "for\\(?:\\s-*\\(?:all\\|each\\)\\)?" "step"
              "in" "on" "off" "write" "pause"
              "such\\s-+that" "let" "match" "clear\\(?:rules\\)?"
              "order" "factor" "remfac" "showtime"
              "index" "mass" "mshell"
              ;; "assert_install" "assert_install_all"
              ;; "assert_uninstall" "assert_uninstall_all"
              ;; "assert"
              "assert\\(?:_\\(?:un\\)?install\\(?:_all\\)?\\)?"
              ;; Lisp keywords used frequently in REDUCE:
              "lambda" "function"
              ;; "put" "flag" "remprop" "remflag"
              reduce-infix-regexp)
             "\\|")
  ;; module/endmodule keywords are handled specially in
  ;; reduce-font-lock--keywords-symbolic.
  "Regular expression matching a REDUCE keyword.")

(defconst reduce-font-lock--keywords-00
  `((reduce-font-lock--match-comment-statement
     . (1 font-lock-comment-face t))

    ;; Main keywords:
    (,(concat
       ;; Ignore 'keyword, _keyword, #keyword:
       "\\(?:^\\|[^'_#]\\)"
       "\\<\\(" reduce-keyword-regexp "\\)\\>"
       ;; Ignore composite identifiers beginning with a keyword:
       "[^!_#]")
     (1 font-lock-keyword-face)
     ;; Handle consecutive keywords:
     (,(concat "\\<\\(" reduce-keyword-regexp "\\)\\>[^!_#]")
      nil nil (1 font-lock-keyword-face))))
  "List of rules to highlight comment statements and main keywords.
Spliced into the start of all other rule lists.")

(defconst reduce-type-regexp
  "algebraic\\|symbolic\\|lisp\\|scalar\\|integer\\|real")

(defconst reduce-font-lock--keywords-0
  `("reduce-font-lock--keywords-0"      ; TEMPORARY label for debugging

    ,@reduce-font-lock--keywords-00

    ;; References:
    "\\<\\go\\(?:\\s-*to\\)?\\>"

    ;; Procedure declarations:
    (,(concat "\\<\\(procedure\\)\\s-+"
              "\\(" reduce-identifier-regexp "\\)")
     (1 font-lock-keyword-face)
     (2 font-lock-function-name-face))

    ;; Type declarations:
    ;; (Ignore quoted keywords and composite identifiers.)
    (,(concat
       "\\(?:^\\|[^'_]\\)\\<\\("
       reduce-type-regexp
       "\\)\\>[^!_]")
     (1 font-lock-type-face)))
  "List of minimal REDUCE fontification rules.
Highlights comment statements, main keywords and procedure definitions.
No variables are fontified.")


;; *****************************************************************
;; Assertion and preprocessor rules based on code by Thomas Sturm.
;; A good test file for all assertion rules is "redlog/cl/clqe.red".

;; A constant with a name of the form ‘font-lock-rule’ becomes an
;; element of the list assigned by ‘reduce-mode’ to
;; ‘font-lock-keywords’, which directly controls search-based
;; fontification, whereas a constant with a name of the form
;; ‘font-lock-rules’ (plural) below becomes appended to or spliced
;; into the list assigned to ‘font-lock-keywords’.
;; *****************************************************************

(defconst font-lock-default-face 'font-lock-default-face
  "A copy of the default face for use by REDUCE Font Lock mode.")

(copy-face 'default 'font-lock-default-face)

(defconst reduce-font-lock--asserted-type-rule
  `("procedure"
     ;; anchored-highlighter to handle the rest of the statement:
    ,(concat "[^!]:\\s-*\\(" reduce-identifier-regexp "\\)") nil nil
    (1 font-lock-type-face t))
  "Rules to highlight types of procedure arguments and return values.")

(defconst reduce-font-lock--assert-declare/struct-rules
  `((,(concat
       "\\(declare\\)\\s-+"
       "\\(" reduce-identifier-regexp "\\)\\s-*:")
     (1 font-lock-keyword-face)
     (2 font-lock-function-name-face)
     ;; anchored-highlighter to handle the rest of the statement:
     (,reduce-identifier-regexp nil nil (0 font-lock-type-face)))
    (,(concat
       "\\(struct\\)\\s-+"
       "\\(" reduce-identifier-regexp "\\)"
       ;; optionally followed by...
       "\\(?:\\s-+\\(\\(?:checked\\|asserted\\)\\s-+by\\)\\s-+"
       "\\(" reduce-identifier-regexp "\\)\\)?")
     (1 font-lock-keyword-face)
     (2 font-lock-type-face)
     (3 font-lock-keyword-face t)
     (4 font-lock-function-name-face)))
  "Rules to highlight “declare” and “struct” statements, as used in “redlog”.")

(defconst reduce-font-lock--preprocessor-rules
  `((,(concat
       "\\(#define\\)\\s-+"
       "\\(" reduce-identifier-regexp "\\)\\s-+"
       "\\(" reduce-identifier-regexp "\\)")
     (1 font-lock-preprocessor-face)
     (2 font-lock-variable-name-face)
     (3 font-lock-variable-name-face))
    ("\\(#if\\)\\s-+\\(.*\\)"
     (1 font-lock-preprocessor-face)
     (2 font-lock-default-face))
    ("\\(#elif\\)\\s-+\\(.*\\)"
     (1 font-lock-preprocessor-face)
     (2 font-lock-default-face))
    ("\\(#else\\)"
     (1 font-lock-preprocessor-face))
    ("\\(#endif\\)"
     (1 font-lock-preprocessor-face)))
  "Rules to highlight preprocessor #-directives.")


;; ****************************************
;; End of assertion and preprocessor rules.
;; ****************************************

(defconst reduce-font-lock--keywords-basic
  `(,@reduce-font-lock--keywords-00

    ;; Procedure declarations:
    ;; procedure name arg ;  [where arg may be missing]
    (,(concat "\\<\\(procedure\\)\\s-+"
              "\\(" reduce-identifier-regexp "\\)\\s-+"
              "\\(" reduce-identifier-regexp "\\)?\\s-*[;$]")
     (1 font-lock-keyword-face)
     (2 font-lock-function-name-face)
     (3 font-lock-variable-name-face))
    ;; procedure name ( arg1 , arg2 , ... )
    (,(concat "\\<\\(procedure\\)\\s-+"
              "\\(" reduce-identifier-regexp "\\)\\s-*(?")
     (1 font-lock-keyword-face)
     (2 font-lock-function-name-face)
     ;; Anchored matches (single line only!):
     (,(concat "\\s-*\\(" reduce-identifier-regexp "\\)\\s-*[,\)]")
      nil nil (1 font-lock-variable-name-face)))

    ;; Type declarations: e.g.
    ;; scalar var1 , var2 , ... ;
    ("\\<\\(scalar\\|integer\\|real\\)\\s-"
     (1 font-lock-type-face)
     ;; Anchored matches (single line only!):
     (,(concat "\\s-*\\(" reduce-identifier-regexp "\\)\\s-*\\s.")
      nil nil (1 font-lock-variable-name-face)))

    ;; References -- goto and labels:
    ;; go to label; ... label :
    (,(concat "\\<\\(go\\(?:\\s-*to\\)?\\)\\s-+"
              "\\(" reduce-identifier-regexp "\\)")
     (1 font-lock-keyword-face)
     (2 font-lock-constant-face))
    (,(concat "\\(?:^\\|[\;$]\\)\\s-*\\("
              reduce-identifier-regexp "\\)\\s-*:[^=]")
     . (1 font-lock-constant-face))

    ,reduce-font-lock--asserted-type-rule
    ,@reduce-font-lock--preprocessor-rules)
  "List of basic REDUCE fontification rules including variable fontification.")


;;;;; Algebraic fontification

(defconst reduce-font-lock--keywords-algebraic
  `(;; Operator declarations of the form ‘type op1, op2, ...’
    (,(concat "\\_<\\(?:"
              (mapconcat #'identity
                         '("even" "odd"
                           "linear" "noncom"
                           "\\(?:anti\\)?symmetric"
                           "operator" "infix" "precedence"
                           "vector")
                         "\\|")
              "\\_>\\)")
     ;; Subexp highlighter:
     (0 font-lock-type-face)
     ;; Anchored highlighter:
     (,(concat "\\s-*\\(" reduce-identifier-regexp "\\)\\s-*[,;$]")
      ;; Pre-form -- return position of terminator to limit search:
      (save-excursion (re-search-forward "[;$]"))
      nil (1 font-lock-function-name-face)))

    ;; Array and matrix type declarations: e.g.
    ;; array a 10, b(2,3,4);
    ;; matrix x(2,1),y(3,4),z;
    ("\\_<\\(?:array\\|matrix\\)\\_>"
     ;; Subexp highlighter:
     (0 font-lock-type-face)
     ;; Anchored highlighter:
     (,(concat "\\s-*\\(" reduce-identifier-regexp "\\)"
               ;; Optional bounds with optional ():
               "\\s-*\\(?:\\(?:(.*?)\\)\\|\\w*\\)\\s-*[,;$]"
               )
      ;; Pre-form -- return position of terminator to limit search:
      (save-excursion (re-search-forward "[;$]"))
      nil (1 font-lock-function-name-face)))

    ;; Symbolic constants:
    ("[^[:alpha:]_]\\(e\\|i\\|infinity\\|nil\\|pi\\|t\\)\\_>"
     ;; Allow 5pi to match pi, etc.  Digits have word syntax.
     ;; Must also match within i*pi/2, etc.
     (1 font-lock-constant-face)))
  "List of more algebraic-mode REDUCE fontification rules.
Operator, operator type and vector declarations; array and matrix
declarations with or without bounds; symbolic constants.")


;;;;; Symbolic fontification

(defconst reduce-font-lock--keywords-symbolic
  `(;; References -- module:
    (,(concat "\\<\\(module\\)\\s-+"
              "\\(" reduce-identifier-regexp "\\)")
     (1 font-lock-keyword-face)
     (2 font-lock-constant-face))

    "endmodule"

    ;; Type declarations:
    ;; ("\\<\\(fluid\\|global\\)\\>\\s-*'(\\([^\)]*\\))"
    ;;  ;; Should match a multi-line list because [^\)] matches \n.
    ;;  (1 font-lock-type-face)
    ;;  (2 font-lock-variable-name-face))
    ;; But don't fontify quoted data:
    ("fluid\\|global" . font-lock-type-face)

    ;; Ignore quoted keywords and composite identifiers.
    ("\\(?:^\\|[^'_]\\)\\<\\(\
algebraic\\|symbolic\\|lisp\\|\
newtok\\|precedence\\|switch\\|share\\|\
expr\\|s?macro\\|inline\\|asserted\
\\)\\>[^!_]"
     (1 font-lock-type-face))

    ,@reduce-font-lock--assert-declare/struct-rules)
  "List of more symbolic-mode REDUCE fontification sub-rules.")


;;;;; Maximal fontification

(defconst reduce-number-regexp
  "[[:digit:]]+\
\\(?:\\.[[:digit:]]*\\)?\
\\(?:e[+-]?[[:digit:]]+\\)?"
  "Regular expression matching a REDUCE unsigned integer or real number.
Real numbers can be input in two ways:
• as a sequence of any number of decimal digits with an embedded
or trailing decimal point;
• as above followed by a decimal exponent which is written as the
letter e followed by a signed or unsigned integer.
For example, 32., 32.0, 0.32e2 and 320.e-1 are all
representations of 32.")

(defconst reduce-font-lock--keywords-extra
  `(;; Quoted identifiers:
    (,(concat "'\\(" reduce-identifier-regexp "\\)")
     (1 font-lock-constant-face))

    (;; Quoted lists (arbitrarily nested and multi-line):
     "'\\((\\)"
     (1 font-lock-constant-face)
     ("\\(?:.\\|\n\\)"         ; match anything including \n
      ;; This is a hack but it seems to work!
      ;; Pre-form function sets search limit to end of list:
      (save-excursion (backward-char) (forward-sexp) (point))
      nil
      (0 font-lock-constant-face)))

    ;; Function calls:
    ;; fn ( ), fn { }, fn " ", fn 'data, fn << >>
    (,(concat "\\(" reduce-identifier-regexp "\\)"
              "\\s-*\\(?:[\(\{\"']\\|<<\\)")
     (1 font-lock-function-name-face))
    ;; fn space variable-or-number optional-space punctuation
    (,(concat "\\(" reduce-identifier-regexp "\\)"
              "\\s-+\\(?:\\(?:"
              reduce-identifier-regexp "\\)\\|\\(?:"
              reduce-number-regexp
              "\\)\\)\\s-*\\s.")
     (1 font-lock-function-name-face))

    ;; Match f1 f2 ... fn in
    ;; f1 f2 ... fn f(...)  or  f1 f2 ... fn any_identifier
    ;; Commented out for now since overly aggressive!
    ;; (reduce-font-lock--match-functions
    ;;  . (0 font-lock-function-name-face t))

    ;; Variable invocations:
    ;; ( var), var PUNCTUATION, var EOL, var KEYWORD, var INFIX )
    ;; (,(concat
    ;;    "\\(" reduce-identifier-regexp "\\)"
    ;;    "\\s *\\("
    ;;    "\\s\)\\|\\s.\\|$\\|"
    ;;    "\\s \\<\\(" reduce-keyword-regexp
    ;;    "\\|\\(" reduce-infix-regexp "\\)\\)\\>"
    ;;    "\\)")
    ;;  (1 font-lock-variable-name-face)
    ;;  (4 font-lock-default-face nil t))

;;; Should force ALL infix ops into right font!

    )
  "List of maximal REDUCE fontification rules.")


;;;; ********************************************
;;;; Support for nested functions (experimental!)
;;;; Not currently used.
;;;; ********************************************

(defconst anchored-reduce-identifier-regexp
  (concat "\\=\\s-+\\(" reduce-identifier-regexp "\\)"))

(defconst entire-reduce-keyword-regexp
  (concat "\\`\\(?:"
          reduce-keyword-regexp "\\|" reduce-type-regexp
          "\\|module\\|procedure\\)\\'"))

(defsubst reduce-font-lock--match-keyword (num)
  "Return non-nil if ‘(match-string NUM)’ is a REDUCE keyword."
  (string-match-p                   ; avoids modifying the match data.
   entire-reduce-keyword-regexp
   (match-string num)))

(defsubst reduce-font-lock--match-procedure (num)
  "Return non-nil if ‘(match-string NUM)’ is 'procedure'."
  (string-match-p                   ; avoids modifying the match data.
   "\\`procedure\\'"
   (match-string num)))

(defconst entire-reduce-functional-keyword-regexp
  (concat
   "\\`\\(?:" "comment\\|"
   "begin\\|" "if\\|" "for\\(?:\\s-*\\(?:all\\|each\\)\\)?\\|"
   "\\)\\'"))

(defsubst reduce-font-lock--match-functional-keyword (num)
  "Return non-nil if “(match-string NUM)” is a REDUCE functional keyword."
  (string-match-p                   ; avoids modifying the match data.
   entire-reduce-functional-keyword-regexp
   (match-string num)))

;; Use commented out for now since overly aggressive!
(defun reduce-font-lock--match-functions (limit)
  "Search for functions without () between point and LIMIT.
Also match composed function calls where the final call has ().
If successful, return non-nil and set the match data to describe
the function name(s) matched; otherwise return nil."
  ;; Fontification will call this function repeatedly with the same
  ;; limit, and with point where the previous invocation left it,
  ;; until it fails.  On failure, there is no need to reset point in
  ;; any particular way.

  ;; An identifier (function or variable name) matches
  ;; reduce-identifier-regexp but not reduce-keyword-regexp.  Function
  ;; names followed by a variable, function name or functional keyword
  ;; indicates successive composed functions of the form

  ;; f1 f2 ... fn f(...)  or  f1 f2 ... fn var_or_functional_keyword

  ;; where only f1 f2 ... fn should be matched because f should
  ;; already be fontified and var_or_functional_keyword should not be
  ;; fontified by this rule; it may be a variable or one of the
  ;; functional keywords that can return a value: begin, if, for*.
  ;; (message "Function composition search: %d %d" (point) limit)
  (let (beg newend end)
    ;; Find the next identifier that is not a keyword before limit
    ;; and save its beginning and end positions.
    (while
        (and
         ;; Find next identifier or stop:
         (re-search-forward
          reduce-identifier-regexp limit t)
         ;; If identifier is procedure then skip to the following
         ;; terminator and return nil:
         (if (reduce-font-lock--match-procedure 0)
             (progn (re-search-forward "[;$]" limit t) nil)
           ;; If identifier is a keyword then ignore it and continue
           ;; the search, otherwise update end data and stop search:
           (if (reduce-font-lock--match-keyword 0)
               t
             (setq beg (match-beginning 0) newend (match-end 0))
             nil))))
    (when beg                           ; found initial identifier
      ;; Find successive identifiers that are not keywords before
      ;; limit, each of which validates the previous match as an
      ;; identifier, and update the match end position.  Stop on
      ;; finding a functional keyword (e.g. begin, if) or non-keyword.
      (while
          (and
           ;; Find next identifier or stop:
           (re-search-forward
            anchored-reduce-identifier-regexp limit t)
           ;; Check identifier:
           (if (reduce-font-lock--match-keyword 1)
               ;; keyword...
               (if (reduce-font-lock--match-functional-keyword 1)
                   ;; functional keyword so update end and stop:
                   (progn (setq end newend) nil)
                 ;; regular keyword so just stop:
                 nil)
             ;; not a keyword so update end data and continue search:
             (setq end newend newend (match-end 0)))))
      (when end                         ; also found final identifier
        (set-match-data (list beg end))
        ;; (message "Function composition found: %d %d" beg end)
        newend ;; t
        ;; (add-face-text-property beg end 'font-lock-warning-face) ; FOR DEBUGGING!
        ))))


;;;; ***********************************
;;;; End of support for nested functions
;;;; ***********************************

(defconst reduce-font-lock--keywords-1
  `("reduce-font-lock--keywords-1"       ; TEMPORARY label for debugging
    ,@reduce-font-lock--keywords-basic
    ,@reduce-font-lock--keywords-algebraic)
  "Standard algebraic-mode REDUCE fontification rules.")

(defconst reduce-font-lock--keywords-2
  `("reduce-font-lock--keywords-2"       ; TEMPORARY label for debugging
    ,@reduce-font-lock--keywords-basic
    ,@reduce-font-lock--keywords-symbolic)
  "Standard symbolic-mode REDUCE fontification rules.")

(defconst reduce-font-lock--keywords-3
  `("reduce-font-lock--keywords-3"      ; TEMPORARY label for debugging
    ,@reduce-font-lock--keywords-basic
    ,@reduce-font-lock--keywords-algebraic
    ,@reduce-font-lock--keywords-symbolic
    ,@reduce-font-lock--keywords-extra)
  "Full REDUCE fontification rules.")


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
      (re-search-forward "\\(\\<comment\\>[^;$]*[;$]\\)" limit t)
    ;; If successful, check that "comment" is preceded by beginning of
    ;; buffer or a terminator, possibly with white space and/or %
    ;; comments in between:
    (save-excursion
      (goto-char (match-beginning 0))
      (save-match-data
        (looking-back "\\(?:\\`\\|[;$]\\)\
\\(?:\\s-*\\(?:%.*\\)?\n\\)*\\s-*" nil)))))

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
    ;; ["Toggle ‘!’ Syntax" reduce-font-lock--toggle-escape t]
    ["Maximal (3)" (reduce-font-lock--change 3)
     :style radio :selected (eq reduce-font-lock--level 3) :active t]
    ["Symbolic (2)" (reduce-font-lock--change 2)
     :style radio :selected (eq reduce-font-lock--level 2) :active t]
    ["Algebraic (1)" (reduce-font-lock--change 1)
     :style radio :selected (eq reduce-font-lock--level 1) :active t]
    ["Minimal (0)" (reduce-font-lock--change 0)
     :style radio :selected (eq reduce-font-lock--level 0) :active t]))

(easy-menu-define                       ; (symbol maps doc menu)
  reduce-fontification-submenu
  nil
  "REDUCE Fontification Submenu."
  reduce-font-lock--submenu)

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

(defun reduce-font-lock--toggle-escape (&optional arg)
  "Toggle “!” escape syntax for REDUCE Font Lock mode (only) and re-fontify.
With ARG, clear “!” escape syntax if ARG >= 0 and set it if ARG < 0.
For example,
\(add-hook 'reduce-mode-hook
      (function (lambda () (reduce-font-lock--toggle-escape 1))))
will turn off the default font-lock escape syntax for “!”."
  (interactive "P")
  (require 'font-lock)
  (let ((reset font-lock-syntax-table))
    (font-lock-mode 0)
    (font-lock-set-defaults)           ; resets font-lock-syntax-table
    (if arg (setq reset (< (prefix-numeric-value arg) 0)))
    (if reset
        ;; ‘!’ syntax has been reset to ‘escape’, so do nothing:
        () ;; (setq font-lock-syntax-table nil) ; default
      ;; Set ‘!’ syntax to punctuation:
      (setq font-lock-syntax-table
            (copy-syntax-table reduce-mode-syntax-table))
      (modify-syntax-entry ?! "." font-lock-syntax-table)) ; punctuation
    (font-lock-mode 1)
    ;; Display message so it is not overwritten by font-lock messages:
    (message
     (if font-lock-syntax-table
         "REDUCE Font Lock syntax (only) for ‘!’ set to ‘punctuation’."
       "REDUCE Font Lock syntax table reset."))))

(provide 'reduce-font-lock)

;;; reduce-font-lock.el ends here
