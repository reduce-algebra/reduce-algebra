// $Id$

#if defined BYTECODE
            case OP_PUSHNIL:
                *++stack = nil;
                continue;

#elif defined __x86_64__ | defined __aarch64__

            case OP_PUSHNIL:
                storereg_pre(nilreg, spreg, 8);
                break;

#else
            case OP_PUSHNIL:
                unfinished("Unsupported architecture");

#endif

// end of op_pushnil.cpp
