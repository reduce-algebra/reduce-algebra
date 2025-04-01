// jumpl1natom.cpp

#if defined BYTECODE
            case OP_JUMPL1NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-1])) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPL1NATOM:
                next = bytes[ppc++];
                loadloc(w, 1);
                JITnotatomic(w, perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPL1NATOM:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpl1natom.cpp
