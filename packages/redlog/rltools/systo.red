module systo;  % System tools.

revision('systo, "$Id$");

copyright('systo, "(c) 2017 T. Sturm");

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

operator meminfo;

procedure meminfo();
   systo_meminfo();

#if (memq 'psl lispsystem!*)

procedure systo_meminfo();
   begin scalar bit, hs, hsb, cpgcp, w, bs, bsb, bps, bpsb;
      if not memq('psl,lispsystem!*) then
	 return nil;
      bit := if eqn(lshift(-1, -56), 255) then 64 else 32;
      prin2 "                address range: ";
      prin2 bit;
      prin2t " bit";
      prin2 "                available bps: ";
      bps := (lastbps-nextbps)/addressingunitsperitem;
      prin2 systo_meminfocomma(bps,'!,);
      prin2t " Lisp items";
      bpsb := (if eqn(bit,64) then 8 else 4) * bps;
      w := systo_meminfoscale bpsb;
      prin2 "                               ";
      prin2 car w;
      prin2 " ";
      prin2t cdr w;
      w := systo_meminfoiscale bpsb;
      prin2 "                               ";
      prin2 car w;
      prin2 " ";
      prin2t cdr w;
      prin2 "           binding stack size: ";
      bs := (bndstkupperbound-bndstklowerbound)/(addressingunitsperitem);
      bs := bs + 1;  % Do not quite understand this.
      prin2 systo_meminfocomma(bs,'!,);
      prin2t " Lisp items";
      bs := bs/2;    % stack elements to Lisp items
      prin2 "                               ";
      prin2 systo_meminfocomma(bs,'!,);
      prin2t " stack elements";
      bsb := (if eqn(bit,64) then 8 else 4) * bs;
      w := systo_meminfoscale bsb;
      prin2 "                               ";
      prin2 car w;
      prin2 " ";
      prin2t cdr w;
      w := systo_meminfoiscale bsb;
      prin2 "                               ";
      prin2 car w;
      prin2 " ";
      prin2t cdr w;
      prin2 "                     heapsize: ";
      hs := set_heap_size nil;
      prin2 systo_meminfocomma(hs,'!,);
      prin2 " Lisp items";
      hsb := (if eqn(bit,64) then 8 else 4) * hs;
      w := systo_meminfoscale hsb;
      prin2 "                               ";
      prin2 car w;
      prin2 " ";
      prin2t cdr w;
      w := systo_meminfoiscale hsb;
      prin2 "                               ";
      prin2 car w;
      prin2 " ";
      prin2t cdr w;
      prin2 "                     GC model: ";
      cpgcp := getd 'copyfromstaticheap;
      prin2t if cpgcp then "stop-and-copy" else "mark-and-sweep";
      if cpgcp then <<
	 hsb := 2 * hsb;
	 prin2 " memory allocation by 2 heaps: ";
	 w := systo_meminfoscale hsb;
	 prin2 car w;
	 prin2 " ";
	 prin2t cdr w;
	 w := systo_meminfoiscale hsb;
	 prin2 "                               ";
	 prin2 car w;
	 prin2 " ";
	 prin2t cdr w;
      >>
   end;

#elif (memq 'csl lispsystem!*)

procedure systo_meminfo();
   begin scalar bit;
      if not memq('csl,lispsystem!*) then
	 return nil;
      bit := if memq('sixty!-four,lispsystem!*) then 64 else 32;
      prin2 "address range: ";
      prin2 bit;
      prin2t " bit";
   end;

#else

procedure systo_meminfo();
   if boundp lispsystem!* then
      prettyprint lispsystem!*
   else
      lprim "unknown Lisp";

#endif

procedure systo_meminfoscale(n);
   if n >= 10^9 then
      (float(n)/10^9) . "GB"
   else if n >= 10^6 then
      (float(n)/10^6) . "MB"
   else if n >= 10^3 then
      (float(n)/10^3) . "kB"
   else
      n . "B";

   procedure systo_meminfoiscale(n);
      if n >= 2^30 then
      	 (float(n)/2^30) . "GiB"
      else if n >= 2^20 then
      	 (float(n)/2^20) . "MiB"
      else if n >= 2^10 then
      	 (float(n)/2^10) . "kiB"
      else
      	 n . "B";

procedure systo_meminfocomma(n,comma);
   begin scalar l; integer c;
      l := '(!");
      for each d on reversip explode n do <<
	 l := car d . l;
	 c := c+1;
	 if cdr d and eqn(c,3) then <<
	    c := 0;
	    l := comma . l
	 >>
      >>;
      return compress('!" . l)
   end;

#if (memq 'psl lispsystem!*)

fluid '(symbolfilename!*);

procedure systo_trunk();
   systo_dotdotx(symbolfilename!*,4);

procedure systo_get!-resource!-directory();
   % The name of a directory in which "resources" may be found without trailing
   % "/". For PSL it will be something like .../pslbuild/xxxx/red where
   % .../pslbuild/xxx/psl contains the executable file bpsl.
   concat(systo_dotdot systo_dotdot symbolfilename!*, "red");

#elif (memq 'csl lispsystem!*)

procedure systo_trunk();
   concat(!@reduce, "/");

procedure systo_get!-resource!-directory();
   begin scalar l, os, a;
      l := lispsystem!*;
      while not os and l do <<
	 a := pop l;
	 if eqcar(a, 'opsys) then
	    os := cdr a
      >>;
      if lto_substr(id2string os, 6, 1) = "darwin" then
	 return concat(get!-lisp!-directory(), "/../Resources/reduce.resources");
      return concat(get!-lisp!-directory(), "/reduce.resources")
   end;

#endif

#if (memq 'psl lispsystem!*)

procedure systo_datestamp();
   <<
      date();
      sys2int wgetv(datebuffer,0)
   >>;

#elif (memq 'csl lispsystem!*)

procedure systo_datestamp();
   datestamp();

#endif

procedure systo_dotdotx(s,n);
   if eqn(n,0) then
      s
   else
      systo_dotdotx(systo_dotdot s,n-1);

procedure systo_dotdot(s);
   begin scalar w;
      w := cdr reversip explode s;
      if eqcar(w,'!/) then w := cdr w;
      repeat w := cdr w until eqcar(w,'!/);
      return compress reversip('!" . w)
   end;

operator rndseed;

procedure rndseed(s);
   systo_rndseed(s);

procedure systo_rndseed(s);
   % Call with a unique odd number.
   <<
      if 'csl memq lispsystem!* then
 	 s := 2 * s;
      random_new_seed s
   >>;

endmodule;

end;
