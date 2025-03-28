// jumpeq_l.cpp

#if defined BYTECODE
            case OP_JUMPEQ_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) long_jump(w, ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPEQ_L:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                cmp(A_reg, B_reg);
                je(perInstruction[ppc+next]);
                break;

#elif defined __aarch64__

            case OP_JUMPEQ_L:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPEQ_L:
                unfinished("Unsupported architecture");

#endif

// end of jumpeq_l.cpp
