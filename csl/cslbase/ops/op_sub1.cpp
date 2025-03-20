// sub1.cpp

#if defined BYTECODE
            case OP_SUB1:
                if (is_fixnum(A_reg) && A_reg != MOST_NEGATIVE_FIXNUM)
                {   A_reg -= 0x10;
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Sub1::A_reg);
#else // ARITHLIB
                A_reg = plus2(A_reg, fixnum_of_int(-1));
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__

            case OP_SUB1:
                {   Label notFixnum = newLabel();
                    Label endSub1 = newLabel();
                    mov(w, A_reg);
                    and_(w, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnum);
                    mov(w, MOST_NEGATIVE_FIXNUM);
                    cmp(A_reg, w);
                    jne(notFixnum);
                    add(A_reg, -0x10);
                    jmp(endSub1);
                bind(notFixnum);
#ifdef ARITHLIB
                    loadstatic(w, OJITshim1);
                    loadstatic(w1, OJITsub1);
                    JITcall(w, A_reg,
                           w1, A_reg);
#else // ARITHLIB
                    loadstatic(w, OJITshim2);
                    loadstatic(w1, OJITplus2);
                    mov(B_reg, fixnum_of_int(-1));
                    JITcall(w, A_reg,
                           w1, A_reg, B_reg);  
#endif // ARITHLIB
                    cmp(ptr(nilreg, JIToffset(OJITerrflag), 1), 0);
                    jne(callFailed);
                bind(endSub1);
                }
                break;

#elif defined __aarch64__

            case OP_SUB1:
                unfinished(__FILE__ " not yet implemented for ARM");

#else
            case OP_SUB1:
                unfinished("Unsupported architecture");

#endif

// end of sub1.cpp
