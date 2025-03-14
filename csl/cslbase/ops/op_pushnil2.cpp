// op_pushnil2.cpp

#if defined BYTECODE
            case OP_PUSHNIL2:
                *++stack = nil;
                *++stack = nil;
                continue;

#elif defined __x86_64__

            case OP_PUSHNIL2:
                cc.add(spreg, 8);
                cc.mov(nilreg, ptr(spreg));
                cc.add(spreg, 8);
                cc.mov(nilreg, ptr(spreg));
                break;

#elif defined __aarch64__

            case OP_PUSHNIL2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSHNIL2:
                unfinished("Unsupported architecture");

#endif
