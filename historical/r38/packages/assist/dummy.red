module dummy; % Header Module for REDUCE versions from 3.5 to 3.7.

create!-package('(dummy perms backtrck dummycnt),'(contrib assist));

% % *****************************************************************
%
%            Author: A. Dresse
%
%          Revision: H. Caprasse
%
% All problems should be submitted to H. Caprasse:
%     hubert.caprasse@ulg.ac.be
%
% Version and Date:  Version 1.1, 15 January 1999.
%
% This package is built on top of ASSIST.RED version 2.31 which runs in
% REDUCE 3.6 and REDUCE 3.7. and is available inside the REDUCE library.
%
% Revision history to versions 1.1 :
% %   ****************************************************************
% 30/03/95 : reference to totalcopy eliminated and replaced by
% FULLCOPY
% 15/09/98 : NODUM_VARP and LIST_IS_ALL_FREE created
%          : DV_SKELPROD corrected and modified to allow extension 
%          : to tensor-like objects (!~dva introduced). 
%          : DUMMY_BASE and DUMMY_NAMES modified
%          : SHOW_DUMMY_NAMES to display dummy names has been created.
%          : Several local variables eliminated.
% 01/01/99 : DV_SKEL2FACTOR1 modified.
% % ****************************************************************** 


load_package assist;


symbolic procedure fullcopy s;
   % A subset of the PSL totalcopy function.
   if pairp s then fullcopy car s . fullcopy cdr s
    else if vectorp s then
        begin scalar cop; integer si;
        si:=upbv s;
        cop:=mkvect si;
        for i:=0:si do putv(cop,i,fullcopy getv(s,i));
        return cop end
    else s;

endmodule;

end;
