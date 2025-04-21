// $Id$

#if defined BYTECODE
            case OP_CALL0_0:      // Calling myself...
                fname = 0;
                goto call0;

#elif defined __x86_64__ || defined __aarch64__

            case OP_CALL0_0:      // Calling myself...
                lispcall0(0);
                break;

#else
            case OP_CALL0_0:      // Calling myself...
                unfinished("Unsupported architecture");

#endif

// end of call0_0.cpp