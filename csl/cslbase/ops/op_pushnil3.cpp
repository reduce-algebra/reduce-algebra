// $Id$

#if defined BYTECODE
            case OP_PUSHNIL3:
                *++stack = nil;
                *++stack = nil;
                *++stack = nil;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_PUSHNIL3:
                storereg_pre(nilreg, spreg, 8);
                storereg_pre(nilreg, spreg, 8);
                storereg_pre(nilreg, spreg, 8);
                break;

#else
            case OP_PUSHNIL3:
                unfinished("Unsupported architecture");

#endif

// end of op_pushnil3.cpp
