// op_call0_2.cpp

#if defined BYTECODE
            case OP_CALL0_2:
                fname = 2;
                goto call0;

#elif defined __x86_64__

            case OP_CALL0_2:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL0_2:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CALL0_2:
                myabort("Unsupported architecture");

#endif
