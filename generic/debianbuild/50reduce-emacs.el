;; -*-emacs-lisp-*-
;;
;; Emacs startup file for REDUCE

;; The maxima package follows the Debian/GNU Linux 'emacsen' policy and
;; byte-compiles its elisp files for each 'emacs flavor' (emacs19,
;; xemacs19, emacs20, xemacs20...).  The compiled code is then
;; installed in a subdirectory of the respective site-lisp directory.
;; We have to add this to the load-path:
(debian-pkg-add-load-path-item (concat "/usr/share/"
                              (symbol-name debian-emacs-flavor)
                              "/site-lisp/reduce") load-path))

(autoload 'reduce-mode "reduce-mode" "" t)
