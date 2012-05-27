%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:pipes.sl 
% Title:        Unix pipe interface
% Author:       Winfried Neun
% Created:      5 February 1991
% Status:       Experimental 
% Mode:         Lisp 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(compiletime (load "c:/psl/nonkern/dos386/lap/io-decls"))

(de pipe-open(cmd type)

  (prog (filedes)
   (when (or (not (stringp cmd))
	     (and (not (eq type 'input)) (not (eq type 'output))))
       (return (ioerror "Illegal parameter to pipe-open")))

   (when (eq type 'input)
   (setq filedes (syspopen cmd "r"))
   (setf (wgetv lineposition filedes) 0)
   (setf (wgetv maxline filedes) 80)
   (setf (wgetv unreadbuffer filedes) (char null))
   (setf (wgetv readfunction filedes)  'independentreadchar)
   (setf (wgetv writefunction filedes) 'readonlychannel)
   (setf (wgetv closefunction filedes) 'independentclosepipe)
   (setf (wgetv nextposition  filedes) 0)   % Will be post Incremented
   (setf (wgetv bufferlength  filedes) -1)
   (setf (wgetv maxbuffer filedes) (sysmaxbuffer (wgetv channeltable filedes)))
   (setf (igetv iobuffer  filedes) (mkstring (wgetv maxbuffer filedes) 32))
   )

   (when (eq type 'output)
   (setq filedes (syspopen cmd "w"))
   (setf (wgetv lineposition filedes) 0)
   (setf (wgetv maxline filedes) 80)
   (setf (wgetv unreadbuffer filedes) (char null))
   (setf (wgetv readfunction filedes)  'writeonlychannel)
   (setf (wgetv writefunction filedes) 'independentwritechar)
   (setf (wgetv closefunction filedes) 'independentclosepipe)
   (setf (wgetv nextposition  filedes) 0)   % Will be post Incremented
   (setf (wgetv maxbuffer filedes) (sysmaxbuffer (wgetv channeltable filedes)))
   (setf (wgetv bufferlength filedes) (wgetv maxbuffer filedes))
   (setf (igetv iobuffer filedes) (mkstring (wgetv maxbuffer filedes) 32))
   )


  (return  filedes)))


(de syspopen (cmd type)
 
  (let ((channel (findfreechannel)) )
    (setf (wgetv channelstatus channel) 'channelopenspecial)
    (setf (wgetv channeltable  channel) (syspipeopen cmd type))
    channel
    ))
 
 
(de independentclosepipe (channel)

  (testlegalchannel channel)
  (pclose (wgetv channeltable channel))
  )

%-------------------------- windows pipe support ----------------------------

(fluid '(**windows))

(compiletime (load include))
(compiletime (include "C:/psl/kernel/dos386/windows/psllcall.h"))

(de syspipeopen(name type)
 (let (p) 
  (cond ((not (stringp name))(nonstringerror name 'pipe-open))
	((not (weq **windows 1))(stderror "pipes only under windows"))
	(t 
	  (setq p (psll-call (strbase (strinf name))
		      0 0
		      PIPE_OPEN)) 
	  (when (eq p 0)
		(stderror "cannot open windows pipe"))
	  p
		      ))))
	
(de pclose(pipe)
     (psll-call pipe 0 0 PIPE_CLOSE))

(off fast-integers)


