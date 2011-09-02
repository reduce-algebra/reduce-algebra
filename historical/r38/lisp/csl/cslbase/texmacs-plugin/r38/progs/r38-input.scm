
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; MODULE      : r38-input.scm
;; DESCRIPTION : Reduce input converters
;; COPYRIGHT   : (C) 1999  Joris van der Hoeven and Andrey Grozin
;;               This CSL-Reduce variant is exactly the same as the
;;               earlier code apart from the name-change reduce->r38.
;;               A C Norman, 2005
;;
;; This software falls under the GNU general public license and comes WITHOUT
;; ANY WARRANTY WHATSOEVER. See the file $TEXMACS_PATH/LICENSE for details.
;; If you don't have this file, write to the Free Software Foundation, Inc.,
;; 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(texmacs-module (r38-input)
  (:use (texmacs plugin plugin-convert)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Specific conversion routines
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (r38-input-var-row r)
  (if (not (null? r))
      (begin
	(display ", ")
	(plugin-input (car r))
	(r38-input-var-row (cdr r)))))

(define (r38-input-row r)
  (display "(")
  (plugin-input (car r))
  (r38-input-var-row (cdr r))
  (display ")"))

(define (r38-input-var-rows t)
  (if (not (null? t))
      (begin
	(display ", ")
	(r38-input-row (car t))
	(r38-input-var-rows (cdr t)))))

(define (r38-input-rows t)
  (display "mat(")
  (r38-input-row (car t))
  (r38-input-var-rows (cdr t))
  (display ")"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Initialization
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(plugin-input-converters r38
  (rows r38-input-rows))
