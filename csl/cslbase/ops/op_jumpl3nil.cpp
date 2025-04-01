// jumpl3nil.cpp

#if defined BYTECODE
            case OP_JUMPL3NIL:
                xppc = ppc;
                ppc++;
                if (stack[-3] == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL3NIL:
                next = bytes[ppc++];
                loadloc(w, 3);
                cmp(w, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL3NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl3nil.cpp
