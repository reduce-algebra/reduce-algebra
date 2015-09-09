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

ofsfform procedure guard!-1!-1m(a, b);
   a < 0;

ofsfform procedure guard!-1!-1(a, b);
   a > 0;

ofsfform procedure guard!-1!-2(a, b);
   a <> 0;

ofsfform procedure guard!-2!-2m(a, b, c);
   a < 0 and b^2 - 4*a*c = 0;

ofsfform procedure guard!-2!-1m(a, b, c);
   a < 0 and b^2 - 4*a*c > 0;

ofsfform procedure guard!-2!-1(a, b, c);
   a > 0 and b^2 - 4*a*c > 0;

ofsfform procedure guard!-2!-2(a, b, c);
   a > 0 and b^2 - 4*a*c = 0;

ofsfform procedure guard!-2!-3m(a, b, c);
   a < 0 and b^2 - 4*a*c >= 0;

ofsfform procedure guard!-2!-3(a, b, c);
   a > 0 and b^2 - 4*a*c >= 0;

ofsfform procedure guard!-2!-4(a, b, c);
   a <> 0 and b^2 - 4*a*c >= 0;

ofsfform procedure guard!-3!-4m(a, b, c, d);
   a < 0 and -b^2 + 3*a*c < 0 and
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d < 0;

ofsfform procedure guard!-3!-3m(a, b, c, d);
   a < 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c < 0 and
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0;

ofsfform procedure guard!-3!-2m(a, b, c, d);
   a < 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c > 0 and
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0;

ofsfform procedure guard!-3!-1m(a, b, c, d);
   a < 0 and (-b^2 + 3*a*c >= 0 or
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d > 0);

ofsfform procedure guard!-3!-1(a, b, c, d);
   a > 0 and (-b^2 + 3*a*c >= 0 or
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d > 0);

ofsfform procedure guard!-3!-2(a, b, c, d);
   a > 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c < 0 and
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0;

ofsfform procedure guard!-3!-3(a, b, c, d);
   a > 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c > 0 and
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0;

ofsfform procedure guard!-3!-4(a, b, c, d);
   a > 0 and -b^2 + 3*a*c < 0 and
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d < 0;

ofsfform procedure guard!-3!-5m(a, b, c, d);
   a < 0 and -b^2 + 3*a*c < 0 and
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d <= 0;

ofsfform procedure guard!-3!-5(a, b, c, d);
   a > 0 and -b^2 + 3*a*c < 0 and
      -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d <= 0;

vsub!-fnalist!* := {
   % key: {ldeg f, rsl, ldeg g, op}
   % value: virtual substitution constructing function

   % equal
   {2, {(-2) . 1}, 1, 'equal} . 'vsub!-2!-equal!-1,
   {2, {(-1) . 1}, 1, 'equal} . 'vsub!-2!-equal!-2,
   {2, {(-1) . 2}, 1, 'equal} . 'vsub!-2!-equal!-3,
   {2, {1 . 1}, 1, 'equal} . 'vsub!-2!-equal!-4,
   {2, {1 . 2}, 1, 'equal} . 'vsub!-2!-equal!-5,
   {2, {2 . 1}, 1, 'equal} . 'vsub!-2!-equal!-6,
   % for clustering:
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'equal} . 'vsub!-2!-equal!-7,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'equal} . 'vsub!-2!-equal!-8,
   {2, {(-1) . 1, (-2) . 1}, 1, 'equal} . 'vsub!-2!-equal!-2,
   {2, {(-1) . 2, (-2) . 1}, 1, 'equal} . 'vsub!-2!-equal!-3,
   {2, {1 . 1, 2 . 1}, 1, 'equal} . 'vsub!-2!-equal!-4,
   {2, {1 . 2, 2 . 1}, 1, 'equal} . 'vsub!-2!-equal!-5,

   % neq
   {2, {(-2) . 1}, 1, 'neq} . 'vsub!-2!-neq!-1,
   {2, {(-1) . 1}, 1, 'neq} . 'vsub!-2!-neq!-2,
   {2, {(-1) . 2}, 1, 'neq} . 'vsub!-2!-neq!-3,
   {2, {1 . 1}, 1, 'neq} . 'vsub!-2!-neq!-4,
   {2, {1 . 2}, 1, 'neq} . 'vsub!-2!-neq!-5,
   {2, {2 . 1}, 1, 'neq} . 'vsub!-2!-neq!-6,
   % for clustering:
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'neq} . 'vsub!-2!-neq!-7,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'neq} . 'vsub!-2!-neq!-8,
   {2, {(-1) . 1, (-2) . 1}, 1, 'neq} . 'vsub!-2!-neq!-2,
   {2, {(-1) . 2, (-2) . 1}, 1, 'neq} . 'vsub!-2!-neq!-3,
   {2, {1 . 1, 2 . 1}, 1, 'neq} . 'vsub!-2!-neq!-4,
   {2, {1 . 2, 2 . 1}, 1, 'neq} . 'vsub!-2!-neq!-5,

   % lessp
   {2, {(-2) . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-1,
   {2, {(-1) . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-2,
   {2, {(-1) . 2}, 1, 'lessp} . 'vsub!-2!-lessp!-3,
   {2, {1 . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-4,
   {2, {1 . 2}, 1, 'lessp} . 'vsub!-2!-lessp!-5,
   {2, {2 . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-6,
   % for clustering:
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-7,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-8,
   {2, {(-1) . 1, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-2,
   {2, {(-1) . 2, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-3,
   {2, {1 . 1, 2 . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-4,
   {2, {1 . 2, 2 . 1}, 1, 'lessp} . 'vsub!-2!-lessp!-5,

   % leq
   {2, {(-2) . 1}, 1, 'leq} . 'vsub!-2!-leq!-1,
   {2, {(-1) . 1}, 1, 'leq} . 'vsub!-2!-leq!-2,
   {2, {(-1) . 2}, 1, 'leq} . 'vsub!-2!-leq!-3,
   {2, {1 . 1}, 1, 'leq} . 'vsub!-2!-leq!-4,
   {2, {1 . 2}, 1, 'leq} . 'vsub!-2!-leq!-5,
   {2, {2 . 1}, 1, 'leq} . 'vsub!-2!-leq!-6,
   % for clustering:
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'leq} . 'vsub!-2!-leq!-7,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'leq} . 'vsub!-2!-leq!-8,
   {2, {(-1) . 1, (-2) . 1}, 1, 'leq} . 'vsub!-2!-leq!-2,
   {2, {(-1) . 2, (-2) . 1}, 1, 'leq} . 'vsub!-2!-leq!-3,
   {2, {1 . 1, 2 . 1}, 1, 'leq} . 'vsub!-2!-leq!-4,
   {2, {1 . 2, 2 . 1}, 1, 'leq} . 'vsub!-2!-leq!-5,

   % geq
   {2, {(-2) . 1}, 1, 'geq} . 'vsub!-2!-geq!-1,
   {2, {(-1) . 1}, 1, 'geq} . 'vsub!-2!-geq!-2,
   {2, {(-1) . 2}, 1, 'geq} . 'vsub!-2!-geq!-3,
   {2, {1 . 1}, 1, 'geq} . 'vsub!-2!-geq!-4,
   {2, {1 . 2}, 1, 'geq} . 'vsub!-2!-geq!-5,
   {2, {2 . 1}, 1, 'geq} . 'vsub!-2!-geq!-6,
   % for clustering:
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'geq} . 'vsub!-2!-geq!-7,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'geq} . 'vsub!-2!-geq!-8,
   {2, {(-1) . 1, (-2) . 1}, 1, 'geq} . 'vsub!-2!-geq!-2,
   {2, {(-1) . 2, (-2) . 1}, 1, 'geq} . 'vsub!-2!-geq!-3,
   {2, {1 . 1, 2 . 1}, 1, 'geq} . 'vsub!-2!-geq!-4,
   {2, {1 . 2, 2 . 1}, 1, 'geq} . 'vsub!-2!-geq!-5,

   % greaterp
   {2, {(-2) . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-1,
   {2, {(-1) . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-2,
   {2, {(-1) . 2}, 1, 'greaterp} . 'vsub!-2!-greaterp!-3,
   {2, {1 . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-4,
   {2, {1 . 2}, 1, 'greaterp} . 'vsub!-2!-greaterp!-5,
   {2, {2 . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-6,
   % for clustering:
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-7,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-8,
   {2, {(-1) . 1, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-2,
   {2, {(-1) . 2, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-3,
   {2, {1 . 1, 2 . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-4,
   {2, {1 . 2, 2 . 1}, 1, 'greaterp} . 'vsub!-2!-greaterp!-5
      };

% equal

ofsfform procedure vsub!-2!-equal!-1(a, b, c, aa, bb);
   2*a*bb - aa*b = 0;

ofsfform procedure vsub!-2!-equal!-2(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0;

ofsfform procedure vsub!-2!-equal!-3(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0;

ofsfform procedure vsub!-2!-equal!-4(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b >= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0;

ofsfform procedure vsub!-2!-equal!-5(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0;

ofsfform procedure vsub!-2!-equal!-6(a, b, c, aa, bb);
   2*a*bb - aa*b = 0;

ofsfform procedure vsub!-2!-equal!-7(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b >= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0;

ofsfform procedure vsub!-2!-equal!-8(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0;

% neq

ofsfform procedure vsub!-2!-neq!-1(a, b, c, aa, bb);
   2*a*bb - aa*b <> 0;

ofsfform procedure vsub!-2!-neq!-2(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b > 0 or a*bb**2 + aa**2*c - aa*b*bb <> 0;

ofsfform procedure vsub!-2!-neq!-3(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b < 0 or a*bb**2 + aa**2*c - aa*b*bb <> 0;

ofsfform procedure vsub!-2!-neq!-4(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b < 0 or a*bb**2 + aa**2*c - aa*b*bb <> 0;

ofsfform procedure vsub!-2!-neq!-5(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b > 0 or a*bb**2 + aa**2*c - aa*b*bb <> 0;

ofsfform procedure vsub!-2!-neq!-6(a, b, c, aa, bb);
   2*a*bb - aa*b <> 0;

ofsfform procedure vsub!-2!-neq!-7(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b < 0 or a*bb**2 + aa**2*c - aa*b*bb <> 0;

ofsfform procedure vsub!-2!-neq!-8(a, b, c, aa, bb);
   2*a*aa*bb - aa**2*b > 0 or a*bb**2 + aa**2*c - aa*b*bb <> 0;

% lessp

ofsfform procedure vsub!-2!-lessp!-1(a, b, c, aa, bb);
   2*a*bb - aa*b > 0;

ofsfform procedure vsub!-2!-lessp!-2(a, b, c, aa, bb);
   2*a*bb - aa*b > 0 and a*bb**2 + aa**2*c - aa*b*bb < 0 or
      aa >= 0 and (2*a*bb - aa*b > 0 or a*bb**2 + aa**2*c - aa*b*bb > 0);

ofsfform procedure vsub!-2!-lessp!-3(a, b, c, aa, bb);
   2*a*bb - aa*b > 0 and a*bb**2 + aa**2*c - aa*b*bb < 0 or
      aa <= 0 and (2*a*bb - aa*b > 0 or a*bb**2 + aa**2*c - aa*b*bb > 0);

ofsfform procedure vsub!-2!-lessp!-4(a, b, c, aa, bb);
   2*a*bb - aa*b < 0 and a*bb**2 + aa**2*c - aa*b*bb > 0 or
      aa >= 0 and (2*a*bb - aa*b < 0 or a*bb**2 + aa**2*c - aa*b*bb < 0);

ofsfform procedure vsub!-2!-lessp!-5(a, b, c, aa, bb);
   2*a*bb - aa*b < 0 and a*bb**2 + aa**2*c - aa*b*bb > 0 or
      aa <= 0 and (2*a*bb - aa*b < 0 or a*bb**2 + aa**2*c - aa*b*bb < 0);

ofsfform procedure vsub!-2!-lessp!-6(a, b, c, aa, bb);
   2*a*bb - aa*b < 0;

ofsfform procedure vsub!-2!-lessp!-7(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b < 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb > 0 or
      a*aa >= 0 and (2*a**2*bb - a*aa*b < 0 or a**2*bb**2 + a*aa**2*c - a*aa*b*bb < 0);

ofsfform procedure vsub!-2!-lessp!-8(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b < 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb > 0 or
      a*aa <= 0 and (2*a**2*bb - a*aa*b < 0 or a**2*bb**2 + a*aa**2*c - a*aa*b*bb < 0);

% leq

ofsfform procedure vsub!-2!-leq!-1(a, b, c, aa, bb);
   2*a*bb - aa*b >= 0;

ofsfform procedure vsub!-2!-leq!-2(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb <= 0 or
      aa >= 0 and a*bb**2 + aa**2*c - aa*b*bb >= 0;

ofsfform procedure vsub!-2!-leq!-3(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb <= 0 or
      aa <= 0 and a*bb**2 + aa**2*c - aa*b*bb >= 0;

ofsfform procedure vsub!-2!-leq!-4(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb >= 0 or
      aa >= 0 and a*bb**2 + aa**2*c - aa*b*bb <= 0;

ofsfform procedure vsub!-2!-leq!-5(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb >= 0 or
      aa <= 0 and a*bb**2 + aa**2*c - aa*b*bb <= 0;

ofsfform procedure vsub!-2!-leq!-6(a, b, c, aa, bb);
   2*a*bb - aa*b <= 0;

ofsfform procedure vsub!-2!-leq!-7(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b <= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb >= 0 or
      a*aa >= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb <= 0;

ofsfform procedure vsub!-2!-leq!-8(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b <= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb >= 0 or
      a*aa <= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb <= 0;

% geq

ofsfform procedure vsub!-2!-geq!-1(a, b, c, aa, bb);
   2*a*bb - aa*b <= 0;

ofsfform procedure vsub!-2!-geq!-2(a, b, c, aa, bb);
   a*bb**2 - aa**2*c - aa*b*bb >= 0 and 2*a**2*bb - a*aa*b <= 0 or
      aa >= 0 and a*bb**2 - aa**2*c - aa*b*bb <= 0;

ofsfform procedure vsub!-2!-geq!-3(a, b, c, aa, bb);
   a*bb**2 - aa**2*c - aa*b*bb >= 0 and 2*a**2*bb - a*aa*b <= 0 or
      aa <= 0 and a*bb**2 - aa**2*c - aa*b*bb <= 0;

ofsfform procedure vsub!-2!-geq!-4(a, b, c, aa, bb);
   a*bb**2 - aa**2*c - aa*b*bb <= 0 and 2*a**2*bb - a*aa*b <= 0 or
      aa >= 0 and a*bb**2 - aa**2*c - aa*b*bb >= 0;

ofsfform procedure vsub!-2!-geq!-5(a, b, c, aa, bb);
   a*bb**2 - aa**2*c - aa*b*bb <= 0 and 2*a**2*bb - a*aa*b <= 0 or
      aa <= 0 and a*bb**2 - aa**2*c - aa*b*bb >= 0;

ofsfform procedure vsub!-2!-geq!-6(a, b, c, aa, bb);
   2*a*bb - aa*b >= 0;

ofsfform procedure vsub!-2!-geq!-7(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b <= 0 and a**2*bb**2 - a*aa**2*c - a*aa*b*bb >= 0 or
      a*aa <= 0 and a**2*bb**2 - a*aa**2*c - a*aa*b*bb <= 0;

ofsfform procedure vsub!-2!-geq!-8(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b <= 0 and a**2*bb**2 - a*aa**2*c - a*aa*b*bb >= 0 or
      a*aa >= 0 and a**2*bb**2 - a*aa**2*c - a*aa*b*bb <= 0;

% greaterp

ofsfform procedure vsub!-2!-greaterp!-1(a, b, c, aa, bb);
   2*a*bb - aa*b < 0;

ofsfform procedure vsub!-2!-greaterp!-2(a, b, c, aa, bb);
   2*a*bb - aa*b < 0 and a*bb**2 - aa**2*c - aa*b*bb > 0 or
      aa >= 0 and (2*a*bb - aa*b < 0 or a*bb**2 - aa**2*c - aa*b*bb < 0);

ofsfform procedure vsub!-2!-greaterp!-3(a, b, c, aa, bb);
   2*a*bb - aa*b < 0 and a*bb**2 - aa**2*c - aa*b*bb > 0 or
      aa <= 0 and (2*a*bb - aa*b < 0 or a*bb**2 - aa**2*c - aa*b*bb < 0);

ofsfform procedure vsub!-2!-greaterp!-4(a, b, c, aa, bb);
   2*a*bb - aa*b > 0 and a*bb**2 - aa**2*c - aa*b*bb < 0 or
      aa >= 0 and (2*a*bb - aa*b > 0 or a*bb**2 - aa**2*c - aa*b*bb > 0);

ofsfform procedure vsub!-2!-greaterp!-5(a, b, c, aa, bb);
   2*a*bb - aa*b > 0 and a*bb**2 - aa**2*c - aa*b*bb < 0 or
      aa <= 0 and (2*a*bb - aa*b > 0 or a*bb**2 - aa**2*c - aa*b*bb > 0);

ofsfform procedure vsub!-2!-greaterp!-6(a, b, c, aa, bb);
   2*a*bb - aa*b > 0;

ofsfform procedure vsub!-2!-greaterp!-7(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b < 0 and a**2*bb**2 - a*aa**2*c - a*aa*b*bb > 0 or
      a*aa <= 0 and (2*a**2*bb - a*aa*b < 0 or a**2*bb**2 - a*aa**2*c - a*aa*b*bb < 0);

ofsfform procedure vsub!-2!-greaterp!-8(a, b, c, aa, bb);
   2*a**2*bb - a*aa*b < 0 and a**2*bb**2 - a*aa**2*c - a*aa*b*bb > 0 or
      a*aa >= 0 and (2*a**2*bb - a*aa*b < 0 or a**2*bb**2 - a*aa**2*c - a*aa*b*bb < 0);

asserted procedure rsl!-compute(op: Id, f: SF, x: Kernel, s: Any): Any;
   % Root specification list compute. [op] is an operator, [x] is
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

asserted procedure rsl!-guard(f: SF, x: Kernel, rsl: List): QfFormula;
   % Root specification list guard. [x] is [mvar f]; [rsl] is a list
   % of root specifications. Returns a guard of [(f, rsl)].
   begin scalar rtl, w;
      assert(sfto_mvartest(f, x));
      rtl := for each rs in rsl collect car rs;
      % TODO: There could be duplicates in [rtl] in the future. Then
      % you will have to delete them here!
      rtl := sort(rtl, function(lambda(a, b); a < b));
      w := assoc({ldeg f, rtl}, guard!-fnalist!*);
      if null w then <<
	 assert(nil);
	 return 'failed
      >>;
      return apply(cdr w, coeffs f)
   end;

asserted procedure rsl!-vsub(op: Id, g: SF, f: SF, x: Kernel, rsl: List): QfFormula;
   % Root specification list virtual substitution. [op] is an
   % operator; [rsl] is a list of root specifications of [f]. Returns
   % an equivalent of (g op 0)[x // (f, rsl)].
   begin scalar w;
      assert(sfto_mvartest(f, x));
      if not sfto_mvartest(g, x) then
	 return ofsf_0mk2(op, g);
      w := assoc({ldeg f, rsl, ldeg g, op}, vsub!-fnalist!*);
      if null w then <<
	 assert(nil);
	 return 'failed
      >>;
      return apply(cdr w, append(coeffs f, coeffs g))
   end;

endmodule;  % [ofsfvslists]

end;  % of file
