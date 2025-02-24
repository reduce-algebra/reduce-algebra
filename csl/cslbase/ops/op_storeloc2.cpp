// op_storeloc2.cpp

#if defined BYTECODE
            case OP_STORELOC2:
                stack[-2] = A_reg;
                continue;

#elif defined __x86_64__

            case OP_STORELOC2:
                cc.mov(ptr(spreg, -16), A_reg);
                break;

#elif defined __aarch64__

            case OP_STORELOC2:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STORELOC2:
                unfinished("Unsupported architecture");

#endif
