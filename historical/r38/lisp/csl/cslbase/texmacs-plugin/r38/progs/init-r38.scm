
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; MODULE      : init-r38.scm
;; DESCRIPTION : Initialize r38 plugin
;; COPYRIGHT   : (C) 1999  Joris van der Hoeven and Andrey Grozin
;;               version for CSL-based Reduce, A C Norman 2005
;;
;; This software falls under the GNU general public license and comes WITHOUT
;; ANY WARRANTY WHATSOEVER. See the file $TEXMACS_PATH/LICENSE for details.
;; If you don't have this file, write to the Free Software Foundation, Inc.,
;; 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(use-modules (ice-9 popen))


(define r38-doc-dir "")

(define (r38-initialize myname)
  (import-from (texmacs plugin plugin-convert))
  (lazy-input-converter (r38-input) r38)
  (lazy-menu (r38-menus) r38-help-menu)
;; If the executable for r38 refers to a file /xxx/yyy/zzz/r38 (possibly
;; via some symbolic links) I want to look for documentation in
;; /xxx/yyy/zzz/r38.doc.
;; The symbolic-link handling in guile seems to run on strings rather then
;; URLs, but the conversion backwards and forwards is unreliable in the
;; early win32 versions, so I use rather more ugly code here than you might
;; expect. Further on win32 the lstat function is not present...
  (if (defined? 'lstat)
    (while (eq? (stat:type (lstat (url->string myname))) 'symlink)
      (set! myname (string->url (readlink (url->string myname))))))
  (set! myname (url-append myname (url-parent)))
  (set! r38-doc-dir (url-append myname "r38.doc"))
  (menu-extend texmacs-session-help-icons
    (if (and (in-r38?) (url-exists? r38-doc-dir))
       |
       (=> (balloon (icon "tm_help.xpm") "r38 documentation")
           (link r38-help-menu)))))

(plugin-configure r38
  (:require (url-exists-in-path? "r38"))
;; I KNOW now that "r38" exists in my path, so it is now reasonable
;; to resolve it to find its absolute path name.
  (:initialize (r38-initialize (url-resolve-in-path "r38")))
  (:launch "r38 --texmacs")
  (:session "r38 (CSL)"))


