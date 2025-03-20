// jumpl3nil.cpp

#if defined BYTECODE
            case OP_JUMPL3NIL:
                xppc = ppc;
                ppc++;
                if (stack[-3] == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPL3NIL:
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPL3NIL:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPL3NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl3nil.cpp
