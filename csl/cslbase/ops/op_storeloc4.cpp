// op_storeloc4.cpp

#if defined BYTECODE
            case OP_STORELOC4:
                stack[-4] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC4:
                cc.mov(ptr(spreg, -32), A_reg);
                break;

#elif defined __aarch64__

            case OP_STORELOC4:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STORELOC4:
                unfinished("Unsupported architecture");

#endif
