// $Id$

#if defined BYTECODE
            case OP_JUMPL0ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[0])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL0ATOM:
                next = bytes[ppc++];
                loadloc(w, 0);
                JITatomic(w, perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL0ATOM:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl0atom.cpp
