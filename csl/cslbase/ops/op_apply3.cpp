// $Id$

#if defined BYTECODE
            case OP_APPLY3:
// Somewhat beware here - This is (apply3 F a1 a2 a3) or
// (funcall F a1 a2 a3) and a3 will be passed directly as is in the stack.
// In particular a general call to an "apply3" function would have passed in
// effect (apply3' F a1 a2 [a3]) with the fourth argument passed as a list.
// When I use the bytecode I do not do that.
                r1 = *stack--;
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   f3 = qfn3(r2);
                    RECORD_CALL(list4(r2, r1, B_reg, A_reg));
                    if ((qheader(r2) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r2, r1, B_reg, A_reg);
                    else A_reg = f3(r2, r1, B_reg, A_reg);
                    stack--;
                    errexit();
                    continue;
                }
                A_reg = list3(stack[-1], B_reg, A_reg);
                r2 = *stack--;
                errexit();
                A_reg = apply(r2, A_reg, nil, basic_elt(litvec, 0));
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_APPLY3:
                mov(w1, list3);
                loadreg_post(w, spreg, -8);
                JITcall(JITshim3, A_reg,
                        w1, w, B_reg, A_reg);
                JITerrorcheck();
                mov(w1, apply);
                loadlit(w2, 0);
                loadreg_post(w3, spreg, -8);
                JITcall(JITshim4, A_reg,
                        w1, w3, A_reg, nilreg, w2);
                JITerrorcheck();
                break;

#else
            case OP_APPLY3:
                unfinished("Unsupported architecture");

#endif

// end of op_apply3.cpp
