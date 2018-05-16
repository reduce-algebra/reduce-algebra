// bytes2.cpp                             Copyright (C) 1991-2017, Codemist
//
//
// Bytecode interpreter for Lisp
// This in just the body of the bytecode interpreter function...
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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


// $Id$

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
// I declare all the other variables I need here up at the top of the function
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
    memcpy((void *)&ffname[0], &celt(ffpname, 0), fflength);
    ffname[fflength] = 0;
    debug_record((const char *)ffname);
//
#ifdef CHECK_STACK
    {   char *my_stack = (char *)&my_stack;
        if (native_stack == NULL) native_stack = native_stack_base = my_stack;
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
//

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
    codevec = qcar(lit);
    litvec = qcdr(lit);
#ifndef NO_BYTECOUNT
// Attribute 30-bytecode overhead to entry sequence. This is a pretty
// arbitrary number, but the idea is that when I am profiling I want to
// end up ranking funtions as by their overall contribution to cost.
// If I only counted byte opcodes obeyed within functions then a
// function that used 2 bytecodes and was called 1 million times would
// be recorded as as more critical than one that used only a single
// bytecode but was called just under 2 million times. The overheads of
// starting up the bytecode interpreter nake that an invalid judgement,
// and the "+30" here is intended to counterbalance it.
    qcount(basic_elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
//
    A_reg = nil;
#ifdef CHECK_STACK
    if ((char *)fringe <= (char *)heaplimit) A_reg = cons_gc_test(A_reg);

#ifdef DEBUG
    if (check_stack((char *)&ffname[0],__LINE__))
    {   err_printf("\n+++ stack overflow\n");
        aerror("stack overflow");
    }
#else
    if (check_stack("bytecode_interpreter",__LINE__))
    {   err_printf("\n+++ stack overflow\n");
        aerror("stack overflow");
    }
#endif
#else // CHECK_STACK
    {   char *p = (char *)&p;
        if (p < C_stack_limit)
        {   err_printf("\n+++ stack overflow\n");
            aerror("stack_overflow");
        }
    }
#endif // CHECK_STACK
#ifdef DEBUG
    jmp_buf *jbsave;
#endif

next_opcode:   // This label is so that I can restart what I am doing
               // following a CATCH or to handle UNWIND-PROTECT.
    my_assert(A_reg != 0, [&]{ trace_printf("A_reg == 0 @ bytes2.cpp line __LINE__\n"); });
    try
    {
// The try block will neeed to cope with
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
// pops items one at a time looking for those to get back to the state I
// need to be in.
// If I call aerror or aerror1 (etc) inside this try block it merely jumps
// to the end of it.

#ifdef DEBUG
// I will also convert signals into exceptions, so that utter disasters
// in things that I call can be at least partially recovered from
    jbsave = global_jb;
    jmp_buf jb;
    switch (setjmp(jb))
    {   default:
        case 1: exit_reason = UNWIND_SIGNAL;
                if (miscflags & HEADLINE_FLAG)
                    err_printf("\n+++ Error %s: ", errorset_msg);
                throw LispSignal();
        case 2: exit_reason = UNWIND_SIGINT;
                if (miscflags & HEADLINE_FLAG)
                    err_printf("\n+++ Error %s: ", errorset_msg);
                throw LispSigint();
        case 0: break;
    }
    global_jb = &jb;
// Now I must remember that on every exit from this region of code I need
// to go "global_jb = jbsave;". I have messy enough handling of exceptions
// here that I will want to track every path explicitly, so I am not using
// RAII to ensure this. So let me remind myself once again that on every
// exit from this code region the stack will need unwindind, restoring any
// fluids that have been bound and removing catch frames that are no longer
// needed.
#endif // DEBUG

    for (;;)
    {
#ifndef NO_BYTECOUNT
        if (!profile_count_mode) qcount(basic_elt(litvec, 0)) += 1;
        total++;
        frequencies[((unsigned char *)codevec)[ppc]]++;
#endif

//trace_printf("ppc=%d, byte=%.2x\n", ppc, ((unsigned char *)codevec)[ppc]);
//ensure_screen();

        switch (next_byte)
        {
//
// I give labels for all 256 possible cases here so that a sufficiently
// clever compiler can understand that there is no "default" that can possibly
// be activated.
//
            case OP_SPARE:
                continue; // used on a temporary basis as LABEL

            default:
//
// Here I have an unrecognised opcode - the result of a compiler error
//
                err_printf("\nUnrecognized opcode byte %x\n", ((unsigned char *)codevec)[ppc-1]);
                aerror("compiler failure");

            case OP_ONEVALUE:
// ONEVALUE is here to support a proposed re-write of the multiple values
// handling scheme.
                exit_count = 1;
                continue;

            case OP_LOC0EXIT:
// If I execute this opcode then I will have followed a path that will have
// executed previous opcodes to restore fluids etc. entry_stack is where the
// stack needs to be so that arguments have been popped as necessary.
                A_reg = stack[0];
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
#endif

#ifdef DEBUG
                global_jb = jbsave;
#endif
                return A_reg;


            case OP_LOC1EXIT:
                A_reg = stack[-1];
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
#endif
#ifdef DEBUG
                global_jb = jbsave;
#endif
                return A_reg;


            case OP_LOC2EXIT:
                A_reg = stack[-2];
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
#endif
#ifdef DEBUG
                global_jb = jbsave;
#endif
                return A_reg;

            case OP_NILEXIT:
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
#endif
#ifdef DEBUG
                global_jb = jbsave;
#endif
                return onevalue(nil);

            case OP_FREEBIND:
                do_freebind(basic_elt(litvec, next_byte));
                continue;

            case OP_FREERSTR:
                do_freerstr();
                continue;

            case OP_PVBIND:
                do_pvbind(A_reg, B_reg);
                continue;

            case OP_PVRESTORE:
                do_pvrestore();
                continue;

            case OP_STOREFREE:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   STACK_SANITY;
                    push(A_reg);
                    print_traceset(current_byte, A_reg);
                    pop(A_reg);
                }
                qvalue(basic_elt(litvec, next_byte)) = A_reg;  // store into special var
                continue;

            case OP_STOREFREE1:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   STACK_SANITY;
                    push(A_reg);
                    print_traceset(1, A_reg);
                    pop(A_reg);
                }
                qvalue(basic_elt(litvec, 1)) = A_reg;
                continue;

            case OP_STOREFREE2:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   STACK_SANITY;
                    push(A_reg);
                    print_traceset(2, A_reg);
                    pop(A_reg);
                }
                qvalue(basic_elt(litvec, 2)) = A_reg;
                continue;

            case OP_STOREFREE3:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                {   STACK_SANITY;
                    push(A_reg);
                    print_traceset(3, A_reg);
                    pop(A_reg);
                }
                qvalue(basic_elt(litvec, 3)) = A_reg;
                continue;

            case OP_PUSHNILS:
                n = next_byte;
                for (k=0; k<n; k++) push(nil);
                continue;

            case OP_VNIL:
                B_reg = A_reg;
                A_reg = nil;
                continue;

            case OP_SWOP:
                r1 = B_reg;
                B_reg = A_reg;
                A_reg = r1;
                continue;

            case OP_NCONS:                          // A_reg = cons(A_reg, nil);
                push(B_reg);
                A_reg = ncons(A_reg);
                pop(B_reg);
                continue;

            case OP_XCONS:                          // A_reg = cons(A_reg, B_reg);
                A_reg = cons(A_reg, B_reg);
                continue;

            case OP_LIST2:                  // A_reg = cons(B_reg, cons(A_reg, nil));
                A_reg = list2(B_reg, A_reg);
                continue;

            case OP_ACONS:                  // A_reg = acons(pop(), B_reg, A_reg);
                // = (pop() . B) . A
                pop(r1);
                A_reg = acons(r1, B_reg, A_reg);
                continue;

//
// For the next two opcodes the first argument to the current function
// must have been an environment pointer as set up with CLOSURE. I do
// not check that I have a closure object - perhaps I can excuse that by
// claiming that all creation and management of encapsulated closures
// will have been introduced by the compiler, which I propose to trust!
// (actually as of April 2002 I think there may be bugs I need to fix...)
// Note that this has STILL not been heavily tested!
            case OP_LOADLEX:
                r1 = elt(stack[1-(int)next_byte], 0);
                B_reg = A_reg;
                w = next_byte;             // Number of levels to chain
                while (w != 0) r1 = ((LispObject *)r1)[1], w--;
                A_reg = ((LispObject *)r1)[next_byte];
                continue;

            case OP_STORELEX:
                r1 = elt(stack[1-(int)next_byte], 0);
                w = next_byte;             // Number of levels to chain
                while (w != 0) r1 = ((LispObject *)r1)[1], w--;
                ((LispObject *)r1)[next_byte] = A_reg;
                continue;

            case OP_CLOSURE:
                push2(B_reg, A_reg);
//
// This will be the address where the first arg of this function lives on
// the stack.  It provides a hook for the called function to access lexical
// variables.
//
                w = next_byte;
                A_reg = encapsulate_sp(&stack[-2-(int)w]);
                pop(B_reg);
                A_reg = list2star(cfunarg, B_reg, A_reg);
                pop(B_reg);
                continue;

            case OP_BIGSTACK:               // LOADLOC, STORELOC, CLOSURE etc
                //
                // This opcode allows me to support functions that use up to
                // 2047-deep stack frames using LOADLEX and STORELEX, or
                // up to 4095 deep if just using LOADLOC and STORELOC. I hope
                // that such cases are very uncommon, but examples have been
                // shown to me where my previous limit of 256-item frames was
                // inadequate. The BIGSTACK opcode is followed by a byte that
                // contains a few bits selecting which operation is to be
                // performed, plus an extension to the address byte that follows.
                //
                w = next_byte;             // contains sub-opcode
                switch (w & 0xc0)
                {   case 0x00:                  // LOADLOC extended
                        B_reg = A_reg;
                        w = (w & 0x3f) << 8;
                        A_reg = stack[-(int)(w + next_byte)];
                        continue;
                    case 0x40:                  // STORELOC extended
                        w = (w & 0x3f) << 8;
                        stack[-(int)(w + next_byte)] = A_reg;
                        continue;
                    case 0x80:                  // CLOSURE extended
                        push2(B_reg, A_reg);
                        w = ((w & 0x3f) << 8) + next_byte;
                        A_reg = encapsulate_sp(&stack[-2-(int)w]);
                        pop(B_reg);
                        A_reg = list2star(cfunarg, B_reg, A_reg);
                        pop(B_reg);
                        continue;
                    case 0xc0:                  // LOADLEX, STORELEX extended
                        n = next_byte;
                        k = next_byte;
                        n = (n << 4) | (k >> 4);
                        k = ((k & 0xf) << 8) | next_byte;
                        r1 = elt(stack[1-n], 0);
                        B_reg = A_reg;
                        n = w & 0x1f;
                        while (n != 0) r1 = ((LispObject *)r1)[1], n--;
                        if ((w & 0x20) == 0) A_reg = ((LispObject *)r1)[k];
                        else ((LispObject *)r1)[k] = A_reg;
                        continue;
                }

            case OP_LIST2STAR:              // A_reg = list2!*(pop(), B_reg, A_reg);
                // = pop() . (B . A)
                pop(r1);
                A_reg = list2star(r1, B_reg, A_reg);
                continue;

            case OP_LIST3:                  // A_reg = list3(pop(), B_reg, A_reg);
                // = pop() . (B . (A . nil))
                pop(r1);
                A_reg = list3(r1, B_reg, A_reg);
                continue;

            case OP_ADD1:
                if (is_fixnum(A_reg) && A_reg != MOST_POSITIVE_FIXNUM)
                {   A_reg += 0x10;
                    continue;
                }
//
// I drop through in the case of floating, bignum or error arithmetic.
//
                A_reg = plus2(A_reg, fixnum_of_int(1));
                continue;

            case OP_PLUS2:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   intptr_t nn = int_of_fixnum(A_reg) + int_of_fixnum(B_reg);
                    A_reg = make_lisp_integerptr(nn);
                    continue;
                }
//
// I drop through in the case of floating, bignum or error arithmetic.
//
                A_reg = plus2(B_reg, A_reg);
                continue;

            case OP_SUB1:
                if (is_fixnum(A_reg) && A_reg != MOST_NEGATIVE_FIXNUM)
                {   A_reg -= 0x10;
                    continue;
                }
//
// I drop through in the case of floating, bignum or error arithmetic.
//
                A_reg = plus2(A_reg, fixnum_of_int(-1));
                continue;

            case OP_DIFFERENCE:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   intptr_t nn = int_of_fixnum(B_reg) - int_of_fixnum(A_reg);
                    A_reg = make_lisp_integerptr(nn);
                    continue;
                }
                A_reg = difference2(B_reg, A_reg);
                continue;

            case OP_TIMES2:
//
// I do not in-line even the integer case here, since overflow checking
// is a slight mess.
//
                A_reg = times2(B_reg, A_reg);
                continue;

            case OP_LESSP:
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg < A_reg;
                else
                {   w = lessp2(B_reg, A_reg);
                }
                A_reg = Lispify_predicate(w);
                continue;

            case OP_GREATERP:
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg > A_reg;
                else
                {   w = lessp2(A_reg, B_reg);
                }
                A_reg = Lispify_predicate(w);
                continue;

            case OP_FLAGP:                                  // A = flagp(B, A)
#ifdef COMMON
                A_reg = get(B_reg, A_reg, unset_var);
                if (A_reg == unset_var) A_reg = nil;
                else A_reg = lisp_true;
                continue;
#else
                A_reg = Lflagp(nil, B_reg, A_reg);
                continue;
#endif

            case OP_APPLY1:
                if (is_symbol(B_reg))   // can optimise this case, I guess
                {   f1 = qfn1(B_reg);
                    push(B_reg);
                    if ((qheader(B_reg) & SYM_TRACED) != 0)
                        A_reg = traced_call1(basic_elt(litvec, 0), f1, B_reg, A_reg);
                    else A_reg = f1(B_reg, A_reg);
                    popv(1);
                    continue;
                }
                push(B_reg);
                A_reg = ncons(A_reg);
                pop(B_reg);
                A_reg = apply(B_reg, A_reg, nil, basic_elt(litvec, 0));
                continue;

            case OP_APPLY2:
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   f2 = qfn2(r2);
                    popv(1);
                    if ((qheader(r2) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r2, B_reg, A_reg);
                    else A_reg = f2(r2, B_reg, A_reg);
                    continue;
                }
// Here the stack has fn on the top and the 2 args are in B_reg, A_reg
                A_reg = list2(B_reg, A_reg);
                pop(r2);
                A_reg = apply(r2, A_reg, nil, basic_elt(litvec, 0));
                continue;

            case OP_APPLY3:
// Somewhat beware here - This is (apply3 F a1 a2 a3) or
// (funcall F a1 a2 a3) and a3 will be passed directly as is in the stack.
// In particular a general call to an "apply3" function would have passed in
// effect (apply3' F a1 a2 [a3]) with the fourth argument passed as a list.
// When I use the bytecode op I do not do that.
                pop(r1);
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   f3 = qfn3(r2);
                    if ((qheader(r2) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r2, r1, B_reg, A_reg);
                    else A_reg = f3(r2, r1, B_reg, A_reg);
                    popv(1);
                    continue;
                }
                A_reg = list3(stack[-1], B_reg, A_reg);
                pop(r2);
                A_reg = apply(r2, A_reg, nil, basic_elt(litvec, 0));
                continue;

            case OP_APPLY4:
                pop2(r1, r3);
// The 4 arguments are now r3, r1, B_reg, A_reg in that order, and as with
// APPLY3 I do not wrap the final two arguments up in a list but instead pass
// them individually.
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   push4(r2, r3, r1, B_reg);
                    A_reg = ncons(A_reg);    // Make 4th arg a list!
                    pop4(B_reg, r1, r3, r2);
                    f4up = qfn4up(r2);
                    if ((qheader(r2) & SYM_TRACED) != 0)
                        A_reg = traced_call4up(basic_elt(litvec, 0), f4up, r2, r3, r1, B_reg, A_reg);
                    else A_reg = f4up(r2, r3, r1, B_reg, A_reg);
                    popv(1);
                    continue;
                }
                A_reg = list4(r3, r1, B_reg, A_reg);
                pop(r2);
                A_reg = apply(r2, A_reg, nil, basic_elt(litvec, 0));
                continue;

#ifdef COMMON
#define SL_OR_CL_EQUAL cl_equal
#else
#define SL_OR_CL_EQUAL equal
#endif

            case OP_EQUAL:                                  // A = equal(B, A)
                A_reg = SL_OR_CL_EQUAL(B_reg, A_reg) ? lisp_true : nil;
                continue;

            case OP_EQ:                                     // A = eq(B, A)
                if (A_reg == B_reg) A_reg = lisp_true;
                else A_reg = nil;
                continue;

            case OP_NUMBERP:                                // A = numberp(A)
                A_reg = Lispify_predicate(is_number(A_reg));
                continue;

            case OP_QGETV:                          // A_reg = getv(B_reg, A_reg)
//
// Note - this is an UNCHECKED vector access, used when carcheck(nil) has
// been selected because the user prefers speed to security.  This is in
// here because the Reduce factoriser test uses getv VERY heavily indeed
// and both use of a special opcode here and removal of the checking make
// noticable differences to performance.
//
                A_reg = *(LispObject *)(
                            (char *)B_reg +
                            (CELL - TAG_VECTOR) +
                            (CELL*int_of_fixnum(A_reg)));
                continue;

            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                A_reg = Lgetv(nil, B_reg, A_reg);
                continue;

            case OP_QGETVN:                         // A_reg = getv(A_reg, n)
//
// Note - this is an UNCHECKED vector access, and only applicable to simple
// vectors that hold general Lisp data.  The offset is passed in the
// byte stream.  It is expected that it will help with code that passes
// around vectors of guff and use (getv vvv 0) etc (aka svref) to
// grab stuff out.
//
                A_reg = *(LispObject *)(
                            (char *)A_reg + (CELL - TAG_VECTOR) + (CELL*(next_byte)));
                continue;

            case OP_EQCAR:
                if (car_legal(B_reg) && A_reg == qcar(B_reg)) A_reg = lisp_true;
                else A_reg = nil;
                continue;

            case OP_LENGTH:
                A_reg = Llength(nil, A_reg);
                continue;

//
// The following combinations feel a little odd, but ONE of them showed up
// very clearly in REDUCE tests, and adding the other few seems liable
// (on sentiment, not measurement!) to make reasonable sense.
//
            case OP_LOC0LOC1:
                B_reg = stack[-0];
                A_reg = stack[-1];
                continue;

            case OP_LOC1LOC2:
                B_reg = stack[-1];
                A_reg = stack[-2];
                continue;

            case OP_LOC2LOC3:
                B_reg = stack[-2];
                A_reg = stack[-3];
                continue;

            case OP_LOC1LOC0:
                B_reg = stack[-1];
                A_reg = stack[-0];
                continue;

            case OP_LOC2LOC1:
                B_reg = stack[-2];
                A_reg = stack[-1];
                continue;

            case OP_LOC3LOC2:
                B_reg = stack[-3];
                A_reg = stack[-2];
                continue;

            case OP_CDRLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                continue;

            case OP_CDRLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                continue;

            case OP_CDRLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                continue;

            case OP_CDRLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                continue;

            case OP_CDRLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                continue;

            case OP_CDRLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                continue;

            case OP_CAARLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                goto caar;

            case OP_CAARLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                goto caar;

            case OP_CAARLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                goto caar;

            case OP_CAARLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                goto caar;

            case OP_CAAR:
            caar:
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                continue;

            case OP_CADR:
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                continue;

            case OP_CDAR:
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                continue;

            case OP_CDDR:
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                continue;


//
// The ICASE opcode is followed by a byte (n say) that indicates the number
// of cases that follow, followed by n+1 double-byte label values.
// If these addresses are called L<dflt>, L<0>, L<1>, ... L<n-1> then if the
// A register contains an integer in the range 0 <= k < n then control is
// transferred to L<k>, while if the A register does not hold an integer or
// if its value is out of range then control goes to L<dflt>.
//
            case OP_ICASE:
                w = next_byte;
                if (is_fixnum(A_reg) &&
                    (n = int_of_fixnum(A_reg)) >= 0 &&
                    n < (int)w) ppc += 2*n + 2;
                w = next_byte;
//
// I support backwards jumps here by setting their top bit. At present I do
// poll for interrupts on a backwards case-branch. And the encoding used means
// that case branches can not reach quite as far as regular jumps.
//
                if (w & 0x80) ppc = ppc - (((w & 0x7f) << 8) + ((unsigned char *)codevec)[ppc]);
                else ppc = ppc + (w << 8) + ((unsigned char *)codevec)[ppc];
                continue;

//
// There are a bunch of special-case jumps here - they are only
// provided with the variants that jump forwards by small offsets,
// but are expected to pick up a useful number of cases (for both speed and
// compactness) all the same.
//
            case OP_JUMPL0NIL:
                xppc = ppc;
                ppc++;
                if (stack[0] == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL0T:
                xppc = ppc;
                ppc++;
                if (stack[0] != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL1NIL:
                xppc = ppc;
                ppc++;
                if (stack[-1] == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL1T:
                xppc = ppc;
                ppc++;
                if (stack[-1] != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL2NIL:
                xppc = ppc;
                ppc++;
                if (stack[-2] == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL2T:
                xppc = ppc;
                ppc++;
                if (stack[-2] != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL3NIL:
                xppc = ppc;
                ppc++;
                if (stack[-3] == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL3T:
                xppc = ppc;
                ppc++;
                if (stack[-3] != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL4NIL:
                xppc = ppc;
                ppc++;
                if (stack[-4] == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL4T:
                xppc = ppc;
                ppc++;
                if (stack[-4] != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL0ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[0])) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL0NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[0])) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL1ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-1])) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL1NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-1])) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL2ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-2])) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL2NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-2])) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL3ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-3])) short_jump(ppc, xppc);
                continue;

            case OP_JUMPL3NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-3])) short_jump(ppc, xppc);
                continue;

            case OP_JUMPST0NIL:
                xppc = ppc;
                ppc++;
                if ((stack[0] = A_reg) == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPST0T:
                xppc = ppc;
                ppc++;
                if ((stack[0] = A_reg) != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPST1NIL:
                xppc = ppc;
                ppc++;
                if ((stack[-1] = A_reg) == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPST1T:
                xppc = ppc;
                ppc++;
                if ((stack[-1] = A_reg) != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPST2NIL:
                xppc = ppc;
                ppc++;
                if ((stack[-2] = A_reg) == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPST2T:
                xppc = ppc;
                ppc++;
                if ((stack[-2] = A_reg) != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREE1NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 1)) == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREE1T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 1)) != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREE2NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 2)) == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREE2T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 2)) != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREE3NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 3)) == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREE3T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 3)) != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREE4NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 4)) == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREE4T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 4)) != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLIT1EQ:
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, 1) == A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLIT1NE:
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, 1) != A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLIT2EQ:
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, 2) == A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLIT2NE:
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, 2) != A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLIT3EQ:
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, 3) == A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLIT3NE:
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, 3) != A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLIT4EQ:
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, 4) == A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLIT4NE:
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, 4) != A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREENIL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, w)) == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFREET:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, w)) != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLITEQ:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, w) == A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPLITNE:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (basic_elt(litvec, w) != A_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPB1NIL:
                f1 = one_arg_functions[next_byte];
                A_reg = f1(nil, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPB1T:
                f1 = one_arg_functions[next_byte];
                A_reg = f1(nil, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPB2NIL:
                f2 = two_arg_functions[next_byte];
                A_reg = f2(nil, B_reg, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPB2T:
                f2 = two_arg_functions[next_byte];
                A_reg = f2(nil, B_reg, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (car_legal(A_reg) &&
                    basic_elt(litvec, w) == qcar(A_reg)) short_jump(ppc, xppc);
                continue;

            case OP_JUMPNEQCAR:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!car_legal(A_reg) ||
                    basic_elt(litvec, w) != qcar(A_reg)) short_jump(ppc, xppc);
                continue;

            case OP_JUMPFLAGP:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!symbolp(A_reg)) continue;
                else
#ifdef COMMON
                {   r1 = get(A_reg, basic_elt(litvec, w), unset_var);
                    if (r1 != unset_var) short_jump(ppc, xppc);
                    continue;
                }
#else
                r1 = Lflagp(nil, A_reg, basic_elt(litvec, w));
                if (r1 != nil) short_jump(ppc, xppc);
                continue;
#endif

            case OP_JUMPNFLAGP:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!symbolp(A_reg))
                {   short_jump(ppc, xppc);
                    continue;
                }
                else
#ifdef COMMON
                {   r1 = get(A_reg, basic_elt(litvec, w), unset_var);
                    if (r1 == unset_var) short_jump(ppc, xppc);
                    continue;
                }
#else
                    r1 = Lflagp(nil, A_reg, basic_elt(litvec, w));
                if (r1 == nil) short_jump(ppc, xppc);
                continue;
#endif

//
// Now the general jumps.  Each has four variants - forwards and backwards
// and long and short offsets.  Backwards jumps poll for interrupts so that
// all loops will be interruptible.
//

            case OP_JUMPATOM:
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) short_jump(ppc, xppc);
                continue;

            case OP_JUMPATOM_B:
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) short_jump_back(ppc, xppc, A_reg);
                continue;

            case OP_JUMPNATOM:
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) short_jump(ppc, xppc);
                continue;

            case OP_JUMPNATOM_B:
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) short_jump_back(ppc, xppc, A_reg);
                continue;

            case OP_JUMPEQ:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPEQ_B:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) short_jump_back(ppc, xppc, A_reg);
                continue;

            case OP_JUMPNE:
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) short_jump(ppc, xppc);
                continue;

            case OP_JUMPNE_B:
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) short_jump_back(ppc, xppc, A_reg);
                continue;

            case OP_JUMPEQUAL:
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump(ppc, xppc);
                continue;

            case OP_JUMPEQUAL_B:
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump_back(ppc, xppc, A_reg);
                continue;

            case OP_JUMPNEQUAL:
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump(ppc, xppc);
                continue;

            case OP_JUMPNEQUAL_B:
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump_back(ppc, xppc, A_reg);
                continue;

            case OP_JUMP:
                ppc++;
                short_jump(ppc, ppc-1);
                continue;

            case OP_JUMP_B:
                ppc++;
                short_jump_back(ppc, ppc-1, A_reg);
                continue;

            case OP_JUMPATOM_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) long_jump(w, ppc, xppc);
                continue;

            case OP_JUMPATOM_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) long_jump_back(w, ppc, xppc, A_reg);
                continue;

            case OP_JUMPNATOM_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) long_jump(w, ppc, xppc);
                continue;

            case OP_JUMPNATOM_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) long_jump_back(w, ppc, xppc, A_reg);
                continue;

            case OP_JUMPEQ_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) long_jump(w, ppc, xppc);
                continue;

            case OP_JUMPEQ_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) long_jump_back(w, ppc, xppc, A_reg);
                continue;

            case OP_JUMPNE_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) long_jump(w, ppc, xppc);
                continue;

            case OP_JUMPNE_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) long_jump_back(w, ppc, xppc, A_reg);
                continue;

            case OP_JUMPEQUAL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump(w, ppc, xppc);
                continue;

            case OP_JUMPEQUAL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump_back(w, ppc, xppc, A_reg);
                continue;

            case OP_JUMPNEQUAL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump(w, ppc, xppc);
                continue;

            case OP_JUMPNEQUAL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump_back(w, ppc, xppc, A_reg);
                continue;

            case OP_JUMP_L:
                w = next_byte;
                ppc++;
                long_jump(w, ppc, ppc-1);
                continue;

            case OP_JUMP_BL:
                w = next_byte;
                ppc++;
                long_jump_back(w, ppc, ppc-1, A_reg);
                continue;

            case OP_CATCH:
                w = (unsigned int)(ppc + ((unsigned char *)codevec)[ppc]);
                ppc++;
                goto catcher;

            case OP_CATCH_B:
                w = (unsigned int)(ppc - ((unsigned char *)codevec)[ppc]);
                ppc++;
                goto catcher;

            case OP_CATCH_L:
                w = next_byte;
                w = (unsigned int)(ppc + (w << 8) + ((unsigned char *)codevec)[ppc]);
                ppc++;
                goto catcher;

            case OP_CATCH_BL:
                w = next_byte;
                w = (unsigned int)(ppc - ((w << 8) + ((unsigned char *)codevec)[ppc]));
                ppc++;
            catcher:
                A_reg = cons(A_reg, catch_tags);
                catch_tags = A_reg;
                push3(fixnum_of_int(w+1), catch_tags, SPID_CATCH);
                continue;

            case OP_UNCATCH:
                popv(1); pop(r1); popv(1);
                catch_tags = qcdr(r1);
                qcar(r1) = r1; qcdr(r1) = nil;
                continue;

            case OP_PROTECT:
//
// This is used to support UNWIND-PROTECT.
// This needs to save A_reg, all the multiple-result registers,
// and the exit_count. Also something to indicate that there had not been
// an error.
//
                popv(1); pop(r1); popv(1);
                catch_tags = qcdr(r1);
                qcar(r1) = r1; qcdr(r1) = nil;
                A_reg = Lmv_list(nil, A_reg);
                push3(nil, fixnum_of_int(UNWIND_NULL), A_reg);
                continue;

            case OP_UNPROTECT:
//
// This must restore all the results (including exit_count). If the
// PROTECT had been done by an unwinding then exit_reason and exit_tag
// must also be restored, and the unwind condition must be re-instated.
//
                pop3(A_reg, B_reg, exit_tag);
                exit_reason = int_of_fixnum(B_reg);
// Here I have multiple values to restore.
                exit_count = 0;
                B_reg = A_reg;
                A_reg = nil;
                if (consp(B_reg))
                {   A_reg = qcar(B_reg);
                    B_reg = qcdr(B_reg);
                    exit_count++;
                    while (consp(B_reg))
                    {   (&mv_1)[exit_count++] = qcar(B_reg);
                        B_reg = qcdr(B_reg);
                    }
                }
                exit_value = A_reg;
                assert(A_reg != 0);
// Here after performing the unwind-protect code I must restore a throw
// action that was the same sort as the one that caused me to arrive. I
// think that will involve switching on exit_reason and trying to re-create
// the correct state. In native C++ situations I would be able to go just
// "throw;" without an operand except that in this code I am now outside
// the block that was the signal handler.
                switch (exit_reason)
                {
                case UNWIND_NULL:      continue;
                case UNWIND_GO:        throw LispGo();
                case UNWIND_RETURN:    throw LispReturnFrom();
                case UNWIND_THROW:     throw LispThrow();
                case UNWIND_RESTART:   throw LispRestart();
                case UNWIND_RESOURCE:  throw LispResource();
                case UNWIND_SIGNAL:    throw LispSignal();
                case UNWIND_SIGINT:    throw LispSigint();
                case UNWIND_ERROR:     throw LispError();
                case UNWIND_FNAME:     throw LispError();
                case UNWIND_UNWIND:    throw LispError();
                default:               throw LispError();
                }

            case OP_THROW:
                pop(r1);       // the tag to throw to
                for (r2 = catch_tags; r2!=nil; r2=qcdr(r2))
                    if (r1 == qcar(r2)) break;
                if (r2==nil) aerror1("throw: tag not found", r1);
                exit_tag = r2;
                exit_value = A_reg;
                assert(A_reg != 0);
                exit_reason = UNWIND_THROW;
                throw LispThrow();

//
// I expect that calling functions with 0, 1, 2 or 3 arguments will
// be enormously important for Lisp, and so separate opcodes are provided
// for these cases.  The operand in each case selects the function to be
// called, which MUST be a symbol (loaded from the literal vector),
// and arguments are taken from A and B as necessary.  If several
// arguments are needed the first argument will be loaded first, and thus
// it is the LAST argument that end up in the A register.
//

            case OP_CALL0_0:      // Calling myself...
                fname = 0;
                goto call0;

            case OP_CALL0_1:
                fname = 1;
                goto call0;

            case OP_CALL0_2:
                fname = 2;
                goto call0;

            case OP_CALL0_3:
                fname = 3;
                goto call0;

            case OP_CALL0:
                fname = next_byte;
            call0:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
//
// NB I set fname to be the literal-vector offset in the line above so that
// it will be possible to find the name of the function that was called
// if I have to display a backtrace.
//
                f0 = qfn0(r1);
// CALL0:  A=fn()
                if ((qheader(r1) & SYM_TRACED) != 0)
                    A_reg = traced_call0(basic_elt(litvec, 0), f0, r1);
                else A_reg = f0(r1);
                assert(A_reg != 0);
                continue;


            case OP_JCALL:
// This version has the number of args and the target packed into a
// single operand byte.  Cases where the offset does not fit into this
// will go via BIGCALL.
// Note that the argument count can only ever be 0, 1, 2, 3 or 4, so
// codes 5, 6 and 7 ar enot used. Hmmm I could provide a JCALL2R option
// if I wanted!
                w = next_byte;
                fname = w & 0x1f;
                w = (w >> 5) & 0x7;
                switch (w)
                {   case 0: goto jcall0;
                    case 1: goto jcall1;
                    case 2: goto jcall2;
                    case 3: goto jcall3;
                    default:goto jcall4;
                }

            jcall0: r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f0 = qfn0(r1);
// The issue here is cases such as
//    (de f1 (x) (f2 x))
//    (de f2 (x) (f1 x))
// where the bodies of the functions so not do enough work that polling
// for interrupts or for window-system updates will happen. Thus it seems
// I need to perform a polling operation as part of the tail-call sequence.
                push(r1);
                poll_jump_back(A_reg);
                pop(r1);
// If I have an (untraced) tailcall to a bytecoded function I can just reset
// some pointers and go back to the top of the code of the bytecode
// interpreter.
                if (f0 == bytecoded_0 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   lit = qenv(r1);
                    codevec = qcar(lit);
                    litvec = qcdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    memcpy((void *)&ffname[0], &celt(ffpname, 0), fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    ppc = BPS_DATA_OFFSET;
#ifndef NO_BYTECOUNT
                    qcount(basic_elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
                    continue;
                }
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
                if ((qheader(r1) & SYM_TRACED) != 0)
                    A_reg = traced_call0(basic_elt(litvec, 0), f0, r1);
                else A_reg = f0(r1);
#ifdef DEBUG
                global_jb = jbsave;
#endif
                return A_reg;
#else
#ifdef DEBUG
                global_jb = jbsave;
#endif
                if ((qheader(r1) & SYM_TRACED) != 0)
                    return traced_call0(basic_elt(litvec, 0), f0, r1);
                else return f0(r1);
#endif

            jcall1:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f1 = qfn1(r1);
                push(r1);
                poll_jump_back(A_reg);
                pop(r1);
                if (f1 == bytecoded_1 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   lit = qenv(r1);
                    codevec = qcar(lit);
                    litvec = qcdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    memcpy((void *)&ffname[0], &celt(ffpname, 0), fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    push(A_reg);
                    ppc = BPS_DATA_OFFSET;
#ifndef NO_BYTECOUNT
                    qcount(basic_elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
                    continue;
                }
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
                if ((qheader(r1) & SYM_TRACED) != 0)
                    A_reg = traced_call1(basic_elt(litvec, 0), f1, r1, A_reg);
                else A_reg = f1(r1, A_reg);
#ifdef DEBUG
                global_jb = jbsave;
#endif
                return A_reg;
#else
#ifdef DEBUG
                global_jb = jbsave;
#endif
                if ((qheader(r1) & SYM_TRACED) != 0)
                    return traced_call1(basic_elt(litvec, 0), f1, r1, A_reg);
                else return f1(r1, A_reg);
#endif


            jcall2:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f2 = qfn2(r1);
                push(r1);
                poll_jump_back(A_reg);
                pop(r1);
                if (f2 == bytecoded_2 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   lit = qenv(r1);
                    codevec = qcar(lit);
                    litvec = qcdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    memcpy((void *)&ffname[0], &celt(ffpname, 0), fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    push2(B_reg, A_reg);
                    ppc = BPS_DATA_OFFSET;
#ifndef NO_BYTECOUNT
                    qcount(basic_elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
                    continue;
                }
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
                if ((qheader(r1) & SYM_TRACED) != 0)
                    A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, B_reg, A_reg);
                else A_reg = f2(r1, B_reg, A_reg);
#ifdef DEBUG
                global_jb = jbsave;
#endif
                return A_reg;
#else
#ifdef DEBUG
                global_jb = jbsave;
#endif
                if ((qheader(r1) & SYM_TRACED) != 0)
                    return traced_call2(basic_elt(litvec, 0), f2, r1, B_reg, A_reg);
                else return f2(r1, B_reg, A_reg);
#endif

            jcall3:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f3 = qfn3(r1);
                push(r1);
                poll_jump_back(A_reg);
                pop2(r1, r2);
                if (f3 == bytecoded_3 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   lit = qenv(r1);
                    codevec = qcar(lit);
                    litvec = qcdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    memcpy((void *)&ffname[0], &celt(ffpname, 0), fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    push3(r2, B_reg, A_reg);
                    ppc = BPS_DATA_OFFSET;
#ifndef NO_BYTECOUNT
                    qcount(basic_elt(litvec, 0)) += profile_count_mode ? 1 : 30;
#endif
                    continue;
                }
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
                if ((qheader(r1) & SYM_TRACED) != 0)
                    A_reg = traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                else A_reg = f3(r1, r2, B_reg, A_reg);
#ifdef DEBUG
                global_jb = jbsave;
#endif
                return A_reg;
#else
#ifdef DEBUG
                global_jb = jbsave;
#endif
                if ((qheader(r1) & SYM_TRACED) != 0)
                    return traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                else return f3(r1, r2, B_reg, A_reg);
#endif

            jcall4:
// fname is the offset in the literal vector of the function to call.
// The args are in stack[-1], stack[0], B_reg, A_reg
// In some other JCALL cases I optimise if the called function is
// bytecoded. I have not done that here (yet?).
                poll_jump_back(A_reg);
                pop2(r2, r1);
                B_reg = list3star(r1, r2, B_reg, A_reg);
                A_reg = basic_elt(litvec, fname);
                debug_record_symbol(A_reg);
                A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
#endif
#ifdef DEBUG
                global_jb = jbsave;
#endif
                return A_reg;

            case OP_BIGCALL:
//
// This provides for calls (and a few other operations!) where the literal
// to be referenced is beyond position 256 in the literal vector. The
// encoding is that BIGCALL is followed by two bytes. The top half of the
// first of these is a sub opcode, while the remaining 12 bits provide
// support for literal vectors with up to 4096 elements. At present I
// will just not support code bigger than that. Note that if I were feeling
// keen here I could easily arrange that the 12-bit offset here started at
// 256 and went on upwards. But for simplicity in a first version I will
// leave a bit of redundancy.
//
                w = next_byte;
                fname = next_byte + ((w & 0xf) << 8);
                switch (w >> 4)
                {   case 0: goto call0;
                    case 1: goto call1;
                    case 2: goto call2;
                    case 3: goto call3;
                    case 4:
// Here I write out a variant on the CALL4 code.
                        B_reg = list3star(stack[-1], stack[0], B_reg, A_reg);
                        popv(2);
                        A_reg = basic_elt(litvec, fname);
                        A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                        ppc++;
                        continue;

                    case 5: goto call2r;
// sub-opcodes 6 and 7 are use for LOADFREE and STOREFREE - this is a bit
// odd but fits the required operations tightly into the opcode map.
                    case 6:
                        B_reg = A_reg;
                        A_reg = qvalue(basic_elt(litvec, fname));
                        continue;
                    case 7:
                        if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                        {   push(A_reg);
                            print_traceset(fname, A_reg);
                            pop(A_reg);
                        }
                        qvalue(basic_elt(litvec, fname)) = A_reg;  // store into special var
                        continue;
// Now tailcalls.
                    case 8: goto jcall0;
                    case 9: goto jcall1;
                    case 10:goto jcall2;
                    case 11:goto jcall3;
                    case 12:goto jcall4;
// Codes 13 and 14 do FREEBIND and LITGET, which completes the list of
// byte operations that access big literals.
                    case 13:do_freebind(basic_elt(litvec, fname));
                        continue;
                    case 14:B_reg = A_reg;
                        A_reg = basic_elt(litvec, fname);
                        A_reg = get(B_reg, A_reg, nil);
                        continue;
// Code 15 is LOADLIT with a long offset, which may be used as an alternative
// to the LOADLIT/QGETVN mechanism that I otherwise support.
                    case 15:B_reg = A_reg;
                        A_reg = basic_elt(litvec, fname);
                        continue;
                }

            case OP_CALL1_0:
//
// Note that this is spotted and treated as a direct call to the
// current function (because offset zero in the literal vector is reserved
// for the name of the function).  I can NOT avoid the overhead of stacking
// and restoring codevec and litvec here, even the values used in the called
// function are the same as the present ones, because the lower level call
// might itself do a JCALL and corrupt them!  Also I know that the current
// function is bytecoded, so I avoid the overhead of (re-)discovering that.
//
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACED) != 0)
                {   fname = 0;
                    goto call1;
                }
                push3(codevec, litvec, A_reg); // the argument
                if (--countdown < 0) deal_with_tick();
                if (++reclaim_trigger_count == reclaim_trigger_target ||
                    stack >= stacklimit)
                    reclaim(nil, "stack", GC_STACK, 0);
                A_reg = bytestream_interpret(CELL-TAG_VECTOR, basic_elt(litvec, 0), stack-1);
                pop2(litvec, codevec);
                assert(A_reg != 0);
                continue;

            case OP_CALL1_1:
                fname = 1;
                goto call1;

            case OP_CALL1_2:
                fname = 2;
                goto call1;

            case OP_CALL1_3:
                fname = 3;
                goto call1;

            case OP_CALL1_4:
                fname = 4;
                goto call1;

            case OP_CALL1_5:
                fname = 5;
                goto call1;

            case OP_CALL1:
                fname = next_byte;
            call1:  r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f1 = qfn1(r1);
// CALL1:   A=fn(A);
                if ((qheader(r1) & SYM_TRACED) != 0)
                    A_reg = traced_call1(basic_elt(litvec, 0), f1, r1, A_reg);
                else A_reg = f1(r1, A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CALL2_0:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACED) != 0)
                {   fname = 0;
                    goto call2;
                }
                push4(codevec, litvec, B_reg, A_reg);
                if (--countdown < 0) deal_with_tick();
                if (++reclaim_trigger_count == reclaim_trigger_target ||
                    stack >= stacklimit)
                    reclaim(nil, "stack", GC_STACK, 0);
                A_reg = bytestream_interpret(CELL-TAG_VECTOR, basic_elt(litvec, 0), stack-2);
                pop2(litvec, codevec);
                assert(A_reg != 0);
                continue;

            case OP_CALL2_1:
                fname = 1;
                goto call2;

            case OP_CALL2_2:
                fname = 2;
                goto call2;

            case OP_CALL2_3:
                fname = 3;
                goto call2;

            case OP_CALL2_4:
                fname = 4;
                goto call2;

            case OP_CALL2:
                fname = next_byte;
            call2:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f2 = qfn2(r1);
// CALL2:   A=fn(B,A);
                if ((qheader(r1) & SYM_TRACED) != 0)
                    A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, B_reg, A_reg);
                else A_reg = f2(r1, B_reg, A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CALL2R:
                fname = next_byte;
            call2r:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f2 = qfn2(r1);
// CALL2R:   A=fn(A,B); NOTE arg order reversed
                if ((qheader(r1) & SYM_TRACED) != 0)
                    A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, A_reg, B_reg);
                else A_reg = f2(r1, A_reg, B_reg);
                assert(A_reg != 0);
                continue;

            case OP_CALL3:
                fname = next_byte;
            call3:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f3 = qfn3(r1);
// CALL3:   A=fn(pop(),B,A);
                pop(r2);
                if ((qheader(r1) & SYM_TRACED) != 0)
                    A_reg = traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                else A_reg = f3(r1, r2, B_reg, A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CALL4:
// All but the last two args have been pushed onto the stack already.
// The last two are in A and B.
                pop2(r2, r1);
                B_reg = list3star(r1, r2, B_reg, A_reg);
// Here the post-byte indicates the function to be called.
                A_reg = basic_elt(litvec, ((unsigned char *)codevec)[ppc]);
                A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                assert(A_reg != 0);
                ppc++;
                continue;

            case OP_BUILTIN0:
// At present this uses the "old" scheme for functions that do not take
// arguments that passes the integer 0 to tell them of the lack of args
// actually passed.
                f0 = no_arg_functions[next_byte];
                debug_record_int("BUILTIN0", previous_byte);
// BUILTIN0:  A=fn()
                if (no_arg_traceflags[previous_byte])
                    A_reg = traced_call0(basic_elt(litvec, 0), f0,
                        make_undefined_symbol(no_arg_names[previous_byte]));
                else A_reg = f0(nil);
                assert(A_reg != 0);
                continue;

            case OP_BUILTIN1:
                f1 = one_arg_functions[next_byte];
                debug_record_int("BUILTIN1", previous_byte);
// BUILTIN1:   A=fn(A);
                if (one_arg_traceflags[previous_byte])
                    A_reg = traced_call1(basic_elt(litvec, 0), f1,
                        make_undefined_symbol(one_arg_names[previous_byte]),
                        A_reg);
                A_reg = f1(nil, A_reg);
                assert(A_reg != 0);
                continue;

            case OP_BUILTIN2:
                f2 = two_arg_functions[next_byte];
                debug_record_int("BUILTIN2", previous_byte);
// BUILTIN2:   A=fn(B,A);
                if (two_arg_traceflags[previous_byte])
                    A_reg = traced_call2(basic_elt(litvec, 0), f2,
                        make_undefined_symbol(two_arg_names[previous_byte]),
                        B_reg, A_reg);
                A_reg = f2(nil, B_reg, A_reg);
                assert(A_reg != 0);
                continue;

            case OP_BUILTIN2R:
                f2 = two_arg_functions[next_byte];
                debug_record_int("BUILTIN2R", previous_byte);
// BUILTIN2R:   A=fn(A,B); NOTE arg order reversed
                if (two_arg_traceflags[previous_byte])
                    A_reg = traced_call2(basic_elt(litvec, 0), f2,
                        make_undefined_symbol(two_arg_names[previous_byte]),
                        A_reg, B_reg);
                else A_reg = f2(nil, A_reg, B_reg);
                assert(A_reg != 0);
                continue;

            case OP_BUILTIN3:
                f3 = three_arg_functions[next_byte];
                debug_record_int("BUILTIN3", previous_byte);
// CALL3:   A=fn(pop(),B,A);
                pop(r1);
                if (three_arg_traceflags[previous_byte])
                    A_reg = traced_call3(basic_elt(litvec, 0), f3,
                        make_undefined_symbol(three_arg_names[previous_byte]),
                        r1, B_reg, A_reg);
                else A_reg = f3(nil, r1, B_reg, A_reg);
                assert(A_reg != 0);
                continue;

//
// Now here in a neat block I will have the cases that seem to occur most
// frequently, at least when I tested things running REDUCE. By collecting
// these together I hope to (slightly) improve the cache locality behaviour
// for this code - maybe...
//
            case OP_LOADLOC:
                B_reg = A_reg;
                A_reg = stack[-(int)next_byte];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC6:
                B_reg = A_reg;
                A_reg = stack[-6];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC7:
                B_reg = A_reg;
                A_reg = stack[-7];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC8:
                B_reg = A_reg;
                A_reg = stack[-8];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC9:
                B_reg = A_reg;
                A_reg = stack[-9];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC10:
                B_reg = A_reg;
                A_reg = stack[-10];
                assert(A_reg != 0);
                continue;

            case OP_LOADLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                assert(A_reg != 0);
                continue;

            case OP_CAR:
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC6:
                B_reg = A_reg;
                A_reg = stack[-6];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC7:
                B_reg = A_reg;
                A_reg = stack[-7];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC8:
                B_reg = A_reg;
                A_reg = stack[-8];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC9:
                B_reg = A_reg;
                A_reg = stack[-9];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC10:
                B_reg = A_reg;
                A_reg = stack[-10];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CARLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                if (car_legal(A_reg)) A_reg = qcar(A_reg);
                else A_reg = carerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_CDR:
                if (car_legal(A_reg)) A_reg = qcdr(A_reg);
                else A_reg = cdrerror(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_STORELOC:
                stack[-(int)next_byte] = A_reg;
// NB this opcode does not pop the A/B stack
                continue;

            case OP_STORELOC0:
                stack[-0] = A_reg;
                continue;

            case OP_STORELOC1:
                stack[-1] = A_reg;
                continue;

            case OP_STORELOC2:
                stack[-2] = A_reg;
                continue;

            case OP_STORELOC3:
                stack[-3] = A_reg;
                continue;

            case OP_STORELOC4:
                stack[-4] = A_reg;
                continue;

            case OP_STORELOC5:
                stack[-5] = A_reg;
                continue;

            case OP_STORELOC6:
                stack[-6] = A_reg;
                continue;

            case OP_STORELOC7:
                stack[-7] = A_reg;
                continue;

            case OP_LOADLIT:
//
// Associated with each body of byte-codes there is a literal vector,
// and this opcode loads values from same.  The literal vector has a
// header word and is tagged as a Lisp vector.
//
                B_reg = A_reg;
                A_reg = basic_elt(litvec, next_byte);
                continue;

            case OP_LOADLIT1:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 1);
                continue;

            case OP_LOADLIT2:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 2);
                continue;

            case OP_LOADLIT3:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 3);
                continue;

            case OP_LOADLIT4:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 4);
                continue;

            case OP_LOADLIT5:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 5);
                continue;

            case OP_LOADLIT6:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 6);
                continue;

            case OP_LOADLIT7:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 7);
                continue;

            case OP_LOADFREE:
//
// Load the value of a free (GLOBAL, SPECIAL, FLUID) variable
//
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, next_byte));
                continue;

            case OP_LOADFREE1:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 1));
                continue;

            case OP_LOADFREE2:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 2));
                continue;

            case OP_LOADFREE3:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 3));
                continue;

            case OP_LOADFREE4:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 4));
                continue;

            case OP_JUMPNIL:
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPNIL_B:
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump_back(ppc, xppc, A_reg);
                continue;

            case OP_JUMPT:
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump(ppc, xppc);
                continue;

            case OP_JUMPT_B:
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump_back(ppc, xppc, A_reg);
                continue;

            case OP_JUMPNIL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == nil) ppc = ppc + ((w << 8) + ((unsigned char *)codevec)[xppc]);
                continue;

            case OP_JUMPNIL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == nil)
                {   ppc = ppc - ((w << 8) + ((unsigned char *)codevec)[xppc]);
                    poll_jump_back(A_reg);
                }
                continue;

            case OP_JUMPT_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != nil) ppc = ppc + ((w << 8) + ((unsigned char *)codevec)[xppc]);
                continue;

            case OP_JUMPT_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != nil)
                {   ppc = ppc - ((w << 8) + ((unsigned char *)codevec)[xppc]);
                    poll_jump_back(A_reg);
                }
                continue;

            case OP_EXIT:
//
// Here I assume that exit_count has been set up already. Note also that
// there is no need to do any LOSE operations just before an EXIT since the
// stack gets reset automatically here.
//
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = qcdr(callstack);
#endif
#ifdef DEBUG
                global_jb = jbsave;
#endif
                return A_reg;


            case OP_PUSH:
                assert(A_reg != 0);
                push(A_reg);
                continue;

            case OP_PUSHNIL:
                push(nil);
                continue;

            case OP_PUSHNIL2:
                push2(nil, nil);
                continue;

            case OP_PUSHNIL3:
                push3(nil, nil, nil);
                continue;

            case OP_POP:
                B_reg = A_reg;
                pop(A_reg);
                assert(A_reg != 0);
                continue;

            case OP_LOSE:
                popv(1);
                continue;

            case OP_LOSE2:
                popv(2);
                continue;

            case OP_LOSE3:
                popv(3);
                continue;

            case OP_LOSES:
                popv(next_byte);
                continue;

            case OP_CONS:                           // A_reg = cons(B_reg, A_reg);
                A_reg = cons(B_reg, A_reg);
                continue;

//
// FASTGET n
//     0 <= n < 64       (GET A_reg property_n)
//    64 <= n < 128      (GET A_reg property_n B_reg)
//   128 <= n < 192      (FLAGP A_reg property_n)
//   192 <= n < 256      not used at present.
//
            case OP_FASTGET:
                w = next_byte;
#ifdef RECORD_GET
                n = 0;
#endif
                if (symbolp(A_reg))
                {   r1 = qfastgets(A_reg);
                    if (r1 == nil)
                    {   if (w & 0x40) A_reg = B_reg;
                        else A_reg = nil;
                    }
                    else
                    {   A_reg = basic_elt(r1, w & 0x3f);
                        if (A_reg == SPID_NOPROP)
                        {   if (w & 0x40) A_reg = B_reg;
                            else A_reg = nil;
#ifdef RECORD_GET
                            n = 1;
#endif
                        }
                        else if (w & 0x80) A_reg = lisp_true;
                    }
                }
                else A_reg = nil;
#ifdef RECORD_GET
                record_get(basic_elt(fastget_names, w & 0x7f), n);
#endif
                continue;

            case OP_LITGET:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, next_byte);
                A_reg = get(B_reg, A_reg, nil);
                continue;

            case OP_GET:                                    // A = get(B, A)
                A_reg = get(B_reg, A_reg, nil);
                assert(A_reg != 0);
                continue;

        }

//*****************************************************************************
// End of the main block of opcodes.
//*****************************************************************************
    } // end of switch block
    } // end of try block
    catch (LispException e)
    {
// What follows is my current guess for a good diagnostic...
        if (SHOW_FNAME)
        {   err_printf("Inside: ");
            loop_print_error(basic_elt(litvec, 0));
            err_printf("\n");
        }
// Here I need to scan down the current stack-frame looking for either a
// CATCH or an UNWIND-PROTECT marker.
        for (;;)
        {   unwind_stack(entry_stack, true);
            if (stack == entry_stack) throw;   // re-throw!
// Here I have a CATCH/UNWIND record within the current function
            pop2(r1, r2);
// If the tag matches exit_tag then I must reset pc based on offset (r2)
// and continue. NB need to restore A_reg from exit_value.
            w = int_of_fixnum(r2);
            if (qcar(r1) == SPID_PROTECT)
            {   // This is an UNWIND catcher
                push2(exit_tag, fixnum_of_int(exit_reason));
                A_reg = Lmv_list(nil, exit_value);
                push(A_reg);
                ppc = w;
                A_reg = exit_value;
                goto next_opcode;
            }
            else if (exit_reason == UNWIND_THROW && r1 == exit_tag)
            {   ppc = w;
                A_reg = exit_value;
                goto next_opcode;
            }
        }
    }


// end of bytes2.cpp
