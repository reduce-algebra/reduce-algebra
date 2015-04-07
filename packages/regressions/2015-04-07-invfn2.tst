on complex, rounded;
epsilon :=0.0001;

% fewer tests as acosh, asin & acos all defined in terms of asinh
% acosh  
a:= {acosh(1), acosh(-1), acosh(0)};
cosh a;

a:= {acosh(1+i), acosh(-1-i), acosh(1-i), acosh(-1+i)};
cosh a;
first a+second a;

a:= {acosh(3+i), acosh(-3-i), acosh(3-i), acosh(-3+i)};
cosh a;
first a+second a;

a:= {acosh(i), acosh(i+epsilon), acosh(i-epsilon)};
cosh a;
b:= {acosh(-i), acosh(-i-epsilon), acosh(-i+epsilon)};
cosh b;
{first a+first b,second a+second b, third a+third b};

a:= {acosh(4i), acosh(4i+epsilon), acosh(4i-epsilon)};
cosh a;
b:= {acosh(-4i), acosh(-4i-epsilon), acosh(-4i+epsilon)};
cosh b;
{first a+first b,second a+second b, third a+third b};

precision 20;
% values on the real axis (includes the cut)

% two branch points
a:= {acosh(1), acosh(1+epsilon*i), acosh(1-epsilon*i)};
cosh a;
b:= {acosh(-1), acosh(-1-epsilon*i), acosh(-1+epsilon*i)};
cosh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% not on the cut
a:= {acosh(1/2), acosh(1/2+epsilon*i), acosh(1/2-epsilon*i)};
cosh a;
b:= {acosh(-1/2), acosh(-1/2-epsilon*i), acosh(-1/2+epsilon*i)};
cosh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% on the cut 
a:= {acosh(3/2), acosh(3/2+epsilon*i), acosh(3/2-epsilon*i)};
cosh a;
b:= {acosh(-3/2), acosh(-3/2-epsilon*i), acosh(-3/2+epsilon*i)};
cosh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

precision 12;
% asin  
a:= {asin(1), asin(-1), asin(0)};
sin a;

a:= {asin(1+i), asin(-1-i), asin(1-i), asin(-1+i)};
sin a;
first a+second a;

a:= {asin(3+i), asin(-3-i), asin(3-i), asin(-3+i)};
sin a;
first a+second a;

a:= {asin(i), asin(i+epsilon), asin(i-epsilon)};
sin a;
b:= {asin(-i), asin(-i-epsilon), asin(-i+epsilon)};
sin b;
{first a+first b,second a+second b, third a+third b};

a:= {asin(4i), asin(4i+epsilon), asin(4i-epsilon)};
sin a;
b:= {asin(-4i), asin(-4i-epsilon), asin(-4i+epsilon)};
sin b;
{first a+first b,second a+second b, third a+third b};

% values on the real axis (includes the cut)

% two branch points
a:= {asin(1), asin(1+epsilon*i), asin(1-epsilon*i)};
sin a;
b:= {asin(-1), asin(-1-epsilon*i), asin(-1+epsilon*i)};
sin b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% not on the cut
a:= {asin(1/2), asin(1/2+epsilon*i), asin(1/2-epsilon*i)};
sin a;
b:= {asin(-1/2), asin(-1/2-epsilon*i), asin(-1/2+epsilon*i)};
sin b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% on the cut
a:= {asin(3/2), asin(3/2+epsilon*i), asin(3/2-epsilon*i)};
sin a;
b:= {asin(-3/2), asin(-3/2-epsilon*i), asin(-3/2+epsilon*i)};
sin b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

precision 20;
% acos  
a:= {acos(1), acos(-1), acos(0)};
cos a;

a:= {acos(1+i), acos(-1-i), acos(1-i), acos(-1+i)};
cos a;
first a+second a;

a:= {acos(3+i), acos(-3-i), acos(3-i), acos(-3+i)};
cos a;
first a+second a;

a:= {acos(i), acos(i+epsilon), acos(i-epsilon)};
cos a;
b:= {acos(-i), acos(-i-epsilon), acos(-i+epsilon)};
cos b;
{first a+first b,second a+second b, third a+third b};

a:= {acos(4i), acos(4i+epsilon), acos(4i-epsilon)};
cos a;
b:= {acos(-4i), acos(-4i-epsilon), acos(-4i+epsilon)};
cos b;
{first a+first b,second a+second b, third a+third b};


% values on the real axis (includes the cut)

% two branch points
a:= {acos(1), acos(1+epsilon*i), acos(1-epsilon*i)};
cos a;
b:= {acos(-1), acos(-1-epsilon*i), acos(-1+epsilon*i)};
cos b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% not on the cut
a:= {acos(1/2), acos(1/2+epsilon*i), acos(1/2-epsilon*i)};
cos a;
b:= {acos(-1/2), acos(-1/2-epsilon*i), acos(-1/2+epsilon*i)};
cos b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% on the cut
a:= {acos(3/2), acos(3/2+epsilon*i), acos(3/2-epsilon*i)};
cos a;
b:= {acos(-3/2), acos(-3/2-epsilon*i), acos(-3/2+epsilon*i)};
cos b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

end;
