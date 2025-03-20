// call0.cpp

#if defined BYTECODE
            case OP_CALL0:
                fname = next_byte;
            call0:
                r1 = basic_elt(litvec, fname);
                {   debug_record_symbol(r1);
//
// NB I set fname to be the literal-vector offset in the line above so that
// it will be possible to find the name of the function that was called
// if I have to display a backtrace.
//
                    RECORD_CALL(ncons(r1));
                    f0 = qfn0(r1);
// CALL0:  A=fn()
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call0(basic_elt(litvec, 0), f0, r1);
                    else A_reg = f0(r1);
                }
                errexit();
                continue;


#elif defined __x86_64__

            case OP_CALL0:
                next = bytes[ppc++];
                mov(w, ptr(nilreg, JIToffset(OJITshim1)));
                mov(w1, ptr(litvec, 8*next+CELL-TAG_VECTOR));
// w1 is now the symbol that names the function to be called. Now fetch
// from that the entrypoint to be used when it is a function of 0 args.
                mov(w1,
                       ptr(w1, offsetof(Symbol_Head, function0)-TAG_SYMBOL));
                JITcall(w, A_reg,
                       w1);
                cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                jne(callFailed);
                break;

#elif defined __aarch64__

            case OP_CALL0:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL0:
                unfinished("Unsupported architecture");

#endif

// end of call0.cpp
