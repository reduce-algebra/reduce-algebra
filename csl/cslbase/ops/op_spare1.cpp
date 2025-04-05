// spare1.cpp $Id$

#if defined BYTECODE

            case OP_SPARE1:
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_SPARE1:
                break;

#else
            case OP_SPARE1:
                unfinished("Unsupported architecture");

#endif

// end of op_spare1.cpp
