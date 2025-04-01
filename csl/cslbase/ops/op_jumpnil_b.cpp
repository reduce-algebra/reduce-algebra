// jumpnil_b.cpp $Id$

#if defined BYTECODE
            case OP_JUMPNIL_B:
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNIL_B:
                next = bytes[ppc++];
                cmp(A_reg, nilreg);
                je(perInstruction[ppc-next]);
                break;

#else
            case OP_JUMPNIL_B:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpnil_b.cpp
