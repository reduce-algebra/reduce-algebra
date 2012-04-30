;;; reduce-run.el --- Run the REDUCE computer-algebra system in a buffer

;; Copyright (C) 1998-2001, 2012 Francis J. Wright

;; Author: Francis J. Wright <http://sourceforge.net/users/fjwright>
;; Created: late 1998
;; Version: $Id$
;; Keywords: languages, processes
;; Package-Version: 1.21
;; Package-Requires: ((reduce-mode "1.21"))

;; This program is free software: you can redistribute it and/or
;; modify it under the terms of the GNU General Public License as
;; published by the Free Software Foundation, either version 3 of
;; the License, or (at your option) any later version.

;; This program is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with this program.  If not, see
;; <http://www.gnu.org/licenses/>.

;;; Commentary:

;; REDUCE run is a package for running the REDUCE computer algebra
;; system, which is Open Source and available from
;; <http://reduce-algebra.svn.sourceforge.net/>.

;; The latest version of REDUCE run is available from
;; <http://reduce-algebra.svn.sourceforge.net/viewvc/reduce-algebra/trunk/generic/emacs/>.

;; Hacked from inf-lisp.el by Olin Shivers <shivers@cs.cmu.edu>

;; This file defines a REDUCE-in-a-buffer package built on top of
;; comint mode. Since this mode is built on top of the general
;; command-interpreter-in-a-buffer mode (comint mode), it shares a
;; common base functionality, and a common set of bindings, with all
;; modes derived from comint mode. This makes these modes easier to
;; use.

;; For documentation on the functionality provided by comint mode, and
;; the hooks available for customising it, see the file comint.el.

;;; Usage:

;; To install in GNU Emacs 24+, download this file to any convenient
;; directory and run the Emacs command `package-install-file' on it.

;; REDUCE run requires `reduce-mode.el' also available from the above
;; URL, which must be installed first.

;; Brief manual installation instructions follow.

;; Byte-compile this file, put it somewhere in your `load-path', and
;; put the following in your `.emacs' file:

;; (autoload 'run-reduce "reduce-run" "Run a REDUCE process" t)

;; To have automatic access to REDUCE run from REDUCE mode, and make
;; REDUCE mode customization always available, put the following
;; (after `autoload') in your `.emacs' file:

;;;###autoload
(add-hook 'reduce-mode-load-hook 'require-reduce-run)

;;; To do:

;; phase out prompt regexp completely
;; control echoing from input of statement, proc or region?

;;; Code:

(defconst reduce-run-version
  ;; Extract version from `package-version' in file header:
  (eval-when-compile
    (require 'lisp-mnt)
    (save-excursion (lm-header "package-version")))
  "Version information for REDUCE Run.")

;; (message "Loading reduce-run")		; TEMPORARY!

;; Support from `reduce-mode' is needed both when compiling and when
;; loading!  As a "user convenience", guess that if `reduce-mode' is
;; not in `load-path' then it is in the current directory.
(eval-and-compile
  (condition-case nil
      (require 'reduce-mode)
    ('error
     (let ((load-path load-path))
       (add-to-list 'load-path ".")
       (require 'reduce-mode)
       ))))

(require 'comint)

;; Customizable user options:

(defgroup reduce-run nil
  "Support for running REDUCE code."
  :tag "REDUCE Run"
  :group 'reduce)

(defcustom reduce-run-program "reduce"
  "*Command to invoke REDUCE.
It can also be a relative or absolute path name.
It must invoke a command\-line version of REDUCE. A GUI version will not work!
If running CSL REDUCE on Windows, this should be `reduce.com' (if in your path)
or (for example) `C:/REDUCE/reduce-windows64-20110414/reduce.com'."
  :type 'string
  :group 'reduce-run)

(defcustom reduce-run-prompt "^\\([0-9]+[:*] \\)+"
  "*Regexp to recognise prompts in REDUCE Run mode.
Defaults to \"^\\([0-9]+[:*] \\)+\", which works well for CSL-REDUCE.
This variable is used to initialize `comint-prompt-regexp' in the
REDUCE Run buffer."
  :type 'regexp
  :group 'reduce-run)

(defcustom reduce-run-autostart t
  "*If non-nil, automatically start a REDUCE process if necessary."
  :type 'boolean
  :group 'reduce-run)

(defcustom reduce-run-mode-hook nil
  "*Hook for customising REDUCE Run mode."
  :type 'hook
  :group 'reduce-run)

(defcustom reduce-run-load-hook nil
  "*Hook run when REDUCE Run mode is loaded.
It is a good place to put keybindings."
  :type 'hook
  :group 'reduce-run)

(defcustom reduce-input-filter "\\`\\([ \t;$]*\\|[ \t]*.[ \t]*\\)\\'"
  "*What not to save on REDUCE Run mode's input history.
The value is a regexp. The default matches any combination of zero or
more whitespace characters and/or statement terminators, or any single
character (e.g. y or n) possibly surrounded by whitespace."
  :type 'regexp
  :group 'reduce-run)

(defcustom reduce-run-buffer nil
  "*The current REDUCE process buffer.

MULTIPLE PROCESS SUPPORT
========================================================================
To run multiple REDUCE processes, you start the first up with
\\[run-reduce].  It will be in a buffer named `*REDUCE*'.  Rename this
buffer with \\[rename-buffer].  You may now start up a new process
with another \\[run-reduce].  It will be in a new buffer, named
`*REDUCE*'.  You can switch between the different process buffers with
\\[switch-to-buffer].

Commands that send text from source buffers to REDUCE processes --
like `reduce-eval-proc' or `reduce-eval-region' -- have to choose a
process to send to, when you have more than one REDUCE process around.
This is determined by the global variable `reduce-run-buffer'.
Suppose you have three REDUCE processes running:
    Buffer              Process
    foo                 REDUCE
    bar                 REDUCE<2>
    *REDUCE*            REDUCE<3>
If you do a \\[reduce-eval-proc] command on some REDUCE source code,
what process do you send it to?

- If you're in a process buffer (foo, bar, or *REDUCE*),
  you send it to that process.
- If you're in some other buffer (e.g., a source file), you
  send it to the process attached to buffer `reduce-run-buffer'.
This process selection is performed by function `reduce-run-proc'.

Whenever \\[run-reduce] fires up a new process, it resets
`reduce-run-buffer' to be the new process's buffer.  If you only
run one process, this does the right thing.  If you run multiple
processes, you can change `reduce-run-buffer' to another process
buffer with \\[set-variable]."
  :type 'string
  :group 'reduce-run)

(defcustom reduce-source-modes '(reduce-mode)
  "*Used to determine if a buffer contains REDUCE source code.
If it's loaded into a buffer that is in one of these major modes, it's
considered a REDUCE source file by `reduce-input-file' and `reduce-fasl-file'.
Used by these commands to determine defaults."
  :type '(repeat symbol)
  :group 'reduce-run)


;; Internal variables:

(defvar reduce-run-mode-map nil)
(if reduce-run-mode-map ()
  (setq reduce-run-mode-map (copy-keymap comint-mode-map))
  (define-key reduce-run-mode-map "\C-x\C-e" 'reduce-eval-last-statement)
  (define-key reduce-run-mode-map "\C-c\C-i" 'reduce-input-file)
  (define-key reduce-run-mode-map "\C-c\C-l" 'reduce-load-package)
  (define-key reduce-run-mode-map "\C-c\C-f" 'reduce-fasl-file)
  (define-key reduce-run-mode-map "\e\t" 'reduce-complete-symbol)
  )

;; These commands augment REDUCE mode, so you can process REDUCE
;; code in the source files.
(define-key reduce-mode-map "\M-\C-x"  'reduce-eval-proc) ; Gnu convention
(define-key reduce-mode-map "\C-x\C-e" 'reduce-eval-last-statement) ; ditto
(define-key reduce-mode-map "\C-c\C-e" 'reduce-eval-proc)
(define-key reduce-mode-map "\C-c\C-r" 'reduce-eval-region)
(define-key reduce-mode-map "\C-c\C-z" 'switch-to-reduce)
(define-key reduce-mode-map "\C-c\C-i" 'reduce-input-file) ; redefines backtab
(define-key reduce-mode-map "\C-c\C-l" 'reduce-load-package)
(define-key reduce-mode-map "\C-c\C-f" 'reduce-fasl-file)
(define-key reduce-mode-map [(meta R)] 'run-reduce)

(defconst reduce-run-menu2
  '(["Input File..." reduce-input-file t]
    ["Load Package..." reduce-load-package t]
    ["Faslout File..." reduce-fasl-file t]
    "--"))

(easy-menu-define			; (symbol maps doc menu)
 reduce-run-menu
 reduce-run-mode-map
 "REDUCE Run Menu"
 `("Run REDUCE"
   ,@reduce-run-menu2
   ["Re-Run REDUCE" re-run-reduce t]
   ["Customize..." (customize-group 'reduce-run) t]
   ["Highlighting" font-lock-mode
    :style toggle :selected font-lock-mode :active t]
   ))

(easy-menu-define			; (symbol maps doc menu)
 reduce-mode-run-menu
 nil
 "REDUCE Mode Run Menu"
 `("Run REDUCE"
   ["Run REDUCE" run-reduce t]
   "--"
   ["Input Last Statement" reduce-eval-last-statement t]
   ["Input Procedure" reduce-eval-proc t]
   ["Input Region" reduce-eval-region mark-active]
   "--"
   ,@reduce-run-menu2
   ["Switch To REDUCE" switch-to-reduce t]
   "--"
   ["Show Version" reduce-run-show-version :active t
    :help "Show the REDUCE Run version"]
   ))

(defun reduce-run-show-version ()
  "Echo version information for REDUCE Run."
  (interactive)
  (message "REDUCE Run version: %s" reduce-run-version))

;; Put the Run REDUCE menu on the menu bar AFTER the REDUCE menu:
(define-key-after
  (lookup-key reduce-mode-map [menu-bar])
  [Run\ REDUCE]
  (cons "Run REDUCE" reduce-mode-run-menu) 'REDUCE)

(defun reduce-run-install-letter-bindings ()
  "Bind many REDUCE run commands to C-c <letter> bindings.
This makes them more accessible. These bindings are reserved for
the user and so are non-standard. If you want to use them, you
should have this function called by the `reduce-run-load-hook':
   (add-hook 'reduce-run-load-hook
             'reduce-run-install-letter-bindings)
You can modify this function to install just the bindings you want."
  (define-key reduce-mode-map "\C-ce" 'reduce-eval-proc)
  (define-key reduce-mode-map "\C-cr" 'reduce-eval-region)
  (define-key reduce-mode-map "\C-cz" 'switch-to-reduce)
  (define-key reduce-mode-map "\C-ci" 'reduce-input-file)
  (define-key reduce-mode-map "\C-cl" 'reduce-load-package)
  (define-key reduce-mode-map "\C-cf" 'reduce-fasl-file)
  (define-key reduce-run-mode-map "\C-cl" 'reduce-load-package)
  (define-key reduce-run-mode-map "\C-cf" 'reduce-fasl-file)
  )

(defconst reduce-run-font-lock-keywords
  '(;; REDUCE and CSL warning and error messages:
    ("\\(\\*\\*\\*\\|\\+\\+\\+\\).*" . font-lock-warning-face)
    ;; Rtrace output:
    ("^\\(Enter\\|Leave\\) ([0-9]+) [^ \n]+\\( =\\)?" . font-lock-warning-face)
    ("^Rule.*:" . font-lock-warning-face)
    ;; CSL trace output:
    ("^\\(Entering .*\\| *Arg[0-9]+:\\|Value = \\)" . font-lock-warning-face))
  "Syntax highlighting for running REDUCE.")

;; Prevent new buffers inheriting this mode:
(put 'reduce-run-mode 'mode-class 'special)


(defun reduce-run-mode ()
  "Major mode for interacting with a REDUCE process -- part of REDUCE IDE.
Author: Francis Wright <http://sourceforge.net/users/fjwright>
Version: see `reduce-run-version'
Comments, suggestions, bug reports, etc. are welcome.
Full texinfo documentation is provided in the file `reduce-ide.texinfo'.

Runs REDUCE as a subprocess of Emacs, with I/O through an Emacs
buffer. Variable `reduce-run-program' controls which REDUCE is
run. Variable `reduce-run-prompt' can customize this mode for
different REDUCE implementations.

For information on running multiple processes in multiple buffers, see
documentation for variable `reduce-run-buffer'.

\\{reduce-run-mode-map}

Customisation: Entry to this mode runs the hooks on `comint-mode-hook'
and `reduce-run-mode-hook' (in that order).

You can send text to the REDUCE process from other buffers containing
REDUCE source:
 * switch-to-reduce switches the current buffer to the REDUCE process
   buffer;
 * reduce-eval-proc sends the current procedure definition to the
   REDUCE process;
 * reduce-eval-region sends the current region to the REDUCE process.
Prefixing the reduce-eval- commands with a \\[universal-argument]
also switches to the REDUCE process buffer window.

Commands:
 * Return after the end of the process' output sends the text from the
   end of process to point.
 * Return before the end of the process' output copies the statement
   ending at point to the end of the process' output, and sends it.
 * Delete converts tabs to spaces as it moves back.
 * \\[reduce-indent-line] indents for REDUCE; with argument,
   shifts rest of expression rigidly with the current line.
 * \\[reduce-indent-procedure] does `reduce-indent-line' on each
   line starting within following expression.
Paragraphs are separated only by blank lines. Percent signs start comments.
If you accidentally suspend your process, use \\[comint-continue-subjob]
to continue it."
  (interactive)
  (kill-all-local-variables)
  (comint-mode)
  (set (make-local-variable 'comint-use-prompt-regexp) nil)
  (setq major-mode 'reduce-run-mode)
  (setq mode-name "REDUCE Run")
  (setq mode-line-process '(":%s"))
  (reduce-mode-variables)
  (set (make-local-variable 'font-lock-defaults)
       '(reduce-run-font-lock-keywords	; KEYWORDS
	 t				; KEYWORDS-ONLY
	 ))
  (use-local-map reduce-run-mode-map)
  (setq comint-input-filter (function reduce-input-filter))
  (setq comint-input-ignoredups t)
;   (add-hook 'comint-preoutput-filter-functions
; 	    'reduce-preoutput-filter-function)
  (MS-DOS-reduce-fix)
  (run-hooks 'reduce-run-mode-hook))

(defun reduce-input-filter (str)
  "True if STR does not match `reduce-input-filter'."
  (not (string-match reduce-input-filter str)))

; (defun reduce-preoutput-filter-function (string)
;   "Make prompts `read-only', `intangible' and `rear-nonsticky';
; hung on `comint-preoutput-filter-functions'."
;   (if (string-match reduce-run-prompt string)
;       (add-text-properties
;        (match-beginning 0) (match-end 0)
;        '(read-only t intangible t rear-nonsticky t)
;        string))
;   string)

;;;###autoload
(defun run-reduce (cmd)
  "Run CMD as a REDUCE process with input and output via buffer `*REDUCE*'.
If there is a process already running in `*REDUCE*', just switch to
that buffer.  With argument, allows you to edit the command line
\(default is value of `reduce-run-program'). Runs the hooks from
`reduce-run-mode-hook' (after the `comint-mode-hook' is run).
\(Type \\[describe-mode] in the process buffer for a list of
commands.)"
  (interactive (list (if current-prefix-arg
			 (read-string "Run REDUCE: " reduce-run-program)
		       reduce-run-program)))
  (if (not (comint-check-proc "*REDUCE*"))
      (let ((cmdlist (reduce-run-args-to-list cmd)))
	(set-buffer
	 ;; `apply' used below because last arg is &rest!
	 (apply 'make-comint "REDUCE" (car cmdlist) nil (cdr cmdlist)))
	(reduce-run-mode)))
  (setq reduce-run-buffer "*REDUCE*")
  (pop-to-buffer "*REDUCE*"))

;;;###autoload
(add-hook 'same-window-buffer-names "*REDUCE*")

(defun reduce-run-args-to-list (string)
  "Break STRING into a list of arguments.
This will fail if you have an argument with whitespace, as in
string = \"-ab +c -x 'you lose'\"."
  (let ((where (string-match "[ \t]" string)))
    (cond ((null where) (list string))
	  ((not (= where 0))
	   (cons (substring string 0 where)
		 (reduce-run-args-to-list
		  (substring string (+ 1 where) (length string)))))
	  (t (let ((pos (string-match "[^ \t]" string)))
	       (if (null pos)
		   ()
		 (reduce-run-args-to-list
		  (substring string pos (length string)))))))))


(defun reduce-send-string (string)
  "Send STRING to the REDUCE process.
Echo and save it in the input history."
  (switch-to-reduce t t)
  (insert string)
  (comint-send-input))

(defun reduce-send-region (start end)
  "Send region from START to END to the REDUCE process.
Switch to the REDUCE buffer, echo a possibly shortened version and
save it in the input history."
  (let ((region (buffer-substring-no-properties start end))
	(START 0) (lines 1) reg
	(comint-input-sender-old comint-input-sender))
    ;; Delete all leading and trailing newlines from region:
    (while (eq (aref region 0) ?\n)
      (setq region (substring region 1)))
    (while (eq (aref region (1- (length region))) ?\n)
      (setq region (substring region 0 -1)))
    ;; reg := region shortened if more than 3 lines:
    (while (and (<= lines 3)
		(setq START (string-match "\n" region (1+ START))))
      (setq lines (1+ lines)))
    (setq reg
	  (if (> lines 3)
	      (replace-regexp-in-string
	       "\\(.*\n\\)\\(\\(.*\n\\)*.*\\)\n"
	       "%\\1%   ...\n%" region t)
	    region))
    (switch-to-reduce t t)
    (insert reg)
    ;; Send full region to REDUCE, but replace all newlines (and any
    ;; preceding comments!) with spaces to avoid multiple REDUCE
    ;; propmts:
    (setq region
	  (replace-regexp-in-string "\\(%.*\\)?\n" " " region t t))
    ;; Hack sender to actually send region!  This ugly code is
    ;; necessary (?) because `comint-input-sender' is a buffer local
    ;; variable.
    (setq comint-input-sender
	  (lambda (proc string)
	    (comint-simple-send (reduce-run-proc) region)))
    (comint-send-input)
    (setq comint-input-sender comint-input-sender-old)))

(defun reduce-eval-region (start end switch)
  "Send the current region, from START to END, to the REDUCE process.
Prefix argument SWITCH means also switch to the REDUCE window."
  (interactive "r\nP")
  (if switch
      (reduce-send-region start end)
    (save-selected-window (reduce-send-region start end))))

(defun reduce-eval-last-statement (switch)
  "Send the previous statement to the REDUCE process.
Prefix argument SWITCH means also switch to the REDUCE window."
  (interactive "P")
  (let ((fn '(reduce-send-region
	      (save-excursion (reduce-backward-statement 1) (point))
	      (point))))
    (if switch
	(eval fn)
      (save-selected-window (eval fn)))))

(defun reduce-eval-proc (switch)
  "Send the current procedure definition to the REDUCE process.
Prefix argument SWITCH means also switch to the REDUCE window."
  ;; cf. reduce-mark-procedure
  (interactive "P")
  (save-excursion
    (let ((start (point)))
      (reduce-forward-procedure 1)
      (unless (= (point) start)
	(skip-chars-forward " \t\n")	; skip trailing white space
	(let ((end (point)))
	  (reduce-backward-procedure 1)
	  (if switch
	      (reduce-send-region (point) end)
	    (save-selected-window
	      (reduce-send-region (point) end)))
	)))))

(defun reduce-running-bufferp ()
  "True if current buffer is running a REDUCE process."
  (and (eq major-mode 'reduce-run-mode)
       (get-buffer-process (current-buffer))))

(defun switch-to-reduce (eob-p &optional no-mark)
  "Go to REDUCE process buffer, at end if EOB-P; if NO-MARK do not save mark.
With argument, position cursor at end of buffer.
If `reduce-run-autostart' is non-nil then automatically start a REDUCE
process if necessary."
  ;; Optional argument no-mark is for internal use: do not save mark.
  (interactive "P")
  (let (restart)
    (and reduce-run-buffer
	 (get-buffer reduce-run-buffer)
	 (let ((pop-up-frames
		;; Be willing to use another frame
		;; that already has the window in it.
		(or pop-up-frames
		    (get-buffer-window reduce-run-buffer t))))
	   (pop-to-buffer reduce-run-buffer)
	   (setq restart t)
	   (when (and eob-p (not (eobp)))
	     (or no-mark (push-mark))
	     (goto-char (point-max)))))
    (cond ((reduce-running-bufferp))
	  (reduce-run-autostart
	   (when restart
	     (goto-char (point-max))
	     (insert ?\n))
	   (run-reduce reduce-run-program)
	   ;; Wait for REDUCE to start ...
	   (while (not (comint-check-proc "*REDUCE*"))
	     (sit-for 1))
	   ;; and then wait for first REDUCE prompt:
	   (while (save-excursion
		    ;; (beginning-of-line)
		    ;; Unlike `beginning-of-line', forward-line ignores field
		    ;; boundaries (cf. `comint-bol')
		    (forward-line 0)
		    (or (eobp) (/= (char-after) ?1)))
	     (sit-for 1)))
	  (t (error "No current REDUCE Run buffer")))))

(defun re-run-reduce ()
  "Re-run REDUCE in the current buffer, killing it first if necessary."
  (interactive)
  (goto-char (point-max))
  (when (reduce-running-bufferp)
    (insert "bye\;")			; to show termination explicitly!
    (comint-send-input)
    (sit-for 1))
  (insert ?\n)
  (call-interactively 'run-reduce))


(defvar reduce-prev-dir/file nil
  "Record last directory and file used in inputting or compiling.
This holds a cons cell of the form `(DIRECTORY . FILE)' describing the
last `reduce-input-file' or `reduce-fasl-file' command.")

(defvar reduce-prev-package nil
  "Name of last package loaded or compiled.")

(defvar reduce-run-file-name-history nil
     "A history list for reduce-run source file-name arguments.")

(defun reduce-run-get-source (prompt)
  "Get, check and save a REDUCE source file-name using prompt string PROMPT."
  ;; Need to rewrite this messy function!
  (let* ((file-name-history reduce-run-file-name-history)
	 (file-name
	  (car (comint-get-source prompt reduce-prev-dir/file
				  reduce-source-modes t))))
    (comint-check-source file-name)  ; Check to see if buffer should be saved.
    (setq reduce-prev-dir/file (cons (file-name-directory file-name)
				     (file-name-nondirectory file-name)))
    ;; Save filenames in MRU order, once only:
    (setq reduce-run-file-name-history
	  (cons file-name (delete file-name (cdr file-name-history))))
    (list file-name)			; Yuk!
    ))

(defun reduce-input-file (file-name)
  "Input REDUCE source file FILE-NAME into the REDUCE process.
The user chooses whether to echo file input."
  (interactive (reduce-run-get-source "Input REDUCE file: "))
  (reduce-send-string
   (format "in \"%s\"%c" file-name
	   (if (y-or-n-p "Echo file input? ") ?\; ?$))))

(defun reduce-wait-for-prompt ()
  "Wait for REDUCE prompt."
  (save-excursion
    (pop-to-buffer reduce-run-buffer)
    (while (progn
	     (goto-char (point-max))
	     ;; (beginning-of-line)
	     ;; Unlike `beginning-of-line', forward-line ignores field
	     ;; boundaries (cf. `comint-bol')
	     (forward-line 0)
	     (not (looking-at reduce-run-prompt)))
      (sit-for 1))))

(defalias 'reduce-compile-file 'reduce-fasl-file)

(defun reduce-fasl-file (file-name)
  "Compile REDUCE source file FILE-NAME to a FASL image in the REDUCE process.
The user chooses whether to echo file input."
  (interactive (reduce-run-get-source "Compile REDUCE file: "))
  (let* ((fasl-name (file-name-sans-extension (cdr reduce-prev-dir/file)))
	 (fasl-name (read-minibuffer "FASL name: " fasl-name)))
    (reduce-send-string (format "faslout %s;" fasl-name))
    (reduce-wait-for-prompt)
    (reduce-input-file file-name)
    (reduce-wait-for-prompt)
    (reduce-send-string "faslend;")
    (setq reduce-prev-package fasl-name))
  (switch-to-reduce t))

(defun reduce-packages-default ()
  "Return REDUCE packages file or directory or nil if neither can be found."
  (let ((dir (getenv "REDUCE")) result)
    (setq dir (if dir
		  (expand-file-name dir)
		"/reduce"))		; default
    (cond ((file-readable-p
	    (setq result (concat dir "/package.ini")))
	   result)
	  ((file-accessible-directory-p
	    (setq result (concat dir "/packages/")))
	   result))))

(defvar reduce-package-completion-alist nil
  "Alist of REDUCE packages used for completion by `reduce-load-package'.
Not intended to be set directly but by customizing `reduce-packages'.")

(defcustom reduce-packages (reduce-packages-default)
  "*File, directory or list of REDUCE packages, or nil.
The file should be \"reduce/package.ini\", the directory should be
\"reduce/packages/\", but absolute pathnames should be used.
For a file or directory, you can complete with `M-<TAB>'.
Used for completion by `reduce-load-package'."
  ;; Can this be set by querying REDUCE?
  :type '(choice
 	  (const :tag "none" nil)
 	  (file :tag "file" :value "/reduce/package.ini")
 	  (directory :tag "directory" :value "/reduce/packages/")
	  (repeat string))
  :group 'reduce-run
  :set (lambda (symbol value)
	 (let (packages)
	   (if (stringp value)
	       (if (file-readable-p value)
		   (if (file-directory-p value)
		       (setq packages
			     (delete "TAGS"
				     (directory-files value nil "\\`[^.]")))
		     (with-temp-buffer
		       (insert-file-contents value)
		       (while (re-search-forward "\\[\\(.*?\\)\\]" nil t)
			 (setq packages (cons (match-string 1) packages)))))
		 (error "File or directory must exist and be readable"))
	     (setq packages value))
	   (setq reduce-package-completion-alist
		 (and packages (mapcar 'list packages)))
	   (set-default symbol value))))

(defun reduce-load-package (package)
  "Load Reduce package PACKAGE into the REDUCE process."
  (interactive
   (let ((default
	   (or (and reduce-prev-package
		    (if (symbolp reduce-prev-package)
			(symbol-name reduce-prev-package)
		      reduce-prev-package))
	       (cdr reduce-prev-dir/file)
	       (and (memq major-mode reduce-source-modes)
		    buffer-file-name    ; might be a dissociated buffer!
		    (file-name-nondirectory buffer-file-name))))
	 prompt)
     (if default
	 (setq default (file-name-sans-extension default)))
     (setq prompt
	   (if default
	       (format "Load REDUCE package (default %s): " default)
	     "Load REDUCE package: "))
     (list
      (completing-read
       prompt
       reduce-package-completion-alist
       nil				; predicate
       nil				; require-match
       nil				; initial
       nil				; hist
       default)
      )))
  (reduce-send-string (format "load_package %s;" package))
  (setq reduce-prev-package package)
  (switch-to-reduce t))



;;; Ancillary functions
;;; ===================

;; Temporary fixes for some functions in comint.el!

;; Also, the help-echo (see `comint-send-input') would be much clearer
;; if it read something like: "mouse-2: insert after prompt as new
;; input to be edited."  cf. the documentation for
;; `comint-copy-old-input'.  [Reported]

(defun comint-insert-clicked-input (event)
  "Set current comint buffer input to previous via clicked mouse event EVENT."
  (interactive "e")
  (let ((over (catch 'found
		;; Ignore non-input overlays
		(dolist (ov (overlays-at (posn-point (event-end event))))
		  (when (eq (overlay-get ov 'field) 'input)
		    (throw 'found ov))))))
    ;; Do we have input in this area?
    (if over
	(let ((input-str (buffer-substring (overlay-start over)
					   (overlay-end over))))
	  (goto-char (point-max))	; FJW
	  (delete-region
	   ;; Can't use kill-region as it sets this-command
	   (or  (marker-position comint-accum-marker)
		(process-mark (get-buffer-process (current-buffer))))
	   (point))
	  (insert input-str))
      ;; Fall back to the global definition.
      (let* ((keys (this-command-keys))
	     (last-key (and (vectorp keys) (aref keys (1- (length keys)))))
	     (fun (and last-key (lookup-key global-map (vector last-key)))))
	(if fun (call-interactively fun))))))


(defun reduce-run-proc ()
  "Return the current REDUCE process.
See variable `reduce-run-buffer'.
If `reduce-run-autostart' is non-nil then automatically start a REDUCE
process if necessary."
  (let ((proc (get-buffer-process (if (eq major-mode 'reduce-run-mode)
				      (current-buffer)
				    reduce-run-buffer))))
    (cond (proc)
	  (reduce-run-autostart
	   (save-excursion
	     (run-reduce reduce-run-program)
	     (get-buffer-process (current-buffer))))
	  (t (error "No REDUCE process; see variable `reduce-run-buffer'")))))

;; The MS-DOS shell COMMAND.COM does not transmit signals, so add
;; support for terminating the REDUCE process explicitly.

(defun reduce-send-bye (proc)
  "Send PROC the string `bye;'."
  (process-send-string proc "bye\;\n"))

(defun reduce-kill-buffer ()
  "Hang on `kill-buffer-hook' to terminate the REDUCE process."
  (if (eq major-mode 'reduce-run-mode)
      (let ((proc (get-buffer-process (current-buffer))))
	(if proc (reduce-send-bye proc)))))

(defun reduce-processp (proc)
  "True if PROC is a REDUCE process."
  (save-excursion
    (and (setq proc (process-buffer proc))
	 (set-buffer proc)
	 (eq major-mode 'reduce-run-mode))))

(defun reduce-kill-emacs ()
  "Hang on `kill-emacs-hook' to terminate the REDUCE process."
  (mapcar (function
	   (lambda (proc)
	     ;; If PROC is a REDUCE process then send it the string `bye;'
	     ;; and pause to allow it to take effect (before Emacs dies).
	     (cond ((reduce-processp proc)
		    (reduce-send-bye proc)
		    ;; The time may need tuning on different systems.
		    ;; For me, anything less than 1 second is unreliable.
		    (sit-for 1 t)	; no redisplay
		    ))))
	  (process-list)))

(defun MS-DOS-reduce-fix ()
  "Install MS-DOS support if appropriate."
  (cond ((string-match "cmdproxy" shell-file-name) ; case sensitive!
	 (add-hook 'kill-buffer-hook 'reduce-kill-buffer)
	 (add-hook 'kill-emacs-hook 'reduce-kill-emacs)
	 ;; (add-hook 'comint-output-filter-functions
		   ;; 'shell-strip-ctrl-m nil t)
	 ;; (setq comint-process-echoes t)
	 )))


;;; Do the user's customisation...
;;; ==============================

(provide 'reduce-run)

(run-hooks 'reduce-run-load-hook)

;;; reduce-run.el ends here
