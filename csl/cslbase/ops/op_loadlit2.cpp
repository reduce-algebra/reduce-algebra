// op_loadlit2.cpp

#if defined BYTECODE
            case OP_LOADLIT2:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 2);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT2:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADLIT2:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOADLIT2:
                myabort("Unsupported architecture");

#endif
