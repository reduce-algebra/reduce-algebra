// jumpl2t.cpp

#if defined BYTECODE
            case OP_JUMPL2T:
                xppc = ppc;
                ppc++;
                if (stack[-2] != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPL2T:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPL2T:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPL2T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl2t.cpp
