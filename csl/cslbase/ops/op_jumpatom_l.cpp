// jumpatom_l.cpp

#if defined BYTECODE
            case OP_JUMPATOM_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) long_jump(w, ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPATOM_L:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                test(A_reg, TAG_BITS);
                jne(perInstruction[ppc+next]);
                break;

#elif defined __aarch64__

            case OP_JUMPATOM_L:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPATOM_L:
                unfinished("Unsupported architecture");

#endif

// end of jumpatom_l.cpp
