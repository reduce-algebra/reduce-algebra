#! /bin/bash -v

./vsl -i pslcomp-fasl.img <<XXX | tee try-fasl.log

(setq *echo t)

% This seems to be called at cross-compile time with NIL as the
% second argument. That seems a bit weird to me.

(de mkitem (tag x)
  (cond
    ((null (fixp tag)) (mkitem 0 x))
    ((null (fixp x)) (mkitem tag 0))
    (t (land 16#ffffffffffffffff (lor
         (lsh tag 56)
         (land x 16#00ffffffffffffff))))))

(trace '(mkitem lap))
% (trace '(putbyte))
(trace '(puthalfword putword wputv))

(setq *plap t)
(setq *pgwd t)


(faslout 'foo)
(de bar (x) "hello")
(faslend)

XXX

