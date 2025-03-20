// loadlit6.cpp

#if defined BYTECODE
            case OP_LOADLIT6:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 6);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT6:
                mov(A_reg, ptr(litvec, 48+CELL-TAG_VECTOR));
                break;

#elif defined __aarch64__

            case OP_LOADLIT6:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLIT6:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit6.cpp
