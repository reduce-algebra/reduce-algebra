(* Prologue for the SML-TeX stuff *)

(* The idea here is that I will have a file Library_reduce.sml and
   another one Library_sml.sml that provide environment spectific
   support. For instance the first thing here is the setting of
   infix declarations for all the standard operators, since it is
   easier to do that here within SML code than to hand-wire it into
   the parser itself.
 *)

(* In the declarations here I am assuming that "=" and "*" have been
   hard-wired into the parser. That is because they are used for purposes
   other than as operators/constructors. The way I implement things is that
   if a name, say "+" is declared as an infix as it is here, then the
   lexer will turn a "+" sign in the input into a token with type :infix6
   and with the further details (ie the value in yylval) showing it as
   a "+". Then the grammar just has to cope with precedence info on the
   abstract token types :infix0 to :infix9 (and the right-associating
   variants. But this means that the parser can not distinguish one operator
   with precedence n from another as far as raw syntax is concerned. But
   the tokens "*" and "=" have to be recognized elsewhere in the grammar.
   It I needed to support variable precedence for those I could arrange that
   the lexer mapped * onto (say) one of :infix0* through :infix9* and then
   in the syntax rule for types (as in ('a * 'b)) I could accept any one
   of those 9 tokens, knowing that what I really had was still an asterisk.
   I view that as too messy and specialised to worry about just now.
 *)


(* infix 7 *;   Must be FIXED because also used in type descriptions *)
infix 7 /;
infix 7 %;
infix 7 div;
infix 7 mod;
infix 6 +;
infix 6 -;
infixr 5 ::;
(* infix 4 =;  Must be FIXED because also used after VAL and FUN (etc) *)
infix 4 <;
infix 4 >;
infix 4 <=;
infix 4 >=;
infix 4 <>;
infix 3 :=;

(* end of Library_reduce.sml *)
