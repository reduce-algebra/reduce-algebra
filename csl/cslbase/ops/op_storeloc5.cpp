// op_storeloc5.cpp

#if defined BYTECODE
            case OP_STORELOC5:
                stack[-5] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC5:
                cc.mov(ptr(spreg, -40), A_reg);
                break;

#elif defined __aarch64__

            case OP_STORELOC5:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STORELOC5:
                unfinished("Unsupported architecture");

#endif
