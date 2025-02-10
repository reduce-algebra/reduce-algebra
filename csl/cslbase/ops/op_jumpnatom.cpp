// op_jumpnatom.cpp

#if defined BYTECODE
            case OP_JUMPNATOM:
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNATOM:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNATOM:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPNATOM:
                myabort("Unsupported architecture");

#endif
