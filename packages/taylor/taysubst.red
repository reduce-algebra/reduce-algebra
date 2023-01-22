module taysubst;

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

% $Id$

%*****************************************************************
%
%      Interface to the substitution functions
%
%*****************************************************************


exports subsubtaylor$

imports

% from the REDUCE kernel:
        addsq, denr, depends, exptsq, invsq, multsq, nlist, nth, numr,
	prepsq, replace!-nth!-nth, reval, reversip, simp!*, sort,
        subeval1, subs2!*, subsq, subtrsq, typerr,

% from the header module:
        make!-taylor!*, set!-taycfsq, taycfpl, taycfsq, taycoefflist,
        tayflags, taylor!:, taylor!-error, tayvars, taymakecoeff,
        tayorig, taytemplate, taytpelnext, taytpelorder, taytpelpoint,
        taytpelvars,

% from module Tayintro:
        constant!-sq!-p, delete!-nth, delete!-nth!-nth, replace!-nth,
        taylor!-error, taylor!-error!*, var!-is!-nth,

% from module Tayutils:
       enter!-sorted, rat!-kern!-pow;


fluid '(!*taylorkeeporiginal);

put ('taylor!*, 'subfunc, 'subsubtaylor);

symbolic procedure subsubtaylor(l,v);
  begin scalar x,clist,delete_list,tp,pl,!*mcd:=t;
    clist := for each u in taycoefflist v collect
               taymakecoeff(taycfpl u,subsq(taycfsq u,l));
    tp := taytemplate v;
    %
    % Substitute in expansion point
    %
    tp := for each quartet in tp collect
            {taytpelvars quartet,
             reval subeval1(l,taytpelpoint quartet),
             taytpelorder quartet,
             taytpelnext quartet};
    pl := for each quartet in tp collect
            nlist(nil,length taytpelvars quartet);
    %
    % Make x the list of substitutions of Taylor variables.
    %
    for each p in l do
      if car p member tayvars v
        %
        % The replacement of a Taylor variable must again be
        % a kernel.  If it is a constant, we have to delete it
        % from the list of Taylor variables.  Actually the main
        % problem is to distinguish kernels that are constant
        % expressions (e.g. sin (acos (4))) from others.
        %
        then begin scalar temp,w,about; integer pos,pos1;
         temp := simp!* cdr p;
         %
         % Determine the position of the variable
         %
         w := var!-is!-nth(tp,car p);
         pos := car w;
         pos1 := cdr w;
         about := taytpelpoint nth(tp,pos);
         if constant!-sq!-p temp or about = cdr p
          then begin scalar ll,y,z;
            if not null nth(nth(pl,pos),pos1)
              then taylor!-error('invalid!-subst,
                            "multiple substitution for same variable");
            pl := replace!-nth!-nth(pl,pos,pos1,0);
            %
            % Calculate the difference (new_variable - expansion_point)
            %
            if about eq 'infinity
              then if null numr temp
                then taylor!-error!*('zero!-denom,"Taylor Substitution")
               else temp := invsq temp
             else temp := subtrsq(temp,simp!* about);
            %
            % Adjust for already deleted
            %
            foreach pp in delete_list do
              if car pp < pos then pos := pos - 1;
            delete_list := (pos . pos1) . delete_list;
            %
            % Substitute in every coefficient
            %
            taylor!:
            for each cc in clist do begin scalar exponent;
              w := nth(taycfpl cc,pos);
              w := if null cdr w then delete!-nth(taycfpl cc,pos)
                    else delete!-nth!-nth(taycfpl cc,pos,pos1);
              exponent := nth(nth(taycfpl cc,pos),pos1);
              z := if exponent = 0 then taycfsq cc
                    else if exponent < 0 and null numr temp
                     then taylor!-error!*('zero!-denom,"Taylor Substitution")
                    else multsq(taycfsq cc,exptsq(temp,exponent));
              y := assoc(w,ll);
              if y then set!-taycfsq(y,subs2!* addsq(taycfsq y,z))
               else if not null numr (z := subs2!* z)
                then ll := taymakecoeff(w,z) . ll
             end;
            %
            % Delete zero coefficients
            %
            clist := nil;
            while ll do <<
              if not null numr taycfsq car ll
                then clist := enter!-sorted(car ll,clist);
              ll := cdr ll>>;
          end
         else if not (denr temp = 1 and
                      (temp := rat!-kern!-pow(numr temp,t)))
          then typerr({'replaceby,car p,cdr p},
                      "Taylor substitution")
         else begin scalar w,expo; integer pos,pos1;
           expo := cdr temp;
           temp := car temp;
           for each el in delete(car p,tayvars v) do
             if depends(temp,el)
               then taylor!-error('invalid!-subst,
                                  {"dependent variables",cdr p,el});
           if not (expo = 1) then <<
             w := var!-is!-nth(tp,car p);
             pos := car w;
             pos1 := cdr w;
             if not null nth(nth(pl,pos),pos1)
               then taylor!-error('invalid!-subst,
                            "different powers in homogeneous template");
             pl := replace!-nth!-nth(pl,pos,pos1,expo)>>;
           x := (car p . temp) . x
         end
        end;
   for each pp in sort(delete_list,function sortpred) do
      <<if null cdr taytpelvars u
          then <<tp := delete!-nth(tp,car pp);
                 pl := delete!-nth(pl,car pp)>>
         else <<tp := replace!-nth(tp,car pp,
                                   {delete!-nth(taytpelvars u,cdr pp),
                                    taytpelpoint u,
                                    taytpelorder u,
                                    taytpelnext u});
                pl := delete!-nth!-nth(pl,car pp,cdr pp)>>>>
          where u := nth(tp,car pp);
    if null tp
      then return if null clist then 0 else prepsq taycfsq car clist;
    x := reversip x;
    pl := check!-pl pl;
    if null pl then taylor!-error('invalid!-subst,
                            "different powers in homogeneous template");
    return if pl = nlist(1,length tp)
             then make!-taylor!*(clist,sublis(x,tp),
                        if !*taylorkeeporiginal and tayorig v
                          then subsq(tayorig v,l)
                         else nil,
                        tayflags v)
            else make!-taylor!*(change!-coefflist(clist,pl),
                        change!-tp(sublis(x,tp),pl),
                        if !*taylorkeeporiginal and tayorig v
                          then subsq(tayorig v,l)
                         else nil,
                        tayflags v)
  end;

symbolic procedure sortpred(u,v);
   car u > car v or car u = car v and cdr u > cdr v;

symbolic procedure check!-pl pl;
  taylor!:
   if null pl then nil
    else ((if n=0 then check!-pl cdr pl
            else if n and n<0 then nil
            else n . check!-pl cdr pl)
           where n := check!-pl0(car car pl,cdr car pl));

symbolic procedure check!-pl0(n,nl);
   if null nl then n else n=car nl and check!-pl0(n,cdr nl);

symbolic procedure change!-coefflist(cflist,pl);
   for each cf in cflist collect
     taymakecoeff(change!-pl(taycfpl cf,pl),taycfsq cf);

symbolic procedure change!-tp(tp,pl);
   if null tp then nil
    else (if null car pl then car tp
           else taylor!:{taytpelvars car tp,
                         taytpelpoint car tp,
                         taytpelorder car tp * car pl,
                         taytpelnext car tp * car pl})
        . cdr tp;

symbolic procedure change!-pl(pl,pl0);
  if null pl then nil
   else (if null car pl0 then car pl
          else for each n in car pl collect taylor!:(car pl0 * n))
        . change!-pl(cdr pl,cdr pl0);

endmodule;

end;
