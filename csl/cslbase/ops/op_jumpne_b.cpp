// $Id$

#if defined BYTECODE
            case OP_JUMPNE_B:
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNE_B:
                next = bytes[ppc++];
                cmp(A_reg, B_reg);
                jne(perInstruction[ppc-next]);
                break;

#else
            case OP_JUMPNE_B:
                unfinished("Unsupported architecture");

#endif

// end of jumpne_b.cpp
