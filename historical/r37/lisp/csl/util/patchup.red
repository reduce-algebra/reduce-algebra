
% This script ensures that REDUCE has the most recent set of
% patches applied. It cab be used in two manners

% (a) Have the REDUCE binary directory selected as current, and go just
%         r37 patchup.red
%     This relies on being located within the REDUCE source tree.
%
% (b) Being in some other directory where you often use REDUCE and
%     issuing the command
%         r37 (wherever)/patchup.red -D@reduce="path-to-reduce-tree"
%     This will put the compiled patches in your local directory.

lisp;

load!-module 'remake;

ensure_patches_are_up_to_date();

end;


