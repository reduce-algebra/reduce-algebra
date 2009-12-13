%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:shmem.sl 
% Title:        Unix shared memory interface
% Author:       Winfried Neun
% Created:      5 October 1992 
% Status:       Experimental 
% Mode:         Lisp 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (progn % from /usr/include/sys/ipc.h

        (define-constant IPC_CREAT     8#01000)
	(define-constant IPC_EXCL      8#02000)
	(define-constant IPC_NOWAIT    8#04000)

	(define-constant IPC_RMID      0) % /* remove identifier */
	(define-constant IPC_SET       1) % /* set options */
	(define-constant IPC_STAT      2) % /* get options */
	(define-constant IPC_PRIVATE   0) % /* private key */

		% from /usr/include/sys/sem.h

	(define-constant SEM_UNDO      8#10000 )% set up adjust on exit entry

	(define-constant GETNCNT 3)    % /* get semncnt */
	(define-constant GETPID  4)    % /* get sempid */
	(define-constant GETVAL  5)    % /* get semval */
	(define-constant GETALL  6)    % /* get all semval's */
	(define-constant GETZCNT 7)    % /* get semzcnt */
	(define-constant SETVAL  8)    % /* set semval */
	(define-constant SETALL  9)    % /* set all semval's */
))

(on fast-integers)

(compiletime (load "$pnkl/io-decls"))

(de shm-open (cmd type)

  (prog (filedes shmid shmaddr sema)
   (unless (eq cmd 0) (setq shmid (car cmd) sema (cdr cmd)))
   (setq filedes (findfreechannel))
   (cond ((and (izerop cmd) (memq type '(input_create output_create))) t)
	 ((and (pairp cmd) (numberp (car cmd)) (numberp (cdr  cmd)) 
	   (memq type '(input_create output_create input output))) t)
	 (t (return (ioerror "Illegal parameter to shm-open"))))

   (when (eq type 'input_create)
        (setq type 'input)
	(setq shmid 
	    (shmget IPC_PRIVATE 10000 (plus2 IPC_CREAT 8#777)))
        (when (lessp shmid 1)
  		(return (ioerror "Unable to allocate shared memory"))))

   (when (eq type 'output_create)
        (setq type 'output)
        (setq shmid
            (shmget IPC_PRIVATE 10000 (plus2 IPC_CREAT 8#777)))
        (when (lessp shmid 1)
                (return (ioerror "Unable to allocate shared memory"))))

   (when (eq type 'input)
   (setq shmaddr (shmat shmid 0 0))
   (setf (wgetv channeltable filedes) (cons shmid sema))
   (setf (wgetv channelstatus filedes) 'open)
   (setf (wgetv lineposition filedes) 0)
   (setf (wgetv maxline filedes) 80)
   (setf (wgetv unreadbuffer filedes) (char null))
   (setf (wgetv readfunction filedes)  'independentreadshm)
   (setf (wgetv writefunction filedes) 'readonlychannel)
   (setf (wgetv closefunction filedes) 'independentdetachshm)
   (setf (wgetv nextposition  filedes) 0)   % Will be post Incremented
   (setf (wgetv bufferlength  filedes) 10000)
   (setf (wgetv maxbuffer filedes)
			(sysmaxbuffer (car (wgetv channeltable filedes))))
   (setf (igetv iobuffer  filedes) shmaddr ))

   (when (eq type 'output)
   (setq sema (semget IPC_PRIVATE 1 (plus2 IPC_CREAT 8#777)))
   (semctl sema 0 SETVAL 2) % will be written
   (setq shmaddr (shmat shmid 0 0) )
   (setf (wgetv channeltable filedes) (cons shmid sema))
   (setf (wgetv channelstatus filedes) 'open)
   (setf (wgetv lineposition filedes) 0)
   (setf (wgetv maxline filedes) 80)
   (setf (wgetv unreadbuffer filedes) (char null))
   (setf (wgetv readfunction filedes)  'writeonlychannel)
   (setf (wgetv writefunction filedes) 'independentwriteshm)
   (setf (wgetv closefunction filedes) 'independentdetachshm)
   (setf (wgetv nextposition  filedes) -1)  % Will be pre Incremented
   (setf (wgetv bufferlength  filedes) 10000)
   (setf (wgetv maxbuffer filedes) 
			(sysmaxbuffer (car (wgetv channeltable filedes))))
   (setf (igetv iobuffer  filedes) shmaddr))

  (return (list filedes shmid sema (wshift shmaddr -5)))))
                                      % for gc

(de independentreadshm (channel)

  % This function will read in a character from the buffer.  It will read
  % the record on buffer length overflow only.  Thus when an EOL character
  % is read, it is processed as any other character, except, if it is the last
  % one, in the record, it will do the read automatically.
  % Note, this will not read the next record until after the final character
  % has been processed.

  (testlegalchannel channel)

  % If the input buffer is empty, read another buffer full:
  
  (when (wgreaterp (wgetv nextposition channel) (wgetv bufferlength channel))
    (setf (wgetv bufferlength channel)
      %(sysreadrec (wgetv channeltable channel) (igetv iobuffer channel)))
		(wgetv (igetv iobuffer channel) 0))
    (setf (wgetv nextposition channel) 0))

  % Pull the next character out of the buffer.
  
  (let ((chr (strbyt (igetv iobuffer channel)
                     (wgetv nextposition channel))))
    (setf (wgetv nextposition channel) (+ (wgetv nextposition channel) 1))
    (when *echo
      (writechar chr))
    chr
    ))

(fluid '(sembuf*))

(setq sembuf* (gtwarray 4))

(de readfromshm (channel)
  (prog (result)
      (wputv sembuf* 0 0)
      (wputv sembuf* 1 0)
      (semop (cdr (wgetv channeltable channel)) sembuf* 1)
			 % wait for semaphore to be 0
      (setq result (channelread channel))
      (semctl (cdr (wgetv channeltable channel)) 0 SETVAL 1) % can be written
      (return result)))

(de independentwriteshm (channel chr)

  % Write a character into the buffer.  Actually dump the buffer when the
  % EOL character is found, or when the buffer is full.  This happens
  % immediately upon meeting this condition, not waiting for the
  % next character.  Note, that this places the EOL character into the
  % buffer for machine dependent treatment as CR/LF etc

  (testlegalchannel channel)
  (setf (wgetv nextposition channel) (+ (wgetv nextposition channel) 1))
  (setf (strbyt (igetv iobuffer channel) 
                (wgetv nextposition channel))
    chr)
  (when (or (equal chr (char eol))
	    (>= (add1 (wgetv nextposition channel))   % Indexed from 0
		(wgetv bufferlength channel)))        % Number of characters
    (flushbufferintoshm channel)
    )
  )

(de writetoshm (channel expr)
  (prog (result)
      (puthalfword sembuf* 0  0) % setting up sembuf for wait until semaphore
				 % changes from 0 to 1
      (puthalfword sembuf* 1 16#ffff)
      (wputv sembuf* 1 0)
      (semop (cdr (wgetv channeltable channel)) sembuf* 1)
                         % wait for semaphore to be 1
      (setq result (channelprin2 channel expr))
      (channelterpri channel)
      (return result)))


(de independentdetachshm (channel)

  (systemmarkasclosedchannel channel)
  (shmdt (igetv iobuffer channel))
  )


(de flushbufferintoshm (channel)

  % Actually output any characters still hanging around in the buffer.

  (putmem (igetv iobuffer channel) (wgetv nextposition channel))
  (setf (strbyt (igetv iobuffer channel) (wgetv nextposition channel)) 0)
  (setf (wgetv nextposition channel) -1)
  (semctl (cdr (wgetv channeltable channel)) 0 SETVAL 0) % can be read
  )


(off fast-integers)


