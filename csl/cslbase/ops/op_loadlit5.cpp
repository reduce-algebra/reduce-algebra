// op_loadlit5.cpp

#if defined BYTECODE
            case OP_LOADLIT5:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 5);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT5:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADLIT5:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOADLIT5:
                myabort("Unsupported architecture");

#endif
