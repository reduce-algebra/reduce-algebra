// eq.cpp $Id$

#if defined BYTECODE
            case OP_EQ:                                     // A = eq(B, A)
                if (A_reg == B_reg) A_reg = lisp_true;
                else A_reg = nil;
                continue;

#elif defined __x86_64__ | defined __aarch64__

            case OP_EQ:                                     // A = eq(B, A)
                {   Label eqyes = newLabel();
                    Label endEq = newLabel();
                    cmp(A_reg, B_reg);
                    je(eqyes);
                    mov(A_reg, nilreg);
                    jmp(endEq);
                bind(eqyes);
                    loadstatic(A_reg, Olisp_true);
                bind(endEq);
                }
                break;

#else
            case OP_EQ:                                     // A = eq(B, A)
                unfinished("Unsupported architecture");

#endif

// end of op_eq.cpp
