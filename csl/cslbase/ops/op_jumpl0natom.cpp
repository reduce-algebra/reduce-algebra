// jumpl0natom.cpp

#if defined BYTECODE
            case OP_JUMPL0NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[0])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPL0NATOM:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPL0NATOM:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPL0NATOM:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl0natom.cpp
