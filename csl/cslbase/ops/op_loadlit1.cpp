// op_loadlit1.cpp

#if defined BYTECODE
            case OP_LOADLIT1:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 1);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT1:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADLIT1:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOADLIT1:
                myabort("Unsupported architecture");

#endif
