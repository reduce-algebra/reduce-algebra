module fps; 	% a package for the algorithmic calculation
		% of Formal Power Series

% Author : Wolfram Koepf, ZIB Berlin

% REDUCE version by: Winfried Neun, ZIB Berlin.
%     (September 1994)

%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     Please report bugs to Winfried Neun,                       %
%                           Konrad-Zuse-Zentrum                  %
%                              fuer Informationstechnik Berlin,  %
%                           Heilbronner Str. 10                  %
%                           10711 Berlin - Wilmersdorf           %
%                           Federal Republic of Germany          %
%     or by email, neun@sc.ZIB-Berlin.de                         %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %

create!-package ('(fps simplede substexp linrec hgrsolve constre
			ratalgo),
                 '(contrib specfn));

packages_to_load limits,factor,specfn,sfgamma;

fluid '(ps!:order!-limit);

lisp(ps!:order!-limit := 30);

algebraic << factor factorial >>;

endmodule;

end;


