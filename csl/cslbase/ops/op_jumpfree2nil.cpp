// jumpfree2nil.cpp $Id$

#if defined BYTECODE
            case OP_JUMPFREE2NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 2)) == nil)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPFREE2NIL:
                next = bytes[ppc++];
                loadlit(w, 2);
                loadfromsymbol(w, w, Ovalue);
                cmp(w, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPFREE2NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpfree2nil.cpp
