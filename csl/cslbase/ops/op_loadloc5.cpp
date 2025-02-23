// op_loadloc5.cpp

#if defined BYTECODE
            case OP_LOADLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC5:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg, -40*next));
                break;

#elif defined __aarch64__

            case OP_LOADLOC5:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC5:
                unfinished("Unsupported architecture");

#endif
