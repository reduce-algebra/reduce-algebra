// $Id$

#if defined BYTECODE
            case OP_PUSH:
                *++stack = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_PUSH:
                storereg_pre(A_reg, spreg, 8);
                break;

#else
            case OP_PUSH:
                unfinished("Unsupported architecture");

#endif

// end of op_push.cpp
