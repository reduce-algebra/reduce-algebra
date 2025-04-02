// loadloc9.cpp $Id$

#if defined BYTECODE
            case OP_LOADLOC9:
                B_reg = A_reg;
                A_reg = stack[-9];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC9:
                mov(B_reg, A_reg);
                loadloc(A_reg, 9);
                break;

#else
            case OP_LOADLOC9:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc9.cpp
