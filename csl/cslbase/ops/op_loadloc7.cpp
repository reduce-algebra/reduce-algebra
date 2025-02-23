// op_loadloc7.cpp

#if defined BYTECODE
            case OP_LOADLOC7:
                B_reg = A_reg;
                A_reg = stack[-7];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC7:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg, -56*next));
                break;

#elif defined __aarch64__

            case OP_LOADLOC7:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC7:
                unfinished("Unsupported architecture");

#endif
