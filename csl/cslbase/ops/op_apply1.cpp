// $Id$

#if defined BYTECODE
            case OP_APPLY1:
                if (is_symbol(B_reg))   // can optimise this case, I guess
                {   f1 = qfn1(B_reg);
                    RECORD_CALL(list2(B_reg, A_reg));
                    *++stack = B_reg;
                    if ((qheader(B_reg) & SYM_TRACED) != 0)
                        A_reg = traced_call1(basic_elt(litvec, 0), f1, B_reg, A_reg);
                    else A_reg = f1(B_reg, A_reg);
                    errexit();
                    stack--;
                    continue;
                }
                A_reg = ncons(A_reg);
                errexit();
                A_reg = apply(B_reg, A_reg, nil, basic_elt(litvec, 0));
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_APPLY1:
                mov(w1, ncons);
                JITcall(JITshim1, A_reg,
                        w1, A_reg);
                JITerrorcheck();
                mov(w1, apply);
                loadlit(w2, 0);
                JITcall(JITshim4, A_reg,
                        w1, B_reg, A_reg, nilreg, w2);
                JITerrorcheck();
                break;


#else
            case OP_APPLY1:
                unfinished("Unsupported architecture");

#endif

// end of op_apply1.cpp
