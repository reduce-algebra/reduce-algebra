module dint;  % Definite integration support.

% Author: Anthony C. Hearn.

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

fluid '(!*hold!-int!* !*precise);

% If you go "on acn;" then definite integration will use a small stanza of
% experimental code (from A C Norman, hence the name of the switch) that
% uses simple indefinite integration to make a first attempt at any
% definite integration that has finite bounds.
  
switch acn;
off acn;

symbolic procedure simpdint u;
   begin scalar cflag,dmod,result,ceflg;!*combineexpt;
      if length u neq 4
        then rerror(int,2,"Improper number of arguments to INT");
      if dmode!*
        then << if (cflag:=get(dmode!*, 'cmpxfn))
                  then onoff('complex, nil);
                if (dmod := get(dmode!*,'dname))
                  then onoff(dmod,nil)
             >> where !*msg := nil;
%%% Replaced by autoload mechanism
%      load!-package 'defint;
      result := simpdint1 u;
      << if dmod then onoff(dmod,t);
         if cflag then onoff('complex,t)>> where !*msg := nil;
	 % If rounded or complex mode was switched off during integration,
	 %  resimplification of the result is needed after restoring the domain mode
	 % Set !*hold!-int!* to t to avoid infinite recursion when integration
	 %  had failed.
	 if dmod or cflag then result := resimp result where !*hold!-int!* := t;
      	 return result;
   end;


symbolic procedure simpdint1 u;
   begin scalar low,upp,fn,var,x,y,result;
      fn := car u;
      var := cadr u;
      low := caddr u;
      upp := cadddr u;
      low := reval low;
      upp := reval upp;
      % Now I will have really simple code that tries to deal with cases that are
% easily solve using indefinite integration. At this stage I am not going to
% worry about branch cuts!
      if low neq 'infinity and low neq '(minus infinity) and
         upp neq 'infinity and upp neq '(minus infinity) and
         idp var and !*acn then <<
        result := simpint list(fn, var);
        if not smemq('int, result) then << % Has the integration completed OK
          x := subsq(result, list (var . low));
          y := subsq(result, list (var . upp));
          return addsq(negsq x, y) >> >>;
% End of hack to try direct integration
      if low = upp then return nil ./ 1
       else if null getd 'new_defint then nil
       else if upp = 'infinity
        then if low = 0
               then if not smemql('(infinity unknown fail),
                                  x := defint!* {fn,var})
                      then return simp!* x else nil
              else if low = '(minus infinity)
               then return mkinfint(fn,var)
              else if freeof(var,low)
               then if not smemql('(infinity unknown fail),
                                  x := defint!* {fn,var})
                     and not smemql('(infinity unknown fail),
                                  y := indefint!* {fn,var,low})
                      then return simp!* {'difference,x,y} else nil
              else nil
       else if upp = '(minus infinity) or low = 'infinity
        then return negsq simpdint {fn,var,upp,low}
       else if low = '(minus infinity)
        then return
           simpdint{prepsq simp{'sub,{'equal,var,{'minus,var}},fn},
                     var,{'minus,upp},'infinity}
       else if low = 0
        then if freeof(var,upp)
                and not smemql('(infinity unknown fail),
                               x := indefint!* {fn,var,upp})
               then return simp!* x else nil
       else if freeof(var,upp) and freeof(var,low)
                 and not smemql('(infinity unknown fail),
                               x := indefint!* {fn,var,upp})
                 and not smemql('(infinity unknown fail),
                               y := indefint!* {fn,var,low})
        then return simp!* {'difference,x,y};
      result := mkdint(fn,var,low,upp);
      return result;
   end;

symbolic procedure defint!* u;
   (if errorp x then 'unknown else car x)
    where x = errorset2 {'new_defint,mkquote u};

symbolic procedure indefint!* u;
   (if errorp x or smemq('indefint2,car x) then 'unknown else car x)
    where x = errorset2 {'new_indefint,mkquote u};

symbolic procedure mkdint(fn,var,low,upp);
   % This could be used as an entry point to other dint procedures.
   % Should we handle infinity, - infinity differently?
   begin scalar x,!*precise;
      if getd 'defint0
         and not((x := defint0 {fn,var,low,upp}) eq 'failed)
        then return simp x
       else if not smemq('infinity,low) and not smemq('infinity,upp)
        then <<x := prepsq!* simpint {fn,var};
               if not eqcar(x,'int)
                 then return simp!* {'difference,
                                     subeval {{'equal,var,upp},x},
                                     subeval {{'equal,var,low},x}}>>;
      return mksq({'int,fn,var,low,upp},1)
   end;

symbolic procedure mkinfint(fn,var);
   begin scalar x,y;
      if getd 'defint0
         and not((x := defint0 {fn,var,'(minus infinity),'infinity})
                 eq 'failed) then return simp x;
      x := simpdint {fn,var,0,'infinity};
      y := simpdint {fn,var,'(minus infinity),0};
      if kernp x and eqcar(mvar numr x,'int)
         and kernp y and eqcar(mvar numr y,'int)
        then return mkdint(fn,var,'(minus infinity),'infinity)
       else return addsq(x,y)
   end;

endmodule;

end;
