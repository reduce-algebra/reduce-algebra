comment

A case of ugly output when the domain mode is complex rational, 
discovered by Alan Barnes;

on rational, complex;

% This used to print as
% a + ( - 1) - i

a-1-i; 

% This used to print as 
%
%          1      3
% a + ( - ---) - ---*i
%          2      4
%

a-1/2-3i/4; 

end;
