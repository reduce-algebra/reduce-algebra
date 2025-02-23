// op_loadloc9.cpp

#if defined BYTECODE
            case OP_LOADLOC9:
                B_reg = A_reg;
                A_reg = stack[-9];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC9:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg, -72*next));
                break;

#elif defined __aarch64__

            case OP_LOADLOC9:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC9:
                unfinished("Unsupported architecture");

#endif
