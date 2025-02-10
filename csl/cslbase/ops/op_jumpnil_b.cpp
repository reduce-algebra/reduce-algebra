// op_jumpnil_b.cpp

#if defined BYTECODE
            case OP_JUMPNIL_B:
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNIL_B:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNIL_B:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPNIL_B:
                myabort("Unsupported architecture");

#endif
