module conlaw;  % Conservation laws using CRACK

% This header file by FJW, 28 July 1998

create!-package('(conlaw conlaw0 conlaw1 conlaw2 conlaw3 conlaw4),nil);

% FJW: Load support packages, but not when compiling:
!#if (getd 'packages_to_load)
packages_to_load crack;
!#else                                  % for REDUCE 3.6
apply1('load!-package, 'crack);
!#endif

endmodule;

end;


