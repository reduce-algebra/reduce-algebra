// op_call1_4.cpp

#if defined BYTECODE
            case OP_CALL1_4:
                fname = 4;
                goto call1;

#elif defined __x86_64__

            case OP_CALL1_4:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL1_4:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL1_4:
                unfinished("Unsupported architecture");

#endif
