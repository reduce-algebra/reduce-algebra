// loadlit7.cpp

#if defined BYTECODE
            case OP_LOADLIT7:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 7);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT7:
                mov(A_reg, ptr(litvec, 56+CELL-TAG_VECTOR));
                break;

#elif defined __aarch64__

            case OP_LOADLIT7:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLIT7:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit7.cpp
