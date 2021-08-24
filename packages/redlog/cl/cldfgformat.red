module cldfgformat;

revision('cldfgformat, "$Id$");

copyright('cldfgformat, "(c) 2021 T. Sturm");

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

rl_provideService rl_dfgprint = cl_dfgPrint using rl_dfgPrintAt, rl_dfgPrintV;

procedure cl_dfgPrint(f, fname);
   % Prefix print.
   <<
      if fname neq "" then
         out fname;
      prin2 "formula(";
      cl_dfgPrint1 f;
      prin2 ")";
      terpri();
      if fname neq "" then
         shut fname
   >>;

procedure cl_dfgPrint1(f);
   % Prefix print.
   begin scalar ql, vll, vl;
      {ql, vll, f, vl} := cl_split f;
      ql := reverse ql;
      vll := reverse vll;
      for each q in ql do <<
         vl := reverse pop vll;
         prin2 if q eq 'ex then "exists" else "forall";
         prin2 "(";
         cl_dfgPrintVl vl;
         prin2 ", "
      >>;
      cl_dfgPrintQff f;
      for each q in ql do
         prin2 ")"
   end;

procedure cl_dfgPrintVl(vl);
   <<
      prin2 "[";
      for each rvl on vl do <<
         rl_dfgPrintV car rvl;
         if cdr rvl then prin2  ", "
      >>;
      prin2 "]"
   >>;

procedure cl_dfgPrintQff(f);
   begin scalar op, l, r;
      op := rl_op f;
      if op eq 'impl then
         cl_dfgPrintQff rl_mk2('or, rl_mk1('not, rl_arg2l f), rl_arg2r f)
      else if op eq 'repl then
         cl_dfgPrintQff rl_mk2('or, rl_arg2l f, rl_mk1('not, rl_arg2r f))
      else if op eq 'equiv then <<
         l := rl_arg2l f;
         r := rl_arg2r f;
         cl_dfgPrint1 rl_mkn('and, {rl_mk2('impl, l, r), rl_mk2('repl, l, r)})
      >> else if op eq 'not then <<
         prin2 "not";
         prin2 "(";
         cl_dfgPrint1 rl_arg1 f;
         prin2 ")"
      >> else if rl_tvalp op then
         prin2 f
      else if rl_junctp op then
         cl_dfgPrintJ(op, rl_argn f)
      else  % atomic formula
         rl_dfgPrintAt f
   end;

procedure cl_dfgPrintJ(op, argl);
   if not cdr argl then
      cl_dfgPrint1 car argl
   else <<
      prin2 op;
      prin2 "(";
      for each rargl on argl do <<
         cl_dfgPrint1 car rargl;
         if cdr rargl then
            prin2 ", "
      >>;
      prin2 ")"
   >>;

procedure cl_dfgPrintJ2(op, argl);
   if not cdr argl then
      cl_dfgPrint1 car argl
   else <<
      prin2 op;
      prin2 "(";
      cl_dfgPrint1 car argl;
      prin2 ", ";
      cl_dfgPrintJ(op, cdr argl);
      prin2 ")"
   >>;

endmodule;

end;
