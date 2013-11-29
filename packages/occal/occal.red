module occal;

% Author: Rainer Schöpf 

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


create!-package('(occal
%                  oczusatz
%		  ocvars
%		  ocparse
%                  ocread
%		  ocdispl
%		  assume
%		  ocstruct
%		  ocinterf
%		  ocpriprg
		  ),
		'nil);

load_package matrix;
load_package gentran;

symbolic smacro procedure tracewrite x;
  if !*oc_trace then write x;

symbolic smacro procedure tracenewline();
  if !*oc_trace then terpri();

symbolic smacro procedure tracewritenl x;
  if !*oc_trace then <<write x; terpri()>>;

symbolic smacro procedure tracepri(x,y);
  if !*oc_trace then writepri(x,y);

symbolic smacro procedure tracemathpri x;
  if !*oc_trace then mathprint x;

symbolic procedure strconcat(a,b);
   <<a := reversip cdr reversip explode a;
     b := cdr explode b;
     compress nconc(a,b)>>;

symbolic procedure occal u;
   begin scalar rname;
     rname := strconcat(u,".red");
%     out rname;
     process_file(strconcat(u,".dsc"),rname);
%     shut rname;
     clear_oc_variables();
     infile rname;
     do_calculation();
     showtime;
   end;


flag('(occal),'opfn);

endmodule;

end;
