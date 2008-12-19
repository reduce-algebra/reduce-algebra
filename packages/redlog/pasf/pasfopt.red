% ----------------------------------------------------------------------
% $Id: pasfopt.red,v 1.7 2005/07/17 16:44:32 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2002 A. Dolzmann, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
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

% $Log: pasfopt.red,v $
% Revision 1.7  2005/07/17 16:44:32  lasaruk
% Comments rewritten
%
% Revision 1.6  2005/04/29 12:17:16  lasaruk
% Debugging code removed
%
% Revision 1.5  2005/03/17 16:58:45  lasaruk
% Code structure changed
%
% Revision 1.4  2005/02/24 15:20:03  lasaruk
% QE code completely rewritten using a correct representant choice
%
% Revision 1.3  2005/01/24 16:02:08  lasaruk
% Uniform Presburger Arithmetic is now implemented. Elimination code rewritten,
% so no elimination normal form is explicitly computed.
%
% Revision 1.2  2005/01/20 23:19:59  lasaruk
% Partial elimination sets improoved. Linear optimization rewritten with
% single QE call, minimal value search and bound value reconstruction.
% Care for bounded quantifiers in gauss elimination and condensing added.
%
% Revision 1.1  2005/01/17 22:17:00  lasaruk
% Linear optimization added. For now withot parameters.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(pasf_opt_rcsid!* pasf_opt_copyright!*);
   pasf_misc_rcsid!* := "$Id: pasfopt.red,v 1.7 2005/07/17 16:44:32 lasaruk Exp $";
   pasf_misc_copyright!* :=
      "Copyright (c) 1995-2002 by A. Dolzmann, A. Seidl, and T. Sturm"
>>;


module pasfopf;
% Presburger arithmetic standard form optimization. This module was introduced
% by lasaruk to experiment with linear optimization.

procedure pasf_opt(cl,targ,parml,nproc);
   % Presburger arithmetic standard form linear optimization. [cl] is a list
   % of constraints; [targ] is the cost function; [paraml] is the list of
   % parameters; [nproc] is NOT COMMENTED. Returns optimal solutions of the
   % problem if any exist.
   rederr {"Linear optimization not yet implemented in context PASF"};

endmodule; % pasfopt

end; % of file