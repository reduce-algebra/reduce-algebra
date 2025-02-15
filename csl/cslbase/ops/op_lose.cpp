// op_lose.cpp

#if defined BYTECODE
            case OP_LOSE:
                stack--;
                continue;

#elif defined __x86_64__

            case OP_LOSE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_LOSE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOSE:
                unfinished("Unsupported architecture");

#endif
