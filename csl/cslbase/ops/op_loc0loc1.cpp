// op_loc0loc1.cpp

#if defined BYTECODE
            case OP_LOC0LOC1:
                B_reg = stack[-0];
                A_reg = stack[-1];
                continue;

#elif defined __x86_64__

            case OP_LOC0LOC1:
                cc.mov(B_reg, ptr(spreg));
                cc.mov(A_reg, ptr(spreg, -8));
                break;

#elif defined __aarch64__

            case OP_LOC0LOC1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOC0LOC1:
                unfinished("Unsupported architecture");

#endif

// end of op_loc0loc1.cpp