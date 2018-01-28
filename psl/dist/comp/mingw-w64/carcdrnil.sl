%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         carcdrnil.sl
% SCCS:         %A% %G% %U%
% Description:  Patches to make car and cdr of nil be nil.
% Author:       Robert R. Kessler, University of Utah
% Created:      3-Apr-86
% Modified:     
% Status:       Open Source: BSD License
% Package:      PSL
%
% (c) Copyright 1986, University of Utah
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% This file portably fixes car and cdr of nil to be nil.  It should
% only be used when the target machine doesn't have a nice tricky way
% of handling car and cdr of nil (because this is expensive).  On the
% 68000's for example, it costs an additional 10 bytes for every car
% and cdr that is included (which is about an additional 75% in space).
% The time costs are very hard to measure, but probably are similar to
% the space costs.

% What we do is declare two fluid variables that as soon as the system
% sees them will allocate two new symbol table slots.  We initialize
% them to be nil.  They will be allocated sequentially, so, using the
% first one as the address, when the car to access them, it will
% get the value of the first and cdr will retrieve the value of the
% second.  This all pretty sleazy and is highly dependent on the
% underlying system.  For those of you who write code that doesn't
% rely on car and cdr of nil being nil, then you can use the fastcar
% flag.  The default of which is nil, which means it will do the check
% for nil.  When turned on, the system will revert back and generate
% the code as before.  So, if you want to use the car and cdr of nil
% style, then you must pay for it.

% The first two is where the car and cdr actually grab the values.
% The second is the flag to control if we check or not.

(fluid '(***MUST-BE-NIL*** ***MUST-BE-NIL-TOO*** *fastcar))

% Initialize each of the variables to nil.  The first two must not be
% changed (EVER!!).
(setf ***MUST-BE-NIL*** NIL)
(setf ***MUST-BE-NIL-TOO*** NIL)
(setf *fastcar nil)

% This little function is a way of testing to see if the *fastcar flag
% has been set or not.  Since I don't know of a way to put conditional
% code into the test part of the anyreg definition, this works
% reasonably well.
(de !&fastcar (u)
  *fastcar)

% Here are the anyregs.  There could be some optimization by checking
% for the argument type, except it might only save one instruction.
% Its all kind of a mess, since the field operation has to occur in a
% D register and the indexing has to occur in an A register.  The nil
% register is actually a D register, but comparisons work across
% register types.
(DefAnyreg CAR
           AnyregCAR   %Grab the source so caller can displace off it.
	   ((!&fastcar)
	    (!*Field REGISTER SOURCE InfStartingBit InfBitLength)
	    (Indirect REGISTER))
           ((!*MOVE SOURCE REGISTER)       
	    (!*JUMPNOTEQ (labelgen CAR) (quote nil) REGISTER)
	    (!*LOC REGISTER ($FLUID ***MUST-BE-NIL***))
	    (labelref CAR)
	    (!*Field REGISTER REGISTER InfStartingBit InfBitLength)
	    (Indirect REGISTER))
)

% Same as CAR, except move to next word in pair.
(DefAnyreg CDR
           AnyregCDR
	   ((!&fastcar)
	    (!*Field REGISTER SOURCE InfStartingBit InfBitLength)
	    (Displacement REGISTER 4))
           ((!*MOVE SOURCE REGISTER)       
	    (!*JUMPNOTEQ (labelgen CDR) (quote nil) REGISTER)
	    (!*LOC REGISTER ($FLUID ***MUST-BE-NIL***))
	    (labelref CDR)
	    (!*Field REGISTER REGISTER InfStartingBit InfBitLength)
	    (Displacement REGISTER 8))
)



