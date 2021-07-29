% Potential Khokhlov-Zabolotskaya equation: local conservation laws
% 2015-11-13

% Author: Raffaele Vitolo

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

% $Id: $


load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={v,w}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="pkz_csy1_state.red"$
resname:="pkz_csy1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={v_y,w_y}$
% right-hand side of the differential equation
de:={w,v_tx - v_x*v_2x}$

% Calling cde's main routine
cde({indep_var,dep_var,{},total_order},
   {principal_der,de,{},{}})$

% Conservation laws of the Khokhlov-Zabolotskaya equation
% (after removal of trivial ones), result from the program file pkz_lcl1.red
operator c;

ctnontriv := 0$

cxnontriv := (24*c(1684)*v_t - 12*c(1684)*v_x**2 - 12*c(1675)*v_t + 6*c(1675)*
v_x**2 - 12*c(1642)*v_t + 6*c(1642)*v_x**2 - 12*c(1625)*v_t + 6*c(1625)*v_x**2 -
 24*c(1583)*v_t + 12*c(1583)*v_x**2 + 12*c(1488)*v_t - 6*c(1488)*v_x**2 + 6*c(
1465)*v_t - 3*c(1465)*v_x**2 + 6*c(1463)*v_t - 3*c(1463)*v_x**2 + 24*c(1342)*v_t
 - 12*c(1342)*v_x**2 - 24*c(1322)*v_t + 12*c(1322)*v_x**2 + 24*c(1318)*v_t - 12*
c(1318)*v_x**2 - 48*c(1272)*v_t + 24*c(1272)*v_x**2 + 24*c(1269)*v_t - 12*c(1269
)*v_x**2 - 12*c(681)*t*v**2*w_2x - 12*c(681)*t*v*v_2tx*y + 36*c(681)*t*v*v_2x*
v_tx*y + 24*c(681)*t*v*v_3x*v_x**2*y - 12*c(681)*t*v*v_t2x*v_x*y - 72*c(681)*t*v
*v_x*w_x + 24*c(681)*t*v*w*w_2x*y - 24*c(681)*t*v*w_x**2*y - 6*c(681)*t*v_2tx*
v_tx*y**3 + 12*c(681)*t*v_2tx*v_x*x*y - 12*c(681)*t*v_2x*v_x**3*y + 24*c(681)*t*
v_2x*w**2*y - 12*c(681)*t*v_3t*x*y - 2*c(681)*t*v_3tx*v_x*y**3 + 2*c(681)*t*v_4t
*y**3 + 12*c(681)*t*v_tx**2*x*y + 12*c(679)*t*v**2*w_2x + 12*c(679)*t*v*v_2tx*y 
- 36*c(679)*t*v*v_2x*v_tx*y - 24*c(679)*t*v*v_3x*v_x**2*y + 12*c(679)*t*v*v_t2x*
v_x*y + 72*c(679)*t*v*v_x*w_x - 24*c(679)*t*v*w*w_2x*y + 24*c(679)*t*v*w_x**2*y 
+ 6*c(679)*t*v_2tx*v_tx*y**3 - 12*c(679)*t*v_2tx*v_x*x*y + 12*c(679)*t*v_2x*v_x
**3*y - 24*c(679)*t*v_2x*w**2*y + 12*c(679)*t*v_3t*x*y + 2*c(679)*t*v_3tx*v_x*y
**3 - 2*c(679)*t*v_4t*y**3 - 12*c(679)*t*v_tx**2*x*y - 12*c(630)*t*v**2*w_2x - 
12*c(630)*t*v*v_2tx*y + 36*c(630)*t*v*v_2x*v_tx*y + 24*c(630)*t*v*v_3x*v_x**2*y 
- 12*c(630)*t*v*v_t2x*v_x*y - 72*c(630)*t*v*v_x*w_x + 24*c(630)*t*v*w*w_2x*y - 
24*c(630)*t*v*w_x**2*y - 6*c(630)*t*v_2tx*v_tx*y**3 + 12*c(630)*t*v_2tx*v_x*x*y 
- 12*c(630)*t*v_2x*v_x**3*y + 24*c(630)*t*v_2x*w**2*y - 12*c(630)*t*v_3t*x*y - 2
*c(630)*t*v_3tx*v_x*y**3 + 2*c(630)*t*v_4t*y**3 + 12*c(630)*t*v_tx**2*x*y + 12*c
(627)*t*v**2*w_2x + 12*c(627)*t*v*v_2tx*y - 36*c(627)*t*v*v_2x*v_tx*y - 24*c(627
)*t*v*v_3x*v_x**2*y + 12*c(627)*t*v*v_t2x*v_x*y + 72*c(627)*t*v*v_x*w_x - 24*c(
627)*t*v*w*w_2x*y + 24*c(627)*t*v*w_x**2*y + 6*c(627)*t*v_2tx*v_tx*y**3 - 12*c(
627)*t*v_2tx*v_x*x*y + 12*c(627)*t*v_2x*v_x**3*y - 24*c(627)*t*v_2x*w**2*y + 12*
c(627)*t*v_3t*x*y + 2*c(627)*t*v_3tx*v_x*y**3 - 2*c(627)*t*v_4t*y**3 - 12*c(627)
*t*v_tx**2*x*y - 12*c(625)*t*v**2*w_2x - 12*c(625)*t*v*v_2tx*y + 36*c(625)*t*v*
v_2x*v_tx*y + 24*c(625)*t*v*v_3x*v_x**2*y - 12*c(625)*t*v*v_t2x*v_x*y - 72*c(625
)*t*v*v_x*w_x + 24*c(625)*t*v*w*w_2x*y - 24*c(625)*t*v*w_x**2*y - 6*c(625)*t*
v_2tx*v_tx*y**3 + 12*c(625)*t*v_2tx*v_x*x*y - 12*c(625)*t*v_2x*v_x**3*y + 24*c(
625)*t*v_2x*w**2*y - 12*c(625)*t*v_3t*x*y - 2*c(625)*t*v_3tx*v_x*y**3 + 2*c(625)
*t*v_4t*y**3 + 12*c(625)*t*v_tx**2*x*y + 12*c(620)*t*v**2*w_2x + 12*c(620)*t*v*
v_2tx*y - 36*c(620)*t*v*v_2x*v_tx*y - 24*c(620)*t*v*v_3x*v_x**2*y + 12*c(620)*t*
v*v_t2x*v_x*y + 72*c(620)*t*v*v_x*w_x - 24*c(620)*t*v*w*w_2x*y + 24*c(620)*t*v*
w_x**2*y + 6*c(620)*t*v_2tx*v_tx*y**3 - 12*c(620)*t*v_2tx*v_x*x*y + 12*c(620)*t*
v_2x*v_x**3*y - 24*c(620)*t*v_2x*w**2*y + 12*c(620)*t*v_3t*x*y + 2*c(620)*t*
v_3tx*v_x*y**3 - 2*c(620)*t*v_4t*y**3 - 12*c(620)*t*v_tx**2*x*y + 12*c(592)*t*v
**2*w_2x + 12*c(592)*t*v*v_2tx*y - 36*c(592)*t*v*v_2x*v_tx*y - 24*c(592)*t*v*
v_3x*v_x**2*y + 12*c(592)*t*v*v_t2x*v_x*y + 72*c(592)*t*v*v_x*w_x - 24*c(592)*t*
v*w*w_2x*y + 24*c(592)*t*v*w_x**2*y + 6*c(592)*t*v_2tx*v_tx*y**3 - 12*c(592)*t*
v_2tx*v_x*x*y + 12*c(592)*t*v_2x*v_x**3*y - 24*c(592)*t*v_2x*w**2*y + 12*c(592)*
t*v_3t*x*y + 2*c(592)*t*v_3tx*v_x*y**3 - 2*c(592)*t*v_4t*y**3 - 12*c(592)*t*v_tx
**2*x*y - 12*c(587)*t*v**2*w_2x - 12*c(587)*t*v*v_2tx*y + 36*c(587)*t*v*v_2x*
v_tx*y + 24*c(587)*t*v*v_3x*v_x**2*y - 12*c(587)*t*v*v_t2x*v_x*y - 72*c(587)*t*v
*v_x*w_x + 24*c(587)*t*v*w*w_2x*y - 24*c(587)*t*v*w_x**2*y - 6*c(587)*t*v_2tx*
v_tx*y**3 + 12*c(587)*t*v_2tx*v_x*x*y - 12*c(587)*t*v_2x*v_x**3*y + 24*c(587)*t*
v_2x*w**2*y - 12*c(587)*t*v_3t*x*y - 2*c(587)*t*v_3tx*v_x*y**3 + 2*c(587)*t*v_4t
*y**3 + 12*c(587)*t*v_tx**2*x*y + 24*c(394)*t*v**2*w_2x + 24*c(394)*t*v*v_2tx*y 
- 72*c(394)*t*v*v_2x*v_tx*y - 48*c(394)*t*v*v_3x*v_x**2*y + 24*c(394)*t*v*v_t2x*
v_x*y + 144*c(394)*t*v*v_x*w_x - 48*c(394)*t*v*w*w_2x*y + 48*c(394)*t*v*w_x**2*y
 + 12*c(394)*t*v_2tx*v_tx*y**3 - 24*c(394)*t*v_2tx*v_x*x*y + 24*c(394)*t*v_2x*
v_x**3*y - 48*c(394)*t*v_2x*w**2*y + 24*c(394)*t*v_3t*x*y + 4*c(394)*t*v_3tx*v_x
*y**3 - 4*c(394)*t*v_4t*y**3 - 24*c(394)*t*v_tx**2*x*y - 24*c(382)*t*v**2*w_2x -
 24*c(382)*t*v*v_2tx*y + 72*c(382)*t*v*v_2x*v_tx*y + 48*c(382)*t*v*v_3x*v_x**2*y
 - 24*c(382)*t*v*v_t2x*v_x*y - 144*c(382)*t*v*v_x*w_x + 48*c(382)*t*v*w*w_2x*y -
 48*c(382)*t*v*w_x**2*y - 12*c(382)*t*v_2tx*v_tx*y**3 + 24*c(382)*t*v_2tx*v_x*x*
y - 24*c(382)*t*v_2x*v_x**3*y + 48*c(382)*t*v_2x*w**2*y - 24*c(382)*t*v_3t*x*y -
 4*c(382)*t*v_3tx*v_x*y**3 + 4*c(382)*t*v_4t*y**3 + 24*c(382)*t*v_tx**2*x*y + 24
*c(381)*t*v**2*w_2x + 24*c(381)*t*v*v_2tx*y - 72*c(381)*t*v*v_2x*v_tx*y - 48*c(
381)*t*v*v_3x*v_x**2*y + 24*c(381)*t*v*v_t2x*v_x*y + 144*c(381)*t*v*v_x*w_x - 48
*c(381)*t*v*w*w_2x*y + 48*c(381)*t*v*w_x**2*y + 12*c(381)*t*v_2tx*v_tx*y**3 - 24
*c(381)*t*v_2tx*v_x*x*y + 24*c(381)*t*v_2x*v_x**3*y - 48*c(381)*t*v_2x*w**2*y + 
24*c(381)*t*v_3t*x*y + 4*c(381)*t*v_3tx*v_x*y**3 - 4*c(381)*t*v_4t*y**3 - 24*c(
381)*t*v_tx**2*x*y + 24*c(358)*t*v**2*w_2x + 24*c(358)*t*v*v_2tx*y - 72*c(358)*t
*v*v_2x*v_tx*y - 48*c(358)*t*v*v_3x*v_x**2*y + 24*c(358)*t*v*v_t2x*v_x*y + 144*c
(358)*t*v*v_x*w_x - 48*c(358)*t*v*w*w_2x*y + 48*c(358)*t*v*w_x**2*y + 12*c(358)*
t*v_2tx*v_tx*y**3 - 24*c(358)*t*v_2tx*v_x*x*y + 24*c(358)*t*v_2x*v_x**3*y - 48*c
(358)*t*v_2x*w**2*y + 24*c(358)*t*v_3t*x*y + 4*c(358)*t*v_3tx*v_x*y**3 - 4*c(358
)*t*v_4t*y**3 - 24*c(358)*t*v_tx**2*x*y + 12*c(309)*t*v**2*w_2x + 12*c(309)*t*v*
v_2tx*y - 36*c(309)*t*v*v_2x*v_tx*y - 24*c(309)*t*v*v_3x*v_x**2*y + 12*c(309)*t*
v*v_t2x*v_x*y + 72*c(309)*t*v*v_x*w_x - 24*c(309)*t*v*w*w_2x*y + 24*c(309)*t*v*
w_x**2*y + 6*c(309)*t*v_2tx*v_tx*y**3 - 12*c(309)*t*v_2tx*v_x*x*y + 12*c(309)*t*
v_2x*v_x**3*y - 24*c(309)*t*v_2x*w**2*y + 12*c(309)*t*v_3t*x*y + 2*c(309)*t*
v_3tx*v_x*y**3 - 2*c(309)*t*v_4t*y**3 - 12*c(309)*t*v_tx**2*x*y + 12*c(300)*t*v
**2*w_2x + 12*c(300)*t*v*v_2tx*y - 36*c(300)*t*v*v_2x*v_tx*y - 24*c(300)*t*v*
v_3x*v_x**2*y + 12*c(300)*t*v*v_t2x*v_x*y + 72*c(300)*t*v*v_x*w_x - 24*c(300)*t*
v*w*w_2x*y + 24*c(300)*t*v*w_x**2*y + 6*c(300)*t*v_2tx*v_tx*y**3 - 12*c(300)*t*
v_2tx*v_x*x*y + 12*c(300)*t*v_2x*v_x**3*y - 24*c(300)*t*v_2x*w**2*y + 12*c(300)*
t*v_3t*x*y + 2*c(300)*t*v_3tx*v_x*y**3 - 2*c(300)*t*v_4t*y**3 - 12*c(300)*t*v_tx
**2*x*y - 24*c(296)*t*v**2*w_2x - 24*c(296)*t*v*v_2tx*y + 72*c(296)*t*v*v_2x*
v_tx*y + 48*c(296)*t*v*v_3x*v_x**2*y - 24*c(296)*t*v*v_t2x*v_x*y - 144*c(296)*t*
v*v_x*w_x + 48*c(296)*t*v*w*w_2x*y - 48*c(296)*t*v*w_x**2*y - 12*c(296)*t*v_2tx*
v_tx*y**3 + 24*c(296)*t*v_2tx*v_x*x*y - 24*c(296)*t*v_2x*v_x**3*y + 48*c(296)*t*
v_2x*w**2*y - 24*c(296)*t*v_3t*x*y - 4*c(296)*t*v_3tx*v_x*y**3 + 4*c(296)*t*v_4t
*y**3 + 24*c(296)*t*v_tx**2*x*y - 24*c(247)*t*v**2*w_2x - 24*c(247)*t*v*v_2tx*y 
+ 72*c(247)*t*v*v_2x*v_tx*y + 48*c(247)*t*v*v_3x*v_x**2*y - 24*c(247)*t*v*v_t2x*
v_x*y - 144*c(247)*t*v*v_x*w_x + 48*c(247)*t*v*w*w_2x*y - 48*c(247)*t*v*w_x**2*y
 - 12*c(247)*t*v_2tx*v_tx*y**3 + 24*c(247)*t*v_2tx*v_x*x*y - 24*c(247)*t*v_2x*
v_x**3*y + 48*c(247)*t*v_2x*w**2*y - 24*c(247)*t*v_3t*x*y - 4*c(247)*t*v_3tx*v_x
*y**3 + 4*c(247)*t*v_4t*y**3 + 24*c(247)*t*v_tx**2*x*y + 24*c(242)*t*v**2*w_2x +
 24*c(242)*t*v*v_2tx*y - 72*c(242)*t*v*v_2x*v_tx*y - 48*c(242)*t*v*v_3x*v_x**2*y
 + 24*c(242)*t*v*v_t2x*v_x*y + 144*c(242)*t*v*v_x*w_x - 48*c(242)*t*v*w*w_2x*y +
 48*c(242)*t*v*w_x**2*y + 12*c(242)*t*v_2tx*v_tx*y**3 - 24*c(242)*t*v_2tx*v_x*x*
y + 24*c(242)*t*v_2x*v_x**3*y - 48*c(242)*t*v_2x*w**2*y + 24*c(242)*t*v_3t*x*y +
 4*c(242)*t*v_3tx*v_x*y**3 - 4*c(242)*t*v_4t*y**3 - 24*c(242)*t*v_tx**2*x*y)/12$

cynontriv := (12*c(1684)*w - 6*c(1675)*w - 6*c(1642)*w - 6*c(1625)*w - 12*c(1583
)*w + 6*c(1488)*w + 3*c(1465)*w + 3*c(1463)*w + 12*c(1342)*w - 12*c(1322)*w + 12
*c(1318)*w - 24*c(1272)*w + 12*c(1269)*w - 6*c(681)*t*v**2*v_3x - 36*c(681)*t*v*
v_2x*v_x + 12*c(681)*t*v*v_3x*w*y + 6*c(681)*t*v*v_tx - 12*c(681)*t*v*v_x*w_2x*y
 - 6*c(681)*t*v*w_tx*y + 6*c(681)*t*v_2t*x + 24*c(681)*t*v_2x*v_x*w*y - 3*c(681)
*t*v_3t*y**2 + 6*c(681)*t*v_tx*w*y - 10*c(681)*t*v_x**3 - 6*c(681)*t*v_x**2*w_x*
y - 6*c(681)*t*w**2 - 6*c(681)*t*w_2t*x*y + c(681)*t*w_3t*y**3 + 6*c(679)*t*v**2
*v_3x + 36*c(679)*t*v*v_2x*v_x - 12*c(679)*t*v*v_3x*w*y - 6*c(679)*t*v*v_tx + 12
*c(679)*t*v*v_x*w_2x*y + 6*c(679)*t*v*w_tx*y - 6*c(679)*t*v_2t*x - 24*c(679)*t*
v_2x*v_x*w*y + 3*c(679)*t*v_3t*y**2 - 6*c(679)*t*v_tx*w*y + 10*c(679)*t*v_x**3 +
 6*c(679)*t*v_x**2*w_x*y + 6*c(679)*t*w**2 + 6*c(679)*t*w_2t*x*y - c(679)*t*w_3t
*y**3 - 6*c(630)*t*v**2*v_3x - 36*c(630)*t*v*v_2x*v_x + 12*c(630)*t*v*v_3x*w*y +
 6*c(630)*t*v*v_tx - 12*c(630)*t*v*v_x*w_2x*y - 6*c(630)*t*v*w_tx*y + 6*c(630)*t
*v_2t*x + 24*c(630)*t*v_2x*v_x*w*y - 3*c(630)*t*v_3t*y**2 + 6*c(630)*t*v_tx*w*y 
- 10*c(630)*t*v_x**3 - 6*c(630)*t*v_x**2*w_x*y - 6*c(630)*t*w**2 - 6*c(630)*t*
w_2t*x*y + c(630)*t*w_3t*y**3 + 6*c(627)*t*v**2*v_3x + 36*c(627)*t*v*v_2x*v_x - 
12*c(627)*t*v*v_3x*w*y - 6*c(627)*t*v*v_tx + 12*c(627)*t*v*v_x*w_2x*y + 6*c(627)
*t*v*w_tx*y - 6*c(627)*t*v_2t*x - 24*c(627)*t*v_2x*v_x*w*y + 3*c(627)*t*v_3t*y**
2 - 6*c(627)*t*v_tx*w*y + 10*c(627)*t*v_x**3 + 6*c(627)*t*v_x**2*w_x*y + 6*c(627
)*t*w**2 + 6*c(627)*t*w_2t*x*y - c(627)*t*w_3t*y**3 - 6*c(625)*t*v**2*v_3x - 36*
c(625)*t*v*v_2x*v_x + 12*c(625)*t*v*v_3x*w*y + 6*c(625)*t*v*v_tx - 12*c(625)*t*v
*v_x*w_2x*y - 6*c(625)*t*v*w_tx*y + 6*c(625)*t*v_2t*x + 24*c(625)*t*v_2x*v_x*w*y
 - 3*c(625)*t*v_3t*y**2 + 6*c(625)*t*v_tx*w*y - 10*c(625)*t*v_x**3 - 6*c(625)*t*
v_x**2*w_x*y - 6*c(625)*t*w**2 - 6*c(625)*t*w_2t*x*y + c(625)*t*w_3t*y**3 + 6*c(
620)*t*v**2*v_3x + 36*c(620)*t*v*v_2x*v_x - 12*c(620)*t*v*v_3x*w*y - 6*c(620)*t*
v*v_tx + 12*c(620)*t*v*v_x*w_2x*y + 6*c(620)*t*v*w_tx*y - 6*c(620)*t*v_2t*x - 24
*c(620)*t*v_2x*v_x*w*y + 3*c(620)*t*v_3t*y**2 - 6*c(620)*t*v_tx*w*y + 10*c(620)*
t*v_x**3 + 6*c(620)*t*v_x**2*w_x*y + 6*c(620)*t*w**2 + 6*c(620)*t*w_2t*x*y - c(
620)*t*w_3t*y**3 + 6*c(592)*t*v**2*v_3x + 36*c(592)*t*v*v_2x*v_x - 12*c(592)*t*v
*v_3x*w*y - 6*c(592)*t*v*v_tx + 12*c(592)*t*v*v_x*w_2x*y + 6*c(592)*t*v*w_tx*y -
 6*c(592)*t*v_2t*x - 24*c(592)*t*v_2x*v_x*w*y + 3*c(592)*t*v_3t*y**2 - 6*c(592)*
t*v_tx*w*y + 10*c(592)*t*v_x**3 + 6*c(592)*t*v_x**2*w_x*y + 6*c(592)*t*w**2 + 6*
c(592)*t*w_2t*x*y - c(592)*t*w_3t*y**3 - 6*c(587)*t*v**2*v_3x - 36*c(587)*t*v*
v_2x*v_x + 12*c(587)*t*v*v_3x*w*y + 6*c(587)*t*v*v_tx - 12*c(587)*t*v*v_x*w_2x*y
 - 6*c(587)*t*v*w_tx*y + 6*c(587)*t*v_2t*x + 24*c(587)*t*v_2x*v_x*w*y - 3*c(587)
*t*v_3t*y**2 + 6*c(587)*t*v_tx*w*y - 10*c(587)*t*v_x**3 - 6*c(587)*t*v_x**2*w_x*
y - 6*c(587)*t*w**2 - 6*c(587)*t*w_2t*x*y + c(587)*t*w_3t*y**3 + 12*c(394)*t*v**
2*v_3x + 72*c(394)*t*v*v_2x*v_x - 24*c(394)*t*v*v_3x*w*y - 12*c(394)*t*v*v_tx + 
24*c(394)*t*v*v_x*w_2x*y + 12*c(394)*t*v*w_tx*y - 12*c(394)*t*v_2t*x - 48*c(394)
*t*v_2x*v_x*w*y + 6*c(394)*t*v_3t*y**2 - 12*c(394)*t*v_tx*w*y + 20*c(394)*t*v_x
**3 + 12*c(394)*t*v_x**2*w_x*y + 12*c(394)*t*w**2 + 12*c(394)*t*w_2t*x*y - 2*c(
394)*t*w_3t*y**3 - 12*c(382)*t*v**2*v_3x - 72*c(382)*t*v*v_2x*v_x + 24*c(382)*t*
v*v_3x*w*y + 12*c(382)*t*v*v_tx - 24*c(382)*t*v*v_x*w_2x*y - 12*c(382)*t*v*w_tx*
y + 12*c(382)*t*v_2t*x + 48*c(382)*t*v_2x*v_x*w*y - 6*c(382)*t*v_3t*y**2 + 12*c(
382)*t*v_tx*w*y - 20*c(382)*t*v_x**3 - 12*c(382)*t*v_x**2*w_x*y - 12*c(382)*t*w
**2 - 12*c(382)*t*w_2t*x*y + 2*c(382)*t*w_3t*y**3 + 12*c(381)*t*v**2*v_3x + 72*c
(381)*t*v*v_2x*v_x - 24*c(381)*t*v*v_3x*w*y - 12*c(381)*t*v*v_tx + 24*c(381)*t*v
*v_x*w_2x*y + 12*c(381)*t*v*w_tx*y - 12*c(381)*t*v_2t*x - 48*c(381)*t*v_2x*v_x*w
*y + 6*c(381)*t*v_3t*y**2 - 12*c(381)*t*v_tx*w*y + 20*c(381)*t*v_x**3 + 12*c(381
)*t*v_x**2*w_x*y + 12*c(381)*t*w**2 + 12*c(381)*t*w_2t*x*y - 2*c(381)*t*w_3t*y**
3 + 12*c(358)*t*v**2*v_3x + 72*c(358)*t*v*v_2x*v_x - 24*c(358)*t*v*v_3x*w*y - 12
*c(358)*t*v*v_tx + 24*c(358)*t*v*v_x*w_2x*y + 12*c(358)*t*v*w_tx*y - 12*c(358)*t
*v_2t*x - 48*c(358)*t*v_2x*v_x*w*y + 6*c(358)*t*v_3t*y**2 - 12*c(358)*t*v_tx*w*y
 + 20*c(358)*t*v_x**3 + 12*c(358)*t*v_x**2*w_x*y + 12*c(358)*t*w**2 + 12*c(358)*
t*w_2t*x*y - 2*c(358)*t*w_3t*y**3 + 6*c(309)*t*v**2*v_3x + 36*c(309)*t*v*v_2x*
v_x - 12*c(309)*t*v*v_3x*w*y - 6*c(309)*t*v*v_tx + 12*c(309)*t*v*v_x*w_2x*y + 6*
c(309)*t*v*w_tx*y - 6*c(309)*t*v_2t*x - 24*c(309)*t*v_2x*v_x*w*y + 3*c(309)*t*
v_3t*y**2 - 6*c(309)*t*v_tx*w*y + 10*c(309)*t*v_x**3 + 6*c(309)*t*v_x**2*w_x*y +
 6*c(309)*t*w**2 + 6*c(309)*t*w_2t*x*y - c(309)*t*w_3t*y**3 + 6*c(300)*t*v**2*
v_3x + 36*c(300)*t*v*v_2x*v_x - 12*c(300)*t*v*v_3x*w*y - 6*c(300)*t*v*v_tx + 12*
c(300)*t*v*v_x*w_2x*y + 6*c(300)*t*v*w_tx*y - 6*c(300)*t*v_2t*x - 24*c(300)*t*
v_2x*v_x*w*y + 3*c(300)*t*v_3t*y**2 - 6*c(300)*t*v_tx*w*y + 10*c(300)*t*v_x**3 +
 6*c(300)*t*v_x**2*w_x*y + 6*c(300)*t*w**2 + 6*c(300)*t*w_2t*x*y - c(300)*t*w_3t
*y**3 - 12*c(296)*t*v**2*v_3x - 72*c(296)*t*v*v_2x*v_x + 24*c(296)*t*v*v_3x*w*y 
+ 12*c(296)*t*v*v_tx - 24*c(296)*t*v*v_x*w_2x*y - 12*c(296)*t*v*w_tx*y + 12*c(
296)*t*v_2t*x + 48*c(296)*t*v_2x*v_x*w*y - 6*c(296)*t*v_3t*y**2 + 12*c(296)*t*
v_tx*w*y - 20*c(296)*t*v_x**3 - 12*c(296)*t*v_x**2*w_x*y - 12*c(296)*t*w**2 - 12
*c(296)*t*w_2t*x*y + 2*c(296)*t*w_3t*y**3 - 12*c(247)*t*v**2*v_3x - 72*c(247)*t*
v*v_2x*v_x + 24*c(247)*t*v*v_3x*w*y + 12*c(247)*t*v*v_tx - 24*c(247)*t*v*v_x*
w_2x*y - 12*c(247)*t*v*w_tx*y + 12*c(247)*t*v_2t*x + 48*c(247)*t*v_2x*v_x*w*y - 
6*c(247)*t*v_3t*y**2 + 12*c(247)*t*v_tx*w*y - 20*c(247)*t*v_x**3 - 12*c(247)*t*
v_x**2*w_x*y - 12*c(247)*t*w**2 - 12*c(247)*t*w_2t*x*y + 2*c(247)*t*w_3t*y**3 + 
12*c(242)*t*v**2*v_3x + 72*c(242)*t*v*v_2x*v_x - 24*c(242)*t*v*v_3x*w*y - 12*c(
242)*t*v*v_tx + 24*c(242)*t*v*v_x*w_2x*y + 12*c(242)*t*v*w_tx*y - 12*c(242)*t*
v_2t*x - 48*c(242)*t*v_2x*v_x*w*y + 6*c(242)*t*v_3t*y**2 - 12*c(242)*t*v_tx*w*y 
+ 20*c(242)*t*v_x**3 + 12*c(242)*t*v_x**2*w_x*y + 12*c(242)*t*w**2 + 12*c(242)*t
*w_2t*x*y - 2*c(242)*t*w_3t*y**3)/6$


% Next commands find generating functions corresponding to 
% nontrivial conservation laws.
genfun:={pvar_df(0,cynontriv,v),pvar_df(0,cynontriv,w)}$

% Extracting all constants
c_list:=cde_mkset(
      append(cdiff_get_kernels(cxnontriv,c),
      cdiff_get_kernels(cynontriv,c))
)$

% Finding the generating functions corresponding to every constant
genfun_el:=
  for each el in c_list collect {el,for each ell in genfun collect df(ell,el)}$

off nat$
off echo$
out <<resname>>$
write "% Conservation laws (after removal of trivial ones)";
write ctnontriv:=ctnontriv;
write cxnontriv:=cxnontriv;
write cynontriv:=cynontriv;

write genfun_el:=genfun_el;

write ";end;";
shut <<resname>>$
on echo$
on nat$


;end;

Local Variables:
mode:reduce
End:
