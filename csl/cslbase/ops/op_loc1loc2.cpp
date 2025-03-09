// op_loc1loc2.cpp

#if defined BYTECODE
            case OP_LOC1LOC2:
                B_reg = stack[-1];
                A_reg = stack[-2];
                continue;

#elif defined __x86_64__

            case OP_LOC1LOC2:
                cc.mov(B_reg, ptr(spreg, -8));
                cc.mov(A_reg, ptr(spreg, -16));
                break;

#elif defined __aarch64__

            case OP_LOC1LOC2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOC1LOC2:
                unfinished("Unsupported architecture");

#endif

// end of op_loc1loc2.cpp
