%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:TIMC.SL
% Description:  Get run time in milliseconds.                              
% Author:       W. Neun, H. Melenk
% Created:      22-Dec-86
% Package:      
% RCS $Header: $
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Revisions:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load sys-macros))
(on fast-integers)

(declare-warray timebuffer size 6) %0:3 used for external_timc
                                   %  4 accumulated system time
                                   %  5 temporary value

% Get run-time in milliseconds. Left in for compatability
(de time () 
  (sys2int 
     (wdifference (timc) (wgetv timebuffer 4))
   ))

(de timc ()(external_timc))

(de &time-control(mode)
  % nil: start system time
  % t:   start user time
  % -1:  reset timing
  (cond ((eq mode -1) (setf (wgetv timebuffer 4) (timc)))
        (mode
            (setf (wgetv timebuffer 4)
                  (wplus2 (wgetv timebuffer 4)
                          (wdifference (timc) (wgetv timebuffer 5)) )))
        (t (setf (wgetv timebuffer 5) (timc)))
))


(off fast-integers)
