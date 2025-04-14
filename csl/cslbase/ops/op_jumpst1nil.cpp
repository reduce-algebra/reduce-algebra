// $Id$

#if defined BYTECODE
            case OP_JUMPST1NIL:
                xppc = ppc;
                ppc++;
                if ((stack[-1] = A_reg) == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPST1NIL:
                next = bytes[ppc++];
                storeloc(A_reg, 1);
                cmp(A_reg, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPST1NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpst1nil.cpp
