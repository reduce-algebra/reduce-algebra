// op_jumpl0atom.cpp

#if defined BYTECODE
            case OP_JUMPL0ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[0])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPL0ATOM:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPL0ATOM:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPL0ATOM:
                unfinished("Unsupported architecture");

#endif
