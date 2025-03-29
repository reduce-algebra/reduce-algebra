// storeloc2.cpp

#if defined BYTECODE
            case OP_STORELOC2:
                stack[-2] = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STORELOC2:
                storeloc(A_reg, 2);
                break;

#else
            case OP_STORELOC2:
                unfinished("Unsupported architecture");

#endif

// end of op_storeloc2.cpp
