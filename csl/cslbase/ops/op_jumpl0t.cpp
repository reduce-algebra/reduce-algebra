// $Id$

#if defined BYTECODE
            case OP_JUMPL0T:
                xppc = ppc;
                ppc++;
                if (stack[0] != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL0T:
                next = bytes[ppc++];
                loadloc(w, 0);
                cmp(w, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL0T:
                unfinished("Unsupported architecture");

#endif

// end of jumpl0t.cpp
