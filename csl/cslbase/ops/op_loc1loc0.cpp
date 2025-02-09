// op_loc1loc0.cpp

#if defined BYTECODE
            case OP_LOC1LOC0:
                B_reg = stack[-1];
                A_reg = stack[-0];
                continue;

#elif defined __x86_64__

            case OP_LOC1LOC0:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOC1LOC0:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOC1LOC0:
                myabort("Unsupported architecture");

#endif
