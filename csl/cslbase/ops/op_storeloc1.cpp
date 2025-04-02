// storeloc1.cpp $Id$

#if defined BYTECODE
            case OP_STORELOC1:
                stack[-1] = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STORELOC1:
                storeloc(A_reg, 1);
                break;

#else
            case OP_STORELOC1:
                unfinished("Unsupported architecture");

#endif

// end of op_storeloc1.cpp
