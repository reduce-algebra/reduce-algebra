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
   (prog (libbb)
   (setq libbb (dlopen (strbase (strinf filename)) 1))
   (when (eq 0 libbb)
          (return (bldmsg "**** Error opening dyn lib " filename)))        
   (return libbb)
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

   (if (idp symb)
   (setq libbb (dlsym handle (strbase (strinf (id2string symb)) )))
   (setq libbb (dlsym handle (strbase (strinf symb)) )))

   (return libbb)
))

% calling the function  arg1 points to the address to call.

(lap '((!*entry dynloadhelper expr 1)

(*push (reg 5))
(*push (reg 4))
(*push (reg 3))
(*push (reg 2))
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
(add 32 (reg st))
(ret)))

% this versions is for floating results ( provided in %xmm0 )

(lap '((!*entry dynloadhelper_float_float expr 1)

(*push (reg 5))
(*push (reg 4))
(*push (reg 3))
(*push (reg 2))
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
(*toxmm0 (reg rdi))

       (*callhugo (reg 1)) % will be done by the sed script

(*fromxmm0 (Reg 1))
(*move (displacement (reg st) 40) (reg st))
(*pop (reg bndstkupperbound))
(*pop (reg bndstklowerbound))
(*pop (reg bndstkptr))
(*pop ( reg heaptrapbound))
(*pop (reg heaplast))
(*pop (reg nil))
(*move (reg 2) (fluid ebxsave*))
(add 32 (reg st))
(ret)))

(de psl-dlclose (handle)
   (return (dlclose handle )))

