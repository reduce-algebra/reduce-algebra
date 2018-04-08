%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         MEMFILES.SL
% Description:  support of files in memory
% Author:       Herbert Melenk
% Created:      4-April-90
% Modified:
% Package:
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load inum fast-vector fast-int))

(fluid '( mf-files*))

(compiletime
  (progn


        % descriptor management
     (ds make-mf() (list2vector '(MF 0 "" -1 nil nil nil 0 99999)))
     (ds mf-tag(u) (igetv u 0))
     (ds mf-des(u) (igetv u 1))
     (ds mf-name(u) (igetv u 2))
     (ds mf-mode(u) (igetv u 3))
     (ds mf-first(u)(igetv u 4))
     (ds mf-last(u) (igetv u 5))
     (ds mf-act(u) (igetv u 6))
     (ds mf-size(u) (igetv u 7))
     (ds mf-limit(u) (igetv u 8))


))
 
(de mf-dump (i) 
   (setq i (mf-find-file i))
   (list (mf-tag i) 
         (mf-des i)
         (mf-name i)
         (mf-mode i)
         nil nil nil
         (mf-size i)
         (mf-limit i)))

(de mf2list(i)
   (setq i (mf-find-file i))
   (reversip (cdr (reverse (mf-first i)))))

(de mf-print(m)
   (prog (line)
      (setq line (mf2list m))
      (while line
           (prin2 (car line))
           (setq line (cdr line)) )))


(de mf? (u)
   (if (and (vectorp u )(eq (igetv u 0) 'MF))
       t
       (stderror "illegal call to memory file package")))

(de mf-setmax(i n) (mf-setmax1 (mf-find-file i) n))
 
(de mf-setmax1(mf n) (setf (mf-limit mf) n))

(de mf-append(mf line)
   (when (mf? mf)
     (let ((l (mf-last mf)))
       (setf (car l) line)
       (setf (cdr l) (cons nil nil))
       (setf (mf-last mf) (cdr l))
       (mf-adjustsize mf 1)
)))

(de mf-adjustsize(mf n)
      (setf (mf-size mf) (wplus2 (mf-size mf) n))
      (while (wgreaterp (mf-size mf) (mf-limit mf))
             (when (not (eq (mf-first mf) (mf-last mf)))
                   (setf (mf-first mf) (cdr (mf-first mf)))
             (setf (mf-size mf) (isub1 (mf-size mf))) )))
 

(de mf-open (filename accesstype)
    (cond((eq accesstype 'OUTPUT)(mf-open-output filename))
         ((eq accesstype 'INPUT)(mf-open-input filename))
	 (t (stderror (list "unknown open type for memory file:" accesstype))) ))


(de mf-open-output (filename)
   (prog (filedes rec x)
        (setq filedes (mf-systemopenfile-output filename))
        (setq rec (make-mf))
        (setf (mf-des rec) filedes)
        (setf (mf-name rec) filename)
        (setq x (cons nil nil))
        (setf (mf-first rec) x)
        (setf (mf-last rec) x) 
        (setq mf-files* (cons (cons filedes rec) mf-files*))
        (return filedes)))
 
(de mf-systemopenfile-output (filename)
  (let ((channel (findfreechannel)))
    (setf (wgetv channeltable  channel) channel)
    (setf (wgetv channelstatus channel) 'MF)
    (setf (wgetv maxbuffer     channel) (sysmaxbuffer (wgetv channeltable
 channel)))
    (setf (wgetv readfunction  channel) 'writeonlychannel)
    (setf (wgetv writefunction channel) 'mf-writechar)
    (setf (wgetv closefunction channel) 'mf-close-1-write)
    (setf (wgetv nextposition  channel) 0)   % Will be post Incremented
    (setf (wgetv bufferlength  channel) -1)
    (setf (igetv iobuffer      channel) 
               (mkstring (wgetv maxbuffer channel) 32))
    channel
    ))

(de mf-open-input (filename) 
   (prog (filedes rec x)    
        (setq rec (mf-find-file filename))
        (when (mf-act rec) (stderror "memory file can be read only in one stream"))
        (setq filedes (mf-systemopenfile-input filename))
        (setf (mf-act rec)(mf2list filename))
        (setq mf-files* (cons (cons filedes rec) mf-files*))
        (return filedes)))
 
(de mf-systemopenfile-input (filename)
  (let ((channel (findfreechannel)))  
    (setf (wgetv channeltable  channel) channel)
    (setf (wgetv channelstatus channel) 'MF)   
    (setf (wgetv maxbuffer     channel) (sysmaxbuffer (wgetv channeltable
 channel)))
    (setf (wgetv readfunction  channel) 'mf-readchar)
    (setf (wgetv writefunction channel) 'readonlychannel)
    (setf (wgetv closefunction channel) 'mf-close-1-read) 
    (setf (wgetv nextposition  channel) 0)   % Will be post Incremented
    (setf (wgetv bufferlength  channel) -1)
    (setf (igetv iobuffer      channel) nil)   
    channel
    ))    
 
(de mf-find-file(i)
   (let((j (assoc i mf-files*)))
       (when j (setq j (cdr j)))
       (when (mf? j) j)))
 
(de mf-close(fil) (close fil))

(de mf-close-1-write(channel)
     % simply kill the references to the data structure
       (setq mf-files* (delete (assoc channel mf-files*) mf-files*))
       (setf (wgetv channelstatus channel) 0)   % CHANNELCLOSED
       nil)
 
(de mf-close-1-read(channel) 
   (let ((r (mf-find-file channel))) 
       (setf (mf-act r) nil) 
       (setq mf-files* (delete (assoc channel mf-files*) mf-files*))
       (setf (wgetv channelstatus channel) 0)   % CHANNELCLOSED 
       nil))
       
(de mf-readchar(channel)
 (let ((r (mf-find-file channel)) (w t))
  (when (wgreaterp (wgetv nextposition channel) (wgetv bufferlength channel))
      (setf w (mf-act r))
      (setf (igetv iobuffer channel) 
            (if (null w) (id2string (int2id (char eof))) (pop w)))
      (setf (mf-act r) w)
      (setf (wgetv bufferlength channel) (strlen (strinf (igetv iobuffer channel))))
      (setf (wgetv nextposition channel) 0))

  % Pull the next character out of the buffer.
  (let ((chr (strbyt (strinf (igetv iobuffer channel))
                     (wgetv nextposition channel))))
    (setf (wgetv nextposition channel) (+ (wgetv nextposition channel) 1))
    (when *echo
      (writechar chr))
    chr
    ))) 



(de mf-writechar(channel chr)
 (let ((r (mf-find-file channel)) (w t)) 
  (setf (wgetv nextposition channel) (+ (wgetv nextposition channel) 1))
  (setf (strbyt (strinf (igetv iobuffer channel))
                (wgetv nextposition channel))
    chr)
  (when (or (equal chr (char eol))
        (>= (add1 (wgetv nextposition channel))   % Indexed from 0
        (wgetv maxbuffer channel)))        % Number of characters
    (mf-flushbuffer r channel)
    )
  ))
 
(de mf-flushbuffer(mf channel)
  (prog (line buffer n)
   (setq buffer (igetv iobuffer channel))
   (setq n (wgetv nextposition channel))
   (setq line (mkstring n))
   (ifor (from i 0 n 1) (do (setf (strbyt (strinf line) i) 
                                  (strbyt (strinf buffer) i))))
   (mf-append mf line)
   (setf (wgetv nextposition channel) -1)
   ))
    
(de mfload (file)
   (when (not(filep file)) (error "file cannot be loaded"))
   (prog (mf f wold rold c)
       (setq f (open file 'INPUT))
       (setq mf (mf-open file 'OUTPUT))
       (setq wold (wrs mf))
       (setq rold (rds f))
       (while (not (weq (inf c) (char eof))) (prin2 (setq c (readch))))
       (wrs wold)
       (rds rold)
       (close f)
       (return mf) ))
 
(de mfsave (channel)
   (let*((r (mf-find-file channel))
         (f (open (mf-name r) 'output))
         (l (mf2list channel))
         (wo (wrs f)))
     (foreach u in l do (prin2 u))
     (wrs wo)
     (close f)
     t))
      
       
