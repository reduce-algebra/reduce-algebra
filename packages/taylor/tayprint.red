module tayprint;

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


%*****************************************************************
%
%     Functions for printing Taylor kernels
%
%*****************************************************************


exports taylor!*print, taylor!*print1;

imports

% from the REDUCE kernel:
        denr, eqcar, fmprint, kernp, lastpair, maprint, mvar, numr,
        prepsq, simp!*, smemq, typerr,

% from the header module:
        taycfsq, taycoefflist, tayorig, taytemplate, taytpelorder,
        taytpelpoint, taytpelvars,

% from module Tayconv:
        preptaylor!*, preptaylor!*1, taylor!-gen!-big!-o;


fluid '(!*fort !*nat !*taylorprintorder taylor!-truncation!-flag
        taylorprintterms);

symbolic procedure check!-print!-terms u;
  begin scalar x;
    x := simp!* u;
    if kernp x and mvar numr x eq 'all then return nil
     else if denr x = 1 and fixp numr x then return numr x
     else typerr (x, "value of TaylorPrintTerms")
  end;


symbolic procedure taylor!*print1 u;
  if smemq('!~,u) or atom taycoefflist u and not null taycoefflist u
    then 'taylor . cdr u
   else begin scalar taylor!-truncation!-flag, prepexpr, rest, nterms;
    nterms := if !*taylorprintorder
                then check!-print!-terms taylorprintterms
               else nil;
    prepexpr := preptaylor!*1 (
                  taycoefflist u,
                  taytemplate u,
                  nterms);
    if !*taylorprintorder then <<
      rest := {taylor!-gen!-big!-o taytemplate u};
      if taylor!-truncation!-flag then begin integer notprinted;
           notprinted := -nterms;
           for each pp in taycoefflist u do
             if not null numr taycfsq pp then
               notprinted := notprinted + 1;
           if notprinted=1 then rest := "(1 term)" . rest
            else rest := list2string ('!( .
                           nconc(explode notprinted,
                                 '(!  !t !e !r !m !s !)) )) . rest
        end
        %%%if prepexpr=0 and null cdr rest then return car rest
        >>
     else rest := {'!.!.!.};
    return if not eqcar (prepexpr, 'plus)
             then 'plus . (prepexpr or 0) . rest
            else nconc (prepexpr, rest)
  end;

COMMENT The following statement is the interface for the XReduce
        fancy printer;

put('taylor!*,'fancy!-reform,'taylor!*print1);


symbolic procedure taylor!*print(u,p);
  if !*fort then fmprint(preptaylor!* u,0)
   else if null !*nat then maprint(
                     'taylor .
                        (if tayorig u
                           then prepsq tayorig u
                          else preptaylor!* u) .
                        for each el in taytemplate u join
                          {if null cdr taytpelvars el
                             then car taytpelvars el
                            else 'list . taytpelvars el,
                           taytpelpoint el,
                           taytpelorder el},
                     p)
   else maprint(taylor!*print1 u,p);

put('taylor!*,'pprifn,'taylor!*print);


COMMENT We need another printing function for use with the
        TeX-REDUCE interface; %not yet done;


endmodule;

end;
