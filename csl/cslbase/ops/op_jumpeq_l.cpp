// jumpeq_l.cpp $Id$

#if defined BYTECODE
            case OP_JUMPEQ_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) long_jump(w, ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPEQ_L:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                cmp(A_reg, B_reg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPEQ_L:
                unfinished("Unsupported architecture");

#endif

// end of jumpeq_l.cpp
