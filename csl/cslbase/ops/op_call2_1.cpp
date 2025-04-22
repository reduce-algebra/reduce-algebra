// $Id$

#if defined BYTECODE
            case OP_CALL2_1:
                fname = 1;
                goto call2;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL2_1:
                lispcall2(1);
                break;

#else
            case OP_CALL2_1:
                unfinished("Unsupported architecture");

#endif

// end of call2_1.cpp
