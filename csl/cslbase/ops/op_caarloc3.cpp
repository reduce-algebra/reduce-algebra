// op_caarloc3.cpp

#if defined BYTECODE
            case OP_CAARLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                goto caar;

#elif defined __x86_64__

            case OP_CAARLOC3:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CAARLOC3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CAARLOC3:
                unfinished("Unsupported architecture");

#endif
