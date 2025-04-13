// greaterp.cpp $Id$

#if defined BYTECODE
            case OP_GREATERP:
#ifdef ARITHLIB
                w = Lessp::op(A_reg, B_reg);
#else // ARITHLIB
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg > A_reg;
                else
                {   w = lessp2(A_reg, B_reg);
                    errexit();
                }
#endif // ARITHLIB
                A_reg = Lispify_predicate(w);
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_GREATERP:
                {   Label notFixnums = newLabel();
                    Label yes = newLabel();
                    Label no = newLabel();
                    Label endGreaterp = newLabel();
                    and3(w, A_reg, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnums);
                    and3(w, B_reg, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnums);
                    cmp(A_reg, B_reg);
                    jnl(no);
                bind(yes);
                    loadstatic(A_reg, Olisp_true);
                    jmp(endGreaterp);
                bind(notFixnums);
                    mov(w1, lessp2);
                    JITcall(JITshim2B, A_reg,
                            w1, A_reg, B_reg);
                    JITerrorcheck();
                    test(A_reg, 0xff);
                    jne(yes);
                bind(no);
                    mov(A_reg, nilreg);
                bind(endGreaterp);
                }
                break;

#else
            case OP_GREATERP:
                unfinished("Unsupported architecture");

#endif

// end of op_greaterp.cpp
