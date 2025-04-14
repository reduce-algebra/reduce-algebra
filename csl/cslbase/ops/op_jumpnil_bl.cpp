// $Id$

#if defined BYTECODE
            case OP_JUMPNIL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == nil)
                {   ppc = ppc - ((w << 8) + (reinterpret_cast<unsigned char *>
                                             (codevec))[xppc]);
                    poll_jump_back(A_reg);
                }
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNIL_BL:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                cmp(A_reg, nilreg);
                je(perInstruction[ppc-next]);
                break;

#else
            case OP_JUMPNIL_BL:
                unfinished("Unsupported architecture");

#endif

// end of jumpnil_bl.cpp
