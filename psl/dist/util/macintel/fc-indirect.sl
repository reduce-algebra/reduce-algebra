%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXU:FC-INDIRECT.SL
% Description:  Builds an indirect call to a function.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      24-Apr-84
% Modified:     01-May-84 13:11:09 (Mike Creech)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(imports 'sys-consts)

(on fast-integers)

% The following three s-expressions will go away when the micro-kernel is released.
% NOTE: The anyreg part of the '*move' below (entry), may have to be changed
%       for other implementations.

(lap '((*entry symfnc-hack expr 0)
       (*move (entry (int2id 0)) (reg 1))
       (*exit 0)
       ))

(fluid '(symfnc))

(setf symfnc (symfnc-hack))

(de define-indirect-function (calling-function called-function)

  % Build a  calling function named (calling-function) that simply calls
  % another function (called-function).
  % No knowledge of the number of arguments is needed.
  % Note that the interpreter will do no error checking on number of
  % arguments for a function defined by this routine.

  (if (member 'compiler options*)
    (lap `((*entry ,calling-function expr -1)
	   (*alloc 0)
	   (*linke 0 ,called-function expr -1)
	   ))
    (*hacked-define-indirect-function calling-function
				      called-function)
    )
  calling-function   % Return the name of the defined function
  )

(de *hacked-define-indirect-function (calling-function called-function)
  
  % Builds the function linkage by hand, without use of the compiler.
  % First, some BPS is allocated, and code is placed in it to jump to
  % the called function.
  % CODE-BASE points to the start of the segment allocated by GTBPS, where
  % the argument count resides.
  % CODE-ADDRESS points to the beginning of the actual code.

  (let* ((code-base     (gtbps 4))
	 (code-address  (loc (wgetv code-base 1)))
	 (called-address (+ symfnc (* (wconst addressingunitsperfunctioncell)
				      (idinf called-function)))))

    (wputv code-base 0 -1)      % Number of arguments = undefined

    % The '16#4EF9' is the op-code for the jmp instruction on the 68000.

    (setf (halfword code-address 0)        16#4EF9)    

    % The following '2' is the number of addressing units in the above op-code.

    (setf (getmem (wplus2 code-address 2)) called-address)

    % Now the code is built.  Next we make a code pointer that points to
    % it and plant it in the function cell of the newly defined function:

    (putd calling-function 'expr (mkcode code-address))
    ))

(off fast-integers)
