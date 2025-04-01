// jumpeq_b.cpp

#if defined BYTECODE
            case OP_JUMPEQ_B:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPEQ_B:
                next = bytes[ppc++];
                cmp(A_reg, B_reg);
                je(perInstruction[ppc-next]);
                break;

#else
            case OP_JUMPEQ_B:
                unfinished("Unsupported architecture");

#endif

// end of jumpeq_b.cpp
