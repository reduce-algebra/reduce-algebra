// loc2loc1.cpp

#if defined BYTECODE
            case OP_LOC2LOC1:
                B_reg = stack[-2];
                A_reg = stack[-1];
                continue;

#elif defined __x86_64__

            case OP_LOC2LOC1:
                mov(B_reg, ptr(spreg, -16));
                mov(A_reg, ptr(spreg, -8));
                break;

#elif defined __aarch64__

            case OP_LOC2LOC1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOC2LOC1:
                unfinished("Unsupported architecture");

#endif

// end of loc2loc1.cpp
