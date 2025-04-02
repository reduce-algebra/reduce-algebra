// jumpl3natom.cpp $Id$

#if defined BYTECODE
            case OP_JUMPL3NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-3])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL3NATOM:
                next = bytes[ppc++];
                loadloc(w, 3);
                JITnotatomic(w, perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL3NATOM:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl3natom.cpp
