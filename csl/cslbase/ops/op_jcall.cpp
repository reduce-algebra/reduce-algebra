// jcall.cpp $Id$

#if defined BYTECODE
            case OP_JCALL:
// This version has the number of args and the target packed into a
// single rand byte.  Cases where the offset does not fit into this
// will go via BIGCALL.
// Note that the argument count can only ever be 0, 1, 2, 3 or 4, so
// codes 5, 6 and 7 are not used. Hmmm I could provide a JCALL2R ion
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
                errexit();
// The issue here is cases such as
//    (de f1 (x) (f2 x))
//    (de f2 (x) (f1 x))
// where the bodies of the functions so not do enough work that polling
// for interrupts or for window-system updates will happen. Thus it seems
// I need to perform a polling ration as part of the tail-call sequence.
                poll_jump_back(A_reg);
// If I have an (untraced) tailcall to a bytecoded function I can just reset
// some pointers and go back to the tof the code of the bytecode
// interpreter.
                if (f0 == bytecoded_0 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   RECORD_TAILCALL(ncons(r1));
                    lit = qenv(r1);
                    codevec = car(lit);
                    litvec = cdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    std::memcpy(reinterpret_cast<void *>(&ffname[0]), &celt(ffpname, 0),
                                fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    ppc = BPS_DATA_OFFSET;
#ifndef NO_BYTECOUNT
// Here I treat this in the statistics as a single increment of the
// counter whether I am counting just function entries or the total
// number of bytes executed. Well it is a little more complicated than
// that. If this is a "JCALL self" and I am only counting function entries
// then I will not increment the count, because this just counts as a jump
// back to the tof the current procedure. However a JCALL to any other
// function will be counted.
                    if (!profile_count_mode || fname != 0)
                        incCount(basic_elt(litvec, 0));
#endif
                    continue;
                }
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
                {   RECORD_CALL(ncons(r1));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call0(basic_elt(litvec, 0), f0, r1);
                    else A_reg = f0(r1);
                }
                errexit();
//              return A_reg;
                return nil;
#else
                {   RECORD_CALL(ncons(r1));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call0(basic_elt(litvec, 0), f0, r1);
                    else A_reg = f0(r1);
                }
                return nil;
#endif

            jcall1:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f1 = qfn1(r1);
                poll_jump_back(A_reg);
                if (f1 == bytecoded_1 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   RECORD_TAILCALL(list2(r1, A_reg));
                    lit = qenv(r1);
                    codevec = car(lit);
                    litvec = cdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    std::memcpy(reinterpret_cast<void *>(&ffname[0]), &celt(ffpname, 0),
                                fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    *++stack = A_reg;
                    ppc = BPS_DATA_OFFSET;
#ifndef NO_BYTECOUNT
                    if (!profile_count_mode || fname != 0)
                      incCount(basic_elt(litvec, 0));
#endif
                    continue;
                }
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
                {   RECORD_CALL(list2(r1, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call1(basic_elt(litvec, 0), f1, r1, A_reg);
                    else A_reg = f1(r1, A_reg);
                }
//              return A_reg;
                return nil;
#else
                {   RECORD_CALL(list2(r1, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call1(basic_elt(litvec, 0), f1, r1, A_reg);
                    else A_reg = f1(r1, A_reg);
                }
                return nil;
#endif


            jcall2:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f2 = qfn2(r1);
                poll_jump_back(A_reg);
                if (f2 == bytecoded_2 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   RECORD_TAILCALL(list3(r1, B_reg, A_reg));
                    lit = qenv(r1);
                    codevec = car(lit);
                    litvec = cdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    std::memcpy(reinterpret_cast<void *>(&ffname[0]), &celt(ffpname, 0),
                                fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    *++stack = B_reg; *++stack = A_reg;
                    ppc = BPS_DATA_OFFSET;
#ifndef NO_BYTECOUNT
                    if (!profile_count_mode || fname != 0)
                        incCount(basic_elt(litvec, 0));
#endif
                    continue;
                }
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
                {   RECORD_CALL(list3(r1, B_reg, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, B_reg, A_reg);
                    else A_reg = f2(r1, B_reg, A_reg);
                }
//              return A_reg;
                return nil;
#else
                {   RECORD_CALL(list3(r1, B_reg, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, B_reg, A_reg);
                    else A_reg = f2(r1, B_reg, A_reg);
                }
                return nil;
#endif

            jcall3:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f3 = qfn3(r1);
                poll_jump_back(A_reg);
                r2 = *stack--;
                if (f3 == bytecoded_3 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   RECORD_TAILCALL(list4(r1, r2, B_reg, A_reg));
                    lit = qenv(r1);
                    codevec = car(lit);
                    litvec = cdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    std::memcpy(reinterpret_cast<void *>(&ffname[0]), &celt(ffpname, 0),
                                fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    *++stack = r2; *++stack = B_reg; *++stack = A_reg;
                    ppc = BPS_DATA_OFFSET;
#ifndef NO_BYTECOUNT
                    if (!profile_count_mode || fname != 0)
                        incCount(basic_elt(litvec, 0));
#endif
                    continue;
                }
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
                {   RECORD_CALL(list4(r1, r2, B_reg, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                    else A_reg = f3(r1, r2, B_reg, A_reg);
                }
//              return A_reg;
                return nil;
#else
                {   RECORD_CALL(list4(r1, r2, B_reg, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                    else A_reg = f3(r1, r2, B_reg, A_reg);
                }
                return nil;
#endif

            jcall4:
// fname is the offset in the literal vector of the function to call.
// The args are in stack[-1], stack[0], B_reg, A_reg
// In some other JCALL cases I imise if the called function is
// bytecoded. I have not done that here (yet?).
                r2 = *stack--; r1 = *stack--;
                B_reg = list3star(r1, r2, B_reg, A_reg);
                A_reg = basic_elt(litvec, fname);
                debug_record_symbol(A_reg);
                A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                stack = entry_stack;
#ifndef NO_BYTECOUNT
                if (callstack != nil) callstack = cdr(callstack);
#endif
//              return A_reg;
                return nil;

#elif defined __x86_64__

            case OP_JCALL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JCALL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JCALL:
                unfinished("Unsupported architecture");

#endif

// end of op_jcall.cpp
