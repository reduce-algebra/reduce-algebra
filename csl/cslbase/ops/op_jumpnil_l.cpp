// jumpnil_l.cpp $Id$

#if defined BYTECODE
            case OP_JUMPNIL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == nil) ppc = ppc + ((w << 8) +
                                                   (reinterpret_cast<unsigned char *>(codevec))[xppc]);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNIL_L:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                cmp(A_reg, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPNIL_L:
                unfinished("Unsupported architecture");

#endif

// end of jumpnil_l.cpp
