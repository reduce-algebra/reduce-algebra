// jumpatom_b.cpp

#if defined BYTECODE
            case OP_JUMPATOM_B:
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPATOM_B:
                next = bytes[ppc++];
                test(A_reg, TAG_BITS);
                jne(perInstruction[ppc-next]);
                break;

#elif defined __aarch64__

            case OP_JUMPATOM_B:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPATOM_B:
                unfinished("Unsupported architecture");

#endif

// end of jumpatom_b.cpp
