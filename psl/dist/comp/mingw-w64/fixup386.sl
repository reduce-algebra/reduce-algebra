%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:FIXUP.SL
% Description:  
% Author:       Jim Ambras/CRC
% Created:      27-Mar-84
% Modified:     11-May-84 07:38:38 (Brian Beach)
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 27-Mar-84 13:51:45 (Jim Ambras/CRC)
%  Added compiletime load of sys-consts.
% 02-Mar-84 09:19:47 (Jim Ambras/CRC)                                      
%  Corrected file header.                                                  
% 13-Dec-83 09:31:39 (Tim Tillson)                                         
%  D-register model version. Added header.                                 
%                                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
%%%%%%%
%%%%%% Fuer Cross LAP geklaut von /keller/cons/psl/dist/nonkernel/sun/fixup.sl
%%%%%%%

(compiletime (load sys-consts))

(commentoutcode %%%% das stoert hier

(off r2i) %avoid infinite recursion


(de getbyte (m o)
  (getbyte m o))

(de byte (m o)
  (getbyte m o))

(de putbyte (m o v)
  (putbyte m o v))

(de gethalfword (m o)
  (gethalfword m o))

(de halfword (m o)
  (gethalfword m o))

(de puthalfword (m o v)
  (puthalfword m o v))

(on r2i)
)

(de bittable (a b)
  (getbittable a b)
  )

% Fixups for the HP-Lap.red relocation                                     

(de makerelocword (reloctag relocinf)
  (iplus2 (ilsh reloctag 30) (field relocinf 2 30)))

(de makerelocinf (reloctag relocinf)
  (iplus2 (ilsh reloctag 22) (field relocinf 10 22)))

(de makerelochalfword (reloctag relocinf)
  (iplus2 (ilsh reloctag 14) (field relocinf 18 14)))

(de getbittable (baseaddress bitoffset)
  (field (ilsh (byte baseaddress (ilsh bitoffset -2)) 
               (idifference (itimes2 (field bitoffset 30 2) 2) 6))
         30 2))

(de putbittable (baseaddress bitoffset value2)
  (prog (m b c)
        (setq b 
              (iland (byte baseaddress (setq m (ilsh bitoffset -2))) 
                     (ilsh (idifference -1 (itimes2 3 256)) 
                      (idifference -2 
                       (setq c (itimes2 (field bitoffset 30 2) 2))))))
        (putbyte baseaddress m (if (eq value2 0)
                   b
                   (ilor b (ilsh value2 (idifference 6 c)))))))

