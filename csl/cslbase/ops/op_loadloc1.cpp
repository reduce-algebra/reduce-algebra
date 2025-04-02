// loadloc1.cpp $Id$

#if defined BYTECODE
            case OP_LOADLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC1:
                mov(B_reg, A_reg);
                loadloc(A_reg, 1);
                break;

#else
            case OP_LOADLOC1:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc1.cpp
