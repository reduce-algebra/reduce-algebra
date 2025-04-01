// lose2.cpp $Id$

#if defined BYTECODE
            case OP_LOSE2:
                stack -= 2;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOSE2:
                sub2(spreg, 16);
                break;

#else
            case OP_LOSE2:
                unfinished("Unsupported architecture");

#endif

// end of lose2.cpp
