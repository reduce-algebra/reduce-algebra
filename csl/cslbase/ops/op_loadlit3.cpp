// op_loadlit3.cpp

#if defined BYTECODE
            case OP_LOADLIT3:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 3);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT3:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(litvec, 24+CELL-TAG_VECTOR));
                break;

#elif defined __aarch64__

            case OP_LOADLIT3:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLIT3:
                unfinished("Unsupported architecture");

#endif
