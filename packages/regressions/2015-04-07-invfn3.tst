on complex, rounded;
epsilon :=0.0001;

atanh(0);
a:= {atanh(1+i), atanh(-1-i), atanh(1-i), atanh(-1+i)};
tanh a;
first a+second a;
a:= {atanh(3+i), atanh(-3-i), atanh(3-i), atanh(-3+i)};
tanh a;
first a+second a;

% real axis (includeds the cut)
% two branch points (singularities)
a:= {atanh(1+epsilon*i), atanh(1-i*epsilon)};
tanh a;
b:= {atanh(-1-epsilon*i), atanh(-1+i*epsilon)};
tanh b;
{first a + first b, second a +second b};

% on the cut
a:= {atanh(4), atanh(4+epsilon*i), atanh(4-i*epsilon)};
tanh a;
b:= {atanh(-4), atanh(-4-epsilon*i), atanh(-4+i*epsilon)};
tanh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

a:= {atanh(2), atanh(2+epsilon*i), atanh(2-i*epsilon)};
tanh a;
b:= {atanh(-2), atanh(-2-epsilon*i), atanh(-2+i*epsilon)};
tanh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

% not on the cut
a:= {atanh(1/2), atanh(1/2+epsilon*i), atanh(1/2-i*epsilon)};
tanh a;
b:= {atanh(-1/2), atanh(-1/2-epsilon*i), atanh(-1/2+i*epsilon)};
tanh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

precision 20;
% imaginary axis

a:= {atanh(i), atanh(i+epsilon), atanh(i-epsilon)};
tanh a;
b:= {atanh(-i), atanh(-i-epsilon), atanh(-i+epsilon)};
tanh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {atanh(i/2), atanh(i/2+epsilon), atanh(i/2-epsilon)};
tanh a;
b:= {atanh(-i/2), atanh(-i/2-epsilon), atanh(-i/2+epsilon)};
tanh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {atanh(3i/2), atanh(3i/2+epsilon), atanh(3i/2-epsilon)};
tanh a;
b:= {atanh(-3i/2), atanh(-3i/2-epsilon), atanh(-3i/2+epsilon)};
tanh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {atanh(3i), atanh(3i+epsilon), atanh(3i-epsilon)};
tanh a;
b:= {atanh(-3i), atanh(-3i-epsilon), atanh(-3i+epsilon)};
tanh b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% acoth

a:= {acoth(1+i), acoth(-1-i), acoth(1-i), acoth(-1+i)};
coth a;
first a+second a;
a:= {acoth(3+i), acoth(-3-i), acoth(3-i), acoth(-3+i)};
coth a;
first a+second a;

% real axis (includeds the cut)
% two branch points (singularities)
a:= {acoth(1+epsilon*i), acoth(1-i*epsilon)};
coth a;
b:= {acoth(-1-epsilon*i), acoth(-1+i*epsilon)};
coth b;
{first a + first b, second a+second b};

% not on the cut
a:= {acoth(4), acoth(4+epsilon*i), acoth(4-i*epsilon)};
coth a;
b:= {acoth(-4), acoth(-4-epsilon*i), acoth(-4+i*epsilon)};
coth b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

a:= {acoth(2), acoth(2+epsilon*i), acoth(2-i*epsilon)};
coth a;
b:= {acoth(-2), acoth(-2-epsilon*i), acoth(-2+i*epsilon)};
coth b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

% on the cut
a:= {acoth(1/2), acoth(1/2+epsilon*i), acoth(1/2-i*epsilon)};
coth a;
b:= {acoth(-1/2), acoth(-1/2-epsilon*i), acoth(-1/2+i*epsilon)};
coth b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

precision 12;
% imaginary axis

a:= {acoth(i), acoth(i+epsilon), acoth(i-epsilon)};
coth a;
b:= {acoth(-i), acoth(-i-epsilon), acoth(-i+epsilon)};
coth b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {acoth(i/2), acoth(i/2+epsilon), acoth(i/2-epsilon)};
coth a;
b:= {acoth(-i/2), acoth(-i/2-epsilon), acoth(-i/2+epsilon)};
coth b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {acoth(3i/2), acoth(3i/2+epsilon), acoth(3i/2-epsilon)};
coth a;
b:= {acoth(-3i/2), acoth(-3i/2-epsilon), acoth(-3i/2+epsilon)};
coth b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {acoth(3i), acoth(3i+epsilon), acoth(3i-epsilon)};
coth a;
b:= {acoth(-3i), acoth(-3i-epsilon), acoth(-3i+epsilon)};
coth b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% neighbourhood of origin (discontinuous but odd)
a:= {acoth(epsilon), acoth(-epsilon)};
b:={ acoth(epsilon*i), acoth(-epsilon*i)};
{first a+second a, first b +second b};

a:={ acoth(epsilon+epsilon*i), acoth(-epsilon-epsilon*i)};
b:={ acoth(-epsilon + epsilon*i), acoth(epsilon-epsilon*i)};
{first a+second a, first b +second b};

{first a-second b, first b-second a};
 acoth 0;
off rounded;
acoth 0;   % acoth not flagged nonzero

on rounded;
precision 20;
% atan

atan(0);
a:= {atan(1+i), atan(-1-i), atan(1-i), atan(-1+i)};
tan a;
first a+second a;
a:= {atan(3+i), atan(-3-i), atan(3-i), atan(-3+i)};
tan a;
first a+second a;

% imaginary axis (includeds the cut)
% two branch points (singularities)
a:= {atan(i+epsilon), atan(i-epsilon)};
tan a;
b:= {atan(-i-epsilon), atan(-i+epsilon)};
tan b;
{first a +first b, second a+second b};

% on the cut
a:= {atan(3i), atan(3i+epsilon), atan(3i-epsilon)};
tan a;
b:= {atan(-3i), atan(-3i-epsilon), atan(-3i+epsilon)};
tan b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

a:= {atan(2i), atan(2i+epsilon), atan(2i-epsilon)};
tan a;
b:= {atan(-2i), atan(-2i-epsilon), atan(-2i+epsilon)};
tan b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

% not on the cut
a:= {atan(i/2), atan(i/2+epsilon), atan(i/2-epsilon)};
tan a;
b:= {atan(-i/2), atan(-i/2-epsilon), atan(-i/2+epsilon)};
tan b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

precision 12;
% real axis

a:= {atan(1), atan(1+epsilon*i), atan(1-epsilon*i)};
tan a;
b:= {atan(-1), atan(-1-epsilon*i), atan(-1+epsilon*i)};
tan b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {atan(1/2), atan(1/2+epsilon*i), atan(1/2-epsilon*i)};
tan a;
b:= {atan(-1/2), atan(-1/2-epsilon*i), atan(-1/2+epsilon*i)};
tan b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {atan(3), atan(3+epsilon*i), atan(3-epsilon*i)};
tan a;
b:= {atan(-3), atan(-3-epsilon*i), atan(-3+epsilon*i)};
tan b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

precision 20;
% acot
acot(0);
a:= {acot(1+i), acot(-1-i), acot(1-i), acot(-1+i)};
cot a;
first a+second a;
a:= {acot(3+i), acot(-3-i), acot(3-i), acot(-3+i)};
cot a;
first a+second a;

% imaginary axis (includeds the cut)
% two branch points (singularities)
a:= {acot(i+epsilon), acot(i-epsilon)};
cot a;
b:= {acot(-i-epsilon), acot(-i+epsilon)};
cot b;
{first a + first b, second a+second b};

% on the cut
a:= {acot(3i), acot(3i+epsilon), acot(3i-epsilon)};
cot a;
b:= {acot(-3i), acot(-3i-epsilon), acot(-3i+epsilon)};
cot b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

a:= {acot(2i), acot(2i+epsilon), acot(2i-epsilon)};
cot a;
b:= {acot(-2i), acot(-2i-epsilon), acot(-2i+epsilon)};
cot b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

% not on the cut
a:= {acot(i/2), acot(i/2+epsilon), acot(i/2-epsilon)};
cot a;
b:= {acot(-i/2), acot(-i/2-epsilon), acot(-i/2+epsilon)};
cot b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a -third a, first b-second b, first b -third b};

precision 12;
% real axis

a:= {acot(1), acot(1+epsilon*i), acot(1-epsilon*i)};
cot a;
b:= {acot(-1), acot(-1-epsilon*i), acot(-1+epsilon*i)};
cot b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {acot(1/2), acot(1/2+epsilon*i), acot(1/2-epsilon*i)};
cot a;
b:= {acot(-1/2), acot(-1/2-epsilon*i), acot(-1/2+epsilon*i)};
cot b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

a:= {acot(3), acot(3+epsilon*i), acot(3-epsilon*i)};
cot a;
b:= {acot(-3), acot(-3-epsilon*i), acot(-3+epsilon*i)};
cot b;
{first a+first b,second a+second b, third a+third b};
{first a-second a, first a-third a, first b-second b, first b-third b};

% neighbourhood of origin (continuous, but not odd)

a:= {acot(epsilon), acot(-epsilon)};
b:={ acot(epsilon*i), acot(-epsilon*i)};
{first a+second a, first b +second b};

a:={ acot(epsilon+epsilon*i), acot(-epsilon-epsilon*i)};
b:={ acot(-epsilon + epsilon*i), acot(epsilon-epsilon*i)};
{first a+second a, first b +second b};

{first a-second b, first b-second a};
acot 0;

end;
