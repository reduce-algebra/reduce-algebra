// op_loadloc3.cpp

#if defined BYTECODE
            case OP_LOADLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC3:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg, -24*next));
                break;

#elif defined __aarch64__

            case OP_LOADLOC3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC3:
                unfinished("Unsupported architecture");

#endif
