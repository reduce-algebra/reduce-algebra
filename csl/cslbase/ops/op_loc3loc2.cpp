// op_loc3loc2.cpp

#if defined BYTECODE
            case OP_LOC3LOC2:
                B_reg = stack[-3];
                A_reg = stack[-2];
                continue;

#elif defined __x86_64__

            case OP_LOC3LOC2:
                cc.mov(B_reg, ptr(spreg, -24));
                cc.mov(A_reg, ptr(spreg, -16));
                break;

#elif defined __aarch64__

            case OP_LOC3LOC2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOC3LOC2:
                unfinished("Unsupported architecture");

#endif

// end of op_loc3loc2.cpp
