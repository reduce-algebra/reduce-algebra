// op_loc1loc0.cpp

#if defined BYTECODE
            case OP_LOC1LOC0:
                B_reg = stack[-1];
                A_reg = stack[-0];
                continue;

#elif defined __x86_64__
            case OP_LOC1LOC0:
                cc.mov(B_reg, ptr(spreg, -8));
                cc.mov(A_reg, ptr(spreg));
                break;

#elif defined __aarch64__

            case OP_LOC1LOC0:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOC1LOC0:
                unfinished("Unsupported architecture");

#endif

// end of op_loc1log0.cpp