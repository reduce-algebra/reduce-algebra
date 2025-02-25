// op_loadlit1.cpp

#if defined BYTECODE
            case OP_LOADLIT1:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 1);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT1:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(litvec, 8+CELL-TAG_VECTOR));
                break;

#elif defined __aarch64__

            case OP_LOADLIT1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLIT1:
                unfinished("Unsupported architecture");

#endif
