// op_pushnil3.cpp

#if defined BYTECODE
            case OP_PUSHNIL3:
                *++stack = nil;
                *++stack = nil;
                *++stack = nil;
                continue;

#elif defined __x86_64__

            case OP_PUSHNIL3:
                cc.add(spreg, 8);
                cc.mov(nilreg, ptr(spreg));
                cc.add(spreg, 8);
                cc.mov(nilreg, ptr(spreg));
                cc.add(spreg, 8);
                cc.mov(nilreg, ptr(spreg));
                break;

#elif defined __aarch64__

            case OP_PUSHNIL3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_PUSHNIL3:
                unfinished("Unsupported architecture");

#endif
