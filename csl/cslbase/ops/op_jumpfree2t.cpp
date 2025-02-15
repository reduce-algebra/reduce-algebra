// op_jumpfree2t.cpp

#if defined BYTECODE
            case OP_JUMPFREE2T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 2)) != nil)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPFREE2T:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPFREE2T:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPFREE2T:
                unfinished("Unsupported architecture");

#endif
