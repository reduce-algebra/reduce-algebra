// $Id$

#if defined BYTECODE
            case OP_CALL1_3:
                fname = 3;
                goto call1;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL1_3:
                lispcall1(3);
                break;

#else
            case OP_CALL1_3:
                unfinished("Unsupported architecture");

#endif

// end of call1_3.cpp
