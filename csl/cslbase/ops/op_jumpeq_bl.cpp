// op_jumpeq_bl.cpp

#if defined BYTECODE
            case OP_JUMPEQ_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPEQ_BL:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPEQ_BL:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPEQ_BL:
                myabort("Unsupported architecture");

#endif
