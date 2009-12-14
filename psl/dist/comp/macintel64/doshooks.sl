%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:DOSHOOKS.SL
% Description:  Intel 80386 processor Interrupt support
% Author:       H. Melenk
% Created:      10-May 1990
% Modified:
% Mode:         Lisp
% Package:
%


% ------------------------------------------------------------
% Fluid declarations:
% ------------------------------------------------------------

% ------------------------------------------------------------
% Register access structure:
% ------------------------------------------------------------


   %  we use the extra regs as buffer for the 386
   %  registers

(de 386register (regname pslreg extrareg shift mask)
      (let ((accessfn (gensym))
            (setfn (gensym)))
       (put accessfn 'opencode
         (if mask
           `((*move (reg ,extrareg) (reg 1))
             (*wshift (reg 1) (quote ,(minus shift)))
             (*wand (reg 1) (wconst ,mask)))

           `((*move (reg ,extrareg) (reg 1)))
       ))

       (put setfn 'opencode
         (if mask
           `((*move (wconst ,mask) (reg 2))

             (*wshift (reg 2)(quote ,shift))
             (*wnot (reg 2) (reg 2))
             (*move (reg ,extrareg) (reg 3))
             (*wand (reg 3) (reg 2))
             (*wshift (reg 1)(quote ,shift))
             (*wor (reg 3)(reg 1))
             (*move (reg 3) (reg ,extrareg)))

           `((*move (reg 1) (reg ,extrareg)))
        ))

         (put regname 'reg-accessfn accessfn)
         (put regname 'reg-setfn setfn)
))

(386register 'eax 1 6  0  nil)
(386register  'ax 1 6  0 16#ffff)
(386register  'al 1 6  0 16#ff)
(386register  'ah 1 6  8 16#ff)

(386register 'ebx 2 7  0  nil)
(386register  'bx 2 7  0 16#ffff)
(386register  'bl 2 7  0 16#ff)
(386register  'bh 2 7  8 16#ff)

(386register 'ecx 3 8  0  nil)
(386register  'cx 3 8  0 16#ffff)
(386register  'cl 3 8  0 16#ff)
(386register  'ch 3 8  8 16#ff)

(386register 'edx 4 9  0  nil)
(386register  'dx 4 9  0 16#ffff)
(386register  'dl 4 9  0 16#ff)
(386register  'dh 4 9  8 16#ff)

(386register 'esi 6 11 0  nil)

(dm 386reg (u)
    (let* ((name (cadr u))
           (accessfn (get name 'reg-accessfn)))
       (when (null accessfn)
             (print u)
             (stderror "unknown 386 register access"))
       (list accessfn)))

(put '386reg 'assign-op '386set-reg)

(dm 386set-reg (u)
    (let* ((name (cadr u))
           (setfn (get name 'reg-setfn)))
       (when (null setfn)
             (print u)
             (stderror "unknown 386 register"))
       (list setfn (caddr u))))

(dm 386int (u)
    (let ((intfn (gensym)))
         (put intfn 'opencode
              `((*move (reg 6)(reg 1))
                (*move (reg 7)(reg 2))
                (*move (reg 8)(reg 3))
                (*move (reg 9)(reg 4))
                (*move (reg 11)(reg ESI))
                (int (wconst ,(cadr u)))
                (*move (reg 1)(reg 6))
                (*move (reg 2)(reg 7))
                (*move (reg 3)(reg 8))
                (*move (reg 4)(reg 9))
                (*move (reg ESI)(reg 11))
          ))
         (list intfn)))

(dm 386asm(u)
    (cons 'progn
        (cons '(&&clearregs)
               (append (cdr u)
                       '((&&clearregs))))))

(put '&&clearregs 'opencode
      '((*move (quote 0) (reg 6))
        (*move (quote 0) (reg 7))
        (*move (quote 0) (reg 8))
        (*move (quote 0) (reg 9))
))

 
(commentoutcode   % SPECIMEN
(de scroll (n)
  % scroll active video page
   (386asm
      (setf (386reg ah) 16#06)
      (setf (386reg al) n)
      (setf (386reg ch) 0)
      (setf (386reg cl) 79)
      (setf (386reg dh) 0)
      (setf (386reg dl) 24)
      (setf (386reg bh) 2#01110000)
      (386INT 16#10)
    ))


 (de vpa(n) (386asm
    % set active video page
       (setf (386reg ah) 16#05)
       (setf (386reg al) n)
       (386INT 16#10)
      ))

(load inum)
(de exec (p)
     (prog(adr block)
        (when (not (stringp p)) (stderror "exec illegal call"))
        (setq block (make-words 3 0))
        (setq adr (strbase (strinf p)))
        (386asm
           (setf(386reg edx) adr)
           (setf(386reg ebx) (wplus2 (inf block) 4))
           (setf(386reg al) 0)
           (setf(386reg ax) 16#4b)
           (386INT 16#21)
        )
        ))
)

