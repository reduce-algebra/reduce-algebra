// jumpl3atom.cpp

#if defined BYTECODE
            case OP_JUMPL3ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-3])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL3ATOM:
                next = bytes[ppc++];
                loadloc(w, 3);
                JITatomic(w, perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL3ATOM:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl3atom.cpp
