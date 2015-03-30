% Examples for the conversion of reaction equations to ordinary
% differential equations.

% Example taken from Feinberg (Chemical Engineering):

   species := {a1,a2,a3,a4,a5};

   reac2ode {  a1 + a4 <> 2a1,       rho, beta,
               a1 + a2 <> a3,        gamma, epsilon,
               a3      <> a2 + a5,   theta, mue};
        
  inputmat;

  outputmat;

% Computation of the classical reaction matrix as difference
% of output and input matrix:

  reactmat := outputmat-inputmat;

% Example with automatic generation of rate constants and automatic
% extraction of species.
 
   species := {};
   reac2ode {  a1 + a4 <> 2a1, 
               a1 + a2 <> a3,
               a3      <> a2 + a5};
 
   on rounded;
   species := {};
   reac2ode {  a1 + a4 <> 2a1, 17.3* 22.4**1.5,
                               0.04* 22.4**1.5 };

end;
