%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXU:NBIG30.SL 
% Description:  Vector based BIGNUM package with INUM operations 
% Author:       M. L. Griss & B Morrison 
% Created:      25 June 1982 
% Modified:	
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Experimental 
%
% (c) Copyright 1987, University of Utah, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(load muls vector-fix double nbig30a quotx30)% mbarith)

(de gcdn(u v)
%  U and v are integers. Value is absolute value of gcd of u and v.
   (if (eqn v 0) (abs u) 
     (gcdn v (remainder u v))))

