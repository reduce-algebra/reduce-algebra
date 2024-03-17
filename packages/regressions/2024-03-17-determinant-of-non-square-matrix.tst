%
% Applying the det operator to a non-square matrix failed to
% print an error message.
%

mat05 := mat((1,0,-1),(0,1,0));

det(mat05);

on rounded;

det(mat05);

end;

