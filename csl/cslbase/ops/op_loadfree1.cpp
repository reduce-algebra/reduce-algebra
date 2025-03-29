// loadfree1.cpp

#if defined BYTECODE
            case OP_LOADFREE1:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 1));
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADFREE1:
                mov(B_reg, A_reg);
                loadlit(A_reg, 1);
                loadfromsymbol(A_reg, A_reg, Ovalue);
                break;

#else
            case OP_LOADFREE1:
                unfinished("Unsupported architecture");

#endif

// end of op_loadfree1.cpp
