// storeloc6.cpp $Id$

#if defined BYTECODE
            case OP_STORELOC6:
                stack[-6] = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STORELOC6:
                storeloc(A_reg, 6);
                break;

#else
            case OP_STORELOC6:
                unfinished("Unsupported architecture");

#endif

// end of op_storeloc6.cpp
