// jumpeqcar.cpp

#if defined BYTECODE
            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (car_legal(A_reg) &&
                    static_cast<LispObject>(basic_elt(litvec,
                                                      w)) == car(A_reg)) short_jump(ppc, xppc, codevec);
                continue;

#elif defined __x86_64__

            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                unfinished(__FILE__ " not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                unfinished("Unsupported architecture");

#endif

// end of op_jumpeqcar.cpp
