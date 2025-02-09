// op_xcons.cpp

#if defined BYTECODE
            case OP_XCONS:                          // A_reg = cons(A_reg, B_reg);
                A_reg = cons(A_reg, B_reg);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_XCONS:                          // A_reg = cons(A_reg, B_reg);
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_XCONS:                          // A_reg = cons(A_reg, B_reg);
                myabort("This case not yet implemented for ARM");

#else
            case OP_XCONS:                          // A_reg = cons(A_reg, B_reg);
                myabort("Unsupported architecture");

#endif
