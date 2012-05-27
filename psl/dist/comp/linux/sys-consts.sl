%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:SYS-CONSTS.SL
% Description:  HPUX PSL constants needed in the compiler
% Author:       Cris Perdue
% Created:      24-Feb-84
% Modified:     27-Jun-84 09:31:48
% Mode:         Lisp
% Package:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

(imports '(tags))

(fluid '(system_list*))

(setq system_list* '(Intel386 i386 sun386i unix ieee))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MACHINE DEPENDENT CONSTANTS FOR THE MC68000                           %
% Four BYTES per LONGWORD (32 bits).                                    %
% Four CHARACTERs per LONGWORD (32 bits).                               %
% Stack grows down, rather than UP, used to control Stack Scan loops.   %
% Items are placed on stack with -(SP)xx addressing  (predecrement).    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(define-constant faslin-magic  399)
(define-constant faslout-magic 399)


(define-constant tagstartingbit                 0) 
(define-constant tagbitlength                   5)
(define-constant infstartingbit                 5)
(define-constant infbitlength                   27) 
(define-constant addressingunitsperitem         4)
(define-constant charactersperword              4) 
(makeunbound 'bitsperword) % avoid ugly message in REDUCE
(define-constant bitsperword                    32)
(define-constant bitsperword2                   16)
(define-constant addressingunitsperfunctioncell 4) 
(define-constant stackdirection                 -1)


(define-constant maxargs     15)  
 
(define-constant maxrealregs     5)

% At present this is the single machine-dependent character
% (for ASCII machines).  Defined here in case cross-compilation
% is being done.  Defined for the kernel in php:scan-table.sl. /csp

(put 'eof 'charconst (char (control d)))


(define-constant maxtokensize          5000)
(define-constant bndstksize            2000)
(define-constant catchstacksize        400)
(define-constant hash-table-size       68023)
(define-constant savesize              4)
(define-constant maxargblock           15)
(define-constant stacksize             20000)
(define-constant maxsymbols            65000)
(define-constant compressedbinaryradix 16)
