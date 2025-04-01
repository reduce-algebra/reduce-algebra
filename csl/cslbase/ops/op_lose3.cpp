// lose3.cpp $Id$

#if defined BYTECODE
            case OP_LOSE3:
                stack -= 3;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOSE3:
                sub2(spreg, 24);
                break;

#else
            case OP_LOSE3:
                unfinished("Unsupported architecture");

#endif

// end of lose3.cpp
