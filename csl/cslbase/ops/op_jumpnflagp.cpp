// op_jumpnflagp.cpp

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

//
// Now the general jumps.  Each has four variants - forwards and backwards
// and long and short offsets.  Backwards jumps poll for interrupts so that
// all loops will be interruptible.
//

#elif defined __x86_64__

            case OP_JUMPNFLAGP:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNFLAGP:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPNFLAGP:
                unfinished("Unsupported architecture");

#endif
