
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; MODULE      : r38-menus.scm
;; DESCRIPTION : Reduce menus
;; COPYRIGHT   : (C) 1999  Joris van der Hoeven and Andrey Grozin
;;               Adapted, 2005, by Arthur Norman for the CSL version...
;;
;; This software falls under the GNU general public license and comes WITHOUT
;; ANY WARRANTY WHATSOEVER. See the file $TEXMACS_PATH/LICENSE for details.
;; If you don't have this file, write to the Free Software Foundation, Inc.,
;; 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(texmacs-module (r38-menus)
  (:use (texmacs texmacs tm-files)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Help menus
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;; I will mostly refer to .tex documentation here since at present
;; TeXmacs does not render the HTML help as neatly.

(menu-bind r38-help-menu
  ("Abstract" (load-buffer (url-append r38-doc-dir "abstract.tex")))
  ("Acknowledgement" (load-buffer (url-append r38-doc-dir "acknowl.tex")))
  ("Introduction" (load-buffer (url-append r38-doc-dir "intro.tex")))
  ---
  (-> "Programming"
      ("Structure of programs"
       (load-buffer (url-append r38-doc-dir "progstr.tex")))
      ("Expressions"
       (load-buffer (url-append r38-doc-dir "exprn.tex")))
      ("Lists"
       (load-buffer (url-append r38-doc-dir "list.tex")))
      ("Statements"
       (load-buffer (url-append r38-doc-dir "statemnt.tex")))
      ("Commands and declarations"
       (load-buffer (url-append r38-doc-dir "command.tex")))
      ("Procedures"
       (load-buffer (url-append r38-doc-dir "proc.tex")))
      ("The remember statement"
       (load-buffer (url-append r38-doc-dir "rememb.tex"))))
  (-> "Operators"
      ("Built-in prefix operators"
       (load-buffer (url-append r38-doc-dir "oper.tex")))
      ("Operators with special properties"
       (load-buffer (url-append r38-doc-dir "oper2.tex")))
      ("Map operator"
       (load-buffer (url-append r38-doc-dir "map.tex")))
      ("Substitutions"
       (load-buffer (url-append r38-doc-dir "subst.tex")))
      ("Solve operator"
       (load-buffer (url-append r38-doc-dir "solve.tex")))
      ("Root val operator"
       (load-buffer (url-append r38-doc-dir "rest.tex"))))
  (-> "Data types"
      ;;("conversions"
      ;;(load-buffer (url-append r38-doc-dir "convert.tex")))
      ("Polynomials and rational functions"
       (load-buffer (url-append r38-doc-dir "polyrat.tex")))
      ("Matrix calculations"
       (load-buffer (url-append r38-doc-dir "matrix.tex"))))
  (-> "Using reduce"
      ("Structure of expressions"
       (load-buffer (url-append r38-doc-dir "structr.tex")))
      ("File handling"
       (load-buffer (url-append r38-doc-dir "io.tex")))
      ("Interactive use"
       (load-buffer (url-append r38-doc-dir "inter.tex")))
      ("Symbolic mode"
       (load-buffer (url-append r38-doc-dir "symbolic.tex")))
      ("Rlisp '88"
       (load-buffer (url-append r38-doc-dir "rlisp88.tex")))
      ("Reduce and rlisp utilities"
       (load-buffer (url-append r38-doc-dir "util.tex"))))
  (-> "Miscellaneous"
      ("Algebraic properties"
       (load-buffer (url-append r38-doc-dir "aprop.tex")))
      ("Continued fractions"
       (load-buffer (url-append r38-doc-dir "cfrac.tex")))
      ("Heuristic g.c.d."
       (load-buffer (url-append r38-doc-dir "heugcd.tex")))
      ("High energy physics"
       (load-buffer (url-append r38-doc-dir "hephys.tex"))))
  ---
  ("Maintaining reduce"
   (load-buffer (url-append r38-doc-dir "maintain.tex")))
  ("Reserved identifiers"
   (load-buffer (url-append r38-doc-dir "appenda.tex")))
  ---
  ("HTML-format index" (load-buffer (url-append r38-doc-dir "r38_idx.html"))))

