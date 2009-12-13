%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:SYS-MACROS.SL
% Description:  Macros for doing system type things.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      22-Mar-84
% Modified:     26-Jun-84 14:45:24
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 26-Jun-82 14:45:24 (Vicki O'Day)
%  Added support for `external words'.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(defmacro declare-warray (name init-type init)
  (cond 
   ((eq init-type 'size)      (warray-size name init))
   ((eq init-type 'initially) (warray-init name init))
   (t  (stderror (bldmsg "Bad warray declaration: %w" (list name init-type init))))
   ))

(de warray-size (name init)
  `(progn
    (fluid '(,name))
    (setf ,name (gtwarray ,init))
    (clear-warray ,name ,init)
    ))

(de warray-init (name init)
  `(progn
    (fluid '(,name))
    (setf ,name (gtwarray ,(length init)))
    (initialize-warray ,name (list ,@init))
    ))

(defmacro declare-wstring (name init-type init)
  (cond 
   ((eq init-type 'size)      (wstring-size name init))
   ((eq init-type 'initially) (wstring-init name init))
   (t  (stderror (bldmsg "Bad wstring declaration: %w" (list name init-type init))))
   ))

(ds wstring-word-size (n)
  (plus (quotient n charactersperword) 2)
  )

(de wstring-size (name init)
  `(progn
    (fluid '(,name))
    (setf ,name (gtwarray (wstring-word-size ,init)))
    (clear-wstring ,name ,init (wstring-word-size ,init))
    ))

(de wstring-init (name init)
  `(progn
    (fluid '(,name))
    (setf ,name (gtwarray (wstring-word-size ,(string-length init))))
    (initialize-wstring ,name ,init (wstring-word-size ,(string-length init)))
    ))

(defmacro external-word (name)
  `(getmem ,name)
  )

(defmacro declare-external-word (name)
  (flag1 name 'externalsymbol)
  (put name 'symbol name)
  `(fluid '(,name))
  )

