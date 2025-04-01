// storeloc5.cpp $Id$

#if defined BYTECODE
            case OP_STORELOC5:
                stack[-5] = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STORELOC5:
                storeloc(A_reg, 5);
                break;

#else
            case OP_STORELOC5:
                unfinished("Unsupported architecture");

#endif

// end of op_storeloc5.cpp
