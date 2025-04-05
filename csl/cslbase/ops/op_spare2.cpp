// spare2.cpp $Id$

#if defined BYTECODE

            case OP_SPARE2:
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_SPARE2:
                break;

#else
            case OP_SPARE2:
                unfinished("Unsupported architecture");

#endif

// end of op_spare2.cpp
