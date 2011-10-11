% Compat.sl.  Useful definitions for Cray and Sun 4 PSL versions.

% Author: Winfried Neun.

(remflag '(digit) 'lose)

(ds digit (u) ((lambda (x) (eq 1 (wshift
                      (wand (wdifference 8#057 (inf x))
                            (wdifference (inf x) 8#072))
                                 -31))) u))

(flag '(digit) 'lose)

(ds orderp (u v) (not (wgreaterp (inf u) (inf v))))

(flag '(orderp) 'lose)

(ds flagp** (u v)
          (flagp u v))

(flag '(flagp**) 'lose)

(dm terminalp (u)
    '(and *int (null ifl*)))

(flag '(terminalp) 'lose)

(ds liter (u)
  ((lambda (&u& &infu&)
    (setq &infu& (inf &u&))
     (eq 0 (wor (wxor (tag &u&) id-tag)
               (wshift
                  (wand (wor (wdifference &infu& 8#141) % a
                             (wdifference 8#172 &infu&)) % z
                        (wor (wdifference &infu& 8#101) % A
                             (wdifference 8#132 &infu&)) % Z
                   ) -31)))) u 0))
