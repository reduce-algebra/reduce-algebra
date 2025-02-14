// op_call2_2.cpp

#if defined BYTECODE
            case OP_CALL2_2:
                fname = 2;
                goto call2;

#elif defined __x86_64__

            case OP_CALL2_2:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_CALL2_2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_CALL2_2:
                unfinished("Unsupported architecture");

#endif
