module latexsyms;

/**************************************************************************
 * Copyright (C) 2025,                                   E. Schruefer     *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

% This provides for the use of non-escaped latex symbols by the web-gui.
% It is only needed when the backslash is not treated as an id.

for each s in
  '(!\alpha       !\beta         !\gamma        !\delta
    !\epsilon     !\varepsilon   !\zeta         !\eta
    !\theta       !\vartheta     !\iota         !\kappa
    !\varkappa    !\lambda       !\mu           !\nu
    !\xi          !\omicron      !\pi           !\varpi
    !\rho         !\varrho       !\sigma        !\varsigma
    !\tau         !\phi          !\varphi       !\upsilon
    !\chi         !\psi          !\omega        !\digamma

    !\Alpha       !\Beta         !\Gamma        !\varGamma
    !\Delta       !\varDelta     !\Epsilon      !\Zeta
    !\Eta         !\Theta        !\varTheta     !\Iota
    !\Kappa       !\Lambda       !\varLambda    !\Mu
    !\Nu          !\Xi           !\varXi        !\Omicron
    !\Pi          !\varPi        !\Rho          !\Sigma
    !\varSigma    !\Tau          !\Phi          !\varPhi
    !\Upsilon     !\varUpsilon   !\Chi          !\Psi
    !\varPsi      !\Omega        !\varOmega)
%  do newtok {explode2 s, s};
 do newtok ({x, compress cdr x} where x = explode2 s);

for each s in
  '(!\aleph       !\beth         !\gimel        !\daleth)
  do newtok {explode2 s, s};


for each s in
  '(!\rd          !\rD     !\scriptCapitalE !\scriptCapitalH
    !\scriptCapitalL !\gothicCapitalC !\gothicCapitalH
    !\gothicCapitalI !\gothicCapitalR
    !\imaginaryI  !\imaginaryJ   !\exponentialE
    !\differentialD  !\capitalDifferentialD)
  do newtok {explode2 s, s};



for each s in
  '(!\pm          !\div          !\divides      !\sqrt
%\sqrt{}
%\sqrt[]{}
    !\surd        !\intercal     !\dotplus      !\doublebarwedge
    !\divideontimes !\times      !\cdot
    !\ast         !\star         !\ltimes       !\rtimes
    !\leftthreetimes !\rightthreetimes !\circ   !\bullet
    !\centerdot   !\boxminus     !\boxplus      !\boxtimes
    !\boxdot      !\ominus       !\oplus        !\otimes
    !\odot        !\circleddash  !\circledast   !\circledcirc
    !\oslash)
  do newtok {explode2 s, s};


for each s in
  '(!\emptyset !\varnothing)
  do newtok {explode2 s, s};

for each s in 
  '(!\N           !\R            !\Q            !\C
    !\Z)
  do newtok {explode2 s, s};

for each s in
  '(!\nsupseteqq  !\supsetneq   !\varsupsetneq  !\supsetneqq
    !\varsupsetneqq !\nsubseteqq !\subseteqq    !\Subset
    !\sqsubset    !\supseteqq   !\Supset        !\sqsupset
    !\sqsubseteq  !\sqsupseteq  !\in            !\notin
    !\ni          !\owns        !\backepsilon   !\subset
    !\supset      !\subseteq    !\supseteq      !\subsetneq
    !\varsubsetneq !\subsetneqq !\varsubsetneqq !\nsubset
    !\nsupset     !\nsubseteq   !\nsupseteq)
  do newtok {explode2 s, s};

for each s in
  '(!\cap         !\cup         !\setminus      !\smallsetminus
    !\complement)
  do newtok {explode2 s, s};

for each s in
  '(!\lparen      !\rparen      !\lbrace        !\rbrace
    !\langle      !\rangle      !\lfloor        !\rfloor
    !\lceil       !\rceil       !\vert          !\lvert
    !\rvert       !\|           !\Vert          !\mVert
    !\lVert       !\rVert       !\lbrack        !\rbrack
    !\ulcorner    !\urcorner
    !\llcorner    !\lrcorner    !\lgroup        !\rgroup
    !\lmoustache  !\rmoustache  !\mvert)
  do newtok {explode2 s, s};

for each s in
  '(!\bra         !\ket         !\braket        !\Bra
    !\Ket         !\Braket)
  do newtok {explode2 s, s};

for each s in
  '(!\sum         !\prod        !\coprod        !\int
    !\intop       !\iint        !\iiint         !\oint
    !\smallint    !\bigcup      !\bigcap        !\bigvee
    !\bigwedge    !\biguplus    !\bigotimes     !\bigoplus
    !\bigodot     !\bigsqcup    !\oiint         !\oiiint
    !\intclockwise !\varointclockwise !\ointctrclockwise
    !\intctrclockwise !\Cap     !\Cup           !\doublecap
    !\doublecup   !\sqcup       !\sqcap         !\uplus
    !\wr          !\amalg)
  do newtok {explode2 s, s};

for each s in
  '(!\cdotp       !\ldotp       !\vdots         !\cdots
    !\ddots       !\ldots       !\mathellipsis)
  do newtok {explode2 s, s};

for each s in
  '(!\square      !\Box         !\blacksquare   !\bigcirc
    !\circledS    !\circledR    !\diamond       !\Diamond
    !\lozenge     !\blacklozenge !\triangleleft !\triangleright
    !\triangle    !\triangledown !\blacktriangleleft
    !\blacktriangleright !\blacktriangle !\blacktriangledown
    !\vartriangle !\vartriangleleft !\vartriangleright
    !\triangleq   !\trianglelefteq  !\trianglerighteq
    !\ntriangleleft !\ntriangleright !\ntrianglelefteq
    !\ntrianglerighteq !\bigtriangleup !\bigtriangledown
    !\dagger      !\dag         !\ddag          !\ddagger
    !\maltese)
  do newtok {explode2 s, s};


for each s in
  '(!\top         !\bot         !\nabla         !\partial
    !\ell         !\hbar        !\pounds        !\euro
    !\And         !\differencedelta !\wp        !\hslash
    !\Finv        !\Game        !\eth             !\mho
    !\Bbbk        !\yen         !\imath         !\jmath
    !\Re          !\Im)
  do newtok {explode2 s, s};


for each s in
  '(!\mapsfrom    !\Mapsfrom    !\MapsTo         !\Yup
    !\lightning   !\leftarrowtriangle !\rightarrowtriangle
    !\leftrightarrowtriangle    !\boxdot
    !\bigtriangleup !\bigtriangledown            !\boxbar
    !\Lbag        !\Rbag        !\llbracket      !\rrbracket
    !\longmapsfrom !\Longmapsfrom   !\Longmapsto
    !\boxslash    !\boxbslash   !\boxast         !\boxcircle
    !\boxbox      !\fatsemi     !\leftslice      !\rightslice
    !\interleave  !\biginterleave !\sslash       !\talloblong)
  do newtok {explode2 s, s};


for each f in
  '(!\exp    !\ln      !\log     !\lg      !\lb
    !\ker    !\det     !\arg     !\dim     !\gcd
    !\argmin !\argmax  !\plim)
 do newtok ({x, compress cdr x} where x = explode2 f);

for each f in
  '(!\degree !\circ    !\ang     !\arccos  !\arcsin
    !\arctan !\cos     !\cosh    !\cot     !\coth
    !\csc    !\sec     !\sin     !\sinh    !\tan
    !\tanh   !\arctg   !\arcctg  !\ch      !\ctg
    !\cth    !\cotg    !\cosec   !\sh      !\tg
    !\th)
 do newtok ({x, compress cdr x} where x = explode2 f);


for each f in
  '(!\max    !\min     !\sup     !\inf     !\lim
    !\liminf !\limsup  !\injlim  !\varlimsup !\varliminf
    !\varinjlim)
 do newtok ({x, compress cdr x} where x = explode2 f);

for each f in
  '(!\Pr     !\hom     !\varprojlim !\projlim)
% do newtok ({x, compress cdr x} where x = explode2 f);
  do newtok {explode2 f, f};

for each f in
  '(!\pmod   !\mod     !\bmod)
  do newtok {explode2 f, f};

for each c in 
  '(!\overset !\underset !\overunderset
    !\stackrel !\stackbin        !\rlap    !\llap
    !\mathllap !\mathrlap)
  do newtok {explode2 c, c};

for each c in
  '(!\dot    !\ddot    !\dddot   !\ddddot  !\mathring
    !\tilde  !\bar     !\breve   !\check   !\hat
    !\vec)
  do newtok {explode2 c, c};

endmodule;

end;


