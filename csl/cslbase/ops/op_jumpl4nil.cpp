// $Id$

#if defined BYTECODE
            case OP_JUMPL4NIL:
                xppc = ppc;
                ppc++;
                if (stack[-4] == nil) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL4NIL:
                next = bytes[ppc++];
                loadloc(w, 4);
                cmp(w, nilreg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL4NIL:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl4nil.cpp
