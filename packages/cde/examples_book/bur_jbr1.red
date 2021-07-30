% Burgers equation: Jacobi bracket of higher symmetries.
% 2017-10-01

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


%on comp, echo, backtrace;
load_package cde;
%in "cde_vectorfield.red";
%algebraic;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u}$
odd_var:={p}$
total_order:=10$

% names for output of the state of cde and results of computations
statename:="bur_jbr1_state.red"$
resname:="bur_jbr1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u_2x+2*u*u_x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{principal_der,de,{},{}})$

% Saving cde state in a file
save_cde_state(statename)$

% we load a generating function of a symmetry, computed in bur_hsy1.red
operator c$
sym := (6*c(34)*u*u_x + 3*c(34)*u_2x + 16*c(22)*t*u**3*u_x + 24*c(22)*t*u**2*
u_2x + 16*c(22)*t*u*u_3x + 48*c(22)*t*u*u_x**2 + 40*c(22)*t*u_2x*u_x + 4*c(22)*t
*u_4x + 2*c(22)*u**3 + 6*c(22)*u**2*u_x*x + 6*c(22)*u*u_2x*x - c(22)*u_2x + 2*c(
22)*u_3x*x + 6*c(22)*u_x**2*x + 6*c(20)*u_x + 18*c(12)*t*u**2*u_x + 18*c(12)*t*u
*u_2x + 6*c(12)*t*u_3x + 18*c(12)*t*u_x**2 + 3*c(12)*u**2 + 6*c(12)*u*u_x*x + 3*
c(12)*u_2x*x + 24*c(6)*t*u*u_x + 12*c(6)*t*u_2x + 6*c(6)*u + 6*c(6)*u_x*x + 6*c(
3)*t*u_x + 3*c(3))/6$

mk_evfield(evsym01);
evsym01(0,1):=df(sym,c(20));
evsym01(1,1):=0;

mk_evfield(evsym11);
evsym11(0,1):=df(sym,c(3));
evsym11(1,1):=0;

mk_evfield(evsym02);
evsym02(0,1):=df(sym,c(34));
evsym02(1,1):=0;

mk_evfield(evsym12);
evsym12(0,1):=df(sym,c(6));
evsym12(1,1):=0;

mk_evfield(evsym13);
evsym13(0,1):=df(sym,c(12));
evsym13(1,1):=0;

jacobi_bracket(evsym01,evsym12,ev_01_12);

% The following code can be used to test that
% the Jacobi bracket of two symmetries is a symmetry.
sym:=ev_01_12(0,1);
td(sym,t)-td(sym,x,2)-2*u*td(sym,x)-2*u_x*sym;

;end;

