// op_spare.cpp

#if defined BYTECODE
            case OP_SPARE:
                continue; // used on a temporary basis as LABEL

#elif defined __x86_64__

            case OP_SPARE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_SPARE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_SPARE:
                unfinished("Unsupported architecture");

#endif
