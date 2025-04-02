// pushnil3.cpp $Id$

#if defined BYTECODE
            case OP_PUSHNIL3:
                *++stack = nil;
                *++stack = nil;
                *++stack = nil;
                continue;

#elif defined __x86_64__

            case OP_PUSHNIL3:
                add(spreg, 24);
                storeloc(nilreg, 0);
                storeloc(nilreg, -8);
                storeloc(nilreg, -16);
                break;

#elif defined __aarch64__

            case OP_PUSHNIL3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSHNIL3:
                unfinished("Unsupported architecture");

#endif

// end of op_pushnil3.cpp
