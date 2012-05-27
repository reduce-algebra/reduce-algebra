
(compiletime (load sys-consts sys-macros doshooks))
(compiletime (load inum fast-vector fast-int))

(de setbreak(x)
        (386asm
           (setf (386reg ah) 16#2E)
           (setf (386reg al) x)
           (386INT 16#21)
))
