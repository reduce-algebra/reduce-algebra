// loadlit7.cpp $Id$

#if defined BYTECODE
            case OP_LOADLIT7:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 7);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLIT7:
                mov(B_reg, A_reg);
                loadlit(A_reg, 7);
                break;

#else
            case OP_LOADLIT7:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit7.cpp
