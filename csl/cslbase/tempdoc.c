/* tempdoc.c                             Copyright (C) 2011 Codemist Ltd */



/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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

/* Signature: 712f356a 28-Feb-2010 */


/*
 * This file is where I have dumped existing fragments of description,
 * but as you can imagine this is merely a temporary location - the comments
 * here need fleshing out and distributing to sit next to the things
 * they refer to. I do not know if this strategy will lead me to getting
 * full documentation but at least it might prod me into making SOME progress!
 * If somebody would like to volunteer even just to move comments to the
 * correct place that would be nice!
 */

/*!!! csl
 */

/*! predef [!fleps1] !!fleps1
 * There is a function safe!-fp!-plus that performs floating point
 * arithmetic but guarantees never to raise an exception. This value was
 * at one stage related to when small values created there got truncated to zero,
 * but the current code does not use the Lisp variable at all and instead does
 * things based on the bitwise representation of the numbers.
 */

/*! predef [$eof$] !\$eof!\$
 * The value of this variable is a special ``character'' used to denote an
 * end-of-file condition.
 *
 */

/*! predef [$eol$] !\$eol!\$
 * The value of this variable is an end-of-line character.
 */

/*! predef [*applyhook] !*applyhook!*
 * If this is set it might be supposed to be the name of a function used
 * by the interpreter as a callbackm but at presnet it does not actually do
 * anything!
 */

/*! predef [*break-loop*] !*break!-loop!*
 * If the value of this is a symbol that is defined as a function of one
 * argument then it is called during the processing on an error. This has not
 * been used in anger and so its whole status may be dubious!
 */

/*! predef [*carcheckflag] !*carcheckflag
 * In general CSL arranges that every {\ttfamily car} or {\ttfamily cdr} access
 * is checked for validity. Once upon a time setting this variable to nil
 * turned such checks off in the hope of gaining a little speed. But it no
 * longer does that. It may have a minor effect on array access primitives.
 */

/*! predef [*comp] !*comp
 * When set each function is compiled (into bytecodes) as it gets defined.
 */

/*! predef [*debug-io] !*debug!-io!*
 * An I/O channel intended to be used for diagnostic interactions.
 */

/*! predef [*echo] !*echo
 * When this is non-nil characters that are read from an input file are
 * echoed to the standard output. This gives a more comlete transcript in
 * a log file, but can sometimes amount to over-verbose output.
 */

/*! predef [*error-message*] !*error!-messages!*
 * Has the value nil and does not do anything!
 */

/*! predef [*error-output*] !*error!-output!*
 * An I/O channel intended for diagnostic output.
 */

/*! predef [*evalhook] !*evalhook!*
 * See {\ttfamily !*applyhool!*}. This also does not do anything at present.
 */

/*! predef [*gchook*] !*gc!-hook!*
 * If this is set to have as its value that is a function of one argument then
 * that function is called with {\ttfamily nil} on every minor entry to the
 * garbage collection, and with argument {\ttfamily t} at the end of a ``genuine''
 * full garbage collection.
 */

/*! predef [*hanaku] !*hankaku
 * This was concerned with internationalisation to support a Japanese
 * locale but has not been activated for some while.
 */

/*! predef [*loop-print*] !*loop!-print!*
 * Probably not used at present.
 */

/*! predef [*lower] !*lower
 * Not yet written
 */

/*! predef [*macroexpand-hook*] !*macroexpand!-hook!*
 * Not yet written
 */

/*! predef [*math-output*] !*math!-output!*
 * Not yet written
 */

/*! predef [*native_code] !*native\_code
 * Not yet written
 */

/*! predef [*notailcall] !*notailcall
 * Not yet written
 */

/*! predef [*package*] !*package!*
 * Not yet written
 */

/*! predef [*pgwd] !*pgwd
 * Not yet written
 */

/*! predef [*[lap] !*plap
 * Not yet written
 */

/*! predef [*pretty-symamtic] !*pretty!-symmetric
 * Not yet written
 */

/*! predef [*prinl-fn!*] !*prinl!-fn!*
 * Not yet written
 */

/*! predef [*prinl-index] !*prinl!-index!*
 * Not yet written
 */

/*! predef [*prinl-visited-nodes*] !*prinl!-visited!-nodes!*
 * Not yet written
 */

/*! predef [*print-array*] !*print!-array!*
 * Not yet written
 */

/*! predef [*print-length*] !*print!-length!*
 * Not yet written
 */

/*! predef [*print-level*] !*print!-level!*
 * Not yet written
 */

/*! predef [*pwrds] !*pwrds
 * Not yet written
 */

/*! predef [*query-io*] !*query!-io!*
 * Not yet written
 */

/*! predef [*quotes] !*quotes
 * Not yet written
 */

/*! predef [*raise] !*raise
 * Not yet written
 */

/*! predef [*redefmsg] !*redefmsg
 * Not yet written
 */

/*! predef [*resources*] !*resources!*
 * Not yet written
 */

/*! predef [*savedef] !*savedef
 * Not yet written
 */

/*! predef [*spool-output*] !*spool!-output!*
 * Not yet written
 */

/*! predef [*standard-input*] !*standard!-input!*
 * Not yet written
 */

/*! predef [*standard-output*] !*standard!-output!*
 * Not yet written
 */

/*! predef [*terminal-io*] !*terminal!-io!*
 * Not yet written
 */

/*! predef [*trace-output*] !*trace!-output!*
 * Not yet written
 */

/*! predef [@cslbase] !@cslbase
 * Not yet written
 */

/*! predef bn
 * Not yet written
 */

/*! predef bufferi
 * Not yet written
 */

/*! predef buffero
 * Not yet written
 */

/*! predef [common-lisp-mode] common!-lisp!-mode
 * Not yet written
 */

/*! predef [crbuf*] crbuf!*
 * Not yet written
 */

/*! predef [emsg*] emsg!*
 * Not yet written
 */

/*! predef [eof*] eof!*
 * Not yet written
 */

/*! predef indblanks
 * Not yet written
 */

/*! predef indentlevel
 * Not yet written
 */

/*! predef initialblanks
 * Not yet written
 */

/*! predef [lispsystem*] lispsystem!*
 * Not yet written
 */

/*! predef lmar
 * Not yet written
 */

/*! predef [load-source] load!-source
 * Not yet written
 */

/*! predef nil
 * Not yet written
 */

/*! predef [ofl*] ofl!*
 * Not yet written
 */

/*! predef pendingrpars
 * Not yet written
 */

/*! predef [program*] program!*
 * Not yet written
 */

/*! predef rmar
 * Not yet written
 */

/*! predef rparcount
 * Not yet written
 */

/*! predef [s:gensym-serial] s!:gensym!-serial
 * Not yet written
 */

/*! predef stack
 * Not yet written
 */

/*! predef t
 * Not yet written
 */

/*! predef [thin*] thin!*
 * Not yet written
 */

/*! predef [ttype*] ttype!*
 * Not yet written

/*!! flags [04] Flags and Properties
 *
 * Most of tags here are probably not much use to end-users, but I am noting them
 * as a matter of completeness.
 *
 */

/*! flags [s:ppchar] s!:ppchar and s!:ppformat
 * These are used in the prettyprint code found in {\ttfamily extras.red}. A
 * name is given a property {\ttfamily s!:ppformat} if in prettyprinted display
 * its first few arguments should appear on the same line as it if at all
 * possible. The {\ttfamily s!:ppchar} property is used to make the display of
 * bracket characters a little more tide in the source code.
 */

/*! flags switch
 * In the Reduce parser some names are ``switches'', and then directives such
 * as {\ttfamily on xxx} and {\ttfamily off xx} have the effect of setting or
 * clearing the value of a variable {\ttfamily !*xxx}. This is managed by
 * setting the {\ttfamily switch} flag om {\ttfamily xxx}. CSL sets some
 * things as switches ready for when they may be used by the Reduce parser.
 */

/*! flags lose
 * If a name is flagged as {ttfamily lose} then a subsequent attempt to
 * define or redefine it will be ignored.
 */

/*! flags [~magic-internal-symbol~] !$\sim$magic!-internal!-symbol!$\sim$
 * CSL does not have a clear representation for functions that is separated from
 * the representation of an identifier, and so when you ask to get the value
 * of a raw function you get an identifier (probably a gensym) and this
 * tag is used to link such values with the symbols they were originally
 * extracted from.
 */

/*!! fns [05] Functions and Special Forms
 *
 * Each line here shows a name and then one of the words {\ttfamily expr},
 * {\ttfamily fexpr} or {\ttfamily macro}. In some cases there can also be special
 * treatment of functions by the compiler so that they get compiled in-line.
 *
 */

/*! fns abs expr
 * Not yet written
 */

/*! fns acons expr
 * Not yet written
 */

/*! fns acos expr
 * Not yet written
 */

/*! fns acosd expr
 * Not yet written
 */

/*! fns acosh expr
 * Not yet written
 */

/*! fns acot expr
 * Not yet written
 */

/*! fns acotd expr
 * Not yet written
 */

/*! fns acoth expr
 * Not yet written
 */

/*! fns acsc expr
 * Not yet written
 */

/*! fns acscd expr
 * Not yet written
 */

/*! fns acsch expr
 * Not yet written
 */

/*! fns add1 expr
 * Not yet written
 */

/*! fns and fexpr
 * Not yet written
 */

/*! fns append expr
 * Not yet written
 */

/*! fns apply expr
 * Not yet written
 */

/*! fns apply0 expr
 * Not yet written
 */

/*! fns apply1 expr
 * Not yet written
 */

/*! fns apply2 expr
 * Not yet written
 */

/*! fns apply3 expr
 * Not yet written
 */

/*! fns asec expr
 * Not yet written
 */

/*! fns asecd expr
 * Not yet written
 */

/*! fns asech expr
 * Not yet written
 */

/*! fns ash expr
 * Not yet written
 */

/*! fns ash1 expr
 * Not yet written
 */

/*! fns asin expr
 * Not yet written
 */

/*! fns asind expr
 * Not yet written
 */

/*! fns asinh expr
 * Not yet written
 */

/*! fns assoc expr
 * Not yet written
 */

/*! fns assoc!*!* expr
 * Not yet written
 */

/*! fns atan expr
 * Not yet written
 */

/*! fns atan2 expr
 * Not yet written
 */

/*! fns atan2d expr
 * Not yet written
 */

/*! fns atand expr
 * Not yet written
 */

/*! fns atanh expr
 * Not yet written
 */

/*! fns atom expr
 * Not yet written
 */

/*! fns atsoc expr
 * Not yet written
 */

/*! fns batchp expr
 * Not yet written
 */

/*! fns [binary_close_input] binary\_close\_input expr
 * Not yet written
 */

/*! fns [binary_close_output] binary\_close\_output expr
 * Not yet written
 */

/*! fns [binary_open_input] binary\_open\_input expr
 * Not yet written
 */

/*! fns [binary_open_output] binary\_open\_output expr
 * Not yet written
 */

/*! fns [binary_prin1] binary\_prin1 expr
 * Not yet written
 */

/*! fns [binary_prin2] binary\_prin2 expr
 * Not yet written
 */

/*! fns [binary_prin3] binary\_prin3 expr
 * Not yet written
 */

/*! fns [binary_prinbyte] binary\_prinbyte expr
 * Not yet written
 */

/*! fns [binary_princ] binary\_princ expr
 * Not yet written
 */

/*! fns [binary_prinfloat] binary\_prinfloat expr
 * Not yet written
 */

/*! fns [binary_read2] binary\_read2 expr
 * Not yet written
 */

/*! fns [binary_read3] binary\_read3 expr
 * Not yet written
 */

/*! fns [binary_read4] binary\_read4 expr
 * Not yet written
 */

/*! fns [binary_readbyte] binary\_readbyte expr
 * Not yet written
 */

/*! fns [binary_readfloat] binary\_readfloat expr
 * Not yet written
 */

/*! fns [binary_select_input] binary\_select\_input expr
 * Not yet written
 */

/*! fns [binary_terpri] binary\_terpri expr
 * Not yet written
 */

/*! fns binopen expr
 * Not yet written
 */

/*! fns boundp expr
 * Not yet written
 */

/*! fns [bps-getv] bps!-getv expr
 * Not yet written
 */

/*! fns [bps-putv] bps!-putv expr
 * Not yet written
 */

/*! fns [bps-upvb] bps!-upbv expr
 * Not yet written
 */

/*! fns bpsp expr
 * Not yet written
 */

/*! fns [break-loop] break!-loop expr
 * Not yet written
 */

/*! fns byte!-getv expr
 * Not yet written
 */

/*! fns bytecounts expr
 * Not yet written
 */

/*! fns [c_out] c\_out expr
 * Not yet written
 */

/*! fns carcheck expr
 * Not yet written
 */

/*! fns catch fexpr
 * Not yet written
 */

/*! fns cbrt expr
 * Not yet written
 */

/*! fns ceiling expr
 * Not yet written
 */

/*! fns [char-code] char!-code expr
 * Not yet written
 */

/*! fns [char-downcase] char!-downcase expr
 * Not yet written
 */

/*! fns [char-upcase] char!-upcase expr
 * Not yet written
 */

/*! fns chdir expr
 * Not yet written
 */

/*! fns [check-c-code] check!-c!-code expr
 * Not yet written
 */

/*! fns checkpoint expr
 * Not yet written
 */

/*! fns [cl-equal] cl!-equal expr
 * Not yet written
 */

/*! fns close expr
 * Not yet written
 */

/*! fns [close-library] close!-library expr
 * Not yet written
 */

/*! fns clrhash expr
 * Not yet written
 */

/*! fns [code-char] code!-char expr
 * Not yet written
 */

/*! fns codep expr
 * Not yet written
 */

/*! fns compile expr
 * Not yet written
 */

/*! fns [compile-all] compile!-all expr
 * Not yet written
 */

/*! fns compress expr
 * Not yet written
 */

/*! fns cond fexpr
 * Not yet written
 */

/*! fns cons expr
 * Not yet written
 */

/*! fns consp expr
 * Not yet written
 */

/*! fns constantp expr
 * Not yet written
 */

/*! fns contained expr
 * Not yet written
 */

/*! fns [convert-to-evector] convert!-to!-evector expr
 * Not yet written
 */

/*! fns copy expr
 * Not yet written
 */

/*! fns [copy-module] copy!-module expr
 * Not yet written
 */

/*! fns [copy-native] copy!-native expr
 * Not yet written
 */

/*! fns cos expr
 * Not yet written
 */

/*! fns cosd expr
 * Not yet written
 */

/*! fns cosh expr
 * Not yet written
 */

/*! fns cot expr
 * Not yet written
 */

/*! fns cotd expr
 * Not yet written
 */

/*! fns coth expr
 * Not yet written
 */

/*! fns [create-directory] create!-directory expr
 * Not yet written
 */

/*! fns csc expr
 * Not yet written
 */

/*! fns cscd expr
 * Not yet written
 */

/*! fns csch expr
 * Not yet written
 */

/*! fns date expr
 * Not yet written
 */

/*! fns [dated-name] dated!-name expr
 * Not yet written
 */

/*! fns datelessp expr
 * Not yet written
 */

/*! fns datestamp expr
 * Not yet written
 */

/*! fns de fexpr
 * Not yet written
 */

/*! fns [define-in-module] define!-in!-module expr
 * Not yet written
 */

/*! fns deflist expr
 * Not yet written
 */

/*! fns deleq expr
 * Not yet written
 */

/*! fns delete expr
 * Not yet written
 */

/*! fns [delete-file] delete!-file expr
 * Not yet written
 */

/*! fns [delete-module] delete!-module expr
 * Not yet written
 */

/*! fns difference expr
 * Not yet written
 */

/*! fns digit expr
 * Not yet written
 */

/*! fns directoryp expr
 * Not yet written
 */

/*! fns divide expr
 * Not yet written
 */

/*! fns dm fexpr
 * Not yet written
 */

/*! fns do macro
 * Not yet written
 */

/*! fns [do*] do!* macro
 * Not yet written
 */

/*! fns dolist macro
 * Not yet written
 */


/*! fns dotimes macro
 * Not yet written
 */

/*! fns [double-execute] double!-execute expr
 * Not yet written
 */

/*! fns egetv expr
 * Not yet written
 */

/*! fns eject expr
 * Not yet written
 */

/*! fns [enable-backtrace] enable!-backtrace expr
 * Not yet written
 */

/*! fns [enable-errorset] enable!-errorset expr
 * Not yet written
 */

/*! fns encapsulatedp expr
 * Not yet written
 */

/*! fns endp expr
 * Not yet written
 */

/*! fns eputv expr
 * Not yet written
 */

/*! fns eq expr
 * Not yet written
 */

/*! fns [eq-safe] eq!-safe expr
 * Not yet written
 */

/*! fns eqcar expr
 * Not yet written
 */

/*! fns eql expr
 * Not yet written
 */

/*! fns eqlhash expr
 * Not yet written
 */

/*! fns eqn expr
 * Not yet written
 */

/*! fns equal expr
 * Not yet written
 */

/*! fns equalcar expr
 * Not yet written
 */

/*! fns equalp expr
 * Not yet written
 */

/*! fns error expr
 * Not yet written
 */

/*! fns error1 expr
 * Not yet written
 */

/*! fns errorset expr
 * Not yet written
 */

/*! fns eupbv expr
 * Not yet written
 */

/*! fns eval expr
 * Not yet written
 */

/*! fns [eval-when] eval!-when fexpr
 * Not yet written
 */

/*! fns evectorp expr
 * Not yet written
 */

/*! fns evenp expr
 * Not yet written
 */

/*! fns evlis expr
 * Not yet written
 */

/*! fns exp expr
 * Not yet written
 */

/*! fns expand expr
 * Not yet written
 */

/*! fns explode expr
 * Not yet written
 */

/*! fns explode2 expr
 * Not yet written
 */

/*! fns explode2lc expr
 * Not yet written
 */

/*! fns explode2lcn expr
 * Not yet written
 */

/*! fns explode2n expr
 * Not yet written
 */

/*! fns explode2uc expr
 * Not yet written
 */

/*! fns explode2ucn expr
 * Not yet written
 */

/*! fns explodebinary expr
 * Not yet written
 */

/*! fns explodec expr
 * Not yet written
 */

/*! fns explodecn expr
 * Not yet written
 */

/*! fns explodehex expr
 * Not yet written
 */

/*! fns exploden expr
 * Not yet written
 */

/*! fns explodeoctal expr
 * Not yet written
 */

/*! fns expt expr
 * Not yet written
 */

/*! fns faslout expr
 * Not yet written
 */

/*! fns fetch!-url expr
 * Not yet written
 */

/*! fns fgetv32 expr
 * Not yet written
 */

/*! fns fgetv64 expr
 * Not yet written
 */

/*! fns [file-length] file!-length expr
 * Not yet written
 */

/*! fns [file-readablep] file!-readablep expr
 * Not yet written
 */

/*! fns [file-writablep] file!-writeablep expr
 * Not yet written
 */

/*! fns filedate expr
 * Not yet written
 */

/*! fns filep expr
 * Not yet written
 */

/*! fns fix expr
 * Not yet written
 */

/*! fns fixp expr
 * Not yet written
 */

/*! fns flag expr
 * Not yet written
 */

/*! fns flagp expr
 * Not yet written
 */

/*! fns [flagp**] flagp!*!* expr
 * Not yet written
 */

/*! fns flagpcar expr
 * Not yet written
 */

/*! fns float expr
 * Not yet written
 */

/*! fns floatp expr
 * Not yet written
 */

/*! fns floor expr
 * Not yet written
 */

/*! fns fluid expr
 * Not yet written
 */

/*! fns fluidp expr
 * Not yet written
 */

/*! fns flush expr
 * Not yet written
 */

/*! fns format macro
 * Not yet written
 */


/*! fns [fp-evaluate] fp!-evaluate expr
 * Not yet written
 */

/*! fns fputv32 expr
 * Not yet written
 */

/*! fns fputv64 expr
 * Not yet written
 */

/*! fns frexp expr
 * Not yet written
 */

/*! fns funcall expr
 * Not yet written
 */

/*! fns [funcall*] funcall!* expr
 * Not yet written
 */

/*! fns function fexpr
 * Not yet written
 */

/*! fns gcdn expr
 * Not yet written
 */

/*! fns gctime expr
 * Not yet written
 */

/*! fns gensym expr
 * Not yet written
 */

/*! fns gensym1 expr
 * Not yet written
 */

/*! fns gensym2 expr
 * Not yet written
 */

/*! fns gensymp expr
 * Not yet written
 */

/*! fns geq expr
 * Not yet written
 */

/*! fns get expr
 * Not yet written
 */

/*! fns [get*] get!* expr
 * Not yet written
 */

/*! fns [get-current-directory] get!-current!-directory expr
 * Not yet written
 */

/*! fns [get-lisp-directory] get!-lisp!-directory expr
 * Not yet written
 */

/*! fns getd expr
 * Not yet written
 */

/*! fns getenv expr
 * Not yet written
 */

/*! fns gethash expr
 * Not yet written
 */

/*! fns getv expr
 * Not yet written
 */

/*! fns getv16 expr
 * Not yet written
 */

/*! fns getv32 expr
 * Not yet written
 */

/*! fns getv8 expr
 * Not yet written
 */

/*! fns global expr
 * Not yet written
 */

/*! fns globalp expr
 * Not yet written
 */

/*! fns go fexpr
 * Not yet written
 */

/*! fns greaterp expr
 * Not yet written
 */

/*! fns [hash-table-p] hash!-table!-p expr
 * Not yet written
 */

/*! fns hashcontents expr
 * Not yet written
 */

/*! fns [hashtagged-name] hashtagged!-name expr
 * Not yet written
 */

/*! fns hypot expr
 * Not yet written
 */

/*! fns iadd1 expr
 * Not yet written
 */

/*! fns idapply expr
 * Not yet written
 */

/*! fns idifference expr
 * Not yet written
 */

/*! fns idp expr
 * Not yet written
 */

/*! fns iequal expr
 * Not yet written
 */

/*! fns if fexpr
 * Not yet written
 */

/*! fns igeq expr
 * Not yet written
 */

/*! fns igreaterp expr
 * Not yet written
 */

/*! fns ileq expr
 * Not yet written
 */

/*! fns ilessp expr
 * Not yet written
 */

/*! fns ilogand expr
 * Not yet written
 */

/*! fns ilogor expr
 * Not yet written
 */

/*! fns ilogxor expr
 * Not yet written
 */

/*! fns imax expr
 * Not yet written
 */

/*! fns imin expr
 * Not yet written
 */

/*! fns iminus expr
 * Not yet written
 */

/*! fns iminusp expr
 * Not yet written
 */

/*! fns indirect expr
 * Not yet written
 */

/*! fns inorm expr
 * Not yet written
 */

/*! fns [input-libraries] input!-libraries fexpr
 * Not yet written
 */

/*! fns [instate-c-code] instate!-c!-code expr
 * Not yet written
 */

/*! fns integerp expr
 * Not yet written
 */

/*! fns intern expr
 * Not yet written
 */

/*! fns [interbal-open] internal!-open expr
 * Not yet written
 */

/*! fns intersection expr
 * Not yet written
 */

/*! fns ionep expr
 * Not yet written
 */

/*! fns iplus expr
 * Not yet written
 */

/*! fns iplus2 expr
 * Not yet written
 */

/*! fns iquotient expr
 * Not yet written
 */

/*! fns iremainder expr
 * Not yet written
 */

/*! fns irightshift expr
 * Not yet written
 */

/*! fns [is-console] is!-console expr
 * Not yet written
 */

/*! fns isub1 expr
 * Not yet written
 */

/*! fns itimes expr
 * Not yet written
 */

/*! fns itimes2 expr
 * Not yet written
 */

/*! fns izerop expr
 * Not yet written
 */

/*! fns last expr
 * Not yet written
 */

/*! fns lastcar expr
 * Not yet written
 */

/*! fns lastpair expr
 * Not yet written
 */

/*! fns lcmn expr
 * Not yet written
 */

/*! fns length expr
 * Not yet written
 */

/*! fns lengthc expr
 * Not yet written
 */

/*! fns leq expr
 * Not yet written
 */

/*! fns lessp expr
 * Not yet written
 */

/*! fns [let*] let!* fexpr
 * Not yet written
 */

/*! fns [library-members] library!-members expr
 * Returns a list of all the modules that could potentially be loaded using
 * {\ttfamily load!-module}. See {\ttfamily list!-modules} to get a human
 * readable display that looks more like the result of listing a directory, or
 * {\ttfamily modulep} for checking the state of a particular named module.
 *
 */

/*! fns [library-name] library!-name expr
 * Not yet written
 */

/*! fns linelength expr
 * Not yet written
 */

/*! fns list fexpr
 * Not yet written
 */

/*! fns [list*] list!* fexpr
 * Not yet written
 */

/*! fns [list-directory] list!-directory expr
 * Not yet written
 *
 */

/*! fns [list-modules] list!-modules expr
 * This prints a human-readable display of the modules present in the current
 * image files. This will include ``InitialImage'' which is the heap-image
 * loaded at system startup. For example
 * \begin{verbatim}
 * > (list!-modules)
 *
 * File d:\csl\csl.img (dirsize 8  length 155016, Writable):
 *   compat       Sat Jul 26 10:20:08 2008  position 556   size: 9320
 *   compiler     Sat Jul 26 10:20:08 2008  position 9880  size: 81088
 *   InitialImage Sat Jul 26 10:20:09 2008  position 90972 size: 64040
 *
 * nil
 * \end{verbatim}
 *
 * See {\ttfamily library!-members} and {\ttfamily modulep} for functions that
 * make it possible for Lisp code to discover about the loadable modules that are
 * available.
 */

/*! fns [list-to-string] list!-to!-string expr
 * Not yet written
 */

/*! fns [list-to-symbol] list!-to!-symbol expr
 * Not yet written
 */

/*! fns [list-to-vector] list!-to!-vector expr
 * Not yet written
 */

/*! fns list2 expr
 * Not yet written
 */

/*! fns [list2*] list2!* expr
 * Not yet written
 */

/*! fns list3 expr
 * Not yet written
 */

/*! fns [list3*] list3!* expr
 * Not yet written
 */

/*! fns list4 expr
 * Not yet written
 */

/*! fns liter expr
 * Not yet written
 */

/*! fns ln expr
 * Not yet written
 */

/*! fns [load-module] load!-module expr
 * Not yet written
 */

/*! fns [load-source] load!-source expr
 * Not yet written
 */

/*! fns log expr
 * Not yet written
 */

/*! fns log10 expr
 * Not yet written
 */

/*! fns logand expr
 * Not yet written
 */

/*! fns logb expr
 * Not yet written
 */

/*! fns logeqv expr
 * Not yet written
 */

/*! fns lognot expr
 * Not yet written
 */

/*! fns logor expr
 * Not yet written
 */

/*! fns logxor expr
 * Not yet written
 */

/*! fns [lose-precision] lose!-precision expr
 * Not yet written
 */

/*! fns lposn expr
 * Not yet written
 */

/*! fns lsd expr
 * Not yet written
 */

/*! fns [macro-function] macro!-function expr
 * Not yet written
 */

/*! fns macroexpand expr
 * Not yet written
 */

/*! fns [macroexpand-1] macroexpand!-1 expr
 * Not yet written
 */

/*! fns [make-bps] make!-bps expr
 * Not yet written
 */

/*! fns [make-function-stream] make!-function!-stream expr
 * Not yet written
 */

/*! fns [make-global] make!-global expr
 * Not yet written
 */

/*! fns [make-native] make!-native expr
 * Not yet written
 */

/*! fns [make-random-state] make!-random!-state expr
 * Not yet written
 */

/*! fns [make-simple-string] make!-simple!-string expr
 * Not yet written
 */

/*! fns [make-special] make!-special expr
 * Not yet written
 */

/*! fns map expr
 * Not yet written
 */

/*! fns mapc expr
 * Not yet written
 */

/*! fns mapcan expr
 * Not yet written
 */

/*! fns mapcar expr
 * Not yet written
 */

/*! fns mapcon expr
 * Not yet written
 */

/*! fns maphash expr
 * Not yet written
 */

/*! fns maple\_atomic\_value expr
 * Not yet written
 */

/*! fns maple\_component expr
 * Not yet written
 */

/*! fns maple\_integer expr
 * Not yet written
 */

/*! fns maple\_length expr
 * Not yet written
 */

/*! fns maple\_string\_data expr
 * Not yet written
 */

/*! fns maple\_tag expr
 * Not yet written
 */

/*! fns maplist expr
 * Not yet written
 */

/*! fns mapstore expr
 * Not yet written
 */

/*! fns [math-display] math!-display expr
 * Not yet written
 */

/*! fns max expr
 * Not yet written
 */

/*! fns max2 expr
 * Not yet written
 */

/*! fns md5 expr
 * Not yet written
 */

/*! fns md60 expr
 * Not yet written
 */

/*! fns member expr
 * Not yet written
 */

/*! fns [member**] member!*!* expr
 * Not yet written
 */

/*! fns memq expr
 * Not yet written
 */

/*! fns min expr
 * Not yet written
 */

/*! fns min2 expr
 * Not yet written
 */

/*! fns minus expr
 * Not yet written
 */

/*! fns minusp expr
 * Not yet written
 */

/*! fns mkevect expr
 * Not yet written
 */

/*! fns mkfvect32 expr
 * Not yet written
 */

/*! fns mkfvect64 expr
 * Not yet written
 */

/*! fns mkhash expr
 * Not yet written
 */

/*! fns mkquote expr
 * Not yet written
 */

/*! fns mkvect expr
 * Not yet written
 */

/*! fns mkvect16 expr
 * Not yet written
 */

/*! fns mkvect32 expr
 * Not yet written
 */

/*! fns mkvect8 expr
 * Not yet written
 */

/*! fns mkxvect expr
 * Not yet written
 */

/*! fns mod expr
 * Not yet written
 */

/*! fns modular!-difference expr
 * Not yet written
 */

/*! fns modular!-expt expr
 * Not yet written
 */

/*! fns modular!-minus expr
 * Not yet written
 */

/*! fns modular!-number expr
 * Not yet written
 */

/*! fns modular!-plus expr
 * Not yet written
 */

/*! fns modular!-quotient expr
 * Not yet written
 */

/*! fns modular!-reciprocal expr
 * Not yet written
 */

/*! fns modular!-times expr
 * Not yet written
 */

/*! fns modulep expr
 * This takes a single argument and checks whether there is a loadable module
 * of that name. If there is not then {\ttfamily nil} is returned, otherwise a
 * string that indicates the date-stamp on the module is given. See
 * {\ttfamily datelessp} for working with such dates, and {\ttfamily
 * library!-members} for finding a list of all modules that are available.
 *
 */

/*! fns mpi\_allgather expr
 * Not yet written
 */

/*! fns mpi\_alltoall expr
 * Not yet written
 */

/*! fns mpi\_barrier expr
 * Not yet written
 */

/*! fns mpi\_bcast expr
 * Not yet written
 */

/*! fns mpi\_comm\_rank expr
 * Not yet written
 */

/*! fns mpi\_comm\_size expr
 * Not yet written
 */

/*! fns mpi\_gather expr
 * Not yet written
 */

/*! fns mpi\_iprobe expr
 * Not yet written
 */

/*! fns mpi\_irecv expr
 * Not yet written
 */

/*! fns mpi\_isend expr
 * Not yet written
 */

/*! fns mpi\_probe expr
 * Not yet written
 */

/*! fns mpi\_recv expr
 * Not yet written
 */

/*! fns mpi\_scatter expr
 * Not yet written
 */

/*! fns mpi\_send expr
 * Not yet written
 */

/*! fns mpi\_sendrecv expr
 * Not yet written
 */

/*! fns mpi\_test expr
 * Not yet written
 */

/*! fns mpi\_wait expr
 * Not yet written
 */

/*! fns msd expr
 * Not yet written
 */

/*! fns native!-address expr
 * Not yet written
 */

/*! fns native!-getv expr
 * Not yet written
 */

/*! fns native!-putv expr
 * Not yet written
 */

/*! fns native!-type expr
 * Not yet written
 */

/*! fns nconc expr
 * Not yet written
 */

/*! fns ncons expr
 * Not yet written
 */

/*! fns neq expr
 * Not yet written
 */

/*! fns noisy!-setq fexpr
 * Not yet written
 */

/*! fns not expr
 * Not yet written
 */

/*! fns nreverse expr
 * Not yet written
 */

/*! fns null expr
 * Not yet written
 */

/*! fns numberp expr
 * Not yet written
 */

/*! fns oblist expr
 * Not yet written
 */

/*! fns oddp expr
 * Not yet written
 */

/*! fns oem!-supervisor expr
 * Not yet written
 */

/*! fns onep expr
 * Not yet written
 */

/*! fns open expr
 * Not yet written
 */

/*! fns open!-library expr
 * Not yet written
 */

/*! fns open!-url expr
 * Not yet written
 */

/*! fns or fexpr
 * Not yet written
 */

/*! fns orderp expr
 * Not yet written
 */

/*! fns ordp expr
 * Not yet written
 */

/*! fns output!-library fexpr
 * Not yet written
 */

/*! fns pagelength expr
 * Not yet written
 */

/*! fns pair expr
 * Not yet written
 */

/*! fns pairp expr
 * Not yet written
 */

/*! fns parallel expr
 * Not yet written
 */

/*! fns peekch expr
 * Not yet written
 */

/*! fns pipe!-open expr
 * Not yet written
 */

/*! fns plist expr
 * Not yet written
 */

/*! fns plus fexpr
 * Not yet written
 */

/*! fns plus2 expr
 * Not yet written
 */

/*! fns plusp expr
 * Not yet written
 */

/*! fns posn expr
 * Not yet written
 */

/*! fns preserve expr
 * Not yet written
 */

/*! fns prettyprint expr
 * Not yet written
 */

/*! fns prin expr
 * Not yet written
 */

/*! fns prin1 expr
 * Not yet written
 */

/*! fns prin2 expr
 * Not yet written
 */

/*! fns prin2a expr
 * Not yet written
 */

/*! fns prinbinary expr
 * Not yet written
 */

/*! fns princ expr
 * Not yet written
 */

/*! fns princ!-downcase expr
 * Not yet written
 */

/*! fns princ!-upcase expr
 * Not yet written
 */

/*! fns princl expr
 * Not yet written
 */

/*! fns prinhex expr
 * Not yet written
 */

/*! fns prinl expr
 * Not yet written
 */

/*! fns prinoctal expr
 * Not yet written
 */

/*! fns prinraw expr
 * Not yet written
 */

/*! fns print expr
 * Not yet written
 */

/*! fns print!-config!-header expr
 * Not yet written
 */

/*! fns print!-csl!-headers expr
 * Not yet written
 */

/*! fns print!-imports expr
 * Not yet written
 */

/*! fns printc expr
 * Not yet written
 */

/*! fns printcl expr
 * Not yet written
 */

/*! fns printl expr
 * Not yet written
 */

/*! fns printprompt expr
 * Not yet written
 */

/*! fns prog fexpr
 * Not yet written
 */

/*! fns prog1 fexpr
 * Not yet written
 */

/*! fns prog2 fexpr
 * Not yet written
 */

/*! fns progn fexpr
 * Not yet written
 */

/*! fns protect!-symbols expr
 * Not yet written
 */

/*! fns protected!-symbol!-warn expr
 * Not yet written
 */

/*! fns psetq macro
 * Not yet written
 */

/*! fns put expr
 * Not yet written
 */

/*! fns putc expr
 * Not yet written
 */

/*! fns putd expr
 * Not yet written
 */

/*! fns puthash expr
 * Not yet written
 */

/*! fns putv expr
 * Not yet written
 */

/*! fns putv!-char expr
 * Not yet written
 */

/*! fns putv16 expr
 * Not yet written
 */

/*! fns putv32 expr
 * Not yet written
 */

/*! fns putv8 expr
 * Not yet written
 */

/*! fns qcaar expr
 * Not yet written
 */

/*! fns qcadr expr
 * Not yet written
 */

/*! fns qcar expr
 * Not yet written
 */

/*! fns qcdar expr
 * Not yet written
 */

/*! fns qcddr expr
 * Not yet written
 */

/*! fns qcdr expr
 * Not yet written
 */

/*! fns qgetv expr
 * Not yet written
 */

/*! fns qputv expr
 * Not yet written
 */

/*! fns quote fexpr
 * Not yet written
 */

/*! fns quotient expr
 * Not yet written
 */

/*! fns random!-fixnum expr
 * Not yet written
 */

/*! fns random!-number expr
 * Not yet written
 */

/*! fns rassoc expr
 * Not yet written
 */

/*! fns rational expr
 * Not yet written
 */

/*! fns rdf expr
 * Not yet written
 */

/*! fns rds expr
 * Not yet written
 */

/*! fns read expr
 * Not yet written
 */

/*! fns readb expr
 * Not yet written
 */

/*! fns readch expr
 * Not yet written
 */

/*! fns readline expr
 * Not yet written
 */

/*! fns reclaim expr
 * Not yet written
 */

/*! fns remainder expr
 * Not yet written
 */

/*! fns remd expr
 * Not yet written
 */

/*! fns remflag expr
 * Not yet written
 */

/*! fns remhash expr
 * Not yet written
 */

/*! fns remob expr
 * Not yet written
 */

/*! fns remprop expr
 * Not yet written
 */

/*! fns rename!-file expr
 * Not yet written
 */

/*! fns representation expr
 * Not yet written
 */

/*! fns resource!-exceeded expr
 * Not yet written
 */

/*! fns resource!-limit expr
 * Not yet written
 */

/*! fns restart!-csl expr
 * Not yet written
 */

/*! fns restore!-c!-code expr
 * Not yet written
 */

/*! fns return fexpr
 * Not yet written
 */

/*! fns reverse expr
 * Not yet written
 */

/*! fns reversip expr
 * Not yet written
 */

/*! fns round expr
 * Not yet written
 */


/*! fns rplacw expr
 * Not yet written
 */

/*! fns rseek expr
 * Not yet written
 */

/*! fns rtell expr
 * Not yet written
 */

/*! fns s!:blankcount macro
 * Not yet written
 */

/*! fns s!:blanklist macro
 * Not yet written
 */

/*! fns s!:blankp macro
 * Not yet written
 */

/*! fns s!:depth macro
 * Not yet written
 */

/*! fns s!:do!-bindings expr
 * Not yet written
 */

/*! fns s!:do!-endtest expr
 * Not yet written
 */

/*! fns s!:do!-result expr
 * Not yet written
 */

/*! fns s!:do!-updates expr
 * Not yet written
 */

/*! fns s!:endlist expr
 * Not yet written
 */

/*! fns s!:expand!-do expr
 * Not yet written
 */

/*! fns s!:expand!-dolist expr
 * Not yet written
 */

/*! fns s!:expand!-dotimes expr
 * Not yet written
 */

/*! fns s!:explodes expr
 * Not yet written
 */

/*! fns s!:finishpending expr
 * Not yet written
 */

/*! fns s!:format expr
 * Not yet written
 */

/*! fns s!:indenting macro
 * Not yet written
 */

/*! fns s!:make!-psetq!-assignments expr
 * Not yet written
 */

/*! fns s!:make!-psetq!-bindings expr
 * Not yet written
 */

/*! fns s!:make!-psetq!-vars expr
 * Not yet written
 */

/*! fns s!:newframe macro
 * Not yet written
 */

/*! fns s!:oblist expr
 * Not yet written
 */

/*! fns s!:oblist1 expr
 * Not yet written
 */

/*! fns s!:overflow expr
 * Not yet written
 */

/*! fns s!:prindent expr
 * Not yet written
 */

/*! fns s!:prinl0 expr
 * Not yet written
 */

/*! fns s!:prinl1 expr
 * Not yet written
 */

/*! fns s!:prinl2 expr
 * Not yet written
 */

/*! fns s!:prvector expr
 * Not yet written
 */

/*! fns s!:putblank expr
 * Not yet written
 */

/*! fns s!:putch expr
 * Not yet written
 */

/*! fns s!:quotep expr
 * Not yet written
 */

/*! fns s!:setblankcount macro
 * Not yet written
 */


/*! fns s!:setblanklist macro
 * Not yet written
 */


/*! fns s!:setindenting macro
 * Not yet written
 */


/*! fns s!:stamp expr
 * Not yet written
 */

/*! fns s!:top macro
 * Not yet written
 */


/*! fns safe!-fp!-pl expr
 * Not yet written
 */

/*! fns safe!-fp!-pl0 expr
 * Not yet written
 */

/*! fns safe!-fp!-plus expr
 * Not yet written
 */

/*! fns safe!-fp!-quot expr
 * Not yet written
 */

/*! fns safe!-fp!-times expr
 * Not yet written
 */

/*! fns sample expr
 * Not yet written
 */

/*! fns sassoc expr
 * Not yet written
 */

/*! fns schar expr
 * Not yet written
 */

/*! fns scharn expr
 * Not yet written
 */

/*! fns sec expr
 * Not yet written
 */

/*! fns secd expr
 * Not yet written
 */

/*! fns sech expr
 * Not yet written
 */

/*! fns seprp expr
 * Not yet written
 */

/*! fns set expr
 * Not yet written
 */

/*! fns set!-autoload expr
 * Not yet written
 */

/*! fns set!-help!-file expr
 * Not yet written
 */

/*! fns set!-print!-precision expr
 * Not yet written
 */

/*! fns set!-small!-modulus expr
 * Not yet written
 */

/*! fns setpchar expr
 * Not yet written
 */

/*! fns setq fexpr
 * Not yet written
 */

/*! fns silent!-system expr
 * Not yet written
 */

/*! fns simple!-string!-p expr
 * Not yet written
 */

/*! fns simple!-vector!-p expr
 * Not yet written
 */

/*! fns sin expr
 * Not yet written
 */

/*! fns sind expr
 * Not yet written
 */

/*! fns sinh expr
 * Not yet written
 */

/*! fns smemq expr
 * Not yet written
 */

/*! fns sort expr
 * Not yet written
 */

/*! fns sortip expr
 * Not yet written
 */

/*! fns spaces expr
 * Not yet written
 */

/*! fns special!-char expr
 * Not yet written
 */

/*! fns special!-form!-p expr
 * Not yet written
 */

/*! fns spool expr
 * Not yet written
 */

/*! fns sqrt expr
 * Not yet written
 */

/*! fns stable!-sort expr
 * Not yet written
 */

/*! fns stable!-sortip expr
 * Not yet written
 */

/*! fns start!-module expr
 * Not yet written
 */

/*! fns startup!-banner expr
 * Not yet written
 */

/*! fns stop expr
 * Not yet written
 */

/*! fns streamp expr
 * Not yet written
 */

/*! fns stringp expr
 * Not yet written
 */

/*! fns sub1 expr
 * Not yet written
 */

/*! fns subla expr
 * Not yet written
 */

/*! fns sublis expr
 * Not yet written
 */

/*! fns subst expr
 * Not yet written
 */

/*! fns superprinm expr
 * Not yet written
 */

/*! fns superprintm expr
 * Not yet written
 */

/*! fns sxhash expr
 * Not yet written
 */

/*! fns symbol!-argcode expr
 * Not yet written
 */

/*! fns symbol!-argcount expr
 * Not yet written
 */

/*! fns symbol!-env expr
 * Not yet written
 */

/*! fns symbol!-fastgets expr
 * Not yet written
 */

/*! fns symbol!-fn!-cell expr
 * Not yet written
 */

/*! fns symbol!-function expr
 * Not yet written
 */

/*! fns symbol!-make!-fastget expr
 * Not yet written
 */

/*! fns symbol!-name expr
 * Not yet written
 */

/*! fns symbol!-protect expr
 * Not yet written
 */

/*! fns symbol!-restore!-fns expr
 * Not yet written
 */

/*! fns symbol!-set!-definition expr
 * Not yet written
 */

/*! fns symbol!-set!-env expr
 * Not yet written
 */

/*! fns symbol!-set!-native expr
 * Not yet written
 */

/*! fns symbol!-value expr
 * Not yet written
 */

/*! fns symbolp expr
 * Not yet written
 */

/*! fns system expr
 * Not yet written
 */

/*! fns tagbody fexpr
 * Not yet written
 */

/*! fns tan expr
 * Not yet written
 */

/*! fns tand expr
 * Not yet written
 */

/*! fns tanh expr
 * Not yet written
 */

/*! fns terpri expr
 * Not yet written
 */

/*! fns threevectorp expr
 * Not yet written
 */

/*! fns throw fexpr
 * Not yet written
 */

/*! fns time expr
 * Not yet written
 */

/*! fns times fexpr
 * Not yet written
 */

/*! fns times2 expr
 * Not yet written
 */

/*! fns tmpnam expr
 * Not yet written
 */

/*! fns trace expr
 * Not yet written
 */

/*! fns trace!-all expr
 * Not yet written
 */

/*! fns traceset expr
 * Not yet written
 */

/*! fns traceset1 expr
 * Not yet written
 */

/*! fns truename expr
 * Not yet written
 */

/*! fns truncate expr
 * Not yet written
 */

/*! fns ttab expr
 * Not yet written
 */

/*! fns tyo expr
 * Not yet written
 */

/*! fns undouble!-execute expr
 * Not yet written
 */

/*! fns unfluid expr
 * Not yet written
 */

/*! fns unglobal expr
 * Not yet written
 */

/*! fns union expr
 * Not yet written
 */

/*! fns unless fexpr
 * Not yet written
 */

/*! fns unmake!-global expr
 * Not yet written
 */

/*! fns unmake!-special expr
 * Not yet written
 */

/*! fns unreadch expr
 * Not yet written
 */

/*! fns untrace expr
 * Not yet written
 */

/*! fns untraceset expr
 * Not yet written
 */

/*! fns untraceset1 expr
 * Not yet written
 */

/*! fns unwind!-protect fexpr
 * Not yet written
 */

/*! fns upbv expr
 * Not yet written
 */

/*! fns user!-homedir!-pathname expr
 * Not yet written
 */

/*! fns vectorp expr
 * Not yet written
 */

/*! fns verbos expr
 * Not yet written
 */

/*! fns when fexpr
 * Not yet written
 */

/*! fns where!-was!-that expr
 * Not yet written
 */

/*! fns window!-heading expr
 * Not yet written
 */

/*! fns writable!-libraryp expr
 * Not yet written
 */

/*! fns write!-module expr
 * Not yet written
 */

/*! fns wrs expr
 * Not yet written
 */

/*! fns xassoc expr
 * Not yet written
 */

/*! fns xcons expr
 * Not yet written
 */

/*! fns xdifference expr
 * Not yet written
 */

/*! fns xtab expr
 * Not yet written
 */

/*! fns zerop expr
 * Not yet written
 */

/*! fns [~block] !$\sim$block fexpr
 * Not yet written
 */

/*! fns [~let] !$\sim$let fexpr
 * Not yet written
 */

/*! fns [~tyi] !$\sim$tyi expr
 * Not yet written
 */

/* end of tempdoc.c */
