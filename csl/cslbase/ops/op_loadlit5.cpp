// $Id$

#if defined BYTECODE
            case OP_LOADLIT5:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 5);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLIT5:
                mov(B_reg, A_reg);
                loadlit(A_reg, 5);
                break;

#else
            case OP_LOADLIT5:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit5.cpp
