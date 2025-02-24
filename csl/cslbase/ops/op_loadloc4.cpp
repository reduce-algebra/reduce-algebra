// op_loadloc4.cpp

#if defined BYTECODE
            case OP_LOADLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC4:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg, -32*next));
                break;

#elif defined __aarch64__

            case OP_LOADLOC4:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC4:
                unfinished("Unsupported architecture");

#endif
