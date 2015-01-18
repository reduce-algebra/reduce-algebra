
% This worked
xn := select(~x < 0, {1,2,-3,4});  abs(xn);

% This triggered an error
abs select(~x < 0, {1,2,-3,4});

% And this one as well
select(~x < 0, {1,2});

end;
