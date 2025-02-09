// op_eq.cpp

#if defined BYTECODE
            case OP_EQ:                                     // A = eq(B, A)
                if (A_reg == B_reg) A_reg = lisp_true;
                else A_reg = nil;
                continue;

#elif defined __x86_64__

            case OP_EQ:                                     // A = eq(B, A)
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_EQ:                                     // A = eq(B, A)
                myabort("This case not yet implemented for ARM");

#else
            case OP_EQ:                                     // A = eq(B, A)
                myabort("Unsupported architecture");

#endif
