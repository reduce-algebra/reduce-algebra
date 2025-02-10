// op_jumpflagp.cpp

#if defined BYTECODE
            case OP_JUMPFLAGP:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!symbolp(A_reg)) continue;
                else
#ifdef COMMON
                {   r1 = get(A_reg, basic_elt(litvec, w), unset_var);
                    errexit();
                    if (r1 != unset_var) short_jump(ppc, xppc, codevec);
                    continue;
                }
#else
                {   r1 = Lflagp(nil, A_reg, basic_elt(litvec, w));
                    errexit();
                }
                if (r1 != nil) short_jump(ppc, xppc, codevec);
                continue;
#endif

#elif defined __x86_64__

            case OP_JUMPFLAGP:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPFLAGP:
                myabort("This case not yet implemented for ARM");

#else
            case OP_JUMPFLAGP:
                myabort("Unsupported architecture");

#endif
