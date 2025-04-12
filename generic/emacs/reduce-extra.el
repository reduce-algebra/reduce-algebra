;;; reduce-extra.el --- Experimental optional extra REDUCE functionality -*- lexical-binding:t -*-

;; Copyright (C) 2024, 2025 Francis J. Wright

;; Author: Francis J. Wright <https://sites.google.com/site/fjwcentaur>
;; Created: September 2024
;; Time-stamp: <2025-03-17 16:00:51 franc>
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

;; Currently, this file is loaded via ‘reduce-mode-load-hook’.  It is
;; experimental, may be subject to possibly incompatible changes, and
;; may not be documented in the REDUCE IDE manual.

;;; Code:

(defvar reduce-mode-map)                ; defined in "reduce-mode.el"

;; ***** Requires Emacs 29.1 for keymap-set. *****


;; Add optional word motion functionality to move by a REDUCE
;; identifier or number; see ‘Word Motion’ in the ELisp manual.
;; Currently, ‘reduce-word-mode’ is turned on automatically via
;; ‘reduce-mode-hook’.

(keymap-set reduce-mode-map "C-S-<right>" 'reduce-forward-word)
(keymap-set reduce-mode-map "C-S-<left>" 'reduce-backward-word)

(defun reduce-forward-word (arg)
  "Move forwards to the next end of an identifier or number.
This applies within comments.  An identifier is a letter or escape
sequence followed by one or more alphanumeric characters or underscores
or escape sequences; an escape sequence is ‘!’ followed by any
character.  A number is an integer or a float, which may include a
positive or negative exponent.  With prefix argument ARG, do it ARG
times if positive, or move backwards ARG times if negative."
  ;; cf. ‘forward-symbol’, ‘forward-word’, ‘backward-word’
  (interactive "p")
  (if (< arg 0)
      (reduce-backward-word (- arg))
    (while (> arg 0)
      (when (eq (char-before) ?!) (backward-char))
      (re-search-forward "\\([[:digit:]]+\\)\\|\
\\(?:\\sw\\|\\s_\\|!.\\)+" nil t)
      ;; If this has found an integer then it may be part of a
      ;; float, in which case move to the end of the float:
      (when (match-beginning 1)
        (re-search-forward "\\=\\(?:\\.[[:digit:]]*\\)?\
\\(?:[eE][+-]?[[:digit:]]+\\)?" nil t))
      (setq arg (1- arg)))))

(defun reduce-backward-word (arg)
  "Move backwards to the next beginning of an identifier or number.
This applies within comments.  An identifier is a letter or escape
sequence followed by one or more alphanumeric characters or underscores
or escape sequences; an escape sequence is ‘!’ followed by any
character.  A number is an integer or a float, which may include a
positive or negative exponent.  With prefix argument ARG, do it ARG
times if positive, or move forwards ARG times if negative."
  ;; cf. ‘forward-symbol’, ‘forward-word’, ‘backward-word’
  (interactive "p")
  (if (< arg 0)
      (reduce-forward-word (- arg))
    (while (> arg 0)
      (when (re-search-backward "\\(?:\\sw\\|\\s_\\|!.\\)+" nil t)
        ;; ‘re-search-backward’ finds the match whose beginning
        ;; is as close as possible to the starting point,
        ;; i.e. the shortest, so...
	(while (or (< (skip-syntax-backward "w_") 0)
                   (cond ((eq (char-before (1- (point))) ?!)
                          (backward-char 2) t)
                         ((eq (char-before) ?!)
                          (backward-char) t))))
        ;; Point may be in a number, in which case move to the
        ;; beginning of the number:
        (if (string-match "\\`[[:digit:]]*\\(?:[eE][[:digit:]]+\\)?\\'"
                          (buffer-substring-no-properties
                           (point) (match-end 0)))
            (cond ((eq (char-before) ?.)
                   ;; In a float, e.g. 123.456
                   (skip-chars-backward "[:digit:]."))
                  ((memq (char-after) '(?e ?E))
                   ;; In a float, e.g. 123.456e78
                   (skip-chars-backward "[:digit:]."))
                  ((and (memq (char-before) '(?+ ?-))
                        (memq (char-before (1- (point))) '(?e ?E)))
                   ;; In a float, e.g. 123.456e+78, 123.456e-78
                   (skip-chars-backward "[:digit:].+-eE")))
          ;; Otherwise, a number preceding an identifier implies a
          ;; product, so...
          (if (looking-at "[eE]?[[:digit:]]+[^[:digit:]]")
              (skip-chars-forward "eE[:digit:]"))))
      (setq arg (1- arg)))))

;; (defun reduce-forward-identifier (arg)
;;   "Move forwards until encountering the end of an identifier.
;; This includes identifiers within comments.  An identifier is a letter or
;; escape sequence followed by one or more alphanumeric characters or
;; underscores or escape sequences; an escape sequence is ‘!’ followed by
;; any character.  With prefix argument ARG, do it ARG times if positive,
;; or move backwards ARG times if negative."
;;   ;; cf. ‘forward-symbol’, ‘forward-word’, ‘backward-word’
;;   (interactive "p")
;;   (cond ((> arg 0)
;;          (when (eq (char-before) ?!) (backward-char))
;;          (while
;;              (and
;;               (re-search-forward "\\(?:\\sw\\|\\s_\\|!.\\)+" nil 'move arg)
;;               ;; If this has found an integer then try again:
;;               (string-match "\\`[[:digit:]]*\\'"
;;                             (match-string-no-properties 0)))))
;;         ((< arg 0) (reduce-backward-identifier (- arg)))))

;; (defun reduce-backward-identifier (arg)
;;   "Move backwards until encountering the beginning of an identifier.
;; This includes identifiers within comments.  An identifier is a letter or
;; escape sequence followed by one or more alphanumeric characters or
;; underscores or escape sequences; an escape sequence is ‘!’ followed by
;; any character.  With prefix argument ARG, do it ARG times if positive,
;; or move forwards ARG times if negative."
;;   ;; cf. ‘forward-symbol’, ‘forward-word’, ‘backward-word’
;;   (interactive "p")
;;   (cond ((> arg 0)
;;          (while (> arg 0)
;;            (while
;;                (and
;;                 (when (re-search-backward "\\(?:\\sw\\|\\s_\\|!.\\)+" nil 'move)
;;                   ;; ‘re-search-backward’ finds the match whose beginning
;;                   ;; is as close as possible to the starting point,
;;                   ;; i.e. the shortest, so...
;; 	          (while (or (< (skip-syntax-backward "w_") 0)
;;                              (cond ((eq (char-before (1- (point))) ?!)
;;                                     (backward-char 2) t)
;;                                    ((eq (char-before) ?!)
;;                                     (backward-char) t))))
;;                   t)
;;                 ;; If this has found an integer then try again:
;;                 (string-match "\\`[[:digit:]]*\\'"
;;                               (buffer-substring-no-properties
;;                                (point) (match-end 0)))))
;;            ;; A number preceding an identifier implies a product, so...
;;            (skip-chars-forward "[:digit:]")
;;            (setq arg (1- arg))))
;;         ((< arg 0) (reduce-forward-identifier (- arg)))))


;; Make word motion into REDUCE word motion!  Like ‘superword-mode’
;; but (mostly!) handles not only ‘_’ but also ‘!’ correctly.

(defconst reduce--find-word-boundary-function-table
  (make-char-table nil #'reduce--find-word-bounday)
  "Assigned to `find-word-boundary-function-table'.
Done as its buffer-local value in ‘reduce-word-mode’; defers to
‘reduce--find-word-bounday’.")

(define-minor-mode reduce-word-mode
  "Toggle treatment of REDUCE identifiers and numbers as words.
REDUCE word mode is a buffer-local minor mode.  Enabling it changes the
definition of “word” to mean “REDUCE word” for movement, selection, etc.
For example, ‘!*obscure!-id!-name!*’ counts as one word."
  :lighter " !"
  (if reduce-word-mode
      (setq-local
       find-word-boundary-function-table
       reduce--find-word-boundary-function-table)
    (kill-local-variable 'find-word-boundary-function-table)))

(defun reduce--find-word-bounday (pos limit)
  "Return the position of the other word boundary.
Default word motion has completed.  If POS < LIMIT, then POS is at the
beginning of a default word, so return the position after the last
character of the identifier or number; otherwise, POS is at the last
character of a default word, so return the position of the first
character of the identifier or number."
  ;; cf. ‘subword-find-word-boundary’ in ‘subword.el’.
  (save-match-data
    (save-excursion
      (if (< pos limit)
          (reduce-forward-word 1)
        (reduce-backward-word 1))
      (point))))


;; Quickly select a block or group.

(keymap-set reduce-mode-map "C-S-<mouse-1>"
            'reduce-mark-block-or-group)
(keymap-set reduce-mode-map "C-c <space>"
            'reduce-mark-block-or-group)

(defvar reduce-mode)                    ; defined in ‘reduce-mode.el’
(defvar reduce-run-mode)                ; defined in ‘reduce-run.el’
(defvar mouse-select-region-move-to-beginning) ; defined in ‘mouse.el’

(defun reduce-mark-block-or-group (arg event)
  "Select the block or group beginning or ending at EVENT or point.
If EVENT is a mouse click then first move point to EVENT.  If a block or
group does not begin or end at point then select the smallest block or
group enclosing point.  Place mark at the beginning of the block or
group and point at the end.  With a prefix argument ARG, or if
‘mouse-select-region-move-to-beginning’ is non-nil, exchange mark and
point, i.e. place mark at the end of the block or group and point at the
beginning.  Cf. <double-mouse-1>."
  (interactive "P\ne" reduce-mode reduce-run-mode)
  (when (listp event)                   ; mouse event
    (mouse-set-point event))
  (let ((case-fold-search t))
    (cond ;; At beginning of block or group?
     ((looking-at-p "\\_<begin\\_>\\|<<"))
     ;; Within <<?
     ((and (eq (char-before) ?<) (eq (char-after) ?<))
      (left-char))
     ;; Within begin?
     ((and (looking-at-p "\\sw")
           (skip-syntax-backward "w")
           (looking-at-p "\\_<begin\\_>")))
     ;; Default -- assume within or at end of block or group.
     (t (reduce-up-block-or-group nil)))
    ;; Now at beginning of block or group.
    (push-mark nil nil t)
    (reduce-forward-sexp)
    ;; Now immediately after block or group.
    (when (or arg mouse-select-region-move-to-beginning)
      (exchange-point-and-mark))))

(provide 'reduce-extra)

;;; reduce-extra.el ends here
