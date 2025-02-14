// op_jumplit2ne.cpp

#if defined BYTECODE
            case OP_JUMPLIT2NE:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 2)) != A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPLIT2NE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPLIT2NE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPLIT2NE:
                unfinished("Unsupported architecture");

#endif
