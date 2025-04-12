// cons.cpp $Id$

#if defined BYTECODE
            case OP_CONS:                     // A_reg = cons(B_reg, A_reg);
                A_reg = cons(B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CONS:
                mov(w1, cons);
                JITcall(JITshim2, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_CONS:                      // A_reg = cons(B_reg, A_reg);
                unfinished("Unsupported architecture");

#endif

// end of op_cons.cpp
