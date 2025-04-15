// $Id$

// bytes2.cpp                              Copyright (C) 1991-2025 Codemist
//
//
// Bytecode interpreter for Lisp
// This in just the body of the bytecode interpreter function...
//

/**************************************************************************
 * Cright (C) 2025, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       cright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       cright notice, this list of conditions and the following      *
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




#ifdef SIMPLIFIED_MERELY_TO_SERVE_AS_DOCUMENTATION

// The full definition of bytestream_interpret() has a significant body
// of code in it that is guarded by #ifdefs and is often not used - and
// which is certainly not relevant for understanding what it does. This
// includes extra sections of code that perform heavier duty stack
// checking than normal and that can be used when trying to identify
// functions that recurse unduly. There are general debugging-support things
// and features that accumulate statistics about which bytecodes are used
// most. The version here has these "extras" stripped out and alse reduces
// the bulk of comments so that the simplicity of the core behaviour of
// ths function should become more visible.

LispObject bytestream_interpret1(size_t ppc, LispObject lit,
                                 LispObject *entry_stack)
{   LispObject A_reg = nil;
    LispObject r1, r2, r3;
    no_args *f0; one_arg *f1; two_args *f2; three_args *f3; fourup_args *f4up;
    unsigned int fname, w;
    int32_t n, k;
    size_t xppc;

next_ode:
    try
    {   for (;;)
        {   switch (next_byte)
            {
        ... ... ...
#else // SIMPLIFIED_MERELY_TO_SERVE_AS_DOCUMENTATION

LispObject A_reg;
LispObject r1, r2, r3;
no_args *f0;
one_arg *f1;
two_args *f2;
three_args *f3;
fourup_args *f4up;
unsigned int fname, w;
int32_t n, k;
size_t xppc;
//
// I declare all the other variables I need here up at the tof the function
// since at least on some C compilers putting the declarations more locally
// seems to be unexpectedly costly.  In some cases moving the stack pointer
// may be a pain, in others code like
//   { int x; ...} { int x; ... } { int x;  ... }
// end up allocating three stack locations (one for each instance of x) and
// hence makes this function overall have much to big a stack frame.
//
//
// ffname will be the first 31 characters of the name of the function
// that is being interpreted. This is used when you trace things so that
// you get a report of where a function has been called from. At one stage
// I only set this information up when in the slower bootstrap mode, but now
// I have decided to accept the cost at all times so that full tracing
// facilities are always available.
    LispObject ffpname = qpname(lit);
    size_t fflength = (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
    char ffname[32];
    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
    std::memcpy(reinterpret_cast<void *>(&ffname[0]),
                &celt(ffpname, 0), fflength);
    ffname[fflength] = 0;
    debug_record(reinterpret_cast<const char *>(ffname));
//
#ifdef CHECK_STACK
    {   char *my_stack = reinterpret_cast<char *>(&my_stack);
        if (native_stack == nullptr)
            native_stack = native_stack_base = my_stack;
        else if (my_stack + 10000 < native_stack)
        {   native_stack = my_stack;
            trace_printf("\nFunction %s stack depth %d\n",
                         &celt(qpname(lit), 0),
                         native_stack_base - my_stack);
        }
    }
#endif

//
// The byte-stream interpreter here uses the lisp stack and two
// special registers, called A, and B which act as a mini stack.
// Note that it does NOT preserve the stack depth quite the way you
// might have liked because it gets arguments passed on the stack.
// At least maybe!

#ifndef NO_BYTECOUNT
//
// If I am collecting bytecounts I am in the slow version of REDUCE
// with everything bytecoded rather than turned into C. I will view this as
// a debugging as well as a bootstrapping environment, so I will keep more
// information about the call stack.
//
#ifdef ACN
// ... except that I will only go the whole hog if one defines ACN
    callstack = cons_no_gc(lit, callstack);
#endif
#endif
    lit = qenv(lit);
    LispObject codevec = car(lit);
    LispObject litvec = cdr(lit);
#ifndef NO_BYTECOUNT
// Attribute 10-bytecode overhead to entry sequence. This is a pretty
// arbitrary number, but the idea is that when I am profiling I want to
// end up ranking funtions as by their overall contribution to cost.
// If I only counted byte odes obeyed within functions then a
// function that used 2 bytecodes and was called 1 million times would
// be recorded as as more critical than one that used only a single
// bytecode but was called just under 2 million times. The overheads of
// starting up the bytecode interpreter nake that an invalid judgement,
// and the "+10" here is intended to counterbalance it.
// Note that I count "byte odes obeyed" with no attempt to consider
// the fact that some odes are very cheap and some rather expensive. I
// could potentially change the code so that each individual bytecode
// incremented the count by an amount intended to stand for its expected
// cost. I do not think that is worthwhile!
    incCount(basic_elt(litvec, 0), profile_count_mode ? 1 : 10);
#endif
//
    A_reg = nil;
#ifdef CHECK_STACK
    if (reinterpret_cast<char *>(ufringe) <=
        reinterpret_cast<char *>(uheaplimit))
    {   A_reg = cons_gc_test(A_reg);
        errexit();
    }
#ifdef DEBUG
    if (check_stack(reinterpret_cast<char *>(&ffname[0]), __LINE__))
    {   err_printf("\n+++ stack overflow\n");
        return aerror("stack overflow");
    }
#else // DEBUG
    if (check_stack("bytecode_interpreter",__LINE__))
    {   err_printf("\n+++ stack overflow\n");
        return aerror("stack overflow");
    }
#endif // DEBUG
#else // CHECK_STACK
    {   char *p = reinterpret_cast<char *>(&p);
        if (reinterpret_cast<uintptr_t>(p) < C_stackLimit)
        {   err_printf("\n+++ stack overflow\n");
            if (C_stackLimit > 1024*1024) C_stackLimit -= 1024*1024;
            return aerror("stack_overflow");
        }
    }
#endif // CHECK_STACK

next_ode:   // This label is so that I can restart what I am doing
// following a CATCH or to handle UNWIND-PROTECT.
// Here the "try" must NOT preserve the stack pointer!
// I think this may be because of cases like
//    (f a1 a2 a3 (catch ...) a5 a6)
// where when preparing args for f some values go on the (Lisp) stack. Then
// the inline-compiled catch arises. The purpose of the try block here is to
// be able to c with it but if this "try" preserved the stack then maybe
// reaching the end of it would discard stacked arguments and cause trouble?
// Anyway, although I make the default behaviour one when a try block
// preseved the stack I customise this one not to!
#ifdef NO_THROW
    ([&]()->LispObject {
#else
    try { ([&]()->LispObject {
#endif // NO_THROW
// The try block will neeed to c with
// .  Various errors raised by functions called from here: a fragment of
//    backtrace may be called for, and variable bindings undone.
// .  THROW performed by a called function and caught here.
// .  THROW in a called function but not caught here.
// .  UNWIND-PROTECT and a range of exit conditions.
// .  other stack unwinding.
//
// The main scheme will be that if an exception gets back to here
// then I will know where my own part of the stack starts, and even though
// there may be excess items on the stack there will only be values
// SPID_CATCH or SPID_FBIND on there marking places where I can perform
// nice recovery actions, so I can use the procedure unwind_stack that
// p items one at a time looking for those to get back to the state I
// need to be in.
// If I call aerror or aerror1 (etc) inside this try block it merely jumps
// to the end of it.

#ifdef DEBUG
// Let me remind myself once again that on every
// exit from this code region the stack will need unwinding, restoring any
// fluids that have been bound and removing catch frames that are no longer
// needed.
#endif // DEBUG

    for (;;)
    {
#ifndef NO_BYTECOUNT
        if (!profile_count_mode) incCount(basic_elt(litvec, 0));
        total++;
        frequencies[(reinterpret_cast<unsigned char *>(codevec))[ppc]]++;
#endif

//trace_printf("ppc=%d, byte=%.2x\n", ppc, ((unsigned char *)codevec)[ppc]);
//ensure_screen();

#ifdef DEBUG
        if (is_exception(A_reg)) my_abort("exception value not trapped");
        if (is_exception(B_reg)) my_abort("exception value not trapped");
#endif

        switch (next_byte)
        {
//
// I give labels for all 256 possible cases here so that a sufficiently
// clever compiler can understand that there is no "default" that can possibly
// be activated.
//

#endif //  SIMPLIFIED_MERELY_TO_SERVE_AS_DOCUMENTATION

// end of bytes_head.cpp
