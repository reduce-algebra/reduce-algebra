// op_call0_1.cpp

#if defined BYTECODE
            case OP_CALL0_1:
                fname = 1;
                goto call0;

#elif defined __x86_64__

            case OP_CALL0_1:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL0_1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL0_1:
                unfinished("Unsupported architecture");

#endif
