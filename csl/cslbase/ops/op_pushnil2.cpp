// pushnil2.cpp

#if defined BYTECODE
            case OP_PUSHNIL2:
                *++stack = nil;
                *++stack = nil;
                continue;

#elif defined __x86_64__

            case OP_PUSHNIL2:
                add(spreg, 16);
                storeloc(nilreg, 0);
                storeloc(nilreg, -8);
                break;

#elif defined __aarch64__

            case OP_PUSHNIL2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSHNIL2:
                unfinished("Unsupported architecture");

#endif

// end of op_pushnil2.cpp
