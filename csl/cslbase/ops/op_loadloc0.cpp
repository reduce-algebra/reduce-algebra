// op_loadloc0.cpp

#if defined BYTECODE
            case OP_LOADLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC0:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg));
                break;

#elif defined __aarch64__

            case OP_LOADLOC0:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC0:
                unfinished("Unsupported architecture");

#endif
