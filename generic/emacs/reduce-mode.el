;;; reduce-mode.el --- Major mode to edit REDUCE computer-algebra code

;; Copyright (C) 1998-2001, 2012, 2017, 2018 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Created: late 1992
;; Version: $Id$
;; Keywords: languages
;; Homepage: http://reduce-algebra.sourceforge.net/reduce-ide
;; Package-Version: 1.54

;; This file is not part of GNU Emacs.

;; This program is free software: you can redistribute it and/or
;; modify it under the terms of the GNU General Public License as
;; published by the Free Software Foundation, either version 3 of
;; the License, or (at your option) any later version.

;; This program is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with this program.  If not, see <http://www.gnu.org/licenses/>.

;; Contributions by Rainer Schoepf flagged ; RS
;; Schoepf@goofy.zdv.Uni-Mainz.DE

;; Contributions by Thomas Sturm flagged ; TS
;; sturm@redlog.eu

;;; Commentary:

;; REDUCE Mode is a major mode for editing source code for the REDUCE
;; computer algebra system, which is Open Source and available from
;; <https://sourceforge.net/projects/reduce-algebra>.

;; The latest version of REDUCE Mode is available from
;; <https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs>.

;; Full documentation covering the installation and use of REDUCE mode
;; is provided by a texinfo source file called `reduce-ide.texinfo'.
;; From this are (or can be) derived the info file `reduce-ide.info',
;; the HTML file `reduce-ide.html' and the PDF file `reduce-ide.pdf'.
;; The info file can be browsed using the independent info browsing
;; program called `info', or installed into the Emacs info browser.

;;; Usage:

;; To install in GNU Emacs 24+, download this file to any convenient
;; directory and run the Emacs command `package-install-file' on it.

;; Brief manual installation instructions follow.

;; Byte-compile this file, put it somewhere in your `load-path', and
;; put the following in your `.emacs' file:

;; (autoload 'reduce-mode "reduce-mode" "Major mode for REDUCE code editing" t)

;; To run REDUCE Mode automatically on files with extension ".red" or
;; ".tst" put the following (after `autoload') in your `.emacs' file:

;;;###autoload
(add-to-list 'auto-mode-alist '("\\.\\(red\\|tst\\)\\'" . reduce-mode))

;; To make REDUCE Mode customization always available put the
;; following (after `autoload') in your `.emacs' file:

;;;###autoload
(defgroup reduce nil
  "Support for editing and running REDUCE code."
  :tag "REDUCE" :group 'languages :load "reduce-mode")

;; To turn on only REDUCE font-lock mode by default include
;; (add-hook 'reduce-mode-hook 'turn-on-font-lock)
;; or to turn on all supported font-lock modes by default include
;; (global-font-lock-mode 1)

;;; To do:

;;	BUGS
;;	====
;;	! should not be an escape IN STRINGS (motion by sexp, font-lock)
;;	reduce-backward-statement does too much searching!

;;	Enhancements
;;	============
;;	more flexible intelligent indentation, rationalize the code
;;	make skipping comment statements configurable (?)
;;	add RLisp88 support (?)
;;	more structure templates (?) -- while, repeat
;;  faster font-lock (function rather than just regexps)?

;;; Code:

(defconst reduce-mode-version
  ;; Extract version from `package-version' in file header:
  (eval-when-compile
    (require 'lisp-mnt)
    (save-excursion (lm-header "package-version")))
  "Version information for REDUCE Mode.")

;; (message "Loading reduce-mode")	; TEMPORARY!

(eval-when-compile						; keep compiler happy!
  (require 'font-lock)
  (require 'timer))

;; Customizable user options:

(defgroup reduce nil
  "Support for editing and running REDUCE code."
  :tag "REDUCE"
  :group 'languages)

(defgroup reduce-interface nil
  "Interface options for editing and running REDUCE code."
  :tag "REDUCE Interface"
  :group 'reduce)

(defgroup reduce-format-display nil
  "Format and display options for editing and running REDUCE code."
  :tag "REDUCE Format & Display"
  :group 'reduce)

(defcustom reduce-mode-load-hook nil
  "*List of functions to be called when REDUCE mode is loaded.
E.g. `require-reduce-run' to automatically load `reduce-run'.
It can be used to customize global features of REDUCE mode such as its
key map, i.e. it is a good place to put keybindings."
  :type 'hook
  :options '(require-reduce-run)
  :group 'reduce)

(defcustom reduce-mode-hook nil
  "*List of functions to be called when REDUCE mode is entered.
E.g. `turn-on-font-lock' to turn on font-lock mode locally.
It can be used to customize buffer-local features of REDUCE mode."
  :type 'hook
  :options '(turn-on-font-lock)
  :group 'reduce)

;; Interface:

(defcustom reduce-imenu-generic-expression ; EXPERIMENTAL!
  '((nil "^\\([^%\n]+\\(ic\\|ro\\) \\)?\\s *procedure \\(\\w\\(\\w\\|\\s_\\|!.\\)*\\)" 3)
    ("Operators" "^\\([^%\n]+ic \\)?\\s *operator \\(\\w\\(\\w\\|\\s_\\|!.\\)*\\)" 2))
  "*Imenu support for procedure definitions and operator declarations.
An alist with elements of the form (MENU-TITLE REGEXP INDEX) --
see the documentation for `imenu-generic-expression'."
  :type '(repeat (list (choice (const nil) string) regexp integer))
  :group 'reduce-interface)

(defcustom reduce-imenu nil
  "*If non-nil REDUCE mode automatically calls `imenu-add-to-menubar'.
This adds a Contents menu to the menubar. Default is nil."
  :type 'boolean
  :group 'reduce-interface)

(defcustom reduce-imenu-title "Procs/Ops"
  "*The title to use if REDUCE mode adds a proc/op menu to the menubar.
Default is \"Procs/Ops\"."
  :type 'string
  :group 'reduce-interface)

(defcustom reduce-max-up-tries 2
  "*Repeats of reduce-forward/backward-statement to move up block or group."
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
  "Alist of REDUCE symbols to be completed by `reduce-complete-symbol'.
Optional `cdr' is a replacement string or nullary function (for structures)."
  :type '(repeat (cons string (choice (const nil) string function)))
  :group 'reduce-interface)

;; Formatting:

(defcustom reduce-indentation 3
  "*Depth of successive indentations in REDUCE code."
  :type 'integer
  :group 'reduce-format-display)

(defcustom reduce-indent-line-conservative nil ; TS
  "*If non-nil, `reduce-indent-line' will not successively indent."
  :type 'boolean
  :group 'reduce-format-display)

(defcustom reduce-comment-region-string "%% "
  "*String inserted by \\[reduce-comment-region] at start of each line."
  :version "1.21" ; Name was reduce-comment-region up to version 1555!
  :type 'string
  :group 'reduce-format-display)

(defcustom reduce-auto-indent-mode t
  "*If non-nil then conditionally re-indent the current line.
This will happen after `reduce-auto-indent-delay' seconds of idle
time if the text just typed matches `reduce-auto-indent-regex'."
  :set (lambda (symbol value)
	 (reduce-auto-indent-mode (or value 0)))
  :initialize 'custom-initialize-default
  :type 'boolean
  :group 'reduce-format-display)

(defcustom reduce-auto-indent-delay 0.125
  "*Time in seconds to delay before maybe re-indenting current line."
  :type 'number
  :group 'reduce-format-display)

(defcustom reduce-auto-indent-regexp "\\(else\\|end\\|>>\\)\\="
  "*Auto indent current line if text just typed matches this regexp.
It should end with \\=\\=.  The default value is \"\\(else\\|end\\|>>\\)\\=\\=\"."
  :type 'regexp
  :group 'reduce-format-display)

;; Display:

(defcustom reduce-show-delim-mode-on show-paren-mode
  "If non-nil then turn on `reduce-show-delim-mode' initially.
Since `reduce-show-delim-mode' is a buffer-local minor mode, it
can also be turned on and off in each buffer independently.
Defaults to the value of `show-paren-mode'."
  :package-version '(reduce-mode . "1.54")
  :type 'boolean
  :group 'reduce-format-display)

(defcustom reduce-show-proc-mode nil
  "*If non-nil then display current procedure name in mode line.
Update after `reduce-show-proc-delay' seconds of Emacs idle time."
  :set (lambda (symbol value)
	 (reduce-show-proc-mode (or value 0)))
  :initialize 'custom-initialize-default
  :type 'boolean
  :group 'reduce-format-display)

(defcustom reduce-show-proc-delay 0.125
  "*Time in seconds to delay before showing the current procedure name."
  :type 'number
  :group 'reduce-format-display)

;; External variables:

;; Due to improvements of byte compilation around 2003 the compiler
;; would complain about `make-local-var' on these later on. I left
;; unchanged another (too late) declaration for `which-func-mode' below,
;; which appears not to disturb. TS

(defvar which-func-mode)
(defvar which-func-format)
(defvar imenu-space-replacement)

;; Internal variables:

(defvar reduce-imenu-done nil
  "Buffer-local: set to true if `reduce-imenu-add-to-menubar' has been called.")
(make-variable-buffer-local 'reduce-imenu-done)

(defvar reduce-mode-map nil
  "Keymap for REDUCE mode.")

(defvar reduce-mode-syntax-table nil
  "Syntax table for REDUCE mode.")

(defconst reduce-font-lock-keywords
  '(
    reduce-font-lock-keywords-0		; Default = nil
    reduce-font-lock-keywords-1		; Algebraic
    reduce-font-lock-keywords-2		; Symbolic
    reduce-font-lock-keywords-3		; Full = t
    )
  "A list of symbols corresponding to increasing fontification.
Each is assigned a `font-lock-keywords' value for REDUCE mode.")

(defconst reduce-font-lock-syntactic-keywords
  ;; ((MATCHER SUBEXP SYNTAX OVERRIDE LAXMATCH) ... )
  ;; where SYNTAX = (SYNTAX-CODE . MATCHING-CHAR)
  ;;   If this proves unreliable, try
  ;;    '(("\".*\\(!\\)\"" 1 (1 . nil)))
  ;;   i.e. only mark ! at end of a string as punctuation.
  ;;   But this may be slow!
  '(("[^'\(]\\(!\\)\"" 1 (1 . nil)))
  "Mark ! followed by \" as having punctuation syntax (syntax-code 1)
unless preceded by ' or (, for correct syntax highlighing of strings.")


;;;; *****************
;;;; REDUCE major mode
;;;; *****************

;;; Automatically pre-define reduce mode to autoload if available
;;; when building Emacs (unlikely ever to be done!):

;;;###autoload
(defun reduce-mode ()
  "Major mode for editing REDUCE source code -- part of REDUCE IDE.
Author: Francis Wright <http://sourceforge.net/users/fjwright>
Version: see `reduce-mode-version'
Comments, suggestions, bug reports, etc. are welcome.
Full texinfo documentation is provided in the file `reduce-ide.texinfo'.

Commands are aware of REDUCE syntax, and syntax-directed commands
ignore comments, strings and character case.  Standard indentation and
comment commands are supported.  Modelled primarily on Lisp mode;
comment commands follow Lisp conventions.

`<< ... >>' and `begin ... end' are treated as bracketed or
``symbolic'' expressions for motion, delimiter matching, etc.

The command `reduce-indent-line' (`\\[reduce-indent-line]') indents in a fixed style (mine!).
If re-run immediately after itself or `reindent-then-newline-and-indent'
\(`\\[reindent-then-newline-and-indent]') or `newline-and-indent' (`\\[newline-and-indent]') it indents further.
The indentation increment is the value of the variable `reduce-indentation'.

Structure template commands are provided to insert and indent
if-then (`\\[reduce-insert-if-then]'), block (`\\[reduce-insert-block]') and group (`\\[reduce-insert-group]') constructs,
the latter optionally on a single line.

The command `reduce-complete-symbol' (`\\[reduce-complete-symbol]') performs REDUCE
keyword/phrase/structure completion.

Text highlighting is supported via the command `font-lock-mode', and
the style of highlighting may be controlled by setting
`font-lock-maximum-decoration' to one of:

  1, nil : basic keyword highlighting -- the default;
  2      : algebraic-mode highlighting;
  3      : symbolic-mode highlighting;
  4, t   : full highlighting -- of almost everything!

Highlighting may also be controlled using the REDUCE menu.

Delete converts tabs to spaces as it moves back.
Blank lines separate paragraphs.  Percent signs start comments.
REDUCE mode defines the following local key bindings:

\\{reduce-mode-map}
Entry to this mode calls the value of `reduce-mode-hook' if non-nil."
  (interactive)
  (kill-all-local-variables)
  (use-local-map reduce-mode-map)
  (setq major-mode 'reduce-mode)
  (setq mode-name "REDUCE")
  (reduce-mode-variables)
  ;; Set up font-lock mode - variables automatically buffer-local:
  (setq font-lock-defaults
       ;; reduce-font-lock-keywords evaluates to a list of symbols!
       (list reduce-font-lock-keywords	; KEYWORDS
	     nil   			; KEYWORDS-ONLY
	     t				; CASE-FOLD
	     nil			; SYNTAX-ALIST
	     (cons			; (VARIABLE . VALUE) ...
	      'font-lock-syntactic-keywords	; obsolete since 24.1! Use
										; syntax-propertize-function
										; instead!
	      reduce-font-lock-syntactic-keywords)
	     ))
  (setq font-lock-multiline t)			; for comment statements
  ;; Additional support for comment statements:
  (add-to-list 'font-lock-extend-region-functions
			   #'reduce-font-lock-extend-region-for-comment)
  ;; Make all parsing respect the syntax property set by the above
  ;; font-lock option (which is essential to parse "...!"):
  (set (make-local-variable 'parse-sexp-lookup-properties) t)
  ;; Optionally turn on REDUCE minor modes:
  (when reduce-show-delim-mode-on
	(require 'reduce-delim)
	(funcall 'reduce-show-delim-mode))
  (if reduce-auto-indent-mode (reduce-auto-indent-mode t))
  ;; For reduce-show-proc-mode:
  (set (make-local-variable 'which-func-mode) nil)
  (set (make-local-variable 'which-func-format) 'reduce-show-proc-string)
  (if reduce-show-proc-mode (reduce-show-proc-mode t))
  ;; This seems to be obsolete in Emacs 26!
  ;; Experimental support for outline minor mode (cf. lisp-mode.el)
  ;; `outline-regexp' must match `heading' from beginning of line;
  ;; length of match determines level:
  ;; (set (make-local-variable 'outline-regexp) "[^ \t\n]")
  ;; Imenu support:
  (set (make-local-variable 'imenu-generic-expression)
       ;; `make-local-variable' in case imenu not yet loaded!
       reduce-imenu-generic-expression)
  (set (make-local-variable 'imenu-space-replacement) " ")
  ;; Necessary to avoid re-installing the same imenu:
  (setq reduce-imenu-done nil)
  (if reduce-imenu (reduce-imenu-add-to-menubar))
  ;; ChangeLog support:
  (set (make-local-variable 'add-log-current-defun-function)
       'reduce-current-proc)
  (run-hooks 'reduce-mode-hook))

(defun reduce-mode-variables ()
  "Define REDUCE mode local variables."
  (set-syntax-table reduce-mode-syntax-table)
  ;; (set (make-local-variable 'paragraph-start)
  ;;      (concat "^$\\|" page-delimiter))
  (set (make-local-variable 'paragraph-separate)
       ;; paragraph-start)
       (concat paragraph-start "\\|^%")) ; RS
  ;; so that comments at beginning of a line do not disturb reformatting.
  (set (make-local-variable 'paragraph-ignore-fill-prefix) t)
  (set (make-local-variable 'indent-line-function) 'reduce-indent-line)
  (set (make-local-variable 'comment-start) "% ")
  (set (make-local-variable 'comment-start-skip)
       "\\(^\\|[^!]\\)%+ *")		; "%+ *" but not !%
  (set (make-local-variable 'comment-column) 40)
  (set (make-local-variable 'comment-indent-function)
       'reduce-comment-indent)
  ;; (setq fill-prefix "% ")		; buffer local
  (set (make-local-variable 'parse-sexp-ignore-comments) t) ; RS
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


;;;; **********************
;;;; Keyboard and menu maps
;;;; **********************

(if reduce-mode-map ()
  (let ((map (make-sparse-keymap)))
    ;; (define-key map ">" 'reduce-self-insert-and-blink-matching-group-open)
    ;; (define-key map "\t" 'reduce-indent-line)
    (define-key map "\n" 'reindent-then-newline-and-indent)
    (define-key map "\C-c\t" 'reduce-unindent-line) ; default
    (define-key map [(shift tab)] 'reduce-unindent-line) ; backtab
    (define-key map "\177" 'backward-delete-char-untabify) ; DEL
    (define-key map "\C-c\C-n" 'reduce-forward-statement)
    (define-key map "\C-c\C-p" 'reduce-backward-statement)
    (define-key map "\C-c\C-d" 'reduce-down-block-or-group)
    (define-key map "\C-c\C-u" 'reduce-up-block-or-group)
    (define-key map "\C-c\C-k" 'reduce-kill-statement)
    (define-key map "\e\C-f" 'reduce-forward-sexp)
    (define-key map "\e\C-b" 'reduce-backward-sexp)
    (define-key map "\e\C-e" 'reduce-forward-procedure)
    (define-key map "\e\C-a" 'reduce-backward-procedure)
    (define-key map "\e\C-h" 'reduce-mark-procedure)
    (define-key map "\C-xnd" 'reduce-narrow-to-procedure)
    (define-key map "\C-ck" 'reduce-kill-procedure)
    ;; (define-key map "\e;" 'reduce-indent-comment) ; via global map
    (define-key map "\e\C-\\" 'reduce-indent-region)
    (define-key map "\e\C-q" 'reduce-indent-procedure)
    (define-key map "\C-c;" 'reduce-comment-region)
    (define-key map "\C-c:" 'reduce-comment-procedure)
    (define-key map "\eq" 'reduce-fill-comment)
    (define-key map "\C-ci" 'reduce-insert-if-then)
    (define-key map "\C-cb" 'reduce-insert-block)
    (define-key map "\C-c<" 'reduce-insert-group)
    (define-key map "\e\C-l" 'reduce-reposition-window)
    (define-key map "\e\t" 'reduce-complete-symbol)
    (setq reduce-mode-map map)))

;; REDUCE-mode menu bar and pop-up menu
(easy-menu-define			; (symbol maps doc menu)
 reduce-mode-menu
 reduce-mode-map
 "REDUCE Mode Menu"
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
     :help "Tag all REDUCE files in this directory"]
    ["Tag Subdirs..." reduce-tagify-subdirs :active t
     :help "Tag all REDUCE files in sub-directories of `..'"]
    )
   ;;   "-- TEMPLATES --" ; not good in ntemacs
   "--"
   ["Insert If-Then" reduce-insert-if-then :active t
    :help "Insert an `if-then' template"]
   ["Insert Block" reduce-insert-block :active t
    :help "Insert a `block' template"]
   ["Insert Group" reduce-insert-group :active t
    :help "Insert a `group' template"]
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
  "Echo version information for REDUCE Major Mode."
  (interactive)
  (message "REDUCE Major Mode version: %s" reduce-mode-version))


;;;; ************
;;;; Syntax table
;;;; ************

(if reduce-mode-syntax-table ()
  (let ((table (make-syntax-table)))
    (modify-syntax-entry ?_ "_" table)
    ;; (modify-syntax-entry ?! "\\" table)
    (modify-syntax-entry ?! "/" table)	; single character quote
    (modify-syntax-entry ?\\ "." table)
    (modify-syntax-entry ?{ "(}" table)
    (modify-syntax-entry ?} "){" table)
    (modify-syntax-entry ?\( "()" table)
    (modify-syntax-entry ?\) ")(" table)
    (modify-syntax-entry ?\[ "(]" table)
    (modify-syntax-entry ?\] ")[" table)
    (modify-syntax-entry ?< "." table)
    (modify-syntax-entry ?> "." table)
    (modify-syntax-entry ?* "." table)
    (modify-syntax-entry ?/ "." table)
    (modify-syntax-entry ?+ "." table)
    (modify-syntax-entry ?- "." table)
    (modify-syntax-entry ?= "." table)
    (modify-syntax-entry ?% "<" table)
    (modify-syntax-entry ?\n ">" table)
    (modify-syntax-entry ?& "." table)
    (modify-syntax-entry ?| "." table)
    (modify-syntax-entry ?' "'" table)
    (modify-syntax-entry ?\" "\"" table)
    (modify-syntax-entry ?$ "." table)	; RS
    (setq reduce-mode-syntax-table table))
  )


;;;; ********************
;;;; Indentation commands
;;;; ********************

(defun reduce-indent-line (&optional arg)
  "Indent current line; if ARG indent whole statement rigidly.
Indents to fixed style determined by current and previous non-blank line.
Subsequent consecutive calls indent additionally by `reduce-indentation'
unless `reduce-indent-line-conservative' is non-nil. With argument,
indent any additional lines of the same statement rigidly together with
this one."
  (interactive "*P")			; error if buffer read-only
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
For an opening token (`begin' or `<<') normally return the indentation of
the previous non-blank line; for an intermediate token (`then' or `else')
return the indentation of the beginning of the statement; for a
closing token (`end' or `>>') return the indentation of the beginning
of the construct; otherwise return nil."
  (save-excursion
    (back-to-indentation)
    (cond
     ;; *** Opening tokens *** :
     ((looking-at "[({ \t]*\\(\\<begin\\>\\|<<\\)")
      ;; Find previous non-blank line:
      (let ((closed (looking-at ".*\\(\\<end\\>\\|>>\\)")))
	(skip-syntax-backward " >")	; whitespace, endcomment
	(if (looking-at "[;$]")
	    (reduce-backward-statement 1)
	  (back-to-indentation))
	(if (or (looking-at-procedure)
		(and
		 (or closed		; single-line construct
		     (looking-at "\\w+[ \t]*:=")) ; assignment
		 (not (looking-at ".*[;$]")))) ; not completed
	    (+ (current-column) reduce-indentation)
	  (current-column))
	))
     ((looking-at "\\w+[ \t]*:[^=]")	; label
      ;; Indent to beginning of enclosing block:
      (reduce-backward-block) (current-column))
     ;; *** Intermediate tokens *** :
     ((looking-at "\\<then\\>\\|\\<else\\>")
      (reduce-find-matching-if) (current-indentation))
     ;; *** Closing tokens *** :
     ((looking-at "\\<end\\>")
      (reduce-backward-block) (current-indentation))
     ((looking-at ">>")
      (reduce-backward-group) (current-indentation))
     ;; ((looking-at "#\\<endif\\>")
     ;;  (reduce-backward-group) 0)
     ((looking-at "#\\(\\<define\\>\\|\\<if\\>\\|\\<\\elif\\>\\|\\<\\else\\>\\|\\<endif\\>\\)")
      0))))

(defun reduce-find-matching-if ()
  "Find the `if' matching a `then' or `else'."
  ;; Must skip groups, blocks and brackets.
  ;; Detects a missing `if' as early as possible as an unrecoverable error.
  (let ((pattern "\\<\\(if\\|else\\|end\\|begin\\)\\>\\|>>\\|\\s)\\|<<\\|\\s(\\|[^!][;$]"))
    (or (and
	 (reduce-re-search-backward pattern)
	 (cond
	  ((looking-at "if"))		; found it -- return t
	  ((looking-at "else")		; nested conditional
	   (reduce-find-matching-if) (reduce-find-matching-if))
	  ((= (following-char) ?>)	; end of group
	   (reduce-backward-group) (reduce-find-matching-if))
	  ((looking-at "end")		; end of block
	   (reduce-backward-block) (reduce-find-matching-if))
	  ((= (char-syntax (following-char)) ?\) )
	   (forward-char) (backward-list) ; skip balanced brackets
	   (reduce-find-matching-if))))
	;; begin, <<, opening bracket, `;', `$' or beginning of buffer
	(error "`if' matching `then' or `else' not found"))
    ))


(defun reduce-calculate-indent-prev ()
  "Return indentation based on previous non-blank line."
  ;; Should comments be ignored, esp. if they begin the line?
  ;; e.g. they may indicate a commented-out region!
  (save-excursion
    (beginning-of-line)
    (if (bobp)
	0				; no previous line
      ;; Find previous line that is neither blank nor a comment
      ;; beginning in the first column (which may represent
      ;; commented-out code):
      (while (and (= (forward-line -1) 0)
		  (looking-at "%\\|[ \t\f]*$")) )
      (if (and (bobp) (looking-at "[ \t\f]*$"))
	  0				; no previous non-blank line
	(back-to-indentation)
	;; Point is now at first text in the previous non-blank line.
	(let ((previous-indentation (current-column))
	      extra-indentation)
	  ;; Skip any label:
	  (when (looking-at "^\\(\\w+[ \t]*:\\)[^=]") ; label
	    (goto-char (match-end 1))
	    (skip-chars-forward "[ \t]")
	    (if (eolp)		; label alone on line
		(setq extra-indentation reduce-indentation)
	      (setq previous-indentation (current-column))))
	  ;; Point is now at start of statement text in the previous
	  ;; non-blank line.
	  (or extra-indentation
	      (setq extra-indentation
		    (cond
		     ;; *** Tokens at beginning of the line *** :
		     ((looking-at "%") 0)	; % comment (HANDLE THIS FIRST!)
     ;  		((looking-at "\\w+[ \t]*:[^=]") ; label
     ;  		 (if (looking-at ".*\\<if\\>") ; what else?
     ;  		     (* 2 reduce-indentation)
     ;  		   reduce-indentation))
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
;	   ((and (looking-at ".*<<") (not (looking-at ".*>>")))
;	    (reduce-backward-statement 1)
;	    (back-to-indentation)
;	    (+ (current-column) reduce-indentation))
	   ;; If continuing `if' then indent relative to the `if' ...
;  	   ((looking-at ".*\\(\\<then\\>\\|\\<else\\>\\)[ \t]*[%\n]")
;  	    (if (looking-at ".*\\<if\\>")
;  		()
;  	      (goto-char (match-beginning 1))
;  	      (reduce-find-matching-if))
;  	    (+ (current-indentation) reduce-indentation))
	   ;; ... but the `if' must be embedded ...
	   ((looking-at ".+\\<if\\>.*\\(\\<then\\>\\|\\<else\\>\\)[ \t]*[%\n]")
	    (goto-char (match-beginning 1))
	    (reduce-find-matching-if)
	    (+ (current-indentation) reduce-indentation))
	   ;; Otherwise continuing previous line, so ...
	   (t (+ previous-indentation reduce-indentation))
	   ))))))

(defun reduce-calculate-indent-prev1 ()
  "Sub-function of `reduce-calculate-indent-prev'.
If beginning new statement or comma-separated element or
sub-expression ending with `+', `-', `or' or `and' then indent to
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
		    (reduce-re-search-backward "[^ \t\f\n]")
		    (not (looking-at "\\(,\\|\\s(\\)[ \t]*[%\n]"))
		    )))
	(back-to-indentation)
	(if (or second_arg
		(and open
		     (looking-at
		      ;; ... procedure / begin, << / label
		      ".*\\<procedure\\>\
\\|\\<begin\\>\\|<<\
\\|\\w+[ \t]*:[^=]"))			; ???
		(looking-at "\\w+[ \t]*:[^=]"))	; label
	    (+ (current-column) reduce-indentation)
	  (current-column)))))

(defun reduce-unindent-line (arg)
  "Unindent current line; if ARG indent whole statement rigidly.
Delete `reduce-indentation' spaces from beginning of line.
With argument, unindent any additional lines of the same statement
rigidly along with this one."
  (interactive "*P")			; error if buffer read-only
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
  "Value of `comment-indent-function'."
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
  (interactive "*p")			; error if buffer read-only
  (save-excursion
    (if (reduce-mark-procedure arg)
	;; Leaves mark at end of procedure, point at start.
	(reduce-indent-region (point) (mark))
      )))

(defun reduce-indent-region (beg-region end-region)
  "Interactively indent region; otherwise BEG-REGION to END-REGION.
Interactively with prefix arg, indent the whole buffer."
  ;; (interactive "*r")			; error if buffer read-only
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
`reduce-auto-indent-delay' seconds of Emacs idle time re-indent the
current line if the text just typed matches `reduce-auto-indent-regexp'."
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
  "Re-indent current line if match with `reduce-auto-indent-regexp' just typed."
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
  "Move backward to next start of procedure. With ARG, do it ARG times."
  (interactive "p")
  (let ((case-fold-search t) (count arg))
    (while (and (> count 0) (reduce-re-search-backward procedure-regexp))
      (setq count (1- count)))
    (if (= count arg)
	()
      ;; (reduce-backward-statement 1)	; overkill?  Instead ...
      ;; Find preceding "%", ";", "$", "(" or beginning of buffer:
      (while (progn (skip-chars-backward "^%;$(")
		    (and (not (bobp))
			 (not (backward-char 1))
			 (= (preceding-char) ?!))))
      ;; If in %-comment then skip to its end:
      (if (reduce-back-to-percent-comment-start) (end-of-line))
      ;; Find actual start of procedure statement:
      (if (reduce-re-search-forward "[a-zA-Z]") (backward-char 1))
      )))

(defun reduce-forward-procedure (arg)
  "Move forward to next end of procedure.  With ARG, do it ARG times."
  (interactive "p")
  (let ((case-fold-search t) (start (point)) count)
    ;; Move to end of procedure starting before point:
    (if (reduce-re-search-backward procedure-regexp)
		(reduce-forward-statement 2))
    ;; Now move forward by arg or arg-1 procedures
    ;; or stay put if at least one move not possible
    (unless (<= (point) start)
      (setq arg (1- arg)) (setq start (point)))
    (setq count arg)
    (while (and (> count 0) (reduce-re-search-forward procedure-regexp))
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
      (skip-chars-forward " \t\n")	; skip trailing white space
      (push-mark start t)		; save original position QUIETLY
      (push-mark)			; mark end of procedure
      (reduce-backward-procedure arg)
      t)
    ))

(defun reduce-kill-procedure ()
  "Kill the procedure (and trailing white space) ending after point."
  (interactive "*")			; error if buffer read-only
  (if (reduce-mark-procedure 1)
      (kill-region (region-beginning) (region-end))))

(defun reduce-narrow-to-procedure (arg)
  ;; Based on `narrow-to-defun' in `lisp.el'.
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

(defvar reduce-up-tries 1
  "Repeat count of reduce-forward/backward-statement at end of block or group.")

(defun reduce-up-block-or-group-maybe (found start)
  "Move over `<<', `begin', `>>' or `end' (including end-of-file marker)
after reduce-max-up-tries repeated interactive attempts."
  (if (and found (= (point) start) (eq this-command last-command))
      (if (< reduce-up-tries reduce-max-up-tries)
	  (setq reduce-up-tries (1+ reduce-up-tries))
	(setq reduce-up-tries 1)
	(goto-char found)
	(if (eq this-command 'reduce-forward-statement)
	    ;; End of file marker needs special treatment:
	    (progn
	      (reduce-re-search-forward "[;$]" 'move)
	      (if (reduce-re-search-forward "[^ \t\f\n]") (goto-char found)))
	  ))
    (setq reduce-up-tries 1)))

(defvar reduce-forward-statement-found nil
  "Free variable bound in `reduce-forward-statement'")
;; Consider replacing with lexical binding.

(defun reduce-forward-statement (arg)
  "Move forward to end of statement. With ARG, do it ARG times.
If looking at the end of a block or group, or the end-of-file marker,
move over it after `reduce-max-up-tries' consecutive interactive tries."
  (interactive "p")
  (let ((case-fold-search t)
		(pattern "[;$]\\|>>\\|\\<end\\>\\|<<\\|\\<begin\\>\\|\\s(\\|\\s)")
		(start (point))
		reduce-forward-statement-found)
    ;; Skip an immediate closing bracket:
    (if (looking-at "[ \t\n]*\\s)") (goto-char (match-end 0)))
    (while (and (> arg 0) (reduce-forward-statement1 pattern))
      (setq arg (1- arg)))
    ;; Never move backwards:
    (if (< (point) start) (goto-char start))
    ;; Move over  >>  or  end  on repeated interactive attempt:
    (reduce-up-block-or-group-maybe reduce-forward-statement-found start)))

(defun reduce-forward-statement1 (pattern)
  "Move forward to next statement end and return t if successful."
  (if (looking-at "[;$]")
      ;; (forward-char 1)
      (not (forward-char 1))
    (if (reduce-re-search-forward pattern)
	(cond
	 ((= (preceding-char) ?>)
	  (setq reduce-forward-statement-found (point))
	  (backward-char 2) (skip-chars-backward " \t\n") t)
	 ((memq (preceding-char) '(?d ?D))
	  (setq reduce-forward-statement-found (point))
	  (backward-char 3) (skip-chars-backward " \t\n") t)
	 ((= (preceding-char) ?<)
	  (reduce-forward-group) (reduce-forward-statement1 pattern))
	 ((memq (preceding-char) '(?n ?N))
	  (reduce-forward-block) (reduce-forward-statement1 pattern))
	 ((= (char-syntax (preceding-char)) ?\( )
	  (backward-char) (forward-list) ; skip balanced brackets
	  (reduce-forward-statement1 pattern))
	 ((= (char-syntax (preceding-char)) ?\) )
	  (if (save-excursion		; quoted list does not
		(backward-list)		; contain REDUCE statements
		(skip-chars-backward " \t\n")
		(= (preceding-char) ?'))
	      (reduce-forward-statement1 pattern)
	    (backward-char) (skip-chars-backward " \t\n") t))
	 (t t))
      )))


(defun reduce-backward-statement (arg)
  "Move backward to start of statement. With ARG, do it ARG times.
If looking at the beginning of a block or group move over it after
`reduce-max-up-tries' consecutive interactive tries.
The end-of-file marker is treated as a statement.
Returns the count of statements left to move."
;; Return count used by reduce-calculate-indent-proc.
  (interactive "p")
  (let ((case-fold-search t)
	(pattern "[;$]\\|<<\\|\\<begin\\>\\|>>\\|\\<end\\>\\|\\s)\\|\\s(")
	(start (point)) (found t)
	;; Check whether after end of file marker, ``end''.
	;; Assume it starts at the beginning of the line.
	(not-eof (save-excursion
		   (or (reduce-re-search-forward "[^ \t\f\n]")
		       (not (progn
			      (reduce-re-search-backward "[^ \t\f\n]")
			      (beginning-of-line)
			      (looking-at "\\<end\\>")))
		       ))))
    (if (and (reduce-re-search-backward "[^ \t\f\n]")
	     (not (or (memq (following-char) '(?\; ?$))
		      ;; Skip an immediate opening bracket:
		      (= (char-syntax (following-char)) ?\( ))))
	(forward-char 1))
    (while (and (> arg 0) found)
      (setq found (reduce-backward-statement1 pattern not-eof))
      (setq arg (1- arg)))
    (if found
	(cond ((= (following-char) ?<)
	       (setq found (point)) (forward-char 2))
	      ((memq (following-char) '(?b ?B))
	       (setq found (point)) (forward-char 5))
	      (t (forward-char 1))
	      ))
    ;; Move to actual start of statement:
    (reduce-re-search-forward "[^ \t\f\n]") (backward-char 1)
    ;; Never move forwards:
    (if (> (point) start) (goto-char start))
    ;; Move over  <<  or  begin  on repeated interactive attempt:
    (reduce-up-block-or-group-maybe found start)
    arg
    ))

(defun reduce-backward-statement1 (pattern not-eof)
  "Move backward to next statement beginning.
Return t if successful, nil if reaches beginning of buffer."
  (if (reduce-re-search-backward pattern 'move)
      (cond
       ((= (following-char) ?>)		; end of group
	(reduce-backward-group) (reduce-backward-statement1 pattern not-eof))
       ((memq (following-char) '(?e ?E)) ; end of block (or file)
	(if not-eof
	    (progn (reduce-backward-block) (setq not-eof nil)))
	(reduce-backward-statement1 pattern not-eof))
       ((= (char-syntax (following-char)) ?\) )
	(forward-char) (backward-list) ; skip balanced brackets
	(reduce-backward-statement1 pattern not-eof))
       ((= (char-syntax (following-char)) ?\( )
	(forward-char) (skip-chars-forward " \t\n") (backward-char) t)
       (t t))
    ))


(defun reduce-kill-statement (&optional arg)
  "Kill the rest of the current statement or ARG statements from point.
If no nonblanks kill thru newline.
With prefix argument, kill that many statements from point.
Negative arguments kill complete statements backwards, cf. `kill-line'."
  ;; Based on kill-line in simple.el
  (interactive "*P")			; error if buffer read-only
  (kill-region (point)
	       (progn
		 (if (and (null arg) (looking-at "[ \t]*$"))
		     (forward-line 1)
		   (setq arg (prefix-numeric-value arg))
		   (if (> arg 0)
		       (progn
			 (reduce-forward-statement arg)
			 (skip-chars-forward " \t")) ; 2 Oct 1994
		     (reduce-backward-statement (- 1 arg))))
		 (point))))


;;;; ************************
;;;; Moving by block or group
;;;; ************************

(defun reduce-up-block-or-group (arg)
  "Move backwards up one level of block or group; if ARG move forwards.
Move to beginning of nearest unpaired  `begin'  or  `<<'.
A universal argument means move forwards
to end of nearest unpaired  `end'  or  `>>'.
With a numeric argument, do it that many times, where a
negative argument means move forward instead of backward."
  (interactive "P")
  (let ((case-fold-search t))
    (setq arg (reduce-prefix-numeric-value arg))
    (while (and (not (= arg 0)) (reduce-up-block-or-group1 arg))
      (setq arg (if (> arg 0) (1- arg) (1+ arg)))
      )))

(defun reduce-up-block-or-group1 (arg)
  "Sub-function of `reduce-up-block-or-group'."
  (let ((start (point)))
    (if (or
	 (and (> arg 0) (reduce-backward-block-or-group))
	 (and (< arg 0) (reduce-forward-block-or-group)))
	t
      (goto-char start) nil)))

(defun reduce-backward-block-or-group ()
  "Move backward to beginning of block or group containing point."
  (if (reduce-re-search-backward "\\<begin\\>\\|<<\\|\\<end\\>\\|>>")
      (cond ((= (following-char) ?>)
	     (reduce-backward-group)
	     (reduce-backward-block-or-group))
	    ((memq (following-char) '(?e ?E))
	     (reduce-backward-block)
	     (reduce-backward-block-or-group))
	    (t t)
	    )))

(defun reduce-forward-block-or-group ()
  "Move forward to end of block or group containing point."
  (if (reduce-re-search-forward "\\<end\\>\\|>>\\|\\<begin\\>\\|<<")
      (cond ((= (preceding-char) ?<)
	     (reduce-forward-group)
	     (reduce-forward-block-or-group))
	    ((memq (preceding-char) '(?n ?N))
	     (reduce-forward-block)
	     (reduce-forward-block-or-group))
	    (t t)
	    )))


(defun reduce-down-block-or-group (arg)
  "Move forward down one level of block or group; if ARG move backwards.
Move to end of nearest unpaired  `begin'  or  `<<'.
A universal argument means move backward
to beginning of nearest unpaired  `end'  or  `>>'.
With a numeric argument, do it that many times, where a
negative argument means move backward instead of forward."
  (interactive "P")
  (let ((case-fold-search t))
    (setq arg (reduce-prefix-numeric-value arg))
    (while (and (not (= arg 0)) (reduce-down-block-or-group1 arg))
      (setq arg (if (> arg 0) (1- arg) (1+ arg)))
      )))

(defun reduce-down-block-or-group1 (arg)
  "Sub-function of `reduce-down-block-or-group'."
  (let ((start (point)))
    (if
	(if (> arg 0)
	    (and
	     (reduce-re-search-forward "<<\\|\\<begin\\>\\|>>\\|\\<end\\>")
	     (memq (preceding-char) '(?< ?n ?N)))
	  (and
	   (reduce-re-search-backward ">>\\|\\<end\\>\\|<<\\|\\<begin\\>")
	   (memq (following-char) '(?> ?e ?E)))
	  )
	t
      (goto-char start) nil)
    ))


(defun reduce-prefix-numeric-value (arg)
  "Interpret universal ARG as -1, otherwise apply `prefix-numeric-value'."
  (if (and arg (listp arg)) -1 (prefix-numeric-value arg)))


(defun reduce-forward-block ()
  "Move forwards to end of block containing point.
Return t if successful; otherwise move as far as possible and return nil."
  (let (return)
    (while (and (setq return (reduce-re-search-forward
							  "[^'\(]\\<end\\>\\|\\([^'\(]\\<begin\\>\\)" 'move))
				(match-beginning 1))
      (reduce-forward-block))
    return))

;; ***** Should reduce-backward-block also skip white space,which it
;; ***** seems to do? This is a problem for reduce-show-delim-mode.
(defun reduce-backward-block ()
  "Move backwards to start of block containing point.
Return t if successful; otherwise move as far as possible and return nil."
  (let (return)
    (while (and (setq return (reduce-re-search-backward
							  "[^'\(]\\<begin\\>\\|\\([^'\(]\\<end\\>\\)" 'move))
				(match-beginning 1))
      (reduce-backward-block))
    return))

(defun reduce-forward-group ()
  "Move forwards to end of group containing point.
Return t if successful; otherwise move as far as possible and return nil."
  (let (return)
    (while (and (setq return (reduce-re-search-forward ">>\\|<<" 'move))
		(= (preceding-char) ?<))
      (reduce-forward-group))
    return))

(defun reduce-backward-group ()
  "Move backwards to start of group containing point.
Return t if successful; otherwise move as far as possible and return nil."
  (let (return)
    (while (and (setq return (reduce-re-search-backward "<<\\|>>" 'move))
		(= (following-char) ?>))
      (reduce-backward-group))
    return))


;;;; *****************************************************************
;;;; Searching for syntactic elements ignoring comments, strings, etc.
;;;; *****************************************************************

(defun reduce-re-search-forward (regexp &optional MOVE)
  "Syntactic search forwards for REGEXP; if no match and MOVE then move to end.
Skip comments, strings, escaped tokens, and quoted tokens other than `('.
Return t if match found, nil otherwise."
  (let ((start (point))
	(pattern (concat regexp "\\|%\\|\\<comment\\>"))
	(move (if MOVE 'move t)))
    (if (reduce-re-search-forward1 pattern move)
	t
      (if (not MOVE) (goto-char start))
      nil)
    ))

(defun reduce-re-search-forward1 (pattern move)
  "Skip strings."
  (if (reduce-re-search-forward2 pattern move)
      (if (reduce-in-string)		; try again!
	  (reduce-re-search-forward1 pattern move)
	t)
    nil))

(defun reduce-re-search-forward2 (pattern move)
  "Skip escaped, quoted or commented text."
  (if (re-search-forward pattern nil move)
      (let ((match-data (match-data))
	    before)
	(if (> (match-beginning 0) 0)
	    (setq before (char-after (1- (match-beginning 0)))))
	(cond
	 ((and before
	       (or (= before ?!)      ; skip escaped text
		   (and (= before ?') ; skip quoted text except '(...)
			(not (= (char-after (match-beginning 0)) ?\( )))))
	  (reduce-re-search-forward2 pattern move)) ; search again
	 ((= (preceding-char) ?%)		    ; skip % comment
	  (forward-line 1)
	  (reduce-re-search-forward2 pattern move)) ; search again
	 ((string-match "^comment$"
			;; otherwise might fortuitously match only
			;; the beginning of the string "comment"
			(buffer-substring
			 (match-beginning 0) (match-end 0)) )
	  (re-search-forward "[^!][;$]" nil move)   ; 'move ???
	  (reduce-re-search-forward2 pattern move)) ; search again
	 (t (store-match-data match-data) t))
	)))


(defun reduce-re-search-backward (regexp &optional MOVE)
  "Syntactic search backwards for REGEXP else if MOVE then move to start.
Skip REDUCE comments and strings. Return t if match found, nil otherwise."
  (let ((start (point))
	(move (if MOVE 'move t)))
    (if (reduce-re-search-backward1 regexp move)
	t
      (if (not MOVE) (goto-char start))
      nil)
    ))

(defun reduce-re-search-backward1 (regexp move)
  "Sub-function of `reduce-re-search-backward'.
Skip strings backwards."
  (if (reduce-re-search-backward2 regexp move)
      (if (reduce-in-string)		; try again!
	  (reduce-re-search-backward1 regexp move)
	t)
    nil))

(defun reduce-re-search-backward2 (regexp move)
  "Skip escaped, quoted or commented text backwards."
  (if (re-search-backward regexp nil move)
      (let ((match-data (match-data)))
	(if (or (= (preceding-char) ?!) ; escaped
		(and (= (preceding-char) ?') ; quoted (maybe)
		     (not (= (char-after (- (point) 2)) ?!)))
		(reduce-back-to-comment-start)) ; in comment
	    (reduce-re-search-backward2 regexp move) ; search again
	  ;; Restore finally accepted match data:
	  (store-match-data match-data)
	  t)
    )))


(defun reduce-back-to-comment-start ()
  "If point is in a comment then move to its start and return t.
Otherwise do not move and return nil."
  (or
   ;; Check whether in % comment:
   (reduce-back-to-percent-comment-start)
   ;; Check whether in comment statement:
   (let ((start (point)) posn
		 (pattern "[^!][;$]\\|\\<comment\\>"))
     (cond
      ((setq posn (reduce-back-to-comment-statement-start pattern))
       ;; in comment statement -- go to its true beginning
       (goto-char posn) t)
      (t (goto-char start) nil))		; not in comment statement
     )))

(defun reduce-back-to-comment-statement-start (pattern)
  "Move backwards to the nearest `comment' keyword or separator.
If it is `comment' then return its start position; otherwise return nil."
  (while (and (re-search-backward pattern nil 'move)
			  (reduce-back-to-percent-comment-start)))
  (if (looking-at "comment") (point)))

(defun reduce-back-to-percent-comment-start ()
  "If point is in a percent comment then move to its start and return t.
Otherwise do not move and return nil."
;;;  (re-search-backward
;;;   "^%\\|[^!]%" (save-excursion (beginning-of-line) (point)) t)
  ;; Note that a % may appear at the end of, or alone on, a line!
  (let ((start (point)))
    (beginning-of-line)
    (prog1
	(re-search-forward "^%\\|[^!]%" (1+ start) 'move)
      (backward-char)
      )))

(defun reduce-in-string ()
  "Return t if point is within a string, assuming no multi-line strings."
  (let ((start (point)) (in-string nil))
    (beginning-of-line)
    (while (< (point) start)
      (if (= (following-char) ?\")
	  (if in-string
	      ;; Cannot include a \" within a string
	      (setq in-string nil)	; found end of string
	    (if (not(= (preceding-char) ?!))
		(setq in-string t))	; found beginning of string
	    ))
      (forward-char 1))
    in-string))


;;;; ****************
;;;; Comment commands
;;;; ****************

(defun reduce-comment-region (beg-region end-region arg)
  "Comment/uncomment every line in region, from BEG-REGION to END-REGION.
With interactive ARG, comment if non-negative, uncomment if null
or negative (cf. minor modes).
Put `reduce-comment-region-string' at the beginning of every line in the region.
First two args specify the region boundaries, third arg is interactive."
  ;; Taken almost directly from fortran.el
  ;; by Michael D. Prange (prange@erl.mit.edu).
  (interactive "*r\nP")			; error if buffer read-only
  (let ((end-region-mark (make-marker)) (save-point (point-marker)))
    (set-marker end-region-mark end-region)
    (goto-char beg-region)
    (beginning-of-line)
    (if (if arg
	    (< (reduce-prefix-numeric-value arg) 0)
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
  (interactive "*P")			; error if buffer read-only
  (save-excursion
    (beginning-of-line)
    (if (if arg
	    (< (reduce-prefix-numeric-value arg) 0)
	  (looking-at "%"))
	(let (start)			; uncomment lines
	  (if (looking-at "%")		; necessary ???
	      (if (re-search-backward "^[^%]" nil t) (forward-line 1))
	    (re-search-forward "^%" nil t))
	  (setq start (point))
	  (re-search-forward "^[^%]" nil t)
	  (reduce-comment-region start (point) -1)) ; UNCOMMENT
      (if (reduce-mark-procedure 1)	; comment out procedure
	  (progn			; first back up to real
	    (exchange-point-and-mark)	; end of procedure
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
			  ;; (See `reduce-font-lock-extend-region-for-comment'.)
			  (save-excursion
				(and (re-search-backward "\\(comment\\)\\|\\(;\\)" nil t)
					 (match-beginning 1)
					 (setq first (point)))))
		  ;; Yes -- use normal text-mode fill, but only within the
		  ;; comment statement, which might be within code:
		  (save-restriction
			(narrow-to-region first (save-excursion (search-forward ";")))
			(fill-paragraph justify))
		;;No...
		;; If point is in a %-comment then find its prefix and fill it:
		(if (looking-at "[ \t]*%")
			(let (fill-prefix last)
			  ;; Code modified from `set-fill-prefix' in fill.el.
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
  "Insert `if ... then'; if ELSE then include `else'.
Position point after `if'.
With argument include a correctly indented `else' on a second line."
  (interactive "*P")			; error if buffer read-only
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
  "Insert and indent `begin ... end' block; if NOSPLIT then on same line.
Position point inside.
With argument put `begin' and `end' on the same line
\(see `reduce-insert-block-or-group')."
  (interactive "*P")			; error if buffer read-only
  (reduce-insert-block-or-group "begin" "end" t nosplit))

(defun reduce-insert-group (&optional nosplit)
  "Insert and indent `<<  >>' group; if NOSPLIT then on same line.
Position point inside.
With argument put `<<' and `>>' on the same line
\(see `reduce-insert-block-or-group')."
  (interactive "*P")			; error if buffer read-only
  (reduce-insert-block-or-group "<<" ">>" nil nosplit))

(defun reduce-insert-block-or-group (open close block nosplit)
  "Insert and indent `open ... close' structure and position point inside.
If the mark is transient and active then enclose the region; otherwise
if point is not at the end of the line then enclose the rest of the line.
Leave the mark at the insertion point in the body of a block.
If `nosplit' is true then put `open' and `close' on the same line."
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
	(progn				; better to indent rigidly?
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
    (reduce-indent-line)		; necessary AFTER inserting close
    (goto-char finish-marker)
    (set-marker finish-marker nil)
    ))

;; If an expansion function interprets an argument then it means that
;; the expansion should be kept on one line.  The following are
;; provided solely to ignore any argument:

(defun reduce-expand-if-then (&optional arg)
  "Insert `if ... then' and position point inside, ignoring ARG."
  (reduce-insert-if-then))

(defun reduce-expand-if-then-else (&optional arg)
  "Insert `if ... then ... else' and position point after `if', ignoring ARG."
  (reduce-insert-if-then 'else))


;;;; **********************************
;;;; Balanced structure (sexp) commands
;;;; **********************************

(defun reduce-forward-sexp (&optional arg)
  "Move forward across one, or ARG, balanced expression(s).
With argument, do it that many times."
  (interactive "p")
  (let ((case-fold-search t))
    (skip-chars-forward " \t\n;$")
    (cond
     ((= (char-syntax (following-char)) ?\( ) (forward-sexp))
     ((looking-at "<<") (forward-char 2) (reduce-forward-group))
     ((looking-at "begin") (forward-char 5) (reduce-forward-block))
     ((looking-at ">>") (forward-char 2))
     (t (forward-sexp))
     ))
  (if (and arg (> arg 1)) (reduce-forward-sexp (1- arg)))
  )

(defun reduce-backward-sexp (&optional arg)
  "Move backward across one, or ARG, balanced expression(s).
With argument, do it that many times."
  (interactive "p")
  (skip-chars-backward " \t\n;$")
  (if (= (char-syntax (preceding-char)) ?\) )
      (backward-sexp)
    (let ((case-fold-search t) (start (point)))
      (skip-chars-backward ">>end<<")
      (cond
       ((looking-at ">>") (reduce-backward-group))
       ((looking-at "end") (reduce-backward-block))
       ((looking-at "<<"))
       (t (goto-char start) (backward-sexp))
       )
      ))
  (if (and arg (> arg 1)) (reduce-backward-sexp (1- arg)))
  )


;;;; *************************************
;;;; Support for matching group delimiters
;;;; *************************************

(defun reduce-self-insert-and-blink-matching-group-open ()
  "Insert character and then blink matching group opening construct."
  ;; Based on blink-matching-open in simple.el
  ;; but cannot use syntax table for composite tokens like << ... >>
  (interactive "*")			; error if buffer read-only
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
	   (reduce-backward-group)
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
  "See `reposition-window' for details."
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
Compare that symbol against the elements of `reduce-completion-alist'.
If a perfect match (only) has a cdr then delete the match and insert
the cdr if it is a string or call it if it is a (nullary) function,
passing on any prefix argument (in raw form)."
  ;; Based on lisp-complete-symbol in lisp.el
  (interactive "*P")			; error if buffer read-only
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
    (cond ((eq completion t)		; perfect match
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


;;;; ****************************************************
;;;; Support font-lock-mode for highlighting keywords and
;;;; "object" names (based on code by Rainer Schoepf).
;;;; ****************************************************

;; Fontification is performed syntactically (e.g. comments) and THEN
;; by keyword.

;; *** Make these temp variables let bindings later ??? ***

(defconst reduce-identifier-regexp
  "\\([a-z]\\|!.\\)\\(\\w\\|\\s_\\|!.\\)*"
  ;; NB: digits have word syntax
  "Regular expression matching a REDUCE identifier.")

(defconst reduce-infix-regexp
  "where\\|when\\|or\\|and\\|member\\|memq\\|neq\\|eq")

(defconst reduce-keyword-regexp
  (mapconcat 'identity
			 (list
			  "begin" "return" "end\\(module\\)?"
			  "if" "then" "else"
			  "while" "do" "repeat" "until"
			  "collect" "join" "conc" "sum" "product"
			  "for\\(\\s *\\(all\\|each\\)\\)?" "step"
			  "in" "on" "off" "write"
			  "let" "clearrules"
			  "clear" "pause"
			  "assert_install" "assert_install_all"
			  "assert_uninstall" "assert_uninstall_all"
			  "assert"

			  ;; Lisp keywords used frequently in REDUCE:
			  "lambda" "function"
			  ;; "put" "flag" "remprop" "remflag"
			  reduce-infix-regexp)
			 "\\|")
  "Regular expression matching a REDUCE keyword.")

;(defvar reduce-reserved-variable-regexp
;  "e\\|i\\|infinity\\|nil\\|pi\\|t")

(defconst font-lock-default-face 'font-lock-default-face
  "A copy of the default face for use by REDUCE Font Lock mode.")
(copy-face 'default 'font-lock-default-face)

;;; I should tidy up the following a bit at some point. For now I have made an
;;; effort to isolate this not to disturb others. TS
(defconst reduce-asserted-arg-types-rule ;; TS
     (list (concat "[(,]\\s-*"
		 "\\("
		 "[^: \"]+";  should be reduce-identifier-regexp but this did not work
;;		 reduce-identifier-regexp
		 "\\)"
		 "\\s-*:\\s-*"
		 "\\("
		 "[^), \"]+";  should be reduce-identifier-regexp but this did not work
;;		 reduce-identifier-regexp
		 "\\)")
	   '(2 font-lock-type-face t)))

(defconst reduce-asserted-return-type-rule ;; TS
     (list (concat ")\\s-*:\\s-*"
		 "\\("
		 "[^ ;$]+";  should be reduce-identifier-regexp but this did not work
		 "\\)")
	 '(1 font-lock-type-face t)))

(defconst reduce-assert-declare-rules  ;; TS
  (list '("\\(declare\\)\\s +\\([^:]*\\)"
	  (1 font-lock-keyword-face)
	  (2 font-lock-function-name-face))
	'("declare\\s +[^(]*(\\([^)]*\\)"
	  (1 font-lock-type-face))
	(list (concat "declare\\s +.*->\\s *\\(" reduce-identifier-regexp "\\)")
	      '(1 font-lock-type-face))))

(defconst reduce-assert-struct-rules  ;; TS
  (list (list (concat "\\(struct\\)\\s *\\("
		      reduce-identifier-regexp
		      "\\)")
	      '(1 font-lock-keyword-face)
	      '(2 font-lock-type-face))
	(list (concat "struct\\s *.*"
		      "\\s *\\(checked\\s-*by\\|asserted\\s-*by\\)\\s *\\("
		      reduce-identifier-regexp
		      "\\)")
	      '(1 font-lock-keyword-face t)
	      '(2 font-lock-function-name-face))))

(defconst reduce-preprocessor-rules  ;; TS
  (list
   (list (concat "\\(#\\<define\\>\\)\\s +\\("
   		 reduce-identifier-regexp
   		 "\\)\\s +\\("
   		 reduce-identifier-regexp
   		 "\\)")
   	 '(1 font-lock-preprocessor-face)
   	 '(2 font-lock-function-name-face)
   	 '(3 font-function-name-face))
   (list "\\(#\\<if\\>\\)\\s +\\(.*$\\)"
	 '(1 font-lock-preprocessor-face)
	 '(2 font-lock-default-face))
   (list "\\(#\\<elif\\>\\)\\s +\\(.*$\\)"
	 '(1 font-lock-preprocessor-face)
	 '(2 font-lock-default-face))
   (list "\\(#\\<else\\>\\)"
	 '(1 font-lock-preprocessor-face))
   (list "\\(#\\<endif\\>\\)"
	 '(1 font-lock-preprocessor-face))))

(defconst reduce-font-lock-keywords-0
  (append (list
	   ;; Main keywords:
	   (list (concat
		  ;; Ignore quoted keywords and composite identifiers:
		  ;; "\\(^[^!_']?\\|[^!][^!_']\\)"
		  "\\(^[^!_'#]?\\|[^!#][^!_'#]\\)"
		  "\\<\\(\\(" reduce-keyword-regexp "\\)"
		  ;; Handle consecutive keywords:
		  "\\(\\s +\\(" reduce-keyword-regexp "\\)\\)*"
		  "\\)\\>"
		  ;; Ignore composite identifiers:
		  ;; "[^!_]"
		  "[^!_#]"
		  ) '(2 font-lock-keyword-face))
	   ;; Group delimiters and references:
	   '("<<\\|>>\\|\\<\\(module\\|go\\(\\s *to\\)?\\)\\>"
	     . font-lock-keyword-face)
	   ;; Procedure declarations:
	   (list (concat "\\(^\\|ic\\|macro\\|expr\\|asserted\\|inline\\)\\s *\\<\\(procedure\\)\\s +"
			 "\\(" reduce-identifier-regexp "\\)" "\\s *(?")
		 '(2 font-lock-keyword-face)
		 ;; '(2 font-lock-function-name-face t) ; highlights within comments
		 '(3 font-lock-function-name-face)
		 )
	   '("\\(declare\\)\\s +\\([^:]*\\)"
	     (1 font-lock-keyword-face)
	     (2 font-lock-function-name-face))
	   '("declare\\s +[^(]*(\\([^)]*\\)"
	     (1 font-lock-type-face))
	   ;; Type declarations:
	   ;; '("[^!][^_]\\<\\(algebraic\\|symbolic\\|operator\\|scalar\\|integer\\|real\\)\\>[^!_]"
	   '("\\(?:^\\|[^_]\\)\\<\\(algebraic\\|symbolic\\|operator\\|scalar\\|integer\\|real\\|linear\\)\\>[^!_]"
	     (1 font-lock-type-face))
	   reduce-asserted-arg-types-rule
	   reduce-asserted-return-type-rule)
	  reduce-assert-declare-rules
	  reduce-assert-struct-rules
	  reduce-preprocessor-rules)
  "Default minimal REDUCE fontification rules.")

(defvar font-lock-beg) (defvar font-lock-end)
(defun reduce-font-lock-extend-region-for-comment ()
  "Extend font-lock region if necessary to include all of any
comment statements that it intersects, and if so return non-nil.
This function is prepended to `font-lock-extend-region-functions'."
  (let (new-beg new-end)
	(goto-char font-lock-beg)
	;; Is font-lock-beg within a comment?
	(save-excursion
	  (if (and (re-search-backward "\\(comment\\)\\|\\(;\\)" nil t)
			   (match-beginning 1))
		  (setq new-beg (point))))
	(when (or new-beg
			  ;; Or does a comment start in the font-lock region?
			  (search-forward "comment" font-lock-end t))
	  ;; If either of the above then...
	  (search-forward ";" nil 1)		; if un-terminated move to EOB
	  ;; Do multiple comments start in the font-lock region?
	  (while (and (< (point) font-lock-end)
				  (search-forward "comment" font-lock-end t))
		(search-forward ";" nil 1))		; if un-terminated move to EOB
	  (if (> (point) font-lock-end)
		  (setq new-end (point))))
	;; Temporary message for testing:
	;; (message "reduce-font-lock-extend-region-for-comment: %s --> %s, %s --> %s"
	;; 		 font-lock-beg new-beg font-lock-end new-end)
	;; Return non-nil if font-lock region adjusted:
	(or (if new-beg (setq font-lock-beg new-beg))
		(if new-end (setq font-lock-end new-end)))))

(defconst reduce-font-lock-keywords-basic
  (list
   
   ;; Comment statements.  Note that `.' does not match EOL and the
   ;; repetition must be non-greedy `*?'.  This fontification must
   ;; override any previous (syntactic) fontification.  Being normally
   ;; multi-line, it requires the support of the function
   ;; `reduce-font-lock-extend-region-for-comment'.
   '("\\(?:^\\|[ \t;$]\\)\\(comment\\(?:\\s-\\|\n\\)\\(?:.\\|\n\\)*?;\\)" .
	 (1 font-lock-comment-face t))

   ;; Main keywords:
   (list (concat
		  ;; Ignore quoted keywords and composite identifiers:
		  ;; "\\(^[^!_']?\\|[^!][^!_']\\)"
		  "\\(^[^!_'#]?\\|[^!#][^!_'#]\\)"
		  "\\<\\(\\(" reduce-keyword-regexp "\\)"
		  ;; Handle consecutive keywords:
		  "\\(\\s +\\(" reduce-keyword-regexp "\\)\\)*"
		  "\\)\\>"
		  ;; Ignore composite identifiers:
		  ;; "[^!_]"
		  "[^!_#]"
		  ) '(2 font-lock-keyword-face))

   ;; Group delimiters:  OK
   '("<<\\|>>" . font-lock-keyword-face)

   ;; Procedure declarations:
   (list (concat "\\<\\(procedure\\)\\s +"
				 "\\(" reduce-identifier-regexp "\\)" "\\s *(?")
		 '(1 font-lock-keyword-face)
		 ;; This will probably cause highlighting within comments, see above:
		 ;; 	 '(2 font-lock-function-name-face t)
 		 '(2 font-lock-function-name-face)  ; no highlighting in comments; TS
		 ;; Anchored matches (single line only!):
		 (list (concat "\\s *"
					   "\\(" reduce-identifier-regexp "\\)"
					   "\\s *\\([\);$].*\\|\\s.\\)"
										; Stop after `)', `;' or `$'
					   )
			   nil nil
			   '(1 font-lock-variable-name-face)))

   ;; Type declarations:
   (list "\\<\\(operator\\|scalar\\|integer\\|real\\)\\s "
		 '(1 font-lock-type-face)
		 ;; Anchored matches (single line only!):
		 (list (concat "\\s *"
					   "\\(" reduce-identifier-regexp "\\)"
					   "\\s *\\s."
					   )
			   nil nil
			   '(1 font-lock-variable-name-face)))

   ;; References -- goto and labels:
   (list (concat "\\<\\(go\\(\\s *to\\)?\\)\\s +"
				 "\\(" reduce-identifier-regexp "\\)")
		 '(1 font-lock-keyword-face)
		 '(3 font-lock-constant-face))	; was font-lock-reference-face
   (cons (concat "^\\s *\\(" reduce-identifier-regexp "\\)\\s *:[^=]")
		 '(1 font-lock-constant-face))	; was font-lock-reference-face
   )
  "Basic REDUCE fontification sub-rules.")

(defconst reduce-font-lock-keywords-algebraic
  (append (list
	   ;; More type declarations:
	   (list "\\<\\(array\\|matrix\\)\\s "
		 '(1 font-lock-type-face)
		 ;; Anchored matches (single line only!):
		 (list (concat "\\s *"
			       "\\(" reduce-identifier-regexp "\\)"
			       "\\s *\\(([^\)]*)\\s *\\)?\\s."
			       )
		       nil nil
		       '(1 font-lock-variable-name-face))
		 )
	   reduce-asserted-arg-types-rule
	   reduce-asserted-return-type-rule)
	  reduce-preprocessor-rules)
  "More algebraic-mode REDUCE fontification sub-rules.")

(defconst reduce-font-lock-keywords-symbolic
  (append (list
	   ;; References -- module:
	   (list (concat "\\<\\(module\\)\\s +"
			 "\\(" reduce-identifier-regexp "\\)")
		 '(1 font-lock-keyword-face)
		 '(2 font-lock-constant-face))	; was font-lock-reference-face
	   ;; Type declarations:
	   '("\\<\\(fluid\\|global\\)\\>\\s *'(\\(.*\\))"
	     (1 font-lock-type-face)
	     (2 font-lock-variable-name-face))
	   (cons (concat
		  ;; Ignore quoted keywords and composite identifiers:
		  "\\(^[^!_']?\\|[^!][^!_']\\)"
		  "\\<\\(newtok\\|precedence\\|switch\\|share\\|"
		  "algebraic\\|symbolic\\|f?expr\\|s?macro\\|asserted\\|inline\\)\\>"
		  ;; Ignore composite identifiers:
		  "[^!_]"
		  )
		 '(2 font-lock-type-face))
	   reduce-asserted-arg-types-rule
	   reduce-asserted-return-type-rule)
	  reduce-assert-declare-rules
	  reduce-assert-struct-rules
	  reduce-preprocessor-rules)
  "More symbolic-mode REDUCE fontification sub-rules.")

(defconst reduce-font-lock-keywords-full
  (list
   ;; Gaudier fontification
   ;; =====================

   ;; More type declarations:
   (list "\\<\\(array\\|matrix\\)\\s "
	 '(1 font-lock-type-face)
	 ;; Anchored matches (single line only!):
	 (list (concat "\\s *"
		       "\\(" reduce-identifier-regexp "\\)"
		       "\\s *\\(([^\)]*)\\s *\\)?\\s."
		       )
	       nil nil
	       '(1 font-lock-variable-name-face))
	 )

   ;; Set *ALL* quoted identifiers in the default face:
   (cons (concat
	  "'\\("
	  ;; All (multi-line) quoted lists (nested to 2 levels):
	  "(\\([^)]*([^)]*[^!])\\)*[^)]*[^!])"
	  "\\|" reduce-identifier-regexp ; includes keywords!
	  "\\)")
	 '(0 font-lock-default-face keep)) ; not already highlighted

   ;; Highlight variable invocations:
   ;; ( var), var PUNCTUATION, var EOL, var KEYWORD, var INFIX )
   (list (concat
	  "\\(" reduce-identifier-regexp "\\)"
	  "\\s *\\("
	  "\\s\)\\|\\s.\\|$\\|"
	  "\\s \\<\\(" reduce-keyword-regexp
	  "\\|\\(" reduce-infix-regexp "\\)\\)\\>"
	  "\\)")
	 '(1 font-lock-variable-name-face)
	 '(4 font-lock-default-face))

;;; Should force ALL infix ops into right font!

   ;; Highlight function calls:
   ;; ( fn(), fn{}, fn"", fn'data, fn var, fn ! )
   (cons (concat
	  "\\(\\(" reduce-identifier-regexp "\\)"
	  ;; Handle unparenthesized compositions:
	  "\\(\\s +\\(" reduce-identifier-regexp "\\)\\)*\\)"
	  "\\s *\\(\\s\(\\|[\"']\\|\\s \\(\\w\\|!\\)\\)"
	  )
	 ;; Must keep already fontified keywords in order to
	 ;; highlight functions immediately following keywords
	 ;; and avoid mis-highlighting variables:
	 '(1 font-lock-function-name-face keep))
   )
  "Full maximal REDUCE fontification sub-rules.")

(defconst reduce-font-lock-keywords-1
  (append reduce-font-lock-keywords-basic
		  reduce-font-lock-keywords-algebraic)
  "Standard algebraic-mode REDUCE fontification rules.")

(defconst reduce-font-lock-keywords-2
  (append reduce-font-lock-keywords-basic
		  reduce-font-lock-keywords-symbolic)
  "Standard symbolic-mode REDUCE fontification rules.")

(defconst reduce-font-lock-keywords-3
  (append reduce-font-lock-keywords-basic
		  reduce-font-lock-keywords-algebraic
		  reduce-font-lock-keywords-symbolic
		  reduce-font-lock-keywords-full)
  "Full REDUCE fontification rules.")

;; Provide a REDUCE font-lock menu, based on font-lock-menu.el by
;; Simon Marshall <simon@gnu.ai.mit.edu>.

;; The following is a temporary hack to make things work. It appears
;; that font-locking is correctly initialized only if
;; `reduce-font-lock-level' is initialized with with the maximum value
;; 4. If you try a value of three in the following line, you will find
;; this as the chosen value in the menu but still see maximum
;; decoration. Switching then works fine though. I thus had the idea to
;; run at the end of this file, right before executing the hook,
;; something like the following:
;;
;; (let ((tmp reduce-font-lock-level))
;;   (reduce-font-lock-change 4)
;;   (reduce-font-lock-change tmp))
;;
;; This, however, produces errors at loading, which indiciate that
;; things are more complicated, and I do not completely understand the
;; situation so far. Note that the problems do not origin from my
;; generalization to alists of the initialization code for
;; `reduce-font-lock-level' -  at least I hope so! TS

(set (make-local-variable 'font-lock-maximum-decoration) 4)

;; Considerably modified the following procedure to cover also the case
;; that `font-lock-maximum-decoration' is an alist. TS

(defvar reduce-font-lock-level
  ;; boundp in case font-lock not loaded
  (if (boundp 'font-lock-maximum-decoration)
      (let ((max (length reduce-font-lock-keywords))
	    (dec font-lock-maximum-decoration)
	    w)
	(if (listp dec)
	    (setq dec (if (or (setq w (assoc 'reduce-mode dec))
			      (setq w (assoc t dec)))
			  (cdr w)
			nil)))
	(if dec
	    (if (numberp dec)
		(cond ((< dec 1) 1)
		      ((> dec max) max)
		      (t dec))
	      max)				; t = maximum
	  1))
	1))					; nil = minimum

(defconst reduce-font-lock-submenu
  '("Syntax Highlighting"
    ["In Current Buffer" font-lock-mode
     :style toggle :selected font-lock-mode :active t]
    ["Highlight Buffer" font-lock-fontify-buffer t]
;     ["Toggle `!' Syntax" reduce-font-lock-toggle-escape t]
    ["Maximum (4)" (reduce-font-lock-change 4)
     :style radio :selected (eq reduce-font-lock-level 4) :active t]
    ["Symbolic (3)" (reduce-font-lock-change 3)
     :style radio :selected (eq reduce-font-lock-level 3) :active t]
    ["Algebraic (2)" (reduce-font-lock-change 2)
     :style radio :selected (eq reduce-font-lock-level 2) :active t]
    ["Minimum (1)" (reduce-font-lock-change 1)
     :style radio :selected (eq reduce-font-lock-level 1) :active t]))

(easy-menu-define  ; (symbol maps doc menu)
 reduce-fontification-submenu
 nil
 "REDUCE Fontification Submenu"
 reduce-font-lock-submenu
 )

(define-key-after (lookup-key reduce-mode-map [menu-bar REDUCE])
  [Fontification] (cons "Syntax Highlighting" reduce-fontification-submenu)
  t)					; was 'Make\ Proc\ Menu

(defconst reduce-font-lock-level-names
  '("minimum" "algebraic" "symbolic" "maximum"))

(defun reduce-font-lock-change (level)
  "Turn on REDUCE Font Lock mode using specified keywords."
  (interactive)
  (require 'font-lock)
  (let ((name (nth (1- level) reduce-font-lock-level-names))
	(keywords (eval (nth (1- level) (car font-lock-defaults)))))
    ;; `font-lock-defaults' is used in order to support both
    ;; reduce-mode and reduce-run with the same code!
    (setq keywords (font-lock-compile-keywords keywords)) ; Emacs 20 only!
    (if (and font-lock-mode (equal font-lock-keywords keywords))
	(message "REDUCE Font Lock decoration unchanged (level %d : %s)."
		 level name)
      (font-lock-mode 0)
      (font-lock-set-defaults)
      (setq font-lock-keywords keywords)
      (font-lock-mode 1)
      (setq reduce-font-lock-level level)
      (message "REDUCE Font Lock decoration set to level %d : %s."
	       level name))))

(defun reduce-font-lock-toggle-escape (&optional arg)
  "Toggle `!' escape syntax for REDUCE Font Lock mode (only) and re-fontify.
With arg, clear `!' escape syntax if arg >= 0 and set it if arg < 0.
For example,
\(add-hook 'reduce-mode-hook
	  (function (lambda () (reduce-font-lock-toggle-escape 1))))
will turn off the default font-lock escape syntax for `!'."
  (interactive "P")
  (require 'font-lock)
  (let ((reset font-lock-syntax-table))
    (font-lock-mode 0)
    (font-lock-set-defaults)		; resets font-lock-syntax-table
    (if arg (setq reset (< (prefix-numeric-value arg) 0)))
    (if reset
	;; `!' syntax has been reset to `escape', so do nothing:
	() ;; (setq font-lock-syntax-table nil)	; default
      ;; Set `!' syntax to punctuation:
      (setq font-lock-syntax-table
	    (copy-syntax-table reduce-mode-syntax-table))
      (modify-syntax-entry ?! "." font-lock-syntax-table)) ; punctuation
    (font-lock-mode 1)
    ;; Display message so it is not overwritten by font-lock messages:
    (message
     (if font-lock-syntax-table
	 "REDUCE Font Lock syntax (only) for `!' set to `punctuation'."
       "REDUCE Font Lock syntax table reset."))))


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
in mode line after `reduce-show-proc-delay' seconds of Emacs idle time."
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
	(if (<= (point) start)		; not in procedure
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

(defun reduce-tagify-dir (dir)
  "Generate a REDUCE TAGS file for all `.red' files in directory DIR.
By default DIR is the current directory."
  (interactive
   (list (read-directory-name
	  "Tag files in dir: "		; PROMPT
	  nil				; DIR (default cwd)
	  nil				; DEFAULT-DIRNAME
	  t				; MUSTMATCH
	  )))
  (reduce-tagify dir "*.red"))

(defun reduce-tagify-subdirs (dir)
  "Generate a REDUCE TAGS file in directory DIR for all its subdirectories.
By default DIR is the parent of the current directory."
  (interactive
   (list (read-directory-name
	  "Tag subdirs of dir: "	; PROMPT
	  (expand-file-name "..")	; DIR
	  nil				; DEFAULT-DIRNAME
	  t				; MUSTMATCH
	  )))
  (reduce-tagify dir "*/*.red"))

; (start-process			; creates an asynchronous process
;  "*rtags*"				; NAME for process
;  "*rtags-out*"			; BUFFER-OR-NAME for stdout
;  "sh"					; PROGRAM in `exec-path' to run
;  "-c"					; ARGS ...
;  "etags --lang=none '--regex=/[^%]*procedure[ \t]+\([^ \t()]+\)/\1/' $dir.red"
;  )

(defcustom reduce-etags-directory invocation-directory
  "Directory containing the etags program, or nil if it is in path.
If non-nil the string must end with /."
  :package-version '(reduce-mode . "1.54")
  :type '(choice (directory :tag "Etags program directory")
				 (const :tag "Etags is in exec path" nil))
  :group 'reduce-interface)

(defun reduce-tagify (dir files)
  "Generate a REDUCE TAGS file in directory DIR as cwd for specified FILES.
FILES can be a UNIX shell regexp."
  ;; Assumes a UNIX shell called `sh' in `exec-path'!
  ;; (Could avoid use of `sh' by constructing file list in lisp.)
  (unless (file-directory-p dir) (error "Not a directory: %s" dir))
  (setq dir (file-name-as-directory (expand-file-name dir)))
  (message "Tagging files `%s%s' ..." dir files)
  (let ((shell-file-name "sh")	       ; necessary for MS Windows etc.
		(default-directory dir))
    (set-process-sentinel
     (start-process-shell-command ; creates an asynchronous shell process
      "*rtags*"			  ; NAME for process
      "*rtags-log*"		  ; BUFFER for stdout
      (concat			  ; COMMAND: program and args
	   reduce-etags-directory
       "etags --lang=none '--regex=/[^%\n]*procedure[ \t]+\\([^ \t()]+\\)/\\1/' "
       files))
     'reduce-tagify-sentinel)))

(defun reduce-tagify-sentinel (process event)
  "Sentinel to show (primarily) when the tagification is finished."
  (message "REDUCE tagify process %s has %s."
	   process (substring event 0 -1))) ; remove trailing \n


;;;; **********************************************************************

;;; Load Hook
(defun require-reduce-run ()
  "Require the library `reduce-run'.  Useful on `reduce-mode-load-hook'."
  (require 'reduce-run))

(provide 'reduce-mode)

(run-hooks 'reduce-mode-load-hook)

;;; reduce-mode.el ends here
