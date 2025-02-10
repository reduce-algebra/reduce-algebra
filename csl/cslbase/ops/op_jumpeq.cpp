// op_jumpeq.cpp

#if defined BYTECODE
            case OP_JUMPEQ:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPEQ:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPEQ:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPEQ:
                myabort("Unsupported architecture");

#endif
