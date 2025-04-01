// jumpfree3t.cpp $Id$

#if defined BYTECODE
            case OP_JUMPFREE3T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 3)) != nil)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPFREE3T:
                next = bytes[ppc++];
                loadlit(w, 3);
                loadfromsymbol(w, w, Ovalue);
                cmp(w, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPFREE3T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpfree3t.cpp
