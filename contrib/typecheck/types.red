lisp;

enable!-errorset(3,3); % See all diagnostics.

load!-source();

global '(fnlist);

for each x in oblist() do
   if get(x, '!*savedef) then fnlist := x . fnlist;

% This will now illustrate the information available about a function by
% displaying what is on its property list. I will look as ADDF.

% The information shows the file name and line within that file where
% addf was defined. It gives its arguments. It shows some information
% about its type - but unless the original source code tagged arguments
% with type information this will tend to use the word "general". And it
% shows the source code. Note here that some Reduce syntax features (eg
% WHILE loops) have been expanded out in terms of lower level Lisp
% forms, but that because I am using noinlines.img that inline functions
% (such as LC, LT, RED) are retained as visible.


<<
  printf("%nThere seem to be %s functions defined%n", length fnlist);
  printf("ADDF:%n");
  for each x in plist 'addf do <<
     printf("%s : ", car x);
     prettyprint cdr x >>;
  terpri() >>;

quit;
