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

/* Signature: 3496b3d1 18-Nov-2011 */


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

/*! predef [*applyhook] \item [{\ttfamily !*applyhook!*}]
 * If this is set it might be supposed to be the name of a function used
 * by the interpreter as a callbackm but at presnet it does not actually do
 * anything!
 */

/*! predef [*break-loop*] \item [{\ttfamily !*break!-loop!*}]
 * If the value of this is a symbol that is defined as a function of one
 * argument then it is called during the processing on an error. This has not
 * been used in anger and so its whole status may be dubious!
 */

/*! predef [*carcheckflag] \item [{\ttfamily !*carcheckflag}]
 * In general CSL arranges that every {\ttfamily car} or {\ttfamily cdr} access
 * is checked for validity. Once upon a time setting this variable to nil
 * turned such checks off in the hope of gaining a little speed. But it no
 * longer does that. It may have a minor effect on array access primitives.
 */

/*! predef [*comp] \item [{\ttfamily !*comp}]
 * When set each function is compiled (into bytecodes) as it gets defined.
 */

/*! predef [*debug-io] \item [{\ttfamily !*debug!-io!*}]
 * An I/O channel intended to be used for diagnostic interactions.
 */

/*! predef [*echo] \item [{\ttfamily !*echo}]
 * When this is non-nil characters that are read from an input file are
 * echoed to the standard output. This gives a more comlete transcript in
 * a log file, but can sometimes amount to over-verbose output.
 */

/*! predef [*error-message*] \item [{\ttfamily !*error!-messages!*}]
 * Has the value nil and does not do anything!
 */

/*! predef [*error-output*] \item [{\ttfamily !*error!-output!*}]
 * An I/O channel intended for diagnostic output.
 */

/*! predef [*evalhook] \item [{\ttfamily !*evalhook!*}]
 * See {\ttfamily !*applyhook!*}. This also does not do anything at present.
 */

/*! predef [*gchook*] \item [{\ttfamily !*gc!-hook!*}]
 * If this is set to have as its value that is a function of one argument then
 * that function is called with {\ttfamily nil} on every minor entry to the
 * garbage collection, and with argument {\ttfamily t} at the end of a ``genuine''
 * full garbage collection.
 */

/*! predef [*hanaku] \item [{\ttfamily !*hankaku}]
 * This was concerned with internationalisation to support a Japanese
 * locale but has not been activated for some while. In the fullness of time I
 * hope to migrate CSL to use an UTF8 representation of Unicode characters
 * internally, but that upgrade is at present an ideal and a project not
 * a reality. Volunteers to help welcomed.
 */

/*! predef [*loop-print*] \item [{\ttfamily !*loop!-print!*}]
 * Probably not used at present.
 */

/*! predef [*lower] \item [{\ttfamily !*lower}]
 * Not yet written
 */

/*! predef [*macroexpand-hook*] \item [{\ttfamily !*macroexpand!-hook!*}]
 * Not yet written
 */

/*! predef [*math-output*] \item [{\ttfamily !*math!-output!*}]
 * Not yet written
 */

/*! predef [*native_code] \item [{\ttfamily !*native\_code}]
 * Not yet written
 */

/*! predef [*notailcall] \item [{\ttfamily !*notailcall}]
 * Not yet written
 */

/*! predef [*package*] \item [{\ttfamily !*package!*}]
 * Not yet written
 */

/*! predef [*pgwd] \item [{\ttfamily !*pgwd}]
 * Not yet written
 */

/*! predef [*[lap] \item [{\ttfamily !*plap}]
 * Not yet written
 */

/*! predef [*pretty-symamtic] \item [{\ttfamily !*pretty!-symmetric}]
 * Not yet written
 */

/*! predef [*prinl-fn!*] \item [{\ttfamily !*prinl!-fn!*}]
 * Not yet written
 */

/*! predef [*prinl-index] \item [{\ttfamily !*prinl!-index!*}]
 * Not yet written
 */

/*! predef [*prinl-visited-nodes*] \item [{\ttfamily !*prinl!-visited!-nodes!*}]
 * Not yet written
 */

/*! predef [*print-array*] \item [{\ttfamily !*print!-array!*}]
 * Not yet written
 */

/*! predef [*print-length*] \item [{\ttfamily !*print!-length!*}]
 * Not yet written
 */

/*! predef [*print-level*] \item [{\ttfamily !*print!-level!*}]
 * Not yet written
 */

/*! predef [*pwrds] \item [{\ttfamily !*pwrds}]
 * Not yet written
 */

/*! predef [*query-io*] \item [{\ttfamily !*query!-io!*}]
 * Not yet written
 */

/*! predef [*quotes] \item [{\ttfamily !*quotes}]
 * Not yet written
 */

/*! predef [*raise] \item [{\ttfamily !*raise}]
 * Not yet written
 */

/*! predef [*redefmsg] \item [{\ttfamily !*redefmsg}]
 * Not yet written
 */

/*! predef [*resources*] \item [{\ttfamily !*resources!*}]
 * Not yet written
 */

/*! predef [*savedef] \item [{\ttfamily !*savedef}]
 * Not yet written
 */

/*! predef [*spool-output*] \item [{\ttfamily !*spool!-output!*}]
 * Not yet written
 */

/*! predef [*standard-input*] \item [{\ttfamily !*standard!-input!*}]
 * Not yet written
 */

/*! predef [*standard-output*] \item [{\ttfamily !*standard!-output!*}]
 * Not yet written
 */

/*! predef [*terminal-io*] \item [{\ttfamily !*terminal!-io!*}]
 * Not yet written
 */

/*! predef [*trace-output*] \item [{\ttfamily !*trace!-output!*}]
 * Not yet written
 */

/*! predef [@cslbase] \item [{\ttfamily !@cslbase}]
 * Not yet written
 */

/*! predef [bn] \item [{\ttfamily bn}]
 * Not yet written
 */

/*! predef [bufferi]  \item [{\ttfamily bufferi}]
 * Not yet written
 */

/*! predef [buffero]  \item [{\ttfamily bufferp}]
 * Not yet written
 */

/*! predef [common-lisp-mode]  \item [{\ttfamily common!-lisp!-mode}]
 * Not yet written
 */

/*! predef [crbuf*]  \item [{\ttfamily crbuf!*}]
 * Not yet written
 */

/*! predef [emsg*]  \item [{\ttfamily emsg!*}]
 * Not yet written
 */

/*! predef [eof*]  \item [{\ttfamily eof!*}]
 * Not yet written
 */

/*! predef [indblanks]  \item [{\ttfamily indblanks}]
 * Not yet written
 */

/*! predef [indentlevel]  \item [{\ttfamily indentlevel}]
 * Not yet written
 */

/*! predef [initialblanls]  \item [{\ttfamily initialblanks}]
 * Not yet written
 */

/*! predef [lispsystem*]  \item [{\ttfamily lispsystem!*}]
 * Not yet written
 */

/*! predef [lmar]  \item [{\ttfamily lmar}]
 * Not yet written
 */

/*! predef [load-source]  \item [{\ttfamily load!-source}]
 * Not yet written
 */

/*! predef [nil]  \item [{\ttfamily nil}]
 * Not yet written
 */

/*! predef [ofl*]  \item [{\ttfamily ofl!*}]
 * Not yet written
 */

/*! predef ]pendingrpars]  \item [{\ttfamily pendingrpars}]
 * Not yet written
 */

/*! predef [program*]  \item [{\ttfamily program!*}]
 * Not yet written
 */

/*! predef [rmar]  \item [{\ttfamily rmar}]
 * Not yet written
 */

/*! predef [rparcount]  \item [{\ttfamily rparcount}]
 * Not yet written
 */

/*! predef [s:gensym-serial]  \item [{\ttfamily s!:gensym!-serial}]
 * Not yet written
 */

/*! predef [stack]  \item [{\ttfamily stack}]
 * Not yet written
 */

/*! predef [t]  \item [{\ttfamily t}]
 * Not yet written
 */

/*! predef [thin*]  \item [{\ttfamily thin!*}]
 * Not yet written
 */

/*! predef [ttype*]  \item [{\ttfamily ttype!*}]
 * Not yet written

/*!! flags [04] Flags and Properties
 *
 * Most of tags here are probably not much use to end-users, but I am noting them
 * as a matter of completeness.
 *
 */

/*! flags [s:ppchar]  \item [{\ttfamily s!:ppchar} and {\ttfamily s!:ppformat}]
 * These are used in the prettyprint code found in {\ttfamily extras.red}. A
 * name is given a property {\ttfamily s!:ppformat} if in prettyprinted display
 * its first few arguments should appear on the same line as it if at all
 * possible. The {\ttfamily s!:ppchar} property is used to make the display of
 * bracket characters a little more tide in the source code.
 */

/*! flags [switch]  \item [{\ttfamily switch}]
 * In the Reduce parser some names are ``switches'', and then directives such
 * as {\ttfamily on xxx} and {\ttfamily off xx} have the effect of setting or
 * clearing the value of a variable {\ttfamily !*xxx}. This is managed by
 * setting the {\ttfamily switch} flag om {\ttfamily xxx}. CSL sets some
 * things as switches ready for when they may be used by the Reduce parser.
 */

/*! flags [lose]  \item [{\ttfamily lose}]
 * If a name is flagged as {ttfamily lose} then a subsequent attempt to
 * define or redefine it will be ignored.
 */

/*! flags [~magic-internal-symbol~]  \item [{\ttfamily !$\sim$magic!-internal!-symbol!$\sim$}]
 * CSL does not have a clear representation for functions that is separated from
 * the representation of an identifier, and so when you ask to get the value
 * of a raw function you get an identifier (probably a gensym) and this
 * tag is used to link such values with the symbols they were originally
 * extracted from.
 */

/*!! fns [05] \section{Functions and Special Forms}
 *
 * Each line here shows a name and then one of the words {\itshape  expr},
 * {\itshape  fexpr} or {\itshape  macro}. In some cases there can also be special
 * treatment of functions by the compiler so that they get compiled in-line.
 * \begin{description}
 */

/*! fns [~~~~~~~~]  \end{description}
 */

/*! fns [abs]  \item [{\ttfamily abs} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acons expr] \item [{\ttfamily acons} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acos expr] \item [{\ttfamily acos} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acosd expr] \item [{\ttfamily acosd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acosh expr] \item [{\ttfamily acosh} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acot expr] \item [{\ttfamily acot} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acotd expr] \item [{\ttfamily acotd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acoth expr] \item [{\ttfamily acoth} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acsc expr] \item [{\ttfamily acsc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acscd expr] \item [{\ttfamily acscd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [acsch expr] \item [{\ttfamily acsch} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [add1 expr] \item [{\ttfamily add1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [and fexpr] \item [{\ttfamily and} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [append expr] \item [{\ttfamily append} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [apply expr] \item [{\ttfamily apply} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [apply0 expr] \item [{\ttfamily apply0} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [apply1 expr] \item [{\ttfamily apply1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [apply2 expr] \item [{\ttfamily apply2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [apply3 expr] \item [{\ttfamily apply3} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [asec expr] \item [{\ttfamily asec} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [asecd expr] \item [{\ttfamily asecd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [asech expr] \item [{\ttfamily asech} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ash expr] \item [{\ttfamily ash} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ash1 expr] \item [{\ttfamily ash1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [asin expr] \item [{\ttfamily asin} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [asind expr] \item [{\ttfamily asind} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [asinh expr] \item [{\ttfamily asinh} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [assoc expr] \item [{\ttfamily assoc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [assoc!*!* expr] \item [{\ttfamily assoc!*!*} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [atan expr] \item [{\ttfamily atan} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [atan2 expr] \item [{\ttfamily atan2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [atan2d expr] \item [{\ttfamily atan2d} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [atand expr] \item [{\ttfamily atand} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [atanh expr] \item [{\ttfamily atanh} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [atom expr] \item [{\ttfamily atom} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [atsoc expr] \item [{\ttfamily atsoc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [batchp expr] \item [{\ttfamily batchp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_close_input]  \item [{\ttfamily binary\_close\_input} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_close_output]  \item [{\ttfamily binary\_close\_output} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_open_input]  \item [{\ttfamily binary\_open\_input} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_open_output]  \item [{\ttfamily binary\_open\_output} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_prin1]  \item [{\ttfamily binary\_prin1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_prin2]  \item [{\ttfamily binary\_prin2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_prin3]  \item [{\ttfamily binary\_prin3} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_prinbyte]  \item [{\ttfamily binary\_prinbyte} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_princ]  \item [{\ttfamily binary\_princ} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_prinfloat]  \item [{\ttfamily binary\_prinfloat} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_read2]  \item [{\ttfamily binary\_read2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_read3]  \item [{\ttfamily binary\_read3} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_read4]  \item [{\ttfamily binary\_read4} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_readbyte]  \item [{\ttfamily binary\_readbyte} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_readfloat]  \item [{\ttfamily binary\_readfloat} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_select_input]  \item [{\ttfamily binary\_select\_input} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [binary_terpri]  \item [{\ttfamily binary\_terpri} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [binopen expr] \item [{\ttfamily binopen} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [boundp expr] \item [{\ttfamily boundp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [bps-getv]  \item [{\ttfamily bps!-getv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [bps-putv]  \item [{\ttfamily bps!-putv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [bps-upvb]  \item [{\ttfamily bps!-upbv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [bpsp expr] \item [{\ttfamily bpsp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [break-loop]  \item [{\ttfamily break!-loop} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [byte!-getv expr] \item [{\ttfamily byte!-getv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [bytecounts expr] \item [{\ttfamily bytecounts} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [c_out]  \item [{\ttfamily c\_out} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [carcheck expr] \item [{\ttfamily carcheck} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [catch fexpr] \item [{\ttfamily catch} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [cbrt expr] \item [{\ttfamily cbrt} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ceiling expr] \item [{\ttfamily ceiling} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [char-code]  \item [{\ttfamily char!-code} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [char-downcase]  \item [{\ttfamily char!-downcase} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [char-upcase]  \item [{\ttfamily char!-upcase} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [chdir expr] \item [{\ttfamily chdir} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [check-c-code]  \item [{\ttfamily check!-c!-code} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [checkpoint expr] \item [{\ttfamily checkpoint} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [cl-equal]  \item [{\ttfamily cl!-equal} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [close expr] \item [{\ttfamily close} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [close-library]  \item [{\ttfamily close!-library} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [clrhash expr] \item [{\ttfamily clrhash} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [code-char]  \item [{\ttfamily code!-char} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [codep expr] \item [{\ttfamily codep} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [compile expr] \item [{\ttfamily compile} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [compile-all]  \item [{\ttfamily compile!-all} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [compress expr] \item [{\ttfamily compress} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [cond fexpr] \item [{\ttfamily cond} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [cons expr] \item [{\ttfamily cons} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [consp expr] \item [{\ttfamily consp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [constantp expr] \item [{\ttfamily constantp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [contained expr] \item [{\ttfamily contained} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [convert-to-evector]  \item [{\ttfamily convert!-to!-evector} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [copy expr] \item [{\ttfamily copy} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [copy-module]  \item [{\ttfamily copy!-module} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [copy-native]  \item [{\ttfamily copy!-native} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [cos expr] \item [{\ttfamily cos} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [cosd expr] \item [{\ttfamily cosd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [cosh expr] \item [{\ttfamily cosh} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [cot expr] \item [{\ttfamily cot} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [cotd expr] \item [{\ttfamily cotd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [coth expr] \item [{\ttfamily coth} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [create-directory]  \item [{\ttfamily create!-directory} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [csc expr] \item [{\ttfamily csc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [cscd expr] \item [{\ttfamily cscd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [csch expr] \item [{\ttfamily csch} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [date expr] \item [{\ttfamily date} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [dated-name]  \item [{\ttfamily dated!-name} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [datelessp expr] \item [{\ttfamily datelessp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [datestamp expr] \item [{\ttfamily datestamp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [de fexpr] \item [{\ttfamily de} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/*! fns [define-in-module]  \item [{\ttfamily define!-in!-module} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [deflist expr] \item [{\ttfamily deflist} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [deleq expr] \item [{\ttfamily deleq} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [delete expr] \item [{\ttfamily delete} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [delete-file]  \item [{\ttfamily delete!-file} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [delete-module]  \item [{\ttfamily delete!-module} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [difference expr] \item [{\ttfamily difference} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [digit expr] \item [{\ttfamily digit} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [directoryp expr] \item [{\ttfamily directoryp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [divide expr] \item [{\ttfamily divide} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [dm fexpr] \item [{\ttfamily dm} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [do macro] \item [{\ttfamily do} {\itshape macro}] ~\newline
 * Not yet written
 */

/*! fns [do*]  \item [{\ttfamily do!*} {\itshape macro}] ~\newline
 * Not yet written
 */

/* fns [dolist macro] \item [{\ttfamily dolist} {\itshape macro}] ~\newline
 * Not yet written
 */


/* fns [dotimes macro] \item [{\ttfamily dotimes} {\itshape macro}] ~\newline
 * Not yet written
 */

/*! fns [double-execute]  \item [{\ttfamily double!-execute} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [egetv expr] \item [{\ttfamily egetv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [eject expr] \item [{\ttfamily eject} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [enable-backtrace]  \item [{\ttfamily enable!-backtrace} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [enable-errorset]  \item [{\ttfamily enable!-errorset} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [encapsulatedp expr] \item [{\ttfamily encapsulatedp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [endp expr] \item [{\ttfamily endp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [eputv expr] \item [{\ttfamily eputv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [eq expr] \item [{\ttfamily eq} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [eq-safe]  \item [{\ttfamily eq!-safe} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [eqcar expr] \item [{\ttfamily eqcar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [eql expr] \item [{\ttfamily eql} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [eqlhash expr] \item [{\ttfamily eqlhash} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [eqn expr] \item [{\ttfamily eqn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [equal expr] \item [{\ttfamily equal} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [equalcar expr] \item [{\ttfamily equalcar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [equalp expr] \item [{\ttfamily equalp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [error expr] \item [{\ttfamily error} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [error1 expr] \item [{\ttfamily error1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [errorset expr] \item [{\ttfamily errorset} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [eupbv expr] \item [{\ttfamily eupbv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [eval expr] \item [{\ttfamily eval} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [eval-when]  \item [{\ttfamily eval!-when} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [evectorp expr] \item [{\ttfamily evectorp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [evenp expr] \item [{\ttfamily evenp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [evlis expr] \item [{\ttfamily evlis} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [exp expr] \item [{\ttfamily exp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [expand expr] \item [{\ttfamily expand} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explode expr] \item [{\ttfamily explode} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explode2 expr] \item [{\ttfamily explode2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explode2lc expr] \item [{\ttfamily explode2lc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explode2lcn expr] \item [{\ttfamily explode2lcn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explode2n expr] \item [{\ttfamily explode2n} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explode2uc expr] \item [{\ttfamily explode2uc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explode2ucn expr] \item [{\ttfamily explode2ucn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explodebinary expr] \item [{\ttfamily explodebinary} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explodec expr] \item [{\ttfamily explodec} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explodecn expr] \item [{\ttfamily explodecn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explodehex expr] \item [{\ttfamily explodehex} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [exploden expr] \item [{\ttfamily exploden} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [explodeoctal expr] \item [{\ttfamily explodeoctal} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [expt expr] \item [{\ttfamily expt} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [faslout expr] \item [{\ttfamily faslout} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [fetch!-url expr] \item [{\ttfamily fetch!-url} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [fgetv32 expr] \item [{\ttfamily fgetv32} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [fgetv64 expr] \item [{\ttfamily fgetv64} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [file-length]  \item [{\ttfamily file!-length} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [file-readablep]  \item [{\ttfamily file!-readablep} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [file-writablep]  \item [{\ttfamily file!-writeablep} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [filedate expr] \item [{\ttfamily filedate} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [filep expr] \item [{\ttfamily filep} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [fix expr] \item [{\ttfamily fix} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [fixp expr] \item [{\ttfamily fixp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [flag expr] \item [{\ttfamily flag} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [flagp expr] \item [{\ttfamily flagp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [flagp**]  \item [{\ttfamily flagp!*!*} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [flagpcar expr] \item [{\ttfamily flagpcar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [float expr] \item [{\ttfamily float} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [floatp expr] \item [{\ttfamily floatp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [floor expr] \item [{\ttfamily floor} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [fluid expr] \item [{\ttfamily fluid} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [fluidp expr] \item [{\ttfamily fluidp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [flush expr] \item [{\ttfamily flush} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [format macro] \item [{\ttfamily format} {\itshape macro}] ~\newline
 * Not yet written
 */


/*! fns [fp-evaluate]  \item [{\ttfamily fp!-evaluate} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [fputv32 expr] \item [{\ttfamily fputv32} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [fputv64 expr] \item [{\ttfamily fputv64} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [frexp expr] \item [{\ttfamily frexp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [funcall expr] \item [{\ttfamily funcall} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [funcall*]  \item [{\ttfamily funcall!*} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [function fexpr] \item [{\ttfamily function} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [gcdn expr] \item [{\ttfamily gcdn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [gctime expr] \item [{\ttfamily gctime} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [gensym expr] \item [{\ttfamily gensym} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [gensym1 expr] \item [{\ttfamily gensym1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [gensym2 expr] \item [{\ttfamily gensym2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [gensymp expr] \item [{\ttfamily gensymp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [geq expr] \item [{\ttfamily geq} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [get expr] \item [{\ttfamily get} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [get*]  \item [{\ttfamily get!*} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [get-current-directory]  \item [{\ttfamily get!-current!-directory} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [get-lisp-directory]  \item [{\ttfamily get!-lisp!-directory} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [getd expr] \item [{\ttfamily getd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [getenv expr] \item [{\ttfamily getenv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [gethash expr] \item [{\ttfamily gethash} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [getv expr] \item [{\ttfamily getv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [getv16 expr] \item [{\ttfamily getv16} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [getv32 expr] \item [{\ttfamily getv32} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [getv8 expr] \item [{\ttfamily getv8} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [global expr] \item [{\ttfamily global} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [globalp expr] \item [{\ttfamily globalp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [go fexpr] \item [{\ttfamily go} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [greaterp expr] \item [{\ttfamily greaterp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [hash-table-p]  \item [{\ttfamily hash!-table!-p} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [hashcontents expr] \item [{\ttfamily hashcontents} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [hashtagged-name]  \item [{\ttfamily hashtagged!-name} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [hypot expr] \item [{\ttfamily hypot} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [iadd1 expr] \item [{\ttfamily iadd1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [idapply expr] \item [{\ttfamily idapply} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [idifference expr] \item [{\ttfamily idifference} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [idp expr] \item [{\ttfamily idp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [iequal expr] \item [{\ttfamily iequal} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [if fexpr] \item [{\ttfamily if} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [igeq expr] \item [{\ttfamily igeq} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [igreaterp expr] \item [{\ttfamily igreaterp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ileq expr] \item [{\ttfamily ileq} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ilessp expr] \item [{\ttfamily ilessp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ilogand expr] \item [{\ttfamily ilogand} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ilogor expr] \item [{\ttfamily ilogor} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ilogxor expr] \item [{\ttfamily ilogxor} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [imax expr] \item [{\ttfamily imax} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [imin expr] \item [{\ttfamily imin} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [iminus expr] \item [{\ttfamily iminus} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [iminusp expr] \item [{\ttfamily iminusp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [indirect expr] \item [{\ttfamily indirect} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [inorm expr] \item [{\ttfamily inorm} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [input-libraries]  \item [{\ttfamily input!-libraries} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/*! fns [instate-c-code]  \item [{\ttfamily instate!-c!-code} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [integerp expr] \item [{\ttfamily integerp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [intern expr] \item [{\ttfamily intern} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [interbal-open]  \item [{\ttfamily internal!-open} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [intersection expr] \item [{\ttfamily intersection} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ionep expr] \item [{\ttfamily ionep} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [iplus expr] \item [{\ttfamily iplus} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [iplus2 expr] \item [{\ttfamily iplus2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [iquotient expr] \item [{\ttfamily iquotient} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [iremainder expr] \item [{\ttfamily iremainder} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [irightshift expr] \item [{\ttfamily irightshift} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [is-console]  \item [{\ttfamily is!-console} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [isub1 expr] \item [{\ttfamily isub1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [itimes expr] \item [{\ttfamily itimes} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [itimes2 expr] \item [{\ttfamily itimes2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [izerop expr] \item [{\ttfamily izerop} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [last expr] \item [{\ttfamily last} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [lastcar expr] \item [{\ttfamily lastcar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [lastpair expr] \item [{\ttfamily lastpair} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [lcmn expr] \item [{\ttfamily lcmn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [length expr] \item [{\ttfamily length} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [lengthc expr] \item [{\ttfamily lengthc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [leq expr] \item [{\ttfamily leq} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [lessp expr] \item [{\ttfamily lessp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [let*]  \item [{\ttfamily let!*} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/*! fns [library-members]  \item [{\ttfamily library!-members} {\itshape  expr}] ~\newline
 * Returns a list of all the modules that could potentially be loaded using
 * {\ttfamily load!-module}. See {\ttfamily list!-modules} to get a human
 * readable display that looks more like the result of listing a directory, or
 * {\ttfamily modulep} for checking the state of a particular named module.
 *
 */

/*! fns [library-name]  \item [{\ttfamily library!-name} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [linelength expr] \item [{\ttfamily linelength} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [list fexpr] \item [{\ttfamily list} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/*! fns [list*]  \item [{\ttfamily list!*} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/*! fns [list-directory]  \item [{\ttfamily list!-directory} {\itshape  expr}] ~\newline
 * Not yet written
 *
 */

/*! fns [list-modules]  \item [{\ttfamily list!-modules} {\itshape  expr}] ~\newline
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

/*! fns [list-to-string]  \item [{\ttfamily list!-to!-string} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [list-to-symbol]  \item [{\ttfamily list!-to!-symbol} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [list-to-vector]  \item [{\ttfamily list!-to!-vector} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [list2 expr] \item [{\ttfamily list2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [list2*]  \item [{\ttfamily list2!*} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [list3 expr] \item [{\ttfamily list3} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [list3*]  \item [{\ttfamily list3!*} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [list4 expr] \item [{\ttfamily list4} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [liter expr] \item [{\ttfamily liter} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ln expr] \item [{\ttfamily ln} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [load-module]  \item [{\ttfamily load!-module} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [load-source]  \item [{\ttfamily load!-source} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [log expr] \item [{\ttfamily log} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [log10 expr] \item [{\ttfamily log10} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [logand expr] \item [{\ttfamily logand} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [logb expr] \item [{\ttfamily logb} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [logeqv expr] \item [{\ttfamily logeqv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [lognot expr] \item [{\ttfamily lognot} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [logor expr] \item [{\ttfamily logor} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [logxor expr] \item [{\ttfamily logxor} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [lose-precision]  \item [{\ttfamily lose!-precision} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [lposn expr] \item [{\ttfamily lposn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [lsd expr] \item [{\ttfamily lsd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [macro-function]  \item [{\ttfamily macro!-function} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [macroexpand expr] \item [{\ttfamily macroexpand} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [macroexpand-1]  \item [{\ttfamily macroexpand!-1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [make-bps]  \item [{\ttfamily make!-bps} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [make-function-stream]  \item [{\ttfamily make!-function!-stream} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [make-global]  \item [{\ttfamily make!-global} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [make-native]  \item [{\ttfamily make!-native} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [make-random-state]  \item [{\ttfamily make!-random!-state} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [make-simple-string]  \item [{\ttfamily make!-simple!-string} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [make-special]  \item [{\ttfamily make!-special} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [map expr] \item [{\ttfamily map} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mapc expr] \item [{\ttfamily mapc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mapcan expr] \item [{\ttfamily mapcan} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mapcar expr] \item [{\ttfamily mapcar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mapcon expr] \item [{\ttfamily mapcon} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [maphash expr] \item [{\ttfamily maphash} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [maple\_atomic\_value expr] \item [{\ttfamily maple\_atomic\_value} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [maple\_component expr] \item [{\ttfamily maple\_component} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [maple\_integer expr] \item [{\ttfamily maple\_integer} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [maple\_length expr] \item [{\ttfamily maple\_length} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [maple\_string\_data expr] \item [{\ttfamily maple\_string\_data} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [maple\_tag expr] \item [{\ttfamily maple\_tag} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [maplist expr] \item [{\ttfamily maplist} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mapstore expr] \item [{\ttfamily mapstore} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [math-display]  \item [{\ttfamily math!-display} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [max expr] \item [{\ttfamily max} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [max2 expr] \item [{\ttfamily max2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [md5 expr] \item [{\ttfamily md5} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [md60 expr] \item [{\ttfamily md60} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [member expr] \item [{\ttfamily member} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [member**]  \item [{\ttfamily member!*!*} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [memq expr] \item [{\ttfamily memq} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [min expr] \item [{\ttfamily min} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [min2 expr] \item [{\ttfamily min2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [minus expr] \item [{\ttfamily minus} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [minusp expr] \item [{\ttfamily minusp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkevect expr] \item [{\ttfamily mkevect} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkfvect32 expr] \item [{\ttfamily mkfvect32} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkfvect64 expr] \item [{\ttfamily mkfvect64} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkhash expr] \item [{\ttfamily mkhash} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkquote expr] \item [{\ttfamily mkquote} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkvect expr] \item [{\ttfamily mkvect} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkvect16 expr] \item [{\ttfamily mkvect16} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkvect32 expr] \item [{\ttfamily mkvect32} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkvect8 expr] \item [{\ttfamily mkvect8} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mkxvect expr] \item [{\ttfamily mkxvect} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mod expr] \item [{\ttfamily mod} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [modular!-difference expr] \item [{\ttfamily modular!-difference} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [modular!-expt expr] \item [{\ttfamily modular!-expt} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [modular!-minus expr] \item [{\ttfamily modular!-minus} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [modular!-number expr] \item [{\ttfamily modular!-number} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [modular!-plus expr] \item [{\ttfamily modular!-plus} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [modular!-quotient expr] \item [{\ttfamily modular!-quotient} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [modular!-reciprocal expr] \item [{\ttfamily modular!-reciprocal} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [modular!-times expr] \item [{\ttfamily modular!-times} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [modulep expr] \item [{\ttfamily modulep} {\itshape  expr}] ~\newline
 * This takes a single argument and checks whether there is a loadable module
 * of that name. If there is not then {\ttfamily nil} is returned, otherwise a
 * string that indicates the date-stamp on the module is given. See
 * {\ttfamily datelessp} for working with such dates, and {\ttfamily
 * library!-members} for finding a list of all modules that are available.
 *
 */

/* fns [mpi\_allgather expr] \item [{\ttfamily mpi\_allgather} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_alltoall expr] \item [{\ttfamily mpi\_alltoall} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_barrier expr] \item [{\ttfamily mpi\_barrier} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_bcast expr] \item [{\ttfamily mpi\_bcast} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_comm\_rank expr] \item [{\ttfamily mpi\_comm\_rank} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_comm\_size expr] \item [{\ttfamily mpi\_comm\_size} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_gather expr] \item [{\ttfamily mpi\_gather} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_iprobe expr] \item [{\ttfamily mpi\_iprobe} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_irecv expr] \item [{\ttfamily mpi\_irecv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_isend expr] \item [{\ttfamily mpi\_isend} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_probe expr] \item [{\ttfamily mpi\_probe} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_recv expr] \item [{\ttfamily mpi\_recv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_scatter expr] \item [{\ttfamily mpi\_scatter} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_send expr] \item [{\ttfamily mpi\_send} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_sendrecv expr] \item [{\ttfamily mpi\_sendrecv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_test expr] \item [{\ttfamily mpi\_test} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [mpi\_wait expr] \item [{\ttfamily mpi\_wait} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [msd expr] \item [{\ttfamily msd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [native!-address expr] \item [{\ttfamily native!-address} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [native!-getv expr] \item [{\ttfamily native!-getv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [native!-putv expr] \item [{\ttfamily native!-putv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [native!-type expr] \item [{\ttfamily native!-type} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [nconc expr] \item [{\ttfamily nconc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ncons expr] \item [{\ttfamily ncons} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [neq expr] \item [{\ttfamily neq} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [noisy!-setq fexpr] \item [{\ttfamily noisy!-setq} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [not expr] \item [{\ttfamily not} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [nreverse expr] \item [{\ttfamily nreverse} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [null expr] \item [{\ttfamily null} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [numberp expr] \item [{\ttfamily numberp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [oblist expr] \item [{\ttfamily oblist} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [oddp expr] \item [{\ttfamily oddp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [oem!-supervisor expr] \item [{\ttfamily oem!-supervisor} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [onep expr] \item [{\ttfamily onep} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [open expr] \item [{\ttfamily open} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [open!-library expr] \item [{\ttfamily open!-library} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [open!-url expr] \item [{\ttfamily open!-url} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [or fexpr] \item [{\ttfamily or} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [orderp expr] \item [{\ttfamily orderp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ordp expr] \item [{\ttfamily ordp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [output!-library fexpr] \item [{\ttfamily output!-library} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [pagelength expr] \item [{\ttfamily pagelength} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [pair expr] \item [{\ttfamily pair} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [pairp expr] \item [{\ttfamily pairp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [parallel expr] \item [{\ttfamily parallel} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [peekch expr] \item [{\ttfamily peekch} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [pipe!-open expr] \item [{\ttfamily pipe!-open} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [plist expr] \item [{\ttfamily plist} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [plus fexpr] \item [{\ttfamily plus} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [plus2 expr] \item [{\ttfamily plus2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [plusp expr] \item [{\ttfamily plusp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [posn expr] \item [{\ttfamily posn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [preserve expr] \item [{\ttfamily preserve} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prettyprint expr] \item [{\ttfamily prettyprint} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prin expr] \item [{\ttfamily prin} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prin1 expr] \item [{\ttfamily prin1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prin2 expr] \item [{\ttfamily prin2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prin2a expr] \item [{\ttfamily prin2a} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prinbinary expr] \item [{\ttfamily prinbinary} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [princ expr] \item [{\ttfamily princ} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [princ!-downcase expr] \item [{\ttfamily princ!-downcase} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [princ!-upcase expr] \item [{\ttfamily princ!-upcase} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [princl expr] \item [{\ttfamily princl} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prinhex expr] \item [{\ttfamily prinhex} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prinl expr] \item [{\ttfamily prinl} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prinoctal expr] \item [{\ttfamily prinoctal} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prinraw expr] \item [{\ttfamily prinraw} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [print expr] \item [{\ttfamily print} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [print!-config!-header expr] \item [{\ttfamily print!-config!-header} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [print!-csl!-headers expr] \item [{\ttfamily print!-csl!-headers} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [print!-imports expr] \item [{\ttfamily print!-imports} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [printc expr] \item [{\ttfamily printc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [printcl expr] \item [{\ttfamily printcl} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [printl expr] \item [{\ttfamily printl} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [printprompt expr] \item [{\ttfamily printprompt} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [prog fexpr] \item [{\ttfamily prog} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [prog1 fexpr] \item [{\ttfamily prog1} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [prog2 fexpr] \item [{\ttfamily prog2} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [progn fexpr] \item [{\ttfamily progn} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [protect!-symbols expr] \item [{\ttfamily protect!-symbols} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [protected!-symbol!-warn expr] \item [{\ttfamily protected!-symbol!-warn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [psetq macro] \item [{\ttfamily psetq} {\itshape macro}] ~\newline
 * Not yet written
 */

/* fns [put expr] \item [{\ttfamily put} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [putc expr] \item [{\ttfamily putc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [putd expr] \item [{\ttfamily putd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [puthash expr] \item [{\ttfamily puthash} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [putv expr] \item [{\ttfamily putv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [putv!-char expr] \item [{\ttfamily putv!-char} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [putv16 expr] \item [{\ttfamily putv16} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [putv32 expr] \item [{\ttfamily putv32} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [putv8 expr] \item [{\ttfamily putv8} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [qcaar expr] \item [{\ttfamily qcaar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [qcadr expr] \item [{\ttfamily qcadr} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [qcar expr] \item [{\ttfamily qcar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [qcdar expr] \item [{\ttfamily qcdar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [qcddr expr] \item [{\ttfamily qcddr} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [qcdr expr] \item [{\ttfamily qcdr} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [qgetv expr] \item [{\ttfamily qgetv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [qputv expr] \item [{\ttfamily qputv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [quote fexpr] \item [{\ttfamily quote} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [quotient expr] \item [{\ttfamily quotient} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [random!-fixnum expr] \item [{\ttfamily random!-fixnum} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [random!-number expr] \item [{\ttfamily random!-number} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [rassoc expr] \item [{\ttfamily rassoc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [rational expr] \item [{\ttfamily rational} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [rdf expr] \item [{\ttfamily rdf} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [rds expr] \item [{\ttfamily rds} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [read expr] \item [{\ttfamily read} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [readb expr] \item [{\ttfamily readb} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [readch expr] \item [{\ttfamily readch} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [readline expr] \item [{\ttfamily readline} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [reclaim expr] \item [{\ttfamily reclaim} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [remainder expr] \item [{\ttfamily remainder} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [remd expr] \item [{\ttfamily remd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [remflag expr] \item [{\ttfamily remflag} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [remhash expr] \item [{\ttfamily remhash} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [remob expr] \item [{\ttfamily remob} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [remprop expr] \item [{\ttfamily remprop} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [rename!-file expr] \item [{\ttfamily rename!-file} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [representation expr] \item [{\ttfamily representation} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [resource!-exceeded expr] \item [{\ttfamily resource!-exceeded} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [resource!-limit expr] \item [{\ttfamily resource!-limit} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [restart!-csl expr] \item [{\ttfamily restart!-csl} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [restore!-c!-code expr] \item [{\ttfamily restore!-c!-code} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [return fexpr] \item [{\ttfamily return} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [reverse expr] \item [{\ttfamily reverse} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [reversip expr] \item [{\ttfamily reversip} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [round expr] \item [{\ttfamily round} {\itshape  expr}] ~\newline
 * Not yet written
 */


/* fns [rplacw expr] \item [{\ttfamily rplacw} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [rseek expr] \item [{\ttfamily rseek} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [rtell expr] \item [{\ttfamily rtell} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:blankcount macro] \item [{\ttfamily s!:blankcount} {\itshape macro}] ~\newline
 * Not yet written
 */

/* fns [s!:blanklist macro] \item [{\ttfamily s!:blanklist} {\itshape macro}] ~\newline
 * Not yet written
 */

/* fns [s!:blankp macro] \item [{\ttfamily s!:blankp} {\itshape macro}] ~\newline
 * Not yet written
 */

/* fns [s!:depth macro] \item [{\ttfamily s!:depth} {\itshape macro}] ~\newline
 * Not yet written
 */

/* fns [s!:do!-bindings expr] \item [{\ttfamily s!:do!-bindings} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:do!-endtest expr] \item [{\ttfamily s!:do!-endtest} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:do!-result expr] \item [{\ttfamily s!:do!-result} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:do!-updates expr] \item [{\ttfamily s!:do!-updates} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:endlist expr] \item [{\ttfamily s!:endlist} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:expand!-do expr] \item [{\ttfamily s!:expand!-do} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:expand!-dolist expr] \item [{\ttfamily s!:expand!-dolist} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:expand!-dotimes expr] \item [{\ttfamily s!:expand!-dotimes} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:explodes expr] \item [{\ttfamily s!:explodes} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:finishpending expr] \item [{\ttfamily s!:finishpending} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:format expr] \item [{\ttfamily s!:format} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:indenting macro] \item [{\ttfamily s!:indenting} {\itshape macro}] ~\newline
 * Not yet written
 */

/* fns [s!:make!-psetq!-assignments expr] \item [{\ttfamily s!:make!-psetq!-assignments} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:make!-psetq!-bindings expr] \item [{\ttfamily s!:make!-psetq!-bindings} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:make!-psetq!-vars expr] \item [{\ttfamily s!:make!-psetq!-vars} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:newframe macro] \item [{\ttfamily s!:newframe} {\itshape macro}] ~\newline
 * Not yet written
 */

/* fns [s!:oblist expr] \item [{\ttfamily s!:oblist} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:oblist1 expr] \item [{\ttfamily s!:oblist1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:overflow expr] \item [{\ttfamily s!:overflow} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:prindent expr] \item [{\ttfamily s!:prindent} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:prinl0 expr] \item [{\ttfamily s!:prinl0} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:prinl1 expr] \item [{\ttfamily s!:prinl1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:prinl2 expr] \item [{\ttfamily s!:prinl2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:prvector expr] \item [{\ttfamily s!:prvector} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:putblank expr] \item [{\ttfamily s!:putblank} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:putch expr] \item [{\ttfamily s!:putch} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:quotep expr] \item [{\ttfamily s!:quotep} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:setblankcount macro] \item [{\ttfamily s!:setblankcount} {\itshape macro}] ~\newline
 * Not yet written
 */


/* fns [s!:setblanklist macro] \item [{\ttfamily s!:setblanklist} {\itshape macro}] ~\newline
 * Not yet written
 */


/* fns [s!:setindenting macro] \item [{\ttfamily s!:setindenting} {\itshape macro}] ~\newline
 * Not yet written
 */


/* fns [s!:stamp expr] \item [{\ttfamily s!:stamp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [s!:top macro] \item [{\ttfamily s!:top} {\itshape macro}] ~\newline
 * Not yet written
 */


/* fns [safe!-fp!-pl expr] \item [{\ttfamily safe!-fp!-pl} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [safe!-fp!-pl0 expr] \item [{\ttfamily safe!-fp!-pl0} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [safe!-fp!-plus expr] \item [{\ttfamily safe!-fp!-plus} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [safe!-fp!-quot expr] \item [{\ttfamily safe!-fp!-quot} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [safe!-fp!-times expr] \item [{\ttfamily safe!-fp!-times} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sample expr] \item [{\ttfamily sample} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sassoc expr] \item [{\ttfamily sassoc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [schar expr] \item [{\ttfamily schar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [scharn expr] \item [{\ttfamily scharn} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sec expr] \item [{\ttfamily sec} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [secd expr] \item [{\ttfamily secd} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sech expr] \item [{\ttfamily sech} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [seprp expr] \item [{\ttfamily seprp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [set expr] \item [{\ttfamily set} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [set!-autoload expr] \item [{\ttfamily set!-autoload} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [set!-help!-file expr] \item [{\ttfamily set!-help!-file} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [set!-print!-precision expr] \item [{\ttfamily set!-print!-precision} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [set!-small!-modulus expr] \item [{\ttfamily set!-small!-modulus} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [setpchar expr] \item [{\ttfamily setpchar} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [setq fexpr] \item [{\ttfamily setq} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [silent!-system expr] \item [{\ttfamily silent!-system} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [simple!-string!-p expr] \item [{\ttfamily simple!-string!-p} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [simple!-vector!-p expr] \item [{\ttfamily simple!-vector!-p} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sin expr] \item [{\ttfamily sin} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sind expr] \item [{\ttfamily sind} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sinh expr] \item [{\ttfamily sinh} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [smemq expr] \item [{\ttfamily smemq} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sort expr] \item [{\ttfamily sort} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sortip expr] \item [{\ttfamily sortip} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [spaces expr] \item [{\ttfamily spaces} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [special!-char expr] \item [{\ttfamily special!-char} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [special!-form!-p expr] \item [{\ttfamily special!-form!-p} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [spool expr] \item [{\ttfamily spool} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sqrt expr] \item [{\ttfamily sqrt} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [stable!-sort expr] \item [{\ttfamily stable!-sort} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [stable!-sortip expr] \item [{\ttfamily stable!-sortip} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [start!-module expr] \item [{\ttfamily start!-module} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [startup!-banner expr] \item [{\ttfamily startup!-banner} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [stop expr] \item [{\ttfamily stop} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [streamp expr] \item [{\ttfamily streamp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [stringp expr] \item [{\ttfamily stringp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sub1 expr] \item [{\ttfamily sub1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [subla expr] \item [{\ttfamily subla} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sublis expr] \item [{\ttfamily sublis} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [subst expr] \item [{\ttfamily subst} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [superprinm expr] \item [{\ttfamily superprinm} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [superprintm expr] \item [{\ttfamily superprintm} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [sxhash expr] \item [{\ttfamily sxhash} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-argcode expr] \item [{\ttfamily symbol!-argcode} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-argcount expr] \item [{\ttfamily symbol!-argcount} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-env expr] \item [{\ttfamily symbol!-env} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-fastgets expr] \item [{\ttfamily symbol!-fastgets} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-fn!-cell expr] \item [{\ttfamily symbol!-fn!-cell} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-function expr] \item [{\ttfamily symbol!-function} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-make!-fastget expr] \item [{\ttfamily symbol!-make!-fastget} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-name expr] \item [{\ttfamily symbol!-name} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-protect expr] \item [{\ttfamily symbol!-protect} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-restore!-fns expr] \item [{\ttfamily symbol!-restore!-fns} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-set!-definition expr] \item [{\ttfamily symbol!-set!-definition} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-set!-env expr] \item [{\ttfamily symbol!-set!-env} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-set!-native expr] \item [{\ttfamily symbol!-set!-native} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbol!-value expr] \item [{\ttfamily symbol!-value} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [symbolp expr] \item [{\ttfamily symbolp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [system expr] \item [{\ttfamily system} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [tagbody fexpr] \item [{\ttfamily tagbody} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [tan expr] \item [{\ttfamily tan} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [tand expr] \item [{\ttfamily tand} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [tanh expr] \item [{\ttfamily tanh} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [terpri expr] \item [{\ttfamily terpri} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [threevectorp expr] \item [{\ttfamily threevectorp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [throw fexpr] \item [{\ttfamily throw} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [time expr] \item [{\ttfamily time} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [times fexpr] \item [{\ttfamily times} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [times2 expr] \item [{\ttfamily times2} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [tmpnam expr] \item [{\ttfamily tmpnam} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [trace expr] \item [{\ttfamily trace} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [trace!-all expr] \item [{\ttfamily trace!-all} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [traceset expr] \item [{\ttfamily traceset} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [traceset1 expr] \item [{\ttfamily traceset1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [truename expr] \item [{\ttfamily truename} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [truncate expr] \item [{\ttfamily truncate} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [ttab expr] \item [{\ttfamily ttab} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [tyo expr] \item [{\ttfamily tyo} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [undouble!-execute expr] \item [{\ttfamily undouble!-execute} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [unfluid expr] \item [{\ttfamily unfluid} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [unglobal expr] \item [{\ttfamily unglobal} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [union expr] \item [{\ttfamily union} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [unless fexpr] \item [{\ttfamily unless} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [unmake!-global expr] \item [{\ttfamily unmake!-global} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [unmake!-special expr] \item [{\ttfamily unmake!-special} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [unreadch expr] \item [{\ttfamily unreadch} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [untrace expr] \item [{\ttfamily untrace} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [untraceset expr] \item [{\ttfamily untraceset} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [untraceset1 expr] \item [{\ttfamily untraceset1} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [unwind!-protect fexpr] \item [{\ttfamily unwind!-protect} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [upbv expr] \item [{\ttfamily upbv} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [user!-homedir!-pathname expr] \item [{\ttfamily user!-homedir!-pathname} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [vectorp expr] \item [{\ttfamily vectorp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [verbos expr] \item [{\ttfamily verbos} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [when fexpr] \item [{\ttfamily when} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/* fns [where!-was!-that expr] \item [{\ttfamily where!-was!-that} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [window!-heading expr] \item [{\ttfamily window!-heading} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [writable!-libraryp expr] \item [{\ttfamily writable!-libraryp} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [write!-module expr] \item [{\ttfamily write!-module} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [wrs expr] \item [{\ttfamily wrs} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [xassoc expr] \item [{\ttfamily xassoc} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [xcons expr] \item [{\ttfamily xcons} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [xdifference expr] \item [{\ttfamily xdifference} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [xtab expr] \item [{\ttfamily xtab} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* fns [zerop expr] \item [{\ttfamily zerop} {\itshape  expr}] ~\newline
 * Not yet written
 */

/*! fns [~block]  \item [{\ttfamily !$\sim$block} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/*! fns [~let]  \item [{\ttfamily !$\sim$let} {\itshape  fexpr}] ~\newline
 * Not yet written
 */

/*! fns [~tyi]  \item [{\ttfamily !$\sim$tyi} {\itshape  expr}] ~\newline
 * Not yet written
 */

/* end of tempdoc.c */
