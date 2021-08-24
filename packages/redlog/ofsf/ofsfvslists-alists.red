% This file contains the Alists from ofsfvslists.red in a more
% readable form. Compilation for PSL of these Alists in this form
% causes problems. Therefore, we decided to paste a "static" version
% of these Alists into the file ofsfvslists.red and keep the originals
% here for reference.

% Author: Thomas Sturm

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

% $Id: $



%%% deg-type-code-alist

deg!-type!-code!-alist!* := {
   % key: degree . real type
   % value: real type code
   (1 . {-1, 0, 1}) . 1,
   (1 . {1, 0, -1}) . -1,
   (2 . {1, 0, -1, 0, 1}) . 1,
   (2 . {1, 0, 1}) . 2,
   (2 . {-1, 0, 1, 0, -1}) . -1,
   (2 . {-1, 0, -1}) . -2,
   (3 . {-1, 0, 1}) . 1,
   (3 . {-1, 0, -1, 0, 1}) . 2,
   (3 . {-1, 0, 1, 0, 1}) . 3,
   (3 . {-1, 0, 1, 0, -1, 0, 1}) . 4,
   (3 . {1, 0, -1}) . -1,
   (3 . {1, 0, 1, 0, -1}) . -2,
   (3 . {1, 0, -1, 0, -1}) . -3,
   (3 . {1, 0, -1, 0, 1, 0, -1}) . -4
      };

%%% rsl-alist %%%

rsl!-alist!* := {
   % key: {ldeg f, sign of lc f, op}
   % value: Alist [al] containing elements [pr] such that [car pr] is
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

%%% rsl-alist-clustering %%%

rsl!-alist!-clustering!* := {
   % key: {ldeg f, sign of lc f, op}
   % value: Alist [al] containing elements [pr] such that [car pr] is
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
      'slb . {
	 {(-2) . 1, (-3) . 2, (-4) . 2}
      	    },
      'sub . {
	 {(-1) . 1},
	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, nil, 'greaterp} . {
      'slb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-2) . 1, (-3) . 2, (-4) . 2}
   	    },
      'sub . {
	 {2 . 1, 3 . 2, 4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, 1, 'greaterp} . {
      'slb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3}
      	    },
      'sub . {
	 {2 . 1, 3 . 2, 4 . 2}
	    }
	       }
   		  };

%%% guard-fnalist %%%

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
   {3, '(-4 -3 -2)} . 'guard!-3!-5m,
   {3, '(2 3 4)} . 'guard!-3!-5
      };

%%% vsub-fnalist %%%

vsub!-fnalist!* := {
   % key: {ldeg f, ldeg g, op, rsl of f}
   % value: virtual substitution constructing function

   % 2, 1, equal
   {2, 1, 'equal, {1 . 1}} . 'vsub!-2!-1!-equal!-1,
   {2, 1, 'equal, {1 . 2}} . 'vsub!-2!-1!-equal!-2,
   {2, 1, 'equal, {2 . 1}} . 'vsub!-2!-1!-equal!-3,
   % 2, 1, equal, clustering
   {2, 1, 'equal, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}} . 'vsub!-2!-1!-equal!-4,
   {2, 1, 'equal, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}} . 'vsub!-2!-1!-equal!-5,
   {2, 1, 'equal, {1 . 1, 2 . 1}} . 'vsub!-2!-1!-equal!-1,
   {2, 1, 'equal, {1 . 2, 2 . 1}} . 'vsub!-2!-1!-equal!-2,

   % 2, 1, lessp
   {2, 1, 'lessp, {1 . 1}} . 'vsub!-2!-1!-lessp!-1,
   {2, 1, 'lessp, {1 . 2}} . 'vsub!-2!-1!-lessp!-2,
   {2, 1, 'lessp, {2 . 1}} . 'vsub!-2!-1!-lessp!-3,
   % 2, 1, lessp, clustering
   {2, 1, 'lessp, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}} . 'vsub!-2!-1!-lessp!-4,
   {2, 1, 'lessp, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}} . 'vsub!-2!-1!-lessp!-5,
   {2, 1, 'lessp, {1 . 1, 2 . 1}} . 'vsub!-2!-1!-lessp!-1,
   {2, 1, 'lessp, {1 . 2, 2 . 1}} . 'vsub!-2!-1!-lessp!-2,

   % 2, 1, leq
   {2, 1, 'leq, {1 . 1}} . 'vsub!-2!-1!-leq!-1,
   {2, 1, 'leq, {1 . 2}} . 'vsub!-2!-1!-leq!-2,
   {2, 1, 'leq, {2 . 1}} . 'vsub!-2!-1!-leq!-3,
   % 2, 1, leq, clustering
   {2, 1, 'leq, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}} . 'vsub!-2!-1!-leq!-4,
   {2, 1, 'leq, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}} . 'vsub!-2!-1!-leq!-5,
   {2, 1, 'leq, {1 . 1, 2 . 1}} . 'vsub!-2!-1!-leq!-1,
   {2, 1, 'leq, {1 . 2, 2 . 1}} . 'vsub!-2!-1!-leq!-2,

   % 3, 1, equal
   {3, 1, 'equal, {1 . 1}} . 'vsub!-3!-1!-equal!-1,
   {3, 1, 'equal, {2 . 1}} . 'vsub!-3!-1!-equal!-2,
   {3, 1, 'equal, {2 . 2}} . 'vsub!-3!-1!-equal!-3,
   {3, 1, 'equal, {3 . 1}} . 'vsub!-3!-1!-equal!-4,
   {3, 1, 'equal, {3 . 2}} . 'vsub!-3!-1!-equal!-5,
   {3, 1, 'equal, {4 . 1}} . 'vsub!-3!-1!-equal!-6,
   {3, 1, 'equal, {4 . 2}} . 'vsub!-3!-1!-equal!-7,
   {3, 1, 'equal, {4 . 3}} . 'vsub!-3!-1!-equal!-8,
   % 3, 1, equal, clustering
   {3, 1, 'equal, {2 . 1, 3 . 1, 4 . 1}} . 'vsub!-3!-1!-equal!-9,
   {3, 1, 'equal, {2 . 1, 3 . 2, 4 . 2}} . 'vsub!-3!-1!-equal!-10,
   {3, 1, 'equal, {2 . 2, 3 . 2, 4 . 3}} . 'vsub!-3!-1!-equal!-11,

   % 3, 1, lessp
   {3, 1, 'lessp, {1 . 1}} . 'vsub!-3!-1!-lessp!-1,
   {3, 1, 'lessp, {2 . 1}} . 'vsub!-3!-1!-lessp!-2,
   {3, 1, 'lessp, {2 . 2}} . 'vsub!-3!-1!-lessp!-3,
   {3, 1, 'lessp, {3 . 1}} . 'vsub!-3!-1!-lessp!-4,
   {3, 1, 'lessp, {3 . 2}} . 'vsub!-3!-1!-lessp!-5,
   {3, 1, 'lessp, {4 . 1}} . 'vsub!-3!-1!-lessp!-6,
   {3, 1, 'lessp, {4 . 2}} . 'vsub!-3!-1!-lessp!-7,
   {3, 1, 'lessp, {4 . 3}} . 'vsub!-3!-1!-lessp!-8,
   % 3, 1, lessp, clustering
   {3, 1, 'lessp, {2 . 1, 3 . 1, 4 . 1}} . 'vsub!-3!-1!-lessp!-9,
   {3, 1, 'lessp, {2 . 1, 3 . 2, 4 . 2}} . 'vsub!-3!-1!-lessp!-10,
   {3, 1, 'lessp, {2 . 2, 3 . 2, 4 . 3}} . 'vsub!-3!-1!-lessp!-11,

   % 3, 1, leq
   {3, 1, 'leq, {1 . 1}} . 'vsub!-3!-1!-leq!-1,
   {3, 1, 'leq, {2 . 1}} . 'vsub!-3!-1!-leq!-2,
   {3, 1, 'leq, {2 . 2}} . 'vsub!-3!-1!-leq!-3,
   {3, 1, 'leq, {3 . 1}} . 'vsub!-3!-1!-leq!-4,
   {3, 1, 'leq, {3 . 2}} . 'vsub!-3!-1!-leq!-5,
   {3, 1, 'leq, {4 . 1}} . 'vsub!-3!-1!-leq!-6,
   {3, 1, 'leq, {4 . 2}} . 'vsub!-3!-1!-leq!-7,
   {3, 1, 'leq, {4 . 3}} . 'vsub!-3!-1!-leq!-8,
   % 3, 1, leq, clustering
   {3, 1, 'leq, {2 . 1, 3 . 1, 4 . 1}} . 'vsub!-3!-1!-leq!-9,
   {3, 1, 'leq, {2 . 1, 3 . 2, 4 . 2}} . 'vsub!-3!-1!-leq!-10,
   {3, 1, 'leq, {2 . 2, 3 . 2, 4 . 3}} . 'vsub!-3!-1!-leq!-11,

   % 3, 2, equal
   {3, 2, 'equal, {1 . 1}} . 'vsub!-3!-2!-equal!-1,
   {3, 2, 'equal, {2 . 1}} . 'vsub!-3!-2!-equal!-2,
   {3, 2, 'equal, {2 . 2}} . 'vsub!-3!-2!-equal!-3,
   {3, 2, 'equal, {3 . 1}} . 'vsub!-3!-2!-equal!-4,
   {3, 2, 'equal, {3 . 2}} . 'vsub!-3!-2!-equal!-5,
   {3, 2, 'equal, {4 . 1}} . 'vsub!-3!-2!-equal!-6,
   {3, 2, 'equal, {4 . 2}} . 'vsub!-3!-2!-equal!-7,
   {3, 2, 'equal, {4 . 3}} . 'vsub!-3!-2!-equal!-8,
   % 3, 2, equal, clustering
   {3, 2, 'equal, {2 . 1, 3 . 1, 4 . 1}} . 'vsub!-3!-2!-equal!-9,
   {3, 2, 'equal, {2 . 1, 3 . 2, 4 . 2}} . 'vsub!-3!-2!-equal!-10,
   {3, 2, 'equal, {2 . 2, 3 . 2, 4 . 3}} . 'vsub!-3!-2!-equal!-11,

   % 3, 2, lessp
   {3, 2, 'lessp, {1 . 1}} . 'vsub!-3!-2!-lessp!-1,
   {3, 2, 'lessp, {2 . 1}} . 'vsub!-3!-2!-lessp!-2,
   {3, 2, 'lessp, {2 . 2}} . 'vsub!-3!-2!-lessp!-3,
   {3, 2, 'lessp, {3 . 1}} . 'vsub!-3!-2!-lessp!-4,
   {3, 2, 'lessp, {3 . 2}} . 'vsub!-3!-2!-lessp!-5,
   {3, 2, 'lessp, {4 . 1}} . 'vsub!-3!-2!-lessp!-6,
   {3, 2, 'lessp, {4 . 2}} . 'vsub!-3!-2!-lessp!-7,
   {3, 2, 'lessp, {4 . 3}} . 'vsub!-3!-2!-lessp!-8,
   % 3, 2, lessp, clustering
   {3, 2, 'lessp, {2 . 1, 3 . 1, 4 . 1}} . 'vsub!-3!-2!-lessp!-9,
   {3, 2, 'lessp, {2 . 1, 3 . 2, 4 . 2}} . 'vsub!-3!-2!-lessp!-10,
   {3, 2, 'lessp, {2 . 2, 3 . 2, 4 . 3}} . 'vsub!-3!-2!-lessp!-11,

   % 3, 2, leq
   {3, 2, 'leq, {1 . 1}} . 'vsub!-3!-2!-leq!-1,
   {3, 2, 'leq, {2 . 1}} . 'vsub!-3!-2!-leq!-2,
   {3, 2, 'leq, {2 . 2}} . 'vsub!-3!-2!-leq!-3,
   {3, 2, 'leq, {3 . 1}} . 'vsub!-3!-2!-leq!-4,
   {3, 2, 'leq, {3 . 2}} . 'vsub!-3!-2!-leq!-5,
   {3, 2, 'leq, {4 . 1}} . 'vsub!-3!-2!-leq!-6,
   {3, 2, 'leq, {4 . 2}} . 'vsub!-3!-2!-leq!-7,
   {3, 2, 'leq, {4 . 3}} . 'vsub!-3!-2!-leq!-8,
   % 3, 2, leq, clustering
   {3, 2, 'leq, {2 . 1, 3 . 1, 4 . 1}} . 'vsub!-3!-2!-leq!-9,
   {3, 2, 'leq, {2 . 1, 3 . 2, 4 . 2}} . 'vsub!-3!-2!-leq!-10,
   {3, 2, 'leq, {2 . 2, 3 . 2, 4 . 3}} . 'vsub!-3!-2!-leq!-11
      };
