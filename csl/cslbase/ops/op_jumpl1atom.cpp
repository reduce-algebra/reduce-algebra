// jumpl1atom.cpp $Id$

#if defined BYTECODE
            case OP_JUMPL1ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-1])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL1ATOM:
                next = bytes[ppc++];
                loadloc(w, 1);
                JITatomic(w, perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL1ATOM:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl1atom.cpp
