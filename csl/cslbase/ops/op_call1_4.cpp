// $Id$

#if defined BYTECODE
            case OP_CALL1_4:
                fname = 4;
                goto call1;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL1_4:
                lispcall1(4);
                break;

#else
            case OP_CALL1_4:
                unfinished("Unsupported architecture");

#endif

// end of call1_4.cpp
