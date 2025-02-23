// op_loadlit5.cpp

#if defined BYTECODE
            case OP_LOADLIT5:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 5);
                continue;

#elif defined __x86_64__

            case OP_LOADLIT5:
                cc.mov(A_reg, ptr(litvec, 40+8-TAG_VECTOR));
                break;

#elif defined __aarch64__

            case OP_LOADLIT5:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_LOADLIT5:
                unfinished("Unsupported architecture");

#endif
