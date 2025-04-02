// jumpnatom_b.cpp $Id$

#if defined BYTECODE
            case OP_JUMPNATOM_B:
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNATOM_B:
                next = bytes[ppc++];
                test(A_reg, TAG_BITS);
                je(perInstruction[ppc-next]);
                break;

#else
            case OP_JUMPNATOM_B:
                unfinished("Unsupported architecture");

#endif

// end og jumpnatom_b.cpp

// end of op_jumpnatom_b.cpp
