// op_caarloc2.cpp

#if defined BYTECODE
            case OP_CAARLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                goto caar;

#elif defined __x86_64__

            case OP_CAARLOC2:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CAARLOC2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CAARLOC2:
                unfinished("Unsupported architecture");

#endif
