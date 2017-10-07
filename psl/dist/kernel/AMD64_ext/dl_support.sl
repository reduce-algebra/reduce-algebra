%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:DL-SUPPORT.SL
% Description:  System support for dynamic loading
% Author:       Winfried Neun, ZIB
% Created:      22-Jul 2013
% Mode:         Lisp
% Package:      
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% a first version for dyn loading
% we put all the void * objects into warrays.

(on fast-integers)

(de psl-dlopen (filename flag)
  (prog (libb libbb)
   (setq libb (gtwarray 1))
   (setq libbb (dlopen (strbase (strinf filename)) flag))
   (wputv libb 0 libbb)
   (return libb)
))

(de psl-dlerror ()
  (prog (mess)
   (setq mess (gtwarray 1))
   (wputv mess 0 (dlerror ))
   (return mess)
)

% this does not yet do the job !! Function is not callable

(de psl-dlsym (handle symb)
  (prog (libb libbb)
   (setq libb (gtwarray 1))
   (if (idp symb)
   (setq libbb (dlsym (wgetv handle 0) (strbase (strinf (id2string symb)) )))
   (setq libbb (dlsym (wgetv handle 0) (strbase (strinf symb)) )))
   (wputv libb 0 libbb)
   (return libb)
))

(de psl-dlclose (handle)
   (dlclose (wgetv handle 0)))
))

