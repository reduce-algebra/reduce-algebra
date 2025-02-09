// op_caarloc1.cpp

#if defined BYTECODE
            case OP_CAARLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                goto caar;

#elif defined __x86_64__

            case OP_CAARLOC1:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CAARLOC1:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CAARLOC1:
                myabort("Unsupported architecture");

#endif
