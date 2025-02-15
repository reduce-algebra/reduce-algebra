// op_jumpne.cpp

#if defined BYTECODE
            case OP_JUMPNE:
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNE:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNE:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPNE:
                unfinished("Unsupported architecture");

#endif
