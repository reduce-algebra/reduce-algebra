// call1_0.cpp

#if defined BYTECODE
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
                {   stack_restorer saver;
                    STACK_SANITY;
                    *++stack = A_reg; // the argument
                    RECORD_CALL(list2(basic_elt(litvec, 0), A_reg));
                    if (reinterpret_cast<uintptr_t>(stack) >= stackLimit)
                        respond_to_stack_event();
                    A_reg = bytestream_interpret(CELL-TAG_VECTOR, basic_elt(litvec, 0),
                                                 stack-1);
                    errexit();
                }
                continue;

#elif defined __x86_64__

            case OP_CALL1_0:
                mov(w, ptr(nilreg, JIToffset(OJITshim2)));
                mov(w2, ptr(litvec, CELL-TAG_VECTOR));
                mov(w1,
                       ptr(w2, offsetof(Symbol_Head, function1)-TAG_SYMBOL));
                JITcall(w, A_reg,
                       w, w1, w2, A_reg);
                cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                jne(callFailed);
                break;

#elif defined __aarch64__

            case OP_CALL1_0:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL1_0:
                unfinished("Unsupported architecture");

#endif

// end of call0.cpp
