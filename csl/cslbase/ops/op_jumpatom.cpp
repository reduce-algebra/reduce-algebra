// jumpatom.cpp

#if defined BYTECODE
            case OP_JUMPATOM:
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPATOM:
                next = bytes[ppc++];
                test(A_reg, TAG_BITS);
                jne(perInstruction[ppc+next]);
                break;

#elif defined __aarch64__

            case OP_JUMPATOM:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPATOM:
                unfinished("Unsupported architecture");

#endif

// end of jumpatom.cpp
