// op_loc0loc1.cpp

#if defined BYTECODE
            case OP_LOC0LOC1:
                B_reg = stack[-0];
                A_reg = stack[-1];
                continue;

#elif defined __x86_64__

            case OP_LOC0LOC1:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOC0LOC1:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOC0LOC1:
                myabort("Unsupported architecture");

#endif
