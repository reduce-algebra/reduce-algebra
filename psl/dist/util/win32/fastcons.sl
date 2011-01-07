(load compiler)

(when (null (getd 'oldfaslout))
      (copyd 'oldfaslout 'faslout))

(de faslout(file)
   (oldfaslout file)
   (flag '(cons xcons ncons) 'internalfunction)
   (lap '(
          (*entry ncons expr 2)
          (*move (quote nil) (reg 2))
          (*jump (label std-cons))
          (*entry xcons expr 2)
          (xchg (reg 1)(reg 2))
   std-cons
          (*entry cons expr 2)
          (*alloc 0)
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 2))
          (*jumpwgeq (label callslow) (reg 5) (reg 4))
          (*move (reg 1) (memory (reg 3) 0))
          (*move (reg 2) (memory (reg 3) addressingunitsperitem))
          (*move (reg 5) (global heaplast))
          (*move (reg 3) (reg 1))
          (*mkitem (reg 1) pair-tag)
          (*exit 0)
      callslow
          (*linke 0 !_slowcons expr 2))))

