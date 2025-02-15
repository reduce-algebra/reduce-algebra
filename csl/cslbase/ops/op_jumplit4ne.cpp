// op_jumplit4ne.cpp

#if defined BYTECODE
            case OP_JUMPLIT4NE:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 4)) != A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPLIT4NE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPLIT4NE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPLIT4NE:
                unfinished("Unsupported architecture");

#endif
