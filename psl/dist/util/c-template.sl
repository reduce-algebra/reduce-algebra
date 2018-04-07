% 
% c-template.sl - A combination of backQuote and subLA.
% 
% Author:	Russell D. Fish
% 		Computer Science Dept.
% 		University of Utah
% Date:	        Mon Sep 13 1982
% Status:       Open Source: BSD License
%
% (c) Copyright 1982, University of Utah
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
% Modified: Tim Mueller
% Date: Mon Nov  3 11:19:44 1986
%   Converted to lisp syntax.

%
% codeTemplate - a utility for defining chunks of code, typically in the
% body of a macro which constructs functions, with optional substitution
% of parameters.  CodeTemplate is actually a frontend to the backQuote
% macro, in a form which is useful in Rlisp syntax.  Parameters are
% wrapped in unQuote or unQuoteL in the returned backQuote form.
%
% CodeTemplate takes a variable number of arguments, with the last one
% being the body of code to be returned.  All arguments but the last one
% are assumed to be specifications for parameters which will be
% subsituted into the code body.  A specification consists of a parameter
% id, possibly followed by a single expression argument to be substituted.
% If the expession argument is omitted, the id is used as the expression.
% 
% The expression will be substituted into the code body wherever the id is
% seen, as "unQuote expr".  Evalutation occurs in the environment which
% invoked codeTemplate.
% 
% If the id is prefixed with an "at" (@) in the code body, eg.  "!@foo",
% unQuoteL will be used instead of unQuote, resulting in removal of the top
% level of parens.  This is useful in cases such as splicing a set of
% arguments into the middle of a function call.
% 
(dm codetemplate (u) 
  (prog (arglist arg parms body) 
    (foreach arglist on (rest u) do     % Skip macro name at start of args.
	(cond ((not (rest arglist)) 
	       (setq body (first arglist)))
	      (t 	% Last arg is the code body.
	       (setq arg (first arglist))  % Id or list( Id, Expr ).
	       % Id is its own expr.
	       (cond ((idp arg) (setq arg (list arg arg))))
	       (cond ((not (idp (first arg))) 
		      (stderror (bldmsg "Non-Id parameter to CodeTemplate: %p" 
			  (first arg))))) 
	       (setq parms    % Accumulate parameter alist for substitution.
		(cons                   % foo
		    (cons (first arg) (list 'unquote (second arg)))
		(cons                   % !@foo
		    (cons (idconcat "@" (first arg))
			  (list 'unquotel (second arg)))
		    parms))))))

    (return (list 'backquote (subla parms body)))))


% idConcat - Make two-part names, where either part can be a string or an ID.
(de idconcat (i1 i2) 
(progn 
    (when (idp i1) (setq i1 (id2string i1)))
    (when (idp i2) (setq i2 (id2string i2)))
    (intern (concat i1 i2))))

% End of file.
