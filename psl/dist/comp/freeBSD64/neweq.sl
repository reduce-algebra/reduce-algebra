(remprop 'eq 'openfn)

(put 'eq 'opencode
   '((cmp (reg 1)(reg 2))
     (setne (reg 3))     % = 1 if neq else 0
     (*wminus (reg 3))    % = ffffff if neq else 0
     (*wand (reg 3) (quote nil))
     (*move (quote t)(reg 1))
     (*wor (reg 1)(reg 3)) ))
