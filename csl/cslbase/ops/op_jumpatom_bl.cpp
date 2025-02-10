// op_jumpatom_bl.cpp

#if defined BYTECODE
            case OP_JUMPATOM_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPATOM_BL:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPATOM_BL:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPATOM_BL:
                myabort("Unsupported architecture");

#endif
