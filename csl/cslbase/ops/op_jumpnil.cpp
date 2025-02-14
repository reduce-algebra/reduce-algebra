// op_jumpnil.cpp

#if defined BYTECODE
            case OP_JUMPNIL:
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNIL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNIL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPNIL:
                unfinished("Unsupported architecture");

#endif
