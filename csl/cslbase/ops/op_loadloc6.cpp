// loadloc6.cpp $Id$

#if defined BYTECODE
            case OP_LOADLOC6:
                B_reg = A_reg;
                A_reg = stack[-6];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC6:
                mov(B_reg, A_reg);
                loadloc(A_reg, 6);
                break;

#else
            case OP_LOADLOC6:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc6.cpp
