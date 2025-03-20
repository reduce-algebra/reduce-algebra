// caarloc0.cpp

#if defined BYTECODE
            case OP_CAARLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                goto caar;

#elif defined __x86_64__

            case OP_CAARLOC0:
                mov(B_reg, A_reg);
                mov(A_reg, ptr(spreg));
                test(A_reg, TAG_BITS);
                jne(carError);
                mov(A_reg, ptr(A_reg));
                test(A_reg, TAG_BITS);
                jne(carError);
                mov(A_reg, ptr(A_reg));
                break;

#elif defined __aarch64__

            case OP_CAARLOC0:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CAARLOC0:
                unfinished("Unsupported architecture");

#endif

// end of caarloc.cpp
