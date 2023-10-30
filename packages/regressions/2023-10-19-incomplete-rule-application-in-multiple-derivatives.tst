comment A problem reported by Alan Barnes:
        a rule for derivatives is sometimes not completely applied
        when differentiating more than once;

depend a, r, t, x$

drule := {df(~z, r) => df(z, x)/r when z freeof df}$

r^2*df(a,r,2) where drule;

r^3*df(a,r,3) where drule;

end;
