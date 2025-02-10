// op_call1_5.cpp

#if defined BYTECODE
            case OP_CALL1_5:
                fname = 5;
                goto call1;

#elif defined __x86_64__

            case OP_CALL1_5:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL1_5:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CALL1_5:
                myabort("Unsupported architecture");

#endif
