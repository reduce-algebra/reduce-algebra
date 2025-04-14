// $Id$

#if defined BYTECODE
            case OP_JUMPLIT1EQ:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 1)) == A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPLIT1EQ:
                next = bytes[ppc++];
                loadlit(w, 1);
                cmp(A_reg, w);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPLIT1EQ:
                unfinished("Unsupported architecture");

#endif


// end of op_jumplit1eq.cpp

