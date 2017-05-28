%
% lufylib.red                   A C Norman     Copyright (C) Codemist, 2017
%

%%
%% Copyright (C) 2017,                                 A C Norman, Codemist
%%
%% Redistribution and use in source and binary forms, with or without
%% modification, are permitted provided that the following conditions are
%% met:
%%
%%     * Redistributions of source code must retain the relevant
%%       copyright notice, this list of conditions and the following
%%       disclaimer.
%%     * Redistributions in binary form must reproduce the above
%%       copyright notice, this list of conditions and the following
%%       disclaimer in the documentation and/or other materials provided
%%       with the distribution.
%%
%% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
%% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
%% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
%% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
%% COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
%% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
%% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
%% OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
%% ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
%% TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
%% THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
%% DAMAGE.
%%

% $Id$

% This file defines functions and values used in the machine-translated
% parts of Lufy.

% A "memoryword" in the TeX source is a 32-bit word that can be
% interpreted as an integer, as two half words, as 4 bytes or as a
% (single precision) floating point number. To cope with type punning
% via the Pascal variant record I will store it as just an integer
% and provide accessor and mutator functions here. Note that the 8
% and 16 bit values used are unsigned.

symbolic procedure get!-rh n;   % right halfword
    land(n, 0xffff);

symbolic procedure get!-lh n;   % left halfword
    land(lshift(n, -16), 0xffff);

symbolic procedure get!-b0 n;   % rightmost byte
    land(n, 0xff);

symbolic procedure get!-b1 n;
    land(lshift(n, -8), 0xff);

symbolic procedure get!-b2 n;
    land(lshift(n, -16), 0xff);

symbolic procedure get!-b3 n;   % leftmost byte
    land(lshift(n, -24), 0xff);

symbolic procedure set!-rh(w, n);   % right halfword
    lor(land(w, 0xffff0000), land(n, 0xffff));

symbolic procedure set!-lh(w, n);   % left halfword
    lor(land(w, 0xffff), lshift(land(n, 0xffff), 16);

symbolic procedure set!-b0(w, n);   % rightmost byte
    lor(land(w, 0xffffff00), land(n, 0xff));

symbolic procedure set!-b1(w, n);
    lor(land(w, 0xffff00ff), lshift(land(n, 0xff), 8));

symbolic procedure set!-b2(w, n);
    lor(land(w, 0xff00ffff), lshift(land(n, 0xff), 16));

symbolic procedure set!-b3(w, n);   % leftmost byte
    lor(land(w, 0x00ffffff), lshift(land(n, 0xff), 24));

% Now the conversion to and from floating point is quite a lot messier!

symbolic procedure get!-fp n;
  begin
    scalar s, x, m;
% Inspectr the sign bit.
    if land(n, 0x80000000) neq 0 then <<
       s := t; % negative
       n = land(n, 0x7fffffff) >>;
    if m = 0 then return 0.0;  % zero (regardless of sign bit).
% Separate out the exponent field.
    x := land(lshift(n, -23), 0xff);
    m := land(n, 0x007fffff);
    if x = 0 then return 0.0;  % sub-normalised values go to zero here
    m = lor(m, 0x00800000);    % restore hidden bit
% On the next line I float an integer representation of the mantissa,
% and the power of 2 that I need to mulriply this by is 0x7f-23, which
% is 104. because Lisp will be working using doubles not floats I will not
% get premature exponent overflow or underflow in the use of expt here.
    n := float m*expt(2.0, x-104); 
% Now attach the sign.
    if s then return -n
    else return n
end;

symbolic procedure put!-fp d;
  begin
    scalar s, x, m, w;
% Deal with zeros, NaNs and infinities.
    if x = 0.0 or x neq x then return 0
    else if 1.0/x = 0.0 then <<
      if d < 0.0 then return 0xff800000
      else return 0x7ff800000 >>;
% Separate off the sign.
    if d >= 0 then s := 0
    else <<
      d := -d;
      s := 0x80000000 >>;
% Now what I want to do is to separate off the exponent. This next
% line does so but not with perfect accuracy.
    x := fix (ln d/0.6931471805599453);
    d := d/expt(2.0, x);
% Do a pessimistic correction loop to get the remaining mantissa in
% the range [1:2).
    while d >= 2.0 do <<
      d := 0.5*d;
      x := x + 1 >>;
    while d < 1.0 do <<
      d := 2.0*d;
      x := x - 1 >>;
% Fix the mantissa and remove the hidden bit. This does not apply a
% "round to even" policy., but if the input number really represented
% a 32-bit float there ought not to be any rounding needed at all, so this
% does not matter much.
    m := fix(8388608.8*d + 0.5) - 83886608;
% Offset the exponent.
    x := x + 0x7f;
% Deal with exponent overflow and underflow.
    if x >= 0xff then  <<
      if s neq 0 then return 0xff800000
      else return 0x7ff800000 >>;
% Sub-normal numbers are all flushed to zero.
    if x <= 0 return 0;
% Pack and return.
    return lor(s, lor(lshift(x, 23), m))
  end;

% End of lufylib.red
