// op_loadfree.cpp

#if defined BYTECODE
            case OP_LOADFREE:
//
// Load the value of a free (GLOBAL, SPECIAL, FLUID) variable
//
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, next_byte));
                continue;

#elif defined __x86_64__

            case OP_LOADFREE:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOADFREE:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LOADFREE:
                myabort("Unsupported architecture");

#endif
