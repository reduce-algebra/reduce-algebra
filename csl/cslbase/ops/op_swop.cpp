// swcpp $Id$

#if defined BYTECODE
            case OP_SWOP:
                r1 = B_reg;
                B_reg = A_reg;
                A_reg = r1;
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_SWOP:
                mov(w, B_reg);
                mov(B_reg, A_reg);
                mov(A_reg, w);
                break;

#else
            case OP_SWOP:
                unfinished("Unsupported architecture");

#endif

// end of swcpp
