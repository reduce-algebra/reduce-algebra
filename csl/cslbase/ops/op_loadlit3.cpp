// loadlit3.cpp

#if defined BYTECODE
            case OP_LOADLIT3:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 3);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLIT3:
                mov(B_reg, A_reg);
                loadlit(A_reg, 3);
                break;

#else
            case OP_LOADLIT3:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit3.cpp
