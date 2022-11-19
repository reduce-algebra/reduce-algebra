% tracearith.red                               Arthur Norman, November 2022

% Not long enough to justify license pedantry: you may do whatever you
% want with this code!



% There are times when one needs to trace functions that are so deeply
% embedded in Lisp/Reduce that their use tends to end up compiled in-line.
% In such case the normal trace schemes do not work well. Also some
% functions are used by Reduce and Lisp infrastructure so global tracing
% of them can cause utter havoc.

% What I have here is a scheme where one goes:
%   lisp settrace();
%   in "some-module-to-test.red";
%   lisp cleartrace();
%   <some test code that exercises the module>

% settrace() in effect adjusts the Reduce parser so that use of functions
% it handles are expanded so that eg (plus A B C) maps to some code
% along the lines of
%    (lambda a,b,c; (lambda r; <print statements>; r) (plus a b c))(A,B,C)
% where the lambdas are there so that (unless there are rplaca/rplacd
% operations to corrupt them!) the arguments and result of the call to
% plus can be printed.

% This is at present set up to arrange testing of a range of basic
% arithmetic functions like PLUS and TIMES since those are things I
% have been working on. The idea is that one can edit this file to
% adjust exactly what you want traced. Well next I will make it deal
% with modular arithmetic and read in the sources of the factorizer
% to see if I can debug some failures I currently see there...

lisp for each x in oblist() do remprop(x, 'inline);

symbolic procedure bodyarith(fnn, av);
  begin
    scalar g := gensym(), i := 0;
    return list(list('lambda, list g, 'progn .
      list('princ, "calling ") .
      list('print, mkquote fnn) .
      append(for each v in av collect
         list('progn, list('prin2, "Arg"),
                      list('prin2, i := i+1),
                      list('prin2, ": "),
                      list('print, v)),
         list(list('princ, "=> "),
              list('print, g)))), fnn . av);
  end;

symbolic procedure formarith(u,vars,mode);
  begin
    scalar fnn := car u, args := formlis(cdr u, vars, mode);
    scalar av := for each x in args collect gensym();
    return ('lambda . av . list bodyarith(fnn, av)) . args
  end;

symbolic procedure settrace();
 << put('plus, 'formfn, 'formarith);
    put('difference, 'formfn, 'formarith);
    put('minus, 'formfn, 'formarith);
    put('times, 'formfn, 'formarith);
    put('quotient, 'formfn, 'formarith);
    put('remainder, 'formfn, 'formarith);
    put('divide, 'formfn, 'formarith);
    put('gcdn, 'formfn, 'formarith);
    put('greaterp, 'formfn, 'formarith);
    put('geq, 'formfn, 'formarith);
    put('lessp, 'formfn, 'formarith);
    put('leq, 'formfn, 'formarith);
    nil >>;

symbolic procedure cleartrace();
 << remprop('plus, 'formfn);
    remprop('difference, 'formfn);
    remprop('minus, 'formfn);
    remprop('times, 'formfn);
    remprop('quotient, 'formfn);
    remprop('remainder, 'formfn);
    remprop('divide, 'formfn);
    remprop('gcdn, 'formfn);
    remprop('greaterp, 'formfn);
    remprop('geq, 'formfn);
    remprop('lessp, 'formfn);
    remprop('leq, 'formfn);
    nil >>;

end;

 