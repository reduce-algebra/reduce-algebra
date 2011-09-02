module defint;  % Special functions integrator package for REDUCE.

% Author:  Kerry Gaskell 1993/94.
%          Winfried Neun, Jan 1995 ...
%	   contribution from Victor Adamchik (WRI)

load_package limits,specfn2;

algebraic operator m_jacobip,m_gegenbauerp,m_laguerrep,m_hermitep,
		m_chebyshevu,m_chebyshevt,m_legendrep,
		struveh2,mycosh,mysinh;

global '(spec_cond unknown_tst product_tst transform_tst transform_lst);


create!-package ('(defint definta defintc defintf definti defint0
		defintd defintg defintj defintb definte 
		definth defintk defintx),
%               definth defintk),
		 '(contrib defint));

!#if (memq 'psl lispsystem!*)
  flag('(definta defintb definte defintf definti defintk),'lap);
!#endif

fluid '(MELLINCOEF);
SHARE MELLINCOEF$

endmodule;

end;



