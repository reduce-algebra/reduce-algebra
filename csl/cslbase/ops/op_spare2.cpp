// spare2.cpp $Id$

#if defined BYTECODE

            case OP_SPARE2:
                continue;

#elif defined __x86_64__

            case OP_SPARE2:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_SPARE2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_SPARE2:
                unfinished("Unsupported architecture");

#endif

// end of op_spare2.cpp
