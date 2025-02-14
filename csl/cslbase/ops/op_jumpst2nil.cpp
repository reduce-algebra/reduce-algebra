// op_jumpst2nil.cpp

#if defined BYTECODE
            case OP_JUMPST2NIL:
                xppc = ppc;
                ppc++;
                if ((stack[-2] = A_reg) == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPST2NIL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPST2NIL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPST2NIL:
                unfinished("Unsupported architecture");

#endif
