%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  FASTLOAD.SL
%
%  caching binary input for load
%
%  Author: Herbert Melenk 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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

(compiletime (flag '(bfill-buffer) 'internalfunction))

(when (null (getd 'old-binaryopenread))
      (copyd 'old-binaryopenread 'binaryopenread)
      (copyd 'old-binaryread     'binaryread)
      (copyd 'old-binaryreadblock 'binaryreadblock)
      (copyd 'old-binaryclose     'binaryclose))

(fluid '(binary-struct))

(setq binary-struct (make-vector 3 0))

(compiletime
 (progn
    (ds bid()(igetv binary-struct 0))
    (ds bbuf()(igetv binary-struct 1))
    (ds bptr()(igetv binary-struct 2))
    (define-constant blth (times 3 128))
    (ds inc1 (x)(setf x (wplus2 x 1)))
    (ds inc4 (x)(setf x (wplus2 x addressingunitsperitem)))
    (ds dec1 (x)(setf x (wdifference x 1)))
))

(de binaryopenread(name)
  (let ((id (old-binaryopenread name)))
    (when (eq (bid) 0)
          (setf (bid) id)
          (when (weq 0 (bbuf))
                (setf (bbuf) (make-words blth 0)))
          (bfill-buffer)
     )
     id))

(de binaryclose(id)
   (when (eq (igetv binary-struct 0) id)
         % (setf (bbuf) 0)
         (setf (bid) 0))
   (old-binaryclose id))

(de binaryread(id)
  (if (not (eq id (bid)))
      (old-binaryread id)
    (progn
     (when (geq (bptr) blth) (bfill-buffer))
     (let ((p (bptr)))
          (setf (bptr) (iadd1 p))
          (igetv (bbuf) p)
) ) ))

(de binaryreadblock(id p l)
  (if (not (eq id (bid)))
      (old-binaryreadblock id p l)
    (prog (f c)
      (setq c (bptr))
  loop
      (setq f (wplus2 (wrdbase (wrdinf (bbuf))) 
                      (times c addressingunitsperitem)))
      (while (and (wgreaterp l 0) (wlessp c blth))
             (putmem p (getmem f))
             (inc4 f) (inc4 p)
             (dec1 l) (inc1 c))
      (setf (bptr) c)
      (when (weq l 0)(return nil))
      (when (wgreaterp l 20)
            (return (old-binaryreadblock id p l)))
      (bfill-buffer)
      (setq c 0)
      (go loop)
)))

(de bfill-buffer()
  (old-binaryreadblock (bid) (wrdbase (wrdinf (bbuf))) blth)
  (setf (bptr) 0))
