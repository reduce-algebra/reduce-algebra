
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; MODULE      : init-reduce.scm
;; DESCRIPTION : Initialize reduce plugin
;; COPYRIGHT   : (C) 1999  Joris van der Hoeven and Andrey Grozin
;;               version for CSL-based Reduce, A C Norman 2005-8
;;
;; This software falls under the GNU general public license and comes WITHOUT
;; ANY WARRANTY WHATSOEVER. See the file $TEXMACS_PATH/LICENSE for details.
;; If you don't have this file, write to the Free Software Foundation, Inc.,
;; 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(use-modules (ice-9 popen))


(define reduce-doc-dir "")

(define (reduce-initialize myname)
  (import-from (texmacs plugin plugin-convert))
  (lazy-input-converter (reduce-input) reduce)
  (lazy-menu (reduce-menus) reduce-help-menu)
;; If the executable for reduce refers to a file /xxx/yyy/zzz/reduce (possibly
;; via some symbolic links) I want to look for documentation in
;; /xxx/yyy/zzz/reduce.doc.
;; The symbolic-link handling in guile seems to run on strings rather then
;; URLs, but the conversion backwards and forwards is unreliable in the
;; early win32 versions, so I use rather more ugly code here than you might
;; expect. Further on win32 the lstat function is not present...
  (if (defined? 'lstat)
    (while (eq? (stat:type (lstat (url->string myname))) 'symlink)
      (set! myname (string->url (readlink (url->string myname))))))
  (set! myname (url-append myname (url-parent)))
  (set! reduce-doc-dir (url-append myname "reduce.doc"))
  (menu-extend texmacs-session-help-icons
    (if (and (in-reduce?) (url-exists? reduce-doc-dir))
       |
       (=> (balloon (icon "tm_help.xpm") "reduce documentation")
           (link reduce-help-menu)))))

(plugin-configure reduce
  (:require (url-exists-in-path? "reduce"))
;; I KNOW now that "reduce" exists in my path, so it is now reasonable
;; to resolve it to find its absolute path name.
  (:initialize (reduce-initialize (url-resolve-in-path "reduce")))
  (:launch "reduce --texmacs")
  (:session "reduce (CSL)"))


