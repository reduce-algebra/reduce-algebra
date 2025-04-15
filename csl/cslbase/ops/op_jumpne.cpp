// $Id$

#if defined BYTECODE
            case OP_JUMPNE:
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNE:
                next = bytes[ppc++];
                cmp(A_reg, B_reg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPNE:
                unfinished("Unsupported architecture");

#endif

// end of jumpne.cpp
