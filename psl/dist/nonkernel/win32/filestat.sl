(compiletime (load sys-macros))

(compiletime (flag '(mkfiletime) 'internalfunction))

                   % bignum from MS FILETIME struct
(de mkfiletime (low high)
   (let ((bi (gtpos 2)))
        (wputv (inf bi) 2 low)
        (wputv (inf bi) 3 high)
        (cons 'filetime bi)))

(de filestatus (filenamestring dostrings)
  (let ((status (get_file_status
		 (expand_file_name (unixstring filenamestring))
		 filestatus-work
		 (if dostrings 1 0))))
    (if (weq status -1) nil
     (when (and (weq status 0) (getd 'gtpos))    % 0 = success
         (list (cons 'createtime (mkfiletime (wgetv filestatus-work 0)
                                             (wgetv filestatus-work 1)))
               (cons 'accesstime (mkfiletime (wgetv filestatus-work 2)
                                             (wgetv filestatus-work 3)))
                (cons 'writetime (mkfiletime (wgetv filestatus-work 4)
                                             (wgetv filestatus-work 5))))
))))


