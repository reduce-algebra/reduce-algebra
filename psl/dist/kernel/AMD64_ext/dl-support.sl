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

(on fast-integers)
(compiletime (put 'UndefinedFunction 'symbol 'UndefinedFunction))
(compiletime (put 'UndefinedFunction 'entrypoint 'UndefinedFunction))
(define-constant RTLD_LAZY 1)
(define-constant RTLD_NOW  2)


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
   (wputv mess 0 "dlerror")
   (return mess)
))

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

% calling the function  arg1 points to the address to call.

(lap '((!*entry dynloadhelper expr 1)

(*push (reg 5))
(*push (reg 4))
(*push (reg 3))
(*push (reg 2))
(*move (displacement (reg st) 72) (reg r13))
(*move (displacement (reg st) 64) (reg r12))
(*move (displacement (reg st) 56) (reg r11))
(*move (displacement (reg st) 48) (reg r10))
(*move (displacement (reg st) 40) (reg r9))
(*move (displacement (reg st) 32) (reg r8))
(*move (displacement (reg st) 24) (reg rcx))
(*move (displacement (reg st) 16) (reg rdx))
(*move (displacement (reg st) 8) (reg rsi)) 
(*move (displacement (reg st) 0) (reg rdi))
(*move (fluid ebxsave*) (reg 2))
(*push (reg nil))
(*push (reg heaplast))
(*push (reg heaptrapbound))
(*push (reg bndstkptr))
(*push (reg bndstklowerbound))
(*push (reg bndstkupperbound))
(*move (reg st) (reg 2))
(sub 64 (reg st)) 
(*wshift (reg st) -5)
(*wshift (reg st) 5)
(*move (reg 2) (displacement (reg st) 40))

       (*callhugo (reg 1)) % will be done by the sed script

(*move (displacement (reg st) 40) (reg st))
(*pop (reg bndstkupperbound))
(*pop (reg bndstklowerbound))
(*pop (reg bndstkptr))
(*pop ( reg heaptrapbound))
(*pop (reg heaplast))
(*pop (reg nil))
(*move (reg 2) (fluid ebxsave*))
(add 80 (reg st))
(ret)))

(de psl-dlclose (handle)
   (return (dlclose (wgetv handle 0))))

