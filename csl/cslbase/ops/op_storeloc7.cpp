// op_storeloc7.cpp

#if defined BYTECODE
            case OP_STORELOC7:
                stack[-7] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC7:
                cc.mov(ptr(spreg, -56), A_reg);
                break;

#elif defined __aarch64__

            case OP_STORELOC7:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STORELOC7:
                unfinished("Unsupported architecture");

#endif
