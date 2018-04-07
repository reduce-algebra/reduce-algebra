%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:ENVIRONMENT.SL 
% Description:  Hardware and Software Information Variables 
% Author:       Martin Griss 
% Created:      11-Apr-84 
% Modified:     12-Sep-84 11:56:34 (Brian Beach)
% Mode:         Lisp 
% Package:      
% Status:       Open Source: BSD License
% Compile to:   PL:ENVIRONMENT.B
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 16-Dec-85 08:30 (Brian Beach)
%  Changed COMPILE TO, and added comments.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% This file defined the macro (DEFINE-GLOBAL) which is used to define
% the global variables which describe the environment.
%
% The rest of the file contains examples of the environment variables which
% should be set up on a system--by-system basis.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% (Were functions in CommonLISP in case code migrates, or need to
% "compute" from present hardware, etc..)

% The following global variables should denote either a string or NIL.
% These variables are normally initialized upon startup
% possibly from a standard configuration file.

(defmacro define-global (variable value)
  `(progn (global '(,variable))
	  (setq ,variable ,value)))

% A short string indicating the location of the computer.

(commentoutcode
 (define-global *site-name* "HP/CRC")
 (define-global *site-name* "HP/FSD")
 )

% A longer string indicating the location of the computer.

(commentoutcode
 (define-global *long-site-name* "Hewlett-Packard Computer Research Center")
 (define-global *long-site-name* "Hewlett-Packard Ft. Collins Systems Division")
 )

% A string describing the currently running HPSL software.
%/CommonLISP used only for "supporting" software, eg TOPS-20
%/Provided *lisp-implementation-type*  for "HPSL" vs "PSL" vs "?"

(commentoutcode
 (define-global *software-type* "PSL Extended DEC-20 TOPS-20 5.0")
 (define-global *software-type* "PSL HP9000/200 PWS 2.1")
 (define-global *software-type* "PSL HP9000/200 HPUX 2.0")
 (define-global *software-type* "PSL DEC-20 TOPS-20 5.0")
 (define-global *software-type* "PSL Vax Unix 4.1aBSD")
 (define-global *software-type* "PSL Vax Unix 4.2BSD")
 (define-global *software-type* "HPSL Extended DEC-20 TOPS-20 5.0")
 (define-global *software-type* "HPSL HP9000/200 PWS 2.1")
 (define-global *software-type* "HPSL HP9000/200 HPUX 2.0")
 (define-global *software-type* "HPSL DEC-20 TOPS-20 5.0")
 (define-global *software-type* "HPSL Vax Unix 4.2BSD")
 )

% A string describing the version of the currently running HPSL software.
%/ Common LISP reserved only for supporting software (eg. "HP Ether-Hacked")
%/ used *lisp-implementation-version* for our "3.3 10-April-1984"

(commentoutcode
 (define-global *software-version* "3.3 01-May-1984")
 (define-global *software-version* "3.25 30-Apr-1984")
 (define-global *software-version* "1.0 04-July-1984")
 )

% A string describing the generic name of the hardware executing HPSL.

(commentoutcode
 (define-global *machine-type* "HP9000/200")
 (define-global *machine-type* "DEC-20")
 (define-global *machine-type* "Vax")
 )

% A string describing the model of the hardware executing HPSL.
%/ Also mention micro-code release etc.

(commentoutcode
 (define-global *machine-version* "Model 236")
 (define-global *machine-version* "Model 9920")
 (define-global *machine-version* "Model 2060")
 (define-global *machine-version* "Model 780")
 )

% A string describing the particular machine executing HPSL.

(commentoutcode
 (define-global *machine-instance* "HULK")
 (define-global *machine-instance* "THOR")
 (define-global *machine-instance* "mars")
 (define-global *machine-instance* "venus")
 (define-global *machine-instance* "mercury")
 (define-global *machine-instance* "saturn")
 (define-global *machine-instance* "apptech")
 (define-global *machine-instance* "hpfcla")
 (define-global *machine-instance* "Sam's Machine")
 (define-global *machine-instance* "")
 )
