// op_loadloc2.cpp

#if defined BYTECODE
            case OP_LOADLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC2:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg, -16*next));
                break;

#elif defined __aarch64__

            case OP_LOADLOC2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLOC2:
                unfinished("Unsupported architecture");

#endif
