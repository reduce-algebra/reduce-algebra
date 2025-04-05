// jumpnflagp.cpp $Id$

#if defined BYTECODE
            case OP_JUMPNFLAGP:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!symbolp(A_reg))
                {   short_jump(ppc, xppc, codevec);
                    continue;
                }
                else
#ifdef COMMON
                {   r1 = get(A_reg, basic_elt(litvec, w), unset_var);
                    errexit();
                    if (r1 == unset_var) short_jump(ppc, xppc, codevec);
                    continue;
                }
#else
                {   r1 = Lflagp(nil, A_reg, basic_elt(litvec, w));
                    errexit();
                }
                if (r1 == nil) short_jump(ppc, xppc, codevec);
                continue;
#endif

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNFLAGP:
                next = bytes[ppc++];
                loadstatic(w, OJITshim2L);
                loadstatic(w1, OJITLflagp);
                loadlit(w2, next);
                JITcall(w, w,
                        w1, nilreg, A_reg, w2);
                JITerrorcheck();
                cmp(w, nilreg);
                next = bytes[ppc++];
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPNFLAGP:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpnflagp.cpp
