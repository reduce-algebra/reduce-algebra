// jumpeq.cpp

#if defined BYTECODE
            case OP_JUMPEQ:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPEQ:
                next = bytes[ppc++];
                cmp(A_reg, B_reg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPEQ:
                unfinished("Unsupported architecture");

#endif

// end of jumpeq.cpp
