// storeloc.cpp $Id$

#if defined BYTECODE
            case OP_STORELOC:
                stack[-static_cast<int>(next_byte)] = A_reg;
// NB this opcode does not pop the A/B stack
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STORELOC:
                next = bytes[ppc++];
                storeloc(A_reg, next);
                break;

#else
            case OP_STORELOC:
                unfinished("Unsupported architecture");

#endif

// end of op_storeloc.cpp
