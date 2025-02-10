// op_caarloc0.cpp

#if defined BYTECODE
            case OP_CAARLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                goto caar;

#elif defined __x86_64__

            case OP_CAARLOC0:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CAARLOC0:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CAARLOC0:
                myabort("Unsupported architecture");

#endif
