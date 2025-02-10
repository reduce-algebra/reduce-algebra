// op_equal.cpp

#if defined BYTECODE
            case OP_EQUAL:                                  // A = equal(B, A)
                A_reg = SL_OR_CL_EQUAL(B_reg, A_reg) ? lisp_true : nil;
                errexit();
                continue;

#elif defined __x86_64__

            case OP_EQUAL:                                  // A = equal(B, A)
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_EQUAL:                                  // A = equal(B, A)
                myabort("This case not yet implemented for ARM");

#else
            case OP_EQUAL:                                  // A = equal(B, A)
                myabort("Unsupported architecture");

#endif
