// jumplit4ne.cpp

#if defined BYTECODE
            case OP_JUMPLIT4NE:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 4)) != A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPLIT4NE:
                next = bytes[ppc++];
                loadlit(w, 4);
                cmp(w, A_reg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPLIT4NE:
                unfinished("Unsupported architecture");

#endif

// end of op_jumplit4ne.cpp
