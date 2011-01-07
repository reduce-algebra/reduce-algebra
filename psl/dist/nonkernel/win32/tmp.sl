%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(fluid '(**windows))

(copyd 'yesp-old 'yesp)

(de win-yesp(s)
   (if (eq **windows 1)
       (wneq 0 (psll-call (strbase(strinf (bldmsg "%l" s) )) 0 0 18)) 
       (yesp-old s) ))

	     
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Handling priority messages from Windows
%

(compiletime (load fast-vectors))

(fluid '(win-messages))

(setq win-messages (make-vector 31 nil))
 
(iputv win-messages 0 '(channellinelength 1 (psll-call 0 0 0 20))) 

(de prio-message1(n)
 (ifor (from i 0 31 1)
    (do
     (progn
       (when (wneq 0 (wand n 1)) (eval (igetv win-messages i)))
       (setq n (wshift n -1))
))  ))

% enable windows interrupts
(de ! yield()(psll-call 0 0 0 0))

% send message box to user
(de tellUser(q)
 (when (weq **windows 1)
       (psll-call (strbase(strinf q)) 0 0 21))
 nil)

% prompt an item (returns a string)
(de askUser(q)
   (let(a c n)
     (cond ((weq **windows 1)
	    (setq c (gtwrds 10))   % buffer for answer
	    (setq n
	       (psll-call (strbase(strinf q))
			  (strbase(strinf c))
			  40
			  21))
	       % convert string to list of chars
	    (ifor (from i 0 (isub1 n) 1)
		  (do (push (int2id (strbyt (strinf c) i)) a)))
	   )
	   (t (let ((out* 1)(in* 0))
		   (prin2t q)
		   (while (wneq (setq c(readch)) (char eol))
			  (push c a))
	   )  )
      )
      (if (null a)
	  nil
	  (compress (cons '!" (reverse (cons '!" a))))
    )))
				       
(de file_tree()
   (let(a c n)
     (cond ((weq **windows 1)
	    (setq c (gtwrds 10))   % buffer for answer
	    (setq n
	       (psll-call 0
			  (strbase(strinf c))
			  40
			  38))
	       % convert string to list of chars
	    (ifor (from i 0 (isub1 n) 1)
		  (do (push (int2id (strbyt (strinf c) i)) a)))
	   ))
      (if (null a)
	  nil
	  (compress (cons '!" (reverse (cons '!" a))))) ))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   Menu interface
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(*win-input-buffer*))

(de psl-popup-menu(callback)
   (when (not (eq **windows 1))
	 (stderror "menu service only under windows"))
   (errorset (list callback) nil nil)
   (psll-call-continue)
   nil)

(de psl-popup-menu1(m s w)
 (prog (r)
  (when (or (eq m 0)(eq m 1))
	(setq s (strbase (strinf s))))
  (setq r (psll-call m s w 36))
  (when (eq m 2)(setq r(psll-call-prioloop)))
  (return r)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  General interface for message passing DDE for windows
%
%  H. Melenk, ZIB Berlin, January 1992
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(fluid '(*message-buffer* *token-buffer* *callback-functions*))
 
(setq *message-buffer* (mkstring 128 0)
      *token-buffer* (mkstring 128 0))
 
(de send-server(handle command text)
   (test-server handle 'send-server)
   (when (not (stringp command))
	 (nonstringerror command 'send-server))
   (when (not (stringp text))
	 (nonstringerror text 'send-server))
   (psll-call handle (strbase (strinf command))
		      (strbase (strinf text))
		      CONNECT_SEND))
 
(de fetch-server(handle command)
  (prog (l n r)
   (test-server handle 'fetch-server)
   (when (not (stringp command))
	 (nonstringerror command 'fetch-server))
   (setf (strbyt (strinf *message-buffer*) 0) 0)
   (setq n
    (psll-call handle (strbase (strinf command))
		      (strbase (strinf *message-buffer*))
		       CONNECT_FETCH))
   (when (or (wleq n 0)
	     (weq 0 (strbyt (strinf *message-buffer*) 0) ))
	 (return nil))
   (setq r (copy-message *message-buffer*))
   (return r)))
 
 
(de open-server(server topic callback)
 (prog(u)
   (when (not (stringp server))
	 (nonstringerror server 'open-server))
   (when (not (stringp topic))
	 (nonstringerror topic 'open-server))
   (setq u
    (psll-call (strbase (strinf server)) (strbase (strinf topic))
	       0 CONNECT_OPEN))
   (when (wleq u 0) (return nil))
   (when callback (push (cons u callback) *callback-functions*))
   (return u)))
 
 
(de close-server(handle)
     (delasc handle *callback-functions*)
     (psll-call handle 0 0 CONNECT_CLOSE))
 
(de message-handler()
    % this routine is called when an asynchronous message has arrived;
    % action: the handle, message type and message text picked up;
    %         if there is a callback function for the handle, this
    %         is executed with the message tag and text as arguments.
  (prog(hand cb tag)
    (setq hand
       (PSLL-call (strbase (strinf *token-buffer*))
		  (strbase (strinf *message-buffer*))
		  0
		  CONNECT_ASK))
    (when (or (wleq hand 0) (eq tag 'ACK)) (return nil))
    (setq tag (intern (copy-message *token-buffer*)))
    (setq cb (assoc hand *callback-functions*))
    (when cb (apply (cdr cb)
		   (list tag
			 (copy-message *message-buffer*) )))
    (return nil) ))
 
(de test-server(handle fcn)
   (when (not (and (fixp handle)(wgreaterp handle 0)))
	 (typeerror handle fcn 'handle)))
 
(de copy-message(msg)
 % copy characters from global buffer to local string.
 (prog(l r)
   (setq l 0)
   (while (not (izerop (strbyt (strinf msg) l)))
	  (setq l (iadd1 l)))
   (setq l (isub1 l))
   (setq r (mkstring l))
   (ifor (from i 0 l 1)
	 (do (setf (strbyt (strinf r) i)
		   (strbyt (strinf msg) i))))
   (return r) ))

(de sleep(n)
  (when (eq **windows 1)  
    (psll-call n 0 0 SLEEP)))

(de psll-reset(n)
  (when (eq **windows 1)  
    (psll-call n 0 0 PSLL_RESET)))



(off fast-integers)

%% End of File.
