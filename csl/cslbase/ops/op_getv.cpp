// getv.cpp $Id$

#if defined BYTECODE
            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                A_reg = Lgetv(nil, B_reg, A_reg);
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_GETV:
                mov(w1, Lgetv);
                JITcall(JITshim2L, A_reg,
                        w1, nilreg, B_reg, A_reg);
                JITerrorcheck();
                break;

#else
            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                unfinished("Unsupported architecture");

#endif

// end of op_getv.cpp
