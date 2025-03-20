// loadlit1.cpp

#if defined BYTECODE
            case OP_LOADLIT1:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 1);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLIT1:
                mov(B_reg, A_reg);
                loadlit(A_reg, 1);
                break;

#else
            case OP_LOADLIT1:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit1.cpp
