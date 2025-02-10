// op_loc3loc2.cpp

#if defined BYTECODE
            case OP_LOC3LOC2:
                B_reg = stack[-3];
                A_reg = stack[-2];
                continue;

#elif defined __x86_64__

            case OP_LOC3LOC2:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOC3LOC2:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOC3LOC2:
                myabort("Unsupported architecture");

#endif
