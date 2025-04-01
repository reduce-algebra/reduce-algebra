// jumpl1t.cpp $Id$

#if defined BYTECODE
            case OP_JUMPL1T:
                xppc = ppc;
                ppc++;
                if (stack[-1] != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL1T:
                next = bytes[ppc++];
                loadloc(w, 1);
                cmp(w, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL1T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl1t.cpp
