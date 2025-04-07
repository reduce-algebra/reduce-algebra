// jumpfreenil.cpp $Id$

#if defined BYTECODE
            case OP_JUMPFREENIL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, w)) == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPFREENIL:
                next = bytes[ppc++];
                loadlit(w, next);
                loadfromsymbol(w, w, Ovalue);
                next = bytes[ppc++];
                cmp(w, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPFREENIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpfreenil.cpp
