// $Id$

#if defined BYTECODE
            case OP_PUSHNIL2:
                *++stack = nil;
                *++stack = nil;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_PUSHNIL2:
                storereg_pre(nilreg, spreg, 16);
                storeloc(nilreg, 1);
                break;

#else
            case OP_PUSHNIL2:
                unfinished("Unsupported architecture");

#endif

// end of op_pushnil2.cpp
