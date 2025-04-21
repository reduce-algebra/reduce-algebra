// $Id$

#if defined BYTECODE
            case OP_CALL0_2:
                fname = 2;
                goto call0;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL0_2:
                lispcall0(2);
                break;

#else
            case OP_CALL0_2:
                unfinished("Unsupported architecture");

#endif

// call0_2.cpp

// end of op_call0_2.cpp
