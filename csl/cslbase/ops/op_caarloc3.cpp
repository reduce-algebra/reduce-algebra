// caarloc3.cpp

#if defined BYTECODE
            case OP_CAARLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                goto caar;

#elif defined __x86_64__

            case OP_CAARLOC3:
                mov(B_reg, A_reg);
                mov(A_reg, ptr(spreg, -24));
                test(A_reg, TAG_BITS);
                jne(carError);
                mov(A_reg, ptr(A_reg));
                test(A_reg, TAG_BITS);
                jne(carError);
                mov(A_reg, ptr(A_reg));
                break;

#elif defined __aarch64__

            case OP_CAARLOC3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CAARLOC3:
                unfinished("Unsupported architecture");

#endif

// end of caarloc3.cpp
