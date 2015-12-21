
% Conservation laws (including trivial ones)$

ct := (6*c(45)*p_4x + 6*c(44)*p_t3x + 6*c(43)*p_2t2x + 6*c(42)*p_3tx + 6*c(34)*
p_2x*u_t + 6*c(34)*p_t2x*u + 6*c(34)*p_y + 6*c(33)*p_2x*u_x + 6*c(33)*p_3x*u + 6
*c(30)*p_t2x*u + 6*c(30)*p_tx*u_x + 6*c(27)*p_2t*u_x + 6*c(27)*p_2tx*u - 6*c(24)
*p_t2x*u + 6*c(24)*p_x*u_tx - 6*c(24)*p_y - 6*c(23)*p_3x*u + 6*c(23)*p_x*u_2x + 
3*c(21)*p_2x*u**2 + 6*c(21)*p_x*u*u_x + 6*c(18)*p_t*u_tx + 6*c(18)*p_tx*u_t + 6*
c(17)*p_t*u_2x - 6*c(17)*p_t2x*u + 6*c(15)*p_t*u*u_x + 3*c(15)*p_tx*u**2 + 6*c(
12)*p*u_2tx + 6*c(12)*p_x*u_2t + 6*c(11)*p*u_t2x + 6*c(11)*p_t2x*u + 6*c(11)*p_y
 + 6*c(10)*p*u_3x + 6*c(10)*p_3x*u + 6*c(5)*p*u*u_tx + 6*c(5)*p*u_t*u_x + 6*c(5)
*p_x*u*u_t + 6*c(4)*p*u*u_2x + 6*c(4)*p*u_x**2 - 3*c(4)*p_2x*u**2 + 6*c(2)*p*u**
2*u_x + 2*c(2)*p_x*u**3)/6$

cx := (6*c(45)*p_t3x + 6*c(44)*p_2t2x + 6*c(43)*p_3tx + 6*c(42)*p_4t - 6*c(34)*
p_2t*u_x + 6*c(34)*p_2tx*u + 12*c(34)*p_tx*u_t - 6*c(34)*p_z + 6*c(33)*p_2x*u_t 
+ 6*c(33)*p_t2x*u + 6*c(30)*p_2tx*u + 6*c(30)*p_tx*u_t + 6*c(27)*p_2t*u_t + 6*c(
27)*p_3t*u + 6*c(24)*p_2t*u_x - 6*c(24)*p_2tx*u - 6*c(24)*p_tx*u_t + 6*c(24)*p_x
*u_2t + 6*c(24)*p_z - 6*c(23)*p_2x*u_t - 6*c(23)*p_t2x*u + 6*c(23)*p_tx*u_x + 6*
c(23)*p_x*u_tx + 3*c(21)*p_tx*u**2 + 6*c(21)*p_x*u*u_t + 6*c(18)*p_2t*u_t + 6*c(
18)*p_t*u_2t + 6*c(17)*p_2t*u_x - 6*c(17)*p_2tx*u + 6*c(17)*p_t*u_tx - 6*c(17)*
p_tx*u_t + 3*c(15)*p_2t*u**2 + 6*c(15)*p_t*u*u_t + 6*c(12)*p*u_3t + 6*c(12)*p_t*
u_2t + 6*c(11)*p*u_2tx - 6*c(11)*p_2t*u_x + 6*c(11)*p_2tx*u + 6*c(11)*p_t*u_tx +
 6*c(11)*p_tx*u_t - 6*c(11)*p_x*u_2t - 6*c(11)*p_z + 6*c(10)*p*u_t2x + 6*c(10)*
p_2x*u_t + 6*c(10)*p_t*u_2x + 6*c(10)*p_t2x*u - 6*c(10)*p_tx*u_x - 6*c(10)*p_x*
u_tx + 6*c(5)*p*u*u_2t + 6*c(5)*p*u_t**2 + 6*c(5)*p_t*u*u_t + 6*c(4)*p*u*u_tx + 
6*c(4)*p*u_t*u_x + 6*c(4)*p_t*u*u_x - 3*c(4)*p_tx*u**2 - 6*c(4)*p_x*u*u_t + 6*c(
2)*p*u**2*u_t + 2*c(2)*p_t*u**3)/6$

% Conservation laws (after removal of trivial ones)$

ctnontriv :=  - c(34)*p_2x*u_t - c(34)*p_t2x*u - c(34)*p_y + c(24)*p_2x*u_t + c(
24)*p_t2x*u + c(24)*p_y - c(11)*p_2x*u_t - c(11)*p_t2x*u - c(11)*p_y$

cxnontriv := c(34)*p_2t*u_x - c(34)*p_2tx*u - 2*c(34)*p_tx*u_t + c(34)*p_z - c(
24)*p_2t*u_x + c(24)*p_2tx*u + 2*c(24)*p_tx*u_t - c(24)*p_z + c(11)*p_2t*u_x - c
(11)*p_2tx*u - 2*c(11)*p_tx*u_t + c(11)*p_z$

;end;$
