// $Id$

#if defined BYTECODE
            case OP_CALL1_2:
                fname = 2;
                goto call1;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL1_2:
                lispcall1(2);
                break;

#else
            case OP_CALL1_2:
                unfinished("Unsupported architecture");

#endif

// end of call1_2.cpp
