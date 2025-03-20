// greaterp.cpp

#if defined BYTECODE
            case OP_GREATERP:
#ifdef ARITHLIB
                w = Lessp::A_reg, B_reg);
#else // ARITHLIB
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg > A_reg;
                else
                {   w = lessp2(A_reg, B_reg);
                    errexit();
                }
#endif // ARITHLIB
                A_reg = Lispify_predicate(w);
                continue;

#elif defined __x86_64__

            case OP_GREATERP:
                {   Label notFixnums = newLabel();
                    Label yes = newLabel();
                    Label no = newLabel();
                    Label endGreaterp = newLabel();
                    mov(w, A_reg);
                    and_(w, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnums);
                    mov(w, B_reg);
                    and_(w, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnums);
                    cmp(A_reg, B_reg);
                    jnl(no);
                bind(yes);
                    mov(A_reg, ptr(nilreg, JIToffset(Olisp_true)));
                    jmp(endGreaterp);
                bind(notFixnums);
                    mov(w, ptr(nilreg, JIToffset(OJITshim2B)));
#ifdef ARITHLIB
                    mov(w1, ptr(nilreg, JIToffset(OJITlessp));
#else // ARITHLIB
                    mov(w1, ptr(nilreg, JIToffset(OJITlessp2)));
#endif // ARITHLIB
                    JITcall(w, A_reg,
                           w1, A_reg, B_reg);
                    cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                    jne(callFailed);
                    test(A_reg, 0xff);
                    jne(yes);
                bind(no);
                    mov(A_reg, nilreg);
                bind(endGreaterp);
                }
                break;

#elif defined __aarch64__

            case OP_GREATERP:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_GREATERP:
                unfinished("Unsupported architecture");

#endif

// end of op_greaterp.cpp
