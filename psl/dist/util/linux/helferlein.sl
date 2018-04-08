%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           Helferlein.SL
% Description:    various useful access functions
% Author:         Herbert Melenk and Winfried Neun, ZIB Berlin
% Created:        5 February 1989 (SUN4 version)
% Status:         Experimental (Do Not Distribute)
% Mode:           Lisp
% Package:        Utilities
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (setq *syslisp t))
(compiletime (load inum if-system))
(compiletime (flag '(terminalwritechar c-p-s c-p-s-nl
                     helferle-prindig) 'internalfunction))

(de memo (x) (getmem x))

(lap '((*entry memo_gs expr 1)
       (GS:)(mov (indexed (reg 1) 0) (reg 1))
	        (*exit 0) ))

(de info (x) (inf x))

(de valo (x) (symval (inf x)))

(de namo (x) (symnam (inf x)))

(de fnco (x) (wgetv symfnc (inf x)))

(de propo (x) (symprp (inf x)))

(de hasho (x) (halfword hashtable x))

(de terminalwritechar (x y) (unixputc y))

(if_system SPARC
 (progn
    (de c-p-s (stri) 
	(when (eq 0 (wand stri 3)) (console-print-string stri) )
	   (console-newline))

	(de c-p-s-nl (stri) 
	   (when (eq 0 (wand stri 3)) (console-print-string stri) )))

 (progn 
    (de c-p-s (stri) 
           (console-print-string stri) (console-newline))

    (de c-p-s-nl (stri)
           (console-print-string stri))))

(de printo (x) (puthex x 8) (terminalwritechar 32 32)
	      (terminalwritechar 32 32)
	      (terminalwritechar 32 32)

	    (case (tag x)
	         ((posint-tag negint-tag)
	                      (progn (unixputn x) (console-newline)))
	         ((fixnum-tag) (c-p-s "<fixnum>"))
	         ((bignum-tag) (c-p-s "<bignum>"))
	         ((floatnum-tag) (c-p-s "<float>"))
	         ((bytes-tag) (c-p-s "<bytes>"))
	         ((halfwords-tag) (c-p-s "<halfwords>"))
	         ((words-tag) (c-p-s "<words>"))
	         ((vector-tag) (c-p-s "<vector>"))
	         ((pair-tag) (c-p-s "<pair>"))
	         ((evector-tag) (c-p-s "<evector>"))
	         ((code-tag) (c-p-s "<code>"))
	         ((unbound-tag) (c-p-s "<unbound>"))
	         ((btr-tag) (c-p-s "<backtrace>"))
	         ((forward-tag) (c-p-s "<forward>"))
	         ((hvect-tag) (c-p-s "<h vector>"))
	         ((hwords-tag) (c-p-s "<h words>"))
	         ((hhalfwords-tag)(c-p-s "<h halfwords>"))
	         ((hbytes-tag) (c-p-s "<h bytes>"))
	         ((id-tag)(if (and (wlessp (inf x) maxsymbols)
	                           (stringp (symnam (inf x))))
	                         (c-p-s (symnam (inf x)))
	                         (console-newline)))
	         ((string-tag)(if (and (wlessp (inf x) heapupperbound)
                                       (wgeq (inf x)
                                           (inf (cdr (getd 'firstkernel))))
                                       (eq 0 (wand 3 (inf x))) % No BUS
	                               (wlessp (strlen (strinf x)) 100))
	                           (progn
	                             (terminalwritechar 34 34)
	                             (c-p-s-nl x)
				     (terminalwritechar 34 34)
                                     (console-newline))
	                           (console-newline)))
	         (nil (console-newline))
	          )
T )

(de dumpo (x n)
   (prog (outputbase* addr)
	(setq outputbase* 8)
	(when (greaterp n 255) (setq n 255))
	(console-newline)
	(printo x) (console-newline)
	(ifor (from i 0 n 1)
	  (do (progn
	        (setq addr (wplus2 (inf x) (wshift i 2)))
	        (when (eq (wand addr 31) 0)
	                  (console-newline) (puthex addr 8)
	                  (c-p-s " ---------------"))

	                  (printo (getmem addr))
	) )   )
   (return t)
)  )

(compiletime (put 'memory_abs 'opencode
  '    ( (mov (indirect (reg 1)) (reg 1)))))

(de dumpo_abs (x n)
   (prog (outputbase* addr)
        (setq outputbase* 8)
        (when (greaterp n 255) (setq n 255))
        (console-newline)
        (printo x) (console-newline)
        (ifor (from i 0 n 1)
          (do (progn
                (setq addr (wplus2 x (wshift i 2)))
                (when (eq (wand addr 31) 0)
                          (console-newline) (puthex addr 8)
                          (c-p-s " ---------------"))

                          (printo (memory_abs addr))
        ) )   )
   (return t)
)  )

(if_system Cray-2
 (de localdumpo (x n)
   (prog (outputbase* addr)
	(setq outputbase* 8)
	(when (greaterp n 255) (setq n 255))
	(console-newline)
	(printo x) (console-newline)
	(ifor (from i 0 n 1)
	  (do (progn
	        (setq addr (wplus2 (inf x) i))
	        (when (eq (wand addr  7) 0)
	                  (console-newline) (putoct addr)
	                  (c-p-s " ---------------"))

	                  (printo (localmemo addr))
	) )   )
   (return t)
))  )

 
(de puthex (it n)                % print an octal number
     (cond ((and (weq it 0) (wleq n 0)) nil)
            (t (progn
                  (puthex (wshift it -4) (wplus2 n -1))
                  (helferle-prindig (wand it 15))
)    )     )  )
 
(de helferle-prindig (dig)        % print a numeric digit
     (if (wlessp dig 10) (unixputc (wplus2 dig 48))
           (unixputc (wplus2 65 (wdifference dig 10)))))

(lap'((*entry flaggo expr 0)
      (pushfd)
	  (pop (reg 1))
	  (*exit 0)))

(compiletime (setq *syslisp nil))
