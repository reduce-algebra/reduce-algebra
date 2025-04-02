// loadlit6.cpp $Id$

#if defined BYTECODE
            case OP_LOADLIT6:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 6);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLIT6:
                mov(B_reg, A_reg);
                loadlit(A_reg, 6);
                break;

#else
            case OP_LOADLIT6:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit6.cpp
