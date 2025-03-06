// op_caarloc3.cpp

#if defined BYTECODE
            case OP_CAARLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                goto caar;

#elif defined __x86_64__

            case OP_CAARLOC3:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(spreg, -24));
                cc.test(A_reg, TAG_BITS);
                cc.jne(carError);
                cc.mov(A_reg, ptr(A_reg));
                cc.test(A_reg, TAG_BITS);
                cc.jne(carError);
                cc.mov(A_reg, ptr(A_reg));
                break;

#elif defined __aarch64__

            case OP_CAARLOC3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CAARLOC3:
                unfinished("Unsupported architecture");

#endif

// end of op_caarloc3.cpp
