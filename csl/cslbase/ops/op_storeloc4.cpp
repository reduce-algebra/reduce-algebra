// $Id$

#if defined BYTECODE
            case OP_STORELOC4:
                stack[-4] = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STORELOC4:
                storeloc(A_reg, 4);
                break;

#else
            case OP_STORELOC4:
                unfinished("Unsupported architecture");

#endif

// end of op_storeloc4.cpp
