// storeloc7.cpp $Id$

#if defined BYTECODE
            case OP_STORELOC7:
                stack[-7] = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STORELOC7:
                storeloc(A_reg, 7);
                break;

#else
            case OP_STORELOC7:
                unfinished("Unsupported architecture");

#endif

// end of op_storeloc7.cpp
