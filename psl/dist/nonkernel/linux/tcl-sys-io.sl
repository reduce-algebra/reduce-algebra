%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:SYSTEM-IO.SL                                            
% Description:  HP-UX specific IO routines for PSL                         
% Author:       Russ Fish, Robert R. Kessler, Martin L. Griss              
% Created:      4-May-84                                                   
% Modified:     05-Oct-87 (Harold Carr)
% Mode:         Lisp                                                       
% Package:                                                                 
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(compiletime (load io-decls sys-macros))

(fluid '(unix-stderr* unix-tty*))

%   C support code in unix-io.c imports knowledge of stdio.h .             
(fluid '(unixeof unixnull unixstderr unixstdout unixstdin unixtty))

% Managed here.                                                            
(de unixstring (s)
  % Strip tags for passing a string.                                       
  (if (stringp s)
    (strbase (mkitem fixnum-tag s))
    (stderror (bldmsg "Not a string: %p%n" s))))

(de unixstring2 (s)
  % Strip tags for passing a string.
    (mkitem fixnum-tag s))

% Use the C/stdio strlen fn
(de unixstrlen (s)
  % Count chars until null (0) char.                                      
  (external_strlen (unixstring s)))

%------------------------------------------------------------------------------
                                                                           
% Read from the FileDescriptor, putting a line record into the StringBuffer
% terminated by an EOL or EOF character.  Return the length of the string read
% as the indexing bound (one less than the number of characters read.)     

(fluid '(tclinputbuffer* globinterp))

(setq tclinputbuffer* (mkstring 200 '!t))

(de sysreadrec (filedescriptor stringbuffer)
    (prog nil
	  (when (or (weq filedescriptor unixstdin) 
		    (weq filedescriptor unixtty))
		(fflush unixstdout))
	  % Ensure prompts seen before input.                                
	  (cond ((weq filedescriptor unixstdin)
			(while (eq (getmem (unixstring2 tclinputbuffer*)) 0)
				(sleep 1))
(prin2 "was da: ")
(print (getmem (unixstring2 tclinputbuffer*)))
			(putmem (unixstring2 stringbuffer)
				(getmem (unixstring2 tclinputbuffer*)))  
			(copystringtofrom stringbuffer tclinputbuffer*)
			(return (prog1  (inf (getmem (unixstring2 tclinputbuffer*))) 
			(putmem (unixstring2 tclinputbuffer*) 0))))  
		((wneq (fgets (unixstring stringbuffer) 
			      (sysmaxbuffer filedescriptor) filedescriptor)
		       unixnull)
		 % Check that not end of file.                             
		 (return (wdifference (unixstrlen stringbuffer) 1)))
		(t % Index of EOL char.                                       
		   (progn % Return an EOF character on end of file.    
			  (setf (strbyt (strinf stringbuffer) 0) $eof$)
			  (clearerr filedescriptor)
			  % TTYs can type again after EOF.                   
			  (return 0))))))

    % Index of EOF char.
%----------------------------------------------------------------------------
                                                                           
% Write StringLength+1 characters from StringToWrite from the first position.  
                                                                           
(de syswriterec (filedescriptor stringtowrite stringlength)
  (if (and globinterp (weq filedescriptor unixstdout))
  (progn 
    (setq globinterp  (mkstring stringlength 0 ))
    (copystringtofrom globinterp stringtowrite)
    (setq globinterp (concat globinterp  (mkstring 1 0)))
	(setq globliste (cons globinterp globliste))
     stringlength)
  (fwrite (unixstring stringtowrite) (wplus2 stringlength 1) 1
          filedescriptor)))

