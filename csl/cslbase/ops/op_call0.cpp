// op_call0.cpp

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
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL0:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL0:
                unfinished("Unsupported architecture");

#endif
