;;; reduce-run.el --- Run the REDUCE computer-algebra system in a buffer  -*- lexical-binding: t; -*-

;; Copyright (C) 1998-2001, 2012, 2017-2019, 2022 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Created: late 1998
;; Time-stamp: <2022-10-02 17:51:39 franc>
;; Keywords: languages, processes
;; Homepage: https://reduce-algebra.sourceforge.io/reduce-ide/
;; Package-Version: 1.8
;; Package-Requires: ((reduce-mode "1.5"))

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

;; REDUCE Run mode is a package for running the REDUCE computer
;; algebra system, which is Open Source and available from
;; <https://sourceforge.net/projects/reduce-algebra>.

;; Hacked from inf-lisp.el by Olin Shivers <shivers@cs.cmu.edu>

;; This file defines a REDUCE-in-a-buffer package built on top of
;; comint mode.  Since this mode is built on top of the general
;; command-interpreter-in-a-buffer mode (comint mode), it shares a
;; common base functionality, and a common set of bindings, with all
;; modes derived from comint mode.  This makes these modes easier to
;; use.

;; For documentation on the functionality provided by comint mode, and
;; the hooks available for customising it, see the file comint.el.

;; REDUCE Run mode requires ‘reduce-mode.el’.

;;; To do:

;; control echoing from input of statement, proc or region?

;;; Code:

;; Declare variables and functions defined in reduce-mode.el to avoid
;; compiler warnings:
(defvar reduce-mode-map)
(declare-function reduce-backward-statement "reduce-mode")
(declare-function reduce-forward-procedure "reduce-mode")
(declare-function reduce-backward-procedure "reduce-mode")

(require 'reduce-mode);; (if load-in-progress (require 'reduce-mode))

(defconst reduce-run-version
  ;; Extract version from Package-Version in file header:
  (eval-when-compile
    (require 'lisp-mnt)
    (save-excursion (lm-header "package-version")))
  "Version information for REDUCE Run mode.")

;; (message "Loading reduce-run")       ; TEMPORARY!

(require 'comint)

;;; Customizable user options
;;; =========================

(defgroup reduce-run nil
  "Support for running REDUCE code.
Note that REDUCE Run inherits from comint."
  :tag "REDUCE Run"
  :group 'reduce
  :link '(custom-group-link comint))

;; Define this variable only on Microsoft Windows:
(eval-and-compile
  (if (eq system-type 'windows-nt)
      (defcustom reduce-run-MSWin-drives
        (cdr (split-string
              ;; Beware that WMIC is deprecated!
              (shell-command-to-string "wmic LogicalDisk get Caption")))
        "On MS Windows (only), the list of drives to be searched for REDUCE.
Default is all local drives, e.g. (\"C:\" \"D:\" \"E:\" \"F:\").
Used only by ‘reduce-run-installation-directory’.
Not defined on other platforms."
        ;; https://stackoverflow.com/questions/3652631/
        ;; is-there-a-way-to-list-drive-letters-in-dired
        :type '(repeat
                :validate
                (lambda (widget)
                  ;; value should be a list of strings
                  (let ((value (widget-value widget)) invalid)
                    (while value
                      (if (string-match "\\`[A-Z]:\\'" (car value))
                          (setq value (cdr value))
                        (setq invalid (car value) value nil)))
                    (when invalid
                      (widget-put widget :error
                                  (format "Invalid drive: ‘%s’.  \
Each drive must be specified as ‘X:’, where X is a letter A-Z." invalid))
                      widget)))
                string)
        :group 'reduce-run
        :package-version '(reduce-ide . "1.6"))))

(defcustom reduce-run-installation-directory
  (if (eq system-type 'windows-nt)
      (let ((drives reduce-run-MSWin-drives)
            (skeleton "/Program Files/Reduce/")
            dir d)
        (while drives
          (setq d (concat (car drives) skeleton))
          (if (file-accessible-directory-p d)
              (setq dir d drives nil)
            (setq drives (cdr drives))))
        dir)
    "/usr/share/reduce/")
  "Absolute root directory of the REDUCE installation, or nil if not set.
It is the directory containing the “packages” directory and, on
Microsoft Windows, the “bin” directory containing the
user-executable batch files.  On Microsoft Windows, it defaults
to “X:/Program Files/Reduce/”, where X is a letter A-Z that
REDUCE Run mode attempts to determine automatically.  On other
platforms, it defaults to “/usr/share/reduce/”.  Note that you
can complete the directory name using \\<widget-field-keymap>‘\\[widget-complete]’."
  :type  '(choice (const :tag "None" nil) directory)
  :group 'reduce-run
  :package-version '(reduce-ide . "1.6"))


(defconst reduce-run--redpsl-bat-filename
  (if reduce-run-installation-directory
      (concat reduce-run-installation-directory "bin/redpsl.bat")
    "redpsl.bat")
  "The absolute pathname of the standard file \"redpsl.bat\".
If it cannot be found then just \"redpsl.bat\".")

(defconst reduce-run--this-filepath
  (or load-file-name (buffer-file-name))
  "The absolute pathname of this file, \"reduce-run.el\".
If it cannot be found then nil (which might be the case if REDUCE
Run mode is customized before it is otherwise used).")

(defconst reduce-run--reduce-run-redpsl-bat-filename
  (if reduce-run--this-filepath
      (concat (file-name-directory reduce-run--this-filepath)
              "reduce-run-redpsl.bat"))
  "The absolute pathname of the local file \"reduce-run-redpsl.bat\".
It must be in this directory; if it cannot be found then nil.")


;; Construct "reduce-run-redpsl.bat" in this directory.  Doing this
;; every time this file is loaded allows for changes between loads.

(if reduce-run--reduce-run-redpsl-bat-filename
    (with-temp-file
        reduce-run--reduce-run-redpsl-bat-filename
      (insert "@echo off\r\n\"" reduce-run--redpsl-bat-filename "\"")))


(defcustom reduce-run-commands
  (if (and (eq system-type 'windows-nt) reduce-run-installation-directory)
      (list (cons "CSL" (concat reduce-run-installation-directory
                                "bin/redcsl.bat --nogui"))
            (cons "PSL"
                  (if (and reduce-run--reduce-run-redpsl-bat-filename
                           (file-exists-p reduce-run--reduce-run-redpsl-bat-filename))
                      ;; local batch file if possible:
                      reduce-run--reduce-run-redpsl-bat-filename
                    ;; otherwise standard batch file:
                    reduce-run--redpsl-bat-filename)))
    '(("CSL" . "redcsl --nogui") ("PSL" . "redpsl")))
  "Alist of commands to run different versions of REDUCE.
By default, it should be appropriate for standard installations
of CSL and PSL REDUCE.  Each element has the form “name .
command”, where name and command are strings.  Name is arbitrary
but typically relates to the underlying Lisp system.  The string
\" REDUCE\" is appended to it to name the interaction buffer.
Command should be a relative or absolute pathname, and may
include switches.  It must invoke a command-line version of
REDUCE; a GUI version will not work!"
  :type '(alist :key-type (choice (const "CSL")
                                  (const "PSL")
                                  (string :tag "Other"))
                :value-type string)
  :group 'reduce-run
  :set-after '(reduce-run-installation-directory))

(defcustom reduce-run-prompt "^\\(?:[0-9]+[:*] \\)+"
  "Regexp to recognise prompts in REDUCE Run mode."
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
If a file is loaded into a buffer that is in one of the major
modes in this list then it is considered to be a REDUCE source
file by ‘reduce-input-file’ and ‘reduce-fasl-file’.  Used by
these commands to determine defaults."
  :type '(repeat symbol)
  :group 'reduce-run)


;;; Internal variables
;;; ==================

(defvar reduce-run-buffer-alist nil
  "This variable holds an alist of REDUCE process buffers (RPBs).
It is used to name new RPBs appropriately and decide where to
send REDUCE input.")

(defvar reduce-run-mode-map
  (let ((map (make-sparse-keymap)))
    (define-key map "\C-m" 'reduce-run-send-input)
    (define-key map [(shift return)] 'comint-send-input)
    (define-key map [?\C-x ?\C-e] 'reduce-eval-last-statement)
    (define-key map [?\C-c ?\C-e] 'reduce-eval-line)
    (define-key map [?\C-c ?\C-i] 'reduce-input-file)
    (define-key map [?\C-c ?\C-l] 'reduce-load-package)
    (define-key map [?\C-c ?\C-f] 'reduce-fasl-file)
    (define-key map [(meta tab)] 'reduce-complete-symbol)
    map))

;; These commands augment REDUCE mode, so you can process REDUCE
;; code in file editing buffers.
(define-key reduce-mode-map "\M-\C-x"  'reduce-eval-proc) ; Emacs convention
(define-key reduce-mode-map "\C-x\C-e" 'reduce-eval-last-statement) ; ditto
(define-key reduce-mode-map "\C-c\C-e" 'reduce-eval-line)
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

(easy-menu-define                       ; (symbol maps doc menu)
  reduce-run-menu
  reduce-run-mode-map
  "REDUCE Run Menu."
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

(easy-menu-define                       ; (symbol maps doc menu)
  reduce-mode-run-menu
  nil
  "REDUCE Mode Run Menu."
  `("Run REDUCE"
    ["Run REDUCE" run-reduce :active t
     :help "Start a new REDUCE process if necessary"]
    ["Run Buffer" reduce-run-buffer :active t
     :help "Run the current buffer in a new REDUCE process"]
    "--"
    ["Input Last Statement" reduce-eval-last-statement :active t
     :help "Input the statement before point to a REDUCE process"]
    ["Input Line" reduce-eval-line :active t
     :help "Input the line containing point to a REDUCE process"]
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
  "Echo version information for REDUCE Run mode."
  (interactive)
  (message "REDUCE Run mode – REDUCE IDE Package Version: %s" reduce-run-version))

;; Put the Run REDUCE menu on the menu bar AFTER the REDUCE menu:
(define-key-after
  (lookup-key reduce-mode-map [menu-bar])
  [Run\ REDUCE]
  (cons "Run REDUCE" reduce-mode-run-menu) 'REDUCE)

(defun reduce-run-install-letter-bindings ()
  "Bind many REDUCE run commands to ‘C-c’ <letter> bindings.
This makes them more accessible.  These bindings are reserved for
the user and so are non-standard.  If you want to use them, you
should have this function called by the ‘reduce-run-load-hook’:
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


;;; Functions to run REDUCE in a buffer
;;; ===================================

(define-derived-mode reduce-run-mode comint-mode "REDUCE Run"
  "Major mode for interacting with a REDUCE process – part of REDUCE IDE.
Version: see ‘reduce-run-version’.\\<reduce-run-mode-map>
Author: Francis J. Wright (URL ‘https://sites.google.com/site/fjwcentaur’).
Website: URL ‘https://reduce-algebra.sourceforge.io/reduce-ide/’.
Comments, suggestions, bug reports, etc. are welcome.
Full documentation is provided in the Info node ‘(reduce-ide)Run’.

Run REDUCE as a subprocess of Emacs, with I/O through an Emacs buffer.

There can be more than one buffer in REDUCE Run mode, in which
case relevant commands allow you to choose which buffer to use,
and you can send text to a selected REDUCE process from other
buffers containing REDUCE source:
 • ‘switch-to-reduce’ switches the current buffer to the selected
   REDUCE process buffer;
 • ‘reduce-eval-proc’ sends the current procedure definition to
   the selected REDUCE process;
 • ‘reduce-eval-region’ sends the current region to the selected
   REDUCE process.
Prefixing the ‘reduce-eval-’ commands with a ‘\\[universal-argument]’
also switches to the selected REDUCE process buffer window.

Commands:
 • Return after the end of the process' output sends the text from the
   end of process to point.
 • Return before the end of the process' output copies the statement
   ending at point to the end of the process' output, and sends it.
 • Delete converts tabs to spaces as it moves back.
 • ‘\\[reduce-indent-line]’ indents for REDUCE; with argument,
   shifts rest of expression rigidly with the current line.
 • ‘\\[reduce-indent-procedure]’ does ‘reduce-indent-line’ on each
   line starting within following expression.
Paragraphs are separated only by blank lines.  Percent signs start comments.
If you accidentally suspend your process, use ‘\\[comint-continue-subjob]’
to continue it.

\\{reduce-run-mode-map}
The customization group ‘reduce-run’ affects this mode.  REDUCE
Run inherits from comint, so the customization group ‘comint’
also affects this mode.  Entry to this mode runs the hooks on
‘comint-mode-hook’ and ‘reduce-run-mode-hook’ (in that order)."
  :syntax-table reduce-mode-syntax-table
  :group 'reduce-run
  (setq font-lock-defaults              ; auto buffer-local
        '(reduce-run-font-lock-keywords ; KEYWORDS
          t))                           ; KEYWORDS-ONLY
  (setq comint-input-filter #'reduce-input-filter) ; buffer-local
  (setq comint-input-ignoredups t)      ; buffer-local
  ;; ansi-color-process-output causes an error when CSL is terminated
  ;; and is probably irrelevant anyway, so ...
  (remove-hook (make-local-variable 'comint-output-filter-functions)
               'ansi-color-process-output t) ; remove locally!
  ;; Try to ensure graceful shutdown. In particular, PSL REDUCE on
  ;; Windows seems to object to being killed!
  (add-hook 'kill-buffer-hook 'reduce-kill-buffer-tidy-up)
  (add-hook 'kill-emacs-hook 'reduce-kill-emacs-tidy-up))

(defun reduce-input-filter (str)
  "True if STR does not match variable ‘reduce-input-filter’."
  (not (string-match reduce-input-filter str)))

(defvar reduce-run-history nil
  "Input history for the ‘run-reduce’ command.")

;;;###autoload
(defun run-reduce (&optional cmd)
  "Run REDUCE command named CMD with I/O via a buffer.
Interactively, prompt with completion for CMD, ignoring case,
which defaults to the last value used.  If CMD is omitted, nil or
not provided, display a pop-up menu of command names.  Look up
CMD in ‘reduce-run-commands’ and run command found.  The buffer
is in REDUCE Run mode and named “*CMD REDUCE*”.

With a prefix argument, CMD is the actual REDUCE command.

If ‘reduce-run-multiple’ in non-nil then always start a new
distinct REDUCE process; otherwise, if there is a REDUCE process
already running this command, switch to it.  Runs the hooks from
‘reduce-run-mode-hook’ (after the ‘comint-mode-hook’ is run).

\(Type ‘\\[describe-mode]’ in the process buffer for a list of commands.)"
  (interactive
   (list (if current-prefix-arg
             (read-string "REDUCE command: " nil 'reduce-run-history)
           (let ((completion-ignore-case t))
             (completing-read
              "REDUCE command name: "
              reduce-run-commands
              nil t (car reduce-run-history) ; predicate require-match initial
              'reduce-run-history)))))
  (if current-prefix-arg
      (reduce-run-reduce cmd "")        ; unknown REDUCE version
    (when (and (null cmd) reduce-run-history)
      ;; Non-interactive but history, so use it:
      (setq cmd (car reduce-run-history)))
    (when (or (null cmd) (zerop (length cmd)))
      (setq cmd (x-popup-menu t `("REDUCE command name:"
                                  (""
                                   ,@(mapcar
                                      (lambda (x)
                                        (cons (car x) (car x)))
                                      reduce-run-commands))))
            reduce-run-history (list cmd)))
    (let ((reduce-run-command (assoc-string cmd reduce-run-commands t)))
      (if reduce-run-command
          (reduce-run-reduce (cdr reduce-run-command) (car reduce-run-command))
        (lwarn '(reduce-run) :warning
               "REDUCE command name \"%s\" not found!" cmd)))))

(defun reduce-run-reduce (cmd xsl)
  "Run CMD as an XSL REDUCE process with I/O via buffer “*XSL REDUCE*”.
XSL is the name of a REDUCE command in ’reduce-run-commands’ (by
default \"CSL\" or \"PSL\") or \"\".  If there is a process
already running this command name, just switch to it.
Return t if successful; nil otherwise."
  ;; Return value is no longer used!
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

(defun reduce-run-reduce-1 (cmd process-name buffer-name)
  "Run CMD as REDUCE process PROCESS-NAME in buffer BUFFER-NAME.
Return the process buffer if successful; nil otherwise."
  (condition-case err
      ;; Protected form:
      (let ((cmdlist (reduce-run-args-to-list cmd)))
        (set-buffer
         ;; ‘apply’ used below because last arg is &rest!
         (apply #'make-comint-in-buffer
                process-name nil (car cmdlist) nil (cdr cmdlist)))
        (reduce-run-mode)
        (pop-to-buffer buffer-name))
    ;; Error handler:
    (error            ; condition
     ;; Display the usual error message then tidy up:
     (message "%s" (error-message-string err))
     (kill-buffer buffer-name)
     nil)))

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

(defun reduce-run-send-input ()
  "Send input to REDUCE.
Add a final ’;’ unless there is already a final terminator or a
’?’ in the current line.  Then call ‘comint-send-input’.
\\<reduce-run-mode-map>Note that ‘\\[comint-send-input]’ calls ‘comint-send-input’ directly."
  (interactive)
  (end-of-line)
  (if (and (eobp) (not (looking-back "[;$]\\s-*\\|\\?.*" nil)))
      (insert ?\;))
  (comint-send-input))


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
  (let ((oldbuf (current-buffer))
        (region (buffer-substring-no-properties start end))
        (START 0) (lines 1) reg window
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
    (setq window (switch-to-reduce t t switch))
    (insert reg)
    ;; Send full region to REDUCE, but replace all newlines (and any
    ;; preceding comments!) with spaces to avoid multiple REDUCE
    ;; prompts:
    (setq region
          (replace-regexp-in-string "\\(%.*\\)?\n" " " region t t))
    ;; Hack sender to actually send region!  This ugly code is
    ;; necessary (?) because ‘comint-input-sender’ is a buffer local
    ;; variable.
    (setq comint-input-sender
          (lambda (_proc _string)
            (comint-simple-send (get-buffer-process (current-buffer)) region)))
    (comint-send-input)
    (setq comint-input-sender comint-input-sender-old)
    (set-window-point window (point-max))
    ;; Re-select file window (if possible):
    (unless switch
      (if (setq window (get-buffer-window oldbuf))
          (select-window window)))))

(defun reduce-eval-last-statement (switch)
  "Send the previous statement to a REDUCE process.
Prefix argument SWITCH means also switch to the REDUCE window."
  (interactive "P")
  (if (bobp)
      (user-error "No previous statement")
    (reduce-eval-region
     (save-excursion (reduce-backward-statement 1) (point))
     (point) switch)))

(defun reduce-eval-line (switch)
  "Send the current line of code to the REDUCE process.
Prefix argument SWITCH means also switch to the REDUCE window."
  (interactive "P")
  (save-excursion
    (beginning-of-line)
    (skip-chars-forward " \t")
    (let ((start (point)))
      (end-of-line)
      (skip-chars-backward " \t")
      (if (= (point) start)
          (user-error "Empty line")
        (reduce-eval-region start (point) switch)))))

(defun reduce-eval-proc (switch)
  "Send the current procedure definition to the REDUCE process.
Prefix argument SWITCH means also switch to the REDUCE window."
  ;; cf. reduce-mark-procedure
  (interactive "P")
  (save-excursion
    (let ((start (point)))
      (reduce-forward-procedure 1)
      (unless (= (point) start)
    (skip-chars-forward " \t\n")    ; skip trailing white space
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
which appears to have the form “buffer-name . buffer-object”."
  (setq buf (car buf))
  (and (eq (aref buf 0) ?*)
       (get-buffer-process buf)
       (with-current-buffer buf (eq major-mode 'reduce-run-mode))))

(defvar switch-to-reduce-default nil
  "Default buffer used by ‘switch-to-reduce’.")

(defun switch-to-reduce (to-eob &optional no-mark switch)
  "Switch to REDUCE process buffer, at end if TO-EOB is non-nil.
If NO-MARK is non-nil then do not save mark.  If SWITCH is
non-nil then also switch to the REDUCE window; see
‘reduce-eval-region’.  With interactive argument, TO-EOB,
position cursor at end of buffer.  If ‘reduce-run-autostart’ is
non-nil then automatically start a new REDUCE process if
necessary.  Return the window displaying the REDUCE process
buffer."
  (interactive "P")
  (let ((set-or-switch-to-buffer (if switch #'switch-to-buffer #'set-buffer)))
    ;; Find the appropriate REDUCE process buffer:
    (cond
     ;; If the current buffer is running REDUCE then do nothing:
     ((reduce-running-buffer-p))
     ;; Look for an *active* REDUCE process buffer (RPB):
     ((and reduce-run-buffer-alist
           (if (null (cdr reduce-run-buffer-alist)) ; at most one active RPB
               (let ((buf (cadar reduce-run-buffer-alist)))
                 (if (get-buffer-process buf) ; one active RPB, so use it:
                     (funcall set-or-switch-to-buffer buf)
                   ;; No active RPB, so fall through to start a new one:
                   nil))
             ;; Multiple RPBs, so offer a choice:
             (funcall set-or-switch-to-buffer
                      (setq switch-to-reduce-default
                            (read-buffer
                             "Switch to REDUCE process buffer: "
                             (and
                              (get-buffer-process switch-to-reduce-default)
                              switch-to-reduce-default)
                             t          ; require-match
                             'reduce-run-buffer-p)))
             t)))
     ;; Start a new REDUCE process in a new window as appropriate:
     (reduce-run-autostart
      (unless switch (split-window nil nil t)) ; new window on the right
      (run-reduce)
      ;; (reduce--wait-for-prompt) ; this seems to hang -- why?
      ))
    ;; Go to the end of the buffer if required:
    (when (and to-eob (not (eobp)))
      (or no-mark (push-mark))
      (goto-char (point-max))))
  ;; Ensure that the new buffer is displayed and return its window:
  (or (get-buffer-window)
      (get-buffer-window
       (switch-to-buffer-other-window (current-buffer)))))

(defun re-run-reduce ()
  "Re-run REDUCE in the current buffer, killing it first if necessary."
  (interactive)
  (if (not (eq major-mode 'reduce-run-mode))
      (user-error "This is not a REDUCE process buffer")
    (goto-char (point-max))
    (when (get-buffer-process (current-buffer))
      (insert "bye\;")                  ; show termination explicitly!
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
This holds a cons cell of the form “(DIRECTORY . FILE)” describing the
last ‘reduce-input-file’ or ‘reduce-fasl-file’ command.")

(defvar reduce-prev-package nil
  "Name of last package loaded or compiled.")

(defvar reduce-run-file-name-history nil
     "A history list for REDUCE Run mode source file-name arguments.")

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
    (list file-name)            ; Yuk!
    ))

(defun reduce-input-file (file-name)
  "Input REDUCE source file FILE-NAME into a REDUCE process.
Interactively, switch to a REDUCE process buffer first;
otherwise assume the current buffer is a REDUCE process buffer.
The user always chooses interactively whether to echo file input."
  (interactive (reduce-run-get-source "Input REDUCE file: "))
  (if (called-interactively-p 'any)
      (switch-to-reduce t t t))
  (reduce-send-string
   (format "in \"%s\"%c" file-name
           (if (y-or-n-p "Echo file input? ") ?\; ?$))))

(defun reduce--wait-for-prompt ()
  "Wait for REDUCE prompt in the current buffer.
Assume the current buffer is a REDUCE process buffer!"
  (save-excursion
    (while (progn
             (goto-char (point-max))
             ;; Unlike ‘beginning-of-line’, forward-line ignores field
             ;; boundaries (cf. ‘comint-bol’)
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
    (reduce--wait-for-prompt)
    (reduce-input-file file-name)
    (reduce--wait-for-prompt)
    (reduce-send-string "faslend;")))


;;; Support for loading REDUCE packages
;;; ===================================

(defvar reduce-package-completion-alist nil
  "Alist of REDUCE packages used for completion by ‘reduce-load-package’.
Not intended to be set directly but by customizing ‘reduce-packages-directory’.")

(defun reduce-set-package-completion-alist (dir)
  "Assign ‘reduce-package-completion-alist’ using directory DIR.
Process the package.map file in directory DIR, assuming it is the
REDUCE packages directory."
  (unless (file-accessible-directory-p dir)
    (user-error "REDUCE packages directory is not accessible"))
  (let ((package.map (concat dir "/package.map")))
    (unless (file-readable-p package.map)
      (user-error "%s is not readable" package.map))
    (with-temp-buffer
      (insert-file-contents package.map)
      (while (re-search-forward "%.*" nil t)
        (replace-match ""))
      (goto-char 1)
      (let ((packages (read (current-buffer))))
        (setq packages
              (mapcar
               #'(lambda (x) (symbol-name (car x)))
               packages)
              packages (sort packages #'string<)
              reduce-package-completion-alist
              (mapcar #'list packages))))))

(defcustom reduce-packages-directory
  (and reduce-run-installation-directory
       (let ((dir (concat reduce-run-installation-directory "packages/")))
         (and (file-accessible-directory-p dir) dir)))
  "Directory of REDUCE packages, or nil if not set.
It should be an absolute pathname ending with “…/packages/” and
should be set automatically.  Note that you can complete the
directory name using \\<widget-field-keymap>‘\\[widget-complete]’.
Customizing this variable sets up completion for
‘reduce-load-package’; setting it directly has no effect."
  :type '(choice (const :tag "None" nil) directory)
  :group 'reduce-run
  :set #'(lambda (symbol value)
           (if value (reduce-set-package-completion-alist value))
           (set-default symbol value))
  :set-after '(reduce-run-installation-directory))

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
       nil              ; predicate
       nil              ; require-match
       nil              ; initial
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
      (reduce--wait-for-prompt))
    (insert input)
    ;; Avoid triggering spurious prompts when inserting a buffer:
    (delete-blank-lines)                ; from end of inserted buffer
    (if (bolp) (delete-char -1))        ; delete previous newline
    (comint-send-input)))


;;; Ancillary functions
;;; ===================

(defun reduce-send-bye (proc)
  "Send PROC the string \"bye;\"."
  (process-send-string proc "bye\;\n"))

(defun reduce-kill-buffer-tidy-up ()
  "Hang on ‘kill-buffer-hook’ to terminate the REDUCE process tidily.
Also remove the buffer from ‘reduce-run-buffer-alist’."
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
  "Hang on ‘kill-emacs-hook’ to terminate all REDUCE processes."
  (mapcar (function
       (lambda (proc)
         ;; If PROC is a REDUCE process then send it the string ‘bye;’
         ;; and pause to allow it to take effect (before Emacs dies).
         (cond ((reduce-process-p proc)
            (reduce-send-bye proc)
            ;; The time may need tuning on different systems.
            ;; For me, anything less than 1 second is unreliable.
            (sit-for 1 t)   ; no redisplay
            ))))
      (process-list)))


;;; Do the user's customisation...
;;; ==============================

(provide 'reduce-run)

(run-hooks 'reduce-run-load-hook)

;;; reduce-run.el ends here
