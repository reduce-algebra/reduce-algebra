% yylex.red

% Author: Arthur Norman, with changes by Zach Hauser, 2016

% Copyright 2016.
%
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

% $Id$

module 'yylex;

%
% This is a lexical anaylser for use with the LALR parser generator.
% By default it will handle items in the way that Rlisp does. Its interface
% is styled after the one needed by yacc, in that it exports a function
% called yylex() that returns as a value a category code, but
% sets a variable yylval to details associated with the item
% just parsed. The result will be an integer corresponding to a token
% type. By setting a flag I may change the lexical rules to match some
% other language.
%
% The variations listed here are so I can collect my thoughts about what
% options might plausibly arise. However having a fully general scheme
% would need to await implementation of something like "lex" or "flex" and
% that is overkill for the present!
%
% COMMENTS
%
% (1)  Rlisp    % ... EOL
% (2)           COMMENT ... ; or $
% (3)  C        /* ... */         (no nesting allowed)
% (4)  C++      // ... EOL
% (5)  SML      (* ... *)         (nesting honoured)
% (6)  Shell    # ... EOL
% (7)  CommonLisp  ; ... EOL
% (8)  Haskell  -- ... EOL
% (9)  CMD      REM ... EOL
% (10) ?        [ ... ]
%
% I propose to ignore comments introduced by words, and assume that
% placement on the line is not special, so that comments will be
% recognised either at the start of a line or anywhere within.
% This leaves the following cases
% (.) A single character starts a comment, which then runs to
%     the end of the line. (1), (6), (7).
% (.) a pair of characters (not necessarily the same) start a comment
%     that runs to end of line. (4), (8).
% (.) A pair of characters open a comment and a different pair end it,
%     with no nexting permitted. (3).
% (.) As above but comments do nest. (5).
% A grammar should be allowed to support one style of line comment and
% one of multiline comment, but I think that having more choices beyond that
% would feel excessive. Note the acronym YAGNI for "You ain't gonna need it"
% applies! But in summary the reasonable generality would need:
%    0, 1 or 2 characters that indicate line comments. If none then
%        there are no line comments. If 1 then line comments are introduced
%        by that character. If 2 they start with the character pair.
%    a flag and 2 or 4 characters for block comments. The flag indicates
%        whether nesting is supported. Well I suppose it should be
%        (1 or 2) plus (1 or 2) characters since start or end could perhaps
%        independently be either single characters or pairs.
%
%
% NAMES
%
% Basic names will start with a letter and continue with letters or
% digits.
%
% The key options are:
% (1) Are not-letters permitted at the start or within a name? For instance
%     Reduce allows "_" within a name but not as the first character. SML
%     allows quote marks but treats a name differently if the first character
%     is one. Common Lisp makes its lexer programmble, but by default it
%     will count !, $, %, &, +, -, *, /, @ and more as alphabetic, with
%     ", #, ', |, parentheses and comma perhaps having special status.
%     So I probably need a way to mark which characters can start a symbol
%     and which can continue it. SML also allows operator-like names, so I
%     also need a second pair of character-sets to support that. Rlisp
%     uses (!) as a character to escape something, while other languages
%     use (\). TeX allows a name to start with (\) but does not allow that
%     character within names.
%     Common Lisp allows names to be written as "|any chars|" and may
%     have special treatment of ":" within names: I will not support those
%     options.
%
% (2) Strings will be in (") marks, but there is an issue about escapes.
%     Many languages allow (\) escapes within strings and the exact rules
%     can be messy. But if that is what is provided I think I should
%     merely accept that the character after a (\) is treated as a generic
%     character and is not special even if it is (\) or (").
%
% (3) Character literals may be like string literals but with single
%     quotes?
%
%
% NUMBERS
%
% I intend (at least at present) to take a simple view that numbers are
% written in a naive simple way. That means that (at present) I will not
% support suffix notation such as "1LL", and if I support non-decimal
% notation at all it will be as in C/C++. Floating point may only use
% the letter (E) or (e) as an exponent marker. I am certainly not going to
% play games with Common Lisp "potential numbers"!
%

% (R)LISP SPECIALS
%
% For Rlisp/Lisp I want (') to act as a read-macro that leads to the
% parsing of an s-expression! I will also make the lexer handle "#if" style
% conditional sections.
%
%
%
% In the face of all this I will simplify and support just a small menu
% of regimes:
%  RLISP: Very specialist as far as the outside world is concerned, but
%         given that this is part of REDUCE it makes sense. The main features
%         are "!" as an escape character, "'" to introduce quoted expressions
%         "%" for comments and "#if" for conditional inclusion.
%  C/C++: Both "/*..*/" and "//" comments with broadly C-like rules for
%         names and strings. I do not support preprocessor directives.
%  SML:   Provided because I happen to have some SML that I wish to process.
%         "(*..*)" nesting comments and sequences of operator-characters
%         making up a single token are characteristic.
%  Simple: For simple scripting I will provide a lexical scheme where "#"
%         introduces a comment and syntax is otherwise rather C-like.
%  TeX:   No strings, and names can be things lile "\begin" and "\(".
%
% I think that if I support just these (to start with) I should cover the
% needs I have for now! In all cases reserved words and reserved sequences
% of punctuation can emerge from the grammar, so of the grammar contains
% a rule with ":=" or "begin" in it then those strings will be recognized
% and treated specially.

fluid '(lexer_style!*
        lexer_style_rlisp lexer_style_C lexer_style_SML lexer_style_script);

% One thing to note about "#define" here is that the naming that it
% introduces is not carried through to the compiled module that is
% generated... so thse names are NOT available to the end user!

#define lexer_comment_percent        0x1    %  "%..." is a comment
#define lexer_comment_hash           0x2    %  "#..." is a comment
#define lexer_comment_slashslash     0x4    %  "//..." is a comment
#define lexer_comment_slashstar      0x8    %  "/*...*/" is a comment
#define lexer_comment_lparstar      0x10    %  "(*...*)" is a comment
#define lexer_comment_nesting       0x20    %  block comments nest
#define lexer_hashif                0x40    %  support for "#if"
#define lexer_string                0x80    %  double quote starts a string
#define lexer_char                 0x100    %  single quote starts a character
#define lexer_string_escapes       0x200    %  support "\x" escapes in strings
#define lexer_string_rlisp         0x400    %  "a""b" is string for 'a"b'
#define lexer_start_underscore     0x800    %  _word is a symbol
#define lexer_start_backslash     0x1000    %  \word is a symbol
#define lexer_start_prime         0x2000    %  'word is a (special) symbol
#define lexer_cont_underscore     0x4000    %  a_b is a symbol
#define lexer_escape_pling        0x8000    %  a!+!*!^b is a symbol
#define lexer_cont_prime         0x10000    %  a'' is a symbol
#define lexer_sml_operators      0x20000    %  +++*+++ is a symbol
#define lexer_lispquote          0x40000    %  '(s-expression) accepted
#define lexer_spare1             0x80000    % 2^19   spare
#define lexer_spare2            0x100000    % 2^20   spare
#define lexer_spare3            0x200000    % 2^21   spare
#define lexer_spare4            0x400000    % 2^22   spare
#define lexer_spare5            0x800000    % 2^23   spare

% Establish simple names for some plausible combinations of options.

lexer_style_rlisp :=          % For use with Standard Lisp/Rlisp/REDUCE
   lexer_comment_percent +
   lexer_hashif +
   lexer_string +
   lexer_string_rlisp +
   lexer_cont_underscore +
   lexer_escape_pling +
   lexer_lispquote;
  
lexer_style_C :=              % For use with C, C++, Java
   lexer_comment_slashslash +
   lexer_comment_slashstar +
   lexer_char +
   lexer_string +
   lexer_string_escapes +
   lexer_start_underscore +
   lexer_cont_underscore;
  
lexer_style_SML :=            % For use with SML
   lexer_comment_lparstar +
   lexer_comment_nesting +
   lexer_string +
   lexer_string_escapes +
   lexer_start_underscore +
   lexer_cont_underscore +
   lexer_start_prime +
   lexer_cont_prime +
   lexer_sml_operators;
  
lexer_style_script :=         % For simple configuration files and scripts
   lexer_comment_hash +
   lexer_string +
   lexer_string_escapes +
   lexer_start_underscore +
   lexer_cont_underscore;
  
lexer_style!* := lexer_style_rlisp;

symbolic inline procedure lexer_option o;
  not zerop land(lexer_style!*, o);

% This identifies characters that SMLbuilds up to make operator-like
% identifiers. It is relevant when lexer_option(lexer_sml_operators) is
% enabled, and by checking that first it avoids using the somewhat slow MEMQ
% test in cases where it is irrelevant.

symbolic inline procedure sml_opchar ch;
  lexer_option(lexer_sml_operators) and
  memq(ch, '(!! !% !& !$ !# !+ !- !/ !: !< != !> !? !@ !\ !~ !` !^ !| !*));

symbolic procedure all_sml_opchar l;
  null l or
  (sml_opchar car l and all_sml_opchar cdr l);

% Before using this lexer all the special tokens that it must handle
% must be passed to it. These are passed as strings. Some of these
% will be purely made up out of letters and would otherwise be treated
% a "symbols" but when advised about them the code here will allocate
% a category code and treat them as keywords. Thus one might have
%     lex_keywords '("if" "else" "begin" "end");
% These cases do not have any effect on how the lexer groups characters
% to form tokens, but do alter the result it gives in the cases concerned.
% Note that in RLISP an exclamation mark escapes the following character
% so it can appear in a symbol. A name written with one or more exclamation
% marks will never be treated as a keyword, and so even if the input 'begin'
% is special any of the inputs '!begin', 'b!egin' or '!b!e!g!i!n' (and of
% course many other variants) just yield a symbol.
%
% The second case is of keyword made up from punctuation marks. It is
% required (at least to start with) that keywords are either entirely
% alphanumeric or entirely punctuation. If no keywords have been set up then
% punctuation characters form single-character symbols. Thus for instance
% the input 'a:=b' would tokenise as a sequence of four symbols, 'a', ':',
% '=' and 'b'. If a multi-characters string has been passed to lex_keywords
% then dipthongs can be formed, so after
%     lex_keywords '(":=");
% the same input would tokenise to 3 items, the symbols 'a', a keyword ':='
% and then the symbol 'b'.
% If a sequence  punctuation marks is passed the behaviour is as if each
% prefix had been to. Thus after the above plus
%     lex_keywords '("<==>");
% the behaviour is just as if the user had presented
%     lex_keywords '(":" ":=" "<" "<=" "<==" "<==>");
% and any grammar using the lexer may thus need to deal with the intermediate
% cases.
%
% Input that is not exactly the string of characters making up a keyword will
% not be read as a keyword. That means that escape characters (!) have an
% effect. For alphanumeric cases the result will just be a symbol
%     beg!in            is the symbol whose name is 'begin'.
% For punctuation sequences an exclamation mark terminates a token and
% starts another (which will then always be a symbol). So
%     <=!=>             is the keyword '<=' followed by the
%                       symbol '=' followed by the keyword or symbol '>',
%                       much as if it had been written as '<= != >' with
%                       extra whitespace to make eveything clearer. 
%
% lex_keywords can be called multiple times so you do not have to declare
% all your keywords at once.
%
% After use of the lexer it will be desirable to call lex_cleanup() which
% will discard all tables and other information that was created. It will
% typically be vital to do this before starting to create a fresh grammar!
%
% To use the lexer call lex_init() and then repeatdly call yylex();
%
% At present this design provides for having just one lexer (and its tables)
% available at a time. I could imagine wanting to have several available
% for different purposes - the extension of this interface to support that
% case is something I will worry about later - maybe!

global '(lex_keyword_names lex_next_code lex_initial_next_code lex_codename);

% The various primitive lex types have pre-set codes. These exist once
% and for all so get established on a static base here.

%   :eof           End of file
%   :symbol        Either a single punctuation character that has not
%                  been declared as a keyword, or a letter followed
%                  by letters, digits and underscores, also excluding
%                  cases that are keywords, or any other string of
%                  characters with leading digits or underscores and any
%                  punctuation marks preceeded by exclamation marks.
%   :typename      A symbol whose name starts with a quote mark. This may
%                  arise in SML mode.
%   :string        Enclosed in double quotes. To include a double quote
%                  within a string double it, as in "with ""inside"" quotes".
%   :char          Enclosed in single quotes in C mode.
%   :number        Either an integer or a floating point value. I will need
%                  to review whether non-decimal representations for
%                  integers (eg 0xff) are supported.
%   :list          Either a quote or a backquote followed by Lisp-like
%                  data, for instance 'word or `(template ,sub1 ,@sub2 end).
%   :infix0 to !:infix9 and !:infixr0 to !:infixr9
%                  These are intended for use if a language needs some
%                  dynamic control over operator precedence. Specifically
%                  they are to cope with the SML "infix" and "infixr"
%                  declarations. It can be arranged that an operator such
%                  as "+" returns (say) !:infix5 as its lex code while leaving
%                  yylval to explain that it is "+" or "plus".

global '(initial_codename);

initial_codename :=
  '((0 . !:eof)      (1 . !:symbol)   (2 . !:typename)
    (3 . !:string)   (4 . !:char)     (5 . !:number)
    (6 . !:list)     (7 . !:infix0)   (8 . !:infix1)
    (9 . !:infix2)   (10 . !:infix3)  (11 . !:infix4)
    (12 . !:infix5)  (13 . !:infix6)  (14 . !:infix7)
    (15 . !:infix8)  (16 . !:infix9)  (17 . !:infixr0)
    (18 . !:infixr1) (19 . !:infixr2) (20 . !:infixr3)
    (21 . !:infixr4) (22 . !:infixr5) (23 . !:infixr6)
    (24 . !:infixr7) (25 . !:infixr8) (26 . !:infixr9));

for each p in initial_codename do
  put(cdr p, 'lex_fixed_code, car p);

% lex_codename is just used when generating trace output and maps from
% numeric codes back to the corresponding terminal symbols. Because it is
% only used for tracing I am not concerned about performance and I will use
% a simple association list.

lex_codename := initial_codename;

% All further terminals are given codes beyond the range used for the
% primitive ones.

lex_initial_next_code := lex_next_code := 1 + caar reverse initial_codename;

lex_keyword_names := nil;

global '(lex_escaped       lex_eof_code     lex_symbol_code
         lex_typename_code lex_number_code  lex_string_code
         lex_char_code     lex_list_code);

lex_eof_code      := get('!:eof,      'lex_fixed_code);
lex_symbol_code   := get('!:symbol,   'lex_fixed_code);
lex_typename_code := get('!:typename, 'lex_fixed_code);
lex_number_code   := get('!:number,   'lex_fixed_code);
lex_string_code   := get('!:string,   'lex_fixed_code);
lex_char_code     := get('!:char,     'lex_fixed_code);
lex_list_code     := get('!:list,     'lex_fixed_code);


% I will treat just very plain letters as items that can be in
% alphanumeric keywords. By "very plain" I mean the letters A-Z and
% a-x in the range U+0000 to U+007f. So accented letters. Greek letters and
% letters with style variations (eg small caps, fullwidth (U+ff41 et seq),
% mathematical (eg U+1d41a et seq)) are not treated as things that could
% make a simple symbol without the nees for escapes. 

symbolic inline procedure lex_unicode_alphabetic c;
  (c >= 0x41 and c <= 0x5a) or (c >= 0x61 and c <= 0x7a);

% Similarly only basic Latin digits can be used in numbers. "Other language"
% digits and mathematical presentation forms will not count.

symbolic inline procedure lex_unicode_numeric c;
  (c >= 0x30 and c <= 0x39);

% For hexadecimal input I am using basic Latin digits and letters.

symbolic procedure lex_hexval c;
  (if n >= 0x30 and n <= 0x39 then n - 0x30            % "0" to "9"
   else if n >= 0x41 and n <= 0x46 then n - 0x41 + 10  % "A" to "F"
   else if n >= 0x61 and n <= 0x66 then n - 0x61 + 10  % "a" to "f"
   else nil) where n = car widestring2list symbol!-name c;

symbolic procedure lex_keywords l;
  for each x in l do
    begin
      scalar w, ok, pre;
% I will see what all the characters in the string are. By using
% widestring2list I get the codes for those characters even if some
% are over U+00FF. The resulting list is a list of integers...
      w := widestring2list x;
      if null w then rederr "Empty string passed to lex_keywords";
% Now I will check if the string starts with a letter and continues
% with letters, digits and underscores...
      ok := lex_unicode_alphabetic car w;
      for each c in cdr w do
        if not lex_unicode_alphabetic c and
           not lex_unicode_numeric c and
           c neq 0x5f then ok := nil;      % 0x5f is '_'
      if null cdr w or ok then << % Simple case without dipthong consequences
        w := intern x;
        if null get(w, 'lex_code) then <<
          lex_keyword_names := w . lex_keyword_names;
          if null get(w, 'lex_next_code) then <<
            put(w, 'lex_code, lex_next_code);
            lex_codename := (lex_next_code . w) . lex_codename;
            if !*tracelex then <<
              princ "Token '";
              prin w;
              princ "' allocated code ";
              print lex_next_code >>;
            lex_next_code := lex_next_code + 1 >> >>;
        return >>; % remember that RETURN just exits the begin/end block.
% Now I have something that may be introducing a dipthong. I will set things
% up so that each case where there is a prefix "ABC" "X" that the token "ABC"
% is a keyword and then I will go
%    put(ABC, 'lex_dipthong, (X . ABCX) . get(abc, 'lex_dipthing))
     x := intern x;
     if not get(x, 'lex_code) then << % may have been seen already
        lex_keyword_names := x . lex_keyword_names;
        put(x, 'lex_code, lex_next_code);
        lex_codename := (lex_next_code . x) . lex_codename;
        lex_next_code := lex_next_code + 1;
% Recurse to deal with prefixes...
        pre := list2widestring reverse cdr reverse w;
        lex_keywords list pre;
        pre := intern pre;
        w := intern list2widestring list lastcar w;
        if !*tracelex then <<
          if not zerop posn() then terpri();
          princ "dipthong data '";
          prin pre;
          princ "' plus '";
          prin w;
          princ "' => '";
          prin x;
          printc "'" >>;
        put(pre, 'lex_dipthong, (w . x) . get(pre, 'lex_dipthong)) >>;
    end;

symbolic procedure lex_cleanup();
  begin
% Note that !:symbol etc retain their lex_code properties since the values
% they have are universal.
    for each x in lex_keyword_names do <<
      remprop(x, 'lex_code);
      remprop(x, 'lex_dipthong) >>;
    lex_keyword_names := nil;
    lex_next_code := lex_initial_next_code;
    lex_codename := initial_codename;
  end;

% The following pair of procedures provide for switching back and forth  
% between "different lexers".
% 
% Specifically, lex_save_context() returns some data that, when fed back into 
% lex_restore_context(), should have everything right back at the point after 
% you made your lex_keywords calls but before you called lex_init().

symbolic procedure lex_save_context();
  for each w in lex_codename collect (get(intern cdr w, 'lex_dipthong) . w);

symbolic procedure lex_restore_context context;
  begin
    scalar token, dipthong, code;
    lex_cleanup();
    for each x in context do <<
      dipthong := car x; code := cadr x; token := intern cddr x; 
      if not get(token, 'lex_fixed_code) then <<
        if code > lex_next_code then lex_next_code := code;
        put(token, 'lex_dipthong, dipthong);
        put(token, 'lex_code, code);
        lex_codename := (code . token) . lex_codename;
        lex_keyword_names := token . lex_keyword_names >> >>
  end;

% This procedure returns an association list mapping from integer category 
% codes (same as returned by yylex()) to tokens (as symbols). The list is 
% ordered by category code (decreasing). 
%
% If the lexer's internals are changed around such that lex_codename 
% disappears (perhaps, is replaced by a hash table), this should continue
% to export the same structure for consumption by other code, like 
% the parser generator.
symbolic procedure lex_export_codes(); 
  sort(lex_codename, function ordopcar); %% does this do what I think?

% I keep a circular buffer with the last 64 characters that have been
% read. Initially the buffer contains NILs rather than characters, so I can
% tell when it is only partially filled.

% Note that in CSL (ar least) readch will return a character and it will
% interpret UTF-8 multi-byte sequences as single characters where necessary.
% So this code is (at least on CSL) unicode friendly.

fluid '(lex_char yypeek_char!*);
yypeek_char!* := nil;

symbolic procedure yyreadch();
  if not null yypeek_char!* then <<
    lex_char := yypeek_char!*;
    yypeek_char!* := nil;
    lex_char >>
  else <<
    lex_char := readch();
    if lex_char = !$eol!$ then which_line := which_line + 1;
    if lex_char neq !$eof!$ then <<
      last64p := last64p + 1;
      if last64p = 64 then last64p := 0;
      putv(last64, last64p, lex_char) >>;
    lex_char >>;

% yypeek() must not mess with lex_char

symbolic procedure yypeek();
  begin
    scalar lex_char;
    if null yypeek_char!* then yypeek_char!* := yyreadch();
    return yypeek_char!*
  end;

switch parse_errors_fatal;

symbolic procedure yyerror msg;
  begin
    scalar c;
    terpri();
    prin2 "+++++ Parse error at line "; prin1 which_line; prin2 ":";
    if atom msg then msg := list msg;
    for each s in msg do << prin2 " "; prin2 s >>;
    terpri();
    for i := 1:64 do <<
      last64p := last64p + 1;
      if last64p = 64 then last64p := 0;
      c := getv(last64, last64p);
      if not (c = nil) then prin2 c >>;
    princ "^^^";    % Marks where we had read as far as...
    if not (c = !$eol!$) then terpri();
    if lex_char = !$eof!$ then printc "<EOF>";
    if !*parse_errors_fatal then <<
      if not zerop posn() then terpri();
      printc "+++ Quitting (parse_errors_fatal is set)";
      quit >>;
  end;

% Before a succession of calls to yylex() it is necessary to
% ensure that lex_char is set suitably and that the circular buffer
% used to store characters for error messages is ready for use.

global '(lex_peeked);

symbolic procedure lex_init();
 << last64 := mkvect 64;
    last64p := 0;
    which_line := 1;
    if_depth := 0;
    if !*tracelex then <<
      if posn() neq 0 then terpri();
      printc "yylex initialized" >>;
    lex_peeked := nil;
    yyreadch() >>;

%
% The following version of YYLEX provides RLISP with a facility for
% conditional compilation.  The protocol is that text is included or
% excluded at the level of tokens.  Control by use of new reserved
% tokens #if, #else and #endif.  These are used in the form:
%    #if (some Lisp expression for use as a condition)
%    ... RLISP input ...
%    #else
%    ... alternative RLISP input ...
%    #endif
%
% The form
%    #if C1 ... #elif C2 ... #elif C3 ... #else ... #endif
% is also supported.
%
% Conditional compilation can be nested.  If the Lisp expression used to
% guard a condition causes an error it is taken to be a FALSE condition.
% It is not necessary to have an #else before #endif if no alternative
% text is needed. Although the examples here put #if etc at the start of
% lines this is not necessary (though it may count as good style?). Since
% the condition will be read using RLISPs own list-reader there could be
% condtional compilation guarding parts of it - the exploitation of that
% possibility is to be discouraged!
%
% "#else" is treated exacty as "#elif t" and any "#else", "#elif" or
% "#endif" statements that are stray at top level not associated with an
% "#if" will be trerated as if there had been an extra "#if t" just before
% the start of the file.
%
% Making the condition a raw Lisp expression makes sure that parsing it
% is easy. It makes it possible to express arbitrary conditions, but it is
% hoped that most conditions will not be very elaborate - things like
%    #if (not (member 'csl lispsystem!*))
%         error();
%    #else
%         magic();
%    #endif
% or
%    #if debugging_mode   % NB if variable is unset that counts as nil...
%    print "message";     % ...so care should be taken to select the most...
%    #endif               % ...useful default sense for such tests.
% should be about as complicated as reasonable people need.
%
% Two further facilities are provided:
%    #eval (any lisp expression)
% causes that expression to be evaluated at parse time.  Apart from any
% side-effects in the evaluation the text involved is all ignored. It is
% expected that this will only be needed in rather curious cases, for
% instance to set system-specific options for a compiler.
%
%    #define symbol value
% where the value should be another symbol, a string or a number, causes
% the first symbol to be mapped onto the second value wherever it occurs in
% subsequent input.  No special facility for undoing the effect of a
% #define is provided, but the general-purpose #eval could be used to
% remove the '#define property that is involved. The result generated this
% was is not re-scanned and can not end up being treated as a preprocessor
% directive.
%
% NOTE: The special symbols #if etc are NOT recognised within Lisp
%       quoted expressions, so test like the following will be
%       ineffective:
%            a := '(
%                P
%            #if q_is_wanted
%                Q
%            #endif
%                R);
%       but on the other hand code like
%            if sym = '!#if then ...
%       behaves the way that had probably been wanted. Unlike the C
%       preprocessor, this system recognizes directives within rather than
%       just at the start of lines.

symbolic procedure lex_process_directive();
  begin
    scalar w;
    if yylval = '!#endif or yylval = !$eof!$ then return t
    else if yylval = '!#if then <<
      read_s_expression();
      w := errorset(yylval, nil, nil);
      if errorp w or null car w then return lex_skip_to_else_or_endif t
      else return t >>
    else if yylval = '!#else then return lex_skip_to_else_or_endif nil
    else if yylval = '!#elif then <<
      read_s_expression();
      return lex_skip_to_else_or_endif nil >>
    else return nil
  end;

% This detects end of file, "#endif" as an unescaped symbol and
% optionally "#else" or "elif TRUE".

symbolic procedure lex_is_else_or_endif(w, elif);
  if w = lex_eof_code then t
  else if w neq lex_symbol_code then nil
  else if lex_escaped then nil
  else if yylval = '!#endif then t
  else if not elif then nil
  else if yylval = '!#else then t
  else if yylval neq '!#elif then nil
  else <<
    read_s_expression();
    w := errorset(yylval, nil, nil);
    ((not errorp w) and car w) >>;
    

symbolic procedure lex_skip_to_else_or_endif elif;
  begin
% This skips to the next "#endif", and if its argument is true
% it will also stop at either "else" or "#elif true".
% It also stops at end of file just to be safe. There are five special
% treatments that may be worth noting:
% (1) As it scans if this code finds a futther "#if" it will skip
%     ahead to the "#endif" matching that before looking for the "#endif"
%     that it wants.
% (2) A word "#if" or "#endif" that is entered with escape characters
%     will not be treated as special. So "!#endif" and "#!endif" and
%     "#endi!f" (and so on) are treated as being merely random tokens and
%     so are skipped past.
% (3) Comments and all material in them are ignored while setching for
%     the "#endif". In RLISP mode that will mean anything from a percent
%     characdter to the end of line, or anything from the symbol "comment"
%     to the next dollar or semicolon.
% (4) If the character "'" (ie single quote) is found then RLISP syntax
%     has that followed by a Lisp style s-expression. Keywords present as
%     or within that expression will not be recognized or processed.
% (5) The keyword "#elif" is not of itself significant, but the item
%     after it will be read as an s-expression and not recognized as a
%     keyword. Similarly for "#eval" and "#define"
% So here is a sequence illustrating some of the above
%        !#endif       [escape character present, so nothing special]
%        '#endif       [Lisp-style quoted, so nothing special]
%        "#endif"      [a string not a symbol, so nothing special]
%        #elif #endif  [In place as a condition for #elif, so nothing special]
%        #eval (de #endif (#endif) #endif) [similarly]
%        comment #endif;  [Within a comment, so nothing special]
%        % #endif      [Within a comment, so nothing special]
%        !#elif #endif [The #elif is escaped so is not special, hence
%                       the #endif here IS noticed and acted upon]
% Is it always fun when there is significantly more comment than code?
%
    while not lex_is_else_or_endif(lex_basic_token(), elif) do <<
      if yylval = '!#if and not lex_escaped then <<
        read_s_expression();
        lex_skip_to_else_or_endif nil >>
      else if yylval = '!#define and not lex_escaped then <<
        read_s_expression();
        read_s_expression() >>
      else if (yylval = '!#elif or
               yylval = '!#eval) and not lex_escaped then
        read_s_expression() >>;
    return t
  end;

symbolic procedure yylex();
  begin
    scalar w, w1, done;
% I take a rather robust view here - words that are intended to be used as
% keywords may not be written with included escape characters. Thus for
% instance this lexer will view "be!gin" or "!begin" as being a simple
% symbol and NOT being the keyword "begin".
    w := lex_basic_token();
    while not done and
          w = lex_symbol_code and
          not lex_escaped and
          lexer_option(lexer_hashif) do <<
% First deal with "#if"  conditionals.
      if lex_process_directive() then w := lex_basic_token()
% Also deal with new "#define" settings.
      else if yylval = '!#define then <<
        read_s_expression();
        w := yylval;   % Should be a symbol
        read_s_expression();
        w1 := yylval;  % Should be symbol, number or string
% I only instate the definitition if it seems sensible.
        if idp w and (idp w1 or numberp w1 or stringp w1) then <<
          if not zerop posn() then terpri();
          princ "+++ "; prin w; princ " => "; print w1;
          put(1, '!#define, list w1) >>;
        w := lex_basic_token() >>
% Next the "#eval" directive
      else if yylval = '!#eval then <<
        read_s_expression();
        errorset(yylval, nil, nil);
        w := lex_basic_token() >>
% If I have a symbol previously set using "#define" then expand it.
% The expansion will not be subject to re-expansion and will not be
% treated as a preprocessor-style keyword.
      else if w1 := get(yylval, '!#define) then <<
        yylval := car w1;
        if numberp w1 then w := lex_number_code
        else if stringp w1 then w := lex_string_code;
        done := t >>
% A symbol that is nothing special merely stands for itself.
      else done := t >>;
    if !*tracelex then <<
      if posn() neq 0 then terpri();
      prin2 "yylex = "; prin1 yylval; prin2 " type "; print w >>;
    return w;
  end;

% lex_basic_token() will read the next token from the current input stream
% and leave a value in yylval to show what was found.
% It recognize the quote prefix, as in '(lisp expression) and
% `(backquoted thing).  The return value is a numeric code.
% It leaves a variable lex_escaped true if the "word" that was
% read had any "!" characers used to escape parts of it.

global '(lex_peeked lex_peeked_yylval lex_peeked_escaped);

% There are a range of different ways in which a comment might start!

% Note that if "#" starts a line comment it may be hard to input "#if" and so
% the conditional processing stuff will be unavailable.

symbolic procedure lex_start_line_comment ch;
  (ch = '!% and lexer_option(lexer_comment_percent)) or
  (ch = '!# and lexer_option(lexer_comment_hash)) or
  (ch = '!/ and lexer_option(lexer_comment_slashslash) and yypeek() = '!/);

symbolic procedure lex_skip_line_comment();
  << while not (lex_char = !$eol!$ or lex_char = !$eof!$) do yyreadch();
     t >>;

symbolic procedure lex_start_block_comment ch;
  (ch = '!/ and yypeek() = '!* and lexer_option(lexer_comment_slashstar)) or
  (ch = '!( and yypeek() = '!* and lexer_option(lexer_comment_lparstar));

symbolic procedure lex_skip_block_comment();
  begin
    scalar flavour, term;
    flavour  := lex_char;   % Tells if it was /* or (* style
    if flavour = '!/ then term := '!/
    else term := '!);
    lex_char := yyreadch(); % reads the "*", previouly peeked
    while ((lex_char := yyreadch()) neq '!* or
           yypeek() neq term) and
          lex_char neq !$eof!$ do <<
       if lexer_option lexer_comment_nesting and
          lex_start_block_comment lex_char then
         lex_skip_block_comment() >>;
    lex_char := yyreadch();  % reads the terminating character.
    return t
  end;

% Symbols have a range of rules about initial and subsequent characters.

symbolic procedure lexer_word_starter ch;
  liter ch or
  (ch = '!_ and lexer_option(lexer_start_underscore)) or
  (ch = '!' and lexer_option(lexer_start_prime)) or
  (ch = '!\ and lexer_option(lexer_start_backslash));

symbolic procedure lexer_word_continues ch;
  liter ch or
  digit ch or
  (ch = '!_ and lexer_option(lexer_cont_underscore)) or
  (ch = '!' and lexer_option(lexer_cont_prime));

symbolic procedure lex_basic_token();
  begin
    scalar r, w;
% The item I peeked ahead and read will have started with a letter or an
% exclamation mark so should be a :symbol or some keyword, and not either
% a number or a string. And one further key fact is that it can not have
% started with a "#".
% Oh dear, what about the input
%     #!#if
% well that will return # and then #if, and because the inner "#if" is
% introduced with an exclamation mark it can not cause nested attempts at
% look-ahead. Whew.
    if lex_peeked then <<
      r := lex_peeked;
      yylval := lex_peeked_yylval;
      lex_escaped := lex_peeked_escaped;
      lex_peeked := lex_peeked_yylval := lex_peeked_escaped := nil;
      return r >>;
    lex_escaped := nil;
% First skip over whitespace. Note that at some stage in the future RLISP
% may want to make newlines significant and partially equivalent to
% semicolons, but that is not supported at present. Indeed in this lexer
% at present newline are treated like all other whitespace and are discarded.
% So any syntax that needs to know about them is out of luck. Similarly
% any syntax that depends on other fine details of whitespace such as
% the distinction between space and tab, or indentation levels, will again
% be out of luck - anybody needing that will need to provide their own
% lexer. Possibly by modifying this one, or possibly by starting from
% scratch.
    while lex_char = '!  or
          lex_char = !$eol!$ or
          lex_char =  '!	 or  % Note a tab character on this line
          (lex_start_line_comment lex_char and
           lex_skip_line_comment()) or
          (lex_start_block_comment lex_char and
           lex_skip_block_comment()) do yyreadch();
    if lex_char = !$eof!$ then <<
      yylval := lex_char;
      return lex_eof_code >>; 
%
% Symbols start with a letter or an escaped character and continue with
% letters, digits, underscores and escapes.
    if lexer_word_starter lex_char or
       (lex_char = '!! and lexer_option(lexer_escape_pling) and <<
          yyreadch() where !*raise = nil, !*lower = nil;
          lex_escaped := t >>) then <<
      r := lex_char. r;
      while lexer_word_continues yyreadch() or
            (lex_char = '!! and lexer_option(lexer_escape_pling) and <<
               yyreadch() where !*raise = nil, !*lower = nil;
               lex_escaped := t >>) do r := lex_char . r;
% If there was a '!' in the word I will never treat it as a keyword.
% That situation is spottable by virtue of the variable lex_escaped.
% Note that list2widestring is passed a list of symbols here not integers,
% bur recent implementations of it support that case.
      yylval := intern list2widestring (r := reversip r);
%     if !*tracelex then <<
%       princ "symbol is '"; prin yylval;
%       princ "' lex_escaped="; prin lex_escaped;
%       princ " lex_code="; print get(yylval, 'lex_code) >>;
% If the token I just saw was COMMENT and Rlisp mode is active I will
% discard characters up to a ";" or "$" and then look for a token
% again. Note that the stuff within the comment is read character by
% character and any stuff at all apart from ";" and "$" can appear and
% will be ignored.
      if yylval = 'COMMENT and
         lexer_option(lexer_lispquote) and
         not lex_escaped then <<
        while not (lex_char = '!; or lex_char = '!$) do yyreadch();
        yyreadch();
        return lex_basic_token() >>;
      if not lex_escaped and (w := get(yylval, 'lex_code)) then return w
      else if eqcar(r, '!') or
              get(r, 'lex_is_typename) then return lex_typename_code
      else return lex_symbol_code >>
% Numbers are either integers or floats. A floating point number is
% indicated by either a point "." or an exponent marker "e". In the code
% here I keep a flag (in w) to indicate if I had a floating or integer
% value, but in the end I ignore this and hand back the lexical category
% for :number in both cases.
    else if digit lex_char then <<
% I support hexadecimal input with syntax like 0xDDDD for hex digits DDDD.
      if lex_char = '!0 and (yypeek() = 'x or yypeek() = '!X) then <<
        yylval := 0;
        yyreadch();
        while (w := lex_hexval yyreadch()) do yylval := 16*yylval + w;
        return lex_number_code >>;
      r := list lex_char;
      while << yyreadch(); digit lex_char >> do r := lex_char . r;
      if lex_char = '!. then <<
        w := t;       % Flag to indicate floating point
        r := lex_char . r;
        while << yyreadch(); digit lex_char >> do r := lex_char . r >>;
% I permit the user to write the exponent marker in either case.
      if lex_char = '!e or lex_char = '!E then <<
% If the input as 1234E56 I expand it as 1234.0E56
        if not w then r := '!0 . '!. . r;
        w := t;
        r := '!e . r;
        yyreadch();
        if lex_char = '!+ or lex_char = '!- then <<
          r := lex_char . r;
          yyreadch() >>;
% If there is no digit written after "E" I insert a zero. Thus overall the
% input 17E gets treated as 17.0E0
        if not digit lex_char then r := '!0 . r
        else <<
          r := lex_char . r;
          while << yyreadch(); digit lex_char >> do r := lex_char . r >> >>;
% Here I have a number, so I can use compress to parse it.
      yylval := compress reversip r;
      return lex_number_code >>
    else if lex_char = '!" and lexer_option(lexer_string) then <<
      if lexer_option(lexer_string_rlisp) then
      begin
        scalar !*raise, !*lower;      % Make !*raise & !*lower both nil.
% The key behaviour here is that a doubled doublequote does not terminate
% a string - it stands for a single doublequote. Thus "ab""cd" is a single
% string with 5 characters in it. a, b, ", c and d.
        while yyreadch() neq '!" or
              (yypeek() = '!" and yyreadch() = '!") do
          r := lex_char . r;
      end
      else
      begin
        scalar !*raise, !*lower;      % Make !*raise & !*lower both nil.
        scalar prev;
% The key behaviour here is that " terminates a string unless preceeded
% by \. Thus "ab\"cd" is a string with 5 characters in it. a, b, ", c, and d.
% "ab""cd" would be two strings a, b and c, d.
        while yyreadch() neq '!" or
              prev = '!\ do <<
           prev := lex_char;
           r := lex_char . r >>;
          end;
      yyreadch();  % Go beyond the terminating doublequote.
      yylval := list2widestring reversip r;
      return lex_string_code >>
    else if lex_char = '!' and lexer_option(lexer_char) then <<
      begin
        scalar !*raise, !*lower;      % Make !*raise & !*lower both nil.
        repeat <<
          while not (yyreadch() = '!') do r := lex_char . r;
          r := lex_char . r;
          yyreadch() >> until not (lex_char = '!');
      end;
      yylval := list2widestring reversip cdr r;
      return lex_char_code >>
% "'" and "`"(backquote) can introduce Lisp syntax S-expressions
    else if lex_char = '!' and lexer_option(lexer_lispquote) then <<
      yyreadch();
      read_s_expression();
      yylval := list('quote, yylval);
      return lex_list_code >>
    else if lex_char = '!` and lexer_option(lexer_lispquote) then <<
      yyreadch();
      read_s_expression();
      yylval := list('backquote, yylval);
      return lex_list_code >>
    else <<
      yylval := lex_char;
% I take special notice of end of file, since it is fairly drastic.
% In particular I do not attempt to advance lex_char beyond it. So I do
% TWO things here: I avoid advancing the input, and I return the lex_eof_code
% as an end-of-file indication.
      if yylval = !$eof!$ then return lex_eof_code;
      if (yylval = '!# and lexer_option(lexer_hashif)) or
         get(yylval, 'lex_dipthong) or
         sml_opchar(yylval) then yyreadch()
      else lex_char := '! ;  % Try to avoid reading beyond where I HAVE to.
% There is a bit of horribly magic needed here. I want
%  #if #else #elif #endif #eval and #define
% to be accepted without needing an initial exclamation mark.
% The spelling "!#if" (etc) will already have been coped with,
% it is the case with no escape character I am concerned
% about here, and that requires a 1-symbol look-ahead. Well even there
% the look ahead only has to consider a whole symbol if the character after
% the "#" is a letter (or an "!").
      if (yylval = '!# and lexer_option(lexer_hashif) and liter lex_char)
         or lex_char = '!! then <<
        r := lex_basic_token();
% Observe that I only check yylval here (not the type of token returned).
% That is because words like "if" and "define" stand a real chance of being
% keywords! For this to be safe it is important that lex_basic_token
% always updates yylval whatever it returns.
        if memq(yylval,'(if else elif endif define eval)) then <<
          yylval := intern list2widestring(
                      '!# . widestring2list symbol!-name yylval) >>
        else <<   % set up the peeked token for later processing.
          lex_peeked := r;
          lex_peeked_yylval := yylval;
          lex_peeked_escaped := lex_escaped;
          yylval := '!#;
          lex_escaped := nil >> >>;
        while w := atsoc(lex_char, get(yylval, 'lex_dipthong)) do <<
          yylval := cdr w;
          yyreadch() >>;
% Here I have an operator-like token which may be just one character or
% it may be a dipthong. So for instance ":=" might have been read. In the
% SML case I have to allow that I might be in the middle of reading ":=:"
% or some such... Well I think that supporting the ML case here ends up
% much less messy than I had feared.
      if lexer_option(lexer_sml_operators) and
         all_sml_opchar (w := explode2 yylval) then <<
        while sml_opchar lex_char do <<
          w := append(w, list lex_char);
          yyreadch() >>;
        yylval := intern list2string w >>;
      if w := get(yylval, 'lex_code) then return w
      else return lex_symbol_code >>
  end;

%
% I use a hand-written recursive descent parser for Lisp S-expressions
% mainly because the syntax involved is so VERY simple. A rough sketch of
% the syntax required is given here, but in reality (in part because I do
% not want to have to report syntax errors) I implement a more liberal
% syntax, especially as it relates to dotted-pair notation. This of course
% is one of the natural dangers in using recursive descent... the syntax
% actually parsed is only properly defined by direct reference to the code.
%

% s_tail      =   ")" |
%                 "." s_expr ")" |
%                 s_expr s_tail;
% 
% s_vectail   =   "]" |
%                 s_expr s_vectail;
% 
% s_expr      =   symbol |
%                 number |
%                 string |
%                 "(" s_tail |
%                 "[" s_vectail |
%                 "'" s_expr |
%                 "`" s_expr |
%                 "," s_expr |
%                 ",@" s_expr;

dot_char     := char!-code '!.;
rpar_char    := char!-code '!);
rsquare_char := char!-code '!];

symbolic procedure read_s_expression();
 <<
% At the start of an S-expression I want to check for the characters
% "(", "[" and ",". Thus I need to skip whitespace.
    while lex_char = '!  or lex_char = '!$eol!$ do yyreadch();
    if lex_char = '!( then begin
      scalar r, w, w1;
      yyreadch();
      w := read_s_expression();
      while not (w = rpar_char or w = dot_char or w = 0) do <<
        r := yylval . r;
% Note that at the end of the list read_s_expression() will read the ")"
% as a token.
        w := read_s_expression() >>;
      if not (w = dot_char) then yylval := reversip r
      else <<
        read_s_expression();  % Thing after the "."
        w := yylval;
% Reverse the list putting a dotted item on the end.
        while r do <<
          w1 := cdr r;
          rplacd(r, w);
          w := r;
          r := w1 >>;
        yylval := w;
        while lex_char = '!  or lex_char = '!$eol!$ do
            yyreadch();
% When I find a ")" I do not read beyond it immediately, but reset lex_char
% to whitespace. This may help prevent unwanted hangups in interactive use.
        if lex_char = '!) then lex_char := '!   % turn ')' into a blank.
        else yyerror "Syntax error with '.' notation in a list" >>;
      return '!:list end
% "[" introduces a simple vector.
    else if lex_char = '![ then begin
      scalar r, w, w1;
      yyreadch();
      w := read_s_expression();
      w1 := -1;
      while not (w = rsquare_char or w = 0) do <<
        r := yylval . r;
        w1 := w1 + 1;
        w := read_s_expression() >>;
% Create a vector of the correct size and copy information into it.
      w := mkvect w1;
      r := reversip r;
      w1 := 0;
      while r do <<
        putv(w, w1, car r);
        w1 := w1 + 1;
        r := cdr r >>;
      yylval := w;
      return '!:list end
% I spot "," and ",@" here, and should wonder if I should (a) police that
% they are only expected to make sense within the scope of a "`" and (b)
% whether I ought to expand them in terms of LIST, CONS, APPEND etc here.
% For now I just hand back markers that show where they occured.
    else if lex_char = '!, then <<
      yyreadch();
      if lex_char = '!@ then <<
        yyreadch();
        read_s_expression();
        yylval := list('!,!@, yylval) >>
      else <<
        read_s_expression();
        yylval := list('!,, yylval) >>;
      'list >>
% Care with ")" and "]" not to read ahead further than is essential.
    else if lex_char = '!) or lex_char = '!] or lex_char = '!. then <<
      yylval := lex_char;
      lex_char := '! ;
      char!-code yylval >>      
% In most cases (including "'" and "`") I just hand down to read a token.
% This covers the cases of symbols, numbers and strings.
    else lex_basic_token() >>;


endmodule;

end;
