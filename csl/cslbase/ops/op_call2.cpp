// $Id$

#if defined BYTECODE
            case OP_CALL2:
                fname = next_byte;
            call2:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f2 = qfn2(r1);
// CALL2:   A=fn(B,A);
                {
                    RECORD_CALL(list3(r1, B_reg, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, B_reg, A_reg);
                    else A_reg = f2(r1, B_reg, A_reg);
                }
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL2:
                next = bytes[ppc++];
                lispcall2(next);
                break;

#else
            case OP_CALL2:
                unfinished("Unsupported architecture");

#endif

// end of call2.cpp
