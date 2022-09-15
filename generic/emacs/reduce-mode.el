;;; reduce-mode.el --- Major mode to edit REDUCE computer-algebra code

;; Copyright (C) 1998-2001, 2012, 2017-2019, 2022 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Created: late 1992
;; Time-stamp: <2022-09-14 17:25:41 franc>
;; Keywords: languages
;; Homepage: https://reduce-algebra.sourceforge.io/reduce-ide/
;; Package-Version: 1.7

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

;; This file is intended to be installed as part of the REDUCE IDE
;; package; see the homepage for guidance on installing REDUCE IDE.

;; Contributions by Rainer Schoepf flagged ; RS
;; Schoepf@goofy.zdv.Uni-Mainz.DE

;; Contributions by Thomas Sturm flagged ; TS
;; sturm@redlog.eu

;;;###autoload
(add-to-list 'auto-mode-alist '("\\.\\(?:red\\|tst\\)\\'" . reduce-mode))

;; To turn on only REDUCE font-lock mode by default include
;; (add-hook 'reduce-mode-hook 'turn-on-font-lock)
;; or to turn on all supported font-lock modes by default include
;; (global-font-lock-mode 1)

;;; To do:

;;  BUGS
;;  ====
;;  ! should not be an escape IN STRINGS (motion by sexp, font-lock)

;;  Enhancements
;;  ============
;;  more flexible intelligent indentation, rationalize the code
;;  make skipping comment statements configurable (?)
;;  add RLisp88 support (?)
;;  more structure templates (?) – while, repeat

;;; Code:

(defconst reduce-mode-version
  ;; Extract version from Package-Version in file header:
  (eval-when-compile
    (require 'lisp-mnt)
    (save-excursion (lm-header "package-version")))
  "Version information for REDUCE mode.")

;; (message "Loading reduce-mode")  ; TEMPORARY!

(eval-when-compile                      ; keep compiler happy!
  (require 'timer))

;; Customizable user options:

;;;###autoload
(defgroup reduce nil
  "Support for editing and running REDUCE code."
  :tag "REDUCE"
  :group 'languages
  :link '(custom-manual "(reduce-ide)Top")
  :link '(url-link "https://reduce-algebra.sourceforge.io/reduce-ide/")
  ;; Include the REDUCE Run customization group:
  :load "reduce-run")

(defgroup reduce-interface nil
  "Interface options for editing and running REDUCE code."
  :tag "REDUCE Interface"
  :group 'reduce)

(defgroup reduce-display nil
  "Display options for editing and running REDUCE code."
  :tag "REDUCE Display"
  :group 'reduce)

(defgroup reduce-format nil
  "Format options for editing and running REDUCE code."
  :tag "REDUCE Format"
  :group 'reduce)

(defcustom reduce-mode-load-hook nil
  "List of functions to be called when REDUCE mode is loaded.
For example, ‘require-reduce-run’ to automatically load REDUCE
Run mode.  It can be used to customize global features of REDUCE
mode and so is a good place to put keybindings."
  :type 'hook
  :options '(require-reduce-run)
  :group 'reduce)

(defcustom reduce-mode-hook nil
  "List of functions to be called when REDUCE mode is entered.
For example, ‘turn-on-font-lock’ to turn on font-lock mode locally.
It can be used to customize buffer-local features of REDUCE mode."
  :type 'hook
  :group 'reduce)

;; Interface:

(defcustom reduce-imenu-generic-expression ; EXPERIMENTAL!
  '((nil "^\\([^%\n]+\\(ic\\|ro\\) \\)?\\s *procedure \\(\\w\\(\\w\\|\\s_\\|!.\\)*\\)" 3)
    ("Operators" "^\\([^%\n]+ic \\)?\\s *operator \\(\\w\\(\\w\\|\\s_\\|!.\\)*\\)" 2))
  "Imenu support for procedure definitions and operator declarations.
An alist with elements of the form (MENU-TITLE REGEXP INDEX) –
see the documentation for ‘imenu-generic-expression’."
  :type '(repeat (list (choice (const nil) string) regexp integer))
  :group 'reduce-interface)

(defcustom reduce-imenu nil
  "If non-nil REDUCE mode automatically calls ‘imenu-add-to-menubar’.
This adds a Contents menu to the menubar.  Default is nil."
  :type 'boolean
  :group 'reduce-interface)

(defcustom reduce-imenu-title "Procs/Ops"
  "The title to use if REDUCE mode adds a proc/op menu to the menubar.
Default is \"Procs/Ops\"."
  :type 'string
  :group 'reduce-interface)

(define-obsolete-variable-alias
  'reduce-max-up-tries 'reduce-max-escape-tries "1.7")

(defcustom reduce-max-escape-tries 2
  "Number of attempts required to escape a block or group.
This relates to repeated use of ‘reduce-forward-statement’ or
‘reduce-backward-statement’ from inside the block or group."
  :type 'integer
  :group 'reduce-interface)

(defcustom reduce-completion-alist
  '(("algebraic ")
    ("algebraic procedure ")
    ("ap" . "algebraic procedure ")
    ("begin" . reduce-insert-block)
    ("clearrules ")
    ("collect ")
    ("comment ")
    ("endmodule")
    ("factorize(")
    ("first ")
    ("for all ")
    ("for each ")
    ("freeof ")
    ("gensym()")
    ("ift" . reduce-expand-if-then)
    ("if...then" . reduce-expand-if-then)
    ("ife" . reduce-expand-if-then-else)
    ("if...then...else" . reduce-expand-if-then-else)
    ("impart ")
    ("infinity")
    ("integer ")
    ("length ")
    ("linear ")
    ("load_package ")
    ("member ")
    ("module ")
    ("operator ")
    ("order ")
    ("procedure ")
    ("product ")
    ("quotient(")
    ("remainder(")
    ("repart ")
    ("repeat ")
    ("repeat until ")
    ("resultant(")
    ("return ")
    ("reverse ")
    ("scalar ")
    ("second ")
    ("smember(")
    ("such that ")
    ("st" . "such that ")
    ("symbolic ")
    ("symbolic operator ")
    ("sop" . "symbolic operator ")
    ("symbolic procedure ")
    ("sp" . "symbolic procedure ")
    ("third ")
    ("until ")
    ("where ")
    ("while ")
    ("while do ")
    ("write ")
    ("<<" . reduce-insert-group)
    )
  "Alist of REDUCE symbols to be completed by ‘reduce-complete-symbol’.
Optional ‘cdr’ is a replacement string or nullary function (for structures)."
  :type '(repeat (cons string (choice (const nil) string function)))
  :group 'reduce-interface)

;; Formatting:

(defcustom reduce-indentation 3
  "Depth of successive indentations in REDUCE code."
  :type 'integer
  :group 'reduce-format)

(defcustom reduce-indent-line-conservative nil ; TS
  "If non-nil, ‘reduce-indent-line’ will not successively indent."
  :type 'boolean
  :group 'reduce-format)

(defcustom reduce-comment-region-string "%% "
  "String inserted by \\[reduce-comment-region] at start of each line."
  :version "1.21" ; Name was reduce-comment-region up to version 1555!
  :type 'string
  :group 'reduce-format)

(defcustom reduce-auto-indent-mode t
  "If non-nil then conditionally re-indent the current line.
This will happen after ‘reduce-auto-indent-delay’ seconds of idle
time if the text just typed matches ‘reduce-auto-indent-regex’."
  :set (lambda (symbol value)
     (reduce-auto-indent-mode (or value 0)))
  :initialize 'custom-initialize-default
  :type 'boolean
  :group 'reduce-format)

(defcustom reduce-auto-indent-delay 0.125
  "Time in seconds to delay before maybe re-indenting current line."
  :type 'number
  :group 'reduce-format)

(defcustom reduce-auto-indent-regexp "\\(else\\|end\\|>>\\)\\="
  "Auto indent current line if text just typed matches this regexp.
It should end with \\=\\=.  The default value is \"\\(else\\|end\\|>>\\)\\=\\=\"."
  :type 'regexp
  :group 'reduce-format)

;; Display:

(defcustom reduce-font-lock-mode-on t
  "If non-nil then turn on ‘reduce-font-lock-mode’ initially.
Defaults to t."
  :package-version '(reduce-ide . "1.6")
  :type 'boolean
  :group 'reduce-display)

(defcustom reduce-show-delim-mode-on show-paren-mode
  "If non-nil then turn on ‘reduce-show-delim-mode’ initially.
Since ‘reduce-show-delim-mode’ is a buffer-local minor mode, it
can also be turned on and off in each buffer independently.
Defaults to the value of ‘show-paren-mode’."
  :package-version '(reduce-ide . "1.54")
  :type 'boolean
  :group 'reduce-display)

(defcustom reduce-show-proc-mode nil
  "If non-nil then display current procedure name in mode line.
Update after ‘reduce-show-proc-delay’ seconds of Emacs idle time."
  :set (lambda (symbol value)
     (reduce-show-proc-mode (or value 0)))
  :initialize 'custom-initialize-default
  :type 'boolean
  :group 'reduce-display)

(defcustom reduce-show-proc-delay 0.125
  "Time in seconds to delay before showing the current procedure name."
  :type 'number
  :group 'reduce-display)

;; External variables:

;; Due to improvements of byte compilation around 2003 the compiler
;; would complain about ‘make-local-var’ on these later on. I left
;; unchanged another (too late) declaration for ‘which-func-mode’ below,
;; which appears not to disturb. TS

(defvar which-func-mode)
(defvar which-func-format)
(defvar imenu-space-replacement)

;; Internal variables:

(defvar reduce-imenu-done nil
  "Buffer-local: set to true if ‘reduce-imenu-add-to-menubar’ has been called.")
(make-variable-buffer-local 'reduce-imenu-done)


;;;; **********************
;;;; Keyboard and menu maps
;;;; **********************

(defvar reduce-mode-map
  (let ((map (make-sparse-keymap)))
    ;; (define-key map ">" 'reduce-self-insert-and-blink-matching-group-open)
    ;; (define-key map "\t" 'reduce-indent-line)
    (define-key map "\C-j" 'reindent-then-newline-and-indent)
    ;; (define-key map [(shift tab)] 'reduce-unindent-line) ; backtab
    (define-key map [backtab] 'reduce-unindent-line)
    (define-key map [del] 'backward-delete-char-untabify)
    (define-key map "\C-c\C-n" 'reduce-forward-statement)
    (define-key map "\C-c\C-p" 'reduce-backward-statement)
    (define-key map "\C-c\C-d" 'reduce-down-block-or-group)
    (define-key map "\C-c\C-u" 'reduce-up-block-or-group)
    (define-key map "\C-c\C-k" 'reduce-kill-statement)
    (define-key map "\C-\M-f" 'reduce-forward-sexp)
    (define-key map "\C-\M-b" 'reduce-backward-sexp)
    (define-key map "\C-\M-e" 'reduce-forward-procedure)
    (define-key map "\C-\M-a" 'reduce-backward-procedure)
    (define-key map "\C-\M-h" 'reduce-mark-procedure)
    (define-key map "\C-xnd" 'reduce-narrow-to-procedure)
    (define-key map "\C-ck" 'reduce-kill-procedure)
    ;; (define-key map "\e;" 'reduce-indent-comment) ; via global map
    (define-key map "\C-\M-\\" 'reduce-indent-region)
    (define-key map "\C-\M-q" 'reduce-indent-procedure)
    (define-key map "\C-c;" 'reduce-comment-region)
    (define-key map "\C-c:" 'reduce-comment-procedure)
    (define-key map "\M-q" 'reduce-fill-comment)
    (define-key map "\C-ci" 'reduce-insert-if-then)
    (define-key map "\C-cb" 'reduce-insert-block)
    (define-key map "\C-c<" 'reduce-insert-group)
    (define-key map "\C-\M-l" 'reduce-reposition-window)
    (define-key map "\C-\M-i" 'reduce-complete-symbol)
    (define-key map "\C-c\t" 'reduce-complete-symbol)
                                        ; since C-M-i used by flyspell
    map)
  "Keymap for REDUCE mode.")

;; REDUCE-mode menu bar and pop-up menu
(easy-menu-define           ; (symbol maps doc menu)
 reduce-mode-menu
 reduce-mode-map
 "REDUCE Mode Menu."
 `("REDUCE"
   ["Indent Line" indent-for-tab-command :active t
    :help "Re-indent the current line"]
   ["Unindent Line" reduce-unindent-line :active t
    :help "Unindent the current line by one indentation step"]
   ["Kill Statement" reduce-kill-statement :active t
    :help "Kill to the end of the current statement"]
   ["Fill Comment" reduce-fill-comment :active t
    :help "Fill the current comment"]
   ["(Un)Comment Region" reduce-comment-region :active mark-active
    :help "Toggle the commenting of the current region"]
   ;; "-- PROCEDURES --" ; not good in ntemacs
   "--"
   ["Forward Procedure" reduce-forward-procedure :active t
    :help "Move forward to the nearest end of a procedure"]
   ["Backward Procedure" reduce-backward-procedure :active t
    :help "Move backward to the nearest start of a procedure"]
   ["Indent Procedure" reduce-indent-procedure :active t
    :help "Re-indent the current procedure"]
   ["Mark Procedure" reduce-mark-procedure :active t
    :help "Mark the current procedure"]
   ["Reposition Window" reduce-reposition-window :active t
    :help "Scroll to show the current procedure optimally"]
   ["Narrow To Procedure" reduce-narrow-to-procedure :active t
    :help "Narrow the buffer to the current procedure"]
   ["(Un)Comment Proc" reduce-comment-procedure :active t
    :help "Toggle the commenting of the current procedure"]
   ["Kill Procedure" reduce-kill-procedure :active t
    :help "Kill the current procedure"]
   "--"
   ("Show / Find / Tag"
    ["Show Current Proc" reduce-show-proc-mode
     :style toggle :selected reduce-show-proc-mode :active t
     :help "Toggle display of the current procedure name"]
    ["Make Proc/Op Menu" (reduce-imenu-add-to-menubar t) :active (not reduce-imenu-done)
     :help "Show an imenu of procedures and operators"]
    "--"
    ["Find Tag..." xref-find-definitions :active t
     :help "Find a procedure definition using a tag file"]
    ["New TAGS Table..." visit-tags-table :active t
     :help "Select a new tag file"]
    "--"
    ["Tag Directory..." reduce-tagify-dir :active t
     :help "Tag REDUCE files in this directory"]
    ["Tag Dir & Subdirs..." reduce-tagify-dir-recursively :active t
     :help "Tag all REDUCE files under this directory"]
    )
   ;;   "-- TEMPLATES --" ; not good in ntemacs
   "--"
   ["Insert If-Then" reduce-insert-if-then :active t
    :help "Insert an ‘if-then’ template"]
   ["Insert Block" reduce-insert-block :active t
    :help "Insert a ‘block’ template"]
   ["Insert Group" reduce-insert-group :active t
    :help "Insert a ‘group’ template"]
   "--"
   ["Indent Region" reduce-indent-region :active mark-active
    :help "Re-indent the current region"]
   ["Indent Buffer" (reduce-indent-region (point-min) (point-max))
    :keys "C-u M-C-\\" :active t
    :help "Re-indent the current buffer"]
   "--"
   ["Command Mini Help" (apropos-command "reduce") :active t
    :help "Show a REDUCE Mode command summary"]
   ["Customize..." (customize-group 'reduce) :active t
    :help "Customize REDUCE Mode"]
   ["Show Version" reduce-mode-show-version :active t
    :help "Show the REDUCE Mode version"]
   ;; This seems to be obsolete in Emacs 26!
   ;; ["Outline" outline-minor-mode
   ;;  :style toggle :selected outline-minor-mode :active t
   ;;  :help "Toggle outline minor mode"]
   ["Update ChangeLog" add-change-log-entry-other-window :active t
    :help "Add change log entry other window"]
   ))

(defun reduce-mode-show-version ()
  "Echo version information for REDUCE mode."
  (interactive)
  (message "REDUCE mode – REDUCE IDE Package Version: %s" reduce-mode-version))


;;;; ************
;;;; Syntax table
;;;; ************

(defvar reduce-mode-syntax-table
  (let ((table (make-syntax-table)))
    (modify-syntax-entry ?\n ">" table) ; comment ender
    (modify-syntax-entry ?! "/" table)  ; single character quote
    (modify-syntax-entry ?# "'" table)  ; expression prefix
    (modify-syntax-entry ?$ "." table)  ; punctuation (RS)
    (modify-syntax-entry ?% "<" table)  ; comment starter
    (modify-syntax-entry ?& "." table)  ; punctuation
    (modify-syntax-entry ?' "'" table)  ; expression prefix
    (modify-syntax-entry ?* ". 23" table) ; C-style comment
    (modify-syntax-entry ?+ "." table)
    (modify-syntax-entry ?- "." table)
    (modify-syntax-entry ?/ ". 14" table) ; C-style comment
    (modify-syntax-entry ?< "." table)
    (modify-syntax-entry ?= "." table)
    (modify-syntax-entry ?> "." table)
    (modify-syntax-entry ?\\ "." table)
    (modify-syntax-entry ?| "." table)
    table)
  "Syntax table for REDUCE mode.")


;;;; *****************
;;;; REDUCE major mode
;;;; *****************

(declare-function reduce-font-lock-mode "reduce-font-lock" ())
(declare-function reduce-show-delim-mode "reduce-delim" ())

;;;###autoload
(define-derived-mode reduce-mode prog-mode "REDUCE"
  "Major mode for editing REDUCE source code – part of REDUCE IDE.
Version: see ‘reduce-mode-version’.\\<reduce-mode-map>
Author: Francis J. Wright (URL ‘https://sites.google.com/site/fjwcentaur’).
Website: URL ‘https://reduce-algebra.sourceforge.io/reduce-ide/’.
Comments, suggestions, bug reports, etc. are welcome.
Full documentation is provided in the Info node ‘(reduce-ide)Top’.

Commands are aware of REDUCE syntax, and syntax-directed commands
ignore comments, strings and character case.  Standard indentation and
comment commands are supported.  Modelled primarily on Lisp mode;
comment commands follow Lisp conventions.

“<<...>>” and “begin...end” are treated as bracketed or
symbolic expressions for motion, delimiter matching, etc.

The command ‘\\[reduce-indent-line]’ indents in a fixed style (mine!).
If re-run immediately after itself or ‘\\[reindent-then-newline-and-indent]’
or ‘\\[newline-and-indent]’ it indents further.
The indentation increment is the value of the variable ‘reduce-indentation’.

Structure template commands are provided to insert and indent
if-then (‘\\[reduce-insert-if-then]’), block (‘\\[reduce-insert-block]’) and group (‘\\[reduce-insert-group]’) constructs,
the latter optionally on a single line.

The command ‘\\[reduce-complete-symbol]’ performs REDUCE
keyword/phrase/structure completion.

Text highlighting is supported via the command ‘font-lock-mode’, and
the style of highlighting may be controlled by setting
‘font-lock-maximum-decoration’ to one of:

  0, nil : basic keyword highlighting;
  1      : algebraic-mode highlighting;
  2      : symbolic-mode highlighting;
  3, t   : full highlighting – of almost everything!

Text highlighting may also be controlled using the REDUCE menu.

Delete converts tabs to spaces as it moves back.
Blank lines separate paragraphs.  Percent signs start comments.
REDUCE mode defines the following local key bindings:

\\{reduce-mode-map}
The customization group ‘reduce’ affects this mode.  REDUCE mode
inherits from Prog mode, so the customization group ‘prog-mode’
also affects this mode.  Entry to this mode runs the hooks on
‘prog-mode-hook’ and ‘reduce-mode-hook’ (in that order)."
  :group 'reduce
  ;; Optionally set up font-lock mode:
  (and reduce-font-lock-mode-on
       (require 'reduce-font-lock "reduce-font-lock" t)
       (reduce-font-lock-mode))
  ;; Optionally turn on REDUCE minor modes:
  (and reduce-show-delim-mode-on
       (require 'reduce-delim "reduce-delim" t)
       (reduce-show-delim-mode))
  (if reduce-auto-indent-mode (reduce-auto-indent-mode t))
  ;; For reduce-show-proc-mode:
  (setq which-func-mode nil)           ; auto buffer local
  (setq-local which-func-format 'reduce-show-proc-string)
  (if reduce-show-proc-mode (reduce-show-proc-mode t))
  ;; This seems to be obsolete in Emacs 26!
  ;; Experimental support for outline minor mode (cf. lisp-mode.el)
  ;; ‘outline-regexp’ must match ‘heading’ from beginning of line;
  ;; length of match determines level:
  ;; (setq-local outline-regexp "[^ \t\n]")
  ;; Imenu support:
  (setq imenu-generic-expression       ; auto buffer local
        reduce-imenu-generic-expression)
  (setq-local imenu-space-replacement " ")
  ;; Necessary to avoid re-installing the same imenu:
  (setq reduce-imenu-done nil)
  (if reduce-imenu (reduce-imenu-add-to-menubar))
  ;; ChangeLog support:
  (setq-local add-log-current-defun-function
              #'reduce-current-proc)
  ;; (setq-local paragraph-start (concat "^$\\|" page-delimiter))
  (setq-local paragraph-separate
              ;; paragraph-start)
              (concat paragraph-start "\\|^%")) ; RS
  ;; so that comments at beginning of a line do not disturb reformatting.
  (setq-local paragraph-ignore-fill-prefix t)
  (setq-local indent-line-function 'reduce-indent-line)
  (setq-local comment-start "% ")
  (setq-local comment-start-skip
              "\\(?:^\\|[^!]\\)%+ *")   ; "%+ *" but not !%
  (setq comment-column 40)              ; auto buffer local
  (setq-local comment-indent-function #'reduce-comment-indent)
  ;; (setq fill-prefix "% ")        ; buffer local
 )

(defun reduce-imenu-add-to-menubar (&optional redraw)
  "Add \"Contents\" menu to menubar; if REDRAW force update."
  (interactive)
  (if reduce-imenu-done
      ;; This is PRIMARILY to avoid a bug in imenu-add-to-menubar that
      ;; causes it to corrupt the menu bar if it is run more than once
      ;; in the same buffer.
      ()
    (setq reduce-imenu-done t)
    (imenu-add-to-menubar reduce-imenu-title)
    (if redraw (force-mode-line-update))))


;;;; ********************
;;;; Indentation commands
;;;; ********************

(defun reduce-indent-line (&optional arg)
  "Indent current line; if ARG indent whole statement rigidly.
Indents to fixed style determined by current and previous non-blank line.
Subsequent consecutive calls indent additionally by ‘reduce-indentation’
unless ‘reduce-indent-line-conservative’ is non-nil.  With argument,
indent any additional lines of the same statement rigidly together with
this one."
  (interactive "*P")            ; error if buffer read-only
  (let ((start-marker (point-marker))
    (indentation (progn (back-to-indentation) (current-column)))
    new-indent)
    (if (and (memq this-command
           '(reduce-indent-line indent-for-tab-command))
         (memq last-command
           (list 'reduce-indent-line 'indent-for-tab-command
             'newline-and-indent
             'reindent-then-newline-and-indent))
         (not reduce-indent-line-conservative))  ; TS
    (indent-to 0 reduce-indentation)
      (if (< (setq new-indent (reduce-calculate-indent)) indentation)
      (delete-horizontal-space))
      (indent-to new-indent))
    (if arg
    (save-excursion
      (setq indentation (- (current-column) indentation))
      (indent-rigidly
       (point) (progn (reduce-forward-statement 1) (point)) indentation)
      ))
    (if (< (point) start-marker) (goto-char start-marker))
    (set-marker start-marker nil)
    ))


(defun reduce-calculate-indent ()
  "Return appropriate indentation for current line as REDUCE code."
  (let ((case-fold-search t))
    (or (reduce-calculate-indent-proc)
    (reduce-calculate-indent-this)
    (reduce-calculate-indent-prev))))

(defconst procedure-regexp "\\(?:^\\|\\s-+\\|[;$]\\)procedure\\s-+[![:alpha:]]"
  "Regexp for use in a SEARCH to find a procedure header.")

(defsubst looking-at-procedure ()
  "Return t if text after point matches the start of a procedure."
  (looking-at ".*\\<procedure\\s-+[![:alpha:]]"))

(defun reduce-calculate-indent-proc ()
  ;; "Handle comment lines, or if immediately following a procedure body
  ;; then return 0, otherwise return nil."
  "Return 0 if immediately following procedure body, else return nil."
  (save-excursion
    (beginning-of-line)
    (cond
     ;; ((looking-at "[ \t]*%")
     ;; (back-to-indentation) (reduce-comment-indent))
          ;; ((and (re-search-backward "[;$][ \t\n]*\n" nil t) ; ))
      ((progn
         ;; Find previous line that is neither blank nor a comment:
         (while (and (= (forward-line -1) 0)
             (looking-at "[ \t\f]*[%\n]")) )
         ;; Does it end with a separator?
         (and (looking-at ".*[;$][ \t]*[%\n]")
          ;; Is it the end of a procedure?
          (progn (end-of-line)
             (= (reduce-backward-statement 2) 0))
          (looking-at-procedure)))
       0)
      )))


(defun reduce-calculate-indent-this ()
  "Handle current line BEGINNING with a special token.
For an opening token (‘begin’ or ‘<<’) normally return the indentation of
the previous non-blank line; for an intermediate token (‘then’ or ‘else’)
return the indentation of the beginning of the statement; for a
closing token (‘end’ or ‘>>’) return the indentation of the beginning
of the construct; otherwise return nil."
  (save-excursion
    (back-to-indentation)
    (cond
     ;; *** Opening tokens *** :
     ((looking-at "[({ \t]*\\(\\<begin\\>\\|<<\\)")
      ;; Find previous non-blank line:
      (let ((closed (looking-at ".*\\(\\<end\\>\\|>>\\)")))
    (skip-syntax-backward " >") ; whitespace, endcomment
    (if (looking-at "[;$]")
        (reduce-backward-statement 1)
      (back-to-indentation))
    (if (or (looking-at-procedure)
        (and
         (or closed     ; single-line construct
             (looking-at "\\w+[ \t]*:=")) ; assignment
         (not (looking-at ".*[;$]")))) ; not completed
        (+ (current-column) reduce-indentation)
      (current-column))
    ))
     ((looking-at "\\w+[ \t]*:[^=]")    ; label
      ;; Indent to beginning of enclosing block:
      (reduce--backward-block) (current-column))
     ;; *** Intermediate tokens *** :
     ((looking-at "\\<then\\>\\|\\<else\\>")
      (reduce-find-matching-if) (current-indentation))
     ;; *** Closing tokens *** :
     ((looking-at "\\<end\\>")
      (reduce--backward-block) (current-indentation))
     ((looking-at ">>")
      (reduce--backward-group) (current-indentation))
     ;; ((looking-at "#\\<endif\\>")
     ;;  (reduce--backward-group) 0)
     ((looking-at "#\\(\\<define\\>\\|\\<if\\>\\|\\<\\elif\\>\\|\\<\\else\\>\\|\\<endif\\>\\)")
      0))))

(defun reduce-find-matching-if ()
  "Find the ‘if’ matching a ‘then’ or ‘else’."
  ;; Must skip groups, blocks and brackets.
  ;; Detects a missing ‘if’ as early as possible as an unrecoverable error.
  (let ((pattern "\\<\\(if\\|else\\|end\\|begin\\)\\>\\|>>\\|\\s)\\|<<\\|\\s(\\|[^!][;$]"))
    (or (and
     (reduce--re-search-backward pattern)
     (cond
      ((looking-at "if"))       ; found it – return t
      ((looking-at "else")      ; nested conditional
       (reduce-find-matching-if) (reduce-find-matching-if))
      ((= (following-char) ?>)  ; end of group
       (reduce--backward-group) (reduce-find-matching-if))
      ((looking-at "end")       ; end of block
       (reduce--backward-block) (reduce-find-matching-if))
      ((= (char-syntax (following-char)) ?\) )
       (forward-char) (backward-list) ; skip balanced brackets
       (reduce-find-matching-if))))
    ;; begin, <<, opening bracket, ‘;’, ‘$’ or beginning of buffer
    (error "‘if’ matching ‘then’ or ‘else’ not found"))
    ))


(defun reduce-calculate-indent-prev ()
  "Return indentation based on previous non-blank line."
  ;; Should comments be ignored, esp. if they begin the line?
  ;; e.g. they may indicate a commented-out region!
  (save-excursion
    (beginning-of-line)
    (if (bobp)
    0               ; no previous line
      ;; Find previous line that is neither blank nor a comment
      ;; beginning in the first column (which may represent
      ;; commented-out code):
      (while (and (= (forward-line -1) 0)
          (looking-at "%\\|[ \t\f]*$")) )
      (if (and (bobp) (looking-at "[ \t\f]*$"))
      0             ; no previous non-blank line
    (back-to-indentation)
    ;; Point is now at first text in the previous non-blank line.
    (let ((previous-indentation (current-column))
          extra-indentation)
      ;; Skip any label:
      (when (looking-at "^\\(\\w+[ \t]*:\\)[^=]") ; label
        (goto-char (match-end 1))
        (skip-chars-forward "[ \t]")
        (if (eolp)      ; label alone on line
        (setq extra-indentation reduce-indentation)
          (setq previous-indentation (current-column))))
      ;; Point is now at start of statement text in the previous
      ;; non-blank line.
      (or extra-indentation
          (setq extra-indentation
            (cond
             ;; *** Tokens at beginning of the line *** :
             ((looking-at "%") 0)   ; % comment (HANDLE THIS FIRST!)
     ;          ((looking-at "\\w+[ \t]*:[^=]") ; label
     ;           (if (looking-at ".*\\<if\\>") ; what else?
     ;               (* 2 reduce-indentation)
     ;             reduce-indentation))
             ;; *** Tokens anywhere in the line *** :
             ((or (looking-at-procedure)
              (and (looking-at ".*\\<begin\\>")
                   (not (looking-at ".*\\<end\\>")))
              (and (looking-at ".*<<") (not (looking-at ".*>>"))))
              (if (looking-at ".*,[ \t]*[%\n]") ; line ends with ,
              (* 2 reduce-indentation)
            reduce-indentation))
             ;; *** Tokens at the end of the (logical) line *** :
             ((looking-at ".*\\<\\(if\\|for\\|do\\|collect\\|join\\|sum\\product\\)\\>[ \t]*[%\n]")
              reduce-indentation)
             ;; Otherwise, extra indentation undefined
             )))
      (cond
       ((looking-at "#\\<endif\\>")
        (current-indentation))
       ((looking-at "#\\(\\<define\\>\\|\\<if\\>\\|\\<\\elif\\>\\|\\<\\else\\>\\)")
        (current-indentation))
       ;; If extra indentation determined then use it ...
       (extra-indentation (+ previous-indentation extra-indentation))
       ;; If beginning new statement or comma-separated element
       ;; then indent to previous statement or element
       ;; unless it is a first argument ...
       ((reduce-calculate-indent-prev1))
; This produces very odd results if the group is preceded by indented code:
;      ((and (looking-at ".*<<") (not (looking-at ".*>>")))
;       (reduce-backward-statement 1)
;       (back-to-indentation)
;       (+ (current-column) reduce-indentation))
       ;; If continuing ‘if’ then indent relative to the ‘if’ ...
;      ((looking-at ".*\\(\\<then\\>\\|\\<else\\>\\)[ \t]*[%\n]")
;       (if (looking-at ".*\\<if\\>")
;       ()
;         (goto-char (match-beginning 1))
;         (reduce-find-matching-if))
;       (+ (current-indentation) reduce-indentation))
       ;; ... but the ‘if’ must be embedded ...
       ((looking-at ".+\\<if\\>.*\\(\\<then\\>\\|\\<else\\>\\)[ \t]*[%\n]")
        (goto-char (match-beginning 1))
        (reduce-find-matching-if)
        (+ (current-indentation) reduce-indentation))
       ;; Otherwise continuing previous line, so ...
       (t (+ previous-indentation reduce-indentation))
       ))))))

(defun reduce-calculate-indent-prev1 ()
  "Sub-function of ‘reduce-calculate-indent-prev’.
If beginning new statement or comma-separated element or
sub-expression ending with ‘+’, ‘-’, ‘or’ or ‘and’ then indent to
previous statement or element unless it is a first argument ..."
  (if (looking-at ".*\\(\\([,+-]\\|\\<or\\|\\<and\\)\\|[\;$]\\)[ \t]*[%\n]")
      (let* ((second_arg (match-string 2))
         (open (or second_arg
               (not (looking-at
                 ".*\\(\\<end\\>\\|>>\\)[\;$][ \t]*[%\n]")))))
    (end-of-line)
    (reduce-backward-statement 1)
    (if second_arg
        (setq second_arg
          (save-excursion
            (reduce--re-search-backward "[^ \t\f\n]")
            (not (looking-at "\\(,\\|\\s(\\)[ \t]*[%\n]"))
            )))
    (back-to-indentation)
    (if (or second_arg
        (and open
             (looking-at
              ;; ... procedure / begin, << / label
              ".*\\<procedure\\>\
\\|\\<begin\\>\\|<<\
\\|\\w+[ \t]*:[^=]"))           ; ???
        (looking-at "\\w+[ \t]*:[^=]")) ; label
        (+ (current-column) reduce-indentation)
      (current-column)))))

(defun reduce-unindent-line (arg)
  "Unindent current line; if ARG indent whole statement rigidly.
Delete ‘reduce-indentation’ spaces from beginning of line.
With argument, unindent any additional lines of the same statement
rigidly along with this one."
  (interactive "*P")            ; error if buffer read-only
  (let ((start-marker (point-marker))
    (indentation (progn (back-to-indentation) (current-column))))
    (if (bolp)
    ()
      (backward-delete-char-untabify reduce-indentation)
      (if arg
      (save-excursion
        (setq indentation (- (current-column) indentation))
        (indent-rigidly
         (point) (progn (reduce-forward-statement 1) (point)) indentation)
        ))
      (if (< (point) start-marker) (goto-char start-marker))
      (set-marker start-marker nil)
      )))


(defun reduce-comment-indent ()
  "Value of ‘comment-indent-function’."
  ;; Called only by indent-for-comment and
  ;; (hence) indent-new-comment-line.
  (if (looking-at "%%%")
      (current-column)
    (if (looking-at "%%")
    (reduce-calculate-indent)
      (skip-chars-backward " \t")
      ;; (bolp) needed by indent-new-comment-line:
      (max (if (bolp) 0 (1+ (current-column))) comment-column)
      )))


(defun reduce-indent-procedure (arg)
  "Indent this and following ARG procedures.
Indent the procedure (and trailing white space) ending after point.
With arg, indent the following arg procedures including this one."
  (interactive "*p")            ; error if buffer read-only
  (save-excursion
    (if (reduce-mark-procedure arg)
    ;; Leaves mark at end of procedure, point at start.
    (reduce-indent-region (point) (mark))
      )))

(defun reduce-indent-region (beg-region end-region)
  "Interactively indent region; otherwise BEG-REGION to END-REGION.
Interactively with prefix arg, indent the whole buffer."
  ;; (interactive "*r")         ; error if buffer read-only
  (interactive
   (if current-prefix-arg
       (list (point-min) (point-max))
     (list (region-beginning) (region-end))))
  ;; Indent lines between beg-region and end-region
  ;; and return point to where it started.
  ;; This version is not very efficient.
  (message "Indenting ...")
  (let ((end-region-mark (make-marker)) (save-point (point-marker)))
    ;; Must use markers so that they move with the text.
    (set-marker end-region-mark end-region)
    (goto-char beg-region)
    (while (< (point) end-region-mark)
      (reduce-indent-line)
      ;; Strip trailing white space from lines
      (end-of-line) (delete-horizontal-space)
      (forward-line))
    (goto-char save-point)
    (set-marker end-region-mark nil)
    (set-marker save-point nil))
  (message "Indenting ... done"))


;;;; ******************************************************
;;;; Support for automatic re-indentation of specific lines
;;;; ******************************************************

(defvar reduce-auto-indent-idle-timer nil)

(defun reduce-auto-indent-mode (&optional arg)
  "Toggle REDUCE Auto Indent mode.
With prefix ARG, turn mode on if and only if ARG is positive.
Returns the new status of REDUCE Auto Indent mode (non-nil means on).

When REDUCE Auto Indent mode is enabled, after
‘reduce-auto-indent-delay’ seconds of Emacs idle time re-indent the
current line if the text just typed matches ‘reduce-auto-indent-regexp’."
  (interactive "P")
  (let ((on-p (if arg
          (> (prefix-numeric-value arg) 0)
        (not reduce-auto-indent-mode))))
    (if reduce-auto-indent-idle-timer
    (cancel-timer reduce-auto-indent-idle-timer))
    (if on-p
    (setq reduce-auto-indent-idle-timer
          (run-with-idle-timer reduce-auto-indent-delay t
                   'reduce-auto-indent-function)))
    (setq reduce-auto-indent-mode on-p)
    (reduce-auto-indent-function)))

(defun reduce-auto-indent-function ()
  "Re-indent current line if match with ‘reduce-auto-indent-regexp’ just typed."
  (and (eq major-mode 'reduce-mode)
       (eq last-command 'self-insert-command)
       (save-excursion
     (save-match-data
       (if (re-search-backward reduce-auto-indent-regexp nil t)
           (reduce-indent-line))
       ))))


;;;; ******************************
;;;; Operations based on procedures
;;;; ******************************

(defun reduce-backward-procedure (arg)
  "Move backward to next start of procedure.  With ARG, do it ARG times."
  (interactive "p")
  (let ((case-fold-search t) (count arg))
    (while (and (> count 0) (reduce--re-search-backward procedure-regexp))
      (setq count (1- count)))
    (if (= count arg)
    ()
      ;; (reduce-backward-statement 1)  ; overkill?  Instead ...
      ;; Find preceding "%", ";", "$", "(" or beginning of buffer:
      (while (progn (skip-chars-backward "^%;$(")
            (and (not (bobp))
             (not (backward-char 1))
             (= (preceding-char) ?!))))
      ;; If in %-comment then skip to its end:
      (if (reduce--back-to-percent-comment-start) (end-of-line))
      ;; Find actual start of procedure statement:
      (if (reduce--re-search-forward "[a-zA-Z]") (backward-char 1))
      )))

(defun reduce-forward-procedure (arg)
  "Move forward to next end of procedure.  With ARG, do it ARG times."
  (interactive "p")
  (let ((case-fold-search t) (start (point)) count)
    ;; Move to end of procedure starting before point:
    (if (reduce--re-search-backward procedure-regexp)
        (reduce-forward-statement 2))
    ;; Now move forward by arg or arg-1 procedures
    ;; or stay put if at least one move not possible
    (unless (<= (point) start)
      (setq arg (1- arg)) (setq start (point)))
    (setq count arg)
    (while (and (> count 0) (reduce--re-search-forward procedure-regexp))
      (setq count (1- count)))
    (if (< count arg)
        (reduce-forward-statement 2)
      (goto-char start)))
  ;; Skip white space and any following eol:
  (skip-chars-forward " \t")
  (if (= (following-char) ?\n) (forward-char)))

(defun reduce-mark-procedure (arg)
  "Mark this and following ARG procedures.
Put mark after next end of procedure, point at start of that procedure.
Procedure ends AFTER any trailing white space.
Return t is successful, nil otherwise."
  ;; Could be more efficient by hacking reduce-forward-procedure!
  (interactive "p")
  (let ((start (point)) transient-mark-mode)
    ;; Region must stay active, even if transient-mark-mode is on.
    (reduce-forward-procedure arg)
    (if (= (point) start)
    nil
      (skip-chars-forward " \t\n")  ; skip trailing white space
      (push-mark start t)       ; save original position QUIETLY
      (push-mark)           ; mark end of procedure
      (reduce-backward-procedure arg)
      t)
    ))

(defun reduce-kill-procedure ()
  "Kill the procedure (and trailing white space) ending after point."
  (interactive "*")         ; error if buffer read-only
  (if (reduce-mark-procedure 1)
      (kill-region (region-beginning) (region-end))))

(defun reduce-narrow-to-procedure (arg)
  ;; Based on ‘narrow-to-defun’ in ‘lisp.el’.
  "Narrow to this and following ARG procedures.
Make text outside current procedure invisible.
The procedure visible is the one that contains point or follows point."
  (interactive "p")
  (save-excursion
    (widen)
    (reduce-forward-procedure arg)
    (let ((end (point)))
      (reduce-backward-procedure arg)
      (narrow-to-region (point) end))))


;;;; ******************************
;;;; Operations based on statements
;;;; ******************************

;; This section updated September 2022.
;; It now handles /*...*/ comments.

(defvar reduce-escape-tries 1
  "Repeat count of reduce-forward/backward-statement calls.
These were made inside a block or group at its beginning or end.")

(defvar reduce--outside-block-or-group nil
  "Position immediately outside a block or group, or nil.
This includes position after an end-of-file marker.  These
positions are found from inside the block or group by
‘reduce-forward-statement’ or ‘reduce-backward-statement’, which
bind this variable.")

(defun reduce--escape-block-or-group (start)
  "Move over “<<”, “begin”, “>>” or “end” if at START.
This includes the end-of-file marker.  But move only after
‘reduce-max-escape-tries’ repeated interactive attempts."
  (if (and reduce--outside-block-or-group
           (= (point) start)
           (eq this-command last-command))
      (if (< reduce-escape-tries reduce-max-escape-tries)
          (setq reduce-escape-tries (1+ reduce-escape-tries))
        (setq reduce-escape-tries 1)
        (goto-char reduce--outside-block-or-group))
    (setq reduce-escape-tries 1)))

(defun reduce-forward-statement (arg)
  "Move forwards to the end of this or the following statement.
With ARG, move that many times.  Ignore (skip) comment statements.
If looking at the end of a block or group, or the end-of-file
marker, move over it after ‘reduce-max-escape-tries’ consecutive
interactive tries."
  (interactive "p")
  (let ((case-fold-search t)
        (start (point))
        (pattern "\\([\;$]\\)\\|\\(>>\\|\\_<end\\_>\\)\\|\
\\(<<\\)\\|\\(\\_<begin\\_>\\)\\|\\(\\s\(\\)\\|\\(\\s\)\\)")
        reduce--outside-block-or-group)
    ;; Skip an immediate closing bracket:
    (if (looking-at "[ \t\n]*\\s)") (goto-char (match-end 0)))
    (while (and (> arg 0) (reduce--forward-statement1 pattern))
      (setq arg (1- arg)))
    (when (> arg 0)                     ; error!
      (goto-char start)
      (user-error "End of statement not found"))
    ;; Move over  >>  or  end  on repeated interactive attempts:
    (reduce--escape-block-or-group start)
    ;; Never move backwards:
    (if (< (point) start) (goto-char start))))

(defun reduce--forward-statement1 (pattern)
  "Syntactic search forwards for PATTERN.
Recursive sub-function of ‘reduce-forward-statement’.
Return t if successful; nil otherwise."
  (if (reduce--re-search-forward pattern)
      (cond
       ((match-beginning 1))            ; found terminator
       ((match-beginning 2)             ; found end of group or block
        (setq reduce--outside-block-or-group (point))
        (goto-char (match-beginning 2))
        (skip-chars-backward " \t\n") t)
       ((match-beginning 3)             ; found start of group
        (and (reduce--forward-group)
             (reduce--forward-statement1 pattern)))
       ((match-beginning 4)             ; found start of block
        (and (reduce--forward-block)
             (reduce--forward-statement1 pattern)))
       ((match-beginning 5)             ; found opening bracket
        (backward-char) (forward-list)
        (reduce--forward-statement1 pattern))
       ((match-beginning 6)             ; found closing bracket
        (if (save-excursion             ; quoted list does not
              (backward-list)           ; contain REDUCE statements
              (skip-chars-backward " \t\n")
              (= (preceding-char) ?'))
            (reduce--forward-statement1 pattern)
          (backward-char) (skip-chars-backward " \t\n") t)))
    (save-excursion
      (reduce--skip-comments-forward)
      (eobp))))


(defun reduce-backward-statement (arg)
  "Move backwards to the start of this or the preceding statement.
With ARG, move that many times.  Ignore (skip) comment statements.
If looking at the beginning of a block or group move over it
after ‘reduce-max-escape-tries’ consecutive interactive tries.
The end-of-file marker is treated as a statement.
Return the count of statements left to move,
which is used by ‘reduce-calculate-indent-proc’."
  (interactive "p")
  (let ((case-fold-search t)
        (start (point))
        (pattern "\\([\;$]\\)\\|\\(<<\\|\\_<begin\\_>\\)\
\\|\\(>>\\)\\|\\(\\_<end\\_>\\)\\|\\(\\s\)\\)\\|\\(\\s\(\\)")
        reduce--outside-block-or-group
        ;; Check whether after end in end-of-file marker, “;end;”, to
        ;; avoid skipping a non-existent block to the top of the file!
        (at-eof (save-excursion
                   (re-search-forward "\\=[\;$]" nil t)
                   (reduce--skip-comments-forward)
                   (eobp))))
    ;; Skip to the preceding syntactically relevant character:
    (reduce--skip-comments-backward)
    ;; If a terminator or opening bracket then skip it:
    (re-search-backward "\\(?:[\;$]\\|\\s\(\\)\\=" nil t)
    ;; Now within a statement or at the end of the preceding
    ;; statement.  Skip arg statements backwards to immediately before
    ;; the preceding terminator or other delimiter:
    (while (and (> arg 0)
                (reduce--backward-statement1 pattern at-eof))
      (setq arg (1- arg)))
    (when (> arg 0)                     ; error!
      (goto-char start)
      (user-error "Start of statement not found"))
    ;; Move forwards to start of actual statement, skipping any
    ;; terminator, comments and white space:
    (re-search-forward "\\=[\;$]" nil t)
    (reduce--skip-comments-forward)
    ;; Move over  <<  or  begin  on repeated interactive attempts:
    (reduce--escape-block-or-group start)
    ;; Never move forwards:
    (if (> (point) start) (goto-char start))
    arg))

(defun reduce--backward-statement1 (pattern at-eof)
  "Syntactic search backwards for PATTERN.
If AT-EOF is non-nil then after “end” in end-of-file marker, “;end;”.
Recursive sub-function of ‘reduce-backward-statement’.
Return t if successful; nil otherwise."
  (if (reduce--re-search-backward pattern 'move)
      (cond
       ((match-beginning 1))           ; found terminator
       ((match-beginning 2)            ; found start of group or block
        (setq reduce--outside-block-or-group (point))
        (goto-char (match-end 2)) t)
       ((match-beginning 3)             ; found end of group
        (and (reduce--backward-group)
             (reduce--backward-statement1 pattern at-eof)))
       ((match-beginning 4)             ; found end of block (or file)
        (and (or at-eof (reduce--backward-block))
             (reduce--backward-statement1 pattern nil)))
       ((match-beginning 5)             ; found closing bracket
        (forward-char) (backward-list)  ; skip balanced brackets
        (reduce--backward-statement1 pattern at-eof))
       ((match-beginning 6)             ; found opening bracket
        (forward-char) (skip-chars-forward " \t\n") t))
    (bobp)))


(defun reduce-kill-statement (&optional arg)
  "Kill the rest of the current statement or ARG statements from point.
With prefix argument, kill that many statements from point.
Negative arguments kill statements backwards, where the prefix
argument minus (-) is equivalent to -1."
  (interactive "*p")                    ; error if buffer read-only
  (kill-region (point) (progn
                         (if (< arg 0)
                             (reduce-backward-statement (- arg))
                           (reduce-forward-statement arg)
                           (skip-syntax-forward "-"))
                         (point))))


;;;; ************************
;;;; Moving by block or group
;;;; ************************

;; This section updated September 2022.

(defun reduce-up-block-or-group (arg)
  "Move backwards up one level of block or group; if ARG move forwards.
Move to the beginning of the nearest unpaired “begin” or “<<”.  A
universal argument means move forwards to the end of the nearest
unpaired “end” or “>>”.  Throw an error if the move fails.  With
a numeric argument, do it that many times, where a negative
argument means move forwards instead of backwards."
  (interactive "P")
  (let ((case-fold-search t))
    (setq arg (reduce--prefix-numeric-value arg))
    (cond
     ((> arg 0)                         ; move backwards
      (while (> arg 0)
        (let ((start (point)))
          (unless (reduce--backward-block-or-group)
            (goto-char start)
            (user-error "Start of block or group containing point not found")))
        (setq arg (1- arg))))
     ((< arg 0)                         ; move forwards
      (while (< arg 0)
        (let ((start (point)))
          (unless (reduce--forward-block-or-group)
            (goto-char start)
            (user-error "End of block or group containing point not found")))
        (setq arg (1+ arg)))))))

(defun reduce--backward-block-or-group ()
  "Move backwards to beginning of block or group containing point.
Return t is successful; otherwise do not move and return nil.
Recursive sub-function of ‘reduce-up-block-or-group’."
  (if (reduce--re-search-backward
       "\\_<begin\\_>\\|<<\\|\\(\\_<end\\_>\\)\\|\\(>>\\)")
      (cond ((match-beginning 1)        ; end of block found
             (reduce--backward-block)   ; skip block
             (reduce--backward-block-or-group))
            ((match-beginning 2)        ; end of group found
             (reduce--backward-group)   ; skip group
             (reduce--backward-block-or-group))
            (t))))

(defun reduce--forward-block-or-group ()
  "Move forwards to end of block or group containing point.
Return t is successful; otherwise do not move and return nil.
Recursive sub-function of ‘reduce-up-block-or-group’."
  (if (reduce--re-search-forward
       "\\_<end\\_>\\|>>\\|\\(\\_<begin\\_>\\)\\|\\(<<\\)")
      (cond ((match-beginning 1)        ; start of block found
             (reduce--forward-block)    ; skip block
             (reduce--forward-block-or-group))
            ((match-beginning 2)        ; start of group found
             (reduce--forward-group)    ; skip group
             (reduce--forward-block-or-group))
            (t))))


(defun reduce-down-block-or-group (arg)
  "Move forwards down one level of block or group; if ARG move backwards.
Move to the end of the nearest unpaired “begin” or “<<”.  A
universal argument means move backwards to the beginning of the
nearest unpaired “end” or “>>”.  Throw an error if the move
fails.  With a numeric argument, do it that many times, where a
negative argument means move backwards instead of forward."
  (interactive "P")
  (let ((case-fold-search t))
    (setq arg (reduce--prefix-numeric-value arg))
    (cond
     ((> arg 0)                         ; move forwards
      (while (> arg 0)
        (let ((start (point)))
          (unless (and
                   (reduce--re-search-forward
                    "\\(<<\\|\\_<begin\\_>\\)\\|>>\\|\\_<end\\_>")
                   (match-beginning 1))
            (goto-char start)
            (user-error "Start of block or group following point not found")))
        (setq arg (1- arg))))
     ((< arg 0)                         ; move backwards
      (while (< arg 0)
        (let ((start (point)))
          (unless (and
                   (reduce--re-search-backward
                    "\\(>>\\|\\_<end\\_>\\)\\|<<\\|\\_<begin\\_>")
                   (match-beginning 1))
            (goto-char start)
            (user-error "End of block or group preceding point not found")))
        (setq arg (1+ arg)))))))


(defun reduce--prefix-numeric-value (arg)
  "Interpret universal ARG as -1, otherwise apply ‘prefix-numeric-value’."
  (if (and arg (listp arg)) -1 (prefix-numeric-value arg)))


(defun reduce--forward-block ()
  "Move forwards to end of block containing point if possible.
Return t if successful; otherwise return nil."
  (let (found)
    (while (and
            (setq found (reduce--re-search-forward
                         "\\_<end\\_>\\|\\(\\_<begin\\_>\\)"))
            (reduce--symbol-unquoted-&-distinct-p
             (match-beginning 0) (match-end 0))
            (match-beginning 1))
      (reduce--forward-block))
    ;; If ‘found’ is true here then ‘(match-beginning 1)’ is false, so
    ;; we have found ‘end’.
    found))

(defun reduce--backward-block ()
  "Move backwards to start of block containing point if possible.
Return t if successful; otherwise return nil."
  (let (found)
    (while (and
            (setq found (reduce--re-search-backward
                         "\\_<begin\\_>\\|\\(\\_<end\\_>\\)"))
            (reduce--symbol-unquoted-&-distinct-p
             (match-beginning 0) (match-end 0))
            (match-beginning 1))
      (reduce--backward-block))
    ;; If ‘found’ is true here then ‘(match-beginning 1)’ is false, so
    ;; we have found ‘begin’.
    found))

(defun reduce--symbol-unquoted-&-distinct-p (beg end)
  "Return t if symbol between BEG and END is unquoted and distinct.
Check preceding character is not a single quote or an escaped
character, and that the following character is not an escape."
  ;; char-after and char-before return nil if the character is not
  ;; available, e.g. at BOB or EOB.
  (let (pos char)
    (not (or
          ;; Preceded by single quote character?
          (and (setq char (char-after (setq pos (1- beg))))
               (eq char ?\'))
          ;; Preceded by escaped character?
          (and char (setq char (char-before pos))
               (eq char ?!))
          ;; Followed by escape character?
          (and (setq char (char-after (setq pos end)))
               (eq char ?!))))))

(defun reduce--unescaped-p (&optional pos)
  "Return t if char at POS (defaults to point) is not escaped.
It may be preceded only by an odd number of escape characters"
  ;; (logand x 1) = lowest order bit of x = 0 if x is even;
  ;; see Emacs paren.el --- highlight matching paren
  (save-excursion
    (if pos (goto-char pos))
    (= (logand (skip-syntax-backward "/") 1) 0)))


(defun reduce--forward-group ()
  "Move forwards to end of group containing point if possible.
Return t if successful; otherwise return nil."
  (let (found)
    (while (and
            (setq found (reduce--re-search-forward ">>\\|<<"))
            (reduce--unescaped-p (match-beginning 0))
            (= (char-before) ?<))
      (reduce--forward-group))
    found))

(defun reduce--backward-group ()
  "Move backwards to start of group containing point if possible.
Return t if successful; otherwise return nil."
  (let (found)
    (while (and
            (setq found (reduce--re-search-backward "<<\\|>>"))
            (reduce--unescaped-p)
            (= (char-after) ?>))
      (reduce--backward-group))
    found))


;;;; **********************************
;;;; Balanced structure (sexp) commands
;;;; **********************************

(defun reduce-forward-sexp (arg)
  "Move forwards across one balanced expression.
With ARG, do it that many times.  Negative arg -N means move
backward across N balanced expressions.  “Balanced expression”
means a symbol, string, bracketed expression, block or group.  A
symbol or bracketed expression may be quoted.  Skip any preceding
or intervening white space or terminator characters.  This
command assumes point is not in a string or comment.  It is
modelled on ‘forward-sexp’.  If unable to move over a balanced
expression, throw a user error."
  (interactive "p")
  (if (< arg 0) (reduce-backward-sexp (- arg))
  (skip-chars-forward " \t\r\n;$")
    (let ((case-fold-search t) (start (point)))
      (cond
       ((and (looking-at "<<") (reduce--unescaped-p))
        (forward-char 2)
        (unless (reduce--forward-group)
          (reduce--move-error start "next")))
       ((and (looking-at "\\_<begin\\_>")
             (reduce--symbol-unquoted-&-distinct-p
              (point) (+ (point) 5)))
        (forward-char 5)
        (unless (reduce--forward-block)
          (reduce--move-error start "next")))
       ((and (looking-at "\\s\(\\|\"") (reduce--unescaped-p))
        (forward-sexp))
       ((looking-at "'?\\_<\\|'\\s\(") (forward-sexp))
       (t (reduce--move-error start "next")))
      (if (> arg 1) (reduce-forward-sexp (1- arg))))))

(defun reduce-backward-sexp (arg)
  "Move backwards across one balanced expression.
With ARG, do it that many times.  Negative arg -N means move
backward across N balanced expressions.  “Balanced expression”
means a symbol, string, bracketed expression, block or group.  A
symbol or bracketed expression may be quoted.  Skip any following
or intervening white space or terminator characters.  This
command assumes point is not in a string or comment.  It is
modelled on ‘backward-sexp’.  If unable to move over a balanced
expression, throw a user error."
  (interactive "p")
  (if (< arg 0) (reduce-forward-sexp (- arg))
  (skip-chars-backward " \t\r\n;$")
    (let ((case-fold-search t) (start (point)))
      (cond
       ((and (looking-back ">>" nil) (reduce--unescaped-p (- (point) 2)))
        (backward-char 2)
        (unless (reduce--backward-group)
          (reduce--move-error start "previous")))
       ((and (looking-back "\\_<end\\_>" nil)
             (reduce--symbol-unquoted-&-distinct-p
              (- (point) 3) (point)))
        (backward-char 3)
        (unless (reduce--backward-block)
          (reduce--move-error start "previous")))
       ((and (looking-back "\\s\)\\|\"" nil) (reduce--unescaped-p (1- (point))))
        (backward-sexp))
       ((looking-back "\\_>" nil) (backward-sexp))
       (t (reduce--move-error start "previous")))
      (if (> arg 1) (reduce-backward-sexp (1- arg))))))

(defun reduce--move-error (start next-or-previous)
  "Move to START and throw an error appropriate to NEXT-OR-PREVIOUS."
  (goto-char start)
  (user-error "No %s “balanced expression”" next-or-previous))


;;;; *****************
;;;; Skipping comments
;;;; *****************

;; This section created September 2022.
;; It handles /*...*/ comments.

(defun reduce--skip-comments-forward ()
  "Move forwards across comments and white space of all types."
  (save-match-data
    (let ((case-fold-search t))
      (forward-comment (buffer-size)) ; syntactic comments & white space
      (while (and (looking-at "comment")
                  (re-search-forward "[\;$]" nil t))
        (forward-comment (buffer-size))))))

(defun reduce--skip-comments-backward ()
  "Move backwards across comments and white space of all types.
But does not skip a comment statement at the beginning of the
buffer – should it?"
  (save-match-data
    (forward-comment (- (buffer-size))) ; syntactic comments & white space
    (let ((start (point)) (case-fold-search t))
      (when (re-search-backward "[\;$]\\=" nil t) ; at end of statement
        ;; If comment statement then skip it:
        (if (re-search-backward "^[^%]*[\;$]" nil t) ; avoiding % comments!
            ;; *** ALSO NEED TO AVOID /*...*/ COMMENTS! ***
            (progn
              (goto-char (match-end 0)) ; at end of preceding statement
              (forward-comment (buffer-size))
              (if (looking-at "comment") ; comment statement skipped
                  (reduce--skip-comments-backward)
                (goto-char start)))
          (goto-char start))))))


;;;; *****************************************************************
;;;; Searching for syntactic elements ignoring comments, strings, etc.
;;;; *****************************************************************

;; This section updated September 2022.
;; It now handles /*...*/ comments.

(defun reduce--re-search-forward (regexp &optional MOVE)
  "Syntactic search forwards for REGEXP.
If no match and MOVE is non-nil then move to end.
Skip comments, strings, escaped and quoted tokens.
Return t if match found, nil otherwise."
  (let ((start (point))
        (pattern (concat regexp "\\|\\(?100:\"\\)\\|\\(?101:%\\|/\\*\\)\\|\\(?102:\\_<comment\\_>\\)"))
        (move (if MOVE 'move t)))
    (if (reduce--re-search-forward1 pattern move)
        t
      (unless MOVE (goto-char start))
      nil)))

(defun reduce--re-search-forward1 (pattern move)
  "Search forwards for PATTERN; if no match and MOVE then move to end.
Recursive sub-function of ‘reduce--re-search-forward’.
Process match to skip comments, strings, etc.
Return t if match found, nil otherwise."
  (if (re-search-forward pattern nil move)
      (if (cond                     ; check match -- t => search again
           ((memq (char-before (match-beginning 0)) '(?! ?'))) ; escaped or quoted
           ((match-beginning 100)       ; string
            (goto-char (match-beginning 100))
            (forward-sexp) t)
           ((match-beginning 101)       ; % or /*...*/ comment
            (goto-char (match-beginning 101))
            (forward-comment 1) t)
           ((match-beginning 102)       ; comment statement
            (re-search-forward "[;$]" nil 'move) t))
          (reduce--re-search-forward1 pattern move) ; search again
        t)))                         ; match for original regexp found


(defun reduce--re-search-backward (regexp &optional MOVE)
  "Syntactic search backwards for REGEXP.
If no match and MOVE is non-nil then move to end.
Skip comments, strings, escaped and quoted tokens.
Return t if match found, nil otherwise."
  (let ((start (point))
        (pattern (concat regexp "\\|\\(?100:\"\\)\\|\\(?101:\\*/\\)"))
        (move (if MOVE 'move t)))
    (if (reduce--re-search-backward1 pattern move)
        t
      (unless MOVE (goto-char start))
      nil)))

(defun reduce--re-search-backward1 (pattern move)
  "Search backwards for PATTERN; if no match and MOVE then move to end.
Recursive sub-function of ‘reduce--re-search-backward’.
Process match to skip comments, strings, etc.
Return t if match found, nil otherwise."
  (if (re-search-backward pattern nil move)
      (if (cond                     ; check match -- t => search again
           ((memq (preceding-char) '(?! ?'))) ; escaped or quoted
           ((match-end 100)                   ; string
            (goto-char (match-end 100))
            (backward-sexp) t)
           ((match-end 101)             ; /*...*/ comment
            (goto-char (match-end 101))
            (forward-comment -1) t)
           ((reduce--back-to-comment-start))) ; % comment or comment statement
          (reduce--re-search-backward1 pattern move) ; search again
        t)))                         ; match for original regexp found

(defun reduce--back-to-comment-start ()
  "If point is in a conventional comment, move to its start and return t.
Otherwise do not move and return nil."
  (or
   ;; Check whether in % comment:
   (reduce--back-to-percent-comment-start)
   ;; Check whether in comment statement:
   (save-match-data
     (let ((initial (point)) found
           (pattern "\\(\\_<comment\\_>\\)\\|\\(\"\\)\\|[;$]"))
       ;; Move backwards to the nearest ‘comment’ keyword or
       ;; terminator not in a comment or string.  (Should also check
       ;; whether match is in a /**/ comment!)
       (while (and (setq found (re-search-backward pattern nil 'move))
                   (or (when (match-beginning 2) ; skip string
                         (forward-char) (backward-sexp) t)
                       (reduce--back-to-percent-comment-start))))
       ;; If match is ‘comment’ then return its start position;
       ;; otherwise return nil.
       (cond
        ((and found (match-beginning 1))) ; in comment statement
        (t (goto-char initial) nil)))))) ; not in comment statement

(defun reduce--back-to-percent-comment-start ()
  "If point is in a % comment then move to its start and return t.
In fact, skip all preceding % and /**/ comments and white space.
Otherwise do not move and return nil."
  (let ((start (point))
        (bol (line-beginning-position)))
    (skip-syntax-backward "^<" bol) ; skip to preceding % on this line
    ;; If point after beginning of line then in % comment:
    (cond ((> (point) bol)
           (backward-char)              ; skip %
           ;; Skip all syntactic comments & white space:
           (forward-comment (- (buffer-size))) t)
          (t (goto-char start) nil))))


;;;; ****************
;;;; Comment commands
;;;; ****************

(defun reduce-comment-region (beg-region end-region arg)
  "Comment/uncomment every line in region, from BEG-REGION to END-REGION.
With interactive ARG, comment if non-negative, uncomment if null
or negative (cf. minor modes).
Put ‘reduce-comment-region-string’ at the beginning of every line in the region.
First two args specify the region boundaries, third arg is interactive."
  ;; Taken almost directly from fortran.el
  ;; by Michael D. Prange (prange@erl.mit.edu).
  (interactive "*r\nP")         ; error if buffer read-only
  (let ((end-region-mark (make-marker)) (save-point (point-marker)))
    (set-marker end-region-mark end-region)
    (goto-char beg-region)
    (beginning-of-line)
    (if (if arg
        (< (reduce--prefix-numeric-value arg) 0)
      (looking-at "%")) ; FJW
    ;; Uncomment the region:
    (let ((com "%+ ?"))
      (if (looking-at com)
          (delete-region (point) (match-end 0)))
      (while (and  (= (forward-line 1) 0)
               (< (point) end-region-mark))
        (if (looking-at com)
        (delete-region (point) (match-end 0)))))
      ;; Comment the region:
      (progn (insert reduce-comment-region-string)
         (while (and (= (forward-line 1) 0)
             (< (point) end-region-mark))
           (insert reduce-comment-region-string)))
      )
    (goto-char save-point)
    (set-marker end-region-mark nil)
    (set-marker save-point nil)))


(defun reduce-comment-procedure (arg)
  "Comment/uncomment every line of this procedure.
This procedure is the one that ends after point.
With interactive arg, if non-negative comment out procedure, if null
or negative uncomment all consecutive commented-out lines containing
or following point (cf. minor modes)."
  (interactive "*P")            ; error if buffer read-only
  (save-excursion
    (beginning-of-line)
    (if (if arg
        (< (reduce--prefix-numeric-value arg) 0)
      (looking-at "%"))
    (let (start)            ; uncomment lines
      (if (looking-at "%")      ; necessary ???
          (if (re-search-backward "^[^%]" nil t) (forward-line 1))
        (re-search-forward "^%" nil t))
      (setq start (point))
      (re-search-forward "^[^%]" nil t)
      (reduce-comment-region start (point) -1)) ; UNCOMMENT
      (if (reduce-mark-procedure 1) ; comment out procedure
      (progn            ; first back up to real
        (exchange-point-and-mark)   ; end of procedure
        (skip-chars-backward " \t\n")
        (reduce-comment-region (region-beginning) (region-end) nil))))
    ))


(defun reduce-fill-comment (justify)
  "Fill %-comment or comment statement paragraph at or after point.
If JUSTIFY is non-nil (interactively, with prefix argument), justify as well."
  (interactive "*P")
  (save-excursion
    (let (first)
      ;; If in empty line then move to start of next non-empty line:
      (beginning-of-line)
      (while (and (looking-at "[ \t]*$")
                  (= (forward-line) 0)
                  (setq first (point))))
      ;; Is point within a comment statement?
      (if (or (and (looking-at "[ \t]*comment")
                   (setq first (point)))
              ;; (See ‘reduce-font-lock-extend-region-for-comment-statement’.)
              (save-excursion
                (and (re-search-backward "\\(comment\\)\\|\\(;\\)" nil t)
                     (match-beginning 1)
                     (setq first (point)))))
          ;; Yes – use normal text-mode fill, but only within the
          ;; comment statement, which might be within code:
          (save-restriction
            (narrow-to-region first (save-excursion (search-forward ";")))
            (fill-paragraph justify))
        ;;No...
        ;; If point is in a %-comment then find its prefix and fill it:
        (if (looking-at "[ \t]*%")
            (let (fill-prefix last)
              ;; Code modified from ‘set-fill-prefix’ in fill.el.
              (setq fill-prefix (buffer-substring
                                 (point)
                                 (progn (skip-chars-forward " \t%") (point))))
              (if (equal fill-prefix "")
                  (setq fill-prefix nil))
              ;; Find the last line of the comment:
              (while (and (= (forward-line) 0)
                          (looking-at "[ \t]*%")))
              (setq last (point))
              ;; Move to the first line of the comment:
              (if first
                  (goto-char first)
                (while (and (= (forward-line -1) 0)
                            (looking-at "[ \t]*%")) )
                ;; Might have reached BOB, so ...
                (if (not (looking-at "[ \t]*%"))
                    (forward-line)))
              ;; Fill region as one paragraph: break lines to fit fill-column.
              (fill-region-as-paragraph (point) last justify)))))))


;;;; ***************************
;;;; Structure template commands
;;;; ***************************

(defun reduce-insert-if-then (&optional else)
  "Insert ‘if ... then’; if ELSE then include ‘else’.
Position point after ‘if’.
With argument include a correctly indented ‘else’ on a second line."
  (interactive "*P")            ; error if buffer read-only
  (insert "if ")
  (let ((finish (point)))
    (insert " then ")
    (if else
    (progn
      (newline)
      (insert "else ")
      (reduce-indent-line)
      ))
    (goto-char finish)
    ))

(defun reduce-insert-block (&optional nosplit)
  "Insert and indent ‘begin ... end’ block; if NOSPLIT then on same line.
Position point inside.
With argument put ‘begin’ and ‘end’ on the same line
\(see ‘reduce-insert-block-or-group’)."
  (interactive "*P")            ; error if buffer read-only
  (reduce-insert-block-or-group "begin" "end" t nosplit))

(defun reduce-insert-group (&optional nosplit)
  "Insert and indent ‘<<  >>’ group; if NOSPLIT then on same line.
Position point inside.
With argument put ‘<<’ and ‘>>’ on the same line
\(see ‘reduce-insert-block-or-group’)."
  (interactive "*P")            ; error if buffer read-only
  (reduce-insert-block-or-group "<<" ">>" nil nosplit))

(defun reduce-insert-block-or-group (open close block nosplit)
  "Insert and indent ‘open ... close’ structure and position point inside.
If the mark is transient and active then enclose the region; otherwise
if point is not at the end of the line then enclose the rest of the line.
Leave the mark at the insertion point in the body of a block.
If ‘nosplit’ is true then put ‘open’ and ‘close’ on the same line."
  (let ((region-beginning (and transient-mark-mode mark-active
                   (region-beginning)))
    (region-end (and transient-mark-mode mark-active
             (copy-marker (region-end))))
    finish-marker)
    (if region-beginning (goto-char region-beginning))
    (insert open)
    (if block (progn
        (insert " scalar ")
        (setq finish-marker (point-marker))
        (insert ";")))
    (if (looking-at "[ \t]*$") ()
      (if nosplit (insert " ") (newline-and-indent)))
    (if region-end
    (progn              ; better to indent rigidly?
      (reduce-indent-region (point) region-end)
      (goto-char region-end)
      (if (bolp) (backward-char))
      (set-marker region-end nil) )
      (if (looking-at "[ \t]*$") ()
    ;; (reduce-forward-statement 1)
    (end-of-line)
    (setq region-end t)) )
    (if region-end ()
      (reduce-indent-line)
      (if nosplit (insert " ") (newline-and-indent)) )
    (if block (push-mark) (setq finish-marker (point-marker)))
    (if nosplit (insert " ") (newline))
    (insert close)
    (if (looking-at "[ \t]*else")
    (just-one-space)
      (insert ";")
      (if (looking-at "[ \t]*$") ()
    (insert "  ")) )
    (reduce-indent-line)        ; necessary AFTER inserting close
    (goto-char finish-marker)
    (set-marker finish-marker nil)
    ))

;; If an expansion function interprets an argument then it means that
;; the expansion should be kept on one line.  The following are
;; provided solely to ignore any argument:

(defun reduce-expand-if-then (&optional arg)
  "Insert ‘if ... then’ and position point inside, ignoring ARG."
  (reduce-insert-if-then))

(defun reduce-expand-if-then-else (&optional arg)
  "Insert ‘if ... then ... else’ and position point after ‘if’, ignoring ARG."
  (reduce-insert-if-then 'else))


;;;; *************************************
;;;; Support for matching group delimiters
;;;; *************************************

(defun reduce-self-insert-and-blink-matching-group-open ()
  "Insert character and then blink matching group opening construct."
  ;; Based on blink-matching-open in simple.el
  ;; but cannot use syntax table for composite tokens like << ... >>
  (interactive "*")         ; error if buffer read-only
  ;; (insert last-command-char)
  (insert ?>)
  (and (= (char-after (- (point) 2)) ?>)
       blink-matching-paren
       (save-excursion
     (save-restriction
       (if blink-matching-paren-distance
           (narrow-to-region
        (max (point-min)
             (- (point) blink-matching-paren-distance))
        (point)))
       (backward-char 2)
       (reduce--backward-group)
       )
     (if (looking-at "<<")
         (blink-point)
       (message "Matching << not found"))
     ;; [within blink-matching-paren-distance]
     )
       ))

(defun blink-point ()
  "Blink the position of point."
  ;; Based closely on blink-matching-open in simple.el
  (if (pos-visible-in-window-p)
      (sit-for 1)
    (let ((blinkpos (point)))
      (message
       "Matches %s"
       (if (save-excursion
         (skip-chars-backward " \t")
         (not (bolp)))
       (buffer-substring (progn (beginning-of-line) (point))
                 (+ blinkpos 2))
     (buffer-substring blinkpos
               (progn
                 (forward-char 1)
                 (skip-chars-forward "\n \t")
                 (end-of-line)
                 (point)))))
      )))


;;;; *****************************
;;;; Support for reposition-window
;;;; *****************************

;; The next two functions should probably be built into
;; reduce-forward/backward-procedure:

(defun reduce-beginning-of-defun (&optional arg)
  (if (null arg) (setq arg 1))
  (if (> arg 0)
      (reduce-backward-procedure arg)
    (reduce-forward-procedure (- 1 arg))
    (reduce-backward-procedure 1)))

(defun reduce-end-of-defun (&optional arg)
  (if (null arg) (setq arg 1))
  (if (> arg 0)
      (reduce-forward-procedure arg)
    (reduce-backward-procedure (- 1 arg))
    (reduce-forward-procedure 1)))

(defun reduce-reposition-window ()
  "See ‘reposition-window’ for details."
  (interactive)
  (let ((beginning-of-defun (symbol-function 'beginning-of-defun))
    (end-of-defun (symbol-function 'end-of-defun)))
    (fset 'beginning-of-defun 'reduce-beginning-of-defun)
    (fset 'end-of-defun 'reduce-end-of-defun)
    (condition-case nil
    (reposition-window)
      (error (message "Error trapped in reposition-window")))
    (fset 'beginning-of-defun beginning-of-defun)
    (fset 'end-of-defun end-of-defun)
    ))


;;;; ******************************************************
;;;; Support for REDUCE keyword/phrase/structure completion
;;;; ******************************************************

(defun reduce-complete-symbol (arg)
  "Perform completion on REDUCE symbol preceding point or region.
Do this only if mark is transient and active.
Compare that symbol against the elements of ‘reduce-completion-alist’.
If a perfect match (only) has a cdr then delete the match and insert
the cdr if it is a string or call it if it is a (nullary) function,
passing on any prefix argument (in raw form)."
  ;; Based on lisp-complete-symbol in lisp.el
  (interactive "*P")            ; error if buffer read-only
  (let* ((end (progn
        (cond ((and transient-mark-mode mark-active)
               (if (= (point) (region-beginning))
               ()
             (exchange-point-and-mark)
             (skip-syntax-backward " "))))
        (point)))
     (beg (unwind-protect
          (save-excursion
            (reduce-backward-sexp 1)
            ;; (while (= (char-syntax (following-char)) ?\')
              ;; (forward-char 1))
            (skip-syntax-forward "\'")
            (point))
        ))
     (pattern (buffer-substring-no-properties beg end))
     (completion (try-completion pattern reduce-completion-alist)))
    (cond ((eq completion t)        ; perfect match
       (let ((fn (cdr (assoc pattern reduce-completion-alist))))
         (if fn
         (cond ((stringp fn) (delete-region beg end) (insert fn))
               ((fboundp fn) (delete-region beg end) (funcall fn arg))
               (t (error "Completion for \"%s\" not a string or function" pattern)))
           )))
      ((null completion)
       (message "Can't find completion for \"%s\"" pattern)
       (ding))
      ((not (string= pattern completion))
       (delete-region beg end)
       (insert completion)
       (if (fboundp (cdr (assoc completion reduce-completion-alist)))
           (setq deactivate-mark nil))) ; for beg -> begin -> ...
      (t
       (message "Making completion list...")
       (let ((list (all-completions pattern reduce-completion-alist)))
         (with-output-to-temp-buffer "*Completions*"
           (display-completion-list list)))
       (message "Making completion list...%s" "done")))))


;;;; **********************************************************
;;;; Support for displaying current procedure name in mode line
;;;; **********************************************************

(defvar reduce-show-proc-idle-timer nil)

(defvar reduce-show-proc-string nil)
(defvar which-func-mode)

(defun reduce-show-proc-mode (&optional arg)
  "Toggle REDUCE Show Proc mode.
With prefix ARG, turn REDUCE Show Proc mode on if and only if ARG is positive.
Returns the new status of REDUCE Show Proc mode (non-nil means on).

When REDUCE Show Proc mode is enabled, display current procedure name
in mode line after ‘reduce-show-proc-delay’ seconds of Emacs idle time."
  (interactive "P")
  (let ((on-p (if arg
          (> (prefix-numeric-value arg) 0)
        (not reduce-show-proc-mode))))
    (if reduce-show-proc-idle-timer
    (cancel-timer reduce-show-proc-idle-timer))
    (if on-p
    (setq reduce-show-proc-idle-timer
          (run-with-idle-timer reduce-show-proc-delay t
                   'reduce-show-proc-function)))
    (setq reduce-show-proc-mode on-p
      which-func-mode on-p)
    (reduce-show-proc-function)))

(defconst reduce-show-proc-regexp
  (car reduce-imenu-generic-expression))

(defun reduce-current-proc ()
  "Return name of procedure definition point is in, or nil."
  ;; Used by reduce-show-proc-mode and ChangeLog support
  (let ((start (point)) procname)
    (end-of-line)
    (save-match-data
      (when (re-search-backward
         (nth 1 reduce-show-proc-regexp) nil t)
    (setq procname
          (match-string (nth 2 reduce-show-proc-regexp)))
    (reduce-forward-procedure 1)
    (if (<= (point) start)      ; not in procedure
        (setq procname nil))))
    (goto-char start)
    procname))

(defun reduce-show-proc-function ()
  "Display current procedure name in mode line."
  (when (eq major-mode 'reduce-mode)
    (setq reduce-show-proc-string
      (concat "[" (or (reduce-current-proc) "") "]"))
    (force-mode-line-update)))


;;;; *****************************************
;;;; Support for tagging procedure definitions
;;;; *****************************************

(defcustom reduce-etags-directory invocation-directory
  "Directory containing the etags program, or nil if it is in path.
If non-nil the string must end with /."
  :package-version '(reduce-ide . "1.54")
  :type '(choice (directory :tag "Etags program directory")
                 (const :tag "Etags is in exec path" nil))
  :group 'reduce-interface)

(defun reduce-tagify-dir (dir)
  "Generate a REDUCE TAGS file for ‘*.red’ files in directory DIR.
TAGS goes in DIR, which by default is the current directory."
  (interactive
   (list (read-directory-name
          "Tag files in dir: "          ; PROMPT
          nil                           ; DIR (default cwd)
          nil                           ; DEFAULT-DIRNAME
          t)))                          ; MUSTMATCH
  (setq dir (directory-file-name (expand-file-name dir)))
  (reduce--tagify
   dir (directory-files dir nil "\\.red\\'")
   (message "Tagging files ‘%s/*.red’..." dir)))

(defun reduce--tagify (dir files msg)
  "Generate a REDUCE TAGS file in directory DIR for specified FILES.
FILES must be a list of filenames, which can be relative to DIR.
MSG is the message displayed when the tagging process started."
  (let* ((default-directory dir)
         (value
          (apply
           #'call-process              ; creates a synchronous process
           (concat reduce-etags-directory "etags") ; program
           nil                                     ; infile
           "*rtags-log*"                           ; destination
           nil                                     ; display
           "--lang=none"                           ; args ...
           "--regex=/[^%]*procedure[ \\t]+\\([^ \\t\(;$]+\\)/\\1/i"
           files)))                     ; LIST of filenames
    (if (eq value 0)
        (message "%sdone" msg)
      (message "etags failed with status: %s" value))))

(defun reduce-tagify-dir-recursively (dir)
  "Generate a REDUCE TAGS file for all ‘*.red’ files under directory DIR.
TAGS goes in DIR, which by default is the current directory."
  (interactive
   (list (read-directory-name
          "Tag all files under dir: "   ; PROMPT
          nil                           ; DIR (default cwd)
          nil                           ; DEFAULT-DIRNAME
          t)))                          ; MUSTMATCH
  (setq dir (directory-file-name (expand-file-name dir)))
  (let ((reduce--tagify-root dir))
    ;; reduce--tagify-root required by ‘reduce--directory-files-recursively’.
    (reduce--tagify
     dir (reduce--directory-files-recursively dir)
     (message "Tagging all files ‘%s/...*.red’..." dir))))

(defvar reduce--tagify-root)

(defun reduce--directory-files-recursively (dir)
  "Return a list of all ‘*.red’ files under DIR.
This function works recursively.  Files are returned in \"depth first\"
order, and files from each directory are sorted in alphabetical order.
Each file name appears in the returned list relative to directory
‘reduce--tagify-root’, assumed to be bound locally in the caller."
  ;; Modelled on ‘directory-files-recursively’.
  (let (result
        files
        ;; When DIR is "/", remote file names like "/method:" could
        ;; also be offered.  We shall suppress them.
        (tramp-mode (and tramp-mode (file-remote-p (expand-file-name dir)))))
    (dolist (file (sort (file-name-all-completions "" dir) 'string<))
      (unless (member file '("./" "../"))
        (if (directory-name-p file)
            (let* ((leaf (substring file 0 -1))
                   (full-file (expand-file-name leaf dir)))
              (setq result
                    (nconc result (reduce--directory-files-recursively
                                   full-file))))
          (when (string-match "\\.red\\'" file)
            (push (file-relative-name
                   (expand-file-name file dir)
                   reduce--tagify-root)
                  files)))))
    (nconc result (nreverse files))))


;;;; **********************************************************************

;;; Load Hook
(defun require-reduce-run ()
  "Require REDUCE Run mode.  Useful on ‘reduce-mode-load-hook’."
  (require 'reduce-run))

(provide 'reduce-mode)

(run-hooks 'reduce-mode-load-hook)

;;; reduce-mode.el ends here
