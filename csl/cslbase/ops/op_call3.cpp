// $Id$

#if defined BYTECODE
            case OP_CALL3:
                fname = next_byte;
            call3:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f3 = qfn3(r1);
// CALL3:   A=fn(p),B,A);
                r2 = *stack--;
                {   RECORD_CALL(list4(r1, r2, A_reg, B_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                    else A_reg = f3(r1, r2, B_reg, A_reg);
                }
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL3:
                next = bytes[ppc++];
                lispcall3(next);
                break;

#else
            case OP_CALL3:
                unfinished("Unsupported architecture");

#endif

// end of op_call3.cpp
