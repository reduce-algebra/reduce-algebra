// xcons.cpp $Id$

#if defined BYTECODE
            case OP_XCONS:                   // A_reg = cons(A_reg, B_reg);
                A_reg = cons(A_reg, B_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_XCONS:
                mov(w1, cons);
                JITcall(JITshim2, A_reg,
                        w1, A_reg, B_reg);
                JITerrorcheck();
                break;

#else
            case OP_XCONS:                   // A_reg = cons(A_reg, B_reg);
                unfinished("Unsupported architecture");

#endif

// end of op_xcons.cpp
