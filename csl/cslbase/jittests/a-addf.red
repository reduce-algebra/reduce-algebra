
on time, echo;
lisp;
on comp, pgwd;    % Observe the bytecodes.
enable!-errorset(3,3);

symbolic procedure Jaddf(u, v);
  begin
    scalar r, w;
% r will end up as a (reversed) list of items to be put
% in front of the terminating item w.
  top:
    if null u then << w := v; go to exit >>
    else if null v then << w := u; go to exit >>
    else if domainp u then << w := addd(u, v); go to exit >>
    else if domainp v then << w := addd(v, u); go to exit >>
    else if peq(lpow u, lpow v) then <<
      w := Jaddf(lc u, lc v);
      if not null w then r := (lpow u .* w) .+ r;
      u := red u;
      v := red v >>
    else if ordpp(lpow u, lpow v) then <<
      r := lt u .+ r;
      u := cdr u >>
    else <<
      r := lt v .+ r;
      v := red v >>;
    go to top;
  exit:
    while r do <<
      u := cdr r;
      print list('r, r);
      rplacd(r, w);
      w := r;
      r := u >>;
    return w;
  end;


arg1 := '(((x . 1) . 2) . 3);
arg2 := '(((x . 1) . 5) . 7);

Jaddf(arg1, arg2);

make!-jit 'Jaddf;

Jaddf(arg1, arg2);

quit;
