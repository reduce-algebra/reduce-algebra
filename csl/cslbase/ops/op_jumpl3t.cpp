// $Id$

#if defined BYTECODE
            case OP_JUMPL3T:
                xppc = ppc;
                ppc++;
                if (stack[-3] != nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL3T:
                next = bytes[ppc++];
                loadloc(w, 3);
                cmp(w, nilreg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL3T:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl3t.cpp
