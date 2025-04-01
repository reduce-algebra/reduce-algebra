// loadloc5.cpp $Id$

#if defined BYTECODE
            case OP_LOADLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLOC5:
                mov(B_reg, A_reg);
                loadloc(A_reg, 5);
                break;

#elif defined __aarch64__

            case OP_LOADLOC5:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC5:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc5.cpp
