// equal.cpp $Id$

#if defined BYTECODE
            case OP_EQUAL:                                  // A = equal(B, A)
                A_reg = SL_OR_CL_EQUAL(B_reg, A_reg) ? lisp_true : nil;
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_EQUAL:
                loadstatic(w, OJITshim2L);
                loadstatic(w1, OJITLequal);  // Either standard or common!
                JITcall(w, A_reg,
                        w1, nilreg, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_EQUAL:                                  // A = equal(B, A)
                unfinished("Unsupported architecture");

#endif

// end of op_equal.cpp
