;;; reduce-run.el --- Run the REDUCE computer-algebra system in a buffer

;; Copyright (C) 1998-2001, 2012, 2017, 2018 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Created: late 1998
;; Version: $Id$
;; Keywords: languages, processes
;; Homepage: http://reduce-algebra.sourceforge.net/reduce-ide
;; Package-Version: 1.54
;; Package-Requires: ((reduce-mode "1.5"))

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
;; along with this program.  If not, see <https://www.gnu.org/licenses/>.

;;; Commentary:

;; REDUCE Run is a package for running the REDUCE computer algebra
;; system, which is Open Source and available from
;; <https://sourceforge.net/projects/reduce-algebra>.

;; The latest version of REDUCE Run is available from
;; <https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs>.

;; Hacked from inf-lisp.el by Olin Shivers <shivers@cs.cmu.edu>

;; This file defines a REDUCE-in-a-buffer package built on top of
;; comint mode.  Since this mode is built on top of the general
;; command-interpreter-in-a-buffer mode (comint mode), it shares a
;; common base functionality, and a common set of bindings, with all
;; modes derived from comint mode.  This makes these modes easier to
;; use.

;; For documentation on the functionality provided by comint mode, and
;; the hooks available for customising it, see the file comint.el.

;; Usage:

;; To install in GNU Emacs 24+, download this file to any convenient
;; directory and run the Emacs command `package-install-file' on it.

;; REDUCE Run requires `reduce-mode.el' also available from the above
;; URL, which must be installed first.

;; Brief manual installation instructions follow.

;; Byte-compile this file, put it somewhere in your `load-path', and
;; put the following in your `.emacs' file:

;; (autoload 'run-reduce "reduce-run" "Run a REDUCE process" t)

;; To have automatic access to REDUCE Run from REDUCE Mode, and make
;; REDUCE Mode customization always available, put the following
;; (after `autoload') in your `.emacs' file:

;;;###autoload
(add-hook 'reduce-mode-load-hook 'require-reduce-run)

;;; Code:

;;; To do:

;; phase out prompt regexp completely
;; control echoing from input of statement, proc or region?


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
       (require 'reduce-mode)))))

(require 'comint)

;;; Customizable user options
;;; =========================

(defgroup reduce-run nil
  "Support for running REDUCE code."
  :tag "REDUCE Run"
  :group 'reduce)

(make-obsolete-variable
 'reduce-run-program
 "This variable has been replaced by `reduce-run-commands' with different syntax."
 "1.3")

(defcustom reduce-run-commands
  (if (eq system-type 'windows-nt)
	  (list '("CSL" . "c:/Program Files/Reduce/bin/redcsl.bat --nogui")
			(cons "PSL"
				  (let ((file (or load-file-name (buffer-file-name))))
					;; file can be nil if REDUCE Run mode is customized
					;; before it is otherwise used!
					(if file
						(setq file (concat (file-name-directory file)
										   "reduce-run-redpsl.bat")))
					(if (and file (file-exists-p file))
						file
					  "c:/Program Files/Reduce/bin/redpsl.bat"))))
	'(("CSL" "redcsl --nogui") ("PSL" "redpsl")))
  "Alist of commands to invoke CSL and PSL REDUCE in preference order.
The commands can also be absolute path names, and they can include switches.
They must invoke a command\-line version of REDUCE.  A GUI version will not work!
The command `run-reduce' tries to run REDUCE on the first Lisp.
If that fails then it tries to run REDUCE on the second Lisp."
  :type '(alist :key-type (choice (const "CSL") (const "PSL")) :value-type string)
  :group 'reduce-run)

(defcustom reduce-run-prompt "^\\([0-9]+[:*] \\)+"
  "Regexp to recognise prompts in REDUCE Run mode.
Defaults to \"^\\([0-9]+[:*] \\)+\", which works well for CSL-REDUCE.
This variable is used to initialize `comint-prompt-regexp' in the
REDUCE Run buffer."
  :type 'regexp
  :group 'reduce-run)

(defcustom reduce-run-autostart t
  "If non-nil, automatically start a REDUCE process if necessary."
  :type 'boolean
  :group 'reduce-run)

(defcustom reduce-run-multiple t
  "If non-nil, always start a new REDUCE process in a new distinct buffer.
Do this even if REDUCE is already running.
If nil, re-use any appropriate running REDUCE process."
  :type 'boolean
  :group 'reduce-run)

(defcustom reduce-run-mode-hook nil
  "Hook for customising REDUCE Run mode."
  :type 'hook
  :group 'reduce-run)

(defcustom reduce-run-load-hook nil
  "Hook run when REDUCE Run mode is loaded.
It is a good place to put keybindings."
  :type 'hook
  :group 'reduce-run)

(defcustom reduce-input-filter "\\`\\([ \t;$]*\\|[ \t]*.[ \t]*\\)\\'"
  "What not to save on REDUCE Run mode's input history.
The value is a regexp.  The default matches any combination of zero or
more whitespace characters and/or statement terminators, or any single
character (e.g. y or n) possibly surrounded by whitespace."
  :type 'regexp
  :group 'reduce-run)

(defcustom reduce-source-modes '(reduce-mode)
  "Used to determine if a buffer contains REDUCE source code.
If it's loaded into a buffer that is in one of these major modes, it's
considered a REDUCE source file by `reduce-input-file' and `reduce-fasl-file'.
Used by these commands to determine defaults."
  :type '(repeat symbol)
  :group 'reduce-run)


;;; Internal variables
;;; ==================

(defvar reduce-run-buffer-alist nil
  "This variable holds an alist of REDUCE process buffers (RPBs),
which is used to name new RPBs appropriately and decide where to
send REDUCE input.")

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
;; code in file editing buffers.
(define-key reduce-mode-map "\M-\C-x"  'reduce-eval-proc) ; Emacs convention
(define-key reduce-mode-map "\C-x\C-e" 'reduce-eval-last-statement) ; ditto
(define-key reduce-mode-map "\C-c\C-e" 'reduce-eval-proc)
(define-key reduce-mode-map "\C-c\C-r" 'reduce-eval-region)
(define-key reduce-mode-map "\C-c\C-z" 'switch-to-reduce)
(define-key reduce-mode-map "\C-c\C-i" 'reduce-input-file)
(define-key reduce-mode-map "\C-c\C-l" 'reduce-load-package)
(define-key reduce-mode-map "\C-c\C-f" 'reduce-fasl-file)
(define-key reduce-mode-map [(meta R)] 'run-reduce)

(defconst reduce-run-menu2
  '(["Input File..." reduce-input-file t]
    ["Load Package..." reduce-load-package t]
    ["Faslout File..." reduce-fasl-file t]
    "--"))

(easy-menu-define						; (symbol maps doc menu)
  reduce-run-menu
  reduce-run-mode-map
  "REDUCE Run Menu"
  `("Run REDUCE"
	,@reduce-run-menu2
	["Re-Run REDUCE" re-run-reduce :active t
	 :help "Stop a running REDUCE process and then restart REDUCE"]
	["Run File" reduce-run-file :active t
	 :help "Run a file in a new REDUCE process"]
	["Customize..." (customize-group 'reduce-run) :active t
	 :help "Customize REDUCE Run mode"]
	["Highlighting" font-lock-mode
     :style toggle :selected font-lock-mode :active t
	 :help "Toggle the highlighting in this buffer"]
	))

(easy-menu-define						; (symbol maps doc menu)
  reduce-mode-run-menu
  nil
  "REDUCE Mode Run Menu"
  `("Run REDUCE"
	["Run REDUCE" run-reduce :active t
	 :help "Start a new REDUCE process if necessary"]
	["Run Buffer" reduce-run-buffer :active t
	 :help "Run the current buffer in a new REDUCE process"]
	"--"
	["Input Last Statement" reduce-eval-last-statement :active t
	 :help "Input the statement before point to a REDUCE process"]
	["Input Procedure" reduce-eval-proc :active t
	 :help "Input the procedure containing point to a REDUCE process"]
	["Input Region" reduce-eval-region :active mark-active
	 :help "Input the selected region to a REDUCE process"]
	"--"
	,@reduce-run-menu2
	["Switch To REDUCE" switch-to-reduce :active t
	 :help "Select and switch to a REDUCE process"]
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
  "Bind many REDUCE run commands to `C-c' <letter> bindings.
This makes them more accessible.  These bindings are reserved for
the user and so are non-standard.  If you want to use them, you
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


;;; Functions to run REDUCE in a buffer
;;; ===================================

(defun reduce-run-mode ()
  "Major mode for interacting with a REDUCE process -- part of REDUCE IDE.
Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
Version: see `reduce-run-version'.
Comments, suggestions, bug reports, etc., are welcome.
Full texinfo documentation is provided in the file `reduce-ide.texinfo'.

Run REDUCE as a subprocess of Emacs, with I/O through an Emacs buffer.

Customisation: Variables in the customization group `reduce-run'
control this mode.  Entry to this mode runs `comint-mode-hook'
and then `reduce-run-mode-hook'.

\\{reduce-run-mode-map}

There can be more than one buffer in REDUCE Run mode, in which
case relevant commands allow you to choose which buffer to use,
and you can send text to a selected REDUCE process from other
buffers containing REDUCE source:
 * ‘switch-to-reduce’ switches the current buffer to the selected
   REDUCE process buffer;
 * ‘reduce-eval-proc’ sends the current procedure definition to
   the selected REDUCE process;
 * ‘reduce-eval-region’ sends the current region to the selected
   REDUCE process.
Prefixing the reduce-eval- commands with a \\[universal-argument]
also switches to the selected REDUCE process buffer window.

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
Paragraphs are separated only by blank lines.  Percent signs start comments.
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
	 t									; KEYWORDS-ONLY
	 ))
  (use-local-map reduce-run-mode-map)
  (setq comint-input-filter (function reduce-input-filter))
  (setq comint-input-ignoredups t)
  ;; ansi-color-process-output causes an error when CSL is terminated
  ;; and is probably irrelevant anyway, so ...
  (set (make-local-variable 'comint-output-filter-functions)
	   (delq 'ansi-color-process-output comint-output-filter-functions))
  ;; Try to ensure graceful shutdown. In particular, PSL REDUCE on
  ;; Windows seems to object to being killed!
  (add-hook 'kill-buffer-hook 'reduce-kill-buffer-tidy-up)
  (add-hook 'kill-emacs-hook 'reduce-kill-emacs-tidy-up)
  (run-hooks 'reduce-run-mode-hook))

(defun reduce-input-filter (str)
  "True if STR does not match variable `reduce-input-filter'."
  (not (string-match reduce-input-filter str)))

;;;###autoload
(defun run-reduce (&optional cmd)
  "Run CMD as a REDUCE process with input and output via a buffer.
If CMD omitted or nil, use whichever REDUCE appears first in `reduce-run-commands'.
If `reduce-run-multiple' in non-nil then always start a new distinct REDUCE process,
Otherwise, if there is a REDUCE process already running, just switch to it.
Runs the hooks from `reduce-run-mode-hook' (after the
`comint-mode-hook' is run).  (Type \\[describe-mode] in the
process buffer for a list of commands.)"
  (interactive
   (let ((reduce-run-command (cdar reduce-run-commands)))
	 (list (if current-prefix-arg
			   (read-string "Run REDUCE: " reduce-run-command)
			 reduce-run-command))))
  (if cmd
	  ;; Run the specified command:
	  (if current-prefix-arg
		  (reduce-run-reduce cmd "")	; unknown REDUCE version
		(reduce-run-reduce cmd (caar reduce-run-commands))) ; default REDUCE version
	;; Automatic mode:
	(or (reduce-run-reduce (cdar reduce-run-commands) (caar reduce-run-commands))
		(reduce-run-reduce (cdadr reduce-run-commands) (caadr reduce-run-commands)))))

;;;###autoload
(defun run-csl-reduce ()
  "Run CSL REDUCE with I/O via a buffer with a name like `*CSL\ REDUCE*'.
The appropriate command is taken from `reduce-run-commands'.
If `reduce-run-multiple' in non-nil then always start a new distinct REDUCE process,
Otherwise, if there is a CSL REDUCE process already running, just switch to it.
Runs the hooks from `reduce-run-mode-hook' (after the
`comint-mode-hook' is run).  (Type \\[describe-mode] in the
process buffer for a list of commands.)"
  (interactive)
  (reduce-run-reduce (cdr (assoc "CSL" reduce-run-commands)) "CSL"))

;;;###autoload
(defun run-psl-reduce ()
  "Run PSL REDUCe with I/O via a buffer with a name like `*PSL\ REDUCE*'.
If `reduce-run-multiple' in non-nil then always start a new distinct REDUCE process,
Otherwise, if there is a PSL REDUCE process already running, just switch to it.
Runs the hooks from `reduce-run-mode-hook' (after the
`comint-mode-hook' is run).  (Type \\[describe-mode] in the
process buffer for a list of commands.)"
  (interactive)
  (reduce-run-reduce (cdr (assoc "PSL" reduce-run-commands)) "PSL"))

(defun reduce-run-reduce (cmd xsl)
  "Run CMD as an XSL REDUCE process with I/O via buffer `*XSL\ REDUCE*'.
If there is a process already running in that buffer, just switch to it.
XSL must be one of the strings `\"CSL\"', `\"PSL\"' or `\"\"'.
Return t if successful; nil otherwise."
  (let* ((proc-name (if (equal xsl "") "REDUCE" (concat xsl " REDUCE")))
		 (buf-name (concat "*" proc-name "*"))
		 (reduce-run-buffer-xsl (assoc xsl reduce-run-buffer-alist))
		 buf-number)
	(cond (reduce-run-multiple
		   ;; Always create a new process buffer with an appropriate name:
		   (if reduce-run-buffer-xsl
			   (setq buf-number (1+ (or (nth 2 reduce-run-buffer-xsl) 0))
					 proc-name (concat proc-name " "
									   (number-to-string buf-number))
					 buf-name (concat "*" proc-name "*")))
		   (when (reduce-run-reduce-1 cmd proc-name buf-name)
			 (push (list xsl buf-name buf-number) reduce-run-buffer-alist)
			 t))
		  ;; Re-use any existing buffer for XSL REDUCE:
		  ((and reduce-run-buffer-xsl
				(string-match proc-name (cdr reduce-run-buffer-xsl))
				(comint-check-proc buf-name))
		   (pop-to-buffer buf-name)) ; just re-visit this process buffer
		  (t (when (reduce-run-reduce-1 cmd proc-name buf-name)
			   (push (list xsl buf-name) reduce-run-buffer-alist)
			   t)))))

;; Try forcing the use of a shell by replacing the use of
;; (start-file-process name buffer-or-name program &rest args) with
;; (start-file-process-shell-command name buffer-or-name command) in
;; make-comint.

(defun reduce-run-reduce-1 (cmd process-name buffer-name)
  "Run CMD as a REDUCE process PROCESS-NAME in buffer BUFFER-NAME.
Return the process buffer if successful; nil otherwise."
  (condition-case err
      ;; Protected form:
	  (let ((cmdlist (reduce-run-args-to-list cmd)))
		;; Hack to try to run PSL on native Windows GNU Emacs:
		;; (fset 'start-file-process
		;; 	  (lambda (name buffer-or-name program &rest args)
		;; 		(start-file-process-shell-command
		;; 		 name buffer-or-name
		;; 		 (mapconcat identity (cons program args) " "))))
		(set-buffer
		 ;; `apply' used below because last arg is &rest!
		 (apply 'make-comint process-name (car cmdlist) nil (cdr cmdlist)))
		(reduce-run-mode)
		(pop-to-buffer buffer-name))
    ;; Error handler:
    (error			  ; condition
     ;; Display the usual error message then tidy up:
     (message "%s" (error-message-string err))
	 (kill-buffer buffer-name)
     nil)))

;;;###autoload
(add-hook 'same-window-regexps "REDUCE") ; ??? Not sure about this! ???

(defun reduce-run-args-to-list (cmd)
  "Break CMD into a list of program and arguments.
The program path-name *may* include spaces.
This ignores quotes and escapes and so will fail if you have an
argument with whitespace, as in cmd = \"-ab +c -x 'you lose'\"."
  (let ((dir (file-name-directory cmd)))
	(cond (dir
		   (setq cmd (reduce-run-args-to-list-1
					  (file-name-nondirectory cmd)))
		   (cons (concat dir (car cmd)) (cdr cmd)))
		  (t (reduce-run-args-to-list-1 cmd)))))

(defun reduce-run-args-to-list-1 (cmd)
  "Break CMD into a list of program and arguments recursively.
The program path-name *must not* include spaces.
This ignores quotes and escapes and so will fail if you have an
argument with whitespace, as in cmd = \"-ab +c -x 'you lose'\"."
  (let ((where (string-match "[ \t]" cmd)))
    (cond ((null where) (list cmd))
		  ((/= where 0)
		   (cons (substring cmd 0 where)
				 (reduce-run-args-to-list-1
				  (substring cmd (1+ where)))))
		  (t (let ((pos (string-match "[^ \t]" cmd)))
			   (if (null pos)
				   ()
				 (reduce-run-args-to-list-1
				  (substring cmd pos))))))))


;;; Functions to send code to REDUCE running in a buffer
;;; ====================================================

(defun reduce-send-string (string)
  "Send STRING to the current REDUCE process.
The current buffer must be a REDUCE process buffer, which is not
checked!  Echo STRING and save it in the input history."
  (insert string)
  (comint-send-input))

(defun reduce-eval-region (start end switch)
  "Send the current region, from START to END, to a REDUCE process.
Prefix argument SWITCH means also switch to the REDUCE window.
Echo a possibly shortened version and save it in the input history.
Used by all functions that send input to REDUCE."
  (interactive "r\nP")
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
    (setq reg (if (> lines 3)
				  (replace-regexp-in-string
				   "\\(.*\n\\)\\(\\(.*\n\\)*.*\\)\n"
				   "%\\1%   ...\n%" region t)
				region))
    (switch-to-reduce t t switch)
    (insert reg)
    ;; Send full region to REDUCE, but replace all newlines (and any
    ;; preceding comments!) with spaces to avoid multiple REDUCE
    ;; prompts:
    (setq region
		  (replace-regexp-in-string "\\(%.*\\)?\n" " " region t t))
    ;; Hack sender to actually send region!  This ugly code is
    ;; necessary (?) because `comint-input-sender' is a buffer local
    ;; variable.
    (setq comint-input-sender
		  (lambda (proc string)
			(comint-simple-send (get-buffer-process (current-buffer)) region)))
    (comint-send-input)
    (setq comint-input-sender comint-input-sender-old)))

(defun reduce-eval-last-statement (switch)
  "Send the previous statement to a REDUCE process.
Prefix argument SWITCH means also switch to the REDUCE window."
  (interactive "P")
  (if (bobp)
	  (user-error "No previous statement")
	(reduce-eval-region
	 (save-excursion (reduce-backward-statement 1) (point))
	 (point) switch)))

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
	  (reduce-eval-region (point) end switch))))))

(defun reduce-running-buffer-p ()
  "Return non-nil if current buffer is running a REDUCE process."
  (and (eq major-mode 'reduce-run-mode)
       (get-buffer-process (current-buffer))))

(defun reduce-run-buffer-p (buf)
  "Return t if cons cell BUF represents an active REDUCE process buffer.
To be applied to each element of the buffer-read completion list, 
which appears to have the form `buffer-name . buffer-object'."
  (setq buf (car buf))
  (and (eq (aref buf 0) ?*)
	   (get-buffer-process buf)
	   (with-current-buffer buf (eq major-mode 'reduce-run-mode))))

(defvar switch-to-reduce-default nil
  "Default buffer used by `switch-to-reduce'.")

(defun switch-to-reduce (to-eob &optional no-mark switch)
  "Switch to REDUCE process buffer, at end if TO-EOB; if NO-MARK do not save mark.
With interactive argument, TO-EOB, position cursor at end of buffer.
If `reduce-run-autostart' is non-nil then automatically start a new REDUCE
process if necessary."
  (interactive "P")
  (let ((set-or-switch-to-buffer (if switch #'switch-to-buffer #'set-buffer)))
	;; Find the appropriate REDUCE process buffer:
	(cond
	 ;; If the current buffer is running REDUCE then do nothing:
	 ((reduce-running-buffer-p))
	 ;; Find an *active* REDUCE process buffer (RPB):
	 (reduce-run-buffer-alist
	  (let (buf)
		(if (and (null (cdr reduce-run-buffer-alist))
				 (get-buffer-process
				  (setq buf (cadar reduce-run-buffer-alist)))) ; only 1 RPB
			(funcall set-or-switch-to-buffer buf)
		  ;; Offer a choice of RPBs to switch to:
		  (funcall set-or-switch-to-buffer
				   (setq switch-to-reduce-default
						 (read-buffer
						  "Switch to REDUCE process buffer: "
						  (and
						   (get-buffer-process switch-to-reduce-default)
						   switch-to-reduce-default)
						  t						; require-match
						  'reduce-run-buffer-p))))))
	 ;; Start a new REDUCE process if appropriate:
	 (reduce-run-autostart
	  (run-reduce)
	  ;; Wait for REDUCE to start. May need to do this properly!
	  (sit-for 1)))
	;; Go to the end of the buffer if required:
	(when (and to-eob (not (eobp)))
	  (or no-mark (push-mark))
	  (goto-char (point-max)))))

(defun re-run-reduce ()
  "Re-run REDUCE in the current buffer, killing it first if necessary."
  (interactive)
  (if (not (eq major-mode 'reduce-run-mode))
	  (user-error "This is not a REDUCE process buffer")
	(goto-char (point-max))
	(when (get-buffer-process (current-buffer))
	  (insert "bye\;")					; show termination explicitly!
	  (comint-send-input)
	  (sit-for 1))
	(insert ?\n)
	(let* ((buf-name (buffer-name (current-buffer)))
		   (proc-name (substring buf-name 1 -1))
		   (cmd (substring proc-name 0 3)) ; "CSL" or "PSL"
		   (cmd (cdr (assoc cmd reduce-run-commands))))
	  ;; This may be overkill!
	  (reduce-run-reduce-1 cmd proc-name buf-name))))


(defvar reduce-prev-dir/file nil
  "Record last directory and file used in inputting or compiling.
This holds a cons cell of the form `(DIRECTORY . FILE)' describing the
last `reduce-input-file' or `reduce-fasl-file' command.")

(defvar reduce-prev-package nil
  "Name of last package loaded or compiled.")

(defvar reduce-run-file-name-history nil
     "A history list for ‘reduce-run’ source file-name arguments.")

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
  "Input REDUCE source file FILE-NAME into a REDUCE process.
Interactively, switch to a REDUCE process buffer first;
otherwise assume the current buffer is a REDUCE process buffer.
The user always chooses interactively whether to echo file input."
  (interactive (reduce-run-get-source "Input REDUCE file: "))
  (when (called-interactively-p 'any)
	(switch-to-reduce t t t)
	(sit-for 1))						; Allow REDUCE time to start
  (reduce-send-string
   (format "in \"%s\"%c" file-name
		   (if (y-or-n-p "Echo file input? ") ?\; ?$))))

(defun reduce-wait-for-prompt ()
  "Wait for REDUCE prompt in the current buffer.
Assume the current buffer is a REDUCE process buffer!"
  (save-excursion
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
  (let ((fasl-name (file-name-sans-extension (cdr reduce-prev-dir/file))))
	(setq fasl-name (read-minibuffer "FASL name: " fasl-name)
		  reduce-prev-package fasl-name)
	(switch-to-reduce t t t)
    (reduce-send-string (format "faslout %s;" fasl-name))
    (reduce-wait-for-prompt)
    (reduce-input-file file-name)
    (reduce-wait-for-prompt)
    (reduce-send-string "faslend;")))


;;; Support for loading REDUCE packages
;;; ===================================

(defun reduce-packages-directory-default ()
  "Return the REDUCE packages directory or nil if it cannot be found."
  ;; Find the REDUCE installation directory from the preferred REDUCE
  ;; command. It must be either an absolute path name or a command on
  ;; the search path.
  (let ((dir (car (reduce-run-args-to-list (cdar reduce-run-commands)))))
	;; Convert to an absolute path name if necessary:
	(unless (file-name-absolute-p dir) (setq dir (executable-find dir)))
	;; The parent directory should be the REDUCE directory:
	(setq dir (expand-file-name (concat (file-name-directory dir) "../packages/")))
	(and (file-accessible-directory-p dir) dir)))

(defvar reduce-package-completion-alist nil
  "Alist of REDUCE packages used for completion by `reduce-load-package'.
Not intended to be set directly but by customizing `reduce-packages-directory'.")

(defcustom reduce-packages-directory (reduce-packages-directory-default)
  "Directory of REDUCE packages, or nil.
It should be an absolute pathname of the form \"reduce/packages/\".
Note that you can complete the directory name using `M-<TAB>'.
This directory is used for completion by `reduce-load-package'."
  :type '(choice (const :tag "None" nil) directory)
  :group 'reduce-run
  :set (lambda (symbol value)
		 (if value
			 (if (file-accessible-directory-p value)
				 (let ((packages (directory-files value nil "\\`[^.]")))
				   (setq packages (delete "LICENSE" packages)
						 packages (delete "package.map" packages)
						 reduce-package-completion-alist
						 (and packages (mapcar 'list packages))))
			   (user-error "Directory must exist and be readable"))
		   (set-default symbol value))))

(defvar reduce-load-package-history nil
     "A history list for ‘reduce-load-package’.")

(defun reduce-load-package (package)
  "Load REDUCE package PACKAGE into the appropriate REDUCE process."
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
       reduce-load-package-history
       default)
      )))
  (setq reduce-prev-package package)
  (switch-to-reduce t t t)
  (reduce-send-string (format "load_package %s;" package)))


;;; Functions to run a REDUCE file or buffer in a unique process buffer
;;; ===================================================================
;;; (essentially as requested by Raffaele Vitolo)

;;;###autoload
(defun reduce-run-file (filename)
  "Run FILENAME as a REDUCE program in a unique process buffer.
Start a new (default) REDUCE process named from FILENAME
\(if necessary) and input FILENAME."
  (interactive "fRun REDUCE file: ")
  (reduce-run-file-or-buffer
   (file-name-nondirectory filename)
   (format "in \"%s\"%c" filename (if (y-or-n-p "Echo file input? ") ?\; ?$))))

(defun reduce-run-buffer ()
  "Run current buffer as a REDUCE program in a unique process buffer.
Start a new (default) REDUCE process named from the current
buffer (if necessary) and input the current buffer."
  (interactive)
  (reduce-run-file-or-buffer (buffer-name) (buffer-string)))

(defun reduce-run-file-or-buffer (name input)
  "Run NAME INPUT as a REDUCE program in a unique process buffer.
Start a new (default) REDUCE process named from file or buffer NAME
\(if necessary) and input INPUT."
  (let* ((xsl (caar reduce-run-commands))
		 (process-name (concat xsl " REDUCE " name))
		 (buffer-name (concat "*" process-name "*"))
		 (reduce-run-buffer-xsl (rassoc buffer-name reduce-run-buffer-alist)))
	;; Re-use any existing buffer for this REDUCE and file-name:
	(if (and reduce-run-buffer-xsl (comint-check-proc buffer-name))
		(pop-to-buffer buffer-name) ; just re-visit existing process buffer
	  (reduce-run-reduce-1 (cdar reduce-run-commands) process-name buffer-name)
	  (push (list xsl buffer-name) reduce-run-buffer-alist)
	  ;; Need a delay here -- see switch-to-reduce.
	  (sit-for 1))
	(insert input)
	;; Avoid triggering spurious prompts when inserting a buffer:
	(delete-blank-lines)				; from end of inserted buffer
	(if (bolp) (delete-char -1))		; delete previous newline
	(comint-send-input)))


;;; Ancillary functions
;;; ===================

(defun reduce-send-bye (proc)
  "Send PROC the string `bye;'."
  (process-send-string proc "bye\;\n"))

(defun reduce-kill-buffer-tidy-up ()
  "Hang on `kill-buffer-hook' to terminate the REDUCE process tidily.
Also remove the buffer from `reduce-run-buffer-alist'."
  (if (eq major-mode 'reduce-run-mode)
      (let ((proc (get-buffer-process (current-buffer))))
		(if proc (reduce-send-bye proc))
		(setq reduce-run-buffer-alist
			  (seq-remove (lambda (x) (equal (cadr x) (buffer-name)))
						  reduce-run-buffer-alist)))))

(defun reduce-process-p (proc)
  "True if PROC is a REDUCE process."
  (save-excursion
    (and (setq proc (process-buffer proc))
	 (set-buffer proc)
	 (eq major-mode 'reduce-run-mode))))

(defun reduce-kill-emacs-tidy-up ()
  "Hang on `kill-emacs-hook' to terminate all REDUCE processes."
  (mapcar (function
	   (lambda (proc)
	     ;; If PROC is a REDUCE process then send it the string `bye;'
	     ;; and pause to allow it to take effect (before Emacs dies).
	     (cond ((reduce-process-p proc)
		    (reduce-send-bye proc)
		    ;; The time may need tuning on different systems.
		    ;; For me, anything less than 1 second is unreliable.
		    (sit-for 1 t)	; no redisplay
		    ))))
	  (process-list)))


;;; Do the user's customisation...
;;; ==============================

(provide 'reduce-run)

(run-hooks 'reduce-run-load-hook)

;;; reduce-run.el ends here
