// $Id$

#if defined BYTECODE
            case OP_CALL2_3:
                fname = 3;
                goto call2;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL2_3:
                lispcall2(3);
                break;

#else
            case OP_CALL2_3:
                unfinished("Unsupported architecture");

#endif

// end of call2_3.cpp
