%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXU:popen.sl 
% Title:        Unix popen interface
% Author:       Winfried Neun
% Created:      5 February 1991
% Status:       Experimental 
% Mode:         Lisp 
%
% (c) Copyright 1991, Konrad-Zuse-Zentrum Berlin , all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(compiletime (load "$pnkl/io-decls"))

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
   (setf (wgetv bufferlength  filedes) -1)
   (setf (wgetv maxbuffer filedes) (sysmaxbuffer (wgetv channeltable filedes)))
   (setf (igetv iobuffer  filedes) (mkstring (wgetv maxbuffer filedes) 32))
   )

  (return  filedes)))


(de syspopen (cmd type)
 
  (let ((channel (findfreechannel)) )
    (setf (wgetv channelstatus channel) 'channelopenspecial)
    (setf (wgetv channeltable  channel) (syspipeopen cmd type))
    channel
    ))
 
 
(de abandonpipe  (channel)
  (testlegalchannel channel)
  (setf (wgetv channelstatus channel) channelclosed)
  (setf (wgetv readfunction  channel) 'channelnotopen)
  (setf (wgetv writefunction channel) 'channelnotopen)
  (setf (wgetv closefunction channel) 'channelnotopen)
  (fclose (wgetv channeltable channel)))

(de independentclosepipe (channel)

  (testlegalchannel channel)
  (pclose (wgetv channeltable channel))
  )

(de syspipeopen (host mode)
  (prog (filed)
        (setq filed (popen (unixstring host) (unixstring mode)))
        (return (if (wleq filed unixnull) (contopenerror host 'input)
                  filed))))

(off fast-integers)


