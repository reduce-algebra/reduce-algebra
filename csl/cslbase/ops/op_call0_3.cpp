// $Id$

#if defined BYTECODE
            case OP_CALL0_3:
                fname = 3;
                goto call0;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL0_3:
                lispcall0(3);
                break;

#else
            case OP_CALL0_3:
                unfinished("Unsupported architecture");

#endif

// end of call0_3.cpp
