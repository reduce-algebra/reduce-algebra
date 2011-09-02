module comment;   % Routines for handling active comments.

% Author:  Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

% This module supports the concept of active comments. Such comments are
% delimited by the comment brackets /* and */.  Everything read between
% those brackets is converted to a string (including eol), and the
% expression returned as the list (*comment* <comment string>).

symbolic procedure read!-comment;
   begin scalar ollength,raise,x,y,z;
      raise := !*raise;
      !*raise := nil;
      ollength := linelength 150;
      z := list(crchar!*,'!");
   a: if (x := readch()) eq '!*
	then if (y := readch()) eq '!/ then go to b
	      else z := y . x . z
       else if x = !$eof!$
	then <<!*raise := raise; rederr "EOF encountered in comment">>
       else z := x . z;
      go to a;
   b:
      !*raise := raise;
      crchar!* := readch();
      z := '!" . z;
      z := list('!*comment!*,mkstrng compress reversip z);
      linelength ollength;
      return z
   end;

newtok '((!/ !*) !*comment!*);

endmodule;

end;
