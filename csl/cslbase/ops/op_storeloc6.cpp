// op_storeloc6.cpp

#if defined BYTECODE
            case OP_STORELOC6:
                stack[-6] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC6:
                cc.mov(ptr(spreg, -48*next), A_reg);
                break;

#elif defined __aarch64__

            case OP_STORELOC6:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STORELOC6:
                unfinished("Unsupported architecture");

#endif
