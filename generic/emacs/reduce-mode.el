;;; reduce-mode.el --- Major mode to edit REDUCE computer-algebra code  -*- lexical-binding: t; -*-

;; Copyright (C) 1998-2001, 2012, 2017-2019, 2022 Francis J. Wright

;; Author: Francis J. Wright <https://sites.google.com/site/fjwcentaur>
;; Created: late 1992
;; Time-stamp: <2022-12-14 15:40:10 franc>
;; Homepage: https://reduce-algebra.sourceforge.io/reduce-ide/
;; Package-Version: 1.10
;; Package-Requires: (cl-lib)

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

;;  more flexible intelligent indentation, rationalize the code
;;  make skipping comment statements configurable (?)
;;  add RLisp88 support (?)
;;  more structure templates (?) – while, repeat

;;; Code:
(eval-when-compile (require 'cl-lib))

(defconst reduce-ide-version
  ;; Extract version from Package-Version in file header:
  (eval-when-compile
    (require 'lisp-mnt)
    (save-excursion (lm-header "package-version")))
  "Version information for REDUCE IDE.")

;; (message "Loading reduce-mode")  ; TEMPORARY!

;; Customizable user options:

;;;###autoload
(defgroup reduce nil
  "Support for editing and running REDUCE code."
  :tag "REDUCE"
  :group 'languages
  :link '(custom-manual "(reduce-ide)Top")
  :link '(url-link "https://reduce-algebra.sourceforge.io/reduce-ide/"))

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

(defgroup reduce-run nil
  "Support for running REDUCE code.
Note that REDUCE Run inherits from comint."
  :tag "REDUCE Run"
  :group 'reduce
  :link '(custom-group-link comint)
  ;; Include the REDUCE Run customization options:
  :load "reduce-run")

(defcustom reduce-mode-load-hook nil
  "List of functions to be called when REDUCE mode is loaded.
It can be used to customize global features of REDUCE mode and so
is a good place to put keybindings."
  :type 'hook
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

(defcustom reduce-comment-region-string "%% "
  "String inserted by \\[reduce-comment-region] at start of each line."
  :version "1.21" ; Name was reduce-comment-region up to version 1555!
  :type 'string
  :group 'reduce-format)

(defcustom reduce-auto-indent-mode t
  "If non-nil then conditionally re-indent the current line.
This will happen after ‘reduce-auto-indent-delay’ seconds of idle
time if the text just typed matches ‘reduce-auto-indent-regex’."
  :set (lambda (_symbol value)
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
  :set (lambda (_symbol value)
     (reduce-show-proc-mode (or value 0)))
  :initialize 'custom-initialize-default
  :type 'boolean
  :group 'reduce-display)

(defcustom reduce-show-proc-delay 0.125
  "Time in seconds to delay before showing the current procedure name."
  :type 'number
  :group 'reduce-display)

;; Run:

(defcustom autoload-reduce-run 'menu
  "Whether, and if so how, to autoload REDUCE Run mode.
Loading it is necessary only if you plan to run REDUCE within
REDUCE IDE.  If the value is t then load REDUCE Run mode after
‘reduce-mode’ has loaded; if it is ‘menu’ (the default) then
display a Run REDUCE menu stub that can load REDUCE Run mode; if
it is nil then do nothing."
  :type '(choice (const :tag "Load REDUCE Run mode" t)
                 (const :tag "Display Run REDUCE menu stub" menu)
                 (const :tag "Do nothing" nil))
  :group 'reduce-run)

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

;; The following two constants are also used in reduce-font-lock.el.

(defconst reduce-identifier-regexp
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

(defconst reduce-whitespace-regexp
  "\\(?:\\s-\\|\n\\|%.*?\n\\|/\\*.*?\\*/\\)"
  "Regexp that matches a white space or comment.
Precisely, a single white space (including newline), or a single
%- or /**/-comment.")


;;;; **********************
;;;; Keyboard and menu maps
;;;; **********************

(defvar reduce-mode-map
  (let ((map (make-sparse-keymap)))
    ;; (define-key map ">" 'reduce-self-insert-and-blink-matching-group-open)
    (define-key map "\C-j" 'reindent-then-newline-and-indent)
    (define-key map "\M-i" 'reduce-indent-line)
    (define-key map [(control tab)] 'reduce-indent-line-always)
    (define-key map [backtab] 'reduce-unindent-line) ; [(shift tab)]
    ;; (define-key map [del] 'backward-delete-char-untabify)
    (define-key map "\C-c\C-n" 'reduce-forward-statement)
    (define-key map "\C-c\C-p" 'reduce-backward-statement)
    (define-key map "\C-c\C-d" 'reduce-down-block-or-group)
    (define-key map "\C-c\C-u" 'reduce-up-block-or-group)
    (define-key map "\C-c\C-k" 'reduce-kill-statement)
    (define-key map "\C-\M-f" 'reduce-forward-sexp)
    (define-key map "\C-\M-b" 'reduce-backward-sexp)
    (define-key map "\C-\M-k" 'reduce-kill-sexp)
    (define-key map "\C-\M-e" 'reduce-forward-procedure)
    (define-key map "\C-\M-a" 'reduce-backward-procedure)
    (define-key map "\C-\M-h" 'reduce-mark-procedure)
    (define-key map "\C-xnd" 'reduce-narrow-to-procedure)
    (define-key map "\C-ck" 'reduce-kill-procedure)
    ;; (define-key map "\C-\M-\\" 'reduce-indent-region)
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

;; REDUCE-run menu bar and pop-up menu stub
(when (eq autoload-reduce-run 'menu)
  (easy-menu-define                     ; (symbol maps doc menu)
    reduce-mode-run-menu
    reduce-mode-map
    "REDUCE Mode Run Menu stub -- updated when REDUCE Run is loaded."
    '("Run REDUCE"
      ["Run REDUCE" run-reduce :active t
       :help "Start a new REDUCE process"]
      ["Load REDUCE Run Mode" (require 'reduce-run) :active t
       :help "Load the full REDUCE Run mode functionality"])))

;; REDUCE-mode menu bar and pop-up menu
(easy-menu-define           ; (symbol maps doc menu)
 reduce-mode-menu
 reduce-mode-map
 "REDUCE Mode Menu."
 '("REDUCE"
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
   "--"
   "Procedures:"
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
   "--"
   "Templates:"
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
   ["Command Mini Help" (apropos-command "\\`reduce\\|reduce\\'") :active t
    :help "Show a REDUCE Mode command summary"]
   ["Customize..." (customize-group 'reduce) :active t
    :help "Customize REDUCE Mode"]
   ["Show Version" reduce-ide-version :active t
    :help "Show the REDUCE IDE version"]
   ;; This seems to be obsolete in Emacs 26!
   ;; ["Outline" outline-minor-mode
   ;;  :style toggle :selected outline-minor-mode :active t
   ;;  :help "Toggle outline minor mode"]
   ["Update ChangeLog" add-change-log-entry-other-window :active t
    :help "Add change log entry other window"]
   ))

(defun reduce-ide-version ()
  "Echo version information for REDUCE IDE."
  (interactive)
  (message "REDUCE IDE Version: %s" reduce-ide-version))


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
    (modify-syntax-entry ?* ". 23b" table) ; C-style comment
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
Version: see ‘reduce-ide-version’.\\<reduce-mode-map>
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
The indentation increment is the value of the variable ‘reduce-indentation’.

Structure template commands are provided to insert and indent
if-then (‘\\[reduce-insert-if-then]’), block (‘\\[reduce-insert-block]’) and group (‘\\[reduce-insert-group]’) constructs,
the latter optionally on a single line.

The command ‘\\[reduce-complete-symbol]’ performs REDUCE
keyword/phrase/structure completion.

Text highlighting is supported via the command ‘font-lock-mode’, and
the style of highlighting may be controlled by setting
‘font-lock-maximum-decoration’ to one of:

  0, nil – basic keyword highlighting;
  1      – algebraic-mode highlighting;
  2, t   – symbolic-mode highlighting.

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
  ;; (setq-local paragraph-separate
  ;;             ;; paragraph-start)
  ;;             (concat paragraph-start "\\|^%"))
                                        ; RS
  ;; so that comments at beginning of a line do not disturb reformatting.
  (setq-local paragraph-ignore-fill-prefix t)
  (setq-local indent-line-function #'reduce-indent-line
              indent-region-function #'reduce-indent-region)
  (setq-local comment-start "% ")
  (setq-local comment-start-skip
              "\\(?:^\\|[^!]\\)%+ *")   ; "%+ *" but not !%
  (setq comment-column 40)              ; auto buffer local
  (setq-local comment-indent-function #'reduce-comment-indent)
  ;; (setq fill-prefix "% ")        ; buffer local
  (setq-local
   ;; Fix syntax of ! at the end of a strings:
   syntax-propertize-function
   #'reduce--syntax-propertize
   ;; Make syntax scanning functions, like ‘forward-sexp’, pay
   ;; attention to ‘syntax-table’ text properties:
   parse-sexp-lookup-properties t
   ;; Treat escape char (!) as part of word:
   words-include-escapes t)
  ;; This is needed for the comment statement parser:
  (add-hook 'before-change-functions
            'reduce--comment-seq-reset nil t))

(defun reduce--syntax-propertize (start end)
  "Syntax-propertize buffer text between START and END.
Mark ! followed by \" as having punctuation syntax (syntax-code
1) if in a string, for correct syntactic processing of strings."
  ;; Allowed to arbitrarily move point within the region delimited by
  ;; START and END.
  (while (< start end)
    (and (eq (char-after start) ?!)
         (eq (char-after (1+ start)) ?\")
         (nth 3 (syntax-ppss start))    ; moves point to start
         (put-text-property start (1+ start) 'syntax-table '(1 . nil)))
    (setq start (1+ start))))

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


;;;; *******************************
;;;; Parse REDUCE comment statements
;;;; *******************************

;; Created: October 2022

;; This code provides an analogue of syntax-ppss for REDUCE comment
;; statements, which cannot be handled by the Emacs parser.  It builds
;; a sequence of start and finish positions for comment statements and
;; uses it to detect efficiently whether a position is within such a
;; statement and if so to determine its start and finish.

(defvar-local reduce--comment-seq nil
  "A sequence of elements of the form (start . finish), or nil.
The car of each element is the position at the start of a comment
statement and the cdr is the position immediately after the end
of that comment statement.  The value is nil if there are no
comment statements, which is a common special case.")

(defun reduce--build-comment-seq ()
  "Scan the buffer for comment statements.
Use the information found to build ‘reduce--comment-seq’."
  (let ((case-fold-search t) lst)
    (save-excursion
      (save-restriction
        (widen) (goto-char (point-min))
        (save-match-data
          (while (re-search-forward "\\_<comment\\_>" nil t)
            ;; Unless in a string or syntactic comment...
            (unless (nth 8 (syntax-ppss))
              (push (cons (match-beginning 0)
                          (or (re-search-forward "[\;$]" nil t) (point-max)))
                    lst))))))
    (setq reduce--comment-seq (and lst (nreverse (vconcat lst))))))

;; Resetting reduce--comment-seq to nil before every edit is somewhat
;; crude!  But it seems to work for now and not be noticeably slow.
;; It should be possible (later) to re-parse only from the start of
;; the change, rather than from the start of the buffer.

(defun reduce--comment-seq-reset (_beg &rest _ignored-args)
  "Reset ‘reduce--comment-seq’ to nil, currently ignoring all args.
It *should* flush ‘reduce--comment-seq’ from position BEG.  The
remaining arguments, IGNORED-ARGS, are ignored; this function
accepts them so that it can be directly used on the hook
‘before-change-functions’, which is set up  in ‘reduce-mode’."
  (setq reduce--comment-seq nil))

;; (defun reduce--highlight-comment-statements ()
;;   "Highlight all comment statements in the buffer.
;; Only works reliably with font-lock off, so turns font-lock off.
;; Purely intended for testing."
;;   (interactive)
;;   (let ((seq (or reduce--comment-seq (reduce--build-comment-seq))))
;;     (when seq                           ; nil if no comment statements
;;       (font-lock-mode 0)
;;       (with-silent-modifications
;;         (mapc
;;          (lambda (i)                    ; i = (start . finish)
;;            (add-face-text-property (car i) (cdr i) 'highlight))
;;          seq)))))

(defun reduce--in-comment-statement-p (&optional pos)
  "Return a cons if POS is within a comment statement; nil otherwise.
If POS is omitted then it defaults to point.  The cons has the
form (start . finish), where start is the position at the start
of the comment statement containing POS and finish is the
position immediately after the end of that comment statement."
  (interactive)
  (let ((seq (or reduce--comment-seq (reduce--build-comment-seq))))
    (when seq                           ; nil if no comment statements
      (unless pos (setq pos (point)))
      (let ((lower 0) (upper (1- (length seq))) value)
        ;; seq is a sequence of integer intervals.  Use bisection to
        ;; search seq for an interval surrounding POS.  lower < mid <
        ;; upper are indices into seq and mid is the (integer) mid-point
        ;; between lower and upper.  ivl is the mid-point interval.
        (while (<= lower upper)
          (let* ((mid (/ (+ lower upper) 2)) (ivl (elt seq mid))
                 (start (car ivl)) (finish (cdr ivl)))
            (cond ((< finish pos)       ; interval < pos
                   (setq lower (1+ mid)))
                  ((< pos start)        ; pos < interval
                   (setq upper (1- mid)))
                  ((eq finish pos)      ; pos = interval-finish
                   (setq lower (1+ upper))) ; -- stop loop
                  ;; interval-start <= pos < interval-finish
                  ;; so pos within interval -- stop loop
                  (t (setq lower (1+ upper) value ivl)))))
        (when (called-interactively-p 'interactive) (message "%s" value))
        value))))

(defsubst reduce--in-string-or-comment-p (&optional pos)
  "Return non-nil if POS is within a string or comment; nil otherwise.
If POS is omitted then it defaults to point.  If POS is inside a
string, return the position where the string began; if inside a %
or /**/ comment, return the position where the comment began; if
inside a comment statement return a cons of the form (start
. finish), where start is the position at the start of the
comment statement and finish is the position immediately after
the end of that comment statement."
  (or (nth 8 (syntax-ppss pos))
      (reduce--in-comment-statement-p pos)))


;;;; *****************************************************************
;;;; Searching for syntactic elements ignoring comments, strings, etc.
;;;; *****************************************************************

(defun reduce--re-search-forward (regexp &optional MOVE)
  "Syntactic search forwards for REGEXP.
Skip comments, strings, escaped and quoted tokens.  If match
found then move point to end of match and return t, else return
nil.  If no match found and MOVE is non-nil then move point as
far as possible, otherwise do not move point at all."
  (let ((start (point))
        (move (if MOVE 'move t)))
    (if (reduce--re-search-forward1 regexp move)
        t
      (unless MOVE (goto-char start))
      nil)))

(defun reduce--re-search-forward1 (regexp move)
  "Search forwards for REGEXP; if no match and MOVE then move to EOB.
Recursive sub-function of ‘reduce--re-search-forward’.
Process match to skip comments, strings, etc.
Return t if match found, nil otherwise."
  (when (re-search-forward regexp nil move)
    (let (tmp)
      (if (cond                     ; check match -- t => search again
           ((memq (char-before (match-beginning 0)) '(?! ?'))) ; escaped or quoted
           ((nth 3 (setq tmp (syntax-ppss))) ; in string
            (goto-char (nth 8 tmp))
            (forward-sexp) t)
           ((nth 4 tmp)                 ; in % or /*...*/ comment
            (goto-char (nth 8 tmp))
            (forward-comment 1) t)
           ((setq tmp (reduce--in-comment-statement-p
                       (match-beginning 0))) ; comment statement
            (goto-char (cdr tmp)) t))
          (reduce--re-search-forward1 regexp move) ; search again
        t))))                         ; match for original regexp found


(defun reduce--re-search-backward (regexp &optional MOVE)
  "Syntactic search backwards for REGEXP.
Skip comments, strings, escaped and quoted tokens.  If match
found then move point to beginning of match and return t, else
return nil.  If no match found and MOVE is non-nil then move
point as far as possible, otherwise do not move point at all."
  (let ((start (point))
        (move (if MOVE 'move t)))
    (if (reduce--re-search-backward1 regexp move)
        t
      (unless MOVE (goto-char start))
      nil)))

(defun reduce--re-search-backward1 (regexp move)
  "Search backwards for REGEXP; if no match and MOVE then move to BOB.
Recursive sub-function of ‘reduce--re-search-backward’.
Process match to skip comments, strings, etc.
Return t if match found, nil otherwise."
  (when (re-search-backward regexp nil move)
    (let (tmp)
      (if (cond                     ; check match -- t => search again
           ((memq (preceding-char) '(?! ?'))) ; escaped or quoted
           ((setq tmp (nth 8 (syntax-ppss)))
            ;; in string or % or /**/ comment
            (goto-char tmp) t)          ; skip it
           ((setq tmp (reduce--in-comment-statement-p))
            ;; in comment statement
            (goto-char (car tmp)) t))               ; skip it
          (reduce--re-search-backward1 regexp move) ; search again
        t))))                         ; match for original regexp found


;;;; **********************************************
;;;; Skipping comments and white space of all types
;;;; **********************************************

(defun reduce--skip-comments-forward ()
  "Move forwards across comments and white space of all types."
  (let (cmnt)
    (forward-comment (buffer-size)) ; syntactic comments & white space
    (while (setq cmnt (reduce--in-comment-statement-p))
      (goto-char (cdr cmnt))
      (forward-comment (buffer-size))))) ; syntactic comments & white space

(defun reduce--skip-comments-backward ()
  "Move backwards across comments and white space of all types."
  (let (cmnt)
    (forward-comment (-(buffer-size))) ; syntactic comments & white space
    (while (setq cmnt (reduce--in-comment-statement-p (1- (point))))
      (goto-char (car cmnt))
      (forward-comment (-(buffer-size)))))) ; syntactic comments & white space


;;;; ********************
;;;; Indentation commands
;;;; ********************

;; This section updated 13 October 2022, but needs a lot more work!

(defun reduce-indent-line (&optional arg)
  "Indent current line; if ARG indent whole statement rigidly.
Indents to fixed style determined by current and previous
non-blank line.  With argument, indent any additional lines of
the same statement rigidly together with this one.  Assigned
locally to ‘indent-line-function’ to implement
‘indent-for-tab-command’."
  (interactive "*P")                    ; error if buffer read-only
  (let ((start-marker (point-marker))
        (indentation (progn (back-to-indentation) (current-column)))
        (new-indent (reduce--calculate-indent)))
    (if (< new-indent indentation) (delete-horizontal-space))
    (indent-to new-indent)
    (if arg
        (save-excursion
          (setq indentation (- (current-column) indentation))
          (indent-rigidly
           (point) (reduce-forward-statement 1) indentation)))
    (if (< (point) start-marker) (goto-char start-marker))
    (set-marker start-marker nil)))

(defun reduce--calculate-indent ()
  "Return appropriate indentation for current line as REDUCE code."
  (let ((case-fold-search t)
        ;; Check whether point is in a comment first:
        (comment-indent (reduce--calculate-indent-comment)))
    ;; comment-indent is t for the first line of a comment and
    ;; numerical for subsequent lines of a multi-line comment:
    (or (and (numberp comment-indent) comment-indent)
        (reduce--calculate-indent-proc)
        (unless comment-indent (reduce--calculate-indent-this))
        (reduce--calculate-indent-prev))))

(defun reduce--calculate-indent-comment ()
  "Return non-nil if point is in a comment.
Return t if point is in the first or only line of a comment.
Return the indentation of the previous comment line if point is
below the first line of a multi-line comment.  This applies to
any type of comment."
  (save-excursion
    (back-to-indentation)
    (cond
     ;; % comment:
     ((looking-at "%")
      (if (and (eq (forward-line -1) 0)
               (looking-at "\\s-*%"))
          (current-indentation)         ; later line
        t))                             ; first line
     ;; First line of /**/ comment:
     ((looking-at "/\\*") t)
     ;; First line of comment statement:
     ((looking-at "\\_<comment\\_>") t)
     ;; Later line of /**/ comment or comment statement:
     ((or (nth 4 (syntax-ppss)) (reduce--in-comment-statement-p))
      (forward-line -1)
      (current-indentation)))))

(defsubst reduce--looking-at-procedure ()
  "Return t if text after point matches the start of a procedure."
  (looking-at "[a-z \t\f\n]*\\_<procedure\\_>"))

(defun reduce--calculate-indent-proc ()
  "Return non-nil if point in or above procedure header or below body.
If above or below and point is within white space or comments
then return 0 unless point is in a continuation of the procedure
header onto subsequent lines, in which case return
‘reduce-indentation’; otherwise return nil."
  (save-excursion
    (beginning-of-line)
    (condition-case nil
        (let ((start (point)))
          (or
           ;; Point in or above procedure header, separated only by
           ;; white space or comments?
           (progn
             (reduce-forward-statement 1)
             (reduce-backward-statement 1)
             (when (reduce--looking-at-procedure)
               (if (> start (point))    ; start below "procedure"
                   reduce-indentation   ; on continuation line
                 0)))
           ;; Point below procedure, separated only by white space or
           ;; comments?
           (progn
             (goto-char start)
             (reduce-backward-statement 2)
             (when (reduce--looking-at-procedure)
               ;; Check start not within procedure body:
               (reduce-forward-statement 2)
               (when (> start (point)) 0)))))
      (t nil))))

(defconst reduce--label-or-end-regexp
  ;; "[^:\n]+:[^=]\\|\\_<end\\_>"
  (concat reduce-identifier-regexp reduce-whitespace-regexp "*"
          ":[^=]\\|\\_<end\\_>")
  "Regexp that matches a label or end token.")

(defun reduce--calculate-indent-this ()
  "Return indentation for current line beginning with a special token.
The indentation depends on *this* and previous non-blank lines.
For an opening token (‘begin’ or ‘<<’) normally return the indentation of
the previous non-blank line; for an intermediate token (‘then’ or ‘else’)
return the indentation of the beginning of the statement; for a
closing token (‘end’ or ‘>>’) return the indentation of the beginning
of the construct; otherwise return nil."
  (save-excursion
    (back-to-indentation)
    (cond
     ;; *** Opening token ***
     ((looking-at "[\({ \t]*\\(?:\\_<begin\\_>\\|<<\\)")
      (let ((closed (looking-at ".*\\(?:\\_<end\\_>\\|>>\\)")))
        ;; Closed true if opening and closing tokens on same line.
        ;; Find previous non-blank line:
        (skip-chars-backward " \t\f\n")
        ;; Go to beginning of statement or line:
        (if (memq (char-before) '(?\; ?$))
            (reduce-backward-statement 1)
          (back-to-indentation))
        (cond ((reduce--looking-at-procedure)
               reduce-indentation)
              ((and
                (or closed                     ; single-line construct
                    (looking-at ".*:="))       ; assignment
                (not (looking-at ".*[;$]")))   ; not completed
               (+ (current-column) reduce-indentation))
              (t
               (current-column)))))
     ;; *** Intermediate tokens ***
     ((looking-at "\\_<\\(?:then\\|else\\)\\_>")
      (reduce--find-matching-if) (current-indentation))
     ;; *** Label or closing tokens ***
     ;; Indent to beginning of enclosing block or group:
     ((and (looking-at reduce--label-or-end-regexp)
           (save-excursion              ; check really in block
             (and (reduce--backward-block) (current-indentation)))))
     ((looking-at ">>")
      (reduce--backward-group) (current-indentation))
     ;; *** Symbolic mode tokens ***
     ((looking-at "\\_<\\(?:\\(?:end\\)?module\\)\\_>\\|\
#\\(?:define\\|\\(?:el\\)?if\\|else\\|endif\\)\\_>")
      0)
     ;; *** Within continuation of multi-line string ***
     ((let ((state (syntax-ppss)))
        (and (nth 3 state)              ; within string
             (< (nth 8 state) (line-beginning-position))))
      0))))

(defun reduce--find-matching-if ()
  "Search backwards for the ‘if’ matching a ‘then’ or ‘else’.
Return non-nil if found; otherwise report a user error."
  ;; Must skip groups, blocks and brackets.  Also search for invalid
  ;; tokens such as ‘begin’ so as to detect a missing ‘if’ ASAP.
  (let ((pattern
         "\\_<\\(?:\\(if\\)\\|\\(else\\)\\|\\(end\\)\\|begin\\)\\_>\
\\|\\(>>\\)\\|\\(\\s\)\\)\\|<<\\|\\s\(\\|[^!][\;$]"))
    (or (and
         (reduce--re-search-backward pattern)
         (cond
          ((match-end 1))               ; if – return t
          ((match-end 2)                ; else – nested conditional
           (reduce--find-matching-if)
           (reduce--find-matching-if))
          ((match-end 3)                ; end of block
           (reduce--backward-block)
           (reduce--find-matching-if))
          ((match-end 4)                ; end of group
           (reduce--backward-group)
           (reduce--find-matching-if))
          ((match-end 5)                  ; closing bracket
           (forward-char) (backward-list) ; skip balanced brackets
           (reduce--find-matching-if))))
        ;; Found begin, <<, opening bracket, terminator or beginning
        ;; of buffer, so...
        (user-error "Cannot find ‘if’ matching ‘then’ or ‘else’"))))

(defun reduce--calculate-indent-prev ()
  "Return indentation for current line based on previous lines.
The indentation depends only on *previous* non-blank line."
  ;; Should comments be ignored, esp. if they begin the line?
  ;; e.g. they may indicate a commented-out region!
  (cl-block nil
    (save-excursion
      (beginning-of-line)
      (when (bobp) (cl-return 0))       ; no previous line
      ;; Find previous line that is neither blank nor a comment
      ;; beginning in the first column (which may represent
      ;; commented-out code):
      (while (and (= (forward-line -1) 0)
                  (looking-at "%\\|[ \t\f]*$")) )
      (when (and (bobp) (looking-at "[ \t\f]*$"))
        (cl-return 0))                  ; no previous non-blank line
      (back-to-indentation)

      ;; Point is now at first text in the previous non-blank line.

      ;; If in comment then indent to its start:
      (when (looking-at "%\\|/\\*") ; immediately before % or /**/ comment
        (cl-return (current-column)))
      (let ((state (reduce--in-comment-statement-p))) ; in comment statement
        (when state
          (goto-char (car state))       ; start of comment
          (cl-return (current-column))))
      (let ((state (syntax-ppss)))      ; within /**/ comment after /*
        (when (nth 4 state)
          (goto-char (nth 8 state))     ; start of comment
          (cl-return (current-column))))

      (let ((previous-indentation (current-column))
            extra-indentation)
        ;; Skip any label:
        (when (looking-at "^\\(\\w+[ \t]*:\\)[^=]") ; label
          (goto-char (match-end 1))
          (skip-chars-forward "[ \t]")
          (if (eolp)                    ; label alone on line
              (setq extra-indentation reduce-indentation)
            (setq previous-indentation (current-column))))

        ;; Point is now at start of statement text in the previous
        ;; non-blank line.

        (when (looking-at
               "#\\_<\\(?:define\\|if\\|elif\\|else\\|endif\\)\\_>")
          (cl-return (current-indentation)))

        (unless extra-indentation
          (setq extra-indentation
                (cond
                 ;; *** Tokens at beginning of the line ***
                 ;; ((looking-at "\\w+[ \t]*:[^=]") ; label
                 ;;  (if (looking-at ".*\\<if\\>") ; what else?
                 ;;      (* 2 reduce-indentation)
                 ;;    reduce-indentation))
                 ;; *** Tokens anywhere in the line ***
                 ((or (reduce--looking-at-procedure)
                      (and (looking-at ".*\\<begin\\>")
                           (not (looking-at ".*\\<end\\>")))
                      (and (looking-at ".*<<") (not (looking-at ".*>>"))))
                  (if (looking-at ".*,[ \t]*[%\n]") ; line ends with ,
                      (* 2 reduce-indentation)
                    reduce-indentation))
                 ;; *** Tokens at the end of the (logical) line *** :
                 ((looking-at ".*\\<\\(?:if\\|for\\|do\\|collect\\|join\\|sum\\product\\)\\>[ \t]*[%\n]")
                  reduce-indentation)
                 ;; Otherwise, extra indentation undefined
                 )))

        ;; Point is still at start of statement text in the *previous*
        ;; non-blank line.

        (cond
         ;; If extra indentation determined then use it ...
         (extra-indentation (+ previous-indentation extra-indentation))
         ;; Indent successive lines of a comma-separated sequence by
         ;; the same amount if both previous lines end with , :
         ((and (looking-at ".*,\\s-*[%\n]")
               (looking-back ",\\s-*[%\n]\\s-*" nil))
          (current-indentation))
         ;; Indent successive continuation lines of a multi-line
         ;; expression, where this line ends or the next line (that
         ;; being indented) begins with a simple operator, by the same
         ;; amount.  Now looking at *previous* line.  (Beware:
         ;; incomplete comment support!)
         ((and (or (looking-at ".*[=*/+-]\\s-*[%\n]") ; - must be at end of []!
                   (looking-at ".*\n\\s-*[=*/+-]"))
               ;; and this is not the first line
               (save-excursion
                 (reduce--skip-comments-backward)
                 (not (looking-back "[;$]" nil))))
          (current-indentation))
         ;; If beginning new statement or comma-separated element
         ;; then indent to previous statement or element
         ;; unless it is a first argument ...
         ((reduce--calculate-indent-prev1))
         ;; This produces very odd results if the group is preceded by indented code:
         ;; ((and (looking-at ".*<<") (not (looking-at ".*>>")))
         ;;  (reduce-backward-statement 1)
         ;;  (back-to-indentation)
         ;;  (+ (current-column) reduce-indentation))
         ;; ;; If continuing ‘if’ then indent relative to the ‘if’ ...
         ;; ((looking-at ".*\\(\\<then\\>\\|\\<else\\>\\)[ \t]*[%\n]")
         ;;  (if (looking-at ".*\\<if\\>")
         ;;  ()
         ;;    (goto-char (match-beginning 1))
         ;;    (reduce--find-matching-if))
         ;;  (+ (current-indentation) reduce-indentation))
         ;; ;; ... but the ‘if’ must be embedded ...
         ((looking-at ".+\\<if\\>.*\\(\\<then\\>\\|\\<else\\>\\)[ \t]*[%\n]")
          (goto-char (match-beginning 1))
          (reduce--find-matching-if)
          (+ (current-indentation) reduce-indentation))
         ;; Otherwise continuing previous line, so ...
         (t (+ previous-indentation reduce-indentation)))))))

(defun reduce--calculate-indent-prev1 ()
  "Sub-function of ‘reduce--calculate-indent-prev’.
If beginning new statement or continuing comma-separated sequence
or sub-expression ending with ‘+’, ‘-’, ‘or’ or ‘and’ then indent
to previous statement or element unless it is the first element."
  ;; Point now at start of previous non-blank line.
  (when (looking-at
         ".*\\(?:\\([,+-]\\|\\_<\\(?:or\\|and\\)\\_>\\)\\|[\;$]\\)[ \t]*[%\n]")
    (let* ((not-first-el (match-end 1))
           (open (or not-first-el ; not end of block, group or statement
                     (not (looking-at
                           ".*\\(?:\\_<end\\_>\\|>>\\)[\;$][ \t]*[%\n]")))))
      (end-of-line)
      (reduce-backward-statement 1)
      (when not-first-el
        (setq not-first-el
              (save-excursion
                (reduce--re-search-backward "[^ \t\f\n]")
                (not (looking-at "\\(,\\|\\s(\\)[ \t]*[%\n]")))))
      (back-to-indentation)
      (if (or not-first-el
              (and open
                   (looking-at
                    ;; ... procedure, begin, <<, label
                    ".*\\<procedure\\>\
\\|\\<begin\\>\\|<<\
\\|\\w+[ \t]*:[^=]"))                           ; ???
              (looking-at "\\w+[ \t]*:[^=]"))   ; label
          (+ (current-indentation) reduce-indentation)
        (current-indentation)))))

(defun reduce-indent-line-always (arg)
  "Indent current line; with ARG indent whole statement rigidly.
Add ‘reduce-indentation’ spaces at the beginning of the line.
With any argument, indent any additional lines of the same
statement rigidly along with this one."
  (interactive "*P")                    ; error if buffer read-only
  (let ((start-marker (point-marker)))
    (set-marker-insertion-type start-marker t)
    (indent-rigidly
     (1- (line-beginning-position))     ; to include first line
     (if arg
         (reduce-forward-statement 1)
       (line-end-position))
     reduce-indentation)
    (goto-char start-marker)
    (set-marker start-marker nil)))

(defun reduce-unindent-line (arg)
  "Unindent current line; with ARG unindent whole statement rigidly.
Delete ‘reduce-indentation’ spaces from the beginning of the
line.  With any argument, unindent any additional lines of the
same statement rigidly along with this one."
  (interactive "*P")                    ; error if buffer read-only
  (let ((start-marker (point-marker))
        (indentation (progn (back-to-indentation) (current-indentation))))
    ;; Point now at first non-blank character of current line.
    (unless (bolp)
      (backward-delete-char-untabify reduce-indentation)
      (when arg
        (progn
          (setq indentation (- (current-column) indentation))
          (indent-rigidly
           (point) (reduce-forward-statement 1) indentation)))
      (goto-char start-marker)
      (set-marker start-marker nil))))

(defun reduce-comment-indent ()
  "Return indent for %-comment depending on number of % characters.
Assigned to ‘comment-indent-function’."
  ;; Called only by indent-for-comment and (hence)
  ;; indent-new-comment-line.
  (cond ((looking-at "%%%") (current-column))
        ((looking-at "%%") (reduce--calculate-indent))
        (t (skip-chars-backward " \t")
           ;; (bolp) needed by indent-new-comment-line:
           (max (if (bolp) 0 (1+ (current-column))) comment-column))))

(defun reduce-indent-procedure (arg)
  "Indent the procedure ending after point.
With positive ARG, indent that many procedures ending after point.
Put mark at the first non-blank character or next line after the
ARGth end of procedure after point.  If this fails, do not indent
anything and report a user error.  Leave point at the start of
the first procedure before any preceding blank lines."
  (interactive "*p")                    ; error if buffer read-only
  (save-excursion
    (reduce-mark-procedure arg)
    (reduce-indent-region (point) (mark))
    (deactivate-mark)))

(defun reduce-indent-region (beg-region end-region)
  "Interactively indent region; otherwise BEG-REGION to END-REGION.
Interactively with prefix arg, indent the whole buffer."
  (interactive
   (if current-prefix-arg
       (list (point-min) (point-max))
     (list (region-beginning) (region-end))))
  (barf-if-buffer-read-only)
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
      ;; Strip trailing white space from lines:
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

;; This section updated 27 September 2022.

(defconst reduce--proc-kwd-regexp
  "\\_<\\(?:\\(?:matrix\\|list\\)?proc\\(?:edure\\)?\\)\\_>"
  "Regexp that matches “procedure”, “matrixproc” or “listproc”.")

(defun reduce-forward-procedure (arg)
  "Move forwards to the end of the procedure ending after point.
With positive ARG, do it ARG times.  If this fails, move forwards
by as many complete procedures as possible and report a user
error.  Skip to the first following non-blank character or the
next line."
  (interactive "p")
  (let ((case-fold-search t) (start (point)) found)
    ;; Move to the end of the procedure starting before point, which
    ;; might be within the procedure keyword:
    (skip-syntax-backward "w")
    (when (or (looking-at reduce--proc-kwd-regexp)
              ;; Now search BACKWARDS for procedure keyword:
              (reduce--re-search-backward reduce--proc-kwd-regexp))
      (reduce-forward-statement 2))
    ;; If point has moved forwards then it is now at the end of the
    ;; procedure it was within, so move forwards by another arg-1
    ;; procedures; otherwise point was not in a procedure, so move
    ;; forwards by arg procedures.
    (if (> (point) start)
        (setq arg (1- arg) found t)
      (goto-char start))                ; don't move backwards!
    (while (and (> arg 0) (reduce--re-search-forward reduce--proc-kwd-regexp))
      (reduce-forward-statement 2)
      (setq arg (1- arg) found t))
    (when found
      ;; Skip white space and any following eol:
      (skip-chars-forward " \t")
      (if (eolp) (forward-char))))
  (unless (zerop arg)
    (user-error "Next end of procedure not found")))

(defconst reduce--proc-type-regexp
  "\\(?:\\(?:algebraic\\|integer\\|real\\|\
symbolic\\|lisp\\|inline\\|s?macro\\|expr\\)[ \t\n]+\\)"
  "Regexp that matches any single possible procedural type followed
by white space.")

(defun reduce-backward-procedure (arg)
  "Move backwards to the start of the procedure starting before point.
With positive ARG, do it ARG times.  If this fails, move
backwards by as many complete procedures as possible and report a
user error.  Skip to the start of any procedural types."
  (interactive "p")
  ;; Move to the start of the procedure starting before point.  This
  ;; heuristic allows point to be within the procedure keyword or
  ;; procedural types, which might be on different lines.  First,
  ;; check point is not in a string or syntactic comment:
  (let ((case-fold-search t))
    (unless (reduce--in-string-or-comment-p)
      (let ((start (point)) (tries 0) (max-tries 3)
            (regexp (concat reduce--proc-type-regexp "*"
                            reduce--proc-kwd-regexp)))
        (while (and (< tries max-tries) (not (looking-at regexp)))
          (skip-syntax-backward "-") (skip-syntax-backward "w")
          (setq tries (1+ tries)))
        (if (and (> tries 0) (< tries max-tries)) ; procedure header found?
            (setq arg (1- arg))
          (goto-char start))))
    ;; Search backwards arg times for procedure keyword:
    (while (and (> arg 0)
                (reduce--re-search-backward reduce--proc-kwd-regexp))
      (setq arg (1- arg)))
    ;; Skip any preceding procedural types:
    (let ((regexp (concat reduce--proc-type-regexp "\\=")))
      (while (re-search-backward regexp nil t)))
    (unless (zerop arg)
      (user-error "Previous start of procedure not found"))))

(defun reduce-mark-procedure (arg)
  "Mark the procedure ending after point.
With positive ARG, mark that many procedures ending after point.
Put mark at the first non-blank character or next line after the
ARGth end of procedure after point.  If this fails, do not mark
anything and report a user error.  Leave point at the start of
the first procedure before any preceding blank lines."
  (interactive "p")
  ;; Region must stay active, even if transient-mark-mode is on:
  (let (transient-mark-mode next)
    (reduce-forward-procedure 1)
    (if (eq arg 1)
        (push-mark)                     ; mark end of procedure
      (setq next (point)))
    (reduce-backward-procedure 1)
    (skip-chars-backward " \t\f\n") (forward-char)
    (if (> arg 1)
        (save-excursion                 ; leave point here
          (goto-char next)
          (reduce-forward-procedure (1- arg))
          (push-mark)))))               ; mark end of ARG procedures

(defun reduce-kill-procedure (arg)
  "Kill the procedure ending after point.
With positive ARG, kill that many procedures ending after point,
including any preceding blank lines.  If this fails, do not kill
anything and report a user error."
  (interactive "*p")                    ; error if buffer read-only
  (reduce-mark-procedure arg)
  (kill-region (region-beginning) (region-end)))

(defun reduce-narrow-to-procedure (arg)
  "Narrow to the procedure ending after point.
In other words, make all text outside this procedure invisible.
With positive ARG, include that many procedures ending after
point.  Also include any preceding blank lines.  If narrowing
fails, report a user error."
  ;; Based on ‘narrow-to-defun’ in ‘lisp.el’.
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
With ARG, move that many times.  Ignore (skip) comment
statements.  If looking at the end of a block or group, or the
end-of-file marker, move over it after ‘reduce-max-escape-tries’
consecutive interactive tries.  Return point or report a user
error if unsuccessful."
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
    (if (< (point) start)
        (goto-char start)
      (point))))

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
The end-of-file marker is treated as a statement.  Return the
count of statements left to move, which is used by
‘reduce--calculate-indent-proc’.  Report a user error if
unsuccessful."
  ;; *** No longer used by ‘reduce--calculate-indent-proc’! ***
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
That is, move backwards to the beginning of the “begin” or “<<”
at the start of the block or group containing point.  A universal
argument means move forwards to the end of the “end” or “>>” at
the end of the block or group containing point.  Throw an error
if the move fails.  With a numeric argument, do it that many
times, where a negative argument means move forwards instead of
backwards."
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
That is, move forwards to the end of the nearest “begin” or “<<”
within the current block or group, if any.  A universal argument
means move backwards to the beginning of the nearest “end” or
“>>” within the current block or group, if any.  Throw an error
if the move fails.  With a numeric argument, do it that many
times, where a negative argument means move backwards instead of
forward."
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


;;;; ***********************************
;;;; Balanced expression (sexp) commands
;;;; ***********************************

(defun reduce-forward-sexp ()
  "Move forwards across one balanced expression (sexp).
“Balanced expression” means a symbol, string, bracketed
expression, block or group.  A symbol or bracketed expression may
be quoted.  Skip any preceding comments or white space.  This
command assumes point is not in a string or comment.  It is
modelled loosely on ‘forward-sexp’.  If the move succeeds then
return ‘point’; otherwise throw a user error."
  (interactive)
  (let ((case-fold-search t) (start (point)))
    (condition-case nil                 ; to catch scan errors
        (progn
          (reduce--skip-comments-forward)
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
           (t (user-error ""))))
      (t (reduce--move-error start "next"))))
  (point))

(defun reduce-backward-sexp ()
  "Move backwards across one balanced expression (sexp).
“Balanced expression” means a symbol, string, bracketed
expression, block or group.  A symbol or bracketed expression may
be quoted.  Skip any following comments or white space.  This
command assumes point is not in a string or comment.  It is
modelled loosely on ‘backward-sexp’.  If the move succeeds then
return ‘point’; otherwise throw a user error."
  (interactive)
  (let ((case-fold-search t) (start (point)))
    (condition-case nil                 ; to catch scan errors
        (progn
          (reduce--skip-comments-backward)
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
           (t (user-error ""))))
      (t (reduce--move-error start "previous"))))
  (point))

(defun reduce--move-error (start next-or-previous)
  "Move to START and throw an error appropriate to NEXT-OR-PREVIOUS."
  (goto-char start)
  (user-error "No %s “balanced expression”" next-or-previous))

(defun reduce-kill-sexp (&optional arg)
  "Kill the balanced expression (sexp) following point.
With any argument ARG, kill the balanced expression before point.
“Balanced expression” means a symbol, string, bracketed
expression, block or group.  A symbol or bracketed expression may
be quoted.  Also kill any comments or white space between point
and the balanced expression.  This command assumes point is not
in a string or comment.  It is modelled loosely on ‘kill-sexp’.
If unable to kill a balanced expression, throw a user error."
  (interactive "*P")                    ; error if buffer read-only
  (kill-region (point) (if arg
                           (reduce-backward-sexp)
                         (reduce-forward-sexp))))


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
    (let (first                          ; nil unless first line found
          fill-paragraph-handle-comment) ; don't!
      ;; If in empty line then move to start of next non-empty line:
      (beginning-of-line)
      (while (and (looking-at "\\s-*$")
                  (= (forward-line) 0)
                  (setq first (point))))
      (back-to-indentation)
      (cond
       ;; If point is in a %-comment then find its prefix and fill it:
       ((looking-at "%")
        ;; Code modified from ‘set-fill-prefix’ in fill.el.
        (let ((fill-prefix (buffer-substring-no-properties
                            (line-beginning-position)
                            (progn (skip-chars-forward " \t%") (point))))
              last)
          (when (equal fill-prefix "") (setq fill-prefix nil))
          ;; Find the last line of the comment:
          (while (and (= (forward-line) 0)
                      (looking-at "\\s-*%")))
          (setq last (point))
          ;; Move to the first line of the comment:
          (if first
              (goto-char first)
            (while (and (= (forward-line -1) 0)
                        (looking-at "\\s-*%")))
            ;; Might have reached BOB, so ...
            (unless (looking-at "\\s-*%") (forward-line)))
          ;; Fill region as one paragraph breaking lines to fit
          ;; fill-column:
          (fill-region-as-paragraph (point) last justify)))
       ;; If point is in a comment statement then use normal text-mode
       ;; fill, but only within the comment statement, which might be
       ;; within code:
       ((setq first (reduce--in-comment-statement-p))
        (save-restriction
          (narrow-to-region (car first) (cdr first))
          (fill-paragraph justify)))
       ;; Ditto for /**/ comment:
       ((or (looking-at "/\\*")         ; before /**/ comment
            (when                       ; within /**/ comment after /*
                (nth 4 (setq first (syntax-ppss)))
              (goto-char (nth 8 first)) t))
        (save-restriction
          (narrow-to-region (point)
                            (save-excursion (forward-comment 1) (point)))
          (fill-paragraph justify)))))))


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

(defun reduce-expand-if-then (&optional _arg)
  "Insert ‘if ... then’ and position point inside, ignoring ARG."
  (reduce-insert-if-then))

(defun reduce-expand-if-then-else (&optional _arg)
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
            (reduce-backward-sexp)
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

(defvar reduce--tagify-root)

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
  (require 'reduce-run)
  (warn "‘require-reduce-run’ is obsolete; \
please customize ‘autoload-reduce-run’ instead."))

(make-obsolete 'require-reduce-run
               "please customize ‘autoload-reduce-run’ instead."
               "REDUCE IDE v1.10")

(provide 'reduce-mode)

(when (eq autoload-reduce-run t) (require 'reduce-run))

(run-hooks 'reduce-mode-load-hook)

;;; reduce-mode.el ends here
