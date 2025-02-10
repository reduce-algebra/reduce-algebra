// op_jumpnatom_l.cpp

#if defined BYTECODE
            case OP_JUMPNATOM_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) long_jump(w, ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNATOM_L:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNATOM_L:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPNATOM_L:
                myabort("Unsupported architecture");

#endif
