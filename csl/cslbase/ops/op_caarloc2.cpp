// caarloc2.cpp

#if defined BYTECODE
            case OP_CAARLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                goto caar;

#elif defined __x86_64__

            case OP_CAARLOC2:
                mov(B_reg, A_reg);
                mov(A_reg, ptr(spreg, -16));
                test(A_reg, TAG_BITS);
                jne(carError);
                mov(A_reg, ptr(A_reg));
                test(A_reg, TAG_BITS);
                jne(carError);
                mov(A_reg, ptr(A_reg));
                break;

#elif defined __aarch64__

            case OP_CAARLOC2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CAARLOC2:
                unfinished("Unsupported architecture");

#endif

// end of caarloc2.cpp
