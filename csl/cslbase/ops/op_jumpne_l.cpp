// op_jumpne_l.cpp

#if defined BYTECODE
            case OP_JUMPNE_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) long_jump(w, ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPNE_L:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPNE_L:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPNE_L:
                unfinished("Unsupported architecture");

#endif
