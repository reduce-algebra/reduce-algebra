lisp;

load!-package 'assert;
on1 'assert;
on1 'assertbreak;

load!-package 'redlog;
rl_set '(r);

setkorder '(x);

a1 := '(anuiv_span (anusp_open (anu (aex ((((x . 10) . 1)
((x . 9) . -33) ((x . 8) . 474) ((x . 7) . -3894) (
(x . 6) . 20217) ((x . 5) . -69153) ((x . 4) . 157436)
((x . 3) . -234936) ((x . 2) . 219312) ((x . 1) . -115344) . 25920) . 1)
(ctx nil) t t) ((nil . 1) 117469 . 65536))) (anusp_open
(anu (aex ((((x . 10) . 1) ((x . 9) . -33) ((x . 8) . 474)
((x . 7) . -3894) ((x . 6) . 20217) ((x . 5) . -69153)
((x . 4) . 157436) ((x . 3) . -234936) ((x . 2) . 219312)
((x . 1) . -115344) . 25920) . 1) (ctx nil) t t) ((117469 . 65536) 352407 .
131072))))$

a2 := '((anuiv_span (anusp_closed (anu (aex ((((x . 2) . -4)
((x . 1) . 24) . -27) . 1) (ctx nil) t t) ((nil . 1) 35 . 8)))
(anusp_closed (anu (aex ((((x . 2) . -4) ((x . 1) . 24) . -27) . 1)
(ctx nil) t t) ((35 . 8) 35 . 4)))))$

% tr ofsf_ivcutl;
% tr ofsf_ivcut;
% tr ofsf_ivcut2;
% tr ofsf_ivbmax;
% tr ofsf_ivbmin;
% tr ganu_compare;
% tr anu_compare;
% tr aex_minus;

procedure anu_compare2(anu1, anu2, g);
   % [anu1], [anu2] are Anu or 'minf or 'pinf. Returns an integer [z]. We have
   % [z < 0] if [anu1 < anu2], [z = 0] if [anu1 = anu2] and [z = 1] if [anu1 >
   % anu2].
   begin scalar hugo, aex1, aex2;
      aex1 := aex_fromAnu anu1;
      aex2 := aex_fromAnu anu_varChange(anu2, g);
      hugo := aex_minus(aex1, aex2);
      hugo := aex_sgn hugo;
      return hugo
   end;

trst anu_compare2;

% ofsf_ivcutl(a1, a2);

aex := aex_fromrp simp xread t;
4*x - 12;

dp := aex_fromrp simp xread t;
x^2 - 1;

dp := aex_fromrp simp xread t;
(x-1)^2*(x-2)^2*(x-3)^2*(x-4)*(x-5)*(x-6)^2;

dp := aex_fromrp simp xread t;
(x-1)*(x-3)^2;

aex := aex_bind(aex, 'x, anu_mk(dp, iv_mk(simp 0, simp '(quotient 3 2))));

aex_inv aex;

end;
