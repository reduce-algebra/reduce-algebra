// push.cpp

#if defined BYTECODE
            case OP_PUSH:
                *++stack = A_reg;
                continue;

#elif defined __x86_64__

            case OP_PUSH:
                add(spreg, 8);
                mov(ptr(spreg), A_reg);
                break;

#elif defined __aarch64__

            case OP_PUSH:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSH:
                unfinished("Unsupported architecture");

#endif

// end of op_push.cpp
