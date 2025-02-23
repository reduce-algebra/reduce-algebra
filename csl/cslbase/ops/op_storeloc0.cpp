// op_storeloc0.cpp

#if defined BYTECODE
            case OP_STORELOC0:
                stack[-0] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC0:
                cc.mov(ptr(spreg), A_reg);
                break;

#elif defined __aarch64__

            case OP_STORELOC0:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STORELOC0:
                unfinished("Unsupported architecture");

#endif
