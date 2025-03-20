// loadlit4.cpp

#if defined BYTECODE
            case OP_LOADLIT4:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 4);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT4:
                mov(A_reg, ptr(litvec, 32+CELL-TAG_VECTOR));
                break;

#elif defined __aarch64__

            case OP_LOADLIT4:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLIT4:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit4.cpp
