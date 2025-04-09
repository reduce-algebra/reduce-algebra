// jumpeqcar.cpp $Id$

#if defined BYTECODE
            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (car_legal(A_reg) &&
                    static_cast<LispObject>(
                        basic_elt(litvec,w)) == car(A_reg))
                    short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                next = bytes[ppc++];
                {   Label noteqcar = newLabel();
                    JITatomic(A_reg, noteqcar);
                    loadlit(w, next);
                    loadreg(w1, A_reg, 0);
                    cmp(w, w1);
                    next = bytes[ppc++];
                    je(perInstruction[ppc+next]);
                bind(noteqcar);
                }
                break;
#else
            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                unfinished("Unsupported architecture");

#endif

// end of op_jumpeqcar.cpp
