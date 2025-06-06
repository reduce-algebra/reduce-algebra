// $Id$

#if defined BYTECODE
            case OP_CALL2R:
                fname = next_byte;
            call2r:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f2 = qfn2(r1);
// CALL2R:   A=fn(A,B); NOTE arg order reversed
                {   RECORD_CALL(list3(r1, A_reg, B_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, A_reg, B_reg);
                    else A_reg = f2(r1, A_reg, B_reg);
                }
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__
            case OP_CALL2R:
                next = bytes[ppc++];
                loadlit(w2, next);
                loadfromsymbol(w1, w2, Ofunction2);
                JITcall(JITshim2L, A_reg,
                        w1, w2, A_reg, B_reg);
                JITerrorcheck();
                break;

#else
            case OP_CALL2R:
                unfinished("Unsupported architecture");

#endif

// end of call2r.cpp
