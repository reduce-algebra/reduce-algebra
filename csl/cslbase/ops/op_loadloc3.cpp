// loadloc3.cpp $Id$

#if defined BYTECODE
            case OP_LOADLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC3:
                mov(B_reg, A_reg);
                loadloc(A_reg, 3);
                break;

#else
            case OP_LOADLOC3:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc3.cpp
