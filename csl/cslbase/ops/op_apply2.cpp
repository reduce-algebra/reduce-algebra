// $Id$

#if defined BYTECODE
            case OP_APPLY2:
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   f2 = qfn2(r2);
                    stack--;
                    RECORD_CALL(list3(r2, B_reg, A_reg));
                    if ((qheader(r2) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r2, B_reg, A_reg);
                    else A_reg = f2(r2, B_reg, A_reg);
                    errexit();
                    continue;
                }
// Here the stack has fn on the tand the 2 args are in B_reg, A_reg
                A_reg = list2(B_reg, A_reg);
                r2 = *stack--;
                errexit();
                A_reg = apply(r2, A_reg, nil, basic_elt(litvec, 0));
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_APPLY2:
                mov(w1, list2);
                JITcall(JITshim2, A_reg,
                        w1, B_reg, A_reg);
                JITerrorcheck();
                mov(w1, apply);
                loadlit(w2, 0);
                loadreg_post(w3, spreg, -8);
                JITcall(JITshim4, A_reg,
                        w1, w3, A_reg, nilreg, w2);
                JITerrorcheck();
                break;

#else
            case OP_APPLY2:
                unfinished("Unsupported architecture");

#endif

// end of op_apply2.cpp
