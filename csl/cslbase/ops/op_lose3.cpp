// op_lose3.cpp

#if defined BYTECODE
            case OP_LOSE3:
                stack -= 3;
                continue;

#elif defined __x86_64__

            case OP_LOSE3:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOSE3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOSE3:
                unfinished("Unsupported architecture");

#endif
