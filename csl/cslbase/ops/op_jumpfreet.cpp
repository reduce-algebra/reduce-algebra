// $Id$

#if defined BYTECODE
            case OP_JUMPFREET:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, w)) != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPFREET:
                next = bytes[ppc++];
                loadlit(w, next);
                loadfromsymbol(w, w, Ovalue);
                next = bytes[ppc++];
                cmp(w, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPFREET:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpfreet.cpp
