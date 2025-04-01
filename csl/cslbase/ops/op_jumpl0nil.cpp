// jumpl0nil.cpp $Id$

#if defined BYTECODE
            case OP_JUMPL0NIL:
                xppc = ppc;
                ppc++;
                if (stack[0] == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL0NIL:
                next = bytes[ppc++];
                loadloc(w, 0);
                cmp(w, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL0NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl0nil.cpp

