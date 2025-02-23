// op_storeloc3.cpp

#if defined BYTECODE
            case OP_STORELOC3:
                stack[-3] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC3:
                cc.mov(ptr(spreg, -24), A_reg);
                break;

#elif defined __aarch64__

            case OP_STORELOC3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STORELOC3:
                unfinished("Unsupported architecture");

#endif
