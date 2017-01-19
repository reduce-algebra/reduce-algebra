%
% Version and Date:  Version 1.0, 1 September 2010.
%
% *****************************************************************
%
% Description: This is the package CDIFF. It is made of three main files:
% 1 - integrator.red, a package for the integration of overdetermined
%     systems of PDEs. It also includes software for solving large sparse
%     linear algebraic systems of equations;
% 2 - supervf.red, a package for defining vector fields on supermanifolds;
% 3 - tools21.red, a package of utilities to be used in 1 and 2.
%
% The original authors are P. Gragert, P. Kersten, M. Roelofs, G. Post,
% from the Twente University (The Netherlands). The main aim of the package
% was the symmetry analysis of (nonlinear) PDEs, and later the computation
% of integrability operators for (nonlinear) PDEs like Hamiltonian, symplectic
% and recursion operators.
%
% The current maintainer of the package is:
% Raffaele Vitolo
% Dipartimento di Matematica, Universita' del Salento (Lecce, Italy)
% email: raffaele.vitolo@unisalento.it
% web: http://poincare.unisalento.it/vitolo
%
% In this folder there are three separate user guides for the three main
% program files written by the authors.
% There is also a general user guide written by R. Vitolo on using CDIFF for
% computations of integrability operators; the userguide is accompanied by
% several example programs.
%
% NOTE (10/12/2014): R. Vitolo renamed one of the procedures in tools21.red
% due to a name clash with a procedure in the package CRACK. The old name of
% the procedure was get_kernels, the new name is cdiff_get_kernels.
% The documentation of tools21.red could not be modified because it is only
% available in pdf.
%
% NOTE (10/12/2014) R. Vitolo wrote extensions to CDIFF
% that automatize the generation of differential consequences of PDEs, the
% definition of total derivatives (possibly with differential constraints), the
% definition of Schouten brackets between local Hamiltonian operators. This is
% the content of a new package, called CDE, which is going to be included in
% the official Reduce distribution quite soon. At the moment it is distributed
% in the website dedicated to the Geometry of Differential Equations
% http://gdeq.org
%
% NOTE (19/01/2017) Changed the global undeclared variable 'graadlijst' into
% a fluid (and declared) variable all_graded_mon; added a useful procedure.
