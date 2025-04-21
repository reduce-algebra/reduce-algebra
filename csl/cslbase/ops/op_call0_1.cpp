// $Id$

#if defined BYTECODE
            case OP_CALL0_1:
                fname = 1;
                goto call0;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL0_1:
                lispcall0(1);
                break;

#else
            case OP_CALL0_1:
                unfinished("Unsupported architecture");

#endif

// end of call0_1.cpp
