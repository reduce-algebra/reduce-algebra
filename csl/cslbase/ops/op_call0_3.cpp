// op_call0_3.cpp

#if defined BYTECODE
            case OP_CALL0_3:
                fname = 3;
                goto call0;

#elif defined __x86_64__

            case OP_CALL0_3:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL0_3:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CALL0_3:
                myabort("Unsupported architecture");

#endif
