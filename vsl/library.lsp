% This is a collection of commonly useful Lisp
% functions that can be defined in terms of the
% things that are built into vsl. The idea is that
% going
%     ./vsl -z library.lsp
% will create an image file vsl.img that can be loaded
% next time vsl is started, so that the cold-start
% flag (-z) does not then have to be used and all these
% extra functions will be available.

% The library itself if in "vsl.lsp"...

(rdf "vsl.lsp")

% The compatibility file "vsl.lsp" defines a macro called
% "~let" rather than "let" because of a name-clash with the
% Reduce algbera system. I put in the more ordinary name here.

(dm let (u) (cons '!~let (cdr u)))

% Checkpoint a heap image and stop.

(preserve)

(stop 0)

