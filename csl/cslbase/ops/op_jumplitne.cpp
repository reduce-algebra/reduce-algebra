// op_jumplitne.cpp

#if defined BYTECODE
            case OP_JUMPLITNE:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec,
                                                      w)) != A_reg) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPLITNE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPLITNE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPLITNE:
                unfinished("Unsupported architecture");

#endif
