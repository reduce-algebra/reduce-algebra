;;; reduce-delim.el -- highlight matching group or block delimiter

;; Copyright (C) 2018 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Created: 22 March 2018
;; Version: $Id$	
;; Keywords: languages, faces
;; Homepage: http://reduce-algebra.sourceforge.net/reduce-ide
;; Package-Version: 1.54
;; Package-Requires: ((reduce-mode "1.54"))

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

;; Based closely on Emacs 26 paren.el --- highlight matching paren

;; Display highlighting on whatever group or block delimiter matches
;; the one before or after point.

;;; Commentary:

;; In a REDUCE mode buffer, execute `M-x reduce-show-delim-mode' to
;; toggle this buffer-local minor mode.  When on, it will display
;; highlighting on whatever group or block delimiter matches the one
;; before or after point.

;; You can also customize the variable `reduce-show-delim-mode-on' to
;; turn this mode on initially in every REDUCE mode buffer.

;;; Add matching of delim AROUND point later???

;;; Code:

(require 'reduce-mode)
(require 'paren)						; although loaded by default

(defgroup reduce-delim-showing nil
  "Showing (un)matching of group/block delimiters and enclosed expressions."
  :package-version '(reduce-mode . "1.54")
  :prefix "reduce-show-delim-"
  :group 'reduce-format-display)

(defface reduce-show-delim-match
  '((default :inherit show-paren-match))
  "Face used for a matching delimiter.
This face is used by `reduce-show-delim-mode'.
Default is the same as for `show-paren-mode'."
  :group 'reduce-delim-showing)

(defface reduce-show-delim-match-expression
  '((default :inherit show-paren-match-expression))
  "Face used for a matching delimiter when highlighting the whole expression.
This face is used by `reduce-show-delim-mode'.
Default is the same as for `show-paren-mode'."
  :group 'reduce-delim-showing)

(defface reduce-show-delim-mismatch
  '((default :inherit show-paren-mismatch))
  "Face used for a mismatching delimiter.
This face is used by `reduce-show-delim-mode'.
Default is the same as for `show-paren-mode'."
  :group 'reduce-delim-showing)

(defcustom reduce-show-delim-style
  (if (eq show-paren-style 'parenthesis) 'delimiter show-paren-style)
  "Style used when showing a matching delimiter.
Valid styles are `delimiter' (meaning show the matching delimiter),
`expression' (meaning show the entire expression enclosed by the
delimiters) and `mixed' (meaning show the matching delimiter if
it is visible, and the expression otherwise)."
  :type '(choice (const delimiter) (const expression) (const mixed))
  :group 'reduce-delim-showing)

(defvar reduce-show-delim-mode)	; defined by `define-minor-mode' below

(defcustom reduce-show-delim-delay show-paren-delay
  "Time in seconds to delay before showing a matching delimiter.
If you change this without using customize while `reduce-show-delim-mode' is
active, you must toggle the mode off and on again for this to take effect."
  :type '(number :tag "seconds")
  :initialize 'custom-initialize-default
  :set (lambda (sym val)
		 (if (not reduce-show-delim-mode)
			 (set sym val)
		   (reduce-show-delim-mode -1)
		   (set sym val)
		   (reduce-show-delim-mode 1)))
  :group 'reduce-delim-showing)

(defcustom reduce-show-delim-priority show-paren-priority
  "Priority of delimiter highlighting overlays."
  :type 'integer
  :group 'reduce-delim-showing)

(defcustom reduce-show-delim-ring-bell-on-mismatch
  show-paren-ring-bell-on-mismatch
  "If non-nil, beep if mismatched delimiter is detected."
  :type 'boolean
  :group 'reduce-delim-showing)

(defcustom reduce-show-delim-when-point-inside-paren
  show-paren-when-point-inside-paren
  "If non-nil, show delimiters when point is just inside one.
This will only be done when point isn't also just outside a delimiter."
  :type 'boolean
  :group 'reduce-delim-showing)

(defcustom reduce-show-delim-when-point-in-periphery
  show-paren-when-point-in-periphery
  "If non-nil, show delimiters when point is in the line's periphery.
The periphery is at the beginning or end of a line or in any
whitespace there."
  :type 'boolean
  :group 'reduce-delim-showing)

(defcustom reduce-show-delim-highlight-opendelim
  show-paren-highlight-openparen
  "Non-nil turns on opening delimiter highlighting when matching forward.
When nil, and point stands just before an opening delimiter, it is not
highlighted, the cursor being regarded as adequate to mark its position."
  :type 'boolean
  :group 'reduce-delim-showing)

(defvar reduce-show-delim--idle-timer nil)
(defvar reduce-show-delim--overlay
  (let ((ol (make-overlay (point) (point) nil t))) (delete-overlay ol) ol)
  "Overlay used to highlight the matching delimiter.")
(defvar reduce-show-delim--overlay-1
  (let ((ol (make-overlay (point) (point) nil t))) (delete-overlay ol) ol)
  "Overlay used to highlight the delimiter at point.")


;;;###autoload
(define-minor-mode reduce-show-delim-mode
  "Toggle visualization of matching delimiters (REDUCE Show Delim mode).
With a prefix argument ARG, enable Show Delim mode if ARG is
positive, and disable it otherwise.  If called from Lisp, enable
the mode if ARG is omitted or nil.

Show Delim mode is a buffer-local minor mode.  When enabled, any
matching delimiter is highlighted in `reduce-show-delim-style' after
`reduce-show-delim-delay' seconds of Emacs idle time."
  :group 'reduce-delim-showing
  ;; Enable or disable the mechanism.
  ;; First get rid of the old idle timer.
  (when reduce-show-delim--idle-timer
    (cancel-timer reduce-show-delim--idle-timer)
    (setq reduce-show-delim--idle-timer nil))
  (setq reduce-show-delim--idle-timer (run-with-idle-timer
									   reduce-show-delim-delay t
									   #'reduce-show-delim-function))
  (unless reduce-show-delim-mode
    (delete-overlay reduce-show-delim--overlay)
    (delete-overlay reduce-show-delim--overlay-1)))

(defun reduce-show-delim--unescaped-p ()
  "Determine whether the delimiter after point is unescaped."
  ;; Only used in the following function!
  (= (logand (skip-syntax-backward "/\\") 1) 0))

(defun reduce-show-delim--categorize-delim (pos)
  "Determine whether the characters after POS form a delimiter.
If so, return a cons (DIR . OUTSIDE), where DIR is > 0 for an
opening delimiter, < 0 for a closing delimiter, and OUTSIDE is
the buffer position of the outside of the delimiter.  |DIR| is
the width of the delimiter.  If POS is nil, or the character
isn't a delimiter, or it is an escaped delimiter, return nil."
  (if pos
	  (let ((case-fold-search t))
		(save-excursion
		  (goto-char pos)
		  (cond
		   ((and (looking-at "<<") (reduce-show-delim--unescaped-p))
			(cons 2 pos))
		   ((and (looking-at ">>") (reduce-show-delim--unescaped-p))
			(cons -2 (+ pos 2)))
		   ((and (looking-at "begin") (reduce-show-delim--unescaped-p))
			(cons 5 pos))
		   ((and (looking-at "end") (reduce-show-delim--unescaped-p))
			(cons -3 (+ pos 3))))))))

(defun reduce-show-delim--locate-delim-backward (&optional pos)
  "Locate and return the start of a delimiter ending at POS.
Use point if POS not given.  Return nil if no delimiter found."
  (save-excursion
	(if pos (goto-char pos))			; otherwise start from point
	(search-backward-regexp
	 "\\(?:<<\\|>>\\|begin\\|end\\)\\=" nil t)))

(defun reduce-show-delim--locate-near-delim ()
  "Locate an unescaped delimiter \"near\" point to show.
If one is found, return a cons (DIR . OUTSIDE), where DIR is > 0
for an opening delimiter, < 0 for a closing delimiter, and
OUTSIDE is the buffer position of the outside of the delimiter.
|DIR| is the width of the delimiter.  Otherwise return nil."
  (let* ((ind-pos (save-excursion (back-to-indentation) (point)))
		 (eol-pos
		  (save-excursion
			(end-of-line) (skip-chars-backward " \t" ind-pos) (point)))
		 ;; Delimiter (<</>>) before point?
		 (before (reduce-show-delim--categorize-delim
				  (reduce-show-delim--locate-delim-backward)))
		 ;; Delimiter after point?
		 (after (reduce-show-delim--categorize-delim (point))))
    (cond
     ;; Point is immediately outside a delimiter.
     ((and before (< (car before) 0)) before)		; closer before point
     ((and after (> (car after) 0)) after)			; opener after point
     ;; Point is immediately inside a delimiter.
     ((and reduce-show-delim-when-point-inside-paren before)) ; opener before point
     ((and reduce-show-delim-when-point-inside-paren after))  ; closer after point
     ;; Point is in the whitespace before the code.
     ((and reduce-show-delim-when-point-in-periphery
		   (<= (point) ind-pos))
      (or (reduce-show-delim--categorize-delim ind-pos)
		  ;; or inside a lone closer...
		  (reduce-show-delim--categorize-delim
		   (reduce-show-delim--locate-delim-backward eol-pos))))
     ;; Point is in the whitespace after the code.
     ((and reduce-show-delim-when-point-in-periphery
		   (>= (point) eol-pos))
      (reduce-show-delim--categorize-delim
	   (reduce-show-delim--locate-delim-backward eol-pos))))))

(defun reduce-show-delim-skip-group-forward (pos)
  "Move forwards to end of group immediately following POS.
Return t if successful; otherwise move as far as possible and return nil."
  (goto-char (+ pos 2))
  (reduce-forward-group))

(defun reduce-show-delim-skip-group-backward (pos)
  "Move backwards to start of group immediately preceding POS.
Return t if successful; otherwise move as far as possible and return nil."
  (goto-char (- pos 2))
  (reduce-backward-group))

(defun reduce-show-delim-skip-block-forward (pos)
  "Move forwards to end of block immediately following POS.
Return t if successful; otherwise move as far as possible and return nil."
  (goto-char (+ pos 5))
  (reduce-forward-block))

;; ***** Should reduce-backward-block also skip white space? *****
(defun reduce-show-delim-skip-block-backward (pos)
  "Move backwards to start of block immediately preceding POS.
Return t if successful; otherwise move as far as possible and return nil."
  (goto-char (- pos 3))
  (when (reduce-backward-block)
	(skip-chars-forward " \t")
	t))

(defun reduce-show-delim-data-function ()
  "Find the opening/closing delimiter \"near\" point and its match.
The function is called with no argument and should return either nil
if there's no opener/closer near point, or a list of the form
\(HERE-BEG HERE-END THERE-BEG THERE-END MISMATCH)
Where HERE-BEG..HERE-END is expected to be near point."
  (save-match-data
	(let* ((temp (reduce-show-delim--locate-near-delim))
		   (dir (car temp))
		   (outside (cdr temp))
		   pos mismatch here-beg here-end)
      ;;
      ;; Find the other end of the expression.
      (when dir							; +ve = opener, -ve = closer
		;; here-beg <</>> here-end
		(setq here-beg (if (> dir 0) outside (+ outside dir))
			  here-end (if (> dir 0) (+ outside dir) outside))
		(save-excursion
		  (save-restriction
			;; Determine the range within which to look for a match.
			(when blink-matching-paren-distance
			  (narrow-to-region
			   (max (point-min) (- (point) blink-matching-paren-distance))
			   (min (point-max) (+ (point) blink-matching-paren-distance))))
			;; Scan across one group within that range.
			;; Errors or nil mean there is a mismatch.
			(condition-case ()
				(progn
				  (if (cond ((eq dir +2)
							 (reduce-show-delim-skip-group-forward outside))
							((eq dir -2)
							 (reduce-show-delim-skip-group-backward outside))
							((eq dir +5)
							 (reduce-show-delim-skip-block-forward outside))
							((eq dir -3)
							 (reduce-show-delim-skip-block-backward outside)))
					  (setq pos (point))
					(setq pos t mismatch t)))
			  (error (setq pos t mismatch t)))
			;; Move back the other way and verify we get back to the
			;; starting point.  If not, these two delimiters don't really
			;; match.  Maybe the one at point is escaped and doesn't
			;; really count, or one is inside a comment.
			(when (integerp pos)
			  (unless (condition-case ()
						  (progn
							(cond ((eq dir +2)
								   (reduce-show-delim-skip-group-backward pos))
								  ((eq dir -2)
								   (reduce-show-delim-skip-group-forward pos))
								  ((eq dir +5)
								   (reduce-show-delim-skip-block-backward pos))
								  ((eq dir -3)
								   (reduce-show-delim-skip-block-forward pos)))
							(eq outside (point)))
						(error nil))
				(setq pos nil)))
			;; If found a "matching" delimiter, see if it is the right
			;; kind of delimiter to match the one we started at.
			(if (not (integerp pos))
				(if mismatch (list here-beg here-end nil nil t))
			  (let ((beg (min pos outside)) (end (max pos outside)))
				;; beg << ... >> end (???)
				(unless (memq (char-after beg) '(?< ?b ?B))
				  (setq mismatch
						(not (or (memq (char-before end) '(?> ?d ?D))
								 (memq (char-after beg) '(?< ?b ?B))))))
				(list here-beg here-end
					  (if (> dir 0)
						  (if (= dir +5) (- pos 3) (- pos 2))
						pos)
					  (if (> dir 0)
						  pos
						(if (= dir -3) (+ pos 5) (+ pos 2)))
					  mismatch)))))))))

(defun reduce-show-delim-function ()
  "Highlight the delimiters until the next input arrives."
  (let ((data (and reduce-show-delim-mode
				   (reduce-show-delim-data-function))))
    (if (not data)
        (progn
          ;; If reduce-show-delim-mode is nil in this buffer or if not
          ;; at a delimiter that has a match, turn off any previous
          ;; delimiter highlighting.
          (delete-overlay reduce-show-delim--overlay)
          (delete-overlay reduce-show-delim--overlay-1))

      ;; Found something to highlight.
      (let* ((here-beg (nth 0 data))
             (here-end (nth 1 data))
             (there-beg (nth 2 data))
             (there-end (nth 3 data))
             (mismatch (nth 4 data))
             (highlight-expression
              (or (eq reduce-show-delim-style 'expression)
                  (and there-beg
                       (eq reduce-show-delim-style 'mixed)
                       (let ((closest (if (< there-beg here-beg)
                                          (- there-end 2) (+ there-beg 2)))) ; !!!
                         (not (pos-visible-in-window-p closest))))))
             (face
              (cond
               (mismatch
                (if reduce-show-delim-ring-bell-on-mismatch
                    (beep))
                'reduce-show-delim-mismatch)
               (highlight-expression 'reduce-show-delim-match-expression)
               (t 'reduce-show-delim-match))))
        ;;
        ;; If matching backwards, highlight the closing delimiter
        ;; before point as well as its matching opening delimiter.
        ;; If matching forward, and the opening delimiter is unbalanced,
        ;; highlight the delimiter at point to indicate imbalance.
        ;; Otherwise, turn off any such highlighting.
        (if (or (not here-beg)
                (and (not reduce-show-delim-highlight-opendelim)
					 (> here-end (point))
					 (<= here-beg (point))
                     (integerp there-beg)))
            (delete-overlay reduce-show-delim--overlay-1)
          (move-overlay reduce-show-delim--overlay-1
                        here-beg here-end (current-buffer))
          ;; Always set the overlay face, since it varies.
          (overlay-put reduce-show-delim--overlay-1 'priority
					   reduce-show-delim-priority)
          (overlay-put reduce-show-delim--overlay-1 'face face))
        ;;
        ;; Turn on highlighting for the matching delimiter, if found.
        ;; If it's an unmatched delimiter, turn off any such highlighting.
        (if (not there-beg)
            (delete-overlay reduce-show-delim--overlay)
          (if highlight-expression
              (move-overlay reduce-show-delim--overlay
							(if (< there-beg here-beg) here-end here-beg)
                            (if (< there-beg here-beg) there-beg there-end)
                            (current-buffer))
            (move-overlay reduce-show-delim--overlay
                          there-beg there-end (current-buffer)))
          ;; Always set the overlay face, since it varies.
          (overlay-put reduce-show-delim--overlay 'priority
					   reduce-show-delim-priority)
          (overlay-put reduce-show-delim--overlay 'face face))))))

(provide 'reduce-delim)

;;; reduce-delim.el ends here
