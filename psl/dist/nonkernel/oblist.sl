%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:OBLIST.SL 
% Title:        Intern, RemOb and friends 
% Author:       Eric Benson 
% Created:      27 August 1981 
% Modified:     25-Sep-84 14:02:09 (Brian Beach)
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  PL:HASH-DECLS.B PL:SYS-CONSTS.B 
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 19-Dec-86 (Leigh Stoller)
%  Added copystring to setq of stringgensym* below to make sure the string
%  in allocated in heap, not bps.
% 25-Sep-84 14:01:33 (Brian Beach)
%  Fixed ID-INTERN yet again.  This time a special case was added for sigle
%  character id's, since they are not entered in the hash table.
% 24-Sep-84 14:27:05 (Brian Beach)
%  Fixed ID-INTERN yet again so that interning an ID which has a print name
%  of an already interned ID will return that already interned ID.
% 21-Sep-84 13:14:49 (Brian Beach)
%  Added following change:
% 28-Jun-84 10:43:14 (Cris Perdue)
%  Added startup time copyd from intern to reader-intern.
%  Reader-intern was added as a hook for the pkg system.
% 22-Aug-84 08:38:50 (Brian Beach)
%  Fixed ID-INTERN so that the ID created has the same ID number as the one
%  being interned.
% 18-Jul-84 08:36:24 (Brian Beach)
%  Reintroduced internal functions.  Minor cleanup.
% 23-Mar-84 07:32:21 (Brian Beach)
%  Removed duplicate definitions of functions defined in the kernel.  Added
%  compile time load of HASH-DECLS.
% 01-Dec-83 14:55:01 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load hash-decls sys-consts))

(on fast-integers)

(compiletime
  (flag '(addtooblist lookuporaddtooblist inoblist initnewid gensym1) 
        'internalfunction))

(fluid '(hashtable symnam))

(de intern (u)
  % Add U to ObList
  %
  % U is a string or uninterned ID
  (cond ((idp u)     (id-intern u))
        ((stringp u) (string-intern u))
        (t           (typeerror u 'intern '"ID or string"))))

(de id-intern (u)
  %
  % U is an ID, which is added to the oblist if an ID with the same
  % print name is not already there.  The interned ID (the same one
  % that was given) is returned.
  %
  (let* ((name  (symnam (idinf u)))
	 (len   (strlen (strinf name))))
    (if (eq len 0)
      (mkid (strbyt (strinf name) 0))
      (let ((hash-table-index (hash-into-table (symnam (idinf u)))))
	(if (occupied-slot? hash-table-index)
	  (mkid (hash-table-entry hash-table-index))
	  (progn
	   (setf (hash-table-entry hash-table-index) (idinf u))
	   u
	   ))))))

(de string-intern (u)
  %
  % U is a String, which IS copied if it is not found on the ObList
  % The interned ID with U as print name is returned
  %
  (let ((len (strlen (strinf u))))
    (if (wlessp len 0)
      (stderror '"The null string cannot be interned")
      (unchecked-string-intern u)
      )))

%
% UNCHECKED-STRING-INTERN is defined in the kernel.
%

(de reader-intern (x)
  (intern x)
  )

(de remob (u)
  % REMove id from OBlist
  (if (not (idp u))
    (noniderror u 'remob)
    (let* ((inf   (idinf u))
	   (name  (symnam inf)))
      (if (wlessp inf 256)
	(typeerror u 'remob '"non-char")
	(let ((slot (hash-into-table name)))
	  (when (occupied-slot? slot)
	    (setf (hash-table-entry slot) deleted-slot-value)
	    )
	  u
	  )))))

(de internp (u)
  % Is U an interned ID?
  % Changed to allow a string as well as a symbol, EB, 15 September 1982
  (cond ((idp u)
	 (let ((inf (idinf u)))
	   (or (wlessp inf 128) 
	       (weq inf (hash-table-entry (hash-into-table (symnam inf)))))
	   ))
        ((stringp u)
         (or (weq (strlen (strinf u)) 0)
	     (occupied-slot? (hash-into-table u))
	     ))
        (t nil)))

(fluid '(gensympname))

% Make sure that the string ends up in heap, not bps, so we can unexec over it.
(setq gensympname (copystring (symnam (inf 'g0000))))

(de gensym ()
  % GENerate unique, uninterned SYMbol
  (gensym1 4)
  (newid (copystring gensympname))
  )

(de gensym1 (n)
  % Auxiliary function for GenSym
  (if (wgreaterp n 0)
    (let ((ch (strbyt (strinf gensympname) n)))
      (if (wlessp ch (char !9))
	(setf (strbyt (strinf gensympname) n) (wplus2 ch 1))
	(progn
	 (setf (strbyt (strinf gensympname) n) (char !0))
	 (gensym1 (wdifference n 1))
	 )))
    (progn
     (setf (strbyt (strinf gensympname) 0)
       (wplus2 (strbyt (strinf gensympname) 0) 1))
     (gensym1 4)
     )))

(de newid (s)
  % Allocate un-interned ID with print name S                             
  (initialize-new-id (gtid) s)
  )

(de interngensym ()
  % GENerate unique, interned SYMbol
  (gensym1 4)
  (intern gensympname)
  )

(de mapobl (f)
  % Apply F to every interned ID
  (for (from i 0 127 1) 
       (do (apply f (list (mkid i)))))
  (for (from i 0 hash-table-size 1)
       (do (when (occupied-slot? i)
	     (apply f (list (mkid (hash-table-entry i))))))))

% These functions provide support for multiple oblists
% Cf PACKAGE.RED for their use

(fluid '(lastobarrayptr))

(de globallookup (s)
  % Lookup string S in global oblist
  (cond ((not (stringp s)) (nonstringerror s 'globallookup))
        ((occupied-slot? (setq lastobarrayptr (hash-into-oblist s)))
         (mkid (hash-table-entry lastobarrayptr)))
        (t '0)))

(de globalinstall (s)
  % Add new ID with PName S to oblist
  (let ((index (globallookup s)))
    (if (neq index 0)
      index
      (progn (setq index (gtid))
	     (setf (hash-table-entry lastobarrayptr) index)
	     (let ((pname (gtconststr (strlen (strinf s)))))
	       (copystringtofrom pname (strinf s))
	       (initialize-new-id index (mkstr pname))
	       )))))

(de globalremove (s)
  % Remove ID with PName S from oblist
  (let ((index (globallookup s)))
    (if (equal index 0)
      0
      (progn (setq index (hash-table-entry lastobarrayptr))
	     (setf (hash-table-entry lastobarrayptr) deleted-slot-value)
	     (mkid index)))))

(off fast-integers)

