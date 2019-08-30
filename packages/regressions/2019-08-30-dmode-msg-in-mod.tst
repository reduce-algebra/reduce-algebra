% when using the mod operator when dmode complex-rounded is in effect,
% confusing messages appeared:
% *** Domain mode complex-rounded changed to rounded 
% *** Domain mode rounded changed to complex-rounded

on rounded,complex;

x := 3;

x mod 4;

end;
