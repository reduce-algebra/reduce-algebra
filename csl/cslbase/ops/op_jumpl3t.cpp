// jumpl3t.cpp

#if defined BYTECODE
            case OP_JUMPL3T:
                xppc = ppc;
                ppc++;
                if (stack[-3] != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPL3T:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPL3T:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPL3T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl3t.cpp
