// op_call2_1.cpp

#if defined BYTECODE
            case OP_CALL2_1:
                fname = 1;
                goto call2;

#elif defined __x86_64__

            case OP_CALL2_1:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL2_1:
                myabort("This case not yet implemented for ARM");

#else
            case OP_CALL2_1:
                myabort("Unsupported architecture");

#endif
