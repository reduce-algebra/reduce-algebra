// op_loadloc11.cpp

#if defined BYTECODE
            case OP_LOADLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                continue;

#elif defined __x86_64__

            case OP_LOADLOC11:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADLOC11:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOADLOC11:
                myabort("Unsupported architecture");

#endif
