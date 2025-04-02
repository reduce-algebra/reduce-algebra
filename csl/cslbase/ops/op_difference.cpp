// difference.cpp $Id$

#if defined BYTECODE
            case OP_DIFFERENCE:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   intptr_t nn = int_of_fixnum(B_reg) - int_of_fixnum(A_reg);
                    A_reg = make_lisp_integerptr(nn);
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Difference::op(B_reg, A_reg);
#else // ARITHLIB
                A_reg = difference2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_DIFFERENCE:
                loadstatic(w, OJITshim1);
                loadstatic(w1, OJITtimes2);
                JITcall(w, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_DIFFERENCE:
                unfinished("Unsupported architecture");

#endif

// end of op_difference.cpp
