// jumpliteq.cpp

#if defined BYTECODE
            case OP_JUMPLITEQ:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(
                    basic_elt(litvec, w)) == A_reg) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPLITEQ:
                next = bytes[ppc++];
                loadlit(w, next);
                next = bytes[ppc++];
                cmp(w, A_reg);
                je(perInstruction[ppc+next]);
                break;

#else
            case OP_JUMPLITEQ:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpliteq.cpp
