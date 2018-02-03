% Implements the example from man dlopen in PSL, 
% computes cos(2.0)

(cd "psl/dist/lap/freeBSD64")
(load useful helferlein)
(on comp)
(de plantfloat (fl re)
(setq re (gtfltn))
(putmem (plus re 8) fl)
(mkfltn re))

(setq outputbase* 16)
(setq libhandle (psl-dlopen "libm.so.6" 1))
(if (stringp libhandle)
    (print (importforeignstring (dlerror)))
  (progn 
    (setq  functionhandle (psl-dlsym libhandle 'cos))
    (plantfloat (dynloadhelper_float_float functionhandle (plus2 8 (info 2.0))))))

