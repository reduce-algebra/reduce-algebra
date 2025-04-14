// $Id$

#if defined BYTECODE
            case OP_LOADFREE2:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 2));
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADFREE2:
                mov(B_reg, A_reg);
                loadlit(A_reg, 2);
                loadfromsymbol(A_reg, A_reg, Ovalue);
                break;

#else
            case OP_LOADFREE2:
                unfinished("Unsupported architecture");

#endif

// end of op_loadfree2.cpp
