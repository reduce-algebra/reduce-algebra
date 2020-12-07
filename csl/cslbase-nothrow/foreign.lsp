
(setq !*echo t)

%
% This illustrates and tests use of the foreign function scheme present in
% CSL. There is associated code "foreign.c" that is compiled to create
% a module (foreign.so or foreign.dll) and that defines a collection
% of functions that are exercised here.

(setq a (open!-foreign!-library "./foreign"))

% The first few are functions that do not take any arguments but that
% return results. Well the very first one has "void" as its result type.

(call!-foreign!-function (find!-foreign!-function "vff" a))
(call!-foreign!-function (find!-foreign!-function "i32ff" a) 'int32)
(call!-foreign!-function (find!-foreign!-function "i64ff" a) 'int64)
(call!-foreign!-function (find!-foreign!-function "dff" a) 'double)
(call!-foreign!-function (find!-foreign!-function "sff" a) 'string)

% The next batch are all void functions but they accept a range of
% different sorts of argument

(call!-foreign!-function (find!-foreign!-function "vffi32" a) 'int32 12345)
(call!-foreign!-function (find!-foreign!-function "vffi64" a) 'int64 (expt 10 15))
(call!-foreign!-function (find!-foreign!-function "vffd" a) 'double 123.45)
(call!-foreign!-function (find!-foreign!-function "vffs" a) 'string "Test Data")

% Now something messier. I register some callbacks so that the foreign
% code can call back into Lisp

(setq register_callback (find!-foreign!-function "register_callback" a))
(dotimes (i 33)
   (call!-foreign!-function register_callback 'int32 i
                                              'int64 (get!-callback i)))

(dotimes (x 3)
   (princ "About to try with x = ")
   (print x)
   (print (call!-foreign!-function
             (find!-foreign!-function 'two_way a) 'int32 x 'int32))
   (terpri))

(stop)
