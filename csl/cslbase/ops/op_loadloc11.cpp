// loadloc11.cpp

#if defined BYTECODE
            case OP_LOADLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC11:
                mov(B_reg, A_reg);
                mov(A_reg, ptr(spreg, -88*next));
                break;

#elif defined __aarch64__

            case OP_LOADLOC11:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC11:
                unfinished("Unsupported architecture");

#endif

// end of op_loadloc11.cpp
