// $Id$

#if defined BYTECODE
            case OP_JUMPL2NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-2])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL2NATOM:
                next = bytes[ppc++];
                loadloc(w, 2);
                JITnotatomic(w, perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL2NATOM:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl2natom.cpp
