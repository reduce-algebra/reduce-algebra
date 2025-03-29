// loadfree4.cpp

#if defined BYTECODE
            case OP_LOADFREE4:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 4));
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADFREE4:
                mov(B_reg, A_reg);
                loadlit(A_reg, 4);
                loadfromsymbol(A_reg, A_reg, Ovalue);
                break;

#else
            case OP_LOADFREE4:
                unfinished("Unsupported architecture");

#endif

// end of op_loadfree4.cpp
