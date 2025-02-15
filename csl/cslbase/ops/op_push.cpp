// op_push.cpp

#if defined BYTECODE
            case OP_PUSH:
                *++stack = A_reg;
                continue;

#elif defined __x86_64__

            case OP_PUSH:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_PUSH:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSH:
                unfinished("Unsupported architecture");

#endif
