// $Id$

#if defined BYTECODE
            case OP_JUMPLIT2NE:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 2)) != A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPLIT2NE:
                next = bytes[ppc++];
                loadlit(w, 2);
                cmp(w, A_reg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPLIT2NE:
                unfinished("Unsupported architecture");

#endif

// end of op_jumplit2ne.cpp
