// $Id$

#if defined BYTECODE
            case OP_CALL2_4:
                fname = 4;
                goto call2;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL2_4:
                lispcall2(4);
                break;

#else
            case OP_CALL2_4:
                unfinished("Unsupported architecture");

#endif

// end of call2_4.cpp
