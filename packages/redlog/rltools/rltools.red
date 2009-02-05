% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 1995-2009 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
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

lisp <<
   fluid '(rltools_rcsid!* rltools_copyright!*);
   rltools_rcsid!* := "$Id$";
   rltools_copyright!* := "Copyright (c) 1995-2009 A. Dolzmann and T. Sturm"
>>;

module rltools;
% Redlog tools.

create!-package('(rltools ioto lto sfto),nil);

exports ioto_prin2,ioto_tprin2,ioto_prin2t,ioto_tprin2t,ioto_prtmsg,
   ioto_cterpri,ioto_cplu,ioto_realtime,ioto_flush,ioto_datestamp,
   lto_insert,lto_insertq,lto_mergesort,lto_catsoc,lto_natsoc,lto_cassoc,
   lto_nconcn,lto_alunion,lto_almerge,lto_sconcat2,lto_sconcat,lto_at2str,
   delq,delqip,adjoin,sfto_dcontentf,sfto_dprpartf,sfto_sqfpartf,
   sfto_ucontentf,sfto_uprpartf,sfto_tsqsumf,sfto_sqfdecf,sfto_pdecf,
   sfto_updecf,sfto_decdegf,sfto_reorder,sfto_groebnerf,sfto_preducef,
   sfto_greducef,sfto_gcdf!*,sfto_gcdf,sfto_sqrtf,sfto_monfp,sfto_sqfpartz,
   sfto_zdeqn,sfto_zdgtn,sfto_zdgen;
      
imports groebner,groebnr2;

if 'psl member lispsystem!* then <<
   if filestatus("$reduce/lisp/psl/$MACHINE/red/groebner.b",nil) then
      load!-package 'groebner;
   if filestatus("$reduce/lisp/psl/$MACHINE/red/groebnr2.b",nil) then
      load!-package 'groebnr2;
>>;

if 'csl member lispsystem!* then <<
   if modulep 'groebner then
      load!-package 'groebner;
   if modulep 'groebnr2 then
      load!-package 'groebnr2
>>;

endmodule;  % [rltools]

end;  % of file
