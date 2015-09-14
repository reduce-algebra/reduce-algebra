% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2015 M. Kosta, T. Sturm
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
   fluid '(ofsfvslists_rcsid!* ofsfvslists_copyright!*);
   ofsfvslists_rcsid!* :=
      "$Id$";
   ofsfvslists_copyright!* := "(c) 2015 M. Kosta, T. Sturm"
>>;

module ofsfvslists;

fluid '(rlclustering!*);
rlclustering!* := t;

fluid '(rsl!-alist!* rsl!-alist!-clustering!* guard!-fnalist!* vsub!-fnalist!*);

rsl!-alist!* := {
   % key: {ldeg f, sign of lc f, op}
   % value: AList [al] containing elements [pr] such that [car pr] is
   % one of ['(ip ep slb wlb sub wub)] and [cdr pr] is a list of root
   % specification lists
   {1, -1, 'equal} . {
      'ip . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'equal} . {
      'ip . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'neq} . {
      'ep  . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'neq} . {
      'ep . {
	 {1 . 1},
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'neq} . {
      'ep . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'lessp} . {
      'slb . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'lessp} . {
      'slb . {
	 {(-1) . 1}
	    },
      'sub . {
	 {1 . 1}
	    }
	       },

   {1, 1, 'lessp} . {
      'sub . {
	 {1 . 1}
	    }
      	       },

   {1, -1, 'leq} . {
      'wlb . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'leq} . {
      'wlb . {
      	 {(-1) . 1}
	    },
      'wub . {
	 {1 . 1}
	    }
      	       },

   {1, 1, 'leq} . {
      'wub . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'geq} . {
      'wub . {
	 {(-1) . 1}
	    }
      	       },
   {1, nil, 'geq} . {
      'wlb . {
	 {1 . 1}
	    },
      'wub . {
	 {(-1) . 1}
	    }
	       },

   {1, 1, 'geq} . {
      'wlb . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'greaterp} . {
      'sub . {
      	 {(-1) . 1}
	    }
      	       },

   {1, nil, 'greaterp} . {
      'slb . {
      	 {1 . 1}
	    },
      'sub . {
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'greaterp} . {
      'slb . {
      	 {1 . 1}
	    }
	       },

   {2, -1, 'equal} . {
      'ip . {
      	 {(-1) . 1},
      	 {(-1) . 2},
      	 {(-2) . 1}
	    }
	       },

   {2, nil, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {1 . 2},
      	 {2 . 1},
      	 {(-1) . 1},
      	 {(-1) . 2},
      	 {(-2) . 1}
	    }
	       },

   {2, 1, 'equal} . {
      'ip . {
      	 {1 . 1},
      	 {1 . 2},
      	 {2 . 1}
	    }
	       },

   {2, -1, 'neq} . {
      'ep . {
      	 {(-1) . 1},
      	 {(-1) . 2},
      	 {(-2) . 1}
	    }
	       },

   {2, nil, 'neq} . {
      'ep . {
	 {1 . 1},
      	 {1 . 2},
      	 {2 . 1},
      	 {(-1) . 1},
      	 {(-1) . 2},
      	 {(-2) . 1}
	    }
	       },

   {2, 1, 'neq} . {
      'ep . {
      	 {1 . 1},
      	 {1 . 2},
      	 {2 . 1}
	    }
	       },

   {2, -1, 'lessp} . {
      'ep . {
	 {(-2) . 1}
	    },
      'slb . {
      	 {(-1) . 2}
	    },
      'sub . {
	 {(-1) . 1}
	    }
	       },

   {2, nil, 'lessp} . {
      'ep . {
	 {(-2) . 1}
	    },
      'slb . {
      	 {1 . 1},
	 {(-1) . 2}
	    },
      'sub . {
	 {1 . 2},
      	 {(-1) . 1}
	    }
	       },

   {2, 1, 'lessp} . {
      'slb . {
      	 {1 . 1}
	    },
      'sub . {
      	 {1 . 2}
	    }
	       },

   {2, -1, 'leq} . {
      'wlb . {
      	 {(-1) . 2}
	    },
      'wub . {
	 {(-1) . 1}
	    }
	       },

   {2, nil, 'leq} . {
      'ip . {
      	 {2 . 1}
	    },
      'wlb . {
      	 {1 . 1},
      	 {(-1) . 2}
	    },
      'wub . {
	 {1 . 2},
      	 {(-1) . 1}
	    }
	       },

   {2, 1, 'leq} . {
      'ip . {
      	 {2 . 1}
	    },
      'wlb . {
      	 {1 . 1}
	    },
      'wub . {
	 {1 . 2}
	    }
	       },

   {2, -1, 'geq} . {
      'ip . {
	 {(-2) . 1}
	    },
      'wlb . {
      	 {(-1) . 1}
	    },
      'wub . {
	 {(-1) . 2}
	    }
	       },

   {2, nil, 'geq} . {
      'ip . {
	 {(-2) . 1}
	    },
      'wlb . {
      	 {1 . 2},
      	 {(-1) . 1}
	    },
      'wub . {
	 {1 . 1},
      	 {(-1) . 2}
	    }
	       },

   {2, 1, 'geq} . {
      'wlb . {
      	 {1 . 2}
	    },
      'wub . {
	 {1 . 1}
	    }
	       },

   {2, -1, 'greaterp} . {
      'slb . {
      	 {(-1) . 1}
	    },
      'sub . {
	 {(-1) . 2}
	    }
	       },

   {2, nil, 'greaterp} . {
      'ep . {
      	 {2 . 1}
	    },
      'slb . {
      	 {1 . 2},
      	 {(-1) . 1}
	    },
      'sub . {
      	 {1 . 1},
      	 {(-1) . 2}
	    }
	       },

   {2, 1, 'greaterp} . {
      'ep . {
	 {2 . 1}
	    },
      'slb . {
      	 {1 . 2}
	    },
      'sub . {
	 {1 . 1}
	    }
	       },

   {3, -1, 'equal} . {
      'ip . {
	 {(-1) . 1},
      	 {(-2) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-3) . 2},
      	 {(-4) . 1},
      	 {(-4) . 2},
      	 {(-4) . 3}
	    }
	       },

   {3, nil, 'equal} . {
      'ip . {
      	 {1 . 1},
      	 {2 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {3 . 2},
      	 {4 . 1},
      	 {4 . 2},
      	 {4 . 3},
      	 {(-1) . 1},
      	 {(-2) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-3) . 2},
      	 {(-4) . 1},
      	 {(-4) . 2},
      	 {(-4) . 3}
	    }
	       },

   {3, 1, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {2 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {3 . 2},
      	 {4 . 1},
      	 {4 . 2},
      	 {4 . 3}
	    }
	       },

   {3, -1, 'neq} . {
      'ep . {
      	 {(-1) . 1},
      	 {(-2) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-3) . 2},
      	 {(-4) . 1},
      	 {(-4) . 2},
      	 {(-4) . 3}
	    }
	       },
   {3, nil, 'neq} . {
      'ep . {
      	 {1 . 1},
      	 {2 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {3 . 2},
      	 {4 . 1},
      	 {4 . 2},
      	 {4 . 3},
      	 {(-1) . 1},
      	 {(-2) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-3) . 2},
      	 {(-4) . 1},
      	 {(-4) . 2},
      	 {(-4) . 3}
	    }
	       },

   {3, 1, 'neq} . {
      'ep . {
      	 {1 . 1},
      	 {2 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {3 . 2},
      	 {4 . 1},
      	 {4 . 2},
      	 {4 . 3}
	    }
	       },

   {3, -1, 'lessp} . {
      'ep . {
	 {(-3) . 2}
	    },
      'slb . {
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    },
      'sub . {
	 {(-4) . 2}
	    }
	       },

   {3, nil, 'lessp} . {
      'ep . {
	 {2 . 1},
	 {(-3) . 2}
	    },
      'slb . {
      	 {4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    },
      'sub . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3},
      	 {(-4) . 2}
	    }
	       },

   {3, 1, 'lessp} . {
      'ep . {
      	 {2 . 1}
	    },
      'slb . {
      	 {4 . 2}
	    },
      'sub . {
	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3}
	    }
	       },

   {3, -1, 'leq} . {
      'ip . {
      	 {(-2) . 1}
	    },
      'wlb . {
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    },
      'wub . {
	 {(-4) . 2}
	    }
	       },

   {3, nil, 'leq} . {
      'ip . {
      	 {3 . 2},
      	 {(-2) . 1}
	    },
      'wlb . {
      	 {4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    },
      'wub . {
	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3},
      	 {(-4) . 2}
	    }
      	       },

   {3, 1, 'leq} . {
      'ip . {
	 {3 . 2}
	    },
      'wlb . {
      	 {4 . 2}
	    },
      'wub . {
	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3}
	    }
	       },

   {3, -1, 'geq} . {
      'ip . {
      	 {(-3) . 2}
	    },
      'wlb . {
      	 {(-4) . 2}
	    },
      'wub . {
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    }
      	       },

   {3, nil, 'geq} . {
      'ip . {
      	 {2 . 1},
      	 {(-3) . 2}
	    },
      'wlb . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3},
      	 {(-4) . 2}
	    },
      'wub . {
      	 {4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    }
      	       },

   {3, 1, 'geq} . {
      'ip . {
      	 {2 . 1}
	    },
      'wlb . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3}
	    },
      'wub . {
      	 {4 . 2}
	    }
      	       },

   {3, -1, 'greaterp} . {
      'ep . {
	 {(-2) . 1}
	    },
      'slb . {
      	 {(-4) . 2}
	    },
      'sub . {
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    }
	       },

   {3, nil, 'greaterp} . {
      'ep . {
      	 {3 . 2},
	 {(-2) . 1}
	    },
      'slb . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3},
      	 {(-4) . 2}
	    },
      'sub . {
      	 {4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    }
	       },

   {3, 1, 'greaterp} . {
      'ep . {
      	 {3 . 2}
	    },
      'slb . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3}
	    },
      'sub . {
      	 {4 . 2}
	    }
	       }
   	    	  };

rsl!-alist!-clustering!* := {
   % key: {ldeg f, sign of lc f, op}
   % value: AList [al] containing elements [pr] such that [car pr] is
   % one of ['(ip ep slb wlb sub wub)] and [cdr pr] is a list of root
   % specification lists
   {1, -1, 'equal} . {
      'ip . {
      	 {(-1) . 1}
	    }
	       },

   {1, nil, 'equal} . {
      'ip . {
	 {1 . 1, (-1) . 1}
	    }
	       },

   {1, 1, 'equal} . {
      'ip . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'neq} . {
      'ep . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'neq} . {
      'ep . {
	 {1 . 1, (-1) . 1}
	    }
	       },

   {1, 1, 'neq} . {
      'ep . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'lessp} . {
      'slb . {
      	 {(-1) . 1}
	    }
	       },

   {1, nil, 'lessp} . {
      'slb . {
      	 {(-1) . 1}
	    },
      'sub . {
	 {1 . 1}
	    }
	       },

   {1, 1, 'lessp} . {
      'sub . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'leq} . {
      'wlb . {
      	 {(-1) . 1}
	    }
	       },

   {1, nil, 'leq} . {
      'wlb . {
      	 {(-1) . 1}
	    },
      'wub . {
	 {1 . 1}
	    }
	       },

   {1, 1, 'leq} . {
      'wub . {
	 {1 . 1}
      	    }
	       },

   {1, -1, 'geq} . {
      'wub . {
      	 {(-1) . 1}
	    }
      	       },

   {1, nil, 'geq} . {
      'wlb . {
	 {1 . 1}
	    },
      'wub . {
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'geq} . {
      'wlb . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'greaterp} . {
      'sub . {
      	 {(-1) . 1}
	    }
	       },

   {1, nil, 'greaterp} . {
      'slb . {
	 {1 . 1}
	    },
      'sub . {
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'greaterp} . {
      'slb . {
	 {1 . 1}
	    }
	       },

   {2, -1, 'equal} . {
      'ip . {
	 {(-1) . 2, (-2) . 1},
      	 {(-1) . 1, (-2) . 1}
	    }
	       },

   {2, nil, 'equal} . {
      'ip . {
	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1},
      	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    }
	       },

   {2, 1, 'equal} . {
      'ip . {
      	 {1 . 1, 2 . 1},
      	 {1 . 2, 2 . 1}
	    }
	       },

   {2, -1, 'neq} . {
      'ep . {
	 {(-1) . 2, (-2) . 1},
      	 {(-1) . 1, (-2) . 1}
	    }
	       },

   {2, nil, 'neq} . {
      'ep . {
      	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1},
      	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    }
	       },

   {2, 1, 'neq} . {
      'ep . {
      	 {1 . 1, 2 . 1},
      	 {1 . 2, 2 . 1}
	    }
	       },

   {2, -1, 'lessp} . {
      'slb . {
	 {(-1) . 2, (-2) . 1}
	    },
      'sub . {
	 {(-1) . 1, (-2) . 1}
	    }
	       },

   {2, nil, 'lessp} . {
      'slb . {
      	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}
	    },
      'sub . {
	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    }
	       },

   {2, 1, 'lessp} . {
      'slb . {
      	 {1 . 1, 2 . 1}
	    },
      'sub . {
	 {1 . 2, 2 . 1}
	    }
	       },

   {2, -1, 'leq} . {
      'wlb . {
	 {(-1) . 2, (-2) . 1}
	    },
      'wub . {
	 {(-1) . 1, (-2) . 1}
	    }
	       },

   {2, nil, 'leq} . {
      'wlb . {
      	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}
	    },
      'wub . {
	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    }
      	       },

   {2, 1, 'leq} . {
      'wlb . {
	 {1 . 1, 2 . 1}
	    },
      'wub . {
	 {1 . 2, 2 . 1}
	    }
	       },

   {2, -1, 'geq} . {
      'wlb . {
	 {(-1) . 1, (-2) . 1}
	    },
      'wub . {
	 {(-1) . 2, (-2) . 1}
	    }
	       },

   {2, nil, 'geq} . {
      'wlb . {
	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    },
      'wub . {
	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}
	    }
	       },

   {2, 1, 'geq} . {
      'wlb . {
	 {1 . 2, 2 . 1}
	    },
      'wub . {
	 {1 . 1, 2 . 1}
	    }
	       },

   {2, -1, 'greaterp} . {
      'slb . {
	 {(-1) . 1, (-2) . 1}
	    },
      'sub . {
	 {(-1) . 2, (-2) . 1}
	    }
	       },

   {2, nil, 'greaterp} . {
      'slb . {
	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    },
      'sub . {
	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}
	    }
      	       },

   {2, 1, 'greaterp} . {
      'slb . {
	 {1 . 2, 2 . 1}
	    },
      'sub . {
	 {1 . 1, 2 . 1}
	    }
	       },

   {3, -1, 'equal} . {
      'ip . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 1, (-3) . 2, (-4) . 2},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, nil, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 1, (-3) . 2, (-4) . 2},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, 1, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {2 . 2, 3 . 2, 4 . 3}
      	    }
	       },

   {3, -1, 'neq} . {
      'ep . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 1, (-3) . 2, (-4) . 2},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, nil, 'neq} . {
      'ep . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 1, (-3) . 2, (-4) . 2},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, 1, 'neq} . {
      'ep . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {2 . 2, 3 . 2, 4 . 3}
      	    }
	       },

   {3, -1, 'lessp} . {
      'slb . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    },
      'sub . {
	 {(-2) . 1, (-3) . 2, (-4) . 2}
	    }
	       },

   {3, nil, 'lessp} . {
      'slb . {
	 {2 . 1, 3 . 2, 4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    },
      'sub . {
      	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-2) . 1, (-3) . 2, (-4) . 2}
	    }
	       },

   {3, 1, 'lessp} . {
      'slb . {
	 {2 . 1, 3 . 2, 4 . 2}
	    },
      'sub . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3}
	    }
      	       },

   {3, -1, 'leq} . {
      'wlb . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    },
      'wub . {
	 {(-2) . 1, (-3) . 2, (-4) . 2}
	    }
	       },

   {3, nil, 'leq} . {
      'wlb . {
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    },
      'wub . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-2) . 1, (-3) . 2, (-4) . 2}
	    }
	       },

   {3, 1, 'leq} . {
      'wlb . {
	 {2 . 1, 3 . 2, 4 . 2}
	    },
      'wub . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3}
	    }
	       },

   {3, -1, 'geq} . {
      'wlb . {
	 {(-2) . 1, (-3) . 2, (-4) . 2}
      	    },
      'wub . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, nil, 'geq} . {
      'wlb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-2) . 1, (-3) . 2, (-4) . 2}
   	    },
      'wub . {
	 {2 . 1, 3 . 2, 4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, 1, 'geq} . {
      'wlb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3}
      	    },
      'wub . {
	 {2 . 1, 3 . 2, 4 . 2}
	    }
	       },

   {3, -1, 'greaterp} . {
      'wlb . {
	 {(-2) . 1, (-3) . 2, (-4) . 2}
      	    },
      'wub . {
	 {(-1) . 1},
	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, nil, 'greaterp} . {
      'wlb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-2) . 1, (-3) . 2, (-4) . 2}
   	    },
      'wub . {
	 {2 . 1, 3 . 2, 4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, 1, 'greaterp} . {
      'wlb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3}
      	    },
      'wub . {
	 {2 . 1, 3 . 2, 4 . 2}
	    }
	       }
   		  };

guard!-fnalist!* := {
   % key: {ldeg f, rtl}
   % value: guard constructing function
   {1, '(-1)} . 'guard!-1!-1m,
   {1, '(1)} . 'guard!-1!-1,
   {1, '(-1 1)} . 'guard!-1!-2,

   {2, '(-2)} . 'guard!-2!-2m,
   {2, '(-1)} . 'guard!-2!-1m,
   {2, '(1)} . 'guard!-2!-1,
   {2, '(2)} . 'guard!-2!-2,
   {2, '(-2 -1)} . 'guard!-2!-3m,
   {2, '(1 2)} . 'guard!-2!-3,
   {2, '(-2 -1 1 2)} . 'guard!-2!-4,

   {3, '(-4)} . 'guard!-3!-4m,
   {3, '(-3)} . 'guard!-3!-3m,
   {3, '(-2)} . 'guard!-3!-2m,
   {3, '(-1)} . 'guard!-3!-1m,
   {3, '(1)} . 'guard!-3!-1,
   {3, '(2)} . 'guard!-3!-2,
   {3, '(3)} . 'guard!-3!-3,
   {3, '(4)} . 'guard!-3!-4,
   {3, '(-2 -3 -4)} . 'guard!-3!-5m,
   {3, '(2 3 4)} . 'guard!-3!-5
      };

procedure guard!-1!-1m(f);
   begin scalar a;
      a := lc f;
      return ofsf_iparse(
      	 a < 0
	    )
   end;

procedure guard!-1!-1(f);
   begin scalar a;
      a := lc f;
      return ofsf_iparse(
      	 a > 0
	    )
   end;

procedure guard!-1!-2(f);
   begin scalar a;
      a := lc f;
      return ofsf_iparse(
      	 a <> 0
	    )
   end;

procedure guard!-2!-2m(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 a < 0 and b^2 - 4*a*c = 0
	    )
   end;

procedure guard!-2!-1m(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 a < 0 and b^2 - 4*a*c > 0
	    )
   end;

procedure guard!-2!-1(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and b^2 - 4*a*c > 0
	    )
   end;

procedure guard!-2!-2(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and b^2 - 4*a*c = 0
	    )
   end;

procedure guard!-2!-3m(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 a < 0 and b^2 - 4*a*c >= 0
	    )
   end;

procedure guard!-2!-3(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and b^2 - 4*a*c >= 0
	    )
   end;

procedure guard!-2!-4(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
      	 a <> 0 and b^2 - 4*a*c >= 0
	    )
   end;

procedure guard!-3!-4m(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a < 0 and -b^2 + 3*a*c < 0 and
   	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d < 0
	    )
   end;

procedure guard!-3!-3m(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a < 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c < 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0
	    )
   end;

procedure guard!-3!-2m(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a < 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c > 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0
	    )
   end;

procedure guard!-3!-1m(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a < 0 and (-b^2 + 3*a*c >= 0 or
      	    -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d > 0)
	    )
   end;

procedure guard!-3!-1(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and (-b^2 + 3*a*c >= 0 or
      	    -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d > 0)
	    )
   end;

procedure guard!-3!-2(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c < 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0
	    )
   end;

procedure guard!-3!-3(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c > 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0
	    )
   end;

procedure guard!-3!-4(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and -b^2 + 3*a*c < 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d < 0
	    )
   end;

procedure guard!-3!-5m(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a < 0 and -b^2 + 3*a*c < 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d <= 0
	    )
   end;

procedure guard!-3!-5(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and -b^2 + 3*a*c < 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d <= 0
	    )
   end;

#if (memq 'psl lispsystem!*)

vsub!-fnalist!* := {
   % key: {ldeg f, rsl, ldeg g, op}
   % value: virtual substitution constructing function

   % 2, 1, equal
   {2, {1 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1,
   {2, {1 . 2}, 1, 'equal} . 'vsub!-2!-1!-equal!-2,
   {2, {2 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-3,
   {2, {(-1) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1m,
   {2, {(-1) . 2}, 1, 'equal} . 'vsub!-2!-1!-equal!-2m,
   {2, {(-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-3m,
   % 2, 1, equal, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-5,
   {2, {1 . 1, 2 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1,
   {2, {1 . 2, 2 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-2m,

   % 2, 1, lessp
   {2, {1 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1,
   {2, {1 . 2}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2,
   {2, {2 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-3,
   {2, {(-1) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1m,
   {2, {(-1) . 2}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2m,
   {2, {(-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-3m,
   % 2, 1, lessp, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-5,
   {2, {1 . 1, 2 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1,
   {2, {1 . 2, 2 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2m,

   % 2, 1, leq
   {2, {1 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1,
   {2, {1 . 2}, 1, 'leq} . 'vsub!-2!-1!-leq!-2,
   {2, {2 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-3,
   {2, {(-1) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1m,
   {2, {(-1) . 2}, 1, 'leq} . 'vsub!-2!-1!-leq!-2m,
   {2, {(-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-3m,
   % 2, 1, leq, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-5,
   {2, {1 . 1, 2 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1,
   {2, {1 . 2, 2 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-2m,

   % 2, 1, neq
   {2, {1 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1,
   {2, {1 . 2}, 1, 'neq} . 'vsub!-2!-1!-neq!-2,
   {2, {2 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-3,
   {2, {(-1) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1m,
   {2, {(-1) . 2}, 1, 'neq} . 'vsub!-2!-1!-neq!-2m,
   {2, {(-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-3m,
   % 2, 1, neq, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-5,
   {2, {1 . 1, 2 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1,
   {2, {1 . 2, 2 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-2m,

   % 2, 1, greaterp
   {2, {1 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1,
   {2, {1 . 2}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2,
   {2, {2 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-3,
   {2, {(-1) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1m,
   {2, {(-1) . 2}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2m,
   {2, {(-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-3m,
   % 2, 1, greaterp, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-5,
   {2, {1 . 1, 2 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1,
   {2, {1 . 2, 2 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2m,

   % 2, 1, geq
   {2, {1 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1,
   {2, {1 . 2}, 1, 'geq} . 'vsub!-2!-1!-geq!-2,
   {2, {2 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-3,
   {2, {(-1) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1m,
   {2, {(-1) . 2}, 1, 'geq} . 'vsub!-2!-1!-geq!-2m,
   {2, {(-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-3m,
   % 2, 1, geq, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-5,
   {2, {1 . 1, 2 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1,
   {2, {1 . 2, 2 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-2m
      };

#else

vsub!-fnalist!* := {
   % key: {ldeg f, rsl, ldeg g, op}
   % value: virtual substitution constructing function

   % 2, 1, equal
   {2, {1 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1,
   {2, {1 . 2}, 1, 'equal} . 'vsub!-2!-1!-equal!-2,
   {2, {2 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-3,
   {2, {(-1) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1m,
   {2, {(-1) . 2}, 1, 'equal} . 'vsub!-2!-1!-equal!-2m,
   {2, {(-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-3m,
   % 2, 1, equal, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-5,
   {2, {1 . 1, 2 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1,
   {2, {1 . 2, 2 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-2m,

   % 2, 1, lessp
   {2, {1 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1,
   {2, {1 . 2}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2,
   {2, {2 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-3,
   {2, {(-1) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1m,
   {2, {(-1) . 2}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2m,
   {2, {(-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-3m,
   % 2, 1, lessp, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-5,
   {2, {1 . 1, 2 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1,
   {2, {1 . 2, 2 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2m,

   % 2, 1, leq
   {2, {1 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1,
   {2, {1 . 2}, 1, 'leq} . 'vsub!-2!-1!-leq!-2,
   {2, {2 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-3,
   {2, {(-1) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1m,
   {2, {(-1) . 2}, 1, 'leq} . 'vsub!-2!-1!-leq!-2m,
   {2, {(-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-3m,
   % 2, 1, leq, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-5,
   {2, {1 . 1, 2 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1,
   {2, {1 . 2, 2 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-2m,

   % 2, 1, neq
   {2, {1 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1,
   {2, {1 . 2}, 1, 'neq} . 'vsub!-2!-1!-neq!-2,
   {2, {2 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-3,
   {2, {(-1) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1m,
   {2, {(-1) . 2}, 1, 'neq} . 'vsub!-2!-1!-neq!-2m,
   {2, {(-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-3m,
   % 2, 1, neq, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-5,
   {2, {1 . 1, 2 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1,
   {2, {1 . 2, 2 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-2m,

   % 2, 1, greaterp
   {2, {1 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1,
   {2, {1 . 2}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2,
   {2, {2 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-3,
   {2, {(-1) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1m,
   {2, {(-1) . 2}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2m,
   {2, {(-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-3m,
   % 2, 1, greaterp, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-5,
   {2, {1 . 1, 2 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1,
   {2, {1 . 2, 2 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2m,

   % 2, 1, geq
   {2, {1 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1,
   {2, {1 . 2}, 1, 'geq} . 'vsub!-2!-1!-geq!-2,
   {2, {2 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-3,
   {2, {(-1) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1m,
   {2, {(-1) . 2}, 1, 'geq} . 'vsub!-2!-1!-geq!-2m,
   {2, {(-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-3m,
   % 2, 1, geq, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-5,
   {2, {1 . 1, 2 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1,
   {2, {1 . 2, 2 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-2m,

   % 3, 1, equal
   {3, {1 . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-1,
   {3, {2 . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-2,
   {3, {2 . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-3,
   {3, {3 . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-4,
   {3, {3 . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-5,
   {3, {4 . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-6,
   {3, {4 . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-7,
   {3, {4 . 3}, 1, 'equal} . 'vsub!-3!-1!-equal!-8,
   {3, {(-1) . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-1m,
   {3, {(-2) . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-2m,
   {3, {(-2) . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-3m,
   {3, {(-3) . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-4m,
   {3, {(-3) . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-5m,
   {3, {(-4) . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-6m,
   {3, {(-4) . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-7m,
   {3, {(-4) . 3}, 1, 'equal} . 'vsub!-3!-1!-equal!-8m,

   % 3, 1, lessp
   {3, {1 . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-1,
   {3, {2 . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-2,
   {3, {2 . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-3,
   {3, {3 . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-4,
   {3, {3 . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-5,
   {3, {4 . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-6,
   {3, {4 . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-7,
   {3, {4 . 3}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-8,
   {3, {(-1) . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-1m,
   {3, {(-2) . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-2m,
   {3, {(-2) . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-3m,
   {3, {(-3) . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-4m,
   {3, {(-3) . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-5m,
   {3, {(-4) . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-6m,
   {3, {(-4) . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-7m,
   {3, {(-4) . 3}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-8m,

   % 3, 1, leq
   {3, {1 . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-1,
   {3, {2 . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-2,
   {3, {2 . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-3,
   {3, {3 . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-4,
   {3, {3 . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-5,
   {3, {4 . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-6,
   {3, {4 . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-7,
   {3, {4 . 3}, 1, 'leq} . 'vsub!-3!-1!-leq!-8,
   {3, {(-1) . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-1m,
   {3, {(-2) . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-2m,
   {3, {(-2) . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-3m,
   {3, {(-3) . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-4m,
   {3, {(-3) . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-5m,
   {3, {(-4) . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-6m,
   {3, {(-4) . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-7m,
   {3, {(-4) . 3}, 1, 'leq} . 'vsub!-3!-1!-leq!-8m,

   % 3, 1, neq
   {3, {1 . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-1,
   {3, {2 . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-2,
   {3, {2 . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-3,
   {3, {3 . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-4,
   {3, {3 . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-5,
   {3, {4 . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-6,
   {3, {4 . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-7,
   {3, {4 . 3}, 1, 'neq} . 'vsub!-3!-1!-neq!-8,
   {3, {(-1) . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-1m,
   {3, {(-2) . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-2m,
   {3, {(-2) . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-3m,
   {3, {(-3) . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-4m,
   {3, {(-3) . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-5m,
   {3, {(-4) . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-6m,
   {3, {(-4) . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-7m,
   {3, {(-4) . 3}, 1, 'neq} . 'vsub!-3!-1!-neq!-8m,

   % 3, 1, greaterp
   {3, {1 . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-1,
   {3, {2 . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-2,
   {3, {2 . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-3,
   {3, {3 . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-4,
   {3, {3 . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-5,
   {3, {4 . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-6,
   {3, {4 . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-7,
   {3, {4 . 3}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-8,
   {3, {(-1) . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-1m,
   {3, {(-2) . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-2m,
   {3, {(-2) . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-3m,
   {3, {(-3) . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-4m,
   {3, {(-3) . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-5m,
   {3, {(-4) . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-6m,
   {3, {(-4) . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-7m,
   {3, {(-4) . 3}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-8m,

   % 3, 1, geq
   {3, {1 . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-1,
   {3, {2 . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-2,
   {3, {2 . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-3,
   {3, {3 . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-4,
   {3, {3 . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-5,
   {3, {4 . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-6,
   {3, {4 . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-7,
   {3, {4 . 3}, 1, 'geq} . 'vsub!-3!-1!-geq!-8,
   {3, {(-1) . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-1m,
   {3, {(-2) . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-2m,
   {3, {(-2) . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-3m,
   {3, {(-3) . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-4m,
   {3, {(-3) . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-5m,
   {3, {(-4) . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-6m,
   {3, {(-4) . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-7m,
   {3, {(-4) . 3}, 1, 'geq} . 'vsub!-3!-1!-geq!-8m,

   % 3, 2, equal
   {3, {1 . 1}, 2, 'equal} . 'vsub!-3!-1!-equal!-1,
   {3, {2 . 1}, 2, 'equal} . 'vsub!-3!-1!-equal!-2,
   {3, {2 . 2}, 2, 'equal} . 'vsub!-3!-1!-equal!-3,
   {3, {3 . 1}, 2, 'equal} . 'vsub!-3!-1!-equal!-4,
   {3, {3 . 2}, 2, 'equal} . 'vsub!-3!-1!-equal!-5,
   {3, {4 . 1}, 2, 'equal} . 'vsub!-3!-1!-equal!-6,
   {3, {4 . 2}, 2, 'equal} . 'vsub!-3!-1!-equal!-7,
   {3, {4 . 3}, 2, 'equal} . 'vsub!-3!-1!-equal!-8,
   {3, {(-1) . 1}, 2, 'equal} . 'vsub!-3!-1!-equal!-1m,
   {3, {(-2) . 1}, 2, 'equal} . 'vsub!-3!-1!-equal!-2m,
   {3, {(-2) . 2}, 2, 'equal} . 'vsub!-3!-1!-equal!-3m,
   {3, {(-3) . 1}, 2, 'equal} . 'vsub!-3!-1!-equal!-4m,
   {3, {(-3) . 2}, 2, 'equal} . 'vsub!-3!-1!-equal!-5m,
   {3, {(-4) . 1}, 2, 'equal} . 'vsub!-3!-1!-equal!-6m,
   {3, {(-4) . 2}, 2, 'equal} . 'vsub!-3!-1!-equal!-7m,
   {3, {(-4) . 3}, 2, 'equal} . 'vsub!-3!-1!-equal!-8m,

   % 3, 2, lessp
   {3, {1 . 1}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-1,
   {3, {2 . 1}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-2,
   {3, {2 . 2}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-3,
   {3, {3 . 1}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-4,
   {3, {3 . 2}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-5,
   {3, {4 . 1}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-6,
   {3, {4 . 2}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-7,
   {3, {4 . 3}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-8,
   {3, {(-1) . 1}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-1m,
   {3, {(-2) . 1}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-2m,
   {3, {(-2) . 2}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-3m,
   {3, {(-3) . 1}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-4m,
   {3, {(-3) . 2}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-5m,
   {3, {(-4) . 1}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-6m,
   {3, {(-4) . 2}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-7m,
   {3, {(-4) . 3}, 2, 'lessp} . 'vsub!-3!-1!-lessp!-8m,

   % 3, 2, leq
   {3, {1 . 1}, 2, 'leq} . 'vsub!-3!-1!-leq!-1,
   {3, {2 . 1}, 2, 'leq} . 'vsub!-3!-1!-leq!-2,
   {3, {2 . 2}, 2, 'leq} . 'vsub!-3!-1!-leq!-3,
   {3, {3 . 1}, 2, 'leq} . 'vsub!-3!-1!-leq!-4,
   {3, {3 . 2}, 2, 'leq} . 'vsub!-3!-1!-leq!-5,
   {3, {4 . 1}, 2, 'leq} . 'vsub!-3!-1!-leq!-6,
   {3, {4 . 2}, 2, 'leq} . 'vsub!-3!-1!-leq!-7,
   {3, {4 . 3}, 2, 'leq} . 'vsub!-3!-1!-leq!-8,
   {3, {(-1) . 1}, 2, 'leq} . 'vsub!-3!-1!-leq!-1m,
   {3, {(-2) . 1}, 2, 'leq} . 'vsub!-3!-1!-leq!-2m,
   {3, {(-2) . 2}, 2, 'leq} . 'vsub!-3!-1!-leq!-3m,
   {3, {(-3) . 1}, 2, 'leq} . 'vsub!-3!-1!-leq!-4m,
   {3, {(-3) . 2}, 2, 'leq} . 'vsub!-3!-1!-leq!-5m,
   {3, {(-4) . 1}, 2, 'leq} . 'vsub!-3!-1!-leq!-6m,
   {3, {(-4) . 2}, 2, 'leq} . 'vsub!-3!-1!-leq!-7m,
   {3, {(-4) . 3}, 2, 'leq} . 'vsub!-3!-1!-leq!-8m,

   % 3, 2, neq
   {3, {1 . 1}, 2, 'neq} . 'vsub!-3!-1!-neq!-1,
   {3, {2 . 1}, 2, 'neq} . 'vsub!-3!-1!-neq!-2,
   {3, {2 . 2}, 2, 'neq} . 'vsub!-3!-1!-neq!-3,
   {3, {3 . 1}, 2, 'neq} . 'vsub!-3!-1!-neq!-4,
   {3, {3 . 2}, 2, 'neq} . 'vsub!-3!-1!-neq!-5,
   {3, {4 . 1}, 2, 'neq} . 'vsub!-3!-1!-neq!-6,
   {3, {4 . 2}, 2, 'neq} . 'vsub!-3!-1!-neq!-7,
   {3, {4 . 3}, 2, 'neq} . 'vsub!-3!-1!-neq!-8,
   {3, {(-1) . 1}, 2, 'neq} . 'vsub!-3!-1!-neq!-1m,
   {3, {(-2) . 1}, 2, 'neq} . 'vsub!-3!-1!-neq!-2m,
   {3, {(-2) . 2}, 2, 'neq} . 'vsub!-3!-1!-neq!-3m,
   {3, {(-3) . 1}, 2, 'neq} . 'vsub!-3!-1!-neq!-4m,
   {3, {(-3) . 2}, 2, 'neq} . 'vsub!-3!-1!-neq!-5m,
   {3, {(-4) . 1}, 2, 'neq} . 'vsub!-3!-1!-neq!-6m,
   {3, {(-4) . 2}, 2, 'neq} . 'vsub!-3!-1!-neq!-7m,
   {3, {(-4) . 3}, 2, 'neq} . 'vsub!-3!-1!-neq!-8m,

   % 3, 2, greaterp
   {3, {1 . 1}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-1,
   {3, {2 . 1}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-2,
   {3, {2 . 2}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-3,
   {3, {3 . 1}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-4,
   {3, {3 . 2}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-5,
   {3, {4 . 1}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-6,
   {3, {4 . 2}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-7,
   {3, {4 . 3}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-8,
   {3, {(-1) . 1}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-1m,
   {3, {(-2) . 1}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-2m,
   {3, {(-2) . 2}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-3m,
   {3, {(-3) . 1}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-4m,
   {3, {(-3) . 2}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-5m,
   {3, {(-4) . 1}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-6m,
   {3, {(-4) . 2}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-7m,
   {3, {(-4) . 3}, 2, 'greaterp} . 'vsub!-3!-1!-greaterp!-8m,

   % 3, 2, geq
   {3, {1 . 1}, 2, 'geq} . 'vsub!-3!-1!-geq!-1,
   {3, {2 . 1}, 2, 'geq} . 'vsub!-3!-1!-geq!-2,
   {3, {2 . 2}, 2, 'geq} . 'vsub!-3!-1!-geq!-3,
   {3, {3 . 1}, 2, 'geq} . 'vsub!-3!-1!-geq!-4,
   {3, {3 . 2}, 2, 'geq} . 'vsub!-3!-1!-geq!-5,
   {3, {4 . 1}, 2, 'geq} . 'vsub!-3!-1!-geq!-6,
   {3, {4 . 2}, 2, 'geq} . 'vsub!-3!-1!-geq!-7,
   {3, {4 . 3}, 2, 'geq} . 'vsub!-3!-1!-geq!-8,
   {3, {(-1) . 1}, 2, 'geq} . 'vsub!-3!-1!-geq!-1m,
   {3, {(-2) . 1}, 2, 'geq} . 'vsub!-3!-1!-geq!-2m,
   {3, {(-2) . 2}, 2, 'geq} . 'vsub!-3!-1!-geq!-3m,
   {3, {(-3) . 1}, 2, 'geq} . 'vsub!-3!-1!-geq!-4m,
   {3, {(-3) . 2}, 2, 'geq} . 'vsub!-3!-1!-geq!-5m,
   {3, {(-4) . 1}, 2, 'geq} . 'vsub!-3!-1!-geq!-6m,
   {3, {(-4) . 2}, 2, 'geq} . 'vsub!-3!-1!-geq!-7m,
   {3, {(-4) . 3}, 2, 'geq} . 'vsub!-3!-1!-geq!-8m
      };

#endif

% 2, 1, equal

procedure vsub!-2!-1!-equal!-1(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*aa*bb - aa**2*b >= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0
	    )
   end;

procedure vsub!-2!-1!-equal!-2(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*aa*bb - aa**2*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0
	    )
   end;

procedure vsub!-2!-1!-equal!-3(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b = 0
	    )
   end;

procedure vsub!-2!-1!-equal!-1m(g, f, x, theo);
   vsub!-2!-1!-equal!-1(g, negf f, x, theo);

procedure vsub!-2!-1!-equal!-2m(g, f, x, theo);
   vsub!-2!-1!-equal!-2(g, negf f, x, theo);

procedure vsub!-2!-1!-equal!-3m(g, f, x, theo);
   vsub!-2!-1!-equal!-3(g, negf f, x, theo);

procedure vsub!-2!-1!-equal!-4(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*aa*bb - aa**2*b >= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0
	    )
   end;

procedure vsub!-2!-1!-equal!-5(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*aa*bb - aa**2*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0
	    )
   end;

% 2, 1, lessp

procedure vsub!-2!-1!-lessp!-1(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b < 0 and a*bb**2 + aa**2*c - aa*b*bb > 0 or
      	 aa >= 0 and (2*a*bb - aa*b < 0 or a*bb**2 + aa**2*c - aa*b*bb < 0)
	    )
   end;

procedure vsub!-2!-1!-lessp!-2(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b < 0 and a*bb**2 + aa**2*c - aa*b*bb > 0 or
      	 aa <= 0 and (2*a*bb - aa*b < 0 or a*bb**2 + aa**2*c - aa*b*bb < 0)
	    )
   end;

procedure vsub!-2!-1!-lessp!-3(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b < 0
	    )
   end;

procedure vsub!-2!-1!-lessp!-1m(g, f, x, theo);
   vsub!-2!-1!-lessp!-1(g, negf f, x, theo);

procedure vsub!-2!-1!-lessp!-2m(g, f, x, theo);
   vsub!-2!-1!-lessp!-2(g, negf f, x, theo);

procedure vsub!-2!-1!-lessp!-3m(g, f, x, theo);
   vsub!-2!-1!-lessp!-3(g, negf f, x, theo);

procedure vsub!-2!-1!-lessp!-4(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b < 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb > 0 or
      	 a*aa >= 0 and (2*a**2*bb - a*aa*b < 0 or a**2*bb**2 + a*aa**2*c - a*aa*b*bb < 0)
	    )
   end;

procedure vsub!-2!-1!-lessp!-5(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b < 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb > 0 or
      	 a*aa <= 0 and (2*a**2*bb - a*aa*b < 0 or a**2*bb**2 + a*aa**2*c - a*aa*b*bb < 0)
	    )
   end;

% 2, 1, leq

procedure vsub!-2!-1!-leq!-1(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb >= 0 or
      	 aa >= 0 and a*bb**2 + aa**2*c - aa*b*bb <= 0
	    )
   end;

procedure vsub!-2!-1!-leq!-2(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb >= 0 or
      	 aa <= 0 and a*bb**2 + aa**2*c - aa*b*bb <= 0
	    )
   end;

procedure vsub!-2!-1!-leq!-3(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b <= 0
	    )
   end;

procedure vsub!-2!-1!-leq!-1m(g, f, x, theo);
   vsub!-2!-1!-leq!-1(g, negf f, x, theo);

procedure vsub!-2!-1!-leq!-2m(g, f, x, theo);
   vsub!-2!-1!-leq!-2(g, negf f, x, theo);

procedure vsub!-2!-1!-leq!-3m(g, f, x, theo);
   vsub!-2!-1!-leq!-3(g, negf f, x, theo);

procedure vsub!-2!-1!-leq!-4(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b <= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb >= 0 or
      	 a*aa >= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb <= 0
	    )
   end;

procedure vsub!-2!-1!-leq!-5(g, f, x, theo);
   begin scalar aa, bb, a, b, c;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b <= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb >= 0 or
      	 a*aa <= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb <= 0
	    )
   end;

% 2, 1, neq

procedure vsub!-2!-1!-neq!-1(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-equal!-1(g, f, x, theo)});

procedure vsub!-2!-1!-neq!-2(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-equal!-2(g, f, x, theo)});

procedure vsub!-2!-1!-neq!-3(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-equal!-3(g, f, x, theo)});

procedure vsub!-2!-1!-neq!-1m(g, f, x, theo);
   vsub!-2!-1!-neq!-1(g, negf f, x, theo);

procedure vsub!-2!-1!-neq!-2m(g, f, x, theo);
   vsub!-2!-1!-neq!-2(g, negf f, x, theo);

procedure vsub!-2!-1!-neq!-3m(g, f, x, theo);
   vsub!-2!-1!-neq!-3(g, negf f, x, theo);

procedure vsub!-2!-1!-neq!-4(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-equal!-4(g, f, x, theo)});

procedure vsub!-2!-1!-neq!-5(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-equal!-5(g, f, x, theo)});

% 2, 1, greaterp

procedure vsub!-2!-1!-greaterp!-1(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-leq!-1(g, f, x, theo)});

procedure vsub!-2!-1!-greaterp!-2(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-leq!-2(g, f, x, theo)});

procedure vsub!-2!-1!-greaterp!-3(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-leq!-3(g, f, x, theo)});

procedure vsub!-2!-1!-greaterp!-1m(g, f, x, theo);
   vsub!-2!-1!-greaterp!-1(g, negf f, x, theo);

procedure vsub!-2!-1!-greaterp!-2m(g, f, x, theo);
   vsub!-2!-1!-greaterp!-2(g, negf f, x, theo);

procedure vsub!-2!-1!-greaterp!-3m(g, f, x, theo);
   vsub!-2!-1!-greaterp!-3(g, negf f, x, theo);

procedure vsub!-2!-1!-greaterp!-4(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-leq!-4(g, f, x, theo)});

procedure vsub!-2!-1!-greaterp!-5(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-leq!-5(g, f, x, theo)});

% 2, 1, geq

procedure vsub!-2!-1!-geq!-1(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-lessp!-1(g, f, x, theo)});

procedure vsub!-2!-1!-geq!-2(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-lessp!-2(g, f, x, theo)});

procedure vsub!-2!-1!-geq!-3(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-lessp!-3(g, f, x, theo)});

procedure vsub!-2!-1!-geq!-1m(g, f, x, theo);
   vsub!-2!-1!-geq!-1(g, negf f, x, theo);

procedure vsub!-2!-1!-geq!-2m(g, f, x, theo);
   vsub!-2!-1!-geq!-2(g, negf f, x, theo);

procedure vsub!-2!-1!-geq!-3m(g, f, x, theo);
   vsub!-2!-1!-geq!-3(g, negf f, x, theo);

procedure vsub!-2!-1!-geq!-4(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-lessp!-4(g, f, x, theo)});

procedure vsub!-2!-1!-geq!-5(g, f, x, theo);
   rl_mkn('not, {vsub!-2!-1!-lessp!-5(g, f, x, theo)});

% 3, 1, equal

procedure vsub!-3!-1!-equal!-1(g, f, x, theo);
   begin scalar beta;
      beta := vspr_mk(g, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta, theo)
   end;

procedure vsub!-3!-1!-equal!-2(g, f, x, theo);
   begin scalar df, alpha1;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), x, alpha1, theo)
   end;

procedure vsub!-3!-1!-equal!-3(g, f, x, theo);
   begin scalar df, beta, alpha2, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

procedure vsub!-3!-1!-equal!-4(g, f, x, theo);
   begin scalar df, beta, alpha1, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, g), x, alpha1, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

procedure vsub!-3!-1!-equal!-5(g, f, x, theo);
   begin scalar df, alpha2;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), x, alpha2, theo)
   end;

procedure vsub!-3!-1!-equal!-6(g, f, x, theo);
   begin scalar df, beta, alpha1, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, g), x, alpha1, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

procedure vsub!-3!-1!-equal!-7(g, f, x, theo);
   begin scalar df, beta, alpha1, alpha2, w1, w2, w3;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, g), x, alpha2, theo);
      return ofsf_iparse(
	 w1 and w2 and w3
	    )
   end;

procedure vsub!-3!-1!-equal!-8(g, f, x, theo);
   begin scalar df, beta, alpha1, alpha2, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

procedure vsub!-3!-1!-equal!-1m(g, f, x, theo);
   vsub!-3!-1!-equal!-1(g, negf f, x, theo);

procedure vsub!-3!-1!-equal!-2m(g, f, x, theo);
   vsub!-3!-1!-equal!-2(g, negf f, x, theo);

procedure vsub!-3!-1!-equal!-3m(g, f, x, theo);
   vsub!-3!-1!-equal!-3(g, negf f, x, theo);

procedure vsub!-3!-1!-equal!-4m(g, f, x, theo);
   vsub!-3!-1!-equal!-4(g, negf f, x, theo);

procedure vsub!-3!-1!-equal!-5m(g, f, x, theo);
   vsub!-3!-1!-equal!-5(g, negf f, x, theo);

procedure vsub!-3!-1!-equal!-6m(g, f, x, theo);
   vsub!-3!-1!-equal!-6(g, negf f, x, theo);

procedure vsub!-3!-1!-equal!-7m(g, f, x, theo);
   vsub!-3!-1!-equal!-7(g, negf f, x, theo);

procedure vsub!-3!-1!-equal!-8m(g, f, x, theo);
   vsub!-3!-1!-equal!-8(g, negf f, x, theo);

% 3, 1, lessp

procedure vsub!-3!-1!-lessp!-1(g, f, x, theo);
   begin scalar beta;
      beta := vspr_mk(g, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta, theo)
   end;

procedure vsub!-3!-1!-lessp!-2(g, f, x, theo);
   begin scalar df, alpha1;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), x, alpha1, theo)
   end;

procedure vsub!-3!-1!-lessp!-3(g, f, x, theo);
   begin scalar beta;
      beta := vspr_mk(g, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta, theo)
   end;

procedure vsub!-3!-1!-lessp!-4(g, f, x, theo);
   begin scalar df, beta, alpha2, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), x, alpha2, theo);
      return ofsf_iparse(
	 w1 or w2
	    )
   end;

procedure vsub!-3!-1!-lessp!-5(g, f, x, theo);
   begin scalar df, alpha2;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), x, alpha2, theo)
   end;

procedure vsub!-3!-1!-lessp!-6(g, f, x, theo);
   begin scalar df, beta, alpha1, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo);
      return ofsf_iparse(
	 w1 or w2
	    )
   end;

procedure vsub!-3!-1!-lessp!-7(g, f, x, theo);
   begin scalar df, beta, alpha1, alpha2, w1, w2, w3;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), x, beta, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo);
      return ofsf_iparse(
	 w1 or (w2 and w3)
	    )
   end;

procedure vsub!-3!-1!-lessp!-8(g, f, x, theo);
   begin scalar df, beta, alpha2, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

procedure vsub!-3!-1!-lessp!-1m(g, f, x, theo);
   vsub!-3!-1!-lessp!-1(g, negf f, x, theo);

procedure vsub!-3!-1!-lessp!-2m(g, f, x, theo);
   vsub!-3!-1!-lessp!-2(g, negf f, x, theo);

procedure vsub!-3!-1!-lessp!-3m(g, f, x, theo);
   vsub!-3!-1!-lessp!-3(g, negf f, x, theo);

procedure vsub!-3!-1!-lessp!-4m(g, f, x, theo);
   vsub!-3!-1!-lessp!-4(g, negf f, x, theo);

procedure vsub!-3!-1!-lessp!-5m(g, f, x, theo);
   vsub!-3!-1!-lessp!-5(g, negf f, x, theo);

procedure vsub!-3!-1!-lessp!-6m(g, f, x, theo);
   vsub!-3!-1!-lessp!-6(g, negf f, x, theo);

procedure vsub!-3!-1!-lessp!-7m(g, f, x, theo);
   vsub!-3!-1!-lessp!-7(g, negf f, x, theo);

procedure vsub!-3!-1!-lessp!-8m(g, f, x, theo);
   vsub!-3!-1!-lessp!-8(g, negf f, x, theo);

% 3, 1, leq

procedure vsub!-3!-1!-leq!-1(g, f, x, theo);
   begin scalar beta;
      beta := vspr_mk(g, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta, theo)
   end;

procedure vsub!-3!-1!-leq!-2(g, f, x, theo);
   begin scalar df, alpha1;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo)
   end;

procedure vsub!-3!-1!-leq!-3(g, f, x, theo);
   begin scalar df, beta, alpha2, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

procedure vsub!-3!-1!-leq!-4(g, f, x, theo);
   begin scalar beta;
      beta := vspr_mk(g, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta, theo)
   end;

procedure vsub!-3!-1!-leq!-5(g, f, x, theo);
   begin scalar df, alpha2;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo)
   end;

procedure vsub!-3!-1!-leq!-6(g, f, x, theo);
   begin scalar df, beta, alpha1, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo);
      return ofsf_iparse(
	 w1 or w2
	    )
   end;

procedure vsub!-3!-1!-leq!-7(g, f, x, theo);
   begin scalar df, beta, alpha1, alpha2, w1, w2, w3;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), x, beta, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo);
      return ofsf_iparse(
	 w1 or (w2 and w3)
	    )
   end;

procedure vsub!-3!-1!-leq!-8(g, f, x, theo);
   begin scalar df, beta, alpha2, w1, w2;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

% 3, 1, neq

procedure vsub!-3!-1!-neq!-1(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-1(g, f, x, theo)});

procedure vsub!-3!-1!-neq!-2(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-2(g, f, x, theo)});

procedure vsub!-3!-1!-neq!-3(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-3(g, f, x, theo)});

procedure vsub!-3!-1!-neq!-4(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-4(g, f, x, theo)});

procedure vsub!-3!-1!-neq!-5(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-5(g, f, x, theo)});

procedure vsub!-3!-1!-neq!-6(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-6(g, f, x, theo)});

procedure vsub!-3!-1!-neq!-7(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-7(g, f, x, theo)});

procedure vsub!-3!-1!-neq!-8(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-8(g, f, x, theo)});

procedure vsub!-3!-1!-neq!-1m(g, f, x, theo);
   vsub!-3!-1!-neq!-1(g, negf f, x, theo);

procedure vsub!-3!-1!-neq!-2m(g, f, x, theo);
   vsub!-3!-1!-neq!-2(g, negf f, x, theo);

procedure vsub!-3!-1!-neq!-3m(g, f, x, theo);
   vsub!-3!-1!-neq!-3(g, negf f, x, theo);

procedure vsub!-3!-1!-neq!-4m(g, f, x, theo);
   vsub!-3!-1!-neq!-4(g, negf f, x, theo);

procedure vsub!-3!-1!-neq!-5m(g, f, x, theo);
   vsub!-3!-1!-neq!-5(g, negf f, x, theo);

procedure vsub!-3!-1!-neq!-6m(g, f, x, theo);
   vsub!-3!-1!-neq!-6(g, negf f, x, theo);

procedure vsub!-3!-1!-neq!-7m(g, f, x, theo);
   vsub!-3!-1!-neq!-7(g, negf f, x, theo);

procedure vsub!-3!-1!-neq!-8m(g, f, x, theo);
   vsub!-3!-1!-neq!-8(g, negf f, x, theo);

% 3, 1, greaterp

procedure vsub!-3!-1!-greaterp!-1(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-1(g, f, x, theo)});

procedure vsub!-3!-1!-greaterp!-2(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-2(g, f, x, theo)});

procedure vsub!-3!-1!-greaterp!-3(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-3(g, f, x, theo)});

procedure vsub!-3!-1!-greaterp!-4(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-4(g, f, x, theo)});

procedure vsub!-3!-1!-greaterp!-5(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-5(g, f, x, theo)});

procedure vsub!-3!-1!-greaterp!-6(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-6(g, f, x, theo)});

procedure vsub!-3!-1!-greaterp!-7(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-7(g, f, x, theo)});

procedure vsub!-3!-1!-greaterp!-8(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-8(g, f, x, theo)});

procedure vsub!-3!-1!-greaterp!-1m(g, f, x, theo);
   vsub!-3!-1!-greaterp!-1(g, negf f, x, theo);

procedure vsub!-3!-1!-greaterp!-2m(g, f, x, theo);
   vsub!-3!-1!-greaterp!-2(g, negf f, x, theo);

procedure vsub!-3!-1!-greaterp!-3m(g, f, x, theo);
   vsub!-3!-1!-greaterp!-3(g, negf f, x, theo);

procedure vsub!-3!-1!-greaterp!-4m(g, f, x, theo);
   vsub!-3!-1!-greaterp!-4(g, negf f, x, theo);

procedure vsub!-3!-1!-greaterp!-5m(g, f, x, theo);
   vsub!-3!-1!-greaterp!-5(g, negf f, x, theo);

procedure vsub!-3!-1!-greaterp!-6m(g, f, x, theo);
   vsub!-3!-1!-greaterp!-6(g, negf f, x, theo);

procedure vsub!-3!-1!-greaterp!-7m(g, f, x, theo);
   vsub!-3!-1!-greaterp!-7(g, negf f, x, theo);

procedure vsub!-3!-1!-greaterp!-8m(g, f, x, theo);
   vsub!-3!-1!-greaterp!-8(g, negf f, x, theo);

% 3, 1, geq

procedure vsub!-3!-1!-geq!-1(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-1(g, f, x, theo)});

procedure vsub!-3!-1!-geq!-2(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-2(g, f, x, theo)});

procedure vsub!-3!-1!-geq!-3(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-3(g, f, x, theo)});

procedure vsub!-3!-1!-geq!-4(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-4(g, f, x, theo)});

procedure vsub!-3!-1!-geq!-5(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-5(g, f, x, theo)});

procedure vsub!-3!-1!-geq!-6(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-6(g, f, x, theo)});

procedure vsub!-3!-1!-geq!-7(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-7(g, f, x, theo)});

procedure vsub!-3!-1!-geq!-8(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-8(g, f, x, theo)});

procedure vsub!-3!-1!-geq!-1m(g, f, x, theo);
   vsub!-3!-1!-geq!-1(g, negf f, x, theo);

procedure vsub!-3!-1!-geq!-2m(g, f, x, theo);
   vsub!-3!-1!-geq!-2(g, negf f, x, theo);

procedure vsub!-3!-1!-geq!-3m(g, f, x, theo);
   vsub!-3!-1!-geq!-3(g, negf f, x, theo);

procedure vsub!-3!-1!-geq!-4m(g, f, x, theo);
   vsub!-3!-1!-geq!-4(g, negf f, x, theo);

procedure vsub!-3!-1!-geq!-5m(g, f, x, theo);
   vsub!-3!-1!-geq!-5(g, negf f, x, theo);

procedure vsub!-3!-1!-geq!-6m(g, f, x, theo);
   vsub!-3!-1!-geq!-6(g, negf f, x, theo);

procedure vsub!-3!-1!-geq!-7m(g, f, x, theo);
   vsub!-3!-1!-geq!-7(g, negf f, x, theo);

procedure vsub!-3!-1!-geq!-8m(g, f, x, theo);
   vsub!-3!-1!-geq!-8(g, negf f, x, theo);

% 3, 2, equal

procedure vsub!-3!-2!-equal!-1(g, f, x, theo);
   begin scalar beta1, beta2, guard, w1, w2;
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2)
	    )
   end;

procedure vsub!-3!-2!-equal!-2(g, f, x, theo);
   begin scalar df, alpha1;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), x, alpha1, theo)
   end;

procedure vsub!-3!-2!-equal!-3(g, f, x, theo);
   begin scalar ddf, beta1, beta2, guard, w1, w2, w3, w4;
      ddf := diff(diff(f, x), x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), x, beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or (w3 and w4))
	    )
   end;

procedure vsub!-3!-2!-equal!-4(g, f, x, theo);
   begin scalar ddf, beta1, beta2, guard, w1, w2, w3, w4;
      ddf := diff(diff(f, x), x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), x, beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or (w3 and w4))
	    )
   end;

procedure vsub!-3!-2!-equal!-5(g, f, x, theo);
   begin scalar df, alpha2;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), x, alpha2, theo)
   end;

procedure vsub!-3!-2!-equal!-6(g, f, x, theo);
   begin scalar df, ddf, beta1, beta2, guard, w1, w2, w3, w4, w5, w6;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), x, beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), x, beta2, theo);
      w6 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), x, beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2 and w3) or (w4 and w5 and w6))
	    )
   end;

procedure vsub!-3!-2!-equal!-7(g, f, x, theo);
   begin scalar df, beta1, beta2, guard, w1, w2, w3, w4;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), x, beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or (w3 and w4))
	    )
   end;

procedure vsub!-3!-2!-equal!-8(g, f, x, theo);
   begin scalar df, ddf, beta1, beta2, guard, w1, w2, w3, w4, w5, w6;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), x, beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), x, beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), x, beta2, theo);
      w6 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), x, beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2 and w3) or (w4 and w5 and w6))
	    )
   end;

procedure vsub!-3!-2!-equal!-1m(g, f, x, theo);
   vsub!-3!-2!-equal!-1(g, negf f, x, theo);

procedure vsub!-3!-2!-equal!-2m(g, f, x, theo);
   vsub!-3!-2!-equal!-2(g, negf f, x, theo);

procedure vsub!-3!-2!-equal!-3m(g, f, x, theo);
   vsub!-3!-2!-equal!-3(g, negf f, x, theo);

procedure vsub!-3!-2!-equal!-4m(g, f, x, theo);
   vsub!-3!-2!-equal!-4(g, negf f, x, theo);

procedure vsub!-3!-2!-equal!-5m(g, f, x, theo);
   vsub!-3!-2!-equal!-5(g, negf f, x, theo);

procedure vsub!-3!-2!-equal!-6m(g, f, x, theo);
   vsub!-3!-2!-equal!-6(g, negf f, x, theo);

procedure vsub!-3!-2!-equal!-7m(g, f, x, theo);
   vsub!-3!-2!-equal!-7(g, negf f, x, theo);

procedure vsub!-3!-2!-equal!-8m(g, f, x, theo);
   vsub!-3!-2!-equal!-8(g, negf f, x, theo);

% 3, 2, lessp

procedure vsub!-3!-2!-lessp!-1(g, f, x, theo);
   begin scalar beta1, beta2, guard, w1, w2;
      beta1 := vspr_mk(g, x, {1 . 1});
      beta2 := vspr_mk(g, x, {1 . 2});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta2, theo);
      return ofsf_iparse(
	 guard and w1 and w2
	    )
   end;

procedure vsub!-3!-2!-lessp!-2(g, f, x, theo);
   begin scalar df, alpha1;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), x, alpha1, theo)
   end;

procedure vsub!-3!-2!-lessp!-3(g, f, x, theo);
   begin scalar df, beta1, beta2, guard, w1, w2, w3;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1});
      beta2 := vspr_mk(g, x, {1 . 2});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, df), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and w3
	    )
   end;

procedure vsub!-3!-2!-lessp!-4(g, f, x, theo);
   begin scalar df, beta1, beta2, guard, w1, w2, w3;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1});
      beta2 := vspr_mk(g, x, {1 . 2});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta2, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, df), x, beta2, theo);
      return ofsf_iparse(
	 guard and w1 and (w2 or w3)
	    )
   end;

procedure vsub!-3!-2!-lessp!-5(g, f, x, theo);
   begin scalar df, alpha2;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), x, alpha2, theo)
   end;

procedure vsub!-3!-2!-lessp!-6(g, f, x, theo);
   begin scalar df, ddf, beta1, beta2, alpha1, guard, w1, w2, w3, w4, w5;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1});
      beta2 := vspr_mk(g, x, {1 . 2});
      alpha1 := vspr_mk(df, x, {1 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), x, beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo);
      return ofsf_iparse(
	 guard and w1 and w2 and w3 and (w4 or w5)
	    )
   end;

procedure vsub!-3!-2!-lessp!-7(g, f, x, theo);
   begin scalar df, beta1, beta2, alpha1, alpha2, guard, w1, w2, w3, w4;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1});
      beta2 := vspr_mk(g, x, {1 . 2});
      alpha1 := vspr_mk(df, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), x, beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and (w3 or w4)
	    )
   end;

procedure vsub!-3!-2!-lessp!-8(g, f, x, theo);
   begin scalar df, ddf, beta1, beta2, alpha2, guard, w1, w2, w3, w4, w5;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1});
      beta2 := vspr_mk(g, x, {1 . 2});
      alpha2 := vspr_mk(df, x, {1 . 2});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), x, beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), x, beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), x, beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and (w3 and w4 and w5)
	    )
   end;

procedure vsub!-3!-2!-lessp!-1m(g, f, x, theo);
   vsub!-3!-2!-lessp!-1(g, negf f, x, theo);

procedure vsub!-3!-2!-lessp!-2m(g, f, x, theo);
   vsub!-3!-2!-lessp!-2(g, negf f, x, theo);

procedure vsub!-3!-2!-lessp!-3m(g, f, x, theo);
   vsub!-3!-2!-lessp!-3(g, negf f, x, theo);

procedure vsub!-3!-2!-lessp!-4m(g, f, x, theo);
   vsub!-3!-2!-lessp!-4(g, negf f, x, theo);

procedure vsub!-3!-2!-lessp!-5m(g, f, x, theo);
   vsub!-3!-2!-lessp!-5(g, negf f, x, theo);

procedure vsub!-3!-2!-lessp!-6m(g, f, x, theo);
   vsub!-3!-2!-lessp!-6(g, negf f, x, theo);

procedure vsub!-3!-2!-lessp!-7m(g, f, x, theo);
   vsub!-3!-2!-lessp!-7(g, negf f, x, theo);

procedure vsub!-3!-2!-lessp!-8m(g, f, x, theo);
   vsub!-3!-2!-lessp!-8(g, negf f, x, theo);

% 3, 2, leq

procedure vsub!-3!-2!-leq!-1(g, f, x, theo);
   begin scalar beta1, beta2, guard, w1, w2;
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta2, theo);
      return ofsf_iparse(
	 guard and w1 and w2
	    )
   end;

procedure vsub!-3!-2!-leq!-2(g, f, x, theo);
   begin scalar df, alpha1;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo)
   end;

procedure vsub!-3!-2!-leq!-3(g, f, x, theo);
   begin scalar beta1, beta2, guard, w1, w2;
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta2, theo);
      return ofsf_iparse(
	 guard and w1 and w2
	    )
   end;

procedure vsub!-3!-2!-leq!-4(g, f, x, theo);
   begin scalar ddf, beta1, beta2, guard, w1, w2, w3;
      ddf := diff(diff(f, x), x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta2, theo);
      return ofsf_iparse(
	 guard and w1 and w2 and w3
	    )
   end;

procedure vsub!-3!-2!-leq!-5(g, f, x, theo);
   begin scalar df, alpha2;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2});
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo)
   end;

procedure vsub!-3!-2!-leq!-6(g, f, x, theo);
   begin scalar df, ddf, beta1, beta2, alpha1, guard, w1, w2, w3, w4, w5;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), x, beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo);
      return ofsf_iparse(
	 guard and w1 and w2 and w3 and (w4 or w5)
	    )
   end;

procedure vsub!-3!-2!-leq!-7(g, f, x, theo);
   begin scalar df, beta1, beta2, alpha1, alpha2, guard, w1, w2, w3, w4, w5;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      alpha1 := vspr_mk(df, x, {1 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), x, beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), x, beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or w3) and (w4 or w5)
	    )
   end;

procedure vsub!-3!-2!-leq!-8(g, f, x, theo);
   begin scalar df, ddf, beta1, beta2, alpha2, guard, w1, w2, w3, w4, w5;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1});
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1});
      alpha2 := vspr_mk(df, x, {1 . 2});
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), x, beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), x, alpha2, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), x, beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), x, beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), x, beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and w3 and w4 and w5
	    )
   end;

procedure vsub!-3!-2!-leq!-1m(g, f, x, theo);
   vsub!-3!-2!-leq!-1(g, negf f, x, theo);

procedure vsub!-3!-2!-leq!-2m(g, f, x, theo);
   vsub!-3!-2!-leq!-2(g, negf f, x, theo);

procedure vsub!-3!-2!-leq!-3m(g, f, x, theo);
   vsub!-3!-2!-leq!-3(g, negf f, x, theo);

procedure vsub!-3!-2!-leq!-4m(g, f, x, theo);
   vsub!-3!-2!-leq!-4(g, negf f, x, theo);

procedure vsub!-3!-2!-leq!-5m(g, f, x, theo);
   vsub!-3!-2!-leq!-5(g, negf f, x, theo);

procedure vsub!-3!-2!-leq!-6m(g, f, x, theo);
   vsub!-3!-2!-leq!-6(g, negf f, x, theo);

procedure vsub!-3!-2!-leq!-7m(g, f, x, theo);
   vsub!-3!-2!-leq!-7(g, negf f, x, theo);

procedure vsub!-3!-2!-leq!-8m(g, f, x, theo);
   vsub!-3!-2!-leq!-8(g, negf f, x, theo);

% 3, 2, neq

procedure vsub!-3!-2!-neq!-1(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-1(g, f, x, theo)});

procedure vsub!-3!-2!-neq!-2(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-2(g, f, x, theo)});

procedure vsub!-3!-2!-neq!-3(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-3(g, f, x, theo)});

procedure vsub!-3!-2!-neq!-4(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-4(g, f, x, theo)});

procedure vsub!-3!-2!-neq!-5(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-5(g, f, x, theo)});

procedure vsub!-3!-2!-neq!-6(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-6(g, f, x, theo)});

procedure vsub!-3!-2!-neq!-7(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-7(g, f, x, theo)});

procedure vsub!-3!-2!-neq!-8(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-equal!-8(g, f, x, theo)});

procedure vsub!-3!-2!-neq!-1m(g, f, x, theo);
   vsub!-3!-2!-neq!-1(g, negf f, x, theo);

procedure vsub!-3!-2!-neq!-2m(g, f, x, theo);
   vsub!-3!-2!-neq!-2(g, negf f, x, theo);

procedure vsub!-3!-2!-neq!-3m(g, f, x, theo);
   vsub!-3!-2!-neq!-3(g, negf f, x, theo);

procedure vsub!-3!-2!-neq!-4m(g, f, x, theo);
   vsub!-3!-2!-neq!-4(g, negf f, x, theo);

procedure vsub!-3!-2!-neq!-5m(g, f, x, theo);
   vsub!-3!-2!-neq!-5(g, negf f, x, theo);

procedure vsub!-3!-2!-neq!-6m(g, f, x, theo);
   vsub!-3!-2!-neq!-6(g, negf f, x, theo);

procedure vsub!-3!-2!-neq!-7m(g, f, x, theo);
   vsub!-3!-2!-neq!-7(g, negf f, x, theo);

procedure vsub!-3!-2!-neq!-8m(g, f, x, theo);
   vsub!-3!-2!-neq!-8(g, negf f, x, theo);

% 3, 2, greaterp

procedure vsub!-3!-2!-greaterp!-1(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-1(g, f, x, theo)});

procedure vsub!-3!-2!-greaterp!-2(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-2(g, f, x, theo)});

procedure vsub!-3!-2!-greaterp!-3(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-3(g, f, x, theo)});

procedure vsub!-3!-2!-greaterp!-4(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-4(g, f, x, theo)});

procedure vsub!-3!-2!-greaterp!-5(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-5(g, f, x, theo)});

procedure vsub!-3!-2!-greaterp!-6(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-6(g, f, x, theo)});

procedure vsub!-3!-2!-greaterp!-7(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-7(g, f, x, theo)});

procedure vsub!-3!-2!-greaterp!-8(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-leq!-8(g, f, x, theo)});

procedure vsub!-3!-2!-greaterp!-1m(g, f, x, theo);
   vsub!-3!-2!-greaterp!-1(g, negf f, x, theo);

procedure vsub!-3!-2!-greaterp!-2m(g, f, x, theo);
   vsub!-3!-2!-greaterp!-2(g, negf f, x, theo);

procedure vsub!-3!-2!-greaterp!-3m(g, f, x, theo);
   vsub!-3!-2!-greaterp!-3(g, negf f, x, theo);

procedure vsub!-3!-2!-greaterp!-4m(g, f, x, theo);
   vsub!-3!-2!-greaterp!-4(g, negf f, x, theo);

procedure vsub!-3!-2!-greaterp!-5m(g, f, x, theo);
   vsub!-3!-2!-greaterp!-5(g, negf f, x, theo);

procedure vsub!-3!-2!-greaterp!-6m(g, f, x, theo);
   vsub!-3!-2!-greaterp!-6(g, negf f, x, theo);

procedure vsub!-3!-2!-greaterp!-7m(g, f, x, theo);
   vsub!-3!-2!-greaterp!-7(g, negf f, x, theo);

procedure vsub!-3!-2!-greaterp!-8m(g, f, x, theo);
   vsub!-3!-2!-greaterp!-8(g, negf f, x, theo);

% 3, 2, geq

procedure vsub!-3!-2!-geq!-1(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-1(g, f, x, theo)});

procedure vsub!-3!-2!-geq!-2(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-2(g, f, x, theo)});

procedure vsub!-3!-2!-geq!-3(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-3(g, f, x, theo)});

procedure vsub!-3!-2!-geq!-4(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-4(g, f, x, theo)});

procedure vsub!-3!-2!-geq!-5(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-5(g, f, x, theo)});

procedure vsub!-3!-2!-geq!-6(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-6(g, f, x, theo)});

procedure vsub!-3!-2!-geq!-7(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-7(g, f, x, theo)});

procedure vsub!-3!-2!-geq!-8(g, f, x, theo);
   rl_mkn('not, {vsub!-3!-1!-lessp!-8(g, f, x, theo)});

procedure vsub!-3!-2!-geq!-1m(g, f, x, theo);
   vsub!-3!-2!-geq!-1(g, negf f, x, theo);

procedure vsub!-3!-2!-geq!-2m(g, f, x, theo);
   vsub!-3!-2!-geq!-2(g, negf f, x, theo);

procedure vsub!-3!-2!-geq!-3m(g, f, x, theo);
   vsub!-3!-2!-geq!-3(g, negf f, x, theo);

procedure vsub!-3!-2!-geq!-4m(g, f, x, theo);
   vsub!-3!-2!-geq!-4(g, negf f, x, theo);

procedure vsub!-3!-2!-geq!-5m(g, f, x, theo);
   vsub!-3!-2!-geq!-5(g, negf f, x, theo);

procedure vsub!-3!-2!-geq!-6m(g, f, x, theo);
   vsub!-3!-2!-geq!-6(g, negf f, x, theo);

procedure vsub!-3!-2!-geq!-7m(g, f, x, theo);
   vsub!-3!-2!-geq!-7(g, negf f, x, theo);

procedure vsub!-3!-2!-geq!-8m(g, f, x, theo);
   vsub!-3!-2!-geq!-8(g, negf f, x, theo);

asserted procedure vsub_compute!-rsl(op: Id, f: SF, x: Kernel, s: Any): Any;
   % Compute root specification list. [op] is an operator, [x] is
   % [mvar f], [s] is the sign of [lc f]. Returns either ['fail] or an
   % AList [al] containing elements [pr] such that [car pr] is one of
   % ['(ip ep slb wlb sub wub)] and [cdr pr] is a list of root
   % specification lists.
   begin scalar w;
      assert(sfto_mvartest(f, x));
      w := if rlclustering!* then
	 assoc({ldeg f, s, op}, rsl!-alist!-clustering!*)
      else
      	 assoc({ldeg f, s, op}, rsl!-alist!*);
      if null w then
	 return 'failed;
      return cdr w
   end;

asserted procedure vsub_guard(pr: VSpr): QfFormula;
   % Guard. Returns a guard of [pr].
   begin scalar f, rtl, w;
      f := vspr_f pr;
      assert(sfto_mvartest(f, vspr_v pr));
      rtl := vspr_rtl pr;
      w := assoc({ldeg f, rtl}, guard!-fnalist!*);
      if null w then <<
	 assert(nil);
	 return 'failed
      >>;
      return apply(cdr w, {f})
   end;

asserted procedure vsub_vsub(op: Id, g: SF, x: Kernel, pr: VSpr, theo: Theory): QfFormula;
   % Virtual substitution. [op] is an operator. Returns an equivalent
   % of (g op 0)[x // (f, S)], where (f, S) is a parametric root
   % specification described by [pr].
   begin scalar f, w;
      f := vspr_f pr;
      assert(sfto_mvartest(f, x));
      if not sfto_mvartest(g, x) then
	 return ofsf_0mk2(op, g);
      w := assoc({ldeg f, vspr_rsl pr, ldeg g, op}, vsub!-fnalist!*);
      if null w then <<
	 assert(nil);
	 return 'failed
      >>;
      return apply(cdr w, {g, f, x, theo})
   end;

endmodule;  % [ofsfvslists]

end;  % of file
