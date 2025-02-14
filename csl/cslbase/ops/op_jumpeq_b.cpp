// op_jumpeq_b.cpp

#if defined BYTECODE
            case OP_JUMPEQ_B:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPEQ_B:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPEQ_B:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPEQ_B:
                unfinished("Unsupported architecture");

#endif
