;;; reduce-run.el --- Run the REDUCE computer-algebra system in a buffer  -*- lexical-binding:t -*-

;; Copyright (C) 1998-2001, 2012, 2017-2019, 2022-2025 Francis J. Wright

;; Author: Francis J. Wright <https://sites.google.com/site/fjwcentaur>
;; Created: late 1998
;; Time-stamp: <2025-03-25 17:11:10 franc>
;; Keywords: languages, processes
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

;; This file is intended to be installed as part of the REDUCE IDE
;; package; see the homepage for guidance on installing REDUCE IDE.

;; REDUCE Run is a major mode for running the REDUCE computer algebra
;; system, which is Open Source and available from
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

;;; To do:

;; control echoing from input of statement, proc or region?

;;; Code:

(require 'reduce-mode)
(require 'comint)
(require 'wid-edit)

(eval-when-compile (require 'cl-lib))

;;; Customizable user options
;;; =========================

(define-obsolete-variable-alias
  'reduce-run-installation-directory 'reduce-root-dir-file-name "1.12"
  "But note that ‘reduce-root-dir-file-name’ has slightly different
semantics.  It is a directory file name and so should *not* end with a
directory separator.")

(defun reduce-run--validate-root-dir (widget)
  "Ensure that WIDGET is an accessible absolute directory file name.
If so, return nil.  Otherwise, return WIDGET with error set."
  (let* ((value (widget-value widget)) (old-value value))
    (if (not (file-accessible-directory-p value))
        (progn
          (widget-put
           widget :error
           (format "Directory not accessible: %S" value))
          widget)
      (if (directory-name-p value)
          (setq value (directory-file-name value)))
      (if (not (file-name-absolute-p value))
          (setq value (expand-file-name value)))
      (if (not (string-equal value old-value))
          (widget-value-set widget value))
      nil)))

(defcustom reduce-root-dir-file-name
  (if (eq system-type 'windows-nt)
      (let ((path (copy-sequence "?:/Program Files/Reduce"))) ; mutable
        (cl-do ((drive ?C (1+ drive))) ((> drive ?Z))
          (aset path 0 drive)
          (when (file-accessible-directory-p path)
            (cl-return path))))
    "/usr/share/reduce")
  "Default REDUCE installation root directory, or nil if not set.
If set, it must be an accessible absolute directory file name (without
any trailing directory separator).  It should be the directory
containing the “packages” directory and, on Microsoft Windows, the “bin”
directory containing “redcsl.bat” and “redpsl.bat”.  On Microsoft
Windows, it defaults to “?:/Program Files/Reduce”, where ? is a letter
C\-Z that REDUCE Run mode attempts to determine automatically.  On other
platforms, it defaults to “/usr/share/reduce”.

Note that you can complete the directory name using \
\\<widget-field-keymap>‘\\[widget-complete]’."
  :type '(choice
          (const :tag "None" nil)
          (directory :validate reduce-run--validate-root-dir))
  :link '(custom-manual "(reduce-ide)REDUCE on Windows")
  :group 'reduce-run
  :package-version '(reduce-ide . "1.13"))

(defcustom reduce-run-commands
  (if (and (eq system-type 'windows-nt) reduce-root-dir-file-name)
      ;; reduce-root-dir-file-name must be set to replace $reduce!
      '(("CSL"
         nil
         "$reduce/lib/csl/reduce.exe"
         "--nogui")
        ("PSL"
         nil
         "$reduce/lib/psl/psl/bpsl.exe"
         "-td" "1000" "-f" "$reduce/lib/psl/red/reduce.img")
        ("redcsl.bat"
         nil
         "$reduce/bin/redcsl.bat" "-nocd" "--nogui")
        ("redpsl.bat"
         nil
         "$reduce/bin/redpsl.bat"))
    '(("CSL" nil "redcsl" "--nogui")
      ("PSL" nil "redpsl")))
  "Alist of commands to run different versions of REDUCE.
By default, it should be appropriate for standard installations of CSL
and PSL REDUCE.

Each element has the form “name.root.program.arguments”, where “name”
and “program” are strings, “root” is nil or a directory file name, and
“arguments” is a possibly empty list of strings.  All strings may
include spaces.

The “name” component is arbitrary but typically relates to the
underlying Lisp system.  The string \" REDUCE\" is appended to it to
provide the default name for the interaction buffer.

If “root” is unset (nil) then it defaults to the value of
‘reduce-root-dir-file-name’; if it is set then its value should be as
described for ‘reduce-root-dir-file-name’.  If “root” is non-nil and
“program” or any argument _begins_ with the shorthand “$reduce” then
“$reduce” will be replaced by “root”.  Also, “root” will become the
value of the environment variable “reduce” within the REDUCE
process.  (This is used only by a few specialized REDUCE packages and it
will be overwritten if REDUCE is run via a shell script that sets the
environment variable “reduce” itself.)

The “program” component should be an absolute pathname or a command on
the search path, and “arguments” consists of optional command arguments.

For *temporary* backward compatibility, each element may alternatively
have the form “name.command”, where “name” and “command” are strings.
The command string should begin with an absolute pathname that *may*
include spaces or a command on the search path, and it may be followed
by arguments, which *may not* include spaces.

The command (together with its arguments) must invoke a
command-line version of REDUCE; a GUI version will not work!  A
binary program is run directly, whereas a shell script is run via
the default shell.  On Microsoft Windows, it is best to run
REDUCE directly and not via a “.bat” file."
  :type
  `(alist :tag "Commands"
          :key-type (string :tag "Name")
          :value-type
          (cons :tag ,(format "Root => $reduce (defaults to \"%s\")"
                              reduce-root-dir-file-name)
                (choice (const :tag "Unset" nil)
                        (directory :validate reduce-run--validate-root-dir))
                (cons :tag "Command"
                      (string :tag "Program")
                      (repeat :tag "Arguments"
                              (string :tag "Arg")))))
  :set-after '(reduce-root-dir-file-name)
  :link '(custom-manual "(reduce-ide)Running")
  :group 'reduce-run
  :package-version '(reduce-ide . "1.13"))

(defcustom reduce-run-command-name-default
  (caar reduce-run-commands)
  "Default command name to run REDUCE, or nil.
The default is the first command name in ‘reduce-run-commands’."
  :type `(choice (const :tag "None" nil)
                 ,@(mapcar #'(lambda (x) (list 'const (car x)))
                           reduce-run-commands))
  :set-after '(reduce-run-commands)
  :link '(custom-manual "(reduce-ide)Running")
  :group 'reduce-run
  :package-version '(reduce-ide . "1.11"))

(defcustom reduce-run-terminal
  (and (not (eq system-type 'windows-nt)) "Eterm")
  "If non-nil, value of TERM to use on Unix-like platforms.
This sets ‘comint-terminfo-terminal’ to the value of
‘reduce-run-terminal’ and ‘system-uses-terminfo’ to t locally within
‘run-reduce’ so that CSL REDUCE responds appropriately to interrupts,
which with a dumb terminal it does not.  A nil value means use the Emacs
defaults.  Possible values to try are ‘Eterm’, ‘emacs’, ‘xterm’."
  :type '(choice (const :tag "Default" nil) string)
  :link '(custom-manual "(reduce-ide)Running")
  :group 'reduce-run
  :package-version '(reduce-ide . "1.11"))

(defcustom reduce-run-prompt "^\\(?:[0-9]+[:*] \\)+"
  "Regexp to recognise prompts in REDUCE Run mode."
  :type 'regexp
  :link '(custom-manual "(reduce-ide)Run Customization")
  :group 'reduce-run)

(defcustom reduce-run-autostart t
  "If non-nil, automatically start a REDUCE process if necessary."
  :type 'boolean
  :link '(custom-manual "(reduce-ide)Running")
  :group 'reduce-run)

(defcustom reduce-run-multiple t
  "If non-nil, always start a new REDUCE process in a new distinct buffer.
Do this even if REDUCE is already running.
If nil, re-use any appropriate running REDUCE process."
  :type 'boolean
  :link '(custom-manual "(reduce-ide)Running")
  :group 'reduce-run)

(defcustom reduce-input-filter "\\`\\([ \t;$]*\\|[ \t]*.[ \t]*\\)\\'"
  "What not to save on REDUCE Run mode's input history.
The value is a regexp.  The default matches any combination of zero or
more whitespace characters and/or statement terminators, or any single
character (e.g. y or n) possibly surrounded by whitespace."
  :type 'regexp
  :link '(custom-manual "(reduce-ide)Run Customization")
  :group 'reduce-run)

(defcustom reduce-source-modes '(reduce-mode)
  "Used to determine if a buffer contains REDUCE source code.
If a file is loaded into a buffer that is in one of the major
modes in this list then it is considered to be a REDUCE source
file by ‘reduce-input-file’ and ‘reduce-compile-file’.  Used by
these commands to determine defaults."
  :type '(repeat symbol)
  :link '(custom-manual "(reduce-ide)Run Customization")
  :group 'reduce-run)

(defcustom reduce-run-mode-hook nil
  "Hook for customising REDUCE Run mode."
  :type 'hook
  :link '(custom-manual "(reduce-ide)Hooks")
  :group 'reduce-run)

(defcustom reduce-run-load-hook nil
  "Hook run when REDUCE Run mode is loaded.
It is a good place to put keybindings."
  :type 'hook
  :link '(custom-manual "(reduce-ide)Hooks")
  :group 'reduce-run)


;;;; Keyboard and menu maps
;;;; ======================

;; The key sequences C-c followed by a control character or digit are
;; reserved for major modes, but do not bind C-c C-g (cancel) or C-c
;; C-h (help).  Also, avoid binding C-c C-c, C-c C-d, C-c C-z and C-c
;; C-\, which are bound by Comint mode.

(defvar-keymap reduce-run-mode-map
  :doc "Keymap for REDUCE Run mode."
  "RET" #'reduce-run-send-input
  "S-RET" #'comint-send-input
  "M-TAB" #'reduce-complete-symbol
  "C-c TAB" #'reduce-complete-symbol
  :menu
  `("REDUCE"
    ["(Re)Run REDUCE" rerun-reduce
     :help "Stop REDUCE if running in this buffer, then (re)start it"]
    ,@reduce--common-run-menu-items     ; defined in reduce-mode.el
    ["Customize…" (customize-group 'reduce-run)
     :help "Customize REDUCE Run mode"]
    ["Show Version" reduce-ide-version
     :help "Show the REDUCE IDE version"]))

(defun reduce-run--add-common-keys-to-map (map)
  "Add common key bindings to keymap MAP.
Bindings are common to REDUCE mode and REDUCE Run mode."
  (define-keymap
    :keymap map
    "C-x C-e" #'reduce-eval-last-statement ; Emacs convention
    "C-c C-M-e" #'reduce-eval-line
    "C-c C-f" #'reduce-input-file
    "C-c C-M-l" #'reduce-load-package
    "C-c C-M-c" #'reduce-compile-file
    "C-c C-M-f" #'reduce-run-file))     ; since C-M-i used by flyspell

(reduce-run--add-common-keys-to-map reduce-run-mode-map)

;; These commands augment REDUCE mode, so you can process REDUCE
;; code in file editing buffers.
(define-keymap
  :keymap reduce-mode-map
  "C-M-x"  #'reduce-eval-proc           ; Emacs convention
  "C-c C-r" #'reduce-eval-region
  "C-c C-M-b" #'reduce-run-buffer
  "C-c C-z" #'switch-to-reduce
  "M-R" #'run-reduce)

(reduce-run--add-common-keys-to-map reduce-mode-map)

(easy-menu-define                       ; (symbol maps doc menu)
  reduce-mode--run-menu
  nil
  "REDUCE mode Run menu -- \
updates autoload version when this file is loaded."
  reduce-mode--run-menu-source)         ; defined in reduce-mode.el

;; Update or add the REDUCE mode Run menu:
(let ((keymap (keymap-lookup reduce-mode-map "<menu-bar>"))
      (definition (cons "Run-REDUCE" reduce-mode--run-menu)))
  ;; Redefine the REDUCE mode Run menu autoload version if it exists:
  (if (keymap-lookup keymap "<run-reduce>")
      (keymap-set keymap "<run-reduce>" definition)
    ;; Otherwise, put the REDUCE Mode Run menu on the menu bar AFTER
    ;; the REDUCE menu:
    (keymap-set-after keymap "<run-reduce>" definition 'REDUCE)))


;;; Functions to run REDUCE in a buffer
;;; ===================================

(defvar reduce-run--buffer-alist nil
  "This variable holds an alist of REDUCE process buffers (RPBs).
It is used to name new RPBs appropriately and decide where to
send REDUCE input.")

(declare-function reduce-font-lock--run-mode "reduce-font-lock" ())
(declare-function reduce-show-delim-mode "reduce-delim" ())

(define-derived-mode reduce-run-mode comint-mode "REDUCE Run"
  "Major mode for interacting with a REDUCE process – part of REDUCE IDE.
Version: see variable ‘reduce-ide-version’.\\<reduce-run-mode-map>
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
  :group 'reduce-run
  :syntax-table reduce-mode-syntax-table
  ;; Optionally set up font-lock-mode:
  (and reduce-font-lock-mode-on
       (require 'reduce-font-lock "reduce-font-lock" t)
       (reduce-font-lock--run-mode))
  ;; Optionally set up reduce-show-delim-mode:
  (and reduce-show-delim-mode-on
       (require 'reduce-delim "reduce-delim" t)
       (reduce-show-delim-mode))
  (setq comint-input-filter #'reduce-run--input-filter  ; buffer-local
        comint-input-ignoredups t)                 ; buffer-local
  ;; ansi-color-process-output may cause an error on MS Windows when
  ;; CSL is terminated and is probably irrelevant anyway, so …
  (when (eq system-type 'windows-nt)
    (remove-hook (make-local-variable 'comint-output-filter-functions)
                 'ansi-color-process-output t)) ; remove locally!
  ;; Try to ensure graceful shutdown. In particular, PSL REDUCE on
  ;; Windows seems to object to being killed!
  (add-hook 'kill-buffer-hook #'reduce-run--kill-buffer-tidy-up)
  (add-hook 'kill-emacs-hook #'reduce-run--kill-emacs-tidy-up))

(defun reduce-run--input-filter (str)
  "True if STR does not match variable ‘reduce-input-filter’."
  (not (string-match reduce-input-filter str)))

(defvar reduce-run--history nil
  "Input history for the ‘run-reduce’ command.")

;;;###autoload
(defun run-reduce (&optional label)
  "Run REDUCE with I/O via a buffer.
If LABEL is non-nil, append it to the process and buffer names.

Prompt with completion for a REDUCE command name, which defaults
initially to the value of ‘reduce-run-command-name-default’ and
subsequently to the last value used.  Look up the command
name (CMD), ignoring case, in ‘reduce-run-commands’ and run the
command found.  The buffer is in REDUCE Run mode.  If LABEL is
nil, which it is interactively, the buffer is named “*CMD
REDUCE*”; otherwise it is named “*CMD REDUCE LABEL*”.

With a prefix argument, request the actual REDUCE command and run
it in a buffer named “*REDUCE*”.

If ‘reduce-run-multiple’ in non-nil then always start a new
distinct REDUCE process; otherwise, if there is a REDUCE process
already running this command, switch to it.  Runs the hooks from
‘reduce-run-mode-hook’ (after the ‘comint-mode-hook’ is run).

\(Type ‘\\[describe-mode]’ in the process buffer for a list of commands.)

Return t unless aborted, in which case return nil."
  (interactive)
  (if current-prefix-arg
      (reduce-run--run-reduce
       (read-string "REDUCE command: " nil 'reduce-run--history) "")
    (let* ((completion-ignore-case t)
           (cmd (completing-read
                 "REDUCE command name: "
                 reduce-run-commands
                 nil t                  ; predicate require-match
                 (or (car reduce-run--history) ; initial
                     reduce-run-command-name-default)
                 'reduce-run--history)))
      (when (not (zerop (length cmd)))
        (let ((command (assoc-string cmd reduce-run-commands t)))
          ;; this test should be unnecessary…
          (if command
              (reduce-run--run-reduce (cdr command) (car command) label)
            (lwarn '(reduce-run) :warning
                   "REDUCE command name \"%s\" not found!" cmd)))))))

(defun reduce-run--run-reduce (cmd name &optional label)
  "Run CMD as a NAME REDUCE process with I/O via a buffer.
If LABEL is nil then the process is named “NAME REDUCE” and the
buffer is named “*NAME REDUCE*”; otherwise, the process is named
“NAME REDUCE LABEL” and the buffer is named “*NAME REDUCE LABEL*”.
NAME is the name of a REDUCE command in ’reduce-run-commands’ (by
default \"CSL\" or \"PSL\") or \"\".  If there is a process
already running this command name, just switch to it.
Return t if successful; otherwise return nil."
  (let ((proc-name (if (equal name "") "REDUCE" (concat name " REDUCE")))
        (reduce-run-buffer-name (assoc name reduce-run--buffer-alist))
        buf-name buf-number)
    (when label (setq proc-name (concat proc-name " " label)))
    (setq buf-name (concat "*" proc-name "*"))
    (cond (reduce-run-multiple
           ;; Always create a new process buffer with an appropriate name:
           (if reduce-run-buffer-name
               (setq buf-number (1+ (or (nth 2 reduce-run-buffer-name) 0))
                     proc-name (concat proc-name " "
                                       (number-to-string buf-number))
                     buf-name (concat "*" proc-name "*")))
           (when (reduce-run--run-reduce-1 cmd proc-name buf-name)
             (push (list name buf-name buf-number) reduce-run--buffer-alist)
             t))
          ;; Re-use any existing buffer for NAME REDUCE:
          ((and reduce-run-buffer-name
                (string-match proc-name (cdr reduce-run-buffer-name))
                (comint-check-proc buf-name))
           (pop-to-buffer buf-name)) ; just re-visit this process buffer
          (t (when (reduce-run--run-reduce-1 cmd proc-name buf-name)
               (push (list name buf-name) reduce-run--buffer-alist)
               t)))))

;; The error handling below doesn't seem helpful.  It leads to a
;; second error "No buffer named *CSL REDUCE*" from the tidy-up code!
;; Consider this again later.

;; (defun reduce-run--run-reduce-1 (cmd process-name buffer-name)
;;   "Run CMD as REDUCE process PROCESS-NAME in buffer BUFFER-NAME.
;; Return the process buffer if successful; nil otherwise."
;;   (condition-case err
;;       (progn                            ; protected form
;;         (set-buffer (reduce-run--run-reduce-2 cmd process-name))
;;         (reduce-run-mode)
;;         (pop-to-buffer buffer-name))
;;     ;; Error handler:
;;     (error            ; condition
;;      ;; Display the usual error message then tidy up:
;;      (message "%s" (error-message-string err))
;;      (kill-buffer buffer-name)
;;      nil)))

(defvar-local reduce--package-root-dir-file-name nil
  "Buffer-local REDUCE root directory file name.
Used by ‘reduce-run--package-completion-alist’ to locate the “packages”
directory for the version of REDUCE running in the current buffer.")

(defun reduce-run--run-reduce-1 (cmd process-name buffer-name)
  "Run CMD as REDUCE process PROCESS-NAME in buffer BUFFER-NAME.
Set the (buffer-local) value of ‘reduce--package-root-dir-file-name’ to
“root”.  Return the process buffer if successful; nil otherwise."
  (let ((root (reduce-run--run-reduce-2 cmd process-name)))
    (reduce-run-mode)
    (setq reduce--package-root-dir-file-name root))
  (pop-to-buffer buffer-name))

(defun reduce-run--run-reduce-2 (cmd process-name)
  "Run CMD as REDUCE process PROCESS-NAME.
Use terminal type ‘reduce-run-terminal’ if non-nil.  Return “root”."
  (if reduce-run-terminal
      (let ((comint-terminfo-terminal reduce-run-terminal)
            (system-uses-terminfo t))
        (reduce-run--run-reduce-3 cmd process-name))
    (reduce-run--run-reduce-3 cmd process-name)))

(defun reduce-run--run-reduce-3 (cmd process-name)
  "Run CMD as REDUCE process PROCESS-NAME.
CMD has the form “root.program.arguments”, where “root” is nil or the
value for both the shorthand “$reduce” and the environment variable
“reduce” within the REDUCE process; “program.arguments” is a list of
strings representing a command and its arguments.  Switch to the process
buffer and return “root”."
  (let ((process-environment process-environment)
        (root (or (car cmd) reduce-root-dir-file-name)))
    (setq cmd (cdr cmd))
    (when root
      (setq cmd
            (mapcar
             #'(lambda (s) (replace-regexp-in-string "\\`\\$reduce" root s))
             cmd))
      (push (concat "reduce=" root) process-environment))
    ;; ‘apply’ used below because last arg is &rest!
    (set-buffer (apply #'make-comint-in-buffer
                       process-name nil (car cmd) nil (cdr cmd)))
    root))

(add-hook 'same-window-regexps "REDUCE") ; ??? Not sure about this! ???

(defun reduce-run-send-input ()
  "Send input to REDUCE.
Provided REDUCE is running, the cursor is at the end of the
buffer, there is non-blank input (to support “on demo”) and there
is no final terminator or ’?’ in the current line then add a
final ’;’.  Then call ‘comint-send-input’.
\\<reduce-run-mode-map>Note that ‘\\[comint-send-input]’ calls ‘comint-send-input’ directly."
  (interactive)
  (end-of-line)
  (if (and (get-buffer-process (current-buffer))
           (eobp)
           (not (looking-back "\\([[:digit:]][:*]\\|[;$]\\)\\s-*\\|\\?.*" nil)))
      (insert ?\;))
  (comint-send-input))


;;; Functions to send code to REDUCE running in a buffer
;;; ====================================================

(defun reduce-run--send-string (string)
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

(defun reduce-run--running-buffer-p ()
  "Return non-nil if current buffer is running a REDUCE process."
  (and (eq major-mode 'reduce-run-mode)
       (get-buffer-process (current-buffer))))

(defun reduce-run--buffer-p (buf)
  "Return t if cons cell BUF represents an active REDUCE process buffer.
To be applied to each element of the buffer-read completion list,
which appears to have the form “buffer-name.buffer-object”."
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
     ((reduce-run--running-buffer-p))
     ;; Look for an *active* REDUCE process buffer (RPB):
     ((and reduce-run--buffer-alist
           (if (null (cdr reduce-run--buffer-alist)) ; at most one active RPB
               (let ((buf (cadar reduce-run--buffer-alist)))
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
                             #'reduce-run--buffer-p)))
             t)))
     ;; Start a new REDUCE process in a new window as appropriate:
     (reduce-run-autostart
      (unless switch (split-window nil nil t)) ; new window on the right
      (run-reduce)
      (reduce-run--wait-for-prompt)))
    ;; Go to the end of the buffer if required:
    (when (and to-eob (not (eobp)))
      (or no-mark (push-mark))
      (goto-char (point-max))))
  ;; Ensure that the new buffer is displayed and return its window:
  (or (get-buffer-window)
      (get-buffer-window
       (switch-to-buffer-other-window (current-buffer)))))

(defun rerun-reduce ()
  "Rerun REDUCE in the current buffer, killing it first if necessary."
  (interactive)
  (if (not (eq major-mode 'reduce-run-mode))
      (user-error "This is not a REDUCE process buffer")
    (goto-char (point-max))
    (when (get-buffer-process (current-buffer))
      (insert "bye\;")                  ; show termination explicitly!
      (comint-send-input)
      (while (progn
               (sit-for 1)
               (get-buffer-process (current-buffer))))
      (goto-char (point-max)))
    (insert ?\n)
    (let* ((buf-name (buffer-name (current-buffer))) ; "*CMD REDUCE LABEL*"
           (proc-name (substring buf-name 1 -1)) ; "CMD REDUCE LABEL"
           (cmd (string-search " REDUCE" proc-name))
                                        ; strip off " REDUCE..."
           (cmd (or (and cmd (substring proc-name 0 cmd))
                    (car reduce-run--history)))
           (cmd (cdr (assoc cmd reduce-run-commands))))
      (reduce-run--run-reduce-1 cmd proc-name buf-name))))

(define-obsolete-function-alias 're-run-reduce 'rerun-reduce "REDUCE IDE 1.10.1")


(defvar reduce-run--prev-dir/file nil
  "Record last directory and file used in inputting or compiling.
This holds a cons cell of the form “(DIRECTORY . FILE)” describing
the last ‘reduce-input-file’ or ‘reduce-compile-file’ command.")

(defvar reduce-run--prev-package nil
  "Name of last package loaded or compiled.")

(defvar reduce-run--file-name-history nil
     "A history list for REDUCE Run mode source file-name arguments.")

(defun reduce-run--get-source (prompt)
  "Get, check and save a REDUCE source file-name using prompt string PROMPT."
  ;; Need to rewrite this messy function!
  (let* ((file-name-history reduce-run--file-name-history)
     (file-name
      (car (comint-get-source prompt reduce-run--prev-dir/file
                  reduce-source-modes t))))
    (comint-check-source file-name)  ; Check to see if buffer should be saved.
    (setq reduce-run--prev-dir/file (cons (file-name-directory file-name)
                     (file-name-nondirectory file-name)))
    ;; Save filenames in MRU order, once only:
    (setq reduce-run--file-name-history
      (cons file-name (delete file-name (cdr file-name-history))))
    (list file-name)            ; Yuk!
    ))

(defun reduce-input-file (file-name)
  "Input REDUCE source file FILE-NAME into a REDUCE process.
Interactively, switch to a REDUCE process buffer first;
otherwise assume the current buffer is a REDUCE process buffer.
The user always chooses interactively whether to echo file input."
  (interactive (reduce-run--get-source "Input REDUCE file: "))
  (if (called-interactively-p 'any)
      (switch-to-reduce t t t))
  (reduce-run--send-string
   (format "in \"%s\"%c" file-name
           (if (y-or-n-p "Echo file input? ") ?\; ?$))))

(defun reduce-run--wait-for-prompt ()
  "Wait for a REDUCE prompt in the current buffer.
After waiting for 10 seconds, throw an error.
Otherwise, leave point after the prompt, i.e. at end of buffer.
Assume the current buffer is a REDUCE process buffer!"
  (let ((count 10))
    (while (progn
             (when (<= (setq count (1- count)) 0)
               (error "Timeout waiting for REDUCE prompt"))
             (goto-char (point-max))
             ;; Unlike ‘beginning-of-line’, forward-line ignores field
             ;; boundaries (cf. ‘comint-bol’)
             (forward-line 0)
             (not (looking-at reduce-run-prompt)))
      (sit-for 1)))
  (goto-char (point-max)))

(defalias 'reduce-fasl-file 'reduce-compile-file)

(defun reduce-compile-file (file-name)
  "Compile REDUCE source file FILE-NAME to a FASL image in the REDUCE process.
The user chooses whether to echo file input."
  (interactive (reduce-run--get-source "Compile REDUCE file: "))
  (let ((fasl-name (file-name-sans-extension (cdr reduce-run--prev-dir/file))))
    (setq fasl-name (read-minibuffer "FASL name: " fasl-name)
          reduce-run--prev-package fasl-name)
    (switch-to-reduce t t t)
    (reduce-run--send-string (format "faslout %s;" fasl-name))
    (reduce-run--wait-for-prompt)
    (reduce-input-file file-name)
    (reduce-run--wait-for-prompt)
    (reduce-run--send-string "faslend;")))


;;; Support for loading REDUCE packages
;;; ===================================

(defvar-local reduce-run--package-completion-alist nil
  "Alist of REDUCE packages used for completion by ‘reduce-load-package’.
It is buffer-local and specific to each version of REDUCE.")

(defun reduce-run--package-completion-alist ()
  "Return the value of variable ‘reduce-run--package-completion-alist’.
Build it if necessary by processing \"$reduce/packages/package.map\"
using the (buffer-local) value of ‘reduce--package-root-dir-file-name’."
  ;; Errors are trapped by customization, so report problems using
  ;; message.
  (or reduce-run--package-completion-alist
      (let ((dir (concat reduce--package-root-dir-file-name "/packages/")))
        (if (not (file-accessible-directory-p dir))
            (progn (message "Directory %s is not accessible" dir) nil)
          (let ((package.map (concat dir "package.map")))
            (if (not (file-readable-p package.map))
                (progn (message "File %s is not readable" package.map) nil)
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
                        packages
                        (sort packages :lessp #'string< :in-place t)
                        ;; was (sort packages #'string<) => in place
                        reduce-run--package-completion-alist
                        (mapcar #'list packages))))))))))

(defvar reduce-run--load-package-history nil
     "A history list for ‘reduce-load-package’.")

(defun reduce-load-package (package)
  "Load REDUCE package PACKAGE into the appropriate REDUCE process."
  (interactive
   (let ((default
           (or (and reduce-run--prev-package
                    (if (symbolp reduce-run--prev-package)
                        (symbol-name reduce-run--prev-package)
                      reduce-run--prev-package))
               (cdr reduce-run--prev-dir/file)
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
       (reduce-run--package-completion-alist)
       nil              ; predicate
       nil              ; require-match
       nil              ; initial
       reduce-run--load-package-history
       default)
      )))
  (setq reduce-run--prev-package package)
  (switch-to-reduce t t t)
  (reduce-run--send-string (format "load_package %s;" package)))


;;; Functions to run a REDUCE file or buffer in a new process buffer
;;; ================================================================
;;; (essentially as requested by Raffaele Vitolo)

;;;###autoload
(defun reduce-run-file (filename echo)
  "Run FILENAME as a REDUCE program in a new process buffer.
Echo the file contents if ECHO is non-nil.  Start a new REDUCE
process named from FILENAME and input FILENAME."
  (interactive (list
                (read-file-name "Run REDUCE file: ")
                (y-or-n-p "Echo file input? ")))
  (reduce-run--file-or-buffer
   (file-name-nondirectory filename)
   (format "in \"%s\"%c" filename (if echo ?\; ?$))))

;;;###autoload
(defun reduce-run-buffer ()
  "Run current buffer as a REDUCE program in a new process buffer.
Start a new REDUCE process named from the current buffer and
input the current buffer."
  (interactive)
  (reduce-run--file-or-buffer (buffer-name) (buffer-string)))

(defun reduce-run--file-or-buffer (label input)
  "Run INPUT as a REDUCE program in a new process buffer.
Start a new REDUCE process named from file or buffer LABEL and
input INPUT."
  (when (run-reduce label)
    (reduce-run--wait-for-prompt)
    (insert input)
    ;; Avoid triggering spurious prompts when inserting a buffer:
    (delete-blank-lines)                ; from end of inserted buffer
    (if (bolp) (delete-char -1))        ; delete previous newline
    (comint-send-input)))


;;; Ancillary functions
;;; ===================

(defun reduce-run--send-bye (proc)
  "Send PROC the string \"bye;\"."
  (process-send-string proc "bye\;\n"))

(defun reduce-run--kill-buffer-tidy-up ()
  "Hang on ‘kill-buffer-hook’ to terminate the REDUCE process tidily.
Also remove the buffer from ‘reduce-run--buffer-alist’."
  (if (eq major-mode 'reduce-run-mode)
      (let ((proc (get-buffer-process (current-buffer))))
        (if proc (reduce-run--send-bye proc))
        (setq reduce-run--buffer-alist
              (seq-remove (lambda (x) (equal (cadr x) (buffer-name)))
                          reduce-run--buffer-alist)))))

(defun reduce-run--process-p (proc)
  "True if PROC is a REDUCE process."
  (save-excursion
    (and (setq proc (process-buffer proc))
     (set-buffer proc)
     (eq major-mode 'reduce-run-mode))))

(defun reduce-run--kill-emacs-tidy-up ()
  "Hang on ‘kill-emacs-hook’ to terminate all REDUCE processes."
  (mapcar (function
       (lambda (proc)
         ;; If PROC is a REDUCE process then send it the string ‘bye;’
         ;; and pause to allow it to take effect (before Emacs dies).
         (cond ((reduce-run--process-p proc)
            (reduce-run--send-bye proc)
            ;; The time may need tuning on different systems.
            ;; For me, anything less than 1 second is unreliable.
            (sit-for 1 t)   ; no redisplay
            ))))
      (process-list)))


;;; Do the user's customisation…
;;; ============================

(provide 'reduce-run)

(run-hooks 'reduce-run-load-hook)

;; Temporary backward compatibility code run at load time:

(defun reduce-run--args-to-list (cmd)
  "Break CMD into a list of program and arguments.
The program path-name *may* include spaces.
This ignores quotes and escapes and so will fail if you have an
argument with whitespace, as in cmd = \"-ab +c -x \='you lose\='\"."
  (let ((dir (file-name-directory cmd)))
    (cond (dir
           (setq cmd (reduce-run--args-to-list-1
                      (file-name-nondirectory cmd)))
           (cons (concat dir (car cmd)) (cdr cmd)))
          (t (reduce-run--args-to-list-1 cmd)))))

(defun reduce-run--args-to-list-1 (cmd)
  "Break CMD into a list of program and arguments recursively.
The program path-name *must not* include spaces.
This ignores quotes and escapes and so will fail if you have an
argument with whitespace, as in cmd = \"-ab +c -x \='you lose\='\"."
  (let ((where (string-match "[ \t]" cmd)))
    (cond ((null where) (list cmd))
          ((/= where 0)
           (cons (substring cmd 0 where)
                 (reduce-run--args-to-list-1
                  (substring cmd (1+ where)))))
          (t (let ((pos (string-match "[^ \t]" cmd)))
               (unless (null pos)
                 (reduce-run--args-to-list-1
                  (substring cmd pos))))))))

(when (stringp (cdar reduce-run-commands))
  ;; Update ‘reduce-run-commands’ to new structure.
  (setq reduce-run-commands
        (mapcar
         #'(lambda (x)
             (cons (car x) (cons nil (reduce-run--args-to-list (cdr x)))))
         reduce-run-commands))
  (put 'reduce-run-commands 'customized-value reduce-run-commands)
  (when (y-or-n-p "Option ‘reduce-run-commands’ updated to new structure.  \
Please check, edit and/or save it for future sessions.  Do it now?")
    (customize-option 'reduce-run-commands)))

;;; reduce-run.el ends here
