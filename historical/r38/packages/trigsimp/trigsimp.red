module trigsimp;  % User controlled simplification
                  % of trigonometric expressions.

% Authors: Wolfram Koepf, Andreas Bernig, Herbert Melenk
% Version 1.0 April 1995
% Bugfix Dependent arguments 6.6.96 Harald Boeing

% Revised by Francis J. Wright <F.J.Wright@Maths.QMW.ac.uk>

% Version 2.0, 29 June 1998

% My primariy motivation was for use with the ODESolve package.  I
% have not made any changes to the main algorithms, but I have
% re-implemented the code making greater use of symbolic mode, and I
% have made changes to some of the sub-algorithms.  The revised
% version runs the test file (which I have not changed) almost 25%
% faster in my tests, for which I used the CSL development system
% (under Windows 95).  I have also fixed a few minor bugs (one of
% which was visible in the test file).  I hope that the result is a
% little more robust and will be easier to maintain.

% I have changed the definitions of a number of internal procedures,
% and removed others.  Fewer internal procedures now have
% algebraic-mode interfaces.  TrigSimp appears not to be used in any
% other package, but until I am sure that my revisions are correct and
% do not upset any other packages I am preserving the previous version
% in files whose names begin with `o' (for old).

% Version 2.1, 17 January 1999

% Tidied the TrigSimp code.  Fixed bug in handling of trig arguments.
% Added option to specify additional trig arguments, which are treated
% as if they appeared as arguments in the trig expression to be
% simplified.  Added options tan and tanh, to convert output to these
% forms as far as possible; the remaining trig functions will be as
% specified by the other optional arguments.

% Revised trigfactorize to support the new factorizer interface.  It
% now respects the switch nopowers, and uses the power form
% internally, which should be more efficient.


!#if (memq 'psl lispsystem!*)
  flag('(trigsmp1),'lap);
!#endif

create!-package('(trigsimp trigsmp1 trigsmp2), nil);

endmodule;

end;
