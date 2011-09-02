module odesolve;      % Top level ordinary differential equation solver.

comment on this package:

 a) Title: ODESOLVE

 b) Main Author: Malcolm MacCallum
     [Prof. M.A.H. MacCallum, School of Mathematical Sciences, Queen
     Mary and Westfield College, University of London,  Mile End Road,
     LONDON E1 4NS, U.K.
     E-mail: on JANET (U.K. national network)  mm@uk.ac.qmw.maths
             (Arpa/Internet form: mm@maths.qmw.ac.uk) 
             Relays: ARPA: nsfnet-relay.ac.uk
                     EARN/BITNET: UKACRL
                     uucp/Usenet: ....!mcsun!ukc!maths.qmw.ac.uk!mm
     Telex: 893750 QMCUOL G
     Fax: +44 81 981 9587
     Tel: +44 71 975 5445 or 975 5555 extension 5445]
    Other authors: Alan Barnes, Department of Computer Science,
     University of Aston, Aston triangle, Birmingham, U.K.
      Francis Wright: address as for Malcolm MacCallum

 c) Date: November 1990

 d) Abstract: This is a solver for simple ordinary differential
    equations. The present version solves some well-known simple
    types of first-order equations and higher order linear equations
    with constant coefficients and Euler equations: a full list
    is in the accompanying documentation file. Very much more
    extensive and sophisticated versions are planned.

 e) REDUCE version required: 3.4.

 f) Relevant publications: M.A.H. MacCallum, `An ordinary differential
     solver for REDUCE', Lecture Notes in Computer Science, vol.
     358 [Symbolic and algebraic computation (International symposium
     ISSAC '88], ed. P. Gianni, Springer-Verlag, Berlin and Heidelberg
     pp. 196-205 (1989).

 g) Appropriate keywords: Ordinary differential equations

 This is the source code file odesolve.red. There are also files
 of documentation, test examples and a log of a run of the test
 with extensions .doc .tst and .log;

% If you are not compiling using a module system, comment out all
% 'module' and 'endmodule' statements

% This package has modules odesolve, ode1, testdf, linearn and lccode
% at present. Note that testdf ends with extensions or variations on
% REDUCE functions which may not be required in all implementations or
% REDUCE versions

create!-package('(odesolve ode1 testdf linearn lccode),'(solve));

% Note the following become reserved identifiers used as if they were
% global variables (and there are also the function names of course)
% In a later version this will be redone in functional programming style
%
% odeorder, odedegree, odelinearity, highestderiv, in testdf
% odecoeffs, !!arbconst, arbconst                  in ode1 and linearn
% numfacs!*, denfacs!*, numfactors, denfactors     in ode1
% wronskian (a matrix)                             in lccode
% and the reserved variables associated with solve and coeff will
% be reset by certain of the routines
 
% Note that no attempt is made to extend the integrator i.e. to solve
% in any improved way the problems discussed by Davenport et al. It
% should extend this solver's capabilities if the Reduce 3.3 algint
% module is used.

% Changes history
% Jan 1990  Enabled input in the form of an equation
%           Changed output format to list of equation (in future,
%              equations?) (calling solve on these was abandoned as it
%              fails in nasty ways)
%           Added trode switch and message function.
%           Altered messages. Removed typing errors. Removed
%              setoperator.
%           Put in check for the factorizer bug (factorize(1) -> {})
%           Declared arbconst algebraic. Changed method of finding
%              argument.
%           Made sortoutode return ode.
%           Removed an argument from lccode
%           
% Planned changes
%           Rewrite in more functional style and remove use of global
%              variables
%           Add extra algorithms (see in the individual module headers)
%           Convert more from algebraic to symbolic mode
%           Other possible changes marked by lines starting % ***

% Tracing switch and function

fluid '(!*evallhseqp !*precise);

fluid '(!*trode);

switch trode;

% The following two statements are needed in case SOLVE has not been
% loaded before compiling this package.

global '(multiplicities!*);

flag('(multiplicities!*),'share);

symbolic operator traceode;
symbolic procedure traceode u;
 if !*trode then write u;

% The arbitrary constants in solutions
algebraic operator arbconst;
algebraic (!!arbconst := 0);

algebraic procedure newarbconst();
 <<!!arbconst := !!arbconst +1;
   arbconst(!!arbconst)>>;

% The entry point function
% The procedures called are defined in the appropriate following modules
algebraic procedure odesolve(ode, y, x);
 begin scalar var1,!*evallhseqp,!*precise;
  symbolic(!*evallhseqp := t);          % Since we wish to evaluation
					% LHS of equations.
  var1 := sortoutode(ode, y, x);        % returns ode as an expression
  if odeorder > 1 and odelinearity neq 1 then return odefailure(var1);
  return if odelinearity = 1
               then <<if odeorder = 1 then linear1(var1, y, x)
                                      else linearn(var1,y,x) >>
               else if odeorder = 1 then odesolve1(var1, y, x);
% *** Add entry points for extra methods here
 end;

algebraic procedure odefailure(ode);
 <<traceode
    "This version of ODESOLVE cannot solve equations of the type given";
   {ode=0}>>;

endmodule;              % odesolve

end;
