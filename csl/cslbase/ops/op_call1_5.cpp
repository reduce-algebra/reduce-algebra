// $Id$

#if defined BYTECODE
            case OP_CALL1_5:
                fname = 5;
                goto call1;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL1_5:
                lispcall1(5);
                break;

#else
            case OP_CALL1_5:
                unfinished("Unsupported architecture");

#endif

// end of call1_5.cpp
