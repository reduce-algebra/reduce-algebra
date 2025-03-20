// storeloc0.cpp

#if defined BYTECODE
            case OP_STORELOC0:
                stack[-0] = A_reg;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_STORELOC0:
                storeloc(A_reg, 0);
                break;

#else
            case OP_STORELOC0:
                unfinished("Unsupported architecture");

#endif

// end of op_storeloc0.cpp
