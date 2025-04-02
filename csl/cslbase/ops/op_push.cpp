// push.cpp $Id$

#if defined BYTECODE
            case OP_PUSH:
                *++stack = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_PUSH:
                add2(spreg, 8);
                storeloc(A_reg, 0);
                break;

#else
            case OP_PUSH:
                unfinished("Unsupported architecture");

#endif

// end of op_push.cpp
