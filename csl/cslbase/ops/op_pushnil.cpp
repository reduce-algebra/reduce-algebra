// pushnil.cpp

#if defined BYTECODE
            case OP_PUSHNIL:
                *++stack = nil;
                continue;

#elif defined __x86_64__

            case OP_PUSHNIL:
                add(spreg, 8);
                storeloc(nilreg, 0);
                break;

#elif defined __aarch64__

            case OP_PUSHNIL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSHNIL:
                unfinished("Unsupported architecture");

#endif

// end of op_pushnil.cpp
