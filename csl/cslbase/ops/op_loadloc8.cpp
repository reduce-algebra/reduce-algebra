// loadloc8.cpp

#if defined BYTECODE
            case OP_LOADLOC8:
                B_reg = A_reg;
                A_reg = stack[-8];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC8:
                mov(B_reg, A_reg);
                mov(A_reg, ptr(spreg, 64*next));
                break;

#elif defined __aarch64__

            case OP_LOADLOC8:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC8:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc8.cpp
