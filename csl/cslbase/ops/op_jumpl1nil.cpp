// jumpl1nil.cpp

#if defined BYTECODE
            case OP_JUMPL1NIL:
                xppc = ppc;
                ppc++;
                if (stack[-1] == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL1NIL:
                next = bytes[ppc++];
                loadloc(w, 1);
                cmp(w, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL1NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl1nil.cpp
