// $Id$

#if defined BYTECODE
            case OP_LOADLIT2:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 2);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_LOADLIT2:
                mov(B_reg, A_reg);
                loadlit(A_reg, 2);
                break;

#else
            case OP_LOADLIT2:
                unfinished("Unsupported architecture");

#endif

// end of loadlit2.cpp
