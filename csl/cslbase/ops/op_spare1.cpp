// spare1.cpp

#if defined BYTECODE

            case OP_SPARE1:
                continue;

#elif defined __x86_64__

            case OP_SPARE1:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_SPARE1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_SPARE1:
                unfinished("Unsupported architecture");

#endif

// end of op_spare1.cpp
