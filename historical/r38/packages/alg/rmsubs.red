module rmsubs;   % Remove system wide standard quotient substitutions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(alglist!*);

global '(!*sqvar!*);

% Contains RPLACA update of *SQVAR*.

!*sqvar!*:= list 't;    %variable used by *SQ expressions to control
                        %resimplification;

symbolic procedure rmsubs;
   begin
        rplaca(!*sqvar!*,nil); !*sqvar!* := list t;
%       while kprops!* do
%          <<remprop(car kprops!*,'klist); %kprops!* := cdr kprops!*>>;
%       exlist!* := list '(!*);
        %This is too dangerous: someone else may have constructed a
        %standard form;
        alglist!* := nil . nil
   end;

endmodule;

end;
