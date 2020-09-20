module rljson;

revision('rljson, "$Id$");

copyright('rljson, "(c) 2019-2020 T. Sturm");

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

% Dump documentation of rl_services to json for use on www.redlog.eu.

procedure rl_services2json(file);
   begin scalar l, w, ll;
      l := for each s in sort(rl_services!*, 'ordp) join <<
	 w := get(s, 'rl_amservice);
      	 if w then
	    {get(w, 'json) or ('domain . "generic") . ('name . lto_at2str w) . rl_helpMkDocal(w, nil)}
      >>;
      ll := linelength 4096;
      if file then out file;
      rl_services2jsonPrintList(l, 0);
      if file then shut file;
      linelength ll
   end;

procedure rl_builtins2json(file);
   begin scalar l, w, ll;
      l := for each s in sort(rl_builtins!*, 'ordp) join
	 {('domain . "generic") . ('name . lto_at2str s) . rl_helpMkDocalBuiltin(s, nil)};
      ll := linelength 4096;
      if file then out file;
      rl_services2jsonPrintList(l, 0);
      if file then shut file;
      linelength ll
   end;

procedure rl_types2json(file);
   begin scalar types, bl, cl, kwl, l, ll;
      for each s in rl_typeStrings rl_services!* do <<
	 {bl, cl, kwl} := rl_helpOverviewTypesDecompose s;
	 types := union(union(types, bl), cl)
      >>;
      l := for each s in sort(types, 'ordp) join
	 {('name . s) . rl_helpMkDocalType(lto_downcase lto_string2id s, nil)};
      ll := linelength 4096;
      if file then out file;
      rl_services2jsonPrintList(l, 0);
      if file then shut file;
      linelength ll
   end;

procedure rl_services2jsonPrintList(l, indent);
   % Print a List as a json list. The entries are Alists to be printed as json
   % records.
   begin scalar first;
      first := t; for each s in l do <<
	 if first then <<
      	    ioto_prin2t "[";
      	    indent := indent + 2;
	    first := nil
	 >> else
	    ioto_prin2t ",";
	 for i := 1:indent do ioto_prin2 " ";
	 if stringp s then
 	    prin s
	 else
	    rl_services2jsonPrint(s, indent)
      >>;
      ioto_cterpri();
      indent := indent - 2;
      for i := 1:indent do ioto_prin2 " ";
      ioto_prin2 "]"
   end;

procedure rl_services2jsonPrint(x, indent);
   begin scalar l, ll;
      if not x then
      	 return ioto_prin2 "{}";
      if idp x or numberp x then
      	 return ioto_prin2 {"""", lto_at2str x, """"};
      if stringp x then <<
      	 l := cdr reversip cdr explode x;
	 ll := {'!"};
      	 while l do <<
	    c := pop l;
	    if c eq '!" and l and car l eq '!" then <<
	       push(c, ll);
	       push(pop l, ll);
	       push('!\, ll)
	    >> else
	       push(c, ll);
      	 >>;
	 ll := '!" . ll;
	 return ioto_prin2 {"""", compress ll, """"}
      >>;
      if alistp x then
      	 return rl_services2jsonPrintRecord(x, indent);
      if listp x then
      	 return rl_services2jsonPrintList(x, indent);
      rederr {"rl_services2jsonPrint: bad argument", x}
   end;

procedure rl_services2jsonPrintRecord(al, indent);
   % Print an Alist as a json record. The keys are expected to be atoms, the
   % entries are Strings, Lists, or Alists.
   begin scalar first;
      first := t; for each pr in al do <<
	 if first then <<
      	    ioto_prin2t "{";
      	    indent := indent + 2;
	    first := nil
	 >> else
	    ioto_prin2t ",";
	 for i := 1:indent do ioto_prin2 " ";
	 rl_services2jsonPrint(car pr, indent);
	 ioto_prin2 ": ";
	 rl_services2jsonPrint(cdr pr, indent)
      >>;
      ioto_cterpri();
      indent := indent - 2;
      for i := 1:indent do ioto_prin2 " ";
      ioto_prin2 "}"
   end;

procedure rl_services2jsonArgs(docal);
   begin scalar names, defaults;
      names := cdr atsoc('names, docal);
      defaults := cdr atsoc('defaults, docal);
      return for each name in names join
	 if not atsoc(name, defaults) then
	    {name}
   end;

endmodule;

end;
