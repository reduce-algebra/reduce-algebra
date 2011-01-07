%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         TERMIO.SL
% Description:  Terminal i-o with protocol and pagemode
% Author:       Herbert Melenk
% Created:      4-April-90
% Modified:
% Package:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load inum fast-vector fast-int))

(compiletime (flag '(reset-terminal-page sync-terminal
		     char-to-protfile beiss-ab)
		   'internalfunction))


(compiletime (progn
      (define-constant ESC         16#01B)
      (define-constant BELL        16#007)
   % cursor
      (define-constant BACKSPACE   16#008)
      (define-constant DELETE      16#153)
      (define-constant INSERT      16#152)
      (define-constant HOME        16#147)
      (define-constant END         16#14F)
      (define-constant UP          16#148)
      (define-constant DOWN        16#150)
      (define-constant RIGHT       16#14D)
      (define-constant LEFT        16#14B)
   % page
      (define-constant PAGEUP      16#149)  % I
      (define-constant PAGEDOWN    16#151)  % Q
   % tabulator
      (define-constant TABLEFT     16#10f)
      (define-constant TABRIGHT    16#009)
))


(fluid '(oldterminalinputhandler oldterminaloutputhandler protfile 
	 morechars* terminaldir  linebuffer*
	 pagelength* bufferfile!* *page **windows))

(flag '(page) 'switch)

(setq pagelength* 23)

(when (null oldterminalinputhandler)
      (setq oldterminalinputhandler (wgetv readfunction 0))
      (setq oldterminaloutputhandler (wgetv writefunction 1))
)

(de hard-readch()
  % hard-wired terminal input
  (prog(c)
    (&time-control nil)
    (setq c (int_7))
    (&time-control t)
    (return (wand c 16#ff))))

(de hard-princ(c) 
  (&time-control nil)   
  (int_2 (wand c 16#ff))
  (&time-control t))


(de protfile (u)
    (when (weq **windows 1)
	  (stderror "use dribble file from Edit menu instead"))
    (when protfile (close protfile))
    (setq protfile nil)
    (cond ((or (equal u "") (null u)(eq u T)) nil)
	  ((stringp u) (setq protfile (open u 'OUTPUT)) u)
	  ((idp u)(setq protfile (open (id2string u) 'OUTPUT)) u)
	  (t (stderror "protfile must be called with string or id"))))

(de newterminalinputhandler (u)
  (prog(c)
    (when (not *page)
       (return
	 (idapply oldterminalinputhandler (list u))))

	   % fresh buffer necessary
    (when (wgreaterp (wgetv nextposition u)
		     (wgetv bufferlength u))
	  (channelwritestring promptout*
	     (if (stringp promptstring*) promptstring* ">"))
	  (flushbuffer promptout*)
	  (when (weq promptout* stdout*)
		(setf (wgetv lineposition promptout*) 0))
	  (setf (wgetv bufferlength u)
		(line-from-terminal u))
	  (setf (wgetv nextposition u) 0) )

	  % pick character from buffer
    (setq c (strbyt (strinf(igetv iobuffer u))
		     (wgetv nextposition u)))
    (setf (wgetv nextposition u)
	       (iadd1 (wgetv nextposition u)))

	  % page control and protocol generation
    (reset-terminal-page)
    (when protfile (when (weq terminaldir 1)
			 (channelterpri protfile)
			 (setq terminaldir -1))
		   (char-to-protfile c))
    (return c)))

(de newterminaloutputhandler (ch u)
  (prog(ll p)
    (when (not *page) (go ready))
    (setq ll (isub1 (wgetv maxline ch)))
    (setq p (wgetv lineposition ch))
    (when (and (wgreaterp p 0) (izerop (iremainder p ll)))
	  (setf (wgetv pageposition ch) (iadd1 (wgetv pageposition ch)))
	  (when (and bufferfile!* (eq ch 1))
		(channelterpri bufferfile!*)))
    (when (and pagelength* (intp pagelength*)
	       (wgreaterp (wgetv pageposition ch) pagelength*))
	   (idapply  oldterminaloutputhandler (list ch (char eol)))
	   (mapc '(- - M  !o !r !e - -)
		  (function hard-princ))
	   (reset-terminal-page)
	   (sync-terminal))
    (when (and bufferfile!* (eq ch 1))
	   (channelwritechar bufferfile!* u))
    (when (and protfile (eq ch 1))
	  (when (weq terminaldir -1)
		(channelterpri protfile)
		(setq terminaldir 1))
	  (char-to-protfile u))
  ready
    (return (idapply oldterminaloutputhandler (list ch u)))))

(de char-to-protfile(u)
     (cond ((weq u (char (cntrl m))))    % ignore
	   ((weq u (char (cntrl j))) (channelterpri protfile))
	   (t (channelwritechar protfile u))))

(de reset-terminal-page()
    (setf (wgetv lineposition 1) 0)
    (setf (wgetv pageposition 1) 0))

(de sync-terminal() 
   (let ((c (hard-readch)))
    (if (eq c (char (cntrl C)))
	(stderror "break from terminal ")
     %  (setq morechars* (append morechars* (list c)))
   )))

(de pagelength(n)
  (prog(m)
   (setq m pagelength*)
   (if (not (intp n)) (stderror "*** illegal parameter for pagelength")
		      (setq pagelength* n))
   (return m)))

(compiletime (define-constant PAGE 35))

(de pageon(i)
  (prog()
   (when (weq **windows 1) (return (psll-call i 0 0 PAGE)))
   (when  (weq i 1)
	  (setf (wgetv readfunction 0) 'newterminalinputhandler)
	  (setf (wgetv pageposition 1) 0)
	  (setf (wgetv writefunction 1)'newterminaloutputhandler)
)))

(pageon 0)

(put 'page 'simpfg '((nil (pageon 0))
		     (t (pageon 1))))

(de pagebuffer(n)
  (when (null (getd 'mf-open)) (load1 'memio))
  (when (null bufferfile!*) (setq bufferfile!* (mf-open "buffer" 'output)))
  (mf-setmax bufferfile!* n))

(pagebuffer 200)

(compiletime

(ds page-over(u v n)
  % move n elements from u to v as long as possible
   (ifor (from i 1 n 1)
	 (do
	   (when u
	      (setq v (cons (car u) v))
	      (setq u (cdr u)) ))))
)

(de wposmin(n m)
   % positive minimum from n and m
    (setq n (if (wgreaterp n m) m n))
    (if (wlessp n 0) 0 n))


(de show-page()
   (let*((bf bufferfile!*)
	 (bufferfile!* nil)
	 (pl pagelength*)
	 (pagelength* nil)
	   fwd bwd
	   x y n)
    (prog()
       (reset-terminal-page)
       (setq bwd (reversip (mf2list bf)))
       (page-over bwd fwd pl)
  show (setq y (print-page fwd bwd pl))
  cmd  (setq x (char-from-terminal))
       (cond
	     ((eq x HOME)
	      (setq fwd (append (reverse bwd) fwd))
	      (setq bwd nil)
	      (go show))
	     ((eq x UP)
	      (page-over bwd fwd 5)
	      (go show))
	     ((eq x DOWN)
	      (page-over fwd bwd 
		    (wposmin 5 (wdifference (length fwd) pl)))
	      (go show))
	     ((eq x PAGEUP)
	      (page-over bwd fwd pl)
	      (go show))
	     ((eq x PAGEDOWN)
	      (page-over fwd bwd
		   (wposmin pl (wdifference (length fwd) pl)))
	      (go show))
	    )
       (reset-terminal-page)
       (return x)
  )))

(de char-from-terminal()
   (prog (x y)
      (setq x (hard-readch))
      (when (not (eq x 0))
			(when (wgreaterp x 127) (setq x 1))
		(return x))
      (setq y (hard-readch))
      (return  (wplus2 16#100 y))))

(de print-page(fwd bwd n)
    (terpri)
    (hard-line (when (null bwd) '(T O P)))
    (terpri)
    (ifor (from i 1 n 1)
	  (do
	     (when fwd
		(prin2 (car fwd))
		(setq fwd (cdr fwd)))))
    (hard-line (when (null fwd) '(B O T T O M))) )

(de hard-line(text)
    (ifor (from i 1 35 1) (do (hard-princ (char -))))
    (mapc text (function hard-princ))
    (ifor (from i 1 35 1) (do (hard-princ (char -))))
)

(flag '(pagelength protfile pagebuffer) 'opfn)

(compiletime
  (ds linebyte(x) (strbyt (strinf ln) x))
)

(de line-from-terminal(u)
    (prog (ln c n xn mx ins lb lbr ol lth)
       (setq lb linebuffer*)
       (setq ins t)
       (setq ln (igetv iobuffer u))
       (setq mx (wgetv maxbuffer u))
       (setq n -1  xn -1)
 next  (when (not (wgreaterp mx n)) (go ready1))
       (setq c (if morechars* (pop morechars*) (char-from-terminal)))
       (when (or (eq c PAGEUP) 
	     )
	     (setq c (show-page))
	     (terpri)
	     (ifor (from i 0 n 1)
		 (do
		   (hard-princ
		     (strbyt (strinf ln) i))))
       )
       (when (eq c UP)   % fetch old line
	     (when (null lb) (go next))
	     (clear-line n xn)
	     (setq ol (pop lb))
	     (push ol lbr)
	     (go copyline))
       
       (when (eq c DOWN)   % fetch old line
	     (clear-line n xn) (setq n (setq xn -1))
	     (when (null lbr) (go next))
	     (setq ol (pop lbr))
	     (push ol lb)
	     (go copyline))

    ret
       (cond
	     ((eq c ESC)
	      (clear-line n xn) (setq n (setq xn -1))
	      (go next))

	     ((eq c HOME)
	      (ifor (from i (isub1 n) -1 -1)
		    (do (progn (setq n i) (hard-princ BACKSPACE)))))
	     
	     ((eq c END)
	      (ifor (from i (iadd1 n) xn 1)
		    (do (progn (setq n i) (hard-princ (linebyte i))  ))))
	     
	     ((eq c BACKSPACE) 
	       (when (wgeq n 0)
		 (setf n (isub1 n))
		 (hard-princ BACKSPACE)
		 (go delete)))
	     
	     ((eq c LEFT)
		(when (wgeq n 0) 
		      (hard-princ BACKSPACE)
		      (setq n (isub1 n))))
	     
	     ((eq c RIGHT)   
		(when (wlessp n xn)
		      (setq n (iadd1 n)) 
		      (hard-princ (strbyt (strinf ln) n))
		       )) 
	     
	     ((eq c DELETE)  % skip one char 
	      (go delete))

	     ((eq c INSERT) % switch inser mode 
	      (setq ins (not ins))
	      (go next))

	     ((eq c (char (cntrl C)))
	      (setf (wgetv bufferlength u) -1)
	      (stderror "break from terminal "))
	     ((and (or (eq c (char (cntrl m)))(eq c (char (cntrl D))))
		   (wlessp n xn)) 
	      (hard-princ c)
	      (setq xn (iadd1 xn))
	      (setf (linebyte xn) c)
	      (go ready)
	       )   % don't destroy line

	     (t
		 (when (and ins (wlessp n xn)) % insert ?
		    (hard-princ (char BLANK))
		    (ifor (from i (iadd1 n) xn 1)
			  (do (hard-princ (linebyte i))))
		    (ifor (from i xn n -1)
			  (do (progn 
				(setf (linebyte (iadd1 i)) (linebyte i))
				(hard-princ BACKSPACE))))
		    (setq xn (iadd1 xn))
		 )
		 (when (eq c BELL)(setq c ESC))
		 (setq n (iadd1 n))
		 (setf (strbyt (strinf ln) n) c)
		 (hard-princ c)
		 ))
       (when (wgreaterp n xn)(setq xn n))

       (when (or (eq c (char (cntrl m)))(eq c (char (cntrl D))))
	     (go ready))
       (go next)
		 
 delete                
       (when (wgeq n xn) (go next))
       (ifor (from i (iadd1 (iadd1 n)) xn 1)
	     (do (progn
		  (hard-princ (linebyte i))
		  (setf (linebyte (isub1 i))(linebyte i))
	     )))
       (hard-princ (char BLANK))
       (hard-princ BACKSPACE) 
       (ifor (from i xn (iadd1 (iadd1 n)) -1)
	     (do (hard-princ BACKSPACE)))
       (setq xn (isub1 xn))
       (go next)
 
 copyline
       (setq lth (strlen (strinf ol)))
       (ifor (from i 0 lth 1)
	     (do (progn
		     (setq c (strbyt (strinf ol) i))
		     (hard-princ c)
		     (setf (strbyt (strinf ln) i) c))))
       (setq xn lth)
       (setq n xn)
       (go next)

 ready (setq n (iadd1 n))
       (hard-princ (char eol)) 
       (ifor (from i 1 80 1)
	     (do (hard-princ BACKSPACE)))

       (setf (strbyt (strinf ln) xn) (char eol))
% ready1(setq oldlinefill* xn)
%       (ifor (from i 0 xn 1)
%             (do (setf (strbyt(strinf oldline*) i)
%                       (strbyt (strinf ln) i))))
  ready1     
       (push (subseq ln 0 xn) linebuffer*)
       (beiss-ab linebuffer* 20)
       (return xn)))

(de beiss-ab(l n)
   (cond ((null l) l)
	 ((wleq n 0) (setf (cdr l) nil))
	 (t (beiss-ab (cdr l)(isub1 n))) ))

 (de clear-line(n xn)
    (ifor (from i n 0 -1)
	  (do (hard-princ BACKSPACE)))
    (ifor (from i 0 xn 1)
	  (do (hard-princ (char blank))))
    (ifor (from i 0 xn 1)
	  (do (hard-princ BACKSPACE))))


