// $Id$

#if defined BYTECODE
            case OP_JUMPLITNE:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec,
                                                      w)) != A_reg) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPLITNE:
                next = bytes[ppc++];
                loadlit(w, next);
                next = bytes[ppc++];
                cmp(w, A_reg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPLITNE:
                unfinished("Unsupported architecture");

#endif

// end of op_jumplitne.cpp
