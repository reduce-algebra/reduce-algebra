// $Id$

#if defined BYTECODE
            case OP_CALL2_2:
                fname = 2;
                goto call2;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL2_2:
                lispcall2(2);
                break;


#else
            case OP_CALL2_2:
                unfinished("Unsupported architecture");

#endif

// end of call2_2.cpp
