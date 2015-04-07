on complex, rounded;
epsilon :=0.0001;

asinh(0);
% |z| <2
a:= {asinh(1+i), asinh(-1-i), asinh(1-i), asinh(-1+i)};
sinh a;
first a+second a;
% |z| > 2
a:= {asinh(3+i), asinh(-3-i), asinh(3-i), asinh(-3+i)};
sinh a;
first a+second a;

% |z| <2
a:= {asinh(1), asinh(1+epsilon*i), asinh(1-i*epsilon)};
sinh a;
b:= {asinh(-1), asinh(-1-epsilon*i), asinh(-1+i*epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};

% |z| >2
a:= {asinh(4), asinh(4+epsilon*i), asinh(4-i*epsilon)};
sinh a;
b:= {asinh(-4), asinh(-4-epsilon*i), asinh(-4+i*epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};

% |z| =2
a:= {asinh(2), asinh(2+epsilon*i), asinh(2-i*epsilon)};
sinh a;
b:= {asinh(-2), asinh(-2-epsilon*i), asinh(-2+i*epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};

% values on the imaginary axes (includes the cut)

% two branch points
a:= {asinh(i), asinh(i+epsilon), asinh(i-epsilon)};
sinh a;
b:= {asinh(-i), asinh(-i-epsilon), asinh(-i+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% not on the cut
a:= {asinh(i/2), asinh(i/2+epsilon), asinh(i/2-epsilon)};
sinh a;
b:= {asinh(-i/2), asinh(-i/2-epsilon), asinh(-i/2+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% on the cut |z| <2
a:= {asinh(3i/2), asinh(3i/2+epsilon), asinh(3i/2-epsilon)};
sinh a;
b:= {asinh(-3i/2), asinh(-3i/2-epsilon), asinh(-3i/2+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% on the cut  |z| >2
a:= {asinh(3i), asinh(3i+epsilon), asinh(3i-epsilon)};
sinh a;
b:= {asinh(-3i), asinh(-3i-epsilon), asinh(-3i+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% on the cut |z| =2
a:= {asinh(2i), asinh(2i+epsilon), asinh(2i-epsilon)};
sinh a;
b:= {asinh(-2i), asinh(-2i-epsilon), asinh(-2i+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};


precision 20;
% |z| <2
a:= {asinh(1+i), asinh(-1-i), asinh(1-i), asinh(-1+i)};
sinh a;
first a+second a;
% |z| > 2
a:= {asinh(3+i), asinh(-3-i), asinh(3-i), asinh(-3+i)};
sinh a;
first a+second a;

% |z| <2
a:= {asinh(1), asinh(1+epsilon*i), asinh(1-i*epsilon)};
sinh a;
b:= {asinh(-1), asinh(-1-epsilon*i), asinh(-1+i*epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};

% |z| >2
a:= {asinh(4), asinh(4+epsilon*i), asinh(4-i*epsilon)};
sinh a;
b:= {asinh(-4), asinh(-4-epsilon*i), asinh(-4+i*epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};

% |z| =2
a:= {asinh(2), asinh(2+epsilon*i), asinh(2-i*epsilon)};
sinh a;
b:= {asinh(-2), asinh(-2-epsilon*i), asinh(-2+i*epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};

% values on the imaginary axes (includes the cut)

% two branch points
a:= {asinh(i), asinh(i+epsilon), asinh(i-epsilon)};
sinh a;
b:= {asinh(-i), asinh(-i-epsilon), asinh(-i+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% not on the cut
a:= {asinh(i/2), asinh(i/2+epsilon), asinh(i/2-epsilon)};
sinh a;
b:= {asinh(-i/2), asinh(-i/2-epsilon), asinh(-i/2+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% on the cut |z| <2
a:= {asinh(3i/2), asinh(3i/2+epsilon), asinh(3i/2-epsilon)};
sinh a;
b:= {asinh(-3i/2), asinh(-3i/2-epsilon), asinh(-3i/2+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% on the cut  |z| >2
a:= {asinh(3i), asinh(3i+epsilon), asinh(3i-epsilon)};
sinh a;
b:= {asinh(-3i), asinh(-3i-epsilon), asinh(-3i+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% on the cut |z| =2
a:= {asinh(2i), asinh(2i+epsilon), asinh(2i-epsilon)};
sinh a;
b:= {asinh(-2i), asinh(-2i-epsilon), asinh(-2i+epsilon)};
sinh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

end;
