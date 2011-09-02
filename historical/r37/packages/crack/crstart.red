module crstart;  % CRACK Startup code

% Moved here from crack header module.
% FJW, 15 July 1998

% load_package ezgcd,odesolve,factor,int,algint$

% Do this load_package only at load time, not at compile time,
% otherwise Win32-PSL can run out of memory during compilation:
% apply1('load_package, '(ezgcd odesolve factor int algint))$

packages_to_load ezgcd,odesolve,factor,int,algint$ % only at load time

% The following procedure definition should not really be here, but it
% also should not be in crack.red, which flags setprop lose if
% necessary.  This flag must be set before the file defining setprop
% is compiled, so that the lose takes effect at compile time rather
% than load time!

% The following is defined in PSL but not CSL:

symbolic procedure setprop(U, L);
   %% Store item L as the property list of U.
   %% FJW: Defined (but NOT flagged lose) in PSL only.
   %% FJW: A crude implementation for CSL.
   %% Note that in CSL flags are properties with value t.
   << for each p in plist U do remprop(U, car p);
      for each p in L do put(U, car p, cdr p) >>$

setcrackflags()$

!*fullroots := t$                       % FJW: should all be local!
!*dfprint := t$
!*nopowers := t$                        % FJW
!*allowdfint := t$                      % FJW: moved here from crintfix

endmodule;

end$
