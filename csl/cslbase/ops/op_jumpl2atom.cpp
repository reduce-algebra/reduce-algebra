// jumpl2atom.cpp $Id$

#if defined BYTECODE
            case OP_JUMPL2ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-2])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL2ATOM:
                next = bytes[ppc++];
                loadloc(w, 2);
                JITatomic(w, perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL2ATOM:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl2atom.cpp
