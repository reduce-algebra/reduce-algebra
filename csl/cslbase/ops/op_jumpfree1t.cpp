// jumpfree1t.cpp $Id$

#if defined BYTECODE
            case OP_JUMPFREE1T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 1)) != nil)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPFREE1T:
                next = bytes[ppc++];
                loadlit(w, 1);
                loadfromsymbol(w, w, Ovalue);
                cmp(w, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPFREE1T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpfree1t.cpp
