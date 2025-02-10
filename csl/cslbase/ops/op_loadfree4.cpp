// op_loadfree4.cpp

#if defined BYTECODE
            case OP_LOADFREE4:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 4));
                continue;

#elif defined __x86_64__

            case OP_LOADFREE4:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADFREE4:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOADFREE4:
                myabort("Unsupported architecture");

#endif
