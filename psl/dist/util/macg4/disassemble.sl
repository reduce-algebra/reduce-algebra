%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXU:disassemble.sl
% Title:          Disassemble of instructions for IBM RS 6000 PSL
% Author:         Winfried Neun
% Created:        January 2, 1991
% Status:         Experimental
%
% Copyright (c) 1990, Konrad-Zuse-Zentrum Berlin, All Rights Reserved
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% The disassemble takes its information from the compiler patterns
% ibmrs-instrs.sl and inverts them in order to disassemble
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

(compiletime (flag '(dispatch-disassemble safe-cdr special-dispatch-disassemble
        cop1-dispatch-disassemble bcond-dispatch-disassemble
        normal-dispatch-disassemble print-instruction prinbl prinb prinbo
        prinbn prindig) 'iinternalfunction))

(fluid '(*instrsvect* *special19opcodevect* *regnames* *special31opcodevect*
         *special63opcodevect* *floatopcodevect* klingelbeutel))

(setq *regnames*
   '((0 . "reg t") (1 . "reg st") (3 . "reg 1") (4 . "reg 2") (5 . "reg 3")
     (6 . "reg 4") (7 . "reg 5") (8 . "reg t2") (9 . "reg t3") (10 . "reg t4")
     (11 . "reg t5") (12 . "reg t6") (13 . "reg NIL") (14 . "reg bndstkptr")
    (15 . "reg bndstklowerbound") (16 . "reg bndstkupperbound")
    (17 . "reg symfncc") (18 . "reg symvalc") (19 . "reg t1") 
    (20 . "reg heaplast") (21 . "reg heaptrapbound")
    (22 . "frame 9") (23 . "frame 8") (24 . "frame 7") (26 . "frame 6") 
    (27 . "frame 5") (28 . "frame 4") (29 . "frame 3")
    (25 . "frame 2") (30 . "frame 1") (31 . "reg returnaddr"))) 

(setq   *instrsvect* (mkvect 64)
        *special19opcodevect* (mkvect 2048)
        *special31opcodevect* (mkvect 4096)
        *special63opcodevect* (mkvect 2048)
        *floatopcodevect* (mkvect 1024))


(compiletime
 (progn
  (de load-instruction-vectors (id)
     (when (get id '*opcode*)  (read-normal-instruction id))
     (when (get id '*special31*) (read-special-instruction id))
     (when (get id '*special63*) (read-scaled-instruction id))
     (when (get id '*special19*) (read-bitfield-instruction id))
  )

  (de read-special-instruction (id)
     (prog (opcode format)
       (setq opcode (get id '*special31*))
       (setq format (lshift (car opcode) 1))
       (when (memq 'oe opcode)  (setq format (plus2 (expt 2 11) format)))
       (when (memq 'rc opcode)  (setq format (plus2 1 format)))
       (setq opcode format)
       (setq format (or (get id '*xo-format*)
			(get id '*x-format*)))
       (push `(putv *special31opcodevect* ,opcode ',(list id format))
            klingelbeutel)))

  (de read-float-instruction (id)
     (prog (opcode format)
       (setq opcode (get id '*float*))
       (setq opcode (lor (lshift (car opcode) 5) (cadr opcode)))
       (setq format (get id '*r-format*))
       (push `(putv *floatopcodevect* ,opcode ',(list id format))
            klingelbeutel)))

  (de read-scaled-instruction (id)

     (prog (opcode format)
       (setq opcode (get id '*special63*))
       (setq format (lshift (car opcode) 1))
       (when (memq 'rc opcode)  (setq format (plus2 1 format)))
       (setq opcode format)
       (setq format (get id '*a-format*))
       (push `(putv *special63opcodevect* ,opcode ',(list id format))
                klingelbeutel)))

  (de read-bitfield-instruction (id)
     (prog (opcode format)
       (setq opcode (lshift (car (get id '*special19*)) 1))
       (if (memq 'lk (get id '*special19*)) (setq opcode (plus2 opcode 1)))
       (setq format (get id '*xl-format*))
       (push `(putv *special19opcodevect* ,opcode ',(list id format))
                klingelbeutel)))

  (de read-normal-instruction (id)
     (prog (opcode format)
       (setq opcode (car (get id '*opcode*)))
       (setq format (or (get id '*i-format*)
			(get id '*m-format*)
			(get id '*b-format*)
                        (get id '*d-format*)))  
       (push `(putv *instrsvect* ,opcode ',(list id format))
                klingelbeutel)))
))
% installing the vectors now:
    
(compiletime
 (dm generate-it()
 (setq klingelbeutel nil)
 (mapobl (function load-instruction-vectors))
 (cons 'progn klingelbeutel)))

(generate-it)

(de dispatch-disassemble (where word nextword)
   (prog (op instr)
     (prinbn where 8) (tab 15)
     (prinbn word  8) (tab 30)
     (setq op (wshift word -26))  % the opcode
     (cond ((eq op 19) (special-dispatch-disassemble word ))
           ((eq op 31) (special-31-dispatch-disassemble word ))
           ((eq op 63) (bitfield-dispatch-disassemble word ))
           (t (normal-dispatch-disassemble where word nextword))) 
)
))

% words will be split to sanitize the gc problem with unweaponed words
(de safe-cdr (x) (cond ((null x) x) (t (cdr x)))) 

(de special-dispatch-disassemble (word)
  (prog (instr secondary tertiary rs ra rb rt bo bi)
    (setq secondary (field word 21 10))  % the secondary opcode
    (setq tertiary  (field word 31 1))  % the tertiary opcode
    (setq instr (getv *special19opcodevect*
                        (wor (wshift secondary 1) tertiary)))
    (when (atom instr) (print  " ???? " ) (return nil))
    (setq ra  (cdr (assoc (field word 11 5) *regnames*)))
    (setq rb  (cdr (assoc (field word 16 5) *regnames*)))
    (setq rs  (cdr (assoc (field word 6  5) *regnames*)))
    (setq rt rs)
    (setq bo (field word 6  5))
    (cond ((wlessp bo 8) (setq bo "false"))
          ((wlessp bo 15)(setq bo "true"))
          ((eq bo 20)    (setq bo "always")))
    (setq bi (field word 11 5))
    (cond ((eq bi 0) (setq bi "lt"))
         ((eq bi 1) (setq bi "gt"))
         ((eq bi 2) (setq bi "eq"))
         ((eq bi 3) (setq bi "so")))
    (print-instruction
      (pair '(instr rs ra rb rt bo bi bt ba bb)
        (list instr rs ra rb rt bo bi rt ra rb))
              (safe-cdr instr)) %the format
))

(de special-31-dispatch-disassemble (word)
  (prog (instr secondary tertiary rs ra rb rt Oe spr bf)
    (setq secondary (field word 21 10))  % the secondary opcode
    (setq tertiary  (field word 31 1))  % the tertiary opcode
    (setq instr (getv *special31opcodevect*
		(wor (wshift secondary 1) tertiary )))
    (when (atom instr) (print  " ???? " ) (return nil))
    (setq bf (field word 6 3))
    (setq ra  (cdr (assoc (setq spr (field word 11 5)) *regnames*)))
    (setq rb  (cdr (assoc (field word 16 5) *regnames*)))
    (setq rs  (cdr (assoc (field word 6  5) *regnames*)))
    (setq rt rs)
    (setq spr (atsoc spr '((0 . "mq") (1 . "xer") (4 . "rctu")
		(5 . "rctl") (6 . "dec") (8 . "lr") (9 . "ctr"))))
    (when spr (setq spr (cdr spr)))
    (print-instruction 
              (pair '(instr rs ra rb rt spr sh bf) 
		 (list instr rs ra rb rt spr (field word 16 5) bf))
              (safe-cdr instr)) %the format 
))

(de bitfield-dispatch-disassemble (word nextword)
  (prog (instr secondary tertiary rs ra rb rt bo bi)
    (setq secondary (field word 21 10))  % the secondary opcode
    (setq tertiary  (field word 31 1))  % the tertiary opcode
    (setq instr (getv *special31opcodevect*
                        (wor (wshift secondary 1) tertiary)))
    (when (atom instr) (print  " ???? " ) (return nil))
    (setq ra  (cdr (assoc (field word 11 5) *regnames*)))
    (setq rb  (cdr (assoc (field word 16 5) *regnames*)))
    (setq rs  (cdr (assoc (field word 6  5) *regnames*)))
    (setq rt rs)
    (print-instruction
      (pair '(instr rs ra rb rt bo bi bt ba bb )
         (list instr rs ra rb rt bo bi rt ra rb))
              (safe-cdr instr)) %the format
))

(de normal-dispatch-disassemble (where word nextword)
  (prog (op instr ra rb si d26 d16 rt based cc bf ui me mb bi bo)
    (setq op (wshift word -26)) 
    (setq instr (getv *instrsvect* op))
    (when (atom instr) (print  " ???? " ) (return nil))
    (setq ra (cdr (assoc (field word 11 5) *regnames*)))
    (setq rt  (cdr (assoc (field word 6  5) *regnames*)))
    (setq rb (field word 16 5))
    (setq bf (field word 6 3))
    (setq si (signedfield word 16 16))
    (setq ui (field word 16 16))
    (setq d26 (wplus2  where (wshift (signedfield word 6 24) 2)))
    (setq d16 (wplus2  where (wshift (signedfield word 16 14) 2)))
    (setq d26 (bldmsg "%x" d26))
    (setq d16 (bldmsg "%x" d16))
    (setq based (bldmsg "%w,%w" ra si))
    (setq mb (field word 21 5))
    (setq me (field word 26 5))
    (setq bo (field word 6  5))
    (cond ((wlessp bo 8) (setq bo "false"))
          ((wlessp bo 15)(setq bo "true"))
          ((eq bo 20)    (setq bo "always")))
    (setq bi (field word 11 5))
    (cond ((eq bi 0) (setq bi "lt"))
         ((eq bi 1) (setq bi "gt"))
         ((eq bi 2) (setq bi "eq"))
         ((eq bi 3) (setq bi "so")))
    (print-instruction 
      (pair '(instr ra si target target-14 rt based cc bf rs ui sh me mb bi bo)
        (list instr ra si d26 d16 rt based cc bf rt ui rb me mb bi bo))
              (safe-cdr instr)) %the format 
))

(de print-instruction (alist format)
   (prog (fmtitem institem comma comment)
     (tab 30)
     (prin2 (cadr (atsoc 'instr alist)))
     (tab 40)
     (setq format (car format))
    loop
     (when (null format) (when comment (tab 70) (prin2 comment))
                         (return (terpri)))
     (setq fmtitem (car format))
     (when (idp fmtitem)
         (when comma (prin2 ","))
         (setq comma t)
         (setq institem (atsoc fmtitem alist))
         (when (and (not (eq fmtitem 'based)) (null institem))
                 (print (list "komisch:" format)))
         (if (eq fmtitem 'based)
              (progn (prin2 (cdr institem))
                     (when (equal (cdr (atsoc 'ra alist)) "reg st")
                           (setq comment (cdr (atsoc 'si alist)))
                           (setq comment (lshift comment -2))
                           (setq comment (bldmsg "Frame (%w)" comment)))
                     (when (equal (cdr (atsoc 'ra alist)) "reg symvalc")
                           (setq comment (cdr (atsoc 'si alist)))
                           (if (wgreaterp comment 28000)
                              (setq comment (bldmsg "Extrareg%d" 
     					(lshift (wplus2 comment -28000) -2)))
                             (setq comment (lshift (wplus2 comment 32000) -2)))
                           (when (numberp comment) 
					(setq comment (symnam comment))))
                     (when (equal (cdr (atsoc 'ra alist)) "reg symfncc")
                           (setq comment (cdr (atsoc 'si alist)))
                           (setq comment (wshift (wplus2 comment 32000) -2))
                           (setq comment (symnam comment)))) 
             (prin2 (if (pairp institem) (cdr institem)
                                         institem))))
     (setq format (cdr format))
     (go loop)))

(compiletime (put 'memo 'opencode '((lwz (reg 1) (displacement (reg 1) 0)))))

(de disassemble (x)
 (prog (stop i ll)
  (setq ll (linelength 120))
  (setq i x)
  (when (idp x) (when (funboundp x) (error 0 (list x "not compiled")))
                (setq i (wgetv symfnc (idinf x))))  
  (prin2l (list "**** Function :" x " at " (inf i))) (terpri) (terpri)
  (while (wgreaterp (wshift (memo i) -1) 15)
    (dispatch-disassemble i (memo i) (getmem (wplus2 i 4)))
    (setq i (wplus2 i 4)))
  (linelength ll)
))

(de prinbl (l)                  % binary (octal) printing of a list
     (mapc l (function prinb)))

(de prinb (it)                  % binary (octal) printing of an item
     (cond ((numberp it)(prinbo it))
           ((eq it 't1) (tab 35))
           ((eq it 't2) (tab 60))
           (t       (prin2 it))))

(de prinbo (it)
      (cond ((wlessp it 0) (prin2 "-") (prinbo (wminus it)))
            ((wgeq it 10)  (prin2 "x'") (prinbn it 1))
    (t            (prinbn it 1))))

(de prinbn (it n)                % print an octal number
     (cond ((and (weq it 0) (wleq n 0)) nil)
            (t (progn
                  (prinbn (wshift it -4) (wplus2 n -1))
                  (prindig (wand it 15))
)    )     )  )

(de prindig (dig)        % print a numeric digit
     (if (wlessp dig 10) (writeChar  (wplus2 dig 48))
           (writechar (wplus2 65 (wdifference dig 10)))))
