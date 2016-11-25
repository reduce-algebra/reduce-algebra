% Big-number arithmetic done digit by digit for use testing the
% native arithmetic package.

% Please note that that this is GROTTY code not intended for general re-use.
% It is JUST to provide a regression test on CSL arithmetic. It calls upon a
% number of CSL specials (eg validate!-number, which checks if the internal
% format of a number is proper - specifically if checks that there are no
% bignums with unwanted leading zero digits and no bignums where the value
% could have been represented as a fixnum).


% The code tests a lot of arithmetic cases that I expect to be close to
% critical values (eg near powers of two) and also a load of random
% values - these random values should be different each time the test is
% run.

% **************************************************************************
% * Copyright (C) 2016, Codemist.                         A C Norman       *
% *                                                                        *
% * Redistribution and use in source and binary forms, with or without     *
% * modification, are permitted provided that the following conditions are *
% * met:                                                                   *
% *                                                                        *
% *     * Redistributions of source code must retain the relevant          *
% *       copyright notice, this list of conditions and the following      *
% *       disclaimer.                                                      *
% *     * Redistributions in binary form must reproduce the above          *
% *       copyright notice, this list of conditions and the following      *
% *       disclaimer in the documentation and/or other materials provided  *
% *       with the distribution.                                           *
% *                                                                        *
% * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
% * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
% * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
% * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
% * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
% * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
% * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
% * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
% * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
% * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
% * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE * POSSIBILITY OF SUCH *
% * DAMAGE.                                                                *
% *************************************************************************/


(setq !*echo t !*comp t))

(enable!-errorset 3 3)
(verbos nil)
(make!-random!-state 0)   % Different sequence on each run!

% I keep the implementation of the testing code in a separate file so that
% while debugging I can load it and then just test selected cases...

(rdf "arithfns.lsp")


% This will check near 2^0 to 2^100.

% I will check 1-arg functions first...

(checknear1 0)

(when (atom (errorset
  '(dotimes (i 100)
    (setq a (expt 2 i))
    (princ i) (ttab 5) (princ "check 1 arg and shifts near ") (print a)
    (validate!-number a (list "power of 2" i))
    (checknear1 a)) t t))
  (terpri)
  (printc "+++ Stopping")
  (stop 1))

% While testing it is sometimes useful to be able to resume testing some
% way through, so one can set the variable "startat" so that small cases
% get skipped. E.g. the commented out setting to 59 causes the testing to
% begin where the first argument to functions is about to be a bignum not
% a fixnum on 64-bit platforms.

(fluid '(startat))
(setq startat -1)
% (setq startat 58)

(setq onlydivide nil)

(progn
  (terpri)
  (when (atom (errorset
    '(dotimes (i 100)
      (when (geq i startat)
        (setq a (expt 2 i))
        (validate!-number a (list "power of 2" i))
        (princ i) (ttab 5) (princ "check near ") (print a)
        (checknear a 0)
        (checknear 0 a)
        (dotimes (j 100)
          (setq b (expt 2 j))
          (validate!-number b (list "power of 2" i))
          (checknear a b)))) t t))
    (terpri)
    (printc "+++ Stopping")
    (stop 1)))

(setq onlydivide t)

% For quotient and remainder I want to check values with twice as many bits
% because I want to cover cases where the quotient is up to 100 bits long.

(progn
  (terpri)
  (when (atom (errorset
    '(dotimes (i 200)
      (when (geq i startat)
        (setq a (expt 2 i))
        (validate!-number a (list "power of 2" i))
        (princ i) (ttab 5) (princ "check just division near ") (print a)
        (checknear 0 a)
        (dotimes (j 200)
          (setq b (expt 2 j))
          (validate!-number b (list "power of 2" i))
          (checknear a b)))) t t))
    (terpri)
    (printc "+++ Stopping")
    (stop 1)))

% End of bigarith.lsp
