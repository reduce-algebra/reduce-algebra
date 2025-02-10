// op_apply1.cpp

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

#elif defined __x86_64__

            case OP_APPLY1:
                myabort("This case not yet implemented for x86_64");

#elif defined __aarch64__

            case OP_APPLY1:
                myabort("This case not yet implemented for ARM");

#else
            case OP_APPLY1:
                myabort("Unsupported architecture");

#endif
