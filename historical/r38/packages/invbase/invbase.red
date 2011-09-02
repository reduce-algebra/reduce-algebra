module invbase; % Computing involutive basis of polynomial system.

% Authors:  Alexey Yu. Zharkov, Yuri A. Blinkov
%           Saratov University, Astrakhanskaya 83, 
%           Saratov 410071, Russia
%           e-mail: postmaster@scnit.saratov.su

% Copyright A. Zharkov, Y. Blinkov;
%           all rights reserved.

% Minor fixes by John Fitch.

create!-package('(invbase invbint invbcomp),'(contrib invbase));

fluid '(CONDS GV HV BV NG GG VARLIST VJETS NC);            % globals
fluid '(ORDERING REDTAILS);                                % modes
fluid '(PATH TRED STARS);                                  % tracing
fluid '(REDUCTIONS NFORMS ZEROS MAXORD TITLE);             % statistics
fluid '(invsysvars!* !*trinvbase alfa beta shortway thirdway
         invtempbasis);

share invtempbasis;

ordering := 'grev;

switch trinvbase;

gv:=mkvect(1000)$  % p o l y n o m i a l s
bv:=mkvect(1000)$  % f l a g  (n e w  p r o l o n g a t i o n s)

endmodule;

end;
