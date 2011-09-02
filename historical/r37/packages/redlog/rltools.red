% ----------------------------------------------------------------------
% $Id: rltools.red,v 1.2 1999/03/22 15:18:51 dolzmann Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: rltools.red,v $
% Revision 1.2  1999/03/22 15:18:51  dolzmann
% Changed copyright information.
% Added list of exported procedures.
% Added import list.
%
% Revision 1.1  1996/04/30 12:06:45  sturm
% Merged ioto, lto, and sfto into rltools.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(rltools_rcsid!* rltools_copyright!*);
   rltools_rcsid!* := "$Id: rltools.red,v 1.2 1999/03/22 15:18:51 dolzmann Exp $";
   rltools_copyright!* := "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
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

endmodule;  % [rltools]

end;  % of file
