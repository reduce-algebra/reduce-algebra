// jumpt_b.cpp

#if defined BYTECODE
            case OP_JUMPT_B:
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPT_B:
                next = bytes[ppc++];
                cmp(A_reg, nilreg);
                jne(perInstruction[ppc-next]);
                break;


#elif defined __aarch64__

            case OP_JUMPT_B:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPT_B:
                unfinished("Unsupported architecture");

#endif

// end of jumpt_b.cpp
