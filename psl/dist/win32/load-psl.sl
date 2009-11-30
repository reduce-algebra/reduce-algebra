(faslout "load-psl")

 
 
% (on fast-integers)
 
(de loader-main ()
  (suck-in-files           % bootstrap files
    "ottokar.b"
    )
  (pre-main)
  )
 
(commentoutcode
(de suck-in-files (file-list)
  (for (in f file-list)
       (do (console-print-string "loading ")
       (console-print-string f)
       (console-print-string " to ")
       (unixputn nextbps)
       (console-newline)
       (faslin f))))
) 

% (off fast-integers)

(faslend)
(quit)
