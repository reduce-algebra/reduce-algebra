// op_lose2.cpp

#if defined BYTECODE
            case OP_LOSE2:
                stack -= 2;
                continue;

#elif defined __x86_64__

            case OP_LOSE2:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOSE2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOSE2:
                unfinished("Unsupported architecture");

#endif
