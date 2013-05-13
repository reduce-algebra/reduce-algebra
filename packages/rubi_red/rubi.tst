load_package rubi_red;

on time;

lisp;

verbos 7;
on ezgcd, time;

enable!-errorset(3,3);

start_whole_test();

% I am putting the test cases so that slightly smaller sections are
% tried first.

%read_rubi_exponentials();

%read_rubi_logarithms();

%read_rubi_error_fresnel();

%read_rubi_integral();

%read_rubi_special();

%read_rubi_inverse_trig();

%read_rubi_inverse_hyperbolic();

%read_rubi_hyperbolic();

%read_rubi_trig();

% GOSH the integrations that work here often go through in a reasonable
% amount of time, but checking the results using the technology I have
% set up at present is TERRIBLE. I need to invent some heavier duty but
% much faster checking code!

start_test_section "Trig functions";
algebraic operator f;
%read_one_rubi_test "TrigFunctions/cos(x)^m (a+a cos(x))^n.m";
%read_one_rubi_test "TrigFunctions/cos(x)^m (a+b cos(x))^n.m";
%read_one_rubi_test "TrigFunctions/cos(x)^m (b cos(x))^n.m";
%read_one_rubi_test "TrigFunctions/CosecantFunctions.m";
%read_one_rubi_test "TrigFunctions/CosineFunctions.m";
%read_one_rubi_test "TrigFunctions/CotangentFunctions.m";
%read_one_rubi_test "TrigFunctions/csc(x)^m (a+a csc(x))^n.m";
%read_one_rubi_test "TrigFunctions/csc(x)^m (a+b csc(x))^n.m";
%read_one_rubi_test "TrigFunctions/sec(x)^m (a+a sec(x))^n.m";
%read_one_rubi_test "TrigFunctions/sec(x)^m (a+b sec(x))^n.m";
%read_one_rubi_test "TrigFunctions/sec(x)^m (b sec(x))^n.m";
%read_one_rubi_test "TrigFunctions/SecantFunctions.m";
%read_one_rubi_test "TrigFunctions/sin(x)^m (a+a sin(x))^n.m";
%read_one_rubi_test "TrigFunctions/sin(x)^m (a+b sin(x))^n.m";
%read_one_rubi_test "TrigFunctions/SineFunctions.m";
%read_one_rubi_test "TrigFunctions/TangentFunctions.m";
%read_one_rubi_test "TrigFunctions/TrigFunctions.m";
read_one_rubi_test "TrigFunctions/TwoTrigFunctions.m";
report_section();


% I try the algebraic and rational cases last since some of them cause
% Reduce severe problems such as apparently looping (or at least extremely
% lengthy) run-time.

read_rubi_algebraics();

read_rubi_rationals();

final_report();

end;
