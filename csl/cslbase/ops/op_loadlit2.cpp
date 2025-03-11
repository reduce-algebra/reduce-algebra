// op_loadlit2.cpp

#if defined BYTECODE
            case OP_LOADLIT2:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 2);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT2:
                cc.mov(B_reg, A_reg);
                cc.mov(A_reg, ptr(litvec, 16+CELL-TAG_VECTOR));
                break;

#elif defined __aarch64__

            case OP_LOADLIT2:
                cc.mov(B_reg, A_reg);
                cc.ldr(A_reg, ptr(litvec, 16+CELL-TAG_VECTOR));
                break;

#else
            case OP_LOADLIT2:
                unfinished("Unsupported architecture");

#endif

// end of op_loadlit2.cpp
