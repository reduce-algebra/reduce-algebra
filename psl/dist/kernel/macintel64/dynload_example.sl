% Implements the example from man dlopen in PSL, 
% computes cos(2.0)

(cd "psl/dist/lap/macintel64")
(load useful helferlein)
(on comp)
(setq outputbase* 16)
(setq libhandle (psl-dlopen "libm.dylib" 1))
(setq  functionhandle (psl-dlsym libhandle 'cos))
(de plantfloat (fl re)
(setq re (gtfltn))
(putmem (plus re 8) fl) 
(mkfltn re))

(plantfloat (dynloadhelper_float_float functionhandle (plus2 8 (info 2.0))))

