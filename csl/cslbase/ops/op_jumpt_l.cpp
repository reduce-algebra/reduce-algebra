// jumpt_l.cpp

#if defined BYTECODE
            case OP_JUMPT_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != nil) ppc = ppc + ((w << 8) +
                                                   (reinterpret_cast<unsigned char *>(codevec))[xppc]);
                continue;

#elif defined __x86_64__

            case OP_JUMPT_L:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                cmp(A_reg, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#elif defined __aarch64__

            case OP_JUMPT_L:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPT_L:
                unfinished("Unsupported architecture");

#endif

// end of jumpt_l.cpp