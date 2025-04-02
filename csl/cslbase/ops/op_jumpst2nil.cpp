// jumpst2nil.cpp $Id$

#if defined BYTECODE
            case OP_JUMPST2NIL:
                xppc = ppc;
                ppc++;
                if ((stack[-2] = A_reg) == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPST2NIL:
                next = bytes[ppc++];
                storeloc(A_reg, 2);
                cmp(A_reg, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPST2NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpst2nil.cpp
