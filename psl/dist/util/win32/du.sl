%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           DU.SL
% Description:    PSL based UNIX style disk-used for MS-DOS
% Status:         Open Source: BSD License
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load chars))
(fluid '(du-liste))

(de du(file)
   (let (du-liste)
	 (du1 ".")
	 (when (not (stringp file))(setq file nil))
	 (off gc)
     (when file (wrs (setq file(open file 'output))))
	 (setq du-liste (reverse du-liste))
	 (while du-liste
	      (prin2 (caar du-liste))
		  (tab 10)
		  (prin2t (cdar du-liste))
		  (pop du-liste))
     (when file (wrs nil) (close file))))

(de du1(base)
 % base is the name collected so far
   (let ((n 0)
         (m 0)
		 name name1 fs type
		(dir (directory "*.*")))
   (while dir
      (setq name (pop dir))
	  (when (not (eq (car (explode2 name)) '!.))
	        (setq fs (errorset (list 'filestatus name) nil nil))
			(setq fs (if (pairp fs)(car fs) nil))
            (setq type (when fs (cddr (assoc 'MODE fs))))
			(if (eq type 16)  % dir
			  (progn
			     (setq name1 (bldmsg "%w\%w" base name))
				 (printf "cd %w\%w%n" base name)
				 (cd name)
				 (setq m (du1 name1))
				 (cd "..")
			  )
			  (setq m (when fs (cddr (assoc 'SIZE fs))))
			)
			(when (numberp m)(setq n(plus n m)))
	))
	(push (cons n base) du-liste)
	n ))
