%
% There used to be a file "geometry.red" here that was an earlier version
% of geoprover.red. For a while its contents will remain available in
% old-geometry.red. However the Reduce build system sets up a file of
% automatically collected dependencies, so those with a build-tree from before
% mid-March 2015 will find geometry/geometry.red in there. Until the
% files "bootstrapreduce.dep" and "reduce.dep" have been fully rebuilt for
% enought people (eg because they have either removed them by hand or
% started from a fully fresh cslbuild and pslbuild directory) some file
% is needed here to prevent "make" from complaining. Hence this one with
% this explanation but no real content!
%

lisp error(99,
   "You should not be using this file now - see comments in source");

end;
