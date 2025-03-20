// jumpl1atom.cpp

#if defined BYTECODE
            case OP_JUMPL1ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-1])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPL1ATOM:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPL1ATOM:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPL1ATOM:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl1atom.cpp
