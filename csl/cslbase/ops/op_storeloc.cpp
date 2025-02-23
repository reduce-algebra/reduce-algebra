// op_storeloc.cpp

#if defined BYTECODE
            case OP_STORELOC:
                stack[-static_cast<int>(next_byte)] = A_reg;
// NB this opcode does not pop the A/B stack
                continue;

#elif defined __x86_64__

            case OP_STORELOC:
                next = bytes[ppc++];
                cc.mov(ptr(spreg, -8*next), A_reg);
                break;

#elif defined __aarch64__

            case OP_STORELOC:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_STORELOC:
                unfinished("Unsupported architecture");

#endif
