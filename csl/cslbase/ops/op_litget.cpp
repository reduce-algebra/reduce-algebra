// op_litget.cpp

#if defined BYTECODE
            case OP_LITGET:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, next_byte);
                A_reg = get(B_reg, A_reg, nil);
                errexit();
                continue;

#elif defined __x86_64__

            case OP_LITGET:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LITGET:
                myabort("This case not yet implemented for ARM");

#else
            case OP_LITGET:
                myabort("Unsupported architecture");

#endif
