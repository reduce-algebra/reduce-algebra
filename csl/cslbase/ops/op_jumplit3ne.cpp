// jumplit3ne.cpp

#if defined BYTECODE
            case OP_JUMPLIT3NE:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 3)) != A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPLIT3NE:
                next = bytes[ppc++];
                loadlit(w, 3);
                cmp(w, A_reg);
                jne(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPLIT3NE:
                unfinished("Unsupported architecture");

#endif

// end of op_jumplit3ne.cpp
