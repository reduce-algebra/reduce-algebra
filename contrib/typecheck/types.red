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

% A procedure that looks through the code u and applies the function ff
% to every procedure call it finds.

% To help me know what to do here is a complete list of all the "special
% forms" present in CSL:
%*      and
%*      catch
%*      compiler!-let
%       cond
%       de
%       declare
%       dm
%*      eval!-when
%*      flet
%       function
%       go
%*      if
%*      labels
%       let!*
%*      macrolet
%*      multiple!-value!-call
%*      multiple!-value!-prog1
%*      or
%       prog
%*      prog1
%*      prog2
%*      progn
%*      progv
%       quote
%*      return
%*      return!-from
%       setq
%       tagbody
%*      the
%*      throw
%*      unless
%*      unwind!-protect
%*      when
%*      !~block
%*      !~let
% I have put a "*" ahead on one I intend to ignore for now. Some such as
% AND and PROGN and WHEN may be special forms but their "arguments" are all
% ordinary expression syntax ready for evaluation. Some such as MACROLET will
% not be used by Reduce.

symbolic procedure find_calls(ff, u);
  if atom u then nil                    % name, number, vector, string
  else if not atom car u then find_calls_lambda(ff, car u, cdr u)
  else if eqcar(u, 'cond) then find_calls_cond(ff, cdr u)
  else if eqcar(u, 'de) then nil        % do not analyse
  else if eqcar(u, 'declare) then nil   % no function calls here
  else if eqcar(u, 'dm) then nil        % do not analyse
  else if eqcar(u, 'function) then nil  % literal function
  else if eqcar(u, 'go) then nil        % the target label is not evaluated
  else if eqcar(u, 'let!*) then find_calls_let(ff, cadr u, cddr u)
  else if eqcar(u, 'prog) then find_calls_prog(ff, cadr u, cddr u)
  else if eqcar(u, 'quote) then nil     % literal
  else if eqcar(u, 'setq) then find_calls_setq(ff, cdr u)
  else if eqcar(u, 'tagbody) then find_calls_prog(ff, nil, cdr u)
  else <<
    for each a in cdr u do find_calls(ff, a);
    apply2(ff, car u, cdr u);
    nil >>;

symbolic procedure find_calls_lambda(ff, lx, a);
 << for each e in a do find_calls(ff, e);
    for each e in cddar lx do find_calls(ff, e) >>;

symbolic procedure find_calls_cond(ff, a);
  if null a then nil
  else <<
    for each p in car a do find_calls(ff, p);
    find_calls_cond(ff, cdr a) >>;

symbolic procedure find_calls_prog(ff, bvl, body);
  for each s in body do
    if not atom s then
      find_calls(ff, s);

symbolic procedure find_calls_let(ff, bvl, body);
  << for each e in body do find_calls(ff, e);
     for each b in bvl do
       if not atom b then
         for each e in cdr b do find_calls(ff, e) >>;

symbolic procedure find_calls_setq(ff, a);
  if null a then nil
  else <<
    find_calls(ff, cadr a);
    find_calls_setq(ff, cddr a) >>;

symbolic procedure reporter(fn, args);
  begin
    prin fn; ttab 20; print args;
  end;

find_calls(function reporter, caddr get('addf, '!*savedef));
  

quit;
