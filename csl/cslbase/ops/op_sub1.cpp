// sub1.cpp $Id$

#if defined BYTECODE
            case OP_SUB1:
                if (is_fixnum(A_reg) && A_reg != MOST_NEGATIVE_FIXNUM)
                {   A_reg -= 0x10;
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Sub1::op(A_reg);
#else // ARITHLIB
                A_reg = plus2(A_reg, fixnum_of_int(-1));
#endif // ARITHLIB
                errexit();
                continue;

#elif defined __x86_64__ || defined __aarch64__

            case OP_SUB1:
                {   Label notFixnum = newLabel();
                    Label endSub1 = newLabel();
                    and3(w, A_reg, XTAG_BITS);
                    cmp(w, TAG_FIXNUM);
                    jne(notFixnum);
                    mov(w, MOST_NEGATIVE_FIXNUM);
                    cmp(A_reg, w);
                    je(notFixnum);
                    sub2(A_reg, 0x10);
// Could I do an overflow check here rather than the pre-check?
                    jmp(endSub1);
                bind(notFixnum);
                    loadstatic(w, OJITshim2);
                    loadstatic(w1, OJITplus2);
                    mov(B_reg, fixnum_of_int(-1));
                    JITcall(w, A_reg,
                            w1, A_reg, B_reg);  
                    JITerrorcheck();
                bind(endSub1);
                }
                break;

#else
            case OP_SUB1:
                unfinished("Unsupported architecture");

#endif

// end of sub1.cpp
