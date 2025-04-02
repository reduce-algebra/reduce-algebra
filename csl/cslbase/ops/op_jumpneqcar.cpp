// jumpneqcar.cpp $Id$

#if defined BYTECODE
            case OP_JUMPNEQCAR:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!car_legal(A_reg) ||
                    static_cast<LispObject>(basic_elt(litvec,
                                                      w)) != car(A_reg)) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_JUMPNEQCAR:
                next = bytes[ppc++];
                {   intptr_t next1 = bytes[ppc++];
                    JITatomic(A_reg, perInstruction[ppc+next1]);
                    loadlit(w, next);
                    loadreg(w1, A_reg, 0);
                    cmp(w, w1);
                    jne(perInstruction[ppc+next1]);
                }
                break;

#else
            case OP_JUMPNEQCAR:
                unfinished("Unsupported architecture");

#endif

// end of op_jumpneqcar.cpp
