// jumpt.cpp $Id$

#if defined BYTECODE
            case OP_JUMPT:
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPT:
                next = bytes[ppc++];
                cmp(A_reg, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPT:
                unfinished("Unsupported architecture");

#endif

// end of jumpt.cpp
