% yylex.red

% Author: Arthur Norman, with changes by Zach Hauser, 2016

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
%         names and strings.
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
        lexer_style_rlisp lexer_style_c lexer_style_sml lexer_style_simple);

#define lexer_comment_percent        1    %  "%..." is a comment
#define lexer_comment_hash           2    %  "#..." is a comment
#define lexer_comment_slashslash     4    %  "//..." is a comment
#define lexer_comment_slashstar      8    %  "/*...*/" is a comment
#define lexer_comment_lparstar      16    %  "(*...*)" is a comment
#define lexer_comment_nesting       32    %  block comments nest
% BEWARE - the nested option is not implemented yet, so SML-style
% comments of the form "(* xxx (* xxx *) xxx *)" would give problems.
% See the code at lex_skip_block_comment for where an upgrade to
% support nesting would go.
#define lexer_hashif                64    %  support for "#if"
#define lexer_string               128    %  double quote starts a string
#define lexer_char                 256    %  single quote starts a character
#define lexer_string_escapes      1024    %  support "\x" escapes in strings
#define lexer_string_rlisp        2048    %  "a""b" is string for 'a"b'
#define lexer_start_underscore    4096    %  _word is a symbol
#define lexer_start_backslash     8192    %  \word is a symbol
#define lexer_start_prime        32768    %  'word is a (special) symbol
#define lexer_cont_underscore    65536    %  a_b is a symbol
#define lexer_escape_pling      131072    %  a!+!*!^b is a symbol
#define lexer_cont_prime        262144    %  a'' is a symbol
#define lexer_sml_operators     524288    %  +++*+++ is a symbol
% sml_operators is not yet supported. To use multi-character operator-like
% symbols it is at present essential that the sequence forms an explicit
% terminal symbol in the grammar. Cases such as ":=" and "=>" and "::"
% are really liable to, so I hope this will not be too much of a burden.
% if this were to be changed it should be in the code that handles
% lexical dipthongs.
#define lexer_lispquote        1048576    %  '(s-expression) accepted
#define lexer_spare1           2097152    % 2^21   spare
#define lexer_spare2           4194304    % 2^22   spare
#define lexer_spare3           8388608    % 2^23   spare
#define lexer_spare4          16777216    % 2^24   spare

% Establish simple names for some plausible combinations of options.

lexer_style_rlisp :=
   lexer_comment_percent +
   lexer_hashif +
   lexer_string +
   lexer_string_rlisp +
   lexer_cont_underscore +
   lexer_escape_pling +
   lexer_lispquote;
  
lexer_style_c :=
   lexer_comment_slashslash +
   lexer_comment_slashstar +
   lexer_char +
   lexer_string +
   lexer_string_escapes +
   lexer_start_underscore +
   lexer_cont_underscore;
  
lexer_style_sml :=
   lexer_comment_lparstar +
   lexer_comment_nesting +
   lexer_string +
   lexer_string_escapes +
   lexer_start_underscore +
   lexer_cont_underscore +
   lexer_start_prime +
   lexer_cont_prime +
   lexer_sml_operators;
  
lexer_style_simple :=
   lexer_comment_hash +
   lexer_string +
   lexer_string_escapes +
   lexer_start_underscore +
   lexer_cont_underscore;
  
lexer_style!* := lexer_style_rlisp;

symbolic inline procedure lexer_option o;
  not zerop land(lexer_style!*, o);


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

put('!:eof,     'lex_fixed_code, 0);
put('!:symbol,  'lex_fixed_code, 1);
put('!:typename,'lex_fixed_code, 2);
put('!:string,  'lex_fixed_code, 3);
put('!:char,    'lex_fixed_code, 4);
put('!:number,  'lex_fixed_code, 5);
put('!:list,    'lex_fixed_code, 6);

% lex_codename is just used when generating trace output and maps from
% numeric codes back to the corresponding terminal symbols. Because it is
% only used for tracing I am not concerned about performance and I will use
% a simple association list.

lex_codename := '((0 . !:eof)    (1 . !:symbol) (2 . !:typename)
                  (3 . !:string) (4 . !:char)   (5 . !:number)
                  (6 . !:list));

% All further terminals are given codes beyond the range used for the
% primitive ones.

lex_initial_next_code := lex_next_code := 7;

lex_keyword_names := nil;

global '(lex_escaped
         lex_eof_code lex_symbol_code lex_number_code
         lex_string_code lex_char_code lex_list_code);

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
          put(w, 'lex_code, lex_next_code);
          lex_codename := (lex_next_code . w) . lex_codename;
          if !*tracelex then <<
            princ "Token '";
            prin w;
            princ "' allocated code ";
            print lex_next_code >>;
          lex_next_code := lex_next_code + 1 >>;
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
    lex_codename := '((0 . !:eof)    (1 . !:symbol) (2 . !:typename)
                      (3 . !:string) (4 . !:char)   (5 . !:number)
                      (6 . !:list));
  end;

% The following pair of procedures provide for switching back and forth  
% between "different lexers".
% 
% Specifically, lex_save_context() returns some data that, when fed back into 
% lex_restore_context(), should have everything right back at the point after 
% you made your lex_keywords calls but before you called lex_init(). 
symbolic procedure lex_save_context();
  mapcar(lex_codename,
    function (lambda w; get(intern cdr w, 'lex_dipthong) . w));

symbolic procedure lex_restore_context(context);
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

fluid '(yypeek_char!*);
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

symbolic procedure yypeek();
 << if null yypeek_char!* then yypeek_char!* := readch();
    yypeek_char!* >>;

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
    if not (c = !$eol!$) then terpri();
    if lex_char = !$eof!$ then printc "<EOF>"
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
% Making the condition a raw Lisp expression makes sure that parsing it
% is easy. It makes it possible to express arbitrary conditions, but it is
% hoped that most conditions will not be very elaborate - things like
%    #if (not (member 'csl lispsystem!*))
%         error();
%    #else
%         magic();
%    #endif
% or
%    #if debugging_mode   % NB if variable is unset that counts as nil
%    print "message";      % so care should be taken to select the most
%    #endif               % useful default sense for such tests
% should be about as complicated as reasonable people need.
%
% NOTE: in the implementation of this in rlisp/tok.red there was for
% some time a bug whereby
%  #if t ; ... ; #elif x ; ... ; #else XXX #endif
% included the text XXX because #else was taken as just flipping the
% acceptance state. I need to review and test the code here to ensure that
% it does not suffer from the same badness!
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


symbolic procedure yylex();
  begin
    scalar w, done;
% I take a rather robust view here - words that are intended to be used as
% keywords may not be written with included escape characters. Thus for
% instance this lexer will view "be!gin" or "!begin" as being a simple
% symbol and NOT being the keyword "begin".
    w := lex_basic_token();
% The "while not done" loop is so that I can restart the scan after seeing
% a pre-processor directive such as #if.
    while not done do <<
% The word "COMMENT" introduces a comment that terminates at the next ";"
% or "$". But note that "co!mment" (for instance) would not since that will
% be classifed as a symbol not as a keyword because of the embedded escape.
% So if you REALLY want to have a symbol with name "comment" in your input
% you can write it as (again for instance) "!comment" so it is not processed
% here. Ha ha ha "comment" is now a keyword in that it will never generate
% a lexer-code to pass back as a result. But it is recognised in the same
% sort of circumstances that keywords are. Note that I only accept COMMENT
% if I will also accept the special syntax    '(s-expression)   so I am
% parsing RLISP.
    while w = lex_symbol_code and yylval = 'COMMENT and
          lexer_option(lexer_lispquote) and
          not lex_escaped do <<
      while not (lex_char = '!; or lex_char = '!$) do yyreadch();
      yyreadch();
      w := lex_basic_token() >>;
% If a word was spelt out directly (without any escape characters in it) it
% may be a keyword - if it is, then deal with it it here.
    if w = lex_symbol_code and not lex_escaped then <<
% #define provides a simple (very simple) macro substitution scheme that is
% probably too limited to be really useful. I will only make the substitution
% if "#if" processing is enabled.
      if done := get(yylval, '!#define) and lexer_option(lexer_hashif) then <<
        yylval := done;
        if numberp done then w := lex_number_code
        else if stringp done then w := lex_string_code;
        done := t >> 
      else done := t >>
% A word with escapes in might be a pre-processor directive because I will
% allow "!#if" as well as "#if" to be used. That is going to require
% lex_basic_token() to accept #if (and other cases) directly.
    else if w = lex_symbol_code then <<
% Note that the conditional compilation keywords are not recognised within
% quoted expressions, so "'!#if" is safe here.
      if yylval eq '!#if and lexer_option(lexer_hashif) then <<
        read_s_expression();
        w := lex_conditional yylval >>
      else if (yylval eq '!#else or
               yylval eq '!#elif) and lexer_option(lexer_hashif) then <<
        if if_depth = 0 then yyerror "Unexpected #else of #elif"
        else if_depth := if_depth-1;
        yylval := nil;
        w := lex_skipping(w, nil) >>
      else if yylval eq '!#endif and lexer_option(lexer_hashif) then <<
        if if_depth = 0 then yyerror "Unexpected #endif"
        else if_depth := if_depth-1;
        w := lex_basic_token() >>
      else if yylval eq '!#eval and lexer_option(lexer_hashif) then << 
        read_s_expression();
        errorset(yylval, nil, nil);
        w := lex_basic_token() >>
      else if yylval eq '!#define and lexer_option(lexer_hashif) then <<
        read_s_expression();
        w := yylval;    % Ought to be a symbol, number of string
        done := read_s_expression();
        if idp w or numberp w or stringp w then
          put(w, '!#define, done);
        w := lex_basic_token();
        done := nil >>
      else if not lex_escaped then <<
        if (done := get(yylval, '!#define)) and
           lexer_option(lexer_hashif) then <<
          yylval := done;
          if numberp done then w := lex_number_code
          else if stringp done then w := lex_string_code;
          done := t >>
        else done := t >>
      else done := t >>
    else done := t >>;
    if !*tracelex then <<
      if posn() neq 0 then terpri();
      prin2 "yylex = "; prin1 yylval; prin2 " type "; print w >>;
    return w;
  end;



% If, when reading ordinary text, I come across the token #if I read
% the expression following. If that evaluates to TRUE I just keep on
% on reading. So the sequence "#if t" is in effect ignored. Then
% if later on I just ignore an "#endif" all will be well.  If on the other
% hand the expression evaluates to NIL (or if evaluation fails), I will
% call lex_skipping() to discard more tokens (up to and including
% the next "#else", "#elif t" or "#endif"). I keep a count of how many
% "#if t" equivalents I have passed so that I can match them with their
% corresponding "#endif" statements and moan if an "#else" or "#endif"
% occurs out of place.
%
% If I wanted to support this in C mode I would need to introduce the
% symbol "#ifdef" as well, and have a rather different scheme for
% decoding conditions. However at present I ONLY support #if in RLISP mode.

symbolic procedure lex_conditional x;
  begin
    scalar w;
    w := lex_basic_token();
    x := errorset(x, nil, nil);
    if errorp x or null car x then return lex_skipping(w, nil);
    if_depth := if_depth+1;
    return w
  end;

% I call lex_skipping when I find "#if nil" or "#else" or "#elif"
% that is processed. When a top-level "#else" or "#elif" is found it
% is discarded before calling lex_skipping, since it must follow a
% successful "#if" and hence introduce material to be thrown away.

symbolic procedure lex_skipping(w, x);
  begin
    scalar done;
% In this code x keep track of the depth of testing of "#if" constructions
    while not done do <<
      if w = lex_eof_code then done := t   % End of file
      else <<
        if w = '!:symbol then <<
          if yylval = '!#endif then <<
            if null x then done := t
            else x := cdr x >>
          else if yylval = '!#if then x := nil . x
          else if yylval = '!#else and null x then done := t
          else if yylval = '!#elif and null x then <<
            read_s_expression();
            done := errorset(yylval, nil, nil);
            if errorp done or null car done then done := nil >> >>;
      w := lex_basic_token() >> >>;
    return w
  end;


% lex_basic_token() will read the next token from the current input stream
% and leave a value in yylval to show what was found.
% It recognize the quote prefix, as in '(lisp expression) and
% `(backquoted thing).  The return value is a numeric code.
% It leaves a variable lex_escaped true if the "word" that was
% read had any "!" characers used to escape parts of it.

global '(lex_peeked lex_peeked_yylval lex_peeked_escaped);

% There are a range of different ways in which a comment might start!

symbolic procedure lex_start_line_comment ch;
  (ch = '!% and lexer_option(lexer_comment_percent)) or
  (ch = '!# and lexer_option(lexer_comment_hash));

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
% As implemented here this does not support nested block
% comments. At some stage I might deal with that, but the
% main language I know of that supports them is SML and the
% SML code that I have at hand at present happpens not to
% use any, so this does not feel urgent.
    while ((lex_char := yyreadch()) neq '!* or
           yypeekchar() neq term) and
          lex_char neq !$eof!$ do nil;
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
          lex_char = tab or
          (lex_start_line_comment lex_char and
           lex_skip_line_comment()) or
          (lex_start_block_comment lex_char and
           lex_skip_block_comment()) do yyreadch();
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
      if not lex_escaped and (w := get(yylval, 'lex_code)) then return w
      else if eqcar(r, '!') then return lex_typename_code
      else return lex_symbol_code >>
% Numbers are either integers or floats. A floating point number is
% indicated by either a point "." or an exponent marker "e". In the code
% here I keep a flag (in w) to indicate if I had a floating or integer
% value, but in the end I ignore this and hand back the lexical category
% for :number in both cases. At present I will not handle radix specifiers.
% I think I should probably upgrade this to support the notation 0xNNN for
% hex numbers, and perhaps 0NNN for octal (though does anybody use octal
% these days?).
    else if digit lex_char then <<
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
% Strings are enclosed in double-quotes, and "abc""def" is a string with
% a double-quote mark within it. Note no case folding on characters in a
% string.
    else if lex_char = '!" and lexer_option(lexer_string) then <<
      begin
        scalar !*raise, !*lower;      % Make !*raise & !*lower both nil.
        repeat <<
          while not (yyreadch() = '!") do r := lex_char . r;
          r := lex_char . r;
          yyreadch() >> until not (lex_char = '!");
      end;
      yylval := list2widestring reversip cdr r;
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
% "'" and "`"(backquote) introduce Lisp syntax S-expressions
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
      if yylval = '!# or get(yylval, 'lex_dipthong) then yyreadch()
      else lex_char := '! ;  % Try to avoid reading beyond where I HAVE to.
% There is a bit of horribly magic needed here. I want
%  #if #else #elif #endif #eval and #define
% to be accepted without needing an initial exclamation mark.
% The spelling "!#if" (etc) will already have been coped with,
% it is the case with no escape character I am concered
% about here, and that requires a 1-symbol look-ahead. Well even there
% the look ahead only has to consider a whole symbol if the character after
% the "#" is a letter (or an "!").
      if (yylval = '!# and lexer_option(lexer_hashif) and liter lex_char)
         or lex_char = '!! then <<
        r := lex_basic_token();
% Observe that I only check yylval here not the type of token returned.
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
