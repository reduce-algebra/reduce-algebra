%
% testcases.red
%


% Small test-cases for the vjacn.red compiler.



% Author: Vijay Chauhan and Arthur Norman          Copyright 2002-2011

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%





%test all the 14 cases

lisp;

symbolic procedure identity x;
  x;

symbolic procedure identity2a(x, y);
  x;

symbolic procedure identity2b(x, y);
  y;
    
symbolic procedure identity3a(a,b,c);
  a;

symbolic procedure identity3b(a,b,c);
  b;

symbolic procedure identity3c(a,b,c);
  c;    

symbolic procedure nilfn();
  nil;

symbolic procedure constfn();
  "this is a constant string";

symbolic procedure ifffn x;
  if x then x;

symbolic procedure iffn x;
  if x then x else 2;
    
symbolic procedure callsomething x;
  append(x, x);

symbolic procedure myapp(a, b);
  if null a then b
  else car a . myapp(cdr a, b);
  
symbolic procedure reverse2(a,b);
  if null a then b 
  else reverse2(cdr a, car a . b);

symbolic procedure reverse1(a);
  reverse2(a, nilfn());

vijay_compile 'identity;
vijay_compile 'identity2a;
vijay_compile 'identity2b;

vijay_compile 'identity3a;
vijay_compile 'identity3b;
vijay_compile 'identity3c;

vijay_compile 'nilfn;
vijay_compile 'constfn;
vijay_compile 'ifffn;
vijay_compile 'iffn;
vijay_compile 'callsomething;
vijay_compile 'myapp;
vijay_compile 'reverse2;
vijay_compile 'reverse1;

identity 'test_arg;
identity2a('test_arg1, 'test_arg2);
identity2b('test_arg1, 'test_arg2);
identity3a('test_arg1, 'test_arg2, 'test_arg3);
identity3b('test_arg1, 'test_arg2, 'test_arg3);
identity3c('test_arg1, 'test_arg2, 'test_arg3);
nilfn();
constfn();
ifffn 'nonnil;
ifffn nil;
iffn 'nonnil;
iffn nil;
callsomething '(a b c d);
myapp('(a b c), '(1 2 3));
reverse2('(a b c), '(1 2 3));
reverse1('(a b c));

end;