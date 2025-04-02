// loadloc7.cpp $Id$

#if defined BYTECODE
            case OP_LOADLOC7:
                B_reg = A_reg;
                A_reg = stack[-7];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC7:
                mov(B_reg, A_reg);
                loadloc(A_reg, 7);
                break;

#else
            case OP_LOADLOC7:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc7.cpp
