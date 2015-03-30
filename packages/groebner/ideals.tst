i_setting(x,y,z);

torder revgradlex;

u := i(x*z-y**2, x**3-y*z);
y member i(x,y^2);
x member i(x,y^2);
i(x,y^2) subset i(x,y);         % yes
i(x,y) subset i(x,y^2);         % no

% examples taken from Cox, Little, O'Shea: "Ideals, Varieties and Algorithms"




q1 := u .: i(x);                        % quotient ideal

q2 := u .+ i(x^2 * y - z^2);            % sum ideal

if q1 .= q2 then write "same ideal";    % test equality

intersection(u,i(y));                   % ideal intersection

u .: i(y);

u .: i(x,y);

%-----------------------------------------------------

u1 := i(x,y^2);
u1u1:= u1 .* u1;                       % square ideal
u0 :=i(x,y);

% test equality/inclusion for u1,u1u1,u0

u1 .= u1u1;     % no

u1 subset u1u1; % no

u1u1 subset u1; % yes

u1 .= u0;       % no

u1 subset u0;   % yes

intersection (i(x) , i(x^2,x*y,y^2)) .= intersection(i(x) , i(x^2,y)); 

end;
