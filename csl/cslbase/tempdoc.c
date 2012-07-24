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

/* Signature: 67864428 19-Feb-2012 */


/*
 * This file is where I have dumped existing fragments of description,
 * but as you can imagine this is merely a temporary location - the comments
 * here need fleshing out and distributing to sit next to the things
 * they refer to. I do not know if this strategy will lead me to getting
 * full documentation but at least it might prod me into making SOME progress!
 * If somebody would like to volunteer even just to move comments to the
 * correct place that would be nice!
 */

/*
 * Any file containing documentation needs an annotation with three
 * exclamation marks noting what product it is documenting.
 */

/*!!! csl
 */

/*! predef [*applyhook] \item [{\ttfamily !*applyhook!*}] \index{{\ttfamily "!*applyhook"!*}} ~\newline
 * If this is set it might be supposed to be the name of a function used
 * by the interpreter as a callback, but at present it does not actually do
 * anything!
 */

/*! predef [*break-loop*] \item [{\ttfamily !*break!-loop!*}] \index{{\ttfamily "!*break"!-loop"!*}} ~\newline
 * If the value of this is a symbol that is defined as a function of one
 * argument then it is called during the processing on an error. This has not
 * been used in anger and so its whole status may be dubious!
 */

/*! predef [*carcheckflag] \item [{\ttfamily !*carcheckflag}] \index{{\ttfamily "!*carcheckflag}} ~\newline
 * In general CSL arranges that every {\ttfamily car} or {\ttfamily cdr} access
 * is checked for validity. Once upon a time setting this variable to nil
 * turned such checks off in the hope of gaining a little speed. But it no
 * longer does that. It may have a minor effect on array access primitives.
 */

/*! predef [*comp] \item [{\ttfamily !*comp}] \index{{\ttfamily "!*comp}} ~\newline
 * When set each function is compiled (into bytecodes) as it gets defined.
 */

/*! predef [*debug-io*] \item [{\ttfamily !*debug!-io!*}] \index{{\ttfamily "!*debug"!-io"!*}} ~\newline
 * An I/O channel intended to be used for diagnostic interactions. The concept
 * and name is taken from Common Lisp, but there is in fact no real separation
 * between this and the standard input and output streams.
 */

/*! predef [*echo] \item [{\ttfamily !*echo}] \index{{\ttfamily "!*echo}} ~\newline
 * When this is non-nil characters that are read from an input file are
 * echoed to the standard output. This gives a more comlete transcript in
 * a log file, but can sometimes amount to over-verbose output.
 */

/*! predef [*error-messages*] \item [{\ttfamily !*error!-messages!*}] \index{{\ttfamily "!*error"!-messages"!*}} ~\newline
 * Has the value nil and does not do anything! At one stage the idea had been
 * that CSL's error messages would be in this table so as to be available
 * from Lisp, but that never happened.
 */

/*! predef [*error-output*] \item [{\ttfamily !*error!-output!*}] \index{{\ttfamily "!*error"!-output"!*}} ~\newline
 * An I/O channel intended for diagnostic output. The concept comes from
 * Common Lisp but Standard Lisp (and hence CSL) does not really exploit it.
 */

/*! predef [*evalhook] \item [{\ttfamily !*evalhook!*}] \index{{\ttfamily "!*evalhook"!*}} ~\newline
 * See {\ttfamily !*applyhook!*}. This also does not do anything at present,
 * but it it did it would be a place to put the name of a function that
 * would be called by the interpreter when applying a function.
 */

/*! predef [*gchook*] \item [{\ttfamily !*gc!-hook!*}] \index{{\ttfamily "!*gc"!-hook"!*}} ~\newline
 * If this is set to have as its value that is a function of one argument then
 * that function is called with {\ttfamily nil} on every minor entry to the
 * garbage collection, and with argument {\ttfamily t} at the end of a ``genuine''
 * full garbage collection. This may sometimes be of interest for those who
 * want to notice when garbage collection happens but want to control how
 * they are informed rather than relying on the displayed text that the
 * {\ttfamily verbos} function controls.
 */

/*! predef [*hanaku] \item [{\ttfamily !*hankaku}] \index{{\ttfamily "!*hankaku}} ~\newline
 * This was concerned with internationalisation to support a Japanese
 * locale but has not been activated for some while. In the fullness of time I
 * hope to migrate CSL to use an UTF8 representation of Unicode characters
 * internally, but that upgrade is at present an ideal and a project not
 * a reality. Volunteers to help welcome!
 */

/*! predef [*lower] \item [{\ttfamily !*lower}] \index{{\ttfamily "!*lower}} ~\newline
 * In CSL if the fluid variable {\ttfamily !*lower} is set (which it is
 * by default) then when characters are read they are folded to lower case.
 * The related variable {\ttfamily !*raise} causes input to be folded to
 * upper case on input. In the original Standard Lisp the true internal names
 * of all functions were in upper case, and {\ttfamily !*raise} was used so
 * that code using it could be written in mixed or lower case. At some stage
 * it was accepted that upper case was a throw-back to the days of FORTRAN
 * and punched cards, so the CSL switched to using lower case
 * internally and the {\ttfamily !*lower} flag allowed the existing Reduce
 * sources to survive. At some time in the future I hope that Reduce will
 * arrange to have both {\ttfamily *raise} and {\ttfamily !*lower} set to
 * {\ttfamily nil} so that it becomes a case-sensitive system.
 *
 * Note that the PSL Lisp system once (but not now) used {\ttfamily !*lower}
 * to cause internally upper case symbols to be printed in lower case,
 * so that there it is a control of output rather than input case folding.
 * PSL has functions {\ttfamily input!-case} and {\ttfamily output!-case}
 * that are relevant in this respect.
 * So code that is to be portable between the two Lisps needs to take care.
 */

/*! predef [*macroexpand-hook*] \item [{\ttfamily !*macroexpand!-hook!*}] \index{{\ttfamily "!*macroexpand"!-hook"!*}} ~\newline
 * Common Lisp would like it to be possible to specify a function that would
 * be called to allow overriding of the normal method of expanding macros. This
 * variable exists in CSL in case at any stage a serious need for this
 * capability arises, but at present any use of this variable has no effect.
 */

/*! predef [*math-output*] \item [{\ttfamily !*math!-output!*}] \index{{\ttfamily "!*math"!-output"!*}} ~\newline
 * In the case that CSL is being used with Reduce and its ``fancy'' maths mode
 * display is available in a GUI then this provides a special output
 * stream that displayable layout information in a {\TeX}-like notation that
 * is not documented here because it is potentially in the process of being
 * updated. The {\ttfamily tmprint} package in Reduce generates this
 * material and collaborates with the mathematical display parts of CSL.
 */

/*! predef [*native_code] \item [{\ttfamily !*native\_code}] \index{{\ttfamily "!*native\_code}} ~\newline
 * An experimental additional compiler for CSL that maps Lisp directly onto
 * native code for the current platform has been in development for some time,
 * but it is not in a state such as to make it useful for other than
 * people who wish to experiment, extend and debug it. This flag is to do
 * with enabling it. It is not supported but may possibly become so one day.
 */

/*! predef [*notailcall] \item [{\ttfamily !*notailcall}] \index{{\ttfamily "!*notailcall}} ~\newline
 * The CSL compiler normally tries to detect patterns of recursion that it
 * can convert into iteration. This can dramatically reduce stack use and
 * so allow calculations to succeed when otherwise they would have failed.
 * This flag can disable that optimisation. The most plausible reason to
 * want to do that would be if there was serious cause to believe that the
 * code performorming the optimisation was faulty, and results without it were
 * needed as part of the process of tracking down the bug.
 */

/*! predef [*package*] \item [{\ttfamily !*package!*}] \index{{\ttfamily "!*package"!*}} ~\newline
 * Interrnally CSL stores the table that maps names into symbols in a way
 * following the style of the Common Lisp package system. When used as
 * a Standard Lisp there is only one package and no distinction between
 * internal and external name visibility, but this name provides access to
 * the main tdata-structure involved. It is in general expected that this
 * will be used via the {\ttfamily oblist} function, not directly be users.
 */

/*! predef [*pgwd] \item [{\ttfamily !*pgwd}] \index{{\ttfamily "!*pgwd}} ~\newline
 * See {\ttfamily !*plap}.
 */

/*! predef [*plap] \item [{\ttfamily !*plap}] \index{{\ttfamily "!*plap}} ~\newline
 * When the CSL compiler runs to generate byte-codes if {\ttfamily !*plap} or
 * {\ttfamily !*pgwd} is set then the generated code is displayed. This may
 * be of interest when debugging or for anybody who wants to explore the
 * Lisp bytecode model that is used. If at some stage a full native compiler
 * is released then {\ttfamily !*plap} will control display of any intermediate
 * Lisp-specific material and {\ttfamily !*pgwd} will control display of the
 * final generated platform dependent machine code.
 */

/*! predef [*pretty-symmetric] \item [{\ttfamily !*pretty!-symmetric}] \index{{\ttfamily "!*pretty"!-symmetric}} ~\newline
 * The {\ttfamily prettyprint} function displays a Lisp expression neatly
 * indended. If this variable is set (which by default it is) symbols and
 * strings are shown with escape characters and quotation marks so that the
 * indented form could be re-input. If this variable is set to {\ttfamily nil}
 * that does not happen -- the output may not be re-readable by CSL but in
 * some cases it may be easier for a human reader to decipher.
 */

/*! predef [*prinl-fn!*] \item [{\ttfamily !*prinl!-fn!*}] \index{{\ttfamily "!*prinl"!-fn"!*}} ~\newline
 * Used internally by the functions {\ttfamily prinl} and {\ttfamily princl}
 * that can print data structures that are re-entrant or looped. Not for use
 * by end-users.
 */

/*! predef [*prinl-index] \item [{\ttfamily !*prinl!-index!*}] \index{{\ttfamily "!*prinl"!-index"!*}} ~\newline
 * Used internally by the functions {\ttfamily prinl} and {\ttfamily princl}
 * that can print data structures that are re-entrant or looped. Not for use
 * by end-users.
 */

/*! predef [*prinl-visited-nodes*] \item [{\ttfamily !*prinl!-visited!-nodes!*}] \index{{\ttfamily "!*prinl"!-visited"!-nodes"!*}} ~\newline
 * Used internally by the functions {\ttfamily prinl} and {\ttfamily princl}
 * that can print data structures that are re-entrant or looped. Not for use
 * by end-users.
 */

/*! predef [*print-array*] \item [{\ttfamily !*print!-array!*}] \index{{\ttfamily "!*print"!-array"!*}} ~\newline
 * In {\ttfamily prinl} if this variable is {\ttfamily nil} arrays and
 * structures are not printed in full. In some cases this merely loses valuable
 * information, while in others it leads to output that is more concise and
 * legible and hence nore useful.
 */

/*! predef [*print-length*] \item [{\ttfamily !*print!-length!*}] \index{{\ttfamily "!*print"!-length"!*}} ~\newline
 * In {\ttfamily prinl} if this variable is set to an integer then that specifies
 * the largest number of items in a list that will be displayed.
 */

/*! predef [*print-level*] \item [{\ttfamily !*print!-level!*}] \index{{\ttfamily "!*print"!-level"!*}} ~\newline
 * In {\ttfamily prinl} if this variable is set to an integer then that specifies
 * the greatest depth of nesting of lists before the printing gives up. This
 * and {\ttfamily !*print!-length!*} may very occasionally be useful when
 * faced with huge lists of whihc only the top few layers are relevant.
 */

/*! predef [*pwrds] \item [{\ttfamily !*pwrds}] \index{{\ttfamily "!*pwrds}} ~\newline
 * This is normally set, and it causes the compiler to display a message
 * commenting on how many bytes were used in the compiled version of each
 * function that is processed.
 */

/*! predef [*query-io*] \item [{\ttfamily !*query!-io!*}] \index{{\ttfamily "!*query"!-io"!*}} ~\newline
 * An I/O channel intended to be used for query interactions. The concept
 * and name is taken from Common Lisp, but there is in fact no real separation
 * between this and the standard input and output streams.
 */

/*! predef [*quotes] \item [{\ttfamily !*quotes}] \index{{\ttfamily "!*quotes}} ~\newline
 * Used in the prettyprinter to determine whether the form {\ttfamily (quote x)}
 * should be displayed as {\ttfamily 'x}. By default it is.
 */

/*! predef [*raise] \item [{\ttfamily !*raise}] \index{{\ttfamily "!*raise}} ~\newline
 * See {\ttfamily !*lower}.
 */

/*! predef [*redefmsg] \item [{\ttfamily !*redefmsg}] \index{{\ttfamily "!*redefmsg}} ~\newline
 * If this is set a message is displayed when a function is redefined.
 */

/*! predef [*resources*] \item [{\ttfamily !*resources!*}] \index{{\ttfamily "!*resources"!*}} ~\newline
 * See the {\ttfamily resource!-limit} function.
 */

/*! predef [*savedef] \item [{\ttfamily !*savedef}] \index{{\ttfamily "!*savedef}} ~\newline
 * If this variable is set then when you define a function and compile it the
 * original interpratable Lisp form of the defintion is saved under the
 * property-name {\ttfamily !*savedef} so that it could be recovered using
 * {\ttfamily get}. If the function is being compiled into a fasl-file for
 * later reloading the lisp form of the definition is saved there so that when
 * {\ttfamily load!-module} or {\ttfamily load!-source} is used it can be
 * retrieved. This facility is activated when the ``bootstrap'' version of
 * Reduce is built so that in effect the full source code is available at
 * run-time. The availability of source in that way can be useful for forms
 * of global analysis or optimisation of the code -- for instance Reduce
 * uses it to find the definitions of functions that it wants to optimise
 * int C code rather than the slower (but more compact) bytecodes it uses
 * for most things.
 */

/*! predef [*spool-output*] \item [{\ttfamily !*spool!-output!*}] \index{{\ttfamily "!*spool"!-output"!*}} ~\newline
 * The {\ttfamily spool} function or the command-line option {\ttfamily -l}
 * can establish a file that normal output is copied to as a log. This variable
 * holds a handle to that file.
 */

/*! predef [*standard-input*] \item [{\ttfamily !*standard!-input!*}] \index{{\ttfamily "!*standard"!-input"!*}} ~\newline
 * Standard Lisp specifies that to select input from the ``standard'' source
 * one goes {\ttfamily (rds nil)}. In CSL this is underpinned by having an
 * input stream as stored in this variable following the naming convention used
 * by Common Lisp.
 */

/*! predef [*standard-output*] \item [{\ttfamily !*standard!-output!*}] \index{{\ttfamily "!*standard"!-output"!*}} ~\newline
 * As {\ttfamily !*standard!-input!*} but for output.
 */

/*! predef [*terminal-io*] \item [{\ttfamily !*terminal!-io!*}] \index{{\ttfamily "!*terminal"!-io"!*}} ~\newline
 * A Common Lisp motivated variable which is intended to provide access to
 * the ``terminal''. In Standard Lisp you are expected to use {\ttfamily rds}
 * and the precise concept of a terminal is not really defined.
 */

/*! predef [*trace-output*] \item [{\ttfamily !*trace!-output!*}] \index{{\ttfamily "!*trace"!-output"!*}} ~\newline
 * The Lisp trace facility tends to send output to this which is a synonym
 * for the original standard output.
 */

/*! predef [@cslbase] \item [{\ttfamily !@cslbase}] \index{{\ttfamily "!"@cslbase}} ~\newline
 * This variable is not actually predefined, but I will nevertheless give some
 * explanation of how it is used during the bootstrapping process that makes
 * a CSL or a Reduce image. When you attempt to open a file you mau give
 * a path starting with an initial ``\$word/\ldots'' or ``\$\{word\}/\ldots''.
 * these notations of course model typical Unix-style parameter substitution.
 * The expansion proceeds by first checking if a Lisp variable ``@word''
 * exists with a string or a symbol as its name. If so that value is used
 * as the expansion. If that scheme fails the system next looks for an
 * environment variable and uses its value. This the use of a Lisp variable
 * ``@word'' takes priority over the system environment. Finally if there is
 * no environment variable available a Lisp variable with name ``\$word'' is
 * checked and if its value is a string or symbol that is the expansion,
 * otherwise the expansion will be empty.
 *
 * This is used in the build sequences by passing a command-line
 * option {\ttfamily -D@cslbase=...} that predefines
 * {\ttfamily @cslbase} to refer to a key directory where necessary files
 * can be found.
 * By defining this rather than {\ttfamily \$cslbase} there is no chance that
 * any odd values in the (shell) environment will cause trouble, and the
 * lines such as {\ttfamily (rdf~"\$cslbase/compat.lsp")} can appear in the build
 * code without any need for absolute path names or any
 * reliance on the setting of a current directory.
 *
 * In a file-name a path that starts with {\ttfamily !$\sim$/} or
 * {\ttfamily !$\sim$name/} tries to identify the home directory of the
 * current or named user.
 */

/*! predef [$cslbase] \item [{\ttfamily !\$cslbase}] \index{{\ttfamily "!\$cslbase}} ~\newline
 * See {\ttfamily !@cslbase}.
 */

/*! predef [s:bn] \item [{\ttfamily s!:bn}]  ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [s:bufferi]  \item [{\ttfamily s!:bufferi}] ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [s:buffero]  \item [{\ttfamily s!:bufferp}] ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [common-lisp-mode]  \item [{\ttfamily common!-lisp!-mode}] \index{{\ttfamily common"!-lisp"!-mode}} ~\newline
 * The CSL Lisp system was designed so that if necessary much of the code could
 * be shared with a version that met the Common Lisp Standard. At no stage has
 * there been anything like a complete Common version. This is both because the
 * main use of CSL has been to support Reduce and that wants Standard (not
 * Common) Lisp, and because providing complete support for all the
 * functionality in Common Lisp would be a lot of work and would tend to make
 * the code bulkier (and hence necessarily less reliable) and slower. However
 * various key underpinnings for Common Lisp are present in the C-coded sources,
 * generally guarded by ``{\ttfamily \#ifdef COMMON}''. If the Lisp has been
 * built in this way then this variable will be set in order that users can
 * readily detect the situation.  At one stage the Axiom algebra system could
 * be built using the limited Common Lisp compatibility mode, but the recent
 * Open Source versions of Axiom have probably changed leaving that not an
 * easy option.
 */

/*! predef [crbuf*]  \item [{\ttfamily crbuf!*}] \index{{\ttfamily crbuf"!*}} ~\newline
 * This is a variable used by the Reduce parser, and as a matter of caution it
 * is to be treated as reserved in the Lisp system. 
 */

/*! predef [emsg*]  \item [{\ttfamily emsg!*}] \index{{\ttfamily emsg"!*}} ~\newline
 * After a call {\ttfamily (error nn msg)} this variable gets set to the
 * value of the second argument ({\ttfamily msg}). This may help if you have had
 * a failure and want to see if it resulted from a call to the {\ttfamily error}
 * function and if so what message had been used with it!
 */

/*! predef [eof*]  \item [{\ttfamily eof!*}] \index{{\ttfamily eof"!*}} ~\newline
 * Used in Reduce in association with detecting and handling end-of-file
 * conditions, and reserved in the Lisp to avoid potential interference with
 * that.
 */

/*! predef [s:indblanks]  \item [{\ttfamily s!:indblanks}]  ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [s:indentlevel]  \item [{\ttfamily s!:indentlevel}] ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [s:initialblanls]  \item [{\ttfamily s!:initialblanks}] ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [lispsystem*]  \item [{\ttfamily lispsystem!*}] \index{{\ttfamily lispsystem"!*}} ~\newline
 * This variable is initialised at the start of any run of Lisp to hold
 * information about the computer in use and the collection of features
 * available in the Lisp. The items that might be present are explained
 * further in Section \ref{lispsys}.
 */

/*! predef [s:lmar]  \item [{\ttfamily s!:lmar}] ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [load-source]  \item [{\ttfamily load!-source}] \index{{\ttfamily load"!-source}} ~\newline
 * The function {\ttfamily load!-source} will load data from a fasl file
 * and is intended to make it possible to have saved uncompiled Lisp forms
 * for functions there -- and to be able to reload then in a selective
 * way. The {\ttfamily load!-source} variable can tune this behaviour. See the
 * explanation of the function for further details.
 */

/*! predef [nil]  \item [{\ttfamily nil}] \index{{\ttfamily nil}} ~\newline
 * {\ttfamily nil} is the fundamental Lisp atom used to stand for ``false'',
 * used to terminate lists and generally something that every Lisp programmer
 * will already understand about. In Standard Lisp {\ttfamily nil} is a
 * symbol and as such you may not take {\ttfamily car} or {\ttfamily cdr} of
 * it. So any code that had been developed for Common Lisp and relies on being
 * able to treat it as if it was a non-empty list will need revision. CSL
 * always checks for valid access so not only would {\ttfamily (car~nil)} be
 * a mistake,  but any attempt to do it will lead to an exception being
 * raised. {\ttfamily nil} must not be used as a name of an argument or a
 * {\ttfamily prog} variable or in any other context that could attempt to
 * alter its value.
 */

/*! predef [ofl*]  \item [{\ttfamily ofl!*}] \index{{\ttfamily ofl"!*}} ~\newline
 * Used in Reduce in association with tracking output files, and reserved in
 * CSL to avoid conflict with that.
 */

/*! predef [s:pendingrpars]  \item [{\ttfamily s!:pendingrpars}] ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [program*]  \item [{\ttfamily program!*}] \index{{\ttfamily program"!*}} ~\newline
 * Used by the Reduce parser to hold a command that has just been parsed, and
 * reserved in CSL in order to ensure that there is no conflict with that.
 */

/*! predef [s:rmar]  \item [{\ttfamily s!:rmar}] ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [s:rparcount]  \item [{\ttfamily s!:rparcount}] ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [s:gensym-serial]  \item [{\ttfamily s!:gensym!-serial}] \index{{\ttfamily s"!:gensym"!-serial}} ~\newline
 * internal variable used by {\ttfamily dated!-name}.
 */

/*! predef [s:stack]  \item [{\ttfamily s!:stack}] ~\newline
 * Used internally by the prettyprint function.
 */

/*! predef [t]  \item [{\ttfamily t}] \index{{\ttfamily t}} ~\newline
 * The Lisp value that stands for ``true''. Any attempt to reset or
 * rebind {\ttfamily t} will be an error. The value of {\ttfamily t} is
 * itself. Yoy may recall that in Lisp 1.5 the value of {\ttfamily t}
 * had been {\ttfamily *t*}, but Standard Lisp mandates the behaviour
 * implemented here. As far as truth values are concerned, {\ttfamily nil}
 * is treated as meaning ``false'' and anything that is non-{\ttfamily nil}
 * is true, including as an obvious special case {\ttfamily t}.
 */

/*! predef [thin*]  \item [{\ttfamily thin!*}] \index{{\ttfamily thin"!*}} ~\newline
 * In the prettyprinter if {\ttfamily thin!*} values (default 5) can be
 * fitted on a single line. The idea behind this is so that long lists can
 * in relevant cases be displayed almost horizontalloy rather than
 * vertically, as in
 * {\footnotesize\begin{verbatim}
 *   (one two three four five             (one 
 *    six seven eight nine ten   vs.       two
 *    eleven twelve)                       three
 *                                         ...
 * \end{verbatim}}
 */

/*! predef [ttype*]  \item [{\ttfamily ttype!*}] \index{{\ttfamily ttype"!*}} ~\newline
 * Used by the Reduce parser, and so best not used for other purposes.
 */

/*! flags [s:ppchar]  \item [{\ttfamily s!:ppchar} and {\ttfamily s!:ppformat}] \index{{\ttfamily s"!:ppchar} and {\ttfamily s!:ppformat}}
 * These are used in the prettyprint code found in {\ttfamily extras.red}. A
 * name is given a property {\ttfamily s!:ppformat} if in prettyprinted display
 * its first few arguments should appear on the same line as it if at all
 * possible. The {\ttfamily s!:ppchar} property is used to make the display of
 * bracket characters a little more tidy in the source code.
 */

/*! flags [switch]  \item [{\ttfamily switch}] \index{{\ttfamily switch}}
 * In the Reduce parser some names are ``switches'', and then directives such
 * as {\ttfamily on xxx} and {\ttfamily off xx} have the effect of setting or
 * clearing the value of a variable {\ttfamily !*xxx}. This is managed by
 * setting the {\ttfamily switch} flag om {\ttfamily xxx}. CSL sets some
 * things as switches ready for when they may be used by the Reduce parser.
 */

/*! flags [lose]  \item [{\ttfamily lose}] \index{{\ttfamily lose}}
 * If a name is flagged as {ttfamily lose} then a subsequent attempt to
 * define or redefine it will be ignored.
 */

/*! flags [~magic-internal-symbol~]  \item [{\ttfamily !$\sim$magic!-internal!-symbol!$\sim$}] \index{{\ttfamily "!$\sim$magic"!-internal"!-symbol"!$\sim$}}
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

/*! fns [~~~~~~~~]  \end{description} % end of fns section [tempdoc.c]
 */

/*! fns [abs]  \item [{\ttfamily abs} {\itshape  expr}] \index{{\ttfamily abs} {\itshape  expr}} ~\newline
 * This takes one argument that should be a number -- and returns its absolute
 * value. In Common Lisp mode it would find the magnitude of a complex
 * number, but in normal Standard Lisp mode the only cases that arise are
 * integers are floating point values.
 */

/* fns [acons expr] \item [{\ttfamily acons} {\itshape  expr}] \index{{\ttfamily acons} {\itshape  expr}} ~\newline
 * {\ttfamily (acons a b c)} = {\ttfamily (cons (cons a b) x)}. The name
 * arises because this may be used to add a new key-value pair on the
 * front of an association list. Use of {\ttfamily acons} may be just
 * marginally faster than using the two simple uses of {\ttfamily cons}
 * that it stands for.
 */

/* fns [acos expr] \item [{\ttfamily acos} {\itshape  expr}] \index{{\ttfamily acos} {\itshape  expr}} ~\newline
 * Inverse or arc-cosine (working in radians). In Common Lisp mode this
 * will cope with complex numbers, but for Standard Lisp it only needs to
 * handle floating point values. Well the integers -1, 0 and 1 are also
 * accepted and are converted to -1.0, 0.0 and 1.0 before use. The result
 * (when given a real argument) will be in the range 0.0 to $\pi$.
 */

/* fns [acosd expr] \item [{\ttfamily acosd} {\itshape  expr}] \index{{\ttfamily acosd} {\itshape  expr}} ~\newline
 * The inverse cosine function (see {\ttfamily acos}) but delivering a result
 * in degrees from 0.0 to 180.0.
 */

/* fns [acosh expr] \item [{\ttfamily acosh} {\itshape  expr}] \index{{\ttfamily acosh} {\itshape  expr}} ~\newline
 * Inverse hyperbolic cosine. For the result to be real (and hence valid with
 * Standard Lisp) the argument must be at least 1.0.
 */

/* fns [acot expr] \item [{\ttfamily acot} {\itshape  expr}] \index{{\ttfamily acot} {\itshape  expr}} ~\newline
 * Inverse cotangent, expressed in radians. The result will be in the range
 * 0 to $\pi$.
 */

/* fns [acotd expr] \item [{\ttfamily acotd} {\itshape  expr}] \index{{\ttfamily acotd} {\itshape  expr}} ~\newline
 * Inverse cotangent with result in degrees, in range 0.0 to 180.0.
 */

/* fns [acoth expr] \item [{\ttfamily acoth} {\itshape  expr}] \index{{\ttfamily acoth} {\itshape  expr}} ~\newline
 * Inverse hyperbolic cotangent. The argument must not be in the range
 * $(-1.0 \ldots 1.0)$.
 */

/* fns [acsc expr] \item [{\ttfamily acsc} {\itshape  expr}] \index{{\ttfamily acsc} {\itshape  expr}} ~\newline
 * Inverse cosecant (in radians). Recall that {\fffamily (csc x)} gives the
 * reciprocal of {\ttfamily (sin x)}. Argument must be at least 1.0 in absolute
 * value and result will be in the range $- \pi/2$ to $\pi/2}.
 */

/* fns [acscd expr] \item [{\ttfamily acscd} {\itshape  expr}] \index{{\ttfamily acscd} {\itshape  expr}} ~\newline
 * Inverse cosecant in degrees.
 */

/* fns [acsch expr] \item [{\ttfamily acsch} {\itshape  expr}] \index{{\ttfamily acsch} {\itshape  expr}} ~\newline
 * Inverse hyperbolic cosecant.
 */

/* fns [add1 expr] \item [{\ttfamily add1} {\itshape  expr}] \index{{\ttfamily add1} {\itshape  expr}} ~\newline
 * This function takes one argument and adds 1 to it. If you know that you will
 * be working with a small integer you may wish to use {\ttfamily iadd1}
 * instead. {\ttfamily (add1~x)} is basically a shorthand for {\ttfamily
 * (plus~x~1)}.
 */

/* fns [and fexpr] \item [{\ttfamily and} {\itshape  fexpr}] \index{{\ttfamily and} {\itshape  fexpr}} ~\newline
 * A form {\ttfamily (and~a~b~\ldots~z)} evaluates its arguments sequentially
 * until either one returns {\ttfamily nil} or until it reaches the last.
 * It returns the last value it evaluates. This is treating the values
 * as booleans with {\ttfamily nil} standing for false and anything else for
 * true, and only doing the minimum evaluation needed to yield a result.
 * One could interpret {\ttfamily (and~a~b}} as standing for the more
 * explictly sequential evaluation {\ttfamily
 * (cond~(a~b)~(t~nil))}, with related expansions if more arguments were
 * provided. See also {\ttfamily or}.
 */

/* fns [append expr] \item [{\ttfamily append} {\itshape  expr}] \index{{\ttfamily append} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [apply expr] \item [{\ttfamily apply} {\itshape  expr}] \index{{\ttfamily apply} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [apply0 expr] \item [{\ttfamily apply0} {\itshape  expr}] \index{{\ttfamily apply0} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [apply1 expr] \item [{\ttfamily apply1} {\itshape  expr}] \index{{\ttfamily apply1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [apply2 expr] \item [{\ttfamily apply2} {\itshape  expr}] \index{{\ttfamily apply2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [apply3 expr] \item [{\ttfamily apply3} {\itshape  expr}] \index{{\ttfamily apply3} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [asec expr] \item [{\ttfamily asec} {\itshape  expr}] \index{{\ttfamily asec} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [asecd expr] \item [{\ttfamily asecd} {\itshape  expr}] \index{{\ttfamily asecd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [asech expr] \item [{\ttfamily asech} {\itshape  expr}] \index{{\ttfamily asech} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ash expr] \item [{\ttfamily ash} {\itshape  expr}] \index{{\ttfamily ash} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ash1 expr] \item [{\ttfamily ash1} {\itshape  expr}] \index{{\ttfamily ash1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [asin expr] \item [{\ttfamily asin} {\itshape  expr}] \index{{\ttfamily asin} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [asind expr] \item [{\ttfamily asind} {\itshape  expr}] \index{{\ttfamily asind} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [asinh expr] \item [{\ttfamily asinh} {\itshape  expr}] \index{{\ttfamily asinh} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [assoc expr] \item [{\ttfamily assoc} {\itshape  expr}] \index{{\ttfamily assoc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [assoc!*!* expr] \item [{\ttfamily assoc!*!*} {\itshape  expr}] \index{{\ttfamily assoc"!*"!*} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [atan expr] \item [{\ttfamily atan} {\itshape  expr}] \index{{\ttfamily atan} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [atan2 expr] \item [{\ttfamily atan2} {\itshape  expr}] \index{{\ttfamily atan2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [atan2d expr] \item [{\ttfamily atan2d} {\itshape  expr}] \index{{\ttfamily atan2d} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [atand expr] \item [{\ttfamily atand} {\itshape  expr}] \index{{\ttfamily atand} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [atanh expr] \item [{\ttfamily atanh} {\itshape  expr}] \index{{\ttfamily atanh} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [atom expr] \item [{\ttfamily atom} {\itshape  expr}] \index{{\ttfamily atom} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [atsoc expr] \item [{\ttfamily atsoc} {\itshape  expr}] \index{{\ttfamily atsoc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [batchp expr] \item [{\ttfamily batchp} {\itshape  expr}] \index{{\ttfamily batchp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_close_input]  \item [{\ttfamily binary\_close\_input} {\itshape  expr}] \index{{\ttfamily binary\_close\_input} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_close_output]  \item [{\ttfamily binary\_close\_output} {\itshape  expr}] \index{{\ttfamily binary\_close\_output} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_open_input]  \item [{\ttfamily binary\_open\_input} {\itshape  expr}] \index{{\ttfamily binary\_open\_input} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_open_output]  \item [{\ttfamily binary\_open\_output} {\itshape  expr}] \index{{\ttfamily binary\_open\_output} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_prin1]  \item [{\ttfamily binary\_prin1} {\itshape  expr}] \index{{\ttfamily binary\_prin1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_prin2]  \item [{\ttfamily binary\_prin2} {\itshape  expr}] \index{{\ttfamily binary\_prin2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_prin3]  \item [{\ttfamily binary\_prin3} {\itshape  expr}] \index{{\ttfamily binary\_prin3} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_prinbyte]  \item [{\ttfamily binary\_prinbyte} {\itshape  expr}] \index{{\ttfamily binary\_prinbyte} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_princ]  \item [{\ttfamily binary\_princ} {\itshape  expr}] \index{{\ttfamily binary\_princ} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_prinfloat]  \item [{\ttfamily binary\_prinfloat} {\itshape  expr}] \index{{\ttfamily binary\_prinfloat} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_read2]  \item [{\ttfamily binary\_read2} {\itshape  expr}] \index{{\ttfamily binary\_read2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_read3]  \item [{\ttfamily binary\_read3} {\itshape  expr}] \index{{\ttfamily binary\_read3} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_read4]  \item [{\ttfamily binary\_read4} {\itshape  expr}] \index{{\ttfamily binary\_read4} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_readbyte]  \item [{\ttfamily binary\_readbyte} {\itshape  expr}] \index{{\ttfamily binary\_readbyte} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_readfloat]  \item [{\ttfamily binary\_readfloat} {\itshape  expr}] \index{{\ttfamily binary\_readfloat} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_select_input]  \item [{\ttfamily binary\_select\_input} {\itshape  expr}] \index{{\ttfamily binary\_select\_input} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [binary_terpri]  \item [{\ttfamily binary\_terpri} {\itshape  expr}] \index{{\ttfamily binary\_terpri} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [binopen expr] \item [{\ttfamily binopen} {\itshape  expr}] \index{{\ttfamily binopen} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [boundp expr] \item [{\ttfamily boundp} {\itshape  expr}] \index{{\ttfamily boundp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [bps-getv]  \item [{\ttfamily bps!-getv} {\itshape  expr}] \index{{\ttfamily bps"!-getv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [bps-putv]  \item [{\ttfamily bps!-putv} {\itshape  expr}] \index{{\ttfamily bps"!-putv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [bps-upvb]  \item [{\ttfamily bps!-upbv} {\itshape  expr}] \index{{\ttfamily bps"!-upbv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [bpsp expr] \item [{\ttfamily bpsp} {\itshape  expr}] \index{{\ttfamily bpsp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [break-loop]  \item [{\ttfamily break!-loop} {\itshape  expr}] \index{{\ttfamily break"!-loop} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [byte!-getv expr] \item [{\ttfamily byte!-getv} {\itshape  expr}] \index{{\ttfamily byte"!-getv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [bytecounts expr] \item [{\ttfamily bytecounts} {\itshape  expr}] \index{{\ttfamily bytecounts} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [c_out]  \item [{\ttfamily c\_out} {\itshape  expr}] \index{{\ttfamily c\_out} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [carcheck expr] \item [{\ttfamily carcheck} {\itshape  expr}] \index{{\ttfamily carcheck} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [catch fexpr] \item [{\ttfamily catch} {\itshape  fexpr}] \index{{\ttfamily catch} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [cbrt expr] \item [{\ttfamily cbrt} {\itshape  expr}] \index{{\ttfamily cbrt} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ceiling expr] \item [{\ttfamily ceiling} {\itshape  expr}] \index{{\ttfamily ceiling} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [char-code]  \item [{\ttfamily char!-code} {\itshape  expr}] \index{{\ttfamily char"!-code} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [char-downcase]  \item [{\ttfamily char!-downcase} {\itshape  expr}] \index{{\ttfamily char"!-downcase} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [char-upcase]  \item [{\ttfamily char!-upcase} {\itshape  expr}] \index{{\ttfamily char"!-upcase} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [chdir expr] \item [{\ttfamily chdir} {\itshape  expr}] \index{{\ttfamily chdir} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [check-c-code]  \item [{\ttfamily check!-c!-code} {\itshape  expr}] \index{{\ttfamily check"!-c"!-code} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [checkpoint expr] \item [{\ttfamily checkpoint} {\itshape  expr}] \index{{\ttfamily checkpoint} {\itshape  expr}} ~\newline
 * A function by this name used to exist, but its functionality has now
 * been subsumed into {\ttfamily (preserve)}
 */

/*! fns [cl-equal]  \item [{\ttfamily cl!-equal} {\itshape  expr}] \index{{\ttfamily cl"!-equal} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [close expr] \item [{\ttfamily close} {\itshape  expr}] \index{{\ttfamily close} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [close-library]  \item [{\ttfamily close!-library} {\itshape  expr}] \index{{\ttfamily close"!-library} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [clrhash expr] \item [{\ttfamily clrhash} {\itshape  expr}] \index{{\ttfamily clrhash} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [code-char]  \item [{\ttfamily code!-char} {\itshape  expr}] \index{{\ttfamily code"!-char} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [codep expr] \item [{\ttfamily codep} {\itshape  expr}] \index{{\ttfamily codep} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [compile expr] \item [{\ttfamily compile} {\itshape  expr}] \index{{\ttfamily compile} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [compile-all]  \item [{\ttfamily compile!-all} {\itshape  expr}] \index{{\ttfamily compile"!-all} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [compress expr] \item [{\ttfamily compress} {\itshape  expr}] \index{{\ttfamily compress} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [cond fexpr] \item [{\ttfamily cond} {\itshape  fexpr}] \index{{\ttfamily cond} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [cons expr] \item [{\ttfamily cons} {\itshape  expr}] \index{{\ttfamily cons} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [consp expr] \item [{\ttfamily consp} {\itshape  expr}] \index{{\ttfamily consp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [constantp expr] \item [{\ttfamily constantp} {\itshape  expr}] \index{{\ttfamily constantp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [contained expr] \item [{\ttfamily contained} {\itshape  expr}] \index{{\ttfamily contained} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [convert-to-evector]  \item [{\ttfamily convert!-to!-evector} {\itshape  expr}] \index{{\ttfamily convert"!-to"!-evector} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [copy expr] \item [{\ttfamily copy} {\itshape  expr}] \index{{\ttfamily copy} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [copy-module]  \item [{\ttfamily copy!-module} {\itshape  expr}] \index{{\ttfamily copy"!-module} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [copy-native]  \item [{\ttfamily copy!-native} {\itshape  expr}] \index{{\ttfamily copy"!-native} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [cos expr] \item [{\ttfamily cos} {\itshape  expr}] \index{{\ttfamily cos} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [cosd expr] \item [{\ttfamily cosd} {\itshape  expr}] \index{{\ttfamily cosd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [cosh expr] \item [{\ttfamily cosh} {\itshape  expr}] \index{{\ttfamily cosh} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [cot expr] \item [{\ttfamily cot} {\itshape  expr}] \index{{\ttfamily cot} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [cotd expr] \item [{\ttfamily cotd} {\itshape  expr}] \index{{\ttfamily cotd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [coth expr] \item [{\ttfamily coth} {\itshape  expr}] \index{{\ttfamily coth} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [create-directory]  \item [{\ttfamily create!-directory} {\itshape  expr}] \index{{\ttfamily create"!-directory} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [csc expr] \item [{\ttfamily csc} {\itshape  expr}] \index{{\ttfamily csc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [cscd expr] \item [{\ttfamily cscd} {\itshape  expr}] \index{{\ttfamily cscd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [csch expr] \item [{\ttfamily csch} {\itshape  expr}] \index{{\ttfamily csch} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [date expr] \item [{\ttfamily date} {\itshape  expr}] \index{{\ttfamily date} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [dated-name]  \item [{\ttfamily dated!-name} {\itshape  expr}] \index{{\ttfamily dated"!-name} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [datelessp expr] \item [{\ttfamily datelessp} {\itshape  expr}] \index{{\ttfamily datelessp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [datestamp expr] \item [{\ttfamily datestamp} {\itshape  expr}] \index{{\ttfamily datestamp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [de fexpr] \item [{\ttfamily de} {\itshape  fexpr}] \index{{\ttfamily de} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/*! fns [define-in-module]  \item [{\ttfamily define!-in!-module} {\itshape  expr}] \index{{\ttfamily define"!-in"!-module} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [deflist expr] \item [{\ttfamily deflist} {\itshape  expr}] \index{{\ttfamily deflist} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [deleq expr] \item [{\ttfamily deleq} {\itshape  expr}] \index{{\ttfamily deleq} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [delete expr] \item [{\ttfamily delete} {\itshape  expr}] \index{{\ttfamily delete} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [delete-file]  \item [{\ttfamily delete!-file} {\itshape  expr}] \index{{\ttfamily delete"!-file} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [delete-module]  \item [{\ttfamily delete!-module} {\itshape  expr}] \index{{\ttfamily delete"!-module} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [difference expr] \item [{\ttfamily difference} {\itshape  expr}] \index{{\ttfamily difference} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [digit expr] \item [{\ttfamily digit} {\itshape  expr}] \index{{\ttfamily digit} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [directoryp expr] \item [{\ttfamily directoryp} {\itshape  expr}] \index{{\ttfamily directoryp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [divide expr] \item [{\ttfamily divide} {\itshape  expr}] \index{{\ttfamily divide} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [dm fexpr] \item [{\ttfamily dm} {\itshape  fexpr}] \index{{\ttfamily dm} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [do macro] \item [{\ttfamily do} {\itshape macro}] \index{{\ttfamily do} {\itshape macro}} ~\newline
 * Not yet written
 */

/*! fns [do*]  \item [{\ttfamily do!*} {\itshape macro}] \index{{\ttfamily do"!*} {\itshape macro}} ~\newline
 * Not yet written
 */

/* fns [dolist macro] \item [{\ttfamily dolist} {\itshape macro}] \index{{\ttfamily dolist} {\itshape macro}} ~\newline
 * Not yet written
 */


/* fns [dotimes macro] \item [{\ttfamily dotimes} {\itshape macro}] \index{{\ttfamily dotimes} {\itshape macro}} ~\newline
 * Not yet written
 */

/*! fns [double-execute]  \item [{\ttfamily double!-execute} {\itshape  expr}] \index{{\ttfamily double"!-execute} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [egetv expr] \item [{\ttfamily egetv} {\itshape  expr}] \index{{\ttfamily egetv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [eject expr] \item [{\ttfamily eject} {\itshape  expr}] \index{{\ttfamily eject} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [enable-backtrace]  \item [{\ttfamily enable!-backtrace} {\itshape  expr}] \index{{\ttfamily enable"!-backtrace} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [enable-errorset]  \item [{\ttfamily enable!-errorset} {\itshape  expr}] \index{{\ttfamily enable"!-errorset} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [encapsulatedp expr] \item [{\ttfamily encapsulatedp} {\itshape  expr}] \index{{\ttfamily encapsulatedp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [endp expr] \item [{\ttfamily endp} {\itshape  expr}] \index{{\ttfamily endp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [eputv expr] \item [{\ttfamily eputv} {\itshape  expr}] \index{{\ttfamily eputv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [eq expr] \item [{\ttfamily eq} {\itshape  expr}] \index{{\ttfamily eq} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [eq-safe]  \item [{\ttfamily eq!-safe} {\itshape  expr}] \index{{\ttfamily eq"!-safe} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [eqcar expr] \item [{\ttfamily eqcar} {\itshape  expr}] \index{{\ttfamily eqcar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [eql expr] \item [{\ttfamily eql} {\itshape  expr}] \index{{\ttfamily eql} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [eqlhash expr] \item [{\ttfamily eqlhash} {\itshape  expr}] \index{{\ttfamily eqlhash} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [eqn expr] \item [{\ttfamily eqn} {\itshape  expr}] \index{{\ttfamily eqn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [equal expr] \item [{\ttfamily equal} {\itshape  expr}] \index{{\ttfamily equal} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [equalcar expr] \item [{\ttfamily equalcar} {\itshape  expr}] \index{{\ttfamily equalcar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [equalp expr] \item [{\ttfamily equalp} {\itshape  expr}] \index{{\ttfamily equalp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [error expr] \item [{\ttfamily error} {\itshape  expr}] \index{{\ttfamily error} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [error1 expr] \item [{\ttfamily error1} {\itshape  expr}] \index{{\ttfamily error1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [errorset expr] \item [{\ttfamily errorset} {\itshape  expr}] \index{{\ttfamily errorset} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [eupbv expr] \item [{\ttfamily eupbv} {\itshape  expr}] \index{{\ttfamily eupbv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [eval expr] \item [{\ttfamily eval} {\itshape  expr}] \index{{\ttfamily eval} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [eval-when]  \item [{\ttfamily eval!-when} {\itshape  fexpr}] \index{{\ttfamily eval"!-when} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [evectorp expr] \item [{\ttfamily evectorp} {\itshape  expr}] \index{{\ttfamily evectorp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [evenp expr] \item [{\ttfamily evenp} {\itshape  expr}] \index{{\ttfamily evenp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [evlis expr] \item [{\ttfamily evlis} {\itshape  expr}] \index{{\ttfamily evlis} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [exp expr] \item [{\ttfamily exp} {\itshape  expr}] \index{{\ttfamily exp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [expand expr] \item [{\ttfamily expand} {\itshape  expr}] \index{{\ttfamily expand} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explode expr] \item [{\ttfamily explode} {\itshape  expr}] \index{{\ttfamily explode} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explode2 expr] \item [{\ttfamily explode2} {\itshape  expr}] \index{{\ttfamily explode2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explode2lc expr] \item [{\ttfamily explode2lc} {\itshape  expr}] \index{{\ttfamily explode2lc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explode2lcn expr] \item [{\ttfamily explode2lcn} {\itshape  expr}] \index{{\ttfamily explode2lcn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explode2n expr] \item [{\ttfamily explode2n} {\itshape  expr}] \index{{\ttfamily explode2n} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explode2uc expr] \item [{\ttfamily explode2uc} {\itshape  expr}] \index{{\ttfamily explode2uc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explode2ucn expr] \item [{\ttfamily explode2ucn} {\itshape  expr}] \index{{\ttfamily explode2ucn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explodebinary expr] \item [{\ttfamily explodebinary} {\itshape  expr}] \index{{\ttfamily explodebinary} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explodec expr] \item [{\ttfamily explodec} {\itshape  expr}] \index{{\ttfamily explodec} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explodecn expr] \item [{\ttfamily explodecn} {\itshape  expr}] \index{{\ttfamily explodecn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explodehex expr] \item [{\ttfamily explodehex} {\itshape  expr}] \index{{\ttfamily explodehex} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [exploden expr] \item [{\ttfamily exploden} {\itshape  expr}] \index{{\ttfamily exploden} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [explodeoctal expr] \item [{\ttfamily explodeoctal} {\itshape  expr}] \index{{\ttfamily explodeoctal} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [expt expr] \item [{\ttfamily expt} {\itshape  expr}] \index{{\ttfamily expt} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [faslout expr] \item [{\ttfamily faslout} {\itshape  expr}] \index{{\ttfamily faslout} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [fetch!-url expr] \item [{\ttfamily fetch!-url} {\itshape  expr}] \index{{\ttfamily fetch"!-url} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [fgetv32 expr] \item [{\ttfamily fgetv32} {\itshape  expr}] \index{{\ttfamily fgetv32} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [fgetv64 expr] \item [{\ttfamily fgetv64} {\itshape  expr}] \index{{\ttfamily fgetv64} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [file-length]  \item [{\ttfamily file!-length} {\itshape  expr}] \index{{\ttfamily file"!-length} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [file-readablep]  \item [{\ttfamily file!-readablep} {\itshape  expr}] \index{{\ttfamily file"!-readablep} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [file-writablep]  \item [{\ttfamily file!-writeablep} {\itshape  expr}] \index{{\ttfamily file"!-writeablep} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [filedate expr] \item [{\ttfamily filedate} {\itshape  expr}] \index{{\ttfamily filedate} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [filep expr] \item [{\ttfamily filep} {\itshape  expr}] \index{{\ttfamily filep} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [fix expr] \item [{\ttfamily fix} {\itshape  expr}] \index{{\ttfamily fix} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [fixp expr] \item [{\ttfamily fixp} {\itshape  expr}] \index{{\ttfamily fixp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [flag expr] \item [{\ttfamily flag} {\itshape  expr}] \index{{\ttfamily flag} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [flagp expr] \item [{\ttfamily flagp} {\itshape  expr}] \index{{\ttfamily flagp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [flagp**]  \item [{\ttfamily flagp!*!*} {\itshape  expr}] \index{{\ttfamily flagp"!*"!*} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [flagpcar expr] \item [{\ttfamily flagpcar} {\itshape  expr}] \index{{\ttfamily flagpcar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [float expr] \item [{\ttfamily float} {\itshape  expr}] \index{{\ttfamily float} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [floatp expr] \item [{\ttfamily floatp} {\itshape  expr}] \index{{\ttfamily floatp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [floor expr] \item [{\ttfamily floor} {\itshape  expr}] \index{{\ttfamily floor} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [fluid expr] \item [{\ttfamily fluid} {\itshape  expr}] \index{{\ttfamily fluid} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [fluidp expr] \item [{\ttfamily fluidp} {\itshape  expr}] \index{{\ttfamily fluidp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [flush expr] \item [{\ttfamily flush} {\itshape  expr}] \index{{\ttfamily flush} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [format macro] \item [{\ttfamily format} {\itshape macro}] \index{{\ttfamily format} {\itshape macro}} ~\newline
 * Not yet written
 */


/*! fns [fp-evaluate]  \item [{\ttfamily fp!-evaluate} {\itshape  expr}] \index{{\ttfamily fp"!-evaluate} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [fputv32 expr] \item [{\ttfamily fputv32} {\itshape  expr}] \index{{\ttfamily fputv32} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [fputv64 expr] \item [{\ttfamily fputv64} {\itshape  expr}] \index{{\ttfamily fputv64} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [frexp expr] \item [{\ttfamily frexp} {\itshape  expr}] \index{{\ttfamily frexp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [funcall expr] \item [{\ttfamily funcall} {\itshape  expr}] \index{{\ttfamily funcall} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [funcall*]  \item [{\ttfamily funcall!*} {\itshape  expr}] \index{{\ttfamily funcall"!*} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [function fexpr] \item [{\ttfamily function} {\itshape  fexpr}] \index{{\ttfamily function} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [gcdn expr] \item [{\ttfamily gcdn} {\itshape  expr}] \index{{\ttfamily gcdn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [gctime expr] \item [{\ttfamily gctime} {\itshape  expr}] \index{{\ttfamily gctime} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [gensym expr] \item [{\ttfamily gensym} {\itshape  expr}] \index{{\ttfamily gensym} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [gensym1 expr] \item [{\ttfamily gensym1} {\itshape  expr}] \index{{\ttfamily gensym1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [gensym2 expr] \item [{\ttfamily gensym2} {\itshape  expr}] \index{{\ttfamily gensym2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [gensymp expr] \item [{\ttfamily gensymp} {\itshape  expr}] \index{{\ttfamily gensymp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [geq expr] \item [{\ttfamily geq} {\itshape  expr}] \index{{\ttfamily geq} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [get expr] \item [{\ttfamily get} {\itshape  expr}] \index{{\ttfamily get} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [get*]  \item [{\ttfamily get!*} {\itshape  expr}] \index{{\ttfamily get"!*} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [get-current-directory]  \item [{\ttfamily get!-current!-directory} {\itshape  expr}] \index{{\ttfamily get"!-current"!-directory} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [get-lisp-directory]  \item [{\ttfamily get!-lisp!-directory} {\itshape  expr}] \index{{\ttfamily get"!-lisp"!-directory} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [getd expr] \item [{\ttfamily getd} {\itshape  expr}] \index{{\ttfamily getd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [getenv expr] \item [{\ttfamily getenv} {\itshape  expr}] \index{{\ttfamily getenv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [gethash expr] \item [{\ttfamily gethash} {\itshape  expr}] \index{{\ttfamily gethash} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [getv expr] \item [{\ttfamily getv} {\itshape  expr}] \index{{\ttfamily getv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [getv16 expr] \item [{\ttfamily getv16} {\itshape  expr}] \index{{\ttfamily getv16} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [getv32 expr] \item [{\ttfamily getv32} {\itshape  expr}] \index{{\ttfamily getv32} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [getv8 expr] \item [{\ttfamily getv8} {\itshape  expr}] \index{{\ttfamily getv8} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [global expr] \item [{\ttfamily global} {\itshape  expr}] \index{{\ttfamily global} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [globalp expr] \item [{\ttfamily globalp} {\itshape  expr}] \index{{\ttfamily globalp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [go fexpr] \item [{\ttfamily go} {\itshape  fexpr}] \index{{\ttfamily go} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [greaterp expr] \item [{\ttfamily greaterp} {\itshape  expr}] \index{{\ttfamily greaterp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [hash-table-p]  \item [{\ttfamily hash!-table!-p} {\itshape  expr}] \index{{\ttfamily hash"!-table"!-p} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [hashcontents expr] \item [{\ttfamily hashcontents} {\itshape  expr}] \index{{\ttfamily hashcontents} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [hashtagged-name]  \item [{\ttfamily hashtagged!-name} {\itshape  expr}] \index{{\ttfamily hashtagged"!-name} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [hypot expr] \item [{\ttfamily hypot} {\itshape  expr}] \index{{\ttfamily hypot} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [iadd1 expr] \item [{\ttfamily iadd1} {\itshape  expr}] \index{{\ttfamily iadd1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [idapply expr] \item [{\ttfamily idapply} {\itshape  expr}] \index{{\ttfamily idapply} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [idifference expr] \item [{\ttfamily idifference} {\itshape  expr}] \index{{\ttfamily idifference} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [idp expr] \item [{\ttfamily idp} {\itshape  expr}] \index{{\ttfamily idp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [iequal expr] \item [{\ttfamily iequal} {\itshape  expr}] \index{{\ttfamily iequal} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [if fexpr] \item [{\ttfamily if} {\itshape  fexpr}] \index{{\ttfamily if} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [igeq expr] \item [{\ttfamily igeq} {\itshape  expr}] \index{{\ttfamily igeq} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [igreaterp expr] \item [{\ttfamily igreaterp} {\itshape  expr}] \index{{\ttfamily igreaterp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ileq expr] \item [{\ttfamily ileq} {\itshape  expr}] \index{{\ttfamily ileq} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ilessp expr] \item [{\ttfamily ilessp} {\itshape  expr}] \index{{\ttfamily ilessp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ilogand expr] \item [{\ttfamily ilogand} {\itshape  expr}] \index{{\ttfamily ilogand} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ilogor expr] \item [{\ttfamily ilogor} {\itshape  expr}] \index{{\ttfamily ilogor} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ilogxor expr] \item [{\ttfamily ilogxor} {\itshape  expr}] \index{{\ttfamily ilogxor} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [imax expr] \item [{\ttfamily imax} {\itshape  expr}] \index{{\ttfamily imax} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [imin expr] \item [{\ttfamily imin} {\itshape  expr}] \index{{\ttfamily imin} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [iminus expr] \item [{\ttfamily iminus} {\itshape  expr}] \index{{\ttfamily iminus} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [iminusp expr] \item [{\ttfamily iminusp} {\itshape  expr}] \index{{\ttfamily iminusp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [indirect expr] \item [{\ttfamily indirect} {\itshape  expr}] \index{{\ttfamily indirect} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [inorm expr] \item [{\ttfamily inorm} {\itshape  expr}] \index{{\ttfamily inorm} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [input-libraries]  \item [{\ttfamily input!-libraries} {\itshape  fexpr}] \index{{\ttfamily input"!-libraries} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/*! fns [instate-c-code]  \item [{\ttfamily instate!-c!-code} {\itshape  expr}] \index{{\ttfamily instate"!-c"!-code} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [integerp expr] \item [{\ttfamily integerp} {\itshape  expr}] \index{{\ttfamily integerp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [intern expr] \item [{\ttfamily intern} {\itshape  expr}] \index{{\ttfamily intern} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [interbal-open]  \item [{\ttfamily internal!-open} {\itshape  expr}] \index{{\ttfamily internal"!-open} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [intersection expr] \item [{\ttfamily intersection} {\itshape  expr}] \index{{\ttfamily intersection} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ionep expr] \item [{\ttfamily ionep} {\itshape  expr}] \index{{\ttfamily ionep} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [iplus expr] \item [{\ttfamily iplus} {\itshape  expr}] \index{{\ttfamily iplus} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [iplus2 expr] \item [{\ttfamily iplus2} {\itshape  expr}] \index{{\ttfamily iplus2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [iquotient expr] \item [{\ttfamily iquotient} {\itshape  expr}] \index{{\ttfamily iquotient} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [iremainder expr] \item [{\ttfamily iremainder} {\itshape  expr}] \index{{\ttfamily iremainder} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [irightshift expr] \item [{\ttfamily irightshift} {\itshape  expr}] \index{{\ttfamily irightshift} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [is-console]  \item [{\ttfamily is!-console} {\itshape  expr}] \index{{\ttfamily is"!-console} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [isub1 expr] \item [{\ttfamily isub1} {\itshape  expr}] \index{{\ttfamily isub1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [itimes expr] \item [{\ttfamily itimes} {\itshape  expr}] \index{{\ttfamily itimes} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [itimes2 expr] \item [{\ttfamily itimes2} {\itshape  expr}] \index{{\ttfamily itimes2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [izerop expr] \item [{\ttfamily izerop} {\itshape  expr}] \index{{\ttfamily izerop} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [last expr] \item [{\ttfamily last} {\itshape  expr}] \index{{\ttfamily last} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [lastcar expr] \item [{\ttfamily lastcar} {\itshape  expr}] \index{{\ttfamily lastcar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [lastpair expr] \item [{\ttfamily lastpair} {\itshape  expr}] \index{{\ttfamily lastpair} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [lcmn expr] \item [{\ttfamily lcmn} {\itshape  expr}] \index{{\ttfamily lcmn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [length expr] \item [{\ttfamily length} {\itshape  expr}] \index{{\ttfamily length} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [lengthc expr] \item [{\ttfamily lengthc} {\itshape  expr}] \index{{\ttfamily lengthc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [leq expr] \item [{\ttfamily leq} {\itshape  expr}] \index{{\ttfamily leq} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [lessp expr] \item [{\ttfamily lessp} {\itshape  expr}] \index{{\ttfamily lessp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [let*]  \item [{\ttfamily let!*} {\itshape  fexpr}] \index{{\ttfamily let"!*} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/*! fns [library-members]  \item [{\ttfamily library!-members} {\itshape  expr}] \index{{\ttfamily library"!-members} {\itshape  expr}} ~\newline
 * Returns a list of all the modules that could potentially be loaded using
 * {\ttfamily load!-module}. See {\ttfamily list!-modules} to get a human
 * readable display that looks more like the result of listing a directory, or
 * {\ttfamily modulep} for checking the state of a particular named module.
 *
 */

/*! fns [library-name]  \item [{\ttfamily library!-name} {\itshape  expr}] \index{{\ttfamily library"!-name} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [linelength expr] \item [{\ttfamily linelength} {\itshape  expr}] \index{{\ttfamily linelength} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [list fexpr] \item [{\ttfamily list} {\itshape  fexpr}] \index{{\ttfamily list} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/*! fns [list*]  \item [{\ttfamily list!*} {\itshape  fexpr}] \index{{\ttfamily list"!*} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/*! fns [list-directory]  \item [{\ttfamily list!-directory} {\itshape  expr}] \index{{\ttfamily list"!-directory} {\itshape  expr}} ~\newline
 * Not yet written
 *
 */

/*! fns [list-modules]  \item [{\ttfamily list!-modules} {\itshape  expr}] \index{{\ttfamily list"!-modules} {\itshape  expr}} ~\newline
 * This prints a human-readable display of the modules present in the current
 * image files. This will include ``InitialImage'' which is the heap-image
 * loaded at system startup. For example
 * {\footnotesize \begin{verbatim}
 * > (list!-modules)
 *
 * File d:\csl\csl.img (dirsize 8  length 155016, Writable):
 *   compat       Sat Jul 26 10:20:08 2008  position 556   size: 9320
 *   compiler     Sat Jul 26 10:20:08 2008  position 9880  size: 81088
 *   InitialImage Sat Jul 26 10:20:09 2008  position 90972 size: 64040
 *
 * nil
 * \end{verbatim}}
 *
 * See {\ttfamily library!-members} and {\ttfamily modulep} for functions that
 * make it possible for Lisp code to discover about the loadable modules that are
 * available.
 */

/*! fns [list-to-string]  \item [{\ttfamily list!-to!-string} {\itshape  expr}] \index{{\ttfamily list"!-to"!-string} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [list-to-symbol]  \item [{\ttfamily list!-to!-symbol} {\itshape  expr}] \index{{\ttfamily list"!-to"!-symbol} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [list-to-vector]  \item [{\ttfamily list!-to!-vector} {\itshape  expr}] \index{{\ttfamily list"!-to"!-vector} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [list2 expr] \item [{\ttfamily list2} {\itshape  expr}] \index{{\ttfamily list2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [list2*]  \item [{\ttfamily list2!*} {\itshape  expr}] \index{{\ttfamily list2"!*} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [list3 expr] \item [{\ttfamily list3} {\itshape  expr}] \index{{\ttfamily list3} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [list3*]  \item [{\ttfamily list3!*} {\itshape  expr}] \index{{\ttfamily list3"!*} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [list4 expr] \item [{\ttfamily list4} {\itshape  expr}] \index{{\ttfamily list4} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [liter expr] \item [{\ttfamily liter} {\itshape  expr}] \index{{\ttfamily liter} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ln expr] \item [{\ttfamily ln} {\itshape  expr}] \index{{\ttfamily ln} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [load-module]  \item [{\ttfamily load!-module} {\itshape  expr}] \index{{\ttfamily load"!-module} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [load-source]  \item [{\ttfamily load!-source} {\itshape  expr}] \index{{\ttfamily load"!-source} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [log expr] \item [{\ttfamily log} {\itshape  expr}] \index{{\ttfamily log} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [log10 expr] \item [{\ttfamily log10} {\itshape  expr}] \index{{\ttfamily log10} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [logand expr] \item [{\ttfamily logand} {\itshape  expr}] \index{{\ttfamily logand} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [logb expr] \item [{\ttfamily logb} {\itshape  expr}] \index{{\ttfamily logb} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [logeqv expr] \item [{\ttfamily logeqv} {\itshape  expr}] \index{{\ttfamily logeqv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [lognot expr] \item [{\ttfamily lognot} {\itshape  expr}] \index{{\ttfamily lognot} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [logor expr] \item [{\ttfamily logor} {\itshape  expr}] \index{{\ttfamily logor} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [logxor expr] \item [{\ttfamily logxor} {\itshape  expr}] \index{{\ttfamily logxor} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [lose-precision]  \item [{\ttfamily lose!-precision} {\itshape  expr}] \index{{\ttfamily lose"!-precision} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [lposn expr] \item [{\ttfamily lposn} {\itshape  expr}] \index{{\ttfamily lposn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [lsd expr] \item [{\ttfamily lsd} {\itshape  expr}] \index{{\ttfamily lsd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [macro-function]  \item [{\ttfamily macro!-function} {\itshape  expr}] \index{{\ttfamily macro"!-function} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [macroexpand expr] \item [{\ttfamily macroexpand} {\itshape  expr}] \index{{\ttfamily macroexpand} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [macroexpand-1]  \item [{\ttfamily macroexpand!-1} {\itshape  expr}] \index{{\ttfamily macroexpand"!-1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [make-bps]  \item [{\ttfamily make!-bps} {\itshape  expr}] \index{{\ttfamily make"!-bps} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [make-function-stream]  \item [{\ttfamily make!-function!-stream} {\itshape  expr}] \index{{\ttfamily make"!-function"!-stream} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [make-global]  \item [{\ttfamily make!-global} {\itshape  expr}] \index{{\ttfamily make"!-global} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [make-native]  \item [{\ttfamily make!-native} {\itshape  expr}] \index{{\ttfamily make"!-native} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [make-random-state]  \item [{\ttfamily make!-random!-state} {\itshape  expr}] \index{{\ttfamily make"!-random"!-state} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [make-simple-string]  \item [{\ttfamily make!-simple!-string} {\itshape  expr}] \index{{\ttfamily make"!-simple"!-string} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [make-special]  \item [{\ttfamily make!-special} {\itshape  expr}] \index{{\ttfamily make"!-special} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [map expr] \item [{\ttfamily map} {\itshape  expr}] \index{{\ttfamily map} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mapc expr] \item [{\ttfamily mapc} {\itshape  expr}] \index{{\ttfamily mapc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mapcan expr] \item [{\ttfamily mapcan} {\itshape  expr}] \index{{\ttfamily mapcan} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mapcar expr] \item [{\ttfamily mapcar} {\itshape  expr}] \index{{\ttfamily mapcar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mapcon expr] \item [{\ttfamily mapcon} {\itshape  expr}] \index{{\ttfamily mapcon} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [maphash expr] \item [{\ttfamily maphash} {\itshape  expr}] \index{{\ttfamily maphash} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [maple\_atomic\_value expr] \item [{\ttfamily maple\_atomic\_value} {\itshape  expr}] \index{{\ttfamily maple\_atomic\_value} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [maple\_component expr] \item [{\ttfamily maple\_component} {\itshape  expr}] \index{{\ttfamily maple\_component} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [maple\_integer expr] \item [{\ttfamily maple\_integer} {\itshape  expr}] \index{{\ttfamily maple\_integer} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [maple\_length expr] \item [{\ttfamily maple\_length} {\itshape  expr}] \index{{\ttfamily maple\_length} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [maple\_string\_data expr] \item [{\ttfamily maple\_string\_data} {\itshape  expr}] \index{{\ttfamily maple\_string\_data} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [maple\_tag expr] \item [{\ttfamily maple\_tag} {\itshape  expr}] \index{{\ttfamily maple\_tag} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [maplist expr] \item [{\ttfamily maplist} {\itshape  expr}] \index{{\ttfamily maplist} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mapstore expr] \item [{\ttfamily mapstore} {\itshape  expr}] \index{{\ttfamily mapstore} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [math-display]  \item [{\ttfamily math!-display} {\itshape  expr}] \index{{\ttfamily math"!-display} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [max expr] \item [{\ttfamily max} {\itshape  expr}] \index{{\ttfamily max} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [max2 expr] \item [{\ttfamily max2} {\itshape  expr}] \index{{\ttfamily max2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [md5 expr] \item [{\ttfamily md5} {\itshape  expr}] \index{{\ttfamily md5} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [md60 expr] \item [{\ttfamily md60} {\itshape  expr}] \index{{\ttfamily md60} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [member expr] \item [{\ttfamily member} {\itshape  expr}] \index{{\ttfamily member} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [member**]  \item [{\ttfamily member!*!*} {\itshape  expr}] \index{{\ttfamily member"!*"!*} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [memq expr] \item [{\ttfamily memq} {\itshape  expr}] \index{{\ttfamily memq} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [min expr] \item [{\ttfamily min} {\itshape  expr}] \index{{\ttfamily min} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [min2 expr] \item [{\ttfamily min2} {\itshape  expr}] \index{{\ttfamily min2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [minus expr] \item [{\ttfamily minus} {\itshape  expr}] \index{{\ttfamily minus} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [minusp expr] \item [{\ttfamily minusp} {\itshape  expr}] \index{{\ttfamily minusp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkevect expr] \item [{\ttfamily mkevect} {\itshape  expr}] \index{{\ttfamily mkevect} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkfvect32 expr] \item [{\ttfamily mkfvect32} {\itshape  expr}] \index{{\ttfamily mkfvect32} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkfvect64 expr] \item [{\ttfamily mkfvect64} {\itshape  expr}] \index{{\ttfamily mkfvect64} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkhash expr] \item [{\ttfamily mkhash} {\itshape  expr}] \index{{\ttfamily mkhash} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkquote expr] \item [{\ttfamily mkquote} {\itshape  expr}] \index{{\ttfamily mkquote} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkvect expr] \item [{\ttfamily mkvect} {\itshape  expr}] \index{{\ttfamily mkvect} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkvect16 expr] \item [{\ttfamily mkvect16} {\itshape  expr}] \index{{\ttfamily mkvect16} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkvect32 expr] \item [{\ttfamily mkvect32} {\itshape  expr}] \index{{\ttfamily mkvect32} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkvect8 expr] \item [{\ttfamily mkvect8} {\itshape  expr}] \index{{\ttfamily mkvect8} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mkxvect expr] \item [{\ttfamily mkxvect} {\itshape  expr}] \index{{\ttfamily mkxvect} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mod expr] \item [{\ttfamily mod} {\itshape  expr}] \index{{\ttfamily mod} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [modular!-difference expr] \item [{\ttfamily modular!-difference} {\itshape  expr}] \index{{\ttfamily modular"!-difference} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [modular!-expt expr] \item [{\ttfamily modular!-expt} {\itshape  expr}] \index{{\ttfamily modular"!-expt} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [modular!-minus expr] \item [{\ttfamily modular!-minus} {\itshape  expr}] \index{{\ttfamily modular"!-minus} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [modular!-number expr] \item [{\ttfamily modular!-number} {\itshape  expr}] \index{{\ttfamily modular"!-number} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [modular!-plus expr] \item [{\ttfamily modular!-plus} {\itshape  expr}] \index{{\ttfamily modular"!-plus} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [modular!-quotient expr] \item [{\ttfamily modular!-quotient} {\itshape  expr}] \index{{\ttfamily modular"!-quotient} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [modular!-reciprocal expr] \item [{\ttfamily modular!-reciprocal} {\itshape  expr}] \index{{\ttfamily modular"!-reciprocal} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [modular!-times expr] \item [{\ttfamily modular!-times} {\itshape  expr}] \index{{\ttfamily modular"!-times} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [modulep expr] \item [{\ttfamily modulep} {\itshape  expr}] \index{{\ttfamily modulep} {\itshape  expr}} ~\newline
 * This takes a single argument and checks whether there is a loadable module
 * of that name. If there is not then {\ttfamily nil} is returned, otherwise a
 * string that indicates the date-stamp on the module is given. See
 * {\ttfamily datelessp} for working with such dates, and {\ttfamily
 * library!-members} for finding a list of all modules that are available.
 *
 */

/* fns [mpi\_allgather expr] \item [{\ttfamily mpi\_allgather} {\itshape  expr}] \index{{\ttfamily mpi\_allgather} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_alltoall expr] \item [{\ttfamily mpi\_alltoall} {\itshape  expr}] \index{{\ttfamily mpi\_alltoall} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_barrier expr] \item [{\ttfamily mpi\_barrier} {\itshape  expr}] \index{{\ttfamily mpi\_barrier} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_bcast expr] \item [{\ttfamily mpi\_bcast} {\itshape  expr}] \index{{\ttfamily mpi\_bcast} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_comm\_rank expr] \item [{\ttfamily mpi\_comm\_rank} {\itshape  expr}] \index{{\ttfamily mpi\_comm\_rank} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_comm\_size expr] \item [{\ttfamily mpi\_comm\_size} {\itshape  expr}] \index{{\ttfamily mpi\_comm\_size} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_gather expr] \item [{\ttfamily mpi\_gather} {\itshape  expr}] \index{{\ttfamily mpi\_gather} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_iprobe expr] \item [{\ttfamily mpi\_iprobe} {\itshape  expr}] \index{{\ttfamily mpi\_iprobe} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_irecv expr] \item [{\ttfamily mpi\_irecv} {\itshape  expr}] \index{{\ttfamily mpi\_irecv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_isend expr] \item [{\ttfamily mpi\_isend} {\itshape  expr}] \index{{\ttfamily mpi\_isend} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_probe expr] \item [{\ttfamily mpi\_probe} {\itshape  expr}] \index{{\ttfamily mpi\_probe} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_recv expr] \item [{\ttfamily mpi\_recv} {\itshape  expr}] \index{{\ttfamily mpi\_recv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_scatter expr] \item [{\ttfamily mpi\_scatter} {\itshape  expr}] \index{{\ttfamily mpi\_scatter} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_send expr] \item [{\ttfamily mpi\_send} {\itshape  expr}] \index{{\ttfamily mpi\_send} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_sendrecv expr] \item [{\ttfamily mpi\_sendrecv} {\itshape  expr}] \index{{\ttfamily mpi\_sendrecv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_test expr] \item [{\ttfamily mpi\_test} {\itshape  expr}] \index{{\ttfamily mpi\_test} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [mpi\_wait expr] \item [{\ttfamily mpi\_wait} {\itshape  expr}] \index{{\ttfamily mpi\_wait} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [msd expr] \item [{\ttfamily msd} {\itshape  expr}] \index{{\ttfamily msd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [native!-address expr] \item [{\ttfamily native!-address} {\itshape  expr}] \index{{\ttfamily native"!-address} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [native!-getv expr] \item [{\ttfamily native!-getv} {\itshape  expr}] \index{{\ttfamily native"!-getv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [native!-putv expr] \item [{\ttfamily native!-putv} {\itshape  expr}] \index{{\ttfamily native"!-putv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [native!-type expr] \item [{\ttfamily native!-type} {\itshape  expr}] \index{{\ttfamily native"!-type} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [nconc expr] \item [{\ttfamily nconc} {\itshape  expr}] \index{{\ttfamily nconc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ncons expr] \item [{\ttfamily ncons} {\itshape  expr}] \index{{\ttfamily ncons} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [neq expr] \item [{\ttfamily neq} {\itshape  expr}] \index{{\ttfamily neq} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [noisy!-setq fexpr] \item [{\ttfamily noisy!-setq} {\itshape  fexpr}] \index{{\ttfamily noisy"!-setq} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [not expr] \item [{\ttfamily not} {\itshape  expr}] \index{{\ttfamily not} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [nreverse expr] \item [{\ttfamily nreverse} {\itshape  expr}] \index{{\ttfamily nreverse} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [null expr] \item [{\ttfamily null} {\itshape  expr}] \index{{\ttfamily null} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [numberp expr] \item [{\ttfamily numberp} {\itshape  expr}] \index{{\ttfamily numberp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [oblist expr] \item [{\ttfamily oblist} {\itshape  expr}] \index{{\ttfamily oblist} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [oddp expr] \item [{\ttfamily oddp} {\itshape  expr}] \index{{\ttfamily oddp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [oem!-supervisor expr] \item [{\ttfamily oem!-supervisor} {\itshape  expr}] \index{{\ttfamily oem"!-supervisor} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [onep expr] \item [{\ttfamily onep} {\itshape  expr}] \index{{\ttfamily onep} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [open expr] \item [{\ttfamily open} {\itshape  expr}] \index{{\ttfamily open} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [open!-library expr] \item [{\ttfamily open!-library} {\itshape  expr}] \index{{\ttfamily open"!-library} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [open!-url expr] \item [{\ttfamily open!-url} {\itshape  expr}] \index{{\ttfamily open"!-url} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [or fexpr] \item [{\ttfamily or} {\itshape  fexpr}] \index{{\ttfamily or} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [orderp expr] \item [{\ttfamily orderp} {\itshape  expr}] \index{{\ttfamily orderp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ordp expr] \item [{\ttfamily ordp} {\itshape  expr}] \index{{\ttfamily ordp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [output!-library fexpr] \item [{\ttfamily output!-library} {\itshape  fexpr}] \index{{\ttfamily output"!-library} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [pagelength expr] \item [{\ttfamily pagelength} {\itshape  expr}] \index{{\ttfamily pagelength} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [pair expr] \item [{\ttfamily pair} {\itshape  expr}] \index{{\ttfamily pair} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [pairp expr] \item [{\ttfamily pairp} {\itshape  expr}] \index{{\ttfamily pairp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [parallel expr] \item [{\ttfamily parallel} {\itshape  expr}] \index{{\ttfamily parallel} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [peekch expr] \item [{\ttfamily peekch} {\itshape  expr}] \index{{\ttfamily peekch} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [pipe!-open expr] \item [{\ttfamily pipe!-open} {\itshape  expr}] \index{{\ttfamily pipe"!-open} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [plist expr] \item [{\ttfamily plist} {\itshape  expr}] \index{{\ttfamily plist} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [plus fexpr] \item [{\ttfamily plus} {\itshape  fexpr}] \index{{\ttfamily plus} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [plus2 expr] \item [{\ttfamily plus2} {\itshape  expr}] \index{{\ttfamily plus2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [plusp expr] \item [{\ttfamily plusp} {\itshape  expr}] \index{{\ttfamily plusp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [posn expr] \item [{\ttfamily posn} {\itshape  expr}] \index{{\ttfamily posn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [preserve expr] \item [{\ttfamily preserve} {\itshape  expr}] \index{{\ttfamily preserve} {\itshape  expr}} ~\newline
 * If {\ttfamily preserve} is not given any arguments or is given {\ttfamily
 * nil} as its first argument if writes a new image file that, when restarted,
 * will run whatever startup-function was currently active. For a raw Lisp this
 * is a simple read-eval-print loop, but if the system had been loaded
 * from a previous image that had been saved by {\ttfamily preserve} with
 * a non-{\ttfamily nil} first argument it is the function specified there.
 * If the second argument is non-{\ttfamily nil} it should really be a string
 * of length no more than 40 that will be used as a banner to be displayed
 * when the new image is loaded. The arrangements are that the banner is
 * displayed right at the start of the image-loading process, and so can
 * give the user reassurance even if the loading were to take some time (for
 * instance because a very slow computer was in use).
 *
 * Normally {\ttfamily preserve} exits. If a third argument and is
 * non-{\ttfamily nil} then after creating the image file the system
 * re-loads it and invokes its start-up function. This exits from the
 * current computation. The behaviour should be as if {\ttfamily
 * (restart!-csl t)} had been called. 
 */

/* fns [prettyprint expr] \item [{\ttfamily prettyprint} {\itshape  expr}] \index{{\ttfamily prettyprint} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prin expr] \item [{\ttfamily prin} {\itshape  expr}] \index{{\ttfamily prin} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prin1 expr] \item [{\ttfamily prin1} {\itshape  expr}] \index{{\ttfamily prin1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prin2 expr] \item [{\ttfamily prin2} {\itshape  expr}] \index{{\ttfamily prin2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prin2a expr] \item [{\ttfamily prin2a} {\itshape  expr}] \index{{\ttfamily prin2a} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prinbinary expr] \item [{\ttfamily prinbinary} {\itshape  expr}] \index{{\ttfamily prinbinary} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [princ expr] \item [{\ttfamily princ} {\itshape  expr}] \index{{\ttfamily princ} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [princ!-downcase expr] \item [{\ttfamily princ!-downcase} {\itshape  expr}] \index{{\ttfamily princ"!-downcase} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [princ!-upcase expr] \item [{\ttfamily princ!-upcase} {\itshape  expr}] \index{{\ttfamily princ"!-upcase} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [princl expr] \item [{\ttfamily princl} {\itshape  expr}] \index{{\ttfamily princl} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prinhex expr] \item [{\ttfamily prinhex} {\itshape  expr}] \index{{\ttfamily prinhex} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prinl expr] \item [{\ttfamily prinl} {\itshape  expr}] \index{{\ttfamily prinl} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prinoctal expr] \item [{\ttfamily prinoctal} {\itshape  expr}] \index{{\ttfamily prinoctal} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prinraw expr] \item [{\ttfamily prinraw} {\itshape  expr}] \index{{\ttfamily prinraw} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [print expr] \item [{\ttfamily print} {\itshape  expr}] \index{{\ttfamily print} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [print!-config!-header expr] \item [{\ttfamily print!-config!-header} {\itshape  expr}] \index{{\ttfamily print"!-config"!-header} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [print!-csl!-headers expr] \item [{\ttfamily print!-csl!-headers} {\itshape  expr}] \index{{\ttfamily print"!-csl"!-headers} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [print!-imports expr] \item [{\ttfamily print!-imports} {\itshape  expr}] \index{{\ttfamily print"!-imports} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [printc expr] \item [{\ttfamily printc} {\itshape  expr}] \index{{\ttfamily printc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [printcl expr] \item [{\ttfamily printcl} {\itshape  expr}] \index{{\ttfamily printcl} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [printl expr] \item [{\ttfamily printl} {\itshape  expr}] \index{{\ttfamily printl} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [printprompt expr] \item [{\ttfamily printprompt} {\itshape  expr}] \index{{\ttfamily printprompt} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [prog fexpr] \item [{\ttfamily prog} {\itshape  fexpr}] \index{{\ttfamily prog} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [prog1 fexpr] \item [{\ttfamily prog1} {\itshape  fexpr}] \index{{\ttfamily prog1} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [prog2 fexpr] \item [{\ttfamily prog2} {\itshape  fexpr}] \index{{\ttfamily prog2} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [progn fexpr] \item [{\ttfamily progn} {\itshape  fexpr}] \index{{\ttfamily progn} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [protect!-symbols expr] \item [{\ttfamily protect!-symbols} {\itshape  expr}] \index{{\ttfamily protect"!-symbols} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [protected!-symbol!-warn expr] \item [{\ttfamily protected!-symbol!-warn} {\itshape  expr}] \index{{\ttfamily protected"!-symbol!-warn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [psetq macro] \item [{\ttfamily psetq} {\itshape macro}] \index{{\ttfamily psetq} {\itshape macro}} ~\newline
 * Not yet written
 */

/* fns [put expr] \item [{\ttfamily put} {\itshape  expr}] \index{{\ttfamily put} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [putc expr] \item [{\ttfamily putc} {\itshape  expr}] \index{{\ttfamily putc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [putd expr] \item [{\ttfamily putd} {\itshape  expr}] \index{{\ttfamily putd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [puthash expr] \item [{\ttfamily puthash} {\itshape  expr}] \index{{\ttfamily puthash} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [putv expr] \item [{\ttfamily putv} {\itshape  expr}] \index{{\ttfamily putv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [putv!-char expr] \item [{\ttfamily putv!-char} {\itshape  expr}] \index{{\ttfamily putv"!-char} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [putv16 expr] \item [{\ttfamily putv16} {\itshape  expr}] \index{{\ttfamily putv16} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [putv32 expr] \item [{\ttfamily putv32} {\itshape  expr}] \index{{\ttfamily putv32} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [putv8 expr] \item [{\ttfamily putv8} {\itshape  expr}] \index{{\ttfamily putv8} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [qcaar expr] \item [{\ttfamily qcaar} {\itshape  expr}] \index{{\ttfamily qcaar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [qcadr expr] \item [{\ttfamily qcadr} {\itshape  expr}] \index{{\ttfamily qcadr} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [qcar expr] \item [{\ttfamily qcar} {\itshape  expr}] \index{{\ttfamily qcar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [qcdar expr] \item [{\ttfamily qcdar} {\itshape  expr}] \index{{\ttfamily qcdar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [qcddr expr] \item [{\ttfamily qcddr} {\itshape  expr}] \index{{\ttfamily qcddr} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [qcdr expr] \item [{\ttfamily qcdr} {\itshape  expr}] \index{{\ttfamily qcdr} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [qgetv expr] \item [{\ttfamily qgetv} {\itshape  expr}] \index{{\ttfamily qgetv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [qputv expr] \item [{\ttfamily qputv} {\itshape  expr}] \index{{\ttfamily qputv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [quote fexpr] \item [{\ttfamily quote} {\itshape  fexpr}] \index{{\ttfamily quote} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [quotient expr] \item [{\ttfamily quotient} {\itshape  expr}] \index{{\ttfamily quotient} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [random!-fixnum expr] \item [{\ttfamily random!-fixnum} {\itshape  expr}] \index{{\ttfamily random"!-fixnum} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [random!-number expr] \item [{\ttfamily random!-number} {\itshape  expr}] \index{{\ttfamily random"!-number} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [rassoc expr] \item [{\ttfamily rassoc} {\itshape  expr}] \index{{\ttfamily rassoc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [rational expr] \item [{\ttfamily rational} {\itshape  expr}] \index{{\ttfamily rational} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [rdf expr] \item [{\ttfamily rdf} {\itshape  expr}] \index{{\ttfamily rdf} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [rds expr] \item [{\ttfamily rds} {\itshape  expr}] \index{{\ttfamily rds} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [read expr] \item [{\ttfamily read} {\itshape  expr}] \index{{\ttfamily read} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [readb expr] \item [{\ttfamily readb} {\itshape  expr}] \index{{\ttfamily readb} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [readch expr] \item [{\ttfamily readch} {\itshape  expr}] \index{{\ttfamily readch} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [readline expr] \item [{\ttfamily readline} {\itshape  expr}] \index{{\ttfamily readline} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [reclaim expr] \item [{\ttfamily reclaim} {\itshape  expr}] \index{{\ttfamily reclaim} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [remainder expr] \item [{\ttfamily remainder} {\itshape  expr}] \index{{\ttfamily remainder} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [remd expr] \item [{\ttfamily remd} {\itshape  expr}] \index{{\ttfamily remd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [remflag expr] \item [{\ttfamily remflag} {\itshape  expr}] \index{{\ttfamily remflag} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [remhash expr] \item [{\ttfamily remhash} {\itshape  expr}] \index{{\ttfamily remhash} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [remob expr] \item [{\ttfamily remob} {\itshape  expr}] \index{{\ttfamily remob} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [remprop expr] \item [{\ttfamily remprop} {\itshape  expr}] \index{{\ttfamily remprop} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [rename!-file expr] \item [{\ttfamily rename!-file} {\itshape  expr}] \index{{\ttfamily rename"!-file} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [representation expr] \item [{\ttfamily representation} {\itshape  expr}] \index{{\ttfamily representation} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [resource!-exceeded expr] \item [{\ttfamily resource!-exceeded} {\itshape  expr}] \index{{\ttfamily resource"!-exceeded} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [resource!-limit expr] \item [{\ttfamily resource!-limit} {\itshape  expr}] \index{{\ttfamily resource"!-limit} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [restart!-csl expr] \item [{\ttfamily restart!-csl} {\itshape  expr}] \index{{\ttfamily restart"!-csl} {\itshape  expr}} ~\newline
 * {\ttfamily restart!-csl} can be called with 1 or 2 arguments. If the
 * first argument is {\ttfamily nil} it does a ``cold'' restart, so that
 * the lisp-system re-initialises itself from scratch with only a minimum
 * amount of functionality. This should only be used by people who are
 * bootstrapping the whole system. If the first argument is {\ttfamily t}
 * the restart is a normal one that expects to reload an image previously
 * created by {\ttfamily preserve} abd invoke its default restart function.
 * If the argument is another name then that image is re-loaded but the
 * named function is called. Finally of the argument is a list of the
 * form {\itshape (module fname)} then the standard image is loaded, then
 * the named module is loaded into it (as by {\ttfamily load!-module}) and
 * the function named is called.
 *
 * If {\ttfamily restart!-csl} is called with two arguments then the second
 * is used as an argument for the restart function in the restored image.
 * Because everything has been re-initialised it is an expression that is
 * as if the value had been printed and then the new image read it back in
 * that is used. In simple cases this will not make any difference, but
 * it does mean that sub-structure sharing etc.\ is not reliable as from the
 * data presented to the argument passed on restart, and some data objects may
 * not be passable. Simple lists, symbols, numbers and strings should work
 * in an unremarkable and straightforward manner.
 */

/* fns [restore!-c!-code expr] \item [{\ttfamily restore!-c!-code} {\itshape  expr}] \index{{\ttfamily restore"!-c"!-code} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [return fexpr] \item [{\ttfamily return} {\itshape  fexpr}] \index{{\ttfamily return} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [reverse expr] \item [{\ttfamily reverse} {\itshape  expr}] \index{{\ttfamily reverse} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [reversip expr] \item [{\ttfamily reversip} {\itshape  expr}] \index{{\ttfamily reversip} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [round expr] \item [{\ttfamily round} {\itshape  expr}] \index{{\ttfamily round} {\itshape  expr}} ~\newline
 * Not yet written
 */


/* fns [rplacw expr] \item [{\ttfamily rplacw} {\itshape  expr}] \index{{\ttfamily rplacw} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [rseek expr] \item [{\ttfamily rseek} {\itshape  expr}] \index{{\ttfamily rseek} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [rtell expr] \item [{\ttfamily rtell} {\itshape  expr}] \index{{\ttfamily rtell} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:blankcount macro] \item [{\ttfamily s!:blankcount} {\itshape macro}] \index{{\ttfamily s"!:blankcount} {\itshape macro}} ~\newline
 * Not yet written
 */

/* fns [s!:blanklist macro] \item [{\ttfamily s!:blanklist} {\itshape macro}] \index{{\ttfamily s"!:blanklist} {\itshape macro}} ~\newline
 * Not yet written
 */

/* fns [s!:blankp macro] \item [{\ttfamily s!:blankp} {\itshape macro}] \index{{\ttfamily s"!:blankp} {\itshape macro}} ~\newline
 * Not yet written
 */

/* fns [s!:depth macro] \item [{\ttfamily s!:depth} {\itshape macro}] \index{{\ttfamily s"!:depth} {\itshape macro}} ~\newline
 * Not yet written
 */

/* fns [s!:do!-bindings expr] \item [{\ttfamily s!:do!-bindings} {\itshape  expr}] \index{{\ttfamily s"!:do"!-bindings} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:do!-endtest expr] \item [{\ttfamily s!:do!-endtest} {\itshape  expr}] \index{{\ttfamily s"!:do"!-endtest} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:do!-result expr] \item [{\ttfamily s!:do!-result} {\itshape  expr}] \index{{\ttfamily s"!:do"!-result} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:do!-updates expr] \item [{\ttfamily s!:do!-updates} {\itshape  expr}] \index{{\ttfamily s"!:do"!-updates} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:endlist expr] \item [{\ttfamily s!:endlist} {\itshape  expr}] \index{{\ttfamily s"!:endlist} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:expand!-do expr] \item [{\ttfamily s!:expand!-do} {\itshape  expr}] \index{{\ttfamily s"!:expand"!-do} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:expand!-dolist expr] \item [{\ttfamily s!:expand!-dolist} {\itshape  expr}] \index{{\ttfamily s"!:expand"!-dolist} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:expand!-dotimes expr] \item [{\ttfamily s!:expand!-dotimes} {\itshape  expr}] \index{{\ttfamily s"!:expand"!-dotimes} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:explodes expr] \item [{\ttfamily s!:explodes} {\itshape  expr}] \index{{\ttfamily s"!:explodes} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:finishpending expr] \item [{\ttfamily s!:finishpending} {\itshape  expr}] \index{{\ttfamily s"!:finishpending} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:format expr] \item [{\ttfamily s!:format} {\itshape  expr}] \index{{\ttfamily s"!:format} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:indenting macro] \item [{\ttfamily s!:indenting} {\itshape macro}] \index{{\ttfamily s"!:indenting} {\itshape macro}} ~\newline
 * Not yet written
 */

/* fns [s!:make!-psetq!-assignments expr] \item [{\ttfamily s!:make!-psetq!-assignments} {\itshape  expr}] \index{{\ttfamily s"!:make"!-psetq"!-assignments} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:make!-psetq!-bindings expr] \item [{\ttfamily s!:make!-psetq!-bindings} {\itshape  expr}] \index{{\ttfamily s"!:make"!-psetq"!-bindings} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:make!-psetq!-vars expr] \item [{\ttfamily s!:make!-psetq!-vars} {\itshape  expr}] \index{{\ttfamily s"!:make"!-psetq"!-vars} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:newframe macro] \item [{\ttfamily s!:newframe} {\itshape macro}] \index{{\ttfamily s"!:newframe} {\itshape macro}} ~\newline
 * Not yet written
 */

/* fns [s!:oblist expr] \item [{\ttfamily s!:oblist} {\itshape  expr}] \index{{\ttfamily s"!:oblist} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:oblist1 expr] \item [{\ttfamily s!:oblist1} {\itshape  expr}] \index{{\ttfamily s"!:oblist1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:overflow expr] \item [{\ttfamily s!:overflow} {\itshape  expr}] \index{{\ttfamily s"!:overflow} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:prindent expr] \item [{\ttfamily s!:prindent} {\itshape  expr}] \index{{\ttfamily s"!:prindent} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:prinl0 expr] \item [{\ttfamily s!:prinl0} {\itshape  expr}] \index{{\ttfamily s"!:prinl0} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:prinl1 expr] \item [{\ttfamily s!:prinl1} {\itshape  expr}] \index{{\ttfamily s"!:prinl1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:prinl2 expr] \item [{\ttfamily s!:prinl2} {\itshape  expr}] \index{{\ttfamily s"!:prinl2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:prvector expr] \item [{\ttfamily s!:prvector} {\itshape  expr}] \index{{\ttfamily s"!:prvector} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:putblank expr] \item [{\ttfamily s!:putblank} {\itshape  expr}] \index{{\ttfamily s"!:putblank} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:putch expr] \item [{\ttfamily s!:putch} {\itshape  expr}] \index{{\ttfamily s"!:putch} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:quotep expr] \item [{\ttfamily s!:quotep} {\itshape  expr}] \index{{\ttfamily s"!:quotep} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:setblankcount macro] \item [{\ttfamily s!:setblankcount} {\itshape macro}] \index{{\ttfamily s"!:setblankcount} {\itshape macro}} ~\newline
 * Not yet written
 */


/* fns [s!:setblanklist macro] \item [{\ttfamily s!:setblanklist} {\itshape macro}] \index{{\ttfamily s"!:setblanklist} {\itshape macro}} ~\newline
 * Not yet written
 */


/* fns [s!:setindenting macro] \item [{\ttfamily s!:setindenting} {\itshape macro}] \index{{\ttfamily s"!:setindenting} {\itshape macro}} ~\newline
 * Not yet written
 */


/* fns [s!:stamp expr] \item [{\ttfamily s!:stamp} {\itshape  expr}] \index{{\ttfamily s"!:stamp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [s!:top macro] \item [{\ttfamily s!:top} {\itshape macro}] \index{{\ttfamily s"!:top} {\itshape macro}} ~\newline
 * Not yet written
 */


/* fns [safe!-fp!-pl expr] \item [{\ttfamily safe!-fp!-pl} {\itshape  expr}] \index{{\ttfamily safe"!-"fp"!-pl} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [safe!-fp!-pl0 expr] \item [{\ttfamily safe!-fp!-pl0} {\itshape  expr}] \index{{\ttfamily safe"!-fp"!-pl0} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [safe!-fp!-plus expr] \item [{\ttfamily safe!-fp!-plus} {\itshape  expr}] \index{{\ttfamily safe"!-fp"!-plus} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [safe!-fp!-quot expr] \item [{\ttfamily safe!-fp!-quot} {\itshape  expr}] \index{{\ttfamily safe"!-fp"!-quot} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [safe!-fp!-times expr] \item [{\ttfamily safe!-fp!-times} {\itshape  expr}] \index{{\ttfamily safe"!-fp"!-times} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sample expr] \item [{\ttfamily sample} {\itshape  expr}] \index{{\ttfamily sample} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sassoc expr] \item [{\ttfamily sassoc} {\itshape  expr}] \index{{\ttfamily sassoc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [schar expr] \item [{\ttfamily schar} {\itshape  expr}] \index{{\ttfamily schar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [scharn expr] \item [{\ttfamily scharn} {\itshape  expr}] \index{{\ttfamily scharn} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sec expr] \item [{\ttfamily sec} {\itshape  expr}] \index{{\ttfamily sec} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [secd expr] \item [{\ttfamily secd} {\itshape  expr}] \index{{\ttfamily secd} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sech expr] \item [{\ttfamily sech} {\itshape  expr}] \index{{\ttfamily sech} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [seprp expr] \item [{\ttfamily seprp} {\itshape  expr}] \index{{\ttfamily seprp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [set expr] \item [{\ttfamily set} {\itshape  expr}] \index{{\ttfamily set} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [set!-autoload expr] \item [{\ttfamily set!-autoload} {\itshape  expr}] \index{{\ttfamily set"!-autoload} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [set!-help!-file expr] \item [{\ttfamily set!-help!-file} {\itshape  expr}] \index{{\ttfamily set"!-help"!-file} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [set!-print!-precision expr] \item [{\ttfamily set!-print!-precision} {\itshape  expr}] \index{{\ttfamily set"!-print"!-precision} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [set!-small!-modulus expr] \item [{\ttfamily set!-small!-modulus} {\itshape  expr}] \index{{\ttfamily set"!-small"!-modulus} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [setpchar expr] \item [{\ttfamily setpchar} {\itshape  expr}] \index{{\ttfamily setpchar} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [setq fexpr] \item [{\ttfamily setq} {\itshape  fexpr}] \index{{\ttfamily setq} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [silent!-system expr] \item [{\ttfamily silent!-system} {\itshape  expr}] \index{{\ttfamily silent"!-system} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [simple!-string!-p expr] \item [{\ttfamily simple!-string!-p} {\itshape  expr}] \index{{\ttfamily simple"!-string"!-p} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [simple!-vector!-p expr] \item [{\ttfamily simple!-vector!-p} {\itshape  expr}] \index{{\ttfamily simple"!-vector"!-p} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sin expr] \item [{\ttfamily sin} {\itshape  expr}] \index{{\ttfamily sin} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sind expr] \item [{\ttfamily sind} {\itshape  expr}] \index{{\ttfamily sind} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sinh expr] \item [{\ttfamily sinh} {\itshape  expr}] \index{{\ttfamily sinh} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [smemq expr] \item [{\ttfamily smemq} {\itshape  expr}] \index{{\ttfamily smemq} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sort expr] \item [{\ttfamily sort} {\itshape  expr}] \index{{\ttfamily sort} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sortip expr] \item [{\ttfamily sortip} {\itshape  expr}] \index{{\ttfamily sortip} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [spaces expr] \item [{\ttfamily spaces} {\itshape  expr}] \index{{\ttfamily spaces} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [special!-char expr] \item [{\ttfamily special!-char} {\itshape  expr}] \index{{\ttfamily special"!-char} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [special!-form!-p expr] \item [{\ttfamily special!-form!-p} {\itshape  expr}] \index{{\ttfamily special"!-form"!-p} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [spool expr] \item [{\ttfamily spool} {\itshape  expr}] \index{{\ttfamily spool} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sqrt expr] \item [{\ttfamily sqrt} {\itshape  expr}] \index{{\ttfamily sqrt} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [stable!-sort expr] \item [{\ttfamily stable!-sort} {\itshape  expr}] \index{{\ttfamily stable"!-sort} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [stable!-sortip expr] \item [{\ttfamily stable!-sortip} {\itshape  expr}] \index{{\ttfamily stable"!-sortip} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [start!-module expr] \item [{\ttfamily start!-module} {\itshape  expr}] \index{{\ttfamily start"!-module} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [startup!-banner expr] \item [{\ttfamily startup!-banner} {\itshape  expr}] \index{{\ttfamily startup"!-banner} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [stop expr] \item [{\ttfamily stop} {\itshape  expr}] \index{{\ttfamily stop} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [streamp expr] \item [{\ttfamily streamp} {\itshape  expr}] \index{{\ttfamily streamp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [stringp expr] \item [{\ttfamily stringp} {\itshape  expr}] \index{{\ttfamily stringp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sub1 expr] \item [{\ttfamily sub1} {\itshape  expr}] \index{{\ttfamily sub1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [subla expr] \item [{\ttfamily subla} {\itshape  expr}] \index{{\ttfamily subla} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sublis expr] \item [{\ttfamily sublis} {\itshape  expr}] \index{{\ttfamily sublis} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [subst expr] \item [{\ttfamily subst} {\itshape  expr}] \index{{\ttfamily subst} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [superprinm expr] \item [{\ttfamily superprinm} {\itshape  expr}] \index{{\ttfamily superprinm} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [superprintm expr] \item [{\ttfamily superprintm} {\itshape  expr}] \index{{\ttfamily superprintm} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [sxhash expr] \item [{\ttfamily sxhash} {\itshape  expr}] \index{{\ttfamily sxhash} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-argcode expr] \item [{\ttfamily symbol!-argcode} {\itshape  expr}] \index{{\ttfamily symbol"!-argcode} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-argcount expr] \item [{\ttfamily symbol!-argcount} {\itshape  expr}] \index{{\ttfamily symbol"!-argcount} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-env expr] \item [{\ttfamily symbol!-env} {\itshape  expr}] \index{{\ttfamily symbol"!-env} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-fastgets expr] \item [{\ttfamily symbol!-fastgets} {\itshape  expr}] \index{{\ttfamily symbol"!-fastgets} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-fn!-cell expr] \item [{\ttfamily symbol!-fn!-cell} {\itshape  expr}] \index{{\ttfamily symbol"!-fn"!-cell} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-function expr] \item [{\ttfamily symbol!-function} {\itshape  expr}] \index{{\ttfamily symbol"!-function} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-make!-fastget expr] \item [{\ttfamily symbol!-make!-fastget} {\itshape  expr}] \index{{\ttfamily symbol"!-make"!-fastget} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-name expr] \item [{\ttfamily symbol!-name} {\itshape  expr}] \index{{\ttfamily symbol"!-name} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-protect expr] \item [{\ttfamily symbol!-protect} {\itshape  expr}] \index{{\ttfamily symbol"!-protect} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-restore!-fns expr] \item [{\ttfamily symbol!-restore!-fns} {\itshape  expr}] \index{{\ttfamily symbol"!-restore"!-fns} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-set!-definition expr] \item [{\ttfamily symbol!-set!-definition} {\itshape  expr}] \index{{\ttfamily symbol"!-set"!-definition} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-set!-env expr] \item [{\ttfamily symbol!-set!-env} {\itshape  expr}] \index{{\ttfamily symbol"!-set"!-env} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-set!-native expr] \item [{\ttfamily symbol!-set!-native} {\itshape  expr}] \index{{\ttfamily symbol"!-set"!-native} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbol!-value expr] \item [{\ttfamily symbol!-value} {\itshape  expr}] \index{{\ttfamily symbol"!-value} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [symbolp expr] \item [{\ttfamily symbolp} {\itshape  expr}] \index{{\ttfamily symbolp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [system expr] \item [{\ttfamily system} {\itshape  expr}] \index{{\ttfamily system} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [tagbody fexpr] \item [{\ttfamily tagbody} {\itshape  fexpr}] \index{{\ttfamily tagbody} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [tan expr] \item [{\ttfamily tan} {\itshape  expr}] \index{{\ttfamily tan} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [tand expr] \item [{\ttfamily tand} {\itshape  expr}] \index{{\ttfamily tand} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [tanh expr] \item [{\ttfamily tanh} {\itshape  expr}] \index{{\ttfamily tanh} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [terpri expr] \item [{\ttfamily terpri} {\itshape  expr}] \index{{\ttfamily terpri} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [threevectorp expr] \item [{\ttfamily threevectorp} {\itshape  expr}] \index{{\ttfamily threevectorp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [throw fexpr] \item [{\ttfamily throw} {\itshape  fexpr}] \index{{\ttfamily throw} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [time expr] \item [{\ttfamily time} {\itshape  expr}] \index{{\ttfamily time} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [times fexpr] \item [{\ttfamily times} {\itshape  fexpr}] \index{{\ttfamily times} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [times2 expr] \item [{\ttfamily times2} {\itshape  expr}] \index{{\ttfamily times2} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [tmpnam expr] \item [{\ttfamily tmpnam} {\itshape  expr}] \index{{\ttfamily tmpnam} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [trace expr] \item [{\ttfamily trace} {\itshape  expr}] \index{{\ttfamily trace} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [trace!-all expr] \item [{\ttfamily trace!-all} {\itshape  expr}] \index{{\ttfamily trace"!-all} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [traceset expr] \item [{\ttfamily traceset} {\itshape  expr}] \index{{\ttfamily traceset} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [traceset1 expr] \item [{\ttfamily traceset1} {\itshape  expr}] \index{{\ttfamily traceset1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [truename expr] \item [{\ttfamily truename} {\itshape  expr}] \index{{\ttfamily truename} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [truncate expr] \item [{\ttfamily truncate} {\itshape  expr}] \index{{\ttfamily truncate} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [ttab expr] \item [{\ttfamily ttab} {\itshape  expr}] \index{{\ttfamily ttab} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [tyo expr] \item [{\ttfamily tyo} {\itshape  expr}] \index{{\ttfamily tyo} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [undouble!-execute expr] \item [{\ttfamily undouble!-execute} {\itshape  expr}] \index{{\ttfamily undouble"!-execute} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [unfluid expr] \item [{\ttfamily unfluid} {\itshape  expr}] \index{{\ttfamily unfluid} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [unglobal expr] \item [{\ttfamily unglobal} {\itshape  expr}] \index{{\ttfamily unglobal} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [union expr] \item [{\ttfamily union} {\itshape  expr}] \index{{\ttfamily union} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [unless fexpr] \item [{\ttfamily unless} {\itshape  fexpr}] \index{{\ttfamily unless} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [unmake!-global expr] \item [{\ttfamily unmake!-global} {\itshape  expr}] \index{{\ttfamily unmake"!-global} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [unmake!-special expr] \item [{\ttfamily unmake!-special} {\itshape  expr}] \index{{\ttfamily unmake"!-special} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [unreadch expr] \item [{\ttfamily unreadch} {\itshape  expr}] \index{{\ttfamily unreadch} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [untrace expr] \item [{\ttfamily untrace} {\itshape  expr}] \index{{\ttfamily untrace} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [untraceset expr] \item [{\ttfamily untraceset} {\itshape  expr}] \index{{\ttfamily untraceset} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [untraceset1 expr] \item [{\ttfamily untraceset1} {\itshape  expr}] \index{{\ttfamily untraceset1} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [unwind!-protect fexpr] \item [{\ttfamily unwind!-protect} {\itshape  fexpr}] \index{{\ttfamily unwind"!-protect} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [upbv expr] \item [{\ttfamily upbv} {\itshape  expr}] \index{{\ttfamily upbv} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [user!-homedir!-pathname expr] \item [{\ttfamily user!-homedir!-pathname} {\itshape  expr}] \index{{\ttfamily user"!-homedir"!-pathname} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [vectorp expr] \item [{\ttfamily vectorp} {\itshape  expr}] \index{{\ttfamily vectorp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [verbos expr] \item [{\ttfamily verbos} {\itshape  expr}] \index{{\ttfamily verbos} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [when fexpr] \item [{\ttfamily when} {\itshape  fexpr}] \index{{\ttfamily when} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/* fns [where!-was!-that expr] \item [{\ttfamily where!-was!-that} {\itshape  expr}] \index{{\ttfamily where"!-was"!-that} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [window!-heading expr] \item [{\ttfamily window!-heading} {\itshape  expr}] \index{{\ttfamily window"!-heading} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [writable!-libraryp expr] \item [{\ttfamily writable!-libraryp} {\itshape  expr}] \index{{\ttfamily writable"!-libraryp} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [write!-module expr] \item [{\ttfamily write!-module} {\itshape  expr}] \index{{\ttfamily write"!-module} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [wrs expr] \item [{\ttfamily wrs} {\itshape  expr}] \index{{\ttfamily wrs} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [xassoc expr] \item [{\ttfamily xassoc} {\itshape  expr}] \index{{\ttfamily xassoc} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [xcons expr] \item [{\ttfamily xcons} {\itshape  expr}] \index{{\ttfamily xcons} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [xdifference expr] \item [{\ttfamily xdifference} {\itshape  expr}] \index{{\ttfamily xdifference} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [xtab expr] \item [{\ttfamily xtab} {\itshape  expr}] \index{{\ttfamily xtab} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* fns [zerop expr] \item [{\ttfamily zerop} {\itshape  expr}] \index{{\ttfamily zerop} {\itshape  expr}} ~\newline
 * Not yet written
 */

/*! fns [~block]  \item [{\ttfamily !$\sim$block} {\itshape  fexpr}] \index{{\ttfamily "!$\sim$block} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/*! fns [~let]  \item [{\ttfamily !$\sim$let} {\itshape  fexpr}] \index{{\ttfamily "!$\sim$let} {\itshape  fexpr}} ~\newline
 * Not yet written
 */

/*! fns [~tyi]  \item [{\ttfamily !$\sim$tyi} {\itshape  expr}] \index{{\ttfamily "!$\sim$tyi} {\itshape  expr}} ~\newline
 * Not yet written
 */

/* end of tempdoc.c */
