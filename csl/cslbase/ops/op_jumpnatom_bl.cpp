#// jumpnatom_bl.cpp $Id$

#if defined BYTECODE
            case OP_JUMPNATOM_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNATOM_BL:
                next = bytes[ppc++];
                next = (next<<8) | bytes[ppc++];
                test(A_reg, TAG_BITS);
                je(perInstruction[ppc-next]);
                break;

#else
            case OP_JUMPNATOM_BL:
                unfinished("Unsupported architecture");

#endif

// end of jumpnatom_bl.cpp
