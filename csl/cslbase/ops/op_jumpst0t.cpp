// jumpst0t.cpp $Id$

#if defined BYTECODE
            case OP_JUMPST0T:
                xppc = ppc;
                ppc++;
                if ((stack[0] = A_reg) != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPST0T:
                next = bytes[ppc++];
                storeloc(A_reg, 0);
                cmp(A_reg, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPST0T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpst0t.cpp
