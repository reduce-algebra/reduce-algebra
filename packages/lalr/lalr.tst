% Test cases for the parser generator. This all runs in symbolic mode...


%
% This is where (for now) I will put documentation of the syntax I
% will use when creating a grammer. There is a main function called
% lalr_create_parser and that is passed a list that describes
% a grammar. It is in the form of a sequence of productions, and the first
% one given is taken to be the top-level target.
%
% Each production is in the form
%     (LHS   ((rhs1.1 rhs1.2 ...) a1.1 a1.2 ...)
%            ((rhs2.1 rhs2.1 ...) a2.1 a2.2 ...)
%            ...)
% which in regular publication style for grammars might be interpreted
% as meaning
%      LHS ::= rhs1.1 rhs1.2 ... { a1.1 a1.2 ... }
%          |   rhs2.1 rhs2.2 ... { a2.1 a2.2 ... }
%          ...
%          ;
%
% Each LHS is treated as a non-terminal symbol and is specified as a simple
% name. Note that by default the Reduce parser will be folding characters
% within names to lower case and so it will be best to choose names for
% non-terminals that are unambiguous even when case-folded, but I would like
% to establish a convention that in source code they are written in capitals.
%
% The rhs items may be either non-terminals (identified because they are
% present in the left hand side of some production) or terminals. Terminal
% symbols can be specified in two different ways.
% The lexer has built-in recipies that decode certain sequences of characters
% and return the special markers for !:symbol, !:number, !:string, !:list for
% commonly used cases. In these cases the variable yylval gets left set
% to associated data, so for instance in the case of !:symbol it gets set
% to the particular symbol concerned.
% The token type :list is used for Lisp or rlisp-like notation where the
% input contains
%     'expression
% or  `expression
% so for instance the input `(a b c) leads to the lexer returning !:list and
% yylvel being set to (backquote (a b c)). This treatment is specialised for
% handling rlisp-like syntax.
%
% Other terminals are indicated by writing a string. That may either
% consist of characters that would otherwise form a symbol (ie a letter
% followed by letters, digits and underscores) or a sequence of
% non-alphanumeric characters. In the latter case if a sequence of three or
% more punctuation marks make up a terminal then all the shorter prefixes
% of it will also be grouped to form single entities. So if "<-->" is a
% terminal then '<', '<-' and '<--' will each by parsed as single tokens, and
% any of them that are not used as terminals will be classified as !:symbol.
%
% As well as terminals and non-terminals (which are wrirrent as symbols or
% strings) it is possible to write one of
%     (OPT s1 s2 ...)           0 or 1 instances of the sequence s1, ...
%     (STAR s1 s2 ...)          0, 1, 2, ... instances
%     (PLUS s1 s2 ...)          1, 2, 3, ... instances
%     (LIST sep s1 s2 ...)      like (STAR s1 s2 ...) but with the single
%                               item sep between each instance.
%     (LISTPLUS sep s1 ...)     like (PLUS s2 ...) but with sep interleaved.
%     (OR s1 s2 ...)            one or other of the tokens shown.
%
% When the lexer processes input it will return a numeric code that identifies
% the type of the item seen, so in a production one might write
%     (!:symbol ":=" EXPRESSION)
% and as it recognises the first two tokens the lexer will return a numeric
% code for !:symbol (and set yylval to the actual symbol as seen) and then
% a numeric code that it allocates for ":=". In the latter case it will
% also set yylval to the symbol !:!= in case that is useful.
%
% Precedence can be set using lalr_precedence. See examples lower down in this
% file.

% Limitations are
% (1) At present the parser generator will not cope with large grammars
%     because it does not merge rules promptly enough.
% (2) The lexer is hand-written and can not readily be reconfigured for
%     use with languages other than rlisp. For instance it has use of "!"
%     as a character escape built into it.
%
%


symbolic;

% Before testing parser generation I will demonstrate the lexer..
% If I was jumpy about the exact behaviour of the lexer I could go
%               on tracelex;
% to get some more tracing.

lex_cleanup();

lex_keywords '("begin" "<=>" "<==");

% The output from this is expected to be

%  Result: (2 symbol)
%  Result: (4 200)
%  Result: (4 3.542)
%  Result: (3 "a string")
%  Result: (2 nil)
%  Result: (5 (quote (quoted lisp)))
%  Result: (5 (backquote (backquoted (!, comma) (!,!@ comma_at))))
%  Result: (2 !+)
%  Result: (7 !<!=!>)
%  Result: (2 !-)
%  Result: (2 !=)
%  Result: (2 !>)
%  Result: (9 !<)
%  Result: (8 !<!=)
%  Result: (5 begin)
%  Result: (2 !;)
%  Result: (2 !;)
%  Result: (2 !;)
%
%  nil

% The row of "; ; ;" at the end provides some protection so that
% if faults in the lexer were to cause it to read more or less than it ought
% to then what is left over is reasonably likely to remain as valid rlisp
% syntax and so the rest of this test file will be able to continue happily.


<< off echo;
   lex_init();
   for i := 1:18 do <<
     tt := yylex();
     if not zerop posn() then terpri();
     princ "Result: ";
     print list(tt, yylval) >>;
   on echo >>;

symbol
200
3.542
"a string"
'(quoted lisp)
`(backquoted ,comma ,@comma_at)
+
<=>
-
=>
<
<=
begin
; ; ; ;


on lalr_verbose;

% Here I set up a sample grammar
%    S' -> S
%    S  -> C C        { }
%    C  -> "c" C      { }
%        | "d"        { }
% This is example 4.42 from Aho, Sethi and Ullman's Red Dragon book.
% It is example 4.54 in the more recent Purple book.

% Note that this grammar will introduce "c" and "d" as keywords rather than
% being general symbols. When I construct a subsequent grammar that will
% undo that setting. I will omit semantic actions here so that the default
% action of building a form of tree is used.

% There seems to be an issue here in that if I use a name for a non-terminal
% that is the same as one used for a terminal thinsg get confused. So I had
% originally hoped and expected to write just 'c' for the name of the
% non-terminal here are use '"c"' to denote the terminal. However when I
% try that I find that internally the names and up clashing to rather bad
% effect. I will look into this later since it is merely a matter of surface
% notation!  Also in the input to semantic actions the values passed when a
% terminal is matched may at present be the internal numeric code allocated
% to that terminal, not a "sensible" value. Agian this is a small issue.

grammar := '(
  (s  ((cc cc)  )   % One production for S, no explicit semantic here
  )
  (cc (("c" cc) (list 'c !$2))   % First production for C
      (("d")    'd           )   % Second production for C
  ));

g := lalr_create_parser(nil, grammar)$

symbolic procedure pparse g;
  begin
    scalar r;
    r := yyparse g;
    terpri();
    princ "= ";
    print r
  end;

pparse g$

c c c d c d ;

pparse g$

d d ;


% Now switch off the tracing. It is useful while debugging this
% package but is typically rather over the top for normal use.

off tracelex, lalr_verbose;

% Example 4.46 from the Red Dragon (4.61 in Aho, Lam, Sethi and Ullman,
% "Compilers: principles, techniques and tools", second edition 2007).
%
% This is used there as an example of a grammar that is not SLR(1) but
% that can be handled by LALR .

% The semantic actions here contain print statements that will
% print some sort of trace as the parsing progresses.

symbolic procedure neatprintc x;
 << if not zerop posn() then terpri();
    printc x >>;

g4_46 := '((s   ((l "=" r)   (neatprintc "## S => L = R")
                             (list 'equal !$1 !$3))
                ((r)         (neatprintc "## S => R")
                             !$1))
           (l   (("*" r)     (neatprintc "## L => * R")
                             (list 'star !$2))
                ((!:symbol)  (neatprintc "## L => symbol")
                             !$1))
           (r   ((l)         (neatprintc "## R => L")
                             !$1)));

g := lalr_create_parser(nil, g4_46)$

pparse g$

leftsym = rightsym ;


pparse g$

****abc = *def ;

% This next example is expected to be reasonably representative of
% small grammars. It needs precedence rules to disambiguate the
% grammar, and illustrates both left and right associativity, and
% cases where two operators have the same precedence.

gtest := '((s  ((p))
               ((s "^" s) (list 'expt !$1 !$3))
               ((s "**" s) (list 'expt !$1 !$3))
               ((s "*" s) (list 'times !$1 !$3))
               ((s "/" s) (list 'quotient !$1 !$3))
               ((s "+" s) (list 'plus !$1 !$3))
               ((s "-" s) (list 'difference !$1 !$3))
               ((s "=" s) (list 'equal !$1 !$3))
               (("-" s) (list 'minus !$2))
               (("+" s) !$2))

           (p  (("(" s ")") !$2)
               ((!:symbol))
               ((!:string))
               ((!:number))));

% "^" and "**" both have the same high precedence and are right
% associative. Next come "*" and "/" which are left associative,
% and after that "+" and "-". Finally "=" has lowest precedence and
% must not associate with itself, so (a=b=c) should be a syntax error.

p := '(!:right ("^" "**") !:left ("*" "/") ("+" "-") !:none "=");

g := lalr_create_parser(p, gtest)$

pparse g$
a^b^c;

pparse g$
a*b+c*d;

pparse g$
a * (b/c + d/e/f) ^ 2 ^ g - "str" ;

% Demonstrate various of the short-hand notations...

g := lalr_create_parser(nil, '(
 (s
% (opt ...) means that the included material is optional.
          (("begin" (opt "and" "also") "end")))))$

pparse g$
begin end
;;

pparse g$
begin and also end
;;

g := lalr_create_parser(nil, '(
 (s
% (star ...) is for zero or mor instances of something.
          (((star "a") "end") !$1))))$

pparse g$
end
;;

pparse g$
a a a a a a end
;;

g := lalr_create_parser(nil, '(
 (s
% (plus ...) is for one or more repetitions of an item
          (((plus "a") "end") !$1))))$

pparse g$
a end
;;

pparse g$
a a a a a a end
;;

g := lalr_create_parser(nil, '(
 (s
% (list delimiter item-description) is a sequence of zero
% or more items, and if there are several that are separated by the
% indicated delimiter. 
          (((list ";" !:symbol) "eof") !$1))))$

pparse g$

several ; words ; here eof
;;

g := lalr_create_parser(nil, '(
 (s
% (listplus delimiter item-description) is as (list ...) however it
% requires at least one item.
          (((listplus ";" !:symbol) "eof") !$1))))$

pparse g$

several ; words ; here eof
;;

g := lalr_create_parser(nil, '(
 (s
% (or x y z) may be a more compact way of writing what could
% otherwise by given as multiple productions, so for instance
% (or "+" "-" "*" "/") would match one of the listed operators.
          (((star (or "a" "b")) "end") !$1))))$

pparse g$
end
;;

pparse g$
a b b a end
;;

% The next example shows all the above put together to parse what is
% in effect a small programming language. Although it is not yet a large
% grammar it illustrates painfull clearly how poor performange of the
% parser generator can be if ut used what Aho, Sethi and Ullman describe as
% the "Easy but space-consuming LALR table construction" method.

p := '(!:left ("*" "/")
              ("+" "-")
       !:none ("<" "<=" "==" "neq" ">=" ">")
       !:right ":=" "="
       !:left ("then" "else" "return"))$

mini_language := '(
 (program
          (((listplus ";" expression) "eof") !$1))

 (expression
          ((funcall))
          ((expression "*" expression) (list 'times !$1 !$3))
          ((expression "/" expression) (list 'quotient !$1 !$3))
          ((expression "+" expression) (list 'plus !$1 !$3))
          ((expression "-" expression) (list 'difference !$1 !$3))
          ((expression "<" expression) (list 'lessp !$1 !$3))
          ((expression "<=" expression) (list 'lesseq !$1 !$3))
          ((expression "==" expression) (list 'equals !$1 !$3))
          ((expression "neq" expression) (list 'neq !$1 !$3))
          ((expression "=>" expression) (list 'geq !$1 !$3))
          ((expression ">" expression) (list 'greaterp !$1 !$3))
          ((expression ":=" expression) (list 'setq !$1 !$3))
          (("fun" funcall "=" expression) (list 'fun !$2 !$4))
          (("if" sequence "then" expression)
             (list 'cond, list(!$2, !$4)))
          (("if" sequence "then" sequence "else" expression)
             (list 'cond, list(!$2, !$4), list(t, !$6)))
          (("go" (opt "to") !:symbol) (list 'go !$3))
          (("goto" !:symbol) (list 'go !$2))
          (("return" expression)))

(funcall
          ((closedexpression))
          ((funcall closedexpression)))

(closedexpression
          ((!:symbol))
          ((!:number))
          (((plus !:string))) % Several strings in a row just concatenate
          (("let" sequence "in" sequence "end") (list 'letstat !$2 !$4))
          (("(" exprlist ")") (cons 'paren !$2))
          (("(" sequence ")") (cons 'paren !$2))
          (("[" exprlist "]") (cons 'bracket !$2)))

(exprlist (((list "," expression))))

(sequence
          (((list ";" expression)))))$

% The grammar shown here used to fail for lack of space. It should now
% behave.
% One issue it reveals at right now is that the processing here does not
% keep the types of terminal symbols under control carefully enough, so the
% numeric values 22 and 33 in the sample text get transliterated back into
% terminal symbols that happen to have ended up allocated numeric codes
% 22 and 33. This NEEDS fixing, but is not really an issue for the
% code that manufactures parsing tables.
%
%                                                       ACN   May 2016

on tracelex, lalr_verbose;

g := lalr_create_parser(p, mini_language)$

pparse g$
fun f(a,b) = a + b;
f(22,33)
eof

end;

