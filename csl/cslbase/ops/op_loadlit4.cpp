// loadlit4.cpp

#if defined BYTECODE
            case OP_LOADLIT4:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 4);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLIT4:
                mov(B_reg, A_reg);
                loadlit(A_reg, 4);
                break;

#else
            case OP_LOADLIT4:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit4.cpp
