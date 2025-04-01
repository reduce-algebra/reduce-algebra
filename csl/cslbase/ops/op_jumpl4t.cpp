// jumpl4t.cpp

#if defined BYTECODE
            case OP_JUMPL4T:
                xppc = ppc;
                ppc++;
                if (stack[-4] != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL4T:
                next = bytes[ppc++];
                loadloc(w, 4);
                cmp(w, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL4T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl4t.cpp
