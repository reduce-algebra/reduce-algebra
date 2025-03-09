// op_loc2loc3.cpp

#if defined BYTECODE
            case OP_LOC2LOC3:
                B_reg = stack[-2];
                A_reg = stack[-3];
                continue;

#elif defined __x86_64__

            case OP_LOC2LOC3:
                cc.mov(B_reg, ptr(spreg, -16));
                cc.mov(A_reg, ptr(spreg, -24));
                break;

#elif defined __aarch64__

            case OP_LOC2LOC3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOC2LOC3:
                unfinished("Unsupported architecture");

#endif

// end of op_loc2loc3.cpp
